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

#include "utility/CoapMessageLayer.h"

CoapMessageLayer::CoapMessageLayer(uint8_t* rxBuffer, uint16_t rxLen, TembooCoAPIPStack& ipStack) :
    m_rxBuffer(rxBuffer),
    m_rxLen(rxLen),
    m_ipStack(ipStack),
    m_state(STATE_CLOSED),
    m_prevState(STATE_CLOSED),
    m_retransmitCount(0),
    m_lastResult(NO_ERROR),
    m_msgID(0) {
}


CoapMessageLayer::Result CoapMessageLayer::rejectMsg(CoapMsg& msg) {
    return rejectMsg(msg, m_ipStack.getRemoteAddress(), m_ipStack.getRemotePort());
}

CoapMessageLayer::Result CoapMessageLayer::rejectMsg(CoapMsg& msg, IPAddress addr, uint16_t port) {
    msg.convertToReset();
    TEMBOO_TRACE("DBG: ");
    TEMBOO_TRACELN("Sending RST");
    if (m_ipStack.sendDatagram(addr, port, msg.getMsgBytes(), msg.getMsgLen())) {
        m_lastResult = ERROR_SENDING_PACKET;
    } else {
        m_lastResult = NO_ERROR;
        if (STATE_ACK_PENDING == m_state) {
            // go back to previous state since the
            // message recv'd wasn't what we're expecting
            m_state = m_prevState;
        }
    }
    return m_lastResult;
}


CoapMessageLayer::Result CoapMessageLayer::acceptMsg(CoapMsg& msg) {
    return acceptMsg(msg, m_ipStack.getRemoteAddress(), m_ipStack.getRemotePort());
}



CoapMessageLayer::Result CoapMessageLayer::acceptMsg(CoapMsg& msg, IPAddress addr, uint16_t port) {
    if (m_state != STATE_ACK_PENDING) {
        m_lastResult = ERROR_IMPROPER_STATE;
    } else {
        msg.convertToEmptyAck();
        TEMBOO_TRACE("DBG: ");
        TEMBOO_TRACELN("Sending ACK");
        if (m_ipStack.sendDatagram(addr, port, msg.getMsgBytes(), msg.getMsgLen())) {
            m_lastResult = ERROR_SENDING_PACKET;
        } else {
            m_state = STATE_CLOSED;
            m_lastResult = NO_ERROR;
        }
    }
    return m_lastResult;
}



CoapMessageLayer::Result CoapMessageLayer::reliableSend(CoapMsg& msg, IPAddress destAddr, uint16_t destPort) {
    
    if (m_state != STATE_CLOSED) {
        m_lastResult = ERROR_IMPROPER_STATE;
        return m_lastResult;
    }
    
    m_rxByteCount = 0;
    m_msgID = msg.getId();
    m_msgBytes = msg.getMsgBytes();
    m_msgLen = msg.getMsgLen();
    m_destAddr = destAddr;
    m_destPort = destPort;
    msg.setType(CoapMsg::COAP_CONFIRMABLE);
    m_retransmitCount = 0;
    m_retransmitTimeoutMillis = random(ACK_TIMEOUT, MAX_ACK_TIMEOUT);
    TEMBOO_TRACE("DBG: ");
    TEMBOO_TRACELN("Sending message");
    if (m_ipStack.sendDatagram(m_destAddr, m_destPort, msg.getMsgBytes(), msg.getMsgLen())) {
        m_state = STATE_CLOSED;
        m_lastResult = ERROR_SENDING_PACKET;
    } else {
        m_txSpanTimer.start(MAX_TRANSMIT_WAIT);
        m_retransmitTimer.start(m_retransmitTimeoutMillis);
        m_state = STATE_RELIABLE_TX;
        m_lastResult = NO_ERROR;
    }
    
    return m_lastResult;
}


CoapMessageLayer::Result CoapMessageLayer::cancelReliableSend() {
    if (m_state != STATE_RELIABLE_TX) {
        m_lastResult = ERROR_IMPROPER_STATE;
        return m_lastResult;
    }
    
    m_state = STATE_CLOSED;
    m_lastResult = NO_ERROR;
    return m_lastResult;
}



