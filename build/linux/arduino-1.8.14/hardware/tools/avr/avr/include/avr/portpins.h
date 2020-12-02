/* Copyright (c) 2003  Theodore A. Roth
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

/* $Id$ */

#ifndef _AVR_PORTPINS_H_
#define _AVR_PORTPINS_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

/* Define Generic PORTn, DDn, and PINn values. */

/* Port Data Register (generic) */
#define    PORT7        7
#define    PORT6        6
#define    PORT5        5
#define    PORT4        4
#define    PORT3        3
#define    PORT2        2
#define    PORT1        1
#define    PORT0        0

/* Port Data Direction Register (generic) */
#define    DD7          7
#define    DD6          6
#define    DD5          5
#define    DD4          4
#define    DD3          3
#define    DD2          2
#define    DD1          1
#define    DD0          0

/* Port Input Pins (generic) */
#define    PIN7         7
#define    PIN6         6
#define    PIN5         5
#define    PIN4         4
#define    PIN3         3
#define    PIN2         2
#define    PIN1         1
#define    PIN0         0

/* Define PORTxn an Pxn values for all possible port pins if not defined already by io.h. */

/* PORT A */

#if defined(PA0) && !defined(PORTA0)
#  define PORTA0 PA0
#elif defined(PORTA0) && !defined(PA0)
#  define PA0 PORTA0
#endif
#if defined(PA1) && !defined(PORTA1)
#  define PORTA1 PA1
#elif defined(PORTA1) && !defined(PA1)
#  define PA1 PORTA1
#endif
#if defined(PA2) && !defined(PORTA2)
#  define PORTA2 PA2
#elif defined(PORTA2) && !defined(PA2)
#  define PA2 PORTA2
#endif
#if defined(PA3) && !defined(PORTA3)
#  define PORTA3 PA3
#elif defined(PORTA3) && !defined(PA3)
#  define PA3 PORTA3
#endif
#if defined(PA4) && !defined(PORTA4)
#  define PORTA4 PA4
#elif defined(PORTA4) && !defined(PA4)
#  define PA4 PORTA4
#endif
#if defined(PA5) && !defined(PORTA5)
#  define PORTA5 PA5
#elif defined(PORTA5) && !defined(PA5)
#  define PA5 PORTA5
#endif
#if defined(PA6) && !defined(PORTA6)
#  define PORTA6 PA6
#elif defined(PORTA6) && !defined(PA6)
#  define PA6 PORTA6
#endif
#if defined(PA7) && !defined(PORTA7)
#  define PORTA7 PA7
#elif defined(PORTA7) && !defined(PA7)
#  define PA7 PORTA7
#endif

/* PORT B */

#if defined(PB0) && !defined(PORTB0)
#  define PORTB0 PB0
#elif defined(PORTB0) && !defined(PB0)
#  define PB0 PORTB0
#endif
#if defined(PB1) && !defined(PORTB1)
#  define PORTB1 PB1
#elif defined(PORTB1) && !defined(PB1)
#  define PB1 PORTB1
#endif
#if defined(PB2) && !defined(PORTB2)
#  define PORTB2 PB2
#elif defined(PORTB2) && !defined(PB2)
#  define PB2 PORTB2
#endif
#if defined(PB3) && !defined(PORTB3)
#  define PORTB3 PB3
#elif defined(PORTB3) && !defined(PB3)
#  define PB3 PORTB3
#endif
#if defined(PB4) && !defined(PORTB4)
#  define PORTB4 PB4
#elif defined(PORTB4) && !defined(PB4)
#  define PB4 PORTB4
#endif
#if defined(PB5) && !defined(PORTB5)
#  define PORTB5 PB5
#elif defined(PORTB5) && !defined(PB5)
#  define PB5 PORTB5
#endif
#if defined(PB6) && !defined(PORTB6)
#  define PORTB6 PB6
#elif defined(PORTB6) && !defined(PB6)
#  define PB6 PORTB6
#endif
#if defined(PB7) && !defined(PORTB7)
#  define PORTB7 PB7
#elif defined(PORTB7) && !defined(PB7)
#  define PB7 PORTB7
#endif

/* PORT C */

