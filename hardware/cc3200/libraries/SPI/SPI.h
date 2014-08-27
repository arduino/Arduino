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
#include <driverlib/spi.h>

#define MAX_BITRATE 16000000
#define SPI_CLOCK_DIV1 1
#define SPI_CLOCK_DIV2 2
#define SPI_CLOCK_DIV4 4
#define SPI_CLOCK_DIV8 8
#define SPI_CLOCK_DIV16 16
#define SPI_CLOCK_DIV32 32

#define SPI_MODE0 SPI_SUB_MODE_0
#define SPI_MODE1 SPI_SUB_MODE_1
#define SPI_MODE2 SPI_SUB_MODE_2
#define SPI_MODE3 SPI_SUB_MODE_3

#define SPI_MODE_MASK SPI_SUB_MODE_3
#define SPI_CLKD_MASK 0xF << 2
#define SPI_EXTCLK_MASK 0xFF0 << 4
#define BOOST_PACK_SPI 0

#define MSBFIRST 1
#define LSBFIRST 0

class SPIClass
{
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
		void setModule(uint8_t module);
};

extern SPIClass SPI;
#endif
