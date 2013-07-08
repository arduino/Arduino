///
/// @mainpage	SPI for LM4F
///
/// @details	Test of the 4 SPI ports on Stellaris LaunchPad
/// @n          Works fine on all ports, SPI=SPI2, SPI1, SP0 and SPI3
///
/// @author	reaper7
/// @date	Jul 08, 2013
/// @version	101
///
/// @see Based on SPI Master library for Arduino.
///
/// @copyright Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
/// This file is free software; you can redistribute it and/or modify
/// it under the terms of either the GNU General Public License version 2
/// or the GNU Lesser General Public License version 2.1, both as
/// published by the Free Software Foundation.
///

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

// Board check
#ifndef __LM4F120H5QR__
#error Board not supported.
#endif

#include <stdio.h>

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

class SPIClass {

private:

	unsigned long slaveSelect;
	unsigned long SSIModule;	

public:

  SPIClass(void);
  SPIClass(unsigned long);
  void begin(); // Default
  void begin(unsigned long);
  void end();
  void end(unsigned long);

  void setBitOrder(uint8_t);
  void setBitOrder(unsigned long, uint8_t);
  void setDataMode(uint8_t);

  void setClockDivider(uint8_t);

  uint8_t transfer(uint8_t);
  uint8_t transfer(unsigned long, uint8_t);
  uint8_t transfer(unsigned long, uint8_t, uint8_t);

  // Stellarpad-specific functions
  void setModule(unsigned long);                // module
  void setModule(unsigned long, unsigned long); // module, sspin
};

// SPI ports
extern SPIClass SPI0;
extern SPIClass SPI1;
extern SPIClass SPI2;
extern SPIClass SPI3;

// default SPI port on LM4F = SPI port 2
#define SPI SPI2

#endif
