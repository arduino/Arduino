/*
 ************************************************************************
 *	wiring_analog.c
 *
 *	Energia core files for MSP430
 *	Copyright (c) 2014 Robert Wessels. All right reserved.
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
#include <driverlib/prcm.h>
#include <driverlib/rom_map.h>
#include <driverlib/pin.h>
#include <driverlib/timer.h>
#include <inc/hw_memmap.h>

#define TIMER_INTERVAL_RELOAD   40035//255*157
#define DUTYCYCLE_GRANULARITY   157

void analogWrite(uint8_t pin, int val) {
	/* duty cycle(%) = val / 255;
	 * Frequency of 490Hz specified by Arduino API */

	if (val == 0) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, LOW);
		return;
	}

	if (val >= 255) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, HIGH);
		return;
	}

	uint8_t timer = digitalPinToTimer(pin);

	if(timer == NOT_ON_TIMER)
		return;

	MAP_PRCMPeripheralClkEnable(PRCM_TIMERA0 + (timer/2), PRCM_RUN_MODE_CLK);

	uint16_t pnum = digitalPinToPinNum(pin);
	MAP_PinTypeTimer(pnum, PIN_MODE_3);

	uint32_t base = TIMERA0_BASE + ((timer/2) << 12);
	MAP_TimerConfigure(base, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM | TIMER_CFG_B_PWM);

	uint16_t timerab = timer % 2 ? TIMER_B : TIMER_A;
	MAP_TimerPrescaleSet(base, timerab, 0);

	MAP_TimerControlLevel(base, timerab, 1);

	MAP_TimerLoadSet(base, timerab, TIMER_INTERVAL_RELOAD);

	MAP_TimerMatchSet(base, timerab, (val * DUTYCYCLE_GRANULARITY));

	MAP_TimerEnable(base, timerab);
}
