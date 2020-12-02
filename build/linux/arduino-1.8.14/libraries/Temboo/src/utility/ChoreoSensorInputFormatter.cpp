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
#include <avr/pgmspace.h>
#include "ChoreoSensorInputFormatter.h"
#include "ChoreoSensorInputSet.h"

static const char TAG_INPUTS_START[] PROGMEM = "\"sensorInputs\":{";
static const char TAG_SENSOR_NAME_SEPERATOR[] PROGMEM = "\":{";
static const char TAG_VALUE_START[] PROGMEM = "\"value\":";
static const char TAG_CALIBRATION_START[] PROGMEM = ",\"calibration\":";
static const char TAG_RAW_LOW_START[] PROGMEM = ",\"rawLow\":";
static const char TAG_RAW_HIGH_START[] PROGMEM = ",\"rawHigh\":";
static const char TAG_SCALE_LOW_START[] PROGMEM = ",\"scaleLow\":";
static const char TAG_SCALE_HIGH_START[] PROGMEM = ",\"scaleHigh\":";
static const char TAG_CONVERSION_START[] PROGMEM = ",\"conversion\":";

ChoreoSensorInputFormatter::ChoreoSensorInputFormatter(const ChoreoSensorInputSet* inputSet) {
    m_inputSet = inputSet;
    reset();
}

void ChoreoSensorInputFormatter::reset() {
    m_currentInput = NULL;
    m_nextChar = NULL;
    if (m_inputSet == NULL || m_inputSet->isEmpty()) {
        m_nextState = END;
    } else {
        m_nextState = START;
    }
}

bool ChoreoSensorInputFormatter::hasNext() {
    return m_nextState != END;
}

