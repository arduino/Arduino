/* Copyright (c) 2009 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id: iotn5.h 2063 2009-11-18 22:06:28Z arcanum $ */

/* avr/iotn5.h - definitions for ATtiny5 */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn5.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATtiny5_H_
#define _AVR_ATtiny5_H_ 1


/* Registers and associated bit numbers. */

#define PINB _SFR_IO8(0x00)
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3

#define DDRB _SFR_IO8(0x01)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3

#define PORTB _SFR_IO8(0x02)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3

#define PUEB _SFR_IO8(0x03)
#define PUEB0 0
#define PUEB1 1
#define PUEB2 2
#define PUEB3 3

#define PORTCR _SFR_IO8(0x0C)
#define BBMB 1

#define PCMSK _SFR_IO8(0x10)
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3

#define PCIFR _SFR_IO8(0x11)
#define PCIF0 0

#define PCICR _SFR_IO8(0x12)
#define PCIE0 0

#define EIMSK _SFR_IO8(0x13)
#define INT0 0

#define EIFR _SFR_IO8(0x14)
#define INTF0 0

#define EICRA _SFR_IO8(0x15)
#define ISC00 0
#define ISC01 1

#define DIDR0 _SFR_IO8(0x17)
#define ADC0D 0
#define AIN0D 0
#define ADC1D 1
#define AIN1D 1
#define ADC2D 2
#define ADC3D 3

#define ADCL _SFR_IO8(0x19)
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

#define ADMUX _SFR_IO8(0x1B)
#define MUX0 0
#define MUX1 1

#define ADCSRB _SFR_IO8(0x1C)
#define ADTS0 0
#define ADTS1 1
#define ADTS2 2

#define ADCSRA _SFR_IO8(0x1D)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ACSR _SFR_IO8(0x1F)
#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACD 7

#define ICR0 _SFR_IO16(0x22)

#define ICR0L _SFR_IO8(0x22)
#define ICR0_0 0
#define ICR0_1 1
#define ICR0_2 2
#define ICR0_3 3
#define ICR0_4 4
#define ICR0_5 5
#define ICR0_6 6
#define ICR0_7 7

#define ICR0H _SFR_IO8(0x23)
#define ICR0_8 0
#define ICR0_9 1
#define ICR0_10 2
#define ICR0_11 3
#define ICR0_12 4
#define ICR0_13 5
#define ICR0_14 6
#define ICR0_15 7

#define OCR0B _SFR_IO16(0x24)

#define OCR0BL _SFR_IO8(0x24)
#define OCR0B0 0
#define OCR0B1 1
#define OCR0B2 2
#define OCR0B3 3
#define OCR0B4 4
#define OCR0B5 5
#define OCR0B6 6
#define OCR0B7 7

#define OCR0BH _SFR_IO8(0x25)
#define OCR0B8 0
#define OCR0B9 1
#define OCR0B10 2
#define OCR0B11 3
#define OCR0B12 4
#define OCR0B13 5
#define OCR0B14 6
#define OCR0B15 7

#define OCR0A _SFR_IO16(0x26)

#define OCR0AL _SFR_IO8(0x26)
#define OCR0A0 0
#define OCR0A1 1
#define OCR0A2 2
#define OCR0A3 3
#define OCR0A4 4
#define OCR0A5 5
#define OCR0A6 6
#define OCR0A7 7

#define OCR0AH _SFR_IO8(0x27)
#define OCR0A8 0
#define OCR0A9 1
#define OCR0A10 2
#define OCR0A11 3
#define OCR0A12 4
#define OCR0A13 5
#define OCR0A14 6
#define OCR0A15 7

#define TCNT0 _SFR_IO16(0x28)

#define TCNT0L _SFR_IO8(0x28)
#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define TCNT0H _SFR_IO8(0x29)
#define TCNT0_8 0
#define TCNT0_9 1
#define TCNT0_10 2
#define TCNT0_11 3
#define TCNT0_12 4
#define TCNT0_13 5
#define TCNT0_14 6
#define TCNT0_15 7

#define TIFR0 _SFR_IO8(0x2A)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2
#define ICF0 5

#define TIMSK0 _SFR_IO8(0x2B)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2
#define ICIE0 5

#define TCCR0C _SFR_IO8(0x2C)
#define FOC0B 6
#define FOC0A 7

#define TCCR0B _SFR_IO8(0x2D)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM02 3
#define WGM03 4
#define ICES0 6
#define ICNC0 7

#define TCCR0A _SFR_IO8(0x2E)
#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

#define GTCCR _SFR_IO8(0x2F)
#define PSR 0
#define TSM 7

#define WDTCSR _SFR_IO8(0x31)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDP3 5
#define WDIE 6
#define WDIF 7

#define NVMCSR _SFR_IO8(0x32)
#define NVMBSY 7

#define NVMCMD _SFR_IO8(0x33)
#define NVMCMD0 0
#define NVMCMD1 1
#define NVMCMD2 2
#define NVMCMD3 3
#define NVMCMD4 4
#define NVMCMD5 5

#define VLMCSR _SFR_IO8(0x34)
#define VLM0 0
#define VLM1 1
#define VLM2 2
#define VLMIE 6
#define VLMF 7

#define PRR _SFR_IO8(0x35)
#define PRTIM0 0
#define PRADC 1

#define __AVR_HAVE_PRR	((1<<PRTIM0)|(1<<PRADC))
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRADC

#define CLKPSR _SFR_IO8(0x36)
#define CLKPS0 0
#define CLKPS1 1
#define CLKPS2 2
#define CLKPS3 3

