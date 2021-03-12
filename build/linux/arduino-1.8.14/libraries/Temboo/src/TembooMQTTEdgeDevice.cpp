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


///////////////////////////////////////////////////////
//  BEGIN ARDUINO NON-YUN SUPPORT
///////////////////////////////////////////////////////

#include <avr/pgmspace.h>

#include "utility/TembooGlobal.h"
#include "utility/TembooMQTTSession.h"
#include "utility/MQTTPacket.h"

#include "TembooMQTTEdgeDevice.h"

#ifndef UINT16_MAX
#define UINT16_MAX (0xFFFF)
#endif

static const char HTTP_CODE_PREFIX[] PROGMEM = "HTTP_CODE\x0A\x1F";
static const char HTTP_CODE_SUFFIX[] PROGMEM = "\x0A\x1E";

static const char REQUEST_TOPIC_PREFIX[]       PROGMEM = "/temboo/req/";
static const char REQUEST_ACK_TOPIC_PREFIX[]   PROGMEM = "/temboo/ack/";
static const char RESPONSE_TOPIC_PREFIX[]      PROGMEM = "/temboo/resp/";
static const char RESPONSE_DATA_TOPIC_PREFIX[] PROGMEM = "/temboo/resp-data/";

// TIME_TOPIC must NOT be PROGMEM
static const char TIME_TOPIC[] = "/temboo/time";

static TembooMQTTChoreo* volatile g_currentChoreo = NULL;
uint16_t TembooMQTTChoreo::s_nextRequestId = 0;

void handleDataMessage(MQTT::MessageData& md) {

    TEMBOO_TRACE("data: ");

    MQTT::Message& msg = md.message;

    char* c;
    unsigned int count;
    for (c = (char*)msg.payload, count = 0; *c != '\0' && isdigit(*c) && count < msg.payloadlen; c++) {
        count++;
        if (count > 5) {
            TEMBOO_TRACELN(" long");
            return;
        }
    }

    if (count == 0) {
        TEMBOO_TRACELN(" short");
        return;
    }

    if (TAG_VALUE_SEPARATOR != *c) {
        TEMBOO_TRACELN(" bad msg");
        return;
    }

    // Replace the : with \0 so we can use strtoul.
    *c = '\0';

    unsigned long requestId = strtoul((char*)msg.payload, NULL, 10);
    if (UINT16_MAX < requestId) {
        TEMBOO_TRACELN(" bad id");
        return;
    }

    if ((NULL == g_currentChoreo) || (g_currentChoreo->getRequestId() != (uint16_t)requestId)) {
        TEMBOO_TRACE(" stale id: ");
        TEMBOO_TRACELN(requestId);
        return;
    }

    g_currentChoreo->setResponseData(c + 1, msg.payloadlen - strlen((char*)msg.payload) - 1);
    TEMBOO_TRACELN(" ok");

}

bool validateUint16PairMessage(const char* msg) {
    const char* c;
    int count = 0;
    for (c = msg; *c != '\0' && isdigit(*c); c++) {
        count++;
        if (count > 5)
            return false;
    }

    if (count == 0) {
        return false;
    }

    if (TAG_VALUE_SEPARATOR != *c) {
        return false;
    }
    
    c++;
    for (count = 0; *c != '\0' && isdigit(*c); c++) {
        count++;
        if (count > 5) {
            return false;
        }
    }
    if (count == 0) {
        return false;
    }
    return true;
}


