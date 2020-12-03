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


#ifndef _AVR_ATMEGA64HVE2_H_INCLUDED
#define _AVR_ATMEGA64HVE2_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom64hve2.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

/* Registers and associated bit numbers */

#define PINA    _SFR_IO8(0x00)
#define PINA1   1
#define PINA0   0

#define DDRA    _SFR_IO8(0x01)
#define DDRA1   1
// Inserted "DDA1" from "DDRA1" due to compatibility
#define DDA1    1
#define DDRA0   0
// Inserted "DDA0" from "DDRA0" due to compatibility
#define DDA0    0

#define PORTA   _SFR_IO8(0x02)
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

/* Reserved [0x06..0x14] */

#define TIFR0   _SFR_IO8(0x15)
#define TOV0    0
#define OCF0A   1
#define OCF0B   2
#define ICF0    3

#define TIFR1   _SFR_IO8(0x16)
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    3

/* Reserved [0x17..0x1A] */

#define PCIFR   _SFR_IO8(0x1B)
#define PCIF0   0
#define PCIF1   1

#define EIFR    _SFR_IO8(0x1C)
#define INTF0   0

#define EIMSK   _SFR_IO8(0x1D)
#define INT0    0

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

#define TCCR0A  _SFR_IO8(0x24)
#define WGM00   0
#define ICS0    3
#define ICES0   4
#define ICNC0   5
#define ICEN0   6
#define TCW0    7

#define TCCR0B  _SFR_IO8(0x25)
#define CS00    0
#define CS01    1
#define CS02    2

/* Combine TCNT0L and TCNT0H */
#define TCNT0   _SFR_IO16(0x26)

#define TCNT0L  _SFR_IO8(0x26)
#define TCNT0H  _SFR_IO8(0x27)

#define OCR0A   _SFR_IO8(0x28)

#define OCR0B   _SFR_IO8(0x29)

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

/* Reserved [0x2F..0x32] */

#define SMCR    _SFR_IO8(0x33)
#define SE      0
#define SM0     1
#define SM1     2
#define SM2     3

#define MCUSR   _SFR_IO8(0x34)
#define PORF    0
#define EXTRF   1
#define BODRF   2
#define WDRF    3
#define OCDRF   4

#define MCUCR   _SFR_IO8(0x35)
#define IVCE    0
#define IVSEL   1
#define PUD     4
#define CKOE    5

/* Reserved [0x36] */

#define SPMCSR  _SFR_IO8(0x37)
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define LBSET   3
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
#define CLKPCE  7

#define WUTCSR  _SFR_MEM8(0x62)
#define WUTP0   0
#define WUTP1   1
#define WUTP2   2
#define WUTE    3
#define WUTR    4
#define WUTIE   6
#define WUTIF   7

#define WDTCLR  _SFR_MEM8(0x63)
#define WDCLE   0
#define WDCL0   1
#define WDCL1   2

#define PRR0    _SFR_MEM8(0x64)
#define PRTIM0  0
#define PRTIM1  1
#define PRSPI   2
#define PRLIN   3

#define __AVR_HAVE_PRR0	((1<<PRTIM0)|(1<<PRTIM1)|(1<<PRSPI)|(1<<PRLIN))
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRLIN

/* Reserved [0x65] */

#define SOSCCALA _SFR_MEM8(0x66)

#define SOSCCALB _SFR_MEM8(0x67)

#define PCICR   _SFR_MEM8(0x68)
#define PCIE0   0
#define PCIE1   1

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1

/* Reserved [0x6A] */

#define PCMSK0  _SFR_MEM8(0x6B)

#define PCMSK1  _SFR_MEM8(0x6C)

/* Reserved [0x6D] */

#define TIMSK0  _SFR_MEM8(0x6E)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2
#define ICIE0   3

#define TIMSK1  _SFR_MEM8(0x6F)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   3

/* Reserved [0x70..0x7D] */

#define DIDR0   _SFR_MEM8(0x7E)
#define PA0DID  0
#define PA1DID  1

