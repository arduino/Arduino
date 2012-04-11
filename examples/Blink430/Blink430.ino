//
//  Blink430
//
//  © Rei VILO 2012
// 
//  LED1 on pin 2
//  LED2 on pin 14
//

#define LED1  2
#define LED2 14


void setup() {                
  // initialise digital pins as outputs
  pinMode(LED1, OUTPUT);     
  pinMode(LED2, OUTPUT);     
}

void loop() {
  digitalWrite(LED1, HIGH);   // set the LED on
  delay(1000);                // wait for a second
  digitalWrite(LED2, HIGH);   // set the LED on
  digitalWrite(LED1, LOW);    // set the LED off
  delay(2000);              
  digitalWrite(LED1, HIGH); 
  delay(3000);              
  digitalWrite(LED2, LOW);  
  digitalWrite(LED1, LOW);  
  delay(500);              
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, HIGH);
  delay(500);              
  digitalWrite(LED2, LOW); 
  digitalWrite(LED1, LOW); 
  delay(500);              
  digitalWrite(LED2, HIGH);
  digitalWrite(LED1, HIGH);
  delay(500);              
  digitalWrite(LED2, LOW); 
  digitalWrite(LED1, LOW); 
  delay(500);              
}
