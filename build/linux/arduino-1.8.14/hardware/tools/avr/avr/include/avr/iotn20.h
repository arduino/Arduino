/* Copyright (c) 2010 Atmel Corporation
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

/* $Id$ */

/* avr/iotn20.h - definitions for ATtiny20 */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn20.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATtiny20_H_
#define _AVR_ATtiny20_H_ 1


/* Registers and associated bit numbers. */

#define PINA _SFR_IO8(0x00)
#define PINA0 0
#define PINA1 1
#define PINA2 2
#define PINA3 3
#define PINA4 4
#define PINA5 5
#define PINA6 6
#define PINA7 7

#define DDRA _SFR_IO8(0x01)
#define DDA0 0
#define DDA1 1
#define DDA2 2
#define DDA3 3
#define DDA4 4
#define DDA5 5
#define DDA6 6
#define DDA7 7

#define PORTA _SFR_IO8(0x02)
#define PORTA0 0
#define PORTA1 1
#define PORTA2 2
#define PORTA3 3
#define PORTA4 4
#define PORTA5 5
#define PORTA6 6
#define PORTA7 7

#define PUEA _SFR_IO8(0x03)
#define PUEA0 0
#define PUEA1 1
#define PUEA2 2
#define PUEA3 3
#define PUEA4 4
#define PUEA5 5
#define PUEA6 6
#define PUEA7 7

#define PINB _SFR_IO8(0x04)
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3

#define DDRB _SFR_IO8(0x05)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3

#define PORTB _SFR_IO8(0x06)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3

#define PUEB _SFR_IO8(0x07)
#define PUEB0 0
#define PUEB1 1
#define PUEB2 2
#define PUEB3 3

#define PORTCR _SFR_IO8(0x08)
#define BBMA 0
#define BBMB 1

#define PCMSK0 _SFR_IO8(0x09)
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define PCMSK1 _SFR_IO8(0x0A)
#define PCINT8 0
#define PCINT9 1
#define PCINT10 2
#define PCINT11 3

#define GIFR _SFR_IO8(0x0B)
#define INTF0 0
#define PCIF0 4
#define PCIF1 5

#define GIMSK _SFR_IO8(0x0C)
#define INT0 0
#define PCIE0 4
#define PCIE1 5

#define DIDR0 _SFR_IO8(0x0D)
#define ADC0D 0
#define ADC1D 1
#define ADC2D 2
#define ADC3D 3
#define ADC4D 4
#define ADC5D 5
#define ADC6D 6
#define ADC7D 7

#ifndef __ASSEMBLER__
#define ADC _SFR_IO16(0x0E)
#endif
#define ADCW _SFR_IO16(0x0E)

#define ADCL _SFR_IO8(0x0E)
#define ADCL0 0
#define ADCL1 1
#define ADCL2 2
#define ADCL3 3
#define ADCL4 4
#define ADCL5 5
#define ADCL6 6
#define ADCL7 7

#define ADCH _SFR_IO8(0x0F)
#define ADCH0 0
#define ADCH1 1
#define ADCH2 2
#define ADCH3 3
#define ADCH4 4
#define ADCH5 5
#define ADCH6 6
#define ADCH7 7

#define ADMUX _SFR_IO8(0x10)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define REFS 6

#define ADCSRB _SFR_IO8(0x11)
#define ADTS0 0
#define ADTS1 1
#define ADTS2 2
#define ADLAR 3

#define ADCSRA _SFR_IO8(0x12)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ACSRB _SFR_IO8(0x13)
#define ACME 2
#define HLEV 6
#define HSEL 7

#define ACSRA _SFR_IO8(0x14)
#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACBG 6
#define ACD 7

#define OCR0B _SFR_IO8(0x15)
#define OCR0B_0 0
#define OCR0B_1 1
#define OCR0B_2 2
#define OCR0B_3 3
#define OCR0B_4 4
#define OCR0B_5 5
#define OCR0B_6 6
#define OCR0B_7 7

#define OCR0A _SFR_IO8(0x16)
#define OCR0_0 0
#define OCR0_1 1
#define OCR0_2 2
#define OCR0_3 3
#define OCR0_4 4
#define OCR0_5 5
#define OCR0_6 6
#define OCR0_7 7

