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

/* $Id: iom16u2.h 2240 2011-05-09 22:18:18Z arcanum $ */

/* avr/iom16u2.h - definitions for ATmega16U2 */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom16u2.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATmega16U2_H_
#define _AVR_ATmega16U2_H_ 1


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
#define PINC4 4
#define PINC5 5
#define PINC6 6
#define PINC7 7

#define DDRC _SFR_IO8(0x07)
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC4 4
#define DDC5 5
#define DDC6 6
#define DDC7 7

#define PORTC _SFR_IO8(0x08)
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
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

#define TIFR0 _SFR_IO8(0x15)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2

#define TIFR1 _SFR_IO8(0x16)
#define TOV1 0
#define OCF1A 1
#define OCF1B 2
#define OCF1C 3
#define ICF1 5

#define PCIFR _SFR_IO8(0x1B)
#define PCIF0 0
#define PCIF1 1

#define EIFR _SFR_IO8(0x1C)
#define INTF0 0
#define INTF1 1
#define INTF2 2
#define INTF3 3
#define INTF4 4
#define INTF5 5
#define INTF6 6
#define INTF7 7

#define EIMSK _SFR_IO8(0x1D)
#define INT0 0
#define INT1 1
#define INT2 2
#define INT3 3
#define INT4 4
#define INT5 5
#define INT6 6
#define INT7 7

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

#define PLLCSR _SFR_IO8(0x29)
#define PLOCK 0
#define PLLE 1
#define PLLP0 2
#define PLLP1 3
#define PLLP2 4

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

#define DWDR _SFR_IO8(0x31)
#define DWDR0 0
#define DWDR1 1
#define DWDR2 2
#define DWDR3 3
#define DWDR4 4
#define DWDR5 5
#define DWDR6 6
#define DWDR7 7

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
#define USBRF 5

#define MCUCR _SFR_IO8(0x35)
#define IVCE 0
#define IVSEL 1
#define PUD 4

#define SPMCSR _SFR_IO8(0x37)
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define BLBSET 3
#define RWWSRE 4
#define SIGRD 5
#define RWWSB 6
#define SPMIE 7

#define EIND _SFR_IO8(0x3C)
#define EIND0 0

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

#define WDTCKD _SFR_MEM8(0x62)
#define WCLKD0 0
#define WCLKD1 1
#define WDEWIE 2
#define WDEWIF 3

#define REGCR _SFR_MEM8(0x63)
#define REGDIS 0

#define PRR0 _SFR_MEM8(0x64)
#define PRSPI 2
#define PRTIM1 3
#define PRTIM0 5

#define __AVR_HAVE_PRR0	((1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0))
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRTIM0

#define PRR1 _SFR_MEM8(0x65)
#define PRUSART1 0
#define PRUSB 7

#define __AVR_HAVE_PRR1	((1<<PRUSART1)|(1<<PRUSB))
#define __AVR_HAVE_PRR1_PRUSART1
#define __AVR_HAVE_PRR1_PRUSB

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

#define EICRA _SFR_MEM8(0x69)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC20 4
#define ISC21 5
#define ISC30 6
#define ISC31 7

#define EICRB _SFR_MEM8(0x6A)
#define ISC40 0
#define ISC41 1
#define ISC50 2
#define ISC51 3
#define ISC60 4
#define ISC61 5
#define ISC70 6
#define ISC71 7

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

#define TIMSK0 _SFR_MEM8(0x6E)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2

#define TIMSK1 _SFR_MEM8(0x6F)
#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define OCIE1C 3
#define ICIE1 5

#define DIDR1 _SFR_MEM8(0x7F)
#define AIN0D 0
#define AIN1D 1
#define AIN2D 2
#define AIN3D 3
#define AIN4D 4
#define AIN5D 5
#define AIN6D 6
#define AIN7D 7

#define TCCR1A _SFR_MEM8(0x80)
#define WGM10 0
#define WGM11 1
#define COM1C0 2
#define COM1C1 3
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
#define FOC1C 5
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

#define OCR1C _SFR_MEM16(0x8C)

