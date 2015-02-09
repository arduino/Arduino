/*
 ************************************************************************
 *  WInterrupts.c
 *
 *  Arduino core files for TI-RTOS
 *      Copyright (c) 2013 Louis Peryea. All right reserved.
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
  Modified for MSP430 by Robert Wessels
 */


#include "Energia.h"
#include "ti/drivers/GPIO.h"

extern GPIO_Config GPIO_config[];
extern GPIO_HWAttrs gpioHWAttrs[];

//extern GPIO_Callbacks Board_gpioCallbacks0;
//extern GPIO_Callbacks Board_gpioCallbacks1;
//extern GPIO_Callbacks Board_gpioCallbacks2;
//extern GPIO_Callbacks Board_gpioCallbacks3;

static GPIO_Callbacks *gpioCallbacks[4] =
{
//    &Board_gpioCallbacks0,
//    &Board_gpioCallbacks1,
//    &Board_gpioCallbacks2,
//    &Board_gpioCallbacks3
};

void Wiring_GPIO_hwiIntFxn(UArg callbacks)
{
    uint32_t        pins;
    unsigned int    i;
    GPIO_Callbacks *portCallback;

    portCallback = (GPIO_Callbacks*)callbacks;

    /* Find out which pins have their interrupt flags set */
//    pins = GPIOIntStatus(portCallback->port, 0xFF) & 0xFF;

    /* Match the interrupt to its corresponding callback function */
    for (i = 0; pins; i++) {
        if (pins & 0x1) {
//            GPIOIntClear(portCallback->port, (1 << i));
            if (portCallback->callbackFxn[i] != NULL) {
                portCallback->callbackFxn[i]();
            }
        }
        pins = pins >> 1;
    }
}

void interrupts(void)
{
    Hwi_enable();
}

void noInterrupts(void)
{
    Hwi_disable();
}

void attachInterrupt(uint8_t pin, void (*userFunc)(void), int mode)
{
    volatile uint32_t portBase;
    GPIO_IntType intType;
    uint8_t bitNum, bitMask, i;

    uint8_t hwAttrIndex = digital_pin_to_hwAttrs_index[pin];

    if (hwAttrIndex == NOT_A_PORT) return;

    portBase = (uint32_t) gpioHWAttrs[hwAttrIndex].port;

    i = bitMask = digitalPinToBitMask(pin);

    bitNum = 0;

    while (i >>= 1) {
        bitNum++;
    }

    for (i = 0; i < 4; i++) {
        if (portBase == gpioCallbacks[i]->port) {
            gpioCallbacks[i]->callbackFxn[bitNum] = userFunc;
        }
    }

    switch(mode) {
    case LOW:
        intType = GPIO_INT_LOW;
        break;
    case CHANGE:
        intType = GPIO_INT_BOTH_EDGES;
        break;
    case RISING:
        intType = GPIO_INT_RISING;
        break;
    case FALLING:
        intType = GPIO_INT_FALLING;
        break;
    default:
        intType = GPIO_INT_RISING;
        break;
    }

    GPIOIntTypeSet(portBase, bitMask, intType);
    GPIOIntClear(portBase, bitMask);
    GPIOIntEnable(portBase, bitMask);
}

void detachInterrupt(uint8_t pin) {
    uint8_t bitMask, bitNum, i;
    volatile uint32_t portBase;
    i = bitMask = digitalPinToBitMask(pin);
    portBase = digitalPinToPortBase(pin);
    GPIOIntClear(portBase, bitMask);
    GPIOIntDisable(portBase, bitMask);

    while (i >>= 1) {
        bitNum++;
    }

    for (i = 0; i < 4; i++) {
        if (portBase == gpioCallbacks[i]->port) {
            gpioCallbacks[i]->callbackFxn[bitNum] = 0;
        }
    }
}
