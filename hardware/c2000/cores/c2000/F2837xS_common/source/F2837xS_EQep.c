//###########################################################################
//
// FILE:   F2837xS_EQep.c
//
// TITLE:  F2837xS eQEP Initialization & Support Functions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // F2837xS Headerfile Include File
#include "F2837xS_Examples.h"   // F2837xS Examples Include File

//---------------------------------------------------------------------------
// InitEQep:
//---------------------------------------------------------------------------
// This function initializes the eQEP(s) to a known state.
void InitEQep(void)
{
    // Initialize eQEP1

    //tbd...

}
//---------------------------------------------------------------------------
// Example: InitEQepGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as eQEP pins
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
// Caution:
// For each eQEP peripheral
// Only one GPIO pin should be enabled for EQEPxA operation.
// Only one GPIO pin should be enabled for EQEPxB operation.
// Only one GPIO pin should be enabled for EQEPxS operation.
// Only one GPIO pin should be enabled for EQEPxI operation.
// Comment out other unwanted lines.

void InitEQepGpio()
{
    InitEQep1Gpio();
    InitEQep2Gpio();
    InitEQep3Gpio();
}
// Caution:
// For each eQEP peripheral
// Only one GPIO pin should be enabled for EQEPxA operation.
// Only one GPIO pin should be enabled for EQEPxB operation.
// Only one GPIO pin should be enabled for EQEPxS operation.
// Only one GPIO pin should be enabled for EQEPxI operation.
// Comment out other unwanted lines.

