/*
  Stepper.cpp - - Stepper library for Wiring/Arduino - Version 0.4
  
  Original library     (0.1) by Tom Igoe.
  Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley  

  Drives a unipolar or bipolar stepper motor using  2 wires or 4 wires

  When wiring multiple stepper motors to a microcontroller,
  you quickly run out of output pins, with each motor requiring 4 connections. 

  By making use of the fact that at any time two of the four motor
  coils are the inverse  of the other two, the number of
  control connections can be reduced from 4 to 2. 

  A slightly modified circuit around a Darlington transistor array or an L293 H-bridge
  connects to only 2 microcontroler pins, inverts the signals received,
  and delivers the 4 (2 plus 2 inverted ones) output signals required
  for driving a stepper motor.

  The sequence of control signals for 4 control wires is as follows:

  Step C0 C1 C2 C3
     1  1  0  1  0
     2  0  1  1  0
     3  0  1  0  1
     4  1  0  0  1

  The sequence of controls signals for 2 control wires is as follows
  (columns C1 and C2 from above):

  Step C0 C1
     1  0  1
     2  1  1
     3  1  0
     4  0  0

  For 4 wire configurations only, the motor can be driven with full-stepping (the default),
  half-stepping, or a wave drive.

  Half-stepping will halve the size of the motor's step, giving it double the resolution.
  Remember that the amount of steps you pass to step() will be interpreted based on the current
  value of the drive type. The sequence of control signals is as follows:

  Step C0 C1 C2 C3
     1  1  0  1  0
     2  0  0  1  0
     3  0  1  1  0
     4  0  1  0  0
     5  0  1  0  1
     6  0  0  0  1
     7  1  0  0  1
     8  1  0  0  0

  Wave drive mode only keeps one phase on a time. This means that the motor will use less power, but
  will also only have half of the torque of full-stepping. The sequence of control signals is as
  follows:

  Step C0 C1 C2 C3
     1  0  0  1  0
     2  0  1  0  0
     3  0  0  0  1
     4  1  0  0  0

  The circuits can be found at http://www.arduino.cc/en/Tutorial/Stepper
  More info on the different types of drives can be found at
  http://www.wikipedia.org/wiki/Stepper_motor#Phase_current_waveforms
*/


#include "Arduino.h"
#include "Stepper.h"

// Only even rows are used for full-stepping.
// Only odd rows are used for wave-stepping.
// All rows are used for half-stepping.
const int Stepper::STEP_VALUES[8][4] = {
  {HIGH, LOW, HIGH,  LOW}, // not used for wave-stepping
  {LOW,  LOW, HIGH,  LOW}, // not used for full-stepping
  {LOW, HIGH, HIGH,  LOW}, // not used for wave-stepping
  {LOW, HIGH,  LOW,  LOW}, // not used for full-stepping
  {LOW, HIGH,  LOW, HIGH}, // not used for wave-stepping
  {LOW,  LOW,  LOW, HIGH}, // not used for full-stepping
  {HIGH, LOW,  LOW, HIGH}, // not used for wave-stepping
  {HIGH, LOW,  LOW,  LOW}  // not used for full-stepping
};

/*
 * two-wire constructor.
 * Sets which wires should control the motor.
 */
Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2)
{
  this->step_number = 0;      // which step the motor is on
  this->speed = 0;        // the motor speed, in revolutions per minute
  this->direction = 0;      // motor direction
  this->last_step_time = 0;    // time stamp in ms of the last step taken
  this->number_of_steps = number_of_steps;    // total number of steps for this motor
  this->drive_type = FullStep;
  
  // Arduino pins for the motor control connection:
  this->motor_pin_1 = motor_pin_1;
  this->motor_pin_2 = motor_pin_2;

  // setup the pins on the microcontroller:
  pinMode(this->motor_pin_1, OUTPUT);
  pinMode(this->motor_pin_2, OUTPUT);
  
  // When there are only 2 pins, set the other two to 0:
  this->motor_pin_3 = 0;
  this->motor_pin_4 = 0;
  
  // pin_count is used by the stepMotor() method:
  this->pin_count = 2;
}


/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor.
 */

