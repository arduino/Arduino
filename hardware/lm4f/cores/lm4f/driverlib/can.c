//*****************************************************************************
//
// can.c - Driver for the CAN module.
//
// Copyright (c) 2006-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup can_api
//! @{
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_can.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "driverlib/can.h"
#include "driverlib/debug.h"
#include "driverlib/interrupt.h"

//*****************************************************************************
//
// This is the maximum number that can be stored as an 11bit Message
// identifier.
//
//*****************************************************************************
#define CAN_MAX_11BIT_MSG_ID    0x7ff

//*****************************************************************************
//
// The maximum CAN bit timing divisor is 19.
//
//*****************************************************************************
#define CAN_MAX_BIT_DIVISOR     19

//*****************************************************************************
//
// The minimum CAN bit timing divisor is 4.
//
//*****************************************************************************
#define CAN_MIN_BIT_DIVISOR     4

//*****************************************************************************
//
// The maximum CAN pre-divisor is 1024.
//
//*****************************************************************************
#define CAN_MAX_PRE_DIVISOR     1024

//*****************************************************************************
//
// The minimum CAN pre-divisor is 1.
//
//*****************************************************************************
#define CAN_MIN_PRE_DIVISOR     1

//*****************************************************************************
//
// Converts a set of CAN bit timing values into the value that needs to be
// programmed into the CAN_BIT register to achieve those timings.
//
//*****************************************************************************
#define CAN_BIT_VALUE(seg1, seg2, sjw)                                        \
                                ((((seg1 - 1) << CAN_BIT_TSEG1_S) &           \
                                  CAN_BIT_TSEG1_M) |                          \
                                 (((seg2 - 1) << CAN_BIT_TSEG2_S) &           \
                                  CAN_BIT_TSEG2_M) |                          \
                                 (((sjw - 1) << CAN_BIT_SJW_S) &              \
                                  CAN_BIT_SJW_M))

//*****************************************************************************
//
// This table is used by the CANBitRateSet() API as the register defaults for
// the bit timing values.
//
//*****************************************************************************
static const uint16_t g_ui16CANBitValues[] =
{
    CAN_BIT_VALUE(2, 1, 1),     // 4 clocks/bit
    CAN_BIT_VALUE(3, 1, 1),     // 5 clocks/bit
    CAN_BIT_VALUE(3, 2, 2),     // 6 clocks/bit
    CAN_BIT_VALUE(4, 2, 2),     // 7 clocks/bit
    CAN_BIT_VALUE(4, 3, 3),     // 8 clocks/bit
    CAN_BIT_VALUE(5, 3, 3),     // 9 clocks/bit
    CAN_BIT_VALUE(5, 4, 4),     // 10 clocks/bit
    CAN_BIT_VALUE(6, 4, 4),     // 11 clocks/bit
    CAN_BIT_VALUE(6, 5, 4),     // 12 clocks/bit
    CAN_BIT_VALUE(7, 5, 4),     // 13 clocks/bit
    CAN_BIT_VALUE(7, 6, 4),     // 14 clocks/bit
    CAN_BIT_VALUE(8, 6, 4),     // 15 clocks/bit
    CAN_BIT_VALUE(8, 7, 4),     // 16 clocks/bit
    CAN_BIT_VALUE(9, 7, 4),     // 17 clocks/bit
    CAN_BIT_VALUE(9, 8, 4),     // 18 clocks/bit
    CAN_BIT_VALUE(10, 8, 4)     // 19 clocks/bit
};

//*****************************************************************************
//
//! \internal
//! Checks a CAN base address.
//!
//! \param ui32Base is the base address of the CAN controller.
//!
//! This function determines if a CAN controller base address is valid.
//!
//! \return Returns \b true if the base address is valid and \b false
//! otherwise.
//
//*****************************************************************************
#ifdef DEBUG
static bool
_CANBaseValid(uint32_t ui32Base)
{
    return((ui32Base == CAN0_BASE) || (ui32Base == CAN1_BASE));
}
#endif

//*****************************************************************************
//
//! Returns the CAN controller interrupt number.
//!
//! \param ui32Base is the base address of the selected CAN controller
//!
//! This function returns the interrupt number for the CAN module with the base
//! address passed in the \e ui32Base parameter.
//!
//! \return Returns a CAN interrupt number or 0 if the interrupt does not
//! exist.
//
//*****************************************************************************
static uint_fast8_t
_CANIntNumberGet(uint32_t ui32Base)
{
    uint_fast8_t ui8Int;

    ASSERT((ui32Base == CAN0_BASE) || (ui32Base == CAN1_BASE));

    ui8Int = 0;

    //
    // Find the valid interrupt number for this CAN controller.
    //
    if(CLASS_IS_BLIZZARD)
    {
        if(ui32Base == CAN0_BASE)
        {
            ui8Int = INT_CAN0_BLIZZARD;
        }
        else if(ui32Base == CAN1_BASE)
        {
            ui8Int = INT_CAN1_BLIZZARD;
        }
    }
    else if(CLASS_IS_SNOWFLAKE)
    {
        if(ui32Base == CAN0_BASE)
        {
            ui8Int = INT_CAN0_SNOWFLAKE;
        }
        else if(ui32Base == CAN1_BASE)
        {
            ui8Int = INT_CAN1_SNOWFLAKE;
        }
    }

    return(ui8Int);
}

//*****************************************************************************
//
//! \internal
//! Copies data from a buffer to the CAN Data registers.
//!
//! \param pui8Data is a pointer to the data to be written out to the CAN
//! controller's data registers.
//! \param pui32Register is an uint32_t pointer to the first register of the
//! CAN controller's data registers.  For example, in order to use the IF1
//! register set on CAN controller 0, the value would be: \b CAN0_BASE \b +
//! \b CAN_O_IF1DA1.
//! \param iSize is the number of bytes to copy into the CAN controller.
//!
//! This function takes the steps necessary to copy data from a contiguous
//! buffer in memory into the non-contiguous data registers used by the CAN
//! controller.  This function is rarely used outside of the CANMessageSet()
//! function.
//!
//! \return None.
//
//*****************************************************************************
static void
_CANDataRegWrite(uint8_t *pui8Data, uint32_t *pui32Register, uint32_t ui32Size)
{
    uint32_t ui32Idx, ui32Value;

    //
    // Loop always copies 1 or 2 bytes per iteration.
    //
    for(ui32Idx = 0; ui32Idx < ui32Size; )
    {
        //
        // Write out the data 16 bits at a time since this is how the registers
        // are aligned in memory.
        //
        ui32Value = pui8Data[ui32Idx++];

        //
        // Only write the second byte if needed otherwise it will be zero.
        //
        if(ui32Idx < ui32Size)
        {
            ui32Value |= (pui8Data[ui32Idx++] << 8);
        }

        HWREG(pui32Register++) = ui32Value;
    }
}

//*****************************************************************************
//
//! \internal
//! Copies data from a buffer to the CAN Data registers.
//!
//! \param pui8Data is a pointer to the location to store the data read from
//! the CAN controller's data registers.
//! \param pui32Register is an uint32_t pointer to the first register of the
//! CAN controller's data registers.  For example, in order to use the IF1
//! register set on CAN controller 1, the value would be: \b CAN0_BASE \b +
//! \b CAN_O_IF1DA1.
//! \param iSize is the number of bytes to copy from the CAN controller.
//!
//! This function takes the steps necessary to copy data to a contiguous buffer
//! in memory from the non-contiguous data registers used by the CAN
//! controller.  This function is rarely used outside of the CANMessageGet()
//! function.
//!
//! \return None.
//
//*****************************************************************************
static void
_CANDataRegRead(uint8_t *pui8Data, uint32_t *pui32Register, uint32_t ui32Size)
{
    uint32_t ui32Idx, ui32Value;

    //
    // Loop always copies 1 or 2 bytes per iteration.
    //
    for(ui32Idx = 0; ui32Idx < ui32Size; )
    {
        //
        // Read out the data 16 bits at a time since this is how the registers
        // are aligned in memory.
        //
        ui32Value = HWREG(pui32Register++);

        //
        // Store the first byte.
        //
        pui8Data[ui32Idx++] = (uint8_t)ui32Value;

        //
        // Only read the second byte if needed.
        //
        if(ui32Idx < ui32Size)
        {
            pui8Data[ui32Idx++] = (uint8_t)(ui32Value >> 8);
        }
    }
}

