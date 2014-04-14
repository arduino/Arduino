#include <Energia.h>

#include "inc/hw_gpio.h"
#include "driverlib/rom.h"

int main(void)
{
	setup();

	for (;;) {
		loop();
		//if (serialEventRun) serialEventRun();
	}
}
