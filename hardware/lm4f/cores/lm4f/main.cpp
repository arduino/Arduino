#include <Energia.h>
#include "inc/lm4f120h5qr.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/eeprom.h"

int main(void)
{
    ROM_FPULazyStackingEnable();

    timerInit();

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	
	//Initialize EEPROM 
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
    if(EEPROMInit() == EEPROM_INIT_ERROR) {
    	if(EEPROMInit() != EEPROM_INIT_ERROR)
    		EEPROMMassErase();
    }
    
	setup();

    for (;;) {
        loop();
    }

    return 0;
}

