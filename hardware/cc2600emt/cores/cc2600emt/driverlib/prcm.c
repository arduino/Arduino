/******************************************************************************
*  Filename:       prcm.c
*  Revised:        2015-09-09 11:55:59 +0200 (Wed, 09 Sep 2015)
*  Revision:       44536
*
*  Description:    Driver for the PRCM.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#include <driverlib/prcm.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #undef  PRCMInfClockConfigureSet
    #define PRCMInfClockConfigureSet        NOROM_PRCMInfClockConfigureSet
    #undef  PRCMInfClockConfigureGet
    #define PRCMInfClockConfigureGet        NOROM_PRCMInfClockConfigureGet
    #undef  PRCMAudioClockConfigSet
    #define PRCMAudioClockConfigSet         NOROM_PRCMAudioClockConfigSet
    #undef  PRCMAudioClockConfigSetOverride
    #define PRCMAudioClockConfigSetOverride NOROM_PRCMAudioClockConfigSetOverride
    #undef  PRCMPowerDomainOn
    #define PRCMPowerDomainOn               NOROM_PRCMPowerDomainOn
    #undef  PRCMPowerDomainOff
    #define PRCMPowerDomainOff              NOROM_PRCMPowerDomainOff
    #undef  PRCMPeripheralRunEnable
    #define PRCMPeripheralRunEnable         NOROM_PRCMPeripheralRunEnable
    #undef  PRCMPeripheralRunDisable
    #define PRCMPeripheralRunDisable        NOROM_PRCMPeripheralRunDisable
    #undef  PRCMPeripheralSleepEnable
    #define PRCMPeripheralSleepEnable       NOROM_PRCMPeripheralSleepEnable
    #undef  PRCMPeripheralSleepDisable
    #define PRCMPeripheralSleepDisable      NOROM_PRCMPeripheralSleepDisable
    #undef  PRCMPeripheralDeepSleepEnable
    #define PRCMPeripheralDeepSleepEnable   NOROM_PRCMPeripheralDeepSleepEnable
    #undef  PRCMPeripheralDeepSleepDisable
    #define PRCMPeripheralDeepSleepDisable  NOROM_PRCMPeripheralDeepSleepDisable
    #undef  PRCMPowerDomainStatus
    #define PRCMPowerDomainStatus           NOROM_PRCMPowerDomainStatus
    #undef  PRCMDeepSleep
    #define PRCMDeepSleep                   NOROM_PRCMDeepSleep
#endif


//*****************************************************************************
//
// Arrays that maps the "peripheral set" number (which is stored in the
// third nibble of the PRCM_PERIPH_* defines) to the PRCM register that
// contains the relevant bit for that peripheral.
//
//*****************************************************************************

// Run mode registers
static const uint32_t g_pui32RCGCRegs[] =
{
    PRCM_O_GPTCLKGR,
    PRCM_O_SSICLKGR,
    PRCM_O_UARTCLKGR,
    PRCM_O_I2CCLKGR,
    PRCM_O_SECDMACLKGR,
    PRCM_O_GPIOCLKGR,
    PRCM_O_I2SCLKGR
};

// Sleep mode registers
static const uint32_t g_pui32SCGCRegs[] =
{
    PRCM_O_GPTCLKGS,
    PRCM_O_SSICLKGS,
    PRCM_O_UARTCLKGS,
    PRCM_O_I2CCLKGS,
    PRCM_O_SECDMACLKGS,
    PRCM_O_GPIOCLKGS,
    PRCM_O_I2SCLKGS
};

// Deep sleep mode registers
static const uint32_t g_pui32DCGCRegs[] =
{
    PRCM_O_GPTCLKGDS,
    PRCM_O_SSICLKGDS,
    PRCM_O_UARTCLKGDS,
    PRCM_O_I2CCLKGDS,
    PRCM_O_SECDMACLKGDS,
    PRCM_O_GPIOCLKGDS,
    PRCM_O_I2SCLKGDS
};

//*****************************************************************************
//
// This macro extracts the array index out of the peripheral number
//
//*****************************************************************************
#define PRCM_PERIPH_INDEX(a)  (((a) >> 8) & 0xf)

//*****************************************************************************
//
// This macro extracts the peripheral instance number and generates bit mask
//
//*****************************************************************************
#define PRCM_PERIPH_MASKBIT(a) (0x00000001 << ((a) & 0xf))


//*****************************************************************************
//
//! Configure the infrastructure clock.
//
//*****************************************************************************
void
PRCMInfClockConfigureSet(uint32_t ui32ClkDiv, uint32_t ui32PowerMode)
{
    uint32_t ui32Divisor;

    //
    // Check the arguments.
    //
    ASSERT((ui32ClkDiv == PRCM_CLOCK_DIV_1) ||
           (ui32ClkDiv == PRCM_CLOCK_DIV_2) ||
           (ui32ClkDiv == PRCM_CLOCK_DIV_8) ||
           (ui32ClkDiv == PRCM_CLOCK_DIV_32));
    ASSERT((ui32PowerMode == PRCM_RUN_MODE) ||
           (ui32PowerMode == PRCM_SLEEP_MODE) ||
           (ui32PowerMode == PRCM_DEEP_SLEEP_MODE));

    ui32Divisor = 0;

    //
    // Find the correct division factor.
    //
    if(ui32ClkDiv == PRCM_CLOCK_DIV_1)
    {
        ui32Divisor = 0x0;
    }
    else if(ui32ClkDiv == PRCM_CLOCK_DIV_2)
    {
        ui32Divisor = 0x1;
    }
    else if(ui32ClkDiv == PRCM_CLOCK_DIV_8)
    {
        ui32Divisor = 0x2;
    }
    else if(ui32ClkDiv == PRCM_CLOCK_DIV_32)
    {
        ui32Divisor = 0x3;
    }

    //
    // Determine the correct power mode set the division factor accordingly.
    //
    if(ui32PowerMode == PRCM_RUN_MODE)
    {
        HWREG(PRCM_BASE + PRCM_O_INFRCLKDIVR) = ui32Divisor;
    }
    else if(ui32PowerMode == PRCM_SLEEP_MODE)
    {
        HWREG(PRCM_BASE + PRCM_O_INFRCLKDIVS) = ui32Divisor;
    }
    else if(ui32PowerMode == PRCM_DEEP_SLEEP_MODE)
    {
        HWREG(PRCM_BASE + PRCM_O_INFRCLKDIVDS) = ui32Divisor;
    }
}

//*****************************************************************************
//
//! Use this function to get the infrastructure clock configuration
//
//*****************************************************************************
uint32_t
PRCMInfClockConfigureGet(uint32_t ui32PowerMode)
{
    uint32_t ui32ClkDiv;
    uint32_t ui32Divisor;

    //
    // Check the arguments.
    //
    ASSERT((ui32PowerMode == PRCM_RUN_MODE) ||
           (ui32PowerMode == PRCM_SLEEP_MODE) ||
           (ui32PowerMode == PRCM_DEEP_SLEEP_MODE));

    ui32ClkDiv = 0;
    ui32Divisor = 0;

    //
    // Determine the correct power mode.
    //
    if(ui32PowerMode == PRCM_RUN_MODE)
    {
        ui32ClkDiv = HWREG(PRCM_BASE + PRCM_O_INFRCLKDIVR);
    }
    else if(ui32PowerMode == PRCM_SLEEP_MODE)
    {
        ui32ClkDiv = HWREG(PRCM_BASE + PRCM_O_INFRCLKDIVS);
    }
    else if(ui32PowerMode == PRCM_DEEP_SLEEP_MODE)
    {
        ui32ClkDiv = HWREG(PRCM_BASE + PRCM_O_INFRCLKDIVDS);
    }

    //
    // Find the correct division factor.
    //
    if(ui32ClkDiv == 0x0)
    {
        ui32Divisor = PRCM_CLOCK_DIV_1;
    }
    else if(ui32ClkDiv == 0x1)
    {
        ui32Divisor = PRCM_CLOCK_DIV_2;
    }
    else if(ui32ClkDiv == 0x2)
    {
        ui32Divisor = PRCM_CLOCK_DIV_8;
    }
    else if(ui32ClkDiv == 0x3)
    {
        ui32Divisor = PRCM_CLOCK_DIV_32;
    }

    //
    // Return the clock division factor.
    //
    return ui32Divisor;
}


//*****************************************************************************
//
//! Configure the audio clock generation
//
//*****************************************************************************
void
PRCMAudioClockConfigSet(uint32_t ui32ClkConfig, uint32_t ui32SampleRate)
{
    uint32_t ui32Reg;
    uint32_t ui32MstDiv;
    uint32_t ui32BitDiv;
    uint32_t ui32WordDiv;

    //
    // Check the arguments.
    //
    ASSERT(!(ui32ClkConfig & (PRCM_I2SCLKCTL_WCLK_PHASE_M | PRCM_I2SCLKCTL_SMPL_ON_POSEDGE_M)));
    ASSERT((ui32SampleRate == I2S_SAMPLE_RATE_16K) ||
           (ui32SampleRate == I2S_SAMPLE_RATE_24K) ||
           (ui32SampleRate == I2S_SAMPLE_RATE_32K) ||
           (ui32SampleRate == I2S_SAMPLE_RATE_48K));

    ui32MstDiv = 0;
    ui32BitDiv = 0;
    ui32WordDiv = 0;

    //
    // Make sure the audio clock generation is disabled before reconfiguring.
    //
    PRCMAudioClockDisable();

    //
    // Define the clock division factors for the audio interface.
    //
    switch(ui32SampleRate)
    {
    case I2S_SAMPLE_RATE_16K :
        ui32MstDiv = 6;
        ui32BitDiv = 60;
        ui32WordDiv = 25;
        break;
    case I2S_SAMPLE_RATE_24K :
        ui32MstDiv = 4;
        ui32BitDiv = 40;
        ui32WordDiv = 25;
        break;
    case I2S_SAMPLE_RATE_32K :
        ui32MstDiv = 3;
        ui32BitDiv = 30;
        ui32WordDiv = 25;
        break;
    case I2S_SAMPLE_RATE_48K :
        ui32MstDiv = 2;
        ui32BitDiv = 20;
        ui32WordDiv = 25;
        break;
    }

    //
    // Make sure to compensate the Frame clock division factor if using single
    // phase format.
    //
    if((ui32ClkConfig & PRCM_I2SCLKCTL_WCLK_PHASE_M) == PRCM_WCLK_SINGLE_PHASE)
    {
        ui32WordDiv -= 1;
    }

    //
    // Write the clock division factors.
    //
    HWREG(PRCM_BASE + PRCM_O_I2SMCLKDIV) = ui32MstDiv;
    HWREG(PRCM_BASE + PRCM_O_I2SBCLKDIV) = ui32BitDiv;
    HWREG(PRCM_BASE + PRCM_O_I2SWCLKDIV) = ui32WordDiv;

    //
    // Configure the Word clock format and polarity.
    //
    ui32Reg = HWREG(PRCM_BASE + PRCM_O_I2SCLKCTL) & ~(PRCM_I2SCLKCTL_WCLK_PHASE_M |
              PRCM_I2SCLKCTL_SMPL_ON_POSEDGE_M);
    HWREG(PRCM_BASE + PRCM_O_I2SCLKCTL) = ui32Reg | ui32ClkConfig;
}

//*****************************************************************************
//
//! Configure the audio clock generation with manual setting of clock divider.
//
//*****************************************************************************
void
PRCMAudioClockConfigSetOverride(uint32_t ui32ClkConfig, uint32_t ui32MstDiv,
                        uint32_t ui32BitDiv, uint32_t ui32WordDiv)
{
    uint32_t ui32Reg;

    //
    // Check the arguments.
    //
    ASSERT(!(ui32ClkConfig & (PRCM_I2SCLKCTL_WCLK_PHASE_M | PRCM_I2SCLKCTL_SMPL_ON_POSEDGE_M)));

    //
    // Make sure the audio clock generation is disabled before reconfiguring.
    //
    PRCMAudioClockDisable();

    //
    // Make sure to compensate the Frame clock division factor if using single
    // phase format.
    //
    if((ui32ClkConfig & PRCM_I2SCLKCTL_WCLK_PHASE_M) == PRCM_WCLK_SINGLE_PHASE)
    {
        ui32WordDiv -= 1;
    }

    //
    // Write the clock division factors.
    //
    HWREG(PRCM_BASE + PRCM_O_I2SMCLKDIV) = ui32MstDiv;
    HWREG(PRCM_BASE + PRCM_O_I2SBCLKDIV) = ui32BitDiv;
    HWREG(PRCM_BASE + PRCM_O_I2SWCLKDIV) = ui32WordDiv;

    //
    // Configure the Word clock format and polarity.
    //
    ui32Reg = HWREG(PRCM_BASE + PRCM_O_I2SCLKCTL) & ~(PRCM_I2SCLKCTL_WCLK_PHASE_M |
              PRCM_I2SCLKCTL_SMPL_ON_POSEDGE_M);
    HWREG(PRCM_BASE + PRCM_O_I2SCLKCTL) = ui32Reg | ui32ClkConfig;
}

//*****************************************************************************
//
//! Turn power on in power domains in the MCU domain
//
//*****************************************************************************
void
PRCMPowerDomainOn(uint32_t ui32Domains)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Domains & PRCM_DOMAIN_RFCORE) ||
           (ui32Domains & PRCM_DOMAIN_SERIAL) ||
           (ui32Domains & PRCM_DOMAIN_PERIPH) ||
           (ui32Domains & PRCM_DOMAIN_CPU) ||
           (ui32Domains & PRCM_DOMAIN_VIMS));

    //
    // Assert the request to power on the right domains.
    //
    if(ui32Domains & PRCM_DOMAIN_RFCORE)
    {
        HWREG(PRCM_BASE +
              PRCM_O_PDCTL0RFC) |= PRCM_PDCTL0RFC_ON;
        HWREG(PRCM_BASE + PRCM_O_PDCTL1RFC) |= PRCM_PDCTL1RFC_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_SERIAL)
    {
        HWREG(PRCM_BASE +
              PRCM_O_PDCTL0SERIAL) |= PRCM_PDCTL0SERIAL_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_PERIPH)
    {
        HWREG(PRCM_BASE +
              PRCM_O_PDCTL0PERIPH) |= PRCM_PDCTL0PERIPH_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_VIMS)
    {
        HWREG(PRCM_BASE + PRCM_O_PDCTL1VIMS) |=
            PRCM_PDCTL1VIMS_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_CPU)
    {
        HWREG(PRCM_BASE + PRCM_O_PDCTL1CPU) |= PRCM_PDCTL1CPU_ON;
    }
}

//*****************************************************************************
//
//! Turn off a specific power domain
//
//*****************************************************************************
void
PRCMPowerDomainOff(uint32_t ui32Domains)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Domains & PRCM_DOMAIN_RFCORE) ||
           (ui32Domains & PRCM_DOMAIN_SERIAL) ||
           (ui32Domains & PRCM_DOMAIN_PERIPH) ||
           (ui32Domains & PRCM_DOMAIN_CPU) ||
           (ui32Domains & PRCM_DOMAIN_VIMS));

    //
    // Assert the request to power off the right domains.
    //
    if(ui32Domains & PRCM_DOMAIN_RFCORE)
    {
        HWREG(PRCM_BASE +
              PRCM_O_PDCTL0RFC) &= ~PRCM_PDCTL0RFC_ON;
        HWREG(PRCM_BASE + PRCM_O_PDCTL1RFC) &= ~PRCM_PDCTL1RFC_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_SERIAL)
    {
        HWREG(PRCM_BASE +
              PRCM_O_PDCTL0SERIAL) &= ~PRCM_PDCTL0SERIAL_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_PERIPH)
    {
        HWREG(PRCM_BASE +
              PRCM_O_PDCTL0PERIPH) &= ~PRCM_PDCTL0PERIPH_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_VIMS)
    {
        HWREG(PRCM_BASE + PRCM_O_PDCTL1VIMS) &=
            ~PRCM_PDCTL1VIMS_ON;
    }
    if(ui32Domains & PRCM_DOMAIN_CPU)
    {
        HWREG(PRCM_BASE + PRCM_O_PDCTL1CPU) &= ~PRCM_PDCTL1CPU_ON;
    }
}

//*****************************************************************************
//
//! Enables a peripheral in Run mode
//
//*****************************************************************************
void
PRCMPeripheralRunEnable(uint32_t ui32Peripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(PRCMPeripheralValid(ui32Peripheral));

    //
    // Enable module in Run Mode.
    //
    HWREG(PRCM_BASE + g_pui32RCGCRegs[PRCM_PERIPH_INDEX(ui32Peripheral)]) |=
        PRCM_PERIPH_MASKBIT(ui32Peripheral);
}

//*****************************************************************************
//
//! Disables a peripheral in Run mode
//
//*****************************************************************************
void
PRCMPeripheralRunDisable(uint32_t ui32Peripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(PRCMPeripheralValid(ui32Peripheral));

    //
    // Disable module in Run Mode.
    //
    HWREG(PRCM_BASE + g_pui32RCGCRegs[PRCM_PERIPH_INDEX(ui32Peripheral)]) &=
        ~PRCM_PERIPH_MASKBIT(ui32Peripheral);
}

//*****************************************************************************
//
//! Enables a peripheral in sleep mode
//
//*****************************************************************************
void
PRCMPeripheralSleepEnable(uint32_t ui32Peripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(PRCMPeripheralValid(ui32Peripheral));

    //
    // Enable this peripheral in sleep mode.
    //
    HWREG(PRCM_BASE + g_pui32SCGCRegs[PRCM_PERIPH_INDEX(ui32Peripheral)]) |=
        PRCM_PERIPH_MASKBIT(ui32Peripheral);
}

//*****************************************************************************
//
//! Disables a peripheral in sleep mode
//
//*****************************************************************************
void
PRCMPeripheralSleepDisable(uint32_t ui32Peripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(PRCMPeripheralValid(ui32Peripheral));

    //
    // Disable this peripheral in sleep mode
    //
    HWREG(PRCM_BASE + g_pui32SCGCRegs[PRCM_PERIPH_INDEX(ui32Peripheral)]) &=
        ~PRCM_PERIPH_MASKBIT(ui32Peripheral);
}

//*****************************************************************************
//
//! Enables a peripheral in deep-sleep mode
//
//*****************************************************************************
void
PRCMPeripheralDeepSleepEnable(uint32_t ui32Peripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(PRCMPeripheralValid(ui32Peripheral));

    //
    // Enable this peripheral in deep-sleep mode.
    //
    HWREG(PRCM_BASE + g_pui32DCGCRegs[PRCM_PERIPH_INDEX(ui32Peripheral)]) |=
        PRCM_PERIPH_MASKBIT(ui32Peripheral);
}

//*****************************************************************************
//
//! Disables a peripheral in deep-sleep mode
//
//*****************************************************************************
void
PRCMPeripheralDeepSleepDisable(uint32_t ui32Peripheral)
{
    //
    // Check the arguments.
    //
    ASSERT(PRCMPeripheralValid(ui32Peripheral));

    //
    // Disable this peripheral in Deep Sleep mode.
    //
    HWREG(PRCM_BASE + g_pui32DCGCRegs[PRCM_PERIPH_INDEX(ui32Peripheral)]) &=
        ~PRCM_PERIPH_MASKBIT(ui32Peripheral);
}

//*****************************************************************************
//
//! Get the status for a specific power domain
//
//*****************************************************************************
uint32_t
PRCMPowerDomainStatus(uint32_t ui32Domains)
{
    bool bStatus;
    uint32_t ui32StatusRegister0;
    uint32_t ui32StatusRegister1;

    //
    // Check the arguments.
    //
    ASSERT((ui32Domains & (PRCM_DOMAIN_RFCORE |
                           PRCM_DOMAIN_SERIAL |
                           PRCM_DOMAIN_PERIPH)));

    bStatus = true;
    ui32StatusRegister0 = HWREG(PRCM_BASE + PRCM_O_PDSTAT0);
    ui32StatusRegister1 = HWREG(PRCM_BASE + PRCM_O_PDSTAT1);

    //
    // Return the correct power status.
    //
    if(ui32Domains & PRCM_DOMAIN_RFCORE)
    {
       bStatus = bStatus &&
                 ((ui32StatusRegister0 & PRCM_PDSTAT0_RFC_ON) ||
                  (ui32StatusRegister1 & PRCM_PDSTAT1_RFC_ON));
    }
    if(ui32Domains & PRCM_DOMAIN_SERIAL)
    {
        bStatus = bStatus && (ui32StatusRegister0 & PRCM_PDSTAT0_SERIAL_ON);
    }
    if(ui32Domains & PRCM_DOMAIN_PERIPH)
    {
        bStatus = bStatus && (ui32StatusRegister0 & PRCM_PDSTAT0_PERIPH_ON);
    }

    //
    // Return the status.
    //
    return (bStatus ? PRCM_DOMAIN_POWER_ON : PRCM_DOMAIN_POWER_OFF);
}

//*****************************************************************************
//
//! Put the processor into deep-sleep mode
//
//*****************************************************************************
void
PRCMDeepSleep(void)
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
    // Disable deep-sleep so that a future sleep will work correctly.
    //
    HWREG(NVIC_SYS_CTRL) &= ~(NVIC_SYS_CTRL_SLEEPDEEP);
}
