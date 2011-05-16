/*
  pins_arduino.c - pin definitions for the Arduino board
  Part of Arduino / Wiring Lite

  Copyright (c) 2005 David A. Mellis

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

  $Id: pins_arduino.c 804 2009-12-18 16:05:52Z dmellis $
*/

#include <avr/io.h>
#include "wiring_private.h"
#include "pins_arduino.h"

#define REPEAT8(x) x, x, x, x, x, x, x, x
#define BV0TO7 _BV(0), _BV(1), _BV(2), _BV(3), _BV(4), _BV(5), _BV(6), _BV(7)
#define BV7TO0 _BV(7), _BV(6), _BV(5), _BV(4), _BV(3), _BV(2), _BV(1), _BV(0)

#define DDRA PORTA_DIR
#define DDRB PORTB_DIR
#define DDRC PORTC_DIR
#define DDRD PORTD_DIR
#define DDRE PORTE_DIR
#define DDRF PORTF_DIR
#define DDRH PORTH_DIR
#define DDRJ PORTJ_DIR
#define DDRK PORTK_DIR

// TODO: Kill PINX. Just use PORTX_IN.
#define PINA PORTA_IN
#define PINB PORTB_IN
#define PINC PORTC_IN
#define PIND PORTD_IN
#define PINE PORTE_IN
#define PINF PORTF_IN
#define PINH PORTH_IN
#define PINJ PORTJ_IN
#define PINK PORTK_IN

const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	&DDRA,
	&DDRB,
	&DDRC,
	&DDRD,
	&DDRE,
	// Not defined on all xmegas
#if defined(PORTF)
	&DDRF,
#endif
#if defined(PORTH)
	&DDRH,
#endif
#if defined(PORTJ)
	&DDRJ,
#endif
#if defined(PORTK)
	&DDRK,
#endif
};

const uint16_t PROGMEM port_to_portReg_PGM[] = {
	NOT_A_PORT,
	&PORTA,
	&PORTB,
	&PORTC,
	&PORTD,
	&PORTE,
#if defined(PORTF)
	&PORTF,
#endif
#if defined(PORTH)
	&PORTH,
#endif
#if defined(PORTJ)
	&PORTJ,
#endif
#if defined(PORTK)
	&PORTK,
#endif
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	&PINA,
	&PINB,
	&PINC,
	&PIND,
	&PINE,
#if defined(PORTF)
	&PINF,
#endif
#if defined(PORTH)
	&PINH,
#endif
#if defined(PORTJ)
	&PINJ,
#endif
#if defined(PORTK)
	&PINK,
#endif
};

#if BOARD_sfe == BOARD

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST
        REPEAT8(PA), //  0 -  7
        REPEAT8(PB), //  8 - 15
        REPEAT8(PC), // 16 - 23
        REPEAT8(PD), // 24 - 31
        REPEAT8(PE), // 32 - 39
        REPEAT8(PF), // 40 - 47
        REPEAT8(PH), // 48 - 55
        REPEAT8(PJ), // 56 - 63
        REPEAT8(PK), // 64 - 71
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
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
	// TIMERS		
	// -------------------------------------------		
	REPEAT8(NOT_ON_TIMER), // PORT A
	REPEAT8(NOT_ON_TIMER), // PORT B
	TIMER_C0A, // PORT C
	TIMER_C0B,
	TIMER_C0C,
	TIMER_C0D,
	TIMER_C1A,
	TIMER_C1B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER_D0A, // PORT D
	TIMER_D0B,
	TIMER_D0C,
	TIMER_D0D,
	TIMER_D1A,
	TIMER_D1B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	TIMER_E0A, // PORT E
	TIMER_E0B,
	TIMER_E0C,
	TIMER_E0D,
	TIMER_E1A,
	TIMER_E1B,
	NOT_ON_TIMER,
	NOT_ON_TIMER,
	REPEAT8(NOT_ON_TIMER), // PORT F Switches
	};

#elif BOARD_xplain == BOARD

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
	// PIN IN PORT		
	// -------------------------------------------		
	BV0TO7, // PORT A Header
	BV0TO7, // PORT B Pot and Speaker
	BV0TO7, // PORT C USARTC0 to USB on 2&3
	BV0TO7, // PORT D Header
	BV0TO7, // PORT E LEDs
	BV0TO7, // PORT F Switches
	};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
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

#elif BOARD_xplain_arduino == BOARD

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	// PORTLIST
	PC,
	PC,
	PA,
	PA,
	PA,
	PD,
	PD,
	PA,
	PA,
	PA,
	PD,
	PD,
	PF,//PD, //DEBUG !!!
	PE,//PD, //DEBUG !!!
	PB,
	PB,
	PB,
	PB,
	PD,
	PD,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	// PIN IN PORT		
	// -------------------------------------------		
	_BV( 2 ), // C
	_BV( 3 ), // C
	_BV( 0 ), // A
	_BV( 2 ), // A
	_BV( 1 ), // A
	_BV( 2 ), // D
	_BV( 3 ), // D
	_BV( 5 ), // A
	_BV( 6 ), // A
	_BV( 7 ), // A
	_BV( 4 ), // D
	_BV( 5 ), // D
	_BV( 6 ), // F (DEBUG) // D
	_BV( 7 ), // E (DEBUG) // D
	_BV( 4 ), // B
	_BV( 5 ), // B
	_BV( 6 ), // B
	_BV( 7 ), // B
	_BV( 0 ), // D
	_BV( 1 ), // D
	};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	// TIMERS		
	// -------------------------------------------		
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	NOT_ON_TIMER	, 
	};

#else

#error BOARD not defined

#endif

const TC0_t* PROGMEM timer_to_tc0_PGM[] = {
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
    NULL,

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