//*****************************************************************************
//
//! Initializes the CAN controller after reset.
//!
//! \param ui32Base is the base address of the CAN controller.
//!
//! After reset, the CAN controller is left in the disabled state.  However,
//! the memory used for message objects contains undefined values and must be
//! cleared prior to enabling the CAN controller the first time.  This prevents
//! unwanted transmission or reception of data before the message objects are
//! configured.  This function must be called before enabling the controller
//! the first time.
//!
//! \return None.
//
//*****************************************************************************
void
CANInit(uint32_t ui32Base)
{
    uint32_t ui32Msg;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // Place CAN controller in init state, regardless of previous state.  This
    // will put controller in idle, and allow the message object RAM to be
    // programmed.
    //
    HWREG(ui32Base + CAN_O_CTL) = CAN_CTL_INIT;

    //
    // Wait for busy bit to clear
    //
    while(HWREG(ui32Base + CAN_O_IF1CRQ) & CAN_IF1CRQ_BUSY)
    {
    }

    //
    // Clear the message value bit in the arbitration register.  This indicates
    // the message is not valid and is a "safe" condition to leave the message
    // object.  The same arb reg is used to program all the message objects.
    //
    HWREG(ui32Base + CAN_O_IF1CMSK) = (CAN_IF1CMSK_WRNRD | CAN_IF1CMSK_ARB |
                                       CAN_IF1CMSK_CONTROL);
    HWREG(ui32Base + CAN_O_IF1ARB2) = 0;
    HWREG(ui32Base + CAN_O_IF1MCTL) = 0;

    //
    // Loop through to program all 32 message objects
    //
    for(ui32Msg = 1; ui32Msg <= 32; ui32Msg++)
    {
        //
        // Wait for busy bit to clear
        //
        while(HWREG(ui32Base + CAN_O_IF1CRQ) & CAN_IF1CRQ_BUSY)
        {
        }

        //
        // Initiate programming the message object
        //
        HWREG(ui32Base + CAN_O_IF1CRQ) = ui32Msg;
    }

    //
    // Make sure that the interrupt and new data flags are updated for the
    // message objects.
    //
    HWREG(ui32Base + CAN_O_IF1CMSK) = (CAN_IF1CMSK_NEWDAT |
                                       CAN_IF1CMSK_CLRINTPND);

    //
    // Loop through to program all 32 message objects
    //
    for(ui32Msg = 1; ui32Msg <= 32; ui32Msg++)
    {
        //
        // Wait for busy bit to clear.
        //
        while(HWREG(ui32Base + CAN_O_IF1CRQ) & CAN_IF1CRQ_BUSY)
        {
        }

        //
        // Initiate programming the message object
        //
        HWREG(ui32Base + CAN_O_IF1CRQ) = ui32Msg;
    }

    //
    // Acknowledge any pending status interrupts.
    //
    HWREG(ui32Base + CAN_O_STS);
}

//*****************************************************************************
//
//! Enables the CAN controller.
//!
//! \param ui32Base is the base address of the CAN controller to enable.
//!
//! Enables the CAN controller for message processing.  Once enabled, the
//! controller automatically transmits any pending frames, and processes any
//! received frames.  The controller can be stopped by calling CANDisable().
//! Prior to calling CANEnable(), CANInit() should have been called to
//! initialize the controller and the CAN bus clock should be configured by
//! calling CANBitTimingSet().
//!
//! \return None.
//
//*****************************************************************************
void
CANEnable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // Clear the init bit in the control register.
    //
    HWREG(ui32Base + CAN_O_CTL) &= ~CAN_CTL_INIT;
}

//*****************************************************************************
//
//! Disables the CAN controller.
//!
//! \param ui32Base is the base address of the CAN controller to disable.
//!
//! Disables the CAN controller for message processing.  When disabled, the
//! controller no longer automatically processes data on the CAN bus.  The
//! controller can be restarted by calling CANEnable().  The state of the CAN
//! controller and the message objects in the controller are left as they were
//! before this call was made.
//!
//! \return None.
//
//*****************************************************************************
void
CANDisable(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // Set the init bit in the control register.
    //
    HWREG(ui32Base + CAN_O_CTL) |= CAN_CTL_INIT;
}

//*****************************************************************************
//
//! Reads the current settings for the CAN controller bit timing.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param psClkParms is a pointer to a structure to hold the timing
//! parameters.
//!
//! This function reads the current configuration of the CAN controller bit
//! clock timing and stores the resulting information in the structure
//! supplied by the caller.  Refer to CANBitTimingSet() for the meaning of the
//! values that are returned in the structure pointed to by \e psClkParms.
//!
//! \return None.
//
//*****************************************************************************
void
CANBitTimingGet(uint32_t ui32Base, tCANBitClkParms *psClkParms)
{
    uint32_t ui32BitReg;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT(psClkParms);

    //
    // Read out all the bit timing values from the CAN controller registers.
    //
    ui32BitReg = HWREG(ui32Base + CAN_O_BIT);

    //
    // Set the phase 2 segment.
    //
    psClkParms->ui32Phase2Seg =
        ((ui32BitReg & CAN_BIT_TSEG2_M) >> CAN_BIT_TSEG2_S) + 1;

    //
    // Set the phase 1 segment.
    //
    psClkParms->ui32SyncPropPhase1Seg =
        ((ui32BitReg & CAN_BIT_TSEG1_M) >> CAN_BIT_TSEG1_S) + 1;

    //
    // Set the synchronous jump width.
    //
    psClkParms->ui32SJW = ((ui32BitReg & CAN_BIT_SJW_M) >> CAN_BIT_SJW_S) + 1;

    //
    // Set the pre-divider for the CAN bus bit clock.
    //
    psClkParms->ui32QuantumPrescaler =
        ((ui32BitReg & CAN_BIT_BRP_M) |
         ((HWREG(ui32Base + CAN_O_BRPE) & CAN_BRPE_BRPE_M) << 6)) + 1;
}

