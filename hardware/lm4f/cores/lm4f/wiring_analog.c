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
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_timer.h"
#include "inc/hw_ints.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/timer.h"


#define PWM_MODE 0x20A

#ifdef __TM4C1294NCPDT__
uint32_t getTimerBase(uint32_t offset) {
    return (TIMER0_BASE + (offset << 12));
}

uint8_t getTimerInterrupt(uint8_t timer) {
    if(timer < T3CCP0_0) {
        return(INT_TIMER0A + timer);
    }
    else if(timer > T2CCP1_1 || timer < T4CCP0_0) {
        return (INT_TIMER3A + timer - 11);
    }
    else {
        return(INT_TIMER4A + timer - 22);
    }
}
void enableTimerPeriph(uint32_t offset) {
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0 + offset);
}

#else
uint32_t getTimerBase(uint32_t offset) {
    if(offset > WTIMER1) {
        return (WTIMER2_BASE + ((offset - 6) << 12));
    }
    else if(offset < WTIMER0){
        return (TIMER0_BASE + (offset << 12));
    }
    else {
    	return WTIMER0_BASE + ((offset-4) << 12);
    }
}

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
void enableTimerPeriph(uint32_t offset) {
    if(offset > TIMER3) {
        ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0 + offset - 4);
    }
    else {
        ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0 + offset);
    }
}

#endif

//
//empty function due to single reference
//
void analogReference(uint16_t mode) {
}

void PWMWrite(uint8_t pin, uint32_t analog_res, uint32_t duty, unsigned int freq) {
    if (duty == 0) {
    	pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
    }
    else if (duty >= analog_res) {
    	pinMode(pin, OUTPUT);
    	digitalWrite(pin, HIGH);
    }
    else {
        uint8_t bit = digitalPinToBitMask(pin); // get pin bit
        uint8_t port = digitalPinToPort(pin);   // get pin port
        uint8_t timer = digitalPinToTimer(pin);
        uint32_t portBase = (uint32_t) portBASERegister(port);
        uint32_t offset = timerToOffset(timer);
        uint32_t timerBase = getTimerBase(offset);
        uint32_t timerAB = TIMER_A << timerToAB(timer);

        if (port == NOT_A_PORT) return; 	// pin on timer?

#ifdef __TM4C1294NCPDT__
        uint32_t periodPWM = F_CPU/freq;
#else
        uint32_t periodPWM = SysCtlClockGet()/freq;
#endif


        enableTimerPeriph(offset);
        ROM_GPIOPinConfigure(timerToPinConfig(timer));
        ROM_GPIOPinTypeTimer((long unsigned int) portBase, bit);

        //
        // Configure for half-width mode, allowing timers A and B to
        // operate independently
        //
        HWREG(timerBase + TIMER_O_CFG) = 0x04;

        if(timerAB == TIMER_A) {
        	HWREG(timerBase + TIMER_O_CTL) &= ~TIMER_CTL_TAEN;
        	HWREG(timerBase + TIMER_O_TAMR) = PWM_MODE;
        }
        else {
        	HWREG(timerBase + TIMER_O_CTL) &= ~TIMER_CTL_TBEN;
        	HWREG(timerBase + TIMER_O_TBMR) = PWM_MODE;
        }
        ROM_TimerLoadSet(timerBase, timerAB, periodPWM);
        ROM_TimerMatchSet(timerBase, timerAB,
                (analog_res-duty)*periodPWM/analog_res);

        //
        // If using a 16-bit timer, with a periodPWM > 0xFFFF,
        // need to use a prescaler
        //
        if((offset < WTIMER0) && (periodPWM > 0xFFFF)) {
            ROM_TimerPrescaleSet(timerBase, timerAB,
                (periodPWM & 0xFFFF0000) >> 16);
            ROM_TimerPrescaleMatchSet(timerBase, timerAB,
                (((analog_res-duty)*periodPWM/analog_res) & 0xFFFF0000) >> 16);
        }
        ROM_TimerEnable(timerBase, timerAB);
    }
}
void analogWrite(uint8_t pin, int val) {
    //
    //  duty cycle(%) = val / 255;
    //  Frequency of 490Hz specified by Arduino API
    //
    PWMWrite(pin, 255, val, 490);
}

uint16_t analogRead(uint8_t pin) {
    uint8_t port = digitalPinToPort(pin);
    uint16_t value[1];
    uint32_t channel = digitalPinToADCIn(pin);
    if (channel == NOT_ON_ADC) { //invalid ADC pin
        return 0;
    }
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    ROM_GPIOPinTypeADC((uint32_t) portBASERegister(port), digitalPinToBitMask(pin));
    ROM_ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
    ROM_ADCSequenceStepConfigure(ADC0_BASE, 3, 0, channel | ADC_CTL_IE | ADC_CTL_END);
    ROM_ADCSequenceEnable(ADC0_BASE, 3);

    ROM_ADCIntClear(ADC0_BASE, 3);
    ROM_ADCProcessorTrigger(ADC0_BASE, 3);
    while(!ROM_ADCIntStatus(ADC0_BASE, 3, false)) {
    }
	ROM_ADCIntClear(ADC0_BASE, 3);
    ROM_ADCSequenceDataGet(ADC0_BASE, 3, (unsigned long*) value);
    return value[0];
}
