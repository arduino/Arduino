//###########################################################################
//
// FILE:	F2837xS_Gpio_defines.h
//
// TITLE:	F2837xS GPIO support definitions
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#ifndef F2837xS_GPIO_DEFINES_H
#define F2837xS_GPIO_DEFINES_H

//--------------------------------------------
// Defines
//--------------------------------------------

//CPU pin masters for GPIO_SelectPinMux()
#define GPIO_MUX_CPU1		0x0
#define GPIO_MUX_CPU1CLA	0x1
#define GPIO_MUX_CPU2		0x2
#define GPIO_MUX_CPU2CLA	0x3

//Flags for GPIO_SetupPinOptions(). The qualification flags (SYNC, QUAL3,
//QUAL6, and ASYNC) take up two bits and must be in the order specified.
#define GPIO_INPUT		0
#define GPIO_OUTPUT		1
#define GPIO_PUSHPULL   0
#define GPIO_PULLUP		(1 << 0)
#define GPIO_INVERT		(1 << 1)
#define GPIO_OPENDRAIN	(1 << 2)
#define GPIO_SYNC		(0x0 << 4)
#define GPIO_QUAL3		(0x1 << 4)
#define GPIO_QUAL6		(0x2 << 4)
#define GPIO_ASYNC		(0x3 << 4)

//Flags for GPIO_SetupLock().
#define GPIO_UNLOCK		0
#define GPIO_LOCK		1

//Commands for the CPU2->CPU1 GPIO configuration interrupt handler
#define GPIO_CMD_INIT		1L
#define GPIO_CMD_PINMUX		2L
#define GPIO_CMD_PINOPTS	3L
#define GPIO_CMD_WRITE32	4L
#define GPIO_CMD_WRITE16	5L
#define GPIO_CMD_READ32		6L
#define GPIO_CMD_READ16		7L

//Helpful constants for array-based access to GPIO registers
#define GPY_CTRL_OFFSET	(0x40/2)
#define GPY_DATA_OFFSET	(0x8/2)

#define GPYQSEL		(0x2/2)
#define GPYMUX		(0x6/2)
#define GPYDIR		(0xA/2)
#define GPYPUD		(0xC/2)
#define GPYINV		(0x10/2)
#define GPYODR		(0x12/2)
#define GPYGMUX		(0x20/2)
#define GPYCSEL		(0x28/2)
#define GPYLOCK		(0x3C/2)
#define GPYCR		(0x3E/2)

#define GPYDAT		(0x0/2)
#define GPYSET		(0x2/2)
#define GPYCLEAR	(0x4/2)
#define GPYTOGGLE	(0x6/2)

#endif  // end of F2837xS_GPIO_DEFINES_H definition

//===========================================================================
// End of file.
//===========================================================================