#define OCR1CL _SFR_MEM8(0x8C)
#define OCR1CL0 0
#define OCR1CL1 1
#define OCR1CL2 2
#define OCR1CL3 3
#define OCR1CL4 4
#define OCR1CL5 5
#define OCR1CL6 6
#define OCR1CL7 7

#define OCR1CH _SFR_MEM8(0x8D)
#define OCR1CH0 0
#define OCR1CH1 1
#define OCR1CH2 2
#define OCR1CH3 3
#define OCR1CH4 4
#define OCR1CH5 5
#define OCR1CH6 6
#define OCR1CH7 7

#define UCSR1A _SFR_MEM8(0xC8)
#define MPCM1 0
#define U2X1 1
#define UPE1 2
#define DOR1 3
#define FE1 4
#define UDRE1 5
#define TXC1 6
#define RXC1 7

#define UCSR1B _SFR_MEM8(0xC9)
#define TXB81 0
#define RXB81 1
#define UCSZ12 2
#define TXEN1 3
#define RXEN1 4
#define UDRIE1 5
#define TXCIE1 6
#define RXCIE1 7

#define UCSR1C _SFR_MEM8(0xCA)
#define UCPOL1 0
#define UCSZ10 1
#define UCSZ11 2
#define USBS1 3
#define UPM10 4
#define UPM11 5
#define UMSEL10 6
#define UMSEL11 7

#define UCSR1D _SFR_MEM8(0xCB)
#define RTSEN 0
#define CTSEN 1

#define UBRR1 _SFR_MEM16(0xCC)

#define UBRR1L _SFR_MEM8(0xCC)
#define UBRR1_0 0
#define UBRR1_1 1
#define UBRR1_2 2
#define UBRR1_3 3
#define UBRR1_4 4
#define UBRR1_5 5
#define UBRR1_6 6
#define UBRR1_7 7

#define UBRR1H _SFR_MEM8(0xCD)
#define UBRR1_8 0
#define UBRR1_9 1
#define UBRR1_10 2
#define UBRR1_11 3

#define UDR1 _SFR_MEM8(0xCE)
#define UDR1_0 0
#define UDR1_1 1
#define UDR1_2 2
#define UDR1_3 3
#define UDR1_4 4
#define UDR1_5 5
#define UDR1_6 6
#define UDR1_7 7

#define CLKSEL0 _SFR_MEM8(0xD0)
#define CLKS 0
#define EXTE 2
#define RCE 3
#define EXSUT0 4
#define EXSUT1 5
#define RCSUT0 6
#define RCSUT1 7

#define CLKSEL1 _SFR_MEM8(0xD1)
#define EXCKSEL0 0
#define EXCKSEL1 1
#define EXCKSEL2 2
#define EXCKSEL3 3
#define RCCKSEL0 4
#define RCCKSEL1 5
#define RCCKSEL2 6
#define RCCKSEL3 7

#define CLKSTA _SFR_MEM8(0xD2)
#define EXTON 0
#define RCON 1

#define USBCON _SFR_MEM8(0xD8)
#define FRZCLK 5
#define USBE 7

#define UDCON _SFR_MEM8(0xE0)
#define DETACH 0
#define RMWKUP 1
#define RSTCPU 2

#define UDINT _SFR_MEM8(0xE1)
#define SUSPI 0
#define SOFI 2
#define EORSTI 3
#define WAKEUPI 4
#define EORSMI 5
#define UPRSMI 6

#define UDIEN _SFR_MEM8(0xE2)
#define SUSPE 0
#define SOFE 2
#define EORSTE 3
#define WAKEUPE 4
#define EORSME 5
#define UPRSME 6

#define UDADDR _SFR_MEM8(0xE3)
#define UADD0 0
#define UADD1 1
#define UADD2 2
#define UADD3 3
#define UADD4 4
#define UADD5 5
#define UADD6 6
#define ADDEN 7

#define UDFNUM _SFR_MEM16(0xE4)

