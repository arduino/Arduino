/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for MSP430
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

#if defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__)
static const uint8_t SS      = 36;  /* P2.7 */
static const uint8_t SCK     = 39;  /* P3.2 */
static const uint8_t MOSI    = 37;  /* P3.0 */
static const uint8_t MISO    = 38;  /* P3.1 */
static const uint8_t TWISDA  = 37;  /* P3.0 */
static const uint8_t TWISCL  = 38;  /* P3.1 */
static const uint8_t UARTRXD = 52;  /* Receive  Data (RXD) at P4.5 */
static const uint8_t UARTTXD = 51;  /* Transmit Data (TXD) at P4.4 */
#define TWISDA_SET_MODE  (PORT_SELECTION0 | PORT_SELECTION1 /* | INPUT_PULLUP*/) /* do not enable the pull ups for this device */
#define TWISCL_SET_MODE  (PORT_SELECTION0 | PORT_SELECTION1 /* | INPUT_PULLUP*/)
#define UARTRXD_SET_MODE (PORT_SELECTION0 | PORT_SELECTION1 | INPUT)
#define UARTTXD_SET_MODE (PORT_SELECTION0 | PORT_SELECTION1 | OUTPUT)
#define SPISCK_SET_MODE (PORT_SELECTION0)
#define SPIMOSI_SET_MODE (PORT_SELECTION0)
#define SPIMISO_SET_MODE (PORT_SELECTION0)
#endif

#if defined(__MSP430_HAS_USCI_A1__)
#define USE_USCI_A1
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

//       May add Pin Mapping here
//       
//       
//       
//       
//       
//       
//       
//       
//       
//       
//       
//

// Pin names based on the silkscreen
//
static const uint8_t P1_0 = 21;
static const uint8_t P1_1 = 22;
static const uint8_t P1_2 = 23;
static const uint8_t P1_3 = 24;
static const uint8_t P1_4 = 25;
static const uint8_t P1_5 = 26;
static const uint8_t P1_6 = 27;
static const uint8_t P1_7 = 28;

static const uint8_t P2_0 = 29;
static const uint8_t P2_1 = 30;
static const uint8_t P2_2 = 31;
static const uint8_t P2_3 = 32;
static const uint8_t P2_4 = 33;
static const uint8_t P2_5 = 34;
static const uint8_t P2_7 = 35;
static const uint8_t P2_6 = 36;

static const uint8_t P3_0 = 37;
static const uint8_t P3_1 = 38;
static const uint8_t P3_2 = 39;
static const uint8_t P3_3 = 40;
static const uint8_t P3_4 = 41;
static const uint8_t P3_5 = 42;
static const uint8_t P3_7 = 43;
static const uint8_t P3_6 = 44;

static const uint8_t P4_0 = 45;
static const uint8_t P4_1 = 46;
static const uint8_t P4_2 = 47;
static const uint8_t P4_3 = 48;
static const uint8_t P4_4 = 51;
static const uint8_t P4_5 = 52;
static const uint8_t P4_6 = 53;
static const uint8_t P4_7 = 54;

static const uint8_t P6_0 = 77;
static const uint8_t P6_1 = 78;
static const uint8_t P6_2 = 79;
static const uint8_t P6_3 = 80;
static const uint8_t P6_4 = 1;
static const uint8_t P6_5 = 2;
static const uint8_t P6_7 = 3;
static const uint8_t P6_6 = 4;

static const uint8_t RED_LED = 21;
static const uint8_t GREEN_LED = 54;
static const uint8_t PUSH1 = 30;
static const uint8_t PUSH2 = 22;
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
#ifdef __MSP430_HAS_PORT5_R__
	(uint16_t) &P5IN,
#endif
#ifdef __MSP430_HAS_PORT6_R__
	(uint16_t) &P6IN,
#endif
#ifdef __MSP430_HAS_PORT7_R__
	(uint16_t) &P7IN,
#endif
#ifdef __MSP430_HAS_PORT8_R__
	(uint16_t) &P8IN,
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
#ifdef __MSP430_HAS_PORT5_R__
	(uint16_t) &P5OUT,
#endif
#ifdef __MSP430_HAS_PORT6_R__
	(uint16_t) &P6OUT,
#endif
#ifdef __MSP430_HAS_PORT7_R__
	(uint16_t) &P7OUT,
#endif
#ifdef __MSP430_HAS_PORT8_R__
	(uint16_t) &P8OUT,
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
#ifdef __MSP430_HAS_PORT5_R__
	(uint16_t) &P5DIR,
#endif
#ifdef __MSP430_HAS_PORT6_R__
	(uint16_t) &P6DIR,
