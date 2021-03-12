/*****************************************************************************
 *
 * Copyright (C) 2020 Atmel Corporation, a wholly owned subsidiary of Microchip Technology Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ****************************************************************************/


#ifndef _AVR_ATMEGA328PB_H_INCLUDED
#define _AVR_ATMEGA328PB_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom328pb.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

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
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x07)
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
#define PINE3   3
#define PINE2   2
#define PINE1   1
#define PINE0   0

#define DDRE    _SFR_IO8(0x0D)
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
#define PORTE3  3
#define PORTE2  2
#define PORTE1  1
#define PORTE0  0

/* Reserved [0x0F..0x14] */

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

#define TIFR2   _SFR_IO8(0x17)
#define TOV2    0
#define OCF2A   1
#define OCF2B   2

#define TIFR3   _SFR_IO8(0x18)
#define TOV3    0
#define OCF3A   1
#define OCF3B   2
#define ICF3    5

#define TIFR4   _SFR_IO8(0x19)
#define TOV4    0
#define OCF4A   1
#define OCF4B   2
#define ICF4    5

/* Reserved [0x1A] */

#define PCIFR   _SFR_IO8(0x1B)
#define PCIF0   0
#define PCIF1   1
#define PCIF2   2
#define PCIF3   3

#define EIFR    _SFR_IO8(0x1C)
#define INTF0   0
#define INTF1   1

#define EIMSK   _SFR_IO8(0x1D)
#define INT0    0
#define INT1    1

#define GPIOR0  _SFR_IO8(0x1E)

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
#define TSM     7
#define PSRASY  1

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

#define GPIOR2  _SFR_IO8(0x2B)

#define SPCR0   _SFR_IO8(0x2C)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR0   _SFR_IO8(0x2D)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPDR0   _SFR_IO8(0x2E)

#define ACSRB   _SFR_IO8(0x2F)
#define ACOE    0

#define ACSRA   _SFR_IO8(0x30)

#define ACSR    _SFR_IO8(0x30)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

/* Reserved [0x31..0x32] */

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
#define PUD     4
#define BODSE   5
#define BODS    6

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

/* Reserved [0x38..0x3C] */

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

#define XFDCSR  _SFR_MEM8(0x62)
#define XFDIE   0
#define XFDIF   1

/* Reserved [0x63] */

#define PRR0    _SFR_MEM8(0x64)
#define PRADC   0
#define PRUSART0 1
#define PRSPI0  2
#define PRTIM1  3
#define PRUSART1 4
#define PRTIM0  5
#define PRTIM2  6
#define PRTWI0  7

#define __AVR_HAVE_PRR0	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI0)|(1<<PRTIM1)|(1<<PRUSART1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI0))
#define __AVR_HAVE_PRR0_PRADC
#define __AVR_HAVE_PRR0_PRUSART0
#define __AVR_HAVE_PRR0_PRSPI0
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRUSART1
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM2
#define __AVR_HAVE_PRR0_PRTWI0

#define PRR1    _SFR_MEM8(0x65)
#define PRTIM3  0
#define PRSPI1  2
#define PRTIM4  3
#define PRPTC   4
#define PRTWI1  5

#define __AVR_HAVE_PRR1	((1<<PRTIM3)|(1<<PRSPI1)|(1<<PRTIM4)|(1<<PRPTC)|(1<<PRTWI1))
#define __AVR_HAVE_PRR1_PRTIM3
#define __AVR_HAVE_PRR1_PRSPI1
#define __AVR_HAVE_PRR1_PRTIM4
#define __AVR_HAVE_PRR1_PRPTC
#define __AVR_HAVE_PRR1_PRTWI1

#define OSCCAL  _SFR_MEM8(0x66)
#define OSCCAL0 0
#define OSCCAL1 1
#define OSCCAL2 2
#define OSCCAL3 3
#define OSCCAL4 4
#define OSCCAL5 5
#define OSCCAL6 6
#define OSCCAL7 7

/* Reserved [0x67] */

#define PCICR   _SFR_MEM8(0x68)
#define PCIE0   0
#define PCIE1   1
#define PCIE2   2
#define PCIE3   3

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

/* Reserved [0x6A] */

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
#define ICIE1   5

#define TIMSK2  _SFR_MEM8(0x70)
#define TOIE2   0
#define OCIE2A  1
#define OCIE2B  2

#define TIMSK3  _SFR_MEM8(0x71)
#define TOIE3   0
#define OCIE3A  1
#define OCIE3B  2
#define ICIE3   5

#define TIMSK4  _SFR_MEM8(0x72)
#define TOIE4   0
#define OCIE4A  1
#define OCIE4B  2
#define ICIE4   5

