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

/* $Id: iom88pa.h 2035 2009-11-02 02:44:17Z arcanum $ */

/* avr/iom88pa.h - definitions for ATmega88PA */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom88pa.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATmega88PA_H_
#define _AVR_ATmega88PA_H_ 1


/* Registers and associated bit numbers. */

#define PINB _SFR_IO8(0x03)
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

#define DDRB _SFR_IO8(0x04)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB _SFR_IO8(0x05)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

#define PINC _SFR_IO8(0x06)
#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6

#define DDRC _SFR_IO8(0x07)
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6

#define PORTC _SFR_IO8(0x08)
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6

#define PIND _SFR_IO8(0x09)
#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7

#define DDRD _SFR_IO8(0x0A)
#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7

#define PORTD _SFR_IO8(0x0B)
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7

#define TIFR0 _SFR_IO8(0x15)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2

#define TIFR1 _SFR_IO8(0x16)
#define TOV1 0
#define OCF1A 1
#define OCF1B 2
#define ICF1 5

#define TIFR2 _SFR_IO8(0x17)
#define TOV2 0
#define OCF2A 1
#define OCF2B 2

#define PCIFR _SFR_IO8(0x1B)
#define PCIF0 0
#define PCIF1 1
#define PCIF2 2

#define EIFR _SFR_IO8(0x1C)
#define INTF0 0
#define INTF1 1

#define EIMSK _SFR_IO8(0x1D)
#define INT0 0
#define INT1 1

#define GPIOR0 _SFR_IO8(0x1E)
#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define EECR _SFR_IO8(0x1F)
#define EERE 0
#define EEPE 1
#define EEMPE 2
#define EERIE 3
#define EEPM0 4
#define EEPM1 5

#define EEDR _SFR_IO8(0x20)
#define EEDR0 0
#define EEDR1 1
#define EEDR2 2
#define EEDR3 3
#define EEDR4 4
#define EEDR5 5
#define EEDR6 6
#define EEDR7 7

#define EEAR _SFR_IO16(0x21)

#define EEARL _SFR_IO8(0x21)
#define EEAR0 0
#define EEAR1 1
#define EEAR2 2
#define EEAR3 3
#define EEAR4 4
#define EEAR5 5
#define EEAR6 6
#define EEAR7 7

#define EEARH _SFR_IO8(0x22)
#define EEAR8 0

#define GTCCR _SFR_IO8(0x23)
#define PSRSYNC 0
#define PSRASY 1
#define TSM 7

#define TCCR0A _SFR_IO8(0x24)
#define WGM00 0
#define WGM01 1
#define COM0B0 4
#define COM0B1 5
#define COM0A0 6
#define COM0A1 7

#define TCCR0B _SFR_IO8(0x25)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM02 3
#define FOC0B 6
#define FOC0A 7

#define TCNT0 _SFR_IO8(0x26)
#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define OCR0A _SFR_IO8(0x27)
#define OCR0A_0 0
#define OCR0A_1 1
#define OCR0A_2 2
#define OCR0A_3 3
#define OCR0A_4 4
#define OCR0A_5 5
#define OCR0A_6 6
#define OCR0A_7 7

#define OCR0B _SFR_IO8(0x28)
#define OCR0B_0 0
#define OCR0B_1 1
#define OCR0B_2 2
#define OCR0B_3 3
#define OCR0B_4 4
#define OCR0B_5 5
#define OCR0B_6 6
#define OCR0B_7 7

#define GPIOR1 _SFR_IO8(0x2A)
#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR2 _SFR_IO8(0x2B)
#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

#define SPCR _SFR_IO8(0x2C)
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

#define SPSR _SFR_IO8(0x2D)
#define SPI2X 0
#define WCOL 6
#define SPIF 7

#define SPDR _SFR_IO8(0x2E)
#define SPDR0 0
#define SPDR1 1
#define SPDR2 2
#define SPDR3 3
#define SPDR4 4
#define SPDR5 5
#define SPDR6 6
#define SPDR7 7

#define ACSR _SFR_IO8(0x30)
#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACBG 6
#define ACD 7

#define SMCR _SFR_IO8(0x33)
#define SE 0
#define SM0 1
#define SM1 2
#define SM2 3

#define MCUSR _SFR_IO8(0x34)
#define PORF 0
#define EXTRF 1
#define BORF 2
#define WDRF 3

