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

#ifndef __TEMBOOGPIO__
#define __TEMBOOGPIO__

#include "TembooWebSocketRequestHandles.h"

#if defined(__cplusplus)
extern "C" {
#endif

typedef struct TembooGPIOConfig{
    uint8_t* channel;
    int pin;
    int currentValue;
    int mode;
} TembooGPIOConfig;

void tembooGPIOBegin(void* sensorConfig);
uint8_t* tembooGPIOGetSensorChannel(void* sensorConfig);
int tembooGPIOGetSensorPin(void* sensorConfig);

void tembooDigitalGPIOInit(TembooGPIOConfig* sensorConfig, TembooSensor* tembooSensor, int pin, int defaultValue, int mode);
int  tembooDigitalRead(void* sensorConfig);
void tembooDigitalWrite(void* sensorConfig, int val);

void tembooAnalogGPIOInit(TembooGPIOConfig* sensorConfig, TembooSensor* tembooSensor, int pin, int defaultValue, int mode);
int  tembooAnalogRead(void* sensorConfig);
void tembooAnalogWrite(void* sensorConfig, int val);

#if defined(__cplusplus)
}
#endif

#endif /* defined(__TEMBOOGPIO__) */