/*
 ************************************************************************
 *	wiring.c
 *
 *	Arduino core files for MSP430
 *		Copyright (c) 2012 Robert Wessels. All right reserved.
 *
 *
 ***********************************************************************
  Derived from:
  wiring.c - Partial implementation of the Wiring API for the ATmega8.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
 */
#include "Energia.h"
#include "inc/hw_ints.h"
#include "inc/hw_timer.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

static void (*SysTickCbFuncs[8])(uint32_t ui32TimeMS);

#define SYSTICKMS               (1000 / SYSTICKHZ)
#define SYSTICKHZ               1000
#define DEEPSLEEP_CPU		(16000000 / 16)    // PIOSC / 16

static void SysTickMode_DeepSleep(void);
static void SysTickMode_DeepSleepCoarse(void);
static void SysTickMode_Run(void);
static void CPUwfi_safe(void);

static unsigned long milliseconds = 0;
#define SYSTICK_INT_PRIORITY    0x80
void timerInit()
{
#ifdef TARGET_IS_BLIZZARD_RB1
    //
    //  Run at system clock at 80MHz
    //
    MAP_SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|
                       SYSCTL_OSC_MAIN);
#else
    //
    //  Run at system clock at 120MHz
    //
    MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ|SYSCTL_OSC_MAIN|SYSCTL_USE_PLL|SYSCTL_CFG_VCO_480), F_CPU);
#endif

    //
    //  SysTick is used for delay() and delayMicroseconds()
    //

    MAP_SysTickPeriodSet(F_CPU / SYSTICKHZ);
    MAP_SysTickEnable();
    MAP_IntPrioritySet(FAULT_SYSTICK, SYSTICK_INT_PRIORITY);
    MAP_SysTickIntEnable();
    MAP_IntMasterEnable();
}

unsigned long micros(void)
{
	return (milliseconds * 1000) + ( ((F_CPU / SYSTICKHZ) - MAP_SysTickValueGet()) / (F_CPU/1000000));
}

unsigned long millis(void)
{
	return milliseconds;
}

void delayMicroseconds(unsigned int us)
{
	// Systick timer rolls over every 1000000/SYSTICKHZ microseconds 
	if (us > (1000000UL / SYSTICKHZ - 1)) {
		delay(us / 1000);  // delay milliseconds
		us = us % 1000;     // handle remainder of delay
	};

	// 24 bit timer - mask off undefined bits
	unsigned long startTime = HWREG(NVIC_ST_CURRENT) & NVIC_ST_CURRENT_M;

	unsigned long ticks = (unsigned long)us * (F_CPU/1000000UL);
	volatile unsigned long elapsedTime;

	if (ticks > startTime) {
		ticks = (ticks + (NVIC_ST_CURRENT_M - (unsigned long)F_CPU / SYSTICKHZ)) & NVIC_ST_CURRENT_M;
	}

	do {
		elapsedTime = (startTime-(HWREG(NVIC_ST_CURRENT) & NVIC_ST_CURRENT_M )) & NVIC_ST_CURRENT_M;
	} while(elapsedTime <= ticks);
}

void delay(uint32_t millis)
{
	unsigned long i;
	for(i=0; i<millis*2; i++){
		delayMicroseconds(500);
	}
}


volatile boolean stay_asleep = false;

void sleep(uint32_t ms)
{
	unsigned long i;

	i = milliseconds;
	i += ms;
	stay_asleep = true;

	HWREG(NVIC_SYS_CTRL) |= NVIC_SYS_CTRL_SLEEPDEEP;

	while ( stay_asleep && (milliseconds < i) ) {
		MAP_IntMasterDisable();  // Set PRIMASK so CPU wakes on IRQ but ISRs don't execute until PRIMASK is cleared
		SysTickMode_DeepSleep();

		CPUwfi_safe();

		// Handle low-power SysTick triggers without using the default SysTickIntHandler
		if (HWREG(NVIC_INT_CTRL) & NVIC_INT_CTRL_PENDSTSET) {
			milliseconds += 50;
			MAP_IntPendClear(FAULT_SYSTICK);
		} else {
			milliseconds += ((DEEPSLEEP_CPU / (1000/50)) - MAP_SysTickValueGet()) / (DEEPSLEEP_CPU / 1000);
		}

		// Restore SysTick to normal parameters in preparation for full-speed ISR execution
		SysTickMode_Run();
		MAP_IntMasterEnable();  // Clearing PRIMASK allows pending ISRs to run
	}

	HWREG(NVIC_SYS_CTRL) &= ~(NVIC_SYS_CTRL_SLEEPDEEP);
	stay_asleep = false;
}

