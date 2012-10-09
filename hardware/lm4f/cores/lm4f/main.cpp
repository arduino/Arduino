#include <Energia.h>
#include "inc/lm4f120h5qr.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
int main(void)
{

    timerInit();
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	
    setup();

    for (;;) {
        loop();
    }

    return 0;
}

