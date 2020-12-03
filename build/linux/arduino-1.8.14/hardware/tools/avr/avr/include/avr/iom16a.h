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

/* $Id: iom16a.h 2248 2011-05-23 19:54:32Z joerg_wunsch $ */

/* avr/iom16a.h - definitions for ATmega16A */

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iom16a.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 


#ifndef _AVR_ATmega16A_H_
#define _AVR_ATmega16A_H_ 1


/* Registers and associated bit numbers. */

#define TWBR _SFR_IO8(0x00)
#define TWBR0 0
#define TWBR1 1
#define TWBR2 2
#define TWBR3 3
#define TWBR4 4
#define TWBR5 5
#define TWBR6 6
#define TWBR7 7

#define TWSR _SFR_IO8(0x01)
#define TWPS0 0
#define TWPS1 1
#define TWS3 3
#define TWS4 4
#define TWS5 5
#define TWS6 6
#define TWS7 7

#define TWAR _SFR_IO8(0x02)
#define TWGCE 0
#define TWA0 1
#define TWA1 2
#define TWA2 3
#define TWA3 4
#define TWA4 5
#define TWA5 6
#define TWA6 7

#define TWDR _SFR_IO8(0x03)
#define TWD0 0
#define TWD1 1
#define TWD2 2
#define TWD3 3
#define TWD4 4
#define TWD5 5
#define TWD6 6
#define TWD7 7

#ifndef __ASSEMBLER__
#define ADC _SFR_IO16(0x04)
#endif
#define ADCW _SFR_IO16(0x04)

#define ADCL _SFR_IO8(0x04)
#define ADCL0 0
#define ADCL1 1
#define ADCL2 2
#define ADCL3 3
#define ADCL4 4
#define ADCL5 5
#define ADCL6 6
#define ADCL7 7

#define ADCH _SFR_IO8(0x05)
#define ADCH0 0
#define ADCH1 1
#define ADCH2 2
#define ADCH3 3
#define ADCH4 4
#define ADCH5 5
#define ADCH6 6
#define ADCH7 7

#define ADCSRA _SFR_IO8(0x06)
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE 3
#define ADIF 4
#define ADATE 5
#define ADSC 6
#define ADEN 7

#define ADMUX _SFR_IO8(0x07)
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ACSR _SFR_IO8(0x08)
#define ACIS0 0
#define ACIS1 1
#define ACIC 2
#define ACIE 3
#define ACI 4
#define ACO 5
#define ACBG 6
#define ACD 7

#define UBRRL _SFR_IO8(0x09)
#define UBRR0 0
#define UBRR1 1
#define UBRR2 2
#define UBRR3 3
#define UBRR4 4
#define UBRR5 5
#define UBRR6 6
#define UBRR7 7

#define UCSRB _SFR_IO8(0x0A)
#define TXB8 0
#define RXB8 1
#define UCSZ2 2
#define TXEN 3
#define RXEN 4
#define UDRIE 5
#define TXCIE 6
#define RXCIE 7

#define UCSRA _SFR_IO8(0x0B)
#define MPCM 0
#define U2X 1
#define UPE 2
#define DOR 3
#define FE 4
#define UDRE 5
#define TXC 6
#define RXC 7

#define UDR _SFR_IO8(0x0C)
#define UDR0 0
#define UDR1 1
#define UDR2 2
#define UDR3 3
#define UDR4 4
#define UDR5 5
#define UDR6 6
#define UDR7 7

#define SPCR _SFR_IO8(0x0D)
#define SPR0 0
#define SPR1 1
#define CPHA 2
#define CPOL 3
#define MSTR 4
#define DORD 5
#define SPE 6
#define SPIE 7

#define SPSR _SFR_IO8(0x0E)
#define SPI2X 0
#define WCOL 6
#define SPIF 7

#define SPDR _SFR_IO8(0x0F)
#define SPDR0 0
#define SPDR1 1
#define SPDR2 2
#define SPDR3 3
#define SPDR4 4
#define SPDR5 5
#define SPDR6 6
#define SPDR7 7

#define PIND _SFR_IO8(0x10)
#define PIND0 0
#define PIND1 1
#define PIND2 2
#define PIND3 3
#define PIND4 4
#define PIND5 5
#define PIND6 6
#define PIND7 7

