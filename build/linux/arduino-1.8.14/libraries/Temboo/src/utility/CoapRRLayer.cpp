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

#include "CoapRRLayer.h"

CoapRRLayer::CoapRRLayer(CoapMessageLayer& messageLayer, uint8_t* rxBuffer, uint16_t rxBufferLen) :
    m_messageLayer(messageLayer),
    m_state(STATE_IDLE),
    m_lastResult(NO_ERROR),
    m_token(NULL),
    m_rxBuffer(rxBuffer),
    m_rxBufferLen(rxBufferLen) {
}



CoapRRLayer::Result CoapRRLayer::reliableSend(CoapMsg& msg, char* token, IPAddress addr, uint16_t port) {
    if (m_state != STATE_IDLE) {
        return ERROR_IMPROPER_STATE;
    }
    
    if (CoapMessageLayer::NO_ERROR != m_messageLayer.reliableSend(msg, addr, port)) {
        return ERROR_SENDING_MSG;
    }
    
    m_token = token;
    m_state = STATE_WAITING;
    return NO_ERROR;
}



bool CoapRRLayer::rxTokenMatches(CoapMsg& msg) {
    if (msg.getTokenLen() != strlen(m_token)) {
        return false;
    }
    
    if (0 != memcmp(msg.getToken(), m_token, strlen(m_token))) {
        return false;
    }
    return true;
}



CoapRRLayer::Result CoapRRLayer::loop() {
    
    m_lastResult = NO_ERROR;
    
    switch (m_state) {
            
        case STATE_IDLE:
            
            // Pump the receiver.
            // We're not serving anything, so unless there's an outstanding
            // request (which would mean we would be in STATE_WAITING, not STATE_IDLE),
            // we're going to reject or ignore any incoming traffic.
            switch(m_messageLayer.loop()) {
                case CON_RECEIVED:
                {
                    // Explicitly reject any CON messages so the sender will
                    // quit bugging us with retransmissions.
                    CoapMsg msg(m_rxBuffer, m_rxBufferLen, m_messageLayer.getRXByteCount());
                    m_messageLayer.rejectMsg(msg);
                    break;
                }
                default:
                    // Just ignore anything else.
                    break;
            }
            
            break;
            
        case STATE_WAITING:
            // We're waiting for a response to an earlier request.
            switch(m_messageLayer.loop()) {
                    
                case CoapMessageLayer::NO_ERROR:
                    // Nothing happened. Nothing to do.
                    break;
                    
                case CoapMessageLayer::ACK_RECEIVED:
                {
                    CoapMsg msg(m_rxBuffer, m_rxBufferLen, m_messageLayer.getRXByteCount());
                    
                    // If it wasn't an empty ack, it's a response.
                    // And if the token matches, then it's the response we're waiting for.
                    if (rxTokenMatches(msg)) {
                        m_lastResult = RESPONSE_RECEIVED;
                        m_state = STATE_IDLE;
                    } else {
                        // if ACK is not empty and tokens don't match, an error has occurred
                        if (msg.getTokenLen() != 0) {
                            m_lastResult = ERROR_RECEIVING_RESPONSE;
                            m_state = STATE_IDLE;
                            TEMBOO_TRACE("Error: ");
                            TEMBOO_TRACELN("Msg token did not match");
                        }
                    }
                    break;
                }
                    
                case CoapMessageLayer::RESET_RECEIVED:
                {
                    // If it was a reset, the message should be empty
                    // and there will be no token
                    m_lastResult = RST_RECEIVED;
                    m_state = STATE_IDLE;
                    break;
                }
                    
                case CoapMessageLayer::CON_RECEIVED:
                {
                    // See if this is our response or just some random message.
                    // The message layer has already confirmed it's from the right host.
                    CoapMsg msg(m_rxBuffer, m_rxBufferLen, m_messageLayer.getRXByteCount());
                    
                    // We only accept responses for the current request (i.e. the tokens must match)
                    if (rxTokenMatches(msg)) {
                        m_lastResult = RESPONSE_RECEIVED;
                        m_state = STATE_IDLE;
                    } else {
                        m_messageLayer.rejectMsg(msg);
                        TEMBOO_TRACE("Error: ");
                        TEMBOO_TRACELN("Msg token did not match");
                    }
                    break;
                }
                    
                case CoapMessageLayer::NON_RECEIVED:
                {
                    CoapMsg msg(m_rxBuffer, m_rxBufferLen, m_messageLayer.getRXByteCount());
                    if (rxTokenMatches(msg)) {
                        m_lastResult = RESPONSE_RECEIVED;
                        m_state = STATE_IDLE;
                    } else {
                        // if the token does not match, then an error occurred
                        m_lastResult = ERROR_RECEIVING_RESPONSE;
                        m_state = STATE_IDLE;
                        TEMBOO_TRACE("Error: ");
                        TEMBOO_TRACELN("Msg token did not match");
                    }
                    break;
                }
                    
                default:
                    // Anything else indicates a failure of some sort.  Check
                    // the messageLayer lastResult for specifics.
                    m_lastResult = ERROR_RECEIVING_RESPONSE;
                    m_state = STATE_IDLE;
                    
            }
            break;
    }
    
    return m_lastResult;
}
