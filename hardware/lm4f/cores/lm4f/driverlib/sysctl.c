//*****************************************************************************
//
// sysctl.c - Driver for the system controller.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup sysctl_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/cpu.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"

//*****************************************************************************
//
// A macro used to determine whether the target part uses the new SysCtl
// register layout.
//
//*****************************************************************************

//*****************************************************************************
//
// This macro extracts the array index out of the peripheral number.
//
//*****************************************************************************
#define SYSCTL_PERIPH_INDEX(a)  (((a) >> 28) & 0xf)

//*****************************************************************************
//
// This macro constructs the peripheral bit mask from the peripheral number.
//
//*****************************************************************************
#define SYSCTL_PERIPH_MASK(a)   (((a) & 0xffff) << (((a) & 0x001f0000) >> 16))

//*****************************************************************************
//
// An array that maps the "peripheral set" number (which is stored in the upper
// nibble of the SYSCTL_PERIPH_* defines) to the SYSCTL DC? register that
// contains the peripheral present bit for that peripheral.
//
//*****************************************************************************
static const unsigned long g_pulDCRegs[] =
{
    SYSCTL_DC1,
    SYSCTL_DC2,
    SYSCTL_DC4,
    SYSCTL_DC1
};

//*****************************************************************************
//
// An array that maps the "peripheral set" number (which is stored in the upper
// nibble of the SYSCTL_PERIPH_* defines) to the SYSCTL_SRCR? register that
// controls the software reset for that peripheral.
//
//*****************************************************************************
static const unsigned long g_pulSRCRRegs[] =
{
    SYSCTL_SRCR0,
    SYSCTL_SRCR1,
    SYSCTL_SRCR2
};

//*****************************************************************************
//
// An array that maps the "peripheral set" number (which is stored in the upper
// nibble of the SYSCTL_PERIPH_* defines) to the SYSCTL_RCGC? register that
// controls the run-mode enable for that peripheral.
//
//*****************************************************************************
static const unsigned long g_pulRCGCRegs[] =
{
    SYSCTL_RCGC0,
    SYSCTL_RCGC1,
    SYSCTL_RCGC2
};

//*****************************************************************************
//
// An array that maps the "peripheral set" number (which is stored in the upper
// nibble of the SYSCTL_PERIPH_* defines) to the SYSCTL_SCGC? register that
// controls the sleep-mode enable for that peripheral.
//
//*****************************************************************************
static const unsigned long g_pulSCGCRegs[] =
{
    SYSCTL_SCGC0,
    SYSCTL_SCGC1,
    SYSCTL_SCGC2
};

//*****************************************************************************
//
// An array that maps the "peripheral set" number (which is stored in the upper
// nibble of the SYSCTL_PERIPH_* defines) to the SYSCTL_DCGC? register that
// controls the deep-sleep-mode enable for that peripheral.
//
//*****************************************************************************
static const unsigned long g_pulDCGCRegs[] =
{
    SYSCTL_DCGC0,
    SYSCTL_DCGC1,
    SYSCTL_DCGC2
};

//*****************************************************************************
//
// An array that maps the crystal number in RCC to a frequency.
//
//*****************************************************************************
static const unsigned long g_pulXtals[] =
{
    1000000,
    1843200,
    2000000,
    2457600,
    3579545,
    3686400,
    4000000,
    4096000,
    4915200,
    5000000,
    5120000,
    6000000,
    6144000,
    7372800,
    8000000,
    8192000,
    10000000,
    12000000,
    12288000,
    13560000,
    14318180,
    16000000,
    16384000,
    18000000,
    20000000,
    24000000,
    25000000
};

//*****************************************************************************
//
// The base addresses of the various peripheral control registers.
//
//*****************************************************************************
#define SYSCTL_PPBASE           0x400fe300
#define SYSCTL_SRBASE           0x400fe500
#define SYSCTL_RCGCBASE         0x400fe600
#define SYSCTL_SCGCBASE         0x400fe700
#define SYSCTL_DCGCBASE         0x400fe800
#define SYSCTL_PCBASE           0x400fe900
#define SYSCTL_PRBASE           0x400fea00

//*****************************************************************************
//
//! \internal
//! Checks a peripheral identifier.
//!
//! \param ulPeripheral is the peripheral identifier.
//!
//! This function determines if a peripheral identifier is valid.
//!
//! \return Returns \b true if the peripheral identifier is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static tBoolean
SysCtlPeripheralValid(unsigned long ulPeripheral)
{
    return((ulPeripheral == SYSCTL_PERIPH_ADC0) ||
           (ulPeripheral == SYSCTL_PERIPH_ADC1) ||
           (ulPeripheral == SYSCTL_PERIPH_CAN0) ||
           (ulPeripheral == SYSCTL_PERIPH_CAN1) ||
           (ulPeripheral == SYSCTL_PERIPH_CAN2) ||
           (ulPeripheral == SYSCTL_PERIPH_COMP0) ||
           (ulPeripheral == SYSCTL_PERIPH_COMP1) ||
           (ulPeripheral == SYSCTL_PERIPH_COMP2) ||
           (ulPeripheral == SYSCTL_PERIPH_EEPROM0) ||
           (ulPeripheral == SYSCTL_PERIPH_EPI0) ||
           (ulPeripheral == SYSCTL_PERIPH_ETH) ||
           (ulPeripheral == SYSCTL_PERIPH_FAN0) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOA) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOB) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOC) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOD) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOE) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOF) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOG) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOH) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOJ) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOK) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOL) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOM) ||
           (ulPeripheral == SYSCTL_PERIPH_GPION) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOP) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOQ) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOR) ||
           (ulPeripheral == SYSCTL_PERIPH_GPIOS) ||
           (ulPeripheral == SYSCTL_PERIPH_HIBERNATE) ||
           (ulPeripheral == SYSCTL_PERIPH_I2C0) ||
           (ulPeripheral == SYSCTL_PERIPH_I2C1) ||
           (ulPeripheral == SYSCTL_PERIPH_I2C2) ||
           (ulPeripheral == SYSCTL_PERIPH_I2C3) ||
           (ulPeripheral == SYSCTL_PERIPH_I2C4) ||
           (ulPeripheral == SYSCTL_PERIPH_I2C5) ||
           (ulPeripheral == SYSCTL_PERIPH_I2S0) ||
           (ulPeripheral == SYSCTL_PERIPH_IEEE1588) ||
           (ulPeripheral == SYSCTL_PERIPH_LPC0) ||
           (ulPeripheral == SYSCTL_PERIPH_MPU) ||
           (ulPeripheral == SYSCTL_PERIPH_PECI0) ||
           (ulPeripheral == SYSCTL_PERIPH_PLL) ||
           (ulPeripheral == SYSCTL_PERIPH_PWM0) ||
           (ulPeripheral == SYSCTL_PERIPH_PWM1) ||
           (ulPeripheral == SYSCTL_PERIPH_QEI0) ||
           (ulPeripheral == SYSCTL_PERIPH_QEI1) ||
           (ulPeripheral == SYSCTL_PERIPH_SSI0) ||
           (ulPeripheral == SYSCTL_PERIPH_SSI1) ||
           (ulPeripheral == SYSCTL_PERIPH_SSI2) ||
           (ulPeripheral == SYSCTL_PERIPH_SSI3) ||
           (ulPeripheral == SYSCTL_PERIPH_TEMP) ||
           (ulPeripheral == SYSCTL_PERIPH_TIMER0) ||
           (ulPeripheral == SYSCTL_PERIPH_TIMER1) ||
           (ulPeripheral == SYSCTL_PERIPH_TIMER2) ||
           (ulPeripheral == SYSCTL_PERIPH_TIMER3) ||
           (ulPeripheral == SYSCTL_PERIPH_TIMER4) ||
           (ulPeripheral == SYSCTL_PERIPH_TIMER5) ||
           (ulPeripheral == SYSCTL_PERIPH_UART0) ||
           (ulPeripheral == SYSCTL_PERIPH_UART1) ||
           (ulPeripheral == SYSCTL_PERIPH_UART2) ||
           (ulPeripheral == SYSCTL_PERIPH_UART3) ||
           (ulPeripheral == SYSCTL_PERIPH_UART4) ||
           (ulPeripheral == SYSCTL_PERIPH_UART5) ||
           (ulPeripheral == SYSCTL_PERIPH_UART6) ||
           (ulPeripheral == SYSCTL_PERIPH_UART7) ||
           (ulPeripheral == SYSCTL_PERIPH_UDMA) ||
           (ulPeripheral == SYSCTL_PERIPH_USB0) ||
           (ulPeripheral == SYSCTL_PERIPH_WDOG0) ||
           (ulPeripheral == SYSCTL_PERIPH_WDOG1) ||
           (ulPeripheral == SYSCTL_PERIPH_WTIMER0) ||
           (ulPeripheral == SYSCTL_PERIPH_WTIMER1) ||
           (ulPeripheral == SYSCTL_PERIPH_WTIMER2) ||
           (ulPeripheral == SYSCTL_PERIPH_WTIMER3) ||
           (ulPeripheral == SYSCTL_PERIPH_WTIMER4) ||
           (ulPeripheral == SYSCTL_PERIPH_WTIMER5));
}
#endif

//*****************************************************************************
//
// A map of old peripheral defines to new peripheral defines.  Note that the
// new peripheral defines do not work on parts that precede Blizzard class.
//
//*****************************************************************************
static const unsigned long g_ppulPeripheralMap[][2] =
{
    { SYSCTL_PERIPH_ADC0, SYSCTL_PERIPH2_ADC0 },
    { SYSCTL_PERIPH_ADC1, SYSCTL_PERIPH2_ADC1 },
    { SYSCTL_PERIPH_CAN0, SYSCTL_PERIPH2_CAN0 },
    { SYSCTL_PERIPH_CAN1, SYSCTL_PERIPH2_CAN1 },
    { SYSCTL_PERIPH_CAN2, SYSCTL_PERIPH2_CAN2 },
    { SYSCTL_PERIPH_COMP0, SYSCTL_PERIPH2_COMP0 },
    { SYSCTL_PERIPH_COMP1, SYSCTL_PERIPH2_COMP0 },
    { SYSCTL_PERIPH_COMP2, SYSCTL_PERIPH2_COMP0 },
    { SYSCTL_PERIPH_GPIOA, SYSCTL_PERIPH2_GPIOA },
    { SYSCTL_PERIPH_GPIOB, SYSCTL_PERIPH2_GPIOB },
    { SYSCTL_PERIPH_GPIOC, SYSCTL_PERIPH2_GPIOC },
    { SYSCTL_PERIPH_GPIOD, SYSCTL_PERIPH2_GPIOD },
    { SYSCTL_PERIPH_GPIOE, SYSCTL_PERIPH2_GPIOE },
    { SYSCTL_PERIPH_GPIOF, SYSCTL_PERIPH2_GPIOF },
    { SYSCTL_PERIPH_GPIOG, SYSCTL_PERIPH2_GPIOG },
    { SYSCTL_PERIPH_GPIOH, SYSCTL_PERIPH2_GPIOH },
    { SYSCTL_PERIPH_GPIOJ, SYSCTL_PERIPH2_GPIOJ },
    { SYSCTL_PERIPH_HIBERNATE, SYSCTL_PERIPH2_HIBERNATE },
    { SYSCTL_PERIPH_I2C0, SYSCTL_PERIPH2_I2C0 },
    { SYSCTL_PERIPH_I2C1, SYSCTL_PERIPH2_I2C1 },
    { SYSCTL_PERIPH_PWM0, SYSCTL_PERIPH2_PWM0 },
    { SYSCTL_PERIPH_QEI0, SYSCTL_PERIPH2_QEI0 },
    { SYSCTL_PERIPH_QEI1, SYSCTL_PERIPH2_QEI1 },
    { SYSCTL_PERIPH_SSI0, SYSCTL_PERIPH2_SSI0 },
    { SYSCTL_PERIPH_SSI1, SYSCTL_PERIPH2_SSI1 },
    { SYSCTL_PERIPH_TIMER0, SYSCTL_PERIPH2_TIMER0 },
    { SYSCTL_PERIPH_TIMER1, SYSCTL_PERIPH2_TIMER1 },
    { SYSCTL_PERIPH_TIMER2, SYSCTL_PERIPH2_TIMER2 },
    { SYSCTL_PERIPH_TIMER3, SYSCTL_PERIPH2_TIMER3 },
    { SYSCTL_PERIPH_UART0, SYSCTL_PERIPH2_UART0 },
    { SYSCTL_PERIPH_UART1, SYSCTL_PERIPH2_UART1 },
    { SYSCTL_PERIPH_UART2, SYSCTL_PERIPH2_UART2 },
    { SYSCTL_PERIPH_UDMA, SYSCTL_PERIPH2_UDMA },
    { SYSCTL_PERIPH_USB0, SYSCTL_PERIPH2_USB0 },
    { SYSCTL_PERIPH_WDOG0, SYSCTL_PERIPH2_WDOG0 },
    { SYSCTL_PERIPH_WDOG1, SYSCTL_PERIPH2_WDOG1 },
};

