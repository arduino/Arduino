/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Pin definition functions for LaunchPad w/ msp430fr5969
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
static const uint8_t SS      = 8;   /* P3.4 */
static const uint8_t SCK     = 7;   /* P2.2 */
static const uint8_t MOSI    = 15;  /* P1.6 aka SIMO */
static const uint8_t MISO    = 14;  /* P1.7 aka SOMI */
static const uint8_t TWISCL1  = 9;   /* P3.5 SW I2C */
static const uint8_t TWISDA1  = 10;  /* P3.6 SW I2C */
static const uint8_t TWISDA0  = 15;  /* P1.6 UCB0 */
static const uint8_t TWISCL0  = 14;  /* P1.7 UCB0 */
#define TWISDA0_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISCL0_SET_MODE  (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISDA1_SET_MODE  (INPUT_PULLUP)
#define TWISCL1_SET_MODE  (INPUT_PULLUP)
#define SPISCK_SET_MODE  (PORT_SELECTION1)
#define SPIMOSI_SET_MODE (PORT_SELECTION1)
#define SPIMISO_SET_MODE (PORT_SELECTION1)
/* Define the default I2C settings */
#define DEFAULT_I2C -1 /* indicates SW I2C on pseudo module 1 */
#define TWISDA TWISDA1
#define TWISCL TWISCL1
#define TWISDA_SET_MODE  TWISDA1_SET_MODE
#define TWISCL_SET_MODE  TWISCL1_SET_MODE
#endif

#if defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_EUSCI_A1__)
static const uint8_t DEBUG_UARTRXD = 22;  /* Receive  Data (RXD) at P2.1 */
static const uint8_t DEBUG_UARTTXD = 21;  /* Transmit Data (TXD) at P2.0 */
static const uint8_t AUX_UARTRXD = 3;     /* Receive  Data (RXD) at P4.5 */
static const uint8_t AUX_UARTTXD = 4;     /* Transmit Data (TXD) at P4.4 */
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define AUX_UARTRXD_SET_MODE (PORT_SELECTION1 | INPUT)
#define AUX_UARTTXD_SET_MODE (PORT_SELECTION1 | OUTPUT)
#define DEBUG_UART_MODULE_OFFSET 0x00
#define AUX_UART_MODULE_OFFSET 0x20
#define SERIAL1_AVAILABLE 1
#endif


/* Analog pins */

static const uint8_t A0  = 128 + 0; // Not available on BoosterPack header
static const uint8_t A1  = 128 + 1; // Not available on BoosterPack header
static const uint8_t A2  = 19;
static const uint8_t A3  = 11;
static const uint8_t A4  = 12;
static const uint8_t A5  = 13;
static const uint8_t A6  = 128 + 6; // Not available on BoosterPack header
static const uint8_t A7  = 128 + 7; // Not available on BoosterPack header
static const uint8_t A8  = 23; // Available, but not on the 20-pin BP header
static const uint8_t A9  = 24; // Available, but not on the 20-pin BP header
static const uint8_t A10 = 128 + 10;
static const uint8_t A11  = 5;
static const uint8_t A12  = 18; 
static const uint8_t A13  = 128 + 13;  // Not available on BoosterPack header
static const uint8_t A14  = 128 + 14; // Not available on BoosterPack header
static const uint8_t A15  = 128 + 15; // Not available on BoosterPack header

//-------------------------------------------

/* Layout of the 2 - 10 pin headers.

   All pins support digitalWrite() and attachInterrupt()
   Pins marked with PWM support anaglogWrite()
   Pins marked with Ax support analogRead()

                                          +---\/---+
                                   VCC0  1|        |20  GND
                            (A10)  P4.2  2|        |19  P1.2            (A2) (PWM)
(PWM) (UCA1RXD -> Serial1)         P2.6  3|        |18  P3.0            (A12)(PWM)
(PWM) (UCA1TXD -> Serial1)         P2.5  4|        |17  TEST
                            (A11)  P4.3  5|        |16  RST
(PWM)                              P2.4  6|        |15  P1.6 (SDA) (MOSI)    (PWM)
(PWM)                              P2.2  7|        |14  P1.7 (SCL) (MISO)    (PWM)
(PWM)                              P3.4  8|        |13  P1.5            (A5) (PWM)
(PWM)                              P3.5  9|        |12  P1.4            (A4) (PWM)
(PWM)                              P3.6 10|        |11  P1.3            (A3) (PWM)
                                          +--------+


                                               ----+
                                                   |21  DebugUART TX  (P2.0) (PWM)
                     J13 eZ-FET Connector          |22  DebugUART RX  (P2.1) (PWM)
                                                   |23  DebugUART CTS (P4.0) (A8)
                                                   |24  DebugUART RTS (P4.1) (A9)
                                               ----+
                                               ----+
                                                   |25  LED1       (P4.6)
                     Extra LED's and Switches      |26  LED2       (P1.0)
                                                   |27  PUSH1      (P4.5)
                                                   |28  PUSH2      (P1.1)
                                               ----+
                                               ----+
                                                   |29  TDO        (PJ.0)
                     JTAG Connector J3             |30  TDI        (PJ.1)
                                                   |31  TMS        (PJ.2)
                                                   |32  TCK        (PJ.3)
                                               ----+
*/

