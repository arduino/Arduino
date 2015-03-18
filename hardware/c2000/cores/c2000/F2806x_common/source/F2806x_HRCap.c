//###########################################################################
//
// FILE:   F2806x_HRCap.c
//
// TITLE:  F2806x HRCap Initialization & Support Functions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File

//---------------------------------------------------------------------------
// InitEPwm:
//---------------------------------------------------------------------------
// This function initializes the HRCap(s) to a known state.
//
void InitHRCap(void)
{
   // Initialize HRCap1/2/3/4

   //tbd...

}

//---------------------------------------------------------------------------
// Example: InitHRCapGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as EPwm pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
//

void InitHRCapGpio(void)
{
   #if DSP28_HRCAP1
   	   InitHRCap1Gpio();
   #endif // endif DSP28_HRCAP1
   #if DSP28_HRCAP2
       InitHRCap2Gpio();
   #endif // endif DSP28_HRCAP2
   #if DSP28_HRCAP3
       InitHRCap3Gpio();
   #endif // endif DSP28_HRCAP3
   #if DSP28_HRCAP4
       InitHRCap4Gpio();
   #endif // endif DSP28_HRCAP4
}

#if DSP28_HRCAP1
void InitHRCap1Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBPUD.bit.GPIO54 = 0;		// Enable pull-up on GPIO54 (HRCAP1)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBQSEL2.bit.GPIO54 = 3;		// Asynch to SYSCLKOUT GPIO54 (HRCAP1)

/* Configure HRCAP-1 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be HRCAP1 functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBMUX2.bit.GPIO54 = 3;		// Configure GPIO54 as HRCAP1

   EDIS;
}
#endif // endif DSP28_HRCAP1

#if DSP28_HRCAP2
void InitHRCap2Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAPUD.bit.GPIO27 = 0;		// Enable pull-up on GPIO27 (HRCAP2)
// GpioCtrlRegs.GPBPUD.bit.GPIO55 = 0;		// Enable pull-up on GPIO55 (HRCAP2)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAQSEL2.bit.GPIO27 = 3;		// Asynch to SYSCLKOUT GPIO27 (HRCAP2)
// GpioCtrlRegs.GPBQSEL2.bit.GPIO55 = 3;		// Asynch to SYSCLKOUT GPIO55 (HRCAP2)

/* Configure HRCAP-2 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be HRCAP2 functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAMUX2.bit.GPIO27 = 1;		// Configure GPIO27 as HRCAP2
// GpioCtrlRegs.GPBMUX2.bit.GPIO55 = 3;		// Configure GPIO55 as HRCAP2

   EDIS;
}
#endif // endif DSP28_HRCAP2

#if DSP28_HRCAP3
void InitHRCap3Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBPUD.bit.GPIO56 = 0;		// Enable pull-up on GPIO56 (HRCAP3)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBQSEL2.bit.GPIO56 = 3;		// Asynch to SYSCLKOUT GPIO56 (HRCAP3)

/* Configure HRCAP-3 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be HRCAP3 functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBMUX2.bit.GPIO56 = 3;		// Configure GPIO56 as HRCAP3

   EDIS;
}
#endif // endif DSP28_HRCAP3

#if DSP28_HRCAP4
void InitHRCap4Gpio(void)
{
   EALLOW;

/* Enable internal pull-up for the selected pins */
// Pull-ups can be enabled or disabled by the user.
// This will enable the pullups for the specified pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBPUD.bit.GPIO57 = 0;		// Enable pull-up on GPIO57 (HRCAP4)

// Inputs are synchronized to SYSCLKOUT by default.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBQSEL2.bit.GPIO57 = 3;		// Asynch to SYSCLKOUT GPIO57 (HRCAP4)

/* Configure HRCAP-4 pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be HRCAP4 functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBMUX2.bit.GPIO57 = 3;		// Configure GPIO57 as HRCAP4

   EDIS;
}
#endif // endif DSP28_HRCAP4

//===========================================================================
// End of file.
//===========================================================================
