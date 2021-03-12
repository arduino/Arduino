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

/* $Id: iom64hve.h 2086 2009-12-15 03:24:16Z arcanum $ */

/* avr/iom64hve.h - definitions for ATmega64HVE */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom64hve.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATmega64HVE_H_
#define _AVR_ATmega64HVE_H_ 1


/* Registers and associated bit numbers. */

#define PINA _SFR_IO8(0x00)
#define PINA0 0
#define PINA1 1

#define DDRA _SFR_IO8(0x01)
#define DDA0 0
#define DDA1 1

#define PORTA _SFR_IO8(0x02)
#define PORTA0 0
#define PORTA1 1

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

#define TIFR0 _SFR_IO8(0x15)
#define TOV0 0
#define OCF0A 1
#define OCF0B 2
#define ICF0 3

#define TIFR1 _SFR_IO8(0x16)
#define TOV1 0
#define OCF1A 1
#define OCF1B 2
#define ICF1 3

#define PCIFR _SFR_IO8(0x1B)
#define PCIF0 0
#define PCIF1 1

#define EIFR _SFR_IO8(0x1C)
#define INTF0 0

#define EIMSK _SFR_IO8(0x1D)
#define INT0 0

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

#define GTCCR _SFR_IO8(0x23)
#define PSRSYNC 0
#define TSM 7

#define TCCR0A _SFR_IO8(0x24)
#define WGM00 0
#define ICS0 3
#define ICES0 4
#define ICNC0 5
#define ICEN0 6
#define TCW0 7

#define TCCR0B _SFR_IO8(0x25)
#define CS00 0
#define CS01 1
#define CS02 2

#define TCNT0 _SFR_IO16(0x26)

#define TCNT0L _SFR_IO8(0x26)
#define TCNT0L0 0
#define TCNT0L1 1
#define TCNT0L2 2
#define TCNT0L3 3
#define TCNT0L4 4
#define TCNT0L5 5
#define TCNT0L6 6
#define TCNT0L7 7

#define TCNT0H _SFR_IO8(0x27)
#define TCNT0H0 0
#define TCNT0H1 1
#define TCNT0H2 2
#define TCNT0H3 3
#define TCNT0H4 4
#define TCNT0H5 5
#define TCNT0H6 6
#define TCNT0H7 7

#define OCR0A _SFR_IO8(0x28)
#define OCR0A0 0
#define OCR0A1 1
#define OCR0A2 2
#define OCR0A3 3
#define OCR0A4 4
#define OCR0A5 5
#define OCR0A6 6
#define OCR0A7 7

#define OCR0B _SFR_IO8(0x29)
#define OCR0B0 0
#define OCR0B1 1
#define OCR0B2 2
#define OCR0B3 3
#define OCR0B4 4
#define OCR0B5 5
#define OCR0B6 6
#define OCR0B7 7

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

#define TCCR0C _SFR_IO8(0x2F)

#define OCDR _SFR_IO8(0x31)

#define SMCR _SFR_IO8(0x33)
#define SE 0
#define SM0 1
#define SM1 2
#define SM2 3

#define MCUSR _SFR_IO8(0x34)
#define PORF 0
#define EXTRF 1
#define BODRF 2
#define WDRF 3
#define OCDRF 4

#define MCUCR _SFR_IO8(0x35)
#define IVCE 0
#define IVSEL 1
#define PUD 4
#define CKOE 5

#define SPMCSR _SFR_IO8(0x37)
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define LBSET 3
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
#define CLKPCE 7

#define WUTCSR _SFR_MEM8(0x62)
#define WUTP0 0
#define WUTP1 1
#define WUTP2 2
#define WUTE 3
#define WUTR 4
#define WUTIE 6
#define WUTIF 7

#define WDTCLR _SFR_MEM8(0x63)
#define WDCLE 0
#define WDCL0 1
#define WDCL1 2

#define PRR0 _SFR_MEM8(0x64)
#define PRTIM0 0
#define PRTIM1 1
#define PRSPI 2
#define PRLIN 3

#define __AVR_HAVE_PRR0	((1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRLIN))
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRLIN

#define SOSCCALA _SFR_MEM8(0x66)
#define SCALA0 0
#define SCALA1 1
#define SCALA2 2
#define SCALA3 3
#define SCALA4 4
#define SCALA5 5
#define SCALA6 6
#define SCALA7 7

#define SOSCCALB _SFR_MEM8(0x67)
#define SCALB0 0
#define SCALB1 1
#define SCALB2 2
#define SCALB3 3
#define SCALB4 4
#define SCALB5 5
#define SCALB6 6
#define SCALB7 7

#define PCICR _SFR_MEM8(0x68)
#define PCIE0 0
#define PCIE1 1

#define EICRA _SFR_MEM8(0x69)
#define ISC00 0
#define ISC01 1

#define PCMSK0 _SFR_MEM8(0x6B)
#define PCINT0 0
#define PCINT1 1

#define PCMSK1 _SFR_MEM8(0x6C)
#define PCINT2 0
#define PCINT3 1
#define PCINT4 2
#define PCINT5 3
#define PCINT6 4
#define PCINT7 5
#define PCINT8 6
#define PCINT9 7

#define TIMSK0 _SFR_MEM8(0x6E)
#define TOIE0 0
#define OCIE0A 1
#define OCIE0B 2
#define ICIE0 3

#define TIMSK1 _SFR_MEM8(0x6F)
#define TOIE1 0
#define OCIE1A 1
#define OCIE1B 2
#define ICIE1 3

#define DIDR0 _SFR_MEM8(0x7E)
#define PA0DID 0
#define PA1DID 1

#define TCCR1A _SFR_MEM8(0x80)
#define WGM10 0
#define ICS1 3
#define ICES1 4
#define ICNC1 5
#define ICEN1 6
#define TCW1 7

#define TCCR1B _SFR_MEM8(0x81)
#define CS10 0
#define CS11 1
#define CS12 2

#define TCCR1C _SFR_MEM8(0x82)

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

#define OCR1A _SFR_MEM8(0x88)
#define OCR1A0 0
#define OCR1A1 1
#define OCR1A2 2
#define OCR1A3 3
#define OCR1A4 4
#define OCR1A5 5
#define OCR1A6 6
#define OCR1A7 7

#define OCR1B _SFR_MEM8(0x89)
#define OCR1B0 0
#define OCR1B1 1
#define OCR1B2 2
#define OCR1B3 3
#define OCR1B4 4
#define OCR1B5 5
#define OCR1B6 6
#define OCR1B7 7

#define LINCR _SFR_MEM8(0xC0)
#define LCMD0 0
#define LCMD1 1
#define LCMD2 2
#define LENA 3
#define LCONF0 4
#define LCONF1 5
#define LIN13 6
#define LSWRES 7

#define LINSIR _SFR_MEM8(0xC1)
#define LRXOK 0
#define LTXOK 1
#define LIDOK 2
#define LERR 3
#define LBUSY 4
#define LIDST0 5
#define LIDST1 6
#define LIDST2 7

#define LINENIR _SFR_MEM8(0xC2)
#define LENRXOK 0
#define LENTXOK 1
#define LENIDOK 2
#define LENERR 3

#define LINERR _SFR_MEM8(0xC3)
#define LBERR 0
#define LCERR 1
#define LPERR 2
#define LSERR 3
#define LFERR 4
#define LOVERR 5
#define LTOERR 6
#define LABORT 7

#define LINBTR _SFR_MEM8(0xC4)
#define LBT0 0
#define LBT1 1
#define LBT2 2
#define LBT3 3
#define LBT4 4
#define LBT5 5
#define LDISR 7

#define LINBRR _SFR_MEM16(0xC5)

#define LINBRRL _SFR_MEM8(0xC5)
#define LDIV0 0
#define LDIV1 1
#define LDIV2 2
#define LDIV3 3
#define LDIV4 4
#define LDIV5 5
#define LDIV6 6
#define LDIV7 7

#define LINBRRH _SFR_MEM8(0xC6)
#define LDIV8 0
#define LDIV9 1
#define LDIV10 2
#define LDIV11 3

#define LINDLR _SFR_MEM8(0xC7)
#define LRXDL0 0
#define LRXDL1 1
#define LRXDL2 2
#define LRXDL3 3
#define LTXDL0 4
#define LTXDL1 5
#define LTXDL2 6
#define LTXDL3 7

#define LINIDR _SFR_MEM8(0xC8)
#define LID0 0
#define LID1 1
#define LID2 2
#define LID3 3
#define LID4 4
#define LID5 5
#define LP0 6
#define LP1 7

#define LINSEL _SFR_MEM8(0xC9)
#define LINDX0 0
#define LINDX1 1
#define LINDX2 2
#define LAINC 3

#define LINDAT _SFR_MEM8(0xCA)
#define LDATA0 0
#define LDATA1 1
#define LDATA2 2
#define LDATA3 3
#define LDATA4 4
#define LDATA5 5
#define LDATA6 6
#define LDATA7 7

#define BGCSRA _SFR_MEM8(0xD1)
#define BGSC0 0
#define BGSC1 1
#define BGSC2 2

#define BGCRB _SFR_MEM8(0xD2)
#define BGCL0 0
#define BGCL1 1
#define BGCL2 2
#define BGCL3 3
#define BGCL4 4
#define BGCL5 5
#define BGCL6 6
#define BGCL7 7

#define BGCRA _SFR_MEM8(0xD3)
#define BGCN0 0
#define BGCN1 1
#define BGCN2 2
#define BGCN3 3
#define BGCN4 4
#define BGCN5 5
#define BGCN6 6
#define BGCN7 7

#define BGLR _SFR_MEM8(0xD4)
#define BGPL 0
#define BGPLE 1

#define PLLCSR _SFR_MEM8(0xD8)
#define PLLCIE 0
#define PLLCIF 1
#define LOCK 4
#define SWEN 5

#define PBOV _SFR_MEM8(0xDC)
#define PBOE0 0
#define PBOE3 3
#define PBOVCE 7

#define ADSCSRA _SFR_MEM8(0xE0)
#define SCMD0 0
#define SCMD1 1
#define SBSY 2

#define ADSCSRB _SFR_MEM8(0xE1)
#define CADICRB 0
#define CADACRB 1
#define CADICPS 2
#define VADICRB 4
#define VADACRB 5
#define VADICPS 6

#define ADCRA _SFR_MEM8(0xE2)
#define CKSEL 0
#define ADCMS0 1
#define ADCMS1 2
#define ADPSEL 3

#define ADCRB _SFR_MEM8(0xE3)
#define ADADES0 0
#define ADADES1 1
#define ADADES2 2
#define ADIDES0 3
#define ADIDES1 4

#define ADCRC _SFR_MEM8(0xE4)
#define CADRCT0 0
#define CADRCT1 1
#define CADRCT2 2
#define CADRCT3 3
#define CADRCM0 4
#define CADRCM1 5
#define CADEN 7

#define ADCRD _SFR_MEM8(0xE5)
#define CADDSEL 0
#define CADPDM0 1
#define CADPDM1 2
#define CADG0 3
#define CADG1 4
#define CADG2 5

#define ADCRE _SFR_MEM8(0xE6)
#define VADMUX0 0
#define VADMUX1 1
#define VADMUX2 2
#define VADPDM0 3
#define VADPDM1 4
#define VADREFS 5
#define VADEN 7

#define ADIFR _SFR_MEM8(0xE7)
#define CADICIF 0
#define CADACIF 1
#define CADRCIF 2
#define VADICIF 4
#define VADACIF 5

#define ADIMR _SFR_MEM8(0xE8)
#define CADICIE 0
#define CADACIE 1
#define CADRCIE 2
#define VADICIE 4
#define VADACIE 5

#define CADRCL _SFR_MEM16(0xE9)

#define CADRCLL _SFR_MEM8(0xE9)
#define CADRCL0 0
#define CADRCL1 1
#define CADRCL2 2
#define CADRCL3 3
#define CADRCL4 4
#define CADRCL5 5
#define CADRCL6 6
#define CADRCL7 7

#define CADRCLH _SFR_MEM8(0xEA)
#define CADRCL8 0
#define CADRCL9 1
#define CADRCL10 2
#define CADRCL11 3
#define CADRCL12 4
#define CADRCL13 5
#define CADRCL14 6
#define CADRCL15 7

#define CADIC _SFR_MEM16(0xEB)

#define CADICL _SFR_MEM8(0xEB)
#define CADIC0 0
#define CADIC1 1
#define CADIC2 2
#define CADIC3 3
#define CADIC4 4
#define CADIC5 5
#define CADIC6 6
#define CADIC7 7

#define CADICH _SFR_MEM8(0xEC)
#define CADIC8 0
#define CADIC9 1
#define CADIC10 2
#define CADIC11 3
#define CADIC12 4
#define CADIC13 5
#define CADIC14 6
#define CADIC15 7

#define CADAC0 _SFR_MEM8(0xED)
#define CADAC00 0
#define CADAC01 1
#define CADAC02 2
#define CADAC03 3
#define CADAC04 4
#define CADAC05 5
#define CADAC06 6
#define CADAC07 7

#define CADAC1 _SFR_MEM8(0xEE)
#define CADAC08 0
#define CADAC09 1
#define CADAC10 2
#define CADAC11 3
#define CADAC12 4
#define CADAC13 5
#define CADAC14 6
#define CADAC15 7

#define CADAC2 _SFR_MEM8(0xEF)
#define CADAC16 0
#define CADAC17 1
#define CADAC18 2
#define CADAC19 3
#define CADAC20 4
#define CADAC21 5
#define CADAC22 6
#define CADAC23 7

#define CADAC3 _SFR_MEM8(0xF0)
#define CADAC24 0
#define CADAC25 1
#define CADAC26 2
#define CADAC27 3
#define CADAC28 4
#define CADAC29 5
#define CADAC30 6
#define CADAC31 7

#define VADIC _SFR_MEM16(0xF1)

#define VADICL _SFR_MEM8(0xF1)
#define VADIC0 0
#define VADIC1 1
#define VADIC2 2
#define VADIC3 3
#define VADIC4 4
#define VADIC5 5
#define VADIC6 6
#define VADIC7 7

#define VADICH _SFR_MEM8(0xF2)
#define VADIC8 0
#define VADIC9 1
#define VADIC10 2
#define VADIC11 3
#define VADIC12 4
#define VADIC13 5
#define VADIC14 6
#define VADIC15 7

#define VADAC0 _SFR_MEM8(0xF3)
#define VADAC00 0
#define VADAC01 1
#define VADAC02 2
#define VADAC03 3
#define VADAC04 4
#define VADAC05 5
#define VADAC06 6
#define VADAC07 7

#define VADAC1 _SFR_MEM8(0xF4)
#define VADAC08 0
#define VADAC09 1
#define VADAC10 2
#define VADAC11 3
#define VADAC12 4
#define VADAC13 5
#define VADAC14 6
#define VADAC15 7

#define VADAC2 _SFR_MEM8(0xF5)
#define VADAC16 0
#define VADAC17 1
#define VADAC18 2
#define VADAC19 3
#define VADAC20 4
#define VADAC21 5
#define VADAC22 6
#define VADAC23 7

#define VADAC3 _SFR_MEM8(0xF6)
#define VADAC24 0
#define VADAC25 1
#define VADAC26 2
#define VADAC27 3
#define VADAC28 4
#define VADAC29 5
#define VADAC30 6
#define VADAC31 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt 0 */
#define PCINT0_vect_num  2
#define PCINT0_vect      _VECTOR(2)  /* Pin Change Interrupt 0 */
#define PCINT1_vect_num  3
#define PCINT1_vect      _VECTOR(3)  /* Pin Change Interrupt 1 */
#define WDT_vect_num  4
#define WDT_vect      _VECTOR(4)  /* Watchdog Timeout Interrupt */
#define WAKEUP_vect_num  5
#define WAKEUP_vect      _VECTOR(5)  /* Wakeup Timer Overflow */
#define TIMER1_IC_vect_num  6
#define TIMER1_IC_vect      _VECTOR(6)  /* Timer 1 Input capture */
#define TIMER1_COMPA_vect_num  7
#define TIMER1_COMPA_vect      _VECTOR(7)  /* Timer 1 Compare Match A */
#define TIMER1_COMPB_vect_num  8
#define TIMER1_COMPB_vect      _VECTOR(8)  /* Timer 1 Compare Match B */
#define TIMER1_OVF_vect_num  9
#define TIMER1_OVF_vect      _VECTOR(9)  /* Timer 1 overflow */
#define TIMER0_IC_vect_num  10
#define TIMER0_IC_vect      _VECTOR(10)  /* Timer 0 Input Capture */
#define TIMER0_COMPA_vect_num  11
#define TIMER0_COMPA_vect      _VECTOR(11)  /* Timer 0 Comapre Match A */
#define TIMER0_COMPB_vect_num  12
#define TIMER0_COMPB_vect      _VECTOR(12)  /* Timer 0 Compare Match B */
#define TIMER0_OVF_vect_num  13
#define TIMER0_OVF_vect      _VECTOR(13)  /* Timer 0 Overflow */
#define LIN_STATUS_vect_num  14
#define LIN_STATUS_vect      _VECTOR(14)  /* LIN Status Interrupt */
#define LIN_ERROR_vect_num  15
#define LIN_ERROR_vect      _VECTOR(15)  /* LIN Error Interrupt */
#define SPI_STC_vect_num  16
#define SPI_STC_vect      _VECTOR(16)  /* SPI Serial transfer complete */
#define VADC_CONV_vect_num  17
#define VADC_CONV_vect      _VECTOR(17)  /* Voltage ADC Instantaneous Conversion Complete */
#define VADC_ACC_vect_num  18
#define VADC_ACC_vect      _VECTOR(18)  /* Voltage ADC Accumulated Conversion Complete */
#define CADC_CONV_vect_num  19
#define CADC_CONV_vect      _VECTOR(19)  /* C-ADC Instantaneous Conversion Complete */
#define CADC_REG_CUR_vect_num  20
#define CADC_REG_CUR_vect      _VECTOR(20)  /* C-ADC Regular Current */
#define CADC_ACC_vect_num  21
#define CADC_ACC_vect      _VECTOR(21)  /* C-ADC Accumulated Conversion Complete */
#define EE_READY_vect_num  22
#define EE_READY_vect      _VECTOR(22)  /* EEPROM Ready */
#define SPM_vect_num  23
#define SPM_vect      _VECTOR(23)  /* SPM Ready */
#define PLL_vect_num  24
#define PLL_vect      _VECTOR(24)  /* PLL Lock Change Interrupt */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (25 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (128)
#define RAMSTART     (0x100)
#define RAMSIZE      (4096)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (NA)
#define XRAMEND      (RAMEND)
#define E2END        (0x3FF)
#define E2PAGESIZE   (4)
#define FLASHEND     (0xFFFF)


/* Fuses */
#define FUSE_MEMORY_SIZE 2

/* Low Fuse Byte */
#define FUSE_OSCSEL0  (unsigned char)~_BV(0)  /* Oscillator Select */
#define FUSE_SUT0  (unsigned char)~_BV(1)  /* Select start-up time */
#define FUSE_SUT1  (unsigned char)~_BV(2)  /* Select start-up time */
#define FUSE_CKDIV8  (unsigned char)~_BV(3)  /* Divide clock by 8 */
#define FUSE_BODEN  (unsigned char)~_BV(4)  /* Enable BOD */
#define FUSE_SPIEN  (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_EESAVE  (unsigned char)~_BV(6)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON  (unsigned char)~_BV(7)  /* Watchdog Timer Always On */
#define LFUSE_DEFAULT (FUSE_SPIEN & FUSE_CKDIV8 & FUSE_OSCSEL0)

/* High Fuse Byte */
#define FUSE_BOOTRST  (unsigned char)~_BV(0)  /* Select Reset Vector */
#define FUSE_BOOTSZ0  (unsigned char)~_BV(1)  /* Select Boot Size */
#define FUSE_BOOTSZ1  (unsigned char)~_BV(2)  /* Select Boot Size */
#define FUSE_DWEN  (unsigned char)~_BV(3)  /* Enable debugWire */
#define HFUSE_DEFAULT (FUSE_BOOTSZ1 & FUSE_BOOTSZ0)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x96
#define SIGNATURE_2 0x10


/* Device Pin Definitions */
#define PV2_DDR   DDRV
#define PV2_PORT  PORTV
#define PV2_PIN   PINV
#define PV2_BIT   2

#define PV1_DDR   DDRV
#define PV1_PORT  PORTV
#define PV1_PIN   PINV
#define PV1_BIT   1

#define NV_DDR   DDRNV
#define NV_PORT  PORTNV
#define NV_PIN   PINNV
#define NV_BIT   NV

#define VFET_DDR   DDRVFET
#define VFET_PORT  PORTVFET
#define VFET_PIN   PINVFET
#define VFET_BIT   VFET

#define CF1P_DDR   DDRCF1P
#define CF1P_PORT  PORTCF1P
#define CF1P_PIN   PINCF1P
#define CF1P_BIT   CF1P

#define CF1N_DDR   DDRCF1N
#define CF1N_PORT  PORTCF1N
#define CF1N_PIN   PINCF1N
#define CF1N_BIT   CF1N

#define CF2P_DDR   DDRCF2P
#define CF2P_PORT  PORTCF2P
#define CF2P_PIN   PINCF2P
#define CF2P_BIT   CF2P

#define CF2N_DDR   DDRCF2N
#define CF2N_PORT  PORTCF2N
#define CF2N_PIN   PINCF2N
#define CF2N_BIT   CF2N

#define VREG_DDR   DDRVREG
#define VREG_PORT  PORTVREG
#define VREG_PIN   PINVREG
#define VREG_BIT   VREG

#define VREF_DDR   DDRVREF
#define VREF_PORT  PORTVREF
#define VREF_PIN   PINVREF
#define VREF_BIT   VREF

#define VREFGND_DDR   DDRVREFGND
#define VREFGND_PORT  PORTVREFGND
#define VREFGND_PIN   PINVREFGND
#define VREFGND_BIT   VREFGND

#define PI_DDR   DDRI
#define PI_PORT  PORTI
#define PI_PIN   PINI
#define PI_BIT   

#define NI_DDR   DDRNI
#define NI_PORT  PORTNI
#define NI_PIN   PINNI
#define NI_BIT   NI

#define PA0_DDR   DDRA
#define PA0_PORT  PORTA
#define PA0_PIN   PINA
#define PA0_BIT   0

#define PA1_DDR   DDRA
#define PA1_PORT  PORTA
#define PA1_PIN   PINA
#define PA1_BIT   1

#define PA2_DDR   DDRA
#define PA2_PORT  PORTA
#define PA2_PIN   PINA
#define PA2_BIT   2

#define PB0_DDR   DDRB
#define PB0_PORT  PORTB
#define PB0_PIN   PINB
#define PB0_BIT   0

#define PB1_DDR   DDRB
#define PB1_PORT  PORTB
#define PB1_PIN   PINB
#define PB1_BIT   1

#define PB2_DDR   DDRB
#define PB2_PORT  PORTB
#define PB2_PIN   PINB
#define PB2_BIT   2

#define PB3_DDR   DDRB
#define PB3_PORT  PORTB
#define PB3_PIN   PINB
#define PB3_BIT   3

#define PC0_DDR   DDRC
#define PC0_PORT  PORTC
#define PC0_PIN   PINC
#define PC0_BIT   0

#define BATT_DDR   DDRBATT
#define BATT_PORT  PORTBATT
#define BATT_PIN   PINBATT
#define BATT_BIT   BATT

#define OC_DDR   DDROC
#define OC_PORT  PORTOC
#define OC_PIN   PINOC
#define OC_BIT   OC


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)

#endif /* _AVR_ATmega64HVE_H_ */

