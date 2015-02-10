/*
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

  $Id: wiring.c 248 2007-02-03 15:36:30Z mellis $
*/

#define ARDUINO_MAIN
#include "wiring_private.h"
#include "pins_arduino.h"

// Defined in WInterrupts.c
extern uint8_t getBitFromBitField(uint8_t input);

void pinMode(uint8_t pin, uint8_t mode)
{
	
	uint8_t bitmask = digitalPinToBitMask(pin);
	uint8_t bit = getBitFromBitField(bitmask);
	uint8_t portIndex = digitalPinToPort(pin);
	volatile PORT_t *port;

	if (portIndex == NOT_A_PIN) return;

	// JWS: can I let the optimizer do this?
	port = portRegister(portIndex);
	uint8_t* pinctrl = (uint8_t*)&port->PIN0CTRL;

	uint8_t oldSREG = SREG;
	cli();

	if (mode == INPUT) {
		port->DIRCLR = bitmask;
		pinctrl[bit] &= ~PORT_OPC_gm; // Reset all pullups on that pin
	} else if (mode == INPUT_PULLDOWN){
		port->DIRCLR = bitmask;
		pinctrl[bit] |= PORT_OPC_PULLDOWN_gc;
	} else if (mode == INPUT_PULLUP){
		port->DIRCLR = bitmask;
		pinctrl[bit] |= PORT_OPC_PULLUP_gc;
	} else {
		port->DIRSET = bitmask;
		pinctrl[bit] &= ~PORT_OPC_gm; // Reset all pullups on that pin
	}

	SREG = oldSREG;
}

// Forcing this inline keeps the callers from having to push their own stuff
// on the stack. It is a good performance win and only takes 1 more byte per
// user than calling. (It will take more bytes on the 168/328p/xmega.)
//
// But shouldn't this be moved into pinMode? Seems silly to check and do on
// each digitalread or write.
//
static inline void turnOffPWM(uint8_t timer) __attribute__ ((always_inline));
static inline void turnOffPWM(uint8_t timer)
{
	TC0_t*  tc0 = (TC0_t*)timerToTC0(timer);
	TC1_t*  tc1 = (TC1_t*)timerToTC1(timer);
#if defined(TCC2) || defined(TCD2)
	TC2_t*  tc2 = (TC2_t*)timerToTC2(timer);
#endif
        uint8_t channel = timerToChannel(timer);

        if ( tc0 ) {
        	tc0->CTRLB &= ~(TC0_CCAEN_bm << channel);
        } else if ( tc1 ) {
        	tc1->CTRLB &= ~(TC1_CCAEN_bm << channel);
        } 
#if defined(TCC2) || defined(TCD2)
	else if ( tc2 ) {
		tc2->CTRLB &= ~(1 << channel);
	}
#endif
}

void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t bitmask = digitalPinToBitMask(pin);
        uint8_t bit = getBitFromBitField(bitmask);
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t portIndex = digitalPinToPort(pin);
	volatile PORT_t *port;

	if (portIndex == NOT_A_PIN) return;

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	port = portRegister(portIndex);
	uint8_t* pinctrl = (uint8_t*)&port->PIN0CTRL;

	uint8_t oldSREG = SREG;
	cli();

	if((port->DIR & bitmask) == 0) //if the pin is an input pit, change the pullup resistor instead of the input value
	{
		if (val == LOW) {
                        pinctrl[bit] &= ~PORT_OPC_PULLUP_gc;
                } else {
                        pinctrl[bit] |= PORT_OPC_PULLUP_gc;
                }
	}
	else
	{
		if (val == LOW) {
			port->OUTCLR = bitmask;
		} else {
			port->OUTSET = bitmask;
		}
	}

	SREG = oldSREG;
}

int digitalRead(uint8_t pin)
{
	
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t portIndex = digitalPinToPort(pin);

	if (portIndex == NOT_A_PIN) return LOW;

	// If the pin that support PWM output, we need to turn it off
	// before getting a digital reading.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	if (portRegister(portIndex)->IN & bit) return HIGH;
	return LOW;
}
