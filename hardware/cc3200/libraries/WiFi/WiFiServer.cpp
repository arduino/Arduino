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
    #include "SimpleLink/simplelink.h"
    #include "SimpleLink/socket.h"
    #include "utility/wl_definitions.h"
    #include "SimpleLink/netapp.h"
}

#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"

WiFiServer::WiFiServer(uint16_t port)
{
    _socketIndex = NO_SOCKET_AVAIL;
    _port = port;
}

//--tested, working--//
void WiFiServer::begin()
{
    //
    //Stop the port 80 internal http server if running a server on port 80
    //
    if (_port == 80) {
        sl_NetAppStop(SL_NET_APP_HTTP_SERVER_ID);
    }
    
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
    int socketHandle = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, SL_IPPROTO_TCP);
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
    int iRet = sl_Bind(socketHandle, (SlSockAddr_t*)&portAddress, sizeof(SlSockAddrIn_t));
    if (iRet < 0) {
        sl_Close(socketHandle);
        return;
    }
    
    //
    //Make the socket start listening for incoming tcp connections
    //(backlog of length 0)
    //
    iRet = sl_Listen(socketHandle, 0);
    if (iRet < 0) {
        sl_Close(socketHandle);
        return;
    }
    
    //
    //set socket operation to be non blocking
    //
    long NonBlocking = true;
    iRet = sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_NONBLOCKING, &NonBlocking, sizeof(NonBlocking));
    if (iRet < 0) {
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

//--tested, working--//
WiFiClient WiFiServer::available(byte* status)
{
    //
    //Get a socket number from the wificlass
    //
    int clientSocketIndex = WiFiClass::getSocket();
    if (clientSocketIndex == NO_SOCKET_AVAIL) {
        return WiFiClient(255);
    }
    
    //
    //create the client address structure to be filled in by sl_accept
    //
    SlSockAddrIn_t clientAddress = {0};
    unsigned int clientAddressSize = sizeof(clientAddress);
    
    //
    //get the client handle, if there's a queued client. If no client, return 0
    //
    int socketHandle = WiFiClass::_handleArray[_socketIndex];
    int clientHandle = sl_Accept(socketHandle, (SlSockAddr_t*)&clientAddress, &clientAddressSize);
    
    //
    //if there is no new client (or an error), return a "fake" client that
    //evaluates to false if placed in a boolean comparison (arduino compatability)
    //
    if ((clientHandle == SL_EAGAIN) || (clientHandle < 0)) {
        return WiFiClient(255);
    }
    
    //
    //We've successfully created a socket, so store everything in the wificlass
    //arrays used to keep track of the connected sockets, port #s, and types
    //
    WiFiClient client(clientSocketIndex);
    WiFiClass::_handleArray[clientSocketIndex] = clientHandle;
    WiFiClass::_typeArray[clientSocketIndex] = TYPE_TCP_CONNECTED_CLIENT;
    WiFiClass::_portArray[clientSocketIndex] = sl_Htons(clientAddress.sin_port);
    return client;
}

uint8_t WiFiServer::status()
{
    //
    //!! functionality not described in arduino online api
    //
    return 0;
}


size_t WiFiServer::write(uint8_t b)
{
    //
    //send the single byte
    //
    return write(&b, 1);
    
}

//!! With this implementation, only 1 server can run on each cc3200 !!//
size_t WiFiServer::write(const uint8_t *buffer, size_t size)
{
    //
    //iterate through the sockets and write the data to any connected clients
    //the arduino API dictates to write the data to ALL clients
    //
    int i;
    int sentBytes = 0;
    for (i = 0; i < MAX_SOCK_NUM; i++) {
        if (WiFiClass::_typeArray[i] == TYPE_TCP_CONNECTED_CLIENT) {
            //
            //Write the data to the connected client and return if error
            //
            int handle = WiFiClass::_handleArray[i];
            sentBytes = sl_Send(handle, buffer, size, NULL);
            if (sentBytes < 0) {
                return 0;
            }
        }
    }
    return sentBytes;
}
