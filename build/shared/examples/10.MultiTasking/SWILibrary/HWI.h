///
/// @file		HWI.h
/// @brief		RTOS HWI, part of the Galaxia Library Suite
/// @details	RTOS HWI as C++ object for Energia MT
/// @n
/// @n @b		Project EMT-HWI
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		Jun 08, 2015 09:53
/// @version	104
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references and example
///
/// @see        SYS/BIOS (TI-RTOS Kernel) v6.41 User's Guide (spruex3o)
///             http://www.ti.com/lit/pdf/spruex3
///

#ifndef HWI_h
#define HWI_h

// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/hal/Hwi.h>
#include <ti/sysbios/BIOS.h>
#include <ti/drivers/GPIO.h>

/*
///
/// @brief		Available count
/// @return		number of available count
/// @bug        Disabling HWI disables all HWIs, included those used by Energia MT
///
void disableHWI();

///
/// @brief      Wait for the HWI
///
void restoreHWI();
*/

///
/// @brief      RTOS HWI as object
/// @details    The RTOS HWI is encapsulated as a C++ object for easier use
/// @bug        Reuse of msp432/cores/msp432/WInterrupts.c based on ti/drivers/GPIO.h. HWI impementation?
///
class HWI
{
private:
    Hwi_Handle HWIHandle;
    uint8_t HWIpin;
    
public:
    ///
    /// @brief      Define the HWI
    ///
    HWI();
    
    ///
    /// @brief      Create the HWI
    /// @param      pinNumber function to be called
    /// @param      functionHWI function to be called
    /// @param      mode LOW, CHANGE, FALLING, RISING
    /// @note       Same as attachInterrupt()
    /// @note       The function must be void functionHWI()
    /// @code   void functionHWI()
    ///         {
    ///             digitalWrite(RED_LED, HIGH);
    ///         }
    /// @endcode
    ///
    void begin(uint8_t pinNumber, void (*functionHWI)(void), int mode);

    
    ///
    /// @brief      Clear the interrupt
    /// @note       Same as detachInterrupt()
    ///
    void clearInterrupt();
};
#endif
