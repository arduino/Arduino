/*
  Stepper.h - - Stepper library for Wiring/Arduino - Version 0.4

  Original library     (0.1) by Tom Igoe.
  Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley

  Drives unipolar or bipolar stepper motors using 2 wires or 4 wires

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

// ensure this library description is only included once
#ifndef Stepper_h
#define Stepper_h

#include <inttypes.h>
#include "utility/Vector.h"

// forward declaration so it can be counted as a friend class.
class MultiStepper;

// library interface description
class Stepper {
  public:
    enum DriveType { FullStep, HalfStep, Wave };

    // constructors:
    // The two constructors below will also add a motor as motor_id 0.
    // steps_per_rev should be in full steps
    Stepper() {}
    Stepper(const Stepper& copy);
    Stepper(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2);
    Stepper(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2, uint8_t motor_pin_3, uint8_t motor_pin_4);

    // destructor
    ~Stepper();

    Stepper& operator=(const Stepper& copy);

    // speed setter methods:
    // Set the speed of the motor, in RPM
    void setSpeed(unsigned int speed);

    // drive type setter methods:
    // Set the drive type of the motor.
    void setDriveType(DriveType drive_type);

    // mover methods:
    // Note that steps_to_move is an integer, with a max value of 2^15-1
    void step(int steps_to_move);
    // Does a step without regard for speed or the steps left to move. After this method it will be
    // just like no steps have happened with respect to speed and number of steps left.
    void stepNow();

    // Sets whether the steppers should hold their position after they finish stepping.
    // This can only be done for 4-pin motor configurations, and will be ignored otherwise.
    // This will only take effect after the next step() call finishes. Call step(0) if you want to
    // have it take immediately.
    void setHold(bool hold);

    void setDirection(bool forward);

    // sets a limit on how many steps should be moved
    void setStepsToMove(unsigned int steps_to_move);

    // returns how many steps are left to move.
    // This is scaled based on the drive type (1 FullStep = 2 HalfSteps)
    unsigned int getStepsLeftToMove();

    void stepSlice();

    uint8_t version(void);

    friend class MultiStepper;

  protected:
    // Helper method for stepSlice(). Takes the current time in microseconds.
    // It is useful when needing to move multiple motors simultaneously. Having each motor calculate
    // can make them out of sync, and slow since micros() take a long time to evaluate.
    void stepSlice(const unsigned long now);

  private:
    // initialization
    void init(int steps_per_rev, uint8_t motor_pins[], uint8_t num_pins);

    // moves the motor specified one step.
    void stepMotor();

    // writes the given values to the motor pins.
    void writeMotorPins(uint8_t motor_pins[], const uint8_t values[], uint8_t num_pins);

    // Only even rows are used for full-stepping.
    // Only odd rows are used for wave-stepping.
    // All rows are used for half-stepping.
    static const uint8_t STEP_VALUES[8][4];

    // Pin values that turn off current to a motor so that it does not hold its position.
    // This is only possible for 4-pin configurations
    static const uint8_t OFF_VALUES[4];

    uint8_t* motor_pins; // motor pin numbers
    uint8_t num_pins;

    Stepper::DriveType drive_type; // What kind of stepping to use. Defaults to full.
    unsigned long step_delay; // delay between steps, in micros, based on speed
    int steps_per_rev; // total number of steps this motor can take
    bool forward; // whether to move forward or backward

    unsigned int step_number; // which step the motor is on
    unsigned int steps_to_move; // the number of steps left to take
    unsigned long last_step_time; // time stamp in micros of when the last step was taken

    bool should_hold; // whether to hold the motor position when not stepping.
};

#endif
