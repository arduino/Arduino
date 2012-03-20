/*
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

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define REPEAT8(x) x, x, x, x, x, x, x, x
#define BV0TO7 _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7)
#define BV7TO0 _BV(7), _BV(6), _BV(5), _BV(4), _BV(3), _BV(2), _BV(1), _BV(0)

#define NUM_DIGITAL_PINS            72
#define NUM_ANALOG_INPUTS           16
#define EXTERNAL_NUM_INTERRUPTS     48

#define analogInputToDigitalPin(p)  ((p < 16) ? p : -1)
#define digitalPinHasPWM(p)         (((p) >= 16 && (p) <= 21) || ((p) >= 24 && (p)<= 29) || ((p) >= 32 && (p)<= 37))

static const uint8_t SS    = 20;
static const uint8_t MOSI  = 21;
static const uint8_t MISO  = 22;
static const uint8_t SCK   = 23;
static const uint8_t SS1   = 28;
static const uint8_t MOSI1 = 29;
static const uint8_t MISO1 = 30;
static const uint8_t SCK1  = 31;
static const uint8_t SS2   = 36;
static const uint8_t MOSI2 = 37;
static const uint8_t MISO2 = 38;
static const uint8_t SCK2  = 39;
static const uint8_t SS3   = 44;
static const uint8_t MOSI3 = 45;
static const uint8_t MISO3 = 46;
static const uint8_t SCK3  = 47;

static const uint8_t SDA = 16;
static const uint8_t SCL = 17;
static const uint8_t LED_BUILTIN = 13;

static const uint8_t A0 = 0;
static const uint8_t A1 = 1;
static const uint8_t A2 = 2;
static const uint8_t A3 = 3;
static const uint8_t A4 = 4;
static const uint8_t A5 = 5;
static const uint8_t A6 = 6;
static const uint8_t A7 = 7;
static const uint8_t A8 = 8;
static const uint8_t A9 = 9;
static const uint8_t A10 = 10;
static const uint8_t A11 = 11;
static const uint8_t A12 = 12;
static const uint8_t A13 = 13;
static const uint8_t A14 = 14;
static const uint8_t A15 = 15;

#define Wire xmWireC
#define Wire1 xmWireD
#define Wire2 xmWireE
#define Wire3 xmWireF

#define SPI_PORT	SPIC

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)

const uint16_t PROGMEM port_to_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTH,
	(uint16_t) &PORTJ,
	(uint16_t) &PORTK,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST
	REPEAT8(PA), // Header
	REPEAT8(PB), // Pot and Speaker
	REPEAT8(PC), // USARTC0 connected to USB on 2&3
	REPEAT8(PD), // Header
	REPEAT8(PE), // LEDs
	REPEAT8(PF), // Switches
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	BV0TO7, // PORT A
	BV0TO7, // PORT B
	BV0TO7, // PORT C
	BV0TO7, // PORT D
	BV0TO7, // PORT E
	BV0TO7, // PORT F
	BV0TO7, // PORT H
	BV0TO7, // PORT J
	BV0TO7, // PORT K
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	REPEAT8(NOT_ON_TIMER), // PORT A Header
	REPEAT8(NOT_ON_TIMER), // PORT B Pot and Speaker
	REPEAT8(NOT_ON_TIMER), // PORT C USARTC0 to USB on 2&3
	TIMER_D0A, // PORT D Header
	TIMER_D0B,
	TIMER_D0C,
	TIMER_D0D,
	TIMER_D1A,
	TIMER_D1B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER_E0A, // PORT E LEDs
	TIMER_E0B,
	TIMER_E0C,
	TIMER_E0D,
	TIMER_E1A,
	TIMER_E1B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	REPEAT8(NOT_ON_TIMER), // PORT F Switches
};

const TC0_t* PROGMEM timer_to_tc0_PGM[] = {
	NULL,

	&TCC0,
	&TCC0,
	&TCC0,
	&TCC0,
	NULL,
	NULL,

	&TCD0,
	&TCD0,
	&TCD0,
	&TCD0,
	NULL,
	NULL,

	&TCE0,
	&TCE0,
	&TCE0,
	&TCE0,
	NULL,
	NULL,
	};

const TC1_t* PROGMEM timer_to_tc1_PGM[] = {
	NULL,

	NULL,
	NULL,
	NULL,
	NULL,
	&TCC1,
	&TCC1,

	NULL,
	NULL,
	NULL,
	NULL,
	&TCD1,
	&TCD1,

	NULL,
	NULL,
	NULL,
	NULL,
	// TCE1 not defined on all xmegas
#if defined(PORTH)
	&TCE1,
	&TCE1,
#else
	NULL,
	NULL,
#endif
	};

const uint8_t PROGMEM timer_to_channel_PGM[] = {
	NOT_ON_TIMER,

    0,
    1,
    2,
    3,
    0,
    1,

    0,
    1,
    2,
    3,
    0,
    1,

    0,
    1,
    2,
    3,
    0,
    1,
};

const uint8_t PROGMEM adc_to_channel_PGM[] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,  
    10,
    11,
    12,
    13,
    14,
    15
};


#endif

#endif
