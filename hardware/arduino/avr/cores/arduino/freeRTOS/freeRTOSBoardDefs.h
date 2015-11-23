/* freeRTOSBoardDefs.h
 *
 * Board (hardware) specific definitions for the AVR boards that I use regularly.
 * This includes
 * Arduino UNO with ATmega328p
 * Goldilocks with ATmega1284p
 * Arduino MEGA with ATmega2560
 *
 * And also Pololu SVP with ATmega1284p
 *
 * This file is NOT part of the FreeRTOS distribution.
 *
 */

#ifndef freeRTOSBoardDefs_h
#define freeRTOSBoardDefs_h

#ifdef __cplusplus
extern "C" {
#endif

#include <avr/io.h>
#include <avr/wdt.h>

// System Tick - Scheduler timer
// Prefer to use the Watchdog timer, and choose the rate at which scheduler interrupts will occur.

#define portUSE_WDTO			WDTO_30MS			// portUSE_WDTO to use the Watchdog Timer for xTaskIncrementTick

/* Watchdog period options: 	WDTO_15MS
								WDTO_30MS
								WDTO_60MS
								WDTO_120MS
								WDTO_250MS
								WDTO_500MS
*/
//	xxx Watchdog Timer is 128kHz nominal, but 120 kHz at 5V DC and 25 degrees is actually more accurate, from data sheet.
#define configTICK_RATE_HZ 			( (TickType_t)( (uint32_t)128000 >> (portUSE_WDTO + 11) ) )  // 2^11 = 2048 WDT Scale-factor

#ifdef __cplusplus
}
#endif

#endif // freeRTOSBoardDefs_h
