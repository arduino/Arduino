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


#ifndef _AVR_AT90PWM161_H_INCLUDED
#define _AVR_AT90PWM161_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "io90pwm161.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define ACSR    _SFR_IO8(0x00)
#define AC1O    1
#define AC2O    2
#define AC3O    3
#define AC1IF   5
#define AC2IF   6
#define AC3IF   7

#define TIMSK1  _SFR_IO8(0x01)
#define TOIE1   0
#define ICIE1   5

#define TIFR1   _SFR_IO8(0x02)
#define TOV1    0
#define ICF1    5

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

#define ADCSRA  _SFR_IO8(0x06)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADCSRB  _SFR_IO8(0x07)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADTS3   3
#define ADSSEN  4
#define ADNCDIS 6
#define ADHSM   7

#define ADMUX   _SFR_IO8(0x08)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define ADLAR   5
#define REFS0   6
#define REFS1   7

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

#define PINE    _SFR_IO8(0x0C)
#define PINE2   2
#define PINE1   1
#define PINE0   0

#define DDRE    _SFR_IO8(0x0D)
#define DDRE2   2
// Inserted "DDE2" from "DDRE2" due to compatibility
#define DDE2    2
#define DDRE1   1
// Inserted "DDE1" from "DDRE1" due to compatibility
#define DDE1    1
#define DDRE0   0
// Inserted "DDE0" from "DDRE0" due to compatibility
#define DDE0    0

#define PORTE   _SFR_IO8(0x0E)
#define PORTE2  2
#define PORTE1  1
#define PORTE0  0

#define PIM0    _SFR_IO8(0x0F)
#define PEOPE0  0
#define PEOEPE0 1
#define PEVE0A  3
#define PEVE0B  4

#define PIFR0   _SFR_IO8(0x10)
#define PEOP0   0
#define PRN00   1
#define PRN01   2
#define PEV0A   3
#define PEV0B   4
#define POAC0A  6
#define POAC0B  7

#define PCNF0   _SFR_IO8(0x11)
#define PCLKSEL0 1
#define POP0    2
#define PMODE00 3
#define PMODE01 4
#define PLOCK0  5
#define PALOCK0 6
#define PFIFTY0 7

#define PCTL0   _SFR_IO8(0x12)
#define PRUN0   0
#define PCCYC0  1
#define PAOC0A  3
#define PAOC0B  4
#define PBFM00  2
#define PBFM01  5
#define PPRE00  6
#define PPRE01  7

#define PIM2    _SFR_IO8(0x13)
#define PEOPE2  0
#define PEOEPE2 1
#define PEVE2A  3
#define PEVE2B  4
#define PSEIE2  5

#define PIFR2   _SFR_IO8(0x14)
#define PEOP2   0
#define PRN20   1
#define PRN21   2
#define PEV2A   3
#define PEV2B   4
#define PSEI2   5
#define POAC2A  6
#define POAC2B  7

#define PCNF2   _SFR_IO8(0x15)
#define POME2   0
#define PCLKSEL2 1
#define POP2    2
#define PMODE20 3
#define PMODE21 4
#define PLOCK2  5
#define PALOCK2 6
#define PFIFTY2 7

#define PCTL2   _SFR_IO8(0x16)
#define PRUN2   0
#define PCCYC2  1
#define PARUN2  2
#define PAOC2A  3
#define PAOC2B  4
#define PBFM2   5
#define PPRE20  6
#define PPRE21  7

#define SPCR    _SFR_IO8(0x17)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _SFR_IO8(0x18)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define GPIOR0  _SFR_IO8(0x19)
#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define GPIOR1  _SFR_IO8(0x1A)
#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR2  _SFR_IO8(0x1B)
#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

#define EECR    _SFR_IO8(0x1C)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5
#define EEPAGE  6
#define NVMBSY  7

#define EEDR    _SFR_IO8(0x1D)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x1E)

#define EEARL   _SFR_IO8(0x1E)
#define EEARH   _SFR_IO8(0x1F)

#define EIFR    _SFR_IO8(0x20)
#define INTF0   0
#define INTF1   1
#define INTF2   2

#define EIMSK   _SFR_IO8(0x21)
#define INT0    0
#define INT1    1
#define INT2    2

/* Combine OCR0SBL and OCR0SBH */
#define OCR0SB  _SFR_IO16(0x22)

#define OCR0SBL _SFR_IO8(0x22)
#define OCR0SBH _SFR_IO8(0x23)

/* Combine OCR0RBL and OCR0RBH */
#define OCR0RB  _SFR_IO16(0x24)

#define OCR0RBL _SFR_IO8(0x24)
#define OCR0RBH _SFR_IO8(0x25)

