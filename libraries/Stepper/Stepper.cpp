#include <inttypes.h>
#include <stddef.h>

#include <Arduino.h>
#include "utility/Vector.h"

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

// Pin values that turn off current to a motor so that it does not hold its position.
// This is only possible for 4-pin configurations
const uint8_t Stepper::OFF_VALUES[] = { LOW, LOW, LOW, LOW };

Stepper::Stepper(const Stepper& copy)
{
  init(copy.steps_per_rev, copy.motor_pins, copy.num_pins);
}

Stepper& Stepper::operator=(const Stepper& copy) {
  free(this->motor_pins);
  init(copy.steps_per_rev, copy.motor_pins, copy.num_pins);
}

/*
 * two-wire constructor.
 * Sets which wires should control the motor.
 */
Stepper::Stepper(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2)
{
  uint8_t motor_pins[] = {motor_pin_1, motor_pin_2};
  init(steps_per_rev, motor_pins, 2);
}

/*
 *   constructor for four-pin version
 *   Sets which wires should control the motor.
 */
Stepper::Stepper(int steps_per_rev,
    uint8_t motor_pin_1, uint8_t motor_pin_2, uint8_t motor_pin_3, uint8_t motor_pin_4)
{
  uint8_t motor_pins[] = {motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4};
  init(steps_per_rev, motor_pins, 4);
}

Stepper::~Stepper()
{
  free(this->motor_pins);
}

void Stepper::init(int steps_per_rev, uint8_t motor_pins[], uint8_t num_pins)
{
  this->forward = true;
  this->drive_type = FullStep;
  this->last_step_time = 0UL;

  this->motor_pins = (uint8_t*)malloc(num_pins * sizeof(uint8_t));
  for (uint8_t i = 0; i < num_pins; i++) {
    this->motor_pins[i] = motor_pins[i];
  }

  this->num_pins = num_pins;
  this->step_delay = 0UL;
  this->step_number = 0;
  this->steps_per_rev = steps_per_rev;
  this->steps_to_move = 0;
  this->should_hold = true;

  // Setup the pins on the microcontroller.
  for (uint8_t i = 0; i < num_pins; i++) {
    pinMode(motor_pins[i], OUTPUT);
  }

  // Write LOW to each pin initially so the motor is not driven and current is not wasted.
  // This only really makes sense for a 4-pin motor, but it's still better than letting the pins of
  // a 2-pin motor have random values.
  writeMotorPins(motor_pins, Stepper::OFF_VALUES, num_pins);
}

/*
  Sets the speed in revs per minute
*/
void Stepper::setSpeed(unsigned int speed)
{
  this->step_delay = 60UL * 1000000UL / this->steps_per_rev / speed;
  this->step_delay = this->step_delay;
}

/*
  Sets the drive type
 */
void Stepper::setDriveType(DriveType drive_type)
{
  this->drive_type = drive_type;
}

void Stepper::setHold(bool hold)
{
  this->should_hold = hold;

  // Only makes sense to do for 4-pin motors, but we still pass num_pins to writeMotorPins since a
  // SEGFAULT would be really bad.
  if (this->num_pins == 4) {
    if (this->should_hold) {
      // This will rewrite the latest pin values
      stepMotor();
    } else {
      writeMotorPins(this->motor_pins, Stepper::OFF_VALUES, this->num_pins);
    }
  }
}

void Stepper::setDirection(bool forward)
{
  this->forward = forward;
}

void Stepper::setStepsToMove(unsigned int steps_to_move)
{
  this->steps_to_move = steps_to_move;
}

unsigned int Stepper::getStepsLeftToMove()
{
  return this->steps_to_move;
}

/*
  Moves the motor steps_to_move steps.  If the number is negative,
   the motor moves in the reverse direction.
 */
void Stepper::step(int steps_to_move) {
  setStepsToMove(abs(steps_to_move));
  // determine direction based on whether steps_to_mode is + or -:
  setDirection(steps_to_move > 0);

  while(this->steps_to_move > 0) {
    stepSlice();
  }

  // TODO(smike): Since this happens right after the last step, it will effectively cancel it out.
  // Add a delay so the motor has time to complete its last step.
  setHold(this->should_hold);
}

void Stepper::stepSlice() {
  stepSlice(micros());
}

void Stepper::stepSlice(const unsigned long now)
{
  if (this->steps_to_move == 0) {
    // we have nothing to do
    return;
  }

  int steps_per_rev;
  unsigned long step_delay;

  steps_per_rev = this->steps_per_rev;
  step_delay = this->step_delay;
  if (this->drive_type == HalfStep) {
    // There are twice as many steps, adjust appropriately.
    steps_per_rev *= 2;
    step_delay /= 2UL;
  }

  unsigned long elapsed_time = now - this->last_step_time;

  // micros has rolled over. Assume that it has only rolled over once.
  if (now < this->last_step_time) {
    // 0xFFFF is 2^32-1, the maximum value of an unsigned long
    elapsed_time += 0xFFFFUL;
  }

  // move only if the appropriate delay has passed:
  if (elapsed_time >= step_delay) {
    // get the timeStamp of when you stepped:
    this->last_step_time = now;

    stepNow();

    // decrement the steps left:
    this->steps_to_move--;
  }
}

void Stepper::stepNow()
{
  // increment or decrement the step number,
  // depending on direction:
  if (this->forward) {
    this->step_number++;
  } else {
    this->step_number--;
  }
  this->step_number %= steps_per_rev;
  // step the motor:
  stepMotor();
}

/*
 * Moves the motor forward or backwards.
 */
void Stepper::stepMotor()
{
  // Only write out the values if the configuration is valid.
  if (this->num_pins != 4 &&
      !(this->num_pins == 2 && this->drive_type == FullStep)) {
    return;
  }

  const uint8_t* step_row;
  switch(this->drive_type) {
    case FullStep:
      step_row = Stepper::STEP_VALUES[(this->step_number % 4) * 2];
      if (this->num_pins == 2) {
        // For 2-wire configurations we take the middle two values, so we move the pointer up by
        // one so that the first two values are really elements 1 and 2, instead of 0 and 1.
        step_row++;
      }
      break;
    case HalfStep:
      step_row = Stepper::STEP_VALUES[this->step_number % 8];
      break;
    case Wave:
      step_row = Stepper::STEP_VALUES[(this->step_number % 4) * 2 + 1];
      break;
    default:
      // If the this is an unknown drive type do nothing.
      return;
  }

  writeMotorPins(this->motor_pins, step_row, this->num_pins);
}

void Stepper::writeMotorPins(uint8_t motor_pins[], const uint8_t values[], uint8_t num_pins)
{
  for (uint8_t i = 0; i < num_pins; i++) {
    digitalWrite(motor_pins[i], values[i]);
  }
}

/*
  version() returns the version of the library:
*/
uint8_t Stepper::version(void)
{
  return 5;
}
