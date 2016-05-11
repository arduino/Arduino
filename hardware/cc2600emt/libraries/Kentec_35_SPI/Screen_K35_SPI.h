///
/// @file       Screen_K35_SPI.h - SPECIAL EDITION FOR ENERGIA
/// @brief      Library header
/// @details	SSD2119 screen library
/// @n
/// @n @b       Project LCD_screen Library Suite
/// @n @a       Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author     Rei VILO
/// @author     http://embedXcode.weebly.com
/// @date       Aug 09, 2015
/// @version	106
///
/// @copyright	© Rei VILO, 2013-2016 - SPECIAL EDITION FOR ENERGIA
/// @copyright	Attribution-NonCommercial-ShareAlike 4.0 Unported (CC BY-NC-SA 3.0)
///
/// @n  Unique license: Attribution-NonCommercial-ShareAlike 4.0 Unported (CC BY-NC-SA 3.0)
/// *   For hobbyists and for personal usage
/// *   For professionals or organisations or for commercial usage
///
/// @see
/// *		3.5" inch TFT LCD module BoosterPack for LaunchPad Stellaris
/// @n      http://www.kentecdisplay.com/uploads/soft/Products_spec/EB-LM4F120-L35_UserGuide_03.pdf
/// *       Help from Stellaristi forum for SPI and touch
/// @n      http://forum.stellarisiti.com/topic/666-solved-writing-and-reading-the-values-of-an-8-bit-port-with-energia/?p=3391
/// @n      http://forum.stellarisiti.com/topic/666-solved-writing-and-reading-the-values-of-an-8-bit-port-with-energia/?p=3395
/// @n      http://forum.stellarisiti.com/topic/682-solved-4-wire-resistive-touch-screen-reading-with-energia/?p=3502
/// *       Documentation from Getting Started with the Stellaris EK-LM4F120XL LaunchPad Workshop
/// @n      http://processors.wiki.ti.com/index.php/Getting_Started_with_the_Stellaris_EK-LM4F120XL_LaunchPad_Workshop?DCMP=stellaris-launchpad&HQS=stellaris-launchpadtraining
/// * 		Fonts generated with MikroElektronika GLCD Font Creator 1.2.0.0
/// @n		http://www.mikroe.com
/// *		LCD_screen Library Suite
/// @n		http://embeddedcomputing.weebly.com/lcd_screen-library-suite.html
/// *		Serial_LCD Library Suite
/// @n		http://embeddedcomputing.weebly.com/serial-lcd.html
///


// Core library - IDE-based
#if defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
#include "Energia.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(CORE_TEENSY) // Teensy specific
#include "WProgram.h"
#elif defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(ARDUINO) // Arduino 1.0x and 1.5x specific
#include "Arduino.h"
#endif // end IDE

#ifndef Screen_K35_SPI_RELEASE
///
/// @brief	Library release number
///
#define Screen_K35_SPI_RELEASE 104

#include "LCD_screen_font.h"
#include "SPI.h"

//#if LCD_SCREEN_FONT_RELEASE < 117
//#error Required LCD_SCREEN_FONT_RELEASE 117
//#endif

///
/// @brief      Class for 3.5" 480x320 screen
/// @details    Screen controllers
/// *   LCD: SSD2119, 8-bit 8080 parallel
/// *   touch: direct ADC, no controller
/// @note       The class configures the GPIOs and the SPI port.
///
class Screen_K35_SPI : public LCD_screen_font {
public:
    
    ///
    /// @brief	Constructor with default pins
    ///
    /// @note	Default pins for BoosterPack on LaunchPad
    ///
    Screen_K35_SPI();
    
    ///
    /// @brief      Initialise
    /// @details	Open connections
    ///
    void begin();
    
    ///
    /// @brief	Request information about the screen
    /// @return	string with hardware version
    ///
    String WhoAmI();
    
private:
	// * Virtual =0 compulsory functions
    // Orientation
    void _setOrientation(uint8_t orientation); // compulsory
    void _orientCoordinates(uint16_t &x1, uint16_t &y1); // compulsory
    
	// Position
    void _setWindow(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1); // compulsory
    void _closeWindow(); // compulsory
	void _setPoint(uint16_t x1, uint16_t y1, uint16_t colour); // compulsory
    void _fastFill(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t colour); // compulsory
    
    // Write and Read
    void _writeData88(uint8_t dataHigh8, uint8_t dataLow8); // compulsory;
    
	// Touch
    void _getRawTouch(uint16_t &x0, uint16_t &y0, uint16_t &z0); // compulsory
    
    // * Other functions specific to the screen
    // Communication, write
    void _writeRegister(uint8_t command8, uint16_t data16);
    void _writeCommand16(uint16_t command16);
    void _writeData16(uint16_t data16);
    
    void _setCursor(uint16_t x1, uint16_t y1);

    // Energy
    void _setIntensity(uint8_t intensity); // compulsory
    void _setBacklight(bool flag); // compulsory
    
    // Touch
    void _getOneTouch(uint8_t command8, uint8_t &a, uint8_t &b);

    uint8_t _pinScreenDataCommand, _pinScreenReset, _pinScreenChipSelect, _pinScreenBackLight;
};

#endif