#define PCMSK3  _SFR_MEM8(0x73)
#define PCINT24 0
#define PCINT25 1
#define PCINT26 2
#define PCINT27 3

/* Reserved [0x74..0x77] */

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
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ACME    6

#define ADMUX   _SFR_MEM8(0x7C)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define ADLAR   5
#define REFS0   6
#define REFS1   7

/* Reserved [0x7D] */

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

/* Reserved [0x8C..0x8F] */

#define TCCR3A  _SFR_MEM8(0x90)
#define WGM30   0
#define WGM31   1
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

/* Reserved [0x9C..0x9F] */

#define TCCR4A  _SFR_MEM8(0xA0)
#define WGM40   0
#define WGM41   1
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

#define SPCR1   _SFR_MEM8(0xAC)
#define SPR10   0
#define SPR11   1
#define CPHA1   2
#define CPOL1   3
#define MSTR1   4
#define DORD1   5
#define SPE1    6
#define SPIE1   7

#define SPSR1   _SFR_MEM8(0xAD)
#define SPI2X1  0
#define WCOL1   6
#define SPIF1   7

#define SPDR1   _SFR_MEM8(0xAE)

/* Reserved [0xAF] */

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

/* Reserved [0xB7] */

#define TWBR0   _SFR_MEM8(0xB8)

#define TWSR0   _SFR_MEM8(0xB9)
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define TWAR0   _SFR_MEM8(0xBA)
#define TWGCE   0
#define TWA0    1
#define TWA1    2
#define TWA2    3
#define TWA3    4
#define TWA4    5
#define TWA5    6
#define TWA6    7

#define TWDR0   _SFR_MEM8(0xBB)

#define TWCR0   _SFR_MEM8(0xBC)
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

#define TWAMR0  _SFR_MEM8(0xBD)
#define TWAM0   1
#define TWAM1   2
#define TWAM2   3
#define TWAM3   4
#define TWAM4   5
#define TWAM5   6
#define TWAM6   7

/* Reserved [0xBE..0xBF] */

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

#define UCSR0D  _SFR_MEM8(0xC3)
#define SFDE    5
#define RXS     6
#define RXSIE   7

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

#define UCSR1D  _SFR_MEM8(0xCB)
#define SFDE1   5
#define RXS1    6
#define RXSIE1  7

/* Combine UBRR1L and UBRR1H */
#define UBRR1   _SFR_MEM16(0xCC)

#define UBRR1L  _SFR_MEM8(0xCC)
#define UBRR1H  _SFR_MEM8(0xCD)

#define UDR1    _SFR_MEM8(0xCE)

/* Reserved [0xCF..0xD7] */

#define TWBR1   _SFR_MEM8(0xD8)

#define TWSR1   _SFR_MEM8(0xD9)
#define TWPS10  0
#define TWPS11  1
#define TWS13   3
#define TWS14   4
#define TWS15   5
#define TWS16   6
#define TWS17   7

#define TWAR1   _SFR_MEM8(0xDA)

#define TWDR1   _SFR_MEM8(0xDB)

#define TWCR1   _SFR_MEM8(0xDC)
#define TWIE1   0
#define TWEN1   2
#define TWWC1   3
#define TWSTO1  4
#define TWSTA1  5
#define TWEA1   6
#define TWINT1  7

#define TWAMR1  _SFR_MEM8(0xDD)
#define TWAM10  1
#define TWAM11  2
#define TWAM12  3
#define TWAM13  4
#define TWAM14  5
#define TWAM15  6
#define TWAM16  7



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

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect            _VECTOR(3)
#define PCINT0_vect_num        3

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect            _VECTOR(4)
#define PCINT1_vect_num        4

/* Pin Change Interrupt Request 2 */
#define PCINT2_vect            _VECTOR(5)
#define PCINT2_vect_num        5

/* Watchdog Time-out Interrupt */
#define WDT_vect            _VECTOR(6)
#define WDT_vect_num        6

/* Timer/Counter2 Compare Match A */
#define TIMER2_COMPA_vect            _VECTOR(7)
#define TIMER2_COMPA_vect_num        7

/* Timer/Counter2 Compare Match B */
#define TIMER2_COMPB_vect            _VECTOR(8)
#define TIMER2_COMPB_vect_num        8

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect            _VECTOR(9)
#define TIMER2_OVF_vect_num        9

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(10)
#define TIMER1_CAPT_vect_num        10

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(11)
#define TIMER1_COMPA_vect_num        11

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(12)
#define TIMER1_COMPB_vect_num        12

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(13)
#define TIMER1_OVF_vect_num        13

