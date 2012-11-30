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

#include "wiring_private.h"

#ifndef BV
#define BV(x) (1 << (x))
#endif

#define bit_pos(A) ((A) == 1u << 0 ? 0 \
: (A) == 1u << 1 ? 1 \
: (A) == 1u << 2 ? 2 \
: (A) == 1u << 3 ? 3 \
: (A) == 1u << 4 ? 4 \
: (A) == 1u << 5 ? 5 \
: (A) == 1u << 6 ? 6 \
: (A) == 1u << 7 ? 7 \
: 0)

#define NUM_INTS_PER_PORT 8
static volatile voidFuncPtr intFuncP1[NUM_INTS_PER_PORT];
#if defined(__MSP430_HAS_PORT2_R__)
static volatile voidFuncPtr intFuncP2[NUM_INTS_PER_PORT];
#endif

void attachInterrupt(uint8_t interruptNum, void (*userFunc)(void), int mode) {
 	uint8_t bit = digitalPinToBitMask(interruptNum);
	uint8_t port = digitalPinToPort(interruptNum);
        	
        
        if ((port == NOT_A_PIN) || !((mode == FALLING) || (mode == RISING))) return;
        
        __dint();
        
        switch(port) {
                case P1:
        		P1IE |= bit;
	        	P1IFG &= ~bit;
		        P1IES = mode ? P1IES | bit : P1IES & ~bit;
                        intFuncP1[bit_pos(bit)] = userFunc;
                        break;
                #if defined(__MSP430_HAS_PORT2_R__)
                case P2:
        		P2IE |= bit;
	        	P2IFG &= ~bit;
		        P2IES = mode ? P2IES | bit : P2IES & ~bit;
	                intFuncP2[bit_pos(bit)] = userFunc;
                        break;
                #endif
                default:
                        break;
        }
       
        __eint();
}

void detachInterrupt(uint8_t interruptNum) {
 	uint8_t bit = digitalPinToBitMask(interruptNum);
	uint8_t port = digitalPinToPort(interruptNum);
	
        if (port == NOT_A_PIN) return;
        
        switch(port) {
                case P1:
        		P1IE &= ~bit;
		        intFuncP1[bit_pos(bit)] = 0;
                        break;
                #if defined(__MSP430_HAS_PORT2_R__)
                case P2:
        		P2IE &= ~bit;
		        intFuncP2[bit_pos(bit)] = 0;
                        break;
                #endif
                default:
                        break;
        } 
}


__attribute__((interrupt(PORT1_VECTOR)))
void Port_1(void)
{
	uint8_t i;
	for(i = 0; i < 8; i++) {
		if((P1IFG & BV(i)) && intFuncP1[i]) {
			intFuncP1[i]();
			P1IFG &= ~BV(i);
		}
	}
}

#if defined(__MSP430_HAS_PORT2_R__)
__attribute__((interrupt(PORT2_VECTOR)))
void Port_2(void)
{
	uint8_t i;
	for(i = 0; i < 8; i++) {
		if((P2IFG & BV(i)) && intFuncP2[i]) {
			intFuncP2[i]();
			P2IFG &= ~BV(i);
		}
	}
}
#endif
