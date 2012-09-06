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

unsigned long ms_Counter = 0;
unsigned long us_Counter = 0;
void initClocks(void);
void enableWatchDogIntervalMode(void);
void enableSysTick(void)
void init()
{
	ROM_SysTickPeriodSet(ROM_SysCtlClockGet()/1000000);//1us
    ROM_IntMasterEnable();
    ROM_SysTickIntEnable();
    ROM_SysTickEnable();
}

volatile uint32_t wdtCounter = 0;
void delay4Cycles(unsigned long ulCount)
{
    __asm("    nop\n"
          "    sub     r0,r0, #1\n"
          "    bne     delay4Cycles\n"
          "    bx      lr");
}
unsigned long micros()
{
    return us_Counter;
}

unsigned long millis()
{
    return ms_Counter;
}

/* Delay for the given number of microseconds.  Assumes a 1, 8 or 16 MHz clock. */
void delayMicroseconds(unsigned int us)
{
#if F_CPU == 80000000L
	/* For a one-microsecond delay, simply wait 2 cycle and return. The overhead
	 * of the function call yields a delay of exactly one microsecond. */
	__asm__ __volatile__ (
		"nop" "\n\t"
		"nop");
	if (--us == 0)
		return;
	/* The following loop takes a 1/20 of a microsecond (4 cycles)
	 * per iteration, so execute it 20 times for each microsecond of
	 * delay requested. */
	us = ((us<<2) + us)<<4; // x20 us

	/* Account for the time taken in the preceeding commands. */
	us -= 2;//TO-DO=Test this
#elif F_CPU == 40000000L
	/* For a one-microsecond delay, simply wait 2 cycle and return. The overhead
	 * of the function call yields a delay of exactly one microsecond. */
	__asm__ __volatile__ (
		"nop" "\n\t"
		"nop");
	if (--us == 0)
		return;
	/* The following loop takes a 1/10 of a microsecond (4 cycles)
	 * per iteration, so execute it 20 times for each microsecond of
	 * delay requested. */
	us = ((us<<2) + us)<<1; // x10 us

	/* Account for the time taken in the preceeding commands. */
	us -= 2;//TO-DO=Test this
#elif F_CPU >= 16000000L
	/* For the 16 MHz clock on most boards */

	/* For a one-microsecond delay, simply return.  the overhead
	 * of the function call yields a delay of approximately 1 1/8 us. */
	if (--us == 0)
		return;

	/* The following loop takes a quarter of a microsecond (4 cycles)
	 * per iteration, so execute it four times for each microsecond of
	 * delay requested. */
	us <<= 2;

	/* Account for the time taken in the preceeding commands. */
	us -= 2;
#else
	/* For the 1 MHz */

	/* For a one- or two-microsecond delay, simply return.  the overhead of
	 * the function calls takes more than two microseconds.  can't just
	 * subtract two, since us is unsigned; we'd overflow. */
	if (--us == 0)
		return;
	if (--us == 0)
		return;

	/* The following loop takes 4 microsecond (4 cycles)
	 * per iteration, so execute it ones for each 4 microsecond of
	 * delay requested. */
	us >>= 2;

	/* Partially compensate for the time taken by the preceeding commands.
	 * we can't subtract any more than this or we'd overflow w/ small delays. */
	us--;
#endif

	delay4Cycles(us);
}

/* (ab)use the WDT */
void delay(uint32_t milliseconds)
{
	delayMicroseconds(1000*milliseconds);
/*	uint32_t wakeTime = wdtCounter + (milliseconds * WDT_TICKS_PER_MILISECOND);
        while(wdtCounter < wakeTime)
                // Wait for WDT interrupt in LMP0
                __bis_status_register(LPM0_bits+GIE);*/
}

void
SysTickIntHandler(void)
{
    us_Counter++;
    if(!(us_Counter % 1000))
        ms_Counter++;
}
