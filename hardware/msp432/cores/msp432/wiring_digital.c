/*
 ************************************************************************
 *  wiring_digital.cpp
 *
 *  Energia core files for cc3200
 *      Copyright (c) 2014 Robert Wessels. All right reserved.
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

#include "wiring_private.h"
#include "GPIO2.h"

/* device specific routine */
GPIO2_PinConfig mode2gpioConfig(uint8_t mode)
{
   switch (mode) {
        case INPUT:
        case INPUT_PULLUP:
            return (GPIO2_INPUT_PULLUP);

        case INPUT_PULLDOWN:
            return (GPIO2_INPUT_PULLDOWN);

        case OUTPUT:
            return (GPIO2_OUTPUT_HIGH_STRENGTH);
    }

    /* unknown mode */
    return (GPIO2_DO_NOT_CONFIG);
}

void pinMode(uint8_t pin, uint8_t mode)
{
    GPIO2_PinConfig gpioConfig = mode2gpioConfig(mode);

    if (gpioConfig != GPIO2_DO_NOT_CONFIG) {
        digital_pin_to_pin_function[pin] = mode;
        GPIO2_setConfig(pin, gpioConfig);
    }
}

int digitalRead(uint8_t pin)
{
    if (digital_pin_to_pin_function[pin] == OUTPUT) {
        pinMode(pin, INPUT);
    }

    if (GPIO2_read(pin)) {
        return (HIGH);
    }

    return (LOW);
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    if (digital_pin_to_pin_function[pin] != OUTPUT) {
        pinMode(pin, OUTPUT);
    }

    GPIO2_write(pin, val ? 0xff : 0);
}
