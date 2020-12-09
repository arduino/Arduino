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

#include <stdint.h>
#include <string.h>
#include "CoapMsg.h"
#include "TembooGlobal.h"

const uint8_t COAP_VERSION = 1;
const uint8_t HEADER_LENGTH = 4;


CoapMsg::CoapMsg(uint8_t* buffer, uint16_t bufferLen) : m_buffer(buffer), m_bufferLen(bufferLen) {
    
    // Starting a new message.  All messages have a header.
    m_msgLen = HEADER_LENGTH;
    memset(m_buffer, 0, m_bufferLen);
    m_buffer[0] = COAP_VERSION << 6;
    m_buildState = BUILD_BEGIN;
    m_lastOptionCode = 0;
}



CoapMsg::CoapMsg(uint8_t* buffer, uint16_t bufferLen, uint16_t packetLen) : m_buffer(buffer), m_bufferLen(bufferLen) {
    m_msgLen = packetLen;
    m_buildState = BUILD_HAVE_PAYLOAD;
    m_lastOptionCode = 0;
}



void CoapMsg::setType(CoapMsg::Type msgType) {
    m_buffer[0] &= 0xCF; //11001111
    m_buffer[0] |= msgType << 4;
}



CoapMsg::Type CoapMsg::getType() {
    return (CoapMsg::Type)((m_buffer[0] & 0x30) >> 4);
}



void CoapMsg::setId(uint16_t msgId) {
    m_buffer[2] = msgId >> 8;
    m_buffer[3] = msgId & 0x00FF;
}



uint16_t CoapMsg::getId() {
    return (m_buffer[2] << 8) + m_buffer[3];
}



CoapMsg::Result CoapMsg::setToken(const uint8_t* token, uint8_t tokenLen){
    
    if (m_buildState >= BUILD_HAVE_TOKEN) {
        return COAP_RESULT_BUILD_ORDER;
    }
    
    if (tokenLen > 8){
        return COAP_RESULT_TOKEN_LENGTH;
    }
    
    if ((tokenLen > 0) && (NULL == token)) {
        return COAP_RESULT_TOKEN_NULL;
    }
    
    if ((m_msgLen + tokenLen) > m_bufferLen) {
        return COAP_RESULT_BUFFER_OVERRUN;
    }
    
    memcpy(m_buffer + m_msgLen, token, tokenLen);
    m_msgLen += tokenLen;
    m_buffer[0] &= 0xF0;
    m_buffer[0] |= tokenLen;
    m_buildState = BUILD_HAVE_TOKEN;
    
    return COAP_RESULT_SUCCESS;
}



uint8_t* CoapMsg::getToken() {
    if (getTokenLen() > 0) {
        return m_buffer + HEADER_LENGTH;
    }
    return NULL;
}



uint8_t CoapMsg::getTokenLen() {
    return m_buffer[0] & 0x0F;
}



void CoapMsg::setCode(CoapMsg::Code code) {
    m_buffer[1] = (uint8_t)code;
}



CoapMsg::Code CoapMsg::getCode() {
    return (CoapMsg::Code)(m_buffer[1]);
}



uint16_t CoapMsg::getHTTPStatus() {
    uint8_t code = getCode();
    // 3 MSbs are the most significant digit (0 - 6)
    // 5 LSbs are the two least significant digits (0 - 31)
    return (code >> 5) * 100 + (code & 0x1F);
}



CoapMsg::Result CoapMsg::setPayload(const uint8_t* payload, uint16_t payloadLen) {
    
    if (m_buildState >= BUILD_HAVE_PAYLOAD) {
        return COAP_RESULT_BUILD_ORDER;
    }
    
    if (payloadLen > 0 && payload == NULL) {
        return COAP_RESULT_PAYLOAD_NULL;
    }
    
    if ((m_msgLen + payloadLen + 1) > m_bufferLen) {
        return COAP_RESULT_BUFFER_OVERRUN;
    }
    
    // Add the special payload marker flag.
    m_buffer[m_msgLen++] = 0xFF;
    memcpy(m_buffer + m_msgLen, payload, payloadLen);
    m_msgLen += payloadLen;
    m_buildState = BUILD_HAVE_PAYLOAD;
    
    return COAP_RESULT_SUCCESS;
}



