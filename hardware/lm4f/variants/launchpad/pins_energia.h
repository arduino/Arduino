/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for LM4F
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: Rei VILO
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

#ifndef Pins_Arduino_h
#define Pins_Arduino_h
#ifndef BV
#define BV(x) (1 << (x))
#endif
/*
static const uint8_t SS   = 8;  // P2.0
static const uint8_t SCK  = 7;  // P1.5
static const uint8_t MOSI = 15; // P1.7
static const uint8_t MISO = 14; // P1.6
*/
// Pin names based on the silkscreen
//
static const uint8_t PB_6 = 1;
static const uint8_t PB_7 = 4;
static const uint8_t PF_4 = 5;
static const uint8_t PE_3 = 6;
static const uint8_t PE_2 = 7;
static const uint8_t PE_1 = 8;
static const uint8_t PE_0 = 9;
static const uint8_t PD_7 = 10;
static const uint8_t PC_7 = 13;
static const uint8_t PC_6 = 14;
static const uint8_t PC_5 = 15;
static const uint8_t PC_4 = 16;
static const uint8_t PA_0 = 17;
static const uint8_t PA_1 = 18;
static const uint8_t PA_2 = 19;
static const uint8_t PA_3 = 20;
static const uint8_t PA_4 = 21;
static const uint8_t PA_5 = 22;
static const uint8_t PA_6 = 23;
static const uint8_t PA_7 = 24;
static const uint8_t PF_0 = 28;
static const uint8_t PF_1 = 29;
static const uint8_t PF_2 = 30;
static const uint8_t PF_3 = 31;
static const uint8_t PD_4 = 43;
static const uint8_t PD_5 = 44;
static const uint8_t PB_0 = 45;
static const uint8_t PB_1 = 46;
static const uint8_t PB_2 = 47;
static const uint8_t PB_3 = 48;
static const uint8_t PC_3 = 49;
static const uint8_t PC_2 = 50;
static const uint8_t PC_1 = 51;
static const uint8_t PC_0 = 52;
static const uint8_t PD_6 = 53;
static const uint8_t PB_5 = 57;
static const uint8_t PB_4 = 58;
static const uint8_t PE_4 = 59;
static const uint8_t PE_5 = 60;
static const uint8_t PD_0 = 61;
static const uint8_t PD_1 = 62;
static const uint8_t PD_2 = 63;
static const uint8_t PD_3 = 64;

static const uint8_t RED_LED = 2;
static const uint8_t GREEN_LED = 14;
static const uint8_t PUSH2 = 5;
static const uint8_t TEMPSENSOR = 10; // depends on chip


#ifdef ARDUINO_MAIN

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3DIR,
#endif
};

const uint16_t port_to_sel[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL,
#endif
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3REN,
#endif
};

const uint16_t port_to_sel2[] = {
	NOT_A_PORT,
#ifdef P1SEL2_
	(uint16_t) &P1SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P2SEL2_
	(uint16_t) &P2SEL2,
#else 
        NOT_A_PORT,
#endif
#ifdef P3SEL2_
	(uint16_t) &P3SEL2,
#else
        NOT_A_PORT,
#endif
};

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3IN,
#endif
};
const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3OUT,
#endif
};

/* 
 * Defines for devices with 2x TA3 timers (e.g. MSP430g2553). On the 20pin devices, upto 3 analog outputs are available
 * T0A1, T1A1 and T1A2 
 */
const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  dummy */
	NOT_ON_TIMER, /*  1 - VCC */
	NOT_ON_TIMER, /*  2 - P1.0 */
	T0A0,         /*  3 - P1.1, note: A0 output cannot be used with analogWrite */
	T0A1,         /*  4 - P1.2 */
	NOT_ON_TIMER, /*  5 - P1.3 */
	NOT_ON_TIMER, /*  6 - P1.4 note: special case. Leaving as no timer due to difficulty determining if available */
	T0A0,         /*  7 - P1.5 note: A0 output cannot be used with analogWrite  */
#if defined(__MSP430_HAS_T1A3__) 
	T1A0,         /*  8 - P2.0 note: A0 output cannot be used with analogWrite */
	T1A1,         /*  9 - P2.1 */
	T1A1,         /* 10 - P2.3 */
	T1A0,         /* 11 - P2.4 note: A0 output cannot be used with analogWrite  */
	T1A2,         /* 12 - P2.5 */
	T1A2,         /* 13 - P2.6 */
#else
	NOT_ON_TIMER, /*  8 - P2.0 */
	NOT_ON_TIMER, /*  9 - P2.1 */
	NOT_ON_TIMER, /* 10 - P2.3 */
	NOT_ON_TIMER, /* 11 - P2.4 */
	NOT_ON_TIMER, /* 12 - P2.5 */
	NOT_ON_TIMER, /* 13 - P2.6 */
#endif
	T0A1,         /* 14 - P1.6 */
	NOT_ON_TIMER, /* 15 - P1.7 */
	NOT_ON_TIMER, /* 16 - /RESET */  
	NOT_ON_TIMER, /* 17 - TEST */  
	NOT_ON_TIMER, /* 18 - XOUT - P2.7 */
	T0A1,         /* 18 - XIN - P2.6: */
	NOT_ON_TIMER, /* 20 - GND */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN, /* dummy */
	NOT_A_PIN, /* 1 */
	P1, /* 2 */
	P1, /* 3 */
	P1, /* 4 */
	P1, /* 5 */
	P1, /* 6 */
	P1, /* 7 */
	P2, /* 8 */
	P2, /* 9 */
	P2, /* 10 */
	P2, /* 11 */
	P2, /* 12 */
	P2, /* 13 */
	P1, /* 14 */
	P1, /* 15 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN, /* 0,  pin count starts at 1 */
	NOT_A_PIN, /* 1,  VCC */
	BV(0),     /* 2,  port P1.0 */
	BV(1),     /* 3,  port P1.1 */
	BV(2),     /* 4,  port P1.2 */
	BV(3),     /* 5,  port P1.3*/
	BV(4),     /* 6,  port P1.4 */
	BV(5),     /* 7,  port P1.5 */
	BV(0),     /* 8,  port P2.0 */
	BV(1),     /* 9,  port P2.1 */
	BV(2),     /* 10, port P2.2 */
	BV(3),     /* 11, port P2.3 */
	BV(4),     /* 12, port P2.4 */
	BV(5),     /* 13, port P2.5 */
	BV(6),     /* 14, port P1.6 */
	BV(7),     /* 15, port P1.7 */
	NOT_A_PIN, /* 16, RST */
	NOT_A_PIN, /* 17, TEST */
	NOT_A_PIN, /* 18, XOUT */
	NOT_A_PIN, /* 19, XIN */
	NOT_A_PIN, /* 20, GND */
};
#endif
#endif
