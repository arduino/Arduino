/*
 * Copyright (c) 2010 by Arduino LLC. All rights reserved.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#include <stdio.h>
#include <string.h>

#include "w5100.h"

// W5x00 controller instance
W5x00Class W5100;

uint8_t W5x00Class::chipset = W5x00Chipset::W5100;
uint8_t W5x00Class::sockets = 4;

#define TX_RX_MAX_BUF_SIZE 2048
#define TX_BUF 0x1100
#define RX_BUF (TX_BUF + TX_RX_MAX_BUF_SIZE)

void W5x00Class::init(void)
{
  delay(300);

#if !defined(SPI_HAS_EXTENDED_CS_PIN_HANDLING)
  SPI.begin();
  initSS();
#else
  SPI.begin(ETHERNET_SHIELD_SPI_CS);
#endif

  /*
   * Runtime detection of Wiznet Chip.
   * Based on code from: https://github.com/jbkim/Differentiate-WIznet-Chip
   */
  uint8_t testW5200[] = { 0x00, 0x1F, 0x00, 0x01, 0x00 };
  uint8_t testW5500[] = { 0x00, 0x39, 0x00, 0x00 };
  SPI.beginTransaction(SPI_ETHERNET_SETTINGS);
#if !defined(SPI_HAS_EXTENDED_CS_PIN_HANDLING)
  // Check for W5200
  setSS();
  SPI.transfer(testW5200, 5);
  resetSS();
  if (testW5200[4] == 0x03) {
    chipset = W5x00Chipset::W5200;
  } else {
    // Check for W5500
    setSS();
    SPI.transfer(testW5500, 4);
    resetSS();
    if (testW5500[3] == 0x04) {
      chipset = W5x00Chipset::W5500;
    } else {
      chipset = W5x00Chipset::W5100;
    }
  }
#else
  // Check for W5200
  SPI.transfer(ETHERNET_SHIELD_SPI_CS, testW5200, 5);
  if (testW5200[4] == 0x03) {
    chipset = W5x00Chipset::W5200;
  } else {
    // Check for W5500
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, testW5500, 4);
    if (testW5500[3] == 0x04) {
      chipset = W5x00Chipset::W5500;
    } else {
      chipset = W5x00Chipset::W5100;
    }
  }
#endif
  SPI.endTransaction();

  // W5x00 reset
  if (chipset == W5x00Chipset::W5100) {
    sockets = 4;
    SPI.beginTransaction(SPI_ETHERNET_SETTINGS);
    writeMR(1<<RST);
    writeTMSR(0x55);
    writeRMSR(0x55);
    SPI.endTransaction();

    const uint16_t TXBUF_BASE = 0x4000;
    const uint16_t RXBUF_BASE = 0x6000;
    for (uint8_t i=0; i<sockets; i++) {
      SBASE[i] = TXBUF_BASE + SSIZE * i;
      RBASE[i] = RXBUF_BASE + RSIZE * i;
    }
  } else if (chipset == W5x00Chipset::W5200) {
    sockets = 8;
    SPI.beginTransaction(SPI_ETHERNET_SETTINGS);
    writeMR(1<<RST);
    for (uint8_t i=0; i<sockets; i++) {
      writeSnRXBUF_SIZE(i, 2);
      writeSnTXBUF_SIZE(i, 2);
    }
    SPI.endTransaction();

    const uint16_t TXBUF_BASE = 0x8000;
    const uint16_t RXBUF_BASE = 0xC000;
    for (uint8_t i=0; i<sockets; i++) {
      SBASE[i] = TXBUF_BASE + SSIZE * i;
      RBASE[i] = RXBUF_BASE + RSIZE * i;
    }
  } else {
    sockets = 8;
    SPI.beginTransaction(SPI_ETHERNET_SETTINGS);
    writeMR(1<<RST);
    for (uint8_t i=0; i<sockets; i++) {
      writeSnRXBUF_SIZE(i, 2);
      writeSnTXBUF_SIZE(i, 2);
    }
    SPI.endTransaction();
  }
}

uint16_t W5x00Class::getTXFreeSize(SOCKET s)
{
  uint16_t val=0, val1=0;
  do {
    val1 = readSnTX_FSR(s);
    if (val1 != 0)
      val = readSnTX_FSR(s);
  }
  while (val != val1);
  return val;
}

