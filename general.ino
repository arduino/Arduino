void general()
{
pirState     = digitalRead(pirPin);
pir1State    = digitalRead(pir1Pin);
generalState = digitalRead(generalPin);
resetState   = digitalRead(resetPin);

if(digitalRead(generalPin) == HIGH){
   virtuino.vDigitalMemoryWrite(1, HIGH);
   digitalWrite(ledRosso, HIGH);
if(digitalRead(pirPin) == HIGH || digitalRead(pir1Pin) == HIGH){
   digitalWrite(sirena, HIGH);
   virtuino.vDigitalMemoryWrite(10, HIGH);}
if(digitalRead(resetPin) == HIGH){
   digitalWrite(sirena, LOW);
   digitalWrite(pirPin, LOW);
   virtuino.vDigitalMemoryWrite(10, LOW);}}

else{
  digitalWrite(sirena, LOW);
  digitalWrite(pirPin, LOW);
  digitalWrite(ledRosso, LOW);
  virtuino.vDigitalMemoryWrite(1, LOW);
  virtuino.vDigitalMemoryWrite(10, LOW);}}
