/*
  WiFiStream.h

  An Arduino Stream extension for a WiFiClient or WiFiServer to be used
  with legacy Arduino WiFi shield and other boards and shields that
  are compatible with the Arduino WiFi library.

  Copyright (C) 2015-2016 Jesse Frush. All rights reserved.
  Copyright (C) 2016      Jens B. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.

  Last updated April 23rd, 2016
 */

#ifndef WIFI_STREAM_H
#define WIFI_STREAM_H

#include <inttypes.h>
#include <Stream.h>

#define HOST_CONNECTION_DISCONNECTED 0
#define HOST_CONNECTION_CONNECTED    1

extern "C" {
  // callback function types
  typedef void (*hostConnectionCallbackFunction)(byte);
}

class WiFiStream : public Stream
{
protected:
  WiFiClient _client;
  bool _connected = false;
  hostConnectionCallbackFunction _currentHostConnectionCallback;

  //configuration members
  IPAddress _local_ip;                // DHCP
  IPAddress _subnet;
  IPAddress _gateway;
  IPAddress _remote_ip;
  uint16_t _port;
  uint8_t _key_idx;                   //WEP
  const char *_key = nullptr;         //WEP
  const char *_passphrase = nullptr;  //WPA
  char *_ssid = nullptr;

  /**
   * check if TCP client is connected
   * @return true if connected
   */
  virtual bool connect_client() = 0;

public:
  /** constructor for TCP server */
  WiFiStream(uint16_t server_port) : _port(server_port) {}

  /** constructor for TCP client */
  WiFiStream(IPAddress server_ip, uint16_t server_port) : _remote_ip(server_ip), _port(server_port) {}

  inline void attach( hostConnectionCallbackFunction newFunction ) { _currentHostConnectionCallback = newFunction; }

/******************************************************************************
 *           network configuration
 ******************************************************************************/

#ifndef ESP8266
  /**
   * configure a static local IP address without defining the local network
   * DHCP will be used as long as local IP address is not defined
   */
  inline void config(IPAddress local_ip)
  {
    _local_ip = local_ip;
    WiFi.config( local_ip );
  }
#endif

  /**
   * configure a static local IP address
   * DHCP will be used as long as local IP address is not defined
   */
  inline void config(IPAddress local_ip, IPAddress gateway, IPAddress subnet)
  {
    _local_ip = local_ip;
    _subnet = subnet;
    _gateway = gateway;
#ifndef ESP8266
    WiFi.config( local_ip, IPAddress(0, 0, 0, 0), gateway, subnet );
#else
    WiFi.config( local_ip, gateway, subnet );
#endif
  }

  /**
   * @return local IP address
   */
  inline IPAddress getLocalIP()
  {
    return WiFi.localIP();
  }

/******************************************************************************
 *           network functions
 ******************************************************************************/

  /**
   * maintain WiFi and TCP connection
   * @return true if WiFi and TCP connection are established
   */
  virtual bool maintain() = 0;

#ifdef ESP8266
  /**
   * get status of TCP connection
   * @return status of TCP connection
   *         CLOSED      = 0 (typical)
   *         LISTEN      = 1 (not used)
   *         SYN_SENT    = 2
   *         SYN_RCVD    = 3
   *         ESTABLISHED = 4 (typical)
   *         FIN_WAIT_1  = 5
   *         FIN_WAIT_2  = 6
   *         CLOSE_WAIT  = 7
   *         CLOSING     = 8
   *         LAST_ACK    = 9
   *         TIME_WAIT   = 10
   */
  inline uint8_t status()
  {
    return _client.status();
  }
#endif

  /**
   * close TCP client connection
   */
  virtual void stop() = 0;

/******************************************************************************
 *           WiFi configuration
 ******************************************************************************/

  /**
   * initialize WiFi without security (open) and initiate client connection
   * if WiFi connection is already established
   * @return WL_CONNECTED if WiFi connection is established
   */
  inline int begin(char *ssid)
  {
    _ssid = ssid;

    WiFi.begin(ssid);
    int result = WiFi.status();
    return WiFi.status();
  }

#ifndef ESP8266
  /**
   * initialize WiFi with WEP security and initiate client connection
   * if WiFi connection is already established
   * @return WL_CONNECTED if WiFi connection is established
   */
  inline int begin(char *ssid, uint8_t key_idx, const char *key)
  {
    _ssid = ssid;
    _key_idx = key_idx;
    _key = key;

    WiFi.begin( ssid, key_idx, key );
    return WiFi.status();
  }
#endif

  /**
   * initialize WiFi with WPA-PSK security and initiate client connection
   * if WiFi connection is already established
   * @return WL_CONNECTED if WiFi connection is established
   */
  inline int begin(char *ssid, const char *passphrase)
  {
    _ssid = ssid;
    _passphrase = passphrase;

    WiFi.begin(ssid, passphrase);
    return WiFi.status();
  }


/******************************************************************************
 *             stream functions
 ******************************************************************************/

  inline int available()
  {
    return connect_client() ? _client.available() : 0;
  }

  inline void flush()
  {
    if( _client ) _client.flush();
  }

  inline int peek()
  {
    return connect_client() ? _client.peek(): 0;
  }

  inline int read()
  {
    return connect_client() ? _client.read() : -1;
  }

  inline size_t write(uint8_t byte)
  {
    return connect_client() ? _client.write( byte ) : 0;
  }

};

#endif //WIFI_STREAM_H
