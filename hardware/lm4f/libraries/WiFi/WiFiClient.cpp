/* TO DO:
 *   1) Add a way to check if the connection has been dropped by the server
 * X 2) Make this an extension of the print class in print.cpp
 *   3) Figure out what status is supposed to do
 *   4) Prevent the wrong methods from being called based on server or client side
 *
 */

/*
 WiFiClient.cpp - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 Author: Noah Luskey | LuskeyNoah@gmail.com
 
 WiFiClient objects suffer from a bit of an existential crisis, where really
 the same class serves two separate purposes. Client instances can exist server
 side (as a wrapper for a port to send messages to), or client side, as the 
 object attempting to make a connection. Only certain calls should be made in 
 each instance, and effort has been made to prevent the user from being able
 to mess things up with the wrong function calls.
 
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
  #include "utility/socket.h"
}

#include "WiFi.h"
#include "WiFiClient.h"
#include "WiFiServer.h"

//--tested, working--//
//--client side--//
WiFiClient::WiFiClient()
{
    //
    //initialize to empty buffer and no socket assigned yet
    //
    rx_currentIndex = 0;
    rx_fillLevel = 0;
    _socketIndex = NO_SOCKET_AVAIL;
    hasRootCA = false;
    sslVerifyStrict = false;
    sslLastError = 0;
}

//--tested, working--//
//--server side--//
WiFiClient::WiFiClient(uint8_t socketIndex)
{
    //
    //this is called by the server class. Initialize with the assigned socket index
    //
    rx_currentIndex = 0;
    rx_fillLevel = 0;
    _socketIndex = socketIndex;
}


WiFiClient::~WiFiClient()
{
    //
    //don't do anything if the socket was never set up
    //
    if (_socketIndex == NO_SOCKET_AVAIL) {
        return;
    }

    //
    //Abuse the deconstructor to copy the state of a client going
    //out of scope in the loop. This is an ugly hack but there is no
    //other way to keep track of state of a client.
    //
    memcpy(&WiFiClass::clients[_socketIndex], this, sizeof(WiFiClient));
}

//--tested, working--//
//--client side--//
int WiFiClient::connect(const char* host, uint16_t port)
{
    //
    //get the host ip address
    //
    IPAddress hostIP(0,0,0,0);
    int success = WiFi.hostByName((char*)host, hostIP);
    if (!success) {
        return false;
    }
    
    return connect(hostIP, port);
}

//--tested, working--//
//--client side--//
int WiFiClient::connect(IPAddress ip, uint16_t port)
{
    //
    //this function should only be called once and only on the client side
    //
    if (_socketIndex != NO_SOCKET_AVAIL) {
        return false;
    }
    
    
    //
    //get a socket index and attempt to create a socket
    //note that the socket is intentionally left as BLOCKING. This allows an
    //abusive user to send as many requests as they want as fast as they can try
    //and it won't overload simplelink.
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
    server.sin_addr.s_addr = ip;
    int iRet = sl_Connect(socketHandle, (SlSockAddr_t*)&server, sizeof(SlSockAddrIn_t));

    if (iRet < 0) {
        sl_Close(socketHandle);
        return false;
    }

    int enableOption = 1;
    sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_NONBLOCKING, &enableOption, sizeof(enableOption));
    sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_KEEPALIVE, &enableOption, sizeof(enableOption));

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

int WiFiClient::sslConnect(const char* host, uint16_t port)
{
    //
    //get the host ip address
    //
    IPAddress hostIP(0,0,0,0);
    int success = WiFi.hostByName((char*)host, hostIP);
    if (!success) {
        return false;
    }
    
    return sslConnect(hostIP, port);
}

#define ROOTCA_PEM_FILE "/cert/rootCA.pem"

int WiFiClient::sslConnect(IPAddress ip, uint16_t port)
{
    //
    //this function should only be called once and only on the client side
    //
    if (_socketIndex != NO_SOCKET_AVAIL) {
        return false;
    }
    
    
    //
    //get a socket index and attempt to create a socket
    //note that the socket is intentionally left as BLOCKING. This allows an
    //abusive user to send as many requests as they want as fast as they can try
    //and it won't overload simplelink.
    //
    int socketIndex = WiFiClass::getSocket();
    if (socketIndex == NO_SOCKET_AVAIL) {
        return false;
    }


    int socketHandle = sl_Socket(SL_AF_INET, SL_SOCK_STREAM, SL_SEC_SOCKET);
    if (socketHandle < 0) {
        return false;
    }

    // Utilize rootCA file for verifying server certificate if it's been supplied with .sslRootCA() previously
    if (hasRootCA) {
        sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_SECURE_FILES_CA_FILE_NAME, ROOTCA_PEM_FILE, strlen(ROOTCA_PEM_FILE));
    }
    sslIsVerified = true;

    //
    //connect the socket to the requested IP address and port. Check for success
    //

    SlSockAddrIn_t server = {0};
    server.sin_family = SL_AF_INET;
    server.sin_port = sl_Htons(port);
    server.sin_addr.s_addr = ip;
    int iRet = sl_Connect(socketHandle, (SlSockAddr_t*)&server, sizeof(SlSockAddrIn_t));

    if ( iRet < 0 && (iRet != SL_ESECSNOVERIFY && iRet != SL_ESECDATEERROR) ) {
        sslLastError = iRet;
        sl_Close(socketHandle);
        return false;
    }

    // If the remote-end server cert could not be verified, and we demand strict verification, ABORT.
    if ( sslVerifyStrict && (iRet == SL_ESECSNOVERIFY || iRet == SL_ESECDATEERROR) ) {
        sslLastError = iRet;
        sl_Close(socketHandle);
        return false;
    }

    if (iRet == SL_ESECSNOVERIFY || iRet == SL_ESECDATEERROR) {
        sslLastError = iRet;
        sslIsVerified = false;
    }

    int enableOption = 1;
    sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_NONBLOCKING, &enableOption, sizeof(enableOption));
    sl_SetSockOpt(socketHandle, SL_SOL_SOCKET, SL_SO_KEEPALIVE, &enableOption, sizeof(enableOption));

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

/*  SSL root CA verification is a work in progress
int32_t WiFiClient::sslGetReasonID(void)
{
    return sslLastError;
}

const char * WiFiClient::sslGetReason(void)
{
    switch (sslLastError) {
        case SL_SOC_OK:
            return "OK";
        case SL_ESECSNOVERIFY:
            return "SL_ESECSNOVERIFY - SSL verification not enabled";
        case SL_ESECDATEERROR:
            return "SL_ESECDATEERROR - Connected, but RootCA date error";
        case SL_ESEC_ASN_SIG_CONFIRM_E:
            return "SL_ESEC_ASN_SIG_CONFIRM_E - RootCA could not verify site cert";
        case SL_ESECBADCAFILE:
            return "SL_ESECBADCAFILE - Bad RootCA file (needs DER binary format, not PEM)";
    }
    return "UNKNOWN";
}

void WiFiClient::sslStrict(boolean yesno)
{
    sslVerifyStrict = yesno;
}

int WiFiClient::sslRootCA(const uint8_t *rootCAfilecontents, const size_t filelen)
{
    int32_t i, fh;
    uint32_t tok;
    size_t maxsize;

    sl_FsDel((uint8_t*)ROOTCA_PEM_FILE, 0);

    if (rootCAfilecontents == NULL || filelen == 0) {
	hasRootCA = false;
        return true;
    }

    maxsize = (filelen / 512) * 512 + (filelen % 512);
    i = sl_FsOpen((uint8_t*)ROOTCA_PEM_FILE, FS_MODE_OPEN_CREATE(maxsize, _FS_FILE_OPEN_FLAG_COMMIT | _FS_FILE_OPEN_FLAG_NO_SIGNATURE_TEST), &tok, &fh);
    if (i != SL_FS_OK) {
        return false;
    }

    i = sl_FsWrite(fh, 0, (uint8_t *)rootCAfilecontents, filelen);
    sl_FsClose(fh, NULL, NULL, 0);

    if (i != filelen)
        return false;

    hasRootCA = true;
    return true;
}

// Checks if an existing copy of /cert/rootCA.pem is on the Serial Flash; if so, use it!
int WiFiClient::useRootCA(void)
{
    int32_t i;
    SlFsFileInfo_t fi;

    i = sl_FsGetInfo((uint8_t*)ROOTCA_PEM_FILE, 0, &fi);
    if (i != SL_FS_OK)
        return false;

    hasRootCA = true;
    return true;
}
 */

