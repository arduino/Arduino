///
/// @file	SPI_23LC1024.ino
/// @brief	Example for SPI with SRAM
///
/// @details	Example for SPI
/// @n
/// Place pull-up resistor on MISO and SCK and capacitor
///
/// @see http://forum.stellarisiti.com/topic/442-energia-library-stellaris-launchpad-fatfs-energia-library/?p=3420
/// 2013-07-03
///
/// Use the following components and wire routing:
/// * LaunchPad Stellaris
/// * Microchip 23K640 or 23LC1024
/// * 10k pull-up resistors
/// * 100nF capacitor
///
/// @n @a	Developed with [embedXcode](http://embedXcode.weebly.com)
///
/// @author	Rei VILO
/// @author	http://embedXcode.weebly.com
/// @date	Jul 08, 2013
/// @version	101
///
/// @copyright	© Rei VILO, 2013
/// @copyright	CC = BY NC SA
///
/// @see	ReadMe.txt for references
/// @n
///


// Core library for code-sense
#include "Energia.h"
#include "SPI.h"
#include "FastDigitalWrite.h"

#include "SPI.h"

// Results
// SPI port 0: ok
// SPI port 1: ok
// SPI port 2: ok, DIV4 max
// SPI port 3: ok

#define mySPI SPI                                                               // SPI0 SPI1 SPI=SPI2 SPI3
#define SPI_SRAM_SIZE 640                                                       // 640 1024
#define PIN_SRAM_CS PE_2

///
/// @brief	SRAM commands
///
/// @{
#define SRAM_BYTE_MODE     0b00000000  ///< Byte mode (default operation)
#define SRAM_PAGE_MODE     0b10000000  ///< Page mode
#define SRAM_SEQUENCE_MODE 0b01000000  ///< Sequential mode
#define SRAM_RESERVED_MODE 0b11000000  ///< Reserved
#define SRAM_HOLD_MODE     0b00000001  ///< Set this bit to DISABLE hold mode
/// @}

void testSRAM(uint8_t pinSRAM_CS)
{
    uint32_t i;
    uint8_t value;
    pinMode(pinSRAM_CS, OUTPUT);
    uint32_t address = 100;
    fastDigitalOutputPin _pin(PE_2);
    
    for (uint8_t j=0; j<10; j++) {
        
        Serial.print("write: ");
        
        _pin.setLOW();
        mySPI.transfer(WRITE);

#if (SPI_SRAM_SIZE == 1024)
        mySPI.transfer((uint8_t)(address >> 16) & 0xff);                        // 1024 = 24-bit address
#endif                                                                          // 640 = 16-bit adress

        mySPI.transfer((uint8_t)(address >> 8) & 0xff);
        mySPI.transfer((uint8_t)address);
        
        for (i=0; i<26; i++) {
            value = (i+j) % 26;
            mySPI.transfer((uint8_t)('A'+value));
            Serial.print((char)('A'+value));
            Serial.print(".");
        }
        _pin.setHIGH();
        Serial.println();
        
        _pin.setLOW();
        mySPI.transfer(WRSR);
        mySPI.transfer(SRAM_SEQUENCE_MODE);
        _pin.setHIGH();
        
        Serial.print("read:  ");
        
        _pin.setLOW();
        mySPI.transfer(READ);

#if (SPI_SRAM_SIZE == 1024)
        mySPI.transfer((uint8_t)(address >> 16) & 0xff);
#endif

        mySPI.transfer((uint8_t)(address >> 8) & 0xff);
        mySPI.transfer((uint8_t)address);
        
        for (i=0; i<26; i++) {
            value = mySPI.transfer(0);
            Serial.print((char)value);
            Serial.print(".");
        }
        _pin.setHIGH();
        Serial.println();
    }
    Serial.println();
}

void testFastPin(uint8_t pin)
{
    uint32_t chrono;
    pinMode(pin, OUTPUT);
    Serial.println("1000 cycles, time in microseconds");
    Serial.println("1 second = 10^9 microseconds");
    Serial.println();
    Serial.print("digitalWrite()\t");
    chrono = micros();
    for (uint16_t i=0; i<1000; i++) {
        digitalWrite(pin, HIGH);
        digitalWrite(pin, LOW);
    }
    Serial.println(micros() - chrono, DEC);
    
    fastDigitalOutputPin myPin(pin);
    
    Serial.print("fast setHIGH() setLOW()\t");
    chrono = micros();
    for (uint16_t i=0; i<1000; i++) {
        myPin.setHIGH();
        myPin.setLOW();
    }
    Serial.println(micros() - chrono, DEC);
    
    Serial.print("fast set()\t");
    chrono = micros();
    for (uint16_t i=0; i<1000; i++) {
        myPin.set(HIGH);
        myPin.set(LOW);
    }
    Serial.println(micros() - chrono, DEC);
    Serial.println();
}

void testLogicAnalyser(uint8_t pin)
{
    pinMode(pin, OUTPUT);
    Serial.println("digitalWrite(HIGH)");
    Serial.println("digitalWrite(LOW)");
    digitalWrite(pin, HIGH);
    digitalWrite(pin, LOW);
    delay(10);

    fastDigitalOutputPin myPin(pin);

    Serial.println("setHIGH()");
    Serial.println("setLOW()");
    myPin.setHIGH();
    myPin.setLOW();
    delay(10);
    Serial.println("pulseHIGH()");
    myPin.pulseHIGH();
    delay(10);
    Serial.println("setHIGH()");
    myPin.setHIGH();
    delay(10);
    Serial.println("pulseLOW()");
    myPin.pulseLOW();
    delay(10);
    Serial.println("pulseLOW() x2");
    myPin.pulseLOW();
    myPin.pulseLOW();
    Serial.println("setLOW()");
    myPin.setLOW();
    delay(1000);
}

void setup(void) {
    Serial.begin(9600);
    delay(100);
    
//    testLogicAnalyser(PA_7);
//    while (true);

    testFastPin(RED_LED);
    
    mySPI.begin();
    mySPI.setClockDivider(SPI_CLOCK_DIV4); // for LM4F with 16000000
    mySPI.setBitOrder(MSBFIRST);
    mySPI.setDataMode(SPI_MODE0); // SPI_MODE0
    
    pinMode(PIN_SRAM_CS, OUTPUT);
    digitalWrite(PIN_SRAM_CS, LOW);
    mySPI.transfer(WRSR);
    mySPI.transfer(SRAM_SEQUENCE_MODE);
    digitalWrite(PIN_SRAM_CS, HIGH);
    
    testSRAM(PIN_SRAM_CS);
}

void loop() {
    
}














