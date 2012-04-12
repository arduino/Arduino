//
// Analog Input - MSP430 Internal Thermometer
// 
// Demonstrates analog input by reading the internal temperature sensor. 
// 
// Created by Robert Wessels
// modified 7 March 2012
// By Robert Wessels
// 
// This example code is in the public domain.
// 
// Revision: 
//   Rei VILO, Mar 12, 2012
//   One decimal place
//   Press push 2 to end
//   Tested on msp430g2452
//   1936 bytes

#include <TimerSerial.h>

#define LED1 2 // LED is on pin 2 of the launchpad
#define LED2 14
#define TEMPSENSOR 10 // sensor is on channel 10
#define PUSH2 5

TimerSerial mySerial;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  analogReference(INTERNAL1V5);
  mySerial.begin();
  pinMode(PUSH2, INPUT);   

  mySerial.print("\n\n\n*** MSP430 Thermometer \n"); 
  mySerial.print("Press PUSH2 to end\n"); 
}

int ledState = LOW;
uint32_t val = 0;
uint8_t i = 0;


void loop() {
  ledState = !ledState;

  digitalWrite(LED1, ledState); // flashing a LED is always a good idea!
  digitalWrite(LED2, !ledState);// more is better!

  if(i == 10) {
    i = 0;

    val = analogRead(TEMPSENSOR);

    // Integer
    val -= 673;  
    val *= 10;   // one decimal place
    val /= 3;

    // Print temp 
    mySerial.print(val/10, DEC);
    mySerial.print(".");
    mySerial.print(val%10, DEC);
    mySerial.print("\n");
  }

  if (digitalRead(PUSH2)==LOW) {
    mySerial.print("\n\n*** End \n"); 
    mySerial.end();
    while(true); // endless loop
  }
  delay(100);

  i++;
}