//--tested, working--//
//--client and server side--//
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

//--tested, working--//
//--client and server side--//
size_t WiFiClient::write(const uint8_t *buffer, size_t size)
{
    //
    //don't do anything if not properly set up
    //
    if (_socketIndex == NO_SOCKET_AVAIL) {
        return 0;
    }

    //
    //write the buffer to the socket
    //
    int iRet = sl_Send(WiFiClass::_handleArray[_socketIndex], buffer, size, NULL);

    // Flow control signal; perform a paced-retry.
    while (iRet == SL_EAGAIN) {
        delay(10);
        iRet = sl_Send(WiFiClass::_handleArray[_socketIndex], buffer, size, NULL);
    }

    if ((iRet < 0) || (iRet != size)) {
        //
        //if an error occured or the socket has died, call stop()
        //to make the object aware that it's dead
        //
        stop();
        return 0;
    } else {
        return iRet;
    }
}

//--tested, working--//
//--client and server side--//
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
        SlTimeval_t timeout;
        memset(&timeout, 0, sizeof(SlTimeval_t));
        timeout.tv_sec = 0;
        timeout.tv_usec = 500;
        SlFdSet_t readsds, errorsds;
        SL_FD_ZERO(&readsds);
        SL_FD_ZERO(&errorsds);
        SL_FD_SET(WiFiClass::_handleArray[_socketIndex], &readsds);
        SL_FD_SET(WiFiClass::_handleArray[_socketIndex], &errorsds);

