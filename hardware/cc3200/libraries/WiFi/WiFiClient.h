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
#include "Stream.h"
#include "Client.h"


#define TCP_RX_BUFF_MAX_SIZE 255

//
//Inhereting from stream (which inherits from print)
//provides all the cool parse read methods and print format methods
//
class WiFiClient : public Client {
    
public:
    WiFiClient();
    WiFiClient(uint8_t sock);
    ~WiFiClient();
    
    uint8_t status();
    virtual int connect(IPAddress ip, uint16_t port);
    virtual int connect(const char *host, uint16_t port);
    virtual int sslConnect(IPAddress ip, uint16_t port);
    virtual int sslConnect(const char *host, uint16_t port);
    // SSL root CA verification is a work in progress
    //virtual int sslRootCA(const uint8_t *rootCAfilecontents, const size_t);
    //virtual int useRootCA(void);
    //virtual void sslStrict(boolean);
    //virtual int32_t sslGetReasonID(void);
    //virtual const char *sslGetReason(void);
    virtual size_t write(uint8_t);
    virtual size_t write(const uint8_t *buffer, size_t size);
    virtual int available();
    virtual int read();
    virtual int read(uint8_t* buf, size_t size);
    virtual int peek();
    virtual void flush();
    virtual void stop();
    virtual uint8_t connected();
    virtual operator bool();
    
    friend class WiFiServer;

    boolean sslIsVerified;
    
private:
    int _socketIndex;
    uint8_t rx_buffer[TCP_RX_BUFF_MAX_SIZE] = {0};
    int rx_fillLevel;
    int rx_currentIndex;
    boolean sslVerifyStrict;
    boolean hasRootCA;
    int32_t sslLastError;
};

#endif
