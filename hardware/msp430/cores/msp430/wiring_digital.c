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

	volatile uint8_t *dir;
	volatile uint8_t *ren;
	volatile uint8_t *out;

	if (port == NOT_A_PORT) return;

	dir = portDirRegister(port);
	ren = portRenRegister(port);
	out = portOutputRegister(port);

	if (mode == INPUT) {
		*dir &= ~bit;
	} else if (mode == INPUT_PULLUP) {
		*dir &= ~bit;
                *out |= bit;
                *ren |= bit;
        } else if (mode == INPUT_PULLDOWN) {
		*dir &= ~bit;
                *out &= ~bit;
                *ren |= bit;
        } else {
		*dir |= bit;
	}
}

void pinMode_int(uint8_t pin, uint8_t mode)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	volatile uint8_t *dir;
	volatile uint8_t *ren;
	volatile uint8_t *out;
	volatile uint8_t *sel;

	if (port == NOT_A_PORT) return;

	dir = portDirRegister(port);
	ren = portRenRegister(port);
	out = portOutputRegister(port);

	if (mode & OUTPUT) {
		*dir |= bit;
	} else {
		*dir &= ~bit;
		if (mode & INPUT_PULLUP) {
                *out |= bit;
                *ren |= bit;
        } else if (mode & INPUT_PULLDOWN) {
                *out &= ~bit;
                *ren |= bit;
        }
	}

	#if (defined(P1SEL_) || defined(P1SEL))
	sel = portSel0Register(port);	/* get the port function select register address */
	if (mode & PORT_SELECTION0) {
		*sel |= bit;
    } else {
		*sel &= ~bit;
	}
	#if (defined(P1SEL2_) || defined(P1SEL2))
	sel = portSel2Register(port);	/* get the port function select register address */
	if (mode & PORT_SELECTION1) {
		*sel |= bit;
    } else {
		*sel &= ~bit;
	}
	#endif
	#endif
	
	#if (defined(P1SEL0_) || defined(P1SEL0))
	sel = portSel0Register(port);	/* get the port function select register address */
	if (mode & PORT_SELECTION0) {
		*sel |= bit;
    } else {
		*sel &= ~bit;
	}
	#if (defined(P1SEL1_) || defined(P1SEL1))
	sel = portSel1Register(port);	/* get the port function select register address */
	if (mode & PORT_SELECTION1) {
		*sel |= bit;
    } else {
		*sel &= ~bit;
	}
	#endif
	#endif

}

int digitalRead(uint8_t pin)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);

	if (port == NOT_A_PORT) return LOW;

	if (*portInputRegister(port) & bit) return HIGH;
	return LOW;
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *out;
	volatile uint8_t *sel;

	if (port == NOT_A_PORT) return;

	/*
	 * Clear bit in PxSEL register to select GPIO function. Other functions like analogWrite(...) 
	 * will set this bit so need to clear it.
	 */
	#if (defined(P1SEL_) || defined(P1SEL))
	sel = portSel0Register(port);	/* get the port function select register address */
	*sel &= ~bit;			/* clear bit in pin function select register */
	#if (defined(P1SEL2_) || defined(P1SEL2))
	sel = portSel2Register(port);	/* get the port function select register address */
	*sel &= ~bit;			/* clear bit in pin function select register */
	#endif
	#endif
	
	#if (defined(P1SEL0_) || defined(P1SEL0))
	sel = portSel0Register(port);	/* get the port function select register address */
	*sel &= ~bit;			/* clear bit in pin function select register */
	#if (defined(P1SEL1_) || defined(P1SEL1))
	sel = portSel1Register(port);	/* get the port function select register address */
	*sel &= ~bit;			/* clear bit in pin function select register */
	#endif
	#endif
	
	
	out = portOutputRegister(port);

	if (val == LOW) {
		*out &= ~bit;
	} else {
		*out |= bit;
	}
}
