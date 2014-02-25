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
// ucs.c - Driver for the ucs Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup ucs_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifndef DRIVERLIB_LEGACY_MODE

#ifdef __MSP430_HAS_UCS__
#include "ucs.h"

#include <assert.h>

#ifdef __GNUC__
#define __delay_cycles(x) \
        ({ \
                 volatile unsigned int j; \
                 for (j = 0; j < x; j++) \
                 { \
                         __no_operation(); \
                 } \
         })

#endif
//******************************************************************************
//
// The XT1 crystal frequency. Should be set with
// UCS_setExternalClockSource if XT1 is used and user intends to
// invoke UCS_getSMCLK, UCS_getMCLK or UCS_getACLK
//
//******************************************************************************
uint32_t UCS_XT1ClockFrequency = 0;

//******************************************************************************
//
// The XT2 crystal frequency. Should be set with
// UCS_setExternalClockSource if XT1 is used and user intends to invoke
// UCS_getSMCLK, UCS_getMCLK or UCS_getACLK
//
//******************************************************************************
uint32_t UCS_XT2ClockFrequency = 0;

//*****************************************************************************
//
//! \brief Compute the clock frequency when clock is sourced from DCO
//!
//! \param FLLRefCLKSource is clock source for FLL reference
//!
//! \return Calculated clock frequency in Hz
//
//*****************************************************************************
static uint32_t privateUCSSourceClockFromDCO(uint16_t FLLRefCLKSource
                                             )
{
        assert((SELM__DCOCLKDIV == FLLRefCLKSource) ||
               (SELM__DCOCLK == FLLRefCLKSource)
               );
        uint16_t D_value = 1;
        uint16_t N_value;
        uint16_t n_value = 1;
        uint32_t Fref_value;
        uint8_t i;

        N_value = (HWREG16(UCS_BASE + OFS_UCSCTL2)) & 0x03FF;
        uint16_t tempDivider = HWREG8(UCS_BASE + OFS_UCSCTL3) & FLLREFDIV_7;

        if (tempDivider < 4)
                n_value <<= tempDivider;
        else if (tempDivider == 4)
                n_value = 12;
        else if (tempDivider == 5)
                n_value = 16;

        switch ( (HWREG8(UCS_BASE + OFS_UCSCTL3)) & SELREF_7) {
        case SELREF__XT1CLK:
                Fref_value = UCS_XT1ClockFrequency;

                if (XTS != (HWREG16(UCS_BASE + OFS_UCSCTL6) & XTS)) {
                        if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1LFOFFG) {
                                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1LFOFFG);
                                //Clear OFIFG fault flag
                                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;

                                if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1LFOFFG)
                                        Fref_value = UCS_REFOCLK_FREQUENCY;
                        }
                }else  {
                        if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1HFOFFG) {
                                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1HFOFFG);
                                //Clear OFIFG fault flag
                                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;

                                if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1HFOFFG)
                                        Fref_value = UCS_REFOCLK_FREQUENCY;
                        }
                }

                break;
        case SELREF__REFOCLK:
                Fref_value = UCS_REFOCLK_FREQUENCY;
                break;
        case SELREF__XT2CLK:
                Fref_value = UCS_XT2ClockFrequency;

                if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG) {
                        HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT2OFFG);

                        //Clear OFIFG fault flag
                        HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;

                        if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG)
                                Fref_value = UCS_REFOCLK_FREQUENCY;
                }

                break;
        default: assert(0);
        }

        uint32_t CLKFrequency = Fref_value * ( N_value + 1) / n_value;

        if (SELM__DCOCLK == FLLRefCLKSource) {
                tempDivider = (HWREG16(UCS_BASE + OFS_UCSCTL2)) & FLLD_7;
                tempDivider = tempDivider >> 12;

                for (i = 0; i < tempDivider; i++)
                        D_value =  D_value * 2;

                CLKFrequency *= D_value;
        }
        return CLKFrequency;
}

//*****************************************************************************
//
//! \brief Compute the clock frequency given the clock source and divider
//!
//! \param CLKSource is the clock source
//! \param CLKSourceDivider is the clock source divider
//!
//! \return Calculated clock frequency in Hz
//
//*****************************************************************************
static uint32_t privateUCSComputeCLKFrequency(uint16_t CLKSource,
                                              uint16_t CLKSourceDivider
                                              )
{
        uint32_t CLKFrequency;
        uint8_t CLKSourceFrequencyDivider = 1;
        uint8_t i = 0;

        for ( i = 0; i < CLKSourceDivider; i++)
                CLKSourceFrequencyDivider *= 2;

        switch (CLKSource) {
        case SELM__XT1CLK:
                CLKFrequency = (UCS_XT1ClockFrequency /
                                CLKSourceFrequencyDivider);

                if (XTS != (HWREG16(UCS_BASE + OFS_UCSCTL6) & XTS)) {
                        if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1LFOFFG) {
                                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1LFOFFG);
                                //Clear OFIFG fault flag
                                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;

                                if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1LFOFFG)
                                        CLKFrequency = UCS_REFOCLK_FREQUENCY;
                        }
                }else  {
                        if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1HFOFFG) {
                                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1HFOFFG);
                                //Clear OFIFG fault flag
                                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;

                                if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1HFOFFG)
                                        CLKFrequency = UCS_REFOCLK_FREQUENCY;
                        }
                }
                break;

        case SELM__VLOCLK:
                CLKFrequency =
                        (UCS_VLOCLK_FREQUENCY / CLKSourceFrequencyDivider);
                break;
        case SELM__REFOCLK:
                CLKFrequency =
                        (UCS_REFOCLK_FREQUENCY / CLKSourceFrequencyDivider);
                break;
        case SELM__XT2CLK:
                CLKFrequency =
                        (UCS_XT2ClockFrequency / CLKSourceFrequencyDivider);

                if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG) {

                        HWREG8(UCS_BASE + OFS_UCSCTL7) &=  ~XT2OFFG;
                        //Clear OFIFG fault flag
                        HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
                }

                if (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG)
                        CLKFrequency =
                                privateUCSSourceClockFromDCO( SELM__DCOCLKDIV);
                break;
        case SELM__DCOCLK:
        case SELM__DCOCLKDIV:
                CLKFrequency = privateUCSSourceClockFromDCO(
                        CLKSource) / CLKSourceFrequencyDivider;
                break;
        }

        return CLKFrequency;
}

