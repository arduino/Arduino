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


#ifndef _AVR_ATA5272_H_INCLUDED
#define _AVR_ATA5272_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioa5272.h"
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

/* Reserved [0x06..0x11] */

#define PORTCR  _SFR_IO8(0x12)
#define PUDA    0
#define PUDB    1
#define BBMA    4
#define BBMB    5

/* Reserved [0x13..0x14] */

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

/* Reserved [0x17..0x1A] */

#define PCIFR   _SFR_IO8(0x1B)
#define PCIF0   0
#define PCIF1   1

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
#define PSR1    0
#define PSR0    1
#define TSM     7

/* Reserved [0x24] */

#define TCCR0A  _SFR_IO8(0x25)
#define WGM00   0
#define WGM01   1
#define COM0A0  6
#define COM0A1  7

#define TCCR0B  _SFR_IO8(0x26)
#define CS00    0
#define CS01    1
#define CS02    2
#define FOC0A   7

#define TCNT2   _SFR_IO8(0x27)

#define OCR0A   _SFR_IO8(0x28)

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

/* Reserved [0x2F] */

#define ACSR    _SFR_IO8(0x30)
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACIRS   6
#define ACD     7

#define DWDR    _SFR_IO8(0x31)

/* Reserved [0x32] */

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
#define PUD     4
#define BODSE   5
#define BODS    6

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RFLB    3
#define CTPB    4
#define SIGRD   5
#define RWWSB   6

/* Reserved [0x38..0x3C] */

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCR   _SFR_MEM8(0x60)
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

#define CLKCSR  _SFR_MEM8(0x62)
#define CLKC0   0
#define CLKC1   1
#define CLKC2   2
#define CLKC3   3
#define CLKRDY  4
#define CLKCCE  7

#define CLKSELR _SFR_MEM8(0x63)
#define CSEL0   0
#define CSEL1   1
#define CSEL2   2
#define CSEL3   3
#define CSUT0   4
#define CSUT1   5
#define COUT    6

#define PRR     _SFR_MEM8(0x64)
#define PRADC   0
#define PRUSI   1
#define PRTIM0  2
#define PRTIM1  3
#define PRSPI   4
#define PRLIN   5

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRLIN))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSI
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1
#define __AVR_HAVE_PRR_PRSPI
#define __AVR_HAVE_PRR_PRLIN

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

/* Reserved [0x67] */

#define PCICR   _SFR_MEM8(0x68)
#define PCIE0   0
#define PCIE1   1

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

/* Reserved [0x6D] */

#define TIMSK0  _SFR_MEM8(0x6E)
#define TOIE0   0
#define OCIE0A  1

#define TIMSK1  _SFR_MEM8(0x6F)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   5

/* Reserved [0x70..0x76] */

#define AMISCR  _SFR_MEM8(0x77)
#define XREFEN  1
#define AREFEN  2
#define ISRCEN  0

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
#define BIN     7
#define ACIR0   4
#define ACIR1   5
#define ACME    6

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
#define ADC8D   0
#define ADC9D   1
#define ADC10D  2

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

#define TCCR1D  _SFR_MEM8(0x83)
#define OC1AU   0
#define OC1AV   1
#define OC1AW   2
#define OC1AX   3
#define OC1BU   4
#define OC1BV   5
#define OC1BW   6
#define OC1BX   7

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

/* Reserved [0x8C..0xB5] */

#define ASSR    _SFR_MEM8(0xB6)
#define TCR0BUB 0
#define TCR0AUB 1
#define OCR0AUB 3
#define TCN0UB  4
#define AS0     5
#define EXCLK   6

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

#define USIBR   _SFR_MEM8(0xBB)

#define USIPP   _SFR_MEM8(0xBC)

/* Reserved [0xBD..0xC7] */

#define LINCR   _SFR_MEM8(0xC8)
#define LCMD0   0
#define LCMD1   1
#define LCMD2   2
#define LENA    3
#define LCONF0  4
#define LCONF1  5
#define LIN13   6
#define LSWRES  7

#define LINSIR  _SFR_MEM8(0xC9)
#define LRXOK   0
#define LTXOK   1
#define LIDOK   2
#define LERR    3
#define LBUSY   4
#define LIDST0  5
#define LIDST1  6
#define LIDST2  7

