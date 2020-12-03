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

/* $Id: iotn44a.h 2035 2009-11-02 02:44:17Z arcanum $ */

/* avr/iotn44a.h - definitions for ATtiny44A */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn44a.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATtiny44A_H_
#define _AVR_ATtiny44A_H_ 1


/* Registers and associated bit numbers. */

#define PRR _SFR_IO8(0x00)
#define PRADC 0
#define PRUSI 1
#define PRTIM0 2
#define PRTIM1 3

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSI
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1

#define DIDR0 _SFR_IO8(0x01)
#define ADC0D 0
#define ADC1D 1
#define ADC2D 2
#define ADC3D 3
#define ADC4D 4
#define ADC5D 5
#define ADC6D 6
#define ADC7D 7

#define ADCSRB _SFR_IO8(0x03)
#define ADTS0 0
#define ADTS1 1
#define ADTS2 2
#define ADLAR 4
#define ACME 6
#define BIN 7

#ifndef __ASSEMBLER__
#define ADC _SFR_IO16(0x04)
#endif
#define ADCW _SFR_IO16(0x04)

#define ADCL _SFR_IO8(0x04)
#define ADCL0 0
#define ADCL1 1
#define ADCL2 2
#define ADCL3 3
#define ADCL4 4
#define ADCL5 5
#define ADCL6 6
#define ADCL7 7

#define ADCH _SFR_IO8(0x05)
#define ADCH0 0
#define ADCH1 1
#define ADCH2 2
#define ADCH3 3
#define ADCH4 4
#define ADCH5 5
#define ADCH6 6
#define ADCH7 7

#define ADCSRA _SFR_IO8(0x06)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ADMUX _SFR_IO8(0x07)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define MUX5 5
#define REFS0 6
#define REFS1 7

#define ACSR _SFR_IO8(0x08)
#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACBG 6
#define ACD 7

#define TIFR1 _SFR_IO8(0x0B)
#define TOV1 0
#define OCF1A 1
#define OCF1B 2
#define ICF1 5

#define TIMSK1 _SFR_IO8(0x0C)
#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define ICIE1 5

#define USICR _SFR_IO8(0x0D)
#define USITC 0
#define USICLK 1
#define USICS0 2
#define USICS1 3
#define USIWM0 4
#define USIWM1 5
#define USIOIE 6
#define USISIE 7

#define USISR _SFR_IO8(0x0E)
#define USICNT0 0
#define USICNT1 1
#define USICNT2 2
#define USICNT3 3
#define USIDC 4
#define USIPF 5
#define USIOIF 6
#define USISIF 7

#define USIDR _SFR_IO8(0x0F)
#define USIDR0 0
#define USIDR1 1
#define USIDR2 2
#define USIDR3 3
#define USIDR4 4
#define USIDR5 5
#define USIDR6 6
#define USIDR7 7

#define USIBR _SFR_IO8(0x10)
#define USIBR0 0
#define USIBR1 1
#define USIBR2 2
#define USIBR3 3
#define USIBR4 4
#define USIBR5 5
#define USIBR6 6
#define USIBR7 7

#define PCMSK0 _SFR_IO8(0x12)
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define GPIOR0 _SFR_IO8(0x13)
#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define GPIOR1 _SFR_IO8(0x14)
#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR2 _SFR_IO8(0x15)
#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

#define PINB _SFR_IO8(0x16)
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3

#define DDRB _SFR_IO8(0x17)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3

#define PORTB _SFR_IO8(0x18)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3

#define PINA _SFR_IO8(0x19)
#define PINA0 0
#define PINA1 1
#define PINA2 2
#define PINA3 3
#define PINA4 4
#define PINA5 5
#define PINA6 6
#define PINA7 7

#define DDRA _SFR_IO8(0x1A)
#define DDA0 0
#define DDA1 1
#define DDA2 2
#define DDA3 3
#define DDA4 4
#define DDA5 5
#define DDA6 6
#define DDA7 7

#define PORTA _SFR_IO8(0x1B)
#define PORTA0 0
#define PORTA1 1
#define PORTA2 2
#define PORTA3 3
#define PORTA4 4
#define PORTA5 5
#define PORTA6 6
#define PORTA7 7

