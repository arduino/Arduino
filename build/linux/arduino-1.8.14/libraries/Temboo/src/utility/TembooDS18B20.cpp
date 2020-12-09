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

#include "TembooOneWire.h"
#include "TembooDS18B20.h"

TembooOneWire* g_wire;

int tembooDS18B20Read(void* sensorConfig) {

    uint8_t scratchPad[9];
	TembooDS18B20Config* config = (TembooDS18B20Config*) sensorConfig;
	
	g_wire->reset();
	g_wire->select(config->channel);
	// tells device to convert temperature to scratchpad to read
	g_wire->write(0x44, config->parasite);
	// delay 750ms for conversion to occur, but wait for 1 second just in case
	delay(config->conversionDelayMillis);

	// begin reading data
	g_wire->reset();
	// select the device we're requesting data from
	g_wire->select(config->channel);
	// send message to device requesting data
	g_wire->write(0xBE);

	for(int i = 0; i < 9; i++) {
		scratchPad[i] = g_wire->read();
	}
	int16_t temp = (((int16_t)scratchPad[1]) << 8) + (int16_t)scratchPad[0];

	return temp;
}

void tembooDS18B20Begin(__attribute__((unused)) void* sensorConfig) {
	// all of the initializtion is done in init
	return;
}

uint8_t* tembooDS18B20GetSensorChannel(void* sensorConfig) {
	TembooDS18B20Config* config = (TembooDS18B20Config*) sensorConfig;
	return config->channel;
}

int tembooDS18B20GetSensorPin(void* sensorConfig) {
	TembooDS18B20Config* config = (TembooDS18B20Config*) sensorConfig;
	return config->pin;
}

void tembooDS18B20Init(TembooDS18B20Config* sensorConfig, TembooSensor* tembooSensor, int pin, int defaultValue) {
	sensorConfig->pin = pin;
	sensorConfig->conversionDelayMillis = 1000;

	// create OneWire object
	if (NULL == g_wire) {
        g_wire = new TembooOneWire(pin);
    }
	// reset search before searching for device
	g_wire->reset_search();
	// find device connected to the wire
	g_wire->search(sensorConfig->channel);

	if (g_wire->crc8(sensorConfig->channel, 7) != sensorConfig->channel[7]) {
		// invalid address
	}
	// begin to check if sensor is in parasite mode
	g_wire->reset();
	g_wire->select(sensorConfig->channel);
	g_wire->write(0xB4);
	sensorConfig->parasite = g_wire->read_bit() == 0;
	g_wire->reset();

	tembooSensor->sensorConfig = sensorConfig;
	tembooSensor->read = tembooDS18B20Read;
	tembooSensor->begin = tembooDS18B20Begin;
	tembooSensor->write = NULL;
	tembooSensor->getSensorPin = tembooDS18B20GetSensorPin;
	tembooSensor->getSensorChannel = tembooDS18B20GetSensorChannel;
	tembooSensor->defaultValue = defaultValue;
}