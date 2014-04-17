#include "Energia.h"
#include "inc/hw_ints.h"
#include "inc/hw_timer.h"
#include "driverlib/rom_map.h"
#include "driverlib/systick.h"
#include "driverlib/timer.h"

void initSysTick()
{
	/* SysTick is used for delay() and delayMicroseconds() */
	MAP_SysTickIntEnable();
	MAP_SysTickPeriodSet(F_CPU / 1000);
	MAP_SysTickEnable();
//	MAP_IntPrioritySet(FAULT_SYSTICK, SYSTICK_INT_PRIORITY);
}
