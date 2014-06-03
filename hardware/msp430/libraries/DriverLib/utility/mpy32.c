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
// mpy32.c - Driver for the mpy32 Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup mpy32_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifndef DRIVERLIB_LEGACY_MODE

#ifdef __MSP430_HAS_MPY32__
#include "mpy32.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Sets the write delay setting for the MPY32 module.
//!
//! This function sets up a write delay to the MPY module's registers, which
//! holds any writes to the registers until all calculations are complete.
//! There are two different settings, one which waits for 32-bit results to be
//! ready, and one which waits for 64-bit results to be ready. This prevents
//! unpredicatble results if registers are changed before the results are
//! ready.
//!
//! \param writeDelaySelect delays the write to any MPY32 register until the
//!        selected bit size of result has been written.
//!        Valid values are:
//!        - \b MPY32_WRITEDELAY_OFF [Default] - writes are not delayed
//!        - \b MPY32_WRITEDELAY_32BIT - writes are delayed until a 32-bit
//!           result is available in the result registers
//!        - \b MPY32_WRITEDELAY_64BIT - writes are delayed until a 64-bit
//!           result is available in the result registers
//!        \n Modified bits are \b MPYDLY32 and \b MPYDLYWRTEN of \b MPY32CTL0
//!        register.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setWriteDelay(uint16_t writeDelaySelect)
{
        HWREG16(MPY32_BASE + OFS_MPY32CTL0) &= ~(MPYDLY32 + MPYDLYWRTEN);
        HWREG16(MPY32_BASE + OFS_MPY32CTL0) |= writeDelaySelect;
}

//*****************************************************************************
//
//! \brief Enables Saturation Mode.
//!
//! This function enables saturation mode. When this is enabled, the result
//! read out from the MPY result registers is converted to the most-positive
//! number in the case of an overflow, or the most-negative number in the case
//! of an underflow. Please note, that the raw value in the registers does not
//! reflect the result returned, and if the saturation mode is disabled, then
//! the raw value of the registers will be returned instead.
//!
//!
//! \return None
//
//*****************************************************************************
void MPY32_setSaturationMode(void)
{
        HWREG8(MPY32_BASE + OFS_MPY32CTL0_L) |= MPYSAT;
}

//*****************************************************************************
//
//! \brief Disables Saturation Mode.
//!
//! This function disables saturation mode, which allows the raw result of the
//! MPY result registers to be returned.
//!
//!
//! \return None
//
//*****************************************************************************
void MPY32_resetSaturationMode(void)
{
        HWREG8(MPY32_BASE + OFS_MPY32CTL0_L) &= ~(MPYSAT);
}

//*****************************************************************************
//
//! \brief Enables Fraction Mode.
//!
//! This function enables fraction mode.
//!
//!
//! \return None
//
//*****************************************************************************
void MPY32_setFractionMode(void)
{
        HWREG8(MPY32_BASE + OFS_MPY32CTL0_L) |= MPYFRAC;
}

//*****************************************************************************
//
//! \brief Disables Fraction Mode.
//!
//! This function disables fraction mode.
//!
//!
//! \return None
//
//*****************************************************************************
void MPY32_resetFractionMode(void)
{
        HWREG8(MPY32_BASE + OFS_MPY32CTL0_L) &= ~(MPYFRAC);
}

//*****************************************************************************
//
//! \brief Sets an 8-bit value into operand 1.
//!
//! This function sets the first operand for multiplication and determines what
//! type of operation should be performed. Once the second operand is set, then
//! the operation will begin.
//!
//! \param multiplicationType is the type of multiplication to perform once the
//!        second operand is set.
//!        Valid values are:
//!        - \b MPY32_MULTIPLY_UNSIGNED
//!        - \b MPY32_MULTIPLY_SIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_UNSIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_SIGNED
//! \param operand is the 8-bit value to load into the 1st operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandOne8Bit(uint8_t multiplicationType,
                             uint8_t operand)
{
        HWREG8(MPY32_BASE + OFS_MPY + multiplicationType) = operand;
}