// Pin names based on the silkscreen
//

static const uint8_t P1_0 = 26;
static const uint8_t P1_1 = 28;
static const uint8_t P1_2 = 19;
static const uint8_t P1_3 = 11;
static const uint8_t P1_4 = 12;
static const uint8_t P1_5 = 13;
static const uint8_t P1_6 = 15;
static const uint8_t P1_7 = 14;

static const uint8_t P2_0 = 21;
static const uint8_t P2_1 = 22;
static const uint8_t P2_2 = 7;
//static const uint8_t P2_3 = ;
static const uint8_t P2_4 = 6;
static const uint8_t P2_5 = 4;
static const uint8_t P2_6 = 3;
//static const uint8_t P2_7 = ;

static const uint8_t P3_0 = 18;
//static const uint8_t P3_1 = ;
//static const uint8_t P3_2 = ;
//static const uint8_t P3_3 = ;
static const uint8_t P3_4 = 8;
static const uint8_t P3_5 = 9;
static const uint8_t P3_6 = 10;
//static const uint8_t P3_7 = ;

static const uint8_t P4_0 = 23;
static const uint8_t P4_1 = 24;
static const uint8_t P4_2 = 2;
static const uint8_t P4_3 = 5;
//static const uint8_t P4_4 = ;
static const uint8_t P4_5 = 27;
static const uint8_t P4_6 = 25;
//static const uint8_t P4_7 = ;

static const uint8_t PJ_0 = 29;
static const uint8_t PJ_1 = 30;
static const uint8_t PJ_2 = 31;
static const uint8_t PJ_3 = 32;
//static const uint8_t PJ_4 = ;
//static const uint8_t PJ_5 = ;
//static const uint8_t PJ_6 = ;
//static const uint8_t PJ_7 = ;


static const uint8_t LED1 = 25;
static const uint8_t LED2 = 26;
/* For LaunchPad compatability */
static const uint8_t RED_LED = 25;
static const uint8_t GREEN_LED = 26;

