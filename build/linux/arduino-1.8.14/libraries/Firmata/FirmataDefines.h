/*
  FirmataDefines.h
  Copyright (c) 2006-2008 Hans-Christoph Steiner.  All rights reserved.
  Copyright (C) 2009-2016 Jeff Hoefs.  All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  See file LICENSE.txt for further informations on licensing terms.
*/

#ifndef FirmataDefines_h
#define FirmataDefines_h

#include "FirmataConstants.h"

/* Version numbers for the Firmata library.
 * The firmware version will not always equal the protocol version going forward.
 * Query using the REPORT_FIRMWARE message.
 */
#define FIRMATA_FIRMWARE_MAJOR_VERSION  firmata::FIRMWARE_MAJOR_VERSION
#define FIRMATA_FIRMWARE_MINOR_VERSION  firmata::FIRMWARE_MINOR_VERSION
#define FIRMATA_FIRMWARE_BUGFIX_VERSION firmata::FIRMWARE_BUGFIX_VERSION

/* Version numbers for the protocol.  The protocol is still changing, so these
 * version numbers are important.
 * Query using the REPORT_VERSION message.
 */
#define FIRMATA_PROTOCOL_MAJOR_VERSION  firmata::PROTOCOL_MAJOR_VERSION // for non-compatible changes
#define FIRMATA_PROTOCOL_MINOR_VERSION  firmata::PROTOCOL_MINOR_VERSION // for backwards compatible changes
#define FIRMATA_PROTOCOL_BUGFIX_VERSION firmata::PROTOCOL_BUGFIX_VERSION // for bugfix releases

#ifdef MAX_DATA_BYTES
#undef MAX_DATA_BYTES
#endif
#define MAX_DATA_BYTES          firmata::MAX_DATA_BYTES // max number of data bytes in incoming messages

// message command bytes (128-255/0x80-0xFF)

#ifdef DIGITAL_MESSAGE
#undef DIGITAL_MESSAGE
#endif
#define DIGITAL_MESSAGE         firmata::DIGITAL_MESSAGE // send data for a digital port (collection of 8 pins)

#ifdef ANALOG_MESSAGE
#undef ANALOG_MESSAGE
#endif
#define ANALOG_MESSAGE          firmata::ANALOG_MESSAGE // send data for an analog pin (or PWM)

#ifdef REPORT_ANALOG
#undef REPORT_ANALOG
#endif
#define REPORT_ANALOG           firmata::REPORT_ANALOG // enable analog input by pin #

#ifdef REPORT_DIGITAL
#undef REPORT_DIGITAL
#endif
#define REPORT_DIGITAL          firmata::REPORT_DIGITAL // enable digital input by port pair

//

#ifdef SET_PIN_MODE
#undef SET_PIN_MODE
#endif
#define SET_PIN_MODE            firmata::SET_PIN_MODE // set a pin to INPUT/OUTPUT/PWM/etc

#ifdef SET_DIGITAL_PIN_VALUE
#undef SET_DIGITAL_PIN_VALUE
#endif
#define SET_DIGITAL_PIN_VALUE   firmata::SET_DIGITAL_PIN_VALUE // set value of an individual digital pin

//

#ifdef REPORT_VERSION
#undef REPORT_VERSION
#endif
#define REPORT_VERSION          firmata::REPORT_VERSION // report protocol version

#ifdef SYSTEM_RESET
#undef SYSTEM_RESET
#endif
#define SYSTEM_RESET            firmata::SYSTEM_RESET // reset from MIDI

//

#ifdef START_SYSEX
#undef START_SYSEX
#endif
#define START_SYSEX             firmata::START_SYSEX // start a MIDI Sysex message

#ifdef END_SYSEX
#undef END_SYSEX
#endif
#define END_SYSEX               firmata::END_SYSEX // end a MIDI Sysex message

// extended command set using sysex (0-127/0x00-0x7F)
/* 0x00-0x0F reserved for user-defined commands */

#ifdef SERIAL_MESSAGE
#undef SERIAL_MESSAGE
#endif
#define SERIAL_MESSAGE          firmata::SERIAL_DATA // communicate with serial devices, including other boards

#ifdef ENCODER_DATA
#undef ENCODER_DATA
#endif
#define ENCODER_DATA            firmata::ENCODER_DATA // reply with encoders current positions

#ifdef SERVO_CONFIG
#undef SERVO_CONFIG
#endif
#define SERVO_CONFIG            firmata::SERVO_CONFIG // set max angle, minPulse, maxPulse, freq

#ifdef STRING_DATA
#undef STRING_DATA
#endif
#define STRING_DATA             firmata::STRING_DATA // a string message with 14-bits per char

#ifdef STEPPER_DATA
#undef STEPPER_DATA
#endif
#define STEPPER_DATA            firmata::STEPPER_DATA // control a stepper motor

#ifdef ONEWIRE_DATA
#undef ONEWIRE_DATA
#endif
#define ONEWIRE_DATA            firmata::ONEWIRE_DATA // send an OneWire read/write/reset/select/skip/search request

#ifdef SHIFT_DATA
#undef SHIFT_DATA
#endif
#define SHIFT_DATA              firmata::SHIFT_DATA // a bitstream to/from a shift register

#ifdef I2C_REQUEST
#undef I2C_REQUEST
#endif
#define I2C_REQUEST             firmata::I2C_REQUEST // send an I2C read/write request

#ifdef I2C_REPLY
#undef I2C_REPLY
#endif
#define I2C_REPLY               firmata::I2C_REPLY // a reply to an I2C read request

#ifdef I2C_CONFIG
#undef I2C_CONFIG
#endif
#define I2C_CONFIG              firmata::I2C_CONFIG // config I2C settings such as delay times and power pins

