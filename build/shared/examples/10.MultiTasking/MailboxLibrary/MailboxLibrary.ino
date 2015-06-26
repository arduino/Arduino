///
/// @mainpage	EMT-mailbox-template
///
/// @details	Mailbox library for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		Jun 14, 2015 17:18
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		EMT_mailbox_template.ino
/// @brief		Main sketch
///
/// @details	RTOS mailbox as an object
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		Jun 14, 2015 17:18
/// @version	101
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
///


// Core library for code-sense - IDE-based
#   include "Energia.h"

// Include application, user and local libraries
#include "Mailbox.h"
#include "rtosGlobals.h"

// Prototypes


// Define variables and constants
myMessage_t message1;


// Add setup code
void setup()
{
    Serial.begin(115200);

    Serial.print("?\tAction\tchrono");
    Serial.print("\tMessage");
    Serial.print("\t");
    Serial.print("");
    Serial.print("\t");
    Serial.print("available");
    Serial.print("\t:\t");
    Serial.println("result");
    
    Serial.print("?\t\t");
    Serial.print("\t.chrono");
    Serial.print("\t");
    Serial.print(".buffer");
    Serial.print("\t");
    Serial.print("");
    Serial.print("\t:\t");
    Serial.println("");
    
    mySemaphore.begin(1);
    myMailbox.begin(NUMBER); // default = 16
}

// Add loop code
void loop()
{
    message1.chrono = millis();
    strcpy(message1.buffer, "from 1");
    
    bool result = myMailbox.post(message1, MODALITY); // default = BIOS_WAIT_FOREVER
    
    mySemaphore.waitFor();
    Serial.print("1>\t");
    Serial.print(millis(), DEC);
    Serial.print("\tTX\t");
    Serial.print(message1.chrono, DEC);
    Serial.print("\t");
    Serial.print(message1.buffer);
    Serial.print("\t");
    Serial.print(myMailbox.available());
    Serial.print("\t:\t");
    Serial.println(result, DEC);
    mySemaphore.post();
    
    delay(500);
}
