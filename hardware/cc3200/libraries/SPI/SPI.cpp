/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include "SPI.h"
#include "wiring_private.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_mcspi.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom_map.h"
#include "driverlib/spi.h"
#include "driverlib/gpio.h"
#include "driverlib/prcm.h"
#include "driverlib/pin.h"

#define SSIBASE g_ulSSIBase[SSIModule]
#define NOT_ACTIVE 0xA

static const unsigned long g_ulSSIBase[] = {
	GSPI_BASE
};

//*****************************************************************************
//
// The list of SSI peripherals.
//
//*****************************************************************************
static const unsigned long g_ulSSIPeriph[] = {
	PRCM_GSPI
};

//*****************************************************************************
//
// The list of SSI gpio configurations.
//
//*****************************************************************************
static const unsigned long g_ulSSIPins[][4] = {
	{PIN_05 /* SCLK */, PIN_08 /* SS */, PIN_06 /* MISO */, PIN_07 /* MOSI */}
};

static const unsigned long g_ulSSIPinModes[][4] = {
	{PIN_MODE_7 /* SCLK */, PIN_MODE_7 /* SS */, PIN_MODE_7 /* MISO */, PIN_MODE_7 /* MOSI */}
};

SPIClass::SPIClass(void) {
	SSIModule = BOOST_PACK_SPI;
	SSIBitOrder = MSBFIRST;
}

SPIClass::SPIClass(uint8_t module) {
	SSIModule = module;
	SSIBitOrder = MSBFIRST;
}
  
void SPIClass::begin() {
	unsigned long initialData = 0;

	if(SSIModule == NOT_ACTIVE) {
		SSIModule = BOOST_PACK_SPI;
	}

	MAP_PRCMPeripheralClkEnable(PRCM_GSPI, PRCM_RUN_MODE_CLK);

	/* Configure pins as SPI */
	MAP_PinTypeSPI(g_ulSSIPins[SSIModule][0], g_ulSSIPinModes[SSIModule][0]);
	/* Leave the CS pin under software control */
//	MAP_PinTypeSPI(g_ulSSIPins[SSIModule][1], g_ulSSIPinModes[SSIModule][1]);
	MAP_PinTypeSPI(g_ulSSIPins[SSIModule][2], g_ulSSIPinModes[SSIModule][2]);
	MAP_PinTypeSPI(g_ulSSIPins[SSIModule][3], g_ulSSIPinModes[SSIModule][3]);

	MAP_PRCMPeripheralReset(PRCM_GSPI);
	MAP_SPIReset(SSIBASE);

	/* 4 MHz clock, MODE 0, 3 PIN with CS under S/W control */
	MAP_SPIConfigSetExpClk(SSIBASE,MAP_PRCMPeripheralClockGet(PRCM_GSPI),
				4000000, SPI_MODE_MASTER, SPI_MODE0,
				(SPI_HW_CTRL_CS |
				SPI_3PIN_MODE |
				SPI_TURBO_OFF |
				SPI_CS_ACTIVELOW |
				SPI_WL_8));

	MAP_SPIEnable(SSIBASE);
}

void SPIClass::end()
{
	MAP_SPIDisable(SSIBASE);
}

void SPIClass::setBitOrder(uint8_t ssPin, uint8_t bitOrder)
{
	SSIBitOrder = bitOrder;
}

void SPIClass::setBitOrder(uint8_t bitOrder)
{
	SSIBitOrder = bitOrder;
}

void SPIClass::setDataMode(uint8_t mode)
{
	MAP_PRCMPeripheralClkEnable(PRCM_GSPI, PRCM_RUN_MODE_CLK);
	HWREG(SSIBASE + MCSPI_O_CH0CONF) &= ~SPI_MODE_MASK;
	HWREG(SSIBASE + MCSPI_O_CH0CONF) |= mode;
}

void SPIClass::setClockDivider(uint8_t divider)
{
	/* The least significant four bits of the divider is used fo configure
	 * CLKD in MCSPI_CHCONF next eight least significant bits are used to
	 * configure the EXTCLK in MCSPI_CHCTRL.
	 * Note that the peripheral clock is set to 40 MHz vs System Clock @ 80 MHz */
	MAP_PRCMPeripheralClkEnable(PRCM_GSPI, PRCM_RUN_MODE_CLK);

	uint16_t _divider = ((MAP_PRCMPeripheralClockGet(PRCM_GSPI) / (MAX_BITRATE / divider))  - 1);

	HWREG(SSIBASE + MCSPI_O_CH0CONF) &= ~SPI_CLKD_MASK;
	HWREG(SSIBASE + MCSPI_O_CH0CONF) |= ((_divider & 0x0000000F) << 2);

	HWREG(SSIBASE + MCSPI_O_CH0CTRL) &= ~SPI_EXTCLK_MASK;
	HWREG(SSIBASE + MCSPI_O_CH0CTRL) |= ((_divider & 0x00000FF0) << 4);
	SPIEnable(SSIBASE);
}

uint8_t SPIClass::transfer(uint8_t data)
{
	uint32_t rxtxData;
	uint8_t rxData;

	if(SSIBitOrder == LSBFIRST) {
		rxtxData = data;
		asm("rbit %0, %1" : "=r" (rxtxData) : "r" (rxtxData));	// reverse order of 32 bits 
		asm("rev %0, %1" : "=r" (rxtxData) : "r" (rxtxData));	// reverse order of bytes to get original bits into lowest byte 
		data = (uint8_t) rxtxData;
	}

	MAP_SPITransfer(SSIBASE, &data, &rxData, 1, 0);

	if(SSIBitOrder == LSBFIRST) {
		rxtxData = rxData;
		asm("rbit %0, %1" : "=r" (rxtxData) : "r" (rxtxData));	// reverse order of 32 bits 
		asm("rev %0, %1" : "=r" (rxtxData) : "r" (rxtxData));	// reverse order of bytes to get original bits into lowest byte 
		rxData = (uint8_t) rxtxData;
	}

	return (uint8_t) rxData;
}

/* Only one module available in the CC3200
 * But we leave it in here in case there will
 * be variants with more modules in the future */
void SPIClass::setModule(uint8_t module) {
	SSIModule = module;
	begin();
}

SPIClass SPI(0);
