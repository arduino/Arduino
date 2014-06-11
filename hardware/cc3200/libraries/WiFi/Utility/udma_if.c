//*****************************************************************************
// udma_if.c
//
// uDMA interface file
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_uart.h"
#include "inc/hw_types.h"
#include "inc/hw_udma.h"

#include <stdio.h>
#include <string.h>

/* Hardware library includes. */
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/gpio.h"
#include "driverlib/udma.h"
#include "driverlib/interrupt.h"
#include "driverlib/prcm.h"
#include "driverlib/uart.h"

/* Peripheral interface includes. */
#include "udma_if.h"

#define MAX_NUM_CH              64  //32*2 entries
#define CTL_TBL_SIZE            64  //32*2 entries

#define UDMA_CH5_BITID          (1<<5)
#if defined(__GNUC__)
tDMAControlTable gpCtlTbl[CTL_TBL_SIZE] __attribute__(( aligned(1024)));
#endif

#if defined(ccs)
#pragma DATA_ALIGN(gpCtlTbl, 1024)
tDMAControlTable gpCtlTbl[CTL_TBL_SIZE];
#endif

#if defined(ewarm)
#pragma data_alignment=1024
tDMAControlTable gpCtlTbl[CTL_TBL_SIZE];
#endif

unsigned char iDone;
tAppCallbackHndl gfpAppCallbackHndl[MAX_NUM_CH];

//*****************************************************************************
//
//! DMA software interrupt handler
//!
//! \param None
//!
//! This function
//!        1. Invoked when DMA operation is complete
//!
//! \return None.
//
//*****************************************************************************
void
DmaSwIntHandler(void)
{
    unsigned long uiIntStatus;
    iDone = 1;
    uiIntStatus = MAP_uDMAIntStatus();
    MAP_uDMAIntClear(uiIntStatus);
}

//*****************************************************************************
//
//! DMA error interrupt handler
//!
//! \param None
//!
//! This function
//!        1. Invoked when DMA operation is in error
//!
//! \return None.
//
//*****************************************************************************
void
DmaErrorIntHandler(void)
{
    MAP_uDMAIntClear(MAP_uDMAIntStatus());
}

