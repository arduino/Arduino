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

#ifndef TEMBOOTIMER_H_
#define TEMBOOTIMER_H_

class TembooTimer {
    public:
        TembooTimer() {
            this->m_startTimeMillis = 0;
            this->m_durationMillis = 0;
        }

        TembooTimer(uint32_t m_durationMillis) {
            this->start(m_durationMillis);
        }

        bool expired() {
            return leftMillis() == 0;
        }

        void start(uint32_t m_durationMillis) {
            this->m_startTimeMillis = getMillis();
            this->m_durationMillis = m_durationMillis;
        }

        uint32_t leftMillis() {
            uint32_t elapsedMillis = getMillis() - this->m_startTimeMillis;
            return elapsedMillis < this->m_durationMillis ? (this->m_durationMillis - elapsedMillis) : 0;
        }

    protected:
        uint32_t getMillis() {
            return millis();
        }

        uint32_t m_startTimeMillis;
        uint32_t m_durationMillis;

};


#endif /* TEMBOOTIMER_H_ */