#define LINENIR _SFR_MEM8(0xCA)
#define LENRXOK 0
#define LENTXOK 1
#define LENIDOK 2
#define LENERR  3

#define LINERR  _SFR_MEM8(0xCB)
#define LBERR   0
#define LCERR   1
#define LPERR   2
#define LSERR   3
#define LFERR   4
#define LOVERR  5
#define LTOERR  6
#define LABORT  7

#define LINBTR  _SFR_MEM8(0xCC)
#define LBT0    0
#define LBT1    1
#define LBT2    2
#define LBT3    3
#define LBT4    4
#define LBT5    5
#define LDISR   7

#define LINBRRL _SFR_MEM8(0xCD)
#define LDIV0   0
#define LDIV1   1
#define LDIV2   2
#define LDIV3   3
#define LDIV4   4
#define LDIV5   5
#define LDIV6   6
#define LDIV7   7

#define LINBRRH _SFR_MEM8(0xCE)
#define LDIV8   0
#define LDIV9   1
#define LDIV10  2
#define LDIV11  3

#define LINDLR  _SFR_MEM8(0xCF)
#define LRXDL0  0
#define LRXDL1  1
#define LRXDL2  2
#define LRXDL3  3
#define LTXDL0  4
#define LTXDL1  5
#define LTXDL2  6
#define LTXDL3  7

#define LINIDR  _SFR_MEM8(0xD0)
#define LID0    0
#define LID1    1
#define LID2    2
#define LID3    3
#define LID4    4
#define LID5    5
#define LP0     6
#define LP1     7

#define LINSEL  _SFR_MEM8(0xD1)
#define LINDX0  0
#define LINDX1  1
#define LINDX2  2
#define LAINC   3

#define LINDAT  _SFR_MEM8(0xD2)
#define LDATA0  0
#define LDATA1  1
#define LDATA2  2
#define LDATA3  3
#define LDATA4  4
#define LDATA5  5
#define LDATA6  6
#define LDATA7  7



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)

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

/* Watchdog Time-Out Interrupt */
#define WDT_vect            _VECTOR(5)
#define WDT_vect_num        5

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect            _VECTOR(6)
#define TIMER1_CAPT_vect_num        6

/* Timer/Counter1 Compare Match 1A */
#define TIMER1_COMPA_vect            _VECTOR(7)
#define TIMER1_COMPA_vect_num        7

/* Timer/Counter1 Compare Match 1B */
#define TIMER1_COMPB_vect            _VECTOR(8)
#define TIMER1_COMPB_vect_num        8

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect            _VECTOR(9)
#define TIMER1_OVF_vect_num        9

/* Timer/Counter0 Compare Match 0A */
#define TIMER0_COMPA_vect            _VECTOR(10)
#define TIMER0_COMPA_vect_num        10

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(11)
#define TIMER0_OVF_vect_num        11

/* LIN Transfer Complete */
#define LIN_TC_vect            _VECTOR(12)
#define LIN_TC_vect_num        12

/* LIN Error */
#define LIN_ERR_vect            _VECTOR(13)
#define LIN_ERR_vect_num        13

/* SPI Serial Transfer Complete */
#define SPI_STC_vect            _VECTOR(14)
#define SPI_STC_vect_num        14

/* ADC Conversion Complete */
#define ADC_vect            _VECTOR(15)
#define ADC_vect_num        15

/* EEPROM Ready */
#define EE_RDY_vect            _VECTOR(16)
#define EE_RDY_vect_num        16

/* USI Overflow */
#define USI_OVF_vect            _VECTOR(19)
#define USI_OVF_vect_num        19

/* Analog Comparator */
#define ANA_COMP_vect            _VECTOR(34)
#define ANA_COMP_vect_num        34

/* USI Start */
#define USI_START_vect            _VECTOR(36)
#define USI_START_vect_num        36

#define _VECTORS_SIZE 74


/* Constants */

#define SPM_PAGESIZE 128
#define FLASHSTART   0x0000
#define FLASHEND     0x1FFF
#define RAMSTART     0x0100
#define RAMSIZE      512
#define RAMEND       0x02FF
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
#define EFUSE_DEFAULT    (0xFF)



/* Lock Bits */
#define __LOCK_BITS_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x87


#endif /* #ifdef _AVR_ATA5272_H_INCLUDED */

