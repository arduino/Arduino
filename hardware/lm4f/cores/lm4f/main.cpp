#include <Energia.h>
#ifdef TARGET_IS_BLIZZARD_RB1
#include "inc/tm4c123gh6pm.h"
#else
#include "inc/tm4c129xnczad.h"
#endif
#include "inc/hw_gpio.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/eeprom.h"

int main(void)
{

    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
    if(ROM_EEPROMInit() == EEPROM_INIT_ERROR) {
    	if(ROM_EEPROMInit() != EEPROM_INIT_ERROR)
    		EEPROMMassErase();
    }

    timerInit();

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    //Unlock and commit NMI pins PD7 and PF0
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0x4C4F434B;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x1;
    HWREG(GPIO_PORTD_BASE + GPIO_O_LOCK) = 0x4C4F434B;
    HWREG(GPIO_PORTD_BASE + GPIO_O_CR) |= 0x80;

    setup();

    for (;;) {
        loop();
        if (serialEventRun) serialEventRun();
    }

}
