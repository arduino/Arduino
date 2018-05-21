/*
 Stepper Motor Control - one revolution

 This program drives a unipolar or bipolar stepper motor.
 The motor is attached to digital pins 8 - 11 of the Arduino.

 The motor should revolve one revolution in one direction, then
 one revolution in the other direction.


 Created 11 Mar. 2007
 Modified 30 Nov. 2009
 by Tom Igoe

 Example adapted for the combination of Motor 28BYJ-48 and driver ULN2003
 see http://www.amazon.de/gp/product/B00ATA5MFE?keywords=ULN2003%2028BYJ48
 Modified 05 Dec. 2015
 by Stanislav Kniazev

 */

#include <Stepper.h>
// Motor 28BYJ-48 has 4096 steps per one revolution
const int stepsPerRevolution = 4096;  // change this to fit the number of steps per revolution for your motor

/* Custom phase matrix for driver ULN2003.
 * The sequence of control signals for 8 phases, 4 control wires is as follows:
 * Step C0 C1 C2 C3
 *    1  0  0  0  1
 *    2  0  0  1  1
 *    3  0  0  1  0
 *    4  0  1  1  0
 *    5  0  1  0  0
 *    6  1  1  0  0
 *    7  1  0  0  0
 *    8  1  0  0  1
 */
const unsigned char phasesMatrix[8] PROGMEM = {
  0b0001,
  0b0011,
  0b0010,
  0b0110,
  0b0100,
  0b1100,
  0b1000,
  0b1001
  };

//initialize the stepper library on pins 8 through 11, phasesMatrix, pin_count, phase_count:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11, (unsigned char*)phasesMatrix, 8);

void setup() {
  // 17 is the maximum for counterclockwise revolution of motor 28BYJ-48
  // set the speed at 17 rpm:
  myStepper.setSpeed(17);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

