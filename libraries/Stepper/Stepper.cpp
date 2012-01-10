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

#include <inttypes.h>
#include <stddef.h>

#include <Arduino.h>
#include "utility/vector.h"

#include "Stepper.h"

// Only even rows are used for full-stepping.
// Only odd rows are used for wave-stepping.
// All rows are used for half-stepping.
const uint8_t Stepper::STEP_VALUES[8][4] = {
  {HIGH, LOW, HIGH,  LOW}, // not used for wave-stepping
  {LOW,  LOW, HIGH,  LOW}, // not used for full-stepping
  {LOW, HIGH, HIGH,  LOW}, // not used for wave-stepping
  {LOW, HIGH,  LOW,  LOW}, // not used for full-stepping
  {LOW, HIGH,  LOW, HIGH}, // not used for wave-stepping
  {LOW,  LOW,  LOW, HIGH}, // not used for full-stepping
  {HIGH, LOW,  LOW, HIGH}, // not used for wave-stepping
  {HIGH, LOW,  LOW,  LOW}  // not used for full-stepping
};

Stepper::Stepper() : should_halt(false), callback(NULL) {}

/*
 * two-wire constructor.
 * Sets which wires should control the motor.
 */
Stepper::Stepper(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2)
    : should_halt(false), callback(NULL)
{
  registerMotor(steps_per_rev, motor_pin_1, motor_pin_2);
}

/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor.
 */
Stepper::Stepper(int steps_per_rev,
    uint8_t motor_pin_1, uint8_t motor_pin_2, uint8_t motor_pin_3, uint8_t motor_pin_4)
    : should_halt(false), callback(NULL)
{
  registerMotor(steps_per_rev, motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4);
}

Stepper::~Stepper()
{
  uint8_t num_motors = numMotors();
  for(uint8_t i = 0; i < num_motors; i++) {
    free(motor_infos[i]->motor_pins);
    delete motor_infos[i];
  }
}

uint8_t Stepper::registerMotor(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2)
{
  uint8_t motor_pins[] = { motor_pin_1, motor_pin_2 };
  return registerMotor(steps_per_rev, motor_pins, 2);
}

uint8_t Stepper::registerMotor(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2, uint8_t motor_pin_3, uint8_t motor_pin_4)
{
  uint8_t motor_pins[] = { motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4 };
  return registerMotor(steps_per_rev, motor_pins, 4);
}

uint8_t Stepper::registerMotor(int steps_per_rev, uint8_t motor_pins[], uint8_t num_pins)
{
  MotorInfo* motor_info = new MotorInfo;
  motor_info->drive_type = FullStep;
  motor_info->last_step_time = 0UL;

  motor_info->motor_pins = (uint8_t*)malloc(num_pins * sizeof(uint8_t));
  for (uint8_t i = 0; i < num_pins; i++) {
    motor_info->motor_pins[i] = motor_pins[i];
  }

  motor_info->num_pins = num_pins;
  motor_info->step_delay = 0UL;
  motor_info->step_number = 0;
  motor_info->steps_per_rev = steps_per_rev;

  setupMotorPins(motor_pins, num_pins);

  this->motor_infos.push_back(motor_info);
  return motor_infos.size() - 1;
}

void Stepper::setupMotorPins(uint8_t motor_pins[], uint8_t num_pins) {
  // Setup the pins on the microcontroller.
  // Write LOW to each pin initially so the motor is not driven and current is not wasted.
  for (uint8_t i = 0; i < num_pins; i++) {
    pinMode(motor_pins[i], OUTPUT);
    digitalWrite(motor_pins[i], LOW);
  }
}

/*
  Sets the speed in revs per minute
*/
void Stepper::setSpeed(long speed)
{
  uint8_t num_motors = numMotors();
  for (uint8_t i = 0; i < num_motors; i++) {
    setSpeed(i, speed);
  }
}

void Stepper::setSpeed(uint8_t motor_id, long speed)
{
  MotorInfo* motor_info = this->motor_infos[motor_id];
  motor_info->step_delay = 60UL * 1000000UL / motor_info->steps_per_rev / speed;
}

/*
  Sets the drive type
 */
void Stepper::setDriveType(DriveType drive_type)
{
  uint8_t num_motors = numMotors();
  for (uint8_t i = 0; i < num_motors; i++) {
    setDriveType(i, drive_type);
  }
}

