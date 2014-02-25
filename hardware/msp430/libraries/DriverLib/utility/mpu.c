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
// mpu.c - Driver for the mpu Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup mpu_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_MPU__
#include "mpu.h"

#include <assert.h>

//*****************************************************************************
//
// The following value is used by createTwoSegments, createThreeSegments to
// check the user has passed a valid segmentation value. This value was
// obtained from the User's Guide.
//
//*****************************************************************************
#define MPU_MAX_SEG_VALUE                                                0x13C1

//*****************************************************************************
//
//! This function creates two memory segments in FRAM allowing the user to set
//! access right to each segment. To set the correct value for seg1boundary,
//! the user must consult the Device Family User's Guide and provide the MPUSBx
//! value corresponding to the memory address where the user wants to create
//! the partition. Consult the "Segment Border Setting" section in the User's
//! Guide to find the options available for MPUSBx.
//!
//! \param baseAddress is the base address of the MPU module.
//! \param seg1boundary Valid values can be found in the Family User's Guide
//!        Valid values are:
//!        - \b MPU_Range of 0x4000 - 0x13C0
//! \param seg1accmask is the bit mask of access right for memory segment 1.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//! \param seg2accmask is the bit mask of access right for memory segment 2
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//!
//! Modified bits of \b MPUSAM register, bits of \b MPUSEG register and bits of
//! \b MPUCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void MPU_createTwoSegments(uint32_t baseAddress,
                           uint16_t seg1boundary,
                           uint8_t seg1accmask,
                           uint8_t seg2accmask
                           )
{

        // Verify access right mask for segment1 is a valid selection
        assert((seg1accmask < MPUSEG1VS) && ((seg1accmask == (MPU_EXEC | MPU_READ | MPU_WRITE)) ||
                                             (seg1accmask == (MPU_EXEC | MPU_READ)) ||
                                             (seg1accmask == (MPU_READ | MPU_WRITE)) ||
                                             (seg1accmask == (MPU_READ))));

        // Verify access right mask for segment2 is a valid selection
        assert((seg2accmask < MPUSEG1VS) && ((seg2accmask == (MPU_EXEC | MPU_READ | MPU_WRITE)) ||
                                             (seg2accmask == (MPU_EXEC | MPU_READ)) ||
                                             (seg2accmask == (MPU_READ | MPU_WRITE)) ||
                                             (seg2accmask == (MPU_READ))));

        // Write MPU password to allow MPU register configuration
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;

        // Verify segment1 boundary is valid selection
        assert(seg1boundary < MPU_MAX_SEG_VALUE);

        // Create two memory segmentations
        HWREG16(baseAddress + OFS_MPUSEGB1) = seg1boundary;
        HWREG16(baseAddress + OFS_MPUSEGB2) = seg1boundary;

        // Set access rights based on user's selection for segment1
        switch (seg1accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1XE + MPUSEG1RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE + MPUSEG1WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG1XE + MPUSEG1WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG1XE + MPUSEG1WE + MPUSEG1RE);
                break;
        }

        // Set access rights based on user's selection for segment2
        switch (seg2accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3WE + MPUSEG2WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3XE + MPUSEG3RE +
                                                     MPUSEG2XE + MPUSEG2RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3XE + MPUSEG2XE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE + MPUSEG3WE +
                                                     MPUSEG2RE + MPUSEG2WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3XE + MPUSEG3WE +
                                                       MPUSEG2XE + MPUSEG2WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE + MPUSEG2RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG3XE + MPUSEG3WE +
                                                      MPUSEG3RE + MPUSEG2XE + MPUSEG2WE + MPUSEG2RE);
                break;
        }

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! This function creates three memory segments in FRAM allowing the user to
//! set access right to each segment. To set the correct value for
//! seg1boundary, the user must consult the Device Family User's Guide and
//! provide the MPUSBx value corresponding to the memory address where the user
//! wants to create the partition. Consult the "Segment Border Setting" section
//! in the User's Guide to find the options available for MPUSBx.
//!
//! \param baseAddress is the base address of the MPU module.
//! \param seg1boundary Valid values can be found in the Family User's Guide
//!        Valid values are:
//!        - \b MPU_Range of 0x4000 - 0x13C0
//! \param seg2boundary Valid values can be found in the Family User's Guide
//!        Valid values are:
//!        - \b MPU_Range of 0x4000 - 0x13C0
//! \param seg1accmask is the bit mask of access right for memory segment 1.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//! \param seg2accmask is the bit mask of access right for memory segment 2.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//! \param seg3accmask is the bit mask of access right for memory segment 3.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//!
//! Modified bits of \b MPUSAM register, bits of \b MPUSEG register and bits of
//! \b MPUCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void MPU_createThreeSegments(uint32_t baseAddress,
                             uint16_t seg1boundary,
                             uint16_t seg2boundary,
                             uint8_t seg1accmask,
                             uint8_t seg2accmask,
                             uint8_t seg3accmask
                             )
{

        // Verify access right mask for segment1 is a valid selection
        assert((seg1accmask < MPUSEG1VS) && ((seg1accmask == (MPU_EXEC | MPU_READ | MPU_WRITE)) ||
                                             (seg1accmask == (MPU_EXEC | MPU_READ)) ||
                                             (seg1accmask == (MPU_READ | MPU_WRITE)) ||
                                             (seg1accmask == (MPU_READ))));

        // Verify access right mask for segment2 is a valid selection
        assert((seg2accmask < MPUSEG1VS) && ((seg2accmask == (MPU_EXEC | MPU_READ | MPU_WRITE)) ||
                                             (seg2accmask == (MPU_EXEC | MPU_READ)) ||
                                             (seg2accmask == (MPU_READ | MPU_WRITE)) ||
                                             (seg2accmask == (MPU_READ))));

        // Verify access right mask for segment3 is a valid selection
        assert((seg3accmask < MPUSEG1VS) && ((seg3accmask == (MPU_EXEC | MPU_READ | MPU_WRITE)) ||
                                             (seg3accmask == (MPU_EXEC | MPU_READ)) ||
                                             (seg3accmask == (MPU_READ | MPU_WRITE)) ||
                                             (seg3accmask == (MPU_READ))));

        // Write MPU password to allow MPU register configuration
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;

        // Verify segment1 boundary is valid selection
        assert(seg1boundary < MPU_MAX_SEG_VALUE);

        // Create two memory segmentations
        HWREG16(baseAddress + OFS_MPUSEGB1) = seg1boundary;
        HWREG16(baseAddress + OFS_MPUSEGB2) = seg2boundary;

        // Set access rights based on user's selection for segment1
        switch (seg1accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1XE + MPUSEG1RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE + MPUSEG1WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG1XE + MPUSEG1WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG1XE + MPUSEG1WE + MPUSEG1RE);
                break;
        }

        // Set access rights based on user's selection for segment2
        switch (seg2accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG2WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG2XE + MPUSEG2RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG2XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG2RE + MPUSEG2WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG2XE + MPUSEG2WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG2RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG2XE + MPUSEG2WE + MPUSEG2RE);
                break;
        }

        // Set access rights based on user's selection for segment3
        switch (seg3accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG3WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3XE + MPUSEG3RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG3XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE + MPUSEG3WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3XE + MPUSEG3WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG3XE + MPUSEG3WE + MPUSEG3RE);
                break;
        }

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief The following function enables the NMI Event if a Segment violation
//! has occurred.
//!
//! \param baseAddress is the base address of the MPU module.
//!
//! Modified bits of \b MPUCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void MPU_enableNMIevent(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW + MPUSEGIE;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief The following function enables the MPU module in the device.
//!
//! This function needs to be called once all memory segmentation has been
//! done. If this function is not called the MPU module will not be activated.
//!
//! \param baseAddress is the base address of the MPU module.
//!
//! Modified bits of \b MPUCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void MPU_start(uint32_t baseAddress)
{
        if (HWREG16(baseAddress + OFS_MPUCTL0) & MPUSEGIE)
                HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW  | MPUSEGIE | MPUENA;
        else
                HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW  | MPUENA;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief The following function enables PUC generation when an access
//! violation has Occurred on the memory segment selected by the user.
//!
//! \param baseAddress is the base address of the MPU module.
//! \param segment is the bit mask of memory segment that will generate a PUC
//!        when an access violation occurs.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_FIRST_SEG - PUC generation on first memory segment
//!        - \b MPU_SECOND_SEG - PUC generation on second memory segment
//!        - \b MPU_THIRD_SEG - PUC generation on third memory segment
//!
//! Modified bits of \b MPUSAM register and bits of \b MPUCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void MPU_enablePUCOnViolation(uint32_t baseAddress,
                              uint16_t segment
                              )
{
        // Verify user has selected a valid memory segment
        assert(0x00 != (segment & (MPU_FIRST_SEG + MPU_SECOND_SEG + MPU_THIRD_SEG)));

        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUSAM) |= segment;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief The following function disables PUC generation when an access
