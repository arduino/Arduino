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


#ifndef _AVR_ATMEGA64A_H_INCLUDED
#define _AVR_ATMEGA64A_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom64a.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PINF    _SFR_IO8(0x00)
#define PINF7   7
#define PINF6   6
#define PINF5   5
#define PINF4   4
#define PINF3   3
#define PINF2   2
#define PINF1   1
#define PINF0   0

#define PINE    _SFR_IO8(0x01)
#define PINE7   7
#define PINE6   6
#define PINE5   5
#define PINE4   4
#define PINE3   3
#define PINE2   2
#define PINE1   1
#define PINE0   0

#define DDRE    _SFR_IO8(0x02)
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

#define PORTE   _SFR_IO8(0x03)
#define PORTE7  7
#define PORTE6  6
#define PORTE5  5
#define PORTE4  4
#define PORTE3  3
#define PORTE2  2
#define PORTE1  1
#define PORTE0  0

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_IO16(0x04)
#endif
#define ADCW    _SFR_IO16(0x04)

#define ADCL    _SFR_IO8(0x04)
#define ADCH    _SFR_IO8(0x05)

#define ADCSRA  _SFR_IO8(0x06)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADMUX   _SFR_IO8(0x07)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

#define ACSR    _SFR_IO8(0x08)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

#define UBRR0L  _SFR_IO8(0x09)

#define UCSR0B  _SFR_IO8(0x0A)
#define TXB80   0
#define RXB80   1
#define UCSZ02  2
#define TXEN0   3
#define RXEN0   4
#define UDRIE0  5
#define TXCIE0  6
#define RXCIE0  7

#define UCSR0A  _SFR_IO8(0x0B)
#define MPCM0   0
#define U2X0    1
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRE0   5
#define TXC0    6
#define RXC0    7

#define UDR0    _SFR_IO8(0x0C)

#define SPCR    _SFR_IO8(0x0D)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define SPSR    _SFR_IO8(0x0E)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPDR    _SFR_IO8(0x0F)

#define PIND    _SFR_IO8(0x10)
#define PIND7   7
#define PIND6   6
#define PIND5   5
#define PIND4   4
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0

#define DDRD    _SFR_IO8(0x11)
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

#define PORTD   _SFR_IO8(0x12)
#define PORTD7  7
#define PORTD6  6
#define PORTD5  5
#define PORTD4  4
#define PORTD3  3
#define PORTD2  2
#define PORTD1  1
#define PORTD0  0

#define PINC    _SFR_IO8(0x13)
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x14)
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

#define PORTC   _SFR_IO8(0x15)
#define PORTC7  7
#define PORTC6  6
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

#define PINB    _SFR_IO8(0x16)
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x17)
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

#define PORTB   _SFR_IO8(0x18)
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PINA    _SFR_IO8(0x19)
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

#define DDRA    _SFR_IO8(0x1A)
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

#define PORTA   _SFR_IO8(0x1B)
#define PORTA7  7
#define PORTA6  6
#define PORTA5  5
#define PORTA4  4
#define PORTA3  3
#define PORTA2  2
#define PORTA1  1
#define PORTA0  0

#define EECR    _SFR_IO8(0x1C)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3

#define EEDR    _SFR_IO8(0x1D)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x1E)

#define EEARL   _SFR_IO8(0x1E)
#define EEARH   _SFR_IO8(0x1F)

#define SFIOR   _SFR_IO8(0x20)
#define ACME    3
#define PSR321  0
#define PSR0    1
#define PUD     2
#define TSM     7

#define WDTCR   _SFR_IO8(0x21)
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDE     3
#define WDCE    4

#define OCDR    _SFR_IO8(0x22)
#define OCDR0   0
#define OCDR1   1
#define OCDR2   2
#define OCDR3   3
#define OCDR4   4
#define OCDR5   5
#define OCDR6   6
#define OCDR7   7

#define OCR2    _SFR_IO8(0x23)

#define TCNT2   _SFR_IO8(0x24)

#define TCCR2   _SFR_IO8(0x25)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM20   4
#define COM21   5
#define WGM20   6
#define FOC2    7

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_IO16(0x26)

#define ICR1L   _SFR_IO8(0x26)
#define ICR1H   _SFR_IO8(0x27)

/* Combine OCR1BL and OCR1BH */
#define OCR1B   _SFR_IO16(0x28)

