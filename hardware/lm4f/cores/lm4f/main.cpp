#include <Energia.h>
#include "inc/lm4f120h5qr.h"
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/eeprom.h"

int main(void)
{

    timerInit();

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
    if(EEPROMInit() == EEPROM_INIT_ERROR) {
    	if(EEPROMInit() != EEPROM_INIT_ERROR)
    		EEPROMMassErase();
    }

    //Unlock and commit NMI pins PD7 and PF0
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0x4C4F434B;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x1;
    HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0x4C4F434B;
    HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x8;

    setup();

    for (;;) {
        loop();
    }

}
