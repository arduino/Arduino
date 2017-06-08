void rfid(){
 
  byte i;
  if (RC522.isCard()){
    
    RC522.readCardSerial();
    String codiceLetto ="";
    Serial.println("Codice delle tessera letto:");
    
  for(i = 0; i <= 4; i++){
      
      codiceLetto+= String (RC522.serNum[i],HEX);
      codiceLetto.toUpperCase();}
    
    
      Serial.println(codiceLetto);
    
    if(verificaCodice(codiceLetto,codiceAutorizzato1)){
      
      Serial.println("Tessera autorizzata");
      accendiLed(ledVerde);
      reading = digitalRead(ledVerde);
  
    if(reading == LOW && millis() - time > debounce) {
    if(state == HIGH)
      state = HIGH;
      digitalWrite(generalPin,HIGH);
      virtuino.vDigitalMemoryWrite(1, HIGH);}
    else
      state = LOW;   
      //virtuino.vDigitalMemoryWrite(1, LOW);
  
    if(state == HIGH){
      state = LOW;
      digitalWrite(generalPin,LOW);
      virtuino.vDigitalMemoryWrite(1, LOW);}
    else
      state = HIGH; 
      //virtuino.vDigitalMemoryWrite(1, HIGH);
    time = millis();    

    digitalWrite(ledRosso, state);

    previous = reading;} 
 
   else{
      
      Serial.println("Tessera non autorizzata");
      accendiLed(ledGiallo);}
     
      delay(delayRead);}}


boolean verificaCodice(String codiceLetto, String codiceAutorizzato){
  
   if(codiceLetto.equals(codiceAutorizzato)){
   return true;}
   else{
   return false;}}    

void accendiLed(int ledPin){
  digitalWrite(ledPin,HIGH);
  delay(delayLed);
  digitalWrite(ledPin,LOW);}