#define TCNT0 _SFR_IO8(0x17)
#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define TCCR0B _SFR_IO8(0x18)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM02 3
#define FOC0B 6
#define FOC0A 7

#define TCCR0A _SFR_IO8(0x19)
#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

#define ICR1 _SFR_IO16(0x1A)

#define ICR1L _SFR_IO8(0x1A)
#define ICR1_0 0
#define ICR1_1 1
#define ICR1_2 2
#define ICR1_3 3
#define ICR1_4 4
#define ICR1_5 5
#define ICR1_6 6
#define ICR1_7 7

#define ICR1H _SFR_IO8(0x1B)
#define ICR1_8 0
#define ICR1_9 1
#define ICR1_10 2
#define ICR1_11 3
#define ICR1_12 4
#define ICR1_13 5
#define ICR1_14 6
#define ICR1_15 7

#define OCR1B _SFR_IO16(0x1C)

#define OCR1BL _SFR_IO8(0x1C)
#define OCR1B0 0
#define OCR1B1 1
#define OCR1B2 2
#define OCR1B3 3
#define OCR1B4 4
#define OCR1B5 5
#define OCR1B6 6
#define OCR1B7 7

#define OCR1BH _SFR_IO8(0x1D)
#define OCR1B8 0
#define OCR1B9 1
#define OCR1B10 2
#define OCR1B11 3
#define OCR1B12 4
#define OCR1B13 5
#define OCR1B14 6
#define OCR1B15 7

#define OCR1A _SFR_IO16(0x1E)

#define OCR1AL _SFR_IO8(0x1E)
#define OCR1A0 0
#define OCR1A1 1
#define OCR1A2 2
#define OCR1A3 3
#define OCR1A4 4
#define OCR1A5 5
#define OCR1A6 6
#define OCR1A7 7

#define OCR1AH _SFR_IO8(0x1F)
#define OCR1A8 0
#define OCR1A9 1
#define OCR1A10 2
#define OCR1A11 3
#define OCR1A12 4
#define OCR1A13 5
#define OCR1A14 6
#define OCR1A15 7

#define TCNT1 _SFR_IO16(0x20)

#define TCNT1L _SFR_IO8(0x20)
#define TCNT1_0 0
#define TCNT1_1 1
#define TCNT1_2 2
#define TCNT1_3 3
#define TCNT1_4 4
#define TCNT1_5 5
#define TCNT1_6 6
#define TCNT1_7 7

#define TCNT1H _SFR_IO8(0x21)
#define TCNT1_8 0
#define TCNT1_9 1
#define TCNT1_10 2
#define TCNT1_11 3
#define TCNT1_12 4
#define TCNT1_13 5
#define TCNT1_14 6
#define TCNT1_15 7

#define TCCR1C _SFR_IO8(0x22)
#define FOC1B 6
#define FOC1A 7

#define TCCR1B _SFR_IO8(0x23)
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define TCCR1A _SFR_IO8(0x24)
#define WGM10 0
#define WGM11 1
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TIFR _SFR_IO8(0x25)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2
#define TOV1 3
#define OCF1A 4
#define OCF1B 5
#define ICF1 7

#define TIMSK _SFR_IO8(0x26)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2
#define TOIE1 3
#define OCIE1A 4
#define OCIE1B 5
#define ICIE1 7

#define GTCCR _SFR_IO8(0x27)
#define PSR 0
#define TSM 7

#define TWSD _SFR_IO8(0x28)
#define TWSD0 0
#define TWSD1 1
#define TWSD2 2
#define TWSD3 3
#define TWSD4 4
#define TWSD5 5
#define TWSD6 6
#define TWSD7 7

#define TWSAM _SFR_IO8(0x29)
#define TWAE 0
#define TWSAM1 1
#define TWSAM2 2
#define TWSAM3 3
#define TWSAM4 4
#define TWSAM5 5
#define TWSAM6 6
#define TWSAM7 7

#define TWSA _SFR_IO8(0x2A)
#define TWSA0 0
#define TWSA1 1
#define TWSA2 2
#define TWSA3 3
#define TWSA4 4
#define TWSA5 5
#define TWSA6 6
#define TWSA7 7

