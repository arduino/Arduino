/*
  Servo.h - Interrupt driven Servo library for MSP430
  Copyright (c) 2012 Petr Baudis.  All right reserved.
  Modified by Peter Brier 26-6-2012: Fixed timing/IRQ problem

  Derived from:
  Servo.h - Interrupt driven Servo library for Arduino using 16 bit timers- Version 2
  Copyright (c) 2009 Michael Margolis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef Servo_H
#define Servo_H

#include <inttypes.h>

/*
  This version attempts to be compatible with the Arduino Servo library,
  but supports only a single timer. So do not add too many servos. :-)
 */

/*
  Note that the Servo uses TIMER0_A, which cannot be used for other
  purposes, e.g. for TimerSerial.

  XXX: Also, some pins reused by TIMER0_A may be affected by this
  library, but I do not understand the datasheet enough regarding this.
  Most likely, you should avoid PWM on pin 2? (And other stuff too?)
 */

#define Servo_VERSION           2      // software version of this library

#define MIN_PULSE_WIDTH       544     // the shortest pulse sent to a servo [uS]
#define MAX_PULSE_WIDTH      2400     // the longest pulse sent to a servo [uS]
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define REFRESH_INTERVAL    20000     // servos refresh period in microseconds

#define MAX_SERVOS              8

#define INVALID_SERVO         255     // flag indicating an invalid servo index

typedef struct  {
  uint8_t nbr        :6 ;             // a pin number from 0 to 63
  uint8_t isActive   :1 ;             // true if this channel is enabled, pin not pulsed if false 
} ServoPin_t;

typedef struct {
  ServoPin_t Pin;
  unsigned int ticks;
} servo_t;

class Servo
{
public:
  Servo();
  uint8_t attach(int pin);           // attach the given pin to the next free channel, sets pinMode, returns channel number or 0 if failure
  uint8_t attach(int pin, int min, int max); // as above but also sets min and max values for writes. 
  void detach();
  void write(int value);             // if value is < 200 its treated as an angle, otherwise as pulse width in microseconds 
  void writeMicroseconds(int value); // Write pulse width in microseconds 
  int read();                        // returns current pulse width as an angle between 0 and 180 degrees
  int readMicroseconds();            // returns current pulse width in microseconds for this servo (was read_us() in first release)
  bool attached();                   // return true if this servo is attached, otherwise false 
private:
   uint8_t servoIndex;               // index into the channel data for this servo
   int8_t min;                       // minimum is this value times 4 added to MIN_PULSE_WIDTH    
   int8_t max;                       // maximum is this value times 4 added to MAX_PULSE_WIDTH   
};

#endif