#define DDRD _SFR_IO8(0x11)
#define DDD0 0
#define DDD1 1
#define DDD2 2
#define DDD3 3
#define DDD4 4
#define DDD5 5
#define DDD6 6
#define DDD7 7

#define PORTD _SFR_IO8(0x12)
#define PORTD0 0
#define PORTD1 1
#define PORTD2 2
#define PORTD3 3
#define PORTD4 4
#define PORTD5 5
#define PORTD6 6
#define PORTD7 7

#define PINC _SFR_IO8(0x13)
#define PINC0 0
#define PINC1 1
#define PINC2 2
#define PINC3 3
#define PINC4 4
#define PINC5 5
#define PINC6 6
#define PINC7 7

#define DDRC _SFR_IO8(0x14)
#define DDC0 0
#define DDC1 1
#define DDC2 2
#define DDC3 3
#define DDC4 4
#define DDC5 5
#define DDC6 6
#define DDC7 7

#define PORTC _SFR_IO8(0x15)
#define PORTC0 0
#define PORTC1 1
#define PORTC2 2
#define PORTC3 3
#define PORTC4 4
#define PORTC5 5
#define PORTC6 6
#define PORTC7 7

#define PINB _SFR_IO8(0x16)
#define PINB0 0
#define PINB1 1
#define PINB2 2
#define PINB3 3
#define PINB4 4
#define PINB5 5
#define PINB6 6
#define PINB7 7

#define DDRB _SFR_IO8(0x17)
#define DDB0 0
#define DDB1 1
#define DDB2 2
#define DDB3 3
#define DDB4 4
#define DDB5 5
#define DDB6 6
#define DDB7 7

#define PORTB _SFR_IO8(0x18)
#define PORTB0 0
#define PORTB1 1
#define PORTB2 2
#define PORTB3 3
#define PORTB4 4
#define PORTB5 5
#define PORTB6 6
#define PORTB7 7

#define PINA _SFR_IO8(0x19)
#define PINA0 0
#define PINA1 1
#define PINA2 2
#define PINA3 3
#define PINA4 4
#define PINA5 5
#define PINA6 6
#define PINA7 7

#define DDRA _SFR_IO8(0x1A)
#define DDA0 0
#define DDA1 1
#define DDA2 2
#define DDA3 3
#define DDA4 4
#define DDA5 5
#define DDA6 6
#define DDA7 7

#define PORTA _SFR_IO8(0x1B)
#define PORTA0 0
#define PORTA1 1
#define PORTA2 2
#define PORTA3 3
#define PORTA4 4
#define PORTA5 5
#define PORTA6 6
#define PORTA7 7

#define EECR _SFR_IO8(0x1C)
#define EERE 0
#define EEWE 1
#define EEMWE 2
#define EERIE 3

#define EEDR _SFR_IO8(0x1D)
#define EEDR0 0
#define EEDR1 1
#define EEDR2 2
#define EEDR3 3
#define EEDR4 4
#define EEDR5 5
#define EEDR6 6
#define EEDR7 7

#define EEAR _SFR_IO16(0x1E)

#define EEARL _SFR_IO8(0x1E)
#define EEAR0 0
#define EEAR1 1
#define EEAR2 2
#define EEAR3 3
#define EEAR4 4
#define EEAR5 5
#define EEAR6 6
#define EEAR7 7

#define EEARH _SFR_IO8(0x1F)
#define EEAR8 0

#define UBRRH _SFR_IO8(0x20)
#define UBRR8 0
#define UBRR9 1
#define UBRR10 2
#define UBRR11 3

#define UCSRC _SFR_IO8(0x20)
#define UCPOL 0
#define UCSZ0 1
#define UCSZ1 2
#define USBS 3
#define UPM0 4
#define UPM1 5
#define UMSEL 6
#define URSEL 7

#define WDTCR _SFR_IO8(0x21)
#define WDP0 0
#define WDP1 1
#define WDP2 2
#define WDE 3
#define WDTOE 4

#define ASSR _SFR_IO8(0x22)
#define TCR2UB 0
#define OCR2UB 1
#define TCN2UB 2
#define AS2 3

