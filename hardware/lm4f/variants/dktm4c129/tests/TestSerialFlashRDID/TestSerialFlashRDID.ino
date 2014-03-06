/* 
   This is a SPI example to show reading the dktm4c129 serial flash, 
   Macronix-MX66L512 part connected via J7. This example uses the SSI3
   controller and PQ_1 for CS signal, chipSelectPin. Replace jumper 
   J7:SPI_DAT1-J7:PF0 with J7:SPI_DAT1 J30:PQ3. This example or SPI
   library doesn't support splitting SSI3 on port Q and port F. Look
   at SPI.cpp for how SSI1 is split on port B and E as an example to
   accomplish this.

   The Macronix-MX66L512 doesn't like /CS to toggle per byte, so 
   this sketch manually controls /CS, chipSelectPin. This serial flash
   should respond with 0xC2 0x20 0x1A from a RDID, 0x9F, command, see
   datasheet "Table 6. ID Definitions". 
*/

#include <SPI.h>

#define chipSelectPin PQ_1
#define RDID 0x9F

SPIClass mySPI(5); // 5 is SSI3 on port Q, see SPI.cpp for others

void setup() {
  Serial.begin(9600);
  delay(1000); // wait a bit serial monitor to open

  Serial.println("TestSerialFlashRDID setup");

  mySPI.begin();
  pinMode(chipSelectPin, OUTPUT); // have to set CS pin as output after spi.begin
}

void loop() {
  uint8_t rv;
  Serial.print(millis());
  digitalWrite(chipSelectPin, LOW);
  mySPI.transfer(RDID);
  rv = mySPI.transfer(0x00);
  Serial.print(" 0x");
  Serial.print(rv,HEX);
  rv = mySPI.transfer(0x00);
  Serial.print(" 0x");
  Serial.print(rv,HEX);
  rv = mySPI.transfer(0x00);
  Serial.print(" 0x");
  Serial.println(rv,HEX);
  digitalWrite(chipSelectPin, HIGH);
  delay(1000);
}

