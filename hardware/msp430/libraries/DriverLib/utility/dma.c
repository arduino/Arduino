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
// dma.c - Driver for the dma Module.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup dma_api
//! @{
//
//*****************************************************************************

#include "inc/hw_regaccess.h"
#include "inc/hw_memmap.h"

#ifndef DRIVERLIB_LEGACY_MODE

#if defined(__MSP430_HAS_DMAX_3__) || defined(__MSP430_HAS_DMAX_6__)
#include "dma.h"

#include <assert.h>

//*****************************************************************************
//
//! \brief Initializes the specified DMA channel.
//!
//! This function initializes the specified DMA channel. Upon successful
//! completion of initialization of the selected channel the control registers
//! will be cleared and the given variables will be set. Please note, if
//! transfers have been enabled with the enableTransfers() function, then a
//! call to disableTransfers() is necessary before re-initialization. Also
//! note, that the trigger sources are device dependent and can be found in the
//! device family data sheet. The amount of DMA channels available are also
//! device specific.
//!
//! \param channelSelect is the specified channel to initialize.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//! \param transferModeSelect is the transfer mode of the selected channel.
//!        Valid values are:
//!        - \b DMA_TRANSFER_SINGLE [Default] - Single transfer, transfers
//!           disabled after transferAmount of transfers.
//!        - \b DMA_TRANSFER_BLOCK - Multiple transfers of transferAmount,
//!           transfers disabled once finished.
//!        - \b DMA_TRANSFER_BURSTBLOCK - Multiple transfers of transferAmount
//!           interleaved with CPU activity, transfers disabled once finished.
//!        - \b DMA_TRANSFER_REPEATED_SINGLE - Repeated single transfer by
//!           trigger.
//!        - \b DMA_TRANSFER_REPEATED_BLOCK - Multiple transfers of
//!           transferAmount by trigger.
//!        - \b DMA_TRANSFER_REPEATED_BURSTBLOCK - Multiple transfers of
//!           transferAmount by trigger interleaved with CPU activity.
//!        \n Modified bits are \b DMADT of \b DMAxCTL register.
//! \param transferSize is the amount of transfers to complete in a block
//!        transfer mode, as well as how many transfers to complete before the
//!        interrupt flag is set. Valid value is between 1-65535, if 0, no
//!        transfers will occur.
//!        \n Modified bits are \b DMAxSZ of \b DMAxSZ register.
//! \param triggerSourceSelect is the source that will trigger the start of
//!        each transfer, note that the sources are device specific.
//!        Valid values are:
//!        - \b DMA_TRIGGERSOURCE_0 [Default]
//!        - \b DMA_TRIGGERSOURCE_1
//!        - \b DMA_TRIGGERSOURCE_2
//!        - \b DMA_TRIGGERSOURCE_3
//!        - \b DMA_TRIGGERSOURCE_4
//!        - \b DMA_TRIGGERSOURCE_5
//!        - \b DMA_TRIGGERSOURCE_6
//!        - \b DMA_TRIGGERSOURCE_7
//!        - \b DMA_TRIGGERSOURCE_8
//!        - \b DMA_TRIGGERSOURCE_9
//!        - \b DMA_TRIGGERSOURCE_10
//!        - \b DMA_TRIGGERSOURCE_11
//!        - \b DMA_TRIGGERSOURCE_12
//!        - \b DMA_TRIGGERSOURCE_13
//!        - \b DMA_TRIGGERSOURCE_14
//!        - \b DMA_TRIGGERSOURCE_15
//!        - \b DMA_TRIGGERSOURCE_16
//!        - \b DMA_TRIGGERSOURCE_17
//!        - \b DMA_TRIGGERSOURCE_18
//!        - \b DMA_TRIGGERSOURCE_19
//!        - \b DMA_TRIGGERSOURCE_20
//!        - \b DMA_TRIGGERSOURCE_21
//!        - \b DMA_TRIGGERSOURCE_22
//!        - \b DMA_TRIGGERSOURCE_23
//!        - \b DMA_TRIGGERSOURCE_24
//!        - \b DMA_TRIGGERSOURCE_25
//!        - \b DMA_TRIGGERSOURCE_26
//!        - \b DMA_TRIGGERSOURCE_27
//!        - \b DMA_TRIGGERSOURCE_28
//!        - \b DMA_TRIGGERSOURCE_29
//!        - \b DMA_TRIGGERSOURCE_30
//!        - \b DMA_TRIGGERSOURCE_31
//!        \n Modified bits are \b DMAxTSEL of \b DMACTLx register.
//! \param transferUnitSelect is the specified size of transfers.
//!        Valid values are:
//!        - \b DMA_SIZE_SRCWORD_DSTWORD [Default]
//!        - \b DMA_SIZE_SRCBYTE_DSTWORD
//!        - \b DMA_SIZE_SRCWORD_DSTBYTE
//!        - \b DMA_SIZE_SRCBYTE_DSTBYTE
//!        \n Modified bits are \b DMASRCBYTE and \b DMADSTBYTE of \b DMAxCTL
//!        register.
//! \param triggerTypeSelect is the type of trigger that the trigger signal
//!        needs to be to start a transfer.
//!        Valid values are:
//!        - \b DMA_TRIGGER_RISINGEDGE [Default]
//!        - \b DMA_TRIGGER_HIGH - A trigger would be a high signal from the
//!           trigger source, to be held high through the length of the
//!           transfer(s).
//!        \n Modified bits are \b DMALEVEL of \b DMAxCTL register.
//!
//! \return STATUS_SUCCESS or STATUS_FAILURE of the initialization process.
//
//*****************************************************************************
bool DMA_init(uint8_t channelSelect,
              uint16_t transferModeSelect,
              uint16_t transferSize,
              uint8_t triggerSourceSelect,
              uint8_t transferUnitSelect,
              uint8_t triggerTypeSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);
        assert(transferModeSelect <= DMA_TRANSFER_REPEATED_BURSTBLOCK);
        assert(triggerSourceSelect <= DMA_TRIGGERSOURCE_31);
        assert(transferUnitSelect <= DMA_SIZE_SRCBYTE_DSTBYTE);
        assert(triggerTypeSelect <= DMA_TRIGGER_HIGH);

        bool retVal = STATUS_SUCCESS;
        uint8_t triggerOffset = (channelSelect >> 4);

        //Reset and Set DMA Control 0 Register
        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) =
                transferModeSelect      //Set Transfer Mode
                + transferUnitSelect    //Set Transfer Unit Size
                + triggerTypeSelect;    //Set Trigger Type

        //Set Transfer Size Amount
        HWREG16(DMA_BASE + channelSelect + OFS_DMA0SZ) = transferSize;

        if (triggerOffset & 0x01) {                                     //Odd Channel
                HWREG16(DMA_BASE + (triggerOffset & 0x0E)) &= 0x00FF;   //Reset Trigger Select
                HWREG16(DMA_BASE +
                        (triggerOffset & 0x0E)) |= (triggerSourceSelect << 8);
        } else {                                                        //Even Channel
                HWREG16(DMA_BASE + (triggerOffset & 0x0E)) &= 0xFF00;   //Reset Trigger Select
                HWREG16(DMA_BASE + (triggerOffset & 0x0E)) |= triggerSourceSelect;
        }

        return retVal;
}