//! violation has Occurred on the memory segment selected by the user.
//!
//! \param baseAddress is the base address of the MPU module.
//! \param segment is the bit mask of memory segment that will NOT generate a
//!        PUC when an access violation occurs.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_FIRST_SEG - PUC generation on first memory segment
//!        - \b MPU_SECOND_SEG - PUC generation on second memory segment
//!        - \b MPU_THIRD_SEG - PUC generation on third memory segment
//!
//! Modified bits of \b MPUSAM register and bits of \b MPUCTL0 register.
//!
//! \return None
//
//*****************************************************************************
void MPU_disablePUCOnViolation(uint32_t baseAddress,
                               uint16_t segment
                               )
{
        // Verify user has selected a valid memory segment
        assert(0x00 != (segment & (MPU_FIRST_SEG + MPU_SECOND_SEG + MPU_THIRD_SEG)));

        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUSAM) &= ~segment;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Returns the memory segment violation flag status requested by the
//! user.
//!
//! \param baseAddress is the base address of the MPU module.
//! \param memAccFlag is the is the memory access violation flag.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_SEG_1_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 1 is detected
//!        - \b MPU_SEG_2_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 2 is detected
//!        - \b MPU_SEG_3_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 3 is detected
//!
//! \return Logical OR of any of the following:
//!         - \b MPU_SEG_1_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 1 is detected
//!         - \b MPU_SEG_2_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 2 is detected
//!         - \b MPU_SEG_3_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 3 is detected
//!         \n indicating the status of the masked flags.
//
//*****************************************************************************
uint16_t MPU_getInterruptStatus(uint32_t baseAddress,
                                uint16_t memAccFlag
                                )
{
        return HWREG16(baseAddress + OFS_MPUCTL1) & memAccFlag;
}