char ChoreoSensorInputFormatter::next() {
    char c;
    switch(m_nextState) {
        case START:
            c = readStartTagChar(TAG_INPUTS_START, SENSOR_INPUT_TAG);
            break;
            
        case SENSOR_INPUT_TAG:
            c = readTagChar(SENSOR_NAME_START);
            if (m_nextState == SENSOR_NAME_START) {
                m_currentInput= m_inputSet->getFirstInput();
            }
            break;
            
        case SENSOR_NAME_START:
            c = '"';
            m_nextChar = m_currentInput->getName();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = SENSOR_NAME_END;
            } else {
                m_nextState = SENSOR_NAME;
            }
            break;
            
        case SENSOR_NAME:
            c = readValueChar(SENSOR_NAME_END);
            break;
            
        case SENSOR_NAME_END:
            c = readStartTagChar(TAG_SENSOR_NAME_SEPERATOR, SENSOR_NAME_SEPERATOR);
            break;
            
        case SENSOR_NAME_SEPERATOR:
            c = readTagChar(VALUE_TAG);
            if (m_nextState == VALUE_TAG) {
                m_nextChar= TAG_VALUE_START;
            }
            break;
            
        case VALUE_TAG:
            c = readTagChar(VALUE_START);
            break;
            
        case VALUE_START:
            c = '"';
            m_nextChar = m_currentInput->getValue();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = VALUE_END;
            } else {
                m_nextState = VALUE;
            }
            break;
            
        case VALUE:
            c = readValueChar(VALUE_END);
            break;
            
        case VALUE_END:
            c = '"';
            // decide how the data set should be set up, with just the value, with
            // a conversion, or with the user defined scale
            if (m_currentInput->getCalibration() != NULL) {
                m_nextChar = TAG_CALIBRATION_START;
                m_nextState = CALIBRATION_TAG;
            } else {
                if (m_currentInput->getConversion() != NULL) {
                    // use conversion
                    m_nextState = CONVERSION_TAG;
                    m_nextChar = TAG_CONVERSION_START;
                } else if (m_currentInput->getScaleHigh() != m_currentInput->getScaleLow()) {
                    // use user defined scale
                    m_nextState = RAW_LOW_TAG;
                    m_nextChar = TAG_RAW_LOW_START;
                } else {
                    // just the value is needed
                    m_nextState = DATA_SET_END;
                }
            }
            break;
            
        case CALIBRATION_TAG:
            c = readTagChar(CALIBRATION_START);
            break;
            
        case CALIBRATION_START:
            c = '"';
            m_nextChar = m_currentInput->getCalibration();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = CALIBRATION_END;
            } else {
                m_nextState = CALIBRATION;
            }
            break;
            
        case CALIBRATION:
            c = readValueChar(CALIBRATION_END);
            break;
            
        case CALIBRATION_END:
            c = '"';
            if (m_currentInput->getConversion() != NULL) {
                // use conversion
                m_nextState = CONVERSION_TAG;
                m_nextChar = TAG_CONVERSION_START;
            } else if (m_currentInput->getScaleHigh() != m_currentInput->getScaleLow()) {
                // use user defined scale
                m_nextState = RAW_LOW_TAG;
                m_nextChar = TAG_RAW_LOW_START;
            } else {
                // just the value is needed
                m_nextState = DATA_SET_END;
            }
            break;

        case CONVERSION_TAG:
            c = readTagChar(CONVERSION_START);
            break;
            
        case CONVERSION_START:
            c = '"';
            m_nextChar = m_currentInput->getConversion();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = CONVERSION_END;
            } else {
                m_nextState = CONVERSION;
            }
            break;
            
        case CONVERSION:
            c = readValueChar(CONVERSION_END);
            break;
            
        case CONVERSION_END:
            c = '"';
            m_nextState = DATA_SET_END;
            break;
            
        case RAW_LOW_TAG:
            c = readTagChar(RAW_LOW_START);
            break;
            
        case RAW_LOW_START:
            c = '"';
            m_nextChar = m_currentInput->getRawLow();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = RAW_LOW_END;
            } else {
                m_nextState = RAW_LOW;
            }
            break;
            
        case RAW_LOW:
            c = readValueChar(RAW_LOW_END);
            break;
            
        case RAW_LOW_END:
            c = '"';
            m_nextState = RAW_HIGH_TAG;
            m_nextChar = TAG_RAW_HIGH_START;
            break;
            
        case RAW_HIGH_TAG:
            c = readTagChar(RAW_HIGH_START);
            break;
            
        case RAW_HIGH_START:
            c = '"';
            m_nextChar = m_currentInput->getRawHigh();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = RAW_HIGH_END;
            } else {
                m_nextState = RAW_HIGH;
            }
            break;
            
        case RAW_HIGH:
            c = readValueChar(RAW_HIGH_END);
            break;
            
        case RAW_HIGH_END:
            c = '"';
            m_nextState = SCALE_LOW_TAG;
            m_nextChar = TAG_SCALE_LOW_START;
            break;
            
        case SCALE_LOW_TAG:
            c = readTagChar(SCALE_LOW_START);
            break;
            
        case SCALE_LOW_START:
            c = '"';
            m_nextChar = m_currentInput->getScaleLow();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = SCALE_LOW_END;
            } else {
                m_nextState = SCALE_LOW;
            }
            break;
            
        case SCALE_LOW:
            c = readValueChar(SCALE_LOW_END);
            break;
            
        case SCALE_LOW_END:
            c = '"';
            m_nextState = SCALE_HIGH_TAG;
            m_nextChar = TAG_SCALE_HIGH_START;
            break;
            
        case SCALE_HIGH_TAG:
            c = readTagChar(SCALE_HIGH_START);
            break;
            
        case SCALE_HIGH_START:
            c = '"';
            m_nextChar = m_currentInput->getScaleHigh();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = SCALE_HIGH_END;
            } else {
                m_nextState = SCALE_HIGH;
            }
            break;
            
        case SCALE_HIGH:
            c = readValueChar(SCALE_HIGH_END);
            break;
            
        case SCALE_HIGH_END:
            c = '"';
            m_nextState = DATA_SET_END;
            break;
            
        case DATA_SET_END:
            c = '}';
            m_currentInput = m_currentInput->getNext();
            if (NULL != m_currentInput) {
                m_nextState = NEXT_INPUT;
            } else {
                m_nextState = INPUTS_END;
            }
            break;
            
        case NEXT_INPUT:
            c = ',';
            m_nextChar = m_currentInput->getName();
            m_nextState = SENSOR_NAME_START;
            break;
            
        case INPUTS_END:
            c = '}';
            m_nextState = END;
            break;
            
        case END:
        default:
            c = '\0';
    }
    
    return c;
}