//*****************************************************************************
//
//! \brief Sets the specified amount of transfers for the selected DMA channel.
//!
//! This function sets the specified amount of transfers for the selected DMA
//! channel without having to reinitialize the DMA channel.
//!
//! \param channelSelect is the specified channel to set source address
//!        direction for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//! \param transferSize is the amount of transfers to complete in a block
//!        transfer mode, as well as how many transfers to complete before the
//!        interrupt flag is set. Valid value is between 1-65535, if 0, no
//!        transfers will occur.
//!        \n Modified bits are \b DMAxSZ of \b DMAxSZ register.
//!
//! \return None
//
//*****************************************************************************
void DMA_setTransferSize(uint8_t channelSelect,
                         uint16_t transferSize)
{
        //Set Transfer Size Amount
        HWREG16(DMA_BASE + channelSelect + OFS_DMA0SZ) = transferSize;
}

//*****************************************************************************
//
//! \brief Sets source address and the direction that the source address will
//! move after a transfer.
//!
//! This function sets the source address and the direction that the source
//! address will move after a transfer is complete. It may be incremented,
//! decremented or unchanged.
//!
//! \param channelSelect is the specified channel to set source address
//!        direction for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//! \param srcAddress is the address of where the data will be transferred
//!        from.
//!        \n Modified bits are \b DMAxSA of \b DMAxSA register.
//! \param directionSelect is the specified direction of the source address
//!        after a transfer.
//!        Valid values are:
//!        - \b DMA_DIRECTION_UNCHANGED
//!        - \b DMA_DIRECTION_DECREMENT
//!        - \b DMA_DIRECTION_INCREMENT
//!        \n Modified bits are \b DMASRCINCR of \b DMAxCTL register.
//!
//! \return None
//
//*****************************************************************************
void DMA_setSrcAddress(uint8_t channelSelect,
                       uint32_t srcAddress,
                       uint16_t directionSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);
        assert(directionSelect <= DMA_DIRECTION_INCREMENT);

        //Set the Source Address
        __data16_write_addr((unsigned short)(DMA_BASE + channelSelect + OFS_DMA0SA),
                            srcAddress);

        //Reset bits before setting them
        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) &= ~(DMASRCINCR_3);
        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) |= directionSelect;
}

