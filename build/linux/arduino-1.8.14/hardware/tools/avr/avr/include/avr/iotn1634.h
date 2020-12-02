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


#ifndef _AVR_ATTINY1634_H_INCLUDED
#define _AVR_ATTINY1634_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn1634.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC     _SFR_IO16(0x00)
#endif
#define ADCW    _SFR_IO16(0x00)

#define ADCL    _SFR_IO8(0x00)
#define ADCH    _SFR_IO8(0x01)

#define ADCSRB  _SFR_IO8(0x02)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADLAR   3
#define VDPD    6
#define VDEN    7

#define ADCSRA  _SFR_IO8(0x03)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADMUX   _SFR_IO8(0x04)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define ADC0EN  4
#define REFEN   5
#define REFS0   6
#define REFS1   7

#define ACSRB   _SFR_IO8(0x05)
#define ACIRS0  0
#define ACIRS1  1
#define ACME    2
#define ACCE    3
#define ACLP    5
#define HLEV    6
#define HSEL    7

#define ACSRA   _SFR_IO8(0x06)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

#define PINC    _SFR_IO8(0x07)
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x08)
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

#define PORTC   _SFR_IO8(0x09)
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

#define PUEC    _SFR_IO8(0x0A)
#define PUEC0   0
#define PUEC1   1
#define PUEC2   2
#define PUEC3   3
#define PUEC4   4
#define PUEC5   5

#define PINB    _SFR_IO8(0x0B)
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x0C)
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

#define PORTB   _SFR_IO8(0x0D)
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PUEB    _SFR_IO8(0x0E)
#define PUEB0   0
#define PUEB1   1
#define PUEB2   2
#define PUEB3   3

#define PINA    _SFR_IO8(0x0F)
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

#define DDRA    _SFR_IO8(0x10)
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

#define PORTA   _SFR_IO8(0x11)
#define PORTA7  7
#define PORTA6  6
#define PORTA5  5
#define PORTA4  4
#define PORTA3  3
#define PORTA2  2
#define PORTA1  1
#define PORTA0  0

#define PUEA    _SFR_IO8(0x12)
#define PUEA0   0
#define PUEA1   1
#define PUEA2   2
#define PUEA3   3
#define PUEA4   4
#define PUEA5   5
#define PUEA6   6
#define PUEA7   7

#define PORTCR  _SFR_IO8(0x13)
#define BBMB    1
#define BBMC    2
#define BBMA    0

#define GPIOR0  _SFR_IO8(0x14)

#define GPIOR1  _SFR_IO8(0x15)

#define GPIOR2  _SFR_IO8(0x16)

#define OCR0B   _SFR_IO8(0x17)

#define OCR0A   _SFR_IO8(0x18)

#define TCNT0   _SFR_IO8(0x19)

#define TCCR0B  _SFR_IO8(0x1A)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

#define TCCR0A  _SFR_IO8(0x1B)
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

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

#define UDR0    _SFR_IO8(0x20)

/* Combine UBRR0L and UBRR0H */
#define UBRR0   _SFR_IO16(0x21)

#define UBRR0L  _SFR_IO8(0x21)
#define UBRR0H  _SFR_IO8(0x22)

#define UCSR0D  _SFR_IO8(0x23)
#define SFDE0   5
#define RXS0    6
#define RXSIE0  7

#define UCSR0C  _SFR_IO8(0x24)
#define UCPOL0  0
#define UCSZ00  1
#define UCSZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL00 6
#define UMSEL01 7

#define UCSR0B  _SFR_IO8(0x25)
#define TXB80   0
#define RXB80   1
#define UCSZ02  2
#define TXEN0   3
#define RXEN0   4
#define UDRIE0  5
#define TXCIE0  6
#define RXCIE0  7

#define UCSR0A  _SFR_IO8(0x26)
#define MPCM0   0
#define U2X0    1
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRE0   5
#define TXC0    6
#define RXC0    7

#define PCMSK0  _SFR_IO8(0x27)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  _SFR_IO8(0x28)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3

#define PCMSK2  _SFR_IO8(0x29)
#define PCINT12 0
#define PCINT13 1
#define PCINT14 2
#define PCINT15 3
#define PCINT16 4
#define PCINT17 5

