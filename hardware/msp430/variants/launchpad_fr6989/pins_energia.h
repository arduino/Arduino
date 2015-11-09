/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Pin definition functions for LaunchPad w/ msp430fr6989
  *		Copyright (c) 2015 Robert Wessels. All right reserved.
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
static const uint8_t SS      = 8;   /* P2.0 */
static const uint8_t SCK     = 7;   /* P1.4 */
static const uint8_t MOSI    = 15;  /* P1.6 aka SIMO */
static const uint8_t MISO    = 14;  /* P1.7 aka SOMI */
static const uint8_t TWISDA1  = 10;  /* P4.0 UCB1 */
static const uint8_t TWISCL1  = 9;   /* P4.1 UCB1 */
static const uint8_t TWISDA0  = 15;  /* P1.6 UCB0 */
static const uint8_t TWISCL0  = 14;  /* P1.7 UCB0 */
#define TWISDA0_SET_MODE (PORT_SELECTION0 | INPUT_PULLUP)
#define TWISCL0_SET_MODE (PORT_SELECTION0 | INPUT_PULLUP)
#define TWISDA1_SET_MODE (PORT_SELECTION1 | INPUT_PULLUP)
#define TWISCL1_SET_MODE (PORT_SELECTION1 | INPUT_PULLUP)
#define SPISCK_SET_MODE  (PORT_SELECTION0)
#define SPIMOSI_SET_MODE (PORT_SELECTION0)
#define SPIMISO_SET_MODE (PORT_SELECTION0)
/* Define the default I2C settings */
#define DEFAULT_I2C 1
#define TWISDA TWISDA1
#define TWISCL TWISCL1
#define TWISDA_SET_MODE  TWISDA1_SET_MODE
#define TWISCL_SET_MODE  TWISCL1_SET_MODE
#endif

#if defined(__MSP430_HAS_EUSCI_A0__) || defined(__MSP430_HAS_EUSCI_A1__)
static const uint8_t DEBUG_UARTRXD = 42;  /* Receive  Data (RXD) at P3.5 */
static const uint8_t DEBUG_UARTTXD = 41;  /* Transmit Data (TXD) at P3.4 */
static const uint8_t AUX_UARTRXD = 3;     /* Receive  Data (RXD) at P4.3 */
static const uint8_t AUX_UARTTXD = 4;     /* Transmit Data (TXD) at P4.2 */
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION0 | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION0 | OUTPUT)
#define AUX_UARTRXD_SET_MODE (PORT_SELECTION0 | INPUT)
#define AUX_UARTTXD_SET_MODE (PORT_SELECTION0 | OUTPUT)
#define DEBUG_UART_MODULE_OFFSET 0x20
#define AUX_UART_MODULE_OFFSET 0x00
#define SERIAL1_AVAILABLE 1
#endif


/* Analog pins */

static const uint8_t A0  = 128 + 0; // Not available on BoosterPack header
static const uint8_t A1  = 128 + 1; // Not available on BoosterPack header
static const uint8_t A2  = 128 + 2; // Not available on BoosterPack header
static const uint8_t A3  = 34;
static const uint8_t A4  = 26;
static const uint8_t A5  = 25;
static const uint8_t A6  = 24;
static const uint8_t A7  = 23;
static const uint8_t A8  = 27;
static const uint8_t A9  = 28;
static const uint8_t A10 = 2;
static const uint8_t A11  = 6;
static const uint8_t A12  = 17;
static const uint8_t A13  = 29;
static const uint8_t A14  = 30;
static const uint8_t A15  = 128 + 15; // Not available on BoosterPack header

