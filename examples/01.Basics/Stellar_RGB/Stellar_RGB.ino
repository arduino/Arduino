//  
//  StellarRGB
//
//  © Rei VILO 2012
//
// Based on 
//   DualBlink_430
//
// Revision
//   Rei VILO, May 21, 2012 - Updated with GREEN_LED, RED_LED and PUSH2
//   Rei VILO, Sep 25, 2012 - Support for FraunchPad
//   Rei VILO, Oct 24, 2012 - Support for LM4

void setup() {                
  // initialise digital pins as outputs
  pinMode(RED_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);     
  pinMode(BLUE_LED, OUTPUT);     
}

void loop() {
  digitalWrite(RED_LED, HIGH);   // set the LED on
  delay(1000);                // wait for a second
  digitalWrite(GREEN_LED, HIGH);   // set the LED on
  delay(1000);                // wait for a second
  digitalWrite(RED_LED, LOW);    // set the LED off
  delay(1000);              
  digitalWrite(BLUE_LED, HIGH); 
  delay(1000);              
  digitalWrite(GREEN_LED, LOW);  
  delay(1000);              
  digitalWrite(BLUE_LED, HIGH);  
  delay(1000);              
  digitalWrite(RED_LED, HIGH);
  delay(1000);              
  digitalWrite(RED_LED, LOW); 
  delay(1000);              
  digitalWrite(BLUE_LED, HIGH); 
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  delay(1000);              
  digitalWrite(BLUE_LED, LOW); 
  digitalWrite(GREEN_LED, LOW); 
  digitalWrite(RED_LED, LOW); 
  delay(1000);              
}
