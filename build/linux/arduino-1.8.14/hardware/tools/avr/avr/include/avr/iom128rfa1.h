/* Copyright (c) 2009 Atmel Corporation
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id: iom128rfa1.h 2009 2009-07-01 14:57:41Z joerg_wunsch $ */

/* avr/iom128rfa1.h - definitions for ATmega128RFA1 */

#ifndef _AVR_IOM128RFA1_H_
#define _AVR_IOM128RFA1_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom128rfa1.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif

#include <avr/sfr_defs.h>

#ifndef __ASSEMBLER__
#  define _MMIO_BYTE_STRUCT(mem_addr,type) (*(volatile type *)(mem_addr))
#  define _SFR_IO8_STRUCT(io_addr,type) _MMIO_BYTE_STRUCT((io_addr) + 0x20, type)
#  define _SFR_MEM8_STRUCT(io_addr,type) _MMIO_BYTE_STRUCT((io_addr), type)
#endif /* __ASSEMBLER__ */

/*
 * USAGE:
 *
 * simple register assignment:
 * TIFR1 = 0x17
 * subregister assignment:
 * TIFR1_struct.ocf1a = 1
 * (subregister names are converted to small letters)
 */


/* Port A Input Pins Address */
#define PINA                            _SFR_IO8(0x00)

  /* PINA */

#define PINA0                           0
#define PINA1                           1
#define PINA2                           2
#define PINA3                           3
#define PINA4                           4
#define PINA5                           5
#define PINA6                           6
#define PINA7                           7

/* Port A Data Direction Register */
#define DDRA                            _SFR_IO8(0x01)

  /* DDRA */

#define DDA0                            0
#define DDA1                            1
#define DDA2                            2
#define DDA3                            3
#define DDA4                            4
#define DDA5                            5
#define DDA6                            6
#define DDA7                            7

/* Port A Data Register */
#define PORTA                           _SFR_IO8(0x02)

  /* PORTA */

#define PORTA0                          0
#define PA0                             0
#define PORTA1                          1
#define PA1                             1
#define PORTA2                          2
#define PA2                             2
#define PORTA3                          3
#define PA3                             3
#define PORTA4                          4
#define PA4                             4
#define PORTA5                          5
#define PA5                             5
#define PORTA6                          6
#define PA6                             6
#define PORTA7                          7
#define PA7                             7

/* Port B Input Pins Address */
#define PINB                            _SFR_IO8(0x03)

  /* PINB */

#define PINB0                           0
#define PINB1                           1
#define PINB2                           2
#define PINB3                           3
#define PINB4                           4
#define PINB5                           5
#define PINB6                           6
#define PINB7                           7

/* Port B Data Direction Register */
#define DDRB                            _SFR_IO8(0x04)

  /* DDRB */

#define DDB0                            0
#define DDB1                            1
#define DDB2                            2
#define DDB3                            3
#define DDB4                            4
#define DDB5                            5
#define DDB6                            6
#define DDB7                            7

/* Port B Data Register */
#define PORTB                           _SFR_IO8(0x05)

  /* PORTB */

#define PORTB0                          0
#define PB0                             0
#define PORTB1                          1
#define PB1                             1
#define PORTB2                          2
#define PB2                             2
#define PORTB3                          3
#define PB3                             3
#define PORTB4                          4
#define PB4                             4
#define PORTB5                          5
#define PB5                             5
#define PORTB6                          6
#define PB6                             6
#define PORTB7                          7
#define PB7                             7

/* Port C Input Pins Address */
#define PINC                            _SFR_IO8(0x06)

  /* PINC */

#define PINC0                           0
#define PINC1                           1
#define PINC2                           2
#define PINC3                           3
#define PINC4                           4
#define PINC5                           5
#define PINC6                           6
#define PINC7                           7

/* Port C Data Direction Register */
#define DDRC                            _SFR_IO8(0x07)

  /* DDRC */

#define DDC0                            0
#define DDC1                            1
#define DDC2                            2
#define DDC3                            3
#define DDC4                            4
#define DDC5                            5
#define DDC6                            6
#define DDC7                            7

/* Port C Data Register */
#define PORTC                           _SFR_IO8(0x08)

  /* PORTC */

#define PORTC0                          0
#define PC0                             0
#define PORTC1                          1
#define PC1                             1
#define PORTC2                          2
#define PC2                             2
#define PORTC3                          3
#define PC3                             3
#define PORTC4                          4
#define PC4                             4
#define PORTC5                          5
#define PC5                             5
#define PORTC6                          6
#define PC6                             6
#define PORTC7                          7
#define PC7                             7

/* Port D Input Pins Address */
#define PIND                            _SFR_IO8(0x09)

  /* PIND */

#define PIND0                           0
#define PIND1                           1
#define PIND2                           2
#define PIND3                           3
#define PIND4                           4
#define PIND5                           5
#define PIND6                           6
#define PIND7                           7

/* Port D Data Direction Register */
#define DDRD                            _SFR_IO8(0x0A)

  /* DDRD */

#define DDD0                            0
#define DDD1                            1
#define DDD2                            2
#define DDD3                            3
#define DDD4                            4
#define DDD5                            5
#define DDD6                            6
#define DDD7                            7

/* Port D Data Register */
#define PORTD                           _SFR_IO8(0x0B)

  /* PORTD */

#define PORTD0                          0
#define PD0                             0
#define PORTD1                          1
#define PD1                             1
#define PORTD2                          2
#define PD2                             2
#define PORTD3                          3
#define PD3                             3
#define PORTD4                          4
#define PD4                             4
#define PORTD5                          5
#define PD5                             5
#define PORTD6                          6
#define PD6                             6
#define PORTD7                          7
#define PD7                             7

/* Port E Input Pins Address */
#define PINE                            _SFR_IO8(0x0C)

  /* PINE */

#define PINE0                           0
#define PINE1                           1
#define PINE2                           2
#define PINE3                           3
#define PINE4                           4
#define PINE5                           5
#define PINE6                           6
#define PINE7                           7

/* Port E Data Direction Register */
#define DDRE                            _SFR_IO8(0x0D)

  /* DDRE */

#define DDE0                            0
#define DDE1                            1
#define DDE2                            2
#define DDE3                            3
#define DDE4                            4
#define DDE5                            5
#define DDE6                            6
#define DDE7                            7

/* Port E Data Register */
#define PORTE                           _SFR_IO8(0x0E)

  /* PORTE */

#define PORTE0                          0
#define PE0                             0
#define PORTE1                          1
#define PE1                             1
#define PORTE2                          2
#define PE2                             2
#define PORTE3                          3
#define PE3                             3
#define PORTE4                          4
#define PE4                             4
#define PORTE5                          5
#define PE5                             5
#define PORTE6                          6
#define PE6                             6
#define PORTE7                          7
#define PE7                             7

/* Port F Input Pins Address */
#define PINF                            _SFR_IO8(0x0F)

  /* PINF */

#define PINF0                           0
#define PINF1                           1
#define PINF2                           2
#define PINF3                           3
#define PINF4                           4
#define PINF5                           5
#define PINF6                           6
#define PINF7                           7

/* Port F Data Direction Register */
#define DDRF                            _SFR_IO8(0x10)

  /* DDRF */

#define DDF0                            0
#define DDF1                            1
#define DDF2                            2
#define DDF3                            3
#define DDF4                            4
#define DDF5                            5
#define DDF6                            6
#define DDF7                            7

/* Port F Data Register */
#define PORTF                           _SFR_IO8(0x11)

  /* PORTF */

#define PORTF0                          0
#define PF0                             0
#define PORTF1                          1
#define PF1                             1
#define PORTF2                          2
#define PF2                             2
#define PORTF3                          3
#define PF3                             3
#define PORTF4                          4
#define PF4                             4
#define PORTF5                          5
#define PF5                             5
#define PORTF6                          6
#define PF6                             6
#define PORTF7                          7
#define PF7                             7

/* Port G Input Pins Address */
#define PING                            _SFR_IO8(0x12)

  /* PING */

#define PING0                           0
#define PING1                           1
#define PING2                           2
#define PING3                           3
#define PING4                           4
#define PING5                           5

/* Port G Data Direction Register */
#define DDRG                            _SFR_IO8(0x13)

  /* DDRG */

#define DDG0                            0
#define DDG1                            1
#define DDG2                            2
#define DDG3                            3
#define DDG4                            4
#define DDG5                            5

/* Port G Data Register */
#define PORTG                           _SFR_IO8(0x14)

  /* PORTG */

#define PORTG0                          0
#define PG0                             0
#define PORTG1                          1
#define PG1                             1
#define PORTG2                          2
#define PG2                             2
#define PORTG3                          3
#define PG3                             3
#define PORTG4                          4
#define PG4                             4
#define PORTG5                          5
#define PG5                             5

/* Timer/Counter0 Interrupt Flag Register */
#define TIFR0                           _SFR_IO8(0x15)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIFR0 {
        unsigned int tov0 : 1;	/* Timer/Counter0 Overflow Flag */
        unsigned int ocf0a : 1;	/* Timer/Counter0 Output Compare A Match Flag */
        unsigned int ocf0b : 1;	/* Timer/Counter0 Output Compare B Match Flag */
        unsigned int : 5;
};

#define TIFR0_struct _SFR_IO8_STRUCT(0x15, struct __reg_TIFR0)

#endif /* __ASSEMBLER__ */

  /* TIFR0 */

#define TOV0                            0
#define OCF0A                           1
#define OCF0B                           2

/* Timer/Counter1 Interrupt Flag Register */
#define TIFR1                           _SFR_IO8(0x16)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIFR1 {
        unsigned int tov1 : 1;	/* Timer/Counter1 Overflow Flag */
        unsigned int ocf1a : 1;	/* Timer/Counter1 Output Compare A Match Flag */
        unsigned int ocf1b : 1;	/* Timer/Counter1 Output Compare B Match Flag */
        unsigned int ocf1c : 1;	/* Timer/Counter1 Output Compare C Match Flag */
        unsigned int : 1;
        unsigned int icf1 : 1;	/* Timer/Counter1 Input Capture Flag */
        unsigned int : 2;
};

#define TIFR1_struct _SFR_IO8_STRUCT(0x16, struct __reg_TIFR1)

#endif /* __ASSEMBLER__ */

  /* TIFR1 */

#define TOV1                            0
#define OCF1A                           1
#define OCF1B                           2
#define OCF1C                           3
#define ICF1                            5

/* Timer/Counter Interrupt Flag Register */
#define TIFR2                           _SFR_IO8(0x17)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIFR2 {
        unsigned int tov2 : 1;	/* Timer/Counter2 Overflow Flag */
        unsigned int ocf2a : 1;	/* Output Compare Flag 2 A */
        unsigned int ocf2b : 1;	/* Output Compare Flag 2 B */
        unsigned int : 5;
};

#define TIFR2_struct _SFR_IO8_STRUCT(0x17, struct __reg_TIFR2)

#endif /* __ASSEMBLER__ */

  /* TIFR2 */

#define TOV2                            0
#define OCF2A                           1
#define OCF2B                           2

/* Timer/Counter3 Interrupt Flag Register */
#define TIFR3                           _SFR_IO8(0x18)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIFR3 {
        unsigned int tov3 : 1;	/* Timer/Counter3 Overflow Flag */
        unsigned int ocf3a : 1;	/* Timer/Counter3 Output Compare A Match Flag */
        unsigned int ocf3b : 1;	/* Timer/Counter3 Output Compare B Match Flag */
        unsigned int ocf3c : 1;	/* Timer/Counter3 Output Compare C Match Flag */
        unsigned int : 1;
        unsigned int icf3 : 1;	/* Timer/Counter3 Input Capture Flag */
        unsigned int : 2;
};

#define TIFR3_struct _SFR_IO8_STRUCT(0x18, struct __reg_TIFR3)

#endif /* __ASSEMBLER__ */

  /* TIFR3 */

#define TOV3                            0
#define OCF3A                           1
#define OCF3B                           2
#define OCF3C                           3
#define ICF3                            5

/* Timer/Counter4 Interrupt Flag Register */
#define TIFR4                           _SFR_IO8(0x19)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIFR4 {
        unsigned int tov4 : 1;	/* Timer/Counter4 Overflow Flag */
        unsigned int ocf4a : 1;	/* Timer/Counter4 Output Compare A Match Flag */
        unsigned int ocf4b : 1;	/* Timer/Counter4 Output Compare B Match Flag */
        unsigned int ocf4c : 1;	/* Timer/Counter4 Output Compare C Match Flag */
        unsigned int : 1;
        unsigned int icf4 : 1;	/* Timer/Counter4 Input Capture Flag */
        unsigned int : 2;
};

#define TIFR4_struct _SFR_IO8_STRUCT(0x19, struct __reg_TIFR4)

#endif /* __ASSEMBLER__ */

  /* TIFR4 */

#define TOV4                            0
#define OCF4A                           1
#define OCF4B                           2
#define OCF4C                           3
#define ICF4                            5

/* Timer/Counter5 Interrupt Flag Register */
#define TIFR5                           _SFR_IO8(0x1A)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIFR5 {
        unsigned int tov5 : 1;	/* Timer/Counter5 Overflow Flag */
        unsigned int ocf5a : 1;	/* Timer/Counter5 Output Compare A Match Flag */
        unsigned int ocf5b : 1;	/* Timer/Counter5 Output Compare B Match Flag */
        unsigned int ocf5c : 1;	/* Timer/Counter5 Output Compare C Match Flag */
        unsigned int : 1;
        unsigned int icf5 : 1;	/* Timer/Counter5 Input Capture Flag */
        unsigned int : 2;
};

#define TIFR5_struct _SFR_IO8_STRUCT(0x1a, struct __reg_TIFR5)

#endif /* __ASSEMBLER__ */

  /* TIFR5 */

#define TOV5                            0
#define OCF5A                           1
#define OCF5B                           2
#define OCF5C                           3
#define ICF5                            5

/* Pin Change Interrupt Flag Register */
#define PCIFR                           _SFR_IO8(0x1B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PCIFR {
        unsigned int pcif : 3;	/* Pin Change Interrupt Flag 2 */
        unsigned int : 5;
};

#define PCIFR_struct _SFR_IO8_STRUCT(0x1b, struct __reg_PCIFR)

#endif /* __ASSEMBLER__ */

  /* PCIFR */

#define PCIF0                           0
#define PCIF1                           1
#define PCIF2                           2

/* External Interrupt Flag Register */
#define EIFR                            _SFR_IO8(0x1C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_EIFR {
        unsigned int intf : 8;	/* External Interrupt Flag */
};

#define EIFR_struct _SFR_IO8_STRUCT(0x1c, struct __reg_EIFR)

#endif /* __ASSEMBLER__ */

  /* EIFR */

#define INTF0                           0
#define INTF1                           1
#define INTF2                           2
#define INTF3                           3
#define INTF4                           4
#define INTF5                           5
#define INTF6                           6
#define INTF7                           7

/* External Interrupt Mask Register */
#define EIMSK                           _SFR_IO8(0x1D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_EIMSK {
        unsigned int intm : 8;	/* External Interrupt Request Enable */
};

#define EIMSK_struct _SFR_IO8_STRUCT(0x1d, struct __reg_EIMSK)

#endif /* __ASSEMBLER__ */

  /* EIMSK */

#define INT0                            0
#define INT1                            1
#define INT2                            2
#define INT3                            3
#define INT4                            4
#define INT5                            5
#define INT6                            6
#define INT7                            7

/* General Purpose IO Register 0 */
#define GPIOR0                          _SFR_IO8(0x1E)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_GPIOR0 {
        unsigned int gpior0 : 8;	/* General Purpose I/O Register 0 Value */
};

#define GPIOR0_struct _SFR_IO8_STRUCT(0x1e, struct __reg_GPIOR0)

#endif /* __ASSEMBLER__ */

  /* GPIOR0 */

#define GPIOR00                         0
#define GPIOR01                         1
#define GPIOR02                         2
#define GPIOR03                         3
#define GPIOR04                         4
#define GPIOR05                         5
#define GPIOR06                         6
#define GPIOR07                         7

/* 6-char sequence denoting where to find the EEPROM registers in memory space.
   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
   subroutines.
   First two letters:  EECR address.
   Second two letters: EEDR address.
   Last two letters:   EEAR address.  */

#define __EEPROM_REG_LOCATIONS__ 1F2021

/* EEPROM Control Register */
#define EECR                            _SFR_IO8(0x1F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_EECR {
        unsigned int eere : 1;	/* EEPROM Read Enable */
        unsigned int eepe : 1;	/* EEPROM Programming Enable */
        unsigned int eempe : 1;	/* EEPROM Master Write Enable */
        unsigned int eerie : 1;	/* EEPROM Ready Interrupt Enable */
        unsigned int eepm : 2;	/* EEPROM Programming Mode */
        unsigned int : 2;
};

#define EECR_struct _SFR_IO8_STRUCT(0x1f, struct __reg_EECR)

#endif /* __ASSEMBLER__ */

  /* EECR */

#define EERE                            0
#define EEPE                            1
#define EEMPE                           2
#define EERIE                           3
#define EEPM0                           4
#define EEPM1                           5

/* EEPROM Data Register */
#define EEDR                            _SFR_IO8(0x20)

  /* EEDR */

#define EEDR0                           0
#define EEDR1                           1
#define EEDR2                           2
#define EEDR3                           3
#define EEDR4                           4
#define EEDR5                           5
#define EEDR6                           6
#define EEDR7                           7

/* EEPROM Address Register  Bytes */
#define EEAR                            _SFR_IO16(0x21)
#define EEARL                           _SFR_IO8(0x21)
#define EEARH                           _SFR_IO8(0x22)

/* General Timer/Counter Control Register */
#define GTCCR                           _SFR_IO8(0x23)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_GTCCR {
        unsigned int psrsync : 1;	/* Prescaler Reset for Synchronous Timer/Counters */
        unsigned int psrasy : 1;	/* Prescaler Reset Timer/Counter2 */
        unsigned int : 5;
        unsigned int tsm : 1;	/* Timer/Counter Synchronization Mode */
};

#define GTCCR_struct _SFR_IO8_STRUCT(0x23, struct __reg_GTCCR)

#endif /* __ASSEMBLER__ */

  /* GTCCR */

#define PSRSYNC                         0
#define PSR10                           0
#define PSRASY                          1
#define PSR2                            1
#define TSM                             7

/* Timer/Counter0 Control Register A */
#define TCCR0A                          _SFR_IO8(0x24)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR0A {
        unsigned int wgm0 : 2;	/* Waveform Generation Mode */
        unsigned int : 2;
        unsigned int com0b : 2;	/* Compare Match Output B Mode */
        unsigned int com0a : 2;	/* Compare Match Output A Mode */
};

#define TCCR0A_struct _SFR_IO8_STRUCT(0x24, struct __reg_TCCR0A)

#endif /* __ASSEMBLER__ */

  /* TCCR0A */

#define WGM00                           0
#define WGM01                           1
#define COM0B0                          4
#define COM0B1                          5
#define COM0A0                          6
#define COM0A1                          7

/* Timer/Counter0 Control Register B */
#define TCCR0B                          _SFR_IO8(0x25)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR0B {
        unsigned int cs0 : 3;	/* Clock Select */
        unsigned int wgm02 : 1;	/*  */
        unsigned int : 2;
        unsigned int foc0b : 1;	/* Force Output Compare B */
        unsigned int foc0a : 1;	/* Force Output Compare A */
};

#define TCCR0B_struct _SFR_IO8_STRUCT(0x25, struct __reg_TCCR0B)

#endif /* __ASSEMBLER__ */

  /* TCCR0B */

#define CS00                            0
#define CS01                            1
#define CS02                            2
#define WGM02                           3
#define FOC0B                           6
#define FOC0A                           7

/* Timer/Counter0 Register */
#define TCNT0                           _SFR_IO8(0x26)

  /* TCNT0 */

#define TCNT0_0                         0
#define TCNT0_1                         1
#define TCNT0_2                         2
#define TCNT0_3                         3
#define TCNT0_4                         4
#define TCNT0_5                         5
#define TCNT0_6                         6
#define TCNT0_7                         7

/* Timer/Counter0 Output Compare Register */
#define OCR0A                           _SFR_IO8(0x27)

  /* OCR0A */

#define OCR0A_0                         0
#define OCR0A_1                         1
#define OCR0A_2                         2
#define OCR0A_3                         3
#define OCR0A_4                         4
#define OCR0A_5                         5
#define OCR0A_6                         6
#define OCR0A_7                         7

