/*
 OneMsTaskTimer.cpp - Leveraging tasks using a timer with 1ms resolution
 
 History:
 got inspired by Arduino MsTimer2 by Javier Valencia <javiervalencia80@gmail.com>
 11/Nov/14 - Made more flexible for MSP430 variants
             set to 1ms overflow time -> change to OneMsTaskTimer
			 by Stefan Sch
 17/Nov/14 - restructured code to support mulitple tasks 
             added suppport for CC3200
			 by Stefan Sch
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

/*
 MSP430 Notes:
 This timer currently uses Timer1 available on chips like the MSP430G2553
 It uses CCR0 in interrupt mode with the same period as PWM so PWM is 
 still available for Timer1 which means pwm , analogWrite() is still available
 on the Timer1 associated pins.  We could have hacked into the watchdog timer
 which is used for millis() but that would have been a core change.
 
 The MSP430/Energia Servo library uses Timer0 so this library should be able to 
 run concurrently with Servo.  
 
 It will not run at the same time as the interrupt driven software serial library
 because that uses both timer interrupt vectors
*/
 
#include "Energia.h"
#include "OneMsTaskTimer.h"

volatile int8_t overflowing;
OneMsTaskTimer_t * p_initial_OneMsTaskTimer = 0;

#if defined(__MSP430__)

#define DEFAULT_TIMER 1
uint32_t timer_index_ = DEFAULT_TIMER;

//#if defined(__MSP430_HAS_T1A2__) || defined(__MSP430_HAS_T1A3__) || defined(__MSP430_HAS_T1A5__) || defined(__MSP430_HAS_T1A7__)
	#if DEFAULT_TIMER == 0
	#define TAxCCTL0 TA0CCTL0
	#define TAxCCR0 TA0CCR0
	#define TAxCTL TA0CTL
	#define TIMERx_A0_VECTOR TIMER0_A0_VECTOR
	#endif
	#if DEFAULT_TIMER == 1
	#define TAxCCTL0 TA1CCTL0
	#define TAxCCR0 TA1CCR0
	#define TAxCTL TA1CTL
	#define TIMERx_A0_VECTOR TIMER1_A0_VECTOR
	#endif
	#if DEFAULT_TIMER == 2
	#define TAxCCTL0 TA2CCTL0
	#define TAxCCR0 TA2CCR0
	#define TAxCTL TA2CTL
	#define TIMERx_A0_VECTOR TIMER2_A0_VECTOR
	#endif
	#if DEFAULT_TIMER == 3
	#define TAxCCTL0 TA3CCTL0
	#define TAxCCR0 TA3CCR0
	#define TAxCTL TA3CTL
	#define TIMERx_A0_VECTOR TIMER3_A0_VECTOR
	#endif
	#if DEFAULT_TIMER == 4
	#define TAxCCTL0 TA4CCTL0
	#define TAxCCR0 TA4CCR0
	#define TAxCTL TA4CTL
	#define TIMERx_A0_VECTOR TIMER4_A0_VECTOR
	#endif
	#if DEFAULT_TIMER == 10
	#define TAxCCTL0 TB0CCTL0
	#define TAxCCR0 TB0CCR0
	#define TAxCTL TB0CTL
	#define TIMERx_A0_VECTOR TIMER0_B0_VECTOR
	#endif
//#else
//#error Board not supported
//#endif


// lifted from wiring_analog.c so that the do not step on each other
// there should probably be a processor check here but that also exists in MsTimer.h
#define PWM_DIV ID__8
#define PWM_PERIOD F_CPU/1000/8

#ifndef MC__UP
#define MC__UP MC_1
#endif
#ifndef ID__8
#define ID__8 ID_3
#endif


void OneMsTaskTimer::start(uint32_t timer_index) {
  //// !!!! count = 0;
  overflowing = 0;
  // identical to the wiring_analog.c pwm setup so is compatible
  TAxCCR0 = PWM_PERIOD;           // PWM Period
  TAxCTL = TACLR | TASSEL_2 | MC__UP | PWM_DIV;            // SMCLK, up mode
  TAxCCTL0 |= CCIE;                             // CCR0 interrupt enabled
}

// turn off the interrupts but don't turn of the timer because may
// be in use for pwm.
void OneMsTaskTimer::stop() {
  // disable interrupt
  TAxCCTL0 &= ~CCIE;
  TAxCTL = 0;  
}

