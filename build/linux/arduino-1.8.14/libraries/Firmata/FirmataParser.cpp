/*
  FirmataParser.cpp
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2009-2016 Jeff Hoefs.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

//******************************************************************************
//* Includes
//******************************************************************************

#include "FirmataParser.h"

#include "FirmataConstants.h"

using namespace firmata;

//******************************************************************************
//* Constructors
//******************************************************************************

/**
 * The FirmataParser class.
 * @param dataBuffer A pointer to an external buffer used to store parsed data
 * @param dataBufferSize The size of the external buffer
 */
FirmataParser::FirmataParser(uint8_t * const dataBuffer, size_t dataBufferSize)
:
  dataBuffer(dataBuffer),
  dataBufferSize(dataBufferSize),
  executeMultiByteCommand(0),
  multiByteChannel(0),
  waitForData(0),
  parsingSysex(false),
  sysexBytesRead(0),
  currentAnalogCallbackContext((void *)NULL),
  currentDigitalCallbackContext((void *)NULL),
  currentReportAnalogCallbackContext((void *)NULL),
  currentReportDigitalCallbackContext((void *)NULL),
  currentPinModeCallbackContext((void *)NULL),
  currentPinValueCallbackContext((void *)NULL),
  currentReportFirmwareCallbackContext((void *)NULL),
  currentReportVersionCallbackContext((void *)NULL),
  currentDataBufferOverflowCallbackContext((void *)NULL),
  currentStringCallbackContext((void *)NULL),
  currentSysexCallbackContext((void *)NULL),
  currentSystemResetCallbackContext((void *)NULL),
  currentAnalogCallback((callbackFunction)NULL),
  currentDigitalCallback((callbackFunction)NULL),
  currentReportAnalogCallback((callbackFunction)NULL),
  currentReportDigitalCallback((callbackFunction)NULL),
  currentPinModeCallback((callbackFunction)NULL),
  currentPinValueCallback((callbackFunction)NULL),
  currentDataBufferOverflowCallback((dataBufferOverflowCallbackFunction)NULL),
  currentStringCallback((stringCallbackFunction)NULL),
  currentSysexCallback((sysexCallbackFunction)NULL),
  currentReportFirmwareCallback((versionCallbackFunction)NULL),
  currentReportVersionCallback((systemCallbackFunction)NULL),
  currentSystemResetCallback((systemCallbackFunction)NULL)
{
    allowBufferUpdate = ((uint8_t *)NULL == dataBuffer);
}

//******************************************************************************
//* Public Methods
//******************************************************************************

//------------------------------------------------------------------------------
// Serial Receive Handling

/**
 * Parse data from the input stream.
 * @param inputData A single byte to be added to the parser.
 */
