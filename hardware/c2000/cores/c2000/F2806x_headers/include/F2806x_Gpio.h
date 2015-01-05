//###########################################################################
//
// FILE:   F2806x_Gpio.h
//
// TITLE:  F2806x Device GPIO Register Definitions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $   
// $Release Date: April 7, 2011 $   
//###########################################################################

#ifndef F2806x_GPIO_H
#define F2806x_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// GPIO Individual Register Bit Definitions:

struct GPACTRL_BITS {     // bits description
	Uint16	QUALPRD0:8;			// 7:0	GPIO0 to 7 Qual Cycles
	Uint16	QUALPRD1:8;			// 15:8	GPIO8 to 15 Qual Cycles
	Uint16	QUALPRD2:8;			// 23:16	GPIO16 to 23 Qual Cycles
	Uint16	QUALPRD3:8;			// 31:24	GPIO24 to 31 Qual Cycles
};

union GPACTRL_REG {
	Uint32 all;
	struct GPACTRL_BITS	bit;
};

struct GPACTRL2_BITS {	// bits description
	Uint16	USB0IOEN:1;		// 0	USB I/O Enable Bit
	Uint16	rsvd1:15;		// 15:1	Reserved
};

union GPACTRL2_REG {
	Uint16	all;
	struct GPACTRL2_BITS	bit;
};

struct GPBCTRL_BITS {     // bits description
	Uint16	QUALPRD0:8;			// 7:0	GPIO32 to 39 Qual Cycles
	Uint16	QUALPRD1:8;			// 15:8	GPIO40 to 47 Qual Cycles
	Uint16	QUALPRD2:8;			// 23:16	GPIO48 to 55 Qual Cycles
	Uint16	QUALPRD3:8;			// 31:24	GPIO56 to 63 Qual Cycles
};

union GPBCTRL_REG {
	Uint32 all;
	struct GPBCTRL_BITS	bit;
};

struct GPA1_BITS {     // bits description
	Uint16	GPIO0:2;			// 1:0	GPIO0
	Uint16	GPIO1:2;			// 3:2	GPIO1
	Uint16	GPIO2:2;			// 5:4	GPIO2
	Uint16	GPIO3:2;			// 7:6	GPIO3
	Uint16	GPIO4:2;			// 9:8	GPIO4
	Uint16	GPIO5:2;			// 11:10	GPIO5
	Uint16	GPIO6:2;			// 13:12	GPIO6
	Uint16	GPIO7:2;			// 15:14	GPIO7
	Uint16	GPIO8:2;			// 17:16	GPIO8
	Uint16	GPIO9:2;			// 19:18	GPIO9
	Uint16	GPIO10:2;			// 21:20	GPIO10
	Uint16	GPIO11:2;			// 23:22	GPIO11
	Uint16	GPIO12:2;			// 25:24	GPIO12
	Uint16	GPIO13:2;			// 27:26	GPIO13
	Uint16	GPIO14:2;			// 29:28	GPIO14
	Uint16	GPIO15:2;			// 31:30	GPIO15
};

union GPA1_REG {
	Uint32 all;
	struct GPA1_BITS	bit;
};

struct GPA2_BITS {     // bits description
	Uint16	GPIO16:2;			// 1:0	GPIO16
	Uint16	GPIO17:2;			// 3:2	GPIO17
	Uint16	GPIO18:2;			// 5:4	GPIO18
	Uint16	GPIO19:2;			// 7:6	GPIO19
	Uint16	GPIO20:2;			// 9:8	GPIO20
	Uint16	GPIO21:2;			// 11:10	GPIO21
	Uint16	GPIO22:2;			// 13:12	GPIO22
	Uint16	GPIO23:2;			// 15:14	GPIO23
	Uint16	GPIO24:2;			// 17:16	GPIO24
	Uint16	GPIO25:2;			// 19:18	GPIO25
	Uint16	GPIO26:2;			// 21:20	GPIO26
	Uint16	GPIO27:2;			// 23:22	GPIO27
	Uint16	GPIO28:2;			// 25:24	GPIO28
	Uint16	GPIO29:2;			// 27:26	GPIO29
	Uint16	GPIO30:2;			// 29:28	GPIO30
	Uint16	GPIO31:2;			// 31:30	GPIO31
};

union GPA2_REG {
	Uint32 all;
	struct GPA2_BITS	bit;
};

