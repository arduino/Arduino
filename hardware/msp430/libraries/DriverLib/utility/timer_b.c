//*****************************************************************************
//
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5969__) || defined(__MSP430F5529__) || defined(__MSP430FR5739__)

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
// timer_b.c - Driver for the timer_b Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup timer_b_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_TxB7__
#include "timer_b.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Private clock source divider helper function
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSourceDivider is the desired divider for the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//!
//! Modified bits of \b TBxCTL register and bits of \b TBxEX0 register.
//!
//! \return None
//
//*****************************************************************************
static void privateTimerBProcessClockSourceDivider(uint32_t baseAddress,
                                                   uint16_t clockSourceDivider)
{
        HWREG16(baseAddress + OFS_TBxCTL) &= ~ID__8;
        HWREG16(baseAddress + OFS_TBxEX0) &= ~TBIDEX_7;
        switch (clockSourceDivider) {
        case TIMER_B_CLOCKSOURCE_DIVIDER_1:
        case TIMER_B_CLOCKSOURCE_DIVIDER_2:
        case TIMER_B_CLOCKSOURCE_DIVIDER_4:
        case TIMER_B_CLOCKSOURCE_DIVIDER_8:
                HWREG16(baseAddress + OFS_TBxCTL) |= ((clockSourceDivider - 1) << 6);
                HWREG16(baseAddress + OFS_TBxEX0) = TBIDEX_0;
                break;

        case TIMER_B_CLOCKSOURCE_DIVIDER_3:
        case TIMER_B_CLOCKSOURCE_DIVIDER_5:
        case TIMER_B_CLOCKSOURCE_DIVIDER_6:
        case TIMER_B_CLOCKSOURCE_DIVIDER_7:
                HWREG16(baseAddress + OFS_TBxCTL) |= ID__1;
                HWREG16(baseAddress + OFS_TBxEX0) = (clockSourceDivider - 1);
                break;

        case TIMER_B_CLOCKSOURCE_DIVIDER_10:
        case TIMER_B_CLOCKSOURCE_DIVIDER_12:
        case TIMER_B_CLOCKSOURCE_DIVIDER_14:
        case TIMER_B_CLOCKSOURCE_DIVIDER_16:
                HWREG16(baseAddress + OFS_TBxCTL) |= ID__2;
                HWREG16(baseAddress + OFS_TBxEX0) = (clockSourceDivider / 2 - 1 );
                break;

        case TIMER_B_CLOCKSOURCE_DIVIDER_20:
        case TIMER_B_CLOCKSOURCE_DIVIDER_24:
        case TIMER_B_CLOCKSOURCE_DIVIDER_28:
        case TIMER_B_CLOCKSOURCE_DIVIDER_32:
                HWREG16(baseAddress + OFS_TBxCTL) |= ID__4;
                HWREG16(baseAddress + OFS_TBxEX0) = (clockSourceDivider / 4 - 1);
                break;
        case TIMER_B_CLOCKSOURCE_DIVIDER_40:
        case TIMER_B_CLOCKSOURCE_DIVIDER_48:
        case TIMER_B_CLOCKSOURCE_DIVIDER_56:
        case TIMER_B_CLOCKSOURCE_DIVIDER_64:
                HWREG16(baseAddress + OFS_TBxCTL) |= ID__8;
                HWREG16(baseAddress + OFS_TBxEX0) = (clockSourceDivider / 8 - 1);
                break;
        }
}

//*****************************************************************************
//
//! \brief Starts TIMER_B counter
//!
//! This function assumes that the timer has been previously configured using
//! TIMER_B_configureContinuousMode, TIMER_B_configureUpMode or
//! TIMER_B_configureUpDownMode.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param timerMode selects the mode of the timer
//!        Valid values are:
//!        - \b TIMER_B_STOP_MODE
//!        - \b TIMER_B_UP_MODE
//!        - \b TIMER_B_CONTINUOUS_MODE [Default]
//!        - \b TIMER_B_UPDOWN_MODE
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_startCounter( uint32_t baseAddress,
                           uint16_t timerMode
                           )
{
        assert(
                (TIMER_B_UPDOWN_MODE == timerMode) ||
                (TIMER_B_CONTINUOUS_MODE == timerMode) ||
                (TIMER_B_UP_MODE == timerMode)
                );

        HWREG16(baseAddress + OFS_TBxCTL) |= timerMode;
}

