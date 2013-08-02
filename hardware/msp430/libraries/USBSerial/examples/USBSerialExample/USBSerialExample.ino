/*
  USB serial test
 
 Receives from the hardware serial, sends to USB serial.
 Receives from USB serial, sends to hardware serial.
 
 
 created back in the mists of time
 modified 31 July 2013
 by Stefan Schauer
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */
#include <USBSerial.h>

USBSerial mySerial(1); // USB

void setup()  
{
  digitalWrite(RED_LED, LOW);    // set the LED off
  digitalWrite(GREEN_LED, LOW);    // set the LED off
  pinMode(RED_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);     
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Goodnight moon!");
  digitalWrite(RED_LED, HIGH);    // set the LED on

  // open the USBSerial port
  mySerial.begin();
  mySerial.println("Hello USB world");
  digitalWrite(GREEN_LED, HIGH);    // set the LED on
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}  