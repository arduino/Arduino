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


#ifndef _AVR_ATMEGA128RFR2_H_INCLUDED
#define _AVR_ATMEGA128RFR2_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom128rfr2.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PINA    _SFR_IO8(0x00)
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

#define DDRA    _SFR_IO8(0x01)
#define DDRA7   7
// Inserted "DDA7" from "DDRA7" due to compatibility
#define DDA7    7
#define DDRA6   6
// Inserted "DDA6" from "DDRA6" due to compatibility
#define DDA6    6
#define DDRA5   5
// Inserted "DDA5" from "DDRA5" due to compatibility
#define DDA5    5
#define DDRA4   4
// Inserted "DDA4" from "DDRA4" due to compatibility
#define DDA4    4
#define DDRA3   3
// Inserted "DDA3" from "DDRA3" due to compatibility
#define DDA3    3
#define DDRA2   2
// Inserted "DDA2" from "DDRA2" due to compatibility
#define DDA2    2
#define DDRA1   1
// Inserted "DDA1" from "DDRA1" due to compatibility
#define DDA1    1
#define DDRA0   0
// Inserted "DDA0" from "DDRA0" due to compatibility
#define DDA0    0

#define PORTA   _SFR_IO8(0x02)
#define PORTA7  7
#define PORTA6  6
#define PORTA5  5
#define PORTA4  4
#define PORTA3  3
#define PORTA2  2
#define PORTA1  1
#define PORTA0  0

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
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x07)
#define DDRC7   7
// Inserted "DDC7" from "DDRC7" due to compatibility
#define DDC7    7
#define DDRC6   6
// Inserted "DDC6" from "DDRC6" due to compatibility
#define DDC6    6
#define DDRC5   5
// Inserted "DDC5" from "DDRC5" due to compatibility
#define DDC5    5
#define DDRC4   4
// Inserted "DDC4" from "DDRC4" due to compatibility
#define DDC4    4
#define DDRC3   3
// Inserted "DDC3" from "DDRC3" due to compatibility
#define DDC3    3
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
#define PORTC7  7
#define PORTC6  6
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
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

#define PINE    _SFR_IO8(0x0C)
#define PINE7   7
#define PINE6   6
#define PINE5   5
#define PINE4   4
#define PINE3   3
#define PINE2   2
#define PINE1   1
#define PINE0   0

#define DDRE    _SFR_IO8(0x0D)
#define DDRE7   7
// Inserted "DDE7" from "DDRE7" due to compatibility
#define DDE7    7
#define DDRE6   6
// Inserted "DDE6" from "DDRE6" due to compatibility
#define DDE6    6
#define DDRE5   5
// Inserted "DDE5" from "DDRE5" due to compatibility
#define DDE5    5
#define DDRE4   4
// Inserted "DDE4" from "DDRE4" due to compatibility
#define DDE4    4
#define DDRE3   3
// Inserted "DDE3" from "DDRE3" due to compatibility
#define DDE3    3
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
#define PORTE7  7
#define PORTE6  6
#define PORTE5  5
#define PORTE4  4
#define PORTE3  3
#define PORTE2  2
#define PORTE1  1
#define PORTE0  0

#define PINF    _SFR_IO8(0x0F)
#define PINF7   7
#define PINF6   6
#define PINF5   5
#define PINF4   4
#define PINF3   3
#define PINF2   2
#define PINF1   1
#define PINF0   0

#define DDRF    _SFR_IO8(0x10)
#define DDRF7   7
// Inserted "DDF7" from "DDRF7" due to compatibility
#define DDF7    7
#define DDRF6   6
// Inserted "DDF6" from "DDRF6" due to compatibility
#define DDF6    6
#define DDRF5   5
// Inserted "DDF5" from "DDRF5" due to compatibility
#define DDF5    5
#define DDRF4   4
// Inserted "DDF4" from "DDRF4" due to compatibility
#define DDF4    4
#define DDRF3   3
// Inserted "DDF3" from "DDRF3" due to compatibility
#define DDF3    3
#define DDRF2   2
// Inserted "DDF2" from "DDRF2" due to compatibility
#define DDF2    2
#define DDRF1   1
// Inserted "DDF1" from "DDRF1" due to compatibility
#define DDF1    1
#define DDRF0   0
// Inserted "DDF0" from "DDRF0" due to compatibility
#define DDF0    0

#define PORTF   _SFR_IO8(0x11)
#define PORTF7  7
#define PORTF6  6
#define PORTF5  5
#define PORTF4  4
#define PORTF3  3
#define PORTF2  2
#define PORTF1  1
#define PORTF0  0

#define PING    _SFR_IO8(0x12)
#define PING7   7
#define PING6   6
#define PING5   5
#define PING4   4
#define PING3   3
#define PING2   2
#define PING1   1
#define PING0   0

#define DDRG    _SFR_IO8(0x13)
#define DDRG7   7
// Inserted "DDG7" from "DDRG7" due to compatibility
#define DDG7    7
#define DDRG6   6
// Inserted "DDG6" from "DDRG6" due to compatibility
#define DDG6    6
#define DDRG5   5
// Inserted "DDG5" from "DDRG5" due to compatibility
#define DDG5    5
#define DDRG4   4
// Inserted "DDG4" from "DDRG4" due to compatibility
#define DDG4    4
#define DDRG3   3
// Inserted "DDG3" from "DDRG3" due to compatibility
#define DDG3    3
#define DDRG2   2
// Inserted "DDG2" from "DDRG2" due to compatibility
#define DDG2    2
#define DDRG1   1
// Inserted "DDG1" from "DDRG1" due to compatibility
#define DDG1    1
#define DDRG0   0
// Inserted "DDG0" from "DDRG0" due to compatibility
#define DDG0    0

#define PORTG   _SFR_IO8(0x14)
#define PORTG7  7
#define PORTG6  6
#define PORTG5  5
#define PORTG4  4
#define PORTG3  3
#define PORTG2  2
#define PORTG1  1
#define PORTG0  0

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2
#define Res0    3
#define Res1    4
#define Res2    5
#define Res3    6
#define Res4    7

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define OCF1C   3
#define ICF1    5

#define TIFR2   _SFR_IO8(0x17)
#define TOV2    0
#define OCF2A   1
#define OCF2B   2

#define TIFR3   _SFR_IO8(0x18)
#define TOV3    0
#define OCF3A   1
#define OCF3B   2
#define OCF3C   3
#define ICF3    5

#define TIFR4   _SFR_IO8(0x19)
#define TOV4    0
#define OCF4A   1
#define OCF4B   2
#define OCF4C   3
#define ICF4    5

#define TIFR5   _SFR_IO8(0x1A)
#define TOV5    0
#define OCF5A   1
#define OCF5B   2
#define OCF5C   3
#define ICF5    5

#define PCIFR   _SFR_IO8(0x1B)
#define PCIF0   0
#define PCIF1   1
#define PCIF2   2

#define EIFR    _SFR_IO8(0x1C)
#define INTF0   0
#define INTF1   1
#define INTF2   2
#define INTF3   3
#define INTF4   4
#define INTF5   5
#define INTF6   6
#define INTF7   7

#define EIMSK   _SFR_IO8(0x1D)
#define INT0    0
#define INT1    1
#define INT2    2
#define INT3    3
#define INT4    4
#define INT5    5
#define INT6    6
#define INT7    7

#define GPIOR0  _SFR_IO8(0x1E)
#define GPIOR00 0
#define GPIOR01 1
#define GPIOR02 2
#define GPIOR03 3
#define GPIOR04 4
#define GPIOR05 5
#define GPIOR06 6
#define GPIOR07 7

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEPE    1
#define EEMPE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

#define EEDR    _SFR_IO8(0x20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0x22)

#define GTCCR   _SFR_IO8(0x23)
#define PSRSYNC 0
#define PSRASY  1
#define TSM     7

#define TCCR0A  _SFR_IO8(0x24)
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

#define TCCR0B  _SFR_IO8(0x25)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

#define TCNT0   _SFR_IO8(0x26)

#define OCR0A   _SFR_IO8(0x27)

#define OCR0B   _SFR_IO8(0x28)

/* Reserved [0x29] */

#define GPIOR1  _SFR_IO8(0x2A)
#define GPIOR10 0
#define GPIOR11 1
#define GPIOR12 2
#define GPIOR13 3
#define GPIOR14 4
#define GPIOR15 5
#define GPIOR16 6
#define GPIOR17 7

#define GPIOR2  _SFR_IO8(0x2B)
#define GPIOR20 0
#define GPIOR21 1
#define GPIOR22 2
#define GPIOR23 3
#define GPIOR24 4
#define GPIOR25 5
#define GPIOR26 6
#define GPIOR27 7

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
#define WCOL    6
#define SPIF    7

#define SPDR    _SFR_IO8(0x2E)

/* Reserved [0x2F] */

#define ACSR    _SFR_IO8(0x30)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

#define OCDR    _SFR_IO8(0x31)
#define OCDR0   0
#define OCDR1   1
#define OCDR2   2
#define OCDR3   3
#define OCDR4   4
#define OCDR5   5
#define OCDR6   6
#define OCDR7   7