//*****************************************************************************
//
//! \brief Sets the external clock source
//!
//! This function sets the external clock sources XT1 and XT2 crystal
//! oscillator frequency values. This function must be called if an external
//! crystal XT1 or XT2 is used and the user intends to call UCS_getMCLK,
//! UCS_getSMCLK or UCS_getACLK APIs. If not, it is not necessary to invoke
//! this API.
//!
//! \param XT1CLK_frequency is the XT1 crystal frequencies in Hz
//! \param XT2CLK_frequency is the XT2 crystal frequencies in Hz
//!
//! \return None
//
//*****************************************************************************
void UCS_setExternalClockSource(uint32_t XT1CLK_frequency,
                                uint32_t XT2CLK_frequency
                                )
{
        UCS_XT1ClockFrequency = XT1CLK_frequency;
        UCS_XT2ClockFrequency = XT2CLK_frequency;
}

//*****************************************************************************
//
//! \brief Initializes a clock signal
//!
//! This function initializes each of the clock signals. The user must ensure
//! that this function is called for each clock signal. If not, the default
//! state is assumed for the particular clock signal. Refer MSP430Ware
//! documentation for UCS module or Device Family User's Guide for details of
//! default clock signal states.
//!
//! \param selectedClockSignal selected clock signal
//!        Valid values are:
//!        - \b UCS_ACLK
//!        - \b UCS_MCLK
//!        - \b UCS_SMCLK
//!        - \b UCS_FLLREF
//! \param clockSource is clock source for the selectedClockSignal
//!        Valid values are:
//!        - \b UCS_XT1CLK_SELECT
//!        - \b UCS_VLOCLK_SELECT
//!        - \b UCS_REFOCLK_SELECT
//!        - \b UCS_DCOCLK_SELECT
//!        - \b UCS_DCOCLKDIV_SELECT
//!        - \b UCS_XT2CLK_SELECT
//! \param clockSourceDivider selected the clock divider to calculate
//!        clocksignal from clock source.
//!        Valid values are:
//!        - \b UCS_CLOCK_DIVIDER_1 [Default]
//!        - \b UCS_CLOCK_DIVIDER_2
//!        - \b UCS_CLOCK_DIVIDER_4
//!        - \b UCS_CLOCK_DIVIDER_8
//!        - \b UCS_CLOCK_DIVIDER_12 - [Valid only for UCS_FLLREF]
//!        - \b UCS_CLOCK_DIVIDER_16
//!        - \b UCS_CLOCK_DIVIDER_32 - [Not valid for UCS_FLLREF]
//!
//! Modified bits of \b UCSCTL5 register, bits of \b UCSCTL4 register and bits
//! of \b UCSCTL3 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_clockSignalInit(uint8_t selectedClockSignal,
                         uint16_t clockSource,
                         uint16_t clockSourceDivider
                         )
{
        assert(
                (UCS_XT1CLK_SELECT == clockSource) ||
                (UCS_VLOCLK_SELECT == clockSource) ||
                (UCS_REFOCLK_SELECT == clockSource) ||
                (UCS_DCOCLK_SELECT == clockSource) ||
                (UCS_DCOCLKDIV_SELECT == clockSource) ||
                (UCS_XT2CLK_SELECT == clockSource)
                );

        assert(
                (UCS_CLOCK_DIVIDER_1 == clockSourceDivider) ||
                (UCS_CLOCK_DIVIDER_2 == clockSourceDivider) ||
                (UCS_CLOCK_DIVIDER_4 == clockSourceDivider) ||
                (UCS_CLOCK_DIVIDER_8 == clockSourceDivider) ||
                (UCS_CLOCK_DIVIDER_16 == clockSourceDivider) ||
                (UCS_CLOCK_DIVIDER_32 == clockSourceDivider)
                );

        switch (selectedClockSignal) {
        case UCS_ACLK:
                HWREG16(UCS_BASE + OFS_UCSCTL4) &= ~(SELA_7);
                clockSource = clockSource << 8;
                HWREG16(UCS_BASE + OFS_UCSCTL4) |= (clockSource);

                HWREG16(UCS_BASE + OFS_UCSCTL5) &= ~(DIVA_7);
                clockSourceDivider = clockSourceDivider << 8;
                HWREG16(UCS_BASE + OFS_UCSCTL5) |= clockSourceDivider;
                break;
        case UCS_SMCLK:
                HWREG16(UCS_BASE + OFS_UCSCTL4) &= ~(SELS_7);
                clockSource = clockSource << 4;
                HWREG16(UCS_BASE + OFS_UCSCTL4) |= (clockSource);

                HWREG16(UCS_BASE + OFS_UCSCTL5) &= ~(DIVS_7);
                clockSourceDivider = clockSourceDivider << 4;
                HWREG16(UCS_BASE + OFS_UCSCTL5) |= clockSourceDivider;
                break;
        case UCS_MCLK:
                HWREG16(UCS_BASE + OFS_UCSCTL4) &= ~(SELM_7);
                HWREG16(UCS_BASE + OFS_UCSCTL4) |= (clockSource);

                HWREG16(UCS_BASE + OFS_UCSCTL5) &= ~(DIVM_7);
                HWREG16(UCS_BASE + OFS_UCSCTL5) |= clockSourceDivider;
                break;
        case UCS_FLLREF:
                assert(clockSource <= SELA_5);
                HWREG8(UCS_BASE + OFS_UCSCTL3) &=  ~(SELREF_7);

                clockSource = clockSource << 4;
                HWREG8(UCS_BASE + OFS_UCSCTL3) |= (clockSource);

                HWREG8(UCS_BASE + OFS_UCSCTL3) &= ~(FLLREFDIV_7);
                //Note that dividers for FLLREF are slightly different
                //Hence handled differently from other CLK signals
                switch (clockSourceDivider) {
                case UCS_CLOCK_DIVIDER_12:
                        HWREG8(UCS_BASE + OFS_UCSCTL3) |= FLLREFDIV__12;
                        break;
                case UCS_CLOCK_DIVIDER_16:
                        HWREG8(UCS_BASE + OFS_UCSCTL3) |= FLLREFDIV__16;
                        break;
                default:
                        HWREG8(UCS_BASE + OFS_UCSCTL3) |= clockSourceDivider;
                        break;
                }

                break;
        }
}

