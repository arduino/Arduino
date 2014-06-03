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


// energia pin definition begin, needed by tool digital_pin_to_template.py
// Pin names based on the 
// board's silkscreen
//
// BOOSTER PACK 1
// X8 and X9

//                   3.3v = 1;  // X8_01
static const uint8_t PE_4 = 2;  // X8_03
static const uint8_t PC_4 = 3;  // X8_05
static const uint8_t PC_5 = 4;  // X8_07
static const uint8_t PC_6 = 5;  // X8_09
static const uint8_t PE_5 = 6;  // X8_11
static const uint8_t PD_3 = 7;  // X8_13
static const uint8_t PC_7 = 8;  // X8_15
static const uint8_t PB_2 = 9;  // X8_17
static const uint8_t PB_3 = 10; // X8_19
static const uint8_t PP_2 = 11; // X9_20
static const uint8_t PN_3 = 12; // X9_18
static const uint8_t PN_2 = 13; // X9_16
static const uint8_t PD_0 = 14; // X9_14
static const uint8_t PD_1 = 15; // X9_12
//                    RST = 16  // X9_10
static const uint8_t PH_3 = 17; // X9_08
static const uint8_t PH_2 = 18; // X9_06
static const uint8_t PM_3 = 19; // X9_04
//                    GND = 20  // X9_02

// X8 and X9
//                     5v = 21  // X8_02
//                    GND = 22  // X8_04
static const uint8_t PE_0 = 23; // X8_06
static const uint8_t PE_1 = 24; // X8_08
static const uint8_t PE_2 = 25; // X8_10
static const uint8_t PE_3 = 26; // X8_12
static const uint8_t PD_7 = 27; // X8_14
static const uint8_t PA_6 = 28; // X8_16
static const uint8_t PM_4 = 29; // X8_18
static const uint8_t PM_5 = 30; // X8_20
static const uint8_t PL_3 = 31; // X9_19
static const uint8_t PL_2 = 32; // X9_17
static const uint8_t PL_1 = 33; // X9_15
static const uint8_t PL_0 = 34; // X9_13
static const uint8_t PL_5 = 35; // X9_11
static const uint8_t PL_4 = 36; // X9_09
static const uint8_t PG_0 = 37; // X9_07
static const uint8_t PF_3 = 38; // X9_05
static const uint8_t PF_2 = 39; // X9_03
static const uint8_t PF_1 = 40; // X9_01
// BOOSTER PACK 1 end

// BOOSTER PACK 2
// X6 and X7
//                   3.3v = 41; // X6_01
static const uint8_t PD_2 = 42; // X6_03
static const uint8_t PP_0 = 43; // X6_05
static const uint8_t PP_1 = 44; // X6_07
static const uint8_t PD_4 = 45; // X6_09 jumper JP4 uart
static const uint8_t PD_5 = 46; // X6_11 jumper JP5 uart
static const uint8_t PQ_0 = 47; // X6_13
static const uint8_t PP_4 = 48; // X6_15 
static const uint8_t PN_5 = 49; // X6_17
static const uint8_t PN_4 = 50; // X6_19
static const uint8_t PM_6 = 51; // X7_20
static const uint8_t PQ_1 = 52; // X7_18
static const uint8_t PP_3 = 53; // X7_16
static const uint8_t PQ_3 = 54; // X7_14
static const uint8_t PQ_2 = 55; // X7_12
//                  RESET = 56; // X7_10
static const uint8_t PA_7 = 57; // X7_08
static const uint8_t PP_5 = 58; // X7_06
static const uint8_t PM_7 = 59; // X7_04
//                    GND = 60; // X7_02
// X6 and X7
//                     5v = 61  // X6_02
//                    GND = 62  // X6_04
static const uint8_t PB_4 = 63; // X6_06
static const uint8_t PB_5 = 64; // X6_08
static const uint8_t PK_0 = 65; // X6_10
static const uint8_t PK_1 = 66; // X6_12
static const uint8_t PK_2 = 67; // X6_14
static const uint8_t PK_3 = 68; // X6_16
static const uint8_t PA_4 = 69; // X6_18
static const uint8_t PA_5 = 70; // X6_20
static const uint8_t PK_7 = 71; // X7_19
static const uint8_t PK_6 = 72; // X7_17
static const uint8_t PH_1 = 73; // X7_15
static const uint8_t PH_0 = 74; // X7_13
static const uint8_t PM_2 = 75; // X7_11
static const uint8_t PM_1 = 76; // X7_09
static const uint8_t PM_0 = 77; // X7_07
static const uint8_t PK_5 = 78; // X7_05
static const uint8_t PK_4 = 79; // X7_03
static const uint8_t PG_1 = 80; // X7_01
// BOOSTER PACK 2 end


// LEDs
static const uint8_t PN_1 = 81; // LED1
static const uint8_t PN_0 = 82; // LED2
static const uint8_t PF_4 = 83; // LED3
static const uint8_t PF_0 = 84; // LED4


// pushbuttons
static const uint8_t PJ_0 = 85; // USR_SW1
static const uint8_t PJ_1 = 86; // USR_SW2

// other
static const uint8_t PD_6 = 87; // AIN5
static const uint8_t PA_0 = 88; // JP4
static const uint8_t PA_1 = 89; // JP5
static const uint8_t PA_2 = 90; // X11_06
static const uint8_t PA_3 = 91; // X11_08
static const uint8_t PL_6 = 92; // unrouted
static const uint8_t PL_7 = 93; // unrouted
static const uint8_t PB_0 = 94; // X11_58
static const uint8_t PB_1 = 95; // unrouted