void FirmataParser::parse(uint8_t inputData)
{
  uint8_t command;

  if (parsingSysex) {
    if (inputData == END_SYSEX) {
      //stop sysex byte
      parsingSysex = false;
      //fire off handler function
      processSysexMessage();
    } else {
      //normal data byte - add to buffer
      bufferDataAtPosition(inputData, sysexBytesRead);
      ++sysexBytesRead;
    }
  } else if ( (waitForData > 0) && (inputData < 128) ) {
    --waitForData;
    bufferDataAtPosition(inputData, waitForData);
    if ( (waitForData == 0) && executeMultiByteCommand ) { // got the whole message
      switch (executeMultiByteCommand) {
        case ANALOG_MESSAGE:
          if (currentAnalogCallback) {
            (*currentAnalogCallback)(currentAnalogCallbackContext,
                                     multiByteChannel,
                                     (dataBuffer[0] << 7)
                                     + dataBuffer[1]);
          }
          break;
        case DIGITAL_MESSAGE:
          if (currentDigitalCallback) {
            (*currentDigitalCallback)(currentDigitalCallbackContext,
                                      multiByteChannel,
                                      (dataBuffer[0] << 7)
                                      + dataBuffer[1]);
          }
          break;
        case SET_PIN_MODE:
          if (currentPinModeCallback)
            (*currentPinModeCallback)(currentPinModeCallbackContext, dataBuffer[1], dataBuffer[0]);
          break;
        case SET_DIGITAL_PIN_VALUE:
          if (currentPinValueCallback)
            (*currentPinValueCallback)(currentPinValueCallbackContext, dataBuffer[1], dataBuffer[0]);
          break;
        case REPORT_ANALOG:
          if (currentReportAnalogCallback)
            (*currentReportAnalogCallback)(currentReportAnalogCallbackContext, multiByteChannel, dataBuffer[0]);
          break;
        case REPORT_DIGITAL:
          if (currentReportDigitalCallback)
            (*currentReportDigitalCallback)(currentReportDigitalCallbackContext, multiByteChannel, dataBuffer[0]);
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
      case SET_DIGITAL_PIN_VALUE:
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
        if (currentReportVersionCallback)
          (*currentReportVersionCallback)(currentReportVersionCallbackContext);
        break;
    }
  }
}

/**
 * @return Returns true if the parser is actively parsing data.
 */
bool FirmataParser::isParsingMessage(void)
const
{
  return (waitForData > 0 || parsingSysex);
}

/**
 * Provides a mechanism to either set or update the working buffer of the parser.
 * The method will be enabled when no buffer has been provided, or an overflow
 * condition exists.
 * @param dataBuffer A pointer to an external buffer used to store parsed data
 * @param dataBufferSize The size of the external buffer
 */
int FirmataParser::setDataBufferOfSize(uint8_t * dataBuffer, size_t dataBufferSize)
{
    int result;

    if ( !allowBufferUpdate ) {
      result = __LINE__;
    } else if ((uint8_t *)NULL == dataBuffer) {
      result = __LINE__;
    } else {
      this->dataBuffer = dataBuffer;
      this->dataBufferSize = dataBufferSize;
      allowBufferUpdate = false;
      result = 0;
    }

    return result;
}

/**
 * Attach a generic sysex callback function to a command (options are: ANALOG_MESSAGE,
 * DIGITAL_MESSAGE, REPORT_ANALOG, REPORT DIGITAL, SET_PIN_MODE and SET_DIGITAL_PIN_VALUE).
 * @param command The ID of the command to attach a callback function to.
 * @param newFunction A reference to the callback function to attach.
 * @param context An optional context to be provided to the callback function (NULL by default).
 * @note The context parameter is provided so you can pass a parameter, by reference, to
 *       your callback function.
 */
void FirmataParser::attach(uint8_t command, callbackFunction newFunction, void * context)
{
  switch (command) {
    case ANALOG_MESSAGE:
      currentAnalogCallback = newFunction;
      currentAnalogCallbackContext = context;
      break;
    case DIGITAL_MESSAGE:
      currentDigitalCallback = newFunction;
      currentDigitalCallbackContext = context;
      break;
    case REPORT_ANALOG:
      currentReportAnalogCallback = newFunction;
      currentReportAnalogCallbackContext = context;
      break;
    case REPORT_DIGITAL:
      currentReportDigitalCallback = newFunction;
      currentReportDigitalCallbackContext = context;
      break;
    case SET_PIN_MODE:
      currentPinModeCallback = newFunction;
      currentPinModeCallbackContext = context;
      break;
    case SET_DIGITAL_PIN_VALUE:
      currentPinValueCallback = newFunction;
      currentPinValueCallbackContext = context;
      break;
  }
}

/**
 * Attach a version callback function (supported option: REPORT_FIRMWARE).
 * @param command The ID of the command to attach a callback function to.
 * @param newFunction A reference to the callback function to attach.
 * @param context An optional context to be provided to the callback function (NULL by default).
 * @note The context parameter is provided so you can pass a parameter, by reference, to
 *       your callback function.
 */
void FirmataParser::attach(uint8_t command, versionCallbackFunction newFunction, void * context)
{
  switch (command) {
    case REPORT_FIRMWARE:
      currentReportFirmwareCallback = newFunction;
      currentReportFirmwareCallbackContext = context;
      break;
  }
}

/**
 * Attach a system callback function (supported options are: SYSTEM_RESET, REPORT_VERSION).
 * @param command The ID of the command to attach a callback function to.
 * @param newFunction A reference to the callback function to attach.
 * @param context An optional context to be provided to the callback function (NULL by default).
 * @note The context parameter is provided so you can pass a parameter, by reference, to
 *       your callback function.
 */
void FirmataParser::attach(uint8_t command, systemCallbackFunction newFunction, void * context)
{
  switch (command) {
    case REPORT_VERSION:
      currentReportVersionCallback = newFunction;
      currentReportVersionCallbackContext = context;
      break;
    case SYSTEM_RESET:
      currentSystemResetCallback = newFunction;
      currentSystemResetCallbackContext = context;
      break;
  }
}

/**
 * Attach a callback function for the STRING_DATA command.
 * @param command Must be set to STRING_DATA or it will be ignored.
 * @param newFunction A reference to the string callback function to attach.
 * @param context An optional context to be provided to the callback function (NULL by default).
 * @note The context parameter is provided so you can pass a parameter, by reference, to
 *       your callback function.
 */
void FirmataParser::attach(uint8_t command, stringCallbackFunction newFunction, void * context)
{
  switch (command) {
    case STRING_DATA:
      currentStringCallback = newFunction;
      currentStringCallbackContext = context;
      break;
  }
}

/**
 * Attach a generic sysex callback function to sysex command.
 * @param command The ID of the command to attach a callback function to.
 * @param newFunction A reference to the sysex callback function to attach.
 * @param context An optional context to be provided to the callback function (NULL by default).
 * @note The context parameter is provided so you can pass a parameter, by reference, to
 *       your callback function.
 */
void FirmataParser::attach(uint8_t command, sysexCallbackFunction newFunction, void * context)
{
  (void)command;
  currentSysexCallback = newFunction;
  currentSysexCallbackContext = context;
}

/**
 * Attach a buffer overflow callback
 * @param newFunction A reference to the buffer overflow callback function to attach.
 * @param context An optional context to be provided to the callback function (NULL by default).
 * @note The context parameter is provided so you can pass a parameter, by reference, to
 *       your callback function.
 */
void FirmataParser::attach(dataBufferOverflowCallbackFunction newFunction, void * context)
{
  currentDataBufferOverflowCallback = newFunction;
  currentDataBufferOverflowCallbackContext = context;
}

/**
 * Detach a callback function for a specified command (such as SYSTEM_RESET, STRING_DATA,
 * ANALOG_MESSAGE, DIGITAL_MESSAGE, etc).
 * @param command The ID of the command to detatch the callback function from.
 */
void FirmataParser::detach(uint8_t command)
{
  switch (command) {
    case REPORT_FIRMWARE:
      attach(command, (versionCallbackFunction)NULL, NULL);
      break;
    case REPORT_VERSION:
    case SYSTEM_RESET:
      attach(command, (systemCallbackFunction)NULL, NULL);
      break;
    case STRING_DATA:
      attach(command, (stringCallbackFunction)NULL, NULL);
      break;
    case START_SYSEX:
      attach(command, (sysexCallbackFunction)NULL, NULL);
      break;
    default:
      attach(command, (callbackFunction)NULL, NULL);
      break;
  }
}

/**
 * Detach the buffer overflow callback
 * @param <unused> Any pointer of type dataBufferOverflowCallbackFunction.
 */
void FirmataParser::detach(dataBufferOverflowCallbackFunction)
{
  currentDataBufferOverflowCallback = (dataBufferOverflowCallbackFunction)NULL;
  currentDataBufferOverflowCallbackContext = (void *)NULL;
}

//******************************************************************************
//* Private Methods
//******************************************************************************

/**
 * Buffer abstraction to prevent memory corruption
 * @param data The byte to put into the buffer
 * @param pos The position to insert the byte into the buffer
 * @return writeError A boolean to indicate if an error occured
 * @private
 */
bool FirmataParser::bufferDataAtPosition(const uint8_t data, const size_t pos)
{
  bool bufferOverflow = (pos >= dataBufferSize);

  // Notify of overflow condition
  if ( bufferOverflow
  && ((dataBufferOverflowCallbackFunction)NULL != currentDataBufferOverflowCallback) )
  {
    allowBufferUpdate = true;
    currentDataBufferOverflowCallback(currentDataBufferOverflowCallbackContext);
    // Check if overflow was resolved during callback
    bufferOverflow = (pos >= dataBufferSize);
  }

  // Write data to buffer if no overflow condition persist
  if ( !bufferOverflow )
  {
    dataBuffer[pos] = data;
  }

  return bufferOverflow;
}

/**
 * Transform 7-bit firmata message into 8-bit stream
 * @param bytec The encoded data byte length of the message (max: 16383).
 * @param bytev A pointer to the encoded array of data bytes.
 * @return The length of the decoded data.
 * @note The conversion will be done in place on the provided buffer.
 * @private
 */
size_t FirmataParser::decodeByteStream(size_t bytec, uint8_t * bytev) {
  size_t decoded_bytes, i;

  for ( i = 0, decoded_bytes = 0 ; i < bytec ; ++decoded_bytes, ++i ) {
    bytev[decoded_bytes] = bytev[i];
    bytev[decoded_bytes] |= (uint8_t)(bytev[++i] << 7);
  }

  return decoded_bytes;
}

/**
 * Process incoming sysex messages. Handles REPORT_FIRMWARE and STRING_DATA internally.
 * Calls callback function for STRING_DATA and all other sysex messages.
 * @private
 */
void FirmataParser::processSysexMessage(void)
{
  switch (dataBuffer[0]) { //first byte in buffer is command
    case REPORT_FIRMWARE:
      if (currentReportFirmwareCallback) {
        const size_t major_version_offset = 1;
        const size_t minor_version_offset = 2;
        const size_t string_offset = 3;
        // Test for malformed REPORT_FIRMWARE message (used to query firmware prior to Firmata v3.0.0)
        if ( 3 > sysexBytesRead ) {
          (*currentReportFirmwareCallback)(currentReportFirmwareCallbackContext, 0, 0, (const char *)NULL);
        } else {
          const size_t end_of_string = (string_offset + decodeByteStream((sysexBytesRead - string_offset), &dataBuffer[string_offset]));
          bufferDataAtPosition('\0', end_of_string); // NULL terminate the string
          (*currentReportFirmwareCallback)(currentReportFirmwareCallbackContext, (size_t)dataBuffer[major_version_offset], (size_t)dataBuffer[minor_version_offset], (const char *)&dataBuffer[string_offset]);
        }
      }
      break;
    case STRING_DATA:
      if (currentStringCallback) {
        const size_t string_offset = 1;
        const size_t end_of_string = (string_offset + decodeByteStream((sysexBytesRead - string_offset), &dataBuffer[string_offset]));
        bufferDataAtPosition('\0', end_of_string); // NULL terminate the string
        (*currentStringCallback)(currentStringCallbackContext, (const char *)&dataBuffer[string_offset]);
      }
      break;
    default:
      if (currentSysexCallback)
        (*currentSysexCallback)(currentSysexCallbackContext, dataBuffer[0], sysexBytesRead - 1, dataBuffer + 1);
  }
}

/**
 * Resets the system state upon a SYSTEM_RESET message from the host software.
 * @private
 */
void FirmataParser::systemReset(void)
{
  size_t i;

  waitForData = 0; // this flag says the next serial input will be data
  executeMultiByteCommand = 0; // execute this after getting multi-byte data
  multiByteChannel = 0; // channel data for multiByteCommands

  for (i = 0; i < dataBufferSize; ++i) {
    dataBuffer[i] = 0;
  }

  parsingSysex = false;
  sysexBytesRead = 0;

  if (currentSystemResetCallback)
    (*currentSystemResetCallback)(currentSystemResetCallbackContext);
}