#define UDFNUML _SFR_MEM8(0xE4)
#define FNUM0 0
#define FNUM1 1
#define FNUM2 2
#define FNUM3 3
#define FNUM4 4
#define FNUM5 5
#define FNUM6 6
#define FNUM7 7

#define UDFNUMH _SFR_MEM8(0xE5)
#define FNUM8 0
#define FNUM9 1
#define FNUM10 2

#define UDMFN _SFR_MEM8(0xE6)
#define FNCERR 4

#define UEINTX _SFR_MEM8(0xE8)
#define TXINI 0
#define STALLEDI 1
#define RXOUTI 2
#define RXSTPI 3
#define NAKOUTI 4
#define RWAL 5
#define NAKINI 6
#define FIFOCON 7

#define UENUM _SFR_MEM8(0xE9)
#define EPNUM0 0
#define EPNUM1 1
#define EPNUM2 2

#define UERST _SFR_MEM8(0xEA)
#define EPRST0 0
#define EPRST1 1
#define EPRST2 2
#define EPRST3 3
#define EPRST4 4

#define UECONX _SFR_MEM8(0xEB)
#define EPEN 0
#define RSTDT 3
#define STALLRQC 4
#define STALLRQ 5

#define UECFG0X _SFR_MEM8(0xEC)
#define EPDIR 0
#define EPTYPE0 6
#define EPTYPE1 7

#define UECFG1X _SFR_MEM8(0xED)
#define ALLOC 1
#define EPBK0 2
#define EPBK1 3
#define EPSIZE0 4
#define EPSIZE1 5
#define EPSIZE2 6

#define UESTA0X _SFR_MEM8(0xEE)
#define NBUSYBK0 0
#define NBUSYBK1 1
#define DTSEQ0 2
#define DTSEQ1 3
#define UNDERFI 5
#define OVERFI 6
#define CFGOK 7

#define UESTA1X _SFR_MEM8(0xEF)
#define CURRBK0 0
#define CURRBK1 1
#define CTRLDIR 2

#define UEIENX _SFR_MEM8(0xF0)
#define TXINE 0
#define STALLEDE 1
#define RXOUTE 2
#define RXSTPE 3
#define NAKOUTE 4
#define NAKINE 6
#define FLERRE 7

#define UEDATX _SFR_MEM8(0xF1)
#define DAT0 0
#define DAT1 1
#define DAT2 2
#define DAT3 3
#define DAT4 4
#define DAT5 5
#define DAT6 6
#define DAT7 7

#define UEBCLX _SFR_MEM8(0xF2)
#define BYCT0 0
#define BYCT1 1
#define BYCT2 2
#define BYCT3 3
#define BYCT4 4
#define BYCT5 5
#define BYCT6 6
#define BYCT7 7

#define UEINT _SFR_MEM8(0xF4)
#define EPINT0 0
#define EPINT1 1
#define EPINT2 2
#define EPINT3 3
#define EPINT4 4

#define PS2CON _SFR_MEM8(0xFA)
#define PS2EN 0

