//*****************************************************************************
// udma_if.h
//
// uDMA interface MACRO and function prototypes
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

#ifndef __UDMA_IF_H__
#define __UDMA_IF_H__

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

#define PRINT_DBG               printf

typedef void (*tAppCallbackHndl)(void);
#define MAX_NUM_CH	            64	//32*2 entries
#define CTL_TBL_SIZE	            64	//32*2 entries

#define UDMA_CH5_BITID          (1<<5)

//
// UDMA Interface APIs
//
void UDMAInit();
void UDMAChannelSelect(unsigned int uiChannel, tAppCallbackHndl pfpAppCb);
void SetupTransfer(
                  unsigned long ulChannel, 
                  unsigned long ulMode,
                  unsigned long ulItemCount,
                  unsigned long ulItemSize, 
                  unsigned long ulArbSize,
                  void *pvSrcBuf, 
                  unsigned long ulSrcInc,
                  void *pvDstBuf, 
                  unsigned long ulDstInc);
void UDMASetupAutoMemTransfer(
                              unsigned long ulChannel,
                              void *pvSrcBuf,
                              void *pvDstBuf,
                              unsigned long size);
void UDMASetupPingPongTransfer(
                              unsigned long ulChannel,
                              void *pvSrcBuf1,
                              void *pvDstBuf1,
                              void *pvSrcBuf2,
                              void *pvDstBuf2,
                              unsigned long size);
void UDMAStartTransfer(unsigned long ulChannel);
void UDMAStopTransfer(unsigned long ulChannel);
void UDMADeInit();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __UDMA_IF_H__

