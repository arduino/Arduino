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

#include <part.h>

#ifndef BV
#define BV(x) (1 << (x))
#endif 
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"

//
// Pin names based on the silkscreen
//
// BOOSTER PACK 1
// X8 and X9
static const uint8_t PE_4 = 2;  // X8-03
static const uint8_t PC_4 = 3;  // X8-05
static const uint8_t PC_5 = 4;  // X8-07
static const uint8_t PC_6 = 5;  // X8-09
static const uint8_t PE_5 = 6;  // X8-11
static const uint8_t PD_3 = 7;  // X8-13
static const uint8_t PC_7 = 8;  // X8-15
static const uint8_t PB_2 = 9;  // X8-17
static const uint8_t PB_3 = 10; // X8-19
static const uint8_t PP_2 = 11; // X9-20
static const uint8_t PN_3 = 12; // X9-18
static const uint8_t PN_2 = 13; // X9-16
static const uint8_t PD_0 = 14; // X9-14
static const uint8_t PD_1 = 15; // X9-12
//                    RST = 16  // X9-10
static const uint8_t PH_3 = 17; // X9-08
static const uint8_t PH_2 = 18; // X9-06
static const uint8_t PM_3 = 19; // X9-04
//                    GND = 20  // X9-02

// X8 and X9
//                     5v = 21  // X8-02
//                    GND = 22  // X8-04
static const uint8_t PE_0 = 23; // X8-06
static const uint8_t PE_1 = 24; // X8-08
static const uint8_t PE_2 = 25; // X8-10
static const uint8_t PE_3 = 26; // X8-12
static const uint8_t PD_7 = 27; // X8-14
static const uint8_t PA_6 = 28; // X8-16
static const uint8_t PM_4 = 29; // X8-18
static const uint8_t PM_5 = 30; // X8-20
static const uint8_t PL_3 = 31; // X9-19
static const uint8_t PL_2 = 32; // X9-17
static const uint8_t PL_1 = 33; // X9-15
static const uint8_t PL_0 = 34; // X9-13
static const uint8_t PL_5 = 35; // X9-11
static const uint8_t PL_4 = 36; // X9-09
static const uint8_t PG_0 = 37; // X9-07
static const uint8_t PF_3 = 38; // X9-05
static const uint8_t PF_2 = 39; // X9-03
static const uint8_t PF_1 = 40; // X9-01
// BOOSTER PACK 1 end

// BOOSTER PACK 2
// X6 and X7
//                   3.3v = 41; // X6-01
static const uint8_t PD_2 = 42; // X6-03
static const uint8_t PP_0 = 43; // X6-05
static const uint8_t PP_1 = 44; // X6-07
static const uint8_t PA_0 = 45; // X6-09 JP4 4-2
static const uint8_t PA_1 = 46; // X6-11 JP5 4-2
static const uint8_t PQ_0 = 47; // X6-13
static const uint8_t PP_4 = 48; // X6-15 
static const uint8_t PN_5 = 49; // X6-17
static const uint8_t PN_4 = 50; // X6-19
static const uint8_t PM_6 = 51; // X7-20
static const uint8_t PQ_1 = 52; // X7-18
static const uint8_t PP_3 = 53; // X7-16
static const uint8_t PQ_3 = 54; // X7-14
static const uint8_t PQ_2 = 55; // X7-12
//                  RESET = 56; // X7-10
static const uint8_t PA_7 = 57; // X7-08
static const uint8_t PP_5 = 58; // X7-06
static const uint8_t PM_7 = 59; // X7-04
//                    GND = 60; // X7-02
// X6 and X7
//                     5v = 61  // X6-02
//                    GND = 62  // X6-04
static const uint8_t PB_4 = 63; // X6-06
static const uint8_t PB_5 = 64; // X6-08
static const uint8_t PK_0 = 65; // X6-10
static const uint8_t PK_1 = 66; // X6-12
static const uint8_t PK_2 = 67; // X6-14
static const uint8_t PK_3 = 68; // X6-16
static const uint8_t PA_4 = 69; // X6-18
static const uint8_t PA_5 = 70; // X6-20
static const uint8_t PK_7 = 71; // X7-19
static const uint8_t PK_6 = 72; // X7-17
static const uint8_t PH_1 = 73; // X7-15
static const uint8_t PH_0 = 74; // X7-13
static const uint8_t PM_2 = 75; // X7-11
static const uint8_t PM_1 = 76; // X7-09
static const uint8_t PM_0 = 77; // X7-07
static const uint8_t PK_5 = 78; // X7-05
static const uint8_t PK_4 = 79; // X7-03
static const uint8_t PG_1 = 80; // X7-01
// BOOSTER PACK 2 end

// LEDs
static const uint8_t PN_1 = 81; // LED1
static const uint8_t PN_0 = 82; // LED2
static const uint8_t PF_4 = 83; // LED3
static const uint8_t PF_0 = 84; // LED4

static const uint8_t RED_LED      = 81;  // TODO: verify colors
static const uint8_t BLUE_LED     = 82;
static const uint8_t GREEN_LED    = 83;
static const uint8_t SPEED_LED    = 84;

