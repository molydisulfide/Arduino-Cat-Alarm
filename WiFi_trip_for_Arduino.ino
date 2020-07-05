#include<ESP8266WiFi.h>

WiFiServer server(80); // Set web server port number to 80.
// Variable to store the HTTP request


// Auxiliar variables to store the current output state
String output26State = "off";

// Assign output variables to GPIO pins
const int output26 = 26;
const int output27 = 27;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;
String header; // Variable to store the HTTP request.

char ssid[] = "****";
char password[] = "*****";

// Note: GPIO pins on the ESP2866 can draw a maximum current of 12 mA. //

int trip = 0; // This is the D3 pin on the ESP that will be used as a trip signal 
              // to play the file off the SD on the Arduino. 
              // The pinout mapping is weird on the NodeMCU — the D3 pin is "0". 

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

// ESP server functionality: //

  
  server.begin();                  // Start server.
  Serial.println("HTTP server started!"); // Print status of the server to the Serial Monitor.
  
// Initialize the trip pin to the LOW (0) state: //

  pinMode(trip, OUTPUT);
  digitalWrite(trip, LOW);
}

void loop() {

 WiFiClient client = server.available();
 if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /0/on") >= 0) {
              Serial.println("GPIO trip on");
              output26State = "on";
              digitalWrite(trip, HIGH);
            } else if (header.indexOf("GET /0/off") >= 0) {
              Serial.println("GPIO trip off");
              output26State = "off";
              digitalWrite(trip, LOW);
            } 
            
            // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #555555;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>Louie's Wi-Fi Arduino Alarm</h1>");
            
            // Display current state, and ON/OFF buttons for GPIO 26  
            client.println("<p>Play Birds for Louie: Status is " + output26State + "</p>");
            // If the output26State is off, it displays the ON button       
            if (output26State=="off") {
              client.println("<p><a href=\"/0/on\"><button class=\"button\">PLAY</button></a></p>");
            } else {
              client.println("<p><a href=\"/0/off\"><button class=\"button button2\">STOP</button></a></p>");
            } 
               
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");


 }
 }
