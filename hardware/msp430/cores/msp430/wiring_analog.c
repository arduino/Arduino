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

//TODO: Can be a lot more efficient.
//      - lower clock rated / input divider to conserve Energia.
//      - pin configuration logic.
//Arduino specifies ~490 Hz for analog out PWM so we follow suit.
#define PWM_PERIOD F_CPU/490
#define PWM_DUTY PWM_PERIOD / 255
void analogWrite(uint8_t pin, int val)
{
        pinMode(pin, OUTPUT); // pin as output

 	if (val == 0)
	{
		digitalWrite(pin, LOW); // set pin to LOW when duty cycle is 0
                                        // digitalWrite will take care of invalid pins
	}
	else if (val == 255)
	{
		digitalWrite(pin, HIGH); // set pin HIGH when duty cycle is 255
                                         // digitalWrite will take care of invalid pins
	}
	else
	{

	        uint8_t bit = digitalPinToBitMask(pin); // get pin bit
	        uint8_t port = digitalPinToPort(pin);   // get pin port
	        volatile uint16_t *sel;
	        volatile uint16_t *sel2;
                
                if (port == NOT_A_PORT) return; // pin on timer?
               
	        sel = portSelRegister(port); // get the port function select register address
		*sel |= bit;                 // set bit in pin function select register  
                
                //TODO: Firgure out a way to determine if SEL2 needs to be set
	        //reg2 = portSel2Register(port); // get the port function select register address
                
                switch(digitalPinToTimer(pin)) {                // which timer and CCR?
 			//case: T0A0                            // CCR0 used as period register
			case T0A1:                              // Timer0 / CCR1
                                TA0CCR0 = PWM_PERIOD;           // PWM Period
                                TA0CCTL1 = OUTMOD_7;            // reset/set
                                TA0CCR1 = PWM_DUTY * val;       // PWM duty cycle
                                TA0CTL = TASSEL_2 + MC_1;       // SMCLK, up mode
                                break;
 			case T0A2:                              // Timer0 / CCR1
                                TA0CCR0 = PWM_PERIOD;           // PWM Period
                                TA0CCTL2 = OUTMOD_7;            // reset/set
                                TA0CCR2 = PWM_DUTY * val;       // PWM duty cycle
                                TA0CTL = TASSEL_2 + MC_1;       // SMCLK, up mode
                                break;
#if defined(__MSP430_HAS_T1A3__) 
                        case T1A0:
                        case T1A1:
                        case T1A2:
#endif
#if defined(__MSP430_HAS_T2A3__) 
                        case T2A0:
                        case T2A1:
                        case T2A2:
#endif
                        case NOT_ON_TIMER:
			default:
				if (val < 128) {
					digitalWrite(pin, LOW);
				} else {
					digitalWrite(pin, HIGH);
				}
                }
        }
}

uint16_t analogRead(uint8_t pin)
{

// make sure we have an ADC
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

        // Pin has ADC functionality?
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