void handleResponseMessage(MQTT::MessageData& md) {
    
    TEMBOO_TRACE("resp: ");

    MQTT::Message& msg = md.message;
    
    // Expected max length is 9 (for 65535:599)
    if (msg.payloadlen > 9) {
        TEMBOO_TRACELN("long");
        return;
    }

    if (msg.payloadlen < 3) {
        TEMBOO_TRACELN("short");
        return;
    }

    // Copy the payload and nul terminate it;
    char respStr[10]; 
    memcpy(respStr, msg.payload, msg.payloadlen);
    respStr[msg.payloadlen] = '\0';

    TEMBOO_TRACE(respStr);
    
    if (!validateUint16PairMessage(respStr)) {
        TEMBOO_TRACELN(" bad msg");
        return;
    }
    
    char* next;
    unsigned long respCode = 0;
    unsigned long requestId = strtoul(respStr, &next, 10);
    
    // validate only checks that the request ID 
    // has at least 1 but no more than 6 digits.
    // so we have to check the actual value here.
    if (UINT16_MAX < requestId) {
        TEMBOO_TRACELN(" bad id");
        return;
    }

    // If the request ID in the message doesn't match the
    // current request ID, then it's a stale ack.
    if ((NULL == g_currentChoreo) || (g_currentChoreo->getRequestId() != (uint16_t)requestId)) {
        TEMBOO_TRACE(" stale id: ");
        TEMBOO_TRACELN(respStr);
        return;
    }

    next++;
    respCode = strtoul(next, NULL, 10);

    // Validate only checks that the ack code
    // has at least 1 but no more than 6 digits,
    // so we have to check the actual value here.
    if (1000 <= respCode) {
        TEMBOO_TRACELN(" bad code");
        return;
    }

    // FINALLY, everything's OK. 
    // pass the value to the waiting choreo.
    g_currentChoreo->setHTTPResponseCode(next);
    TEMBOO_TRACELN(" ok");

}


void handleTimeMessage(MQTT::MessageData& md) {
    
    TEMBOO_TRACE("time: ");

    MQTT::Message& msg = md.message;
    
    // Time messages should be <= 10 characters long.
    if (msg.payloadlen > 10) {
        TEMBOO_TRACELN("long");
        return;
    }

    if (msg.payloadlen == 0) {
        TEMBOO_TRACELN("short");
        return;
    }

    // Payload should consist only of digits (0 - 9)
    for (unsigned int i = 0; i < msg.payloadlen; i++) {
        if (! isdigit(((char*)msg.payload)[i])) {
            TEMBOO_TRACELN("!digit");
            return;
        }
    }

    char timeStr[11];
    memcpy(timeStr, msg.payload, msg.payloadlen);
    timeStr[msg.payloadlen] = '\0';

    TEMBOO_TRACE(timeStr);

    uint32_t t = strtoul(timeStr, NULL, 10);
    TembooMQTTSession::setTime(t);

    TEMBOO_TRACELN(" ok");
}

void handleAckMessage(MQTT::MessageData& md) {
    
    TEMBOO_TRACE("ack: ");

    MQTT::Message& msg = md.message;
    
    // Expected max length is 11 (for 65535:65535)
    if (msg.payloadlen > 11) {
        TEMBOO_TRACELN("long");
        return;
    }

    if (msg.payloadlen == 0) {
        TEMBOO_TRACELN("short");
        return;
    }

    // Copy the payload and nul terminate it;
    char ackStr[12]; 
    memcpy(ackStr, msg.payload, msg.payloadlen);
    ackStr[msg.payloadlen] = '\0';

    TEMBOO_TRACE(ackStr);
    
    if (!validateUint16PairMessage(ackStr)) {
        TEMBOO_TRACELN(" bad msg");
        return;
    }
    
    char* next;
    unsigned long ackCode = TEMBOO_ERROR_FAILURE;
    unsigned long requestId = strtoul(ackStr, &next, 10);
    
    // validate only checks that the request ID 
    // has at least 1 but no more than 6 digits.
    // so we have to check the actual value here.
    if (UINT16_MAX < requestId) {
        TEMBOO_TRACELN(" bad id");
        return;
    }

    // If the request ID in the message doesn't match the
    // current request ID, then it's a stale ack.
    if ((NULL == g_currentChoreo) || (g_currentChoreo->getRequestId() != (uint16_t)requestId)) {
        TEMBOO_TRACE(" stale id: ");
        TEMBOO_TRACELN(ackStr);
        return;
    }

    next++;
    ackCode = strtoul(next, NULL, 10);

    // Validate only checks that the ack code
    // has at least 1 but no more than 6 digits,
    // so we have to check the actual value here.
    if (UINT16_MAX < ackCode) {
        TEMBOO_TRACELN(" bad code");
        return;
    }

    // FINALLY, everything's OK. 
    // pass the value to the waiting choreo.
    g_currentChoreo->setAckCode(ackCode);
    TEMBOO_TRACELN(" ok");

}


TembooMQTTClient::TembooMQTTClient(TembooMQTTIPStack& ipStack, unsigned int commandTimeoutMs )
    : BaseClient (ipStack, commandTimeoutMs), 
    m_ipStack(ipStack) {
        m_deviceId = NULL;
        m_requestTopic = NULL;
        m_ackTopic = NULL;
        m_responseTopic = NULL;
        m_dataTopic = NULL;
}

