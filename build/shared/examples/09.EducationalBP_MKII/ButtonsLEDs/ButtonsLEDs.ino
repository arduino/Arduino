/*
  Buttons & LEDs example for Educational BoosterPack MK II
http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Turns on and off Green & Blue light emitting diodes(LEDs) 
 connected to digital pins 38 & 37, when pressing pushbuttons
 attached to pins 33 & 32.
 
 
 The circuit:
 * LED attached from pin 13 to ground 
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 modified Apr 27 2012
 by Robert Wessels
 modified Dec 03 2013 - for Educational BoosterPack MK II
 by Dung Dang
 modified May 23 2014 - corrected pin for buttonOne
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonOne = 33;     // the number of the pushbutton pin
const int buttonTwo = 32;     // the number of the pushbutton pin
const int ledGreen =  38;      // the number of the LED pin
const int ledBlue =  37;      // the number of the LED pin

// variables will change:
int buttonOneState = 0;         // variable for reading the pushbutton #1 status
int buttonTwoState = 0;         // variable for reading the pushbutton #2 status

void setup() {
  // initialize the LED pins as  output:
  pinMode(ledGreen, OUTPUT);     
  pinMode(ledBlue, OUTPUT);     
   
  // initialize the pushbutton pin as an input:
  pinMode(buttonOne, INPUT_PULLUP);     
  pinMode(buttonTwo, INPUT_PULLUP);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonOneState = digitalRead(buttonOne);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonOneState == LOW) {     
    // turn LED on:    
    digitalWrite(ledGreen, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledGreen, LOW); 
  }
  // read the state of the pushbutton value:
  buttonTwoState = digitalRead(buttonTwo);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonTwoState == LOW) {     
    // turn LED on:    
    digitalWrite(ledBlue, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledBlue, LOW); 
  }  
}