//*****************************************************************************
//
// Maps a SYSCTL_PERIPH_foo identifier into its new-style SYSCTL_PERIPH2_foo
// identifier.
//
//*****************************************************************************
static unsigned long
SysCtlPeripheralMapToNew(unsigned long ulPeripheral)
{
    unsigned long ulIndex;

    //
    // Loop through the table of old-style identifiers.
    //
    for(ulIndex = 0; ulIndex < (sizeof(g_ppulPeripheralMap) /
                                sizeof(g_ppulPeripheralMap[0])); ulIndex++)
    {
        //
        // See if this peripheral matches the old-style identifier.
        //
        if(g_ppulPeripheralMap[ulIndex][0] == ulPeripheral)
        {
            //
            // Return the new-style identifier that corresponds to this
            // peripheral.
            //
            return(g_ppulPeripheralMap[ulIndex][1]);
        }
    }

    //
    // No old-style identifier was found, so return the identifier unchanged
    // (on the assumption that it is already a new-style identifier).
    //
    return(ulPeripheral);
}

//*****************************************************************************
//
//! Gets the size of the SRAM.
//!
//! This function determines the size of the SRAM on the Stellaris device.
//!
//! \return The total number of bytes of SRAM.
//
//*****************************************************************************
unsigned long
SysCtlSRAMSizeGet(void)
{
    //
    // Compute the size of the SRAM.
    //
    return(((HWREG(SYSCTL_DC0) & SYSCTL_DC0_SRAMSZ_M) >> 8) + 0x100);
}

//*****************************************************************************
//
//! Gets the size of the flash.
//!
//! This function determines the size of the flash on the Stellaris device.
//!
//! \return The total number of bytes of flash.
//
//*****************************************************************************
unsigned long
SysCtlFlashSizeGet(void)
{
    //
    // Compute the size of the flash.
    //
    return(((HWREG(SYSCTL_DC0) & SYSCTL_DC0_FLASHSZ_M) << 11) + 0x800);
}

//*****************************************************************************
//
//! Determines if a pin is present.
//!
//! \param ulPin is the pin in question.
//!
//! This function determines if a particular pin is present in the device.  The
//! PWM, analog comparators, ADC, and timers have a varying number of pins
//! across members of the Stellaris family; this function determines which pins
//! are present on this device.
//!
//! The \e ulPin argument must be only one of the following values:
//! \b SYSCTL_PIN_PWM0, \b SYSCTL_PIN_PWM1, \b SYSCTL_PIN_PWM2,
//! \b SYSCTL_PIN_PWM3, \b SYSCTL_PIN_PWM4, \b SYSCTL_PIN_PWM5,
//! \b SYSCTL_PIN_C0MINUS, \b SYSCTL_PIN_C0PLUS, \b SYSCTL_PIN_C0O,
//! \b SYSCTL_PIN_C1MINUS, \b SYSCTL_PIN_C1PLUS, \b SYSCTL_PIN_C1O,
//! \b SYSCTL_PIN_C2MINUS, \b SYSCTL_PIN_C2PLUS, \b SYSCTL_PIN_C2O,
//! \b SYSCTL_PIN_ADC0, \b SYSCTL_PIN_ADC1, \b SYSCTL_PIN_ADC2,
//! \b SYSCTL_PIN_ADC3, \b SYSCTL_PIN_ADC4, \b SYSCTL_PIN_ADC5,
//! \b SYSCTL_PIN_ADC6, \b SYSCTL_PIN_ADC7, \b SYSCTL_PIN_CCP0,
//! \b SYSCTL_PIN_CCP1, \b SYSCTL_PIN_CCP2, \b SYSCTL_PIN_CCP3,
//! \b SYSCTL_PIN_CCP4, \b SYSCTL_PIN_CCP5, \b SYSCTL_PIN_CCP6,
//! \b SYSCTL_PIN_CCP7, \b SYSCTL_PIN_32KHZ, or \b SYSCTL_PIN_MC_FAULT0.
//!
//! \return Returns \b true if the specified pin is present and \b false if it
//! is not.
//
//*****************************************************************************
tBoolean
SysCtlPinPresent(unsigned long ulPin)
{
    //
    // Check the arguments.
    //
    ASSERT((ulPin == SYSCTL_PIN_PWM0) ||
           (ulPin == SYSCTL_PIN_PWM1) ||
           (ulPin == SYSCTL_PIN_PWM2) ||
           (ulPin == SYSCTL_PIN_PWM3) ||
           (ulPin == SYSCTL_PIN_PWM4) ||
           (ulPin == SYSCTL_PIN_PWM5) ||
           (ulPin == SYSCTL_PIN_C0MINUS) ||
           (ulPin == SYSCTL_PIN_C0PLUS) ||
           (ulPin == SYSCTL_PIN_C0O) ||
           (ulPin == SYSCTL_PIN_C1MINUS) ||
           (ulPin == SYSCTL_PIN_C1PLUS) ||
           (ulPin == SYSCTL_PIN_C1O) ||
           (ulPin == SYSCTL_PIN_C2MINUS) ||
           (ulPin == SYSCTL_PIN_C2PLUS) ||
           (ulPin == SYSCTL_PIN_C2O) ||
           (ulPin == SYSCTL_PIN_MC_FAULT0) ||
           (ulPin == SYSCTL_PIN_ADC0) ||
           (ulPin == SYSCTL_PIN_ADC1) ||
           (ulPin == SYSCTL_PIN_ADC2) ||
           (ulPin == SYSCTL_PIN_ADC3) ||
           (ulPin == SYSCTL_PIN_ADC4) ||
           (ulPin == SYSCTL_PIN_ADC5) ||
           (ulPin == SYSCTL_PIN_ADC6) ||
           (ulPin == SYSCTL_PIN_ADC7) ||
           (ulPin == SYSCTL_PIN_CCP0) ||
           (ulPin == SYSCTL_PIN_CCP1) ||
           (ulPin == SYSCTL_PIN_CCP2) ||
           (ulPin == SYSCTL_PIN_CCP3) ||
           (ulPin == SYSCTL_PIN_CCP4) ||
           (ulPin == SYSCTL_PIN_CCP5) ||
           (ulPin == SYSCTL_PIN_32KHZ));

    //
    // Determine if this pin is present.
    //
    if(HWREG(SYSCTL_DC3) & ulPin)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

//*****************************************************************************
//
//! Determines if a peripheral is present.
//!
//! \param ulPeripheral is the peripheral in question.
//!
//! This function determines if a particular peripheral is present in the
//! device.  Each member of the Stellaris family has a different peripheral
//! set; this function determines which peripherals are present on this device.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EPI0,
//! \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0, \b SYSCTL_PERIPH_GPIOA,
//! \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC, \b SYSCTL_PERIPH_GPIOD,
//! \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF, \b SYSCTL_PERIPH_GPIOG,
//! \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ, \b SYSCTL_PERIPH_GPIOK,
//! \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM, \b SYSCTL_PERIPH_GPION,
//! \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ, \b SYSCTL_PERIPH_HIBERNATE,
//! \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1, \b SYSCTL_PERIPH_I2C2,
//! \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4, \b SYSCTL_PERIPH_I2C5,
//! \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_IEEE1588, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_MPU, \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PLL,
//! \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1, \b SYSCTL_PERIPH_QEI0,
//! \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0, \b SYSCTL_PERIPH_SSI1,
//! \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3, \b SYSCTL_PERIPH_TEMP,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5,
//!
//! \return Returns \b true if the specified peripheral is present and \b false
//! if it is not.
//
//*****************************************************************************
tBoolean
SysCtlPeripheralPresent(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_PPperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // See if this peripheral is present.
        //
        return(HWREGBITW(SYSCTL_PPBASE + ((ulPeripheral & 0xff00) >> 8),
                         ulPeripheral & 0xff));
    }
    else if(ulPeripheral == SYSCTL_PERIPH_USB0)
    {
        //
        // USB is a special case because the DC bit is missing for USB0.
        //
        if(HWREG(SYSCTL_DC6) & SYSCTL_DC6_USB0_M)
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }
    else if(HWREG(g_pulDCRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) &
            SYSCTL_PERIPH_MASK(ulPeripheral))
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

//*****************************************************************************
//
//! Determines if a peripheral is ready.
//!
//! \param ulPeripheral is the peripheral in question.
//!
//! This function determines if a particular peripheral is ready to be
//! accessed.  The peripheral may be in a non-ready state if it is not enabled,
//! is being held in reset, or is in the process of becoming ready after being
//! enabled or taken out of reset.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \note The ability to check for a peripheral being ready varies based on the
//! Stellaris part in use.  Please consult the data sheet for the part you are
//! using to determine if this feature is available.
//!
//! \return Returns \b true if the specified peripheral is ready and \b false
//! if it is not.
//
//*****************************************************************************
tBoolean
SysCtlPeripheralReady(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // Map the peripheral identifier to the new style identifiers.  If it is
    // already a new style identifier, this is a NOP.
    //
    ulPeripheral = SysCtlPeripheralMapToNew(ulPeripheral);

    //
    // See if this peripheral is ready.
    //
    return(HWREGBITW(SYSCTL_PRBASE + ((ulPeripheral & 0xff00) >> 8),
                     ulPeripheral & 0xff));
}

//*****************************************************************************
//
//! Powers on a peripheral.
//!
//! \param ulPeripheral is the peripheral to be powered on.
//!
//! This function turns on the power to a peripheral.  The peripheral continues
//! to receive power even when its clock is not enabled.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \note The ability to power off a peripheral varies based on the Stellaris
//! part in use.  Please consult the data sheet for the part you are using to
//! determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralPowerOn(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // Map the peripheral identifier to the new style identifiers.  If it is
    // already a new style identifier, this is a NOP.
    //
    ulPeripheral = SysCtlPeripheralMapToNew(ulPeripheral);

    //
    // Power on this peripheral.
    //
    HWREGBITW(SYSCTL_PCBASE + ((ulPeripheral & 0xff00) >> 8),
              ulPeripheral & 0xff) = 1;
}

//*****************************************************************************
//
//! Powers off a peripheral.
//!
//! \param ulPeripheral is the peripheral to be powered off.
//!
//! This function allows the power to a peripheral to be turned off.  The
//! peripheral continues to receive power when its clock is enabled, but
//! the power is removed when its clock is disabled.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \note The ability to power off a peripheral varies based on the Stellaris
//! part in use.  Please consult the data sheet for the part you are using to
//! determine if this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralPowerOff(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // Map the peripheral identifier to the new style identifiers.  If it is
    // already a new style identifier, this is a NOP.
    //
    ulPeripheral = SysCtlPeripheralMapToNew(ulPeripheral);

    //
    // Power off this peripheral.
    //
    HWREGBITW(SYSCTL_PCBASE + ((ulPeripheral & 0xff00) >> 8),
              ulPeripheral & 0xff) = 0;
}

