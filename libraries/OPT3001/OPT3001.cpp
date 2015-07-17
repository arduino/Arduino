/*
  OPT3001.cpp
  Created by Adrian Fernandez & Dung Dang, Dec 2013
  
  Released into the public domain.
*/
#include "OPT3001.h"
#define slaveAdr 0x44

#define RESULT_REG 0x00
#define CONFIG_REG 0x01
#define LOWLIMIT_REG 0x02
#define HIGHLIMIT_REG 0x03
#define MANUFACTUREID_REG 0x7E
#define DEVICEID_REG 0x7F

#define DEFAULT_CONFIG 0b1100110000010000 // 800ms
#define DEFAULT_CONFIG_100 0b1100010000010000 // 100ms
/* 	CONFIG REGISTER BITS: RN3 RN2 RN1 RN0 CT M1 M0 OVF CRF FH FL L Pol ME FC1 FC0
	RN3 to RN0 = Range select:
					1100 by default, enables auto-range 
	CT = Conversion time bit
					0 = 100ms conversion time
					1 = 800ms conversion time (default)
	M1 to M0 = Mode bits
					00 = Shutdown mode
					01 = Single shot mode
					10 = Continuous conversion (default)
					11 = Continuous conversion
	OVF (Bit 8)	– 	Overflow flag. When set the conversion result is overflown.
	CRF (Bit 7)	–	Conversion ready flag. Sets at end of conversion. Clears by read or write of the Configuration register.
	FH (Bit 6)	– 	Flag high bit. Read only. Sets when result is higher that TH register. Clears when Config register is 
					read or when Latch bit is ‘0’ and the result goes bellow TH register.
	FL (Bit 5)	– 	Flag low bit. Read only. Sets when result is lower that TL register. Clears when Config register is read 
					or when Latch bit is ‘0’ and the result goes above TL register.
	L (Bit 4) 	–	Latch bit. Read/write bit. Default ‘1’, Controls Latch/transparent functionality of FH and FL bits. When 
					L = 1 the Alert pin works in window comparator mode with Latched functionality When L = 0 the Alert pin 
					works in transparent mode and the two limit registers provide the hysteresis.
	Pol (Bit 3)	–	Polarity. Read/write bit. Default ‘0’, Controls the active state of the Alert pin. Pol = 0 means Alert 
					active low.
	ME (Bit 2)	–	Exponent mask. In fixed range modes masks the exponent bits in the result register to “0000”.
	FC1 to FC0	-	Fault count bits. Read/write bits. Default “00” - the first fault will trigger the alert pin.
*/

void opt3001::begin()
{
	uint16_t writeByte = DEFAULT_CONFIG_100;
	// Initialize Wire

	// Use I2C module 1 (I2C1SDA & I2C1SCL per BoosterPack standard) and begin
	
	Wire.begin();
	
	
    /* Begin Tranmission at address of device on bus */
	Wire.beginTransmission(slaveAdr);
	/* Send Pointer Register Byte */
	
	Wire.write(CONFIG_REG);

	/* Read*/
	Wire.write((unsigned char)(writeByte>>8));
	Wire.write((unsigned char)(writeByte&0x00FF));

	/* Sends Stop */
	Serial.println("before ending transmission");
	Wire.endTransmission();
	Serial.println("return to life");
	return;
}

uint16_t opt3001::readRegister(uint8_t registerName)
{
	int8_t lsb;
	int8_t msb;
	int16_t result;


	// Initialize Wire
	Wire.begin();

	/* Begin Transmission at address of device on bus */
	Wire.beginTransmission(slaveAdr);

	/* Send Pointer to register you want to read */
	Wire.write(registerName);

	/* Sends Stop */
	Wire.endTransmission(true);

	/* Requests 2 bytes from Slave */
	Wire.requestFrom(slaveAdr, 2);

	/* Wait Until 2 Bytes are Ready*/
	while(Wire.available() < 2)	{}

	/* Read*/
	msb = Wire.read();
	lsb = Wire.read();
	result = (msb << 8) | lsb;

	return result;
}


uint16_t opt3001::readManufacturerId()
{

	return readRegister(MANUFACTUREID_REG);
	
}

uint16_t opt3001::readDeviceId()
{
	return readRegister(DEVICEID_REG);
		
}

uint16_t opt3001::readConfigReg()
{
	return readRegister(CONFIG_REG);
}

uint16_t opt3001::readLowLimitReg()
{
	return readRegister(LOWLIMIT_REG);
	
	
}

uint16_t opt3001::readHighLimitReg()
{
	return readRegister(HIGHLIMIT_REG);
}


uint32_t opt3001::readResult()
{
	uint16_t exponent = 0;
	uint32_t result = 0;
	int16_t raw;
	raw = readRegister(RESULT_REG);
	
	/*Convert to LUX*/
	//extract result & exponent data from raw readings
	result = raw&0x0FFF;
	exponent = (raw>>12)&0x000F;

	//convert raw readings to LUX
	switch(exponent){
		case 0: //*0.015625
			result = result>>6;
			break;
		case 1: //*0.03125
			result = result>>5;
			break;
		case 2: //*0.0625
			result = result>>4;
			break;
		case 3: //*0.125
			result = result>>3;
			break;
		case 4: //*0.25
			result = result>>2;
			break;
		case 5: //*0.5
			result = result>>1;
			break;
		case 6:
			result = result;
			break;
		case 7: //*2
			result = result<<1;
			break;
		case 8: //*4
			result = result<<2;
			break;
		case 9: //*8
			result = result<<3;
			break;
		case 10: //*16
			result = result<<4;
			break;
		case 11: //*32
			result = result<<5;
			break;
	}

	return result;
	
}

uint8_t opt3001::interruptPin()
{
	return (digitalRead(OPT_INTERRUPT_PIN)==0?1:0);
}
