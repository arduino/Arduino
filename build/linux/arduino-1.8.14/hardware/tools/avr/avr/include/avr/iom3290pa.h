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


#ifndef _AVR_ATMEGA3290PA_H_INCLUDED
#define _AVR_ATMEGA3290PA_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom3290pa.h"
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
#define PING5   5
#define PING4   4
#define PING3   3
#define PING2   2
#define PING1   1
#define PING0   0

#define DDRG    _SFR_IO8(0x13)
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
#define PORTG4  4
#define PORTG3  3
#define PORTG2  2
#define PORTG1  1
#define PORTG0  0

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

#define TIFR2   _SFR_IO8(0x17)
#define TOV2    0
#define OCF2A   1

/* Reserved [0x18..0x1B] */

#define EIFR    _SFR_IO8(0x1C)
#define INTF0   0
#define PCIF0   4
#define PCIF1   5
#define PCIF2   6
#define PCIF3   7

#define EIMSK   _SFR_IO8(0x1D)
#define INT0    0
#define PCIE0   4
#define PCIE1   5
#define PCIE2   6
#define PCIE3   7

#define GPIOR0  _SFR_IO8(0x1E)

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3

#define EEDR    _SFR_IO8(0x20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0x22)

#define GTCCR   _SFR_IO8(0x23)
#define PSR310  0
#define TSM     7
#define PSR2    1

#define TCCR0A  _SFR_IO8(0x24)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM0A0  4
#define COM0A1  5
#define WGM00   6
#define FOC0A   7

/* Reserved [0x25] */

#define TCNT0   _SFR_IO8(0x26)

#define OCR0A   _SFR_IO8(0x27)

/* Reserved [0x28..0x29] */

#define GPIOR1  _SFR_IO8(0x2A)

#define GPIOR2  _SFR_IO8(0x2B)

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
#define OCDR7   7
#define OCDR6   6
#define OCDR5   5
#define OCDR4   4
#define OCDR3   3
#define OCDR2   2
#define OCDR1   1
#define OCDR0   0

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
#define BODSE   5
#define BODS    6

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define RWWSB   6
#define SPMIE   7

/* Reserved [0x38..0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCR   _SFR_MEM8(0x60)
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDE     3
#define WDCE    4

#define CLKPR   _SFR_MEM8(0x61)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3
#define CLKPCE  7

/* Reserved [0x62..0x63] */

#define PRR     _SFR_MEM8(0x64)
#define PRADC   0
#define PRUSART0 1
#define PRSPI   2
#define PRTIM1  3
#define PRLCD   4

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRLCD))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRLCD

/* Reserved [0x65] */

#define OSCCAL  _SFR_MEM8(0x66)
#define OSCCAL0 0
#define OSCCAL1 1
#define OSCCAL2 2
#define OSCCAL3 3
#define OSCCAL4 4
#define OSCCAL5 5
#define OSCCAL6 6
#define OSCCAL7 7

/* Reserved [0x67..0x68] */

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1

/* Reserved [0x6A] */

#define PCMSK0  _SFR_MEM8(0x6B)

#define PCMSK1  _SFR_MEM8(0x6C)

#define PCMSK2  _SFR_MEM8(0x6D)

#define TIMSK0  _SFR_MEM8(0x6E)
#define TOIE0   0
#define OCIE0A  1

#define TIMSK1  _SFR_MEM8(0x6F)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   5

#define TIMSK2  _SFR_MEM8(0x70)
#define TOIE2   0
#define OCIE2A  1

/* Reserved [0x71..0x72] */

#define PCMSK3  _SFR_MEM8(0x73)

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
#define ACME    6
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2

#define ADMUX   _SFR_MEM8(0x7C)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
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

/* Reserved [0x8C..0xAF] */

#define TCCR2A  _SFR_MEM8(0xB0)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM21   3
#define COM2A0  4
#define COM2A1  5
#define WGM20   6
#define FOC2A   7

/* Reserved [0xB1] */

#define TCNT2   _SFR_MEM8(0xB2)

#define OCR2A   _SFR_MEM8(0xB3)

/* Reserved [0xB4..0xB5] */

#define ASSR    _SFR_MEM8(0xB6)
#define TCR2UB  0
#define OCR2UB  1
#define TCN2UB  2
#define AS2     3
#define EXCLK   4

/* Reserved [0xB7] */

#define USICR   _SFR_MEM8(0xB8)
#define USITC   0
#define USICLK  1
#define USICS0  2
#define USICS1  3
#define USIWM0  4
#define USIWM1  5
#define USIOIE  6
#define USISIE  7

