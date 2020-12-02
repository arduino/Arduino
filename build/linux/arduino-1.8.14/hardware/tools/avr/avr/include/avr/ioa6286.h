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


#ifndef _AVR_ATA6286_H_INCLUDED
#define _AVR_ATA6286_H_INCLUDED


#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "ioa6286.h"
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
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC    _SFR_IO8(0x07)
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

/* Reserved [0x0C..0x0E] */

#define CMCR    _SFR_IO8(0x0F)
#define CMM0    0
#define CMM1    1
#define SRCD    2
#define CMONEN  3
#define CCS     4
#define ECINS   5
#define CMCCE   7

#define CMSR    _SFR_IO8(0x10)
#define ECF     0

#define T2CRA   _SFR_IO8(0x11)
#define T2OTM   0
#define T2CTM   1
#define T2CR    2
#define T2CRM   3
#define T2ICS   5
#define T2TS    6
#define T2E     7

#define T2CRB   _SFR_IO8(0x12)
#define T2SCE   0

/* Reserved [0x13] */

#define T3CRA   _SFR_IO8(0x14)
#define T3AC    0
#define T3SCE   1
#define T3CR    2
#define T3TS    6
#define T3E     7

/* Reserved [0x15] */

#define VMCSR   _SFR_IO8(0x16)
#define VMEN    0
#define VMLS0   1
#define VMLS1   2
#define VMLS2   3
#define VMIM    4
#define VMF     5
#define BODPD   6
#define BODLS   7

#define PCIFR   _SFR_IO8(0x17)
#define PCIF0   0
#define PCIF1   1
#define PCIF2   2

#define LFFR    _SFR_IO8(0x18)
#define LFWPF   0
#define LFBF    1
#define LFEDF   2
#define LFRF    3

#define SSFR    _SFR_IO8(0x19)
#define MSENF   0
#define MSENO   1

#define T10IFR  _SFR_IO8(0x1A)
#define T0F     0
#define T1F     1

#define T2IFR   _SFR_IO8(0x1B)
#define T2OFF   0
#define T2COF   1
#define T2ICF   2
#define T2RXF   3
#define T2TXF   4
#define T2TCF   5

#define T3IFR   _SFR_IO8(0x1C)
#define T3OFF   0
#define T3COAF  1
#define T3COBF  2
#define T3ICF   3

#define EIFR    _SFR_IO8(0x1D)
#define INTF0   0
#define INTF1   1

#define GPIOR0  _SFR_IO8(0x1E)

#define EECR    _SFR_IO8(0x1F)
#define EERE    0
#define EEWE    1
#define EEMWE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

#define EEDR    _SFR_IO8(0x20)

/* Combine EEARL and EEARH */
#define EEAR    _SFR_IO16(0x21)

#define EEARL   _SFR_IO8(0x21)
#define EEARH   _SFR_IO8(0x22)

#define PCICR   _SFR_IO8(0x23)
#define PCIE0   0
#define PCIE1   1
#define PCIE2   2

#define EIMSK   _SFR_IO8(0x24)
#define INT0    0
#define INT1    1

/* Reserved [0x25..0x26] */

#define SVCR    _SFR_IO8(0x27)

#define SCR     _SFR_IO8(0x28)
#define SMS     0
#define SEN0    1
#define SEN1    2
#define SMEN    3

#define SCCR    _SFR_IO8(0x29)
#define SRCC0   0
#define SRCC1   1
#define SCCS0   2
#define SCCS1   3
#define SCCS2   4

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

#define T2MDR   _SFR_IO8(0x2F)

#define LFRR    _SFR_IO8(0x30)

/* Reserved [0x31] */

#define LFCDR   _SFR_IO8(0x32)
#define LFDO    0
#define LFRST   6
#define LFSCE   7

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
#define TSRF    5

#define MCUCR   _SFR_IO8(0x35)
#define IVCE    0
#define IVSEL   1
#define PUD     4

#define LFRB    _SFR_IO8(0x36)

#define SPMCSR  _SFR_IO8(0x37)
#define SELFPRGEN 0
#define PGERS   1
#define PGWRT   2
#define BLBSET  3
#define RWWSRE  4
#define RWWSB   6
#define SPMIE   7

#define T1CR    _SFR_IO8(0x38)
#define T1PS0   0
#define T1PS1   1
#define T1PS2   2
#define T1CS0   3
#define T1CS1   4
#define T1CS2   5
#define T1IE    7

#define T0CR    _SFR_IO8(0x39)
#define T0PAS0  0
#define T0PAS1  1
#define T0PAS2  2
#define T0IE    3
#define T0PR    4
#define T0PBS0  5
#define T0PBS1  6
#define T0PBS2  7

/* Reserved [0x3A] */

#define CMIMR   _SFR_IO8(0x3B)
#define ECIE    0

