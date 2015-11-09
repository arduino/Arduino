/*
  ************************************************************************
  *    pins_energia.h
  *
  *    Energia core files for MSP430
  *        Copyright (c) 2012 Robert Wessels. All right reserved.
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

#ifndef Pins_Energia_h
#define Pins_Energia_h
#ifndef BV
#define BV(x) (1 << (x))
#endif

#if defined(__MSP430_HAS_USCI_A0__) || defined(__MSP430_HAS_USCI_A1__)
static const uint8_t SS      = 8;  /* P2.7 */
static const uint8_t SCK     = 7;  /* P3.2 */
static const uint8_t MOSI    = 15;  /* P3.0 */
static const uint8_t MISO    = 14;  /* P3.1 */
static const uint8_t TWISDA1  = 10;  /* P4.1 UCB1 */
static const uint8_t TWISCL1  = 9;   /* P4.2 UCB1 */
static const uint8_t TWISDA0  = 15;  /* P3.0 UCB0 */
static const uint8_t TWISCL0  = 14;  /* P3.1 UCB0 */
static const uint8_t DEBUG_UARTRXD = 45;  /* Receive  Data (RXD) at P4.5 */
static const uint8_t DEBUG_UARTTXD = 46;  /* Transmit Data (TXD) at P4.4 */
static const uint8_t AUX_UARTRXD = 3;  /* Receive  Data (RXD) at P4.5 */
static const uint8_t AUX_UARTTXD = 4;  /* Transmit Data (TXD) at P4.4 */
#define TWISDA0_SET_MODE (PORT_SELECTION0)
#define TWISCL0_SET_MODE (PORT_SELECTION0)
#define TWISDA1_SET_MODE (PORT_SELECTION0 | (PM_UCB1SDA << 8)) 
#define TWISCL1_SET_MODE (PORT_SELECTION0 | (PM_UCB1SCL << 8))
#define DEBUG_UARTRXD_SET_MODE (PORT_SELECTION0 | (PM_UCA1RXD << 8) | INPUT)
#define DEBUG_UARTTXD_SET_MODE (PORT_SELECTION0 | (PM_UCA1TXD << 8) | OUTPUT)
#define AUX_UARTRXD_SET_MODE (PORT_SELECTION0 | INPUT)
#define AUX_UARTTXD_SET_MODE (PORT_SELECTION0 | OUTPUT)
#define SPISCK_SET_MODE (PORT_SELECTION0)
#define SPIMOSI_SET_MODE (PORT_SELECTION0)
#define SPIMISO_SET_MODE (PORT_SELECTION0)
/* Define the default I2C settings */
#define DEFAULT_I2C 1
#define TWISDA TWISDA1
#define TWISCL TWISCL1
#define TWISDA_SET_MODE  TWISDA1_SET_MODE
#define TWISCL_SET_MODE  TWISCL1_SET_MODE
#endif

#define DEBUG_UART_MODULE_OFFSET 0x40
#define AUX_UART_MODULE_OFFSET 0x0
#define SERIAL1_AVAILABLE 1

#if defined(__MSP430_HAS_USCI_A1__)
#define USE_USCI_A1
#endif

static const uint8_t A0  = 23;
static const uint8_t A1  = 24;
static const uint8_t A2  = 25;
static const uint8_t A3  = 26;
static const uint8_t A4  = 27;
static const uint8_t A5  = 2;
static const uint8_t A6  = 6;
static const uint8_t A7  = 128 + 7; // Not available on BoosterPack header
static const uint8_t A10 = 128 + 10; // special. This is the internal temp sensor
static const uint8_t A11  = 128 + 11; // special. This is Vcc/2
static const uint8_t A12  = 28; 
static const uint8_t A13  = 128 + 13; 
static const uint8_t A14  = 128 + 14; // Not available on BoosterPack header
static const uint8_t A15  = 128 + 15; // Not available on BoosterPack header