#define UPOE _SFR_MEM8(0xFB)
#define DMI 0
#define DPI 1
#define DATAI 2
#define SCKI 3
#define UPDRV0 4
#define UPDRV1 5
#define UPWE0 6
#define UPWE1 7


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
#define INT4_vect_num  5
#define INT4_vect      _VECTOR(5)  /* External Interrupt Request 4 */
#define INT5_vect_num  6
#define INT5_vect      _VECTOR(6)  /* External Interrupt Request 5 */
#define INT6_vect_num  7
#define INT6_vect      _VECTOR(7)  /* External Interrupt Request 6 */
#define INT7_vect_num  8
#define INT7_vect      _VECTOR(8)  /* External Interrupt Request 7 */
#define PCINT0_vect_num  9
#define PCINT0_vect      _VECTOR(9)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect_num  10
#define PCINT1_vect      _VECTOR(10)  /* Pin Change Interrupt Request 1 */
#define USB_GEN_vect_num  11
#define USB_GEN_vect      _VECTOR(11)  /* USB General Interrupt Request */
#define USB_COM_vect_num  12
#define USB_COM_vect      _VECTOR(12)  /* USB Endpoint/Pipe Interrupt Communication Request */
#define WDT_vect_num  13
#define WDT_vect      _VECTOR(13)  /* Watchdog Time-out Interrupt */
#define TIMER1_CAPT_vect_num  14
#define TIMER1_CAPT_vect      _VECTOR(14)  /* Timer/Counter2 Capture Event */
#define TIMER1_COMPA_vect_num  15
#define TIMER1_COMPA_vect      _VECTOR(15)  /* Timer/Counter2 Compare Match B */
#define TIMER0_COMPA_vect_num  19
#define TIMER0_COMPA_vect      _VECTOR(19)  /* Timer/Counter0 Compare Match A */
#define TIMER0_COMPB_vect_num  20
#define TIMER0_COMPB_vect      _VECTOR(20)  /* Timer/Counter0 Compare Match B */
#define TIMER0_OVF_vect_num  21
#define TIMER0_OVF_vect      _VECTOR(21)  /* Timer/Counter0 Overflow */
#define SPI_STC_vect_num  22
#define SPI_STC_vect      _VECTOR(22)  /* SPI Serial Transfer Complete */
#define USART1_RX_vect_num  23
#define USART1_RX_vect      _VECTOR(23)  /* USART1, Rx Complete */
#define USART1_UDRE_vect_num  24
#define USART1_UDRE_vect      _VECTOR(24)  /* USART1 Data register Empty */
#define USART1_TX_vect_num  25
#define USART1_TX_vect      _VECTOR(25)  /* USART1, Tx Complete */
#define ANALOG_COMP_vect_num  26
#define ANALOG_COMP_vect      _VECTOR(26)  /* Analog Comparator */
#define EE_READY_vect_num  27
#define EE_READY_vect      _VECTOR(27)  /* EEPROM Ready */
#define SPM_READY_vect_num  28
#define SPM_READY_vect      _VECTOR(28)  /* Store Program Memory Read */
#define TIMER1_COMPB_vect_num  16
#define TIMER1_COMPB_vect      _VECTOR(16)  /* Timer/Counter2 Compare Match B */
#define TIMER1_COMPC_vect_num  17
#define TIMER1_COMPC_vect      _VECTOR(17)  /* Timer/Counter2 Compare Match C */
#define TIMER1_OVF_vect_num  18
#define TIMER1_OVF_vect      _VECTOR(18)  /* Timer/Counter1 Overflow */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (29 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (128)
#define RAMSTART     (0x100)
#define RAMSIZE      (512)
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
#define LFUSE_DEFAULT (FUSE_CKDIV8 & FUSE_SUT1 & FUSE_SUT0 & FUSE_CKSEL3 & FUSE_CKSEL2 & FUSE_CKSEL1)

/* High Fuse Byte */
#define FUSE_BOOTRST  (unsigned char)~_BV(0)  /* Select Reset Vector */
#define FUSE_BOOTSZ0  (unsigned char)~_BV(1)  /* Select Boot Size */
#define FUSE_BOOTSZ1  (unsigned char)~_BV(2)  /* Select Boot Size */
#define FUSE_EESAVE  (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON  (unsigned char)~_BV(4)  /* Watchdog timer always on */
#define FUSE_SPIEN  (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_RSTDISBL  (unsigned char)~_BV(6)  /* External Reset Disable */
#define FUSE_DWEN  (unsigned char)~_BV(7)  /* dwbugWIRE Enable */
#define HFUSE_DEFAULT (FUSE_SPIEN & FUSE_BOOTSZ1 & FUSE_BOOTSZ0)

/* Extended Fuse Byte */
#define FUSE_BODLEVEL0  (unsigned char)~_BV(0)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1  (unsigned char)~_BV(1)  /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2  (unsigned char)~_BV(2)  /* Brown-out Detector trigger level */
#define FUSE_HWBE  (unsigned char)~_BV(3)  /* Hardware Boot Enable */
#define EFUSE_DEFAULT (0xFF)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x89


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)

#endif /* _AVR_ATmega16U2_H_ */

