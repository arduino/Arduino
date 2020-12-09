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

/* $Id: iotn40.h 2435 2014-08-11 10:31:52Z joerg_wunsch $ */

/* avr/iotn40.h - definitions for ATtiny40 */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn40.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATtiny40_H_
#define _AVR_ATtiny40_H_ 1


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
#define BBMC 2
#define ADC8D 4
#define ADC9D 5
#define ADC10D 6
#define ADC11D 7

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
#define PCIF2 6

#define GIMSK _SFR_IO8(0x0C)
#define INT0 0
#define PCIE0 4
#define PCIE1 5
#define PCIE2 6

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
#define PSR 4
#define TSM 5
#define FOC0B 6
#define FOC0A 7

#define TCCR0A _SFR_IO8(0x19)
#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

#define PCMSK2 _SFR_IO8(0x1A)
#define PCINT12 0
#define PCINT13 1
#define PCINT14 2
#define PCINT15 3
#define PCINT16 4
#define PCINT17 5

#define PINC _SFR_IO8(0x1B)
#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5

#define DDRC _SFR_IO8(0x1C)
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5

#define PORTC _SFR_IO8(0x1D)
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5

#define PUEC _SFR_IO8(0x1E)
#define PUEC0 0
#define PUEC1 1
#define PUEC2 2
#define PUEC3 3
#define PUEC4 4
#define PUEC5 5

#define RAMDR _SFR_IO8(0x1F)
#define RAMDR0 0
#define RAMDR1 1
#define RAMDR2 2
#define RAMDR3 3
#define RAMDR4 4
#define RAMDR5 5
#define RAMDR6 6
#define RAMDR7 7

#define RAMAR _SFR_IO8(0x20)
#define RAMAR0 0
#define RAMAR1 1
#define RAMAR2 2
#define RAMAR3 3
#define RAMAR4 4
#define RAMAR5 5
#define RAMAR6 6
#define RAMAR7 7

#define OCR1B _SFR_IO8(0x21)
#define OCR1B0 0
#define OCR1B1 1
#define OCR1B2 2
#define OCR1B3 3
#define OCR1B4 4
#define OCR1B5 5
#define OCR1B6 6
#define OCR1B7 7

#define OCR1A _SFR_IO8(0x22)
#define OCR1A0 0
#define OCR1A1 1
#define OCR1A2 2
#define OCR1A3 3
#define OCR1A4 4
#define OCR1A5 5
#define OCR1A6 6
#define OCR1A7 7

#define TCNT1L _SFR_IO8(0x23)
#define TCNT1_0 0
#define TCNT1_1 1
#define TCNT1_2 2
#define TCNT1_3 3
#define TCNT1_4 4
#define TCNT1_5 5
#define TCNT1_6 6
#define TCNT1_7 7

#define TCCR1A _SFR_IO8(0x24)
#define CS10 0
#define CS11 1
#define CS12 2
#define CTC1 3
#define ICES1 4
#define ICNC1 5
#define ICEN1 6
#define TCW1 7

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

#define TCNT1H _SFR_IO8(0x27)
#define TCNT1_8 0
#define TCNT1_9 1
#define TCNT1_10 2
#define TCNT1_11 3
#define TCNT1_12 4
#define TCNT1_13 5
#define TCNT1_14 6
#define TCNT1_15 7

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

#define SPSR _SFR_IO8(0x2F)

#define SPCR _SFR_IO8(0x30)

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

#define DWDR _SFR_IO8(0x38)

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
#define PCINT2_vect_num  4
#define PCINT2_vect      _VECTOR(4)  /* Pin Change Interrupt Request 2 */
#define WDT_vect_num  5
#define WDT_vect      _VECTOR(5)  /* Watchdog Time-out */
#define TIM1_CAPT_vect_num  6
#define TIM1_CAPT_vect      _VECTOR(6)  /* Timer/Counter1 Input Capture */
#define TIM1_COMPA_vect_num  7
#define TIM1_COMPA_vect      _VECTOR(7)  /*  Timer/Counter1 Compare Match A */
#define TIM1_COMPB_vect_num  8
#define TIM1_COMPB_vect      _VECTOR(8)  /*  Timer/Counter1 Compare Match B */
#define TIM1_OVF_vect_num  9
#define TIM1_OVF_vect      _VECTOR(9)  /* Timer/Counter1 Overflow */
#define TIM0_COMPA_vect_num  10
#define TIM0_COMPA_vect      _VECTOR(10)  /* Timer/Counter0 Compare Match A */
#define TIM0_COMPB_vect_num  11
#define TIM0_COMPB_vect      _VECTOR(11)  /* Timer/Counter0 Compare Match B */
#define TIM0_OVF_vect_num  12
#define TIM0_OVF_vect      _VECTOR(12)  /* Timer/Counter0 Overflow */
#define ANA_COMP_vect_num  13
#define ANA_COMP_vect      _VECTOR(13)  /* Analog Comparator */
#define ADC_vect_num  14
#define ADC_vect      _VECTOR(14)  /* Conversion Complete */
#define TWI_SLAVE_vect_num  15
#define TWI_SLAVE_vect      _VECTOR(15)  /* Two-Wire Interface */
#define SPI_vect_num  16
#define SPI_vect      _VECTOR(16)  /* Serial Peripheral Interface */
#define QTRIP_vect_num  17
#define QTRIP_vect      _VECTOR(17)  /* Touch Sensing */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (18 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (64)
#define RAMSTART     (0x40)
#define RAMSIZE      (256)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0x0)
#define E2PAGESIZE   (0)
#define FLASHEND     (0xFFF)


