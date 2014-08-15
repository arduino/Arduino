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
#include "inc/hw_timer.h"

static uint8_t tone_state = 0;
static uint8_t current_pin = 0;
static long g_duration = 0;
static uint8_t tone_timer = 0;

void ToneIntHandler(void)
{
	MAP_TimerIntClear(TIMERA0_BASE, TIMER_B);

	if(--g_duration <= 0) {
		MAP_TimerIntDisable(TIMERA0_BASE, TIMER_TIMB_TIMEOUT);
		MAP_TimerDisable(TIMERA0_BASE, TIMER_B);
		noTone(current_pin);
	}
}

void tone(uint8_t pin, unsigned int frequency, unsigned long duration)
{
	/* Use TIMERA0B since it is not on any pin */

	tone_timer = digitalPinToTimer(pin);

	if(tone_timer == NOT_ON_TIMER)
		return;

	if(tone_state != 0 && pin != current_pin)
		return;

	g_duration = duration;
	current_pin = pin;
	tone_state = 2;

	MAP_PRCMPeripheralClkEnable(PRCM_TIMERA0, PRCM_RUN_MODE_CLK);
	MAP_PRCMPeripheralReset(PRCM_TIMERA0);
	MAP_TimerConfigure(TIMERA0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_B_PERIODIC);
	MAP_TimerIntRegister(TIMERA0_BASE, TIMER_B, ToneIntHandler);
	MAP_TimerIntEnable(TIMERA0_BASE, TIMER_TIMB_TIMEOUT);
	MAP_TimerPrescaleSet(TIMERA0_BASE, TIMER_B, 7);
	MAP_TimerLoadSet(TIMERA0_BASE, TIMER_B, (F_CPU / 8) / 1000);
	MAP_TimerEnable(TIMERA0_BASE, TIMER_B);

	PWMWrite(pin, 256, 128, frequency);
}

void tone(uint8_t pin, unsigned int frequency)
{
	tone_timer = digitalPinToTimer(pin);

	if(tone_timer == NOT_ON_TIMER)
		return;

	if(tone_state == 0 || pin == current_pin) {
		PWMWrite(pin, 255, 128, frequency);
		tone_state = 1;
		current_pin = pin;
	}
}

void noTone(uint8_t pin)
{
	uint8_t timer = digitalPinToTimer(pin);
	if(timer != tone_timer || timer == NOT_ON_TIMER)
		return;

	/* For whatever reason disabling a not enabled
	 * interrupt lands us in the FalutIsr.
	 * Work around is to check if the timer is running */
	if(tone_state == 2) {
		MAP_TimerIntDisable(TIMERA0_BASE, TIMER_TIMB_TIMEOUT);
		MAP_TimerDisable(TIMERA0_BASE, TIMER_B);
	}

	uint32_t base = TIMERA0_BASE + ((timer/2) << 12);
	uint16_t timerab = timer % 2 ? TIMER_B : TIMER_A;
	MAP_TimerDisable(base, timerab);

	tone_state = 0;
	current_pin = 0;
	g_duration = 0;

	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}
