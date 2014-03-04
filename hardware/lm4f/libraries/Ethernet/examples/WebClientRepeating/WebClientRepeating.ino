/*
  Repeating Web client
 
 This sketch connects to a a web server and makes a request
 using a Wiznet Ethernet shield. You can use the Arduino Ethernet shield, or
 the Adafruit Ethernet shield, either one will work, as long as it's got
 a Wiznet Ethernet module on board.
 
 This example uses DNS, by assigning the Ethernet client with a MAC address,
 IP address, and DNS address.
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 
 created 19 Apr 2012
 by Tom Igoe
 
 http://arduino.cc/en/Tutorial/WebClientRepeating
 This code is in the public domain.
 
 */

#include <Ethernet.h>

// assign a MAC address for the ethernet controller.
// fill in your address here:
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
// fill in an available IP address on your network here,
// for manual configuration:
//IPAddress ip(173, 194, 33, 104);
IPAddress ip(146, 252, 242, 192);

// fill in your Domain Name Server address here:
IPAddress myDns(1,1,1,1);

// initialize the library instance:
EthernetClient client;

char server[] = "www.arduino.cc";

unsigned long lastConnectionTime = 0;          // last time you connected to the server, in milliseconds
boolean lastConnected = false;                 // state of the connection last time through the main loop
const unsigned long postingInterval = 10*1000;  // delay between updates, in milliseconds

void setup() {
  // start serial port:
  Serial.begin(115200);
  // start the Ethernet connection using a fixed IP address and DNS server:
  Ethernet.begin(0);
  // print the Ethernet board/shield's IP address:
  Serial.print("My IP address: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // if there's incoming data from the net connection.
  // send it out the serial port.  This is for debugging
  // purposes only:
  
  while (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // if there's no net connection, but there was one last time
  // through the loop, then stop the client:
  if (!client.connected() && lastConnected) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
  }

  // if you're not connected, and ten seconds have passed since
  // your last connection, then connect again and send data:
    //Serial.println(millis());
  if(!client.connected() && (millis() - lastConnectionTime > postingInterval)) {
    httpRequest();
  }
  // store the state of the connection for next time through
  // the loop:
  lastConnected = client.connected();
}

// this method makes a HTTP connection to the server:
void httpRequest() {
    Serial.print("connecting...");
  // if there's a successful connection:
  if (client.connect(ip, 80)) {
    Serial.println("connection success");
    // send the HTTP PUT request:
    client.println("GET / HTTP/1.1");
    client.println("Host: 146.252.242.126");
    client.println("User-Agent: energia-ethernet");
    client.println("Connection: close");
    client.println();

  } 
  else {
    // if you couldn't make a connection:
    Serial.println("connection failed");
    Serial.println("disconnecting.");
    client.stop();
  }
    // note the time that the connection was made:
    lastConnectionTime = millis();

}

