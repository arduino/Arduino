/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2014 Frank Oltmanns

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

#define NUM_DIGITAL_PINS            53
#define NUM_ANALOG_INPUTS           8
#define analogInputToDigitalPin(p)  ((p < 8) ? (p) + 45 : -1)

//PB7, PB6, PB5, PB4
#define digitalPinHasPWM(p)         (((p) >= 12) && ((p) <= 15))

static const uint8_t SS   = 8;  //PB0
static const uint8_t MOSI = 10; //PB2
static const uint8_t MISO = 11; //PB3
static const uint8_t SCK  = 9;  //PB1

static const uint8_t SDA = 5; //PE5
static const uint8_t SCL = 4; //PE4

static const uint8_t A0 = 45;
static const uint8_t A1 = 46;
static const uint8_t A2 = 47;
static const uint8_t A3 = 48;
static const uint8_t A4 = 49;
static const uint8_t A5 = 50;
static const uint8_t A6 = 51;
static const uint8_t A7 = 52;

#if 0
// These defines seem not to be needed for any Arduino function, is it? Maybe interrupt?
// The ones below are taken from the standard Arduino board.
#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))
#endif

#ifdef ARDUINO_MAIN

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &DDRA,
	(uint16_t) &DDRB,
	(uint16_t) &DDRC,
	(uint16_t) &DDRD,
	(uint16_t) &DDRE,
	(uint16_t) &DDRF,
	(uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
	NOT_A_PORT,
	(uint16_t) &PORTA,
	(uint16_t) &PORTB,
	(uint16_t) &PORTC,
	(uint16_t) &PORTD,
	(uint16_t) &PORTE,
	(uint16_t) &PORTF,
	(uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
	NOT_A_PIN,
	(uint16_t) &PINA,
	(uint16_t) &PINB,
	(uint16_t) &PINC,
	(uint16_t) &PIND,
	(uint16_t) &PINE,
	(uint16_t) &PINF,
	(uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
	PE, // D0 - RXD - PE0 
	PE, // D1 - TXD - PE1 
	PE, // D2 - PE2 
	PE, // D3 - PE3 
	PE, // D4 - SCL - PE4 
	PE, // D5 - SDA - PE5 
	PE, // D6 - PE6 
	PE, // D7 - PE7 

	PB, // D8 - SS - PB0 
	PB, // D9 - SCK - PB1 
	PB, // D10 - MOSI - PB2 
	PB, // D11 - MISO - PB3 
	PB, // D12 - PB4 
	PB, // D13 - PB5 
	PB, // D14 - PB6 
	PB, // D15 - PB7 

	PG, // D16 - PG3 
	PG, // D17 - PG4 
	PD, // D18 - PD0 
	PD, // D19 - PD1 
	PD, // D20 - PD2 
	PD, // D21 - PD3 
	PD, // D22 - PD4 
	PD, // D23 - PD5 

	PD, // D24 - PD6 
	PD, // D25 - PD7 
	PG, // D26 - PG0 
	PG, // D27 - PG1 
	PC, // D28 - PC0 
	PC, // D29 - PC1 
	PC, // D30 - PC2 
	PC, // D31 - PC3 

	PC, // D32 - PC4 
	PC, // D33 - PC5 
	PC, // D34 - PC6 
	PC, // D35 - PC7 
	PG, // D36 - PG2 
	PA, // D37 - PA7 
	PA, // D38 - PA6 
	PA, // D39 - PA5 

	PA, // D40 - PA4 
	PA, // D41 - PA3 
	PA, // D42 - PA2 
	PA, // D43 - PA1 
	PA, // D44 - PA0 
	PF, // D45 - A0 - PF7 
	PF, // D46 - A1 - PF6 
	PF, // D47 - A2 - PF5 

	PF, // D48 - A3 - PF4 
	PF, // D49 - A4 - PF3 
	PF, // D50 - A5 - PF2 
	PF, // D51 - A6 - PF1 
	PF, // D52 - A7 - PF0 
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(0), // D0 - RXD - PE0 
	_BV(1), // D1 - TXD - PE1 
	_BV(2), // D2 - PE2 
	_BV(3), // D3 - PE3 
	_BV(4), // D4 - SCL - PE4 
	_BV(5), // D5 - SDA - PE5
	_BV(6), // D6 - PE6 
	_BV(7), // D7 - PE7 

	_BV(0), // D8 - SS - PB0 
	_BV(1), // D9 - SCK - PB1 
	_BV(2), // D10 - MOSI - PB2 
	_BV(3), // D11 - MISO - PB3 
	_BV(4), // D12 - PB4 
	_BV(5), // D13 - PB5 
	_BV(6), // D14 - PB6 
	_BV(7), // D15 - PB7 

	_BV(3), // D16 - PG3 
	_BV(4), // D17 - PG4 
	_BV(0), // D18 - PD0 
	_BV(1), // D19 - PD1 
	_BV(2), // D20 - PD2 
	_BV(3), // D21 - PD3 
	_BV(4), // D22 - PD4 
	_BV(5), // D23 - PD5 

	_BV(6), // D24 - PD6 
	_BV(7), // D25 - PD7 
	_BV(0), // D26 - PG0 
	_BV(1), // D27 - PG1 
	_BV(0), // D28 - PC0 
	_BV(1), // D29 - PC1 
	_BV(2), // D30 - PC2 
	_BV(3), // D31 - PC3 

	_BV(4), // D32 - PC4 
	_BV(5), // D33 - PC5 
	_BV(6), // D34 - PC6 
	_BV(7), // D35 - PC7 
	_BV(2), // D36 - PG2 
	_BV(7), // D37 - PA7 
	_BV(6), // D38 - PA6 
	_BV(5), // D39 - PA5 

	_BV(4), // D40 - PA4 
	_BV(3), // D41 - PA3 
	_BV(2), // D42 - PA2 
	_BV(1), // D43 - PA1 
	_BV(0), // D44 - PA0 
	_BV(7), // D45 - A0 - PF7 
	_BV(6), // D46 - A1 - PF6 
	_BV(5), // D47 - A2 - PF5 

	_BV(4), // D48 - A3 - PF4 
	_BV(3), // D49 - A4 - PF3 
	_BV(2), // D50 - A5 - PF2 
	_BV(1), // D51 - A6 - PF1 
	_BV(0), // D52 - A7 - PF0 
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
	NOT_ON_TIMER, // D0 - RXD - PE0 
	NOT_ON_TIMER, // D1 - TXD - PE1 
	NOT_ON_TIMER, // D2 - PE2 
	NOT_ON_TIMER, // D3 - PE3 
	NOT_ON_TIMER, // D4 - SCL - PE4 
	NOT_ON_TIMER, // D5 - SDA - PE5
	NOT_ON_TIMER, // D6 - PE6 
	NOT_ON_TIMER, // D7 - PE7 

	NOT_ON_TIMER, // D8 - SS - PB0 
	NOT_ON_TIMER, // D9 - SCK - PB1 
	NOT_ON_TIMER, // D10 - MOSI - PB2 
	NOT_ON_TIMER, // D11 - MISO - PB3 
	TIMER0A,      // D12 - PB4 
	TIMER1A,      // D13 - PB5 
	TIMER1B,      // D14 - PB6 
	TIMER2A,      // D15 - PB7 

	NOT_ON_TIMER, // D16 - PG3 
	NOT_ON_TIMER, // D17 - PG4 
	NOT_ON_TIMER, // D18 - PD0 
	NOT_ON_TIMER, // D19 - PD1 
	NOT_ON_TIMER, // D20 - PD2 
	NOT_ON_TIMER, // D21 - PD3 
	NOT_ON_TIMER, // D22 - PD4 
	NOT_ON_TIMER, // D23 - PD5 

	NOT_ON_TIMER, // D24 - PD6 
	NOT_ON_TIMER, // D25 - PD7 
	NOT_ON_TIMER, // D26 - PG0 
	NOT_ON_TIMER, // D27 - PG1 
	NOT_ON_TIMER, // D28 - PC0 
	NOT_ON_TIMER, // D29 - PC1 
	NOT_ON_TIMER, // D30 - PC2 
	NOT_ON_TIMER, // D31 - PC3 

	NOT_ON_TIMER, // D32 - PC4 
	NOT_ON_TIMER, // D33 - PC5 
	NOT_ON_TIMER, // D34 - PC6 
	NOT_ON_TIMER, // D35 - PC7 
	NOT_ON_TIMER, // D36 - PG2 
	NOT_ON_TIMER, // D37 - PA7 
	NOT_ON_TIMER, // D38 - PA6 
	NOT_ON_TIMER, // D39 - PA5 

	NOT_ON_TIMER, // D40 - PA4 
	NOT_ON_TIMER, // D41 - PA3 
	NOT_ON_TIMER, // D42 - PA2 
	NOT_ON_TIMER, // D43 - PA1 
	NOT_ON_TIMER, // D44 - PA0 
	NOT_ON_TIMER, // D45 - A0 - PF7 
	NOT_ON_TIMER, // D46 - A1 - PF6 
	NOT_ON_TIMER, // D47 - A2 - PF5 

	NOT_ON_TIMER, // D48 - A3 - PF4 
	NOT_ON_TIMER, // D49 - A4 - PF3 
	NOT_ON_TIMER, // D50 - A5 - PF2 
	NOT_ON_TIMER, // D51 - A6 - PF1 
	NOT_ON_TIMER, // D52 - A7 - PF0 
};

#endif

#endif