#define USICR   _SFR_IO8(0x2A)
#define USITC   0
#define USICLK  1
#define USICS0  2
#define USICS1  3
#define USIWM0  4
#define USIWM1  5
#define USIOIE  6
#define USISIE  7

#define USISR   _SFR_IO8(0x2B)
#define USICNT0 0
#define USICNT1 1
#define USICNT2 2
#define USICNT3 3
#define USIDC   4
#define USIPF   5
#define USIOIF  6
#define USISIF  7

#define USIDR   _SFR_IO8(0x2C)

#define USIBR   _SFR_IO8(0x2D)

/* Reserved [0x2E] */

#define CCP     _SFR_IO8(0x2F)

#define WDTCSR  _SFR_IO8(0x30)
#define WDE     3
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

/* Reserved [0x31] */

#define CLKSR   _SFR_IO8(0x32)
#define CKSEL0  0
#define CKSEL1  1
#define CKSEL2  2
#define CKSEL3  3
#define SUT     4
#define CKOUT_IO 5
#define CSTR    6
#define OSCRDY  7

#define CLKPR   _SFR_IO8(0x33)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3

#define PRR     _SFR_IO8(0x34)
#define PRADC   0
#define PRUSART0 1
#define PRUSART1 2
#define PRUSI   3
#define PRTIM0  4
#define PRTIM1  5
#define PRTWI   6

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSART0)|(1<<PRUSART1)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRTWI))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART0
#define __AVR_HAVE_PRR_PRUSART1
#define __AVR_HAVE_PRR_PRUSI
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRTWI

#define MCUSR   _SFR_IO8(0x35)
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

#define MCUCR   _SFR_IO8(0x36)
#define ISC00   0
#define ISC01   1
#define SE      4
#define SM0     5
#define SM1     6

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RFLB    3
#define CTPB    4
#define RSIG    5

/* Reserved [0x38] */

#define TIFR    _SFR_IO8(0x39)
#define ICF1    3
#define OCF1B   5
#define OCF1A   6
#define TOV1    7
#define OCF0A   0
#define TOV0    1
#define OCF0B   2

#define TIMSK   _SFR_IO8(0x3A)
#define ICIE1   3
#define OCIE1B  5
#define OCIE1A  6
#define TOIE1   7
#define OCIE0A  0
#define TOIE0   1
#define OCIE0B  2

#define GIFR    _SFR_IO8(0x3B)
#define PCIF0   3
#define PCIF1   4
#define PCIF2   5
#define INTF0   6

#define GIMSK   _SFR_IO8(0x3C)
#define PCIE0   3
#define PCIE1   4
#define PCIE2   5
#define INT0    6

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define DIDR0   _SFR_MEM8(0x60)
#define AREFD   0
#define AIN0D   1
#define AIN1D   2
#define ADC0D   3
#define ADC1D   4
#define ADC2D   5
#define ADC3D   6
#define ADC4D   7

#define DIDR1   _SFR_MEM8(0x61)
#define ADC5D   0
#define ADC6D   1
#define ADC7D   2
#define ADC8D   3

#define DIDR2   _SFR_MEM8(0x62)
#define ADC9D   0
#define ADC10D  1
#define ADC11D  2

#define OSCCAL0 _SFR_MEM8(0x63)

#define OSCTCAL0A _SFR_MEM8(0x64)

#define OSCTCAL0B _SFR_MEM8(0x65)

#define OSCCAL1 _SFR_MEM8(0x66)

#define GTCCR   _SFR_MEM8(0x67)
#define PSR10   0
#define TSM     7

/* Combine ICR1L and ICR1H */
#define ICR1    _SFR_MEM16(0x68)

#define ICR1L   _SFR_MEM8(0x68)
#define ICR1H   _SFR_MEM8(0x69)

/* Combine OCR1BL and OCR1BH */
#define OCR1B   _SFR_MEM16(0x6A)

#define OCR1BL  _SFR_MEM8(0x6A)
#define OCR1BH  _SFR_MEM8(0x6B)

/* Combine OCR1AL and OCR1AH */
#define OCR1A   _SFR_MEM16(0x6C)

#define OCR1AL  _SFR_MEM8(0x6C)
#define OCR1AH  _SFR_MEM8(0x6D)

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_MEM16(0x6E)

#define TCNT1L  _SFR_MEM8(0x6E)
#define TCNT1H  _SFR_MEM8(0x6F)

