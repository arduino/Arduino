/*
    FreeRTOS V8.2.3 - This file is NOT part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation >>>> AND MODIFIED BY <<<< the FreeRTOS exception.

    ***************************************************************************
    >>!   NOTE: The modification to the GPL is included to allow you to     !<<
    >>!   distribute a combined work that includes FreeRTOS without being   !<<
    >>!   obliged to provide the source code for proprietary components     !<<
    >>!   outside of the FreeRTOS kernel.                                   !<<
    ***************************************************************************

    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE.  Full license text is available on the following
    link: http://www.freertos.org/a00114.html

    ***************************************************************************
     *                                                                       *
     *    FreeRTOS provides completely free yet professionally developed,    *
     *    robust, strictly quality controlled, supported, and cross          *
     *    platform software that is more than just the market leader, it     *
     *    is the industry's de facto standard.                               *
     *                                                                       *
     *    Help yourself get started quickly while simultaneously helping     *
     *    to support the FreeRTOS project by purchasing a FreeRTOS           *
     *    tutorial book, reference manual, or both:                          *
     *    http://www.FreeRTOS.org/Documentation                              *
     *                                                                       *
    ***************************************************************************

    http://www.FreeRTOS.org/FAQHelp.html - Having a problem?  Start by reading
    the FAQ page "My application does not run, what could be wrong?".  Have you
    defined configASSERT()?

    http://www.FreeRTOS.org/support - In return for receiving this top quality
    embedded software for free we request you assist our global community by
    participating in the support forum.

    http://www.FreeRTOS.org/training - Investing in training allows your team to
    be as productive as possible as early as possible.  Now you can receive
    FreeRTOS training directly from Richard Barry, CEO of Real Time Engineers
    Ltd, and the world's leading authority on the world's leading RTOS.

    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
    including FreeRTOS+Trace - an indispensable productivity tool, a DOS
    compatible FAT file system, and our tiny thread aware UDP/IP stack.

    http://www.FreeRTOS.org/labs - Where new FreeRTOS products go to incubate.
    Come and try FreeRTOS+TCP, our new open source TCP/IP stack for FreeRTOS.

    http://www.OpenRTOS.com - Real Time Engineers ltd. license FreeRTOS to High
    Integrity Systems ltd. to sell under the OpenRTOS brand.  Low cost OpenRTOS
    licenses offer ticketed support, indemnification and commercial middleware.

    http://www.SafeRTOS.com - High Integrity Systems also provide a safety
    engineered and independently SIL3 certified version for use in safety and
    mission critical applications that require provable dependability.

    1 tab == 4 spaces!
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#include <util/delay.h>

/* FreeRTOS includes. */
#include "freeRTOS/FreeRTOS.h"
#include "freeRTOS/task.h"
#include "freeRTOS/timers.h"
#include "freeRTOS/StackMacros.h"

#include "Arduino.h"

/*-----------------------------------------------------------*/

/**
 * Empty serialEventRun hook.
 *
 *
 * Its defined as a weak symbol and it can be redefined to implement a
 * real serial event handler.
 */

void serialEventRun(void) __attribute__((weak));
void serialEventRun(void)
{
}

/*-----------------------------------------------------------*/

/**
 * Empty yield() hook.
 *
 * This function is intended to be used by library writers to build
 * libraries or sketches that supports cooperative threads.
 *
 * Its defined as a weak symbol and it can be redefined to implement a
 * real cooperative scheduler.
 */
static void __empty() __attribute__((unused));
static void __empty() {
	;// Empty
}
void yield(void) __attribute__ ((weak, unused, alias("__empty")));

/*-----------------------------------------------------------*/

#if defined( configUSE_IDLE_HOOK )

/*
 * Call the user defined loop() function from within the idle task.
 * This allows the application designer to add background functionality
 * without the overhead of a separate task.
 *
 * NOTE: vApplicationIdleHook() MUST NOT, UNDER ANY CIRCUMSTANCES, CALL A FUNCTION THAT MIGHT BLOCK.
 *
 */
