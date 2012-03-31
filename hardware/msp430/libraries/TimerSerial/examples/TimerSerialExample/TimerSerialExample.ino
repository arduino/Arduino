/*
 Timer based serial test
 
 Echo back whatever is recieved.
 
 The circuit: 
 * TX is digital pin 3 (on Launchpad this is connected to the USB UART)
 * RX is digital pin 4 (on Launchpad this is connected to the USB UART)
 
 This example code is in the public domain.
 
 */
#include <TimerSerial.h>

TimerSerial mySerial; // Create a new TimerSerial object

void setup()  
{
  mySerial.begin(); // only 9600 baud is supported
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
   mySerial.write(mySerial.read());
}
