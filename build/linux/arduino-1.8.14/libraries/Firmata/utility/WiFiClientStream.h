/*
  WiFiClientStream.h

  An Arduino Stream that wraps an instance of a WiFiClient. For use
  with legacy Arduino WiFi shield and other boards and shields that
  are compatible with the Arduino WiFi library.

  Copyright (C) 2016 Jens B. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.

  Parts of this class are based on

  - EthernetClientStream - Copyright (C) 2013 Norbert Truchsess. All rights reserved.

  published under the same license.

  Last updated April 23rd, 2016
 */

#ifndef WIFI_CLIENT_STREAM_H
#define WIFI_CLIENT_STREAM_H

#include "WiFiStream.h"

#define MILLIS_RECONNECT 5000

class WiFiClientStream : public WiFiStream
{
protected:
  uint32_t _time_connect = 0;

  /**
   * check if TCP client is connected
   * @return true if connected
   */
  virtual inline bool connect_client()
  {
    if ( _connected )
    {
      if ( _client && _client.connected() ) return true;
      stop();
    }

    // active TCP connect
    if ( WiFi.status() == WL_CONNECTED )
    {
      // if the client is disconnected, try to reconnect every 5 seconds
      if ( millis() - _time_connect >= MILLIS_RECONNECT )
      {
        _connected = _client.connect( _remote_ip, _port );
        if ( !_connected )
        {
          _time_connect = millis();
        }
        else if ( _currentHostConnectionCallback )
        {
          (*_currentHostConnectionCallback)(HOST_CONNECTION_CONNECTED);
        }
      }
    }

    return _connected;
  }

public:
  /**
   * create a WiFi stream with a TCP client
   */
  WiFiClientStream(IPAddress server_ip, uint16_t server_port) : WiFiStream(server_ip, server_port) {}

  /**
   * maintain WiFi and TCP connection
   * @return true if WiFi and TCP connection are established
   */
  virtual inline bool maintain()
  {
    return connect_client();
  }

  /**
   * stop client connection
   */
  virtual inline void stop()
  {
    if ( _client)
    {
      _client.stop();
      if ( _currentHostConnectionCallback )
      {
        (*_currentHostConnectionCallback)(HOST_CONNECTION_DISCONNECTED);
      }
    }
    _connected = false;
    _time_connect = millis();
  }

};

#endif //WIFI_CLIENT_STREAM_H