//*****************************************************************************
//
//! \brief Configures TIMER_B in continuous mode.
//!
//! This API does not start the timer. Timer needs to be started when required
//! using the TIMER_B_startCounter API.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerInterruptEnable_TBIE is to enable or disable TIMER_B interrupt
//!        Valid values are:
//!        - \b TIMER_B_TBIE_INTERRUPT_ENABLE
//!        - \b TIMER_B_TBIE_INTERRUPT_DISABLE [Default]
//! \param timerClear decides if TIMER_B clock divider, count direction, count
//!        need to be reset.
//!        Valid values are:
//!        - \b TIMER_B_DO_CLEAR
//!        - \b TIMER_B_SKIP_CLEAR [Default]
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_configureContinuousMode( uint32_t baseAddress,
                                      uint16_t clockSource,
                                      uint16_t clockSourceDivider,
                                      uint16_t timerInterruptEnable_TBIE,
                                      uint16_t timerClear
                                      )
{
        assert(
                (TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_ACLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_SMCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK == clockSource)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        assert(
                (TIMER_B_TBIE_INTERRUPT_ENABLE == timerInterruptEnable_TBIE) ||
                (TIMER_B_TBIE_INTERRUPT_DISABLE == timerInterruptEnable_TBIE)
                );

        assert(
                (TIMER_B_CLOCKSOURCE_DIVIDER_1 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_2 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_4 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_8 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_3 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_5 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_6 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_7 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_10 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_12 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_14 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_16 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_20 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_24 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_28 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_32 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_40 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_48 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_56 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_64 == clockSourceDivider)
                );

        privateTimerBProcessClockSourceDivider(baseAddress,
                                               clockSourceDivider
                                               );

        HWREG16(baseAddress +
                OFS_TBxCTL) &= ~(TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK +
                                 TIMER_B_UPDOWN_MODE +
                                 TIMER_B_DO_CLEAR +
                                 TIMER_B_TBIE_INTERRUPT_ENABLE +
                                 CNTL_3
                                 );

        HWREG16(baseAddress + OFS_TBxCTL)  |= ( clockSource +
                                                timerClear +
                                                timerInterruptEnable_TBIE);
}

//*****************************************************************************
//
//! \brief Configures TIMER_B in up mode.
//!
//! This API does not start the timer. Timer needs to be started when required
//! using the TIMER_B_startCounter API.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerPeriod is the specified TIMER_B period. This is the value that
//!        gets written into the CCR0. Limited to 16 bits[uint16_t]
//! \param timerInterruptEnable_TBIE is to enable or disable TIMER_B interrupt
//!        Valid values are:
//!        - \b TIMER_B_TBIE_INTERRUPT_ENABLE
//!        - \b TIMER_B_TBIE_INTERRUPT_DISABLE [Default]
//! \param captureCompareInterruptEnable_CCR0_CCIE is to enable or disable
//!        TIMER_B CCR0 capture compare interrupt.
//!        Valid values are:
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_DISABLE [Default]
//! \param timerClear decides if TIMER_B clock divider, count direction, count
//!        need to be reset.
//!        Valid values are:
//!        - \b TIMER_B_DO_CLEAR
//!        - \b TIMER_B_SKIP_CLEAR [Default]
//!
//! Modified bits of \b TBxCTL register, bits of \b TBxCCTL0 register and bits
//! of \b TBxCCR0 register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_configureUpMode(   uint32_t baseAddress,
                                uint16_t clockSource,
                                uint16_t clockSourceDivider,
                                uint16_t timerPeriod,
                                uint16_t timerInterruptEnable_TBIE,
                                uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                                uint16_t timerClear
                                )
{
        assert(
                (TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_ACLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_SMCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK == clockSource)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        privateTimerBProcessClockSourceDivider(baseAddress,
                                               clockSourceDivider
                                               );

        HWREG16(baseAddress + OFS_TBxCTL) &=
                ~(TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK +
                  TIMER_B_UPDOWN_MODE +
                  TIMER_B_DO_CLEAR +
                  TIMER_B_TBIE_INTERRUPT_ENABLE +
                  CNTL_3
                  );

        HWREG16(baseAddress + OFS_TBxCTL)  |= ( clockSource +
                                                timerClear +
                                                timerInterruptEnable_TBIE
                                                );

        if (TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE ==
            captureCompareInterruptEnable_CCR0_CCIE)
                HWREG16(baseAddress + OFS_TBxCCTL0)  |= TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;
        else
                HWREG16(baseAddress + OFS_TBxCCTL0)  &= ~TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;

        HWREG16(baseAddress + OFS_TBxCCR0)  = timerPeriod;
}

//*****************************************************************************
//
//! \brief Configures TIMER_B in up down mode.
//!
//! This API does not start the timer. Timer needs to be started when required
//! using the TIMER_B_startCounter API.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerPeriod is the specified TIMER_B period
//! \param timerInterruptEnable_TBIE is to enable or disable TIMER_B interrupt
//!        Valid values are:
//!        - \b TIMER_B_TBIE_INTERRUPT_ENABLE
//!        - \b TIMER_B_TBIE_INTERRUPT_DISABLE [Default]
//! \param captureCompareInterruptEnable_CCR0_CCIE is to enable or disable
//!        TIMER_B CCR0 capture compare interrupt.
//!        Valid values are:
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_DISABLE [Default]
//! \param timerClear decides if TIMER_B clock divider, count direction, count
//!        need to be reset.
//!        Valid values are:
//!        - \b TIMER_B_DO_CLEAR
//!        - \b TIMER_B_SKIP_CLEAR [Default]
//!
//! Modified bits of \b TBxCTL register, bits of \b TBxCCTL0 register and bits
//! of \b TBxCCR0 register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_configureUpDownMode(
        uint32_t baseAddress,
        uint16_t clockSource,
        uint16_t clockSourceDivider,
        uint16_t timerPeriod,
        uint16_t timerInterruptEnable_TBIE,
        uint16_t captureCompareInterruptEnable_CCR0_CCIE,
        uint16_t timerClear
        )
{
        assert(
                (TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_ACLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_SMCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK == clockSource)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        privateTimerBProcessClockSourceDivider(baseAddress,
                                               clockSourceDivider
                                               );

        HWREG16(baseAddress + OFS_TBxCTL) &=
                ~(TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK +
                  TIMER_B_UPDOWN_MODE +
                  TIMER_B_DO_CLEAR +
                  TIMER_B_TBIE_INTERRUPT_ENABLE +
                  CNTL_3
                  );

        HWREG16(baseAddress + OFS_TBxCTL)  |= ( clockSource +
                                                TIMER_B_STOP_MODE +
                                                timerClear +
                                                timerInterruptEnable_TBIE
                                                );
        if (TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE ==
            captureCompareInterruptEnable_CCR0_CCIE)
                HWREG16(baseAddress + OFS_TBxCCTL0)  |= TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;
        else
                HWREG16(baseAddress + OFS_TBxCCTL0)  &= ~TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;

        HWREG16(baseAddress + OFS_TBxCCR0)  = timerPeriod;
}

//*****************************************************************************
//
//! \brief DEPRECATED - Replaced by TIMER_B_configureContinuousMode and
//! TIMER_B_startCounter API. Starts TIMER_B in continuous mode.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerInterruptEnable_TBIE is to enable or disable TIMER_B interrupt
//!        Valid values are:
//!        - \b TIMER_B_TBIE_INTERRUPT_ENABLE
//!        - \b TIMER_B_TBIE_INTERRUPT_DISABLE [Default]
//! \param timerClear decides if TIMER_B clock divider, count direction, count
//!        need to be reset.
//!        Valid values are:
//!        - \b TIMER_B_DO_CLEAR
//!        - \b TIMER_B_SKIP_CLEAR [Default]
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_startContinuousMode( uint32_t baseAddress,
                                  uint16_t clockSource,
                                  uint16_t clockSourceDivider,
                                  uint16_t timerInterruptEnable_TBIE,
                                  uint16_t timerClear
                                  )
{
        assert(
                (TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_ACLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_SMCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK == clockSource)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        assert(
                (TIMER_B_TBIE_INTERRUPT_ENABLE == timerInterruptEnable_TBIE) ||
                (TIMER_B_TBIE_INTERRUPT_DISABLE == timerInterruptEnable_TBIE)
                );

        assert(
                (TIMER_B_CLOCKSOURCE_DIVIDER_1 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_2 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_4 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_8 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_3 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_5 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_6 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_7 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_10 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_12 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_14 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_16 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_20 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_24 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_28 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_32 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_40 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_48 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_56 == clockSourceDivider) ||
                (TIMER_B_CLOCKSOURCE_DIVIDER_64 == clockSourceDivider)
                );

        privateTimerBProcessClockSourceDivider(baseAddress,
                                               clockSourceDivider
                                               );

        HWREG16(baseAddress +
                OFS_TBxCTL) &= ~(TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK +
                                 TIMER_B_UPDOWN_MODE +
                                 TIMER_B_DO_CLEAR +
                                 TIMER_B_TBIE_INTERRUPT_ENABLE +
                                 CNTL_3
                                 );

        HWREG16(baseAddress + OFS_TBxCTL)  |= ( clockSource + TIMER_B_CONTINUOUS_MODE +
                                                timerClear +
                                                timerInterruptEnable_TBIE);
}

//*****************************************************************************
//
//! \brief DEPRECATED - Spelling Error Fixed. Starts TIMER_B in continuous
//! mode.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerInterruptEnable_TBIE is to enable or disable TIMER_B interrupt
//!        Valid values are:
//!        - \b TIMER_B_TBIE_INTERRUPT_ENABLE
//!        - \b TIMER_B_TBIE_INTERRUPT_DISABLE [Default]
//! \param timerClear decides if TIMER_B clock divider, count direction, count
//!        need to be reset.
//!        Valid values are:
//!        - \b TIMER_B_DO_CLEAR
//!        - \b TIMER_B_SKIP_CLEAR [Default]
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_startContinousMode( uint32_t baseAddress,
                                 uint16_t clockSource,
                                 uint16_t clockSourceDivider,
                                 uint16_t timerInterruptEnable_TBIE,
                                 uint16_t timerClear
                                 )
{
        TIMER_B_startContinuousMode(baseAddress,
                                    clockSource,
                                    clockSourceDivider,
                                    timerInterruptEnable_TBIE,
                                    timerClear
                                    );
}

//*****************************************************************************
//
//! \brief DEPRECATED - Replaced by TIMER_B_configureUpMode and
//! TIMER_B_startCounter API. Starts TIMER_B in up mode.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerPeriod is the specified TIMER_B period. This is the value that
//!        gets written into the CCR0. Limited to 16 bits[uint16_t]
//! \param timerInterruptEnable_TBIE is to enable or disable TIMER_B interrupt
//!        Valid values are:
//!        - \b TIMER_B_TBIE_INTERRUPT_ENABLE
//!        - \b TIMER_B_TBIE_INTERRUPT_DISABLE [Default]
//! \param captureCompareInterruptEnable_CCR0_CCIE is to enable or disable
//!        TIMER_B CCR0 capture compare interrupt.
//!        Valid values are:
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_DISABLE [Default]
//! \param timerClear decides if TIMER_B clock divider, count direction, count
//!        need to be reset.
//!        Valid values are:
//!        - \b TIMER_B_DO_CLEAR
//!        - \b TIMER_B_SKIP_CLEAR [Default]
//!
//! Modified bits of \b TBxCTL register, bits of \b TBxCCTL0 register and bits
//! of \b TBxCCR0 register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_startUpMode(   uint32_t baseAddress,
                            uint16_t clockSource,
                            uint16_t clockSourceDivider,
                            uint16_t timerPeriod,
                            uint16_t timerInterruptEnable_TBIE,
                            uint16_t captureCompareInterruptEnable_CCR0_CCIE,
                            uint16_t timerClear
                            )
{
        assert(
                (TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_ACLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_SMCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK == clockSource)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        privateTimerBProcessClockSourceDivider(baseAddress,
                                               clockSourceDivider
                                               );

        HWREG16(baseAddress + OFS_TBxCTL) &=
                ~(TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK +
                  TIMER_B_UPDOWN_MODE +
                  TIMER_B_DO_CLEAR +
                  TIMER_B_TBIE_INTERRUPT_ENABLE +
                  CNTL_3
                  );

        HWREG16(baseAddress + OFS_TBxCTL)  |= ( clockSource +
                                                TIMER_B_UP_MODE +
                                                timerClear +
                                                timerInterruptEnable_TBIE
                                                );

        if (TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE ==
            captureCompareInterruptEnable_CCR0_CCIE)
                HWREG16(baseAddress + OFS_TBxCCTL0)  |= TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;
        else
                HWREG16(baseAddress + OFS_TBxCCTL0)  &= ~TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;

        HWREG16(baseAddress + OFS_TBxCCR0)  = timerPeriod;
}

//*****************************************************************************
//
//! \brief DEPRECATED - Replaced by TIMER_B_configureUpDownMode and
//! TIMER_B_startCounter API. Starts TIMER_B in up down mode.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerPeriod is the specified TIMER_B period
//! \param timerInterruptEnable_TBIE is to enable or disable TIMER_B interrupt
//!        Valid values are:
//!        - \b TIMER_B_TBIE_INTERRUPT_ENABLE
//!        - \b TIMER_B_TBIE_INTERRUPT_DISABLE [Default]
//! \param captureCompareInterruptEnable_CCR0_CCIE is to enable or disable
//!        TIMER_B CCR0 capture compare interrupt.
//!        Valid values are:
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE
//!        - \b TIMER_B_CCIE_CCR0_INTERRUPT_DISABLE [Default]
//! \param timerClear decides if TIMER_B clock divider, count direction, count
//!        need to be reset.
//!        Valid values are:
//!        - \b TIMER_B_DO_CLEAR
//!        - \b TIMER_B_SKIP_CLEAR [Default]
//!
//! Modified bits of \b TBxCTL register, bits of \b TBxCCTL0 register and bits
//! of \b TBxCCR0 register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_startUpDownMode(
        uint32_t baseAddress,
        uint16_t clockSource,
        uint16_t clockSourceDivider,
        uint16_t timerPeriod,
        uint16_t timerInterruptEnable_TBIE,
        uint16_t captureCompareInterruptEnable_CCR0_CCIE,
        uint16_t timerClear
        )
{
        assert(
                (TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_ACLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_SMCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK == clockSource)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        assert(
                (TIMER_B_DO_CLEAR == timerClear) ||
                (TIMER_B_SKIP_CLEAR == timerClear)
                );

        privateTimerBProcessClockSourceDivider(baseAddress,
                                               clockSourceDivider
                                               );

        HWREG16(baseAddress + OFS_TBxCTL) &=
                ~(TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK +
                  TIMER_B_UPDOWN_MODE +
                  TIMER_B_DO_CLEAR +
                  TIMER_B_TBIE_INTERRUPT_ENABLE +
                  CNTL_3
                  );

        HWREG16(baseAddress + OFS_TBxCTL)  |= ( clockSource +
                                                TIMER_B_UPDOWN_MODE +
                                                timerClear +
                                                timerInterruptEnable_TBIE
                                                );
        if (TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE ==
            captureCompareInterruptEnable_CCR0_CCIE)
                HWREG16(baseAddress + OFS_TBxCCTL0)  |= TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;
        else
                HWREG16(baseAddress + OFS_TBxCCTL0)  &= ~TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;

        HWREG16(baseAddress + OFS_TBxCCR0)  = timerPeriod;
}

//*****************************************************************************
//
//! \brief Initializes Capture Mode
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureRegister selects the capture register being used. Refer to
//!        datasheet to ensure the device has the capture register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param captureMode is the capture mode selected.
//!        Valid values are:
//!        - \b TIMER_B_CAPTUREMODE_NO_CAPTURE [Default]
//!        - \b TIMER_B_CAPTUREMODE_RISING_EDGE
//!        - \b TIMER_B_CAPTUREMODE_FALLING_EDGE
//!        - \b TIMER_B_CAPTUREMODE_RISING_AND_FALLING_EDGE
//! \param captureInputSelect decides the Input Select
//!        Valid values are:
//!        - \b TIMER_B_CAPTURE_INPUTSELECT_CCIxA [Default]
//!        - \b TIMER_B_CAPTURE_INPUTSELECT_CCIxB
//!        - \b TIMER_B_CAPTURE_INPUTSELECT_GND
//!        - \b TIMER_B_CAPTURE_INPUTSELECT_Vcc
//! \param synchronizeCaptureSource decides if capture source should be
//!        synchronized with TIMER_B clock
//!        Valid values are:
//!        - \b TIMER_B_CAPTURE_ASYNCHRONOUS [Default]
//!        - \b TIMER_B_CAPTURE_SYNCHRONOUS
//! \param captureInterruptEnable is to enable or disable TIMER_B capture
//!        compare interrupt.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE [Default]
//!        - \b TIMER_B_CAPTURECOMPARE_INTERRUPT_ENABLE
//! \param captureOutputMode specifies the output mode.
//!        Valid values are:
//!        - \b TIMER_B_OUTPUTMODE_OUTBITVALUE [Default]
//!        - \b TIMER_B_OUTPUTMODE_SET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE_RESET
//!        - \b TIMER_B_OUTPUTMODE_SET_RESET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE
//!        - \b TIMER_B_OUTPUTMODE_RESET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE_SET
//!        - \b TIMER_B_OUTPUTMODE_RESET_SET
//!
//! Modified bits of \b TBxCCTLn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_initCapture(uint32_t baseAddress,
                         uint16_t captureRegister,
                         uint16_t captureMode,
                         uint16_t captureInputSelect,
                         uint16_t synchronizeCaptureSource,
                         uint16_t captureInterruptEnable,
                         uint16_t captureOutputMode
                         )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureRegister)
               );

        assert((TIMER_B_CAPTUREMODE_NO_CAPTURE == captureMode) ||
               (TIMER_B_CAPTUREMODE_RISING_EDGE == captureMode) ||
               (TIMER_B_CAPTUREMODE_FALLING_EDGE == captureMode) ||
               (TIMER_B_CAPTUREMODE_RISING_AND_FALLING_EDGE == captureMode)
               );

        assert((TIMER_B_CAPTURE_INPUTSELECT_CCIxA == captureInputSelect) ||
               (TIMER_B_CAPTURE_INPUTSELECT_CCIxB == captureInputSelect) ||
               (TIMER_B_CAPTURE_INPUTSELECT_GND == captureInputSelect) ||
               (TIMER_B_CAPTURE_INPUTSELECT_Vcc == captureInputSelect)
               );

        assert((TIMER_B_CAPTURE_ASYNCHRONOUS == synchronizeCaptureSource) ||
               (TIMER_B_CAPTURE_SYNCHRONOUS == synchronizeCaptureSource)
               );

        assert(
                (TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE == captureInterruptEnable) ||
                (TIMER_B_CAPTURECOMPARE_INTERRUPT_ENABLE == captureInterruptEnable)
                );

        assert((TIMER_B_OUTPUTMODE_OUTBITVALUE == captureOutputMode) ||
               (TIMER_B_OUTPUTMODE_SET == captureOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE_RESET == captureOutputMode) ||
               (TIMER_B_OUTPUTMODE_SET_RESET == captureOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE == captureOutputMode) ||
               (TIMER_B_OUTPUTMODE_RESET == captureOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE_SET == captureOutputMode) ||
               (TIMER_B_OUTPUTMODE_RESET_SET == captureOutputMode)
               );

        if (TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureRegister) {
                //CaptureCompare register 0 only supports certain modes
                assert((TIMER_B_OUTPUTMODE_OUTBITVALUE == captureOutputMode) ||
                       (TIMER_B_OUTPUTMODE_SET == captureOutputMode) ||
                       (TIMER_B_OUTPUTMODE_TOGGLE == captureOutputMode) ||
                       (TIMER_B_OUTPUTMODE_RESET == captureOutputMode)
                       );
        }

        HWREG16(baseAddress + captureRegister ) |=   CAP;

        HWREG16(baseAddress + captureRegister) &=
                ~(TIMER_B_CAPTUREMODE_RISING_AND_FALLING_EDGE +
                  TIMER_B_CAPTURE_INPUTSELECT_Vcc +
                  TIMER_B_CAPTURE_SYNCHRONOUS +
                  TIMER_B_DO_CLEAR +
                  TIMER_B_TBIE_INTERRUPT_ENABLE +
                  CM_3
                  );

        HWREG16(baseAddress + captureRegister)  |= (captureMode +
                                                    captureInputSelect +
                                                    synchronizeCaptureSource +
                                                    captureInterruptEnable +
                                                    captureOutputMode
                                                    );
}

