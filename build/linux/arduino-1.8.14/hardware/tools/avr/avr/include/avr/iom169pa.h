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

/* $Id: iom169pa.h 2192 2010-11-08 13:53:24Z arcanum $ */

/* avr/iom169pa.h - definitions for ATmega169PA */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom169pa.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATmega169PA_H_
#define _AVR_ATmega169PA_H_ 1


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
#define PINC7 7

#define DDRC _SFR_IO8(0x07)
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6
#define DDC7 7

#define PORTC _SFR_IO8(0x08)
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6
#define PORTC7 7

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

#define PINE _SFR_IO8(0x0C)
#define PINE0 0
#define PINE1 1
#define PINE2 2
#define PINE3 3
#define PINE4 4
#define PINE5 5
#define PINE6 6
#define PINE7 7

#define DDRE _SFR_IO8(0x0D)
#define DDE0 0
#define DDE1 1
#define DDE2 2
#define DDE3 3
#define DDE4 4
#define DDE5 5
#define DDE6 6
#define DDE7 7

#define PORTE _SFR_IO8(0x0E)
#define PORTE0 0
#define PORTE1 1
#define PORTE2 2
#define PORTE3 3
#define PORTE4 4
#define PORTE5 5
#define PORTE6 6
#define PORTE7 7

#define PINF _SFR_IO8(0x0F)
#define PINF0 0
#define PINF1 1
#define PINF2 2
#define PINF3 3
#define PINF4 4
#define PINF5 5
#define PINF6 6
#define PINF7 7

#define DDRF _SFR_IO8(0x10)
#define DDF0 0
#define DDF1 1
#define DDF2 2
#define DDF3 3
#define DDF4 4
#define DDF5 5
#define DDF6 6
#define DDF7 7

#define PORTF _SFR_IO8(0x11)
#define PORTF0 0
#define PORTF1 1
#define PORTF2 2
#define PORTF3 3
#define PORTF4 4
#define PORTF5 5
#define PORTF6 6
#define PORTF7 7

#define PING _SFR_IO8(0x12)
#define PING0 0
#define PING1 1
#define PING2 2
#define PING3 3
#define PING4 4
#define PING5 5

#define DDRG _SFR_IO8(0x13)
#define DDG0 0
#define DDG1 1
#define DDG2 2
#define DDG3 3
#define DDG4 4
#define DDG5 5

#define PORTG _SFR_IO8(0x14)
#define PORTG0 0
#define PORTG1 1
#define PORTG2 2
#define PORTG3 3
#define PORTG4 4
#define PORTG5 5

#define TIFR0 _SFR_IO8(0x15)
#define TOV0 0
#define OCF0A 1

#define TIFR1 _SFR_IO8(0x16)
#define TOV1 0
#define OCF1A 1
#define OCF1B 2
#define ICF1 5

#define TIFR2 _SFR_IO8(0x17)
#define TOV2 0
#define OCF2A 1

#define EIFR _SFR_IO8(0x1C)
#define INTF0 0
#define PCIF0 4
#define PCIF1 5

#define EIMSK _SFR_IO8(0x1D)
#define INT0 0
#define PCIE0 4
#define PCIE1 5

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
#define EEWE 1
#define EEMWE 2
#define EERIE 3

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
#define PSR310 0
#define PSR2 1
#define TSM 7

#define TCCR0A _SFR_IO8(0x24)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM0A0 4
#define COM0A1 5
#define WGM00 6
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
#define OCR0A0 0
#define OCR0A1 1
#define OCR0A2 2
#define OCR0A3 3
#define OCR0A4 4
#define OCR0A5 5
#define OCR0A6 6
#define OCR0A7 7

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

#define OCDR _SFR_IO8(0x31)
#define OCDR0 0
#define OCDR1 1
#define OCDR2 2
#define OCDR3 3
#define OCDR4 4
#define OCDR5 5
#define OCDR6 6
#define OCDR7 7

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
#define JTRF 4

