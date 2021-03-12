/*
  SerialFirmata.cpp
  Copyright (C) 2016 Jeff Hoefs. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.

  This version of SerialFirmata.cpp differs from the ConfigurableFirmata
  version in the following ways:

  - handlePinMode calls Firmata::setPinMode

  Last updated October 16th, 2016
*/

#include "SerialFirmata.h"

SerialFirmata::SerialFirmata()
{
#if defined(SoftwareSerial_h)
  swSerial0 = NULL;
  swSerial1 = NULL;
  swSerial2 = NULL;
  swSerial3 = NULL;
#endif

  serialIndex = -1;
}

boolean SerialFirmata::handlePinMode(byte pin, int mode)
{
  // used for both HW and SW serial
  if (mode == PIN_MODE_SERIAL) {
    Firmata.setPinMode(pin, PIN_MODE_SERIAL);
    return true;
  }
  return false;
}

void SerialFirmata::handleCapability(byte pin)
{
  if (IS_PIN_SERIAL(pin)) {
    Firmata.write(PIN_MODE_SERIAL);
    Firmata.write(getSerialPinType(pin));
  }
}

boolean SerialFirmata::handleSysex(byte command, byte argc, byte *argv)
{
  if (command == SERIAL_MESSAGE) {

    Stream *serialPort;
    byte mode = argv[0] & SERIAL_MODE_MASK;
    byte portId = argv[0] & SERIAL_PORT_ID_MASK;

    switch (mode) {
      case SERIAL_CONFIG:
        {
          long baud = (long)argv[1] | ((long)argv[2] << 7) | ((long)argv[3] << 14);
          serial_pins pins;

          if (portId < 8) {
            serialPort = getPortFromId(portId);
            if (serialPort != NULL) {
              pins = getSerialPinNumbers(portId);
              if (pins.rx != 0 && pins.tx != 0) {
                Firmata.setPinMode(pins.rx, PIN_MODE_SERIAL);
                Firmata.setPinMode(pins.tx, PIN_MODE_SERIAL);
                // Fixes an issue where some serial devices would not work properly with Arduino Due
                // because all Arduino pins are set to OUTPUT by default in StandardFirmata.
                pinMode(pins.rx, INPUT);
              }
              ((HardwareSerial*)serialPort)->begin(baud);
            }
          } else {
#if defined(SoftwareSerial_h)
            byte swTxPin, swRxPin;
            if (argc > 4) {
              swRxPin = argv[4];
              swTxPin = argv[5];
            } else {
              // RX and TX pins must be specified when using SW serial
              Firmata.sendString("Specify serial RX and TX pins");
              return false;
            }
            switch (portId) {
              case SW_SERIAL0:
                if (swSerial0 == NULL) {
                  swSerial0 = new SoftwareSerial(swRxPin, swTxPin);
                }
                break;
              case SW_SERIAL1:
                if (swSerial1 == NULL) {
                  swSerial1 = new SoftwareSerial(swRxPin, swTxPin);
                }
                break;
              case SW_SERIAL2:
                if (swSerial2 == NULL) {
                  swSerial2 = new SoftwareSerial(swRxPin, swTxPin);
                }
                break;
              case SW_SERIAL3:
                if (swSerial3 == NULL) {
                  swSerial3 = new SoftwareSerial(swRxPin, swTxPin);
                }
                break;
            }
            serialPort = getPortFromId(portId);
            if (serialPort != NULL) {
              Firmata.setPinMode(swRxPin, PIN_MODE_SERIAL);
              Firmata.setPinMode(swTxPin, PIN_MODE_SERIAL);
              ((SoftwareSerial*)serialPort)->begin(baud);
            }
#endif
          }
          break; // SERIAL_CONFIG
        }
      case SERIAL_WRITE:
        {
          byte data;
          serialPort = getPortFromId(portId);
          if (serialPort == NULL) {
            break;
          }
          for (byte i = 1; i < argc; i += 2) {
            data = argv[i] + (argv[i + 1] << 7);
            serialPort->write(data);
          }
          break; // SERIAL_WRITE
        }
      case SERIAL_READ:
        if (argv[1] == SERIAL_READ_CONTINUOUSLY) {
          if (serialIndex + 1 >= MAX_SERIAL_PORTS) {
            break;
          }

          if (argc > 2) {
            // maximum number of bytes to read from buffer per iteration of loop()
            serialBytesToRead[portId] = (int)argv[2] | ((int)argv[3] << 7);
          } else {
            // read all available bytes per iteration of loop()
            serialBytesToRead[portId] = 0;
          }
          serialIndex++;
          reportSerial[serialIndex] = portId;
        } else if (argv[1] == SERIAL_STOP_READING) {
          byte serialIndexToSkip = 0;
          if (serialIndex <= 0) {
            serialIndex = -1;
          } else {
            for (byte i = 0; i < serialIndex + 1; i++) {
              if (reportSerial[i] == portId) {
                serialIndexToSkip = i;
                break;
              }
            }
            // shift elements over to fill space left by removed element
            for (byte i = serialIndexToSkip; i < serialIndex + 1; i++) {
              if (i < MAX_SERIAL_PORTS) {
                reportSerial[i] = reportSerial[i + 1];
              }
            }
            serialIndex--;
          }
        }
        break; // SERIAL_READ
      case SERIAL_CLOSE:
        serialPort = getPortFromId(portId);
        if (serialPort != NULL) {
          if (portId < 8) {
            ((HardwareSerial*)serialPort)->end();
          } else {
#if defined(SoftwareSerial_h)
            ((SoftwareSerial*)serialPort)->end();
            if (serialPort != NULL) {
              free(serialPort);
              serialPort = NULL;
            }
#endif
          }
        }
        break; // SERIAL_CLOSE
      case SERIAL_FLUSH:
        serialPort = getPortFromId(portId);
        if (serialPort != NULL) {
          getPortFromId(portId)->flush();
        }
        break; // SERIAL_FLUSH
#if defined(SoftwareSerial_h)
      case SERIAL_LISTEN:
        // can only call listen() on software serial ports
        if (portId > 7) {
          serialPort = getPortFromId(portId);
          if (serialPort != NULL) {
            ((SoftwareSerial*)serialPort)->listen();
          }
        }
        break; // SERIAL_LISTEN
#endif
    } // end switch
    return true;
  }
  return false;
}

