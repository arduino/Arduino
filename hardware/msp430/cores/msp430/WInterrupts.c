/* -*- mode: jde; c-basic-offset: 2; indent-tabs-mode: nil -*- */

/*
  Part of the Wiring project - http://wiring.uniandes.edu.co

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

#include "wiring_private.h"
//TODO: Revisit. Is this the right way to do this? Only allowing int on P1.[0-7]

#ifndef BV
#define BV(x) (1 << (x))
#endif

static volatile voidFuncPtr intFunc[EXTERNAL_NUM_INTERRUPTS];

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
	if(interruptNum <= EXTERNAL_NUM_INTERRUPTS) {
		intFunc[interruptNum] = userFunc;
		P1IE |= BV(interruptNum);
		P1IFG &= ~BV(interruptNum);
		P1IES |= mode;
	}
}

void detachInterrupt(uint8_t interruptNum) {
	if(interruptNum < EXTERNAL_NUM_INTERRUPTS) {
		intFunc[interruptNum] = 0;
	}
}


__attribute__((interrupt(PORT1_VECTOR)))
void Port_1(void)
{
	uint8_t i;
	for(i = 0; i < 7; i++) {
		if((P1IFG & BV(i)) && intFunc[i]) {
			intFunc[i]();
			P1IFG &= ~BV(i);
		}
	}
}