// Timer interrupt service routine
__attribute__((interrupt(TIMERx_A0_VECTOR)))
void OneMsTaskTimer_int(void)
{
  OneMsTaskTimer::_ticHandler();
}

#endif //if defined(__MSP430__)


#if defined(__CC3200R1M1RGC__)

#include <driverlib/prcm.h>
#include <driverlib/rom_map.h>
#include <driverlib/pin.h>
#include <driverlib/timer.h>
#include <inc/hw_memmap.h>
#include <inc/hw_gprcm.h>
#include "inc/hw_timer.h"

#define DEFAULT_TIMER 1
uint32_t timer_index_ = DEFAULT_TIMER;


static volatile uint32_t g_ulBase;
void OneMsTaskTimer_int(void);

// lifted from wiring_analog.c so that the do not step on each other
// there should probably be a processor check here but that also exists in MsTimer.h
#define PWM_DIV 0
#define PWM_PERIOD F_CPU/1000

void OneMsTaskTimer::start(uint32_t timer_index) {
  uint32_t load = (F_CPU / 1000);
  //// !!!! count = 0;
  overflowing = 0;
  // Base address for first timer
  g_ulBase = TIMERA0_BASE + (timer_index <<12);
  // Configuring the timers
  MAP_PRCMPeripheralClkEnable(PRCM_TIMERA0 + timer_index, PRCM_RUN_MODE_CLK);
  MAP_PRCMPeripheralReset(PRCM_TIMERA0 + timer_index);
  MAP_TimerConfigure(g_ulBase,TIMER_CFG_PERIODIC);
  MAP_TimerPrescaleSet(g_ulBase,TIMER_A,0);
  // Setup the interrupts for the timer timeouts.
  MAP_TimerIntRegister(g_ulBase, TIMER_A, OneMsTaskTimer_int);
  MAP_TimerIntEnable(g_ulBase, TIMER_TIMA_TIMEOUT);
  // Turn on the timers
  MAP_TimerLoadSet(g_ulBase,TIMER_A, load);
  // Enable the GPT 
  MAP_TimerEnable(g_ulBase,TIMER_A);
}

// turn off the interrupts but don't turn of the timer because may
// be in use for pwm.
void OneMsTaskTimer::stop() {
  // disable interrupt
  MAP_TimerIntDisable(g_ulBase, TIMER_TIMA_TIMEOUT);
  MAP_TimerDisable(g_ulBase, TIMER_A);
}

// Timer interrupt service routine
void OneMsTaskTimer_int(void)
{
  // Clear the timer interrupt.
  MAP_TimerIntClear(g_ulBase, MAP_TimerIntStatus(g_ulBase, true));
  OneMsTaskTimer::_ticHandler();
}

#endif //if defined(__CC3200R1M1RGC__)


#if defined(__TM4C123GH6PM__)

#include "wiring_private.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include <inc/hw_memmap.h>
#include "inc/hw_timer.h"
#include "driverlib/rom.h"

#define DEFAULT_TIMER 0
uint32_t timer_index_ = DEFAULT_TIMER;


static volatile uint32_t g_ulBase;
static volatile uint32_t timerAB;
void OneMsTaskTimer_int(void);

// lifted from wiring_analog.c so that the do not step on each other
// there should probably be a processor check here but that also exists in MsTimer.h
#define PWM_DIV 0
#define PWM_PERIOD F_CPU/1000

void OneMsTaskTimer::start(uint32_t timer_index) {
  uint32_t load = (F_CPU / 1000);
  //// !!!! count = 0;
  overflowing = 0;
  // Base address for first timer
  g_ulBase = getTimerBase(timerToOffset(timer_index));
  timerAB = TIMER_A << timerToAB(timer_index);
  //Setup interrupts for duration, interrupting at 1kHz
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0+ timer_index);
  ROM_IntMasterEnable();
  ROM_TimerConfigure(g_ulBase, TIMER_CFG_PERIODIC);
  ROM_TimerLoadSet(g_ulBase, TIMER_A, F_CPU/1000);
  
  
  // Setup the interrupts for the timer timeouts.
  TimerIntRegister(g_ulBase, TIMER_A, OneMsTaskTimer_int);
  ROM_IntEnable(INT_TIMER0A+timer_index);
  ROM_TimerIntEnable(g_ulBase, TIMER_TIMA_TIMEOUT);
  ROM_TimerEnable(g_ulBase, TIMER_A);
  
}

