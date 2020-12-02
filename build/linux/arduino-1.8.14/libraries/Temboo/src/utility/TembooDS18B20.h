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

#ifndef __TEMBOODS18B20__
#define __TEMBOODS18B20__

#include "TembooWebSocketRequestHandles.h"

typedef struct TembooDS18B20Config{
    uint8_t channel[8];
    int pin;
    uint16_t conversionDelayMillis;
    bool parasite;
} TembooDS18B20Config;

void tembooDS18B20Init(TembooDS18B20Config* sensorConfig, TembooSensor* tembooSensor, int pin, int defaultValue);
void tembooDS18B20Begin(void* sensorConfig);
uint8_t* tembooDS18B20GetSensorChannel(void* sensorConfig);
int tembooDS18B20GetSensorPin(void* sensorConfig);
int  tembooDS18B20Read(void* sensorConfig);


#endif /* defined(__TEMBOODS18B20__) */