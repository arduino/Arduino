/******************************************************************************
*  Filename:       aon_rtc.c
*  Revised:        2015-03-06 16:03:05 +0100 (fr, 06 mar 2015)
*  Revision:       42910
*
*  Description:    Driver for the AON RTC.
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

#include <driverlib/aon_rtc.h>
#include <driverlib/cpu.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#ifndef DRIVERLIB_GENERATE_ROM
    #undef  AONRTCStatus
    #define AONRTCStatus                    NOROM_AONRTCStatus
    #undef  AONRTCEventClear
    #define AONRTCEventClear                NOROM_AONRTCEventClear
    #undef  AONRTCEventGet
    #define AONRTCEventGet                  NOROM_AONRTCEventGet
    #undef  AONRTCModeCh1Set
    #define AONRTCModeCh1Set                NOROM_AONRTCModeCh1Set
    #undef  AONRTCModeCh1Get
    #define AONRTCModeCh1Get                NOROM_AONRTCModeCh1Get
    #undef  AONRTCModeCh2Set
    #define AONRTCModeCh2Set                NOROM_AONRTCModeCh2Set
    #undef  AONRTCModeCh2Get
    #define AONRTCModeCh2Get                NOROM_AONRTCModeCh2Get
    #undef  AONRTCChannelEnable
    #define AONRTCChannelEnable             NOROM_AONRTCChannelEnable
    #undef  AONRTCChannelDisable
    #define AONRTCChannelDisable            NOROM_AONRTCChannelDisable
    #undef  AONRTCCompareValueSet
    #define AONRTCCompareValueSet           NOROM_AONRTCCompareValueSet
    #undef  AONRTCCompareValueGet
    #define AONRTCCompareValueGet           NOROM_AONRTCCompareValueGet
    #undef  AONRTCCurrentCompareValueGet
    #define AONRTCCurrentCompareValueGet    NOROM_AONRTCCurrentCompareValueGet
    #undef  AONRTCCurrentCompareValueGet
    #define AONRTCCurrentCompareValueGet    NOROM_AONRTCCurrentCompareValueGet
#endif

//*****************************************************************************
//
//! Check if the AON Real Time Clock is running.
//
//*****************************************************************************
uint32_t
AONRTCStatus(void)
{
    uint32_t ui32ChannelStatus;
    uint32_t ui32RtcStatus;

    //
    // Read out the status'
    //
    ui32ChannelStatus = HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL);
    ui32RtcStatus = HWREG(AON_RTC_BASE + AON_RTC_O_CTL) &
                    AON_RTC_CTL_EN ? AON_RTC_ACTIVE : 0;

    //
    // Return the status
    //
    ui32RtcStatus |= (ui32ChannelStatus & AON_RTC_CHCTL_CH2_EN ?
                      AON_RTC_CH2 : 0) |
                     (ui32ChannelStatus & AON_RTC_CHCTL_CH1_EN ?
                      AON_RTC_CH1 : 0) |
                     (ui32ChannelStatus & AON_RTC_CHCTL_CH0_EN ?
                      AON_RTC_CH0 : 0);
    return ui32RtcStatus;
}

//*****************************************************************************
//
//! Clear event from a specified channel
//
//*****************************************************************************
void
AONRTCEventClear(uint32_t ui32Channel)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Channel == AON_RTC_CH0) ||
           (ui32Channel == AON_RTC_CH1) ||
           (ui32Channel == AON_RTC_CH2));

    if(ui32Channel & AON_RTC_CH0)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_EVFLAGS) = AON_RTC_EVFLAGS_CH0;
    }
    else if(ui32Channel & AON_RTC_CH1)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_EVFLAGS) = AON_RTC_EVFLAGS_CH1;
    }
    else if(ui32Channel & AON_RTC_CH2)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_EVFLAGS) = AON_RTC_EVFLAGS_CH2;
    }
}

//*****************************************************************************
//
//! Get event status for a specified channel
//
//*****************************************************************************
bool
AONRTCEventGet(uint32_t ui32Channel)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Channel == AON_RTC_CH0) ||
           (ui32Channel == AON_RTC_CH1) ||
           (ui32Channel == AON_RTC_CH2));

    if(ui32Channel & AON_RTC_CH0)
    {
        return ((HWREG(AON_RTC_BASE + AON_RTC_O_EVFLAGS) &
                 AON_RTC_EVFLAGS_CH0) ? true : false);
    }
    else if(ui32Channel & AON_RTC_CH1)
    {
        return ((HWREG(AON_RTC_BASE + AON_RTC_O_EVFLAGS) &
                 AON_RTC_EVFLAGS_CH1) ? true : false);
    }
    else if(ui32Channel & AON_RTC_CH2)
    {
        return ((HWREG(AON_RTC_BASE + AON_RTC_O_EVFLAGS) &
                 AON_RTC_EVFLAGS_CH2) ? true : false);
    }

    return(false);
}

//*****************************************************************************
//
//! Set operational mode of channel 1
//
//*****************************************************************************
void
AONRTCModeCh1Set(uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Mode == AON_RTC_MODE_CH1_CAPTURE) ||
           (ui32Mode == AON_RTC_MODE_CH1_COMPARE));

    if(ui32Mode == AON_RTC_MODE_CH1_CAPTURE)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) |= AON_RTC_CHCTL_CH1_CAPT_EN;
    }
    else if(ui32Mode == AON_RTC_MODE_CH1_COMPARE)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) &= ~(AON_RTC_CHCTL_CH1_CAPT_EN);
    }
}

//*****************************************************************************
//
//! Get operational mode of channel 1
//
//*****************************************************************************
uint32_t
AONRTCModeCh1Get(void)
{
    if(HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) & AON_RTC_CHCTL_CH1_CAPT_EN)
    {
        return(AON_RTC_MODE_CH1_CAPTURE);
    }
    else
    {
        return(AON_RTC_MODE_CH1_COMPARE);
    }
}

//*****************************************************************************
//
//! Set operational mode of channel 2
//
//*****************************************************************************
void
AONRTCModeCh2Set(uint32_t ui32Mode)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Mode == AON_RTC_MODE_CH2_CONTINUOUS) ||
           (ui32Mode == AON_RTC_MODE_CH2_NORMALCOMPARE));

    if(ui32Mode == AON_RTC_MODE_CH2_CONTINUOUS)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) |= AON_RTC_CHCTL_CH2_CONT_EN;
    }
    else if(ui32Mode == AON_RTC_MODE_CH2_NORMALCOMPARE)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) &= ~(AON_RTC_CHCTL_CH2_CONT_EN);
    }
}

//*****************************************************************************
//
//! Get operational mode of channel 2
//
//*****************************************************************************
uint32_t
AONRTCModeCh2Get(void)
{
    if(HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) & AON_RTC_CHCTL_CH2_CONT_EN)
    {
        return(AON_RTC_MODE_CH2_CONTINUOUS);
    }
    else
    {
        return(AON_RTC_MODE_CH2_NORMALCOMPARE);
    }
}

//*****************************************************************************
//
//! Enable event operation for the specified channel
//
//*****************************************************************************
void
AONRTCChannelEnable(uint32_t ui32Channel)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Channel == AON_RTC_CH0) ||
           (ui32Channel == AON_RTC_CH1) ||
           (ui32Channel == AON_RTC_CH2));

    if(ui32Channel & AON_RTC_CH0)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) |= AON_RTC_CHCTL_CH0_EN;
    }
    else if(ui32Channel & AON_RTC_CH1)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) |= AON_RTC_CHCTL_CH1_EN;
    }
    else if(ui32Channel & AON_RTC_CH2)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) |= AON_RTC_CHCTL_CH2_EN;
    }
}

//*****************************************************************************
//
//! Disable event operation for the specified channel
//
//*****************************************************************************
void
AONRTCChannelDisable(uint32_t ui32Channel)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Channel == AON_RTC_CH0) ||
           (ui32Channel == AON_RTC_CH1) ||
           (ui32Channel == AON_RTC_CH2));

    if(ui32Channel & AON_RTC_CH0)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) &= ~(AON_RTC_CHCTL_CH0_EN);
    }
    else if(ui32Channel & AON_RTC_CH1)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) &= ~(AON_RTC_CHCTL_CH1_EN);
    }
    else if(ui32Channel & AON_RTC_CH2)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CHCTL) &= ~(AON_RTC_CHCTL_CH2_EN);
    }
}

//*****************************************************************************
//
//! Set the compare value for the given channel
//
//*****************************************************************************
void
AONRTCCompareValueSet(uint32_t ui32Channel, uint32_t ui32CompValue)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Channel == AON_RTC_CH0) ||
           (ui32Channel == AON_RTC_CH1) ||
           (ui32Channel == AON_RTC_CH2));

    if(ui32Channel & AON_RTC_CH0)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CH0CMP) = ui32CompValue;
    }
    else if(ui32Channel & AON_RTC_CH1)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CH1CMP) = ui32CompValue;
    }
    else if(ui32Channel & AON_RTC_CH2)
    {
        HWREG(AON_RTC_BASE + AON_RTC_O_CH2CMP) = ui32CompValue;
    }
}

//*****************************************************************************
//
//! Get the compare value for the given channel
//
//*****************************************************************************
uint32_t
AONRTCCompareValueGet(uint32_t ui32Channel)
{
    //
    // Check the arguments
    //
    ASSERT((ui32Channel == AON_RTC_CH0) ||
           (ui32Channel == AON_RTC_CH1) ||
           (ui32Channel == AON_RTC_CH2));

    if(ui32Channel & AON_RTC_CH0)
    {
        return(HWREG(AON_RTC_BASE + AON_RTC_O_CH0CMP));
    }
    else if(ui32Channel & AON_RTC_CH1)
    {
        return(HWREG(AON_RTC_BASE + AON_RTC_O_CH1CMP));
    }
    else if(ui32Channel & AON_RTC_CH2)
    {
        return(HWREG(AON_RTC_BASE + AON_RTC_O_CH2CMP));
    }
    //
    // Should never return from here!
    //
    return(0);
}

//*****************************************************************************
//
// Get the current value of the RTC counter in a format compatible to the compare registers.
//
//*****************************************************************************
extern uint32_t AONRTCCurrentCompareValueGet( void )
{
    uint32_t   ui32CurrentSec    ;
    uint32_t   ui32CurrentSubSec ;
    bool       bIrqEnabled       ;

    //
    // Disable interrupts and store if interrupts was already disabled
    // Must disable interrupt in order to guarantee that you don't get
    // an interrupt reading AON_RTC_O_SEC once more in between.
    //
    bIrqEnabled = ( ! CPUcpsid() );

    //
    // Make sure that SEC is read before SUBSEC since SUBSEC will be
    // latched by hardware when SEC is read and hence guarantee that
    // the two registers represents the same timestamp.
    //
    ui32CurrentSec    = HWREG( AON_RTC_BASE + AON_RTC_O_SEC    );
    ui32CurrentSubSec = HWREG( AON_RTC_BASE + AON_RTC_O_SUBSEC );

    //
    // Reenable interrupt if it was enabled initially
    //
    if ( bIrqEnabled ) {
        CPUcpsie();
    }

    return (( ui32CurrentSec << 16 ) | ( ui32CurrentSubSec >> 16 ));
}