#define TCCR1C  _SFR_MEM8(0x70)
#define FOC1B   6
#define FOC1A   7

#define TCCR1B  _SFR_MEM8(0x71)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1A  _SFR_MEM8(0x72)
#define WGM10   0
#define WGM11   1
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define UDR1    _SFR_MEM8(0x73)

/* Combine UBRR1L and UBRR1H */
#define UBRR1   _SFR_MEM16(0x74)

#define UBRR1L  _SFR_MEM8(0x74)
#define UBRR1H  _SFR_MEM8(0x75)

#define UCSR1D  _SFR_MEM8(0x76)
#define SFDE1   5
#define RXS1    6
#define RXSIE1  7

#define UCSR1C  _SFR_MEM8(0x77)
#define UCPOL1  0
#define UCSZ10  1
#define UCSZ11  2
#define USBS1   3
#define UPM10   4
#define UPM11   5
#define UMSEL10 6
#define UMSEL11 7

#define UCSR1B  _SFR_MEM8(0x78)
#define TXB81   0
#define RXB81   1
#define UCSZ12  2
#define TXEN1   3
#define RXEN1   4
#define UDRIE1  5
#define TXCIE1  6
#define RXCIE1  7

#define UCSR1A  _SFR_MEM8(0x79)
#define MPCM1   0
#define U2X1    1
#define UPE1    2
#define DOR1    3
#define FE1     4
#define UDRE1   5
#define TXC1    6
#define RXC1    7

#define TWSD    _SFR_MEM8(0x7A)
#define TWSD0   0
#define TWSD1   1
#define TWSD2   2
#define TWSD3   3
#define TWSD4   4
#define TWSD5   5
#define TWSD6   6
#define TWSD7   7

#define TWSAM   _SFR_MEM8(0x7B)

#define TWSA    _SFR_MEM8(0x7C)
#define TWSA0   0
#define TWSA1   1
#define TWSA2   2
#define TWSA3   3
#define TWSA4   4
#define TWSA5   5
#define TWSA6   6
#define TWSA7   7

#define TWSSRA  _SFR_MEM8(0x7D)
#define TWAS    0
#define TWDIR   1
#define TWBE    2
#define TWC     3
#define TWRA    4
#define TWCH    5
#define TWASIF  6
#define TWDIF   7

#define TWSCRB  _SFR_MEM8(0x7E)
#define TWCMD0  0
#define TWCMD1  1
#define TWAA    2

#define TWSCRA  _SFR_MEM8(0x7F)
#define TWSME   0
#define TWPME   1
#define TWSIE   2
#define TWEN    3
#define TWASIE  4
#define TWDIE   5
#define TWSHE   7



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<5)
#define SLEEP_MODE_ADC (0x01<<5)
#define SLEEP_MODE_PWR_DOWN (0x02<<5)
#define SLEEP_MODE_STANDBY (0x03<<5)

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

/* Pin Change Interrupt Request 2 */
#define PCINT2_vect            _VECTOR(4)
#define PCINT2_vect_num        4

/* Watchdog Time-out Interrupt */
#define WDT_vect            _VECTOR(5)
#define WDT_vect_num        5

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(6)
#define TIMER1_CAPT_vect_num        6

/* Timer/Counter1 Capture Event */
#define TIM1_CAPT_vect            _VECTOR(6)
#define TIM1_CAPT_vect_num        6

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(7)
#define TIMER1_COMPA_vect_num        7

/* Timer/Counter1 Compare Match A */
#define TIM1_COMPA_vect            _VECTOR(7)
#define TIM1_COMPA_vect_num        7

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(8)
#define TIMER1_COMPB_vect_num        8

/* Timer/Counter1 Compare Match B */
#define TIM1_COMPB_vect            _VECTOR(8)
#define TIM1_COMPB_vect_num        8

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(9)
#define TIMER1_OVF_vect_num        9

/* Timer/Counter1 Overflow */
#define TIM1_OVF_vect            _VECTOR(9)
#define TIM1_OVF_vect_num        9

/* TimerCounter0 Compare Match A */
#define TIMER0_COMPA_vect            _VECTOR(10)
#define TIMER0_COMPA_vect_num        10

/* TimerCounter0 Compare Match A */
#define TIM0_COMPA_vect            _VECTOR(10)
#define TIM0_COMPA_vect_num        10