//*****************************************************************************
//
//! Performs a software reset of a peripheral.
//!
//! \param ulPeripheral is the peripheral to reset.
//!
//! This function performs a software reset of the specified peripheral.  An
//! individual peripheral reset signal is asserted for a brief period and then
//! de-asserted, returning the internal state of the peripheral to its reset
//! condition.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralReset(unsigned long ulPeripheral)
{
    volatile unsigned long ulDelay;

    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_SRperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // Put the peripheral into the reset state.
        //
        HWREGBITW(SYSCTL_SRBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 1;

        //
        // Delay for a little bit.
        //
        for(ulDelay = 0; ulDelay < 16; ulDelay++)
        {
        }

        //
        // Take the peripheral out of the reset state.
        //
        HWREGBITW(SYSCTL_SRBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 0;
    }
    else
    {
        //
        // Put the peripheral into the reset state.
        //
        HWREG(g_pulSRCRRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) |=
            SYSCTL_PERIPH_MASK(ulPeripheral);

        //
        // Delay for a little bit.
        //
        for(ulDelay = 0; ulDelay < 16; ulDelay++)
        {
        }

        //
        // Take the peripheral out of the reset state.
        //
        HWREG(g_pulSRCRRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) &=
            ~SYSCTL_PERIPH_MASK(ulPeripheral);
    }
}

//*****************************************************************************
//
//! Enables a peripheral.
//!
//! \param ulPeripheral is the peripheral to enable.
//!
//! This function enables peripherals.  At power-up, all peripherals
//! are disabled; they must be enabled in order to operate or respond to
//! register reads/writes.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \note It takes five clock cycles after the write to enable a peripheral
//! before the the peripheral is actually enabled.  During this time, attempts
//! to access the peripheral result in a bus fault.  Care should be taken
//! to ensure that the peripheral is not accessed during this brief time
//! period.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralEnable(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_RCGCperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // Enable this peripheral.
        //
        HWREGBITW(SYSCTL_RCGCBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 1;
    }
    else
    {
        //
        // Enable this peripheral.
        //
        HWREG(g_pulRCGCRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) |=
            SYSCTL_PERIPH_MASK(ulPeripheral);
    }
}

//*****************************************************************************
//
//! Disables a peripheral.
//!
//! \param ulPeripheral is the peripheral to disable.
//!
//! This function disables peripherals are disabled with this function.  Once
//! disabled, they do not operate or respond to register reads/writes.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralDisable(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_RCGCperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // Disable this peripheral.
        //
        HWREGBITW(SYSCTL_RCGCBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 0;
    }
    else
    {
        //
        // Disable this peripheral.
        //
        HWREG(g_pulRCGCRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) &=
            ~SYSCTL_PERIPH_MASK(ulPeripheral);
    }
}

//*****************************************************************************
//
//! Enables a peripheral in sleep mode.
//!
//! \param ulPeripheral is the peripheral to enable in sleep mode.
//!
//! This function allows a peripheral to continue operating when the processor
//! goes into sleep mode.  Because the clocking configuration of the device
//! does not change, any peripheral can safely continue operating while the
//! processor is in sleep mode and can therefore wake the processor from sleep
//! mode.
//!
//! Sleep mode clocking of peripherals must be enabled via
//! SysCtlPeripheralClockGating(); if disabled, the peripheral sleep mode
//! configuration is maintained but has no effect when sleep mode is entered.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralSleepEnable(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_SCGCperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // Enable this peripheral in sleep mode.
        //
        HWREGBITW(SYSCTL_SCGCBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 1;
    }
    else
    {
        //
        // Enable this peripheral in sleep mode.
        //
        HWREG(g_pulSCGCRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) |=
            SYSCTL_PERIPH_MASK(ulPeripheral);
    }
}

//*****************************************************************************
//
//! Disables a peripheral in sleep mode.
//!
//! \param ulPeripheral is the peripheral to disable in sleep mode.
//!
//! This function causes a peripheral to stop operating when the processor goes
//! into sleep mode.  Disabling peripherals while in sleep mode helps to lower
//! the current draw of the device.  If enabled (via SysCtlPeripheralEnable()),
//! the peripheral automatically resumes operation when the processor
//! leaves sleep mode, maintaining its entire state from before sleep mode was
//! entered.
//!
//! Sleep mode clocking of peripherals must be enabled via
//! SysCtlPeripheralClockGating(); if disabled, the peripheral sleep mode
//! configuration is maintained but has no effect when sleep mode is entered.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralSleepDisable(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_SCGCperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // Disable this peripheral in sleep mode.
        //
        HWREGBITW(SYSCTL_SCGCBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 0;
    }
    else
    {
        //
        // Disable this peripheral in sleep mode.
        //
        HWREG(g_pulSCGCRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) &=
            ~SYSCTL_PERIPH_MASK(ulPeripheral);
    }
}

//*****************************************************************************
//
//! Enables a peripheral in deep-sleep mode.
//!
//! \param ulPeripheral is the peripheral to enable in deep-sleep mode.
//!
//! This function allows a peripheral to continue operating when the processor
//! goes into deep-sleep mode.  Because the clocking configuration of the
//! device may change, not all peripherals can safely continue operating while
//! the processor is in sleep mode.  Those that must run at a particular
//! frequency (such as a UART) do not work as expected if the clock changes.
//! It is the responsibility of the caller to make sensible choices.
//!
//! Deep-sleep mode clocking of peripherals must be enabled via
//! SysCtlPeripheralClockGating(); if disabled, the peripheral deep-sleep mode
//! configuration is maintained but has no effect when deep-sleep mode is
//! entered.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralDeepSleepEnable(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_DCGCperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // Enable this peripheral in deep-sleep mode.
        //
        HWREGBITW(SYSCTL_DCGCBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 1;
    }
    else
    {
        //
        // Enable this peripheral in deep-sleep mode.
        //
        HWREG(g_pulDCGCRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) |=
            SYSCTL_PERIPH_MASK(ulPeripheral);
    }
}

//*****************************************************************************
//
//! Disables a peripheral in deep-sleep mode.
//!
//! \param ulPeripheral is the peripheral to disable in deep-sleep mode.
//!
//! This function causes a peripheral to stop operating when the processor goes
//! into deep-sleep mode.  Disabling peripherals while in deep-sleep mode helps
//! to lower the current draw of the device, and can keep peripherals that
//! require a particular clock frequency from operating when the clock changes
//! as a result of entering deep-sleep mode.  If enabled (via
//! SysCtlPeripheralEnable()), the peripheral automatically resumes
//! operation when the processor leaves deep-sleep mode, maintaining its entire
//! state from before deep-sleep mode was entered.
//!
//! Deep-sleep mode clocking of peripherals must be enabled via
//! SysCtlPeripheralClockGating(); if disabled, the peripheral deep-sleep mode
//! configuration is maintained but has no effect when deep-sleep mode is
//! entered.
//!
//! The \e ulPeripheral parameter must be only one of the following values:
//! \b SYSCTL_PERIPH_ADC0, \b SYSCTL_PERIPH_ADC1, \b SYSCTL_PERIPH_CAN0,
//! \b SYSCTL_PERIPH_CAN1, \b SYSCTL_PERIPH_CAN2, \b SYSCTL_PERIPH_COMP0,
//! \b SYSCTL_PERIPH_COMP1, \b SYSCTL_PERIPH_COMP2, \b SYSCTL_PERIPH_EEPROM0,
//! \b SYSCTL_PERIPH_EPI0, \b SYSCTL_PERIPH_ETH, \b SYSCTL_PERIPH_FAN0,
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, \b SYSCTL_PERIPH_GPIOJ,
//! \b SYSCTL_PERIPH_GPIOK, \b SYSCTL_PERIPH_GPIOL, \b SYSCTL_PERIPH_GPIOM,
//! \b SYSCTL_PERIPH_GPION, \b SYSCTL_PERIPH_GPIOP, \b SYSCTL_PERIPH_GPIOQ,
//! \b SYSCTL_PERIPH_HIBERNATE, \b SYSCTL_PERIPH_I2C0, \b SYSCTL_PERIPH_I2C1,
//! \b SYSCTL_PERIPH_I2C2, \b SYSCTL_PERIPH_I2C3, \b SYSCTL_PERIPH_I2C4,
//! \b SYSCTL_PERIPH_I2C5, \b SYSCTL_PERIPH_I2S0, \b SYSCTL_PERIPH_LPC0,
//! \b SYSCTL_PERIPH_PECI0, \b SYSCTL_PERIPH_PWM0, \b SYSCTL_PERIPH_PWM1,
//! \b SYSCTL_PERIPH_QEI0, \b SYSCTL_PERIPH_QEI1, \b SYSCTL_PERIPH_SSI0,
//! \b SYSCTL_PERIPH_SSI1, \b SYSCTL_PERIPH_SSI2, \b SYSCTL_PERIPH_SSI3,
//! \b SYSCTL_PERIPH_TIMER0, \b SYSCTL_PERIPH_TIMER1, \b SYSCTL_PERIPH_TIMER2,
//! \b SYSCTL_PERIPH_TIMER3, \b SYSCTL_PERIPH_TIMER4, \b SYSCTL_PERIPH_TIMER5,
//! \b SYSCTL_PERIPH_UART0, \b SYSCTL_PERIPH_UART1, \b SYSCTL_PERIPH_UART2,
//! \b SYSCTL_PERIPH_UART3, \b SYSCTL_PERIPH_UART4, \b SYSCTL_PERIPH_UART5,
//! \b SYSCTL_PERIPH_UART6, \b SYSCTL_PERIPH_UART7, \b SYSCTL_PERIPH_UDMA,
//! \b SYSCTL_PERIPH_USB0, \b SYSCTL_PERIPH_WDOG0, \b SYSCTL_PERIPH_WDOG1,
//! \b SYSCTL_PERIPH_WTIMER0, \b SYSCTL_PERIPH_WTIMER1,
//! \b SYSCTL_PERIPH_WTIMER2, \b SYSCTL_PERIPH_WTIMER3,
//! \b SYSCTL_PERIPH_WTIMER4, or \b SYSCTL_PERIPH_WTIMER5.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralDeepSleepDisable(unsigned long ulPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(SysCtlPeripheralValid(ulPeripheral));

    //
    // See if the peripheral index is 15, indicating a peripheral that is
    // accessed via the SYSCTL_DCGCperiph registers.
    //
    if((ulPeripheral & 0xf0000000) == 0xf0000000)
    {
        //
        // Disable this peripheral in deep-sleep mode.
        //
        HWREGBITW(SYSCTL_DCGCBASE + ((ulPeripheral & 0xff00) >> 8),
                  ulPeripheral & 0xff) = 0;
    }
    else
    {
        //
        // Disable this peripheral in deep-sleep mode.
        //
        HWREG(g_pulDCGCRegs[SYSCTL_PERIPH_INDEX(ulPeripheral)]) &=
            ~SYSCTL_PERIPH_MASK(ulPeripheral);
    }
}

//*****************************************************************************
//
//! Controls peripheral clock gating in sleep and deep-sleep mode.
//!
//! \param bEnable is a boolean that is \b true if the sleep and deep-sleep
//! peripheral configuration should be used and \b false if not.
//!
//! This function controls how peripherals are clocked when the processor goes
//! into sleep or deep-sleep mode.  By default, the peripherals are clocked the
//! same as in run mode; if peripheral clock gating is enabled, they are
//! clocked according to the configuration set by
//! SysCtlPeripheralSleepEnable(), SysCtlPeripheralSleepDisable(),
//! SysCtlPeripheralDeepSleepEnable(), and SysCtlPeripheralDeepSleepDisable().
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPeripheralClockGating(tBoolean bEnable)
{
    //
    // Enable peripheral clock gating as requested.
    //
    if(bEnable)
    {
        HWREG(SYSCTL_RCC) |= SYSCTL_RCC_ACG;
    }
    else
    {
        HWREG(SYSCTL_RCC) &= ~(SYSCTL_RCC_ACG);
    }
}

