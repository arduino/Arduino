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


#ifndef _AVR_ATTINY102_H_INCLUDED
#define _AVR_ATTINY102_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotn102.h"
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
#define PUEA7   7
#define PUEA6   6
#define PUEA5   5
#define PUEA4   4
#define PUEA3   3
#define PUEA2   2
#define PUEA1   1
#define PUEA0   0

#define PINB    _SFR_IO8(0x04)
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB    _SFR_IO8(0x05)
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
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

#define PUEB    _SFR_IO8(0x07)
#define PUEB3   3
#define PUEB2   2
#define PUEB1   1
#define PUEB0   0

#define UDR     _SFR_IO8(0x08)

/* Combine UBRRL and UBRRH */
#define UBRR    _SFR_IO16(0x09)

#define UBRRL   _SFR_IO8(0x09)
#define UBRRH   _SFR_IO8(0x0A)

#define UCSRD   _SFR_IO8(0x0B)
#define SFDE    5
#define RXS     6
#define RXSIE   7

#define UCSRC   _SFR_IO8(0x0C)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL0  6
#define UMSEL1  7

#define UCSRB   _SFR_IO8(0x0D)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRA   _SFR_IO8(0x0E)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define PCMSK0  _SFR_IO8(0x0F)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  _SFR_IO8(0x10)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3

#define PCIFR   _SFR_IO8(0x11)
#define PCIF0   0
#define PCIF1   1

#define PCICR   _SFR_IO8(0x12)
#define PCIE0   0
#define PCIE1   1

#define EIMSK   _SFR_IO8(0x13)
#define INT0    0

#define EIFR    _SFR_IO8(0x14)
#define INTF0   0

#define EICRA   _SFR_IO8(0x15)
#define ISC00   0
#define ISC01   1

#define PORTCR  _SFR_IO8(0x16)
#define BBMA    0
#define BBMB    1

#define DIDR0   _SFR_IO8(0x17)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7
#define AIN0D   0
#define AIN1D   1

/* Reserved [0x18] */

#define ADCL    _SFR_IO8(0x19)

#define ADCH    _SFR_IO8(0x1A)

#define ADMUX   _SFR_IO8(0x1B)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define REFS0   6
#define REFS1   7

#define ADCSRB  _SFR_IO8(0x1C)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADLAR   7

#define ADCSRA  _SFR_IO8(0x1D)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ACSRB   _SFR_IO8(0x1E)
#define ACPMUX  0
#define ACOE    1

#define ACSRA   _SFR_IO8(0x1F)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

/* Reserved [0x20..0x21] */

/* Combine ICR0L and ICR0H */
#define ICR0    _SFR_IO16(0x22)

#define ICR0L   _SFR_IO8(0x22)
#define ICR0H   _SFR_IO8(0x23)

/* Combine OCR0BL and OCR0BH */
#define OCR0B   _SFR_IO16(0x24)

#define OCR0BL  _SFR_IO8(0x24)
#define OCR0BH  _SFR_IO8(0x25)

/* Combine OCR0AL and OCR0AH */
#define OCR0A   _SFR_IO16(0x26)

#define OCR0AL  _SFR_IO8(0x26)
#define OCR0AH  _SFR_IO8(0x27)

/* Combine TCNT0L and TCNT0H */
#define TCNT0   _SFR_IO16(0x28)

#define TCNT0L  _SFR_IO8(0x28)
#define TCNT0H  _SFR_IO8(0x29)

#define TIFR0   _SFR_IO8(0x2A)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2
#define ICF0    5

#define TIMSK0  _SFR_IO8(0x2B)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2
#define ICIE0   5

#define TCCR0C  _SFR_IO8(0x2C)
#define FOC0B   6
#define FOC0A   7

#define TCCR0B  _SFR_IO8(0x2D)
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define WGM03   4
#define ICES0   6
#define ICNC0   7

#define TCCR0A  _SFR_IO8(0x2E)
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

#define GTCCR   _SFR_IO8(0x2F)
#define PSR     0
#define REMAP   1
#define TSM     7

/* Reserved [0x30] */

#define WDTCSR  _SFR_IO8(0x31)
#define WDE     3
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define NVMCSR  _SFR_IO8(0x32)
#define NVMBSY  7