//*****************************************************************************
//
//! \brief Initializes the XT1 crystal oscillator in low frequency mode
//!
//! Initializes the XT1 crystal oscillator in low frequency mode. Loops until
//! all oscillator fault flags are cleared, with no timeout. See the device-
//! specific data sheet for appropriate drive settings.
//!
//! \param xt1drive is the target drive strength for the XT1 crystal
//!        oscillator.
//!        Valid values are:
//!        - \b UCS_XT1_DRIVE0
//!        - \b UCS_XT1_DRIVE1
//!        - \b UCS_XT1_DRIVE2
//!        - \b UCS_XT1_DRIVE3 [Default]
//!        \n Modified bits are \b XT1DRIVE of \b UCSCTL6 register.
//! \param xcap is the selected capacitor value. This parameter selects the
//!        capacitors applied to the LF crystal (XT1) or resonator in the LF
//!        mode. The effective capacitance (seen by the crystal) is Ceff. (CXIN
//!        + 2 pF)/2. It is assumed that CXIN = CXOUT and that a parasitic
//!        capacitance of 2 pF is added by the package and the printed circuit
//!        board. For details about the typical internal and the effective
//!        capacitors, refer to the device-specific data sheet.
//!        Valid values are:
//!        - \b UCS_XCAP_0
//!        - \b UCS_XCAP_1
//!        - \b UCS_XCAP_2
//!        - \b UCS_XCAP_3 [Default]
//!
//! Modified bits are \b XCAP of \b UCSCTL6 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_LFXT1Start(uint16_t xt1drive,
                    uint8_t xcap
                    )
{
        assert((xcap == UCS_XCAP_0) ||
               (xcap == UCS_XCAP_1) ||
               (xcap == UCS_XCAP_2) ||
               (xcap == UCS_XCAP_3) );

        assert((xt1drive == UCS_XT1_DRIVE0 ) ||
               (xt1drive == UCS_XT1_DRIVE1 ) ||
               (xt1drive == UCS_XT1_DRIVE2 ) ||
               (xt1drive == UCS_XT1_DRIVE3 ));

        //If the drive setting is not already set to maximum
        //Set it to max for LFXT startup
        if ((HWREG16(UCS_BASE + OFS_UCSCTL6) & XT1DRIVE_3) != XT1DRIVE_3)
                //Highest drive setting for XT1startup
                HWREG16(UCS_BASE + OFS_UCSCTL6_L) |= XT1DRIVE1_L + XT1DRIVE0_L;

        //Enable LF mode and clear xcap and bypass
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~(XTS + XCAP_3 + XT1BYPASS);
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= xcap;

        while (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1LFOFFG) {
                //Clear OSC flaut Flags fault flags
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1LFOFFG);

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        }

        //set requested Drive mode
        HWREG16(UCS_BASE + OFS_UCSCTL6) = ( HWREG16(UCS_BASE + OFS_UCSCTL6) &
                                            ~(XT1DRIVE_3)
                                            ) |
                                          (xt1drive);

        //Switch ON XT1 oscillator
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1OFF;
}

//*****************************************************************************
//
//! \brief Initializes the XT1 crystal oscillator in low frequency mode
//!
//! Initializes the XT1 crystal oscillator in high frequency mode. Loops until
//! all oscillator fault flags are cleared, with no timeout. See the device-
//! specific data sheet for appropriate drive settings.
//!
//! \param xt1drive is the target drive strength for the XT1 crystal
//!        oscillator.
//!        Valid values are:
//!        - \b UCS_XT1_DRIVE0
//!        - \b UCS_XT1_DRIVE1
//!        - \b UCS_XT1_DRIVE2
//!        - \b UCS_XT1_DRIVE3 [Default]
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return None
//
//*****************************************************************************
void UCS_HFXT1Start(uint16_t xt1drive
                    )
{
        //Check if drive value is the expected one
        if ((HWREG16(UCS_BASE + OFS_UCSCTL6) & XT1DRIVE_3) != xt1drive) {
                //Clear XT1drive field
                HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1DRIVE_3;

                //Set requested value
                HWREG16(UCS_BASE + OFS_UCSCTL6) |= xt1drive;
        }

        //Enable HF mode
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= XTS;

        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1BYPASS;

        // Check XT1 fault flags
        while ((HWREG8(UCS_BASE + OFS_UCSCTL7) & (XT1HFOFFG))) {
                //Clear OSC flaut Flags fault flags
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1HFOFFG);

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        }

        //Switch ON XT1 oscillator
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1OFF;
}

//*****************************************************************************
//
//! \brief Bypass the XT1 crystal oscillator
//!
//! Bypasses the XT1 crystal oscillator. Loops until all oscillator fault flags
//! are cleared, with no timeout.
//!
//! \param highOrLowFrequency selects high frequency or low frequency mode for
//!        XT1.
//!        Valid values are:
//!        - \b UCS_XT1_HIGH_FREQUENCY
//!        - \b UCS_XT1_LOW_FREQUENCY [Default]
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return None
//
//*****************************************************************************
void UCS_bypassXT1(uint8_t highOrLowFrequency
                   )
{
        assert((UCS_XT1_LOW_FREQUENCY == highOrLowFrequency) ||
               (UCS_XT1_HIGH_FREQUENCY == highOrLowFrequency )
               );

        //Enable HF/LF mode
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XTS;
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= highOrLowFrequency;

        //Switch OFF XT1 oscillator and enable BYPASS mode
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= (XT1BYPASS + XT1OFF);

        if (UCS_XT1_LOW_FREQUENCY == highOrLowFrequency) {
                while (HWREG8(UCS_BASE + OFS_UCSCTL7) & (XT1LFOFFG)) {
                        //Clear OSC flaut Flags fault flags
                        HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1LFOFFG);

                        // Clear the global fault flag. In case the XT1 caused the global fault
                        // flag to get set this will clear the global error condition. If any
                        // error condition persists, global flag will get again.
                        HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
                }
        } else {
                while (HWREG8(UCS_BASE + OFS_UCSCTL7) & (XT1HFOFFG)) {
                        //Clear OSC flaut Flags fault flags
                        HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1HFOFFG);

                        //Clear the global fault flag. In case the XT1 caused the global fault
                        //flag to get set this will clear the global error condition. If any
                        //error condition persists, global flag will get again.
                        HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
                }
        }

}

