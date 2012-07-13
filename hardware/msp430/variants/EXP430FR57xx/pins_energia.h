/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for MSP430FR5739
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *     Contribution: Stefan Sch
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

#if defined(__MSP430_HAS_EUSCI_A0__)
static const uint8_t SS      = 9;   /* P3.0 */
static const uint8_t SCK     = 12;  /* P3.3 */
static const uint8_t MOSI    = 10;  /* P3.1 */
static const uint8_t MISO    = 11;  /* P3.2 */
static const uint8_t TWISDA  = 28;  /* P1.6 */
static const uint8_t TWISCL  = 29;  /* P1.7 */
static const uint8_t UARTRXD = 22;  /* Receive  Data (RXD) at P2.1 */
static const uint8_t UARTTXD = 21;  /* Transmit Data (TXD) at P2.0 */
#define TWISDA_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISCL_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
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
//               P1.0  1|        |40  AVCC
//               P1.1  2|        |39  AVSS
//               P1.2  3|        |38  PJ.5/XOUT
//               P3.0  4|        |37  PJ.4/XIN
//               P3.1  5|        |36  AVSS
//               P3.2  6|        |35  P2.4
//               P3.3  7|        |34  P2.3
//               P1.3  8|        |33  P2.7
//               P1.4  9|        |32  DVCC
//               P1.5 10|        |31  DVSS
//               PJ.0 11|        |30  VCORE
//               PJ.1 12|        |29  P1.7
//               PJ.2 13|        |28  P1.6
//               PJ.3 14|        |27  P3.7
//               P4.0 15|        |26  P3.6
//               P4.1 16|        |25  P3.5
//               P2.5 17|        |24  P3.4
//               P2.6 18|        |23  P2.2
//               TEST 19|        |22  P2.1
//               RST  20|        |21  P2.0
//                      +--------+
//

// Pin names based on the silkscreen
//

static const uint8_t P1_0 = 1;
static const uint8_t P1_1 = 2;
static const uint8_t P1_2 = 3;
static const uint8_t P3_0 = 4;
static const uint8_t P3_1 = 5;
static const uint8_t P3_2 = 6;
static const uint8_t P3_3 = 7;
static const uint8_t P1_3 = 8;
static const uint8_t P1_4 = 9;
static const uint8_t P1_5 = 10;
static const uint8_t PJ_0 = 11;
static const uint8_t PJ_1 = 12;
static const uint8_t PJ_2 = 13;
static const uint8_t PJ_3 = 14;
static const uint8_t P4_0 = 15;
static const uint8_t P4_1 = 16;
static const uint8_t P2_5 = 17;
static const uint8_t P2_6 = 18;

static const uint8_t P2_0 = 21;
static const uint8_t P2_1 = 22;
static const uint8_t P2_2 = 23;
static const uint8_t P3_4 = 24;
static const uint8_t P3_5 = 25;
static const uint8_t P3_6 = 26;
static const uint8_t P3_7 = 27;
static const uint8_t P1_6 = 28;
static const uint8_t P1_7 = 29;

static const uint8_t P2_7 = 33;
static const uint8_t P2_3 = 34;
static const uint8_t P2_4 = 35;
static const uint8_t PJ_4 = 37;
static const uint8_t PJ_5 = 38;

static const uint8_t RED_LED = 11;
static const uint8_t GREEN_LED = 12;
static const uint8_t LED1 = 11;
static const uint8_t LED2 = 12;
static const uint8_t LED3 = 13;
static const uint8_t LED4 = 14;
static const uint8_t LED5 = 24;
static const uint8_t LED6 = 25;
static const uint8_t LED7 = 26;
static const uint8_t LED8 = 27;

static const uint8_t PUSH1 = 15;
static const uint8_t PUSH2 = 16;
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
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJIN,
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
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJOUT,
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
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJDIR,
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
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJREN,
#endif
};

const uint16_t port_to_sel0[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL0,
	(uint16_t) &P2SEL0,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL0,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL0,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL0,
#endif
};

const uint16_t port_to_sel1[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL1,
	(uint16_t) &P2SEL1,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL1,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL1,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL1,
#endif
};

/* 
 * Defines for devices with 2x TA3 timers (e.g. MSP430g2553). On the 20pin devices, upto 3 analog outputs are available
 * T0A1, T1A1 and T1A2 
 */