#define OCR2 _SFR_IO8(0x23)
#define OCR2_0 0
#define OCR2_1 1
#define OCR2_2 2
#define OCR2_3 3
#define OCR2_4 4
#define OCR2_5 5
#define OCR2_6 6
#define OCR2_7 7

#define TCNT2 _SFR_IO8(0x24)
#define TCNT2_0 0
#define TCNT2_1 1
#define TCNT2_2 2
#define TCNT2_3 3
#define TCNT2_4 4
#define TCNT2_5 5
#define TCNT2_6 6
#define TCNT2_7 7

#define TCCR2 _SFR_IO8(0x25)
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2 7

#define ICR1 _SFR_IO16(0x26)

#define ICR1L _SFR_IO8(0x26)
#define ICR1L0 0
#define ICR1L1 1
#define ICR1L2 2
#define ICR1L3 3
#define ICR1L4 4
#define ICR1L5 5
#define ICR1L6 6
#define ICR1L7 7

#define ICR1H _SFR_IO8(0x27)
#define ICR1H0 0
#define ICR1H1 1
#define ICR1H2 2
#define ICR1H3 3
#define ICR1H4 4
#define ICR1H5 5
#define ICR1H6 6
#define ICR1H7 7

#define OCR1B _SFR_IO16(0x28)

#define OCR1BL _SFR_IO8(0x28)
#define OCR1BL0 0
#define OCR1BL1 1
#define OCR1BL2 2
#define OCR1BL3 3
#define OCR1BL4 4
#define OCR1BL5 5
#define OCR1BL6 6
#define OCR1BL7 7

#define OCR1BH _SFR_IO8(0x29)
#define OCR1BH0 0
#define OCR1BH1 1
#define OCR1BH2 2
#define OCR1BH3 3
#define OCR1BH4 4
#define OCR1BH5 5
#define OCR1BH6 6
#define OCR1BH7 7

#define OCR1A _SFR_IO16(0x2A)

#define OCR1AL _SFR_IO8(0x2A)
#define OCR1AL0 0
#define OCR1AL1 1
#define OCR1AL2 2
#define OCR1AL3 3
#define OCR1AL4 4
#define OCR1AL5 5
#define OCR1AL6 6
#define OCR1AL7 7

#define OCR1AH _SFR_IO8(0x2B)
#define OCR1AH0 0
#define OCR1AH1 1
#define OCR1AH2 2
#define OCR1AH3 3
#define OCR1AH4 4
#define OCR1AH5 5
#define OCR1AH6 6
#define OCR1AH7 7

#define TCNT1 _SFR_IO16(0x2C)

#define TCNT1L _SFR_IO8(0x2C)
#define TCNT1L0 0
#define TCNT1L1 1
#define TCNT1L2 2
#define TCNT1L3 3
#define TCNT1L4 4
#define TCNT1L5 5
#define TCNT1L6 6
#define TCNT1L7 7

#define TCNT1H _SFR_IO8(0x2D)
#define TCNT1H0 0
#define TCNT1H1 1
#define TCNT1H2 2
#define TCNT1H3 3
#define TCNT1H4 4
#define TCNT1H5 5
#define TCNT1H6 6
#define TCNT1H7 7

#define TCCR1B _SFR_IO8(0x2E)
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

#define TCCR1A _SFR_IO8(0x2F)
#define WGM10 0
#define WGM11 1
#define FOC1B 2
#define FOC1A 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#define SFIOR _SFR_IO8(0x30)
#define PSR10 0
#define PSR2 1
#define PUD 2
#define ACME 3
#define ADTS0 5
#define ADTS1 6
#define ADTS2 7

#define OSCCAL _SFR_IO8(0x31)
#define CAL0 0
#define CAL1 1
#define CAL2 2
#define CAL3 3
#define CAL4 4
#define CAL5 5
#define CAL6 6
#define CAL7 7

#define OCDR _SFR_IO8(0x31)
#define OCDR0 0
#define OCDR1 1
#define OCDR2 2
#define OCDR3 3
#define OCDR4 4
#define OCDR5 5
#define OCDR6 6
#define OCDR7 7