#endif
#ifdef __MSP430_HAS_PORT7_R__
	(uint16_t) &P7DIR,
#endif
#ifdef __MSP430_HAS_PORT8_R__
	(uint16_t) &P8DIR,
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
#ifdef __MSP430_HAS_PORT5_R__
	(uint16_t) &P5REN,
#endif
#ifdef __MSP430_HAS_PORT6_R__
	(uint16_t) &P6REN,
#endif
#ifdef __MSP430_HAS_PORT7_R__
	(uint16_t) &P7REN,
#endif
#ifdef __MSP430_HAS_PORT8_R__
	(uint16_t) &P8REN,
#endif
};

const uint16_t port_to_sel0[] = {  /* put this PxSEL register under the group of PxSEL0 */
	NOT_A_PORT,
	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL,
#endif
#ifdef __MSP430_HAS_PORT5_R__
	(uint16_t) &P5SEL,
#endif
#ifdef __MSP430_HAS_PORT6_R__
	(uint16_t) &P6SEL,
#endif
#ifdef __MSP430_HAS_PORT7_R__
	(uint16_t) &P7SEL,
#endif
#ifdef __MSP430_HAS_PORT8_R__
	(uint16_t) &P8SEL,
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
#ifdef P4SEL2_
	(uint16_t) &P4SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P5SEL2_
	(uint16_t) &P5SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P6SEL2_
	(uint16_t) &P6SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P7SEL2_
	(uint16_t) &P7SEL2,
#else
        NOT_A_PORT,
#endif
#ifdef P8SEL2_
	(uint16_t) &P8SEL2,
#else
        NOT_A_PORT,
#endif
};

const uint16_t port_to_pmap[] = {
	NOT_A_PORT,	/* PMAP starts at port P1 */
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	(uint16_t) &P4MAP0,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
	NOT_A_PORT,
};


/* 
 * Defines for devices with 2x TA3 timers (e.g. MSP430g2553). On the 20pin devices, upto 3 analog outputs are available
 * T0A1, T1A1 and T1A2 
 */
