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

#ifndef COAPMSG_H_
#define COAPMSG_H_

/*
     Byte 0            Byte 1            Byte 2            Byte 3
     MSB          LSB   MSB         LSB   MSB         LSB   MSB         LSB
     0                     1                   2                       3
     0 1 2 3 4 5 6 7   8 9 0 1 2 3 4 5   6 7 8 9 0 1 2 3   4 5 6 7 8 9 0 1
     +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
     |Ver| T |  TKL  | |      Code     | |  MsgID MSB    | |  MsgID LSB    |
     +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+
     |   Token (if any, TKL bytes) ...
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     |   Options (if any) ...
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     |1 1 1 1 1 1 1 1|    Payload (if any) ...
     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 */

#define RESPONSE_CODE(class, detail) ((class << 5) + detail)

class CoapMsg {
    
    public:
        enum Type {
            COAP_CONFIRMABLE     = 0,
            COAP_NON_CONFIRMABLE = 1,
            COAP_ACK             = 2,
            COAP_RESET           = 3
        };
        
        enum Code {
            //REQUEST CODES
            COAP_EMPTY           = 0,
            COAP_GET             = 1,
            COAP_POST            = 2,
            COAP_PUT             = 3,
            COAP_DELETE          = 4,
            
            //RESPONSE CODES
            COAP_CREATED                    = RESPONSE_CODE(2,1),
            COAP_DELETED                    = RESPONSE_CODE(2,2),
            COAP_VALID                      = RESPONSE_CODE(2,3),
            COAP_CHANGED                    = RESPONSE_CODE(2,4),
            COAP_CONTENT                    = RESPONSE_CODE(2,5),
            COAP_CONTINUE                   = RESPONSE_CODE(2,31),
            COAP_BAD_REQUEST                = RESPONSE_CODE(4,0),
            COAP_UNAUTHORIZED               = RESPONSE_CODE(4,1),
            COAP_BAD_OPTION                 = RESPONSE_CODE(4,2),
            COAP_FORBIDDEN                  = RESPONSE_CODE(4,3),
            COAP_NOT_FOUND                  = RESPONSE_CODE(4,4),
            COAP_METHOD_NOT_ALLOWED         = RESPONSE_CODE(4,5),
            COAP_NOT_ACCEPTABLE             = RESPONSE_CODE(4,6),
            COAP_REQUEST_ENTITY_INCOMPLETE  = RESPONSE_CODE(4,8),
            COAP_PRECONDITION_FAILED        = RESPONSE_CODE(4,12),
            COAP_REQUEST_ENTITY_TOO_LARGE   = RESPONSE_CODE(4,13),
            COAP_UNSUPPORTED_CONTENT_FORMAT = RESPONSE_CODE(4,15),
            COAP_INTERNAL_SERVER_ERROR      = RESPONSE_CODE(5,0),
            COAP_NOT_IMPLEMENTED            = RESPONSE_CODE(5,1),
            COAP_BAD_GATEWAY                = RESPONSE_CODE(5,2),
            COAP_SERVICE_UNAVAILABLE        = RESPONSE_CODE(5,3),
            COAP_GATEWAY_TIMEOUT            = RESPONSE_CODE(5,4),
            COAP_PROXYING_NOT_SUPPORTED     = RESPONSE_CODE(5,5)
        };
        
        enum Option {
            COAP_OPTION_IF_MATCH       = 1,
            COAP_OPTION_URI_HOST       = 3,
            COAP_OPTION_ETAG           = 4,
            COAP_OPTION_IF_NONE_MATCH  = 5,
            //TODO:			COAP_OPTION_OBSERVE        = 6,
            COAP_OPTION_URI_PORT       = 7,
            COAP_OPTION_LOCATION_PATH  = 8,
            COAP_OPTION_URI_PATH       = 11,
            COAP_OPTION_CONTENT_FORMAT = 12,
            COAP_OPTION_MAX_AGE        = 14,
            COAP_OPTION_URI_QUERY      = 15,
            COAP_OPTION_ACCEPT         = 17,
            COAP_OPTION_LOCATION_QUERY = 20,
            COAP_OPTION_BLOCK2         = 23,
            COAP_OPTION_BLOCK1         = 27,
            COAP_OPTION_SIZE2          = 28,
            COAP_OPTION_PROXY_URI      = 35,
            COAP_OPTION_PROXY_SCHEME   = 39,
            COAP_OPTION_SIZE1          = 60
        };
        