/*
 FR6989 LaunchPad pin mapping - for all functions see docu

                               +--\/--+                                 +--\/--+
                          3.3v |1   21| 5.0v               (TB0.6) P2.7 |40  20| GND
                    (A10) P9.2 |2   22| GND                (TB0.5) P2.6 |39  19| P2.1 (TB0.5)
     (UCA0RXD -> Serial1) P4.3 |3   23| P8.4 (A7)          (TA1.1) P3.3 |38  18| P1.5
     (UCA0TXD -> Serial1) P4.2 |4   24| P8.5 (A6)          (TB0.2) P3.6 |37  17| P9.4 (A12)
                          P3.2 |5   25| P8.6 (A5)          (TB0.3) P3.7 |36  16| RST
                    (A11) P9.3 |6   26| P8.7 (A4)          (TB0.4) P2.2 |35  15| P1.6 (UCB0SIMO) (UCB0SDA)
                          P1.4 |7   27| P9.0 (A8)          (A3)    P1.3 |34  14| P1.7 (UCB0SOMI) (UCB0SCL)
                  (TB0.6) P2.0 |8   28| P9.1 (A9)                  P3.1 |33  13| P2.5 (TB0.4)
             (PM_UCB1SCL) P4.1 |9   29| P9.5 (A13)                 P3.2 |32  12| P2.4 (TB0.3)
             (PM_UCB1SDA) P4.0 |10  30| P9.6 (A14)                 P3.3 |31  11| P4.7 (TA1.2)
                               +------+                                 +------+

                                 ----+
                                   41| P3.4 (UCA1TXD -> ezFET -> Serial)
                                   42| P3.5 (UCA1RXD -> ezFET -> Serial)
                                   43| P1.0 (LED1 - RED)         (TA0.1)
                                   44| P9.7 (LED2 - GREEN)       (A15)
                                   45| P1.1 (PUSH1)
                                   46| P1.2 (PUSH2)
                                 ----+
*/

/* Pin names based on the silkscreen */

/* PIN1 = 3.3v */
static const uint8_t P9_2 = 2;
static const uint8_t P4_3 = 3;
static const uint8_t P4_2 = 4;
static const uint8_t P3_2 = 5;
static const uint8_t P9_3 = 6;
static const uint8_t P1_4 = 7;
static const uint8_t P2_0 = 8;
static const uint8_t P4_1 = 9;
static const uint8_t P4_0 = 10;

static const uint8_t P4_7 = 11;
static const uint8_t P2_4 = 12;
static const uint8_t P2_5 = 13;
static const uint8_t P1_7 = 14;
static const uint8_t P1_6 = 15;
/* PIN16 is RST */
static const uint8_t P9_4 = 17;
static const uint8_t P1_5 = 18;
static const uint8_t P2_1 = 19;
/* PIN20 is GND */

/* PIN21 is 5.0v */
/* PIN22 is GND */
static const uint8_t P8_4 = 23;
static const uint8_t P8_5 = 24;
static const uint8_t P8_6 = 25;
static const uint8_t P8_7 = 26;
static const uint8_t P9_0 = 27;
static const uint8_t P9_1 = 28;
static const uint8_t P9_5 = 29;
static const uint8_t P9_6 = 30;

static const uint8_t P2_3 = 31;
static const uint8_t P3_1 = 32;
static const uint8_t P3_0 = 33;
static const uint8_t P1_3 = 34;
static const uint8_t P2_2 = 35;
static const uint8_t P3_7 = 36;
static const uint8_t P3_6 = 37;
static const uint8_t P3_3 = 38;
static const uint8_t P2_6 = 39;
static const uint8_t P2_7 = 40;

/* Extra pins not on the header + temp sensor */
static const uint8_t P3_4 = 41;    /* on Pin 8 of J101 (Header to Debugger) */
static const uint8_t P3_5 = 42;    /* on Pin 10 of J101 (Header to Debugger) */
static const uint8_t P1_0 = 43;
static const uint8_t P9_7 = 44;
static const uint8_t P1_1 = 45;
static const uint8_t P1_2 = 46;

static const uint8_t PUSH1 = 45;
static const uint8_t PUSH2 = 46;
static const uint8_t RED_LED = 43;
static const uint8_t GREEN_LED = 44;
static const uint8_t TEMPSENSOR = 128 + 30;

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
#ifdef __MSP430_HAS_PORT9_R__
	(uint16_t) &P9IN,
#endif
#ifdef __MSP430_HAS_PORT10_R__
	(uint16_t) &P10IN,
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
#ifdef __MSP430_HAS_PORT9_R__
	(uint16_t) &P9OUT,
#endif
#ifdef __MSP430_HAS_PORT10_R__
	(uint16_t) &P10OUT,
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
#ifdef __MSP430_HAS_PORT9_R__
	(uint16_t) &P9DIR,