// energia pin definition end

#define D1_LED         PN_1
#define RED_LED        PN_1
#define D2_LED         PN_0
#define GREEN_LED      PN_0
#define D3_LED         PF_4
#define D4_LED         PF_0

#define ACTIVITY_LED      GPIO_PF4_EN0LED1
#define ACTIVITY_LED_BASE GPIO_PORTF_BASE
#define ACTIVITY_LED_PIN  GPIO_PIN_4
#define LINK_LED          GPIO_PF0_EN0LED0
#define LINK_LED_BASE     GPIO_PORTF_BASE
#define LINK_LED_PIN      GPIO_PIN_0

// LEDs end

// pushbuttons
#define PUSH1      PJ_0
#define PUSH2      PJ_1
#define TEMPSENSOR 0

#define USR_SW1    PJ_0
#define USR_SW2    PJ_1
// pushbuttons end

#define A0  PE_3   /* X8_12 */
#define A1  PE_2   /* X8_10 */
#define A2  PE_1   /* X8_08 */
#define A3  PE_0   /* X8_06 */
#define A4  PD_7   /* X8_14 */
#define A5  PD_6   /* AIN5 */
#define A6  PD_5   /* X6_11 */
#define A7  PD_4   /* X6_09 */
#define A8  PE_5   /* X8_11 */
#define A9  PE_4   /* X8_03 */
#define A10 PB_4   /* X6_06 */
#define A11 PB_5   /* X6_08 */
#define A12 PD_3   /* X8_13 */
#define A13 PD_2   /* X6_03 */
#define A14 PD_1   /* X9_12 */
#define A15 PD_0   /* X9_14 */
#define A16 PK_0   /* X6_10 */
#define A17 PK_1   /* X6_12 */
#define A18 PK_2   /* X6_14 */
#define A19 PK_3   /* X6_16 */

/* pins defines by connector
   Using defines instead of 'static const uint8_t' re-uses correct 
   energia pin declares. Also checks that all Px_x are declared.
*/

//      X6_01 3.3v
//      X6_02 5v
#define X6_03 PD_2
//      X6_04 GND
#define X6_05 PP_0
#define X6_5  PP_0
#define X6_06 PB_4
#define X6_6  PB_4
#define X6_07 PP_1
#define X6_7  PP_1
#define X6_08 PB_5
#define X6_8  PB_5
#define X6_09 PA_0
#define X6_9  PA_0
#define X6_10 PK_0
#define X6_11 PA_1
#define X6_12 PK_1
#define X6_13 PQ_0
#define X6_14 PK_2
#define X6_15 PP_4
#define X6_16 PK_3
#define X6_17 PN_5
#define X6_18 PA_4
#define X6_19 PN_4
#define X6_20 PA_5

#define X7_01 PG_1
//      X7_02 GND
#define X7_03 PK_4
#define X7_3  PK_4
#define X7_04 PM_7
#define X7_4  PM_7
#define X7_05 PK_5
#define X7_5  PK_5
#define X7_06 PP_5
#define X7_6  PP_5
#define X7_07 PM_0
#define X7_7  PM_0
#define X7_08 PA_7
#define X7_8  PA_7
#define X7_09 PM_1
#define X7_9  PM_1
//      X7_10 RESET
#define X7_11 PM_2
#define X7_12 PQ_2
#define X7_13 PH_0
#define X7_14 PQ_3
#define X7_15 PH_1
#define X7_16 PP_3
#define X7_17 PK_6
#define X7_18 PQ_1
#define X7_19 PK_7
#define X7_20 PM_6

//      X8_01 3.3v
//      X8_02 5v
#define X8_03 PE_4
//      X8_04 GND
#define X8_05 PC_4
#define X8_5  PC_4
#define X8_06 PE_0
#define X8_6  PE_0
#define X8_7  PC_5
#define X8_7  PC_5
#define X8_08 PE_1
#define X8_8  PE_1
#define X8_09 PC_6
#define X8_9  PC_6
#define X8_10 PE_2
#define X8_11 PE_5
#define X8_12 PE_3
#define X8_13 PD_3
#define X8_14 PD_7
#define X8_15 PC_7
#define X8_16 PA_6
#define X8_17 PB_2
#define X8_18 PM_4
#define X8_19 PB_3
#define X8_20 PM_5

#define X9_01 PF_1
//      X9_02 GND
#define X9_03 PF_2
#define X9_3  PF_2
#define X9_04 PM_3
#define X9_4  PM_3
#define X9_05 PF_3
#define X9_5  PF_3
#define X9_06 PH_2
#define X9_6  PH_2
#define X9_07 PG_0
#define X9_7  PG_0
#define X9_08 PH_3
#define X9_8  PH_3
#define X9_09 PL_4
#define X9_9  PL_4
//      X9_10 RST
#define X9_11 PL_5
#define X9_12 PD_1
#define X9_13 PL_0
#define X9_14 PD_0
#define X9_15 PL_1
#define X9_16 PN_2
#define X9_17 PL_2
#define X9_18 PN_3
#define X9_19 PL_3
#define X9_20 PP_2


