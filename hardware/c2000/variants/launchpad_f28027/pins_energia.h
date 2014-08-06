/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for C2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
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
#define BV(x) ((uint32_t) 1 << (x))
#endif

static const uint8_t SS   = 8;  /* P2.0 */
static const uint8_t SCK  = 7;  /* P1.5 */
static const uint8_t MOSI = 15; /* P1.7 */
static const uint8_t MISO = 14; /* P1.6 */

static const uint8_t AA0 = 0x8000;  //A0
static const uint8_t AA1 = 0x8001;	//A1
static const uint8_t AA2 = 0x8002;	//A2
static const uint8_t AA3 = 0x8003;	//A3
static const uint8_t AA4 = 0x8004;	//A4
static const uint8_t AA5 = 0x8005;	//A5
static const uint8_t AA6 = 0x8006;	//A6
static const uint8_t AA7 = 0x8007;	//A7
static const uint8_t AB0 = 0x8008;  //B0
static const uint8_t AB1 = 0x8009;  //B1
static const uint8_t AB2 = 0x800A;  //B2
static const uint8_t AB3 = 0x800B;  //B3
static const uint8_t AB4 = 0x800C;  //B4
static const uint8_t AB5 = 0x800D;  //B5
static const uint8_t AB6 = 0x800E;  //B6
static const uint8_t AB7 = 0x800F;  //B7


// Pin names based on GPIO numbers
//
static const uint8_t P0 = 0x0000;
static const uint8_t P1 = 0x0001;
static const uint8_t P2 = 0x0002;
static const uint8_t P3 = 0x0003;
static const uint8_t P4 = 0x0004;
static const uint8_t P5 = 0x0005;
static const uint8_t P6 = 0x0006;
static const uint8_t P7 = 0x0007;
static const uint8_t P12 = 0x0000C;
static const uint8_t P16 = 0x00010;
static const uint8_t P17 = 0x00011;
static const uint8_t P18 = 0x00012;
static const uint8_t P19 = 0x00013;
static const uint8_t P28 = 0x0001C;
static const uint8_t P29 = 0x0001D;
static const uint8_t P32 = 0x00020;
static const uint8_t P33 = 0x00021;
static const uint8_t P34 = 0x00022;


#ifdef ARDUINO_MAIN

const uint32_t* port_to_dir[] = {
	NOT_A_PORT,
	(const uint32_t *) &GpioCtrlRegs.GPADIR.all,
	(const uint32_t *) &GpioCtrlRegs.GPADIR.all,
	(const uint32_t *) &GpioCtrlRegs.GPBDIR.all,
	(const uint32_t *) &GpioCtrlRegs.GPBDIR.all,

};

const uint32_t* port_to_sel[] = {
	NOT_A_PORT,
	(const uint32_t *) &GpioCtrlRegs.GPAMUX1.all,
	(const uint32_t *) &GpioCtrlRegs.GPAMUX2.all,
	(const uint32_t *) &GpioCtrlRegs.GPBMUX1.all,
	NOT_A_PORT
};

////Not needed?
//const uint16_t port_to_ren[] = {
//	NOT_A_PORT,
//	(uint16_t) &P1REN,
//	(uint16_t) &P2REN,
//	(uint16_t) &P3REN,
//};

////Not sure on this one
//const uint16_t port_to_sel2[] = {
//	NOT_A_PORT,
//#ifdef P1SEL2_
//	(uint16_t) &P1SEL2,
//#else
//        NOT_A_PORT,
//#endif
//#ifdef P2SEL2_
//	(uint16_t) &P2SEL2,
//#else
//        NOT_A_PORT,
//#endif
//#ifdef P3SEL2_
//	(uint16_t) &P3SEL2,
//#else
//        NOT_A_PORT,
//#endif
//};

const uint32_t* port_to_input[] = {
	NOT_A_PORT,
	(const uint32_t *) &GpioDataRegs.GPADAT.all,
	(const uint32_t *) &GpioDataRegs.GPADAT.all,
	(const uint32_t *) &GpioDataRegs.GPBDAT.all,
	(const uint32_t *) &GpioDataRegs.GPBDAT.all
};
const uint32_t* port_to_output[] = {
	NOT_A_PORT,
	(const uint32_t *) &GpioDataRegs.GPADAT.all,
	(const uint32_t *) &GpioDataRegs.GPADAT.all,
	(const uint32_t *) &GpioDataRegs.GPBDAT.all,
	(const uint32_t *) &GpioDataRegs.GPBDAT.all
};

const uint32_t* port_to_pullup[] = {
	NOT_A_PORT,
	(const uint32_t *) &GpioCtrlRegs.GPAPUD.all,
	(const uint32_t *) &GpioCtrlRegs.GPAPUD.all,
	(const uint32_t *) &GpioCtrlRegs.GPBPUD.all,
	(const uint32_t *) &GpioCtrlRegs.GPBPUD.all
};

/* 
 * Defines for devices with 2x TA3 timers (e.g. MSP430g2553). On the 20pin devices, upto 3 analog outputs are available
 * T0A1, T1A1 and T1A2 
 */
