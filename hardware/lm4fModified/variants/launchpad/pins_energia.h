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
#ifndef BV
#define BV(x) (1 << (x))
#endif
/*
static const uint8_t SS   = 8;  // P2.0
static const uint8_t SCK  = 7;  // P1.5
static const uint8_t MOSI = 15; // P1.7
static const uint8_t MISO = 14; // P1.6
*/
// Pin names based on the silkscreen
//
static const uint8_t PB_6 = 1;
static const uint8_t PB_7 = 4;
static const uint8_t PF_4 = 5;
static const uint8_t PE_3 = 6;
static const uint8_t PE_2 = 7;
static const uint8_t PE_1 = 8;
static const uint8_t PE_0 = 9;
static const uint8_t PD_7 = 10;
static const uint8_t PC_7 = 13;
static const uint8_t PC_6 = 14;
static const uint8_t PC_5 = 15;
static const uint8_t PC_4 = 16;
static const uint8_t PA_0 = 17;
static const uint8_t PA_1 = 18;
static const uint8_t PA_2 = 19;
static const uint8_t PA_3 = 20;
static const uint8_t PA_4 = 21;
static const uint8_t PA_5 = 22;
static const uint8_t PA_6 = 23;
static const uint8_t PA_7 = 24;
static const uint8_t PF_0 = 28;
static const uint8_t PF_1 = 29;
static const uint8_t PF_2 = 30;
static const uint8_t PF_3 = 31;
static const uint8_t PD_4 = 43;
static const uint8_t PD_5 = 44;
static const uint8_t PB_0 = 45;
static const uint8_t PB_1 = 46;
static const uint8_t PB_2 = 47;
static const uint8_t PB_3 = 48;
static const uint8_t PC_3 = 49;
static const uint8_t PC_2 = 50;
static const uint8_t PC_1 = 51;
static const uint8_t PC_0 = 52;
static const uint8_t PD_6 = 53;
static const uint8_t PB_5 = 57;
static const uint8_t PB_4 = 58;
static const uint8_t PE_4 = 59;
static const uint8_t PE_5 = 60;
static const uint8_t PD_0 = 61;
static const uint8_t PD_1 = 62;
static const uint8_t PD_2 = 63;
static const uint8_t PD_3 = 64;

static const uint8_t RED_LED = 4;
static const uint8_t GREEN_LED = 2;
static const uint8_t BLUE_LED = 3;

static const uint8_t PUSH1 = 5;
static const uint8_t PUSH2 = 28;

//static const uint8_t TEMPSENSOR = 10; // depends on chip


#ifdef ARDUINO_MAIN

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) GPIO_PORTA_DIR_R,
	(uint16_t) GPIO_PORTB_DIR_R,
	(uint16_t) GPIO_PORTC_DIR_R,
	(uint16_t) GPIO_PORTD_DIR_R,
	(uint16_t) GPIO_PORTE_DIR_R,
	(uint16_t) GPIO_PORTF_DIR_R
	/*	//(uint16_t) &P1DIR,
	//(uint16_t) &P2DIR,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3DIR,
#endif*/
};

const uint16_t port_to_afsel[] = {
	NOT_A_PORT,
	(uint16_t) GPIO_PORTA_AFSEL_R,
	(uint16_t) GPIO_PORTB_AFSEL_R,
	(uint16_t) GPIO_PORTC_AFSEL_R,
	(uint16_t) GPIO_PORTD_AFSEL_R,
	(uint16_t) GPIO_PORTE_AFSEL_R,
	(uint16_t) GPIO_PORTF_AFSEL_R
/*	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3SEL,
#endif*/
};

