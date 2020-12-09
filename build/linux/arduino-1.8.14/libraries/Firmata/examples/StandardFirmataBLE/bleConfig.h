/*==================================================================================================
 * BLE CONFIGURATION
 *
 * If you are using an Arduino 101, you do not need to make any changes to this file (unless you
 * need a unique ble local name (see below). If you are using another supported BLE board or shield,
 * follow the instructions for the specific board or shield below.
 *
 * Make sure you have the Intel Curie Boards package v2.0.2 or higher installed via the Arduino
 * Boards Manager.
 *
 * Supported boards and shields:
 * - Arduino 101 (recommended)
 * - RedBearLab BLE Shield (v2)  ** to be verified **
 * - RedBearLab BLE Nano ** works with modifications **
 * - Adafruit Feather M0 Bluefruit LE
 *
 *================================================================================================*/

// change this to a unique name per board if running StandardFirmataBLE on multiple boards
// within the same physical space
#define FIRMATA_BLE_LOCAL_NAME "FIRMATA"

/*
 * Arduino 101
 *
 * Make sure you have the Intel Curie Boards package v2.0.2 or higher installed via the Arduino
 * Boards Manager.
 *
 * Test script: https://gist.github.com/soundanalogous/927360b797574ed50e27
 */
#ifdef _VARIANT_ARDUINO_101_X_
// After conversion to units of 1.25ms, both values must be between
// 0x0006 (7.5ms) and 0x0c80 (4s)
#define FIRMATA_BLE_MIN_INTERVAL 8  // ( 8 * 1000) / 1250 == 0x06 -> 7.5ms
#define FIRMATA_BLE_MAX_INTERVAL 30 // (30 * 1000) / 1250 == 0x18 -> 30ms
#endif


/*
 * RedBearLab BLE Shield
 *
 * If you are using a RedBearLab BLE shield, uncomment the define below.
 * Also, change the define for BLE_RST if you have the jumper set to pin 7 rather than pin 4.
 *
 * You will need to use the shield with an Arduino Zero, Due, Mega, or other board with sufficient
 * Flash and RAM. Arduino Uno, Leonardo and other ATmega328p and Atmega32u4 boards to not have
 * enough memory to run StandardFirmataBLE.
 *
 * TODO: verify if this works and with which boards it works.
 *
 * Test script: https://gist.github.com/soundanalogous/927360b797574ed50e27
 */
//#define REDBEAR_BLE_SHIELD

#ifdef REDBEAR_BLE_SHIELD
#define BLE_REQ  9
#define BLE_RDY  8
#define BLE_RST  4 // 4 or 7 via jumper on shield
#endif


/*
 * Adafruit Feather M0 Bluefruit LE
 *
 * If you are using an Adafruit Feather M0 Bluefruit LE, uncomment the define below.
 * This configuration should also work with other Bluefruit LE boards/modules that communicate
 * with the nRF51822 via SPI (e.g. Bluefruit LE SPI Friend, Bluefruit LE Shield), although
 * you may need to change the values of BLE_SPI_CS, BLE_SPI_IRQ, and/or BLE_SPI_RST below.
 *
 * You will need to install a lightly-modified version of the Adafruit BluefruitLE nRF51
 * package, available at:
 * https://github.com/cstawarz/Adafruit_BluefruitLE_nRF51/archive/firmata_fixes.zip
 */
//#define BLUEFRUIT_LE_SPI

#ifdef BLUEFRUIT_LE_SPI
// Both values must be between 10ms and 4s
#define FIRMATA_BLE_MIN_INTERVAL 10 // 10ms
#define FIRMATA_BLE_MAX_INTERVAL 20 // 20ms

#define BLE_SPI_CS   8
#define BLE_SPI_IRQ  7
#define BLE_SPI_RST  4
#endif


/*
 * Generic settings
 */
#if !defined(FIRMATA_BLE_MIN_INTERVAL) && !defined(FIRMATA_BLE_MAX_INTERVAL)
// These values apply to all devices using the Arduino BLEPeripheral library
// with a Nordic nRF8001 or nRF51822.  Both values must be between
// 0x0006 (7.5ms) and 0x0c80 (4s).
#define FIRMATA_BLE_MIN_INTERVAL 0x0006 // 7.5ms (7.5 / 1.25)
#define FIRMATA_BLE_MAX_INTERVAL 0x0018 // 30ms (30 / 1.25)
#endif

#if !defined(FIRMATA_BLE_TXBUFFER_FLUSH_INTERVAL)
#define FIRMATA_BLE_TXBUFFER_FLUSH_INTERVAL 30 // 30ms
#endif


/*==================================================================================================
 * END BLE CONFIGURATION - you should not need to change anything below this line
 *================================================================================================*/

#ifdef _VARIANT_ARDUINO_101_X_
#include "utility/BLEStream.h"
BLEStream stream;
#endif


#ifdef REDBEAR_BLE_SHIELD
#include <SPI.h>
#include "utility/BLEStream.h"
BLEStream stream(BLE_REQ, BLE_RDY, BLE_RST);
#endif


#ifdef BLUEFRUIT_LE_SPI
#include "utility/BluefruitLE_SPI_Stream.h"
BluefruitLE_SPI_Stream stream(BLE_SPI_CS, BLE_SPI_IRQ, BLE_SPI_RST);
#endif


/*
 * RedBearLab BLE Nano (with default switch settings)
 *
 * Blocked on this issue: https://github.com/RedBearLab/nRF51822-Arduino/issues/46
 * Works with modifications. See comments at top of the test script referenced below.
 * When the RBL nRF51822-Arduino library issue is resolved, this should work witout
 * any modifications.
 *
 * Test script: https://gist.github.com/soundanalogous/d39bb3eb36333a0906df
 *
 * Note: If you have changed the solder jumpers on the Nano you may encounter issues since
 * the pins are currently mapped in Firmata only for the default (factory) jumper settings.
 */
// #ifdef BLE_NANO
// #include "utility/BLEStream.h"
// BLEStream stream;
// #endif


/*
 * RedBearLab Blend and Blend Micro
 *
 * StandardFirmataBLE requires too much Flash and RAM to run on the ATmega32u4-based Blend
 * and Blend Micro boards. It may work with ConfigurableFirmata selecting only analog and/or
 * digital I/O.
 */
// #if defined(BLEND_MICRO) || defined(BLEND)
// #include <SPI.h>
// #include "utility/BLEStream.h"

// #define BLE_REQ  6
// #define BLE_RDY  7
// #define BLE_RST  4

// BLEStream stream(BLE_REQ, BLE_RDY, BLE_RST);
// #endif


#if defined(BLE_REQ) && defined(BLE_RDY) && defined(BLE_RST)
#define IS_IGNORE_BLE_PINS(p) ((p) == BLE_REQ || (p) == BLE_RDY || (p) == BLE_RST)
#elif defined(BLE_SPI_CS) && defined(BLE_SPI_IRQ) && defined(BLE_SPI_RST)
#define IS_IGNORE_BLE_PINS(p) ((p) == BLE_SPI_CS || (p) == BLE_SPI_IRQ || (p) == BLE_SPI_RST)
#endif
