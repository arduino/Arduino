/*
 ###############################################################################
 #
 # Temboo MQTT edge device library
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

#ifndef ARDUINOTIMER_H_
#define ARDUINOTIMER_H_

class ArduinoTimer {
    public:
        ArduinoTimer() {
            this->startTimeMillis = 0;
            this->durationMillis = 0;
        }

        ArduinoTimer(unsigned long durationMillis) {
            this->countdown_ms(durationMillis);
        }

        bool expired() {
            return left_ms() == 0;
        }

        void countdown_ms(unsigned long durationMillis) {
            this->startTimeMillis = millis();
            this->durationMillis = durationMillis;
        }

        void countdown(int durationSeconds) {
            countdown_ms((unsigned long)durationSeconds * 1000L);
        }

        unsigned long left_ms() {
            unsigned long elapsedMillis = millis() - this->startTimeMillis;
            return elapsedMillis < this->durationMillis ? (this->durationMillis - elapsedMillis) : 0;
        }

    private:
        unsigned long startTimeMillis;
        unsigned long durationMillis;

};


#endif /* ARDUINOIMER_H_ */
