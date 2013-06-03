/*
  This example reads three analog sensors (potentiometers are easiest)
  and sends their values serially. The Processing code at the bottom
  take those three values and use them to change the background color of the screen.

  The circuit:
  * potentiometers attached to analog inputs 0, 1, and 2

  created 2 Dec 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald
  modified 16 April 2013
  by Sean Alvarado
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * (3) potentiometers
  * (3) 10K ohm resistors
  * breadboard
  * hook-up wire

  This example code is in the public domain.
*/

const int redPin = A0;  // sensor to control red color
const int greenPin = A1; // sensor to control green color
const int bluePin = A2; // sensor to control blue color

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print(analogRead(redPin));
  Serial.print(",");
  Serial.print(analogRead(greenPin));
  Serial.print(",");
  Serial.println(analogRead(bluePin));
}

/* 
// Processing code for this example

// This example code is in the public domain.

import processing.serial.*;

float redValue = 0; // red value
float greenValue = 0; // green value
float blueValue = 0; // blue value

Serial myPort;

void setup() {
  size(200, 200);

  // List all the available serial ports
  println(Serial.list());

  // Open whatever port is the one you're using with the LaunchPad
  myPort = new Serial(this, Serial.list()[0], 9600);

  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
}

void draw() {
  // set the background color with the color values:
  background(redValue, greenValue, blueValue);
}

void serialEvent(Serial myPort) { 
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // split the string on the commas and convert the 
	// resulting substrings into an integer array:
	float[] colors = float(split(inString, ","));
	// if the array has at least three elements, you know
	// you got the whole thing. Put the numbers in the
	// color variables:
	if (colors.length >=3) {
	  // map them to the range 0-255:
	  redValue = map(colors[0], 0, 1023, 0, 255);
	  greenValue = map(colors[1], 0, 1023, 0, 255);
	  blueValue = map(colors[2], 0, 1023, 0, 255);
    }
  }
}
*/
