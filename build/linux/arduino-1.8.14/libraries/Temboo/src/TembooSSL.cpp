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

#if defined (ARDUINO_AVR_YUN) || defined (ARDUINO_AVR_TRE)

#else

#include <string.h>
#include <Client.h>
#include <avr/pgmspace.h>
#include <TembooSSL.h>
#include "utility/TembooGlobal.h"
#include "utility/TembooSession.h"

TembooChoreoSSL::TembooChoreoSSL(Client& client) : TembooChoreo(client) {
    m_accountName = NULL;
    m_appKeyName = NULL;
    m_appKeyValue = NULL;
    m_path = NULL;
    m_nextChar = NULL;
    m_nextState = END;
}

int TembooChoreoSSL::run() {
    return TembooChoreo::run(INADDR_NONE, 443, TEMBOO_CHOREO_DEFAULT_TIMEOUT_SECS);
}

int TembooChoreoSSL::run(uint16_t timeoutSecs) {
    return TembooChoreo::run(INADDR_NONE, 443, timeoutSecs);
}

#endif
