/**
 * File: usi_spi.c - msp430 USI SPI implementation
 *
 * Copyright (c) 2012 by Rick Kimball <rick@kimballsoftware.com>
 * spi abstraction api for msp430
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 */

#include <msp430.h>
#include <stdint.h>
#include "spi_430.h"

#ifdef __MSP430_HAS_USI__
/**
 * USI flags for various the SPI MODEs
 *
 * Note: The msp430 USICKPL tracks the CPOL value. However,
 * the USICKPH flag is inverted when compared to the CPHA
 * value described in Motorola documentation.
 */

#define SPI_MODE_0 (USICKPH)			/* CPOL=0 CPHA=0 */
#define SPI_MODE_1 (0)                 	/* CPOL=0 CPHA=1 */
#define SPI_MODE_2 (USICKPL | USICKPH)  /* CPOL=1 CPHA=0 */
#define SPI_MODE_3 (USICKPL)			/* CPOL=1 CPHA=1 */

#define SPI_MODE_MASK (USICKPL | USICKPH)
#define SPI_DIV_MASK  (USIDIV0 | USIDIV1 | USIDIV2)
#define SPI_LSBMSB_MASK USILSB

/**
 * spi_initialize() - Configure USI for SPI mode
 *
 * P2.0 - CS (active low)
 * P1.5 - SCLK
 * P1.6 - MOSI aka SIMO
 * P1.7 - MISO aka SOMI
 */

void spi_initialize(void)
{
    USICTL0 |= USISWRST;	                // put USI in reset mode, source USI clock from SMCLK
    USICTL0 |= USIPE5 | USIPE6 | USIPE7 | USIMST | USIOE;
    USICTL1 |= SPI_MODE_0;                  // use SPI MODE 0 - CPOL=0 CPHA=0
    USICKCTL = USIDIV_2 | USISSEL_2;        // default speed 4MHz 16MHz/4

	P1OUT |= BIT5 | BIT6;                   // SPI OUTPUT PINS LOW
	P1DIR = (P1DIR & ~BIT7) | BIT5 | BIT6;  // configure P1.5, P1.6, P1.7 for USI

	USICTL0 &= ~USISWRST;			        // release USI for operation
}

void spi_disable(void)
{
    USICTL0 |= USISWRST; // put USI in reset mode
}

/**
 * spi_send() - send a byte and recv response
 */
uint8_t spi_send(const uint8_t _data)
{
    USISRL = _data;
    USICNT = 8;

	while (!(USIIFG & USICTL1))
        ; // wait for an inbound character

	return USISRL; // reading clears RXIFG flag
}

/**
 * spi_set_divisor() - set new clock divider for USI
 *
 * There are a fixed set of valid values for clock divisors
 * see the slau144 for details. DIV by 2/4/8 .. 128
 */

void spi_set_divisor(const uint16_t clkdiv)
{
    USICTL0 |= USISWRST;        // put USI in reset mode
    USICKCTL = (USICKCTL & ~SPI_DIV_MASK) | clkdiv;
    USICTL0 &= ~USISWRST;		// release for operation
}

/**
 * spi_set_bitorder (enum LSBFIRST=0|MSBFIRST=1)
 *
 * Note: this should use the LSBFIRST/MSBFIRST defines however
 * it doesn't to allow this code to compile without Energia.
 *
 */
void spi_set_bitorder(const uint8_t order)
{
    USICTL0 |= USISWRST;        // put USI in reset mode
    USICTL0 = (USICTL0 & ~SPI_LSBMSB_MASK) | ((order == 1 /*MSBFIRST*/) ? 0 : USILSB); /* MSBFIRST = 1 */
    USICTL0 &= ~USISWRST;       // release for operation
}

/**
 * spi_set_datamode() - Motorola SPI Mode 0 ... 3
 *
 * mode is really an enum SPI_MODE0 ... SPI_MODE3 as defined in
 * the Energia header file.
 */
void spi_set_datamode(const uint8_t mode)
{
    USICTL0 |= USISWRST;        // put USI in reset mode while we make changes
    switch(mode) {
    case 0: /* SPI_MODE0 */
        USICTL1 = (USICTL1 & ~SPI_MODE_MASK) | SPI_MODE_0;
        break;
    case 1: /* SPI_MODE1 */
        USICTL1 = (USICTL1 & ~SPI_MODE_MASK) | SPI_MODE_1;
        break;
    case 2: /* SPI_MODE2 */
        USICTL1 = (USICTL1 & ~SPI_MODE_MASK) | SPI_MODE_2;
        break;
    case 4: /* SPI_MODE3 */
        USICTL1 = (USICTL1 & ~SPI_MODE_MASK) | SPI_MODE_3;
        break;
    default:
        break;
    }
    USICTL0 &= ~USISWRST;       // release for operation
}
#else
    //#warning "Error! This device doesn't have a USI peripheral"
#endif
