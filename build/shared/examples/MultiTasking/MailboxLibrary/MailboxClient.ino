///
/// @file		MailboxClient.ino
/// @brief		Task for Energia MT
/// @details	<#details#>
/// @n
/// @n @b		Project EMT-mailbox
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
///
/// @date		Jun 14, 2015 15:51
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///



// Core library for code-sense - IDE-based
#if defined(EMBEDXCODE)
#if defined(ENERGIA) && defined(__MSP432P401R__) // LaunchPad MSP432 on Energia MT only
#include "Energia.h"
#else
#error LaunchPad MSP432 on Energia MT only
#endif
#endif // end IDE

// Include application, user and local libraries
#include "Mailbox.h"
#include "rtosGlobals.h"


// Prototypes


// Define variables and constants
myMessage_t messageB;


// Setup
void MailboxClient_setup()
{
    //    Serial.begin(115200);
    //
    //    myMailbox.begin();
    
    delay(100);
}

// Loop
void MailboxClient_loop()
{
    myMailbox.waitFor(messageB);
    
    mySemaphore.waitFor();
    Serial.print("*<\t");
    Serial.print(millis(), DEC);
    Serial.print("\tRX\t");
    Serial.print(messageB.chrono, DEC);
    Serial.print("\t");
    Serial.print(messageB.buffer);
    Serial.print("\t");
    Serial.print(myMailbox.available());
    Serial.println("\t:\t");
    mySemaphore.post();
 
    delay(300);
}