#define MCUCR _SFR_IO8(0x35)
#define IVCE 0
#define IVSEL 1
#define PUD 4
#define BODSE 5
#define BODS 6
#define JTD 7

#define SPMCSR _SFR_IO8(0x37)
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define BLBSET 3
#define RWWSRE 4
#define RWWSB 6
#define SPMIE 7

#define WDTCR _SFR_MEM8(0x60)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDCE 4

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
#define PRLCD 4

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRLCD))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRLCD

#define OSCCAL _SFR_MEM8(0x66)
#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define EICRA _SFR_MEM8(0x69)
#define ISC00 0
#define ISC01 1

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
#define PCINT15 7

#define TIMSK0 _SFR_MEM8(0x6E)
#define TOIE0 0
#define OCIE0A 1

#define TIMSK1 _SFR_MEM8(0x6F)
#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define ICIE1 5

#define TIMSK2 _SFR_MEM8(0x70)
#define TOIE2 0
#define OCIE2A 1

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
#define MUX4 4
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
#define ADC6D 6
#define ADC7D 7

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
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM21 3
#define COM2A0 4
#define COM2A1 5
#define WGM20 6
#define FOC2A 7

#define TCCR2B _SFR_MEM8(0xB1)

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
#define OCR2A0 0
#define OCR2A1 1
#define OCR2A2 2
#define OCR2A3 3
#define OCR2A4 4
#define OCR2A5 5
#define OCR2A6 6
#define OCR2A7 7

#define ASSR _SFR_MEM8(0xB6)
#define TCR2UB 0
#define OCR2UB 1
#define TCN2UB 2
#define AS2 3
#define EXCLK 4

#define USICR _SFR_MEM8(0xB8)
#define USITC 0
#define USICLK 1
#define USICS0 2
#define USICS1 3
#define USIWM0 4
#define USIWM1 5
#define USIOIE 6
#define USISIE 7

#define USISR _SFR_MEM8(0xB9)
#define USICNT0 0
#define USICNT1 1
#define USICNT2 2
#define USICNT3 3
#define USIDC 4
#define USIPF 5
#define USIOIF 6
#define USISIF 7

#define USIDR _SFR_MEM8(0xBA)
#define USIDR0 0
#define USIDR1 1
#define USIDR2 2
#define USIDR3 3
#define USIDR4 4
#define USIDR5 5
#define USIDR6 6
#define USIDR7 7

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
#define UMSEL0 6

#define UBRR0 _SFR_MEM16(0xC4)

#define UBRR0L _SFR_MEM8(0xC4)
#define UBRR0_0 0
#define UBRR0_1 1
#define UBRR0_2 2
#define UBRR0_3 3
#define UBRR0_4 4
#define UBRR0_5 5
#define UBRR0_6 6
#define UBRR0_7 7

#define UBRR0H _SFR_MEM8(0xC5)
#define UBRR0_8 0
#define UBRR0_9 1
#define UBRR0_10 2
#define UBRR0_11 3

#define UDR0 _SFR_MEM8(0xC6)
#define UDR00 0
#define UDR01 1
#define UDR02 2
#define UDR03 3
#define UDR04 4
#define UDR05 5
#define UDR06 6
#define UDR07 7

#define LCDCRA _SFR_MEM8(0xE4)
#define LCDBL 0
#define LCDCCD 1
#define LCDBD 2
#define LCDIE 3
#define LCDIF 4
#define LCDAB 6
#define LCDEN 7

#define LCDCRB _SFR_MEM8(0xE5)
#define LCDPM0 0
#define LCDPM1 1
#define LCDPM2 2
#define LCDMUX0 4
#define LCDMUX1 5
#define LCD2B 6
#define LCDCS 7