static const uint8_t LINK_LED     = 84;
static const uint8_t ACTIVITY_LED = 83;
// LEDs end

// pushbuttons
static const uint8_t PJ_0       = 85;
static const uint8_t PJ_1       = 86;

static const uint8_t PUSH1      = 85;
static const uint8_t PUSH2      = 86;

static const uint8_t USR_SW1    = 85;
static const uint8_t USR_SW2    = 86;
// pushbuttons end

static const uint8_t A0 =  23; //PE_3
static const uint8_t A1 =   2; //PE_2
static const uint8_t A2 =  30; //PE_1
static const uint8_t A3 =  29; //PE_0
static const uint8_t A4 =  77; //PD_7
static const uint8_t A5 =  76; //PD_6
static const uint8_t A6 =  51; //PD_5
static const uint8_t A7 =  78; //PD_4
static const uint8_t A8 =  67; //PE_5
static const uint8_t A9 =  57; //PE_4
static const uint8_t A10 =  9; //PB_4
static const uint8_t A11 = 50; //PB_5
static const uint8_t A12 = 39; //PD_3
static const uint8_t A13 = 32; //PD_2
static const uint8_t A14 = 59; //PD_1
static const uint8_t A15 = 42; //PD_0
static const uint8_t A16 = 25; //PK_0
static const uint8_t A17 = 26; //PK_1
static const uint8_t A18 = 27; //PK_2
static const uint8_t A19 = 28; //PK_3

#ifdef ARDUINO_MAIN
const uint32_t port_to_base[] = {
    NOT_A_PORT,
    (uint32_t) GPIO_PORTA_BASE, // 1
    (uint32_t) GPIO_PORTB_BASE, // 2
    (uint32_t) GPIO_PORTC_BASE, // 3
    (uint32_t) GPIO_PORTD_BASE, // 4
    (uint32_t) GPIO_PORTE_BASE, // 5
    (uint32_t) GPIO_PORTF_BASE, // 6
    (uint32_t) GPIO_PORTG_BASE, // 7
    (uint32_t) GPIO_PORTH_BASE, // 8
    (uint32_t) GPIO_PORTJ_BASE, // 9
    (uint32_t) GPIO_PORTK_BASE, // 10
    (uint32_t) GPIO_PORTL_BASE, // 11
    (uint32_t) GPIO_PORTM_BASE, // 12
    (uint32_t) GPIO_PORTN_BASE, // 13
    (uint32_t) GPIO_PORTP_BASE, // 14
    (uint32_t) GPIO_PORTQ_BASE, // 15
};

