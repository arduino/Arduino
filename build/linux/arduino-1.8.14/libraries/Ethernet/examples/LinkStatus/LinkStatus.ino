/*
  Link Status
  This sketch prints the ethernet link status. When the
  ethernet cable is connected the link status should go to "ON".
  NOTE: Only WizNet W5200 and W5500 are capable of reporting
  the link status. W5100 will report "Unknown".
  Hardware:
   - Ethernet shield or equivalent board/shield with WizNet 5200/5500
  Written by Cristian Maglie
  This example is public domain.
*/

#include <SPI.h>
#include <Ethernet.h>

void setup() {
  // You can use Ethernet.init(pin) to configure the CS pin
  //Ethernet.init(10);  // Most Arduino shields
  //Ethernet.init(5);   // MKR ETH shield
  //Ethernet.init(0);   // Teensy 2.0
  //Ethernet.init(20);  // Teensy++ 2.0
  //Ethernet.init(15);  // ESP8266 with Adafruit Featherwing Ethernet
  //Ethernet.init(33);  // ESP32 with Adafruit Featherwing Ethernet

  Serial.begin(9600);
}

void loop() {
  auto link = Ethernet.linkStatus();
  Serial.print("Link status: ");
  switch (link) {
    case Unknown:
      Serial.println("Unknown");
      break;
    case LinkON:
      Serial.println("ON");
      break;
    case LinkOFF:
      Serial.println("OFF");
      break;
  }
  delay(1000);
}