#define TWSSRA _SFR_IO8(0x2B)
#define TWAS 0
#define TWDIR 1
#define TWBE 2
#define TWC 3
#define TWRA 4
#define TWCH 5
#define TWASIF 6
#define TWDIF 7

#define TWSCRB _SFR_IO8(0x2C)
#define TWCMD0 0
#define TWCMD1 1
#define TWAA 2

#define TWSCRA _SFR_IO8(0x2D)
#define TWSME 0
#define TWPME 1
#define TWSIE 2
#define TWEN 3
#define TWASIE 4
#define TWDIE 5
#define TWSHE 7

#define SPDR _SFR_IO8(0x2E)
#define SPDR0 0
#define SPDR1 1
#define SPDR2 2
#define SPDR3 3
#define SPDR4 4
#define SPDR5 5
#define SPDR6 6
#define SPDR7 7

#define SPSR _SFR_IO8(0x2F)
#define SPI2X 0
#define WCOL 6
#define SPIF 7

#define SPCR _SFR_IO8(0x30)
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

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

#define QTCSR _SFR_IO8(0x34)

#define PRR _SFR_IO8(0x35)
#define PRADC 0
#define PRTIM0 1
#define PRTIM1 2
#define PRSPI 3
#define PRTWI 4

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRTWI))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTWI

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

#define MCUCR _SFR_IO8(0x3A)
#define SE 0
#define SM0 1
#define SM1 2
#define SM2 3
#define BODS 4
#define ISC00 6
#define ISC01 7

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
#define PCINT1_vect_num  3
#define PCINT1_vect      _VECTOR(3)  /* Pin Change Interrupt Request 1 */
#define WDT_vect_num  4
#define WDT_vect      _VECTOR(4)  /* Watchdog Time-out */
#define TIM1_CAPT_vect_num  5
#define TIM1_CAPT_vect      _VECTOR(5)  /* Timer/Counter1 Input Capture */
#define TIM1_COMPA_vect_num  6
#define TIM1_COMPA_vect      _VECTOR(6)  /*  Timer/Counter1 Compare Match A */
#define TIM1_COMPB_vect_num  7
#define TIM1_COMPB_vect      _VECTOR(7)  /*  Timer/Counter1 Compare Match B */
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
#define ADC_ADC_vect_num  13
#define ADC_ADC_vect      _VECTOR(13)  /* Conversion Complete */
#define TWI_SLAVE_vect_num  14
#define TWI_SLAVE_vect      _VECTOR(14)  /* Two-Wire Interface */
#define SPI_vect_num  15
#define SPI_vect      _VECTOR(15)  /* Serial Peripheral Interface */
#define QTRIP_vect_num  16
#define QTRIP_vect      _VECTOR(16)  /* Touch Sensing */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (17 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (64)
#define RAMSTART     (0x40)
#define RAMSIZE      (128)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0x0)
#define E2PAGESIZE   (0)
#define FLASHEND     (0x7FF)


/* Fuses */
#define FUSE_MEMORY_SIZE 0


/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x91
#define SIGNATURE_2 0x0F


/* Device Pin Definitions */
#define ADC4_DDR   DDRCINT
#define ADC4_PORT  PORTCINT
#define ADC4_PIN   PINCINT
#define ADC4_BIT   INT4

#define ADC3_DDR   DDRCINT
#define ADC3_PORT  PORTCINT
#define ADC3_PIN   PINCINT
#define ADC3_BIT   INT3

#define AIN1_DDR   DDRCINT
#define AIN1_PORT  PORTCINT
#define AIN1_PIN   PINCINT
#define AIN1_BIT   INT2

#define ADC2_DDR   DDRCINT
#define ADC2_PORT  PORTCINT
#define ADC2_PIN   PINCINT
#define ADC2_BIT   INT2

#define AIN0_DDR   DDRCINT
#define AIN0_PORT  PORTCINT
#define AIN0_PIN   PINCINT
#define AIN0_BIT   INT1

#define ADC1_DDR   DDRCINT
#define ADC1_PORT  PORTCINT
#define ADC1_PIN   PINCINT
#define ADC1_BIT   INT1

