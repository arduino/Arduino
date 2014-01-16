


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
// J29 and J30
static const uint8_t PE_2 = 2;
static const uint8_t PH_6 = 3;
static const uint8_t PH_7 = 4;
static const uint8_t PN_7 = 5;
static const uint8_t PF_3 = 6;
static const uint8_t PG_7 = 7;
static const uint8_t PJ_2 = 8;
static const uint8_t PB_4 = 9;
static const uint8_t PJ_7 = 10;
static const uint8_t PN_2 = 11;
static const uint8_t PN_1 = 12;
static const uint8_t PN_0 = 13;
static const uint8_t PG_4 = 14;
static const uint8_t PG_5 = 15;
//                    RST = 16
//                     NC = 17
static const uint8_t PQ_7 = 18;
static const uint8_t PS_2 = 19;
//                    GND = 20
//                     5v = 21
//                    GND = 22
static const uint8_t PE_3 = 23;
static const uint8_t PE_6 = 24;
static const uint8_t PK_0 = 25;
static const uint8_t PK_1 = 26;
static const uint8_t PK_2 = 27; 
static const uint8_t PK_3 = 28;
static const uint8_t PE_0 = 29; 
static const uint8_t PE_1 = 30;

static const uint8_t PM_7 = 31;
static const uint8_t PD_2 = 32;
static const uint8_t PQ_3 = 33;
static const uint8_t PS_1 = 34;
static const uint8_t PS_0 = 35;
static const uint8_t PL_4 = 36;
static const uint8_t PL_5 = 37;
static const uint8_t PS_3 = 38;
static const uint8_t PD_3 = 39;
static const uint8_t PM_5 = 40;
// BOOSTER PACK 1 end

// BOOSTER PACK 2 
// J6
//                 J6_VCC = 41;
static const uint8_t PD_0 = 42;
static const uint8_t PJ_0 = 43; // J12 2-3, BP2_RX
static const uint8_t PJ_1 = 44; // J13 2-3, BP2_TX
static const uint8_t PT_0 = 45;
static const uint8_t PT_1 = 46;
static const uint8_t PA_2 = 47;
static const uint8_t PS_6 = 48;
static const uint8_t PS_7 = 49;
static const uint8_t PB_5 = 50;
// J6 

// J9
static const uint8_t PD_5 = 51;
static const uint8_t PP_6 = 52;
static const uint8_t PH_5 = 53;
static const uint8_t PA_5 = 54; // J16 1-2
static const uint8_t PA_4 = 55; // J17 1-2
//                  RESET = 56;
static const uint8_t PE_4 = 57;
static const uint8_t PJ_3 = 58;
static const uint8_t PD_1 = 59;
//                    GND = 60;
// J9 end 
// BOOSTER PACK 2 end

// LEDs
static const uint8_t PN_5 = 61;
static const uint8_t PQ_4 = 62;
static const uint8_t PF_1 = 63;
static const uint8_t PK_4 = 64;
static const uint8_t PK_6 = 65;

static const uint8_t RED_LED      = 61; 
static const uint8_t BLUE_LED     = 62; 
static const uint8_t GREEN_LED    = 18;
static const uint8_t SPEED_LED    = 63;
static const uint8_t LINK_LED     = 64;
static const uint8_t ACTIVITY_LED = 65;
// LEDs end


// pushbuttons
static const uint8_t PN_3 = 66; // up
static const uint8_t PE_5 = 67; // down
static const uint8_t PP_1 = 68; // sel

static const uint8_t PUSH1     = 66; 
static const uint8_t PUSH_UP   = 66; 
static const uint8_t PUSH2     = 67;
static const uint8_t PUSH_DOWN = 67;
static const uint8_t PUSH3     = 68;
static const uint8_t PUSH_SEL  = 68;
// pushbuttons end


