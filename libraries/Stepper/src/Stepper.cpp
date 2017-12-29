/*
 * Stepper.cpp - Stepper library for Wiring/Arduino - Version 1.1.0
 *
 * Original library        (0.1)   by Tom Igoe.
 * Two-wire modifications  (0.2)   by Sebastian Gassner
 * Combination version     (0.3)   by Tom Igoe and David Mellis
 * Bug fix for four-wire   (0.4)   by Tom Igoe, bug fix from Noah Shibley
 * High-speed stepping mod         by Eugene Kozlenko
 * Timer rollover fix              by Eugene Kozlenko
 * Five phase five wire    (1.1.0) by Ryan Orendorff
 * Improve C++             (1.2)   by Steve Weinrich
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *
 * Drives a unipolar, bipolar, or five phase stepper motor.
 *
 * When wiring multiple stepper motors to a microcontroller, you quickly run
 * out of output pins, with each motor requiring 4 connections.
 *
 * By making use of the fact that at any time two of the four motor coils are
 * the inverse of the other two, the number of control connections can be
 * reduced from 4 to 2 for the unipolar and bipolar motors.
 *
 * A slightly modified circuit around a Darlington transistor array or an
 * L293 H-bridge connects to only 2 microcontroler pins, inverts the signals
 * received, and delivers the 4 (2 plus 2 inverted ones) output signals
 * required for driving a stepper motor. Similarly the Arduino motor shields
 * 2 direction pins may be used.
 *
 * The sequence of control signals for 5 phase, 5 control wires is as follows:
 *
 * Step C0 C1 C2 C3 C4
 *    1  0  1  1  0  1
 *    2  0  1  0  0  1
 *    3  0  1  0  1  1
 *    4  0  1  0  1  0
 *    5  1  1  0  1  0
 *    6  1  0  0  1  0
 *    7  1  0  1  1  0
 *    8  1  0  1  0  0
 *    9  1  0  1  0  1
 *   10  0  0  1  0  1
 *
 * The sequence of control signals for 4 control wires is as follows:
 *
 * Step C0 C1 C2 C3
 *    1  1  0  1  0
 *    2  0  1  1  0
 *    3  0  1  0  1
 *    4  1  0  0  1
 *
 * The sequence of controls signals for 2 control wires is as follows
 * (columns C1 and C2 from above):
 *
 * Step C0 C1
 *    1  0  1
 *    2  1  1
 *    3  1  0
 *    4  0  0
 *
 * The circuits can be found at
 *
 * http://www.arduino.cc/en/Reference/Stepper
 */

#include "Arduino.h"
#include "Stepper.h"

/*
 * two-wire constructor.
 * Sets which wires should control the motor.
 */
Stepper::Stepper (int numberOfSteps, int motorPin1, int motorPin2)
: mStepMotor(&Stepper::stepMotorTwoWire),
  mMotorPins{ motorPin1, motorPin2, 0, 0, 0 },
  mNumberOfPositions(4),
  mNumberOfSteps(numberOfSteps)
{
  commonInitialization();
}

/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor.
 */
Stepper::Stepper (int numberOfSteps, int motorPin1, int motorPin2,
                  int motorPin3, int motorPin4)
: mStepMotor(&Stepper::stepMotorFourWire),
  mMotorPins{ motorPin1, motorPin2, motorPin3, motorPin4, 0 },
  mNumberOfPositions(4),
  mNumberOfSteps(numberOfSteps)
{
  commonInitialization();
}

/*
 *   constructor for five phase motor with five wires
 *   Sets which wires should control the motor.
 */
Stepper::Stepper (int numberOfSteps, int motorPin1, int motorPin2,
                                     int motorPin3, int motorPin4,
                                     int motorPin5)
: mStepMotor(&Stepper::stepMotorFiveWire),
  mMotorPins{ motorPin1, motorPin2, motorPin3, motorPin4, motorPin5 },
  mNumberOfPositions(10),
  mNumberOfSteps(numberOfSteps)
{
  commonInitialization();
}

  void Stepper::commonInitialization ()
  {
    mStepNumber   = 0;    // which step the motor is on
    mLastStepTime = 0;    // time stamp in us of the last step taken

    // default speed
    setSpeed(1);

    // setup the pins on the microcontroller:
    for (int i = 0; i < (sizeof(mMotorPins) / sizeof(mMotorPins[0])); ++i)
        if (mMotorPins[i] != 0)
            pinMode(mMotorPins[i], OUTPUT);
  }

/*
 * Sets the speed in revolutions per minute
 */
void Stepper::setSpeed (unsigned long revolutionsPerMinute)
{
  mStepDelay = 60L * 1000L * 1000L / mNumberOfSteps / revolutionsPerMinute;
}

/*
 * Moves the motor numberOfSteps steps.  If the number is negative,
 * the motor moves in the reverse direction.
 */
