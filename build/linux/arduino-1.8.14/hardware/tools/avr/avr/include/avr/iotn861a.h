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

/* $Id: iotn861a.h 2063 2009-11-18 22:06:28Z arcanum $ */

/* avr/iotn861a.h - definitions for ATtiny861A */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn861a.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATtiny861A_H_
#define _AVR_ATtiny861A_H_ 1


/* Registers and associated bit numbers. */

#define TCCR1E _SFR_IO8(0x00)
#define OC1OE0 0
#define OC1OE1 1
#define OC1OE2 2
#define OC1OE3 3
#define OC1OE4 4
#define OC1OE5 5

#define DIDR0 _SFR_IO8(0x01)
#define ADC0D 0
#define ADC1D 1
#define ADC2D 2
#define AREFD 3
#define ADC3D 4
#define ADC4D 5
#define ADC5D 6
#define ADC6D 7

#define DIDR1 _SFR_IO8(0x02)
#define ADC7D 4
#define ADC8D 5
#define ADC9D 6
#define ADC10D 7

#define ADCSRB _SFR_IO8(0x03)
#define ADTS0 0
#define ADTS1 1
#define ADTS2 2
#define MUX5 3
#define REFS2 4
#define IPR 5
#define GSEL 6
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
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ACSRA _SFR_IO8(0x08)
#define ACIS0 0
#define ACIS1 1
#define ACME 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACBG 6
#define ACD 7

#define ACSRB _SFR_IO8(0x09)
#define ACM0 0
#define ACM1 1
#define ACM2 2
#define HLEV 6
#define HSEL 7

#define GPIOR0 _SFR_IO8(0x0A)
#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define GPIOR1 _SFR_IO8(0x0B)
#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR2 _SFR_IO8(0x0C)
#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

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

#define USIPP _SFR_IO8(0x11)
#define USIPOS 0

#define OCR0B _SFR_IO8(0x12)
#define OCR0B_0 0
#define OCR0B_1 1
#define OCR0B_2 2
#define OCR0B_3 3
#define OCR0B_4 4
#define OCR0B_5 5
#define OCR0B_6 6
#define OCR0B_7 7

#define OCR0A _SFR_IO8(0x13)
#define OCR0A_0 0
#define OCR0A_1 1
#define OCR0A_2 2
#define OCR0A_3 3
#define OCR0A_4 4
#define OCR0A_5 5
#define OCR0A_6 6
#define OCR0A_7 7

#define TCNT0H _SFR_IO8(0x14)
#define TCNT0H_0 0
#define TCNT0H_1 1
#define TCNT0H_2 2
#define TCNT0H_3 3
#define TCNT0H_4 4
#define TCNT0H_5 5
#define TCNT0H_6 6
#define TCNT0H_7 7

#define TCCR0A _SFR_IO8(0x15)
#define WGM00 0
#define ACIC0 3
#define ICES0 4
#define ICNC0 5
#define ICEN0 6
#define TCW0 7

#define PINB _SFR_IO8(0x16)
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

#define DDRB _SFR_IO8(0x17)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB _SFR_IO8(0x18)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

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

#define DWDR _SFR_IO8(0x20)
#define DWDR0 0
#define DWDR1 1
#define DWDR2 2
#define DWDR3 3
#define DWDR4 4
#define DWDR5 5
#define DWDR6 6
#define DWDR7 7

#define WDTCR _SFR_IO8(0x21)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDCE 4
#define WDP3 5
#define WDIE 6
#define WDIF 7

#define PCMSK1 _SFR_IO8(0x22)
#define PCINT8 0
#define PCINT9 1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6
#define PCINT15 7

#define PCMSK0 _SFR_IO8(0x23)
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define DT1 _SFR_IO8(0x24)
#define DT1L0 0
#define DT1L1 1
#define DT1L2 2
#define DT1L3 3
#define DT1H0 4
#define DT1H1 5
#define DT1H2 6
#define DT1H3 7

#define TC1H _SFR_IO8(0x25)
#define TC18 0
#define TC19 1

