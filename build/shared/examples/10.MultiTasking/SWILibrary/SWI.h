///
/// @file		SWI.h
/// @brief		RTOS SWI, part of the Galaxia Library Suite
/// @details	RTOS SWI as C++ object for Energia MT
/// @n
/// @n @b		Project EMT-SWI
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

#ifndef SWI_h
#define SWI_h

// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/BIOS.h>

/*
///
/// @brief		Available count
/// @return		number of available count
/// @bug        Disabling SWI disables all SWIs, included those used by Energia MT
///
void disableSWI();

///
/// @brief      Wait for the SWI
///
void restoreSWI();
*/

///
/// @brief      RTOS SWI as object
/// @details    The RTOS SWI is encapsulated as a C++ object for easier use
/// @note       For w SWI with trigger, see the SWItrigger library.
///
class SWI
{
private:
    Swi_Handle SWIHandle;
    
public:
    ///
    /// @brief      Define the SWI
    ///
    SWI();
    
    ///
    /// @brief      Create the SWI
    /// @param      functionSWI function to be called
    /// @note       For serial port, take 1.
    /// @note       The function must be void functionSWI()
    /// @code   void functionSWI()
    ///         {
    ///             digitalWrite(RED_LED, HIGH);
    ///         }
    /// @endcode
    ///
    void begin(void (*functionSWI)(void));
    
    ///
    /// @brief      Post a SWI
    ///
    void post();
};
#endif