void sleepSeconds(uint32_t seconds)
{
	unsigned long i;

	i = milliseconds;
	i += seconds * 1000;

	stay_asleep = true;

	HWREG(NVIC_SYS_CTRL) |= NVIC_SYS_CTRL_SLEEPDEEP;

	while ( stay_asleep && (milliseconds < i) ) {
		MAP_IntMasterDisable();  // Set PRIMASK so CPU wakes on IRQ but ISRs don't execute until PRIMASK is cleared
		SysTickMode_DeepSleepCoarse();

		CPUwfi_safe();

		// Handle low-power SysTick triggers without using the default SysTickIntHandler
		if (HWREG(NVIC_INT_CTRL) & NVIC_INT_CTRL_PENDSTSET) {
			milliseconds += 1000;
			MAP_IntPendClear(FAULT_SYSTICK);
		} else {
			milliseconds += (DEEPSLEEP_CPU - MAP_SysTickValueGet()) / (DEEPSLEEP_CPU / 1000);
		}

		// Restore SysTick to normal parameters in preparation for full-speed ISR execution
		SysTickMode_Run();
		MAP_IntMasterEnable();  // Clearing PRIMASK allows pending ISRs to run
	}

	HWREG(NVIC_SYS_CTRL) &= ~(NVIC_SYS_CTRL_SLEEPDEEP);
	stay_asleep = false;
}

void suspend(void)
{
	stay_asleep = true;

	HWREG(NVIC_SYS_CTRL) |= NVIC_SYS_CTRL_SLEEPDEEP;

	while(stay_asleep) {
		MAP_IntMasterDisable();  // Set PRIMASK so CPU wakes on IRQ but ISRs don't execute until PRIMASK is cleared
		MAP_SysTickDisable();  // Halt SysTick during suspend mode - millis will no longer increment

		CPUwfi_safe();

		MAP_SysTickEnable();   // Re-enable SysTick before ISRs start (in case ISR uses millis/micros)
		MAP_IntMasterEnable();  // Clearing PRIMASK allows pending ISRs to run
	}

	HWREG(NVIC_SYS_CTRL) &= ~(NVIC_SYS_CTRL_SLEEPDEEP);
}

void registerSysTickCb(void (*userFunc)(uint32_t))
{
	uint8_t i;
	for (i=0; i<8; i++) {
		if(!SysTickCbFuncs[i]) {
			SysTickCbFuncs[i] = userFunc;
			break;
		}
	}
}

void SysTickIntHandler(void)
{
	milliseconds++;

	uint8_t i;
	for (i=0; i<8; i++) {
		if (SysTickCbFuncs[i])
			SysTickCbFuncs[i](SYSTICKMS);
	}
}

static void SysTickMode_DeepSleep(void)
{
	MAP_SysTickPeriodSet(DEEPSLEEP_CPU / (1000/50));  // 50ms
	HWREG(NVIC_ST_CURRENT) = 0;  // Clear SysTick
}

static void SysTickMode_DeepSleepCoarse(void)
{
	MAP_SysTickPeriodSet(DEEPSLEEP_CPU);  // 1sec
	HWREG(NVIC_ST_CURRENT) = 0;  // Clear SysTick
}

static void SysTickMode_Run(void)
{
	MAP_SysTickPeriodSet(F_CPU / SYSTICKHZ);
	HWREG(NVIC_ST_CURRENT) = 0;
}

/* SYSCTL#04 from TM4C123 errata
 *
 * Device May not Wake Correctly From Sleep Mode Under Certain Circumstances
 *
 * With a certain configuration, the device may not wake correctly from Sleep mode
 * because invalid data may be fetched from the prefetch buffer.  The configuration that
 * causes this issue is as follows:
 *  * The system clock must be at least 40 MHz
 *  * Interrupts must be disabled
 *
 * Note: While our exact circumstances do not seem to match these, what I did notice was an instruction
 * appeared to be missing or did not execute in the code shortly after CPUwfi() when using the driverlib
 * version.  This version appears to fix the issue.
 */
static void CPUwfi_safe(void)
{
	asm volatile ("wfi              \n"\
		      "mov r0, #0       \n");  // force bx lr to not start until after clocks back on
}
