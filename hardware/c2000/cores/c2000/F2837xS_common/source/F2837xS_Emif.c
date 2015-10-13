//###########################################################################
//
// FILE:   F2837xS_Emif.c
//
// TITLE:  F2837xS EMIF Initialization & Support Functions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // F2837xS Headerfile Include File
#include "F2837xS_Examples.h"   // F2837xS Examples Include File

//
// This function initializes the EMIF1 to a known state.
//
void Emif1Initialize(void)
{
    EALLOW;
    // Perform a Module soft reset on EMIF
#ifdef CPU1
    DevCfgRegs.SOFTPRES1.all = 0x1;
   __asm (" nop");
    DevCfgRegs.SOFTPRES1.all = 0x0;
#endif
    EDIS;
}

//
// This function initializes the EMIF2 to a known state.
//
void Emif2Initialize(void)
{
    EALLOW;
    // Perform a Module soft reset on EMIF
#ifdef CPU1
    DevCfgRegs.SOFTPRES1.all = 0x2;
   __asm (" nop");
    DevCfgRegs.SOFTPRES1.all = 0x0;
#endif
    EDIS;

}

//
//Async wait config function
//
void ASync_wait_config(Uint16 inst, Uint16 wait_count, Uint16 wait_polarity)
{
    if (inst == 0) 
    {
        Emif1Regs.ASYNC_WCCR.bit.MAX_EXT_WAIT = wait_count;       // 7:0 Maximum Extended Wait cycles.
        Emif1Regs.ASYNC_WCCR.bit.WP0 = wait_polarity;             // 28 Wait Polarity for pad_wait_i[0].
	}
	else 
    {
        Emif2Regs.ASYNC_WCCR.bit.MAX_EXT_WAIT = wait_count;       // 7:0 Maximum Extended Wait cycles.
        Emif2Regs.ASYNC_WCCR.bit.WP0 = wait_polarity;             // 28 Wait Polarity for pad_wait_i[0].
	}
}

void ASync_cs2_config(Uint16 inst, Uint16 async_mem_data_width, 
                      Uint16 turn_around_time, Uint16 r_hold_time, 
                      Uint16 r_strobe_time, Uint16 r_setup, Uint16 w_hold, 
                      Uint16 w_strobe, Uint16 w_setup, Uint16 extend_wait, 
                      Uint16 strobe_sel) 
{ 
    if (inst == 0) 
    {
        Emif1Regs.ASYNC_CS2_CR.bit.ASIZE = async_mem_data_width;  // 1:0 Asynchronous Memory Size.
        Emif1Regs.ASYNC_CS2_CR.bit.TA= turn_around_time;          // 3:2 Turn Around cycles.
        Emif1Regs.ASYNC_CS2_CR.bit.R_HOLD= r_hold_time;           // 6:4 Read Strobe Hold cycles.
        Emif1Regs.ASYNC_CS2_CR.bit.R_STROBE = r_strobe_time;      // 12:7 Read Strobe Duration cycles.
        Emif1Regs.ASYNC_CS2_CR.bit.R_SETUP = r_setup;             // 16:13 Read Strobe Setup cycles.
        Emif1Regs.ASYNC_CS2_CR.bit.W_HOLD = w_hold;               // 19:17 Write Strobe Hold cycles.
        Emif1Regs.ASYNC_CS2_CR.bit.W_STROBE = w_strobe;           // 25:20 Write Strobe Duration cycles.
        Emif1Regs.ASYNC_CS2_CR.bit.W_SETUP  = w_setup;            // 29:26 Write Strobe Setup cycles.
        Emif1Regs.ASYNC_CS2_CR.bit.EW = extend_wait;              // 30 Extend Wait mode.
        Emif1Regs.ASYNC_CS2_CR.bit.SS = strobe_sel;               // 31 Select Strobe mode.
	}
	else 
    {
        Emif2Regs.ASYNC_CS2_CR.bit.ASIZE = async_mem_data_width;  // 1:0 Asynchronous Memory Size.
        Emif2Regs.ASYNC_CS2_CR.bit.TA= turn_around_time;          // 3:2 Turn Around cycles.
        Emif2Regs.ASYNC_CS2_CR.bit.R_HOLD= r_hold_time;           // 6:4 Read Strobe Hold cycles.
        Emif2Regs.ASYNC_CS2_CR.bit.R_STROBE = r_strobe_time;      // 12:7 Read Strobe Duration cycles.
        Emif2Regs.ASYNC_CS2_CR.bit.R_SETUP = r_setup;             // 16:13 Read Strobe Setup cycles.
        Emif2Regs.ASYNC_CS2_CR.bit.W_HOLD = w_hold;               // 19:17 Write Strobe Hold cycles.
        Emif2Regs.ASYNC_CS2_CR.bit.W_STROBE = w_strobe;           // 25:20 Write Strobe Duration cycles.
        Emif2Regs.ASYNC_CS2_CR.bit.W_SETUP  = w_setup;            // 29:26 Write Strobe Setup cycles.
        Emif2Regs.ASYNC_CS2_CR.bit.EW = extend_wait;              // 30 Extend Wait mode.
        Emif2Regs.ASYNC_CS2_CR.bit.SS = strobe_sel;               // 31 Select Strobe mode.
	}
}