//*****************************************************************************
//
//! Sets the CAN bit timing values to a nominal setting based on a desired
//! bit rate.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param ui32SourceClock is the system clock for the device in Hz.
//! \param ui32BitRate is the desired bit rate.
//!
//! This function sets the CAN bit timing for the bit rate passed in the
//! \e ui32BitRate parameter based on the \e ui32SourceClock parameter.
//! Because the CAN clock is based off of the system clock, the calling
//! function should pass in the source clock rate either by retrieving it from
//! SysCtlClockGet() or using a specific value in Hz.  The CAN bit timing is
//! calculated assuming a minimal amount of propagation delay, which works for
//! most cases where the network length is int16_t.  If tighter timing
//! requirements or longer network lengths are needed, then the
//! CANBitTimingSet() function is available for full customization of all of
//! the CAN bit timing values.  Because not all bit rates can be matched
//! exactly, the bit rate is set to the value closest to the desired bit rate
//! without being higher than the \e ui32BitRate value.
//!
//! \note On some devices the source clock is fixed at 8MHz so the
//! \e ui32SourceClock should be set to 8000000.
//!
//! \return This function returns the bit rate that the CAN controller was
//! configured to use or it returns 0 to indicate that the bit rate was not
//! changed because the requested bit rate was not valid.
//!
//*****************************************************************************
uint32_t
CANBitRateSet(uint32_t ui32Base, uint32_t ui32SourceClock,
              uint32_t ui32BitRate)
{
    uint32_t ui32DesiredRatio;
    uint32_t ui32CANBits;
    uint32_t ui32PreDivide;
    uint32_t ui32RegValue;
    uint16_t ui16CANCTL;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT(ui32SourceClock);
    ASSERT(ui32BitRate);

    //
    // Calculate the desired clock rate.
    //
    ui32DesiredRatio = ui32SourceClock / ui32BitRate;

    //
    // Make sure that the ratio of CAN bit rate to processor clock is not too
    // small or too large.
    //
    ASSERT(ui32DesiredRatio <= (CAN_MAX_PRE_DIVISOR * CAN_MAX_BIT_DIVISOR));
    ASSERT(ui32DesiredRatio >= (CAN_MIN_PRE_DIVISOR * CAN_MIN_BIT_DIVISOR));

    //
    // Make sure that the Desired Ratio is not too large.  This enforces the
    // requirement that the bit rate is larger than requested.
    //
    if((ui32SourceClock / ui32DesiredRatio) > ui32BitRate)
    {
        ui32DesiredRatio += 1;
    }

    //
    // Check all possible values to find a matching value.
    //
    while(ui32DesiredRatio <= (CAN_MAX_PRE_DIVISOR * CAN_MAX_BIT_DIVISOR))
    {
        //
        // Loop through all possible CAN bit divisors.
        //
        for(ui32CANBits = CAN_MAX_BIT_DIVISOR;
            ui32CANBits >= CAN_MIN_BIT_DIVISOR; ui32CANBits--)
        {
            //
            // For a given CAN bit divisor save the pre divisor.
            //
            ui32PreDivide = ui32DesiredRatio / ui32CANBits;

            //
            // If the calculated divisors match the desired clock ratio then
            // return these bit rate and set the CAN bit timing.
            //
            if((ui32PreDivide * ui32CANBits) == ui32DesiredRatio)
            {
                //
                // Start building the bit timing value by adding the bit timing
                // in time quanta.
                //
                ui32RegValue = g_ui16CANBitValues[ui32CANBits -
                                                  CAN_MIN_BIT_DIVISOR];

                //
                // To set the bit timing register, the controller must be
                // placed in init mode (if not already), and also configuration
                // change bit enabled.  The state of the register should be
                // saved so it can be restored.
                //
                ui16CANCTL = HWREG(ui32Base + CAN_O_CTL);
                HWREG(ui32Base + CAN_O_CTL) = ui16CANCTL | CAN_CTL_INIT |
                                              CAN_CTL_CCE;

                //
                // Now add in the pre-scalar on the bit rate.
                //
                ui32RegValue |= ((ui32PreDivide - 1) & CAN_BIT_BRP_M);

                //
                // Set the clock bits in the and the lower bits of the
                // pre-scalar.
                //
                HWREG(ui32Base + CAN_O_BIT) = ui32RegValue;

                //
                // Set the divider upper bits in the extension register.
                //
                HWREG(ui32Base + CAN_O_BRPE) = ((ui32PreDivide - 1) >> 6) &
                                               CAN_BRPE_BRPE_M;

                //
                // Restore the saved CAN Control register.
                //
                HWREG(ui32Base + CAN_O_CTL) = ui16CANCTL;

                //
                // Return the computed bit rate.
                //
                return(ui32SourceClock / (ui32PreDivide * ui32CANBits));
            }
        }

        //
        // Move the divisor up one and look again.  Only in rare cases are
        // more than 2 loops required to find the value.
        //
        ui32DesiredRatio++;
    }

    //
    // A valid combination could not be found, so return 0 to indicate that the
    // bit rate was not changed.
    //
    return(0);
}

//*****************************************************************************
//
//! Configures the CAN controller bit timing.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param psClkParms points to the structure with the clock parameters.
//!
//! Configures the various timing parameters for the CAN bus bit timing:
//! Propagation segment, Phase Buffer 1 segment, Phase Buffer 2 segment, and
//! the Synchronization Jump Width.  The values for Propagation and Phase
//! Buffer 1 segments are derived from the combination
//! \e psClkParms->ui32SyncPropPhase1Seg parameter.  Phase Buffer 2 is
//! determined from the \e psClkParms->ui32Phase2Seg parameter.  These two
//! parameters, along with \e psClkParms->ui32SJW are based in units of bit
//! time quanta.  The actual quantum time is determined by the
//! \e psClkParms->ui32QuantumPrescaler value, which specifies the divisor for
//! the CAN module clock.
//!
//! The total bit time, in quanta, is the sum of the two Seg parameters,
//! as follows:
//!
//! bit_time_q = ui32SyncPropPhase1Seg + ui32Phase2Seg + 1
//!
//! Note that the Sync_Seg is always one quantum in duration, and is added
//! to derive the correct duration of Prop_Seg and Phase1_Seg.
//!
//! The equation to determine the actual bit rate is as follows:
//!
//! CAN Clock /
//! ((\e ui32SyncPropPhase1Seg + \e ui32Phase2Seg + 1) *
//! (\e ui32QuantumPrescaler))
//!
//! Thus with \e ui32SyncPropPhase1Seg = 4, \e ui32Phase2Seg = 1,
//! \e ui32QuantumPrescaler = 2 and an 8 MHz CAN clock, the bit rate is
//! (8 MHz) / ((5 + 2 + 1) * 2) or 500 Kbit/sec.
//!
//! \return None.
//
//*****************************************************************************
void
CANBitTimingSet(uint32_t ui32Base, tCANBitClkParms *psClkParms)
{
    uint32_t ui32BitReg, ui32SavedInit;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT(psClkParms);

    //
    // The phase 1 segment must be in the range from 2 to 16.
    //
    ASSERT((psClkParms->ui32SyncPropPhase1Seg >= 2) &&
           (psClkParms->ui32SyncPropPhase1Seg <= 16));

    //
    // The phase 2 segment must be in the range from 1 to 8.
    //
    ASSERT((psClkParms->ui32Phase2Seg >= 1) &&
           (psClkParms->ui32Phase2Seg <= 8));

    //
    // The synchronous jump windows must be in the range from 1 to 4.
    //
    ASSERT((psClkParms->ui32SJW >= 1) && (psClkParms->ui32SJW <= 4));

    //
    // The CAN clock pre-divider must be in the range from 1 to 1024.
    //
    ASSERT((psClkParms->ui32QuantumPrescaler <= 1024) &&
           (psClkParms->ui32QuantumPrescaler >= 1));

    //
    // To set the bit timing register, the controller must be placed in init
    // mode (if not already), and also configuration change bit enabled.  State
    // of the init bit should be saved so it can be restored at the end.
    //
    ui32SavedInit = HWREG(ui32Base + CAN_O_CTL);
    HWREG(ui32Base + CAN_O_CTL) = ui32SavedInit | CAN_CTL_INIT | CAN_CTL_CCE;

    //
    // Set the bit fields of the bit timing register according to the parms.
    //
    ui32BitReg = (((psClkParms->ui32Phase2Seg - 1) << CAN_BIT_TSEG2_S) &
                  CAN_BIT_TSEG2_M);
    ui32BitReg |= (((psClkParms->ui32SyncPropPhase1Seg - 1) <<
                    CAN_BIT_TSEG1_S) & CAN_BIT_TSEG1_M);
    ui32BitReg |= ((psClkParms->ui32SJW - 1) << CAN_BIT_SJW_S) & CAN_BIT_SJW_M;
    ui32BitReg |= (psClkParms->ui32QuantumPrescaler - 1) & CAN_BIT_BRP_M;
    HWREG(ui32Base + CAN_O_BIT) = ui32BitReg;

    //
    // Set the divider upper bits in the extension register.
    //
    HWREG(ui32Base + CAN_O_BRPE) =
        ((psClkParms->ui32QuantumPrescaler - 1) >> 6) & CAN_BRPE_BRPE_M;

    //
    // Clear the config change bit, and restore the init bit.
    //
    ui32SavedInit &= ~CAN_CTL_CCE;

    //
    // If Init was not set before, then clear it.
    //
    if(ui32SavedInit & CAN_CTL_INIT)
    {
        ui32SavedInit &= ~CAN_CTL_INIT;
    }

    HWREG(ui32Base + CAN_O_CTL) = ui32SavedInit;
}

