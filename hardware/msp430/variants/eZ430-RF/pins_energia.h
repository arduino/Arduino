/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for MSP430F2274
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: StefanSch
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

#if defined(__MSP430_HAS_USCI__)
static const uint8_t SS      = 9;   /* P3.0 */
static const uint8_t SCK     = 12;  /* P3.3 */
static const uint8_t MOSI    = 10;  /* P3.1 */
static const uint8_t MISO    = 11;  /* P3.2 */
static const uint8_t TWISDA  = 10;  /* P3.1 */
static const uint8_t TWISCL  = 11;  /* P3.2 */
static const uint8_t UARTRXD = 24;  /* Receive  Data (RXD) at P3.5 */
static const uint8_t UARTTXD = 23;  /* Transmit Data (TXD) at P3.4 */
#define TWISDA_SET_MODE  (PORT_SELECTION0 | INPUT_PULLUP)
#define TWISCL_SET_MODE  (PORT_SELECTION0 | INPUT_PULLUP)
#define UARTRXD_SET_MODE (PORT_SELECTION0 | INPUT)
#define UARTTXD_SET_MODE (PORT_SELECTION0 | OUTPUT)
#endif

static const uint8_t A0  = 0;
static const uint8_t A1  = 1;
static const uint8_t A2  = 2;
static const uint8_t A3  = 3;
static const uint8_t A4  = 4;
static const uint8_t A5  = 5;
static const uint8_t A6  = 6;
static const uint8_t A7  = 7;
static const uint8_t A10 = 10; // special. This is the internal temp sensor
static const uint8_t A11 = 11; // 
static const uint8_t A12 = 12; // 
static const uint8_t A13 = 13; // 
static const uint8_t A14 = 14; // 
static const uint8_t A15 = 15; // 

//                      +---\/---+
//               GND   1|        |40  P2.5
//           XOUT/P2.7 2|        |39  DVCC
//            XIN/P2.6 3|        |38  DVCC
//               DVSS  4|        |37  TEST
//               RST#  5|        |36  P1.7
//       (A0)    P2.0  6|        |35  P1.6
//       (A1)    P2.1  7|        |34  P1.5
//       (A2)    P2.2  8|        |33  P1.4
//       (A5)    P3.0  9|        |32  P1.3
//               P3.1 10|        |31  P1.2
//               P3.2 11|        |30  P1.1
//               P3.3 12|        |29  P1.0
//               AVSS 13|        |28  P2.4    (A4)
//               AVCC 14|        |27  P2.3    (A3)
//               P4.0 15|        |26  P3.7
//               P4.1 16|        |25  P3.6
//               P4.2 17|        |24  P3.5
//       (A12)   P4.3 18|        |23  P3.4
//       (A13)   P4.4 19|        |22  P4.7
//       (A14)   P4.5 20|        |21  P4.6    (A15)
//                      +--------+
//

// Pin names based on the silkscreen
//

static const uint8_t P2_7 = 2;
static const uint8_t P2_6 = 3;
static const uint8_t P2_0 = 6;
static const uint8_t P2_1 = 7;
static const uint8_t P2_2 = 8;
static const uint8_t P3_0 = 9;
static const uint8_t P3_1 = 10;
static const uint8_t P3_2 = 11;
static const uint8_t P3_3 = 12;
static const uint8_t P4_0 = 15;
static const uint8_t P4_1 = 16;
static const uint8_t P4_2 = 17;
static const uint8_t P4_3 = 18;
static const uint8_t P4_4 = 19;
static const uint8_t P4_5 = 20;
static const uint8_t P4_6 = 21;
static const uint8_t P4_7 = 22;
static const uint8_t P3_4 = 23;
static const uint8_t P3_5 = 24;
static const uint8_t P3_6 = 25;
static const uint8_t P3_7 = 26;
static const uint8_t P2_3 = 27;
static const uint8_t P2_4 = 28;
static const uint8_t P1_0 = 29;
static const uint8_t P1_1 = 30;
static const uint8_t P1_2 = 31;
static const uint8_t P1_3 = 32;
static const uint8_t P1_4 = 33;
static const uint8_t P1_5 = 34;
static const uint8_t P1_6 = 35;
static const uint8_t P1_7 = 36;
static const uint8_t P2_5 = 40;

