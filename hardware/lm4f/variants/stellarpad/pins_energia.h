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

#define __LM4F120H5QR__
#define __TM4C123GH6PM__

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
static const uint8_t PB_5 = 2;
static const uint8_t PB_0 = 3;
static const uint8_t PB_1 = 4;
static const uint8_t PE_4 = 5;
static const uint8_t PE_5 = 6;
static const uint8_t PB_4 = 7;
static const uint8_t PA_5 = 8;
static const uint8_t PA_6 = 9;
static const uint8_t PA_7 = 10;
static const uint8_t PA_2 = 11;
static const uint8_t PA_3 = 12;
static const uint8_t PA_4 = 13;
static const uint8_t PB_6 = 14;
static const uint8_t PB_7 = 15;
static const uint8_t PF_0 = 17;
static const uint8_t PE_0 = 18;
static const uint8_t PB_2 = 19;
static const uint8_t PD_0 = 23;
static const uint8_t PD_1 = 24;
static const uint8_t PD_2 = 25;
static const uint8_t PD_3 = 26;
static const uint8_t PE_1 = 27; 
static const uint8_t PE_2 = 28;
static const uint8_t PE_3 = 29; 
static const uint8_t PF_1 = 30;
static const uint8_t PF_4 = 31;
static const uint8_t PD_7 = 32;
static const uint8_t PD_6 = 33;
static const uint8_t PC_7 = 34;
static const uint8_t PC_6 = 35;
static const uint8_t PC_5 = 36;
static const uint8_t PC_4 = 37;
static const uint8_t PB_3 = 38;
static const uint8_t PF_3 = 39;
static const uint8_t PF_2 = 40;

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

static const uint8_t RED_LED = 30;
static const uint8_t GREEN_LED = 39;
static const uint8_t BLUE_LED = 40;

static const uint8_t PUSH1 = 31;
static const uint8_t PUSH2 = 17;
static const uint8_t TEMPSENSOR = 0;

