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
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "StackMacros.h"

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
static void __empty() {
	// Empty
}
void yield(void) __attribute__ ((weak, alias("__empty")));

/*-----------------------------------------------------------*/

//#if( configUSE_IDLE_HOOK == 1 )
#if 0

void vApplicationIdleHook( void )
{

	// There are several macros provided in this header file to actually put the device into sleep mode.
	// The simplest way is to optionally set the desired sleep mode using set_sleep_mode()
	// (it usually defaults to idle mode where the CPU is put on sleep but all peripheral clocks are still running),
	// and then call sleep_mode(). This macro automatically sets the sleep enable bit,
	// goes to sleep, and clears the sleep enable bit.

	// SLEEP_MODE_IDLE         (0)
	// SLEEP_MODE_ADC          _BV(SM0)
	// SLEEP_MODE_PWR_DOWN     _BV(SM1)
	// SLEEP_MODE_PWR_SAVE     (_BV(SM0) | _BV(SM1))
	// SLEEP_MODE_STANDBY      (_BV(SM1) | _BV(SM2))
	// SLEEP_MODE_EXT_STANDBY  (_BV(SM0) | _BV(SM1) | _BV(SM2))

	set_sleep_mode( SLEEP_MODE_IDLE );

	// Analogue Comparator Disable
	// When the ACD bit is written logic one, the power to the Analogue Comparator is switched off.
	// This bit can be set at any time to turn off the Analogue Comparator.
	// This will reduce power consumption in Active and Idle mode.
	// When changing the ACD bit, the Analogue Comparator Interrupt must be disabled by clearing the ACIE bit in ACSR.
	// Otherwise an interrupt can occur when the ACD bit is changed.
	ACSR &= ~_BV(ACIE);
	ACSR |=  _BV(ACD);

	// Digital Input Disable on Analogue Pins
	// When this bit is written logic one, the digital input buffer on the corresponding ADC pin is disabled.
	// The corresponding PIN Register bit will always read as zero when this bit is set. When an
	// analogue signal is applied to the ADC7..0 pin and the digital input from this pin is not needed, this
	// bit should be written logic one to reduce power consumption in the digital input buffer.

#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__) // Mega with 2560
	DIDR0 = 0xFF;

#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega1284PA__) // Goldilocks with 1284p
	DIDR0 = 0xFF;

#elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__) // assume we're using an Arduino with 328p
	DIDR0 = 0x3F;

#endif

	portENTER_CRITICAL();
	sleep_enable();

#if defined(BODS) && defined(BODSE) // only if there is support to disable the BOD.
	sleep_bod_disable();
#endif

	portEXIT_CRITICAL();
	sleep_cpu();		// good night.

	// Uhh. I was woken up, so now disable sleep_mode.
	sleep_disable();
}

#endif /* configUSE_IDLE_HOOK == 1 */


#if defined( configUSE_MALLOC_FAILED_HOOK)

void vApplicationMallocFailedHook( void )
{
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
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)
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

void vApplicationStackOverflowHook( TaskHandle_t xTask, portCHAR *pcTaskName )
{
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
#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)
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
