/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <stdio.h>
#include <Arduino.h>
#include <avr/pgmspace.h>

#if defined(__AVR_XMEGA__)
  #if !defined(SPI_PORT)
    #error "Please define SPI_PORT in pins_arduino for your board"
  #endif
  #define SPCR	SPI_PORT.CTRL
  #define SPSR	SPI_PORT.STATUS
  #define SPDR	SPI_PORT.DATA
  #define SPE	SPI_ENABLE_bp
  #define MSTR	SPI_MASTER_bp
  #define SPI_INT_FLAG	SPI_IF_bp
  #define SPI_INT_EN	SPI_ENABLE_bp
  #define DORD  SPI_DORD_bp

#define SPI_CLOCK_DIV4   0x00
#define SPI_CLOCK_DIV16  SPI_PRESCALER0_bm
#define SPI_CLOCK_DIV64  SPI_PRESCALER1_bm
#define SPI_CLOCK_DIV128 (SPI_PRESCALER0_bm | SPI_PRESCALER1_bm)
#define SPI_CLOCK_DIV2   SPI_CLK2X_bm
#define SPI_CLOCK_DIV8   (SPI_CLK2X_bm | SPI_PRESCALER0_bm)
#define SPI_CLOCK_DIV32  (SPI_CLK2X_bm | SPI_PRESCALER1_bm)
//#define SPI_CLOCK_DIV64  (SPI_CLK2X_bm | SPI_PRESCALER0_bm | SPI_PRESCALER1_bm)

#define SPI_MODE0 0x00
#define SPI_MODE1 SPI_MODE0_bm
#define SPI_MODE2 SPI_MODE1_bm
#define SPI_MODE3 (SPI_MODE0_bm | SPI_MODE0_bm)

#define SPI_MODE_MASK    SPI_MODE_gm
#define SPI_CLOCK_MASK   SPI_PRESCALER_gm
#define SPI_2XCLOCK_MASK SPI_CLK2X_bm

#else
#define SPI_INT_EN		SPIE
#define SPI_INT_FLAG	SPIF

#define SPI_CLOCK_DIV4 0x00
#define SPI_CLOCK_DIV16 0x01
#define SPI_CLOCK_DIV64 0x02
#define SPI_CLOCK_DIV128 0x03
#define SPI_CLOCK_DIV2 0x04
#define SPI_CLOCK_DIV8 0x05
#define SPI_CLOCK_DIV32 0x06
//#define SPI_CLOCK_DIV64 0x07

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define SPI_MODE_MASK 0x0C  // CPOL = bit 3, CPHA = bit 2 on SPCR
#define SPI_CLOCK_MASK 0x03  // SPR1 = bit 1, SPR0 = bit 0 on SPCR
#define SPI_2XCLOCK_MASK 0x01  // SPI2X = bit 0 on SPSR
#endif

class SPIClass {
public:
  inline static byte transfer(byte _data);

  // SPI Configuration methods

  inline static void attachInterrupt();
  inline static void detachInterrupt(); // Default

  static void begin(); // Default
  static void end();

  static void setBitOrder(uint8_t);
  static void setDataMode(uint8_t);
  static void setClockDivider(uint8_t);
};

extern SPIClass SPI;

byte SPIClass::transfer(byte _data) {
  SPDR = _data;
  while (!(SPSR & _BV(SPI_INT_FLAG)))
    ;
  return SPDR;
}

void SPIClass::attachInterrupt() {
#if defined(__AVR_XMEGA__)
  SPI_PORT.INTCTRL  |= PORT_INT1LVL_LO_gc;
#endif
  SPCR |= _BV(SPI_INT_EN);
}

void SPIClass::detachInterrupt() {
#if defined(__AVR_XMEGA__)
  SPI_PORT.INTCTRL  &= ~PORT_INT1LVL_gm;
#endif
  SPCR &= ~_BV(SPI_INT_EN);
}

#endif
