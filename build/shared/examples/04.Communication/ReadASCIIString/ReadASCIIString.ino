/*
  Reading a serial ASCII-encoded string.

  This sketch demonstrates the Serial parseInt() function.
  It looks for an ASCII string of comma-separated values.
  It parses them into ints, and uses those to fade an RGB LED.

  Circuit: Common-anode RGB LED wired like so:
  * Red cathode: digital pin 9
  * Green cathode: digital pin 10
  * blue cathode: digital pin 12
  * anode: +3V

  created 13 Apr 2012
  by Tom Igoe
  Modified 12 Apr 2013
  by Sean Alvarado
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * breadboard
  * hook-up wire
  * Common anode RGB LED
  * (3) 220 ohm resistors
  
  This example code is in the public domain.
*/

// pins for the LEDs:
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 12;

void setup() {
 // initialize serial:
 Serial.begin(9600);
 // make the pins outputs:
 pinMode(redPin, OUTPUT); 
 pinMode(greenPin, OUTPUT); 
 pinMode(bluePin, OUTPUT); 

}

void loop() {
// if there's any serial available, read it:
while (Serial.available() > 0) {

  // look for the next valid integer in the incoming serial stream:
  int red = Serial.parseInt(); 
  // do it again:
  int green = Serial.parseInt(); 
  // do it again:
  int blue = Serial.parseInt(); 

  // look for the newline. That's the end of your
  // sentence:
  if (Serial.read() == '\n') {
  // constrain the values to 0 - 255 
  // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
  red = constrain(red, 0, 255);
  green = constrain(green, 0, 255);
  blue = constrain(blue, 0, 255);

  // fade the red, green, and blue legs of the LED: 
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);

  // print the three numbers in one string as hexadecimal:
  Serial.print(red, HEX);
  Serial.print(green, HEX);
  Serial.println(blue, HEX);
  }
 }
}