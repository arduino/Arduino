/*
  Conditionals - If statement
 
  This example demonstrates the use of if() statements.
  It reads the state of a potentiometer (an analog input) and turns on an LED
  only if the LED goes above a certain threshold level. It prints the analog value
  regardless of the level.
 
  The circuit:
  * potentiometer connected to analog pin A3.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +3V and ground
  * LED connected from digital pin 2 to ground
 
  * Note: On the MSP-EXP430G2 LaunchPad boards, there is already an LED connected 
    to pin 2, so you don't need any extra components for this example.
 
  created 17 Jan 2009
  by Tom Igoe
  modified 16 Apr 2013
  by Tom Igoe

  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  * Potentiometer
  * 220 ohm resistor
  * LED
  * hook-up wire
  
  This example code is in the public domain.
 
*/
 
// These constants won't change:
const int analogPin = A3;    // pin that the sensor is attached to
const int ledPin = 2;       // pin that the LED is attached to
const int threshold = 400;   // an arbitrary threshold level that's in the range of the analog input

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);

  // if the analog value is high enough, turn on the LED:
  if (analogValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } 
  else {
    digitalWrite(ledPin,LOW); 
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability
}

