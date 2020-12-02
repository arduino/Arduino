/*
  CapacitiveSense.h v.04 - Capacitive Sensing Library for 'duino / Wiring
  https://github.com/PaulStoffregen/CapacitiveSensor
  http://www.pjrc.com/teensy/td_libs_CapacitiveSensor.html
  http://playground.arduino.cc/Main/CapacitiveSensor
  Copyright (c) 2008 Paul Bagder  All rights reserved.
  Version 05 by Paul Stoffregen - Support non-AVR board: Teensy 3.x, Arduino Due
  Version 04 by Paul Stoffregen - Arduino 1.0 compatibility, issue 146 fix
  vim: set ts=4:
*/

// ensure this library description is only included once
#ifndef CapacitiveSensor_h
#define CapacitiveSensor_h

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#if defined(ARDUINO_NRF52840_CIRCUITPLAY)
#define RwReg uint32_t
#elif defined(__AVR__)
#define RwReg uint8_t
#endif


/**************************************************************************/
/*! 
    @brief  Class that stores state and functions for the capacitive sensor on CircuitPlayground boards
*/
/**************************************************************************/
class CPlay_CapacitiveSensor
{
  // user-accessible "public" interface
  public:
  // methods
	CPlay_CapacitiveSensor(uint8_t sendPin = 0, uint8_t receivePin = 0);
	long capacitiveSensorRaw(uint8_t samples);
	long capacitiveSensor(uint8_t samples);
	void set_CS_Timeout_Millis(unsigned long timeout_millis);
	void reset_CS_AutoCal();
	void set_CS_AutocaL_Millis(unsigned long autoCal_millis);
  // library-accessible "private" interface
  private:
  // variables
	int error;
	unsigned long  leastTotal;
	unsigned int   loopTimingFactor;
	unsigned long  CS_Timeout_Millis;
	unsigned long  CS_AutocaL_Millis;
	unsigned long  lastCal;
	unsigned long  total;
	uint8_t _sendPin, _receivePin;
	volatile RwReg *send_outport, *recv_outport, *recv_inport, *recv_direction;
	RwReg send_mask, recv_mask;
  
  // methods
	int SenseOneCycle(void);
};

#endif