/* Reserved [0x32] */

#define SMCR    _SFR_IO8(0x33)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define MCUSR   _SFR_IO8(0x34)
#define JTRF    4
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

#define MCUCR   _SFR_IO8(0x35)
#define JTD     7
#define IVCE    0
#define IVSEL   1
#define PUD     4

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define SIGRD   5
#define RWWSB   6
#define SPMIE   7

/* Reserved [0x38..0x3A] */

#define RAMPZ   _SFR_IO8(0x3B)
#define RAMPZ0  0
#define Res5    6
#define Res6    7

/* Reserved [0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCSR  _SFR_MEM8(0x60)
#define WDE     3
#define WDCE    4
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define CLKPR   _SFR_MEM8(0x61)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3
#define CLKPCE  7

/* Reserved [0x62] */

#define PRR2    _SFR_MEM8(0x63)
#define PRRAM0  0
#define PRRAM1  1
#define PRRAM2  2
#define PRRAM3  3

#define __AVR_HAVE_PRR2	((1<<PRRAM0)|(1<<PRRAM1)|(1<<PRRAM2)|(1<<PRRAM3))
#define __AVR_HAVE_PRR2_PRRAM0
#define __AVR_HAVE_PRR2_PRRAM1
#define __AVR_HAVE_PRR2_PRRAM2
#define __AVR_HAVE_PRR2_PRRAM3

#define PRR0    _SFR_MEM8(0x64)
#define PRADC   0
#define PRUSART0 1
#define PRSPI   2
#define PRTIM1  3
#define PRPGA   4
#define PRTIM0  5
#define PRTIM2  6
#define PRTWI   7

#define __AVR_HAVE_PRR0	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRPGA)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#define __AVR_HAVE_PRR0_PRADC
#define __AVR_HAVE_PRR0_PRUSART0
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRPGA
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM2
#define __AVR_HAVE_PRR0_PRTWI

#define PRR1    _SFR_MEM8(0x65)
#define PRUSART1 0
#define PRTIM3  3
#define PRTIM4  4
#define PRTIM5  5
#define PRTRX24 6
#define Res     7

#define __AVR_HAVE_PRR1	((1<<PRUSART1)|(1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTRX24))
#define __AVR_HAVE_PRR1_PRUSART1
#define __AVR_HAVE_PRR1_PRTIM3
#define __AVR_HAVE_PRR1_PRTIM4
#define __AVR_HAVE_PRR1_PRTIM5
#define __AVR_HAVE_PRR1_PRTRX24

#define OSCCAL  _SFR_MEM8(0x66)
#define CAL0    0
#define CAL1    1
#define CAL2    2
#define CAL3    3
#define CAL4    4
#define CAL5    5
#define CAL6    6
#define CAL7    7
#define OSCCAL0 0
#define OSCCAL1 1
#define OSCCAL2 2
#define OSCCAL3 3
#define OSCCAL4 4
#define OSCCAL5 5
#define OSCCAL6 6
#define OSCCAL7 7

#define BGCR    _SFR_MEM8(0x67)
#define BGCAL0  0
#define BGCAL1  1
#define BGCAL2  2
#define BGCAL_FINE0 3
#define BGCAL_FINE1 4
#define BGCAL_FINE2 5
#define BGCAL_FINE3 6

#define PCICR   _SFR_MEM8(0x68)
#define PCIE0   0
#define PCIE1   1
#define PCIE2   2

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC20   4
#define ISC21   5
#define ISC30   6
#define ISC31   7

#define EICRB   _SFR_MEM8(0x6A)
#define ISC40   0
#define ISC41   1
#define ISC50   2
#define ISC51   3
#define ISC60   4
#define ISC61   5
#define ISC70   6
#define ISC71   7

#define PCMSK0  _SFR_MEM8(0x6B)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  _SFR_MEM8(0x6C)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6
#define PCINT15 7

#define PCMSK2  _SFR_MEM8(0x6D)
#define PCINT16 0
#define PCINT17 1
#define PCINT18 2
#define PCINT19 3
#define PCINT20 4
#define PCINT21 5
#define PCINT22 6
#define PCINT23 7

#define TIMSK0  _SFR_MEM8(0x6E)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2

#define TIMSK1  _SFR_MEM8(0x6F)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define OCIE1C  3
#define ICIE1   5

#define TIMSK2  _SFR_MEM8(0x70)
#define TOIE2   0
#define OCIE2A  1
#define OCIE2B  2

#define TIMSK3  _SFR_MEM8(0x71)
#define TOIE3   0
#define OCIE3A  1
#define OCIE3B  2
#define OCIE3C  3
#define ICIE3   5

#define TIMSK4  _SFR_MEM8(0x72)
#define TOIE4   0
#define OCIE4A  1
#define OCIE4B  2
#define OCIE4C  3
#define ICIE4   5

#define TIMSK5  _SFR_MEM8(0x73)
#define TOIE5   0
#define OCIE5A  1
#define OCIE5B  2
#define OCIE5C  3
#define ICIE5   5

/* Reserved [0x74] */

#define NEMCR   _SFR_MEM8(0x75)
#define AEAM0   4
#define AEAM1   5
#define ENEAM   6

/* Reserved [0x76] */

#define ADCSRC  _SFR_MEM8(0x77)
#define ADSUT0  0
#define ADSUT1  1
#define ADSUT2  2
#define ADSUT3  3
#define ADSUT4  4
#define ADTHT0  6
#define ADTHT1  7

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_MEM16(0x78)
#endif
#define ADCW    _SFR_MEM16(0x78)

#define ADCL    _SFR_MEM8(0x78)
#define ADCH    _SFR_MEM8(0x79)

#define ADCSRA  _SFR_MEM8(0x7A)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADCSRB  _SFR_MEM8(0x7B)
#define ACME    6
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define MUX5    3
#define ACCH    4
#define REFOK   5
#define AVDDOK  7

#define ADMUX   _SFR_MEM8(0x7C)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

#define DIDR2   _SFR_MEM8(0x7D)
#define ADC8D   0
#define ADC9D   1
#define ADC10D  2
#define ADC11D  3
#define ADC12D  4
#define ADC13D  5
#define ADC14D  6
#define ADC15D  7

#define DIDR0   _SFR_MEM8(0x7E)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7

#define DIDR1   _SFR_MEM8(0x7F)
#define AIN0D   0
#define AIN1D   1

#define TCCR1A  _SFR_MEM8(0x80)
#define WGM10   0
#define WGM11   1
#define COM1C0  2
#define COM1C1  3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B  _SFR_MEM8(0x81)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1C  _SFR_MEM8(0x82)
#define FOC1C   5
#define FOC1B   6
#define FOC1A   7

/* Reserved [0x83] */

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_MEM16(0x84)

#define TCNT1L  _SFR_MEM8(0x84)
#define TCNT1H  _SFR_MEM8(0x85)

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_MEM16(0x86)

#define ICR1L   _SFR_MEM8(0x86)
#define ICR1H   _SFR_MEM8(0x87)

/* Combine OCR1AL and OCR1AH */
#define OCR1A   _SFR_MEM16(0x88)

#define OCR1AL  _SFR_MEM8(0x88)
#define OCR1AH  _SFR_MEM8(0x89)

/* Combine OCR1BL and OCR1BH */
#define OCR1B   _SFR_MEM16(0x8A)

#define OCR1BL  _SFR_MEM8(0x8A)
#define OCR1BH  _SFR_MEM8(0x8B)

/* Combine OCR1CL and OCR1CH */
#define OCR1C   _SFR_MEM16(0x8C)

#define OCR1CL  _SFR_MEM8(0x8C)
#define OCR1CH  _SFR_MEM8(0x8D)

/* Reserved [0x8E..0x8F] */

#define TCCR3A  _SFR_MEM8(0x90)
#define WGM30   0
#define WGM31   1
#define COM3C0  2
#define COM3C1  3
#define COM3B0  4
#define COM3B1  5
#define COM3A0  6
#define COM3A1  7

#define TCCR3B  _SFR_MEM8(0x91)
#define CS30    0
#define CS31    1
#define CS32    2
#define WGM32   3
#define WGM33   4
#define ICES3   6
#define ICNC3   7

#define TCCR3C  _SFR_MEM8(0x92)
#define FOC3C   5
#define FOC3B   6
#define FOC3A   7

/* Reserved [0x93] */

/* Combine TCNT3L and TCNT3H */
#define TCNT3   _SFR_MEM16(0x94)

#define TCNT3L  _SFR_MEM8(0x94)
#define TCNT3H  _SFR_MEM8(0x95)

/* Combine ICR3L and ICR3H */
#define ICR3    _SFR_MEM16(0x96)

#define ICR3L   _SFR_MEM8(0x96)
#define ICR3H   _SFR_MEM8(0x97)

/* Combine OCR3AL and OCR3AH */
#define OCR3A   _SFR_MEM16(0x98)

#define OCR3AL  _SFR_MEM8(0x98)
#define OCR3AH  _SFR_MEM8(0x99)