/* Timer/Counter0 Output Compare Register B */
#define OCR0B                           _SFR_IO8(0x28)

  /* OCR0B */

#define OCR0B_0                         0
#define OCR0B_1                         1
#define OCR0B_2                         2
#define OCR0B_3                         3
#define OCR0B_4                         4
#define OCR0B_5                         5
#define OCR0B_6                         6
#define OCR0B_7                         7

/* General Purpose IO Register 1 */
#define GPIOR1                          _SFR_IO8(0x2A)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_GPIOR1 {
        unsigned int gpior1 : 8;	/* General Purpose I/O Register 1 Value */
};

#define GPIOR1_struct _SFR_IO8_STRUCT(0x2a, struct __reg_GPIOR1)

#endif /* __ASSEMBLER__ */

  /* GPIOR1 */

#define GPIOR10                         0
#define GPIOR11                         1
#define GPIOR12                         2
#define GPIOR13                         3
#define GPIOR14                         4
#define GPIOR15                         5
#define GPIOR16                         6
#define GPIOR17                         7

/* General Purpose I/O Register 2 */
#define GPIOR2                          _SFR_IO8(0x2B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_GPIOR2 {
        unsigned int gpior2 : 8;	/* General Purpose I/O Register 2 Value */
};

#define GPIOR2_struct _SFR_IO8_STRUCT(0x2b, struct __reg_GPIOR2)

#endif /* __ASSEMBLER__ */

  /* GPIOR2 */

#define GPIOR20                         0
#define GPIOR21                         1
#define GPIOR22                         2
#define GPIOR23                         3
#define GPIOR24                         4
#define GPIOR25                         5
#define GPIOR26                         6
#define GPIOR27                         7

/* SPI Control Register */
#define SPCR                            _SFR_IO8(0x2C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SPCR {
        unsigned int spr : 2;	/* SPI Clock Rate Select 1 and 0 */
        unsigned int cpha : 1;	/* Clock Phase */
        unsigned int cpol : 1;	/* Clock polarity */
        unsigned int mstr : 1;	/* Master/Slave Select */
        unsigned int dord : 1;	/* Data Order */
        unsigned int spe : 1;	/* SPI Enable */
        unsigned int spie : 1;	/* SPI Interrupt Enable */
};

#define SPCR_struct _SFR_IO8_STRUCT(0x2c, struct __reg_SPCR)

#endif /* __ASSEMBLER__ */

  /* SPCR */

#define SPR0                            0
#define SPR1                            1
#define CPHA                            2
#define CPOL                            3
#define MSTR                            4
#define DORD                            5
#define SPE                             6
#define SPIE                            7

/* SPI Status Register */
#define SPSR                            _SFR_IO8(0x2D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SPSR {
        unsigned int spi2x : 1;	/* Double SPI Speed Bit */
        unsigned int : 5;
        unsigned int wcol : 1;	/* Write Collision Flag */
        unsigned int spif : 1;	/* SPI Interrupt Flag */
};

#define SPSR_struct _SFR_IO8_STRUCT(0x2d, struct __reg_SPSR)

#endif /* __ASSEMBLER__ */

  /* SPSR */

#define SPI2X                           0
#define WCOL                            6
#define SPIF                            7

/* SPI Data Register */
#define SPDR                            _SFR_IO8(0x2E)

  /* SPDR */

#define SPDR0                           0
#define SPDR1                           1
#define SPDR2                           2
#define SPDR3                           3
#define SPDR4                           4
#define SPDR5                           5
#define SPDR6                           6
#define SPDR7                           7

/* Analog Comparator Control And Status Register */
#define ACSR                            _SFR_IO8(0x30)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_ACSR {
        unsigned int acis : 2;	/* Analog Comparator Interrupt Mode Select */
        unsigned int acic : 1;	/* Analog Comparator Input Capture Enable */
        unsigned int acie : 1;	/* Analog Comparator Interrupt Enable */
        unsigned int aci : 1;	/* Analog Comparator Interrupt Flag */
        unsigned int aco : 1;	/* Analog Compare Output */
        unsigned int acbg : 1;	/* Analog Comparator Bandgap Select */
        unsigned int acd : 1;	/* Analog Comparator Disable */
};

#define ACSR_struct _SFR_IO8_STRUCT(0x30, struct __reg_ACSR)

#endif /* __ASSEMBLER__ */

  /* ACSR */

#define ACIS0                           0
#define ACIS1                           1
#define ACIC                            2
#define ACIE                            3
#define ACI                             4
#define ACO                             5
#define ACBG                            6
#define ACD                             7

/* On-Chip Debug Register */
#define OCDR                            _SFR_IO8(0x31)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_OCDR {
        unsigned int ocdr : 8;	/* On-Chip Debug Register Data */
};

#define OCDR_struct _SFR_IO8_STRUCT(0x31, struct __reg_OCDR)

#endif /* __ASSEMBLER__ */

  /* OCDR */

#define OCDR0                           0
#define OCDR1                           1
#define OCDR2                           2
#define OCDR3                           3
#define OCDR4                           4
#define OCDR5                           5
#define OCDR6                           6
#define OCDR7                           7
#define IDRD                            7

/* Sleep Mode Control Register */
#define SMCR                            _SFR_IO8(0x33)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SMCR {
        unsigned int se : 1;	/* Sleep Enable */
        unsigned int sm : 3;	/* Sleep Mode Select bits */
        unsigned int : 4;
};

#define SMCR_struct _SFR_IO8_STRUCT(0x33, struct __reg_SMCR)

#endif /* __ASSEMBLER__ */

  /* SMCR */

#define SE                              0
#define SM0                             1
#define SM1                             2
#define SM2                             3

/* MCU Status Register */
#define MCUSR                           _SFR_IO8(0x34)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_MCUSR {
        unsigned int porf : 1;	/* Power-on Reset Flag */
        unsigned int extrf : 1;	/* External Reset Flag */
        unsigned int borf : 1;	/* Brown-out Reset Flag */
        unsigned int wdrf : 1;	/* Watchdog Reset Flag */
        unsigned int jtrf : 1;	/* JTAG Reset Flag */
        unsigned int : 3;
};

#define MCUSR_struct _SFR_IO8_STRUCT(0x34, struct __reg_MCUSR)

#endif /* __ASSEMBLER__ */

  /* MCUSR */

#define PORF                            0
#define EXTRF                           1
#define BORF                            2
#define WDRF                            3
#define JTRF                            4

/* MCU Control Register */
#define MCUCR                           _SFR_IO8(0x35)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_MCUCR {
        unsigned int ivce : 1;	/* Interrupt Vector Change Enable */
        unsigned int ivsel : 1;	/* Interrupt Vector Select */
        unsigned int : 2;
        unsigned int pud : 1;	/* Pull-up Disable */
        unsigned int : 2;
        unsigned int jtd : 1;	/* JTAG Interface Disable */
};

#define MCUCR_struct _SFR_IO8_STRUCT(0x35, struct __reg_MCUCR)

#endif /* __ASSEMBLER__ */

  /* MCUCR */

#define IVCE                            0
#define IVSEL                           1
#define PUD                             4
#define JTD                             7

/* Store Program Memory Control Register */
#define SPMCSR                          _SFR_IO8(0x37)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SPMCSR {
        unsigned int spmen : 1;	/* Store Program Memory Enable */
        unsigned int pgers : 1;	/* Page Erase */
        unsigned int pgwrt : 1;	/* Page Write */
        unsigned int blbset : 1;	/* Boot Lock Bit Set */
        unsigned int rwwsre : 1;	/* Read While Write Section Read Enable */
        unsigned int sigrd : 1;	/* Signature Row Read */
        unsigned int rwwsb : 1;	/* Read While Write Section Busy */
        unsigned int spmie : 1;	/* SPM Interrupt Enable */
};

#define SPMCSR_struct _SFR_IO8_STRUCT(0x37, struct __reg_SPMCSR)

#endif /* __ASSEMBLER__ */

  /* SPMCSR */

#define SPMEN                           0
#define PGERS                           1
#define PGWRT                           2
#define BLBSET                          3
#define RWWSRE                          4
#define SIGRD                           5
#define RWWSB                           6
#define SPMIE                           7

/* Extended Z-pointer Register for ELPM/SPM */
#define RAMPZ                           _SFR_IO8(0x3B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_RAMPZ {
        unsigned int rampz : 2;	/* Extended Z-Pointer Value */
        unsigned int : 6;
};

#define RAMPZ_struct _SFR_IO8_STRUCT(0x3b, struct __reg_RAMPZ)

#endif /* __ASSEMBLER__ */

  /* RAMPZ */

#define RAMPZ0                          0
#define RAMPZ1                          1

/* Stack Pointer */
#define SP                              _SFR_IO16(0x3D)
#define SPL                             _SFR_IO8(0x3D)
#define SPH                             _SFR_IO8(0x3E)

/* Status Register */
#define SREG                            _SFR_IO8(0x3F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SREG {
        unsigned int c : 1;	/* Carry Flag */
        unsigned int z : 1;	/* Zero Flag */
        unsigned int n : 1;	/* Negative Flag */
        unsigned int v : 1;	/* Two's Complement Overflow Flag */
        unsigned int s : 1;	/* Sign Bit */
        unsigned int h : 1;	/* Half Carry Flag */
        unsigned int t : 1;	/* Bit Copy Storage */
        unsigned int i : 1;	/* Global Interrupt Enable */
};

#define SREG_struct _SFR_IO8_STRUCT(0x3f, struct __reg_SREG)

#endif /* __ASSEMBLER__ */

  /* SREG */

#define SREG_C                          0
#define SREG_Z                          1
#define SREG_N                          2
#define SREG_V                          3
#define SREG_S                          4
#define SREG_H                          5
#define SREG_T                          6
#define SREG_I                          7

/* Watchdog Timer Control Register */
#define WDTCSR                          _SFR_MEM8(0x60)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_WDTCSR {
        unsigned int wdp : 3;	/* Watchdog Timer Prescaler bits */
        unsigned int wde : 1;	/* Watch Dog Enable */
        unsigned int wdce : 1;	/* Watchdog Change Enable */
        unsigned int : 1;
        unsigned int wdie : 1;	/* Watchdog Timeout Interrupt Enable */
        unsigned int wdif : 1;	/* Watchdog Timeout Interrupt Flag */
};

#define WDTCSR_struct _SFR_MEM8_STRUCT(0x60, struct __reg_WDTCSR)

#endif /* __ASSEMBLER__ */

  /* WDTCSR */

#define WDP0                            0
#define WDP1                            1
#define WDP2                            2
#define WDE                             3
#define WDCE                            4
#define WDP3                            5
#define WDIE                            6
#define WDIF                            7

/* Clock Prescale Register */
#define CLKPR                           _SFR_MEM8(0x61)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_CLKPR {
        unsigned int clkps : 4;	/* Clock Prescaler Select Bits */
        unsigned int : 3;
        unsigned int clkpce : 1;	/* Clock Prescaler Change Enable */
};

#define CLKPR_struct _SFR_MEM8_STRUCT(0x61, struct __reg_CLKPR)

#endif /* __ASSEMBLER__ */

  /* CLKPR */

#define CLKPS0                          0
#define CLKPS1                          1
#define CLKPS2                          2
#define CLKPS3                          3
#define CLKPCE                          7

/* Power Reduction Register 2 */
#define PRR2                            _SFR_MEM8(0x63)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PRR2 {
        unsigned int prram : 4;	/* Power Reduction SRAM 3 */
        unsigned int : 4;
};

#define PRR2_struct _SFR_MEM8_STRUCT(0x63, struct __reg_PRR2)

#endif /* __ASSEMBLER__ */

  /* PRR2 */

#define PRRAM0                          0
#define PRRAM1                          1
#define PRRAM2                          2
#define PRRAM3                          3

#define __AVR_HAVE_PRR2	((1<<PRRAM0)|(1<<PRRAM1)|(1<<PRRAM2)|(1<<PRRAM3))
#define __AVR_HAVE_PRR2_PRRAM0
#define __AVR_HAVE_PRR2_PRRAM1
#define __AVR_HAVE_PRR2_PRRAM2
#define __AVR_HAVE_PRR2_PRRAM3

/* Power Reduction Register0 */
#define PRR0                            _SFR_MEM8(0x64)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PRR0 {
        unsigned int pradc : 1;	/* Power Reduction ADC */
        unsigned int prusart0 : 1;	/* Power Reduction USART */
        unsigned int prspi : 1;	/* Power Reduction Serial Peripheral Interface */
        unsigned int prtim1 : 1;	/* Power Reduction Timer/Counter1 */
        unsigned int prpga : 1;	/* Power Reduction PGA */
        unsigned int prtim0 : 1;	/* Power Reduction Timer/Counter0 */
        unsigned int prtim2 : 1;	/* Power Reduction Timer/Counter2 */
        unsigned int prtwi : 1;	/* Power Reduction TWI */
};

#define PRR0_struct _SFR_MEM8_STRUCT(0x64, struct __reg_PRR0)

#endif /* __ASSEMBLER__ */

  /* PRR0 */

#define PRADC                           0
#define PRUSART0                        1
#define PRSPI                           2
#define PRTIM1                          3
#define PRPGA                           4
#define PRTIM0                          5
#define PRTIM2                          6
#define PRTWI                           7

#define __AVR_HAVE_PRR0	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRPGA)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#define __AVR_HAVE_PRR0_PRADC
#define __AVR_HAVE_PRR0_PRUSART0
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRPGA
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM2
#define __AVR_HAVE_PRR0_PRTWI

/* Power Reduction Register 1 */
#define PRR1                            _SFR_MEM8(0x65)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PRR1 {
        unsigned int prusart : 3;	/* Reserved */
        unsigned int prtim3 : 1;	/* Power Reduction Timer/Counter3 */
        unsigned int prtim4 : 1;	/* Power Reduction Timer/Counter4 */
        unsigned int prtim5 : 1;	/* Power Reduction Timer/Counter5 */
        unsigned int prtrx24 : 1;	/* Power Reduction Transceiver */
        unsigned int : 1;
};

#define PRR1_struct _SFR_MEM8_STRUCT(0x65, struct __reg_PRR1)

#endif /* __ASSEMBLER__ */

  /* PRR1 */

#define PRUSART1                        0
#define PRUSART2                        1
#define PRUSART3                        2
#define PRTIM3                          3
#define PRTIM4                          4
#define PRTIM5                          5
#define PRTRX24                         6

#define __AVR_HAVE_PRR1	((1<<PRUSART1)|(1<<PRUSART2)|(1<<PRUSART3)|(1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5)|(1<<PRTRX24))
#define __AVR_HAVE_PRR1_PRUSART1
#define __AVR_HAVE_PRR1_PRUSART2
#define __AVR_HAVE_PRR1_PRUSART3
#define __AVR_HAVE_PRR1_PRTIM3
#define __AVR_HAVE_PRR1_PRTIM4
#define __AVR_HAVE_PRR1_PRTIM5
#define __AVR_HAVE_PRR1_PRTRX24

/* Oscillator Calibration Value */
#define OSCCAL                          _SFR_MEM8(0x66)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_OSCCAL {
        unsigned int cal : 8;	/* Oscillator Calibration Tuning Value */
};

#define OSCCAL_struct _SFR_MEM8_STRUCT(0x66, struct __reg_OSCCAL)

#endif /* __ASSEMBLER__ */

  /* OSCCAL */

#define CAL0                            0
#define CAL1                            1
#define CAL2                            2
#define CAL3                            3
#define CAL4                            4
#define CAL5                            5
#define CAL6                            6
#define CAL7                            7

/* Reference Voltage Calibration Register */
#define BGCR                            _SFR_MEM8(0x67)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_BGCR {
        unsigned int bgcal : 3;	/* Coarse Calibration Bits */
        unsigned int bgcal_fine : 4;	/* Fine Calibration Bits */
        unsigned int : 1;
};

#define BGCR_struct _SFR_MEM8_STRUCT(0x67, struct __reg_BGCR)

#endif /* __ASSEMBLER__ */

  /* BGCR */

#define BGCAL0                          0
#define BGCAL1                          1
#define BGCAL2                          2
#define BGCAL_FINE0                     3
#define BGCAL_FINE1                     4
#define BGCAL_FINE2                     5
#define BGCAL_FINE3                     6

/* Pin Change Interrupt Control Register */
#define PCICR                           _SFR_MEM8(0x68)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PCICR {
        unsigned int pcie : 3;	/* Pin Change Interrupt Enable 2 */
        unsigned int : 5;
};

#define PCICR_struct _SFR_MEM8_STRUCT(0x68, struct __reg_PCICR)

#endif /* __ASSEMBLER__ */

  /* PCICR */

#define PCIE0                           0
#define PCIE1                           1
#define PCIE2                           2

/* External Interrupt Control Register A */
#define EICRA                           _SFR_MEM8(0x69)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_EICRA {
        unsigned int isc0 : 2;	/* External Interrupt 0 Sense Control Bit */
        unsigned int isc1 : 2;	/* External Interrupt 1 Sense Control Bit */
        unsigned int isc2 : 2;	/* External Interrupt 2 Sense Control Bit */
        unsigned int isc3 : 2;	/* External Interrupt 3 Sense Control Bit */
};

#define EICRA_struct _SFR_MEM8_STRUCT(0x69, struct __reg_EICRA)

#endif /* __ASSEMBLER__ */

  /* EICRA */

#define ISC00                           0
#define ISC01                           1
#define ISC10                           2
#define ISC11                           3
#define ISC20                           4
#define ISC21                           5
#define ISC30                           6
#define ISC31                           7

/* External Interrupt Control Register B */
#define EICRB                           _SFR_MEM8(0x6A)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_EICRB {
        unsigned int isc4 : 2;	/* External Interrupt 4 Sense Control Bit */
        unsigned int isc5 : 2;	/* External Interrupt 5 Sense Control Bit */
        unsigned int isc6 : 2;	/* External Interrupt 6 Sense Control Bit */
        unsigned int isc7 : 2;	/* External Interrupt 7 Sense Control Bit */
};

#define EICRB_struct _SFR_MEM8_STRUCT(0x6a, struct __reg_EICRB)

#endif /* __ASSEMBLER__ */

  /* EICRB */

#define ISC40                           0
#define ISC41                           1
#define ISC50                           2
#define ISC51                           3
#define ISC60                           4
#define ISC61                           5
#define ISC70                           6
#define ISC71                           7

/* Pin Change Mask Register 0 */
#define PCMSK0                          _SFR_MEM8(0x6B)

  /* PCMSK0 */

#define PCINT0                          0
#define PCINT1                          1
#define PCINT2                          2
#define PCINT3                          3
#define PCINT4                          4
#define PCINT5                          5
#define PCINT6                          6
#define PCINT7                          7

/* Pin Change Mask Register 1 */
#define PCMSK1                          _SFR_MEM8(0x6C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PCMSK1 {
        unsigned int pcint : 2;	/* Pin Change Enable Mask */
        unsigned int pcint1 : 6;	/* Pin Change Enable Mask */
};

#define PCMSK1_struct _SFR_MEM8_STRUCT(0x6c, struct __reg_PCMSK1)

#endif /* __ASSEMBLER__ */

  /* PCMSK1 */

#define PCINT8                          0
#define PCINT9                          1
#define PCINT10                         2
#define PCINT11                         3
#define PCINT12                         4
#define PCINT13                         5
#define PCINT14                         6
#define PCINT15                         7

/* Pin Change Mask Register 2 */
#define PCMSK2                          _SFR_MEM8(0x6D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PCMSK2 {
        unsigned int pcint1 : 4;	/* Pin Change Enable Mask */
        unsigned int pcint2 : 4;	/* Pin Change Enable Mask */
};

#define PCMSK2_struct _SFR_MEM8_STRUCT(0x6d, struct __reg_PCMSK2)

#endif /* __ASSEMBLER__ */

  /* PCMSK2 */

#define PCINT16                         0
#define PCINT17                         1
#define PCINT18                         2
#define PCINT19                         3
#define PCINT20                         4
#define PCINT21                         5
#define PCINT22                         6
#define PCINT23                         7

/* Timer/Counter0 Interrupt Mask Register */
#define TIMSK0                          _SFR_MEM8(0x6E)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIMSK0 {
        unsigned int toie0 : 1;	/* Timer/Counter0 Overflow Interrupt Enable */
        unsigned int ocie0a : 1;	/* Timer/Counter0 Output Compare Match A Interrupt Enable */
        unsigned int ocie0b : 1;	/* Timer/Counter0 Output Compare Match B Interrupt Enable */
        unsigned int : 5;
};

