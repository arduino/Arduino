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

#ifndef _C2000_SPI_H_
#define _C2000_SPI_H_

void spi_initialize(void);
void spi_disable(void);
uint8_t spi_send(const uint8_t);
void spi_set_bitorder(const uint8_t);
void spi_set_datamode(const uint8_t);
void spi_set_divisor(const uint16_t clkdivider);

#endif /*_C2000_SPI_H_*/