//*****************************************************************************
//
//! Registers an interrupt handler for the system control interrupt.
//!
//! \param pfnHandler is a pointer to the function to be called when the system
//! control interrupt occurs.
//!
//! This function registers the handler to be called when a system control
//! interrupt occurs. This function enables the global interrupt in the
//! interrupt controller; specific system control interrupts must be enabled
//! via SysCtlIntEnable().  It is the interrupt handler's responsibility to
//! clear the interrupt source via SysCtlIntClear().
//!
//! System control can generate interrupts when the PLL achieves lock, if the
//! internal LDO current limit is exceeded, if the internal oscillator fails,
//! if the main oscillator fails, if the internal LDO output voltage droops too
//! much, if the external voltage droops too much, or if the PLL fails.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \note The events that cause system control interrupts vary based on the
//! Stellaris part in use.  Please consult the data sheet for the part you are
//! using to determine which interrupt sources are available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlIntRegister(void (*pfnHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    IntRegister(INT_SYSCTL, pfnHandler);

    //
    // Enable the system control interrupt.
    //
    IntEnable(INT_SYSCTL);
}

//*****************************************************************************
//
//! Unregisters the interrupt handler for the system control interrupt.
//!
//! This function unregisters the handler to be called when a system control
//! interrupt occurs.  This function also masks off the interrupt in the
//! interrupt controller so that the interrupt handler no longer is called.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlIntUnregister(void)
{
    //
    // Disable the interrupt.
    //
    IntDisable(INT_SYSCTL);

    //
    // Unregister the interrupt handler.
    //
    IntUnregister(INT_SYSCTL);
}

//*****************************************************************************
//
//! Enables individual system control interrupt sources.
//!
//! \param ulInts is a bit mask of the interrupt sources to be enabled.  Must
//! be a logical OR of \b SYSCTL_INT_PLL_LOCK, \b SYSCTL_INT_CUR_LIMIT,
//! \b SYSCTL_INT_IOSC_FAIL, \b SYSCTL_INT_MOSC_FAIL, \b SYSCTL_INT_POR,
//! \b SYSCTL_INT_BOR, and/or \b SYSCTL_INT_PLL_FAIL.
//!
//! This function enables the indicated system control interrupt sources.  Only
//! the sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! \note The interrupt sources vary based on the Stellaris part in use.
//! Please consult the data sheet for the part you are using to determine
//! which interrupt sources are available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlIntEnable(unsigned long ulInts)
{
    //
    // Enable the specified interrupts.
    //
    HWREG(SYSCTL_IMC) |= ulInts;
}

//*****************************************************************************
//
//! Disables individual system control interrupt sources.
//!
//! \param ulInts is a bit mask of the interrupt sources to be disabled.  Must
//! be a logical OR of \b SYSCTL_INT_PLL_LOCK, \b SYSCTL_INT_CUR_LIMIT,
//! \b SYSCTL_INT_IOSC_FAIL, \b SYSCTL_INT_MOSC_FAIL, \b SYSCTL_INT_POR,
//! \b SYSCTL_INT_BOR, and/or \b SYSCTL_INT_PLL_FAIL.
//!
//! This function disables the indicated system control interrupt sources.
//! Only the sources that are enabled can be reflected to the processor
//! interrupt; disabled sources have no effect on the processor.
//!
//! \note The interrupt sources vary based on the Stellaris part in use.
//! Please consult the data sheet for the part you are using to determine
//! which interrupt sources are available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlIntDisable(unsigned long ulInts)
{
    //
    // Disable the specified interrupts.
    //
    HWREG(SYSCTL_IMC) &= ~(ulInts);
}

//*****************************************************************************
//
//! Clears system control interrupt sources.
//!
//! \param ulInts is a bit mask of the interrupt sources to be cleared.  Must
//! be a logical OR of \b SYSCTL_INT_PLL_LOCK, \b SYSCTL_INT_CUR_LIMIT,
//! \b SYSCTL_INT_IOSC_FAIL, \b SYSCTL_INT_MOSC_FAIL, \b SYSCTL_INT_POR,
//! \b SYSCTL_INT_BOR, and/or \b SYSCTL_INT_PLL_FAIL.
//!
//! The specified system control interrupt sources are cleared, so that they no
//! longer assert.  This function must be called in the interrupt handler to
//! keep it from being called again immediately upon exit.
//!
//! \note Because there is a write buffer in the Cortex-M processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \note The interrupt sources vary based on the Stellaris part in use.
//! Please consult the data sheet for the part you are using to determine
//! which interrupt sources are available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlIntClear(unsigned long ulInts)
{
    //
    // Clear the requested interrupt sources.
    //
    HWREG(SYSCTL_MISC) = ulInts;
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! \param bMasked is false if the raw interrupt status is required and true if
//! the masked interrupt status is required.
//!
//! This function returns the interrupt status for the system controller.
//! Either the raw interrupt status or the status of interrupts that are
//! allowed to reflect to the processor can be returned.
//!
//! \return The current interrupt status, enumerated as a bit field of
//! \b SYSCTL_INT_PLL_LOCK, \b SYSCTL_INT_CUR_LIMIT, \b SYSCTL_INT_IOSC_FAIL,
//! \b SYSCTL_INT_MOSC_FAIL, \b SYSCTL_INT_POR, \b SYSCTL_INT_BOR, and
//! \b SYSCTL_INT_PLL_FAIL.
//!
//! \note The interrupt sources vary based on the Stellaris part in use.
//! Please consult the data sheet for the part you are using to determine
//! which interrupt sources are available.
//
//*****************************************************************************
unsigned long
SysCtlIntStatus(tBoolean bMasked)
{
    //
    // Return either the interrupt status or the raw interrupt status as
    // requested.
    //
    if(bMasked)
    {
        return(HWREG(SYSCTL_MISC));
    }
    else
    {
        return(HWREG(SYSCTL_RIS));
    }
}

//*****************************************************************************
//
//! Sets the output voltage of the LDO.
//!
//! \param ulVoltage is the required output voltage from the LDO.
//!
//! This function sets the output voltage of the LDO.  The \e ulVoltage
//! parameter specifies the LDO voltage and must be one of the following
//! values:
//! \b SYSCTL_LDO_2_25V, \b SYSCTL_LDO_2_30V, \b SYSCTL_LDO_2_35V,
//! \b SYSCTL_LDO_2_40V, \b SYSCTL_LDO_2_45V, \b SYSCTL_LDO_2_50V,
//! \b SYSCTL_LDO_2_55V, \b SYSCTL_LDO_2_60V, \b SYSCTL_LDO_2_65V,
//! \b SYSCTL_LDO_2_70V, or \b SYSCTL_LDO_2_75V.
//!
//! \note The default LDO voltage and the adjustment range varies with the
//! Stellaris part in use.  Please consult the data sheet for the part you are
//! using to determine the default voltage and range available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlLDOSet(unsigned long ulVoltage)
{
    //
    // Check the arguments.
    //
    ASSERT((ulVoltage == SYSCTL_LDO_2_25V) ||
           (ulVoltage == SYSCTL_LDO_2_30V) ||
           (ulVoltage == SYSCTL_LDO_2_35V) ||
           (ulVoltage == SYSCTL_LDO_2_40V) ||
           (ulVoltage == SYSCTL_LDO_2_45V) ||
           (ulVoltage == SYSCTL_LDO_2_50V) ||
           (ulVoltage == SYSCTL_LDO_2_55V) ||
           (ulVoltage == SYSCTL_LDO_2_60V) ||
           (ulVoltage == SYSCTL_LDO_2_65V) ||
           (ulVoltage == SYSCTL_LDO_2_70V) ||
           (ulVoltage == SYSCTL_LDO_2_75V));

    //
    // Set the LDO voltage to the requested value.
    //
    HWREG(SYSCTL_LDOPCTL) = ulVoltage;
}

//*****************************************************************************
//
//! Gets the output voltage of the LDO.
//!
//! This function determines the output voltage of the LDO, as specified by the
//! control register.
//!
//! \return Returns the current voltage of the LDO and is one of:
//! \b SYSCTL_LDO_2_25V, \b SYSCTL_LDO_2_30V, \b SYSCTL_LDO_2_35V,
//! \b SYSCTL_LDO_2_40V, \b SYSCTL_LDO_2_45V, \b SYSCTL_LDO_2_50V,
//! \b SYSCTL_LDO_2_55V, \b SYSCTL_LDO_2_60V, \b SYSCTL_LDO_2_65V,
//! \b SYSCTL_LDO_2_70V, or \b SYSCTL_LDO_2_75V.
//
//*****************************************************************************
unsigned long
SysCtlLDOGet(void)
{
    //
    // Return the LDO voltage setting.
    //
    return(HWREG(SYSCTL_LDOPCTL));
}

//*****************************************************************************
//
//! Configures the LDO failure control.
//!
//! \param ulConfig is the required LDO failure control setting; can be either
//! \b SYSCTL_LDOCFG_ARST or \b SYSCTL_LDOCFG_NORST.
//!
//! This function allows the LDO to be configured to cause a processor reset
//! when the output voltage becomes unregulated.
//!
//! The LDO failure control is only available on Sandstorm-class devices.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlLDOConfigSet(unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT((ulConfig == SYSCTL_LDOCFG_ARST) ||
           (ulConfig == SYSCTL_LDOCFG_NORST));

    //
    // Set the reset control as requested.
    //
    HWREG(SYSCTL_LDOARST) = ulConfig;
}

//*****************************************************************************
//
//! Resets the device.
//!
//! This function performs a software reset of the entire device.  The
//! processor and all peripherals are reset and all device registers are
//! returned to their default values (with the exception of the reset cause
//! register, which maintains its current value but has the software reset
//! bit set as well).
//!
//! \return This function does not return.
//
//*****************************************************************************
void
SysCtlReset(void)
{
    //
    // Perform a software reset request.  This request causes the device to
    // reset, no further code is executed.
    //
    HWREG(NVIC_APINT) = NVIC_APINT_VECTKEY | NVIC_APINT_SYSRESETREQ;

    //
    // The device should have reset, so this should never be reached.  Just in
    // case, loop forever.
    //
    while(1)
    {
    }
}

//*****************************************************************************
//
//! Puts the processor into sleep mode.
//!
//! This function places the processor into sleep mode; it does not return
//! until the processor returns to run mode.  The peripherals that are enabled
//! via SysCtlPeripheralSleepEnable() continue to operate and can wake up the
//! processor (if automatic clock gating is enabled with
//! SysCtlPeripheralClockGating(), otherwise all peripherals continue to
//! operate).
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlSleep(void)
{
    //
    // Wait for an interrupt.
    //
    CPUwfi();
}

//*****************************************************************************
//
//! Puts the processor into deep-sleep mode.
//!
//! This function places the processor into deep-sleep mode; it does not return
//! until the processor returns to run mode.  The peripherals that are enabled
//! via SysCtlPeripheralDeepSleepEnable() continue to operate and can wake up
//! the processor (if automatic clock gating is enabled with
//! SysCtlPeripheralClockGating(), otherwise all peripherals continue to
//! operate).
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlDeepSleep(void)
{
    //
    // Enable deep-sleep.
    //
    HWREG(NVIC_SYS_CTRL) |= NVIC_SYS_CTRL_SLEEPDEEP;

    //
    // Wait for an interrupt.
    //
    CPUwfi();

    //
    // Disable deep-sleep so that a future sleep works correctly.
    //
    HWREG(NVIC_SYS_CTRL) &= ~(NVIC_SYS_CTRL_SLEEPDEEP);
}

//*****************************************************************************
//
//! Gets the reason for a reset.
//!
//! This function returns the reason(s) for a reset.  Because the reset
//! reasons are sticky until either cleared by software or an external reset
//! (for Sandstorm-class devices) or a power-on reset (for all other classes),
//! multiple reset reasons may be returned if multiple resets have occurred.
//! The reset reason is a logical OR of \b SYSCTL_CAUSE_LDO,
//! \b SYSCTL_CAUSE_SW, \b SYSCTL_CAUSE_WDOG, \b SYSCTL_CAUSE_BOR,
//! \b SYSCTL_CAUSE_POR, and/or \b SYSCTL_CAUSE_EXT.
//!
//! \return Returns the reason(s) for a reset.
//
//*****************************************************************************
unsigned long
SysCtlResetCauseGet(void)
{
    //
    // Return the reset reasons.
    //
    return(HWREG(SYSCTL_RESC));
}

