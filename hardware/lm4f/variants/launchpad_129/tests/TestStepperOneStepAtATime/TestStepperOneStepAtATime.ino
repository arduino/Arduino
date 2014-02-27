
/* 
 Stepper Motor Control - one step at a time
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 
 The motor will step one step at a time, very slowly.  You can use this to
 test that you've got the four wires of your stepper wired to the correct
 pins. If wired correctly, all steps should be in the same direction.
 
 Use this also to count the number of steps per revolution of your motor,
 if you don't know it.  Then plug that number into the oneRevolution
 example to see if you got it right.
 
 Created 30 Nov. 2009
 by Tom Igoe

 Modified 26 Feb 2014
 by Craig Hollabaugh
 
 */

#include <Stepper.h>

const int stepsPerRevolution = 200;  
// change this to fit the your motor number of steps per revolution

Stepper myStepper(stepsPerRevolution, D1_LED,D2_LED,D3_LED,D4_LED);            
//Stepper myStepper(stepsPerRevolution, D1_LED,D2_LED);            

int stepCount = 0;         // number of steps the motor has taken

void setup() {
  Serial.begin(9600);
  Serial.println("TestStepperOneStepAtATime setup");

/*
  pinMode(D1_LED,OUTPUT);
  pinMode(D2_LED,OUTPUT);
  pinMode(D3_LED,OUTPUT);
  pinMode(D4_LED,OUTPUT);
*/
}

void loop() {
  // step one step:
  myStepper.step(1);
  Serial.print("steps:" );
  Serial.println(stepCount);
  stepCount++;
  delay(500);
}