/*
 F5529 LaunchPad pin mapping

                               +--\/--+                                 +--\/--+
                          3.3v |1   21| 5.0v               (TA2.2) P2.5 |40  20| GND
                          P6.5 |2   22| GND                (TA2.1) P2.4 |39  19| P2.0 (TA1.1)
     (UCA0RXD -> Serial1) P3.4 |3   23| P6.0 (A0)          (TA0.4) P1.5 |38  18| P2.2
     (UCA0TXD -> Serial1) P3.3 |4   24| P6.1 (A1)          (TA0.3) P1.4 |37  17| P7.4 (TB0.2)
                          P1.6 |5   25| P6.2 (A2)          (TA0.2) P1.3 |36  16| RST
                     (A6) P6.6 |6   26| P6.3 (A3)          (TA0.1) P1.2 |35  15| P3.0 (UCB0SIMO) (UCB0SDA)
                          P3.2 |7   27| P6.4 (A4)                  P4.3 |34  14| P3.1 (UCB0SOMI) (UCB0SCL)
                          P2.7 |8   28| P7.0 (A12)                 P4.0 |33  13| P2.6
             (PM_UCB1SCL) P4.2 |9   29| P3.6 (TB0.6)               P3.7 |32  12| P2.3
             (PM_UCB1SDA) P4.1 |10  30| P3.5 (TB0.5)               P8.2 |31  11| P8.1
                               +------+                                 +------+

                                 ----+
                                   41| P2.1 (PUSH1)
                                   42| P1.1 (PUSH2)
                                   43| P1.0 (LED1 - RED)
                                   44| P4.7 (LED2 - GREEN)
                                   45| P4.5 (UCA1RXD -> ezFET -> Serial)
                                   46| P4.4 (UCA1TXD -> ezFET -> Serial)
                                 ----+
*/

/* Pin names based on the silkscreen */

/* PIN1 = 3.3v */
static const uint8_t P6_5 = 2;
static const uint8_t P3_4 = 3;
static const uint8_t P3_3 = 4;
static const uint8_t P1_6 = 5;
static const uint8_t P6_6 = 6;
static const uint8_t P3_2 = 7;
static const uint8_t P2_7 = 8;
static const uint8_t P4_2 = 9;
static const uint8_t P4_1 = 10;

static const uint8_t P8_1 = 11;
static const uint8_t P2_3 = 12;
static const uint8_t P2_6 = 13;
static const uint8_t P3_1 = 14;
static const uint8_t P3_0 = 15;
/* PIN16 is RST */
static const uint8_t P7_4 = 17;
static const uint8_t P2_2 = 18;
static const uint8_t P2_0 = 19;
/* PIN20 is GND */

/* PIN21 is 5.0v */
/* PIN22 is GND */
static const uint8_t P6_0 = 23;
static const uint8_t P6_1 = 24;
static const uint8_t P6_2 = 25;
static const uint8_t P6_3 = 26;
static const uint8_t P6_4 = 27;
static const uint8_t P7_0 = 28;
static const uint8_t P3_6 = 29;
static const uint8_t P3_5 = 30;

static const uint8_t P8_2 = 31;
static const uint8_t P3_7 = 32;
static const uint8_t P4_0 = 33;
static const uint8_t P4_3 = 34;
static const uint8_t P1_2 = 35;
static const uint8_t P1_3 = 36;
static const uint8_t P1_4 = 37;
static const uint8_t P1_5 = 38;
static const uint8_t P2_4 = 39;
static const uint8_t P2_5 = 40;

/* Extra pins not on the header + temp sensor */
static const uint8_t P2_1 = 41;
static const uint8_t P1_1 = 42;
static const uint8_t P1_0 = 43;
static const uint8_t P4_7 = 44;
static const uint8_t P4_5 = 45;
static const uint8_t P4_4 = 46;

static const uint8_t PUSH1 = 41;
static const uint8_t PUSH2 = 42;
static const uint8_t RED_LED = 43;
static const uint8_t GREEN_LED = 44;
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

const uint16_t port_to_pmap[] = {
    NOT_A_PORT,    /* PMAP starts at port P1 */
    NOT_A_PORT,
    NOT_A_PORT,
    NOT_A_PORT,
    (uint16_t) &P4MAP0,
    NOT_A_PORT,
    NOT_A_PORT,
    NOT_A_PORT,
    NOT_A_PORT,
};

