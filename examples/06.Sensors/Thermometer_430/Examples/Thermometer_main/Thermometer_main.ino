//
//  Thermometer_library.ino 
//  Sketch
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Thermometer_430
//  Created by Rei VILO on Jun 05, 2012
//  Copyright © 2012 http://embeddedcomputing.weebly.com
//  Licence CC = BY SA NC
//
//  Binary sketch size: 2 318 bytes (of a 16 384 byte maximum)
//  Now 2 983 bytes

// for msp430g2553 only

// Core library
#if defined(__MSP430G2553__) 
#else
#error Platform not supported
#endif

#include "Thermometer_430.h"

Thermometer_430 myThermometer;

void setup() {
  pinMode(PUSH2, INPUT_PULLUP);     
  myThermometer.begin();
  Serial.begin(9600);
  Serial.println("Thermometer");
  Serial.println("press PUSH2 to exit serial");    
}

void loop() {
  myThermometer.get();

  Serial.print(myThermometer.temperatureX10()/10, DEC);
  Serial.print(".");
  Serial.println(myThermometer.temperatureX10()%10, DEC);

  if (digitalRead(PUSH2)==LOW) {
    Serial.println("exit"); 
    Serial.end();
    while(true); // endless loop
  }

}

