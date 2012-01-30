/* Tone.cpp

  A Tone Generator Library

  Written by Brett Hagman, Ported to xmega by Russell McClellan

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
-- See github history for history of the xmega version.

*************************************************/
#include "pins_arduino.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "Arduino.h"

// For the xmega, this only ever can deal with a single pin.
// The reason for this is the interrupts make the timing inherently imprecise.
// I'm going to write a "precise tone generator" library that will support
// multiple pins and will use waveform generation rather than interrupts.
// with 16 bits accuracy and no interrupts we'd be in a similar accuracy situation
// to professional synthesizers :-).

uint8_t tone_pin = 255; // as in the Arduino version, 255 means "no port."
uint8_t tone_pin_port = 0;
uint8_t tone_pin_mask = 0;

// Just like the arduino version, we implement the timeout as countdown
// on the number of toggles.  A negative value here  means that we never 
// want to timeout.
int32_t tone_toggle_count = 0;

// edit all these together, please!
uint32_t prescales_available[] = {1, 2, 4, 8, 64, 256, 1024};
uint8_t  prescales_shift_vs_previous[] = {0, 1, 1, 1, 3, 2, 2};
uint8_t prescale_ctrla[] = {TC_CLKSEL_DIV1_gc, TC_CLKSEL_DIV2_gc,
                            TC_CLKSEL_DIV4_gc, TC_CLKSEL_DIV8_gc,
                            TC_CLKSEL_DIV64_gc, TC_CLKSEL_DIV256_gc,
                            TC_CLKSEL_DIV1024_gc};

#define NUM_PRESCALES ( sizeof(prescales_available) / sizeof(uint32_t) )

// we use a 16 bit timer for extra precision.  good enough for the juno, good enough for us :-).  currently we don't use this timer anywhere else on the protomega.
#define TONE_TIMER TCC1
#define TONE_TIMER_OVF_vect TCC1_OVF_vect

void noTone(uint8_t pin)
{
  if (pin == tone_pin)
  {
    // no more tone!
    tone_pin = 255;
    
    // turn off interrupt.
    TONE_TIMER.INTCTRLA = TC_OVFINTLVL_OFF_gc;
  }

  // This is here rather than inside the conditional in order to maintain
  // compatibility with the arduino.
  digitalWrite(pin, LOW);
  
}

// frequency (in hertz) and duration (in milliseconds).
void tone(uint8_t pin, unsigned int frequency, unsigned long duration)
{
  if(frequency == 0)
    noTone(pin);

  // set the pin to be an output.
  pinMode(pin, OUTPUT);

  tone_pin = pin;
  tone_pin_port = digitalPinToPort(pin);
  tone_pin_mask = digitalPinToBitMask(pin);

  if(duration > 0)
    tone_toggle_count = 2* frequency * duration / 1000;
  else
    tone_toggle_count = -1;

  // we're trying to set up an interrupt with a frequency of 2 * frequency, since we toggle the pin on each interrupt.  let's loop through the pre-scalers and try to find the best match.
  uint32_t required_period = (F_CPU / frequency / 2);

  // go through from fastest to slowest, since we want the most accurate possible.
  for(int i = 0; i < NUM_PRESCALES; ++i)
  {
    required_period >>= prescales_shift_vs_previous[i];
    if(required_period <= 0x10000) // can we do this in 16 bits?
    {
      TONE_TIMER.CTRLA = prescale_ctrla[i];
      TONE_TIMER.PERBUF = required_period - 1;
      TONE_TIMER.CTRLB = ( TONE_TIMER.CTRLB & ~TC1_WGMODE_gm ) | TC_WGMODE_NORMAL_gc;
      TONE_TIMER.CNT = 0;
      // turn on a low-priority interrupt. the timing isn't going to be that great anyways because this is all interrupt based, so no point in being high priority.
      TONE_TIMER.INTCTRLA = TC_OVFINTLVL_LO_gc;
      break;
    }
  }
}

// ISR routine is exactly the same as the arduino version.
ISR(TONE_TIMER_OVF_vect)
{
  
  if(tone_toggle_count != 0)
  {
    // toggle the tone pin.
    portRegister(tone_pin_port)->OUT = (portRegister(tone_pin_port)->IN) ^ tone_pin_mask;
    
    if(tone_toggle_count > 0)
      --tone_toggle_count;
  }
  else
  {
    // we've toggled our last toggle, buddy!
    noTone(tone_pin);
  }
}
