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

/* $Id: io90scr100.h 1910 2009-03-04 17:45:30Z arcanum $ */

/* avr/io90scr100.h - definitions for AT90SCR100 */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "io90scr100.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_AT90SCR100_H_
#define _AVR_AT90SCR100_H_ 1


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

#define EIRR _SFR_IO8(0x1A)
#define INTD2 2
#define INTD3 3

#define PCIFR _SFR_IO8(0x1B)
#define PCIF0 0
#define PCIF1 1
#define PCIF2 2
#define PCIF3 3

#define EIFR _SFR_IO8(0x1C)
#define INTF0 0
#define INTF1 1
#define INTF2 2
#define INTF3 3

#define EIMSK _SFR_IO8(0x1D)
#define INT0 0
#define INT1 1
#define INT2 2
#define INT3 3

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
#define EEAR9 1
#define EEAR10 2
#define EEAR11 3

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
#define SIGRD 5
#define RWWSB 6
#define SPMIE 7

#define RAMPZ _SFR_IO8(0x3B)
#define RAMPZ0 0

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

#define PLLCR _SFR_MEM8(0x62)
#define ON 0
#define LOCK 1
#define PLLMUX 7

#define SMONCR _SFR_MEM8(0x63)
#define SMONEN 0
#define SMONIE 1
#define SMONIF 4

#define PRR0 _SFR_MEM8(0x64)
#define PRUSART0 1
#define PRSPI 2
#define PRTIM1 3
#define PRTIM0 5
#define PRTIM2 6
#define PRTWI 7

#define __AVR_HAVE_PRR0 ((1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#define __AVR_HAVE_PRR0_PRUSART0
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM2
#define __AVR_HAVE_PRR0_PRTWI

#define PRR1 _SFR_MEM8(0x65)
#define PRUSBH 0
#define PRUSB 1
#define PRHSSPI 2
#define PRSCI 3
#define PRAES 4
#define PRKB 5

#define __AVR_HAVE_PRR1 ((1<<PRUSBH)|(1<<PRUSB)|(1<<PRHSSPI)|(1<<PRSCI)|(1<<PRAES)|(1<<PRKB))
#define __AVR_HAVE_PRR1_PRUSBH
#define __AVR_HAVE_PRR1_PRUSB
#define __AVR_HAVE_PRR1_PRHSSPI
#define __AVR_HAVE_PRR1_PRSCI
#define __AVR_HAVE_PRR1_PRAES
#define __AVR_HAVE_PRR1_PRKB

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
#define PCIE3 3

#define EICRA _SFR_MEM8(0x69)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC20 4
#define ISC21 5
#define ISC30 6
#define ISC31 7

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

#define PCMSK3 _SFR_MEM8(0x73)

#define LEDCR _SFR_MEM8(0x75)
#define LED00 0
#define LED01 1
#define LED10 2
#define LED11 3
#define LED20 4
#define LED21 5
#define lED30 6
#define LED31 7

#define AESCR _SFR_MEM8(0x78)
#define AESGO 0
#define ENCRYPT 1
#define KS 3
#define KEYGN 4
#define AUTOKEY 5
#define AESIF 6
#define AESIE 7

#define AESACR _SFR_MEM8(0x79)
#define KD 0
#define AUTOINC 1
#define MANINC 2
#define XOR 3

#define AESADDR _SFR_MEM8(0x7A)
#define ADDR0 0
#define ADDR1 1
#define ADDR2 2
#define ADDR3 3
#define ADDR4 4
#define ADDR5 5
#define ADDR6 6
#define ADDR7 7

#define AESDR _SFR_MEM8(0x7B)
#define DATA0 0
#define DATA1 1
#define DATA2 2
#define DATA3 3
#define DATA4 4
#define DATA5 5
#define DATA6 6
#define DATA7 7

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

#define KBLSR _SFR_MEM8(0x8D)
#define KBLS0 0
#define KBLS1 1
#define KBLS2 2
#define KBLS3 3
#define KBLS4 4
#define KBLS5 5
#define KBLS6 6
#define KBLS7 7

#define KBER _SFR_MEM8(0x8E)
#define KBE0 0
#define KBE1 1
#define KBE2 2
#define KBE3 3
#define KBE4 4
#define KBE5 5
#define KBE6 6
#define KBE7 7