#define TIMSK0_struct _SFR_MEM8_STRUCT(0x6e, struct __reg_TIMSK0)

#endif /* __ASSEMBLER__ */

  /* TIMSK0 */

#define TOIE0                           0
#define OCIE0A                          1
#define OCIE0B                          2

/* Timer/Counter1 Interrupt Mask Register */
#define TIMSK1                          _SFR_MEM8(0x6F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIMSK1 {
        unsigned int toie1 : 1;	/* Timer/Counter1 Overflow Interrupt Enable */
        unsigned int ocie1a : 1;	/* Timer/Counter1 Output Compare A Match Interrupt Enable */
        unsigned int ocie1b : 1;	/* Timer/Counter1 Output Compare B Match Interrupt Enable */
        unsigned int ocie1c : 1;	/* Timer/Counter1 Output Compare C Match Interrupt Enable */
        unsigned int : 1;
        unsigned int icie1 : 1;	/* Timer/Counter1 Input Capture Interrupt Enable */
        unsigned int : 2;
};

#define TIMSK1_struct _SFR_MEM8_STRUCT(0x6f, struct __reg_TIMSK1)

#endif /* __ASSEMBLER__ */

  /* TIMSK1 */

#define TOIE1                           0
#define OCIE1A                          1
#define OCIE1B                          2
#define OCIE1C                          3
#define ICIE1                           5

/* Timer/Counter Interrupt Mask register */
#define TIMSK2                          _SFR_MEM8(0x70)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIMSK2 {
        unsigned int toie2 : 1;	/* Timer/Counter2 Overflow Interrupt Enable */
        unsigned int ocie2a : 1;	/* Timer/Counter2 Output Compare Match A Interrupt Enable */
        unsigned int ocie2b : 1;	/* Timer/Counter2 Output Compare Match B Interrupt Enable */
        unsigned int : 5;
};

#define TIMSK2_struct _SFR_MEM8_STRUCT(0x70, struct __reg_TIMSK2)

#endif /* __ASSEMBLER__ */

  /* TIMSK2 */

#define TOIE2                           0
#define TOIE2A                          0
#define OCIE2A                          1
#define OCIE2B                          2

/* Timer/Counter3 Interrupt Mask Register */
#define TIMSK3                          _SFR_MEM8(0x71)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIMSK3 {
        unsigned int toie3 : 1;	/* Timer/Counter3 Overflow Interrupt Enable */
        unsigned int ocie3a : 1;	/* Timer/Counter3 Output Compare A Match Interrupt Enable */
        unsigned int ocie3b : 1;	/* Timer/Counter3 Output Compare B Match Interrupt Enable */
        unsigned int ocie3c : 1;	/* Timer/Counter3 Output Compare C Match Interrupt Enable */
        unsigned int : 1;
        unsigned int icie3 : 1;	/* Timer/Counter3 Input Capture Interrupt Enable */
        unsigned int : 2;
};

#define TIMSK3_struct _SFR_MEM8_STRUCT(0x71, struct __reg_TIMSK3)

#endif /* __ASSEMBLER__ */

  /* TIMSK3 */

#define TOIE3                           0
#define OCIE3A                          1
#define OCIE3B                          2
#define OCIE3C                          3
#define ICIE3                           5

/* Timer/Counter4 Interrupt Mask Register */
#define TIMSK4                          _SFR_MEM8(0x72)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIMSK4 {
        unsigned int toie4 : 1;	/* Timer/Counter4 Overflow Interrupt Enable */
        unsigned int ocie4a : 1;	/* Timer/Counter4 Output Compare A Match Interrupt Enable */
        unsigned int ocie4b : 1;	/* Timer/Counter4 Output Compare B Match Interrupt Enable */
        unsigned int ocie4c : 1;	/* Timer/Counter4 Output Compare C Match Interrupt Enable */
        unsigned int : 1;
        unsigned int icie4 : 1;	/* Timer/Counter4 Input Capture Interrupt Enable */
        unsigned int : 2;
};

#define TIMSK4_struct _SFR_MEM8_STRUCT(0x72, struct __reg_TIMSK4)

#endif /* __ASSEMBLER__ */

  /* TIMSK4 */

#define TOIE4                           0
#define OCIE4A                          1
#define OCIE4B                          2
#define OCIE4C                          3
#define ICIE4                           5

/* Timer/Counter5 Interrupt Mask Register */
#define TIMSK5                          _SFR_MEM8(0x73)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TIMSK5 {
        unsigned int toie5 : 1;	/* Timer/Counter5 Overflow Interrupt Enable */
        unsigned int ocie5a : 1;	/* Timer/Counter5 Output Compare A Match Interrupt Enable */
        unsigned int ocie5b : 1;	/* Timer/Counter5 Output Compare B Match Interrupt Enable */
        unsigned int ocie5c : 1;	/* Timer/Counter5 Output Compare C Match Interrupt Enable */
        unsigned int : 1;
        unsigned int icie5 : 1;	/* Timer/Counter5 Input Capture Interrupt Enable */
        unsigned int : 2;
};

#define TIMSK5_struct _SFR_MEM8_STRUCT(0x73, struct __reg_TIMSK5)

#endif /* __ASSEMBLER__ */

  /* TIMSK5 */

#define TOIE5                           0
#define OCIE5A                          1
#define OCIE5B                          2
#define OCIE5C                          3
#define ICIE5                           5

/* Flash Extended-Mode Control-Register */
#define NEMCR                           _SFR_MEM8(0x75)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_NEMCR {
        unsigned int : 4;
        unsigned int aeam : 2;	/* Address for Extended Address Mode of Extra Rows */
        unsigned int eneam : 1;	/* Enable Extended Address Mode for Extra Rows */
        unsigned int : 1;
};

#define NEMCR_struct _SFR_MEM8_STRUCT(0x75, struct __reg_NEMCR)

#endif /* __ASSEMBLER__ */

  /* NEMCR */

#define AEAM0                           4
#define AEAM1                           5
#define ENEAM                           6

/* The ADC Control and Status Register C */
#define ADCSRC                          _SFR_MEM8(0x77)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_ADCSRC {
        unsigned int adsut : 5;	/* ADC Start-up Time */
        unsigned int res0 : 1;	/* Reserved */
        unsigned int adtht : 2;	/* ADC Track-and-Hold Time */
};

#define ADCSRC_struct _SFR_MEM8_STRUCT(0x77, struct __reg_ADCSRC)

#endif /* __ASSEMBLER__ */

  /* ADCSRC */

#define ADSUT0                          0
#define ADSUT1                          1
#define ADSUT2                          2
#define ADSUT3                          3
#define ADSUT4                          4
#define ADTHT0                          6
#define ADTHT1                          7

/* ADC Data Register  Bytes */
#ifndef __ASSEMBLER__
#define ADC                             _SFR_MEM16(0x78)
#define ADCL                            _SFR_MEM8(0x78)
#define ADCH                            _SFR_MEM8(0x79)
#endif /* __ASSEMBLER__ */
#define ADCW                            _SFR_MEM16(0x78)
#define ADCWL                           _SFR_MEM8(0x78)
#define ADCWH                           _SFR_MEM8(0x79)

/* The ADC Control and Status Register A */
#define ADCSRA                          _SFR_MEM8(0x7A)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_ADCSRA {
        unsigned int adps : 3;	/* ADC  Prescaler Select Bits */
        unsigned int adie : 1;	/* ADC Interrupt Enable */
        unsigned int adif : 1;	/* ADC Interrupt Flag */
        unsigned int adate : 1;	/* ADC Auto Trigger Enable */
        unsigned int adsc : 1;	/* ADC Start Conversion */
        unsigned int aden : 1;	/* ADC Enable */
};

#define ADCSRA_struct _SFR_MEM8_STRUCT(0x7a, struct __reg_ADCSRA)

#endif /* __ASSEMBLER__ */

  /* ADCSRA */

#define ADPS0                           0
#define ADPS1                           1
#define ADPS2                           2
#define ADIE                            3
#define ADIF                            4
#define ADATE                           5
#define ADSC                            6
#define ADEN                            7

/* ADC Control and Status Register B */
#define ADCSRB                          _SFR_MEM8(0x7B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_ADCSRB {
        unsigned int adts : 3;	/* ADC Auto Trigger Source */
        unsigned int mux5 : 1;	/* Analog Channel and Gain Selection Bits */
        unsigned int acch : 1;	/* Analog Channel Change */
        unsigned int refok : 1;	/* Reference Voltage OK */
        unsigned int acme : 1;	/* Analog Comparator Multiplexer Enable */
        unsigned int avddok : 1;	/* AVDD Supply Voltage OK */
};

#define ADCSRB_struct _SFR_MEM8_STRUCT(0x7b, struct __reg_ADCSRB)

#endif /* __ASSEMBLER__ */

  /* ADCSRB */

#define ADTS0                           0
#define ADTS1                           1
#define ADTS2                           2
#define MUX5                            3
#define ACCH                            4
#define REFOK                           5
#define ACME                            6
#define AVDDOK                          7

/* The ADC Multiplexer Selection Register */
#define ADMUX                           _SFR_MEM8(0x7C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_ADMUX {
        unsigned int mux : 5;	/* Analog Channel and Gain Selection Bits */
        unsigned int adlar : 1;	/* ADC Left Adjust Result */
        unsigned int refs : 2;	/* Reference Selection Bits */
};

#define ADMUX_struct _SFR_MEM8_STRUCT(0x7c, struct __reg_ADMUX)

#endif /* __ASSEMBLER__ */

  /* ADMUX */

#define MUX0                            0
#define MUX1                            1
#define MUX2                            2
#define MUX3                            3
#define MUX4                            4
#define ADLAR                           5
#define REFS0                           6
#define REFS1                           7

/* Digital Input Disable Register 2 */
#define DIDR2                           _SFR_MEM8(0x7D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DIDR2 {
        unsigned int adc8d : 1;	/* Reserved Bits */
        unsigned int adc9d : 1;	/* Reserved Bits */
        unsigned int adc10d : 1;	/* Reserved Bits */
        unsigned int adc11d : 1;	/* Reserved Bits */
        unsigned int adc12d : 1;	/* Reserved Bits */
        unsigned int adc13d : 1;	/* Reserved Bits */
        unsigned int adc14d : 1;	/* Reserved Bits */
        unsigned int adc15d : 1;	/* Reserved Bits */
};

#define DIDR2_struct _SFR_MEM8_STRUCT(0x7d, struct __reg_DIDR2)

#endif /* __ASSEMBLER__ */

  /* DIDR2 */

#define ADC8D                           0
#define ADC9D                           1
#define ADC10D                          2
#define ADC11D                          3
#define ADC12D                          4
#define ADC13D                          5
#define ADC14D                          6
#define ADC15D                          7

/* Digital Input Disable Register 0 */
#define DIDR0                           _SFR_MEM8(0x7E)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DIDR0 {
        unsigned int adc0d : 1;	/* Disable ADC7:0 Digital Input */
        unsigned int adc1d : 1;	/* Disable ADC7:0 Digital Input */
        unsigned int adc2d : 1;	/* Disable ADC7:0 Digital Input */
        unsigned int adc3d : 1;	/* Disable ADC7:0 Digital Input */
        unsigned int adc4d : 1;	/* Disable ADC7:0 Digital Input */
        unsigned int adc5d : 1;	/* Disable ADC7:0 Digital Input */
        unsigned int adc6d : 1;	/* Disable ADC7:0 Digital Input */
        unsigned int adc7d : 1;	/* Disable ADC7:0 Digital Input */
};

#define DIDR0_struct _SFR_MEM8_STRUCT(0x7e, struct __reg_DIDR0)

#endif /* __ASSEMBLER__ */

  /* DIDR0 */

#define ADC0D                           0
#define ADC1D                           1
#define ADC2D                           2
#define ADC3D                           3
#define ADC4D                           4
#define ADC5D                           5
#define ADC6D                           6
#define ADC7D                           7

/* Digital Input Disable Register 1 */
#define DIDR1                           _SFR_MEM8(0x7F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DIDR1 {
        unsigned int ain0d : 1;	/* AIN0 Digital Input Disable */
        unsigned int ain1d : 1;	/* AIN1 Digital Input Disable */
        unsigned int : 6;
};

#define DIDR1_struct _SFR_MEM8_STRUCT(0x7f, struct __reg_DIDR1)

#endif /* __ASSEMBLER__ */

  /* DIDR1 */

#define AIN0D                           0
#define AIN1D                           1

/* Timer/Counter1 Control Register A */
#define TCCR1A                          _SFR_MEM8(0x80)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR1A {
        unsigned int wgm1 : 2;	/* Waveform Generation Mode */
        unsigned int com1c : 2;	/* Compare Output Mode for Channel C */
        unsigned int com1b : 2;	/* Compare Output Mode for Channel B */
        unsigned int com1a : 2;	/* Compare Output Mode for Channel A */
};

#define TCCR1A_struct _SFR_MEM8_STRUCT(0x80, struct __reg_TCCR1A)

#endif /* __ASSEMBLER__ */

  /* TCCR1A */

#define WGM10                           0
#define WGM11                           1
#define COM1C0                          2
#define COM1C1                          3
#define COM1B0                          4
#define COM1B1                          5
#define COM1A0                          6
#define COM1A1                          7

/* Timer/Counter1 Control Register B */
#define TCCR1B                          _SFR_MEM8(0x81)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR1B {
        unsigned int cs1 : 3;	/* Clock Select */
        unsigned int wgm1 : 2;	/* Waveform Generation Mode */
        unsigned int : 1;
        unsigned int ices1 : 1;	/* Input Capture 1 Edge Select */
        unsigned int icnc1 : 1;	/* Input Capture 1 Noise Canceller */
};

#define TCCR1B_struct _SFR_MEM8_STRUCT(0x81, struct __reg_TCCR1B)

#endif /* __ASSEMBLER__ */

  /* TCCR1B */

#define CS10                            0
#define CS11                            1
#define CS12                            2
#define WGM12                           3
#define WGM13                           4
#define ICES1                           6
#define ICNC1                           7

/* Timer/Counter1 Control Register C */
#define TCCR1C                          _SFR_MEM8(0x82)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR1C {
        unsigned int : 5;
        unsigned int foc1c : 1;	/* Force Output Compare for Channel C */
        unsigned int foc1b : 1;	/* Force Output Compare for Channel B */
        unsigned int foc1a : 1;	/* Force Output Compare for Channel A */
};

#define TCCR1C_struct _SFR_MEM8_STRUCT(0x82, struct __reg_TCCR1C)

#endif /* __ASSEMBLER__ */

  /* TCCR1C */

#define FOC1C                           5
#define FOC1B                           6
#define FOC1A                           7

/* Timer/Counter1  Bytes */
#define TCNT1                           _SFR_MEM16(0x84)
#define TCNT1L                          _SFR_MEM8(0x84)
#define TCNT1H                          _SFR_MEM8(0x85)

/* Timer/Counter1 Input Capture Register  Bytes */
#define ICR1                            _SFR_MEM16(0x86)
#define ICR1L                           _SFR_MEM8(0x86)
#define ICR1H                           _SFR_MEM8(0x87)

/* Timer/Counter1 Output Compare Register A  Bytes */
#define OCR1A                           _SFR_MEM16(0x88)
#define OCR1AL                          _SFR_MEM8(0x88)
#define OCR1AH                          _SFR_MEM8(0x89)

/* Timer/Counter1 Output Compare Register B  Bytes */
#define OCR1B                           _SFR_MEM16(0x8A)
#define OCR1BL                          _SFR_MEM8(0x8A)
#define OCR1BH                          _SFR_MEM8(0x8B)

/* Timer/Counter1 Output Compare Register C  Bytes */
#define OCR1C                           _SFR_MEM16(0x8C)
#define OCR1CL                          _SFR_MEM8(0x8C)
#define OCR1CH                          _SFR_MEM8(0x8D)

/* Timer/Counter3 Control Register A */
#define TCCR3A                          _SFR_MEM8(0x90)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR3A {
        unsigned int wgm3 : 2;	/* Waveform Generation Mode */
        unsigned int com3c : 2;	/* Compare Output Mode for Channel C */
        unsigned int com3b : 2;	/* Compare Output Mode for Channel B */
        unsigned int com3a : 2;	/* Compare Output Mode for Channel A */
};

#define TCCR3A_struct _SFR_MEM8_STRUCT(0x90, struct __reg_TCCR3A)

#endif /* __ASSEMBLER__ */

  /* TCCR3A */

#define WGM30                           0
#define WGM31                           1
#define COM3C0                          2
#define COM3C1                          3
#define COM3B0                          4
#define COM3B1                          5
#define COM3A0                          6
#define COM3A1                          7

/* Timer/Counter3 Control Register B */
#define TCCR3B                          _SFR_MEM8(0x91)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR3B {
        unsigned int cs3 : 3;	/* Clock Select */
        unsigned int wgm3 : 2;	/* Waveform Generation Mode */
        unsigned int : 1;
        unsigned int ices3 : 1;	/* Input Capture 3 Edge Select */
        unsigned int icnc3 : 1;	/* Input Capture 3 Noise Canceller */
};

#define TCCR3B_struct _SFR_MEM8_STRUCT(0x91, struct __reg_TCCR3B)

#endif /* __ASSEMBLER__ */

  /* TCCR3B */

#define CS30                            0
#define CS31                            1
#define CS32                            2
#define WGM32                           3
#define WGM33                           4
#define ICES3                           6
#define ICNC3                           7

/* Timer/Counter3 Control Register C */
#define TCCR3C                          _SFR_MEM8(0x92)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR3C {
        unsigned int : 5;
        unsigned int foc3c : 1;	/* Force Output Compare for Channel C */
        unsigned int foc3b : 1;	/* Force Output Compare for Channel B */
        unsigned int foc3a : 1;	/* Force Output Compare for Channel A */
};

#define TCCR3C_struct _SFR_MEM8_STRUCT(0x92, struct __reg_TCCR3C)

#endif /* __ASSEMBLER__ */

  /* TCCR3C */

#define FOC3C                           5
#define FOC3B                           6
#define FOC3A                           7

/* Timer/Counter3  Bytes */
#define TCNT3                           _SFR_MEM16(0x94)
#define TCNT3L                          _SFR_MEM8(0x94)
#define TCNT3H                          _SFR_MEM8(0x95)

/* Timer/Counter3 Input Capture Register  Bytes */
#define ICR3                            _SFR_MEM16(0x96)
#define ICR3L                           _SFR_MEM8(0x96)
#define ICR3H                           _SFR_MEM8(0x97)

/* Timer/Counter3 Output Compare Register A  Bytes */
#define OCR3A                           _SFR_MEM16(0x98)
#define OCR3AL                          _SFR_MEM8(0x98)
#define OCR3AH                          _SFR_MEM8(0x99)

/* Timer/Counter3 Output Compare Register B  Bytes */
#define OCR3B                           _SFR_MEM16(0x9A)
#define OCR3BL                          _SFR_MEM8(0x9A)
#define OCR3BH                          _SFR_MEM8(0x9B)

/* Timer/Counter3 Output Compare Register C  Bytes */
#define OCR3C                           _SFR_MEM16(0x9C)
#define OCR3CL                          _SFR_MEM8(0x9C)
#define OCR3CH                          _SFR_MEM8(0x9D)

/* Timer/Counter4 Control Register A */
#define TCCR4A                          _SFR_MEM8(0xA0)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR4A {
        unsigned int wgm4 : 2;	/* Waveform Generation Mode */
        unsigned int com4c : 2;	/* Compare Output Mode for Channel C */
        unsigned int com4b : 2;	/* Compare Output Mode for Channel B */
        unsigned int com4a : 2;	/* Compare Output Mode for Channel A */
};

#define TCCR4A_struct _SFR_MEM8_STRUCT(0xa0, struct __reg_TCCR4A)

#endif /* __ASSEMBLER__ */

  /* TCCR4A */

#define WGM40                           0
#define WGM41                           1
#define COM4C0                          2
#define COM4C1                          3
#define COM4B0                          4
#define COM4B1                          5
#define COM4A0                          6
#define COM4A1                          7

