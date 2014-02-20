/*
  Telnet client
 
 This sketch connects to a telnet server.  You'll need a telnet server 
 to test. netcat also works using 'nc -l 23'

 created 14 Sep 2010
 by Tom Igoe

 modified 9 Feb 2014
 by Craig Hollabaugh
  removed SPI
  added connection info prints
  added re-connect after timeout or disconnect
 
 */

#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,177);

// Enter the IP address of the server you're connecting to:
IPAddress server(192,168,1,149); 
#define TELNETPORT 23

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 23 is default for telnet;
EthernetClient client;

void connect() {
  Serial.print("connecting to ");
  server.printTo(Serial);
  Serial.print(":");
  Serial.print(TELNETPORT);
  Serial.println();
  while(1) {
    // if you get a connection, report back via serial:
    if (client.connect(server, TELNETPORT)) {
      Serial.println("connected");
      break;
    } else {
      // if you didn't get a connection to the server:
      Serial.println("connection failed, retry in 5 seconds");
    }
    delay(5000);
  } 
}

void setup() {
  // start the Ethernet connection:
  Ethernet.begin(mac, ip);
  // start the serial library:
  Serial.begin(9600);

  Serial.println("\n\nTelnet client setup");
  Serial.print("my address    ");
  ip.printTo(Serial);
  Serial.println();

  // give the Ethernet controller a second to initialize
  delay(1000);

  connect();
}

void loop() {
  // if there are incoming bytes available 
  // from the server, read them and print them:
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  // as long as there are bytes in the serial queue,
  // read them and send them out the socket if it's open:
  while (Serial.available() > 0) {
    char inChar = Serial.read();
    if (client.connected()) {
      client.print(inChar); 
    }
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnected");
    connect();
  }
}