/* Combine OCR3BL and OCR3BH */
#define OCR3B   _SFR_MEM16(0x9A)

#define OCR3BL  _SFR_MEM8(0x9A)
#define OCR3BH  _SFR_MEM8(0x9B)

/* Combine OCR3CL and OCR3CH */
#define OCR3C   _SFR_MEM16(0x9C)

#define OCR3CL  _SFR_MEM8(0x9C)
#define OCR3CH  _SFR_MEM8(0x9D)

/* Reserved [0x9E..0x9F] */

#define TCCR4A  _SFR_MEM8(0xA0)
#define WGM40   0
#define WGM41   1
#define COM4C0  2
#define COM4C1  3
#define COM4B0  4
#define COM4B1  5
#define COM4A0  6
#define COM4A1  7

#define TCCR4B  _SFR_MEM8(0xA1)
#define CS40    0
#define CS41    1
#define CS42    2
#define WGM42   3
#define WGM43   4
#define ICES4   6
#define ICNC4   7

#define TCCR4C  _SFR_MEM8(0xA2)
#define FOC4C   5
#define FOC4B   6
#define FOC4A   7

/* Reserved [0xA3] */

/* Combine TCNT4L and TCNT4H */
#define TCNT4   _SFR_MEM16(0xA4)

#define TCNT4L  _SFR_MEM8(0xA4)
#define TCNT4H  _SFR_MEM8(0xA5)

/* Combine ICR4L and ICR4H */
#define ICR4    _SFR_MEM16(0xA6)

#define ICR4L   _SFR_MEM8(0xA6)
#define ICR4H   _SFR_MEM8(0xA7)

/* Combine OCR4AL and OCR4AH */
#define OCR4A   _SFR_MEM16(0xA8)

#define OCR4AL  _SFR_MEM8(0xA8)
#define OCR4AH  _SFR_MEM8(0xA9)

/* Combine OCR4BL and OCR4BH */
#define OCR4B   _SFR_MEM16(0xAA)

#define OCR4BL  _SFR_MEM8(0xAA)
#define OCR4BH  _SFR_MEM8(0xAB)

/* Combine OCR4CL and OCR4CH */
#define OCR4C   _SFR_MEM16(0xAC)

#define OCR4CL  _SFR_MEM8(0xAC)
#define OCR4CH  _SFR_MEM8(0xAD)

/* Reserved [0xAE..0xAF] */

#define TCCR2A  _SFR_MEM8(0xB0)
#define WGM20   0
#define WGM21   1
#define COM2B0  4
#define COM2B1  5
#define COM2A0  6
#define COM2A1  7

#define TCCR2B  _SFR_MEM8(0xB1)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM22   3
#define FOC2B   6
#define FOC2A   7

#define TCNT2   _SFR_MEM8(0xB2)

#define OCR2A   _SFR_MEM8(0xB3)

#define OCR2B   _SFR_MEM8(0xB4)

/* Reserved [0xB5] */

#define ASSR    _SFR_MEM8(0xB6)
#define TCR2BUB 0
#define TCR2AUB 1
#define OCR2BUB 2
#define OCR2AUB 3
#define TCN2UB  4
#define AS2     5
#define EXCLK   6
#define EXCLKAMR 7

/* Reserved [0xB7] */

#define TWBR    _SFR_MEM8(0xB8)

#define TWSR    _SFR_MEM8(0xB9)
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define TWAR    _SFR_MEM8(0xBA)
#define TWGCE   0
#define TWA0    1
#define TWA1    2
#define TWA2    3
#define TWA3    4
#define TWA4    5
#define TWA5    6
#define TWA6    7

#define TWDR    _SFR_MEM8(0xBB)

#define TWCR    _SFR_MEM8(0xBC)
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

#define TWAMR   _SFR_MEM8(0xBD)
#define TWAM0   1
#define TWAM1   2
#define TWAM2   3
#define TWAM3   4
#define TWAM4   5
#define TWAM5   6
#define TWAM6   7

#define IRQ_MASK1 _SFR_MEM8(0xBE)
#define TX_START_EN 0
#define MAF_0_AMI_EN 1
#define MAF_1_AMI_EN 2
#define MAF_2_AMI_EN 3
#define MAF_3_AMI_EN 4

#define IRQ_STATUS1 _SFR_MEM8(0xBF)
#define TX_START 0
#define MAF_0_AMI 1
#define MAF_1_AMI 2
#define MAF_2_AMI 3
#define MAF_3_AMI 4

#define UCSR0A  _SFR_MEM8(0xC0)
#define MPCM0   0
#define U2X0    1
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRE0   5
#define TXC0    6
#define RXC0    7

#define UCSR0B  _SFR_MEM8(0xC1)
#define TXB80   0
#define RXB80   1
#define UCSZ02  2
#define TXEN0   3
#define RXEN0   4
#define UDRIE0  5
#define TXCIE0  6
#define RXCIE0  7

#define UCSR0C  _SFR_MEM8(0xC2)
#define UCPOL0  0
#define UCSZ00  1
#define UCSZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL00 6
#define UMSEL01 7
#define UCPHA0  1
#define UDORD0  2

/* Reserved [0xC3] */

/* Combine UBRR0L and UBRR0H */
#define UBRR0   _SFR_MEM16(0xC4)

#define UBRR0L  _SFR_MEM8(0xC4)
#define UBRR0H  _SFR_MEM8(0xC5)

#define UDR0    _SFR_MEM8(0xC6)

/* Reserved [0xC7] */

#define UCSR1A  _SFR_MEM8(0xC8)
#define MPCM1   0
#define U2X1    1
#define UPE1    2
#define DOR1    3
#define FE1     4
#define UDRE1   5
#define TXC1    6
#define RXC1    7

#define UCSR1B  _SFR_MEM8(0xC9)
#define TXB81   0
#define RXB81   1
#define UCSZ12  2
#define TXEN1   3
#define RXEN1   4
#define UDRIE1  5
#define TXCIE1  6
#define RXCIE1  7

#define UCSR1C  _SFR_MEM8(0xCA)
#define UCPOL1  0
#define UCSZ10  1
#define UCSZ11  2
#define USBS1   3
#define UPM10   4
#define UPM11   5
#define UMSEL10 6
#define UMSEL11 7
#define UCPHA1  1
#define UDORD1  2

/* Reserved [0xCB] */

/* Combine UBRR1L and UBRR1H */
#define UBRR1   _SFR_MEM16(0xCC)

#define UBRR1L  _SFR_MEM8(0xCC)
#define UBRR1H  _SFR_MEM8(0xCD)

#define UDR1    _SFR_MEM8(0xCE)

/* Reserved [0xCF..0xD6] */

#define SCRSTRLL _SFR_MEM8(0xD7)
#define SCRSTRLL0 0
#define SCRSTRLL1 1
#define SCRSTRLL2 2
#define SCRSTRLL3 3
#define SCRSTRLL4 4
#define SCRSTRLL5 5
#define SCRSTRLL6 6
#define SCRSTRLL7 7

#define SCRSTRLH _SFR_MEM8(0xD8)
#define SCRSTRLH0 0
#define SCRSTRLH1 1
#define SCRSTRLH2 2
#define SCRSTRLH3 3
#define SCRSTRLH4 4
#define SCRSTRLH5 5
#define SCRSTRLH6 6
#define SCRSTRLH7 7

#define SCRSTRHL _SFR_MEM8(0xD9)
#define SCRSTRHL0 0
#define SCRSTRHL1 1
#define SCRSTRHL2 2
#define SCRSTRHL3 3
#define SCRSTRHL4 4
#define SCRSTRHL5 5
#define SCRSTRHL6 6
#define SCRSTRHL7 7

#define SCRSTRHH _SFR_MEM8(0xDA)
#define SCRSTRHH0 0
#define SCRSTRHH1 1
#define SCRSTRHH2 2
#define SCRSTRHH3 3
#define SCRSTRHH4 4
#define SCRSTRHH5 5
#define SCRSTRHH6 6
#define SCRSTRHH7 7

#define SCCSR   _SFR_MEM8(0xDB)
#define SCCS10  0
#define SCCS11  1
#define SCCS20  2
#define SCCS21  3
#define SCCS30  4
#define SCCS31  5

#define SCCR0   _SFR_MEM8(0xDC)
#define SCCMP1  0
#define SCCMP2  1
#define SCCMP3  2
#define SCTSE   3
#define SCCKSEL 4
#define SCEN    5
#define SCMBTS  6
#define SCRES   7

#define SCCR1   _SFR_MEM8(0xDD)
#define SCENBO  0
#define SCEECLK 1
#define SCCKDIV0 2
#define SCCKDIV1 3
#define SCCKDIV2 4
#define SCBTSM  5

#define SCSR    _SFR_MEM8(0xDE)
#define SCBSY   0

#define SCIRQM  _SFR_MEM8(0xDF)
#define IRQMCP1 0
#define IRQMCP2 1
#define IRQMCP3 2
#define IRQMOF  3
#define IRQMBO  4