uint8_t* CoapMsg::getPayload() {
    if (m_buildState < BUILD_HAVE_PAYLOAD) {
        return NULL;
    }
    
    uint8_t* payload = NULL;
    uint16_t optionDelta = 0;
    uint16_t optionLen = 0;
    uint8_t* i = m_buffer + HEADER_LENGTH + getTokenLen();
    
    while (i < m_buffer + m_msgLen) {
        i = decodeOption(i, &optionDelta, &optionLen);
        if ((optionDelta == 15) || (optionLen == 15)) {
            //Technically, if either optionDelta or optionLen is 15, then
            //both MUST be 15, else it's a malformed message.  However,
            //we're going to be a little loose with the spec here.
            payload = i;
            break;
        }
    }
    
    return payload;
}



uint16_t CoapMsg::getPayloadLen() {
    if (m_buildState < BUILD_HAVE_PAYLOAD) {
        return 0;
    }
    
    uint8_t* payload = getPayload();
    if (NULL == payload) {
        return 0;
    }
    return m_buffer + m_msgLen - payload;
}



/*
 0   1   2   3   4   5   6   7
 +---------------+---------------+
 |               |               |
 |  Option Delta | Option Length |   1 byte
 |               |               |
 +---------------+---------------+
 \                               \   0 bytes if OptionDelta <= 12
 /         Option Delta          /   1 byte if OptionDelte == 13
 \          (extended)           \   2 bytes if OptionDelta == 14
 +-------------------------------+
 \                               \   0 bytes if OptionLength <= 12
 /         Option Length         /   1 byte if OptionLength == 13
 \          (extended)           \   2 bytes if OptionLength == 14
 +-------------------------------+
 \                               \
 /                               /
 \                               \
 /         Option Value          /   0 or more bytes (i.e. OptionLength bytes)
 \                               \
 /                               /
 \                               \
 +-------------------------------+
 */

CoapMsg::Result CoapMsg::addOption(CoapMsg::Option optionCode, const uint8_t* optionValue, uint16_t optionLen) {
    
    if (m_buildState > BUILD_HAVE_OPTIONS) {
        return COAP_RESULT_BUILD_ORDER;
    }
    
    if (m_lastOptionCode > optionCode) {
        return COAP_RESULT_BUILD_ORDER;
    }
    
    if (optionLen > 0 && NULL == optionValue) {
        return COAP_RESULT_OPTION_NULL;
    }
    
    CoapMsg::Result rc = validateOption(optionCode, optionValue, optionLen);
    if (COAP_RESULT_SUCCESS != rc) {
        return rc;
    }
    
    // See if there's enough room in the buffer to add this option.
    uint16_t byteCount = 1;
    uint16_t optionDelta = optionCode - m_lastOptionCode;
    if (optionDelta >= 13) {
        byteCount++;
    }
    if (optionDelta >= 269) {
        byteCount++;
    }
    if (optionLen >= 13) {
        byteCount++;
    }
    if (optionLen >= 269) {
        byteCount++;
    }
    byteCount += optionLen;
    
    if (m_msgLen + byteCount > m_bufferLen) {
        return COAP_RESULT_BUFFER_OVERRUN;
    }
    
    // If we get this far, there's enough room.
    byteCount = 0;
    if (optionDelta >= 269) {
        m_buffer[m_msgLen] = 14 << 4;
        byteCount++;
        m_buffer[m_msgLen + byteCount] = (optionDelta - 269) >> 8;
        byteCount++;
        m_buffer[m_msgLen + byteCount] = (optionDelta - 269) & 0x00FF;
    } else if (optionDelta >= 13) {
        m_buffer[m_msgLen] = 13 << 4;
        byteCount++;
        m_buffer[m_msgLen + byteCount] = (optionDelta - 13);
    } else {
        m_buffer[m_msgLen] = optionDelta << 4;
    }
    
    if (optionLen >= 269) {
        m_buffer[m_msgLen] = (m_buffer[m_msgLen] & 0XF0) | 14;
        byteCount++;
        m_buffer[m_msgLen + byteCount] = (optionLen - 269) >> 8;
        byteCount++;
        m_buffer[m_msgLen + byteCount] = (optionLen - 269) & 0xFF;
    } else if (optionLen >= 13) {
        m_buffer[m_msgLen] = (m_buffer[m_msgLen] & 0xF0) | 13;
        byteCount++;
        m_buffer[m_msgLen + byteCount] = (optionLen - 13);
    } else {
        m_buffer[m_msgLen] = (m_buffer[m_msgLen] & 0xF0) | optionLen;
        byteCount++;
    }
    
    m_msgLen += byteCount;
    if (optionLen > 0) {
        memcpy(m_buffer + m_msgLen, optionValue, optionLen);
    }
    m_msgLen += optionLen;
    m_lastOptionCode = optionCode;
    return COAP_RESULT_SUCCESS;
}



