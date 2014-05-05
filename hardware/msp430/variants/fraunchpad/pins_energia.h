/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Pin definition functions for FraunchPad
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

#ifndef Pins_Energia_h
#define Pins_Energia_h
#ifndef BV
#define BV(x) (1 << (x))
#endif

#if defined(__MSP430_HAS_EUSCI_B0__)
static const uint8_t SS      = 20;  /* P1.3 */
static const uint8_t SCK     = 6;   /* P2.2 */
static const uint8_t MOSI    = 11;  /* P1.6 aka SIMO */
static const uint8_t MISO    = 12;  /* P1.7 aka SOMI */
static const uint8_t TWISDA  = 11;  /* P1.6 */
static const uint8_t TWISCL  = 12;  /* P1.7 */
#define TWISDA_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISCL_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#endif

#if defined(__MSP430_HAS_EUSCI_A0__)
static const uint8_t DEBUG_UARTRXD = 5;  /* Receive  Data (RXD) at P2.1 */
static const uint8_t DEBUG_UARTTXD = 2;  /* Transmit Data (TXD) at P2.0 */
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define DEBUG_UART_MODULE_OFFSET 0x00
#endif

/* Analog pins */
/* Note: the Ax assignment is according to energia.nu/Guide_MSP430FraunchPad.html 
   pin map, not the MSP430FR5739 device Analog channels (also named Ax) */

static const uint8_t A0  = 22;  /* 22 - P1.5 */
static const uint8_t A1  = 21;  /* 21 - P1.4 */
static const uint8_t A2  = 20;  /* 20 - P1.3 */
static const uint8_t A3  = 19; /* 19 - P3.3 */
static const uint8_t A4  = 18; /* 18 - P3.2 */
static const uint8_t A5  = 17; /* 17 - P3.1 */
static const uint8_t A6  = 16; /* 16 - P3.0 */
static const uint8_t A7  = 15;  /* 15 - P1.2 */
static const uint8_t A8  = 14;  /* 14 - P1.1 */
static const uint8_t A9  = 13;  /* 13 - P1.0 */
static const uint8_t A10 = 128 + 10; //Special this is device's internal temp sensor */
static const uint8_t A11 = 128 + 11; //Special this is Vcc/2 */

/* 3-axes accelerometer pins */
static const uint8_t ACC_X  = 12; /* (A6) 16 - P3.0 */
static const uint8_t ACC_Y  = 13; /* (A5) 17 - P3.1 */
static const uint8_t ACC_Z  = 14; /* (A4) 18 - P3.0 */
static const uint8_t ACC_ENABLE = 30; /* 30 - P2.7 */
static const uint8_t NTC_ENABLE = 30; /* 30 - P2.7 */

/* Layout of the 2x 12 pin headers.
   Header is _not_ compatible with LaunchPad!

   All pins support digitalWrite() and attachInterrupt()
   Pins marked with PWM support anaglogWrite()
   Pins marked with Ax support analogRead()

                                          +---\/---+
                                   VCC   1|        |24  GND
                   (UARTTX)        P2.0  2|        |23  P4.0
                                   P2.5  3|        |22  P1.5        (A0) (PWM)
                                   P2.6  4|        |21  P1.4        (A1) (PWM)
(PWM)              (UARTRX)        P2.1  5|        |20  P1.3  (SS)  (A2) (PWM)
(PWM)        (SCK)                 P2.2  6|        |19  P3.3        (A3)
(PWM)                      (LED5)  P3.4  7|        |18  P3.2        (A4)
(PWM)                      (LED6)  P3.5  8|        |17  P3.1        (A5)
(PWM)                      (LED7)  P3.6  9|        |16  P3.0        (A6)
(PWM)                      (LED8)  P3.7 10|        |15  P1.2        (A7) (PWM)
(PWM) (SDA) (MOSI)                 P1.6 11|        |14  P1.1        (A8) (PWM)
(PWM) (SCL) (MISO)                 P1.7 12|        |13  P1.0        (A9) (PWM)
                                          +--------+

                                               ----+
                                                   |25  LED1
                                                   |26  LED2
                     Extra LED's and S2 aka PUSH2  |27  LED3
                                                   |28  LED4
                                                   |29  PUSH2
                                               ----+
*/