/* Timer/Counter4 Control Register B */
#define TCCR4B                          _SFR_MEM8(0xA1)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR4B {
        unsigned int cs4 : 3;	/* Clock Select */
        unsigned int wgm4 : 2;	/* Waveform Generation Mode */
        unsigned int : 1;
        unsigned int ices4 : 1;	/* Input Capture 4 Edge Select */
        unsigned int icnc4 : 1;	/* Input Capture 4 Noise Canceller */
};

#define TCCR4B_struct _SFR_MEM8_STRUCT(0xa1, struct __reg_TCCR4B)

#endif /* __ASSEMBLER__ */

  /* TCCR4B */

#define CS40                            0
#define CS41                            1
#define CS42                            2
#define WGM42                           3
#define WGM43                           4
#define ICES4                           6
#define ICNC4                           7

/* Timer/Counter4 Control Register C */
#define TCCR4C                          _SFR_MEM8(0xA2)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR4C {
        unsigned int : 5;
        unsigned int foc4c : 1;	/* Force Output Compare for Channel C */
        unsigned int foc4b : 1;	/* Force Output Compare for Channel B */
        unsigned int foc4a : 1;	/* Force Output Compare for Channel A */
};

#define TCCR4C_struct _SFR_MEM8_STRUCT(0xa2, struct __reg_TCCR4C)

#endif /* __ASSEMBLER__ */

  /* TCCR4C */

#define FOC4C                           5
#define FOC4B                           6
#define FOC4A                           7

/* Timer/Counter4  Bytes */
#define TCNT4                           _SFR_MEM16(0xA4)
#define TCNT4L                          _SFR_MEM8(0xA4)
#define TCNT4H                          _SFR_MEM8(0xA5)

/* Timer/Counter4 Input Capture Register  Bytes */
#define ICR4                            _SFR_MEM16(0xA6)
#define ICR4L                           _SFR_MEM8(0xA6)
#define ICR4H                           _SFR_MEM8(0xA7)

/* Timer/Counter4 Output Compare Register A  Bytes */
#define OCR4A                           _SFR_MEM16(0xA8)
#define OCR4AL                          _SFR_MEM8(0xA8)
#define OCR4AH                          _SFR_MEM8(0xA9)

/* Timer/Counter4 Output Compare Register B  Bytes */
#define OCR4B                           _SFR_MEM16(0xAA)
#define OCR4BL                          _SFR_MEM8(0xAA)
#define OCR4BH                          _SFR_MEM8(0xAB)

/* Timer/Counter4 Output Compare Register C  Bytes */
#define OCR4C                           _SFR_MEM16(0xAC)
#define OCR4CL                          _SFR_MEM8(0xAC)
#define OCR4CH                          _SFR_MEM8(0xAD)

/* Timer/Counter2 Control Register A */
#define TCCR2A                          _SFR_MEM8(0xB0)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR2A {
        unsigned int wgm2 : 2;	/* Waveform Generation Mode */
        unsigned int : 2;
        unsigned int com2b : 2;	/* Compare Match Output B Mode */
        unsigned int com2a : 2;	/* Compare Match Output A Mode */
};

#define TCCR2A_struct _SFR_MEM8_STRUCT(0xb0, struct __reg_TCCR2A)

#endif /* __ASSEMBLER__ */

  /* TCCR2A */

#define WGM20                           0
#define WGM21                           1
#define COM2B0                          4
#define COM2B1                          5
#define COM2A0                          6
#define COM2A1                          7

/* Timer/Counter2 Control Register B */
#define TCCR2B                          _SFR_MEM8(0xB1)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR2B {
        unsigned int cs2 : 3;	/* Clock Select */
        unsigned int wgm22 : 1;	/* Waveform Generation Mode */
        unsigned int : 2;
        unsigned int foc2b : 1;	/* Force Output Compare B */
        unsigned int foc2a : 1;	/* Force Output Compare A */
};

#define TCCR2B_struct _SFR_MEM8_STRUCT(0xb1, struct __reg_TCCR2B)

#endif /* __ASSEMBLER__ */

  /* TCCR2B */

#define CS20                            0
#define CS21                            1
#define CS22                            2
#define WGM22                           3
#define FOC2B                           6
#define FOC2A                           7

/* Timer/Counter2 */
#define TCNT2                           _SFR_MEM8(0xB2)

  /* TCNT2 */

#define TCNT20                          0
#define TCNT21                          1
#define TCNT22                          2
#define TCNT23                          3
#define TCNT24                          4
#define TCNT25                          5
#define TCNT26                          6
#define TCNT27                          7

/* Timer/Counter2 Output Compare Register A */
#define OCR2A                           _SFR_MEM8(0xB3)

  /* OCR2A */

#define OCR2A0                          0
#define OCR2A1                          1
#define OCR2A2                          2
#define OCR2A3                          3
#define OCR2A4                          4
#define OCR2A5                          5
#define OCR2A6                          6
#define OCR2A7                          7

/* Timer/Counter2 Output Compare Register B */
#define OCR2B                           _SFR_MEM8(0xB4)

  /* OCR2B */

#define OCR2B0                          0
#define OCR2B1                          1
#define OCR2B2                          2
#define OCR2B3                          3
#define OCR2B4                          4
#define OCR2B5                          5
#define OCR2B6                          6
#define OCR2B7                          7

/* Asynchronous Status Register */
#define ASSR                            _SFR_MEM8(0xB6)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_ASSR {
        unsigned int tcr2bub : 1;	/* Timer/Counter2 Control Register B Update Busy */
        unsigned int tcr2aub : 1;	/* Timer/Counter2 Control Register A Update Busy */
        unsigned int ocr2bub : 1;	/* Timer/Counter2 Output Compare Register B Update Busy */
        unsigned int ocr2aub : 1;	/* Timer/Counter2 Output Compare Register A Update Busy */
        unsigned int tcn2ub : 1;	/* Timer/Counter2 Update Busy */
        unsigned int as2 : 1;	/* Timer/Counter2 Asynchronous Mode */
        unsigned int exclk : 1;	/* Enable External Clock Input */
        unsigned int exclkamr : 1;	/* Enable External Clock Input for AMR */
};

#define ASSR_struct _SFR_MEM8_STRUCT(0xb6, struct __reg_ASSR)

#endif /* __ASSEMBLER__ */

  /* ASSR */

#define TCR2BUB                         0
#define TCR2AUB                         1
#define OCR2BUB                         2
#define OCR2AUB                         3
#define TCN2UB                          4
#define AS2                             5
#define EXCLK                           6
#define EXCLKAMR                        7

/* TWI Bit Rate Register */
#define TWBR                            _SFR_MEM8(0xB8)

  /* TWBR */

#define TWBR0                           0
#define TWBR1                           1
#define TWBR2                           2
#define TWBR3                           3
#define TWBR4                           4
#define TWBR5                           5
#define TWBR6                           6
#define TWBR7                           7

/* TWI Status Register */
#define TWSR                            _SFR_MEM8(0xB9)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TWSR {
        unsigned int twps : 2;	/* TWI Prescaler Bits */
        unsigned int : 1;
        unsigned int tws : 5;	/* TWI Status */
};

#define TWSR_struct _SFR_MEM8_STRUCT(0xb9, struct __reg_TWSR)

#endif /* __ASSEMBLER__ */

  /* TWSR */

#define TWPS0                           0
#define TWPS1                           1
#define TWS3                            3
#define TWS4                            4
#define TWS5                            5
#define TWS6                            6
#define TWS7                            7

/* TWI (Slave) Address Register */
#define TWAR                            _SFR_MEM8(0xBA)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TWAR {
        unsigned int twgce : 1;	/* TWI General Call Recognition Enable Bit */
        unsigned int twa : 7;	/* TWI (Slave) Address */
};

#define TWAR_struct _SFR_MEM8_STRUCT(0xba, struct __reg_TWAR)

#endif /* __ASSEMBLER__ */

  /* TWAR */

#define TWGCE                           0
#define TWA0                            1
#define TWA1                            2
#define TWA2                            3
#define TWA3                            4
#define TWA4                            5
#define TWA5                            6
#define TWA6                            7

/* TWI Data Register */
#define TWDR                            _SFR_MEM8(0xBB)

  /* TWDR */

#define TWD0                            0
#define TWD1                            1
#define TWD2                            2
#define TWD3                            3
#define TWD4                            4
#define TWD5                            5
#define TWD6                            6
#define TWD7                            7

/* TWI Control Register */
#define TWCR                            _SFR_MEM8(0xBC)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TWCR {
        unsigned int twie : 1;	/* TWI Interrupt Enable */
        unsigned int : 1;
        unsigned int twen : 1;	/* TWI Enable Bit */
        unsigned int twwc : 1;	/* TWI Write Collision Flag */
        unsigned int twsto : 1;	/* TWI STOP Condition Bit */
        unsigned int twsta : 1;	/* TWI START Condition Bit */
        unsigned int twea : 1;	/* TWI Enable Acknowledge Bit */
        unsigned int twint : 1;	/* TWI Interrupt Flag */
};

#define TWCR_struct _SFR_MEM8_STRUCT(0xbc, struct __reg_TWCR)

#endif /* __ASSEMBLER__ */

  /* TWCR */

#define TWIE                            0
#define TWEN                            2
#define TWWC                            3
#define TWSTO                           4
#define TWSTA                           5
#define TWEA                            6
#define TWINT                           7

/* TWI (Slave) Address Mask Register */
#define TWAMR                           _SFR_MEM8(0xBD)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TWAMR {
        unsigned int : 1;
        unsigned int twam : 7;	/* TWI Address Mask */
};

#define TWAMR_struct _SFR_MEM8_STRUCT(0xbd, struct __reg_TWAMR)

#endif /* __ASSEMBLER__ */

  /* TWAMR */

#define TWAM0                           1
#define TWAMR0                          1
#define TWAM1                           2
#define TWAMR1                          2
#define TWAM2                           3
#define TWAMR2                          3
#define TWAM3                           4
#define TWAMR3                          4
#define TWAM4                           5
#define TWAMR4                          5
#define TWAM5                           6
#define TWAMR5                          6
#define TWAM6                           7
#define TWAMR6                          7

/* USART0 Control and Status Register A */
#define UCSR0A                          _SFR_MEM8(0xC0)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_UCSR0A {
        unsigned int mpcm0 : 1;	/* Multi-processor Communication Mode */
        unsigned int u2x0 : 1;	/* Double the USART Transmission Speed */
        unsigned int upe0 : 1;	/* USART Parity Error */
        unsigned int dor0 : 1;	/* Data OverRun */
        unsigned int fe0 : 1;	/* Frame Error */
        unsigned int udre0 : 1;	/* USART Data Register Empty */
        unsigned int txc0 : 1;	/* USART Transmit Complete */
        unsigned int rxc0 : 1;	/* USART Receive Complete */
};

#define UCSR0A_struct _SFR_MEM8_STRUCT(0xc0, struct __reg_UCSR0A)

#endif /* __ASSEMBLER__ */

  /* UCSR0A */

#define MPCM0                           0
#define U2X0                            1
#define UPE0                            2
#define DOR0                            3
#define FE0                             4
#define UDRE0                           5
#define TXC0                            6
#define RXC0                            7

/* USART0 Control and Status Register B */
#define UCSR0B                          _SFR_MEM8(0xC1)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_UCSR0B {
        unsigned int txb80 : 1;	/* Transmit Data Bit 8 */
        unsigned int rxb80 : 1;	/* Receive Data Bit 8 */
        unsigned int ucsz02 : 1;	/* Character Size */
        unsigned int txen0 : 1;	/* Transmitter Enable */
        unsigned int rxen0 : 1;	/* Receiver Enable */
        unsigned int udrie0 : 1;	/* USART Data Register Empty Interrupt Enable */
        unsigned int txcie0 : 1;	/* TX Complete Interrupt Enable */
        unsigned int rxcie0 : 1;	/* RX Complete Interrupt Enable */
};

#define UCSR0B_struct _SFR_MEM8_STRUCT(0xc1, struct __reg_UCSR0B)

#endif /* __ASSEMBLER__ */

  /* UCSR0B */

#define TXB80                           0
#define RXB80                           1
#define UCSZ02                          2
#define TXEN0                           3
#define RXEN0                           4
#define UDRIE0                          5
#define TXCIE0                          6
#define RXCIE0                          7

/* USART0 Control and Status Register C */
#define UCSR0C                          _SFR_MEM8(0xC2)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_UCSR0C {
        unsigned int ucpol0 : 1;	/* Clock Polarity */
        unsigned int ucsz0 : 2;	/* Character Size */
        unsigned int usbs0 : 1;	/* Stop Bit Select */
        unsigned int upm0 : 2;	/* Parity Mode */
        unsigned int umsel0 : 2;	/* USART Mode Select */
};
/* NOTE: UCSR0C in SPI mode have only lower three bits.
  UCORD1 Data Order
  UCPHA1 Clock Phase
  UCPOL1 Clock Polarity
*/

#define UCSR0C_struct _SFR_MEM8_STRUCT(0xc2, struct __reg_UCSR0C)

#endif /* __ASSEMBLER__ */

  /* UCSR0C */

#define UCPOL0                          0
#define UCPHA0                          1
#define UCSZ00                          1
#define UDORD0                          2
#define UCSZ01                          2
#define USBS0                           3
#define UPM00                           4
#define UPM01                           5
#define UMSEL00                         6
#define UMSEL0                          6
#define UMSEL01                         7
#define UMSEL1                          7

/* USART0 Baud Rate Register  Bytes */
#define UBRR0                           _SFR_MEM16(0xC4)
#define UBRR0L                          _SFR_MEM8(0xC4)
#define UBRR0H                          _SFR_MEM8(0xC5)

/* USART0 I/O Data Register */
#define UDR0                            _SFR_MEM8(0xC6)

  /* UDR0 */

#define UDR00                           0
#define UDR01                           1
#define UDR02                           2
#define UDR03                           3
#define UDR04                           4
#define UDR05                           5
#define UDR06                           6
#define UDR07                           7

/* USART1 Control and Status Register A */
#define UCSR1A                          _SFR_MEM8(0xC8)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_UCSR1A {
        unsigned int mpcm1 : 1;	/* Multi-processor Communication Mode */
        unsigned int u2x1 : 1;	/* Double the USART Transmission Speed */
        unsigned int upe1 : 1;	/* USART Parity Error */
        unsigned int dor1 : 1;	/* Data OverRun */
        unsigned int fe1 : 1;	/* Frame Error */
        unsigned int udre1 : 1;	/* USART Data Register Empty */
        unsigned int txc1 : 1;	/* USART Transmit Complete */
        unsigned int rxc1 : 1;	/* USART Receive Complete */
};

#define UCSR1A_struct _SFR_MEM8_STRUCT(0xc8, struct __reg_UCSR1A)

#endif /* __ASSEMBLER__ */

  /* UCSR1A */

#define MPCM1                           0
#define U2X1                            1
#define UPE1                            2
#define DOR1                            3
#define FE1                             4
#define UDRE1                           5
#define TXC1                            6
#define RXC1                            7

/* USART1 Control and Status Register B */
#define UCSR1B                          _SFR_MEM8(0xC9)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_UCSR1B {
        unsigned int txb81 : 1;	/* Transmit Data Bit 8 */
        unsigned int rxb81 : 1;	/* Receive Data Bit 8 */
        unsigned int ucsz12 : 1;	/* Character Size */
        unsigned int txen1 : 1;	/* Transmitter Enable */
        unsigned int rxen1 : 1;	/* Receiver Enable */
        unsigned int udrie1 : 1;	/* USART Data Register Empty Interrupt Enable */
        unsigned int txcie1 : 1;	/* TX Complete Interrupt Enable */
        unsigned int rxcie1 : 1;	/* RX Complete Interrupt Enable */
};

#define UCSR1B_struct _SFR_MEM8_STRUCT(0xc9, struct __reg_UCSR1B)

#endif /* __ASSEMBLER__ */

  /* UCSR1B */

#define TXB81                           0
#define RXB81                           1
#define UCSZ12                          2
#define TXEN1                           3
#define RXEN1                           4
#define UDRIE1                          5
#define TXCIE1                          6
#define RXCIE1                          7

/* USART1 Control and Status Register C */
#define UCSR1C                          _SFR_MEM8(0xCA)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_UCSR1C {
        unsigned int ucpol1 : 1;	/* Clock Polarity */
        unsigned int ucsz1 : 2;	/* Character Size */
        unsigned int usbs1 : 1;	/* Stop Bit Select */
        unsigned int upm1 : 2;	/* Parity Mode */
        unsigned int umsel1 : 2;	/* USART Mode Select */
};
/* NOTE: UCSR1C in SPI mode have only lower three bits.
  UCORD1 Data Order
  UCPHA1 Clock Phase
  UCPOL1 Clock Polarity
*/
#define UCSR1C_struct _SFR_MEM8_STRUCT(0xca, struct __reg_UCSR1C)

#endif /* __ASSEMBLER__ */

  /* UCSR1C */

#define UCPOL1                          0
#define UCPHA1                          1
#define UCSZ10                          1
#define UDORD1                          2
#define UCSZ11                          2
#define USBS1                           3
#define UPM10                           4
#define UPM11                           5
#define UMSEL10                         6
#define UMSEL11                         7

/* USART1 Baud Rate Register  Bytes */
#define UBRR1                           _SFR_MEM16(0xCC)
#define UBRR1L                          _SFR_MEM8(0xCC)
#define UBRR1H                          _SFR_MEM8(0xCD)

/* USART1 I/O Data Register */
#define UDR1                            _SFR_MEM8(0xCE)

  /* UDR1 */

#define UDR10                           0
#define UDR11                           1
#define UDR12                           2
#define UDR13                           3
#define UDR14                           4
#define UDR15                           5
#define UDR16                           6
#define UDR17                           7

/* Symbol Counter Control Register 0 */
#define SCCR0                           _SFR_MEM8(0xDC)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCCR0 {
        unsigned int sccmp : 3;	/* Symbol Counter Compare Unit 3 Mode select */
        unsigned int sctse : 1;	/* Symbol Counter Automatic Timestamping enable */
        unsigned int sccksel : 1;	/* Symbol Counter Clock Source select */
        unsigned int scen : 1;	/* Symbol Counter enable */
        unsigned int scmbts : 1;	/* Manual Beacon Timestamp */
        unsigned int scres : 1;	/* Symbol Counter Synchronization */
};

#define SCCR0_struct _SFR_MEM8_STRUCT(0xdc, struct __reg_SCCR0)

#endif /* __ASSEMBLER__ */

  /* SCCR0 */

#define SCCMP1                          0
#define SCCMP2                          1
#define SCCMP3                          2
#define SCTSE                           3
#define SCCKSEL                         4
#define SCEN                            5
#define SCMBTS                          6
#define SCRES                           7

/* Symbol Counter Control Register 1 */
#define SCCR1                           _SFR_MEM8(0xDD)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCCR1 {
        unsigned int scenbo : 1;	/* Backoff Slot Counter enable */
        unsigned int : 7;
};

#define SCCR1_struct _SFR_MEM8_STRUCT(0xdd, struct __reg_SCCR1)

#endif /* __ASSEMBLER__ */

  /* SCCR1 */

#define SCENBO                          0

/* Symbol Counter Status Register */
#define SCSR                            _SFR_MEM8(0xDE)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCSR {
        unsigned int scbsy : 1;	/* Symbol Counter busy */
        unsigned int : 7;
};

#define SCSR_struct _SFR_MEM8_STRUCT(0xde, struct __reg_SCSR)

#endif /* __ASSEMBLER__ */

  /* SCSR */

#define SCBSY                           0

/* Symbol Counter Interrupt Mask Register */
#define SCIRQM                          _SFR_MEM8(0xDF)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCIRQM {
        unsigned int irqmcp : 3;	/* Symbol Counter Compare Match 3 IRQ enable */
        unsigned int irqmof : 1;	/* Symbol Counter Overflow IRQ enable */
        unsigned int irqmbo : 1;	/* Backoff Slot Counter IRQ enable */
        unsigned int : 3;
};

#define SCIRQM_struct _SFR_MEM8_STRUCT(0xdf, struct __reg_SCIRQM)

#endif /* __ASSEMBLER__ */

  /* SCIRQM */

#define IRQMCP1                         0
#define IRQMCP2                         1
#define IRQMCP3                         2
#define IRQMOF                          3
#define IRQMBO                          4

/* Symbol Counter Interrupt Status Register */
#define SCIRQS                          _SFR_MEM8(0xE0)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCIRQS {
        unsigned int irqscp : 3;	/* Compare Unit 3 Compare Match IRQ */
        unsigned int irqsof : 1;	/* Symbol Counter Overflow IRQ */
        unsigned int irqsbo : 1;	/* Backoff Slot Counter IRQ */
        unsigned int : 3;
};

