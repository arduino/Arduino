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


#ifndef _AVR_ATTINY441_H_INCLUDED
#define _AVR_ATTINY441_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn441.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define ADCSRB  _SFR_IO8(0x04)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADLAR   3

#define ADCSRA  _SFR_IO8(0x05)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_IO16(0x06)
#endif
#define ADCW    _SFR_IO16(0x06)

#define ADCL    _SFR_IO8(0x06)
#define ADCH    _SFR_IO8(0x07)

#define ADMUXB  _SFR_IO8(0x08)
#define GSEL0   0
#define GSEL1   1
#define REFS0   5
#define REFS1   6
#define REFS2   7

#define ADMUXA  _SFR_IO8(0x09)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define MUX5    5

#define ACSR0A  _SFR_IO8(0x0A)
#define ACIS00  0
#define ACIS01  1
#define ACIC0   2
#define ACIE0   3
#define ACI0    4
#define ACO0    5
#define ACPMUX2 6
#define ACD0    7

#define ACSR0B  _SFR_IO8(0x0B)
#define ACPMUX0 0
#define ACPMUX1 1
#define ACNMUX0 2
#define ACNMUX1 3
#define ACOE0   4
#define HLEV0   6
#define HSEL0   7

#define ACSR1A  _SFR_IO8(0x0C)
#define ACIS10  0
#define ACIS11  1
#define ACIC1   2
#define ACIE1   3
#define ACI1    4
#define ACO1    5
#define ACBG1   6
#define ACD1    7

#define ACSR1B  _SFR_IO8(0x0D)
#define ACME1   2
#define ACOE1   4
#define HLEV1   6
#define HSEL1   7

#define TIFR1   _SFR_IO8(0x0E)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

#define TIMSK1  _SFR_IO8(0x0F)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   5

#define TIFR2   _SFR_IO8(0x10)
#define TOV2    0
#define OCF2A   1
#define OCF2B   2
#define ICF2    5

#define TIMSK2  _SFR_IO8(0x11)
#define TOIE2   0
#define OCIE2A  1
#define OCIE2B  2
#define ICIE2   5

#define PCMSK0  _SFR_IO8(0x12)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define GPIOR0  _SFR_IO8(0x13)

#define GPIOR1  _SFR_IO8(0x14)

#define GPIOR2  _SFR_IO8(0x15)

#define PINB    _SFR_IO8(0x16)
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x17)
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
#define EEPE    1
#define EEMPE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

#define EEDR    _SFR_IO8(0x1D)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x1E)

#define EEARL   _SFR_IO8(0x1E)
#define EEARH   _SFR_IO8(0x1F)

#define PCMSK1  _SFR_IO8(0x20)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3

#define WDTCSR  _SFR_IO8(0x21)
#define WDE     3
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define TCCR1C  _SFR_IO8(0x22)
#define FOC1B   6
#define FOC1A   7

#define GTCCR   _SFR_IO8(0x23)
#define PSR     0
#define TSM     7

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_IO16(0x24)

#define ICR1L   _SFR_IO8(0x24)
#define ICR1H   _SFR_IO8(0x25)

/* Reserved [0x26..0x27] */

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
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR0A  _SFR_IO8(0x30)
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

/* Reserved [0x31] */

#define TCNT0   _SFR_IO8(0x32)

#define TCCR0B  _SFR_IO8(0x33)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

#define MCUSR   _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

#define MCUCR   _SFR_IO8(0x35)
#define ISC00   0
#define ISC01   1
#define SM0     3
#define SM1     4
#define SE      5

#define OCR0A   _SFR_IO8(0x36)

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RFLB    3
#define CTPB    4
#define RSIG    5

#define TIFR0   _SFR_IO8(0x38)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2

#define TIMSK0  _SFR_IO8(0x39)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2

#define GIFR    _SFR_IO8(0x3A)
#define PCIF0   4
#define PCIF1   5
#define INTF0   6

#define GIMSK   _SFR_IO8(0x3B)
#define PCIE0   4
#define PCIE1   5
#define INT0    6

#define OCR0B   _SFR_IO8(0x3C)

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define DIDR0   _SFR_MEM8(0x60)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7

