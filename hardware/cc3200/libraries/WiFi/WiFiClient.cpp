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
  #include "utility/Socket.h"
}

#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"


WiFiClient::WiFiClient()
{
    //
    //initialize to empty buffer and no socket assigned yet
    //
    rx_currentIndex = 0;
    rx_fillLevel = 0;
    _socketIndex = NO_SOCKET_AVAIL;
    
}

WiFiClient::WiFiClient(uint8_t socketIndex)
{
    //
    //this is called by the server class. Initialize with the assigned socket index
    //
    rx_currentIndex = 0;
    rx_fillLevel = 0;
    _socketIndex = socketIndex;
}


int WiFiClient::connect(char* host, uint16_t port)
{
    //
    //get the host ip address
    //
    IPAddress hostIP(0,0,0,0);
    int success = WiFi.hostByName(host, hostIP);
    if (!success) {
        return false;
    }
    
    return connect(hostIP, port);
    
}

int WiFiClient::connect(IPAddress ip, uint16_t port)
{
    //
    //get a socket index and attempt to create a socket
    //
    int socketIndex = WiFiClass::getSocket();
    if (socketIndex == NO_SOCKET_AVAIL) {
        return false;
    }
    int socketHandle = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, SL_IPPROTO_TCP);
    if (socketHandle < 0) {
        return false;
    }
    
    //
    //connect the socket to the requested IP address and port. Check for success
    //
    SlSockAddrIn_t server = {0};
    server.sin_family = SL_AF_INET;
    server.sin_port = sl_Htons(port);
    server.sin_addr.s_addr = sl_Htonl(ip);
    int iRet = sl_Connect(socketHandle, (SlSockAddr_t*)&server, sizeof(server));
    if (iRet < 0) {
        sl_Close(socketHandle);
        return false;
    }
    
    //
    //set socket operation to be non blocking
    //
    long NonBlocking = true;
    iRet = sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_NONBLOCKING, &NonBlocking, sizeof(NonBlocking));
    if (iRet < 0) {
        sl_Close(socketHandle);
        return false;
    }
    
    //
    //we've successfully created a socket and connected, so store the
    //information in the arrays provided by WiFiClass
    //
    _socketIndex = socketIndex;
    WiFiClass::_handleArray[socketIndex] = socketHandle;
    WiFiClass::_typeArray[socketIndex] = TYPE_TCP_CLIENT;
    WiFiClass::_portArray[socketIndex] = port;
    return true;
}

size_t WiFiClient::write(uint8_t b)
{
    //
    //don't do anything if not properly set up
    //
    if (_socketIndex == NO_SOCKET_AVAIL) {
        return 0;
    }
    
    //
    //write the single byte to the server the client is connected to
    //
    return write(&b, 1);
}

size_t WiFiClient::write(uint8_t *buf, size_t size)
{
    //
    //don't do anything if not properly set up
    //
    if (_socketIndex == NO_SOCKET_AVAIL) {
        return 0;
    }
    
    //
    //write the bufer to the socket
    //
    int iRet = sl_Send(WiFiClass::_handleArray[_socketIndex], buf, size, NULL);
    if (iRet < 0) {
        return 0;
    } else {
        return iRet;
    }
}

int WiFiClient::available()
{
    //
    //don't do anything if not properly set up
    //
    if (_socketIndex == NO_SOCKET_AVAIL) {
        return 0;
    }
    
    //
    //if the buffer doesn't have any data in it or we've read everything
    //then receive some data
    //
    int bytesLeft = rx_fillLevel - rx_currentIndex;
    if (bytesLeft <= 0) {
        //
        //Receive any pending information into the buffer
        //clear the rx_buffer if an error occured (SL_EAGAIN just means no new info)
        //
        int iRet = sl_Recv(WiFiClass::_handleArray[_socketIndex], rx_buffer, TCP_RX_BUFF_MAX_SIZE, NULL);
        if ((iRet < 0)  &&  (iRet != SL_EAGAIN)) {
            memset(rx_buffer, 0, TCP_RX_BUFF_MAX_SIZE);
            return 0;
        }
        
        //
        //receive successful. Reset rx index pointer and set buffer fill level indicator
        //
        rx_currentIndex = 0;
        rx_fillLevel = iRet;
        bytesLeft = rx_currentIndex - rx_fillLevel;
    }
    
    //
    //limit bytes left to >= 0 (although it *shouldn't* ever become negative)
    //
    if (bytesLeft < 0) {
        bytesLeft = 0;
    }
    return bytesLeft;
}

uint8_t WiFiClient::read()
{
    //
    //return a single byte from the rx buffer (or zero if past the end)
    //
    if (rx_currentIndex < rx_fillLevel) {
        return rx_buffer[rx_currentIndex++];
    } else {
        return 0;
    }
}

int WiFiClient::read(uint8_t* buf, size_t size)
{
    //
    //read the requested number of bytes into the buffer
    //this won't read past the end of the data since read() handles that
    //
    int i;
    for (i = 0; i < size; i++) {
        buf[i++] = read();
    }
    return i;
}

uint8_t WiFiClient::peek()
{
    //
    //return the next byte in the buffer or zero if we're past the end of the data
    //
    if (rx_currentIndex < rx_fillLevel) {
        return rx_buffer[rx_currentIndex+1];
    } else {
        return 0;
    }
}

void WiFiClient::flush()
{
    //
    //clear out the buffer and reset all the buffer indicators
    //
    memset(rx_buffer, 0, TCP_RX_BUFF_MAX_SIZE);
    rx_fillLevel = 0;
    rx_currentIndex = 0;
}

void WiFiClient::stop()
{
    //
    //don't do anything if not properly set up
    //
    if (_socketIndex == NO_SOCKET_AVAIL) {
        return;
    }
    
    //
    //disconnect, destroy the socket, and reset the socket tracking variables
    //in WiFiClass, but don't destroy any of the received data
    //
    int iRet = sl_Close(WiFiClass::_handleArray[_socketIndex]);
    if (iRet < 0) {
        return;
    }
    
    //
    //since no error occurred while closing the socket, reset WiFiClass variables
    //
    WiFiClass::_portArray[_socketIndex] = -1;
    WiFiClass::_handleArray[_socketIndex] = -1;
    WiFiClass::_typeArray[_socketIndex] = -1;
    _socketIndex = NO_SOCKET_AVAIL;
    
}

bool WiFiClient::connected()
{
    //
    //as described by the arduino api, this will return true even if the client has
    //disconnected as long as there is data left in the buffer
    //
    if (_socketIndex != NO_SOCKET_AVAIL) {
        return true;
    } else if (rx_currentIndex < rx_fillLevel) {
        return true;
    } else {
        return false;
    }
    
}

uint8_t WiFiClient::status()
{
    //
    //!! not described in arduino online api
    //
    return 0;
}

WiFiClient::operator bool()
{
    //
    //a "fake" client instance with index==255 should evaluate to false
    //
    return _socketIndex != 255;
}


