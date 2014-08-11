/* Tone.cpp

  A Tone Generator Library - Modified for Energia
  Implements up to 3 (software) PWM outputs using TIMERA0 compare registers and IRQ. 
  Can use any digital output pin for pulse generation

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
*/

#include "wiring_private.h"
#include <driverlib/prcm.h>
#include <driverlib/rom_map.h>
#include <driverlib/pin.h>
#include <driverlib/timer.h>
#include <inc/hw_memmap.h>
#include <inc/hw_gprcm.h>


// tone_duration:
//  > 0 - duration specified
//  = 0 - stopped
//  < 0 - infinitely (until stop() method called, or new play() called)

static uint8_t tone_state = 0; // 0==not initialized, 1==timer running
static uint8_t current_pin = 0;
static long g_duration = 0;
static uint8_t tone_timer = 0;

void
ToneIntHandler(void)
{
/*
    ROM_TimerIntClear(TIMER4_BASE, TIMER_A);

    //End of tone duration
    if(--g_duration <= 0) {
        	noTone(current_pin);
    		ROM_TimerIntDisable(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
    		ROM_TimerIntClear(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
    		ROM_TimerDisable(TIMER4_BASE, TIMER_A);
    }
*/
}

/**
 *** tone() -- Output a tone (50% Dutycycle PWM signal) on a pin
 ***  pin: This pin is selected as output
 ***  frequency: [Hz]
 **   duration: [milliseconds], if duration <=0, then we output tone continuously,
 **   otherwise tone is stopped after this time (output = 0)
 **/

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
/*
    uint8_t port = digitalPinToPort(_pin);
    if (port == NOT_A_PORT) return;
    if (tone_state == 0 || _pin == current_pin) {

    	//Setup PWM
    	current_pin = _pin;
        tone_timer = digitalPinToTimer(_pin);
        tone_state = 1;
        g_duration = duration;
//        PWMWrite(_pin, 256, 128, frequency);

        //Setup interrupts for duration, interrupting at 1kHz
        ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER4);
        ROM_IntMasterEnable();
        ROM_TimerConfigure(TIMER4_BASE, TIMER_CFG_PERIODIC);
        ROM_TimerLoadSet(TIMER4_BASE, TIMER_A, F_CPU/1000);
        ROM_IntEnable(INT_TIMER4A);
        ROM_TimerIntEnable(TIMER4_BASE, TIMER_TIMA_TIMEOUT);
        ROM_TimerEnable(TIMER4_BASE, TIMER_A);
    }
*/
}

#define TIMER_INTERVAL_RELOAD   40035//255*157
#define DUTYCYCLE_GRANULARITY   157
void PWMWrite(uint8_t pin, uint32_t analog_res, uint32_t duty, unsigned int freq)
{
	uint8_t prescaler = (F_CPU / freq) / 0xFFFF;
	uint32_t granularity = ceil(((F_CPU >> prescaler) / freq) / analog_res);
	uint32_t reload = analog_res * granularity;

	Serial.println(prescaler);
	Serial.print("pre:");
	Serial.println(prescaler);
	Serial.print("gran:");
	Serial.println(granularity);
	Serial.print("reload:");
	Serial.println(reload);
	Serial.print("match:");
	Serial.println(duty * granularity);
	Serial.println("===============");

	if (duty == 0) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, LOW);
		return;
	}

	if (duty >= 255) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, HIGH);
		return;
	}

	uint8_t timer = digitalPinToTimer(pin);

	if(timer == NOT_ON_TIMER)
		return;

	MAP_PRCMPeripheralClkEnable(PRCM_TIMERA0 + (timer/2), PRCM_RUN_MODE_CLK);

	uint16_t pnum = digitalPinToPinNum(pin);

	switch(timer) {
	/* PWM0/1 */
	case TIMERA0A:
	case TIMERA0B:
		MAP_PinTypeTimer(pnum, PIN_MODE_5);
		break;
 	/* PWM2/3 */
	case TIMERA1A:
	case TIMERA1B:
		MAP_PinTypeTimer(pnum, PIN_MODE_9);
		break;
	/* PWM4/5 */
	case TIMERA2A:
	case TIMERA2B:
		MAP_PinTypeTimer(pnum, PIN_MODE_3);
		break;
	/* PWM6/7 */
	case TIMERA3A:
	case TIMERA3B:
		MAP_PinTypeTimer(pnum, PIN_MODE_3);
		break;
	}

	uint32_t base = TIMERA0_BASE + ((timer/2) << 12);

	/* FIXME: If B is already opperational and configure A, B get's messed up. */
	MAP_TimerConfigure(base, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM | TIMER_CFG_B_PWM);

	uint16_t timerab = timer % 2 ? TIMER_B : TIMER_A;
	MAP_TimerPrescaleSet(base, timerab, prescaler);

	MAP_TimerControlLevel(base, timerab, 1);

	MAP_TimerLoadSet(base, timerab, reload);

	MAP_TimerMatchSet(base, timerab, (duty * granularity));

	MAP_TimerEnable(base, timerab);
}

void tone(uint8_t _pin, unsigned int frequency)
{
/*
    uint8_t port = digitalPinToPort(_pin);

    if (port == NOT_A_PORT) return;

    if(tone_state == 0 || _pin == current_pin) {
        tone_timer = digitalPinToTimer(_pin);
        PWMWrite(_pin, 256, 128, frequency);
        tone_state = 1;
    }
*/
}

/*
 * noTone() - Stop outputting the tone on a pin
 */
void noTone(uint8_t _pin)
{
/*
	uint8_t timer = digitalPinToTimer(_pin);

    if(timer == tone_timer) {
		uint32_t timerBase = getTimerBase(timerToOffset(timer));
		uint32_t timerAB = TIMER_A << timerToAB(timer);
		ROM_TimerIntDisable(timerBase, TIMER_TIMA_TIMEOUT << timerToAB(tone_timer));
		ROM_TimerIntClear(timerBase, TIMER_TIMA_TIMEOUT << timerToAB(tone_timer));
		ROM_TimerDisable(timerBase, timerAB);
		tone_state = 0;
		g_duration = 0;
		pinMode(_pin, OUTPUT);
		digitalWrite(_pin, LOW);
    }
*/
}