void ASync_cs3_config(Uint16 inst, Uint16 async_mem_data_width, 
                      Uint16 turn_around_time, Uint16 r_hold_time, 
                      Uint16 r_strobe_time, Uint16 r_setup, Uint16 w_hold, 
                      Uint16 w_strobe, Uint16 w_setup, Uint16 extend_wait, 
                      Uint16 strobe_sel) 
{
    Emif1Regs.ASYNC_CS3_CR.bit.ASIZE = async_mem_data_width;      // 1:0 Asynchronous Memory Size.
    Emif1Regs.ASYNC_CS3_CR.bit.TA= turn_around_time;              // 3:2 Turn Around cycles.
    Emif1Regs.ASYNC_CS3_CR.bit.R_HOLD= r_hold_time;               // 6:4 Read Strobe Hold cycles.
    Emif1Regs.ASYNC_CS3_CR.bit.R_STROBE = r_strobe_time;          // 12:7 Read Strobe Duration cycles.
    Emif1Regs.ASYNC_CS3_CR.bit.R_SETUP = r_setup;                 // 16:13 Read Strobe Setup cycles.
    Emif1Regs.ASYNC_CS3_CR.bit.W_HOLD = w_hold;                   // 19:17 Write Strobe Hold cycles.
    Emif1Regs.ASYNC_CS3_CR.bit.W_STROBE = w_strobe;               // 25:20 Write Strobe Duration cycles.
    Emif1Regs.ASYNC_CS3_CR.bit.W_SETUP  = w_setup;                // 29:26 Write Strobe Setup cycles.
    Emif1Regs.ASYNC_CS3_CR.bit.EW = extend_wait;                  // 30 Extend Wait mode.
    Emif1Regs.ASYNC_CS3_CR.bit.SS = strobe_sel;                   // 31 Select Strobe mode.
}

void ASync_cs4_config(Uint16 inst, Uint16 async_mem_data_width, 
                      Uint16 turn_around_time, Uint16 r_hold_time, 
                      Uint16 r_strobe_time, Uint16 r_setup, Uint16 w_hold, 
                      Uint16 w_strobe, Uint16 w_setup, Uint16 extend_wait, 
                      Uint16 strobe_sel) 
{
    Emif1Regs.ASYNC_CS4_CR.bit.ASIZE = async_mem_data_width;      // 1:0 Asynchronous Memory Size.
    Emif1Regs.ASYNC_CS4_CR.bit.TA= turn_around_time;              // 3:2 Turn Around cycles.
    Emif1Regs.ASYNC_CS4_CR.bit.R_HOLD= r_hold_time;               // 6:4 Read Strobe Hold cycles.
    Emif1Regs.ASYNC_CS4_CR.bit.R_STROBE = r_strobe_time;          // 12:7 Read Strobe Duration cycles.
    Emif1Regs.ASYNC_CS4_CR.bit.R_SETUP = r_setup;                 // 16:13 Read Strobe Setup cycles.
    Emif1Regs.ASYNC_CS4_CR.bit.W_HOLD = w_hold;                   // 19:17 Write Strobe Hold cycles.
    Emif1Regs.ASYNC_CS4_CR.bit.W_STROBE = w_strobe;               // 25:20 Write Strobe Duration cycles.
    Emif1Regs.ASYNC_CS4_CR.bit.W_SETUP  = w_setup;                // 29:26 Write Strobe Setup cycles.
    Emif1Regs.ASYNC_CS4_CR.bit.EW = extend_wait;                  // 30 Extend Wait mode.
    Emif1Regs.ASYNC_CS4_CR.bit.SS = strobe_sel;                   // 31 Select Strobe mode.
}