//*****************************************************************************
//
//! \brief Initializes the XT1 crystal oscillator in low frequency mode with
//! timeout
//!
//! Initializes the XT1 crystal oscillator in low frequency mode with timeout.
//! Loops until all oscillator fault flags are cleared or until a timeout
//! counter is decremented and equals to zero. See the device-specific
//! datasheet for appropriate drive settings.
//!
//! \param xt1drive is the target drive strength for the XT1 crystal
//!        oscillator.
//!        Valid values are:
//!        - \b UCS_XT1_DRIVE0
//!        - \b UCS_XT1_DRIVE1
//!        - \b UCS_XT1_DRIVE2
//!        - \b UCS_XT1_DRIVE3 [Default]
//! \param xcap is the selected capacitor value. This parameter selects the
//!        capacitors applied to the LF crystal (XT1) or resonator in the LF
//!        mode. The effective capacitance (seen by the crystal) is Ceff. (CXIN
//!        + 2 pF)/2. It is assumed that CXIN = CXOUT and that a parasitic
//!        capacitance of 2 pF is added by the package and the printed circuit
//!        board. For details about the typical internal and the effective
//!        capacitors, refer to the device-specific data sheet.
//!        Valid values are:
//!        - \b UCS_XCAP_0
//!        - \b UCS_XCAP_1
//!        - \b UCS_XCAP_2
//!        - \b UCS_XCAP_3 [Default]
//! \param timeout is the count value that gets decremented every time the loop
//!        that clears oscillator fault flags gets executed.
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL
//
//*****************************************************************************
bool UCS_LFXT1StartWithTimeout(uint16_t xt1drive,
                               uint8_t xcap,
                               uint16_t timeout
                               )
{
        assert((xcap == UCS_XCAP_0) ||
               (xcap == UCS_XCAP_1) ||
               (xcap == UCS_XCAP_2) ||
               (xcap == UCS_XCAP_3) );

        assert((xt1drive == UCS_XT1_DRIVE0 ) ||
               (xt1drive == UCS_XT1_DRIVE1 ) ||
               (xt1drive == UCS_XT1_DRIVE2 ) ||
               (xt1drive == UCS_XT1_DRIVE3 ));

        assert(timeout > 0);

        //If the drive setting is not already set to maximum
        //Set it to max for LFXT startup
        if ((HWREG16(UCS_BASE + OFS_UCSCTL6) & XT1DRIVE_3) != XT1DRIVE_3)
                //Highest drive setting for XT1startup
                HWREG16(UCS_BASE + OFS_UCSCTL6_L) |= XT1DRIVE1_L + XT1DRIVE0_L;

        //Enable LF mode and clear xcap and bypass
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~(XTS + XCAP_3 + XT1BYPASS);
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= xcap;

        do {
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1LFOFFG);

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        } while ((HWREG8(UCS_BASE + OFS_UCSCTL7) & XT1LFOFFG) && --timeout);

        if (timeout) {
                //set requested Drive mode
                HWREG16(UCS_BASE + OFS_UCSCTL6) = ( HWREG16(UCS_BASE + OFS_UCSCTL6) &
                                                    ~(XT1DRIVE_3)
                                                    ) |
                                                  (xt1drive);
                //Switch ON XT1 oscillator
                HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1OFF;

                return STATUS_SUCCESS;
        } else
                return STATUS_FAIL;
}

//*****************************************************************************
//
//! \brief Initializes the XT1 crystal oscillator in high frequency mode with
//! timeout
//!
//! Initializes the XT1 crystal oscillator in high frequency mode with timeout.
//! Loops until all oscillator fault flags are cleared or until a timeout
//! counter is decremented and equals to zero. See the device-specific data
//! sheet for appropriate drive settings.
//!
//! \param xt1drive is the target drive strength for the XT1 crystal
//!        oscillator.
//!        Valid values are:
//!        - \b UCS_XT1_DRIVE0
//!        - \b UCS_XT1_DRIVE1
//!        - \b UCS_XT1_DRIVE2
//!        - \b UCS_XT1_DRIVE3 [Default]
//! \param timeout is the count value that gets decremented every time the loop
//!        that clears oscillator fault flags gets executed.
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL
//
//*****************************************************************************
bool UCS_HFXT1StartWithTimeout(uint16_t xt1drive,
                               uint16_t timeout
                               )
{
        assert((xt1drive == UCS_XT1_DRIVE0 ) ||
               (xt1drive == UCS_XT1_DRIVE1 ) ||
               (xt1drive == UCS_XT1_DRIVE2 ) ||
               (xt1drive == UCS_XT1_DRIVE3 ));

        assert(timeout > 0);

        //Check if drive value is the expected one
        if ((HWREG16(UCS_BASE + OFS_UCSCTL6) & XT1DRIVE_3) != xt1drive) {
                //Clear XT1drive field
                HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1DRIVE_3;

                //Set requested value
                HWREG16(UCS_BASE + OFS_UCSCTL6) |= xt1drive;
        }

        //Enable HF mode
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= XTS;

        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1BYPASS;

        // Check XT1 fault flags
        do {
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1HFOFFG);

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        } while ((HWREG8(UCS_BASE + OFS_UCSCTL7) & ( XT1HFOFFG))
                 && --timeout);

        if (timeout) {
                //Switch ON XT1 oscillator
                HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT1OFF;

                return STATUS_SUCCESS;
        } else
                return STATUS_FAIL;
}