uint16_t W5x00Class::getRXReceivedSize(SOCKET s)
{
  uint16_t val=0,val1=0;
  do {
    val1 = readSnRX_RSR(s);
    if (val1 != 0)
      val = readSnRX_RSR(s);
  }
  while (val != val1);
  return val;
}

void W5x00Class::send_data_processing(SOCKET s, const uint8_t *data, uint16_t len)
{
  // This is same as having no offset in a call to send_data_processing_offset
  send_data_processing_offset(s, 0, data, len);
}

void W5x00Class::send_data_processing_offset(SOCKET s, uint16_t data_offset, const uint8_t *data, uint16_t len)
{
  uint16_t ptr = readSnTX_WR(s);
  ptr += data_offset;

  if (chipset != W5x00Chipset::W5500) {
    uint16_t offset = ptr & SMASK;
    uint16_t dstAddr = offset + SBASE[s];
    if (offset + len > SSIZE)
    {
      // Wrap around circular buffer
      uint16_t size = SSIZE - offset;
      write(dstAddr, 0x00, data, size);
      write(SBASE[s], 0x00, data + size, len - size);
    } else {
      write(dstAddr, 0x00, data, len);
    }
  } else {
    write(ptr, (s<<5) + 0x14, data, len);
  }

  ptr += len;
  writeSnTX_WR(s, ptr);
}

void W5x00Class::recv_data_processing(SOCKET s, uint8_t *data, uint16_t len, uint8_t peek)
{
  uint16_t ptr = readSnRX_RD(s);
  read_data(s, ptr, data, len);
  if (!peek)
  {
    ptr += len;
    writeSnRX_RD(s, ptr);
  }
}

void W5x00Class::read_data(SOCKET s, uint16_t src, uint8_t *dst, uint16_t len)
{
  if (chipset != W5x00Chipset::W5500) {
    uint16_t src_mask = src & RMASK;
    uint16_t src_ptr = RBASE[s] + src_mask;
    if ((src_mask + len) > RSIZE) {
      uint16_t size = RSIZE - src_mask;
      read(src_ptr, 0x00, dst, size);
      dst += size;
      read(RBASE[s], 0x00, dst, len - size);
    } else {
      read(src_ptr, 0x00, dst, len);
    }
  } else {
    read(src, (s<<5) + 0x18, dst, len);
  }
}


uint8_t W5x00Class::write(uint16_t _addr, uint8_t _cb, uint8_t _data)
{
#if !defined(SPI_HAS_EXTENDED_CS_PIN_HANDLING)
  setSS();
  if (chipset == W5x00Chipset::W5100) {
    SPI.transfer(0xF0);
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(_data);
  } else if (chipset == W5x00Chipset::W5200) {
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(0x80);
    SPI.transfer(0x01);
    SPI.transfer(_data);
  } else {
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(_cb);
    SPI.transfer(_data);
  }
  resetSS();
#else
  if (chipset == W5x00Chipset::W5100) {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0xF0, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _data);
  } else if (chipset == W5x00Chipset::W5200) {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0x80, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0x01, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _data);
  } else {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _cb, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _data);
  }
#endif
  return 1;
}

uint16_t W5x00Class::write(uint16_t _addr, uint8_t _cb, const uint8_t *_buf, uint16_t _len)
{
#if !defined(SPI_HAS_EXTENDED_CS_PIN_HANDLING)
  if (chipset == W5x00Chipset::W5100) {
    for (uint16_t i=0; i<_len; i++)
    {
      setSS();
      SPI.transfer(0xF0);
      SPI.transfer(_addr >> 8);
      SPI.transfer(_addr & 0xFF);
       _addr++;
      SPI.transfer(_buf[i]);
      resetSS();
    }
  } else if (chipset == W5x00Chipset::W5200) {
    if (_len == 0)
      return 0;
    setSS();
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(0x80 | ((_len & 0x7F00) >> 8));
    SPI.transfer(_len & 0xFF);
    for (uint16_t i=0; i<_len; i++) {
      SPI.transfer(_buf[i]);
    }
    resetSS();
  } else {
    setSS();
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(_cb);
    for (uint16_t i=0; i<_len; i++) {
      SPI.transfer(_buf[i]);
    }
    resetSS();
  }
#else
  uint16_t i;
  if (chipset == W5x00Chipset::W5100) {
    for (i=0; i<_len; i++)
    {
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0xF0, SPI_CONTINUE);
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, _buf[i]);
      _addr++;
    }
  } else if (chipset == W5x00Chipset::W5200) {
    if (_len == 0)
      return 0;
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0x80 | ((_len & 0x7F00) >> 8), SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _len & 0xFF, SPI_CONTINUE);
    for (i=0; i<_len-1; i++) {
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, _buf[i], SPI_CONTINUE);
    }
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _buf[i]);
  } else {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _cb, SPI_CONTINUE);
    for (i=0; i<_len-1; i++) {
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, _buf[i], SPI_CONTINUE);
    }
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _buf[i]);
  }
