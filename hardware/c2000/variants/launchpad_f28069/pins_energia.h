/*
  ************************************************************************
  *	pins_energia.h
  *
  *	Energia core files for C2000
  *		Copyright (c) 2014 Trey German and Terry Lin. All right reserved.
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

static const uint8_t SCK  = 7;
static const uint8_t MOSI = 15;
static const uint8_t MISO = 14;

static const uint8_t SDA = 10;
static const uint8_t SCL = 9;

static const uint8_t RX = 3;
static const uint8_t TX = 4;

static const uint8_t BLUE_LED = 82; //GPIO39
static const uint8_t GREEN_LED = 82; //Redeclare so that examples that use this still work
static const uint8_t RED_LED = 81; //GPIO34


static const uint8_t AA0 = 27;  //A0 0x8000
static const uint8_t AA1 = 29;	//A1 0x8001
static const uint8_t AA2 = 25;	//A2 0x8002
static const uint8_t AA3 = 67;	//A3 0x8003
static const uint8_t AA4 = 69;	//A4 0x8004
static const uint8_t AA5 = 65;	//A5 0x8005
static const uint8_t AA6 = 2;	//A6 0x8006
static const uint8_t AA7 = 23;	//A7 0x8007
static const uint8_t AB0 = 28;  //B0 0x8008
static const uint8_t AB1 = 24;  //B1 0x8009
static const uint8_t AB2 = 26;  //B2 0x800A
static const uint8_t AB3 = 68;  //B3 0x800B
static const uint8_t AB4 = 64;  //B4 0x800C
static const uint8_t AB5 = 66;  //B5 0x800D
static const uint8_t AB6 = 6;   //B6 0x800E
static const uint8_t AB7 = 63;  //B7 0x800F


// Pin names based on GPIO numbers
//
static const uint8_t P0 = 40; //GPIO0
static const uint8_t P1 = 39; //GPIO1
static const uint8_t P2 = 38; //GPIO2
static const uint8_t P3 = 37; //GPIO3
static const uint8_t P4 = 36; //GPIO4
static const uint8_t P5 = 35; //GPIO1
static const uint8_t P6 = 80; //GPIO6
static const uint8_t P7 = 79; //GPIO7
static const uint8_t P8 = 78; //GPIO8
static const uint8_t P9 = 77; //GPIO9
static const uint8_t P10 = 76; //GPIO10
static const uint8_t P11 = 75; //GPIO11
static const uint8_t P12 = 5; //GPIO12
static const uint8_t P13 = 34; //GPIO13
static const uint8_t P14 = 47; //GPIO14
static const uint8_t P15 = 43; //GPIO15
static const uint8_t P16 = 15; //GPIO16
static const uint8_t P17 = 14; //GPIO17
static const uint8_t P18 = 7; //GPIO18
static const uint8_t P19 = 19; //GPIO19
static const uint8_t P20 = 45; //GPIO20
static const uint8_t P21 = 48; //GPIO21
static const uint8_t P22 = 8; //GPIO22
static const uint8_t P23 = 49; //GPIO23
static const uint8_t P24 = 55; //GPIO24
static const uint8_t P25 = 54; //GPIO25
static const uint8_t P26 = 58; //GPIO26
static const uint8_t P27 = 59; //GPIO27
static const uint8_t P28 = 3; //GPIO28
static const uint8_t P29 = 4; //GPIO29
static const uint8_t P30 = 0; //GPIO30 CANRX
static const uint8_t P31 = 0; //GPIO31 CANTX
static const uint8_t P32 = 10; //GPIO32
static const uint8_t P33 = 9; //GPIO33
static const uint8_t P34 = 0; //GPIO34 RED LED
static const uint8_t P35 = 0; //GPIO35 NOT A PIN
static const uint8_t P36 = 0; //GPIO36 NOT A PIN
static const uint8_t P37 = 0; //GPIO37 NOT A PIN
static const uint8_t P38 = 0; //GPIO38 NOT A PIN
static const uint8_t P39 = 0; //GPIO39 BLUE LED
static const uint8_t P40 = 32; //GPIO40 DAC1
static const uint8_t P41 = 31; //GPIO41 DAC2
static const uint8_t P42 = 72; //GPIO42 DAC3
static const uint8_t P43 = 71; //GPIO43 DAC4
static const uint8_t P44 = 18; //GPIO44
static const uint8_t P50 = 13; //GPIO50
static const uint8_t P51 = 12; //GPIO51
static const uint8_t P52 = 53; //GPIO52
static const uint8_t P53 = 52; //GPIO53
static const uint8_t P54 = 50; //GPIO54
static const uint8_t P55 = 11; //GPIO55
static const uint8_t P56 = 51; //GPIO56
static const uint8_t P57 = 0; //GPIO57 NOT A PIN
static const uint8_t P58 = 44; //GPIO58 NOT A PIN

// Alternate Names

static const uint8_t RX_A = 3; //J1.3
static const uint8_t TX_A = 4; //J1.4 
static const uint8_t SCK_A = 7; //J1.7
static const uint8_t MOSI_A = 15; //J2.15
static const uint8_t MISO_A = 14; //J2.14
static const uint8_t SCL_A = 9; //J1.9
static const uint8_t SDA_A = 10; //J1.10

static const uint8_t RX_B = 43; //J5.3
static const uint8_t TX_B = 44; //J5.4
static const uint8_t SCK_B = 47; //J5.7
static const uint8_t MOSI_B = 55; //J6.15
static const uint8_t MISO_B = 54; //J6.14


//Array used to map physical pin numbers to GPIO/AIO numbers

static const uint16_t  pin_mapping[] = {
    //First set of headers
    NOT_A_PIN, //0
    NOT_A_PIN, //1
    0x8006, //2
    28, //3
    29, //4
    12, //5
    0x800E, //6
    18, //7
    22, //8
    33, //9
    32, //10
    55, //11
    51, //12
    50, //13
    17, //14
    16, //15
    NOT_A_PIN, //16
    NOT_A_PIN, //17
    44, //18
    19, //19
    NOT_A_PIN, //20
    NOT_A_PIN, //21
    NOT_A_PIN, //22
    0x8007, //23
    0x8009, //24
    0x8002, //25
    0x800A, //26
    0x8000, //27
    0x8008, //28
    0x8001, //29
    NOT_A_PIN, //30
    41, //31
    40, //32
    NOT_A_PIN, //33
    13, //34
    5, //35
    4, //36
    3, //37
    2, //38
    1, //39
    0, //40
    
    
    
    //Second set of headers
    NOT_A_PIN, //1
    NOT_A_PIN, //2
    15, //3
    58, //4
    20, //5
    NOT_A_PIN, //6
    14, //7
    21, //8
    23, //9
    54, //10
    56, //11
    53, //12
    52, //13
    25, //14
    24, //15
    NOT_A_PIN, //16
    NOT_A_PIN, //17
    26, //18
    27, //19
    NOT_A_PIN, //20
    NOT_A_PIN, //21
    NOT_A_PIN, //22
    0x800F, //23
    0x800C, //24
    0x8005, //25
    0x800D, //26
    0x8003, //27
    0x800B, //28
    0x8004, //29
    NOT_A_PIN, //30
    43, //31
    42, //32
    NOT_A_PIN, //33
    NOT_A_PIN, //34
    11, //35
    10, //36
    9, //37
    8, //38
    7, //39
    6, //40
    
    
    //Miscellaneous pins
    34, //81 Red LED
    39, //82 Blue LED
    30, //83 CAN RX
    31, //84 CAN TX
    20, //85 EQEP1A
    21, //86 EQEP1B
    23, //87 EQEP1I
    54, //88 EQEP2A
    55, //89 EQEP2B
    56, //90 EQEP2I
    
    
};



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
	(const uint32_t *) &GpioCtrlRegs.GPBMUX2.all,
	NOT_A_PORT
};

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

const uint32_t digital_pin_to_timer[] = {
	PWM1A,        	//GPIO 0  
	PWM1B,        	//GPIO 1  
	PWM2A,        	//GPIO 2  
	PWM2B,        	//GPIO 3  
	PWM3A,        	//GPIO 4  
	PWM3B,        	//GPIO 5  
	PWM4A, 			//GPIO 6  
	PWM4B, 			//GPIO 7  
	PWM5A,			//GPIO8 
	PWM5B,			//GPIO9 
	PWM6A,			//GPIO10 	
	PWM6B,			//GPIO11 
	NOT_ON_TIMER, 	//GPIO12 
	NOT_ON_TIMER, 	//GPIO13 
	NOT_ON_TIMER, 	//GPIO14 
	NOT_ON_TIMER, 	//GPIO15 
	NOT_ON_TIMER, 	//GPIO16   
	NOT_ON_TIMER, 	//GPIO17   
	NOT_ON_TIMER, 	//GPIO18 
	NOT_ON_TIMER, 	//GPIO19 
	NOT_ON_TIMER, 	//GPIO20 
	NOT_ON_TIMER, 	//GPIO21
	NOT_ON_TIMER, 	//GPIO22
	NOT_ON_TIMER, 	//GPIO23
	NOT_ON_TIMER, 	//GPIO24
	NOT_ON_TIMER, 	//GPIO25
	NOT_ON_TIMER, 	//GPIO26
	NOT_ON_TIMER, 	//GPIO27
	NOT_ON_TIMER, 	//GPIO28
	NOT_ON_TIMER, 	//GPIO29
	NOT_ON_TIMER, 	//GPIO30
	NOT_ON_TIMER, 	//GPIO31
	NOT_ON_TIMER, 	//GPIO32
	NOT_ON_TIMER, 	//GPIO33
	NOT_ON_TIMER, 	//GPIO34
	NOT_ON_TIMER, 	//GPIO35
	NOT_ON_TIMER, 	//GPIO36
	NOT_ON_TIMER, 	//GPIO37
	NOT_ON_TIMER, 	//GPIO38
	NOT_ON_TIMER, 	//GPIO39
	PWM7A,			//GPIO40
	PWM7B,			//GPIO41
	PWM8A,			//GPIO42
	PWM8B,			//GPIO43
	NOT_ON_TIMER, 	//GPIO44
	NOT_ON_TIMER, 	//GPIO45
	NOT_ON_TIMER, 	//GPIO46
	NOT_ON_TIMER, 	//GPIO47
	NOT_ON_TIMER, 	//GPIO48
	NOT_ON_TIMER, 	//GPIO49
	NOT_ON_TIMER, 	//GPIO50
	NOT_ON_TIMER, 	//GPIO51
	NOT_ON_TIMER, 	//GPIO52
	NOT_ON_TIMER, 	//GPIO53
	NOT_ON_TIMER, 	//GPIO54
	NOT_ON_TIMER, 	//GPIO55
	NOT_ON_TIMER, 	//GPIO56
	NOT_ON_TIMER, 	//GPIO57
	NOT_ON_TIMER 	//GPIO58

};

const uint32_t digital_pin_to_port[] = {
		PORT_A_1,     	/* GPIO0 */
		PORT_A_1,     	/* GPIO1 */
		PORT_A_1,     	/* GPIO2 */
		PORT_A_1,     	/* GPIO3 */
		PORT_A_1,     	/* GPIO4 */
		PORT_A_1,     	/* GPIO5 */
		PORT_A_1,     	/* GPIO6 */
		PORT_A_1,     	/* GPIO7 */
		PORT_A_1,		/* GPIO8 */
		PORT_A_1,		/* GPIO9 */
		PORT_A_1,		/* GPIO10 */
		PORT_A_1,		/* GPIO11 */
		PORT_A_1,		/* GPIO12 */
		PORT_A_1,		/* GPIO13 */
		PORT_A_1,		/* GPIO14 */
		PORT_A_1,		/* GPIO15 */
		PORT_A_2,     /* GPIO16 */
		PORT_A_2,     /* GPIO17 */
		PORT_A_2,     /* GPIO18 */
		PORT_A_2,     /* GPIO19 */
		PORT_A_2,     /* GPIO20 */
		PORT_A_2,     /* GPIO21 */
		PORT_A_2,     /* GPIO22 */
		PORT_A_2,     /* GPIO23 */
		PORT_A_2,     /* GPIO24 */
		PORT_A_2,     /* GPIO25 */
		PORT_A_2,     /* GPIO26 */
		PORT_A_2,     /* GPIO27 */
		PORT_A_2,     /* GPIO28 */
		PORT_A_2,     /* GPIO29 */
		PORT_A_2,     /* GPIO30 */
		PORT_A_2,     /* GPIO31 */
		PORT_B_1,     /* GPIO32 */
		PORT_B_1,     /* GPIO33 */
		PORT_B_1,     /* GPIO34 */
		PORT_B_1,     /* GPIO35 */
		PORT_B_1,     /* GPIO36 */
		PORT_B_1,     /* GPIO37 */
		PORT_B_1,     /* GPIO38 */
		PORT_B_1,     /* GPIO39 */
		PORT_B_1,     /* GPIO40 */
		PORT_B_1,     /* GPIO41 */
		PORT_B_1,     /* GPIO42 */
		PORT_B_1,     /* GPIO43 */
		PORT_B_1,     /* GPIO44 */
		NOT_A_PIN,     /* GPIO45 */
		NOT_A_PIN,     /* GPIO46 */
		NOT_A_PIN,     /* GPIO47 */
		NOT_A_PIN,     /* GPIO48 */
		NOT_A_PIN,     /* GPIO49 */
		PORT_B_2,     /* GPIO50 */
		PORT_B_2,     /* GPIO51 */
		PORT_B_2,     /* GPIO52 */
		PORT_B_2,     /* GPIO53 */
		PORT_B_2,     /* GPIO54 */
		PORT_B_2,     /* GPIO55 */
		PORT_B_2,     /* GPIO56 */
		PORT_B_2,     /* GPIO57 */
		PORT_B_2     /* GPIO58 */
};