#define TCCR1D _SFR_IO8(0x26)
#define WGM10 0
#define WGM11 1
#define FPF1 2
#define FPAC1 3
#define FPES1 4
#define FPNC1 5
#define FPEN1 6
#define FPIE1 7

#define TCCR1C _SFR_IO8(0x27)
#define PWM1D 0
#define FOC1D 1
#define COM1D0 2
#define COM1D1 3
#define COM1B0S 4
#define COM1B1S 5
#define COM1A0S 6
#define COM1A1S 7

#define CLKPR _SFR_IO8(0x28)
#define CLKPS0 0
#define CLKPS1 1
#define CLKPS2 2
#define CLKPS3 3
#define CLKPCE 7

#define PLLCSR _SFR_IO8(0x29)
#define PLOCK 0
#define PLLE 1
#define PCKE 2
#define LSM 7

#define OCR1D _SFR_IO8(0x2A)
#define OCR1D0 0
#define OCR1D1 1
#define OCR1D2 2
#define OCR1D3 3
#define OCR1D4 4
#define OCR1D5 5
#define OCR1D6 6
#define OCR1D7 7

#define OCR1C _SFR_IO8(0x2B)
#define OCR1C0 0
#define OCR1C1 1
#define OCR1C2 2
#define OCR1C3 3
#define OCR1C4 4
#define OCR1C5 5
#define OCR1C6 6
#define OCR1C7 7

#define OCR1B _SFR_IO8(0x2C)
#define OCR1B0 0
#define OCR1B1 1
#define OCR1B2 2
#define OCR1B3 3
#define OCR1B4 4
#define OCR1B5 5
#define OCR1B6 6
#define OCR1B7 7

#define OCR1A _SFR_IO8(0x2D)
#define OCR1A0 0
#define OCR1A1 1
#define OCR1A2 2
#define OCR1A3 3
#define OCR1A4 4
#define OCR1A5 5
#define OCR1A6 6
#define OCR1A7 7

#define TCNT1 _SFR_IO8(0x2E)
#define TC1H_0 0
#define TC1H_1 1
#define TC1H_2 2
#define TC1H_3 3
#define TC1H_4 4
#define TC1H_5 5
#define TC1H_6 6
#define TC1H_7 7

#define TCCR1B _SFR_IO8(0x2F)
#define CS10 0
#define CS11 1
#define CS12 2
#define CS13 3
#define DTPS10 4
#define DTPS11 5
#define PSR1 6
#define PWM1X 7

#define TCCR1A _SFR_IO8(0x30)
#define PWM1B 0
#define PWM1A 1
#define FOC1B 2
#define FOC1A 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define OSCCAL _SFR_IO8(0x31)
#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define TCNT0L _SFR_IO8(0x32)
#define TCNT0L_0 0
#define TCNT0L_1 1
#define TCNT0L_2 2
#define TCNT0L_3 3
#define TCNT0L_4 4
#define TCNT0L_5 5
#define TCNT0L_6 6
#define TCNT0L_7 7

#define TCCR0B _SFR_IO8(0x33)
#define CS00 0
#define CS01 1
#define CS02 2
#define PSR0 3
#define TSM 4

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

#define PRR _SFR_IO8(0x36)
#define PRADC 0
#define PRUSI 1
#define PRTIM0 2
#define PRTIM1 3

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSI
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1

#define SPMCSR _SFR_IO8(0x37)
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define RFLB 3
#define CTPB 4

#define TIFR _SFR_IO8(0x38)
#define ICF0 0
#define TOV0 1
#define TOV1 2
#define OCF0B 3
#define OCF0A 4
#define OCF1B 5
#define OCF1A 6
#define OCF1D 7

#define TIMSK _SFR_IO8(0x39)
#define TICIE0 0
#define TOIE0 1
#define TOIE1 2
#define OCIE0B 3
#define OCIE0A 4
#define OCIE1B 5
#define OCIE1A 6
#define OCIE1D 7

#define GIFR _SFR_IO8(0x3A)
#define PCIF 5
#define INTF0 6
#define INTF1 7

