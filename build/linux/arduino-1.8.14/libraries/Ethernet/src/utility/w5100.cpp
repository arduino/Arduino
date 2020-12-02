/*
 * Copyright 2018 Paul Stoffregen
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include <Arduino.h>
#include "Ethernet.h"
#include "w5100.h"


/***************************************************/
/**            Default SS pin setting             **/
/***************************************************/

// If variant.h or other headers specifically define the
// default SS pin for ethernet, use it.
#if defined(PIN_SPI_SS_ETHERNET_LIB)
#define SS_PIN_DEFAULT  PIN_SPI_SS_ETHERNET_LIB

// MKR boards default to pin 5 for MKR ETH
// Pins 8-10 are MOSI/SCK/MISO on MRK, so don't use pin 10
#elif defined(USE_ARDUINO_MKR_PIN_LAYOUT) || defined(ARDUINO_SAMD_MKRZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRWAN1300)
#define SS_PIN_DEFAULT  5

// For boards using AVR, assume shields with SS on pin 10
// will be used.  This allows for Arduino Mega (where
// SS is pin 53) and Arduino Leonardo (where SS is pin 17)
// to work by default with Arduino Ethernet Shield R2 & R3.
#elif defined(__AVR__)
#define SS_PIN_DEFAULT  10

// If variant.h or other headers define these names
// use them if none of the other cases match
#elif defined(PIN_SPI_SS)
#define SS_PIN_DEFAULT  PIN_SPI_SS
#elif defined(CORE_SS0_PIN)
#define SS_PIN_DEFAULT  CORE_SS0_PIN

// As a final fallback, use pin 10
#else
#define SS_PIN_DEFAULT  10
#endif




// W5100 controller instance
uint8_t  W5100Class::chip = 0;
uint8_t  W5100Class::CH_BASE_MSB;
uint8_t  W5100Class::ss_pin = SS_PIN_DEFAULT;
#ifdef ETHERNET_LARGE_BUFFERS
uint16_t W5100Class::SSIZE = 2048;
uint16_t W5100Class::SMASK = 0x07FF;
#endif
W5100Class W5100;

// pointers and bitmasks for optimized SS pin
#if defined(__AVR__)
  volatile uint8_t * W5100Class::ss_pin_reg;
  uint8_t W5100Class::ss_pin_mask;
#elif defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__MK66FX1M0__) || defined(__MK64FX512__)
  volatile uint8_t * W5100Class::ss_pin_reg;
#elif defined(__MKL26Z64__)
  volatile uint8_t * W5100Class::ss_pin_reg;
  uint8_t W5100Class::ss_pin_mask;
#elif defined(__SAM3X8E__) || defined(__SAM3A8C__) || defined(__SAM3A4C__)
  volatile uint32_t * W5100Class::ss_pin_reg;
  uint32_t W5100Class::ss_pin_mask;
#elif defined(__PIC32MX__)
  volatile uint32_t * W5100Class::ss_pin_reg;
  uint32_t W5100Class::ss_pin_mask;
#elif defined(ARDUINO_ARCH_ESP8266)
  volatile uint32_t * W5100Class::ss_pin_reg;
  uint32_t W5100Class::ss_pin_mask;
#elif defined(__SAMD21G18A__)
  volatile uint32_t * W5100Class::ss_pin_reg;
  uint32_t W5100Class::ss_pin_mask;
#endif