#ifdef ARDUINO_MAIN
const uint32_t port_to_base[] = {
        NOT_A_PORT,
        (uint32_t) GPIO_PORTA_BASE,
        (uint32_t) GPIO_PORTB_BASE,
        (uint32_t) GPIO_PORTC_BASE,
        (uint32_t) GPIO_PORTD_BASE,
        (uint32_t) GPIO_PORTE_BASE,
        (uint32_t) GPIO_PORTF_BASE
};
const uint8_t digital_pin_to_timer[] = {
        NOT_ON_TIMER,   /*  dummy */
        NOT_ON_TIMER,   /*  1 - 3.3V */
        T1B0,      		/*  2 - PB5 */
        T2A0,      		/*  3 - PB0 */
        T2B, 	  		/*  4 - PB1 */
        NOT_ON_TIMER, 	/*  5 - PE4 */
        NOT_ON_TIMER, 	/*  6 - PE5 */
        T1A0,      		/*  7 - PB4 */
        NOT_ON_TIMER, 	/*  8 - PA5 */
        NOT_ON_TIMER, 	/*  9 - PA6 */
        NOT_ON_TIMER, 	/*  10 - PA7 */
        NOT_ON_TIMER, 	/*  11 - PA2 */
        NOT_ON_TIMER, 	/*  12 - PA3 */
        NOT_ON_TIMER, 	/*  13 - PA4 */
        T0A0,      		/*  14 - PB6 */
        T0B0,      		/*  15 - PB7 */
        NOT_ON_TIMER, 	/*  16 - RST */
        T0A1,      		/*  17 - PF0 */
        NOT_ON_TIMER, 	/*  18 - PE0 */
        T3A,       		/*  19 - PB2 */
        NOT_ON_TIMER, 	/*  20 - GND */
        NOT_ON_TIMER, 	/*  21 - VBUS */
		NOT_ON_TIMER, 	/*  22 - GND */
        WT2A,      		/*  23 - PD0 */
        WT2B,      		/*  24 - PD1 */
        WT3A,      		/*  25 - PD2 */
        WT3B,      		/*  26 - PD3 */
        NOT_ON_TIMER, 	/*  27 - PE1 */
        NOT_ON_TIMER, 	/*  28 - PE2 */
        NOT_ON_TIMER, 	/*  29 - PE3 */
        T0B1,      		/*  30 - PF1 */
        T2A1, 	  		/*  31 - PF4 */
        WT5B,      		/*  32 - PD7 */
        WT5A,      		/*  33 - PD6 */
        WT1B,      		/*  34 - PC7 */
        WT1A,      		/*  35 - PC6 */
        WT0B,      		/*  36 - PC5 */
        WT0A,      		/*  37 - PC4 */
        T3B,       		/*  38 - PB3 */
        T1B1,      		/*  39 - PF3 */
        T1A1,      		/*  40 - PF2 */
};
const uint8_t digital_pin_to_port[] = {
        NOT_A_PIN,      /*  dummy */
        NOT_A_PIN,      /*  1 - 3.3V */
        PB,      		/*  2 - PB5 */
        PB,      		/*  3 - PB0 */
        PB, 	  		/*  4 - PB1 */
        PE, 	        /*  5 - PE4 */
        PE, 	        /*  6 - PE5 */
        PB,      		/*  7 - PB4 */
        PA, 	        /*  8 - PA5 */
        PA, 	        /*  9 - PA6 */
        PA, 	        /*  10 - PA7 */
        PA, 	        /*  11 - PA2 */
        PA, 	        /*  12 - PA3 */
        PA, 	        /*  13 - PA4 */
        PB,      		/*  14 - PB6 */
        PB,      		/*  15 - PB7 */
        NOT_A_PIN,      /*  16 - RST */
        PF,      		/*  17 - PF0 */
        PE,             /*  18 - PE0 */
        PB,       		/*  19 - PB2 */
        NOT_A_PIN, 	    /*  20 - GND */
        NOT_A_PIN, 	    /*  21 - VBUS */
		NOT_A_PIN, 	    /*  22 - GND */
        PD,      		/*  23 - PD0 */
        PD,      		/*  24 - PD1 */
        PD,      		/*  25 - PD2 */
        PD,      		/*  26 - PD3 */
        PE, 	        /*  27 - PE1 */
        PE, 	        /*  28 - PE2 */
        PE, 	        /*  29 - PE3 */
        PF,      		/*  30 - PF1 */
        PF, 	  		/*  31 - PF4 */
        PD,      		/*  32 - PD7 */
        PD,      		/*  33 - PD6 */
        PC,      		/*  34 - PC7 */
        PC,      		/*  35 - PC6 */
        PC,      		/*  36 - PC5 */
        PC,      		/*  37 - PC4 */
        PB,       		/*  38 - PB3 */
        PF,      		/*  39 - PF3 */
        PF,      		/*  40 - PF2 */
};
const uint8_t digital_pin_to_bit_mask[] = {
        NOT_A_PIN,      /*  dummy */
        NOT_A_PIN,      /*  1 - 3.3V */
        BV(5),      	/*  2 - PB5 */
        BV(0),      	/*  3 - PB0 */
        BV(1), 	  		/*  4 - PB1 */
        BV(4), 	        /*  5 - PE4 */
        BV(5), 	        /*  6 - PE5 */
        BV(4),      	/*  7 - PB4 */
        BV(5), 	        /*  8 - PA5 */
        BV(6), 	        /*  9 - PA6 */
        BV(7), 	        /*  10 - PA7 */
        BV(2), 	        /*  11 - PA2 */
        BV(3), 	        /*  12 - PA3 */
        BV(4), 	        /*  13 - PA4 */
        BV(6),      	/*  14 - PB6 */
        BV(7),      	/*  15 - PB7 */
        NOT_A_PIN,      /*  16 - RST */
        BV(0),      	/*  17 - PF0 */
        BV(0),          /*  18 - PE0 */
        BV(2),       	/*  19 - PB2 */
        NOT_A_PIN, 	    /*  20 - GND */
        NOT_A_PIN, 	    /*  21 - VBUS */
		NOT_A_PIN, 	    /*  22 - GND */
        BV(0),      	/*  23 - PD0 */
        BV(1),      	/*  24 - PD1 */
        BV(2),      	/*  25 - PD2 */
        BV(3),      	/*  26 - PD3 */
        BV(1), 	        /*  27 - PE1 */
        BV(2), 	        /*  28 - PE2 */
        BV(3), 	        /*  29 - PE3 */
        BV(1),      	/*  30 - PF1 */
        BV(4), 	  		/*  31 - PF4 */
        BV(7),      	/*  32 - PD7 */
        BV(6),      	/*  33 - PD6 */
        BV(7),      	/*  34 - PC7 */
        BV(6),      	/*  35 - PC6 */
        BV(5),      	/*  36 - PC5 */
        BV(4),      	/*  37 - PC4 */
        BV(3),       	/*  38 - PB3 */
        BV(3),      	/*  39 - PF3 */
        BV(2),      	/*  40 - PF2 */
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
};
const uint32_t digital_pin_to_analog_in[] = {
        ADC_CTL_TS,     /*  0 - TempSensor   */
        NOT_ON_ADC,     /*  1 - 3.3V*/
        ADC_CTL_CH11,	/*  2 - PB5 */
        NOT_ON_ADC,     /*  3 - PB0 */
        NOT_ON_ADC, 	/*  4 - PB1 */
        ADC_CTL_CH9, 	/*  5 - PE4 */
        ADC_CTL_CH8, 	/*  6 - PE5 */
        ADC_CTL_CH10,   /*  7 - PB4 */
        NOT_ON_ADC, 	/*  8 - PA5 */
        NOT_ON_ADC, 	/*  9 - PA6 */
        NOT_ON_ADC, 	/*  10 - PA7 */
        NOT_ON_ADC, 	/*  11 - PA2 */
        NOT_ON_ADC, 	/*  12 - PA3 */
        NOT_ON_ADC, 	/*  13 - PA4 */
        NOT_ON_ADC,     /*  14 - PB6 */
        NOT_ON_ADC,     /*  15 - PB7 */
        NOT_ON_ADC, 	/*  16 - RST */
        NOT_ON_ADC,     /*  17 - PF0 */
        ADC_CTL_CH3, 	/*  18 - PE0 */
        NOT_ON_ADC,     /*  19 - PB2 */
        NOT_ON_ADC, 	/*  20 - GND */
        NOT_ON_ADC, 	/*  21 - VBUS */
		NOT_ON_ADC, 	/*  22 - GND */
        ADC_CTL_CH7,    /*  23 - PD0 */
        ADC_CTL_CH6,    /*  24 - PD1 */
        ADC_CTL_CH5,    /*  25 - PD2 */
        ADC_CTL_CH4,	/*  26 - PD3 */
        ADC_CTL_CH2, 	/*  27 - PE1 */
        ADC_CTL_CH1, 	/*  28 - PE2 */
        ADC_CTL_CH0, 	/*  29 - PE3 */
        NOT_ON_ADC,     /*  30 - PF1 */
        NOT_ON_ADC, 	/*  31 - PF4 */
        NOT_ON_ADC,     /*  32 - PD7 */
        NOT_ON_ADC,     /*  33 - PD6 */
        NOT_ON_ADC,     /*  34 - PC7 */
        NOT_ON_ADC,     /*  35 - PC6 */
        NOT_ON_ADC,     /*  36 - PC5 */
        NOT_ON_ADC,     /*  37 - PC4 */
        NOT_ON_ADC,  	/*  38 - PB3 */
        NOT_ON_ADC,		/*  39 - PF3 */
        NOT_ON_ADC,     /*  40 - PF2 */
};
#endif
#endif 
