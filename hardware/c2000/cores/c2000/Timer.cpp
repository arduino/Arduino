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
static void initTimers();
static void setTimer(unsigned int frequency, void (*userFunc)(void));
 void stopTimer(uint8_t n);
interrupt void cpu_timer0_isr(void);

// timer clock frequency set to clock/8, at F_CPU = 1MHZ this gives an output freq range of ~[1Hz ..65Khz] and at 16Mhz this is ~[16Hz .. 1MHz]
#define F_TIMER (F_CPU/60L)


#define AVAILABLE_TONE_PINS 2
#define SETARRAY(a) a,a


// tone_duration:
//  > 0 - duration specified
//  = 0 - stopped
//  < 0 - infinitely (until stop() method called, or new play() called)

static uint8_t timer_state = 0; // 0==not initialized, 1==timer running
//static uint16_t tone_interval[AVAILABLE_TONE_PINS] = { SETARRAY(-1)  };
//Above line changed to prevent build warnings
static uint16_t timer_interval = 0; 

static volatile voidFuncPtr intFuncP0;

/**
*** tone() -- Output a tone (50% Dutycycle PWM signal) on a pin
***  pin: This pin is selected as output
***  frequency: [Hertz] 
**   duration: [milliseconds], if duration <=0, then we output tone continously, otherwise tone is stopped after this time (output = 0)
**/
void timer( unsigned int frequency, void (*userFunc)(void))
{


      if ( timer_state == 0 ) 
        initTimers();
      setTimer(frequency, userFunc);
      return; // we are done, timer set

}





// Initialize the timers - Set mode and Enable IRQ
static void inline initTimers()
{
   EALLOW;  // This is needed to write to EALLOW protected registers
   PieVectTable.TINT0 = &cpu_timer0_isr;
   PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
   IER |= M_INT1;
   EDIS;    // This is needed to disable write to EALLOW protected registers


	CpuTimer0Regs.TPR.all  = 0;
	CpuTimer0Regs.TPRH.all = 0;
	CpuTimer0Regs.TCR.bit.TSS = 1;
	CpuTimer0Regs.TCR.bit.TIE = 0;
	//divide by 60 to get 1MHz timer
	CpuTimer0Regs.TPR.bit.TDDR = 59;


  timer_state = 1;  // init is done
}


// Set the timer interval and duration
// frequency in [Hz] and duration in [msec]
// we initialize the timer match value only if the tone was not running already, to prevent glitches when re-programming a running tone
static void setTimer(unsigned int frequency, void (*userFunc)(void))
{
  if ( frequency <= 0 ) 
  {
    return;
  }

  timer_interval = F_TIMER / (2L*frequency);
  

  intFuncP0 = userFunc;

  if ( CpuTimer0Regs.TCR.bit.TIE == 0 )
  {
   	  CpuTimer0Regs.PRD.all =  timer_interval;
  }
  CpuTimer0Regs.TCR.bit.TIE = 1;
  CpuTimer0Regs.TCR.bit.TSS = 0;
  EINT;

} 

/* stopTimer() - Disable timer IRQ */
void inline stopTimer(void)
{

    CpuTimer0Regs.TCR.bit.TSS = 1;
    CpuTimer0Regs.TCR.bit.TIE = 0;
    

}


// Peform the isr magic, toggle output, decrease duation if > 0, and stop if duration == 0, continous if duration < 0
// set new interval - defined as macro to limit ISR overhead (at the expense of some code size)
#define isrTimer(n,ccr) do { \
  *tone_out[n] ^= tone_bit[n]; \
  if ( tone_periods[n] == 0 ) stopTimer(n);\
  else if ( tone_periods[n] > 0) tone_periods[n]--; \
}while(0)


interrupt void cpu_timer0_isr(void)
{
    intFuncP0();
    PieCtrlRegs.PIEACK.bit.ACK1  = 1;
}


