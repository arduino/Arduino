void zona1(){
  pir1State    = digitalRead(pir1Pin);
  zona1State = digitalRead(zona1Pin);
  resetState   = digitalRead(resetPin);
  
if(digitalRead(zona1Pin) == HIGH){
   virtuino.vDigitalMemoryWrite(2, HIGH);
   digitalWrite(ledRosso, HIGH);
if(digitalRead(pir1Pin) == HIGH){
   digitalWrite(sirena, HIGH);
   virtuino.vDigitalMemoryWrite(11, HIGH);}
if(digitalRead(resetPin) == HIGH){
   digitalWrite(sirena, LOW);
   digitalWrite(pir1Pin, LOW);
   virtuino.vDigitalMemoryWrite(11, LOW);}}
else{
  virtuino.vDigitalMemoryWrite(2, LOW);
  virtuino.vDigitalMemoryWrite(11, LOW);}}


