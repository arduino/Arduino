/*
 Sample program that uses 1 tasks triggered by the OneMsTaskTimer
 loop is empty as all is done in the ISR 
 running 1 tasks with LED.

 The circuit:
 * LED common tied to VCC.
 * LED connected to I/Os
  
 This example code is in the public domain.
 
*/

#include "OneMsTaskTimer.h"

const int heartbeatPin = RED_LED;
int status = 0;

OneMsTaskTimer_t myTask ={5,  flash, 0, 0};

void setup()  { 
  // open the hardware serial port
  pinMode(heartbeatPin, OUTPUT);
  OneMsTaskTimer::add(&myTask); // 1ms period
  OneMsTaskTimer::start();

} 

void loop()  { 
}

// interrupt handler passed to OneMsTaskTimer
void flash(){
  if (status){
    digitalWrite(heartbeatPin,HIGH);
  }else{
    digitalWrite(heartbeatPin,LOW);
  }
  status ^= 0x0001;
}