#define NVMCMD  _SFR_IO8(0x33)

#define VLMCSR  _SFR_IO8(0x34)
#define VLM0    0
#define VLM1    1
#define VLM2    2
#define VLMIE   6
#define VLMF    7

#define PRR     _SFR_IO8(0x35)
#define PRTIM0  0
#define PRADC   1
#define PRUSART 2

#define __AVR_HAVE_PRR	((1<<PRTIM0)|(1<<PRADC)|(1<<PRUSART))
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSART

#define CLKPSR  _SFR_IO8(0x36)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3

#define CLKMSR  _SFR_IO8(0x37)
#define CLKMS0  0
#define CLKMS1  1

/* Reserved [0x38] */

#define OSCCAL  _SFR_IO8(0x39)

#define SMCR    _SFR_IO8(0x3A)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define RSTFLR  _SFR_IO8(0x3B)
#define PORF    0
#define EXTRF   1
#define WDRF    3

#define CCP     _SFR_IO8(0x3C)
#define CCP0    0
#define CCP1    1
#define CCP2    2
#define CCP3    3
#define CCP4    4
#define CCP5    5
#define CCP6    6
#define CCP7    7

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_STANDBY (0x04<<1)

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

/* Timer/Counter0 Input Capture */
#define TIM0_CAPT_vect            _VECTOR(4)
#define TIM0_CAPT_vect_num        4

/* Timer/Counter0 Overflow */
#define TIM0_OVF_vect            _VECTOR(5)
#define TIM0_OVF_vect_num        5

/* Timer/Counter Compare Match A */
#define TIM0_COMPA_vect            _VECTOR(6)
#define TIM0_COMPA_vect_num        6

/* Timer/Counter Compare Match B */
#define TIM0_COMPB_vect            _VECTOR(7)
#define TIM0_COMPB_vect_num        7

/* Analog Comparator */
#define ANA_COMP_vect            _VECTOR(8)
#define ANA_COMP_vect_num        8

/* Watchdog Time-out */
#define WDT_vect            _VECTOR(9)
#define WDT_vect_num        9

/* Vcc Voltage Level Monitor */
#define VLM_vect            _VECTOR(10)
#define VLM_vect_num        10

/* ADC Conversion complete */
#define ADC_vect            _VECTOR(11)
#define ADC_vect_num        11

/* USART RX Start */
#define USART_RXS_vect            _VECTOR(12)
#define USART_RXS_vect_num        12

/* USART RX Complete */
#define USART_RXC_vect            _VECTOR(13)
#define USART_RXC_vect_num        13

/* USART Data register empty */
#define USART_DRE_vect            _VECTOR(14)
#define USART_DRE_vect_num        14

/* USART Tx Complete */
#define USART_TXC_vect            _VECTOR(15)
#define USART_TXC_vect_num        15

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define _VECTORS_SIZE 32
#else
#  define _VECTORS_SIZE 32U
#endif


/* Constants */

#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define SPM_PAGESIZE 128
#  define FLASHSTART   0x0000
#  define FLASHEND     0x03FF
#else
#  define SPM_PAGESIZE 128U
#  define FLASHSTART   0x0000U
#  define FLASHEND     0x03FFU
#endif
#if (defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
#  define RAMSTART     0x0040
#  define RAMSIZE      32
#  define RAMEND       0x005F
#else
#  define RAMSTART     0x0040U
#  define RAMSIZE      32U
#  define RAMEND       0x005FU
#endif
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 1

/* Fuse Byte */
#define FUSE_RSTDISBL    (unsigned char)~_BV(0)
#define FUSE_WDTON       (unsigned char)~_BV(1)
#define FUSE_CKOUT       (unsigned char)~_BV(2)
#define FUSE_SELFPROGEN  (unsigned char)~_BV(3)
#define LFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x90
#define SIGNATURE_2 0x0C



/* Properties */
#define CCP_IOREG_gc 0xD8 	 // IOREG signature for Change Protect
#define   CCP_SPM_gc 0xE7 	 // SPM signature for Change Protect

#endif /* #ifdef _AVR_ATTINY102_H_INCLUDED */

