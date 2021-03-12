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


#include "utility/TembooGlobal.h"
#include "utility/TembooCoAPSession.h"
#include "utility/TembooTags.h"

#include "TembooCoAPEdgeDevice.h"

#ifndef UINT16_MAX
#define UINT16_MAX (0xFFFF)
#endif

#ifndef UINT32_MAX
#define UINT32_MAX (0xFFFFFFFF)
#endif

//TODO: Maybe.  Put these in PROGMEM and
//      modify any code that uses them.
const char HTTP_CODE_PREFIX[] = "HTTP_CODE\x0A\x1F";
const char HTTP_CODE_SUFFIX[] = "\x0A\x1E";
const char TembooCoAPClient::URI_PATH[] = "exec";
const char TIME_URI_PATH[] = "time";
static char HEADER_TIME[] = "x-temboo-time:";

uint16_t TembooCoAPChoreo::s_nextRequestId = 0;

TembooCoAPClient::TembooCoAPClient(TembooCoAPIPStack& ipStack, IPAddress gatewayAddress, uint16_t gatewayPort) :
    m_messageLayer(m_rxBuffer, sizeof(m_rxBuffer), ipStack),
    m_rrLayer(m_messageLayer, m_rxBuffer, sizeof(m_rxBuffer)),
    m_gatewayAddress(gatewayAddress),
    m_gatewayPort(gatewayPort),
    m_messageID(0),
    m_state(STATE_IDLE),
    m_blockSize(MAX_BLOCK_SIZE),
    m_lastError(NO_ERROR),
    m_dataLen(0),
    m_txIndex(0),
    m_respLen(0),
    m_txByteCount(0),
    m_respHttpCode(0) {
    
    memset(m_token, 0, sizeof(m_token));
    memset(m_dataBuffer, 0, sizeof(m_dataBuffer));
    memset(m_respBuffer, 0, sizeof(m_respBuffer));
    
}


void TembooCoAPClient::resetChoreo() {
    memset(m_token, 0, sizeof(m_token));
    memset(m_dataBuffer, 0, sizeof(m_dataBuffer));
    memset(m_respBuffer, 0, sizeof(m_respBuffer));
    m_dataLen = 0;
    m_respLen = 0;
    m_txIndex = 0;
    m_txByteCount = 0;
    m_rxBlockNum = 0;
    
    m_rrLayer.setState(CoapRRLayer::STATE_IDLE);
    m_messageLayer.setState(CoapMessageLayer::STATE_CLOSED);
}

void TembooCoAPClient::begin(long seed){
    //RFC7252 "strongly recommends" that the initial
    //value of messageID be randomized.  There's no good way
    //to do that reliably on many MCU boards.  We will
    //use random(), and can instruct the user to call randomSeed
    //with input from an unused analog input if it's important to them.
    randomSeed(seed);
    m_messageID = random(0, UINT16_MAX);
    
}


TembooCoAPClient::~TembooCoAPClient() {
}



TembooCoAPClient::Result TembooCoAPClient::write(uint8_t value) {
    if (m_dataLen < sizeof(m_dataBuffer)) {
        m_dataBuffer[m_dataLen] = value;
        m_dataLen++;
        m_txByteCount = 0;
        m_txIndex = 0;
        return NO_ERROR;
    }
    return ERROR_BUFFER_FULL;
}

TembooCoAPClient::Result TembooCoAPClient::saveResponse(uint8_t* values, uint16_t len) {
    len = len < (sizeof(m_respBuffer) - m_respLen - 1) ? len : (sizeof(m_respBuffer) - m_respLen -1);
    TEMBOO_TRACE("DBG: ");
    TEMBOO_TRACELN("Saving payload to the buffer");
    if ( len > 0) {
        memcpy(&m_respBuffer[m_respLen], values, len);
        m_respLen += len;
        return NO_ERROR;
    }
    TEMBOO_TRACE("ERROR: ");
    TEMBOO_TRACELN("Buffer full, payload not saved");
    return ERROR_BUFFER_FULL;
}



