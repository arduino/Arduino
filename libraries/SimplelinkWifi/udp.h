// // /*****************************************************************************
// // *
// // *  server.h - CC3000 Sensor Application Server functionality definitions
// // *  Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
// // *
// // *  Redistribution and use in source and binary forms, with or without
// // *  modification, are permitted provided that the following conditions
// // *  are met:
// // *
// // *    Redistributions of source code must retain the above copyright
// // *    notice, this list of conditions and the following disclaimer.
// // *
// // *    Redistributions in binary form must reproduce the above copyright
// // *    notice, this list of conditions and the following disclaimer in the
// // *    documentation and/or other materials provided with the   
// // *    distribution.
// // *
// // *    Neither the name of Texas Instruments Incorporated nor the names of
// // *    its contributors may be used to endorse or promote products derived
// // *    from this software without specific prior written permission.
// // *
// // *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// // *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// // *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// // *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// // *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// // *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// // *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// // *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// // *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// // *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// // *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// // *
// // *****************************************************************************/

// // #ifndef UDP_H
// // #define UDP_H

// // #include "SimplelinkWifi.h"
// // #define SERVER_RECV_BUF_SIZE 8
// // // SERVER ERROR
// // enum serverError
// // {
    // // SERV_ERR_SOCKET = 1,
    // // SERV_ERR_BIND = 2,
    // // SERV_ERR_LISTEN = 3    
// // };

// // int initServer(void);

// // void shutdownServer();
// // void serverError(char err);
// // void clientUDPconnection(void);
// // #endif


// #ifndef UDP_H
// #define UDP_H

// // #include <Stream.h>
// // #include <IPAddress.h>

// #define UDP_TX_PACKET_MAX_SIZE 24

// class WiFiUDP {
// private:
  // uint8_t _sock;  // socket ID for Wiz5100
  // uint16_t _port; // local port to listen on
  // void init();	

// public:
  // WiFiUDP();  // Constructor
  // virtual uint8_t begin(uint16_t);	// initialize, start listening on specified port. Returns 1 if successful, 0 if there are no sockets available to use
 
// };

// #endif
