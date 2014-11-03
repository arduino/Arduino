/*
  ************************************************************************
  *	WInterrupts.c
  *
  *	Arduino core files for C2000
  *		Copyright (c) 2012 Trey German. All right reserved.
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

#define AVAILABLE_EXT_INTS 3


static volatile voidFuncPtr intFuncP1;
static volatile voidFuncPtr intFuncP2;
static volatile voidFuncPtr intFuncP3;

static uint8_t extInts[AVAILABLE_EXT_INTS] = {255, 255, 255};


interrupt void Port_1(void)
{
	intFuncP1();
	PieCtrlRegs.PIEACK.bit.ACK1  = 1;
}


interrupt void Port_2(void)
{
	intFuncP2();
	PieCtrlRegs.PIEACK.bit.ACK1  = 1;
}

interrupt void Port_3(void)
{
	intFuncP3();
	PieCtrlRegs.PIEACK.bit.ACK12  = 1;
}



void attachInterrupt(uint8_t pin, void (*userFunc)(void), int mode) {
    uint16_t gpio_number = pin_mapping[pin];
 	uint32_t bit = digitalPinToPort(gpio_number);
    int i;    	
        
        if (bit == NOT_A_PIN) return;
        
        DINT;
        EALLOW;

        for(i = 0; i < AVAILABLE_EXT_INTS; i++)
        {
            if(extInts[i] == 255)
            {
                extInts[i] = gpio_number;
                i++;
                switch(i) {
                    case 1:
                    	PieVectTable.XINT1 = Port_1;
                    	PieCtrlRegs.PIEIER1.bit.INTx4 = 1;
                    	IER |= M_INT1;
                    	GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = gpio_number;
                    	XIntruptRegs.XINT1CR.bit.POLARITY = mode;
				    	intFuncP1 = userFunc;
                    	XIntruptRegs.XINT1CR.bit.ENABLE = 1;
				    	break;
                    case 2:
                    	PieVectTable.XINT2 = Port_2;
                    	PieCtrlRegs.PIEIER1.bit.INTx5 = 1;
                    	IER |= M_INT1;
                    	GpioIntRegs.GPIOXINT2SEL.bit.GPIOSEL = gpio_number;
                    	XIntruptRegs.XINT2CR.bit.POLARITY = mode;
				    	intFuncP2 = userFunc;
                    	XIntruptRegs.XINT2CR.bit.ENABLE = 1;
				    	break;
                    case 3:
                    	PieVectTable.XINT3 = Port_3;
                    	PieCtrlRegs.PIEIER12.bit.INTx1 = 1;
                    	IER |= M_INT12;
                    	GpioIntRegs.GPIOXINT3SEL.bit.GPIOSEL = gpio_number;
                    	XIntruptRegs.XINT3CR.bit.POLARITY = mode;
				    	intFuncP3 = userFunc;
                    	XIntruptRegs.XINT3CR.bit.ENABLE = 1;
				    	break;
                    default:
                        break;
                }
            }


        }

       EDIS;
       EINT;
}

void detachInterrupt(uint8_t pin) {
     uint16_t gpio_number = pin_mapping[pin];
    int i;    
    for(i = 0; i < AVAILABLE_EXT_INTS; i++)
    {
        if(extInts[i] == gpio_number)
        {
            extInts[i] = 255;
            i++;
            switch(i) {
                case 1:
                	XIntruptRegs.XINT1CR.bit.ENABLE = 0;
					intFuncP1 = rsvd_ISR;
					break;
                case 2:
                	XIntruptRegs.XINT2CR.bit.ENABLE = 0;
					intFuncP2 = rsvd_ISR;
					break;
                case 3:
                	XIntruptRegs.XINT3CR.bit.ENABLE = 0;
					intFuncP3 = rsvd_ISR;
					break;
                default:
                        break;
            }

        }

    }

}