/*const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3REN,
#endif
};*/
const uint16_t port_to_pur[] = {
	NOT_A_PORT,
	(uint32_t) GPIO_PORTA_PUR_R,
	(uint32_t) GPIO_PORTB_PUR_R,
	(uint32_t) GPIO_PORTC_PUR_R,
	(uint32_t) GPIO_PORTD_PUR_R,
	(uint32_t) GPIO_PORTE_PUR_R,
	(uint32_t) GPIO_PORTF_PUR_R
};
const uint16_t port_to_pdr[] = {
	NOT_A_PORT,
	(uint32_t) GPIO_PORTA_PDR_R,
	(uint32_t) GPIO_PORTB_PDR_R,
	(uint32_t) GPIO_PORTC_PDR_R,
	(uint32_t) GPIO_PORTD_PDR_R,
	(uint32_t) GPIO_PORTE_PDR_R,
	(uint32_t) GPIO_PORTF_PDR_R
};
const uint16_t port_to_base[] = {
	NOT_A_PORT,
	(uint32_t) GPIO_PORTA_DATA_BITS_R,
	(uint32_t) GPIO_PORTB_DATA_BITS_R,
	(uint32_t) GPIO_PORTC_DATA_BITS_R,
	(uint32_t) GPIO_PORTD_DATA_BITS_R,
	(uint32_t) GPIO_PORTE_DATA_BITS_R,
	(uint32_t) GPIO_PORTF_DATA_BITS_R
};
#define GPIO_DATA  0x000
#define GPIO_DIR   0x400
#define GPIO_IS    0x404
#define GPIO_IBE   0x408
#define GPIO_IEV   0x40C
#define GPIO_IM    0x410
#define GPIO_RIS   0x414
#define GPIO_MIS   0x418
#define GPIO_ICR   0x41C
#define GPIO_AFSEL 0x420
#define GPIO_DR2R  0x500
#define GPIO_DR4R  0x504
#define GPIO_DR8R  0x508
#define GPIO_ODR    0x50C
#define GPIO_PUR   0x510
#define GPIO_PDR   0x514
#define GPIO_SLR  0x518
#define GPIO_DEN  0x51C
#define GPIO_LOCK 0x520
#define GPIO_CR  0x524
#define GPIO_AMSEL  0x528
#define GPIO_PCTL  0x52C
#define GPIO_ADCCTL  0x530
#define GPIO_MACTL  0x534
#define GPIO_PeriphID4  0xFD0
#define GPIO_PeriphID5  0xFD4
#define GPIO_PeriphID6  0xFD8
#define GPIO_PeriphID7 0xFDC
#define GPIO_PeriphID0  0xFE0
#define GPIO_PeriphID1  0xFE4
#define GPIO_PeriphID2  0xFE8
#define GPIO_PeriphID3  0xFEC
#define GPIO_CellID0  0xFF0
#define GPIO_CellID1  0xFF4
#define GPIO_CellID2  0xFF8
#define GPIO_CellID3  0xFFC

/*const uint16_t port_to_sel2[] = {
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
};*/

/*
const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3IN,
#endif
};
const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
#ifdef __MSP430_HAS_PORT3_R__
	(uint16_t) &P3OUT,
#endif
};
*/
/* 
 * Defines for devices with 2x TA3 timers (e.g. MSP430g2553). On the 20pin devices, upto 3 analog outputs are available
 * T0A1, T1A1 and T1A2 
 */