//*****************************************************************************
//
//! Clears reset reasons.
//!
//! \param ulCauses are the reset causes to be cleared; must be a logical OR of
//! \b SYSCTL_CAUSE_LDO, \b SYSCTL_CAUSE_SW, \b SYSCTL_CAUSE_WDOG,
//! \b SYSCTL_CAUSE_BOR, \b SYSCTL_CAUSE_POR, and/or \b SYSCTL_CAUSE_EXT.
//!
//! This function clears the specified sticky reset reasons.  Once cleared,
//! another reset for the same reason can be detected, and a reset for a
//! different reason can be distinguished (instead of having two reset causes
//! set).  If the reset reason is used by an application, all reset causes
//! should be cleared after they are retrieved with SysCtlResetCauseGet().
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlResetCauseClear(unsigned long ulCauses)
{
    //
    // Clear the given reset reasons.
    //
    HWREG(SYSCTL_RESC) &= ~(ulCauses);
}

//*****************************************************************************
//
//! Configures the brown-out control.
//!
//! \param ulConfig is the desired configuration of the brown-out control.
//! Must be the logical OR of \b SYSCTL_BOR_RESET and/or
//! \b SYSCTL_BOR_RESAMPLE.
//! \param ulDelay is the number of internal oscillator cycles to wait before
//! resampling an asserted brown-out signal.  This value only has meaning when
//! \b SYSCTL_BOR_RESAMPLE is set and must be less than 8192.
//!
//! This function configures how the brown-out control operates.  It can detect
//! a brown-out by looking at only the brown-out output, or it can wait for it
//! to be active for two consecutive samples separated by a configurable time.
//! When it detects a brown-out condition, it can either reset the device or
//! generate a processor interrupt.
//!
//! \note The availability of the resample feature is only available on
//! Sandstorm-class devices. Please consult the data sheet for the part you
//! are using to determine whether this feature is available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlBrownOutConfigSet(unsigned long ulConfig, unsigned long ulDelay)
{
    //
    // Check the arguments.
    //
    ASSERT(!(ulConfig & ~(SYSCTL_BOR_RESET | SYSCTL_BOR_RESAMPLE)));
    ASSERT(ulDelay < 8192);

    //
    // Configure the brown-out reset control.
    //
    HWREG(SYSCTL_PBORCTL) = (ulDelay << SYSCTL_PBORCTL_BORTIM_S) | ulConfig;
}

//*****************************************************************************
//
//! Provides a small delay.
//!
//! \param ulCount is the number of delay loop iterations to perform.
//!
//! This function provides a means of generating a constant length delay.  It
//! is written in assembly to keep the delay consistent across tool chains,
//! avoiding the need to tune the delay based on the tool chain in use.
//!
//! The loop takes 3 cycles/loop.
//!
//! \return None.
//
//*****************************************************************************
#if defined(ewarm) || defined(DOXYGEN)
void
SysCtlDelay(unsigned long ulCount)
{
    __asm("    subs    r0, #1\n"
          "    bne.n   SysCtlDelay\n"
          "    bx      lr");
}
#endif
#if defined(codered) || defined(gcc) || defined(sourcerygxx)
void __attribute__((naked))
SysCtlDelay(unsigned long ulCount)
{
    __asm("    subs    r0, #1\n"
          "    bne     SysCtlDelay\n"
          "    bx      lr");
}
#endif
#if defined(rvmdk) || defined(__ARMCC_VERSION)
__asm void
SysCtlDelay(unsigned long ulCount)
{
    subs    r0, #1;
    bne     SysCtlDelay;
    bx      lr;
}
#endif
//
// For CCS implement this function in pure assembly.  This prevents the TI
// compiler from doing funny things with the optimizer.
//
#if defined(ccs)
    __asm("    .sect \".text:SysCtlDelay\"\n"
          "    .clink\n"
          "    .thumbfunc SysCtlDelay\n"
          "    .thumb\n"
          "    .global SysCtlDelay\n"
          "SysCtlDelay:\n"
          "    subs r0, #1\n"
          "    bne.n SysCtlDelay\n"
          "    bx lr\n");
#endif

//*****************************************************************************
//
//! Sets the configuration of the main oscillator (MOSC) control.
//!
//! \param ulConfig is the required configuration of the MOSC control.
//!
//! This function configures the control of the main oscillator.  The
//! \e ulConfig is specified as follows:
//!
//! - \b SYSCTL_MOSC_VALIDATE enables the MOSC verification circuit that
//!   detects a failure of the main oscillator (such as a loss of the clock).
//! - \b SYSCTL_MOSC_INTERRUPT indicates that a MOSC failure should generate an
//!   interrupt instead of resetting the processor.
//! - \b SYSCTL_MOSC_NO_XTAL indicates that there is no crystal connected to
//!   the OSC0/OSC1 pins, allowing power consumption to be reduced.
//!
//! \note The availability of MOSC control varies based on the Stellaris part
//! in use.  Please consult the data sheet for the part you are using to
//! determine whether this support is available. In addition, the capability
//! of MOSC control varies based on the Stellaris part in use.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlMOSCConfigSet(unsigned long ulConfig)
{
    //
    // Configure the MOSC control.
    //
    HWREG(SYSCTL_MOSCCTL) = ulConfig;
}

//*****************************************************************************
//
//! Calibrates the precision internal oscillator.
//!
//! \param ulType is the type of calibration to perform.
//!
//! This function performs a calibration of the PIOSC.  There are three types
//! of calibration available; the desired calibration type as specified in
//! \e ulType is one of:
//!
//! - \b SYSCTL_PIOSC_CAL_AUTO to perform automatic calibration using the
//!   32-kHz clock from the hibernate module as a reference.  This type is
//!   only possible on parts that have a hibernate module, and then only if
//!   it is enabled and the hibernate module's RTC is also enabled.
//!
//! - \b SYSCTL_PIOSC_CAL_FACT to reset the PIOSC calibration to the factory
//!   provided calibration.
//!
//! - \b SYSCTL_PIOSC_CAL_USER to set the PIOSC calibration to a user-supplied
//!   value.  The value to be used is ORed into the lower 7-bits of this value,
//!   with 0x40 being the ``nominal'' value (in other words, if everything were
//!   perfect, 0x40 provides exactly 16 MHz).  Values larger than 0x40
//!   slow down PIOSC, and values smaller than 0x40 speed up PIOSC.
//!
//! \return Returns 1 if the calibration was successful and 0 if it failed.
//
//*****************************************************************************
unsigned long
SysCtlPIOSCCalibrate(unsigned long ulType)
{
    //
    // Perform the requested calibration.  If performing user calibration, the
    // UTEN bit must be set with one write, then the UT field in a second
    // write, and the UPDATE bit in a final write.  For other calibration
    // types, a single write to set UPDATE or CAL is all that is required.
    //
    if(ulType & (SYSCTL_PIOSCCAL_UTEN | SYSCTL_PIOSCCAL_UPDATE))
    {
        HWREG(SYSCTL_PIOSCCAL) = ulType & SYSCTL_PIOSCCAL_UTEN;
        HWREG(SYSCTL_PIOSCCAL) =
            ulType & (SYSCTL_PIOSCCAL_UTEN | SYSCTL_PIOSCCAL_UT_M);
    }
    HWREG(SYSCTL_PIOSCCAL) = ulType;

    //
    // See if an automatic calibration was requested.
    //
    if(ulType & SYSCTL_PIOSCCAL_CAL)
    {
        //
        // Wait for the automatic calibration to complete.
        //
        while((HWREG(SYSCTL_PIOSCSTAT) & SYSCTL_PIOSCSTAT_CR_M) == 0)
        {
        }

        //
        // If the automatic calibration failed, return an error.
        //
        if((HWREG(SYSCTL_PIOSCSTAT) & SYSCTL_PIOSCSTAT_CR_M) !=
           SYSCTL_PIOSCSTAT_CRPASS)
        {
            return(0);
        }
    }

    //
    // The calibration was successful.
    //
    return(1);
}
    unsigned long ulSysDiv, ulOsc, ulOscSelect;
    tBoolean bNewPLL;


