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

static void (*cbFuncsA[8])(void);
static void (*cbFuncsB[8])(void);
static void (*cbFuncsC[8])(void);
static void (*cbFuncsD[8])(void);
static void (*cbFuncsE[8])(void);
static void (*cbFuncsF[8])(void);
static void (*cbFuncsG[8])(void);
static void (*cbFuncsH[8])(void);
static void (*cbFuncsJ[8])(void);
static void (*cbFuncsK[8])(void);
static void (*cbFuncsL[8])(void);
static void (*cbFuncsM[8])(void);
static void (*cbFuncsN[8])(void);
static void (*cbFuncsP[8])(void);
static void (*cbFuncsQ[8])(void);
#ifdef TARGET_IS_SNOWFLAKE_RA0
static void (*cbFuncsR[8])(void);
static void (*cbFuncsS[8])(void);
static void (*cbFuncsT[8])(void);
#endif

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

void GPIOAIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTA_BASE, cbFuncsA);
}

void GPIOBIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTB_BASE, cbFuncsB);
}

void GPIOCIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTC_BASE, cbFuncsC);
}

void GPIODIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTD_BASE, cbFuncsD);
}

void GPIOEIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTE_BASE, cbFuncsE);
}

void GPIOFIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTF_BASE, cbFuncsF);
}

void GPIOGIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTG_BASE, cbFuncsG);
}

void GPIOHIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTH_BASE, cbFuncsH);
}

void GPIOJIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTJ_BASE, cbFuncsJ);
}

void GPIOKIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTK_BASE, cbFuncsK);
}

void GPIOLIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTL_BASE, cbFuncsL);
}

void GPIOMIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTM_BASE, cbFuncsM);
}
void GPIONIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTN_BASE, cbFuncsN);
}

void GPIOPIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTP_BASE, cbFuncsP);
}

void GPIOQIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTQ_BASE, cbFuncsQ);
}

#ifdef TARGET_IS_SNOWFLAKE_RA0
void GPIORIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTR_BASE, cbFuncsR);
}

void GPIOSIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTS_BASE, cbFuncsS);
}

void GPIOTIntHandler(void)
{
	GPIOXIntHandler(GPIO_PORTT_BASE, cbFuncsT);
}
#endif

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode)
{
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
	GPIOIntClear(portBase, bit);
	ROM_GPIOIntTypeSet(portBase, bit, lm4fMode);
	GPIOIntEnable(portBase, bit);

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
	case GPIO_PORTG_BASE:
		cbFuncsG[i] = userFunc;
		ROM_IntEnable(INT_GPIOG);
		break;
	case GPIO_PORTH_BASE:
		cbFuncsH[i] = userFunc;
		ROM_IntEnable(INT_GPIOH);
		break;
	case GPIO_PORTJ_BASE:
		cbFuncsJ[i] = userFunc;
		ROM_IntEnable(INT_GPIOJ);
		break;
	case GPIO_PORTK_BASE:
		cbFuncsK[i] = userFunc;
		ROM_IntEnable(INT_GPIOK);
		break;
	case GPIO_PORTL_BASE:
		cbFuncsL[i] = userFunc;
		ROM_IntEnable(INT_GPIOL);
		break;
	case GPIO_PORTM_BASE:
		cbFuncsM[i] = userFunc;
		ROM_IntEnable(INT_GPIOM);
		break;
	case GPIO_PORTN_BASE:
		cbFuncsN[i] = userFunc;
		ROM_IntEnable(INT_GPION);
		break;
	case GPIO_PORTP_BASE:
		cbFuncsP[i] = userFunc;
		ROM_IntEnable(INT_GPIOP0);
		ROM_IntEnable(INT_GPIOP1);
		ROM_IntEnable(INT_GPIOP2);
		ROM_IntEnable(INT_GPIOP3);
		ROM_IntEnable(INT_GPIOP4);
		ROM_IntEnable(INT_GPIOP5);
		ROM_IntEnable(INT_GPIOP6);
		ROM_IntEnable(INT_GPIOP7);
		break;
	case GPIO_PORTQ_BASE:
		cbFuncsQ[i] = userFunc;
		ROM_IntEnable(INT_GPIOQ0);
		ROM_IntEnable(INT_GPIOQ1);
		ROM_IntEnable(INT_GPIOQ2);
		ROM_IntEnable(INT_GPIOQ3);
		ROM_IntEnable(INT_GPIOQ4);
		ROM_IntEnable(INT_GPIOQ5);
		ROM_IntEnable(INT_GPIOQ6);
		ROM_IntEnable(INT_GPIOQ7);
		break;
#ifdef TARGET_IS_SNOWFLAKE_RA0
	case GPIO_PORTR_BASE:
		cbFuncsR[i] = userFunc;
		ROM_IntEnable(INT_GPIOR);
		break;
	case GPIO_PORTS_BASE:
		cbFuncsS[i] = userFunc;
		ROM_IntEnable(INT_GPIOS);
		break;
	case GPIO_PORTT_BASE:
		cbFuncsT[i] = userFunc;
		ROM_IntEnable(INT_GPIOT);
		break;
#endif
	}
	ROM_IntMasterEnable();
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
	case GPIO_PORTG_BASE:
		cbFuncsG[i] = 0;
	case GPIO_PORTH_BASE:
		cbFuncsH[i] = 0;
	case GPIO_PORTJ_BASE:
		cbFuncsJ[i] = 0;
	case GPIO_PORTK_BASE:
		cbFuncsK[i] = 0;
	case GPIO_PORTL_BASE:
		cbFuncsL[i] = 0;
	case GPIO_PORTM_BASE:
		cbFuncsM[i] = 0;
	case GPIO_PORTN_BASE:
		cbFuncsN[i] = 0;
	case GPIO_PORTP_BASE:
		cbFuncsP[i] = 0;
	case GPIO_PORTQ_BASE:
		cbFuncsQ[i] = 0;
#ifdef TARGET_IS_SNOWFLAKE_RA0
	case GPIO_PORTR_BASE:
		cbFuncsR[i] = 0;
	case GPIO_PORTS_BASE:
		cbFuncsS[i] = 0;
	case GPIO_PORTT_BASE:
		cbFuncsT[i] = 0;
#endif
	}
}