//      X11_01 3.3V
//      X11_02 5.0V
//      X11_03 GND
//      X11_04 GND
#define X11_05 PB_4
#define X11_5  PB_4
#define X11_06 PA_2
#define X11_6  PA_2
#define X11_07 PB_5
#define X11_7  PB_5
#define X11_08 PA_3
#define X11_8  PA_3
#define X11_09 PH_0
#define X11_9  PH_0
#define X11_10 PA_4
#define X11_11 PH_1
#define X11_12 PA_5
#define X11_13 PH_2
#define X11_14 PE_0
#define X11_15 PH_3
#define X11_16 PE_1
#define X11_17 PC_7
#define X11_18 PE_2
#define X11_19 PC_6
#define X11_20 PE_3
#define X11_21 PC_5
#define X11_22 PE_4
#define X11_23 PC_4
#define X11_24 PE_5
#define X11_25 PA_6
#define X11_26 PK_0
#define X11_27 PA_7
#define X11_28 PK_1
#define X11_29 PG_1
#define X11_30 PK_2
#define X11_31 PG_0
#define X11_32 PK_3
#define X11_33 PM_3
//      X11_34 VREF
//      X11_35 GND
//      X11_36 GND
#define X11_37 PM_2
#define X11_38 PD_5
#define X11_39 PM_1
#define X11_40 PD_4
#define X11_41 PM_0
#define X11_42 PD_7
#define X11_43 PL_0
#define X11_44 PD_6
#define X11_45 PL_1
#define X11_46 PD_3
#define X11_47 PL_2
#define X11_48 PD_1
#define X11_49 PL_3
#define X11_50 PD_0
#define X11_51 PQ_0
#define X11_52 PD_2
#define X11_53 PQ_1
#define X11_54 PP_0
#define X11_55 PQ_2
#define X11_56 PP_1
#define X11_57 PQ_3
#define X11_58 PB_0
#define X11_59 PK_7
//      TARGET_VBUS
#define X11_61 GND
#define X11_62 GND
#define X11_63 PK_6
#define X11_64 PF_4
#define X11_65 PL_4
#define X11_66 PF_0
#define X11_67 PB_2
#define X11_68 PF_1
#define X11_69 PB_3
#define X11_70 PF_2
#define X11_71 PP_2
#define X11_72 PF_3
#define X11_73 PP_3
#define X11_74 PA_0
#define X11_75 PK_5
#define X11_76 PA_1
#define X11_77 PK_4
#define X11_78 PP_4
#define X11_79 PL_5
#define X11_80 PP_5
#define X11_81 PN_4
#define X11_82 PJ_0
#define X11_83 PN_5
#define X11_84 PJ_1
#define X11_85 PN_0
#define X11_86 PM_7
#define X11_87 PN_1
#define X11_88 PM_6
#define X11_89 PN_2
#define X11_90 PM_5
#define X11_91 PN_3
#define X11_92 PM_4
#define X11_93 PQ_4
#define X11_99 PQ_40
//      X11_94 TARGET_RESET
//      X11_95 WAKE
//      X11_96 GND
//      X11_97 5.0V
//      X11_98 3.3V


// end connector pin defines

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



const uint32_t timer_to_offset[] = {
    TIMER0, // 0
    TIMER0, // 1
    TIMER0, // 2
    TIMER0, // 3
    TIMER0, // 4
    TIMER0, // 5
    TIMER1, // 6
    TIMER1, // 7
    TIMER1, // 8
    TIMER1, // 9
    TIMER1, // 10
    TIMER1, // 11
    TIMER2, // 12
    TIMER2, // 13
    TIMER2, // 14
    TIMER2, // 15
    TIMER3, // 16
    TIMER3, // 17
    TIMER3, // 18
    TIMER3, // 19
    TIMER3, // 20
    TIMER3, // 21
    TIMER4, // 22
    TIMER4, // 23
    TIMER4, // 24
    TIMER4, // 25
    TIMER4, // 26
    TIMER4, // 27
    TIMER5, // 28
    TIMER5, // 29
    TIMER5, // 30
    TIMER5  // 31
};

const uint8_t timer_to_ab[] = {
    TIMA, // 0
    TIMA, // 1
    TIMA, // 2
    TIMB, // 3
    TIMB, // 4
    TIMB, // 5
    TIMA, // 6
    TIMA, // 7
    TIMA, // 8
    TIMB, // 9
    TIMB, // 10
    TIMB, // 11
    TIMA, // 12
    TIMA, // 13
    TIMB, // 14
    TIMB, // 15
    TIMA, // 16
    TIMA, // 17
    TIMA, // 18
    TIMB, // 19
    TIMB, // 20
    TIMB, // 21
    TIMA, // 22
    TIMA, // 23
    TIMA, // 24
    TIMB, // 25
    TIMB, // 26
    TIMB, // 27
    TIMA, // 28
    TIMA, // 29
    TIMB, // 30
    TIMB  // 31
};
const uint32_t timer_to_pin_config[] = {
    GPIO_PD0_T0CCP0, //  0
    GPIO_PA0_T0CCP0, //  1
    GPIO_PL4_T0CCP0, //  2
    GPIO_PD1_T0CCP1, //  3
    GPIO_PA1_T0CCP1, //  4
    GPIO_PL5_T0CCP1, //  5
    GPIO_PD2_T1CCP0, //  6
    GPIO_PA2_T1CCP0, //  7
    GPIO_PL6_T1CCP0, //  8
    GPIO_PD3_T1CCP1, //  9
    GPIO_PA3_T1CCP1, //  10
    GPIO_PL7_T1CCP1, //  11
    GPIO_PA4_T2CCP0, //  12
    GPIO_PM0_T2CCP0, //  13
    GPIO_PA5_T2CCP1, //  14
    GPIO_PM1_T2CCP1, //  15
    GPIO_PA6_T3CCP0, //  16
    GPIO_PM2_T3CCP0, //  17
    GPIO_PD4_T3CCP0, //  18
    GPIO_PA7_T3CCP1, //  19
    GPIO_PM3_T3CCP1, //  20
    GPIO_PD5_T3CCP1, //  21
    GPIO_PM4_T4CCP0, //  22
    GPIO_PB0_T4CCP0, //  23
    GPIO_PD6_T4CCP0, //  24
    GPIO_PM5_T4CCP1, //  25
    GPIO_PB1_T4CCP1, //  26
    GPIO_PD7_T4CCP1, //  27
    GPIO_PM6_T5CCP0, //  28
    GPIO_PB2_T5CCP0, //  29
    GPIO_PM7_T5CCP1, //  30
    GPIO_PB3_T5CCP1, //  31
};