/* Reserved [0x7F] */

#define TCCR1A  _SFR_MEM8(0x80)
#define WGM10   0
#define ICS1    3
#define ICES1   4
#define ICNC1   5
#define ICEN1   6
#define TCW1    7

#define TCCR1B  _SFR_MEM8(0x81)
#define CS10    0
#define CS11    1
#define CS12    2

/* Reserved [0x82..0x83] */

/* Combine TCNT1L and TCNT1H */
#define TCNT1   _SFR_MEM16(0x84)

#define TCNT1L  _SFR_MEM8(0x84)
#define TCNT1H  _SFR_MEM8(0x85)

/* Reserved [0x86..0x87] */

#define OCR1A   _SFR_MEM8(0x88)

#define OCR1B   _SFR_MEM8(0x89)

/* Reserved [0x8A..0xBF] */

#define LINCR   _SFR_MEM8(0xC0)
#define LCMD0   0
#define LCMD1   1
#define LCMD2   2
#define LENA    3
#define LCONF0  4
#define LCONF1  5
#define LIN13   6
#define LSWRES  7

#define LINSIR  _SFR_MEM8(0xC1)
#define LRXOK   0
#define LTXOK   1
#define LIDOK   2
#define LERR    3
#define LBUSY   4
#define LIDST0  5
#define LIDST1  6
#define LIDST2  7

#define LINENIR _SFR_MEM8(0xC2)
#define LENRXOK 0
#define LENTXOK 1
#define LENIDOK 2
#define LENERR  3

#define LINERR  _SFR_MEM8(0xC3)
#define LBERR   0
#define LCERR   1
#define LPERR   2
#define LSERR   3
#define LFERR   4
#define LOVERR  5
#define LTOERR  6
#define LABORT  7

#define LINBTR  _SFR_MEM8(0xC4)
#define LBT0    0
#define LBT1    1
#define LBT2    2
#define LBT3    3
#define LBT4    4
#define LBT5    5
#define LDISR   7

#define LINBRRL _SFR_MEM8(0xC5)
#define LDIV0   0
#define LDIV1   1
#define LDIV2   2
#define LDIV3   3
#define LDIV4   4
#define LDIV5   5
#define LDIV6   6
#define LDIV7   7

#define LINBRRH _SFR_MEM8(0xC6)
#define LDIV8   0
#define LDIV9   1
#define LDIV10  2
#define LDIV11  3

#define LINDLR  _SFR_MEM8(0xC7)
#define LRXDL0  0
#define LRXDL1  1
#define LRXDL2  2
#define LRXDL3  3
#define LTXDL0  4
#define LTXDL1  5
#define LTXDL2  6
#define LTXDL3  7

#define LINIDR  _SFR_MEM8(0xC8)
#define LID0    0
#define LID1    1
#define LID2    2
#define LID3    3
#define LID4    4
#define LID5    5
#define LP0     6
#define LP1     7

#define LINSEL  _SFR_MEM8(0xC9)
#define LINDX0  0
#define LINDX1  1
#define LINDX2  2
#define LAINC   3

#define LINDAT  _SFR_MEM8(0xCA)
#define LDATA0  0
#define LDATA1  1
#define LDATA2  2
#define LDATA3  3
#define LDATA4  4
#define LDATA5  5
#define LDATA6  6
#define LDATA7  7

/* Reserved [0xCB..0xD0] */

#define BGCSRA  _SFR_MEM8(0xD1)
#define BGSC0   0
#define BGSC1   1
#define BGSC2   2

#define BGCRB   _SFR_MEM8(0xD2)
#define BGCL0   0
#define BGCL1   1
#define BGCL2   2
#define BGCL3   3
#define BGCL4   4
#define BGCL5   5
#define BGCL6   6
#define BGCL7   7

#define BGCRA   _SFR_MEM8(0xD3)
#define BGCN0   0
#define BGCN1   1
#define BGCN2   2
#define BGCN3   3
#define BGCN4   4
#define BGCN5   5
#define BGCN6   6
#define BGCN7   7