#define GIMSK _SFR_IO8(0x3B)
#define PCIE0 4
#define PCIE1 5
#define INT0 6
#define INT1 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt 0 */
#define PCINT_vect_num  2
#define PCINT_vect      _VECTOR(2)  /* Pin Change Interrupt */
#define TIMER1_COMPA_vect_num  3
#define TIMER1_COMPA_vect      _VECTOR(3)  /* Timer/Counter1 Compare Match 1A */
#define TIMER1_COMPB_vect_num  4
#define TIMER1_COMPB_vect      _VECTOR(4)  /* Timer/Counter1 Compare Match 1B */
#define TIMER1_OVF_vect_num  5
#define TIMER1_OVF_vect      _VECTOR(5)  /* Timer/Counter1 Overflow */
#define TIMER0_OVF_vect_num  6
#define TIMER0_OVF_vect      _VECTOR(6)  /* Timer/Counter0 Overflow */
#define USI_START_vect_num  7
#define USI_START_vect      _VECTOR(7)  /* USI Start */
#define USI_OVF_vect_num  8
#define USI_OVF_vect      _VECTOR(8)  /* USI Overflow */
#define EE_RDY_vect_num  9
#define EE_RDY_vect      _VECTOR(9)  /* EEPROM Ready */
#define ANA_COMP_vect_num  10
#define ANA_COMP_vect      _VECTOR(10)  /* Analog Comparator */
#define ADC_vect_num  11
#define ADC_vect      _VECTOR(11)  /* ADC Conversion Complete */
#define WDT_vect_num  12
#define WDT_vect      _VECTOR(12)  /* Watchdog Time-Out */
#define INT1_vect_num  13
#define INT1_vect      _VECTOR(13)  /* External Interrupt 1 */
#define TIMER0_COMPA_vect_num  14
#define TIMER0_COMPA_vect      _VECTOR(14)  /* Timer/Counter0 Compare Match A */
#define TIMER0_COMPB_vect_num  15
#define TIMER0_COMPB_vect      _VECTOR(15)  /* Timer/Counter0 Compare Match B */
#define TIMER0_CAPT_vect_num  16
#define TIMER0_CAPT_vect      _VECTOR(16)  /* ADC Conversion Complete */
#define TIMER1_COMPD_vect_num  17
#define TIMER1_COMPD_vect      _VECTOR(17)  /* Timer/Counter1 Compare Match D */
#define FAULT_PROTECTION_vect_num  18
#define FAULT_PROTECTION_vect      _VECTOR(18)  /* Timer/Counter1 Fault Protection */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (19 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (64)
#define RAMSTART     (0x60)
#define RAMSIZE      (512)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0x1FF)
#define E2PAGESIZE   (4)
#define FLASHEND     (0x1FFF)


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
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_CKDIV8)

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
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x0D


/* Device Pin Definitions */
#define DI_B_DDR   DDRMOSI
#define DI_B_PORT  PORTMOSI
#define DI_B_PIN   PINMOSI
#define DI_B_BIT   MOSI

#define SDA_B_DDR   DDRMOSI
#define SDA_B_PORT  PORTMOSI
#define SDA_B_PIN   PINMOSI
#define SDA_B_BIT   MOSI

#define _OC1A_DDR   DDRMOSI
#define _OC1A_PORT  PORTMOSI
#define _OC1A_PIN   PINMOSI
#define _OC1A_BIT   MOSI

#define PCINT8_DDR   DDRMOSI
#define PCINT8_PORT  PORTMOSI
#define PCINT8_PIN   PINMOSI
#define PCINT8_BIT   MOSI

#define PB0_DDR   DDRMOSI
#define PB0_PORT  PORTMOSI
#define PB0_PIN   PINMOSI
#define PB0_BIT   MOSI

#define DO_B_DDR   DDRMISO
#define DO_B_PORT  PORTMISO
#define DO_B_PIN   PINMISO
#define DO_B_BIT   MISO

#define OC1A_DDR   DDRMISO
#define OC1A_PORT  PORTMISO
#define OC1A_PIN   PINMISO
#define OC1A_BIT   MISO

#define PCINT9_DDR   DDRMISO
#define PCINT9_PORT  PORTMISO
#define PCINT9_PIN   PINMISO
#define PCINT9_BIT   MISO