/* Fuses */
#define FUSE_MEMORY_SIZE 0


/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x92
#define SIGNATURE_2 0x0E


/* Device Pin Definitions */
#define ADC6_DDR   DDRCINT
#define ADC6_PORT  PORTCINT
#define ADC6_PIN   PINCINT
#define ADC6_BIT   INT6

#define ADC5_DDR   DDRCINT
#define ADC5_PORT  PORTCINT
#define ADC5_PIN   PINCINT
#define ADC5_BIT   INT5

#define OC0B_DDR   DDRCINT
#define OC0B_PORT  PORTCINT
#define OC0B_PIN   PINCINT
#define OC0B_BIT   INT5

#define ADC4_DDR   DDRCINT
#define ADC4_PORT  PORTCINT
#define ADC4_PIN   PINCINT
#define ADC4_BIT   INT4

#define T0_DDR   DDRCINT
#define T0_PORT  PORTCINT
#define T0_PIN   PINCINT
#define T0_BIT   INT4

#define ADC3_DDR   DDRPCINT
#define ADC3_PORT  PORTPCINT
#define ADC3_PIN   PINPCINT
#define ADC3_BIT   PCINT3

#define ADC2_DDR   DDRPCINT
#define ADC2_PORT  PORTPCINT
#define ADC2_PIN   PINPCINT
#define ADC2_BIT   PCINT2

#define AIN1_DDR   DDRPCINT
#define AIN1_PORT  PORTPCINT
#define AIN1_PIN   PINPCINT
#define AIN1_BIT   PCINT2

#define ADC1_DDR   DDRCINT
#define ADC1_PORT  PORTCINT
#define ADC1_PIN   PINCINT
#define ADC1_BIT   INT1

#define AIN0_DDR   DDRCINT
#define AIN0_PORT  PORTCINT
#define AIN0_PIN   PINCINT
#define AIN0_BIT   INT1

#define ADC0_DDR   DDRCINT
#define ADC0_PORT  PORTCINT
#define ADC0_PIN   PINCINT
#define ADC0_BIT   INT0

#define CLKI_DDR   DDRCINT1
#define CLKI_PORT  PORTCINT1
#define CLKI_PIN   PINCINT1
#define CLKI_BIT   INT17

#define SDA_DDR   DDRMOSI
#define SDA_PORT  PORTMOSI
#define SDA_PIN   PINMOSI
#define SDA_BIT   MOSI

#define PCINT16_DDR   DDRMOSI
#define PCINT16_PORT  PORTMOSI
#define PCINT16_PIN   PINMOSI
#define PCINT16_BIT   MOSI

#define PCINT15_DDR   DDRRESET
#define PCINT15_PORT  PORTRESET
#define PCINT15_PIN   PINRESET
#define PCINT15_BIT   RESET

#define CLKO_DDR   DDRINT
#define CLKO_PORT  PORTINT
#define CLKO_PIN   PININT
#define CLKO_BIT   INT0

#define MISO_DDR   DDRINT
#define MISO_PORT  PORTINT
#define MISO_PIN   PININT
#define MISO_BIT   INT0

#define PCINT14_DDR   DDRINT
#define PCINT14_PORT  PORTINT
#define PCINT14_PIN   PININT
#define PCINT14_BIT   INT0

#define SCL_DDR   DDRSCK
#define SCL_PORT  PORTSCK
#define SCL_PIN   PINSCK
#define SCL_BIT   SCK

#define ICP1_DDR   DDRSCK
#define ICP1_PORT  PORTSCK
#define ICP1_PIN   PINSCK
#define ICP1_BIT   SCK

#define T1_DDR   DDRSCK
#define T1_PORT  PORTSCK
#define T1_PIN   PINSCK
#define T1_BIT   SCK

#define PCINT13_DDR   DDRSCK
#define PCINT13_PORT  PORTSCK
#define PCINT13_PIN   PINSCK
#define PCINT13_BIT   SCK

#define SS_DDR   DDROC0A
#define SS_PORT  PORTOC0A
#define SS_PIN   PINOC0A
#define SS_BIT   OC0A

#define PCINT12_DDR   DDROC0A
#define PCINT12_PORT  PORTOC0A
#define PCINT12_PIN   PINOC0A
#define PCINT12_BIT   OC0A

#define PCINT11_DDR   DDRADC1
#define PCINT11_PORT  PORTADC1
#define PCINT11_PIN   PINADC1
#define PCINT11_BIT   ADC11

#define PCINT10_DDR   DDRADC1
#define PCINT10_PORT  PORTADC1
#define PCINT10_PIN   PINADC1
#define PCINT10_BIT   ADC10

#define PCINT9_DDR   DDRADC9
#define PCINT9_PORT  PORTADC9
#define PCINT9_PIN   PINADC9
#define PCINT9_BIT   ADC9

#define PCINT8_DDR   DDRADC
#define PCINT8_PORT  PORTADC
#define PCINT8_PIN   PINADC
#define PCINT8_BIT   ADC8

#define PCINT7_DDR   DDRADC
#define PCINT7_PORT  PORTADC
#define PCINT7_PIN   PINADC
#define PCINT7_BIT   ADC7

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_STANDBY (0x04<<1)

#endif /* _AVR_ATtiny40_H_ */