void SerialFirmata::update()
{
  checkSerial();
}

void SerialFirmata::reset()
{
#if defined(SoftwareSerial_h)
  Stream *serialPort;
  // free memory allocated for SoftwareSerial ports
  for (byte i = SW_SERIAL0; i < SW_SERIAL3 + 1; i++) {
    serialPort = getPortFromId(i);
    if (serialPort != NULL) {
      free(serialPort);
      serialPort = NULL;
    }
  }
#endif

  serialIndex = -1;
  for (byte i = 0; i < SERIAL_READ_ARR_LEN; i++) {
    serialBytesToRead[i] = 0;
  }
}

// get a pointer to the serial port associated with the specified port id
Stream* SerialFirmata::getPortFromId(byte portId)
{
  switch (portId) {
    case HW_SERIAL0:
      // block use of Serial (typically pins 0 and 1) until ability to reclaim Serial is implemented
      //return &Serial;
      return NULL;
#if defined(PIN_SERIAL1_RX)
    case HW_SERIAL1:
      return &Serial1;
#endif
#if defined(PIN_SERIAL2_RX)
    case HW_SERIAL2:
      return &Serial2;
#endif
#if defined(PIN_SERIAL3_RX)
    case HW_SERIAL3:
      return &Serial3;
#endif
#if defined(PIN_SERIAL4_RX)
    case HW_SERIAL4:
      return &Serial4;
#endif
#if defined(PIN_SERIAL5_RX)
    case HW_SERIAL5:
      return &Serial5;
#endif
#if defined(PIN_SERIAL6_RX)
    case HW_SERIAL6:
      return &Serial6;
#endif
#if defined(SoftwareSerial_h)
    case SW_SERIAL0:
      if (swSerial0 != NULL) {
        // instances of SoftwareSerial are already pointers so simply return the instance
        return swSerial0;
      }
      break;
    case SW_SERIAL1:
      if (swSerial1 != NULL) {
        return swSerial1;
      }
      break;
    case SW_SERIAL2:
      if (swSerial2 != NULL) {
        return swSerial2;
      }
      break;
    case SW_SERIAL3:
      if (swSerial3 != NULL) {
        return swSerial3;
      }
      break;
#endif
  }
  return NULL;
}

// Check serial ports that have READ_CONTINUOUS mode set and relay any data
// for each port to the device attached to that port.
void SerialFirmata::checkSerial()
{
  byte portId, serialData;
  int bytesToRead = 0;
  int numBytesToRead = 0;
  Stream* serialPort;

  if (serialIndex > -1) {

    // loop through all reporting (READ_CONTINUOUS) serial ports
    for (byte i = 0; i < serialIndex + 1; i++) {
      portId = reportSerial[i];
      bytesToRead = serialBytesToRead[portId];
      serialPort = getPortFromId(portId);
      if (serialPort == NULL) {
        continue;
      }
#if defined(SoftwareSerial_h)
      // only the SoftwareSerial port that is "listening" can read data
      if (portId > 7 && !((SoftwareSerial*)serialPort)->isListening()) {
        continue;
      }
#endif
      if (serialPort->available() > 0) {
        Firmata.write(START_SYSEX);
        Firmata.write(SERIAL_MESSAGE);
        Firmata.write(SERIAL_REPLY | portId);

        if (bytesToRead == 0 || (serialPort->available() <= bytesToRead)) {
          numBytesToRead = serialPort->available();
        } else {
          numBytesToRead = bytesToRead;
        }

        // relay serial data to the serial device
        while (numBytesToRead > 0) {
          serialData = serialPort->read();
          Firmata.write(serialData & 0x7F);
          Firmata.write((serialData >> 7) & 0x7F);
          numBytesToRead--;
        }
        Firmata.write(END_SYSEX);
      }

    }
  }
}
