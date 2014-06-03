/*
  Joystick example for Educational BoosterPack MK II
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II

 Move the joystick around in x & y axes (pin 2 & 26) to adjust/mix the Green
 Press straight down on the joystick center button to turn on the Red LED.
 
 
 The circuit:
 * Joystick X attached to pin 2
 * Joystick Y attached to pin 26
 * Joystick Sel attached to pin 5 
 * Blue LED (analog) attached to pin 37  
 * Green LED (analog) attached to pin 38 
 * Red LED (digital) attached to pin 39 



 Dec 03 2013 for Educational BoosterPack MK II
 by Dung Dang
 
 This example code is in the public domain.
 
 */

// constants won't change. They're used here to 
// set pin numbers:
const int joystickSel = 5;     // the number of the joystick select pin
const int joystickX = 2;       // the number of the joystick X-axis analog
const int joystickY =  26;     // the number of the joystick Y-axis analog

const int ledBlue  =  37;      // the number of the LED pin
const int ledGreen =  38;      // the number of the LED pin
const int ledRed =  39;        // the number of the LED pin
// variables will change:
int joystickSelState = 0;      // variable for reading the joystick sel status
int joystickXState, joystickYState ; 

void setup() {
  // initialize the LED pins as  output:
  pinMode(ledRed, OUTPUT);     
   
  // initialize the pushbutton pin as an input:
  pinMode(joystickSel, INPUT_PULLUP);     

}

void loop(){
  // read the analog value of joystick x axis
  joystickXState = analogRead(joystickX);
  // scale the analog input range [0,4096] into the analog write range [0,255]
  joystickXState = map(joystickXState, 0, 4096, 0, 255);
  // output to the led
  analogWrite(ledGreen, joystickXState);
  
  // read the analog value of joystick y axis
  joystickYState = analogRead(joystickY);
  // scale the analog input range [0,4096] into the analog write range [0,255]
  joystickYState = map(joystickYState, 0, 4096, 0, 255);
  // output to the led
  analogWrite(ledBlue, joystickYState);
  
  // read the state of the joystick select button value:
  joystickSelState = digitalRead(joystickSel);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (joystickSelState == LOW) {     
    // turn LED on:    
    digitalWrite(ledRed, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledRed, LOW); 
  }
  
}
