//
// Event.cpp
// Code file
// ----------------------------------
//
// Project EventLibrary for Energia MT 0101E0016
//

#include "Event.h"

Event::Event()
{
    ;
}

void Event::begin()
{
    Error_Block eb;
    Error_init(&eb);
    
    Event_Params params;
    Event_Params_init(&params);
    
    EventHandle = Event_create(&params, &eb);
    
    if (EventHandle == NULL)
    {
        System_abort("Event create failed");
    }
}

uint32_t Event::waitFor(xdc_UInt andMask, xdc_UInt orMask)
{
    return Event_pend(EventHandle, andMask, orMask, BIOS_WAIT_FOREVER);
}

void Event::send(xdc_UInt eventId_number)
{
    Event_post(EventHandle, eventId_number);
}
