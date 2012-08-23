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
#include "pins_energia.h"

uint16_t analog_reference = DEFAULT, analog_period = F_CPU/490, analog_div = 0, analog_res=255; // devide clock with 0, 2, 4, 8

void analogReference(uint16_t mode)
{
	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
	analog_reference = mode;
}

//TODO: Can be a lot more efficiant.
//      - lower clock rated / input devider to conserve Energia.
//      - pin configuration logic.

// Note set frequency before sending analog value
// Lowest fequency is defined by clock frequency F_CPU, and max counter value 2^16-1
// fmin = F_CPU / 2^16
void analogFrequency(uint32_t freq)
{
  if ( freq <= F_CPU/(4*65334L) ) { analog_div = ID_3; freq *=8; }  
  else if ( freq <= F_CPU/(2*65334L) ) { analog_div = ID_2; freq *=4; }
  else if ( freq <= F_CPU/(4*65334L) ) { analog_div = ID_1; freq *=2; }
  analog_period = F_CPU/freq;
}

// Set the resulution (nr of counts for 100%), default = 255, large values may not work at all frequencies
void analogResolution(uint16_t res)
{
  analog_res = res;
}

//Arduino specifies ~490 Hz for analog out PWM so we follow suit.
#define PWM_PERIOD analog_period // F_CPU/490
#define PWM_DUTY(x) ( (unsigned long)x*PWM_PERIOD / (unsigned long)analog_res )
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
               
	        sel = portAFSelRegister(port); // get the port function select register address
		*sel |= bit;                 // set bit in pin function select register  
                
                //TODO: Firgure out a better way to determine if SEL2 needs to be set
	           /*if(bit == BV(4) && port == P1) {
                        sel2 = portSel2Register(port); // get the port function select register address
                        *sel2 |= bit;
                }*/
                switch(digitalPinToTimer(pin)) {                // which timer and CCR?
 			//case: T0A0                            // CCR0 used as period register
			case T0A1:                              // Timer0 / CCR1
                                TA0CCR0 = PWM_PERIOD;           // PWM Period
                                TA0CCTL1 = OUTMOD_7;            // reset/set
                                TA0CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TA0CTL = TASSEL_2 + MC_1 + analog_div;       // SMCLK, up mode
                                break;
#if defined(__MSP430_HAS_TA3__) 
 			case T0A2:                              // Timer0 / CCR1
                                TA0CCR0 = PWM_PERIOD;           // PWM Period
                                TA0CCTL2 = OUTMOD_7;            // reset/set
                                TA0CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TA0CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
#if defined(__MSP430_HAS_T1A3__) 
 			//case: T1A0                            // CCR0 used as period register
			case T1A1:                              // Timer0 / CCR1
                                TA1CCR0 = PWM_PERIOD;           // PWM Period
                                TA1CCTL1 = OUTMOD_7;            // reset/set
                                TA1CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TA1CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
 			case T1A2:                              // Timer0 / CCR1
                                TA1CCR0 = PWM_PERIOD;           // PWM Period
                                TA1CCTL2 = OUTMOD_7;            // reset/set
                                TA1CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TA1CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
#if defined(__MSP430_HAS_T2A3__)  
 			//case: T2A0                            // CCR0 used as period register
			case T2A1:                              // Timer0 / CCR1
                                TA2CCR0 = PWM_PERIOD;           // PWM Period
                                TA2CCTL1 = OUTMOD_7;            // reset/set
                                TA2CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TA2CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
 			case T2A2:                              // Timer0 / CCR1
                                TA2CCR0 = PWM_PERIOD;           // PWM Period
                                TA2CCTL2 = OUTMOD_7;            // reset/set
                                TA2CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TA2CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
                        case NOT_ON_TIMER:                      // not on a timer output pin
			default:                                // or TxA0 pin
				if (val < 128) {
					digitalWrite(pin, LOW); // 
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
    //  0000 A0
    //  0001 A1
    //  0010 A2
    //  0011 A3
    //  0100 A4
    //  0101 A5
    //  0110 A6
    //  0111 A7
    //  1010 Internal temperature sensor

    //TODO: Only int. temp. sensor requires Tsample > 30us.
    // The below ADC configuration applies this rule to all channels right now.
    // ADC10CLK = 5MHz / 5 = 1Mhz
    // Tsample = S&H / ADC10CLK = 64 / 1 MHz = 64 us
    // Tconvert = 13 / ADC10CLK = 13 / 1 MHz = 13 us
    // Total time per sample = Tconvert + Tsample = 64 + 13 = 67 us = ~15k samples / sec
    if (pin > 7 && pin != 10) {             // Is this a valid ADC pin?
        return 0;
    }

    ADC10CTL0 &= ~ENC;                      // disable ADC
    ADC10CTL0 = analog_reference |          // set analog reference
            ADC10ON | ADC10SHT_3 | ADC10IE; // turn ADC ON; sample + hold @ 64 × ADC10CLKs; Enable interrupts
    ADC10CTL1 = ADC10SSEL_0 | ADC10DIV_5 |  // ADC10OSC as ADC10CLK (~5MHz) / 5
            (pin << 12);                    // select channel
    __delay_cycles(128);                    // Delay to allow Ref to settle
    ADC10CTL0 |= ENC | ADC10SC;             // enable ADC and start conversion
    while (ADC10CTL1 & ADC10BUSY) {         // sleep and wait for completion
        __bis_SR_register(CPUOFF + GIE);    // LPM0 with interrupts enabled
    }

    return ADC10MEM;             // return sampled value after returning to active mode in ADC10_ISR
#else
    // no ADC
    return 0;
#endif
}

__attribute__((interrupt(ADC10_VECTOR)))
void ADC10_ISR(void)
{
	__bic_SR_register_on_exit(CPUOFF);        // return to active mode
}