#define SCIRQS  _SFR_MEM8(0xE0)
#define IRQSCP1 0
#define IRQSCP2 1
#define IRQSCP3 2
#define IRQSOF  3
#define IRQSBO  4

#define SCCNTLL _SFR_MEM8(0xE1)
#define SCCNTLL0 0
#define SCCNTLL1 1
#define SCCNTLL2 2
#define SCCNTLL3 3
#define SCCNTLL4 4
#define SCCNTLL5 5
#define SCCNTLL6 6
#define SCCNTLL7 7

#define SCCNTLH _SFR_MEM8(0xE2)
#define SCCNTLH0 0
#define SCCNTLH1 1
#define SCCNTLH2 2
#define SCCNTLH3 3
#define SCCNTLH4 4
#define SCCNTLH5 5
#define SCCNTLH6 6
#define SCCNTLH7 7

#define SCCNTHL _SFR_MEM8(0xE3)
#define SCCNTHL0 0
#define SCCNTHL1 1
#define SCCNTHL2 2
#define SCCNTHL3 3
#define SCCNTHL4 4
#define SCCNTHL5 5
#define SCCNTHL6 6
#define SCCNTHL7 7

#define SCCNTHH _SFR_MEM8(0xE4)
#define SCCNTHH0 0
#define SCCNTHH1 1
#define SCCNTHH2 2
#define SCCNTHH3 3
#define SCCNTHH4 4
#define SCCNTHH5 5
#define SCCNTHH6 6
#define SCCNTHH7 7

#define SCBTSRLL _SFR_MEM8(0xE5)
#define SCBTSRLL0 0
#define SCBTSRLL1 1
#define SCBTSRLL2 2
#define SCBTSRLL3 3
#define SCBTSRLL4 4
#define SCBTSRLL5 5
#define SCBTSRLL6 6
#define SCBTSRLL7 7

#define SCBTSRLH _SFR_MEM8(0xE6)
#define SCBTSRLH0 0
#define SCBTSRLH1 1
#define SCBTSRLH2 2
#define SCBTSRLH3 3
#define SCBTSRLH4 4
#define SCBTSRLH5 5
#define SCBTSRLH6 6
#define SCBTSRLH7 7

#define SCBTSRHL _SFR_MEM8(0xE7)
#define SCBTSRHL0 0
#define SCBTSRHL1 1
#define SCBTSRHL2 2
#define SCBTSRHL3 3
#define SCBTSRHL4 4
#define SCBTSRHL5 5
#define SCBTSRHL6 6
#define SCBTSRHL7 7

#define SCBTSRHH _SFR_MEM8(0xE8)
#define SCBTSRHH0 0
#define SCBTSRHH1 1
#define SCBTSRHH2 2
#define SCBTSRHH3 3
#define SCBTSRHH4 4
#define SCBTSRHH5 5
#define SCBTSRHH6 6
#define SCBTSRHH7 7

#define SCTSRLL _SFR_MEM8(0xE9)
#define SCTSRLL0 0
#define SCTSRLL1 1
#define SCTSRLL2 2
#define SCTSRLL3 3
#define SCTSRLL4 4
#define SCTSRLL5 5
#define SCTSRLL6 6
#define SCTSRLL7 7

#define SCTSRLH _SFR_MEM8(0xEA)
#define SCTSRLH0 0
#define SCTSRLH1 1
#define SCTSRLH2 2
#define SCTSRLH3 3
#define SCTSRLH4 4
#define SCTSRLH5 5
#define SCTSRLH6 6
#define SCTSRLH7 7

#define SCTSRHL _SFR_MEM8(0xEB)
#define SCTSRHL0 0
#define SCTSRHL1 1
#define SCTSRHL2 2
#define SCTSRHL3 3
#define SCTSRHL4 4
#define SCTSRHL5 5
#define SCTSRHL6 6
#define SCTSRHL7 7

#define SCTSRHH _SFR_MEM8(0xEC)
#define SCTSRHH0 0
#define SCTSRHH1 1
#define SCTSRHH2 2
#define SCTSRHH3 3
#define SCTSRHH4 4
#define SCTSRHH5 5
#define SCTSRHH6 6
#define SCTSRHH7 7

#define SCOCR3LL _SFR_MEM8(0xED)
#define SCOCR3LL0 0
#define SCOCR3LL1 1
#define SCOCR3LL2 2
#define SCOCR3LL3 3
#define SCOCR3LL4 4
#define SCOCR3LL5 5
#define SCOCR3LL6 6
#define SCOCR3LL7 7

#define SCOCR3LH _SFR_MEM8(0xEE)
#define SCOCR3LH0 0
#define SCOCR3LH1 1
#define SCOCR3LH2 2
#define SCOCR3LH3 3
#define SCOCR3LH4 4
#define SCOCR3LH5 5
#define SCOCR3LH6 6
#define SCOCR3LH7 7

#define SCOCR3HL _SFR_MEM8(0xEF)
#define SCOCR3HL0 0
#define SCOCR3HL1 1
#define SCOCR3HL2 2
#define SCOCR3HL3 3
#define SCOCR3HL4 4
#define SCOCR3HL5 5
#define SCOCR3HL6 6
#define SCOCR3HL7 7

#define SCOCR3HH _SFR_MEM8(0xF0)
#define SCOCR3HH0 0
#define SCOCR3HH1 1
#define SCOCR3HH2 2
#define SCOCR3HH3 3
#define SCOCR3HH4 4
#define SCOCR3HH5 5
#define SCOCR3HH6 6
#define SCOCR3HH7 7

#define SCOCR2LL _SFR_MEM8(0xF1)
#define SCOCR2LL0 0
#define SCOCR2LL1 1
#define SCOCR2LL2 2
#define SCOCR2LL3 3
#define SCOCR2LL4 4
#define SCOCR2LL5 5
#define SCOCR2LL6 6
#define SCOCR2LL7 7

#define SCOCR2LH _SFR_MEM8(0xF2)
#define SCOCR2LH0 0
#define SCOCR2LH1 1
#define SCOCR2LH2 2
#define SCOCR2LH3 3
#define SCOCR2LH4 4
#define SCOCR2LH5 5
#define SCOCR2LH6 6
#define SCOCR2LH7 7

#define SCOCR2HL _SFR_MEM8(0xF3)
#define SCOCR2HL0 0
#define SCOCR2HL1 1
#define SCOCR2HL2 2
#define SCOCR2HL3 3
#define SCOCR2HL4 4
#define SCOCR2HL5 5
#define SCOCR2HL6 6
#define SCOCR2HL7 7

#define SCOCR2HH _SFR_MEM8(0xF4)
#define SCOCR2HH0 0
#define SCOCR2HH1 1
#define SCOCR2HH2 2
#define SCOCR2HH3 3
#define SCOCR2HH4 4
#define SCOCR2HH5 5
#define SCOCR2HH6 6
#define SCOCR2HH7 7

#define SCOCR1LL _SFR_MEM8(0xF5)
#define SCOCR1LL0 0
#define SCOCR1LL1 1
#define SCOCR1LL2 2
#define SCOCR1LL3 3
#define SCOCR1LL4 4
#define SCOCR1LL5 5
#define SCOCR1LL6 6
#define SCOCR1LL7 7

#define SCOCR1LH _SFR_MEM8(0xF6)
#define SCOCR1LH0 0
#define SCOCR1LH1 1
#define SCOCR1LH2 2
#define SCOCR1LH3 3
#define SCOCR1LH4 4
#define SCOCR1LH5 5
#define SCOCR1LH6 6
#define SCOCR1LH7 7

#define SCOCR1HL _SFR_MEM8(0xF7)
#define SCOCR1HL0 0
#define SCOCR1HL1 1
#define SCOCR1HL2 2
#define SCOCR1HL3 3
#define SCOCR1HL4 4
#define SCOCR1HL5 5
#define SCOCR1HL6 6
#define SCOCR1HL7 7

#define SCOCR1HH _SFR_MEM8(0xF8)
#define SCOCR1HH0 0
#define SCOCR1HH1 1
#define SCOCR1HH2 2
#define SCOCR1HH3 3
#define SCOCR1HH4 4
#define SCOCR1HH5 5
#define SCOCR1HH6 6
#define SCOCR1HH7 7

#define SCTSTRLL _SFR_MEM8(0xF9)
#define SCTSTRLL0 0
#define SCTSTRLL1 1
#define SCTSTRLL2 2
#define SCTSTRLL3 3
#define SCTSTRLL4 4
#define SCTSTRLL5 5
#define SCTSTRLL6 6
#define SCTSTRLL7 7

#define SCTSTRLH _SFR_MEM8(0xFA)
#define SCTSTRLH0 0
#define SCTSTRLH1 1
#define SCTSTRLH2 2
#define SCTSTRLH3 3
#define SCTSTRLH4 4
#define SCTSTRLH5 5
#define SCTSTRLH6 6
#define SCTSTRLH7 7

#define SCTSTRHL _SFR_MEM8(0xFB)
#define SCTSTRHL0 0
#define SCTSTRHL1 1
#define SCTSTRHL2 2
#define SCTSTRHL3 3
#define SCTSTRHL4 4
#define SCTSTRHL5 5
#define SCTSTRHL6 6
#define SCTSTRHL7 7

