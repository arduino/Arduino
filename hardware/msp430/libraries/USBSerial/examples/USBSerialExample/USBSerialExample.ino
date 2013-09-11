/*
  USB serial test
 
 Receives from USB serial and Echos back the data.
 
 
 created back in the mists of time
 modified 31 July 2013
 by Stefan Schauer
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */
#include <USBSerial.h>

USBSerial mySerial(1); // USB
uint8_t i = 0;

void setup()  
{
  digitalWrite(RED_LED, LOW);    // set the LED off
  digitalWrite(GREEN_LED, LOW);    // set the LED off
  pinMode(RED_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);     
  
  // open the USBSerial port
  mySerial.begin();
  mySerial.println("Hello USB world");
  digitalWrite(GREEN_LED, HIGH);    // set the LED on
}

void loop() // run over and over
{
  if (mySerial.available())
  {
    mySerial.write(mySerial.read());
    i ^= HIGH;                   // Toggle value
    digitalWrite(RED_LED, i);    // toggle the LED
  }

}  