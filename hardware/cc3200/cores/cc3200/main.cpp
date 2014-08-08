#include <Energia.h>
#include "inc/hw_gpio.h"
#include "driverlib/rom_map.h"
#include "driverlib/prcm.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include <driverlib/utils.h>
#include "inc/hw_hib1p2.h"
#include "inc/hw_hib3p3.h"

extern void (* const g_pfnVectors[])(void);

int main(void)
{
	IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);

	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA0, PRCM_RUN_MODE_CLK);
	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);
	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA2, PRCM_RUN_MODE_CLK);
	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA3, PRCM_RUN_MODE_CLK);

	MAP_IntMasterEnable();
	PRCMCC3200MCUInit();
	MAP_SysTickIntEnable();
	MAP_SysTickPeriodSet(F_CPU / 1000);
	MAP_SysTickEnable();

	setup();

	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
}
