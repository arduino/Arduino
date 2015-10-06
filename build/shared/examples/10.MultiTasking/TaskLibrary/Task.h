///
/// @file		Task.h
/// @brief		RTOS Task, part of the Galaxia Library Suite
/// @details	RTOS Task as C++ object for Energia MT
/// @n
/// @n @b		Project EMT-Task
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		Jun 23, 2015 09:53
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references and example
///
/// @see        SYS/BIOS (TI-RTOS Kernel) v6.41 User's Guide (spruex3o)
///             http://www.ti.com/lit/pdf/spruex3
///

#ifndef Task_h
#define Task_h

// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/BIOS.h>

/*
///
/// @brief		Available count
/// @return		number of available count
/// @bug        Disabling Task disables all Tasks, included those used by Energia MT
///
void disableTask();

///
/// @brief      Wait for the Task
///
void restoreTask();
*/

///
/// @brief      RTOS Task as object
/// @details    The RTOS Task is encapsulated as a C++ object for easier use
/// @note       functionTask() runs once only, unless a while() { ... } is included
/// @note       This implementation of Task differs from Energia MT.
/// @n          Each sketch (.ino file) includes setup() and loop() for Energia MT.
///
class Task
{
private:
    Task_Handle TaskHandle;
    
public:
    ///
    /// @brief      Define the Task
    ///
    Task();
    
    ///
    /// @brief      Create the Task
    /// @param      functionTask function to be called
    /// @param      priority 0 .. Task_numPriorities - 1
    /// @note       The function must be void functionTask()
    /// @code   void functionTask()
    ///         {
    ///             digitalWrite(RED_LED, HIGH);
    ///         }
    /// @endcode
    ///
    void begin(void (*functionTask)(void), int8_t priority);
    
//    ///
//    /// @brief      Post a Task
//    ///
//    void post();
};
#endif