//*****************************************************************************
//
//! \brief Initializes Compare Mode
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param compareRegister selects the compare register being used. Refer to
//!        datasheet to ensure the device has the compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param compareInterruptEnable is to enable or disable TIMER_B capture
//!        compare interrupt.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE [Default]
//!        - \b TIMER_B_CAPTURECOMPARE_INTERRUPT_ENABLE
//! \param compareOutputMode specifies the output mode.
//!        Valid values are:
//!        - \b TIMER_B_OUTPUTMODE_OUTBITVALUE [Default]
//!        - \b TIMER_B_OUTPUTMODE_SET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE_RESET
//!        - \b TIMER_B_OUTPUTMODE_SET_RESET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE
//!        - \b TIMER_B_OUTPUTMODE_RESET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE_SET
//!        - \b TIMER_B_OUTPUTMODE_RESET_SET
//! \param compareValue is the count to be compared with in compare mode
//!
//! Modified bits of \b TBxCCTLn register and bits of \b TBxCCRn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_initCompare(  uint32_t baseAddress,
                           uint16_t compareRegister,
                           uint16_t compareInterruptEnable,
                           uint16_t compareOutputMode,
                           uint16_t compareValue
                           )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == compareRegister)
               );

        assert((TIMER_B_CAPTURECOMPARE_INTERRUPT_ENABLE == compareInterruptEnable) ||
               (TIMER_B_CAPTURECOMPARE_INTERRUPT_DISABLE == compareInterruptEnable)
               );

        assert((TIMER_B_OUTPUTMODE_OUTBITVALUE == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_SET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE_RESET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_SET_RESET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_RESET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE_SET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_RESET_SET == compareOutputMode)
               );

        if (TIMER_B_CAPTURECOMPARE_REGISTER_0 == compareRegister) {
                //CaptureCompare register 0 only supports certain modes
                assert((TIMER_B_OUTPUTMODE_OUTBITVALUE == compareOutputMode) ||
                       (TIMER_B_OUTPUTMODE_SET == compareOutputMode) ||
                       (TIMER_B_OUTPUTMODE_TOGGLE == compareOutputMode) ||
                       (TIMER_B_OUTPUTMODE_RESET == compareOutputMode)
                       );
        }

        HWREG16(baseAddress + compareRegister ) &=   ~CAP;

        HWREG16(baseAddress + compareRegister) &=
                ~(TIMER_B_CAPTURECOMPARE_INTERRUPT_ENABLE +
                  TIMER_B_OUTPUTMODE_RESET_SET
                  );

        HWREG16(baseAddress + compareRegister)  |= ( compareInterruptEnable +
                                                     compareOutputMode
                                                     );

        HWREG16(baseAddress + compareRegister + OFS_TBxR) = compareValue;
}