#define LCDFRR _SFR_MEM8(0xE6)
#define LCDCD0 0
#define LCDCD1 1
#define LCDCD2 2
#define LCDPS0 4
#define LCDPS1 5
#define LCDPS2 6

#define LCDCCR _SFR_MEM8(0xE7)
#define LCDCC0 0
#define LCDCC1 1
#define LCDCC2 2
#define LCDCC3 3
#define LCDMDT 4
#define LCDDC0 5
#define LCDDC1 6
#define LCDDC2 7

#define LCDDR0 _SFR_MEM8(0xEC)
#define SEG000 0
#define SEG001 1
#define SEG002 2
#define SEG003 3
#define SEG004 4
#define SEG005 5
#define SEG006 6
#define SEG007 7

#define LCDDR1 _SFR_MEM8(0xED)
#define SEG008 0
#define SEG009 1
#define SEG010 2
#define SEG011 3
#define SEG012 4
#define SEG013 5
#define SEG014 6
#define SEG015 7

#define LCDDR2 _SFR_MEM8(0xEE)
#define SEG016 0
#define SEG017 1
#define SEG018 2
#define SEG019 3
#define SEG020 4
#define SEG021 5
#define SEG022 6
#define SEG023 7

#define LCDDR3 _SFR_MEM8(0xEF)
#define SEG024 0

#define LCDDR5 _SFR_MEM8(0xF1)
#define SEG100 0
#define SEG101 1
#define SEG102 2
#define SEG103 3
#define SEG104 4
#define SEG105 5
#define SEG106 6
#define SEG107 7

#define LCDDR6 _SFR_MEM8(0xF2)
#define SEG108 0
#define SEG109 1
#define SEG110 2
#define SEG111 3
#define SEG112 4
#define SEG113 5
#define SEG114 6
#define SEG115 7

#define LCDDR7 _SFR_MEM8(0xF3)
#define SEG116 0
#define SEG117 1
#define SEG118 2
#define SEG119 3
#define SEG120 4
#define SEG121 5
#define SEG122 6
#define SEG123 7

#define LCDDR8 _SFR_MEM8(0xF4)
#define SEG124 0

#define LCDDR10 _SFR_MEM8(0xF6)
#define SEG200 0
#define SEG201 1
#define SEG202 2
#define SEG203 3
#define SEG204 4
#define SEG205 5
#define SEG206 6
#define SEG207 7

#define LCDDR11 _SFR_MEM8(0xF7)
#define SEG208 0
#define SEG209 1
#define SEG210 2
#define SEG211 3
#define SEG212 4
#define SEG213 5
#define SEG214 6
#define SEG215 7

#define LCDDR12 _SFR_MEM8(0xF8)
#define SEG216 0
#define SEG217 1
#define SEG218 2
#define SEG219 3
#define SEG220 4
#define SEG221 5
#define SEG222 6
#define SEG223 7

#define LCDDR13 _SFR_MEM8(0xF9)
#define SEG224 0

#define LCDDR15 _SFR_MEM8(0xFB)
#define SEG300 0
#define SEG301 1
#define SEG302 2
#define SEG303 3
#define SEG304 4
#define SEG305 5
#define SEG306 6
#define SEG307 7

#define LCDDR16 _SFR_MEM8(0xFC)
#define SEG308 0
#define SEG309 1
#define SEG310 2
#define SEG311 3
#define SEG312 4
#define SEG313 5
#define SEG314 6
#define SEG315 7

#define LCDDR17 _SFR_MEM8(0xFD)
#define SEG316 0
#define SEG317 1
#define SEG318 2
#define SEG319 3
#define SEG320 4
#define SEG321 5
#define SEG322 6
#define SEG323 7

