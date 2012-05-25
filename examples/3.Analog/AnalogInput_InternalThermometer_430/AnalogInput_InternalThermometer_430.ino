//
// AnalogInput_InternalThermometer_430
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
//   Rei VILO, Mar 12, 2012 - One decimal place
//   Rei VILO, Mar 13, 2012 - More precise algorithm
//   Rei VILO, Mar 14, 2012 - Average
//   Rei VILO, May 21, 2012 - Updated with GREEN_LED, RED_LED and PUSH2
//   Press push 2 to end
//   Tested on msp430g2452 and msp430g2553
//   2196 bytes

#include <TimerSerial.h>

// RED_LED, GREEN_LED, TEMPSENSOR, PUSH2 already defined
#define NUMBER 4 // take number / 2

TimerSerial mySerial;
int ledState = HIGH;
uint8_t i = 0;
uint32_t average = 0;
uint32_t values[NUMBER];
uint8_t j = 0;
boolean flag = false;


void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  analogReference(INTERNAL1V5);
  mySerial.begin();
  pinMode(PUSH2, INPUT_PULLUP);   

  digitalWrite(RED_LED, HIGH); 
  digitalWrite(GREEN_LED, LOW); 


  mySerial.print("\n\n\n*** MSP430 Thermometer \n"); 
  mySerial.print("Press PUSH2 to end\n"); 
  mySerial.print("instant\taverage\n");

  for (j=0; j<NUMBER; j++) values[j]=0;
  average = 0;
  j=0;
}

void printDec(uint32_t ui) {
  mySerial.print(ui/10, DEC);
  mySerial.print(".");
  mySerial.print(ui%10, DEC);
}


void loop() {
  ledState = !ledState;

  // LEDs: green = ready; red = acquisition
  digitalWrite(flag ? GREEN_LED : RED_LED, ledState); 

  if (i == 10) {
    i = 0;

    average -= values[j];
    values[j] = ((uint32_t)analogRead(TEMPSENSOR)*27069 - 18169625) *10 >> 16;
    average += values[j];

    // Print measure 
    printDec(values[j]);
    mySerial.print("\t");

    // Print average 
    if (flag) printDec(average/NUMBER);
    mySerial.print("\n");

    j++; 
    if (j==NUMBER) flag=true;
    j %= NUMBER;
  }

  if (digitalRead(PUSH2)==LOW) {
    mySerial.print("\n\n*** End \n"); 
    mySerial.end();
    while(true); // endless loop
  }
  delay(100);

  i++;
}