//*****************************************************************************
//
//! Sets the clocking of the device.
//!
//! \param ulConfig is the required configuration of the device clocking.
//!
//! This function configures the clocking of the device.  The input crystal
//! frequency, oscillator to be used, use of the PLL, and the system clock
//! divider are all configured with this function.
//!
//! The \e ulConfig parameter is the logical OR of several different values,
//! many of which are grouped into sets where only one can be chosen.
//!
//! The system clock divider is chosen with one of the following values:
//! \b SYSCTL_SYSDIV_1, \b SYSCTL_SYSDIV_2, \b SYSCTL_SYSDIV_3, ...
//! \b SYSCTL_SYSDIV_64.  Only \b SYSCTL_SYSDIV_1 through \b SYSCTL_SYSDIV_16
//! are valid on Sandstorm-class devices. Half-dividers, such as
//! \b SYSCTL_SYSDIV_2_5 and \b SYSCTL_SYSDIV_3_5. are available on Tempest-,
//! Firestorm-, and Blizzard-class devices.
//!
//! The use of the PLL is chosen with either \b SYSCTL_USE_PLL or
//! \b SYSCTL_USE_OSC.
//!
//! The external crystal frequency is chosen with one of the following values:
//! \b SYSCTL_XTAL_1MHZ, \b SYSCTL_XTAL_1_84MHZ, \b SYSCTL_XTAL_2MHZ,
//! \b SYSCTL_XTAL_2_45MHZ, \b SYSCTL_XTAL_3_57MHZ, \b SYSCTL_XTAL_3_68MHZ,
//! \b SYSCTL_XTAL_4MHZ, \b SYSCTL_XTAL_4_09MHZ, \b SYSCTL_XTAL_4_91MHZ,
//! \b SYSCTL_XTAL_5MHZ, \b SYSCTL_XTAL_5_12MHZ, \b SYSCTL_XTAL_6MHZ,
//! \b SYSCTL_XTAL_6_14MHZ, \b SYSCTL_XTAL_7_37MHZ, \b SYSCTL_XTAL_8MHZ,
//! \b SYSCTL_XTAL_8_19MHZ, \b SYSCTL_XTAL_10MHZ, \b SYSCTL_XTAL_12MHZ,
//! \b SYSCTL_XTAL_12_2MHZ, \b SYSCTL_XTAL_13_5MHZ, \b SYSCTL_XTAL_14_3MHZ,
//! \b SYSCTL_XTAL_16MHZ, \b SYSCTL_XTAL_16_3MHZ, \b SYSCTL_XTAL_18MHZ,
//! \b SYSCTL_XTAL_20MHZ, \b SYSCTL_XTAL_24MHZ, or \b SYSCTL_XTAL_25MHz.
//! Values below \b SYSCTL_XTAL_3_57MHZ are not valid when the PLL is in
//! operation on Sandstorm-, Fury-, Dustdevil-, Tempest-, and Firestorm-class.
//! devices. Values below \b SYSCTL_XTAL_5MHZ are not valid when the PLL is in
//! operation on Blizzard-class devices.  Values below \b SYSCTL_XTAL_4MHZ
//! are never valid on Blizzard-class devices. On  Sandstorm- and Fury-class
//! devices, values above \b SYSCTL_XTAL_8_19MHZ are not valid. On Dustdevil-,
//! Tempest-, and Firestorm-class devices, values above \b SYSCTL_XTAL_16_3MHZ
//! are not valid.
//!
//! The oscillator source is chosen with one of the following values:
//! \b SYSCTL_OSC_MAIN, \b SYSCTL_OSC_INT, \b SYSCTL_OSC_INT4,
//! \b SYSCTL_OSC_INT30, or \b SYSCTL_OSC_EXT32.  On Sandstorm-class devices,
//! \b SYSCTL_OSC_INT30 and \b SYSCTL_OSC_EXT32 are not valid.
//! \b SYSCTL_OSC_EXT32 is only available on devices with the hibernate module,
//! and then only when the hibernate module has been enabled.
//!
//! The internal and main oscillators are disabled with the
//! \b SYSCTL_INT_OSC_DIS and \b SYSCTL_MAIN_OSC_DIS flags, respectively.
//! The external oscillator must be enabled in order to use an external clock
//! source.  Note that attempts to disable the oscillator used to clock the
//! device is prevented by the hardware.
//!
//! To clock the system from an external source (such as an external crystal
//! oscillator), use \b SYSCTL_USE_OSC \b | \b SYSCTL_OSC_MAIN.  To clock the
//! system from the main oscillator, use \b SYSCTL_USE_OSC \b |
//! \b SYSCTL_OSC_MAIN.  To clock the system from the PLL, use
//! \b SYSCTL_USE_PLL \b | \b SYSCTL_OSC_MAIN, and select the appropriate
//! crystal with one of the \b SYSCTL_XTAL_xxx values.
//!
//! \note If selecting the PLL as the system clock source (that is, via
//! \b SYSCTL_USE_PLL), this function polls the PLL lock interrupt to
//! determine when the PLL has locked.  If an interrupt handler for the
//! system control interrupt is in place, and it responds to and clears the
//! PLL lock interrupt, this function delays until its timeout has occurred
//! instead of completing as soon as PLL lock is achieved.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlClockSet(unsigned long ulConfig)
{
    unsigned long ulDelay, ulRCC, ulRCC2;

    //
    // See if this is a Sandstorm-class device and clocking features from newer
    // devices were requested.
    //
    if(CLASS_IS_SANDSTORM && (ulConfig & SYSCTL_RCC2_USERCC2))
    {
        //
        // Return without changing the clocking because the requested
        // configuration can not be achieved.
        //
        return;
    }

    //
    // Get the current value of the RCC and RCC2 registers.  If using a
    // Sandstorm-class device, the RCC2 register reads back as zero and the
    // writes to it from within this function are ignored.
    //
    ulRCC = HWREG(SYSCTL_RCC);
    ulRCC2 = HWREG(SYSCTL_RCC2);

    //
    // Bypass the PLL and system clock dividers for now.
    //
    ulRCC |= SYSCTL_RCC_BYPASS;
    ulRCC &= ~(SYSCTL_RCC_USESYSDIV);
    ulRCC2 |= SYSCTL_RCC2_BYPASS2;

    //
    // Write the new RCC value.
    //
    HWREG(SYSCTL_RCC) = ulRCC;
    HWREG(SYSCTL_RCC2) = ulRCC2;

    //
    // See if either oscillator needs to be enabled.
    //
    if(((ulRCC & SYSCTL_RCC_IOSCDIS) && !(ulConfig & SYSCTL_RCC_IOSCDIS)) ||
       ((ulRCC & SYSCTL_RCC_MOSCDIS) && !(ulConfig & SYSCTL_RCC_MOSCDIS)))
    {
        //
        // Make sure that the required oscillators are enabled.  For now, the
        // previously enabled oscillators must be enabled along with the newly
        // requested oscillators.
        //
        ulRCC &= (~(SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS) |
                  (ulConfig & (SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS)));

        //
        // Write the new RCC value.
        //
        HWREG(SYSCTL_RCC) = ulRCC;

        //
        // Wait for a bit, giving the oscillator time to stabilize.  The number
        // of iterations is adjusted based on the current clock source; a
        // smaller number of iterations is required for slower clock rates.
        //
        if(((ulRCC2 & SYSCTL_RCC2_USERCC2) &&
            (((ulRCC2 & SYSCTL_RCC2_OSCSRC2_M) == SYSCTL_RCC2_OSCSRC2_30) ||
             ((ulRCC2 & SYSCTL_RCC2_OSCSRC2_M) == SYSCTL_RCC2_OSCSRC2_32))) ||
           (!(ulRCC2 & SYSCTL_RCC2_USERCC2) &&
            ((ulRCC & SYSCTL_RCC_OSCSRC_M) == SYSCTL_RCC_OSCSRC_30)))
        {
            //
            // Delay for 4096 iterations.
            //
            SysCtlDelay(4096);
        }
        else
        {
            //
            // Delay for 524,288 iterations.
            //
            SysCtlDelay(524288);
        }
    }

    //
    // Set the new crystal value and oscillator source.  Because the OSCSRC2
    // field in RCC2 overlaps the XTAL field in RCC, the OSCSRC field has a
    // special encoding within ulConfig to avoid the overlap.
    //
    ulRCC &= ~(SYSCTL_RCC_XTAL_M | SYSCTL_RCC_OSCSRC_M);
    ulRCC |= ulConfig & (SYSCTL_RCC_XTAL_M | SYSCTL_RCC_OSCSRC_M);
    ulRCC2 &= ~(SYSCTL_RCC2_USERCC2 | SYSCTL_RCC2_OSCSRC2_M);
    ulRCC2 |= ulConfig & (SYSCTL_RCC2_USERCC2 | SYSCTL_RCC_OSCSRC_M);
    ulRCC2 |= (ulConfig & 0x00000008) << 3;

    //
    // Write the new RCC value.
    //
    HWREG(SYSCTL_RCC) = ulRCC;
    HWREG(SYSCTL_RCC2) = ulRCC2;

    //
    // Wait for a bit so that new crystal value and oscillator source can take
    // effect.
    //
    SysCtlDelay(16);

    //
    // Set the PLL configuration.
    //
    ulRCC &= ~(SYSCTL_RCC_PWRDN | SYSCTL_RCC_OEN);
    ulRCC |= ulConfig & (SYSCTL_RCC_PWRDN | SYSCTL_RCC_OEN);
    ulRCC2 &= ~(SYSCTL_RCC2_PWRDN2);
    ulRCC2 |= ulConfig & SYSCTL_RCC2_PWRDN2;

    //
    // Clear the PLL lock interrupt.
    //
    HWREG(SYSCTL_MISC) = SYSCTL_INT_PLL_LOCK;

    //
    // Write the new RCC value.
    //
    if(ulRCC2 & SYSCTL_RCC2_USERCC2)
    {
        HWREG(SYSCTL_RCC2) = ulRCC2;
        HWREG(SYSCTL_RCC) = ulRCC;
    }
    else
    {
        HWREG(SYSCTL_RCC) = ulRCC;
        HWREG(SYSCTL_RCC2) = ulRCC2;
    }

    //
    // Set the requested system divider and disable the appropriate
    // oscillators.  This value is not written immediately.
    //
    ulRCC &= ~(SYSCTL_RCC_SYSDIV_M | SYSCTL_RCC_USESYSDIV |
               SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS);
    ulRCC |= ulConfig & (SYSCTL_RCC_SYSDIV_M | SYSCTL_RCC_USESYSDIV |
                         SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS);
    ulRCC2 &= ~(SYSCTL_RCC2_SYSDIV2_M);
    ulRCC2 |= ulConfig & SYSCTL_RCC2_SYSDIV2_M;
    if(ulConfig & SYSCTL_RCC2_DIV400)
    {
        ulRCC |= SYSCTL_RCC_USESYSDIV;
        ulRCC2 &= ~(SYSCTL_RCC_USESYSDIV);
        ulRCC2 |= ulConfig & (SYSCTL_RCC2_DIV400 | SYSCTL_RCC2_SYSDIV2LSB);
    }
    else
    {
        ulRCC2 &= ~(SYSCTL_RCC2_DIV400);
    }

    //
    // See if the PLL output is being used to clock the system.
    //
    if(!(ulConfig & SYSCTL_RCC_BYPASS))
    {
        //
        // Wait until the PLL has locked.
        //
        for(ulDelay = 32768; ulDelay > 0; ulDelay--)
        {
            if(HWREG(SYSCTL_RIS) & SYSCTL_INT_PLL_LOCK)
            {
                break;
            }
        }

        //
        // Enable use of the PLL.
        //
        ulRCC &= ~(SYSCTL_RCC_BYPASS);
        ulRCC2 &= ~(SYSCTL_RCC2_BYPASS2);
    }

    //
    // Write the final RCC value.
    //
    HWREG(SYSCTL_RCC) = ulRCC;
    HWREG(SYSCTL_RCC2) = ulRCC2;

    //
    // Delay for a little bit so that the system divider takes effect.
    //
    SysCtlDelay(16);
}

