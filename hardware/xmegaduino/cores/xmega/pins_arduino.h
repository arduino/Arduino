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

  $Id: wiring.h 249 2007-02-03 16:52:51Z mellis $
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#define NOT_A_PIN 0
#define NOT_A_PORT 0

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PH 7
#define PJ 8
#define PK 9

#define NOT_ON_TIMER 0

#define TIMER_C0A  1
#define TIMER_C0B  2
#define TIMER_C0C  3
#define TIMER_C0D  4
#define TIMER_C1A  5
#define TIMER_C1B  6

#define TIMER_D0A  7
#define TIMER_D0B  8
#define TIMER_D0C  9
#define TIMER_D0D 10
#define TIMER_D1A 11
#define TIMER_D1B 12

#define TIMER_E0A 13
#define TIMER_E0B 14
#define TIMER_E0C 15
#define TIMER_E0D 16
#define TIMER_E1A 17
#define TIMER_E1B 18


// TODO: Revise so we don't need the port index stuff: PORTA, ..., PORTF. Just use port register.

// On the ATmega1280, the addresses of some of the port registers are
// greater than 255, so we can't store them in uint8_t's.
extern const uint16_t PROGMEM port_to_mode_PGM[];
extern const uint16_t PROGMEM port_to_input_PGM[];
extern const uint16_t PROGMEM port_to_portReg_PGM[];

extern const uint8_t PROGMEM digital_pin_to_port_PGM[];
extern const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[];
extern const uint8_t PROGMEM digital_pin_to_timer_PGM[];
extern const TC0_t* PROGMEM timer_to_tc0_PGM[];
extern const TC1_t* PROGMEM timer_to_tc1_PGM[];
extern const uint8_t PROGMEM timer_to_channel_register_PGM[];

// Get the bit location within the hardware port of the given virtual pin.
// This comes from the pins_*.c file for the active board configuration.
// 
// These perform slightly better as macros compared to inline functions
//
#define digitalPinToPort(P) ( pgm_read_byte( digital_pin_to_port_PGM + (P) ) )
#define digitalPinToBitMask(P) ( pgm_read_byte( digital_pin_to_bit_mask_PGM + (P) ) )
#define digitalPinToTimer(P) ( pgm_read_byte( digital_pin_to_timer_PGM + (P) ) )
#define analogInPinToBit(P) (P)
#define portInputRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_input_PGM + (P))) )
#define portModeRegister(P) ( (volatile uint8_t *)( pgm_read_word( port_to_mode_PGM + (P))) )
#define portRegister(P) ( (volatile PORT_t *)( pgm_read_word( port_to_portReg_PGM + (P))) )
#define timerToTC0(T) ( (volatile TC0_t *)( pgm_read_word( timer_to_tc0_PGM + (T))) )
#define timerToTC1(T) ( (volatile TC1_t *)( pgm_read_word( timer_to_tc1_PGM + (T))) )
#define timerToChannel(T) ( (uint8_t)( pgm_read_word( timer_to_channel_register_PGM + (T))) )

#endif