#define SCTSTRHH _SFR_MEM8(0xFC)
#define SCTSTRHH0 0
#define SCTSTRHH1 1
#define SCTSTRHH2 2
#define SCTSTRHH3 3
#define SCTSTRHH4 4
#define SCTSTRHH5 5
#define SCTSTRHH6 6
#define SCTSTRHH7 7

/* Reserved [0xFD..0x10B] */

#define MAFCR0  _SFR_MEM8(0x10C)
#define MAF0EN  0
#define MAF1EN  1
#define MAF2EN  2
#define MAF3EN  3

#define MAFCR1  _SFR_MEM8(0x10D)
#define AACK_0_I_AM_COORD 0
#define AACK_0_SET_PD 1
#define AACK_1_I_AM_COORD 2
#define AACK_1_SET_PD 3
#define AACK_2_I_AM_COORD 4
#define AACK_2_SET_PD 5
#define AACK_3_I_AM_COORD 6
#define AACK_3_SET_PD 7

#define MAFSA0L _SFR_MEM8(0x10E)
#define MAFSA0L0 0
#define MAFSA0L1 1
#define MAFSA0L2 2
#define MAFSA0L3 3
#define MAFSA0L4 4
#define MAFSA0L5 5
#define MAFSA0L6 6
#define MAFSA0L7 7

#define MAFSA0H _SFR_MEM8(0x10F)
#define MAFSA0H0 0
#define MAFSA0H1 1
#define MAFSA0H2 2
#define MAFSA0H3 3
#define MAFSA0H4 4
#define MAFSA0H5 5
#define MAFSA0H6 6
#define MAFSA0H7 7

#define MAFPA0L _SFR_MEM8(0x110)
#define MAFPA0L0 0
#define MAFPA0L1 1
#define MAFPA0L2 2
#define MAFPA0L3 3
#define MAFPA0L4 4
#define MAFPA0L5 5
#define MAFPA0L6 6
#define MAFPA0L7 7

#define MAFPA0H _SFR_MEM8(0x111)
#define MAFPA0H0 0
#define MAFPA0H1 1
#define MAFPA0H2 2
#define MAFPA0H3 3
#define MAFPA0H4 4
#define MAFPA0H5 5
#define MAFPA0H6 6
#define MAFPA0H7 7

#define MAFSA1L _SFR_MEM8(0x112)
#define MAFSA1L0 0
#define MAFSA1L1 1
#define MAFSA1L2 2
#define MAFSA1L3 3
#define MAFSA1L4 4
#define MAFSA1L5 5
#define MAFSA1L6 6
#define MAFSA1L7 7

#define MAFSA1H _SFR_MEM8(0x113)
#define MAFSA1H0 0
#define MAFSA1H1 1
#define MAFSA1H2 2
#define MAFSA1H3 3
#define MAFSA1H4 4
#define MAFSA1H5 5
#define MAFSA1H6 6
#define MAFSA1H7 7

#define MAFPA1L _SFR_MEM8(0x114)
#define MAFPA1L0 0
#define MAFPA1L1 1
#define MAFPA1L2 2
#define MAFPA1L3 3
#define MAFPA1L4 4
#define MAFPA1L5 5
#define MAFPA1L6 6
#define MAFPA1L7 7

#define MAFPA1H _SFR_MEM8(0x115)
#define MAFPA1H0 0
#define MAFPA1H1 1
#define MAFPA1H2 2
#define MAFPA1H3 3
#define MAFPA1H4 4
#define MAFPA1H5 5
#define MAFPA1H6 6
#define MAFPA1H7 7

#define MAFSA2L _SFR_MEM8(0x116)
#define MAFSA2L0 0
#define MAFSA2L1 1
#define MAFSA2L2 2
#define MAFSA2L3 3
#define MAFSA2L4 4
#define MAFSA2L5 5
#define MAFSA2L6 6
#define MAFSA2L7 7

#define MAFSA2H _SFR_MEM8(0x117)
#define MAFSA2H0 0
#define MAFSA2H1 1
#define MAFSA2H2 2
#define MAFSA2H3 3
#define MAFSA2H4 4
#define MAFSA2H5 5
#define MAFSA2H6 6
#define MAFSA2H7 7

#define MAFPA2L _SFR_MEM8(0x118)
#define MAFPA2L0 0
#define MAFPA2L1 1
#define MAFPA2L2 2
#define MAFPA2L3 3
#define MAFPA2L4 4
#define MAFPA2L5 5
#define MAFPA2L6 6
#define MAFPA2L7 7

#define MAFPA2H _SFR_MEM8(0x119)
#define MAFPA2H0 0
#define MAFPA2H1 1
#define MAFPA2H2 2
#define MAFPA2H3 3
#define MAFPA2H4 4
#define MAFPA2H5 5
#define MAFPA2H6 6
#define MAFPA2H7 7

#define MAFSA3L _SFR_MEM8(0x11A)
#define MAFSA3L0 0
#define MAFSA3L1 1
#define MAFSA3L2 2
#define MAFSA3L3 3
#define MAFSA3L4 4
#define MAFSA3L5 5
#define MAFSA3L6 6
#define MAFSA3L7 7

#define MAFSA3H _SFR_MEM8(0x11B)
#define MAFSA3H0 0
#define MAFSA3H1 1
#define MAFSA3H2 2
#define MAFSA3H3 3
#define MAFSA3H4 4
#define MAFSA3H5 5
#define MAFSA3H6 6
#define MAFSA3H7 7

#define MAFPA3L _SFR_MEM8(0x11C)
#define MAFPA3L0 0
#define MAFPA3L1 1
#define MAFPA3L2 2
#define MAFPA3L3 3
#define MAFPA3L4 4
#define MAFPA3L5 5
#define MAFPA3L6 6
#define MAFPA3L7 7

#define MAFPA3H _SFR_MEM8(0x11D)
#define MAFPA3H0 0
#define MAFPA3H1 1
#define MAFPA3H2 2
#define MAFPA3H3 3
#define MAFPA3H4 4
#define MAFPA3H5 5
#define MAFPA3H6 6
#define MAFPA3H7 7

/* Reserved [0x11E..0x11F] */

#define TCCR5A  _SFR_MEM8(0x120)
#define WGM50   0
#define WGM51   1
#define COM5C0  2
#define COM5C1  3
#define COM5B0  4
#define COM5B1  5
#define COM5A0  6
#define COM5A1  7

#define TCCR5B  _SFR_MEM8(0x121)
#define CS50    0
#define CS51    1
#define CS52    2
#define WGM52   3
#define WGM53   4
#define ICES5   6
#define ICNC5   7

#define TCCR5C  _SFR_MEM8(0x122)
#define FOC5C   5
#define FOC5B   6
#define FOC5A   7

/* Reserved [0x123] */

/* Combine TCNT5L and TCNT5H */
#define TCNT5   _SFR_MEM16(0x124)

#define TCNT5L  _SFR_MEM8(0x124)
#define TCNT5H  _SFR_MEM8(0x125)

/* Combine ICR5L and ICR5H */
#define ICR5    _SFR_MEM16(0x126)

#define ICR5L   _SFR_MEM8(0x126)
#define ICR5H   _SFR_MEM8(0x127)

/* Combine OCR5AL and OCR5AH */
#define OCR5A   _SFR_MEM16(0x128)

#define OCR5AL  _SFR_MEM8(0x128)
#define OCR5AH  _SFR_MEM8(0x129)

/* Combine OCR5BL and OCR5BH */
#define OCR5B   _SFR_MEM16(0x12A)

#define OCR5BL  _SFR_MEM8(0x12A)
#define OCR5BH  _SFR_MEM8(0x12B)

/* Combine OCR5CL and OCR5CH */
#define OCR5C   _SFR_MEM16(0x12C)

#define OCR5CL  _SFR_MEM8(0x12C)
#define OCR5CH  _SFR_MEM8(0x12D)

/* Reserved [0x12E] */

#define LLCR    _SFR_MEM8(0x12F)
#define LLENCAL 0
#define LLSHORT 1
#define LLTCO   2
#define LLCAL   3
#define LLCOMP  4
#define LLDONE  5

#define LLDRL   _SFR_MEM8(0x130)
#define LLDRL0  0
#define LLDRL1  1
#define LLDRL2  2
#define LLDRL3  3

#define LLDRH   _SFR_MEM8(0x131)
#define LLDRH0  0
#define LLDRH1  1
#define LLDRH2  2
#define LLDRH3  3
#define LLDRH4  4

#define DRTRAM3 _SFR_MEM8(0x132)
#define ENDRT   4
#define DRTSWOK 5

#define DRTRAM2 _SFR_MEM8(0x133)

#define DRTRAM1 _SFR_MEM8(0x134)

#define DRTRAM0 _SFR_MEM8(0x135)

#define DPDS0   _SFR_MEM8(0x136)
#define PBDRV0  0
#define PBDRV1  1
#define PDDRV0  2
#define PDDRV1  3
#define PEDRV0  4
#define PEDRV1  5
#define PFDRV0  6
#define PFDRV1  7

