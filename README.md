# Arduino-Cat-Alarm

This is a homemade IoT distraction system for my cat Louie. 

Louie is a real pest in the morning when he hasn't yet had his breakfast. This device plays the sound of birds singing in another room when a button is pressed on a website hosted by an ESP2866 server connected to an Arduino reading off the audio file off an SD card. 

Both the Arduino and the ESP2866 board are powered with a 5 V battery, making the device fully wireless, and allowing it to be placed in arbitray parts of the home.

The repo contains the hardware wiring diagram, a sketch which runs on the ESP2866, and a sketch that runs on the Arduino.

Server IP is: *192.168.0.140*.

_______

## SD Card Module connections:

____________

| **SD Card Module** | **Arduino** |
|:--------------:|:-------:|
|       GND      |   GND   |
|       + 5      |   5 V   |
|       CS       |   #10   |
|      MOSI      |   #11   |
|       SCK      |   #13   |
|      MISO      |   #12   |

## Single-Transistor Speaker Amplifier: 

_________
| **Start Point**                | **End Point** |
|:-------:|:------:|
| GND on Arduino                 | Negative rail on breadboard    |
| 5 V supply on Arduino          | Positive rail on breadboard    |
| #9 (sound signal) on Arduino   | 1 k$\Omega$ resistor           |
| 1 k$\Omega$ resistor           | **Base** of NPN P2222 BJT      |
| **Base** of NPN P2222 BJT      | 100 k$\Omega$ resistor         |
| 100 k$\Omega$ resistor         | **Emitter** of NPN P2222 BJT   |
| **Emitter** of NPN P2222 BJT   | Negative rail on breadboard    |
| **Base** of NPN P2222 BJT      | 100 k$\Omega$ resistor         |
| 100 k$\Omega$ resistor         | **Collector** of NPN P2222 BJT |
| **Collector** of NPN P2222 BJT | Negative input on speaker      |
| Positive input on speaker      | 10 $\Omega$ resistor           |
| 10 $\Omega$ resistor           | Positive rail on breadboard    |



## Arduino-ESP8266 Trip Wire:

_________

| **Arduino** | **ESP8266**| 
|:------:|:-------:|
|#3 | #D3 |

## Power supply:

Vin pin on ESP -> 5 V rail from Elegoo Power Supply Module
GND pin on ESP -> GND rail from Elegoo Power Supply Module
Vin pin on Arduino -> 5 V rail from Elegoo Power Supply Module
GND pin on Arduino -> GND rail from Elegoo Power Supply Module