//*****************************************************************************
//
//! \brief Clears the masked interrupt flags
//!
//! Returns the memory segment violation flag status requested by the user or
//! if user is providing a bit mask value, the function will return a value
//! indicating if all flags were cleared.
//!
//! \param baseAddress is the base address of the MPU module.
//! \param memAccFlag is the is the memory access violation flag.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_SEG_1_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 1 is detected
//!        - \b MPU_SEG_2_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 2 is detected
//!        - \b MPU_SEG_3_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 3 is detected
//!
//! \return Logical OR of any of the following:
//!         - \b MPU_SEG_1_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 1 is detected
//!         - \b MPU_SEG_2_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 2 is detected
//!         - \b MPU_SEG_3_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 3 is detected
//!         \n indicating the status of the masked flags.
//
//*****************************************************************************
uint16_t MPU_clearInterruptFlag(uint32_t baseAddress,
                                uint16_t memAccFlag
                                )
{

        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUCTL1) &= ~memAccFlag;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;

        return HWREG16(baseAddress + OFS_MPUCTL1) & memAccFlag;
}

//*****************************************************************************
//
//! \brief Clears all Memory Segment Access Violation Interrupt Flags.
//!
//! \param baseAddress is the base address of the MPU module.
//!
//! Modified bits of \b MPUCTL1 register.
//!
//! \return Logical OR of any of the following:
//!         - \b MPU_SEG_1_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 1 is detected
//!         - \b MPU_SEG_2_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 2 is detected
//!         - \b MPU_SEG_3_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 3 is detected
//!         \n indicating the status of the interrupt flags.
//
//*****************************************************************************
uint16_t MPU_clearAllInterruptFlags(uint32_t baseAddress
                                    )
{

        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUCTL1) &= ~(MPUSEG1IFG + MPUSEG2IFG + MPUSEG3IFG);

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;

        return HWREG16(baseAddress + OFS_MPUCTL1) & (MPUSEG1IFG + MPUSEG2IFG + MPUSEG3IFG);
}

