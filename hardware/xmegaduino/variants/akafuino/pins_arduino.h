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

#define NUM_DIGITAL_PINS            28
#define NUM_ANALOG_INPUTS           6
#define EXTERNAL_NUM_INTERRUPTS     36 // PORTA to PORTE 3

#define analogInputToDigitalPin(p)  ((p < 6) ? (p) + 22 : -1)
#define digitalPinHasPWM(p)         (((p) >= 2 && (p) <= 6) || ((p) >= 9 && (p)<= 11) || ((p) >= 14 && (p)<= 19))

const static uint8_t SS    = 6;
const static uint8_t MOSI  = 11;
const static uint8_t MISO  = 12;
const static uint8_t SCK   = 13;

const static uint8_t SDA = 2;
const static uint8_t SCL = 3;
const static uint8_t LED_BUILTIN = 13;

const static uint8_t A0 = 22;
const static uint8_t A1 = 23;
const static uint8_t A2 = 24;
const static uint8_t A3 = 25;
const static uint8_t A4 = 26;
const static uint8_t A5 = 27;

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#ifdef ARDUINO_MAIN

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA_DIR,
	(uint16_t) &PORTB_DIR,
	(uint16_t) &PORTC_DIR,
	(uint16_t) &PORTD_DIR,
	(uint16_t) &PORTE_DIR,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA_IN,
	(uint16_t) &PORTB_IN,
	(uint16_t) &PORTC_IN,
	(uint16_t) &PORTD_IN,
	(uint16_t) &PORTE_IN,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
		// PORTLIST
		PC,/* 0 */
		PC,
		PC,
		PC,
		PD,
		PD,
		PD,
		PB,
		PB,/* 8 */
		PC,
		PC,
		PD,
		PD,
		PD,
		PE,/* 14 */
		PE,
		PE,
		PE,
		PD,
		PD,
		PC,
		PC, /* 21 */
		PA, /* A0 */
		PA,
		PA,
		PA,
		PA,
		PA,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
		// PIN IN PORT		
		// -------------------------------------------		
		_BV( 2 ), // 0
		_BV( 3 ),
		_BV( 0 ),
		_BV( 1 ),
		_BV( 2 ),
		_BV( 3 ),
		_BV( 4 ),
		_BV( 2 ),
		_BV( 3 ), // 8
		_BV( 4 ),
		_BV( 5 ),
		_BV( 5 ),
		_BV( 6 ),
		_BV( 7 ),
		_BV( 0 ), // 14
		_BV( 1 ),
		_BV( 2 ),
		_BV( 3 ),
		_BV( 0 ),
		_BV( 1 ),
		_BV( 6 ),
		_BV( 7 ), // 21
		_BV( 0 ), // A0
		_BV( 1 ),
		_BV( 2 ),
		_BV( 3 ),
		_BV( 4 ),
		_BV( 5 ),
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
	TIMER_C0C	, // 0
	TIMER_C0D	, 
	TIMER_C0A	, 
	TIMER_C0B	, 
	TIMER_D0C	, 
	TIMER_D0D	, 
	TIMER_D1A	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	TIMER_C1A	, // 8
	TIMER_C1B	, 
	TIMER_D1B	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	TIMER_E0A	, // 14
	TIMER_E0B	, 
	TIMER_E0C	, 
	TIMER_E0D	, 
	TIMER_D0A	, 
	TIMER_D0B	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, // 21
	NOT_ON_TIMER	, // A0
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
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
	NULL,
	NULL,
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

#endif

#endif
