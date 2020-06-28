# Arduino-Cat-Alarm

This is a homemade IoT distraction system for my cat Louie. 

Louie is a real pest in the morning when he hasn't yet had his breakfast. This device plays the sound of birds singing in another room when a button is pressed on a website hosted by an ESP2866 server connected to an Arduino reading off the audio file off an SD card. 

Both the Arduino and the ESP2866 board are powered with a 5 V battery, making the device fully wireless, and allowing it to be placed in arbitray parts of the home.

The repo contains the hardware wiring diagram, a sketch which runs on the ESP2866, and a sketch that runs on the Arduino.

Server IP is: 192.168.0.140.

SD Card Module connections:

____________

| **SD Card Module** | **Arduino** |
|:--------------:|:-------:|
|       GND      |   GND   |
|       + 5      |   5 V   |
|       CS       |   #10   |
|      MOSI      |   #11   |
|       SCK      |   #13   |
|      MISO      |   #12   |

Speaker Amplifier: 

GND on Arduino -> GND rail on breadboard
5 V supply on Arduino -> positive rail on breadboard
#9 (sound signal on Arduino) -> 1kOhm resistor
1kOhm resistor -> Base of NPN P2222 BJT
Base of NPN P2222 BJT -> 100kOhm resistor
100 kOhm resistor -> Emitter of NPN P2222 BJT
Emitter of NPN P222 BJT -> GND rail on breadboard
Base of NPN P2222 BJT -> 100 kOhm resistor 
100kOhm resistor -> Collector of NPN P2222 BJT
Collector of NPN P2222 BJT -> negative input on the speaker
positive input on the speaker -> 10 Ohm resistor
10 Ohm resistor -> positive rail on breadboard

Arduino-ESP8266 Trip Wire:

#3 (Arduino) -> #D3 on ESP8266

Power supply:

Vin pin on ESP -> 5 V rail from Elegoo Power Supply Module
GND pin on ESP -> GND rail from Elegoo Power Supply Module
Vin pin on Arduino -> 5 V rail from Elegoo Power Supply Module
GND pin on Arduino -> GND rail from Elegoo Power Supply Module


