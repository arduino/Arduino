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
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "inc/hw_memmap.h"

uint16_t analog_res=256;

void analogReference(uint16_t mode)
{
}
void PWMWrite(uint8_t pin, uint16_t analog_res, int duty, unsigned int freq)
{
	//val= duty cycle = 0-510
    uint8_t bit = digitalPinToBitMask(pin); // get pin bit
    uint8_t port = digitalPinToPort(pin);   // get pin port
    uint8_t timer = digitalPinToTimer(pin);
    uint32_t * timerBase;
   	ROM_GPIOPinTypeGPIOOutput(pin, OUTPUT);
	if (duty == 0) {
		digitalWrite(pin, LOW);
	}
	else if (duty >= analog_res) {
		digitalWrite(pin, HIGH);
	}
	else {
		unsigned long periodPWM = ROM_SysCtlClockGet()/freq;
        if (port == NOT_A_PORT) return; 	// pin on timer?
        if(timer >= WTIMER2) {
        	timerBase = TIMER0_BASE + timer_to_offset[timer] - 8;
        }
        else {
        	timerBase = TIMER0_BASE + timer_to_offset[timer];
        }
        if(timer >= WTIMER0) {
            ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_WTIMER0 + timer_to_offset[timer] - 6);
        }
        else {
            ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH2_TIMER0 + timer_to_offset[timer]);
        }

        ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA + port - 1);
        //ROM_GPIOPinConfigure(GPIO_PF0_CCP0);
       	ROM_GPIOPinTypeTimer(timerBase, bit);
       	ROM_TimerConfigure(timerBase, TIMER_CFG_16_BIT_PAIR | (TIMER_CFG_A_PWM << timer_to_ab[timer]));
       	ROM_TimerLoadSet(timerBase, TIMER_A << timer_to_ab[timer], analog_res*periodPWM);
       	ROM_TimerMatchSet(timerBase, TIMER_A << timer_to_ab[timer], (analog_res-duty)*periodPWM);
        ROM_TimerEnable(timerBase, TIMER_A << timer_to_ab[timer]);
    }
}
void analogWrite(uint8_t pin, int val)//val=the duty cycle
{
	PWMWrite(pin, 255, val, 490);
}

uint16_t analogRead(uint8_t pin)
{
	uint8_t port = digitalPinToPort(pin);
	uint16_t value = 0;
	if ((pin < 6) || (pin > 9 && pin < 56)) { //invalid ADC pin
        return 0;
    }

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);

	if(port == PE){
		ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
	}
	else {
		ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
	}

	ROM_GPIOPinTypeADC(portBASERegister(port), digitalPinToGPIOPin(pin));
	ROM_ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);
	ROM_ADCSequenceEnable(ADC0_BASE, 3);
	ROM_ADCIntClear(ADC0_BASE, 3);
    ROM_ADCProcessorTrigger(ADC0_BASE, 3);
    while(!ROM_ADCIntStatus(ADC0_BASE, 3, false))
    {
    }
    ADCIntClear(ADC0_BASE, 3);
    ADCSequenceDataGet(ADC0_BASE, 3, value);
    return value;
}
