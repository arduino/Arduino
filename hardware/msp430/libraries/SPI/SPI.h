/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 * 2012-04-29 rick@kimballsoftware.com - added msp430 support.
 *
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <Energia.h>
#include <inttypes.h>

#if defined(__MSP430_HAS_USI__) || defined(__MSP430_HAS_USCI_B0__) || defined(__MSP430_HAS_USCI_B1__) || defined(__MSP430_HAS_USCI__) || defined(__MSP430_HAS_EUSCI_B0__)
#include "utility/spi_430.h"
#endif

#define SPI_MODE0 0
#define SPI_MODE1 1
#define SPI_MODE2 2
#define SPI_MODE3 4

class SPIClass {
public:
  inline static uint8_t transfer(uint8_t _data);

  // SPI Configuration methods

  inline static void begin(); // Default
  inline static void end();

  inline static void setBitOrder(uint8_t);
  inline static void setDataMode(uint8_t);
  inline static void setClockDivider(uint8_t);

  inline static void attachInterrupt();
  inline static void detachInterrupt();
};

extern SPIClass SPI;

uint8_t SPIClass::transfer(uint8_t _data) {
    return spi_send(_data);
}

void SPIClass::begin()
{
    spi_initialize();
}

void SPIClass::end()
{
    spi_disable();
}

void SPIClass::setBitOrder(uint8_t bitOrder)
{
    spi_set_bitorder(bitOrder);
}

void SPIClass::setDataMode(uint8_t mode)
{
    spi_set_datamode(mode);
}

void SPIClass::setClockDivider(uint8_t rate)
{
    spi_set_divisor(rate);
}

void SPIClass::attachInterrupt() {
    /* undocumented in Arduino 1.0 */
}

void SPIClass::detachInterrupt() {
    /* undocumented in Arduino 1.0 */
}


#endif
