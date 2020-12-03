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


#ifndef _AVR_ATTINY828_H_INCLUDED
#define _AVR_ATTINY828_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn828.h"
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

#define PUEA    _SFR_IO8(0x03)

#define PINB    _SFR_IO8(0x04)
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x05)
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

#define PORTB   _SFR_IO8(0x06)
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PUEB    _SFR_IO8(0x07)

#define PINC    _SFR_IO8(0x08)
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x09)
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

#define PORTC   _SFR_IO8(0x0A)
#define PORTC7  7
#define PORTC6  6
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

#define PUEC    _SFR_IO8(0x0B)

#define PIND    _SFR_IO8(0x0C)
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0

#define DDRD    _SFR_IO8(0x0D)
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

#define PORTD   _SFR_IO8(0x0E)
#define PORTD3  3
#define PORTD2  2
#define PORTD1  1
#define PORTD0  0

#define PUED    _SFR_IO8(0x0F)

/* Reserved [0x10..0x13] */

#define PHDE    _SFR_IO8(0x14)
#define PHDEC   2

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

/* Reserved [0x17..0x1A] */

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

#define EEAR    _SFR_IO8(0x21)

/* Reserved [0x22] */

#define GTCCR   _SFR_IO8(0x23)
#define PSRSYNC 0
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

#define ACSRB   _SFR_IO8(0x2F)
#define ACPMUX0 0
#define ACPMUX1 1
#define ACNMUX0 2
#define ACNMUX1 3
#define HLEV    6
#define HSEL    7

#define ACSRA   _SFR_IO8(0x30)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACPMUX2 6
#define ACD     7

/* Reserved [0x31..0x32] */

#define SMCR    _SFR_IO8(0x33)
#define SE      0
#define SM0     1
#define SM1     2

#define MCUSR   _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

#define MCUCR   _SFR_IO8(0x35)
#define IVSEL   1

#define CCP     _SFR_IO8(0x36)

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RWFLB   3
#define RWWSRE  4
#define RSIG    5
#define RWWSB   6
#define SPMIE   7

/* Reserved [0x38..0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCSR  _SFR_MEM8(0x60)
#define WDE     3
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

/* Reserved [0x62..0x63] */

#define PRR     _SFR_MEM8(0x64)
#define PRADC   0
#define PRUSART0 1
#define PRSPI   2
#define PRTIM1  3
#define PRTIM0  5
#define PRTWI   7

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTWI))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTWI

/* Reserved [0x65] */

#define OSCCAL0 _SFR_MEM8(0x66)

#define OSCCAL1 _SFR_MEM8(0x67)

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
#define ICIE1   5

/* Reserved [0x70..0x72] */

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
#define ADLAR   3

#define ADMUXA  _SFR_MEM8(0x7C)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4

#define ADMUXB  _SFR_MEM8(0x7D)
#define MUX5    0
#define REFS    5

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
#define ADC8D   0
#define ADC9D   1
#define ADC10D  2
#define ADC11D  3
#define ADC12D  4
#define ADC13D  5
#define ADC14D  6
#define ADC15D  7

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

/* Reserved [0x8C..0xB7] */

#define TWSCRA  _SFR_MEM8(0xB8)
#define TWSME   0
#define TWPME   1
#define TWSIE   2
#define TWEN    3
#define TWASIE  4
#define TWDIE   5
#define TWSHE   7

#define TWSCRB  _SFR_MEM8(0xB9)
#define TWCMD0  0
#define TWCMD1  1
#define TWAA    2
#define TWHNM   3

#define TWSSRA  _SFR_MEM8(0xBA)
#define TWAS    0
#define TWDIR   1
#define TWBE    2
#define TWC     3
#define TWRA    4
#define TWCH    5
#define TWASIF  6
#define TWDIF   7

#define TWSAM   _SFR_MEM8(0xBB)
#define TWAE    0
#define TWSAM1  1
#define TWSAM2  2
#define TWSAM3  3
#define TWSAM4  4
#define TWSAM5  5
#define TWSAM6  6
#define TWSAM7  7

#define TWSA    _SFR_MEM8(0xBC)

#define TWSD    _SFR_MEM8(0xBD)
#define TWSD0   0
#define TWSD1   1
#define TWSD2   2
#define TWSD3   3
#define TWSD4   4
#define TWSD5   5
#define TWSD6   6
#define TWSD7   7

/* Reserved [0xBE..0xBF] */

#define UCSRA   _SFR_MEM8(0xC0)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UCSRB   _SFR_MEM8(0xC1)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRC   _SFR_MEM8(0xC2)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL0  6
#define UMSEL1  7

#define UCSRD   _SFR_MEM8(0xC3)
#define SFDE    5
#define RXS     6
#define RXSIE   7

/* Combine UBRRL and UBRRH */
#define UBRR    _SFR_MEM16(0xC4)

#define UBRRL   _SFR_MEM8(0xC4)
#define UBRRH   _SFR_MEM8(0xC5)

#define UDR     _SFR_MEM8(0xC6)

/* Reserved [0xC7..0xDD] */