const uint8_t digital_pin_to_timer[]      = {
    NOT_ON_TIMER,   // dummy 
    NOT_ON_TIMER,   // 01 - 3.3v       X8_01   
    NOT_ON_TIMER,   // 02 - PE_4       X8_03
    NOT_ON_TIMER,   // 03 - PC_4       X8_05
    NOT_ON_TIMER,   // 04 - PC_5       X8_07
    NOT_ON_TIMER,   // 05 - PC_6       X8_09
    NOT_ON_TIMER,   // 06 - PE_5       X8_11
    T1CCP1_0,       // 07 - PD_3       X8_13
    NOT_ON_TIMER,   // 08 - PC_7       X8_15
    T5CCP0_1,       // 09 - PB_2       X8_17
    T5CCP1_1,       // 10 - PB_3       X8_19
    NOT_ON_TIMER,   // 11 - PP_2       X9_20
    NOT_ON_TIMER,   // 12 - PN_3       X9_18
    NOT_ON_TIMER,   // 13 - PN_2       X9_16
    T0CCP0_1,       // 14 - PD_0       X9_14
    T0CCP1_0,       // 15 - PD_1       X9_12
    NOT_ON_TIMER,   // 16 - RST        X9_10
    NOT_ON_TIMER,   // 17 - PH_3       X9_08
    NOT_ON_TIMER,   // 18 - PH_2       X9_06
    T3CCP1_1,       // 19 - PM_3       X9_04
    NOT_ON_TIMER,   // 20 - GND        X9_02
    NOT_ON_TIMER,   // 21 - 5v         X8_02
    NOT_ON_TIMER,   // 22 - GND        X8_04
    NOT_ON_TIMER,   // 23 - PE_0       X8_06
    NOT_ON_TIMER,   // 24 - PE_1       X8_08
    NOT_ON_TIMER,   // 25 - PE_2       X8_10
    NOT_ON_TIMER,   // 26 - PE_3       X8_12
    T4CCP1_2,       // 27 - PD_7       X8_14
    T3CCP0_0,       // 28 - PA_6       X8_16
    T4CCP0_0,       // 29 - PM_4       X8_18
    T4CCP1_0,       // 30 - PM_5       X8_20
    NOT_ON_TIMER,   // 31 - PL_3       X9_19
    NOT_ON_TIMER,   // 32 - PL_2       X9_17
    NOT_ON_TIMER,   // 33 - PL_1       X9_15
    NOT_ON_TIMER,   // 34 - PL_0       X9_13
    T0CCP1_2,       // 35 - PL_5       X9_11
    T0CCP0_2,       // 36 - PL_4       X9_09
    NOT_ON_TIMER,   // 37 - PG_0       X9_07
    NOT_ON_TIMER,   // 38 - PF_3       X9_05
    NOT_ON_TIMER,   // 39 - PF_2       X9_03
    NOT_ON_TIMER,   // 40 - PF_1       X9_01
    NOT_ON_TIMER,   // 41 - 3.3v       X6_01
    T1CCP0_0,       // 42 - PD_2       X6_03
    NOT_ON_TIMER,   // 43 - PP_0       X6_05
    NOT_ON_TIMER,   // 44 - PP_1       X6_07
    T3CCP0_2,       // 45 - PD_4       X6_09
    T3CCP1_2,       // 46 - PD_5       X6_11
    NOT_ON_TIMER,   // 47 - PQ_0       X6_13
    NOT_ON_TIMER,   // 48 - PP_4       X6_15
    NOT_ON_TIMER,   // 49 - PN_5       X6_17
    NOT_ON_TIMER,   // 50 - PN_4       X6_19
    T5CCP0_0,       // 51 - PM_6       X7_20
    NOT_ON_TIMER,   // 52 - PQ_1       X7_18
    NOT_ON_TIMER,   // 53 - PP_3       X7_16
    NOT_ON_TIMER,   // 54 - PQ_3       X7_14
    NOT_ON_TIMER,   // 55 - PQ_2       X7_12
    NOT_ON_TIMER,   // 56 - RESET      X7_10
    T3CCP1_0,       // 57 - PA_7       X7_08
    NOT_ON_TIMER,   // 58 - PP_5       X7_06
    T5CCP1_0,       // 59 - PM_7       X7_04
    NOT_ON_TIMER,   // 60 - GND        X7_02
    NOT_ON_TIMER,   // 61 - 5v         X6_02
    NOT_ON_TIMER,   // 62 - GND        X6_04
    NOT_ON_TIMER,   // 63 - PB_4       X6_06
    NOT_ON_TIMER,   // 64 - PB_5       X6_08
    NOT_ON_TIMER,   // 65 - PK_0       X6_10
    NOT_ON_TIMER,   // 66 - PK_1       X6_12
    NOT_ON_TIMER,   // 67 - PK_2       X6_14
    NOT_ON_TIMER,   // 68 - PK_3       X6_16
    T2CCP0_0,       // 69 - PA_4       X6_18
    T2CCP1_0,       // 70 - PA_5       X6_20
    NOT_ON_TIMER,   // 71 - PK_7       X7_19
    NOT_ON_TIMER,   // 72 - PK_6       X7_17
    NOT_ON_TIMER,   // 73 - PH_1       X7_15
    NOT_ON_TIMER,   // 74 - PH_0       X7_13
    T3CCP0_1,       // 75 - PM_2       X7_11
    T2CCP1_1,       // 76 - PM_1       X7_09
    T2CCP0_1,       // 77 - PM_0       X7_07
    NOT_ON_TIMER,   // 78 - PK_5       X7_05
    NOT_ON_TIMER,   // 79 - PK_4       X7_03
    NOT_ON_TIMER,   // 80 - PG_1       X7_01
    NOT_ON_TIMER,   // 81 - PN_1       LED1
    NOT_ON_TIMER,   // 82 - PN_0       LED2
    NOT_ON_TIMER,   // 83 - PF_4       LED3
    NOT_ON_TIMER,   // 84 - PF_0       LED4
    NOT_ON_TIMER,   // 85 - PJ_0       USR_SW1
    NOT_ON_TIMER,   // 86 - PJ_1       USR_SW2
    T4CCP0_2,       // 87 - PD_6       AIN5
    T0CCP0_1,       // 88 - PA_0       JP4
    T0CCP1_1,       // 89 - PA_1       JP5
    T1CCP0_1,       // 90 - PA_2       X11_06
    T1CCP1_1,       // 91 - PA_3       X11_08
    T1CCP0_2,       // 92 - PL_6       unrouted
    T1CCP1_2,       // 93 - PL_7       unrouted
    T4CCP0_1,       // 94 - PB_0       X11_58
    T4CCP1_1,       // 95 - PB_1       unrouted
};


