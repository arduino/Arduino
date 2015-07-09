/******************************************************************************
*  Filename:       aux_timer.h
*  Revised:        2015-01-14 12:12:44 +0100 (on, 14 jan 2015)
*  Revision:       42373
*
*  Description:    Defines and prototypes for the AUX Timer
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
//! \addtogroup auxtimer_api
//! @{
//
//*****************************************************************************

#ifndef __AUX_TIMER_H__
#define __AUX_TIMER_H__

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
#include <inc/hw_ints.h>
#include <inc/hw_memmap.h>
#include <inc/hw_aux_timer.h>
#include <driverlib/debug.h>
#include <driverlib/interrupt.h>

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
    #define AUXTimerConfigure               NOROM_AUXTimerConfigure
    #define AUXTimerStart                   NOROM_AUXTimerStart
    #define AUXTimerStop                    NOROM_AUXTimerStop
    #define AUXTimerPrescaleSet             NOROM_AUXTimerPrescaleSet
    #define AUXTimerPrescaleGet             NOROM_AUXTimerPrescaleGet
#endif

//*****************************************************************************
//
// Values that can be passed to AUXTimerConfigure().
//
//*****************************************************************************
#define AUX_TIMER_CFG_ONE_SHOT \
                                0x00000000  // One-shot timer mode
#define AUX_TIMER_CFG_PERIODIC \
                                0x00000001  // Period timer mode
#define AUX_TIMER_CFG_ONE_SHOT_EDGE_COUNT \
                                0x00000002  // One-shot timer with edge count
#define AUX_TIMER_CFG_PERIODIC_EDGE_COUNT \
                                0x00000003  // Periodic timer with edge count
#define AUX_TIMER_CFG_RISING_EDGE \
                                0x00000000  // Count rising edges (used with
                                            // edge count mode)
#define AUX_TIMER_CFG_FALLING_EDGE \
                                0x00002000  // Count falling edges (used with
                                            // edge count mode)
#define AUX_TIMER_CFG_TICK_SRC_RTC_EVENT \
                                0x00000000 // AON wake-up event
#define AUX_TIMER_CFG_TICK_SRC_CMP_A \
                                0x00000100 // Comperator A
#define AUX_TIMER_CFG_TICK_SRC_CMP_B \
                                0x00000200 // Comperator B
#define AUX_TIMER_CFG_TICK_SRC_TDCDONE \
                                0x00000300 // TDC Done
#define AUX_TIMER_CFG_TICK_SRC_TIMER0_EVENT \
                                0x00000400 // Timer 0 event
#define AUX_TIMER_CFG_TICK_SRC_TIMER1_EVENT \
                                0x00000500 // Timer 1 event
#define AUX_TIMER_CFG_TICK_SRC_SMPH_RELEASE \
                                0x00000600 // Semaphore release
#define AUX_TIMER_CFG_TICK_SRC_ADC_DONE \
                                0x00000700 // ADC done
#define AUX_TIMER_CFG_TICK_SRC_ADC_DONE \
                                0x00000700 // ADC done

#define AUX_TIMER_CFG_TICK_SRC_AIO0 \
                                0x00000d00 // AIO_DAT[ 0]
#define AUX_TIMER_CFG_TICK_SRC_AIO1 \
                                0x00000e00 // AIO_DAT[ 1]
#define AUX_TIMER_CFG_TICK_SRC_AIO2 \
                                0x00000f00 // AIO_DAT[ 2]
#define AUX_TIMER_CFG_TICK_SRC_AIO3 \
                                0x00001000 // AIO_DAT[ 3]
#define AUX_TIMER_CFG_TICK_SRC_AIO4 \
                                0x00001100 // AIO_DAT[ 4]
#define AUX_TIMER_CFG_TICK_SRC_AIO5 \
                                0x00001200 // AIO_DAT[ 5]
#define AUX_TIMER_CFG_TICK_SRC_AIO6 \
                                0x00001300 // AIO_DAT[ 6]
#define AUX_TIMER_CFG_TICK_SRC_AIO7 \
                                0x00001400 // AIO_DAT[ 7]
#define AUX_TIMER_CFG_TICK_SRC_AIO8 \
                                0x00001500 // AIO_DAT[ 8]
#define AUX_TIMER_CFG_TICK_SRC_AIO9 \
                                0x00001600 // AIO_DAT[ 9]
#define AUX_TIMER_CFG_TICK_SRC_AIO10 \
                                0x00001700 // AIO_DAT[10]
#define AUX_TIMER_CFG_TICK_SRC_AIO11 \
                                0x00001800 // AIO_DAT[11]
#define AUX_TIMER_CFG_TICK_SRC_AIO12 \
                                0x00001900 // AIO_DAT[12]
#define AUX_TIMER_CFG_TICK_SRC_AIO13 \
                                0x00001A00 // AIO_DAT[13]
#define AUX_TIMER_CFG_TICK_SRC_AIO14 \
                                0x00001B00 // AIO_DAT[14]
#define AUX_TIMER_CFG_TICK_SRC_AIO15 \
                                0x00001C00 // AIO_DAT[15]
#define AUX_TIMER_CFG_TICK_SRC_ACLK_REF \
                                0x00001D00 // ACLK_REF_i
#define AUX_TIMER_CFG_TICK_SRC_MCU_EVENT \
                                0x00001E00 // MCU event
#define AUX_TIMER_CFG_TICK_SRC_ADC_IRQ \
                                0x00001F00 // DMA done

//*****************************************************************************
//
// Values that can be passed to most of the timer APIs as the ui32Timer
// parameter.
//
//*****************************************************************************
#define AUX_TIMER_0             0x0000FFFF  // AUX Timer 0
#define AUX_TIMER_1             0x00FF0000  // AUX Timer 1
#define AUX_TIMER_BOTH          0x00FFFFFF  // AUX Timer Both 0 and 1

//*****************************************************************************
//
// Values that can be passed to AUXTimerPrescaleSet and returned from
// AUXTimerPrescaleGet.
//
//*****************************************************************************
#define AUX_TIMER_PRESCALE_DIV_1 \
                                0x00000000  // Prescale division ratio 1
#define AUX_TIMER_PRESCALE_DIV_2 \
                                0x00000010  // Prescale division ratio 2
#define AUX_TIMER_PRESCALE_DIV_4 \
                                0x00000020  // Prescale division ratio 4
#define AUX_TIMER_PRESCALE_DIV_8 \
                                0x00000030  // Prescale division ratio 8
#define AUX_TIMER_PRESCALE_DIV_16 \
                                0x00000040  // Prescale division ratio 16
#define AUX_TIMER_PRESCALE_DIV_32 \
                                0x00000050  // Prescale division ratio 32
#define AUX_TIMER_PRESCALE_DIV_64 \
                                0x00000060  // Prescale division ratio 64
#define AUX_TIMER_PRESCALE_DIV_128 \
                                0x00000070  // Prescale division ratio 128
#define AUX_TIMER_PRESCALE_DIV_256 \
                                0x00000080  // Prescale division ratio 256
#define AUX_TIMER_PRESCALE_DIV_512 \
                                0x00000090  // Prescale division ratio 512
#define AUX_TIMER_PRESCALE_DIV_1028 \
                                0x000000A0  // Prescale div. ratio 1028
#define AUX_TIMER_PRESCALE_DIV_2048 \
                                0x000000B0  // Prescale div. ratio 2048
#define AUX_TIMER_PRESCALE_DIV_4096 \
                                0x000000C0  // Prescale div. ratio 4096
#define AUX_TIMER_PRESCALE_DIV_8192 \
                                0x000000D0  // Prescale div. ratio 8192
#define AUX_TIMER_PRESCALE_DIV_16384 \
                                0x000000E0  // Prescale div. ratio 16384
#define AUX_TIMER_PRESCALE_DIV_32768 \
                                0x000000F0  // Prescale div. ratio 32768

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Configure AUX timer.
//!
//! This call configures the AUX timer selected by the \c ui32Timer.
//! The timer module is disabled before being configured and is left in the
//! disabled state.
//!
//! The configuration is specified in \c ui32Config as one of the following
//! values:
//! - \ref AUX_TIMER_CFG_ONE_SHOT            : One-shot timer.
//! - \ref AUX_TIMER_CFG_PERIODIC            : Periodic timer.
//! - \ref AUX_TIMER_CFG_ONE_SHOT_EDGE_COUNT : One-shot edge counter.
//! - \ref AUX_TIMER_CFG_PERIODIC_EDGE_COUNT : Periodic edge counter.
//!
//! When configured as timer, the counter is incremented based on the aux clock
//! after the prescaler. The prescale division ratio is set
//! using \ref AUXTimerPrescaleSet().
//!
//! When configured as an edge counter the counter is incremented only on edges
//! of the selected event.
//! The polarity of the event is selected by:
//! - \ref AUX_TIMER_CFG_RISING_EDGE  : risging edge trigger
//! - \ref AUX_TIMER_CFG_FALLING_EDGE : falling edge trigger
//!
//! The event source is selected as one of the following defines:
//! - \ref AUX_TIMER_CFG_TICK_SRC_RTC_EVENT
//! - \ref AUX_TIMER_CFG_TICK_SRC_CMP_A
//! - \ref AUX_TIMER_CFG_TICK_SRC_CMP_B
//! - \ref AUX_TIMER_CFG_TICK_SRC_TDCDONE
//! - \ref AUX_TIMER_CFG_TICK_SRC_TIMER0_EVENT
//! - \ref AUX_TIMER_CFG_TICK_SRC_TIMER1_EVENT
//! - \ref AUX_TIMER_CFG_TICK_SRC_SMPH_RELEASE
//! - \ref AUX_TIMER_CFG_TICK_SRC_ADC_DONE
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO0
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO1
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO2
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO3
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO4
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO5
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO6
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO7
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO8
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO9
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO10
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO11
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO12
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO13
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO14
//! - \ref AUX_TIMER_CFG_TICK_SRC_AIO15
//! - \ref AUX_TIMER_CFG_TICK_SRC_ACLK_REF
//! - \ref AUX_TIMER_CFG_TICK_SRC_MCU_EVENT
//! - \ref AUX_TIMER_CFG_TICK_SRC_ADC_IRQ
//!
//! The mode, event polarity and event source are configured by setting the
//! \c ui32Config parameter as the bitwise OR of the various settings.
//! I.e. (\ref AUX_TIMER_CFG_ONE_SHOT_EDGE_COUNT | \ref AUX_TIMER_CFG_RISING_EDGE |
//!       \ref AUX_TIMER_CFG_TICK_SRC_RTC_EVENT).
//!
//! \note When used as an edge counter the prescaler should be set to
//! \ref AUX_TIMER_PRESCALE_DIV_1.
//!
//! \note A timer can not trigger itself thus timer 0 can \b not use
//! \ref AUX_TIMER_CFG_TICK_SRC_TIMER0_EVENT and timer 1 can \b not use
//! \ref AUX_TIMER_CFG_TICK_SRC_TIMER1_EVENT.
//!
//! \param ui32Timer is the timer to configure.
//! - \ref AUX_TIMER_0
//! - \ref AUX_TIMER_1
//! \param ui32Config is the timer configuration.
//!
//! \return None
//!
//! \sa \ref AUXTimerPrescaleSet()
//
//*****************************************************************************
extern void AUXTimerConfigure(uint32_t ui32Timer, uint32_t ui32Config);

//*****************************************************************************
//
//! \brief Start AUX timer(s).
//!
//! This call starts the selected AUX timer(s).
//!
//! \note The counter will start counting up from zero.
//!
//! \param ui32Timer is the timer to start.
//! - \ref AUX_TIMER_0
//! - \ref AUX_TIMER_1
//! - \ref AUX_TIMER_BOTH
//!
//! \return None
//!
//! \sa \ref AUXTimerStop()
//
//*****************************************************************************
extern void AUXTimerStart(uint32_t ui32Timer);

//*****************************************************************************
//
//! \brief Stop AUX timer(s).
//!
//! This call stops the selected AUX timer(s).
//!
//! \param ui32Timer is the timer to stop.
//! - \ref AUX_TIMER_0
//! - \ref AUX_TIMER_1
//! - \ref AUX_TIMER_BOTH
//!
//! \return None
//!
//! \sa \ref AUXTimerStart()
//
//*****************************************************************************
extern void AUXTimerStop(uint32_t ui32Timer);

//*****************************************************************************
//
//! \brief Set AUX timer target value.
//!
//! The timer counts from zero to the target value. When target value is
//! reached an event is generated.
//!
//! \param ui32Timer is the timer to set the target value for.
//! - \ref AUX_TIMER_0
//! - \ref AUX_TIMER_1
//! \param ui32Target is the timer target value.
//! - For \ref AUX_TIMER_0 the target value must be an integer in the range 0..65535 (16 bit).
//! - For \ref AUX_TIMER_1 the target value must be an integer in the range 0..255 (8 bit).
//!
//! \return None
//!
//! \sa \ref AUXTimerTargetValGet()
//
//*****************************************************************************
__STATIC_INLINE void
AUXTimerTargetValSet(uint32_t ui32Timer, uint32_t ui32Target)
{
    uint32_t ui32Addr;

    //
    // Check the arguments.
    //
    ASSERT((ui32Timer == AUX_TIMER_0) || (ui32Timer == AUX_TIMER_1));
    ASSERT(((ui32Timer & AUX_TIMER_0) && (ui32Target <= 65535)) ||
           ((ui32Timer & AUX_TIMER_1) && (ui32Target <= 255)));

    ui32Addr = (ui32Timer & AUX_TIMER_0) ?
               (AUX_TIMER_BASE + AUX_TIMER_O_T0TARGET) :
               (AUX_TIMER_BASE + AUX_TIMER_O_T1TARGET);

    HWREG(ui32Addr) = ui32Target;
}

//*****************************************************************************
//
//! \brief Get AUX timer target value.
//!
//! The timer counts from zero to the target value. When target value is
//! reached an event is generated. This function returns the programmed target
//! value for the specified timer.
//!
//! \param ui32Timer is the timer to get the target value from.
//! - \ref AUX_TIMER_0
//! - \ref AUX_TIMER_1
//!
//! \return Returns target value for the specified timer
//!
//! \sa \ref AUXTimerTargetValSet()
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AUXTimerTargetValGet(uint32_t ui32Timer)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Timer == AUX_TIMER_0) || (ui32Timer == AUX_TIMER_1));

    return(HWREG((ui32Timer & AUX_TIMER_0) ?
                 (AUX_TIMER_BASE + AUX_TIMER_O_T0TARGET) :
                 (AUX_TIMER_BASE + AUX_TIMER_O_T1TARGET)));
}

//*****************************************************************************
//
//! \brief Set AUX timer prescale value.
//!
//! When configured as timer, the counter is incremented based on the AUX clock
//! after the prescaler.
//!
//! \note Setting prescale value is \b not adviced when the timer is running.
//!
//! \note When timer is used as an edge counter the prescaler should be
//!       set to \ref AUX_TIMER_PRESCALE_DIV_1.
//!
//! \param ui32Timer is the timer to set the prescale on.
//! - \ref AUX_TIMER_0
//! - \ref AUX_TIMER_1
//! \param ui32PrescaleDiv is the prescaler division ratio.
//! - \ref AUX_TIMER_PRESCALE_DIV_1     : Prescale division ratio 1
//! - \ref AUX_TIMER_PRESCALE_DIV_2     : Prescale division ratio 2
//! - \ref AUX_TIMER_PRESCALE_DIV_4     : Prescale division ratio 4
//! - \ref AUX_TIMER_PRESCALE_DIV_16    : Prescale division ratio 16
//! - \ref AUX_TIMER_PRESCALE_DIV_32    : Prescale division ratio 32
//! - \ref AUX_TIMER_PRESCALE_DIV_64    : Prescale division ratio 64
//! - \ref AUX_TIMER_PRESCALE_DIV_128   : Prescale division ratio 128
//! - \ref AUX_TIMER_PRESCALE_DIV_256   : Prescale division ratio 256
//! - \ref AUX_TIMER_PRESCALE_DIV_1028  : Prescale division ratio 1028
//! - \ref AUX_TIMER_PRESCALE_DIV_2048  : Prescale division ratio 2048
//! - \ref AUX_TIMER_PRESCALE_DIV_4096  : Prescale division ratio 4096
//! - \ref AUX_TIMER_PRESCALE_DIV_8192  : Prescale division ratio 8192
//! - \ref AUX_TIMER_PRESCALE_DIV_16384 : Prescale division ratio 16384
//! - \ref AUX_TIMER_PRESCALE_DIV_32768 : Prescale division ratio 32768
//!
//! \return None
//!
//! \sa \ref AUXTimerPrescaleGet()
//
//*****************************************************************************
extern void AUXTimerPrescaleSet(uint32_t ui32Timer, uint32_t ui32PrescaleDiv);

//*****************************************************************************
//
//! \brief Get AUX timer prescale value.
//!
//! When configured as timer, the counter is incremented based on the aux clock
//! after the prescaler. This call returns the setting of the prescale divide
//! ratio for the specified timer.
//!
//! \param ui32Timer is the timer to get the prescale value from.
//! - \ref AUX_TIMER_0
//! - \ref AUX_TIMER_1
//!
//! \return Returns the prescaler division ratio as one of the following values:
//! - \ref AUX_TIMER_PRESCALE_DIV_1     : Prescale division ratio 1
//! - \ref AUX_TIMER_PRESCALE_DIV_2     : Prescale division ratio 2
//! - \ref AUX_TIMER_PRESCALE_DIV_4     : Prescale division ratio 4
//! - \ref AUX_TIMER_PRESCALE_DIV_16    : Prescale division ratio 16
//! - \ref AUX_TIMER_PRESCALE_DIV_32    : Prescale division ratio 32
//! - \ref AUX_TIMER_PRESCALE_DIV_64    : Prescale division ratio 64
//! - \ref AUX_TIMER_PRESCALE_DIV_128   : Prescale division ratio 128
//! - \ref AUX_TIMER_PRESCALE_DIV_256   : Prescale division ratio 256
//! - \ref AUX_TIMER_PRESCALE_DIV_1028  : Prescale division ratio 1028
//! - \ref AUX_TIMER_PRESCALE_DIV_2048  : Prescale division ratio 2048
//! - \ref AUX_TIMER_PRESCALE_DIV_4096  : Prescale division ratio 4096
//! - \ref AUX_TIMER_PRESCALE_DIV_8192  : Prescale division ratio 8192
//! - \ref AUX_TIMER_PRESCALE_DIV_16384 : Prescale division ratio 16384
//! - \ref AUX_TIMER_PRESCALE_DIV_32768 : Prescale division ratio 32768
//!
//! \sa \ref AUXTimerPrescaleSet()
//
//*****************************************************************************
extern uint32_t AUXTimerPrescaleGet(uint32_t ui32Timer);

//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#ifndef DRIVERLIB_NOROM
    #include <driverlib/rom.h>
    #ifdef ROM_AUXTimerConfigure
        #undef  AUXTimerConfigure
        #define AUXTimerConfigure               ROM_AUXTimerConfigure
    #endif
    #ifdef ROM_AUXTimerStart
        #undef  AUXTimerStart
        #define AUXTimerStart                   ROM_AUXTimerStart
    #endif
    #ifdef ROM_AUXTimerStop
        #undef  AUXTimerStop
        #define AUXTimerStop                    ROM_AUXTimerStop
    #endif
    #ifdef ROM_AUXTimerPrescaleSet
        #undef  AUXTimerPrescaleSet
        #define AUXTimerPrescaleSet             ROM_AUXTimerPrescaleSet
    #endif
    #ifdef ROM_AUXTimerPrescaleGet
        #undef  AUXTimerPrescaleGet
        #define AUXTimerPrescaleGet             ROM_AUXTimerPrescaleGet
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

#endif // __AUX_TIMER_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//
//*****************************************************************************
