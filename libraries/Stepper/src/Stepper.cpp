/*
 * Stepper.cpp - Stepper library for Wiring/Arduino - Version 1.1.1
 *
 * Original library                     (0.1)   by Tom Igoe.
 * Two-wire modifications               (0.2)   by Sebastian Gassner
 * Combination version                  (0.3)   by Tom Igoe and David Mellis
 * Bug fix for four-wire                (0.4)   by Tom Igoe, bug fix from Noah Shibley
 * High-speed stepping mod                      by Eugene Kozlenko
 * Timer rollover fix                           by Eugene Kozlen
 * Five phase five wire                 (1.1.0) by Ryan Orendorff
 * Generic driver support (see example
 * stepper_oneRevolution_ULN2003),
 * constructors harmonization by
 * introducing the initMotor method,
 * optimization of method stepMotor by
 * introducing the phasesMatrix array   (1.1.1) by Stanislav Kniazev
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
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1)
{
  initMotor(number_of_steps, motor_pin_0, motor_pin_1,
                             0, 0, 0, 2, (unsigned char*)phasesMatrix2, 4);
}

/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor.
 */
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                                      int motor_pin_2, int motor_pin_3)
{
  initMotor(number_of_steps, motor_pin_0, motor_pin_1,
                             motor_pin_2, motor_pin_3,
                             0, 4, (unsigned char*)phasesMatrix4, 4);
}

/*
 *   constructor for five phase motor with five wires
 *   Sets which wires should control the motor.
 */
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                                      int motor_pin_2, int motor_pin_3,
                                      int motor_pin_4)
{
  initMotor(number_of_steps, motor_pin_0, motor_pin_1,
                             motor_pin_2, motor_pin_3,
                             motor_pin_4, 5, (unsigned char*)phasesMatrix5, 10);
}

/*
 *   universal constructor for motors with only one wire
 *   Sets which wires should control the motor, pointer to the phases matrix, number of pins and phases.
 */
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0,
                 unsigned char *phasesMatrix, int phase_count)
{
  initMotor(number_of_steps, motor_pin_0, 0,
                             0,           0,
                             0,           1,
                             phasesMatrix,phase_count);
}

/*
 *   universal constructor for motors with two wires
 *   Sets which wires should control the motor, pointer to the phases matrix, number of pins and phases.
 */
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                 unsigned char *phasesMatrix, int phase_count)
{
  initMotor(number_of_steps, motor_pin_0, motor_pin_1,
                             0,           0,
                             0,           2,
                             phasesMatrix,phase_count);
}

/*
 *   universal constructor for motors with three wires
 *   Sets which wires should control the motor, pointer to the phases matrix, number of pins and phases.
 */
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                 int motor_pin_2, unsigned char *phasesMatrix, int phase_count)
{
  initMotor(number_of_steps, motor_pin_0, motor_pin_1,
                             motor_pin_2, 0,
                             0,           3,
                             phasesMatrix,phase_count);
}

/*
 *   universal constructor for motors with four wires
 *   Sets which wires should control the motor, pointer to the phases matrix, number of pins and phases.
 */
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                 int motor_pin_2, int motor_pin_3,
                 unsigned char *phasesMatrix, int phase_count)
{
  initMotor(number_of_steps, motor_pin_0, motor_pin_1,
                             motor_pin_2, motor_pin_3,
                             0,           4,
                             phasesMatrix,phase_count);
}

/*
 *   universal constructor for motors with five wires
 *   Sets which wires should control the motor, pointer to the phases matrix, number of pins and phases.
 */
Stepper::Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                 int motor_pin_2, int motor_pin_3, int motor_pin_4,
                 unsigned char *phasesMatrix, int phase_count)
{
  initMotor(number_of_steps, motor_pin_0, motor_pin_1,
                             motor_pin_2, motor_pin_3,
                             motor_pin_4, 5,
                             phasesMatrix,phase_count);
}

/*
 * Sets the speed in revs per minute
 */
void Stepper::setSpeed(long whatSpeed)
{
  this->step_delay = 60L * 1000L * 1000L / this->number_of_steps / whatSpeed;
}

/*
 * Moves the motor steps_to_move steps.  If the number is negative,
 * the motor moves in the reverse direction.
 */
void Stepper::step(int steps_to_move)
{
  int steps_left = abs(steps_to_move);  // how many steps to take

  // decrement the number of steps, moving one step each time:
  while (steps_left > 0)
  {
    unsigned long now = micros();
    // move only if the appropriate delay has passed:
    if (now - this->last_step_time >= this->step_delay)
    {
      // get the timeStamp of when you stepped:
      this->last_step_time = now;
      // increment or decrement the step number,
      // depending on direction:
      if (steps_to_move >= 0)
      {
        this->step_number++;
        if (this->step_number >= this->number_of_steps) {
          this->step_number = 0;
        }
      }
      else
      {
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
      // step the motor to step number 0, 1, ..., {3 or 9}
      stepMotor(this->step_number % phase_count);
      // decrement the steps left:
      steps_left--;
    }
  }
}

/*
 * Moves the motor forward or backwards.
 */
void Stepper::stepMotor(unsigned char thisPhase)
{
  unsigned char phase = pgm_read_byte_near(phasesMatrix + thisPhase);
  unsigned char running_one = 1;
  for (char i = pin_count - 1; i >= 0; i--, running_one <<= 1){
    digitalWrite(motor_pin[i], (phase & running_one));
  }
}

/*
 *   Initialize the motor
 */
void Stepper::initMotor(unsigned number_of_steps,  unsigned char motor_pin_0,  unsigned char motor_pin_1,
                                              unsigned char motor_pin_2,  unsigned char motor_pin_3,
                                              unsigned char motor_pin_4,  unsigned char pin_count,
                                              unsigned char *phasesMatrix,unsigned char phase_count)
{
  this->step_number = 0;    // which step the motor is on
  this->number_of_steps = number_of_steps; // total number of steps for this motor

  // pin_count is used by the stepMotor() method:
  this->pin_count     = pin_count;
  // phase_count is used by the step() method:
  this->phase_count   = phase_count;
  // phasesMatrix is used by the stepMotor() method:
  this->phasesMatrix  = phasesMatrix;
  this->motor_pin[0] = motor_pin_0;
  this->motor_pin[1] = motor_pin_1;
  this->motor_pin[2] = motor_pin_2;
  this->motor_pin[3] = motor_pin_3;
  this->motor_pin[4] = motor_pin_4;
  for (unsigned char i = 0; i < this->pin_count; i++){
    pinMode(this->motor_pin[i], OUTPUT);  // setup the pins on the microcontroller
  }
}

/*
  version() returns the version of the library:
*/
int Stepper::version(void)
{
  return 5;
}
