#include <ThingSpeak.h>
#include<ESP8266WiFi.h>
#include "secrets.h"

WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;
char ssid[] = "****";
char password[] = "****";
int Time_S = 1; //Change this to your prefered sampling interval in seconds, exampe 2 min is 120 seconds
float phC; 
int number = 0;

void setup() {
  Serial.begin(9600); 
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client); 
  delay(10);
  Serial.println('\n');
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to Wi-Fi network ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Successfully connected to ");  
  Serial.print(ssid); Serial.println("!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 
}

void loop()
{
// Write to ThingSpeak. There are up to 8 fields in a channel, allowing you to store up to 8 different
  // pieces of information in a channel.  Here, we write to field 1.
  int x = ThingSpeak.writeField(myChannelNumber, 1, phC, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  getLight();
  
  delay(10000); // Wait 20 seconds to update the channel again
}



////////////////////////////////Get Temperature readings///////////////////////////
void getLight()
{           
double Light;
int sensorValue;
sensorValue=analogRead(A0);
float voltage= sensorValue * (3.3 / 1023.0);   // convert sensor reading to voltage  
phC = voltage;
Serial.println("Voltage on photo-resistor is: ");  
Serial.print(phC); Serial.println(" V");
}
