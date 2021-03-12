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

#include <string.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "TembooCoAPSession.h"
#include "tmbhmac.h"
#include "DataFormatter.h"
#include "TembooTags.h"

#define QSEND(x)    if(!qsend((x)))           { goto SendFailed;}

const size_t MAX_HOST_LEN = 64;
const size_t MAX_URL_PATH_LEN = 100;

const char EOL[]                     = "\r\n";
const char POST[]                    = "POST ";
const char POSTAMBLE[]               = " HTTP/1.0"; // Prevent host from using chunked encoding in response.
const char HEADER_HOST[]             = "Host: ";
const char HEADER_ACCEPT[]           = "Accept: application/xml";
const char HEADER_ORG[]              = "x-temboo-domain: /";
const char HEADER_DOM[]              = "/master";
const char HEADER_CONTENT_LENGTH[]   = "Content-Length: ";
const char HEADER_TIME[]             = "x-temboo-time: ";
const char BASE_CHOREO_URI[]         = "/arcturus-web/api-1.0/ar";
const char HEADER_AUTH[]             = "x-temboo-authentication: ";
const char HEADER_CONTENT_TYPE[]     = "Content-Type: text/plain";
const char TEMBOO_DOMAIN[]           = ".temboolive.com";
const char SDK_ID[]                  = "?source_id=CoAPGateway_1";


unsigned long TembooCoAPSession::s_timeOffset = 0;

TembooCoAPSession::TembooCoAPSession(TembooCoAPClient& client) : m_client(client) {
}


void TembooCoAPSession::setTime(unsigned long currentTime) {
    s_timeOffset = currentTime - (millis()/1000);
}


unsigned long TembooCoAPSession::getTime() {
    return s_timeOffset + (millis()/1000);
}



int TembooCoAPSession::executeChoreo(
                                     uint16_t requestId,
                                     const char* accountName,
                                     const char* appKeyName,
                                     const char* appKeyValue,
                                     const char* path,
                                     const ChoreoInputSet& inputSet, 
                                     const ChoreoInputExpressionSet& expressionSet,
                                     const ChoreoSensorInputSet& sensorSet,
                                     const ChoreoOutputSet& outputSet, 
                                     const ChoreoPreset& preset,
                                     const ChoreoDevice& deviceType,
                                     const ChoreoDevice& deviceName){
    
    DataFormatter fmt(&inputSet, &expressionSet, &sensorSet,&outputSet, &preset, &deviceType, &deviceName);
    char auth[HMAC_HEX_SIZE_BYTES + 1];
    char timeStr[11];
    char requestIdStr[5];
    uint16toa(requestId, requestIdStr);
    
    // We use the current time-of-day as salt on the app key.
    // We keep track of time-of-day by getting the current time
    // from the server and applying an offset (the length of time
    // we've been running.)
    uint32toa((uint32_t)TembooCoAPSession::getTime(), timeStr);
    
    getAuth(fmt, appKeyValue, timeStr, auth);
    
    m_client.clearData();
    
    QSEND(TAG_REQUEST_ID);
    QSEND(requestIdStr);
    
    QSEND(TAG_ELEMENT_SEPARATOR);
    
    QSEND(TAG_ACCOUNT_NAME);
    QSEND(accountName);
    
    QSEND(TAG_ELEMENT_SEPARATOR);
    
    QSEND(TAG_APP_KEY_NAME);
    QSEND(appKeyName);
    
    QSEND(TAG_ELEMENT_SEPARATOR);
    
    QSEND(TAG_TIME);
    QSEND(timeStr);
    
    QSEND(TAG_ELEMENT_SEPARATOR);
    
    QSEND(TAG_AUTH);
    QSEND(auth);
    
    QSEND(TAG_ELEMENT_SEPARATOR);
    
    QSEND(TAG_CHOREO_ID);
    QSEND(path);
    
    QSEND(TAG_ELEMENT_SEPARATOR);
    
    QSEND(TAG_DATA);
    fmt.reset();
    while(fmt.hasNext()) {
        QSEND(fmt.next());
    }
    
    QSEND(TAG_END_REQUEST);
    
    return m_client.sendChoreoRequest();
    
SendFailed:
    TEMBOO_TRACELN("FAIL");
    return FAILURE;
    
}

uint16_t TembooCoAPSession::getAuth(DataFormatter& fmt, const char* appKeyValue, const char* salt, char* result) const {
    
    // We need the length of the data for other things, and
    // this method is a convenient place to calculate it.
    uint16_t len = 0;
    
    HMAC hmac;
    
    //combine the salt and the key and give it to the HMAC calculator
    size_t keyLength = strlen(appKeyValue) + strlen(salt);
    char key[keyLength + 1];
    strcpy(key, salt);
    strcat(key, appKeyValue);
    hmac.init((uint8_t*)key, keyLength);
    
    // process the data a block at a time.
    uint8_t buffer[HMAC_BLOCK_SIZE_BYTES];
    int blockCount = 0;
    fmt.reset();
    while(fmt.hasNext()) {
        uint8_t c = fmt.next();
        len++;
        buffer[blockCount++] = c;
        if (blockCount == HMAC_BLOCK_SIZE_BYTES) {
            hmac.process(buffer, blockCount);
            blockCount = 0;
        }
    }
    hmac.process(buffer, blockCount);
    
    // Finalize the HMAC calculation and store the (ASCII HEX) value in *result.
    hmac.finishHex(result);
    
    // Return the number of characters processed.
    return len;
}


bool TembooCoAPSession::qsend(const char* s) {
    char c = *s++;
    bool rc = true;
    while(c != '\0' && rc) {
        rc = qsend(c);
        c = *s++;
    }
    return rc;
}


bool TembooCoAPSession::qsend(char c) {
    // Never send a nul character.
    if ('\0' != c) {
        if (TembooCoAPClient::NO_ERROR == m_client.write(c)) {
            return true;
        }
    }
    return false;
}

