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
 * 07-14-2012 - rick@kimballsoftware.com 
 *    Fixed MODE2/MODE3 phase problems. Added logic to deal with USI5 errata.
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
#define SPI_DIV_MASK    (USIDIV0 | USIDIV1 | USIDIV2)
#define SPI_LSBMSB_MASK (USILSB)

/* deal with USI5 errata see: document slaz061b */
enum USI5 {
    USI5_NO_ADJUST=0,
    USI5_ADJUST=1,
    USI5_SENT=2,
};
static enum USI5 bResetAdjust;

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
    USICTL0  |= USISWRST;                   // put USI in reset mode, source USI clock from SMCLK
    USICTL0  |= USIPE5 | USIPE6 | USIPE7 | USIMST | USIOE;
    USICKCTL |= USIDIV_2 | USISSEL_2;       // default speed 4MHz 16MHz/4
    USICTL1   = USICKPH;                    // SPI_MODE_0

    P1OUT |= BIT5 | BIT6;                   // SPI OUTPUT PINS LOW
    P1DIR = (P1DIR & ~BIT7) | BIT5 | BIT6;  // configure P1.5, P1.6, P1.7 for USI

    USICTL0 &= ~USISWRST;                   // release USI for operation

    bResetAdjust = USI5_ADJUST;
}

void spi_disable(void) {
    USICTL0 |= USISWRST;        // put USI in reset mode
}

/**
 * spi_send() - send a byte and recv response
 */
uint8_t spi_send(const uint8_t _data)
{
    USISRL = _data;

    // SPI master generates one additional clock after module reset if USICKPH is set.
    if ( bResetAdjust == USI5_ADJUST ) {
        USICNT=7;   // adjust first time send
        bResetAdjust = USI5_SENT;
    }
    else {
        USICNT = 8;
    }

    while (!(USICTL1 & USIIFG)) {
        ; // wait for an USICNT to decrement to 0
    }

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
    USICTL0 &= ~USISWRST;        // release for operation
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
    case 0:                   /* SPI_MODE0 */
        USICKCTL &= ~USICKPL; /* CPOL=0 */
        USICTL1  |= USICKPH;  /* CPHA=0 */
        break;

    case 1:                   /* SPI_MODE1 */
        USICKCTL &= ~USICKPL; /* CPOL=0 */
        USICTL1  &= ~USICKPH; /* CPHA=1 */
        break;

    case 2:                   /* SPI_MODE2 */
        USICKCTL |= USICKPL;  /* CPOL=1 */
        USICTL1  |= USICKPH;  /* CPHA=0 */
        break;

    case 4:                   /* SPI_MODE3 */
        USICKCTL |= USICKPL;  /* CPOL=1 */
        USICTL1  &= ~USICKPH; /* CPHA=1 */
        break;

    default:
        break;
    }
    USICTL0 &= ~USISWRST;       // release for operation

    if ( USICTL1 & USICKPH ) {
        if ( bResetAdjust != USI5_SENT ) {
            bResetAdjust = USI5_ADJUST;
        }
    }
    else  {
        bResetAdjust = USI5_NO_ADJUST;
    }
}
#else
    //#warning "Error! This device doesn't have a USI peripheral"
#endif