/* Combine OCR2SBL and OCR2SBH */
#define OCR2SB  _SFR_IO16(0x26)

#define OCR2SBL _SFR_IO8(0x26)
#define OCR2SBH _SFR_IO8(0x27)

/* Combine OCR2RBL and OCR2RBH */
#define OCR2RB  _SFR_IO16(0x28)

#define OCR2RBL _SFR_IO8(0x28)
#define OCR2RBH _SFR_IO8(0x29)

/* Combine OCR0RAL and OCR0RAH */
#define OCR0RA  _SFR_IO16(0x2A)

#define OCR0RAL _SFR_IO8(0x2A)
#define OCR0RAH _SFR_IO8(0x2B)

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_IO16(0x2C)
#endif
#define ADCW    _SFR_IO16(0x2C)

#define ADCL    _SFR_IO8(0x2C)
#define ADCH    _SFR_IO8(0x2D)

/* Combine OCR2RAL and OCR2RAH */
#define OCR2RA  _SFR_IO16(0x2E)

#define OCR2RAL _SFR_IO8(0x2E)
#define OCR2RAH _SFR_IO8(0x2F)

/* Reserved [0x30..0x32] */

#define SMCR    _SFR_IO8(0x33)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define MCUSR   _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

#define MCUCR   _SFR_IO8(0x35)
#define IVCE    0
#define IVSEL   1
#define CKRC81  2
#define RSTDIS  3
#define PUD     4

#define SPDR    _SFR_IO8(0x36)

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define SIGRD   5
#define RWWSB   6
#define SPMIE   7

#define DACL    _SFR_IO8(0x38)
#define DACL0   0
#define DACL1   1
#define DACL2   2
#define DACL3   3
#define DACL4   4
#define DACL5   5
#define DACL6   6
#define DACL7   7

#define DACH    _SFR_IO8(0x39)
#define DACH0   0
#define DACH1   1
#define DACH2   2
#define DACH3   3
#define DACH4   4
#define DACH5   5
#define DACH6   6
#define DACH7   7

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_IO16(0x3A)

#define TCNT1L  _SFR_IO8(0x3A)
#define TCNT1H  _SFR_IO8(0x3B)

/* Reserved [0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

/* Combine OCR0SAL and OCR0SAH */
#define OCR0SA  _SFR_MEM16(0x60)

#define OCR0SAL _SFR_MEM8(0x60)
#define OCR0SAH _SFR_MEM8(0x61)

#define PFRC0A  _SFR_MEM8(0x62)
#define PRFM0A0 0
#define PRFM0A1 1
#define PRFM0A2 2
#define PRFM0A3 3
#define PFLTE0A 4
#define PELEV0A 5
#define PISEL0A 6
#define PCAE0A  7

#define PFRC0B  _SFR_MEM8(0x63)
#define PRFM0B0 0
#define PRFM0B1 1
#define PRFM0B2 2
#define PRFM0B3 3
#define PFLTE0B 4
#define PELEV0B 5
#define PISEL0B 6
#define PCAE0B  7

/* Combine OCR2SAL and OCR2SAH */
#define OCR2SA  _SFR_MEM16(0x64)

#define OCR2SAL _SFR_MEM8(0x64)
#define OCR2SAH _SFR_MEM8(0x65)

#define PFRC2A  _SFR_MEM8(0x66)
#define PRFM2A0 0
#define PRFM2A1 1
#define PRFM2A2 2
#define PRFM2A3 3
#define PFLTE2A 4
#define PELEV2A 5
#define PISEL2A 6
#define PCAE2A  7

#define PFRC2B  _SFR_MEM8(0x67)
#define PRFM2B0 0
#define PRFM2B1 1
#define PRFM2B2 2
#define PRFM2B3 3
#define PFLTE2B 4
#define PELEV2B 5
#define PISEL2B 6
#define PCAE2B  7

/* Combine PICR0L and PICR0H */
#define PICR0   _SFR_MEM16(0x68)

#define PICR0L  _SFR_MEM8(0x68)
#define PICR0H  _SFR_MEM8(0x69)

#define PSOC0   _SFR_MEM8(0x6A)
#define POEN0A  0
#define POEN0B  2
#define PSYNC00 4
#define PSYNC01 5
#define PISEL0B1 6
#define PISEL0A1 7

/* Reserved [0x6B] */

#define PICR2L  _SFR_MEM8(0x6C)

#define PICR2H  _SFR_MEM8(0x6D)
#define PICR28  0
#define PICR29  1
#define PICR210 2
#define PICR211 3
#define PCST2   7