#define MCUCR _SFR_IO8(0x35)
#define IVCE 0
#define IVSEL 1
#define PUD 4
#define BODSE 5
#define BODS 6

#define SPMCSR _SFR_IO8(0x37)
#define SELFPRGEN 0
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define BLBSET 3
#define RWWSRE 4
#define SIGRD 5
#define RWWSB 6
#define SPMIE 7

#define WDTCSR _SFR_MEM8(0x60)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDCE 4
#define WDP3 5
#define WDIE 6
#define WDIF 7

#define CLKPR _SFR_MEM8(0x61)
#define CLKPS0 0
#define CLKPS1 1
#define CLKPS2 2
#define CLKPS3 3
#define CLKPCE 7

#define PRR _SFR_MEM8(0x64)
#define PRADC 0
#define PRUSART0 1
#define PRSPI 2
#define PRTIM1 3
#define PRTIM0 5
#define PRTIM2 6
#define PRTWI 7

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM2
#define __AVR_HAVE_PRR_PRTWI

#define OSCCAL _SFR_MEM8(0x66)
#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define PCICR _SFR_MEM8(0x68)
#define PCIE0 0
#define PCIE1 1
#define PCIE2 2

#define EICRA _SFR_MEM8(0x69)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define PCMSK0 _SFR_MEM8(0x6B)
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define PCMSK1 _SFR_MEM8(0x6C)
#define PCINT8 0
#define PCINT9 1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6

#define PCMSK2 _SFR_MEM8(0x6D)
#define PCINT16 0
#define PCINT17 1
#define PCINT18 2
#define PCINT19 3
#define PCINT20 4
#define PCINT21 5
#define PCINT22 6
#define PCINT23 7

#define TIMSK0 _SFR_MEM8(0x6E)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2

#define TIMSK1 _SFR_MEM8(0x6F)
#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define ICIE1 5

#define TIMSK2 _SFR_MEM8(0x70)
#define TOIE2 0
#define OCIE2A 1
#define OCIE2B 2

#ifndef __ASSEMBLER__
#define ADC _SFR_MEM16(0x78)
#endif
#define ADCW _SFR_MEM16(0x78)

#define ADCL _SFR_MEM8(0x78)
#define ADCL0 0
#define ADCL1 1
#define ADCL2 2
#define ADCL3 3
#define ADCL4 4
#define ADCL5 5
#define ADCL6 6
#define ADCL7 7

#define ADCH _SFR_MEM8(0x79)
#define ADCH0 0
#define ADCH1 1
#define ADCH2 2
#define ADCH3 3
#define ADCH4 4
#define ADCH5 5
#define ADCH6 6
#define ADCH7 7

#define ADCSRA _SFR_MEM8(0x7A)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ADCSRB _SFR_MEM8(0x7B)
#define ADTS0 0
#define ADTS1 1
#define ADTS2 2
#define ACME 6

#define ADMUX _SFR_MEM8(0x7C)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define DIDR0 _SFR_MEM8(0x7E)
#define ADC0D 0
#define ADC1D 1
#define ADC2D 2
#define ADC3D 3
#define ADC4D 4
#define ADC5D 5

#define DIDR1 _SFR_MEM8(0x7F)
#define AIN0D 0
#define AIN1D 1

#define TCCR1A _SFR_MEM8(0x80)
#define WGM10 0
#define WGM11 1
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define TCCR1B _SFR_MEM8(0x81)
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define TCCR1C _SFR_MEM8(0x82)
#define FOC1B 6
#define FOC1A 7

#define TCNT1 _SFR_MEM16(0x84)

#define TCNT1L _SFR_MEM8(0x84)
#define TCNT1L0 0
#define TCNT1L1 1
#define TCNT1L2 2
#define TCNT1L3 3
#define TCNT1L4 4
#define TCNT1L5 5
#define TCNT1L6 6
#define TCNT1L7 7

#define TCNT1H _SFR_MEM8(0x85)
#define TCNT1H0 0
#define TCNT1H1 1
#define TCNT1H2 2
#define TCNT1H3 3
#define TCNT1H4 4
#define TCNT1H5 5
#define TCNT1H6 6
#define TCNT1H7 7

#define ICR1 _SFR_MEM16(0x86)

#define ICR1L _SFR_MEM8(0x86)
#define ICR1L0 0
#define ICR1L1 1
#define ICR1L2 2
#define ICR1L3 3
#define ICR1L4 4
#define ICR1L5 5
#define ICR1L6 6
#define ICR1L7 7