const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  dummy */
	T0A1,         /*  1 - P1.0  */
	T0A2,         /*  2 - P1.1 */
	T1A1,         /*  3 - P1.2 */
	NOT_ON_TIMER, /*  4 - P3.0 */
	NOT_ON_TIMER, /*  5 - P3.1 */
	NOT_ON_TIMER, /*  6 - P3.2 */
	NOT_ON_TIMER, /*  7 - P3.3 */
	T1A2,         /*  8 - P1.3 */
	T0B1,         /*  9 - P1.4 */
	T0B2,         /* 10 - P1.5 */
	NOT_ON_TIMER, /* 11 - PJ.0 */
	NOT_ON_TIMER, /* 12 - PJ.1 */
	NOT_ON_TIMER, /* 13 - PJ.2 */
	NOT_ON_TIMER, /* 14 - PJ.3 */
	T2B0,         /* 15 - P4.0 */
	NOT_ON_TIMER, /* 16 - P4.1 */  
	T0B0,         /* 17 - P2.5 */  
	T1B0,         /* 18 - P2.6 */
	NOT_ON_TIMER, /* 19 - TEST */
	NOT_ON_TIMER, /* 20 - /RST */
	T2B0,         /* 21 - P2.0 */
	T2B1,         /* 22 - P2.1 */
	T2B2,         /* 23 - P2.2 */
	T1B1,         /* 24 - P3.4 */
	T1B2,         /* 25 - P3.5 */
	T2B1,         /* 26 - P3.6 */
	T2B2,         /* 27 - P3.7 */
	T1B1,         /* 28 - P1.6 */
	T1B2,         /* 29 - P1.7 */
	NOT_ON_TIMER, /* 30 - VCORE */
	NOT_ON_TIMER, /* 31 - DVSS */
	NOT_ON_TIMER, /* 32 - DVCC */
	NOT_ON_TIMER, /* 33 - P2.7 */
	T0A0,         /* 34 - P2.3 */
	T1A0,         /* 35 - P2.4 */
	NOT_ON_TIMER, /* 36 - GND */
	NOT_ON_TIMER, /* 37 - XIN */
	NOT_ON_TIMER, /* 38 - XOUT */
	NOT_ON_TIMER, /* 39 - GND */
	NOT_ON_TIMER, /* 40 - VCC */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN, /* dummy */
	P1,          /*  1 - P1.0  */
	P1,          /*  2 - P1.1 */
	P1,          /*  3 - P1.2 */
	P3,          /*  4 - P3.0 */
	P3,          /*  5 - P3.1 */
	P3,          /*  6 - P3.2 */
	P3,          /*  7 - P3.3 */
	P1,          /*  8 - P1.3 */
	P1,          /*  9 - P1.4 */
	P1,          /* 10 - P1.5 */
	PJ,          /* 11 - PJ.0 */
	PJ,          /* 12 - PJ.1 */
	PJ,          /* 13 - PJ.2 */
	PJ,          /* 14 - PJ.3 */
	P4,          /* 15 - P4.0 */
	P4,          /* 16 - P4.1 */  
	P2,          /* 17 - P2.5 */  
	P2,          /* 18 - P2.6 */
	NOT_A_PIN,   /* 19 - TEST */
	NOT_A_PIN,   /* 20 - /RST */
	P2,          /* 21 - P2.0 */
	P2,          /* 22 - P2.1 */
	P2,          /* 23 - P2.2 */
	P3,          /* 24 - P3.4 */
	P3,          /* 25 - P3.5 */
	P3,          /* 26 - P3.6 */
	P3,          /* 27 - P3.7 */
	P1,          /* 28 - P1.6 */
	P1,          /* 29 - P1.7 */
	NOT_A_PIN,   /* 30 - VCORE */
	NOT_A_PIN,   /* 31 - DVSS */
	NOT_A_PIN,   /* 32 - DVCC */
	P2,          /* 33 - P2.7 */
	P2,          /* 34 - P2.3 */
	P2,          /* 35 - P2.4 */
	NOT_A_PIN,   /* 36 - GND */
	NOT_A_PIN,   /* 37 - XIN */
	NOT_A_PIN,   /* 38 - XOUT */
	NOT_A_PIN,   /* 39 - GND */
	NOT_A_PIN,   /* 40 - VCC */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN, /* 0,  pin count starts at 1 */
	BV(0),     /*  1 - P1.0  */
	BV(1),     /*  2 - P1.1 */
	BV(2),     /*  3 - P1.2 */
	BV(0),     /*  4 - P3.0 */
	BV(1),     /*  5 - P3.1 */
	BV(2),     /*  6 - P3.2 */
	BV(3),     /*  7 - P3.3 */
	BV(3),     /*  8 - P1.3 */
	BV(4),     /*  9 - P1.4 */
	BV(5),     /* 10 - P1.5 */
	BV(0),     /* 11 - PJ.0 */
	BV(1),     /* 12 - PJ.1 */
	BV(2),     /* 13 - PJ.2 */
	BV(3),     /* 14 - PJ.3 */
	BV(0),     /* 15 - P4.0 */
	BV(1),     /* 16 - P4.1 */  
	BV(5),     /* 17 - P2.5 */  
	BV(6),     /* 18 - P2.6 */
	NOT_A_PIN, /* 19 - TEST */
	NOT_A_PIN, /* 20 - /RST */
	BV(0),     /* 21 - P2.0 */
	BV(1),     /* 22 - P2.1 */
	BV(2),     /* 23 - P2.2 */
	BV(4),     /* 24 - P3.4 */
	BV(5),     /* 25 - P3.5 */
	BV(6),     /* 26 - P3.6 */
	BV(7),     /* 27 - P3.7 */
	BV(6),     /* 28 - P1.6 */
	BV(7),     /* 29 - P1.7 */
	NOT_A_PIN, /* 30 - VCORE */
	NOT_A_PIN, /* 31 - DVSS */
	NOT_A_PIN, /* 32 - DVCC */
	BV(7),     /* 33 - P2.7 */
	BV(3),     /* 34 - P2.3 */
	BV(4),     /* 35 - P2.4 */
	NOT_A_PIN, /* 36 - GND */
	NOT_A_PIN, /* 37 - XIN */
	NOT_A_PIN, /* 38 - XOUT */
	NOT_A_PIN, /* 39 - GND */
	NOT_A_PIN, /* 40 - VCC */
};
#endif
#endif