CoapMessageLayer::Result CoapMessageLayer::loop() {
    
    m_lastResult = NO_ERROR;
    
    switch(m_state) {
        case STATE_RELIABLE_TX:
            // We have sent a CON request.
            // We're expecting an ACK or a response.
            
            // See if it's time to give up all hope of getting an ACK.
            if (m_txSpanTimer.expired()) {
                m_lastResult = ERROR_TX_SPAN_TIME_EXCEEDED;
                m_state = STATE_CLOSED;
                TEMBOO_TRACE("ERROR: ");
                TEMBOO_TRACELN("ACK not received within timeout");
                break;
            }
            
            // See if any messages have come in.
            if (m_ipStack.recvDatagram(m_rxBuffer, m_rxLen, m_rxByteCount)) {
                m_lastResult = ERROR_RECEIVING_PACKET;
                m_state = STATE_CLOSED;
                break;
            }
            
            // We've received something.  See if it's relevant.
            if (m_rxByteCount > 0) {
                CoapMsg msg(m_rxBuffer, m_rxLen, m_rxByteCount);
                
                // Make sure the message is valid
                if (!msg.isValid()) {
                    rejectMsg(msg);
                    
                    // We're only interested in messages coming from the host
                    // we sent the original request to.
                } else if (m_ipStack.getRemoteAddress() == m_destAddr) {
                    switch (msg.getType()) {
                        case CoapMsg::COAP_ACK:
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("ACK Received");
                            // Is it ACK'ing the last request we sent?
                            if (msg.getId() == m_msgID) {
                                m_state = STATE_CLOSED;
                                m_lastResult = ACK_RECEIVED;
                            } else {
                                // if not, just ignore it.
                                TEMBOO_TRACE("ERROR: ");
                                TEMBOO_TRACELN("MID did not match");
                            }
                            
                            break;
                            
                        case CoapMsg::COAP_RESET:
                            // Is it rejecting the last request we sent?
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("RST Received");
                            if (msg.getId() == m_msgID) {
                                m_state = STATE_CLOSED;
                                m_lastResult = RESET_RECEIVED;
                            } else {
                                // if not, just ignore it.
                                TEMBOO_TRACE("ERROR: ");
                                TEMBOO_TRACELN("MID did not match");
                            }
                            break;
                            
                        case CoapMsg::COAP_CONFIRMABLE:
                            // It COULD be the response to our request, or
                            // just some unexpected message.
                            // We'll let the upper layers decide.
                            m_prevState = m_state;
                            m_state = STATE_ACK_PENDING;
                            m_lastResult = CON_RECEIVED;
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("CON Received");
                            break;
                            
                        case CoapMsg::COAP_NON_CONFIRMABLE:
                            // It COULD be the response to our request, or
                            // just some unexpected message.
                            // We'll let the upper layers decide.
                            
                            // That's what Kovatsch et al. show in their FSM.
                            m_state = STATE_CLOSED;
                            m_lastResult = NON_RECEIVED;
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("NON Received");
                            break;
                    }
                    if (msg.getPayloadLen() > 0) {
                        TEMBOO_TRACE("DBG: ");
                        TEMBOO_TRACELN("Payload data:");
                        uint8_t *payload = msg.getPayload();
                        uint16_t len = msg.getPayloadLen();
                        for (uint16_t i = 0; i < len; i++) {
                            TEMBOO_TRACE((char)payload[i]);
                        }
                        TEMBOO_TRACELN();
                    }
                } else if (msg.getType() == CoapMsg::COAP_CONFIRMABLE) {
                    // It's not from the host we sent the request to, but
                    // the sending host expects a reply, so explicitly reject it.
                    rejectMsg(msg);
                }
                
                break;
            }
            
            // Nothing was received.  See if it's time to retransmit.
            if (m_retransmitTimer.expired()) {
                if (m_retransmitCount >= MAX_RETRANSMIT) {
                    // We've retried enough. Give up.
                    TEMBOO_TRACE("ERROR: ");
                    TEMBOO_TRACELN("Maximum retransmit reached");
                    m_lastResult = ERROR_RETRANSMIT_COUNT_EXCEEDED;
                    m_state = STATE_CLOSED;
                } else {
                    TEMBOO_TRACE("DBG: ");
                    TEMBOO_TRACELN("Retransmit message");
                    m_retransmitCount++;
                    m_retransmitTimeoutMillis *= 2;
                    if (m_ipStack.sendDatagram(m_destAddr, m_destPort, m_msgBytes, m_msgLen)) {
                        m_state = STATE_CLOSED;
                        m_lastResult = ERROR_SENDING_PACKET;
                    } else {
                        m_retransmitTimer.start(m_retransmitTimeoutMillis);
                        m_state = STATE_RELIABLE_TX;
                        m_lastResult = NO_ERROR;
                    }
                }
            }
            break;
            
        case STATE_ACK_PENDING:
            // Nothing to do here but wait for
            // the higher layer to accept or reject.
            break;
            
        case STATE_WAITING_FOR_CON:
            // See if any messages have come in.
            if (m_ipStack.recvDatagram(m_rxBuffer, m_rxLen, m_rxByteCount)) {
                m_lastResult = ERROR_RECEIVING_PACKET;
                m_state = STATE_CLOSED;
                break;
            }
            
            // We've received something.  See if it's relevant.
            if (m_rxByteCount > 0) {
                CoapMsg msg(m_rxBuffer, m_rxLen, m_rxByteCount);
                
                // Make sure the message is valid
                if (!msg.isValid()) {
                    rejectMsg(msg);
                    
                    // We're only interested in messages coming from the host
                    // we sent the original request to.
                } else if (m_ipStack.getRemoteAddress() == m_destAddr) {
                    switch (msg.getType()) {
                        case CoapMsg::COAP_ACK:
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("ACK Received");
                            // Is it ACK'ing the last request we sent?
                            if (msg.getId() == m_msgID) {
                                m_state = STATE_CLOSED;
                                m_lastResult = ACK_RECEIVED;
                            } else {
                                // if not, just ignore it.
                                TEMBOO_TRACE("ERROR: ");
                                TEMBOO_TRACELN("MID did not match");
                            }
                            break;
                            
                        case CoapMsg::COAP_RESET:
                            // Is it rejecting the last request we sent?
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("RST Received");
                            if (msg.getId() == m_msgID) {
                                m_state = STATE_CLOSED;
                                m_lastResult = RESET_RECEIVED;
                            } else {
                                // if not, just ignore it.
                                TEMBOO_TRACE("ERROR: ");
                                TEMBOO_TRACELN("MID did not match");
                            }
                            break;
                            
                        case CoapMsg::COAP_CONFIRMABLE:
                            // It COULD be the response to our request, or
                            // just some unexpected message.
                            // We'll let the upper layers decide.
                            m_prevState = m_state;
                            m_state = STATE_ACK_PENDING;
                            m_lastResult = CON_RECEIVED;
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("CON Received");
                            break;
                            
                        case CoapMsg::COAP_NON_CONFIRMABLE:
                            // It COULD be the response to our request, or
                            // just some unexpected message.
                            // We'll let the upper layers decide.
                            
                            // That's what Kovatsch et al. show in their FSM.
                            m_state = STATE_CLOSED;
                            m_lastResult = NON_RECEIVED;
                            TEMBOO_TRACE("DBG: ");
                            TEMBOO_TRACELN("NON Received");
                            break;
                    }
                    if (msg.getPayloadLen() > 0) {
                        TEMBOO_TRACE("DBG: ");
                        TEMBOO_TRACELN("Payload data:");
                        uint8_t *payload = msg.getPayload();
                        uint16_t len = msg.getPayloadLen();
                        for (uint16_t i = 0; i < len; i++) {
                            TEMBOO_TRACE((char)payload[i]);
                        }
                        TEMBOO_TRACELN();
                    }
                } else if (msg.getType() == CoapMsg::COAP_CONFIRMABLE) {
                    // It's not from the host we sent the request to, but
                    // the sending host expects a reply, so explicitly reject it.
                    rejectMsg(msg);
                }
                
                break;
            }
            break;
            
            
        case STATE_CLOSED:
            
            // We haven't sent anything that we're expecting an answer to.
            // We haven't received anything that requires an answer.
            // Just pump the receiver.
            if (m_ipStack.recvDatagram(m_rxBuffer, m_rxLen, m_rxByteCount)) {
                m_lastResult = ERROR_RECEIVING_PACKET;
                break;
            }
            
            // If we received something, handle it.
            if (m_rxByteCount > 0) {
                CoapMsg msg(m_rxBuffer, m_rxLen, m_rxByteCount);
                switch (msg.getType()) {
                    case CoapMsg::COAP_ACK:
                        // Not expecting any ACKS, ignore it.
                        break;
                        
                    case CoapMsg::COAP_RESET:
                        // Haven't sent any CONs and we don't send NONs, ignore it.
                        break;
                        
                    case CoapMsg::COAP_CONFIRMABLE:
                        // Let the higher layers deal with this.
                        m_prevState = m_state;
                        m_state = STATE_ACK_PENDING;
                        m_lastResult = CON_RECEIVED;
                        break;
                        
                    case CoapMsg::COAP_NON_CONFIRMABLE:
                        // Let the higher layers deal with this.
                        m_lastResult = NON_RECEIVED;
                        break;
                }
            }
            
            break;
            
    }
    return m_lastResult;
}

