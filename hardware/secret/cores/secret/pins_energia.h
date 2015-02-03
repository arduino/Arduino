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

const uint8_t digital_pin_to_hwAttrs_index[] = {
	NOT_A_PIN,	/*  dummy */
	NOT_A_PIN,	/*  1  - 3.3V */
	3,		/*  2  - GPIO_03 */
	13,		/*  3  - GPIO_13 */
	12,		/*  4  - GPIO_12 */
	6,		/*  5  - GPIO_06 */
	4,		/*  6  - GPIO_04 */
	14,		/*  7  - GPIO_14 */
	7,		/*  8  - GPIO_07 */
	10,		/*  9  - GPIO_10 */
	11,		/*  10 - GPIO_11 */
	22,		/*  11 - GPIO_22 */
	1,		/*  12 - GPIO_01 */
	25,		/*  13 - GPIO_25 */
	15,		/*  14 - GPIO_15 */
	16,		/*  15 - GPIO_16 */
	NOT_A_PIN,	/*  16 - RESET */
	31,		/*  17 - GPIO_31 */
	17,		/*  18 - GPIO_17 */
	28,		/*  19 - GPIO_28 */
	NOT_A_PIN,	/*  20 - GND */
	NOT_A_PIN,	/*  21 - 5V */
	NOT_A_PIN,	/*  22 - GND */
	2,		/*  23 - GPIO_02 */
	5,		/*  24 - GPIO_05 */
	3,		/*  25 - GPIO_03 */
	4,		/*  26 - GPIO_04 */
	8,		/*  27 - GPIO_08 */
	30,		/*  28 - GPIO_30 */
	9,		/*  29 - GPIO_09 */
	0,		/*  30 - GPIO_00 */
	24,		/*  31 - GPIO_24 */
	23,		/*  32 - GPIO_23 */
	5,		/*  33 - GPIO_05 */
	7,		/*  34 - GPIO_07 */
	28,		/*  35 - GPIO_28 */
	25,		/*  36 - GPIO_25 */
	9,		/*  37 - GPIO_09 */
	24,		/*  38 - GPIO_24 */
	10,		/*  39 - GPIO_10 */
	11		/*  40 - GPIO_11 */
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
	TIMERA3A, 		/*  9  -  port 0 */
	TIMERA3B, 		/*  10 -  port 1 */
	NOT_ON_TIMER,	/*  11 - GPIO_22 */
	NOT_ON_TIMER,	/*  12 - GPIO_01 */
	TIMERA1A, 		/*  13 -  port 0 */
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
	TIMERA2B,		/*  29 -  port 1 */
	NOT_ON_TIMER,	/*  30 - GPIO_00 */
	TIMERA0A, 		/*  31 -  port 0 */
	NOT_ON_TIMER,	/*  32 - GPIO_23 */
	NOT_ON_TIMER,	/*  33 - GPIO_05 */
	NOT_ON_TIMER,	/*  34 - GPIO_07 */
	NOT_ON_TIMER,	/*  35 - GPIO_28 */
	TIMERA1A, 		/*  36 -  port 0 */
	TIMERA2B, 		/*  37 -  port 1 */
	TIMERA0A, 		/*  38 -  port 0 */
	TIMERA3A, 		/*  39 -  port 0 */
	TIMERA3B, 		/*  40 -  port 1 */
};