#define KBFR _SFR_MEM8(0x8F)
#define KBF0 0
#define KBF1 1
#define KBF2 2
#define KBF3 3
#define KBF4 4
#define KBF5 5
#define KBF6 6
#define KBF7 7

#define RDWDR _SFR_MEM8(0x90)
#define RDD0 0
#define RDD1 1
#define RDD2 2
#define RDD3 3
#define RDD4 4
#define RDD5 5
#define RDD6 6
#define RDD7 7

#define LFSR0 _SFR_MEM8(0x91)
#define LFSD0 0
#define LFSD1 1
#define LFSD2 2
#define LFSD3 3
#define LFSD4 4
#define LFSD5 5
#define LFSD6 6
#define LFSD7 7

#define LFSR1 _SFR_MEM8(0x92)
#define LFSD8 0
#define LFSD9 1
#define LFSD10 2
#define LFSD11 3
#define LFSD12 4
#define LFSD13 5
#define LFSD14 6
#define LFSD15 7

#define LFSR2 _SFR_MEM8(0x93)
#define LFSD16 0
#define LFSD17 1
#define LFSD18 2
#define LFSD19 3
#define LFSD20 4
#define LFSD21 5
#define LFSD22 6
#define LFSD23 7

#define LFSR3 _SFR_MEM8(0x94)
#define LFSD24 0
#define LFSD25 1
#define LFSD26 2
#define LFSD27 3
#define LFSD28 4
#define LFSD29 5
#define LFSD30 6
#define LFSD31 7

#define RNGCR _SFR_MEM8(0x95)
#define ROSCE 0

#define UHSR _SFR_MEM8(0x99)
#define SPEED 3

#define UPINT _SFR_MEM8(0x9A)
#define PINT0 0
#define PINT1 1
#define PINT2 2
#define PINT3 3

#define UPBCX _SFR_MEM16(0x9B)

#define UPBCXL _SFR_MEM8(0x9B)
#define PBYTCT0 0
#define PBYTCT1 1
#define PBYTCT2 2
#define PBYTCT3 3
#define PBYTCT4 4
#define PBYTCT5 5
#define PBYTCT6 6
#define PBYTCT7 7

#define UPBCXH _SFR_MEM8(0x9C)
#define PBYTCT8 0
#define PBYTCT9 1
#define PBYTCT10 2

#define UPERRX _SFR_MEM8(0x9D)
#define DATATGL 0
#define DATAPID 1
#define PID 2
#define PTIMEOUT 3
#define CRC16 4
#define COUNTER0 5
#define COUNTER1 6

#define UHCR _SFR_MEM8(0x9E)
#define SOFEN 0
#define RESET 1
#define RESUME 2
#define FRZCLK 4
#define PAD0 5
#define PAD1 6
#define UHEN 7

#define UHINT _SFR_MEM8(0x9F)
#define DCONNI 0
#define DDISCI 1
#define RSTI 2
#define RSMEDI 3
#define RXRSMI 4
#define HSOFI 5
#define HWUPI 6

#define UHIEN _SFR_MEM8(0xA0)
#define DCONNE 0
#define DDISCE 1
#define RSTE 2
#define RSMEDE 3
#define RXRSME 4
#define HSOFE 5
#define HWUPE 6

#define UHADDR _SFR_MEM8(0xA1)
#define HADDR0 0
#define HADDR1 1
#define HADDR2 2
#define HADDR3 3
#define HADDR4 4
#define HADDR5 5
#define HADDR6 6

#define UHFNUM _SFR_MEM16(0xA2)

#define UHFNUML _SFR_MEM8(0xA2)
#define FNUM0 0
#define FNUM1 1
#define FNUM2 2
#define FNUM3 3
#define FNUM4 4
#define FNUM5 5
#define FNUM6 6
#define FNUM7 7

#define UHFNUMH _SFR_MEM8(0xA3)
#define FNUM8 0
#define FNUM9 1
#define FNUM10 2

#define UHFLEN _SFR_MEM8(0xA4)
#define FLEN0 0
#define FLEN1 1
#define FLEN2 2
#define FLEN3 3
#define FLEN4 4
#define FLEN5 5
#define FLEN6 6
#define FLEN7 7

