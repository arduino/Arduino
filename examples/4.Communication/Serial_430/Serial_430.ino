//
//  Serial_430
//
//  © Rei VILO 2012
// 
//  PUSH2 on pin 5
//
//  Key in text and press Enter for loopback
//  Press push 2 to end
//  Buffer size = 16, of which Enter
//
// Revision
//   Rei VILO, May 21, 2012 - Updated with GREEN_LED, RED_LED and PUSH2
//   Rei VILO, Sep 09, 2012 - TimerSerial.h no longer required
//


void setup() {
  Serial.begin(9600);
  Serial.print("\n\n\n*** Serial test starts \n"); 
  Serial.print("PUSH2 to end\n"); 
  pinMode(PUSH2, INPUT_PULLUP);     
}


void loop() {

  if (Serial.available())   {
    Serial.print(char(Serial.read()));
  } 
  else {  
    Serial.print(".");
    delay(500);
  }
  
  if (digitalRead(PUSH2)==LOW) {
    Serial.print("\n\n*** Serial test ends. \n"); 
    Serial.end();
    while(true); // endless loop
  }
}






