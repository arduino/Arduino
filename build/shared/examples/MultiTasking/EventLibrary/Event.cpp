#include "Event.h"

Event::Event(){}

void Event::begin()
{
  Error_Block eb;
  Error_init(&eb);
  eventHandle = Event_create(NULL, &eb);
}

void Event::waitFor()
{
  Event_pend(eventHandle, Event_Id_NONE,
    Event_Id_00, BIOS_WAIT_FOREVER);    
}

void Event::send()
{
  Event_post(eventHandle, Event_Id_00);  
}
