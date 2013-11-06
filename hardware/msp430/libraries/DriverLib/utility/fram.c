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
// Only include parts of code relevant for Energia device
//
//*****************************************************************************
#if defined(__MSP430FR5739__)

//*****************************************************************************
//
// fram.c - Driver for the fram Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup fram_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_FRAM_FR5XX__
#include "fram.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Write data into the fram memory in byte format.
//!
//! \param dataPtr is the pointer to the data to be written
//! \param framPtr is the pointer into which to write the data
//! \param numberOfBytes is the number of bytes to be written
//!
//! \return None
//
//*****************************************************************************
void FRAM_write8(uint8_t *dataPtr,
    uint8_t *framPtr,
    uint16_t numberOfBytes
    )
{
    while (numberOfBytes > 0)
    {
        //Write to Fram
        *framPtr++ = *dataPtr++;
        numberOfBytes--;
    }
}

//*****************************************************************************
//
//! \brief Write data into the fram memory in word format.
//!
//! \param dataPtr is the pointer to the data to be written
//! \param framPtr is the pointer into which to write the data
//! \param numberOfWords
//!
//
//*****************************************************************************
void FRAM_write16(uint16_t *dataPtr,uint16_t *framPtr,
		uint16_t numberOfWords)
{
    while (numberOfWords > 0)
    {
        //Write to Fram
        *framPtr++ = *dataPtr++;
        numberOfWords--;
    }

}

//*****************************************************************************
//
//! \brief Write data into the fram memory in long format, pass by reference
//!
//! \param dataPtr is the pointer to the data to be written
//! \param framPtr is the pointer into which to write the data
//! \param count
//!
//
//*****************************************************************************
void FRAM_write32(uint32_t *dataPtr,uint32_t *framPtr,
		uint16_t count)
{
    while (count > 0)
    {
        //Write to Fram
        *framPtr++ = *dataPtr++;
        count--;
    }
}

//*****************************************************************************
//
//! \brief Write data into the fram memory in long format, pass by value
//!
//! \param value is the value to written to FRAM memory
//! \param framPtr is the pointer into which to write the data
//! \param count
//!
//
//*****************************************************************************
void FRAM_memoryFill32 (uint32_t value,
    uint32_t *framPtr,
    uint16_t count
    )
{
    while (count> 0)
    {
        //Write to Fram
        *framPtr++ = value;
        count--;
    }
}

//*****************************************************************************
//
//! \brief Enables selected FRAM interrupt sources.
//!
//! If header file contains legacy definitions: FRAM_PUC_ON_DOUBLE_BIT_ERROR -
//! Enable PUC reset if FRAM detects double bit error is detected.
//! FRAM_DOUBLE_BIT_ERROR_INTERRUPT - Interrupts when a double bit error is
//! detected. FRAM_SINGLE_BIT_ERROR_INTERRUPT - Interrupts when a single bit
//! error is detected.
//!
//! \param interruptMask is the bit mask of the memory buffer interrupt sources
//!        to be disabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b FRAM_PUC_ON_UNCORRECTABLE_BIT - Enable PUC reset if FRAM
//!           uncorrectable bit error detected.
//!        - \b FRAM_UNCORRECTABLE_BIT_INTERRUPT - Interrupts when an
//!           uncorrectable bit error is detected.
//!        - \b FRAM_CORRECTABLE_BIT_INTERRUPT - Interrupts when a correctable
//!           bit error is detected.
//!        - \b FRAM_ACCESS_VIOLATION_INTERRUPT - Interrupts when an access
//!           violation occurs.
//!        - \b FRAM_ACCESS_TIME_ERROR_INTERRUPT - Interrupts when an access
//!           time error occurs.
//!
//! \return None
//
//*****************************************************************************
void FRAM_enableInterrupt (uint8_t interruptMask)
{

	uint16_t waitSelection;

	waitSelection=(HWREG16(FRAM_BASE + OFS_FRCTL0) & 0x00FF);
	// Clear lock in FRAM control registers
	HWREG16(FRAM_BASE + OFS_FRCTL0) = FWPW + waitSelection;

	// Enable user selected interrupt sources
    HWREG16(FRAM_BASE + OFS_GCCTL0) |= interruptMask;

}

