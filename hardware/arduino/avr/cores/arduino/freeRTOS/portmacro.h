/*
    FreeRTOS V8.2.3 - Copyright (C) 2015 Real Time Engineers Ltd.
    All rights reserved

    VISIT http://www.FreeRTOS.org TO ENSURE YOU ARE USING THE LATEST VERSION.

    This file is part of the FreeRTOS distribution.

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

/*
Changes from V1.2.3

	+ portCPU_CLOSK_HZ definition changed to 8MHz base 10, previously it
	  base 16.
*/

#ifndef PORTMACRO_H
#define PORTMACRO_H

#ifdef __cplusplus
extern "C" {
#endif

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the
 * given hardware and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#define portCHAR		char
#define portSTACK_TYPE	uint8_t
#define portBASE_TYPE	char

typedef portSTACK_TYPE	StackType_t;
typedef signed char		BaseType_t;
typedef unsigned char	UBaseType_t;

#if( configUSE_16_BIT_TICKS == 1 )
	typedef uint16_t TickType_t;
	#define portMAX_DELAY ( TickType_t ) 0xffffU
#else
	typedef uint32_t TickType_t;
	#define portMAX_DELAY ( TickType_t ) 0xffffffffUL
#endif
/*-----------------------------------------------------------*/

/* Critical section management. */
#define portENTER_CRITICAL()		__asm__ __volatile__ ( "in		__tmp_reg__, __SREG__" :: );	\
									__asm__ __volatile__ ( "cli" :: );								\
									__asm__ __volatile__ ( "push	__tmp_reg__" :: )

#define portEXIT_CRITICAL()			__asm__ __volatile__ ( "pop		__tmp_reg__" :: );				\
									__asm__ __volatile__ ( "out		__SREG__, __tmp_reg__" :: )

#define portDISABLE_INTERRUPTS()	__asm__ __volatile__ ( "cli" :: );
#define portENABLE_INTERRUPTS()		__asm__ __volatile__ ( "sei" :: );

/*-----------------------------------------------------------*/

/**
	Enable the watchdog timer, configuring it for expire after
	(value) timeout (which is a combination of the WDP0
	through WDP3 bits).

	This function is derived from <avr/wdt.h> but enables only
	the interrupt bit (WDIE), rather than the reset bit (WDE).

	Can't find it documented but the WDT, once enabled,
	rolls over and fires a new interrupt each time.

	See also the symbolic constants WDTO_15MS et al.
*/
#define wdt_interrupt_enable(value)     \
					__asm__ __volatile__ (                                      \
										"in __tmp_reg__,__SREG__" "\n\t"        \
										"cli" "\n\t"                            \
										"wdr" "\n\t"                            \
										"sts %0,%1" "\n\t"                      \
										"out __SREG__,__tmp_reg__" "\n\t"       \
										"sts %0,%2" "\n\t"                      \
										: /* no outputs */                      \
										: "M" (_SFR_MEM_ADDR(_WD_CONTROL_REG)), \
										"r" (_BV(_WD_CHANGE_BIT) | _BV(WDE)),   \
										"r" ((uint8_t) ((value & 0x08 ? _WD_PS3_MASK : 0x00) |   \
												_BV(WDIF) | _BV(WDIE) | (value & 0x07)) )        \
										: "r0"                                  \
										)

/*-----------------------------------------------------------*/

/* Architecture specifics. */
#define portSTACK_GROWTH			( -1 )
#define portBYTE_ALIGNMENT			1
#define portNOP()					__asm__ __volatile__ ( "nop" );

/* Timing for the scheduler.
 * Watchdog Timer is 128kHz nominal,
 * but 120 kHz at 5V DC and 25 degrees is actually more accurate,
 * from data sheet.
 */
#define portTICK_PERIOD_MS			( (TickType_t) _BV( portUSE_WDTO + 4 ) )	// Inaccurately assuming 128 kHz Watchdog Timer.
// #define portTICK_PERIOD_MS		( (TickType_t)( (uint32_t) _BV( portUSE_WDTO + 11 ) / 128 ) )	// If you want accuracy, read datasheet.

/*-----------------------------------------------------------*/

/* Kernel utilities. */
extern void vPortYield( void )		__attribute__ ( ( naked ) );
#define portYIELD()					vPortYield()

/*-----------------------------------------------------------*/

#if defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__)
/* Task function macros as described on the FreeRTOS.org WEB site. */
// This changed to add .lowtext tag for the linker for ATmega2560 and ATmega2561. To make sure they are loaded in low memory.
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters ) __attribute__ ((section (".lowtext")))
#else
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters ) void vFunction( void *pvParameters )
#endif

#define portTASK_FUNCTION( vFunction, pvParameters ) void vFunction( void *pvParameters )

#ifdef __cplusplus
}
#endif

#endif /* PORTMACRO_H */