void Stepper::setDriveType(uint8_t motor_id, DriveType drive_type)
{
  this->motor_infos[motor_id]->drive_type = drive_type;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative,
   the motor moves in the reverse direction.
 */
void Stepper::step(int steps_to_move) {
  uint8_t num_motors = numMotors();
  int steps_to_move_array[num_motors];
  for (uint8_t i = 0; i < num_motors; i++) {
    steps_to_move_array[i] = steps_to_move;
  }
  step(steps_to_move_array);
}

void Stepper::step(uint8_t motor_id, int steps_to_move) {
  uint8_t num_motors = numMotors();
  int steps_to_move_array[num_motors];
  for (uint8_t i = 0; i < num_motors; i++) {
    steps_to_move_array[i] = i == motor_id ? steps_to_move : 0;
  }
  step(steps_to_move_array);
}

void Stepper::step(int steps_to_move[])
{
  uint8_t num_motors = numMotors();

  int steps_left[num_motors];
  bool direction_positive[num_motors];
  int steps_per_rev[num_motors];
  unsigned long step_delay[num_motors];
  for (uint8_t i = 0; i < num_motors; i++) {
    const MotorInfo* motor_info = this->motor_infos[i];
    steps_left[i] = abs(steps_to_move[i]);  // how many steps to take

    // determine direction based on whether steps_to_mode is + or -:
    direction_positive[i] = steps_to_move[i] > 0;

    steps_per_rev[i] = motor_info->steps_per_rev;
    step_delay[i] = motor_info->step_delay;
    if (motor_info->drive_type == HalfStep) {
      // There are twice as many steps, adjust appropriately.
      steps_per_rev[i] *= 2;
      step_delay[i] /= 2UL;
    }
  }

  while(!this->should_halt) {
    const unsigned long now = micros();
    bool any_steps_left = false;
    // look at each motor to see if it should be moved now.
    for (uint8_t i = 0; i < num_motors; i++) {
      MotorInfo* motor_info = this->motor_infos[i];
      if (steps_left[i] > 0) {
        any_steps_left = true;

        unsigned long elapsed_time = now - motor_info->last_step_time;
        // micros has rolled over. Assume that it has only rolled over once.
        if (now < motor_info->last_step_time) {
          // 0xFFFF is 2^32-1, the maximum value of an unsigned long
          elapsed_time += 0xFFFFUL;
        }

        // move only if the appropriate delay has passed:
        if (elapsed_time >= step_delay[i]) {
          // get the timeStamp of when you stepped:
          motor_info->last_step_time = now;
          // increment or decrement the step number,
          // depending on direction:
          if (direction_positive[i]) {
            motor_info->step_number++;
          } else {
            motor_info->step_number--;
          }
          motor_info->step_number %= steps_per_rev[i];
          // decrement the steps left:
          steps_left[i]--;
          // step the motor:
          stepMotor(i);
        }
      }
    }

    // if there are no steps left for any motors, we're done!
    if (!any_steps_left) {
      break;
    }

    // if it is set, call the callback.
    if (this->callback != NULL) {
      this->callback();
    }
  }

  // reset halt signal
  this->should_halt = false;
}

/*
 * Moves the motor forward or backwards.
 */
void Stepper::stepMotor(uint8_t motor_id)
{
  const MotorInfo* motor_info = this->motor_infos[motor_id];
  uint8_t* motor_pins = motor_info->motor_pins;

  // Only write out the values if the configuration is valid.
  if (motor_info->num_pins != 4 &&
      motor_info->num_pins != 2 && motor_info->drive_type != FullStep) {
    return;
  }

  const uint8_t* step_row;
  switch(motor_info->drive_type) {
    case FullStep:
      step_row = Stepper::STEP_VALUES[(motor_info->step_number % 4) * 2];
      if (motor_info->num_pins == 2) {
        // For 2-wire configurations we take the middle two values, so we move the pointer up by
        // one so that the first two values are really elements 1 and 2, instead of 0 and 1.
        step_row++;
      }
      break;
    case HalfStep:
      step_row = Stepper::STEP_VALUES[motor_info->step_number % 8];
      break;
    case Wave:
      step_row = Stepper::STEP_VALUES[(motor_info->step_number % 4) * 2 + 1];
      break;
    default:
      // If the this is an unknown drive type do nothing.
      return;
  }

  writeMotorPins(motor_pins, step_row, motor_info->num_pins);
}

void Stepper::writeMotorPins(uint8_t motor_pins[], const uint8_t values[], uint8_t num_pins)
{
  for (uint8_t i = 0; i < num_pins; i++) {
    digitalWrite(motor_pins[i], values[i]);
  }
}

void Stepper::halt()
{
  this->should_halt = true;
}

void Stepper::setCallback(void (*callback)())
{
  this->callback = callback;
}

uint8_t Stepper::numMotors()
{
  return this->motor_infos.size();
}

/*
  version() returns the version of the library:
*/
uint8_t Stepper::version(void)
{
  return 5;
}
