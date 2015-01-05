//###########################################################################
//
// FILE:   F2806x_ECap.c
//
// TITLE:  F2806x eCAP Initialization & Support Functions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File

//---------------------------------------------------------------------------
// InitECap:
//---------------------------------------------------------------------------
// This function initializes the eCAP(s) to a known state.
//
void InitECap(void)
{
   // Initialize eCAP1/2/3

   //tbd...

}

//---------------------------------------------------------------------------
// Example: InitECapGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as ECAP pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
//
// Caution:
// For each eCAP peripheral
// Only one GPIO pin should be enabled for ECAP operation.
// Comment out other unwanted lines.

void InitECapGpio()
{
   #if DSP28_ECAP1
       InitECap1Gpio();
   #endif // endif DSP28_ECAP1
   #if DSP28_ECAP2
       InitECap2Gpio();
   #endif // endif DSP28_ECAP2
   #if DSP28_ECAP3
       InitECap3Gpio();
   #endif // endif DSP28_ECAP3
}

#if DSP28_ECAP1
void InitECap1Gpio(void)
{
   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAPUD.bit.GPIO5 = 0;		// Enable pull-up on GPIO5 (CAP1)
// GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;      // Enable pull-up on GPIO11 (CAP1)
// GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;		// Enable pull-up on GPIO19 (CAP1)
// GpioCtrlRegs.GPAPUD.bit.GPIO24 = 0;      // Enable pull-up on GPIO24 (CAP1)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO5 = 0;		// Synch to SYSCLKOUT GPIO5 (CAP1)
// GpioCtrlRegs.GPAQSEL1.bit.GPIO11 = 0;    // Synch to SYSCLKOUT GPIO11 (CAP1)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 0;	// Synch to SYSCLKOUT GPIO19 (CAP1)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO24 = 0;    // Synch to SYSCLKOUT GPIO24 (CAP1)

/* Configure eCAP-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be eCAP1 functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 3;		// Configure GPIO5 as CAP1
// GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 3;     // Configure GPIO11 as CAP1
// GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 3;		// Configure GPIO19 as CAP1
// GpioCtrlRegs.GPAMUX2.bit.GPIO24 = 1;     // Configure GPIO24 as CAP1

    EDIS;
}
#endif // endif DSP28_ECAP1

#if DSP28_ECAP2
void InitECap2Gpio(void)
{
   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAPUD.bit.GPIO7 = 0;      // Enable pull-up on GPIO7 (CAP2)
// GpioCtrlRegs.GPAPUD.bit.GPIO15 = 0;     // Enable pull-up on GPIO15 (CAP2)
// GpioCtrlRegs.GPAPUD.bit.GPIO25 = 0;	   // Enable pull-up on GPIO25 (CAP2)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO7 = 0;    // Synch to SYSCLKOUT GPIO7 (CAP2)
// GpioCtrlRegs.GPAQSEL1.bit.GPIO15 = 0;   // Synch to SYSCLKOUT GPIO15 (CAP2)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO25 = 0;   // Synch to SYSCLKOUT GPIO25 (CAP2)

/* Configure eCAP-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be eCAP2 functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 3;     // Configure GPIO7 as CAP2
// GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;    // Configure GPIO15 as CAP2
// GpioCtrlRegs.GPAMUX2.bit.GPIO25 = 1;	   // Configure GPIO25 as CAP2

    EDIS;
}
#endif // endif DSP28_ECAP2

#if DSP28_ECAP3
void InitECap3Gpio(void)
{
   EALLOW;
/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAPUD.bit.GPIO9 = 0;      // Enable pull-up on GPIO9 (CAP3)
// GpioCtrlRegs.GPAPUD.bit.GPIO26 = 0;     // Enable pull-up on GPIO26 (CAP3)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 0;    // Synch to SYSCLKOUT GPIO9 (CAP3)
// GpioCtrlRegs.GPAQSEL2.bit.GPIO26 = 0;   // Synch to SYSCLKOUT GPIO26 (CAP3)

/* Configure eCAP-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be eCAP3 functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 3;     // Configure GPIO9 as CAP3
// GpioCtrlRegs.GPAMUX2.bit.GPIO26 = 1;    // Configure GPIO26 as CAP3

    EDIS;
}
#endif // endif DSP28_ECAP3

//===========================================================================
// End of file.
//===========================================================================