#define UPINRQX _SFR_MEM8(0xA5)
#define INRQ0 0
#define INRQ1 1
#define INRQ2 2
#define INRQ3 3
#define INRQ4 4
#define INRQ5 5
#define INRQ6 6
#define INRQ7 7

#define UPINTX _SFR_MEM8(0xA6)
#define RXINI 0
#define RXSTALLI 1
#define TXOUTI 2
#define TXSTPI 3
#define PERRI 4
#define RWAL 5
#define NAKEDI 6
#define FIFOCON 7

#define UPNUM _SFR_MEM8(0xA7)
#define PNUM0 0
#define PNUM1 1

#define UPRST _SFR_MEM8(0xA8)
#define P0RST 0
#define P1RST 1
#define P2RST 2
#define P3RST 3

#define UPCRX _SFR_MEM8(0xA9)
#define PEN 0
#define RSTDT 3
#define INMODE 5
#define PFREEZE 6

#define UPCFG0X _SFR_MEM8(0xAA)
#define PEPNUM0 0
#define PEPNUM1 1
#define PEPNUM2 2
#define PEPNUM3 3
#define PTOKEN0 4
#define PTOKEN1 5
#define PTYPE0 6
#define PTYPE1 7

#define UPCFG1X _SFR_MEM8(0xAB)
#define ALLOC 1
#define PBK0 2
#define PBK1 3
#define PSIZE0 4
#define PSIZE1 5
#define PSIZE2 6

#define UPSTAX _SFR_MEM8(0xAC)
#define NBUSYBK0 0
#define NBUSYBK1 1
#define DTSEQ0 2
#define DTSEQ1 3
#define UNDERFI 5
#define OVERFI 6
#define CFGOK 7

#define UPCFG2X _SFR_MEM8(0xAD)
#define INTFRQ0 0
#define INTFRQ1 1
#define INTFRQ2 2
#define INTFRQ3 3
#define INTFRQ4 4
#define INTFRQ5 5
#define INTFRQ6 6
#define INTFRQ7 7

#define UPIENX _SFR_MEM8(0xAE)
#define RXINE 0
#define RXSTALLE 1
#define TXOUTE 2
#define TXSTPE 3
#define PERRE 4
#define NAKEDE 6
#define FLERRE 7

#define UPDATX _SFR_MEM8(0xAF)
#define PDAT0 0
#define PDAT1 1
#define PDAT2 2
#define PDAT3 3
#define PDAT4 4
#define PDAT5 5
#define PDAT6 6
#define PDAT7 7

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
#define OCR2A0 0
#define OCR2A1 1
#define OCR2A2 2
#define OCR2A3 3
#define OCR2A4 4
#define OCR2A5 5
#define OCR2A6 6
#define OCR2A7 7

#define OCR2B _SFR_MEM8(0xB4)
#define OCR2B0 0
#define OCR2B1 1
#define OCR2B2 2
#define OCR2B3 3
#define OCR2B4 4
#define OCR2B5 5
#define OCR2B6 6
#define OCR2B7 7

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
#define UBRR00 0
#define UBRR01 1
#define UBRR02 2
#define UBRR03 3
#define UBRR04 4
#define UBRR05 5
#define UBRR06 6
#define UBRR07 7

#define UBRR0H _SFR_MEM8(0xC5)
#define UBRR08 0
#define UBRR09 1
#define UBRR010 2
#define UBRR011 3

#define UDR0 _SFR_MEM8(0xC6)
#define UDR00 0
#define UDR01 1
#define UDR02 2
#define UDR03 3
#define UDR04 4
#define UDR05 5
#define UDR06 6
#define UDR07 7

#define USBENUM _SFR_MEM8(0xCA)
#define USBENUM0 0
#define USBENUM1 1
#define USBENUM2 2

#define USBCSEX _SFR_MEM8(0xCB)
#define TXC 0
#define RCVD 1
#define RXSETUP 2
#define STSENT 3
#define TXPB 4
#define FSTALL 5
#define IERR 6

#define USBDBCEX _SFR_MEM8(0xCC)
#define BCT0 0
#define BCT1 1
#define BCT2 2
#define BCT3 3
#define BCT4 4
#define BCT5 5
#define BCT6 6
#define BCT7 7

#define USBFCEX _SFR_MEM8(0xCD)
#define EPTYP0 0
#define EPTYP1 1
#define EPDIR 2
#define EPE 7

