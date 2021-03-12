/*
 ###############################################################################
 #
 # Temboo CoAP Edge Device library
 #
 # Copyright (C) 2017, Temboo Inc.
 #
 # Licensed under the Apache License, Version 2.0 (the "License");
 # you may not use this file except in compliance with the License.
 # You may obtain a copy of the License at
 #
 # http://www.apache.org/licenses/LICENSE-2.0
 #
 # Unless required by applicable law or agreed to in writing,
 # software distributed under the License is distributed on an
 # "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 # either express or implied. See the License for the specific
 # language governing permissions and limitations under the License.
 #
 ###############################################################################
 */

#ifndef TEMBOOCOAPIPSTACK_H_
#define TEMBOOCOAPIPSTACK_H_

#include <string.h>
#include <Udp.h>
#include "TembooGlobal.h"

class TembooCoAPIPStack
{
public:
    enum Error {
        SUCCESS = 0,
        ERROR_RESOLVING,
        ERROR_WRITING,
        ERROR_SENDING,
        ERROR_RECEIVING
        
    };
    
    
    TembooCoAPIPStack(UDP& udp) : m_udp(udp) {}
    
    
    int sendDatagram(IPAddress address, uint16_t port, uint8_t* data, size_t len) {
        if (0 == m_udp.beginPacket(address, port)) {
            TEMBOO_TRACE("ERROR: ");
            TEMBOO_TRACELN("UDP begin");
            return ERROR_RESOLVING;
        }
        
        uint16_t c = m_udp.write(data, len);
        if (len != c) {
            TEMBOO_TRACE("ERROR: ");
            TEMBOO_TRACELN("UDP write");
            Serial.println(len);
            Serial.println(c);
            Serial.println((char*)data);
            
            return ERROR_WRITING;
        }
        
        if (0 == m_udp.endPacket()) {
            TEMBOO_TRACE("ERROR: ");
            TEMBOO_TRACELN("UDP send");
            return ERROR_SENDING;
        }
        
        return SUCCESS;
    }
    
    int recvDatagram(uint8_t* buffer, size_t maxLen, int32_t& count) {
        memset(buffer, 0, maxLen);
        count = 0;
        if (m_udp.parsePacket() > 0) {
            count = m_udp.read(buffer, maxLen);
            if (count < 0) {
                TEMBOO_TRACE("ERROR: ");
                TEMBOO_TRACELN("UDP read");
                return ERROR_RECEIVING;
            }
        }
        return SUCCESS;
    }
    
    IPAddress getRemoteAddress() {
        return m_udp.remoteIP();
    }
    
    uint16_t getRemotePort() {
        return m_udp.remotePort();
    }
    
    
protected:
    UDP& m_udp;
};

#endif

