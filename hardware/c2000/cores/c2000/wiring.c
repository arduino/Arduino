/*
  ************************************************************************
  *	wiring.c
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  wiring.c - Partial implementation of the Wiring API for the ATmega8.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/
#include "Energia.h"

void initClocks(void);

extern void DSP28x_usDelay(Uint32 Count);
extern void analogInit(void);


volatile uint32_t wdtCounter = 0;

interrupt void rsvd_ISR(void)      // For test
{
  asm ("      ESTOP0");
  for(;;);
}

void disableWatchDog()
{
	EALLOW;
	SysCtrlRegs.WDCR= 0x0068;
	EDIS;

}

void serviceWatchDog(void)
{
    EALLOW;
    SysCtrlRegs.WDKEY = 0x0055;
    SysCtrlRegs.WDKEY = 0x00AA;
    EDIS;
}


void enableWatchDog()
{
	EALLOW;
	SysCtrlRegs.WDCR= 0x0028;
	EDIS;
}

interrupt void wdInt()
{

  //Increment our WD counter  
  wdtCounter++;

  //Not needed...watchdog rolls over after overflow...
  //Also...please excuse the poor pun in the line above
  //Service the watchdog
  //serviceWatchDog();

  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}



#define WDCLK_FREQUENCY 10000000UL
#define WD_PRESCALER 1
#define WDT_TICKS_PER_MILISECOND (1/((1/(WDCLK_FREQUENCY/512UL/WD_PRESCALER))*256UL))*(1/1000UL)
//Hardcoded because the compiler isn't playing nicely...grrrr
#define WDT_MILISECONDS_PER_TICK 13 //((1/(WDCLK_FREQUENCY/512/WD_PRESCALER))*256)*1000UL


#pragma CODE_SECTION(initFlash, "ramfuncs");
void initFlash(void)
{
   EALLOW;
   //Enable Flash Pipeline mode to improve performance
   //of code executed from Flash.
   FlashRegs.FOPT.bit.ENPIPE = 1;

   //                CAUTION
   //Minimum waitstates required for the flash operating
   //at a given CPU rate must be characterized by TI.
   //Refer to the datasheet for the latest information.
#if F_CPU >= 90000000L
  //Set the Paged Waitstate for the Flash
  FlashRegs.FBANKWAIT.bit.PAGEWAIT = 3;

  //Set the Random Waitstate for the Flash
  FlashRegs.FBANKWAIT.bit.RANDWAIT = 3;

  //Set the Waitstate for the OTP
  FlashRegs.FOTPWAIT.bit.OTPWAIT = 5;

#elif F_CPU >= 60000000L
	//Set the Paged Waitstate for the Flash
	FlashRegs.FBANKWAIT.bit.PAGEWAIT = 2;

	//Set the Random Waitstate for the Flash
	FlashRegs.FBANKWAIT.bit.RANDWAIT = 2;

	//Set the Waitstate for the OTP
	FlashRegs.FOTPWAIT.bit.OTPWAIT = 2;

#elif F_CPU >= 40000000L
	//Set the Paged Waitstate for the Flash
	FlashRegs.FBANKWAIT.bit.PAGEWAIT = 1;

	//Set the Random Waitstate for the Flash
	FlashRegs.FBANKWAIT.bit.RANDWAIT = 1;

	//Set the Waitstate for the OTP
	FlashRegs.FOTPWAIT.bit.OTPWAIT = 1;

#elif F_CPU >= 20000000L
	//Set the Paged Waitstate for the Flash
	FlashRegs.FBANKWAIT.bit.PAGEWAIT = 0;

	//Set the Random Waitstate for the Flash
	FlashRegs.FBANKWAIT.bit.RANDWAIT = 0;

	//Set the Waitstate for the OTP
	FlashRegs.FOTPWAIT.bit.OTPWAIT = 0;
#endif
   //                CAUTION
   //ONLY THE DEFAULT VALUE FOR THESE 2 REGISTERS SHOULD BE USED
   FlashRegs.FSTDBYWAIT.bit.STDBYWAIT = 0x01FF;
   FlashRegs.FACTIVEWAIT.bit.ACTIVEWAIT = 0x01FF;
   EDIS;

   //Force a pipeline flush to ensure that the write to
   //the last register configured occurs before returning.

   asm(" RPT #7 || NOP");
}

void initPie(void)
{
    int16    i;
    Uint32 *Dest = (void *) &PieVectTable;

    // Disable Interrupts at the CPU level:
    DINT;

    // Disable the PIE
    PieCtrlRegs.PIECTRL.bit.ENPIE = 0;

    // Clear all PIEIER registers:
    PieCtrlRegs.PIEIER1.all = 0;
    PieCtrlRegs.PIEIER2.all = 0;
    PieCtrlRegs.PIEIER3.all = 0;
    PieCtrlRegs.PIEIER4.all = 0;
    PieCtrlRegs.PIEIER5.all = 0;
    PieCtrlRegs.PIEIER6.all = 0;
    PieCtrlRegs.PIEIER7.all = 0;
    PieCtrlRegs.PIEIER8.all = 0;
    PieCtrlRegs.PIEIER9.all = 0;
    PieCtrlRegs.PIEIER10.all = 0;
    PieCtrlRegs.PIEIER11.all = 0;
    PieCtrlRegs.PIEIER12.all = 0;

    // Clear all PIEIFR registers:
    PieCtrlRegs.PIEIFR1.all = 0;
    PieCtrlRegs.PIEIFR2.all = 0;
    PieCtrlRegs.PIEIFR3.all = 0;
    PieCtrlRegs.PIEIFR4.all = 0;
    PieCtrlRegs.PIEIFR5.all = 0;
    PieCtrlRegs.PIEIFR6.all = 0;
    PieCtrlRegs.PIEIFR7.all = 0;
    PieCtrlRegs.PIEIFR8.all = 0;
    PieCtrlRegs.PIEIFR9.all = 0;
    PieCtrlRegs.PIEIFR10.all = 0;
    PieCtrlRegs.PIEIFR11.all = 0;
    PieCtrlRegs.PIEIFR12.all = 0;



    // Do not write over first 3 32-bit locations (these locations are
    // initialized by Boot ROM with boot variables)

    Dest = Dest + 3;

    EALLOW;
    for(i=0; i < 125; i++)
        *Dest++ = (Uint32) rsvd_ISR;
    EDIS;

    // Enable the PIE Vector Table
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;

    EINT;
}



void initClocks(void)
{

    volatile Uint16 iVol;

	//Calibrate ADC
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1; // Enable ADC peripheral clock
    (*Device_cal)();
    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 0; // Return ADC clock to original state

    //Select internal oscillator 1
    SysCtrlRegs.CLKCTL.bit.INTOSC1OFF = 0;
	SysCtrlRegs.CLKCTL.bit.OSCCLKSRCSEL=0;  // Clk Src = INTOSC1
	SysCtrlRegs.CLKCTL.bit.XCLKINOFF=1;     // Turn off XCLKIN
	SysCtrlRegs.CLKCTL.bit.XTALOSCOFF=1;    // Turn off XTALOSC
	SysCtrlRegs.CLKCTL.bit.INTOSC2OFF=1;    // Turn off INTOSC2

    EDIS;


    // Make sure the PLL is not running in limp mode
    if (SysCtrlRegs.PLLSTS.bit.MCLKSTS != 0)
    {
       EALLOW;
       // OSCCLKSRC1 failure detected. PLL running in limp mode.
       // Re-enable missing clock logic.
       SysCtrlRegs.PLLSTS.bit.MCLKCLR = 1;
       EDIS;
       // Replace this line with a call to an appropriate
       // SystemShutdown(); function.
       asm("        ESTOP0");     // Uncomment for debugging purposes
    }

    // DIVSEL MUST be 0 before PLLCR can be changed from
    // 0x0000. It is set to 0 by an external reset XRSn
    // This puts us in 1/4
    if (SysCtrlRegs.PLLSTS.bit.DIVSEL != 0)
    {
        EALLOW;
        SysCtrlRegs.PLLSTS.bit.DIVSEL = 0;
        EDIS;
    }



	EALLOW;
	// Before setting PLLCR turn off missing clock detect logic
	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 1;
#if F_CPU >= 90000000L
  SysCtrlRegs.PLLCR.bit.DIV = 0x12;
#elif F_CPU >= 60000000L
  SysCtrlRegs.PLLCR.bit.DIV = 0x0C;
#elif F_CPU >= 50000000L
	SysCtrlRegs.PLLCR.bit.DIV = 0x0A;
#elif F_CPU >= 40000000L
	SysCtrlRegs.PLLCR.bit.DIV = 0x08;
#elif F_CPU >= 3000000L
	SysCtrlRegs.PLLCR.bit.DIV = 0x06;
#elif F_CPU >= 2000000L
	SysCtrlRegs.PLLCR.bit.DIV = 0x04;
#else
        #warning No Suitable Frequency found!
#endif
	EDIS;


	// Uncomment to disable the watchdog
	disableWatchDog();

	while(SysCtrlRegs.PLLSTS.bit.PLLLOCKS != 1)
	{
	   // Uncomment to service the watchdog
	   // ServiceDog();
	}

	EALLOW;
	SysCtrlRegs.PLLSTS.bit.MCLKOFF = 0;
	EDIS;



	EALLOW;
	SysCtrlRegs.PLLSTS.bit.DIVSEL = 2;
	EDIS;






}

void initWatchDog()
{

    EALLOW;
    PieVectTable.WAKEINT = &wdInt;
    EDIS;

    EALLOW;
    // Configure the watchdog to interrupt the CPU...not reset
    SysCtrlRegs.SCSR = 0x0002;
    EDIS;

    PieCtrlRegs.PIEIER1.bit.INTx8 = 1;   // Enable PIE Gropu 1 INT8
    IER |= M_INT1;                       // Enable CPU INT1

    
    serviceWatchDog();

    // Enable the watchdog
   EALLOW;
   SysCtrlRegs.WDCR = 0x0028;
   EDIS;

}


unsigned long micros()
{
    return (1000 * wdtCounter) * WDT_MILISECONDS_PER_TICK;
}

unsigned long millis()
{
        return wdtCounter * WDT_MILISECONDS_PER_TICK;
}

/* Delay for the given number of microseconds.  Assumes a 1, 8 or 16 MHz clock. */
void delayMicroseconds(uint32_t us)
{
	DSP28x_usDelay(((((long double) us * 1000.0L) / ((long double)(1000000000/F_CPU))) - 9.0L) / 5.0L);
}



/* (ab)use the WDT */
void delay(uint32_t milliseconds)
{
	delayMicroseconds(milliseconds * 1000);
}

void disablePullups(void)
{
    EALLOW;
    GpioCtrlRegs.GPAPUD.all = 0xFFFFFFFF;
    GpioCtrlRegs.GPBPUD.all = 0xFFFFFFFF;
    EDIS;
}


void init()
{
	disableWatchDog();

	initClocks();

	//Copy RAM functions
	memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);

	//Setup flash waitstates
	initFlash();

	initPie();

    initWatchDog();

    disablePullups();

	analogInit();

	EINT;
}