const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  dummy */
	NOT_ON_TIMER, /*  1 - P6.4 */
	NOT_ON_TIMER, /*  2 - P6.5 */
	NOT_ON_TIMER, /*  3 - P6.6 */
	NOT_ON_TIMER, /*  4 - P6.7 */
	NOT_ON_TIMER, /*  5 - P7.0 */
	NOT_ON_TIMER, /*  6 - P7.1 */
	NOT_ON_TIMER, /*  7 - P7.2 */
	NOT_ON_TIMER, /*  8 - P7.3 */
	NOT_ON_TIMER, /*  9 - P5.0 */
	NOT_ON_TIMER, /* 10 - P5.1 */
	NOT_ON_TIMER, /* 11 - VCC */
	NOT_ON_TIMER, /* 12 - P5.4 */
	NOT_ON_TIMER, /* 13 - P5.5 */
	NOT_ON_TIMER, /* 14 - GND */
	NOT_ON_TIMER, /* 15 - P8.0 */
	NOT_ON_TIMER, /* 16 - P8.1 */
	NOT_ON_TIMER, /* 17 - P8.2 */
	NOT_ON_TIMER, /* 18 - VCC */
	NOT_ON_TIMER, /* 19 - GND */
	NOT_ON_TIMER, /* 20 - VCore */
	NOT_ON_TIMER, /* 21 - P1.0 */
	T0A0,         /* 22 - P1.1 */
	T0A1,         /* 23 - P1.2 */
	T0A2,         /* 24 - P1.3 */
	T0A3,         /* 25 - P1.4 */
	T0A4,         /* 26 - P1.5 */
	NOT_ON_TIMER, /* 27 - P1.6 */
	T1A0,         /* 28 - P1.7 */
	T1A1,         /* 29 - P2.0 */
	T1A2,         /* 30 - P2.1 */
	NOT_ON_TIMER, /* 31 - P2.2 */
	T2A0,         /* 32 - P2.3 */
	T2A1,         /* 33 - P2.4 */
	T2A2,         /* 34 - P2.5 */
	NOT_ON_TIMER, /* 35 - P2.6 */
	NOT_ON_TIMER, /* 36 - P2.7 */
	NOT_ON_TIMER, /* 37 - P3.0 */
	NOT_ON_TIMER, /* 38 - P3.1 */
	NOT_ON_TIMER, /* 39 - P3.2 */
	NOT_ON_TIMER, /* 40 - P3.3 */
	NOT_ON_TIMER, /* 41 - P3.4 */
	NOT_ON_TIMER, /* 42 - P3.5 */
	T0B5,         /* 43 - P3.6 */
	T0B6,         /* 44 - P3.7 */
	NOT_ON_TIMER, /* 45 - P4.0 */
	NOT_ON_TIMER, /* 46 - P4.1 */
	NOT_ON_TIMER, /* 47 - P4.2 */
	NOT_ON_TIMER, /* 48 - P4.3 */
	NOT_ON_TIMER, /* 49 - GND */
	NOT_ON_TIMER, /* 50 - VCC */
	NOT_ON_TIMER, /* 51 - P4.4 */
	NOT_ON_TIMER, /* 52 - P4.5 */
	NOT_ON_TIMER, /* 53 - P4.6 */
	NOT_ON_TIMER, /* 54 - P4.7 */
	T0B0,         /* 55 - P5.6 */
	T0B1,         /* 56 - P5.7 */
	T0B2,         /* 57 - P7.4 */
	T0B3,         /* 58 - P7.5 */
	T0B4,         /* 59 - P7.6 */
	NOT_ON_TIMER, /* 60 - P7.7 */
	NOT_ON_TIMER, /* 61 - USB */
	NOT_ON_TIMER, /* 62 - USB */
	NOT_ON_TIMER, /* 63 - USB */
	NOT_ON_TIMER, /* 64 - USB */
	NOT_ON_TIMER, /* 65 - USB */
	NOT_ON_TIMER, /* 66 - USB */
	NOT_ON_TIMER, /* 67 - USB */
	NOT_ON_TIMER, /* 68 - GND */
	NOT_ON_TIMER, /* 69 - XT2IN - P5.2 */
	NOT_ON_TIMER, /* 70 - XT2OUT - P5.3 */
	NOT_ON_TIMER, /* 71 - TEST */  
	NOT_ON_TIMER, /* 72 - PJ.0 */
	NOT_ON_TIMER, /* 73 - PJ.1 */
	NOT_ON_TIMER, /* 74 - PJ.2 */
	NOT_ON_TIMER, /* 75 - PJ.3 */	
	NOT_ON_TIMER, /* 76 - /RESET */
	NOT_ON_TIMER, /* 77 - P6.0 */
	NOT_ON_TIMER, /* 78 - P6.1 */
	NOT_ON_TIMER, /* 79 - P6.2 */
	NOT_ON_TIMER, /* 80 - P6.3 */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN, /* dummy */
	P6, /* 1 */
	P6, /* 2 */
	P6, /* 3 */
	P6, /* 4 */
	P7, /* 5 */
	P7, /* 6 */
	P7, /* 7 */
	P7, /* 8 */
	P5, /* 9 */
	P5, /* 10 */
	NOT_A_PIN, /* 11 */
	P5, /* 12 */
	P5, /* 13 */
	NOT_A_PIN, /* 14 */
	P8, /* 15 */
	P8, /* 16 */
	P8, /* 17 */
	NOT_A_PIN, /* 18 */
	NOT_A_PIN, /* 19 */
	NOT_A_PIN, /* 20 */
	P1, /* 21 */
	P1, /* 22 */
	P1, /* 23 */
	P1, /* 24 */
	P1, /* 25 */
	P1, /* 26 */
	P1, /* 27 */
	P1, /* 28 */
	P2, /* 29 */
	P2, /* 30 */
	P2, /* 31 */
	P2, /* 32 */
	P2, /* 33 */
	P2, /* 34 */
	P2, /* 35 */
	P2, /* 36 */
	P3, /* 37 */
	P3, /* 38 */
	P3, /* 39 */
	P3, /* 40 */
	P3, /* 41 */
	P3, /* 42 */
	P3, /* 43 */
	P3, /* 44 */
	P4, /* 45 */
	P4, /* 46 */
	P4, /* 47 */
	P4, /* 48 */
	NOT_A_PIN, /* 49 */
	NOT_A_PIN, /* 50 */
	P4, /* 51 */
	P4, /* 52 */
	P4, /* 53 */
	P4, /* 54 */
	P5, /* 55 */
	P5, /* 56 */
	P7, /* 57 */
	P7, /* 58 */
	P7, /* 59 */
	P7, /* 60 */
	NOT_A_PIN, /* 61 */
	NOT_A_PIN, /* 62 */
	NOT_A_PIN, /* 63 */
	NOT_A_PIN, /* 64 */
	NOT_A_PIN, /* 65 */
	NOT_A_PIN, /* 66 */
	NOT_A_PIN, /* 67 */
	NOT_A_PIN, /* 68 */
	P5, /* 69 */
	P5, /* 70 */
	NOT_A_PIN, /* 71 */
	PJ, /* 72 */
	PJ, /* 73 */
	PJ, /* 74 */
	PJ, /* 75 */
	NOT_A_PIN, /* 76 */
	P6, /* 77 */
	P6, /* 78 */
	P6, /* 79 */
	P6, /* 80 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN, /* 0,  pin count starts at 1 */
	BV(4),     /* 1,  port P6.4 */
	BV(5),     /* 2,  port P6.5 */
	BV(6),     /* 3,  port P6.6 */
	BV(7),     /* 4,  port P6.7 */
	BV(0),     /* 5,  port P7.0 */
	BV(1),     /* 6,  port P7.1 */
	BV(2),     /* 7,  port P7.2 */
	BV(3),     /* 8,  port P7.3 */
	BV(0),     /* 9,  XIN */
	BV(1),     /* 10, XOUT */
	NOT_A_PIN, /* 11, VCC */
	BV(4),     /* 12, port P5.4 */
	BV(5),     /* 13, port P5.5 */
	NOT_A_PIN, /* 12, GND*/
	BV(0),     /* 15, port P8.0 */
	BV(0),     /* 16, port P8.1 */
	BV(0),     /* 17, port P8.1 */
	NOT_A_PIN, /* 18, VCC */
	NOT_A_PIN, /* 19, GND */
	BV(7),     /* 20, VCORE */
	BV(0),     /* 21, port P1.0 */
	BV(1),     /* 22, port P1.1 */
	BV(2),     /* 23, port P1.2 */
	BV(3),     /* 24, port P1.3 */
	BV(4),     /* 25, port P1.4 */
	BV(5),     /* 26, port P1.5 */
	BV(6),     /* 27, port P1.6 */
	BV(7),     /* 28, port P1.7 */
	BV(0),     /* 29, port P2.0 */
	BV(1),     /* 30, port P2.1 */
	BV(2),     /* 31, port P2.2 */
	BV(3),     /* 32, port P2.3 */
	BV(4),     /* 33, port P2.4 */
	BV(5),     /* 34, port P2.5 */
	BV(6),     /* 35, port P2.6 */
	BV(7),     /* 36, port P2.7 */
	BV(0),     /* 37, port P3.0 */
	BV(1),     /* 38, port P3.1 */
	BV(2),     /* 39, port P3.2 */
	BV(3),     /* 40, port P3.3 */
	BV(4),     /* 41, port P3.4 */
	BV(5),     /* 42, port P3.5 */
	BV(6),     /* 43, port P3.6 */
	BV(7),     /* 44, port P3.7 */
	BV(0),     /* 45, port P4.0 */
	BV(1),     /* 46, port P4.1 */
	BV(2),     /* 47, port P4.2 */
	BV(3),     /* 48, port P4.3 */
	NOT_A_PIN, /* 49, GND */
	NOT_A_PIN, /* 50, VCC */
	BV(4),     /* 51, port P4.4 */
	BV(5),     /* 52, port P4.5 */
	BV(6),     /* 53, port P4.6 */
	BV(7),     /* 54, port P4.7 */
	BV(6),     /* 55, port P5.6 */
	BV(7),     /* 56, port P5.7 */
	BV(4),     /* 57, port P7.4 */
	BV(5),     /* 58, port P7.5 */
	BV(6),     /* 59, port P7.6 */
	BV(7),     /* 60, port P7.7 */
	NOT_A_PIN, /* 61, USB */
	NOT_A_PIN, /* 62, USB */
	NOT_A_PIN, /* 63, USB */
	NOT_A_PIN, /* 64, USB */
	NOT_A_PIN, /* 65, USB */
	NOT_A_PIN, /* 66, USB */
	NOT_A_PIN, /* 67, USB */
	NOT_A_PIN, /* 68, GND */
	BV(2),     /* 69, port P5.2 */
	BV(3),     /* 70, port P5.3 */
	NOT_A_PIN, /* 71, TEST */
	BV(0),     /* 72, port PJ.0 */
	BV(1),     /* 73, port PJ.1 */
	BV(2),     /* 74, port PJ.2 */
	BV(3),     /* 75, port PJ.3 */
	NOT_A_PIN, /* 76, RST */
	BV(0),     /* 77, port P6.0 */
	BV(1),     /* 78, port P6.1 */
	BV(2),     /* 79, port P6.2 */
	BV(3),     /* 80, port P6.3 */
};
#endif // #ifdef ARDUINO_MAIN
#endif // #ifndef Pins_Arduino_h