const uint32_t digital_pin_to_bit_mask[] = {
	BV(0),     	/* GPIO0 */
	BV(1),     	/* GPIO1 */
	BV(2),     	/* GPIO2 */
	BV(3),     	/* GPIO3 */
	BV(4),     	/* GPIO4 */
	BV(5),     	/* GPIO5 */
	BV(6),     	/* GPIO6 */
	BV(7),     	/* GPIO7 */
	BV(8), 		/* GPIO8 */
	BV(9), 		/* GPIO9 */
	BV(10), 	/* GPIO10 */
	BV(11), 	/* GPIO11 */
	BV(12),     /* GPIO12 */
	BV(13), 	/* GPIO13 */
	BV(14), 	/* GPIO14 */
	BV(15), 	/* GPIO15 */
	BV(16),     /* GPIO16 */
	BV(17),     /* GPIO17 */
	BV(18),     /* GPIO18 */
	BV(19),     /* GPIO19 */
	BV(20), 	/* GPIO20 */
	BV(21), 	/* GPIO21 */
	BV(22), 	/* GPIO22 */
	BV(23), 	/* GPIO23 */
	BV(24), 	/* GPIO24 */
	BV(25), 	/* GPIO25 */
	BV(26), 	/* GPIO26 */
	BV(27), 	/* GPIO27 */
	BV(28),     /* GPIO28 */
	BV(29),     /* GPIO29 */
	BV(30), 	/* GPIO30 */
	BV(31), 	/* GPIO31 */
	BV(32-32),  /* GPIO32 */
	BV(33-32),  /* GPIO33 */
	BV(34-32),  /* GPIO34 */
	BV(35-32),  /* GPIO35 */
	BV(36-32),  /* GPIO36 */
	BV(37-32),  /* GPIO37 */
	BV(38-32),  /* GPIO38 */
	BV(39-32),  /* GPIO39 */
	BV(40-32),  /* GPIO40 */
	BV(41-32),  /* GPIO41 */
	BV(42-32),  /* GPIO42 */
	BV(43-32),  /* GPIO43 */
	BV(44-32),  /* GPIO44 */
	NOT_A_PIN,  /* GPIO45 */
	NOT_A_PIN,  /* GPIO46 */
	NOT_A_PIN,  /* GPIO47 */
	NOT_A_PIN,  /* GPIO48 */
	NOT_A_PIN,  /* GPIO49 */
	BV(50-32),  /* GPIO50 */
	BV(51-32),  /* GPIO51 */
	BV(52-32),  /* GPIO52 */
	BV(53-32),  /* GPIO53 */
	BV(54-32),  /* GPIO54 */
	BV(55-32),  /* GPIO54 */
	BV(56-32),  /* GPIO56 */
	BV(57-32),  /* GPIO57 */
	BV(58-32)  /* GPIO58 */

};
#endif
#endif