#ifdef REPORT_FIRMWARE
#undef REPORT_FIRMWARE
#endif
#define REPORT_FIRMWARE         firmata::REPORT_FIRMWARE // report name and version of the firmware

#ifdef EXTENDED_ANALOG
#undef EXTENDED_ANALOG
#endif
#define EXTENDED_ANALOG         firmata::EXTENDED_ANALOG // analog write (PWM, Servo, etc) to any pin

#ifdef PIN_STATE_QUERY
#undef PIN_STATE_QUERY
#endif
#define PIN_STATE_QUERY         firmata::PIN_STATE_QUERY // ask for a pin's current mode and value

#ifdef PIN_STATE_RESPONSE
#undef PIN_STATE_RESPONSE
#endif
#define PIN_STATE_RESPONSE      firmata::PIN_STATE_RESPONSE // reply with pin's current mode and value

#ifdef CAPABILITY_QUERY
#undef CAPABILITY_QUERY
#endif
#define CAPABILITY_QUERY        firmata::CAPABILITY_QUERY // ask for supported modes and resolution of all pins

#ifdef CAPABILITY_RESPONSE
#undef CAPABILITY_RESPONSE
#endif
#define CAPABILITY_RESPONSE     firmata::CAPABILITY_RESPONSE // reply with supported modes and resolution

#ifdef ANALOG_MAPPING_QUERY
#undef ANALOG_MAPPING_QUERY
#endif
#define ANALOG_MAPPING_QUERY    firmata::ANALOG_MAPPING_QUERY // ask for mapping of analog to pin numbers

#ifdef ANALOG_MAPPING_RESPONSE
#undef ANALOG_MAPPING_RESPONSE
#endif
#define ANALOG_MAPPING_RESPONSE firmata::ANALOG_MAPPING_RESPONSE // reply with mapping info

#ifdef SAMPLING_INTERVAL
#undef SAMPLING_INTERVAL
#endif
#define SAMPLING_INTERVAL       firmata::SAMPLING_INTERVAL // set the poll rate of the main loop

#ifdef SCHEDULER_DATA
#undef SCHEDULER_DATA
#endif
#define SCHEDULER_DATA          firmata::SCHEDULER_DATA // send a createtask/deletetask/addtotask/schedule/querytasks/querytask request to the scheduler

#ifdef SYSEX_NON_REALTIME
#undef SYSEX_NON_REALTIME
#endif
#define SYSEX_NON_REALTIME      firmata::SYSEX_NON_REALTIME // MIDI Reserved for non-realtime messages

#ifdef SYSEX_REALTIME
#undef SYSEX_REALTIME
#endif
#define SYSEX_REALTIME          firmata::SYSEX_REALTIME // MIDI Reserved for realtime messages

// pin modes

#ifdef PIN_MODE_INPUT
#undef PIN_MODE_INPUT
#endif
#define PIN_MODE_INPUT          firmata::PIN_MODE_INPUT // same as INPUT defined in Arduino.h

#ifdef PIN_MODE_OUTPUT
#undef PIN_MODE_OUTPUT
#endif
#define PIN_MODE_OUTPUT         firmata::PIN_MODE_OUTPUT // same as OUTPUT defined in Arduino.h

#ifdef PIN_MODE_ANALOG
#undef PIN_MODE_ANALOG
#endif
#define PIN_MODE_ANALOG         firmata::PIN_MODE_ANALOG // analog pin in analogInput mode

#ifdef PIN_MODE_PWM
#undef PIN_MODE_PWM
#endif
#define PIN_MODE_PWM            firmata::PIN_MODE_PWM // digital pin in PWM output mode

#ifdef PIN_MODE_SERVO
#undef PIN_MODE_SERVO
#endif
#define PIN_MODE_SERVO          firmata::PIN_MODE_SERVO // digital pin in Servo output mode

#ifdef PIN_MODE_SHIFT
#undef PIN_MODE_SHIFT
#endif
#define PIN_MODE_SHIFT          firmata::PIN_MODE_SHIFT // shiftIn/shiftOut mode

#ifdef PIN_MODE_I2C
#undef PIN_MODE_I2C
#endif
#define PIN_MODE_I2C            firmata::PIN_MODE_I2C // pin included in I2C setup

#ifdef PIN_MODE_ONEWIRE
#undef PIN_MODE_ONEWIRE
#endif
#define PIN_MODE_ONEWIRE        firmata::PIN_MODE_ONEWIRE // pin configured for 1-wire

#ifdef PIN_MODE_STEPPER
#undef PIN_MODE_STEPPER
#endif
#define PIN_MODE_STEPPER        firmata::PIN_MODE_STEPPER // pin configured for stepper motor

#ifdef PIN_MODE_ENCODER
#undef PIN_MODE_ENCODER
#endif
#define PIN_MODE_ENCODER        firmata::PIN_MODE_ENCODER // pin configured for rotary encoders

#ifdef PIN_MODE_SERIAL
#undef PIN_MODE_SERIAL
#endif
#define PIN_MODE_SERIAL         firmata::PIN_MODE_SERIAL // pin configured for serial communication

#ifdef PIN_MODE_PULLUP
#undef PIN_MODE_PULLUP
#endif
#define PIN_MODE_PULLUP         firmata::PIN_MODE_PULLUP // enable internal pull-up resistor for pin

#ifdef PIN_MODE_IGNORE
#undef PIN_MODE_IGNORE
#endif
#define PIN_MODE_IGNORE         firmata::PIN_MODE_IGNORE // pin configured to be ignored by digitalWrite and capabilityResponse

#ifdef TOTAL_PIN_MODES
#undef TOTAL_PIN_MODES
#endif
#define TOTAL_PIN_MODES         firmata::TOTAL_PIN_MODES

#endif // FirmataConstants_h