//        sl_Select(WiFiClass::_handleArray[_socketIndex] + 1, &readsds, NULL, &errorsds, &timeout);
//        if(!SL_FD_ISSET(WiFiClass::_handleArray[_socketIndex], &readsds)) return 0;

        //
        //Receive any pending information into the buffer
        //if the connection has died, call stop() to make the object aware it's dead
        //
        int iRet = sl_Recv(WiFiClass::_handleArray[_socketIndex], rx_buffer, TCP_RX_BUFF_MAX_SIZE, NULL);
        if ((iRet <= 0)  &&  (iRet != SL_EAGAIN)) {
            stop();
            memset(rx_buffer, 0, TCP_RX_BUFF_MAX_SIZE);
            return 0;
        }
        
        //
        //receive successful. Reset rx index pointer and set buffer fill level indicator
        //(if SL_EAGAIN was received, the actual number of bytes received was zero, not -11)
        //
        rx_currentIndex = 0;
        rx_fillLevel = (iRet != SL_EAGAIN) ? iRet : 0;
        bytesLeft = rx_fillLevel - rx_currentIndex;

        
    }
    
    //
    //limit bytes left to >= 0
    //
    if (bytesLeft < 0) {
        bytesLeft = 0;
    }
    return bytesLeft;
}

//--tested, working--//
int WiFiClient::read()
{
    //
    //available says how many bytes are left to read. It will receive more
    //if there are no more bytes left in the buffer. Returns 0 if nothing more
    //
    if ( available() ) {
        return rx_buffer[rx_currentIndex++];
    } else {
        return -1;
    }
}

//--tested, working--//
int WiFiClient::read(uint8_t* buf, size_t size)
{
    //
    // read up to the requested number of bytes into the buffer
    // uses direct buffer copies to speed things up
    if (!available()) {
        return 0;
    }

    int len = rx_fillLevel - rx_currentIndex;
    if (len > size) {
        len = size;
    }
    memcpy(buf, &rx_buffer[rx_currentIndex], len);
    rx_currentIndex += len;

    return len;
}

//--tested, working--//
int WiFiClient::peek()
{
    //
    //return the next byte in the buffer or zero if we're past the end of the data
    //
    if (rx_currentIndex < rx_fillLevel) {
        return rx_buffer[rx_currentIndex];
    } else {
        return -1;
    }
}

//--tested, working--//
void WiFiClient::flush()
{
    //
    //clear out the buffer and reset all the buffer indicators
    //
    memset(rx_buffer, 0, TCP_RX_BUFF_MAX_SIZE);
    rx_fillLevel = 0;
    rx_currentIndex = 0;
}

//--tested, working--//
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

//!! works, sort of, dependent on status(), which needs work !!//
uint8_t WiFiClient::connected()
{
    //
    //as described by the arduino api, this will return true even if the client has
    //disconnected as long as there is data left in the buffer
    //
    if ( status() ) {
        return true;
    } else if (rx_currentIndex < rx_fillLevel) {
        return true;
    } else {
        return false;
    }
    
}

//!! works, sort of, needs to actually test connection !!//
uint8_t WiFiClient::status()
{
    available();
    if(_socketIndex == NO_SOCKET_AVAIL) return false;

    return true;
}

//--tested, working--//
WiFiClient::operator bool()
{
    //
    //a "fake" client instance with index==255 should evaluate to false
    //
    return _socketIndex != 255;
}