//*****************************************************************************
//
//! Registers an interrupt handler for the CAN controller.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param pfnHandler is a pointer to the function to be called when the
//! enabled CAN interrupts occur.
//!
//! This function registers the interrupt handler in the interrupt vector
//! table, and enables CAN interrupts on the interrupt controller; specific CAN
//! interrupt sources must be enabled using CANIntEnable().  The interrupt
//! handler being registered must clear the source of the interrupt using
//! CANIntClear().
//!
//! If the application is using a static interrupt vector table stored in
//! flash, then it is not necessary to register the interrupt handler this way.
//! Instead, IntEnable() should be used to enable CAN interrupts on the
//! interrupt controller.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
CANIntRegister(uint32_t ui32Base, void (*pfnHandler)(void))
{
    uint_fast8_t ui8IntNumber;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // Get the actual interrupt number for this CAN controller.
    //
    ui8IntNumber = _CANIntNumberGet(ui32Base);
    ASSERT(ui8IntNumber != 0);

    //
    // Register the interrupt handler.
    //
    IntRegister(ui8IntNumber, pfnHandler);

    //
    // Enable the Ethernet interrupt.
    //
    IntEnable(ui8IntNumber);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the CAN controller.
//!
//! \param ui32Base is the base address of the controller.
//!
//! This function unregisters the previously registered interrupt handler and
//! disables the interrupt in the interrupt controller.
//!
//! \sa IntRegister() for important information about registering interrupt
//! handlers.
//!
//! \return None.
//
//*****************************************************************************
void
CANIntUnregister(uint32_t ui32Base)
{
    uint_fast8_t ui8IntNumber;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // Get the actual interrupt number for this CAN controller.
    //
    ui8IntNumber = _CANIntNumberGet(ui32Base);
    ASSERT(ui8IntNumber != 0);

    //
    // Disable the CAN interrupt.
    //
    IntDisable(ui8IntNumber);

    //
    // Register the interrupt handler.
    //
    IntUnregister(ui8IntNumber);
}

//*****************************************************************************
//
//! Enables individual CAN controller interrupt sources.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables specific interrupt sources of the CAN controller.
//! Only enabled sources cause a processor interrupt.
//!
//! The \e ui32IntFlags parameter is the logical OR of any of the following:
//!
//! - \b CAN_INT_ERROR - a controller error condition has occurred
//! - \b CAN_INT_STATUS - a message transfer has completed, or a bus error has
//!   been detected
//! - \b CAN_INT_MASTER - allow CAN controller to generate interrupts
//!
//! In order to generate any interrupts, \b CAN_INT_MASTER must be enabled.
//! Further, for any particular transaction from a message object to generate
//! an interrupt, that message object must have interrupts enabled (see
//! CANMessageSet()).  \b CAN_INT_ERROR will generate an interrupt if the
//! controller enters the ``bus off'' condition, or if the error counters reach
//! a limit.  \b CAN_INT_STATUS generates an interrupt under quite a few
//! status conditions and may provide more interrupts than the application
//! needs to handle.  When an interrupt occurs, use CANIntStatus() to determine
//! the cause.
//!
//! \return None.
//
//*****************************************************************************
void
CANIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT((ui32IntFlags & ~(CAN_CTL_EIE | CAN_CTL_SIE | CAN_CTL_IE)) == 0);

    //
    // Enable the specified interrupts.
    //
    HWREG(ui32Base + CAN_O_CTL) |= ui32IntFlags;
}

//*****************************************************************************
//
//! Disables individual CAN controller interrupt sources.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param ui32IntFlags is the bit mask of the interrupt sources to be
//! disabled.
//!
//! Disables the specified CAN controller interrupt sources.  Only enabled
//! interrupt sources can cause a processor interrupt.
//!
//! The \e ui32IntFlags parameter has the same definition as in the
//! CANIntEnable() function.
//!
//! \return None.
//
//*****************************************************************************
void
CANIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT((ui32IntFlags & ~(CAN_CTL_EIE | CAN_CTL_SIE | CAN_CTL_IE)) == 0);

    //
    // Disable the specified interrupts.
    //
    HWREG(ui32Base + CAN_O_CTL) &= ~ui32IntFlags;
}

//*****************************************************************************
//
//! Returns the current CAN controller interrupt status.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param eIntStsReg indicates which interrupt status register to read
//!
//! This function returns the value of one of two interrupt status registers.
//! The interrupt status register read is determined by the \e eIntStsReg
//! parameter, which can have one of the following values:
//!
//! - \b CAN_INT_STS_CAUSE - indicates the cause of the interrupt
//! - \b CAN_INT_STS_OBJECT - indicates pending interrupts of all message
//! objects
//!
//! \b CAN_INT_STS_CAUSE returns the value of the controller interrupt register
//! and indicates the cause of the interrupt.  The value returned is
//! \b CAN_INT_INTID_STATUS if the cause is a status interrupt.  In this case,
//! the status register should be read with the CANStatusGet() function.
//! Calling this function to read the status also clears the status
//! interrupt.  If the value of the interrupt register is in the range 1-32,
//! then this indicates the number of the highest priority message object that
//! has an interrupt pending.  The message object interrupt can be cleared by
//! using the CANIntClear() function, or by reading the message using
//! CANMessageGet() in the case of a received message.  The interrupt handler
//! can read the interrupt status again to make sure all pending interrupts are
//! cleared before returning from the interrupt.
//!
//! \b CAN_INT_STS_OBJECT returns a bit mask indicating which message objects
//! have pending interrupts.  This value can be used to discover all of the
//! pending interrupts at once, as opposed to repeatedly reading the interrupt
//! register by using \b CAN_INT_STS_CAUSE.
//!
//! \return Returns the value of one of the interrupt status registers.
//
//*****************************************************************************
uint32_t
CANIntStatus(uint32_t ui32Base, tCANIntStsReg eIntStsReg)
{
    uint32_t ui32Status;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // See which status the caller is looking for.
    //
    switch(eIntStsReg)
    {
        //
        // The caller wants the global interrupt status for the CAN controller
        // specified by ui32Base.
        //
        case CAN_INT_STS_CAUSE:
        {
            ui32Status = HWREG(ui32Base + CAN_O_INT);
            break;
        }

        //
        // The caller wants the current message status interrupt for all
        // messages.
        //
        case CAN_INT_STS_OBJECT:
        {
            //
            // Read and combine both 16 bit values into one 32bit status.
            //
            ui32Status = (HWREG(ui32Base + CAN_O_MSG1INT) &
                          CAN_MSG1INT_INTPND_M);
            ui32Status |= (HWREG(ui32Base + CAN_O_MSG2INT) << 16);
            break;
        }

        //
        // Request was for unknown status so just return 0.
        //
        default:
        {
            ui32Status = 0;
            break;
        }
    }

    //
    // Return the interrupt status value
    //
    return(ui32Status);
}

//*****************************************************************************
//
//! Clears a CAN interrupt source.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param ui32IntClr is a value indicating which interrupt source to clear.
//!
//! This function can be used to clear a specific interrupt source.  The
//! \e ui32IntClr parameter should be one of the following values:
//!
//! - \b CAN_INT_INTID_STATUS - Clears a status interrupt.
//! - 1-32 - Clears the specified message object interrupt
//!
//! It is not necessary to use this function to clear an interrupt.  This
//! function should only be used if the application wants to clear an interrupt
//! source without taking the normal interrupt action.
//!
//! Normally, the status interrupt is cleared by reading the controller status
//! using CANStatusGet().  A specific message object interrupt is normally
//! cleared by reading the message object using CANMessageGet().
//!
//! \note Because there is a write buffer in the Cortex-M processor, it may
//! take several clock cycles before the interrupt source is actually cleared.
//! Therefore, it is recommended that the interrupt source be cleared early in
//! the interrupt handler (as opposed to the very last action) to avoid
//! returning from the interrupt handler before the interrupt source is
//! actually cleared.  Failure to do so may result in the interrupt handler
//! being immediately reentered (because the interrupt controller still sees
//! the interrupt source asserted).
//!
//! \return None.
//
//*****************************************************************************
void
CANIntClear(uint32_t ui32Base, uint32_t ui32IntClr)
{
    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT((ui32IntClr == CAN_INT_INTID_STATUS) ||
           ((ui32IntClr >= 1) && (ui32IntClr <= 32)));

    if(ui32IntClr == CAN_INT_INTID_STATUS)
    {
        //
        // Simply read and discard the status to clear the interrupt.
        //
        HWREG(ui32Base + CAN_O_STS);
    }
    else
    {
        //
        // Wait to be sure that this interface is not busy.
        //
        while(HWREG(ui32Base + CAN_O_IF1CRQ) & CAN_IF1CRQ_BUSY)
        {
        }

        //
        // Only change the interrupt pending state by setting only the
        // CAN_IF1CMSK_CLRINTPND bit.
        //
        HWREG(ui32Base + CAN_O_IF1CMSK) = CAN_IF1CMSK_CLRINTPND;

        //
        // Send the clear pending interrupt command to the CAN controller.
        //
        HWREG(ui32Base + CAN_O_IF1CRQ) = ui32IntClr & CAN_IF1CRQ_MNUM_M;

        //
        // Wait to be sure that this interface is not busy.
        //
        while(HWREG(ui32Base + CAN_O_IF1CRQ) & CAN_IF1CRQ_BUSY)
        {
        }
    }
}