void InitEQep1Gpio(void)
{
	EALLOW;

	/* Disable internal pull-up for the selected output pins
	   for reduced power consumption */
	// Pull-ups can be enabled or disabled by the user.
	// Comment out other unwanted lines.

//	GpioCtrlRegs.GPAPUD.bit.GPIO10 = 1;    // Disable pull-up on GPIO10 (EQEP1A)
//	GpioCtrlRegs.GPAPUD.bit.GPIO11 = 1;    // Disable pull-up on GPIO11 (EQEP1B)
//	GpioCtrlRegs.GPAPUD.bit.GPIO12 = 1;    // Disable pull-up on GPIO12 (EQEP1S)
//	GpioCtrlRegs.GPAPUD.bit.GPIO13 = 1;    // Disable pull-up on GPIO13 (EQEP1I)

	GpioCtrlRegs.GPAPUD.bit.GPIO20 = 1;    // Disable pull-up on GPIO20 (EQEP1A)
	GpioCtrlRegs.GPAPUD.bit.GPIO21 = 1;    // Disable pull-up on GPIO21 (EQEP1B)
	GpioCtrlRegs.GPAPUD.bit.GPIO22 = 1;    // Disable pull-up on GPIO22 (EQEP1S)
	GpioCtrlRegs.GPAPUD.bit.GPIO23 = 1;    // Disable pull-up on GPIO23 (EQEP1I)

//	GpioCtrlRegs.GPBPUD.bit.GPIO50 = 1;    // Disable pull-up on GPIO50 (EQEP1A)
//	GpioCtrlRegs.GPBPUD.bit.GPIO51 = 1;    // Disable pull-up on GPIO51 (EQEP1B)
//	GpioCtrlRegs.GPBPUD.bit.GPIO52 = 1;    // Disable pull-up on GPIO52 (EQEP1S)
//	GpioCtrlRegs.GPBPUD.bit.GPIO53 = 1;    // Disable pull-up on GPIO53 (EQEP1I)

//	GpioCtrlRegs.GPDPUD.bit.GPIO96 = 1;    // Disable pull-up on GPIO96 (EQEP1A)
//	GpioCtrlRegs.GPDPUD.bit.GPIO97 = 1;    // Disable pull-up on GPIO97 (EQEP1B)
//	GpioCtrlRegs.GPDPUD.bit.GPIO98 = 1;    // Disable pull-up on GPIO98 (EQEP1S)
//	GpioCtrlRegs.GPDPUD.bit.GPIO99 = 1;    // Disable pull-up on GPIO99 (EQEP1I)

	/* Synchronize inputs to SYSCLK */
	// Synchronization can be enabled or disabled by the user.
	// Comment out other unwanted lines.

//	GpioCtrlRegs.GPAQSEL1.bit.GPIO10 = 0;   // Sync GPIO10 to SYSCLK  (EQEP1A)
//	GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 0;   // Sync GPIO11 to SYSCLK  (EQEP1B)
//	GpioCtrlRegs.GPAQSEL1.bit.GPIO12 = 0;   // Sync GPIO12 to SYSCLK  (EQEP1S)
//	GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 0;   // Sync GPIO13 to SYSCLK  (EQEP1I)

	GpioCtrlRegs.GPAQSEL2.bit.GPIO20 = 0;   // Sync GPIO20 to SYSCLK  (EQEP1A)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO21 = 0;   // Sync GPIO21 to SYSCLK  (EQEP1B)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO22 = 0;   // Sync GPIO22 to SYSCLK  (EQEP1S)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO23 = 0;   // Sync GPIO23 to SYSCLK  (EQEP1I)

//	GpioCtrlRegs.GPBQSEL2.bit.GPIO50 = 0;   // Sync GPIO50 to SYSCLK  (EQEP1A)
//	GpioCtrlRegs.GPBQSEL2.bit.GPIO51 = 0;   // Sync GPIO51 to SYSCLK  (EQEP1B)
//	GpioCtrlRegs.GPBQSEL2.bit.GPIO52 = 0;   // Sync GPIO52 to SYSCLK  (EQEP1S)
//	GpioCtrlRegs.GPBQSEL2.bit.GPIO53 = 0;   // Sync GPIO53 to SYSCLK  (EQEP1I)

//	GpioCtrlRegs.GPDQSEL1.bit.GPIO96 = 0;   // Sync GPIO96 to SYSCLK  (EQEP1A)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO97 = 0;   // Sync GPIO97 to SYSCLK  (EQEP1B)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO98 = 0;   // Sync GPIO98 to SYSCLK  (EQEP1S)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO99 = 0;   // Sync GPIO99 to SYSCLK  (EQEP1I)

	/* Configure EQEP-1 pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be EQEP1 functional pins.
	// Comment out other unwanted lines.

//	GpioCtrlRegs.GPAGMUX1.bit.GPIO10 = 1;	// Configure GPIO10 as EQEP1A
//	GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;    // Configure GPIO10 as EQEP1A
//	GpioCtrlRegs.GPAGMUX1.bit.GPIO11 = 1;   // Configure GPIO11 as EQEP1B
//	GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;    // Configure GPIO11 as EQEP1B
//	GpioCtrlRegs.GPAGMUX1.bit.GPIO12 = 1;   // Configure GPIO12 as EQEP1S
//	GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;    // Configure GPIO12 as EQEP1S
//	GpioCtrlRegs.GPAGMUX1.bit.GPIO13 = 1;   // Configure GPIO13 as EQEP1I
//	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;    // Configure GPIO13 as EQEP1I

	GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;    // Configure GPIO20 as EQEP1A
	GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;    // Configure GPIO21 as EQEP1B
	GpioCtrlRegs.GPAMUX2.bit.GPIO22 = 1;    // Configure GPIO22 as EQEP1S
	GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 1;    // Configure GPIO23 as EQEP1I

//	GpioCtrlRegs.GPBMUX2.bit.GPIO50 = 1;    // Configure GPIO50 as EQEP1A
//	GpioCtrlRegs.GPBMUX2.bit.GPIO51 = 1;    // Configure GPIO51 as EQEP1B
//	GpioCtrlRegs.GPBMUX2.bit.GPIO52 = 1;    // Configure GPIO52 as EQEP1S
//	GpioCtrlRegs.GPBMUX2.bit.GPIO53 = 1;    // Configure GPIO53 as EQEP1I

//	GpioCtrlRegs.GPDGMUX1.bit.GPIO96 = 1;   // Configure GPIO96 as EQEP1A
//	GpioCtrlRegs.GPDMUX1.bit.GPIO96 = 1;    // Configure GPIO96 as EQEP1A
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO97 = 1;   // Configure GPIO97 as EQEP1B
//	GpioCtrlRegs.GPDMUX1.bit.GPIO97 = 1;    // Configure GPIO97 as EQEP1B
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO98 = 1;   // Configure GPIO98 as EQEP1S
//	GpioCtrlRegs.GPDMUX1.bit.GPIO98 = 1;    // Configure GPIO98 as EQEP1S
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO99 = 1;   // Configure GPIO99 as EQEP1I
//	GpioCtrlRegs.GPDMUX1.bit.GPIO99 = 1;    // Configure GPIO99 as EQEP1I

	EDIS;
}

void InitEQep2Gpio(void)
{
	EALLOW;

	/* Disable internal pull-up for the selected output pins
	   for reduced power consumption */
	// Pull-ups can be enabled or disabled by the user.
	// Comment out other unwanted lines.

	GpioCtrlRegs.GPAPUD.bit.GPIO24 = 1;    // Disable pull-up on GPIO24 (EQEP2A)
	GpioCtrlRegs.GPAPUD.bit.GPIO25 = 1;    // Disable pull-up on GPIO25 (EQEP2B)
	GpioCtrlRegs.GPAPUD.bit.GPIO26 = 1;    // Disable pull-up on GPIO26 (EQEP2S)
	GpioCtrlRegs.GPAPUD.bit.GPIO27 = 1;    // Disable pull-up on GPIO27 (EQEP2I)

//	GpioCtrlRegs.GPBPUD.bit.GPIO54 = 1;    // Disable pull-up on GPIO54 (EQEP2A)
//	GpioCtrlRegs.GPBPUD.bit.GPIO55 = 1;    // Disable pull-up on GPIO55 (EQEP2B)
//	GpioCtrlRegs.GPBPUD.bit.GPIO56 = 1;    // Disable pull-up on GPIO56 (EQEP2S)
//	GpioCtrlRegs.GPBPUD.bit.GPIO57 = 1;    // Disable pull-up on GPIO57 (EQEP2I)

//	GpioCtrlRegs.GPCPUD.bit.GPIO78 = 1;    // Disable pull-up on GPIO78 (EQEP2A)
//	GpioCtrlRegs.GPCPUD.bit.GPIO79 = 1;    // Disable pull-up on GPIO79 (EQEP2B)
//	GpioCtrlRegs.GPCPUD.bit.GPIO80 = 1;    // Disable pull-up on GPIO80 (EQEP2S)
//	GpioCtrlRegs.GPCPUD.bit.GPIO81 = 1;    // Disable pull-up on GPIO81 (EQEP2I)

//	GpioCtrlRegs.GPDPUD.bit.GPIO100 = 1;   // Disable pull-up on GPIO100 (EQEP2A)
//	GpioCtrlRegs.GPDPUD.bit.GPIO101 = 1;   // Disable pull-up on GPIO101 (EQEP2B)
//	GpioCtrlRegs.GPDPUD.bit.GPIO102 = 1;   // Disable pull-up on GPIO102 (EQEP2S)
//	GpioCtrlRegs.GPDPUD.bit.GPIO103 = 1;   // Disable pull-up on GPIO103 (EQEP2I)

	/* Synchronize inputs to SYSCLK */
	// Synchronization can be enabled or disabled by the user.
	// Comment out other unwanted lines.

	GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0;   // Sync GPIO24 to SYSCLK  (EQEP2A)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0;   // Sync GPIO25 to SYSCLK  (EQEP2B)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;   // Sync GPIO26 to SYSCLK  (EQEP2S)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 0;   // Sync GPIO27 to SYSCLK  (EQEP2I)

//	GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 0;   // Sync GPIO54 to SYSCLK  (EQEP2A)
//	GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 0;   // Sync GPIO55 to SYSCLK  (EQEP2B)
//	GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 0;   // Sync GPIO56 to SYSCLK  (EQEP2S)
//	GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 0;   // Sync GPIO57 to SYSCLK  (EQEP2I)

//	GpioCtrlRegs.GPCQSEL1.bit.GPIO78 = 0;   // Sync GPIO78 to SYSCLK  (EQEP2A)
//	GpioCtrlRegs.GPCQSEL1.bit.GPIO79 = 0;   // Sync GPIO79 to SYSCLK  (EQEP2B)
//	GpioCtrlRegs.GPCQSEL2.bit.GPIO80 = 0;   // Sync GPIO80 to SYSCLK  (EQEP2S)
//	GpioCtrlRegs.GPCQSEL2.bit.GPIO81 = 0;   // Sync GPIO81 to SYSCLK  (EQEP2I)

//	GpioCtrlRegs.GPDQSEL1.bit.GPIO100 = 0;  // Sync GPIO100 to SYSCLK  (EQEP2A)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO101 = 0;  // Sync GPIO101 to SYSCLK  (EQEP2B)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO102 = 0;  // Sync GPIO102 to SYSCLK  (EQEP2S)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO103 = 0;  // Sync GPIO103 to SYSCLK  (EQEP2I)

	/* Configure EQEP-1 pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be EQEP2 functional pins.
	// Comment out other unwanted lines.

	GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 2;    // Configure GPIO24 as EQEP2A
	GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 2;    // Configure GPIO25 as EQEP2B
	GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 2;    // Configure GPIO26 as EQEP2S
	GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 2;    // Configure GPIO27 as EQEP2I

//	GpioCtrlRegs.GPBGMUX2.bit.GPIO54 = 1;   // Configure GPIO54 as EQEP2A
//	GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 1;    // Configure GPIO54 as EQEP2A
//	GpioCtrlRegs.GPBGMUX2.bit.GPIO55 = 1;   // Configure GPIO55 as EQEP2B
//	GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 1;    // Configure GPIO55 as EQEP2B
//	GpioCtrlRegs.GPBGMUX2.bit.GPIO56 = 1;   // Configure GPIO56 as EQEP2S
//	GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 1;    // Configure GPIO56 as EQEP2S
//	GpioCtrlRegs.GPBGMUX2.bit.GPIO57 = 1;   // Configure GPIO57 as EQEP2I
//	GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 1;    // Configure GPIO57 as EQEP2I

//	GpioCtrlRegs.GPCGMUX1.bit.GPIO78 = 1;   // Configure GPIO78 as EQEP2A
//	GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 2;    // Configure GPIO78 as EQEP2A
//	GpioCtrlRegs.GPCGMUX1.bit.GPIO79 = 1;   // Configure GPIO79 as EQEP2B
//	GpioCtrlRegs.GPCMUX1.bit.GPIO79 = 2;    // Configure GPIO79 as EQEP2B
//	GpioCtrlRegs.GPCGMUX2.bit.GPIO80 = 1;   // Configure GPIO80 as EQEP2S
//	GpioCtrlRegs.GPCMUX2.bit.GPIO80 = 2;    // Configure GPIO80 as EQEP2S
//	GpioCtrlRegs.GPCGMUX2.bit.GPIO81 = 1;   // Configure GPIO81 as EQEP2I
//	GpioCtrlRegs.GPCMUX2.bit.GPIO81 = 2;    // Configure GPIO81 as EQEP2I

//	GpioCtrlRegs.GPDGMUX1.bit.GPIO100 = 1;  // Configure GPIO100 as EQEP2A
//	GpioCtrlRegs.GPDMUX1.bit.GPIO100 = 1;   // Configure GPIO100 as EQEP2A
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO101 = 1;  // Configure GPIO101 as EQEP2B
//	GpioCtrlRegs.GPDMUX1.bit.GPIO101 = 1;   // Configure GPIO101 as EQEP2B
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO102 = 1;  // Configure GPIO102 as EQEP2S
//	GpioCtrlRegs.GPDMUX1.bit.GPIO102 = 1;   // Configure GPIO102 as EQEP2S
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO103 = 1;  // Configure GPIO103 as EQEP2I
//	GpioCtrlRegs.GPDMUX1.bit.GPIO103 = 1;   // Configure GPIO103 as EQEP2I

	EDIS;
}

void InitEQep3Gpio(void)
{
	EALLOW;

	/* Disable internal pull-up for the selected output pins
	   for reduced power consumption */
	// Pull-ups can be enabled or disabled by the user.
	// Comment out other unwanted lines.

//	GpioCtrlRegs.GPAPUD.bit.GPIO6 = 1;     // Disable pull-up on GPIO6 (EQEP3A)
//	GpioCtrlRegs.GPAPUD.bit.GPIO7 = 1;     // Disable pull-up on GPIO7 (EQEP3B)
//	GpioCtrlRegs.GPAPUD.bit.GPIO8 = 1;     // Disable pull-up on GPIO8 (EQEP3S)
//	GpioCtrlRegs.GPAPUD.bit.GPIO9 = 1;     // Disable pull-up on GPIO9 (EQEP3I)

	GpioCtrlRegs.GPAPUD.bit.GPIO28 = 1;    // Disable pull-up on GPIO28 (EQEP3A)
	GpioCtrlRegs.GPAPUD.bit.GPIO29 = 1;    // Disable pull-up on GPIO29 (EQEP3B)
	GpioCtrlRegs.GPAPUD.bit.GPIO30 = 1;    // Disable pull-up on GPIO30 (EQEP3S)
	GpioCtrlRegs.GPAPUD.bit.GPIO31 = 1;    // Disable pull-up on GPIO31 (EQEP3I)

//	GpioCtrlRegs.GPBPUD.bit.GPIO62 = 1;    // Disable pull-up on GPIO62 (EQEP3A)
//	GpioCtrlRegs.GPBPUD.bit.GPIO63 = 1;    // Disable pull-up on GPIO63 (EQEP3B)
//	GpioCtrlRegs.GPCPUD.bit.GPIO64 = 1;    // Disable pull-up on GPIO64 (EQEP3S)
//	GpioCtrlRegs.GPCPUD.bit.GPIO65 = 1;    // Disable pull-up on GPIO65 (EQEP3I)

//	GpioCtrlRegs.GPDPUD.bit.GPIO104 = 1;   // Disable pull-up on GPIO104 (EQEP3A)
//	GpioCtrlRegs.GPDPUD.bit.GPIO105 = 1;   // Disable pull-up on GPIO105 (EQEP3B)
//	GpioCtrlRegs.GPDPUD.bit.GPIO106 = 1;   // Disable pull-up on GPIO106 (EQEP3S)
//	GpioCtrlRegs.GPDPUD.bit.GPIO107 = 1;   // Disable pull-up on GPIO107 (EQEP3I)

	/* Synchronize inputs to SYSCLK */
	// Synchronization can be enabled or disabled by the user.
	// Comment out other unwanted lines.

//	GpioCtrlRegs.GPAQSEL1.bit.GPIO6 = 0;    // Sync GPIO6 to SYSCLK  (EQEP3A)
//	GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 0;    // Sync GPIO7 to SYSCLK  (EQEP3B)
//	GpioCtrlRegs.GPAQSEL1.bit.GPIO8 = 0;    // Sync GPIO8 to SYSCLK  (EQEP3S)
//	GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0;    // Sync GPIO9 to SYSCLK  (EQEP3I)

	GpioCtrlRegs.GPAQSEL2.bit.GPIO28 = 0;   // Sync GPIO28 to SYSCLK  (EQEP3A)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO29 = 0;   // Sync GPIO29 to SYSCLK  (EQEP3B)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO30 = 0;   // Sync GPIO30 to SYSCLK  (EQEP3S)
	GpioCtrlRegs.GPAQSEL2.bit.GPIO31 = 0;   // Sync GPIO31 to SYSCLK  (EQEP3I)

//	GpioCtrlRegs.GPBQSEL2.bit.GPIO62 = 0;   // Sync GPIO62 to SYSCLK  (EQEP3A)
//	GpioCtrlRegs.GPBQSEL2.bit.GPIO63 = 0;   // Sync GPIO63 to SYSCLK  (EQEP3B)
//	GpioCtrlRegs.GPCQSEL1.bit.GPIO64 = 0;   // Sync GPIO64 to SYSCLK  (EQEP3S)
//	GpioCtrlRegs.GPCQSEL1.bit.GPIO65 = 0;   // Sync GPIO65 to SYSCLK  (EQEP3I)

//	GpioCtrlRegs.GPDQSEL1.bit.GPIO104 = 0;  // Sync GPIO104 to SYSCLK  (EQEP3A)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO105 = 0;  // Sync GPIO105 to SYSCLK  (EQEP3B)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO106 = 0;  // Sync GPIO106 to SYSCLK  (EQEP3S)
//	GpioCtrlRegs.GPDQSEL1.bit.GPIO107 = 0;  // Sync GPIO107 to SYSCLK  (EQEP3I)

	/* Configure EQEP-1 pins using GPIO regs*/
	// This specifies which of the possible GPIO pins will be EQEP3 functional pins.
	// Comment out other unwanted lines.

//	GpioCtrlRegs.GPAGMUX1.bit.GPIO6 = 1;    // Configure GPIO6 as EQEP3A
//	GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;     // Configure GPIO6 as EQEP3A
//	GpioCtrlRegs.GPAGMUX1.bit.GPIO7 = 1;    // Configure GPIO7 as EQEP3B
//	GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;     // Configure GPIO7 as EQEP3B
//	GpioCtrlRegs.GPAGMUX1.bit.GPIO8 = 1;    // Configure GPIO8 as EQEP3S
//	GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;     // Configure GPIO8 as EQEP3S
//	GpioCtrlRegs.GPAGMUX1.bit.GPIO9 = 1;    // Configure GPIO9 as EQEP3I
//	GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;     // Configure GPIO9 as EQEP3I

	GpioCtrlRegs.GPAGMUX2.bit.GPIO28 = 1;   // Configure GPIO28 as EQEP3A
	GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 2;    // Configure GPIO28 as EQEP3A
	GpioCtrlRegs.GPAGMUX2.bit.GPIO29 = 1;   // Configure GPIO29 as EQEP3B
	GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 2;    // Configure GPIO29 as EQEP3B
	GpioCtrlRegs.GPAGMUX2.bit.GPIO30 = 1;   // Configure GPIO30 as EQEP3S
	GpioCtrlRegs.GPAMUX2.bit.GPIO30 = 2;    // Configure GPIO30 as EQEP3S
	GpioCtrlRegs.GPAGMUX2.bit.GPIO31 = 1;   // Configure GPIO31 as EQEP3I
	GpioCtrlRegs.GPAMUX2.bit.GPIO31 = 2;    // Configure GPIO31 as EQEP3I

//	GpioCtrlRegs.GPBGMUX2.bit.GPIO62 = 1;   // Configure GPIO62 as EQEP3A
//	GpioCtrlRegs.GPBMUX2.bit.GPIO62 = 1;    // Configure GPIO62 as EQEP3A
//	GpioCtrlRegs.GPBGMUX2.bit.GPIO63 = 1;   // Configure GPIO63 as EQEP3B
//	GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 1;    // Configure GPIO63 as EQEP3B
//	GpioCtrlRegs.GPCGMUX1.bit.GPIO64 = 1;   // Configure GPIO64 as EQEP3S
//	GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 1;    // Configure GPIO64 as EQEP3S
//	GpioCtrlRegs.GPCGMUX1.bit.GPIO65 = 1;   // Configure GPIO65 as EQEP3I
//	GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 1;    // Configure GPIO65 as EQEP3I

//	GpioCtrlRegs.GPDGMUX1.bit.GPIO104 = 1;  // Configure GPIO104 as EQEP3A
//	GpioCtrlRegs.GPDMUX1.bit.GPIO104 = 1;   // Configure GPIO104 as EQEP3A
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO105 = 1;  // Configure GPIO105 as EQEP3B
//	GpioCtrlRegs.GPDMUX1.bit.GPIO105 = 1;   // Configure GPIO105 as EQEP3B
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO106 = 1;  // Configure GPIO106 as EQEP3S
//	GpioCtrlRegs.GPDMUX1.bit.GPIO106 = 1;   // Configure GPIO106 as EQEP3S
//	GpioCtrlRegs.GPDGMUX1.bit.GPIO107 = 1;  // Configure GPIO107 as EQEP3I
//	GpioCtrlRegs.GPDMUX1.bit.GPIO107 = 1;   // Configure GPIO107 as EQEP3I

	EDIS;
}
//===========================================================================
// End of file.
//===========================================================================
