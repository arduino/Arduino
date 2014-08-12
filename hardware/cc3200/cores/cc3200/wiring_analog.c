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
#include <driverlib/adc.h>
#include <inc/hw_memmap.h>
#include <inc/hw_gprcm.h>
#include <inc/hw_adc.h>

#define TIMER_INTERVAL_RELOAD   40035//255*157
#define DUTYCYCLE_GRANULARITY   157

void PWMWrite(uint8_t pin, uint32_t analog_res, uint32_t duty, uint32_t freq)
{
	analog_res = analog_res * 1000;
	freq;

	uint32_t load = (F_CPU / freq) * 1000;
	uint32_t match = load / (analog_res / duty);

	match = match;
	load = load / 1000;

	uint16_t prescaler = load >> 16;
	uint16_t prescaler_match = match >> 16;

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
	MAP_TimerPrescaleMatchSet(base, timerab, prescaler_match);

	MAP_TimerControlLevel(base, timerab, 1);

	MAP_TimerLoadSet(base, timerab, load);

	MAP_TimerMatchSet(base, timerab, match);

	MAP_TimerEnable(base, timerab);
}

void analogWrite(uint8_t pin, int val) {
	/* duty cycle(%) = val / 255;
	 * Frequency of 490Hz specified by Arduino API */
	uint8_t timer = digitalPinToTimer(pin);

	if(timer == NOT_ON_TIMER)
		return;

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

	PWMWrite(pin, 255, val, 490);
}

uint16_t analogRead(uint8_t pin)
{
	uint16_t channel;

	uint16_t pinNum = digitalPinToPinNum(pin);

	switch(pinNum) {
		case PIN_57: {channel = ADC_CH_0;}break;
		case PIN_58: {channel = ADC_CH_1;}break;
		case PIN_59: {channel = ADC_CH_2;}break;
		case PIN_60: {channel = ADC_CH_3;}break;
		default: return 0;
	}

	PinTypeADC(pinNum,0xFF);
	ADCChannelEnable(ADC_BASE, channel);
	ADCTimerConfig(ADC_BASE,2^17);
	ADCTimerEnable(ADC_BASE);
	ADCEnable(ADC_BASE);

	while(!ADCFIFOLvlGet(ADC_BASE, channel));

	uint16_t val = ADCFIFORead(ADC_BASE, channel) & 0x3FFF;

	ADCDisable(ADC_BASE);
	ADCChannelDisable(ADC_BASE, channel);
	ADCTimerDisable(ADC_BASE);

	val = val >> 2;
	return val;
}
