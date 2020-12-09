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

#ifndef TEMBOOCOAP_H_
#define TEMBOOCOAP_H_

#ifndef TEMBOO_LIBRARY_VERSION
#define TEMBOO_LIBRARY_VERSION 2
#endif

///////////////////////////////////////////////////////
//  BEGIN ARDUINO NON-YUN SUPPORT
///////////////////////////////////////////////////////

#include "Arduino.h"
#include "utility/TembooTimer.h"
#include "utility/TembooTags.h"

#include "utility/TembooCoAPIPStack.h"
#include "utility/ChoreoInputSet.h"
#include "utility/ChoreoInputExpressionSet.h"
#include "utility/ChoreoSensorInputSet.h"
#include "utility/ChoreoOutputSet.h"
#include "utility/ChoreoPreset.h"
#include "utility/ChoreoDevice.h"
#include "utility/CoapMsg.h"
#include "utility/CoapMessageLayer.h"
#include "utility/CoapRRLayer.h"


#define IS_EMPTY(s) (NULL == s || '\0' == *s)
#define DEFAULT_CHOREO_TIMEOUT 900

class TembooCoAPChoreo;

class TembooCoAPClient {
    public:
        TembooCoAPClient(TembooCoAPIPStack& ipStack, IPAddress gatewayAddress, uint16_t gatewayPort = DEFAULT_COAP_PORT);
        virtual ~TembooCoAPClient();
        void begin(long seed);
        
        enum Result {
            NO_ERROR = 0,
            ERROR_REQUEST_FAILED,
            ERROR_BAD_RESPONSE,
            ERROR_MSG_TOKEN,
            ERROR_MSG_OPTION,
            ERROR_MSG_PAYLOAD,
            ERROR_SENDING_MSG,
            ERROR_RECEIVING_MSG,
            ERROR_BUFFER_FULL,
            ERROR_INVALID_MSG,
            ERROR_RECEIVING_RESPONSE
        };
        
        enum State {
            STATE_IDLE,
            STATE_TRANSMIT,
            STATE_WAITING_FOR_RESPONSE,
            STATE_RESPONSE_STARTED,
            STATE_RESPONSE_READY,
            STATE_NO_RESPONSE,
            STATE_SEND_REQUEST,
            STATE_ERROR
        };
        
        Result write(uint8_t value);
        Result write(uint8_t* value, uint16_t len);
        void clearData() {m_dataLen = 0;}
        Result loop();
        Result sendChoreoRequest();
        uint8_t* getPacketBuffer() {return m_respBuffer;}
        int32_t getPacketBufferSize() {return m_respLen;}
        int32_t getPacketLength() {return 1000;}
        int16_t getRespHttpCode() {return m_respHttpCode;}
        State getState() {return m_state;}
        Result sendBlockRequest(uint16_t msgID, uint32_t blockNum);
        void resetChoreo();
        int getMessageState() {return m_lastResult;}
        Result requestTime(uint16_t msgID);
        
    protected:
        static const char URI_PATH[];
        Result m_lastResult;
        bool moreBlocksToSend();
        
        // MAX_BLOCK_SIZE *MUST* be one of the standard CoAP block sizes
        // This size should be set with consideration to any network or
        // hardware limitations on UDP packet size.
        // (16, 32, 64, 128, 256, 512, or 1024).
        static const int MAX_BLOCK_SIZE = 64;
        
        // MAX_PACKET_SIZE should be at least big enough to hold:
        // for outgoing requests:
        // 4 header bytes
        // 6 token bytes (in our case,  Spec says tokens can be up to 8 bytes).
        // 1 byte for the URI PATH option (I *think*)
        // 4 strlen(URI_PATH) bytes for the URI PATH option value.
        // 3 bytes for a block1 option
        // 3 bytes for a block1 option value
        // 1 bytes for a block2 option (early response size negotiation)
        // 1 bytes for a block2 option value
        // ? 5 bytes for a size1 or size2 option
        // ? 4 bytes for a sizeX option value
        // 1 byte for the FF payload marker
        // MAX_BLOCK_SIZE for the payload
        //
        // or 24 + MAX_BLOCK_SIZE
        //
        // HOWEVER... we need to consider the possibility that the server may
        // use more options and thus send more bytes.  So we should add as much
        // extra space as we can reasonably afford so as to avoid buffer overflows.
        
        static const size_t MAX_PACKET_SIZE = 90;
        
        
        static const size_t MAX_DATA_SIZE = 1000;
        
        static const uint16_t DEFAULT_COAP_PORT = 5683;
        
        CoapMessageLayer m_messageLayer;
        CoapRRLayer m_rrLayer;
        IPAddress m_gatewayAddress;
        uint16_t m_gatewayPort;
        uint16_t m_messageID;
        State m_state;
        uint16_t m_blockSize;
        Result m_lastError;
        
        uint16_t m_dataLen;
        uint8_t m_dataBuffer[MAX_DATA_SIZE];
        uint8_t m_respBuffer[MAX_DATA_SIZE];
        
        char m_token[9];
        uint8_t m_txBuffer[MAX_PACKET_SIZE];
        uint8_t m_rxBuffer[MAX_PACKET_SIZE];
        uint32_t m_rxBlockNum;
        int32_t m_txIndex;
        int32_t m_txByteCount;
        int32_t m_respLen;
        uint32_t m_txBlockNum;
        int16_t m_respHttpCode;
        
        Result generateToken();
        uint16_t getNextMessageID();
        
