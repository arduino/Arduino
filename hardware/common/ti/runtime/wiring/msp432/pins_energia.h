/*
 ************************************************************************
 *	pins_energia.h
 *
 *	Energia core files for MSP432
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
#include <timer_a.h>
#include <uart.h>
#include <wdt_a.h>

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