static const uint8_t A0 =  29; //PE_3
static const uint8_t A1 =  28; //PE_2
static const uint8_t A2 =  27; //PE_1
static const uint8_t A3 =  18; //PE_0
static const uint8_t A4 =  26; //PD_3
static const uint8_t A5 =  25; //PD_2
static const uint8_t A6 =  24; //PD_1
static const uint8_t A7 =  23; //PD_0
static const uint8_t A8 =   6; //PE_5
static const uint8_t A9 =   5; //PE_4
static const uint8_t A10 =  7; //PB_4
static const uint8_t A11 =  2; //PB_5

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
        (uint32_t) GPIO_PORTR_BASE, // 16
        (uint32_t) GPIO_PORTS_BASE, // 17
        (uint32_t) GPIO_PORTT_BASE, // 18
};
const uint8_t digital_pin_to_timer[] = {
        NOT_ON_TIMER,   /*  dummy */
        NOT_ON_TIMER,   /*  1 - 3.3V */
        T1B0,           /*  2 - PE2 */
        T2A0,           /*  3 - PH6 */
        T2B,            /*  4 - PH7 */
        NOT_ON_TIMER,   /*  5 - PN7 */
        NOT_ON_TIMER,   /*  6 - PF3 */
        T1A0,           /*  7 - PG7 */
        NOT_ON_TIMER,   /*  8 - PJ2 */
        NOT_ON_TIMER,   /*  9 - PB4 */
        NOT_ON_TIMER,   /*  10 - PJ7 */
        NOT_ON_TIMER,   /*  11 - PN2 */
        NOT_ON_TIMER,   /*  12 - PN1 */
        NOT_ON_TIMER,   /*  13 - PN0 */
        T0A0,           /*  14 - PG4 */
        T0B0,           /*  15 - PG5 */
        NOT_ON_TIMER,   /*  16 - RST */
        NOT_ON_TIMER,   /*  17 - NC */
        NOT_ON_TIMER,   /*  18 - PQ7 */
        T3A,            /*  19 - PS4 */
        NOT_ON_TIMER,   /*  20 - GND */
        NOT_ON_TIMER,   /*  21 - VBUS */
        NOT_ON_TIMER,   /*  22 - GND */
        WT2A,           /*  23 - PE3 */
        WT2B,           /*  24 - PE6 */
        WT3A,           /*  25 - PK0 */
        WT3B,           /*  26 - PK1 */
        NOT_ON_TIMER,   /*  27 - PK2 */
        NOT_ON_TIMER,   /*  28 - PK3 */
        NOT_ON_TIMER,   /*  29 - PE0 */
        T0B1,           /*  30 - PE1 */
        T2A1,           /*  31 - PM7 */
        WT5B,           /*  32 - PD2 */
        WT5A,           /*  33 - PQ3 */
        WT1B,           /*  34 - PS1 */
        WT1A,           /*  35 - PS0 */
        WT0B,           /*  36 - PL4 */
        WT0A,           /*  37 - PL5 */
        T3B,            /*  38 - PS3 */
        T1B1,           /*  39 - PD3 */
        T1A1,           /*  40 - PM5 */
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
};