//*****************************************************************************
//
//! \brief Bypasses the XT1 crystal oscillator with time out
//!
//! Bypasses the XT1 crystal oscillator with time out. Loops until all
//! oscillator fault flags are cleared or until a timeout counter is
//! decremented and equals to zero.
//!
//! \param highOrLowFrequency selects high frequency or low frequency mode for
//!        XT1.
//!        Valid values are:
//!        - \b UCS_XT1_HIGH_FREQUENCY
//!        - \b UCS_XT1_LOW_FREQUENCY [Default]
//! \param timeout is the count value that gets decremented every time the loop
//!        that clears oscillator fault flags gets executed.
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL
//
//*****************************************************************************
bool UCS_bypassXT1WithTimeout(uint8_t highOrLowFrequency,
                              uint16_t timeout
                              )
{
        assert((UCS_XT1_LOW_FREQUENCY == highOrLowFrequency) ||
               (UCS_XT1_HIGH_FREQUENCY == highOrLowFrequency )
               );

        assert(timeout > 0);

        //Enable HF/LF mode
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XTS;
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= highOrLowFrequency;

        //Switch OFF XT1 oscillator  and enable bypass
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= (XT1BYPASS + XT1OFF);

        if (UCS_XT1_LOW_FREQUENCY == highOrLowFrequency) {
                do {
                        //Clear OSC flaut Flags fault flags
                        HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1LFOFFG);

                        // Clear the global fault flag. In case the XT1 caused the global fault
                        // flag to get set this will clear the global error condition. If any
                        // error condition persists, global flag will get again.
                        HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
                } while ((HWREG8(UCS_BASE + OFS_UCSCTL7) & (XT1LFOFFG)) && --timeout);

        } else {
                do {
                        //Clear OSC flaut Flags fault flags
                        HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT1HFOFFG);

                        //Clear the global fault flag. In case the XT1 caused the global fault
                        //flag to get set this will clear the global error condition. If any
                        //error condition persists, global flag will get again.
                        HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
                } while ((HWREG8(UCS_BASE + OFS_UCSCTL7) & (XT1HFOFFG)) && --timeout);
        }

        if (timeout)
                return STATUS_SUCCESS;
        else
                return STATUS_FAIL;
}

//*****************************************************************************
//
//! \brief Stops the XT1 oscillator using the XT1OFF bit.
//!
//!
//! \return None
//
//*****************************************************************************
void UCS_XT1Off(void)
{
        //Switch off XT1 oscillator
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= XT1OFF;
}

//*****************************************************************************
//
//! \brief Initializes the XT2 crystal oscillator
//!
//! Initializes the XT2 crystal oscillator, which supports crystal frequencies
//! between 4 MHz and 32 MHz, depending on the selected drive strength. Loops
//! until all oscillator fault flags are cleared, with no timeout. See the
//! device-specific data sheet for appropriate drive settings.
//!
//! \param xt2drive is the target drive strength for the XT2 crystal
//!        oscillator.
//!        Valid values are:
//!        - \b UCS_XT2DRIVE_4MHZ_8MHZ
//!        - \b UCS_XT2DRIVE_8MHZ_16MHZ
//!        - \b UCS_XT2DRIVE_16MHZ_24MHZ
//!        - \b UCS_XT2DRIVE_24MHZ_32MHZ [Default]
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return None
//
//*****************************************************************************
void UCS_XT2Start(uint16_t xt2drive
                  )
{
#if !defined (__CC430F5133__) || (__CC430F5135__) || (__CC430F5137__) || \
        (__CC430F6125__) || (__CC430F6126__) || (__CC430F6127__) || \
        (__CC430F6135__) || (__CC430F6137__) || (__CC430F5123__) || \
        (__CC430F5125__) || (__CC430F5143__) || (__CC430F5145__) || \
        (__CC430F5147__) || (__CC430F6143__) || (__CC430F6145__) || \
        (__CC430F6147__)

        //Check if drive value is the expected one
        if ((HWREG16(UCS_BASE + OFS_UCSCTL6) & XT2DRIVE_3) != xt2drive) {
                //Clear XT2drive field
                HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT2DRIVE_3;

                //Set requested value
                HWREG16(UCS_BASE + OFS_UCSCTL6) |= xt2drive;
        }
#endif

        //Enable XT2 and Switch on XT2 oscillator
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT2BYPASS;
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT2OFF;

        while (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG) {
                //Clear OSC flaut Flags
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT2OFFG);

#if defined (__CC430F5133__) || (__CC430F5135__) || (__CC430F5137__) || \
                (__CC430F6125__) || (__CC430F6126__) || (__CC430F6127__) || \
                (__CC430F6135__) || (__CC430F6137__) || (__CC430F5123__) || \
                (__CC430F5125__) || (__CC430F5143__) || (__CC430F5145__) || \
                (__CC430F5147__) || (__CC430F6143__) || (__CC430F6145__) || \
                (__CC430F6147__)
                // CC430 uses a different fault mechanism. It requires 3 VLO clock
                // cycles delay.If 20MHz CPU, 5000 clock cycles are required in worst
                // case.
                __delay_cycles(5000);
#endif

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        }
}

//*****************************************************************************
//
//! \brief Bypasses the XT2 crystal oscillator
//!
//! Bypasses the XT2 crystal oscillator, which supports crystal frequencies
//! between 4 MHz and 32 MHz. Loops until all oscillator fault flags are
//! cleared, with no timeout.
//!
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return None
//
//*****************************************************************************
void UCS_bypassXT2(void)
{
        //Switch on XT2 oscillator
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= ( XT2BYPASS + XT2OFF );

        while (HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG) {
                //Clear OSC flaut Flags
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT2OFFG);

#if defined (__CC430F5133__) || (__CC430F5135__) || (__CC430F5137__) || \
                (__CC430F6125__) || (__CC430F6126__) || (__CC430F6127__) || \
                (__CC430F6135__) || (__CC430F6137__) || (__CC430F5123__) || \
                (__CC430F5125__) || (__CC430F5143__) || (__CC430F5145__) || \
                (__CC430F5147__) || (__CC430F6143__) || (__CC430F6145__) || \
                (__CC430F6147__)
                // CC430 uses a different fault mechanism. It requires 3 VLO clock
                // cycles delay.If 20MHz CPU, 5000 clock cycles are required in worst
                // case.
                __delay_cycles(5000);
#endif

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        }
}

