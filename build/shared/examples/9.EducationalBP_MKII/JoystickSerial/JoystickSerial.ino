/*
 JoystickSerial example for Educational BoosterPack MK II
 http://boosterpackdepot.info/wiki/index.php?title=Educational_BoosterPack_MK_II
 
 Move the joystick around in x & y axes (pin 2 & 26) or 
 press straight down on the joystick center button. LaunchPad
 will report the joystick readings back to the PC through 
 the serial port.
 
 
 The circuit:
 * Joystick X attached to pin 2
 * Joystick Y attached to pin 26
 * Joystick Sel attached to pin 5 
 * LaunchPad On-board UART Serial connection via USB to PC


 Dec 03 2013 for Educational BoosterPack MK II
 by Dung Dang
 
 This example code is in the public domain.
 
 */

// constants won't change. They're used here to 
// set pin numbers:
const int joystickSel = 5;     // the number of the joystick select pin
const int joystickX = 2;       // the number of the joystick X-axis analog
const int joystickY =  26;     // the number of the joystick Y-axis analog


// variables will change:
int joystickSelState = 0;      // variable for reading the joystick sel status
int joystickXState, joystickYState ; 

void setup() {

   
  // initialize the pushbutton pin as an input:
  pinMode(joystickSel, INPUT_PULLUP);     
  
  Serial.begin(9600);  
}

void loop(){
  // read the analog value of joystick x axis
  joystickXState = analogRead(joystickX);
  Serial.print("Joystick X = ");
  Serial.print(joystickXState);
  
  // read the analog value of joystick y axis
  joystickYState = analogRead(joystickY);
  Serial.print("   Joystick Y = ");
  Serial.print(joystickYState);
    
  // read the state of the joystick select button value:
  joystickSelState = digitalRead(joystickSel);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (joystickSelState == LOW) {     
    Serial.println("   Joystick Center = pressed!");
  } 
  else {
    // turn LED off:
    Serial.println("   Joystick Center = not pressed!");
  }
  delay(300);
}