const uint8_t digital_pin_to_port[] = {
        NOT_A_PIN,  /*  dummy */
        NOT_A_PIN,  /*  1 - 3.3V */
        PE,         /*  2 - PE2 */
        PH,         /*  3 - PH6 */
        PH,         /*  4 - PH7 */
        PN,         /*  5 - PN7 */
        PF,         /*  6 - PF3 */
        PG,         /*  7 - PG7 */
        PJ,         /*  8 - PJ2 */
        PB,         /*  9 - PB4 */
        PJ,         /*  10 - PJ7 */
        PN,         /*  11 - PN2 */
        PN,         /*  12 - PN1 */
        PN,         /*  13 - PN0 */
        PG,         /*  14 - PG4 */
        PG,         /*  15 - PG5 */
        NOT_A_PIN,  /*  16 - RST */
        NOT_A_PIN,  /*  17 - NC */
        PQ,         /*  18 - PQ7 */
        PS,         /*  19 - PS2 */
        NOT_A_PIN,  /*  20 - GND */
        NOT_A_PIN,  /*  21 - VBUS */
        NOT_A_PIN,  /*  22 - GND */
        PE,         /*  23 - PE3 */
        PE,         /*  24 - PE6 */
        PK,         /*  25 - PK0 */
        PK,         /*  26 - PK1 */
        PK,         /*  27 - PK2 */
        PK,         /*  28 - PK3 */
        PE,         /*  29 - PE0 */
        PE,         /*  30 - PE1 */
        PM,         /*  31 - PM7 */
        PD,         /*  32 - PD2 */
        PQ,         /*  33 - PQ3 */
        PS,         /*  34 - PS1 */
        PS,         /*  35 - PS0 */
        PL,         /*  36 - PL4 */
        PL,         /*  37 - PL5 */
        PS,         /*  38 - PS3 */
        PD,         /*  39 - PD3 */
        PM,         /*  40 - PM5 */
        NOT_A_PIN,  /*  41 - J6_VCC */
        PD,         /*  42 - PD_0 */
        PJ,         /*  43 - PJ_0 BP2_RX */
        PJ,         /*  44 - PJ_1 BP2_TX */
        PT,         /*  45 - PT_0 */
        PT,         /*  46 - PT_1 */
        PA,         /*  47 - PA_2 */
        PS,         /*  48 - PS_6 */
        PS,         /*  49 - PS_7 */
        PB,         /*  50 - PB_5 */
        PD,         /*  51 - PD_5 */
        PP,         /*  52 - PP_6 */
        PH,         /*  53 - PH_5 */
        PA,         /*  54 - PA_5 */
        PA,         /*  55 - PA_4 */
        NOT_A_PIN,  /*  56 - RESET */
        PE,         /*  57 - PE_4 */
        PJ,         /*  58 - PJ_3 */
        PD,         /*  59 - PD_1 */
        NOT_A_PIN,  /*  60 - GND */
        PN,         /*  61 - PN_5 */
        PQ,         /*  62 - PQ_4 */
        PF,         /*  63 - PF_1 */
        PK,         /*  64 - PK_4 */
        PK,         /*  65 - PK_6 */
        PN,         /*  66 - PN_3 */
        PE,         /*  67 - PE_5 */
        PP,         /*  68 - PP_1 */
};
const uint8_t digital_pin_to_bit_mask[] = {
        NOT_A_PIN,  /*  dummy */
        NOT_A_PIN,  /*  1 - 3.3V */
        BV(2),      /*  2 - PE2 */
        BV(6),      /*  3 - PH6 */
        BV(7),      /*  4 - PH7 */
        BV(7),      /*  5 - PN7 */
        BV(3),      /*  6 - PF3 */
        BV(7),      /*  7 - PG7 */
        BV(2),      /*  8 - PJ2 */
        BV(4),      /*  9 - PB4 */
        BV(7),      /*  10 - PJ7 */
        BV(2),      /*  11 - PN2 */
        BV(1),      /*  12 - PN1 */
        BV(0),      /*  13 - PN0 */
        BV(4),      /*  14 - PG4 */
        BV(5),      /*  15 - PG5 */
        NOT_A_PIN,  /*  16 - RST */
        NOT_A_PIN,  /*  17 - NC */
        BV(7),      /*  18 - PQ7 */
        BV(2),      /*  19 - PS2 */
        NOT_A_PIN,  /*  20 - GND */
        NOT_A_PIN,  /*  21 - VBUS */
        NOT_A_PIN,  /*  22 - GND */
        BV(2),      /*  23 - PE2 */
        BV(6),      /*  24 - PE6 */
        BV(0),      /*  25 - PK0 */
        BV(1),      /*  26 - PK1 */
        BV(2),      /*  27 - PK2 */
        BV(3),      /*  28 - PK3 */
        BV(0),      /*  29 - PE0 */
        BV(1),      /*  30 - PE1 */
        BV(7),      /*  31 - PM7 */
        BV(2),      /*  32 - PD2 */
        BV(3),      /*  33 - PQ3 */
        BV(1),      /*  34 - PS1 */
        BV(0),      /*  35 - PS0 */
        BV(4),      /*  36 - PL4 */
        BV(5),      /*  37 - PL5 */
        BV(3),      /*  38 - PS3 */
        BV(3),      /*  39 - PD3 */
        BV(5),      /*  40 - PM5 */
        NOT_A_PIN,  /*  41 - J6_VCC */
        BV(0),      /*  42 - PD_0 */
        BV(0),      /*  43 - PJ_0 BP2_RX */
        BV(1),      /*  44 - PJ_0 BP2_TX */
        BV(0),      /*  45 - PT_0 */
        BV(1),      /*  46 - PT_1 */
        BV(2),      /*  47 - PA_2 */
        BV(6),      /*  48 - PS_6 */
        BV(7),      /*  49 - PS_7 */
        BV(5),      /*  50 - PB_5 */
        BV(5),      /*  51 - PD_5 */
        BV(6),      /*  52 - PP_6 */
        BV(5),      /*  53 - PH_5 */
        BV(5),      /*  54 - PA_5 */
        BV(4),      /*  55 - PA_4 */
        NOT_A_PIN,  /*  56 - RESET */
        BV(4),      /*  57 - PE_4 */
        BV(3),      /*  58 - PJ_3 */
        BV(1),      /*  59 - PD_1 */
        NOT_A_PIN,  /*  60 - GND */
        BV(5),      /*  61 - PN_5 */
        BV(4),      /*  62 - PQ_4 */
        BV(1),      /*  63 - PF_1 */
        BV(4),      /*  64 - PK_4 */
        BV(6),      /*  65 - PK_6 */
        BV(3),      /*  66 - PN_3 */
        BV(5),      /*  67 - PE_5 */
        BV(1),      /*  68 - PP_1 */
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
        NOT_ON_ADC,     /*  dummy   */
        NOT_ON_ADC,     /*  1 - 3.3V*/
        ADC_CTL_CH11,   /*  2 - PB5 */
        NOT_ON_ADC,     /*  3 - PB0 */
        NOT_ON_ADC,     /*  4 - PB1 */
        ADC_CTL_CH9,    /*  5 - PE4 */
        ADC_CTL_CH8,    /*  6 - PE5 */
        ADC_CTL_CH10,   /*  7 - PB4 */
        NOT_ON_ADC,     /*  8 - PA5 */
        NOT_ON_ADC,     /*  9 - PA6 */
        NOT_ON_ADC,     /*  10 - PA7 */
        NOT_ON_ADC,     /*  11 - PA2 */
        NOT_ON_ADC,     /*  12 - PA3 */
        NOT_ON_ADC,     /*  13 - PA4 */
        NOT_ON_ADC,     /*  14 - PB6 */
        NOT_ON_ADC,     /*  15 - PB7 */
        NOT_ON_ADC,     /*  16 - RST */
        NOT_ON_ADC,     /*  17 - PF0 */
        ADC_CTL_CH3,    /*  18 - PE0 */
        NOT_ON_ADC,     /*  19 - PB2 */
        NOT_ON_ADC,     /*  20 - GND */
        NOT_ON_ADC,     /*  21 - VBUS */
        NOT_ON_ADC,     /*  22 - GND */
        ADC_CTL_CH7,    /*  23 - PD0 */
        ADC_CTL_CH6,    /*  24 - PD1 */
        ADC_CTL_CH5,    /*  25 - PD2 */
        ADC_CTL_CH4,    /*  26 - PD3 */
        ADC_CTL_CH2,    /*  27 - PE1 */
        ADC_CTL_CH1,    /*  28 - PE2 */
        ADC_CTL_CH0,    /*  29 - PE3 */
        NOT_ON_ADC,     /*  30 - PF1 */
        NOT_ON_ADC,     /*  31 - PF4 */
        NOT_ON_ADC,     /*  32 - PD7 */
        NOT_ON_ADC,     /*  33 - PD6 */
        NOT_ON_ADC,     /*  34 - PC7 */
        NOT_ON_ADC,     /*  35 - PC6 */
        NOT_ON_ADC,     /*  36 - PC5 */
        NOT_ON_ADC,     /*  37 - PC4 */
        NOT_ON_ADC,     /*  38 - PB3 */
        NOT_ON_ADC,     /*  39 - PF3 */
        NOT_ON_ADC,     /*  40 - PF2 */
        NOT_ON_ADC,     /*  41 - J6_VCC */
        NOT_ON_ADC,     /*  42 - PD_0 */
        NOT_ON_ADC,     /*  43 - PJ_0 BP2_RX */
        NOT_ON_ADC,     /*  44 - PJ_1 BP2_TX */
        NOT_ON_ADC,     /*  45 - PT_0 */
        NOT_ON_ADC,     /*  46 - PT_1 */
        NOT_ON_ADC,     /*  47 - PA_2 */
        NOT_ON_ADC,     /*  48 - PS_6 */
        NOT_ON_ADC,     /*  49 - PS_7 */
        NOT_ON_ADC,     /*  50 - PB_5 */
        NOT_ON_ADC,     /*  51 - PD_5 */
        NOT_ON_ADC,     /*  52 - PP_6 */
        NOT_ON_ADC,     /*  53 - PH_5 */
        NOT_ON_ADC,     /*  54 - PA_5 */
        NOT_ON_ADC,     /*  55 - PA_4 */
        NOT_ON_ADC,     /*  56 - RESET */
        NOT_ON_ADC,     /*  57 - PE_4 */
        NOT_ON_ADC,     /*  58 - PJ_3 */
        NOT_ON_ADC,     /*  59 - PD_1 */
        NOT_ON_ADC,     /*  60 - GND */
        NOT_ON_ADC,     /*  61 - PN_5 */
        NOT_ON_ADC,     /*  62 - PQ_4 */
        NOT_ON_ADC,     /*  63 - PF_1 */
        NOT_ON_ADC,     /*  64 - PK_4 */
        NOT_ON_ADC,     /*  65 - PK_6 */
        NOT_ON_ADC,     /*  66 - PN_3 */
        NOT_ON_ADC,     /*  67 - PE_5 */
        NOT_ON_ADC,     /*  68 - PP_1 */
};
#endif
#endif 