#define BGLR    _SFR_MEM8(0xD4)
#define BGPL    0
#define BGPLE   1

/* Reserved [0xD5..0xD7] */

#define PLLCSR  _SFR_MEM8(0xD8)
#define PLLCIE  0
#define PLLCIF  1
#define LOCK    4
#define SWEN    5

/* Reserved [0xD9..0xDB] */

#define PBOV    _SFR_MEM8(0xDC)
#define PBOE0   0
#define PBOE3   3
#define PBOVCE  7

/* Reserved [0xDD..0xDF] */

#define ADSCSRA _SFR_MEM8(0xE0)
#define SCMD0   0
#define SCMD1   1
#define SBSY    2

#define ADSCSRB _SFR_MEM8(0xE1)
#define CADICRB 0
#define CADACRB 1
#define CADICPS 2
#define VADICRB 4
#define VADACRB 5
#define VADICPS 6

#define ADCRA   _SFR_MEM8(0xE2)
#define CKSEL   0
#define ADCMS0  1
#define ADCMS1  2
#define ADPSEL  3

#define ADCRB   _SFR_MEM8(0xE3)
#define ADADES0 0
#define ADADES1 1
#define ADADES2 2
#define ADIDES0 3
#define ADIDES1 4

#define ADCRC   _SFR_MEM8(0xE4)
#define CADRCT0 0
#define CADRCT1 1
#define CADRCT2 2
#define CADRCT3 3
#define CADRCM0 4
#define CADRCM1 5
#define CADEN   7

#define ADCRD   _SFR_MEM8(0xE5)
#define CADDSEL 0
#define CADPDM0 1
#define CADPDM1 2
#define CADG0   3
#define CADG1   4
#define CADG2   5

#define ADCRE   _SFR_MEM8(0xE6)
#define VADMUX0 0
#define VADMUX1 1
#define VADMUX2 2
#define VADPDM0 3
#define VADPDM1 4
#define VADREFS 5
#define VADEN   7

#define ADIFR   _SFR_MEM8(0xE7)
#define CADICIF 0
#define CADACIF 1
#define CADRCIF 2
#define VADICIF 4
#define VADACIF 5

#define ADIMR   _SFR_MEM8(0xE8)
#define CADICIE 0
#define CADACIE 1
#define CADRCIE 2
#define VADICIE 4
#define VADACIE 5

/* Combine CADRCLL and CADRCLH */
#define CADRCL  _SFR_MEM16(0xE9)

#define CADRCLL _SFR_MEM8(0xE9)
#define CADRCLH _SFR_MEM8(0xEA)

/* Combine CADICL and CADICH */
#define CADIC   _SFR_MEM16(0xEB)

#define CADICL  _SFR_MEM8(0xEB)
#define CADICH  _SFR_MEM8(0xEC)

#define CADAC0  _SFR_MEM8(0xED)

#define CADAC1  _SFR_MEM8(0xEE)

#define CADAC2  _SFR_MEM8(0xEF)

#define CADAC3  _SFR_MEM8(0xF0)

/* Combine VADICL and VADICH */
#define VADIC   _SFR_MEM16(0xF1)

#define VADICL  _SFR_MEM8(0xF1)
#define VADICH  _SFR_MEM8(0xF2)

#define VADAC0  _SFR_MEM8(0xF3)

#define VADAC1  _SFR_MEM8(0xF4)

#define VADAC2  _SFR_MEM8(0xF5)

#define VADAC3  _SFR_MEM8(0xF6)



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt 0 */
#define INT0_vect            _VECTOR(1)
#define INT0_vect_num        1

/* Pin Change Interrupt 0 */
#define PCINT0_vect            _VECTOR(2)
#define PCINT0_vect_num        2

/* Pin Change Interrupt 1 */
#define PCINT1_vect            _VECTOR(3)
#define PCINT1_vect_num        3

/* Watchdog Timeout Interrupt */
#define WDT_vect            _VECTOR(4)
#define WDT_vect_num        4