const uint8_t digital_pin_to_port[]       = {
    NOT_A_PIN,      // dummy 
    NOT_A_PIN,      // 01 - 3.3v       X8_01
    PE,             // 02 - PE_4       X8_03
    PC,             // 03 - PC_4       X8_05
    PC,             // 04 - PC_5       X8_07
    PC,             // 05 - PC_6       X8_09
    PE,             // 06 - PE_5       X8_11
    PD,             // 07 - PD_3       X8_13
    PC,             // 08 - PC_7       X8_15
    PB,             // 09 - PB_2       X8_17
    PB,             // 10 - PB_3       X8_19
    PP,             // 11 - PP_2       X9_20
    PN,             // 12 - PN_3       X9_18
    PN,             // 13 - PN_2       X9_16
    PD,             // 14 - PD_0       X9_14
    PD,             // 15 - PD_1       X9_12
    NOT_A_PIN,      // 16 - RST        X9_10
    PH,             // 17 - PH_3       X9_08
    PH,             // 18 - PH_2       X9_06
    PM,             // 19 - PM_3       X9_04
    NOT_A_PIN,      // 20 - GND        X9_02
    NOT_A_PIN,      // 21 - 5v         X8_02
    NOT_A_PIN,      // 22 - GND        X8_04
    PE,             // 23 - PE_0       X8_06
    PE,             // 24 - PE_1       X8_08
    PE,             // 25 - PE_2       X8_10
    PE,             // 26 - PE_3       X8_12
    PD,             // 27 - PD_7       X8_14
    PA,             // 28 - PA_6       X8_16
    PM,             // 29 - PM_4       X8_18
    PM,             // 30 - PM_5       X8_20
    PL,             // 31 - PL_3       X9_19
    PL,             // 32 - PL_2       X9_17
    PL,             // 33 - PL_1       X9_15
    PL,             // 34 - PL_0       X9_13
    PL,             // 35 - PL_5       X9_11
    PL,             // 36 - PL_4       X9_09
    PG,             // 37 - PG_0       X9_07
    PF,             // 38 - PF_3       X9_05
    PF,             // 39 - PF_2       X9_03
    PF,             // 40 - PF_1       X9_01
    NOT_A_PIN,      // 41 - 3.3v       X6_01
    PD,             // 42 - PD_2       X6_03
    PP,             // 43 - PP_0       X6_05
    PP,             // 44 - PP_1       X6_07
    PD,             // 45 - PD_4       X6_09
    PD,             // 46 - PD_5       X6_11
    PQ,             // 47 - PQ_0       X6_13
    PP,             // 48 - PP_4       X6_15
    PN,             // 49 - PN_5       X6_17
    PN,             // 50 - PN_4       X6_19
    PM,             // 51 - PM_6       X7_20
    PQ,             // 52 - PQ_1       X7_18
    PP,             // 53 - PP_3       X7_16
    PQ,             // 54 - PQ_3       X7_14
    PQ,             // 55 - PQ_2       X7_12
    NOT_A_PIN,      // 56 - RESET      X7_10
    PA,             // 57 - PA_7       X7_08
    PP,             // 58 - PP_5       X7_06
    PM,             // 59 - PM_7       X7_04
    NOT_A_PIN,      // 60 - GND        X7_02
    NOT_A_PIN,      // 61 - 5v         X6_02
    NOT_A_PIN,      // 62 - GND        X6_04
    PB,             // 63 - PB_4       X6_06
    PB,             // 64 - PB_5       X6_08
    PK,             // 65 - PK_0       X6_10
    PK,             // 66 - PK_1       X6_12
    PK,             // 67 - PK_2       X6_14
    PK,             // 68 - PK_3       X6_16
    PA,             // 69 - PA_4       X6_18
    PA,             // 70 - PA_5       X6_20
    PK,             // 71 - PK_7       X7_19
    PK,             // 72 - PK_6       X7_17
    PH,             // 73 - PH_1       X7_15
    PH,             // 74 - PH_0       X7_13
    PM,             // 75 - PM_2       X7_11
    PM,             // 76 - PM_1       X7_09
    PM,             // 77 - PM_0       X7_07
    PK,             // 78 - PK_5       X7_05
    PK,             // 79 - PK_4       X7_03
    PG,             // 80 - PG_1       X7_01
    PN,             // 81 - PN_1       LED1
    PN,             // 82 - PN_0       LED2
    PF,             // 83 - PF_4       LED3
    PF,             // 84 - PF_0       LED4
    PJ,             // 85 - PJ_0       USR_SW1
    PJ,             // 86 - PJ_1       USR_SW2
    PD,             // 87 - PD_6       AIN5
    PA,             // 88 - PA_0       JP4
    PA,             // 89 - PA_1       JP5
    PA,             // 90 - PA_2       X11_06
    PA,             // 91 - PA_3       X11_08
    PL,             // 92 - PL_6       unrouted
    PL,             // 93 - PL_7       unrouted
    PB,             // 94 - PB_0       X11_58
    PB,             // 95 - PB_1       unrouted
};


