/*
 ###############################################################################
 #
 # Temboo CoAP Edge Device library
 #
 # Copyright (C) 2017, Temboo Inc.
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

#ifndef TEMBOOCOAPSESSIONCLASS_H_
#define TEMBOOCOAPSESSIONCLASS_H_

#include <stdint.h>
#include <Arduino.h>
#include "TembooCoAPEdgeDevice.h"
#include "TembooGlobal.h"

#ifndef TEMBOO_SEND_QUEUE_SIZE
#define TEMBOO_SEND_QUEUE_SIZE (1000)
#endif

class ChoreoInputSet;
class ChoreoOutputSet;
class ChoreoPreset;
class DataFormatter;

class TembooCoAPSession {
    public:
        
        //TembooSession constructor
        //client: REQUIRED TembooCoAPClient client object.
        TembooCoAPSession(TembooCoAPClient& client);
        
        //executeChoreo sends a choreo execution request to the Temboo system.
        //              Does not wait for a response (that's a job for whoever owns the Client.)
        //accountName: the name of the user's account at Temboo.
        //appKeyName: the name of an application key in the user's account to use
        //            for this execution (analogous to a user name).
        //appKeyValue: the value of the application key named in appKeyName.
        //             Used to authenticate the user (analogous to a password)
        //path: The full path to the choreo to be executed (relative to the root of the
        //      user's account.)
        //inputSet: the set of inputs needed by the choreo.
        //          May be an empty ChoreoInputSet.
        //outputSet: the set of output filters to be applied to the choreo results.
        //           May be an empty ChoreoOutputSet
        //preset: the ChoreoPreset to be used with the choreo execution.
        //        May be an empty ChoreoPreset.
        int executeChoreo(
                          uint16_t requestId,
                          const char* accountName,
                          const char* appKeyName,
                          const char* appKeyValue,
                          const char* path,
                          const ChoreoInputSet& inputSet, 
                          const ChoreoInputExpressionSet& expressionSet,
                          const ChoreoSensorInputSet& sensorSet,
                          const ChoreoOutputSet& outputSet, 
                          const ChoreoPreset& preset,
                          const ChoreoDevice& deviceType,
                          const ChoreoDevice& deviceName);
            
        // setTime sets the current time in Unix timestamp format.  Needed for execution request authentication.
        //         NOTE: This method is usually called by TembooChoreo.run() with the current time returned by
        //         an error response from the Temboo system, thus automatically setting the time.  However, it
        //         MAY be called from user code if the particular board has a way of determining the current
        //         time in the proper format.
        // currentTime: the number of seconds since 1970-01-01 00:00:00 UTC.
        static void setTime(unsigned long currentTime);
        
        //getTime returns the current time in Unix timestamp format (seconds since 1970-01-01 00:00:00 UTC).
        //        Only valid after setTime has been called.
        static unsigned long getTime();
        
        enum Error {
            SUCCESS = 0,
            FAILURE
        };
        
    private:
        TembooCoAPClient& m_client;
        static unsigned long s_timeOffset;
        
        // calculate the authentication code value of the formatted request body
        // using the salted application key value as the key.
        // Returns the number of characters processed (i.e. the length of the request body)
        uint16_t getAuth(DataFormatter& fmt, const char* appKeyValue, const char* salt, char* hexAuth) const;
        
        
        // queue an entire nul-terminated char array
        // from RAM one byte at a time.
        // returns true on success, false on failure
        bool qsend(const char*);
        
        // queue a single character to be sent.
        // returns true on success, false on failure
        bool qsend(char);
    
};

#endif

