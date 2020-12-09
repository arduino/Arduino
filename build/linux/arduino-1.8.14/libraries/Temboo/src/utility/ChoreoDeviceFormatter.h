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

#ifndef CHOREODEVICEFORMATTER_H_
#define CHOREODEVICEFORMATTER_H_
#include "TembooGlobal.h"
#include "BaseFormatter.h"
#include "ChoreoDevice.h"

class ChoreoDeviceFormatter : public BaseFormatter {
    public:
        enum Type {
            DEVICE_TYPE,
            DEVICE_NAME
        };
            
        ChoreoDeviceFormatter(const ChoreoDevice* device, Type type);
        bool hasNext();
        char next();
        void reset();
        
    protected:
        enum State {
            START,
            DEVICE_TAG,
            NAME_START,
            NAME,
            NAME_END,
            END
        };

        const ChoreoDevice* m_device;
        Type m_type;
};

#endif