//*****************************************************************************
//
//! \brief Enable TIMER_B interrupt
//!
//! Enables TIMER_B interrupt. Does not clear interrupt flags.
//!
//! \param baseAddress is the base address of the TIMER_B module.
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_enableInterrupt(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_TBxCTL) |= TBIE;
}

//*****************************************************************************
//
//! \brief Disable TIMER_B interrupt
//!
//! \param baseAddress is the base address of the TIMER_B module.
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_disableInterrupt(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_TBxCTL) &= ~TBIE;
}

//*****************************************************************************
//
//! \brief Get TIMER_B interrupt status
//!
//! \param baseAddress is the base address of the TIMER_B module.
//!
//! \return One of the following:
//!         - \b TIMER_B_INTERRUPT_NOT_PENDING
//!         - \b TIMER_B_INTERRUPT_PENDING
//!         \n indicating the status of the TIMER_B interrupt
//
//*****************************************************************************
uint32_t TIMER_B_getInterruptStatus(uint32_t baseAddress)
{
        return HWREG16(baseAddress + OFS_TBxCTL) & TBIFG;
}

//*****************************************************************************
//
//! \brief Enable capture compare interrupt
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//!
//! Modified bits of \b TBxCCTLn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_enableCaptureCompareInterrupt(uint32_t baseAddress,
                                           uint16_t captureCompareRegister
                                           )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureCompareRegister)
               );

        HWREG16(baseAddress + captureCompareRegister) |= CCIE;
}