#define EECR _SFR_IO8(0x1C)
#define EERE 0
#define EEPE 1
#define EEMPE 2
#define EERIE 3
#define EEPM0 4
#define EEPM1 5

#define EEDR _SFR_IO8(0x1D)
#define EEDR0 0
#define EEDR1 1
#define EEDR2 2
#define EEDR3 3
#define EEDR4 4
#define EEDR5 5
#define EEDR6 6
#define EEDR7 7

#define EEAR _SFR_IO16(0x1E)

#define EEARL _SFR_IO8(0x1E)
#define EEAR0 0
#define EEAR1 1
#define EEAR2 2
#define EEAR3 3
#define EEAR4 4
#define EEAR5 5
#define EEAR6 6
#define EEAR7 7

#define EEARH _SFR_IO8(0x1F)
#define EEAR8 0

#define PCMSK1 _SFR_IO8(0x20)
#define PCINT8 0
#define PCINT9 1
#define PCINT10 2
#define PCINT11 3

#define WDTCSR _SFR_IO8(0x21)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDCE 4
#define WDP3 5
#define WDIE 6
#define WDIF 7

#define TCCR1C _SFR_IO8(0x22)
#define FOC1B 6
#define FOC1A 7

#define GTCCR _SFR_IO8(0x23)
#define PSR10 0
#define TSM 7

#define ICR1 _SFR_IO16(0x24)

#define ICR1L _SFR_IO8(0x24)
#define ICR1L0 0
#define ICR1L1 1
#define ICR1L2 2
#define ICR1L3 3
#define ICR1L4 4
#define ICR1L5 5
#define ICR1L6 6
#define ICR1L7 7

#define ICR1H _SFR_IO8(0x25)
#define ICR1H0 0
#define ICR1H1 1
#define ICR1H2 2
#define ICR1H3 3
#define ICR1H4 4
#define ICR1H5 5
#define ICR1H6 6
#define ICR1H7 7

#define CLKPR _SFR_IO8(0x26)
#define CLKPS0 0
#define CLKPS1 1
#define CLKPS2 2
#define CLKPS3 3
#define CLKPCE 7

#define DWDR _SFR_IO8(0x27)

#define OCR1B _SFR_IO16(0x28)

#define OCR1BL _SFR_IO8(0x28)
#define OCR1BL0 0
#define OCR1BL1 1
#define OCR1BL2 2
#define OCR1BL3 3
#define OCR1BL4 4
#define OCR1BL5 5
#define OCR1BL6 6
#define OCR1BL7 7

#define OCR1BH _SFR_IO8(0x29)
#define OCR1BH0 0
#define OCR1BH1 1
#define OCR1BH2 2
#define OCR1BH3 3
#define OCR1BH4 4
#define OCR1BH5 5
#define OCR1BH6 6
#define OCR1BH7 7

#define OCR1A _SFR_IO16(0x2A)

#define OCR1AL _SFR_IO8(0x2A)
#define OCR1AL0 0
#define OCR1AL1 1
#define OCR1AL2 2
#define OCR1AL3 3
#define OCR1AL4 4
#define OCR1AL5 5
#define OCR1AL6 6
#define OCR1AL7 7

#define OCR1AH _SFR_IO8(0x2B)
#define OCR1AH0 0
#define OCR1AH1 1
#define OCR1AH2 2
#define OCR1AH3 3
#define OCR1AH4 4
#define OCR1AH5 5
#define OCR1AH6 6
#define OCR1AH7 7

#define TCNT1 _SFR_IO16(0x2C)

#define TCNT1L _SFR_IO8(0x2C)
#define TCNT1L0 0
#define TCNT1L1 1
#define TCNT1L2 2
#define TCNT1L3 3
#define TCNT1L4 4
#define TCNT1L5 5
#define TCNT1L6 6
#define TCNT1L7 7

#define TCNT1H _SFR_IO8(0x2D)
#define TCNT1H0 0
#define TCNT1H1 1
#define TCNT1H2 2
#define TCNT1H3 3
#define TCNT1H4 4
#define TCNT1H5 5
#define TCNT1H6 6
#define TCNT1H7 7

