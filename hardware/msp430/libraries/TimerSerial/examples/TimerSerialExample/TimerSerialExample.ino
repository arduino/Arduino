/*
 Timer based serial test
 
 Echo back whatever is recieved.
 
 The circuit: 
 * TX is digital pin 3 (on Launchpad this is connected to the USB UART) P1.1
 * RX is digital pin 4 (on Launchpad this is connected to the USB UART) P1.2
 
 For V1.5 Launchpads the TX/RX J3 pins should be aligned with the other jumpers

 This example code is in the public domain.
 
 */
#include <TimerSerial.h>

TimerSerial mySerial; // Create a new TimerSerial object

void setup()  
{
  mySerial.begin(9600); // msp430g2231 must use 4800 or less
  mySerial.println("Hello, world?");
}

void loop() // run over and over
{
  if (mySerial.available())
   mySerial.write(mySerial.read());
}