CoapMsg::Result CoapMsg::validateOption(CoapMsg::Option optionCode, const uint8_t* optionValue, uint16_t optionLen) {
    
    CoapMsg::Result rc = COAP_RESULT_SUCCESS;
    
    switch(optionCode) {
        case COAP_OPTION_IF_MATCH:
            rc = validateOptionValue(0, 8, optionValue, optionLen);
            break;
            
        case COAP_OPTION_URI_HOST:
            rc = validateOptionValue(1, 255, optionValue, optionLen);
            break;
            
        case COAP_OPTION_ETAG:
            rc = validateOptionValue(1, 8, optionValue, optionLen);
            break;
            
        case COAP_OPTION_IF_NONE_MATCH:
            rc = validateOptionValue(0, 0, optionValue, optionLen);
            break;
            
            //TODO:			case COAP_OPTION_OBSERVE:
            //                rc = validateOptionValue(0, 0, optionValue, optionLen);
            //                break;
            
        case COAP_OPTION_URI_PORT:
            rc = validateOptionValue(0, 2, optionValue, optionLen);
            break;
            
        case COAP_OPTION_LOCATION_PATH:
            rc = validateOptionValue(0, 255, optionValue, optionLen);
            break;
            
        case COAP_OPTION_URI_PATH:
            rc = validateOptionValue(0, 255, optionValue, optionLen);
            break;
            
        case COAP_OPTION_CONTENT_FORMAT:
            rc = validateOptionValue(0, 2, optionValue, optionLen);
            break;
            
        case COAP_OPTION_MAX_AGE:
            rc = validateOptionValue(0, 4, optionValue, optionLen);
            break;
            
        case COAP_OPTION_URI_QUERY:
            rc = validateOptionValue(0, 255, optionValue, optionLen);
            break;
            
        case COAP_OPTION_ACCEPT:
            rc = validateOptionValue(0, 2, optionValue, optionLen);
            break;
            
        case COAP_OPTION_LOCATION_QUERY:
            rc = validateOptionValue(0, 255, optionValue, optionLen);
            break;
            
        case COAP_OPTION_BLOCK2:
            rc = validateOptionValue(0, 3, optionValue, optionLen);
            break;
            
        case COAP_OPTION_BLOCK1:
            rc = validateOptionValue(0, 3, optionValue, optionLen);
            break;
            
        case COAP_OPTION_SIZE2:
            rc = validateOptionValue(0, 4, optionValue, optionLen);
            break;
            
        case COAP_OPTION_PROXY_URI:
            rc = validateOptionValue(0, 1034, optionValue, optionLen);
            break;
            
        case COAP_OPTION_PROXY_SCHEME:
            rc = validateOptionValue(1, 255, optionValue, optionLen);
            break;
            
        case COAP_OPTION_SIZE1:
            rc = validateOptionValue(0, 4, optionValue, optionLen);
            break;
            
        default:
            rc = COAP_RESULT_OPTION_UNKNOWN;
            
    }
    return rc;
}



CoapMsg::Result CoapMsg::validateOptionValue(uint16_t minLen, uint16_t maxLen, const uint8_t* optionValue, uint16_t optionLen) {
    
    if (optionLen < minLen || optionLen > maxLen) {
        return COAP_RESULT_OPTION_LENGTH;
    }
    if (optionLen > 0 && NULL == optionValue) {
        return COAP_RESULT_OPTION_NULL;
    }
    
    //TODO: Maybe.  Validate value format (uint vs string vs opaque)
    
    return COAP_RESULT_SUCCESS;
}