const uint8_t digital_pin_to_timer[] = {
    NOT_ON_TIMER,   /*  dummy */
    NOT_ON_TIMER,   /*   1 - 3.3V */
    T1B0,           /*   2 - PE_2 */
    T2A0,           /*   3 - PH_6 */
    T2B,            /*   4 - PH_7 */
    NOT_ON_TIMER,   /*   5 - PN_7 */
    NOT_ON_TIMER,   /*   6 - PF_3 */
    T1A0,           /*   7 - PG_7 */
    NOT_ON_TIMER,   /*   8 - PJ_2 */
    NOT_ON_TIMER,   /*   9 - PB_4 */
    NOT_ON_TIMER,   /*  10 - PJ_7 */
    NOT_ON_TIMER,   /*  11 - PN_2 */
    NOT_ON_TIMER,   /*  12 - PN_1 */
    NOT_ON_TIMER,   /*  13 - PN_0 */
    T0A0,           /*  14 - PG_4 */
    T0B0,           /*  15 - PG_5 */
    NOT_ON_TIMER,   /*  16 - RST */
    NOT_ON_TIMER,   /*  17 - NC */
    NOT_ON_TIMER,   /*  18 - PQ_7 */
    T3A,            /*  19 - PS_2 */
    NOT_ON_TIMER,   /*  20 - GND */
    NOT_ON_TIMER,   /*  21 - VBUS */
    NOT_ON_TIMER,   /*  22 - GND */
    WT2A,           /*  23 - PE_3 */
    WT2B,           /*  24 - PE_6 */
    WT3A,           /*  25 - PK_0 */
    WT3B,           /*  26 - PK_1 */
    NOT_ON_TIMER,   /*  27 - PK_2 */
    NOT_ON_TIMER,   /*  28 - PK_3 */
    NOT_ON_TIMER,   /*  29 - PE_0 */
    T0B1,           /*  30 - PE_1 */
    T2A1,           /*  31 - PM_7 */
    WT5B,           /*  32 - PD_2 */
    WT5A,           /*  33 - PQ_3 */
    WT1B,           /*  34 - PS_1 */
    WT1A,           /*  35 - PS_0 */
    WT0B,           /*  36 - PL_4 */
    WT0A,           /*  37 - PL_5 */
    T3B,            /*  38 - PS_3 */
    T1B1,           /*  39 - PD_3 */
    T1A1,           /*  40 - PM_5 */
    NOT_ON_TIMER,   /*  41 - J6_VCC */ // CH will clean these up next
    NOT_ON_TIMER,   /*  42 - PD_0 */
    NOT_ON_TIMER,   /*  43 - PJ_0 BP2_RX*/
    NOT_ON_TIMER,   /*  44 - PJ_1 BP2_TX */
    NOT_ON_TIMER,   /*  45 - PT_0 */
    NOT_ON_TIMER,   /*  46 - PT_1 */
    NOT_ON_TIMER,   /*  47 - PA_2 */
    NOT_ON_TIMER,   /*  48 - PS_6 */
    NOT_ON_TIMER,   /*  49 - PS_7 */
    NOT_ON_TIMER,   /*  50 - PB_5 */
    NOT_ON_TIMER,   /*  51 - PD_5 */
    NOT_ON_TIMER,   /*  52 - PP_6 */
    NOT_ON_TIMER,   /*  53 - PH_5 */
    NOT_ON_TIMER,   /*  54 - PA_5 */
    NOT_ON_TIMER,   /*  55 - PA_4 */
    NOT_ON_TIMER,   /*  56 - RESET */
    NOT_ON_TIMER,   /*  57 - PE_4 */
    NOT_ON_TIMER,   /*  58 - PJ_3 */
    NOT_ON_TIMER,   /*  59 - PD_1 */
    NOT_ON_TIMER,   /*  60 - GND */
    NOT_ON_TIMER,   /*  61 - PN_5 */
    NOT_ON_TIMER,   /*  62 - PQ_4 */
    NOT_ON_TIMER,   /*  63 - PF_1 */
    NOT_ON_TIMER,   /*  64 - PK_4 */
    NOT_ON_TIMER,   /*  65 - PK_6 */
    NOT_ON_TIMER,   /*  66 - PN_3 */
    NOT_ON_TIMER,   /*  67 - PE_5 */
    NOT_ON_TIMER,   /*  68 - PP_1 */
    NOT_ON_TIMER,   /*  69 - PA_3 */
    NOT_ON_TIMER,   /*  70 - PB_6 */
    NOT_ON_TIMER,   /*  71 - PB_7 */
    NOT_ON_TIMER,   /*  72 - PF_0 */
    NOT_ON_TIMER,   /*  73 - PF_2 */
    NOT_ON_TIMER,   /*  74 - PQ_1 */
    NOT_ON_TIMER,   /*  75 - PQ_2 */
    NOT_ON_TIMER,   /*  76 - PD_6 */
    NOT_ON_TIMER,   /*  77 - PD_7 */
    NOT_ON_TIMER,   /*  78 - PD_4 */
    NOT_ON_TIMER,   /*  79 - PE_7 */
    NOT_ON_TIMER,   /*  80 - PP_7 */
};

const uint8_t digital_pin_to_port[] = {
    NOT_A_PIN,  /*   dummy */
    NOT_A_PIN,  /*   1 - 3.3V */
    PE,         /*   2 - PE_4 */
    PC,         /*   3 - PC_4 */
    PC,         /*   4 - PC_5 */
    PC,         /*   5 - PN_6 */
    PE,         /*   6 - PE_5 */
    PD,         /*   7 - PG_3 */
    PC,         /*   8 - PC_7 */
    PB,         /*   9 - PB_3 */
    PB,         /*  10 - PB_3 */
    PP,         /*  11 - PP_2 */
    PM,         /*  12 - PM_3 */
    PN,         /*  13 - PN_2 */
    PD,         /*  14 - PD_0 */
    PD,         /*  15 - PD_1 */
    NOT_A_PIN,  /*  16 - RST */
    PH,         /*  17 - PH_3 */
    PH,         /*  18 - PH_2 */
    PM,         /*  19 - PM_3 */
    NOT_A_PIN,  /*  20 - GND */
    NOT_A_PIN,  /*  21 - VBUS */
    NOT_A_PIN,  /*  22 - GND */
    PE,         /*  23 - PE_0 */
    PE,         /*  24 - PE_1 */
    PE,         /*  25 - PE_2 */
    PE,         /*  26 - PE_3 */
    PD,         /*  27 - PD_7 */
    PA,         /*  28 - PA_6 */
    PM,         /*  29 - PM_4 */
    PM,         /*  30 - PM_5 */
    PL,         /*  31 - PL_3 */
    PL,         /*  32 - PL_2 */
    PL,         /*  33 - PL_1 */
    PL,         /*  34 - PL_0 */
    PL,         /*  35 - PL_5 */
    PL,         /*  36 - PL_4 */
    PG,         /*  37 - PG_0 */
    PF,         /*  38 - PF_3 */
    PF,         /*  39 - PF_2 */
    PF,         /*  40 - PM_1 */
    NOT_A_PIN,  /*  41 - 3.3V */
    PD,         /*  42 - PD_2 */
    PP,         /*  43 - PD_0 BP2_RX */
    PP,         /*  44 - PD_1 BP2_TX */
    PA,         /*  45 - PA_0 */
    PA,         /*  46 - PA_1 */
    PQ,         /*  47 - PQ_0 */
    PP,         /*  48 - PP_4 */
    PN,         /*  49 - PN_5 */
    PN,         /*  50 - PN_5 */
    PM,         /*  51 - PM_6 */
    PQ,         /*  52 - PQ_1 */
    PP,         /*  53 - PP_3 */
    PQ,         /*  54 - PQ_3 */
    PQ,         /*  55 - PQ_2 */
    NOT_A_PIN,  /*  56 - RESET */
    PA,         /*  57 - PQ_7 */
    PP,         /*  58 - PP_5 */
    PM,         /*  59 - PM_7 */
    NOT_A_PIN,  /*  60 - GND */
    NOT_A_PIN,  /*  61 - 5v */
    NOT_A_PIN,  /*  62 - GND */
    PB,         /*  63 - PB_4 */
    PB,         /*  64 - PB_5 */
    PK,         /*  65 - PK_0 */
    PK,         /*  66 - PK_1 */
    PK,         /*  67 - PK_2 */
    PK,         /*  68 - PK_3 */
    PA,         /*  69 - PA_4 */
    PA,         /*  70 - PA_5 */
    PK,         /*  71 - PK_7 */
    PK,         /*  72 - PK_6 */
    PH,         /*  73 - PH_1 */
    PH,         /*  74 - PH_0 */
    PM,         /*  75 - PM_2 */
    PM,         /*  76 - PM_1 */
    PM,         /*  77 - PM_0 */
    PK,         /*  78 - PK_5 */
    PK,         /*  79 - PK_4 */
    PG,         /*  80 - PG_1 */
    PN,         /*  81 - PN_1 */
    PN,         /*  82 - PN_0 */
    PF,         /*  83 - PF_4 */
    PF,         /*  84 - PF_0 */
    PJ,         /*  85 - PJ_0 */
    PJ,         /*  86 - PJ_1 */
};