#define LCDDR18 _SFR_MEM8(0xFE)
#define SEG324 0


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt Request 0 */
#define PCINT0_vect_num  2
#define PCINT0_vect      _VECTOR(2)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect_num  3
#define PCINT1_vect      _VECTOR(3)  /* Pin Change Interrupt Request 1 */
#define TIMER2_COMP_vect_num  4
#define TIMER2_COMP_vect      _VECTOR(4)  /* Timer/Counter2 Compare Match */
#define TIMER2_OVF_vect_num  5
#define TIMER2_OVF_vect      _VECTOR(5)  /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect_num  6
#define TIMER1_CAPT_vect      _VECTOR(6)  /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect_num  7
#define TIMER1_COMPA_vect      _VECTOR(7)  /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect_num  8
#define TIMER1_COMPB_vect      _VECTOR(8)  /* Timer/Counter Compare Match B */
#define TIMER1_OVF_vect_num  9
#define TIMER1_OVF_vect      _VECTOR(9)  /* Timer/Counter1 Overflow */
#define TIMER0_COMP_vect_num  10
#define TIMER0_COMP_vect      _VECTOR(10)  /* Timer/Counter0 Compare Match */
#define TIMER0_OVF_vect_num  11
#define TIMER0_OVF_vect      _VECTOR(11)  /* Timer/Counter0 Overflow */
#define SPI_STC_vect_num  12
#define SPI_STC_vect      _VECTOR(12)  /* SPI Serial Transfer Complete */
#define USART0_RX_vect_num  13
#define USART0_RX_vect      _VECTOR(13)  /* USART0, Rx Complete */
#define USART0_UDRE_vect_num  14
#define USART0_UDRE_vect      _VECTOR(14)  /* USART0 Data register Empty */
#define USART0_TX_vect_num  15
#define USART0_TX_vect      _VECTOR(15)  /* USART0, Tx Complete */
#define USI_START_vect_num  16
#define USI_START_vect      _VECTOR(16)  /* USI Start Condition */
#define USI_OVERFLOW_vect_num  17
#define USI_OVERFLOW_vect      _VECTOR(17)  /* USI Overflow */
#define ANALOG_COMP_vect_num  18
#define ANALOG_COMP_vect      _VECTOR(18)  /* Analog Comparator */
#define ADC_vect_num  19
#define ADC_vect      _VECTOR(19)  /* ADC Conversion Complete */
#define EE_READY_vect_num  20
#define EE_READY_vect      _VECTOR(20)  /* EEPROM Ready */
#define SPM_READY_vect_num  21
#define SPM_READY_vect      _VECTOR(21)  /* Store Program Memory Read */
#define LCD_vect_num  22
#define LCD_vect      _VECTOR(22)  /* LCD Start of Frame */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (23 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (128)
#define RAMSTART     (0x100)
#define RAMSIZE      (1024)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0x1FF)
#define E2PAGESIZE   (4)
#define FLASHEND     (0x3FFF)


/* Fuses */
#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_CKSEL0  (unsigned char)~_BV(0)  /* Select Clock Source */
#define FUSE_CKSEL1  (unsigned char)~_BV(1)  /* Select Clock Source */
#define FUSE_CKSEL2  (unsigned char)~_BV(2)  /* Select Clock Source */
#define FUSE_CKSEL3  (unsigned char)~_BV(3)  /* Select Clock Source */
#define FUSE_SUT0  (unsigned char)~_BV(4)  /* Select start-up time */
#define FUSE_SUT1  (unsigned char)~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT  (unsigned char)~_BV(6)  /* Oscillator options */
#define FUSE_CKDIV8  (unsigned char)~_BV(7)  /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKDIV8 & FUSE_SUT0 & FUSE_CKSEL3 & FUSE_CKSEL2 & FUSE_CKSEL0)

