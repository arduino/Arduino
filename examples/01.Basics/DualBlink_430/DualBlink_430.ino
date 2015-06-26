//
//  DualBlink_430
//
//  © Rei VILO 2012
// 
// Revision
//   Rei VILO, May 21, 2012 - Updated with GREEN_LED, RED_LED and PUSH2
//   Rei VILO, Sep 25, 2012 - Support for FraunchPad

void setup() {                
  // initialise digital pins as outputs
  pinMode(RED_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);     
}

void loop() {
  digitalWrite(RED_LED, HIGH);   // set the LED on
  delay(1000);                // wait for a second
  digitalWrite(GREEN_LED, HIGH);   // set the LED on
  digitalWrite(RED_LED, LOW);    // set the LED off
  delay(2000);              
  digitalWrite(RED_LED, HIGH); 
  delay(3000);              
  digitalWrite(GREEN_LED, LOW);  
  digitalWrite(RED_LED, LOW);  
  delay(500);              
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  delay(500);              
  digitalWrite(GREEN_LED, LOW); 
  digitalWrite(RED_LED, LOW); 
  delay(500);              
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  delay(500);              
  digitalWrite(GREEN_LED, LOW); 
  digitalWrite(RED_LED, LOW); 
  delay(500);              
}