#ifdef CPU1
//function for EMIF1 GPIO pin setup
void setup_emif1_pinmux_async_16bit(Uint16 cpu_sel)
{
    Uint16 i;
    
    for (i=28; i<=52;i++) 
    {
        if (i != 42 || i != 43) 
        {
            GPIO_SetupPinMux(i,cpu_sel,2);
        }
    }
    for (i=63; i<=87;i++) 
    {
        if (i != 84)
        {        
            GPIO_SetupPinMux(i,cpu_sel,2);
        }
    }

    GPIO_SetupPinMux(88,cpu_sel,3);
    GPIO_SetupPinMux(89,cpu_sel,3);
    GPIO_SetupPinMux(90,cpu_sel,3);
    GPIO_SetupPinMux(91,cpu_sel,3);
    GPIO_SetupPinMux(92,cpu_sel,3);
    GPIO_SetupPinMux(93,cpu_sel,3);
    GPIO_SetupPinMux(94,cpu_sel,2);
	   
    //setup async mode and enable pull-ups for Data pins
    for (i=69; i<=85;i++) 
    {
        if (i != 84)
        {        
            GPIO_SetupPinOptions(i,0,0x31); // GPIO_ASYNC||GPIO_PULLUP
        }
    }   
 }   
 
void setup_emif1_pinmux_async_32bit(Uint16 cpu_sel)
{
    Uint16 i;
    
    for (i=28; i<=87;i++) 
    {
        if (i != 42 || i != 43 || i != 84 )
        {
            GPIO_SetupPinMux(i,cpu_sel,2);
        }
    }
    
    GPIO_SetupPinMux(88,cpu_sel,3);
    GPIO_SetupPinMux(89,cpu_sel,3);
    GPIO_SetupPinMux(90,cpu_sel,3);
    GPIO_SetupPinMux(91,cpu_sel,3);
    GPIO_SetupPinMux(92,cpu_sel,3);
    GPIO_SetupPinMux(93,cpu_sel,3);
    GPIO_SetupPinMux(94,cpu_sel,2);
	   
    //setup async mode for Data pins	   
    for (i=53; i<=85;i++) 
    {
        if (i != 84)
        {        
            GPIO_SetupPinOptions(i,0,0x31);
        }
    }	   
}
 
//function for EMIF1 GPIO pin setup
void setup_emif2_pinmux_async_16bit(Uint16 cpu_sel)
{
	Uint16 i;
    
	for (i=96; i<=121;i++) 
    {
		GPIO_SetupPinMux(i,cpu_sel,3);
	}
    
	for (i=53; i<=68;i++) 
    {
		GPIO_SetupPinMux(i,cpu_sel,3);
	}

	//setup async mode for Data pins
	for (i=53; i<=68;i++) 
    {
		GPIO_SetupPinOptions(i,0,0x31);
	}
}
 
void setup_emif1_pinmux_sdram_16bit(Uint16 cpu_sel)
{
	int i;
    
	for (i=29; i<=52;i++) 
    {
        if (i != 42 || i != 43)
        {        
            GPIO_SetupPinMux(i,cpu_sel,2);
        }
	}
    
	for (i=69; i<=85;i++) 
    {
        if (i != 84)
        {
            GPIO_SetupPinMux(i,cpu_sel,2);
        }
	}
	
	for(i=86;i<=93;i++)
    {
	   GPIO_SetupPinMux(i,cpu_sel,3);
	}

	//configure Data pins for Async mode
	for (i = 69;i <= 85;i++)
    {
		if (i != 84)
        {
			GPIO_SetupPinOptions(i,0,0x31);
        }
	}

	GPIO_SetupPinOptions(88,0,0x31);
	GPIO_SetupPinOptions(89,0,0x31);
	GPIO_SetupPinOptions(90,0,0x31);
	GPIO_SetupPinOptions(91,0,0x31);
}

void setup_emif2_pinmux_sdram_16bit(Uint16 cpu_sel)
{
	int i;
    
	for (i=53; i<=68;i++) 
    {
        GPIO_SetupPinMux(i,cpu_sel,3);
	}
	for (i=96; i<=121;i++) 
    {
        GPIO_SetupPinMux(i,cpu_sel,3);
	}
	
	//configure Data pins for Async mode
	for (i = 53;i <= 68;i++)
    {
        GPIO_SetupPinOptions(i,0,0x31);
	}
}

void setup_emif1_pinmux_sdram_32bit(Uint16 cpu_sel)
{
	int i;
    
	for (i=28; i<=85;i++) 
    {
        if (i != 42 || i != 43 || i != 84 )
        {        
            GPIO_SetupPinMux(i,cpu_sel,2);
        }
	}

	for(i=86;i<=93;i++)
    {
		GPIO_SetupPinMux(i,cpu_sel,3);
	}

	GPIO_SetupPinMux(94,cpu_sel,2);

	//configure Data pins for Async mode
	for (i = 53;i <= 85;i++)
    {
        if (i != 84)
        {
            GPIO_SetupPinOptions(i,0,0x31);
        }
	}

	GPIO_SetupPinOptions(88,0,0x31);
	GPIO_SetupPinOptions(89,0,0x31);
	GPIO_SetupPinOptions(90,0,0x31);
	GPIO_SetupPinOptions(91,0,0x31);
 }

#endif // CPU1