const uint8_t digital_pin_to_bit_mask[]   = {
    NOT_A_PIN,      // dummy 
    NOT_A_PIN,      // 01 - 3.3v       X8_01
    BV(4),          // 02 - PE_4       X8_03
    BV(4),          // 03 - PC_4       X8_05
    BV(5),          // 04 - PC_5       X8_07
    BV(6),          // 05 - PC_6       X8_09
    BV(5),          // 06 - PE_5       X8_11
    BV(3),          // 07 - PD_3       X8_13
    BV(7),          // 08 - PC_7       X8_15
    BV(2),          // 09 - PB_2       X8_17
    BV(3),          // 10 - PB_3       X8_19
    BV(2),          // 11 - PP_2       X9_20
    BV(3),          // 12 - PN_3       X9_18
    BV(2),          // 13 - PN_2       X9_16
    BV(0),          // 14 - PD_0       X9_14
    BV(1),          // 15 - PD_1       X9_12
    NOT_A_PIN,      // 16 - RST        X9_10
    BV(3),          // 17 - PH_3       X9_08
    BV(2),          // 18 - PH_2       X9_06
    BV(3),          // 19 - PM_3       X9_04
    NOT_A_PIN,      // 20 - GND        X9_02
    NOT_A_PIN,      // 21 - 5v         X8_02
    NOT_A_PIN,      // 22 - GND        X8_04
    BV(0),          // 23 - PE_0       X8_06
    BV(1),          // 24 - PE_1       X8_08
    BV(2),          // 25 - PE_2       X8_10
    BV(3),          // 26 - PE_3       X8_12
    BV(7),          // 27 - PD_7       X8_14
    BV(6),          // 28 - PA_6       X8_16
    BV(4),          // 29 - PM_4       X8_18
    BV(5),          // 30 - PM_5       X8_20
    BV(3),          // 31 - PL_3       X9_19
    BV(2),          // 32 - PL_2       X9_17
    BV(1),          // 33 - PL_1       X9_15
    BV(0),          // 34 - PL_0       X9_13
    BV(5),          // 35 - PL_5       X9_11
    BV(4),          // 36 - PL_4       X9_09
    BV(0),          // 37 - PG_0       X9_07
    BV(3),          // 38 - PF_3       X9_05
    BV(2),          // 39 - PF_2       X9_03
    BV(1),          // 40 - PF_1       X9_01
    NOT_A_PIN,      // 41 - 3.3v       X6_01
    BV(2),          // 42 - PD_2       X6_03
    BV(0),          // 43 - PP_0       X6_05
    BV(1),          // 44 - PP_1       X6_07
    BV(4),          // 45 - PD_4       X6_09
    BV(5),          // 46 - PD_5       X6_11
    BV(0),          // 47 - PQ_0       X6_13
    BV(4),          // 48 - PP_4       X6_15
    BV(5),          // 49 - PN_5       X6_17
    BV(4),          // 50 - PN_4       X6_19
    BV(6),          // 51 - PM_6       X7_20
    BV(1),          // 52 - PQ_1       X7_18
    BV(3),          // 53 - PP_3       X7_16
    BV(3),          // 54 - PQ_3       X7_14
    BV(2),          // 55 - PQ_2       X7_12
    NOT_A_PIN,      // 56 - RESET      X7_10
    BV(7),          // 57 - PA_7       X7_08
    BV(5),          // 58 - PP_5       X7_06
    BV(7),          // 59 - PM_7       X7_04
    NOT_A_PIN,      // 60 - GND        X7_02
    NOT_A_PIN,      // 61 - 5v         X6_02
    NOT_A_PIN,      // 62 - GND        X6_04
    BV(4),          // 63 - PB_4       X6_06
    BV(5),          // 64 - PB_5       X6_08
    BV(0),          // 65 - PK_0       X6_10
    BV(1),          // 66 - PK_1       X6_12
    BV(2),          // 67 - PK_2       X6_14
    BV(3),          // 68 - PK_3       X6_16
    BV(4),          // 69 - PA_4       X6_18
    BV(5),          // 70 - PA_5       X6_20
    BV(7),          // 71 - PK_7       X7_19
    BV(6),          // 72 - PK_6       X7_17
    BV(1),          // 73 - PH_1       X7_15
    BV(0),          // 74 - PH_0       X7_13
    BV(2),          // 75 - PM_2       X7_11
    BV(1),          // 76 - PM_1       X7_09
    BV(0),          // 77 - PM_0       X7_07
    BV(5),          // 78 - PK_5       X7_05
    BV(4),          // 79 - PK_4       X7_03
    BV(1),          // 80 - PG_1       X7_01
    BV(1),          // 81 - PN_1       LED1
    BV(0),          // 82 - PN_0       LED2
    BV(4),          // 83 - PF_4       LED3
    BV(0),          // 84 - PF_0       LED4
    BV(0),          // 85 - PJ_0       USR_SW1
    BV(1),          // 86 - PJ_1       USR_SW2
    BV(6),          // 87 - PD_6       AIN5
    BV(0),          // 88 - PA_0       JP4
    BV(1),          // 89 - PA_1       JP5
    BV(2),          // 90 - PA_2       X11_06
    BV(3),          // 91 - PA_3       X11_08
    BV(6),          // 92 - PL_6       unrouted
    BV(7),          // 93 - PL_7       unrouted
    BV(0),          // 94 - PB_0       X11_58
    BV(1),          // 95 - PB_1       unrouted
};

