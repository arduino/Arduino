/*
  Copyright (c) 2016 Arduino. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

/*
 * NRF52 doesn't use timer, but pwm. This file include definitions to keep
 * compatibility with the Servo library standards.
 */

#ifndef __SERVO_TIMERS_H__
#define __SERVO_TIMERS_H__

/**
 * NRF52 Only definitions
 * ---------------------
 */

#define MIN_PULSE 55
#define MAX_PULSE 284

// define one timer in order to have MAX_SERVOS = 12
typedef enum { _timer1, _Nbr_16timers } timer16_Sequence_t;

#endif   // __SERVO_TIMERS_H__