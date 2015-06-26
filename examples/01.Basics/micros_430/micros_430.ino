//
//  micros_430.ino
//  Sketch 
//  ----------------------------------
//  Developed with embedXcode
//
//  Project micros
//  Created by Rei VILO on 30/05/12
//  Copyright © 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//
//
//  Based on Serial_430
//  © Rei VILO 2012
//  PUSH2 on pin 5
//  Press push 2 to end and clear the serial port
//

// Core library
#if defined(__MSP430G2452__) 
#include "Energia.h"	
#else
#error MSP540G2452 required
#endif

#include "TimerSerial.h"
TimerSerial mySerial;

void setup() {
    mySerial.begin();
    mySerial.print("\n\n\n*** Serial test starts \n"); 
    mySerial.print("PUSH2 to end\n"); 
    pinMode(PUSH2, INPUT_PULLUP);     
}


void loop() {
    
    mySerial.print(1.0*millis(), 0);
    mySerial.print("\t ");
    mySerial.println(1.0*micros(), 0);
    delay(500);
    
    if (digitalRead(PUSH2)==LOW) {
        mySerial.print("\n\n*** Serial test ends. \n"); 
        mySerial.end();
        while(true); // endless loop
    }
}