//*****************************************************************************
//
//! Sets the CAN controller automatic retransmission behavior.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param bAutoRetry enables automatic retransmission.
//!
//! This function enables or disables automatic retransmission of messages with
//! detected errors.  If \e bAutoRetry is \b true, then automatic
//! retransmission is enabled, otherwise it is disabled.
//!
//! \return None.
//
//*****************************************************************************
void
CANRetrySet(uint32_t ui32Base, bool bAutoRetry)
{
    uint32_t ui32CtlReg;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    ui32CtlReg = HWREG(ui32Base + CAN_O_CTL);

    //
    // Conditionally set the DAR bit to enable/disable auto-retry.
    //
    if(bAutoRetry)
    {
        //
        // Clearing the DAR bit tells the controller to not disable the
        // auto-retry of messages which were not transmitted or received
        // correctly.
        //
        ui32CtlReg &= ~CAN_CTL_DAR;
    }
    else
    {
        //
        // Setting the DAR bit tells the controller to disable the auto-retry
        // of messages which were not transmitted or received correctly.
        //
        ui32CtlReg |= CAN_CTL_DAR;
    }

    HWREG(ui32Base + CAN_O_CTL) = ui32CtlReg;
}

//*****************************************************************************
//
//! Returns the current setting for automatic retransmission.
//!
//! \param ui32Base is the base address of the CAN controller.
//!
//! This function reads the current setting for automatic retransmission in the
//! CAN controller and returns it to the caller.
//!
//! \return Returns \b true if automatic retransmission is enabled, \b false
//! otherwise.
//
//*****************************************************************************
bool
CANRetryGet(uint32_t ui32Base)
{
    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // Read the disable automatic retry setting from the CAN controller.
    //
    if(HWREG(ui32Base + CAN_O_CTL) & CAN_CTL_DAR)
    {
        //
        // Automatic data retransmission is not enabled.
        //
        return(false);
    }

    //
    // Automatic data retransmission is enabled.
    //
    return(true);
}

//*****************************************************************************
//
//! Reads one of the controller status registers.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param eStatusReg is the status register to read.
//!
//! This function reads a status register of the CAN controller and returns it
//! to the caller.
//! The different status registers are:
//!
//! - \b CAN_STS_CONTROL - the main controller status
//! - \b CAN_STS_TXREQUEST - bit mask of objects pending transmission
//! - \b CAN_STS_NEWDAT - bit mask of objects with new data
//! - \b CAN_STS_MSGVAL - bit mask of objects with valid configuration
//!
//! When reading the main controller status register, a pending status
//! interrupt is cleared.  This parameter should be used in the interrupt
//! handler for the CAN controller if the cause is a status interrupt.  The
//! controller status register fields are as follows:
//!
//! - \b CAN_STATUS_BUS_OFF - controller is in bus-off condition
//! - \b CAN_STATUS_EWARN - an error counter has reached a limit of at least 96
//! - \b CAN_STATUS_EPASS - CAN controller is in the error passive state
//! - \b CAN_STATUS_RXOK - a message was received successfully (independent of
//!   any message filtering).
//! - \b CAN_STATUS_TXOK - a message was successfully transmitted
//! - \b CAN_STATUS_LEC_MSK - mask of last error code bits (3 bits)
//! - \b CAN_STATUS_LEC_NONE - no error
//! - \b CAN_STATUS_LEC_STUFF - stuffing error detected
//! - \b CAN_STATUS_LEC_FORM - a format error occurred in the fixed format part
//!   of a message
//! - \b CAN_STATUS_LEC_ACK - a transmitted message was not acknowledged
//! - \b CAN_STATUS_LEC_BIT1 - dominant level detected when trying to send in
//!   recessive mode
//! - \b CAN_STATUS_LEC_BIT0 - recessive level detected when trying to send in
//!   dominant mode
//! - \b CAN_STATUS_LEC_CRC - CRC error in received message
//!
//! The remaining status registers consist of 32-bit-wide bit maps to the
//! message objects.  They can be used to quickly obtain information about the
//! status of all the message objects without needing to query each one.  They
//! contain the following information:
//!
//! - \b CAN_STS_TXREQUEST - if a message object's TXRQST bit is set, a
//!   transmission is pending on that object.  The application can use this
//!   information to determine which objects are still waiting to send a
//!   message.
//! - \b CAN_STS_NEWDAT - if a message object's NEWDAT bit is set, a new
//!   message has been received in that object, and has not yet been picked up
//!   by the host application
//! - \b CAN_STS_MSGVAL - if a message object's MSGVAL bit is set, the object
//!   has a valid configuration programmed.  The host application can use this
//!   information to determine which message objects are empty/unused.
//!
//! \return Returns the value of the status register.
//
//*****************************************************************************
uint32_t
CANStatusGet(uint32_t ui32Base, tCANStsReg eStatusReg)
{
    uint32_t ui32Status;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    switch(eStatusReg)
    {
        //
        // Just return the global CAN status register since that is what was
        // requested.
        //
        case CAN_STS_CONTROL:
        {
            ui32Status = HWREG(ui32Base + CAN_O_STS);
            HWREG(ui32Base + CAN_O_STS) = ~(CAN_STS_RXOK | CAN_STS_TXOK |
                                            CAN_STS_LEC_M);
            break;
        }

        //
        // Combine the Transmit status bits into one 32bit value.
        //
        case CAN_STS_TXREQUEST:
        {
            ui32Status = HWREG(ui32Base + CAN_O_TXRQ1);
            ui32Status |= HWREG(ui32Base + CAN_O_TXRQ2) << 16;
            break;
        }

        //
        // Combine the New Data status bits into one 32bit value.
        //
        case CAN_STS_NEWDAT:
        {
            ui32Status = HWREG(ui32Base + CAN_O_NWDA1);
            ui32Status |= HWREG(ui32Base + CAN_O_NWDA2) << 16;
            break;
        }

        //
        // Combine the Message valid status bits into one 32bit value.
        //
        case CAN_STS_MSGVAL:
        {
            ui32Status = HWREG(ui32Base + CAN_O_MSG1VAL);
            ui32Status |= HWREG(ui32Base + CAN_O_MSG2VAL) << 16;
            break;
        }

        //
        // Unknown CAN status requested so return 0.
        //
        default:
        {
            ui32Status = 0;
            break;
        }
    }
    return(ui32Status);
}

//*****************************************************************************
//
//! Reads the CAN controller error counter register.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param pui32RxCount is a pointer to storage for the receive error counter.
//! \param pui32TxCount is a pointer to storage for the transmit error counter.
//!
//! This function reads the error counter register and returns the transmit and
//! receive error counts to the caller along with a flag indicating if the
//! controller receive counter has reached the error passive limit.  The values
//! of the receive and transmit error counters are returned through the
//! pointers provided as parameters.
//!
//! After this call, \e *pui32RxCount holds the current receive error count
//! and \e *pui32TxCount holds the current transmit error count.
//!
//! \return Returns \b true if the receive error count has reached the error
//! passive limit, and \b false if the error count is below the error passive
//! limit.
//
//*****************************************************************************
bool
CANErrCntrGet(uint32_t ui32Base, uint32_t *pui32RxCount,
              uint32_t *pui32TxCount)
{
    uint32_t ui32CANError;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));

    //
    // Read the current count of transmit/receive errors.
    //
    ui32CANError = HWREG(ui32Base + CAN_O_ERR);

    //
    // Extract the error numbers from the register value.
    //
    *pui32RxCount = (ui32CANError & CAN_ERR_REC_M) >> CAN_ERR_REC_S;
    *pui32TxCount = (ui32CANError & CAN_ERR_TEC_M) >> CAN_ERR_TEC_S;

    if(ui32CANError & CAN_ERR_RP)
    {
        return(true);
    }
    return(false);
}