#define TCNT0 _SFR_IO8(0x32)
#define TCNT0_0 0
#define TCNT0_1 1
#define TCNT0_2 2
#define TCNT0_3 3
#define TCNT0_4 4
#define TCNT0_5 5
#define TCNT0_6 6
#define TCNT0_7 7

#define TCCR0 _SFR_IO8(0x33)
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

#define MCUCSR _SFR_IO8(0x34)
#define PORF 0
#define EXTRF 1
#define BORF 2
#define WDRF 3
#define JTRF 4
#define ISC2 6
#define JTD 7

#define MCUCR _SFR_IO8(0x35)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define SM0 4
#define SM1 5
#define SE 6
#define SM2 7

#define TWCR _SFR_IO8(0x36)
#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWEA 6
#define TWINT 7

#define SPMCSR _SFR_IO8(0x37)
#define SPMEN 0
#define PGERS 1
#define PGWRT 2
#define BLBSET 3
#define RWWSRE 4
#define RWWSB 6
#define SPMIE 7

#define TIFR _SFR_IO8(0x38)
#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

#define TIMSK _SFR_IO8(0x39)
#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5
#define TOIE2 6
#define OCIE2 7

#define GIFR _SFR_IO8(0x3A)
#define INTF2 5
#define INTF0 6
#define INTF1 7

#define GICR _SFR_IO8(0x3B)
#define IVCE 0
#define IVSEL 1
#define INT2 5
#define INT0 6
#define INT1 7

#define OCR0 _SFR_IO8(0x3C)
#define OCR0_0 0
#define OCR0_1 1
#define OCR0_2 2
#define OCR0_3 3
#define OCR0_4 4
#define OCR0_5 5
#define OCR0_6 6
#define OCR0_7 7


/* Interrupt vectors */
/* Vector 0 is the reset vector */
#define INT0_vect_num  1
#define INT0_vect      _VECTOR(1)  /* External Interrupt Request 0 */
#define INT1_vect_num  2
#define INT1_vect      _VECTOR(2)  /* External Interrupt Request 1 */
#define TIMER2_COMP_vect_num  3
#define TIMER2_COMP_vect      _VECTOR(3)  /* Timer/Counter2 Compare Match */
#define TIMER2_OVF_vect_num  4
#define TIMER2_OVF_vect      _VECTOR(4)  /* Timer/Counter2 Overflow */
#define TIMER1_CAPT_vect_num  5
#define TIMER1_CAPT_vect      _VECTOR(5)  /* Timer/Counter1 Capture Event */
#define TIMER1_COMPA_vect_num  6
#define TIMER1_COMPA_vect      _VECTOR(6)  /* Timer/Counter1 Compare Match A */
#define TIMER1_COMPB_vect_num  7
#define TIMER1_COMPB_vect      _VECTOR(7)  /* Timer/Counter1 Compare Match B */
#define TIMER1_OVF_vect_num  8
#define TIMER1_OVF_vect      _VECTOR(8)  /* Timer/Counter1 Overflow */
#define TIMER0_OVF_vect_num  9
#define TIMER0_OVF_vect      _VECTOR(9)  /* Timer/Counter0 Overflow */
#define SPI_STC_vect_num  10
#define SPI_STC_vect      _VECTOR(10)  /* Serial Transfer Complete */

/* The following vectors use an inconsistent (to the ATmega16 etc.)
   naming scheme.  The inconsistent names are preserved here for softwares
   that already use them: */
#define USARTRXC_vect_num  11
#define USARTRXC_vect      _VECTOR(11)  /* USART, Rx Complete */
#define USARTUDRE_vect_num  12
#define USARTUDRE_vect      _VECTOR(12)  /* USART Data Register Empty */
#define USARTTXC_vect_num  13
#define USARTTXC_vect      _VECTOR(13)  /* USART, Tx Complete */
/* The "classic" designators: */
#define USART_RXC_vect_num  11
#define USART_RXC_vect      _VECTOR(11)  /* USART, Rx Complete */
#define USART_UDRE_vect_num  12
#define USART_UDRE_vect      _VECTOR(12)  /* USART Data Register Empty */
#define USART_TXC_vect_num  13
#define USART_TXC_vect      _VECTOR(13)  /* USART, Tx Complete */