#define CLKMSR _SFR_IO8(0x37)
#define CLKMS0 0
#define CLKMS1 1

#define OSCCAL _SFR_IO8(0x39)
#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define SMCR _SFR_IO8(0x3A)
#define SE 0
#define SM0 1
#define SM1 2
#define SM2 3

#define RSTFLR _SFR_IO8(0x3B)
#define PORF 0
#define EXTRF 1
#define WDRF 3

#define CCP _SFR_IO8(0x3C)
#define CCP0 0
#define CCP1 1
#define CCP2 2
#define CCP3 3
#define CCP4 4
#define CCP5 5
#define CCP6 6
#define CCP7 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt Request 0 */
#define PCINT0_vect_num  2
#define PCINT0_vect      _VECTOR(2)  /* Pin Change Interrupt Request 0 */
#define TIM0_CAPT_vect_num  3
#define TIM0_CAPT_vect      _VECTOR(3)  /* Timer/Counter0 Input Capture */
#define TIM0_OVF_vect_num  4
#define TIM0_OVF_vect      _VECTOR(4)  /* Timer/Counter0 Overflow */
#define TIM0_COMPA_vect_num  5
#define TIM0_COMPA_vect      _VECTOR(5)  /* Timer/Counter Compare Match A */
#define TIM0_COMPB_vect_num  6
#define TIM0_COMPB_vect      _VECTOR(6)  /* Timer/Counter Compare Match B */
#define ANA_COMP_vect_num  7
#define ANA_COMP_vect      _VECTOR(7)  /* Analog Comparator */
#define WDT_vect_num  8
#define WDT_vect      _VECTOR(8)  /* Watchdog Time-out */
#define VLM_vect_num  9
#define VLM_vect      _VECTOR(9)  /* Vcc Voltage Level Monitor */
#define ADC_vect_num  10
#define ADC_vect      _VECTOR(10)  /* ADC Conversion Complete */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (11 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (32)
#define RAMSTART     (0x40)
#define RAMSIZE      (32)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0x0)
#define E2PAGESIZE   (0)
#define FLASHEND     (0x1FF)


/* Fuses */
#define FUSE_MEMORY_SIZE 0


/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x90
#define SIGNATURE_2 0x09


/* Device Pin Definitions */
#define SPDATA_DDR   DDRCINT
#define SPDATA_PORT  PORTCINT
#define SPDATA_PIN   PINCINT
#define SPDATA_BIT   INT0

#define OC0A_DDR   DDRCINT
#define OC0A_PORT  PORTCINT
#define OC0A_PIN   PINCINT
#define OC0A_BIT   INT0

#define ADC0_DDR   DDRCINT
#define ADC0_PORT  PORTCINT
#define ADC0_PIN   PINCINT
#define ADC0_BIT   INT0

#define AIN0_DDR   DDRCINT
#define AIN0_PORT  PORTCINT
#define AIN0_PIN   PINCINT
#define AIN0_BIT   INT0

#define PB0_DDR   DDRCINT
#define PB0_PORT  PORTCINT
#define PB0_PIN   PINCINT
#define PB0_BIT   INT0

#define SPCLK_DDR   DDRCINT
#define SPCLK_PORT  PORTCINT
#define SPCLK_PIN   PINCINT
#define SPCLK_BIT   INT1

#define CLKI_DDR   DDRCINT
#define CLKI_PORT  PORTCINT
#define CLKI_PIN   PINCINT
#define CLKI_BIT   INT1

#define ICP0_DDR   DDRCINT
#define ICP0_PORT  PORTCINT
#define ICP0_PIN   PINCINT
#define ICP0_BIT   INT1

#define OC0B_DDR   DDRCINT
#define OC0B_PORT  PORTCINT
#define OC0B_PIN   PINCINT
#define OC0B_BIT   INT1

#define ADC1_DDR   DDRCINT
#define ADC1_PORT  PORTCINT
#define ADC1_PIN   PINCINT
#define ADC1_BIT   INT1

#define AIN1_DDR   DDRCINT
#define AIN1_PORT  PORTCINT
#define AIN1_PIN   PINCINT
#define AIN1_BIT   INT1

#define PB1_DDR   DDRCINT
#define PB1_PORT  PORTCINT
#define PB1_PIN   PINCINT
#define PB1_BIT   INT1

#define CLKO_DDR   DDRT
#define CLKO_PORT  PORTT
#define CLKO_PIN   PINT
#define CLKO_BIT   T0

#define PCINT2_DDR   DDRT
#define PCINT2_PORT  PORTT
#define PCINT2_PIN   PINT
#define PCINT2_BIT   T0

#define INT0_DDR   DDRT
#define INT0_PORT  PORTT
#define INT0_PIN   PINT
#define INT0_BIT   T0

#define ADC2_DDR   DDRT
#define ADC2_PORT  PORTT
#define ADC2_PIN   PINT
#define ADC2_BIT   T0

#define PB2_DDR   DDRT
#define PB2_PORT  PORTT
#define PB2_PIN   PINT
#define PB2_BIT   T0

#define PCINT3_DDR   DDRRESET
#define PCINT3_PORT  PORTRESET
#define PCINT3_PIN   PINRESET
#define PCINT3_BIT   RESET

#define ADC3_DDR   DDRRESET
#define ADC3_PORT  PORTRESET
#define ADC3_PIN   PINRESET
#define ADC3_BIT   RESET

#define PB3_DDR   DDRRESET
#define PB3_PORT  PORTRESET
#define PB3_PIN   PINRESET
#define PB3_BIT   RESET

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_STANDBY (0x04<<1)

#endif /* _AVR_ATtiny5_H_ */

