/*
  Graph

  A simple example of communication from the Launchpad to the computer:
  the value of analog input 0 is sent out the serial port. We call this "serial"
  communication because the connection appears to both the Launchpad and the
  computer as a serial port, even though it may actually use
  a USB cable. Bytes are sent one after another (serially) from the Launchpad
  to the computer.

  You can use the Energia serial monitor to view the sent data, or it can
  be read by Processing or another program capable of reading 
  data from a serial port. The Processing code below graphs the data received 
  so you can see the value of the analog input changing over time.

  The circuit:
  Any analog input sensor can be attached to an analog pin.  
  For this example, a potentiometer is attached to analog pin 3. 

  created 2006
  by David A. Mellis
  modified 9 Apr 2012
  by Tom Igoe and Scott Fitzgerald
  Modified 15 April 2013
  By Sean Alvarado

  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * Potentiometer
  
  This example code is in the public domain.

*/

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  // send the value of analog input 3:
  Serial.println(analogRead(A3));
  // wait a bit for the analog-to-digital converter 
  // to stabilize after the last reading:
  delay(1000);
}

/* 
// Processing code for this example

// Graphing sketch


// This program takes ASCII-encoded strings
// from the serial port at 9600 baud and graphs them. It expects values in the
// range 0 to 1023, followed by a newline, or newline and carriage return

// Created 20 Apr 2005
// Updated 18 Jan 2008
// by Tom Igoe
// modified 16 April 2013
// by Sean Alvarado
// This example code is in the public domain.

import processing.serial.*;

Serial myPort; // The serial port
int xPos = 1; // horizontal position of the graph

void setup () {
  // set the window size:
  size(400, 300); 

  // List all the available serial ports
  println(Serial.list());
  // Open whatever port is the one you're using for the Launchpad.
  myPort = new Serial(this, Serial.list()[0], 9600);
  // don't generate a serialEvent() unless you get a newline character:
  myPort.bufferUntil('\n');
  // set inital background:
  background(0);
}
void draw () {
  // everything happens in the serialEvent()
}

void serialEvent (Serial myPort) {
  // get the ASCII string:
  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // trim off any whitespace:
    inString = trim(inString);
    // convert to an int and map to the screen height:
    float inByte = float(inString); 
    inByte = map(inByte, 0, 1023, 0, height);

    // draw the line:
    stroke(127,34,255);
    line(xPos, height, xPos, height - inByte);

    // at the edge of the screen, go back to the beginning:
    if (xPos >= width) {
      xPos = 0;
      background(0); 
    } 
    else {
      // increment the horizontal position:
      xPos++;
    }
  }
}
*/