#define TCCR1B _SFR_IO8(0x2E)
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define TCCR1A _SFR_IO8(0x2F)
#define WGM10 0
#define WGM11 1
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TCCR0A _SFR_IO8(0x30)
#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

#define OSCCAL _SFR_IO8(0x31)
#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define TCNT0 _SFR_IO8(0x32)
#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define TCCR0B _SFR_IO8(0x33)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM02 3
#define FOC0B 6
#define FOC0A 7

#define MCUSR _SFR_IO8(0x34)
#define PORF 0
#define EXTRF 1
#define BORF 2
#define WDRF 3

#define MCUCR _SFR_IO8(0x35)
#define ISC00 0
#define ISC01 1
#define BODSE 2
#define SM0 3
#define SM1 4
#define SE 5
#define PUD 6
#define BODS 7

#define OCR0A _SFR_IO8(0x36)
#define OCR0A_0 0
#define OCR0A_1 1
#define OCR0A_2 2
#define OCR0A_3 3
#define OCR0A_4 4
#define OCR0A_5 5
#define OCR0A_6 6
#define OCR0A_7 7

#define SPMCSR _SFR_IO8(0x37)
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define RFLB 3
#define CTPB 4

#define TIFR0 _SFR_IO8(0x38)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2

#define TIMSK0 _SFR_IO8(0x39)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2

#define GIFR _SFR_IO8(0x3A)
#define PCIF0 4
#define PCIF1 5
#define INTF0 6

#define GIMSK _SFR_IO8(0x3B)
#define PCIE0 4
#define PCIE1 5
#define INT0 6

#define OCR0B _SFR_IO8(0x3C)
#define OCR0_0 0
#define OCR0_1 1
#define OCR0_2 2
#define OCR0_3 3
#define OCR0_4 4
#define OCR0_5 5
#define OCR0_6 6
#define OCR0_7 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define EXT_INT0_vect_num  1
#define EXT_INT0_vect      _VECTOR(1)  /* External Interrupt Request 0 */
#define PCINT0_vect_num  2
#define PCINT0_vect      _VECTOR(2)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect_num  3
#define PCINT1_vect      _VECTOR(3)  /* Pin Change Interrupt Request 1 */
#define WATCHDOG_vect_num  4
#define WATCHDOG_vect      _VECTOR(4)  /* Watchdog Time-out */
#define TIM1_CAPT_vect_num  5
#define TIM1_CAPT_vect      _VECTOR(5)  /* Timer/Counter1 Capture Event */
#define TIM1_COMPA_vect_num  6
#define TIM1_COMPA_vect      _VECTOR(6)  /* Timer/Counter1 Compare Match A */
#define TIM1_COMPB_vect_num  7
#define TIM1_COMPB_vect      _VECTOR(7)  /* Timer/Counter1 Compare Match B */
#define TIM1_OVF_vect_num  8
#define TIM1_OVF_vect      _VECTOR(8)  /* Timer/Counter1 Overflow */
#define TIM0_COMPA_vect_num  9
#define TIM0_COMPA_vect      _VECTOR(9)  /* Timer/Counter0 Compare Match A */
#define TIM0_COMPB_vect_num  10
#define TIM0_COMPB_vect      _VECTOR(10)  /* Timer/Counter0 Compare Match B */
#define TIM0_OVF_vect_num  11
#define TIM0_OVF_vect      _VECTOR(11)  /* Timer/Counter0 Overflow */
#define ANA_COMP_vect_num  12
#define ANA_COMP_vect      _VECTOR(12)  /* Analog Comparator */
#define ADC_vect_num  13
#define ADC_vect      _VECTOR(13)  /* ADC Conversion Complete */
#define EE_RDY_vect_num  14
#define EE_RDY_vect      _VECTOR(14)  /* EEPROM Ready */
#define USI_STR_vect_num  15
#define USI_STR_vect      _VECTOR(15)  /* USI START */
#define USI_OVF_vect_num  16
#define USI_OVF_vect      _VECTOR(16)  /* USI Overflow */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (17 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (64)
#define RAMSTART     (0x60)
#define RAMSIZE      (256)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0xFF)
#define E2PAGESIZE   (4)
#define FLASHEND     (0xFFF)


