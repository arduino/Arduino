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

static const uint8_t SCK  = 7; //SPICLKA
static const uint8_t MOSI = 15; //SPISIMOA
static const uint8_t MISO = 14; //SPISOMIA

static const uint8_t SDA = 10; //I2C SDAA
static const uint8_t SCL = 9; //I2C SCLA

static const uint8_t RX = 0; //SCI RXA
static const uint8_t TX = 0; //SCI TXA

static const uint8_t BLUE_LED = 39; //GPIO13
static const uint8_t GREEN_LED = 39; //Redeclare so that examples that use this still work?
static const uint8_t RED_LED = 40; //GPIO12


static const uint8_t AA0 = 27;  //A0 0x8000
static const uint8_t AA1 = 29;	//A1 0x8001
static const uint8_t AA2 = 64;	//A2 0x8002
static const uint8_t AA3 = 67;	//A3 0x8003
static const uint8_t AA4 = 69;	//A4 0x8004
static const uint8_t AA5 = 65;	//A5 0x8005
static const uint8_t AB0 = 28;  //B0 0x8006
static const uint8_t AB1 = 24;  //B1 0x8007
static const uint8_t AB2 = 26;  //B2 0x8008
static const uint8_t AB3 = 68;  //B3 0x8009
static const uint8_t AB4 = 25;  //B4 0x800A
static const uint8_t AB5 = 66;  //B5 0x800B
static const uint8_t A14 = 23;  //14 0x800C
static const uint8_t A15 = 63;  //15 0x800D


// Pin names based on GPIO numbers
//
static const uint8_t P2 = 80; //GPIO2 ePWM2A
static const uint8_t P3 = 79; //GPIO3 ePWM2B
static const uint8_t P4 = 19; //GPIO4! ePWM3A
static const uint8_t P10 = 78; //GPIO10 ePWM6A
static const uint8_t P11 = 77; //GPIO11 ePWM6B
static const uint8_t P12 = 40; //GPIO12 RED LED ePWM7A
static const uint8_t P13 = 39; //GPIO13 BLUE LED ePWM7B
static const uint8_t P14 = 38; //GPIO14 ePWM8A
static const uint8_t P15 = 37; //GPIO15 ePWM8B
static const uint8_t P16 = 36; //GPIO16 ePWM9A
static const uint8_t P17 = 35; //GPIO17 ePWM9B
static const uint8_t P18 = 76; //GPIO18 DAC3 ePWM10A
static const uint8_t P19 = 75; //GPIO19 DAC4 ePWM10B
static const uint8_t P20 = 34; //GPIO20! DAC1 ePWM11A
static const uint8_t P21 = 33; //GPIO21! DAC2 ePWM11B
static const uint8_t P41 = 5; //GPIO41
static const uint8_t P42 = 10; //GPIO42 SDAA@
static const uint8_t P43 = 9; //GPIO43 SCLA@
static const uint8_t P58 = 15; //GPIO58 SPISIMOA@
static const uint8_t P59 = 14; //GPIO59 SPISOMIA@
static const uint8_t P60 = 7; //GPIO60 SPICLKA@
static const uint8_t P61 = 8; //GPIO61!
static const uint8_t P62 = 18; //GPIO62!
static const uint8_t P63 = 55; //GPIO63 SPISIMOB@
static const uint8_t P64 = 54; //GPIO64 SPISOMIB@
static const uint8_t P65 = 47; //GPIO65 SPICLKB@
static const uint8_t P66 = 50; //GPIO66 SDAB@
static const uint8_t P69 = 49; //GPIO69 SCLB@/SPISIMOC
static const uint8_t P70 = 0; //GPIO70 CANRXA@/SPISOMIC
static const uint8_t P71 = 2; //GPIO71 CANTXA@/SPICLKC
static const uint8_t P72 = 13; //GPIO72 SCITXDC
static const uint8_t P73 = 12; //GPIO73 SCIRXDC
static const uint8_t P78 = 11; //GPIO78!
static const uint8_t P84 = 0; //GPIO84 SCITXDA, no physical pin because main communication
static const uint8_t P85 = 0; //GPIO85 SCIRXDA, no physical pin because main communication
static const uint8_t P86 = 44; //GPIO86 SCITXDB@
static const uint8_t P87 = 43; //GPIO87 SCIRXDB@
static const uint8_t P89 = 4; //GPIO89 SCITXDC@
static const uint8_t P90 = 3; //GPIO90 SCIRXDC@
static const uint8_t P91 = 59; //GPIO91
static const uint8_t P92 = 52; //GPIO92
static const uint8_t P99 = 53; //GPIO99