TembooCoAPClient::Result TembooCoAPClient::write(uint8_t* values, uint16_t len) {
    Result rc = NO_ERROR;
    while(NO_ERROR == rc && len > 0) {
        rc = write(*values++);
        len--;
    }
    return rc;
}



uint16_t TembooCoAPClient::getNextMessageID() {
    m_messageID++;
    if (m_messageID == 0) {
        m_messageID++;
    }
    return m_messageID;
}


TembooCoAPClient::Result TembooCoAPClient::generateToken() {
    // 5.3.1.  Token suggests the tokenID should be a random value
    
    for (int i = 0; i < 8; i++) {
        m_token[i] = (rand() % 93) + 33;
    }
    m_token[8] = '\0';
    return NO_ERROR;
}

TembooCoAPClient::Result TembooCoAPClient::sendBlockRequest(uint16_t msgID, uint32_t blockNum) {
    
    CoapMsg msg(m_txBuffer, sizeof (m_txBuffer));
    msg.setCode(CoapMsg::COAP_POST);
    
    if (msg.setToken((uint8_t*)m_token, strlen(m_token))) {
        TEMBOO_TRACELN("err: setToken");
        return ERROR_MSG_TOKEN;
    }
    
    msg.setId(msgID);
    
    if (msg.addOption(CoapMsg::COAP_OPTION_URI_PATH, (const uint8_t*)URI_PATH, strlen(URI_PATH))) {
        TEMBOO_TRACELN("err: setURI");
        return ERROR_MSG_OPTION;
    }
    
    uint8_t optionValue[3];
    uint16_t optionLen = 0;
    
    // If this is the last block in a series of blocks (or an only block)
    // include a block2 option to let the server know what our
    // desired block size is for the response.
    
    optionValue[0] = (blockNum & 0xF000) >> 12;
    optionValue[1] = (blockNum & 0x0FF0) >> 4;
    optionValue[2] = (blockNum & 0x000F) << 4;
    optionValue[2] |= (0 ? 0x08 : 0);
    optionValue[2] |= (m_blockSize >> 5) & 0x07;
    
    optionLen = 1;
    if (optionValue[0] > 0) {
        optionLen = 3;
    } else if (optionValue[1] > 0) {
        optionLen = 2;
    }
    if (msg.addOption(CoapMsg::COAP_OPTION_BLOCK2, (const uint8_t*)&optionValue[3 - optionLen], optionLen)) {
        TEMBOO_TRACELN("err: block2");
        return ERROR_MSG_OPTION;
    }
    
    if (m_rrLayer.reliableSend(msg, m_token, m_gatewayAddress, m_gatewayPort) != CoapRRLayer::NO_ERROR) {
        TEMBOO_TRACELN("err: send");
        return ERROR_SENDING_MSG;
    }
    
    return NO_ERROR;
}