static const uint8_t PUSH1 = 27;
static const uint8_t PUSH2 = 28;
static const uint8_t TEMPSENSOR = 128 + 30; // depends on chip

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
	NOT_ON_TIMER,  /*  1 - Vcc */
	NOT_ON_TIMER,  /*  2 - P4.2 */
	T0B1,          /*  3 - P2.6 */
	NOT_ON_TIMER,  /*  4 - P2.5  - note: CCR0 output cannot be used with analogWrite */
	NOT_ON_TIMER,  /*  5 - P4.3 */
	NOT_ON_TIMER,  /*  6 - P2.4  - note: CCR0 output cannot be used with analogWrite */
	T0A2,          /*  7 - P2.2 */
	T0B3,          /*  8 - P3.4 */
	T0B4,          /*  9 - P3.5 */
	T0B5,          /* 10 - P3.6 */
	T1A2,          /* 11 - P1.3 */
	T0B1,          /* 12 - P1.4 */
	T0B2,          /* 13 - P1.5 */
	T0B4,          /* 14 - P1.7 */
	T0B3,          /* 15 - P1.6 */
	NOT_ON_TIMER,  /* 16 - RST */
	NOT_ON_TIMER,  /* 17 - TEST */
	NOT_ON_TIMER,  /* 18 - P3.0 */
	T1A1,          /* 19 - P1.2 */
	NOT_ON_TIMER,  /* 20 - GND */
	
	T0B6,          /* 21 - P2.0 */
	T0B0,          /* 22 - P2.1 */
	NOT_ON_TIMER,  /* 23 - P4.0 */
	NOT_ON_TIMER,  /* 24 - P4.1 */
	
	NOT_ON_TIMER,  /* 25 - P4.6 */
	T0A1,          /* 26 - P1.0 */
	NOT_ON_TIMER,  /* 27 - P4.5 */
	T0A2,          /* 28 - P1.1 */
	
	NOT_ON_TIMER,  /* 29 - PJ.0 */
	NOT_ON_TIMER,  /* 30 - PJ.1 */
	NOT_ON_TIMER,  /* 31 - PJ.2 */
	NOT_ON_TIMER,  /* 32 - PJ.3 */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN,   /*  0 - pin count starts at 1 */
	NOT_A_PIN,   /*  1 - Vcc */
	P4,          /*  2 - P4.2 */
	P2,          /*  3 - P2.6 */
	P2,          /*  4 - P2.5 */
	P4,          /*  5 - P4.3 */
	P2,          /*  6 - P2.4 */
	P2,          /*  7 - P2.2 */
	P3,          /*  8 - P3.4 */
	P3,          /*  9 - P3.5 */
	P3,          /* 10 - P3.6 */
	P1,          /* 11 - P1.3 */
	P1,          /* 12 - P1.4 */
	P1,          /* 13 - P1.5 */
	P1,          /* 14 - P1.7 */
	P1,          /* 15 - P1.6 */
	NOT_A_PIN,   /* 16 - RST */
	NOT_A_PIN,   /* 17 - TEST */
	P3,          /* 18 - P3.0 */
	P1,          /* 19 - P1.2 */
	NOT_A_PIN,   /* 20 - GND */

	P2,          /* 21 - P2.0 */
	P2,          /* 22 - P2.1 */
	P4,          /* 23 - P4.0 */
	P4,          /* 24 - P4.1 */

	P4,          /* 25 - P4.6 */
	P1,          /* 26 - P1.0 */
	P4,          /* 27 - P4.5 */
	P1,          /* 28 - P1.1 */

	PJ,          /* 29 - PJ.0 */
	PJ,          /* 30 - PJ.1 */
	PJ,          /* 31 - PJ.2 */
	PJ,          /* 32 - PJ.3 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN,   /*  0 - pin count starts at 1 */
	NOT_A_PIN,   /*  1 - Vcc */
	BV(2),       /*  2 - P4.2 */
	BV(6),       /*  3 - P2.6 */
	BV(5),       /*  4 - P2.5 */
	BV(3),       /*  5 - P4.3 */
	BV(4),       /*  6 - P2.4 */
	BV(2),       /*  7 - P2.2 */
	BV(4),       /*  8 - P3.4 */
	BV(5),       /*  9 - P3.5 */
	BV(6),       /* 10 - P3.6 */
	BV(3),       /* 11 - P1.3 */
	BV(4),       /* 12 - P1.4 */
	BV(5),       /* 13 - P1.5 */
	BV(7),       /* 14 - P1.7 */
	BV(6),       /* 15 - P1.6 */
	NOT_A_PIN,   /* 16 - RST */
	NOT_A_PIN,   /* 17 - TEST */
	BV(0),       /* 18 - P3.0 */
	BV(2),       /* 19 - P1.2 */
	NOT_A_PIN,   /* 20 - GND */

	BV(0),       /* 21 - P2.0 */
	BV(1),       /* 22 - P2.1 */
	BV(0),       /* 23 - P4.0 */
	BV(1),       /* 24 - P4.1 */

	BV(6),       /* 25 - P4.6 */
	BV(0),       /* 26 - P1.0 */
	BV(5),       /* 27 - P4.5 */
	BV(1),       /* 28 - P1.1 */

	BV(0),       /* 29 - PJ.0 */
	BV(1),       /* 30 - PJ.1 */
	BV(2),       /* 31 - PJ.2 */
	BV(3),       /* 32 - PJ.3 */
};

const uint32_t digital_pin_to_analog_in[] = {
        NOT_ON_ADC,     /*  dummy   */
        NOT_ON_ADC,     /*  1 - 3.3V*/
        10,				/*  2 - A10 */
        NOT_ON_ADC,     /*  3 - P2.6 */
        NOT_ON_ADC, 	/*  4 - P2.5 */
        11,      		/*  5 - A11 */
        NOT_ON_ADC,   	/*  6 - P2.4 */
        NOT_ON_ADC,   	/*  7 - P2.2 */
        NOT_ON_ADC, 	/*  8 - P3.4 */
        NOT_ON_ADC, 	/*  9 - P3.5 */
        NOT_ON_ADC, 	/*  10 - P3.6 */
        3, 				/*  11 - A3 */
        4, 				/*  12 - A4 */
        5, 				/*  13 - A5 */
        NOT_ON_ADC,     /*  14 - P1.7 */
        NOT_ON_ADC,     /*  15 - P1.6 */
        NOT_ON_ADC, 	/*  16 - RST */
        NOT_ON_ADC,     /*  17 - TEST */
        12,		 		/*  18 - A12 */
        2,     			/*  19 - A2 */
        NOT_ON_ADC, 	/*  20 - GND */
        NOT_ON_ADC, 	/*  21 - P2.0 */
		NOT_ON_ADC, 	/*  22 - P2.1 */
        8,    			/*  23 - A8 */
        9,    			/*  24 - A9 */
        NOT_ON_ADC,    	/*  25 - P4.6 */
        NOT_ON_ADC,    	/*  26 - P1.0 */
        NOT_ON_ADC,    	/*  27 - P4.5 */
        NOT_ON_ADC, 	/*  28 - P1.1 */
        NOT_ON_ADC, 	/*  29 - PJ.0 */
        NOT_ON_ADC,     /*  30 - PJ.1 */
        NOT_ON_ADC, 	/*  31 - PJ.2 */
        NOT_ON_ADC,     /*  32 - PJ.3 */
        
};
#endif // #ifdef ARDUINO_MAIN
#endif // #ifndef Pins_Energia_h
