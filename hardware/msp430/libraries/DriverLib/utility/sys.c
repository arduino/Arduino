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
// sys.c - Driver for the sys Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup sys_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifndef DRIVERLIB_LEGACY_MODE

#ifdef __MSP430_HAS_SYS__
#include "sys.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Sets the JTAG pins to be exclusively for JTAG until a BOR occurs.
//!
//! This function sets the JTAG pins to be exclusively used for the JTAG, and
//! not to be shared with the GPIO pins. This setting can only be cleared when
//! a BOR occurs.
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_enableDedicatedJTAGPins(void)
{
        HWREG8(SYS_BASE + OFS_SYSCTL_L) |= SYSJTAGPIN;
}

//*****************************************************************************
//
//! \brief Returns the indication of a BSL entry sequence from the Spy-Bi-Wire.
//!
//! This function returns the indication of a BSL entry sequence from the Spy-
//! Bi-Wire.
//!
//!
//! \return One of the following:
//!         - \b SYS_BSLENTRY_INDICATED
//!         - \b SYS_BSLENTRY_NOTINDICATED
//!         \n indicating if a BSL entry sequence was detected
//
//*****************************************************************************
uint8_t SYS_getBSLEntryIndication(void)
{
        if ( HWREG8(SYS_BASE + OFS_SYSCTL_L) & SYSBSLIND)
                return SYS_BSLENTRY_INDICATED;
        else
                return SYS_BSLENTRY_NOTINDICATED;
}

//*****************************************************************************
//
//! \brief Enables PMM Access Protection.
//!
//! This function enables the PMM Access Protection, which will lock any
//! changes on the PMM control registers until a BOR occurs.
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_enablePMMAccessProtect(void)
{
        HWREG8(SYS_BASE + OFS_SYSCTL_L) |= SYSPMMPE;
}

//*****************************************************************************
//
//! \brief Enables RAM-based Interrupt Vectors.
//!
//! This function enables RAM-base Interrupt Vectors, which means that
//! interrupt vectors are generated with the end address at the top of RAM,
//! instead of the top of the lower 64kB of flash.
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_enableRAMBasedInterruptVectors(void)
{
        HWREG8(SYS_BASE + OFS_SYSCTL_L) |= SYSRIVECT;
}

//*****************************************************************************
//
//! \brief Disables RAM-based Interrupt Vectors.
//!
//! This function disables the interrupt vectors from being generated at the
//! top of the RAM.
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_disableRAMBasedInterruptVectors(void)
{
        HWREG8(SYS_BASE + OFS_SYSCTL_L) &= ~(SYSRIVECT);
}

//*****************************************************************************
//
//! \brief Enables BSL memory protection.
//!
//! This function enables protection on the BSL memory, which prevents any
//! reading, programming, or erasing of the BSL memory.
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_enableBSLProtect(void)
{
        HWREG16(SYS_BASE + OFS_SYSBSLC) |= SYSBSLPE;
}

//*****************************************************************************
//
//! \brief Disables BSL memory protection.
//!
//! This function disables protection on the BSL memory.
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_disableBSLProtect(void)
{
        HWREG16(SYS_BASE + OFS_SYSBSLC) &= ~(SYSBSLPE);
}

//*****************************************************************************
//
//! \brief Enables BSL memory.
//!
//! This function enables BSL memory, which allows BSL memory to be addressed
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_enableBSLMemory(void)
{
        HWREG16(SYS_BASE + OFS_SYSBSLC) &= ~(SYSBSLOFF);
}

//*****************************************************************************
//
//! \brief Disables BSL memory.
//!
//! This function disables BSL memory, which makes BSL memory act like vacant
//! memory.
//!
//!
//! \return None
//
//*****************************************************************************
void SYS_disableBSLMemory(void)
{
        HWREG16(SYS_BASE + OFS_SYSBSLC) |= SYSBSLOFF;
}

//*****************************************************************************
//
//! \brief Sets RAM assignment to BSL area.
//!
//! This function allows RAM to be assigned to BSL, based on the selection of
//! the BSLRAMAssignment parameter.
//!
//! \param BSLRAMAssignment is the selection of if the BSL should be placed in
//!        RAM or not.
//!        Valid values are:
//!        - \b SYS_BSLRAMASSIGN_NORAM [Default]
//!        - \b SYS_BSLRAMASSIGN_LOWEST16BYTES
//!        \n Modified bits are \b SYSBSLR of \b SYSBSLC register.
//!
//! \return None
//
//*****************************************************************************
void SYS_setRAMAssignedToBSL(uint8_t BSLRAMAssignment)
{
        HWREG8(SYS_BASE + OFS_SYSBSLC_L) &= ~(SYSBSLR);
        HWREG8(SYS_BASE + OFS_SYSBSLC_L) |= BSLRAMAssignment;
}