TembooCoAPClient::Result TembooCoAPClient::sendBlock(uint16_t msgID, uint8_t* payload, size_t len, uint32_t blockNum, bool moreBlocks) {
    
    CoapMsg msg(m_txBuffer, sizeof (m_txBuffer));
    msg.setCode(CoapMsg::COAP_POST);
    
    if (msg.setToken((uint8_t*)m_token, strlen(m_token))) {
        TEMBOO_TRACELN("err: setToken");
        return ERROR_MSG_TOKEN;
    }
    
    msg.setId(msgID);
    
    if (msg.addOption(CoapMsg::COAP_OPTION_URI_PATH, (const uint8_t*)URI_PATH, strlen(URI_PATH))) {
        TEMBOO_TRACELN("err: setURI");
        return ERROR_MSG_OPTION;
    }
    
    uint8_t optionValue[3];
    uint16_t optionLen = 0;
    
    // If this is the last block in a series of blocks (or an only block)
    // include a block2 option to let the server know what our
    // desired block size is for the response.
    if (!moreBlocksToSend()) {
        optionValue[0] = (m_blockSize >> 5) & 0x07;
        optionLen = (optionValue[0] > 0) ? 1 : 0;
        if (msg.addOption(CoapMsg::COAP_OPTION_BLOCK2, (const uint8_t*)optionValue, optionLen)) {
            TEMBOO_TRACELN("err: block2");
            return ERROR_MSG_OPTION;
        }
    }
    
    // If this is not the only block in the request,
    // include the block1 option.
    if (blockNum > 0 || moreBlocks) {
        
        optionValue[0] = (blockNum & 0xF000) >> 12;
        optionValue[1] = (blockNum & 0x0FF0) >> 4;
        optionValue[2] = (blockNum & 0x000F) << 4;
        optionValue[2] |= (moreBlocks ? 0x08 : 0);
        optionValue[2] |= (m_blockSize >> 5) & 0x07;
        
        optionLen = 1;
        if (optionValue[0] > 0) {
            optionLen = 3;
        } else if (optionValue[1] > 0) {
            optionLen = 2;
        }
        
        if (msg.addOption(CoapMsg::COAP_OPTION_BLOCK1, (const uint8_t*)&optionValue[3 - optionLen], optionLen)) {
            TEMBOO_TRACELN("err: block1");
            return ERROR_MSG_OPTION;
        }
    }
    
    if (msg.setPayload((uint8_t*)payload, len)) {
        TEMBOO_TRACELN("err: setPayload");
        return ERROR_MSG_PAYLOAD;
    }
    
    if (m_rrLayer.reliableSend(msg, m_token, m_gatewayAddress, m_gatewayPort) != CoapRRLayer::NO_ERROR) {
        TEMBOO_TRACELN("err: send");
        return ERROR_SENDING_MSG;
    }
    
    return NO_ERROR;
}


void TembooCoAPClient::adjustRequestBlockSize(CoapMsg& msg) {
    
    // A block1 option in a response means the server is
    // requesting that we use a smaller block size.
    uint16_t newBlockSize = msg.getBlock1Size();
    if (newBlockSize > 0 && newBlockSize < m_blockSize) {
        m_blockSize = newBlockSize;
    }
}