//*****************************************************************************
//
//! Initialize the DMA controller
//!
//! \param None
//!
//! This function initializes
//!        1. Initializes the McASP module
//!
//! \return None.
//
//*****************************************************************************
void UDMAInit()
{
    unsigned int uiLoopCnt;
    //
    // Enable McASP at the PRCM module
    //
    MAP_PRCMPeripheralClkEnable(PRCM_UDMA,PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralReset(PRCM_UDMA);
    //
    // Register interrupt handlers
    //
    MAP_uDMAIntRegister(UDMA_INT_SW, DmaSwIntHandler);
    MAP_uDMAIntRegister(UDMA_INT_ERR, DmaErrorIntHandler);
    //
    // Enable uDMA using master enable
    //
    MAP_uDMAEnable();

    //
    // Set Control Table
    //
    memset(gpCtlTbl,0,sizeof(tDMAControlTable)*CTL_TBL_SIZE);
    MAP_uDMAControlBaseSet(gpCtlTbl);
    //
    // Reset App Callbacks
    //
    for(uiLoopCnt = 0; uiLoopCnt < MAX_NUM_CH; uiLoopCnt++)
    {
        gfpAppCallbackHndl[uiLoopCnt] = NULL;
    }
}

//*****************************************************************************
//
//! Configures the uDMA channel
//!
//! \param uiChannel is the DMA channel to be selected
//! \param pfpAppCb is the application callback to be invoked on transfer
//!
//! This function
//!        1. Configures the uDMA channel
//!
//! \return None.
//
//*****************************************************************************
void UDMAChannelSelect(unsigned int uiChannel, tAppCallbackHndl pfpAppCb)
{
    if((uiChannel & 0xFF) > MAX_NUM_CH)
    {
        return;
    }
    MAP_uDMAChannelAssign(uiChannel);
    MAP_uDMAChannelAttributeDisable(uiChannel,UDMA_ATTR_ALTSELECT);

    gfpAppCallbackHndl[(uiChannel & 0xFF)] = pfpAppCb;
}

//*****************************************************************************
//
//! Does the actual Memory transfer
//!
//! \param ulChannel. DMA Channel to be used
//! \param ulMode. DMA Mode to be used
//! \param ulItemCount. Items to be transfered in DMA Transfer
//! \param ulArbSize. Arbitration Size to be set
//! \param pvSrcBuf. Pointer to the source Buffer
//! \param ulSrcInc. Source Increment
//! \param pvDstBuf. Pointer to the Destination Buffer
//! \param ulDstInc. Destination Increment
//!
//! This function
//!        1. Sets up the uDMA registers to perform the actual transfer
//!
//! \return None.
//
//*****************************************************************************
void SetupTransfer(
                  unsigned long ulChannel,
                  unsigned long ulMode,
                  unsigned long ulItemCount,
                  unsigned long ulItemSize,
                  unsigned long ulArbSize,
                  void *pvSrcBuf,
                  unsigned long ulSrcInc,
                  void *pvDstBuf,
                  unsigned long ulDstInc)
{

    MAP_uDMAChannelControlSet(ulChannel,
                              ulItemSize | ulSrcInc | ulDstInc | ulArbSize);

    MAP_uDMAChannelAttributeEnable(ulChannel,UDMA_ATTR_USEBURST);

    MAP_uDMAChannelTransferSet(ulChannel, ulMode,
                               pvSrcBuf, pvDstBuf, ulItemCount);

    MAP_uDMAChannelEnable(ulChannel);

}

//*****************************************************************************
//
//! Sets up the Auto Memory transfer
//!
//! \param ulChannel. DMA Channel to be used
//! \param pvSrcBuf. Pointer to the source buffer
//! \param pvDstBuf. Pointer to the destination buffer
//! \param size. Items to be transfered
//!
//! This function
//!        1. Configures the uDMA channel
//!
//! \return None.
//
//*****************************************************************************
void UDMASetupAutoMemTransfer(unsigned long ulChannel, void *pvSrcBuf,
                              void *pvDstBuf, unsigned long size)
{
    SetupTransfer(ulChannel, UDMA_MODE_AUTO, size,
                  UDMA_SIZE_8, UDMA_ARB_8, pvSrcBuf,
                  UDMA_SRC_INC_8, pvDstBuf, UDMA_DST_INC_8);
}

//*****************************************************************************
//
//! Sets up the Ping Pong mode of transfer
//!
//! \param ulChannel. DMA Channel to be used
//! \param pvSrcBuf1.Pointer to the Source Buffer for Primary Control Structure
//! \param pvDstBuf1.Pointer to the Destination Buffer for Primary  Structure
//! \param pvSrcBuf2.Pointer to the Source Buffer for alternate Control Structure
//! \param pvDstBuf2. Pointer to the Destination Buffer for alternate Structure
//! \param size. Total size to be transferred.
//!
//! This function
//!        1. Configures the uDMA channel
//!
//! \return None.
//
//*****************************************************************************
void UDMASetupPingPongTransfer(unsigned long ulChannel, void *pvSrcBuf1,
                              void *pvDstBuf1, void *pvSrcBuf2,
                              void *pvDstBuf2, unsigned long size)
{
    SetupTransfer(ulChannel, UDMA_MODE_PINGPONG, size, UDMA_SIZE_8,
                  UDMA_ARB_8, pvSrcBuf1, UDMA_SRC_INC_8,
                  pvDstBuf1, UDMA_DST_INC_8);

    SetupTransfer(ulChannel|UDMA_ALT_SELECT, UDMA_MODE_PINGPONG, size,
                    UDMA_SIZE_8, UDMA_ARB_8, pvSrcBuf2, UDMA_SRC_INC_8,
                        pvDstBuf2, UDMA_DST_INC_8);
}

//*****************************************************************************
//
//! Start the DMA SW transfer
//!
//! \param None
//!
//! This function
//!        1. Starts the SW controlled uDMA transfer
//!
//! \return None.
//
//*****************************************************************************
void UDMAStartTransfer(unsigned long ulChannel)
{
    //
    // Request for channel transfer
    //
    MAP_uDMAChannelRequest(ulChannel);
}

//*****************************************************************************
//
//! Stop the DMA transfer
//!
//! \param None
//!
//! This function
//!        1. Stops the uDMA transfer on specified channel
//!
//! \return None.
//
//*****************************************************************************
void UDMAStopTransfer(unsigned long ulChannel)
{
    //
    // Disable the channel
    //
    MAP_uDMAChannelDisable(ulChannel);
}


//*****************************************************************************
//
//! De-Initialize the DMA controller
//!
//! \param None
//!
//! This function
//!        1. De-Initializes the uDMA module
//!
//! \return None.
//
//*****************************************************************************
void UDMADeInit()
{
    //
    // UnRegister interrupt handlers
    //
    MAP_uDMAIntUnregister(UDMA_INT_SW);
    MAP_uDMAIntUnregister(UDMA_INT_ERR);
    //
    // Disable the uDMA
    //
    MAP_uDMADisable();
}

void DMASetupTransfer(unsigned long ulChannel, unsigned long ulMode,
                      unsigned long ulItemCount, unsigned long ulItemSize,
                      unsigned long ulArbSize, void *pvSrcBuf,
                      unsigned long ulSrcInc, void *pvDstBuf, unsigned long ulDstInc)
{
    MAP_uDMAChannelControlSet(ulChannel, ulItemSize | ulSrcInc | ulDstInc | ulArbSize);
    MAP_uDMAChannelAttributeEnable(ulChannel,UDMA_ATTR_USEBURST);
    MAP_uDMAChannelTransferSet(ulChannel, ulMode, pvSrcBuf, pvDstBuf, ulItemCount);
    MAP_uDMAChannelEnable(ulChannel);
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