#define ICR1H _SFR_MEM8(0x87)
#define ICR1H0 0
#define ICR1H1 1
#define ICR1H2 2
#define ICR1H3 3
#define ICR1H4 4
#define ICR1H5 5
#define ICR1H6 6
#define ICR1H7 7

#define OCR1A _SFR_MEM16(0x88)

#define OCR1AL _SFR_MEM8(0x88)
#define OCR1AL0 0
#define OCR1AL1 1
#define OCR1AL2 2
#define OCR1AL3 3
#define OCR1AL4 4
#define OCR1AL5 5
#define OCR1AL6 6
#define OCR1AL7 7

#define OCR1AH _SFR_MEM8(0x89)
#define OCR1AH0 0
#define OCR1AH1 1
#define OCR1AH2 2
#define OCR1AH3 3
#define OCR1AH4 4
#define OCR1AH5 5
#define OCR1AH6 6
#define OCR1AH7 7

#define OCR1B _SFR_MEM16(0x8A)

#define OCR1BL _SFR_MEM8(0x8A)
#define OCR1BL0 0
#define OCR1BL1 1
#define OCR1BL2 2
#define OCR1BL3 3
#define OCR1BL4 4
#define OCR1BL5 5
#define OCR1BL6 6
#define OCR1BL7 7

#define OCR1BH _SFR_MEM8(0x8B)
#define OCR1BH0 0
#define OCR1BH1 1
#define OCR1BH2 2
#define OCR1BH3 3
#define OCR1BH4 4
#define OCR1BH5 5
#define OCR1BH6 6
#define OCR1BH7 7

#define TCCR2A _SFR_MEM8(0xB0)
#define WGM20 0
#define WGM21 1
#define COM2B0 4
#define COM2B1 5
#define COM2A0 6
#define COM2A1 7

#define TCCR2B _SFR_MEM8(0xB1)
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM22 3
#define FOC2B 6
#define FOC2A 7

#define TCNT2 _SFR_MEM8(0xB2)
#define TCNT2_0 0
#define TCNT2_1 1
#define TCNT2_2 2
#define TCNT2_3 3
#define TCNT2_4 4
#define TCNT2_5 5
#define TCNT2_6 6
#define TCNT2_7 7

#define OCR2A _SFR_MEM8(0xB3)
#define OCR2A_0 0
#define OCR2A_1 1
#define OCR2A_2 2
#define OCR2A_3 3
#define OCR2A_4 4
#define OCR2A_5 5
#define OCR2A_6 6
#define OCR2A_7 7

#define OCR2B _SFR_MEM8(0xB4)
#define OCR2B_0 0
#define OCR2B_1 1
#define OCR2B_2 2
#define OCR2B_3 3
#define OCR2B_4 4
#define OCR2B_5 5
#define OCR2B_6 6
#define OCR2B_7 7

#define ASSR _SFR_MEM8(0xB6)
#define TCR2BUB 0
#define TCR2AUB 1
#define OCR2BUB 2
#define OCR2AUB 3
#define TCN2UB 4
#define AS2 5
#define EXCLK 6

#define TWBR _SFR_MEM8(0xB8)
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

#define TWSR _SFR_MEM8(0xB9)
#define TWPS0 0
#define TWPS1 1
#define TWS3 3
#define TWS4 4
#define TWS5 5
#define TWS6 6
#define TWS7 7

#define TWAR _SFR_MEM8(0xBA)
#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7

#define TWDR _SFR_MEM8(0xBB)
#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7

#define TWCR _SFR_MEM8(0xBC)
#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

#define TWAMR _SFR_MEM8(0xBD)
#define TWAM0 1
#define TWAM1 2
#define TWAM2 3
#define TWAM3 4
#define TWAM4 5
#define TWAM5 6
#define TWAM6 7

#define UCSR0A _SFR_MEM8(0xC0)
#define MPCM0 0
#define U2X0 1
#define UPE0 2
#define DOR0 3
#define FE0 4
#define UDRE0 5
#define TXC0 6
#define RXC0 7

#define UCSR0B _SFR_MEM8(0xC1)
#define TXB80 0
#define RXB80 1
#define UCSZ02 2
#define TXEN0 3
#define RXEN0 4
#define UDRIE0 5
#define TXCIE0 6
#define RXCIE0 7

