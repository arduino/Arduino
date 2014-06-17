/*
 WiFiUdp.cpp - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
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
    #include "utility/SimpleLink.h"
    #include "utility/socket.h"
}

#include <string.h>

#include "WiFi.h"
#include "WiFiUdp.h"
#include "WiFiClient.h"
#include "WiFiServer.h"

WiFiUDP::WiFiUDP() : _sock(NO_SOCKET_AVAIL)
{
    //
    //fill the buffers with zeroes
    //
    memset(rx_buf, 0, sizeof(rx_buf));
    memset(tx_buf, 0, sizeof(tx_buf));
    
}

uint8_t WiFiUDP::begin(uint16_t port)
{
    
    //
    //get a socket from the WiFiClass (convoluted method from the arduino library)
    //
    int sock = WiFiClass::getSocket();
    if (sock == NO_SOCKET_AVAIL) {
        return 0;
    }
    
    //
    //get a socket handle from the simplelink api and make sure it's valid
    //
    int socketHandle = sl_Socket(SL_AF_INET, SL_SOCK_DGRAM, IPPROTO_UDP);
    if (socketHandle < 0) {
        return 0;
    }
    
    //
    //bind the socket to the requested port and check for success
    //if failure, gracefully close the socket and return
    //
    SlSockAddrIn_t portAddress;
    portAddress.sin_family = SL_AF_INET;
    portAddress.sin_port = sl_Htons(port);
    portAddress.sin_addr.s_addr = 0;
    int iRet = sl_Bind(socketHandle, (SlSockAddr_t*)&portAddress, sizeof(portAddress));
    if (iRet < 0) {
        sl_Close(socketHandle);
        return 0;
    }
    
    //
    //now that simplelink api calls are done, set the object's variables
    //
    _socketHandle = socketHandle;
    _port = port;
    _sock = sock;
    WiFiClass::_server_port[sock] = port;
    
    
}


int WiFiUDP::available()
{
    //
    //returns to number of bytes left to read in the current packet
    //bytesLeft should never be negative... but just in case it's restricted positive
    //
    int bytesLeft = rx_fillLevel - rx_currentIndex;
    if (bytesLeft < 0) {
        return 0;
    } else {
        return bytesLeft;
    }
}

void WiFiUDP::stop()
{
    sl_Close(_socketHandle);
    WiFiClass::_server_port[_sock] = 0;
    _sock = NO_SOCKET_AVAIL;
}

int WiFiUDP::beginPacket(const char *host, uint16_t port)
{
}

int WiFiUDP::beginPacket(IPAddress ip, uint16_t port)
{
}

int WiFiUDP::endPacket()
{
}

size_t WiFiUDP::write(uint8_t byte)
{
}

size_t WiFiUDP::write(const uint8_t *buffer, size_t size)
{
}

//
//bit of a misnomer. This waits to receive a packet and then stores it in a buffer
//it is important that this is called before any of the read or available commands
//are called. This does the actual work. Read, peek, etc. are just organizational.
//
int WiFiUDP::parsePacket()
{
    //
    //make sure we actually have a socket
    //
    if (_socketHandle == NO_SOCKET_AVAIL) {
        return 0;
    }
    
    //
    //the sl_select command blocks until something interesting happens or
    //it times out (current timeout set for 2 seconds)
    //
    SlTimeval_t timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;
    
    SlFdSet_t readSocketHandles, errorSocketHandles;
    SL_FD_ZERO(&readSocketHandles);
    SL_FD_ZERO(&errorSocketHandles);
    SL_FD_SET(_socketHandle, &readSocketHandles);
    SL_FD_SET(_socketHandle, &errorSocketHandles);
    
    int iRet = sl_Select(_socketHandle+1, &readSocketHandles, NULL, &errorSocketHandles, &timeout);
    if (iRet <= 0) {
        return 0;
    }

    //
    //Since we've reached this point, the sl_select command has indicated
    //that either we're going to get an error, or an immediate read
    //
    SlSockAddrIn_t  address;
    int AddrSize = sizeof(address);
    int bytes = sl_RecvFrom(_socketHandle, rx_buf, UDP_RX_PACKET_MAX_SIZE, NULL, (SlSockAddr_t*)&address, (SlSocklen_t*)&AddrSize);

    //
    //If an error occured, return 0, otherwise return the byte length of the packet
    //and reset the buffer index counter and fill level variables
    //
    if (bytes < 0) {
        rx_fillLevel = 0;
        return 0;
    } else {
        rx_currentIndex = 0;
        rx_fillLevel = bytes;
        return bytes;
    }
}

int WiFiUDP::read()
{
    //
    //don't read past the available data in the buffer
    //
    if (rx_currentIndex >= rx_fillLevel) {
        return 0;
    }
    
    //
    //return the byte at the current index and increment that index
    //
    return rx_buf[rx_currentIndex++];
}

int WiFiUDP::read(unsigned char* buffer, size_t len)
{
    //
    //copy the requested number of bytes up to the length of the packet
    //
    int bytesCopied = 0;
    while ((bytesCopied <= len) && (rx_currentIndex < rx_fillLevel)) {
        buffer[bytesCopied] = rx_buf[rx_currentIndex];
        bytesCopied++;
        rx_currentIndex++;
    }
    
    return bytesCopied;
}

int WiFiUDP::peek()
{
    return rx_buf[rx_currentIndex];
}

void WiFiUDP::flush()
{
    //
    //destroy the remaining data in the buffer and reset index and length variables
    //
    memset(rx_buf, 0, UDP_RX_PACKET_MAX_SIZE);
    rx_currentIndex = 0;
    rx_fillLevel = 0;
}

IPAddress  WiFiUDP::remoteIP()
{
}

uint16_t  WiFiUDP::remotePort()
{
}