const uint8_t digital_pin_to_timer[] = {
	NOT_ON_TIMER, /*  dummy */
	T0CCP0,       /*  1 - PB6 */
	NOT_ON_TIMER, /*  2 - VDDA */
	NOT_ON_TIMER, /*  3 - GNDA */
	T0CCP1,       /*  4 - PB7 */
	T2CCP0, 	  /*  5 - PF4 */
	NOT_ON_TIMER, /*  6 - PE3 */
	NOT_ON_TIMER, /*  7 - PE2 */
	NOT_ON_TIMER, /*  8 - PE1 */
	NOT_ON_TIMER, /*  9 - PE0 */
	WT5CCP1,      /*  10 - PD7 */
	NOT_ON_TIMER, /*  11 - VDD */
	NOT_ON_TIMER, /*  12 - GND */
	WT1CCP1,      /*  13 - PC7 */
	WT1CCP0,      /*  14 - PC6 */
	WT0CCP1,      /*  15 - PC5 */
	WT0CCP0,      /*  16 - PC4 */
	NOT_ON_TIMER, /*  17 - PA0 */
	NOT_ON_TIMER, /*  18 - PA1 */
	NOT_ON_TIMER, /*  19 - PA2 */
	NOT_ON_TIMER, /*  20 - PA3 */
	NOT_ON_TIMER, /*  21 - PA4 */
	NOT_ON_TIMER, /*  22 - PA5 */
	NOT_ON_TIMER, /*  23 - PA6 */
	NOT_ON_TIMER, /*  24 - PA7 */
	NOT_ON_TIMER, /*  25 - VDDC */
	NOT_ON_TIMER, /*  26 - VDD */
	NOT_ON_TIMER, /*  27 - GND */
	T0CCP0,       /*  28 - PF0 */
	T0CCP1,       /*  29 - PF1 */
	T1CCP0,       /*  30 - PF2 */
	T1CCP1,       /*  31 - PF3 */
	NOT_ON_TIMER, /*  32 - WAKE */
	NOT_ON_TIMER, /*  33 - HIB */
	NOT_ON_TIMER, /*  34 - X0SC0 */
	NOT_ON_TIMER, /*  35 - GNDX */
	NOT_ON_TIMER, /*  36 - X0SC1 */
	NOT_ON_TIMER, /*  37 - VBAT */
	NOT_ON_TIMER, /*  38 - RST */
	NOT_ON_TIMER, /*  39 - GND */
	NOT_ON_TIMER, /*  40 - OSC0 */
	NOT_ON_TIMER, /*  41 - OSC1 */
	NOT_ON_TIMER, /*  42 - VDD */
	WT4CCP0,      /*  43 - PD4 */
	WT4CCP1,      /*  44 - PD5 */
	T2CCP0,       /*  45 - PB0 */
	T2CCP1, 	  /*  46 - PB1 */
	T3CCP0,       /*  47 - PB2 */
	T3CCP1,       /*  48 - PB3 */
	T5CCP1,       /*  49 - PC3 */
	T5CCP0,       /*  50 - PC2 */
	T4CCP1,       /*  51 - PC1 */
	T4CCP0,       /*  52 - PC0 */
	WT5CCP0,      /*  53 - PD6 */
	NOT_ON_TIMER, /*  54 - VDD */
	NOT_ON_TIMER, /*  55 - GND */
	NOT_ON_TIMER, /*  56 - VDDC */
	T1CCP1,       /*  57 - PB5 */
	T1CCP0,       /*  58 - PB4 */
	NOT_ON_TIMER, /*  59 - PE4 */
	NOT_ON_TIMER, /*  60 - PE5 */
	WT2CCP0,      /*  61 - PD0 */
	WT2CCP1,      /*  62 - PD1 */
	WT3CCP0,      /*  61 - PD2 */
	WT3CCP1,      /*  62 - PD3 */
};

const uint8_t digital_pin_to_port[] = {
		NOT_A_PIN, /*  dummy */
		PB,        /*  1 - PB6 */
		NOT_A_PIN, /*  2 - VDDA */
		NOT_A_PIN, /*  3 - GNDA */
		PB,        /*  4 - PB7 */
		PF, 	   /*  5 - PF4 */
		PE,        /*  6 - PE3 */
		PE,        /*  7 - PE2 */
		PE,        /*  8 - PE1 */
		PE,        /*  9 - PE0 */
		PD,        /*  10 - PD7 */
		NOT_A_PIN, /*  11 - VDD */
		NOT_A_PIN, /*  12 - GND */
		PC,        /*  13 - PC7 */
		PC,        /*  14 - PC6 */
		PC,        /*  15 - PC5 */
		PC,        /*  16 - PC4 */
		PA,        /*  17 - PA0 */
		PA,        /*  18 - PA1 */
		PA,        /*  19 - PA2 */
		PA,        /*  20 - PA3 */
		PA,        /*  21 - PA4 */
		PA,        /*  22 - PA5 */
		PA,        /*  23 - PA6 */
		PA,        /*  24 - PA7 */
		NOT_A_PIN, /*  25 - VDDC */
		NOT_A_PIN, /*  26 - VDD */
		NOT_A_PIN, /*  27 - GND */
		PF,        /*  28 - PF0 */
		PF,        /*  29 - PF1 */
		PF,        /*  30 - PF2 */
		PF,        /*  31 - PF3 */
		NOT_A_PIN, /*  32 - WAKE */
		NOT_A_PIN, /*  33 - HIB */
		NOT_A_PIN, /*  34 - X0SC0 */
		NOT_A_PIN, /*  35 - GNDX */
		NOT_A_PIN, /*  36 - X0SC1 */
		NOT_A_PIN, /*  37 - VBAT */
		NOT_A_PIN, /*  38 - RST */
		NOT_A_PIN, /*  39 - GND */
		NOT_A_PIN, /*  40 - OSC0 */
		NOT_A_PIN, /*  41 - OSC1 */
		NOT_A_PIN, /*  42 - VDD */
		PD,        /*  43 - PD4 */
		PD,        /*  44 - PD5 */
		PB,        /*  45 - PB0 */
		PB, 	   /*  46 - PB1 */
		PB,        /*  47 - PB2 */
		PB,        /*  48 - PB3 */
		PC,        /*  49 - PC3 */
		PC,        /*  50 - PC2 */
		PC,        /*  51 - PC1 */
		PC,        /*  52 - PC0 */
		PD,        /*  53 - PD6 */
		NOT_A_PIN, /*  54 - VDD */
		NOT_A_PIN, /*  55 - GND */
		NOT_A_PIN, /*  56 - VDDC */
		PB,        /*  57 - PB5 */
		PB,        /*  58 - PB4 */
		NOT_A_PIN, /*  59 - PE4 */
		NOT_A_PIN, /*  60 - PE5 */
		PD,        /*  61 - PD0 */
		PD,        /*  62 - PD1 */
		PD,        /*  61 - PD2 */
		PD,        /*  62 - PD3 */
};

