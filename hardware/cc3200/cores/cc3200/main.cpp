#include <Energia.h>
#include "inc/hw_gpio.h"
#include "driverlib/rom_map.h"
#include "driverlib/arcm.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"

extern void (* const g_pfnVectors[])(void);

int main(void)
{
	IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);

	MAP_ArcmPeripheralEnable(ARCM_GPIOS0);
	MAP_ArcmPeripheralEnable(ARCM_GPIOS1);
	MAP_ArcmPeripheralEnable(ARCM_GPIOS2);
	MAP_ArcmPeripheralEnable(ARCM_GPIOS3);

	MAP_IntMasterEnable();

	initSysTick();

	setup();

	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
}