#define HSSPITO _SFR_MEM16(0xD1)

#define HSSPITOL _SFR_MEM8(0xD1)
#define HSSPITOD0 0
#define HSSPITOD1 1
#define HSSPITOD2 2
#define HSSPITOD3 3
#define HSSPITOD4 4
#define HSSPITOD5 5
#define HSSPITOD6 6
#define HSSPITOD7 7

#define HSSPITOH _SFR_MEM8(0xD2)
#define HSSPITOD8 0
#define HSSPITOD9 1
#define HSSPITOD10 2
#define HSSPITOD11 3
#define HSSPITOD12 4
#define HSSPITOD13 5
#define HSSPITOD14 6
#define HSSPITOD15 7

#define HSSPICNT _SFR_MEM8(0xD3)
#define HSSPICNTD0 0
#define HSSPICNTD1 1
#define HSSPICNTD2 2
#define HSSPICNTD3 3
#define HSSPICNTD4 4

#define HSSPIIER _SFR_MEM8(0xD4)
#define NSSIE 4
#define RCVOFIE 5
#define BTDIE 6
#define TIMEOUTIE 7

#define HSSPIGTR _SFR_MEM8(0xD5)
#define HSSPIGTD0 0
#define HSSPIGTD1 1
#define HSSPIGTD2 2
#define HSSPIGTD3 3
#define HSSPIGTD4 4
#define HSSPIGTD5 5
#define HSSPIGTD6 6
#define HSSPIGTD7 7

#define HSSPIRDR _SFR_MEM8(0xD6)
#define HSSPIRDD0 0
#define HSSPIRDD1 1
#define HSSPIRDD2 2
#define HSSPIRDD3 3
#define HSSPIRDD4 4
#define HSSPIRDD5 5
#define HSSPIRDD6 6
#define HSSPIRDD7 7

#define HSSPITDR _SFR_MEM8(0xD7)
#define HSSPITDD0 0
#define HSSPITDD1 1
#define HSSPITDD2 2
#define HSSPITDD3 3
#define HSSPITDD4 4
#define HSSPITDD5 5
#define HSSPITDD6 6
#define HSSPITDD7 7

#define HSSPISR _SFR_MEM8(0xD8)
#define SPICKRDY 0
#define TXBUFE 1
#define RXBUFF 2
#define NSS 3
#define DPRAMRDY 4

#define HSSPICFG _SFR_MEM8(0xD9)
#define HSSPIEN 0
#define HSMSTR 1
#define HSCPOL 2
#define HSCPHA 3
#define DPRAM 4
#define SPICKDIV0 5
#define SPICKDIV1 6
#define SPICKDIV2 7

#define HSSPIIR _SFR_MEM8(0xDA)
#define NSSFE 3
#define NSSRE 4
#define RCVOF 5
#define BTD 6
#define TIMEOUT 7

#define HSSPICR _SFR_MEM8(0xDB)
#define CS 0
#define RETTO 1
#define STTTO 2

#define HSSPIDMACS _SFR_MEM8(0xDC)
#define HSSPIDMAR 0
#define HSSPIDMADIR 1
#define HSSPIDMAERR 2

#define HSSPIDMAD _SFR_MEM16(0xDD)

#define HSSPIDMADL _SFR_MEM8(0xDD)
#define HSSPIDMAD0 0
#define HSSPIDMAD1 1
#define HSSPIDMAD2 2
#define HSSPIDMAD3 3
#define HSSPIDMAD4 4
#define HSSPIDMAD5 5
#define HSSPIDMAD6 6
#define HSSPIDMAD7 7

#define HSSPIDMADH _SFR_MEM8(0xDE)
#define HSSPIDMAD8 0
#define HSSPIDMAD9 1
#define HSSPIDMAD10 2
#define HSSPIDMAD11 3
#define HSSPIDMAD12 4
#define HSSPIDMAD13 5

#define HSSPIDMAB _SFR_MEM8(0xDF)
#define HSSPIDMAB0 0
#define HSSPIDMAB1 1
#define HSSPIDMAB2 2
#define HSSPIDMAB3 3
#define HSSPIDMAB4 4

#define USBCR _SFR_MEM8(0xE0)
#define USBE 1
#define UPUC 5
#define URMWU 7