//*****************************************************************************
//
//! \brief Disable capture compare interrupt
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//!
//! Modified bits of \b TBxCCTLn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_disableCaptureCompareInterrupt(uint32_t baseAddress,
                                            uint16_t captureCompareRegister
                                            )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureCompareRegister)
               );
        HWREG16(baseAddress + captureCompareRegister) &= ~CCIE;
}

//*****************************************************************************
//
//! \brief Return capture compare interrupt status
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param mask is the mask for the interrupt status
//!        Mask value is the logical OR of any of the following:
//!        - \b TIMER_B_CAPTURE_OVERFLOW
//!        - \b TIMER_B_CAPTURECOMPARE_INTERRUPT_FLAG
//!
//! \return Logical OR of any of the following:
//!         - \b TIMER_B_CAPTURE_OVERFLOW
//!         - \b TIMER_B_CAPTURECOMPARE_INTERRUPT_FLAG
//!         \n indicating the status of the masked interrupts
//
//*****************************************************************************
uint32_t TIMER_B_getCaptureCompareInterruptStatus(uint32_t baseAddress,
                                                  uint16_t captureCompareRegister,
                                                  uint16_t mask
                                                  )
{
        return HWREG16(baseAddress + captureCompareRegister) & mask;
}

//*****************************************************************************
//
//! \brief Reset/Clear the TIMER_B clock divider, count direction, count
//!
//! \param baseAddress is the base address of the TIMER_B module.
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_clear(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_TBxCTL) |= TBCLR;
}

