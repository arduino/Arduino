/*
  ************************************************************************
  *	HardwareSerial.cpp
  *
  *	Arduino core files for C2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  wiring_digital.c - digital input and output functions
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
#include "pins_energia.h"

void pinMode(uint8_t pin, uint8_t mode)
{
    uint16_t gpio_number = pin_mapping[pin];

    if(gpio_number & 0x8000)
    {

    	EALLOW;
        //Analog Pins
        gpio_number &= 0x7FFF;

        if(mode == HARDWARE)
        {
            //Turn on normal analog functionality
            GpioCtrlRegs.AIOMUX1.all |= 3UL << (gpio_number * 2);
        }
        else
        {
            //Turn on AIO functionality
            GpioCtrlRegs.AIOMUX1.all &= ~( 3UL << (gpio_number * 2));

            if(mode == INPUT)
            {
                GpioCtrlRegs.AIODIR.all &= ~(1UL << gpio_number);
            }
            else if(mode == OUTPUT)
            {
                GpioCtrlRegs.AIODIR.all |= (1UL << gpio_number);
            }

        }
        EDIS;

    }
    else
    {
        //Digital Pins
	    volatile uint32_t *dir;
	    volatile uint32_t *sel;
	    volatile uint32_t *pud;
	    uint8_t port = digitalPinToPort(gpio_number);
	    dir = portDirRegister(port);
	    sel = portSelRegister(port);
    	pud = portPullupRegister(port);

	    if (port == NOT_A_PORT) return;

    	if(gpio_number > 31){
    		gpio_number -= 32;
    	}

    	EALLOW;
    	//Turn off peripheral function
    	if(port == PORT_A_2){
    		*sel &= ~((uint32_t)0x03 << ((gpio_number-16) * 2));
    	}else{
    		*sel &= ~((uint32_t)0x03 << (gpio_number * 2));
    	}
    	*dir &= ~((uint32_t)1 << gpio_number);
    	*dir |= ((uint32_t)(mode & 0x01) << gpio_number);

    	if(mode == INPUT_PULLUP){
    		*pud &= ~((uint32_t)1 << gpio_number);
    	}else{
    		*pud |= ((uint32_t)1 << gpio_number);
    	}

    	EDIS;
    }

}

void pinMode_int(uint8_t pin, uint8_t mode)
{
    uint16_t gpio_number = pin_mapping[pin];
	uint8_t bit = digitalPinToBitMask(gpio_number);
	uint8_t port = digitalPinToPort(gpio_number);

	volatile uint32_t *dir;
	volatile uint32_t *out;

	if (port == NOT_A_PORT) return;

	dir = portDirRegister(port);
	out = portOutputRegister(port);

	if (mode & OUTPUT) {
		*dir |= bit;
	} else {
		*dir &= ~bit;
		if (mode & INPUT_PULLUP) {
                *out |= bit;
        }
	}

}

int digitalRead(uint8_t pin)
{
    uint16_t gpio_number = pin_mapping[pin];
	uint32_t bit = digitalPinToBitMask(gpio_number);
	uint32_t port = digitalPinToPort(gpio_number);


    if(gpio_number & 0x8000)
    {
        //Analog Pins
        gpio_number &= 0x7FFF;

        if(GpioDataRegs.AIODAT.all & (1UL << gpio_number))
            return HIGH;
        else
            return LOW;

    }
    else
    {

    	if (port == NOT_A_PORT) return LOW;

        //Digital Pins

	    if (*portInputRegister(port) & bit) 
            return HIGH;
        else
	        return LOW;

    }
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    uint16_t gpio_number = pin_mapping[pin];
	uint32_t bit = digitalPinToBitMask(gpio_number);
	uint32_t port = digitalPinToPort(gpio_number);
	volatile uint32_t *out;




    if(gpio_number & 0x8000)
    {
        //Analog Pins
        gpio_number &= 0x7FFF;

        GpioDataRegs.AIODAT.all = (GpioDataRegs.AIODAT.all & ~(1UL << gpio_number)) | ((uint32_t)val << gpio_number);

    }
    else
    {
    	if (port == NOT_A_PORT) return;

        //Digital Pins
	    out = portOutputRegister(port);

    	if (val == LOW) {
    		*out &= ~bit;
    	} else {
	    	*out |= bit;
    	}
    }
}