const uint8_t digital_pin_to_bit_mask[] = {
    NOT_A_PIN,  /*   dummy */
    NOT_A_PIN,  /*   1 - 3.3V */
    BV(4),      /*   2 - PE_4 */
    BV(4),      /*   3 - PC_4 */
    BV(5),      /*   4 - PC_5 */
    BV(6),      /*   5 - PN_6 */
    BV(5),      /*   6 - PP_5 */
    BV(3),      /*   7 - PG_3 */
    BV(7),      /*   8 - PC_7 */
    BV(3),      /*   9 - PB_3 */
    BV(3),      /*  10 - PB_3 */
    BV(2),      /*  11 - PP_2 */
    BV(3),      /*  12 - PM_3 */
    BV(2),      /*  13 - PN_2 */
    BV(0),      /*  14 - PD_0 */
    BV(1),      /*  15 - PD_1 */
    NOT_A_PIN,  /*  16 - RST */
    BV(3),      /*  17 - PH_3 */
    BV(2),      /*  18 - PH_2 */
    BV(3),      /*  19 - PM_3 */
    NOT_A_PIN,  /*  20 - GND */
    NOT_A_PIN,  /*  21 - VBUS */
    NOT_A_PIN,  /*  22 - GND */
    BV(0),      /*  23 - PE_0 */
    BV(1),      /*  24 - PE_1 */
    BV(2),      /*  25 - PE_2 */
    BV(3),      /*  26 - PD_3 */
    BV(7),      /*  27 - PA_7 */
    BV(6),      /*  28 - PM_6 */
    BV(4),      /*  29 - PM_4 */
    BV(5),      /*  30 - PM_5 */
    BV(3),      /*  31 - PL_3 */
    BV(2),      /*  32 - PL_2 */
    BV(1),      /*  33 - PL_1 */
    BV(0),      /*  34 - PL_0 */
    BV(5),      /*  35 - PL_5 */
    BV(4),      /*  36 - PL_4 */
    BV(0),      /*  37 - PG_0 */
    BV(3),      /*  38 - PF_3 */
    BV(2),      /*  39 - PF_2 */
    BV(1),      /*  40 - PM_1 */
    NOT_A_PIN,  /*  41 - 3.3v */
    BV(2),      /*  42 - PD_2 */
    BV(0),      /*  43 - PJ_0 BP2_RX */
    BV(1),      /*  44 - PJ_1 BP2_TX */
    BV(0),      /*  45 - PT_0 */
    BV(1),      /*  46 - PT_1 */
    BV(0),      /*  47 - PA_0 */
    BV(4),      /*  48 - PS_4 */
    BV(4),      /*  49 - PS_4 */
    BV(5),      /*  50 - PB_5 */
    BV(6),      /*  51 - PD_6 */
    BV(1),      /*  52 - PP_1 */
    BV(3),      /*  53 - PH_3 */
    BV(3),      /*  54 - PA_3 */
    BV(2),      /*  55 - PA_2 */
    NOT_A_PIN,   /*  56 - RESET */
    BV(7),      /*  57 - PA_4 */
    BV(5),      /*  58 - PP_3 */
    BV(7),      /*  59 - PM_1 */
    NOT_A_PIN,  /*  60 - GND */
    NOT_A_PIN,  /*  61 - 5v */
    NOT_A_PIN,  /*  62 - GND */
    BV(4),      /*  63 - PB_1 */
    BV(5),      /*  64 - PB_4 */
    BV(0),      /*  65 - PK_6 */
    BV(1),      /*  66 - PK_3 */
    BV(2),      /*  67 - PK_5 */
    BV(3),      /*  68 - PK_1 */
    BV(4),      /*  69 - PA_3 */
    BV(5),      /*  70 - PA_6 */
    BV(7),      /*  71 - PK_7 */
    BV(6),      /*  72 - PK_0 */
    BV(1),      /*  73 - PH_2 */
    BV(0),      /*  74 - PH_1 */
    BV(2),      /*  75 - PM_2 */
    BV(1),      /*  76 - PM_6 */
    BV(0),      /*  77 - PM_7 */
    BV(5),      /*  78 - PL_4 */
    BV(4),      /*  79 - PK_7 */
    BV(1),      /*  80 - PG_7 */
    BV(1),      /*  81 - PN_1 */
    BV(0),      /*  82 - PN_0 */
    BV(4),      /*  83 - PF_4 */
    BV(0),      /*  84 - PF_0 */
    BV(0),      /*  85 - PJ_0 */
    BV(1),      /*  86 - PJ_1 */
};

