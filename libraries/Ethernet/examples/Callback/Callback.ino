/*
 Callback
 
 A simple example that show how to use Callback
 Using an Arduino Wiznet Ethernet shield. 
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 
 created 29 Giu 2013
 by Mauro Mombelli
 
 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network.
// gateway and subnet are optional:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1, 177);
IPAddress gateway(192,168,1, 1);
IPAddress subnet(255, 255, 255, 0);


// telnet defaults to port 23
EthernetServer server(23);

void setup() {
  //initialize connect callback
  server.registerConnectCallback(&onConnect);
  // initialize the ethernet device
  Ethernet.begin(mac, ip, gateway, subnet);
  // start listening for clients
  server.begin();
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.print("Server address:");
  Serial.println(Ethernet.localIP());
}

void loop() {
  EthernetClient client = server.available();
}

void onConnect(EthernetClient &client) {
  Serial.print("onConnect called, client ID: ");
  Serial.println( client.getId() );
  //initialize connect callback for the client
  client.registerDisconnectCallback(&onDisconnect);
}

void onDisconnect(EthernetClient &socket) {
  Serial.println("onDisconnect called");
}

