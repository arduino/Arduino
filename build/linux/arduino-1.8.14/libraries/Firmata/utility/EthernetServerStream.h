/*
  EthernetServerStream.h

  Copyright (C) 2017 Marc Josef Pees. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.

  Last updated July 10th, 2017
 */

#ifndef ETHERNETSERVERSTREAM_H
#define ETHERNETSERVERSTREAM_H

#include <inttypes.h>
#include <Stream.h>
#include <Ethernet.h>

//#define SERIAL_DEBUG
#include "firmataDebug.h"

class EthernetServerStream : public Stream
{
  public:
    EthernetServerStream(IPAddress localip, uint16_t port);
    int available();
    int read();
    int peek();
    void flush();
    size_t write(uint8_t);
    void maintain(IPAddress localip);

  private:
    EthernetClient client;
    IPAddress localip;
    uint16_t port;
    bool connected;
    bool maintain();
    void stop();
    
  protected:
    EthernetServer server = EthernetServer(3030);
    bool listening = false;
    bool connect_client();
};


/*
 * EthernetServerStream.cpp
 * Copied here as a hack to linker issues with 3rd party board packages that don't properly
 * implement the Arduino network APIs.
 */
EthernetServerStream::EthernetServerStream(IPAddress localip, uint16_t port)
  : localip(localip),
    port(port),
    connected(false)
{
}

bool EthernetServerStream::connect_client()
  {
    if ( connected )
    {
      if ( client && client.connected() ) return true;
      stop();
    }

    EthernetClient newClient = server.available();
    if ( !newClient ) return false;
    client = newClient;
    connected = true;
    DEBUG_PRINTLN("Connected");
    return true;
  }

int
EthernetServerStream::available()
{
  return maintain() ? client.available() : 0;
}

int
EthernetServerStream::read()
{
  return maintain() ? client.read() : -1;
}

int
EthernetServerStream::peek()
{
  return maintain() ? client.peek() : -1;
}

void EthernetServerStream::flush()
{
  if (maintain())
    client.flush();
}

size_t
EthernetServerStream::write(uint8_t c)
{
  return maintain() ? client.write(c) : 0;
}

void
EthernetServerStream::maintain(IPAddress localip)
{
  // ensure the local IP is updated in the case that it is changed by the DHCP server
  if (this->localip != localip) {
    this->localip = localip;
    if (connected)
      stop();
  }
}

void
EthernetServerStream::stop()
{
  if(client)
  {
    client.stop();
  }
  connected = false;
}

bool
EthernetServerStream::maintain()
{
  if (connect_client()) return true;
  
  stop();
  
  if(!listening)
  {
    server = EthernetServer(port);
    server.begin();
    listening = true;
  }
  return false;
}

#endif /* ETHERNETSERVERSTREAM_H */
