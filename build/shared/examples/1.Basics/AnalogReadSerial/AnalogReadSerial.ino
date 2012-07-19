/*
  AnalogReadSerial
 Reads an analog input on pin 0, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

void setup() {
  Serial.begin(9600); // msp430g2231 must use 4800
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
}