void TembooMQTTClient::makeTopics() {
    m_requestTopic = strCatNew_P(REQUEST_TOPIC_PREFIX, m_deviceId);
    m_ackTopic = strCatNew_P(REQUEST_ACK_TOPIC_PREFIX, m_deviceId);
    m_responseTopic = strCatNew_P(RESPONSE_TOPIC_PREFIX, m_deviceId);
    m_dataTopic = strCatNew_P(RESPONSE_DATA_TOPIC_PREFIX, m_deviceId);
}

int TembooMQTTClient::setDeviceId(char* id) {
    int rc = TEMBOO_ERROR_FAILURE;
    if (NULL == m_deviceId) {
        m_deviceId = new char[strlen(id) + 1];
        if (NULL != m_deviceId) {
            strcpy(m_deviceId, id);
            makeTopics();
            rc = TEMBOO_ERROR_OK;   
        } else {
            rc = TEMBOO_ERROR_MEMORY;
        }
    }
    return rc;
}

int TembooMQTTClient::setDeviceIdFromMac(byte (&mac)[6]) {
    int rc = TEMBOO_ERROR_FAILURE;

    // Only do something if we don't already have a deviceId
    if (NULL == m_deviceId) {
        // generate the deviceId from the MAC address.
        char macStr[13];
        for (unsigned int i = 0; i < sizeof(mac)/sizeof(*mac); i++) {
            byte m = mac[i] >> 4;
            macStr[2 * i] = m < 10 ? ('0' + m):('A' + m - 10);
            m = mac[i] & 0x0F;
            macStr[2 * i + 1] = m < 10 ? ('0' + m):('A' + m - 10);
        }
        macStr[12] = '\0';
        rc = setDeviceId(macStr);
    }
    return rc;
}


char* TembooMQTTClient::strCatNew_P(const char* s1, const char* s2) {
    size_t len = strlen_P(s1) + strlen(s2) + 1;
    char* result = new char[len];
    if (NULL != result) {
        strcpy_P(result, s1);
        strcat(result, s2);
    }
    return result;
}

TembooMQTTClient::~TembooMQTTClient() {
    if (NULL != m_requestTopic) delete[] m_requestTopic;
    if (NULL != m_ackTopic) delete[] m_ackTopic;
    if (NULL != m_responseTopic) delete[] m_responseTopic;
    if (NULL != m_dataTopic) delete[] m_dataTopic;
    if (NULL != m_deviceId) delete[] m_deviceId;
}

int TembooMQTTClient::connect(const char* hostname, int port) {
    int rc = TEMBOO_ERROR_FAILURE;

    if (NULL == m_deviceId) {
        return TEMBOO_ERROR_DEVICE_ID_MISSING;
    } 

    TEMBOO_TRACE("DEVICE ID: ");
    TEMBOO_TRACELN(m_deviceId);

    // Open a socket to the broker.
    TEMBOO_TRACE("IP: ");
    rc = m_ipStack.connect(hostname, port);
    if (1 != rc) {
        TEMBOO_TRACELN(rc);
        rc = TEMBOO_ERROR_TCPIP_CONNECT_FAIL;
        goto ErrorExit;
    } else {
        TEMBOO_TRACELN("OK");

        // Establish an MQTT connection with the broker.
        TEMBOO_TRACE("MQ ");
        TEMBOO_TRACE(m_deviceId);
        TEMBOO_TRACE(": ");
        MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
        data.MQTTVersion = 3;
        data.clientID.cstring = (char*)m_deviceId;
        rc = connect(data);
        if (MQTT::SUCCESS != rc) {
            TEMBOO_TRACELN(rc);
            rc = TEMBOO_ERROR_MQTT_CONNECT_FAIL;
            goto ErrorExit;
        }
        TEMBOO_TRACELN("OK");
    }

    // Subscribe to the various topics we need to monitor.
    //NOTE: 'subscribe()' does NOT copy the topic strings,
    //so those strings must stay valid for the life of the connection.

    TEMBOO_TRACE("SUB:");
    //Yes, it's slightly risky counting on MQTT::SUCCESS always being 0.
    rc = this->subscribe(m_ackTopic, MQTT::QOS1, handleAckMessage);
    rc |= this->subscribe(m_responseTopic, MQTT::QOS1, handleResponseMessage);
    rc |= this->subscribe(m_dataTopic, MQTT::QOS1, handleDataMessage);
    rc |= this->subscribe(TIME_TOPIC, MQTT::QOS1, handleTimeMessage);
    if (MQTT::SUCCESS != rc) {
        TEMBOO_TRACELN("NO");
        rc = TEMBOO_ERROR_MQTT_SUBSCRIBE_FAIL;
        goto ErrorExit;
    }
    TEMBOO_TRACELN("OK");
    
    return TEMBOO_ERROR_OK;

ErrorExit:
    if (isConnected()) {
        disconnect();
    }
    m_ipStack.disconnect();
    return rc;
}

