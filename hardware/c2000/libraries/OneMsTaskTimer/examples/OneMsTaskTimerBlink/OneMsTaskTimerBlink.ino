/*
 Sample program that uses 3 tasks triggered by the OneMsTaskTimer
 loop is empty as all is done in the ISR 
 running 3 tasks with LED.

 The circuit:
 * LED common tied to VCC.
 * LED connected to I/Os
  
 This example code is in the public domain.
 
*/

#include "OneMsTaskTimer.h"

const int heartbeatPin1 = RED_LED;
const int heartbeatPin2 = GREEN_LED;

OneMsTaskTimer_t myTask1 ={500,  flash1, 0, 0};
OneMsTaskTimer_t myTask2 ={1000, flash2, 0, 0};
OneMsTaskTimer_t myTask3 ={2000, flash3, 0, 0};

void setup()  { 
  // open the hardware serial port
  Serial.begin(115200);
  pinMode(heartbeatPin1, OUTPUT);
  pinMode(heartbeatPin2, OUTPUT);
  OneMsTaskTimer::add(&myTask1); // 500ms period
  OneMsTaskTimer::add(&myTask2); // 1000ms period
  OneMsTaskTimer::add(&myTask3); // 2000ms period
  OneMsTaskTimer::start();

} 

void loop()  { 
}

// interrupt handler passed to OneMsTaskTimer
void flash1(){
  // log every time the handler is called should be every 500msec
  // Practically not a good idea as this function inside an ISR should be as short as possilbe
  Serial.print(":1");
  //heartbeatPinOn1 = !heartbeatPinOn1;
  digitalWrite(heartbeatPin1,HIGH);
}

// interrupt handler passed to OneMsTaskTimer
void flash2(){
  // log every time the handler is called should be every 500msec
  // Practically not a good idea as this function inside an ISR should be as short as possilbe
  Serial.print(":2");
  //heartbeatPinOn2 = !heartbeatPinOn2;
  digitalWrite(heartbeatPin2,HIGH);
}
  
// interrupt handler passed to OneMsTaskTimer
void flash3(){
  // log every time the handler is called should be every 500msec
  // Practically not a good idea as this function inside an ISR should be as short as possilbe
  Serial.println(":3");
  //heartbeatPinOn2 = !heartbeatPinOn2;
  digitalWrite(heartbeatPin1,LOW);
  digitalWrite(heartbeatPin2,LOW);
}


