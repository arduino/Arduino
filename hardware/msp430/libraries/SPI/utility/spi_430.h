/*
 * spi_430.h - common function declarations for different SPI implementations
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

#ifndef _SPI_430_H_
#define _SPI_430_H_

#if defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_EUSCI_B0__)

#define SPI_CLOCK_DIV1   1
#define SPI_CLOCK_DIV2   2
#define SPI_CLOCK_DIV4   4
#define SPI_CLOCK_DIV8   8
#define SPI_CLOCK_DIV16  16
#define SPI_CLOCK_DIV32  32
#define SPI_CLOCK_DIV64  64
#define SPI_CLOCK_DIV128 128

#elif defined(__MSP430_HAS_USI__)

#define SPI_CLOCK_DIV1   0
#define SPI_CLOCK_DIV2   USIDIV_1
#define SPI_CLOCK_DIV4   USIDIV_2
#define SPI_CLOCK_DIV8   USIDIV_3
#define SPI_CLOCK_DIV16  USIDIV_4
#define SPI_CLOCK_DIV32  USIDIV_5
#define SPI_CLOCK_DIV64  USIDIV_6
#define SPI_CLOCK_DIV128 USIDIV_7

#else
    #error "SPI not supported by hardware on this chip"
#endif

void spi_initialize(void);
void spi_disable(void);
uint8_t spi_send(const uint8_t);
void spi_set_bitorder(const uint8_t);
void spi_set_datamode(const uint8_t);
void spi_set_divisor(const uint16_t clkdivider);

#endif /*_SPI_430_H_*/