#define USBPI _SFR_MEM8(0xE1)
#define SUSI 0
#define RESI 1
#define RMWUI 2
#define SOFI 3
#define FEURI 4

#define USBPIM _SFR_MEM8(0xE2)
#define SUSIM 0
#define RESIM 1
#define RMWUIM 2
#define SOFIM 3

#define USBEI _SFR_MEM8(0xE3)
#define EP0I 0
#define EP1I 1
#define EP2I 2
#define EP3I 3
#define EP4I 4
#define EP5I 5
#define EP6I 6
#define EP7I 7

#define USBEIM _SFR_MEM8(0xE4)
#define EP0IM 0
#define EP1IM 1
#define EP2IM 2
#define EP3IM 3
#define EP4IM 4
#define EP5IM 5
#define EP6IM 6
#define EP7IM 7

#define USBRSTE _SFR_MEM8(0xE5)
#define RSTE0 0
#define RSTE1 1
#define RSTE2 2
#define RSTE3 3
#define RSTE4 4
#define RSTE5 5
#define RSTE6 6
#define RST7 7

#define USBGS _SFR_MEM8(0xE6)
#define FAF 0
#define FCF 1
#define RMWUE 2
#define RSMON 3

#define USBFA _SFR_MEM8(0xE7)
#define FADD0 0
#define FADD1 1
#define FADD2 2
#define FADD3 3
#define FADD4 4
#define FADD5 5
#define FADD6 6

#define USBFN _SFR_MEM16(0xE8)

#define USBFNL _SFR_MEM8(0xE8)
#define FN0 0
#define FN1 1
#define FN2 2
#define FN3 3
#define FN4 4
#define FN5 5
#define FN6 6
#define FN7 7

#define USBFNH _SFR_MEM8(0xE9)
#define FN8 0
#define FN9 1
#define FN10 2
#define FNERR 3
#define FNEND 4

#define USBDMACS _SFR_MEM8(0xEA)
#define USBDMAR 0
#define USBDMADIR 1
#define USBDMAERR 2
#define EPS0 4
#define EPS1 5
#define EPS2 6

#define USBDMAD _SFR_MEM16(0xEB)

#define USBDMADL _SFR_MEM8(0xEB)
#define USBDMAD0 0
#define USBDMAD1 1
#define USBDMAD2 2
#define USBDMAD3 3
#define USBDMAD4 4
#define USBDMAD5 5
#define USBDMAD6 6
#define USBDMAD7 7

#define USBDMADH _SFR_MEM8(0xEC)
#define USBDMAD8 0
#define USBDMAD9 1
#define USBDMAD10 2
#define USBDMAD11 3
#define USBDMAD12 4
#define USBDMAD13 5

#define USBDMAB _SFR_MEM8(0xED)
#define USBDMAB0 0
#define USBDMAB1 1
#define USBDMAB2 2
#define USBDMAB3 3
#define USBDMAB4 4
#define USBDMAB5 5
#define USBDMAB6 6

#define DCCR _SFR_MEM8(0xEF)
#define DCBUSY 5
#define DCRDY 6
#define DCON 7

#define SCICLK _SFR_MEM8(0xF0)
#define SCICLK0 0
#define SCICLK1 1
#define SCICLK2 2
#define SCICLK3 3
#define SCICLK4 4
#define SCICLK5 5

#define SCWT0 _SFR_MEM8(0xF1)
#define WT0 0
#define WT1 1
#define WT2 2
#define WT3 3
#define WT4 4
#define WT5 5
#define WT6 6
#define WT7 7

#define SCWT1 _SFR_MEM8(0xF2)
#define WT8 0
#define WT9 1
#define WT10 2
#define WT11 3
#define WT12 4
#define WT13 5
#define WT14 6
#define WT15 7

#define SCWT2 _SFR_MEM8(0xF3)
#define WT16 0
#define WT17 1
#define WT18 2
#define WT19 3
#define WT20 4
#define WT21 5
#define WT22 6
#define WT23 7

#define SCWT3 _SFR_MEM8(0xF4)
#define WT24 0
#define WT25 1
#define WT26 2
#define WT27 3
#define WT28 4
#define WT29 5
#define WT30 6
#define WT31 7

