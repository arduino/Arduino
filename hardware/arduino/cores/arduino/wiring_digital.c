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

  Modified 28 September 2010 by Mark Sproul

  $Id: wiring.c 248 2007-02-03 15:36:30Z mellis $
*/

#define ARDUINO_MAIN
#include "wiring_private.h"
#include "pin_functions.h"

// This are versions that call back into, where the pin isn't known
// at compile-time.

const uint16_t port_to_mode_P[] = { PORT_TO_MODE };
const uint16_t PROGMEM port_to_output_P[] = { PORT_TO_OUTPUT };
const uint16_t PROGMEM port_to_input_P[] = { PORT_TO_INPUT };
const uint8_t PROGMEM digital_pin_to_port_P[] = { DIGITAL_PIN_TO_PORT };
const uint8_t PROGMEM digital_pin_to_bit_mask_P[] = { DIGITAL_PIN_TO_BIT_MASK };
const uint8_t PROGMEM digital_pin_to_timer_P[] = { DIGITAL_PIN_TO_TIMER };

void _pinModeRuntime(uint8_t pin, uint8_t mode)
{
  _pinModeInline(pin, mode);
}

void _digitalWriteRuntime(uint8_t pin, uint8_t val)
{
  _digitalWriteInline(pin, val);
}

int _digitalReadRuntime(uint8_t pin)
{
  return _digitalReadInline(pin);
}

void _turnOffPWMRuntime(uint8_t pin)
{
  _turnOffPWMInline(pin);
}