const uint32_t timer_to_offset[] = {
    TIMER0,
    TIMER0,
    TIMER0,
    TIMER0,
    TIMER1,
    TIMER1,
    TIMER1,
    TIMER1,
    TIMER2,
    TIMER2,
    TIMER2,
    TIMER3,
    TIMER3,
    WTIMER0,
    WTIMER0,
    WTIMER1,
    WTIMER1,
    WTIMER2,
    WTIMER2,
    WTIMER3,
    WTIMER3,
    WTIMER5,
    WTIMER5,
};

const uint8_t timer_to_ab[] = {
    TIMA,
    TIMA,
    TIMB,
    TIMB,
    TIMA,
    TIMA,
    TIMB,
    TIMB,
    TIMA,
    TIMA,
    TIMB,
    TIMA,
    TIMB,
    TIMA,
    TIMB,
    TIMA,
    TIMB,
    TIMA,
    TIMB,
    TIMA,
    TIMB,
    TIMA,
    TIMB,
};
const uint32_t timer_to_pin_config[] = {
/*
	GPIO_PB6_T0CCP0,
	GPIO_PF0_T0CCP0,
	GPIO_PB7_T0CCP1,
	GPIO_PF1_T0CCP1,
	GPIO_PB4_T1CCP0,
	GPIO_PF2_T1CCP0,
	GPIO_PB5_T1CCP1,
	GPIO_PF3_T1CCP1,
	GPIO_PB0_T2CCP0,
	GPIO_PF4_T2CCP0,
	GPIO_PB1_T2CCP1,
	GPIO_PB2_T3CCP0,
	GPIO_PB3_T3CCP1,
	GPIO_PC4_WT0CCP0,
	GPIO_PC5_WT0CCP1,
	GPIO_PC6_WT1CCP0,
	GPIO_PC7_WT1CCP1,
	GPIO_PD0_WT2CCP0,
	GPIO_PD1_WT2CCP1,
	GPIO_PD2_WT3CCP0,
	GPIO_PD3_WT3CCP1,
	GPIO_PD6_WT5CCP0,
	GPIO_PD7_WT5CCP1,
*/
};
const uint32_t digital_pin_to_analog_in[] = {
    NOT_ON_ADC,     /*   dummy   */
    NOT_ON_ADC,     /*   1 - 3.3V*/
    ADC_CTL_CH1,    /*   2 - PE_2 */
    NOT_ON_ADC,     /*   3 - PH_6 */
    NOT_ON_ADC,     /*   4 - PH_7 */
    NOT_ON_ADC,     /*   5 - PN_7 */
    NOT_ON_ADC,     /*   6 - PF_3 */
    NOT_ON_ADC,     /*   7 - PG_7 */
    NOT_ON_ADC,     /*   8 - PJ_2 */
    ADC_CTL_CH10,   /*   9 - PB_4 */
    NOT_ON_ADC,     /*  10 - PJ_7 */
    NOT_ON_ADC,     /*  11 - PN_2 */
    NOT_ON_ADC,     /*  12 - PN_1 */
    NOT_ON_ADC,     /*  13 - PN_0 */
    NOT_ON_ADC,     /*  14 - PG_4 */
    NOT_ON_ADC,     /*  15 - PG_5 */
    NOT_ON_ADC,     /*  16 - RST */
    NOT_ON_ADC,     /*  17 - PF0 */
    NOT_ON_ADC,     /*  18 - PQ_7 */
    NOT_ON_ADC,     /*  19 - PS_2 */
    NOT_ON_ADC,     /*  20 - GND */
    NOT_ON_ADC,     /*  21 - VBUS */
    NOT_ON_ADC,     /*  22 - GND */
    ADC_CTL_CH0,    /*  23 - PE_3 */
    ADC_CTL_CH20,   /*  24 - PE_6 */
    ADC_CTL_CH16,   /*  25 - PK_0 */
    ADC_CTL_CH17,   /*  26 - PK_1 */
    ADC_CTL_CH18,   /*  27 - PK_2 */
    ADC_CTL_CH19,   /*  28 - PK_3 */
    ADC_CTL_CH3,    /*  29 - PE_0 */
    ADC_CTL_CH2,    /*  30 - PE_1 */
    NOT_ON_ADC,     /*  31 - PM_7 */
    ADC_CTL_CH13,   /*  32 - PD_2 */
    NOT_ON_ADC,     /*  33 - PQ_3 */
    NOT_ON_ADC,     /*  34 - PS_1 */
    NOT_ON_ADC,     /*  35 - PS_0 */
    NOT_ON_ADC,     /*  36 - PL_4 */
    NOT_ON_ADC,     /*  37 - PL_5 */
    NOT_ON_ADC,     /*  38 - PS_3 */
    ADC_CTL_CH12,   /*  39 - PD_3 */
    NOT_ON_ADC,     /*  40 - PM_5 */
    NOT_ON_ADC,     /*  41 - J6_VCC */
    ADC_CTL_CH15,   /*  42 - PD_0 */
    NOT_ON_ADC,     /*  43 - PJ_0 BP2_RX */
    NOT_ON_ADC,     /*  44 - PJ_1 BP2_TX */
    NOT_ON_ADC,     /*  45 - PT_0 */
    NOT_ON_ADC,     /*  46 - PT_1 */
    NOT_ON_ADC,     /*  47 - PA_2 */
    NOT_ON_ADC,     /*  48 - PS_6 */
    NOT_ON_ADC,     /*  49 - PS_7 */
    ADC_CTL_CH11,   /*  50 - PB_5 */
    ADC_CTL_CH6,    /*  51 - PD_5 */
    ADC_CTL_CH23,   /*  52 - PP_6 */
    NOT_ON_ADC,     /*  53 - PH_5 */
    NOT_ON_ADC,     /*  54 - PA_5 */
    NOT_ON_ADC,     /*  55 - PA_4 */
    NOT_ON_ADC,     /*  56 - RESET */
    ADC_CTL_CH9,    /*  57 - PE_4 */
    NOT_ON_ADC,     /*  58 - PJ_3 */
    ADC_CTL_CH14,   /*  59 - PD_1 */
    NOT_ON_ADC,     /*  60 - GND */
    NOT_ON_ADC,     /*  61 - PN_5 */
    NOT_ON_ADC,     /*  62 - PQ_4 */
    NOT_ON_ADC,     /*  63 - PF_1 */
    NOT_ON_ADC,     /*  64 - PK_4 */
    NOT_ON_ADC,     /*  65 - PK_6 */
    NOT_ON_ADC,     /*  66 - PN_3 */
    ADC_CTL_CH8,    /*  67 - PE_5 */
    NOT_ON_ADC,     /*  68 - PP_1 */
    NOT_ON_ADC,     /*  69 - PA_3 */
    NOT_ON_ADC,     /*  70 - PB_6 */
    NOT_ON_ADC,     /*  71 - PB_7 */
    NOT_ON_ADC,     /*  72 - PF_0 */
    NOT_ON_ADC,     /*  73 - PF_2 */
    NOT_ON_ADC,     /*  74 - PQ_1 */
    NOT_ON_ADC,     /*  75 - PQ_2 */
    ADC_CTL_CH5,    /*  76 - PD_6 */
    ADC_CTL_CH4,    /*  77 - PD_7 */
    ADC_CTL_CH7,    /*  78 - PD_4 */
    ADC_CTL_CH21,   /*  79 - PE_7 */
    ADC_CTL_CH22,   /*  80 - PP_7 */
};

