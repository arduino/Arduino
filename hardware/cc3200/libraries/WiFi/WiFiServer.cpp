/*
 WiFiServer.cpp - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
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

#include <string.h>

extern "C" {
    #include "utility/simplelink.h"
    #include "utility/socket.h"
    #include "utility/wl_definitions.h"
    #include "utility/socket.h"
}

#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"

WiFiServer::WiFiServer(uint16_t port) : _socketIndex(NO_SOCKET_AVAIL)
{
    _port = port;
    _socketIndex = NO_SOCKET_AVAIL;
}

void WiFiServer::begin()
{
    //
    //get a socket from the WiFiClass (convoluted method from the arduino library)
    //
    int socketIndex = WiFiClass::getSocket();
    if (socketIndex == NO_SOCKET_AVAIL) {
        return;
    }
    
    
    //
    //get a socket handle from the simplelink api and make sure it's valid
    //
    int socketHandle = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, IPPROTO_TCP);
    if (socketHandle < 0) {
        return;
    }
    
    //
    //bind the socket to the requested port and check for success
    //if failure, gracefully close the socket and return failure
    //
    SlSockAddrIn_t portAddress;
    portAddress.sin_family = SL_AF_INET;
    portAddress.sin_port = sl_Htons(_port);
    portAddress.sin_addr.s_addr = 0;
    int iRet = sl_Bind(socketHandle, (SlSockAddr_t*)&portAddress, sizeof(portAddress));
    if (iRet < 0) {
        sl_Close(socketHandle);
        return;
    }
    
    //
    //Make the socket start listening for incoming tcp connections
    //(backlog of length 1)
    //
    int success = sl_Listen(socketHandle, 1);
    if (!success) {
        sl_Close(socketHandle);
        return;
    }
    
    //
    //set socket operation to be non blocking
    //
    long NonBlocking = true;
    success = sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_NONBLOCKING, &NonBlocking, sizeof(NonBlocking));
    if (!success) {
        sl_Close(socketHandle);
        return;
    }
    
    //
    //Simplelink api calls are done, so set the object's variables
    //
    _socketIndex = socketIndex;
    WiFiClass::_handleArray[socketIndex] = socketHandle;
    WiFiClass::_portArray[socketIndex] = _port;
    WiFiClass::_typeArray[socketIndex] = TYPE_TCP_SERVER;
}

WiFiClient WiFiServer::available(byte* status)
{
    //
    //Get a socket number from the wificlass
    //
    int sock = WiFiClass::getSocket();
    if (sock == NO_SOCKET_AVAIL) {
        return NULL;
    }
    
    //
    //create the client address structure to be filled in by sl_accept
    //
    SlSockAddrIn_t clientAddress;
    unsigned int clientAddressSize = sizeof(clientAddress);
    
    //
    //get the client handle, if there's a queued client. If no client, return 0
    //
    int socketHandle = WiFiClass::_handleArray[_socketIndex];
    int clientHandle = sl_Accept(socketHandle, (SlSockAddr_t*)&clientAddress, &clientAddressSize);
    
    //
    //if there is no new client (or an error), return a "fake" client that evaluates
    //to false if placed in a boolean comparison (arduino compatability)
    //
    if (clientHandle < 0) {
        WiFiClient client(255);
        return client;
    }
    
    //
    //create a client from the successful client connection handle and return
    //
    WiFiClient client(clientHandle);
    return client;
}

uint8_t WiFiServer::status()
{
    //
    //functionality not described in arduino online api
    //
    return 0;
}


size_t WiFiServer::write(uint8_t b)
{
}

size_t WiFiServer::write(const uint8_t *buffer, size_t size)
{
}