void vApplicationIdleHook( void ) __attribute__((weak));
void vApplicationIdleHook( void )
{
	loop();
	if (serialEventRun) serialEventRun();
}

#endif /* configUSE_IDLE_HOOK == 1 */

/*--------------------------------------------------*/

#if defined( configUSE_MALLOC_FAILED_HOOK )

/*---------------------------------------------------------------------------*\
Usage:
   called by task system when a malloc failure is noticed
Description:
   Malloc failure handler -- Shut down all interrupts, send serious complaint
    to command port. FAST Blink.
Arguments:
   pxTask - pointer to task handle
   pcTaskName - pointer to task name
Results:
   <none>
Notes:
   This routine will never return.
   This routine is referenced in the task.c file of FreeRTOS as an extern.
\*---------------------------------------------------------------------------*/

void vApplicationMallocFailedHook( void ) __attribute__((weak));
void vApplicationMallocFailedHook( void )
{
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__) // Mega with 2560
	DDRB  |= _BV(DDB7);
	PORTB |= _BV(PORTB7);       // Main (red PB7) LED on. Main LED on.

#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega1284PA__) // Goldilocks with 1284p
	DDRB  |= _BV(DDB7);
	PORTB |= _BV(PORTB7);       // Main (red PB7) LED on. Main LED on.

#elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) // assume we're using an Arduino with 328p
	DDRB  |= _BV(DDB5);
	PORTB |= _BV(PORTB5);       // Main (red PB5) LED on. Main LED on.

#endif

	for(;;)
	{
		_delay_ms(50);
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)  // Mega with 2560
		PINB  |= _BV(PINB7);       // Main (red PB7) LED toggle. Main LED fast blink.

#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega1284PA__) // Goldilocks with 1284p
		PINB  |= _BV(PINB7);       // Main (red PB7) LED toggle. Main LED fast blink.

#elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) // assume we're using an Arduino with 328p
		PINB  |= _BV(PINB5);       // Main (red PB7) LED toggle. Main LED fast blink.

#endif

	}
}

#endif /* configUSE_MALLOC_FAILED_HOOK == 1 */

/*--------------------------------------------------*/

#if defined( configCHECK_FOR_STACK_OVERFLOW )

/*---------------------------------------------------------------------------*\
Usage:
   called by task system when a stack overflow is noticed
Description:
   Stack overflow handler -- Shut down all interrupts, send serious complaint
    to command port. SLOW Blink.
Arguments:
   pxTask - pointer to task handle
   pcTaskName - pointer to task name
Results:
   <none>
Notes:
   This routine will never return.
   This routine is referenced in the task.c file of FreeRTOS as an extern.
\*---------------------------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t xTask, portCHAR *pcTaskName ) __attribute__((weak));
void vApplicationStackOverflowHook( TaskHandle_t xTask, portCHAR *pcTaskName )
{
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)  // Mega with 2560
	DDRB  |= _BV(DDB7);
	PORTB |= _BV(PORTB7);       // Main (red PB7) LED on. Main LED on.

#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega1284PA__) // Goldilocks with 1284p
	DDRB  |= _BV(DDB7);
	PORTB |= _BV(PORTB7);       // Main (red PB7) LED on. Main LED on.

#elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) // assume we're using an Arduino with 328p
	DDRB  |= _BV(DDB5);
	PORTB |= _BV(PORTB5);       // Main (red PB5) LED on. Main LED on.

#endif

	for(;;)
	{
		_delay_ms(2000);
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)  // Mega with 2560
		PINB  |= _BV(PINB7);       // Main (red PB7) LED toggle. Main LED slow blink.

#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega1284PA__) // Goldilocks with 1284p
		PINB  |= _BV(PINB7);       // Main (red PB7) LED toggle. Main LED slow blink.

#elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) // assume we're using an Arduino with 328p
		PINB  |= _BV(PINB5);       // Main (red PB7) LED toggle. Main LED slow blink.

#endif

	}
}

#endif /* configCHECK_FOR_STACK_OVERFLOW == 1 */
/*-----------------------------------------------------------*/