/* High Fuse Byte */
#define FUSE_BOOTRST  (unsigned char)~_BV(0)  /* Select Reset Vector */
#define FUSE_BOOTSZ0  (unsigned char)~_BV(1)  /* Select Boot Size */
#define FUSE_BOOTSZ1  (unsigned char)~_BV(2)  /* Select Boot Size */
#define FUSE_EESAVE  (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON  (unsigned char)~_BV(4)  /* Watchdog timer always on */
#define FUSE_SPIEN  (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_JTAGEN  (unsigned char)~_BV(6)  /* Enable JTAG */
#define FUSE_OCDEN  (unsigned char)~_BV(7)  /* Enable OCD */
#define HFUSE_DEFAULT (FUSE_JTAGEN & FUSE_SPIEN & FUSE_BOOTSZ1 & FUSE_BOOTSZ0)

/* Extended Fuse Byte */
#define FUSE_RSTDISBL  (unsigned char)~_BV(0)  /* Disable external reset */
#define FUSE_BODLEVEL0  (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1  (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2  (unsigned char)~_BV(3)  /* Brown out detector trigger level */
#define EFUSE_DEFAULT (0xFF)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x05


/* Device Pin Definitions */
#define RXD_DDR   DDRE
#define RXD_PORT  PORTE
#define RXD_PIN   PINE
#define RXD_BIT   0

#define PCINT0_DDR   DDRE
#define PCINT0_PORT  PORTE
#define PCINT0_PIN   PINE
#define PCINT0_BIT   0

#define TXD_DDR   DDRE
#define TXD_PORT  PORTE
#define TXD_PIN   PINE
#define TXD_BIT   1

#define PCINT1_DDR   DDRE
#define PCINT1_PORT  PORTE
#define PCINT1_PIN   PINE
#define PCINT1_BIT   1

#define XCK_DDR   DDRE
#define XCK_PORT  PORTE
#define XCK_PIN   PINE
#define XCK_BIT   2

#define AIN0_DDR   DDRE
#define AIN0_PORT  PORTE
#define AIN0_PIN   PINE
#define AIN0_BIT   2

#define PCINT2_DDR   DDRE
#define PCINT2_PORT  PORTE
#define PCINT2_PIN   PINE
#define PCINT2_BIT   2

#define AIN1_DDR   DDRE
#define AIN1_PORT  PORTE
#define AIN1_PIN   PINE
#define AIN1_BIT   3

#define PCINT3_DDR   DDRE
#define PCINT3_PORT  PORTE
#define PCINT3_PIN   PINE
#define PCINT3_BIT   3

#define USCK_DDR   DDRE
#define USCK_PORT  PORTE
#define USCK_PIN   PINE
#define USCK_BIT   4

#define SCL_DDR   DDRE
#define SCL_PORT  PORTE
#define SCL_PIN   PINE
#define SCL_BIT   4

#define PCINT4_DDR   DDRE
#define PCINT4_PORT  PORTE
#define PCINT4_PIN   PINE
#define PCINT4_BIT   4

#define DI_DDR   DDRE
#define DI_PORT  PORTE
#define DI_PIN   PINE
#define DI_BIT   5

#define SDA_DDR   DDRE
#define SDA_PORT  PORTE
#define SDA_PIN   PINE
#define SDA_BIT   5

#define PCINT5_DDR   DDRE
#define PCINT5_PORT  PORTE
#define PCINT5_PIN   PINE
#define PCINT5_BIT   5

#define DO_DDR   DDRE
#define DO_PORT  PORTE
#define DO_PIN   PINE
#define DO_BIT   6

#define PCINT6_DDR   DDRE
#define PCINT6_PORT  PORTE
#define PCINT6_PIN   PINE
#define PCINT6_BIT   6

#define PCINT7_DDR   DDRE
#define PCINT7_PORT  PORTE
#define PCINT7_PIN   PINE
#define PCINT7_BIT   7

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   0

#define PCINT8_DDR   DDRB
#define PCINT8_PORT  PORTB
#define PCINT8_PIN   PINB
#define PCINT8_BIT   0

#define SCK_DDR   DDRB
#define SCK_PORT  PORTB
#define SCK_PIN   PINB
#define SCK_BIT   1

