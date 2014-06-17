/*
 WiFiClient.cpp - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 Author: Noah Luskey | LuskeyNoah@gmail.com
 
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

extern "C" {
  #include "utility/wl_definitions.h"
}

#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"


uint16_t WiFiClient::_srcport = 1024;

WiFiClient::WiFiClient() : _sock(MAX_SOCK_NUM) {
}

WiFiClient::WiFiClient(uint8_t sock) : _sock(sock) {
}

int WiFiClient::connect(const char* host, uint16_t port)
{
}

int WiFiClient::connect(IPAddress ip, uint16_t port)
{
}

size_t WiFiClient::write(uint8_t b)
{
}

size_t WiFiClient::write(const uint8_t *buf, size_t size)
{
}


int WiFiClient::read(uint8_t* buf, size_t size)
{
}

int WiFiClient::peek()
{
}

void WiFiClient::flush()
{
}

void WiFiClient::stop()
{
}

uint8_t WiFiClient::connected()
{
}

uint8_t WiFiClient::status()
{
}

WiFiClient::operator bool()
{
}

// Private Methods
uint8_t WiFiClient::getFirstSocket()
{
}

