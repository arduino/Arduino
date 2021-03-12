/*
###############################################################################
#
# Temboo MQTT Edge Device library
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

#ifndef TEMBOOMQTT_H_
#define TEMBOOMQTT_H_

#ifndef TEMBOO_LIBRARY_VERSION
#define TEMBOO_LIBRARY_VERSION 2
#endif

#include <Arduino.h>


///////////////////////////////////////////////////////
//  BEGIN ARDUINO NON-YUN SUPPORT
///////////////////////////////////////////////////////

#include "Arduino.h"
#include "utility/MQTTClient.h"
#include "utility/ArduinoTimer.h"
#include "utility/TembooTags.h"

#include "utility/TembooMQTTIPStack.h"
#include "utility/ChoreoInputSet.h"
#include "utility/ChoreoInputExpressionSet.h"
#include "utility/ChoreoSensorInputSet.h"
#include "utility/ChoreoOutputSet.h"
#include "utility/ChoreoPreset.h"
#include "utility/ChoreoDevice.h"

#define IS_EMPTY(s) (NULL == s || '\0' == *s)

#define TEMBOO_ERROR_OK                   (0)
#define TEMBOO_ERROR_FAILURE              (1)
#define TEMBOO_ERROR_ACCOUNT_MISSING      (201)
#define TEMBOO_ERROR_CHOREO_MISSING       (203)
#define TEMBOO_ERROR_APPKEY_NAME_MISSING  (205)
#define TEMBOO_ERROR_APPKEY_MISSING       (207)
#define TEMBOO_ERROR_HTTP_ERROR           (223)
#define TEMBOO_ERROR_TIMEOUT              (225)
#define TEMBOO_ERROR_MEMORY               (900)
#define TEMBOO_ERROR_TCPIP_CONNECT_FAIL   (901)
#define TEMBOO_ERROR_MQTT_CONNECT_FAIL    (902)
#define TEMBOO_ERROR_MQTT_SUBSCRIBE_FAIL  (903)
#define TEMBOO_ERROR_MQTT_DISCONNECT      (904)
#define TEMBOO_ERROR_DEVICE_ID_MISSING    (905)
/*
 * The data from the MQTT is too large to fit in the buffer.
 * The MQTT read buffer read as much as it could and discarded
 * the rest of the packet data. Increase MAX_MESSAGE_SIZE
 * to read more data in MQTT's readbuf
 */
#define TEMBOO_ERROR_MQTT_BUFFER_OVERFLOW (906)
/*
 * There was more data to be returned in the packet data than could
 * fit in the return buffer. Incease MAX_RESPONSE_SIZE to read more
 * of the packet response
 */
#define TEMBOO_ERROR_MQTT_DATA_TRUNCATED  (907)
#define TEMBOO_ERROR_NO_RESPONSE          (0xFFFF)



static const int MAX_MESSAGE_SIZE = 512;
static const int MAX_RESPONSE_SIZE = 100;
static const int MAX_HANDLERS = 4;
static const int YIELD_TIME_MILLIS = 200;

typedef MQTT::Client<TembooMQTTIPStack, ArduinoTimer, MAX_MESSAGE_SIZE, MAX_HANDLERS> BaseClient;

class TembooMQTTClient : public BaseClient {
    public:  
        TembooMQTTClient(TembooMQTTIPStack& ipStack, unsigned int commandTimeoutMs = 30000 );
        virtual ~TembooMQTTClient();

        using BaseClient::connect;
        int connect(const char* hostname, int port=1883);

        using BaseClient::isConnected;
        bool isConnected();

        int sendChoreoRequest(const char* request, size_t len);
        int setDeviceId(char* id);
        int setDeviceIdFromMac(byte (&mac)[6]);

    protected:
        TembooMQTTIPStack& m_ipStack;
        char* m_deviceId;
        char* m_requestTopic;
        char* m_ackTopic;
        char* m_responseTopic;
        char* m_dataTopic;

        char* strCatNew_P(const char*, const char*);
        void makeTopics();
};

class TembooMQTTSession;

class TembooMQTTChoreo : public Stream {
    public:
        
        // Constructor.
        // client - an instance of a TembooMQTTClient.  
        //          Used to communicate with a Temboo Gateway.
        TembooMQTTChoreo(TembooMQTTClient& client);
        ~TembooMQTTChoreo();

        // Does nothing. Just for source compatibility with Yun code.
        void begin() {}; 

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
        int run(uint16_t timeoutSecs);

        char* getResponseData() {return m_respData;}
        char* getHTTPResponseCode() {return m_httpCodeStr;}


        // Stream interface - see the Arduino library documentation.
        void close() {};
        int available();
        int read();
        int peek();
        void flush();

        //Print interface - see the Arduino library documentation
        size_t write(uint8_t data);


    protected:
        TembooMQTTClient& m_client;
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
        volatile bool m_haveHttpCode;

        uint16_t m_ackCode;
        volatile bool m_haveAckCode;

        char m_respData[MAX_RESPONSE_SIZE+1];
        volatile bool m_haveData;

        uint16_t m_requestId;
        static uint16_t s_nextRequestId;
    
        volatile uint16_t m_packetStatus;
        
        // variables for the stream interface
        size_t m_availableChars;
        const char* m_nextChar;
        enum State {START, HTTP_CODE_PRE, HTTP_CODE_VALUE, HTTP_CODE_SUF, RESP_DATA, END};
        State m_nextState;

    protected:
        uint16_t getRequestId() {return m_requestId;}
        void setAckCode(uint16_t ackCode);
        void setHTTPResponseCode(char* respCode);
        void setResponseData(char* data, size_t len);

        int waitForResponse(volatile bool& var, TembooMQTTSession& session, ArduinoTimer& timer);
        
        friend void handleDataMessage(MQTT::MessageData& md);
        friend void handleResponseMessage(MQTT::MessageData& md);
        friend void handleAckMessage(MQTT::MessageData& md);
        
};


#endif //TEMBOO_H_
