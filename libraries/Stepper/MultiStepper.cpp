#include <inttypes.h>
#include <stddef.h>

#include <Arduino.h>
#include "Stepper.h"
#include "utility/vector.h"

#include "MultiStepper.h"

MultiStepper::MultiStepper() {}

MultiStepper::~MultiStepper() {}

uint8_t MultiStepper::registerStepper(Stepper* stepper)
{
  this->steppers.push_back(stepper);
  return this->steppers.size() - 1;
}

Stepper* MultiStepper::getStepper(uint8_t motor_id)
{
  return this->steppers[motor_id];
}

void MultiStepper::setSpeed(int speed)
{
  uint8_t num_motors = numMotors();
  for (uint8_t i = 0; i < num_motors; i++) {
    this->steppers[i]->setSpeed(speed);
  }
}

void MultiStepper::setDriveType(Stepper::DriveType drive_type)
{
  uint8_t num_motors = numMotors();
  for (uint8_t i = 0; i < num_motors; i++) {
    this->steppers[i]->setDriveType(drive_type);
  }
}

void MultiStepper::setHold(bool hold)
{
  uint8_t num_motors = numMotors();
  for (uint8_t i = 0; i < num_motors; i++) {
    this->steppers[i]->setHold(hold);
  }
}

void MultiStepper::setDirectionPositive(bool direction_positive)
{
  uint8_t num_motors = numMotors();
  for (uint8_t i = 0; i < num_motors; i++) {
    this->steppers[i]->setDirectionPositive(direction_positive);
  }
}

void MultiStepper::setStepsToMove(unsigned int steps_to_move)
{
  uint8_t num_motors = numMotors();
  for (uint8_t i = 0; i < num_motors; i++) {
    this->steppers[i]->setStepsToMove(steps_to_move);
  }
}

void MultiStepper::step(int steps_to_move) {
  uint8_t num_motors = numMotors();
  int steps_to_move_array[num_motors];
  for (uint8_t i = 0; i < num_motors; i++) {
    steps_to_move_array[i] = steps_to_move;
  }
  step(steps_to_move_array);
}

void MultiStepper::step(int steps_to_move[])
{
  uint8_t num_motors = numMotors();

  for (uint8_t i = 0; i < num_motors; i++) {
    Stepper* stepper = this->steppers[i];

    stepper->setStepsToMove(abs(steps_to_move[i]));
    // determine direction based on whether steps_to_mode is + or -:
    stepper->setDirectionPositive(steps_to_move[i] > 0);
  }

  while(true) {
    if (!stepSlice()) {
      // no steps left for any motor. We're done!
      break;
    }
  }
}

bool MultiStepper::stepSlice()
{
  uint8_t num_motors = numMotors();

  bool any_steps_left = false;
  const unsigned long now = micros();
  for (uint8_t i = 0; i < num_motors; i++) {
    Stepper* stepper = this->steppers[i];
    // if there are no steps left for any motors, we're done!
    if (stepper->getStepsLeftToMove() > 0) {
      any_steps_left = true;

      stepper->stepSlice(now);
    }
  }

  return any_steps_left;
}

uint8_t MultiStepper::numMotors()
{
  return this->steppers.size();
}