uint8_t W5100Class::init(void)
{
	static bool initialized = false;
	uint8_t i;

	if (initialized) return 1;

	// Many Ethernet shields have a CAT811 or similar reset chip
	// connected to W5100 or W5200 chips.  The W5200 will not work at
	// all, and may even drive its MISO pin, until given an active low
	// reset pulse!  The CAT811 has a 240 ms typical pulse length, and
	// a 400 ms worst case maximum pulse length.  MAX811 has a worst
	// case maximum 560 ms pulse length.  This delay is meant to wait
	// until the reset pulse is ended.  If your hardware has a shorter
	// reset time, this can be edited or removed.
	delay(560);
	//Serial.println("w5100 init");

	SPI.begin();
	initSS();
	resetSS();
	SPI.beginTransaction(SPI_ETHERNET_SETTINGS);

	// Attempt W5200 detection first, because W5200 does not properly
	// reset its SPI state when CS goes high (inactive).  Communication
	// from detecting the other chips can leave the W5200 in a state
	// where it won't recover, unless given a reset pulse.
	if (isW5200()) {
		CH_BASE_MSB = 0x40;
#ifdef ETHERNET_LARGE_BUFFERS
#if MAX_SOCK_NUM <= 1
		SSIZE = 16384;
#elif MAX_SOCK_NUM <= 2
		SSIZE = 8192;
#elif MAX_SOCK_NUM <= 4
		SSIZE = 4096;
#else
		SSIZE = 2048;
#endif
		SMASK = SSIZE - 1;
#endif
		for (i=0; i<MAX_SOCK_NUM; i++) {
			writeSnRX_SIZE(i, SSIZE >> 10);
			writeSnTX_SIZE(i, SSIZE >> 10);
		}
		for (; i<8; i++) {
			writeSnRX_SIZE(i, 0);
			writeSnTX_SIZE(i, 0);
		}
	// Try W5500 next.  Wiznet finally seems to have implemented
	// SPI well with this chip.  It appears to be very resilient,
	// so try it after the fragile W5200
	} else if (isW5500()) {
		CH_BASE_MSB = 0x10;
#ifdef ETHERNET_LARGE_BUFFERS
#if MAX_SOCK_NUM <= 1
		SSIZE = 16384;
#elif MAX_SOCK_NUM <= 2
		SSIZE = 8192;
#elif MAX_SOCK_NUM <= 4
		SSIZE = 4096;
#else
		SSIZE = 2048;
#endif
		SMASK = SSIZE - 1;
		for (i=0; i<MAX_SOCK_NUM; i++) {
			writeSnRX_SIZE(i, SSIZE >> 10);
			writeSnTX_SIZE(i, SSIZE >> 10);
		}
		for (; i<8; i++) {
			writeSnRX_SIZE(i, 0);
			writeSnTX_SIZE(i, 0);
		}
#endif
	// Try W5100 last.  This simple chip uses fixed 4 byte frames
	// for every 8 bit access.  Terribly inefficient, but so simple
	// it recovers from "hearing" unsuccessful W5100 or W5200
	// communication.  W5100 is also the only chip without a VERSIONR
	// register for identification, so we check this last.
	} else if (isW5100()) {
		CH_BASE_MSB = 0x04;
#ifdef ETHERNET_LARGE_BUFFERS
#if MAX_SOCK_NUM <= 1
		SSIZE = 8192;
		writeTMSR(0x03);
		writeRMSR(0x03);
#elif MAX_SOCK_NUM <= 2
		SSIZE = 4096;
		writeTMSR(0x0A);
		writeRMSR(0x0A);
#else
		SSIZE = 2048;
		writeTMSR(0x55);
		writeRMSR(0x55);
#endif
		SMASK = SSIZE - 1;
#else
		writeTMSR(0x55);
		writeRMSR(0x55);
#endif
	// No hardware seems to be present.  Or it could be a W5200
	// that's heard other SPI communication if its chip select
	// pin wasn't high when a SD card or other SPI chip was used.
	} else {
		//Serial.println("no chip :-(");
		chip = 0;
		SPI.endTransaction();
		return 0; // no known chip is responding :-(
	}
	SPI.endTransaction();
	initialized = true;
	return 1; // successful init
}

// Soft reset the Wiznet chip, by writing to its MR register reset bit
uint8_t W5100Class::softReset(void)
{
	uint16_t count=0;

	//Serial.println("Wiznet soft reset");
	// write to reset bit
	writeMR(0x80);
	// then wait for soft reset to complete
	do {
		uint8_t mr = readMR();
		//Serial.print("mr=");
		//Serial.println(mr, HEX);
		if (mr == 0) return 1;
		delay(1);
	} while (++count < 20);
	return 0;
}

uint8_t W5100Class::isW5100(void)
{
	chip = 51;
	//Serial.println("w5100.cpp: detect W5100 chip");
	if (!softReset()) return 0;
	writeMR(0x10);
	if (readMR() != 0x10) return 0;
	writeMR(0x12);
	if (readMR() != 0x12) return 0;
	writeMR(0x00);
	if (readMR() != 0x00) return 0;
	//Serial.println("chip is W5100");
	return 1;
}