// Pin names based on the silkscreen
//

static const uint8_t P2_0 = 2;
static const uint8_t P2_5 = 3;
static const uint8_t P2_6 = 4;
static const uint8_t P2_1 = 5;
static const uint8_t P2_2 = 6;
static const uint8_t P3_4 = 7;
static const uint8_t P3_5 = 8;
static const uint8_t P3_6 = 9;
static const uint8_t P3_7 = 10;
static const uint8_t P1_6 = 11;
static const uint8_t P1_7 = 12;
static const uint8_t P1_0 = 13;
static const uint8_t P1_1 = 14;
static const uint8_t P1_2 = 15;
static const uint8_t P3_0 = 16;
static const uint8_t P3_1 = 17;
static const uint8_t P3_2 = 18;
static const uint8_t P3_3 = 19;
static const uint8_t P1_3 = 20;
static const uint8_t P1_4 = 21;
static const uint8_t P1_5 = 22;
static const uint8_t P4_0 = 23;

static const uint8_t LED1 = 25;
static const uint8_t LED2 = 26;
static const uint8_t LED3 = 27;
static const uint8_t LED4 = 28;
static const uint8_t LED5 = 7;
static const uint8_t LED6 = 8;
static const uint8_t LED7 = 9;
static const uint8_t LED8 = 10;
/* For LaunchPad compatability */
static const uint8_t RED_LED = 25;
static const uint8_t GREEN_LED = 28;

static const uint8_t PUSH1 = 23;
static const uint8_t PUSH2 = 29;
static const uint8_t TEMPSENSOR = 128 + 10;

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

const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER,  /*  0 - pin count starts at 1 */
	NOT_ON_TIMER,  /*  1 - VCC */
	T2B0,          /*  2 - P2.0 */
	T0B0,          /*  3 - P2.5 */
	T1B0,          /*  4 - P2.6 */
	T2B1,          /*  5 - P2.1 */
	T2B2,          /*  6 - P2.2 */
	T1B1,          /*  7 - P3.4 */
	T1B2,          /*  8 - P3.5 */
	T2B1,          /*  9 - P3.6 */
	T2B2,          /* 10 - P3.7 */
	T1B1,          /* 11 - P1.6 */
	T1B2,          /* 12 - P1.7 */
	T0A1,          /* 13 - P1.0 */
	T0A2,          /* 14 - P1.1 */
	T1A1,          /* 15 - P1.2 */
	NOT_ON_TIMER,  /* 16 - P3.0 */
	NOT_ON_TIMER,  /* 17 - P3.1 */
	NOT_ON_TIMER,  /* 18 - P3.2 */
	NOT_ON_TIMER,  /* 19 - P3.3 */
	T1A2,          /* 20 - P1.3 */
	T0B1,          /* 21 - P1.4 */
	T0B2,          /* 22 - P1.5 */
	T2B0,          /* 23 - P4.0 */
	NOT_ON_TIMER,  /* 24 - GND  */
	/* LED's */
	NOT_ON_TIMER,  /* 25 PJ.0 - LED1 */
	NOT_ON_TIMER,  /* 26 PJ.1 - LED2 */
	NOT_ON_TIMER,  /* 27 PJ.2 - LED3 */
	NOT_ON_TIMER,  /* 28 PJ.3 - LED4 */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN,   /*  0 - pin count starts at 1 */
	NOT_A_PIN,   /*  1 - VCC */
	P2,          /*  2 - P2.0 */
	P2,          /*  3 - P2.5 */
	P2,          /*  4 - P2.6 */
	P2,          /*  5 - P2.1 */
	P2,          /*  6 - P2.2 */
	P3,          /*  7 - P3.4 */
	P3,          /*  8 - P3.5 */
	P3,          /*  9 - P3.6 */
	P3,          /* 10 - P3.7 */
	P1,          /* 11 - P1.6 */
	P1,          /* 12 - P1.7 */
	P1,          /* 13 - P1.0 */
	P1,          /* 14 - P1.1 */
	P1,          /* 15 - P1.2 */
	P3,          /* 16 - P3.0 */
	P3,          /* 17 - P3.1 */
	P3,          /* 18 - P3.2 */
	P3,          /* 19 - P3.3 */
	P1,          /* 20 - P1.3 */
	P1,          /* 21 - P1.4 */
	P1,          /* 22 - P1.5 */
	P4,          /* 23 - P4.0 */
	NOT_A_PIN,   /* 24 - GND */
	/* LED's */
	PJ,          /* 25 PJ.0 - LED1 */
	PJ,          /* 26 PJ.1 - LED2 */
	PJ,          /* 27 PJ.2 - LED3 */
	PJ,          /* 28 PJ.3 - LED4 */
	P4,          /* 29 P4.1 - PUSH2 */
	P2,          /* 30 P2.7 - ACC_ENABLE / NTC_ENABLE */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN,   /*  0 - pin count starts at 1 */
	NOT_A_PIN,   /*  1 - VCC */
	BV(0),       /*  2 - P2.0 */
	BV(5),       /*  3 - P2.5 */
	BV(6),       /*  4 - P2.6 */
	BV(1),       /*  5 - P2.1 */
	BV(2),       /*  6 - P2.2 */
	BV(4),       /*  7 - P3.4 */
	BV(5),       /*  8 - P3.5 */
	BV(6),       /*  9 - P3.6 */
	BV(7),       /* 10 - P3.7 */
	BV(6),       /* 11 - P1.6 */
	BV(7),       /* 12 - P1.7 */
	BV(0),       /* 13 - P1.0 */
	BV(1),       /* 14 - P1.1 */
	BV(2),       /* 15 - P1.2 */
	BV(0),       /* 16 - P3.0 */
	BV(1),       /* 17 - P3.1 */
	BV(2),       /* 18 - P3.2 */
	BV(3),       /* 19 - P3.3 */
	BV(3),       /* 20 - P1.3 */
	BV(4),       /* 21 - P1.4 */
	BV(5),       /* 22 - P1.5 */
	BV(0),       /* 23 - P4.0 */
	NOT_A_PIN,   /* 24 - GND  */
	/* LED's 1 through 8 */
	BV(0),       /* 25 - PJ.0 - LED1 */
	BV(1),       /* 26 - PJ.1 - LED2 */
	BV(2),       /* 27 - PJ.2 - LED3 */
	BV(3),       /* 28 - PJ.3 - LED4 */
	BV(1),       /* 29 - P4.1 - PUSH2 */
	BV(7),       /* 30 - P2.7 - ACC_ENABLE / NTC_ENABLE */

};

