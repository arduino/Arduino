/*
 ************************************************************************
 *	wiring_digital.cpp
 *
 *	Energia core files for cc3200
 *		Copyright (c) 2014 Robert Wessels. All right reserved.
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
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pin.h"
#define GPIO_LOCK_KEY_DD        0x4C4F434B 

void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	if (port == NOT_A_PORT) return;

	uint32_t portBase = (uint32_t) portBASERegister(port);
	uint16_t pinNum = digitalPinToPinNum(pin);

	MAP_PinTypeGPIO(pinNum, PIN_MODE_0, false);

	if (mode == INPUT) {
		MAP_GPIODirModeSet(portBase, bit, GPIO_DIR_MODE_IN);
	} else if (mode == INPUT_PULLUP) {
		MAP_GPIODirModeSet(portBase, bit, GPIO_DIR_MODE_IN);
		MAP_PinConfigSet(pinNum, PIN_STRENGTH_2MA, PIN_TYPE_STD_PU);
	} else if (mode == INPUT_PULLDOWN) {
		MAP_GPIODirModeSet(portBase, bit, GPIO_DIR_MODE_IN);
		MAP_PinConfigSet(pinNum, PIN_STRENGTH_2MA, PIN_TYPE_STD_PD);
	} else {//mode == OUTPUT
		MAP_GPIODirModeSet(portBase, bit, GPIO_DIR_MODE_OUT);
	}
}

int digitalRead(uint8_t pin)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	uint32_t portBase = (uint32_t) portBASERegister(port);

	if (port == NOT_A_PORT) return LOW;

	if(MAP_GPIOPinRead(portBase, bit)){
		return HIGH;
	}

	return LOW;
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t mask = val ? bit : 0;
	uint8_t port = digitalPinToPort(pin);

	if (port == NOT_A_PORT) return;

	uint32_t portBase = (uint32_t) portBASERegister(port);

	MAP_GPIOPinWrite(portBase, bit, mask);
}