uint8_t* CoapMsg::getMsgBytes() {
    return m_buffer;
}



uint16_t CoapMsg::getMsgLen() {
    return m_msgLen;
}



uint8_t* CoapMsg::decodeOption(uint8_t* buffer, uint16_t* optionDelta, uint16_t* optionLen) {
    
    *optionDelta = *buffer >> 4;
    *optionLen = *buffer & 0x0F;
    buffer++;
    
    if (13 == *optionDelta) {
        *optionDelta = *buffer++ + 13;
    } else if (14 == *optionDelta) {
        *optionDelta = *buffer++ << 8;
        *optionDelta += *buffer++;
        *optionDelta += 269;
    }
    
    if (13 == *optionLen) {
        *optionLen = *buffer++ + 13;
    } else if (14 == *optionLen) {
        *optionLen = *buffer++ << 8;
        *optionLen += *buffer++;
        *optionLen += 269;
    }
    
    if (*optionLen != 15) {
        buffer += *optionLen;
    }
    
    return buffer;
}



uint16_t CoapMsg::getOptionCount(CoapMsg::Option optionCode) {
    
    if (m_buildState < BUILD_HAVE_OPTIONS) {
        return 0;
    }
    
    uint16_t count = 0;
    uint16_t lastOption = 0;
    uint16_t optionDelta = 0;
    uint16_t optionLen = 0;
    uint8_t* i = m_buffer + HEADER_LENGTH + getTokenLen();
    
    while (i < (m_buffer + m_msgLen) && *i != 0xFF) {
        i = decodeOption(i, &optionDelta, &optionLen);
        lastOption += optionDelta;
        if (lastOption == optionCode) {
            count++;
        }
    }
    return count;
}



uint16_t CoapMsg::getOptionLen(CoapMsg::Option optionCode, uint16_t index) {
    
    uint16_t count = 0;
    uint16_t lastOption = 0;
    uint16_t optionDelta = 0;
    uint16_t optionLen = 0;
    uint8_t* i = m_buffer + HEADER_LENGTH + getTokenLen();
    
    while (i < (m_buffer + m_msgLen) && *i != 0xFF) {
        i = decodeOption(i, &optionDelta, &optionLen);
        lastOption += optionDelta;
        if (lastOption == optionCode) {
            if (count == index) {
                break;
            }
            count++;
        }
        optionLen = 0;
    }
    return optionLen;
}



uint8_t* CoapMsg::getOptionValue(CoapMsg::Option optionCode, uint16_t index) {
    uint16_t count = 0;
    uint16_t lastOption = 0;
    uint16_t optionDelta = 0;
    uint16_t optionLen = 0;
    uint8_t* i = m_buffer + HEADER_LENGTH + getTokenLen();
    
    while (i < (m_buffer + m_msgLen) && *i != 0xFF) {
        i = decodeOption(i, &optionDelta, &optionLen);
        lastOption += optionDelta;
        if (lastOption == optionCode) {
            if (count == index) {
                return i - optionLen;
            }
            count++;
        }
    }
    return NULL;
}



CoapMsg::Result CoapMsg::getOption(CoapMsg::Option optionCode, uint16_t index, uint8_t*& optionValue, uint16_t& optionLen) {
    
    uint16_t count = 0;
    uint16_t lastOption = 0;
    uint16_t optionDelta = 0;
    uint16_t optLen = 0;
    uint8_t* i = m_buffer + HEADER_LENGTH + getTokenLen();
    
    while (i < (m_buffer + m_msgLen) && *i != 0xFF) {
        i = decodeOption(i, &optionDelta, &optLen);
        lastOption += optionDelta;
        if (lastOption == optionCode) {
            if (count == index) {
                optionValue = i - optLen;
                optionLen = optLen;
                return COAP_RESULT_SUCCESS;
            }
            count++;
        }
    }
    return COAP_RESULT_OPTION_NOT_FOUND;
    
}

uint16_t CoapMsg::getBlock1Size() {
    return getBlockSize(COAP_OPTION_BLOCK1);
}

uint16_t CoapMsg::getBlock2Size() {
    return getBlockSize(COAP_OPTION_BLOCK2);
}