#define SCIRQS_struct _SFR_MEM8_STRUCT(0xe0, struct __reg_SCIRQS)

#endif /* __ASSEMBLER__ */

  /* SCIRQS */

#define IRQSCP1                         0
#define IRQSCP2                         1
#define IRQSCP3                         2
#define IRQSOF                          3
#define IRQSBO                          4

/* Symbol Counter Register LL-Byte */
#define SCCNTLL                         _SFR_MEM8(0xE1)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCCNTLL {
        unsigned int sccntll : 8;	/* Symbol Counter Register LL-Byte */
};

#define SCCNTLL_struct _SFR_MEM8_STRUCT(0xe1, struct __reg_SCCNTLL)

#endif /* __ASSEMBLER__ */

  /* SCCNTLL */

#define SCCNTLL0                        0
#define SCCNTLL1                        1
#define SCCNTLL2                        2
#define SCCNTLL3                        3
#define SCCNTLL4                        4
#define SCCNTLL5                        5
#define SCCNTLL6                        6
#define SCCNTLL7                        7

/* Symbol Counter Register LH-Byte */
#define SCCNTLH                         _SFR_MEM8(0xE2)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCCNTLH {
        unsigned int sccntlh : 8;	/* Symbol Counter Register LH-Byte */
};

#define SCCNTLH_struct _SFR_MEM8_STRUCT(0xe2, struct __reg_SCCNTLH)

#endif /* __ASSEMBLER__ */

  /* SCCNTLH */

#define SCCNTLH0                        0
#define SCCNTLH1                        1
#define SCCNTLH2                        2
#define SCCNTLH3                        3
#define SCCNTLH4                        4
#define SCCNTLH5                        5
#define SCCNTLH6                        6
#define SCCNTLH7                        7

/* Symbol Counter Register HL-Byte */
#define SCCNTHL                         _SFR_MEM8(0xE3)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCCNTHL {
        unsigned int sccnthl : 8;	/* Symbol Counter Register HL-Byte */
};

#define SCCNTHL_struct _SFR_MEM8_STRUCT(0xe3, struct __reg_SCCNTHL)

#endif /* __ASSEMBLER__ */

  /* SCCNTHL */

#define SCCNTHL0                        0
#define SCCNTHL1                        1
#define SCCNTHL2                        2
#define SCCNTHL3                        3
#define SCCNTHL4                        4
#define SCCNTHL5                        5
#define SCCNTHL6                        6
#define SCCNTHL7                        7

/* Symbol Counter Register HH-Byte */
#define SCCNTHH                         _SFR_MEM8(0xE4)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCCNTHH {
        unsigned int sccnthh : 8;	/* Symbol Counter Register HH-Byte */
};

#define SCCNTHH_struct _SFR_MEM8_STRUCT(0xe4, struct __reg_SCCNTHH)

#endif /* __ASSEMBLER__ */

  /* SCCNTHH */

#define SCCNTHH0                        0
#define SCCNTHH1                        1
#define SCCNTHH2                        2
#define SCCNTHH3                        3
#define SCCNTHH4                        4
#define SCCNTHH5                        5
#define SCCNTHH6                        6
#define SCCNTHH7                        7

/* Symbol Counter Beacon Timestamp Register LL-Byte */
#define SCBTSRLL                        _SFR_MEM8(0xE5)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCBTSRLL {
        unsigned int scbtsrll : 8;	/* Symbol Counter Beacon Timestamp Register LL-Byte */
};

#define SCBTSRLL_struct _SFR_MEM8_STRUCT(0xe5, struct __reg_SCBTSRLL)

#endif /* __ASSEMBLER__ */

  /* SCBTSRLL */

#define SCBTSRLL0                       0
#define SCBTSRLL1                       1
#define SCBTSRLL2                       2
#define SCBTSRLL3                       3
#define SCBTSRLL4                       4
#define SCBTSRLL5                       5
#define SCBTSRLL6                       6
#define SCBTSRLL7                       7

/* Symbol Counter Beacon Timestamp Register LH-Byte */
#define SCBTSRLH                        _SFR_MEM8(0xE6)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCBTSRLH {
        unsigned int scbtsrlh : 8;	/* Symbol Counter Beacon Timestamp Register LH-Byte */
};

#define SCBTSRLH_struct _SFR_MEM8_STRUCT(0xe6, struct __reg_SCBTSRLH)

#endif /* __ASSEMBLER__ */

  /* SCBTSRLH */

#define SCBTSRLH0                       0
#define SCBTSRLH1                       1
#define SCBTSRLH2                       2
#define SCBTSRLH3                       3
#define SCBTSRLH4                       4
#define SCBTSRLH5                       5
#define SCBTSRLH6                       6
#define SCBTSRLH7                       7

/* Symbol Counter Beacon Timestamp Register HL-Byte */
#define SCBTSRHL                        _SFR_MEM8(0xE7)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCBTSRHL {
        unsigned int scbtsrhl : 8;	/* Symbol Counter Beacon Timestamp Register HL-Byte */
};

#define SCBTSRHL_struct _SFR_MEM8_STRUCT(0xe7, struct __reg_SCBTSRHL)

#endif /* __ASSEMBLER__ */

  /* SCBTSRHL */

#define SCBTSRHL0                       0
#define SCBTSRHL1                       1
#define SCBTSRHL2                       2
#define SCBTSRHL3                       3
#define SCBTSRHL4                       4
#define SCBTSRHL5                       5
#define SCBTSRHL6                       6
#define SCBTSRHL7                       7

/* Symbol Counter Beacon Timestamp Register HH-Byte */
#define SCBTSRHH                        _SFR_MEM8(0xE8)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCBTSRHH {
        unsigned int scbtsrhh : 8;	/* Symbol Counter Beacon Timestamp Register HH-Byte */
};

#define SCBTSRHH_struct _SFR_MEM8_STRUCT(0xe8, struct __reg_SCBTSRHH)

#endif /* __ASSEMBLER__ */

  /* SCBTSRHH */

#define SCBTSRHH0                       0
#define SCBTSRHH1                       1
#define SCBTSRHH2                       2
#define SCBTSRHH3                       3
#define SCBTSRHH4                       4
#define SCBTSRHH5                       5
#define SCBTSRHH6                       6
#define SCBTSRHH7                       7

/* Symbol Counter Frame Timestamp Register LL-Byte */
#define SCTSRLL                         _SFR_MEM8(0xE9)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCTSRLL {
        unsigned int sctsrll : 8;	/* Symbol Counter Frame Timestamp Register LL-Byte */
};

#define SCTSRLL_struct _SFR_MEM8_STRUCT(0xe9, struct __reg_SCTSRLL)

#endif /* __ASSEMBLER__ */

  /* SCTSRLL */

#define SCTSRLL0                        0
#define SCTSRLL1                        1
#define SCTSRLL2                        2
#define SCTSRLL3                        3
#define SCTSRLL4                        4
#define SCTSRLL5                        5
#define SCTSRLL6                        6
#define SCTSRLL7                        7

/* Symbol Counter Frame Timestamp Register LH-Byte */
#define SCTSRLH                         _SFR_MEM8(0xEA)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCTSRLH {
        unsigned int sctsrlh : 8;	/* Symbol Counter Frame Timestamp Register LH-Byte */
};

#define SCTSRLH_struct _SFR_MEM8_STRUCT(0xea, struct __reg_SCTSRLH)

#endif /* __ASSEMBLER__ */

  /* SCTSRLH */

#define SCTSRLH0                        0
#define SCTSRLH1                        1
#define SCTSRLH2                        2
#define SCTSRLH3                        3
#define SCTSRLH4                        4
#define SCTSRLH5                        5
#define SCTSRLH6                        6
#define SCTSRLH7                        7

/* Symbol Counter Frame Timestamp Register HL-Byte */
#define SCTSRHL                         _SFR_MEM8(0xEB)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCTSRHL {
        unsigned int sctsrhl : 8;	/* Symbol Counter Frame Timestamp Register HL-Byte */
};

#define SCTSRHL_struct _SFR_MEM8_STRUCT(0xeb, struct __reg_SCTSRHL)

#endif /* __ASSEMBLER__ */

  /* SCTSRHL */

#define SCTSRHL0                        0
#define SCTSRHL1                        1
#define SCTSRHL2                        2
#define SCTSRHL3                        3
#define SCTSRHL4                        4
#define SCTSRHL5                        5
#define SCTSRHL6                        6
#define SCTSRHL7                        7

/* Symbol Counter Frame Timestamp Register HH-Byte */
#define SCTSRHH                         _SFR_MEM8(0xEC)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCTSRHH {
        unsigned int sctsrhh : 8;	/* Symbol Counter Frame Timestamp Register HH-Byte */
};

#define SCTSRHH_struct _SFR_MEM8_STRUCT(0xec, struct __reg_SCTSRHH)

#endif /* __ASSEMBLER__ */

  /* SCTSRHH */

#define SCTSRHH0                        0
#define SCTSRHH1                        1
#define SCTSRHH2                        2
#define SCTSRHH3                        3
#define SCTSRHH4                        4
#define SCTSRHH5                        5
#define SCTSRHH6                        6
#define SCTSRHH7                        7

/* Symbol Counter Output Compare Register 3 LL-Byte */
#define SCOCR3LL                        _SFR_MEM8(0xED)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR3LL {
        unsigned int scocr3ll : 8;	/* Symbol Counter Output Compare Register 3 LL-Byte */
};

#define SCOCR3LL_struct _SFR_MEM8_STRUCT(0xed, struct __reg_SCOCR3LL)

#endif /* __ASSEMBLER__ */

  /* SCOCR3LL */

#define SCOCR3LL0                       0
#define SCOCR3LL1                       1
#define SCOCR3LL2                       2
#define SCOCR3LL3                       3
#define SCOCR3LL4                       4
#define SCOCR3LL5                       5
#define SCOCR3LL6                       6
#define SCOCR3LL7                       7

/* Symbol Counter Output Compare Register 3 LH-Byte */
#define SCOCR3LH                        _SFR_MEM8(0xEE)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR3LH {
        unsigned int scocr3lh : 8;	/* Symbol Counter Output Compare Register 3 LH-Byte */
};

#define SCOCR3LH_struct _SFR_MEM8_STRUCT(0xee, struct __reg_SCOCR3LH)

#endif /* __ASSEMBLER__ */

  /* SCOCR3LH */

#define SCOCR3LH0                       0
#define SCOCR3LH1                       1
#define SCOCR3LH2                       2
#define SCOCR3LH3                       3
#define SCOCR3LH4                       4
#define SCOCR3LH5                       5
#define SCOCR3LH6                       6
#define SCOCR3LH7                       7

/* Symbol Counter Output Compare Register 3 HL-Byte */
#define SCOCR3HL                        _SFR_MEM8(0xEF)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR3HL {
        unsigned int scocr3hl : 8;	/* Symbol Counter Output Compare Register 3 HL-Byte */
};

#define SCOCR3HL_struct _SFR_MEM8_STRUCT(0xef, struct __reg_SCOCR3HL)

#endif /* __ASSEMBLER__ */

  /* SCOCR3HL */

#define SCOCR3HL0                       0
#define SCOCR3HL1                       1
#define SCOCR3HL2                       2
#define SCOCR3HL3                       3
#define SCOCR3HL4                       4
#define SCOCR3HL5                       5
#define SCOCR3HL6                       6
#define SCOCR3HL7                       7

/* Symbol Counter Output Compare Register 3 HH-Byte */
#define SCOCR3HH                        _SFR_MEM8(0xF0)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR3HH {
        unsigned int scocr3hh : 8;	/* Symbol Counter Output Compare Register 3 HH-Byte */
};

#define SCOCR3HH_struct _SFR_MEM8_STRUCT(0xf0, struct __reg_SCOCR3HH)

#endif /* __ASSEMBLER__ */

  /* SCOCR3HH */

#define SCOCR3HH0                       0
#define SCOCR3HH1                       1
#define SCOCR3HH2                       2
#define SCOCR3HH3                       3
#define SCOCR3HH4                       4
#define SCOCR3HH5                       5
#define SCOCR3HH6                       6
#define SCOCR3HH7                       7

/* Symbol Counter Output Compare Register 2 LL-Byte */
#define SCOCR2LL                        _SFR_MEM8(0xF1)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR2LL {
        unsigned int scocr2ll : 8;	/* Symbol Counter Output Compare Register 2 LL-Byte */
};

#define SCOCR2LL_struct _SFR_MEM8_STRUCT(0xf1, struct __reg_SCOCR2LL)

#endif /* __ASSEMBLER__ */

  /* SCOCR2LL */

#define SCOCR2LL0                       0
#define SCOCR2LL1                       1
#define SCOCR2LL2                       2
#define SCOCR2LL3                       3
#define SCOCR2LL4                       4
#define SCOCR2LL5                       5
#define SCOCR2LL6                       6
#define SCOCR2LL7                       7

/* Symbol Counter Output Compare Register 2 LH-Byte */
#define SCOCR2LH                        _SFR_MEM8(0xF2)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR2LH {
        unsigned int scocr2lh : 8;	/* Symbol Counter Output Compare Register 2 LH-Byte */
};

#define SCOCR2LH_struct _SFR_MEM8_STRUCT(0xf2, struct __reg_SCOCR2LH)

#endif /* __ASSEMBLER__ */

  /* SCOCR2LH */

#define SCOCR2LH0                       0
#define SCOCR2LH1                       1
#define SCOCR2LH2                       2
#define SCOCR2LH3                       3
#define SCOCR2LH4                       4
#define SCOCR2LH5                       5
#define SCOCR2LH6                       6
#define SCOCR2LH7                       7

/* Symbol Counter Output Compare Register 2 HL-Byte */
#define SCOCR2HL                        _SFR_MEM8(0xF3)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR2HL {
        unsigned int scocr2hl : 8;	/* Symbol Counter Output Compare Register 2 HL-Byte */
};

#define SCOCR2HL_struct _SFR_MEM8_STRUCT(0xf3, struct __reg_SCOCR2HL)

#endif /* __ASSEMBLER__ */

  /* SCOCR2HL */

#define SCOCR2HL0                       0
#define SCOCR2HL1                       1
#define SCOCR2HL2                       2
#define SCOCR2HL3                       3
#define SCOCR2HL4                       4
#define SCOCR2HL5                       5
#define SCOCR2HL6                       6
#define SCOCR2HL7                       7

/* Symbol Counter Output Compare Register 2 HH-Byte */
#define SCOCR2HH                        _SFR_MEM8(0xF4)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR2HH {
        unsigned int scocr2hh : 8;	/* Symbol Counter Output Compare Register 2 HH-Byte */
};

#define SCOCR2HH_struct _SFR_MEM8_STRUCT(0xf4, struct __reg_SCOCR2HH)

#endif /* __ASSEMBLER__ */

  /* SCOCR2HH */

#define SCOCR2HH0                       0
#define SCOCR2HH1                       1
#define SCOCR2HH2                       2
#define SCOCR2HH3                       3
#define SCOCR2HH4                       4
#define SCOCR2HH5                       5
#define SCOCR2HH6                       6
#define SCOCR2HH7                       7

/* Symbol Counter Output Compare Register 1 LL-Byte */
#define SCOCR1LL                        _SFR_MEM8(0xF5)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR1LL {
        unsigned int scocr1ll : 8;	/* Symbol Counter Output Compare Register 1 LL-Byte */
};

#define SCOCR1LL_struct _SFR_MEM8_STRUCT(0xf5, struct __reg_SCOCR1LL)

#endif /* __ASSEMBLER__ */

  /* SCOCR1LL */

#define SCOCR1LL0                       0
#define SCOCR1LL1                       1
#define SCOCR1LL2                       2
#define SCOCR1LL3                       3
#define SCOCR1LL4                       4
#define SCOCR1LL5                       5
#define SCOCR1LL6                       6
#define SCOCR1LL7                       7

/* Symbol Counter Output Compare Register 1 LH-Byte */
#define SCOCR1LH                        _SFR_MEM8(0xF6)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR1LH {
        unsigned int scocr1lh : 8;	/* Symbol Counter Output Compare Register 1 LH-Byte */
};

#define SCOCR1LH_struct _SFR_MEM8_STRUCT(0xf6, struct __reg_SCOCR1LH)

#endif /* __ASSEMBLER__ */

  /* SCOCR1LH */

#define SCOCR1LH0                       0
#define SCOCR1LH1                       1
#define SCOCR1LH2                       2
#define SCOCR1LH3                       3
#define SCOCR1LH4                       4
#define SCOCR1LH5                       5
#define SCOCR1LH6                       6
#define SCOCR1LH7                       7

/* Symbol Counter Output Compare Register 1 HL-Byte */
#define SCOCR1HL                        _SFR_MEM8(0xF7)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR1HL {
        unsigned int scocr1hl : 8;	/* Symbol Counter Output Compare Register 1 HL-Byte */
};

#define SCOCR1HL_struct _SFR_MEM8_STRUCT(0xf7, struct __reg_SCOCR1HL)

#endif /* __ASSEMBLER__ */

  /* SCOCR1HL */

#define SCOCR1HL0                       0
#define SCOCR1HL1                       1
#define SCOCR1HL2                       2
#define SCOCR1HL3                       3
#define SCOCR1HL4                       4
#define SCOCR1HL5                       5
#define SCOCR1HL6                       6
#define SCOCR1HL7                       7

/* Symbol Counter Output Compare Register 1 HH-Byte */
#define SCOCR1HH                        _SFR_MEM8(0xF8)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SCOCR1HH {
        unsigned int scocr1hh : 8;	/* Symbol Counter Output Compare Register 1 HH-Byte */
};

#define SCOCR1HH_struct _SFR_MEM8_STRUCT(0xf8, struct __reg_SCOCR1HH)

#endif /* __ASSEMBLER__ */

  /* SCOCR1HH */

#define SCOCR1HH0                       0
#define SCOCR1HH1                       1
#define SCOCR1HH2                       2
#define SCOCR1HH3                       3
#define SCOCR1HH4                       4
#define SCOCR1HH5                       5
#define SCOCR1HH6                       6
#define SCOCR1HH7                       7

/* Timer/Counter5 Control Register A */
#define TCCR5A                          _SFR_MEM8(0x120)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR5A {
        unsigned int wgm5 : 2;	/* Waveform Generation Mode */
        unsigned int com5c : 2;	/* Compare Output Mode for Channel C */
        unsigned int com5b : 2;	/* Compare Output Mode for Channel B */
        unsigned int com5a : 2;	/* Compare Output Mode for Channel A */
};

#define TCCR5A_struct _SFR_MEM8_STRUCT(0x120, struct __reg_TCCR5A)

#endif /* __ASSEMBLER__ */

  /* TCCR5A */

#define WGM50                           0
#define WGM51                           1
#define COM5C0                          2
#define COM5C1                          3
#define COM5B0                          4
#define COM5B1                          5
#define COM5A0                          6
#define COM5A1                          7

/* Timer/Counter5 Control Register B */
#define TCCR5B                          _SFR_MEM8(0x121)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR5B {
        unsigned int cs5 : 3;	/* Clock Select */
        unsigned int wgm5 : 2;	/* Waveform Generation Mode */
        unsigned int : 1;
        unsigned int ices5 : 1;	/* Input Capture 5 Edge Select */
        unsigned int icnc5 : 1;	/* Input Capture 5 Noise Canceller */
};

#define TCCR5B_struct _SFR_MEM8_STRUCT(0x121, struct __reg_TCCR5B)

#endif /* __ASSEMBLER__ */

  /* TCCR5B */

#define CS50                            0
#define CS51                            1
#define CS52                            2
#define WGM52                           3
#define WGM53                           4
#define ICES5                           6
#define ICNC5                           7

/* Timer/Counter5 Control Register C */
#define TCCR5C                          _SFR_MEM8(0x122)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TCCR5C {
        unsigned int : 5;
        unsigned int foc5c : 1;	/* Force Output Compare for Channel C */
        unsigned int foc5b : 1;	/* Force Output Compare for Channel B */
        unsigned int foc5a : 1;	/* Force Output Compare for Channel A */
};

#define TCCR5C_struct _SFR_MEM8_STRUCT(0x122, struct __reg_TCCR5C)

#endif /* __ASSEMBLER__ */

  /* TCCR5C */

#define FOC5C                           5
#define FOC5B                           6
#define FOC5A                           7