TembooCoAPClient::Result TembooCoAPClient::loop() {
    
    m_lastResult = NO_ERROR;
    
    switch (m_state) {
            
        case STATE_IDLE:
        case STATE_RESPONSE_READY:
            // Pump the receiver.
            // We're not serving anything, so unless there's an outstanding
            // request (which would mean we would be in STATE_WAITING, not STATE_IDLE),
            // the R/R layer will reject or ignore any incoming traffic.
            m_rrLayer.loop();
            
            break;
        case STATE_SEND_REQUEST:
        case STATE_RESPONSE_STARTED:
        case STATE_WAITING_FOR_RESPONSE:
            // We're waiting for a response to an earlier request.
            switch(m_rrLayer.loop()) {
                    
                case CoapRRLayer::NO_ERROR:
                    // Nothing happened. Nothing to do.
                    break;
                    
                case CoapRRLayer::RESPONSE_RECEIVED: {
                    
                    // A response to our request was received.
                    // It may have been a piggybacked ACK or a separate response
                    CoapMsg msg(m_rxBuffer, sizeof(m_rxBuffer), m_messageLayer.getRXByteCount());
                    
                    // See if it has a BLOCK1 option.  If so, make sure the
                    // block number matches the one we just sent. If the block
                    // numbers don't match, we're FUBAR, so abort the request.
                    // If they do match, adjust our request block size if the
                    // server requested a different (smaller) size.
                    
                    if (msg.getOptionCount(CoapMsg::COAP_OPTION_BLOCK1)) {
                        uint32_t ackBlockNum = msg.getBlock1Num();
                        if (ackBlockNum != m_txBlockNum) {
                            TEMBOO_TRACE("ERROR: ");
                            TEMBOO_TRACELN("Block1 message number does not match");
                            m_lastResult = ERROR_RECEIVING_RESPONSE;
                            if (msg.getType() == CoapMsg::COAP_CONFIRMABLE) {
                                m_messageLayer.rejectMsg(msg);
                            }
                            resetChoreo();
                            break;
                        }
                        adjustRequestBlockSize(msg);
                    }
                    
                    // Now deal with the response itself.
                    switch(msg.getCode()) {
                        case CoapMsg::COAP_CONTINUE:    //2.31
                            // 2.31 means the server is requesting the next block of the request.
                            // If there are no more blocks to send, we're FUBAR, so abort the
                            // request.  Otherwise, send the next block.
                            if (m_txIndex >= m_dataLen) {
                                // no more data to send, bad news
                                resetChoreo();
                                m_lastResult = ERROR_REQUEST_FAILED;
                                m_state = STATE_IDLE;
                                TEMBOO_TRACE("ERROR: ");
                                TEMBOO_TRACELN("Gateway requested too many blocks");
                                break;
                            }
                            if (sendChoreoRequest() != NO_ERROR) {
                                resetChoreo();
                                m_lastResult = ERROR_REQUEST_FAILED;
                                m_state = STATE_IDLE;
                                TEMBOO_TRACE("ERROR: ");
                                TEMBOO_TRACELN("Send Choreo request failed");
                            }
                            break;
                            
                        case CoapMsg::COAP_REQUEST_ENTITY_INCOMPLETE: //4.08
                            // 4.08 means the server is missing one or more blocks, so can't
                            // service the request.
                            // We're FUBAR, so abort the request.
                            resetChoreo();
                            m_lastResult = ERROR_REQUEST_FAILED;
                            m_state = STATE_IDLE;
                            TEMBOO_TRACE("ERROR: ");
                            TEMBOO_TRACELN("Gateway returned 4.08");
                            break;
                            
                        case CoapMsg::COAP_REQUEST_ENTITY_TOO_LARGE: //4.13
                            // 4.13 means the server ran out of memory when receiving the
                            // request.
                            // We're FUBAR, so abort the request.
                            resetChoreo();
                            m_lastResult = ERROR_REQUEST_FAILED;
                            m_state = STATE_IDLE;
                            TEMBOO_TRACE("ERROR: ");
                            TEMBOO_TRACELN("Gateway returned 4.13");
                            break;
                            
                        default:
                            // Any response code other than the special ones above means the
                            // server has processed the request and is returning the final result,
                            // which may be in one or more blocks.  If we haven't finished sending
                            // the request, we're FUBAR, so abort the request.  Otherwise, process
                            // the response.
                            m_dataLen = 0;
                            if (moreBlocksToSend()) {
                                m_lastResult = ERROR_RECEIVING_RESPONSE;
                                if (msg.getType() == CoapMsg::COAP_CONFIRMABLE) {
                                    m_messageLayer.rejectMsg(msg);
                                }
                                TEMBOO_TRACE("ERROR: ");
                                TEMBOO_TRACELN("Response received before request finished");
                                resetChoreo();
                                m_state = STATE_IDLE;
                                break;
                            } else {
                                if (msg.getOptionCount(CoapMsg::COAP_OPTION_BLOCK2)) {
                                    // The server is sending a multi-block response, make sure
                                    // it's sending the response block we're expecting.
                                    
                                    uint32_t respBlockNum = msg.getBlock2Num();
                                    TEMBOO_TRACE("DBG: ");
                                    TEMBOO_TRACELN("Block2 opt recv");
                                    
                                    if (respBlockNum > m_rxBlockNum) {
                                        // It sent a newer block than the one we're expecting,
                                        // (i.e. we've somehow missed a block)
                                        // that's an error.
                                        m_lastResult = ERROR_RECEIVING_RESPONSE;
                                        if (msg.getType() == CoapMsg::COAP_CONFIRMABLE) {
                                            m_messageLayer.rejectMsg(msg);
                                        }
                                        resetChoreo();
                                        m_state = STATE_IDLE;
                                        TEMBOO_TRACE("ERROR: ");
                                        TEMBOO_TRACELN("Received block out of order");
                                        break;
                                        
                                    } else if (respBlockNum < m_rxBlockNum) {
                                        // It resent a block we've already received,
                                        // (i.e. it didn't see our ACK),
                                        // just accept (ACK) it again.
                                        if (msg.getType() == CoapMsg::COAP_CONFIRMABLE) {
                                            m_messageLayer.acceptMsg(msg);
                                        }
                                        m_lastResult = NO_ERROR;
                                        sendBlockRequest(m_messageID, m_rxBlockNum);
                                        m_state = STATE_RESPONSE_STARTED;
                                        TEMBOO_TRACE("DBG: ");
                                        TEMBOO_TRACELN("Received previous block");
                                        
                                        
                                    } else {
                                        // Server sent the next block we are expecting.
                                        // Accept it and add the payload to our buffer.
                                        bool block2More = msg.getBlock2More();
                                        m_respHttpCode = msg.getHTTPStatus();
                                        m_lastResult = saveResponse(msg.getPayload(), msg.getPayloadLen());
                                        if (msg.getType() == CoapMsg::COAP_CONFIRMABLE) {
                                            m_rxBlockNum = respBlockNum;
                                            m_messageLayer.acceptMsg(msg);
                                        }
                                        if (block2More) {
                                            m_rxBlockNum++;
                                            m_messageID++;
                                            TEMBOO_TRACE("DBG: ");
                                            TEMBOO_TRACELN("Request next block2 msg");
                                            sendBlockRequest(m_messageID, m_rxBlockNum);
                                            m_state = STATE_RESPONSE_STARTED;
                                        } else {
                                            TEMBOO_TRACE("DBG: ");
                                            TEMBOO_TRACELN("Final block2 msg recv");
                                            TEMBOO_TRACE("DBG: ");
                                            TEMBOO_TRACELN("Response complete");
                                            m_state = STATE_RESPONSE_READY;
                                        }
                                    }
                                    
                                } else {
                                    // There's no Block2 option, so is either
                                    // the one and only block in the response
                                    // or an empty ack.
                                    
                                    // check if empty to handle final ack. If empty
                                    // wait for CON with matching token and then
                                    // request other blocks of response
                                    
                                    if (msg.getCode() == CoapMsg::COAP_EMPTY) {
                                        m_rrLayer.setState(CoapRRLayer::STATE_WAITING);
                                        m_messageLayer.setState(CoapMessageLayer::STATE_WAITING_FOR_CON);
                                        m_state = STATE_WAITING_FOR_RESPONSE;
                                        TEMBOO_TRACE("DBG: ");
                                        TEMBOO_TRACELN("Empty ACK received, waiting for response");
                                        
                                    } else {
                                        m_respHttpCode = msg.getHTTPStatus();
                                        m_lastResult = saveResponse(msg.getPayload(), msg.getPayloadLen());
                                        m_messageLayer.acceptMsg(msg);
                                        m_state = STATE_RESPONSE_READY;
                                        TEMBOO_TRACE("DBG: ");
                                        TEMBOO_TRACELN("Response complete");
                                    }
                                }
                                
                            }
                    }
                    
                    // Does it have a Block2 option?
                    
                    uint32_t responseBlockNum = msg.getBlock2Num();
                    if (responseBlockNum == m_rxBlockNum && msg.getOptionCount(CoapMsg::COAP_OPTION_BLOCK2)) {
                        adjustRequestBlockSize(msg);
                        m_rxBlockNum++;
                        if (0 == m_rxBlockNum) {
                            clearData();
                        }
                    }
                    break;
                }
                    
                case CoapRRLayer::ERROR_RECEIVING_RESPONSE:
                    m_lastResult = ERROR_REQUEST_FAILED;
                    m_state = STATE_IDLE;
                    TEMBOO_TRACE("ERROR: ");
                    TEMBOO_TRACELN("Error receiving response");
                    break;
                    
                case CoapRRLayer::RST_RECEIVED:
                    m_lastResult = ERROR_REQUEST_FAILED;
                    m_state = STATE_IDLE;
                    TEMBOO_TRACE("ERROR: ");
                    TEMBOO_TRACELN("RST received");
                    break;
                    
                default:
                    // Anything else indicates a failure of some sort.  Check
                    // the messageLayer lastResult for specifics.
                    TEMBOO_TRACE("ERROR: ");
                    TEMBOO_TRACELN("Request failed");
                    m_lastResult = ERROR_REQUEST_FAILED;
                    m_state = STATE_IDLE;
                    
            }
            break;
        default:
            break;
    }
    
    return m_lastResult;
}

