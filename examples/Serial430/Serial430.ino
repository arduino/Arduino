//
//  Serial430
//
//  © Rei VILO 2012
// 
//  PUSH2 on pin 5
//
//  Key in text and press Enter for loopback
//  Press push 2 to end
//  Buffer size = 16, of which Enter
//

#include "TimerSerial.h"

TimerSerial mySerial;
const uint8_t PUSH2 = 5;

void setup() {
  mySerial.begin();
  mySerial.print("\n\n\n*** Serial test starts \n"); 
  pinMode(PUSH2, INPUT);     
}


void loop() {

  if (mySerial.available())   {
    mySerial.print(char(mySerial.read()));
  } 
  else {  
    mySerial.print(".");
    delay(500);
  }
  
  if (digitalRead(PUSH2)==LOW) {
    mySerial.print("\n\n*** Serial test ends. \n"); 
    mySerial.end();
    while(true); // endless loop
  }
}