static const uint8_t RED_LED = 29;
static const uint8_t GREEN_LED = 30;
static const uint8_t PUSH2 = 31;
static const uint8_t TEMPSENSOR = 10; // depends on chip


#ifdef ARDUINO_MAIN

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3IN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4IN,
#endif
};

const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3OUT,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4OUT,
#endif
};

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3DIR,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4DIR,
#endif
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3REN,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4REN,
#endif
};

/* 
 * We either of the compination   PxSEL and PxSEL2   or   PxSEL0 and PxSEL1
 * So we can remap  PxSEL and PxSEL2   to   PxSEL0 and PxSEL1
*/ 
const uint16_t port_to_sel0[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL,
#endif
};


/* 
 * Defines for devices with 2x TA3 timers (e.g. MSP430g2553). On the 20pin devices, upto 3 analog outputs are available
 * T0A1, T1A1 and T1A2 
 */
const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  dummy */
	NOT_ON_TIMER, /*  1 - GND */
	NOT_ON_TIMER, /*  2 - XOUT - P2.7 */
	NOT_ON_TIMER, /*  3 - XIN - P2.6: */
	NOT_ON_TIMER, /*  4 - GND */
	NOT_ON_TIMER, /*  5 - /RESET */  
	NOT_ON_TIMER, /*  6 - P2.0 */
	NOT_ON_TIMER, /*  7 - P2.1 */
	T0A0,         /*  8 - P2.2 */
	NOT_ON_TIMER, /*  9 - P3.0 */
	NOT_ON_TIMER, /* 10 - P3.1 */
	NOT_ON_TIMER, /* 11 - P3.2 */
	NOT_ON_TIMER, /* 12 - P3.3 */
	NOT_ON_TIMER, /* 13 - AVSS */
	NOT_ON_TIMER, /* 14 - AVCC */
	T0B0,         /* 15 - P4.0 */
	T0B1,         /* 16 - P4.1 */
	T0B2,         /* 17 - P4.2 */
	T0B0,         /* 18 - P4.3 */
	T0B1,         /* 19 - P4.4 */
	T0B2,         /* 20 - P4.5 */
	NOT_ON_TIMER, /* 21 - P4.6 */
	NOT_ON_TIMER, /* 22 - P4.7 */
	NOT_ON_TIMER, /* 23 - P3.4 */
	NOT_ON_TIMER, /* 24 - P3.5 */
	NOT_ON_TIMER, /* 25 - P3.6 */
	NOT_ON_TIMER, /* 26 - P3.7 */
	NOT_ON_TIMER, /* 27 - P2.3 */
	NOT_ON_TIMER, /* 28 - P2.4 */
	NOT_ON_TIMER, /* 29 - P1.0 */
	T0A0,         /* 30 - P1.1 */
	T0A1,         /* 31 - P1.2 */
	T0A2,         /* 32 - P1.3 */
	NOT_ON_TIMER, /* 33 - P1.4 */
	T0A0,         /* 34 - P1.5 */
	T0A1,         /* 35 - P1.6 */
	T0A2,         /* 36 - P1.7 */
	NOT_ON_TIMER, /* 37 - TEST */
	NOT_ON_TIMER, /* 38 - DVCC */
	NOT_ON_TIMER, /* 39 - DVSS */
	NOT_ON_TIMER, /* 40 - P2.5 */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN, /* dummy */
	NOT_A_PIN, /*  1 - GND */
	NOT_A_PIN, /*  2 - XOUT - P2.7 */
	NOT_A_PIN, /*  3 - XIN - P2.6: */
	NOT_A_PIN, /*  4 - GND */
	NOT_A_PIN, /*  5 - /RESET */  
	P2,        /*  6 - P2.0 */
	P2,        /*  7 - P2.1 */
	P2,        /*  8 - P2.2 */
	P3,        /*  9 - P3.0 */
	P3,        /* 10 - P3.1 */
	P3,        /* 11 - P3.2 */
	P3,        /* 12 - P3.3 */
	NOT_A_PIN, /* 13 - AVSS */
	NOT_A_PIN, /* 14 - AVCC */
	P4,        /* 15 - P4.0 */
	P4,        /* 16 - P4.1 */
	P4,        /* 17 - P4.2 */
	P4,        /* 18 - P4.3 */
	P4,        /* 19 - P4.4 */
	P4,        /* 20 - P4.5 */
	P4,        /* 21 - P4.6 */
	P4,        /* 22 - P4.7 */
	P3,        /* 23 - P3.4 */
	P3,        /* 24 - P3.5 */
	P3,        /* 25 - P3.6 */
	P3,        /* 26 - P3.7 */
	P2,        /* 27 - P2.3 */
	P2,        /* 28 - P2.4 */
	P1,        /* 29 - P1.0 */
	P1,        /* 30 - P1.1 */
	P1,        /* 31 - P1.2 */
	P1,        /* 32 - P1.3 */
	P1,        /* 33 - P1.4 */
	P1,        /* 34 - P1.5 */
	P1,        /* 35 - P1.6 */
	P1,        /* 36 - P1.7 */
	NOT_A_PIN, /* 37 - TEST */
	NOT_A_PIN, /* 38 - DVCC */
	NOT_A_PIN, /* 39 - DVSS */
	P2,        /* 40 - P2.5 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN, /* 0,  pin count starts at 1 */
	NOT_A_PIN, /*  1 - GND */
	NOT_A_PIN, /*  2 - XOUT - P2.7 */
	NOT_A_PIN, /*  3 - XIN - P2.6: */
	NOT_A_PIN, /*  4 - GND */
	NOT_A_PIN, /*  5 - /RESET */  
	BV(0),     /*  6 - P2.0 */
	BV(1),     /*  7 - P2.1 */
	BV(2),     /*  8 - P2.2 */
	BV(0),     /*  9 - P3.0 */
	BV(1),     /* 10 - P3.1 */
	BV(2),     /* 11 - P3.2 */
	BV(3),     /* 12 - P3.3 */
	NOT_A_PIN, /* 13 - AVSS */
	NOT_A_PIN, /* 14 - AVCC */
	BV(0),     /* 15 - P4.0 */
	BV(1),     /* 16 - P4.1 */
	BV(2),     /* 17 - P4.2 */
	BV(3),     /* 18 - P4.3 */
	BV(4),     /* 19 - P4.4 */
	BV(5),     /* 20 - P4.5 */
	BV(6),     /* 21 - P4.6 */
	BV(7),     /* 22 - P4.7 */
	BV(4),     /* 23 - P3.4 */
	BV(5),     /* 24 - P3.5 */
	BV(6),     /* 25 - P3.6 */
	BV(7),     /* 26 - P3.7 */
	BV(3),     /* 27 - P2.3 */
	BV(4),     /* 28 - P2.4 */
	BV(0),     /* 29 - P1.0 */
	BV(1),     /* 30 - P1.1 */
	BV(2),     /* 31 - P1.2 */
	BV(3),     /* 32 - P1.3 */
	BV(4),     /* 33 - P1.4 */
	BV(5),     /* 34 - P1.5 */
	BV(6),     /* 35 - P1.6 */
	BV(7),     /* 36 - P1.7 */
	NOT_A_PIN, /* 37 - TEST */
	NOT_A_PIN, /* 38 - DVCC */
	NOT_A_PIN, /* 39 - DVSS */
	BV(5),     /* 40 - P2.5 */
};
#endif
#endif