#define UCSR0C _SFR_MEM8(0xC2)
#define UCPOL0 0
#define UCSZ00 1
#define UCSZ01 2
#define USBS0 3
#define UPM00 4
#define UPM01 5
#define UMSEL00 6
#define UMSEL01 7

#define UBRR0 _SFR_MEM16(0xC4)

#define UBRR0L _SFR_MEM8(0xC4)
#define _UBRR0 0
#define _UBRR1 1
#define UBRR2 2
#define UBRR3 3
#define UBRR4 4
#define UBRR5 5
#define UBRR6 6
#define UBRR7 7

#define UBRR0H _SFR_MEM8(0xC5)
#define UBRR8 0
#define UBRR9 1
#define UBRR10 2
#define UBRR11 3

#define UDR0 _SFR_MEM8(0xC6)
#define UDR0_0 0
#define UDR0_1 1
#define UDR0_2 2
#define UDR0_3 3
#define UDR0_4 4
#define UDR0_5 5
#define UDR0_6 6
#define UDR0_7 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt Request 0 */
#define INT1_vect_num  2
#define INT1_vect      _VECTOR(2)  /* External Interrupt Request 1 */
#define PCINT0_vect_num  3
#define PCINT0_vect      _VECTOR(3)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect_num  4
#define PCINT1_vect      _VECTOR(4)  /* Pin Change Interrupt Request 0 */
#define PCINT2_vect_num  5
#define PCINT2_vect      _VECTOR(5)  /* Pin Change Interrupt Request 1 */
#define WDT_vect_num  6
#define WDT_vect      _VECTOR(6)  /* Watchdog Time-out Interrupt */
#define TIMER2_COMPA_vect_num  7
#define TIMER2_COMPA_vect      _VECTOR(7)  /* Timer/Counter2 Compare Match A */
#define TIMER2_COMPB_vect_num  8
#define TIMER2_COMPB_vect      _VECTOR(8)  /* Timer/Counter2 Compare Match A */
#define TIMER2_OVF_vect_num  9
#define TIMER2_OVF_vect      _VECTOR(9)  /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect_num  10
#define TIMER1_CAPT_vect      _VECTOR(10)  /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect_num  11
#define TIMER1_COMPA_vect      _VECTOR(11)  /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect_num  12
#define TIMER1_COMPB_vect      _VECTOR(12)  /* Timer/Counter1 Compare Match B */
#define TIMER1_OVF_vect_num  13
#define TIMER1_OVF_vect      _VECTOR(13)  /* Timer/Counter1 Overflow */
#define TIMER0_COMPA_vect_num  14
#define TIMER0_COMPA_vect      _VECTOR(14)  /* TimerCounter0 Compare Match A */
#define TIMER0_COMPB_vect_num  15
#define TIMER0_COMPB_vect      _VECTOR(15)  /* TimerCounter0 Compare Match B */
#define TIMER0_OVF_vect_num  16
#define TIMER0_OVF_vect      _VECTOR(16)  /* Timer/Couner0 Overflow */
#define SPI_STC_vect_num  17
#define SPI_STC_vect      _VECTOR(17)  /* SPI Serial Transfer Complete */
#define USART_RX_vect_num  18
#define USART_RX_vect      _VECTOR(18)  /* USART Rx Complete */
#define USART_UDRE_vect_num  19
#define USART_UDRE_vect      _VECTOR(19)  /* USART, Data Register Empty */
#define USART_TX_vect_num  20
#define USART_TX_vect      _VECTOR(20)  /* USART Tx Complete */
#define ADC_vect_num  21
#define ADC_vect      _VECTOR(21)  /* ADC Conversion Complete */
#define EE_READY_vect_num  22
#define EE_READY_vect      _VECTOR(22)  /* EEPROM Ready */
#define ANALOG_COMP_vect_num  23
#define ANALOG_COMP_vect      _VECTOR(23)  /* Analog Comparator */
#define TWI_vect_num  24
#define TWI_vect      _VECTOR(24)  /* Two-wire Serial Interface */
#define SPM_Ready_vect_num  25
#define SPM_Ready_vect      _VECTOR(25)  /* Store Program Memory Read */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (26 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (64)
#define RAMSTART     (0x100)
#define RAMSIZE      (1024)
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
#define FUSE_CKSEL0  (unsigned char)~_BV(0)  /* Select Clock Source */
#define FUSE_CKSEL1  (unsigned char)~_BV(1)  /* Select Clock Source */
#define FUSE_CKSEL2  (unsigned char)~_BV(2)  /* Select Clock Source */
#define FUSE_CKSEL3  (unsigned char)~_BV(3)  /* Select Clock Source */
#define FUSE_SUT0  (unsigned char)~_BV(4)  /* Select start-up time */
#define FUSE_SUT1  (unsigned char)~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT  (unsigned char)~_BV(6)  /* Clock output */
#define FUSE_CKDIV8  (unsigned char)~_BV(7)  /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKDIV8 & FUSE_SUT0 & FUSE_CKSEL3 & FUSE_CKSEL2 & FUSE_CKSEL0)

