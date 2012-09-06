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
#include "pins_energia.h"

void pinMode(uint8_t pin, uint8_t mode)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	volatile uint32_t *cr;
	volatile uint32_t *dir;
	//volatile uint32_t *ren;
	//volatile uint32_t *out;
	volatile uint32_t *pur;
	volatile uint32_t *pdr;

	if (port == NOT_A_PORT) return;
	cr = portCRRegister(port);
	dir = portDIRRegister(port);
	//ren = portRenRegister(port);
	//out = portOutputRegister(port);
	pur = portPURRegister(port);
	pdr = portPDRRegister(port);


	if (mode == INPUT) {
		*dir &= ~bit;
	} else if (mode == INPUT_PULLUP) {
		*cr |= bit;
		*dir &= ~bit;
        *pur |= bit;
        *cr &= ~bit;
    } else if (mode == INPUT_PULLDOWN) {
		*cr |= bit;
      	*dir &= ~bit;
        *pdr |= bit;
        *cr &= ~bit;
    } else {//mode == OUTPUT
		*dir |= bit;
	}

}

int digitalRead(uint8_t pin)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	if (port == NOT_A_PORT) return LOW;

	return GPIOPinRead(port, bit);

}

void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint32_t *out;
	volatile uint32_t *sel;

	if (port == NOT_A_PORT) return;

	ROM_GPIOPinTypeGPIOOutput(port, bit);
	GPIOPinWrite(port, bit, val);

}