#define SCGT _SFR_MEM16(0xF5)

#define SCGTL _SFR_MEM8(0xF5)
#define GT0 0
#define GT1 1
#define GT2 2
#define GT3 3
#define GT4 4
#define GT5 5
#define GT6 6
#define GT7 7

#define SCGTH _SFR_MEM8(0xF6)
#define GT8 0

#define SCETU _SFR_MEM16(0xF7)

#define SCETUL _SFR_MEM8(0xF7)
#define ETU0 0
#define ETU1 1
#define ETU2 2
#define ETU3 3
#define ETU4 4
#define ETU5 5
#define ETU6 6
#define ETU7 7

#define SCETUH _SFR_MEM8(0xF8)
#define ETU8 0
#define ETU9 1
#define ETU10 2
#define COMP 7

#define SCIBUF _SFR_MEM8(0xF9)
#define SCIBUFD0 0
#define SCIBUFD1 1
#define SCIBUFD2 2
#define SCIBUFD3 3
#define SCIBUFD4 4
#define SCIBUFD5 5
#define SCIBUFD6 6
#define SCIBUFD7 7

#define SCSR _SFR_MEM8(0xFA)
#define CPRESRES 3
#define CREPSEL 4
#define BGTEN 6

#define SCIER _SFR_MEM8(0xFB)
#define ESCPI 0
#define ESCRI 1
#define ESCTI 2
#define ESCWTI 3
#define EVCARDER 4
#define CARDINE 6
#define ESCTBI 7

#define SCIIR _SFR_MEM8(0xFC)
#define SCPI 0
#define SCRI 1
#define SCTI 2
#define SCWTI 3
#define VCARDERR 4
#define SCTBI 7

#define SCISR _SFR_MEM8(0xFD)
#define SCPE 0
#define SCRC 1
#define SCTC 2
#define SCWTO 3
#define VCARDOK 4
#define CARDIN 6
#define SCTBE 7

#define SCCON _SFR_MEM8(0xFE)
#define CARDVCC 0
#define CARDRST 1
#define CARDCLK 2
#define CARDIO 3
#define CARDC4 4
#define CARDC8 5
#define CLK 7

