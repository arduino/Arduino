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
#include "Semaphore.h"


///
/// @brief	Comment to remove the semaphore
///
#define optionSemaphore


///
/// @brief	Semaphore for Serial
///
Semaphore mySemaphore;


#endif
