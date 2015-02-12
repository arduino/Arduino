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

static const uint8_t RED_LED = 43;
static const uint8_t GREEN_LED = 44;
static const uint8_t YELLOW_LED = 44; /* closest to yellow */
static const uint8_t BLUE_LED = 45;
static const uint8_t PUSH1 = 41;
static const uint8_t PUSH2 = 42;

#ifdef ARDUINO_MAIN
#include <msp432.h>
#include <rom.h>
#include <rom_map.h>
#include <dma.h>
#include <gpio.h>
#include <i2c.h>
#include <spi.h>
#include <timer_a.h>
#include <uart.h>
#include <wdt_a.h>

const uint32_t port_to_base[] = {
	NOT_A_PORT,
	(uint32_t) NOT_A_PORT,
	(uint32_t) NOT_A_PORT,
	(uint32_t) NOT_A_PORT,
	(uint32_t) NOT_A_PORT,
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
		NOT_ON_ADC,		/*  2 - P58	*/
        NOT_ON_ADC,     /*  3	*/
        NOT_ON_ADC, 	/*  4	*/
        NOT_ON_ADC, 	/*  5	*/
		NOT_ON_ADC,		/*  6 - P59	*/
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
		NOT_ON_ADC,		/*  23 - P57	*/
		NOT_ON_ADC,		/*  24 - P60	*/
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
		PIN_FUNC_UNUSED,	/*  2  - P6.0_A15 */
		PIN_FUNC_UNUSED,	/*  3  - P3.2_URXD */
		PIN_FUNC_UNUSED,	/*  4  - P3.3_UTXD */
		PIN_FUNC_UNUSED,	/*  5  - P4.1_IO_A12 */
		PIN_FUNC_UNUSED,	/*  6  - P4.3_A10 */
		PIN_FUNC_UNUSED,	/*  7  - P1.5_SPICLK */
		PIN_FUNC_UNUSED,	/*  8  - P4.6_IO_A7 */
		PIN_FUNC_UNUSED,	/*  9  - P6.5_I2CSCL */
		PIN_FUNC_UNUSED,	/*  10 - P6.4_I2CSDA */
		PIN_FUNC_UNUSED,	/*  11 - P3.6_IO */
		PIN_FUNC_UNUSED,	/*  12 - P5.2_IO */
		PIN_FUNC_UNUSED,	/*  13 - P5.0_IO */
		PIN_FUNC_UNUSED,	/*  14 - P1.7_SPIMISO */
		PIN_FUNC_UNUSED,	/*  15 - P1.6_SPIMOSI */
		PIN_FUNC_UNUSED,	/*  16 - RESET */
		PIN_FUNC_UNUSED,	/*  17 - P5.7_IO */
		PIN_FUNC_UNUSED,	/*  18 - P3.0_IO */
		PIN_FUNC_UNUSED,	/*  19 - P2.5_IO_PWM */
		PIN_FUNC_UNUSED,	/*  20 - GND */
		PIN_FUNC_UNUSED,	/*  21 - 5V */
		PIN_FUNC_UNUSED,	/*  22 - GND */
		PIN_FUNC_UNUSED,	/*  23 - P6.1_A14 */
		PIN_FUNC_UNUSED,	/*  24 - P4.0_A13 */
		PIN_FUNC_UNUSED,	/*  25 - P4.2_A11 */
		PIN_FUNC_UNUSED,	/*  26 - P4.4_A9 */
		PIN_FUNC_UNUSED,	/*  27 - P4.5_A8 */
		PIN_FUNC_UNUSED,	/*  28 - P4.7_A6 */
		PIN_FUNC_UNUSED,	/*  29 - P5.4_IO */
		PIN_FUNC_UNUSED,	/*  30 - P5.5_IO */
		PIN_FUNC_UNUSED,	/*  31 - P3.7_IO */
		PIN_FUNC_UNUSED,	/*  32 - P3.5_IO */
		PIN_FUNC_UNUSED,	/*  33 - P5.1_IO */
		PIN_FUNC_UNUSED,	/*  34 - P2.3_IO */
		PIN_FUNC_UNUSED,	/*  35 - P6.7_IO_CAPT */
		PIN_FUNC_UNUSED,	/*  36 - P6.6_IO_CAPT */
		PIN_FUNC_UNUSED,	/*  37 - P5.6_PWM */
		PIN_FUNC_UNUSED,	/*  38 - P2.4_PWM */
		PIN_FUNC_UNUSED,	/*  39 - P2.6_PWM */
		PIN_FUNC_UNUSED,	/*  40 - P2.7_PWM */
		PIN_FUNC_UNUSED,	/*  41 - P1.1 SW1 */
		PIN_FUNC_UNUSED,	/*  42 - P1.4 SW2 */
		PIN_FUNC_UNUSED,	/*  43 - P2.0 RED_LED */
		PIN_FUNC_UNUSED,	/*  44 - P2.1 GREEN_LED */
		PIN_FUNC_UNUSED,	/*  45 - P2.2 BLUE_LED */
		PIN_FUNC_UNUSED,	/*  46 - P1.0 LED1 */
};
#endif
#endif
