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

#ifndef TEMBOOYUNSHIELD_H_
#define TEMBOOYUNSHIELD_H_

#ifndef TEMBOO_LIBRARY_VERSION
#define TEMBOO_LIBRARY_VERSION 2
#endif

#include <Arduino.h>

///////////////////////////////////////////////////////
//  BEGIN ARDUINO YUN SHIELD SUPPORT
///////////////////////////////////////////////////////

#include <Process.h>

class TembooYunShieldChoreo : public Process {

    public:
    void begin() {Process::begin("temboo");}
    void setAccountName(const String& accountName) { addParameter("-a" + accountName);}
    void setAppKeyName(const String& appKeyName) { addParameter("-u" + appKeyName);}
    void setAppKey(const String& appKey) { addParameter("-p" + appKey);}
    void setChoreo(const String& choreo) { addParameter("-c" + choreo);}
    void setCredential(const String& credentialName) { addParameter("-e" + credentialName);}
    void setSavedInputs(const String& savedInputsName) { addParameter("-e" + savedInputsName);}
    void setProfile(const String& profileName) { addParameter("-e" + profileName);}
    void addInput(const String& inputName, const String& inputValue) { addParameter("-i" + inputName + ":" + inputValue);}
    void addOutputFilter(const String& filterName, const String& filterPath, const String& variableName) { addParameter("-o" + filterName + ":" + filterPath + ":" + variableName);}
    void setSettingsFileToWrite(const String& filePath) { addParameter("-w" + filePath);}
    void setSettingsFileToRead(const String& filePath) { addParameter("-r" + filePath);}
    void setGatewayAddress(const String& addr) { addParameter("-s" + addr);}
    void addInputExpression(const String& inputName, const String& inputValue) { addParameter("-f" + inputName + ":" + inputValue);}
    void addInputWithSensor(const String& inputName, const String& inputValue) { addParameter("-f" + inputName + ":" + inputValue);}
    void addSensorInput(const String& sensorName, long sensorValue, const String& conversion) {addParameter("-n" + sensorName + ":" + String(sensorValue) + ":" + conversion);}
    void addSensorInput(const String& sensorName, long sensorValue) {addParameter("-v" + sensorName + ":" + String(sensorValue));}
    void addSensorInput(const String& sensorName, long sensorValue, const String& conversion, const String& calibrationValue) {addParameter("-b" + sensorName + ":" + String(sensorValue) + ":" + conversion + ":" + calibrationValue);}
    void addSensorInput(const String& sensorName, long sensorValue, const String& rawLow, const String& rawHigh, const String& scaleLow, const String& scaleHigh) {addParameter("-m" + sensorName + ":" + String(sensorValue) + ":" + rawLow+ ":" + rawHigh+ ":" + scaleLow+ ":" + scaleHigh);}
    void addSensorValue(const String& sensorName, long sensorValue, const String& conversion) {addParameter("-n" + sensorName + ":" + String(sensorValue) + ":" + conversion);}
    void addSensorValue(const String& sensorName, long sensorValue) {addParameter("-v" + sensorName + ":" + String(sensorValue));}
    void addSensorValue(const String& sensorName, long sensorValue, const String& conversion, const String& calibrationValue) {addParameter("-b" + sensorName + ":" + String(sensorValue) + ":" + conversion + ":" + calibrationValue);}
    void addSensorValue(const String& sensorName, long sensorValue, const String& rawLow, const String& rawHigh, const String& scaleLow, const String& scaleHigh) {addParameter("-m" + sensorName + ":" + String(sensorValue) + ":" + rawLow+ ":" + rawHigh+ ":" + scaleLow+ ":" + scaleHigh);}
    void setDeviceName(const String& deviceName) {addParameter("-d" + deviceName);}
    void setDeviceType(const String& deviceType) {addParameter("-t" + deviceType);}
};



#endif //TEMBOOYUNSHIELD_H_