const uint32_t digital_pin_to_timer[] = {
	PWM1A,        /*  0 - dummy */
	PWM1B,        /*  1 - VCC */
	PWM2A,        /*  2 - P1.0 */
	PWM2B,        /*  3 - P1.1, note: A0 output cannot be used with analogWrite */
	PWM3A,        /*  4 - P1.2 */
	PWM3B,        /*  5 - P1.3 */
	PWM4A, /*  6 - P1.4 note: special case. Leaving as no timer due to difficulty determining if available */
	PWM4B, /*  7 - P1.5 note: A0 output cannot be used with analogWrite  */
	NOT_ON_TIMER, /*  8 - P2.0 */
	NOT_ON_TIMER, /*  9 - P2.1 */
	NOT_ON_TIMER, /* 10 - P2.3 */
	NOT_ON_TIMER, /* 11 - P2.4 */
	NOT_ON_TIMER, /* 12 - P2.5 */
	NOT_ON_TIMER, /* 13 - P2.6 */
	NOT_ON_TIMER, /* 14 - P1.6 */
	NOT_ON_TIMER, /* 15 - P1.7 */
	NOT_ON_TIMER, /* 16 - /RESET */  
	NOT_ON_TIMER, /* 17 - TEST */  
	NOT_ON_TIMER, /* 18 - XOUT - P2.7 */
	NOT_ON_TIMER, /* 18 - XIN - P2.6: */
	NOT_ON_TIMER, /* 20 - GND */
	NOT_ON_TIMER, //21
	NOT_ON_TIMER, //22
	NOT_ON_TIMER, //23
	NOT_ON_TIMER, //24
	NOT_ON_TIMER, //25
	NOT_ON_TIMER, //26
	NOT_ON_TIMER, //27
	NOT_ON_TIMER, //28
	NOT_ON_TIMER, //29
	NOT_ON_TIMER, //30
	NOT_ON_TIMER, //31
	NOT_ON_TIMER, //32
	NOT_ON_TIMER, //33
	NOT_ON_TIMER, //34
};

const uint32_t digital_pin_to_port[] = {
		PORT_A_1,     /* 0,  port P1.0 */
		PORT_A_1,     /* 1,  port P1.1 */
		PORT_A_1,     /* 2,  port P1.2 */
		PORT_A_1,     /* 3,  port P1.3*/
		PORT_A_1,     /* 4,  port P1.4 */
		PORT_A_1,     /* 5,  port P1.5 */
		PORT_A_1,     /* 6,  port P2.0 */
		PORT_A_1,     /* 7,  port P2.1 */
		NOT_A_PIN, /* 8, RST */
		NOT_A_PIN, /* 9, RST */
		NOT_A_PIN, /* 10, RST */
		NOT_A_PIN, /* 11, RST */
		PORT_A_1,     /* 12, port P2.2 */
		NOT_A_PIN, /* 13, RST */
		NOT_A_PIN, /* 14, RST */
		NOT_A_PIN, /* 15, RST */
		PORT_A_2,     /* 16, port P2.3 */
		PORT_A_2,     /* 17, port P2.4 */
		PORT_A_2,     /* 18, port P2.5 */
		PORT_A_2,     /* 19, port P1.6 */
		NOT_A_PIN, /* 20, RST */
		NOT_A_PIN, /* 21, RST */
		NOT_A_PIN, /* 22, RST */
		NOT_A_PIN, /* 23, RST */
		NOT_A_PIN, /* 24, RST */
		NOT_A_PIN, /* 25, RST */
		NOT_A_PIN, /* 26, RST */
		NOT_A_PIN, /* 27, RST */
		PORT_A_2,     /* 28, port P1.7 */
		PORT_A_2,     /* 29, port P1.7 */
		NOT_A_PIN, /* 30, RST */
		NOT_A_PIN, /* 31, RST */
		PORT_B_1,     /* 32, port P1.7 */
		PORT_B_1,     /* 33, port P1.7 */
		PORT_B_1,     /* 34, port P1.7 */
};

const uint32_t digital_pin_to_bit_mask[] = {
	BV(0),     /* 0,  port P1.0 */
	BV(1),     /* 1,  port P1.1 */
	BV(2),     /* 2,  port P1.2 */
	BV(3),     /* 3,  port P1.3*/
	BV(4),     /* 4,  port P1.4 */
	BV(5),     /* 5,  port P1.5 */
	BV(6),     /* 6,  port P2.0 */
	BV(7),     /* 7,  port P2.1 */
	NOT_A_PIN, /* 8, RST */
	NOT_A_PIN, /* 9, RST */
	NOT_A_PIN, /* 10, RST */
	NOT_A_PIN, /* 11, RST */
	BV(12),     /* 12, port P2.2 */
	NOT_A_PIN, /* 13, RST */
	NOT_A_PIN, /* 14, RST */
	NOT_A_PIN, /* 15, RST */
	BV(16),     /* 16, port P2.3 */
	BV(17),     /* 17, port P2.4 */
	BV(18),     /* 18, port P2.5 */
	BV(19),     /* 19, port P1.6 */
	NOT_A_PIN, /* 20, RST */
	NOT_A_PIN, /* 21, RST */
	NOT_A_PIN, /* 22, RST */
	NOT_A_PIN, /* 23, RST */
	NOT_A_PIN, /* 24, RST */
	NOT_A_PIN, /* 25, RST */
	NOT_A_PIN, /* 26, RST */
	NOT_A_PIN, /* 27, RST */
	BV(28),     /* 28, port P1.7 */
	BV(29),     /* 29, port P1.7 */
	NOT_A_PIN, /* 30, RST */
	NOT_A_PIN, /* 31, RST */
	BV(32-32),     /* 32, port P1.7 */
	BV(33-32),     /* 33, port P1.7 */
	BV(34-32),     /* 34, port P1.7 */
};
#endif
#endif
