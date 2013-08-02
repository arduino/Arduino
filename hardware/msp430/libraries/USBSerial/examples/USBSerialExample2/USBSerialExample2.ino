/*
  USB serial multiple serial test
 
 Receives from the hardware serial, sends to USB serial.
 Receives from USB serial, sends to hardware serial.
 
 
 created back in the mists of time
 modified 04 July 2013
 by Stefan Schauer
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */
#include <USBSerial.h>

USBSerial mySerial(1); // USB

void setup()  
{

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  pinMode(PUSH2, INPUT_PULLUP);     
  
  digitalWrite(RED_LED, HIGH);    // set the LED off
  digitalWrite(GREEN_LED, LOW);    // set the LED off
  pinMode(RED_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);     
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Goodnight moon!");

  while (digitalRead(PUSH2) == HIGH);

  // set the data rate for the USBSerial port
  digitalWrite(GREEN_LED, LOW);    // set the LED off
  mySerial.begin();
  digitalWrite(RED_LED, HIGH);    // set the LED on
  mySerial.println("Hello, world?");
  Serial.println("Hello Serial 1");

}

void loop() // run over and over
{
  digitalWrite(GREEN_LED, HIGH);    // set the LED on
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
  digitalWrite(GREEN_LED, LOW);    // set the LED off
  
  if (digitalRead(PUSH2) == LOW)
  {
    Serial.println("serial 1");
    mySerial.println("serial USB");
  }  
  
}  