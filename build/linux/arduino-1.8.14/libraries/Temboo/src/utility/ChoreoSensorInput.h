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

#ifndef CHOREOSENSORINPUT_H_
#define CHOREOSENSORINPUT_H_

#include "TembooGlobal.h"
#define TEMBOO_SENSOR_INPUT_ARRAY_SIZE 8

class ChoreoSensorInput {
    public:
        
        ChoreoSensorInput(ChoreoSensorInput* prev, const char* name, int value, const char* sensorConversion, const char* rawLow, const char* rawHigh, const char* scaleLow, const char* scaleHigh, const char* calibration);
        
        const char* getName() const         {return m_name;}
        const char* getValue() const        {return m_value;}
        const char* getConversion() const   {return m_sensorConversion;}
        const char* getRawLow() const       {return m_rawLow;}
        const char* getRawHigh() const      {return m_rawHigh;}
        const char* getScaleLow() const     {return m_scaleLow;}
        const char* getScaleHigh() const    {return m_scaleHigh;}
        const char* getCalibration() const  {return m_calibration;}
        void setValue(int value)    {snprintf(m_value, TEMBOO_SENSOR_INPUT_ARRAY_SIZE, "%i",value);}
        void setConversion(const char* conversion)    {m_sensorConversion = conversion;}
        void setRawLow(const char* value)    {m_rawLow = value;}
        void setRawHigh(const char* value)    {m_rawHigh = value;}
        void setScaleLow(const char* value)    {m_scaleLow = value;}
        void setScaleHigh(const char* value)    {m_scaleHigh = value;}
        void setCalibration(const char* value)    {m_calibration = value;}
        ChoreoSensorInput* getNext() const  {return m_next;}

    private:
        ChoreoSensorInput* m_next;
        const char*  m_name;
        char  m_value[TEMBOO_SENSOR_INPUT_ARRAY_SIZE];
        const char*  m_sensorConversion;
        const char*  m_rawLow;
        const char*  m_rawHigh;
        const char*  m_scaleLow;
        const char*  m_scaleHigh;
        const char*  m_calibration;
};

#endif //CHOREOSENSORINPUT_H_