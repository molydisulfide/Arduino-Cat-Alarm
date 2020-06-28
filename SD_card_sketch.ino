//TMRpcm library is needed

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm audio;

int val = 0; // variable to store the read value.
int trip_pin = 3; // declare the input pin for tripping the audio signal. 

void setup(){
  
// Set up SD card connection://
  
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

    if(!SD.begin(SD_ChipSelectPin))
      {
        Serial.println("SD failed or not inserted.");
        return;
      }
      
  Serial.println("SD card initialized.");

// Set up audio parameters for playing the 8-bit birdsong file: //

  audio.speakerPin=9;
  audio.volume(5);
  audio.play("birdo.wav");
  audio.loop(1);
  audio.pause();

// Set up input pin://

 
  
  pinMode(trip_pin, INPUT); // sets the digital pin #3 as input trip signal coming from the output of the ESP board.
}

void loop() {
  
  // This loop checks for digital input on pin #3 and trips the audio file on loop on from the SD card://  

  val = digitalRead(trip_pin); // read the input pin.
  Serial.println(val);
  if(val == 1)
    {
      Serial.println("Signal has tripped.");
      Serial.println(val); // print the read-out value to the Serial Monitor.
      audio.pause();
      delay(3000);
      
      
    } else if(val == 0){
   
      audio.play("birdo.wav");}
    }
    
   
