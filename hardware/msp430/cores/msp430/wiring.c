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

  $Id$
*/
#include "Energia.h"

void initClocks(void);
void enableWatchDog(void);
void disableWatchDog(void);

void init(){
	disableWatchDog();
	initClocks(); // initialize clocks
        __eint();
}

void disableWatchDog(void)
{
	WDTCTL = WDTPW | WDTHOLD;
}

void enableWatchDog(void)
{
	// WDT Password + WDT interval mode + Watchdog clock source /512
	// Note that we WDT is running in interval mode. WDT will not trigger a reset on expire in this mode.
	WDTCTL = WDTPW + WDTTMSEL + WDTIS1;

	//WDT interrupt enable
	IE1 |= WDTIE;
}

void initClocks(void)
{
	/*
	 * TODO:
	 * A lot of the devices are capable of running at up to 16MHz using the calibrated register settings.
	 * We default to 1MHz since all devices are able to support this.
	 * Would be nice to have an API that would allow to bump up the speed.
	 */
	BCSCTL1 = CALBC1_16MHZ;
	DCOCTL = CALDCO_16MHZ;

	// SMCLK = DCO / DIVS = nMHz
	BCSCTL2 &= ~(DIVS_0);
}

#define SMCLK_FREQUENCY      1000000
#define WDT_DIVIDER        512

const uint32_t WDT_FREQUENCY = SMCLK_FREQUENCY / WDT_DIVIDER;
volatile uint32_t wdtCounter = 0;

unsigned long millis(){
	return wdtCounter / (WDT_FREQUENCY / 1000);
}

// (ab)use the WDT
void delay(uint32_t milliseconds){
	enableWatchDog();
	uint32_t wakeTime = wdtCounter + (milliseconds * WDT_FREQUENCY / 1000);
	while(wdtCounter < wakeTime);
	disableWatchDog();
}

__attribute__((interrupt(WDT_VECTOR)))
void watchdog_isr (void) {
	wdtCounter++;
}
