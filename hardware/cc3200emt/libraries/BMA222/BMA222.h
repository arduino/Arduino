#include "Energia.h"
#include <Wire.h>

#ifndef BMA222_h
#define BMA222_h
#endif

#define BMA222_DEV_ADDR 0x18
#define BMA222_CHIP_ID_REG 0x00

#define BMA222_ACC_DATA_X_NEW (0x2)
#define BMA222_ACC_DATA_X     (0x3)
#define BMA222_ACC_DATA_Y_NEW (0x4)
#define BMA222_ACC_DATA_Y     (0x5)
#define BMA222_ACC_DATA_Z_NEW (0x6)
#define BMA222_ACC_DATA_Z     (0x7)

class BMA222 {
private:
	uint8_t i2cAddr;
public:

	BMA222();
	~BMA222();
	void begin();
	void begin(uint8_t addr);
	int8_t readReg(uint8_t reg);
	uint8_t chipID();
	int16_t readXData();
	int16_t readYData();
	int16_t readZData();
};