/* Fuses */
#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_CKSEL0  (unsigned char)~_BV(0)  /* Select Clock source */
#define FUSE_CKSEL1  (unsigned char)~_BV(1)  /* Select Clock source */
#define FUSE_CKSEL2  (unsigned char)~_BV(2)  /* Select Clock source */
#define FUSE_CKSEL3  (unsigned char)~_BV(3)  /* Select Clock source */
#define FUSE_SUT0  (unsigned char)~_BV(4)  /* Select start-up time */
#define FUSE_SUT1  (unsigned char)~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT  (unsigned char)~_BV(6)  /* Clock Output Enable */
#define FUSE_CKDIV8  (unsigned char)~_BV(7)  /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_SUT0 & FUSE_CKDIV8)

/* High Fuse Byte */
#define FUSE_BODLEVEL0  (unsigned char)~_BV(0)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1  (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2  (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
#define FUSE_EESAVE  (unsigned char)~_BV(3)  /* EEPROM memory is preserved through the Chip Erase */
#define FUSE_WDTON  (unsigned char)~_BV(4)  /* Watchdog Timer always on */
#define FUSE_SPIEN  (unsigned char)~_BV(5)  /* Enable Serial Program and Data Downloading */
#define FUSE_DWEN  (unsigned char)~_BV(6)  /* DebugWIRE Enable */
#define FUSE_RSTDISBL  (unsigned char)~_BV(7)  /* External Reset disable */
#define HFUSE_DEFAULT (FUSE_SPIEN)

/* Extended Fuse Byte */
#define FUSE_SELFPRGEN  (unsigned char)~_BV(0)  /* Self-Programming Enable */
#define EFUSE_DEFAULT (0xFF)


/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x92
#define SIGNATURE_2 0x07


/* Device Pin Definitions */
#define ADC4_DDR   DDRA
#define ADC4_PORT  PORTA
#define ADC4_PIN   PINA
#define ADC4_BIT   4

#define USCK_DDR   DDRA
#define USCK_PORT  PORTA
#define USCK_PIN   PINA
#define USCK_BIT   4

#define SCL_DDR   DDRA
#define SCL_PORT  PORTA
#define SCL_PIN   PINA
#define SCL_BIT   4

#define T1_DDR   DDRA
#define T1_PORT  PORTA
#define T1_PIN   PINA
#define T1_BIT   4

#define PCINT4_DDR   DDRA
#define PCINT4_PORT  PORTA
#define PCINT4_PIN   PINA
#define PCINT4_BIT   4

#define ADC3_DDR   DDRA
#define ADC3_PORT  PORTA
#define ADC3_PIN   PINA
#define ADC3_BIT   3

#define T0_DDR   DDRA
#define T0_PORT  PORTA
#define T0_PIN   PINA
#define T0_BIT   3

#define PCINT3_DDR   DDRA
#define PCINT3_PORT  PORTA
#define PCINT3_PIN   PINA
#define PCINT3_BIT   3

#define ADC2_DDR   DDRA
#define ADC2_PORT  PORTA
#define ADC2_PIN   PINA
#define ADC2_BIT   2

#define AIN1_DDR   DDRA
#define AIN1_PORT  PORTA
#define AIN1_PIN   PINA
#define AIN1_BIT   2

#define PCINT2_DDR   DDRA
#define PCINT2_PORT  PORTA
#define PCINT2_PIN   PINA
#define PCINT2_BIT   2

#define ADC1_DDR   DDRA
#define ADC1_PORT  PORTA
#define ADC1_PIN   PINA
#define ADC1_BIT   1

#define AIN0_DDR   DDRA
#define AIN0_PORT  PORTA
#define AIN0_PIN   PINA
#define AIN0_BIT   1

#define PCINT1_DDR   DDRA
#define PCINT1_PORT  PORTA
#define PCINT1_PIN   PINA
#define PCINT1_BIT   1