#define PSOC2   _SFR_MEM8(0x6E)
#define POEN2A  0
#define POEN2C  1
#define POEN2B  2
#define POEN2D  3
#define PSYNC20 4
#define PSYNC21 5
#define POS22   6
#define POS23   7

#define POM2    _SFR_MEM8(0x6F)
#define POMV2A0 0
#define POMV2A1 1
#define POMV2A2 2
#define POMV2A3 3
#define POMV2B0 4
#define POMV2B1 5
#define POMV2B2 6
#define POMV2B3 7

#define PCNFE2  _SFR_MEM8(0x70)
#define PISEL2B1 0
#define PISEL2A1 1
#define PELEV2B1 2
#define PELEV2A1 3
#define PBFM21  4
#define PASDLK20 5
#define PASDLK21 6
#define PASDLK22 7

#define PASDLY2 _SFR_MEM8(0x71)

/* Reserved [0x72..0x75] */

#define DACON   _SFR_MEM8(0x76)
#define DAEN    0
#define DALA    2
#define DATS0   4
#define DATS1   5
#define DATS2   6
#define DAATE   7

#define DIDR0   _SFR_MEM8(0x77)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7

#define DIDR1   _SFR_MEM8(0x78)
#define ADC9D   0
#define ADC10D  1
#define AMP0POSD 2
#define ACMP1MD 3

#define AMP0CSR _SFR_MEM8(0x79)
#define AMP0TS0 0
#define AMP0TS1 1
#define AMP0GS  3
#define AMP0G0  4
#define AMP0G1  5
#define AMP0IS  6
#define AMP0EN  7

#define AC1ECON _SFR_MEM8(0x7A)
#define AC1H0   0
#define AC1H1   1
#define AC1H2   2
#define AC1ICE  3
#define AC1OE   4
#define AC1OI   5

#define AC2ECON _SFR_MEM8(0x7B)
#define AC2H0   0
#define AC2H1   1
#define AC2H2   2
#define AC2OE   4
#define AC2OI   5

#define AC3ECON _SFR_MEM8(0x7C)
#define AC3H0   0
#define AC3H1   1
#define AC3H2   2
#define AC3OE   4
#define AC3OI   5

#define AC1CON  _SFR_MEM8(0x7D)
#define AC1M0   0
#define AC1M1   1
#define AC1M2   2
#define AC1IS0  4
#define AC1IS1  5
#define AC1IE   6
#define AC1EN   7

#define AC2CON  _SFR_MEM8(0x7E)
#define AC2M0   0
#define AC2M1   1
#define AC2M2   2
#define AC2IS0  4
#define AC2IS1  5
#define AC2IE   6
#define AC2EN   7

#define AC3CON  _SFR_MEM8(0x7F)
#define AC3M0   0
#define AC3M1   1
#define AC3M2   2
#define AC3OEA  3
#define AC3IS0  4
#define AC3IS1  5
#define AC3IE   6
#define AC3EN   7

#define BGCRR   _SFR_MEM8(0x80)
#define BGCR0   0
#define BGCR1   1
#define BGCR2   2
#define BGCR3   3

#define BGCCR   _SFR_MEM8(0x81)
#define BGCC0   0
#define BGCC1   1
#define BGCC2   2
#define BGCC3   3

#define WDTCSR  _SFR_MEM8(0x82)
#define WDE     3
#define WDCE    4
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define CLKPR   _SFR_MEM8(0x83)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3
#define CLKPCE  7

#define CLKCSR  _SFR_MEM8(0x84)
#define CLKC0   0
#define CLKC1   1
#define CLKC2   2
#define CLKC3   3
#define CLKRDY  4
#define CLKCCE  7

#define CLKSELR _SFR_MEM8(0x85)
#define CKSEL0  0
#define CKSEL1  1
#define CKSEL2  2
#define CKSEL3  3
#define CSUT0   4
#define CSUT1   5
#define COUT    6

#define PRR     _SFR_MEM8(0x86)
#define PRADC   0
#define PRSPI   2
#define PRTIM1  4
#define PRPSCR  5
#define PRPSC2  7

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRPSCR)|(1<<PRPSC2))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRPSCR
#define __AVR_HAVE_PRR_PRPSC2

#define PLLCSR  _SFR_MEM8(0x87)
#define PLOCK   0
#define PLLE    1
#define PLLF0   2
#define PLLF1   3
#define PLLF2   4
#define PLLF3   5

#define OSCCAL  _SFR_MEM8(0x88)
#define OSCCAL0 0
#define OSCCAL1 1
#define OSCCAL2 2
#define OSCCAL3 3
#define OSCCAL4 4
#define OSCCAL5 5
#define OSCCAL6 6
#define OSCCAL7 7