#endif
  return _len;
}

uint8_t W5x00Class::read(uint16_t _addr, uint8_t _cb)
{
  uint8_t res;
#if !defined(SPI_HAS_EXTENDED_CS_PIN_HANDLING)
  setSS();
  if (chipset == W5x00Chipset::W5100) {
    SPI.transfer(0x0F);
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    res = SPI.transfer(0);
  } else if (chipset == W5x00Chipset::W5200) {
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(0x00);
    SPI.transfer(0x01);
    res = SPI.transfer(0);
  } else {
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(_cb);
    res = SPI.transfer(0);
  }
  resetSS();
#else
  if (chipset == W5x00Chipset::W5100) {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0x0F, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    res = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0);
  } else if (chipset == W5x00Chipset::W5200) {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0x00, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0x01, SPI_CONTINUE);
    res = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0);
  } else {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _cb, SPI_CONTINUE);
    uint8_t _data = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0);
  }
#endif
  return res;
}

uint16_t W5x00Class::read(uint16_t _addr, uint8_t _cb, uint8_t *_buf, uint16_t _len)
{
#if !defined(SPI_HAS_EXTENDED_CS_PIN_HANDLING)
  if (chipset == W5x00Chipset::W5100) {
    for (uint16_t i=0; i<_len; i++)
    {
      setSS();
      SPI.transfer(0x0F);
      SPI.transfer(_addr >> 8);
      SPI.transfer(_addr & 0xFF);
      _addr++;
      _buf[i] = SPI.transfer(0);
      resetSS();
    }
  } else if (chipset == W5x00Chipset::W5200) {
    setSS();
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer((_len & 0x7F00) >> 8);
    SPI.transfer(_len & 0xFF);
    for (uint16_t i=0; i<_len; i++){
      _buf[i] = SPI.transfer(0);
    }
    resetSS();
  } else {
    setSS();
    SPI.transfer(_addr >> 8);
    SPI.transfer(_addr & 0xFF);
    SPI.transfer(_cb);
    for (uint16_t i=0; i<_len; i++){
      _buf[i] = SPI.transfer(0);
    }
    resetSS();
  }
#else
  uint16_t i;
  if (chipset == W5x00Chipset::W5100) {
    for (i=0; i<_len; i++)
    {
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0x0F, SPI_CONTINUE);
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
      SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
      _buf[i] = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0);
      _addr++;
    }
  } else if (chipset == W5x00Chipset::W5200) {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, (_len & 0x7F00) >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _len & 0xFF, SPI_CONTINUE);
    for (i=0; i<_len-1; i++){
      _buf[i] = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0, SPI_CONTINUE);
    }
    _buf[_len-1] = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0);
  } else {
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr >> 8, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _addr & 0xFF, SPI_CONTINUE);
    SPI.transfer(ETHERNET_SHIELD_SPI_CS, _cb, SPI_CONTINUE);
    for (i=0; i<_len-1; i++){
      _buf[i] = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0, SPI_CONTINUE);
    }
    _buf[_len-1] = SPI.transfer(ETHERNET_SHIELD_SPI_CS, 0);
  }
#endif

  return _len;
}

void W5x00Class::execCmdSn(SOCKET s, SockCMD _cmd) {
  // Send command to socket
  writeSnCR(s, _cmd);
  // Wait for command to complete
  while (readSnCR(s))
    ;
}

