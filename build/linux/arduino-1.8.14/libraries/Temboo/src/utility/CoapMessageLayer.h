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

#ifndef COAPMESSAGELAYER_H_
#define COAPMESSAGELAYER_H_

#include "TembooCoAPIPStack.h"
#include "TembooTimer.h"
#include "CoapMsg.h"

/**
 * CoapMessageLayer is the lowest layer of the CoAP stack.  It is responsible for
 * transmitting and receiving messages.  Specifically, this implementation is
 * responsible for handling confirmable (CON) messages and their ACKs.
 * It is intended to implement the Message Layer FSM described by Kovatsch et al. in
 * https://tools.ietf.org/html/draft-kovatsch-lwig-coap-01
 *
 * It can send reliable (confirmable or CON) messages and will maintain the necessary
 * state information to wait for an acknowledgement.  It will handle any necessary
 * retransmissions and timeouts until a CON message has been ACK'd (or rejected.)
 *
 * It can not send unreliable (non-confirmable or NON) messages as currently designed
 * because our application does not use NON messages.
 *
 * It can receive CON and NON messages and will send ACKs or RESETs as required.
 *
 * Any non-rejected CON or NON messages received are passed up to the Request/Response
 * layer (CoapRRLayer) for processing.
 *
 * Be sure to note the difference between ACK's and Responses.  This layer handles
 * ACK's, it does not handle Responses. (Responses are handled by the CoapRRLayer class.)
 */


class CoapMessageLayer {
    public:
        
        enum State {
            STATE_CLOSED,
            STATE_RELIABLE_TX,
            STATE_ACK_PENDING,
            STATE_WAITING_FOR_CON
        };
        
        enum Result {
            NO_ERROR = 0,
            CON_RECEIVED,
            NON_RECEIVED,
            ACK_RECEIVED,
            RESET_RECEIVED,
            ERROR_IMPROPER_STATE,
            ERROR_NULL_MESSAGE,
            ERROR_SENDING_PACKET,
            ERROR_RECEIVING_PACKET,
            ERROR_RETRANSMIT_COUNT_EXCEEDED,
            ERROR_TX_SPAN_TIME_EXCEEDED
        };
        
        static const uint32_t ACK_TIMEOUT = 2000;
        
        // MAX_ACK_TIMEOUT = ACK_TIMEOUT * ACK_RANDOM_FACTOR
        // RFC7252 suggests ACK_RANDOM_FACTOR = 1.5
        static const uint32_t MAX_ACK_TIMEOUT = 3000;
        static const uint8_t  MAX_RETRANSMIT = 4;
        
        // MAX_TRANSMIT_SPAN = ACK_TIMEOUT * ((2^MAX_RETRANSMIT) - 1) * ACK_RANDOM_FACTOR
        static const uint32_t MAX_TRANSMIT_SPAN = 45000;
        
        // MAX_TRANSMIT_WAIT = ACK_TIMEOUT * (2^(MAX_RETRANSMIT + 1) - 1) * ACK_RANDOM_FACTOR
        static const uint32_t MAX_TRANSMIT_WAIT = 93000;
        
        
        CoapMessageLayer(uint8_t* rxBuffer, uint16_t rxLen, TembooCoAPIPStack& ipStack);
        Result reliableSend(CoapMsg& msg, IPAddress destAddr, uint16_t destPort);
        Result cancelReliableSend();
        Result acceptMsg(CoapMsg& msg);
        Result acceptMsg(CoapMsg& msg, IPAddress addr, uint16_t port);
        Result rejectMsg(CoapMsg& msg);
        Result rejectMsg(CoapMsg& msg, IPAddress addr, uint16_t port);
        Result loop();
        Result getLastResult() {return m_lastResult;}
        uint16_t getRXByteCount() {return m_rxByteCount;}
        void setState(State state) {m_state = state;}
        
        
    private:
        uint8_t* m_rxBuffer;
        uint16_t m_rxLen;
        TembooCoAPIPStack& m_ipStack;
        
        State m_state;
        State m_prevState;
        int m_retransmitCount;
        Result m_lastResult;
        IPAddress m_destAddr;
        uint16_t m_destPort;
        
        uint16_t m_msgID;
        uint8_t* m_msgBytes;
        uint16_t m_msgLen;
        int32_t m_rxByteCount;
        TembooTimer m_txSpanTimer;
        TembooTimer m_retransmitTimer;
        uint32_t m_retransmitTimeoutMillis;
        
    
};

#endif