#define OCR1BL  _SFR_IO8(0x28)
#define OCR1BH  _SFR_IO8(0x29)

/* Combine OCR1AL and OCR1AH */
#define OCR1A   _SFR_IO16(0x2A)

#define OCR1AL  _SFR_IO8(0x2A)
#define OCR1AH  _SFR_IO8(0x2B)

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_IO16(0x2C)

#define TCNT1L  _SFR_IO8(0x2C)
#define TCNT1H  _SFR_IO8(0x2D)

#define TCCR1B  _SFR_IO8(0x2E)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1A  _SFR_IO8(0x2F)
#define WGM10   0
#define WGM11   1
#define COM1C0  2
#define COM1C1  3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define ASSR    _SFR_IO8(0x30)
#define TCR0UB  0
#define OCR0UB  1
#define TCN0UB  2
#define AS0     3

#define OCR0    _SFR_IO8(0x31)

#define TCNT0   _SFR_IO8(0x32)

#define TCCR0   _SFR_IO8(0x33)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define MCUCSR  _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3
#define JTRF    4
#define JTD     7

#define MCUCR   _SFR_IO8(0x35)
#define IVCE    0
#define IVSEL   1
#define SM2     2
#define SM0     3
#define SM1     4
#define SE      5
#define SRW10   6
#define SRE     7

#define TIFR    _SFR_IO8(0x36)
#define TOV0    0
#define OCF0    1
#define TOV1    2
#define OCF1B   3
#define OCF1A   4
#define ICF1    5
#define TOV2    6
#define OCF2    7

#define TIMSK   _SFR_IO8(0x37)
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

#define EIFR    _SFR_IO8(0x38)
#define INTF0   0
#define INTF1   1
#define INTF2   2
#define INTF3   3
#define INTF4   4
#define INTF5   5
#define INTF6   6
#define INTF7   7

#define EIMSK   _SFR_IO8(0x39)
#define INT0    0
#define INT1    1
#define INT2    2
#define INT3    3
#define INT4    4
#define INT5    5
#define INT6    6
#define INT7    7

#define EICRB   _SFR_IO8(0x3A)
#define ISC40   0
#define ISC41   1
#define ISC50   2
#define ISC51   3
#define ISC60   4
#define ISC61   5
#define ISC70   6
#define ISC71   7

/* Reserved [0x3B] */

#define XDIV    _SFR_IO8(0x3C)
#define XDIV0   0
#define XDIV1   1
#define XDIV2   2
#define XDIV3   3
#define XDIV4   4
#define XDIV5   5
#define XDIV6   6
#define XDIVEN  7

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

/* Reserved [0x40..0x60] */

#define DDRF    _SFR_MEM8(0x61)
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

#define PORTF   _SFR_MEM8(0x62)
#define PORTF7  7
#define PORTF6  6
#define PORTF5  5
#define PORTF4  4
#define PORTF3  3
#define PORTF2  2
#define PORTF1  1
#define PORTF0  0

#define PING    _SFR_MEM8(0x63)
#define PING4   4
#define PING3   3
#define PING2   2
#define PING1   1
#define PING0   0

#define DDRG    _SFR_MEM8(0x64)
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

#define PORTG   _SFR_MEM8(0x65)
#define PORTG4  4
#define PORTG3  3
#define PORTG2  2
#define PORTG1  1
#define PORTG0  0

/* Reserved [0x66..0x67] */

#define SPMCSR  _SFR_MEM8(0x68)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define RWWSB   6
#define SPMIE   7

/* Reserved [0x69] */

#define EICRA   _SFR_MEM8(0x6A)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define ISC20   4
#define ISC21   5
#define ISC30   6
#define ISC31   7

/* Reserved [0x6B] */

#define XMCRB   _SFR_MEM8(0x6C)
#define XMM0    0
#define XMM1    1
#define XMM2    2
#define XMBK    7

#define XMCRA   _SFR_MEM8(0x6D)
#define SRW11   1
#define SRW00   2
#define SRW01   3
#define SRL0    4
#define SRL1    5
#define SRL2    6

/* Reserved [0x6E] */

#define OSCCAL  _SFR_MEM8(0x6F)
#define OSCCAL0 0
#define OSCCAL1 1
#define OSCCAL2 2
#define OSCCAL3 3
#define OSCCAL4 4
#define OSCCAL5 5
#define OSCCAL6 6
#define OSCCAL7 7

