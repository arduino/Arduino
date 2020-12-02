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

#include <string.h>
#include "ChoreoInputExpressionSet.h"

ChoreoInputExpressionSet::ChoreoInputExpressionSet() {
    m_first = NULL;
}

ChoreoInputExpressionSet::~ChoreoInputExpressionSet() {
    ChoreoInputExpression* i = m_first;
    ChoreoInputExpression* next = NULL;
    while (i != NULL) {
        next = i->getNext();
        delete i;
        i = next;
    }
}

void ChoreoInputExpressionSet::put(const char* name, const char* value) {

    // Haven't set ANY inputs yet?  
    // Just create a new one.
    if (m_first == NULL) {
        m_first = new ChoreoInputExpression(NULL, name, value);
    } else {
        // Some inputs already set.
        // See if we already have this input.
        ChoreoInputExpression* last = NULL;
        ChoreoInputExpression* i = m_first;
        while(i != NULL) {
            if (strcmp(i->getName(), name) == 0) {
                // We already have an input with this name.
                // Just update the value.
                i->setValue(value);
                break;
            }
            last = i;
            i = i->getNext();
        }

        // We don't have an input with this name
        // So we need to create a new one.
        if (i == NULL) {
            new ChoreoInputExpression(last, name, value);
        }
    }
}

const char* ChoreoInputExpressionSet::get(const char* name) const {
    ChoreoInputExpression* i = m_first;
    while(i != NULL) {
        if (strcmp(i->getName(), name) == 0) {
            return i->getValue();
        }
        i = i->getNext();
    }
    return NULL;
}

