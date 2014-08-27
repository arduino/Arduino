/*
 ************************************************************************
 *	pins_energia.h
 *
 *	Energia core files for CC3200
 *		Copyright (c) 2014 Robert Wessels. All right reserved.
 *
 ***********************************************************************
  Derived from:
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
 */

#ifndef Pins_Energia_h
#define Pins_Energia_h

#define TARGET_IS_CC3101 1

#ifndef BV
#define BV(x) (1 << (x)) 
#endif 
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/pin.h"

static const uint8_t RED_LED = 29;
static const uint8_t GREEN_LED = 10;
static const uint8_t YELLOW_LED = 9;
static const uint8_t PUSH1 = 3;
static const uint8_t PUSH2 = 11;

#ifdef ARDUINO_MAIN
const uint32_t port_to_base[] = {
	NOT_A_PORT,
	(uint32_t) GPIOA0_BASE,
	(uint32_t) GPIOA1_BASE,
	(uint32_t) GPIOA2_BASE,
	(uint32_t) GPIOA3_BASE,
};

const uint16_t digital_pin_to_pin_num[] = {
	NOT_A_PIN,	/*  dummy */
	NOT_A_PIN,	/*  1  - 3.3V */
	PIN_58,		/*  2  - GPIO_03 */
	PIN_04,		/*  3  - GPIO_13 */
	PIN_03,		/*  4  - GPIO_12 */
	PIN_61,		/*  5  - GPIO_06 */
	PIN_59,		/*  6  - GPIO_04 */
	PIN_05,		/*  7  - GPIO_14 */
	PIN_62,		/*  8  - GPIO_07 */
	PIN_01,		/*  9  - GPIO_10 */
	PIN_02,		/*  10 - GPIO_11 */
	PIN_15,		/*  11 - GPIO_22 */
	PIN_55,		/*  12 - GPIO_01 */
	PIN_21,		/*  13 - GPIO_25 */
	PIN_06,		/*  14 - GPIO_15 */
	PIN_07,		/*  15 - GPIO_16 */
	NOT_A_PIN,	/*  16 - RESET */
	PIN_45,		/*  17 - GPIO_31 */
	PIN_08,		/*  18 - GPIO_17 */
	PIN_18,		/*  19 - GPIO_28 */
	NOT_A_PIN,	/*  20 - GND */
	NOT_A_PIN,	/*  21 - 5V */
	NOT_A_PIN,	/*  22 - GND */
	PIN_57,		/*  23 - GPIO_02 */
	PIN_60,		/*  24 - GPIO_05 */
	PIN_58,		/*  25 - GPIO_03 */
	PIN_59,		/*  26 - GPIO_04 */
	PIN_63,		/*  27 - GPIO_08 */
	PIN_53,		/*  28 - GPIO_30 */
	PIN_64,		/*  29 - GPIO_09 */
	PIN_50,		/*  30 - GPIO_00 */
	PIN_17,		/*  31 - GPIO_24 */
	PIN_16,		/*  32 - GPIO_23 */
	PIN_60,		/*  33 - GPIO_05 */
	PIN_62,		/*  34 - GPIO_07 */
	PIN_18,		/*  35 - GPIO_28 */
	PIN_21,		/*  36 - GPIO_25 */
	PIN_64,		/*  37 - GPIO_09 */
	PIN_17,		/*  38 - GPIO_24 */
	PIN_01,		/*  39 - GPIO_10 */
	PIN_02		/*  40 - GPIO_11 */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN,	/*  dummy */
	NOT_A_PIN,	/*  1  - 3.3V */
	S0,		/*  2  - GPIO_03 */
	S1,		/*  3  - GPIO_13 */
	S1,		/*  4  - GPIO_12 */
	S0,		/*  5  - GPIO_06 */
	S0,		/*  6  - GPIO_04 */
	S1,		/*  7  - GPIO_14 */
	S0,		/*  8  - GPIO_07 */
	S1,		/*  9  - GPIO_10 */
	S1,		/*  10 - GPIO_11 */
	S2,		/*  11 - GPIO_22 */
	S0,		/*  12 - GPIO_01 */
	S3,		/*  13 - GPIO_25 */
	S1,		/*  14 - GPIO_15 */
	S2,		/*  15 - GPIO_16 */
	NOT_A_PIN,	/*  16 - RESET */
	S3,		/*  17 - GPIO_31 */
	S2,		/*  18 - GPIO_17 */
	S3,		/*  19 - GPIO_28 */
	NOT_A_PIN,	/*  20 - GND */
	NOT_A_PIN,	/*  21 - 5V */
	NOT_A_PIN,	/*  22 - GND */
	S0,		/*  23 - GPIO_02 */
	S0,		/*  24 - GPIO_05 */
	S0,		/*  25 - GPIO_03 */
	S0,		/*  26 - GPIO_04 */
	S1,		/*  27 - GPIO_08 */
	S3,		/*  28 - GPIO_30 */
	S1,		/*  29 - GPIO_09 */
	S0,		/*  30 - GPIO_00 */
	S3,		/*  31 - GPIO_24 */
	S2,		/*  32 - GPIO_23 */
	S0,		/*  33 - GPIO_05 */
	S0,		/*  34 - GPIO_07 */
	S3,		/*  35 - GPIO_28 */
	S3,		/*  36 - GPIO_25 */
	S1,		/*  37 - GPIO_09 */
	S3,		/*  38 - GPIO_24 */
	S1,		/*  39 - GPIO_10 */
	S1		/*  40 - GPIO_11 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN,	/*  dummy */
	NOT_A_PIN,	/*  1  - 3.3V */
	BV(3),		/*  2  - GPIO_03 */
	BV(5),		/*  3  - GPIO_13 */
	BV(4),		/*  4  - GPIO_12 */
	BV(6),		/*  5  - GPIO_06 */
	BV(4),		/*  6  - GPIO_04 */
	BV(6),		/*  7  - GPIO_14 */
	BV(7),		/*  8  - GPIO_07 */
	BV(2),		/*  9  - GPIO_10 */
	BV(3),		/*  10 - GPIO_11 */
	BV(6),		/*  11 - GPIO_22 */
	BV(1),		/*  12 - GPIO_01 */
	BV(1),		/*  13 - GPIO_25 */
	BV(7),		/*  14 - GPIO_15 */
	BV(0),		/*  15 - GPIO_16 */
	NOT_A_PIN,	/*  16 - RESET */
	BV(7),		/*  17 - GPIO_31 */
	BV(1),		/*  18 - GPIO_17 */
	BV(4),		/*  19 - GPIO_28 */
	NOT_A_PIN,	/*  20 - GND */
	NOT_A_PIN,	/*  21 - 5V */
	NOT_A_PIN,	/*  22 - GND */
	BV(2),		/*  23 - GPIO_02 */
	BV(5),		/*  24 - GPIO_05 */
	BV(3),		/*  25 - GPIO_03 */
	BV(4),		/*  26 - GPIO_04 */
	BV(8),		/*  27 - GPIO_08 */
	BV(6),		/*  28 - GPIO_30 */
	BV(1),		/*  29 - GPIO_09 */
	BV(0),		/*  30 - GPIO_00 */
	BV(0),		/*  31 - GPIO_24 */
	BV(7),		/*  32 - GPIO_23 */
	BV(5),		/*  33 - GPIO_05 */
	BV(7),		/*  34 - GPIO_07 */
	BV(4),		/*  35 - GPIO_28 */
	BV(1),		/*  36 - GPIO_25 */
	BV(9),		/*  37 - GPIO_09 */
	BV(0),		/*  38 - GPIO_24 */
	BV(2),		/*  39 - GPIO_10 */
	BV(3)		/*  40 - GPIO_11 */
};