bool TembooMQTTClient::isConnected() {
    if (m_ipStack.isConnected()) {
        return BaseClient::isConnected();
    }
    return false;
}

int TembooMQTTClient::sendChoreoRequest(const char* request, size_t len) {
    MQTT::Message message;

    message.qos = MQTT::QOS0;
    message.retained = false;
    message.dup = false;
    message.payload = (void*)request;
    message.payloadlen = len;
    int rc = this->publish(this->m_requestTopic, message);
    return rc == MQTT::SUCCESS ? TEMBOO_ERROR_OK : rc;
}

TembooMQTTChoreo::TembooMQTTChoreo(TembooMQTTClient& client) : 
    m_client(client), 
    m_accountName(NULL),
    m_appKeyName(NULL),
    m_appKeyValue(NULL),
    m_path(NULL),
    m_haveHttpCode(false),
    m_ackCode(0),
    m_haveAckCode(false),
    m_haveData(false),
    m_requestId(0),
    m_availableChars(0),
    m_nextChar(NULL),
    m_nextState(END),
    m_packetStatus(TEMBOO_ERROR_OK)
{
}

TembooMQTTChoreo::~TembooMQTTChoreo() {
    memset(m_respData, '\0', sizeof(m_respData)/sizeof(m_respData[0]));
}

void TembooMQTTChoreo::setAccountName(const String& accountName) {
    m_accountName = accountName.c_str();
}


void TembooMQTTChoreo::setAccountName(const char* accountName) {
    m_accountName = accountName;
}


void TembooMQTTChoreo::setAppKeyName(const String& appKeyName) {
    m_appKeyName = appKeyName.c_str();
}


void TembooMQTTChoreo::setAppKeyName(const char* appKeyName) {
    m_appKeyName = appKeyName;
}


void TembooMQTTChoreo::setAppKey(const String& appKeyValue) {
    m_appKeyValue = appKeyValue.c_str();
}


void TembooMQTTChoreo::setAppKey(const char* appKeyValue) {
    m_appKeyValue = appKeyValue;
}


void TembooMQTTChoreo::setChoreo(const String& path) {
    m_path = path.c_str();
}


void TembooMQTTChoreo::setChoreo(const char* path) {
    m_path = path;
}


void TembooMQTTChoreo::setSavedInputs(const String& savedInputsName) {
    m_preset.put(savedInputsName.c_str());
}


void TembooMQTTChoreo::setSavedInputs(const char* savedInputsName) {
    m_preset.put(savedInputsName);
}


void TembooMQTTChoreo::setCredential(const String& credentialName) {
    m_preset.put(credentialName.c_str());
}


void TembooMQTTChoreo::setCredential(const char* credentialName) {
    m_preset.put(credentialName);
}

void TembooMQTTChoreo::setProfile(const String& profileName) {
    m_preset.put(profileName.c_str());
}


void TembooMQTTChoreo::setProfile(const char* profileName) {
    m_preset.put(profileName);
}



void TembooMQTTChoreo::addInput(const String& inputName, const String& inputValue) {
    m_inputs.put(inputName.c_str(), inputValue.c_str());
}


void TembooMQTTChoreo::addInput(const char* inputName, const char* inputValue) {
    m_inputs.put(inputName, inputValue);
}


void TembooMQTTChoreo::addInput(const char* inputName, const String& inputValue) {
    m_inputs.put(inputName, inputValue.c_str());
}


void TembooMQTTChoreo::addInput(const String& inputName, const char* inputValue) {
    m_inputs.put(inputName.c_str(), inputValue);
}


void TembooMQTTChoreo::addOutputFilter(const char* outputName, const char* filterPath, const char* variableName) {
    m_outputs.put(outputName, filterPath, variableName);
}


