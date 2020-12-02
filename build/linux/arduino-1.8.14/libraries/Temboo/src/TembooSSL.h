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

#ifndef TEMBOOSSL_H_
#define TEMBOOSSL_H_

#ifndef TEMBOO_LIBRARY_VERSION
#define TEMBOO_LIBRARY_VERSION 2
#endif

#include <Arduino.h>

#if defined (ARDUINO_AVR_YUN) || defined (ARDUINO_AVR_TRE)

#include <Temboo.h>

class TembooChoreoSSL : public TembooChoreo {};

#else

///////////////////////////////////////////////////////
//  BEGIN ARDUINO NON-YUN SUPPORT FOR SSL
///////////////////////////////////////////////////////

#include <Stream.h>
#include <Client.h>
#include <IPAddress.h>
#include <Temboo.h>
#include "utility/ChoreoInputSet.h"
#include "utility/ChoreoOutputSet.h"
#include "utility/ChoreoPreset.h"

class TembooChoreoSSL : public TembooChoreo {
    public:
        
        // Constructor.
        // client - an instance of an Arduino Client that 
        // allows HTTPS conntections, usually WiFiSSL
        TembooChoreoSSL(Client& client);

        // run the choreo using the current input info
        // uses port 443
        int run();
        // run the choreo with a user specified timeout
        // uses port 443
        int run(uint16_t timeoutSecs);
};

#endif //ARDUINO_AVR_YUN

#endif //TEMBOO_H_