#define DIDR1   _SFR_MEM8(0x61)
#define ADC11D  0
#define ADC10D  1
#define ADC8D   2
#define ADC9D   3

#define PUEB    _SFR_MEM8(0x62)

#define PUEA    _SFR_MEM8(0x63)

#define PORTCR  _SFR_MEM8(0x64)
#define BBMB    1
#define BBMA    0

#define REMAP   _SFR_MEM8(0x65)
#define U0MAP   0
#define SPIMAP  1

#define TOCPMCOE _SFR_MEM8(0x66)
#define TOCC0OE 0
#define TOCC1OE 1
#define TOCC2OE 2
#define TOCC3OE 3
#define TOCC4OE 4
#define TOCC5OE 5
#define TOCC6OE 6
#define TOCC7OE 7

#define TOCPMSA0 _SFR_MEM8(0x67)
#define TOCC0S0 0
#define TOCC0S1 1
#define TOCC1S0 2
#define TOCC1S1 3
#define TOCC2S0 4
#define TOCC2S1 5
#define TOCC3S0 6
#define TOCC3S1 7

#define TOCPMSA1 _SFR_MEM8(0x68)
#define TOCC4S0 0
#define TOCC4S1 1
#define TOCC5S0 2
#define TOCC5S1 3
#define TOCC6S0 4
#define TOCC6S1 5
#define TOCC7S0 6
#define TOCC7S1 7

/* Reserved [0x69] */

#define PHDE    _SFR_MEM8(0x6A)
#define PHDEA0  0
#define PHDEA1  1

/* Reserved [0x6B..0x6F] */

#define PRR     _SFR_MEM8(0x70)
#define PRADC   0
#define PRTIM0  1
#define PRTIM1  2
#define PRTIM2  3
#define PRSPI   4
#define PRUSART0 5
#define PRUSART1 6
#define PRTWI   7

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRSPI)|(1<<PRUSART0)|(1<<PRUSART1)|(1<<PRTWI))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRTIM2
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRUSART1
#define __AVR_HAVE_PRR_PRTWI

#define CCP     _SFR_MEM8(0x71)

#define CLKCR   _SFR_MEM8(0x72)
#define CKSEL0  0
#define CKSEL1  1
#define CKSEL2  2
#define CKSEL3  3
#define SUT     4
#define CKOUTC  5
#define CSTR    6
#define OSCRDY  7

#define CLKPR   _SFR_MEM8(0x73)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3

#define OSCCAL0 _SFR_MEM8(0x74)

#define OSCTCAL0A _SFR_MEM8(0x75)

#define OSCTCAL0B _SFR_MEM8(0x76)

#define OSCCAL1 _SFR_MEM8(0x77)

/* Reserved [0x78..0x7F] */

#define UDR0    _SFR_MEM8(0x80)

/* Combine UBRR0L and UBRR0H */
#define UBRR0   _SFR_MEM16(0x81)

#define UBRR0L  _SFR_MEM8(0x81)
#define UBRR0H  _SFR_MEM8(0x82)

#define UCSR0D  _SFR_MEM8(0x83)
#define SFDE0   5
#define RXS0    6
#define RXSIE0  7

#define UCSR0C  _SFR_MEM8(0x84)
#define UCPOL0  0
#define UCSZ00  1
#define UCSZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL00 6
#define UMSEL01 7

#define UCSR0B  _SFR_MEM8(0x85)
#define TXB80   0
#define RXB80   1
#define UCSZ02  2
#define TXEN0   3
#define RXEN0   4
#define UDRIE0  5
#define TXCIE0  6
#define RXCIE0  7

#define UCSR0A  _SFR_MEM8(0x86)
#define MPCM0   0
#define U2X0    1
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRE0   5
#define TXC0    6
#define RXC0    7

/* Reserved [0x87..0x8F] */

#define UDR1    _SFR_MEM8(0x90)

/* Combine UBRR1L and UBRR1H */
#define UBRR1   _SFR_MEM16(0x91)

#define UBRR1L  _SFR_MEM8(0x91)
#define UBRR1H  _SFR_MEM8(0x92)

#define UCSR1D  _SFR_MEM8(0x93)
#define SFDE1   5
#define RXS1    6
#define RXSIE1  7