#define USISR   _SFR_MEM8(0xB9)
#define USICNT0 0
#define USICNT1 1
#define USICNT2 2
#define USICNT3 3
#define USIDC   4
#define USIPF   5
#define USIOIF  6
#define USISIF  7

#define USIDR   _SFR_MEM8(0xBA)

/* Reserved [0xBB..0xBF] */

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
#define UMSEL0  6

/* Reserved [0xC3] */

/* Combine UBRR0L and UBRR0H */
#define UBRR0   _SFR_MEM16(0xC4)

#define UBRR0L  _SFR_MEM8(0xC4)
#define UBRR0H  _SFR_MEM8(0xC5)

#define UDR0    _SFR_MEM8(0xC6)

/* Reserved [0xC7..0xD7] */

#define PINH    _SFR_MEM8(0xD8)
#define PINH7   7
#define PINH6   6
#define PINH5   5
#define PINH4   4
#define PINH3   3
#define PINH2   2
#define PINH1   1
#define PINH0   0

#define DDRH    _SFR_MEM8(0xD9)
#define DDRH7   7
// Inserted "DDH7" from "DDRH7" due to compatibility
#define DDH7    7
#define DDRH6   6
// Inserted "DDH6" from "DDRH6" due to compatibility
#define DDH6    6
#define DDRH5   5
// Inserted "DDH5" from "DDRH5" due to compatibility
#define DDH5    5
#define DDRH4   4
// Inserted "DDH4" from "DDRH4" due to compatibility
#define DDH4    4
#define DDRH3   3
// Inserted "DDH3" from "DDRH3" due to compatibility
#define DDH3    3
#define DDRH2   2
// Inserted "DDH2" from "DDRH2" due to compatibility
#define DDH2    2
#define DDRH1   1
// Inserted "DDH1" from "DDRH1" due to compatibility
#define DDH1    1
#define DDRH0   0
// Inserted "DDH0" from "DDRH0" due to compatibility
#define DDH0    0

#define PORTH   _SFR_MEM8(0xDA)
#define PORTH7  7
#define PORTH6  6
#define PORTH5  5
#define PORTH4  4
#define PORTH3  3
#define PORTH2  2
#define PORTH1  1
#define PORTH0  0

#define PINJ    _SFR_MEM8(0xDB)
#define PINJ6   6
#define PINJ5   5
#define PINJ4   4
#define PINJ3   3
#define PINJ2   2
#define PINJ1   1
#define PINJ0   0

#define DDRJ    _SFR_MEM8(0xDC)
#define DDRJ6   6
// Inserted "DDJ6" from "DDRJ6" due to compatibility
#define DDJ6    6
#define DDRJ5   5
// Inserted "DDJ5" from "DDRJ5" due to compatibility
#define DDJ5    5
#define DDRJ4   4
// Inserted "DDJ4" from "DDRJ4" due to compatibility
#define DDJ4    4
#define DDRJ3   3
// Inserted "DDJ3" from "DDRJ3" due to compatibility
#define DDJ3    3
#define DDRJ2   2
// Inserted "DDJ2" from "DDRJ2" due to compatibility
#define DDJ2    2
#define DDRJ1   1
// Inserted "DDJ1" from "DDRJ1" due to compatibility
#define DDJ1    1
#define DDRJ0   0
// Inserted "DDJ0" from "DDRJ0" due to compatibility
#define DDJ0    0

#define PORTJ   _SFR_MEM8(0xDD)
#define PORTJ6  6
#define PORTJ5  5
#define PORTJ4  4
#define PORTJ3  3
#define PORTJ2  2
#define PORTJ1  1
#define PORTJ0  0

/* Reserved [0xDE..0xE3] */

#define LCDCRA  _SFR_MEM8(0xE4)
#define LCDBL   0
#define LCDCCD  1
#define LCDBD   2
#define LCDIE   3
#define LCDIF   4
#define LCDAB   6
#define LCDEN   7

#define LCDCRB  _SFR_MEM8(0xE5)
#define LCDPM0  0
#define LCDPM1  1
#define LCDPM2  2
#define LCDPM3  3
#define LCDMUX0 4
#define LCDMUX1 5
#define LCD2B   6
#define LCDCS   7

#define LCDFRR  _SFR_MEM8(0xE6)
#define LCDCD0  0
#define LCDCD1  1
#define LCDCD2  2
#define LCDPS0  4
#define LCDPS1  5
#define LCDPS2  6

#define LCDCCR  _SFR_MEM8(0xE7)
#define LCDCC0  0
#define LCDCC1  1
#define LCDCC2  2
#define LCDCC3  3
#define LCDMDT  4
#define LCDDC0  5
#define LCDDC1  6
#define LCDDC2  7

/* Reserved [0xE8..0xEB] */

