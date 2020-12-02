/*
###############################################################################
#
# Temboo library
#
# Copyright 2017, Temboo Inc.
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

#include <ctype.h>

#include "TembooWebSocketRequestHandles.h"
#include "TembooGlobal.h"

static WSMessageRequest handleMessageRequest(char** saveptr);
static WSMessageRequest handleIntervalRequest(char** saveptr);
static WSMessageRequest handleSetRequest(char** saveptr, TembooSensor** sensorTable, int sensorTableDepth);
static WSMessageRequest handleGetRequest(char** saveptr, TembooSensor** sensorTable, int sensorTableDepth);
static WSMessageRequest handleMonitoringUpdateRequest(char**saveptr);

static const uint16_t WS_MAX_PAYLOAD_SIZE = 126;



WSMessageRequest handleGetRequest(char** saveptr, TembooSensor** sensorTable, int sensorTableDepth) {
    char* textField = strtok_r(NULL, "|", &(*saveptr));
    int pinNum = -1;
    int pinVal = -1;
    WSMessageRequest rc = WS_REQUEST_ERROR;
    // strlen should catch the + sign
    while (textField != NULL && strlen(textField) >= 2) {
        if (*textField == 'P') {
            // if pinNum is already set, then an extra pin number
            // has been added to the request incorrectly
            if (pinNum != -1) {
                logTembooDebug("Invalid Get request\n");
                return WS_REQUEST_ERROR;
            }
            size_t i = 0;
            // make sure the pin value is made of digits
            while (i < strlen(&textField[1])) {
                if (isdigit(textField[1 + i++]) == 0) {
                    logTembooDebug(("Invalid pin number\n"));
                    return WS_REQUEST_ERROR;
                }
            }
            pinNum = atoi(&textField[1]);
            // make sure pin number is valid, set to -1 if error
            if (pinNum > MAX_PIN_NUMBER) {
                logTembooDebug(("Invalid pin number\n"));
                pinNum = -1;
            }
        } else if (*textField == '+') {
            break;
        } else {
            logTembooDebug("Invalid message key\n");
            return WS_REQUEST_ERROR;
        }
        textField = strtok_r(NULL, "|", &(*saveptr));
    }
    
    if (pinNum >= 0) {
        //obtain the data and send to Temboo
        int i = 0;
        for (i = 0; i < sensorTableDepth; i++) {
            if (sensorTable[i]->getSensorPin(sensorTable[i]->sensorConfig) == pinNum) {
                pinVal = sensorTable[i]->read(sensorTable[i]->sensorConfig);
                rc = WS_GET_REQUEST;
                break;
            }
        }
    }
    if (rc != WS_REQUEST_ERROR) {
        // Send pinVal
        addWebSocketPinData(pinNum, pinVal, true);
    }
    return rc;
}

WSMessageRequest handleSetRequest(char** saveptr, TembooSensor** sensorTable, int sensorTableDepth) {
    int pinNum = -1;
    int pinVal = -1;
    bool pinValSet = false;
    WSMessageRequest rc = WS_REQUEST_ERROR;
    char* textField = strtok_r(NULL, "|", &(*saveptr));
    while (textField != NULL && strlen(textField) >= 2) {
        if (*textField == 'P') {
            // if pinNum is already set, then an extra pin number
            // has been added to the request incorrectly
            if (pinNum != -1) {
                logTembooDebug("Invalid Set request\n");
                return WS_REQUEST_ERROR;
            }
            size_t i = 0;
            // make sure the pin value is made of digits
            while (i < strlen(&textField[1])) {
                if (isdigit(textField[1 + i++]) == 0) {
                    logTembooDebug(("Invalid pin number\n"));
                    return WS_REQUEST_ERROR;
                }
            }
            pinNum = atoi(&textField[1]);
            // make sure pin number is valid, set to -1 if error
            if (pinNum > MAX_PIN_NUMBER) {
                logTembooDebug(("Invalid pin number\n"));
                return WS_REQUEST_ERROR;
            }
        } else if (*textField == 'V') {
            // if pinVal is already set, then an extra pin value
            // has been added to the request incorrectly
            if (pinValSet) {
                logTembooDebug("Invalid Set request\n");
                return WS_REQUEST_ERROR;
            }
            size_t i = 0;
            // make sure the pin value is made of digits
            while (i < strlen(&textField[1])) {
                if (isdigit(textField[1 + i++]) == 0) {
                    logTembooDebug(("Invalid pin value\n"));
                    return WS_REQUEST_ERROR;
                }
            }
            pinVal = atoi(&textField[1]);
            // make sure pin value is valid, pinValSet will remain false
            if (pinVal > MAX_PIN_VALUE) {
                logTembooDebug(("Invalid pin value\n"));
                return WS_REQUEST_ERROR;
            } else {
                pinValSet = true;
            }
            
        } else if (*textField == '+') {
            break;
        } else {
            logTembooDebug("Invalid message key\n");
            return WS_REQUEST_ERROR;
        }
        textField = strtok_r(NULL, "|", &(*saveptr));
    }
    
    if (pinNum >= 0 &&  pinValSet) {
        int i = 0;
        for (; i < sensorTableDepth; i++) {
            if (sensorTable[i]->getSensorPin(sensorTable[i]->sensorConfig) == pinNum) {
                if (sensorTable[i]->write != NULL) {
                    sensorTable[i]->write(sensorTable[i]->sensorConfig, pinVal);
                    rc = WS_SET_REQUEST;
                }
                break;
            }
        }
    }
    if (rc != WS_REQUEST_ERROR) {
        // with pinval found, send the data to Temboo
        addWebSocketPinData(pinNum, pinVal, true);
    }
    return rc;
}

// Parse out the error message while ignoring escaped characters.
// This functions acts like strstr where it will move saveptr
// to the index past the delimeter ('|' in this case), add '\0'
// where the delimeter is, and return the pointer of the error message
char* getErrorMessage(char** saveptr) {
    if (saveptr == NULL || *saveptr == NULL) {
        return NULL;
    }
    char* tok = *saveptr;
    size_t len = strlen(*saveptr);
    (*saveptr)++;
    if (**saveptr == '\0') {
        return NULL;
    }
    while (**saveptr != '\0') {
        // check for delimiter
        if (**saveptr == '\\') {
            // check if we're escaping a special character
            switch (*(*saveptr+1)) {
                case '+':
                case '|':
                case '\\':
                    // shift string over 1 and increment
                    memmove(*saveptr,*saveptr+1, --len);
                    (*saveptr)++;
                    break;
                default:
                    // increment pointer and decrement str length
                    (*saveptr)++;
                    len--;
                    break;
            }
        } else if (**saveptr == '|') {
            // end of message
            **saveptr = '\0';
            (*saveptr)++;
            return tok;
        } else {
            // increment pointer and decrement str length
            (*saveptr)++;
            len--;
        }
    }
    // return string when if the end of the text is found
    return tok;
}

WSMessageRequest handleMessageRequest(char** saveptr) {
    char* textField = getErrorMessage(&(*saveptr));
    WSMessageRequest rc = WS_REQUEST_ERROR;
    if (textField != NULL && strlen(textField) >= 2) {
        if (*textField == 'T') {
            logTembooDebug(&textField[1]);
            rc = WS_MESSAGE_REQUEST;
        }
    }
    return rc;
}

WSMessageRequest handleMonitoringUpdateRequest(char** saveptr) {
    char* textField = strtok_r(NULL, "|", &(*saveptr));
    WSMessageRequest rc = WS_REQUEST_ERROR;
    if (textField != NULL && strlen(textField) >= 2) {
        if (*textField == 'T') {
            if (!strcmp(&textField[1], "true")) {
                rc = WS_UPDATE_CONNECTED;
            } else if (!strcmp(&textField[1], "false")) {
                rc = WS_UPDATE_DISCONNECTED;
            } else {
                rc = WS_REQUEST_ERROR;
            }
        }
    }
    return rc;
}

WSMessageRequest handleIntervalRequest(char** saveptr) {
    char* textField = strtok_r(NULL, "|", &(*saveptr));
    WSMessageRequest rc = WS_REQUEST_ERROR;
    if (textField != NULL && strlen(textField) >= 2) {
        if (*textField == 'V') {
            if (isdigit(textField[1]) && strlen(&textField[1]) < 6) {
               updateIntervalTime(atoi(&textField[1]));
               rc = WS_INTERVAL_REQUEST;
            }
        }
    }
    return rc;
}

WSMessageRequest handleResponse(uint8_t* request, TembooSensor** sensorTable, int sensorTableDepth, bool connectionStatus) {
    // parse response to find request type
    char* saveptr = NULL;
    char* requestField = strtok_r((char*)request, "|", &saveptr);
    WSMessageRequest rc = WS_REQUEST_ERROR;
    while (requestField != NULL) {
        if (*requestField == 'M') {
            switch (requestField[1]) {
                // only read web socket messages if device is connected
                // to the web socket
                case 'G':
                    // send pin data to Temboo
                    if (connectionStatus) {
                        rc = handleGetRequest(&saveptr, sensorTable, sensorTableDepth);
                    }
                    break;
                case 'S':
                    // change state of a pin
                    if (connectionStatus) {
                        rc = handleSetRequest(&saveptr, sensorTable, sensorTableDepth);
                    }
                    break;
                case 'E':
                    // print message
                    rc = handleMessageRequest(&saveptr);
                    break;
                case 'U':
                    rc = handleMonitoringUpdateRequest(&saveptr);
                    break;
                case 'I':
                    rc = handleIntervalRequest(&saveptr);
                    break;
                default:
                    // return error
                    rc = WS_REQUEST_ERROR;
                    break;
            }
        }
        if (rc == WS_REQUEST_ERROR) {
            break;
        }
        requestField = strtok_r(NULL, "|", &saveptr);
    }
    return rc;
}
