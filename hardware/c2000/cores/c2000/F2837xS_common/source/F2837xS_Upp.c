//###########################################################################
//
// FILE:   F2837xS_Upp.c
//
// TITLE:  F2837xS Upp Initialization & Support Functions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // F2837xS Headerfile Include File
#include "F2837xS_Examples.h"   // F2837xS Examples Include File

void InitUpp1Gpio(void)
{
   EALLOW;

/* Disable internal pull-up for the selected output pins
   for reduced power consumption */
// Pull-ups can be enabled or disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;    // Disable pull-up on GPIO10 (uPP_WAIT)
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;    // Disable pull-up on GPIO11 (uPP_START)
    GpioCtrlRegs.GPAPUD.bit.GPIO12 = 1;    // Disable pull-up on GPIO12 (uPP_ENA)
    GpioCtrlRegs.GPAPUD.bit.GPIO13 = 1;    // Disable pull-up on GPIO13 (uPP_D7)
    GpioCtrlRegs.GPAPUD.bit.GPIO14 = 1;    // Disable pull-up on GPIO14 (uPP_D6)
    GpioCtrlRegs.GPAPUD.bit.GPIO15 = 1;    // Disable pull-up on GPIO15 (uPP_D5)
    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 1;    // Disable pull-up on GPIO16 (uPP_D4)
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 1;    // Disable pull-up on GPIO17 (uPP_D3)
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 1;    // Disable pull-up on GPIO18 (uPP_D2)
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 1;    // Disable pull-up on GPIO19 (uPP_D1)
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 1;    // Disable pull-up on GPIO20 (uPP_D0)
    GpioCtrlRegs.GPAPUD.bit.GPIO21 = 1;    // Disable pull-up on GPIO21 (uPP_CLK)
	
/* Disable QUAL for selected pins (ASYNC Input) */

    GpioCtrlRegs.GPAQSEL1.bit.GPIO10 = 3;    // Disable pull-up on GPIO10 (uPP_WAIT)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 3;    // Disable pull-up on GPIO11 (uPP_START)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 3;    // Disable pull-up on GPIO12 (uPP_ENA)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 3;    // Disable pull-up on GPIO13 (uPP_D7)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO14 = 3;    // Disable pull-up on GPIO14 (uPP_D6)
    GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 3;    // Disable pull-up on GPIO15 (uPP_D5)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3;    // Disable pull-up on GPIO16 (uPP_D4)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3;    // Disable pull-up on GPIO17 (uPP_D3)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3;    // Disable pull-up on GPIO18 (uPP_D2)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3;    // Disable pull-up on GPIO19 (uPP_D1)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 3;    // Disable pull-up on GPIO20 (uPP_D0)
    GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 3;    // Disable pull-up on GPIO21 (uPP_CLK)
	
/* Configure uPP-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be EPWM1 functional pins.
// Comment out other unwanted lines.

// Select Additional mux option (option 15)

    GpioCtrlRegs.GPAGMUX1.bit.GPIO10 = 3;   // Configure GPIO10 as uPP_WAIT
    GpioCtrlRegs.GPAGMUX1.bit.GPIO11 = 3;   // Configure GPIO11 as uPP_START
    GpioCtrlRegs.GPAGMUX1.bit.GPIO12 = 3;   // Configure GPIO12 as uPP_ENA
    GpioCtrlRegs.GPAGMUX1.bit.GPIO13 = 3;   // Configure GPIO13 as uPP_D7
    GpioCtrlRegs.GPAGMUX1.bit.GPIO14 = 3;   // Configure GPIO14 as uPP_D6
    GpioCtrlRegs.GPAGMUX1.bit.GPIO15 = 3;   // Configure GPIO15 as uPP_D5
    GpioCtrlRegs.GPAGMUX2.bit.GPIO16 = 3;   // Configure GPIO16 as uPP_D4
    GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 3;   // Configure GPIO17 as uPP_D3
    GpioCtrlRegs.GPAGMUX2.bit.GPIO18 = 3;   // Configure GPIO18 as uPP_D2
    GpioCtrlRegs.GPAGMUX2.bit.GPIO19 = 3;   // Configure GPIO19 as uPP_D1
    GpioCtrlRegs.GPAGMUX2.bit.GPIO20 = 3;   // Configure GPIO20 as uPP_D0
    GpioCtrlRegs.GPAGMUX2.bit.GPIO21 = 3;   // Configure GPIO21 as uPP_CLK

    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 3;   // Configure GPIO10 as uPP_WAIT
    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 3;   // Configure GPIO11 as uPP_START
    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 3;   // Configure GPIO12 as uPP_ENA
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 3;   // Configure GPIO13 as uPP_D7
    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 3;   // Configure GPIO14 as uPP_D6
    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 3;   // Configure GPIO15 as uPP_D5
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 3;   // Configure GPIO16 as uPP_D4
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 3;   // Configure GPIO17 as uPP_D3
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 3;   // Configure GPIO18 as uPP_D2
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 3;   // Configure GPIO19 as uPP_D1
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 3;   // Configure GPIO20 as uPP_D0
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 3;   // Configure GPIO21 as uPP_CLK


    EDIS;
}

void SoftResetUpp(void)
{
	   UppRegs.PERCTL.bit.SOFTRST = 1;  // Issue uPP Internal Reset.
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   asm("          NOP");
	   UppRegs.PERCTL.bit.SOFTRST = 0;  // Release uPP Internal Reset.
}


