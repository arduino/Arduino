/*

 This example demonstrates using the cc3200 as a wifi client (TCP)
 The client will connect to the TCP server.
 
 Write something in the serial console to send it to the server.
 Anything the server sends back will be printed in the serial console

 created 3 July 2014
 by Noah Luskey
 */
#include <WiFi.h>
#include <WiFiClient.h>

char ssid[] = "your network";     //  your network SSID (name)
char pass[] = "your password";  // your network password
uint16_t port = 9999;     // port number of the server
IPAddress server(10, 0, 1, 6);   // IP Address of the server
WiFiClient client;

int status = WL_IDLE_STATUS;     // the Wifi radio's status

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(115200);

  // attempt to connect to Wifi network:
  Serial.print("Attempting to connect to WPA SSID: ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  int tries = 0;
  while ( status != WL_CONNECTED) {
    status = WiFi.status();
    // wait .1 seconds for connection:
    delay(100);
    Serial.print(".");
    if (tries++ > 100) {
      Serial.println("Couldn't connect to your wifi network");
      Serial.println("check your ssid and password.");
      while(1);
    }
  }

  // you're connected now, so print out the data:
  Serial.println("\nYou're connected to the network");
  IPAddress empty(0,0,0,0);
  while (WiFi.localIP() == empty); //wait for IP assignment
  
  // attempt to connect to the server
  Serial.println("Attempting to connect to server");
  tries = 0;
  while (client.connect(server, port) == false) {
    Serial.print(".");
    if (tries++ > 100) {
      Serial.println("\nThe server isn't responding");
      while(1);
    }
    delay(100);
  }
  
  //we've connected to the server by this point
  Serial.println("\nConnected to the server!");
}

void loop() {  
  if (Serial.available()) {
    //read the serial command into a buffer
    char buffer[255] = {0};
    Serial.readBytes(buffer, Serial.available());
    //send the serial command to the server
    client.println(buffer);
    Serial.print("Sent: ");
    Serial.println(buffer);
  }
  
  if (client.available()) {
    char buffer[255] = {0};
    client.read((uint8_t*)buffer, client.available());
    Serial.print("Received: ");
    Serial.println(buffer);
  }
  
}