const uint32_t digital_pin_to_analog_in[] = {
        NOT_ON_ADC,     /*  dummy   */
        NOT_ON_ADC,     /*  1 - 3.3V*/
        NOT_ON_ADC,		/*  2 - P2.0 */
        NOT_ON_ADC,		/*  3 - P2.5 */
        NOT_ON_ADC,		/*  4 - P2.6 */
        NOT_ON_ADC, 	/*  5 - P2.1 */
        NOT_ON_ADC,		/*  6 - P2.2 */
        NOT_ON_ADC,		/*  7 - P3.4 */
        NOT_ON_ADC, 	/*  8 - P3.5 */
        NOT_ON_ADC, 	/*  9 - P3.6 */
        NOT_ON_ADC, 	/*  10 - P3.7 */
        NOT_ON_ADC, 	/*  11 - P1.6 */
        NOT_ON_ADC, 	/*  12 - P1.7 */
        0,     			/*  13 - A9 (device analog channel 0) */
        1,     			/*  14 - A8 (device analog channel 1) */
        2, 				/*  15 - A7 (device analog channel 2) */
        12,     		/*  16 - A6 (device analog channel 12) */
        13, 			/*  17 - A5 (device analog channel 13) */
        14, 			/*  18 - A4 (device analog channel 14) */
        15, 			/*  19 - A3 (device analog channel 15) */
        3, 				/*  20 - A2 (device analog channel 3) */
        4,  			/*  21 - A1 (device analog channel 4) */
        5,  			/*  22 - A0 (device analog channel 5) */	
		NOT_ON_ADC,		/*  23 - P4.0 */
		NOT_ON_ADC		/*  24 - NC */
};
#endif
#endif