//*****************************************************************************
//
//! \brief Sets the size of the BSL in Flash.
//!
//! This function sets the size of the BSL in Flash memory.
//!
//! \param BSLSizeSelect is the amount of segments the BSL should take.
//!        Valid values are:
//!        - \b SYS_BSLSIZE_SEG3
//!        - \b SYS_BSLSIZE_SEGS23
//!        - \b SYS_BSLSIZE_SEGS123
//!        - \b SYS_BSLSIZE_SEGS1234 [Default]
//!        \n Modified bits are \b SYSBSLSIZE of \b SYSBSLC register.
//!
//! \return None
//
//*****************************************************************************
void SYS_setBSLSize(uint8_t BSLSizeSelect)
{
        HWREG8(SYS_BASE + OFS_SYSBSLC_L) &= ~(SYSBSLSIZE0 + SYSBSLSIZE1);
        HWREG8(SYS_BASE + OFS_SYSBSLC_L) |= BSLSizeSelect;
}

//*****************************************************************************
//
//! \brief Initializes JTAG Mailbox with selected properties.
//!
//! This function sets the specified settings for the JTAG Mailbox system. The
//! settings that can be set are the size of the JTAG messages, and the auto-
//! clearing of the inbox flags. If the inbox flags are set to auto-clear, then
//! the inbox flags will be cleared upon reading of the inbox message buffer,
//! otherwise they will have to be reset by software using the
//! SYS_clearJTAGMailboxFlagStatus() function.
//!
//! \param mailboxSizeSelect is the size of the JTAG Mailboxes, whether 16- or
//!        32-bits.
//!        Valid values are:
//!        - \b SYS_JTAGMBSIZE_16BIT [Default] - the JTAG messages will take up
//!           only one JTAG mailbox (i. e. an outgoing message will take up
//!           only 1 outbox of the JTAG mailboxes)
//!        - \b SYS_JTAGMBSIZE_32BIT - the JTAG messages will be contained
//!           within both JTAG mailboxes (i. e. an outgoing message will take
//!           up both Outboxes of the JTAG mailboxes)
//!        \n Modified bits are \b JMBMODE of \b SYSJMBC register.
//! \param autoClearInboxFlagSelect decides how the JTAG inbox flags should be
//!        cleared, whether automatically after the corresponding outbox has
//!        been written to, or manually by software.
//!        Valid values are:
//!        - \b SYS_JTAGINBOX0AUTO_JTAGINBOX1AUTO [Default] - both JTAG inbox
//!           flags will be reset automatically when the corresponding inbox is
//!           read from.
//!        - \b SYS_JTAGINBOX0AUTO_JTAGINBOX1SW - only JTAG inbox 0 flag is
//!           reset automatically, while JTAG inbox 1 is reset with the
//!        - \b SYS_JTAGINBOX0SW_JTAGINBOX1AUTO - only JTAG inbox 1 flag is
//!           reset automatically, while JTAG inbox 0 is reset with the
//!        - \b SYS_JTAGINBOX0SW_JTAGINBOX1SW - both JTAG inbox flags will need
//!           to be reset manually by the
//!        \n Modified bits are \b JMBCLR0OFF and \b JMBCLR1OFF of \b SYSJMBC
//!        register.
//!
//! \return None
//
//*****************************************************************************
void SYS_JTAGMailboxInit(uint8_t mailboxSizeSelect,
                         uint8_t autoClearInboxFlagSelect)
{
        HWREG8(SYS_BASE + OFS_SYSJMBC_L) &= ~(JMBCLR1OFF + JMBCLR0OFF + JMBMODE);
        HWREG8(SYS_BASE + OFS_SYSJMBC_L) |=
                mailboxSizeSelect + autoClearInboxFlagSelect;
}

//*****************************************************************************
//
//! \brief Returns the status of the selected JTAG Mailbox flags.
//!
//! This function will return the status of the selected JTAG Mailbox flags in
//! bit mask format matching that passed into the mailboxFlagMask parameter.
//!
//! \param mailboxFlagMask is the bit mask of JTAG mailbox flags that the
//!        status of should be returned.
//!        Mask value is the logical OR of any of the following:
//!        - \b SYS_JTAGOUTBOX_FLAG0 - flag for JTAG outbox 0
//!        - \b SYS_JTAGOUTBOX_FLAG1 - flag for JTAG outbox 1
//!        - \b SYS_JTAGINBOX_FLAG0 - flag for JTAG inbox 0
//!        - \b SYS_JTAGINBOX_FLAG1 - flag for JTAG inbox 1
//!
//! \return A bit mask of the status of the selected mailbox flags.
//
//*****************************************************************************
uint8_t SYS_getJTAGMailboxFlagStatus(uint8_t mailboxFlagMask)
{
        return HWREG8(SYS_BASE + OFS_SYSJMBC_L) & mailboxFlagMask;
}

