#include "stdint.h"
#include "IPAddress.h"

// IPAddress::IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet)
IPAddress ipoctet(78,79,80,81);

// IPAddress::IPAddress(uint32_t address)
uint32_t u = 45678901;
IPAddress ip32(u);

const uint8_t address[] = "1234";
// IPAddress::IPAddress(const uint8_t *address)
IPAddress ipu8(address);


void setup() {
  Serial.begin(9600);
  Serial.println("TestIPAddress");

  ipoctet.printTo(Serial);
  Serial.println();

  ip32.printTo(Serial);
  Serial.println();
// IPAddress& IPAddress::operator=(const uint8_t *address)
  ip32 = address;
  ip32.printTo(Serial);
  Serial.println("\n");

  ipu8.printTo(Serial);
  Serial.println();
// IPAddress& IPAddress::operator=(uint32_t address)
  ipu8 = u;
  ipu8.printTo(Serial);
  Serial.println();

  if (ip32 == address) {
    Serial.println("true");
  } else {
    Serial.println("false");
  }
}

void loop() {
}