//*****************************************************************************
//
//! \brief Get synchronized capturecompare input
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param synchronized selects the type of capture compare input
//!        Valid values are:
//!        - \b TIMER_B_READ_SYNCHRONIZED_CAPTURECOMPAREINPUT
//!        - \b TIMER_B_READ_CAPTURE_COMPARE_INPUT
//!
//! \return One of the following:
//!         - \b TIMER_B_CAPTURECOMPARE_INPUT_HIGH
//!         - \b TIMER_B_CAPTURECOMPARE_INPUT_LOW
//
//*****************************************************************************
uint8_t TIMER_B_getSynchronizedCaptureCompareInput
        (uint32_t baseAddress,
        uint16_t captureCompareRegister,
        uint16_t synchronized
        )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureCompareRegister)
               );

        assert((TIMER_B_READ_CAPTURE_COMPARE_INPUT == synchronized) ||
               (TIMER_B_READ_SYNCHRONIZED_CAPTURECOMPAREINPUT == synchronized)
               );

        if (HWREG16(baseAddress + captureCompareRegister) & synchronized)
                return TIMER_B_CAPTURECOMPARE_INPUT_HIGH;
        else
                return TIMER_B_CAPTURECOMPARE_INPUT_LOW;
}

//*****************************************************************************
//
//! \brief Get output bit for output mode
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//!
//! \return One of the following:
//!         - \b TIMER_B_OUTPUTMODE_OUTBITVALUE_HIGH
//!         - \b TIMER_B_OUTPUTMODE_OUTBITVALUE_LOW
//
//*****************************************************************************
uint8_t TIMER_B_getOutputForOutputModeOutBitValue
        (uint32_t baseAddress,
        uint16_t captureCompareRegister
        )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureCompareRegister)
               );

        if (HWREG16(baseAddress + captureCompareRegister) & OUT)
                return TIMER_B_OUTPUTMODE_OUTBITVALUE_HIGH;
        else
                return TIMER_B_OUTPUTMODE_OUTBITVALUE_LOW;
}

//*****************************************************************************
//
//! \brief Get current capturecompare count
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//!
//! \return Current count as uint16_t
//
//*****************************************************************************
uint16_t TIMER_B_getCaptureCompareCount
        (uint32_t baseAddress,
        uint16_t captureCompareRegister
        )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureCompareRegister)
               );

        return HWREG16(baseAddress + OFS_TBxR + captureCompareRegister);
}