//*****************************************************************************
//
//! \brief Sets the destination address and the direction that the destination
//! address will move after a transfer.
//!
//! This function sets the destination address and the direction that the
//! destination address will move after a transfer is complete. It may be
//! incremented, decremented, or unchanged.
//!
//! \param channelSelect is the specified channel to set the destination
//!        address direction for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//! \param dstAddress is the address of where the data will be transferred to.
//!        \n Modified bits are \b DMAxDA of \b DMAxDA register.
//! \param directionSelect is the specified direction of the destination
//!        address after a transfer.
//!        Valid values are:
//!        - \b DMA_DIRECTION_UNCHANGED
//!        - \b DMA_DIRECTION_DECREMENT
//!        - \b DMA_DIRECTION_INCREMENT
//!        \n Modified bits are \b DMADSTINCR of \b DMAxCTL register.
//!
//! \return None
//
//*****************************************************************************
void DMA_setDstAddress(uint8_t channelSelect,
                       uint32_t dstAddress,
                       uint16_t directionSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);
        assert(directionSelect <= DMA_DIRECTION_INCREMENT);

        //Set the Destination Address
        __data16_write_addr((unsigned short)(DMA_BASE + channelSelect + OFS_DMA0DA),
                            dstAddress);

        //Reset bits before setting them
        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) &= ~(DMADSTINCR_3);
        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) |= (directionSelect << 2);
}

//*****************************************************************************
//
//! \brief Enables transfers to be triggered.
//!
//! This function enables transfers upon appropriate trigger of the selected
//! trigger source for the selected channel.
//!
//! \param channelSelect is the specified channel to enable transfer for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return None
//
//*****************************************************************************
void DMA_enableTransfers(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) |= DMAEN;
}

//*****************************************************************************
//
//! \brief Disables transfers from being triggered.
//!
//! This function disables transfer from being triggered for the selected
//! channel. This function should be called before any re-initialization of the
//! selected DMA channel.
//!
//! \param channelSelect is the specified channel to disable transfers for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return None
//
//*****************************************************************************
void DMA_disableTransfers(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) &= ~(DMAEN);
}

//*****************************************************************************
//
//! \brief Starts a transfer if using the default trigger source selected in
//! initialization.
//!
//! This functions triggers a transfer of data from source to destination if
//! the trigger source chosen from initialization is the DMA_TRIGGERSOURCE_0.
//! Please note, this function needs to be called for each (repeated-)single
//! transfer, and when transferAmount of transfers have been complete in
//! (repeated-)block transfers.
//!
//! \param channelSelect is the specified channel to start transfers for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return None
//
//*****************************************************************************
void DMA_startTransfer(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) |= DMAREQ;
}

//*****************************************************************************
//
//! \brief Enables the DMA interrupt for the selected channel.
//!
//! Enables the DMA interrupt source.  Only the sources that are enabled can be
//! reflected to the processor interrupt; disabled sources have no effect on
//! the processor. Does not clear interrupt flags.
//!
//! \param channelSelect is the specified channel to enable the interrupt for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return None
//
//*****************************************************************************
void DMA_enableInterrupt(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) |= DMAIE;
}

//*****************************************************************************
//
//! \brief Disables the DMA interrupt for the selected channel.
//!
//! Disables the DMA interrupt source. Only the sources that are enabled can be
//! reflected to the processor interrupt; disabled sources have no effect on
//! the processor.
//!
//! \param channelSelect is the specified channel to disable the interrupt for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return None
//
//*****************************************************************************
void DMA_disableInterrupt(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) &= ~(DMAIE);
}

//*****************************************************************************
//
//! \brief Returns the status of the interrupt flag for the selected channel.
//!
//! Returns the status of the interrupt flag for the selected channel.
//!
//! \param channelSelect is the specified channel to return the interrupt flag
//!        status from.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return One of the following:
//!         - \b DMA_INT_INACTIVE
//!         - \b DMA_INT_ACTIVE
//!         \n indicating the status of the current interrupt flag
//
//*****************************************************************************
uint16_t DMA_getInterruptStatus(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        return HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) & DMAIFG;
}

//*****************************************************************************
//
//! \brief Clears the interrupt flag for the selected channel.
//!
//! This function clears the DMA interrupt flag is cleared, so that it no
//! longer asserts.
//!
//! \param channelSelect is the specified channel to clear the interrupt flag
//!        for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return None
//
//*****************************************************************************
void DMA_clearInterrupt(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) &= ~(DMAIFG);
}