/* Timer/Counter5  Bytes */
#define TCNT5                           _SFR_MEM16(0x124)
#define TCNT5L                          _SFR_MEM8(0x124)
#define TCNT5H                          _SFR_MEM8(0x125)

/* Timer/Counter5 Input Capture Register  Bytes */
#define ICR5                            _SFR_MEM16(0x126)
#define ICR5L                           _SFR_MEM8(0x126)
#define ICR5H                           _SFR_MEM8(0x127)

/* Timer/Counter5 Output Compare Register A  Bytes */
#define OCR5A                           _SFR_MEM16(0x128)
#define OCR5AL                          _SFR_MEM8(0x128)
#define OCR5AH                          _SFR_MEM8(0x129)

/* Timer/Counter5 Output Compare Register B  Bytes */
#define OCR5B                           _SFR_MEM16(0x12A)
#define OCR5BL                          _SFR_MEM8(0x12A)
#define OCR5BH                          _SFR_MEM8(0x12B)

/* Timer/Counter5 Output Compare Register C  Bytes */
#define OCR5C                           _SFR_MEM16(0x12C)
#define OCR5CL                          _SFR_MEM8(0x12C)
#define OCR5CH                          _SFR_MEM8(0x12D)

/* Low Leakage Voltage Regulator Control Register */
#define LLCR                            _SFR_MEM8(0x12F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_LLCR {
        unsigned int llencal : 1;	/* Enable Automatic Calibration */
        unsigned int llshort : 1;	/* Short Lower Calibration Circuit */
        unsigned int lltco : 1;	/* Temperature Coefficient of Current Source */
        unsigned int llcal : 1;	/* Calibration Active */
        unsigned int llcomp : 1;	/* Comparator Output */
        unsigned int lldone : 1;	/* Calibration Done */
        unsigned int : 2;
};

#define LLCR_struct _SFR_MEM8_STRUCT(0x12f, struct __reg_LLCR)

#endif /* __ASSEMBLER__ */

  /* LLCR */

#define LLENCAL                         0
#define LLSHORT                         1
#define LLTCO                           2
#define LLCAL                           3
#define LLCOMP                          4
#define LLDONE                          5

/* Low Leakage Voltage Regulator Data Register (Low-Byte) */
#define LLDRL                           _SFR_MEM8(0x130)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_LLDRL {
        unsigned int lldrl : 4;	/* Low-Byte Data Register Bits */
        unsigned int : 4;
};

#define LLDRL_struct _SFR_MEM8_STRUCT(0x130, struct __reg_LLDRL)

#endif /* __ASSEMBLER__ */

  /* LLDRL */

#define LLDRL0                          0
#define LLDRL1                          1
#define LLDRL2                          2
#define LLDRL3                          3

/* Low Leakage Voltage Regulator Data Register (High-Byte) */
#define LLDRH                           _SFR_MEM8(0x131)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_LLDRH {
        unsigned int lldrh : 5;	/* High-Byte Data Register Bits */
        unsigned int : 3;
};

#define LLDRH_struct _SFR_MEM8_STRUCT(0x131, struct __reg_LLDRH)

#endif /* __ASSEMBLER__ */

  /* LLDRH */

#define LLDRH0                          0
#define LLDRH1                          1
#define LLDRH2                          2
#define LLDRH3                          3
#define LLDRH4                          4

/* Data Retention Configuration Register of SRAM 3 */
#define DRTRAM3                         _SFR_MEM8(0x132)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DRTRAM3 {
        unsigned int : 4;
        unsigned int endrt : 1;	/* Enable SRAM Data Retention */
        unsigned int drtswok : 1;	/* DRT Switch OK */
        unsigned int : 2;
};

#define DRTRAM3_struct _SFR_MEM8_STRUCT(0x132, struct __reg_DRTRAM3)

#endif /* __ASSEMBLER__ */

  /* DRTRAM3 */

#define ENDRT                           4
#define DRTSWOK                         5

/* Data Retention Configuration Register of SRAM 2 */
#define DRTRAM2                         _SFR_MEM8(0x133)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DRTRAM2 {
        unsigned int : 4;
        unsigned int endrt : 1;	/* Enable SRAM Data Retention */
        unsigned int drtswok : 1;	/* DRT Switch OK */
        unsigned int : 2;
};

#define DRTRAM2_struct _SFR_MEM8_STRUCT(0x133, struct __reg_DRTRAM2)

#endif /* __ASSEMBLER__ */

  /* DRTRAM2 */

#define ENDRT                           4
#define DRTSWOK                         5

/* Data Retention Configuration Register of SRAM 1 */
#define DRTRAM1                         _SFR_MEM8(0x134)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DRTRAM1 {
        unsigned int : 4;
        unsigned int endrt : 1;	/* Enable SRAM Data Retention */
        unsigned int drtswok : 1;	/* DRT Switch OK */
        unsigned int : 2;
};

#define DRTRAM1_struct _SFR_MEM8_STRUCT(0x134, struct __reg_DRTRAM1)

#endif /* __ASSEMBLER__ */

  /* DRTRAM1 */

#define ENDRT                           4
#define DRTSWOK                         5

/* Data Retention Configuration Register of SRAM 0 */
#define DRTRAM0                         _SFR_MEM8(0x135)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DRTRAM0 {
        unsigned int : 4;
        unsigned int endrt : 1;	/* Enable SRAM Data Retention */
        unsigned int drtswok : 1;	/* DRT Switch OK */
        unsigned int : 2;
};

#define DRTRAM0_struct _SFR_MEM8_STRUCT(0x135, struct __reg_DRTRAM0)

#endif /* __ASSEMBLER__ */

  /* DRTRAM0 */

#define ENDRT                           4
#define DRTSWOK                         5

/* Port Driver Strength Register 0 */
#define DPDS0                           _SFR_MEM8(0x136)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DPDS0 {
        unsigned int pbdrv : 2;	/* Driver Strength Port B */
        unsigned int pddrv : 2;	/* Driver Strength Port D */
        unsigned int pedrv : 2;	/* Driver Strength Port E */
        unsigned int pfdrv : 2;	/* Driver Strength Port F */
};

#define DPDS0_struct _SFR_MEM8_STRUCT(0x136, struct __reg_DPDS0)

#endif /* __ASSEMBLER__ */

  /* DPDS0 */

#define PBDRV0                          0
#define PBDRV1                          1
#define PDDRV0                          2
#define PDDRV1                          3
#define PEDRV0                          4
#define PEDRV1                          5
#define PFDRV0                          6
#define PFDRV1                          7

/* Port Driver Strength Register 1 */
#define DPDS1                           _SFR_MEM8(0x137)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_DPDS1 {
        unsigned int pgdrv : 2;	/* Driver Strength Port G */
        unsigned int : 6;
};

#define DPDS1_struct _SFR_MEM8_STRUCT(0x137, struct __reg_DPDS1)

#endif /* __ASSEMBLER__ */

  /* DPDS1 */

#define PGDRV0                          0
#define PGDRV1                          1

/* Transceiver Pin Register */
#define TRXPR                           _SFR_MEM8(0x139)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TRXPR {
        unsigned int trxrst : 1;	/* Force Transceiver Reset */
        unsigned int slptr : 1;	/* Multi-purpose Transceiver Control Bit */
        unsigned int : 6;
};

#define TRXPR_struct _SFR_MEM8_STRUCT(0x139, struct __reg_TRXPR)

#endif /* __ASSEMBLER__ */

  /* TRXPR */

#define TRXRST                          0
#define SLPTR                           1

/* AES Control Register */
#define AES_CTRL                        _SFR_MEM8(0x13C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_AES_CTRL {
        unsigned int : 2;
        unsigned int aes_im : 1;	/* AES Interrupt Enable */
        unsigned int aes_dir : 1;	/* Set AES Operation Direction */
        unsigned int : 1;
        unsigned int aes_mode : 1;	/* Set AES Operation Mode */
        unsigned int : 1;
        unsigned int aes_request : 1;	/* Request AES Operation. */
};

#define AES_CTRL_struct _SFR_MEM8_STRUCT(0x13c, struct __reg_AES_CTRL)

/* symbolic names */

#define AES_DIR_ENC                     0
#define AES_DIR_DEC                     1
#define AES_MODE_ECB                    0
#define AES_MODE_CBC                    1

#endif /* __ASSEMBLER__ */

  /* AES_CTRL */

#define AES_IM                          2
#define AES_DIR                         3
#define AES_MODE                        5
#define AES_REQUEST                     7

/* AES Status Register */
#define AES_STATUS                      _SFR_MEM8(0x13D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_AES_STATUS {
        unsigned int aes_done : 1;	/* AES Operation Finished with Success */
        unsigned int : 6;
        unsigned int aes_er : 1;	/* AES Operation Finished with Error */
};

#define AES_STATUS_struct _SFR_MEM8_STRUCT(0x13d, struct __reg_AES_STATUS)

#endif /* __ASSEMBLER__ */

  /* AES_STATUS */

#define AES_DONE                        0
#define AES_ER                          7

/* AES Plain and Cipher Text Buffer Register */
#define AES_STATE                       _SFR_MEM8(0x13E)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_AES_STATE {
        unsigned int aes_state : 8;	/* AES Plain and Cipher Text Buffer */
};

#define AES_STATE_struct _SFR_MEM8_STRUCT(0x13e, struct __reg_AES_STATE)

#endif /* __ASSEMBLER__ */

  /* AES_STATE */

#define AES_STATE0                      0
#define AES_STATE1                      1
#define AES_STATE2                      2
#define AES_STATE3                      3
#define AES_STATE4                      4
#define AES_STATE5                      5
#define AES_STATE6                      6
#define AES_STATE7                      7

/* AES Encryption and Decryption Key Buffer Register */
#define AES_KEY                         _SFR_MEM8(0x13F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_AES_KEY {
        unsigned int aes_key : 8;	/* AES Encryption/Decryption Key Buffer */
};

#define AES_KEY_struct _SFR_MEM8_STRUCT(0x13f, struct __reg_AES_KEY)

#endif /* __ASSEMBLER__ */

  /* AES_KEY */

#define AES_KEY0                        0
#define AES_KEY1                        1
#define AES_KEY2                        2
#define AES_KEY3                        3
#define AES_KEY4                        4
#define AES_KEY5                        5
#define AES_KEY6                        6
#define AES_KEY7                        7

/* Transceiver Status Register */
#define TRX_STATUS                      _SFR_MEM8(0x141)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TRX_STATUS {
        unsigned int trx_status : 5;	/* Transceiver Main Status */
        unsigned int tst_status : 1;	/* Test mode status */
        unsigned int cca_status : 1;	/* CCA Status Result */
        unsigned int cca_done : 1;	/* CCA Algorithm Status */
};

#define TRX_STATUS_struct _SFR_MEM8_STRUCT(0x141, struct __reg_TRX_STATUS)

/* symbolic names */

#define P_ON                            0
#define BUSY_RX                         1
#define BUSY_TX                         2
#define RX_ON                           6
#define TRX_OFF                         8
#define PLL_ON                          9
#define SLEEP                           15
#define BUSY_RX_AACK                    17
#define BUSY_TX_ARET                    18
#define RX_AACK_ON                      22
#define TX_ARET_ON                      25
#define STATE_TRANSITION_IN_PROGRESS    31
#define TST_DISABLED                    0
#define TST_ENABLED                     1
#define CCA_BUSY                        0
#define CCA_IDLE                        1
#define CCA_NOT_FIN                     0
#define CCA_FIN                         1

#endif /* __ASSEMBLER__ */

  /* TRX_STATUS */

#define TRX_STATUS0                     0
#define TRX_STATUS1                     1
#define TRX_STATUS2                     2
#define TRX_STATUS3                     3
#define TRX_STATUS4                     4
#define TST_STATUS                      5
#define CCA_STATUS                      6
#define CCA_DONE                        7

/* Transceiver State Control Register */
#define TRX_STATE                       _SFR_MEM8(0x142)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TRX_STATE {
        unsigned int trx_cmd : 5;	/* State Control Command */
        unsigned int trac_status : 3;	/* Transaction Status */
};

#define TRX_STATE_struct _SFR_MEM8_STRUCT(0x142, struct __reg_TRX_STATE)

/* symbolic names */

#define CMD_NOP                         0
#define CMD_TX_START                    2
#define CMD_FORCE_TRX_OFF               3
#define CMD_FORCE_PLL_ON                4
#define CMD_RX_ON                       6
#define CMD_TRX_OFF                     8
#define CMD_PLL_ON                      9
#define CMD_RX_AACK_ON                  22
#define CMD_TX_ARET_ON                  25
#define TRAC_SUCCESS                    0
#define TRAC_SUCCESS_DATA_PENDING       1
#define TRAC_SUCCESS_WAIT_FOR_ACK       2
#define TRAC_CHANNEL_ACCESS_FAILURE     3
#define TRAC_NO_ACK                     5
#define TRAC_INVALID                    7

#endif /* __ASSEMBLER__ */

  /* TRX_STATE */

#define TRX_CMD0                        0
#define TRX_CMD1                        1
#define TRX_CMD2                        2
#define TRX_CMD3                        3
#define TRX_CMD4                        4
#define TRAC_STATUS0                    5
#define TRAC_STATUS1                    6
#define TRAC_STATUS2                    7

/* Reserved */
#define TRX_CTRL_0                      _SFR_MEM8(0x143)

/* Transceiver Control Register 1 */
#define TRX_CTRL_1                      _SFR_MEM8(0x144)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TRX_CTRL_1 {
        unsigned int : 5;
        unsigned int tx_auto_crc_on : 1;	/* Enable Automatic CRC Calculation */
        unsigned int irq_2_ext_en : 1;	/* Connect Frame Start IRQ to TC1 */
        unsigned int pa_ext_en : 1;	/* External PA support enable */
};

#define TRX_CTRL_1_struct _SFR_MEM8_STRUCT(0x144, struct __reg_TRX_CTRL_1)

#endif /* __ASSEMBLER__ */

  /* TRX_CTRL_1 */

#define TX_AUTO_CRC_ON                  5
#define IRQ_2_EXT_EN                    6
#define PA_EXT_EN                       7

/* Transceiver Transmit Power Control Register */
#define PHY_TX_PWR                      _SFR_MEM8(0x145)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PHY_TX_PWR {
        unsigned int tx_pwr : 4;	/* Transmit Power Setting */
        unsigned int pa_lt : 2;	/* Power Amplifier Lead Time */
        unsigned int pa_buf_lt : 2;	/* Power Amplifier Buffer Lead Time */
};

#define PHY_TX_PWR_struct _SFR_MEM8_STRUCT(0x145, struct __reg_PHY_TX_PWR)

/* symbolic names */

#define PA_LT_2US                       0
#define PA_LT_4US                       1
#define PA_LT_6US                       2
#define PA_LT_8US                       3
#define PA_BUF_LT_0US                   0
#define PA_BUF_LT_2US                   1
#define PA_BUF_LT_4US                   2
#define PA_BUF_LT_6US                   3

#endif /* __ASSEMBLER__ */

  /* PHY_TX_PWR */

#define TX_PWR0                         0
#define TX_PWR1                         1
#define TX_PWR2                         2
#define TX_PWR3                         3
#define PA_LT0                          4
#define PA_LT1                          5
#define PA_BUF_LT0                      6
#define PA_BUF_LT1                      7

/* Receiver Signal Strength Indicator Register */
#define PHY_RSSI                        _SFR_MEM8(0x146)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PHY_RSSI {
        unsigned int rssi : 5;	/* Receiver Signal Strength Indicator */
        unsigned int rnd_value : 2;	/* Random Value */
        unsigned int rx_crc_valid : 1;	/* Received Frame CRC Status */
};

#define PHY_RSSI_struct _SFR_MEM8_STRUCT(0x146, struct __reg_PHY_RSSI)

/* symbolic names */

#define RSSI_MIN                        0
#define RSSI_MIN_PLUS_3dB               1
#define RSSI_MAX                        28
#define CRC_INVALID                     0
#define CRC_VALID                       1

#endif /* __ASSEMBLER__ */

  /* PHY_RSSI */

#define RSSI0                           0
#define RSSI1                           1
#define RSSI2                           2
#define RSSI3                           3
#define RSSI4                           4
#define RND_VALUE0                      5
#define RND_VALUE1                      6
#define RX_CRC_VALID                    7

/* Transceiver Energy Detection Level Register */
#define PHY_ED_LEVEL                    _SFR_MEM8(0x147)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PHY_ED_LEVEL {
        unsigned int ed_level : 8;	/* Energy Detection Level */
};

#define PHY_ED_LEVEL_struct _SFR_MEM8_STRUCT(0x147, struct __reg_PHY_ED_LEVEL)

/* symbolic names */

#define ED_MIN                          0
#define ED_MIN_PLUS_1dB                 1
#define ED_MAX                          84
#define ED_RESET                        255

#endif /* __ASSEMBLER__ */

  /* PHY_ED_LEVEL */

#define ED_LEVEL0                       0
#define ED_LEVEL1                       1
#define ED_LEVEL2                       2
#define ED_LEVEL3                       3
#define ED_LEVEL4                       4
#define ED_LEVEL5                       5
#define ED_LEVEL6                       6
#define ED_LEVEL7                       7

/* Transceiver Clear Channel Assessment (CCA) Control Register */
#define PHY_CC_CCA                      _SFR_MEM8(0x148)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PHY_CC_CCA {
        unsigned int channel : 5;	/* RX/TX Channel Selection */
        unsigned int cca_mode : 2;	/* Select CCA Measurement Mode */
        unsigned int cca_request : 1;	/* Manual CCA Measurement Request */
};

#define PHY_CC_CCA_struct _SFR_MEM8_STRUCT(0x148, struct __reg_PHY_CC_CCA)

/* symbolic names */

#define F_2405MHZ                       11
#define F_2410MHZ                       12
#define F_2415MHZ                       13
#define F_2420MHZ                       14
#define F_2425MHZ                       15
#define F_2430MHZ                       16
#define F_2435MHZ                       17
#define F_2440MHZ                       18
#define F_2445MHZ                       19
#define F_2450MHZ                       20
#define F_2455MHZ                       21
#define F_2460MHZ                       22
#define F_2465MHZ                       23
#define F_2470MHZ                       24
#define F_2475MHZ                       25
#define F_2480MHZ                       26
#define CCA_CS_OR_ED                    0
#define CCA_ED                          1
#define CCA_CS                          2
#define CCA_CS_AND_ED                   3

#endif /* __ASSEMBLER__ */

  /* PHY_CC_CCA */

#define CHANNEL0                        0
#define CHANNEL1                        1
#define CHANNEL2                        2
#define CHANNEL3                        3
#define CHANNEL4                        4
#define CCA_MODE0                       5
#define CCA_MODE1                       6
#define CCA_REQUEST                     7

/* Transceiver CCA Threshold Setting Register */
#define CCA_THRES                       _SFR_MEM8(0x149)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_CCA_THRES {
        unsigned int cca_ed_thres : 4;	/* ED Threshold Level for CCA Measurement */
        unsigned int cca_cs_thres : 4;	/* CS Threshold Level for CCA Measurement */
};

#define CCA_THRES_struct _SFR_MEM8_STRUCT(0x149, struct __reg_CCA_THRES)

#endif /* __ASSEMBLER__ */

  /* CCA_THRES */

#define CCA_ED_THRES0                   0
#define CCA_ED_THRES1                   1
#define CCA_ED_THRES2                   2
#define CCA_ED_THRES3                   3
#define CCA_CS_THRES0                   4
#define CCA_CS_THRES1                   5
#define CCA_CS_THRES2                   6
#define CCA_CS_THRES3                   7

/* Transceiver Receive Control Register */
#define RX_CTRL                         _SFR_MEM8(0x14A)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_RX_CTRL {
        unsigned int pdt_thres : 4;	/* Receiver Sensitivity Control */
        unsigned int : 4;
};

#define RX_CTRL_struct _SFR_MEM8_STRUCT(0x14a, struct __reg_RX_CTRL)

/* symbolic names */

#define PDT_THRES_ANT_DIV_OFF           7
#define PDT_THRES_ANT_DIV_ON            3

#endif /* __ASSEMBLER__ */

  /* RX_CTRL */

#define PDT_THRES0                      0
#define PDT_THRES1                      1
#define PDT_THRES2                      2
#define PDT_THRES3                      3

