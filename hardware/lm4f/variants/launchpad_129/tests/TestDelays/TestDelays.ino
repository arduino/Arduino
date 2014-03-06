/* TestDelays
  This test is not the best approach because test and mechanism are
  based on same timer. 
*/

unsigned long start,end;

void setup() {                
  Serial.begin(9600);
  Serial.println("\nTestDelays setup");

  start = millis();
  delay(888);
  end   = millis();
  Serial.print("millis = ");
  Serial.println((end - start),DEC);

  start = micros();
  delayMicroseconds(444);
  end   = micros();
  Serial.print("micros = ");
  Serial.println((end - start),DEC);
  
}

void loop() {
}
