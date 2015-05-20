/*
  EthernetClientStream.h
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

#ifndef ETHERNETCLIENTSTREAM_H
#define ETHERNETCLIENTSTREAM_H

#include <inttypes.h>
#include <stdio.h>
#include <Stream.h>
#include <Client.h>
#include <IPAddress.h>

class EthernetClientStream : public Stream
{
public:
  EthernetClientStream(Client &client, IPAddress localip, IPAddress ip, const char* host, uint16_t port);
  int available();
  int read();
  int peek();
  void flush();
  size_t write(uint8_t);
  void maintain(IPAddress localip);

private:
  IPAddress localip;
  IPAddress ip;
  const char* host;
  uint16_t port;
  Client &client;
  bool connected;
  uint32_t time_connect;
  bool maintain();
  void stop();
};

#endif
