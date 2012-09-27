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
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/timer.h"

// tone_duration:
//  > 0 - duration specified
//  = 0 - stopped
//  < 0 - infinitely (until stop() method called, or new play() called)

static uint8_t tone_state = 0; // 0==not initialized, 1==timer running
static uint8_t current_pin = 0;
static long g_duration = 0;
static uint8_t tone_timer = 0;

uint8_t getTimerInterrupt(uint8_t timer) {

    if(timer < T3A) {
        return(INT_TIMER0A + timer);
    }
    else if(timer == T3A || timer == T3B){
        return (INT_TIMER3A + timer - 11);
    }
    else {
        return(INT_TIMER4A + timer - 13);
    }

}

uint32_t getTimerBase(uint8_t timer) {

    if(timer >= WT0A) {
        return (TIMER0_BASE + timerToOffset(timer) - 8);
    }
    else {
        return (TIMER0_BASE + timerToOffset(timer));
    }

}

void
ToneIntHandler(void)
{
    uint32_t timerBase = getTimerBase(tone_timer);
    ROM_TimerIntClear(timerBase, TIMER_TIMA_TIMEOUT << timerToAB(tone_timer));
    if(g_duration >= 0) {
        if(--g_duration == 0){
            ROM_IntDisable(getTimerInterrupt(tone_timer));
            ROM_TimerIntDisable(tone_timer,TIMER_TIMA_TIMEOUT << timerToAB(tone_timer));
            ROM_TimerIntClear(tone_timer,TIMER_TIMA_TIMEOUT << timerToAB(tone_timer));
            tone_state = 0;
        }
    }
}

/**
 *** tone() -- Output a tone (50% Dutycycle PWM signal) on a pin
 ***  pin: This pin is selected as output
 ***  frequency: [Hz]
 **   duration: [milliseconds], if duration <=0, then we output tone continously, otherwise tone is stopped after this time (output = 0)
 **/

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
    uint8_t port = digitalPinToPort(_pin);
    if (port == NOT_A_PORT) return;
    if (tone_state == 0 || _pin == current_pin) {
        tone_timer = digitalPinToTimer(_pin);
        uint32_t timerBase = getTimerBase(tone_timer);;
        ROM_IntMasterEnable();
        ROM_IntEnable(getTimerInterrupt(tone_timer));
        ROM_TimerIntEnable(timerBase, TIMER_TIMA_TIMEOUT << timerToAB(tone_timer));
        PWMWrite(_pin, 256, 128, frequency);
        tone_state = 1;
        g_duration = duration*ROM_SysCtlClockGet()/1000;
    }
}

void tone(uint8_t _pin, unsigned int frequency)
{
    uint8_t port = digitalPinToPort(_pin);
    if (port == NOT_A_PORT) return;
    if(tone_state == 0 || _pin == current_pin) {
        tone_timer = digitalPinToTimer(_pin);
        uint32_t timerBase = getTimerBase(tone_timer);
        ROM_IntMasterEnable();
        ROM_IntEnable(getTimerInterrupt(tone_timer));
        ROM_TimerIntEnable(timerBase, TIMER_TIMA_TIMEOUT << timerToAB(tone_timer));
        PWMWrite(_pin, 256, 128, frequency);
        tone_state = 1;
        g_duration = -1;
    }
}

/*
 * noTone() - Stop outputting the tone on a pin
 */
void noTone(uint8_t _pin)
{
    uint8_t timer = digitalPinToTimer(_pin);
    uint32_t timerBase = getTimerBase(timer);
    ROM_TimerIntDisable(timerBase,TIMER_TIMA_TIMEOUT << timerToAB(timer));
    ROM_TimerIntClear(timerBase,TIMER_TIMA_TIMEOUT << timerToAB(timer));
    tone_state = 0;
    g_duration = 0;
}