//*****************************************************************************
//
//! \brief Initializes the XT2 crystal oscillator with timeout
//!
//! Initializes the XT2 crystal oscillator, which supports crystal frequencies
//! between 4 MHz and 32 MHz, depending on the selected drive strength. Loops
//! until all oscillator fault flags are cleared or until a timeout counter is
//! decremented and equals to zero. See the device-specific data sheet for
//! appropriate drive settings.
//!
//! \param xt2drive is the target drive strength for the XT2 crystal
//!        oscillator.
//!        Valid values are:
//!        - \b UCS_XT2DRIVE_4MHZ_8MHZ
//!        - \b UCS_XT2DRIVE_8MHZ_16MHZ
//!        - \b UCS_XT2DRIVE_16MHZ_24MHZ
//!        - \b UCS_XT2DRIVE_24MHZ_32MHZ [Default]
//! \param timeout is the count value that gets decremented every time the loop
//!        that clears oscillator fault flags gets executed.
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL
//
//*****************************************************************************
bool UCS_XT2StartWithTimeout(uint16_t xt2drive,
                             uint16_t timeout
                             )
{
        assert(timeout > 0);

#if !defined (__CC430F5133__) || (__CC430F5135__) || (__CC430F5137__) || \
        (__CC430F6125__) || (__CC430F6126__) || (__CC430F6127__) || \
        (__CC430F6135__) || (__CC430F6137__) || (__CC430F5123__) || \
        (__CC430F5125__) || (__CC430F5143__) || (__CC430F5145__) || \
        (__CC430F5147__) || (__CC430F6143__) || (__CC430F6145__) || \
        (__CC430F6147__)
        //Check if drive value is the expected one
        if ((HWREG16(UCS_BASE + OFS_UCSCTL6) & XT2DRIVE_3) != xt2drive) {
                //Clear XT2drive field
                HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT2DRIVE_3;

                //Set requested value
                HWREG16(UCS_BASE + OFS_UCSCTL6) |= xt2drive;
        }

#endif

        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT2BYPASS;

        //Switch on XT2 oscillator
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~XT2OFF;

        do {
                //Clear OSC flaut Flags
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT2OFFG);

#if defined (__CC430F5133__) || (__CC430F5135__) || (__CC430F5137__) || \
                (__CC430F6125__) || (__CC430F6126__) || (__CC430F6127__) || \
                (__CC430F6135__) || (__CC430F6137__) || (__CC430F5123__) || \
                (__CC430F5125__) || (__CC430F5143__) || (__CC430F5145__) || \
                (__CC430F5147__) || (__CC430F6143__) || (__CC430F6145__) || \
                (__CC430F6147__)
                // CC430 uses a different fault mechanism. It requires 3 VLO clock
                // cycles delay.If 20MHz CPU, 5000 clock cycles are required in worst
                // case.
                __delay_cycles(5000);
#endif

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        } while ((HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG) && --timeout);

        if (timeout)
                return STATUS_SUCCESS;
        else
                return STATUS_FAIL;
}

//*****************************************************************************
//
//! \brief Bypasses the XT2 crystal oscillator with timeout
//!
//! Bypasses the XT2 crystal oscillator, which supports crystal frequencies
//! between 4 MHz and 32 MHz. Loops until all oscillator fault flags are
//! cleared or until a timeout counter is decremented and equals to zero.
//!
//! \param timeout is the count value that gets decremented every time the loop
//!        that clears oscillator fault flags gets executed.
//!
//! Modified bits of \b UCSCTL7 register, bits of \b UCSCTL6 register and bits
//! of \b SFRIFG register.
//!
//! \return STATUS_SUCCESS or STATUS_FAIL
//
//*****************************************************************************
bool UCS_bypassXT2WithTimeout(uint16_t timeout
                              )
{
        assert(timeout > 0);

        //Switch off XT2 oscillator and enable BYPASS mode
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= (XT2BYPASS + XT2OFF );

        do {
                //Clear OSC flaut Flags
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(XT2OFFG);

#if defined (__CC430F5133__) || (__CC430F5135__) || (__CC430F5137__) || \
                (__CC430F6125__) || (__CC430F6126__) || (__CC430F6127__) || \
                (__CC430F6135__) || (__CC430F6137__) || (__CC430F5123__) || \
                (__CC430F5125__) || (__CC430F5143__) || (__CC430F5145__) || \
                (__CC430F5147__) || (__CC430F6143__) || (__CC430F6145__) || \
                (__CC430F6147__)
                // CC430 uses a different fault mechanism. It requires 3 VLO clock
                // cycles delay.If 20MHz CPU, 5000 clock cycles are required in worst
                // case.
                __delay_cycles(5000);
#endif

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        } while ((HWREG8(UCS_BASE + OFS_UCSCTL7) & XT2OFFG) && --timeout);

        if (timeout)
                return STATUS_SUCCESS;
        else
                return STATUS_FAIL;
}

//*****************************************************************************
//
//! \brief Stops the XT2 oscillator using the XT2OFF bit.
//!
//!
//! Modified bits of \b UCSCTL6 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_XT2Off(void)
{
        //Switch off XT2 oscillator
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= XT2OFF;
}

//*****************************************************************************
//
//! \brief Initializes the DCO to operate a frequency that is a multiple of the
//! reference frequency into the FLL
//!
//! Initializes the DCO to operate a frequency that is a multiple of the
//! reference frequency into the FLL. Loops until all oscillator fault flags
//! are cleared, with a timeout. If the frequency is greater than 16 MHz, the
//! function sets the MCLK and SMCLK source to the undivided DCO frequency.
//! Otherwise, the function sets the MCLK and SMCLK source to the DCOCLKDIV
//! frequency. This function executes a software delay that is proportional in
//! length to the ratio of the target FLL frequency and the FLL reference.
//!
//! \param fsystem is the target frequency for MCLK in kHz
//! \param ratio is the ratio x/y, where x = fsystem and y = FLL reference
//!        frequency.
//!
//! Modified bits of \b UCSCTL0 register, bits of \b UCSCTL4 register, bits of
//! \b UCSCTL7 register, bits of \b UCSCTL1 register, bits of \b SFRIFG1
//! register and bits of \b UCSCTL2 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_initFLLSettle(uint16_t fsystem,
                       uint16_t ratio
                       )
{
        volatile uint16_t x = ratio * 32;

        UCS_initFLL(fsystem, ratio);

        while (x--)
                __delay_cycles(30);
}