#define ADC0_DDR   DDRCINT
#define ADC0_PORT  PORTCINT
#define ADC0_PIN   PINCINT
#define ADC0_BIT   INT0

#define T0_DDR   DDRCLKI
#define T0_PORT  PORTCLKI
#define T0_PIN   PINCLKI
#define T0_BIT   CLKI

#define TPICLK_DDR   DDRCLKI
#define TPICLK_PORT  PORTCLKI
#define TPICLK_PIN   PINCLKI
#define TPICLK_BIT   CLKI

#define PCINT8_DDR   DDRCLKI
#define PCINT8_PORT  PORTCLKI
#define PCINT8_PIN   PINCLKI
#define PCINT8_BIT   CLKI

#define SDA_DDR   DDROC1A
#define SDA_PORT  PORTOC1A
#define SDA_PIN   PINOC1A
#define SDA_BIT   OC1A

#define MOSI_DDR   DDROC1A
#define MOSI_PORT  PORTOC1A
#define MOSI_PIN   PINOC1A
#define MOSI_BIT   OC1A

#define TPIDATA_DDR   DDROC1A
#define TPIDATA_PORT  PORTOC1A
#define TPIDATA_PIN   PINOC1A
#define TPIDATA_BIT   OC1A

#define PCINT9_DDR   DDROC1A
#define PCINT9_PORT  PORTOC1A
#define PCINT9_PIN   PINOC1A
#define PCINT9_BIT   OC1A

#define PCINT11_DDR   DDRRESET
#define PCINT11_PORT  PORTRESET
#define PCINT11_PIN   PINRESET
#define PCINT11_BIT   RESET

#define OC0A_DDR   DDRCKOUT
#define OC0A_PORT  PORTCKOUT
#define OC0A_PIN   PINCKOUT
#define OC0A_BIT   CKOUT

#define OC1B_DDR   DDRCKOUT
#define OC1B_PORT  PORTCKOUT
#define OC1B_PIN   PINCKOUT
#define OC1B_BIT   CKOUT

#define MISO_DDR   DDRCKOUT
#define MISO_PORT  PORTCKOUT
#define MISO_PIN   PINCKOUT
#define MISO_BIT   CKOUT

#define INT0_DDR   DDRCKOUT
#define INT0_PORT  PORTCKOUT
#define INT0_PIN   PINCKOUT
#define INT0_BIT   CKOUT

#define PCINT10_DDR   DDRCKOUT
#define PCINT10_PORT  PORTCKOUT
#define PCINT10_PIN   PINCKOUT
#define PCINT10_BIT   CKOUT

#define OC0B_DDR   DDR(ADC
#define OC0B_PORT  PORT(ADC
#define OC0B_PIN   PIN(ADC
#define OC0B_BIT   (ADC7

#define ICP1_DDR   DDR(ADC
#define ICP1_PORT  PORT(ADC
#define ICP1_PIN   PIN(ADC
#define ICP1_BIT   (ADC7

#define T1_DDR   DDR(ADC
#define T1_PORT  PORT(ADC
#define T1_PIN   PIN(ADC
#define T1_BIT   (ADC7

#define SCL_DDR   DDR(ADC
#define SCL_PORT  PORT(ADC
#define SCL_PIN   PIN(ADC
#define SCL_BIT   (ADC7

#define SCK_DDR   DDR(ADC
#define SCK_PORT  PORT(ADC
#define SCK_PIN   PIN(ADC
#define SCK_BIT   (ADC7

#define PCINT7_DDR   DDR(ADC
#define PCINT7_PORT  PORT(ADC
#define PCINT7_PIN   PIN(ADC
#define PCINT7_BIT   (ADC7

#define SS_DDR   DDRADC
#define SS_PORT  PORTADC
#define SS_PIN   PINADC
#define SS_BIT   ADC6

#define PCINT6_DDR   DDRADC
#define PCINT6_PORT  PORTADC
#define PCINT6_PIN   PINADC
#define PCINT6_BIT   ADC6

#define PCINT5_DDR   DDRADC
#define PCINT5_PORT  PORTADC
#define PCINT5_PIN   PINADC
#define PCINT5_BIT   ADC5

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_STANDBY (0x04<<1)

#endif /* _AVR_ATtiny20_H_ */