#define PB1_DDR   DDRMISO
#define PB1_PORT  PORTMISO
#define PB1_PIN   PINMISO
#define PB1_BIT   MISO

#define USCK_B_DDR   DDRSCK
#define USCK_B_PORT  PORTSCK
#define USCK_B_PIN   PINSCK
#define USCK_B_BIT   SCK

#define SCL_B_DDR   DDRSCK
#define SCL_B_PORT  PORTSCK
#define SCL_B_PIN   PINSCK
#define SCL_B_BIT   SCK

#define OC1B_DDR   DDRSCK
#define OC1B_PORT  PORTSCK
#define OC1B_PIN   PINSCK
#define OC1B_BIT   SCK

#define PCINT10_DDR   DDRSCK
#define PCINT10_PORT  PORTSCK
#define PCINT10_PIN   PINSCK
#define PCINT10_BIT   SCK

#define PB2_DDR   DDRSCK
#define PB2_PORT  PORTSCK
#define PB2_PIN   PINSCK
#define PB2_BIT   SCK

#define PCINT11_DDR   DDROC1B
#define PCINT11_PORT  PORTOC1B
#define PCINT11_PIN   PINOC1B
#define PCINT11_BIT   OC1B

#define PB3_DDR   DDROC1B
#define PB3_PORT  PORTOC1B
#define PB3_PIN   PINOC1B
#define PB3_BIT   OC1B

#define PCINT12_DDR   DDRADC
#define PCINT12_PORT  PORTADC
#define PCINT12_PIN   PINADC
#define PCINT12_BIT   ADC7

#define _OC1D_DDR   DDRADC
#define _OC1D_PORT  PORTADC
#define _OC1D_PIN   PINADC
#define _OC1D_BIT   ADC7

#define CLKI_DDR   DDRADC
#define CLKI_PORT  PORTADC
#define CLKI_PIN   PINADC
#define CLKI_BIT   ADC7

#define PB4_DDR   DDRADC
#define PB4_PORT  PORTADC
#define PB4_PIN   PINADC
#define PB4_BIT   ADC7

#define PCINT13_DDR   DDRADC
#define PCINT13_PORT  PORTADC
#define PCINT13_PIN   PINADC
#define PCINT13_BIT   ADC8

#define OC1D_DDR   DDRADC
#define OC1D_PORT  PORTADC
#define OC1D_PIN   PINADC
#define OC1D_BIT   ADC8

#define CKLO_DDR   DDRADC
#define CKLO_PORT  PORTADC
#define CKLO_PIN   PINADC
#define CKLO_BIT   ADC8

#define PB5_DDR   DDRADC
#define PB5_PORT  PORTADC
#define PB5_PIN   PINADC
#define PB5_BIT   ADC8

#define INT0_DDR   DDRADC
#define INT0_PORT  PORTADC
#define INT0_PIN   PINADC
#define INT0_BIT   ADC9

#define T0_DDR   DDRADC
#define T0_PORT  PORTADC
#define T0_PIN   PINADC
#define T0_BIT   ADC9

#define PCINT14_DDR   DDRADC
#define PCINT14_PORT  PORTADC
#define PCINT14_PIN   PINADC
#define PCINT14_BIT   ADC9

#define PB6_DDR   DDRADC
#define PB6_PORT  PORTADC
#define PB6_PIN   PINADC
#define PB6_BIT   ADC9

#define PCINT15_DDR   DDRADC1
#define PCINT15_PORT  PORTADC1
#define PCINT15_PIN   PINADC1
#define PCINT15_BIT   ADC10

#define PB7_DDR   DDRADC1
#define PB7_PORT  PORTADC1
#define PB7_PIN   PINADC1
#define PB7_BIT   ADC10

#define AIN1_DDR   DDRADC
#define AIN1_PORT  PORTADC
#define AIN1_PIN   PINADC
#define AIN1_BIT   ADC6

#define PCINT7_DDR   DDRADC
#define PCINT7_PORT  PORTADC
#define PCINT7_PIN   PINADC
#define PCINT7_BIT   ADC6

#define PA7_DDR   DDRADC
#define PA7_PORT  PORTADC
#define PA7_PIN   PINADC
#define PA7_BIT   ADC6