#define PCINT9_DDR   DDRB
#define PCINT9_PORT  PORTB
#define PCINT9_PIN   PINB
#define PCINT9_BIT   1

#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   2

#define PCINT10_DDR   DDRB
#define PCINT10_PORT  PORTB
#define PCINT10_PIN   PINB
#define PCINT10_BIT   2

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   3

#define PCINT11_DDR   DDRB
#define PCINT11_PORT  PORTB
#define PCINT11_PIN   PINB
#define PCINT11_BIT   3

#define OC0_DDR   DDRB
#define OC0_PORT  PORTB
#define OC0_PIN   PINB
#define OC0_BIT   4

#define PCINT12_DDR   DDRB
#define PCINT12_PORT  PORTB
#define PCINT12_PIN   PINB
#define PCINT12_BIT   4

#define OC1A_DDR   DDRB
#define OC1A_PORT  PORTB
#define OC1A_PIN   PINB
#define OC1A_BIT   5

#define PCINT13_DDR   DDRB
#define PCINT13_PORT  PORTB
#define PCINT13_PIN   PINB
#define PCINT13_BIT   5

#define OC1B_DDR   DDRB
#define OC1B_PORT  PORTB
#define OC1B_PIN   PINB
#define OC1B_BIT   6

#define PCINT14_DDR   DDRB
#define PCINT14_PORT  PORTB
#define PCINT14_PIN   PINB
#define PCINT14_BIT   6

#define OC2_DDR   DDRB
#define OC2_PORT  PORTB
#define OC2_PIN   PINB
#define OC2_BIT   7

#define PCINT15_DDR   DDRB
#define PCINT15_PORT  PORTB
#define PCINT15_PIN   PINB
#define PCINT15_BIT   7

#define T1_DDR   DDRG
#define T1_PORT  PORTG
#define T1_PIN   PING
#define T1_BIT   3

#define SEG24_DDR   DDRG
#define SEG24_PORT  PORTG
#define SEG24_PIN   PING
#define SEG24_BIT   3

#define T0_DDR   DDRG
#define T0_PORT  PORTG
#define T0_PIN   PING
#define T0_BIT   4

#define SEG23_DDR   DDRG
#define SEG23_PORT  PORTG
#define SEG23_PIN   PING
#define SEG23_BIT   4

#define SEG22_DDR   DDRD
#define SEG22_PORT  PORTD
#define SEG22_PIN   PIND
#define SEG22_BIT   0

#define SEG21_DDR   DDRD
#define SEG21_PORT  PORTD
#define SEG21_PIN   PIND
#define SEG21_BIT   1

#define SEG20_DDR   DDRD
#define SEG20_PORT  PORTD
#define SEG20_PIN   PIND
#define SEG20_BIT   2

#define SEG19_DDR   DDRD
#define SEG19_PORT  PORTD
#define SEG19_PIN   PIND
#define SEG19_BIT   3

#define SEG18_DDR   DDRD
#define SEG18_PORT  PORTD
#define SEG18_PIN   PIND
#define SEG18_BIT   4

#define SEG17_DDR   DDRD
#define SEG17_PORT  PORTD
#define SEG17_PIN   PIND
#define SEG17_BIT   5

#define SEG16_DDR   DDRD
#define SEG16_PORT  PORTD
#define SEG16_PIN   PIND
#define SEG16_BIT   6

#define SEG15_DDR   DDRD
#define SEG15_PORT  PORTD
#define SEG15_PIN   PIND
#define SEG15_BIT   7

#define SEG14_DDR   DDRG
#define SEG14_PORT  PORTG
#define SEG14_PIN   PING
#define SEG14_BIT   0

#define SEG13_DDR   DDRG
#define SEG13_PORT  PORTG
#define SEG13_PIN   PING
#define SEG13_BIT   1

