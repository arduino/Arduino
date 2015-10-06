///
/// @file		Semaphore.h
/// @brief		RTOS Semaphore, part of the Galaxia Library Suite
/// @details	RTOS Semaphore as C++ object for Energia MT
/// @n
/// @n @b		Project EMT-Semaphore
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

#ifndef Semaphore_h
#define Semaphore_h

// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/BIOS.h>

///
/// @brief      RTOS Semaphore as object
/// @details    The RTOS Semaphore is encapsulated as a C++ object for easier use
///
class Semaphore
{
private:
    Semaphore_Handle SemaphoreHandle;
    static xdc_UInt SemaphoreId;
    xdc_UInt Semaphore_Id_number;
    
public:
    ///
    /// @brief      Define the semaphore
    ///
    Semaphore();
    
    ///
    /// @brief      Create the semaphore
    /// @param      count usually number of ressources to synchronise, default = 1
    /// @note       For serial port, take 1.
    ///
    void begin(uint8_t count = 1);

    ///
    /// @brief      Post a semaphore
    ///
    void post();
    
    ///
    /// @brief		Available count
    /// @return		number of available count
    ///
    uint16_t available();
    
    ///
    /// @brief      Wait for the semaphore
    ///
    void waitFor();
};


#endif