#define EICRA   _SFR_MEM8(0x89)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC20   4
#define ISC21   5

#define TCCR1B  _SFR_MEM8(0x8A)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM13   4
#define ICES1   6
#define ICNC1   7

/* Reserved [0x8B] */

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_MEM16(0x8C)

#define ICR1L   _SFR_MEM8(0x8C)
#define ICR1H   _SFR_MEM8(0x8D)



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* PSC2 Capture Event */
#define PSC2_CAPT_vect            _VECTOR(1)
#define PSC2_CAPT_vect_num        1

/* PSC2 End Cycle */
#define PSC2_EC_vect            _VECTOR(2)
#define PSC2_EC_vect_num        2

/* PSC2 End Of Enhanced Cycle */
#define PSC2_EEC_vect            _VECTOR(3)
#define PSC2_EEC_vect_num        3

/* PSC0 Capture Event */
#define PSC0_CAPT_vect            _VECTOR(4)
#define PSC0_CAPT_vect_num        4

/* PSC0 End Cycle */
#define PSC0_EC_vect            _VECTOR(5)
#define PSC0_EC_vect_num        5

/* PSC0 End Of Enhanced Cycle */
#define PSC0_EEC_vect            _VECTOR(6)
#define PSC0_EEC_vect_num        6

/* Analog Comparator 1 */
#define ANALOG_COMP_1_vect            _VECTOR(7)
#define ANALOG_COMP_1_vect_num        7

/* Analog Comparator 2 */
#define ANALOG_COMP_2_vect            _VECTOR(8)
#define ANALOG_COMP_2_vect_num        8

/* Analog Comparator 3 */
#define ANALOG_COMP_3_vect            _VECTOR(9)
#define ANALOG_COMP_3_vect_num        9

/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(10)
#define INT0_vect_num        10

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(11)
#define TIMER1_CAPT_vect_num        11

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(12)
#define TIMER1_OVF_vect_num        12

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(13)
#define ADC_vect_num        13

/* External Interrupt Request 1 */
#define INT1_vect            _VECTOR(14)
#define INT1_vect_num        14

/* SPI Serial Transfer Complet */
#define SPI_STC_vect            _VECTOR(15)
#define SPI_STC_vect_num        15

/* External Interrupt Request 2 */
#define INT2_vect            _VECTOR(16)
#define INT2_vect_num        16

/* Watchdog Timeout Interrupt */
#define WDT_vect            _VECTOR(17)
#define WDT_vect_num        17

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(18)
#define EE_READY_vect_num        18

/* Store Program Memory Read */
#define SPM_READY_vect            _VECTOR(19)
#define SPM_READY_vect_num        19

#define _VECTORS_SIZE 80


/* Constants */

#define SPM_PAGESIZE 128
#define FLASHSTART   0x0000
#define FLASHEND     0x3FFF
#define RAMSTART     0x0100
#define RAMSIZE      1024
#define RAMEND       0x04FF
#define E2START     0
#define E2SIZE      512
#define E2PAGESIZE  4
#define E2END       0x01FF
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_SUT_CKSEL0  (unsigned char)~_BV(0)
#define FUSE_SUT_CKSEL1  (unsigned char)~_BV(1)
#define FUSE_SUT_CKSEL2  (unsigned char)~_BV(2)
#define FUSE_SUT_CKSEL3  (unsigned char)~_BV(3)
#define FUSE_SUT_CKSEL4  (unsigned char)~_BV(4)
#define FUSE_SUT_CKSEL5  (unsigned char)~_BV(5)
#define FUSE_CKOUT       (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SUT_CKSEL0 & FUSE_SUT_CKSEL2 & FUSE_SUT_CKSEL3 & FUSE_SUT_CKSEL4 & FUSE_CKDIV8)


/* High Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_DWEN        (unsigned char)~_BV(6)
#define FUSE_RSTDISBL    (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN)


/* Extended Fuse Byte */
#define FUSE_BODLEVEL0   (unsigned char)~_BV(0)
#define FUSE_BODLEVEL1   (unsigned char)~_BV(1)
#define FUSE_BODLEVEL2   (unsigned char)~_BV(2)
#define FUSE_PSCINRB     (unsigned char)~_BV(3)
#define FUSE_PSCRV       (unsigned char)~_BV(4)
#define FUSE_PSC0RB      (unsigned char)~_BV(5)
#define FUSE_PSC2RBA     (unsigned char)~_BV(6)
#define FUSE_PSC2RB      (unsigned char)~_BV(7)
#define EFUSE_DEFAULT    (FUSE_BODLEVEL1)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x8B


#endif /* #ifdef _AVR_AT90PWM161_H_INCLUDED */