/* Wakeup Timer Overflow */
#define WAKEUP_vect            _VECTOR(5)
#define WAKEUP_vect_num        5

/* Timer 1 Input capture */
#define TIMER1_IC_vect            _VECTOR(6)
#define TIMER1_IC_vect_num        6

/* Timer 1 Compare Match A */
#define TIMER1_COMPA_vect            _VECTOR(7)
#define TIMER1_COMPA_vect_num        7

/* Timer 1 Compare Match B */
#define TIMER1_COMPB_vect            _VECTOR(8)
#define TIMER1_COMPB_vect_num        8

/* Timer 1 overflow */
#define TIMER1_OVF_vect            _VECTOR(9)
#define TIMER1_OVF_vect_num        9

/* Timer 0 Input Capture */
#define TIMER0_IC_vect            _VECTOR(10)
#define TIMER0_IC_vect_num        10

/* Timer 0 Comapre Match A */
#define TIMER0_COMPA_vect            _VECTOR(11)
#define TIMER0_COMPA_vect_num        11

/* Timer 0 Compare Match B */
#define TIMER0_COMPB_vect            _VECTOR(12)
#define TIMER0_COMPB_vect_num        12

/* Timer 0 Overflow */
#define TIMER0_OVF_vect            _VECTOR(13)
#define TIMER0_OVF_vect_num        13

/* LIN Status Interrupt */
#define LIN_STATUS_vect            _VECTOR(14)
#define LIN_STATUS_vect_num        14

/* LIN Error Interrupt */
#define LIN_ERROR_vect            _VECTOR(15)
#define LIN_ERROR_vect_num        15

/* SPI Serial transfer complete */
#define SPI_STC_vect            _VECTOR(16)
#define SPI_STC_vect_num        16

/* Voltage ADC Instantaneous Conversion Complete */
#define VADC_CONV_vect            _VECTOR(17)
#define VADC_CONV_vect_num        17

/* Voltage ADC Accumulated Conversion Complete */
#define VADC_ACC_vect            _VECTOR(18)
#define VADC_ACC_vect_num        18

/* C-ADC Instantaneous Conversion Complete */
#define CADC_CONV_vect            _VECTOR(19)
#define CADC_CONV_vect_num        19

/* C-ADC Regular Current */
#define CADC_REG_CUR_vect            _VECTOR(20)
#define CADC_REG_CUR_vect_num        20

/* C-ADC Accumulated Conversion Complete */
#define CADC_ACC_vect            _VECTOR(21)
#define CADC_ACC_vect_num        21

/* EEPROM Ready */
#define EE_READY_vect            _VECTOR(22)
#define EE_READY_vect_num        22

/* SPM Ready */
#define SPM_vect            _VECTOR(23)
#define SPM_vect_num        23

/* PLL Lock Change Interrupt */
#define PLL_vect            _VECTOR(24)
#define PLL_vect_num        24

#define _VECTORS_SIZE 100


/* Constants */

#define SPM_PAGESIZE 128
#define FLASHSTART   0x0000
#define FLASHEND     0xFFFF
#define RAMSTART     0x0100
#define RAMSIZE      4096
#define RAMEND       0x10FF
#define E2START     0
#define E2SIZE      1024
#define E2PAGESIZE  4
#define E2END       0x03FF
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 2

/* Low Fuse Byte */
#define FUSE_OSCSEL0     (unsigned char)~_BV(0)
#define FUSE_SUT0        (unsigned char)~_BV(1)
#define FUSE_SUT1        (unsigned char)~_BV(2)
#define FUSE_CKDIV8      (unsigned char)~_BV(3)
#define FUSE_BODEN       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_EESAVE      (unsigned char)~_BV(6)
#define FUSE_WDTON       (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_CKDIV8 & FUSE_SPIEN)


/* High Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_DWEN        (unsigned char)~_BV(3)
#define HFUSE_DEFAULT    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x96
#define SIGNATURE_2 0x10


#endif /* #ifdef _AVR_ATMEGA64HVE2_H_INCLUDED */

