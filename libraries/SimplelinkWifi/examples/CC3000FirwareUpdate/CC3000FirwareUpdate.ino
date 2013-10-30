/*

 This Sketch will update the firmware of the CC3000 to 
 a version that works with this library.
 The fimware update takes about 10. If the upgrade is successfull
 the RED and GREEN LEDs will flash.
 
 Circuit:
 * WiFi BoosterPack
 
 Created: October 24, 2013 by Robert Wessels (http://energia.nu)
 */

#include <SPI.h>
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  // Gives you time to open the Serial monitor
  delay(5000);

  // Initialize the LEDs and turn them OFF
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  // Set the CC3000 pins
  WiFi.setCSpin(18);  // 18: P2_2 @ F5529, PE_0 @ LM4F/TM4C
  WiFi.setENpin(2);   //  2: P6_5 @ F5529, PB_5 @ LM4F/TM4C
  WiFi.setIRQpin(19); // 19: P2_0 @ F5529, PB_2 @ LM4F/TM4C

  Serial.println("Updating CC3000 Firmware");
  Serial.println("RED and GREEN LED's will flash when complete");

  // Initialize the CC3000
  WiFi.begin();
  
  // Begin firmware update
  WiFi.updateFirmware();
  
  Serial.println("Firmware update success :-)");
  
  // Print the new firmware version
  printFirmwareVersion();
}

uint8_t state = 0;

void loop() {
  state = !state;
  digitalWrite(RED_LED, state);
  digitalWrite(GREEN_LED, !state);
  delay(500);
}

void printFirmwareVersion() {
  uint8_t *ver = WiFi.firmwareVersion();
  Serial.print("Version: ");
  Serial.print(ver[0]);
  Serial.print(".");
  Serial.println(ver[1]);  
}