//*****************************************************************************
//
//! Configures a message object in the CAN controller.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param ui32ObjID is the object number to configure (1-32).
//! \param psMsgObject is a pointer to a structure containing message object
//! settings.
//! \param eMsgType indicates the type of message for this object.
//!
//! This function is used to configure any one of the 32 message objects in the
//! CAN controller.  A message object can be configured to be any type of CAN
//! message object as well as to use automatic transmission and reception.
//! This call also allows the message object to be configured to generate
//! interrupts on completion of message receipt or transmission.  The
//! message object can also be configured with a filter/mask so that actions
//! are only taken when a message that meets certain parameters is seen on the
//! CAN bus.
//!
//! The \e eMsgType parameter must be one of the following values:
//!
//! - \b MSG_OBJ_TYPE_TX - CAN transmit message object.
//! - \b MSG_OBJ_TYPE_TX_REMOTE - CAN transmit remote request message object.
//! - \b MSG_OBJ_TYPE_RX - CAN receive message object.
//! - \b MSG_OBJ_TYPE_RX_REMOTE - CAN receive remote request message object.
//! - \b MSG_OBJ_TYPE_RXTX_REMOTE - CAN remote frame receive remote, then
//!   transmit message object.
//!
//! The message object pointed to by \e psMsgObject must be populated by the
//! caller, as follows:
//!
//! - \e ui32MsgID - contains the message ID, either 11 or 29 bits.
//! - \e ui32MsgIDMask - mask of bits from \e ui32MsgID that must match if
//!   identifier filtering is enabled.
//! - \e ui32Flags
//!   - Set \b MSG_OBJ_TX_INT_ENABLE flag to enable interrupt on transmission.
//!   - Set \b MSG_OBJ_RX_INT_ENABLE flag to enable interrupt on receipt.
//!   - Set \b MSG_OBJ_USE_ID_FILTER flag to enable filtering based on the
//!     identifier mask specified by \e ui32MsgIDMask.
//! - \e ui32MsgLen - the number of bytes in the message data.  This parameter
//!   should be non-zero even for a remote frame; it should match the expected
//!   bytes of data in the responding data frame.
//! - \e pui8MsgData - points to a buffer containing up to 8 bytes of data for
//!   a data frame.
//!
//! \b Example: To send a data frame or remote frame (in response to a remote
//! request), take the following steps:
//!
//! -# Set \e eMsgType to \b MSG_OBJ_TYPE_TX.
//! -# Set \e psMsgObject->ui32MsgID to the message ID.
//! -# Set \e psMsgObject->ui32Flags.  Make sure to set
//!    \b MSG_OBJ_TX_INT_ENABLE to allow an interrupt to be generated when the
//!    message is sent.
//! -# Set \e psMsgObject->ui32MsgLen to the number of bytes in the data frame.
//! -# Set \e psMsgObject->pui8MsgData to point to an array containing the
//!    bytes to send in the message.
//! -# Call this function with \e ui32ObjID set to one of the 32 object
//!    buffers.
//!
//! \b Example: To receive a specific data frame, take the following steps:
//!
//! -# Set \e eMsgObjType to \b MSG_OBJ_TYPE_RX.
//! -# Set \e psMsgObject->ui32MsgID to the full message ID, or a partial mask
//!    to use partial ID matching.
//! -# Set \e psMsgObject->ui32MsgIDMask bits that should be used for masking
//!    during comparison.
//! -# Set \e psMsgObject->ui32Flags as follows:
//!    - Set \b MSG_OBJ_RX_INT_ENABLE flag to be interrupted when the data
//!      frame is received.
//!    - Set \b MSG_OBJ_USE_ID_FILTER flag to enable identifier-based
//!      filtering.
//! -# Set \e psMsgObject->ui32MsgLen to the number of bytes in the expected
//!    data frame.
//! -# The buffer pointed to by \e psMsgObject->pui8MsgData is not used by this
//!    call as no data is present at the time of the call.
//! -# Call this function with \e ui32ObjID set to one of the 32 object
//!    buffers.
//!
//! If you specify a message object buffer that already contains a message
//! definition, it is overwritten.
//!
//! \return None.
//
//*****************************************************************************
void
CANMessageSet(uint32_t ui32Base, uint32_t ui32ObjID,
              tCANMsgObject *psMsgObject, tMsgObjType eMsgType)
{
    uint16_t ui16CmdMaskReg;
    uint16_t ui16MaskReg0, ui16MaskReg1;
    uint16_t ui16ArbReg0, ui16ArbReg1;
    uint16_t ui16MsgCtrl;
    bool bTransferData;
    bool bUseExtendedID;

    bTransferData = 0;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT((ui32ObjID <= 32) && (ui32ObjID != 0));
    ASSERT((eMsgType == MSG_OBJ_TYPE_TX) ||
           (eMsgType == MSG_OBJ_TYPE_TX_REMOTE) ||
           (eMsgType == MSG_OBJ_TYPE_RX) ||
           (eMsgType == MSG_OBJ_TYPE_RX_REMOTE) ||
           (eMsgType == MSG_OBJ_TYPE_TX_REMOTE) ||
           (eMsgType == MSG_OBJ_TYPE_RXTX_REMOTE));

    //
    // Wait for busy bit to clear
    //
    while(HWREG(ui32Base + CAN_O_IF1CRQ) & CAN_IF1CRQ_BUSY)
    {
    }

    //
    // See if we need to use an extended identifier or not.
    //
    if((psMsgObject->ui32MsgID > CAN_MAX_11BIT_MSG_ID) ||
       (psMsgObject->ui32Flags & MSG_OBJ_EXTENDED_ID))
    {
        bUseExtendedID = 1;
    }
    else
    {
        bUseExtendedID = 0;
    }

    //
    // This is always a write to the Message object as this call is setting a
    // message object.  This call will also always set all size bits so it sets
    // both data bits.  The call will use the CONTROL register to set control
    // bits so this bit needs to be set as well.
    //
    ui16CmdMaskReg = (CAN_IF1CMSK_WRNRD | CAN_IF1CMSK_DATAA |
                      CAN_IF1CMSK_DATAB | CAN_IF1CMSK_CONTROL);

    //
    // Initialize the values to a known state before filling them in based on
    // the type of message object that is being configured.
    //
    ui16ArbReg0 = 0;
    ui16ArbReg1 = 0;
    ui16MsgCtrl = 0;
    ui16MaskReg0 = 0;
    ui16MaskReg1 = 0;

    switch(eMsgType)
    {
        //
        // Transmit message object.
        //
        case MSG_OBJ_TYPE_TX:
        {
            //
            // Set the TXRQST bit and the reset the rest of the register.
            //
            ui16MsgCtrl |= CAN_IF1MCTL_TXRQST;
            ui16ArbReg1 = CAN_IF1ARB2_DIR;
            bTransferData = 1;
            break;
        }

        //
        // Transmit remote request message object
        //
        case MSG_OBJ_TYPE_TX_REMOTE:
        {
            //
            // Set the TXRQST bit and the reset the rest of the register.
            //
            ui16MsgCtrl |= CAN_IF1MCTL_TXRQST;
            ui16ArbReg1 = 0;
            break;
        }

        //
        // Receive message object.
        //
        case MSG_OBJ_TYPE_RX:
        {
            //
            // This clears the DIR bit along with everything else.  The TXRQST
            // bit was cleared by defaulting ui16MsgCtrl to 0.
            //
            ui16ArbReg1 = 0;
            break;
        }

        //
        // Receive remote request message object.
        //
        case MSG_OBJ_TYPE_RX_REMOTE:
        {
            //
            // The DIR bit is set to one for remote receivers.  The TXRQST bit
            // was cleared by defaulting ui16MsgCtrl to 0.
            //
            ui16ArbReg1 = CAN_IF1ARB2_DIR;

            //
            // Set this object so that it only indicates that a remote frame
            // was received and allow for software to handle it by sending back
            // a data frame.
            //
            ui16MsgCtrl = CAN_IF1MCTL_UMASK;

            //
            // Use the full Identifier by default.
            //
            ui16MaskReg0 = 0xffff;
            ui16MaskReg1 = 0x1fff;

            //
            // Make sure to send the mask to the message object.
            //
            ui16CmdMaskReg |= CAN_IF1CMSK_MASK;
            break;
        }

        //
        // Remote frame receive remote, with auto-transmit message object.
        //
        case MSG_OBJ_TYPE_RXTX_REMOTE:
        {
            //
            // Oddly the DIR bit is set to one for remote receivers.
            //
            ui16ArbReg1 = CAN_IF1ARB2_DIR;

            //
            // Set this object to auto answer if a matching identifier is seen.
            //
            ui16MsgCtrl = CAN_IF1MCTL_RMTEN | CAN_IF1MCTL_UMASK;

            //
            // The data to be returned needs to be filled in.
            //
            bTransferData = 1;
            break;
        }

        //
        // This case should never happen due to the ASSERT statement at the
        // beginning of this function.
        //
        default:
        {
            return;
        }
    }

    //
    // Configure the Mask Registers.
    //
    if(psMsgObject->ui32Flags & MSG_OBJ_USE_ID_FILTER)
    {
        if(bUseExtendedID)
        {
            //
            // Set the 29 bits of Identifier mask that were requested.
            //
            ui16MaskReg0 = psMsgObject->ui32MsgIDMask & CAN_IF1MSK1_IDMSK_M;
            ui16MaskReg1 = ((psMsgObject->ui32MsgIDMask >> 16) &
                            CAN_IF1MSK2_IDMSK_M);
        }
        else
        {
            //
            // Lower 16 bit are unused so set them to zero.
            //
            ui16MaskReg0 = 0;

            //
            // Put the 11 bit Mask Identifier into the upper bits of the field
            // in the register.
            //
            ui16MaskReg1 = ((psMsgObject->ui32MsgIDMask << 2) &
                            CAN_IF1MSK2_IDMSK_M);
        }
    }

    //
    // If the caller wants to filter on the extended ID bit then set it.
    //
    if((psMsgObject->ui32Flags & MSG_OBJ_USE_EXT_FILTER) ==
       MSG_OBJ_USE_EXT_FILTER)
    {
        ui16MaskReg1 |= CAN_IF1MSK2_MXTD;
    }

    //
    // The caller wants to filter on the message direction field.
    //
    if((psMsgObject->ui32Flags & MSG_OBJ_USE_DIR_FILTER) ==
       MSG_OBJ_USE_DIR_FILTER)
    {
        ui16MaskReg1 |= CAN_IF1MSK2_MDIR;
    }

    if(psMsgObject->ui32Flags &
       (MSG_OBJ_USE_ID_FILTER | MSG_OBJ_USE_DIR_FILTER |
        MSG_OBJ_USE_EXT_FILTER))
    {
        //
        // Set the UMASK bit to enable using the mask register.
        //
        ui16MsgCtrl |= CAN_IF1MCTL_UMASK;

        //
        // Set the MASK bit so that this gets transferred to the Message
        // Object.
        //
        ui16CmdMaskReg |= CAN_IF1CMSK_MASK;
    }

    //
    // Set the Arb bit so that this gets transferred to the Message object.
    //
    ui16CmdMaskReg |= CAN_IF1CMSK_ARB;

    //
    // Configure the Arbitration registers.
    //
    if(bUseExtendedID)
    {
        //
        // Set the 29 bit version of the Identifier for this message object.
        //
        ui16ArbReg0 |= psMsgObject->ui32MsgID & CAN_IF1ARB1_ID_M;
        ui16ArbReg1 |= (psMsgObject->ui32MsgID >> 16) & CAN_IF1ARB2_ID_M;

        //
        // Mark the message as valid and set the extended ID bit.
        //
        ui16ArbReg1 |= CAN_IF1ARB2_MSGVAL | CAN_IF1ARB2_XTD;
    }
    else
    {
        //
        // Set the 11 bit version of the Identifier for this message object.
        // The lower 18 bits are set to zero.
        //
        ui16ArbReg1 |= (psMsgObject->ui32MsgID << 2) & CAN_IF1ARB2_ID_M;

        //
        // Mark the message as valid.
        //
        ui16ArbReg1 |= CAN_IF1ARB2_MSGVAL;
    }

    //
    // Set the data length since this is set for all transfers.  This is also a
    // single transfer and not a FIFO transfer so set EOB bit.
    //
    ui16MsgCtrl |= (psMsgObject->ui32MsgLen & CAN_IF1MCTL_DLC_M);

    //
    // Mark this as the last entry if this is not the last entry in a FIFO.
    //
    if((psMsgObject->ui32Flags & MSG_OBJ_FIFO) == 0)
    {
        ui16MsgCtrl |= CAN_IF1MCTL_EOB;
    }

    //
    // Enable transmit interrupts if they should be enabled.
    //
    if(psMsgObject->ui32Flags & MSG_OBJ_TX_INT_ENABLE)
    {
        ui16MsgCtrl |= CAN_IF1MCTL_TXIE;
    }

    //
    // Enable receive interrupts if they should be enabled.
    //
    if(psMsgObject->ui32Flags & MSG_OBJ_RX_INT_ENABLE)
    {
        ui16MsgCtrl |= CAN_IF1MCTL_RXIE;
    }

    //
    // Write the data out to the CAN Data registers if needed.
    //
    if(bTransferData)
    {
        _CANDataRegWrite(psMsgObject->pui8MsgData,
                         (uint32_t *)(ui32Base + CAN_O_IF1DA1),
                         psMsgObject->ui32MsgLen);
    }

    //
    // Write out the registers to program the message object.
    //
    HWREG(ui32Base + CAN_O_IF1CMSK) = ui16CmdMaskReg;
    HWREG(ui32Base + CAN_O_IF1MSK1) = ui16MaskReg0;
    HWREG(ui32Base + CAN_O_IF1MSK2) = ui16MaskReg1;
    HWREG(ui32Base + CAN_O_IF1ARB1) = ui16ArbReg0;
    HWREG(ui32Base + CAN_O_IF1ARB2) = ui16ArbReg1;
    HWREG(ui32Base + CAN_O_IF1MCTL) = ui16MsgCtrl;

    //
    // Transfer the message object to the message object specified by
    // ui32ObjID.
    //
    HWREG(ui32Base + CAN_O_IF1CRQ) = ui32ObjID & CAN_IF1CRQ_MNUM_M;
}

