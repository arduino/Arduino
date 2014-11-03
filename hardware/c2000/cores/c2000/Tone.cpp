/*
  *************************************************************************
  *	tone.c
  *
  *	Energia core files for C2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
  *
  ***********************************************************************

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
static void initToneTimers();
static void setTimer(uint8_t n, unsigned int frequency, unsigned long duration);
static void stopTimer(uint8_t n);
interrupt void cpu_timer1_isr(void);
interrupt void cpu_timer2_isr(void);

// timer clock frequency set to clock/8, at F_CPU = 1MHZ this gives an output freq range of ~[1Hz ..65Khz] and at 16Mhz this is ~[16Hz .. 1MHz]
#define F_TIMER (F_CPU/60L)


#define AVAILABLE_TONE_PINS 2
#define SETARRAY(a) a,a


// tone_duration:
//  > 0 - duration specified
//  = 0 - stopped
//  < 0 - infinitely (until stop() method called, or new play() called)

static uint8_t tone_state = 0; // 0==not initialized, 1==timer running
static uint8_t tone_pins[AVAILABLE_TONE_PINS] = { SETARRAY(255) };
static uint8_t tone_bit[AVAILABLE_TONE_PINS] = { SETARRAY(255)  };
volatile static uint32_t *tone_out[AVAILABLE_TONE_PINS] = { SETARRAY(0) };
//static uint16_t tone_interval[AVAILABLE_TONE_PINS] = { SETARRAY(-1)  };
//Above line changed to prevent build warnings
static uint16_t tone_interval[AVAILABLE_TONE_PINS] = { (uint16_t)-1, (uint16_t)-1  };
static int16_t tone_periods[AVAILABLE_TONE_PINS] = { SETARRAY(0)  };


/**
*** tone() -- Output a tone (50% Dutycycle PWM signal) on a pin
***  pin: This pin is selected as output
***  frequency: [Hertz] 
**   duration: [milliseconds], if duration <=0, then we output tone continously, otherwise tone is stopped after this time (output = 0)
**/
void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
  uint16_t gpio_number = pin_mapping[_pin];
  uint8_t port = digitalPinToPort(gpio_number);
  if (port == NOT_A_PORT) return;

  // find if we are using it at the moment, if so: update it
  for (int i = 0; i < AVAILABLE_TONE_PINS; i++)
  {
    if (tone_pins[i] == gpio_number) 
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
      tone_pins[i] = gpio_number;
      tone_bit[i] = digitalPinToBitMask(gpio_number);
      tone_out[i] = portOutputRegister(port);
      if ( tone_state == 0 ) 
        initToneTimers();
      pinMode(gpio_number, OUTPUT);
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
  uint16_t gpio_number = pin_mapping[_pin];
  if ( gpio_number == 255 ) return; // Should not happen!
  for (int i = 0; i < AVAILABLE_TONE_PINS; i++)
  {
    if (tone_pins[i] == gpio_number) 
    {
      tone_pins[i] = 255;
      stopTimer(i);
    }
  }
}


// Initialize the timers - Set mode and Enable IRQ
static void inline initToneTimers()
{
   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.TINT1 = &cpu_timer1_isr;
   PieVectTable.TINT2 = &cpu_timer2_isr;
   IER |= M_INT13;
   IER |= M_INT14;
   EDIS;    // This is needed to disable write to EALLOW protected registers


	CpuTimer1Regs.TPR.all  = 0;
	CpuTimer1Regs.TPRH.all = 0;
	CpuTimer1Regs.TCR.bit.TSS = 1;
	CpuTimer1Regs.TCR.bit.TIE = 0;
	//divide by 60 to get 1MHz timer
	CpuTimer1Regs.TPR.bit.TDDR = 59;
	CpuTimer2Regs.TPR.all  = 0;
	CpuTimer2Regs.TPRH.all = 0;
	CpuTimer2Regs.TCR.bit.TSS = 1;
	CpuTimer2Regs.TCR.bit.TIE = 0;
	CpuTimer2Regs.TPR.bit.TDDR = 59;

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
      if ( CpuTimer1Regs.TCR.bit.TIE == 0 ){
    	  CpuTimer1Regs.PRD.all =  tone_interval[0];
      }
  	  CpuTimer1Regs.TCR.bit.TIE = 1;
  	  CpuTimer1Regs.TCR.bit.TSS = 0;
      break;
    case 1:
        if ( CpuTimer2Regs.TCR.bit.TIE == 0 ){
      	    CpuTimer2Regs.PRD.all =  tone_interval[1];
        }
    	CpuTimer2Regs.TCR.bit.TIE = 1;
    	CpuTimer2Regs.TCR.bit.TSS = 0;
      break;
    }
} 

/* stopTimer() - Disable timer IRQ */
static void inline stopTimer(uint8_t n)
{
  switch( n )
  {
    case 0:
    	CpuTimer1Regs.TCR.bit.TSS = 1;
    	CpuTimer1Regs.TCR.bit.TIE = 0;
    	break;
    case 1:
    	CpuTimer2Regs.TCR.bit.TSS = 1;
    	CpuTimer2Regs.TCR.bit.TIE = 0;
    	break;
  }
  *tone_out[n] &= ~tone_bit[n];
}


// Peform the isr magic, toggle output, decrease duation if > 0, and stop if duration == 0, continous if duration < 0
// set new interval - defined as macro to limit ISR overhead (at the expense of some code size)
#define isrTimer(n,ccr) do { \
  *tone_out[n] ^= tone_bit[n]; \
  if ( tone_periods[n] == 0 ) stopTimer(n);\
  else if ( tone_periods[n] > 0) tone_periods[n]--; \
}while(0)


interrupt void cpu_timer1_isr(void)
{
	isrTimer(0, CpuTimer1Regs.PRD.all);
}

interrupt void cpu_timer2_isr(void)
{
	isrTimer(1, CpuTimer2Regs.PRD.all);
}
