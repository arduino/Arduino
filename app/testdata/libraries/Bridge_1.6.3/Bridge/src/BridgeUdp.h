/*
  Copyright (c) 2015 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once

#include <Udp.h>
#include "Bridge.h"

class BridgeUDP : public UDP {

  public:
    BridgeUDP(BridgeClass &_b = Bridge);
    virtual uint8_t begin(uint16_t);
    virtual void stop();

    virtual int beginPacket(IPAddress ip, uint16_t port);
    virtual int beginPacket(const char *host, uint16_t port);
    virtual int beginBroadcastPacket(uint16_t port);
    virtual int endPacket();
    virtual size_t write(uint8_t d) { return write(&d, 1); }
    virtual size_t write(const uint8_t *buffer, size_t size);

    using Print::write;

    virtual int parsePacket();
    /* return number of bytes available in the current packet,
       will return zero if parsePacket hasn't been called yet */
    virtual int available() { return avail; }
    virtual int read();
    virtual int read(unsigned char* buffer, size_t len);
    virtual int read(char* buffer, size_t len) { return read((unsigned char*)buffer, len); };
    virtual int peek();
    virtual void flush() { avail = 0; }

    virtual IPAddress remoteIP();
    virtual uint16_t remotePort();

  private:
    BridgeClass &bridge;
    uint8_t handle;
    boolean opened;

  private:
    void doBuffer();
    uint16_t avail;
    uint8_t buffered;
    uint8_t readPos;
    static const int BUFFER_SIZE = 64;
    uint8_t buffer[BUFFER_SIZE];
};
