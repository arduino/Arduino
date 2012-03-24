/*
  ************************************************************************
  *	wiring_analog.c
  *
  *	Arduino core files for MSP430
  *		Copyright (c) 2012 Robert Wessels. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  wiring_analog.c - analog input and output
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
#include "pins_arduino.h"

uint16_t analog_reference = DEFAULT;

void analogReference(uint16_t mode)
{
	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
	analog_reference = mode;
}

/*
 * TODO: make this interrupt based so that we can wait in LPM0
 */
uint16_t analogRead(uint8_t pin)
{

// make sure we have an ADC
	// Pin has ADC functionality?

#if defined(__MSP430_HAS_ADC10__)
	//	0000 A0
	//	0001 A1
	//	0010 A2
	//	0011 A3
	//	0100 A4
	//	0101 A5
	//	0110 A6
	//	0111 A7
	//	1010 Internal temperature sensor

	if(pin > 7 && pin != 10)
		return 0;

	ADC10CTL0 &= ~ENC;
	ADC10CTL0 = analog_reference + ADC10ON + ADC10SHT_2 + ADC10IE;
	ADC10CTL1 = ADC10SSEL_3 + (pin << 12);
	__delay_cycles (128);
	ADC10CTL0 |= ENC + ADC10SC;
	__bis_SR_register(CPUOFF + GIE);	// LPM0 with interrupts enabled
	return ADC10MEM;

#else
	// no ADC
	return 0;
#endif
}

__attribute__((interrupt(ADC10_VECTOR)))
void ADC10_ISR(void)
{
	__bic_SR_register_on_exit(CPUOFF);        // Return to active mode
}
