/* TestPinMode
   Tests the 4 pin modes

   connect pin 2 to pin 3
 
output 
  TestPinMode setup
  connect pin 2 to 3
  input pullup   1
  input pulldown 0
  input          1 0
  input          1 0
  input          1 0
  input          1 0
*/


#define LED     D1_LED
#define OUT     2  
#define IN      3   
#define INUP    4  
#define INDOWN  5  

void setup() {                
  Serial.begin(9600);
  Serial.println("\nTestPinMode setup");
  Serial.println("connect pin 2 to pin 3");
  pinMode(LED   ,OUTPUT);     
  pinMode(OUT   ,OUTPUT);     
  pinMode(IN    ,INPUT);     
  pinMode(INUP  ,INPUT_PULLUP);     
  pinMode(INDOWN,INPUT_PULLDOWN);     

  Serial.print("input pullup   ");
  Serial.println(digitalRead(INUP));
  Serial.print("input pulldown ");
  Serial.println(digitalRead(INDOWN));
}

void loop() {
  digitalWrite(LED, HIGH);   
  digitalWrite(OUT, HIGH);   
  Serial.print("input          ");
  Serial.print(digitalRead(IN));
  delay(1000);               
  digitalWrite(LED, LOW);    
  digitalWrite(OUT, LOW);    
  Serial.print(" ");
  Serial.println(digitalRead(IN));
  delay(1000);               
}
