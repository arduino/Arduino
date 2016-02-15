/******************************************************************************
*  Filename:       aux_wuc.c
*  Revised:        2015-06-01 15:19:54 +0200 (Mon, 01 Jun 2015)
*  Revision:       43689
*
*  Description:    Driver for the AUX Wakeup Controller.
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

#include <driverlib/aux_wuc.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #undef  AUXWUCClockEnable
    #define AUXWUCClockEnable               NOROM_AUXWUCClockEnable
    #undef  AUXWUCClockDisable
    #define AUXWUCClockDisable              NOROM_AUXWUCClockDisable
    #undef  AUXWUCClockStatus
    #define AUXWUCClockStatus               NOROM_AUXWUCClockStatus
    #undef  AUXWUCPowerCtrl
    #define AUXWUCPowerCtrl                 NOROM_AUXWUCPowerCtrl
#endif

//****************************************************************************
//
//! Enable clocks for peripherals in the AUX domain
//
//****************************************************************************
void
AUXWUCClockEnable(uint32_t ui32Clocks)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Clocks & AUX_WUC_ADI_CLOCK) ||
           (ui32Clocks & AUX_WUC_OSCCTRL_CLOCK) ||
           (ui32Clocks & AUX_WUC_TDCIF_CLOCK) ||
           (ui32Clocks & AUX_WUC_ANAIF_CLOCK) ||
           (ui32Clocks & AUX_WUC_TIMER_CLOCK) ||
           (ui32Clocks & AUX_WUC_AIODIO0_CLOCK) ||
           (ui32Clocks & AUX_WUC_AIODIO1_CLOCK) ||
           (ui32Clocks & AUX_WUC_SMPH_CLOCK) ||
           (ui32Clocks & AUX_WUC_TDC_CLOCK) ||
           (ui32Clocks & AUX_WUC_ADC_CLOCK) ||
           (ui32Clocks & AUX_WUC_REF_CLOCK));

    //
    // Enable some of the clocks in the clock register.
    //
    HWREG(AUX_WUC_BASE + AUX_WUC_O_MODCLKEN0) |= (ui32Clocks &
                                                AUX_WUC_MODCLK_MASK);

    //
    // Check the rest.
    //
    if(ui32Clocks & AUX_WUC_ADC_CLOCK)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_ADCCLKCTL) =
            AUX_WUC_ADCCLKCTL_REQ;
    }
    if(ui32Clocks & AUX_WUC_TDC_CLOCK)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_TDCCLKCTL) =
            AUX_WUC_TDCCLKCTL_REQ;
    }
    if(ui32Clocks & AUX_WUC_REF_CLOCK)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_REFCLKCTL) =
            AUX_WUC_REFCLKCTL_REQ;
    }
}

//****************************************************************************
//
//! Disable clocks for peripherals in the AUX domain
//
//****************************************************************************
void
AUXWUCClockDisable(uint32_t ui32Clocks)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Clocks & AUX_WUC_ADI_CLOCK) ||
           (ui32Clocks & AUX_WUC_OSCCTRL_CLOCK) ||
           (ui32Clocks & AUX_WUC_TDCIF_CLOCK) ||
           (ui32Clocks & AUX_WUC_ANAIF_CLOCK) ||
           (ui32Clocks & AUX_WUC_TIMER_CLOCK) ||
           (ui32Clocks & AUX_WUC_AIODIO0_CLOCK) ||
           (ui32Clocks & AUX_WUC_AIODIO1_CLOCK) ||
           (ui32Clocks & AUX_WUC_SMPH_CLOCK) ||
           (ui32Clocks & AUX_WUC_TDC_CLOCK) ||
           (ui32Clocks & AUX_WUC_ADC_CLOCK) ||
           (ui32Clocks & AUX_WUC_REF_CLOCK));

    //
    // Disable some of the clocks in the clock register.
    //
    HWREG(AUX_WUC_BASE + AUX_WUC_O_MODCLKEN0) &= ~(ui32Clocks &
            AUX_WUC_MODCLK_MASK);

    //
    // Check the rest.
    //
    if(ui32Clocks & AUX_WUC_ADC_CLOCK)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_ADCCLKCTL) &=
            ~AUX_WUC_ADCCLKCTL_REQ;
    }
    if(ui32Clocks & AUX_WUC_TDC_CLOCK)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_TDCCLKCTL) &=
            ~AUX_WUC_TDCCLKCTL_REQ;
    }
    if(ui32Clocks & AUX_WUC_REF_CLOCK)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_REFCLKCTL) &=
            ~AUX_WUC_REFCLKCTL_REQ;
    }
}

//****************************************************************************
//
//! Get the status of a clock
//
//****************************************************************************
uint32_t
AUXWUCClockStatus(uint32_t ui32Clocks)
{
    bool bClockStatus;
    uint32_t ui32ClockRegister;

    //
    // Check the arguments.
    //
    ASSERT((ui32Clocks & AUX_WUC_ADI_CLOCK) ||
           (ui32Clocks & AUX_WUC_OSCCTRL_CLOCK) ||
           (ui32Clocks & AUX_WUC_TDCIF_CLOCK) ||
           (ui32Clocks & AUX_WUC_ANAIF_CLOCK) ||
           (ui32Clocks & AUX_WUC_TIMER_CLOCK) ||
           (ui32Clocks & AUX_WUC_AIODIO0_CLOCK) ||
           (ui32Clocks & AUX_WUC_AIODIO1_CLOCK) ||
           (ui32Clocks & AUX_WUC_SMPH_CLOCK) ||
           (ui32Clocks & AUX_WUC_TDC_CLOCK) ||
           (ui32Clocks & AUX_WUC_ADC_CLOCK) ||
           (ui32Clocks & AUX_WUC_REF_CLOCK));

    bClockStatus = true;

    //
    // Read the status registers.
    //
    ui32ClockRegister = HWREG(AUX_WUC_BASE + AUX_WUC_O_MODCLKEN0);

    //
    // Check all requested clocks
    //
    if(ui32Clocks & AUX_WUC_ADI_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_AUX_ADI4 ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_OSCCTRL_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_AUX_DDI0_OSC ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_TDCIF_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_TDC ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_ANAIF_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_ANAIF ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_TIMER_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_TIMER ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_AIODIO0_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_AIODIO0 ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_AIODIO1_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_AIODIO1 ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_SMPH_CLOCK)
    {
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                              AUX_WUC_MODCLKEN0_SMPH ?
                                              true : false);
    }
    if(ui32Clocks & AUX_WUC_ADC_CLOCK)
    {
        ui32ClockRegister = HWREG(AUX_WUC_BASE + AUX_WUC_O_ADCCLKCTL);
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                        AUX_WUC_ADCCLKCTL_ACK ?
                                        true : false);
    }
    if(ui32Clocks & AUX_WUC_TDC_CLOCK)
    {
        ui32ClockRegister = HWREG(AUX_WUC_BASE + AUX_WUC_O_TDCCLKCTL);
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                        AUX_WUC_TDCCLKCTL_ACK ?
                                        true : false);
    }
    if(ui32Clocks & AUX_WUC_REF_CLOCK)
    {
        ui32ClockRegister = HWREG(AUX_WUC_BASE + AUX_WUC_O_REFCLKCTL);
        bClockStatus = bClockStatus && (ui32ClockRegister &
                                        AUX_WUC_REFCLKCTL_ACK ?
                                        true : false);
    }

    //
    // Return the clock status.
    //
    return bClockStatus ? AUX_WUC_CLOCK_READY : AUX_WUC_CLOCK_OFF;
}

//****************************************************************************
//
//! Control the power to the AUX domain
//
//****************************************************************************
void
AUXWUCPowerCtrl(uint32_t ui32PowerMode)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32PowerMode == AUX_WUC_POWER_OFF) ||
           (ui32PowerMode == AUX_WUC_POWER_DOWN) ||
           (ui32PowerMode == AUX_WUC_POWER_ACTIVE));

    //
    // Power on/off.
    //
    if(ui32PowerMode == AUX_WUC_POWER_OFF)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_PWROFFREQ) = AUX_WUC_PWROFFREQ_REQ;
        HWREG(AUX_WUC_BASE + AUX_WUC_O_MCUBUSCTL) = AUX_WUC_MCUBUSCTL_DISCONNECT_REQ;
        return;
    }
    else
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_PWROFFREQ) = 0x0;
    }

    //
    // Power down/active.
    //
    if(ui32PowerMode == AUX_WUC_POWER_DOWN)
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_PWRDWNREQ) =
            AUX_WUC_PWRDWNREQ_REQ;
        HWREG(AUX_WUC_BASE + AUX_WUC_O_MCUBUSCTL) = AUX_WUC_MCUBUSCTL_DISCONNECT_REQ;
    }
    else
    {
        HWREG(AUX_WUC_BASE + AUX_WUC_O_PWRDWNREQ) = 0x0;
    }
}
