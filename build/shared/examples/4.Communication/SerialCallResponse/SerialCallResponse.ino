/*
  Serial Call and Response

  This program sends an ASCII A (byte of value 65) on startup
  and repeats that until it gets some data in.
  Then it waits for a byte in the serial port, and 
  sends three sensor values whenever it gets a byte in.

  Thanks to Greg Shakar and Scott Fitzgerald for the improvements

  The circuit:
  * potentiometers attached to analog inputs 0 and 1 
  * pushbutton attached to digital I/O 11

  Created 26 Sept. 2005
  by Tom Igoe
  modified 24 April 2012
  by Tom Igoe and Scott Fitzgerald
  Modified 19 April 2013
  By Sean Alvarado
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * (2) potentiometers
  * momentary switch/button
  * (3) 10K ohm resistors
  * breadboard
  * hook-up wire

  This example code is in the public domain.

*/
int firstSensor = 0; // first analog sensor
int secondSensor = 0; // second analog sensor
int thirdSensor = 0; // digital sensor
int inByte = 0; // incoming serial byte

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);

  pinMode(11, INPUT); // digital sensor is on digital pin 11
  establishContact(); // send a byte to establish contact until receiver responds 
}

void loop()
{
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    // read first analog input, divide by 4 to make the range 0-255:
    firstSensor = analogRead(A0)/4;
    // delay 10ms to let the ADC recover:
    delay(10);
    // read second analog input, divide by 4 to make the range 0-255:
    secondSensor = analogRead(A1)/4;
    // read switch, map it to 0 or 255L
    thirdSensor = map(digitalRead(11), 0, 1, 0, 255); 
    // send sensor values:
    Serial.write(firstSensor);
    Serial.write(secondSensor);
    Serial.write(thirdSensor); 
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println('A'); // send a capital A
    delay(300);
  }
}

/*
// Processing sketch to run with this example:

// This example code is in the public domain.

import processing.serial.*;

int bgcolor; // Background color
int fgcolor; // Fill color
Serial myPort; // The serial port
int[] serialInArray = new int[3]; // Where we'll put what we receive
int serialCount = 0; // A count of how many bytes we receive
int xpos, ypos; // Starting position of the ball
boolean firstContact = false; // Whether we've heard from the microcontroller

void setup() {
  size(256, 256); // Stage size
  noStroke(); // No border on the next thing drawn

  // Set the starting position of the ball (middle of the stage)
  xpos = width/2;
  ypos = height/2;

  // Print a list of the serial ports, for debugging purposes:
  println(Serial.list());

  // I know that the first port in the serial list on my mac
  // is always my FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  background(bgcolor);
  fill(fgcolor);
  // Draw the shape
  ellipse(xpos, ypos, 20, 20);
}

void serialEvent(Serial myPort) {
  // read a byte from the serial port:
  int inByte = myPort.read();
  // if this is the first byte received, and it's an A,
  // clear the serial buffer and note that you've
  // had first contact from the microcontroller. 
  // Otherwise, add the incoming byte to the array:
  if (firstContact == false) {
    if (inByte == 'A') { 
      myPort.clear(); // clear the serial port buffer
      firstContact = true; // you've had first contact from the microcontroller
      myPort.write('A'); // ask for more
    } 
  } 
  else {
    // Add the latest byte from the serial port to array:
    serialInArray[serialCount] = inByte;
    serialCount++;

    // If we have 3 bytes:
    if (serialCount > 2 ) {
      xpos = serialInArray[0];
      ypos = serialInArray[1];
      fgcolor = serialInArray[2];

      // print the values (for debugging purposes only):
      println(xpos + "\t" + ypos + "\t" + fgcolor);

      // Send a capital A to request new sensor readings:
      myPort.write('A');
     // Reset serialCount:
     serialCount = 0;
    }
  }
}
*/
