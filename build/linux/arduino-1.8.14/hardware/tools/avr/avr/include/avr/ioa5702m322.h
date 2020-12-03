/*****************************************************************************
 *
 * Copyright (C) 2015 Atmel Corporation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * * Neither the name of the copyright holders nor the names of
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ****************************************************************************/


#ifndef _AVR_ATA5702M322_H_INCLUDED
#define _AVR_ATA5702M322_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioa5702m322.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define GPIOR0  _SFR_IO8(0x00)

#define PRR1    _SFR_IO8(0x01)
#define PRT1    0
#define PRT2    1
#define PRT3    2
#define PRT4    3
#define PRT5    4
#define PRLFR   5
#define PRLFTP  6
#define PRLFPH  7

#define __AVR_HAVE_PRR1	((1<<PRT1)|(1<<PRT2)|(1<<PRT3)|(1<<PRT4)|(1<<PRT5)|(1<<PRLFR)|(1<<PRLFTP)|(1<<PRLFPH))
#define __AVR_HAVE_PRR1_PRT1
#define __AVR_HAVE_PRR1_PRT2
#define __AVR_HAVE_PRR1_PRT3
#define __AVR_HAVE_PRR1_PRT4
#define __AVR_HAVE_PRR1_PRT5
#define __AVR_HAVE_PRR1_PRLFR
#define __AVR_HAVE_PRR1_PRLFTP
#define __AVR_HAVE_PRR1_PRLFPH

#define PRR2    _SFR_IO8(0x02)
#define PRSPI2  0
#define PRTWI2  1
#define PRSF    2
#define PRDF    3
#define PRTM    6
#define PRSSM   7

#define __AVR_HAVE_PRR2	((1<<PRSPI2)|(1<<PRTWI2)|(1<<PRSF)|(1<<PRDF)|(1<<PRTM)|(1<<PRSSM))
#define __AVR_HAVE_PRR2_PRSPI2
#define __AVR_HAVE_PRR2_PRTWI2
#define __AVR_HAVE_PRR2_PRSF
#define __AVR_HAVE_PRR2_PRDF
#define __AVR_HAVE_PRR2_PRTM
#define __AVR_HAVE_PRR2_PRSSM

#define PINB    _SFR_IO8(0x03)
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x04)
#define DDRB7   7
// Inserted "DDB7" from "DDRB7" due to compatibility
#define DDB7    7
#define DDRB6   6
// Inserted "DDB6" from "DDRB6" due to compatibility
#define DDB6    6
#define DDRB5   5
// Inserted "DDB5" from "DDRB5" due to compatibility
#define DDB5    5
#define DDRB4   4
// Inserted "DDB4" from "DDRB4" due to compatibility
#define DDB4    4
#define DDRB3   3
// Inserted "DDB3" from "DDRB3" due to compatibility
#define DDB3    3
#define DDRB2   2
// Inserted "DDB2" from "DDRB2" due to compatibility
#define DDB2    2
#define DDRB1   1
// Inserted "DDB1" from "DDRB1" due to compatibility
#define DDB1    1
#define DDRB0   0
// Inserted "DDB0" from "DDRB0" due to compatibility
#define DDB0    0

#define PORTB   _SFR_IO8(0x05)
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PINC    _SFR_IO8(0x06)
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x07)
#define DDRC2   2
// Inserted "DDC2" from "DDRC2" due to compatibility
#define DDC2    2
#define DDRC1   1
// Inserted "DDC1" from "DDRC1" due to compatibility
#define DDC1    1
#define DDRC0   0
// Inserted "DDC0" from "DDRC0" due to compatibility
#define DDC0    0

#define PORTC   _SFR_IO8(0x08)
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

#define PIND    _SFR_IO8(0x09)
#define PIND7   7
#define PIND6   6
#define PIND5   5
#define PIND4   4
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0

#define DDRD    _SFR_IO8(0x0A)
#define DDRD7   7
// Inserted "DDD7" from "DDRD7" due to compatibility
#define DDD7    7
#define DDRD6   6
// Inserted "DDD6" from "DDRD6" due to compatibility
#define DDD6    6
#define DDRD5   5
// Inserted "DDD5" from "DDRD5" due to compatibility
#define DDD5    5
#define DDRD4   4
// Inserted "DDD4" from "DDRD4" due to compatibility
#define DDD4    4
#define DDRD3   3
// Inserted "DDD3" from "DDRD3" due to compatibility
#define DDD3    3
#define DDRD2   2
// Inserted "DDD2" from "DDRD2" due to compatibility
#define DDD2    2
#define DDRD1   1
// Inserted "DDD1" from "DDRD1" due to compatibility
#define DDD1    1
#define DDRD0   0
// Inserted "DDD0" from "DDRD0" due to compatibility
#define DDD0    0

#define PORTD   _SFR_IO8(0x0B)
#define PORTD7  7
#define PORTD6  6
#define PORTD5  5
#define PORTD4  4
#define PORTD3  3
#define PORTD2  2
#define PORTD1  1
#define PORTD0  0

#define TPCR2   _SFR_IO8(0x0C)
#define TPMA    0
#define TPMOD   1
#define TPPSD   2
#define TPD     3
#define TPNFTO  4
#define TPWDLV0 5
#define TPWDLV1 6

#define TPFR    _SFR_IO8(0x0D)
#define TPF     0
#define TPFTF   1
#define TPNFTF  2
#define TPBERF  3

#define MCUCR   _SFR_IO8(0x0E)
#define IVL0    0
#define IVL1    1
#define SPIIO   2
#define ENPS    3
#define PUD     4
#define TRCCE   5
#define TRCEN   6
#define IVSEL   7

#define FSCR    _SFR_IO8(0x0F)
#define TXMOD   0
#define SFM     1
#define TXMS0   2
#define TXMS1   3
#define PAOER   4
#define PAON    7

/* Reserved [0x10] */

#define T1CR    _SFR_IO8(0x11)
#define T1OTM   0
#define T1CTM   1
#define T1CRM   2
#define T1TOP   4
#define T1RES   5
#define T1TOS   6
#define T1ENA   7

#define T2CR    _SFR_IO8(0x12)
#define T2OTM   0
#define T2CTM   1
#define T2CRM   2
#define T2TOP   4
#define T2RES   5
#define T2TOS   6
#define T2ENA   7

#define T3CR    _SFR_IO8(0x13)
#define T3OTM   0
#define T3CTM   1
#define T3CRM   2
#define T3CPRM  3
#define T3TOP   4
#define T3RES   5
#define T3TOS   6
#define T3ENA   7

#define T4CR    _SFR_IO8(0x14)
#define T4OTM   0
#define T4CTM   1
#define T4CRM   2
#define T4CPRM  3
#define T4TOP   4
#define T4RES   5
#define T4TOS   6
#define T4ENA   7

#define LTCMR   _SFR_IO8(0x15)
#define LTPS0   0
#define LTPS1   1
#define LTPS2   2
#define LTCRM   3
#define LTCIM   4
#define LTCM    5
#define LTSM    6
#define LTENA   7

#define EECR2   _SFR_IO8(0x16)
#define EEBRE   0
#define E2CIM   1
#define E2AVF   5
#define E2FF    6
#define E2CF    7

#define PHTCR   _SFR_IO8(0x17)
#define FRFIFO  5
#define CPM     6
#define CSM     7

#define LDFFL   _SFR_IO8(0x18)
#define LDFFL0  0
#define LDFFL1  1
#define LDFFL2  2
#define LDFFL3  3
#define LDFFL4  4
#define LDFFL5  5
#define LDFCLR  7

#define LDFD    _SFR_IO8(0x19)

#define PRR0    _SFR_IO8(0x1A)
#define PRSPI   0
#define PRLFRS  1
#define PRTXDC  2
#define PRCRC   3
#define PRVM    4
#define PRCO    5
#define PRCU    6
#define PRTWI1  7

#define __AVR_HAVE_PRR0	((1<<PRSPI)|(1<<PRLFRS)|(1<<PRTXDC)|(1<<PRCRC)|(1<<PRVM)|(1<<PRCO)|(1<<PRCU)|(1<<PRTWI1))
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRLFRS
#define __AVR_HAVE_PRR0_PRTXDC
#define __AVR_HAVE_PRR0_PRCRC
#define __AVR_HAVE_PRR0_PRVM
#define __AVR_HAVE_PRR0_PRCO
#define __AVR_HAVE_PRR0_PRCU
#define __AVR_HAVE_PRR0_PRTWI1

#define PHFR    _SFR_IO8(0x1B)
#define CRCEF   0
#define PHTBLF  1
#define PHDFF   2
#define PHIDFF  3
#define PHID0F  4
#define PHID1F  5

#define LFFR    _SFR_IO8(0x1C)
#define LFSYDF  0
#define LFDEF   1
#define LFEOF   2
#define LFTOF   3
#define LFSD    6
#define LFES    7

#define AESCR   _SFR_IO8(0x1D)
#define AESWK   0
#define AESWD   1
#define AESIM   2
#define AESD    3
#define AESXOR  4
#define AESRES  5
#define AESLKM  6
#define AESE    7

#define AESSR   _SFR_IO8(0x1E)
#define AESRF   0
#define AESERF  7

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5
#define EEPAGE  6
#define NVMBSY  7

#define EEDR    _SFR_IO8(0x20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0x22)

#define EEPR    _SFR_IO8(0x23)
#define EEAP0   0
#define EEAP1   1
#define EEAP2   2
#define EEAP3   3

#define GPIOR1  _SFR_IO8(0x24)

#define GPIOR2  _SFR_IO8(0x25)

#define PCICR   _SFR_IO8(0x26)
#define PCIE0   0
#define PCIE1   1

#define EIMSK   _SFR_IO8(0x27)
#define INT0    0
#define INT1    1

#define EIFR    _SFR_IO8(0x28)
#define INTF0   0
#define INTF1   1

#define LDFCKSW _SFR_IO8(0x29)
#define LDFSCSW 0
#define LDFSCKS 1

#define VMSCR   _SFR_IO8(0x2A)
#define VMF     0
#define VMDIH   1

#define MCUSR   _SFR_IO8(0x2B)
#define PORF    0
#define EXTRF   1
#define WDRF    3
#define DWRF    4
#define TPRF    5

#define SPCR    _SFR_IO8(0x2C)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _SFR_IO8(0x2D)
#define SPI2X   0
#define RXIF    4
#define TXIF    5
#define SPIF    7

#define SPDR    _SFR_IO8(0x2E)

#define LFCR0   _SFR_IO8(0x2F)
#define LFCE1   0
#define LFCE2   1
#define LFCE3   2
#define LFBR0   3
#define LFBR1   4
#define LFMG    5
#define LFRRT0  6
#define LFRRT1  7

#define LFCR1   _SFR_IO8(0x30)
#define RSST0   0
#define RSST1   1
#define LFFM1   2
#define ARMDE   3
#define FLLEN   4
#define ADTHEN  5
#define LFPEEN  6
#define LFRE    7

#define DWDR    _SFR_IO8(0x31)

#define T0IFR   _SFR_IO8(0x32)
#define T0F     0

/* Reserved [0x33..0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SELFPRGEN 0
#define PGERS   1
#define PGWRT   2
#define FLSEL0  3
#define FLSEL1  4
#define FLSEL2  5
#define RWWSB   6
#define SPMIE   7

#define SMCR    _SFR_IO8(0x38)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define TPSR    _SFR_IO8(0x39)
#define TPA     0
#define TPGAP   1
#define TPPSW   2
#define TPBCOK  3

#define LFCR2   _SFR_IO8(0x3A)
#define LFSEN0  0
#define LFSEN1  1
#define LFDAMP  2
#define LFVC0   5
#define LFVC1   6
#define LFVC2   7

#define LFCR3   _SFR_IO8(0x3B)
#define LFRCTEN 0
#define LFRCPCEN 1
#define LFRCPM  2
#define LFTON   3
#define LFTS0   4
#define LFTS1   5
#define LFTS2   6
#define LFSBEN  7

/* Reserved [0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define FSEN    _SFR_MEM8(0x60)
#define SDPU    0
#define SDEN    1
#define GAEN    2
#define PEEN    3
#define ASEN    4
#define ANTT    5

#define FSFCR   _SFR_MEM8(0x61)
#define BTSEL0  0
#define BTSEL1  1
#define ASDIV0  4
#define ASDIV1  5
#define ASDIV2  6
#define ASDIV3  7

/* Combine GACDIVL and GACDIVH */
#define GACDIV  _SFR_MEM16(0x62)

#define GACDIVL _SFR_MEM8(0x62)
#define GACDIVH _SFR_MEM8(0x63)

#define FFREQ1L _SFR_MEM8(0x64)

#define FFREQ1M _SFR_MEM8(0x65)

#define FFREQ1H _SFR_MEM8(0x66)

#define FFREQ2L _SFR_MEM8(0x67)

#define FFREQ2M _SFR_MEM8(0x68)

#define FFREQ2H _SFR_MEM8(0x69)

#define BBTE2   _SFR_MEM8(0x6A)
#define TDEPO   0
#define DITDIS  1

#define EICRA   _SFR_MEM8(0x6B)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

#define PCMSK0  _SFR_MEM8(0x6C)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  _SFR_MEM8(0x6D)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6
#define PCINT15 7

#define WDTCR   _SFR_MEM8(0x6E)
#define WDPS0   0
#define WDPS1   1
#define WDPS2   2
#define WDE     3
#define WDCE    4

#define T1CNT   _SFR_MEM8(0x6F)

#define T1COR   _SFR_MEM8(0x70)

#define T1MR    _SFR_MEM8(0x71)
#define T1CS0   0
#define T1CS1   1
#define T1PS0   2
#define T1PS1   3
#define T1PS2   4
#define T1PS3   5
#define T1DC0   6
#define T1DC1   7

#define T1IMR   _SFR_MEM8(0x72)
#define T1OIM   0
#define T1CIM   1

#define T2CNT   _SFR_MEM8(0x73)

#define T2COR   _SFR_MEM8(0x74)

#define T2MR    _SFR_MEM8(0x75)
#define T2CS0   0
#define T2CS1   1
#define T2PS0   2
#define T2PS1   3
#define T2PS2   4
#define T2PS3   5
#define T2DC0   6
#define T2DC1   7

#define T2IMR   _SFR_MEM8(0x76)
#define T2OIM   0
#define T2CIM   1

/* Combine T3CNTL and T3CNTH */
#define T3CNT   _SFR_MEM16(0x77)

#define T3CNTL  _SFR_MEM8(0x77)
#define T3CNTH  _SFR_MEM8(0x78)

/* Combine T3CORL and T3CORH */
#define T3COR   _SFR_MEM16(0x79)

#define T3CORL  _SFR_MEM8(0x79)
#define T3CORH  _SFR_MEM8(0x7A)

/* Combine T3ICRL and T3ICRH */
#define T3ICR   _SFR_MEM16(0x7B)

#define T3ICRL  _SFR_MEM8(0x7B)
#define T3ICRH  _SFR_MEM8(0x7C)

#define T3MRA   _SFR_MEM8(0x7D)
#define T3CS0   0
#define T3CS1   1
#define T3PS0   2
#define T3PS1   3
#define T3PS2   4

#define T3MRB   _SFR_MEM8(0x7E)
#define T3SCE   1
#define T3CNC   2
#define T3CE0   3
#define T3CE1   4
#define T3ICS0  5
#define T3ICS1  6
#define T3ICS2  7

#define T3IMR   _SFR_MEM8(0x7F)
#define T3OIM   0
#define T3CIM   1
#define T3CPIM  2

/* Combine T4CNTL and T4CNTH */
#define T4CNT   _SFR_MEM16(0x80)

#define T4CNTL  _SFR_MEM8(0x80)
#define T4CNTH  _SFR_MEM8(0x81)

/* Combine T4CORL and T4CORH */
#define T4COR   _SFR_MEM16(0x82)

#define T4CORL  _SFR_MEM8(0x82)
#define T4CORH  _SFR_MEM8(0x83)

/* Combine T4ICRL and T4ICRH */
#define T4ICR   _SFR_MEM16(0x84)

#define T4ICRL  _SFR_MEM8(0x84)
#define T4ICRH  _SFR_MEM8(0x85)

#define T4MRA   _SFR_MEM8(0x86)
#define T4CS0   0
#define T4CS1   1
#define T4PS0   2
#define T4PS1   3
#define T4PS2   4

#define T4MRB   _SFR_MEM8(0x87)
#define T4SCE   1
#define T4CNC   2
#define T4CE0   3
#define T4CE1   4
#define T4ICS0  5
#define T4ICS1  6
#define T4ICS2  7

#define T4IMR   _SFR_MEM8(0x88)
#define T4OIM   0
#define T4CIM   1
#define T4CPIM  2

#define T5TEMP  _SFR_MEM8(0x89)

/* Combine T5OCRL and T5OCRH */
#define T5OCR   _SFR_MEM16(0x8A)

#define T5OCRL  _SFR_MEM8(0x8A)
#define T5OCRH  _SFR_MEM8(0x8B)

#define T5CCR   _SFR_MEM8(0x8C)
#define T5CS0   0
#define T5CS1   1
#define T5CS2   2
#define T5CTC   3

/* Combine T5CNTL and T5CNTH */
#define T5CNT   _SFR_MEM16(0x8D)

#define T5CNTL  _SFR_MEM8(0x8D)
#define T5CNTH  _SFR_MEM8(0x8E)

#define T5IMR   _SFR_MEM8(0x8F)
#define T5OIM   0
#define T5CIM   1

#define LFCALR1 _SFR_MEM8(0x90)
#define LFSTC0  0
#define LFSTC1  1
#define LFSTC2  2
#define ICOMPRT0 3
#define ICOMPRT1 4
#define SEL150M0 5
#define SEL150M1 6
#define SEL150M2 7

#define LFCALR2 _SFR_MEM8(0x91)
#define LFSTRES0 0
#define LFSTRES1 1
#define LFSTRES2 2
#define LFSTRES3 3
#define LFSTRES4 4
#define LFSTRES5 5
#define LFSRM   6
#define TIKOMPD 7

#define LFCALR3 _SFR_MEM8(0x92)
#define TCGAIN10 0
#define TCGAIN11 1
#define TCGAIN12 2
#define TCGAIN13 3
#define TCGAIN14 4
#define TCGAIN15 5
#define TCGAIN16 6
#define TCGAIN17 7

#define LFCALR4 _SFR_MEM8(0x93)
#define TCGAIN20 0
#define TCGAIN21 1
#define TCGAIN22 2
#define TCGAIN23 3
#define TCGAIN24 4
#define TCGAIN25 5
#define TCGAIN26 6
#define TCGAIN27 7

#define LFCALR5 _SFR_MEM8(0x94)
#define TCGAIN30 0
#define TCGAIN31 1
#define TCGAIN32 2
#define TCGAIN34 4
#define TCGAIN35 5
#define TCGAIN36 6
#define TCGAIN37 7

#define LFCALR6 _SFR_MEM8(0x95)
#define TCGAIN40 0
#define TCGAIN41 1
#define TCGAIN42 2
#define TCGAIN43 3
#define TCGAIN44 4

#define LFCALR7 _SFR_MEM8(0x96)

#define LFCALR8 _SFR_MEM8(0x97)

#define LFCALR9 _SFR_MEM8(0x98)

#define LFCALR10 _SFR_MEM8(0x99)

#define LFCALR11 _SFR_MEM8(0x9A)

#define LFCALR12 _SFR_MEM8(0x9B)

#define LFCALR13 _SFR_MEM8(0x9C)

#define LFCALR14 _SFR_MEM8(0x9D)

#define LFCALR15 _SFR_MEM8(0x9E)

#define LFCALR16 _SFR_MEM8(0x9F)

#define LFCALR17 _SFR_MEM8(0xA0)

#define LFCALR18 _SFR_MEM8(0xA1)

#define LFCALR19 _SFR_MEM8(0xA2)

#define LFCALR20 _SFR_MEM8(0xA3)

#define LFCALR21 _SFR_MEM8(0xA4)

#define LFCALR22 _SFR_MEM8(0xA5)

#define LFCALR23 _SFR_MEM8(0xA6)

#define LFCALR24 _SFR_MEM8(0xA7)

#define LFCALR25 _SFR_MEM8(0xA8)

#define LFCALR26 _SFR_MEM8(0xA9)

#define LFCALR27 _SFR_MEM8(0xAA)

#define LFCALR28 _SFR_MEM8(0xAB)

#define LFCALR29 _SFR_MEM8(0xAC)

#define LFCALR30 _SFR_MEM8(0xAD)

#define LFCALR31 _SFR_MEM8(0xAE)

#define LFCALR32 _SFR_MEM8(0xAF)

#define LFCALR33 _SFR_MEM8(0xB0)

#define LFCALR34 _SFR_MEM8(0xB1)

#define LFCALR35 _SFR_MEM8(0xB2)

#define LFCALR36 _SFR_MEM8(0xB3)

#define LFCALR37 _SFR_MEM8(0xB4)

#define LFCALR38 _SFR_MEM8(0xB5)

#define LFCALR39 _SFR_MEM8(0xB6)

#define LFCALR40 _SFR_MEM8(0xB7)

#define LFCALR41 _SFR_MEM8(0xB8)

#define LFCALR42 _SFR_MEM8(0xB9)

#define LFCALR43 _SFR_MEM8(0xBA)

#define LFCALR44 _SFR_MEM8(0xBB)

#define LFCALR45 _SFR_MEM8(0xBC)

#define LFCALR46 _SFR_MEM8(0xBD)

#define LFCALR47 _SFR_MEM8(0xBE)

#define LFCALR48 _SFR_MEM8(0xBF)

#define LFCALR49 _SFR_MEM8(0xC0)

#define LFCALR50 _SFR_MEM8(0xC1)

#define LFCALR51 _SFR_MEM8(0xC2)

#define LFCALR52 _SFR_MEM8(0xC3)

#define LFCALR53 _SFR_MEM8(0xC4)

#define XFUSE   _SFR_MEM8(0xC5)

#define MRCCAL  _SFR_MEM8(0xC6)

#define FRCCAL  _SFR_MEM8(0xC7)

#define RCTCAL  _SFR_MEM8(0xC8)
#define FRCTC   0
#define MRCTC0  1
#define MRCTC1  2
#define MRCTC2  3
#define DI_MRCBG 4

#define CMSR    _SFR_MEM8(0xC9)
#define ECF     0

#define CMOCR   _SFR_MEM8(0xCA)
#define FRCAO   0
#define MRCAO   1
#define FRCACT  2

#define SUPFR   _SFR_MEM8(0xCB)
#define AVCCRF  0
#define AVCCLF  1

#define SUPCR   _SFR_MEM8(0xCC)
#define AVCCRM  0
#define AVCCLM  1
#define PVEN    2
#define AVDIC   3
#define AVEN    4
#define DVHEN   5
#define VMRESM  6
#define VMEMEN  7

#define SUPCA1  _SFR_MEM8(0xCD)
#define PV22    2
#define PVDIC   3
#define PVCAL0  4
#define PVCAL1  5
#define PVCAL2  6
#define PVCAL3  7

#define SUPCA2  _SFR_MEM8(0xCE)
#define BGCAL0  0
#define BGCAL1  1
#define BGCAL2  2
#define BGCAL3  3

#define SUPCA3  _SFR_MEM8(0xCF)
#define ACAL0   0
#define ACAL1   1
#define ACAL2   2
#define ACAL3   3
#define ACAL4   4
#define ACAL5   5
#define ACAL6   6
#define ACAL7   7

#define SUPCA4  _SFR_MEM8(0xD0)
#define ICONST0 0
#define ICONST1 1
#define ICONST2 2
#define ICONST3 3
#define ICONST4 4
#define ICONST5 5

#define CALRDY  _SFR_MEM8(0xD1)

#define DFS     _SFR_MEM8(0xD2)
#define DFFLRF  0
#define DFUFL   1
#define DFOFL   2

/* Reserved [0xD3..0xD4] */

#define DFL     _SFR_MEM8(0xD5)
#define DFFLS0  0
#define DFFLS1  1
#define DFFLS2  2
#define DFFLS3  3
#define DFFLS4  4
#define DFFLS5  5
#define DFCLR   7

#define DFWP    _SFR_MEM8(0xD6)

#define DFRP    _SFR_MEM8(0xD7)

#define DFD     _SFR_MEM8(0xD8)

#define DFI     _SFR_MEM8(0xD9)
#define DFFLIM  0
#define DFERIM  1

#define DFC     _SFR_MEM8(0xDA)
#define DFFLC0  0
#define DFFLC1  1
#define DFFLC2  2
#define DFFLC3  3
#define DFFLC4  4
#define DFFLC5  5
#define DFDRA   7

#define SFS     _SFR_MEM8(0xDB)
#define SFFLRF  0
#define SFUFL   1
#define SFOFL   2

#define SFL     _SFR_MEM8(0xDC)
#define SFFLS0  0
#define SFFLS1  1
#define SFFLS2  2
#define SFFLS3  3
#define SFFLS4  4
#define SFCLR   7

#define SFWP    _SFR_MEM8(0xDD)

#define SFRP    _SFR_MEM8(0xDE)

#define SFD     _SFR_MEM8(0xDF)

#define SFI     _SFR_MEM8(0xE0)
#define SFFLIM  0
#define SFERIM  1

#define SFC     _SFR_MEM8(0xE1)
#define SFFLC0  0
#define SFFLC1  1
#define SFFLC2  2
#define SFFLC3  3
#define SFFLC4  4
#define SFDRA   7

#define SSMCR   _SFR_MEM8(0xE2)
#define SSMTGE  2
#define SSMTPE  3
#define SSMPVE  4
#define SSMTAE  5

#define GTCCR   _SFR_MEM8(0xE3)
#define PSR10   0
#define TSM     7

#define SSMFBR  _SFR_MEM8(0xE4)
#define SSMPLDT 5

#define SSMRR   _SFR_MEM8(0xE5)
#define SSMR    0
#define SSMST   1

#define SSMSR   _SFR_MEM8(0xE6)
#define SSMESM0 0
#define SSMESM1 1
#define SSMESM2 2
#define SSMESM3 3
#define SSMERR  7

#define SSMIFR  _SFR_MEM8(0xE7)
#define SSMIF   0

#define SSMIMR  _SFR_MEM8(0xE8)
#define SSMIM   0

#define MSMSTR  _SFR_MEM8(0xE9)
#define SSMMST0 0
#define SSMMST1 1
#define SSMMST2 2
#define SSMMST3 3
#define SSMMST4 4

#define SSMSTR  _SFR_MEM8(0xEA)
#define SSMSTA0 0
#define SSMSTA1 1
#define SSMSTA2 2
#define SSMSTA3 3
#define SSMSTA4 4
#define SSMSTA5 5

#define VXMCTRL _SFR_MEM8(0xEB)
#define VX_SEL0 0
#define VX_SEL1 1
#define EN_VX   2
#define EN_VX_OUT 3
#define EN_VX_IN 4

#define MSMCR1  _SFR_MEM8(0xEC)
#define MSMSM00 0
#define MSMSM01 1
#define MSMSM02 2
#define MSMSM03 3
#define MSMSM10 4
#define MSMSM11 5
#define MSMSM12 6
#define MSMSM13 7

#define MSMCR2  _SFR_MEM8(0xED)
#define MSMSM20 0
#define MSMSM21 1
#define MSMSM22 2
#define MSMSM23 3
#define MSMSM30 4
#define MSMSM31 5
#define MSMSM32 6
#define MSMSM33 7

#define MSMCR3  _SFR_MEM8(0xEE)
#define MSMSM40 0
#define MSMSM41 1
#define MSMSM42 2
#define MSMSM43 3
#define MSMSM50 4
#define MSMSM51 5
#define MSMSM52 6
#define MSMSM53 7

#define MSMCR4  _SFR_MEM8(0xEF)
#define MSMSM60 0
#define MSMSM61 1
#define MSMSM62 2
#define MSMSM63 3
#define MSMSM70 4
#define MSMSM71 5
#define MSMSM72 6
#define MSMSM73 7

/* Reserved [0xF0..0xF6] */

#define SP2CR   _SFR_MEM8(0xF7)
#define SP2R0   0
#define SP2R1   1
#define CPHA2   2
#define CPOL2   3
#define MSTR2   4
#define DORD2   5
#define SP2E    6
#define SP2IE   7

#define SP2DR   _SFR_MEM8(0xF8)

#define SP2SR   _SFR_MEM8(0xF9)
#define SPI22X  0
#define WCOL2   6
#define SP2IF   7

/* Reserved [0xFA..0xFB] */

/* Combine TRCIDL and TRCIDH */
#define TRCID   _SFR_MEM16(0xFC)

#define TRCIDL  _SFR_MEM8(0xFC)
#define TRCIDH  _SFR_MEM8(0xFD)

/* Reserved [0xFE] */

#define TRCDR   _SFR_MEM8(0xFF)

#define FESR    _SFR_MEM8(0x100)
#define XRDY    2
#define PLCK    3
#define ANTS    4

#define FEEN1   _SFR_MEM8(0x101)
#define PLEN    0
#define PLCAL   1
#define XTOEN   2
#define PLSP1   6
#define ATEN    7

#define FEEN2   _SFR_MEM8(0x102)
#define PAEN    2
#define PLPEN   4
#define CPBIA   6

#define FELNA   _SFR_MEM8(0x103)

#define FEAT    _SFR_MEM8(0x104)
#define ANTN0   0
#define ANTN1   1
#define ANTN2   2
#define ANTN3   3

#define FEPAC   _SFR_MEM8(0x105)
#define PACR0   0
#define PACR1   1
#define PACR2   2
#define PACR3   3
#define PACR4   4
#define PACR5   5
#define PACR6   6
#define PACR7   7

#define FEVCT   _SFR_MEM8(0x106)

#define FEBT    _SFR_MEM8(0x107)
#define CTN20   0
#define CTN21   1
#define RTN20   2
#define RTN21   3

#define FEMS    _SFR_MEM8(0x108)
#define PLLS0   0
#define PLLS1   1
#define PLLS2   2
#define PLLS3   3
#define PLLM0   4
#define PLLM1   5
#define PLLM2   6
#define PLLM3   7

#define FETN4   _SFR_MEM8(0x109)
#define CTN40   0
#define CTN41   1
#define CTN42   2
#define CTN43   3
#define RTN40   4
#define RTN41   5
#define RTN42   6
#define RTN43   7

#define FECR    _SFR_MEM8(0x10A)
#define LBNHB   0
#define S4N3    1
#define PLCKG   4
#define ANPS    5

#define FEVCO   _SFR_MEM8(0x10B)
#define CPCC0   0
#define CPCC1   1
#define CPCC2   2
#define CPCC3   3
#define VCOB0   4
#define VCOB1   5
#define VCOB2   6
#define VCOB3   7

#define FEALR   _SFR_MEM8(0x10C)
#define RNGE0   0
#define RNGE1   1

#define FEANT   _SFR_MEM8(0x10D)
#define LVLC0   0
#define LVLC1   1
#define LVLC2   2
#define LVLC3   3

#define FEBIA   _SFR_MEM8(0x10E)

/* Reserved [0x10F..0x114] */

#define CLKOD   _SFR_MEM8(0x115)

#define CLKOCR  _SFR_MEM8(0x116)
#define CLKOS0  0
#define CLKOS1  1
#define CLKOEN  2

/* Reserved [0x117..0x11B] */

#define FETE1   _SFR_MEM8(0x11C)
#define ADCT    0
#define XTOT    1
#define LNLT    2
#define LNHT    3
#define PATE    4
#define AMPT    5
#define VCOT    6
#define ANTN    7

#define FETE2   _SFR_MEM8(0x11D)
#define RCCT    0
#define PPFT    1
#define LFT     2
#define CPT     3
#define PFDT    4
#define DADCT   5
#define PRET    6
#define SWALT   7

#define FETE3   _SFR_MEM8(0x11E)
#define BIOUT   0
#define RMPTST  1

#define FETD    _SFR_MEM8(0x11F)

#define TMFSM   _SFR_MEM8(0x120)
#define TMSSM0  0
#define TMSSM1  1
#define TMSSM2  2
#define TMSSM3  3
#define TMMSM0  4
#define TMMSM1  5
#define TMMSM2  6

/* Combine TMCRCL and TMCRCH */
#define TMCRC   _SFR_MEM16(0x121)

#define TMCRCL  _SFR_MEM8(0x121)
#define TMCRCH  _SFR_MEM8(0x122)

#define TMCSB   _SFR_MEM8(0x123)

/* Combine TMCIL and TMCIH */
#define TMCI    _SFR_MEM16(0x124)

#define TMCIL   _SFR_MEM8(0x124)
#define TMCIH   _SFR_MEM8(0x125)

/* Combine TMCPL and TMCPH */
#define TMCP    _SFR_MEM16(0x126)

#define TMCPL   _SFR_MEM8(0x126)
#define TMCPH   _SFR_MEM8(0x127)

#define TMSHR   _SFR_MEM8(0x128)

/* Combine TMTLLL and TMTLLH */
#define TMTLL   _SFR_MEM16(0x129)

#define TMTLLL  _SFR_MEM8(0x129)
#define TMTLLH  _SFR_MEM8(0x12A)

#define TMSSC   _SFR_MEM8(0x12B)
#define TMSSP0  0
#define TMSSP1  1
#define TMSSP2  2
#define TMSSP3  3
#define TMSSL0  4
#define TMSSL1  5
#define TMSSL2  6
#define TMSSH   7

#define TMSR    _SFR_MEM8(0x12C)
#define TMTCF   0

#define TMCR2   _SFR_MEM8(0x12D)
#define TMCRCE  0
#define TMCRCSE0 1
#define TMCRCSE1 2
#define TMNRZE  3
#define TMPOL   4
#define TMSSE   5
#define TMLSB   6

#define TMCR1   _SFR_MEM8(0x12E)
#define TMPIS0  0
#define TMPIS1  1
#define TMPIS2  2
#define TMSCS   3
#define TMCIM   4

/* Reserved [0x12F] */

#define LFDSR1  _SFR_MEM8(0x130)
#define LOTHA0  0
#define LOTHA1  1
#define HITHA0  2
#define HITHA1  3
#define CTTHA0  4
#define CTTHA1  5

#define LFDSR2  _SFR_MEM8(0x131)
#define LOTHB0  0
#define LOTHB1  1
#define HITHB0  2
#define HITHB1  3
#define CTTHB0  4
#define CTTHB1  5

#define LFDSR3  _SFR_MEM8(0x132)
#define PBDTH0  0
#define PBDTH1  1
#define QCTH0   3
#define QCTH1   4
#define QCTH2   5

#define LFDSR4  _SFR_MEM8(0x133)
#define SDTHA0  0
#define SDTHA1  1
#define SDTHA2  2
#define SCTHA0  3
#define SCTHA1  4
#define SCTHA2  5
#define SRSTC0  6
#define SRSTC1  7

#define LFDSR5  _SFR_MEM8(0x134)
#define SDTHB0  0
#define SDTHB1  1
#define SDTHB2  2
#define SCTHB0  3
#define SCTHB1  4
#define SCTHB2  5
#define SSUTA   6
#define SSUTB   7

#define LFDSR6  _SFR_MEM8(0x135)
#define TODU0   0
#define TODU1   1
#define TODU2   2
#define TODS0   3
#define TODS1   4
#define TODS2   5

#define LFDSR7  _SFR_MEM8(0x136)
#define PBSP0   0
#define PBSP1   1
#define PBG0    2
#define PBG1    3
#define MDSP0   4
#define MDSP1   5
#define MDG0    6
#define MDG1    7

#define LFDSR8  _SFR_MEM8(0x137)
#define CLD0    0
#define CLD1    1
#define CLD2    2
#define LGFE    3
#define ASWTH0  4
#define ASWTH1  5
#define ASWTH2  6

#define LFDSR9  _SFR_MEM8(0x138)
#define STW0    0
#define STW1    1
#define STW2    2
#define STW3    3
#define STW4    4

#define LFDSR10 _SFR_MEM8(0x139)
#define FCL0    0
#define FCL1    1
#define FCL2    2
#define FCL3    3
#define FCL4    4
#define FCL5    5
#define STBTH0  6
#define STBTH1  7

#define LFDSR11 _SFR_MEM8(0x13A)
#define TINITA0 0
#define TINITA1 1
#define TINITA2 2
#define TINITA3 3
#define TINITB0 4
#define TINITB1 5
#define TINITB2 6
#define TINITB3 7

#define EEPR1   _SFR_MEM8(0x13B)
#define EEPS4WD 0
#define EEPS4RD 1
#define EEPS5WD 2
#define EEPS5RD 3
#define EEPS6WD 4
#define EEPS6RD 5
#define EEPS7WD 6
#define EEPS7RD 7

#define EEPR2   _SFR_MEM8(0x13C)
#define EEPS8WD 0
#define EEPS8RD 1
#define EEPS9WD 2
#define EEPS9RD 3
#define EEPS10WD 4
#define EEPS10RD 5
#define EEPS11WD 6
#define EEPS11RD 7

#define EEPR3   _SFR_MEM8(0x13D)
#define EEPS12WD 0
#define EEPS12RD 1

/* Reserved [0x13E..0x144] */

#define CRCCR   _SFR_MEM8(0x145)
#define CRCRS   0
#define REFLI   1
#define REFLO   2

#define CRCDOR  _SFR_MEM8(0x146)

/* Reserved [0x147..0x150] */

#define LFSRCTM _SFR_MEM8(0x151)
#define LFSRCT1 0
#define LFSRCT2 1
#define LFSRCT3 2
#define LFSRCT4 3
#define LFSRCT5 4
#define LFSRCT6 5
#define LFSRCT7 6
#define LFSRCT8 7

#define DBCR    _SFR_MEM8(0x152)
#define DBMD    0
#define DBCS    1
#define DBTMS   2
#define DBHA    3

#define DBTC    _SFR_MEM8(0x153)

#define DBENB   _SFR_MEM8(0x154)

#define DBENC   _SFR_MEM8(0x155)

#define DBGSW   _SFR_MEM8(0x156)
#define DBGGS0  0
#define DBGGS1  1
#define DBGGS2  2
#define DBGGS3  3
#define CPBFOS0 4
#define CPBFOS1 5
#define CPBF    6
#define ATEST   7

#define SFFR    _SFR_MEM8(0x157)
#define RFL0    0
#define RFL1    1
#define RFL2    2
#define RFC     3
#define TFL0    4
#define TFL1    5
#define TFL2    6
#define TFC     7

#define SFIR    _SFR_MEM8(0x158)
#define RIL0    0
#define RIL1    1
#define RIL2    2
#define SRIE    3
#define TIL0    4
#define TIL1    5
#define TIL2    6
#define STIE    7

#define T2IFR   _SFR_MEM8(0x159)
#define T2OFF   0
#define T2COF   1

#define PGMST   _SFR_MEM8(0x15A)
#define PGMSYN0 0
#define PGMSYN1 1
#define PGMSYN2 2
#define PGMSYN3 3
#define PGMSYN4 4

#define EEST    _SFR_MEM8(0x15B)
#define EESYN0  0
#define EESYN1  1
#define EESYN2  2
#define EESYN3  3

#define LFSRCTL _SFR_MEM8(0x15C)
#define LFSRCT0 0

/* Reserved [0x15D..0x160] */

#define PCIFR   _SFR_MEM8(0x161)
#define PCIF0   0
#define PCIF1   1

#define T0CR    _SFR_MEM8(0x162)
#define T0PS0   0
#define T0PS1   1
#define T0PS2   2
#define T0IE    3
#define T0PR    4

/* Reserved [0x163] */

#define DBEND   _SFR_MEM8(0x164)

#define TPCR1   _SFR_MEM8(0x165)
#define TPQPLM  2
#define TPBR    4
#define TPDFCP0 5
#define TPDFCP1 6
#define TPMODE  7

#define TPIMR   _SFR_MEM8(0x166)
#define TPIM    0
#define TPFTIM  1
#define TPNFTIM 2
#define TPBERIM 3

#define TPDCR1  _SFR_MEM8(0x167)
#define TPDCL10 0
#define TPDCL11 1
#define TPDCL12 2
#define TPDCL13 3
#define TPDCL14 4
#define TPDCL15 5

#define TPDCR2  _SFR_MEM8(0x168)
#define TPDCL20 0
#define TPDCL21 1
#define TPDCL22 2
#define TPDCL23 3
#define TPDCL24 4
#define TPDCL25 5

#define TPDCR3  _SFR_MEM8(0x169)
#define TPDCL30 0
#define TPDCL31 1
#define TPDCL32 2
#define TPDCL33 3
#define TPDCL34 4
#define TPDCL35 5

#define TPDCR4  _SFR_MEM8(0x16A)
#define TPDCL40 0
#define TPDCL41 1
#define TPDCL42 2
#define TPDCL43 3
#define TPDCL44 4
#define TPDCL45 5

#define TPDCR5  _SFR_MEM8(0x16B)
#define TPDCL50 0
#define TPDCL51 1
#define TPDCL52 2
#define TPDCL53 3
#define TPDCL54 4
#define TPDCL55 5

#define TPECR1  _SFR_MEM8(0x16C)
#define TPECL10 0
#define TPECL11 1
#define TPECL12 2
#define TPECL13 3
#define TPECL14 4
#define TPECL15 5
#define TPECL16 6
#define TPECL17 7

#define TPECR2  _SFR_MEM8(0x16D)
#define TPECL20 0
#define TPECL21 1
#define TPECL22 2
#define TPECL23 3
#define TPECL24 4
#define TPECL25 5
#define TPECL26 6
#define TPECL27 7

#define TPECR3  _SFR_MEM8(0x16E)
#define TPECL30 0
#define TPECL31 1
#define TPECL32 2
#define TPECL33 3
#define TPECL34 4
#define TPECL35 5
#define TPECL36 6
#define TPECL37 7

#define TPECR4  _SFR_MEM8(0x16F)
#define TPECL40 0
#define TPECL41 1
#define TPECL42 2
#define TPECL43 3
#define TPECL44 4
#define TPECL45 5
#define TPECL46 6
#define TPECL47 7

#define TPECMR  _SFR_MEM8(0x170)
#define TPECM10 0
#define TPECM11 1
#define TPECM20 2
#define TPECM21 3
#define TPECM30 4
#define TPECM31 5
#define TPECM40 6
#define TPECM41 7

#define TPCR3   _SFR_MEM8(0x171)
#define TPTD    0
#define TPRD    1
#define TPTLIW  2
#define TPRCD   5

#define TPCR4   _SFR_MEM8(0x172)
#define TPBCCS0 0
#define TPBCCS1 1
#define TPBCCS2 2
#define TPBCCS3 3
#define TPBCM   4

#define TPCR5   _SFR_MEM8(0x173)
#define TPMUD0  0
#define TPMUD1  1
#define TPMUD2  2
#define TPMD0   4
#define TPMD1   5
#define TPMD2   6

/* Reserved [0x174] */

#define TPCALR1 _SFR_MEM8(0x175)
#define TPBG_IREF0 0
#define TPBG_IREF1 1
#define TPBG_IREF2 2
#define TPBG_IREF3 3
#define TPBG_IREF4 4
#define TPBG_IREF5 5

#define TPCALR2 _SFR_MEM8(0x176)
#define TPBG_UREF0 0
#define TPBG_UREF1 1
#define TPBG_UREF2 2
#define TPBG_UREF3 3
#define TPBG_UREF4 4
#define TPBG_UREF5 5
#define TPBG_UREF6 6

#define TPCALR3 _SFR_MEM8(0x177)
#define LFVCC_TPCAL0 0
#define LFVCC_TPCAL1 1
#define LFVCC_TPCAL2 2
#define TPORTH0 3
#define TPORTH1 4

#define TPCALR4 _SFR_MEM8(0x178)
#define TPINIT_CAL0 0
#define TPINIT_CAL1 1
#define TPINIT_CAL2 2
#define COMPVC_CAL0 3
#define COMPVC_CAL1 4

#define TPCALR5 _SFR_MEM8(0x179)

#define TPCALR6 _SFR_MEM8(0x17A)

#define TPCALR7 _SFR_MEM8(0x17B)

#define TPCALR8 _SFR_MEM8(0x17C)

#define TPCALR9 _SFR_MEM8(0x17D)

#define TPCALR10 _SFR_MEM8(0x17E)

#define AESDPR  _SFR_MEM8(0x17F)

#define AESKR   _SFR_MEM8(0x180)

#define AESDR   _SFR_MEM8(0x181)

#define GPIOR3  _SFR_MEM8(0x182)

#define GPIOR4  _SFR_MEM8(0x183)

#define GPIOR5  _SFR_MEM8(0x184)

#define GPIOR6  _SFR_MEM8(0x185)

#define GPIOR7  _SFR_MEM8(0x186)

#define GPIOR8  _SFR_MEM8(0x187)

#define PHBCRR  _SFR_MEM8(0x188)

/* Reserved [0x189..0x18D] */

#define LFCPR   _SFR_MEM8(0x18E)
#define LFCALP  0
#define LFCALRY 1
#define TPCD    6
#define LFCPCE  7

#define LFIMR   _SFR_MEM8(0x18F)
#define LFSYDIM 0
#define LFDEIM  1
#define LFEOIM  2

#define PHID0   _SFR_MEM16(0x190)

#define PHID0L  _SFR_MEM8(0x194)

#define PHID1   _SFR_MEM16(0x195)

#define PHID1L  _SFR_MEM8(0x199)

#define PHIDFR  _SFR_MEM8(0x19A)

#define LFSYSY  _SFR_MEM16(0x19B)

#define LFSYLE  _SFR_MEM8(0x19F)
#define LFSYLE0 0
#define LFSYLE1 1
#define LFSYLE2 2
#define LFSYLE3 3
#define LFSYLE4 4
#define LFSYLE5 5

#define LFSTOP  _SFR_MEM8(0x1A0)
#define LFSTSY0 0
#define LFSTSY1 1
#define LFSTSY2 2
#define LFSTSY3 3
#define LFSTL0  4
#define LFSTL1  5
#define LFSTL2  6

#define LTCOR   _SFR_MEM8(0x1A1)

#define T1IFR   _SFR_MEM8(0x1A2)
#define T1OFF   0
#define T1COF   1

/* Reserved [0x1A3] */

#define PHTBLR  _SFR_MEM8(0x1A4)

#define PHDFR   _SFR_MEM8(0x1A5)

#define LTEMR   _SFR_MEM8(0x1A6)
#define ID0EM   0
#define ID1EM   1
#define IDFEM   2
#define DFEM    3
#define TBLEM   4
#define FLEM    5
#define EOFEM   6
#define LTCOF   7

#define LFQC3   _SFR_MEM8(0x1A7)
#define LFQS30  0
#define LFQS31  1
#define LFQS32  2
#define LFQS33  3
#define LFCS30  4
#define LFCS31  5
#define LFCS32  6
#define LFCS33  7

#define LFQC2   _SFR_MEM8(0x1A8)
#define LFQS20  0
#define LFQS21  1
#define LFQS22  2
#define LFQS23  3
#define LFCS20  4
#define LFCS21  5
#define LFCS22  6
#define LFCS23  7

#define LFQC1   _SFR_MEM8(0x1A9)
#define LFQS10  0
#define LFQS11  1
#define LFQS12  2
#define LFQS13  3
#define LFCS10  4
#define LFCS11  5
#define LFCS12  6
#define LFCS13  7

#define TW2BR   _SFR_MEM8(0x1AA)

#define TW2CR   _SFR_MEM8(0x1AB)
#define TW2IE   0
#define TW2EN   2
#define TW2WC   3
#define TW2STO  4
#define TW2STA  5
#define TW2EA   6
#define TW2INT  7

#define TW2SR   _SFR_MEM8(0x1AC)
#define TW2PS0  0
#define TW2PS1  1
#define TW2S0   3
#define TW2S1   4
#define TW2S2   5
#define TW2S3   6
#define TW2S4   7

#define TW2DR   _SFR_MEM8(0x1AD)

#define TW2AR   _SFR_MEM8(0x1AE)
#define TW2GCE  0
#define TW2A0   1
#define TW2A1   2
#define TW2A2   3
#define TW2A3   4
#define TW2A4   5
#define TW2A5   6
#define TW2A6   7

#define TW2AMR  _SFR_MEM8(0x1AF)
#define TW2AM0  1
#define TW2AM1  2
#define TW2AM2  3
#define TW2AM3  4
#define TW2AM4  5
#define TW2AM5  6
#define TW2AM6  7

#define RSCR    _SFR_MEM8(0x1B0)
#define RSSDEN  0
#define RSOS    1
#define RSEOR   2
#define RSOFM   3
#define RSMODE0 4
#define RSMODE1 5
#define RSRES   7

#define RSSR    _SFR_MEM8(0x1B1)
#define RSRDY   0
#define RSSVLD  1

#define RSMS1R  _SFR_MEM8(0x1B2)
#define RSCH1E  0
#define RSCH2E  1
#define RSCH3E  2
#define RSINTM  3
#define RSSTIM  4
#define RSCMS   5
#define RSSSV   6
#define RSSCAL  7

#define RSMS2R  _SFR_MEM8(0x1B3)
#define RSSADR0 0
#define RSSADR1 1
#define RSSADR2 2
#define RSSADR3 3
#define RSAVGS0 4
#define RSAVGS1 5
#define RSAVGS2 6
#define RSAVGS3 7

#define RSFR    _SFR_MEM8(0x1B4)
#define RSOOR1  0
#define RSOOR2  1
#define RSOOR3  2
#define RSOFF   3
#define RSAOOR1 5
#define RSAOOR2 6
#define RSAOOR3 7

/* Reserved [0x1B5] */

#define RSCALIB _SFR_MEM8(0x1B6)
#define RSCALIB0 0
#define RSCALIB1 1
#define RSCALIB2 2
#define RSCALIB3 3
#define RSCALIB4 4
#define RSCALIB5 5
#define RSCALIB6 6
#define RSCALIB7 7

#define RSDLYR  _SFR_MEM8(0x1B7)
#define RSTRD0  0
#define RSTRD1  1
#define RSTRD2  2
#define RSTRD3  3
#define RSTRD4  4
#define RSTRD5  5
#define RSRD0   6
#define RSRD1   7

#define RSRES1L _SFR_MEM8(0x1B8)
#define RSRES1L0 0
#define RSRES1L1 1
#define RSRES1L2 2
#define RSRES1L3 3
#define RSRES1L4 4
#define RSRES1L5 5
#define RSRES1L6 6
#define RSRES1L7 7

#define RSRES1H _SFR_MEM8(0x1B9)
#define RSRES1H0 0
#define RSRES1H1 1
#define RSRES1H2 2
#define RSRES1H3 3
#define RSRES1H4 4
#define RSRES1H5 5
#define RSRES1H6 6
#define RSRES1H7 7

#define RSRES2L _SFR_MEM8(0x1BA)
#define RSRES2L0 0
#define RSRES2L1 1
#define RSRES2L2 2
#define RSRES2L3 3
#define RSRES2L4 4
#define RSRES2L5 5
#define RSRES2L6 6
#define RSRES2L7 7

#define RSRES2H _SFR_MEM8(0x1BB)
#define RSRES2H0 0
#define RSRES2H1 1
#define RSRES2H2 2
#define RSRES2H3 3
#define RSRES2H4 4
#define RSRES2H5 5
#define RSRES2H6 6
#define RSRES2H7 7

#define RSRES3L _SFR_MEM8(0x1BC)
#define RSRES3L0 0
#define RSRES3L1 1
#define RSRES3L2 2
#define RSRES3L3 3
#define RSRES3L4 4
#define RSRES3L5 5
#define RSRES3L6 6
#define RSRES3L7 7

#define RSRES3H _SFR_MEM8(0x1BD)
#define RSRES3H0 0
#define RSRES3H1 1
#define RSRES3H2 2
#define RSRES3H3 3
#define RSRES3H4 4
#define RSRES3H5 5
#define RSRES3H6 6
#define RSRES3H7 7

#define RSRES4L _SFR_MEM8(0x1BE)
#define RSRES4L0 0
#define RSRES4L1 1
#define RSRES4L2 2
#define RSRES4L3 3
#define RSRES4L4 4
#define RSRES4L5 5
#define RSRES4L6 6
#define RSRES4L7 7

#define RSRES4H _SFR_MEM8(0x1BF)
#define RSRES4H0 0
#define RSRES4H1 1
#define RSRES4H2 2
#define RSRES4H3 3
#define RSRES4H4 4
#define RSRES4H5 5
#define RSRES4H6 6
#define RSRES4H7 7

#define RSSRCR  _SFR_MEM8(0x1C0)
#define SRCMODE0 0
#define SRCMODE1 1
#define SRCMIN0 2
#define SRCMIN1 3
#define SRCCLR  4
#define SRCSTEP0 6
#define SRCSTEP1 7

#define SD12RR  _SFR_MEM8(0x1C1)
#define SD12RR0 0
#define SD12RR1 1
#define SD12RR2 2
#define SD12RR3 3
#define SD12RR4 4
#define SD12RR5 5
#define SD12RR6 6
#define SD12RR7 7

#define SD13RR  _SFR_MEM8(0x1C2)
#define SD13RR0 0
#define SD13RR1 1
#define SD13RR2 2
#define SD13RR3 3
#define SD13RR4 4
#define SD13RR5 5
#define SD13RR6 6
#define SD13RR7 7

#define SD23RR  _SFR_MEM8(0x1C3)
#define SD23RR0 0
#define SD23RR1 1
#define SD23RR2 2
#define SD23RR3 3
#define SD23RR4 4
#define SD23RR5 5
#define SD23RR6 6
#define SD23RR7 7

#define SD360R  _SFR_MEM8(0x1C4)
#define SD360R0 0
#define SD360R1 1
#define SD360R2 2
#define SD360R3 3
#define SD360R4 4
#define SD360R5 5
#define SD360R6 6
#define SD360R7 7

#define RSDBGR  _SFR_MEM8(0x1C5)
#define RSSANA  0
#define RSINFM  2
#define RSFPD   3
#define RSHOME  4
#define RSDBGS0 5
#define RSDBGS1 6
#define RSDBGEN 7

/* Reserved [0x1C6..0x1D0] */

#define LDFS    _SFR_MEM8(0x1D1)
#define LDFFLR  0
#define LDFUF   1
#define LDFOF   2

#define T4IFR   _SFR_MEM8(0x1D2)
#define T4OFF   0
#define T4COF   1
#define T4ICF   2

#define LDFWP   _SFR_MEM8(0x1D3)
#define LDFWP0  0
#define LDFWP1  1
#define LDFWP2  2
#define LDFWP3  3
#define LDFWP4  4
#define LDFWP5  5

#define LDFRP   _SFR_MEM8(0x1D4)
#define LDFRP0  0
#define LDFRP1  1
#define LDFRP2  2
#define LDFRP3  3
#define LDFRP4  4
#define LDFRP5  5

#define T5IFR   _SFR_MEM8(0x1D5)
#define T5OFF   0
#define T5COF   1

#define LDFIM   _SFR_MEM8(0x1D6)
#define LDFFLIM 0
#define LDFEIM  1

#define LDFC    _SFR_MEM8(0x1D7)
#define LDFFLC0 0
#define LDFFLC1 1
#define LDFFLC2 2
#define LDFFLC3 3
#define LDFFLC4 4
#define LDFFLC5 5
#define LDFMSB  6

#define PHIMR   _SFR_MEM8(0x1D8)
#define PHTBLIM 1
#define PHDFIM  2
#define PHIDFIM 3
#define PHID0IM 4
#define PHID1IM 5

#define PHCRCR  _SFR_MEM8(0x1D9)
#define CRCFR   2
#define CRCSE0  4
#define CRCSE1  5
#define CRCEN   7

#define PHCST   _SFR_MEM8(0x1DA)

/* Reserved [0x1DB] */

/* Combine PHCRPL and PHCRPH */
#define PHCRP   _SFR_MEM16(0x1DC)

#define PHCRPL  _SFR_MEM8(0x1DC)
#define PHCRPH  _SFR_MEM8(0x1DD)

#define PHCSR   _SFR_MEM8(0x1DE)

/* Reserved [0x1DF] */

#define CRCDIR  _SFR_MEM8(0x1E0)

#define T3IFR   _SFR_MEM8(0x1E1)
#define T3OFF   0
#define T3COF   1
#define T3ICF   2

/* Reserved [0x1E2] */

#define CMCR    _SFR_MEM8(0x1E3)
#define CMM0    0
#define CMM1    1
#define CMM2    2
#define CCS     3
#define CMONEN  6
#define CMCCE   7

#define CMIMR   _SFR_MEM8(0x1E4)
#define ECIE    0

#define CLPR    _SFR_MEM8(0x1E5)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLTPS0  3
#define CLTPS1  4
#define CLTPS2  5
#define CLPCE   7

#define VMCR    _SFR_MEM8(0x1E6)
#define VMLS0   0
#define VMLS1   1
#define VMLS2   2
#define VMLS3   3
#define VMIM    4
#define VMPS0   5
#define VMPS1   6
#define VMRS    7

#define DBONDR  _SFR_MEM8(0x1E7)
#define BBESD   0
#define AGND_BB 1
#define ISO_GND 2
#define AGND_LF 3
#define BTEST4  4
#define BTEST5  5
#define BTEST6  6

#define CALRDYLF _SFR_MEM8(0x1E8)

#define TW1BR   _SFR_MEM8(0x1E9)

#define TW1CR   _SFR_MEM8(0x1EA)
#define TW1IE   0
#define TW1EN   2
#define TW1WC   3
#define TW1STO  4
#define TW1STA  5
#define TW1EA   6
#define TW1INT  7

#define TW1SR   _SFR_MEM8(0x1EB)
#define TW1PS0  0
#define TW1PS1  1
#define TW1S0   3
#define TW1S1   4
#define TW1S2   5
#define TW1S3   6
#define TW1S4   7

#define TW1DR   _SFR_MEM8(0x1EC)

#define TW1AR   _SFR_MEM8(0x1ED)
#define TW1GCE  0
#define TW1A0   1
#define TW1A1   2
#define TW1A2   3
#define TW1A3   4
#define TW1A4   5
#define TW1A5   6
#define TW1A6   7

#define TW1AMR  _SFR_MEM8(0x1EE)
#define TW1AM0  1
#define TW1AM1  2
#define TW1AM2  3
#define TW1AM3  4
#define TW1AM4  5
#define TW1AM5  6
#define TW1AM6  7

#define PDSCR   _SFR_MEM8(0x1EF)
#define PDSC0   0
#define PDSC1   1
#define PDSC2   2
#define PDSC3   3
#define PDSC4   4
#define STBTEST 5
#define RSSISEL 6
#define ATBSEL  7

#define TMOCR   _SFR_MEM8(0x1F0)
#define TO1PIS0 0
#define TO1PIS1 1
#define TO2PIS0 2
#define TO2PIS1 3
#define TO3PIS0 4
#define TO3PIS1 5
#define TO4PIS0 6
#define TO4PIS1 7

#define SRCCAL  _SFR_MEM8(0x1F1)
#define SRCCAL1 0
#define SRCCAL2 1
#define SRCCAL3 2
#define SRCCAL4 3
#define SRCCAL5 4
#define SRCCAL6 5
#define SRCCAL7 6
#define SRCCAL8 7

#define SRCTCAL _SFR_MEM8(0x1F2)
#define SRCTC0  0
#define SRCTC1  1
#define SRCTC2  2
#define SRCS0   3
#define SRCS1   4
#define DIS_SRC 6
#define HOLD_SRC 7

#define SUPCA5  _SFR_MEM8(0x1F3)
#define IPTAT0  0
#define IPTAT1  1
#define IPTAT2  2
#define IPTAT3  3
#define IPTAT4  4
#define IPTAT5  5

#define SUPCA6  _SFR_MEM8(0x1F4)
#define VBGTR0  0
#define VBGTR1  1
#define VBGTR2  2
#define VBGTR3  3
#define VBGTR4  4
#define VBGTR5  5
#define VBGTR6  6
#define VBGTR7  7

#define SUPCA7  _SFR_MEM8(0x1F5)
#define VCCCAL0 0
#define VCCCAL1 1
#define VCCCAL2 2
#define LFVCCBD0 3
#define LFVCCBD1 4
#define LFVCCBD2 5

#define SUPCA8  _SFR_MEM8(0x1F6)
#define VSWBD0  0
#define VSWBD1  1
#define VSWBD2  2
#define DVCCBD0 3
#define DVCCBD1 4
#define DVCCBD2 5

#define SUPCA9  _SFR_MEM8(0x1F7)
#define VMEM0   0
#define VMEM1   1
#define VMEM2   2
#define VMEM3   3
#define VMEM4   4
#define VMEM5   5
#define VMEM6   6
#define VMEM7   7

#define SUPCA10 _SFR_MEM8(0x1F8)

#define TPCALR11 _SFR_MEM8(0x1F9)
#define MTBTR0  0
#define MTBTR1  1
#define ENDVBD  2
#define ENLFBD  3
#define ENVSWBD 4
#define TPCALR115 5
#define TPCALR116 6
#define TPCALR117 7

#define TPCALR12 _SFR_MEM8(0x1FA)
#define TPDMOD  0
#define TPCALR121 1
#define TPCALR122 2
#define TPCALR123 3
#define TPCALR124 4
#define TPCALR125 5
#define TPCALR126 6
#define TPCALR127 7

#define TPCALR13 _SFR_MEM8(0x1FB)

/* Reserved [0x1FC..0x1FD] */

#define PMTER   _SFR_MEM8(0x1FE)

#define SRCCALL _SFR_MEM8(0x1FF)
#define SRCCAL0 0



/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(1)
#define INT0_vect_num        1

/* External Interrupt Request 1 */
#define INT1_vect            _VECTOR(2)
#define INT1_vect_num        2

/* Pin Change Interrupt Request 0 */
#define PCI0_vect            _VECTOR(3)
#define PCI0_vect_num        3

/* Pin Change Interrupt Request 1 */
#define PCI1_vect            _VECTOR(4)
#define PCI1_vect_num        4

/* Voltage Monitoring Interrupt */
#define VMON_vect            _VECTOR(5)
#define VMON_vect_num        5

/* AVCC Reset Interrupt */
#define AVCCR_vect            _VECTOR(6)
#define AVCCR_vect_num        6

/* AVCC Low Interrupt */
#define AVCCL_vect            _VECTOR(7)
#define AVCCL_vect_num        7

/* Timer0 Interval Interrupt */
#define T0INT_vect            _VECTOR(8)
#define T0INT_vect_num        8

/* Timer/Counter1 Compare Match Interrupt */
#define T1COMP_vect            _VECTOR(9)
#define T1COMP_vect_num        9

/* Timer/Counter1 Overflow Interrupt */
#define T1OVF_vect            _VECTOR(10)
#define T1OVF_vect_num        10

/* Timer/Counter2 Compare Match Interrupt */
#define T2COMP_vect            _VECTOR(11)
#define T2COMP_vect_num        11

/* Timer/Counter2 Overflow Interrupt */
#define T2OVF_vect            _VECTOR(12)
#define T2OVF_vect_num        12

/* Timer/Counter3 Capture Event Interrupt */
#define T3CAP_vect            _VECTOR(13)
#define T3CAP_vect_num        13

/* Timer/Counter3 Compare Match Interrupt */
#define T3COMP_vect            _VECTOR(14)
#define T3COMP_vect_num        14

/* Timer/Counter3 Overflow Interrupt */
#define T3OVF_vect            _VECTOR(15)
#define T3OVF_vect_num        15

/* Timer/Counter4 Capture Event Interrupt */
#define T4CAP_vect            _VECTOR(16)
#define T4CAP_vect_num        16

/* Timer/Counter4 Compare Match Interrupt */
#define T4COMP_vect            _VECTOR(17)
#define T4COMP_vect_num        17

/* Timer/Counter4 Overflow Interrupt */
#define T4OVF_vect            _VECTOR(18)
#define T4OVF_vect_num        18

/* Timer/Counter5 Compare Match Interrupt */
#define T5COMP_vect            _VECTOR(19)
#define T5COMP_vect_num        19

/* Timer/Counter5 Overflow Interrupt */
#define T5OVF_vect            _VECTOR(20)
#define T5OVF_vect_num        20

/* SPI Serial Transfer Complete Interrupt */
#define SPI_vect            _VECTOR(21)
#define SPI_vect_num        21

/* SPI Rx Buffer Interrupt */
#define SRX_FIFO_vect            _VECTOR(22)
#define SRX_FIFO_vect_num        22

/* SPI Tx Buffer Interrupt */
#define STX_FIFO_vect            _VECTOR(23)
#define STX_FIFO_vect_num        23

/* Sequencer State Machine Interrupt */
#define SSM_vect            _VECTOR(24)
#define SSM_vect_num        24

/* Data FIFO fill level reached Interrupt */
#define DFFLR_vect            _VECTOR(25)
#define DFFLR_vect_num        25

/* Data FIFO overflow or underflow error Interrupt */
#define DFOUE_vect            _VECTOR(26)
#define DFOUE_vect_num        26

/* RSSI/Preamble FIFO fill level reached Interrupt */
#define SFFLR_vect            _VECTOR(27)
#define SFFLR_vect_num        27

/* RSSI/Preamble FIFO overflow or underflow error Interrupt */
#define SFOUE_vect            _VECTOR(28)
#define SFOUE_vect_num        28

/* Tx Modulator Telegram Finish Interrupt */
#define TMTCF_vect            _VECTOR(29)
#define TMTCF_vect_num        29

/* AES Krypto Unit Interrupt */
#define AES_vect            _VECTOR(30)
#define AES_vect_num        30

/* Transponder Mode Interrupt */
#define TPINT_vect            _VECTOR(31)
#define TPINT_vect_num        31

/* Transponder Timeout Error Interrupt */
#define TPTOERR_vect            _VECTOR(32)
#define TPTOERR_vect_num        32

/* LF receiver Identifier 0 Interrupt */
#define LFID0INT_vect            _VECTOR(33)
#define LFID0INT_vect_num        33

/* LF receiver Identifier 1 Interrupt */
#define LFID1INT_vect            _VECTOR(34)
#define LFID1INT_vect_num        34

/* LF receiver Frame End Interrupt */
#define LFFEINT_vect            _VECTOR(35)
#define LFFEINT_vect_num        35

/* LF receiver Bit Count Reached Interrupt */
#define LFBCR_vect            _VECTOR(36)
#define LFBCR_vect_num        36

/* LF receiver PreBurst Detected Interrupt */
#define LFPBD_vect            _VECTOR(37)
#define LFPBD_vect_num        37

/* LF receiver Decoder Error Interrupt */
#define LFDE_vect            _VECTOR(38)
#define LFDE_vect_num        38

/* LF receiver End of Telegram Interrupt */
#define LFEOT_vect            _VECTOR(39)
#define LFEOT_vect_num        39

/* LF receiver Timer Compare Match Interrupt */
#define LFTCOR_vect            _VECTOR(40)
#define LFTCOR_vect_num        40

/* LF receiver RSSI measurement Interrupt */
#define LFRSCO_vect            _VECTOR(41)
#define LFRSCO_vect_num        41

/* LF Data FIFO Fill Level Reached Interrupt */
#define LDFFLR_vect            _VECTOR(42)
#define LDFFLR_vect_num        42

/* LF Data FIFO Overflow or Underflow Error Interrupt */
#define LDFOUE_vect            _VECTOR(43)
#define LDFOUE_vect_num        43

/* External input Clock monitoring Interrupt */
#define EXCM_vect            _VECTOR(44)
#define EXCM_vect_num        44

/* EEPROM Error Correction Interrupt */
#define E2CINT_vect            _VECTOR(45)
#define E2CINT_vect_num        45

/* EEPROM Ready Interrupt */
#define ERDY_vect            _VECTOR(46)
#define ERDY_vect_num        46

/* Store Program Memory Ready */
#define SPMR_vect            _VECTOR(47)
#define SPMR_vect_num        47

/* TWI1 Interrupt */
#define TWI1_vect            _VECTOR(48)
#define TWI1_vect_num        48

/* SPI2 Interrupt */
#define SPI2_vect            _VECTOR(49)
#define SPI2_vect_num        49

/* TWI2 Interrupt */
#define TWI2_vect            _VECTOR(50)
#define TWI2_vect_num        50

#define _VECTORS_SIZE 204


/* Constants */

#define SPM_PAGESIZE 64
#define FLASHSTART   0x8000
#define FLASHEND     0xFFFF
#define RAMSTART     0x0200
#define RAMSIZE      1024
#define RAMEND       0x05FF
#define E2START     0
#define E2SIZE      2304
#define E2PAGESIZE  16
#define E2END       0x08FF
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 1

/* Fuse Byte */
#define FUSE_EXTCLKEN    (unsigned char)~_BV(0)
#define FUSE_EEACC       (unsigned char)~_BV(1)
#define FUSE_BOOTRST     (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_DWEN        (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SPIEN)



/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x69


#endif /* #ifdef _AVR_ATA5702M322_H_INCLUDED */

