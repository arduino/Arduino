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

#include "DataFormatter.h"


DataFormatter::DataFormatter(const ChoreoInputSet* inputSet, const ChoreoInputExpressionSet* expressionSet, const ChoreoSensorInputSet* sensorSet, const ChoreoOutputSet* outputSet, const ChoreoPreset* preset, const ChoreoDevice* device, const ChoreoDevice* deviceName) : 
    m_inputFormatter(inputSet),
    m_expressionFormatter(expressionSet),
    m_sensorFormatter(sensorSet), 
    m_outputFormatter(outputSet), 
    m_presetFormatter(preset),
    m_deviceTypeFormatter(device, ChoreoDeviceFormatter::DEVICE_TYPE),
    m_deviceNameFormatter(deviceName, ChoreoDeviceFormatter::DEVICE_NAME) {

    m_inputSet = inputSet;
    m_expressionSet = expressionSet;
    m_sensorSet = sensorSet;
    m_outputSet = outputSet;
    m_preset = preset;
   
    reset();
}

void DataFormatter::reset() {
    m_nextState = DATA_START;
    m_inputFormatter.reset();
    m_expressionFormatter.reset();
    m_sensorFormatter.reset();
    m_outputFormatter.reset();
    m_presetFormatter.reset();
    m_deviceTypeFormatter.reset();
    m_deviceNameFormatter.reset();
}

bool DataFormatter::hasNext() {
    return m_nextState != DATA_END;
}

char DataFormatter::next() {
    char c;
    switch(m_nextState) {
        case DATA_START:
            c = '{';
            // only add device type or device name if 
            // sensor data is being sent with the Choreo
            // If device name is added, no need to send
            // device type
            if (m_sensorFormatter.hasNext()) {
                if (m_deviceNameFormatter.hasNext()) {
                    m_nextState = FORMATTING_DEVICE_NAME;
                } else if (m_deviceTypeFormatter.hasNext()) {
                    m_nextState = FORMATTING_DEVICE_TYPE;
                }
            } else {    
                if (m_inputFormatter.hasNext()) {
                    m_nextState = FORMATTING_INPUTS;
                } else if (m_expressionFormatter.hasNext()) {
                    m_nextState = FORMATTING_EXPRESSIONS;
                } else if (m_sensorFormatter.hasNext()) {
                    m_nextState = FORMATTING_SENSORS;
                } else if (m_outputFormatter.hasNext()) {
                    m_nextState = FORMATTING_OUTPUTS;
                } else if (m_presetFormatter.hasNext()) {
                    m_nextState = FORMATTING_PRESET;
                } else {
                    m_nextState = FORMATTING_EMPTY;
                }
            }
            break;

        case FORMATTING_DEVICE_TYPE:
            if (m_deviceTypeFormatter.hasNext()) {
                c = m_deviceTypeFormatter.next();
            } else if (m_inputFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_INPUTS;
            } else if (m_expressionFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_EXPRESSIONS;
            } else if (m_sensorFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_SENSORS;
            } else if (m_outputFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_OUTPUTS;
            } else if (m_presetFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_PRESET;
            } else {
                c = '}';
                m_nextState = DATA_END;
            }
            break;

        case FORMATTING_DEVICE_NAME:
            if (m_deviceNameFormatter.hasNext()) {
                c = m_deviceNameFormatter.next();
            } else if (m_inputFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_INPUTS;
            } else if (m_expressionFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_EXPRESSIONS;
            } else if (m_sensorFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_SENSORS;
            } else if (m_outputFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_OUTPUTS;
            } else if (m_presetFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_PRESET;
            } else {
                c = '}';
                m_nextState = DATA_END;
            }
            break;

        case FORMATTING_INPUTS:
            if (m_inputFormatter.hasNext()) {
                c = m_inputFormatter.next();
            } else if (m_expressionFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_EXPRESSIONS;
            } else if (m_sensorFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_SENSORS;
            } else if (m_outputFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_OUTPUTS;
            } else if (m_presetFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_PRESET;
            } else {
                c = '}';
                m_nextState = DATA_END;
            }
            break;

        case FORMATTING_EXPRESSIONS:
            if (m_expressionFormatter.hasNext()) {
                c = m_expressionFormatter.next();
            } else if (m_sensorFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_SENSORS;
            } else if (m_outputFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_OUTPUTS;
            } else if (m_presetFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_PRESET;
            } else {
                c = '}';
                m_nextState = DATA_END;
            }
            break;

        case FORMATTING_SENSORS:
           if (m_sensorFormatter.hasNext()) {
                c = m_sensorFormatter.next();
            } else if (m_outputFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_OUTPUTS;
            } else if (m_presetFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_PRESET;
            } else {
                c = '}';
                m_nextState = DATA_END;
            }
            break;

        case FORMATTING_OUTPUTS:
            if (m_outputFormatter.hasNext()) {
                c = m_outputFormatter.next();
            } else if (m_presetFormatter.hasNext()) {
                c = ',';
                m_nextState = FORMATTING_PRESET;
            } else {
                c = '}';
                m_nextState = DATA_END;
            }
            break;

        case FORMATTING_PRESET:
            if (m_presetFormatter.hasNext()) {
                c = m_presetFormatter.next();
            } else {
                c = '}';
                m_nextState = DATA_END;
            }
            break;

        case FORMATTING_EMPTY:
            c = '}';
            m_nextState = DATA_END;
            break;

        case DATA_END:
        default:
            c = '\0';
            break;
    }
    return c;
}