#if defined(PC0) && !defined(PORTC0)
#  define PORTC0 PC0
#elif defined(PORTC0) && !defined(PC0)
#  define PC0 PORTC0
#endif
#if defined(PC1) && !defined(PORTC1)
#  define PORTC1 PC1
#elif defined(PORTC1) && !defined(PC1)
#  define PC1 PORTC1
#endif
#if defined(PC2) && !defined(PORTC2)
#  define PORTC2 PC2
#elif defined(PORTC2) && !defined(PC2)
#  define PC2 PORTC2
#endif
#if defined(PC3) && !defined(PORTC3)
#  define PORTC3 PC3
#elif defined(PORTC3) && !defined(PC3)
#  define PC3 PORTC3
#endif
#if defined(PC4) && !defined(PORTC4)
#  define PORTC4 PC4
#elif defined(PORTC4) && !defined(PC4)
#  define PC4 PORTC4
#endif
#if defined(PC5) && !defined(PORTC5)
#  define PORTC5 PC5
#elif defined(PORTC5) && !defined(PC5)
#  define PC5 PORTC5
#endif
#if defined(PC6) && !defined(PORTC6)
#  define PORTC6 PC6
#elif defined(PORTC6) && !defined(PC6)
#  define PC6 PORTC6
#endif
#if defined(PC7) && !defined(PORTC7)
#  define PORTC7 PC7
#elif defined(PORTC7) && !defined(PC7)
#  define PC7 PORTC7
#endif

/* PORT D */

#if defined(PD0) && !defined(PORTD0)
#  define PORTD0 PD0
#elif defined(PORTD0) && !defined(PD0)
#  define PD0 PORTD0
#endif
#if defined(PD1) && !defined(PORTD1)
#  define PORTD1 PD1
#elif defined(PORTD1) && !defined(PD1)
#  define PD1 PORTD1
#endif
#if defined(PD2) && !defined(PORTD2)
#  define PORTD2 PD2
#elif defined(PORTD2) && !defined(PD2)
#  define PD2 PORTD2
#endif
#if defined(PD3) && !defined(PORTD3)
#  define PORTD3 PD3
#elif defined(PORTD3) && !defined(PD3)
#  define PD3 PORTD3
#endif
#if defined(PD4) && !defined(PORTD4)
#  define PORTD4 PD4
#elif defined(PORTD4) && !defined(PD4)
#  define PD4 PORTD4
#endif
#if defined(PD5) && !defined(PORTD5)
#  define PORTD5 PD5
#elif defined(PORTD5) && !defined(PD5)
#  define PD5 PORTD5
#endif
#if defined(PD6) && !defined(PORTD6)
#  define PORTD6 PD6
#elif defined(PORTD6) && !defined(PD6)
#  define PD6 PORTD6
#endif
#if defined(PD7) && !defined(PORTD7)
#  define PORTD7 PD7
#elif defined(PORTD7) && !defined(PD7)
#  define PD7 PORTD7
#endif

/* PORT E */

#if defined(PE0) && !defined(PORTE0)
#  define PORTE0 PE0
#elif defined(PORTE0) && !defined(PE0)
#  define PE0 PORTE0
#endif
#if defined(PE1) && !defined(PORTE1)
#  define PORTE1 PE1
#elif defined(PORTE1) && !defined(PE1)
#  define PE1 PORTE1
#endif
#if defined(PE2) && !defined(PORTE2)
#  define PORTE2 PE2
#elif defined(PORTE2) && !defined(PE2)
#  define PE2 PORTE2
#endif
#if defined(PE3) && !defined(PORTE3)
#  define PORTE3 PE3
#elif defined(PORTE3) && !defined(PE3)
#  define PE3 PORTE3
#endif
#if defined(PE4) && !defined(PORTE4)
#  define PORTE4 PE4
#elif defined(PORTE4) && !defined(PE4)
#  define PE4 PORTE4
#endif
#if defined(PE5) && !defined(PORTE5)
#  define PORTE5 PE5
#elif defined(PORTE5) && !defined(PE5)
#  define PE5 PORTE5
#endif
#if defined(PE6) && !defined(PORTE6)
#  define PORTE6 PE6
#elif defined(PORTE6) && !defined(PE6)
#  define PE6 PORTE6
#endif
#if defined(PE7) && !defined(PORTE7)
#  define PORTE7 PE7
#elif defined(PORTE7) && !defined(PE7)
#  define PE7 PORTE7
#endif

/* PORT F */

