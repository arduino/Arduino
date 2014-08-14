/*
 WiFiServer.h - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 modified: Noah Luskey | LuskeyNoah@gmail.com
 
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

#ifndef wifiserver_h
#define wifiserver_h

extern "C" {
    #include "utility/wl_definitions.h"
}
#include "Print.h"
#include "Server.h"

class WiFiClient;


//
//Inhereting from Print provides all the cool print format methods
//
class WiFiServer : public Server {
private:
    uint16_t _port;
    int _socketIndex;
    int8_t _lastServicedClient;
public:
    WiFiServer(uint16_t);
    WiFiClient available(uint8_t* status = NULL);
    void begin();
    virtual size_t write(uint8_t);
    size_t write(const uint8_t *buffer, size_t size);
    uint8_t status();

};

#endif