//*****************************************************************************
//
//! Gets the processor clock rate.
//!
//! This function determines the clock rate of the processor clock, which is
//! also the clock rate of the peripheral modules (with the exception of
//! PWM, which has its own clock divider; other peripherals may have different
//! clocking, see the device data sheet for details).
//!
//! \note This cannot return accurate results if SysCtlClockSet() has not
//! been called to configure the clocking of the device, or if the device is
//! directly clocked from a crystal (or a clock source) that is not one of the
//! supported crystal frequencies.  In the latter case, this function should be
//! modified to directly return the correct system clock rate.
//!
//! \return The processor clock rate.
//
//*****************************************************************************
unsigned long
SysCtlClockGet(void)
{
    unsigned long ulRCC, ulRCC2, ulPLL, ulClk;
    unsigned long ulPLL1;

    //
    // Read RCC and RCC2.  For Sandstorm-class devices (which do not have
    // RCC2), the RCC2 read returns 0, indicating that RCC2 is
    // disabled (because the SYSCTL_RCC2_USERCC2 bit is clear).
    //
    ulRCC = HWREG(SYSCTL_RCC);
    ulRCC2 = HWREG(SYSCTL_RCC2);

    //
    // Get the base clock rate.
    //
    switch((ulRCC2 & SYSCTL_RCC2_USERCC2) ?
           (ulRCC2 & SYSCTL_RCC2_OSCSRC2_M) :
           (ulRCC & SYSCTL_RCC_OSCSRC_M))
    {
        //
        // The main oscillator is the clock source.  Determine its rate from
        // the crystal setting field.
        //
        case SYSCTL_RCC_OSCSRC_MAIN:
        {
            ulClk = g_pulXtals[(ulRCC & SYSCTL_RCC_XTAL_M) >>
                               SYSCTL_RCC_XTAL_S];
            break;
        }

        //
        // The internal oscillator is the source clock.
        //
        case SYSCTL_RCC_OSCSRC_INT:
        {
            //
            // See if this is a Sandstorm-class or Fury-class device.
            //
            if(CLASS_IS_SANDSTORM)
            {
                //
                // The internal oscillator on a Sandstorm-class device is
                // 15 MHz +/- 50%.
                //
                ulClk = 15000000;
            }
            else if((CLASS_IS_FURY && REVISION_IS_A2) ||
                    (CLASS_IS_DUSTDEVIL && REVISION_IS_A0))
            {
                //
                // The internal oscillator on a rev A2 Fury-class device and a
                // Dustdevil-class device is 12 MHz +/- 30%.
                //
                ulClk = 12000000;
            }
            else
            {
                //
                // The internal oscillator on all other devices is 16 MHz.
                //
                ulClk = 16000000;
            }
            break;
        }

        //
        // The internal oscillator divided by four is the source clock.
        //
        case SYSCTL_RCC_OSCSRC_INT4:
        {
            //
            // See if this is a Sandstorm-class or Fury-class device.
            //
            if(CLASS_IS_SANDSTORM)
            {
                //
                // The internal oscillator on a Sandstorm-class device is
                // 15 MHz +/- 50%.
                //
                ulClk = 15000000 / 4;
            }
            else if((CLASS_IS_FURY && REVISION_IS_A2) ||
                    (CLASS_IS_DUSTDEVIL && REVISION_IS_A0))
            {
                //
                // The internal oscillator on a rev A2 Fury-class device and a
                // Dustdevil-class device is 12 MHz +/- 30%.
                //
                ulClk = 12000000 / 4;
            }
            else
            {
                //
                // The internal oscillator on a Tempest-class device is 16 MHz.
                //
                ulClk = 16000000 / 4;
            }
            break;
        }

        //
        // The internal 30-KHz oscillator is the source clock.
        //
        case SYSCTL_RCC_OSCSRC_30:
        {
            //
            // The internal 30-KHz oscillator has an accuracy of +/- 30%.
            //
            ulClk = 30000;
            break;
        }

        //
        // The 4.194304-MHz clock from the hibernate module is the clock
        // source.
        //
        case SYSCTL_RCC2_OSCSRC2_419:
        {
            ulClk = 4194304;
            break;
        }

        //
        // The 32.768-KHz clock from the hibernate module is the source clock.
        //
        case SYSCTL_RCC2_OSCSRC2_32:
        {
            ulClk = 32768;
            break;
        }

        //
        // An unknown setting, so return a zero clock (that is, an unknown
        // clock rate).
        //
        default:
        {
            return(0);
        }
    }

    //
    // See if the PLL is being used.
    //
    if(((ulRCC2 & SYSCTL_RCC2_USERCC2) && !(ulRCC2 & SYSCTL_RCC2_BYPASS2)) ||
       (!(ulRCC2 & SYSCTL_RCC2_USERCC2) && !(ulRCC & SYSCTL_RCC_BYPASS)))
    {
        //
        // See if this is a Blizzard-class device.
        //
        if(CLASS_IS_BLIZZARD)
        {
            //
            // Read the two PLL frequency registers.  The formula for a
            // Blizzard-class device is "(xtal * m) / ((q + 1) * (n + 1))".
            //
            ulPLL = HWREG(SYSCTL_PLLFREQ0);
            ulPLL1 = HWREG(SYSCTL_PLLFREQ1);

            //
            // Divide the input clock by the dividers.
            //
            ulClk /= ((((ulPLL1 & SYSCTL_PLLFREQ1_Q_M) >>
                        SYSCTL_PLLFREQ1_Q_S) + 1) *
                      (((ulPLL1 & SYSCTL_PLLFREQ1_N_M) >>
                        SYSCTL_PLLFREQ1_N_S) + 1) * 2);

            //
            // Multiply the clock by the multiplier, which is split into an
            // integer part and a fractional part.
            //
            ulClk = ((ulClk * ((ulPLL & SYSCTL_PLLFREQ0_MINT_M) >>
                               SYSCTL_PLLFREQ0_MINT_S)) +
                     ((ulClk * ((ulPLL & SYSCTL_PLLFREQ0_MFRAC_M) >>
                                SYSCTL_PLLFREQ0_MFRAC_S)) >> 10));
        }

        //
        // Older device classes used a different PLL.
        //
        else
        {
            //
            // Get the PLL configuration.
            //
            ulPLL = HWREG(SYSCTL_PLLCFG);

            //
            // See if this is a Sandstorm-class or Fury-class device.
            //
            if(CLASS_IS_SANDSTORM)
            {
                //
                // Compute the PLL output frequency based on its input
                // frequency.  The formula for a Sandstorm-class devices is
                // "(xtal * (f + 2)) / (r + 2)".
                //
                ulClk = ((ulClk * (((ulPLL & SYSCTL_PLLCFG_F_M) >>
                                    SYSCTL_PLLCFG_F_S) + 2)) /
                         (((ulPLL & SYSCTL_PLLCFG_R_M) >>
                           SYSCTL_PLLCFG_R_S) + 2));
            }
            else
            {
                //
                // Compute the PLL output frequency based on its input
                // frequency.  The formula for a Fury-class device is
                // "(xtal * f) / ((r + 1) * 2)".
                //
                ulClk = ((ulClk * ((ulPLL & SYSCTL_PLLCFG_F_M) >>
                                   SYSCTL_PLLCFG_F_S)) /
                         ((((ulPLL & SYSCTL_PLLCFG_R_M) >>
                            SYSCTL_PLLCFG_R_S) + 1) * 2));
            }

            //
            // See if the optional output divide by 2 is being used.
            //
            if(ulPLL & SYSCTL_PLLCFG_OD_2)
            {
                ulClk /= 2;
            }

            //
            // See if the optional output divide by 4 is being used.
            //
            if(ulPLL & SYSCTL_PLLCFG_OD_4)
            {
                ulClk /= 4;
            }
        }

        //
        // Force the system divider to be enabled.  It is always used when
        // using the PLL, but in some cases it does not read as being enabled.
        //
        ulRCC |= SYSCTL_RCC_USESYSDIV;
    }

    //
    // See if the system divider is being used.
    //
    if(ulRCC & SYSCTL_RCC_USESYSDIV)
    {
        //
        // Adjust the clock rate by the system clock divider.
        //
        if(ulRCC2 & SYSCTL_RCC2_USERCC2)
        {
            if((ulRCC2 & SYSCTL_RCC2_DIV400) &&
               (((ulRCC2 & SYSCTL_RCC2_USERCC2) &&
                 !(ulRCC2 & SYSCTL_RCC2_BYPASS2)) ||
                (!(ulRCC2 & SYSCTL_RCC2_USERCC2) &&
                 !(ulRCC & SYSCTL_RCC_BYPASS))))

            {
                ulClk = ((ulClk * 2) / (((ulRCC2 & (SYSCTL_RCC2_SYSDIV2_M |
                                                    SYSCTL_RCC2_SYSDIV2LSB)) >>
                                         (SYSCTL_RCC2_SYSDIV2_S - 1)) + 1));
            }
            else
            {
                ulClk /= (((ulRCC2 & SYSCTL_RCC2_SYSDIV2_M) >>
                           SYSCTL_RCC2_SYSDIV2_S) + 1);
            }
        }
        else
        {
            ulClk /= (((ulRCC & SYSCTL_RCC_SYSDIV_M) >> SYSCTL_RCC_SYSDIV_S) +
                      1);
        }
    }

    //
    // Return the computed clock rate.
    //
    return(ulClk);
}

//*****************************************************************************
//
//! Sets the clocking of the device while in deep-sleep mode.
//!
//! \param ulConfig is the required configuration of the device clocking while
//! in deep-sleep mode.
//!
//! This function configures the clocking of the device while in deep-sleep
//! mode.  The oscillator to be used and the system clock divider are
//! configured with this function.
//!
//! The \e ulConfig parameter is the logical OR of the following values:
//!
//! The system clock divider is chosen from one of the following values:
//! \b SYSCTL_DSLP_DIV_1, \b SYSCTL_DSLP_DIV_2, \b SYSCTL_DSLP_DIV_3, ...
//! \b SYSCTL_DSLP_DIV_64.
//!
//! The oscillator source is chosen from one of the following values:
//! \b SYSCTL_DSLP_OSC_MAIN, \b SYSCTL_DSLP_OSC_INT, \b SYSCTL_DSLP_OSC_INT30,
//! or \b SYSCTL_DSLP_OSC_EXT32.  \b SYSCTL_OSC_EXT32 is only available on
//! devices with the hibernation module, and then only when the hibernation
//! module has been enabled.
//!
//! The precision internal oscillator can be powered down in deep-sleep mode by
//! specifying \b SYSCTL_DSLP_PIOSC_PD.  The precision internal oscillator is
//! not powered down if it is required for operation while in deep-sleep
//! (based on other configuration settings.)
//!
//! \note The availability of deep-sleep clocking configuration varies with the
//! Stellaris part in use.  Please consult the data sheet for the part you are
//! using to determine whether this support is available.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlDeepSleepClockSet(unsigned long ulConfig)
{
    //
    // Set the deep-sleep clock configuration.
    //
    HWREG(SYSCTL_DSLPCLKCFG) = ulConfig;
}

//*****************************************************************************
//
//! Sets the PWM clock configuration.
//!
//! \param ulConfig is the configuration for the PWM clock; it must be one of
//! \b SYSCTL_PWMDIV_1, \b SYSCTL_PWMDIV_2, \b SYSCTL_PWMDIV_4,
//! \b SYSCTL_PWMDIV_8, \b SYSCTL_PWMDIV_16, \b SYSCTL_PWMDIV_32, or
//! \b SYSCTL_PWMDIV_64.
//!
//! This function configures the rate of the clock provided to the PWM module
//! as a ratio of the processor clock.  This clock is used by the PWM module to
//! generate PWM signals; its rate forms the basis for all PWM signals.
//!
//! \note The clocking of the PWM is dependent upon the system clock rate as
//! configured by SysCtlClockSet().
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPWMClockSet(unsigned long ulConfig)
{
    //
    // Check the arguments.
    //
    ASSERT((ulConfig == SYSCTL_PWMDIV_1) ||
           (ulConfig == SYSCTL_PWMDIV_2) ||
           (ulConfig == SYSCTL_PWMDIV_4) ||
           (ulConfig == SYSCTL_PWMDIV_8) ||
           (ulConfig == SYSCTL_PWMDIV_16) ||
           (ulConfig == SYSCTL_PWMDIV_32) ||
           (ulConfig == SYSCTL_PWMDIV_64));

    //
    // Check that there is a PWM block on this part.
    //
    ASSERT(HWREG(SYSCTL_DC1) & SYSCTL_DC1_PWM0);

    //
    // Set the PWM clock configuration into the run-mode clock configuration
    // register.
    //
    HWREG(SYSCTL_RCC) = ((HWREG(SYSCTL_RCC) &
                          ~(SYSCTL_RCC_USEPWMDIV | SYSCTL_RCC_PWMDIV_M)) |
                         ulConfig);
}

//*****************************************************************************
//
//! Gets the current PWM clock configuration.
//!
//! This function returns the current PWM clock configuration.
//!
//! \return Returns the current PWM clock configuration; is one of
//! \b SYSCTL_PWMDIV_1, \b SYSCTL_PWMDIV_2, \b SYSCTL_PWMDIV_4,
//! \b SYSCTL_PWMDIV_8, \b SYSCTL_PWMDIV_16, \b SYSCTL_PWMDIV_32, or
//! \b SYSCTL_PWMDIV_64.
//
//*****************************************************************************
unsigned long
SysCtlPWMClockGet(void)
{
    //
    // Check that there is a PWM block on this part.
    //
    ASSERT(HWREG(SYSCTL_DC1) & SYSCTL_DC1_PWM0);

    //
    // Return the current PWM clock configuration.  Make sure that
    // SYSCTL_PWMDIV_1 is returned in all cases where the divider is disabled.
    //
    if(!(HWREG(SYSCTL_RCC) & SYSCTL_RCC_USEPWMDIV))
    {
        //
        // The divider is not active so reflect this in the value we return.
        //
        return(SYSCTL_PWMDIV_1);
    }
    else
    {
        //
        // The divider is active so directly return the masked register value.
        //
        return(HWREG(SYSCTL_RCC) &
               (SYSCTL_RCC_USEPWMDIV | SYSCTL_RCC_PWMDIV_M));
    }
}

//*****************************************************************************
//
//! Sets the sample rate of the ADC.
//!
//! \param ulSpeed is the desired sample rate of the ADC; must be one of
//! \b SYSCTL_ADCSPEED_1MSPS, \b SYSCTL_ADCSPEED_500KSPS,
//! \b SYSCTL_ADCSPEED_250KSPS, or \b SYSCTL_ADCSPEED_125KSPS.
//!
//! This function configures the rate at which the ADC samples are captured by
//! the ADC block.  The sampling speed may be limited by the hardware, so the
//! sample rate may end up being slower than requested.  SysCtlADCSpeedGet()
//! returns the actual speed in use.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlADCSpeedSet(unsigned long ulSpeed)
{
    //
    // Check the arguments.
    //
    ASSERT((ulSpeed == SYSCTL_ADCSPEED_1MSPS) ||
           (ulSpeed == SYSCTL_ADCSPEED_500KSPS) ||
           (ulSpeed == SYSCTL_ADCSPEED_250KSPS) ||
           (ulSpeed == SYSCTL_ADCSPEED_125KSPS));

    //
    // Set the ADC speed in run and sleep mode.
    //
    HWREG(SYSCTL_RCGC0) = ((HWREG(SYSCTL_RCGC0) & ~(SYSCTL_RCGC0_ADCSPD_M)) |
                           ulSpeed);
    HWREG(SYSCTL_SCGC0) = ((HWREG(SYSCTL_SCGC0) & ~(SYSCTL_SCGC0_ADCSPD_M)) |
                           ulSpeed);
}

