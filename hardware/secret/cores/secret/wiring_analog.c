/*
 ************************************************************************
 *  wiring_analog.c
 *
 *  Energia core files for MSP430
 *  Copyright (c) 2014 Robert Wessels. All right reserved.
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
#define ARDUINO_MAIN
#include "wiring_private.h"
#include <driverlib/prcm.h>
#include <driverlib/rom_map.h>
#include <driverlib/pin.h>
#include <driverlib/timer.h>
#include <driverlib/adc.h>
#include <inc/hw_memmap.h>

extern PWM_Config PWM_config[];

static int8_t analogReadShift = 4;

void analogWrite(uint8_t pin, int val) 
{
    uint8_t timer = digitalPinToTimer(pin);

    if (timer == NOT_ON_TIMER) {
        return;
    }

    /* re-configure pin if necessary */
    if (digital_pin_to_pin_function[pin] != PIN_FUNC_UNUSED &&
             digital_pin_to_pin_function[pin] != PIN_FUNC_ANALOG_OUTPUT) {
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

        digital_pin_to_pin_function[pin] = PIN_FUNC_ANALOG_OUTPUT;
    }

    PWM_setDuty((PWM_Handle)&(PWM_config[timer]), (val * 640));
}

/*
 * \brief           Reads an analog value from the pin specified.
 * \param[in] pin   The pin number to read from.
 * \return          A 16-bit integer containing a 12-bit sample from the ADC.
 */
uint16_t analogRead(uint8_t pin)
{
    uint32_t channel = digitalPinToADCIn(pin);

    if (channel == NOT_ON_ADC) { // invalid ADC pin
        return (0);
    }

    /* re-configure pin if necessary */
    if (digital_pin_to_pin_function[pin] != PIN_FUNC_ANALOG_INPUT) {
        // Pinmux the pin to be analog
        MAP_PinTypeADC(digitalPinToPinNum(pin),0xff);

        // Enable the channel
        MAP_ADCChannelEnable(ADC_BASE, channel);

        // Enable ADC module
        MAP_ADCEnable(ADC_BASE);

        digital_pin_to_pin_function[pin] = PIN_FUNC_ANALOG_INPUT;
    }

    // Get the sample
    uint16_t sample = 0;
    while (true){
        if (MAP_ADCFIFOLvlGet(ADC_BASE, channel)) {
            sample = (MAP_ADCFIFORead(ADC_BASE, channel) & 0x3ffc) >> analogReadShift;
            break;
        }
    }

    // Disable ADC module to save power
    MAP_ADCDisable(ADC_BASE);

    // Disable the channel
    MAP_ADCChannelDisable(ADC_BASE, channel);

    return (sample);
}

/*
 * \brief sets the number of bits to shift the value read by ADCFIFORead()
 */
void analogReadResolution(uint8_t bits)
{
    analogReadShift = 14 - bits;
}
