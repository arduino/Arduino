//###########################################################################
//
// FILE:    F2806x_Comp.c
//
// TITLE:   F2806x Comparator Initialization & Support Functions.
//
//###########################################################################
// $TI Release: 2806x C/C++ Header Files V1.10 $
// $Release Date: April 7, 2011 $
//###########################################################################

#include "F2806x_Device.h"     // F2806x Headerfile Include File
#include "F2806x_Examples.h"   // F2806x Examples Include File

//---------------------------------------------------------------------------
// InitComp:
//---------------------------------------------------------------------------
// This function initializes the Comp to a known state.
//
void InitComp(void)
{
    // Initialize Comp1/2/3:

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
// Only one GPIO pin should be enabled for each operation.
// Comment out other unwanted lines.

void InitCompGpio()
{
    #if DSP28_COMP1
        InitComp1Gpio();
    #endif // endif DSP28_COMP1
    #if DSP28_COMP2
        InitComp2Gpio();
    #endif // endif DSP28_COMP2
    #if DSP28_COMP3
        InitComp3Gpio();
    #endif // endif DSP28_COMP3


}

#if DSP28_COMP1
void InitComp1Gpio()
{

   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO1 = 1;    // Disable pull-up for GPIO1 (CMP1OUT)
//  GpioCtrlRegs.GPAPUD.bit.GPIO20 = 1;   // Disable pull-up for GPIO20 (CMP1OUT)
//  GpioCtrlRegs.GPBPUD.bit.GPIO42 = 1;   // Disable pull-up for GPIO42 (CMP1OUT)

/* Configure Comp pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be Comp functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 3;   // Configure GPIO1 for CMP1OUT operation
// GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 3;  // Configure GPIO20 for CMP1OUT operation
// GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 3;  // Configure GPIO42 for CMP1OUT operation

   GpioCtrlRegs.AIOMUX1.bit.AIO2 = 2;    // Configure AIO2 for CMP1A (analog input) operation
   GpioCtrlRegs.AIOMUX1.bit.AIO10 = 2;   // Configure AIO10 for CMP1B (analog input) operation

    EDIS;
}
#endif // endif DSP28_COMP1

#if DSP28_COMP2
void InitComp2Gpio()
{

   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled disabled by the user.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAPUD.bit.GPIO3 = 1;    // Disable pull-up for GPIO3 (CMP2OUT)
//  GpioCtrlRegs.GPAPUD.bit.GPIO21 = 1;   // Disable pull-up for GPIO21 (CMP2OUT)
//  GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;   // Disable pull-up for GPIO34 (CMP2OUT)
//  GpioCtrlRegs.GPBPUD.bit.GPIO43 = 1;   // Disable pull-up for GPIO43 (CMP2OUT)

/* Configure Comp pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be Comp functional pins.
// Comment out other unwanted lines.

    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 3;   // Configure GPIO3 for CMP2OUT operation
//  GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 3;  // Configure GPIO21 for CMP2OUT operation
//  GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 1;  // Configure GPIO34 for CMP2OUT operation
//  GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 3;  // Configure GPIO43 for CMP2OUT operation


    GpioCtrlRegs.AIOMUX1.bit.AIO4 = 2;    // Configure AIO4 for CMP2A (analog input) operation
    GpioCtrlRegs.AIOMUX1.bit.AIO12 = 2;   // Configure AIO12 for CMP2B (analog input) operation

    EDIS;
}
#endif //endif DSP28_COMP2

#if DSP28_COMP3
void InitComp3Gpio()
{

   EALLOW;

/* Disable internal pull-up for the selected output pins
   to reduce power consumption */
// Pull-ups can be enabled or disabled disabled by the user.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBPUD.bit.GPIO34 = 1;    // Disable pull-up for GPIO34 (CMP3OUT)

/* Configure Comp pins using GPIO regs*/
// This specifies which of the possible GPIO pins will be Comp functional pins.
// Comment out other unwanted lines.

   GpioCtrlRegs.GPBMUX1.bit.GPIO34 = 3;  // Configure GPIO34 for CMP3OUT operation

   GpioCtrlRegs.AIOMUX1.bit.AIO6 = 2;    // Configure AIO6 for CMP3A (analog input) operation
   GpioCtrlRegs.AIOMUX1.bit.AIO14 = 2;   // Configure AIO14 for CMP3B (analog input) operation

    EDIS;
}
#endif //endif DSP28_COMP3

//===========================================================================
// End of file.
//===========================================================================
