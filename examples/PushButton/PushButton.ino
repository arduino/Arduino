//
//  PushButton
//
//  © Rei VILO 2012
// 
//  LED1 on pin 2
//  LED2 on pin 14
//  PUSH2 on pin 5
//
//  Press push 2 to light on 
//  red -> green -> red+green -> none -> ...
//

const uint8_t LED1 = 2;
const uint8_t LED2 = 14;
const uint8_t PUSH2 = 5;

void setup() {                
  // initialise digital pins as outputs
  pinMode(LED1, OUTPUT);     
  pinMode(LED2, OUTPUT);     
  pinMode(PUSH2, INPUT);     
  lights(0);
}

void lights(uint8_t ui) {
  digitalWrite(LED1, bitRead(ui, 0) ? HIGH: LOW);  
  digitalWrite(LED2, bitRead(ui, 1) ? HIGH: LOW);  
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