//*****************************************************************************
//
//! \brief Returns the status of the selected FRAM interrupt flags.
//!
//! If header file contains legacy definitions: FRAM_SINGLE_BIT_ERROR_FLAG -
//! Interrupt flag is set if a correctable bit error has been detected and
//! corrected in the FRAM memory error detection logic.
//! FRAM_DOUBLE_BIT_ERROR_FLAG .- Interrupt flag is set if an uncorrectable bit
//! error has been detected in the FRAM memory error detection logic.
//!
//! \param interruptFlagMask is a bit mask of the interrupt flags status to be
//!        returned.
//!        Mask value is the logical OR of any of the following:
//!        - \b FRAM_ACCESS_TIME_ERROR_FLAG - Interrupt flag is set if a wrong
//!           setting for NPRECHG and NACCESS is set and FRAM access time is
//!           not hold.
//!        - \b FRAM_UNCORRECTABLE_BIT_FLAG - Interrupt flag is set if an
//!           uncorrectable bit error has been detected in the FRAM memory
//!           error detection logic.
//!        - \b FRAM_CORRECTABLE_BIT_FLAG - Interrupt flag is set if a
//!           correctable bit error has been detected and corrected in the FRAM
//!           memory error detection logic.
//!        - \b FRAM_ACCESS_VIOLATION_FLAG - Interrupt flag is set if an access
//!           violation is triggered.
//!
//! \return The current interrupt flag status for the corresponding mask.
//!         Return Logical OR of any of the following:
//!         - \b FRAM_ACCESS_TIME_ERROR_FLAG Interrupt flag is set if a wrong
//!         setting for NPRECHG and NACCESS is set and FRAM access time is not
//!         hold.
//!         - \b FRAM_UNCORRECTABLE_BIT_FLAG Interrupt flag is set if an
//!         uncorrectable bit error has been detected in the FRAM memory error
//!         detection logic.
//!         - \b FRAM_CORRECTABLE_BIT_FLAG Interrupt flag is set if a
//!         correctable bit error has been detected and corrected in the FRAM
//!         memory error detection logic.
//!         - \b FRAM_ACCESS_VIOLATION_FLAG Interrupt flag is set if an access
//!         violation is triggered.
//!         \n indicating the status of the masked flags
//
//*****************************************************************************
uint8_t FRAM_getInterruptStatus(uint16_t interruptFlagMask)
{
	return ( HWREG16(FRAM_BASE + OFS_GCCTL1) & interruptFlagMask );
}

//*****************************************************************************
//
//! \brief Disables selected FRAM interrupt sources.
//!
//! If header file contains legacy definitions: FRAM_PUC_ON_DOUBLE_BIT_ERROR -
//! Enable PUC reset if FRAM detects double bit error is detected.
//! FRAM_DOUBLE_BIT_ERROR_INTERRUPT - Interrupts when a double bit error is
//! detected. FRAM_SINGLE_BIT_ERROR_INTERRUPT - Interrupts when a single bit
//! error is detected.
//!
//! \param interruptMask is the bit mask of the memory buffer interrupt sources
//!        to be disabled.
//!        Mask value is the logical OR of any of the following:
//!        - \b FRAM_PUC_ON_UNCORRECTABLE_BIT - Enable PUC reset if FRAM
//!           uncorrectable bit error detected.
//!        - \b FRAM_UNCORRECTABLE_BIT_INTERRUPT - Interrupts when an
//!           uncorrectable bit error is detected.
//!        - \b FRAM_CORRECTABLE_BIT_INTERRUPT - Interrupts when a correctable
//!           bit error is detected.
//!        - \b FRAM_ACCESS_VIOLATION_INTERRUPT - Interrupts when an access
//!           violation occurs.
//!        - \b FRAM_ACCESS_TIME_ERROR_INTERRUPT - Interrupts when an access
//!           time error occurs.
//!
//! \return None
//
//*****************************************************************************
void FRAM_disableInterrupt(uint16_t interruptMask)
{
	uint16_t waitSelection;

	waitSelection=(HWREG16(FRAM_BASE + OFS_FRCTL0) & 0x00FF);
	//Clear lock in FRAM control registers
	HWREG16(FRAM_BASE + OFS_FRCTL0) = FWPW + waitSelection;

    HWREG16(FRAM_BASE + OFS_GCCTL0) &= ~(interruptMask);
}

//*****************************************************************************
//
//! \brief Configures the wait state control of the FRAM module
//! Configures the wait state control of the FRAM module. If using the
//! FRAM_AUTO_MODE the values for accessTime and prechargeTime do not matter.
//!
//! \param manualWaitState chooses if the wait state control is manual or
//!        automatic
//!        Valid values are:
//!        - \b FRAM_AUTO_MODE
//!        - \b FRAM_MANUAL_MODE
//! \param accessTime defines the number of CPU cycles required for precharge
//!        time
//!        Valid values are:
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_0
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_1
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_2
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_3
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_4
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_5
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_6
//!        - \b FRAM_PRECHARGE_TIME_CYCLES_7
//! \param prechargeTime
//!
//
//*****************************************************************************
void FRAM_configureWaitStateControl(uint8_t manualWaitState,
		uint8_t accessTime,
		uint8_t prechargeTime )
{
	// Clear lock in FRAM control registers
	HWREG16(FRAM_BASE + OFS_FRCTL0) = FWPW;

	HWREG8(FRAM_BASE + OFS_FRCTL0_L) |= ( accessTime | manualWaitState | prechargeTime);
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for fram_api
//! @}
//
//*****************************************************************************

#endif