void Stepper::step (int numberOfSteps)
{
  int stepsLeft = abs(numberOfSteps);  // how many steps to take

  // determine direction based on whether steps_to_mode is + or -:
  const bool stepForwards = (numberOfSteps >= 0);

  // decrement the number of steps, moving one step each time:
  while (stepsLeft > 0)
  {
    const unsigned long now = micros();
    // move only if the appropriate delay has passed:
    if ((now - mLastStepTime) >= mStepDelay)
    {
      // get the timeStamp of when you stepped:
      mLastStepTime = now;

      // increment or decrement the step number,
      // depending on direction:
      if (stepForwards)
      {
        ++mStepNumber;
        if (mStepNumber == mNumberOfSteps)
            mStepNumber = 0;
      }
      else
      {
        if (mStepNumber == 0)
            mStepNumber = mNumberOfSteps;
        --mStepNumber;
      }
      // decrement the number of steps left:
      --stepsLeft;

      // step the motor to step number 0, 1, ..., by calling the preestablished
      // "stepMotorxxx" function.
      (this->*mStepMotor)(mStepNumber % mNumberOfPositions);
    }
  }
}

/*
 * Moves the motor forward or backwards.
 */
void Stepper::stepMotorTwoWire (int thisStep) const
{
  switch (thisStep) {
    case 0:  // 01
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], HIGH);
      break;
    case 1:  // 11
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], HIGH);
      break;
    case 2:  // 10
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], LOW);
      break;
    case 3:  // 00
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], LOW);
    break;
    }
}

void Stepper::stepMotorFourWire (int thisStep) const
{
  switch (thisStep) {
    case 0:  // 1010
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], LOW);
      digitalWrite(mMotorPins[2], HIGH);
      digitalWrite(mMotorPins[3], LOW);
      break;
    case 1:  // 0110
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], HIGH);
      digitalWrite(mMotorPins[2], HIGH);
      digitalWrite(mMotorPins[3], LOW);
      break;
    case 2:  //0101
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], HIGH);
      digitalWrite(mMotorPins[2], LOW);
      digitalWrite(mMotorPins[3], HIGH);
      break;
    case 3:  //1001
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], LOW);
      digitalWrite(mMotorPins[2], LOW);
      digitalWrite(mMotorPins[3], HIGH);
      break;
    }
}

void Stepper::stepMotorFiveWire (int thisStep) const
{
  switch (thisStep) {
    case 0:  // 01101
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], HIGH);
      digitalWrite(mMotorPins[2], HIGH);
      digitalWrite(mMotorPins[3], LOW);
      digitalWrite(mMotorPins[4], HIGH);
      break;
    case 1:  // 01001
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], HIGH);
      digitalWrite(mMotorPins[2], LOW);
      digitalWrite(mMotorPins[3], LOW);
      digitalWrite(mMotorPins[4], HIGH);
      break;
    case 2:  // 01011
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], HIGH);
      digitalWrite(mMotorPins[2], LOW);
      digitalWrite(mMotorPins[3], HIGH);
      digitalWrite(mMotorPins[4], HIGH);
      break;
    case 3:  // 01010
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], HIGH);
      digitalWrite(mMotorPins[2], LOW);
      digitalWrite(mMotorPins[3], HIGH);
      digitalWrite(mMotorPins[4], LOW);
      break;
    case 4:  // 11010
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], HIGH);
      digitalWrite(mMotorPins[2], LOW);
      digitalWrite(mMotorPins[3], HIGH);
      digitalWrite(mMotorPins[4], LOW);
      break;
    case 5:  // 10010
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], LOW);
      digitalWrite(mMotorPins[2], LOW);
      digitalWrite(mMotorPins[3], HIGH);
      digitalWrite(mMotorPins[4], LOW);
      break;
    case 6:  // 10110
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], LOW);
      digitalWrite(mMotorPins[2], HIGH);
      digitalWrite(mMotorPins[3], HIGH);
      digitalWrite(mMotorPins[4], LOW);
      break;
    case 7:  // 10100
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], LOW);
      digitalWrite(mMotorPins[2], HIGH);
      digitalWrite(mMotorPins[3], LOW);
      digitalWrite(mMotorPins[4], LOW);
      break;
    case 8:  // 10101
      digitalWrite(mMotorPins[0], HIGH);
      digitalWrite(mMotorPins[1], LOW);
      digitalWrite(mMotorPins[2], HIGH);
      digitalWrite(mMotorPins[3], LOW);
      digitalWrite(mMotorPins[4], HIGH);
      break;
    case 9:  // 00101
      digitalWrite(mMotorPins[0], LOW);
      digitalWrite(mMotorPins[1], LOW);
      digitalWrite(mMotorPins[2], HIGH);
      digitalWrite(mMotorPins[3], LOW);
      digitalWrite(mMotorPins[4], HIGH);
      break;
    }
}