Stepper::Stepper(int number_of_steps, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
{
  this->step_number = 0;      // which step the motor is on
  this->speed = 0;        // the motor speed, in revolutions per minute
  this->direction = 0;      // motor direction
  this->last_step_time = 0;    // time stamp in ms of the last step taken
  this->number_of_steps = number_of_steps;    // total number of steps for this motor
  this->drive_type = FullStep;
  
  // Arduino pins for the motor control connection:
  this->motor_pin_1 = motor_pin_1;
  this->motor_pin_2 = motor_pin_2;
  this->motor_pin_3 = motor_pin_3;
  this->motor_pin_4 = motor_pin_4;

  // setup the pins on the microcontroller:
  pinMode(this->motor_pin_1, OUTPUT);
  pinMode(this->motor_pin_2, OUTPUT);
  pinMode(this->motor_pin_3, OUTPUT);
  pinMode(this->motor_pin_4, OUTPUT);

  // pin_count is used by the stepMotor() method:  
  this->pin_count = 4;  
}

/*
  Sets the speed in revs per minute
*/
void Stepper::setSpeed(long whatSpeed)
{
  this->step_delay = 60L * 1000000L / this->number_of_steps / whatSpeed;
}

/*
  Sets the drive type
*/
void Stepper::setDriveType(DriveType drive_type)
{
  this->drive_type = drive_type;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative, 
   the motor moves in the reverse direction.
 */
void Stepper::step(int steps_to_move)
{  
  int steps_left = abs(steps_to_move);  // how many steps to take
  
  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) {this->direction = 1;}
  if (steps_to_move < 0) {this->direction = 0;}
  
  int number_of_steps = this->number_of_steps;
  unsigned long step_delay = this->step_delay;
  if (this->drive_type == HalfStep) {
    // There are twice as many steps, adjust appropriately.
    number_of_steps *= 2;
    step_delay /= 2;
  }

  // decrement the number of steps, moving one step each time:
  while(steps_left > 0) {
    unsigned long now = micros();
    long elapsed_time = now - this->last_step_time;
    // move only if the appropriate delay has passed:
    if (elapsed_time >= step_delay) {
      // get the timeStamp of when you stepped:
      this->last_step_time = now;
      // increment or decrement the step number,
      // depending on direction:
      if (this->direction == 1) {
        this->step_number++;
        if (this->step_number >= number_of_steps) {
          this->step_number = 0;
        }
      } 
      else { 
        if (this->step_number <= 0) {
          this->step_number = number_of_steps;
        }
        this->step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor:
      stepMotor();
    }
  }
}

/*
 * Moves the motor forward or backwards.
 */
void Stepper::stepMotor() {
  switch(this->drive_type) {
    case FullStep:
      fullStepMotor();
      break;
    case HalfStep:
      halfStepMotor();
      break;
    case Wave:
      waveStepMotor();
      break;
  }
}

void Stepper::fullStepMotor()
{
  const int* step_row = STEP_VALUES[(this->step_number % 4) * 2]; // full-stepping only uses even rows
  if (this->pin_count == 2) {
    // For 2-wire configurations we take the middle two pins
    digitalWrite(motor_pin_2, step_row[1]);
    digitalWrite(motor_pin_3, step_row[2]);
  } else if (this->pin_count == 4) {
    digitalWrite(motor_pin_1, step_row[0]);
    digitalWrite(motor_pin_2, step_row[1]);
    digitalWrite(motor_pin_3, step_row[2]);
    digitalWrite(motor_pin_4, step_row[3]);
  }
}

void Stepper::halfStepMotor()
{
  // Only 4-wire configurations can be half-stepped.
  if (this->pin_count == 4) {
    const int* step_row = STEP_VALUES[this->step_number % 8];
    digitalWrite(motor_pin_1, step_row[0]);
    digitalWrite(motor_pin_2, step_row[1]);
    digitalWrite(motor_pin_3, step_row[2]);
    digitalWrite(motor_pin_4, step_row[3]);
  }
}

void Stepper::waveStepMotor()
{
  // Only 4-wire configurations can be wave-driven.
  if (this->pin_count == 4) {
    const int* step_row = STEP_VALUES[(this->step_number % 4) * 2 + 1]; // wave drive only uses odd rows
    digitalWrite(motor_pin_1, step_row[0]);
    digitalWrite(motor_pin_2, step_row[1]);
    digitalWrite(motor_pin_3, step_row[2]);
    digitalWrite(motor_pin_4, step_row[3]);
  }
}

/*
  version() returns the version of the library:
*/
int Stepper::version(void)
{
  return 4;
}
