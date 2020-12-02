/*
###############################################################################
#
# Temboo Arduino library
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

#ifndef __TembooWebSocketRequestHandles__
#define __TembooWebSocketRequestHandles__

#include <Arduino.h>

#if defined(__cplusplus)
extern "C" {
#endif

#ifndef MAX_PIN_NUMBER
#define MAX_PIN_NUMBER 256
#endif

#ifndef MAX_PIN_VALUE
#define MAX_PIN_VALUE 255
#endif

typedef enum {
    WS_GET_REQUEST = 0,
    WS_SET_REQUEST,
    WS_DATA_REQUEST,
    WS_MESSAGE_REQUEST,
    WS_RR_REQUEST,
    WS_SESSION_ID_REQUEST,
    WS_REQUEST_ERROR,
    WS_UPDATE_CONNECTED,
    WS_UPDATE_DISCONNECTED,
    WS_NO_MESSAGE,
    WS_INTERVAL_REQUEST
} WSMessageRequest;

typedef struct TembooSensor{
    void* sensorConfig;
    int (*read)(void* sensorConfig);
    void (*write)(void* sensorConfig, int val);
    void (*begin)(void* sensorConfig);
    int (*getSensorPin)(void*sensorConfig);
    uint8_t* (*getSensorChannel)(void*sensorConfig);
    int defaultValue;
} TembooSensor;

typedef TembooSensor TembooActuator;

void addWebSocketPinData(int pin, int pinVal, bool requestResponse);
void updateIntervalTime(int intervalTime);

// Send frame
WSMessageRequest handleResponse(uint8_t* request, TembooSensor** sensors, int sensorTableDepth, bool connectionStatus);
void logTembooDebug(const char *c);
#if defined(__cplusplus)
}
#endif



#endif /* defined(__TembooWebSocketRequestHandles__) */
