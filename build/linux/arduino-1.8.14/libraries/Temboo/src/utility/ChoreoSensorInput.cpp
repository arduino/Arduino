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

#include <stddef.h>
#include "ChoreoSensorInput.h"

ChoreoSensorInput::ChoreoSensorInput(ChoreoSensorInput* prev, const char* name, int value, const char* sensorConversion, const char* rawLow, const char* rawHigh, const char* scaleLow, const char* scaleHigh, const char* calibration) {
	if (prev != NULL) {
        prev->m_next = this;
    } 
    m_next = NULL;
    m_name = name;
    snprintf(m_value, TEMBOO_SENSOR_INPUT_ARRAY_SIZE, "%i",value);
    m_sensorConversion = sensorConversion;
    m_rawLow = rawLow;
    m_rawHigh = rawHigh;
    m_scaleLow = scaleLow;
    m_scaleHigh = scaleHigh;
    m_calibration = calibration;
}
        

