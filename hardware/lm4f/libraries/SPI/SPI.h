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
#include <Energia.h>

#define SPI_CLOCK_DIV2 2
#define SPI_CLOCK_DIV4 4
#define SPI_CLOCK_DIV8 8
#define SPI_CLOCK_DIV16 16
#define SPI_CLOCK_DIV32 32
#define SPI_CLOCK_DIV64 64
#define SPI_CLOCK_DIV128 128

#define SPI_MODE0 0x00
#define SPI_MODE1 0x80
#define SPI_MODE2 0x40
#define SPI_MODE3 0xC0

#define BOOST_PACK_SPI 2

#define MSBFIRST 1
#define LSBFIRST 0

class SPIClass {

private:

	uint8_t SSIModule;
	uint8_t SSIBitOrder;

public:

  SPIClass(void);
  SPIClass(uint8_t);
  void begin(); // Default
  void end();

  void setBitOrder(uint8_t);
  void setBitOrder(uint8_t, uint8_t);

  void setDataMode(uint8_t);

  void setClockDivider(uint8_t);

  uint8_t transfer(uint8_t);

  //Stellarpad-specific functions
  void setModule(uint8_t);

};

extern SPIClass SPI;

#endif
