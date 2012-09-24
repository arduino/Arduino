///
/// @file	FraunchPad_Accelerometer.h
/// @brief	Class library header
/// @details	
/// @n
/// @n @b	Project FRAM_ACC
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei Vilo
/// @author	http://embedxcode.weebly.com
/// @date	22/09/12 19:47
/// @version	103
///
/// @copyright	© Rei Vilo, 2012
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
///


// Core library - MCU-based
#if defined(__MSP430FR5739__) // FraunchPad specific
#include "Energia.h"
#else // error
#error Platform not defined
#endif


#ifndef FraunchPad_Accelerometer_h
#define FraunchPad_Accelerometer_h


///
/// @brief Accelerometer on FraunchPad
///
class accelerometer_FR {
public:
  ///
  /// @brief	Constructor
  ///
  accelerometer_FR();
  
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
  /// @brief	Calibrate the accelerometer
  /// @note	To perform a calibration, place the FraunchPad on a horizontal table and press TOUCH2
  ///
  void calibrate();

  
  ///
  /// @brief 	Acquire acceleration
  /// @note	Call this function prior to gravityX100 or degreeX100
  ///
  void get();

  
  ///
  /// @brief	Return gravity, X100 to avoid float
  /// @code {.cpp}
  /// Serial.print(x/10, DEC);     // integer part
  /// Serial.print(".");           // decimal separator
  /// Serial.print(x%100/10, DEC); // decimal part, first digit 
  /// Serial.print(x%10, DEC);     // decimal part, second digit
  /// @endcode
  /// @param	x gravity on x axis
  /// @param	y gravity on y axis
  /// @param	z gravity on z axis
  ///
  void gravityX100(int32_t &x, int32_t &y, int32_t &z);
  
  ///
  /// @brief	Return angle in degrees, X100 to avoid float
  /// @code {.cpp}
  /// Serial.print(x/10, DEC);     // integer part
  /// Serial.print(".");           // decimal separator
  /// Serial.print(x%100/10, DEC); // decimal part, first digit
  /// Serial.print(x%10, DEC);     // decimal part, second digit
  /// @endcode
  /// @param	x angle on x axis
  /// @param	y angle on y axis
  /// @param	z angle on z axis
  ///
  void degreeX100(int32_t &x, int32_t &y, int32_t &z);
  
private:
  int32_t _x, _y, _z;
  int32_t _x0, _y0, _z0;
  int32_t _vRef;
};

#endif
