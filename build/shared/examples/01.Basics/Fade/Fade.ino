/*
  Fade
 
  This example shows how to fade an LED on pin 14
  using the analogWrite() function.
 
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  
  This example code is in the public domain.
 
*/

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup()  { 
  // declare pin 14 to be an output:
  pinMode(GREEN_LED, OUTPUT);
} 

void loop()  { 
  // set the brightness of pin 9:
  analogWrite(GREEN_LED, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}