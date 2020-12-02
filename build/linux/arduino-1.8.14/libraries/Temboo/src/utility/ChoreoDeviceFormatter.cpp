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
#include "ChoreoDeviceFormatter.h"
#include "ChoreoDevice.h"

static const char TAG_DEVICE[] PROGMEM = "\"deviceType\":";
static const char TAG_DEVICE_NAME[] PROGMEM = "\"device\":";

ChoreoDeviceFormatter::ChoreoDeviceFormatter(const ChoreoDevice* device, Type type) {
    m_device = device;
    m_type = type;
    reset();
}

void ChoreoDeviceFormatter::reset() {
    m_nextChar = NULL;
    if (m_device == NULL || m_device->isEmpty()) {
        m_nextState = END;
    } else {
        m_nextState = START;
    }
}

bool ChoreoDeviceFormatter::hasNext() {
    return m_nextState != END;
}

char ChoreoDeviceFormatter::next() {
    char c = '\0';
    switch(m_nextState) {
        case START:
            if (m_type == DEVICE_TYPE) {
                c = readStartTagChar(TAG_DEVICE, DEVICE_TAG);
            } else {
                c = readStartTagChar(TAG_DEVICE_NAME, DEVICE_TAG);
            }
            break;

        case DEVICE_TAG:
            c = readTagChar(NAME_START);
            break;

        case NAME_START:
            c = '"';
            m_nextChar = m_device->getName();
            if ((NULL == m_nextChar) || ('\0' == *m_nextChar)) {
                m_nextState = NAME_END;
            } else {
                m_nextState = NAME;
            }
            break;

        case NAME:
            c = readValueChar(NAME_END);
            break;

        case NAME_END:
            c = '"';
            m_nextState = END;
            break;

        case END:
        default:
            c = '\0';
    }
    return c;
}

