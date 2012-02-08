/*
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

  $Id: wiring.c 248 2007-02-03 15:36:30Z mellis $
*/

#include "wiring_private.h"
#include "pins_arduino.h"

#if !defined ADC_CH_MUXPOS_gp
    #define ADC_CH_MUXPOS_gp  ADC_CH_MUXPOS0_bp
#endif
#if !defined ADC_REFSEL_gp
    #define ADC_REFSEL_gp  ADC_REFSEL0_bp
#endif

uint8_t analog_reference = DEFAULT;

void analogReference(uint8_t mode)
{
    // can't actually set the register here because the default setting
    // will connect AVCC and the AREF pin, which would cause a short if
    // there's something connected to AREF.
    analog_reference = mode;
}

int analogRead12(uint8_t pin)
{
    ADC_t* adc;
#if defined(ADCB) //Atxmega128a1 has 2 8 channel ADCs
    if ( pin < 8 ) {
        adc = &ADCA;
    } else if ( pin < 16 ) {
        adc = &ADCB;
        pin -= 8;
#else            //Atxmega32a4 has 1 12 channel ADC
    if ( pin < 12 ) {
        adc = &ADCA;
#endif
    } else {
        return -1;
    }

    pin = adcToChannel(pin);

    adc->REFCTRL     = analog_reference << ADC_REFSEL_gp;
    adc->CH0.MUXCTRL = pin << ADC_CH_MUXPOS_gp; // Select pin for positive input

    adc->CH0.CTRL |= ADC_CH_START_bm; // Start conversion
    while ( 0 == (adc->CH0.INTFLAGS & ADC_CH_CHIF_bm) ); // wait for adc to finish
    adc->CH0.INTFLAGS = 1;

    uint16_t result = adc->CH0RES;

    return result;
}

int analogRead(uint8_t pin)
{
    return analogRead12(pin) >> 2; // 10 bits
}

// 24 bits let's users represent up to 256 volts using a fixed point representation.
long analogRead24(uint8_t pin)
{
    return ( (long)analogRead12(pin) ) << 12;
}

unsigned analogRead16(uint8_t pin)
{
    return ( (unsigned)analogRead12(pin) ) << 4;
}

double analogReadFloat(uint8_t pin)
{
    return ((double)analogRead12(pin)) / ((double)0xFFF);
}

const uint16_t PROGMEM timer_to_channel_register_PGM[] = {
	(uint16_t)NULL,

    (uint16_t)&TCC0.CCABUF,
    (uint16_t)&TCC0.CCBBUF,
    (uint16_t)&TCC0.CCCBUF,
    (uint16_t)&TCC0.CCDBUF,
    (uint16_t)&TCC1.CCABUF,
    (uint16_t)&TCC1.CCBBUF,

    (uint16_t)&TCD0.CCABUF,
    (uint16_t)&TCD0.CCBBUF,
    (uint16_t)&TCD0.CCCBUF,
    (uint16_t)&TCD0.CCDBUF,
    (uint16_t)&TCD1.CCABUF,
    (uint16_t)&TCD1.CCBBUF,

    (uint16_t)&TCE0.CCABUF,
    (uint16_t)&TCE0.CCBBUF,
    (uint16_t)&TCE0.CCCBUF,
    (uint16_t)&TCE0.CCDBUF,
#if defined(TCE1)
    (uint16_t)&TCE1.CCABUF,
    (uint16_t)&TCE1.CCBBUF,
#else
    (uint16_t)NULL,
    (uint16_t)NULL,
#endif

#if defined(TCC2)
    (uint16_t)&TCC2.LCMPA,
    (uint16_t)&TCC2.LCMPB,
    (uint16_t)&TCC2.LCMPC,
    (uint16_t)&TCC2.LCMPD,
    (uint16_t)&TCC2.HCMPA,
    (uint16_t)&TCC2.HCMPB,
    (uint16_t)&TCC2.HCMPC,
    (uint16_t)&TCC2.HCMPD,
#else
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
#endif

#if defined(TCD2)
    (uint16_t)&TCD2.LCMPA,
    (uint16_t)&TCD2.LCMPB,
    (uint16_t)&TCD2.LCMPC,
    (uint16_t)&TCD2.LCMPD,
    (uint16_t)&TCD2.HCMPA,
    (uint16_t)&TCD2.HCMPB,
    (uint16_t)&TCD2.HCMPC,
    (uint16_t)&TCD2.HCMPD,
#else
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
    (uint16_t)NULL,
#endif
};

#define timerToChannelRegister(T) ( (volatile uint16_t *)( pgm_read_word( timer_to_channel_register_PGM + (T))) )

// TODO: Add pwm12, pwm16, and pwm24.

// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.
void analogWrite(uint8_t pin, int val)
{
    uint8_t            timer            = digitalPinToTimer(pin);
    TC0_t*             tc0              = (TC0_t*)timerToTC0(timer);
    TC1_t*             tc1              = (TC1_t*)timerToTC1(timer);
#if defined(TCC2) || defined(TCD2)
    TC2_t*             tc2              = (TC2_t*)timerToTC2(timer);
#endif
    uint8_t            channel          = timerToChannel(timer);
    volatile uint16_t* channel_register = timerToChannelRegister(timer);

    // We need to make sure the PWM output is enabled for those pins
    // that support it, as we turn it off when digitally reading or
    // writing with them.  Also, make sure the pin is in output mode
    // for consistenty with Wiring, which doesn't require a pinMode
    // call for the analog output pins.

    pinMode(pin, OUTPUT);

    /// TODO: Can we run at 31Khz, well above the audible range?
    /// Issue is whether existing circuits can handle this.
    /// TODO: Add API to set freq pwm. Default to 1000khz,
    /// compatible with existing code.
    /// N = 32Mhz / (2 x freq pwm x PER)

    /// TODO: Update pin at waveform top, bottom, or both?
    /// Seems that by doing at top and bottom we can increase the
    /// pwm freq and resolution.
    /// For now, do at bottom for compatibility.

    // freq pwm = 32Mhz / (2 x N x PER)
    // N = 32Mhz / (2 x freq pwm x PER)
    // 64 is approximately = 61 = 32Mhz / (2 x 1Khz X PER)
    // 976hz = 32Mhz / (2 x 64 x 0xFF)
    if ( tc0 ) {
        tc0->PERBUF = 0xFF;
        tc0->CTRLA  = TC_CLKSEL_DIV64_gc;

        /// TODO: Factor out and move to wiring.c init.
        // Dual slope mode.
        tc0->CTRLB  = ( tc0->CTRLB & ~TC0_WGMODE_gm ) | TC_WGMODE_DS_B_gc;
        tc0->CTRLB |= TC0_CCAEN_bm << channel;
    } else if ( tc1 ) {
        tc1->PERBUF  = 0xFF;
        tc1->CTRLA   = TC_CLKSEL_DIV64_gc;
        tc1->CTRLB   = ( tc1->CTRLB & ~TC1_WGMODE_gm ) | TC_WGMODE_DS_B_gc;
        tc1->CTRLB  |= TC1_CCAEN_bm << channel;
    } 
#if defined(TCC2) || defined(TCD2)
    else if ( tc2 ) {
	tc2->CTRLE = TC2_BYTEM_SPLITMODE_gc;
	tc2->LPER = 0xFF;
	tc2->HPER = 0xFF;
	tc2->CTRLA  = TC2_CLKSEL_DIV64_gc;
	tc2->CTRLB |= 1 << channel;
    }
#endif
    

    // Set value
    if ( channel_register ) {
        *channel_register = val;
    } else if (val < 128) {
       digitalWrite(pin, LOW);
    } else {
        digitalWrite(pin, HIGH);
    }
}
