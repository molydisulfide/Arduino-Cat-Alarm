//TMRpcm library is needed

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"


TMRpcm audio;

void setup(){
  audio.speakerPin=9;
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

    if(!SD.begin(SD_ChipSelectPin))
      {
        Serial.println("SD failed or not inserted.");
        return;
      }
  Serial.println("SD card initialized.");
  audio.volume(5);
  audio.play("birdo.wav");
  audio.loop(1);
  audio.pause();


}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  int trip_signal;
  trip_signal = analogRead(A5);
  if(trip_signal > 700)
    {
      Serial.println("Signal has tripped.");
      Serial.println(trip_signal);
      audio.pause();
      delay(2000);
      
      return;
    }


  
}
