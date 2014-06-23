// TI File $Revision: /main/3 $
// Checkin $Date: September 22, 2009   10:53:23 $
//###########################################################################
//
// FILE:    DSP2802x_Comp.c
//
// TITLE:   DSP2802x Comparator Initialization & Support Functions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#include "F2802x_Device.h"     // Headerfile Include File
#include "f2802x_common/include/f2802x_examples.h"   // Examples Include File

//---------------------------------------------------------------------------
// InitComp:
//---------------------------------------------------------------------------
// This function initializes the Comp to a known state.
//
void InitComp(void)
{
    // Initialize Comp:

    //tbd...
}

//---------------------------------------------------------------------------
// Example: InitCompGpio:
//---------------------------------------------------------------------------
// This function initializes GPIO pins to function as Comp pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
//
// Caution:
// Only one GPIO pin should be enabled for CMP1OUT operation.
// Only one GPIO pin shoudl be enabled for CMP2OUT operation.
// Comment out other unwanted lines.

void InitCompGpio()
{
    InitComp1Gpio();
    #if DSP28_COMP2
        InitComp2Gpio();
    #endif

}

void InitComp1Gpio()
{

   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up for GPIO1 (CMP1OUT)

/* Configure Comp pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be Comp functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 3;   // Configure GPIO1 for CMP1OUT operation

    GpioCtrlRegs.AIOMUX1.bit.AIO2 = 2;    // Configure AIO2 for CMP1A (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO10 = 2;   // Configure AIO10 for CMP1B (analog input) operation

    EDIS;
}

#if DSP28_COMP2
void InitComp2Gpio()
{

   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up for GPIO3 (CMP2OUT)
//  GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;   // Disable pull-up for GPIO34 (CMP2OUT)

/* Configure Comp pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be Comp functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 3;   // Configure GPIO3 for CMP2OUT operation
//  GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 1;  // Configure GPIO34 for CMP2OUT operation

    GpioCtrlRegs.AIOMUX1.bit.AIO4 = 2;    // Configure AIO4 for CMP2A (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO12 = 2;   // Configure AIO12 for CMP2B (analog input) operation

    EDIS;
}

#endif //end DSP28_COMP2

//===========================================================================
// End of file.
//===========================================================================
