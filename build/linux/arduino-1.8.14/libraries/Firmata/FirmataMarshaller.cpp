/*
  FirmataMarshaller.cpp
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

#include "FirmataMarshaller.h"

#if defined(__cplusplus) && !defined(ARDUINO)
  #include <cstring>
#else
  #include <string.h>
#endif

#include "FirmataConstants.h"

using namespace firmata;

//******************************************************************************
//* Support Functions
//******************************************************************************

/**
 * Request or halt a stream of analog readings from the Firmata host application. The range of pins is
 * limited to [0..15] when using the REPORT_ANALOG. The maximum result of the REPORT_ANALOG is limited to 14 bits
 * (16384). To increase the pin range or value, see the documentation for the EXTENDED_ANALOG
 * message.
 * @param pin The analog pin for which to request the value (limited to pins 0 - 15).
 * @param stream_enable A zero value will disable the stream, a non-zero will enable the stream
 * @note The maximum resulting value is 14-bits (16384).
 */
void FirmataMarshaller::reportAnalog(uint8_t pin, bool stream_enable)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  // pin can only be 0-15, so chop higher bits
  FirmataStream->write(REPORT_ANALOG | (pin & 0xF));
  FirmataStream->write(stream_enable);
}

/**
 * Request or halt an 8-bit port stream from the Firmata host application (protocol v2 and later).
 * Send 14-bits in a single digital message (protocol v1).
 * @param portNumber The port number for which to request the value. Note that this is not the same as a "port" on the
 * physical microcontroller. Ports are defined in order per every 8 pins in ascending order
 * of the Arduino digital pin numbering scheme. Port 0 = pins D0 - D7, port 1 = pins D8 - D15, etc.
 * @param stream_enable A zero value will disable the stream, a non-zero will enable the stream
 */
void FirmataMarshaller::reportDigitalPort(uint8_t portNumber, bool stream_enable)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(REPORT_DIGITAL | (portNumber & 0xF));
  FirmataStream->write(stream_enable);
}

/**
 * An alternative to the normal analog message, this extended version allows addressing beyond
 * pin 15 and supports sending analog values with any number of bits.
 * @param pin The analog pin to which the value is sent.
 * @param bytec The size of the storage for the analog value
 * @param bytev The pointer to the location of the analog value
 */
void FirmataMarshaller::sendExtendedAnalog(uint8_t pin, size_t bytec, uint8_t * bytev)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(START_SYSEX);
  FirmataStream->write(EXTENDED_ANALOG);
  FirmataStream->write(pin);
  encodeByteStream(bytec, bytev, bytec);
  FirmataStream->write(END_SYSEX);
}

/**
 * Transform 8-bit stream into 7-bit message
 * @param bytec The number of data bytes in the message.
 * @param bytev A pointer to the array of data bytes to send in the message.
 * @param max_bytes Force message to be n bytes, regardless of data bits.
 */
void FirmataMarshaller::encodeByteStream (size_t bytec, uint8_t * bytev, size_t max_bytes)
const
{
  static const size_t transmit_bits = 7;
  static const uint8_t transmit_mask = ((1 << transmit_bits) - 1);

  size_t bytes_sent = 0;
  size_t outstanding_bits = 0;
  uint8_t outstanding_bit_cache = *bytev;

  if ( !max_bytes ) { max_bytes = static_cast<size_t>(-1); }
  for (size_t i = 0 ; (i < bytec) && (bytes_sent < max_bytes) ; ++i) {
    uint8_t transmit_byte = (outstanding_bit_cache|(bytev[i] << outstanding_bits));
    FirmataStream->write(transmit_mask & transmit_byte);
    ++bytes_sent;
    outstanding_bit_cache = (bytev[i] >> (transmit_bits - outstanding_bits));
    outstanding_bits = (outstanding_bits + (8 - transmit_bits));
    for ( ; (outstanding_bits >= transmit_bits) && (bytes_sent < max_bytes) ; ) {
      transmit_byte = outstanding_bit_cache;
    FirmataStream->write(transmit_mask & transmit_byte);
      ++bytes_sent;
      outstanding_bit_cache >>= transmit_bits;
      outstanding_bits -= transmit_bits;
    }
  }
  if ( outstanding_bits && (bytes_sent < max_bytes) ) {
    FirmataStream->write(static_cast<uint8_t>((1 << outstanding_bits) - 1) & outstanding_bit_cache);
  }
}

//******************************************************************************
//* Constructors
//******************************************************************************

/**
 * The FirmataMarshaller class.
 */
FirmataMarshaller::FirmataMarshaller()
:
  FirmataStream((Stream *)NULL)
{
}

//******************************************************************************
//* Public Methods
//******************************************************************************

/**
 * Reassign the Firmata stream transport.
 * @param s A reference to the Stream transport object. This can be any type of
 * transport that implements the Stream interface. Some examples include Ethernet, WiFi
 * and other UARTs on the board (Serial1, Serial2, etc).
 */
void FirmataMarshaller::begin(Stream &s)
{
  FirmataStream = &s;
}

