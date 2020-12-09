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

#ifndef COAPRRLAYER_H_
#define COAPRRLAYER_H_

#include "CoapMessageLayer.h"
#include "CoapMsg.h"

/**
 * CoapRRLayer (Request/Response layer) is a middle layer of the CoAP stack.  It is responsible for
 * sending requests and receiving responses to those requests.  Note that it does not handle
 * ACKs or RESETs.  Those are handled at the CoapMessageLayer.
 *
 * This class is intended to implement the CoAP Client Request/Response Layer FSM as described
 * by Kovatsch et al. in https://tools.ietf.org/html/draft-kovatsch-lwig-coap-01
 *
 * Note that this design only implements the client functionality as our application does not
 * serve anything.
 */

class CoapRRLayer {
    
    public:
        enum Result {
            NO_ERROR = 0,
            RESPONSE_RECEIVED,
            ACK_RECEIVED,
            CON_RECEIVED,
            ERROR_IMPROPER_STATE,
            ERROR_SENDING_MSG,
            ERROR_RECEIVING_RESPONSE,
            RST_RECEIVED
        };
        
        enum State {
            STATE_IDLE,
            STATE_WAITING
        };
        
        CoapRRLayer(CoapMessageLayer& messageLayer, uint8_t* rxBuffer, uint16_t rxBufferLen);
        
        Result reliableSend(CoapMsg& msg, char* token, IPAddress addr, uint16_t port);
        Result send(CoapMsg& msg, char* token, IPAddress addr, uint16_t port);
        Result loop();
        Result getLastResult() {return m_lastResult;}
        void setState(State state) {m_state = state;}
        int16_t getRxByteCount() {return m_rxByteCount;}
        
    protected:
        
        CoapMessageLayer& m_messageLayer;
        State m_state;
        Result m_lastResult;
        char* m_token;
        uint8_t* m_rxBuffer;
        int16_t m_rxByteCount;
        uint16_t m_rxBufferLen;
        
        bool rxTokenMatches(CoapMsg& msg);
};

#endif