/* TimerCounter0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(14)
#define TIMER0_COMPA_vect_num        14

/* TimerCounter0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(15)
#define TIMER0_COMPB_vect_num        15

/* Timer/Couner0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(16)
#define TIMER0_OVF_vect_num        16

/* SPI Serial Transfer Complete */
#define SPI0_STC_vect            _VECTOR(17)
#define SPI0_STC_vect_num        17

/* USART0 Rx Complete */
#define USART0_RX_vect            _VECTOR(18)
#define USART0_RX_vect_num        18

/* USART0, Data Register Empty */
#define USART0_UDRE_vect            _VECTOR(19)
#define USART0_UDRE_vect_num        19

/* USART0 Tx Complete */
#define USART0_TX_vect            _VECTOR(20)
#define USART0_TX_vect_num        20

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(21)
#define ADC_vect_num        21

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(22)
#define EE_READY_vect_num        22

/* Analog Comparator */
#define ANALOG_COMP_vect            _VECTOR(23)
#define ANALOG_COMP_vect_num        23

/* Two-wire Serial Interface */
#define TWI0_vect            _VECTOR(24)
#define TWI0_vect_num        24

/* Store Program Memory Read */
#define SPM_Ready_vect            _VECTOR(25)
#define SPM_Ready_vect_num        25

/* USART0 Start frame detection */
#define USART0_START_vect            _VECTOR(26)
#define USART0_START_vect_num        26

/* Pin Change Interrupt Request 3 */
#define PCINT3_vect            _VECTOR(27)
#define PCINT3_vect_num        27

/* USART1 Rx Complete */
#define USART1_RX_vect            _VECTOR(28)
#define USART1_RX_vect_num        28

/* USART1, Data Register Empty */
#define USART1_UDRE_vect            _VECTOR(29)
#define USART1_UDRE_vect_num        29

/* USART1 Tx Complete */
#define USART1_TX_vect            _VECTOR(30)
#define USART1_TX_vect_num        30

/* USART1 Start frame detection */
#define USART1_START_vect            _VECTOR(31)
#define USART1_START_vect_num        31

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect            _VECTOR(32)
#define TIMER3_CAPT_vect_num        32

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect            _VECTOR(33)
#define TIMER3_COMPA_vect_num        33

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect            _VECTOR(34)
#define TIMER3_COMPB_vect_num        34

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect            _VECTOR(35)
#define TIMER3_OVF_vect_num        35

/* Clock failure detection interrupt */
#define CFD_vect            _VECTOR(36)
#define CFD_vect_num        36

/* PTC End of conversion */
#define PTC_EOC_vect            _VECTOR(37)
#define PTC_EOC_vect_num        37

/* PTC Window comparator mode */
#define PTC_WCOMP_vect            _VECTOR(38)
#define PTC_WCOMP_vect_num        38

/* SPI1 Serial Transfer Complete */
#define SPI1_STC_vect            _VECTOR(39)
#define SPI1_STC_vect_num        39

/* TWI Transfer Complete */
#define TWI1_vect            _VECTOR(40)
#define TWI1_vect_num        40

/* Timer/Counter4 Capture Event */
#define TIMER4_CAPT_vect            _VECTOR(41)
#define TIMER4_CAPT_vect_num        41

/* Timer/Counter4 Compare Match A */
#define TIMER4_COMPA_vect            _VECTOR(42)
#define TIMER4_COMPA_vect_num        42

/* Timer/Counter4 Compare Match B */
#define TIMER4_COMPB_vect            _VECTOR(43)
#define TIMER4_COMPB_vect_num        43

/* Timer/Counter4 Overflow */
#define TIMER4_OVF_vect            _VECTOR(44)
#define TIMER4_OVF_vect_num        44

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define _VECTORS_SIZE 180
#else
#  define _VECTORS_SIZE 180U
#endif


/* Constants */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 128
#  define FLASHSTART   0x0000
#  define FLASHEND     0x7FFF
#else
#  define SPM_PAGESIZE 128U
#  define FLASHSTART   0x0000U
#  define FLASHEND     0x7FFFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define RAMSTART     0x0100
#  define RAMSIZE      2048
#  define RAMEND       0x08FF
#else
#  define RAMSTART     0x0100U
#  define RAMSIZE      2048U
#  define RAMEND       0x08FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define E2START     0
#  define E2SIZE      1024
#  define E2PAGESIZE  4
#  define E2END       0x03FF
#else
#  define E2START     0U
#  define E2SIZE      1024U
#  define E2PAGESIZE  4U
#  define E2END       0x03FFU
#endif
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
#define FUSE_CFD         (unsigned char)~_BV(3)
#define EFUSE_DEFAULT    (FUSE_CFD)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x16




#endif /* #ifdef _AVR_ATMEGA328PB_H_INCLUDED */