#define LCDDR0  _SFR_MEM8(0xEC)

#define LCDDR1  _SFR_MEM8(0xED)

#define LCDDR2  _SFR_MEM8(0xEE)

#define LCDDR3  _SFR_MEM8(0xEF)

#define LCDDR4  _SFR_MEM8(0xF0)

#define LCDDR5  _SFR_MEM8(0xF1)

#define LCDDR6  _SFR_MEM8(0xF2)

#define LCDDR7  _SFR_MEM8(0xF3)

#define LCDDR8  _SFR_MEM8(0xF4)

#define LCDDR9  _SFR_MEM8(0xF5)

#define LCDDR10 _SFR_MEM8(0xF6)

#define LCDDR11 _SFR_MEM8(0xF7)

#define LCDDR12 _SFR_MEM8(0xF8)

#define LCDDR13 _SFR_MEM8(0xF9)

#define LCDDR14 _SFR_MEM8(0xFA)

#define LCDDR15 _SFR_MEM8(0xFB)

#define LCDDR16 _SFR_MEM8(0xFC)

#define LCDDR17 _SFR_MEM8(0xFD)

#define LCDDR18 _SFR_MEM8(0xFE)

#define LCDDR19 _SFR_MEM8(0xFF)



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */
#define INT0_vect            _VECTOR(1)
#define INT0_vect_num        1

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect            _VECTOR(2)
#define PCINT0_vect_num        2

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect            _VECTOR(3)
#define PCINT1_vect_num        3

/* Timer/Counter2 Compare Match */
#define TIMER2_COMP_vect            _VECTOR(4)
#define TIMER2_COMP_vect_num        4

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect            _VECTOR(5)
#define TIMER2_OVF_vect_num        5

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(6)
#define TIMER1_CAPT_vect_num        6

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(7)
#define TIMER1_COMPA_vect_num        7

/* Timer/Counter Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(8)
#define TIMER1_COMPB_vect_num        8

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(9)
#define TIMER1_OVF_vect_num        9

/* Timer/Counter0 Compare Match */
#define TIMER0_COMP_vect            _VECTOR(10)
#define TIMER0_COMP_vect_num        10

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(11)
#define TIMER0_OVF_vect_num        11

/* SPI Serial Transfer Complete */
#define SPI_STC_vect            _VECTOR(12)
#define SPI_STC_vect_num        12

/* USART, Rx Complete */
#define USART_RX_vect            _VECTOR(13)
#define USART_RX_vect_num        13

/* USART Data register Empty */
#define USART_UDRE_vect            _VECTOR(14)
#define USART_UDRE_vect_num        14

/* USART0, Tx Complete */
#define USART0_TX_vect            _VECTOR(15)
#define USART0_TX_vect_num        15

/* USI Start Condition */
#define USI_START_vect            _VECTOR(16)
#define USI_START_vect_num        16

/* USI Overflow */
#define USI_OVERFLOW_vect            _VECTOR(17)
#define USI_OVERFLOW_vect_num        17

/* Analog Comparator */
#define ANALOG_COMP_vect            _VECTOR(18)
#define ANALOG_COMP_vect_num        18

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(19)
#define ADC_vect_num        19

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(20)
#define EE_READY_vect_num        20

/* Store Program Memory Read */
#define SPM_READY_vect            _VECTOR(21)
#define SPM_READY_vect_num        21

/* LCD Start of Frame */
#define LCD_vect            _VECTOR(22)
#define LCD_vect_num        22

/* Pin Change Interrupt Request 2 */
#define PCINT2_vect            _VECTOR(23)
#define PCINT2_vect_num        23

/* Pin Change Interrupt Request 3 */
#define PCINT3_vect            _VECTOR(24)
#define PCINT3_vect_num        24

#define _VECTORS_SIZE 100


/* Constants */

#define SPM_PAGESIZE 128
#define FLASHSTART   0x0000
#define FLASHEND     0x7FFF
#define RAMSTART     0x0100
#define RAMSIZE      2048
#define RAMEND       0x08FF
#define E2START     0
#define E2SIZE      1024
#define E2PAGESIZE  4
#define E2END       0x03FF
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
#define FUSE_JTAGEN      (unsigned char)~_BV(6)
#define FUSE_OCDEN       (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN & FUSE_JTAGEN)


/* Extended Fuse Byte */
#define FUSE_RSTDISBL    (unsigned char)~_BV(0)
#define FUSE_BODLEVEL0   (unsigned char)~_BV(1)
#define FUSE_BODLEVEL1   (unsigned char)~_BV(2)
#define EFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x0C


#endif /* #ifdef _AVR_ATMEGA3290PA_H_INCLUDED */

