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

#include "TembooGPIO.h"

int tembooDigitalRead(void* sensorConfig) {
	TembooGPIOConfig* config = (TembooGPIOConfig*) sensorConfig;
	if (config->mode == OUTPUT) {
		return config->currentValue;
	} 
	return digitalRead(config->pin);
	
}

void tembooDigitalWrite(void* sensorConfig, int val) {
	TembooGPIOConfig* config = (TembooGPIOConfig*) sensorConfig;
	digitalWrite(config->pin, val);
	config->currentValue = val;
}

int tembooAnalogRead(void* sensorConfig) {
	TembooGPIOConfig* config = (TembooGPIOConfig*) sensorConfig;
	if (config->mode == OUTPUT) {
		return config->currentValue;
	}
	return analogRead(config->pin);
}

void tembooAnalogWrite(void* sensorConfig, int val) {
	TembooGPIOConfig* config = (TembooGPIOConfig*) sensorConfig;
	analogWrite(config->pin, val);
	config->currentValue = val;
}

void tembooGPIOBegin(__attribute__((unused)) void* sensorConfig) {
	// all of the initializtion is done in init
	return;
}

uint8_t* tembooGPIOGetSensorChannel(void* sensorConfig) {
	TembooGPIOConfig* config = (TembooGPIOConfig*) sensorConfig;
	return config->channel;
}

int tembooGPIOGetSensorPin(void* sensorConfig) {
	TembooGPIOConfig* config = (TembooGPIOConfig*) sensorConfig;
	return config->pin;
}

void tembooDigitalGPIOInit(TembooGPIOConfig* sensorConfig, TembooSensor* tembooSensor, int pin, int defaultValue, int mode) {
	sensorConfig->pin = pin;
	sensorConfig->channel = NULL;
	sensorConfig->mode = mode;
	pinMode(pin, mode);
	if (mode == OUTPUT) {
		// this will set the current value
		tembooDigitalWrite(sensorConfig, defaultValue);
		tembooSensor->write = tembooDigitalWrite;
	} else {
		sensorConfig->currentValue = tembooDigitalRead(sensorConfig);
		tembooSensor->write = NULL;
	}
	tembooSensor->sensorConfig = sensorConfig;
	tembooSensor->read = tembooDigitalRead;
	tembooSensor->begin = tembooGPIOBegin;
	tembooSensor->getSensorPin = tembooGPIOGetSensorPin;
	tembooSensor->getSensorChannel = tembooGPIOGetSensorChannel;
	tembooSensor->defaultValue = defaultValue;
}

void tembooAnalogGPIOInit(TembooGPIOConfig* sensorConfig, TembooSensor* tembooSensor, int pin, int defaultValue, int mode) {
	sensorConfig->pin = pin;
	sensorConfig->channel = NULL;
	sensorConfig->mode = mode;
	pinMode(pin, mode);
	if (mode == OUTPUT) {
		// this will set the current value
		tembooAnalogWrite(sensorConfig, defaultValue);
		tembooSensor->write = tembooAnalogWrite;
	} else {
		sensorConfig->currentValue = tembooAnalogRead(sensorConfig);
		tembooSensor->write = NULL;
	}
	tembooSensor->sensorConfig = sensorConfig;
	tembooSensor->read = tembooAnalogRead;
	tembooSensor->begin = tembooGPIOBegin;
	tembooSensor->getSensorPin = tembooGPIOGetSensorPin;
	tembooSensor->getSensorChannel = tembooGPIOGetSensorChannel;
	tembooSensor->defaultValue = defaultValue;
}
