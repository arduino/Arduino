///
/// @file	FastDigitalWrite.h
/// @brief	Library header
/// @details	Fast digital write library
/// @n	
/// @n @b	Project SPI for Stellaris LaunchPad
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	http://embedXcode.weebly.com
/// @date	Jul 08, 2013
/// @version	101
///
/// @copyright	© Rei VILO, 2013
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///
// Board check
#ifndef __LM4F120H5QR__
#error Board not supported.
#endif
// Core library
#include "Energia.h"
#ifndef FAST_DIGITAL_WRITE_VERSION
#define FAST_DIGITAL_WRITE_VERSION 101
typedef volatile uint32_t   regtype;
typedef uint8_t             regsize;
class fastDigitalOutputPin {
private:
    regtype _port;
    regsize _bit;
public:
    fastDigitalOutputPin(uint8_t pin);
    void setHIGH();
    void setLOW();
    void set(uint8_t value);
    void pulseHIGH();
    void pulseLOW();
};
#endif
