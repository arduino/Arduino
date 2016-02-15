/******************************************************************************
*  Filename:       aon_wuc.c
*  Revised:        2015-04-28 11:13:22 +0200 (Tue, 28 Apr 2015)
*  Revision:       43340
*
*  Description:    Driver for the AON Wake-Up Controller.
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

#include <driverlib/aon_wuc.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #undef  AONWUCAuxReset
    #define AONWUCAuxReset                  NOROM_AONWUCAuxReset
    #undef  AONWUCRechargeCtrlConfigSet
    #define AONWUCRechargeCtrlConfigSet     NOROM_AONWUCRechargeCtrlConfigSet
    #undef  AONWUCOscConfig
    #define AONWUCOscConfig                 NOROM_AONWUCOscConfig
#endif


//*****************************************************************************
//
//! Reset the AUX domain
//
//*****************************************************************************
void
AONWUCAuxReset(void)
{
    // Reset the AUX domain.
//  HWREG(AON_WUC_BASE + AON_WUC_O_AUXCTL) |= AON_WUC_AUXCTL_RESET_REQ;  // ROM version
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_AUXCTL, AON_WUC_AUXCTL_RESET_REQ_BITN) = 1;

    // Wait for AON interface to be in sync.
    HWREG(AON_RTC_BASE + AON_RTC_O_SYNC);

    // De-assert reset on the AUX domain.
//  HWREG(AON_WUC_BASE + AON_WUC_O_AUXCTL) &= ~AON_WUC_AUXCTL_RESET_REQ;  // ROM version
    HWREGBITW(AON_WUC_BASE + AON_WUC_O_AUXCTL, AON_WUC_AUXCTL_RESET_REQ_BITN) = 0;

    // Wait for AON interface to be in sync.
    HWREG(AON_RTC_BASE + AON_RTC_O_SYNC);
}

//*****************************************************************************
//
//! Configure the recharge controller
//
//*****************************************************************************
void
AONWUCRechargeCtrlConfigSet(bool bAdaptEnable, uint32_t ui32AdaptRate,
                            uint32_t ui32Period, uint32_t ui32MaxPeriod)
{
    uint32_t ui32Shift;
    uint32_t ui32C1;
    uint32_t ui32C2;
    uint32_t ui32Reg;
    uint32_t ui32Exponent;
    uint32_t ui32MaxExponent;
    uint32_t ui32Mantissa;
    uint32_t ui32MaxMantissa;

    //
    // Check the arguments.
    //
    ASSERT((ui32AdaptRate >= RC_RATE_MIN) ||
           (ui32AdaptRate <= RC_RATE_MAX));

    ui32C1 = 0;
    ui32C2 = 0;
    ui32Shift = 9;

    //
    // Clear the previous values.
    //
    ui32Reg = HWREG(AON_WUC_BASE + AON_WUC_O_RECHARGECFG);
    ui32Reg &= ~(AON_WUC_RECHARGECFG_MAX_PER_M_M | AON_WUC_RECHARGECFG_MAX_PER_E_M |
                 AON_WUC_RECHARGECFG_ADAPTIVE_EN_M | AON_WUC_RECHARGECFG_PER_M_M |
                 AON_WUC_RECHARGECFG_PER_E_M | AON_WUC_RECHARGECFG_C1_M |
                 AON_WUC_RECHARGECFG_C2_M);

    //
    // Check if the recharge controller adaptation algorithm should be active.
    //
    if(bAdaptEnable)
    {
        //
        // Calculate adaptation parameters.
        //
        while(ui32AdaptRate)
        {
            if(ui32AdaptRate & (1 << ui32Shift))
            {
                if(!ui32C1)
                {
                    ui32C1 = ui32Shift;
                }
                else if(!ui32C2)
                {
                    if((2 * ui32AdaptRate) > ((uint32_t)(3 << ui32Shift)))
                    {
                        ui32C2 = ui32Shift + 1;
                    }
                    else
                    {
                        ui32C2 = ui32Shift;
                    }
                }
                else
                {
                    break;
                }
                ui32AdaptRate &= ~(1 << ui32Shift);
            }
            ui32Shift--;
        }
        if(!ui32C2)
        {
            ui32C2 = ui32C1 = ui32C1 - 1;
        }

        ui32C1 = 10 - ui32C1;
        ui32C2 = 10 - ui32C2;

        //
        // Update the recharge rate parameters.
        //
        ui32Reg &= ~(AON_WUC_RECHARGECFG_C1_M | AON_WUC_RECHARGECFG_C2_M);
        ui32Reg |= (ui32C1 << AON_WUC_RECHARGECFG_C1_S) |
                   (ui32C2 << AON_WUC_RECHARGECFG_C2_S) |
                   AON_WUC_RECHARGECFG_ADAPTIVE_EN_M;
    }

    //
    // Resolve the period into an exponent and mantissa.
    //
    ui32Period = (ui32Period >> 4);
    ui32Exponent = 0;
    while(ui32Period > (AON_WUC_RECHARGECFG_PER_M_M >> AON_WUC_RECHARGECFG_PER_M_S))
    {
        ui32Period >>= 1;
        ui32Exponent++;
    }
    ui32Mantissa = ui32Period;

    //
    // Resolve the max period into an exponent and mantissa.
    //
    ui32MaxPeriod = (ui32MaxPeriod >> 4);
    ui32MaxExponent = 0;
    while(ui32MaxPeriod > (AON_WUC_RECHARGECFG_MAX_PER_M_M >> AON_WUC_RECHARGECFG_MAX_PER_M_S))
    {
        ui32MaxPeriod >>= 1;
        ui32MaxExponent++;
    }
    ui32MaxMantissa = ui32MaxPeriod;

    //
    // Configure the controller.
    //
    ui32Reg |= ((ui32MaxMantissa << AON_WUC_RECHARGECFG_MAX_PER_M_S) |
                (ui32MaxExponent << AON_WUC_RECHARGECFG_MAX_PER_E_S) |
                (ui32Mantissa << AON_WUC_RECHARGECFG_PER_M_S) |
                (ui32Exponent << AON_WUC_RECHARGECFG_PER_E_S));
    HWREG(AON_WUC_BASE + AON_WUC_O_RECHARGECFG) = ui32Reg;

}

//*****************************************************************************
//
//! Configure the interval for oscillator amplitude calibration
//
//*****************************************************************************
void
AONWUCOscConfig(uint32_t ui32Period)
{
    uint32_t ui32Mantissa;
    uint32_t ui32Exponent;
    uint32_t ui32Reg;

    //
    // Resolve the period into a exponent and mantissa.
    //
    ui32Period = (ui32Period >> 4);
    ui32Exponent = 0;
    while(ui32Period > (AON_WUC_OSCCFG_PER_M_M >> AON_WUC_OSCCFG_PER_M_S))
    {
        ui32Period >>= 1;
        ui32Exponent++;
    }
    ui32Mantissa = ui32Period;

    //
    // Update the period for the oscillator amplitude calibration.
    //
    HWREG(AON_WUC_BASE + AON_WUC_O_OSCCFG) =
        (ui32Mantissa << AON_WUC_OSCCFG_PER_M_S) |
        (ui32Exponent << AON_WUC_OSCCFG_PER_E_S);

    //
    // Set the maximum recharge period equal to the oscillator amplitude
    // calibration period.
    //
    ui32Reg = HWREG(AON_WUC_BASE + AON_WUC_O_RECHARGECFG);
    ui32Reg &= ~(AON_WUC_RECHARGECFG_MAX_PER_M_M | AON_WUC_RECHARGECFG_MAX_PER_E_M);
    ui32Reg |= ((ui32Mantissa << AON_WUC_RECHARGECFG_MAX_PER_M_S) |
                (ui32Exponent << AON_WUC_RECHARGECFG_MAX_PER_E_S));

    //
    // Write the configuration.
    //
    HWREG(AON_WUC_BASE + AON_WUC_O_RECHARGECFG) = ui32Reg;
}