//*****************************************************************************
//
//! \brief Sets an 16-bit value into operand 1.
//!
//! This function sets the first operand for multiplication and determines what
//! type of operation should be performed. Once the second operand is set, then
//! the operation will begin.
//!
//! \param multiplicationType is the type of multiplication to perform once the
//!        second operand is set.
//!        Valid values are:
//!        - \b MPY32_MULTIPLY_UNSIGNED
//!        - \b MPY32_MULTIPLY_SIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_UNSIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_SIGNED
//! \param operand is the 16-bit value to load into the 1st operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandOne16Bit(uint8_t multiplicationType,
                              uint16_t operand)
{
        HWREG16(MPY32_BASE + OFS_MPY + multiplicationType) = operand;
}

//*****************************************************************************
//
//! \brief Sets an 24-bit value into operand 1.
//!
//! This function sets the first operand for multiplication and determines what
//! type of operation should be performed. Once the second operand is set, then
//! the operation will begin.
//!
//! \param multiplicationType is the type of multiplication to perform once the
//!        second operand is set.
//!        Valid values are:
//!        - \b MPY32_MULTIPLY_UNSIGNED
//!        - \b MPY32_MULTIPLY_SIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_UNSIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_SIGNED
//! \param operand is the 24-bit value to load into the 1st operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandOne24Bit(uint8_t multiplicationType,
                              uint32_t operand)
{
        multiplicationType <<= 1;
        HWREG16(MPY32_BASE + OFS_MPY32L + multiplicationType) = operand;
        HWREG8(MPY32_BASE + OFS_MPY32H + multiplicationType) = (operand >> 16);
}

//*****************************************************************************
//
//! \brief Sets an 32-bit value into operand 1.
//!
//! This function sets the first operand for multiplication and determines what
//! type of operation should be performed. Once the second operand is set, then
//! the operation will begin.
//!
//! \param multiplicationType is the type of multiplication to perform once the
//!        second operand is set.
//!        Valid values are:
//!        - \b MPY32_MULTIPLY_UNSIGNED
//!        - \b MPY32_MULTIPLY_SIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_UNSIGNED
//!        - \b MPY32_MULTIPLYACCUMULATE_SIGNED
//! \param operand is the 32-bit value to load into the 1st operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandOne32Bit(uint8_t multiplicationType,
                              uint32_t operand)
{
        multiplicationType <<= 1;
        HWREG16(MPY32_BASE + OFS_MPY32L + multiplicationType) = operand;
        HWREG16(MPY32_BASE + OFS_MPY32H + multiplicationType) = (operand >> 16);
}

//*****************************************************************************
//
//! \brief Sets an 8-bit value into operand 2, which starts the multiplication.
//!
//! This function sets the second operand of the multiplication operation and
//! starts the operation.
//!
//! \param operand is the 8-bit value to load into the 2nd operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandTwo8Bit(uint8_t operand)
{
        HWREG8(MPY32_BASE + OFS_OP2) = operand;
}

//*****************************************************************************
//
//! \brief Sets an 16-bit value into operand 2, which starts the
//! multiplication.
//!
//! This function sets the second operand of the multiplication operation and
//! starts the operation.
//!
//! \param operand is the 16-bit value to load into the 2nd operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandTwo16Bit(uint16_t operand)
{
        HWREG16(MPY32_BASE + OFS_OP2) = operand;
}

//*****************************************************************************
//
//! \brief Sets an 24-bit value into operand 2, which starts the
//! multiplication.
//!
//! This function sets the second operand of the multiplication operation and
//! starts the operation.
//!
//! \param operand is the 24-bit value to load into the 2nd operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandTwo24Bit(uint32_t operand)
{
        HWREG16(MPY32_BASE + OFS_OP2L) = operand;
        HWREG8(MPY32_BASE + OFS_OP2H) = (operand >> 16);
}

//*****************************************************************************
//
//! \brief Sets an 32-bit value into operand 2, which starts the
//! multiplication.
//!
//! This function sets the second operand of the multiplication operation and
//! starts the operation.
//!
//! \param operand is the 32-bit value to load into the 2nd operand.
//!
//! \return None
//
//*****************************************************************************
void MPY32_setOperandTwo32Bit(uint32_t operand)
{
        HWREG16(MPY32_BASE + OFS_OP2L) = operand;
        HWREG16(MPY32_BASE + OFS_OP2H) = (operand >> 16);
}

