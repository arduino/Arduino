///
/// @file	FraunchPad_NTC.h 
/// @brief	Library header
/// @details	
/// @n	
/// @n @b	Project FRAM_TEMP
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
/// 
/// @author	Rei Vilo
/// @author	http://embedxcode.weebly.com
/// @date	Oct 08, 2012
/// @version	101
/// 
/// @copyright	© Rei Vilo, 2012
/// @copyright	CC = BY NC SA
///
/// @see
///
/// *		Table algorithm by larsie — Tue Apr 03, 2012 1:18 pm
/// @n		http://www.43oh.com/forum/viewtopic.php?f=10&p=18608#p18608
///
/// *		NTC table generated with TDK / Epcos NTC R/T Calculation 5.0
/// @n		http://www.epcos.com/designtools/ntc/index.html
/// @n		Select B57560G1104 for NTC 100 k = 25 oC
/// @n		with temperature scaling = 5 oC, lower limit = -25 oC and upper limit = + 75 oC
///


// Core library - MCU-based
#if defined(__MSP430FR5739__) // FraunchPad specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif

#ifndef FRAM_Thermometer_h
#define FRAM_Thermometer_h

///
/// @brief Temperature NTC on FraunchPad
///
class NTC_FR {
public:
  ///
  /// @brief	Constructor
  ///
  NTC_FR();
  
  ///
  /// @brief 	Initialisation
  ///
  void begin();
  
  ///
  /// @brief 	Who am I?
  /// @return 	Who am I? string
  ///
  String WhoAmI();
  
  ///
  /// @brief 	Acquire temperature
  /// @note	Call this function prior to degreeX10 or fahrenheitX10
  ///
  void get();
    
  ///
  /// @brief	Return temperature in degrees celsius, X10 to avoid float
  /// @code {.cpp}
  /// Serial.print(x/10, DEC);     // integer part
  /// Serial.print(".");           // decimal separator
  /// Serial.print(x%10, DEC);     // decimal part
  /// @endcode
  /// @param	t temperature in degrees celsius
  ///
  void celsiusX10(int32_t &t);

  ///
  /// @brief	Return temperature in degrees fahrenheit, X10 to avoid float
  /// @code {.cpp}
  /// Serial.print(x/10, DEC);     // integer part
  /// Serial.print(".");           // decimal separator
  /// Serial.print(x%10, DEC);     // decimal part
  /// @endcode
  /// @param	t temperature in degrees celsius
  ///
  void fahrenheitX10(int32_t &t);

private:
  int64_t _t;
  int32_t _vRef;
  int32_t _rDiv;
};


#endif