#define SEG12_DDR   DDRC
#define SEG12_PORT  PORTC
#define SEG12_PIN   PINC
#define SEG12_BIT   0

#define SEG11_DDR   DDRC
#define SEG11_PORT  PORTC
#define SEG11_PIN   PINC
#define SEG11_BIT   1

#define SEG10_DDR   DDRC
#define SEG10_PORT  PORTC
#define SEG10_PIN   PINC
#define SEG10_BIT   2

#define SEG9_DDR   DDRC
#define SEG9_PORT  PORTC
#define SEG9_PIN   PINC
#define SEG9_BIT   3

#define SEG8_DDR   DDRC
#define SEG8_PORT  PORTC
#define SEG8_PIN   PINC
#define SEG8_BIT   4

#define SEG7_DDR   DDRC
#define SEG7_PORT  PORTC
#define SEG7_PIN   PINC
#define SEG7_BIT   5

#define SEG6_DDR   DDRC
#define SEG6_PORT  PORTC
#define SEG6_PIN   PINC
#define SEG6_BIT   6

#define SEG5_DDR   DDRC
#define SEG5_PORT  PORTC
#define SEG5_PIN   PINC
#define SEG5_BIT   7

#define SEG4_DDR   DDRG
#define SEG4_PORT  PORTG
#define SEG4_PIN   PING
#define SEG4_BIT   2

#define SEG3_DDR   DDRA
#define SEG3_PORT  PORTA
#define SEG3_PIN   PINA
#define SEG3_BIT   7

#define SEG2_DDR   DDRA
#define SEG2_PORT  PORTA
#define SEG2_PIN   PINA
#define SEG2_BIT   6

#define SEG1_DDR   DDRA
#define SEG1_PORT  PORTA
#define SEG1_PIN   PINA
#define SEG1_BIT   5

#define SEG0_DDR   DDRA
#define SEG0_PORT  PORTA
#define SEG0_PIN   PINA
#define SEG0_BIT   4

#define COM3_DDR   DDRA
#define COM3_PORT  PORTA
#define COM3_PIN   PINA
#define COM3_BIT   3

#define COM2_DDR   DDRA
#define COM2_PORT  PORTA
#define COM2_PIN   PINA
#define COM2_BIT   2

#define COM1_DDR   DDRA
#define COM1_PORT  PORTA
#define COM1_PIN   PINA
#define COM1_BIT   1

#define COM0_DDR   DDRA
#define COM0_PORT  PORTA
#define COM0_PIN   PINA
#define COM0_BIT   0

#define ADC7_DDR   DDRF
#define ADC7_PORT  PORTF
#define ADC7_PIN   PINF
#define ADC7_BIT   7

#define ADC6_DDR   DDRF
#define ADC6_PORT  PORTF
#define ADC6_PIN   PINF
#define ADC6_BIT   6

#define TD0_DDR   DDRF
#define TD0_PORT  PORTF
#define TD0_PIN   PINF
#define TD0_BIT   6

#define ADC5_DDR   DDRF
#define ADC5_PORT  PORTF
#define ADC5_PIN   PINF
#define ADC5_BIT   5

#define ADC4_DDR   DDRF
#define ADC4_PORT  PORTF
#define ADC4_PIN   PINF
#define ADC4_BIT   4

#define ADC3_DDR   DDRF
#define ADC3_PORT  PORTF
#define ADC3_PIN   PINF
#define ADC3_BIT   3

#define ADC2_DDR   DDRF
#define ADC2_PORT  PORTF
#define ADC2_PIN   PINF
#define ADC2_BIT   2

#define ADC1_DDR   DDRF
#define ADC1_PORT  PORTF
#define ADC1_PIN   PINF
#define ADC1_BIT   1

#define ADC0_DDR   DDRF
#define ADC0_PORT  PORTF
#define ADC0_PIN   PINF
#define ADC0_BIT   0

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)

#endif /* _AVR_ATmega169PA_H_ */