//*****************************************************************************
//
//! \brief Returns an 8-bit result of the last multiplication operation.
//!
//! This function returns the 8 least significant bits of the result registers.
//! This can improve efficiency if the operation has no more than an 8-bit
//! result.
//!
//!
//! \return The 8-bit result of the last multiplication operation.
//
//*****************************************************************************
uint8_t MPY32_getResult8Bit(void)
{
        return HWREG8(MPY32_BASE + OFS_RES0_L);
}

//*****************************************************************************
//
//! \brief Returns an 16-bit result of the last multiplication operation.
//!
//! This function returns the 16 least significant bits of the result
//! registers. This can improve efficiency if the operation has no more than a
//! 16-bit result.
//!
//!
//! \return The 16-bit result of the last multiplication operation.
//
//*****************************************************************************
uint16_t MPY32_getResult16Bit(void)
{
        return HWREG16(MPY32_BASE + OFS_RES0);
}

//*****************************************************************************
//
//! \brief Returns an 24-bit result of the last multiplication operation.
//!
//! This function returns the 24 least significant bits of the result
//! registers. This can improve efficiency if the operation has no more than an
//! 24-bit result.
//!
//!
//! \return The 24-bit result of the last multiplication operation.
//
//*****************************************************************************
uint32_t MPY32_getResult24Bit(void)
{
        uint32_t result = HWREG16(MPY32_BASE + OFS_RES1);

        result = (result << 16) + HWREG16(MPY32_BASE + OFS_RES0);
        return result;
}

//*****************************************************************************
//
//! \brief Returns an 32-bit result of the last multiplication operation.
//!
//! This function returns a 32-bit result of the last multiplication operation,
//! which is the maximum amount of bits of a 16 x 16 operation.
//!
//!
//! \return The 32-bit result of the last multiplication operation.
//
//*****************************************************************************
uint32_t MPY32_getResult32Bit(void)
{
        uint32_t result = HWREG16(MPY32_BASE + OFS_RES1);

        result = (result << 16) + HWREG16(MPY32_BASE + OFS_RES0);
        return result;
}

//*****************************************************************************
//
//! \brief Returns an 64-bit result of the last multiplication operation.
//!
//! This function returns all 64 bits of the result registers. The way this is
//! passed is with 4 integers contained within a uint16 struct.
//!
//!
//! \return The 64-bit result separated into 4 uint16_ts in a uint16 struct
//
//*****************************************************************************
uint64 MPY32_getResult64Bit(void)
{
        uint64 result;

        result.RES0 = HWREG16(MPY32_BASE + OFS_RES0);
        result.RES1 = HWREG16(MPY32_BASE + OFS_RES1);
        result.RES2 = HWREG16(MPY32_BASE + OFS_RES2);
        result.RES3 = HWREG16(MPY32_BASE + OFS_RES3);
        return result;
}

//*****************************************************************************
//
//! \brief Returns the Sum Extension of the last multiplication operation.
//!
//! This function returns the Sum Extension of the MPY module, which either
//! gives the sign after a signed operation or shows a carry after a multiply-
//! and-accumulate operation. The Sum Extension acts as a check for overflows
//! or underflows.
//!
//!
//! \return The value of the MPY32 module Sum Extension.
//
//*****************************************************************************
uint16_t MPY32_getSumExtension(void)
{
        return HWREG16(MPY32_BASE + OFS_SUMEXT);
}

//*****************************************************************************
//
//! \brief Returns the Carry Bitof the last multiplication operation.
//!
//! This function returns the Carry Bit of the MPY module, which either gives
//! the sign after a signed operation or shows a carry after a multiply- and-
//! accumulate operation.
//!
//!
//! \return The value of the MPY32 module Carry Bit 0x0 or 0x1.
//
//*****************************************************************************
uint16_t MPY32_getCarryBitValue(void)
{
        return HWREG16(MPY32_BASE + OFS_MPY32CTL0) | MPYC;
}

#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for mpy32_api
//! @}
//
//*****************************************************************************

#endif