void TembooCoAPClient::cancelWait() {
    if (STATE_WAITING_FOR_RESPONSE == m_state) {
        m_messageLayer.cancelReliableSend();
        m_dataLen = 0;
        m_state = STATE_IDLE;
    }
}


bool TembooCoAPClient::moreBlocksToSend() {
    uint16_t payloadLength = (m_dataLen - m_txByteCount) < m_blockSize ? (m_dataLen - m_txByteCount) : m_blockSize;
    return ((m_txByteCount + payloadLength) < m_dataLen);
}

TembooCoAPClient::Result TembooCoAPClient::sendChoreoRequest() {
    uint16_t payloadLength = 0;
    
    generateToken();
    
    payloadLength = (m_dataLen - m_txByteCount) < m_blockSize ? (m_dataLen - m_txByteCount) : m_blockSize;
    m_txBlockNum = m_txByteCount/m_blockSize;
    bool moreBlocks = (m_txByteCount + payloadLength) < m_dataLen;
    m_lastError = sendBlock(m_messageID, &m_dataBuffer[m_txIndex], payloadLength, m_txBlockNum, moreBlocks);
    m_messageID++;
    if (TembooCoAPClient::NO_ERROR == m_lastError) {
        m_state = STATE_SEND_REQUEST;
        m_txIndex += payloadLength;
        m_txByteCount += payloadLength;
    } else {
        m_lastError = ERROR_SENDING_MSG;
        m_state = STATE_ERROR;
    }
    
    
    return m_lastError;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////





TembooCoAPChoreo::TembooCoAPChoreo(TembooCoAPClient& client) :
m_client(client),
m_accountName(NULL),
m_appKeyName(NULL),
m_appKeyValue(NULL),
m_path(NULL),
m_requestId(0),
m_availableChars(0),
m_nextChar(NULL),
m_nextState(END)
{
}

TembooCoAPChoreo::~TembooCoAPChoreo() {
}


void TembooCoAPChoreo::setAccountName(const String& accountName) {
    m_accountName = accountName.c_str();
}


void TembooCoAPChoreo::setAccountName(const char* accountName) {
    m_accountName = accountName;
}


void TembooCoAPChoreo::setAppKeyName(const String& appKeyName) {
    m_appKeyName = appKeyName.c_str();
}


void TembooCoAPChoreo::setAppKeyName(const char* appKeyName) {
    m_appKeyName = appKeyName;
}


void TembooCoAPChoreo::setAppKey(const String& appKeyValue) {
    m_appKeyValue = appKeyValue.c_str();
}


void TembooCoAPChoreo::setAppKey(const char* appKeyValue) {
    m_appKeyValue = appKeyValue;
}


void TembooCoAPChoreo::setChoreo(const String& path) {
    m_path = path.c_str();
}


void TembooCoAPChoreo::setChoreo(const char* path) {
    m_path = path;
}


void TembooCoAPChoreo::setSavedInputs(const String& savedInputsName) {
    m_preset.put(savedInputsName.c_str());
}


void TembooCoAPChoreo::setSavedInputs(const char* savedInputsName) {
    m_preset.put(savedInputsName);
}


void TembooCoAPChoreo::setCredential(const String& credentialName) {
    m_preset.put(credentialName.c_str());
}


void TembooCoAPChoreo::setCredential(const char* credentialName) {
    m_preset.put(credentialName);
}

void TembooCoAPChoreo::setProfile(const String& profileName) {
    m_preset.put(profileName.c_str());
}


void TembooCoAPChoreo::setProfile(const char* profileName) {
    m_preset.put(profileName);
}



void TembooCoAPChoreo::addInput(const String& inputName, const String& inputValue) {
    m_inputs.put(inputName.c_str(), inputValue.c_str());
}


void TembooCoAPChoreo::addInput(const char* inputName, const char* inputValue) {
    m_inputs.put(inputName, inputValue);
}


void TembooCoAPChoreo::addInput(const char* inputName, const String& inputValue) {
    m_inputs.put(inputName, inputValue.c_str());
}


void TembooCoAPChoreo::addInput(const String& inputName, const char* inputValue) {
    m_inputs.put(inputName.c_str(), inputValue);
}


void TembooCoAPChoreo::addOutputFilter(const char* outputName, const char* filterPath, const char* variableName) {
    m_outputs.put(outputName, filterPath, variableName);
}


void TembooCoAPChoreo::addOutputFilter(const String& outputName, const char* filterPath, const char* variableName) {
    m_outputs.put(outputName.c_str(), filterPath, variableName);
}


void TembooCoAPChoreo::addOutputFilter(const char* outputName, const String& filterPath, const char* variableName) {
    m_outputs.put(outputName, filterPath.c_str(), variableName);
}


void TembooCoAPChoreo::addOutputFilter(const String& outputName, const String& filterPath, const char* variableName) {
    m_outputs.put(outputName.c_str(), filterPath.c_str(), variableName);
}


void TembooCoAPChoreo::addOutputFilter(const char* outputName, const char* filterPath, const String& variableName) {
    m_outputs.put(outputName, filterPath, variableName.c_str());
}


void TembooCoAPChoreo::addOutputFilter(const String& outputName, const char* filterPath, const String& variableName) {
    m_outputs.put(outputName.c_str(), filterPath, variableName.c_str());
}


void TembooCoAPChoreo::addOutputFilter(const char* outputName, const String& filterPath, const String& variableName) {
    m_outputs.put(outputName, filterPath.c_str(), variableName.c_str());
}


void TembooCoAPChoreo::addOutputFilter(const String& outputName, const String& filterPath, const String& variableName) {
    m_outputs.put(outputName.c_str(), filterPath.c_str(), variableName.c_str());
}

int TembooCoAPChoreo::waitForResponse(TembooTimer& timer) {
    
    int rc = SUCCESS;
    while (m_client.getState() == TembooCoAPClient::STATE_RESPONSE_STARTED || m_client.getState() == TembooCoAPClient::STATE_WAITING_FOR_RESPONSE) {
        if (timer.expired()) {
            TEMBOO_TRACELN("ERROR: Choreo timeout");
            rc = TEMBOO_ERROR_TIMEOUT;
            break;
        }
        m_client.loop();
        // While the buffer may be full, we need to receive all of the data
        // from the gateway even though we discard it. We still return
        // the buffer error code, but the user is still able to see what
        // data was able to fit in the current buffer
        if (m_client.getMessageState() != TembooCoAPClient::NO_ERROR && m_client.getMessageState() != TembooCoAPClient::ERROR_BUFFER_FULL) {
            rc = FAILURE;
            break;
        }
    }
    
    return rc;
}

int TembooCoAPChoreo::run(uint16_t timeoutSecs) {
    m_nextChar = NULL;
    
    if (IS_EMPTY(m_accountName)) {
        return TEMBOO_ERROR_ACCOUNT_MISSING;
    }
    
    if (IS_EMPTY(m_path)) {
        return TEMBOO_ERROR_CHOREO_MISSING;
    }
    
    if (IS_EMPTY(m_appKeyName)) {
        return TEMBOO_ERROR_APPKEY_NAME_MISSING;
    }
    
    if (IS_EMPTY(m_appKeyValue)) {
        return TEMBOO_ERROR_APPKEY_MISSING;
    }
    int rc = 0;
    
    TembooTimer timer(timeoutSecs * 1000L);
    
    for (int i = 0; i < 2; i++) {
        
        m_client.resetChoreo();
        
        TembooCoAPSession session(m_client);
        m_requestId = s_nextRequestId++;
        
        m_respData = NULL;
        m_availableChars = 0;
        m_nextState = START;
        uint16toa(0 , m_httpCodeStr);
        
        m_client.getNextMessageID();
        TEMBOO_TRACE("DBG: ");
        TEMBOO_TRACELN("Sending request");
        rc = session.executeChoreo(m_requestId, m_accountName, m_appKeyName, m_appKeyValue, m_path, m_inputs, m_expressions, m_sensors, m_outputs, m_preset, m_deviceType, m_deviceName);
        if (SUCCESS != rc) {
            goto ErrorExit;
        }
        
        // finish sending Choreo request
        while (m_client.getState() == TembooCoAPClient::STATE_SEND_REQUEST) {
            if(m_client.loop() == TembooCoAPClient::ERROR_REQUEST_FAILED) {
                rc = m_client.getMessageState();
                TEMBOO_TRACE("ERROR: ");
                TEMBOO_TRACELN("Choreo request failed");
                goto ErrorExit;
            }
        }
        
        // choreo request complete, wait for CON from gateway
        // and then request the rest of the response
        
        rc = waitForResponse(timer);
        if (SUCCESS != rc){
            rc = m_client.getMessageState();
            TEMBOO_TRACE("ERROR: ");
            TEMBOO_TRACELN("Waiting for response failed");
            goto ErrorExit;
        } else {
            
            m_respData = (char*)m_client.getPacketBuffer();
            uint16_t httpCode = m_client.getRespHttpCode();
            if (httpCode >= 700) {
                httpCode = 0;
            }
            
            uint16toa(httpCode, m_httpCodeStr);
            m_availableChars = strlen(m_respData) + strlen(m_httpCodeStr) + strlen(HTTP_CODE_PREFIX) + strlen(HTTP_CODE_SUFFIX);
            
            m_nextChar = HTTP_CODE_PREFIX;
            
            //Unauthroized, need to update the time
            if (httpCode == 401 && i == 0) {
                find(HEADER_TIME);
                TembooCoAPSession::setTime((unsigned long)this->parseInt());
            } else {
                TEMBOO_TRACE("DBG: ");
                TEMBOO_TRACE(m_availableChars);
                TEMBOO_TRACELN(" CHARS");
                TEMBOO_TRACE("DBG: ");
                TEMBOO_TRACELN("Response buffer data:");
                TEMBOO_TRACELN(m_respData);
                
                rc = m_client.getMessageState();
                break;
            }
        }
    }
    
ErrorExit:
    if (SUCCESS != rc) {
        TEMBOO_TRACE(" ERROR:");
        TEMBOO_TRACELN(rc);
    }
    return rc;
}


int TembooCoAPChoreo::available() {
    return m_availableChars;
}


int TembooCoAPChoreo::peek() {
    if (m_availableChars > 0) {
        return (int)*m_nextChar;
    }
    return -1;
}


int TembooCoAPChoreo::read() {
    
    if (m_availableChars > 0) {
        int c = 0;
        switch(m_nextState) {
            case START:
                m_nextChar = HTTP_CODE_PREFIX;
                c = (int)(*m_nextChar++);
                m_nextState = HTTP_CODE_PRE;
                break;
                
            case HTTP_CODE_PRE:
                c = (int)(*m_nextChar++);
                if ('\0' == *m_nextChar) {
                    m_nextState = HTTP_CODE_VALUE;
                    m_nextChar = m_httpCodeStr;
                }
                break;
                
            case HTTP_CODE_VALUE:
                c = (int)(*m_nextChar++);
                if (*m_nextChar == '\0') {
                    m_nextState = HTTP_CODE_SUF;
                    m_nextChar = HTTP_CODE_SUFFIX;
                }
                break;
                
            case HTTP_CODE_SUF:
                c = (int)(*m_nextChar++);
                if ('\0' == *m_nextChar) {
                    m_nextState = RESP_DATA;
                    m_nextChar = m_respData;
                }
                break;
                
            case RESP_DATA:
                c = (int)(*m_nextChar++);
                if ('\0' == *m_nextChar || m_availableChars <= 0) {
                    m_nextState = END;
                }
                break;
                
            case END:
            default:
                c = -1;
        }
        if (m_availableChars > 0) {
            m_availableChars--;
        }
        return c;
    } else {
        return -1;
    }
}


size_t TembooCoAPChoreo::write(uint8_t __attribute__ ((unused)) data) {
    return 0;
}


void TembooCoAPChoreo::flush() {
    m_nextChar = NULL;
    m_nextState = END;
    m_availableChars = 0;
}

