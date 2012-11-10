/*
 ************************************************************************
 *	WInterrupts.c
 *
 *	Arduino core files for MSP430
 *		Copyright (c) 2012 Robert Wessels. All right reserved.
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

#include <inttypes.h>
#include <stdio.h>
#include "inc/hw_types.h"
#include "inc/hw_nvic.h"
#include "inc/hw_ints.h"
#include "driverlib/gpio.h"
#include "wiring_private.h"
#include "driverlib/rom.h"

static void (*cbFuncsA[8])(void);
static void (*cbFuncsB[8])(void);
static void (*cbFuncsC[8])(void);
static void (*cbFuncsD[8])(void);
static void (*cbFuncsE[8])(void);
static void (*cbFuncsF[8])(void);

void GPIOAIntHandler(void) {
	uint32_t i;
	uint32_t isr = ROM_GPIOPinIntStatus(GPIO_PORTA_BASE, true);

	ROM_GPIOPinIntClear(GPIO_PORTA_BASE, isr);

	for (i=0; i<8; i++, isr>>=1) {
		if ((isr & 0x1) == 0)
			continue;
		if (cbFuncsA[i])
			cbFuncsA[i]();
	}
}

void GPIOBIntHandler(void) {
	uint32_t i;
	uint32_t isr = ROM_GPIOPinIntStatus(GPIO_PORTB_BASE, true);

	ROM_GPIOPinIntClear(GPIO_PORTB_BASE, isr);

	for (i=0; i<8; i++, isr>>=1) {
		if ((isr & 0x1) == 0)
			continue;
		if (cbFuncsB[i])
			cbFuncsB[i]();
	}
}

void GPIOCIntHandler(void) {
	uint32_t i;
	uint32_t isr = ROM_GPIOPinIntStatus(GPIO_PORTC_BASE, true);

	ROM_GPIOPinIntClear(GPIO_PORTC_BASE, isr);

	for (i=0; i<8; i++, isr>>=1) {
		if ((isr & 0x1) == 0)
			continue;
		if (cbFuncsC[i])
			cbFuncsC[i]();
	}
}

void GPIODIntHandler(void) {
	uint32_t i;
	uint32_t isr = ROM_GPIOPinIntStatus(GPIO_PORTD_BASE, true);

	ROM_GPIOPinIntClear(GPIO_PORTD_BASE, isr);

	for (i=0; i<8; i++, isr>>=1) {
		if ((isr & 0x1) == 0)
			continue;
		if (cbFuncsD[i])
			cbFuncsD[i]();
	}
}

void GPIOEIntHandler(void) {
	uint32_t i;
	uint32_t isr = ROM_GPIOPinIntStatus(GPIO_PORTE_BASE, true);

	ROM_GPIOPinIntClear(GPIO_PORTE_BASE, isr);

	for (i=0; i<8; i++, isr>>=1) {
		if ((isr & 0x1) == 0)
			continue;
		if (cbFuncsE[i])
			cbFuncsE[i]();
	}
}

void GPIOFIntHandler(void) {
	uint32_t i;
	uint32_t isr = ROM_GPIOPinIntStatus(GPIO_PORTF_BASE, true);

	ROM_GPIOPinIntClear(GPIO_PORTF_BASE, isr);

	for (i=0; i<8; i++, isr>>=1) {
		if ((isr & 0x1) == 0)
			continue;
		if (cbFuncsF[i])
			cbFuncsF[i]();
	}
}

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
	uint32_t lm4fMode, i;

	uint8_t bit = digitalPinToBitMask(interruptNum);
	uint8_t port = digitalPinToPort(interruptNum);
	uint32_t portBase = (uint32_t) portBASERegister(port);

	switch(mode) {
	case LOW:
		lm4fMode = GPIO_LOW_LEVEL;
		break;
	case CHANGE:
		lm4fMode = GPIO_BOTH_EDGES;
		break;
	case RISING:
		lm4fMode = GPIO_RISING_EDGE;
		break;
	case FALLING:
		lm4fMode = GPIO_FALLING_EDGE;
		break;
	default:
		return;
	}

	ROM_IntMasterDisable();
	ROM_GPIOPinIntClear(portBase, bit);
	ROM_GPIOIntTypeSet(portBase, bit, lm4fMode);
	ROM_GPIOPinIntEnable(portBase, bit);

	for (i=0; i<8; i++, bit>>=1) {
		if ((bit & 0x1) == 1)
			break;
	}

	switch(portBase) {
	case GPIO_PORTA_BASE:
		cbFuncsA[i] = userFunc;
		ROM_IntEnable(INT_GPIOA);
		break;
	case GPIO_PORTB_BASE:
		cbFuncsB[i] = userFunc;
		ROM_IntEnable(INT_GPIOB);
		break;
	case GPIO_PORTC_BASE:
		cbFuncsC[i] = userFunc;
		ROM_IntEnable(INT_GPIOC);
		break;
	case GPIO_PORTD_BASE:
		cbFuncsD[i] = userFunc;
		ROM_IntEnable(INT_GPIOD);
		break;
	case GPIO_PORTE_BASE:
		cbFuncsE[i] = userFunc;
		ROM_IntEnable(INT_GPIOE);
		break;
	case GPIO_PORTF_BASE:
		cbFuncsF[i] = userFunc;
		ROM_IntEnable(INT_GPIOF);
		break;
	}
	
	ROM_IntMasterEnable();

}

void detachInterrupt(uint8_t interruptNum) {
	uint32_t i;

	uint8_t bit = digitalPinToBitMask(interruptNum);
	uint8_t port = digitalPinToPort(interruptNum);
	uint32_t portBase = (uint32_t) portBASERegister(port);

	if (port == NOT_A_PIN) return;

	ROM_GPIOPinIntDisable(portBase, bit);

	for (i=0; i<8; i++, bit>>=1) {
		if ((bit & 0x1) == 1)
			break;
	}

	switch(portBase) {
	case GPIO_PORTA_BASE:
		cbFuncsA[i] = 0;
	case GPIO_PORTB_BASE:
		cbFuncsB[i] = 0;
	case GPIO_PORTC_BASE:
		cbFuncsC[i] = 0;
	case GPIO_PORTD_BASE:
		cbFuncsD[i] = 0;
	case GPIO_PORTE_BASE:
		cbFuncsE[i] = 0;
	case GPIO_PORTF_BASE:
		cbFuncsF[i] = 0;
	}
}
