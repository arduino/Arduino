/*
  DHCP-based hostname printer

  Circuit:
   Ethernet shield attached to pins 10, 11, 12, 13

  created 10 Dec 2016
  by mykh
*/

#include <Ethernet.h>

// MAC address
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
};
// Hostname
const char* hostname = "myarduino";

// Initialize the Ethernet client library
EthernetClient client;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // this check is only needed on the Leonardo:
  while (!Serial) {
    ;
  }

  // start the Ethernet connection:
  Serial.println("Setup...");
  while (Ethernet.begin(mac, hostname) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    delay(10000);
    Serial.println("Reconnecting...");
  }
  
  // print your hostname:
  Serial.print("My Hostname: ");
  Serial.println(Ethernet.hostname());
}

void loop() {
  Ethernet.maintain();
}
