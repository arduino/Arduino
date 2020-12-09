/*
  Firmata.cpp - Firmata library v2.5.8 - 2018-04-15
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2009-2017 Jeff Hoefs.  All rights reserved.

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

#include <string.h>
#include <stdlib.h>

using namespace firmata;

//******************************************************************************
//* Static Members
//******************************************************************************
// make one instance for the user to use
FirmataClass Firmata;

/* callback functions */
callbackFunction FirmataClass::currentAnalogCallback = (callbackFunction)NULL;
callbackFunction FirmataClass::currentDigitalCallback = (callbackFunction)NULL;
callbackFunction FirmataClass::currentPinModeCallback = (callbackFunction)NULL;
callbackFunction FirmataClass::currentPinValueCallback = (callbackFunction)NULL;
callbackFunction FirmataClass::currentReportAnalogCallback = (callbackFunction)NULL;
callbackFunction FirmataClass::currentReportDigitalCallback = (callbackFunction)NULL;
stringCallbackFunction FirmataClass::currentStringCallback = (stringCallbackFunction)NULL;
sysexCallbackFunction FirmataClass::currentSysexCallback = (sysexCallbackFunction)NULL;
systemCallbackFunction FirmataClass::currentSystemResetCallback = (systemCallbackFunction)NULL;

//******************************************************************************
//* Support Functions
//******************************************************************************

/**
 * Split a 16-bit byte into two 7-bit values and write each value.
 * @param value The 16-bit value to be split and written separately.
 */
void FirmataClass::sendValueAsTwo7bitBytes(int value)
{
  marshaller.encodeByteStream(sizeof(value), reinterpret_cast<uint8_t *>(&value), sizeof(value));
}

/**
 * A helper method to write the beginning of a Sysex message transmission.
 */
void FirmataClass::startSysex(void)
{
  FirmataStream->write(START_SYSEX);
}

/**
 * A helper method to write the end of a Sysex message transmission.
 */
void FirmataClass::endSysex(void)
{
  FirmataStream->write(END_SYSEX);
}

//******************************************************************************
//* Constructors
//******************************************************************************

/**
 * The Firmata class.
 * An instance named "Firmata" is created automatically for the user.
 */
FirmataClass::FirmataClass()
:
  parser(FirmataParser(parserBuffer, MAX_DATA_BYTES))
{
  firmwareVersionCount = 0;
  firmwareVersionVector = 0;
  blinkVersionDisabled = false;

  // Establish callback translation to parser callbacks
  parser.attach(ANALOG_MESSAGE, (FirmataParser::callbackFunction)staticAnalogCallback, (void *)NULL);
  parser.attach(DIGITAL_MESSAGE, (FirmataParser::callbackFunction)staticDigitalCallback, (void *)NULL);
  parser.attach(REPORT_ANALOG, (FirmataParser::callbackFunction)staticReportAnalogCallback, (void *)NULL);
  parser.attach(REPORT_DIGITAL, (FirmataParser::callbackFunction)staticReportDigitalCallback, (void *)NULL);
  parser.attach(SET_PIN_MODE, (FirmataParser::callbackFunction)staticPinModeCallback, (void *)NULL);
  parser.attach(SET_DIGITAL_PIN_VALUE, (FirmataParser::callbackFunction)staticPinValueCallback, (void *)NULL);
  parser.attach(STRING_DATA, (FirmataParser::stringCallbackFunction)staticStringCallback, (void *)NULL);
  parser.attach(START_SYSEX, (FirmataParser::sysexCallbackFunction)staticSysexCallback, (void *)NULL);
  parser.attach(REPORT_FIRMWARE, (FirmataParser::versionCallbackFunction)staticReportFirmwareCallback, this);
  parser.attach(REPORT_VERSION, (FirmataParser::systemCallbackFunction)staticReportVersionCallback, this);
  parser.attach(SYSTEM_RESET, (FirmataParser::systemCallbackFunction)staticSystemResetCallback, (void *)NULL);
}

//******************************************************************************
//* Public Methods
//******************************************************************************

/**
 * Initialize the default Serial transport at the default baud of 57600.
 */
void FirmataClass::begin(void)
{
  begin(57600);
}

