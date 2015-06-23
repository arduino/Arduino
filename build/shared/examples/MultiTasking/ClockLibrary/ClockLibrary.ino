///
/// @mainpage	EMT-ClockLibrary
///
/// @details	Clock Library for Energia MT
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		18/06/2015 09:49
/// @version	<#version#>
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///


///
/// @file		EMT_ClockLibrary.ino
/// @brief		Main sketch
///
/// @details	<#details#>
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		Rei Vilo
/// @author		http://embeddedcomputing.weebly.com
/// @date		18/06/2015 09:49
/// @version	<#version#>
///
/// @copyright	(c) Rei Vilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
/// @n
/// @example    ReadMe.txt
///


// Core library for code-sense - IDE-based
#   include "Energia.h"


// Include application, user and local libraries
#include "rtosGlobals.h"
#include "Clock.h"

// Prototypes

// Define variables and constants
Clock myClock;

#define MAXCOUNT 16
uint8_t i = 0;
uint32_t chrono[MAXCOUNT];

#define initialPeriod 1000
#define repeatedPeriod 100

uint8_t status = 0;
const uint8_t myLED = BLUE_LED;

void clockFunction()
{
    chrono[i] = micros();
    i++;
    status = 1 - status;
    digitalWrite(myLED, status);
    Serial.print(".");
}


// Add setup code
void setup()
{
    Serial.begin(115200);
    Serial.println("*** Clock Library");
    
    pinMode(myLED, OUTPUT);
    
    xdc_runtime_Types_FreqHz freq;
    BIOS_getCpuFreq(&freq);
    Serial.print("FreqHz.hi = ");
    Serial.println(freq.hi, DEC);
    Serial.print("FreqHz.lo = ");
    Serial.println(freq.lo, DEC);
    Serial.print("microsecondsToClockCycles = ");
    Serial.println(microsecondsToClockCycles(1), DEC);
    
    Serial.print("myClock.begin... ");
    myClock.begin(clockFunction, initialPeriod, repeatedPeriod); // 1000 ms = 1 s
    Serial.println("done");
    
    Serial.print("myClock.start... ");
    myClock.start();
    Serial.println("done");
    chrono[i] = micros();
    i++;

    Serial.print("# 0,\tus = ");
    Serial.println(chrono[0], DEC);
}

void printX10(int32_t number)
{
    Serial.print(number / 10, DEC);
    Serial.print(".");
    if (number < 0) number *= -1;
    Serial.print(number % 10, DEC);
}

// Add loop code
void loop()
{
    if (i >= MAXCOUNT)
    {
        myClock.stop();
        Serial.println();
        
        for (uint8_t j = 1; j < MAXCOUNT; j++)
        {
            Serial.print("# ");
            Serial.print(j, DEC);
            Serial.print(",\tus = ");
            Serial.print(chrono[j], DEC);
            Serial.print(" - ");
            Serial.print(chrono[j-1], DEC);
            Serial.print(" = ");
            Serial.println(chrono[j] - chrono[j-1], DEC);
        }
        Serial.println();
        
        Serial.print("Initial period quality = ");
        printX10((int32_t)(chrono[1] - chrono[0]) / initialPeriod -1000);
        Serial.println("%");
        
        if (repeatedPeriod > 0)
        {
            Serial.print("Repeated period quality = ");
            printX10((int32_t)(chrono[MAXCOUNT -1] - chrono[1]) / (MAXCOUNT -2) / repeatedPeriod -1000);
            Serial.println("%");
        }
        
        Serial.println("***");
        while (1);
    }
    
    delay(100);
}