        Result sendBlock(uint16_t msgID, uint8_t* payload, size_t len, uint32_t blockNum, bool moreBlocks);
        void adjustRequestBlockSize(CoapMsg& msg);
        void cancelWait();
        
        int send(CoapMsg* msg);
        int sendResetMsg(CoapMsg& msg);
        int sendEmptyAckMsg(CoapMsg& msg);
        int sendBlock2AckMsg(CoapMsg& msg);
        bool isMsgResponse(CoapMsg& msg);
        void handleBlockAck(CoapMsg& msg);
        void handleBlock1InResponse(CoapMsg& msg);
        Result saveResponse(uint8_t* values, uint16_t len);
        
        friend class TembooCoAPChoreo;
};

class TembooCoAPChoreo : public Stream {
    public:
        
        // Constructor.
        // client - an instance of a TembooCoAPClient.
        //          Used to communicate with a Temboo CoAP Gateway.
        TembooCoAPChoreo(TembooCoAPClient& client);
        ~TembooCoAPChoreo();
        
        // Does nothing. Just for source compatibility with Yun code.
        void begin() {;};
        
        // Sets the account name to use when communicating with Temboo.
        // (required)
        void setAccountName(const String& accountName);
        void setAccountName(const char* accountName);
        
        // Sets the application key name to use with choreo execution requests.
        // (required)
        void setAppKeyName(const String& appKeyName);
        void setAppKeyName(const char* appKeyName);
        
        // Sets the application key value to use with choreo execution requests
        // (required)
        void setAppKey(const String& appKey);
        void setAppKey(const char* appKey);
        
        // sets the name of the choreo to be executed.
        // (required)
        void setChoreo(const String& choreoPath);
        void setChoreo(const char* choreoPath);
        
        
        // sets the name of the saved inputs to use when executing the choreo
        // (optional)
        void setSavedInputs(const String& savedInputsName);
        void setSavedInputs(const char* savedInputsName);
        
        void setCredential(const String& credentialName);
        void setCredential(const char* credentialName);
        
        void setProfile(const String& profileName);
        void setProfile(const char* profileName);
        
        // sets an input to be used when executing a choreo.
        // (optional or required, depending on the choreo being executed.)
        void addInput(const String& inputName, const String& inputValue);
        void addInput(const char* inputName, const char* inputValue);
        void addInput(const char* inputName, const String& inputValue);
        void addInput(const String& inputName, const char* inputValue);
        
        // sets an output filter to be used to process the choreo output
        // (optional)
        void addOutputFilter(const char* filterName, const char* filterPath, const char* variableName);
        void addOutputFilter(const String& filterName, const char* filterPath, const char* variableName);
        void addOutputFilter(const char* filterName, const String& filterPath, const char* variableName);
        void addOutputFilter(const String& filterName, const String& filterPath, const char* variableName);
        void addOutputFilter(const char* filterName, const char* filterPath, const String& variableName);
        void addOutputFilter(const String& filterName, const char* filterPath, const String& variableName);
        void addOutputFilter(const char* filterName, const String& filterPath, const String& variableName);
        void addOutputFilter(const String& filterName, const String& filterPath, const String& variableName);
        
        // run the choreo using the current input info
        int run(uint16_t timeoutSecs = DEFAULT_CHOREO_TIMEOUT);
        
        char* getResponseData() {return m_respData;}
        char* getHTTPResponseCode() {return m_httpCodeStr;}
        
        
        // Stream interface
        void close() {};
        int available();
        int read();
        int peek();
        void flush();
        
        //Print interface
        size_t write(uint8_t data);
        
        enum Error {
            SUCCESS = 0,
            FAILURE,
            TEMBOO_ERROR_ACCOUNT_MISSING       = 201,
            TEMBOO_ERROR_CHOREO_MISSING        = 203,
            TEMBOO_ERROR_APPKEY_NAME_MISSING   = 205,
            TEMBOO_ERROR_APPKEY_MISSING        = 207,
            TEMBOO_ERROR_HTTP_ERROR            = 223,
            TEMBOO_ERROR_TIMEOUT               = 225,
            TEMBOO_ERROR_MEMORY                = 900,
            TEMBOO_ERROR_TCPIP_CONNECT_FAIL    = 901,
            TEMBOO_ERROR_NO_RESPONSE           = 0xFFFF
        };
        
        
        
    protected:
        static const size_t MAX_RESPONSE_SIZE = 900;
        
        TembooCoAPClient& m_client;
        const char* m_accountName;
        const char* m_appKeyName;
        const char* m_appKeyValue;
        const char* m_path;
        
        ChoreoInputSet m_inputs;
        ChoreoInputExpressionSet m_expressions;
        ChoreoSensorInputSet m_sensors;
        ChoreoOutputSet m_outputs;
        ChoreoPreset m_preset;
        ChoreoDevice m_deviceType;
        ChoreoDevice m_deviceName;
        
        char m_httpCodeStr[4];
        char* m_respData;
        
        uint16_t m_requestId;
        static uint16_t s_nextRequestId;
        
        // variables for the stream interface
        size_t m_availableChars;
        const char* m_nextChar;
        enum State {START,
            HTTP_CODE_PRE,
            HTTP_CODE_VALUE,
            HTTP_CODE_SUF,
            RESP_DATA,
            END};
        State m_nextState;
        
    protected:
        int waitForResponse(TembooTimer& timer);
        uint16_t getRequestId() {return m_requestId;}
};


#endif //TEMBOO_H_