/**
 * Initialize the default Serial transport and override the default baud.
 * Sends the protocol version to the host application followed by the firmware version and name.
 * blinkVersion is also called. To skip the call to blinkVersion, call Firmata.disableBlinkVersion()
 * before calling Firmata.begin(baud).
 * @param speed The baud to use. 57600 baud is the default value.
 */
void FirmataClass::begin(long speed)
{
  Serial.begin(speed);
  blinkVersion();
  begin(Serial);
}

/**
 * Reassign the Firmata stream transport.
 * @param s A reference to the Stream transport object. This can be any type of
 * transport that implements the Stream interface. Some examples include Ethernet, WiFi
 * and other UARTs on the board (Serial1, Serial2, etc).
 */
void FirmataClass::begin(Stream &s)
{
  FirmataStream = &s;
  marshaller.begin(s);
  // do not call blinkVersion() here because some hardware such as the
  // Ethernet shield use pin 13
  printVersion();         // send the protocol version
  printFirmwareVersion(); // send the firmware name and version
}

/**
 * Send the Firmata protocol version to the Firmata host application.
 */
void FirmataClass::printVersion(void)
{
  marshaller.sendVersion(FIRMATA_PROTOCOL_MAJOR_VERSION, FIRMATA_PROTOCOL_MINOR_VERSION);
}

/**
 * Blink the Firmata protocol version to the onboard LEDs (if the board has an onboard LED).
 * If VERSION_BLINK_PIN is not defined in Boards.h for a particular board, then this method
 * does nothing.
 * The first series of flashes indicates the firmware major version (2 flashes = 2).
 * The second series of flashes indicates the firmware minor version (5 flashes = 5).
 */
void FirmataClass::blinkVersion(void)
{
#if defined(VERSION_BLINK_PIN)
  if (blinkVersionDisabled) return;
  // flash the pin with the protocol version
  pinMode(VERSION_BLINK_PIN, OUTPUT);
  strobeBlinkPin(VERSION_BLINK_PIN, FIRMATA_FIRMWARE_MAJOR_VERSION, 40, 210);
  delay(250);
  strobeBlinkPin(VERSION_BLINK_PIN, FIRMATA_FIRMWARE_MINOR_VERSION, 40, 210);
  delay(125);
#endif
}

/**
 * Provides a means to disable the version blink sequence on the onboard LED, trimming startup
 * time by a couple of seconds.
 * Call this before Firmata.begin(). It only applies when using the default Serial transport.
 */
void FirmataClass::disableBlinkVersion()
{
  blinkVersionDisabled = true;
}

/**
 * Sends the firmware name and version to the Firmata host application. The major and minor version
 * numbers are the first 2 bytes in the message. The following bytes are the characters of the
 * firmware name.
 */
void FirmataClass::printFirmwareVersion(void)
{
  if (firmwareVersionCount) { // make sure that the name has been set before reporting
    marshaller.sendFirmwareVersion(static_cast<uint8_t>(firmwareVersionVector[0]), static_cast<uint8_t>(firmwareVersionVector[1]), (firmwareVersionCount - 2), reinterpret_cast<uint8_t *>(&firmwareVersionVector[2]));
  }
}

/**
 * Sets the name and version of the firmware. This is not the same version as the Firmata protocol
 * (although at times the firmware version and protocol version may be the same number).
 * @param name A pointer to the name char array
 * @param major The major version number
 * @param minor The minor version number
 */
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

/**
 * A wrapper for Stream::available()
 * @return The number of bytes remaining in the input stream buffer.
 */
int FirmataClass::available(void)
{
  return FirmataStream->available();
}

/**
 * Read a single int from the input stream. If the value is not = -1, pass it on to parse(byte)
 */
void FirmataClass::processInput(void)
{
  int inputData = FirmataStream->read(); // this is 'int' to handle -1 when no data
  if (inputData != -1) {
    parser.parse(inputData);
  }
}

/**
 * Parse data from the input stream.
 * @param inputData A single byte to be added to the parser.
 */
void FirmataClass::parse(byte inputData)
{
    parser.parse(inputData);
}

