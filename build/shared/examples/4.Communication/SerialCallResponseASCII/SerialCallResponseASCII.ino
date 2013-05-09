/*
  Serial Call and Response in ASCII

  This program sends an ASCII A (byte of value 65) on startup
  and repeats that until it gets some data in.
  Then it waits for a byte in the serial port, and 
  sends three ASCII-encoded, comma-separated sensor values, 
  truncated by a linefeed and carriage return, 
  whenever it gets a byte in.

  Thanks to Greg Shakar and Scott Fitzgerald for the improvements

  The circuit:
  * potentiometers attached to analog inputs 0 and 1 
  * pushbutton attached to digital I/O 2


  Created 26 Sept. 2005
  by Tom Igoe
  modified 24 Apr 2012
  by Tom Igoe and Scott Fitzgerald
  modified 24 Apr 2013
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
  // start serial port at 9600 bps and wait for port to open:
  Serial.begin(9600);

  pinMode(2, INPUT); // digital sensor is on digital pin 2
  establishContact(); // send a byte to establish contact until receiver responds 
}

void loop()
{
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    // read first analog input:
    firstSensor = analogRead(A0);
    // read second analog input:
    secondSensor = analogRead(A1);
    // read switch, map it to 0 or 255L
    thirdSensor = map(digitalRead(2), 0, 1, 0, 255); 
    // send sensor values:
    Serial.print(firstSensor);
    Serial.print(",");
    Serial.print(secondSensor);
    Serial.print(",");
    Serial.println(thirdSensor); 
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.println("0,0,0"); // send an initial string
    delay(300);
  }
}

/*
// Processing code to run with this example:

// This example code is in the public domain.

import processing.serial.*; // import the Processing serial library
Serial myPort; // The serial port

float bgcolor; // Background color
float fgcolor; // Fill color
float xpos, ypos; // Starting position of the ball

void setup() {
  size(640,480);

  // List all the available serial ports
  println(Serial.list());

  // Change the 0 to the appropriate number of the serial port
  // that your LaunchPad is connected to.
  myPort = new Serial(this, Serial.list()[0], 9600);

  // read bytes into a buffer until you get a linefeed (ASCII 10):
  myPort.bufferUntil('\n');

  // draw with smooth edges:
  smooth();
}

void draw() {
  background(bgcolor);
  fill(fgcolor);
  // Draw the shape
  ellipse(xpos, ypos, 20, 20);
}

// serialEvent method is run automatically by the Processing applet
// whenever the buffer reaches the byte value set in the bufferUntil() 
// method in the setup():

void serialEvent(Serial myPort) { 
  // read the serial buffer:
  String myString = myPort.readStringUntil('\n');
  // if you got any bytes other than the linefeed:
  myString = trim(myString);

  // split the string at the commas
  // and convert the sections into integers:
  int sensors[] = int(split(myString, ','));

  // print out the values you got:
  for (int sensorNum = 0; sensorNum < sensors.length; sensorNum++) {
    print("Sensor " + sensorNum + ": " + sensors[sensorNum] + "\t"); 
  }
  // add a linefeed after all the sensor values are printed:
  println();
  if (sensors.length > 1) {
    xpos = map(sensors[0], 0,1023,0,width);
    ypos = map(sensors[1], 0,1023,0,height);
    fgcolor = sensors[2];
  }
  // send a byte to ask for more data:
  myPort.write("A");
}

*/
