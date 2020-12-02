/*
  FirmataMarshaller.h
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2009-2016 Jeff Hoefs.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef FirmataMarshaller_h
#define FirmataMarshaller_h

#if defined(__cplusplus) && !defined(ARDUINO)
  #include <cstddef>
  #include <cstdint>
#else
  #include <stddef.h>
  #include <stdint.h>
#endif

#include <Stream.h>

namespace firmata {

class FirmataMarshaller
{
    friend class FirmataClass;

  public:
    /* constructors */
    FirmataMarshaller();

    /* public methods */
    void begin(Stream &s);
    void end();

    /* serial send handling */
    void queryFirmwareVersion(void) const;
    void queryVersion(void) const;
    void reportAnalogDisable(uint8_t pin) const;
    void reportAnalogEnable(uint8_t pin) const;
    void reportDigitalPortDisable(uint8_t portNumber) const;
    void reportDigitalPortEnable(uint8_t portNumber) const;
    void sendAnalog(uint8_t pin, uint16_t value) const;
    void sendAnalogMappingQuery(void) const;
    void sendCapabilityQuery(void) const;
    void sendDigital(uint8_t pin, uint8_t value) const;
    void sendDigitalPort(uint8_t portNumber, uint16_t portData) const;
    void sendFirmwareVersion(uint8_t major, uint8_t minor, size_t bytec, uint8_t *bytev) const;
    void sendVersion(uint8_t major, uint8_t minor) const;
    void sendPinMode(uint8_t pin, uint8_t config) const;
    void sendPinStateQuery(uint8_t pin) const;
    void sendString(const char *string) const;
    void sendSysex(uint8_t command, size_t bytec, uint8_t *bytev) const;
    void setSamplingInterval(uint16_t interval_ms) const;
    void systemReset(void) const;

  private:
    /* utility methods */
    void reportAnalog(uint8_t pin, bool stream_enable) const;
    void reportDigitalPort(uint8_t portNumber, bool stream_enable) const;
    void sendExtendedAnalog(uint8_t pin, size_t bytec, uint8_t * bytev) const;
    void encodeByteStream (size_t bytec, uint8_t * bytev, size_t max_bytes = 0) const;

    Stream * FirmataStream;
};

} // namespace firmata

#endif /* FirmataMarshaller_h */