#endif
#endif 


/* 
From spms433.pdf
Table 26-5. GPIO Pins and Alternate Functions

             Analog or                           Digital Function (GPIOPCTL PMCx Bit Field Encoding)
 IO    Pin   Special       1       2       3       4       5        6       7        8      11       13       14      15
             Function
 PA0   33       -        U0Rx    I2C9SCL T0CCP0    -        -       -    CAN0Rx      -       -       -         -       -
 PA1   34       -        U0Tx    I2C9SDA T0CCP1    -        -       -    CAN0Tx      -       -       -         -       -
 PA2   35       -        U4Rx    I2C8SCL T1CCP0    -        -       -       -        -       -       -         -   SSI0Clk
 PA3   36       -        U4Tx    I2C8SDA T1CCP1    -        -       -       -        -       -       -         -   SSI0Fss
 PA4   37       -        U3Rx    I2C7SCL T2CCP0    -        -       -       -        -       -       -         -   SSI0XDAT0
 PA5   38       -        U3Tx    I2C7SDA T2CCP1    -        -       -       -        -       -       -         -   SSI0XDAT1
 PA6   40       -        U2Rx    I2C6SCL T3CCP0    -    USB0EPEN    -       -        -       -     SSI0XDAT2   -   EPI0S8
 PA7   41       -        U2Tx    I2C6SDA T3CCP1    -    USB0PFLT    -       -        -    USB0EPEN SSI0XDAT3   -   EPI0S9
 PB0   95    USB0ID      U1Rx    I2C5SCL T4CCP0    -        -       -    CAN1Rx      -       -       -         -       -
 PB1   96    USB0VBUS    U1Tx    I2C5SDA T4CCP1    -        -       -    CAN1Tx      -       -       -         -       -
 PB2   91       -          -     I2C0SCL T5CCP0    -        -       -       -        -       -       -      USB0STP EPI0S27
 PB3   92       -          -     I2C0SDA T5CCP1    -        -       -       -        -       -       -      USB0CLK EPI0S28
 PB4   121   AIN10       U0CTS   I2C5SCL   -       -        -       -       -        -       -       -         -    SSI1Fss
 PB5   120   AIN11       U0RTS   I2C5SDA   -       -        -       -       -        -       -       -         -    SSI1Clk
 PC0   100      -       TCK/SWCL   -       -       -        -       -       -        -       -       -         -       -
 PC1   99       -       TMS/SWDIO  -       -       -        -       -       -        -       -       -         -       -
 PC2   98       -         TDI      -       -       -        -       -       -        -       -       -         -       -
 PC3   97       -       TDO/SW     -       -       -        -       -       -        -       -       -         -       -
 PC4   25      C1-       U7Rx      -       -       -        -       -       -        -       -       -         -    EPI0S7
 PC5   24      C1+       U7Tx      -       -       -        -       -    RTCCLK      -       -       -         -    EPI0S6
 PC6   23      C0+       U5Rx      -       -       -        -       -       -        -       -       -         -    EPI0S5
 PC7   22      C0-       U5Tx      -       -       -        -       -       -        -       -       -         -    EPI0S4
 PD0   1     AIN15         -     I2C7SCL T0CCP0    -      C0o       -       -        -       -       -         -    SSI2XDAT1
 PD1   2     AIN14         -     I2C7SDA T0CCP1    -      C1o       -       -        -       -       -         -    SSI2XDAT0
 PD2   3     AIN13         -     I2C8SCL T1CCP0    -      C2o       -       -        -       -       -         -    SSI2Fss
 PD3   4     AIN12         -     I2C8SDA T1CCP1    -        -       -       -        -       -       -         -    SSI2Clk
 PD4   125    AIN7       U2Rx      -     T3CCP0    -        -       -       -        -       -       -         -    SSI1XDAT2
 PD5   126    AIN6       U2Tx      -     T3CCP1    -        -       -       -        -       -       -         -    SSI1XDAT3
 PD6   127    AIN5       U2RTS     -     T4CCP0    -    USB0EPEN    -       -        -       -       -         -    SSI2XDAT3
 PD7   128    AIN4       U2CTS     -     T4CCP1    -    USB0PFLT    -       -       NMI      -       -         -    SSI2XDAT2
 PE0   15     AIN3       U1RTS     -       -       -        -       -       -        -       -       -         -       -
 PE1   14     AIN2       U1DSR     -       -       -        -       -       -        -       -       -         -       -
 PE2   13     AIN1       U1DCD     -       -       -        -       -       -        -       -       -         -       -
 PE3   12     AIN0       U1DTR     -       -       -        -       -       -        -       -       -         -       -
 PE4   123    AIN9       U1RI      -       -       -        -       -       -        -       -       -         -      SSI1XDAT0
 PE5   124    AIN8         -       -       -       -        -       -       -        -       -       -         -      SSI1XDAT1
 PF0   42       -          -       -       -       -    EN0LED0 M0PWM0      -        -       -       -      SSI3XDAT1  TRD2
 PF1   43       -          -       -       -       -    EN0LED2 M0PWM1      -        -       -       -      SSI3XDAT0  TRD1
 PF2   44       -          -       -       -       -        -    M0PWM2     -        -       -       -      SSI3Fss    TRD0
 PF3   45       -          -       -       -       -        -    M0PWM3     -        -       -       -      SSI3Clk    TRCLK
 PF4   46       -          -       -       -       -    EN0LED1 M0FAULT0    -        -       -       -      SSI3XDAT2  TRD3
 PG0   49       -          -    I2C1SCL    -       -    EN0PPS M0PWM4       -        -       -       -         -      EPI0S11
 PG1   50       -          -    I2C1SDA    -       -        -    M0PWM5     -        -       -       -         -      EPI0S10
 PH0   29       -        U0RTS     -       -       -        -       -       -        -       -       -         -      EPI0S0
 PH1   30       -        U0CTS     -       -       -        -       -       -        -       -       -         -      EPI0S1
 PH2   31       -        U0DCD     -       -       -        -       -       -        -       -       -         -      EPI0S2
 PH3   32       -        U0DSR     -       -       -        -       -       -        -       -       -         -      EPI0S3
 PJ0   116      -        U3Rx      -       -       -    EN0PPS      -       -        -       -       -         -         -
 PJ1   117      -        U3Tx      -       -       -        -       -       -        -       -       -         -         -
 PK0   18    AIN16       U4Rx      -       -       -        -       -       -        -       -       -         -      EPI0S0
 PK1   19    AIN17       U4Tx      -       -       -        -       -       -        -       -       -         -      EPI0S1
 PK2   20    AIN18       U4RTS     -       -       -        -       -       -        -       -       -         -      EPI0S2
 PK3   21    AIN19       U4CTS     -       -       -        -       -       -        -       -       -         -      EPI0S3
 PK4   63       -          -    I2C3SCL    -       -    EN0LED0 M0PWM6      -        -       -       -         -      EPI0S32
 PK5   62       -          -    I2C3SDA    -       -    EN0LED2 M0PWM7      -        -       -       -         -      EPI0S31
 PK6   61       -          -    I2C4SCL    -       -    EN0LED1 M0FAULT1    -        -       -       -         -      EPI0S25
 PK7   60       -        U0RI   I2C4SDA    -       -    RTCCLK M0FAULT2     -        -       -       -         -      EPI0S24
 PL0   81       -          -    I2C2SDA    -       -        -    M0FAULT3   -        -       -       -      USB0D0    EPI0S16
 PL1   82       -          -    I2C2SCL    -       -        -     PhA0      -        -       -       -      USB0D1    EPI0S17
 PL2   83       -          -       -       -       -      C0o     PhB0      -        -       -       -      USB0D2    EPI0S18
 PL3   84       -          -       -       -       -      C1o     IDX0      -        -       -       -      USB0D3    EPI0S19
 PL4   85       -          -       -      T0CCP0    -        -       -      -        -       -       -      USB0D4    EPI0S26
 PL5   86       -          -       -      T0CCP1    -        -       -      -        -       -       -      USB0D5    EPI0S33
 PL6   94    USB0DP        -       -      T1CCP0    -        -       -      -        -       -       -         -         -
 PL7   93    USB0DM        -       -      T1CCP1    -        -       -      -        -       -       -         -         -
 PM0   78       -          -       -      T2CCP0    -        -       -      -        -       -       -         -      EPI0S15
 PM1   77       -          -       -      T2CCP1    -        -       -      -        -       -       -         -      EPI0S14
 PM2   76       -          -       -      T3CCP0    -        -       -      -        -       -       -         -      EPI0S13
 PM3   75       -          -       -      T3CCP1    -        -       -      -        -       -       -         -      EPI0S12
 PM4   74    TMPR3       U0CTS     -      T4CCP0    -        -       -      -        -       -       -         -         -
 PM5   73    TMPR2       U0DCD     -      T4CCP1    -        -       -      -        -       -       -         -         -
 PM6   72    TMPR1       U0DSR     -      T5CCP0    -        -       -      -        -       -       -         -         -
 PM7   71    TMPR0       U0RI      -      T5CCP1    -        -       -      -        -       -       -         -         -
 PN0   107      -        U1RTS     -        -       -        -       -      -        -       -       -         -         -
 PN1   108       -       U1CTS     -        -       -        -       -      -        -       -       -         -         -
 PN2   109       -       U1DCD   U2RTS      -       -        -       -      -        -       -       -         -      EPI0S29
 PN3   110       -       U1DSR   U2CTS      -       -        -       -      -        -       -       -         -      EPI0S30
 PN4   111       -       U1DTR   U3RTS   I2C2SDA    -        -       -      -        -       -       -         -      EPI0S34
 PN5   112       -       U1RI    U3CTS   I2C2SCL    -        -       -      -        -       -       -         -      EPI0S35
 PP0   118      C2+      U6Rx      -        -       -        -       -      -        -       -       -         -      SSI3XDAT2
 PP1   119      C2-      U6Tx      -        -       -        -       -      -        -       -       -         -      SSI3XDAT3
 PP2   103       -       U0DTR     -        -       -        -       -      -        -       -       -     USB0NXT    EPI0S29
 PP3   104       -       U1CTS    U0DCD     -       -        -       -   RTCCLK      -       -       -     USB0DIR    EPI0S30
 PP4   105       -       U3RTS    U0DSR     -       -        -       -      -        -       -       -     USB0D7       -
 PP5   106       -       U3CTS   I2C2SCL    -       -        -       -      -        -       -       -     USB0D6       -
 PQ0     5       -         -       -        -       -        -       -      -        -       -       -     SSI3Clk    EPI0S20
 PQ1     6       -         -       -        -       -        -       -      -        -       -       -     SSI3Fss    EPI0S21
 PQ2    11       -         -       -        -       -        -       -      -        -       -       -     SSI3XDAT0  EPI0S22
 PQ3    27       -         -       -        -       -        -       -      -        -       -       -     SSI3XDAT1  EPI0S23
 PQ4    102      -       U1Rx      -        -       -        -       -   DIVSCLK     -       -       -        -         -

a. The TMPRn signals are digital signals enabled and configured by the Hibernation module. All other signals listed in this column are analog
    signals.
b. The digital signals that are shaded gray are the power-on default values for the corresponding GPIO pin. Encodings 9, 10, and 12 are
    not used on this device.

*/

/* tools
    table extraction from user manual
          pdftotext -f 1813 -l 1815 -layout  spms433.pdf 

    look for duplicate pin declares with
       grep "static const uint8_t P._" pins_energia.h  | awk '{print $4}' | sort | uniq -d
*/


