/**
 * A Legoino example to control a control plus hub
 * with a Motor connected on Port D
 *
 * (c) Copyright 2020 - Cornelius Munz
 * Released under MIT License
 *
 */

#include "Bounce2.h"
#include "Lpf2Hub.h"

#define LEGO_ESP32_PIN_FW 4
#define LEGO_ESP32_PIN_BW 16
#define LEGO_ESP32_PIN_GEAR_PLUS 17
#define LEGO_ESP32_PIN_GEAR_MIN 5
#define LEGO_ESP32_PIN_DIRECTION_LEFT 18
#define LEGO_ESP32_PIN_DIRECTION_RIGHT 19

// create a hub instance
Lpf2Hub myHub;
byte portFwBw      = (byte)ControlPlusHubPort::A;
byte portGear      = (byte)ControlPlusHubPort::B;
byte portDirection = (byte)ControlPlusHubPort::D;

Bounce LegoEsp32ButtonForward        = Bounce();
Bounce LegoEsp32ButtonBackward       = Bounce();
Bounce LegoEsp32ButtonGearPlus       = Bounce();
Bounce LegoEsp32ButtonGearMin        = Bounce();
Bounce LegoEsp32ButtonDirectionLeft  = Bounce();
Bounce LegoEsp32ButtonDirectionRight = Bounce();

void setup()
{
    Serial.begin(115200);
    Serial.println("LegoEsp32 start");
    myHub.init();

    pinMode(LEGO_ESP32_PIN_FW, INPUT_PULLUP);
    LegoEsp32ButtonForward.interval(100);
    LegoEsp32ButtonForward.attach(LEGO_ESP32_PIN_FW);

    pinMode(LEGO_ESP32_PIN_BW, INPUT_PULLUP);
    LegoEsp32ButtonBackward.interval(100);
    LegoEsp32ButtonBackward.attach(LEGO_ESP32_PIN_BW);

    pinMode(LEGO_ESP32_PIN_GEAR_PLUS, INPUT_PULLUP);
    LegoEsp32ButtonGearPlus.interval(100);
    LegoEsp32ButtonGearPlus.attach(LEGO_ESP32_PIN_GEAR_PLUS);

    pinMode(LEGO_ESP32_PIN_GEAR_MIN, INPUT_PULLUP);
    LegoEsp32ButtonGearMin.interval(100);
    LegoEsp32ButtonGearMin.attach(LEGO_ESP32_PIN_GEAR_MIN);

    pinMode(LEGO_ESP32_PIN_DIRECTION_LEFT, INPUT_PULLUP);
    LegoEsp32ButtonDirectionLeft.interval(100);
    LegoEsp32ButtonDirectionLeft.attach(LEGO_ESP32_PIN_DIRECTION_LEFT);

    pinMode(LEGO_ESP32_PIN_DIRECTION_RIGHT, INPUT_PULLUP);
    LegoEsp32ButtonDirectionRight.interval(100);
    LegoEsp32ButtonDirectionRight.attach(LEGO_ESP32_PIN_DIRECTION_RIGHT);
}

// main loop
void loop()
{
    LegoEsp32ButtonForward.update();
    LegoEsp32ButtonBackward.update();
    LegoEsp32ButtonGearMin.update();
    LegoEsp32ButtonGearPlus.update();
    LegoEsp32ButtonDirectionLeft.update();
    LegoEsp32ButtonDirectionRight.update();

    if (LegoEsp32ButtonForward.rose())
    {
        Serial.println("LegoEsp32ButtonForward.rose");
        if (myHub.isConnected())
        {
            myHub.stopTachoMotor(portFwBw);
        }
    }
    else if (LegoEsp32ButtonForward.fell())
    {
        Serial.println("LegoEsp32ButtonForward.fell");
        if (myHub.isConnected())
        {
            myHub.setTachoMotorSpeed(portFwBw, 50);
        }
    }

    if (LegoEsp32ButtonBackward.rose())
    {
        Serial.println("LegoEsp32ButtonBackward.rose");
        if (myHub.isConnected())
        {
            myHub.stopTachoMotor(portFwBw);
        }
    }
    else if (LegoEsp32ButtonBackward.fell())
    {
        Serial.println("LegoEsp32ButtonBackward.fell");
        if (myHub.isConnected())
        {
            myHub.setTachoMotorSpeed(portFwBw, -50);
        }
    }

    if (LegoEsp32ButtonGearMin.rose())
    {
        Serial.println("LegoEsp32ButtonGearMin.rose");
        if (myHub.isConnected())
        {
            myHub.stopTachoMotor(portGear);
        }
    }
    else if (LegoEsp32ButtonGearMin.fell())
    {
        Serial.println("LegoEsp32ButtonGearMin.fell");
        if (myHub.isConnected())
        {
            myHub.setTachoMotorSpeed(portGear, -35);
        }
    }

    if (LegoEsp32ButtonGearPlus.rose())
    {
        Serial.println("LegoEsp32ButtonGearPlus.rose");
        if (myHub.isConnected())
        {
            myHub.stopTachoMotor(portGear);
        }
    }
    else if (LegoEsp32ButtonGearPlus.fell())
    {
        Serial.println("LegoEsp32ButtonGearPlus.fell");
        if (myHub.isConnected())
        {
            myHub.setTachoMotorSpeed(portGear, 35);
        }
    }

    if (LegoEsp32ButtonDirectionLeft.rose())
    {
        Serial.println("LegoEsp32ButtonDirectionLeft.rose");
        if (myHub.isConnected())
        {
            myHub.stopTachoMotor(portDirection);
        }
    }
    else if (LegoEsp32ButtonDirectionLeft.fell())
    {
        Serial.println("LegoEsp32ButtonDirectionLeft.fell");
        if (myHub.isConnected())
        {
            myHub.setTachoMotorSpeed(portDirection, -35);
        }
    }

    if (LegoEsp32ButtonDirectionRight.rose())
    {
        Serial.println("LegoEsp32ButtonDirectionRight.rose");
        if (myHub.isConnected())
        {
            myHub.stopTachoMotor(portDirection);
        }
    }
    else if (LegoEsp32ButtonDirectionRight.fell())
    {
        Serial.println("LegoEsp32ButtonDirectionRight.fell");
        if (myHub.isConnected())
        {
            myHub.setTachoMotorSpeed(portDirection, 35);
        }
    }

    // connect flow. Search for BLE services and try to connect if the uuid of the
    // hub is found
    if (myHub.isConnecting())
    {
        myHub.connectHub();
        if (myHub.isConnected())
        {
            char hubName[] = "myControlPlusHub";
            myHub.setHubName(hubName);
            myHub.setLedColor(GREEN);

            Serial.println("Connected to HUB");
        }
        else
        {
            Serial.println("Failed to connect to HUB");
        }
    }
} // End of loop
