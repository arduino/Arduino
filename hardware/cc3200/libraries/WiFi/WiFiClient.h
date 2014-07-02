/*
 WiFiClient.h - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 Modified: Noah Luskey | LuskeyNoah@gmail.com
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef wificlient_h
#define wificlient_h
#include "Arduino.h"
#include "IPAddress.h"

#define TCP_RX_BUFF_MAX_SIZE 255

class WiFiClient {
    
public:
    WiFiClient();
    WiFiClient(uint8_t sock);
    
    uint8_t status();
    virtual int connect(IPAddress ip, uint16_t port);
    virtual int connect(char *host, uint16_t port);
    virtual size_t write(uint8_t);
    virtual size_t write(uint8_t *buf, size_t size);
    virtual size_t print(char* buffer);
    virtual size_t println(char* buffer);
    virtual size_t println(void);
    virtual int available();
    virtual uint8_t read();
    virtual int read(uint8_t* buf, size_t size);
    virtual uint8_t peek();
    virtual void flush();
    virtual void stop();
    virtual bool connected();
    virtual operator bool();
    
    friend class WiFiServer;
    
private:
    int _socketIndex;
    uint8_t rx_buffer[TCP_RX_BUFF_MAX_SIZE] = {0};
    int rx_fillLevel;
    int rx_currentIndex;
    
};

#endif
