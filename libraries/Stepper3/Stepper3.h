/*
  Stepper.h - - Stepper library for Wiring/Arduino - Version 0.4

  Original library     (0.1) by Tom Igoe.
  Two-wire modifications   (0.2) by Sebastian Gassner
  Combination version   (0.3) by Tom Igoe and David Mellis
  Bug fix for four-wire   (0.4) by Tom Igoe, bug fix from Noah Shibley

  Drives unipolar or bipolar stepper motors using 2 wires or 4 wires

  You can drive multiple motors simultaneously by calling registerMotor() multiple times on the same
  instance of Stepper. You can then either move one motor at a time, or all of them in unison using
  void step(int[] steps) function.

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
#include "utility/vector.h"

// library interface description
class Stepper {
  public:
    enum DriveType { FullStep, HalfStep, Wave };

    // constructors:
    // Empty constructor
    Stepper();
    // The two constructors below will also add a motor as motor_id 0.
    // steps_per_rev should be in full steps
    Stepper(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2);
    Stepper(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2, uint8_t motor_pin_3, uint8_t motor_pin_4);

    // destructor
    ~Stepper();

    // Registers an extra motor. The return value is the motor's id, and should be used to
    // reference it in the future.
    // steps_per_rev should be in full steps
    uint8_t registerMotor(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2);
    uint8_t registerMotor(int steps_per_rev, uint8_t motor_pin_1, uint8_t motor_pin_2, uint8_t motor_pin_3, uint8_t motor_pin_4);

    // speed setter methods:
    // Set the speed for all motors. in RPM
    void setSpeed(int speed);
    // Set the speed for a specific motor, in RPM
    void setSpeed(uint8_t motor_id, int speed);

    // drive type setter methods:
    // Set the drive type for all motors.
    void setDriveType(DriveType drive_type);
    // Set the drive type for a specific motor
    void setDriveType(uint8_t motor_id, DriveType drive_type);

    // mover methods:
    // Move all motors the number_of_steps
    // Note that steps_to_move is an integer, with a max value of 2^15-1
    void step(int steps_to_move);
    // Move only the motor with motor_id number_of_steps
    void step(uint8_t motor_id, int steps_to_move);
    // Move all of the motors simultaneously. Each element in the number_of_steps array corresponds
    // to the number of steps the motor with motor_id being the index of that element should be
    // moved. steps_to_move must have exactly numMotors() elements. If you dont want some motors
    // to move, set those values to 0.
    void step(int steps_to_move[]);

    // Aborts the step() loop once.
    void halt();

    // Sets whether the steppers should hold their position after they finish stepping.
    // This can only be done for 4-pin motor configurations, and will be ignored otherwise.
    // This will only take effect after the next step() call finishes. Call step(0) if you want to
    // have it take immediately.
    void setHold(bool hold);
    void setHold(uint8_t motor_id, bool hold);

    // Sets a callback to call after each iteration of the step() loop. Set to NULL to disable.
    // Remember that the callback should execute quickly and not block. The longer the callback
    // takes the slower steps can be taken.
    void setCallback(void (*callback)());

    // Returns the number of motors registered.
    uint8_t numMotors(void);

    uint8_t version(void);

  private:
    struct MotorInfo {
      uint8_t* motor_pins; // motor pin numbers
      uint8_t num_pins;

      Stepper::DriveType drive_type; // What kind of stepping to use. Defaults to full.
      unsigned long step_delay; // delay between steps, in micros, based on speed
      int steps_per_rev; // total number of steps this motor can take

      unsigned int step_number; // which step the motor is on
      unsigned long last_step_time; // time stamp in micros of when the last step was taken

      bool should_hold; // whether to hold the motor position when not stepping.
    };

    uint8_t registerMotor(int steps_per_rev, uint8_t motor_pins[], uint8_t num_pins);
    void setupMotorPins(uint8_t motor_pins[], uint8_t num_pins);

    // moves the motor specified one step.
    void stepMotor(uint8_t motor_id);

    // writes the given values to the motor pins.
    void writeMotorPins(uint8_t motor_pins[], const uint8_t values[], uint8_t num_pins);

    // Only even rows are used for full-stepping.
    // Only odd rows are used for wave-stepping.
    // All rows are used for half-stepping.
    static const uint8_t STEP_VALUES[8][4];

    // Pin values that turn off current to a motor so that it does not hold its position.
    // This is only possible for 4-pin configurations
    static const uint8_t OFF_VALUES[4];

    Vector<MotorInfo*> motor_infos;
    bool should_halt;
    void (*callback)();
};

#endif
