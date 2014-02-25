//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// pmm.c - Driver for the pmm Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup pmm_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifndef DRIVERLIB_LEGACY_MODE

#ifdef __MSP430_HAS_PMM_FRAM__
#include "pmm.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Enables the low power reset. SVSH does not reset device, but
//! triggers a system NMI
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableLowPowerReset(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= PMMLPRST;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the low power reset. SVSH resets device.
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableLowPowerReset(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) &= ~PMMLPRST;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the high-side SVS circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSVSH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0_L) |= SVSHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the high-side SVS circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSVSH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0_L) &= ~SVSHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Makes the low-dropout voltage regulator (LDO) remain ON when going
//! into LPM 3/4.
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_regOn(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) &= ~PMMREGOFF;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Turns OFF the low-dropout voltage regulator (LDO) when going into
//! LPM3/4, thus the system will enter LPM3.5 or LPM4.5 respectively
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_regOff(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= PMMREGOFF;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Calling this function will trigger a software Power On Reset (POR).
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_trigPOR(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= PMMSWPOR;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Calling this function will trigger a software Brown Out Rest (BOR).
//!
//!
//! Modified bits of \b PMMCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void PMM_trigBOR(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= PMMSWBOR;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Clears interrupt flags for the PMM
//!
//! \param mask is the mask for specifying the required flag
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_PMMBORIFG - Software BOR interrupt
//!        - \b PMM_PMMRSTIFG - RESET pin interrupt
//!        - \b PMM_PMMPORIFG - Software POR interrupt
//!        - \b PMM_SVSHIFG - SVS high side interrupt
//!        - \b PMM_SVSLIFG - SVS low side interrupt
//!        - \b PMM_PMMLPM5IFG - LPM5 indication
//!        - \b PMM_ALL - All interrupts
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIFG register.
//!
//! \return None
//
//*****************************************************************************
void PMM_clearInterrupt(uint16_t mask)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~mask;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Returns interrupt status
//!
//! \param mask is the mask for specifying the required flag
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_PMMBORIFG - Software BOR interrupt
//!        - \b PMM_PMMRSTIFG - RESET pin interrupt
//!        - \b PMM_PMMPORIFG - Software POR interrupt
//!        - \b PMM_SVSHIFG - SVS high side interrupt
//!        - \b PMM_SVSLIFG - SVS low side interrupt
//!        - \b PMM_PMMLPM5IFG - LPM5 indication
//!        - \b PMM_ALL - All interrupts
//!
//! \return STATUS_SUCCESS (0x01) or STATUS_FAIL (0x00)
//
//*****************************************************************************
uint16_t PMM_getInterruptStatus(uint16_t mask)
{
        return (HWREG16(PMM_BASE + OFS_PMMIFG)) & mask;
}

//*****************************************************************************
//
//! \brief Lock LPM5
//!
//! Lock I/O pin and other LPMx.5 relevant (e.g. RTC) configurations upon
//! entry/exit to/from LPMx.5. Once power is applied to the device, this bit,
//! once set, can only be cleared by the user or via another power cycle.
//! LPMx.5 configuration remains locked. Pin state is held during LPMx.5 entry
//! and exit. Disable the GPIO power-on default high-impedance mode to activate
//! previously configured port settings.
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_lockLPM5(void)
{
        HWREG8(PMM_BASE + OFS_PM5CTL0) |= LOCKLPM5;
}

//*****************************************************************************
//
//! \brief Unlock LPM5
//!
//! LPMx.5 configuration is not locked and defaults to its reset condition.
//! Disable the GPIO power-on default high-impedance mode to activate
//! previously configured port settings.
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_unlockLPM5(void)
{
        HWREG8(PMM_BASE + OFS_PM5CTL0) &= ~LOCKLPM5;
}

#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for pmm_api
//! @}
//
//*****************************************************************************

#endif
//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430F5529__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// pmm.c - Driver for the pmm Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup pmm_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifndef DRIVERLIB_LEGACY_MODE

#ifdef __MSP430_HAS_PMM__
#include "pmm.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Enables the low-side SVS circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvsL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= SVSLE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the low-side SVS circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvsL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= ~SVSLE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the low-side SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvmL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= SVMLE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the low-side SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvmL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= ~SVMLE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the high-side SVS circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvsH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= SVSHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the high-side SVS circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvsH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= ~SVSHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the high-side SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvmH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= SVMHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the high-side SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvmH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= ~SVMHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the low-side SVS and SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvsLSvmL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= (SVSLE + SVMLE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the low-side SVS and SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvsLSvmL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= ~(SVSLE + SVMLE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the high-side SVS and SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvsHSvmH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= (SVSHE + SVMHE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the high-side SVS and SVM circuitry
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvsHSvmH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= ~(SVSHE + SVMHE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the POR signal generation when a low-voltage event is
//! registered by the low-side SVS
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvsLReset(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) |= SVSLPE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the POR signal generation when a low-voltage event is
//! registered by the low-side SVS
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvsLReset(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) &= ~SVSLPE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the interrupt generation when a low-voltage event is
//! registered by the low-side SVM
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvmLInterrupt(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) |= SVMLIE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the interrupt generation when a low-voltage event is
//! registered by the low-side SVM
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvmLInterrupt(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) &= ~SVMLIE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the POR signal generation when a low-voltage event is
//! registered by the high-side SVS
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvsHReset(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) |= SVSHPE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the POR signal generation when a low-voltage event is
//! registered by the high-side SVS
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvsHReset(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) &= ~SVSHPE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the interrupt generation when a low-voltage event is
//! registered by the high-side SVM
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSvmHInterrupt(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) |= SVMHIE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the interrupt generation when a low-voltage event is
//! registered by the high-side SVM
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIE register.
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSvmHInterrupt(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMRIE) &= ~SVMHIE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Clear all interrupt flags for the PMM
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b PMMIFG register.
//!
//! \return None
//
//*****************************************************************************
void PMM_clearPMMIFGS(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_PMMIFG) = 0;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables supervisor low side in LPM with twake-up-fast from LPM2,
//! LPM3, and LPM4
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsLEnabledInLPMFastWake(void)
{
        //These settings use SVSH/LACE = 0
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= (SVSLFP + SVSLMD);
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= ~SVSMLACE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables supervisor low side in LPM with twake-up-slow from LPM2,
//! LPM3, and LPM4
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsLEnabledInLPMSlowWake(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= SVSLMD;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= ~(SVSLFP + SVSMLACE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables supervisor low side in LPM with twake-up-fast from LPM2,
//! LPM3, and LPM4
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsLDisabledInLPMFastWake(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= SVSLFP;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= ~(SVSLMD + SVSMLACE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables supervisor low side in LPM with twake-up-slow from LPM2,
//! LPM3, and LPM4
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsLDisabledInLPMSlowWake(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= ~(SVSLFP + SVSMLACE + SVSLMD);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables supervisor high side in LPM with tpd = 20 ?s(1)
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsHEnabledInLPMNormPerf(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= SVSHMD;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= ~(SVSMHACE + SVSHFP);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables supervisor high side in LPM with tpd = 2.5 ?s(1)
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsHEnabledInLPMFullPerf(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= (SVSHMD + SVSHFP);
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= ~SVSMHACE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables supervisor high side in LPM with tpd = 20 ?s(1)
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsHDisabledInLPMNormPerf(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= ~(SVSMHACE + SVSHFP + SVSHMD);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables supervisor high side in LPM with tpd = 2.5 ?s(1)
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMHCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsHDisabledInLPMFullPerf(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= SVSHFP;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= ~(SVSMHACE + SVSHMD);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Optimized to provide twake-up-fast from LPM2, LPM3, and LPM4 with
//! least power
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsLOptimizedInLPMFastWake(void)
{
        //These setting use SVSH/LACE = 1
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= (SVSLFP + SVSLMD + SVSMLACE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Optimized to provide tpd = 2.5 ?s(1) in LPM with least power
//!
//!
//! Modified bits of \b PMMCTL0 register and bits of \b SVSMLCTL register.
//!
//! \return None
//
//*****************************************************************************
void PMM_SvsHOptimizedInLPMFullPerf(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= (SVSHMD + SVSHFP + SVSMHACE);
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Increase Vcore by one level
//!
//! \param level level to which Vcore needs to be increased
//!        Valid values are:
//!        - \b PMM_CORE_LEVEL_0 [Default]
//!        - \b PMM_CORE_LEVEL_1
//!        - \b PMM_CORE_LEVEL_2
//!        - \b PMM_CORE_LEVEL_3
//!
//! Modified bits of \b PMMCTL0 register, bits of \b PMMIFG register, bits of
//! \b PMMRIE register, bits of \b SVSMHCTL register and bits of \b SVSMLCTL
//! register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL
//
//*****************************************************************************
uint16_t PMM_setVCoreUp( uint8_t level)
{
        uint32_t PMMRIE_backup, SVSMHCTL_backup, SVSMLCTL_backup;

        //The code flow for increasing the Vcore has been altered to work around
        //the erratum FLASH37.
        //Please refer to the Errata sheet to know if a specific device is affected
        //DO NOT ALTER THIS FUNCTION

        //Open PMM registers for write access
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;

        //Disable dedicated Interrupts
        //Backup all registers
        PMMRIE_backup = HWREG16(PMM_BASE + OFS_PMMRIE);
        HWREG16(PMM_BASE + OFS_PMMRIE) &= ~(SVMHVLRPE | SVSHPE | SVMLVLRPE |
                                            SVSLPE | SVMHVLRIE | SVMHIE |
                                            SVSMHDLYIE | SVMLVLRIE | SVMLIE |
                                            SVSMLDLYIE
                                            );
        SVSMHCTL_backup = HWREG16(PMM_BASE + OFS_SVSMHCTL);
        SVSMLCTL_backup = HWREG16(PMM_BASE + OFS_SVSMLCTL);

        //Clear flags
        HWREG16(PMM_BASE + OFS_PMMIFG) = 0;

        //Set SVM highside to new level and check if a VCore increase is possible
        HWREG16(PMM_BASE + OFS_SVSMHCTL) = SVMHE | SVSHE | (SVSMHRRL0 * level);

        //Wait until SVM highside is settled
        while ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMHDLYIFG) == 0) ;

        //Clear flag
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~SVSMHDLYIFG;

        //Check if a VCore increase is possible
        if ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVMHIFG) == SVMHIFG) {
                //-> Vcc is too low for a Vcore increase
                //recover the previous settings
                HWREG16(PMM_BASE + OFS_PMMIFG) &= ~SVSMHDLYIFG;
                HWREG16(PMM_BASE + OFS_SVSMHCTL) = SVSMHCTL_backup;

                //Wait until SVM highside is settled
                while ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMHDLYIFG) == 0) ;

                //Clear all Flags
                HWREG16(PMM_BASE +
                        OFS_PMMIFG) &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG |
                                         SVMLVLRIFG | SVMLIFG |
                                         SVSMLDLYIFG
                                         );

                //Restore PMM interrupt enable register
                HWREG16(PMM_BASE + OFS_PMMRIE) = PMMRIE_backup;
                //Lock PMM registers for write access
                HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
                //return: voltage not set
                return STATUS_FAIL;
        }

        //Set also SVS highside to new level
        //Vcc is high enough for a Vcore increase
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= (SVSHRVL0 * level);

        //Wait until SVM highside is settled
        while ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMHDLYIFG) == 0) ;

        //Clear flag
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~SVSMHDLYIFG;

        //Set VCore to new level
        HWREG8(PMM_BASE + OFS_PMMCTL0_L) = PMMCOREV0 * level;

        //Set SVM, SVS low side to new level
        HWREG16(PMM_BASE + OFS_SVSMLCTL) = SVMLE | (SVSMLRRL0 * level) |
                                           SVSLE | (SVSLRVL0 * level);

        //Wait until SVM, SVS low side is settled
        while ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ;

        //Clear flag
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~SVSMLDLYIFG;
        //SVS, SVM core and high side are now set to protect for the new core level

        //Restore Low side settings
        //Clear all other bits _except_ level settings
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= (SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 +
                                             SVSMLRRL1 + SVSMLRRL2
                                             );

        //Clear level settings in the backup register,keep all other bits
        SVSMLCTL_backup &=
                ~(SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

        //Restore low-side SVS monitor settings
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= SVSMLCTL_backup;

        //Restore High side settings
        //Clear all other bits except level settings
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= (SVSHRVL0 + SVSHRVL1 +
                                             SVSMHRRL0 + SVSMHRRL1 +
                                             SVSMHRRL2
                                             );

        //Clear level settings in the backup register,keep all other bits
        SVSMHCTL_backup &=
                ~(SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

        //Restore backup
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= SVSMHCTL_backup;

        //Wait until high side, low side settled
        while (((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ||
               ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMHDLYIFG) == 0)) ;

        //Clear all Flags
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG |
                                            SVMLVLRIFG | SVMLIFG | SVSMLDLYIFG
                                            );

        //Restore PMM interrupt enable register
        HWREG16(PMM_BASE + OFS_PMMRIE) = PMMRIE_backup;

        //Lock PMM registers for write access
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;

        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Decrease Vcore by one level
//!
//! \param level level to which Vcore needs to be decreased
//!        Valid values are:
//!        - \b PMM_CORE_LEVEL_0 [Default]
//!        - \b PMM_CORE_LEVEL_1
//!        - \b PMM_CORE_LEVEL_2
//!        - \b PMM_CORE_LEVEL_3
//!
//! Modified bits of \b PMMCTL0 register, bits of \b PMMIFG register, bits of
//! \b PMMRIE register, bits of \b SVSMHCTL register and bits of \b SVSMLCTL
//! register.
//!
//! \return STATUS_SUCCESS
//
//*****************************************************************************
uint16_t PMM_setVCoreDown( uint8_t level)
{
        uint32_t PMMRIE_backup, SVSMHCTL_backup, SVSMLCTL_backup;

        //The code flow for decreasing the Vcore has been altered to work around
        //the erratum FLASH37.
        //Please refer to the Errata sheet to know if a specific device is affected
        //DO NOT ALTER THIS FUNCTION

        //Open PMM registers for write access
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0xA5;

        //Disable dedicated Interrupts
        //Backup all registers
        PMMRIE_backup = HWREG16(PMM_BASE + OFS_PMMRIE);
        HWREG16(PMM_BASE + OFS_PMMRIE) &= ~(SVMHVLRPE | SVSHPE | SVMLVLRPE |
                                            SVSLPE | SVMHVLRIE | SVMHIE |
                                            SVSMHDLYIE | SVMLVLRIE | SVMLIE |
                                            SVSMLDLYIE
                                            );
        SVSMHCTL_backup = HWREG16(PMM_BASE + OFS_SVSMHCTL);
        SVSMLCTL_backup = HWREG16(PMM_BASE + OFS_SVSMLCTL);

        //Clear flags
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~(SVMHIFG | SVSMHDLYIFG |
                                            SVMLIFG | SVSMLDLYIFG
                                            );

        //Set SVM, SVS high & low side to new settings in normal mode
        HWREG16(PMM_BASE + OFS_SVSMHCTL) = SVMHE | (SVSMHRRL0 * level) |
                                           SVSHE | (SVSHRVL0 * level);
        HWREG16(PMM_BASE + OFS_SVSMLCTL) = SVMLE | (SVSMLRRL0 * level) |
                                           SVSLE | (SVSLRVL0 * level);

        //Wait until SVM high side and SVM low side is settled
        while ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMHDLYIFG) == 0 ||
               (HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ;

        //Clear flags
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~(SVSMHDLYIFG + SVSMLDLYIFG);
        //SVS, SVM core and high side are now set to protect for the new core level

        //Set VCore to new level
        HWREG8(PMM_BASE + OFS_PMMCTL0_L) = PMMCOREV0 * level;

        //Restore Low side settings
        //Clear all other bits _except_ level settings
        HWREG16(PMM_BASE + OFS_SVSMLCTL) &= (SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 +
                                             SVSMLRRL1 + SVSMLRRL2
                                             );

        //Clear level settings in the backup register,keep all other bits
        SVSMLCTL_backup &=
                ~(SVSLRVL0 + SVSLRVL1 + SVSMLRRL0 + SVSMLRRL1 + SVSMLRRL2);

        //Restore low-side SVS monitor settings
        HWREG16(PMM_BASE + OFS_SVSMLCTL) |= SVSMLCTL_backup;

        //Restore High side settings
        //Clear all other bits except level settings
        HWREG16(PMM_BASE + OFS_SVSMHCTL) &= (SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 +
                                             SVSMHRRL1 + SVSMHRRL2
                                             );

        //Clear level settings in the backup register, keep all other bits
        SVSMHCTL_backup &=
                ~(SVSHRVL0 + SVSHRVL1 + SVSMHRRL0 + SVSMHRRL1 + SVSMHRRL2);

        //Restore backup
        HWREG16(PMM_BASE + OFS_SVSMHCTL) |= SVSMHCTL_backup;

        //Wait until high side, low side settled
        while (((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMLDLYIFG) == 0) ||
               ((HWREG16(PMM_BASE + OFS_PMMIFG) & SVSMHDLYIFG) == 0)) ;

        //Clear all Flags
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~(SVMHVLRIFG | SVMHIFG | SVSMHDLYIFG |
                                            SVMLVLRIFG | SVMLIFG | SVSMLDLYIFG
                                            );

        //Restore PMM interrupt enable register
        HWREG16(PMM_BASE + OFS_PMMRIE) = PMMRIE_backup;
        //Lock PMM registers for write access
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
        //Return: OK
        return STATUS_SUCCESS;
}

//*****************************************************************************
//
//! \brief Set Vcore to expected level
//!
//! \param level level to which Vcore needs to be decreased/increased
//!        Valid values are:
//!        - \b PMM_CORE_LEVEL_0 [Default]
//!        - \b PMM_CORE_LEVEL_1
//!        - \b PMM_CORE_LEVEL_2
//!        - \b PMM_CORE_LEVEL_3
//!
//! Modified bits of \b PMMCTL0 register, bits of \b PMMIFG register, bits of
//! \b PMMRIE register, bits of \b SVSMHCTL register and bits of \b SVSMLCTL
//! register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL
//
//*****************************************************************************
bool PMM_setVCore( uint8_t level)
{
        assert(
                (PMM_CORE_LEVEL_0 == level) ||
                (PMM_CORE_LEVEL_1 == level) ||
                (PMM_CORE_LEVEL_2 == level) ||
                (PMM_CORE_LEVEL_3 == level)
                );

        uint8_t actlevel;
        bool status = STATUS_SUCCESS;

        //Set Mask for Max. level
        level &= PMMCOREV_3;

        //Get actual VCore
        actlevel = (HWREG16(PMM_BASE + OFS_PMMCTL0) & PMMCOREV_3);

        //step by step increase or decrease
        while ((level != actlevel) && (status == STATUS_SUCCESS)) {
                if (level > actlevel)
                        status = PMM_setVCoreUp(++actlevel);
                else
                        status = PMM_setVCoreDown(--actlevel);
        }

        return status;
}

//*****************************************************************************
//
//! \brief Returns interrupt status
//!
//! \param mask is the mask for specifying the required flag
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_SVSMLDLYIFG
//!        - \b PMM_SVMLIFG
//!        - \b PMM_SVMLVLRIFG
//!        - \b PMM_SVSMHDLYIFG
//!        - \b PMM_SVMHIFG
//!        - \b PMM_SVMHVLRIFG
//!        - \b PMM_PMMBORIFG
//!        - \b PMM_PMMRSTIFG
//!        - \b PMM_PMMPORIFG
//!        - \b PMM_SVSHIFG
//!        - \b PMM_SVSLIFG
//!        - \b PMM_PMMLPM5IFG
//!
//! \return Logical OR of any of the following:
//!         - \b PMM_SVSMLDLYIFG
//!         - \b PMM_SVMLIFG
//!         - \b PMM_SVMLVLRIFG
//!         - \b PMM_SVSMHDLYIFG
//!         - \b PMM_SVMHIFG
//!         - \b PMM_SVMHVLRIFG
//!         - \b PMM_PMMBORIFG
//!         - \b PMM_PMMRSTIFG
//!         - \b PMM_PMMPORIFG
//!         - \b PMM_SVSHIFG
//!         - \b PMM_SVSLIFG
//!         - \b PMM_PMMLPM5IFG
//!         \n indicating the status of the masked interrupts
//
//*****************************************************************************
uint16_t PMM_getInterruptStatus(uint16_t mask)
{
        return (HWREG16(PMM_BASE + OFS_PMMIFG)) & mask;
}

#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for pmm_api
//! @}
//
//*****************************************************************************

#endif
//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5739__)

/* --COPYRIGHT--,BSD
 * Copyright (c) 2013, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
//*****************************************************************************
//
// pmm.c - Driver for the pmm Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup pmm_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifndef DRIVERLIB_LEGACY_MODE

#ifdef __MSP430_HAS_PMM_FR5xx__
#include "pmm.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Enables the low-side SVS circuitry
//!
//! Modified registers are PMMCTL0 , SVSMLCTL .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSVSL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= SVSLE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the low-side SVS circuitry
//!
//! Modified registers are PMMCTL0 .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSVSL(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) &= ~SVSLE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Enables the high-side SVS circuitry
//!
//! Modified registers are PMMCTL0 .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_enableSVSH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0_L) |= SVSHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Disables the high-side SVS circuitry
//!
//! Modified registers are PMMCTL0 .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_disableSVSH(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0_L) &= ~SVSHE;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Makes the low-dropout voltage regulator (LDO) remain ON when going
//! into LPM 3/4. [Default]
//!
//! Modified registers are PMMCTL0 .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_regOn(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) &= ~PMMREGOFF;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Turns OFF the low-dropout voltage regulator (LDO) when going into
//! LPM3/4, thus the system will enter LPM3.5 or LPM4.5 respectively
//!
//! Modified registers are PMMCTL0 .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_regOff(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= PMMREGOFF;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Calling this function will trigger a software Power On Reset (POR).
//!
//! Modified registers are PMMCTL0 .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_trigPOR(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= PMMSWPOR;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Calling this function will trigger a software Brown Out Rest (BOR).
//!
//! Modified registers are PMMCTL0 .
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_trigBOR(void)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG8(PMM_BASE + OFS_PMMCTL0) |= PMMSWBOR;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Clear all interrupt flags for the PMM
//!
//! Modified registers are PMMCTL0 , PMMIFG .
//!
//! \param mask is the mask for specifying the required flag
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_PMMBORIFG
//!        - \b PMM_PMMRSTIFG
//!        - \b PMM_PMMPORIFG
//!        - \b PMM_SVSLIFG
//!        - \b PMM_SVSHIFG
//!        - \b PMM_PMMLPM5IFG
//!        - \b PMM_ALL
//!
//! \return None
//
//*****************************************************************************
void PMM_clearInterrupt(uint16_t mask)
{
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = PMMPW_H;
        HWREG16(PMM_BASE + OFS_PMMIFG) &= ~mask;
        HWREG8(PMM_BASE + OFS_PMMCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Returns interrupt status
//!
//! \param mask is the mask for specifying the required flag
//!        Mask value is the logical OR of any of the following:
//!        - \b PMM_PMMBORIFG
//!        - \b PMM_PMMRSTIFG
//!        - \b PMM_PMMPORIFG
//!        - \b PMM_SVSLIFG
//!        - \b PMM_SVSHIFG
//!        - \b PMM_PMMLPM5IFG
//!        - \b PMM_ALL
//!
//! \return Logical OR of any of the following:
//!         - \b PMM_PMMBORIFG
//!         - \b PMM_PMMRSTIFG
//!         - \b PMM_PMMPORIFG
//!         - \b PMM_SVSLIFG
//!         - \b PMM_SVSHIFG
//!         - \b PMM_PMMLPM5IFG
//!         - \b PMM_ALL
//!         \n indicating  the status of the selected  interrupt flags
//
//*****************************************************************************
uint16_t PMM_getInterruptStatus(uint16_t mask)
{
        return (HWREG16(PMM_BASE + OFS_PMMIFG)) & mask;
}

//*****************************************************************************
//
//! \brief Lock I/O pin and other LPMx.5 relevant (e.g. RTC) configurations
//! upon entry/exit to/from LPMx.5. Once power is applied to the device, this
//! bit, once set, can only be cleared by the user or via another power cycle.
//! LPMx.5 configuration remains locked. Pin state is held during LPMx.5 entry
//! and exit.
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_lockLPM5(void)
{
        HWREG8(PMM_BASE + OFS_PM5CTL0) |= LOCKLPM5;
}

//*****************************************************************************
//
//! \brief LPMx.5 configuration is not locked and defaults to its reset
//! condition.
//!
//!
//! \return None
//
//*****************************************************************************
void PMM_unlockLPM5(void)
{
        HWREG8(PMM_BASE + OFS_PM5CTL0) &= ~LOCKLPM5;
}

#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for pmm_api
//! @}
//
//*****************************************************************************

#endif
