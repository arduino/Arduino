/*
  Physical Pixel

  An example of using the Launchpad to receive data from the 
  computer. In this case, the Launchpad turns on an LED when
  it receives the character 'H', and turns off the LED when it
  receives the character 'L'.

  The data can be sent from the Energia serial monitor, or another
  program like Processing.

  The circuit:
  * LED connected from digital pin 14 to ground

  created 2006
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe and Scott Fitzgerald
  Modified 15 April 2013
  By Sean Alvarado

  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  
  This example code is in the public domain.

*/

const int ledPin = 14; // the pin that the Green LED that is    attached to on Launchpad 
int incomingByte; // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      digitalWrite(ledPin, HIGH);
    } 
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      digitalWrite(ledPin, LOW);
    }
  }
}

/* 
// Processing code for this example

// mouseover serial 

// Demonstrates how to send data to the Launchpad I/O board, in order to 
// turn ON a light if the mouse is over a square and turn it off 
// if the mouse is not. 

// created 2003-4
// based on examples by Casey Reas and Hernando Barragan
// modified 30 Aug 2011
// by Tom Igoe
// modified 15 April 2013
// by Sean Alvarado
// This example code is in the public domain.



import processing.serial.*; 

float boxX;
float boxY;
int boxSize = 20;
boolean mouseOverBox = false;

Serial port; 

void setup() {
  size(200, 200);
  boxX = width/2.0;
  boxY = height/2.0;
  rectMode(RADIUS); 

  // List all the available serial ports in the output pane. 
  // You will need to choose the port that the Launchpad is 
  // connected to from this list. The first port in the list is 
  // port #0 and the third port in the list is port #2. 
  println(Serial.list()); 

  // Open the port that the Launchpad is connected to (in this case #0) 
  // Make sure to open the port at the same speed Energia is using (9600bps) 
  port = new Serial(this, Serial.list()[0], 9600); // In the [] you will place the number corresponding to the COM your LaunchPad is connected to

}

void draw() { 
  background(0);

  // Test if the cursor is over the box 
  if (mouseX > boxX-boxSize && mouseX < boxX+boxSize && mouseY > boxY-boxSize && mouseY < boxY+boxSize) {
    mouseOverBox = true; 
    // draw a line around the box and change its color:
    stroke(255); 
    fill(153);
    // send an 'H' to indicate mouse is over square:
    port.write('H'); 
  } 
  else {
    // return the box to its inactive state:
    stroke(153);
    fill(153);
    // send an 'L' to turn the LED off: 
    port.write('L'); 
    mouseOverBox = false;
  }

  // Draw the box
  rect(boxX, boxY, boxSize, boxSize);
}

*/