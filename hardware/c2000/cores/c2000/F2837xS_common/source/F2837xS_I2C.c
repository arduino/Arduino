//###########################################################################
//
// FILE:   F2837xS_I2C.c
//
// TITLE:  F2837xS I2C Initialization & Support Functions.
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
// Example: I2cAGpioConfig(), I2cBGpioConfig()
//---------------------------------------------------------------------------
// These functions configures GPIO pins to function as I2C pins
//
// Each GPIO pin can be configured as a GPIO pin or up to 3 different
// peripheral functional pins. By default all pins come up as GPIO
// inputs after reset.
//

#ifdef CPU1
//************************************************************************************
// 'I2caDataClkPin' should be assign with one of the possible I2C_A SDA - SDL GPIO pin
// Use defined Macros from "F2837xS_I2c_defines.h" for  assignment
//************************************************************************************
void I2cAGpioConfig(Uint16 I2caDataClkPin)
{
	EALLOW;

	switch(I2caDataClkPin)
	{
		case I2C_A_GPIO0_GPIO1:
			/* Enable internal pull-up for the selected I2C pins */
			GpioCtrlRegs.GPAPUD.bit.GPIO0 = 0;     // Enable pull-up for GPIO0 (SDAA)
			GpioCtrlRegs.GPAPUD.bit.GPIO1 = 0;     // Enable pull-up for GPIO1 (SDLA)
		
			/* Set qualification for the selected I2C pins */
			GpioCtrlRegs.GPAQSEL1.bit.GPIO0 = 3;   // Async/no qualification (I/ps sync
			GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 3;   // to SYSCLKOUT by default)

			/* Configure which of the possible GPIO pins will be I2C_A pins using GPIO regs*/
			GpioCtrlRegs.GPAGMUX1.bit.GPIO0 = 1;    // Configure GPIO0 for SDAA operation
			GpioCtrlRegs.GPAMUX1.bit.GPIO0  = 2;    // Configure GPIO0 for SDAA operation
		
			GpioCtrlRegs.GPAGMUX1.bit.GPIO1 = 1;    // Configure GPIO1 for SDLA operation
			GpioCtrlRegs.GPAMUX1.bit.GPIO1  = 2;    // Configure GPIO1 for SDLA operation
	
			break;
		
		
		case I2C_A_GPIO32_GPIO33:
			/* Enable internal pull-up for the selected I2C pins */
			GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;
			GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;
			
			/* Set qualification for the selected I2C pins */
			GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3;
			GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3;
			
			/* Configure which of the possible GPIO pins will be I2C_A pins using GPIO regs*/
			GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1;
			GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1;

			break;
			
		case I2C_A_GPIO42_GPIO43:
			/* Enable internal pull-up for the selected I2C pins */
			
			/* Set qualification for the selected I2C pins */
			
			/* Configure which of the possible GPIO pins will be I2C_A pins using GPIO regs*/
			break;
			
		case I2C_A_GPIO91_GPIO92:
			/* Enable internal pull-up for the selected I2C pins */
			GpioCtrlRegs.GPCPUD.bit.GPIO91 = 0;
			GpioCtrlRegs.GPCPUD.bit.GPIO92 = 0;
			
			/* Set qualification for the selected I2C pins */
	   		GpioCtrlRegs.GPCQSEL2.bit.GPIO91 = 3;
	   		GpioCtrlRegs.GPCQSEL2.bit.GPIO92 = 3;
			
			/* Configure which of the possible GPIO pins will be I2C_A pins using GPIO regs*/

	   		GpioCtrlRegs.GPCGMUX2.bit.GPIO91 = 1;	GpioCtrlRegs.GPCMUX2.bit.GPIO91 = 2;
	   		GpioCtrlRegs.GPCGMUX2.bit.GPIO92 = 1;	GpioCtrlRegs.GPCMUX2.bit.GPIO92 = 2;
			break;
			
		case I2C_A_GPIO63104_GPIO105:
			/* Enable internal pull-up for the selected I2C pins */
			
			/* Set qualification for the selected I2C pins */
			
			/* Configure which of the possible GPIO pins will be I2C_A pins using GPIO regs*/
			break;

		default:
			
			break;
			
	} // End of Switch
	EDIS;
} //////////// End of I2cAGpioConfig ///////////////////////////////////////

//************************************************************************************
// 'I2cbDataClkPin' should be assign with one of the possible I2C_B SDA - SDL GPIO pin
// Use defined Macros from "F2837xS_I2c_defines.h" for assignment
//************************************************************************************
void I2cBGpioConfig(Uint16 I2cbDataClkPin)
{
	EALLOW;

	switch(I2cbDataClkPin)
	{
		case I2C_B_GPIO2_GPIO3:
			/* Enable internal pull-up for the selected I2C pins */
			GpioCtrlRegs.GPAPUD.bit.GPIO2 = 0;     // Enable pull-up for GPIO0 (SDAB)
			GpioCtrlRegs.GPAPUD.bit.GPIO3 = 0;     // Enable pull-up for GPIO1 (SDLB)
		
			/* Set qualification for the selected I2C pins */
			GpioCtrlRegs.GPAQSEL1.bit.GPIO2 = 3;   // Async/no qualification (I/ps sync
			GpioCtrlRegs.GPAQSEL1.bit.GPIO3 = 3;   // to SYSCLKOUT by default)

			/* Configure which of the possible GPIO pins will be I2C_B pins using GPIO regs*/
			GpioCtrlRegs.GPAGMUX1.bit.GPIO2 = 1;    // Configure GPIO0 for SDAB operation
			GpioCtrlRegs.GPAMUX1.bit.GPIO2  = 2;    // Configure GPIO0 for SDAB operation
		
			GpioCtrlRegs.GPAGMUX1.bit.GPIO3 = 1;    // Configure GPIO1 for SDLB operation
			GpioCtrlRegs.GPAMUX1.bit.GPIO3  = 2;    // Configure GPIO1 for SDLB operation
			
			break;

		case I2C_B_GPIO134_GPIO35:
			/* Enable internal pull-up for the selected I2C pins */

			/* Set qualification for the selected I2C pins */

			/* Configure which of the possible GPIO pins will be I2C_B pins using GPIO regs*/
			break;

		case I2C_B_GPIO40_GPIO41:
			/* Enable internal pull-up for the selected I2C pins */

			/* Set qualification for the selected I2C pins */

			/* Configure which of the possible GPIO pins will be I2C_B pins using GPIO regs*/
			break;

		case I2C_B_GPIO66_GPIO69:
			/* Enable internal pull-up for the selected I2C pins */
			GpioCtrlRegs.GPCPUD.bit.GPIO66 = 0;	//SDAB
			GpioCtrlRegs.GPCPUD.bit.GPIO69 = 0;	//SCLB

			/* Set qualification for the selected I2C pins */
			GpioCtrlRegs.GPCQSEL1.bit.GPIO66 = 3;
			GpioCtrlRegs.GPCQSEL1.bit.GPIO69 = 3;

			/* Configure which of the possible GPIO pins will be I2C_B pins using GPIO regs*/
			GpioCtrlRegs.GPCGMUX1.bit.GPIO66 = 1;	//0x6
			GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 2;

			GpioCtrlRegs.GPCGMUX1.bit.GPIO69 = 1;	//0x6
			GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 2;
			break;

		default:
			break;

	}
	EDIS;
}
//////////// End of I2cBGpioConfig///////////////////////////////////////
#endif


//===========================================================================
// End of file.
//===========================================================================