#define TWBR    _SFR_MEM8(0x70)

#define TWSR    _SFR_MEM8(0x71)
#define TWPS0   0
#define TWPS1   1
#define TWS3    3
#define TWS4    4
#define TWS5    5
#define TWS6    6
#define TWS7    7

#define TWAR    _SFR_MEM8(0x72)
#define TWGCE   0
#define TWA0    1
#define TWA1    2
#define TWA2    3
#define TWA3    4
#define TWA4    5
#define TWA5    6
#define TWA6    7

#define TWDR    _SFR_MEM8(0x73)

#define TWCR    _SFR_MEM8(0x74)
#define TWIE    0
#define TWEN    2
#define TWWC    3
#define TWSTO   4
#define TWSTA   5
#define TWEA    6
#define TWINT   7

/* Reserved [0x75..0x77] */

/* Combine OCR1CL and OCR1CH */
#define OCR1C   _SFR_MEM16(0x78)

#define OCR1CL  _SFR_MEM8(0x78)
#define OCR1CH  _SFR_MEM8(0x79)

#define TCCR1C  _SFR_MEM8(0x7A)
#define FOC1C   5
#define FOC1B   6
#define FOC1A   7

/* Reserved [0x7B] */

#define ETIFR   _SFR_MEM8(0x7C)
#define OCF1C   0
#define OCF3C   1
#define TOV3    2
#define OCF3B   3
#define OCF3A   4
#define ICF3    5

#define ETIMSK  _SFR_MEM8(0x7D)
#define OCIE1C  0
#define OCIE3C  1
#define TOIE3   2
#define OCIE3B  3
#define OCIE3A  4
#define TICIE3  5

/* Reserved [0x7E..0x7F] */

/* Combine ICR3L and ICR3H */
#define ICR3    _SFR_MEM16(0x80)

#define ICR3L   _SFR_MEM8(0x80)
#define ICR3H   _SFR_MEM8(0x81)

/* Combine OCR3CL and OCR3CH */
#define OCR3C   _SFR_MEM16(0x82)

#define OCR3CL  _SFR_MEM8(0x82)
#define OCR3CH  _SFR_MEM8(0x83)

/* Combine OCR3BL and OCR3BH */
#define OCR3B   _SFR_MEM16(0x84)

#define OCR3BL  _SFR_MEM8(0x84)
#define OCR3BH  _SFR_MEM8(0x85)

/* Combine OCR3AL and OCR3AH */
#define OCR3A   _SFR_MEM16(0x86)

#define OCR3AL  _SFR_MEM8(0x86)
#define OCR3AH  _SFR_MEM8(0x87)

/* Combine TCNT3L and TCNT3H */
#define TCNT3   _SFR_MEM16(0x88)

#define TCNT3L  _SFR_MEM8(0x88)
#define TCNT3H  _SFR_MEM8(0x89)

#define TCCR3B  _SFR_MEM8(0x8A)
#define CS30    0
#define CS31    1
#define CS32    2
#define WGM32   3
#define WGM33   4
#define ICES3   6
#define ICNC3   7

#define TCCR3A  _SFR_MEM8(0x8B)
#define WGM30   0
#define WGM31   1
#define COM3C0  2
#define COM3C1  3
#define COM3B0  4
#define COM3B1  5
#define COM3A0  6
#define COM3A1  7

#define TCCR3C  _SFR_MEM8(0x8C)
#define FOC3C   5
#define FOC3B   6
#define FOC3A   7

/* Reserved [0x8D] */

#define ADCSRB  _SFR_MEM8(0x8E)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2

/* Reserved [0x8F] */

#define UBRR0H  _SFR_MEM8(0x90)

/* Reserved [0x91..0x94] */

#define UCSR0C  _SFR_MEM8(0x95)
#define UCPOL0  0
#define UCSZ00  1
#define UCSZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL0  6

/* Reserved [0x96..0x97] */

#define UBRR1H  _SFR_MEM8(0x98)

#define UBRR1L  _SFR_MEM8(0x99)

#define UCSR1B  _SFR_MEM8(0x9A)
#define TXB81   0
#define RXB81   1
#define UCSZ12  2
#define TXEN1   3
#define RXEN1   4
#define UDRIE1  5
#define TXCIE1  6
#define RXCIE1  7

