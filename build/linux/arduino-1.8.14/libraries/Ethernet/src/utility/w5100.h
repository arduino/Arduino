/*
 * Copyright 2018 Paul Stoffregen
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

// w5100.h contains private W5x00 hardware "driver" level definitions
// which are not meant to be exposed to other libraries or Arduino users

#ifndef	W5100_H_INCLUDED
#define	W5100_H_INCLUDED

#include <Arduino.h>
#include <SPI.h>

// Safe for all chips
#define SPI_ETHERNET_SETTINGS SPISettings(14000000, MSBFIRST, SPI_MODE0)

// Safe for W5200 and W5500, but too fast for W5100
// Uncomment this if you know you'll never need W5100 support.
//  Higher SPI clock only results in faster transfer to hosts on a LAN
//  or with very low packet latency.  With ordinary internet latency,
//  the TCP window size & packet loss determine your overall speed.
//#define SPI_ETHERNET_SETTINGS SPISettings(30000000, MSBFIRST, SPI_MODE0)


// Require Ethernet.h, because we need MAX_SOCK_NUM
#ifndef ethernet_h_
#error "Ethernet.h must be included before w5100.h"
#endif


// Arduino 101's SPI can not run faster than 8 MHz.
#if defined(ARDUINO_ARCH_ARC32)
#undef SPI_ETHERNET_SETTINGS
#define SPI_ETHERNET_SETTINGS SPISettings(8000000, MSBFIRST, SPI_MODE0)
#endif

// Arduino Zero can't use W5100-based shields faster than 8 MHz
// https://github.com/arduino-libraries/Ethernet/issues/37#issuecomment-408036848
// W5500 does seem to work at 12 MHz.  Delete this if only using W5500
#if defined(__SAMD21G18A__)
#undef SPI_ETHERNET_SETTINGS
#define SPI_ETHERNET_SETTINGS SPISettings(8000000, MSBFIRST, SPI_MODE0)
#endif


typedef uint8_t SOCKET;

class SnMR {
public:
  static const uint8_t CLOSE  = 0x00;
  static const uint8_t TCP    = 0x21;
  static const uint8_t UDP    = 0x02;
  static const uint8_t IPRAW  = 0x03;
  static const uint8_t MACRAW = 0x04;
  static const uint8_t PPPOE  = 0x05;
  static const uint8_t ND     = 0x20;
  static const uint8_t MULTI  = 0x80;
};

enum SockCMD {
  Sock_OPEN      = 0x01,
  Sock_LISTEN    = 0x02,
  Sock_CONNECT   = 0x04,
  Sock_DISCON    = 0x08,
  Sock_CLOSE     = 0x10,
  Sock_SEND      = 0x20,
  Sock_SEND_MAC  = 0x21,
  Sock_SEND_KEEP = 0x22,
  Sock_RECV      = 0x40
};

class SnIR {
public:
  static const uint8_t SEND_OK = 0x10;
  static const uint8_t TIMEOUT = 0x08;
  static const uint8_t RECV    = 0x04;
  static const uint8_t DISCON  = 0x02;
  static const uint8_t CON     = 0x01;
};

class SnSR {
public:
  static const uint8_t CLOSED      = 0x00;
  static const uint8_t INIT        = 0x13;
  static const uint8_t LISTEN      = 0x14;
  static const uint8_t SYNSENT     = 0x15;
  static const uint8_t SYNRECV     = 0x16;
  static const uint8_t ESTABLISHED = 0x17;
  static const uint8_t FIN_WAIT    = 0x18;
  static const uint8_t CLOSING     = 0x1A;
  static const uint8_t TIME_WAIT   = 0x1B;
  static const uint8_t CLOSE_WAIT  = 0x1C;
  static const uint8_t LAST_ACK    = 0x1D;
  static const uint8_t UDP         = 0x22;
  static const uint8_t IPRAW       = 0x32;
  static const uint8_t MACRAW      = 0x42;
  static const uint8_t PPPOE       = 0x5F;
};

class IPPROTO {
public:
  static const uint8_t IP   = 0;
  static const uint8_t ICMP = 1;
  static const uint8_t IGMP = 2;
  static const uint8_t GGP  = 3;
  static const uint8_t TCP  = 6;
  static const uint8_t PUP  = 12;
  static const uint8_t UDP  = 17;
  static const uint8_t IDP  = 22;
  static const uint8_t ND   = 77;
  static const uint8_t RAW  = 255;
};

enum W5100Linkstatus {
  UNKNOWN,
  LINK_ON,
  LINK_OFF
};

class W5100Class {

public:
  static uint8_t init(void);

  inline void setGatewayIp(const uint8_t * addr) { writeGAR(addr); }
  inline void getGatewayIp(uint8_t * addr) { readGAR(addr); }

  inline void setSubnetMask(const uint8_t * addr) { writeSUBR(addr); }
  inline void getSubnetMask(uint8_t * addr) { readSUBR(addr); }

  inline void setMACAddress(const uint8_t * addr) { writeSHAR(addr); }
  inline void getMACAddress(uint8_t * addr) { readSHAR(addr); }

  inline void setIPAddress(const uint8_t * addr) { writeSIPR(addr); }
  inline void getIPAddress(uint8_t * addr) { readSIPR(addr); }

  inline void setRetransmissionTime(uint16_t timeout) { writeRTR(timeout); }
  inline void setRetransmissionCount(uint8_t retry) { writeRCR(retry); }

  static void execCmdSn(SOCKET s, SockCMD _cmd);


  // W5100 Registers
  // ---------------
//private:
public:
  static uint16_t write(uint16_t addr, const uint8_t *buf, uint16_t len);
  static uint8_t write(uint16_t addr, uint8_t data) {
    return write(addr, &data, 1);
  }
  static uint16_t read(uint16_t addr, uint8_t *buf, uint16_t len);
  static uint8_t read(uint16_t addr) {
    uint8_t data;
    read(addr, &data, 1);
    return data;
  }

#define __GP_REGISTER8(name, address)             \
  static inline void write##name(uint8_t _data) { \
    write(address, _data);                        \
  }                                               \
  static inline uint8_t read##name() {            \
    return read(address);                         \
  }
#define __GP_REGISTER16(name, address)            \
  static void write##name(uint16_t _data) {       \
    uint8_t buf[2];                               \
    buf[0] = _data >> 8;                          \
    buf[1] = _data & 0xFF;                        \
    write(address, buf, 2);                       \
  }                                               \
  static uint16_t read##name() {                  \
    uint8_t buf[2];                               \
    read(address, buf, 2);                        \
    return (buf[0] << 8) | buf[1];                \
  }
#define __GP_REGISTER_N(name, address, size)      \
  static uint16_t write##name(const uint8_t *_buff) {   \
    return write(address, _buff, size);           \
  }                                               \
  static uint16_t read##name(uint8_t *_buff) {    \
    return read(address, _buff, size);            \
  }
  static W5100Linkstatus getLinkStatus();

public:
  __GP_REGISTER8 (MR,     0x0000);    // Mode
  __GP_REGISTER_N(GAR,    0x0001, 4); // Gateway IP address
  __GP_REGISTER_N(SUBR,   0x0005, 4); // Subnet mask address
  __GP_REGISTER_N(SHAR,   0x0009, 6); // Source MAC address
  __GP_REGISTER_N(SIPR,   0x000F, 4); // Source IP address
  __GP_REGISTER8 (IR,     0x0015);    // Interrupt
  __GP_REGISTER8 (IMR,    0x0016);    // Interrupt Mask
  __GP_REGISTER16(RTR,    0x0017);    // Timeout address
  __GP_REGISTER8 (RCR,    0x0019);    // Retry count
  __GP_REGISTER8 (RMSR,   0x001A);    // Receive memory size (W5100 only)
  __GP_REGISTER8 (TMSR,   0x001B);    // Transmit memory size (W5100 only)
  __GP_REGISTER8 (PATR,   0x001C);    // Authentication type address in PPPoE mode
  __GP_REGISTER8 (PTIMER, 0x0028);    // PPP LCP Request Timer
  __GP_REGISTER8 (PMAGIC, 0x0029);    // PPP LCP Magic Number
  __GP_REGISTER_N(UIPR,   0x002A, 4); // Unreachable IP address in UDP mode (W5100 only)
  __GP_REGISTER16(UPORT,  0x002E);    // Unreachable Port address in UDP mode (W5100 only)
  __GP_REGISTER8 (VERSIONR_W5200,0x001F);   // Chip Version Register (W5200 only)
  __GP_REGISTER8 (VERSIONR_W5500,0x0039);   // Chip Version Register (W5500 only)
  __GP_REGISTER8 (PSTATUS_W5200,     0x0035);    // PHY Status
  __GP_REGISTER8 (PHYCFGR_W5500,     0x002E);    // PHY Configuration register, default: 10111xxx


#undef __GP_REGISTER8
#undef __GP_REGISTER16
#undef __GP_REGISTER_N

  // W5100 Socket registers
  // ----------------------
private:
  static uint16_t CH_BASE(void) {
    //if (chip == 55) return 0x1000;
    //if (chip == 52) return 0x4000;
    //return 0x0400;
    return CH_BASE_MSB << 8;
  }
  static uint8_t CH_BASE_MSB; // 1 redundant byte, saves ~80 bytes code on AVR
  static const uint16_t CH_SIZE = 0x0100;

  static inline uint8_t readSn(SOCKET s, uint16_t addr) {
    return read(CH_BASE() + s * CH_SIZE + addr);
  }
  static inline uint8_t writeSn(SOCKET s, uint16_t addr, uint8_t data) {
    return write(CH_BASE() + s * CH_SIZE + addr, data);
  }
  static inline uint16_t readSn(SOCKET s, uint16_t addr, uint8_t *buf, uint16_t len) {
    return read(CH_BASE() + s * CH_SIZE + addr, buf, len);
  }
  static inline uint16_t writeSn(SOCKET s, uint16_t addr, uint8_t *buf, uint16_t len) {
    return write(CH_BASE() + s * CH_SIZE + addr, buf, len);
  }

#define __SOCKET_REGISTER8(name, address)                    \
  static inline void write##name(SOCKET _s, uint8_t _data) { \
    writeSn(_s, address, _data);                             \
  }                                                          \
  static inline uint8_t read##name(SOCKET _s) {              \
    return readSn(_s, address);                              \
  }
#define __SOCKET_REGISTER16(name, address)                   \
  static void write##name(SOCKET _s, uint16_t _data) {       \
    uint8_t buf[2];                                          \
    buf[0] = _data >> 8;                                     \
    buf[1] = _data & 0xFF;                                   \
    writeSn(_s, address, buf, 2);                            \
  }                                                          \
  static uint16_t read##name(SOCKET _s) {                    \
    uint8_t buf[2];                                          \
    readSn(_s, address, buf, 2);                             \
    return (buf[0] << 8) | buf[1];                           \
  }
#define __SOCKET_REGISTER_N(name, address, size)             \
  static uint16_t write##name(SOCKET _s, uint8_t *_buff) {   \
    return writeSn(_s, address, _buff, size);                \
  }                                                          \
  static uint16_t read##name(SOCKET _s, uint8_t *_buff) {    \
    return readSn(_s, address, _buff, size);                 \
  }

public:
  __SOCKET_REGISTER8(SnMR,        0x0000)        // Mode
  __SOCKET_REGISTER8(SnCR,        0x0001)        // Command
  __SOCKET_REGISTER8(SnIR,        0x0002)        // Interrupt
  __SOCKET_REGISTER8(SnSR,        0x0003)        // Status
  __SOCKET_REGISTER16(SnPORT,     0x0004)        // Source Port
  __SOCKET_REGISTER_N(SnDHAR,     0x0006, 6)     // Destination Hardw Addr
  __SOCKET_REGISTER_N(SnDIPR,     0x000C, 4)     // Destination IP Addr
  __SOCKET_REGISTER16(SnDPORT,    0x0010)        // Destination Port
  __SOCKET_REGISTER16(SnMSSR,     0x0012)        // Max Segment Size
  __SOCKET_REGISTER8(SnPROTO,     0x0014)        // Protocol in IP RAW Mode
  __SOCKET_REGISTER8(SnTOS,       0x0015)        // IP TOS
  __SOCKET_REGISTER8(SnTTL,       0x0016)        // IP TTL
  __SOCKET_REGISTER8(SnRX_SIZE,   0x001E)        // RX Memory Size (W5200 only)
  __SOCKET_REGISTER8(SnTX_SIZE,   0x001F)        // RX Memory Size (W5200 only)
  __SOCKET_REGISTER16(SnTX_FSR,   0x0020)        // TX Free Size
  __SOCKET_REGISTER16(SnTX_RD,    0x0022)        // TX Read Pointer
  __SOCKET_REGISTER16(SnTX_WR,    0x0024)        // TX Write Pointer
  __SOCKET_REGISTER16(SnRX_RSR,   0x0026)        // RX Free Size
  __SOCKET_REGISTER16(SnRX_RD,    0x0028)        // RX Read Pointer
  __SOCKET_REGISTER16(SnRX_WR,    0x002A)        // RX Write Pointer (supported?)

#undef __SOCKET_REGISTER8
#undef __SOCKET_REGISTER16
#undef __SOCKET_REGISTER_N


private:
  static uint8_t chip;
  static uint8_t ss_pin;
  static uint8_t softReset(void);
  static uint8_t isW5100(void);
  static uint8_t isW5200(void);
  static uint8_t isW5500(void);

public:
  static uint8_t getChip(void) { return chip; }
#ifdef ETHERNET_LARGE_BUFFERS
  static uint16_t SSIZE;
  static uint16_t SMASK;
#else
  static const uint16_t SSIZE = 2048;
  static const uint16_t SMASK = 0x07FF;
#endif
  static uint16_t SBASE(uint8_t socknum) {
    if (chip == 51) {
      return socknum * SSIZE + 0x4000;
    } else {
      return socknum * SSIZE + 0x8000;
    }
  }
  static uint16_t RBASE(uint8_t socknum) {
    if (chip == 51) {
      return socknum * SSIZE + 0x6000;
    } else {
      return socknum * SSIZE + 0xC000;
    }
  }

  static bool hasOffsetAddressMapping(void) {
    if (chip == 55) return true;
    return false;
  }
  static void setSS(uint8_t pin) { ss_pin = pin; }

private:
#if defined(__AVR__)
	static volatile uint8_t *ss_pin_reg;
	static uint8_t ss_pin_mask;
	inline static void initSS() {
		ss_pin_reg = portOutputRegister(digitalPinToPort(ss_pin));
		ss_pin_mask = digitalPinToBitMask(ss_pin);
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		*(ss_pin_reg) &= ~ss_pin_mask;
	}
	inline static void resetSS() {
		*(ss_pin_reg) |= ss_pin_mask;
	}
#elif defined(__MK20DX128__) || defined(__MK20DX256__) || defined(__MK66FX1M0__) || defined(__MK64FX512__)
	static volatile uint8_t *ss_pin_reg;
	inline static void initSS() {
		ss_pin_reg = portOutputRegister(ss_pin);
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		*(ss_pin_reg+256) = 1;
	}
	inline static void resetSS() {
		*(ss_pin_reg+128) = 1;
	}
#elif defined(__MKL26Z64__)
	static volatile uint8_t *ss_pin_reg;
	static uint8_t ss_pin_mask;
	inline static void initSS() {
		ss_pin_reg = portOutputRegister(digitalPinToPort(ss_pin));
		ss_pin_mask = digitalPinToBitMask(ss_pin);
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		*(ss_pin_reg+8) = ss_pin_mask;
	}
	inline static void resetSS() {
		*(ss_pin_reg+4) = ss_pin_mask;
	}
#elif defined(__SAM3X8E__) || defined(__SAM3A8C__) || defined(__SAM3A4C__)
	static volatile uint32_t *ss_pin_reg;
	static uint32_t ss_pin_mask;
	inline static void initSS() {
		ss_pin_reg = &(digitalPinToPort(ss_pin)->PIO_PER);
		ss_pin_mask = digitalPinToBitMask(ss_pin);
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		*(ss_pin_reg+13) = ss_pin_mask;
	}
	inline static void resetSS() {
		*(ss_pin_reg+12) = ss_pin_mask;
	}
#elif defined(__PIC32MX__)
	static volatile uint32_t *ss_pin_reg;
	static uint32_t ss_pin_mask;
	inline static void initSS() {
		ss_pin_reg = portModeRegister(digitalPinToPort(ss_pin));
		ss_pin_mask = digitalPinToBitMask(ss_pin);
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		*(ss_pin_reg+8+1) = ss_pin_mask;
	}
	inline static void resetSS() {
		*(ss_pin_reg+8+2) = ss_pin_mask;
	}

#elif defined(ARDUINO_ARCH_ESP8266)
	static volatile uint32_t *ss_pin_reg;
	static uint32_t ss_pin_mask;
	inline static void initSS() {
		ss_pin_reg = (volatile uint32_t*)GPO;
		ss_pin_mask = 1 << ss_pin;
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		GPOC = ss_pin_mask;
	}
	inline static void resetSS() {
		GPOS = ss_pin_mask;
	}

#elif defined(__SAMD21G18A__)
	static volatile uint32_t *ss_pin_reg;
	static uint32_t ss_pin_mask;
	inline static void initSS() {
		ss_pin_reg = portModeRegister(digitalPinToPort(ss_pin));
		ss_pin_mask = digitalPinToBitMask(ss_pin);
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		*(ss_pin_reg+5) = ss_pin_mask;
	}
	inline static void resetSS() {
		*(ss_pin_reg+6) = ss_pin_mask;
	}
#else
	inline static void initSS() {
		pinMode(ss_pin, OUTPUT);
	}
	inline static void setSS() {
		digitalWrite(ss_pin, LOW);
	}
	inline static void resetSS() {
		digitalWrite(ss_pin, HIGH);
	}
#endif
};

extern W5100Class W5100;



#endif

#ifndef UTIL_H
#define UTIL_H

#define htons(x) ( (((x)<<8)&0xFF00) | (((x)>>8)&0xFF) )
#define ntohs(x) htons(x)

#define htonl(x) ( ((x)<<24 & 0xFF000000UL) | \
                   ((x)<< 8 & 0x00FF0000UL) | \
                   ((x)>> 8 & 0x0000FF00UL) | \
                   ((x)>>24 & 0x000000FFUL) )
#define ntohl(x) htonl(x)

#endif