uint16_t CoapMsg::getBlockSize(CoapMsg::Option optionCode) {
    if (m_buildState < BUILD_HAVE_OPTIONS) {
        return 0;
    }
    
    uint16_t optionLen;
    uint8_t* optionValue;
    if (getOption(optionCode, 0, optionValue, optionLen) != COAP_RESULT_SUCCESS) {
        return 0;
    }
    uint16_t blockLen = 16 << (optionValue[optionLen - 1] & 0x07);
    if (blockLen > 1024) {
        return 0;
    }
    return blockLen;
}



uint32_t CoapMsg::getBlock1Num() {
    return getBlockNum(COAP_OPTION_BLOCK1);
}



uint32_t CoapMsg::getBlock2Num() {
    return getBlockNum(COAP_OPTION_BLOCK2);
}



uint32_t CoapMsg::getBlockNum(CoapMsg::Option optionCode) {
    if (m_buildState < BUILD_HAVE_OPTIONS) {
        return 0;
    }
    
    uint16_t optionLen;
    uint8_t* optionValue;
    if (getOption(optionCode, 0, optionValue, optionLen) != COAP_RESULT_SUCCESS) {
        return 0;
    }
    int32_t blockNum = 0;
    for (;optionLen > 0; optionLen--) {
        blockNum <<= 8;
        blockNum += *optionValue;
        optionValue++;
    }
    blockNum >>= 4;
    
    return blockNum;
}



bool CoapMsg::getBlock1More() {
    return getBlockMore(COAP_OPTION_BLOCK1);
}



bool CoapMsg::getBlock2More() {
    return getBlockMore(COAP_OPTION_BLOCK2);
}



bool CoapMsg::getBlockMore(CoapMsg::Option optionCode) {
    if (m_buildState < BUILD_HAVE_OPTIONS) {
        return 0;
    }
    
    uint16_t optionLen;
    uint8_t* optionValue;
    if (getOption(optionCode, 0, optionValue, optionLen) != COAP_RESULT_SUCCESS) {
        return 0;
    }
    if (optionLen == 0) {
        return false;
    }
    
    return (optionValue[optionLen-1] & 0x08) > 0;
}


/**
 * Convert this (existing received) message into a reset message.
 */
void CoapMsg::convertToReset() {
    setType(COAP_RESET);
    setCode(COAP_EMPTY);
    
    // Set token length to 0
    m_buffer[0] &= 0xF0;
    
    m_msgLen = HEADER_LENGTH;
}

void CoapMsg::convertToEmptyAck() {
    setType(COAP_ACK);
    setCode(COAP_EMPTY);
    m_buffer[0] &= 0xF0;
    m_msgLen = HEADER_LENGTH;
}

bool CoapMsg::isValid() {
    // check packet size
    if (m_msgLen < 4) {
        TEMBOO_TRACE("Packet must be a minimum of 4 bytes\n");
        return false;
    }
    // check token length
    if (getTokenLen() < 0 || getTokenLen() > 8) {
        TEMBOO_TRACE("Invalid token length\n");
        return false;
    }
    
    int16_t responseClass = m_buffer[1] >> 5;
    // check HTTP Code is between 000-599
    if (responseClass < 0 || responseClass > 5) {
        TEMBOO_TRACE("Invalid code\n");
        return false;
    }
    
    if (HEADER_LENGTH + getTokenLen() == m_msgLen) {
        // nothing else in the packet
        return true;
    }
    
    uint16_t count =0;
    uint16_t lastOption = 0;
    uint16_t optionDelta = 0;
    uint16_t optionLen = 0;
    uint8_t* i = m_buffer + HEADER_LENGTH + getTokenLen();
    // validate options
    while (i < (m_buffer + m_msgLen) && *i != 0xFF) {
        i = decodeOption(i, &optionDelta, &optionLen);
        lastOption += optionDelta;
        if (validateOption((Option)lastOption, i - optionLen, optionLen)) {
            TEMBOO_TRACE("Invalid option\n");
            return false;
        }
    }
    // if payload marker exists, make sure there is payload data
    if (*i == 0xFF && (i - m_buffer) > m_msgLen) {
        return false;
    }
    
    return true;
}