#define SCICR _SFR_MEM8(0xFF)
#define CONV 0
#define CREP 1
#define WTEN 2
#define UART 3
#define VCARD0 4
#define VCARD1 5
#define CARDDET 6
#define SCIRESET 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt Request 0 */
#define INT1_vect_num  2
#define INT1_vect      _VECTOR(2)  /* External Interrupt Request 1 */
#define INT2_vect_num  3
#define INT2_vect      _VECTOR(3)  /* External Interrupt Request 2 */
#define INT3_vect_num  4
#define INT3_vect      _VECTOR(4)  /* External Interrupt Request 3 */
#define PCINT0_vect_num  5
#define PCINT0_vect      _VECTOR(5)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect_num  6
#define PCINT1_vect      _VECTOR(6)  /* Pin Change Interrupt Request 1 */
#define PCINT2_vect_num  7
#define PCINT2_vect      _VECTOR(7)  /* Pin Change Interrupt Request 2 */
#define WDT_vect_num  8
#define WDT_vect      _VECTOR(8)  /* Watchdog Time-out Interrupt */
#define TIMER2_COMPA_vect_num  9
#define TIMER2_COMPA_vect      _VECTOR(9)  /* Timer/Counter2 Compare Match A */
#define TIMER2_COMPB_vect_num  10
#define TIMER2_COMPB_vect      _VECTOR(10)  /* Timer/Counter2 Compare Match B */
#define TIMER2_OVF_vect_num  11
#define TIMER2_OVF_vect      _VECTOR(11)  /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect_num  12
#define TIMER1_CAPT_vect      _VECTOR(12)  /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect_num  13
#define TIMER1_COMPA_vect      _VECTOR(13)  /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect_num  14
#define TIMER1_COMPB_vect      _VECTOR(14)  /* Timer/Counter1 Compare Match B */
#define TIMER1_OVF_vect_num  15
#define TIMER1_OVF_vect      _VECTOR(15)  /* Timer/Counter1 Overflow */
#define TIMER0_COMPA_vect_num  16
#define TIMER0_COMPA_vect      _VECTOR(16)  /* Timer/Counter0 Compare Match A */
#define TIMER0_COMPB_vect_num  17
#define TIMER0_COMPB_vect      _VECTOR(17)  /* Timer/Counter0 Compare Match B */
#define TIMER0_OVF_vect_num  18
#define TIMER0_OVF_vect      _VECTOR(18)  /* Timer/Counter0 Overflow */
#define SPI_STC_vect_num  19
#define SPI_STC_vect      _VECTOR(19)  /* SPI Serial Transfer Complete */
#define USART0_RX_vect_num  20
#define USART0_RX_vect      _VECTOR(20)  /* USART0, Rx Complete */
#define USART0_UDRE_vect_num  21
#define USART0_UDRE_vect      _VECTOR(21)  /* USART0 Data register Empty */
#define USART0_TX_vect_num  22
#define USART0_TX_vect      _VECTOR(22)  /* USART0, Tx Complete */
#define SUPPLY_MON_vect_num  23
#define SUPPLY_MON_vect      _VECTOR(23)  /* Supply Monitor Interruption */
#define RFU_vect_num  24
#define RFU_vect      _VECTOR(24)  /* Reserved for Future Use */
#define EE_READY_vect_num  25
#define EE_READY_vect      _VECTOR(25)  /* EEPROM Ready */
#define TWI_vect_num  26
#define TWI_vect      _VECTOR(26)  /* 2-wire Serial Interface */
#define SPM_READY_vect_num  27
#define SPM_READY_vect      _VECTOR(27)  /* Store Program Memory Read */
#define KEYBOARD_vect_num  28
#define KEYBOARD_vect      _VECTOR(28)  /* Keyboard Input Changed */
#define AES_Operation_vect_num  29
#define AES_Operation_vect      _VECTOR(29)  /* AES Block Operation Ended */
#define HSSPI_vect_num  30
#define HSSPI_vect      _VECTOR(30)  /* High-Speed SPI Interruption */
#define USB_Endpoint_vect_num  31
#define USB_Endpoint_vect      _VECTOR(31)  /* USB Endpoint Related Interruption */
#define USB_Protocol_vect_num  32
#define USB_Protocol_vect      _VECTOR(32)  /* USB Protocol Related Interruption */
#define SCIB_vect_num  33
#define SCIB_vect      _VECTOR(33)  /* Smart Card Reader Interface */
#define USBHost_Control_vect_num  34
#define USBHost_Control_vect      _VECTOR(34)  /* USB Host Controller Interrupt */
#define USBHost_Pipe_vect_num  35
#define USBHost_Pipe_vect      _VECTOR(35)  /* USB Host Pipe Interrupt */
#define CPRES_vect_num  36
#define CPRES_vect      _VECTOR(36)  /* Card Presence Detection */
#define PCINT3_vect_num  37
#define PCINT3_vect      _VECTOR(37)  /* Pin Change Interrupt Request 3 */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (38 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (256)
#define RAMSTART     (0x100)
#define RAMSIZE      (4096)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (0x0)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0x7FF)
#define E2PAGESIZE   (4)
#define FLASHEND     (0xFFFF)


/* Fuses */
#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_CKSEL0  (unsigned char)~_BV(0)  /* Clock Selection */
#define FUSE_CKSEL3  (unsigned char)~_BV(3)  /* Clock Selection */
#define FUSE_SUT0  (unsigned char)~_BV(4)  /* Select start-up time */
#define FUSE_SUT1  (unsigned char)~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT  (unsigned char)~_BV(6)  /* Clock output */
#define LFUSE_DEFAULT (FUSE_SUT0)

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
#define FUSE_BODENABLE  (unsigned char)~_BV(0)  /* Brown-out Detector Enable Signal */
#define EFUSE_DEFAULT (0xFF)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x96
#define SIGNATURE_2 0xC1

#define SLEEP_MODE_IDLE         (0)
#define SLEEP_MODE_PWR_DOWN     _BV(SM1)
#define SLEEP_MODE_PWR_SAVE     (_BV(SM0) | _BV(SM1))
#define SLEEP_MODE_STANDBY      (_BV(SM1) | _BV(SM2))
#define SLEEP_MODE_EXT_STANDBY  (_BV(SM0) | _BV(SM1) | _BV(SM2))

#endif /* _AVR_AT90SCR100_H_ */

