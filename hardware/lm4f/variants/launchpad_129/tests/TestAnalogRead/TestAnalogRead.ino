/* TestAnalogRead
  This uses D1 and its current limiting resistor as a voltage source 
  between 3.3 and GND.
*/

#define LED D1_LED
#define IN  2

void setup() {                
  Serial.begin(9600);
  Serial.println("\nTestAnalogRead setup");
  Serial.println("touch pin 2 to junction between D1 and R33");
  Serial.println("should see about 540 from CH9 ADC");
  pinMode(LED   ,OUTPUT);     
  digitalWrite(LED, HIGH);   
  delay(2000);
}

void loop() {
  Serial.println(analogRead(IN));
  delay(100);               
}