#define ADC_vect_num  14
#define ADC_vect      _VECTOR(14)  /* ADC Conversion Complete */
#define EE_RDY_vect_num  15
#define EE_RDY_vect      _VECTOR(15)  /* EEPROM Ready */
#define ANA_COMP_vect_num  16
#define ANA_COMP_vect      _VECTOR(16)  /* Analog Comparator */
#define TWI_vect_num  17
#define TWI_vect      _VECTOR(17)  /* 2-wire Serial Interface */
#define INT2_vect_num  18
#define INT2_vect      _VECTOR(18)  /* External Interrupt Request 2 */
#define TIMER0_COMP_vect_num  19
#define TIMER0_COMP_vect      _VECTOR(19)  /* Timer/Counter0 Compare Match */
#define SPM_RDY_vect_num  20
#define SPM_RDY_vect      _VECTOR(20)  /* Store Program Memory Ready */

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (21 * _VECTOR_SIZE)


/* Constants */
#define SPM_PAGESIZE (128)
#define RAMSTART     (0x60)
#define RAMSIZE      (1024)
#define RAMEND       (RAMSTART + RAMSIZE - 1)
#define XRAMSTART    (NA)
#define XRAMSIZE     (0)
#define XRAMEND      (RAMEND)
#define E2END        (0x1FF)
#define E2PAGESIZE   (4)
#define FLASHEND     (0x3FFF)


/* Fuses */
#define FUSE_MEMORY_SIZE 2

/* Low Fuse Byte */
#define FUSE_CKSEL0  (unsigned char)~_BV(0)  /* Select Clock Source */
#define FUSE_CKSEL1  (unsigned char)~_BV(1)  /* Select Clock Source */
#define FUSE_CKSEL2  (unsigned char)~_BV(2)  /* Select Clock Source */
#define FUSE_CKSEL3  (unsigned char)~_BV(3)  /* Select Clock Source */
#define FUSE_SUT0  (unsigned char)~_BV(4)  /* Select start-up time */
#define FUSE_SUT1  (unsigned char)~_BV(5)  /* Select start-up time */
#define FUSE_BODEN  (unsigned char)~_BV(6)  /* Brown out detector enable */
#define FUSE_BODLEVEL  (unsigned char)~_BV(7)  /* Brown out detector trigger level */
#define LFUSE_DEFAULT (FUSE_SUT1 & FUSE_SUT0 & FUSE_CKSEL3 & FUSE_CKSEL2 & FUSE_CKSEL1)

/* High Fuse Byte */
#define FUSE_BOOTRST  (unsigned char)~_BV(0)  /* Select Reset Vector */
#define FUSE_BOOTSZ0  (unsigned char)~_BV(1)  /* Select Boot Size */
#define FUSE_BOOTSZ1  (unsigned char)~_BV(2)  /* Select Boot Size */
#define FUSE_EESAVE  (unsigned char)~_BV(3)  /* EEPROM memory is preserved through chip erase */
#define FUSE_CKOPT  (unsigned char)~_BV(4)  /* Oscillator Options */
#define FUSE_SPIEN  (unsigned char)~_BV(5)  /* Enable Serial programming and Data Downloading */
#define FUSE_JTAGEN  (unsigned char)~_BV(6)  /* Enable JTAG */
#define FUSE_OCDEN  (unsigned char)~_BV(7)  /* Enable OCD */
#define HFUSE_DEFAULT (FUSE_JTAGEN & FUSE_SPIEN & FUSE_BOOTSZ1 & FUSE_BOOTSZ0)


/* Lock Bits */
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST


/* Signature */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x03


/* Device Pin Definitions */
#define MOSI_DDR   DDRB
#define MOSI_PORT  PORTB
#define MOSI_PIN   PINB
#define MOSI_BIT   5

#define MISO_DDR   DDRB
#define MISO_PORT  PORTB
#define MISO_PIN   PINB
#define MISO_BIT   6

#define PB7_SCK_DDR   DDRB7_SCK
#define PB7_SCK_PORT  PORTB7_SCK
#define PB7_SCK_PIN   PINB7_SCK
#define PB7_SCK_BIT   7_SCK

