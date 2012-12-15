///
/// @file	Thermometer_430.h
/// @brief	Library header
/// @details	MSP430 internal thermometer library
/// @n	
/// @n	
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// @n
/// @author	Rei VILO
/// @author	http://embeddedcomputing.weebly.com
/// @date	Dec 13, 2012
/// @version	1.03
/// @n
/// @copyright	© Rei VILO, 2012
/// @copyright	CC = BY NC SA Attribution-NonCommercial-ShareAlike
///
/// @see		http://creativecommons.org/licenses/by-nc-sa/3.0/
///
/// @n	
///

// Core library
#if defined(__MSP430G2553__) // LaunchPad specific
#include "Energia.h"
#else
#error Platform not supported
#endif

#ifndef Thermometer_430_h
#define Thermometer_430_h

///
/// @brief	Number of measures for moving average
/// @note	Take number / 2
///
#define NUMBER  8 

///
/// @brief	Thermometer_430 class
///
class Thermometer_430 {
public:
  ///
  /// @brief	Constructor
  ///
  Thermometer_430();
  
  ///
  /// @brief	Initialisation
  /// @details	Erase and perform measures NUMBER times to initialise moving average
  ///
  void begin();
  
  ///
  /// @brief	Read a new measure
  ///
  void get();
  
  ///
  /// @brief	Temperature based on moving average
  /// @return	return temperature x 10 to avoid float
  /// @code {.cpp}
  /// Serial.print(temperatureX10()/10, DEC); // integer part
  /// Serial.print(".");                      // decimal separator
  /// Serial.print(temperatureX10()%10, DEC); // decimal part
  /// @endcode
  ///
  int32_t temperatureX10();
  
private:
  int32_t _average;
  int32_t _values[NUMBER];
  uint8_t _index;
};

#endif