/* Start of Frame Delimiter Value Register */
#define SFD_VALUE                       _SFR_MEM8(0x14B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SFD_VALUE {
        unsigned int sfd_value : 8;	/* Start of Frame Delimiter Value */
};

#define SFD_VALUE_struct _SFR_MEM8_STRUCT(0x14b, struct __reg_SFD_VALUE)

/* symbolic names */

#define IEEE_SFD                        167

#endif /* __ASSEMBLER__ */

  /* SFD_VALUE */

#define SFD_VALUE0                      0
#define SFD_VALUE1                      1
#define SFD_VALUE2                      2
#define SFD_VALUE3                      3
#define SFD_VALUE4                      4
#define SFD_VALUE5                      5
#define SFD_VALUE6                      6
#define SFD_VALUE7                      7

/* Transceiver Control Register 2 */
#define TRX_CTRL_2                      _SFR_MEM8(0x14C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TRX_CTRL_2 {
        unsigned int oqpsk_data_rate : 2;	/* Data Rate Selection */
        unsigned int : 5;
        unsigned int rx_safe_mode : 1;	/* RX Safe Mode */
};

#define TRX_CTRL_2_struct _SFR_MEM8_STRUCT(0x14c, struct __reg_TRX_CTRL_2)

/* symbolic names */

#define RATE_250KB                      0
#define RATE_500KB                      1
#define RATE_1000KB                     2
#define RATE_2000KB                     3

#endif /* __ASSEMBLER__ */

  /* TRX_CTRL_2 */

#define OQPSK_DATA_RATE0                0
#define OQPSK_DATA_RATE1                1
#define RX_SAFE_MODE                    7

/* Antenna Diversity Control Register */
#define ANT_DIV                         _SFR_MEM8(0x14D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_ANT_DIV {
        unsigned int ant_ctrl : 2;	/* Static Antenna Diversity Switch Control */
        unsigned int ant_ext_sw_en : 1;	/* Enable External Antenna Switch Control */
        unsigned int ant_div_en : 1;	/* Enable Antenna Diversity */
        unsigned int : 3;
        unsigned int ant_sel : 1;	/* Antenna Diversity Antenna Status */
};

#define ANT_DIV_struct _SFR_MEM8_STRUCT(0x14d, struct __reg_ANT_DIV)

/* symbolic names */

#define ANT_1                           1
#define ANT_0                           2
#define ANT_RESET                       3
#define ANT_DIV_EXT_SW_DIS              0
#define ANT_DIV_EXT_SW_EN               1
#define ANTENNA_0                       0
#define ANTENNA_1                       1

#endif /* __ASSEMBLER__ */

  /* ANT_DIV */

#define ANT_CTRL0                       0
#define ANT_CTRL1                       1
#define ANT_EXT_SW_EN                   2
#define ANT_DIV_EN                      3
#define ANT_SEL                         7

/* Transceiver Interrupt Enable Register */
#define IRQ_MASK                        _SFR_MEM8(0x14E)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IRQ_MASK {
        unsigned int pll_lock_en : 1;	/* PLL Lock Interrupt Enable */
        unsigned int pll_unlock_en : 1;	/* PLL Unlock Interrupt Enable */
        unsigned int rx_start_en : 1;	/* RX_START Interrupt Enable */
        unsigned int rx_end_en : 1;	/* RX_END Interrupt Enable */
        unsigned int cca_ed_done_en : 1;	/* End of ED Measurement Interrupt Enable */
        unsigned int ami_en : 1;	/* Address Match Interrupt Enable */
        unsigned int tx_end_en : 1;	/* TX_END Interrupt Enable */
        unsigned int awake_en : 1;	/* Awake Interrupt Enable */
};

#define IRQ_MASK_struct _SFR_MEM8_STRUCT(0x14e, struct __reg_IRQ_MASK)

#endif /* __ASSEMBLER__ */

  /* IRQ_MASK */

#define PLL_LOCK_EN                     0
#define PLL_UNLOCK_EN                   1
#define RX_START_EN                     2
#define RX_END_EN                       3
#define CCA_ED_DONE_EN                  4
#define AMI_EN                          5
#define TX_END_EN                       6
#define AWAKE_EN                        7

/* Transceiver Interrupt Status Register */
#define IRQ_STATUS                      _SFR_MEM8(0x14F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IRQ_STATUS {
        unsigned int pll_lock : 1;	/* PLL Lock Interrupt Status */
        unsigned int pll_unlock : 1;	/* PLL Unlock Interrupt Status */
        unsigned int rx_start : 1;	/* RX_START Interrupt Status */
        unsigned int rx_end : 1;	/* RX_END Interrupt Status */
        unsigned int cca_ed_done : 1;	/* End of ED Measurement Interrupt Status */
        unsigned int ami : 1;	/* Address Match Interrupt Status */
        unsigned int tx_end : 1;	/* TX_END Interrupt Status */
        unsigned int awake : 1;	/* Awake Interrupt Status */
};

#define IRQ_STATUS_struct _SFR_MEM8_STRUCT(0x14f, struct __reg_IRQ_STATUS)

#endif /* __ASSEMBLER__ */

  /* IRQ_STATUS */

#define PLL_LOCK                        0
#define PLL_UNLOCK                      1
#define RX_START                        2
#define RX_END                          3
#define CCA_ED_DONE                     4
#define AMI                             5
#define TX_END                          6
#define AWAKE                           7

/* Voltage Regulator Control and Status Register */
#define VREG_CTRL                       _SFR_MEM8(0x150)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_VREG_CTRL {
        unsigned int : 2;
        unsigned int dvdd_ok : 1;	/* DVDD Supply Voltage Valid */
        unsigned int dvreg_ext : 1;	/* Use External DVDD Regulator */
        unsigned int : 2;
        unsigned int avdd_ok : 1;	/* AVDD Supply Voltage Valid */
        unsigned int avreg_ext : 1;	/* Use External AVDD Regulator */
};

#define VREG_CTRL_struct _SFR_MEM8_STRUCT(0x150, struct __reg_VREG_CTRL)

/* symbolic names */

#define DVDD_INT                        0
#define DVDD_EXT                        1
#define AVDD_INT                        0
#define AVDD_EXT                        1

#endif /* __ASSEMBLER__ */

  /* VREG_CTRL */

#define DVDD_OK                         2
#define DVREG_EXT                       3
#define AVDD_OK                         6
#define AVREG_EXT                       7

/* Battery Monitor Control and Status Register */
#define BATMON                          _SFR_MEM8(0x151)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_BATMON {
        unsigned int batmon_vth : 4;	/* Battery Monitor Threshold Voltage */
        unsigned int batmon_hr : 1;	/* Battery Monitor Voltage Range */
        unsigned int batmon_ok : 1;	/* Battery Monitor Status */
        unsigned int bat_low_en : 1;	/* Battery Monitor Interrupt Enable */
        unsigned int bat_low : 1;	/* Battery Monitor Interrupt Status */
};

#define BATMON_struct _SFR_MEM8_STRUCT(0x151, struct __reg_BATMON)

/* symbolic names */

#define BATMON_HR_DIS                   0
#define BATMON_HR_EN                    1

#endif /* __ASSEMBLER__ */

  /* BATMON */

#define BATMON_VTH0                     0
#define BATMON_VTH1                     1
#define BATMON_VTH2                     2
#define BATMON_VTH3                     3
#define BATMON_HR                       4
#define BATMON_OK                       5
#define BAT_LOW_EN                      6
#define BAT_LOW                         7

/* Crystal Oscillator Control Register */
#define XOSC_CTRL                       _SFR_MEM8(0x152)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_XOSC_CTRL {
        unsigned int xtal_trim : 4;	/* Crystal Oscillator Load Capacitance Trimming */
        unsigned int xtal_mode : 4;	/* Crystal Oscillator Operating Mode */
};

#define XOSC_CTRL_struct _SFR_MEM8_STRUCT(0x152, struct __reg_XOSC_CTRL)

/* symbolic names */

#define XTAL_TRIM_MIN                   0
#define XTAL_TRIM_MAX                   15

#endif /* __ASSEMBLER__ */

  /* XOSC_CTRL */

#define XTAL_TRIM0                      0
#define XTAL_TRIM1                      1
#define XTAL_TRIM2                      2
#define XTAL_TRIM3                      3
#define XTAL_MODE0                      4
#define XTAL_MODE1                      5
#define XTAL_MODE2                      6
#define XTAL_MODE3                      7

/* Transceiver Receiver Sensitivity Control Register */
#define RX_SYN                          _SFR_MEM8(0x155)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_RX_SYN {
        unsigned int rx_pdt_level : 4;	/* Reduce Receiver Sensitivity */
        unsigned int : 3;
        unsigned int rx_pdt_dis : 1;	/* Prevent Frame Reception */
};

#define RX_SYN_struct _SFR_MEM8_STRUCT(0x155, struct __reg_RX_SYN)

/* symbolic names */

#define RX_PDT_LEVEL_MIN                0
#define RX_PDT_LEVEL_MAX                15

#endif /* __ASSEMBLER__ */

  /* RX_SYN */

#define RX_PDT_LEVEL0                   0
#define RX_PDT_LEVEL1                   1
#define RX_PDT_LEVEL2                   2
#define RX_PDT_LEVEL3                   3
#define RX_PDT_DIS                      7

/* Transceiver Acknowledgment Frame Control Register 1 */
#define XAH_CTRL_1                      _SFR_MEM8(0x157)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_XAH_CTRL_1 {
        unsigned int : 1;
        unsigned int aack_prom_mode : 1;	/* Enable Promiscuous Mode */
        unsigned int aack_ack_time : 1;	/* Reduce Acknowledgment Time */
        unsigned int : 1;
        unsigned int aack_upld_res_ft : 1;	/* Process Reserved Frames */
        unsigned int aack_fltr_res_ft : 1;	/* Filter Reserved Frames */
        unsigned int : 2;
};

#define XAH_CTRL_1_struct _SFR_MEM8_STRUCT(0x157, struct __reg_XAH_CTRL_1)

/* symbolic names */

#define AACK_ACK_TIME_12_SYM            0
#define AACK_ACK_TIME_2_SYM             1

#endif /* __ASSEMBLER__ */

  /* XAH_CTRL_1 */

#define AACK_PROM_MODE                  1
#define AACK_ACK_TIME                   2
#define AACK_UPLD_RES_FT                4
#define AACK_FLTR_RES_FT                5

/* Transceiver Filter Tuning Control Register */
#define FTN_CTRL                        _SFR_MEM8(0x158)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_FTN_CTRL {
        unsigned int : 7;
        unsigned int ftn_start : 1;	/* Start Calibration Loop of Filter Tuning Network */
};

#define FTN_CTRL_struct _SFR_MEM8_STRUCT(0x158, struct __reg_FTN_CTRL)

#endif /* __ASSEMBLER__ */

  /* FTN_CTRL */

#define FTN_START                       7

/* Transceiver Center Frequency Calibration Control Register */
#define PLL_CF                          _SFR_MEM8(0x15A)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PLL_CF {
        unsigned int : 7;
        unsigned int pll_cf_start : 1;	/* Start Center Frequency Calibration */
};

#define PLL_CF_struct _SFR_MEM8_STRUCT(0x15a, struct __reg_PLL_CF)

#endif /* __ASSEMBLER__ */

  /* PLL_CF */

#define PLL_CF_START                    7

/* Transceiver Delay Cell Calibration Control Register */
#define PLL_DCU                         _SFR_MEM8(0x15B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PLL_DCU {
        unsigned int : 7;
        unsigned int pll_dcu_start : 1;	/* Start Delay Cell Calibration */
};

#define PLL_DCU_struct _SFR_MEM8_STRUCT(0x15b, struct __reg_PLL_DCU)

#endif /* __ASSEMBLER__ */

  /* PLL_DCU */

#define PLL_DCU_START                   7

/* Device Identification Register (Part Number) */
#define PART_NUM                        _SFR_MEM8(0x15C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PART_NUM {
        unsigned int part_num : 8;	/* Part Number */
};

#define PART_NUM_struct _SFR_MEM8_STRUCT(0x15c, struct __reg_PART_NUM)

/* symbolic names */

#define P_ATmega128RFA1                 131

#endif /* __ASSEMBLER__ */

  /* PART_NUM */

#define PART_NUM0                       0
#define PART_NUM1                       1
#define PART_NUM2                       2
#define PART_NUM3                       3
#define PART_NUM4                       4
#define PART_NUM5                       5
#define PART_NUM6                       6
#define PART_NUM7                       7

/* Device Identification Register (Version Number) */
#define VERSION_NUM                     _SFR_MEM8(0x15D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_VERSION_NUM {
        unsigned int version_num : 8;	/* Version Number */
};

#define VERSION_NUM_struct _SFR_MEM8_STRUCT(0x15d, struct __reg_VERSION_NUM)

/* symbolic names */

#define REV_A                           2
#define REV_B                           3

#endif /* __ASSEMBLER__ */

  /* VERSION_NUM */

#define VERSION_NUM0                    0
#define VERSION_NUM1                    1
#define VERSION_NUM2                    2
#define VERSION_NUM3                    3
#define VERSION_NUM4                    4
#define VERSION_NUM5                    5
#define VERSION_NUM6                    6
#define VERSION_NUM7                    7

/* Device Identification Register (Manufacture ID Low Byte) */
#define MAN_ID_0                        _SFR_MEM8(0x15E)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_MAN_ID_0 {
        unsigned int man_id_0 : 8;	/* Manufacturer ID (Low Byte) */
};

#define MAN_ID_0_struct _SFR_MEM8_STRUCT(0x15e, struct __reg_MAN_ID_0)

/* symbolic names */

#define ATMEL_BYTE_0                    31

#endif /* __ASSEMBLER__ */

  /* MAN_ID_0 */

#define MAN_ID_00                       0
#define MAN_ID_01                       1
#define MAN_ID_02                       2
#define MAN_ID_03                       3
#define MAN_ID_04                       4
#define MAN_ID_05                       5
#define MAN_ID_06                       6
#define MAN_ID_07                       7

/* Device Identification Register (Manufacture ID High Byte) */
#define MAN_ID_1                        _SFR_MEM8(0x15F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_MAN_ID_1 {
        unsigned int man_id_1 : 8;	/* Manufacturer ID (High Byte) */
};

#define MAN_ID_1_struct _SFR_MEM8_STRUCT(0x15f, struct __reg_MAN_ID_1)

/* symbolic names */

#define ATMEL_BYTE_1                    0

#endif /* __ASSEMBLER__ */

  /* MAN_ID_1 */

#define MAN_ID_10                       0
#define MAN_ID_11                       1
#define MAN_ID_12                       2
#define MAN_ID_13                       3
#define MAN_ID_14                       4
#define MAN_ID_15                       5
#define MAN_ID_16                       6
#define MAN_ID_17                       7

/* Transceiver MAC Short Address Register (Low Byte) */
#define SHORT_ADDR_0                    _SFR_MEM8(0x160)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SHORT_ADDR_0 {
        unsigned int short_addr_0 : 8;	/* MAC Short Address */
};

#define SHORT_ADDR_0_struct _SFR_MEM8_STRUCT(0x160, struct __reg_SHORT_ADDR_0)

#endif /* __ASSEMBLER__ */

  /* SHORT_ADDR_0 */

#define SHORT_ADDR_00                   0
#define SHORT_ADDR_01                   1
#define SHORT_ADDR_02                   2
#define SHORT_ADDR_03                   3
#define SHORT_ADDR_04                   4
#define SHORT_ADDR_05                   5
#define SHORT_ADDR_06                   6
#define SHORT_ADDR_07                   7

/* Transceiver MAC Short Address Register (High Byte) */
#define SHORT_ADDR_1                    _SFR_MEM8(0x161)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_SHORT_ADDR_1 {
        unsigned int short_addr_1 : 8;	/* MAC Short Address */
};

#define SHORT_ADDR_1_struct _SFR_MEM8_STRUCT(0x161, struct __reg_SHORT_ADDR_1)

#endif /* __ASSEMBLER__ */

  /* SHORT_ADDR_1 */

#define SHORT_ADDR_10                   0
#define SHORT_ADDR_11                   1
#define SHORT_ADDR_12                   2
#define SHORT_ADDR_13                   3
#define SHORT_ADDR_14                   4
#define SHORT_ADDR_15                   5
#define SHORT_ADDR_16                   6
#define SHORT_ADDR_17                   7

/* Transceiver Personal Area Network ID Register (Low Byte) */
#define PAN_ID_0                        _SFR_MEM8(0x162)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PAN_ID_0 {
        unsigned int pan_id_0 : 8;	/* MAC Personal Area Network ID */
};

#define PAN_ID_0_struct _SFR_MEM8_STRUCT(0x162, struct __reg_PAN_ID_0)

#endif /* __ASSEMBLER__ */

  /* PAN_ID_0 */

#define PAN_ID_00                       0
#define PAN_ID_01                       1
#define PAN_ID_02                       2
#define PAN_ID_03                       3
#define PAN_ID_04                       4
#define PAN_ID_05                       5
#define PAN_ID_06                       6
#define PAN_ID_07                       7

/* Transceiver Personal Area Network ID Register (High Byte) */
#define PAN_ID_1                        _SFR_MEM8(0x163)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_PAN_ID_1 {
        unsigned int pan_id_1 : 8;	/* MAC Personal Area Network ID */
};

#define PAN_ID_1_struct _SFR_MEM8_STRUCT(0x163, struct __reg_PAN_ID_1)

#endif /* __ASSEMBLER__ */

  /* PAN_ID_1 */

#define PAN_ID_10                       0
#define PAN_ID_11                       1
#define PAN_ID_12                       2
#define PAN_ID_13                       3
#define PAN_ID_14                       4
#define PAN_ID_15                       5
#define PAN_ID_16                       6
#define PAN_ID_17                       7

/* Transceiver MAC IEEE Address Register 0 */
#define IEEE_ADDR_0                     _SFR_MEM8(0x164)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_0 {
        unsigned int ieee_addr_0 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_0_struct _SFR_MEM8_STRUCT(0x164, struct __reg_IEEE_ADDR_0)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_0 */

#define IEEE_ADDR_00                    0
#define IEEE_ADDR_01                    1
#define IEEE_ADDR_02                    2
#define IEEE_ADDR_03                    3
#define IEEE_ADDR_04                    4
#define IEEE_ADDR_05                    5
#define IEEE_ADDR_06                    6
#define IEEE_ADDR_07                    7

/* Transceiver MAC IEEE Address Register 1 */
#define IEEE_ADDR_1                     _SFR_MEM8(0x165)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_1 {
        unsigned int ieee_addr_1 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_1_struct _SFR_MEM8_STRUCT(0x165, struct __reg_IEEE_ADDR_1)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_1 */

#define IEEE_ADDR_10                    0
#define IEEE_ADDR_11                    1
#define IEEE_ADDR_12                    2
#define IEEE_ADDR_13                    3
#define IEEE_ADDR_14                    4
#define IEEE_ADDR_15                    5
#define IEEE_ADDR_16                    6
#define IEEE_ADDR_17                    7

/* Transceiver MAC IEEE Address Register 2 */
#define IEEE_ADDR_2                     _SFR_MEM8(0x166)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_2 {
        unsigned int ieee_addr_2 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_2_struct _SFR_MEM8_STRUCT(0x166, struct __reg_IEEE_ADDR_2)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_2 */

#define IEEE_ADDR_20                    0
#define IEEE_ADDR_21                    1
#define IEEE_ADDR_22                    2
#define IEEE_ADDR_23                    3
#define IEEE_ADDR_24                    4
#define IEEE_ADDR_25                    5
#define IEEE_ADDR_26                    6
#define IEEE_ADDR_27                    7

/* Transceiver MAC IEEE Address Register 3 */
#define IEEE_ADDR_3                     _SFR_MEM8(0x167)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_3 {
        unsigned int ieee_addr_3 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_3_struct _SFR_MEM8_STRUCT(0x167, struct __reg_IEEE_ADDR_3)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_3 */

#define IEEE_ADDR_30                    0
#define IEEE_ADDR_31                    1
#define IEEE_ADDR_32                    2
#define IEEE_ADDR_33                    3
#define IEEE_ADDR_34                    4
#define IEEE_ADDR_35                    5
#define IEEE_ADDR_36                    6
#define IEEE_ADDR_37                    7

/* Transceiver MAC IEEE Address Register 4 */
#define IEEE_ADDR_4                     _SFR_MEM8(0x168)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_4 {
        unsigned int ieee_addr_4 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_4_struct _SFR_MEM8_STRUCT(0x168, struct __reg_IEEE_ADDR_4)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_4 */

