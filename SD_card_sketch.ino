//TMRpcm library is needed

#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD failed to connect!");
  return;
}
tmrpcm.setVolume(5);
tmrpcm.play("birdo.wav");

}

void loop() {
  // put your main code here, to run repeatedly:

}
