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

#if defined(__MSP430_HAS_ADC10__) && !defined(ADC10ENC)
#define ADC10ENC ENC 
#endif
#if defined(__MSP430_HAS_ADC10__) && !defined(ADC10MEM0)
#define ADC10MEM0 ADC10MEM 
#endif
#if defined(__MSP430_HAS_ADC10_B__)
#define REFV_MASK 0x70
#define REF_MASK 0x31;
#endif

#if defined(__MSP430_HAS_ADC10__) || defined(__MSP430_HAS_ADC10_B__)
uint16_t analog_reference = DEFAULT; 


void analogReference(uint16_t mode)
{
	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
	analog_reference = mode;
}
#endif

uint16_t analog_period = F_CPU/490, analog_div = 0, analog_res=255; // devide clock with 0, 2, 4, 8

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
	else if (val == analog_res)
	{
		digitalWrite(pin, HIGH); // set pin HIGH when duty cycle is 255
                                         // digitalWrite will take care of invalid pins
	}
	else
	{

	        uint8_t bit = digitalPinToBitMask(pin); // get pin bit
	        uint8_t port = digitalPinToPort(pin);   // get pin port
	        volatile uint8_t *sel;
                
                if (port == NOT_A_PORT) return; // pin on timer?
               
	        sel = portSelRegister(port); // get the port function select register address
		*sel |= bit;                 // set bit in pin function select register  

                switch(digitalPinToTimer(pin)) {                // which timer and CCR?
 			//case: T0A0                            // CCR0 used as period register
			case T0A1:                              // TimerA0 / CCR1
                                TA0CCR0 = PWM_PERIOD;           // PWM Period
                                TA0CCTL1 = OUTMOD_7;            // reset/set
                                TA0CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TA0CTL = TASSEL_2 + MC_1 + analog_div;       // SMCLK, up mode
                                break;
#if defined(__MSP430_HAS_TA3__) || defined(__MSP430_HAS_T0A3__) 
 			case T0A2:                              // TimerA0 / CCR2
                                TA0CCR0 = PWM_PERIOD;           // PWM Period
                                TA0CCTL2 = OUTMOD_7;            // reset/set
                                TA0CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TA0CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
#if defined(__MSP430_HAS_T1A3__) 
 			//case: T1A0                            // CCR0 used as period register
			case T1A1:                              // TimerA1 / CCR1
                                TA1CCR0 = PWM_PERIOD;           // PWM Period
                                TA1CCTL1 = OUTMOD_7;            // reset/set
                                TA1CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TA1CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
 			case T1A2:                              // TimerA1 / CCR2
                                TA1CCR0 = PWM_PERIOD;           // PWM Period
                                TA1CCTL2 = OUTMOD_7;            // reset/set
                                TA1CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TA1CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
#if defined(__MSP430_HAS_T2A3__)  
 			//case: T2A0                            // CCR0 used as period register
			case T2A1:                              // TimerA2 / CCR1
                                TA2CCR0 = PWM_PERIOD;           // PWM Period
                                TA2CCTL1 = OUTMOD_7;            // reset/set
                                TA2CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TA2CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
 			case T2A2:                              // TimerA2 / CCR2
                                TA2CCR0 = PWM_PERIOD;           // PWM Period
                                TA2CCTL2 = OUTMOD_7;            // reset/set
                                TA2CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TA2CTL = TASSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
#if defined(__MSP430_HAS_T0B3__) 
 			//case: T0B0                            // CCR0 used as period register
 			case T0B1:                              // TimerB0 / CCR1
                                TB0CCR0 = PWM_PERIOD;           // PWM Period
                                TB0CCTL1 = OUTMOD_7;            // reset/set
                                TB0CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TB0CTL = TBSSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
 			case T0B2:                              // TimerB0 / CCR1
                                TB0CCR0 = PWM_PERIOD;           // PWM Period
                                TB0CCTL2 = OUTMOD_7;            // reset/set
                                TB0CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TB0CTL = TBSSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
#if defined(__MSP430_HAS_T1B3__) 
 			//case: T1B0                            // CCR0 used as period register
 			case T1B1:                              // TimerB0 / CCR1
                                TB1CCR0 = PWM_PERIOD;           // PWM Period
                                TB1CCTL1 = OUTMOD_7;            // reset/set
                                TB1CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TB1CTL = TBSSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
 			case T1B2:                              // TimerB0 / CCR1
                                TB1CCR0 = PWM_PERIOD;           // PWM Period
                                TB1CCTL2 = OUTMOD_7;            // reset/set
                                TB1CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TB1CTL = TBSSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
#if defined(__MSP430_HAS_T2B3__) 
 			//case: T1B0                            // CCR0 used as period register
 			case T2B1:                              // TimerB0 / CCR1
                                TB2CCR0 = PWM_PERIOD;           // PWM Period
                                TB2CCTL1 = OUTMOD_7;            // reset/set
                                TB2CCR1 = PWM_DUTY(val);       // PWM duty cycle
                                TB2CTL = TBSSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
 			case T2B2:                              // TimerB0 / CCR1
                                TB2CCR0 = PWM_PERIOD;           // PWM Period
                                TB2CCTL2 = OUTMOD_7;            // reset/set
                                TB2CCR2 = PWM_DUTY(val);       // PWM duty cycle
                                TB2CTL = TBSSEL_2 + MC_1+ analog_div;       // SMCLK, up mode
                                break;
#endif
 
                        case NOT_ON_TIMER:                      // not on a timer output pin
			default:                                // or TxA0 pin
				if (val <= (analog_res >> 1)) {
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
#if defined(__MSP430_HAS_ADC10__) || defined(__MSP430_HAS_ADC10_B__)
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

    ADC10CTL0 &= ~ADC10ENC;                 // disable ADC
    ADC10CTL1 = ADC10SSEL_0 | ADC10DIV_5;   // ADC10OSC as ADC10CLK (~5MHz) / 5
#if defined(__MSP430_HAS_ADC10__)
    ADC10CTL0 = analog_reference |          // set analog reference
            ADC10ON | ADC10SHT_3 | ADC10IE; // turn ADC ON; sample + hold @ 64 × ADC10CLKs; Enable interrupts
    ADC10CTL1 |= (pin << 12);               // select channel
    ADC10AE0 = (1 << pin);                  // Disable input/output buffer on pin
#endif
#if defined(__MSP430_HAS_ADC10_B__)
    while(REFCTL0 & REFGENBUSY);            // If ref generator busy, WAIT
    REFCTL0 |= analog_reference & REF_MASK; // Set reference using masking off the SREF bits. See Energia.h.
    ADC10MCTL0 = pin | (analog_reference & REFV_MASK); // set channel and reference 
    ADC10CTL0 = ADC10ON | ADC10SHT_4;       // turn ADC ON; sample + hold @ 64 × ADC10CLKs
    ADC10CTL1 |= ADC10SHP;                  // ADCCLK = MODOSC; sampling timer
    ADC10CTL2 |= ADC10RES;                  // 10-bit resolution
    ADC10IFG = 0;                           // Clear Flags
    ADC10IE |= ADC10IE0;                    // Enable interrupts
#endif
    __delay_cycles(128);                    // Delay to allow Ref to settle
    ADC10CTL0 |= ADC10ENC | ADC10SC;        // enable ADC and start conversion
    while (ADC10CTL1 & ADC10BUSY) {         // sleep and wait for completion
        __bis_SR_register(CPUOFF + GIE);    // LPM0 with interrupts enabled
    }

#if defined(__MSP430_HAS_ADC10__)
    /* POWER: Turn ADC and reference voltage off to conserve power */
    ADC10CTL0 &= ~(ADC10ON | REFON);
#endif

#if defined(__MSP430_HAS_ADC10_B__)
    /* POWER: Turn ADC and reference voltage off to conserve power */
    ADC10CTL0 &= ~(ADC10ON);
    REFCTL0 &= ~REFON;
#endif
    return ADC10MEM0;  // return sampled value after returning to active mode in ADC10_ISR
#else
    // no ADC
    return 0;
#endif
}

#if defined(__MSP430_HAS_ADC10__) || defined(__MSP430_HAS_ADC10_B__)

__attribute__((interrupt(ADC10_VECTOR)))
void ADC10_ISR(void)
{
#if defined(__MSP430_HAS_ADC10)
    __bic_SR_register_on_exit(CPUOFF);        // return to active mode
#endif

#if defined(__MSP430_HAS_ADC10_B__)

    switch(ADC10IV,12) {
        case  0: break;                          // No interrupt
        case  2: break;                          // conversion result overflow
        case  4: break;                          // conversion time overflow
        case  6: break;                          // ADC10HI
        case  8: break;                          // ADC10LO
        case 10: break;                          // ADC10IN
        case 12:
                 __bic_SR_register_on_exit(CPUOFF);        // return to active mode
                 break;                          // Clear CPUOFF bit from 0(SR)                         
        default: break;
    }

    ADC10IFG = 0;                           // Clear Flags
#endif
}

#endif