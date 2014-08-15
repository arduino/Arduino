/*
 ************************************************************************
 *	wiring.c
 *
 *	Energia core files for cc3200
 *		Copyright (c) 2014 Robert Wessels. All right reserved.
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
#include "inc/hw_ints.h"
#include "inc/hw_timer.h"
#include "driverlib/rom_map.h"
#include "driverlib/systick.h"
#include "driverlib/timer.h"

static void (*SysTickCbFuncs[8])(uint32_t ui32TimeMS);

#define SYSTICKMS               (1000 / SYSTICKHZ)
#define SYSTICKHZ               100

static unsigned long milliseconds = 0;
#define SYSTICK_INT_PRIORITY    0x80


unsigned long micros(void)
{
	return (milliseconds * 1000) + (SysTickValueGet() / (F_CPU/1000000));
}

unsigned long millis(void)
{
	return milliseconds;
}

void delayMicroseconds(unsigned int us)
{
	volatile unsigned long elapsedTime;
	unsigned long startTime = SysTickValueGet();

	do{
		elapsedTime = startTime - SysTickValueGet();
	} while(elapsedTime <= us * (F_CPU/1000000));
}

void delay(uint32_t millis)
{
	unsigned long i;
	for(i=0; i<millis; i++){
		delayMicroseconds(1000);
	}
}

void registerSysTickCb(void (*userFunc)(uint32_t))
{
	uint8_t i;
	for (i=0; i<8; i++) {
		if(!SysTickCbFuncs[i]) {
			SysTickCbFuncs[i] = userFunc;
			break;
		}
	}
}

void SysTickIntHandler(void)
{
	milliseconds++;

	uint8_t i;
	for (i=0; i<8; i++) {
		if (SysTickCbFuncs[i])
			SysTickCbFuncs[i](SYSTICKMS);
	}
}