#if defined(PF0) && !defined(PORTF0)
#  define PORTF0 PF0
#elif defined(PORTF0) && !defined(PF0)
#  define PF0 PORTF0
#endif
#if defined(PF1) && !defined(PORTF1)
#  define PORTF1 PF1
#elif defined(PORTF1) && !defined(PF1)
#  define PF1 PORTF1
#endif
#if defined(PF2) && !defined(PORTF2)
#  define PORTF2 PF2
#elif defined(PORTF2) && !defined(PF2)
#  define PF2 PORTF2
#endif
#if defined(PF3) && !defined(PORTF3)
#  define PORTF3 PF3
#elif defined(PORTF3) && !defined(PF3)
#  define PF3 PORTF3
#endif
#if defined(PF4) && !defined(PORTF4)
#  define PORTF4 PF4
#elif defined(PORTF4) && !defined(PF4)
#  define PF4 PORTF4
#endif
#if defined(PF5) && !defined(PORTF5)
#  define PORTF5 PF5
#elif defined(PORTF5) && !defined(PF5)
#  define PF5 PORTF5
#endif
#if defined(PF6) && !defined(PORTF6)
#  define PORTF6 PF6
#elif defined(PORTF6) && !defined(PF6)
#  define PF6 PORTF6
#endif
#if defined(PF7) && !defined(PORTF7)
#  define PORTF7 PF7
#elif defined(PORTF7) && !defined(PF7)
#  define PF7 PORTF7
#endif

/* PORT G */

#if defined(PG0) && !defined(PORTG0)
#  define PORTG0 PG0
#elif defined(PORTG0) && !defined(PG0)
#  define PG0 PORTG0
#endif
#if defined(PG1) && !defined(PORTG1)
#  define PORTG1 PG1
#elif defined(PORTG1) && !defined(PG1)
#  define PG1 PORTG1
#endif
#if defined(PG2) && !defined(PORTG2)
#  define PORTG2 PG2
#elif defined(PORTG2) && !defined(PG2)
#  define PG2 PORTG2
#endif
#if defined(PG3) && !defined(PORTG3)
#  define PORTG3 PG3
#elif defined(PORTG3) && !defined(PG3)
#  define PG3 PORTG3
#endif
#if defined(PG4) && !defined(PORTG4)
#  define PORTG4 PG4
#elif defined(PORTG4) && !defined(PG4)
#  define PG4 PORTG4
#endif
#if defined(PG5) && !defined(PORTG5)
#  define PORTG5 PG5
#elif defined(PORTG5) && !defined(PG5)
#  define PG5 PORTG5
#endif
#if defined(PG6) && !defined(PORTG6)
#  define PORTG6 PG6
#elif defined(PORTG6) && !defined(PG6)
#  define PG6 PORTG6
#endif
#if defined(PG7) && !defined(PORTG7)
#  define PORTG7 PG7
#elif defined(PORTG7) && !defined(PG7)
#  define PG7 PORTG7
#endif

/* PORT H */

#if defined(PH0) && !defined(PORTH0)
#  define PORTH0 PH0
#elif defined(PORTH0) && !defined(PH0)
#  define PH0 PORTH0
#endif
#if defined(PH1) && !defined(PORTH1)
#  define PORTH1 PH1
#elif defined(PORTH1) && !defined(PH1)
#  define PH1 PORTH1
#endif
#if defined(PH2) && !defined(PORTH2)
#  define PORTH2 PH2
#elif defined(PORTH2) && !defined(PH2)
#  define PH2 PORTH2
#endif
#if defined(PH3) && !defined(PORTH3)
#  define PORTH3 PH3
#elif defined(PORTH3) && !defined(PH3)
#  define PH3 PORTH3
#endif
#if defined(PH4) && !defined(PORTH4)
#  define PORTH4 PH4
#elif defined(PORTH4) && !defined(PH4)
#  define PH4 PORTH4
#endif
#if defined(PH5) && !defined(PORTH5)
#  define PORTH5 PH5
#elif defined(PORTH5) && !defined(PH5)
#  define PH5 PORTH5
#endif
#if defined(PH6) && !defined(PORTH6)
#  define PORTH6 PH6
#elif defined(PORTH6) && !defined(PH6)
#  define PH6 PORTH6
#endif
#if defined(PH7) && !defined(PORTH7)
#  define PORTH7 PH7
#elif defined(PORTH7) && !defined(PH7)
#  define PH7 PORTH7
#endif

/* PORT J */