/* High Fuse Byte */
#define FUSE_BODLEVEL0  (unsigned char)~_BV(0)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1  (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2  (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
#define FUSE_EESAVE  (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON  (unsigned char)~_BV(4)  /* Watchdog Timer Always On */
#define FUSE_SPIEN  (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_DWEN  (unsigned char)~_BV(6)  /* debugWIRE Enable */
#define FUSE_RSTDISBL  (unsigned char)~_BV(7)  /* External reset disable */
#define HFUSE_DEFAULT (FUSE_SPIEN)

/* Extended Fuse Byte */
#define FUSE_BOOTRST  (unsigned char)~_BV(0)  /* Select reset vector */
#define FUSE_BOOTSZ0  (unsigned char)~_BV(1)  /* Select boot size */
#define FUSE_BOOTSZ1  (unsigned char)~_BV(2)  /* Select boot size */
#define EFUSE_DEFAULT (FUSE_BOOTSZ1 & FUSE_BOOTSZ0)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x0F


/* Device Pin Definitions */
#define PCINT19_DDR   DDRD
#define PCINT19_PORT  PORTD
#define PCINT19_PIN   PIND
#define PCINT19_BIT   3

#define OC2B_DDR   DDRD
#define OC2B_PORT  PORTD
#define OC2B_PIN   PIND
#define OC2B_BIT   3

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   3

#define XCK_DDR   DDRD
#define XCK_PORT  PORTD
#define XCK_PIN   PIND
#define XCK_BIT   4

#define T0_DDR   DDRD
#define T0_PORT  PORTD
#define T0_PIN   PIND
#define T0_BIT   4

#define PCINT20_DDR   DDRD
#define PCINT20_PORT  PORTD
#define PCINT20_PIN   PIND
#define PCINT20_BIT   4

#define PCINT6_DDR   DDRB
#define PCINT6_PORT  PORTB
#define PCINT6_PIN   PINB
#define PCINT6_BIT   6

#define PCINT7_DDR   DDRB
#define PCINT7_PORT  PORTB
#define PCINT7_PIN   PINB
#define PCINT7_BIT   7

#define T1_DDR   DDRD
#define T1_PORT  PORTD
#define T1_PIN   PIND
#define T1_BIT   5

#define OC0B_DDR   DDRD
#define OC0B_PORT  PORTD
#define OC0B_PIN   PIND
#define OC0B_BIT   5

#define PCINT21_DDR   DDRD
#define PCINT21_PORT  PORTD
#define PCINT21_PIN   PIND
#define PCINT21_BIT   5

#define AIN0_DDR   DDRD
#define AIN0_PORT  PORTD
#define AIN0_PIN   PIND
#define AIN0_BIT   6

#define OC0A_DDR   DDRD
#define OC0A_PORT  PORTD
#define OC0A_PIN   PIND
#define OC0A_BIT   6

#define PCINT22_DDR   DDRD
#define PCINT22_PORT  PORTD
#define PCINT22_PIN   PIND
#define PCINT22_BIT   6

#define AIN1_DDR   DDRD
#define AIN1_PORT  PORTD
#define AIN1_PIN   PIND
#define AIN1_BIT   7

#define PCINT23_DDR   DDRD
#define PCINT23_PORT  PORTD
#define PCINT23_PIN   PIND
#define PCINT23_BIT   7

#define ICP1_DDR   DDRB
#define ICP1_PORT  PORTB
#define ICP1_PIN   PINB
#define ICP1_BIT   0

#define CLKO_DDR   DDRB
#define CLKO_PORT  PORTB
#define CLKO_PIN   PINB
#define CLKO_BIT   0

#define PCINT0_DDR   DDRB
#define PCINT0_PORT  PORTB
#define PCINT0_PIN   PINB
#define PCINT0_BIT   0

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   1