const uint8_t digital_pin_to_timer[] = {
    NOT_ON_TIMER, /*  dummy */
    NOT_ON_TIMER, /*  1 - 3.3v */
    NOT_ON_TIMER, /*  2 - P6.5 */
    NOT_ON_TIMER, /*  3 - P3.4 */
    NOT_ON_TIMER, /*  4 - P3.3 */
    NOT_ON_TIMER, /*  5 - P1.6 */
    NOT_ON_TIMER, /*  6 - P6.6 */
    NOT_ON_TIMER, /*  7 - P3.2 */
    NOT_ON_TIMER, /*  8 - P2.7 */
    NOT_ON_TIMER, /*  9 - P4.2 */
    NOT_ON_TIMER, /* 10 - P4.1 */
    NOT_ON_TIMER, /* 11 - P8.1 */
    NOT_ON_TIMER, /* 12 - P2.3  - note: CCR0 output cannot be used with analogWrite */
    NOT_ON_TIMER, /* 13 - P2.6 */
    NOT_ON_TIMER, /* 14 - P3.2 */
    NOT_ON_TIMER, /* 15 - P3.0 */
    NOT_ON_TIMER, /* 16 - RST */
    T0B2,         /* 17 - P7.4 */
    NOT_ON_TIMER, /* 18 - P2.2 */
    T1A1,         /* 19 - P2.0 */
    NOT_ON_TIMER, /* 20 - GND  */
    NOT_ON_TIMER, /* 21 - 5.0v */
    NOT_ON_TIMER, /* 22 - GND */
    NOT_ON_TIMER, /* 23 - P6.0 */
    NOT_ON_TIMER, /* 24 - P6.1 */
    NOT_ON_TIMER, /* 25 - P6.2 */
    NOT_ON_TIMER, /* 26 - P6.3 */
    NOT_ON_TIMER, /* 27 - P6.4 */
    NOT_ON_TIMER, /* 28 - P7.0 */
    T0B6,         /* 29 - P3.6 */
    T0B5,         /* 30 - P3.5 */
    NOT_ON_TIMER, /* 31 - P8.2 */
    NOT_ON_TIMER, /* 32 - P3.7 */
    NOT_ON_TIMER, /* 33 - P4.0 */
    NOT_ON_TIMER, /* 34 - P4.3 */
    T0A1,         /* 35 - P1.2 */
    T0A2,         /* 36 - P1.3 */
    T0A3,         /* 37 - P1.4 */
    T0A4,         /* 38 - P1.5 */
    T2A1,         /* 39 - P2.4 */
    T2A2,         /* 40 - P2.5 */
    NOT_ON_TIMER, /* 41 - P2.1 */
    NOT_ON_TIMER, /* 42 - P1.1 */
    NOT_ON_TIMER, /* 43 - P1.0 */
    T0B1,         /* 44 - P4.7 */
};

const uint8_t digital_pin_to_port[] = {
    NOT_A_PIN, /* dummy */
    NOT_A_PIN, /* 1 */
    P6,        /* 2 */
    P3,        /* 3 */
    P3,        /* 4 */
    P1,        /* 5 */
    P6,        /* 6 */
    P3,        /* 7 */
    P2,        /* 8 */
    P4,        /* 9 */
    P4,        /* 10 */
    P8,        /* 11 */
    P2,        /* 12 */
    P2,        /* 13 */
    P3,        /* 14 */
    P3,        /* 15 */
    NOT_A_PIN, /* 16 */
    P7,        /* 17 */
    P2,        /* 18 */
    P2,        /* 19 */
    NOT_A_PIN, /* 20 */
    NOT_A_PIN, /* 21 */
    NOT_A_PIN, /* 22 */
    P6,        /* 23 */
    P6,        /* 24 */
    P6,        /* 25 */
    P6,        /* 26 */
    P6,        /* 27 */
    P7,        /* 28 */
    P3,        /* 29 */
    P3,        /* 30 */
    P8,        /* 31 */
    P3,        /* 32 */
    P4,        /* 33 */
    P4,        /* 34 */
    P1,        /* 35 */
    P1,        /* 36 */
    P1,        /* 37 */
    P1,        /* 38 */
    P2,        /* 39 */
    P2,        /* 40 */
    P2,        /* 41 */
    P1,        /* 42 */
    P1,        /* 43 */
    P4,        /* 44 */
    P4,        /* 45 */
    P4,        /* 46 */
};

