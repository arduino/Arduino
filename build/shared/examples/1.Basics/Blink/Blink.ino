/*
  Blink
  The basic Energia example.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Pin 2 has an LED connected on MSP430 boards, has a name 'RED_LED' in the code.
  
  Hardware Required:
  * MSP-EXP430G2 LaunchPad
  
  This example code is in the public domain.
*/
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(RED_LED, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
