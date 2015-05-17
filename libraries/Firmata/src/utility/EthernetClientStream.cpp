/*
  EthernetClientStream.cpp
  An Arduino-Stream that wraps an instance of Client reconnecting to
  the remote-ip in a transparent way. A disconnected client may be
  recognized by the returnvalues -1 from calls to peek or read and
  a 0 from calls to write.

  Copyright (C) 2013 Norbert Truchsess. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.

  formatted using the GNU C formatting and indenting
 */

#include "EthernetClientStream.h"
#include <Arduino.h>

//#define SERIAL_DEBUG
#include "firmataDebug.h"

#define MILLIS_RECONNECT 5000

EthernetClientStream::EthernetClientStream(Client &client, IPAddress localip, IPAddress ip, const char* host, uint16_t port)
: ip(ip),
  host(host),
  port(port),
  connected(false),
  client(client),
  localip(localip)
{
}

int
EthernetClientStream::available()
{
  return maintain() ? client.available() : 0;
}

int
EthernetClientStream::read()
{
  return maintain() ? client.read() : -1;
}

int
EthernetClientStream::peek()
{
  return maintain() ? client.peek() : -1;
}

void EthernetClientStream::flush()
{
  if (maintain())
    client.flush();
}

size_t
EthernetClientStream::write(uint8_t c)
{
  return maintain() ? client.write(c) : 0;
}

void
EthernetClientStream::maintain(IPAddress localip)
{
  if (this->localip!=localip)
    {
      this->localip = localip;
      if (connected)
        stop();
    }
}

void
EthernetClientStream::stop()
{
  client.stop();
  connected = false;
  time_connect = millis();
}

bool
EthernetClientStream::maintain()
{
  if (client && client.connected())
    return true;

  if (connected)
    {
      stop();
    }
  else if (millis()-time_connect >= MILLIS_RECONNECT)
    {
      connected = host ? client.connect(host,port) : client.connect(ip,port);
      if (!connected) {
        time_connect = millis();
        DEBUG_PRINTLN("connection failed");
      } else {
        DEBUG_PRINTLN("connected");
      }
    }
  return connected;
}