#define DPDS1   _SFR_MEM8(0x137)
#define PGDRV0  0
#define PGDRV1  1

#define PARCR   _SFR_MEM8(0x138)
#define PARUFI  0
#define PARDFI  1
#define PALTU0  2
#define PALTU1  3
#define PALTU2  4
#define PALTD0  5
#define PALTD1  6
#define PALTD2  7

#define TRXPR   _SFR_MEM8(0x139)
#define TRXRST  0
#define SLPTR   1

/* Reserved [0x13A..0x13B] */

#define AES_CTRL _SFR_MEM8(0x13C)
#define AES_IM  2
#define AES_DIR 3
#define AES_MODE 5
#define AES_REQUEST 7

#define AES_STATUS _SFR_MEM8(0x13D)
#define AES_DONE 0
#define AES_ER  7

#define AES_STATE _SFR_MEM8(0x13E)
#define AES_STATE0 0
#define AES_STATE1 1
#define AES_STATE2 2
#define AES_STATE3 3
#define AES_STATE4 4
#define AES_STATE5 5
#define AES_STATE6 6
#define AES_STATE7 7

#define AES_KEY _SFR_MEM8(0x13F)
#define AES_KEY0 0
#define AES_KEY1 1
#define AES_KEY2 2
#define AES_KEY3 3
#define AES_KEY4 4
#define AES_KEY5 5
#define AES_KEY6 6
#define AES_KEY7 7

/* Reserved [0x140] */

#define TRX_STATUS _SFR_MEM8(0x141)
#define TRX_STATUS0 0
#define TRX_STATUS1 1
#define TRX_STATUS2 2
#define TRX_STATUS3 3
#define TRX_STATUS4 4
#define TST_STATUS 5
#define CCA_STATUS 6
#define CCA_DONE 7

#define TRX_STATE _SFR_MEM8(0x142)
#define TRX_CMD0 0
#define TRX_CMD1 1
#define TRX_CMD2 2
#define TRX_CMD3 3
#define TRX_CMD4 4
#define TRAC_STATUS0 5
#define TRAC_STATUS1 6
#define TRAC_STATUS2 7

#define TRX_CTRL_0 _SFR_MEM8(0x143)
#define PMU_IF_INV 4
#define PMU_START 5
#define PMU_EN  6
#define Res7    7

#define TRX_CTRL_1 _SFR_MEM8(0x144)
#define PLL_TX_FLT 4
#define TX_AUTO_CRC_ON 5
#define IRQ_2_EXT_EN 6
#define PA_EXT_EN 7

#define PHY_TX_PWR _SFR_MEM8(0x145)
#define TX_PWR0 0
#define TX_PWR1 1
#define TX_PWR2 2
#define TX_PWR3 3

#define PHY_RSSI _SFR_MEM8(0x146)
#define RSSI0   0
#define RSSI1   1
#define RSSI2   2
#define RSSI3   3
#define RSSI4   4
#define RND_VALUE0 5
#define RND_VALUE1 6
#define RX_CRC_VALID 7

#define PHY_ED_LEVEL _SFR_MEM8(0x147)
#define ED_LEVEL0 0
#define ED_LEVEL1 1
#define ED_LEVEL2 2
#define ED_LEVEL3 3
#define ED_LEVEL4 4
#define ED_LEVEL5 5
#define ED_LEVEL6 6
#define ED_LEVEL7 7

#define PHY_CC_CCA _SFR_MEM8(0x148)
#define CHANNEL0 0
#define CHANNEL1 1
#define CHANNEL2 2
#define CHANNEL3 3
#define CHANNEL4 4
#define CCA_MODE0 5
#define CCA_MODE1 6
#define CCA_REQUEST 7

#define CCA_THRES _SFR_MEM8(0x149)
#define CCA_ED_THRES0 0
#define CCA_ED_THRES1 1
#define CCA_ED_THRES2 2
#define CCA_ED_THRES3 3
#define CCA_CS_THRES0 4
#define CCA_CS_THRES1 5
#define CCA_CS_THRES2 6
#define CCA_CS_THRES3 7

#define RX_CTRL _SFR_MEM8(0x14A)
#define PDT_THRES0 0
#define PDT_THRES1 1
#define PDT_THRES2 2
#define PDT_THRES3 3

#define SFD_VALUE _SFR_MEM8(0x14B)
#define SFD_VALUE0 0
#define SFD_VALUE1 1
#define SFD_VALUE2 2
#define SFD_VALUE3 3
#define SFD_VALUE4 4
#define SFD_VALUE5 5
#define SFD_VALUE6 6
#define SFD_VALUE7 7

#define TRX_CTRL_2 _SFR_MEM8(0x14C)
#define OQPSK_DATA_RATE0 0
#define OQPSK_DATA_RATE1 1
#define RX_SAFE_MODE 7

#define ANT_DIV _SFR_MEM8(0x14D)
#define ANT_CTRL0 0
#define ANT_CTRL1 1
#define ANT_EXT_SW_EN 2
#define ANT_DIV_EN 3
#define ANT_SEL 7

#define IRQ_MASK _SFR_MEM8(0x14E)
#define PLL_LOCK_EN 0
#define PLL_UNLOCK_EN 1
#define RX_START_EN 2
#define RX_END_EN 3
#define CCA_ED_DONE_EN 4
#define AMI_EN  5
#define TX_END_EN 6
#define AWAKE_EN 7

#define IRQ_STATUS _SFR_MEM8(0x14F)
#define PLL_LOCK 0
#define PLL_UNLOCK 1
#define RX_START 2
#define RX_END  3
#define CCA_ED_DONE 4
#define AMI     5
#define TX_END  6
#define AWAKE   7

#define VREG_CTRL _SFR_MEM8(0x150)
#define DVDD_OK 2
#define DVREG_EXT 3
#define AVDD_OK 6
#define AVREG_EXT 7

#define BATMON  _SFR_MEM8(0x151)
#define BATMON_VTH0 0
#define BATMON_VTH1 1
#define BATMON_VTH2 2
#define BATMON_VTH3 3
#define BATMON_HR 4
#define BATMON_OK 5
#define BAT_LOW_EN 6
#define BAT_LOW 7

#define XOSC_CTRL _SFR_MEM8(0x152)
#define XTAL_TRIM0 0
#define XTAL_TRIM1 1
#define XTAL_TRIM2 2
#define XTAL_TRIM3 3
#define XTAL_MODE0 4
#define XTAL_MODE1 5
#define XTAL_MODE2 6
#define XTAL_MODE3 7

#define CC_CTRL_0 _SFR_MEM8(0x153)
#define CC_NUMBER0 0
#define CC_NUMBER1 1
#define CC_NUMBER2 2
#define CC_NUMBER3 3
#define CC_NUMBER4 4
#define CC_NUMBER5 5
#define CC_NUMBER6 6
#define CC_NUMBER7 7

#define CC_CTRL_1 _SFR_MEM8(0x154)
#define CC_BAND0 0
#define CC_BAND1 1
#define CC_BAND2 2
#define CC_BAND3 3

#define RX_SYN  _SFR_MEM8(0x155)
#define RX_PDT_LEVEL0 0
#define RX_PDT_LEVEL1 1
#define RX_PDT_LEVEL2 2
#define RX_PDT_LEVEL3 3
#define RX_OVERRIDE 6
#define RX_PDT_DIS 7

#define TRX_RPC _SFR_MEM8(0x156)
#define XAH_RPC_EN 0
#define IPAN_RPC_EN 1
#define PLL_RPC_EN 3
#define PDT_RPC_EN 4
#define RX_RPC_EN 5
#define RX_RPC_CTRL0 6
#define RX_RPC_CTRL1 7

#define XAH_CTRL_1 _SFR_MEM8(0x157)
#define AACK_PROM_MODE 1
#define AACK_ACK_TIME 2
#define AACK_UPLD_RES_FT 4
#define AACK_FLTR_RES_FT 5

#define FTN_CTRL _SFR_MEM8(0x158)
#define FTN_START 7

/* Reserved [0x159] */

#define PLL_CF  _SFR_MEM8(0x15A)
#define PLL_CF_START 7

#define PLL_DCU _SFR_MEM8(0x15B)
#define PLL_DCU_START 7

#define PART_NUM _SFR_MEM8(0x15C)
#define PART_NUM0 0
#define PART_NUM1 1
#define PART_NUM2 2
#define PART_NUM3 3
#define PART_NUM4 4
#define PART_NUM5 5
#define PART_NUM6 6
#define PART_NUM7 7

#define VERSION_NUM _SFR_MEM8(0x15D)
#define VERSION_NUM0 0
#define VERSION_NUM1 1
#define VERSION_NUM2 2
#define VERSION_NUM3 3
#define VERSION_NUM4 4
#define VERSION_NUM5 5
#define VERSION_NUM6 6
#define VERSION_NUM7 7

