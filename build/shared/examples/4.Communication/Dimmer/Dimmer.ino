/*
  Dimmer

  Demonstrates the sending data from the computer to the Launchpad,
  in this case to control the brightness of an LED. The data is sent
  in individual bytes, each of which ranges from 0 to 255. The Launchpad
  reads these bytes and uses them to set the brightness of the LED.

  The circuit:
  LED attached from digital pin 2 to ground.
  Serial connection to Processing, Max/MSP, or another serial application

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald
  Modified 15 April 2013
  By Sean Alvarado

  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * LED
  * 220 ohm resistors
  
  This example code is in the public domain.

*/

const int ledPin = 14; // the pin that the Green LED is attached to on the Launchpad

void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  byte brightness;

  // check if data has been sent from the computer:
  if (Serial.available()) {
    // read the most recent byte (which will be from 0 to 255):
    brightness = Serial.read();
    // set the brightness of the LED:
    analogWrite(ledPin, brightness);
  }
}


/* 
// Processing code for this example
// Dimmer - sends bytes over a serial port
// by David A. Mellis
// Modified 16 April 2013
// by Sean Alvarado
// This example code is in the public domain.

import processing.serial.*;
Serial port;

void setup() {
  size(256, 150);

  println("Available serial ports:");
  println(Serial.list());

  // Uses the first port in this list (number 0). Change this to
  // select the port corresponding to your Launchpad. The last
  // parameter (e.g. 9600) is the speed of the communication. It
  // has to correspond to the value passed to Serial.begin() in your
  // Energia sketch.
  port = new Serial(this, Serial.list()[0], 9600); 

  // If you know the name of the port used by the Launchpad, you
  // can specify it directly like this.
  //port = new Serial(this, "COM1", 9600);
}

void draw() {
  // draw a gradient from black to white
  for (int i = 0; i < 256; i++) {
    stroke(i);
    line(i, 0, i, 150);
  }

  // write the current X-position of the mouse to the serial port as
  // a single byte
  port.write(mouseX);
}
*/