#define DIDR2   _SFR_MEM8(0xDE)
#define ADC16D  0
#define ADC17D  1
#define ADC18D  2
#define ADC19D  3
#define ADC20D  4
#define ADC21D  5
#define ADC22D  6
#define ADC23D  7

#define DIDR3   _SFR_MEM8(0xDF)
#define ADC24D  0
#define ADC25D  1
#define ADC26D  2
#define ADC27D  3

/* Reserved [0xE0..0xE1] */

#define TOCPMCOE _SFR_MEM8(0xE2)
#define TOCC0OE 0
#define TOCC1OE 1
#define TOCC2OE 2
#define TOCC3OE 3
#define TOCC4OE 4
#define TOCC5OE 5
#define TOCC6OE 6
#define TOCC7OE 7

/* Reserved [0xE3..0xE7] */

#define TOCPMSA0 _SFR_MEM8(0xE8)
#define TOCC0S0 0
#define TOCC0S1 1
#define TOCC1S0 2
#define TOCC1S1 3
#define TOCC2S0 4
#define TOCC2S1 5
#define TOCC3S0 6
#define TOCC3S1 7

#define TOCPMSA1 _SFR_MEM8(0xE9)
#define TOCC4S0 0
#define TOCC4S1 1
#define TOCC5S0 2
#define TOCC5S1 3
#define TOCC6S0 4
#define TOCC6S1 5
#define TOCC7S0 6
#define TOCC7S1 7

/* Reserved [0xEA..0xEF] */

#define OSCTCAL0A _SFR_MEM8(0xF0)

#define OSCTCAL0B _SFR_MEM8(0xF1)



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)

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

/* Pin Change Interrupt Request 3 */
#define PCINT3_vect            _VECTOR(6)
#define PCINT3_vect_num        6

/* Watchdog Time-out Interrupt */
#define WDT_vect            _VECTOR(7)
#define WDT_vect_num        7

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(8)
#define TIMER1_CAPT_vect_num        8

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(9)
#define TIMER1_COMPA_vect_num        9

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(10)
#define TIMER1_COMPB_vect_num        10

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(11)
#define TIMER1_OVF_vect_num        11

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(12)
#define TIMER0_COMPA_vect_num        12

/* Timer/Counter0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(13)
#define TIMER0_COMPB_vect_num        13

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(14)
#define TIMER0_OVF_vect_num        14

/* SPI Serial Transfer Complete */
#define SPI_STC_vect            _VECTOR(15)
#define SPI_STC_vect_num        15

/* USART, Start */
#define USART_START_vect            _VECTOR(16)
#define USART_START_vect_num        16

/* USART Rx Complete */
#define USART_RX_vect            _VECTOR(17)
#define USART_RX_vect_num        17

/* USART, Data Register Empty */
#define USART_UDRE_vect            _VECTOR(18)
#define USART_UDRE_vect_num        18

/* USART Tx Complete */
#define USART_TX_vect            _VECTOR(19)
#define USART_TX_vect_num        19

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(20)
#define ADC_vect_num        20

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(21)
#define EE_READY_vect_num        21

/* Analog Comparator */
#define ANALOG_COMP_vect            _VECTOR(22)
#define ANALOG_COMP_vect_num        22

/* Two-wire Serial Interface */
#define TWI_SLAVE_vect            _VECTOR(23)
#define TWI_SLAVE_vect_num        23

/* Store Program Memory Read */
#define SPM_Ready_vect            _VECTOR(24)
#define SPM_Ready_vect_num        24

/* Touch Sensing */
#define QTRIP_vect            _VECTOR(25)
#define QTRIP_vect_num        25

#define _VECTORS_SIZE 52


/* Constants */

#define SPM_PAGESIZE 64
#define FLASHSTART   0x0000
#define FLASHEND     0x1FFF
#define RAMSTART     0x0100
#define RAMSIZE      512
#define RAMEND       0x02FF
#define E2START     0
#define E2SIZE      256
#define E2PAGESIZE  4
#define E2END       0x00FF
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 3

/* Low Fuse Byte */
#define FUSE_SUT_CKSEL0  (unsigned char)~_BV(0)
#define FUSE_SUT_CKSEL1  (unsigned char)~_BV(1)
#define FUSE_SUT_CKSEL2  (unsigned char)~_BV(4)
#define FUSE_SUT_CKSEL3  (unsigned char)~_BV(5)
#define FUSE_CKOUT       (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SUT_CKSEL0 & FUSE_SUT_CKSEL2 & FUSE_CKDIV8)


/* High Fuse Byte */
#define FUSE_BODLEVEL0   (unsigned char)~_BV(0)
#define FUSE_BODLEVEL1   (unsigned char)~_BV(1)
#define FUSE_BODLEVEL2   (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_DWEN        (unsigned char)~_BV(6)
#define FUSE_RSTDISBL    (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_SPIEN)


/* Extended Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_BODACT0     (unsigned char)~_BV(4)
#define FUSE_BODACT1     (unsigned char)~_BV(5)
#define FUSE_BODPD0      (unsigned char)~_BV(6)
#define FUSE_BODPD1      (unsigned char)~_BV(7)
#define EFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x14


#endif /* #ifdef _AVR_ATTINY828_H_INCLUDED */

