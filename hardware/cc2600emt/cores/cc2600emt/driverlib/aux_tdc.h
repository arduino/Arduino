/******************************************************************************
*  Filename:       aux_tdc.h
*  Revised:        2015-01-14 12:12:44 +0100 (on, 14 jan 2015)
*  Revision:       42373
*
*  Description:    Defines and prototypes for the AUX Time-to-Digital Converter
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

//*****************************************************************************
//
//! \addtogroup auxtdc_api
//! @{
//
//*****************************************************************************

#ifndef __AUX_TDC_H__
#define __AUX_TDC_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>
#include <inc/hw_types.h>
#include <inc/hw_memmap.h>
#include <inc/hw_ints.h>
#include <inc/hw_aux_tdc.h>
#include <driverlib/debug.h>

//*****************************************************************************
//
// Support for DriverLib in ROM:
// This section renames all functions that are not "static inline", so that
// calling these functions will default to implementation in flash. At the end
// of this file a second renaming will change the defaults to implementation in
// ROM for available functions.
//
// To force use of the implementation in flash, e.g. for debugging:
// - Globally: Define DRIVERLIB_NOROM at project level
// - Per function: Use prefix "NOROM_" when calling the function
//
// Do not define DRIVERLIB_GENERATE_ROM!
//
//*****************************************************************************
#ifndef DRIVERLIB_GENERATE_ROM
    #define AUXTDCConfigSet                 NOROM_AUXTDCConfigSet
    #define AUXTDCMeasurementDone           NOROM_AUXTDCMeasurementDone
#endif

//*****************************************************************************
//
// Defines for the status of a AUX TDC measurement.
//
//*****************************************************************************
#define AUX_TDC_BUSY            0x00000001
#define AUX_TDC_TIMEOUT         0x00000002
#define AUX_TDC_DONE            0x00000004

//*****************************************************************************
//
// Defines for the control of a AUX TDC.
//
//*****************************************************************************
#define AUX_TDC_RUNSYNC         0x00000001
#define AUX_TDC_RUN             0x00000002
#define AUX_TDC_ABORT           0x00000003

//*****************************************************************************
//
// Defines for possible states of the TDC internal state machine.
//
//*****************************************************************************
#define AUXTDC_WAIT_START         AUX_TDC_STAT_STATE_WAIT_START
#define AUXTDC_WAIT_START_CNTEN   AUX_TDC_STAT_STATE_WAIT_START_STOP_CNT_EN
#define AUXTDC_IDLE               AUX_TDC_STAT_STATE_IDLE
#define AUXTDC_CLRCNT             AUX_TDC_STAT_STATE_CLR_CNT
#define AUXTDC_WAIT_STOP          AUX_TDC_STAT_STATE_WAIT_STOP
#define AUXTDC_WAIT_STOP_CNTDOWN  AUX_TDC_STAT_STATE_WAIT_STOP_CNTDWN
#define AUXTDC_GETRESULTS         AUX_TDC_STAT_STATE_GET_RESULT
#define AUXTDC_POR                AUX_TDC_STAT_STATE_POR
#define AUXTDC_WAIT_CLRCNT_DONE   AUX_TDC_STAT_STATE_WAIT_CLR_CNT_DONE
#define AUXTDC_START_FALL         AUX_TDC_STAT_STATE_START_FALL
#define AUXTDC_FORCE_STOP         AUX_TDC_STAT_STATE_FORCE_STOP

//*****************************************************************************
//
// Defines for controlling the AUX TDC. Values can be passed to AUXTDCConfig().
//
//*****************************************************************************
#define AUXTDC_STOPPOL_RIS      0x00000000  // Rising edge polarity for stop
                                            // event
#define AUXTDC_STOPPOL_FALL     0x00002000  // Falling edge polarity for stop
                                            // event
#define AUXTDC_STOP_AON_WUC     0x00000000
#define AUXTDC_STOP_CMP_A       0x00000100
#define AUXTDC_STOP_CMP_B       0x00000200
#define AUXTDC_STOP_CS_RESET    0x00000300
#define AUXTDC_STOP_TIMER0      0x00000400
#define AUXTDC_STOP_TIMER1      0x00000500
#define AUXTDC_STOP_ADC_DONE    0x00000700
#define AUXTDC_STOP_AIO0        0x00000D00
#define AUXTDC_STOP_AIO1        0x00000E00
#define AUXTDC_STOP_AIO2        0x00000F00
#define AUXTDC_STOP_AIO3        0x00001000
#define AUXTDC_STOP_AIO4        0x00001100
#define AUXTDC_STOP_AIO5        0x00001200
#define AUXTDC_STOP_AIO6        0x00001300
#define AUXTDC_STOP_AIO7        0x00001400
#define AUXTDC_STOP_AIO8        0x00001500
#define AUXTDC_STOP_AIO9        0x00001600
#define AUXTDC_STOP_AIO10       0x00001700
#define AUXTDC_STOP_AIO11       0x00001800
#define AUXTDC_STOP_AIO12       0x00001900
#define AUXTDC_STOP_AIO13       0x00001A00
#define AUXTDC_STOP_AIO14       0x00001B00
#define AUXTDC_STOP_AIO15       0x00001C00
#define AUXTDC_STOP_ACLK        0x00001D00
#define AUXTDC_STOP_MCU_EVT     0x00001E00
#define AUXTDC_STOP_PRESCALER   0x00001F00

#define AUXTDC_STARTPOL_RIS     0x00000000  // Rising edge polarity for start
                                            // event
#define AUXTDC_STARTPOL_FALL    0x00002000  // Falling edge polarity for start
                                            // event
#define AUXTDC_START_AON_WUC    0x00000000
#define AUXTDC_START_CMP_A      0x00000001
#define AUXTDC_START_CMP_B      0x00000002
#define AUXTDC_START_CS_RESET   0x00000003
#define AUXTDC_START_TIMER0     0x00000004
#define AUXTDC_START_TIMER1     0x00000005
#define AUXTDC_START_ADC_DONE   0x00000007
#define AUXTDC_START_AIO0       0x0000000D
#define AUXTDC_START_AIO1       0x0000000E
#define AUXTDC_START_AIO2       0x0000000F
#define AUXTDC_START_AIO3       0x00000010
#define AUXTDC_START_AIO4       0x00000011
#define AUXTDC_START_AIO5       0x00000012
#define AUXTDC_START_AIO6       0x00000013
#define AUXTDC_START_AIO7       0x00000014
#define AUXTDC_START_AIO8       0x00000015
#define AUXTDC_START_AIO9       0x00000016
#define AUXTDC_START_AIO10      0x00000017
#define AUXTDC_START_AIO11      0x00000018
#define AUXTDC_START_AIO12      0x00000019
#define AUXTDC_START_AIO13      0x0000001A
#define AUXTDC_START_AIO14      0x0000001B
#define AUXTDC_START_AIO15      0x0000001C
#define AUXTDC_START_ACLK       0x0000001D
#define AUXTDC_START_MCU_EVT    0x0000001E
#define AUXTDC_START_PRESCALER  0x0000001F

//*****************************************************************************
//
// Defines for the possible saturation values set using AUXTDCLimitSet().
//
//*****************************************************************************
#define AUXTDC_SAT_512          0x00000000
#define AUXTDC_SAT_1024         0x00000001
#define AUXTDC_SAT_2048         0x00000002
#define AUXTDC_SAT_4096         0x00000003
#define AUXTDC_SAT_8192         0x00000004
#define AUXTDC_SAT_16384        0x00000005
#define AUXTDC_SAT_32768        0x00000006
#define AUXTDC_SAT_65536        0x00000007
#define AUXTDC_SAT_131072       0x00000008
#define AUXTDC_SAT_262144       0x00000009
#define AUXTDC_SAT_524288       0x0000000A
#define AUXTDC_SAT_1048576      0x0000000B
#define AUXTDC_SAT_2097152      0x0000000C
#define AUXTDC_SAT_4194304      0x0000000D
#define AUXTDC_SAT_8388608      0x0000000E
#define AUXTDC_SAT_WRAP_AROUND  0x0000000F
#define AUXTDC_NUM_SAT_VALS     16

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

#ifdef DRIVERLIB_DEBUG
//*****************************************************************************
//
//! \internal
//! \brief Checks an AUX TDC base address.
//!
//! This function determines if a AUX TDC port base address is valid.
//!
//! \param ui32Base is the base address of the AUX TDC port.
//!
//! \return Returns \c true if the base address is valid and \c false
//! otherwise.
//
//*****************************************************************************
static bool
AUXTDCBaseValid(uint32_t ui32Base)
{
    return(ui32Base == AUX_TDCIF_BASE);
}
#endif

//*****************************************************************************
//
//! \brief Get the status of the AUX TDC internal state machine.
//!
//! This function will return the current state of the AUX TDC internal state
//! machine.
//! \param ui32Base is base address of the AUX TDC
//!
//! \return Returns the current state of the state machine.
//! Possible states for the state machine are:
//! - \ref AUXTDC_WAIT_START
//! - \ref AUXTDC_WAIT_START_CNTEN
//! - \ref AUXTDC_IDLE
//! - \ref AUXTDC_CLRCNT
//! - \ref AUXTDC_WAIT_STOP
//! - \ref AUXTDC_WAIT_STOP_CNTDOWN
//! - \ref AUXTDC_GETRESULTS
//! - \ref AUXTDC_POR
//! - \ref AUXTDC_WAIT_CLRCNT_DONE
//! - \ref AUXTDC_START_FALL
//! - \ref AUXTDC_FORCE_STOP.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AUXTDCStatusGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Return the status value for the correct ADI Slave.
    //
    return((HWREG(ui32Base + AUX_TDC_O_STAT) & AUX_TDC_STAT_STATE_M) >>
           AUX_TDC_STAT_STATE_S);
}

//*****************************************************************************
//
//! \brief Configure the operation of the AUX TDC.
//!
//! Use this function to configure the start and stop event for the AUX TDC.
//!
//! The \c ui32StartCondition must be a bitwise OR of the start event and the
//! polarity of the start event. The start events are:
//! - \ref AUXTDC_START_AON_WUC
//! - \ref AUXTDC_START_CMP_A
//! - \ref AUXTDC_START_CMP_B
//! - \ref AUXTDC_START_CS_RESET
//! - \ref AUXTDC_START_TIMER0
//! - \ref AUXTDC_START_TIMER1
//! - \ref AUXTDC_START_ADC_DONE
//! - \ref AUXTDC_START_AIO0
//! - \ref AUXTDC_START_AIO1
//! - \ref AUXTDC_START_AIO2
//! - \ref AUXTDC_START_AIO3
//! - \ref AUXTDC_START_AIO4
//! - \ref AUXTDC_START_AIO5
//! - \ref AUXTDC_START_AIO6
//! - \ref AUXTDC_START_AIO7
//! - \ref AUXTDC_START_AIO8
//! - \ref AUXTDC_START_AIO9
//! - \ref AUXTDC_START_AIO10
//! - \ref AUXTDC_START_AIO11
//! - \ref AUXTDC_START_AIO12
//! - \ref AUXTDC_START_AIO13
//! - \ref AUXTDC_START_AIO14
//! - \ref AUXTDC_START_AIO15
//! - \ref AUXTDC_START_ACLK
//! - \ref AUXTDC_START_MCU_EVT
//! - \ref AUXTDC_START_PRESCALER
//!
//! The polarity of the start event is either rising \ref AUXTDC_STARTPOL_RIS
//! or falling \ref AUXTDC_STARTPOL_FALL.
//!
//! The \c ui32StopCondition must be a bitwise OR of the stop event and the
//! polarity of the stop event. The stop events are:
//! - \ref AUXTDC_STOP_AON_WUC
//! - \ref AUXTDC_STOP_CMP_A
//! - \ref AUXTDC_STOP_CMP_B
//! - \ref AUXTDC_STOP_CS_RESET
//! - \ref AUXTDC_STOP_TIMER0
//! - \ref AUXTDC_STOP_TIMER1
//! - \ref AUXTDC_STOP_ADC_DONE
//! - \ref AUXTDC_STOP_AIO0
//! - \ref AUXTDC_STOP_AIO1
//! - \ref AUXTDC_STOP_AIO2
//! - \ref AUXTDC_STOP_AIO3
//! - \ref AUXTDC_STOP_AIO4
//! - \ref AUXTDC_STOP_AIO5
//! - \ref AUXTDC_STOP_AIO6
//! - \ref AUXTDC_STOP_AIO7
//! - \ref AUXTDC_STOP_AIO8
//! - \ref AUXTDC_STOP_AIO9
//! - \ref AUXTDC_STOP_AIO10
//! - \ref AUXTDC_STOP_AIO11
//! - \ref AUXTDC_STOP_AIO12
//! - \ref AUXTDC_STOP_AIO13
//! - \ref AUXTDC_STOP_AIO14
//! - \ref AUXTDC_STOP_AIO15
//! - \ref AUXTDC_STOP_ACLK
//! - \ref AUXTDC_STOP_MCU_EVT
//! - \ref AUXTDC_STOP_PRESCALER
//!
//! The polarity of the stop event is either rising \ref AUXTDC_STOPPOL_RIS
//! or falling \ref AUXTDC_STOPPOL_FALL.
//!
//! \note The AUX TDC should only be configured when the AUX TDC is in the Idle
//! state. To ensure that software does not lock up, it is recommended to
//! ensure that the AUX TDC is actually in idle when calling AUXTDCConfigSet().
//! This can be tested using AUXTDCIdle().
//!
//! \param ui32Base is base address of the AUX TDC.
//! \param ui32StartCondition is AUX TDC a bitwise OR of a start event and polarity.
//! \param ui32StopCondition is AUX TDC a bitwise OR of a stop event and polarity.
//!
//! \return None
//!
//! \sa AUXTDCConfigSet(), AUXTDCIdle()
//
//*****************************************************************************
extern void AUXTDCConfigSet(uint32_t ui32Base, uint32_t ui32StartCondition,
                            uint32_t ui32StopCondition);

//*****************************************************************************
//
//! \brief Check if the AUX TDC is in idle mode.
//!
//! This function can be used to check whether the AUX TDC internal state
//! machine is in idle mode. This is required before setting the polarity
//! of the start and stop event.
//!
//! \param ui32Base is the base address of the AUX TDC.
//!
//! \return Returns \c true if state machine is in idle and returns \c false
//! if the state machine is in any other state.
//
//*****************************************************************************
__STATIC_INLINE bool
AUXTDCIdle(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Check if the AUX TDC is in the Idle state.
    //
    return (((HWREG(ui32Base + AUX_TDC_O_STAT) & AUX_TDC_STAT_STATE_M) ==
             AUX_TDC_STAT_STATE_IDLE) ? true : false);
}

//*****************************************************************************
//
//! \brief Enable the AUX TDC for a measurement.
//!
//! This function is used for arming the AUX TDC to begin a measurement as
//! soon as the start condition is met. There are two run modes:
//! \ref AUX_TDC_RUNSYNC will wait for a falling event of the start pulse before
//! starting measurement on next rising edge of start. This guarantees an edge
//! triggered start and is recommended for frequency measurements. If the
//! first falling edge is close to the start command it may be missed, but
//! the TDC shall catch later falling edges and in any case guarantee a
//! measurement start synchronous to the rising edge of the start event.
//! The \ref AUX_TDC_RUN is asynchronous start and asynchronous stop mode. Using
//! this a TDC measurement may start immediately if start is high and hence it
//! may not give precise edge to edge measurements. This mode is only
//! recommended when start pulse is guaranteed to arrive at least 7 clock
//! periods after command.
//!
//! \note The AUX TDC should be configured and in Idle mode before calling this
//! function.
//!
//! \param ui32Base is the base address of the AUX TDC.
//! \param ui32RunMode is the run mode for the AUX TDC.
//! - \ref AUX_TDC_RUNSYNC : Synchronous run mode.
//! - \ref AUX_TDC_RUN : Asynchronous run mode.
//!
//! \return None
//
//*****************************************************************************
__STATIC_INLINE void
AUXTDCEnable(uint32_t ui32Base, uint32_t ui32RunMode)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));
    ASSERT((ui32RunMode == AUX_TDC_RUN) ||
           (ui32RunMode == AUX_TDC_RUNSYNC));

    //
    // Enable the AUX TDC.
    //
    HWREG(ui32Base + AUX_TDC_O_CTL) = ui32RunMode;
}

//*****************************************************************************
//
//! \brief Force the AUX TDC back to Idle mode.
//!
//! This function will force the AUX TDC in Idle mode. The internal state
//! machine will not go directly to Idle mode, so it is left to the programmer to
//! ensure that the state machine is in Idle mode before doing any new
//! configuration. This can be checked using AUXTDCIdle().
//!
//! \param ui32Base is the base address of the AUX TDC.
//!
//! \return None
//!
//! \sa AUXTDCIdle()
//
//*****************************************************************************
__STATIC_INLINE void
AUXTDCIdleForce(uint32_t ui32Base)
{
    //
    // Check the arguments
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Abort operation of AUX TDC and force into Idle mode.
    //
    HWREG(ui32Base + AUX_TDC_O_CTL) = AUX_TDC_CTL_CMD_ABORT;
}

//*****************************************************************************
//
//! \brief Check if the AUX TDC is done measuring.
//!
//! This function can be used to check whether the AUX TDC has finished a
//! measurement. The AUX TDC may have completed a measurement for two reasons.
//! Either it finish succesfully \ref AUX_TDC_DONE or it failed due to a timeout
//! \ref AUX_TDC_TIMEOUT. If the AUX TDC is still measuring it this function
//! will return \ref AUX_TDC_BUSY.
//!
//! \param ui32Base is the base address of the AUX TDC.
//!
//! \return Returns the current status of a measurement:
//! - \ref AUX_TDC_DONE : An AUX TDC measurement finished successfully.
//! - \ref AUX_TDC_TIMEOUT : An AUX TDC measurement failed due to timeout.
//! - \ref AUX_TDC_BUSY : An AUX TDC measurement is being performed.
//
//*****************************************************************************
extern uint32_t AUXTDCMeasurementDone(uint32_t ui32Base);

//*****************************************************************************
//
//! \brief Get the value of the latest measurement.
//!
//! This function is used for retrieving the value of the lastest measurement
//! performed by the AUX TDC.
//!
//! \param ui32Base is the base address of the AUX TDC.
//!
//! \return Returns the result of the latest measurement.
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AUXTDCMeasurementGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Return the measurement.
    //
    return (HWREG(ui32Base + AUX_TDC_O_RESULT));
}

//*****************************************************************************
//
//! \brief Set the saturation limit of the measurement.
//!
//! This function is used to set a saturation limit for the event accumulation
//! register. The saturation limit is defined as a bit width of the
//! accumulation register and therefore increases in power of 2.
//!
//! \param ui32Base is base address of the AUX TDC.
//! \param ui32Limit is the saturation limit.
//! - \ref AUXTDC_SAT_4096
//! - \ref AUXTDC_SAT_8192
//! - \ref AUXTDC_SAT_16384
//! - \ref AUXTDC_SAT_32768
//! - \ref AUXTDC_SAT_65536
//! - \ref AUXTDC_SAT_131072
//! - \ref AUXTDC_SAT_262144
//! - \ref AUXTDC_SAT_524288
//! - \ref AUXTDC_SAT_1048576
//! - \ref AUXTDC_SAT_2097152
//! - \ref AUXTDC_SAT_4194304
//! - \ref AUXTDC_SAT_8388608
//! - \ref AUXTDC_SAT_WRAP_AROUND
//!
//! \return None
//!
//! \sa AUXTDCLimitGet()
//
//*****************************************************************************
__STATIC_INLINE void
AUXTDCLimitSet(uint32_t ui32Base, uint32_t ui32Limit)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));
    ASSERT(ui32Limit < AUXTDC_NUM_SAT_VALS);

    //
    // Set the saturation limit.
    //
    HWREG(ui32Base + AUX_TDC_O_SATCFG) = ui32Limit;
}

//*****************************************************************************
//
//! \brief Get the saturation limit of the measurement.
//!
//! This function is used to retrieve the current saturation for the
//! accumulator register.
//!
//! \param ui32Base is base address of the AUX TDC.
//!
//! \return Returns the saturation limit.
//! - \ref AUXTDC_SAT_4096
//! - \ref AUXTDC_SAT_8192
//! - \ref AUXTDC_SAT_16384
//! - \ref AUXTDC_SAT_32768
//! - \ref AUXTDC_SAT_65536
//! - \ref AUXTDC_SAT_131072
//! - \ref AUXTDC_SAT_262144
//! - \ref AUXTDC_SAT_524288
//! - \ref AUXTDC_SAT_1048576
//! - \ref AUXTDC_SAT_2097152
//! - \ref AUXTDC_SAT_4194304
//! - \ref AUXTDC_SAT_8388608
//! - \ref AUXTDC_SAT_WRAP_AROUND
//!
//! \sa AUXTDCLimitSet()
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AUXTDCLimitGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Return the saturation limit.
    //
    return (HWREG(ui32Base + AUX_TDC_O_SATCFG));
}

//*****************************************************************************
//
//! \brief Enables the counter if possible.
//!
//! This function can be used to ensable the AUX TDC stop/compare event counter.
//! The counter can be used to measure multiple periods of a clock signal.
//! For each stop/compare event the counter will be decremented by one and
//! the measurement will continue running until the value of the counter
//! reaches 0. The current value of the counter can be read using
//! AUXTDCCounterGet(). The reset value of the counter can be set using
//! AUXTDCCounterSet().
//!
//! \param ui32Base is base address of the AUX TDC.
//!
//! \return Returns \c true if the counter was succesfully enabled. If the
//! AUX TDC is not in Idle mode, the counter can not be enabled, and the
//! return value will be \c false.
//!
//! \sa AUXTDCCounterGet(), AUXTDCCounterSet()
//
//*****************************************************************************
__STATIC_INLINE bool
AUXTDCCounterEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Check if the AUX TDC is in idle mode. If not in Idle mode, the counter
    // will not be enabled.
    //
    if(!((HWREG(ui32Base + AUX_TDC_O_STAT) & AUX_TDC_STAT_STATE_M) ==
            AUX_TDC_STAT_STATE_IDLE))
    {
        return false;
    }

    //
    // Enable the counter.
    //
    HWREG(ui32Base + AUX_TDC_O_TRIGCNTCFG) = AUX_TDC_TRIGCNTCFG_EN;

    //
    // Counter succesfully enabled.
    //
    return true;
}

//*****************************************************************************
//
//! \brief Disables the counter if possible.
//!
//! This function can be used to disable the AUX TDC stop/compare event counter.
//!
//! \param ui32Base is base address of the AUX TDC.
//!
//! \return Returns \c true if the counter was succesfully disabled. If the
//! AUX TDC is not in Idle mode, the counter can not be disabled, and the
//! return value will be \c false.
//!
//! \sa AUXTDCCounterEnable() for more information on how to use the counter.
//
//*****************************************************************************
__STATIC_INLINE bool
AUXTDCCounterDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Check if the AUX TDC is in Idle mode. If not in Idle mode, the counter
    // will not be disabled.
    //
    if(!((HWREG(ui32Base + AUX_TDC_O_STAT) & AUX_TDC_STAT_STATE_M) ==
            AUX_TDC_STAT_STATE_IDLE))
    {
        return false;
    }

    //
    // Disable the counter.
    //
    HWREG(ui32Base + AUX_TDC_O_TRIGCNTCFG) = 0;

    //
    // Counter succesfull disabled.
    //
    return true;
}

//*****************************************************************************
//
//! \brief Set the reset number of counter compare/stop event to ignore before taking
//! a measurement.
//!
//! This function loads the reset value of the counter with the specified
//! number of events to ignore. A reset in this context means the counter
//! has been disabled and then enabled.
//!
//! \param ui32Base is base address of the AUX TDC.
//! \param ui32Events is the number of compare/stop events to load into the
//! counter.
//!
//! \return Returns \c true if the counter was succesfully updated. If the
//! AUX TDC is not in Idle mode, the counter can not be updated, and the
//! return value will be \c false.
//!
//! \sa AUXTDCCounterEnable()
//
//*****************************************************************************
__STATIC_INLINE bool
AUXTDCCounterSet(uint32_t ui32Base, uint32_t ui32Events)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Check if the AUX TDC is in idle mode. If not in idle mode, the counter
    // will not be disabled.
    //
    if(!((HWREG(ui32Base + AUX_TDC_O_STAT) & AUX_TDC_STAT_STATE_M) ==
            AUX_TDC_STAT_STATE_IDLE))
    {
        return false;
    }

    //
    // Update the reset counter value.
    //
    HWREG(ui32Base + AUX_TDC_O_TRIGCNTLOAD) = ui32Events;

    //
    // Counter succesfully updated.
    //
    return true;
}

//*****************************************************************************
//
//! \brief Get the current number of counter compare/stop event to ignore before
//! taking a measurement.
//!
//! This function returns the current value of compare/stop events before
//! a measurement is registered. This value is decremented by one for each
//! registered compare/stop event and will always be less than or equal the
//! reset value of the counter set using AUXTDCCounterSet().
//!
//! \param ui32Base is base address of the AUX TDC.
//!
//! \return Returns the current value of compare/stop events ignored before a
//! measurement is performed.
//!
//! \sa AUXTDCCounterEnable().
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AUXTDCCounterGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(AUXTDCBaseValid(ui32Base));

    //
    // Return the current counter value.
    //
    return (HWREG(ui32Base + AUX_TDC_O_TRIGCNT));
}

//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#ifndef DRIVERLIB_NOROM
    #include <driverlib/rom.h>
    #ifdef ROM_AUXTDCConfigSet
        #undef  AUXTDCConfigSet
        #define AUXTDCConfigSet                 ROM_AUXTDCConfigSet
    #endif
    #ifdef ROM_AUXTDCMeasurementDone
        #undef  AUXTDCMeasurementDone
        #define AUXTDCMeasurementDone           ROM_AUXTDCMeasurementDone
    #endif
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __AUX_TDC_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//
//*****************************************************************************
