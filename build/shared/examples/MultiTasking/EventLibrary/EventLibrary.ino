/*
 * This Sketch demonstrates the Event library that uses TI-RTOS's event feature.
 * The Event library has 3 functions.
 * - begin() will setup the button library.
 * - send() Which will send an event to anybody waiting for an event.
 * - waitFor() waits for the event to be send and sleeps otherwise.
 * 
 * This library will allows you to send an event in one task and have another task
 * wait for the event. The task waiting for the event to be send
 * will sleep until the other task sends the event. 
 *
 * In this example Sketch, the EventLibrary tab is the task sending the event and does this every
 * 1000 ms. The Serial tab is the tab waiting for the event to be send.
 * 
 * Usage:
 * Upload the Sketch and open the Serial monitor.
 */
 
///
/// @file		EventLibrary.ino
/// @brief		Main sketch
///
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///


// Core library for code-sense - IDE-based
#include "Energia.h"

// Include application, user and local libraries
#include "rtosGlobals.h"
#include "Event.h"

// Prototypes


// Define variables and constants


// the setup routine runs once when you press reset:
void setup()
{
    myEvent.begin();
}

// the loop routine runs over and over again forever:
void loop()
{
    myEvent.send();
    delay(1000);
}