#define RXD_DDR   DDRD
#define RXD_PORT  PORTD
#define RXD_PIN   PIND
#define RXD_BIT   0

#define TXD_DDR   DDRD
#define TXD_PORT  PORTD
#define TXD_PIN   PIND
#define TXD_BIT   1

#define INT0_DDR   DDRD
#define INT0_PORT  PORTD
#define INT0_PIN   PIND
#define INT0_BIT   2

#define INT1_DDR   DDRD
#define INT1_PORT  PORTD
#define INT1_PIN   PIND
#define INT1_BIT   3

#define OC1B_DDR   DDRD
#define OC1B_PORT  PORTD
#define OC1B_PIN   PIND
#define OC1B_BIT   4

#define OC1A_DDR   DDRD
#define OC1A_PORT  PORTD
#define OC1A_PIN   PIND
#define OC1A_BIT   5

#define ICP_DDR   DDRD
#define ICP_PORT  PORTD
#define ICP_PIN   PIND
#define ICP_BIT   6

#define OC2_DDR   DDRD
#define OC2_PORT  PORTD
#define OC2_PIN   PIND
#define OC2_BIT   7

#define SCL_DDR   DDRC
#define SCL_PORT  PORTC
#define SCL_PIN   PINC
#define SCL_BIT   0

#define SDA_DDR   DDRC
#define SDA_PORT  PORTC
#define SDA_PIN   PINC
#define SDA_BIT   1

#define PC3_DDR   DDRC
#define PC3_PORT  PORTC
#define PC3_PIN   PINC
#define PC3_BIT   3

#define PC4_DDR   DDRC
#define PC4_PORT  PORTC
#define PC4_PIN   PINC
#define PC4_BIT   4

#define PC5_DDR   DDRC
#define PC5_PORT  PORTC
#define PC5_PIN   PINC
#define PC5_BIT   5

#define ADC7_DDR   DDRA
#define ADC7_PORT  PORTA
#define ADC7_PIN   PINA
#define ADC7_BIT   7

#define ADC6_DDR   DDRA
#define ADC6_PORT  PORTA
#define ADC6_PIN   PINA
#define ADC6_BIT   6

#define ADc5_DDR   DDRA
#define ADc5_PORT  PORTA
#define ADc5_PIN   PINA
#define ADc5_BIT   5

#define ADC4_DDR   DDRA
#define ADC4_PORT  PORTA
#define ADC4_PIN   PINA
#define ADC4_BIT   4

#define ADC3_DDR   DDRA
#define ADC3_PORT  PORTA
#define ADC3_PIN   PINA
#define ADC3_BIT   3

#define ADC2_DDR   DDRA
#define ADC2_PORT  PORTA
#define ADC2_PIN   PINA
#define ADC2_BIT   2

#define ADC1_DDR   DDRA
#define ADC1_PORT  PORTA
#define ADC1_PIN   PINA
#define ADC1_BIT   1

#define ADC0_DDR   DDRA
#define ADC0_PORT  PORTA
#define ADC0_PIN   PINA
#define ADC0_BIT   0

#define T0_DDR   DDRB
#define T0_PORT  PORTB
#define T0_PIN   PINB
#define T0_BIT   0

#define T1_DDR   DDRB
#define T1_PORT  PORTB
#define T1_PIN   PINB
#define T1_BIT   1

#define AIN0_DDR   DDRB
#define AIN0_PORT  PORTB
#define AIN0_PIN   PINB
#define AIN0_BIT   2

#define AIN1_DDR   DDRB
#define AIN1_PORT  PORTB
#define AIN1_PIN   PINB
#define AIN1_BIT   3

#define SS_DDR   DDRB
#define SS_PORT  PORTB
#define SS_PIN   PINB
#define SS_BIT   4

#define SLEEP_MODE_IDLE (0x00<<4)
#define SLEEP_MODE_ADC (0x01<<4)
#define SLEEP_MODE_PWR_DOWN (0x02<<4)
#define SLEEP_MODE_PWR_SAVE (0x03<<4)
#define SLEEP_MODE_STANDBY (0x0A<<4)
#define SLEEP_MODE_EXT_STANDBY (0x0B<<4)

#endif /* _AVR_ATmega16A_H_ */

