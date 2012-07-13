/* Tone.cpp

  A Tone Generator Library - Modified for Energia
  Implements up to 3 (software) PWM outputs using TIMERA0 compare registers and IRQ. 
  Can use any digital output pin for pulse generation
 
  (c) 2012 - Peter Brier.

  Based on code Originally written by Brett Hagman

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

Version Modified By Date     Comments
------- ----------- -------- --------
0001    B Hagman    09/08/02 Initial coding
0002    B Hagman    09/08/18 Multiple pins
0003    B Hagman    09/08/18 Moved initialization from constructor to begin()
0004    B Hagman    09/09/26 Fixed problems with ATmega8
0005    B Hagman    09/11/23 Scanned prescalars for best fit on 8 bit timers
                    09/11/25 Changed pin toggle method to XOR
                    09/11/25 Fixed timer0 from being excluded
0006    D Mellis    09/12/29 Replaced objects with functions
0007    M Sproul    10/08/29 Changed #ifdefs from cpu to register
0008    P Brier     12/05/28 Modified for TI MSP430 processor
0009    P Brier     12/05/29 Fixed problem with re-init of expired tone
*************************************************/

#include "wiring_private.h"
#include "pins_energia.h"
#include "Energia.h"

// local funcions
static void initTimers();
static void setTimer(uint8_t n, unsigned int frequency, unsigned long duration);
static void stopTimer(uint8_t n);

// timer clock frequency set to clock/8, at F_CPU = 1MHZ this gives an output freq range of ~[1Hz ..65Khz] and at 16Mhz this is ~[16Hz .. 1MHz]
#define F_TIMER (F_CPU/8L)

#ifdef __MSP430_HAS_TA3__
#define AVAILABLE_TONE_PINS 3
#define SETARRAY(a) a,a,a
#else
#define AVAILABLE_TONE_PINS 2
#define SETARRAY(a) a,a
#endif


// tone_duration:
//  > 0 - duration specified
//  = 0 - stopped
//  < 0 - infinitely (until stop() method called, or new play() called)

static uint8_t tone_state = 0; // 0==not initialized, 1==timer running
static uint8_t tone_pins[AVAILABLE_TONE_PINS] = { SETARRAY(255) };
static uint8_t tone_bit[AVAILABLE_TONE_PINS] = { SETARRAY(255)  };
volatile static uint8_t *tone_out[AVAILABLE_TONE_PINS] = { SETARRAY(0) };
static uint16_t tone_interval[AVAILABLE_TONE_PINS] = { SETARRAY(-1)  };
static int16_t tone_periods[AVAILABLE_TONE_PINS] = { SETARRAY(0)  };


/**
*** tone() -- Output a tone (50% Dutycycle PWM signal) on a pin
***  pin: This pin is selected as output
***  frequency: [Hertz] 
**   duration: [milliseconds], if duration <=0, then we output tone continously, otherwise tone is stopped after this time (output = 0)
**/
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
  uint8_t port = digitalPinToPort(_pin);
  if (port == NOT_A_PORT) return;

  // find if we are using it at the moment, if so: update it
  for (int i = 0; i < AVAILABLE_TONE_PINS; i++)
  {
    if (tone_pins[i] == _pin) 
    {
      setTimer(i, frequency, duration);
      return; // we are done, timer reprogrammed
    }
  }

  // new tone pin, find empty timer and set it
  for (int i = 0; i < AVAILABLE_TONE_PINS; i++)
  {
    if (tone_pins[i] == 255)      
    {
      tone_pins[i] = _pin;
      tone_bit[i] = digitalPinToBitMask(_pin);
      tone_out[i] = portOutputRegister(port); 
      if ( tone_state == 0 ) 
        initTimers();
      pinMode(_pin, OUTPUT);
      setTimer(i, frequency, duration);
      return; // we are done, timer set
    }
  }
  // if we exit here, no unused timer was found, nothing is done
}


/**
*** noTone() - Stop outputting the tone on a pin
**/
void noTone(uint8_t _pin)
{
  if ( _pin == 255 ) return; // Should not happen!
  for (int i = 0; i < AVAILABLE_TONE_PINS; i++)
  {
    if (tone_pins[i] == _pin) 
    {
      tone_pins[i] = 255;
      stopTimer(i);
    }
  }
}


// Initialize the timers - Set mode and Enable IRQ
static void inline initTimers()
{
  // disable IRQs
  TA0CCTL0 = 0;
  TA0CCTL1 = 0;
#ifdef __MSP430_HAS_TA3__
  TA0CCTL2 = 0;
#endif
  TA0CTL = TACLR + TASSEL_2 +  ID_3 + MC_2;       // clear counter, source=SMCLK/8, mode=continous count up
  tone_state = 1;  // init is done
}


// Set the timer interval and duration
// frequency in [Hz] and duration in [msec]
// we initialize the timer match value only if the tone was not running already, to prevent glitches when re-programming a running tone
static void setTimer(uint8_t n, unsigned int frequency, unsigned long duration)
{
  if ( frequency <= 0 ) 
  {
    tone_interval[n] = 0;
    tone_periods[n] = 0;
    return;
  }
  tone_interval[n] = F_TIMER / (2L*frequency);
  if ( duration > 0 )
    tone_periods[n] = (duration * (F_TIMER/2)) / (1000L * tone_interval[n]);
  else
    tone_periods[n] = -1;
  switch( n ) // enable IRQ and set next match time in various timer compare registers (if we where not enabled already)
  {
    case 0:
      if ( ! (TA0CCTL0 & CCIE) ) TA0CCR0 = TA0R + tone_interval[0];  
      TA0CCTL0 = CCIE;       
      break;
    case 1:
      if ( !(TA0CCTL1 & CCIE) ) TA0CCR1 = TA0R + tone_interval[1]; 
      TA0CCTL1 = CCIE; 
      break;
#ifdef __MSP430_HAS_TA3__
    case 2:
      if ( !(TA0CCTL2 & CCIE) ) TA0CCR2 = TA0R + tone_interval[2];  
      TA0CCTL2 = CCIE;
      break;
#endif
    }
} 

/* stopTimer() - Disable timer IRQ */
static void inline stopTimer(uint8_t n)
{
  switch( n )
  {
    case 0: TA0CCTL0 = 0; break;
    case 1: TA0CCTL1 = 0; break;
#ifdef __MSP430_HAS_TA3__
    case 2: TA0CCTL2 = 0; break;
#endif
  }  
  *tone_out[n] &= ~tone_bit[n];
}


// Peform the isr magic, toggle output, decrease duation if > 0, and stop if duration == 0, continous if duration < 0
// set new interval - defined as macro to limit ISR overhead (at the expense of some code size)
#define isrTimer(n,ccr) do { \
  *tone_out[n] ^= tone_bit[n]; \
  if ( tone_periods[n] == 0 ) stopTimer(n);\
  else if ( tone_periods[n] > 0) tone_periods[n]--; \
  ccr += tone_interval[n]; \
} while(0)


// TIMERA vector (CCR0)
__attribute__((interrupt(TIMER0_A0_VECTOR)))
void TIMER0_A0_ISR(void)
{
  isrTimer(0, TA0CCR0);
}

// TAIV vector (CCR1/CCR2)
__attribute__((interrupt(TIMER0_A1_VECTOR)))
void TIMER0_A1_ISR(void)
{
  switch ( TA0IV ) 
  { 
    case 0x2: isrTimer(1, TA0CCR1); break; // CCR1
#ifdef __MSP430_HAS_TA3__
    case 0x4: isrTimer(2, TA0CCR2); break; // CCR2
#endif
  }  
}
