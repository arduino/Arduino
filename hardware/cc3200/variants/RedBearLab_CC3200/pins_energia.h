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

#define LED  13
static const uint8_t RED_LED = 13;
static const uint8_t GREEN_LED = 13;
static const uint8_t YELLOW_LED = 13;

static const uint8_t PUSH1 = 20;
static const uint8_t PUSH2 = 21;

static const uint8_t SDA = 14;
static const uint8_t SCL = 15;

static const uint8_t SS   = 10;
static const uint8_t MOSI = 22;
static const uint8_t MISO = 23;
static const uint8_t SCK  = 24;

static const uint8_t A0 = 16;
static const uint8_t A1 = 17;
static const uint8_t A2 = 18;
static const uint8_t A3 = 19;

#ifdef ARDUINO_MAIN
const uint32_t port_to_base[] = {
	NOT_A_PORT,
	(uint32_t) GPIOA0_BASE,
	(uint32_t) GPIOA1_BASE,
	(uint32_t) GPIOA2_BASE,
	(uint32_t) GPIOA3_BASE,
};

const uint16_t digital_pin_to_pin_num[] = {
    PIN_57,         // D0 - IO2
    PIN_55,         // D1 - IO1
    PIN_61,         // D2 - IO6
    PIN_62,         // D3 - IO7
    PIN_63,         // D4 - IO8
    PIN_64,         // D5 - IO9
    PIN_17,         // D6 - IO24
    PIN_16,         // D7 - IO23
    PIN_04,         // D8 - IO13
    PIN_15,         // D9 - IO22
    PIN_08,         // D10 - IO17
    PIN_03,         // D11 - IO12
    PIN_20,         // D12 - IO29
    PIN_50,         // D13 - IO0
    PIN_02,         // D14 - IO11
    PIN_01,         // D15 - IO10
    PIN_57,         // D16/A0 - IO02
    PIN_60,         // D17/A1 - IO05
    PIN_59,         // D18/A2 - IO04
    PIN_58,         // D19/A3 - IO03    
    PIN_53,         // D20 - IO30
    PIN_18,         // D21 - IO28
    PIN_07,         // D22 - IO16
    PIN_06,         // D23 - IO15
    PIN_05,         // D24 - IO14
};

const uint8_t digital_pin_to_port[] = {
    S0,         // D0 - IO2
    S0,         // D1 - IO1
    S0,         // D2 - IO6
    S0,         // D3 - IO7
    S1,         // D4 - IO8
    S1,         // D5 - IO9
    S3,         // D6 - IO24
    S2,         // D7 - IO23
    S1,         // D8 - IO13
    S2,         // D9 - IO22
    S2,         // D10 - IO17
    S1,         // D11 - IO12
    S3,         // D12 - IO29
    S0,         // D13 - IO0
    S1,         // D14 - IO11
    S1,         // D15 - IO10
    S0,         // D16/A0 - IO02
    S0,         // D17/A1 - IO05
    S0,         // D18/A2 - IO04
    S0,         // D19/A3 - IO03    
    S3,         // D20 - IO30
    S3,         // D21 - IO28
    S2,         // D22 - IO16
    S1,         // D23 - IO15
    S1,         // D24 - IO14 
};

const uint8_t digital_pin_to_bit_mask[] = {
    BV(2),         // D0 - IO2
    BV(1),         // D1 - IO1
    BV(6),         // D2 - IO6
    BV(7),         // D3 - IO7
    BV(0),         // D4 - IO8
    BV(1),         // D5 - IO9
    BV(0),         // D6 - IO24
    BV(7),         // D7 - IO23
    BV(5),         // D8 - IO13
    BV(6),         // D9 - IO22
    BV(1),         // D10 - IO17
    BV(4),         // D11 - IO12
    BV(5),         // D12 - IO29
    BV(0),         // D13 - IO0
    BV(3),         // D14 - IO11
    BV(2),         // D15 - IO10
    BV(2),         // D16/A0 - IO02
    BV(5),         // D17/A1 - IO05
    BV(4),         // D18/A2 - IO04
    BV(3),         // D19/A3 - IO03    
    BV(6),         // D20 - IO30
    BV(4),         // D21 - IO28
    BV(0),         // D22 - IO16
    BV(7),         // D23 - IO15
    BV(6),         // D24 - IO14
};

const uint8_t digital_pin_to_timer[] = {
    NOT_ON_TIMER,         // D0 - IO2
    NOT_ON_TIMER,         // D1 - IO1
    NOT_ON_TIMER,         // D2 - IO6
    NOT_ON_TIMER,         // D3 - IO7
    NOT_ON_TIMER,         // D4 - IO8
    TIMERA2B,         // D5 - IO9
    TIMERA0A,         // D6 - IO24
    NOT_ON_TIMER,         // D7 - IO23
    NOT_ON_TIMER,         // D8 - IO13
    NOT_ON_TIMER,         // D9 - IO22
    NOT_ON_TIMER,         // D10 - IO17
    NOT_ON_TIMER,         // D11 - IO12
    NOT_ON_TIMER,         // D12 - IO29
    NOT_ON_TIMER,         // D13 - IO0
    TIMERA3B,         // D14 - IO11
    TIMERA3A,         // D15 - IO10
    NOT_ON_TIMER,         // D16/A0 - IO02
    NOT_ON_TIMER,         // D17/A1 - IO05
    NOT_ON_TIMER,         // D18/A2 - IO04
    NOT_ON_TIMER,         // D19/A3 - IO03    
    NOT_ON_TIMER,         // D20 - IO30
    NOT_ON_TIMER,         // D21 - IO28
    NOT_ON_TIMER,         // D22 - IO16
    NOT_ON_TIMER,         // D23 - IO15
    NOT_ON_TIMER,         // D24 - IO14 
};

#endif
#endif