//*****************************************************************************
//
//! \brief Returns the status of the NMIAbort for the selected channel.
//!
//! This function returns the status of the NMI Abort flag for the selected
//! channel. If this flag has been set, it is because a transfer on this
//! channel was aborted due to a interrupt from an NMI.
//!
//! \param channelSelect is the specified channel to return the status of the
//!        NMI Abort flag for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return One of the following:
//!         - \b DMA_NOTABORTED
//!         - \b DMA_ABORTED
//!         \n indicating the status of the NMIAbort for the selected channel
//
//*****************************************************************************
uint16_t DMA_NMIAbortStatus(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        return HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) & DMAABORT;
}

//*****************************************************************************
//
//! \brief Clears the status of the NMIAbort to proceed with transfers for the
//! selected channel.
//!
//! This function clears the status of the NMI Abort flag for the selected
//! channel to allow for transfers on the channel to continue.
//!
//! \param channelSelect is the specified channel to clear the NMI Abort flag
//!        for.
//!        Valid values are:
//!        - \b DMA_CHANNEL_0
//!        - \b DMA_CHANNEL_1
//!        - \b DMA_CHANNEL_2
//!        - \b DMA_CHANNEL_3
//!        - \b DMA_CHANNEL_4
//!        - \b DMA_CHANNEL_5
//!        - \b DMA_CHANNEL_6
//!        - \b DMA_CHANNEL_7
//!
//! \return None
//
//*****************************************************************************
void DMA_clearNMIAbort(uint8_t channelSelect)
{
        assert(channelSelect <= DMA_CHANNEL_7);

        HWREG16(DMA_BASE + channelSelect + OFS_DMA0CTL) &= ~(DMAABORT);
}

//*****************************************************************************
//
//! \brief Disables the DMA from stopping the CPU during a Read-Modify-Write
//! Operation to start a transfer.
//!
//! This function allows the CPU to finish any read-modify-write operations it
//! may be in the middle of before transfers of and DMA channel stop the CPU.
//!
//!
//! \return None
//
//*****************************************************************************
void DMA_disableTransferDuringReadModifyWrite(void)
{
        HWREG16(DMA_BASE + OFS_DMACTL4) |= DMARMWDIS;
}

//*****************************************************************************
//
//! \brief Enables the DMA to stop the CPU during a Read-Modify-Write Operation
//! to start a transfer.
//!
//! This function allows the DMA to stop the CPU in the middle of a read-
//! modify-write operation to transfer data.
//!
//!
//! \return None
//
//*****************************************************************************
void DMA_enableTransferDuringReadModifyWrite(void)
{
        HWREG16(DMA_BASE + OFS_DMACTL4) &= ~(DMARMWDIS);
}

//*****************************************************************************
//
//! \brief Enables Round Robin prioritization.
//!
//! This function enables Round Robin Prioritization of DMA channels. In the
//! case of Round Robin Prioritization, the last DMA channel to have
//! transferred data then has the last priority, which comes into play when
//! multiple DMA channels are ready to transfer at the same time.
//!
//!
//! \return None
//
//*****************************************************************************
void DMA_enableRoundRobinPriority(void)
{
        HWREG16(DMA_BASE + OFS_DMACTL4) |= ROUNDROBIN;
}

//*****************************************************************************
//
//! \brief Disables Round Robin prioritization.
//!
//! This function disables Round Robin Prioritization, enabling static
//! prioritization of the DMA channels. In static prioritization, the DMA
//! channels are prioritized with the lowest DMA channel index having the
//! highest priority (i.e. DMA Channel 0 has the highest priority).
//!
//!
//! \return None
//
//*****************************************************************************
void DMA_disableRoundRobinPriority(void)
{
        HWREG16(DMA_BASE + OFS_DMACTL4) &= ~(ROUNDROBIN);
}

//*****************************************************************************
//
//! \brief Enables a NMI to interrupt a DMA transfer.
//!
//! This function allow NMI's to interrupting any DMA transfer currently in
//! progress and stops any future transfers to begin before the NMI is done
//! processing.
//!
//!
//! \return None
//
//*****************************************************************************
void DMA_enableNMIAbort(void)
{
        HWREG16(DMA_BASE + OFS_DMACTL4) |= ENNMI;
}

//*****************************************************************************
//
//! \brief Disables any NMI from interrupting a DMA transfer.
//!
//! This function disables NMI's from interrupting any DMA transfer currently
//! in progress.
//!
//!
//! \return None
//
//*****************************************************************************
void DMA_disableNMIAbort(void)
{
        HWREG16(DMA_BASE + OFS_DMACTL4) &= ~(ENNMI);
}

#endif
#endif
//*****************************************************************************
//
//! Close the doxygen group for dma_api
//! @}
//
//*****************************************************************************

#endif