/**
 * Closes the FirmataMarshaller stream by setting its stream reference to `(Stream *)NULL`
 */
void FirmataMarshaller::end(void)
{
  FirmataStream = (Stream *)NULL;
}

//******************************************************************************
//* Output Stream Handling
//******************************************************************************

/**
 * Query the target's firmware name and version
 */
void FirmataMarshaller::queryFirmwareVersion(void)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(START_SYSEX);
  FirmataStream->write(REPORT_FIRMWARE);
  FirmataStream->write(END_SYSEX);
}

/**
 * Query the target's Firmata protocol version
 */
void FirmataMarshaller::queryVersion(void)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(REPORT_VERSION);
}

/**
 * Halt the stream of analog readings from the Firmata host application. The range of pins is
 * limited to [0..15] when using the REPORT_ANALOG. The maximum result of the REPORT_ANALOG is limited to 14 bits
 * (16384). To increase the pin range or value, see the documentation for the EXTENDED_ANALOG
 * message.
 * @param pin The analog pin for which to request the value (limited to pins 0 - 15).
 */
void FirmataMarshaller::reportAnalogDisable(uint8_t pin)
const
{
  reportAnalog(pin, false);
}

/**
 * Request a stream of analog readings from the Firmata host application. The range of pins is
 * limited to [0..15] when using the REPORT_ANALOG. The maximum result of the REPORT_ANALOG is limited to 14 bits
 * (16384). To increase the pin range or value, see the documentation for the EXTENDED_ANALOG
 * message.
 * @param pin The analog pin for which to request the value (limited to pins 0 - 15).
 */
void FirmataMarshaller::reportAnalogEnable(uint8_t pin)
const
{
  reportAnalog(pin, true);
}

/**
 * Halt an 8-bit port stream from the Firmata host application (protocol v2 and later).
 * Send 14-bits in a single digital message (protocol v1).
 * @param portNumber The port number for which to request the value. Note that this is not the same as a "port" on the
 * physical microcontroller. Ports are defined in order per every 8 pins in ascending order
 * of the Arduino digital pin numbering scheme. Port 0 = pins D0 - D7, port 1 = pins D8 - D15, etc.
 */
void FirmataMarshaller::reportDigitalPortDisable(uint8_t portNumber)
const
{
  reportDigitalPort(portNumber, false);
}

/**
 * Request an 8-bit port stream from the Firmata host application (protocol v2 and later).
 * Send 14-bits in a single digital message (protocol v1).
 * @param portNumber The port number for which to request the value. Note that this is not the same as a "port" on the
 * physical microcontroller. Ports are defined in order per every 8 pins in ascending order
 * of the Arduino digital pin numbering scheme. Port 0 = pins D0 - D7, port 1 = pins D8 - D15, etc.
 */
void FirmataMarshaller::reportDigitalPortEnable(uint8_t portNumber)
const
{
  reportDigitalPort(portNumber, true);
}

/**
 * Send an analog message to the Firmata host application. The range of pins is limited to [0..15]
 * when using the ANALOG_MESSAGE. The maximum value of the ANALOG_MESSAGE is limited to 14 bits
 * (16384). To increase the pin range or value, see the documentation for the EXTENDED_ANALOG
 * message.
 * @param pin The analog pin to which the value is sent.
 * @param value The value of the analog pin (0 - 1024 for 10-bit analog, 0 - 4096 for 12-bit, etc).
 * @note The maximum value is 14-bits (16384).
 */
void FirmataMarshaller::sendAnalog(uint8_t pin, uint16_t value)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  if ( (0xF >= pin) && (0x3FFF >= value) ) {
    FirmataStream->write(ANALOG_MESSAGE|pin);
    encodeByteStream(sizeof(value), reinterpret_cast<uint8_t *>(&value), sizeof(value));
  } else {
    sendExtendedAnalog(pin, sizeof(value), reinterpret_cast<uint8_t *>(&value));
  }
}

/**
 * Send an analog mapping query to the Firmata host application. The resulting sysex message will
 * have an ANALOG_MAPPING_RESPONSE command byte, followed by a list of pins [0-n]; where each
 * pin will specify its corresponding analog pin number or 0x7F (127) if not applicable.
 */
void FirmataMarshaller::sendAnalogMappingQuery(void)
const
{
  sendSysex(ANALOG_MAPPING_QUERY, 0, NULL);
}

/**
 * Send a capability query to the Firmata host application. The resulting sysex message will have
 * a CAPABILITY_RESPONSE command byte, followed by a list of byte tuples (mode and mode resolution)
 * for each pin; where each pin list is terminated by 0x7F (127).
 */
void FirmataMarshaller::sendCapabilityQuery(void)
const
{
  sendSysex(CAPABILITY_QUERY, 0, NULL);
}

/**
 * Send a single digital pin value to the Firmata host application.
 * @param pin The digital pin to send the value of.
 * @param value The value of the pin.
 */
