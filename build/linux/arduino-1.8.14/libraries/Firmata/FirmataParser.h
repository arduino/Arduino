/*
  FirmataParser.h
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2009-2016 Jeff Hoefs.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef FirmataParser_h
#define FirmataParser_h

#if defined(__cplusplus) && !defined(ARDUINO)
  #include <cstddef>
  #include <cstdint>
#else
  #include <stddef.h>
  #include <stdint.h>
#endif

namespace firmata {

class FirmataParser
{
  public:
    /* callback function types */
    typedef void (*callbackFunction)(void * context, uint8_t command, uint16_t value);
    typedef void (*dataBufferOverflowCallbackFunction)(void * context);
    typedef void (*stringCallbackFunction)(void * context, const char * c_str);
    typedef void (*sysexCallbackFunction)(void * context, uint8_t command, size_t argc, uint8_t * argv);
    typedef void (*systemCallbackFunction)(void * context);
    typedef void (*versionCallbackFunction)(void * context, size_t sv_major, size_t sv_minor, const char * firmware);

    FirmataParser(uint8_t * dataBuffer = (uint8_t *)NULL, size_t dataBufferSize = 0);

    /* serial receive handling */
    void parse(uint8_t value);
    bool isParsingMessage(void) const;
    int setDataBufferOfSize(uint8_t * dataBuffer, size_t dataBufferSize);

    /* attach & detach callback functions to messages */
    void attach(uint8_t command, callbackFunction newFunction, void * context = NULL);
    void attach(dataBufferOverflowCallbackFunction newFunction, void * context = NULL);
    void attach(uint8_t command, stringCallbackFunction newFunction, void * context = NULL);
    void attach(uint8_t command, sysexCallbackFunction newFunction, void * context = NULL);
    void attach(uint8_t command, systemCallbackFunction newFunction, void * context = NULL);
    void attach(uint8_t command, versionCallbackFunction newFunction, void * context = NULL);
    void detach(uint8_t command);
    void detach(dataBufferOverflowCallbackFunction);

  private:
    /* input message handling */
    bool allowBufferUpdate;
    uint8_t * dataBuffer; // multi-byte data
    size_t dataBufferSize;
    uint8_t executeMultiByteCommand; // execute this after getting multi-byte data
    uint8_t multiByteChannel; // channel data for multiByteCommands
    size_t waitForData; // this flag says the next serial input will be data

    /* sysex */
    bool parsingSysex;
    size_t sysexBytesRead;

    /* callback context */
    void * currentAnalogCallbackContext;
    void * currentDigitalCallbackContext;
    void * currentReportAnalogCallbackContext;
    void * currentReportDigitalCallbackContext;
    void * currentPinModeCallbackContext;
    void * currentPinValueCallbackContext;
    void * currentReportFirmwareCallbackContext;
    void * currentReportVersionCallbackContext;
    void * currentDataBufferOverflowCallbackContext;
    void * currentStringCallbackContext;
    void * currentSysexCallbackContext;
    void * currentSystemResetCallbackContext;

    /* callback functions */
    callbackFunction currentAnalogCallback;
    callbackFunction currentDigitalCallback;
    callbackFunction currentReportAnalogCallback;
    callbackFunction currentReportDigitalCallback;
    callbackFunction currentPinModeCallback;
    callbackFunction currentPinValueCallback;
    dataBufferOverflowCallbackFunction currentDataBufferOverflowCallback;
    stringCallbackFunction currentStringCallback;
    sysexCallbackFunction currentSysexCallback;
    versionCallbackFunction currentReportFirmwareCallback;
    systemCallbackFunction currentReportVersionCallback;
    systemCallbackFunction currentSystemResetCallback;

    /* private methods ------------------------------ */
    bool bufferDataAtPosition(const uint8_t data, const size_t pos);
    size_t decodeByteStream(size_t bytec, uint8_t * bytev);
    void processSysexMessage(void);
    void systemReset(void);
};

} // firmata

#endif /* FirmataParser_h */