#define UCSR1A  _SFR_MEM8(0x9B)
#define MPCM1   0
#define U2X1    1
#define UPE1    2
#define DOR1    3
#define FE1     4
#define UDRE1   5
#define TXC1    6
#define RXC1    7

#define UDR1    _SFR_MEM8(0x9C)

#define UCSR1C  _SFR_MEM8(0x9D)
#define UCPOL1  0
#define UCSZ10  1
#define UCSZ11  2
#define USBS1   3
#define UPM10   4
#define UPM11   5
#define UMSEL1  6



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<2)
#define SLEEP_MODE_ADC (0x02<<2)
#define SLEEP_MODE_PWR_DOWN (0x04<<2)
#define SLEEP_MODE_PWR_SAVE (0x06<<2)
#define SLEEP_MODE_STANDBY (0x05<<2)
#define SLEEP_MODE_EXT_STANDBY (0x07<<2)

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

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect            _VECTOR(9)
#define TIMER2_COMP_vect_num        9

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect            _VECTOR(10)
#define TIMER2_OVF_vect_num        10

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(11)
#define TIMER1_CAPT_vect_num        11

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(12)
#define TIMER1_COMPA_vect_num        12

/* Timer/Counter Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(13)
#define TIMER1_COMPB_vect_num        13

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(14)
#define TIMER1_OVF_vect_num        14

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect            _VECTOR(15)
#define TIMER0_COMP_vect_num        15

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(16)
#define TIMER0_OVF_vect_num        16

/* SPI Serial Transfer Complete */
#define SPI_STC_vect            _VECTOR(17)
#define SPI_STC_vect_num        17

/* USART0, Rx Complete */
#define USART0_RX_vect            _VECTOR(18)
#define USART0_RX_vect_num        18

/* USART0 Data Register Empty */
#define USART0_UDRE_vect            _VECTOR(19)
#define USART0_UDRE_vect_num        19

/* USART0, Tx Complete */
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

/* Timer/Counter1 Compare Match C */
#define TIMER1_COMPC_vect            _VECTOR(24)
#define TIMER1_COMPC_vect_num        24

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect            _VECTOR(25)
#define TIMER3_CAPT_vect_num        25

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect            _VECTOR(26)
#define TIMER3_COMPA_vect_num        26

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect            _VECTOR(27)
#define TIMER3_COMPB_vect_num        27

/* Timer/Counter3 Compare Match C */
#define TIMER3_COMPC_vect            _VECTOR(28)
#define TIMER3_COMPC_vect_num        28

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect            _VECTOR(29)
#define TIMER3_OVF_vect_num        29

/* USART1, Rx Complete */
#define USART1_RX_vect            _VECTOR(30)
#define USART1_RX_vect_num        30

/* USART1, Data Register Empty */
#define USART1_UDRE_vect            _VECTOR(31)
#define USART1_UDRE_vect_num        31

/* USART1, Tx Complete */
#define USART1_TX_vect            _VECTOR(32)
#define USART1_TX_vect_num        32

/* 2-wire Serial Interface */
#define TWI_vect            _VECTOR(33)
#define TWI_vect_num        33

/* Store Program Memory Read */
#define SPM_READY_vect            _VECTOR(34)
#define SPM_READY_vect_num        34

#define _VECTORS_SIZE 140


/* Constants */

#define SPM_PAGESIZE 256
#define FLASHSTART   0x0000
#define FLASHEND     0xFFFF
#define RAMSTART     0x0100
#define RAMSIZE      4096
#define RAMEND       0x10FF
#define E2START     0
#define E2SIZE      2048
#define E2PAGESIZE  8
#define E2END       0x07FF
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
#define FUSE_BODEN       (unsigned char)~_BV(6)
#define FUSE_BODLEVEL    (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SUT_CKSEL1 & FUSE_SUT_CKSEL2 & FUSE_SUT_CKSEL3 & FUSE_SUT_CKSEL4)


/* High Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_CKOPT       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_JTAGEN      (unsigned char)~_BV(6)
#define FUSE_OCDEN       (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN & FUSE_JTAGEN)


/* Extended Fuse Byte */
#define FUSE_WDTON       (unsigned char)~_BV(0)
#define FUSE_CompMode    (unsigned char)~_BV(1)
#define EFUSE_DEFAULT    (FUSE_CompMode)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x96
#define SIGNATURE_2 0x02


#endif /* #ifdef _AVR_ATMEGA64A_H_INCLUDED */

