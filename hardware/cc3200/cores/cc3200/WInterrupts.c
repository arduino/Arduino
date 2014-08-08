/*
 ************************************************************************
 *	WInterrupts.c
 *
 *	Energia core files for CC3200
 *		Copyright (c) 2014 Robert Wessels. All right reserved.
 *
 *
 ***********************************************************************
  Derived from:

  WInterrupts.c Part of the Wiring project - http://wiring.uniandes.edu.co

  Copyright (c) 2004-05 Hernando Barragan

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

  Modified 24 November 2006 by David A. Mellis
  Modified 1 August 2010 by Mark Sproul
 */

#include <Energia.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "wiring_private.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus


static void (*cbFuncsA0[8])(void);
static void (*cbFuncsA1[8])(void);
static void (*cbFuncsA2[8])(void);
static void (*cbFuncsA3[8])(void);

void GPIOXIntHandler(uint32_t base, void (**funcs)(void))
{
	uint32_t i;
	uint32_t isr = GPIOIntStatus(base, true);

	GPIOIntClear(base, isr);

	for (i=0; i<8; i++, isr>>=1) {
		if ((isr & 0x1) == 0)
			continue;
		if (funcs[i])
			funcs[i]();
	}
}

void GPIOA0IntHandler(void)
{
	GPIOXIntHandler(GPIOA0_BASE, cbFuncsA0);
}

void GPIOA1IntHandler(void)
{
	GPIOXIntHandler(GPIOA1_BASE, cbFuncsA1);
}

void GPIOA2IntHandler(void)
{
	GPIOXIntHandler(GPIOA2_BASE, cbFuncsA2);
}

void GPIOA3IntHandler(void)
{
	GPIOXIntHandler(GPIOA3_BASE, cbFuncsA3);
}

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode)
{
	uint32_t cc3200Mode, i;

	uint8_t bit = digitalPinToBitMask(interruptNum);
	uint8_t port = digitalPinToPort(interruptNum);
	uint32_t portBase = (uint32_t) portBASERegister(port);

	switch(mode) {
	case LOW:
		cc3200Mode = GPIO_LOW_LEVEL;
		break;
	case CHANGE:
		cc3200Mode = GPIO_BOTH_EDGES;
		break;
	case RISING:
		cc3200Mode = GPIO_RISING_EDGE;
		break;
	case FALLING:
		cc3200Mode = GPIO_FALLING_EDGE;
		break;
	default:
		return;
	}

	MAP_IntMasterDisable();
	MAP_GPIOIntClear(portBase, bit);
	MAP_GPIOIntTypeSet(portBase, bit, cc3200Mode);
	MAP_GPIOIntEnable(portBase, bit);

	for (i=0; i<8; i++, bit>>=1) {
		if ((bit & 0x1) == 1)
			break;
	}

	switch(portBase) {
	case GPIOA0_BASE:
		cbFuncsA0[i] = userFunc;
		MAP_GPIOIntRegister(GPIOA0_BASE, GPIOA0IntHandler);
		IntEnable(INT_GPIOA0);
		break;
	case GPIOA1_BASE:
		cbFuncsA1[i] = userFunc;
		MAP_GPIOIntRegister(GPIOA1_BASE, GPIOA1IntHandler);
		IntEnable(INT_GPIOA1);
		break;
	case GPIOA2_BASE:
		cbFuncsA2[i] = userFunc;
		MAP_GPIOIntRegister(GPIOA2_BASE, GPIOA2IntHandler);
		IntEnable(INT_GPIOA2);
		break;
	case GPIOA3_BASE:
		cbFuncsA3[i] = userFunc;
		MAP_GPIOIntRegister(GPIOA3_BASE, GPIOA3IntHandler);
		IntEnable(INT_GPIOA3);
		break;
	}

	MAP_IntMasterEnable();
}

void detachInterrupt(uint8_t interruptNum)
{
	uint32_t i;

	uint8_t bit = digitalPinToBitMask(interruptNum);
	uint8_t port = digitalPinToPort(interruptNum);
	uint32_t portBase = (uint32_t) portBASERegister(port);

	if (port == NOT_A_PIN) return;

	GPIOIntDisable(portBase, bit);

	for (i=0; i<8; i++, bit>>=1) {
		if ((bit & 0x1) == 1)
			break;
	}

	switch(portBase) {
	case GPIOA0_BASE:
		cbFuncsA0[i] = 0;
	case GPIOA1_BASE:
		cbFuncsA1[i] = 0;
	case GPIOA2_BASE:
		cbFuncsA2[i] = 0;
	case GPIOA3_BASE:
		cbFuncsA3[i] = 0;
	}
}
#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus
