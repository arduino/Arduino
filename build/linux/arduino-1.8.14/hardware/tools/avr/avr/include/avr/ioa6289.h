/* Copyright (c) 2008 Atmel Corporation
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

/* $Id: ioa6289.h 2102 2010-03-16 22:52:39Z joerg_wunsch $ */

/* avr/ioa6289.h - definitions for ATA6289 */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioa6289.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATA6289_H_
#define _AVR_ATA6289_H_ 1


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

#define DDRC _SFR_IO8(0x07)

#define PORTC _SFR_IO8(0x08)
#define PORTC0 0
#define PORTC1 1

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

#define CMCR _SFR_IO8(0x0F)
#define CMM0 0
#define CMM1 1
#define SRCD 2
#define CMONEN 3
#define CCS 4
#define ECINS 5
#define CMCCE 7

#define CMSR _SFR_IO8(0x10)
#define ECF 0

#define T2CRA _SFR_IO8(0x11)
#define T2OTM 0
#define T2CTM 1
#define T2CR 2
#define T2CRM 3
#define T2CPRM 4
#define T2ICS 5
#define T2TS 6
#define T2E 7

#define T2CRB _SFR_IO8(0x12)
#define T2SCE 0

#define T3CRA _SFR_IO8(0x14)
#define T3AC 0
#define T3SCE 1
#define T3CR 2
#define T3TS 6
#define T3E 7

#define VMCSR _SFR_IO8(0x16)
#define VMEN 0
#define VMLS0 1
#define VMLS1 2
#define VMLS2 3
#define VMIM 4
#define VMF 5
#define BODPD 6
#define BODLS 7

#define PCIFR _SFR_IO8(0x17)
#define PCIF0 0
#define PCIF1 1
#define PCIF2 2

#define LFFR _SFR_IO8(0x18)
#define LFWPF 0
#define LFBF 1
#define LFEDF 2
#define LFRF 3

#define SSFR _SFR_IO8(0x19)
#define MSENF 0
#define MSENO 1

#define T10IFR _SFR_IO8(0x1A)
#define T0F 0
#define T1F 1

#define T2IFR _SFR_IO8(0x1B)
#define T2OFF 0
#define T2COF 1
#define T2ICF 2
#define T2RXF 3
#define T2TXF 4
#define T2TCF 5

#define T3IFR _SFR_IO8(0x1C)
#define T3OFF 0
#define T3COAF 1
#define T3COBF 2
#define T3ICF 3

#define EIFR _SFR_IO8(0x1D)
#define INTF0 0
#define INTF1 1

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

#define PCICR _SFR_IO8(0x23)
#define PCIE0 0
#define PCIE1 1
#define PCIE2 2

#define EIMSK _SFR_IO8(0x24)
#define INT0 0
#define INT1 1

#define SVCR _SFR_IO8(0x27)
#define SVCS0 0
#define SVCS1 1
#define SVCS2 2
#define SVCS3 3
#define SVCS4 4

#define SCR _SFR_IO8(0x28)
#define SMS 0
#define SEN0 1
#define SEN1 2
#define SMEN 3

#define SCCR _SFR_IO8(0x29)
#define SRCC0 0
#define SRCC1 1
#define SCCS0 2
#define SCCS1 3
#define SCCS2 4

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

#define T2MDR _SFR_IO8(0x2F)
#define T2MDR0 0
#define T2MDR1 1
#define T2MDR2 2
#define T2MDR3 3
#define T2MDR4 4
#define T2MDR5 5
#define T2MDR6 6
#define T2MDR7 7

#define LFRR _SFR_IO8(0x30)
#define LFRR0 0
#define LFRR1 1
#define LFRR2 2
#define LFRR3 3
#define LFRR4 4
#define LFRR5 5
#define LFRR6 6

#define LFCDR _SFR_IO8(0x32)
#define LFDO 0
#define LFRST 6
#define LFSCE 7

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
#define TSRF 5

#define MCUCR _SFR_IO8(0x35)
#define IVCE 0
#define IVSEL 1
#define PUD 4

#define LFRB _SFR_IO8(0x36)
#define LFRB0 0
#define LFRB1 1
#define LFRB2 2
#define LFRB3 3
#define LFRB4 4
#define LFRB5 5
#define LFRB6 6
#define LFRB7 7

#define SPMCSR _SFR_IO8(0x37)
#define SELFPRGEN 0
#define PGERS 1
#define PGWRT 2
#define BLBSET 3
#define RWWSRE 4
#define RWWSB 6
#define SPMIE 7

#define T1CR _SFR_IO8(0x38)
#define T1PS0 0
#define T1PS1 1
#define T1PS2 2
#define T1CS0 3
#define T1CS1 4
#define T1CS2 5
#define T1IE 7

#define T0CR _SFR_IO8(0x39)
#define T0PAS0 0
#define T0PAS1 1
#define T0PAS2 2
#define T0IE 3
#define T0PR 4
#define T0PBS0 5
#define T0PBS1 6
#define T0PBS2 7

#define CMIMR _SFR_IO8(0x3B)
#define ECIE 0

#define CLKPR _SFR_IO8(0x3C)
#define CLKPS0 0
#define CLKPS1 1
#define CLKPS2 2
#define CLTPS0 3
#define CLTPS1 4
#define CLTPS2 5
#define CLPCE 7

#define WDTCR _SFR_MEM8(0x60)
#define WDPS0 0
#define WDPS1 1
#define WDPS2 2
#define WDE 3
#define WDCE 4

#define SIMSK _SFR_MEM8(0x61)
#define MSIE 0

#define TSCR _SFR_MEM8(0x64)
#define TSSD 0

#define SRCCAL _SFR_MEM8(0x65)
#define SCAL0 0
#define SCAL1 1
#define SCAL2 2
#define SCAL3 3
#define SCAL4 4
#define SCAL5 5
#define SCAL6 6
#define SCAL7 7

#define FRCCAL _SFR_MEM8(0x66)
#define FCAL0 0
#define FCAL1 1
#define FCAL2 2
#define FCAL3 3
#define FCAL4 4
#define FCAL5 5
#define FCAL6 6
#define FCAL7 7

#define MSVCAL _SFR_MEM8(0x67)
#define VRCAL0 0
#define VRCAL1 1
#define VRCAL2 2
#define VRCAL3 3
#define VRCAL4 4
#define VRCAL5 5
#define VRCAL6 6
#define VRCAL7 7

#define BGCAL _SFR_MEM8(0x68)
#define BGCAL0 0
#define BGCAL1 1
#define BGCAL2 2
#define BGCAL3 3
#define BGCAL4 4
#define BGCAL5 5
#define BGCAL6 6
#define BGCAL7 7

#define EICRA _SFR_MEM8(0x69)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define PCMSK0 _SFR_MEM8(0x6A)
#define PCINT0 0
#define PCINT1 1
#define PCINT2 2
#define PCINT3 3
#define PCINT4 4
#define PCINT5 5
#define PCINT6 6
#define PCINT7 7

#define PCMSK1 _SFR_MEM8(0x6B)
#define PCINT8 0
#define PCINT9 1
#define PCINT10 2

#define PCMSK2 _SFR_MEM8(0x6C)
#define PCINT16 0
#define PCINT17 1
#define PCINT18 2
#define PCINT19 3
#define PCINT20 4
#define PCINT21 5
#define PCINT22 6
#define PCINT23 7

#define T2ICR _SFR_MEM16(0x6E)

#define T2ICRL _SFR_MEM8(0x6E)
#define T2ICRL0 0
#define T2ICRL1 1
#define T2ICRL2 2
#define T2ICRL3 3
#define T2ICRL4 4
#define T2ICRL5 5
#define T2ICRL6 6
#define T2ICRL7 7

#define T2ICRH _SFR_MEM8(0x6F)
#define T2ICRH0 0
#define T2ICRH1 1
#define T2ICRH2 2
#define T2ICRH3 3
#define T2ICRH4 4
#define T2ICRH5 5
#define T2ICRH6 6
#define T2ICRH7 7

#define T2COR _SFR_MEM16(0x70)

#define T2CORL _SFR_MEM8(0x70)
#define T2CORL0 0
#define T2CORL1 1
#define T2CORL2 2
#define T2CORL3 3
#define T2CORL4 4
#define T2CORL5 5
#define T2CORL6 6
#define T2CORL7 7

#define T2CORH _SFR_MEM8(0x71)
#define T2CORH0 0
#define T2CORH1 1
#define T2CORH2 2
#define T2CORH3 3
#define T2CORH4 4
#define T2CORH5 5
#define T2CORH6 6
#define T2CORH7 7

#define T2MRA _SFR_MEM8(0x72)
#define T2CS0 0
#define T2CS1 1
#define T2CS2 2
#define T2CE0 3
#define T2CE1 4
#define T2CNC 5
#define T2TP0 6
#define T2TP1 7

#define T2MRB _SFR_MEM8(0x73)
#define T2M0 0
#define T2M1 1
#define T2M2 2
#define T2M3 3
#define T2TOP 4
#define T2CPOL 6
#define T2SSIE 7

#define T2IMR _SFR_MEM8(0x74)
#define T2OIM 0
#define T2CIM 1
#define T2CPIM 2
#define T2RXIM 3
#define T2TXIM 4
#define T2TCIM 5

#define T3ICR _SFR_MEM16(0x76)

#define T3ICRL _SFR_MEM8(0x76)
#define T3ICRL0 0
#define T3ICRL1 1
#define T3ICRL2 2
#define T3ICRL3 3
#define T3ICRL4 4
#define T3ICRL5 5
#define T3ICRL6 6
#define T3ICRL7 7

#define T3ICRH _SFR_MEM8(0x77)
#define T3ICRH0 0
#define T3ICRH1 1
#define T3ICRH2 2
#define T3ICRH3 3
#define T3ICRH4 4
#define T3ICRH5 5
#define T3ICRH6 6
#define T3ICRH7 7

#define T3CORA _SFR_MEM16(0x78)

#define T3CORAL _SFR_MEM8(0x78)
#define T3CORAL0 0
#define T3CORAL1 1
#define T3CORAL2 2
#define T3CORAL3 3
#define T3CORAL4 4
#define T3CORAL5 5
#define T3CORAL6 6
#define T3CORAL7 7

#define T3CORAH _SFR_MEM8(0x79)
#define T3CORAH0 0
#define T3CORAH1 1
#define T3CORAH2 2
#define T3CORAH3 3
#define T3CORAH4 4
#define T3CORAH5 5
#define T3CORAH6 6
#define T3CORAH7 7

#define T3CORB _SFR_MEM16(0x7A)

#define T3CORBL _SFR_MEM8(0x7A)
#define T3CORBL0 0
#define T3CORBL1 1
#define T3CORBL2 2
#define T3CORBL3 3
#define T3CORBL4 4
#define T3CORBL5 5
#define T3CORBL6 6
#define T3CORBL7 7

#define T3CORBH _SFR_MEM8(0x7B)
#define T3CORBH0 0
#define T3CORBH1 1
#define T3CORBH2 2
#define T3CORBH3 3
#define T3CORBH4 4
#define T3CORBH5 5
#define T3CORBH6 6
#define T3CORBH7 7

#define T3MRA _SFR_MEM8(0x7C)
#define T3CS0 0
#define T3CS1 1
#define T3CS2 2
#define T3CE0 3
#define T3CE1 4
#define T3CNC 5
#define T3ICS0 6
#define T3ICS1 7

#define T3MRB _SFR_MEM8(0x7D)
#define T3M0 0
#define T3M1 1
#define T3M2 2
#define T3TOP 4

#define T3CRB _SFR_MEM8(0x7E)
#define T3CTMA 0
#define T3SAMA 1
#define T3CRMA 2
#define T3CTMB 3
#define T3SAMB 4
#define T3CRMB 5
#define T3CPRM 6

#define T3IMR _SFR_MEM8(0x7F)
#define T3OIM 0
#define T3CAIM 1
#define T3CBIM 2
#define T3CPIM 3

#define LFIMR _SFR_MEM8(0x81)
#define LFWIM 0
#define LFBIM 1
#define LFEIM 2

#define LFRCR _SFR_MEM8(0x82)
#define LFEN 0
#define LFBM 1
#define LFWM0 2
#define LFWM1 3
#define LFRSS 4
#define LFCS0 5
#define LFCS1 6
#define LFCS2 7

#define LFHCR _SFR_MEM8(0x83)
#define LFHCR0 0
#define LFHCR1 1
#define LFHCR2 2
#define LFHCR3 3
#define LFHCR4 4
#define LFHCR5 5
#define LFHCR6 6

#define LFIDC _SFR_MEM16(0x84)

#define LFIDCL _SFR_MEM8(0x84)
#define LFIDCL_0 0
#define LFIDCL_1 1
#define LFIDCL_2 2
#define LFIDCL_3 3
#define LFIDCL_4 4
#define LFIDCL_5 5
#define LFIDCL_6 6
#define LFIDCL_7 7

#define LFIDCH _SFR_MEM8(0x85)
#define LFIDCH_8 0
#define LFIDCH_9 1
#define LFIDCH_10 2
#define LFIDCH_11 3
#define LFIDCH_12 4
#define LFIDCH_13 5
#define LFIDCH_14 6
#define LFIDCH_15 7

#define LFCAL _SFR_MEM16(0x86)

#define LFCALL _SFR_MEM8(0x86)
#define LFCAL_00 0
#define LFCAL_01 1
#define LFCAL_02 2
#define LFCAL_03 3
#define LFCAL_04 4
#define LFCAL_05 5
#define LFCAL_06 6
#define LFCAL_07 7

#define LFCALH _SFR_MEM8(0x87)
#define LFCAL_08 0
#define LFCAL_09 1
#define LFCAL_10 2
#define LFCAL_11 3
#define LFCAL_12 4
#define LFCAL_13 5
#define LFCAL_14 6
#define LFCAL_15 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt Request 0 */
#define INT1_vect_num  2
#define INT1_vect      _VECTOR(2)  /* External Interrupt Request 1 */
#define PCINT0_vect_num  3
#define PCINT0_vect      _VECTOR(3)  /* Pin Change Interrupt Request 0 */
#define PCINT1_vect_num  4
#define PCINT1_vect      _VECTOR(4)  /* Pin Change Interrupt Request 1 */
#define PCINT2_vect_num  5
#define PCINT2_vect      _VECTOR(5)  /* Pin Change Interrupt Request 2 */
#define INTVM_vect_num  6
#define INTVM_vect      _VECTOR(6)  /* Voltage Monitor Interrupt */
#define SENINT_vect_num  7
#define SENINT_vect      _VECTOR(7)  /* Sensor Interface Interrupt */
#define INTT0_vect_num  8
#define INTT0_vect      _VECTOR(8)  /* Timer0 Interval Interrupt */
#define LFWP_vect_num  9
#define LFWP_vect      _VECTOR(9)  /* LF-Receiver Wake-up Interrupt */
#define T3CAP_vect_num  10
#define T3CAP_vect      _VECTOR(10)  /* Timer/Counter3 Capture Event */
#define T3COMA_vect_num  11
#define T3COMA_vect      _VECTOR(11)  /* Timer/Counter3 Compare Match A */
#define T3COMB_vect_num  12
#define T3COMB_vect      _VECTOR(12)  /* Timer/Counter3 Compare Match B */
#define T3OVF_vect_num  13
#define T3OVF_vect      _VECTOR(13)  /* Timer/Counter3 Overflow */
#define T2CAP_vect_num  14
#define T2CAP_vect      _VECTOR(14)  /* Timer/Counter2 Capture Event */
#define T2COM_vect_num  15
#define T2COM_vect      _VECTOR(15)  /* Timer/Counter2 Compare Match */
#define T2OVF_vect_num  16
#define T2OVF_vect      _VECTOR(16)  /* Timer/Counter2 Overflow */
#define SPISTC_vect_num  17
#define SPISTC_vect      _VECTOR(17)  /* SPI Serial Transfer Complete */
#define LFRXB_vect_num  18
#define LFRXB_vect      _VECTOR(18)  /* LF Receive Buffer Interrupt */
#define INTT1_vect_num  19
#define INTT1_vect      _VECTOR(19)  /* Timer1 Interval Interrupt */
#define T2RXB_vect_num  20
#define T2RXB_vect      _VECTOR(20)  /* Timer2 SSI Receive Buffer Interrupt */
#define T2TXB_vect_num  21
#define T2TXB_vect      _VECTOR(21)  /* Timer2 SSI Transmit Buffer Interrupt */
#define T2TXC_vect_num  22
#define T2TXC_vect      _VECTOR(22)  /* Timer2 SSI Transmit Complete Interrupt */
#define LFREOB_vect_num  23
#define LFREOB_vect      _VECTOR(23)  /* LF-Receiver End of Burst Interrupt */
#define EXCM_vect_num  24
#define EXCM_vect      _VECTOR(24)  /* External Input Clock break down Interrupt */
#define EEREADY_vect_num  25
#define EEREADY_vect      _VECTOR(25)  /* EEPROM Ready Interrupt */
#define SPM_RDY_vect_num  26
#define SPM_RDY_vect      _VECTOR(26)  /* Store Program Memory Ready */

#define _VECTOR_SIZE 2 /* Size of individual vector. */
#define _VECTORS_SIZE (27 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (64)
#define RAMSTART     (0x100)
#define RAMSIZE      (512)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      RAMEND
#define E2END        (320 - 1)
#define E2PAGESIZE   (4)
#define FLASHEND     (8192 - 1)


/* Fuses */
#define FUSE_MEMORY_SIZE 2

/* Low Fuse Byte */
#define FUSE_TSRDI ~_BV(0)  /* Disable Temperature shutdown Reset  */
#define FUSE_BODEN ~_BV(1)  /* Enable Brown-out detection */
#define FUSE_FRCFS ~_BV(2)  /* Fast RC-Oscillator Frequency select */
#define FUSE_WDRCON ~_BV(3)  /* Enable Watchdog RC-Oscillator */
#define FUSE_SUT0 ~_BV(4)  /* Select start-up time */
#define FUSE_SUT1 ~_BV(5)  /* Select start-up time */
#define FUSE_CKOUT ~_BV(6)  /* Clock output */
#define FUSE_CKDIV8 ~_BV(7)  /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKDIV8 & FUSE_SUT0 & FUSE_WDRCON & FUSE_BODEN)

/* High Fuse Byte */
#define FUSE_BOOTRST ~_BV(0)  /* Select reset vector */
#define FUSE_BOOTSZ0 ~_BV(1)  /* Boot size select */
#define FUSE_BOOTSZ1 ~_BV(2)  /* Boot size select */
#define FUSE_EESAVE ~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON ~_BV(4)  /* Watchdog Timer Always On */
#define FUSE_SPIEN ~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_DWEN ~_BV(6)  /* debugWIRE Enable */
#define FUSE_EELOCK ~_BV(7)  /* Upper EEPROM Locked (disabled) */
#define HFUSE_DEFAULT (FUSE_SPIEN & FUSE_BOOTSZ1 & FUSE_BOOTSZ0)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x82

#define SLEEP_MODE_IDLE                     (0)
#define SLEEP_MODE_SENSOR_NOISE_REDUCTION   (_BV(SM0))
#define SLEEP_MODE_PWR_DOWN                 (_BV(SM1))

#endif /* _AVR_ATA6289_H_ */

