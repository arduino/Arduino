//
//  PushButton_430
//
//  © Rei VILO 2012
// 
//  RED_LED on pin 2
//  GREEN_LED on pin 14
//  PUSH2 on pin 5
//
//  Press push 2 to light on 
//  red -> green -> red+green -> none -> ...
//
// Revision
//   Rei VILO, May 21, 2012 - Updated with GREEN_LED, RED_LED and PUSH2

void setup() {                
  // initialise digital pins as outputs
  pinMode(RED_LED, OUTPUT);     
  pinMode(GREEN_LED, OUTPUT);     
  pinMode(PUSH2, INPUT_PULLUP);     
  lights(0);
}

void lights(uint8_t ui) {
  digitalWrite(RED_LED, bitRead(ui, 0) ? HIGH: LOW);  
  digitalWrite(GREEN_LED, bitRead(ui, 1) ? HIGH: LOW);  
}

uint8_t var = 0;

void loop() {

  if (digitalRead(PUSH2)==LOW) {
    while (digitalRead(PUSH2)==LOW);
    var++;
    var%=4;
    lights(var);
    delay(100);
  }    
}