#endif
#ifdef __MSP430_HAS_PORT10_R__
	(uint16_t) &P10DIR,
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
#ifdef __MSP430_HAS_PORT9_R__
	(uint16_t) &P9REN,
#endif
#ifdef __MSP430_HAS_PORT10_R__
	(uint16_t) &P10REN,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJREN,
#endif
};

const uint16_t port_to_sel0[] = {  /* put this PxSEL register under the group of PxSEL0 */
	NOT_A_PORT,
	(uint16_t) &P1SEL0,
	(uint16_t) &P2SEL0,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL0,
#endif
#ifdef __MSP430_HAS_PORT4_R__
	(uint16_t) &P4SEL0,
#endif
#ifdef __MSP430_HAS_PORT5_R__
	(uint16_t) &P5SEL0,
#endif
#ifdef __MSP430_HAS_PORT6_R__
	(uint16_t) &P6SEL0,
#endif
#ifdef __MSP430_HAS_PORT7_R__
	(uint16_t) &P7SEL0,
#endif
#ifdef __MSP430_HAS_PORT8_R__
	(uint16_t) &P8SEL0,
#endif
#ifdef __MSP430_HAS_PORT9_R__
	(uint16_t) &P9SEL0,
#endif
#ifdef __MSP430_HAS_PORT10_R__
	(uint16_t) &P10SEL0,
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
#ifdef __MSP430_HAS_PORT5_R__
	(uint16_t) &P5SEL1,
#endif
#ifdef __MSP430_HAS_PORT6_R__
	(uint16_t) &P6SEL1,
#endif
#ifdef __MSP430_HAS_PORT7_R__
	(uint16_t) &P7SEL1,
#endif
#ifdef __MSP430_HAS_PORT8_R__
	(uint16_t) &P8SEL1,
#endif
#ifdef __MSP430_HAS_PORT9_R__
	(uint16_t) &P9SEL1,
#endif
#ifdef __MSP430_HAS_PORT10_R__
	(uint16_t) &P10SEL1,
#endif
#ifdef __MSP430_HAS_PORTJ_R__
	(uint16_t) &PJSEL1,
#endif
};

const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  dummy */
	NOT_ON_TIMER, /*  1 - 3.3v */
	NOT_ON_TIMER, /*  2 - P9.2 */
	NOT_ON_TIMER, /*  3 - P4.3 */
	NOT_ON_TIMER, /*  4 - P4.2 */
	NOT_ON_TIMER, /*  5 - P3.2 */
	NOT_ON_TIMER, /*  6 - P9.3 */
	NOT_ON_TIMER, /*  7 - P1.4  - note: CCR0 output cannot be used with analogWrite */
	T0B6_SEL1,    /*  8 - P2.0 */
	NOT_ON_TIMER, /*  9 - P4.1 */
	NOT_ON_TIMER, /* 10 - P4.0 */
	T1A2_SEL01,   /* 11 - P4.7 */
	T0B3,         /* 12 - P2.4 */
	T0B4,         /* 13 - P2.5 */
	T0A2_SEL01,   /* 14 - P1.7 */
	T0A1_SEL01,   /* 15 - P1.6 */
	NOT_ON_TIMER, /* 16 - RST  */
	NOT_ON_TIMER, /* 17 - P9.4 */
	NOT_ON_TIMER, /* 18 - P1.5  - note: CCR0 output cannot be used with analogWrite */
	T0B5_SEL1,    /* 19 - P2.1 */
	NOT_ON_TIMER, /* 20 - GND  */
	NOT_ON_TIMER, /* 21 - 5.0v */
	NOT_ON_TIMER, /* 22 - GND  */
	NOT_ON_TIMER, /* 23 - P8.4 */
	NOT_ON_TIMER, /* 24 - P8.5 */
	NOT_ON_TIMER, /* 25 - P8.6 */
	NOT_ON_TIMER, /* 26 - P8.7 */
	NOT_ON_TIMER, /* 27 - P9.0 */
	NOT_ON_TIMER, /* 28 - P9.1 */
	NOT_ON_TIMER, /* 29 - P9.5 */
	NOT_ON_TIMER, /* 30 - P9.6 */
	NOT_ON_TIMER, /* 31 - P2.3 */
	NOT_ON_TIMER, /* 32 - P3.1 */
	NOT_ON_TIMER, /* 33 - P3.0 */
	T1A2,         /* 34 - P1.3 */
	T0B4_SEL1,    /* 35 - P2.2 */
	T0B3_SEL1,    /* 36 - P3.7 */
	T0B2_SEL1,    /* 37 - P3.6 */
	T1A1_SEL1,    /* 38 - P3.3 */
	T0B5,         /* 39 - P2.6 */
	T0B6,         /* 40 - P2.7 */
	T0B0_SEL1,    /* 41 - P3.4 */
	T0B1_SEL1,    /* 42 - P3.5 */
	T0A1,         /* 43 - P1.0 */
	NOT_ON_TIMER, /* 44 - P9.7 */
	T0A2,         /* 45 - P1.1 */
	T1A1,         /* 46 - P1.2 */
};