#define CLKPR   _SFR_IO8(0x3C)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLTPS0  3
#define CLTPS1  4
#define CLTPS2  5
#define CLPCE   7

/* SP [0x3D..0x3E] */

/* SREG [0x3F] */

#define WDTCR   _SFR_MEM8(0x60)
#define WDPS0   0
#define WDPS1   1
#define WDPS2   2
#define WDE     3
#define WDCE    4

#define SIMSK   _SFR_MEM8(0x61)
#define MSIE    0

/* Reserved [0x62..0x63] */

#define TSCR    _SFR_MEM8(0x64)
#define TSSD    0

#define SRCCAL  _SFR_MEM8(0x65)

#define FRCCAL  _SFR_MEM8(0x66)

#define MSVCAL  _SFR_MEM8(0x67)

/* Reserved [0x68] */

#define EICRA   _SFR_MEM8(0x69)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

#define PCMSK0  _SFR_MEM8(0x6A)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  _SFR_MEM8(0x6B)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2

#define PCMSK2  _SFR_MEM8(0x6C)
#define PCINT16 0
#define PCINT17 1
#define PCINT18 2
#define PCINT19 3
#define PCINT20 4
#define PCINT21 5
#define PCINT22 6
#define PCINT23 7

/* Reserved [0x6D] */

#define T2ICRL  _SFR_MEM8(0x6E)

#define T2ICR   _SFR_MEM8(0x6F)

/* Combine T2CORL and T2CORH */
#define T2COR   _SFR_MEM16(0x70)

#define T2CORL  _SFR_MEM8(0x70)
#define T2CORH  _SFR_MEM8(0x71)

#define T2MRA   _SFR_MEM8(0x72)
#define T2CS0   0
#define T2CS1   1
#define T2CS2   2
#define T2CE0   3
#define T2CE1   4
#define T2CNC   5
#define T2TP0   6
#define T2TP1   7

#define T2MRB   _SFR_MEM8(0x73)
#define T2M0    0
#define T2M1    1
#define T2M2    2
#define T2M3    3
#define T2TOP   4
#define T2CPOL  6
#define T2SSIE  7

#define T2IMR   _SFR_MEM8(0x74)
#define T2OIM   0
#define T2CIM   1
#define T2CPIM  2
#define T2RXIM  3
#define T2TXIM  4
#define T2TCIM  5

/* Reserved [0x75] */

/* Combine T3ICRL and T3ICRH */
#define T3ICR   _SFR_MEM16(0x76)

#define T3ICRL  _SFR_MEM8(0x76)
#define T3ICRH  _SFR_MEM8(0x77)

/* Combine T3CORAL and T3CORAH */
#define T3CORA  _SFR_MEM16(0x78)

#define T3CORAL _SFR_MEM8(0x78)
#define T3CORAH _SFR_MEM8(0x79)

/* Combine T3CORBL and T3CORBH */
#define T3CORB  _SFR_MEM16(0x7A)

#define T3CORBL _SFR_MEM8(0x7A)
#define T3CORBH _SFR_MEM8(0x7B)

#define T3MRA   _SFR_MEM8(0x7C)
#define T3CS0   0
#define T3CS1   1
#define T3CS2   2
#define T3CE0   3
#define T3CE1   4
#define T3CNC   5
#define T3ICS0  6
#define T3ICS1  7

#define T3MRB   _SFR_MEM8(0x7D)
#define T3M0    0
#define T3M1    1
#define T3M2    2
#define T3TOP   4

#define T3CRB   _SFR_MEM8(0x7E)
#define T3CTMA  0
#define T3SAMA  1
#define T3CRMA  2
#define T3CTMB  3
#define T3SAMB  4
#define T3CRMB  5
#define T3CPRM  6

#define T3IMR   _SFR_MEM8(0x7F)
#define T3OIM   0
#define T3CAIM  1
#define T3CBIM  2
#define T3CPIM  3

/* Reserved [0x80] */

#define LFIMR   _SFR_MEM8(0x81)
#define LFWIM   0
#define LFBIM   1
#define LFEIM   2

#define LFRCR   _SFR_MEM8(0x82)
#define LFEN    0
#define LFBM    1
#define LFWM0   2
#define LFWM1   3
#define LFRSS   4
#define LFCS0   5
#define LFCS1   6
#define LFCS2   7

#define LFHCR   _SFR_MEM8(0x83)

/* Combine LFIDCL and LFIDCH */
#define LFIDC   _SFR_MEM16(0x84)

#define LFIDCL  _SFR_MEM8(0x84)
#define LFIDCH  _SFR_MEM8(0x85)

/* Combine LFCALL and LFCALH */
#define LFCAL   _SFR_MEM16(0x86)

#define LFCALL  _SFR_MEM8(0x86)
#define LFCALH  _SFR_MEM8(0x87)



/* Values and associated defines */


