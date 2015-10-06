///
/// @file		SWItrigger.h
/// @brief		RTOS SWI with trigger (SWItrigger), part of the Galaxia Library Suite
/// @details	RTOS SWI with trigger as C++ object for Energia MT
/// @n
/// @n @b		Project EMT-SWItrigger
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

#ifndef SWItrigger_h
#define SWItrigger_h

// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/BIOS.h>

/*
///
/// @brief		Available count
/// @return		number of available count
/// @bug        Disabling SWItrigger disables all triggers, included those used by Energia MT
///
void disableSWItrigger();

///
/// @brief      Wait for the SWItrigger
///
void restoreSWItrigger();
*/

///
/// @brief      RTOS SWI with trigger as object
/// @details    The RTOS SWI with trigger is encapsulated as a C++ object for easier use
///
class SWItrigger
{
private:
    Swi_Handle SWItriggerHandle;
    
public:
    ///
    /// @brief      Define the SWItrigger
    ///
    SWItrigger();
    
    ///
    /// @brief      Create the SWItrigger
    /// @param      functionSWItrigger function to be called
    /// @note       For serial port, take 1.
    /// @note       The function must be void functionSWItrigger()
    /// @code   void functionSWItrigger()
    ///         {
    ///             digitalWrite(RED_LED, HIGH);
    ///         }
    /// @endcode
    /// @bug        functionSWItrigger(uint8_t) with uint8_t = Swi_getTrigger() doesn't work.
    /// @todo       The idea is to have the same function as for Wire library with
    ///             Wire.onReceive(void (*ReceiveEvent)(int)) and void ReceiveEvent(int howMany)
    ///
    // void begin(uint8_t trigger, void (*functionSWItrigger)(uint8_t));
    void begin(uint8_t trigger, void (*functionSWItrigger)());
    
    ///
    /// @brief      Post a SWItrigger
    ///
    void post();
    
    ///
    /// @brief	Increment count and post
    ///
    void inc();

    ///
    /// @brief	Decrement count and post if count = 0
    ///
    void dec();

};
#endif
