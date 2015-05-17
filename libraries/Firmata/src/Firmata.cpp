/*
  Firmata.cpp - Firmata library v2.4.3 - 2015-4-11
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

//******************************************************************************
//* Includes
//******************************************************************************

#include "Firmata.h"
#include "HardwareSerial.h"

extern "C" {
#include <string.h>
#include <stdlib.h>
}

//******************************************************************************
//* Support Functions
//******************************************************************************

void FirmataClass::sendValueAsTwo7bitBytes(int value)
{
  FirmataStream->write(value & B01111111); // LSB
  FirmataStream->write(value >> 7 & B01111111); // MSB
}

void FirmataClass::startSysex(void)
{
  FirmataStream->write(START_SYSEX);
}

void FirmataClass::endSysex(void)
{
  FirmataStream->write(END_SYSEX);
}

//******************************************************************************
//* Constructors
//******************************************************************************

FirmataClass::FirmataClass()
{
  firmwareVersionCount = 0;
  firmwareVersionVector = 0;
  systemReset();
}

//******************************************************************************
//* Public Methods
//******************************************************************************

/* begin method with default serial bitrate */
void FirmataClass::begin(void)
{
  begin(57600);
}

/* begin method for overriding default serial bitrate */
void FirmataClass::begin(long speed)
{
  Serial.begin(speed);
  FirmataStream = &Serial;
  blinkVersion();
  printVersion();
  printFirmwareVersion();
}

/* begin method for overriding default stream */
void FirmataClass::begin(Stream &s)
{
  FirmataStream = &s;
  // do not call blinkVersion() here because some hardware such as the
  // Ethernet shield use pin 13
  printVersion();
  printFirmwareVersion();
}

// output the protocol version message to the serial port
void FirmataClass::printVersion(void)
{
  FirmataStream->write(REPORT_VERSION);
  FirmataStream->write(FIRMATA_MAJOR_VERSION);
  FirmataStream->write(FIRMATA_MINOR_VERSION);
}

void FirmataClass::blinkVersion(void)
{
  // flash the pin with the protocol version
  pinMode(VERSION_BLINK_PIN, OUTPUT);
  strobeBlinkPin(FIRMATA_MAJOR_VERSION, 40, 210);
  delay(250);
  strobeBlinkPin(FIRMATA_MINOR_VERSION, 40, 210);
  delay(125);
}

void FirmataClass::printFirmwareVersion(void)
{
  byte i;

  if (firmwareVersionCount) { // make sure that the name has been set before reporting
    startSysex();
    FirmataStream->write(REPORT_FIRMWARE);
    FirmataStream->write(firmwareVersionVector[0]); // major version number
    FirmataStream->write(firmwareVersionVector[1]); // minor version number
    for (i = 2; i < firmwareVersionCount; ++i) {
      sendValueAsTwo7bitBytes(firmwareVersionVector[i]);
    }
    endSysex();
  }
}

void FirmataClass::setFirmwareNameAndVersion(const char *name, byte major, byte minor)
{
  const char *firmwareName;
  const char *extension;

  // parse out ".cpp" and "applet/" that comes from using __FILE__
  extension = strstr(name, ".cpp");
  firmwareName = strrchr(name, '/');

  if (!firmwareName) {
    // windows
    firmwareName = strrchr(name, '\\');
  }
  if (!firmwareName) {
    // user passed firmware name
    firmwareName = name;
  } else {
    firmwareName ++;
  }

  if (!extension) {
    firmwareVersionCount = strlen(firmwareName) + 2;
  } else {
    firmwareVersionCount = extension - firmwareName + 2;
  }

  // in case anyone calls setFirmwareNameAndVersion more than once
  free(firmwareVersionVector);

  firmwareVersionVector = (byte *) malloc(firmwareVersionCount + 1);
  firmwareVersionVector[firmwareVersionCount] = 0;
  firmwareVersionVector[0] = major;
  firmwareVersionVector[1] = minor;
  strncpy((char *)firmwareVersionVector + 2, firmwareName, firmwareVersionCount - 2);
}

//------------------------------------------------------------------------------
// Serial Receive Handling

int FirmataClass::available(void)
{
  return FirmataStream->available();
}