#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_SENSOR_NOISE_REDUCTION (0x01<<1)
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

/* Voltage Monitor Interrupt */
#define INTVM_vect            _VECTOR(6)
#define INTVM_vect_num        6

/* Sensor Interface Interrupt */
#define SENINT_vect            _VECTOR(7)
#define SENINT_vect_num        7

/* Timer0 Interval Interrupt */
#define INTT0_vect            _VECTOR(8)
#define INTT0_vect_num        8

/* LF-Receiver Wake-up Interrupt */
#define LFWP_vect            _VECTOR(9)
#define LFWP_vect_num        9

/* Timer/Counter3 Capture Event */
#define T3CAP_vect            _VECTOR(10)
#define T3CAP_vect_num        10

/* Timer/Counter3 Compare Match A */
#define T3COMA_vect            _VECTOR(11)
#define T3COMA_vect_num        11

/* Timer/Counter3 Compare Match B */
#define T3COMB_vect            _VECTOR(12)
#define T3COMB_vect_num        12

/* Timer/Counter3 Overflow */
#define T3OVF_vect            _VECTOR(13)
#define T3OVF_vect_num        13

/* Timer/Counter2 Capture Event */
#define T2CAP_vect            _VECTOR(14)
#define T2CAP_vect_num        14

/* Timer/Counter2 Compare Match */
#define T2COM_vect            _VECTOR(15)
#define T2COM_vect_num        15

/* Timer/Counter2 Overflow */
#define T2OVF_vect            _VECTOR(16)
#define T2OVF_vect_num        16

/* SPI Serial Transfer Complete */
#define SPISTC_vect            _VECTOR(17)
#define SPISTC_vect_num        17

/* LF Receive Buffer Interrupt */
#define LFRXB_vect            _VECTOR(18)
#define LFRXB_vect_num        18

/* Timer1 Interval Interrupt */
#define INTT1_vect            _VECTOR(19)
#define INTT1_vect_num        19

/* Timer2 SSI Receive Buffer Interrupt */
#define T2RXB_vect            _VECTOR(20)
#define T2RXB_vect_num        20

/* Timer2 SSI Transmit Buffer Interrupt */
#define T2TXB_vect            _VECTOR(21)
#define T2TXB_vect_num        21

/* Timer2 SSI Transmit Complete Interrupt */
#define T2TXC_vect            _VECTOR(22)
#define T2TXC_vect_num        22

/* LF-Receiver End of Burst Interrupt */
#define LFREOB_vect            _VECTOR(23)
#define LFREOB_vect_num        23

/* External Input Clock break down Interrupt */
#define EXCM_vect            _VECTOR(24)
#define EXCM_vect_num        24

/* EEPROM Ready Interrupt */
#define EEREADY_vect            _VECTOR(25)
#define EEREADY_vect_num        25

/* Store Program Memory Ready */
#define SPM_RDY_vect            _VECTOR(26)
#define SPM_RDY_vect_num        26

#define _VECTORS_SIZE 54


/* Constants */

#define SPM_PAGESIZE 64
#define FLASHSTART   0x0000
#define FLASHEND     0x1FFF
#define RAMSTART     0x0100
#define RAMSIZE      512
#define RAMEND       0x02FF
#define E2START     0
#define E2SIZE      320
#define E2PAGESIZE  4
#define E2END       0x013F
#define XRAMEND      RAMEND


/* Fuses */

#define FUSE_MEMORY_SIZE 2

/* Low Fuse Byte */
#define FUSE_TSRDI       (unsigned char)~_BV(0)
#define FUSE_BODEN       (unsigned char)~_BV(1)
#define FUSE_FRCFS       (unsigned char)~_BV(2)
#define FUSE_WDRCON      (unsigned char)~_BV(3)
#define FUSE_SUT_CKSEL0  (unsigned char)~_BV(4)
#define FUSE_SUT_CKSEL1  (unsigned char)~_BV(5)
#define FUSE_CKOUT       (unsigned char)~_BV(6)
#define FUSE_CKDIV8      (unsigned char)~_BV(7)
#define LFUSE_DEFAULT    (FUSE_BODEN & FUSE_FRCFS & FUSE_WDRCON & FUSE_SUT_CKSEL0 & FUSE_CKDIV8)


/* High Fuse Byte */
#define FUSE_BOOTRST     (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0     (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1     (unsigned char)~_BV(2)
#define FUSE_EESAVE      (unsigned char)~_BV(3)
#define FUSE_WDTON       (unsigned char)~_BV(4)
#define FUSE_SPIEN       (unsigned char)~_BV(5)
#define FUSE_DWEN        (unsigned char)~_BV(6)
#define FUSE_EELOCK      (unsigned char)~_BV(7)
#define HFUSE_DEFAULT    (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN)



/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x82


#endif /* #ifdef _AVR_ATA6286_H_INCLUDED */