//*****************************************************************************
//
//! \brief Lock MPU to protect from write access.
//!
//! Sets MPULOCK to protect MPU from write access on all MPU registers except
//! MPUCTL1, MPUIPC0 and MPUIPSEGBx until a BOR occurs. MPULOCK bit cannot be
//! cleared manually.
//!
//! \param baseAddress is the base address of the MPU module.
//!
//! Modified bits are \b MPULOCK of \b MPUCTL1 register.
//!
//! \return None
//
//*****************************************************************************
void MPU_lockMPU(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW | MPULOCK;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}
#endif
//*****************************************************************************
//
//! Close the doxygen group for mpu_api
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
// mpu.c - Driver for the mpu Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup mpu_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifdef __MSP430_HAS_MPU__
#include "mpu.h"

#include <assert.h>

//*****************************************************************************
//
// The following value is used by createTwoSegments, createThreeSegments
// to check the user has passed a valid segmentation value. This value was
// obtained from the User's Guide
//
//*****************************************************************************
#define MPU_MAX_SEG_VALUE                                                20

//*****************************************************************************
//
//! \brief This function creates two memory segments in FRAM allowing the user
//! to set access right to each segment. To set the correct value for
//! seg1boundary, the user must consult the Device Family User's Guide and
//! provide the MPUSBx value corresponding to the memory address where the user
//! wants to create the partition. For MPU device consult Table 6-1 in Section
//! 6.2.2 of the User's Guide to find the options available for MPUSBx.
//!
//! Modified registers are MPUCTL0 , MPUSEG , MPUSAM
//!
//! \param baseAddress is the base address of the MPU module.
//! \param seg1boundary Valid values can be found in the Family User's Guide
//!        Valid values are:
//!        - \b MPU_Range of 0x4000 - 0x13C0
//! \param seg1accmask is the bit mask of access right for memory segment 1.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//! \param seg2accmask is the bit mask of access right for memory segment 2
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//!
//! \return None
//
//*****************************************************************************
void MPU_createTwoSegments(uint32_t baseAddress,
                           uint16_t seg1boundary,
                           uint8_t seg1accmask,
                           uint8_t seg2accmask
                           )
{

        uint16_t temp;

        // Verify access right mask for segment1 is a valid selection
        assert((seg1accmask < MPUSEG1VS) && ((seg1accmask == (MPU_EXEC | MPU_READ | MPU_WRITE)) ||
                                             (seg1accmask == (MPU_EXEC | MPU_READ)) ||
                                             (seg1accmask == (MPU_READ | MPU_WRITE)) ||
                                             (seg1accmask == (MPU_READ))));

        // Verify access right mask for segment2 is a valid selection
        assert((seg2accmask < MPUSEG1VS) && ((seg2accmask == (MPU_EXEC | MPU_READ | MPU_WRITE)) ||
                                             (seg2accmask == (MPU_EXEC | MPU_READ)) ||
                                             (seg2accmask == (MPU_READ | MPU_WRITE)) ||
                                             (seg2accmask == (MPU_READ))));

        // Write MPU password to allow MPU register configuration
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;

        // Verify segment1 boundary is valid selection
        assert(seg1boundary < MPU_MAX_SEG_VALUE);

        // Write MPU Password to access MPU registers

        //Needed to set first boundary= second boundary 2 to create
        //two memory segments
        temp = seg1boundary << 8;
        HWREG16(baseAddress + OFS_MPUSEG) = temp + seg1boundary;

        // Set access rights based on user's selection for segment1
        switch (seg1accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1XE + MPUSEG1RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE + MPUSEG1WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG1XE + MPUSEG1WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG1XE + MPUSEG1WE + MPUSEG1RE);
                break;
        }

        // Set access rights based on user's selection for segment2
        switch (seg2accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3WE + MPUSEG2WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3XE + MPUSEG3RE +
                                                     MPUSEG2XE + MPUSEG2RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3XE + MPUSEG2XE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE + MPUSEG3WE +
                                                     MPUSEG2RE + MPUSEG2WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3XE + MPUSEG3WE +
                                                       MPUSEG2XE + MPUSEG2WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE + MPUSEG2RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG3XE + MPUSEG3WE +
                                                      MPUSEG3RE + MPUSEG2XE + MPUSEG2WE + MPUSEG2RE);
                break;
        }

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief This function creates three memory segments in FRAM allowing the
//! user to set access right to each segment. To set the correct value for
//! seg1boundary, the user must consult the Device Family User's Guide and
//! provide the MPUSBx value corresponding to the memory address where the user
//! wants to create the partition. For  MPU device consult Table 6-1 in Section
//! 6.2.2 of the User's Guide to find the options available for MPUSBx.
//!
//! Modified registers are MPUCTL0 , MPUSEG , MPUSAM
//!
//! \param baseAddress is the base address of the MPU module.
//! \param seg1boundary Valid values can be found in the Family User's Guide
//!        Valid values are:
//!        - \b MPU_Range of 0x4000 - 0x13C0
//! \param seg2boundary Valid values can be found in the Family User's Guide
//!        Valid values are:
//!        - \b MPU_Range of 0x4000 - 0x13C0
//! \param seg1accmask is the bit mask of access right for memory segment 1.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//! \param seg2accmask is the bit mask of access right for memory segment 2.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//! \param seg3accmask is the bit mask of access right for memory segment 3.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_READ - Read rights
//!        - \b MPU_WRITE - Write rights
//!        - \b MPU_EXEC - Execute rights
//!
//! \return None
//
//*****************************************************************************
void MPU_createThreeSegments(uint32_t baseAddress,
                             uint16_t seg1boundary,
                             uint16_t seg2boundary,
                             uint8_t seg1accmask,
                             uint8_t seg2accmask,
                             uint8_t seg3accmask
                             )
{
        uint16_t temp;

        // Write MPU password to allow MPU register configuration
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;

        // Set segment boundaries based on user's selection
        temp = seg2boundary << 8;
        HWREG16(baseAddress + OFS_MPUSEG) = temp + seg1boundary;

        // Set access rights based on user's selection for segment1
        switch (seg1accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1XE + MPUSEG1RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG1XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE + MPUSEG1WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG1XE + MPUSEG1WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG1RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG1XE + MPUSEG1WE + MPUSEG1RE);
                break;
        }

        // Set access rights based on user's selection for segment2
        switch (seg2accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG2WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG2XE + MPUSEG2RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG2XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG2RE + MPUSEG2WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG2XE + MPUSEG2WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG2RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG2XE + MPUSEG2WE + MPUSEG2RE);
                break;
        }

        // Set access rights based on user's selection for segment3
        switch (seg3accmask) {
        case MPU_EXEC | MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG3WE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3XE + MPUSEG3RE;
                break;
        case MPU_READ | MPU_WRITE:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~MPUSEG3XE;
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE + MPUSEG3WE;
                break;
        case MPU_READ:
                HWREG16(baseAddress + OFS_MPUSAM) &= ~(MPUSEG3XE + MPUSEG3WE);
                HWREG16(baseAddress + OFS_MPUSAM) |= MPUSEG3RE;
                break;
        default:
                HWREG16(baseAddress + OFS_MPUSAM) |= (MPUSEG3XE + MPUSEG3WE + MPUSEG3RE);
                break;
        }

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief The following function enables the MPU module in the device.
//!
//! Modified register is MPUCTL0
//!
//! \param baseAddress is the base address of the MPU module.
//!
//! \return None
//
//*****************************************************************************
void MPU_start(uint32_t baseAddress)
{
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW + MPUENA;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief The following function enables PUC generation when an access
//! violation has Occurred on the memory segment selected by the user.
//!
//! Modified registers are MPUCTL0 , MPUSAM
//!
//! \param baseAddress is the base address of the MPU module.
//! \param segment is the bit mask of memory segment that will generate a PUC
//!        when an access violation occurs.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_FIRST_SEG - PUC generation on first memory segment
//!        - \b MPU_SECOND_SEG - PUC generation on second memory segment
//!        - \b MPU_THIRD_SEG - PUC generation on third memory segment
//!
//! \return None
//
//*****************************************************************************
void MPU_enablePUCOnViolation(uint32_t baseAddress,
                              uint16_t segment
                              )
{
        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUSAM) |= segment;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief The following function disables PUC generation when an access
//! violation has Occurred on the memory segment selected by the user.
//!
//! Modified registers are MPUCTL0 , MPUSAM
//!
//! \param baseAddress is the base address of the MPU module.
//! \param segment is the bit mask of memory segment that will NOT generate a
//!        PUC when an access violation occurs.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_FIRST_SEG - PUC generation on first memory segment
//!        - \b MPU_SECOND_SEG - PUC generation on second memory segment
//!        - \b MPU_THIRD_SEG - PUC generation on third memory segment
//!
//! \return None
//
//*****************************************************************************
void MPU_disablePUCOnViolation(uint32_t baseAddress,
                               uint16_t segment
                               )
{

        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUSAM) |= segment;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;
}

