///
/// @file	SRAM.h
/// @brief	Library header
///
/// @details	Library for 23K640 SPI SRAM
/// @n	
/// @n @b	Project chipKIT_SRAM
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	embedXcode.weebly.com
/// @date	déc. 22, 2012 14:26
/// @version	101
///
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///
// Core library - IDE-based
#if defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#else
#error Platfrom not supported.
#endif // end IDE
#ifndef chipKIT_SRAM_SRAM_h
#define chipKIT_SRAM_SRAM_h
#include "SPI.h"
#define SRAM_READ         0b00000011
#define SRAM_WRITE        0b00000010
#define SRAM_READ_STATUS  0b00000101
#define SRAM_WRITE_STATUS 0b00000001
#define SRAM_BYTE_MODE     0b00000000
#define SRAM_PAGE_MODE     0b10000000
#define SRAM_SEQUENCE_MODE 0b01000000
#define SRAM_RESERVED_MODE 0b11000000
#define SRAM_HOLD_MODE     0b00000001
class SRAM {
public:
    SRAM(uint8_t pinChipSelect);
    void begin();
    void setMode(uint8_t mode);
    uint8_t getMode();
//    void write(uint16_t address, uint8_t data);
    void write(uint16_t address, uint8_t * data, uint16_t length);
//    void read(uint16_t address, uint8_t data);
void read(uint16_t address, uint8_t * data, uint16_t length);
private:
    uint8_t _pinChipSelect;
};
#endif