const uint8_t digital_pin_to_port[] = {
	NOT_A_PIN, /* dummy */
	NOT_A_PIN, /* 1  - 3.3v */
	P9,        /* 2  - P9.2 */
	P4,        /* 3  - P4.3 */
	P4,        /* 4  - P4.2 */
	P3,        /* 5  - P3.2 */
	P9,        /* 6  - P9.3 */
	P1,        /* 7  - P1.4 */
	P2,        /* 8  - P2.0 */
	P4,        /* 9  - P4.1 */
	P4,        /* 10 - P4.0 */
	P4,        /* 11 - P4.7 */
	P2,        /* 12 - P2.4 */
	P2,        /* 13 - P2.5 */
	P1,        /* 14 - P1.7 */
	P1,        /* 15 - P1.6 */
	NOT_A_PIN, /* 16 - RST  */
	P9,        /* 17 - P9.4 */
	P1,        /* 18 - P1.5 */
	P2,        /* 19 - P2.1 */
	NOT_A_PIN, /* 20 - GND  */
	NOT_A_PIN, /* 21 - 5.0v */
	NOT_A_PIN, /* 22 - GND  */
	P8,        /* 23 - P8.4 */
	P8,        /* 24 - P8.5 */
	P8,        /* 25 - P8.6 */
	P8,        /* 26 - P8.7 */
	P9,        /* 27 - P9.0 */
	P9,        /* 28 - P9.1 */
	P9,        /* 29 - P9.5 */
	P9,        /* 30 - P9.6 */
	P2,        /* 31 - P2.3 */
	P3,        /* 32 - P3.1 */
	P3,        /* 33 - P3.0 */
	P1,        /* 34 - P1.3 */
	P2,        /* 35 - P2.2 */
	P3,        /* 36 - P3.7 */
	P3,        /* 37 - P3.6 */
	P3,        /* 38 - P3.3 */
	P2,        /* 39 - P2.6 */
	P2,        /* 40 - P2.7 */
	P3,        /* 41 - P3.4 */
	P3,        /* 42 - P3.5 */
	P1,        /* 43 - P1.0 */
	P9,        /* 44 - P9.7 */
	P1,        /* 45 - P1.1 */
	P1,        /* 46 - P1.2 */
};

