/*
 * Stepper.h - Stepper library for Wiring/Arduino - Version 1.1.0
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

// ensure this library description is only included once
#ifndef Stepper_h
#define Stepper_h

// library interface description
class Stepper {
  public:
    // constructors:
    Stepper (int numberOfSteps, int motorPin1, int motorPin2);

    Stepper (int numberOfSteps, int motorPin1, int motorPin2,
                                int motorPin3, int motorPin4);

    Stepper (int numberOfSteps, int motorPin1, int motorPin2,
                                int motorPin3, int motorPin4,
                                int motorPin5);

    // speed setter method:
    void setSpeed (unsigned long revolutionsPerMinute);

    // mover method, numberOfSteps may be positive or negative:
    void step (int numberOfSteps);

    inline int version (void) const { return 6; }

  private:
    void commonInitialization();

    void stepMotorTwoWire  (int step) const;
    void stepMotorFourWire (int step) const;
    void stepMotorFiveWire (int step) const;

    // Thee following two statements declare a "pointer to member function".  The
    // function pointed to must have the signature "void someFunction (int) const".
    // You can see them declared right above.  The value of mStepMotor is set in
    // the constructors.  The whole point of this is to permit the correct function
    // to be called without using an "if" or "switch" statement.  You can see how
    // mStepMotor is used at the bottom of the "step" function.
    typedef void (Stepper::*StepMotorMethodPointer) (int) const; 
    const StepMotorMethodPointer mStepMotor;

    // motor pin numbers:
    const int mMotorPins[5];        // arrays are indexed starting at 0, not 1

    const int mNumberOfPositions;   // total number of discrete control positions
    const int mNumberOfSteps;       // total number of steps this motor can take

    unsigned long mStepDelay;       // delay between steps, in microseconds, based on speed
    int           mStepNumber;      // which step the motor is on
    unsigned long mLastStepTime;    // time stamp in microseconds of when the last step was taken
};

#endif