//*****************************************************************************
//
//! Reads a CAN message from one of the message object buffers.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param ui32ObjID is the object number to read (1-32).
//! \param psMsgObject points to a structure containing message object fields.
//! \param bClrPendingInt indicates whether an associated interrupt should be
//! cleared.
//!
//! This function is used to read the contents of one of the 32 message objects
//! in the CAN controller and return it to the caller.  The data returned is
//! stored in the fields of the caller-supplied structure pointed to by
//! \e psMsgObject.  The data consists of all of the parts of a CAN message,
//! plus some control and status information.
//!
//! Normally, this function is used to read a message object that has received
//! and stored a CAN message with a certain identifier.  However, this function
//! could also be used to read the contents of a message object in order to
//! load the fields of the structure in case only part of the structure must
//! be changed from a previous setting.
//!
//! When using CANMessageGet(), all of the same fields of the structure are
//! populated in the same way as when the CANMessageSet() function is used,
//! with the following exceptions:
//!
//! \e psMsgObject->ui32Flags:
//!
//! - \b MSG_OBJ_NEW_DATA indicates if this data is new since the last time it
//!   was read
//! - \b MSG_OBJ_DATA_LOST indicates that at least one message was received on
//!   this message object and not read by the host before being overwritten.
//!
//! \return None.
//
//*****************************************************************************
void
CANMessageGet(uint32_t ui32Base, uint32_t ui32ObjID,
              tCANMsgObject *psMsgObject, bool bClrPendingInt)
{
    uint16_t ui16CmdMaskReg;
    uint16_t ui16MaskReg0, ui16MaskReg1;
    uint16_t ui16ArbReg0, ui16ArbReg1;
    uint16_t ui16MsgCtrl;

    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT((ui32ObjID <= 32) && (ui32ObjID != 0));

    //
    // This is always a read to the Message object as this call is setting a
    // message object.
    //
    ui16CmdMaskReg = (CAN_IF1CMSK_DATAA | CAN_IF1CMSK_DATAB |
                      CAN_IF1CMSK_CONTROL | CAN_IF1CMSK_MASK |
                      CAN_IF1CMSK_ARB);

    //
    // Clear a pending interrupt and new data in a message object.
    //
    if(bClrPendingInt)
    {
        ui16CmdMaskReg |= CAN_IF1CMSK_CLRINTPND;
    }

    //
    // Set up the request for data from the message object.
    //
    HWREG(ui32Base + CAN_O_IF2CMSK) = ui16CmdMaskReg;

    //
    // Transfer the message object to the message object specified by
    // ui32ObjID.
    //
    HWREG(ui32Base + CAN_O_IF2CRQ) = ui32ObjID & CAN_IF1CRQ_MNUM_M;

    //
    // Wait for busy bit to clear
    //
    while(HWREG(ui32Base + CAN_O_IF2CRQ) & CAN_IF1CRQ_BUSY)
    {
    }

    //
    // Read out the IF Registers.
    //
    ui16MaskReg0 = HWREG(ui32Base + CAN_O_IF2MSK1);
    ui16MaskReg1 = HWREG(ui32Base + CAN_O_IF2MSK2);
    ui16ArbReg0 = HWREG(ui32Base + CAN_O_IF2ARB1);
    ui16ArbReg1 = HWREG(ui32Base + CAN_O_IF2ARB2);
    ui16MsgCtrl = HWREG(ui32Base + CAN_O_IF2MCTL);

    psMsgObject->ui32Flags = MSG_OBJ_NO_FLAGS;

    //
    // Determine if this is a remote frame by checking the TXRQST and DIR bits.
    //
    if((!(ui16MsgCtrl & CAN_IF1MCTL_TXRQST) &&
        (ui16ArbReg1 & CAN_IF1ARB2_DIR)) ||
       ((ui16MsgCtrl & CAN_IF1MCTL_TXRQST) &&
        (!(ui16ArbReg1 & CAN_IF1ARB2_DIR))))
    {
        psMsgObject->ui32Flags |= MSG_OBJ_REMOTE_FRAME;
    }

    //
    // Get the identifier out of the register, the format depends on size of
    // the mask.
    //
    if(ui16ArbReg1 & CAN_IF1ARB2_XTD)
    {
        //
        // Set the 29 bit version of the Identifier for this message object.
        //
        psMsgObject->ui32MsgID = (((ui16ArbReg1 & CAN_IF1ARB2_ID_M) << 16) |
                                  ui16ArbReg0);

        psMsgObject->ui32Flags |= MSG_OBJ_EXTENDED_ID;
    }
    else
    {
        //
        // The Identifier is an 11 bit value.
        //
        psMsgObject->ui32MsgID = (ui16ArbReg1 & CAN_IF1ARB2_ID_M) >> 2;
    }

    //
    // Indicate that we lost some data.
    //
    if(ui16MsgCtrl & CAN_IF1MCTL_MSGLST)
    {
        psMsgObject->ui32Flags |= MSG_OBJ_DATA_LOST;
    }

    //
    // Set the flag to indicate if ID masking was used.
    //
    if(ui16MsgCtrl & CAN_IF1MCTL_UMASK)
    {
        if(ui16ArbReg1 & CAN_IF1ARB2_XTD)
        {
            //
            // The Identifier Mask is assumed to also be a 29 bit value.
            //
            psMsgObject->ui32MsgIDMask =
                ((ui16MaskReg1 & CAN_IF1MSK2_IDMSK_M) << 16) | ui16MaskReg0;

            //
            // If this is a fully specified Mask and a remote frame then don't
            // set the MSG_OBJ_USE_ID_FILTER because the ID was not really
            // filtered.
            //
            if((psMsgObject->ui32MsgIDMask != 0x1fffffff) ||
               ((psMsgObject->ui32Flags & MSG_OBJ_REMOTE_FRAME) == 0))
            {
                psMsgObject->ui32Flags |= MSG_OBJ_USE_ID_FILTER;
            }
        }
        else
        {
            //
            // The Identifier Mask is assumed to also be an 11 bit value.
            //
            psMsgObject->ui32MsgIDMask =
                (ui16MaskReg1 & CAN_IF1MSK2_IDMSK_M) >> 2;

            //
            // If this is a fully specified Mask and a remote frame then don't
            // set the MSG_OBJ_USE_ID_FILTER because the ID was not really
            // filtered.
            //
            if((psMsgObject->ui32MsgIDMask != 0x7ff) ||
               ((psMsgObject->ui32Flags & MSG_OBJ_REMOTE_FRAME) == 0))
            {
                psMsgObject->ui32Flags |= MSG_OBJ_USE_ID_FILTER;
            }
        }

        //
        // Indicate if the extended bit was used in filtering.
        //
        if(ui16MaskReg1 & CAN_IF1MSK2_MXTD)
        {
            psMsgObject->ui32Flags |= MSG_OBJ_USE_EXT_FILTER;
        }

        //
        // Indicate if direction filtering was enabled.
        //
        if(ui16MaskReg1 & CAN_IF1MSK2_MDIR)
        {
            psMsgObject->ui32Flags |= MSG_OBJ_USE_DIR_FILTER;
        }
    }

    //
    // Set the interrupt flags.
    //
    if(ui16MsgCtrl & CAN_IF1MCTL_TXIE)
    {
        psMsgObject->ui32Flags |= MSG_OBJ_TX_INT_ENABLE;
    }
    if(ui16MsgCtrl & CAN_IF1MCTL_RXIE)
    {
        psMsgObject->ui32Flags |= MSG_OBJ_RX_INT_ENABLE;
    }

    //
    // See if there is new data available.
    //
    if(ui16MsgCtrl & CAN_IF1MCTL_NEWDAT)
    {
        //
        // Get the amount of data needed to be read.
        //
        psMsgObject->ui32MsgLen = (ui16MsgCtrl & CAN_IF1MCTL_DLC_M);

        //
        // Don't read any data for a remote frame, there is nothing valid in
        // that buffer anyway.
        //
        if((psMsgObject->ui32Flags & MSG_OBJ_REMOTE_FRAME) == 0)
        {
            //
            // Read out the data from the CAN registers.
            //
            _CANDataRegRead(psMsgObject->pui8MsgData,
                            (uint32_t *)(ui32Base + CAN_O_IF2DA1),
                            psMsgObject->ui32MsgLen);
        }

        //
        // Now clear out the new data flag.
        //
        HWREG(ui32Base + CAN_O_IF2CMSK) = CAN_IF1CMSK_NEWDAT;

        //
        // Transfer the message object to the message object specified by
        // ui32ObjID.
        //
        HWREG(ui32Base + CAN_O_IF2CRQ) = ui32ObjID & CAN_IF1CRQ_MNUM_M;

        //
        // Wait for busy bit to clear
        //
        while(HWREG(ui32Base + CAN_O_IF2CRQ) & CAN_IF1CRQ_BUSY)
        {
        }

        //
        // Indicate that there is new data in this message.
        //
        psMsgObject->ui32Flags |= MSG_OBJ_NEW_DATA;
    }
    else
    {
        //
        // Along with the MSG_OBJ_NEW_DATA not being set the amount of data
        // needs to be set to zero if none was available.
        //
        psMsgObject->ui32MsgLen = 0;
    }
}