//*****************************************************************************
//
//! \brief Returns the memory segment violation flag status requested by the
//! user.
//!
//! \param baseAddress is the base address of the MPU module.
//! \param memAccFlag is the is the memory access violation flag.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_SEG_1_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 1 is detected
//!        - \b MPU_SEG_2_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 2 is detected
//!        - \b MPU_SEG_3_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 3 is detected
//!
//! \return The current interrupt status as the mask of the set flags.
//!         Return Logical OR of any of the following:
//!         - \b MPU_SEG_1_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 1 is detected
//!         - \b MPU_SEG_2_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 2 is detected
//!         - \b MPU_SEG_3_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 3 is detected
//!         \n indicating the status of the masked flags.
//
//*****************************************************************************
uint16_t MPU_getInterruptStatus(uint32_t baseAddress,
                                uint16_t memAccFlag
                                )
{
        return HWREG16(baseAddress + OFS_MPUCTL1) & memAccFlag;
}

//*****************************************************************************
//
//! \brief Returns the memory segment violation flag status requested by the
//! user or if user is providing a bit mask value, the function will return a
//! value indicating if all flags were cleared
//!
//! \param baseAddress is the base address of the MPU module.
//! \param memAccFlag is the is the memory access violation flag.
//!        Mask value is the logical OR of any of the following:
//!        - \b MPU_SEG_1_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 1 is detected
//!        - \b MPU_SEG_2_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 2 is detected
//!        - \b MPU_SEG_3_ACCESS_VIOLATION - is set if an access violation in
//!           Main Memory Segment 3 is detected
//!
//! \return The current interrupt status as the mask of the set flags.
//!         Return Logical OR of any of the following:
//!         - \b MPU_SEG_1_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 1 is detected
//!         - \b MPU_SEG_2_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 2 is detected
//!         - \b MPU_SEG_3_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 3 is detected
//!         \n indicating the status of the masked flags.
//
//*****************************************************************************
uint16_t MPU_clearInterruptFlag(uint32_t baseAddress,
                                uint16_t memAccFlag
                                )
{

        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUCTL1) &= ~memAccFlag;

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;

        return HWREG16(baseAddress + OFS_MPUCTL1) & memAccFlag;
}

