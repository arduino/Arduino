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

#ifndef CHOREOSENSORINPUTFORMATTER_H_
#define CHOREOSENSORINPUTFORMATTER_H_

#include "TembooGlobal.h"
#include "BaseFormatter.h"
#include "ChoreoSensorInputSet.h"

class ChoreoSensorInputFormatter : public BaseFormatter {

    public:
        ChoreoSensorInputFormatter(const ChoreoSensorInputSet* inputSet);
        bool hasNext();
        char next();
        void reset();

    protected:
        const ChoreoSensorInputSet* m_inputSet;
        const ChoreoSensorInput* m_currentInput;
        
        
        enum State {
            // This is added to fix a compilation bug for the mkr1000
            START = 256,
            SENSOR_INPUT_TAG,
            SENSOR_NAME_START,
            SENSOR_NAME,
            SENSOR_NAME_END,
            SENSOR_NAME_SEPERATOR,
            VALUE_TAG,
            VALUE_START,
            VALUE,
            VALUE_END,
            CALIBRATION_TAG,
            CALIBRATION_START,
            CALIBRATION,
            CALIBRATION_END,
            CONVERSION_TAG,
            CONVERSION_START,
            CONVERSION,
            CONVERSION_END,
            RAW_LOW_TAG,
            RAW_LOW_START,
            RAW_LOW,
            RAW_LOW_END,
            RAW_HIGH_TAG,
            RAW_HIGH_START,
            RAW_HIGH,
            RAW_HIGH_END,
            SCALE_LOW_TAG,
            SCALE_LOW_START,
            SCALE_LOW,
            SCALE_LOW_END,
            SCALE_HIGH_TAG,
            SCALE_HIGH_START,
            SCALE_HIGH,
            SCALE_HIGH_END,
            DATA_SET_END,
            NEXT_INPUT,
            INPUTS_END,
            END
        };
};

#endif //CHOREOSENSORINPUTFORMATTER_H_