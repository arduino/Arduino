/*
 * Stepper.h - Stepper library for Wiring/Arduino - Version 1.1.1
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

// ensure this library description is only included once
#ifndef Stepper_h
#define Stepper_h

#include <avr/pgmspace.h>

    //Default phases matrix for 2 control wires is as follows
    const unsigned char phasesMatrix2[4]  PROGMEM = {
      0b01,
      0b11,
      0b10,
      0b00
    };

    //Default phases matrix for 4 control wires is as follows
    const unsigned char phasesMatrix4[4]  PROGMEM = {
      0b1010,
      0b0110,
      0b0101,
      0b1001
    };

    //Default phases matrix for 5 control wires is as follows
    const unsigned char phasesMatrix5[10] PROGMEM = {
      0b01101,
      0b01001,
      0b01011,
      0b01010,
      0b11010,
      0b10010,
      0b10110,
      0b10100,
      0b10101,
      0b00101
    };

// library interface description
class Stepper {
  public:
    // constructors:
    Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1);
    Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                                 int motor_pin_2, int motor_pin_3);
    Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
                                 int motor_pin_2, int motor_pin_3,
                                 int motor_pin_4);
    Stepper(unsigned number_of_steps, int motor_pin_0,
            unsigned char *phasesMatrix, int phase_count);
    Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
            unsigned char *phasesMatrix, int phase_count);
    Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
            int motor_pin_2, unsigned char *phasesMatrix, int phase_count);
    Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
            int motor_pin_2, int motor_pin_3,
            unsigned char *phasesMatrix, int phase_count);
    Stepper(unsigned number_of_steps, int motor_pin_0, int motor_pin_1,
            int motor_pin_2, int motor_pin_3, int motor_pin_4,
            unsigned char *phasesMatrix, int phase_count);

    // speed setter method:
    void setSpeed(long whatSpeed);

    // mover method:
    void step(int number_of_steps);

    int version(void);

  private:
    void stepMotor(unsigned char thisPhase);
    void initMotor(unsigned number_of_steps, unsigned char motor_pin_0,  unsigned char motor_pin_1,
                                        unsigned char motor_pin_2,  unsigned char motor_pin_3,
                                        unsigned char motor_pin_4,  unsigned char pin_count,
                                        unsigned char *phasesMatrix,unsigned char phase_count);

    unsigned long step_delay; // delay between steps, in ms, based on speed
    unsigned number_of_steps;     // total number of steps this motor can take
    unsigned char pin_count;      // how many pins are in use.
    unsigned char phase_count;    // how many phases are in use.
    unsigned char *phasesMatrix;  // pointer to the phases Matrix
    unsigned step_number;         // which step the motor is on

    // motor pin numbers:
    unsigned char motor_pin[5];   // Maximum 5 control signals
    unsigned long last_step_time; // time stamp in us of when the last step was taken
};

#endif