//*****************************************************************************
//
//! \brief Clears all Memory Segment Access Violation Interrupt Flags.
//!
//! Modified registers are MPUCTL1
//!
//! \param baseAddress is the base address of the MPU module.
//!
//! \return The current interrupt status as the mask of the set flags.
//!         Return Logical OR of any of the following:
//!         - \b MPU_SEG_1_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 1 is detected
//!         - \b MPU_SEG_2_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 2 is detected
//!         - \b MPU_SEG_3_ACCESS_VIOLATION is set if an access violation in
//!         Main Memory Segment 3 is detected
//!         \n indicating the status of the interrupt flags.
//
//*****************************************************************************
uint16_t MPU_clearAllInterruptFlags(uint32_t baseAddress
                                    )
{

        HWREG16(baseAddress + OFS_MPUCTL0) = MPUPW;
        HWREG16(baseAddress + OFS_MPUCTL1) &= ~(MPUSEG1IFG + MPUSEG2IFG + MPUSEG3IFG);

        //Lock MPU to disable writing to all registers
        HWREG8(baseAddress + OFS_MPUCTL0_H) = 0x00;

        return HWREG16(baseAddress + OFS_MPUCTL1) & (MPUSEG1IFG + MPUSEG2IFG + MPUSEG3IFG);
}

#endif
//*****************************************************************************
//
//! Close the doxygen group for mpu_api
//! @}
//
//*****************************************************************************

#endif