        enum Result {
            COAP_RESULT_SUCCESS = 0,     // No error.
            COAP_RESULT_TOKEN_NULL,      // Token length > 0 but NULL pointer given for token value.
            COAP_RESULT_TOKEN_LENGTH,    // Illegal token length value (> 8).
            COAP_RESULT_PAYLOAD_NULL,    // Payload length > 0 but NULL pointer given for payload value.
            COAP_RESULT_OPTION_UNKNOWN,  // An unknown option code was specified.
            COAP_RESULT_OPTION_NULL,     // Option length > 0 but NULL pointer given for option value.
            COAP_RESULT_OPTION_LENGTH,   // Illegal length for option specified.
            COAP_RESULT_OPTION_NOT_FOUND,// The requested option was not found in the message.
            COAP_RESULT_BUFFER_OVERRUN,  // Adding data would overrun the packet buffer
            COAP_RESULT_BUILD_ORDER,     // Message build order incorrect.
            COAP_RESULT_INVALID_MSG,     // Received message is malformed or invalid.
            COAP_RESULT_FAILURE          // Operation failed or unspecified error
        };
        
        CoapMsg(uint8_t* buffer, uint16_t bufferLen);
        CoapMsg(uint8_t* buffer, uint16_t bufferLen, uint16_t packetLen);
        
        void setType(CoapMsg::Type msgType);
        CoapMsg::Type getType();
        
        void setId(uint16_t msgId);
        uint16_t getId();
        
        void setCode(CoapMsg::Code code);
        CoapMsg::Code getCode();
        uint16_t getHTTPStatus();
        
        CoapMsg::Result setToken(const uint8_t* token, uint8_t tokenLen);
        uint8_t* getToken();
        uint8_t getTokenLen();
        
        CoapMsg::Result addOption(CoapMsg::Option optionCode, const uint8_t* optionValue, uint16_t optionLen);
        CoapMsg::Result getOption(CoapMsg::Option optionCode, uint16_t index, uint8_t*& optionValue, uint16_t& optionLen);
        uint16_t getOptionCount(CoapMsg::Option optionCode);
        uint16_t getOptionLen(CoapMsg::Option optionCode, uint16_t index);
        uint8_t* getOptionValue(CoapMsg::Option optionCode, uint16_t index);
        
        CoapMsg::Result setPayload(const uint8_t* payload, uint16_t payloadLen);
        uint8_t* getPayload();
        uint16_t getPayloadLen();
        
        uint8_t* getMsgBytes();
        uint16_t getMsgLen();
        
        bool isValid();
        
        uint16_t getBlock1Size();
        uint32_t getBlock1Num();
        bool getBlock1More();
        
        uint16_t getBlock2Size();
        uint32_t getBlock2Num();
        bool getBlock2More();
        
        void convertToReset();
        void convertToEmptyAck();
        
    protected:
        uint8_t* m_buffer;
        uint16_t m_bufferLen;
        uint16_t m_msgLen;
        
        enum BuildState {
            BUILD_BEGIN,
            BUILD_HAVE_TOKEN,
            BUILD_HAVE_OPTIONS,
            BUILD_HAVE_PAYLOAD
        };
        CoapMsg::BuildState m_buildState;
        uint16_t m_lastOptionCode;
        
    protected:
        CoapMsg::Result validateOption(CoapMsg::Option optionCode, const uint8_t* optionValue, uint16_t optionLen);
        CoapMsg::Result validateOptionValue(uint16_t minLen, uint16_t maxLen, const uint8_t* optionValue, uint16_t optionLen);
        uint8_t* decodeOption(uint8_t* buffer, uint16_t* optionDelta, uint16_t* optionLen);
        uint16_t getBlockSize(CoapMsg::Option optionCode);
        uint32_t getBlockNum(CoapMsg::Option optionCode);
        bool getBlockMore(CoapMsg::Option optionCode);
};


#endif //TEMBOOCOAP_H_
