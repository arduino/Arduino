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

// Results
// SPI port 0: ok
// SPI port 1: ok
// SPI port 2: ok
// SPI port 3: ok
// max speed: SPI_CLOCK_DIV4

#define mySPI SPI                                                               // SPI0 SPI1 SPI=SPI2 SPI3
#define SPI_SRAM_SIZE 640                                                       // 640 1024
#define PIN_SRAM_CS PE_2

///
/// @brief	SRAM codes
///
/// @{
#define RDSR        5
#define WRSR        1
#define READ        3
#define WRITE       2
/// @}

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

  for (uint8_t j=0; j<10; j++) {

    Serial.print("write: ");

    digitalWrite(pinSRAM_CS, LOW);
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
    digitalWrite(pinSRAM_CS, HIGH);

    digitalWrite(pinSRAM_CS, LOW);
    mySPI.transfer(WRSR);
    mySPI.transfer(SRAM_SEQUENCE_MODE);
    digitalWrite(pinSRAM_CS, HIGH);
    Serial.println();

    Serial.print("read:  ");

    digitalWrite(pinSRAM_CS, LOW);
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
    digitalWrite(pinSRAM_CS, HIGH);
    Serial.println();
  }
  Serial.println();
}


void setup(void) {
  Serial.begin(9600);
  delay(100);
  Serial.println("SRAM test");
  Serial.println("---");

  mySPI.begin();
  mySPI.setClockDivider(SPI_CLOCK_DIV4); // for LM4F with 16000000
  mySPI.setBitOrder(MSBFIRST);
  mySPI.setDataMode(SPI_MODE0); 

  pinMode(PIN_SRAM_CS, OUTPUT);
  digitalWrite(PIN_SRAM_CS, LOW);
  mySPI.transfer(WRSR);
  mySPI.transfer(SRAM_SEQUENCE_MODE);
  digitalWrite(PIN_SRAM_CS, HIGH);

  testSRAM(PIN_SRAM_CS);
  Serial.println("---");

}

void loop() {

}

