#define PCINT1_DDR   DDRB
#define PCINT1_PORT  PORTB
#define PCINT1_PIN   PINB
#define PCINT1_BIT   1

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   2

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   2

#define PCINT2_DDR   DDRB
#define PCINT2_PORT  PORTB
#define PCINT2_PIN   PINB
#define PCINT2_BIT   2

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   3

#define OC2A_DDR   DDRB
#define OC2A_PORT  PORTB
#define OC2A_PIN   PINB
#define OC2A_BIT   3

#define PCINT3_DDR   DDRB
#define PCINT3_PORT  PORTB
#define PCINT3_PIN   PINB
#define PCINT3_BIT   3

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   4

#define PCINT4_DDR   DDRB
#define PCINT4_PORT  PORTB
#define PCINT4_PIN   PINB
#define PCINT4_BIT   4

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   5

#define PCINT5_DDR   DDRB
#define PCINT5_PORT  PORTB
#define PCINT5_PIN   PINB
#define PCINT5_BIT   5

#define ADC6_DDR   DDRADC
#define ADC6_PORT  PORTADC
#define ADC6_PIN   PINADC
#define ADC6_BIT   ADC6

#define ADC7_DDR   DDRADC
#define ADC7_PORT  PORTADC
#define ADC7_PIN   PINADC
#define ADC7_BIT   ADC7

#define ADC0_DDR   DDRC
#define ADC0_PORT  PORTC
#define ADC0_PIN   PINC
#define ADC0_BIT   0

#define PCINT8_DDR   DDRC
#define PCINT8_PORT  PORTC
#define PCINT8_PIN   PINC
#define PCINT8_BIT   0

#define ADC1_DDR   DDRC
#define ADC1_PORT  PORTC
#define ADC1_PIN   PINC
#define ADC1_BIT   1

#define PCINT9_DDR   DDRC
#define PCINT9_PORT  PORTC
#define PCINT9_PIN   PINC
#define PCINT9_BIT   1

#define ADC2_DDR   DDRC
#define ADC2_PORT  PORTC
#define ADC2_PIN   PINC
#define ADC2_BIT   2

#define PCINT10_DDR   DDRC
#define PCINT10_PORT  PORTC
#define PCINT10_PIN   PINC
#define PCINT10_BIT   2

#define ADC3_DDR   DDRC
#define ADC3_PORT  PORTC
#define ADC3_PIN   PINC
#define ADC3_BIT   3

#define PCINT11_DDR   DDRC
#define PCINT11_PORT  PORTC
#define PCINT11_PIN   PINC
#define PCINT11_BIT   3

#define ADC4_DDR   DDRC
#define ADC4_PORT  PORTC
#define ADC4_PIN   PINC
#define ADC4_BIT   4

#define SDA_DDR   DDRC
#define SDA_PORT  PORTC
#define SDA_PIN   PINC
#define SDA_BIT   4

#define PCINT12_DDR   DDRC
#define PCINT12_PORT  PORTC
#define PCINT12_PIN   PINC
#define PCINT12_BIT   4

#define ADC5_DDR   DDRC
#define ADC5_PORT  PORTC
#define ADC5_PIN   PINC
#define ADC5_BIT   5

#define SCL_DDR   DDRC
#define SCL_PORT  PORTC
#define SCL_PIN   PINC
#define SCL_BIT   5

#define PCINT13_DDR   DDRC
#define PCINT13_PORT  PORTC
#define PCINT13_PIN   PINC
#define PCINT13_BIT   5

#define PCINT14_DDR   DDRC
#define PCINT14_PORT  PORTC
#define PCINT14_PIN   PINC
#define PCINT14_BIT   6

#define RXD_DDR   DDRD
#define RXD_PORT  PORTD
#define RXD_PIN   PIND
#define RXD_BIT   0

#define PCINT16_DDR   DDRD
#define PCINT16_PORT  PORTD
#define PCINT16_PIN   PIND
#define PCINT16_BIT   0

#define TXD_DDR   DDRD
#define TXD_PORT  PORTD
#define TXD_PIN   PIND
#define TXD_BIT   1

#define PCINT17_DDR   DDRD
#define PCINT17_PORT  PORTD
#define PCINT17_PIN   PIND
#define PCINT17_BIT   1

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   2

#define PCINT18_DDR   DDRD
#define PCINT18_PORT  PORTD
#define PCINT18_PIN   PIND
#define PCINT18_BIT   2

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)

#endif /* _AVR_ATmega88PA_H_ */

