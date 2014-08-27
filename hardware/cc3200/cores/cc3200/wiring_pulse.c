/*
 ************************************************************************
 *	wiring_pulse.c
 *
 *	Energia core files for MSP430
 *		Copyright (c) 2012 Robert Wessels. All right reserved.
 *
 *
 ***********************************************************************
  Derived from:
  wiring_pulse.c - pulseIn() function
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
#include "pins_energia.h"
#include "driverlib/rom_map.h"

/* Measures the length (in microseconds) of a pulse on the pin; state is HIGH
 * or LOW, the type of pulse to measure.  Works on pulses from 2-3 microseconds
 * to 3 minutes in length, but must be called at least a few dozen microseconds
 * before the start of the pulse. */
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout)
{
    // cache the port and bit of the pin in order to speed up the
    // pulse width measuring loop and achieve finer resolution.  calling
    // digitalRead() instead yields much coarser resolution.
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    uint32_t portBase = (uint32_t) portBASERegister(port);
	uint8_t stateMask = (state ? bit : 0);

    // convert the timeout from microseconds to a number of times through
    // the initial loop; it takes 11 clock cycles per iteration.
    unsigned long numloops = 0;
    unsigned long maxloops = microsecondsToClockCycles(timeout) / 11;

    // wait for any previous pulse to end
    while (MAP_GPIOPinRead(portBase, bit) == stateMask)
        if (numloops++ == maxloops)
            return 0;

    // wait for the pulse to start
    while (MAP_GPIOPinRead(portBase, bit) != stateMask)
        if (numloops++ == maxloops)
            return 0;

    // wait for the pulse to stop
    unsigned long start = micros();

    while (MAP_GPIOPinRead(portBase, bit) == stateMask) {
        if (numloops++ == maxloops)
            return 0;
    }
    unsigned long end = micros();
    unsigned long result = end - start;
    return(result);
    // convert the reading to microseconds. The loop has been determined
    // to be 13 clock cycles long and have about 11 clocks between the edge
    // and the start of the loop. There will be some error introduced by
    // the interrupt handlers.
    //return clockCyclesToMicroseconds(width * 13 + 11);
}
