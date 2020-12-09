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

#include <string.h>
#include "ChoreoSensorInputSet.h"

ChoreoSensorInputSet::ChoreoSensorInputSet() {
    m_first = NULL;
}

ChoreoSensorInputSet::~ChoreoSensorInputSet() {
    ChoreoSensorInput* i = m_first;
    ChoreoSensorInput* next = NULL;
    while (i != NULL) {
        next = i->getNext();
        delete i;
        i = next;
    }
}

void ChoreoSensorInputSet::put(const char* name, int value, const char* sensorConversion, const char* rawLow, const char* rawHigh, const char* scaleLow, const char* scaleHigh, const char* calibration) {

    // Haven't set ANY inputs yet?  
    // Just create a new one.
    if (m_first == NULL) {
        m_first = new ChoreoSensorInput(NULL, name, value, sensorConversion, rawLow, rawHigh, scaleLow, scaleHigh, calibration);
    } else {
        // Some inputs already set.
        // See if we already have this input.
        ChoreoSensorInput* last = NULL;
        ChoreoSensorInput* i = m_first;
        while(i != NULL) {
            if (strcmp(i->getName(), name) == 0) {
                // We already have an input with this name.
                // Just update the value.
                i->setValue(value);
                i->setConversion(sensorConversion);
                i->setRawLow(rawLow);
                i->setRawHigh(rawHigh);
                i->setScaleLow(scaleLow);
                i->setScaleHigh(scaleHigh);
                i->setCalibration(calibration);
                break;
            }
            last = i;
            i = i->getNext();
        }

        // We don't have an input with this name
        // So we need to create a new one.
        if (i == NULL) {
            new ChoreoSensorInput(last, name, value, sensorConversion, rawLow, rawHigh, scaleLow, scaleHigh, calibration);
        }
    }
}

const char* ChoreoSensorInputSet::get(const char* name) const {
    ChoreoSensorInput* i = m_first;
    while(i != NULL) {
        if (strcmp(i->getName(), name) == 0) {
            return i->getValue();
        }
        i = i->getNext();
    }
    return NULL;
}