struct GPB1_BITS {     // bits description
	Uint16	GPIO32:2;			// 1:0	GPIO32
	Uint16	GPIO33:2;			// 3:2	GPIO33
	Uint16	GPIO34:2;			// 5:4	GPIO34
	Uint16	GPIO35:2;			// 7:6	GPIO35
	Uint16	GPIO36:2;			// 9:8	GPIO36
	Uint16	GPIO37:2;			// 11:10	GPIO37
	Uint16	GPIO38:2;			// 13:12	GPIO38
	Uint16	GPIO39:2;			// 15:14	GPIO39
	Uint16	GPIO40:2;			// 17:16	GPIO40
	Uint16	GPIO41:2;			// 19:18	GPIO41
	Uint16	GPIO42:2;			// 21:20	GPIO42
	Uint16	GPIO43:2;			// 23:22	GPIO43
	Uint16	GPIO44:2;			// 25:24	GPIO44
	Uint16	rsvd1:6;			// 31:26	Reserved
};

union GPB1_REG {
	Uint32 all;
	struct GPB1_BITS	bit;
};

struct GPB2_BITS {     // bits description
	Uint16	rsvd1:4;			// 3:0	Reserved
	Uint16	GPIO50:2;			// 5:4	GPIO50
	Uint16	GPIO51:2;			// 7:6	GPIO51
	Uint16	GPIO52:2;			// 9:8	GPIO52
	Uint16	GPIO53:2;			// 11:10	GPIO53
	Uint16	GPIO54:2;			// 13:12	GPIO54
	Uint16	GPIO55:2;			// 15:14	GPIO55
	Uint16	GPIO56:2;			// 17:16	GPIO56
	Uint16	GPIO57:2;			// 19:18	GPIO57
	Uint16	GPIO58:2;			// 21:20	GPIO58
	Uint16	rsvd2:10;			// 31:22	Reserved
};

union GPB2_REG {
	Uint32 all;
	struct GPB2_BITS	bit;
};

struct AIO_BITS {     // bits description
	Uint16	rsvd1:2;			// 1:0	Reserved
	Uint16	rsvd2:2;			// 3:2	Reserved
	Uint16	AIO2:2;				// 5:4	AIO2
	Uint16	rsvd3:2;			// 7:6	Reserved
	Uint16	AIO4:2;				// 9:8	AIO4
	Uint16	rsvd4:2;			// 11:10	Reserved
	Uint16	AIO6:2;				// 13:12	AIO6
	Uint16	rsvd5:2;			// 15:14	Reserved
	Uint16	rsvd6:2;			// 17:16	Reserved
	Uint16	rsvd7:2;			// 19:18	Reserved
	Uint16	AIO10:2;			// 21:20	AIO10
	Uint16	rsvd8:2;			// 23:22	Reserved
	Uint16	AIO12:2;			// 25:24	AIO12
	Uint16	rsvd9:2;			// 27:26	Reserved
	Uint16	AIO14:2;			// 29:28	AIO14
	Uint16	rsvd10:2;			// 31:30	Reserved
};

union AIO_REG {
	Uint32 all;
	struct AIO_BITS	bit;
};

struct GPADAT_BITS {     // bits description
	Uint16	GPIO0:1;			// 0	GPIO0 Data
	Uint16	GPIO1:1;			// 1	GPIO1 Data
	Uint16	GPIO2:1;			// 2	GPIO2 Data
	Uint16	GPIO3:1;			// 3	GPIO3 Data
	Uint16	GPIO4:1;			// 4	GPIO4 Data
	Uint16	GPIO5:1;			// 5	GPIO5 Data
	Uint16	GPIO6:1;			// 6	GPIO6 Data
	Uint16	GPIO7:1;			// 7	GPIO7 Data
	Uint16	GPIO8:1;			// 8	GPIO8 Data
	Uint16	GPIO9:1;			// 9	GPIO9 Data
	Uint16	GPIO10:1;			// 10	GPIO10 Data
	Uint16	GPIO11:1;			// 11	GPIO11 Data
	Uint16	GPIO12:1;			// 12	GPIO12 Data
	Uint16	GPIO13:1;			// 13	GPIO13 Data
	Uint16	GPIO14:1;			// 14	GPIO14 Data
	Uint16	GPIO15:1;			// 15	GPIO15 Data
	Uint16	GPIO16:1;			// 16	GPIO16 Data
	Uint16	GPIO17:1;			// 17	GPIO17 Data
	Uint16	GPIO18:1;			// 18	GPIO18 Data
	Uint16	GPIO19:1;			// 19	GPIO19 Data
	Uint16	GPIO20:1;			// 20	GPIO20 Data
	Uint16	GPIO21:1;			// 21	GPIO21 Data
	Uint16	GPIO22:1;			// 22	GPIO22 Data
	Uint16	GPIO23:1;			// 23	GPIO23 Data
	Uint16	GPIO24:1;			// 24	GPIO24 Data
	Uint16	GPIO25:1;			// 25	GPIO25 Data
	Uint16	GPIO26:1;			// 26	GPIO26 Data
	Uint16	GPIO27:1;			// 27	GPIO27 Data
	Uint16	GPIO28:1;			// 28	GPIO28 Data
	Uint16	GPIO29:1;			// 29	GPIO29 Data
	Uint16	GPIO30:1;			// 30	GPIO30 Data
	Uint16	GPIO31:1;			// 31	GPIO31 Data
};