void FirmataMarshaller::sendDigital(uint8_t pin, uint8_t value)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(SET_DIGITAL_PIN_VALUE);
  FirmataStream->write(pin & 0x7F);
  FirmataStream->write(value != 0);
}


/**
 * Send an 8-bit port in a single digital message (protocol v2 and later).
 * Send 14-bits in a single digital message (protocol v1).
 * @param portNumber The port number to send. Note that this is not the same as a "port" on the
 * physical microcontroller. Ports are defined in order per every 8 pins in ascending order
 * of the Arduino digital pin numbering scheme. Port 0 = pins D0 - D7, port 1 = pins D8 - D15, etc.
 * @param portData The value of the port. The value of each pin in the port is represented by a bit.
 */
void FirmataMarshaller::sendDigitalPort(uint8_t portNumber, uint16_t portData)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(DIGITAL_MESSAGE | (portNumber & 0xF));
  // Tx bits  0-6 (protocol v1 and higher)
  // Tx bits 7-13 (bit 7 only for protocol v2 and higher)
  encodeByteStream(sizeof(portData), reinterpret_cast<uint8_t *>(&portData), sizeof(portData));
}

/**
 * Sends the firmware name and version to the Firmata host application.
 * @param major The major verison number
 * @param minor The minor version number
 * @param bytec The length of the firmware name
 * @param bytev The firmware name array
 */
void FirmataMarshaller::sendFirmwareVersion(uint8_t major, uint8_t minor, size_t bytec, uint8_t *bytev)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  size_t i;
  FirmataStream->write(START_SYSEX);
  FirmataStream->write(REPORT_FIRMWARE);
  FirmataStream->write(major);
  FirmataStream->write(minor);
  for (i = 0; i < bytec; ++i) {
    encodeByteStream(sizeof(bytev[i]), reinterpret_cast<uint8_t *>(&bytev[i]));
  }
  FirmataStream->write(END_SYSEX);
}

/**
 * Send the Firmata protocol version to the Firmata host application.
 * @param major The major verison number
 * @param minor The minor version number
 */
void FirmataMarshaller::sendVersion(uint8_t major, uint8_t minor)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(REPORT_VERSION);
  FirmataStream->write(major);
  FirmataStream->write(minor);
}

/**
 * Send the pin mode/configuration. The pin configuration (or mode) in Firmata represents the
 * current function of the pin. Examples are digital input or output, analog input, pwm, i2c,
 * serial (uart), etc.
 * @param pin The pin to configure.
 * @param config The configuration value for the specified pin.
 */
void FirmataMarshaller::sendPinMode(uint8_t pin, uint8_t config)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(SET_PIN_MODE);
  FirmataStream->write(pin);
  FirmataStream->write(config);
}

/**
 * Send a pin state query to the Firmata host application. The resulting sysex message will have
 * a PIN_STATE_RESPONSE command byte, followed by the pin number, the pin mode and a stream of
 * bits to indicate any *data* written to the pin (pin state).
 * @param pin The pin to query
 * @note The pin state is any data written to the pin (i.e. pin state != pin value)
 */
void FirmataMarshaller::sendPinStateQuery(uint8_t pin)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(START_SYSEX);
  FirmataStream->write(PIN_STATE_QUERY);
  FirmataStream->write(pin);
  FirmataStream->write(END_SYSEX);
}

/**
 * Send a sysex message where all values after the command byte are packet as 2 7-bit bytes
 * (this is not always the case so this function is not always used to send sysex messages).
 * @param command The sysex command byte.
 * @param bytec The number of data bytes in the message (excludes start, command and end bytes).
 * @param bytev A pointer to the array of data bytes to send in the message.
 */
void FirmataMarshaller::sendSysex(uint8_t command, size_t bytec, uint8_t *bytev)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  size_t i;
  FirmataStream->write(START_SYSEX);
  FirmataStream->write(command);
  for (i = 0; i < bytec; ++i) {
    encodeByteStream(sizeof(bytev[i]), reinterpret_cast<uint8_t *>(&bytev[i]));
  }
  FirmataStream->write(END_SYSEX);
}

/**
 * Send a string to the Firmata host application.
 * @param string A pointer to the char string
 */
void FirmataMarshaller::sendString(const char *string)
const
{
  sendSysex(STRING_DATA, strlen(string), reinterpret_cast<uint8_t *>(const_cast<char *>(string)));
}

/**
 * The sampling interval sets how often analog data and i2c data is reported to the client.
 * @param interval_ms The interval (in milliseconds) at which to sample
 * @note The default sampling interval is 19ms
 */
void FirmataMarshaller::setSamplingInterval(uint16_t interval_ms)
const
{
  sendSysex(SAMPLING_INTERVAL, sizeof(interval_ms), reinterpret_cast<uint8_t *>(&interval_ms));
}

/**
 * Perform a software reset on the target. For example, StandardFirmata.ino will initialize
 * everything to a known state and reset the parsing buffer.
 */
void FirmataMarshaller::systemReset(void)
const
{
  if ( (Stream *)NULL == FirmataStream ) { return; }
  FirmataStream->write(SYSTEM_RESET);
}