//*****************************************************************************
//
//! Gets the sample rate of the ADC.
//!
//! This function gets the current sample rate of the ADC.
//!
//! \return Returns the current ADC sample rate; is one of
//! \b SYSCTL_ADCSPEED_1MSPS, \b SYSCTL_ADCSPEED_500KSPS,
//! \b SYSCTL_ADCSPEED_250KSPS, or \b SYSCTL_ADCSPEED_125KSPS.
//
//*****************************************************************************
unsigned long
SysCtlADCSpeedGet(void)
{
    //
    // Return the current ADC speed.
    //
    return(HWREG(SYSCTL_RCGC0) & SYSCTL_RCGC0_ADCSPD_M);
}

//*****************************************************************************
//
//! Configures the internal oscillator verification timer.
//!
//! \param bEnable is a boolean that is \b true if the internal oscillator
//! verification timer should be enabled.
//!
//! This function allows the internal oscillator verification timer to be
//! enabled or disabled.  When enabled, an interrupt is generated if the
//! internal oscillator ceases to operate.
//!
//! The internal oscillator verification timer is only available on
//! Sandstorm-class devices.
//!
//! \note Both oscillators (main and internal) must be enabled for this
//! verification timer to operate as the main oscillator verifies the
//! internal oscillator.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlIOSCVerificationSet(tBoolean bEnable)
{
    //
    // Enable or disable the internal oscillator verification timer as
    // requested.
    //
    if(bEnable)
    {
        HWREG(SYSCTL_RCC) |= SYSCTL_RCC_IOSCVER;
    }
    else
    {
        HWREG(SYSCTL_RCC) &= ~(SYSCTL_RCC_IOSCVER);
    }
}

//*****************************************************************************
//
//! Configures the main oscillator verification timer.
//!
//! \param bEnable is a boolean that is \b true if the main oscillator
//! verification timer should be enabled.
//!
//! This function allows the main oscillator verification timer to be enabled
//! or disabled.  When enabled, an interrupt is generated if the main
//! oscillator ceases to operate.
//!
//! The main oscillator verification timer is only available on
//! Sandstorm-class devices.
//!
//! \note Both oscillators (main and internal) must be enabled for this
//! verification timer to operate as the internal oscillator verifies the
//! main oscillator.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlMOSCVerificationSet(tBoolean bEnable)
{
    //
    // Enable or disable the main oscillator verification timer as requested.
    //
    if(bEnable)
    {
        HWREG(SYSCTL_RCC) |= SYSCTL_RCC_MOSCVER;
    }
    else
    {
        HWREG(SYSCTL_RCC) &= ~(SYSCTL_RCC_MOSCVER);
    }
}

//*****************************************************************************
//
//! Configures the PLL verification timer.
//!
//! \param bEnable is a boolean that is \b true if the PLL verification timer
//! should be enabled.
//!
//! This function allows the PLL verification timer to be enabled or disabled.
//! When enabled, an interrupt is generated if the PLL ceases to operate.
//!
//! The PLL verification timer is only available on Sandstorm-class devices.
//!
//! \note The main oscillator must be enabled for this verification timer to
//! operate as it is used to check the PLL.  Also, the verification timer
//! should be disabled while the PLL is being reconfigured via
//! SysCtlClockSet().
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlPLLVerificationSet(tBoolean bEnable)
{
    //
    // Enable or disable the PLL verification timer as requested.
    //
    if(bEnable)
    {
        HWREG(SYSCTL_RCC) |= SYSCTL_RCC_PLLVER;
    }
    else
    {
        HWREG(SYSCTL_RCC) &= ~(SYSCTL_RCC_PLLVER);
    }
}

//*****************************************************************************
//
//! Clears the clock verification status.
//!
//! This function clears the status of the clock verification timers, allowing
//! them to assert another failure if detected.
//!
//! The clock verification timers are only available on Sandstorm-class
//! devices.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlClkVerificationClear(void)
{
    //
    // Clear the clock verification.
    //
    HWREG(SYSCTL_CLKVCLR) = SYSCTL_CLKVCLR_VERCLR;

    //
    // The bit does not self-reset, so clear it.
    //
    HWREG(SYSCTL_CLKVCLR) = 0;
}

//*****************************************************************************
//
//! Enables a GPIO peripheral for access from the AHB.
//!
//! \param ulGPIOPeripheral is the GPIO peripheral to enable.
//!
//! This function is used to enable the specified GPIO peripheral to be
//! accessed from the Advanced Host Bus (AHB) instead of the legacy Advanced
//! Peripheral Bus (APB).  When a GPIO peripheral is enabled for AHB access,
//! the \b _AHB_BASE form of the base address should be used for GPIO
//! functions.  For example, instead of using \b GPIO_PORTA_BASE as the base
//! address for GPIO functions, use \b GPIO_PORTA_AHB_BASE instead.
//!
//! The \e ulGPIOPeripheral argument must be only one of the following values:
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, or \b SYSCTL_PERIPH_GPIOJ.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlGPIOAHBEnable(unsigned long ulGPIOPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT((ulGPIOPeripheral == SYSCTL_PERIPH_GPIOA) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOB) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOC) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOD) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOE) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOF) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOG) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOH) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOJ));

    //
    // Enable this GPIO for AHB access.
    //
    HWREG(SYSCTL_GPIOHBCTL) |= ulGPIOPeripheral & 0xFFFF;
}

//*****************************************************************************
//
//! Disables a GPIO peripheral for access from the AHB.
//!
//! \param ulGPIOPeripheral is the GPIO peripheral to disable.
//!
//! This function disables the specified GPIO peripheral for access from the
//! Advanced Host Bus (AHB).  Once disabled, the GPIO peripheral is accessed
//! from the legacy Advanced Peripheral Bus (APB).
//!
//! The \b ulGPIOPeripheral argument must be only one of the following values:
//! \b SYSCTL_PERIPH_GPIOA, \b SYSCTL_PERIPH_GPIOB, \b SYSCTL_PERIPH_GPIOC,
//! \b SYSCTL_PERIPH_GPIOD, \b SYSCTL_PERIPH_GPIOE, \b SYSCTL_PERIPH_GPIOF,
//! \b SYSCTL_PERIPH_GPIOG, \b SYSCTL_PERIPH_GPIOH, or \b SYSCTL_PERIPH_GPIOJ.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlGPIOAHBDisable(unsigned long ulGPIOPeripheral)
{
    //
    // Check the arguments.
    //
    ASSERT((ulGPIOPeripheral == SYSCTL_PERIPH_GPIOA) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOB) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOC) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOD) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOE) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOF) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOG) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOH) ||
           (ulGPIOPeripheral == SYSCTL_PERIPH_GPIOJ));

    //
    // Disable this GPIO for AHB access.
    //
    HWREG(SYSCTL_GPIOHBCTL) &= ~(ulGPIOPeripheral & 0xFFFF);
}

//*****************************************************************************
//
//! Powers up the USB PLL.
//!
//! This function enables the USB controller's PLL, which is used by it's
//! physical layer.  This call is necessary before connecting to any external
//! devices.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlUSBPLLEnable(void)
{
    //
    // Turn on the USB PLL.
    //
    HWREG(SYSCTL_RCC2) &= ~SYSCTL_RCC2_USBPWRDN;
}

//*****************************************************************************
//
//! Powers down the USB PLL.
//!
//! This function disables the USB controller's PLL, which is used by it's
//! physical layer.  The USB registers are still accessible, but the physical
//! layer no longer functions.
//!
//! \return None.
//
//*****************************************************************************
void
SysCtlUSBPLLDisable(void)
{
    //
    // Turn off the USB PLL.
    //
    HWREG(SYSCTL_RCC2) |= SYSCTL_RCC2_USBPWRDN;
}

//*****************************************************************************
//
//! Sets the MCLK frequency provided to the I2S module.
//!
//! \param ulInputClock is the input clock to the MCLK divider.  If this value
//! is zero, the value is computed from the current PLL configuration.
//! \param ulMClk is the desired MCLK frequency.  If this value is zero, MCLK
//! output is disabled.
//!
//! This function configures the dividers to provide MCLK to the I2S module.  A
//! MCLK divider is chosen that produces the MCLK frequency that is the closest
//! possible to the requested frequency, which may be above or below the
//! requested frequency.
//!
//! The actual MCLK frequency is returned.  It is the responsibility of the
//! application to determine if the selected MCLK is acceptable; in general the
//! human ear can not discern the frequency difference if it is within 0.3% of
//! the desired frequency (although there is a very small percentage of the
//! population that can discern lower frequency deviations).
//!
//! \return Returns the actual MCLK frequency.
//
//*****************************************************************************
unsigned long
SysCtlI2SMClkSet(unsigned long ulInputClock, unsigned long ulMClk)
{
    unsigned long ulDivInt, ulDivFrac, ulPLL;

    //
    // See if the I2S MCLK should be disabled.
    //
    if(ulMClk == 0)
    {
        //
        // Disable the I2S MCLK and return.
        //
        HWREG(SYSCTL_I2SMCLKCFG) = 0;
        return(0);
    }

    //
    // See if the input clock was specified.
    //
    if(ulInputClock == 0)
    {
        //
        // The input clock was not specified, so compute the output frequency
        // of the PLL.  Get the current PLL configuration.
        //
        ulPLL = HWREG(SYSCTL_PLLCFG);

        //
        // Get the frequency of the crystal in use.
        //
        ulInputClock = g_pulXtals[(HWREG(SYSCTL_RCC) & SYSCTL_RCC_XTAL_M) >>
                                  SYSCTL_RCC_XTAL_S];

        //
        // Calculate the PLL output frequency.
        //
        ulInputClock = ((ulInputClock * ((ulPLL & SYSCTL_PLLCFG_F_M) >>
                                         SYSCTL_PLLCFG_F_S)) /
                        ((((ulPLL & SYSCTL_PLLCFG_R_M) >>
                           SYSCTL_PLLCFG_R_S) + 1)));

        //
        // See if the optional output divide by 2 is being used.
        //
        if(ulPLL & SYSCTL_PLLCFG_OD_2)
        {
            ulInputClock /= 2;
        }

        //
        // See if the optional output divide by 4 is being used.
        //
        if(ulPLL & SYSCTL_PLLCFG_OD_4)
        {
            ulInputClock /= 4;
        }
    }

    //
    // Verify that the requested MCLK frequency is attainable.
    //
    ASSERT(ulMClk < ulInputClock);

    //
    // Add a rounding factor to the input clock, so that the MCLK frequency
    // that is closest to the desire value is selected.
    //
    ulInputClock += (ulMClk / 32) - 1;

    //
    // Compute the integer portion of the MCLK divider.
    //
    ulDivInt = ulInputClock / ulMClk;

    //
    // If the divisor is too large, then simply use the maximum divisor.
    //
    if(CLASS_IS_TEMPEST && REVISION_IS_B1 && (ulDivInt > 255))
    {
        ulDivInt = 255;
        ulDivFrac = 15;
    }
    else if(ulDivInt > 1023)
    {
        ulDivInt = 1023;
        ulDivFrac = 15;
    }
    else
    {
        //
        // Compute the fractional portion of the MCLK divider.
        //
        ulDivFrac = ((ulInputClock - (ulDivInt * ulMClk)) * 16) / ulMClk;
    }

    //
    // Set the divisor for the TX and RX MCLK generators and enable the clocks.
    //
    HWREG(SYSCTL_I2SMCLKCFG) = (SYSCTL_I2SMCLKCFG_RXEN |
                                (ulDivInt << SYSCTL_I2SMCLKCFG_RXI_S) |
                                (ulDivFrac << SYSCTL_I2SMCLKCFG_RXF_S) |
                                SYSCTL_I2SMCLKCFG_TXEN |
                                (ulDivInt << SYSCTL_I2SMCLKCFG_TXI_S) |
                                (ulDivFrac << SYSCTL_I2SMCLKCFG_TXF_S));

    //
    // Return the actual MCLK frequency.
    //
    ulInputClock -= (ulMClk / 32) - 1;
    ulDivInt = (ulDivInt * 16) + ulDivFrac;
    ulMClk = (ulInputClock / ulDivInt) * 16;
    ulMClk += ((ulInputClock - ((ulMClk / 16) * ulDivInt)) * 16) / ulDivInt;
    return(ulMClk);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
