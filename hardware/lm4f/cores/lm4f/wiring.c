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
#include "inc/hw_types.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

void timerInit()
{
    ROM_SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|
                SYSCTL_OSC_MAIN);

	ROM_SysTickPeriodSet(ROM_SysCtlClockGet()/1000);//0.125us
    ROM_SysTickEnable();

    //
    //Initialize WTimer4 to be used as time-tracker since beginning of time
    //
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER4); //not tied to launchpad pin
    ROM_TimerConfigure(WTIMER4_BASE, TIMER_CFG_PERIODIC);
    ROM_TimerLoadSet64(WTIMER4_BASE, 0xFFFFFFFFFFFFFFFF); //start at 0 and count up
    ROM_TimerEnable(WTIMER4_BASE, TIMER_A);
    HWREG(0xE000E014) = 0x00FFFFFF;
}

uint64_t micros()
{
    uint64_t cycles = 0xFFFFFFFFFFFFFFFF - ROM_TimerValueGet64(WTIMER4_BASE);
    return (cycles / 80);
}

uint64_t millis()
{
    return (micros() / 1000);
}

/* Delay for the given number of microseconds.  Assumes a 1, 8 or 16 MHz clock. */
void delayMicroseconds(uint32_t us)
{
	volatile uint32_t elapsedTime;
	uint32_t startTime = HWREG(0xE000E018);
	do{
		elapsedTime = startTime-(HWREG(0xE000E018) & 0x00FFFFFF);
	}
	while(elapsedTime <= us*80);
}


/* (ab)use the WDT */
void delay(uint32_t milliseconds)
{
	uint32_t i;
	for(i=0; i<milliseconds; i++){
		delayMicroseconds(1000);
	}
}
