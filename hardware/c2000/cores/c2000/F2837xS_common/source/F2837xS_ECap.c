//###########################################################################
// FILE:   F2837xS_ECap.c
// TITLE:  F2837xS eCAP Initialization & Support Functions.
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // F2837xS Headerfile Include File
#include "F2837xS_Examples.h"   // F2837xS Examples Include File

//---------------------------------------------------------------------------
// InitECap:
//---------------------------------------------------------------------------
// This function initializes the eCAP(s) to a known state.
void InitECap(void)
{
    // Initialize eCAP1/2/3/4/5/6

    //tbd...

}

//---------------------------------------------------------------------------
// Example: InitECapGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ECAP pins
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
// Caution:
// For each eCAP peripheral
// Only one GPIO pin should be enabled for ECAP operation.
// Comment out other unwanted lines.

void InitECapGpio()
{
}

void InitECap1Gpio(Uint16 pin)
{
	EALLOW;
	InputXbarRegs.INPUT7SELECT = pin; 		// Set eCAP1 source to GPIO-pin
	EDIS;
}

void InitECap2Gpio(Uint16 pin)
{
	EALLOW;
	InputXbarRegs.INPUT8SELECT = pin; 		// Set eCAP2 source to GPIO-pin
	EDIS;
}

void InitECap3Gpio(Uint16 pin)
{
	EALLOW;
	InputXbarRegs.INPUT9SELECT = pin; 		// Set eCAP3 source to GPIO-pin
	EDIS;
}

void InitECap4Gpio(Uint16 pin)
{
	EALLOW;
	InputXbarRegs.INPUT10SELECT = pin; 		// Set eCAP4 source to GPIO-pin
	EDIS;
}

void InitECap5Gpio(Uint16 pin)
{
	EALLOW;
	InputXbarRegs.INPUT11SELECT = pin; 		// Set eCAP5 source to GPIO-pin
	EDIS;
}

void InitECap6Gpio(Uint16 pin)
{
	EALLOW;
	InputXbarRegs.INPUT12SELECT = pin; 		// Set eCAP6 source to GPIO-pin
	EDIS;
}

void InitAPwm1Gpio()
{
	EALLOW;
	OutputXbarRegs.OUTPUT3MUX0TO15CFG.bit.MUX0 = 3;	// Select ECAP1.OUT on Mux0
	OutputXbarRegs.OUTPUT3MUXENABLE.bit.MUX0 = 1;	// Enable MUX0 for ECAP1.OUT
	GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 3;	// Select OUTPUTXBAR3 on GPIO5
	EDIS;
}
//===========================================================================
// End of file.
//===========================================================================