#define MAN_ID_0 _SFR_MEM8(0x15E)
#define MAN_ID_00 0
#define MAN_ID_01 1
#define MAN_ID_02 2
#define MAN_ID_03 3
#define MAN_ID_04 4
#define MAN_ID_05 5
#define MAN_ID_06 6
#define MAN_ID_07 7

#define MAN_ID_1 _SFR_MEM8(0x15F)
#define MAN_ID_10 0
#define MAN_ID_11 1
#define MAN_ID_12 2
#define MAN_ID_13 3
#define MAN_ID_14 4
#define MAN_ID_15 5
#define MAN_ID_16 6
#define MAN_ID_17 7

#define SHORT_ADDR_0 _SFR_MEM8(0x160)
#define SHORT_ADDR_00 0
#define SHORT_ADDR_01 1
#define SHORT_ADDR_02 2
#define SHORT_ADDR_03 3
#define SHORT_ADDR_04 4
#define SHORT_ADDR_05 5
#define SHORT_ADDR_06 6
#define SHORT_ADDR_07 7

#define SHORT_ADDR_1 _SFR_MEM8(0x161)
#define SHORT_ADDR_10 0
#define SHORT_ADDR_11 1
#define SHORT_ADDR_12 2
#define SHORT_ADDR_13 3
#define SHORT_ADDR_14 4
#define SHORT_ADDR_15 5
#define SHORT_ADDR_16 6
#define SHORT_ADDR_17 7

#define PAN_ID_0 _SFR_MEM8(0x162)
#define PAN_ID_00 0
#define PAN_ID_01 1
#define PAN_ID_02 2
#define PAN_ID_03 3
#define PAN_ID_04 4
#define PAN_ID_05 5
#define PAN_ID_06 6
#define PAN_ID_07 7

#define PAN_ID_1 _SFR_MEM8(0x163)
#define PAN_ID_10 0
#define PAN_ID_11 1
#define PAN_ID_12 2
#define PAN_ID_13 3
#define PAN_ID_14 4
#define PAN_ID_15 5
#define PAN_ID_16 6
#define PAN_ID_17 7

#define IEEE_ADDR_0 _SFR_MEM8(0x164)
#define IEEE_ADDR_00 0
#define IEEE_ADDR_01 1
#define IEEE_ADDR_02 2
#define IEEE_ADDR_03 3
#define IEEE_ADDR_04 4
#define IEEE_ADDR_05 5
#define IEEE_ADDR_06 6
#define IEEE_ADDR_07 7

#define IEEE_ADDR_1 _SFR_MEM8(0x165)
#define IEEE_ADDR_10 0
#define IEEE_ADDR_11 1
#define IEEE_ADDR_12 2
#define IEEE_ADDR_13 3
#define IEEE_ADDR_14 4
#define IEEE_ADDR_15 5
#define IEEE_ADDR_16 6
#define IEEE_ADDR_17 7

#define IEEE_ADDR_2 _SFR_MEM8(0x166)
#define IEEE_ADDR_20 0
#define IEEE_ADDR_21 1
#define IEEE_ADDR_22 2
#define IEEE_ADDR_23 3
#define IEEE_ADDR_24 4
#define IEEE_ADDR_25 5
#define IEEE_ADDR_26 6
#define IEEE_ADDR_27 7

#define IEEE_ADDR_3 _SFR_MEM8(0x167)
#define IEEE_ADDR_30 0
#define IEEE_ADDR_31 1
#define IEEE_ADDR_32 2
#define IEEE_ADDR_33 3
#define IEEE_ADDR_34 4
#define IEEE_ADDR_35 5
#define IEEE_ADDR_36 6
#define IEEE_ADDR_37 7

#define IEEE_ADDR_4 _SFR_MEM8(0x168)
#define IEEE_ADDR_40 0
#define IEEE_ADDR_41 1
#define IEEE_ADDR_42 2
#define IEEE_ADDR_43 3
#define IEEE_ADDR_44 4
#define IEEE_ADDR_45 5
#define IEEE_ADDR_46 6
#define IEEE_ADDR_47 7

#define IEEE_ADDR_5 _SFR_MEM8(0x169)
#define IEEE_ADDR_50 0
#define IEEE_ADDR_51 1
#define IEEE_ADDR_52 2
#define IEEE_ADDR_53 3
#define IEEE_ADDR_54 4
#define IEEE_ADDR_55 5
#define IEEE_ADDR_56 6
#define IEEE_ADDR_57 7

#define IEEE_ADDR_6 _SFR_MEM8(0x16A)
#define IEEE_ADDR_60 0
#define IEEE_ADDR_61 1
#define IEEE_ADDR_62 2
#define IEEE_ADDR_63 3
#define IEEE_ADDR_64 4
#define IEEE_ADDR_65 5
#define IEEE_ADDR_66 6
#define IEEE_ADDR_67 7

#define IEEE_ADDR_7 _SFR_MEM8(0x16B)
#define IEEE_ADDR_70 0
#define IEEE_ADDR_71 1
#define IEEE_ADDR_72 2
#define IEEE_ADDR_73 3
#define IEEE_ADDR_74 4
#define IEEE_ADDR_75 5
#define IEEE_ADDR_76 6
#define IEEE_ADDR_77 7

#define XAH_CTRL_0 _SFR_MEM8(0x16C)
#define SLOTTED_OPERATION 0
#define MAX_CSMA_RETRIES0 1
#define MAX_CSMA_RETRIES1 2
#define MAX_CSMA_RETRIES2 3
#define MAX_FRAME_RETRIES0 4
#define MAX_FRAME_RETRIES1 5
#define MAX_FRAME_RETRIES2 6
#define MAX_FRAME_RETRIES3 7

#define CSMA_SEED_0 _SFR_MEM8(0x16D)
#define CSMA_SEED_00 0
#define CSMA_SEED_01 1
#define CSMA_SEED_02 2
#define CSMA_SEED_03 3
#define CSMA_SEED_04 4
#define CSMA_SEED_05 5
#define CSMA_SEED_06 6
#define CSMA_SEED_07 7

#define CSMA_SEED_1 _SFR_MEM8(0x16E)
#define CSMA_SEED_10 0
#define CSMA_SEED_11 1
#define CSMA_SEED_12 2
#define AACK_I_AM_COORD 3
#define AACK_DIS_ACK 4
#define AACK_SET_PD 5
#define AACK_FVN_MODE0 6
#define AACK_FVN_MODE1 7

#define CSMA_BE _SFR_MEM8(0x16F)
#define MIN_BE0 0
#define MIN_BE1 1
#define MIN_BE2 2
#define MIN_BE3 3
#define MAX_BE0 4
#define MAX_BE1 5
#define MAX_BE2 6
#define MAX_BE3 7

/* Reserved [0x170..0x175] */

#define TST_CTRL_DIGI _SFR_MEM8(0x176)
#define TST_CTRL_DIG0 0
#define TST_CTRL_DIG1 1
#define TST_CTRL_DIG2 2
#define TST_CTRL_DIG3 3

/* Reserved [0x177..0x17A] */

#define TST_RX_LENGTH _SFR_MEM8(0x17B)
#define RX_LENGTH0 0
#define RX_LENGTH1 1
#define RX_LENGTH2 2
#define RX_LENGTH3 3
#define RX_LENGTH4 4
#define RX_LENGTH5 5
#define RX_LENGTH6 6
#define RX_LENGTH7 7

/* Reserved [0x17C..0x17F] */

#define TRXFBST _SFR_MEM8(0x180)

/* Reserved [0x181..0x1FE] */

#define TRXFBEND _SFR_MEM8(0x1FF)



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(1)
#define INT0_vect_num        1

/* External Interrupt Request 1 */
#define INT1_vect            _VECTOR(2)
#define INT1_vect_num        2

/* External Interrupt Request 2 */
#define INT2_vect            _VECTOR(3)
#define INT2_vect_num        3

/* External Interrupt Request 3 */
#define INT3_vect            _VECTOR(4)
#define INT3_vect_num        4

/* External Interrupt Request 4 */
#define INT4_vect            _VECTOR(5)
#define INT4_vect_num        5

/* External Interrupt Request 5 */
#define INT5_vect            _VECTOR(6)
#define INT5_vect_num        6

/* External Interrupt Request 6 */
#define INT6_vect            _VECTOR(7)
#define INT6_vect_num        7

/* External Interrupt Request 7 */
#define INT7_vect            _VECTOR(8)
#define INT7_vect_num        8

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect            _VECTOR(9)
#define PCINT0_vect_num        9

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect            _VECTOR(10)
#define PCINT1_vect_num        10

/* Pin Change Interrupt Request 2 */
#define PCINT2_vect            _VECTOR(11)
#define PCINT2_vect_num        11

/* Watchdog Time-out Interrupt */
#define WDT_vect            _VECTOR(12)
#define WDT_vect_num        12

/* Timer/Counter2 Compare Match A */
#define TIMER2_COMPA_vect            _VECTOR(13)
#define TIMER2_COMPA_vect_num        13