const uint8_t digital_pin_to_bit_mask[] = {
		NOT_A_PIN, /*  dummy */
		BV(6),     /*  1 - PB6 */
		NOT_A_PIN, /*  2 - VDDA */
		NOT_A_PIN, /*  3 - GNDA */
		BV(77),    /*  4 - PB7 */
		BV(4), 	   /*  5 - PF4 */
		BV(3),     /*  6 - PE3 */
		BV(2),     /*  7 - PE2 */
		BV(1),     /*  8 - PE1 */
		BV(0),     /*  9 - PE0 */
		BV(7),     /*  10 - PD7 */
		NOT_A_PIN, /*  11 - VDD */
		NOT_A_PIN, /*  12 - GND */
		BV(7),     /*  13 - PC7 */
		BV(6),     /*  14 - PC6 */
		BV(5),     /*  15 - PC5 */
		BV(4),     /*  16 - PC4 */
		BV(0),     /*  17 - PA0 */
		BV(1),     /*  18 - PA1 */
		BV(2),     /*  19 - PA2 */
		BV(3),     /*  20 - PA3 */
		BV(4),     /*  21 - PA4 */
		BV(5),     /*  22 - PA5 */
		BV(6),     /*  23 - PA6 */
		BV(7),     /*  24 - PA7 */
		NOT_A_PIN, /*  25 - VDDC */
		NOT_A_PIN, /*  26 - VDD */
		NOT_A_PIN, /*  27 - GND */
		BV(0),     /*  28 - PF0 */
		BV(1),     /*  29 - PF1 */
		BV(2),     /*  30 - PF2 */
		BV(3),     /*  31 - PF3 */
		NOT_A_PIN, /*  32 - WAKE */
		NOT_A_PIN, /*  33 - HIB */
		NOT_A_PIN, /*  34 - X0SC0 */
		NOT_A_PIN, /*  35 - GNDX */
		NOT_A_PIN, /*  36 - X0SC1 */
		NOT_A_PIN, /*  37 - VBAT */
		NOT_A_PIN, /*  38 - RST */
		NOT_A_PIN, /*  39 - GND */
		NOT_A_PIN, /*  40 - OSC0 */
		NOT_A_PIN, /*  41 - OSC1 */
		NOT_A_PIN, /*  42 - VDD */
		BV(4),     /*  43 - PD4 */
		BV(5),     /*  44 - PD5 */
		BV(0),     /*  45 - PB0 */
		BV(1), 	   /*  46 - PB1 */
		BV(2),     /*  47 - PB2 */
		BV(3),     /*  48 - PB3 */
		BV(3),     /*  49 - PC3 */
		BV(2),     /*  50 - PC2 */
		BV(1),     /*  51 - PC1 */
		BV(0),     /*  52 - PC0 */
		BV(6),     /*  53 - PD6 */
		NOT_A_PIN, /*  54 - VDD */
		NOT_A_PIN, /*  55 - GND */
		NOT_A_PIN, /*  56 - VDDC */
		BV(5),     /*  57 - PB5 */
		BV(4),     /*  58 - PB4 */
		NOT_A_PIN, /*  59 - PE4 */
		NOT_A_PIN, /*  60 - PE5 */
		BV(0),     /*  61 - PD0 */
		BV(1),     /*  62 - PD1 */
		BV(2),     /*  61 - PD2 */
		BV(3),     /*  62 - PD3 */
};
#endif
#endif