void TembooMQTTChoreo::addOutputFilter(const String& outputName, const char* filterPath, const char* variableName) {
    m_outputs.put(outputName.c_str(), filterPath, variableName);
}


void TembooMQTTChoreo::addOutputFilter(const char* outputName, const String& filterPath, const char* variableName) {
    m_outputs.put(outputName, filterPath.c_str(), variableName);
}


void TembooMQTTChoreo::addOutputFilter(const String& outputName, const String& filterPath, const char* variableName) {
    m_outputs.put(outputName.c_str(), filterPath.c_str(), variableName);
}


void TembooMQTTChoreo::addOutputFilter(const char* outputName, const char* filterPath, const String& variableName) {
    m_outputs.put(outputName, filterPath, variableName.c_str());
}


void TembooMQTTChoreo::addOutputFilter(const String& outputName, const char* filterPath, const String& variableName) {
    m_outputs.put(outputName.c_str(), filterPath, variableName.c_str());
}


void TembooMQTTChoreo::addOutputFilter(const char* outputName, const String& filterPath, const String& variableName) {
    m_outputs.put(outputName, filterPath.c_str(), variableName.c_str());
}


void TembooMQTTChoreo::addOutputFilter(const String& outputName, const String& filterPath, const String& variableName) {
    m_outputs.put(outputName.c_str(), filterPath.c_str(), variableName.c_str());
}

int TembooMQTTChoreo::waitForResponse(volatile bool& var, TembooMQTTSession& session, ArduinoTimer& timer) {
    
    int rc = TEMBOO_ERROR_OK;

    while (!var) {
        if (timer.expired()) {
            rc = TEMBOO_ERROR_TIMEOUT;
            break;
        }

        if (!m_client.isConnected()) {
            TEMBOO_TRACELN("DISCO");
            rc = TEMBOO_ERROR_MQTT_DISCONNECT;
            break;
        }
        m_client.yield(YIELD_TIME_MILLIS);
    }
    return rc;
}

void TembooMQTTChoreo::setHTTPResponseCode(char* respCodeStr) {
    //NOTE: if we run in a true multithreaded environment, this code
    //will have to be synchronized somehow.  Checking the m_haveHttpCode
    //flag is insufficient to prevent race conditions.
    if (!m_haveHttpCode) {
        strncpy(m_httpCodeStr, respCodeStr, sizeof(m_httpCodeStr)-1);
        m_httpCodeStr[sizeof(m_httpCodeStr)-1] = '\0';
        m_haveHttpCode = true;
    }
}

void TembooMQTTChoreo::setResponseData(char* payload, size_t payloadLen) {

    //NOTE: if we run in a true multithreaded environment, this code
    //will have to be synchronized somehow.  Checking the m_haveData 
    //flag is insufficient to prevent race conditions.
    if (!m_haveData) {
        size_t len = 0;
        if(payloadLen > MAX_MESSAGE_SIZE) {
            m_packetStatus = TEMBOO_ERROR_MQTT_BUFFER_OVERFLOW;
            len = sizeof(m_respData)/sizeof(m_respData[0])-1;
        } else if (payloadLen > MAX_RESPONSE_SIZE) {
            m_packetStatus = TEMBOO_ERROR_MQTT_DATA_TRUNCATED;
            len = sizeof(m_respData)/sizeof(m_respData[0])-1;
        } else {
            len = payloadLen;
        }
        memcpy(m_respData, payload, len);
        m_respData[len] = '\0';
        m_haveData = true;
    }
}

void TembooMQTTChoreo::setAckCode(uint16_t ackCode) {
    //NOTE: if we run in a true multithreaded environment, this code
    //will have to be synchronized somehow.  Checking the m_haveAckCode 
    //flag is insufficient to prevent race conditions.
    if (!m_haveAckCode) {
        m_ackCode = ackCode;
        m_haveAckCode = true;
    }
}