// Alternate Names

static const uint8_t RX_A = 0;
static const uint8_t TX_A = 0;
static const uint8_t SCK_A = 7;
static const uint8_t MOSI_A = 15;
static const uint8_t MISO_A = 14;
static const uint8_t SCL_A = 9;
static const uint8_t SDA_A = 10;

static const uint8_t RX_B = 43;
static const uint8_t TX_B = 44;
static const uint8_t SCK_B = 47;
static const uint8_t MOSI_B = 55;
static const uint8_t MISO_B = 54;
static const uint8_t SCL_B = 49;
static const uint8_t SDA_B = 50;

static const uint8_t RX_C = 3;
static const uint8_t TX_C = 4;
static const uint8_t SCK_C = 2;
static const uint8_t MOSI_C = 49;
static const uint8_t MISO_C = 0;


//Array used to map physical pin numbers to GPIO/AIO numbers

static const uint16_t  pin_mapping[] = {
    //First set of headers
    NOT_A_PIN, //0
    NOT_A_PIN, //1
    71, //2
    90, //3
    89, //4
    41, //5
    NOT_A_PIN, //6
    60, //7
    61, //8
    43, //9
    42, //10
    78, //11
    73, //12
    72, //13
    59, //14
    58, //15
    NOT_A_PIN, //16
    NOT_A_PIN, //17
    62, //18
    4, //19
    NOT_A_PIN, //20
    NOT_A_PIN, //21
    NOT_A_PIN, //22
    0x800C, //23
    0x8007, //24
    0x800A, //25
    0x8008, //26
    0x8000, //27
    0x8006, //28
    0x8001, //29
    NOT_A_PIN, //30
    NOT_A_PIN, //31
    NOT_A_PIN, //32
    21, //33
    20, //34
    17, //35
    16, //36
    15, //37
    14, //38
    13, //39
    12, //40
    
    
    
    //Second set of headers
    NOT_A_PIN, //1
    NOT_A_PIN, //2
    87, //3
    86, //4
    NOT_A_PIN, //5
    NOT_A_PIN, //6
    65, //7
    NOT_A_PIN, //8
    69, //9
    66, //10
    NOT_A_PIN, //11
    92, //12
    99, //13
    64, //14
    63, //15
    NOT_A_PIN, //16
    NOT_A_PIN, //17
    NOT_A_PIN, //18
    91, //19
    NOT_A_PIN, //20
    NOT_A_PIN, //21
    NOT_A_PIN, //22
    0x800D, //23
    0x8002, //24
    0x8005, //25
    0x800B, //26
    0x8003, //27
    0x8009, //28
    0x8004, //29
    NOT_A_PIN, //30
    NOT_A_PIN, //31
    NOT_A_PIN, //32
    NOT_A_PIN, //33
    NOT_A_PIN, //34
    19, //35
    18, //36
    11, //37
    10, //38
    3, //39
    2, //40
    
    /*
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
    */
    
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

//misnomer, this is for ePWM set-ups
const uint32_t digital_pin_to_timer[] = {
	NOT_ON_TIMER,        	//GPIO0  
	NOT_ON_TIMER,        	//GPIO1  
	PWM2A,        	//GPIO2  
	PWM2B,        	//GPIO3  
	PWM3A,        	//GPIO4  
	NOT_ON_TIMER,        	//GPIO5  
	NOT_ON_TIMER, 			//GPIO6  
	NOT_ON_TIMER, 			//GPIO7  
	NOT_ON_TIMER,			//GPIO8 
	NOT_ON_TIMER,			//GPIO9 
	PWM6A,			//GPIO10 	
	PWM6B,			//GPIO11 
	PWM7A, 	//GPIO12 
	PWM7B, 	//GPIO13 
	PWM8A, 	//GPIO14 
	PWM8B, 	//GPIO15 
	PWM9A, 	//GPIO16   
	PWM9B, 	//GPIO17   
	PWM10A, 	//GPIO18 
	PWM10B, 	//GPIO19 
	PWM11A, 	//GPIO20 
	PWM11B, 	//GPIO21
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
	NOT_ON_TIMER,			//GPIO40
	NOT_ON_TIMER,			//GPIO41
	NOT_ON_TIMER,			//GPIO42
	NOT_ON_TIMER,			//GPIO43
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

//? untouched
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
	NOT_A_PIN,     	/* GPIO0 */
	NOT_A_PIN,     	/* GPIO1 */
	BV(2),     	/* GPIO2 */
	BV(3),     	/* GPIO3 */
	BV(4),     	/* GPIO4 */
	NOT_A_PIN,     	/* GPIO5 */
	NOT_A_PIN,     	/* GPIO6 */
	NOT_A_PIN,     	/* GPIO7 */
	NOT_A_PIN, 		/* GPIO8 */
	NOT_A_PIN, 		/* GPIO9 */
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
	NOT_A_PIN, 	/* GPIO22 */
	NOT_A_PIN, 	/* GPIO23 */
	NOT_A_PIN, 	/* GPIO24 */
	NOT_A_PIN, 	/* GPIO25 */
	NOT_A_PIN, 	/* GPIO26 */
	NOT_A_PIN, 	/* GPIO27 */
	NOT_A_PIN,     /* GPIO28 */
	NOT_A_PIN,     /* GPIO29 */
	NOT_A_PIN, 	/* GPIO30 */
	NOT_A_PIN, 	/* GPIO31 */
	NOT_A_PIN,  /* GPIO32 */
	NOT_A_PIN,  /* GPIO33 */
	NOT_A_PIN,  /* GPIO34 */
	NOT_A_PIN,  /* GPIO35 */
	NOT_A_PIN,  /* GPIO36 */
	NOT_A_PIN,  /* GPIO37 */
	NOT_A_PIN,  /* GPIO38 */
	NOT_A_PIN,  /* GPIO39 */
	NOT_A_PIN,  /* GPIO40 */
	BV(41-32),  /* GPIO41 */
	BV(42-32),  /* GPIO42 */
	BV(43-32),  /* GPIO43 */
	NOT_A_PIN,  /* GPIO44 */
	NOT_A_PIN,  /* GPIO45 */
	NOT_A_PIN,  /* GPIO46 */
	NOT_A_PIN,  /* GPIO47 */
	NOT_A_PIN,  /* GPIO48 */
	NOT_A_PIN,  /* GPIO49 */
	NOT_A_PIN,  /* GPIO50 */
	NOT_A_PIN,  /* GPIO51 */
	NOT_A_PIN,  /* GPIO52 */
	NOT_A_PIN,  /* GPIO53 */
	NOT_A_PIN,  /* GPIO54 */
	NOT_A_PIN,  /* GPIO55 */
	NOT_A_PIN,  /* GPIO56 */
	NOT_A_PIN,  /* GPIO57 */
	BV(58-32),  /* GPIO58 */
	BV(59-32),  /* GPIO59 */
	BV(60-32),  /* GPIO60 */
	BV(61-32),  /* GPIO61 */
	BV(62-32),  /* GPIO62 */
	BV(63-32),  /* GPIO63 */
	BV(64-64),  /* GPIO64 */
	BV(65-64),  /* GPIO65 */
	BV(66-64),  /* GPIO66 */
	NOT_A_PIN,  /* GPIO67 */
	NOT_A_PIN,  /* GPIO68 */
	BV(69-64),  /* GPIO69 */
	BV(70-64),  /* GPIO70 */
	BV(71-64),  /* GPIO71 */
	BV(72-64),  /* GPIO72 */
	BV(73-64),  /* GPIO73 */
	NOT_A_PIN,  /* GPIO74 */
	NOT_A_PIN,  /* GPIO75 */
	NOT_A_PIN,  /* GPIO76 */
	NOT_A_PIN,  /* GPIO77 */
	BV(78-64),  /* GPIO78 */
	NOT_A_PIN,  /* GPIO79 */
	NOT_A_PIN,  /* GPIO80 */
	NOT_A_PIN,  /* GPIO81 */
	NOT_A_PIN,  /* GPIO82 */
	NOT_A_PIN,  /* GPIO83 */
	BV(84-64),  /* GPIO84 */
	BV(85-64),  /* GPIO85 */
	BV(86-64),  /* GPIO86 */
	BV(87-64),  /* GPIO87 */
	NOT_A_PIN,  /* GPIO88 */
	BV(89-64),  /* GPIO89 */
	BV(90-64),  /* GPIO90 */
	BV(91-64),  /* GPIO91 */
	BV(92-64),  /* GPIO92 */
	NOT_A_PIN,  /* GPIO93 */
	NOT_A_PIN,  /* GPIO94 */
	NOT_A_PIN,  /* GPIO95 */
	NOT_A_PIN,  /* GPIO96 */
	NOT_A_PIN,  /* GPIO97 */
	NOT_A_PIN,  /* GPIO98 */
	BV(99-96),  /* GPIO99 */

};
#endif
#endif