//*****************************************************************************
//
//! \brief Set output bit for output mode
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param outputModeOutBitValue the value to be set for out bit
//!        Valid values are:
//!        - \b TIMER_B_OUTPUTMODE_OUTBITVALUE_HIGH
//!        - \b TIMER_B_OUTPUTMODE_OUTBITVALUE_LOW
//!
//! Modified bits of \b TBxCCTLn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_setOutputForOutputModeOutBitValue
        (uint32_t baseAddress,
        uint16_t captureCompareRegister,
        uint8_t outputModeOutBitValue
        )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureCompareRegister)
               );

        assert((TIMER_B_OUTPUTMODE_OUTBITVALUE_HIGH == outputModeOutBitValue) ||
               (TIMER_B_OUTPUTMODE_OUTBITVALUE_LOW == outputModeOutBitValue)
               );

        HWREG16(baseAddress + captureCompareRegister) &= ~OUT;
        HWREG16(baseAddress + captureCompareRegister) |= outputModeOutBitValue;
}

//*****************************************************************************
//
//! \brief Generate a PWM with TIMER_B running in up mode
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param clockSource selects the clock source
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK [Default]
//!        - \b TIMER_B_CLOCKSOURCE_ACLK
//!        - \b TIMER_B_CLOCKSOURCE_SMCLK
//!        - \b TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK
//! \param clockSourceDivider is the divider for Clock source.
//!        Valid values are:
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_1 [Default]
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_2
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_4
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_8
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_3
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_5
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_6
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_7
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_10
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_12
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_14
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_16
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_20
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_24
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_28
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_32
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_40
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_48
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_56
//!        - \b TIMER_B_CLOCKSOURCE_DIVIDER_64
//! \param timerPeriod selects the desired TIMER_B period
//! \param compareRegister selects the compare register being used. Refer to
//!        datasheet to ensure the device has the compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param compareOutputMode specifies the output mode.
//!        Valid values are:
//!        - \b TIMER_B_OUTPUTMODE_OUTBITVALUE [Default]
//!        - \b TIMER_B_OUTPUTMODE_SET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE_RESET
//!        - \b TIMER_B_OUTPUTMODE_SET_RESET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE
//!        - \b TIMER_B_OUTPUTMODE_RESET
//!        - \b TIMER_B_OUTPUTMODE_TOGGLE_SET
//!        - \b TIMER_B_OUTPUTMODE_RESET_SET
//! \param dutyCycle specifies the dutycycle for the generated waveform
//!
//! Modified bits of \b TBxCCTLn register, bits of \b TBxCTL register, bits of
//! \b TBxCCTL0 register and bits of \b TBxCCR0 register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_generatePWM(  uint32_t baseAddress,
                           uint16_t clockSource,
                           uint16_t clockSourceDivider,
                           uint16_t timerPeriod,
                           uint16_t compareRegister,
                           uint16_t compareOutputMode,
                           uint16_t dutyCycle
                           )
{
        assert(
                (TIMER_B_CLOCKSOURCE_EXTERNAL_TXCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_ACLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_SMCLK == clockSource) ||
                (TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK == clockSource)
                );

        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == compareRegister)
               );

        assert((TIMER_B_OUTPUTMODE_OUTBITVALUE == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_SET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE_RESET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_SET_RESET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_RESET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_TOGGLE_SET == compareOutputMode) ||
               (TIMER_B_OUTPUTMODE_RESET_SET == compareOutputMode)
               );

        privateTimerBProcessClockSourceDivider(baseAddress,
                                               clockSourceDivider
                                               );

        HWREG16(baseAddress + OFS_TBxCTL)  &=
                ~( TIMER_B_CLOCKSOURCE_INVERTED_EXTERNAL_TXCLK +
                   TIMER_B_UPDOWN_MODE + TIMER_B_DO_CLEAR +
                   TIMER_B_TBIE_INTERRUPT_ENABLE
                   );

        HWREG16(baseAddress + OFS_TBxCTL)  |= ( clockSource +
                                                TIMER_B_UP_MODE +
                                                TIMER_B_DO_CLEAR
                                                );

        HWREG16(baseAddress + OFS_TBxCCR0)  = timerPeriod;

        HWREG16(baseAddress + OFS_TBxCCTL0)  &=
                ~(TIMER_B_CAPTURECOMPARE_INTERRUPT_ENABLE +
                  TIMER_B_OUTPUTMODE_RESET_SET
                  );
        HWREG16(baseAddress + compareRegister)  |= compareOutputMode;

        HWREG16(baseAddress + compareRegister + OFS_TBxR) = dutyCycle;
}

//*****************************************************************************
//
//! \brief Stops the TIMER_B
//!
//! \param baseAddress is the base address of the TIMER_B module.
//!
//! Modified bits of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_stop( uint32_t baseAddress )
{
        HWREG16(baseAddress + OFS_TBxCTL)  &= ~MC_3;
        HWREG16(baseAddress + OFS_TBxCTL)  |= MC_0;
}

//*****************************************************************************
//
//! \brief Sets the value of the capture-compare register
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param compareRegister selects the compare register being used. Refer to
//!        datasheet to ensure the device has the compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param compareValue is the count to be compared with in compare mode
//!
//! Modified bits of \b TBxCCRn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_setCompareValue(  uint32_t baseAddress,
                               uint16_t compareRegister,
                               uint16_t compareValue
                               )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == compareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == compareRegister)
               );

        HWREG16(baseAddress + compareRegister + OFS_TBxR) = compareValue;
}

//*****************************************************************************
//
//! \brief Clears the TIMER_B TBIFG interrupt flag
//!
//! \param baseAddress is the base address of the TIMER_B module.
//!
//! Modified bits are \b TBIFG of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_clearTimerInterruptFlag(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_TBxCTL) &= ~TBIFG;
}