#define AIN0_DDR   DDRADC
#define AIN0_PORT  PORTADC
#define AIN0_PIN   PINADC
#define AIN0_BIT   ADC5

#define PCINT6_DDR   DDRADC
#define PCINT6_PORT  PORTADC
#define PCINT6_PIN   PINADC
#define PCINT6_BIT   ADC5

#define PA6_DDR   DDRADC
#define PA6_PORT  PORTADC
#define PA6_PIN   PINADC
#define PA6_BIT   ADC5

#define AIN2_DDR   DDRADC
#define AIN2_PORT  PORTADC
#define AIN2_PIN   PINADC
#define AIN2_BIT   ADC4

#define PCINT5_DDR   DDRADC
#define PCINT5_PORT  PORTADC
#define PCINT5_PIN   PINADC
#define PCINT5_BIT   ADC4

#define PA5_DDR   DDRADC
#define PA5_PORT  PORTADC
#define PA5_PIN   PINADC
#define PA5_BIT   ADC4

#define ICP0_DDR   DDRADC
#define ICP0_PORT  PORTADC
#define ICP0_PIN   PINADC
#define ICP0_BIT   ADC3

#define PCINT4_DDR   DDRADC
#define PCINT4_PORT  PORTADC
#define PCINT4_PIN   PINADC
#define PCINT4_BIT   ADC3

#define PA4_DDR   DDRADC
#define PA4_PORT  PORTADC
#define PA4_PIN   PINADC
#define PA4_BIT   ADC3

#define PCINT3_DDR   DDRAREF
#define PCINT3_PORT  PORTAREF
#define PCINT3_PIN   PINAREF
#define PCINT3_BIT   AREF

#define PA3_DDR   DDRAREF
#define PA3_PORT  PORTAREF
#define PA3_PIN   PINAREF
#define PA3_BIT   AREF

#define INT1_DDR   DDRADC
#define INT1_PORT  PORTADC
#define INT1_PIN   PINADC
#define INT1_BIT   ADC2

#define USCK_A_DDR   DDRADC
#define USCK_A_PORT  PORTADC
#define USCK_A_PIN   PINADC
#define USCK_A_BIT   ADC2

#define SCL_A_DDR   DDRADC
#define SCL_A_PORT  PORTADC
#define SCL_A_PIN   PINADC
#define SCL_A_BIT   ADC2

#define PCINT2_DDR   DDRADC
#define PCINT2_PORT  PORTADC
#define PCINT2_PIN   PINADC
#define PCINT2_BIT   ADC2

#define PA2_DDR   DDRADC
#define PA2_PORT  PORTADC
#define PA2_PIN   PINADC
#define PA2_BIT   ADC2

#define DO_A_DDR   DDRADC
#define DO_A_PORT  PORTADC
#define DO_A_PIN   PINADC
#define DO_A_BIT   ADC1

#define PCINT1_DDR   DDRADC
#define PCINT1_PORT  PORTADC
#define PCINT1_PIN   PINADC
#define PCINT1_BIT   ADC1

#define PA1_DDR   DDRADC
#define PA1_PORT  PORTADC
#define PA1_PIN   PINADC
#define PA1_BIT   ADC1

#define DI_A_DDR   DDRADC
#define DI_A_PORT  PORTADC
#define DI_A_PIN   PINADC
#define DI_A_BIT   ADC0

#define SDA_A_DDR   DDRADC
#define SDA_A_PORT  PORTADC
#define SDA_A_PIN   PINADC
#define SDA_A_BIT   ADC0

#define PCINT0_DDR   DDRADC
#define PCINT0_PORT  PORTADC
#define PCINT0_PIN   PINADC
#define PCINT0_BIT   ADC0

#define PA0_DDR   DDRADC
#define PA0_PORT  PORTADC
#define PA0_PIN   PINADC
#define PA0_BIT   ADC0

#define SLEEP_MODE_IDLE (0x00<<3)
#define SLEEP_MODE_ADC (0x01<<3)
#define SLEEP_MODE_PWR_DOWN (0x02<<3)
#define SLEEP_MODE_STANDBY (0x03<<3)

#endif /* _AVR_ATtiny861A_H_ */