union GPADAT_REG {
	Uint32 all;
	struct GPADAT_BITS	bit;
};

struct GPBDAT_BITS {     // bits description
	Uint16	GPIO32:1;			// 0	GPIO32 Data
	Uint16	GPIO33:1;			// 1	GPIO33 Data
	Uint16	GPIO34:1;			// 2	GPIO34 Data
	Uint16	GPIO35:1;			// 3	GPIO35 Data
	Uint16	GPIO36:1;			// 4	GPIO36 Data
	Uint16	GPIO37:1;			// 5	GPIO37 Data
	Uint16	GPIO38:1;			// 6	GPIO38 Data
	Uint16	GPIO39:1;			// 7	GPIO39 Data
	Uint16	GPIO40:1;			// 8	GPIO40 Data
	Uint16	GPIO41:1;			// 9	GPIO41 Data
	Uint16	GPIO42:1;			// 10	GPIO42 Data
	Uint16	GPIO43:1;			// 11	GPIO43 Data
	Uint16	GPIO44:1;			// 12	GPIO44 Data
	Uint16	rsvd1:3;			// 15:13	Reserved
	Uint16	rsvd2:2;			// 17:16	Reserved
	Uint16	GPIO50:1;			// 18	GPIO50 Data
	Uint16	GPIO51:1;			// 19	GPIO51 Data
	Uint16	GPIO52:1;			// 20	GPIO52 Data
	Uint16	GPIO53:1;			// 21	GPIO53 Data
	Uint16	GPIO54:1;			// 22	GPIO54 Data
	Uint16	GPIO55:1;			// 23	GPIO55 Data
	Uint16	GPIO56:1;			// 24	GPIO56 Data
	Uint16	GPIO57:1;			// 25	GPIO57 Data
	Uint16	GPIO58:1;			// 26	GPIO58 Data
	Uint16	rsvd3:5;			// 31:27	Reserved
};

union GPBDAT_REG {
	Uint32 all;
	struct GPBDAT_BITS	bit;
};

struct AIODAT_BITS {     // bits description
	Uint16	rsvd1:1;			// 0	Reserved
	Uint16	rsvd2:1;			// 1	Reserved
	Uint16	AIO2:1;				// 2	AIO2
	Uint16	rsvd3:1;			// 3	Reserved
	Uint16	AIO4:1;				// 4	AIO4
	Uint16	rsvd4:1;			// 5	Reserved
	Uint16	AIO6:1;				// 6	AIO6
	Uint16	rsvd5:1;			// 7	Reserved
	Uint16	rsvd6:1;			// 8	Reserved
	Uint16	rsvd7:1;			// 9	Reserved
	Uint16	AIO10:1;			// 10	AIO10
	Uint16	rsvd8:1;			// 11	Reserved
	Uint16	AIO12:1;			// 12	AIO12
	Uint16	rsvd9:1;			// 13	Reserved
	Uint16	AIO14:1;			// 14	AIO14
	Uint16	rsvd10:1;			// 15	Reserved
	Uint16	rsvd11:16;			// 31:16 Reserved
};

union AIODAT_REG {
	Uint32 all;
	struct AIODAT_BITS	bit;
};

struct GPIOXINT_BITS {     // bits description
	Uint16	GPIOSEL:5;			// 4:0	Select GPIO Interrupt Input Source
	Uint16	rsvd1:11;			// 15:5	Reserved
};

union GPIOXINT_REG {
	Uint16 all;
	struct GPIOXINT_BITS	bit;
};