uint8_t W5100Class::isW5200(void)
{
	chip = 52;
	//Serial.println("w5100.cpp: detect W5200 chip");
	if (!softReset()) return 0;
	writeMR(0x08);
	if (readMR() != 0x08) return 0;
	writeMR(0x10);
	if (readMR() != 0x10) return 0;
	writeMR(0x00);
	if (readMR() != 0x00) return 0;
	int ver = readVERSIONR_W5200();
	//Serial.print("version=");
	//Serial.println(ver);
	if (ver != 3) return 0;
	//Serial.println("chip is W5200");
	return 1;
}

uint8_t W5100Class::isW5500(void)
{
	chip = 55;
	//Serial.println("w5100.cpp: detect W5500 chip");
	if (!softReset()) return 0;
	writeMR(0x08);
	if (readMR() != 0x08) return 0;
	writeMR(0x10);
	if (readMR() != 0x10) return 0;
	writeMR(0x00);
	if (readMR() != 0x00) return 0;
	int ver = readVERSIONR_W5500();
	//Serial.print("version=");
	//Serial.println(ver);
	if (ver != 4) return 0;
	//Serial.println("chip is W5500");
	return 1;
}

W5100Linkstatus W5100Class::getLinkStatus()
{
	uint8_t phystatus;

	if (!init()) return UNKNOWN;
	switch (chip) {
	  case 52:
		SPI.beginTransaction(SPI_ETHERNET_SETTINGS);
		phystatus = readPSTATUS_W5200();
		SPI.endTransaction();
		if (phystatus & 0x20) return LINK_ON;
		return LINK_OFF;
	  case 55:
		SPI.beginTransaction(SPI_ETHERNET_SETTINGS);
		phystatus = readPHYCFGR_W5500();
		SPI.endTransaction();
		if (phystatus & 0x01) return LINK_ON;
		return LINK_OFF;
	  default:
		return UNKNOWN;
	}
}

uint16_t W5100Class::write(uint16_t addr, const uint8_t *buf, uint16_t len)
{
	uint8_t cmd[8];

	if (chip == 51) {
		for (uint16_t i=0; i<len; i++) {
			setSS();
			SPI.transfer(0xF0);
			SPI.transfer(addr >> 8);
			SPI.transfer(addr & 0xFF);
			addr++;
			SPI.transfer(buf[i]);
			resetSS();
		}
	} else if (chip == 52) {
		setSS();
		cmd[0] = addr >> 8;
		cmd[1] = addr & 0xFF;
		cmd[2] = ((len >> 8) & 0x7F) | 0x80;
		cmd[3] = len & 0xFF;
		SPI.transfer(cmd, 4);
#ifdef SPI_HAS_TRANSFER_BUF
		SPI.transfer(buf, NULL, len);
#else
		// TODO: copy 8 bytes at a time to cmd[] and block transfer
		for (uint16_t i=0; i < len; i++) {
			SPI.transfer(buf[i]);
		}
#endif
		resetSS();
	} else { // chip == 55
		setSS();
		if (addr < 0x100) {
			// common registers 00nn
			cmd[0] = 0;
			cmd[1] = addr & 0xFF;
			cmd[2] = 0x04;
		} else if (addr < 0x8000) {
			// socket registers  10nn, 11nn, 12nn, 13nn, etc
			cmd[0] = 0;
			cmd[1] = addr & 0xFF;
			cmd[2] = ((addr >> 3) & 0xE0) | 0x0C;
		} else if (addr < 0xC000) {
			// transmit buffers  8000-87FF, 8800-8FFF, 9000-97FF, etc
			//  10## #nnn nnnn nnnn
			cmd[0] = addr >> 8;
			cmd[1] = addr & 0xFF;
			#if defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 1
			cmd[2] = 0x14;                       // 16K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 2
			cmd[2] = ((addr >> 8) & 0x20) | 0x14; // 8K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 4
			cmd[2] = ((addr >> 7) & 0x60) | 0x14; // 4K buffers
			#else
			cmd[2] = ((addr >> 6) & 0xE0) | 0x14; // 2K buffers
			#endif
		} else {
			// receive buffers
			cmd[0] = addr >> 8;
			cmd[1] = addr & 0xFF;
			#if defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 1
			cmd[2] = 0x1C;                       // 16K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 2
			cmd[2] = ((addr >> 8) & 0x20) | 0x1C; // 8K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 4
			cmd[2] = ((addr >> 7) & 0x60) | 0x1C; // 4K buffers
			#else
			cmd[2] = ((addr >> 6) & 0xE0) | 0x1C; // 2K buffers
			#endif
		}
		if (len <= 5) {
			for (uint8_t i=0; i < len; i++) {
				cmd[i + 3] = buf[i];
			}
			SPI.transfer(cmd, len + 3);
		} else {
			SPI.transfer(cmd, 3);
#ifdef SPI_HAS_TRANSFER_BUF
			SPI.transfer(buf, NULL, len);
#else
			// TODO: copy 8 bytes at a time to cmd[] and block transfer
			for (uint16_t i=0; i < len; i++) {
				SPI.transfer(buf[i]);
			}
#endif
		}
		resetSS();
	}
	return len;
}