//*****************************************************************************
//
//! \brief Clears the capture-compare interrupt flag
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param captureCompareRegister selects the capture compare register being
//!        used. Refer to datasheet to ensure the device has the capture
//!        compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//!
//! Modified bits are \b CCIFG of \b TBxCCTLn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_clearCaptureCompareInterruptFlag(uint32_t baseAddress,
                                              uint16_t captureCompareRegister
                                              )
{
        assert((TIMER_B_CAPTURECOMPARE_REGISTER_0 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_1 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_2 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_3 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_4 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_5 == captureCompareRegister) ||
               (TIMER_B_CAPTURECOMPARE_REGISTER_6 == captureCompareRegister)
               );

        HWREG16(baseAddress + captureCompareRegister)  &= ~CCIFG;
}

//*****************************************************************************
//
//! \brief Selects TIMER_B counter length
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param counterLength selects the value of counter length.
//!        Valid values are:
//!        - \b TIMER_B_COUNTER_16BIT [Default]
//!        - \b TIMER_B_COUNTER_12BIT
//!        - \b TIMER_B_COUNTER_10BIT
//!        - \b TIMER_B_COUNTER_8BIT
//!
//! Modified bits are \b CNTL of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_selectCounterLength(uint16_t baseAddress,
                                 uint16_t counterLength
                                 )
{
        assert((TIMER_B_COUNTER_8BIT == counterLength) ||
               (TIMER_B_COUNTER_10BIT == counterLength) ||
               (TIMER_B_COUNTER_12BIT == counterLength) ||
               (TIMER_B_COUNTER_16BIT == counterLength)
               );

        HWREG16(baseAddress + OFS_TBxCTL) &= ~CNTL_3;
        HWREG16(baseAddress + OFS_TBxCTL) |= counterLength;
}

//*****************************************************************************
//
//! \brief Selects TIMER_B Latching Group
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param groupLatch selects the latching group.
//!        Valid values are:
//!        - \b TIMER_B_GROUP_NONE [Default]
//!        - \b TIMER_B_GROUP_CL12_CL23_CL56
//!        - \b TIMER_B_GROUP_CL123_CL456
//!        - \b TIMER_B_GROUP_ALL
//!
//! Modified bits are \b TBCLGRP of \b TBxCTL register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_selectLatchingGroup(uint16_t baseAddress,
                                 uint16_t groupLatch)
{
        assert((TIMER_B_GROUP_NONE  == groupLatch) ||
               (TIMER_B_GROUP_CL12_CL23_CL56 == groupLatch) ||
               (TIMER_B_GROUP_CL123_CL456 == groupLatch) ||
               (TIMER_B_GROUP_ALL == groupLatch)
               );

        HWREG16(baseAddress + OFS_TBxCTL) &= ~TBCLGRP_3;
        HWREG16(baseAddress + OFS_TBxCTL) |= groupLatch;
}

//*****************************************************************************
//
//! \brief Selects Compare Latch Load Event
//!
//! \param baseAddress is the base address of the TIMER_B module.
//! \param compareRegister selects the compare register being used. Refer to
//!        datasheet to ensure the device has the compare register being used.
//!        Valid values are:
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_0
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_1
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_2
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_3
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_4
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_5
//!        - \b TIMER_B_CAPTURECOMPARE_REGISTER_6
//! \param compareLatchLoadEvent selects the latch load event
//!        Valid values are:
//!        - \b TIMER_B_LATCH_ON_WRITE_TO_TBxCCRn_COMPARE_REGISTER [Default]
//!        - \b TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_0_IN_UP_OR_CONT_MODE
//!        - \b TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_0_IN_UPDOWN_MODE
//!        - \b
//!           TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_CURRENT_COMPARE_LATCH_VALUE
//!
//! Modified bits are \b CLLD of \b TBxCCTLn register.
//!
//! \return None
//
//*****************************************************************************
void TIMER_B_initCompareLatchLoadEvent(uint16_t baseAddress,
                                       uint16_t compareRegister,
                                       uint16_t compareLatchLoadEvent
                                       )
{
        assert((TIMER_B_LATCH_ON_WRITE_TO_TBxCCRn_COMPARE_REGISTER  == compareLatchLoadEvent) ||
               (TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_0_IN_UP_OR_CONT_MODE == compareLatchLoadEvent) ||
               (TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_0_IN_UPDOWN_MODE == compareLatchLoadEvent) ||
               (TIMER_B_LATCH_WHEN_COUNTER_COUNTS_TO_CURRENT_COMPARE_LATCH_VALUE == compareLatchLoadEvent)
               );

        HWREG16(baseAddress + compareRegister)  &= ~CLLD_3;
        HWREG16(baseAddress + compareRegister)  |= compareLatchLoadEvent;
}

//*****************************************************************************
//
//! \brief Reads the current timer count value
//!
//! Reads the current count value of the timer. There is a majority vote system
//! in place to confirm an accurate value is returned. The TIMER_B_THRESHOLD
//! #define in the associated header file can be modified so that the votes
//! must be closer together for a consensus to occur.
//!
//! \param baseAddress is the base address of the Timer module.
//!
//! \return Majority vote of timer count value
//
//*****************************************************************************
uint16_t TIMER_B_getCounterValue(uint32_t baseAddress)
{
        uint16_t voteOne, voteTwo, res;

        voteTwo = HWREG16(baseAddress + OFS_TBxR);

        do {
                voteOne = voteTwo;
                voteTwo = HWREG16(baseAddress + OFS_TBxR);

                if (voteTwo > voteOne)
                        res = voteTwo - voteOne;
                else if (voteOne > voteTwo)
                        res = voteOne - voteTwo;
                else
                        res = 0;

        } while ( res > TIMER_B_THRESHOLD);

        return voteTwo;
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for timer_b_api
//! @}
//
//*****************************************************************************

#endif