const uint8_t digital_pin_to_bit_mask[] = {
    NOT_A_PIN, /* 0,  pin count starts at 1 */
    NOT_A_PIN, /* 1 */
    BV(5),     /* 2 */
    BV(4),     /* 3 */
    BV(3),     /* 4 */
    BV(6),     /* 5 */
    BV(6),     /* 6 */
    BV(2),     /* 7 */
    BV(7),     /* 8 */
    BV(2),     /* 9 */
    BV(1),     /* 10 */
    BV(1),     /* 11 */
    BV(3),     /* 12 */
    BV(6),     /* 13 */
    BV(1),     /* 14 */
    BV(0),     /* 15 */
    NOT_A_PIN, /* 16 */
    BV(4),     /* 17 */
    BV(2),     /* 18 */
    BV(0),     /* 19 */
    NOT_A_PIN, /* 20 */
    NOT_A_PIN, /* 21 */
    NOT_A_PIN, /* 22 */
    BV(0),     /* 23 */
    BV(1),     /* 24 */
    BV(2),     /* 25 */
    BV(3),     /* 26 */
    BV(4),     /* 27 */
    BV(0),     /* 28 */
    BV(6),     /* 29 */
    BV(5),     /* 30 */
    BV(2),     /* 31 */
    BV(7),     /* 32 */
    BV(0),     /* 33 */
    BV(3),     /* 34 */
    BV(2),     /* 35 */
    BV(3),     /* 36 */
    BV(4),     /* 37 */
    BV(5),     /* 38 */
    BV(4),     /* 39 */
    BV(5),     /* 40 */
    BV(1),     /* 41 */
    BV(1),     /* 42 */
    BV(0),     /* 43 */
    BV(7),     /* 44 */
    BV(5),     /* 45 */
    BV(4),     /* 46 */
};

const uint32_t digital_pin_to_analog_in[] = {
        NOT_ON_ADC,     /*  dummy   */
        NOT_ON_ADC,     /*  1 - 3.3V*/
        5,              /*  2 - A5 */
        NOT_ON_ADC,     /*  3 - P3.4 */
        NOT_ON_ADC,     /*  4 - P3.3 */
        NOT_ON_ADC,     /*  5 - P1.6 */
        6,              /*  6 - A6 */
        NOT_ON_ADC,     /*  7 - P3.2 */
        NOT_ON_ADC,     /*  8 - P2.7 */
        NOT_ON_ADC,     /*  9 - P4.2 */
        NOT_ON_ADC,     /*  10 - P4.1 */
        NOT_ON_ADC,     /*  11 - P8.1 */
        NOT_ON_ADC,     /*  12 - P2.3 */
        NOT_ON_ADC,     /*  13 - P2.6 */
        NOT_ON_ADC,     /*  14 - P3.1 */
        NOT_ON_ADC,     /*  15 - P3.0 */
        NOT_ON_ADC,     /*  16 - RST */
        NOT_ON_ADC,     /*  17 - P7.4 */
        NOT_ON_ADC,     /*  18 - P2.2 */
        NOT_ON_ADC,     /*  19 - P2.0 */
        NOT_ON_ADC,     /*  20 - GND */
        NOT_ON_ADC,     /*  21 - 5V */
        NOT_ON_ADC,     /*  22 - GND */
        0,              /*  23 - A0 */
        1,              /*  24 - A1 */
        2,              /*  25 - A2 */
        3,              /*  26 - A3 */
        4,              /*  27 - A4 */
        12,             /*  28 - A12 */
        NOT_ON_ADC,     /*  29 - P3.6 */
        NOT_ON_ADC,     /*  30 - P3.5 */
        NOT_ON_ADC,     /*  31 - P8.2 */
        NOT_ON_ADC,     /*  32 - P3.7 */
        NOT_ON_ADC,     /*  33 - P4.0 */
        NOT_ON_ADC,     /*  34 - P4.3 */
        NOT_ON_ADC,     /*  35 - P1.2 */
        NOT_ON_ADC,     /*  36 - P1.3 */
        NOT_ON_ADC,     /*  37 - P1.4 */
        NOT_ON_ADC,     /*  38 - P1.5 */
        NOT_ON_ADC,     /*  39 - P2.4 */
        NOT_ON_ADC      /*  40 - P2.5 */
};
#endif // #ifdef ARDUINO_MAIN
#endif // #ifndef Pins_Energia_h
