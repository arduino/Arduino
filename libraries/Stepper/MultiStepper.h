/*
  Multi.h - - Stepper library for Wiring/Arduino - Version 0.4

  Original library     (0.1) by Tom Igoe.
  Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley

  Drives unipolar or bipolar stepper motors using 2 wires or 4 wires

  You can drive multiple motors simultaneously by calling registerStepper() multiple times
  You can move all of them in unison using the void step(int[]) or void step(int) functions.
*/

// ensure this library description is only included once
#ifndef MultiStepper_h
#define MultiStepper_h

#include <inttypes.h>
#include "utility/Vector.h"
#include "Stepper.h"

// library interface description
class MultiStepper {
  public:
    // constructors:
    // Empty constructor
    MultiStepper();

    // destructor
    ~MultiStepper();

    // Registers an extra stepper. The return value is the motor's id, and should be used to
    // reference it in the future.
    uint8_t registerStepper(Stepper* stepper);

    Stepper* getStepper(uint8_t motor_id);

    // speed setter methods:
    // Set the speed for all motors. in RPM
    void setSpeed(int speed);

    // drive type setter methods:
    // Set the drive type for all motors.
    void setDriveType(Stepper::DriveType drive_type);

    void setDirectionPositive(bool direction_positive);

    // sets a limit on how many steps should be moved
    void setStepsToMove(unsigned int steps_to_move);

    // mover methods:
    // Move all motors the number_of_steps
    // Note that steps_to_move is an integer, with a max value of 2^15-1
    void step(int steps_to_move);
    // Move all of the motors simultaneously. Each element in the number_of_steps array corresponds
    // to the number of steps the motor with motor_id being the index of that element should be
    // moved. steps_to_move must have exactly numMotors() elements. If you dont want some motors
    // to move, set those values to 0.
    void step(int steps_to_move[]);

    bool stepSlice();

    // Sets whether the steppers should hold their position after they finish stepping.
    // This can only be done for 4-pin motor configurations, and will be ignored otherwise.
    // This will only take effect after the next step() call finishes. Call step(0) if you want to
    // have it take immediately.
    void setHold(bool hold);

    // Returns the number of motors registered.
    uint8_t numMotors(void);

  private:
    Vector<Stepper*> steppers;
};

#endif