#define ADC0_DDR   DDRA
#define ADC0_PORT  PORTA
#define ADC0_PIN   PINA
#define ADC0_BIT   0

#define PCINT0_DDR   DDRA
#define PCINT0_PORT  PORTA
#define PCINT0_PIN   PINA
#define PCINT0_BIT   0

#define PCINT8_DDR   DDRB
#define PCINT8_PORT  PORTB
#define PCINT8_PIN   PINB
#define PCINT8_BIT   0

#define PCINT9_DDR   DDRB
#define PCINT9_PORT  PORTB
#define PCINT9_PIN   PINB
#define PCINT9_BIT   1

#define PCINT11_DDR   DDRB
#define PCINT11_PORT  PORTB
#define PCINT11_PIN   PINB
#define PCINT11_BIT   3

#define dW_DDR   DDRB
#define dW_PORT  PORTB
#define dW_PIN   PINB
#define dW_BIT   3

#define PCINT10_DDR   DDRB
#define PCINT10_PORT  PORTB
#define PCINT10_PIN   PINB
#define PCINT10_BIT   2

#define INT0_DDR   DDRB
#define INT0_PORT  PORTB
#define INT0_PIN   PINB
#define INT0_BIT   2

#define OC0A_DDR   DDRB
#define OC0A_PORT  PORTB
#define OC0A_PIN   PINB
#define OC0A_BIT   2

#define CKOUT_DDR   DDRB
#define CKOUT_PORT  PORTB
#define CKOUT_PIN   PINB
#define CKOUT_BIT   2

#define PCINT7_DDR   DDRA
#define PCINT7_PORT  PORTA
#define PCINT7_PIN   PINA
#define PCINT7_BIT   7

#define ICP1_DDR   DDRA
#define ICP1_PORT  PORTA
#define ICP1_PIN   PINA
#define ICP1_BIT   7

#define OC0B_DDR   DDRA
#define OC0B_PORT  PORTA
#define OC0B_PIN   PINA
#define OC0B_BIT   7

#define ADC7_DDR   DDRA
#define ADC7_PORT  PORTA
#define ADC7_PIN   PINA
#define ADC7_BIT   7

#define PCINT6_DDR   DDRA
#define PCINT6_PORT  PORTA
#define PCINT6_PIN   PINA
#define PCINT6_BIT   6

#define OC1A_DDR   DDRA
#define OC1A_PORT  PORTA
#define OC1A_PIN   PINA
#define OC1A_BIT   6

#define DI_DDR   DDRA
#define DI_PORT  PORTA
#define DI_PIN   PINA
#define DI_BIT   6

#define SDA_DDR   DDRA
#define SDA_PORT  PORTA
#define SDA_PIN   PINA
#define SDA_BIT   6

#define MOSI_DDR   DDRA
#define MOSI_PORT  PORTA
#define MOSI_PIN   PINA
#define MOSI_BIT   6

#define ADC6_DDR   DDRA
#define ADC6_PORT  PORTA
#define ADC6_PIN   PINA
#define ADC6_BIT   6

#define ADC5_DDR   DDRA
#define ADC5_PORT  PORTA
#define ADC5_PIN   PINA
#define ADC5_BIT   5

#define DO_DDR   DDRA
#define DO_PORT  PORTA
#define DO_PIN   PINA
#define DO_BIT   5

#define MISO_DDR   DDRA
#define MISO_PORT  PORTA
#define MISO_PIN   PINA
#define MISO_BIT   5

#define OC1B_DDR   DDRA
#define OC1B_PORT  PORTA
#define OC1B_PIN   PINA
#define OC1B_BIT   5

#define PCINT5_DDR   DDRA
#define PCINT5_PORT  PORTA
#define PCINT5_PIN   PINA
#define PCINT5_BIT   5

#define SLEEP_MODE_IDLE (0x00<<3)
#define SLEEP_MODE_ADC (0x01<<3)
#define SLEEP_MODE_PWR_DOWN (0x02<<3)
#define SLEEP_MODE_STANDBY (0x03<<3)

#endif /* _AVR_ATtiny44A_H_ */

