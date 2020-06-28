# Arduino-Cat-Alarm

This is a homemade IoT distraction system for my cat Louie. 

Louie is a real pest in the morning when he hasn't yet had his breakfast. This device plays the sound of birds singing in another room when a button is pressed on a website hosted by an ESP2866 server connected to an Arduino reading off the audio file off an SD card. 

Both the Arduino and the ESP2866 board are powered with a 5 V battery, making the device fully wireless, and allowing it to be placed in arbitray parts of the home.

The repo contains the hardware wiring diagram, a sketch which runs on the ESP2866, and a sketch that runs on the Arduino.

Server IP is: 192.168.0.140.
