# Arduino-Cat-Alarm

This is a homemade IoT distraction system for my cat Louie. 

Louie is a real pest in the morning if he hasn't yet had his breakfast. This device plays the sound of birds singing in another room when a button is pressed on a website hosted by an ESP8266 server which trips an Arduino playing the audio file off an SD card. 

Both the Arduino and the ESP8266 board are powered with a breadboard-compatible power supply module connected to either a battery or power bank, making the device fully wireless, and allowing it to be placed in arbitray parts of the home.

This repo contains:

* the hardware wiring diagram and I/O tables which show how to connect the two boards together so that the output of the ESP trips the audio playback on the Arduino. It also shows the wiring of a single-BJT amplifier which makes the small 8 <img src="https://render.githubusercontent.com/render/math?math=\Omega"> speaker a little bit louder,
* an *.ino* sketch which runs on the ESP8266 to establish a Wi-Fi connection and to create a digital HIGH response to an HTML button,
* an *.ino* sketch that runs on the Arduino to play the audio file off the SD card. The file is a down-converted mono 8-bit *.wav* file, sampled at 16 kHz (an unsigned 8-bit pulse-code modulation (PCM) format).

Server IP is: *192.168.0.140*.

_______

## SD Card Module Connections:


| **SD Card Module** | **Arduino** |
|:--------------:|:-------:|
|       GND      |   GND   |
|       + 5      |   5 V   |
|       CS       |   #10   |
|      MOSI      |   #11   |
|       SCK      |   #13   |
|      MISO      |   #12   |

## Single-Transistor Speaker Amplifier: 

| **Start Point**                | **End Point** |
|:-------:|:------:|
| GND on Arduino                 | Negative rail on breadboard    |
| 5 V supply on Arduino          | Positive rail on breadboard    |
| #9 (sound signal) on Arduino   | 1 k<img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor           |
| 1 k<img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor           | **Base** of NPN P2222 BJT      |
| **Base** of NPN P2222 BJT      | 100 k<img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor         |
| 100 k<img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor         | **Emitter** of NPN P2222 BJT   |
| **Emitter** of NPN P2222 BJT   | Negative rail on breadboard    |
| **Base** of NPN P2222 BJT      | 100 k<img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor         |
| 100 k<img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor         | **Collector** of NPN P2222 BJT |
| **Collector** of NPN P2222 BJT | Negative input on speaker      |
| Positive input on speaker      | 10 <img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor           |
| 10 <img src="https://render.githubusercontent.com/render/math?math=\Omega"> resistor           | Positive rail on breadboard    |

*Note:* The BJT does get quite hot and the speaker is not terribly loud... good enough for a prototype, but for optimal performance need a better speaker/amplifier.

## Arduino-ESP8266 Trip Wire:

| **Arduino** | **ESP8266**| 
|:------:|:-------:|
|#3 | #D3 |

## Power Supply (tbc.):

| **Boards** | **Power Supply Module on Breadboard**|
|:------:|:------:|
|V<sub>in</sub> pin on ESP| 5 V rail from Elegoo Power Supply Module|
|GND pin on ESP| GND rail from Elegoo Power Supply Module|
|V<sub>in</sub> pin on Arduino| 5 V rail from Elegoo Power Supply Module|
|GND pin on Arduino| GND rail from Elegoo Power Supply Module|

## Visual Routing Schematic:

![](https://raw.github.com/molydisulfide/Arduino-Cat-Alarm/master/images/routing.jpg?raw=true )


