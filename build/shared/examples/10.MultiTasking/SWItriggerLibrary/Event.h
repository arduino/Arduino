///
/// @file		Event.h
/// @brief		RTOS Event, part of the Galaxia Library Suite
/// @details	RTOS Event as C++ object for Energia MT
/// @n
/// @n @b		Project Energia MT 0101E0016
///
/// @author		Energia, base
/// @author		Rei Vilo, enhancements
///
/// @date		Jun 22, 2015 15:53
/// @version	105
///
/// @see        SYS/BIOS (TI-RTOS Kernel) v6.41 User's Guide (spruex3o)
///             http://www.ti.com/lit/pdf/spruex3
///

// Include application, user and local libraries
#include <Energia.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/BIOS.h>

#ifndef Event_h
#define Event_h

///
/// @brief      RTOS Event as object
/// @details    The RTOS Event is encapsulated as a C++ object for easier use
/// @note       Only a single Task can pend on an Event object at a time.
///
class Event
{
private:
    Event_Handle EventHandle;
    static xdc_UInt EventId;
    
public:
    ///
    /// @brief      Define the event
    ///
    Event();
    
    ///
    /// @brief      Create the event
    ///
    void begin();
    
    ///
    /// @brief      Raise the event
    /// @param      eventId_number event identifier, default = Event_Id_00
    /// @note       Take event identifier among Event_Id_00..Event_Id_31
    ///
    void send(xdc_UInt eventId_number = Event_Id_00);
    
    ///
    /// @brief      Wait for the event
    /// @param      andMask AND condition, default = Event_Id_00
    /// @param      orMask  OR  condition, default = Event_Id_NONE
    /// @return     events identifiers as bit, 32-bit
    /// @code
    ///     0b=1100 = Event_Id_03 + Event_Id_02
    /// @endcode
    ///
    uint32_t waitFor(xdc_UInt andMask = Event_Id_00, xdc_UInt orMask  = Event_Id_NONE);
};

#endif