/* TimerCounter0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(11)
#define TIMER0_COMPB_vect_num        11

/* TimerCounter0 Compare Match B */
#define TIM0_COMPB_vect            _VECTOR(11)
#define TIM0_COMPB_vect_num        11

/* Timer/Couner0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(12)
#define TIMER0_OVF_vect_num        12

/* Timer/Couner0 Overflow */
#define TIM0_OVF_vect            _VECTOR(12)
#define TIM0_OVF_vect_num        12

/* Analog Comparator */
#define ANA_COMP_vect            _VECTOR(13)
#define ANA_COMP_vect_num        13

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(14)
#define ADC_vect_num        14

/* ADC Conversion Complete */
#define ADC_READY_vect            _VECTOR(14)
#define ADC_READY_vect_num        14

/* USART0, Start */
#define USART0_START_vect            _VECTOR(15)
#define USART0_START_vect_num        15

/* USART0, Start */
#define USART0_RXS_vect            _VECTOR(15)
#define USART0_RXS_vect_num        15

/* USART0, Rx Complete */
#define USART0_RX_vect            _VECTOR(16)
#define USART0_RX_vect_num        16

/* USART0, Rx Complete */
#define USART0_RXC_vect            _VECTOR(16)
#define USART0_RXC_vect_num        16

/* USART0 Data Register Empty */
#define USART0_UDRE_vect            _VECTOR(17)
#define USART0_UDRE_vect_num        17

/* USART0 Data Register Empty */
#define USART0_DRE_vect            _VECTOR(17)
#define USART0_DRE_vect_num        17

/* USART0, Tx Complete */
#define USART0_TX_vect            _VECTOR(18)
#define USART0_TX_vect_num        18

/* USART0, Tx Complete */
#define USART0_TXC_vect            _VECTOR(18)
#define USART0_TXC_vect_num        18

/* USART1, Start */
#define USART1_START_vect            _VECTOR(19)
#define USART1_START_vect_num        19

/* USART1, Start */
#define USART1_RXS_vect            _VECTOR(19)
#define USART1_RXS_vect_num        19

/* USART1, Rx Complete */
#define USART1_RX_vect            _VECTOR(20)
#define USART1_RX_vect_num        20

/* USART1, Rx Complete */
#define USART1_RXC_vect            _VECTOR(20)
#define USART1_RXC_vect_num        20

/* USART1 Data Register Empty */
#define USART1_UDRE_vect            _VECTOR(21)
#define USART1_UDRE_vect_num        21

/* USART1 Data Register Empty */
#define USART1_DRE_vect            _VECTOR(21)
#define USART1_DRE_vect_num        21

/* USART1, Tx Complete */
#define USART1_TX_vect            _VECTOR(22)
#define USART1_TX_vect_num        22

/* USART1, Tx Complete */
#define USART1_TXC_vect            _VECTOR(22)
#define USART1_TXC_vect_num        22

/* USI Start Condition */
#define USI_START_vect            _VECTOR(23)
#define USI_START_vect_num        23

/* USI Start Condition */
#define USI_STR_vect            _VECTOR(23)
#define USI_STR_vect_num        23

/* USI Overflow */
#define USI_OVERFLOW_vect            _VECTOR(24)
#define USI_OVERFLOW_vect_num        24

/* USI Overflow */
#define USI_OVF_vect            _VECTOR(24)
#define USI_OVF_vect_num        24

/* Two-wire Serial Interface */
#define TWI_SLAVE_vect            _VECTOR(25)
#define TWI_SLAVE_vect_num        25

/* Two-wire Serial Interface */
#define TWI_vect            _VECTOR(25)
#define TWI_vect_num        25

/* EEPROM Ready */
#define EE_RDY_vect            _VECTOR(26)
#define EE_RDY_vect_num        26

/* Touch Sensing */
#define QTRIP_vect            _VECTOR(27)
#define QTRIP_vect_num        27

#define _VECTORS_SIZE 112


/* Constants */

#define SPM_PAGESIZE 32
#define FLASHSTART   0x0000
#define FLASHEND     0x3FFF
#define RAMSTART     0x0100
#define RAMSIZE      1024
#define RAMEND       0x04FF
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
#define EFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x12


#endif /* #ifdef _AVR_ATTINY1634_H_INCLUDED */