const uint8_t digital_pin_to_bit_mask[] = {
	NOT_A_PIN, /* 0,  pin count starts at 1 */
	NOT_A_PIN, /* 1  - 3.3v */
	BV(2),     /* 2  - P9.2 */
	BV(3),     /* 3  - P4.3 */
	BV(2),     /* 4  - P4.2 */
	BV(2),     /* 5  - P3.2 */
	BV(3),     /* 6  - P9.3 */
	BV(4),     /* 7  - P1.4 */
	BV(0),     /* 8  - P2.0 */
	BV(1),     /* 9  - P4.1 */
	BV(0),     /* 10 - P4.0 */
	BV(7),     /* 11 - P4.7 */
	BV(4),     /* 12 - P2.4 */
	BV(5),     /* 13 - P2.5 */
	BV(7),     /* 14 - P1.7 */
	BV(6),     /* 15 - P1.6 */
	NOT_A_PIN, /* 16 - RST  */
	BV(4),     /* 17 - P9.4 */
	BV(5),     /* 18 - P1.5 */
	BV(1),     /* 19 - P2.1 */
	NOT_A_PIN, /* 20 - GND  */
	NOT_A_PIN, /* 21 - 5.0v */
	NOT_A_PIN, /* 22 - GND  */
	BV(4),     /* 23 - P8.4 */
	BV(5),     /* 24 - P8.5 */
	BV(6),     /* 25 - P8.6 */
	BV(7),     /* 26 - P8.7 */
	BV(0),     /* 27 - P9.0 */
	BV(1),     /* 28 - P9.1 */
	BV(5),     /* 29 - P9.5 */
	BV(6),     /* 30 - P9.6 */
	BV(3),     /* 31 - P2.3 */
	BV(1),     /* 32 - P3.1 */
	BV(0),     /* 33 - P3.0 */
	BV(3),     /* 34 - P1.3 */
	BV(2),     /* 35 - P2.2 */
	BV(7),     /* 36 - P3.7 */
	BV(6),     /* 37 - P3.6 */
	BV(3),     /* 38 - P3.3 */
	BV(6),     /* 39 - P2.6 */
	BV(7),     /* 40 - P2.7 */
	BV(4),     /* 41 - P3.4 */
	BV(5),     /* 42 - P3.5 */
	BV(0),     /* 43 - P1.0 */
	BV(7),     /* 44 - P9.7 */
	BV(1),     /* 45 - P1.1 */
	BV(2),     /* 46 - P1.2 */
};

const uint32_t digital_pin_to_analog_in[] = {
        NOT_ON_ADC,     /*  dummy   */
        NOT_ON_ADC,		/*  1  - 3.3v */
        10,   			/*  2  - P9.2 */
        NOT_ON_ADC, 	/*  3  - P4.3 */
        NOT_ON_ADC, 	/*  4  - P4.2 */
        NOT_ON_ADC,		/*  5  - P3.2 */
        11,   			/*  6  - P9.3 */
        NOT_ON_ADC, 	/*  7  - P1.4 */
        NOT_ON_ADC, 	/*  8  - P2.0 */
        NOT_ON_ADC, 	/*  9  - P4.1 */
        NOT_ON_ADC, 	/*  10 - P4.0 */
        NOT_ON_ADC, 	/*  11 - P4.7 */
        NOT_ON_ADC, 	/*  12 - P2.4 */
        NOT_ON_ADC,     /*  13 - P2.5 */
        NOT_ON_ADC,     /*  14 - P1.7 */
        NOT_ON_ADC, 	/*  15 - P1.6 */
        NOT_ON_ADC,     /*  16 - RST  */
        12, 			/*  17 - P9.4 */
        NOT_ON_ADC,     /*  18 - P1.5 */
        NOT_ON_ADC, 	/*  19 - P2.1 */
        NOT_ON_ADC, 	/*  20 - GND  */
		NOT_ON_ADC, 	/*  21 - 5.0v */
        NOT_ON_ADC,		/*  22 - GND  */
        7,    			/*  23 - P8.4 */
        6,    			/*  24 - P8.5 */
        5,    			/*  25 - P8.6 */
        4,    			/*  26 - P8.7 */
        8,    			/*  27 - P9.0 */
        9,	 			/*  28 - P9.1 */
        13, 			/*  29 - P9.5 */
        14,   		 	/*  30 - P9.6 */
        NOT_ON_ADC,     /*  31 - P2.3 */
        NOT_ON_ADC,     /*  32 - P3.1 */
        NOT_ON_ADC,     /*  33 - P3.0 */
        3,				/*  34 - P1.3 */
        NOT_ON_ADC,     /*  35 - P2.2 */
        NOT_ON_ADC,     /*  36 - P3.7 */
        NOT_ON_ADC,  	/*  37 - P3.6 */
        NOT_ON_ADC,		/*  38 - P3.3 */
        NOT_ON_ADC,     /*  39 - P2.6 */
        NOT_ON_ADC,     /*  40 - P2.7 */
        NOT_ON_ADC,     /*  41 - P3.4 */
        NOT_ON_ADC,     /*  42 - P3.5 */
        NOT_ON_ADC,     /*  43 - P1.0 */
        15,             /*  44 - P9.7 */
        NOT_ON_ADC,     /*  45 - P1.1 */
        NOT_ON_ADC,     /*  46 - P1.2 */
};
#endif // #ifdef ARDUINO_MAIN
#endif // #ifndef Pins_Energia_h