//*****************************************************************************
//
//! Clears a message object so that it is no longer used.
//!
//! \param ui32Base is the base address of the CAN controller.
//! \param ui32ObjID is the message object number to disable (1-32).
//!
//! This function frees the specified message object from use.  Once a message
//! object has been ``cleared,'' it no longer automatically sends or receives
//! messages, nor does it generate interrupts.
//!
//! \return None.
//
//*****************************************************************************
void
CANMessageClear(uint32_t ui32Base, uint32_t ui32ObjID)
{
    //
    // Check the arguments.
    //
    ASSERT(_CANBaseValid(ui32Base));
    ASSERT((ui32ObjID >= 1) && (ui32ObjID <= 32));

    //
    // Wait for busy bit to clear
    //
    while(HWREG(ui32Base + CAN_O_IF1CRQ) & CAN_IF1CRQ_BUSY)
    {
    }

    //
    // Clear the message value bit in the arbitration register.  This indicates
    // the message is not valid.
    //
    HWREG(ui32Base + CAN_O_IF1CMSK) = CAN_IF1CMSK_WRNRD | CAN_IF1CMSK_ARB;
    HWREG(ui32Base + CAN_O_IF1ARB1) = 0;
    HWREG(ui32Base + CAN_O_IF1ARB2) = 0;

    //
    // Initiate programming the message object
    //
    HWREG(ui32Base + CAN_O_IF1CRQ) = ui32ObjID & CAN_IF1CRQ_MNUM_M;
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