const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER,	/*  dummy */
	NOT_ON_TIMER,	/*  1  - 3.3V */
	NOT_ON_TIMER,	/*  2  - GPIO_03 */
	NOT_ON_TIMER,	/*  3  - GPIO_13 */
	NOT_ON_TIMER,	/*  4  - GPIO_12 */
	NOT_ON_TIMER,	/*  5  - GPIO_06 */
	NOT_ON_TIMER,	/*  6  - GPIO_04 */
	NOT_ON_TIMER,	/*  7  - GPIO_14 */
	NOT_ON_TIMER,	/*  8  - GPIO_07 */
	TIMERA3A,	/*  9  - GPIO_10 */
	TIMERA3B,	/*  10 - GPIO_11 */
	NOT_ON_TIMER,	/*  11 - GPIO_22 */
	NOT_ON_TIMER,	/*  12 - GPIO_01 */
	TIMERA1A,	/*  13 - GPIO_25 */
	NOT_ON_TIMER,	/*  14 - GPIO_15 */
	NOT_ON_TIMER,	/*  15 - GPIO_16 */
	NOT_ON_TIMER,	/*  16 - RESET */
	NOT_ON_TIMER,	/*  17 - GPIO_31 */
	NOT_ON_TIMER,	/*  18 - GPIO_17 */
	NOT_ON_TIMER,	/*  19 - GPIO_28 */
	NOT_ON_TIMER,	/*  20 - GND */
	NOT_ON_TIMER,	/*  21 - 5V */
	NOT_ON_TIMER,	/*  22 - GND */
	NOT_ON_TIMER,	/*  23 - GPIO_02 */
	NOT_ON_TIMER,	/*  24 - GPIO_05 */
	NOT_ON_TIMER,	/*  25 - GPIO_03 */
	NOT_ON_TIMER,	/*  26 - GPIO_04 */
	NOT_ON_TIMER,	/*  27 - GPIO_08 */
	NOT_ON_TIMER,	/*  28 - GPIO_30 */
	TIMERA2B,	/*  29 - GPIO_09 */
	NOT_ON_TIMER,	/*  30 - GPIO_00 */
	TIMERA0A,	/*  31 - GPIO_24 */
	NOT_ON_TIMER,	/*  32 - GPIO_23 */
	NOT_ON_TIMER,	/*  33 - GPIO_05 */
	NOT_ON_TIMER,	/*  34 - GPIO_07 */
	NOT_ON_TIMER,	/*  35 - GPIO_28 */
	TIMERA1A,	/*  36 - GPIO_25 */
	TIMERA2B,	/*  37 - GPIO_09 */
	TIMERA0A,	/*  38 - GPIO_24 */
	TIMERA3A,	/*  39 - GPIO_10 */
	TIMERA3B	/*  40 - GPIO_11 */
};

#endif
#endif