const uint32_t digital_pin_to_analog_in[] = {
    ADC_CTL_TS,     // 00 - Temperature Sensor 
    NOT_ON_ADC,     // 01 - 3.3v       X8_01
    ADC_CTL_CH9,    // 02 - PE_4       X8_03
    NOT_ON_ADC,     // 03 - PC_4       X8_05
    NOT_ON_ADC,     // 04 - PC_5       X8_07
    NOT_ON_ADC,     // 05 - PC_6       X8_09
    ADC_CTL_CH8,    // 06 - PE_5       X8_11
    ADC_CTL_CH12,   // 07 - PD_3       X8_13
    NOT_ON_ADC,     // 08 - PC_7       X8_15
    NOT_ON_ADC,     // 09 - PB_2       X8_17
    NOT_ON_ADC,     // 10 - PB_3       X8_19
    NOT_ON_ADC,     // 11 - PP_2       X9_20
    NOT_ON_ADC,     // 12 - PN_3       X9_18
    NOT_ON_ADC,     // 13 - PN_2       X9_16
    ADC_CTL_CH15,   // 14 - PD_0       X9_14
    ADC_CTL_CH14,   // 15 - PD_1       X9_12
    NOT_ON_ADC,     // 16 - RST        X9_10
    NOT_ON_ADC,     // 17 - PH_3       X9_08
    NOT_ON_ADC,     // 18 - PH_2       X9_06
    NOT_ON_ADC,     // 19 - PM_3       X9_04
    NOT_ON_ADC,     // 20 - GND        X9_02
    NOT_ON_ADC,     // 21 - 5v         X8_02
    NOT_ON_ADC,     // 22 - GND        X8_04
    ADC_CTL_CH3,    // 23 - PE_0       X8_06
    ADC_CTL_CH2,    // 24 - PE_1       X8_08
    ADC_CTL_CH1,    // 25 - PE_2       X8_10
    ADC_CTL_CH0,    // 26 - PE_3       X8_12
    ADC_CTL_CH4,    // 27 - PD_7       X8_14
    NOT_ON_ADC,     // 28 - PA_6       X8_16
    NOT_ON_ADC,     // 29 - PM_4       X8_18
    NOT_ON_ADC,     // 30 - PM_5       X8_20
    NOT_ON_ADC,     // 31 - PL_3       X9_19
    NOT_ON_ADC,     // 32 - PL_2       X9_17
    NOT_ON_ADC,     // 33 - PL_1       X9_15
    NOT_ON_ADC,     // 34 - PL_0       X9_13
    NOT_ON_ADC,     // 35 - PL_5       X9_11
    NOT_ON_ADC,     // 36 - PL_4       X9_09
    NOT_ON_ADC,     // 37 - PG_0       X9_07
    NOT_ON_ADC,     // 38 - PF_3       X9_05
    NOT_ON_ADC,     // 39 - PF_2       X9_03
    NOT_ON_ADC,     // 40 - PF_1       X9_01
    NOT_ON_ADC,     // 41 - 3.3v       X6_01
    ADC_CTL_CH13,   // 42 - PD_2       X6_03
    NOT_ON_ADC,     // 43 - PP_0       X6_05
    NOT_ON_ADC,     // 44 - PP_1       X6_07
    ADC_CTL_CH7,    // 45 - PD_4       X6_09
    ADC_CTL_CH6,    // 46 - PD_5       X6_11
    NOT_ON_ADC,     // 47 - PQ_0       X6_13
    NOT_ON_ADC,     // 48 - PP_4       X6_15
    NOT_ON_ADC,     // 49 - PN_5       X6_17
    NOT_ON_ADC,     // 50 - PN_4       X6_19
    NOT_ON_ADC,     // 51 - PM_6       X7_20
    NOT_ON_ADC,     // 52 - PQ_1       X7_18
    NOT_ON_ADC,     // 53 - PP_3       X7_16
    NOT_ON_ADC,     // 54 - PQ_3       X7_14
    NOT_ON_ADC,     // 55 - PQ_2       X7_12
    NOT_ON_ADC,     // 56 - RESET      X7_10
    NOT_ON_ADC,     // 57 - PA_7       X7_08
    NOT_ON_ADC,     // 58 - PP_5       X7_06
    NOT_ON_ADC,     // 59 - PM_7       X7_04
    NOT_ON_ADC,     // 60 - GND        X7_02
    NOT_ON_ADC,     // 61 - 5v         X6_02
    NOT_ON_ADC,     // 62 - GND        X6_04
    ADC_CTL_CH10,   // 63 - PB_4       X6_06
    ADC_CTL_CH11,   // 64 - PB_5       X6_08
    ADC_CTL_CH16,   // 65 - PK_0       X6_10
    ADC_CTL_CH17,   // 66 - PK_1       X6_12
    ADC_CTL_CH18,   // 67 - PK_2       X6_14
    ADC_CTL_CH19,   // 68 - PK_3       X6_16
    NOT_ON_ADC,     // 69 - PA_4       X6_18
    NOT_ON_ADC,     // 70 - PA_5       X6_20
    NOT_ON_ADC,     // 71 - PK_7       X7_19
    NOT_ON_ADC,     // 72 - PK_6       X7_17
    NOT_ON_ADC,     // 73 - PH_1       X7_15
    NOT_ON_ADC,     // 74 - PH_0       X7_13
    NOT_ON_ADC,     // 75 - PM_2       X7_11
    NOT_ON_ADC,     // 76 - PM_1       X7_09
    NOT_ON_ADC,     // 77 - PM_0       X7_07
    NOT_ON_ADC,     // 78 - PK_5       X7_05
    NOT_ON_ADC,     // 79 - PK_4       X7_03
    NOT_ON_ADC,     // 80 - PG_1       X7_01
    NOT_ON_ADC,     // 81 - PN_1       LED1
    NOT_ON_ADC,     // 82 - PN_0       LED2
    NOT_ON_ADC,     // 83 - PF_4       LED3
    NOT_ON_ADC,     // 84 - PF_0       LED4
    NOT_ON_ADC,     // 85 - PJ_0       USR_SW1
    NOT_ON_ADC,     // 86 - PJ_1       USR_SW2
    ADC_CTL_CH5,    // 87 - PD_6       AIN5
    NOT_ON_ADC,     // 88 - PA_0       JP4
    NOT_ON_ADC,     // 89 - PA_1       JP5
    NOT_ON_ADC,     // 90 - PA_2       X11_06
    NOT_ON_ADC,     // 91 - PA_3       X11_08
    NOT_ON_ADC,     // 92 - PL_6       unrouted
    NOT_ON_ADC,     // 93 - PL_7       unrouted
    NOT_ON_ADC,     // 94 - PB_0       X11_58
    NOT_ON_ADC,     // 95 - PB_1       unrouted
};