int TembooMQTTChoreo::run(uint16_t timeoutSecs) {
    m_nextChar = NULL;

    if (!m_client.isConnected()) {
        return TEMBOO_ERROR_MQTT_DISCONNECT;
    }

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

    m_packetStatus = TEMBOO_ERROR_OK;
    
    TembooMQTTSession session(m_client);
    m_requestId = s_nextRequestId++;
    
    m_haveAckCode = false;
    m_ackCode = TEMBOO_ERROR_NO_RESPONSE;
 
    m_haveHttpCode = false;
    memset(m_httpCodeStr, '\0', sizeof(m_httpCodeStr)/sizeof(m_httpCodeStr[0]));
    
    m_haveData = false;
    memset(m_respData, '\0', sizeof(m_respData)/sizeof(m_respData[0]));

    m_availableChars = 0;
    m_nextState = START;
    g_currentChoreo = this;

    TEMBOO_TRACE("RUN ");
    TEMBOO_TRACE(m_requestId);
    TEMBOO_TRACELN(" START");

    ArduinoTimer timer(timeoutSecs * 1000L);

    int rc = session.executeChoreo( m_requestId, m_accountName, m_appKeyName, m_appKeyValue, m_path, m_inputs, m_expressions, m_sensors, m_outputs, m_preset, m_deviceType, m_deviceName);
    if (TEMBOO_ERROR_OK != rc) {
        goto ErrorExit;
    }

    rc = waitForResponse(m_haveAckCode, session, timer);
    if (TEMBOO_ERROR_OK != rc){
        goto ErrorExit;
    }

    TEMBOO_TRACE("RUN ");
    TEMBOO_TRACE(m_requestId);
    TEMBOO_TRACE(" ACK: ");
    TEMBOO_TRACELN(m_ackCode);

    if (TEMBOO_ERROR_OK != m_ackCode) {
        rc = m_ackCode;
        goto ErrorExit;
    }

    rc = waitForResponse(m_haveHttpCode, session, timer);
    if (TEMBOO_ERROR_OK != rc) {
        goto ErrorExit;
    }

    TEMBOO_TRACE("RUN ");
    TEMBOO_TRACE(m_requestId);
    TEMBOO_TRACE(" RESP: ");
    TEMBOO_TRACELN(m_httpCodeStr);

    rc = waitForResponse(m_haveData, session, timer);
    if (TEMBOO_ERROR_OK != rc) {
        goto ErrorExit;
    }
    m_availableChars = strlen(m_respData) + strlen(m_httpCodeStr) + strlen_P(HTTP_CODE_PREFIX) + strlen_P(HTTP_CODE_SUFFIX);
    
    m_nextChar = HTTP_CODE_PREFIX;

    TEMBOO_TRACE("RUN ");
    TEMBOO_TRACE(m_requestId);
    TEMBOO_TRACE(" ");
    TEMBOO_TRACE(m_availableChars);
    TEMBOO_TRACELN(" CHARS");
    TEMBOO_TRACELN(m_respData);

    rc = m_packetStatus;

ErrorExit:
    if (TEMBOO_ERROR_OK != rc) {
        TEMBOO_TRACE("RUN ");
        TEMBOO_TRACE(m_requestId);
        TEMBOO_TRACE(" ERROR:");
        TEMBOO_TRACELN(rc);
    }
    g_currentChoreo = NULL;
    m_client.yield(YIELD_TIME_MILLIS);
    return rc;
}


int TembooMQTTChoreo::available() {
    return m_availableChars;
}


int TembooMQTTChoreo::peek() {
    if (m_availableChars) {
        if (m_nextState == HTTP_CODE_VALUE || m_nextState == RESP_DATA || m_nextState == END) {
            return (int)*m_nextChar;
        } else {
            return (int)pgm_read_byte(m_nextChar);
        }
    } else {
        return -1;
    }
}


int TembooMQTTChoreo::read() {

    if (m_haveData) {
        int c = 0;
        switch(m_nextState) {
            case START:
                m_nextChar = HTTP_CODE_PREFIX;
                c = (int)pgm_read_byte(m_nextChar++);
                m_nextState = HTTP_CODE_PRE;
                break;

            case HTTP_CODE_PRE:
                c = (int)pgm_read_byte(m_nextChar++);
                if (pgm_read_byte(m_nextChar) == '\0') {
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
                c = (int)pgm_read_byte(m_nextChar++);
                if (pgm_read_byte(m_nextChar) == '\0') {
                    m_nextState = RESP_DATA;
                    m_nextChar = m_respData;
                }
                break;

            case RESP_DATA:
                c = (int)(*m_nextChar++);
                if ((m_availableChars - 1) <= 0) {
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


size_t TembooMQTTChoreo::write(uint8_t data) {
    return 0;
}


void TembooMQTTChoreo::flush() {
    m_nextChar = NULL;
    m_nextState = END;
    m_availableChars = 0;
}