const uint32_t digital_pin_to_analog_in[] = {
        NOT_ON_ADC,     /*  dummy   */
        NOT_ON_ADC,		/*  1	*/
        ADC_CH_1,		/*  2 - P58	*/
        NOT_ON_ADC,     /*  3	*/
        NOT_ON_ADC, 	/*  4	*/
        NOT_ON_ADC, 	/*  5	*/
        ADC_CH_2,		/*  6 - P59	*/
        NOT_ON_ADC,		/*  7 	*/
        NOT_ON_ADC, 	/*  8 	*/
        NOT_ON_ADC, 	/*  9 	*/
        NOT_ON_ADC, 	/*  10 	*/
        NOT_ON_ADC, 	/*  11 	*/
        NOT_ON_ADC, 	/*  12 	*/
        NOT_ON_ADC, 	/*  13 	*/
        NOT_ON_ADC, 	/*  14 	*/
        NOT_ON_ADC,		/*  15	*/
        NOT_ON_ADC,     /*  16 	*/
        NOT_ON_ADC,     /*  17 	*/
        NOT_ON_ADC, 	/*  18 	*/
        NOT_ON_ADC,     /*  19 	*/
        NOT_ON_ADC, 	/*  20 	*/
        NOT_ON_ADC, 	/*  21 	*/
		NOT_ON_ADC, 	/*  22 	*/
		ADC_CH_0,		/*  23 - P57	*/
		ADC_CH_3,		/*  24 - P60	*/
		NOT_ON_ADC,		/*  25 	*/
		NOT_ON_ADC,		/*  26 	*/
		NOT_ON_ADC, 	/*  27 	*/
		NOT_ON_ADC, 	/*  28 	*/
		NOT_ON_ADC, 	/*  29 	*/
        NOT_ON_ADC,     /*  30 	*/
        NOT_ON_ADC, 	/*  31 	*/
        NOT_ON_ADC,     /*  32 	*/
        NOT_ON_ADC,     /*  33 	*/
        NOT_ON_ADC,     /*  34 	*/
        NOT_ON_ADC,     /*  35 	*/
        NOT_ON_ADC,     /*  36 	*/
        NOT_ON_ADC,     /*  37 	*/
        NOT_ON_ADC,  	/*  38 	*/
        NOT_ON_ADC,		/*  39 	*/
        NOT_ON_ADC,     /*  40 	*/
};

uint8_t digital_pin_to_pin_function[] = {
		PIN_FUNC_UNUSED,	/*  dummy */
		PIN_FUNC_UNUSED,	/*  1  - 3.3V */
		PIN_FUNC_UNUSED,	/*  2  - GPIO_03 */
		PIN_FUNC_UNUSED,	/*  3  - GPIO_13 */
		PIN_FUNC_UNUSED,	/*  4  - GPIO_12 */
		PIN_FUNC_UNUSED,	/*  5  - GPIO_06 */
		PIN_FUNC_UNUSED,	/*  6  - GPIO_04 */
		PIN_FUNC_UNUSED,	/*  7  - GPIO_14 */
		PIN_FUNC_UNUSED,	/*  8  - GPIO_07 */
		PIN_FUNC_UNUSED,	/*  9  - GPIO_10 */
		PIN_FUNC_UNUSED,	/*  10 - GPIO_11 */
		PIN_FUNC_UNUSED,	/*  11 - GPIO_22 */
		PIN_FUNC_UNUSED,	/*  12 - GPIO_01 */
		PIN_FUNC_UNUSED,	/*  13 - GPIO_25 */
		PIN_FUNC_UNUSED,	/*  14 - GPIO_15 */
		PIN_FUNC_UNUSED,	/*  15 - GPIO_16 */
		PIN_FUNC_UNUSED,	/*  16 - RESET */
		PIN_FUNC_UNUSED,	/*  17 - GPIO_31 */
		PIN_FUNC_UNUSED,	/*  18 - GPIO_17 */
		PIN_FUNC_UNUSED,	/*  19 - GPIO_28 */
		PIN_FUNC_UNUSED,	/*  20 - GND */
		PIN_FUNC_UNUSED,	/*  21 - 5V */
		PIN_FUNC_UNUSED,	/*  22 - GND */
		PIN_FUNC_UNUSED,	/*  23 - GPIO_02 */
		PIN_FUNC_UNUSED,	/*  24 - GPIO_05 */
		PIN_FUNC_UNUSED,	/*  25 - GPIO_03 */
		PIN_FUNC_UNUSED,	/*  26 - GPIO_04 */
		PIN_FUNC_UNUSED,	/*  27 - GPIO_08 */
		PIN_FUNC_UNUSED,	/*  28 - GPIO_30 */
		PIN_FUNC_UNUSED,	/*  29 - GPIO_09 */
		PIN_FUNC_UNUSED,	/*  30 - GPIO_00 */
		PIN_FUNC_UNUSED,	/*  31 - GPIO_24 */
		PIN_FUNC_UNUSED,	/*  32 - GPIO_23 */
		PIN_FUNC_UNUSED,	/*  33 - GPIO_05 */
		PIN_FUNC_UNUSED,	/*  34 - GPIO_07 */
		PIN_FUNC_UNUSED,	/*  35 - GPIO_28 */
		PIN_FUNC_UNUSED,	/*  36 - GPIO_25 */
		PIN_FUNC_UNUSED,	/*  37 - GPIO_09 */
		PIN_FUNC_UNUSED,	/*  38 - GPIO_24 */
		PIN_FUNC_UNUSED,	/*  39 - GPIO_10 */
		PIN_FUNC_UNUSED,	/*  40 - GPIO_11 */
};
#endif
#endif
