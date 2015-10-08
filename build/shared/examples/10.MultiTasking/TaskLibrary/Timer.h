///
/// @file		Timer.h
/// @brief		RTOS Timer, part of the Galaxia Library Suite
/// @details	RTOS Timer as C++ object for Energia MT
/// @n
/// @n @b		Project EMT-TimerLibrary
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		Rei Vilo, Jun 17, 2015 09:29
/// @version	102
/// 
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


// Core library for code-sense - IDE-based
// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/hal/Timer.h>

#ifndef Timer_h
#define Timer_h

///
/// @brief      RTOS Timer as an object
/// @details    The RTOS Timer is encapsulated as a C++ object for easier use
/// @note       Only one single timer available on the MSP432.
///
class Timer
{
private:
    Timer_Handle TimerHandle;
    
public:
    ///
    /// @brief      Define the timer
    /// @warning    Only one single timer available on the MSP432.
    ///
    Timer();
    
    ///
    /// @brief      Create the timer
    /// @param      timerFunction function to be called
    /// @param      timerPeriod_unit period in unit
    /// @param      unit in us, us = 1, ms = 1000, s = 1000000
    /// @note       The function must be void timerPeriod_ms()
    /// @code   void timerPeriod_ms()
    ///         {
    ///             digitalWrite(RED_LED, HIGH);
    ///         }
    /// @endcode
    /// @bug        Some fucntions like Serial.print(); don't work :(
    ///
    void begin(void (*timerFunction)(void), uint32_t timerPeriod_unit, uint32_t unit = 1000);

    ///
    /// @brief      Start the timer
    ///
    void start();
    
    ///
    /// @brief      Stop the timer
    ///
    void stop();
};

#endif