#endif
#endif 


/* 
From spms433.pdf, see 'tools' at EOF for extraction command
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
 PD4   125   AIN07       U2Rx      -     T3CCP0    -        -       -       -        -       -       -         -    SSI1XDAT2
 PD5   126   AIN06       U2Tx      -     T3CCP1    -        -       -       -        -       -       -         -    SSI1XDAT3
 PD6   127   AIN05       U2RTS     -     T4CCP0    -    USB0EPEN    -       -        -       -       -         -    SSI2XDAT3
 PD7   128   AIN04       U2CTS     -     T4CCP1    -    USB0PFLT    -       -       NMI      -       -         -    SSI2XDAT2
 PE0   15    AIN03       U1RTS     -       -       -        -       -       -        -       -       -         -       -
 PE1   14    AIN02       U1DSR     -       -       -        -       -       -        -       -       -         -       -
 PE2   13    AIN01       U1DCD     -       -       -        -       -       -        -       -       -         -       -
 PE3   12    AIN00       U1DTR     -       -       -        -       -       -        -       -       -         -       -
 PE4   123   AIN09       U1RI      -       -       -        -       -       -        -       -       -         -      SSI1XDAT0
 PE5   124   AIN08         -       -       -       -        -       -       -        -       -       -         -      SSI1XDAT1
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

a. The TMPRn signals are digital signals enabled and configured by the Hibernation module. All other signals listed 
    in this column are analog signals.
b. The digital signals that are shaded gray are the power-on default values for the corresponding GPIO pin. 
    Encodings 9, 10, and 12 are not used on this device.
*/

/* tools
    table extraction from data sheet
          pdftotext -f 1813 -l 1815 -layout  spms433.pdf 

    look for duplicate pin declares with
       grep "static const uint8_t P._" pins_energia.h  | awk '{print $4}' | sort | uniq -d

    this prints out the tables
        cp pins_energia.h a, edit a leaving only the energia pins
        cat a | sed "s/;/ /" | awk '{ printf("    TODO,           // %02d - %-6s %-8s \n",$6,$4,$8)}' | sort -n

    this looks for PWM outputs on X11
        grep CCP.*, pins_energia.h  | awk '{print $5}' | xargs -i grep X11_.[0-9].*{} pins_energia.h  | sort -k 3
*/