#define UCSR1C  _SFR_MEM8(0x94)
#define UCPOL1  0
#define UCSZ10  1
#define UCSZ11  2
#define USBS1   3
#define UPM10   4
#define UPM11   5
#define UMSEL10 6
#define UMSEL11 7

#define UCSR1B  _SFR_MEM8(0x95)
#define TXB81   0
#define RXB81   1
#define UCSZ12  2
#define TXEN1   3
#define RXEN1   4
#define UDRIE1  5
#define TXCIE1  6
#define RXCIE1  7

#define UCSR1A  _SFR_MEM8(0x96)
#define MPCM1   0
#define U2X1    1
#define UPE1    2
#define DOR1    3
#define FE1     4
#define UDRE1   5
#define TXC1    6
#define RXC1    7

/* Reserved [0x97..0x9F] */

#define TWSD    _SFR_MEM8(0xA0)
#define TWSD0   0
#define TWSD1   1
#define TWSD2   2
#define TWSD3   3
#define TWSD4   4
#define TWSD5   5
#define TWSD6   6
#define TWSD7   7

#define TWSAM   _SFR_MEM8(0xA1)
#define TWAE    0
#define TWSAM1  1
#define TWSAM2  2
#define TWSAM3  3
#define TWSAM4  4
#define TWSAM5  5
#define TWSAM6  6
#define TWSAM7  7

#define TWSA    _SFR_MEM8(0xA2)

#define TWSSRA  _SFR_MEM8(0xA3)
#define TWAS    0
#define TWDIR   1
#define TWBE    2
#define TWC     3
#define TWRA    4
#define TWCH    5
#define TWASIF  6
#define TWDIF   7

#define TWSCRB  _SFR_MEM8(0xA4)
#define TWCMD0  0
#define TWCMD1  1
#define TWAA    2
#define TWHNM   3

#define TWSCRA  _SFR_MEM8(0xA5)
#define TWSME   0
#define TWPME   1
#define TWSIE   2
#define TWEN    3
#define TWASIE  4
#define TWDIE   5
#define TWSHE   7

/* Reserved [0xA6..0xAF] */

#define SPDR    _SFR_MEM8(0xB0)

#define SPSR    _SFR_MEM8(0xB1)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPCR    _SFR_MEM8(0xB2)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

/* Reserved [0xB3..0xBF] */

/* Combine ICR2L and ICR2H */
#define ICR2    _SFR_MEM16(0xC0)

#define ICR2L   _SFR_MEM8(0xC0)
#define ICR2H   _SFR_MEM8(0xC1)

/* Combine OCR2BL and OCR2BH */
#define OCR2B   _SFR_MEM16(0xC2)

#define OCR2BL  _SFR_MEM8(0xC2)
#define OCR2BH  _SFR_MEM8(0xC3)

/* Combine OCR2AL and OCR2AH */
#define OCR2A   _SFR_MEM16(0xC4)

#define OCR2AL  _SFR_MEM8(0xC4)
#define OCR2AH  _SFR_MEM8(0xC5)

/* Combine TCNT2L and TCNT2H */
#define TCNT2   _SFR_MEM16(0xC6)

#define TCNT2L  _SFR_MEM8(0xC6)
#define TCNT2H  _SFR_MEM8(0xC7)

#define TCCR2C  _SFR_MEM8(0xC8)
#define FOC2B   6
#define FOC2A   7

#define TCCR2B  _SFR_MEM8(0xC9)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM22   3
#define WGM23   4
#define ICES2   6
#define ICNC2   7

#define TCCR2A  _SFR_MEM8(0xCA)
#define WGM20   0
#define WGM21   1
#define COM2B0  4
#define COM2B1  5
#define COM2A0  6
#define COM2A1  7



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<3)
#define SLEEP_MODE_ADC (0x01<<3)
#define SLEEP_MODE_PWR_DOWN (0x02<<3)
#define SLEEP_MODE_STANDBY (0x03<<3)

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

/* Watchdog Time-out Interrupt */
#define WDT_vect            _VECTOR(4)
#define WDT_vect_num        4

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(5)
#define TIMER1_CAPT_vect_num        5

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(6)
#define TIMER1_COMPA_vect_num        6

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(7)
#define TIMER1_COMPB_vect_num        7

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(8)
#define TIMER1_OVF_vect_num        8

