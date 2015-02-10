/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 *
 *
 *
 * Nov 2014: Mods by Pat Deegan (http://flyingcarsandstuff.com/), to
 * enable support for multiple SPI ports.  The "SPI" global, and various
 * defines (SPCR, SPSR) are still available, but the SPIClass itself may now be 
 * used in two ways:
 *
 * 
 * 1) Dynamic switching/3rd party libraries
 *   You can switch dynamically between ports using the SPI global.  This allows
 *   using legacy code with a different port... for instance, to override some library's
 *   use of the standard SPIC without needing to change anything in the 3rd party code,
 *   start by defining settings for, say, SPID:
 * 
 *     // Create an SPIPortSettings object (need not be global/persistent):
 *     SPIPortSettings myPortD(&SPID, SS1, MOSI1, MISO1, SCK1); // port*, cs, mosi, miso, sck
 *
 *     // tell the SPI global to switch its settings:
 *     SPI.setConfiguration(myPortD);
 *
 *     // begin and operate as normal
 *     SPI.begin();
 *     SPI.transfer(0x42); // ... etc. 
 * 
 *   The configuration() may be used at any time, just remember to call begin() once
 *   for each port you'll be using.
 *   
 *   In this case, the SPCR/SPDR/SPSR "registers" will point to whatever the _current_
 *   setting is.
 * 
 *
 * 2) Additional instances
 *   You may instantiate other instances to interact through SPI with other
 *   ports.  For example, on the Xmega128a3u, you could use:
 * 
 *     // instance name, port, ss, mosi, miso, sck
 *     SPI_DECLARE(SPI2, SPID, SS1, MOSI1, MISO1, SCK1);
 *
 *   Which would create an SPIClass object named SPI2... then,
 *     SPI2.begin();
 *     SPI2.transfer(0xFF); 
 *     // ... etc. 
 * 
 *   In most instances, the SPI_DEFINE() should be done globally so you'll have access to 
 *   to it everywhere.  You may add:
 *     SPI_EXTERNAL_DECL(SPI2);
 *   in a header file to make it visible to any code that includes the header.
 *
 *   In this case, the SPCR/SPDR/SPSR "registers" will point to the _original_ SPI (0) 
 *   global, so be weary when using 3rd party libs.
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


  #define SPCR	((SPI.configuration()->port)->CTRL)
  #define SPSR	((SPI.configuration()->port)->STATUS)
  #define SPDR	((SPI.configuration()->port)->DATA)
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
#define SPI_INT_FLAG		SPIF

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






#if defined(__AVR_XMEGA__)

  #define SPI_INTERNAL_PCTRL	((spi_settings.port)->CTRL)
  #define SPI_INTERNAL_PSTATUS	((spi_settings.port)->STATUS)
  #define SPI_INTERNAL_PDATA	((spi_settings.port)->DATA)
  #define SPI_INTERNAL_INTCTRL  ((spi_settings.port)->INTCTRL)
  #define SPI_DEFINE(name, port, cs, si, so, clk) SPIClass name(SPIconfiguration(&(port), cs, si, so, clk))

#else
  #define SPI_INTERNAL_PCTRL	SPCR
  #define SPI_INTERNAL_PSTATUS	SPSR
  #define SPI_INTERNAL_PDATA	SPDR

  #define SPI_DEFINE(name, cs, si, so, clk) SPIClass name(SPIconfiguration(cs, si, so, clk))
#endif


#define SPI_EXTERNAL_DECL(name)		extern SPIClass name;


typedef struct SPIPortSettingsStruct {

#if defined(__AVR_XMEGA__)
	SPI_t * port;
#endif
	uint8_t ss;
	uint8_t mosi;
	uint8_t miso;
	uint8_t clk;



	SPIPortSettingsStruct() :
#if defined(__AVR_XMEGA__)
		port(&(SPI_PORT)),
#endif
		ss(SS),
		mosi(MOSI),
		miso(MISO),
		clk(SCK)
	{
	}

	SPIPortSettingsStruct(
#if defined(__AVR_XMEGA__)
		SPI_t * port, 
#endif
		uint8_t select, uint8_t slave_input, uint8_t slave_output, uint8_t clock) :
#if defined(__AVR_XMEGA__)
		port(port),
#endif
		ss(select),
		mosi(slave_input),
		miso(slave_output),
		clk(clock)
	{
	}
} SPIPortSettings;




class SPIClass {
public:
  inline byte transfer(byte _data);

  // SPI Configuration methods

  inline void attachInterrupt();
  inline void detachInterrupt(); // Default

  void begin(); // Default
  void end();

  void setBitOrder(uint8_t);
  void setDataMode(uint8_t);
  void setClockDivider(uint8_t);


  SPIClass();
  SPIClass(const SPIPortSettings & init);
  inline const SPIPortSettings * configuration() { return  &spi_settings;}
  inline void setConfiguration(const SPIPortSettings & settings) { spi_settings = settings;}
private:
  SPIPortSettings spi_settings;


};


extern SPIClass SPI;

byte SPIClass::transfer(byte _data) {

  SPI_INTERNAL_PDATA = _data;
  while (!(SPI_INTERNAL_PSTATUS & _BV(SPI_INT_FLAG)))
    ;
  return SPI_INTERNAL_PDATA;

}

void SPIClass::attachInterrupt() {
#if defined(__AVR_XMEGA__)
  SPI_INTERNAL_INTCTRL  |= PORT_INT1LVL_LO_gc;
#endif
  SPI_INTERNAL_PCTRL |= _BV(SPI_INT_EN);
}

void SPIClass::detachInterrupt() {
#if defined(__AVR_XMEGA__)
  SPI_INTERNAL_INTCTRL  &= ~PORT_INT1LVL_gm;
#endif
  SPI_INTERNAL_PCTRL &= ~_BV(SPI_INT_EN);
}

#endif