uint16_t W5100Class::read(uint16_t addr, uint8_t *buf, uint16_t len)
{
	uint8_t cmd[4];

	if (chip == 51) {
		for (uint16_t i=0; i < len; i++) {
			setSS();
			#if 1
			SPI.transfer(0x0F);
			SPI.transfer(addr >> 8);
			SPI.transfer(addr & 0xFF);
			addr++;
			buf[i] = SPI.transfer(0);
			#else
			cmd[0] = 0x0F;
			cmd[1] = addr >> 8;
			cmd[2] = addr & 0xFF;
			cmd[3] = 0;
			SPI.transfer(cmd, 4); // TODO: why doesn't this work?
			buf[i] = cmd[3];
			addr++;
			#endif
			resetSS();
		}
	} else if (chip == 52) {
		setSS();
		cmd[0] = addr >> 8;
		cmd[1] = addr & 0xFF;
		cmd[2] = (len >> 8) & 0x7F;
		cmd[3] = len & 0xFF;
		SPI.transfer(cmd, 4);
		memset(buf, 0, len);
		SPI.transfer(buf, len);
		resetSS();
	} else { // chip == 55
		setSS();
		if (addr < 0x100) {
			// common registers 00nn
			cmd[0] = 0;
			cmd[1] = addr & 0xFF;
			cmd[2] = 0x00;
		} else if (addr < 0x8000) {
			// socket registers  10nn, 11nn, 12nn, 13nn, etc
			cmd[0] = 0;
			cmd[1] = addr & 0xFF;
			cmd[2] = ((addr >> 3) & 0xE0) | 0x08;
		} else if (addr < 0xC000) {
			// transmit buffers  8000-87FF, 8800-8FFF, 9000-97FF, etc
			//  10## #nnn nnnn nnnn
			cmd[0] = addr >> 8;
			cmd[1] = addr & 0xFF;
			#if defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 1
			cmd[2] = 0x10;                       // 16K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 2
			cmd[2] = ((addr >> 8) & 0x20) | 0x10; // 8K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 4
			cmd[2] = ((addr >> 7) & 0x60) | 0x10; // 4K buffers
			#else
			cmd[2] = ((addr >> 6) & 0xE0) | 0x10; // 2K buffers
			#endif
		} else {
			// receive buffers
			cmd[0] = addr >> 8;
			cmd[1] = addr & 0xFF;
			#if defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 1
			cmd[2] = 0x18;                       // 16K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 2
			cmd[2] = ((addr >> 8) & 0x20) | 0x18; // 8K buffers
			#elif defined(ETHERNET_LARGE_BUFFERS) && MAX_SOCK_NUM <= 4
			cmd[2] = ((addr >> 7) & 0x60) | 0x18; // 4K buffers
			#else
			cmd[2] = ((addr >> 6) & 0xE0) | 0x18; // 2K buffers
			#endif
		}
		SPI.transfer(cmd, 3);
		memset(buf, 0, len);
		SPI.transfer(buf, len);
		resetSS();
	}
	return len;
}

void W5100Class::execCmdSn(SOCKET s, SockCMD _cmd)
{
	// Send command to socket
	writeSnCR(s, _cmd);
	// Wait for command to complete
	while (readSnCR(s)) ;
}
