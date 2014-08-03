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
extern void setup1();

extern void foo();

void MCUInit(void)
{

    unsigned long ulRegVal;

    //
    // DIG DCDC NFET SEL and COT mode disable
    //
    HWREG(0x4402F010) = 0x30031820;
    HWREG(0x4402F00C) = 0x04000000;

    UtilsDelay(32000);

    //
    // ANA DCDC clock config
    //
    HWREG(0x4402F11C) = 0x099;
    HWREG(0x4402F11C) = 0x0AA;
    HWREG(0x4402F11C) = 0x1AA;

    //
    // PA DCDC clock config
    //
    HWREG(0x4402F124) = 0x099;
    HWREG(0x4402F124) = 0x0AA;
    HWREG(0x4402F124) = 0x1AA;

    //
    // Enable RTC
    //
    if(MAP_PRCMSysResetCauseGet()== PRCM_POWER_ON)
    {
        HWREG(0x4402F804) = 0x1;
    }

    //
    // TD Flash timing configurations in case of MCU WDT reset
    //

    if((HWREG(0x4402D00C) & 0xFF) == 0x00000005)
    {
        HWREG(0x400F707C) |= 0x01840082;
        HWREG(0x400F70C4)= 0x1;
        HWREG(0x400F70C4)= 0x0;
    }

    //
    // JTAG override for I2C in SWD mode
    //
    if(((HWREG(0x4402F0C8) & 0xFF) == 0x2))
    {
        MAP_PinModeSet(PIN_19,PIN_MODE_2);
        MAP_PinModeSet(PIN_20,PIN_MODE_2);
        HWREG(0x4402E184) |= 0x1;
    }

    //
    // Enable uDMA
    //
    PRCMPeripheralClkEnable(PRCM_UDMA,PRCM_RUN_MODE_CLK);

    //
    // Reset uDMA
    //
    PRCMPeripheralReset(PRCM_UDMA);

    //
    // Disable uDMA
    //
    PRCMPeripheralClkDisable(PRCM_UDMA,PRCM_RUN_MODE_CLK);

}

int main(void)
{
	IntVTableBaseSet((unsigned long)&g_pfnVectors[0]);

	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA0, PRCM_RUN_MODE_CLK);
	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);
	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA2, PRCM_RUN_MODE_CLK);
	MAP_PRCMPeripheralClkEnable(PRCM_GPIOA3, PRCM_RUN_MODE_CLK);

	MAP_IntMasterEnable();
	MCUInit();
	MAP_SysTickIntEnable();
	MAP_SysTickPeriodSet(F_CPU / 1000);
	MAP_SysTickEnable();


	setup();

	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
}
