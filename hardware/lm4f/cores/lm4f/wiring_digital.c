/*
 ************************************************************************
 *	HardwareSerial.cpp
 *
 *	Arduino core files for MSP430
 *		Copyright (c) 2012 Robert Wessels. All right reserved.
 *
 *
 ***********************************************************************
  Derived from:
  wiring_digital.c - digital input and output functions
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

#define ARDUINO_MAIN
#include "wiring_private.h"
#include "driverlib/rom.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#define GPIO_LOCK_KEY_DD        0x4C4F434B 

void pinMode(uint8_t pin, uint8_t mode)
{
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    uint32_t portBase = (uint32_t) portBASERegister(port);
    volatile uint32_t *lock = portLOCKRegister(port);
    volatile uint32_t *cr = portCRRegister(port);
    
    if (port == NOT_A_PORT) return;
    
    if (mode == INPUT) {
        ROM_GPIOPinTypeGPIOInput(portBase, bit);
    } else if (mode == INPUT_PULLUP) {
        *lock = GPIO_LOCK_KEY_DD;
        *cr |= bit;
        *lock = 0;
        ROM_GPIODirModeSet(portBase, bit, GPIO_DIR_MODE_IN);
        ROM_GPIOPadConfigSet(portBase, bit,
                     GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
        *cr &= ~bit;
    } else if (mode == INPUT_PULLDOWN) {
        *lock = GPIO_LOCK_KEY_DD;
        *cr |= bit;
        *lock = 0;
        ROM_GPIODirModeSet(portBase, bit, GPIO_DIR_MODE_IN);
        ROM_GPIOPadConfigSet(portBase, bit,
                     GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);
        *cr &= ~bit;
    } else {//mode == OUTPUT
        ROM_GPIOPinTypeGPIOOutput(portBase, bit);
    }

}

int digitalRead(uint8_t pin)
{
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    uint32_t portBase = (uint32_t) portBASERegister(port);
    if (port == NOT_A_PORT) return LOW;
    if(ROM_GPIOPinRead(portBase, bit)){
    	return HIGH;
    }
    return LOW;
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t mask = val ? bit : 0;
    uint8_t port = digitalPinToPort(pin);
    uint32_t portBase = (uint32_t) portBASERegister(port);
    
    if (port == NOT_A_PORT) return;

    ROM_GPIOPinWrite(portBase, bit, mask);
}
