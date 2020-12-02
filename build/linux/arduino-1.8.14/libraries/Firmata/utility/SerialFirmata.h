/*
  SerialFirmata.h
  Copyright (C) 2016 Jeff Hoefs. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.

  This version of SerialFirmata.h differs from the ConfigurableFirmata
  version in the following ways:

  - Defines FIRMATA_SERIAL_FEATURE (could add to Configurable version as well)
  - Imports Firmata.h rather than ConfigurableFirmata.h

  Last updated October 16th, 2016
*/

#ifndef SerialFirmata_h
#define SerialFirmata_h

#include <Firmata.h>
#include "FirmataFeature.h"
// SoftwareSerial is currently only supported for AVR-based boards and the Arduino 101.
// Limited to Arduino 1.6.6 or higher because Arduino builder cannot find SoftwareSerial
// prior to this release.
#if (ARDUINO > 10605) && (defined(ARDUINO_ARCH_AVR) || defined(ARDUINO_ARCH_ARC32))
#include <SoftwareSerial.h>
#endif

#define FIRMATA_SERIAL_FEATURE

// Serial port Ids
#define HW_SERIAL0                  0x00
#define HW_SERIAL1                  0x01
#define HW_SERIAL2                  0x02
#define HW_SERIAL3                  0x03
#define HW_SERIAL4                  0x04
#define HW_SERIAL5                  0x05
#define HW_SERIAL6                  0x06
// extensible up to 0x07

#define SW_SERIAL0                  0x08
#define SW_SERIAL1                  0x09
#define SW_SERIAL2                  0x0A
#define SW_SERIAL3                  0x0B
// extensible up to 0x0F

#define SERIAL_PORT_ID_MASK         0x0F
#define MAX_SERIAL_PORTS            8
#define SERIAL_READ_ARR_LEN         12

// map configuration query response resolution value to serial pin type
#define RES_RX1                     0x02
#define RES_TX1                     0x03
#define RES_RX2                     0x04
#define RES_TX2                     0x05
#define RES_RX3                     0x06
#define RES_TX3                     0x07
#define RES_RX4                     0x08
#define RES_TX4                     0x09
#define RES_RX5                     0x0a
#define RES_TX5                     0x0b
#define RES_RX6                     0x0c
#define RES_TX6                     0x0d

// Serial command bytes
#define SERIAL_CONFIG               0x10
#define SERIAL_WRITE                0x20
#define SERIAL_READ                 0x30
#define SERIAL_REPLY                0x40
#define SERIAL_CLOSE                0x50
#define SERIAL_FLUSH                0x60
#define SERIAL_LISTEN               0x70

// Serial read modes
#define SERIAL_READ_CONTINUOUSLY    0x00
#define SERIAL_STOP_READING         0x01
#define SERIAL_MODE_MASK            0xF0

namespace {

  struct serial_pins {
    uint8_t rx;
    uint8_t tx;
  };

  /*
   * Get the serial serial pin type (RX1, TX1, RX2, TX2, etc) for the specified pin.
   */
  inline uint8_t getSerialPinType(uint8_t pin) {
  #if defined(PIN_SERIAL_RX)
    // TODO when use of HW_SERIAL0 is enabled
  #endif
  #if defined(PIN_SERIAL1_RX)
    if (pin == PIN_SERIAL1_RX) return RES_RX1;
    if (pin == PIN_SERIAL1_TX) return RES_TX1;
  #endif
  #if defined(PIN_SERIAL2_RX)
    if (pin == PIN_SERIAL2_RX) return RES_RX2;
    if (pin == PIN_SERIAL2_TX) return RES_TX2;
  #endif
  #if defined(PIN_SERIAL3_RX)
    if (pin == PIN_SERIAL3_RX) return RES_RX3;
    if (pin == PIN_SERIAL3_TX) return RES_TX3;
  #endif
  #if defined(PIN_SERIAL4_RX)
    if (pin == PIN_SERIAL4_RX) return RES_RX4;
    if (pin == PIN_SERIAL4_TX) return RES_TX4;
  #endif
  #if defined(PIN_SERIAL5_RX)
    if (pin == PIN_SERIAL5_RX) return RES_RX5;
    if (pin == PIN_SERIAL5_TX) return RES_TX5;
  #endif
  #if defined(PIN_SERIAL6_RX)
    if (pin == PIN_SERIAL6_RX) return RES_RX6;
    if (pin == PIN_SERIAL6_TX) return RES_TX6;
  #endif
    return 0;
  }

  /*
   * Get the RX and TX pins numbers for the specified HW serial port.
   */
  inline serial_pins getSerialPinNumbers(uint8_t portId) {
    serial_pins pins;
    switch (portId) {
  #if defined(PIN_SERIAL_RX)
        // case HW_SERIAL0:
        //   // TODO when use of HW_SERIAL0 is enabled
        //   break;
  #endif
  #if defined(PIN_SERIAL1_RX)
      case HW_SERIAL1:
        pins.rx = PIN_SERIAL1_RX;
        pins.tx = PIN_SERIAL1_TX;
        break;
  #endif
  #if defined(PIN_SERIAL2_RX)
      case HW_SERIAL2:
        pins.rx = PIN_SERIAL2_RX;
        pins.tx = PIN_SERIAL2_TX;
        break;
  #endif
  #if defined(PIN_SERIAL3_RX)
      case HW_SERIAL3:
        pins.rx = PIN_SERIAL3_RX;
        pins.tx = PIN_SERIAL3_TX;
        break;
  #endif
  #if defined(PIN_SERIAL4_RX)
      case HW_SERIAL4:
        pins.rx = PIN_SERIAL4_RX;
        pins.tx = PIN_SERIAL4_TX;
        break;
  #endif
  #if defined(PIN_SERIAL5_RX)
      case HW_SERIAL5:
        pins.rx = PIN_SERIAL5_RX;
        pins.tx = PIN_SERIAL5_TX;
        break;
  #endif
  #if defined(PIN_SERIAL6_RX)
      case HW_SERIAL6:
        pins.rx = PIN_SERIAL6_RX;
        pins.tx = PIN_SERIAL6_TX;
        break;
  #endif
      default:
        pins.rx = 0;
        pins.tx = 0;
    }
    return pins;
  }

} // end namespace


class SerialFirmata: public FirmataFeature
{
  public:
    SerialFirmata();
    boolean handlePinMode(byte pin, int mode);
    void handleCapability(byte pin);
    boolean handleSysex(byte command, byte argc, byte* argv);
    void update();
    void reset();
    void checkSerial();

  private:
    byte reportSerial[MAX_SERIAL_PORTS];
    int serialBytesToRead[SERIAL_READ_ARR_LEN];
    signed char serialIndex;

#if defined(SoftwareSerial_h)
    Stream *swSerial0;
    Stream *swSerial1;
    Stream *swSerial2;
    Stream *swSerial3;
#endif

    Stream* getPortFromId(byte portId);

};

#endif /* SerialFirmata_h */