//*****************************************************************************
//
//! \brief Initializes the DCO to operate a frequency that is a multiple of the
//! reference frequency into the FLL
//!
//! Initializes the DCO to operate a frequency that is a multiple of the
//! reference frequency into the FLL. Loops until all oscillator fault flags
//! are cleared, with no timeout. If the frequency is greater than 16 MHz, the
//! function sets the MCLK and SMCLK source to the undivided DCO frequency.
//! Otherwise, the function sets the MCLK and SMCLK source to the DCOCLKDIV
//! frequency.
//!
//! \param fsystem is the target frequency for MCLK in kHz
//! \param ratio is the ratio x/y, where x = fsystem and y = FLL reference
//!        frequency.
//!
//! Modified bits of \b UCSCTL0 register, bits of \b UCSCTL4 register, bits of
//! \b UCSCTL7 register, bits of \b UCSCTL1 register, bits of \b SFRIFG1
//! register and bits of \b UCSCTL2 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_initFLL(uint16_t fsystem,
                 uint16_t ratio
                 )
{
        uint16_t d, dco_div_bits;
        uint16_t mode = 0;

        //Save actual state of FLL loop control, then disable it. This is needed to
        //prevent the FLL from acting as we are making fundamental modifications to
        //the clock setup.
        uint16_t srRegisterState = __get_SR_register() & SCG0;

        d = ratio;
        //Have at least a divider of 2
        dco_div_bits = FLLD__2;

        if (fsystem > 16000) {
                d >>= 1;
                mode = 1;
        } else
                //fsystem = fsystem * 2
                fsystem <<= 1;

        while (d > 512) {
                //Set next higher div level
                dco_div_bits = dco_div_bits + FLLD0;
                d >>= 1;
        }

        // Disable FLL
        __bis_SR_register(SCG0);

        //Set DCO to lowest Tap
        HWREG8(UCS_BASE + OFS_UCSCTL0_H) = 0x0000;

        //Reset FN bits
        HWREG16(UCS_BASE + OFS_UCSCTL2) &= ~(0x03FF);
        HWREG16(UCS_BASE + OFS_UCSCTL2) = dco_div_bits | (d - 1);

        if (fsystem <= 630)             //fsystem < 0.63MHz
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_0;
        else if (fsystem <  1250)       //0.63MHz < fsystem < 1.25MHz
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_1;
        else if (fsystem <  2500)       //1.25MHz < fsystem <  2.5MHz
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_2;
        else if (fsystem <  5000)       //2.5MHz  < fsystem <    5MHz
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_3;
        else if (fsystem <  10000)      //5MHz    < fsystem <   10MHz
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_4;
        else if (fsystem <  20000)      //10MHz   < fsystem <   20MHz
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_5;
        else if (fsystem <  40000)      //20MHz   < fsystem <   40MHz
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_6;
        else
                HWREG8(UCS_BASE + OFS_UCSCTL1) = DCORSEL_7;

        // Re-enable FLL
        __bic_SR_register(SCG0);

        while (HWREG8(UCS_BASE + OFS_UCSCTL7_L) & DCOFFG) {
                //Clear OSC flaut Flags
                HWREG8(UCS_BASE + OFS_UCSCTL7_L) &= ~(DCOFFG);

                //Clear OFIFG fault flag
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;
        }

        // Restore previous SCG0
        __bis_SR_register(srRegisterState);

        if (mode == 1) {
                //fsystem > 16000
                //Select DCOCLK
                HWREG16(UCS_BASE + OFS_UCSCTL4) &=  ~(SELM_7 + SELS_7);
                HWREG16(UCS_BASE + OFS_UCSCTL4) |= SELM__DCOCLK + SELS__DCOCLK;
        } else {
                //Select DCODIVCLK
                HWREG16(UCS_BASE + OFS_UCSCTL4) &=  ~(SELM_7 + SELS_7);
                HWREG16(UCS_BASE + OFS_UCSCTL4) |= SELM__DCOCLKDIV + SELS__DCOCLKDIV;
        }

}

//*****************************************************************************
//
//! \brief Enables conditional module requests
//!
//! \param selectClock selects specific request enables
//!        Valid values are:
//!        - \b UCS_ACLK
//!        - \b UCS_SMCLK
//!        - \b UCS_MCLK
//!        - \b UCS_MODOSC
//!
//! Modified bits of \b UCSCTL8 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_enableClockRequest(uint8_t selectClock
                            )
{
        HWREG8(UCS_BASE + OFS_UCSCTL8) |= selectClock;
}

//*****************************************************************************
//
//! \brief Disables conditional module requests
//!
//! \param selectClock selects specific request disable
//!        Valid values are:
//!        - \b UCS_ACLK
//!        - \b UCS_SMCLK
//!        - \b UCS_MCLK
//!        - \b UCS_MODOSC
//!
//! Modified bits of \b UCSCTL8 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_disableClockRequest(uint8_t selectClock
                             )
{
        HWREG8(UCS_BASE + OFS_UCSCTL8) &= ~selectClock;
}

//*****************************************************************************
//
//! \brief Gets the current UCS fault flag status.
//!
//! \param mask is the masked interrupt flag status to be returned. Mask
//!        parameter can be either any of the following selection.
//!        Valid values are:
//!        - \b UCS_XT2OFFG - XT2 oscillator fault flag
//!        - \b UCS_XT1HFOFFG - XT1 oscillator fault flag (HF mode)
//!        - \b UCS_XT1LFOFFG - XT1 oscillator fault flag (LF mode)
//!        - \b UCS_DCOFFG - DCO fault flag
//!
//
//*****************************************************************************
uint8_t UCS_faultFlagStatus(uint8_t mask
                            )
{
        assert(mask <= UCS_XT2OFFG );
        return HWREG8(UCS_BASE + OFS_UCSCTL7) & mask;
}