#if defined(PJ0) && !defined(PORTJ0)
#  define PORTJ0 PJ0
#elif defined(PORTJ0) && !defined(PJ0)
#  define PJ0 PORTJ0
#endif
#if defined(PJ1) && !defined(PORTJ1)
#  define PORTJ1 PJ1
#elif defined(PORTJ1) && !defined(PJ1)
#  define PJ1 PORTJ1
#endif
#if defined(PJ2) && !defined(PORTJ2)
#  define PORTJ2 PJ2
#elif defined(PORTJ2) && !defined(PJ2)
#  define PJ2 PORTJ2
#endif
#if defined(PJ3) && !defined(PORTJ3)
#  define PORTJ3 PJ3
#elif defined(PORTJ3) && !defined(PJ3)
#  define PJ3 PORTJ3
#endif
#if defined(PJ4) && !defined(PORTJ4)
#  define PORTJ4 PJ4
#elif defined(PORTJ4) && !defined(PJ4)
#  define PJ4 PORTJ4
#endif
#if defined(PJ5) && !defined(PORTJ5)
#  define PORTJ5 PJ5
#elif defined(PORTJ5) && !defined(PJ5)
#  define PJ5 PORTJ5
#endif
#if defined(PJ6) && !defined(PORTJ6)
#  define PORTJ6 PJ6
#elif defined(PORTJ6) && !defined(PJ6)
#  define PJ6 PORTJ6
#endif
#if defined(PJ7) && !defined(PORTJ7)
#  define PORTJ7 PJ7
#elif defined(PORTJ7) && !defined(PJ7)
#  define PJ7 PORTJ7
#endif

/* PORT K */

#if defined(PK0) && !defined(PORTK0)
#  define PORTK0 PK0
#elif defined(PORTK0) && !defined(PK0)
#  define PK0 PORTK0
#endif
#if defined(PK1) && !defined(PORTK1)
#  define PORTK1 PK1
#elif defined(PORTK1) && !defined(PK1)
#  define PK1 PORTK1
#endif
#if defined(PK2) && !defined(PORTK2)
#  define PORTK2 PK2
#elif defined(PORTK2) && !defined(PK2)
#  define PK2 PORTK2
#endif
#if defined(PK3) && !defined(PORTK3)
#  define PORTK3 PK3
#elif defined(PORTK3) && !defined(PK3)
#  define PK3 PORTK3
#endif
#if defined(PK4) && !defined(PORTK4)
#  define PORTK4 PK4
#elif defined(PORTK4) && !defined(PK4)
#  define PK4 PORTK4
#endif
#if defined(PK5) && !defined(PORTK5)
#  define PORTK5 PK5
#elif defined(PORTK5) && !defined(PK5)
#  define PK5 PORTK5
#endif
#if defined(PK6) && !defined(PORTK6)
#  define PORTK6 PK6
#elif defined(PORTK6) && !defined(PK6)
#  define PK6 PORTK6
#endif
#if defined(PK7) && !defined(PORTK7)
#  define PORTK7 PK7
#elif defined(PORTK7) && !defined(PK7)
#  define PK7 PORTK7
#endif

/* PORT L */

#if defined(PL0) && !defined(PORTL0)
#  define PORTL0 PL0
#elif defined(PORTL0) && !defined(PL0)
#  define PL0 PORTL0
#endif
#if defined(PL1) && !defined(PORTL1)
#  define PORTL1 PL1
#elif defined(PORTL1) && !defined(PL1)
#  define PL1 PORTL1
#endif
#if defined(PL2) && !defined(PORTL2)
#  define PORTL2 PL2
#elif defined(PORTL2) && !defined(PL2)
#  define PL2 PORTL2
#endif
#if defined(PL3) && !defined(PORTL3)
#  define PORTL3 PL3
#elif defined(PORTL3) && !defined(PL3)
#  define PL3 PORTL3
#endif
#if defined(PL4) && !defined(PORTL4)
#  define PORTL4 PL4
#elif defined(PORTL4) && !defined(PL4)
#  define PL4 PORTL4
#endif
#if defined(PL5) && !defined(PORTL5)
#  define PORTL5 PL5
#elif defined(PORTL5) && !defined(PL5)
#  define PL5 PORTL5
#endif
#if defined(PL6) && !defined(PORTL6)
#  define PORTL6 PL6
#elif defined(PORTL6) && !defined(PL6)
#  define PL6 PORTL6
#endif
#if defined(PL7) && !defined(PORTL7)
#  define PORTL7 PL7
#elif defined(PORTL7) && !defined(PL7)
#  define PL7 PORTL7
#endif

#endif /* _AVR_PORTPINS_H_ */
