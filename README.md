# Esp32LegoDuino

Christmass 2020 I bought a [Lego Volvo Dumptruck](https://www.lego.com/nl-nl/product/6x6-volvo-articulated-hauler-42114?age-gate=grown_up) just to get through the Corona Christmass...
Played a little with the Lego App and the Volvo, but did not like the app. So the dump truck gathered dust for some years. 
SOme time ago I stumbled on [LegoIno](https://github.com/corneliusmunz/legoino), had some ESP32 modules around here so gave it a try.
So I was able to control the Lego Dump truck with som buttons on a test board.   

Okay, you need the app to perform software updates of the hub and to initialize the truck.. 
  

## Used library's
If you want to build the code yourself or update / change the code following library's are required.
* [LegoIno](https://github.com/corneliusmunz/legoino) 
* [NimBLE-Arduino-release-1.5](https://github.com/h2zero/NimBLE-Arduino/tree/release/1.5) for BLE stuff... Use this version and not the latest release.
* [Bounce2](https://github.com/thomasfredericks/Bounce2/archive/master.zip) for debounce of switches. 

