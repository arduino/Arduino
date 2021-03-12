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

#ifndef TEMBOO_H_
#define TEMBOO_H_

#ifndef TEMBOO_LIBRARY_VERSION
#define TEMBOO_LIBRARY_VERSION 2
#endif

#include <Arduino.h>

#if defined (ARDUINO_AVR_YUN) || defined (ARDUINO_AVR_TRE)
///////////////////////////////////////////////////////
//  BEGIN ARDUINO YUN AND TRE SUPPORT
///////////////////////////////////////////////////////

#include <Process.h>

class TembooChoreo : public Process {

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

#else //ARDUINO_AVR_YUN

///////////////////////////////////////////////////////
//  BEGIN ARDUINO NON-YUN SUPPORT
///////////////////////////////////////////////////////

#include <Stream.h>
#include <Client.h>
#include <IPAddress.h>
#include "utility/ChoreoInputSet.h"
#include "utility/ChoreoInputExpressionSet.h"
#include "utility/ChoreoSensorInputSet.h"
#include "utility/ChoreoOutputSet.h"
#include "utility/ChoreoPreset.h"
#include "utility/ChoreoDevice.h"

#define TEMBOO_ERROR_OK                   (0)
#define TEMBOO_ERROR_ACCOUNT_MISSING      (201)
#define TEMBOO_ERROR_CHOREO_MISSING       (203)
#define TEMBOO_ERROR_APPKEY_NAME_MISSING  (205)
#define TEMBOO_ERROR_APPKEY_MISSING       (207)
#define TEMBOO_ERROR_HTTP_ERROR           (223)
#define TEMBOO_ERROR_STREAM_TIMEOUT       (225)
#define TEMBOO_CHOREO_DEFAULT_TIMEOUT_SECS     (901) //15 minutes and 1 second

class TembooChoreo : public Stream {
    public:
        
        // Constructor.
        // client - an instance of an Arduino Client, usually an EthernetClient
        //          or a WiFiClient.  Used to communicate with Temboo.
        TembooChoreo(Client& client);

        // Does nothing. Just for source compatibility with Yun code.
        void begin() {}; 
        
        // Sets the account name to use when communicating with Temboo.
        // (required)
        void setAccountName(const String& accountName);
        void setAccountName(const char* accountName);

        // Sets the application key name to use with choreo execution requests.
        // (required)
        void setAppKeyName(const String& appKeyName);
        void setAppKeyName(const char* appKeyName);
        
        // Sets the application key value to use with choreo execution requests
        // (required)
        void setAppKey(const String& appKey);
        void setAppKey(const char* appKey);
        
        // Sets the name of the choreo to be executed.
        // (required)
        void setChoreo(const String& choreoPath);
        void setChoreo(const char* choreoPath);
        
        // Sets the name of the saved inputs to use when executing the choreo
        // (optional)
        void setSavedInputs(const String& savedInputsName);
        void setSavedInputs(const char* savedInputsName);

        void setCredential(const String& credentialName);
        void setCredential(const char* credentialName);

        void setProfile(const String& profileName);
        void setProfile(const char* profileName);

        void setDeviceType(const String& deviceType);
        void setDeviceType(const char* deviceType);

        void setDeviceName(const String& deviceName);
        void setDeviceName(const char* deviceName);

        // Sets an input to be used when executing a choreo.
        // (optional or required, depending on the choreo being executed.)
        void addInput(const String& inputName, const String& inputValue);
        void addInput(const char* inputName, const char* inputValue);
        void addInput(const char* inputName, const String& inputValue);
        void addInput(const String& inputName, const char* inputValue);

        // Sets a Choreo input that contains a sensor value to be converted by Temboo
        void addInputWithSensor(const String& inputName, const String& inputValue);
        void addInputWithSensor(const char* inputName, const String& inputValue);
        void addInputWithSensor(const char* inputName, const char* inputValue);
        // Keeping legacy methods
        void addInputExpression(const String& inputName, const String& inputValue);
        void addInputExpression(const char* inputName, const String& inputValue);
        void addInputExpression(const char* inputName, const char* inputValue);

        // Sets in input that is using a sensor value. Different parameters are needed depending
        // on the type of sensor being used.
        void addSensorValue(const char* sensorName, int sensorValue, const char* conversion);
        void addSensorValue(const char* sensorName, int sensorValue);
        void addSensorValue(const char* sensorName, int sensorValue, const char* conversion, const char* calibrationValue);
        void addSensorValue(const char* sensorName, int sensorValue, const char* rawLow, const char* rawHigh, const char* scaleLow, const char* scaleHigh);
        // Keeping legacy methods
        void addSensorInput(const char* sensorName, int sensorValue, const char* conversion);
        void addSensorInput(const char* sensorName, int sensorValue);
        void addSensorInput(const char* sensorName, int sensorValue, const char* conversion, const char* calibrationValue);
        void addSensorInput(const char* sensorName, int sensorValue, const char* rawLow, const char* rawHigh, const char* scaleLow, const char* scaleHigh);

        // Sets an output filter to be used to process the choreo output
        // (optional)
        void addOutputFilter(const char* filterName, const char* filterPath, const char* variableName);
        void addOutputFilter(const String& filterName, const char* filterPath, const char* variableName);
        void addOutputFilter(const char* filterName, const String& filterPath, const char* variableName);
        void addOutputFilter(const String& filterName, const String& filterPath, const char* variableName);
        void addOutputFilter(const char* filterName, const char* filterPath, const String& variableName);
        void addOutputFilter(const String& filterName, const char* filterPath, const String& variableName);
        void addOutputFilter(const char* filterName, const String& filterPath, const String& variableName);
        void addOutputFilter(const String& filterName, const String& filterPath, const String& variableName);
       
        // Run the choreo using the current input info
        int run();
        // Run the choreo with a user specified timeout
        int run(uint16_t timeoutSecs);
    
        // Run the choreo on the Temboo server at the given IP address and port
        int run(IPAddress addr, uint16_t port);
        int run(IPAddress addr, uint16_t port, uint16_t timeoutSecs);

        void close();

        // Stream interface - see the Arduino library documentation.
        int available();
        int read();
        int peek();
        void flush();

        //Print interface - see the Arduino library documentation
        size_t write(uint8_t data);


    protected:
        ChoreoInputSet m_inputs;
        ChoreoInputExpressionSet m_expressions;
        ChoreoSensorInputSet m_sensors;
        ChoreoOutputSet m_outputs;
        ChoreoPreset m_preset;
        ChoreoDevice m_deviceType;
        ChoreoDevice m_deviceName;

        const char* m_accountName;
        const char* m_appKeyValue;
        const char* m_appKeyName;
        const char* m_path;
        Client& m_client;
        char m_httpCodeStr[6];
        const char* m_nextChar;
        enum State {START, HTTP_CODE_TAG, HTTP_CODE_VALUE, END};
        State m_nextState;

};

#endif //ARDUINO_AVR_YUN

#endif //TEMBOO_H_