void FirmataClass::processSysexMessage(void)
{
  switch (storedInputData[0]) { //first byte in buffer is command
    case REPORT_FIRMWARE:
      printFirmwareVersion();
      break;
    case STRING_DATA:
      if (currentStringCallback) {
        byte bufferLength = (sysexBytesRead - 1) / 2;
        byte i = 1;
        byte j = 0;
        while (j < bufferLength) {
          // The string length will only be at most half the size of the
          // stored input buffer so we can decode the string within the buffer.
          storedInputData[j] = storedInputData[i];
          i++;
          storedInputData[j] += (storedInputData[i] << 7);
          i++;
          j++;
        }
        // Make sure string is null terminated. This may be the case for data
        // coming from client libraries in languages that don't null terminate
        // strings.
        if (storedInputData[j - 1] != '\0') {
          storedInputData[j] = '\0';
        }
        (*currentStringCallback)((char *)&storedInputData[0]);
      }
      break;
    default:
      if (currentSysexCallback)
        (*currentSysexCallback)(storedInputData[0], sysexBytesRead - 1, storedInputData + 1);
  }
}

void FirmataClass::processInput(void)
{
  int inputData = FirmataStream->read(); // this is 'int' to handle -1 when no data
  int command;

  // TODO make sure it handles -1 properly

  if (parsingSysex) {
    if (inputData == END_SYSEX) {
      //stop sysex byte
      parsingSysex = false;
      //fire off handler function
      processSysexMessage();
    } else {
      //normal data byte - add to buffer
      storedInputData[sysexBytesRead] = inputData;
      sysexBytesRead++;
    }
  } else if ( (waitForData > 0) && (inputData < 128) ) {
    waitForData--;
    storedInputData[waitForData] = inputData;
    if ( (waitForData == 0) && executeMultiByteCommand ) { // got the whole message
      switch (executeMultiByteCommand) {
        case ANALOG_MESSAGE:
          if (currentAnalogCallback) {
            (*currentAnalogCallback)(multiByteChannel,
                                     (storedInputData[0] << 7)
                                     + storedInputData[1]);
          }
          break;
        case DIGITAL_MESSAGE:
          if (currentDigitalCallback) {
            (*currentDigitalCallback)(multiByteChannel,
                                      (storedInputData[0] << 7)
                                      + storedInputData[1]);
          }
          break;
        case SET_PIN_MODE:
          if (currentPinModeCallback)
            (*currentPinModeCallback)(storedInputData[1], storedInputData[0]);
          break;
        case REPORT_ANALOG:
          if (currentReportAnalogCallback)
            (*currentReportAnalogCallback)(multiByteChannel, storedInputData[0]);
          break;
        case REPORT_DIGITAL:
          if (currentReportDigitalCallback)
            (*currentReportDigitalCallback)(multiByteChannel, storedInputData[0]);
          break;
      }
      executeMultiByteCommand = 0;
    }
  } else {
    // remove channel info from command byte if less than 0xF0
    if (inputData < 0xF0) {
      command = inputData & 0xF0;
      multiByteChannel = inputData & 0x0F;
    } else {
      command = inputData;
      // commands in the 0xF* range don't use channel data
    }
    switch (command) {
      case ANALOG_MESSAGE:
      case DIGITAL_MESSAGE:
      case SET_PIN_MODE:
        waitForData = 2; // two data bytes needed
        executeMultiByteCommand = command;
        break;
      case REPORT_ANALOG:
      case REPORT_DIGITAL:
        waitForData = 1; // one data byte needed
        executeMultiByteCommand = command;
        break;
      case START_SYSEX:
        parsingSysex = true;
        sysexBytesRead = 0;
        break;
      case SYSTEM_RESET:
        systemReset();
        break;
      case REPORT_VERSION:
        Firmata.printVersion();
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Serial Send Handling

// send an analog message
void FirmataClass::sendAnalog(byte pin, int value)
{
  // pin can only be 0-15, so chop higher bits
  FirmataStream->write(ANALOG_MESSAGE | (pin & 0xF));
  sendValueAsTwo7bitBytes(value);
}

// send a single digital pin in a digital message
void FirmataClass::sendDigital(byte pin, int value)
{
  /* TODO add single pin digital messages to the protocol, this needs to
   * track the last digital data sent so that it can be sure to change just
   * one bit in the packet.  This is complicated by the fact that the
   * numbering of the pins will probably differ on Arduino, Wiring, and
   * other boards.  The DIGITAL_MESSAGE sends 14 bits at a time, but it is
   * probably easier to send 8 bit ports for any board with more than 14
   * digital pins.
   */

  // TODO: the digital message should not be sent on the serial port every
  // time sendDigital() is called.  Instead, it should add it to an int
  // which will be sent on a schedule.  If a pin changes more than once
  // before the digital message is sent on the serial port, it should send a
  // digital message for each change.

  //    if(value == 0)
  //        sendDigitalPortPair();
}


// send 14-bits in a single digital message (protocol v1)
// send an 8-bit port in a single digital message (protocol v2)
void FirmataClass::sendDigitalPort(byte portNumber, int portData)
{
  FirmataStream->write(DIGITAL_MESSAGE | (portNumber & 0xF));
  FirmataStream->write((byte)portData % 128); // Tx bits 0-6
  FirmataStream->write(portData >> 7);  // Tx bits 7-13
}


void FirmataClass::sendSysex(byte command, byte bytec, byte *bytev)
{
  byte i;
  startSysex();
  FirmataStream->write(command);
  for (i = 0; i < bytec; i++) {
    sendValueAsTwo7bitBytes(bytev[i]);
  }
  endSysex();
}

void FirmataClass::sendString(byte command, const char *string)
{
  sendSysex(command, strlen(string), (byte *)string);
}


// send a string as the protocol string type
void FirmataClass::sendString(const char *string)
{
  sendString(STRING_DATA, string);
}

// expose the write method
void FirmataClass::write(byte c)
{
  FirmataStream->write(c);
}


// Internal Actions/////////////////////////////////////////////////////////////

// generic callbacks
void FirmataClass::attach(byte command, callbackFunction newFunction)
{
  switch (command) {
    case ANALOG_MESSAGE: currentAnalogCallback = newFunction; break;
    case DIGITAL_MESSAGE: currentDigitalCallback = newFunction; break;
    case REPORT_ANALOG: currentReportAnalogCallback = newFunction; break;
    case REPORT_DIGITAL: currentReportDigitalCallback = newFunction; break;
    case SET_PIN_MODE: currentPinModeCallback = newFunction; break;
  }
}

void FirmataClass::attach(byte command, systemResetCallbackFunction newFunction)
{
  switch (command) {
    case SYSTEM_RESET: currentSystemResetCallback = newFunction; break;
  }
}

void FirmataClass::attach(byte command, stringCallbackFunction newFunction)
{
  switch (command) {
    case STRING_DATA: currentStringCallback = newFunction; break;
  }
}

void FirmataClass::attach(byte command, sysexCallbackFunction newFunction)
{
  currentSysexCallback = newFunction;
}

void FirmataClass::detach(byte command)
{
  switch (command) {
    case SYSTEM_RESET: currentSystemResetCallback = NULL; break;
    case STRING_DATA: currentStringCallback = NULL; break;
    case START_SYSEX: currentSysexCallback = NULL; break;
    default:
      attach(command, (callbackFunction)NULL);
  }
}

// sysex callbacks
/*
 * this is too complicated for analogReceive, but maybe for Sysex?
 void FirmataClass::attachSysex(sysexFunction newFunction)
 {
 byte i;
 byte tmpCount = analogReceiveFunctionCount;
 analogReceiveFunction* tmpArray = analogReceiveFunctionArray;
 analogReceiveFunctionCount++;
 analogReceiveFunctionArray = (analogReceiveFunction*) calloc(analogReceiveFunctionCount, sizeof(analogReceiveFunction));
 for(i = 0; i < tmpCount; i++) {
 analogReceiveFunctionArray[i] = tmpArray[i];
 }
 analogReceiveFunctionArray[tmpCount] = newFunction;
 free(tmpArray);
 }
*/

//******************************************************************************
//* Private Methods
//******************************************************************************



// resets the system state upon a SYSTEM_RESET message from the host software
void FirmataClass::systemReset(void)
{
  byte i;

  waitForData = 0; // this flag says the next serial input will be data
  executeMultiByteCommand = 0; // execute this after getting multi-byte data
  multiByteChannel = 0; // channel data for multiByteCommands

  for (i = 0; i < MAX_DATA_BYTES; i++) {
    storedInputData[i] = 0;
  }

  parsingSysex = false;
  sysexBytesRead = 0;

  if (currentSystemResetCallback)
    (*currentSystemResetCallback)();
}



// =============================================================================
// used for flashing the pin for the version number
void FirmataClass::strobeBlinkPin(int count, int onInterval, int offInterval)
{
  byte i;
  pinMode(VERSION_BLINK_PIN, OUTPUT);
  for (i = 0; i < count; i++) {
    delay(offInterval);
    digitalWrite(VERSION_BLINK_PIN, HIGH);
    delay(onInterval);
    digitalWrite(VERSION_BLINK_PIN, LOW);
  }
}


// make one instance for the user to use
FirmataClass Firmata;