//*****************************************************************************
//
//! \brief Clears the status of the selected JTAG Mailbox flags.
//!
//! This function clears the selected JTAG Mailbox flags.
//!
//! \param mailboxFlagMask is the bit mask of JTAG mailbox flags that the
//!        status of should be cleared.
//!        Mask value is the logical OR of any of the following:
//!        - \b SYS_JTAGOUTBOX_FLAG0 - flag for JTAG outbox 0
//!        - \b SYS_JTAGOUTBOX_FLAG1 - flag for JTAG outbox 1
//!        - \b SYS_JTAGINBOX_FLAG0 - flag for JTAG inbox 0
//!        - \b SYS_JTAGINBOX_FLAG1 - flag for JTAG inbox 1
//!
//! \return None
//
//*****************************************************************************
void SYS_clearJTAGMailboxFlagStatus(uint8_t mailboxFlagMask)
{
        HWREG8(SYS_BASE + OFS_SYSJMBC_L) &= ~(mailboxFlagMask);
}

//*****************************************************************************
//
//! \brief Returns the contents of the selected JTAG Inbox in a 16 bit format.
//!
//! This function returns the message contents of the selected JTAG inbox. If
//! the auto clear settings for the Inbox flags were set, then using this
//! function will automatically clear the corresponding JTAG inbox flag.
//!
//! \param inboxSelect is the chosen JTAG inbox that the contents of should be
//!        returned
//!        Valid values are:
//!        - \b SYS_JTAGINBOX_0 - return contents of JTAG inbox 0
//!        - \b SYS_JTAGINBOX_1 - return contents of JTAG inbox 1
//!
//! \return The contents of the selected JTAG inbox in a 16 bit format.
//
//*****************************************************************************
uint16_t SYS_getJTAGInboxMessage16Bit(uint8_t inboxSelect)
{
        return HWREG16(SYS_BASE + OFS_SYSJMBI0 + inboxSelect);
}

//*****************************************************************************
//
//! \brief Returns the contents of JTAG Inboxes in a 32 bit format.
//!
//! This function returns the message contents of both JTAG inboxes in a 32 bit
//! format. This function should be used if 32-bit messaging has been set in
//! the SYS_JTAGMailboxInit() function. If the auto clear settings for the
//! Inbox flags were set, then using this function will automatically clear
//! both JTAG inbox flags.
//!
//!
//! \return The contents of both JTAG messages in a 32 bit format.
//
//*****************************************************************************
uint32_t SYS_getJTAGInboxMessage32Bit(void)
{
        uint32_t JTAGInboxMessageLow = HWREG16(SYS_BASE + OFS_SYSJMBI0);
        uint32_t JTAGInboxMessageHigh = HWREG16(SYS_BASE + OFS_SYSJMBI1);

        return (JTAGInboxMessageHigh << 16) + JTAGInboxMessageLow;
}

//*****************************************************************************
//
//! \brief Sets a 16 bit outgoing message in to the selected JTAG Outbox.
//!
//! This function sets the outgoing message in the selected JTAG outbox. The
//! corresponding JTAG outbox flag is cleared after this function, and set
//! after the JTAG has read the message.
//!
//! \param outboxSelect is the chosen JTAG outbox that the message should be
//!        set it.
//!        Valid values are:
//!        - \b SYS_JTAGOUTBOX_0 - set the contents of JTAG outbox 0
//!        - \b SYS_JTAGOUTBOX_1 - set the contents of JTAG outbox 1
//! \param outgoingMessage is the message to send to the JTAG.
//!        \n Modified bits are \b MSGHI and \b MSGLO of \b SYSJMBOx register.
//!
//! \return None
//
//*****************************************************************************
void SYS_setJTAGOutgoingMessage16Bit(uint8_t outboxSelect,
                                     uint16_t outgoingMessage)
{
        HWREG16(SYS_BASE + OFS_SYSJMBO0 + outboxSelect) = outgoingMessage;
}

//*****************************************************************************
//
//! \brief Sets a 32 bit message in to both JTAG Outboxes.
//!
//! This function sets the 32-bit outgoing message in both JTAG outboxes. The
//! JTAG outbox flags are cleared after this function, and set after the JTAG
//! has read the message.
//!
//! \param outgoingMessage is the message to send to the JTAG.
//!        \n Modified bits are \b MSGHI and \b MSGLO of \b SYSJMBOx register.
//!
//! \return None
//
//*****************************************************************************
void SYS_setJTAGOutgoingMessage32Bit(uint32_t outgoingMessage)
{
        HWREG16(SYS_BASE + OFS_SYSJMBO0) = (outgoingMessage);
        HWREG16(SYS_BASE + OFS_SYSJMBO1) = (outgoingMessage >> 16);
}


#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for sys_api
//! @}
//
//*****************************************************************************

#endif