/* Timer/Counter2 Compare Match B */
#define TIMER2_COMPB_vect            _VECTOR(14)
#define TIMER2_COMPB_vect_num        14

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect            _VECTOR(15)
#define TIMER2_OVF_vect_num        15

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(16)
#define TIMER1_CAPT_vect_num        16

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(17)
#define TIMER1_COMPA_vect_num        17

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(18)
#define TIMER1_COMPB_vect_num        18

/* Timer/Counter1 Compare Match C */
#define TIMER1_COMPC_vect            _VECTOR(19)
#define TIMER1_COMPC_vect_num        19

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(20)
#define TIMER1_OVF_vect_num        20

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(21)
#define TIMER0_COMPA_vect_num        21

/* Timer/Counter0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(22)
#define TIMER0_COMPB_vect_num        22

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(23)
#define TIMER0_OVF_vect_num        23

/* SPI Serial Transfer Complete */
#define SPI_STC_vect            _VECTOR(24)
#define SPI_STC_vect_num        24

/* USART0, Rx Complete */
#define USART0_RX_vect            _VECTOR(25)
#define USART0_RX_vect_num        25

/* USART0 Data register Empty */
#define USART0_UDRE_vect            _VECTOR(26)
#define USART0_UDRE_vect_num        26

/* USART0, Tx Complete */
#define USART0_TX_vect            _VECTOR(27)
#define USART0_TX_vect_num        27

/* Analog Comparator */
#define ANALOG_COMP_vect            _VECTOR(28)
#define ANALOG_COMP_vect_num        28

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(29)
#define ADC_vect_num        29

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(30)
#define EE_READY_vect_num        30

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect            _VECTOR(31)
#define TIMER3_CAPT_vect_num        31

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect            _VECTOR(32)
#define TIMER3_COMPA_vect_num        32

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect            _VECTOR(33)
#define TIMER3_COMPB_vect_num        33

/* Timer/Counter3 Compare Match C */
#define TIMER3_COMPC_vect            _VECTOR(34)
#define TIMER3_COMPC_vect_num        34

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect            _VECTOR(35)
#define TIMER3_OVF_vect_num        35

/* USART1, Rx Complete */
#define USART1_RX_vect            _VECTOR(36)
#define USART1_RX_vect_num        36

/* USART1 Data register Empty */
#define USART1_UDRE_vect            _VECTOR(37)
#define USART1_UDRE_vect_num        37

/* USART1, Tx Complete */
#define USART1_TX_vect            _VECTOR(38)
#define USART1_TX_vect_num        38

/* 2-wire Serial Interface */
#define TWI_vect            _VECTOR(39)
#define TWI_vect_num        39

/* Store Program Memory Read */
#define SPM_READY_vect            _VECTOR(40)
#define SPM_READY_vect_num        40

/* Timer/Counter4 Capture Event */
#define TIMER4_CAPT_vect            _VECTOR(41)
#define TIMER4_CAPT_vect_num        41

/* Timer/Counter4 Compare Match A */
#define TIMER4_COMPA_vect            _VECTOR(42)
#define TIMER4_COMPA_vect_num        42

/* Timer/Counter4 Compare Match B */
#define TIMER4_COMPB_vect            _VECTOR(43)
#define TIMER4_COMPB_vect_num        43

/* Timer/Counter4 Compare Match C */
#define TIMER4_COMPC_vect            _VECTOR(44)
#define TIMER4_COMPC_vect_num        44

/* Timer/Counter4 Overflow */
#define TIMER4_OVF_vect            _VECTOR(45)
#define TIMER4_OVF_vect_num        45

/* Timer/Counter5 Capture Event */
#define TIMER5_CAPT_vect            _VECTOR(46)
#define TIMER5_CAPT_vect_num        46

/* Timer/Counter5 Compare Match A */
#define TIMER5_COMPA_vect            _VECTOR(47)
#define TIMER5_COMPA_vect_num        47

/* Timer/Counter5 Compare Match B */
#define TIMER5_COMPB_vect            _VECTOR(48)
#define TIMER5_COMPB_vect_num        48

/* Timer/Counter5 Compare Match C */
#define TIMER5_COMPC_vect            _VECTOR(49)
#define TIMER5_COMPC_vect_num        49

/* Timer/Counter5 Overflow */
#define TIMER5_OVF_vect            _VECTOR(50)
#define TIMER5_OVF_vect_num        50

/* TRX24 - PLL lock interrupt */
#define TRX24_PLL_LOCK_vect            _VECTOR(57)
#define TRX24_PLL_LOCK_vect_num        57

/* TRX24 - PLL unlock interrupt */
#define TRX24_PLL_UNLOCK_vect            _VECTOR(58)
#define TRX24_PLL_UNLOCK_vect_num        58

/* TRX24 - Receive start interrupt */
#define TRX24_RX_START_vect            _VECTOR(59)
#define TRX24_RX_START_vect_num        59

/* TRX24 - RX_END interrupt */
#define TRX24_RX_END_vect            _VECTOR(60)
#define TRX24_RX_END_vect_num        60

/* TRX24 - CCA/ED done interrupt */
#define TRX24_CCA_ED_DONE_vect            _VECTOR(61)
#define TRX24_CCA_ED_DONE_vect_num        61

/* TRX24 - XAH - AMI */
#define TRX24_XAH_AMI_vect            _VECTOR(62)
#define TRX24_XAH_AMI_vect_num        62

/* TRX24 - TX_END interrupt */
#define TRX24_TX_END_vect            _VECTOR(63)
#define TRX24_TX_END_vect_num        63

/* TRX24 AWAKE - tranceiver is reaching state TRX_OFF */
#define TRX24_AWAKE_vect            _VECTOR(64)
#define TRX24_AWAKE_vect_num        64

/* Symbol counter - compare match 1 interrupt */
#define SCNT_CMP1_vect            _VECTOR(65)
#define SCNT_CMP1_vect_num        65

/* Symbol counter - compare match 2 interrupt */
#define SCNT_CMP2_vect            _VECTOR(66)
#define SCNT_CMP2_vect_num        66

/* Symbol counter - compare match 3 interrupt */
#define SCNT_CMP3_vect            _VECTOR(67)
#define SCNT_CMP3_vect_num        67

/* Symbol counter - overflow interrupt */
#define SCNT_OVFL_vect            _VECTOR(68)
#define SCNT_OVFL_vect_num        68

/* Symbol counter - backoff interrupt */
#define SCNT_BACKOFF_vect            _VECTOR(69)
#define SCNT_BACKOFF_vect_num        69

/* AES engine ready interrupt */
#define AES_READY_vect            _VECTOR(70)
#define AES_READY_vect_num        70

/* Battery monitor indicates supply voltage below threshold */
#define BAT_LOW_vect            _VECTOR(71)
#define BAT_LOW_vect_num        71

/* TRX24 TX start interrupt */
#define TRX24_TX_START_vect            _VECTOR(72)
#define TRX24_TX_START_vect_num        72

/* Address match interrupt of address filter 0 */
#define TRX24_AMI0_vect            _VECTOR(73)
#define TRX24_AMI0_vect_num        73

/* Address match interrupt of address filter 1 */
#define TRX24_AMI1_vect            _VECTOR(74)
#define TRX24_AMI1_vect_num        74

/* Address match interrupt of address filter 2 */
#define TRX24_AMI2_vect            _VECTOR(75)
#define TRX24_AMI2_vect_num        75

/* Address match interrupt of address filter 3 */
#define TRX24_AMI3_vect            _VECTOR(76)
#define TRX24_AMI3_vect_num        76

#define _VECTORS_SIZE 308


/* Constants */

#define SPM_PAGESIZE 256
#define FLASHSTART   0x0000
#define FLASHEND     0x1FFFF
#define RAMSTART     0x0200
#define RAMSIZE      16384
#define RAMEND       0x41FF
#define E2START     0
#define E2SIZE      4096
#define E2PAGESIZE  8
#define E2END       0x0FFF
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_CKSEL_SUT0  (unsigned char)~_BV(0)
#define FUSE_CKSEL_SUT1  (unsigned char)~_BV(1)
#define FUSE_CKSEL_SUT2  (unsigned char)~_BV(2)
#define FUSE_CKSEL_SUT3  (unsigned char)~_BV(3)
#define FUSE_CKSEL_SUT4  (unsigned char)~_BV(4)
#define FUSE_CKSEL_SUT5  (unsigned char)~_BV(5)
#define FUSE_CKOUT       (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_CKSEL_SUT0 & FUSE_CKSEL_SUT2 & FUSE_CKSEL_SUT3 & FUSE_CKSEL_SUT4 & FUSE_CKDIV8)


/* High Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_JTAGEN      (unsigned char)~_BV(6)
#define FUSE_OCDEN       (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN & FUSE_JTAGEN)


/* Extended Fuse Byte */
#define FUSE_BODLEVEL0   (unsigned char)~_BV(0)
#define FUSE_BODLEVEL1   (unsigned char)~_BV(1)
#define FUSE_BODLEVEL2   (unsigned char)~_BV(2)
#define EFUSE_DEFAULT    (FUSE_BODLEVEL0)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0xA7
#define SIGNATURE_2 0x02


#endif /* #ifdef _AVR_ATMEGA128RFR2_H_INCLUDED */

