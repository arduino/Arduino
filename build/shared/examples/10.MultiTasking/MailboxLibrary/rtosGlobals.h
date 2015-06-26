///
/// @file		rtosGlobals.h
/// @brief		Header
/// @details	Global variables for Energia MT project
/// @n	
/// @n @b		Project MultiBlink_eX
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
/// 
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		Jun 05, 2015 13:34
/// @version	101
/// 
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


// Core library
#include "Energia.h"


#ifndef rtosGlobals_h
#define rtosGlobals_h

// Include application, user and local libraries
#include "Mailbox.h"
#include "Semaphore.h"

///
/// @brief	myMessage type for mailbox
///
typedef struct myMessage_t
{
	uint32_t chrono; ///< for millis()
	char buffer[10]; ///< for origin
};

///
/// @brief	Number of messages of the mailbox
///
#define NUMBER 4

///
/// @brief	Mailbox post modality
/// @note   Either BIOS_WAIT_FOREVER or BIOS_NO_WAIT
///
#define MODALITY BIOS_WAIT_FOREVER

///
/// @brief	myMailbox
///
Mailbox<myMessage_t> myMailbox;

///
/// @brief	mySemaphore
///
Semaphore mySemaphore;

#endif
