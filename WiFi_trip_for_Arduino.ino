#include<ESP8266WiFi.h>
#include "secrets.h"

WiFiClient  client;

char ssid[] = "Guzman";
char password[] = "M4rk_H3rsam";

// Note: GPIO pins on the ESP2866 can draw a maximum current of 12 mA. //

int trip = D5; // This is the pin on the ESP that will be used as a trip signal to play the file off the SD on the Arduino. //

void setup() {
  

// Wi-Fi connection portion: //

  Serial.begin(9600); // Optimal baud rate for the ESP module. //
  Serial.println('\n');
  WiFi.begin(ssid, password);             // Connect to the network. //
  Serial.print("Connecting to Wi-Fi network ");
  Serial.print(ssid); Serial.println(" ...");

  int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect. //
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }

  Serial.println('\n');
  Serial.println("Successfully connected to ");  
  Serial.print(ssid); Serial.println("!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 

// Initialize the trip pin to the LOW (0) state: //

  pinmode(trip, OUTPUT);
  digitalWrite(trip, LOW);
}

void loop() {

// ESP listens to incoming clients, stores the incoming data and prints to the Serial Monitor: //

  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
  Serial.println("Waiting for new client...");

  while(!client.available())
  {
    delay(1);
  }

  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

// The trip pin is assigned to low always on start of the program. 
// Change its binary status by digital writing it to HIGH (1) when 
// the status from the client availability string from the above if loop changed to ON.

int value = LOW;
  if(request.indexOf("/trip=ON") != -1)
  {
    digitalWrite(trip, HIGH); // Turn trip pin ON.
    value = HIGH;
  }
  if(request.indexOf("/trip=OFF") != -1)
  {
    digitalWrite(trip, LOW); // Turn trip pin OFF.
    value = LOW;

// Create HTML webpage with ON and OFF buttons to control the status of the trip pin: //

client.println("HTTP/1.1 200 OK"); //
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print(" Control Trip Pin: ");

  if(value == HIGH)
  {
    client.print("ON");
  }
  else
  {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/trip=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/trip=OFF\"\"><button>OFF</button></a><br />");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected.");
  Serial.println("");
}

}
