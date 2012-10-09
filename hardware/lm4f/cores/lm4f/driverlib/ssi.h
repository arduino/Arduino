//*****************************************************************************
//
// ssi.h - Prototypes for the Synchronous Serial Interface Driver.
//
// Copyright (c) 2005-2012 Texas Instruments Incorporated.  All rights reserved.
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
// This is part of revision 9453 of the Stellaris Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __SSI_H__
#define __SSI_H__

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

//*****************************************************************************
//
// Values that can be passed to SSIIntEnable, SSIIntDisable, and SSIIntClear
// as the ulIntFlags parameter, and returned by SSIIntStatus.
//
//*****************************************************************************
#define SSI_TXFF                0x00000008  // TX FIFO half full or less
#define SSI_RXFF                0x00000004  // RX FIFO half full or more
#define SSI_RXTO                0x00000002  // RX timeout
#define SSI_RXOR                0x00000001  // RX overrun

//*****************************************************************************
//
// Values that can be passed to SSIConfigSetExpClk.
//
//*****************************************************************************
#define SSI_FRF_MOTO_MODE_0     0x00000000  // Moto fmt, polarity 0, phase 0
#define SSI_FRF_MOTO_MODE_1     0x00000002  // Moto fmt, polarity 0, phase 1
#define SSI_FRF_MOTO_MODE_2     0x00000001  // Moto fmt, polarity 1, phase 0
#define SSI_FRF_MOTO_MODE_3     0x00000003  // Moto fmt, polarity 1, phase 1
#define SSI_FRF_TI              0x00000010  // TI frame format
#define SSI_FRF_NMW             0x00000020  // National MicroWire frame format

#define SSI_MODE_MASTER         0x00000000  // SSI master
#define SSI_MODE_SLAVE          0x00000001  // SSI slave
#define SSI_MODE_SLAVE_OD       0x00000002  // SSI slave with output disabled

//*****************************************************************************
//
// Values that can be passed to SSIDMAEnable() and SSIDMADisable().
//
//*****************************************************************************
#define SSI_DMA_TX              0x00000002  // Enable DMA for transmit
#define SSI_DMA_RX              0x00000001  // Enable DMA for receive

//*****************************************************************************
//
// Values that can be passed to SSIClockSourceSet() or returned from
// SSIClockSourceGet().
//
//*****************************************************************************
#define SSI_CLOCK_SYSTEM        0x00000000
#define SSI_CLOCK_PIOSC         0x00000005

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void SSIConfigSetExpClk(unsigned long ulBase, unsigned long ulSSIClk,
                               unsigned long ulProtocol, unsigned long ulMode,
                               unsigned long ulBitRate,
                               unsigned long ulDataWidth);
extern void SSIDataGet(unsigned long ulBase, unsigned long *pulData);
extern long SSIDataGetNonBlocking(unsigned long ulBase,
                                  unsigned long *pulData);
extern void SSIDataPut(unsigned long ulBase, unsigned long ulData);
extern long SSIDataPutNonBlocking(unsigned long ulBase, unsigned long ulData);
extern void SSIDisable(unsigned long ulBase);
extern void SSIEnable(unsigned long ulBase);
extern void SSIIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void SSIIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern void SSIIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void SSIIntRegister(unsigned long ulBase, void(*pfnHandler)(void));
extern unsigned long SSIIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void SSIIntUnregister(unsigned long ulBase);
extern void SSIDMAEnable(unsigned long ulBase, unsigned long ulDMAFlags);
extern void SSIDMADisable(unsigned long ulBase, unsigned long ulDMAFlags);
extern tBoolean SSIBusy(unsigned long ulBase);
extern void SSIClockSourceSet(unsigned long ulBase, unsigned long ulSource);
extern unsigned long SSIClockSourceGet(unsigned long ulBase);

//*****************************************************************************
//
// Several SSI APIs have been renamed, with the original function name being
// deprecated.  These defines provide backward compatibility.
//
//*****************************************************************************
#ifndef DEPRECATED
#include "driverlib/sysctl.h"
#define SSIConfig(a, b, c, d, e)                            \
        SSIConfigSetExpClk(a, SysCtlClockGet(), b, c, d, e)
#define SSIDataNonBlockingGet(a, b) \
        SSIDataGetNonBlocking(a, b)
#define SSIDataNonBlockingPut(a, b) \
        SSIDataPutNonBlocking(a, b)
#endif

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __SSI_H__