/* TimerCounter0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(9)
#define TIMER0_COMPA_vect_num        9

/* TimerCounter0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(10)
#define TIMER0_COMPB_vect_num        10

/* Timer/Couner0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(11)
#define TIMER0_OVF_vect_num        11

/* Analog Comparator 0 */
#define ANA_COMP0_vect            _VECTOR(12)
#define ANA_COMP0_vect_num        12

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(13)
#define ADC_vect_num        13

/* EEPROM Ready */
#define EE_RDY_vect            _VECTOR(14)
#define EE_RDY_vect_num        14

/* Analog Comparator 1 */
#define ANA_COMP1_vect            _VECTOR(15)
#define ANA_COMP1_vect_num        15

/* Timer/Counter2 Capture Event */
#define TIMER2_CAPT_vect            _VECTOR(16)
#define TIMER2_CAPT_vect_num        16

/* Timer/Counter2 Compare Match A */
#define TIMER2_COMPA_vect            _VECTOR(17)
#define TIMER2_COMPA_vect_num        17

/* Timer/Counter2 Compare Match B */
#define TIMER2_COMPB_vect            _VECTOR(18)
#define TIMER2_COMPB_vect_num        18

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect            _VECTOR(19)
#define TIMER2_OVF_vect_num        19

/* Serial Peripheral Interface */
#define SPI_vect            _VECTOR(20)
#define SPI_vect_num        20

/* USART0, Start */
#define USART0_START_vect            _VECTOR(21)
#define USART0_START_vect_num        21

/* USART0, Rx Complete */
#define USART0_RX_vect            _VECTOR(22)
#define USART0_RX_vect_num        22

/* USART0 Data Register Empty */
#define USART0_UDRE_vect            _VECTOR(23)
#define USART0_UDRE_vect_num        23

/* USART0, Tx Complete */
#define USART0_TX_vect            _VECTOR(24)
#define USART0_TX_vect_num        24

/* USART1, Start */
#define USART1_START_vect            _VECTOR(25)
#define USART1_START_vect_num        25

/* USART1, Rx Complete */
#define USART1_RX_vect            _VECTOR(26)
#define USART1_RX_vect_num        26

/* USART1 Data Register Empty */
#define USART1_UDRE_vect            _VECTOR(27)
#define USART1_UDRE_vect_num        27

/* USART1, Tx Complete */
#define USART1_TX_vect            _VECTOR(28)
#define USART1_TX_vect_num        28

/* Two-wire Serial Interface */
#define TWI_SLAVE_vect            _VECTOR(29)
#define TWI_SLAVE_vect_num        29

#define _VECTORS_SIZE 60


/* Constants */

#define SPM_PAGESIZE 16
#define FLASHSTART   0x0000
#define FLASHEND     0x0FFF
#define RAMSTART     0x0100
#define RAMSIZE      256
#define RAMEND       0x01FF
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
#define FUSE_SUT_CKSEL2  (unsigned char)~_BV(2)
#define FUSE_SUT_CKSEL3  (unsigned char)~_BV(3)
#define FUSE_SUT_CKSEL4  (unsigned char)~_BV(4)
#define FUSE_CKOUT       (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_SUT_CKSEL0 & FUSE_SUT_CKSEL2 & FUSE_SUT_CKSEL3 & FUSE_SUT_CKSEL4 & FUSE_CKDIV8)


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
#define FUSE_SELFPRGEN   (unsigned char)~_BV(0)
#define FUSE_BODACT0     (unsigned char)~_BV(1)
#define FUSE_BODACT1     (unsigned char)~_BV(2)
#define FUSE_BODPD0      (unsigned char)~_BV(3)
#define FUSE_BODPD1      (unsigned char)~_BV(4)
#define FUSE_ULPOSCSEL0  (unsigned char)~_BV(5)
#define FUSE_ULPOSCSEL1  (unsigned char)~_BV(6)
#define FUSE_ULPOSCSEL2  (unsigned char)~_BV(7)
#define EFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x92
#define SIGNATURE_2 0x15


#endif /* #ifdef _AVR_ATTINY441_H_INCLUDED */

