/*
  OPT3001.h
  Created by Adrian Fernandez, Dec 2013
  Modified by Dung Dang, Dec 2013
  Released into the public domain.
*/

#ifndef opt3001_h
#define opt3001_h
#define opt3001_h

#include <Energia.h>
#include <Wire.h>

#define OPT_INTERRUPT_PIN 8  // Configuration based on Educational BoosterPack MK II
class opt3001
{
  public:
	void begin();
	uint32_t readResult();
	uint16_t readManufacturerId();
	uint16_t readDeviceId();
	uint16_t readConfigReg();
	uint16_t readLowLimitReg();
	uint16_t readHighLimitReg();
	uint16_t readRegister(uint8_t registerName);
	uint8_t	 interruptPin();
  private:
  
};

#endif