/**
 * @return Returns true if the parser is actively parsing data.
 */
boolean FirmataClass::isParsingMessage(void)
{
  return parser.isParsingMessage();
}

//------------------------------------------------------------------------------
// Output Stream Handling

/**
 * Send an analog message to the Firmata host application. The range of pins is limited to [0..15]
 * when using the ANALOG_MESSAGE. The maximum value of the ANALOG_MESSAGE is limited to 14 bits
 * (16384). To increase the pin range or value, see the documentation for the EXTENDED_ANALOG
 * message.
 * @param pin The analog pin to send the value of (limited to pins 0 - 15).
 * @param value The value of the analog pin (0 - 1024 for 10-bit analog, 0 - 4096 for 12-bit, etc).
 * The maximum value is 14-bits (16384).
 */
void FirmataClass::sendAnalog(byte pin, int value)
{
  marshaller.sendAnalog(pin, value);
}

/* (intentionally left out asterix here)
 * STUB - NOT IMPLEMENTED
 * Send a single digital pin value to the Firmata host application.
 * @param pin The digital pin to send the value of.
 * @param value The value of the pin.
 */
void FirmataClass::sendDigital(byte pin, int value)
{
  (void)pin;
  (void)value;
  /* TODO add single pin digital messages to the protocol, this needs to
   * track the last digital data sent so that it can be sure to change just
   * one bit in the packet.  This is complicated by the fact that the
   * numbering of the pins will probably differ on Arduino, Wiring, and
   * other boards.
   */

  // TODO: the digital message should not be sent on the serial port every
  // time sendDigital() is called.  Instead, it should add it to an int
  // which will be sent on a schedule.  If a pin changes more than once
  // before the digital message is sent on the serial port, it should send a
  // digital message for each change.

  //    if(value == 0)
  //        sendDigitalPortPair();
}


/**
 * Send an 8-bit port in a single digital message (protocol v2 and later).
 * Send 14-bits in a single digital message (protocol v1).
 * @param portNumber The port number to send. Note that this is not the same as a "port" on the
 * physical microcontroller. Ports are defined in order per every 8 pins in ascending order
 * of the Arduino digital pin numbering scheme. Port 0 = pins D0 - D7, port 1 = pins D8 - D15, etc.
 * @param portData The value of the port. The value of each pin in the port is represented by a bit.
 */
void FirmataClass::sendDigitalPort(byte portNumber, int portData)
{
  marshaller.sendDigitalPort(portNumber, portData);
}

/**
 * Send a sysex message where all values after the command byte are packet as 2 7-bit bytes
 * (this is not always the case so this function is not always used to send sysex messages).
 * @param command The sysex command byte.
 * @param bytec The number of data bytes in the message (excludes start, command and end bytes).
 * @param bytev A pointer to the array of data bytes to send in the message.
 */
void FirmataClass::sendSysex(byte command, byte bytec, byte *bytev)
{
  marshaller.sendSysex(command, bytec, bytev);
}

/**
 * Send a string to the Firmata host application.
 * @param command Must be STRING_DATA
 * @param string A pointer to the char string
 */
void FirmataClass::sendString(byte command, const char *string)
{
  if (command == STRING_DATA) {
    marshaller.sendString(string);
  }
}

/**
 * Send a string to the Firmata host application.
 * @param string A pointer to the char string
 */
void FirmataClass::sendString(const char *string)
{
  marshaller.sendString(string);
}

/**
 * A wrapper for Stream::available().
 * Write a single byte to the output stream.
 * @param c The byte to be written.
 */
void FirmataClass::write(byte c)
{
  FirmataStream->write(c);
}

/**
 * Attach a generic sysex callback function to a command (options are: ANALOG_MESSAGE,
 * DIGITAL_MESSAGE, REPORT_ANALOG, REPORT DIGITAL, SET_PIN_MODE and SET_DIGITAL_PIN_VALUE).
 * @param command The ID of the command to attach a callback function to.
 * @param newFunction A reference to the callback function to attach.
 */