#define IEEE_ADDR_40                    0
#define IEEE_ADDR_41                    1
#define IEEE_ADDR_42                    2
#define IEEE_ADDR_43                    3
#define IEEE_ADDR_44                    4
#define IEEE_ADDR_45                    5
#define IEEE_ADDR_46                    6
#define IEEE_ADDR_47                    7

/* Transceiver MAC IEEE Address Register 5 */
#define IEEE_ADDR_5                     _SFR_MEM8(0x169)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_5 {
        unsigned int ieee_addr_5 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_5_struct _SFR_MEM8_STRUCT(0x169, struct __reg_IEEE_ADDR_5)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_5 */

#define IEEE_ADDR_50                    0
#define IEEE_ADDR_51                    1
#define IEEE_ADDR_52                    2
#define IEEE_ADDR_53                    3
#define IEEE_ADDR_54                    4
#define IEEE_ADDR_55                    5
#define IEEE_ADDR_56                    6
#define IEEE_ADDR_57                    7

/* Transceiver MAC IEEE Address Register 6 */
#define IEEE_ADDR_6                     _SFR_MEM8(0x16A)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_6 {
        unsigned int ieee_addr_6 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_6_struct _SFR_MEM8_STRUCT(0x16a, struct __reg_IEEE_ADDR_6)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_6 */

#define IEEE_ADDR_60                    0
#define IEEE_ADDR_61                    1
#define IEEE_ADDR_62                    2
#define IEEE_ADDR_63                    3
#define IEEE_ADDR_64                    4
#define IEEE_ADDR_65                    5
#define IEEE_ADDR_66                    6
#define IEEE_ADDR_67                    7

/* Transceiver MAC IEEE Address Register 7 */
#define IEEE_ADDR_7                     _SFR_MEM8(0x16B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_IEEE_ADDR_7 {
        unsigned int ieee_addr_7 : 8;	/* MAC IEEE Address */
};

#define IEEE_ADDR_7_struct _SFR_MEM8_STRUCT(0x16b, struct __reg_IEEE_ADDR_7)

#endif /* __ASSEMBLER__ */

  /* IEEE_ADDR_7 */

#define IEEE_ADDR_70                    0
#define IEEE_ADDR_71                    1
#define IEEE_ADDR_72                    2
#define IEEE_ADDR_73                    3
#define IEEE_ADDR_74                    4
#define IEEE_ADDR_75                    5
#define IEEE_ADDR_76                    6
#define IEEE_ADDR_77                    7

/* Transceiver Extended Operating Mode Control Register */
#define XAH_CTRL_0                      _SFR_MEM8(0x16C)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_XAH_CTRL_0 {
        unsigned int slotted_operation : 1;	/* Set Slotted Acknowledgment */
        unsigned int max_csma_retries : 3;	/* Maximum Number of CSMA-CA Procedure Repetition Attempts */
        unsigned int max_frame_retries : 4;	/* Maximum Number of Frame Re-transmission Attempts */
};

#define XAH_CTRL_0_struct _SFR_MEM8_STRUCT(0x16c, struct __reg_XAH_CTRL_0)

/* symbolic names */

#define SLOTTED_OP_DIS                  0
#define SLOTTED_OP_EN                   1

#endif /* __ASSEMBLER__ */

  /* XAH_CTRL_0 */

#define SLOTTED_OPERATION               0
#define MAX_CSMA_RETRIES0               1
#define MAX_CSMA_RETRIES1               2
#define MAX_CSMA_RETRIES2               3
#define MAX_FRAME_RETRIES0              4
#define MAX_FRAME_RETRIES1              5
#define MAX_FRAME_RETRIES2              6
#define MAX_FRAME_RETRIES3              7

/* Transceiver CSMA-CA Random Number Generator Seed Register */
#define CSMA_SEED_0                     _SFR_MEM8(0x16D)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_CSMA_SEED_0 {
        unsigned int csma_seed_0 : 8;	/* Seed Value for CSMA Random Number Generator */
};

#define CSMA_SEED_0_struct _SFR_MEM8_STRUCT(0x16d, struct __reg_CSMA_SEED_0)

#endif /* __ASSEMBLER__ */

  /* CSMA_SEED_0 */

#define CSMA_SEED_00                    0
#define CSMA_SEED_01                    1
#define CSMA_SEED_02                    2
#define CSMA_SEED_03                    3
#define CSMA_SEED_04                    4
#define CSMA_SEED_05                    5
#define CSMA_SEED_06                    6
#define CSMA_SEED_07                    7

/* Transceiver Acknowledgment Frame Control Register 2 */
#define CSMA_SEED_1                     _SFR_MEM8(0x16E)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_CSMA_SEED_1 {
        unsigned int csma_seed_1 : 3;	/* Seed Value for CSMA Random Number Generator */
        unsigned int aack_i_am_coord : 1;	/* Set Personal Area Network Coordinator */
        unsigned int aack_dis_ack : 1;	/* Disable Acknowledgment Frame Transmission */
        unsigned int aack_set_pd : 1;	/* Set Frame Pending Sub-field */
        unsigned int aack_fvn_mode : 2;	/* Acknowledgment Frame Filter Mode */
};

#define CSMA_SEED_1_struct _SFR_MEM8_STRUCT(0x16e, struct __reg_CSMA_SEED_1)

#endif /* __ASSEMBLER__ */

  /* CSMA_SEED_1 */

#define CSMA_SEED_10                    0
#define CSMA_SEED_11                    1
#define CSMA_SEED_12                    2
#define AACK_I_AM_COORD                 3
#define AACK_DIS_ACK                    4
#define AACK_SET_PD                     5
#define AACK_FVN_MODE0                  6
#define AACK_FVN_MODE1                  7

/* Transceiver CSMA-CA Back-off Exponent Control Register */
#define CSMA_BE                         _SFR_MEM8(0x16F)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_CSMA_BE {
        unsigned int min_be : 4;	/* Minimum Back-off Exponent */
        unsigned int max_be : 4;	/* Maximum Back-off Exponent */
};

#define CSMA_BE_struct _SFR_MEM8_STRUCT(0x16f, struct __reg_CSMA_BE)

#endif /* __ASSEMBLER__ */

  /* CSMA_BE */

#define MIN_BE0                         0
#define MIN_BE1                         1
#define MIN_BE2                         2
#define MIN_BE3                         3
#define MAX_BE0                         4
#define MAX_BE1                         5
#define MAX_BE2                         6
#define MAX_BE3                         7

/* Transceiver Digital Test Control Register */
#define TST_CTRL_DIGI                   _SFR_MEM8(0x176)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TST_CTRL_DIGI {
        unsigned int tst_ctrl_dig : 4;	/* Digital Test Controller Register */
        unsigned int : 4;
};

#define TST_CTRL_DIGI_struct _SFR_MEM8_STRUCT(0x176, struct __reg_TST_CTRL_DIGI)

#endif /* __ASSEMBLER__ */

  /* TST_CTRL_DIGI */

#define TST_CTRL_DIG0                   0
#define TST_CTRL_DIG1                   1
#define TST_CTRL_DIG2                   2
#define TST_CTRL_DIG3                   3

/* Transceiver Received Frame Length Register */
#define TST_RX_LENGTH                   _SFR_MEM8(0x17B)

#if !(defined(__ASSEMBLER__) || defined(__NOSTRUCT__))

struct __reg_TST_RX_LENGTH {
        unsigned int rx_length : 8;	/* Received Frame Length */
};

#define TST_RX_LENGTH_struct _SFR_MEM8_STRUCT(0x17b, struct __reg_TST_RX_LENGTH)

#endif /* __ASSEMBLER__ */

  /* TST_RX_LENGTH */

#define RX_LENGTH0                      0
#define RX_LENGTH1                      1
#define RX_LENGTH2                      2
#define RX_LENGTH3                      3
#define RX_LENGTH4                      4
#define RX_LENGTH5                      5
#define RX_LENGTH6                      6
#define RX_LENGTH7                      7

/* Start of frame buffer */
#define TRXFBST                         _SFR_MEM8(0x180)

  /* TRXFBST */

#define TRXFBST0                        0
#define TRXFBST1                        1
#define TRXFBST2                        2
#define TRXFBST3                        3
#define TRXFBST4                        4
#define TRXFBST5                        5
#define TRXFBST6                        6
#define TRXFBST7                        7

/* End of frame buffer */
#define TRXFBEND                        _SFR_MEM8(0x1FF)

  /* TRXFBEND */

#define TRXFBEND0                       0
#define TRXFBEND1                       1
#define TRXFBEND2                       2
#define TRXFBEND3                       3
#define TRXFBEND4                       4
#define TRXFBEND5                       5
#define TRXFBEND6                       6
#define TRXFBEND7                       7


/* Interrupt vectors */
/* Vector 0 is the reset vector */

#define _VECTORS_SIZE                  288

/* External Interrupt Request 0 */
#define INT0_vect                       _VECTOR(1)
#define INT0_vect_num                   1

/* External Interrupt Request 1 */
#define INT1_vect                       _VECTOR(2)
#define INT1_vect_num                   2

/* External Interrupt Request 2 */
#define INT2_vect                       _VECTOR(3)
#define INT2_vect_num                   3

/* External Interrupt Request 3 */
#define INT3_vect                       _VECTOR(4)
#define INT3_vect_num                   4

/* External Interrupt Request 4 */
#define INT4_vect                       _VECTOR(5)
#define INT4_vect_num                   5

/* External Interrupt Request 5 */
#define INT5_vect                       _VECTOR(6)
#define INT5_vect_num                   6

/* External Interrupt Request 6 */
#define INT6_vect                       _VECTOR(7)
#define INT6_vect_num                   7

/* External Interrupt Request 7 */
#define INT7_vect                       _VECTOR(8)
#define INT7_vect_num                   8

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect                     _VECTOR(9)
#define PCINT0_vect_num                 9

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect                     _VECTOR(10)
#define PCINT1_vect_num                 10

/* Pin Change Interrupt Request 2 */
#define PCINT2_vect                     _VECTOR(11)
#define PCINT2_vect_num                 11

/* Watchdog Time-out Interrupt */
#define WDT_vect                        _VECTOR(12)
#define WDT_vect_num                    12

/* Timer/Counter2 Compare Match A */
#define TIMER2_COMPA_vect               _VECTOR(13)
#define TIMER2_COMPA_vect_num           13

/* Timer/Counter2 Compare Match B */
#define TIMER2_COMPB_vect               _VECTOR(14)
#define TIMER2_COMPB_vect_num           14

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect                 _VECTOR(15)
#define TIMER2_OVF_vect_num             15

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect                _VECTOR(16)
#define TIMER1_CAPT_vect_num            16

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect               _VECTOR(17)
#define TIMER1_COMPA_vect_num           17

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect               _VECTOR(18)
#define TIMER1_COMPB_vect_num           18

/* Timer/Counter1 Compare Match C */
#define TIMER1_COMPC_vect               _VECTOR(19)
#define TIMER1_COMPC_vect_num           19

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect                 _VECTOR(20)
#define TIMER1_OVF_vect_num             20

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect               _VECTOR(21)
#define TIMER0_COMPA_vect_num           21

/* Timer/Counter0 Compare Match B */
#define TIMER0_COMPB_vect               _VECTOR(22)
#define TIMER0_COMPB_vect_num           22

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect                 _VECTOR(23)
#define TIMER0_OVF_vect_num             23

/* SPI Serial Transfer Complete */
#define SPI_STC_vect                    _VECTOR(24)
#define SPI_STC_vect_num                24

/* USART0, Rx Complete */
#define USART0_RX_vect                  _VECTOR(25)
#define USART0_RX_vect_num              25

/* USART0 Data register Empty */
#define USART0_UDRE_vect                _VECTOR(26)
#define USART0_UDRE_vect_num            26

/* USART0, Tx Complete */
#define USART0_TX_vect                  _VECTOR(27)
#define USART0_TX_vect_num              27

/* Analog Comparator */
#define ANALOG_COMP_vect                _VECTOR(28)
#define ANALOG_COMP_vect_num            28

/* ADC Conversion Complete */
#define ADC_vect                        _VECTOR(29)
#define ADC_vect_num                    29

/* EEPROM Ready */
#define EE_READY_vect                   _VECTOR(30)
#define EE_READY_vect_num               30

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect                _VECTOR(31)
#define TIMER3_CAPT_vect_num            31

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect               _VECTOR(32)
#define TIMER3_COMPA_vect_num           32

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect               _VECTOR(33)
#define TIMER3_COMPB_vect_num           33

/* Timer/Counter3 Compare Match C */
#define TIMER3_COMPC_vect               _VECTOR(34)
#define TIMER3_COMPC_vect_num           34

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect                 _VECTOR(35)
#define TIMER3_OVF_vect_num             35

/* USART1, Rx Complete */
#define USART1_RX_vect                  _VECTOR(36)
#define USART1_RX_vect_num              36

/* USART1 Data register Empty */
#define USART1_UDRE_vect                _VECTOR(37)
#define USART1_UDRE_vect_num            37

/* USART1, Tx Complete */
#define USART1_TX_vect                  _VECTOR(38)
#define USART1_TX_vect_num              38

/* 2-wire Serial Interface */
#define TWI_vect                        _VECTOR(39)
#define TWI_vect_num                    39

/* Store Program Memory Read */
#define SPM_READY_vect                  _VECTOR(40)
#define SPM_READY_vect_num              40

/* Timer/Counter4 Capture Event */
#define TIMER4_CAPT_vect                _VECTOR(41)
#define TIMER4_CAPT_vect_num            41

/* Timer/Counter4 Compare Match A */
#define TIMER4_COMPA_vect               _VECTOR(42)
#define TIMER4_COMPA_vect_num           42

/* Timer/Counter4 Compare Match B */
#define TIMER4_COMPB_vect               _VECTOR(43)
#define TIMER4_COMPB_vect_num           43

/* Timer/Counter4 Compare Match C */
#define TIMER4_COMPC_vect               _VECTOR(44)
#define TIMER4_COMPC_vect_num           44

/* Timer/Counter4 Overflow */
#define TIMER4_OVF_vect                 _VECTOR(45)
#define TIMER4_OVF_vect_num             45

/* Timer/Counter5 Capture Event */
#define TIMER5_CAPT_vect                _VECTOR(46)
#define TIMER5_CAPT_vect_num            46

/* Timer/Counter5 Compare Match A */
#define TIMER5_COMPA_vect               _VECTOR(47)
#define TIMER5_COMPA_vect_num           47

/* Timer/Counter5 Compare Match B */
#define TIMER5_COMPB_vect               _VECTOR(48)
#define TIMER5_COMPB_vect_num           48

/* Timer/Counter5 Compare Match C */
#define TIMER5_COMPC_vect               _VECTOR(49)
#define TIMER5_COMPC_vect_num           49

/* Timer/Counter5 Overflow */
#define TIMER5_OVF_vect                 _VECTOR(50)
#define TIMER5_OVF_vect_num             50

/* Vectors 51 through 56 are reserved (unimplemented UARTs) */

/* TRX24 - PLL lock interrupt */
#define TRX24_PLL_LOCK_vect             _VECTOR(57)
#define TRX24_PLL_LOCK_vect_num         57

/* TRX24 - PLL unlock interrupt */
#define TRX24_PLL_UNLOCK_vect           _VECTOR(58)
#define TRX24_PLL_UNLOCK_vect_num       58

/* TRX24 - Receive start interrupt */
#define TRX24_RX_START_vect             _VECTOR(59)
#define TRX24_RX_START_vect_num         59

/* TRX24 - RX_END interrupt */
#define TRX24_RX_END_vect               _VECTOR(60)
#define TRX24_RX_END_vect_num           60

/* TRX24 - CCA/ED done interrupt */
#define TRX24_CCA_ED_DONE_vect          _VECTOR(61)
#define TRX24_CCA_ED_DONE_vect_num      61

/* TRX24 - XAH - AMI */
#define TRX24_XAH_AMI_vect              _VECTOR(62)
#define TRX24_XAH_AMI_vect_num          62

/* TRX24 - TX_END interrupt */
#define TRX24_TX_END_vect               _VECTOR(63)
#define TRX24_TX_END_vect_num           63

/* TRX24 AWAKE - tranceiver is reaching state TRX_OFF */
#define TRX24_AWAKE_vect                _VECTOR(64)
#define TRX24_AWAKE_vect_num            64

/* Symbol counter - compare match 1 interrupt */
#define SCNT_CMP1_vect                  _VECTOR(65)
#define SCNT_CMP1_vect_num              65

/* Symbol counter - compare match 2 interrupt */
#define SCNT_CMP2_vect                  _VECTOR(66)
#define SCNT_CMP2_vect_num              66

/* Symbol counter - compare match 3 interrupt */
#define SCNT_CMP3_vect                  _VECTOR(67)
#define SCNT_CMP3_vect_num              67

/* Symbol counter - overflow interrupt */
#define SCNT_OVFL_vect                  _VECTOR(68)
#define SCNT_OVFL_vect_num              68

/* Symbol counter - backoff interrupt */
#define SCNT_BACKOFF_vect               _VECTOR(69)
#define SCNT_BACKOFF_vect_num           69

/* AES engine ready interrupt */
#define AES_READY_vect                  _VECTOR(70)
#define AES_READY_vect_num              70

/* Battery monitor indicates supply voltage below threshold */
#define BAT_LOW_vect                    _VECTOR(71)
#define BAT_LOW_vect_num                71


/* memory parameters */

#define SPM_PAGESIZE                    (256)
#define RAMSTART                        (0x200)
#define RAMSIZE                         (0x4000)
#define RAMEND                          (0x41FF)
#define XRAMSTART                       (0x0000)
#define XRAMSIZE                        (0x0000)
#define XRAMEND                         RAMEND
#define E2END                           (0xFFF)
#define E2PAGESIZE                      (0x08)
#define FLASHEND                        (0x1ffff)


/* Fuses */

#define FUSE_MEMORY_SIZE 3

/* LFUSE Byte */
#define FUSE_CKSEL0     ~_BV(0) /* Select Clock Source */
#define FUSE_CKSEL1     ~_BV(1) /* Select Clock Source */
#define FUSE_CKSEL2     ~_BV(2) /* Select Clock Source */
#define FUSE_CKSEL3     ~_BV(3) /* Select Clock Source */
#define FUSE_SUT0       ~_BV(4) /* Select start-up time */
#define FUSE_SUT1       ~_BV(5) /* Select start-up time */
#define FUSE_CKOUT      ~_BV(6) /* Clock output */
#define FUSE_CKDIV8     ~_BV(7) /* Divide clock by 8 */
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_SUT1 & FUSE_CKDIV8)

/* HFUSE Byte */
#define FUSE_BOOTRST    ~_BV(0) /* Select Reset Vector */
#define FUSE_BOOTSZ0    ~_BV(1) /* Select Boot Size */
#define FUSE_BOOTSZ1    ~_BV(2) /* Select Boot Size */
#define FUSE_EESAVE     ~_BV(3) /* EEPROM memory is preserved through chip erase */
#define FUSE_WDTON      ~_BV(4) /* Watchdog timer always on */
#define FUSE_SPIEN      ~_BV(5) /* Enable Serial programming and Data Downloading */
#define FUSE_JTAGEN     ~_BV(6) /* Enable JTAG */
#define FUSE_OCDEN      ~_BV(7) /* Enable OCD */
#define HFUSE_DEFAULT (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN & FUSE_JTAGEN)

/* EFUSE Byte */
#define FUSE_BODLEVEL0  ~_BV(0) /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL1  ~_BV(1) /* Brown-out Detector trigger level */
#define FUSE_BODLEVEL2  ~_BV(2) /* Brown-out Detector trigger level */
#define EFUSE_DEFAULT (0xFF)



/* Lock Bits */

#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST
#define __LOCK_BITS_EXIST


/* Signature */

#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0xA7
#define SIGNATURE_2 0x01

#define SLEEP_MODE_IDLE (0x00<<1)
#define SLEEP_MODE_ADC (0x01<<1)
#define SLEEP_MODE_PWR_DOWN (0x02<<1)
#define SLEEP_MODE_PWR_SAVE (0x03<<1)
#define SLEEP_MODE_STANDBY (0x06<<1)
#define SLEEP_MODE_EXT_STANDBY (0x07<<1)


#endif /* _AVR_IOM128RFA1_H_ */
