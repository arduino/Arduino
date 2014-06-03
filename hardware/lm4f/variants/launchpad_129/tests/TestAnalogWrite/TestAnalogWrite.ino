/* TestAnalogWrite
  PWM drives pin 7 
*/

unsigned char value;

#define LED D1_LED
#define PWMLED 7

void setup() {                
  Serial.begin(9600);
  Serial.println("\nTestAnalogWrite setup");
  Serial.println("PWM drives pin 7");
  pinMode(LED   ,OUTPUT);     
  pinMode(PWMLED,OUTPUT);     
  value = 200;
}

void loop() {
  digitalWrite(LED,HIGH);
  analogWrite(PWMLED,value);
  value += 10; 
  delay(50);               
  digitalWrite(LED,LOW);
  delay(50);               
}