// turn off the interrupts but don't turn of the timer because may
// be in use for pwm.
void OneMsTaskTimer::stop() {
  // disable interrupt
  ROM_TimerIntDisable(g_ulBase, TIMER_A);
  ROM_TimerIntClear(g_ulBase, TIMER_A);
  ROM_TimerDisable(g_ulBase, timerAB);
}

// Timer interrupt service routine
void OneMsTaskTimer_int(void)
{
  // Clear the timer interrupt.
  ROM_TimerIntClear(g_ulBase, TIMER_A);
  OneMsTaskTimer::_ticHandler();
}
#endif //#if defined(__TM4C123GH6PM__)

#if defined(ti_sysbios_BIOS___VERS)
#include <xdc/runtime/Error.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Types.h>

#define DEFAULT_TIMER 1
uint32_t timer_index_ = DEFAULT_TIMER;
static volatile uint32_t g_ulBase;
Clock_Handle myClock = NULL;
void OneMsTaskTimer_int(UArg arg);

void OneMsTaskTimer::start(uint32_t timer_index) {
    Clock_Params clockParams;
    Error_Block eb;
    Error_init(&eb);

    if (myClock == NULL){
        Clock_Params_init(&clockParams);
        clockParams.period = (uint32_t)1000 / (uint64_t)Clock_tickPeriod;
        clockParams.startFlag = FALSE;
        clockParams.arg = (UArg)0x5555;

		myClock = Clock_create(OneMsTaskTimer_int, clockParams.period, &clockParams, &eb);
	}
    Clock_start(myClock);
}

void OneMsTaskTimer::stop() {
    Clock_stop(myClock);
}
void OneMsTaskTimer_int(UArg arg)
{
  OneMsTaskTimer::_ticHandler();
}

#endif //#if defined(ti_sysbios_BIOS___VERS)
// ---------------------------------------------------------------------
// Common Functions
// ---------------------------------------------------------------------

void OneMsTaskTimer::set_timer_index(uint32_t timer_index) {
	timer_index_ = timer_index;
}

// configure the registers
void OneMsTaskTimer::start() {
  OneMsTaskTimer::start(timer_index_);
}


// add an additional task into the handler
void OneMsTaskTimer::add(OneMsTaskTimer_t * task) {
  OneMsTaskTimer_t * p_task = p_initial_OneMsTaskTimer;
  if (p_task == 0){
	  p_initial_OneMsTaskTimer = task;
  }else{
	while (p_task->nextTask != 0){
	  p_task = p_task->nextTask;
	}
	p_task->nextTask = task;
  }
  p_task = task;
	
  // ensure save initialisation
  if (task->msecs == 0)
  	task->msecs = 1;
  task->count = 0;
  task->nextTask = 0;
}

// removes an task from the handler
void OneMsTaskTimer::remove(OneMsTaskTimer_t * task) {
  OneMsTaskTimer_t * p_task;
  OneMsTaskTimer_t * p_nexttask;
  p_nexttask = (OneMsTaskTimer_t *)p_initial_OneMsTaskTimer;
  p_task = p_nexttask;

  while (p_nexttask != task && p_nexttask != 0){
    p_task = p_nexttask;
    p_nexttask = p_task->nextTask;
  }
  if (p_nexttask != 0){
    if (p_nexttask == p_initial_OneMsTaskTimer){
      if (p_nexttask != 0){
        p_initial_OneMsTaskTimer = p_nexttask->nextTask;
      }else{
        p_initial_OneMsTaskTimer = 0;
      }
    }else{
      p_task->nextTask = p_nexttask->nextTask;
    }
  }
}

// called by the ISR every time we get an interrupt
void OneMsTaskTimer::_ticHandler() {
  OneMsTaskTimer_t * p_task = p_initial_OneMsTaskTimer;

  while (p_task != 0){
    // It is a 1000hz interrupt so each interrupt is 1msec
    p_task->count += 1;
    if (p_task->count >= p_task->msecs && !overflowing) {
      overflowing = 1;
      // subtract ms to catch missed overflows. set to 0 if you don't want this.
      // do this before running supplied function so don't take into account handler time
      p_task->count = p_task->count - p_task->msecs;
      // call the program supplied function
      (*p_task->func)();
      overflowing = 0;
    }
    p_task = (OneMsTaskTimer_t *)p_task->nextTask;
  }
}