//*****************************************************************************
//
//! \brief Clears the current UCS fault flag status for the masked bit.
//!
//! \param mask is the masked interrupt flag status to be returned. mask
//!        parameter can be any one of the following
//!        Valid values are:
//!        - \b UCS_XT2OFFG - XT2 oscillator fault flag
//!        - \b UCS_XT1HFOFFG - XT1 oscillator fault flag (HF mode)
//!        - \b UCS_XT1LFOFFG - XT1 oscillator fault flag (LF mode)
//!        - \b UCS_DCOFFG - DCO fault flag
//!
//! Modified bits of \b UCSCTL7 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_clearFaultFlag(uint8_t mask
                        )
{
        assert(mask <= UCS_XT2OFFG );
        HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~mask;
}

//*****************************************************************************
//
//! \brief Turns off SMCLK using the SMCLKOFF bit
//!
//!
//! Modified bits of \b UCSCTL6 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_SMCLKOff(void)
{
        HWREG16(UCS_BASE + OFS_UCSCTL6) |= SMCLKOFF;
}

//*****************************************************************************
//
//! \brief Turns ON SMCLK using the SMCLKOFF bit
//!
//!
//! Modified bits of \b UCSCTL6 register.
//!
//! \return None
//
//*****************************************************************************
void UCS_SMCLKOn(void)
{
        HWREG16(UCS_BASE + OFS_UCSCTL6) &= ~SMCLKOFF;
}

//*****************************************************************************
//
//! \brief Get the current ACLK frequency
//!
//! Get the current ACLK frequency. The user of this API must ensure that
//! UCS_setExternalClockSource API was invoked before in case XT1 or XT2 is
//! being used.
//!
//!
//! \return Current ACLK frequency in Hz
//
//*****************************************************************************
uint32_t UCS_getACLK(void)
{
        //Find ACLK source
        uint16_t ACLKSource = (HWREG16(UCS_BASE + OFS_UCSCTL4) & SELA_7);

        ACLKSource = ACLKSource >> 8;

        uint16_t ACLKSourceDivider =  HWREG16(UCS_BASE + OFS_UCSCTL5) & DIVA_7;
        ACLKSourceDivider = ACLKSourceDivider >> 8;

        return privateUCSComputeCLKFrequency(
                       ACLKSource,
                       ACLKSourceDivider
                       );
}

//*****************************************************************************
//
//! \brief Get the current SMCLK frequency
//!
//! Get the current SMCLK frequency. The user of this API must ensure that
//! UCS_setExternalClockSource API was invoked before in case XT1 or XT2 is
//! being used.
//!
//!
//! \return Current SMCLK frequency in Hz
//
//*****************************************************************************
uint32_t UCS_getSMCLK(void)
{
        uint16_t SMCLKSource = HWREG8(UCS_BASE + OFS_UCSCTL4_L) & SELS_7;

        SMCLKSource = SMCLKSource >> 4;

        uint16_t SMCLKSourceDivider =
                HWREG16(UCS_BASE + OFS_UCSCTL5) & DIVS_7;
        SMCLKSourceDivider = SMCLKSourceDivider >> 4;

        return privateUCSComputeCLKFrequency(
                       SMCLKSource,
                       SMCLKSourceDivider )
        ;
}

//*****************************************************************************
//
//! \brief Get the current MCLK frequency
//!
//! Get the current MCLK frequency. The user of this API must ensure that
//! UCS_setExternalClockSource API was invoked before in case XT1 or XT2 is
//! being used.
//!
//!
//! \return Current MCLK frequency in Hz
//
//*****************************************************************************
uint32_t UCS_getMCLK(void)
{
        //Find AMCLK source
        uint16_t MCLKSource = (HWREG16(UCS_BASE + OFS_UCSCTL4) & SELM_7);

        uint16_t MCLKSourceDivider =  HWREG16(UCS_BASE + OFS_UCSCTL5) & DIVM_7;

        return privateUCSComputeCLKFrequency(
                       MCLKSource,
                       MCLKSourceDivider )
        ;
}

//*****************************************************************************
//
//! \brief Clears all the Oscillator Flags
//!
//! \param timeout is the count value that gets decremented every time the loop
//!        that clears oscillator fault flags gets executed.
//!
//! \return Logical OR of any of the following:
//!         - \b UCS_XT2OFFG XT2 oscillator fault flag
//!         - \b UCS_XT1HFOFFG XT1 oscillator fault flag (HF mode)
//!         - \b UCS_XT1LFOFFG XT1 oscillator fault flag (LF mode)
//!         - \b UCS_DCOFFG DCO fault flag
//!         \n indicating the status of the oscillator fault flags
//
//*****************************************************************************
uint16_t UCS_clearAllOscFlagsWithTimeout(uint16_t timeout
                                         )
{
        assert(timeout > 0);

        do {
                // Clear all osc fault flags
                HWREG8(UCS_BASE + OFS_UCSCTL7) &= ~(DCOFFG +
                                                    XT1LFOFFG +
                                                    XT1HFOFFG +
                                                    XT2OFFG
                                                    );

#if defined (__CC430F5133__) || (__CC430F5135__) || (__CC430F5137__) || \
                (__CC430F6125__) || (__CC430F6126__) || (__CC430F6127__) || \
                (__CC430F6135__) || (__CC430F6137__) || (__CC430F5123__) || \
                (__CC430F5125__) || (__CC430F5143__) || (__CC430F5145__) || \
                (__CC430F5147__) || (__CC430F6143__) || (__CC430F6145__) || \
                (__CC430F6147__)
                // CC430 uses a different fault mechanism. It requires 3 VLO clock
                // cycles delay.If 20MHz CPU, 5000 clock cycles are required in worst
                // case.
                __delay_cycles(5000);
#endif

                // Clear the global osc fault flag.
                HWREG8(SFR_BASE + OFS_SFRIFG1) &= ~OFIFG;

                // Check XT1 fault flags
        } while ((HWREG8(SFR_BASE + OFS_SFRIFG1) & OFIFG) && --timeout);

        return HWREG8(UCS_BASE + OFS_UCSCTL7) & (DCOFFG +
                                                 XT1LFOFFG +
                                                 XT1HFOFFG +
                                                 XT2OFFG)
        ;
}

#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for ucs_api
//! @}
//
//*****************************************************************************

#endif