void FirmataClass::attach(uint8_t command, ::callbackFunction newFunction)
{
  switch (command) {
    case ANALOG_MESSAGE:
      currentAnalogCallback = newFunction;
      break;
    case DIGITAL_MESSAGE:
      currentDigitalCallback = newFunction;
      break;
    case REPORT_ANALOG:
      currentReportAnalogCallback = newFunction;
      break;
    case REPORT_DIGITAL:
      currentReportDigitalCallback = newFunction;
      break;
    case SET_PIN_MODE:
      currentPinModeCallback = newFunction;
      break;
    case SET_DIGITAL_PIN_VALUE:
      currentPinValueCallback = newFunction;
      break;
  }
}

/**
 * Attach a callback function for the SYSTEM_RESET command.
 * @param command Must be set to SYSTEM_RESET or it will be ignored.
 * @param newFunction A reference to the system reset callback function to attach.
 */
void FirmataClass::attach(uint8_t command, systemCallbackFunction newFunction)
{
  switch (command) {
    case SYSTEM_RESET:
      currentSystemResetCallback = newFunction;
      break;
  }
}

/**
 * Attach a callback function for the STRING_DATA command.
 * @param command Must be set to STRING_DATA or it will be ignored.
 * @param newFunction A reference to the string callback function to attach.
 */
void FirmataClass::attach(uint8_t command, stringCallbackFunction newFunction)
{
  switch (command) {
    case STRING_DATA:
      currentStringCallback = newFunction;
      break;
  }
}

/**
 * Attach a generic sysex callback function to sysex command.
 * @param command The ID of the command to attach a callback function to.
 * @param newFunction A reference to the sysex callback function to attach.
 */
void FirmataClass::attach(uint8_t command, sysexCallbackFunction newFunction)
{
  (void)command;
  currentSysexCallback = newFunction;
}

/**
 * Detach a callback function for a specified command (such as SYSTEM_RESET, STRING_DATA,
 * ANALOG_MESSAGE, DIGITAL_MESSAGE, etc).
 * @param command The ID of the command to detatch the callback function from.
 */
void FirmataClass::detach(uint8_t command)
{
  switch (command) {
    case SYSTEM_RESET:
      attach(command, (systemCallbackFunction)NULL);
      break;
    case STRING_DATA:
      attach(command, (stringCallbackFunction)NULL);
      break;
    case START_SYSEX:
      attach(command, (sysexCallbackFunction)NULL);
      break;
    default:
      attach(command, (callbackFunction)NULL);
      break;
  }
}

/**
 * @param pin The pin to get the configuration of.
 * @return The configuration of the specified pin.
 */
byte FirmataClass::getPinMode(byte pin)
{
  return pinConfig[pin];
}

/**
 * Set the pin mode/configuration. The pin configuration (or mode) in Firmata represents the
 * current function of the pin. Examples are digital input or output, analog input, pwm, i2c,
 * serial (uart), etc.
 * @param pin The pin to configure.
 * @param config The configuration value for the specified pin.
 */
void FirmataClass::setPinMode(byte pin, byte config)
{
  if (pinConfig[pin] == PIN_MODE_IGNORE)
    return;

  pinConfig[pin] = config;
}

/**
 * @param pin The pin to get the state of.
 * @return The state of the specified pin.
 */
int FirmataClass::getPinState(byte pin)
{
  return pinState[pin];
}

/**
 * Set the pin state. The pin state of an output pin is the pin value. The state of an
 * input pin is 0, unless the pin has it's internal pull up resistor enabled, then the value is 1.
 * @param pin The pin to set the state of
 * @param state Set the state of the specified pin
 */
void FirmataClass::setPinState(byte pin, int state)
{
  pinState[pin] = state;
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

/**
 * Flashing the pin for the version number
 * @private
 * @param pin The pin the LED is attached to.
 * @param count The number of times to flash the LED.
 * @param onInterval The number of milliseconds for the LED to be ON during each interval.
 * @param offInterval The number of milliseconds for the LED to be OFF during each interval.
 */
void FirmataClass::strobeBlinkPin(byte pin, int count, int onInterval, int offInterval)
{
  byte i;
  for (i = 0; i < count; i++) {
    delay(offInterval);
    digitalWrite(pin, HIGH);
    delay(onInterval);
    digitalWrite(pin, LOW);
  }
}