struct GPIO_CTRL_REGS {
	union	GPACTRL_REG		GPACTRL;	// GPIO A Control Register (GPIO0 to 31)
	union	GPA1_REG		GPAQSEL1;	// GPIO A Qualifier Select 1 Register (GPIO0 to 15)
	union	GPA2_REG		GPAQSEL2;	// GPIO A Qualifier Select 2 Register (GPIO16 to 31)
	union	GPA1_REG		GPAMUX1;	// GPIO A Mux 1 Register (GPIO0 to 15)
	union	GPA2_REG		GPAMUX2;	// GPIO A Mux 2 Register (GPIO16 to 31)
	union	GPADAT_REG		GPADIR;		// GPIO A Direction Register (GPIO0 to 31) )
	union	GPADAT_REG		GPAPUD;		// GPIO A Pull-Up Disable Register
	union	GPACTRL2_REG	GPACTRL2;	// GPIO A Control Register 2
	Uint16					rsvd1;		// Reserved
	union	GPBCTRL_REG		GPBCTRL;	// GPIO B Control Register (GPIO32 to 63)
	union	GPB1_REG		GPBQSEL1;	// GPIO B Qualifier Select 1 Register (GPIO32 to 47)
	union	GPB2_REG		GPBQSEL2;	// GPIO B Qualifier Select 2 Register (GPIO48 to 63)
	union	GPB1_REG		GPBMUX1;	// GPIO B Mux 1 Register (GPIO32 to 47)
	union	GPB2_REG		GPBMUX2;	// GPIO B Mux 2 Register (GPIO48 to 63)
	union	GPBDAT_REG		GPBDIR;		// GPIO B Direction Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBPUD;		// GPIO B Pull-Up Disable Register
	Uint16					rsvd2[24];	// Reserved
	union	AIO_REG			AIOMUX1;	// Analog IO Mux 1 Register
	Uint16					rsvd3[2];	// Reserved
	union	AIODAT_REG		AIODIR;		// Analog IO Direction Register
	Uint16					rsvd4[4];	// Reserved
};

struct GPIO_DATA_REGS {
	union	GPADAT_REG		GPADAT;		// GPIO A Data Register (GPIO0 to 31)
	union	GPADAT_REG		GPASET;		// GPIO A Data Set Register (GPIO0 to 31)
	union	GPADAT_REG		GPACLEAR;	// GPIO A Data Clear Register (GPIO0 to 31)
	union	GPADAT_REG		GPATOGGLE;	// GPIO A Data Toggle Register (GPIO0 to 31)
	union	GPBDAT_REG		GPBDAT;		// GPIO B Data Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBSET;		// GPIO B Data Set Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBCLEAR;	// GPIO B Data Clear Register (GPIO32 to 63)
	union	GPBDAT_REG		GPBTOGGLE;	// GPIO B Data Toggle Register (GPIO32 to 63)
	Uint16					rsvd1[8];	// Reserved
	union	AIODAT_REG		AIODAT;		// Analog IO Data Register (AIO0 to 15)
	union	AIODAT_REG		AIOSET;		// Analog IO Data Set Register (AIO0 to 15)
	union	AIODAT_REG		AIOCLEAR;	// Analog IO Data Clear Register (AIO0 to 15)
	union	AIODAT_REG		AIOTOGGLE;	// Analog IO Data Toggle Register (AIO0 to 15)
};

struct GPIO_INT_REGS {
	union	GPIOXINT_REG	GPIOXINT1SEL;	// XINT1 GPIO Input Select Register (GPIO0 to 31)
	union	GPIOXINT_REG	GPIOXINT2SEL;	// GPTRIP2 (TZ2n) Input Select Register (GPIO0 to 63)
	union	GPIOXINT_REG	GPIOXINT3SEL;	// GPTRIP3 (TZ3n) Input Select Register (GPIO0 to 63)
	Uint16					rsvd1[5];		// Reserved
	union	GPADAT_REG		GPIOLPMSEL;		// GPTRIP5 (XINT2) Input Select Register (GPIO0 to 63)
	Uint16					rsvd2[22];		// Reserved
};

//---------------------------------------------------------------------------
// Gpio External References & Function Declarations:
//
extern volatile struct GPIO_CTRL_REGS GpioCtrlRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;
extern volatile struct GPIO_INT_REGS  GpioIntRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of F2806x_GPIO_H definition
//===========================================================================
// End of file.
//===========================================================================
