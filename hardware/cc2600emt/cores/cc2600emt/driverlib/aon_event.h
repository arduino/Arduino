/******************************************************************************
*  Filename:       aon_event.h
*  Revised:        2015-07-16 12:12:04 +0200 (Thu, 16 Jul 2015)
*  Revision:       44151
*
*  Description:    Defines and prototypes for the AON Event fabric.
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
//! \addtogroup aon_group
//! @{
//! \addtogroup aonevent_api
//! @{
//
//*****************************************************************************

#ifndef __AON_EVENT_H__
#define __AON_EVENT_H__

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
#include <inc/hw_device.h>
#include <inc/hw_aon_event.h>
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
//*****************************************************************************
#if !defined(DOXYGEN)
    #define AONEventMcuWakeUpSet            NOROM_AONEventMcuWakeUpSet
    #define AONEventMcuWakeUpGet            NOROM_AONEventMcuWakeUpGet
    #define AONEventAuxWakeUpSet            NOROM_AONEventAuxWakeUpSet
    #define AONEventAuxWakeUpGet            NOROM_AONEventAuxWakeUpGet
    #define AONEventMcuSet                  NOROM_AONEventMcuSet
    #define AONEventMcuGet                  NOROM_AONEventMcuGet
#endif

//*****************************************************************************
//
// Event sources for the event AON fabric.
// Note: Events are level-triggered active high
//
//*****************************************************************************
// AON_EVENT_DIO0                      // Edge detect on DIO0. See hw_device.h for DIO-to-PAD mapping.
// ...                                 // ...
// AON_EVENT_DIO31                     // Edge detect on DIO31. See hw_device.h for DIO-to-PAD mapping.
#define AON_EVENT_IO                32 // Edge detect on any DIO
                                       // Event ID 33 is reserved for future use
                                       // Event ID 34 is reserved for future use
#define AON_EVENT_RTC_CH0           35 // RTC channel 0
#define AON_EVENT_RTC_CH1           36 // RTC channel 1
#define AON_EVENT_RTC_CH2           37 // RTC channel 2
#define AON_EVENT_RTC_CH0_DLY       38 // RTC channel 0 - delayed event
#define AON_EVENT_RTC_CH1_DLY       39 // RTC channel 1 - delayed event
#define AON_EVENT_RTC_CH2_DLY       40 // RTC channel 2 - delayed event
#define AON_EVENT_RTC_COMB_DLY      41 // RTC combined delayed event
#define AON_EVENT_RTC_UPD           42 // RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
#define AON_EVENT_JTAG              43 // JTAG generated event
#define AON_EVENT_AUX_SWEV0         44 // AUX Software triggered event #0
#define AON_EVENT_AUX_SWEV1         45 // AUX Software triggered event #1
#define AON_EVENT_AUX_SWEV2         46 // AUX Software triggered event #2
#define AON_EVENT_AUX_COMPA         47 // Comparator A triggered (synchronized in AUX)
#define AON_EVENT_AUX_COMPB         48 // Comparator B triggered (synchronized in AUX)
#define AON_EVENT_AUX_ADC_DONE      49 // ADC conversion completed
#define AON_EVENT_AUX_TDC_DONE      50 // TDC completed or timed out
#define AON_EVENT_AUX_TIMER0_EV     51 // Timer 0 event
#define AON_EVENT_AUX_TIMER1_EV     52 // Timer 1 event
#define AON_EVENT_BATMON_TEMP       53 // BATMON temperature update event
#define AON_EVENT_BATMON_VOLT       54 // BATMON voltage update event
#define AON_EVENT_AUX_COMPB_ASYNC   55 // Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
#define AON_EVENT_AUX_COMPB_ASYNC_N 56 // Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
                                       // Event ID 57-62 is reserved for future use
#define AON_EVENT_NONE              63 // No event, always low

//
// Keeping backward compatibility until major revision number is incremented
//
#define AON_EVENT_RTC0     ( AON_EVENT_RTC_CH0 )

//*****************************************************************************
//
// Values that can be passed to AONEventMCUWakeUpSet() and returned
// by AONEventMCUWakeUpGet().
//
//*****************************************************************************
#define AON_EVENT_MCU_WU0 0     // Programmable MCU wakeup event 0
#define AON_EVENT_MCU_WU1 1     // Programmable MCU wakeup event 1
#define AON_EVENT_MCU_WU2 2     // Programmable MCU wakeup event 2
#define AON_EVENT_MCU_WU3 3     // Programmable MCU wakeup event 3

//*****************************************************************************
//
// Values that can be passed to AONEventAuxWakeUpSet() and AONEventAuxWakeUpGet()
//
//*****************************************************************************
#define AON_EVENT_AUX_WU0 0     // Programmable AUX wakeup event 0
#define AON_EVENT_AUX_WU1 1     // Programmable AUX wakeup event 1
#define AON_EVENT_AUX_WU2 2     // Programmable AUX wakeup event 2

//*****************************************************************************
//
// Values that can be passed to AONEventMcuSet() and AONEventMcuGet()
//
//*****************************************************************************
#define AON_EVENT_MCU_EVENT0 0  // Programmable event source fed to MCU event fabric (first of 3)
#define AON_EVENT_MCU_EVENT1 1  // Programmable event source fed to MCU event fabric (second of 3)
#define AON_EVENT_MCU_EVENT2 2  // Programmable event source fed to MCU event fabric (third of 3)

//*****************************************************************************
//
// API Functions and prototypes
//
//*****************************************************************************

//*****************************************************************************
//
//! \brief Select event source for the specified MCU wakeup programmable event.
//!
//! The AON event fabric has a total of four programmable events that can
//! wake-up the MCU. The events are forwarded to the wakeup controller (WUC).
//!
//! \note The four programmable event sources are effectively OR'ed together
//!  to form a single wake-up event forwarded to the WUC.
//!
//! \param ui32MCUWUEvent is one of four programmable MCU wakeup event sources.
//! - \ref AON_EVENT_MCU_WU0
//! - \ref AON_EVENT_MCU_WU1
//! - \ref AON_EVENT_MCU_WU2
//! - \ref AON_EVENT_MCU_WU3
//! \param ui32EventSrc is an event source for the event AON fabric.
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \return None
//!
//! \sa AONEventMcuWakeUpGet()
//
//*****************************************************************************
extern void AONEventMcuWakeUpSet(uint32_t ui32MCUWUEvent,
                                 uint32_t ui32EventSrc);

//*****************************************************************************
//
//! \brief Get event source for the specified MCU wakeup programmable event.
//!
//! The AON event fabric has a total of four programmable events that can
//! wake-up the MCU. The events are forwarded to the wakeup controller (WUC).
//!
//! \param ui32MCUWUEvent is one of four programmable MCU wakeup event sources.
//! - \ref AON_EVENT_MCU_WU0
//! - \ref AON_EVENT_MCU_WU1
//! - \ref AON_EVENT_MCU_WU2
//! - \ref AON_EVENT_MCU_WU3
//!
//! \return Returns an event source for the event AON fabric, i.e. one of the
//! following:
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \sa AONEventMcuWakeUpSet()
//
//*****************************************************************************
extern uint32_t AONEventMcuWakeUpGet(uint32_t ui32MCUWUEvent);

//*****************************************************************************
//
//! \brief Select event source for the specified AUX wakeup programmable event.
//!
//! The AON event fabric has a total of three programmable events that can
//! wake-up the AUX domain. The events are forwarded to the wakeup
//! controller (WUC).
//!
//! \note The three programmable event sources are effectively OR'ed together
//!  to form a single wake-up event forwarded to the WUC.
//!
//! \param ui32AUXWUEvent is one of three programmable AUX wakeup event sources.
//! - \ref AON_EVENT_AUX_WU0
//! - \ref AON_EVENT_AUX_WU1
//! - \ref AON_EVENT_AUX_WU2
//! \param ui32EventSrc is an event sources for the event AON fabric.
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \return None
//!
//! \sa AONEventAuxWakeUpGet()
//
//*****************************************************************************
extern void AONEventAuxWakeUpSet(uint32_t ui32AUXWUEvent,
                                 uint32_t ui32EventSrc);

//*****************************************************************************
//
//! \brief Get event source for the specified AUX wakeup programmable event.
//!
//! The AON event fabric has a total of three programmable events that can
//! wake-up the AUX domain. The events are forwarded to the wakeup
//! controller (WUC).
//!
//! \param ui32AUXWUEvent is one of three programmable AUX wakeup event sources.
//! - \ref AON_EVENT_AUX_WU0
//! - \ref AON_EVENT_AUX_WU1
//! - \ref AON_EVENT_AUX_WU2
//!
//! \return Returns an event source for the event AON fabric, i.e. one of the following:
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \sa AONEventAuxWakeUpSet()
//
//*****************************************************************************
extern uint32_t AONEventAuxWakeUpGet(uint32_t ui32AUXWUEvent);

//*****************************************************************************
//
//! \brief Select event source for the specified programmable event forwarded to the
//! MCU event fabric.
//!
//! The AON event fabric has a total of three programmable events that can
//! be forwarded to the MCU event fabric.
//!
//! \note The three programmable event sources are forwarded to the MCU Event
//! Fabric as:
//! - AON_PROG0
//! - AON_PROG1
//! - AON_PROG2
//!
//! \param ui32MCUEvent is one of three programmable events forwarded to the
//! MCU event fabric.
//! - \ref AON_EVENT_MCU_EVENT0
//! - \ref AON_EVENT_MCU_EVENT1
//! - \ref AON_EVENT_MCU_EVENT2
//! \param ui32EventSrc is event sources for the event AON fabric.
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \return None
//!
//! \sa AONEventMcuGet()
//
//*****************************************************************************
extern void AONEventMcuSet(uint32_t ui32MCUEvent, uint32_t ui32EventSrc);

//*****************************************************************************
//
//! \brief Get source for the specified programmable event forwarded to the MCU event
//! fabric.
//!
//! The AON event fabric has a total of three programmable events that can
//! be forwarded to the MCU event fabric.
//!
//! \param ui32MCUEvent is one of three programmable events forwarded to the
//! MCU event fabric.
//! - \ref AON_EVENT_MCU_EVENT0
//! - \ref AON_EVENT_MCU_EVENT1
//! - \ref AON_EVENT_MCU_EVENT2
//!
//! \return Returns an event source for the event AON fabric, i.e. one of the following:
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \sa AONEventMcuSet()
//
//*****************************************************************************
extern uint32_t AONEventMcuGet(uint32_t ui32MCUEvent);

//*****************************************************************************
//
//! \brief Select event source forwarded to AON Real Time Clock (RTC).
//!
//! A programmable event can be forwarded to the AON real time clock
//! for triggering a capture event on RTC channel 1.
//!
//! \param ui32EventSrc is the event sources for the event AON fabric.
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \return None
//!
//! \sa AONEventRtcGet()
//
//*****************************************************************************
__STATIC_INLINE void
AONEventRtcSet(uint32_t ui32EventSrc)
{
    uint32_t ui32Ctrl;

    //
    // Check the arguments.
    //
    ASSERT(ui32EventSrc <= AON_EVENT_NONE);

    ui32Ctrl = HWREG(AON_EVENT_BASE + AON_EVENT_O_RTCSEL);
    ui32Ctrl &= ~(AON_EVENT_RTCSEL_RTC_CH1_CAPT_EV_M);
    ui32Ctrl |= (ui32EventSrc & 0x3f) << AON_EVENT_RTCSEL_RTC_CH1_CAPT_EV_S;

    HWREG(AON_EVENT_BASE + AON_EVENT_O_RTCSEL) = ui32Ctrl;
}

//*****************************************************************************
//
//! \brief Get event source forwarded to AON Real Time Clock (RTC).
//!
//! A programmable event can be forwarded to the AON real time clock
//! for triggering a capture event on RTC channel 1.
//!
//! \return Returns an event source to the event AON fabric, i.e. one of the following:
//! - AON_EVENT_DIO0                   : Edge detect on DIO0. See hw_device.h
//! - ...
//! - AON_EVENT_DIO31                  : Edge detect on DIO31. See hw_device.h
//! - \ref AON_EVENT_IO                : Edge detect on any DIO
//! - \ref AON_EVENT_RTC_CH0           : RTC channel 0
//! - \ref AON_EVENT_RTC_CH1           : RTC channel 1
//! - \ref AON_EVENT_RTC_CH2           : RTC channel 2
//! - \ref AON_EVENT_RTC_CH0_DLY       : RTC channel 0 - delayed event
//! - \ref AON_EVENT_RTC_CH1_DLY       : RTC channel 1 - delayed event
//! - \ref AON_EVENT_RTC_CH2_DLY       : RTC channel 2 - delayed event
//! - \ref AON_EVENT_RTC_COMB_DLY      : RTC combined delayed event
//! - \ref AON_EVENT_RTC_UPD           : RTC Update Tick (16 kHz signal, i.e. event line toggles value every 32 kHz clock period)
//! - \ref AON_EVENT_JTAG              : JTAG generated event
//! - \ref AON_EVENT_AUX_SWEV0         : AUX Software triggered event #0
//! - \ref AON_EVENT_AUX_SWEV1         : AUX Software triggered event #1
//! - \ref AON_EVENT_AUX_SWEV2         : AUX Software triggered event #2
//! - \ref AON_EVENT_AUX_COMPA         : Comparator A triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_COMPB         : Comparator B triggered (synchronized in AUX)
//! - \ref AON_EVENT_AUX_ADC_DONE      : ADC conversion completed
//! - \ref AON_EVENT_AUX_TDC_DONE      : TDC completed or timed out
//! - \ref AON_EVENT_AUX_TIMER0_EV     : Timer 0 event
//! - \ref AON_EVENT_AUX_TIMER1_EV     : Timer 1 event
//! - \ref AON_EVENT_BATMON_TEMP       : BATMON temperature update event
//! - \ref AON_EVENT_BATMON_VOLT       : BATMON voltage update event
//! - \ref AON_EVENT_AUX_COMPB_ASYNC   : Comparator B triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_AUX_COMPB_ASYNC_N : Comparator B not triggered. Asynchronous signal directly from the AUX Comparator B
//! - \ref AON_EVENT_NONE              : No event, always low
//!
//! \sa AONEventRtcSet()
//
//*****************************************************************************
__STATIC_INLINE uint32_t
AONEventRtcGet(void)
{
    uint32_t ui32EventSrc;

    //
    // Return the active event.
    //
    ui32EventSrc = HWREG(AON_EVENT_BASE + AON_EVENT_O_RTCSEL);

    return ((ui32EventSrc & AON_EVENT_RTCSEL_RTC_CH1_CAPT_EV_M) >>
            AON_EVENT_RTCSEL_RTC_CH1_CAPT_EV_S);
}

//*****************************************************************************
//
// Support for DriverLib in ROM:
// Redirect to implementation in ROM when available.
//
//*****************************************************************************
#if !defined(DRIVERLIB_NOROM) && !defined(DOXYGEN)
    #include <driverlib/rom.h>
    #ifdef ROM_AONEventMcuWakeUpSet
        #undef  AONEventMcuWakeUpSet
        #define AONEventMcuWakeUpSet            ROM_AONEventMcuWakeUpSet
    #endif
    #ifdef ROM_AONEventMcuWakeUpGet
        #undef  AONEventMcuWakeUpGet
        #define AONEventMcuWakeUpGet            ROM_AONEventMcuWakeUpGet
    #endif
    #ifdef ROM_AONEventAuxWakeUpSet
        #undef  AONEventAuxWakeUpSet
        #define AONEventAuxWakeUpSet            ROM_AONEventAuxWakeUpSet
    #endif
    #ifdef ROM_AONEventAuxWakeUpGet
        #undef  AONEventAuxWakeUpGet
        #define AONEventAuxWakeUpGet            ROM_AONEventAuxWakeUpGet
    #endif
    #ifdef ROM_AONEventMcuSet
        #undef  AONEventMcuSet
        #define AONEventMcuSet                  ROM_AONEventMcuSet
    #endif
    #ifdef ROM_AONEventMcuGet
        #undef  AONEventMcuGet
        #define AONEventMcuGet                  ROM_AONEventMcuGet
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

#endif //  __AON_EVENT_H__

//*****************************************************************************
//
//! Close the Doxygen group.
//! @}
//! @}
//
//*****************************************************************************
