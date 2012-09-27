//*****************************************************************************
//
// lpc.h - Prototypes for the Low Pin Count (LPC) driver.
//
// Copyright (c) 2010-2012 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __LPC_H__
#define __LPC_H__

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
// Values that can be passed to LPCConfigSet as the ulConfig value, and
// returned from LPCConfigGet.
//
//*****************************************************************************
#define LPC_CFG_WAKE            0x00000100  // Restart the LPC Bus

//*****************************************************************************
//
// Values that can be returned from LPCStatus.
//
//*****************************************************************************
#define LPC_STATUS_RST          0x00000400  // LPC is in Reset
#define LPC_STATUS_BUSY         0x00000200  // LPC is Busy
#define LPC_STATUS_SLEEP        0x00000100  // LPC is in Sleep Mode
#define LPC_STATUS_CA7          0x00000080  // Channel 7 Active
#define LPC_STATUS_CA6          0x00000040  // Channel 6 Active
#define LPC_STATUS_CA5          0x00000020  // Channel 5 Active
#define LPC_STATUS_CA4          0x00000010  // Channel 4 Active
#define LPC_STATUS_CA3          0x00000008  // Channel 3 Active
#define LPC_STATUS_CA2          0x00000004  // Channel 2 Active
#define LPC_STATUS_CA1          0x00000002  // Channel 1 Active
#define LPC_STATUS_CA0          0x00000001  // Channel 0 Active

//*****************************************************************************
//
// Values that can be passed to LPCIRQSet and LPCIRQClear in the ulIRQ
// parameter and returned from LPCIRQGet.
//
//*****************************************************************************
#define LPC_IRQ15               0x80000000  // Serial IRQ15
#define LPC_IRQ14               0x40000000  // Serial IRQ14
#define LPC_IRQ13               0x20000000  // Serial IRQ13
#define LPC_IRQ12               0x10000000  // Serial IRQ12
#define LPC_IRQ11               0x08000000  // Serial IRQ11
#define LPC_IRQ10               0x04000000  // Serial IRQ10
#define LPC_IRQ9                0x02000000  // Serial IRQ9
#define LPC_IRQ8                0x01000000  // Serial IRQ8
#define LPC_IRQ7                0x00800000  // Serial IRQ7
#define LPC_IRQ6                0x00400000  // Serial IRQ6
#define LPC_IRQ5                0x00200000  // Serial IRQ5
#define LPC_IRQ4                0x00100000  // Serial IRQ4
#define LPC_IRQ3                0x00080000  // Serial IRQ3
#define LPC_IRQ2                0x00040000  // Serial IRQ2
#define LPC_IRQ1                0x00020000  // Serial IRQ1
#define LPC_IRQ0                0x00010000  // Serial IRQ0
                                 
//*****************************************************************************
//
// Addition values that can be returned from LPCIRQGet.
//
//*****************************************************************************
#define LPC_IRQ_BUSY            0x00000004  // SERIRQ frame in progress
#define LPC_IRQ_CONT            0x00000001  // SERIRQ in Continuous Mode
                                 
//*****************************************************************************
//
// Values that can be passed as the ulChannel parameter in LPCChannel...
// API calls.
//
//*****************************************************************************
#define LPC_CHAN_CH0            0           // LPC Channel 0
#define LPC_CHAN_CH1            1           // LPC Channel 1
#define LPC_CHAN_CH2            2           // LPC Channel 2
#define LPC_CHAN_CH3            3           // LPC Channel 3
#define LPC_CHAN_CH4            4           // LPC Channel 4
#define LPC_CHAN_CH5            5           // LPC Channel 5
#define LPC_CHAN_CH6            6           // LPC Channel 6
#define LPC_CHAN_CH7            7           // LPC Channel 7 (COMx)
#define LPC_CHAN_COMx           7           // LPC Channel 7 (COMx)

//*****************************************************************************
//
// Values that can be passed as part of the ulConfig parameter in the
// LPCChannelConfig... functions.
//
//*****************************************************************************
#define LPC_CHAN_IRQSEL2_NONE   0x00000000  // LPC Channel IRQSEL2 Disabled
#define LPC_CHAN_IRQSEL2_IRQ0   0x00080000  // LPC Channel IRQSEL2 IRQ0
#define LPC_CHAN_IRQSEL2_IRQ1   0x10080000  // LPC Channel IRQSEL2 IRQ1
#define LPC_CHAN_IRQSEL2_IRQ2   0x20080000  // LPC Channel IRQSEL2 IRQ2
#define LPC_CHAN_IRQSEL2_IRQ3   0x30080000  // LPC Channel IRQSEL2 IRQ3
#define LPC_CHAN_IRQSEL2_IRQ4   0x40080000  // LPC Channel IRQSEL2 IRQ4
#define LPC_CHAN_IRQSEL2_IRQ5   0x50080000  // LPC Channel IRQSEL2 IRQ5
#define LPC_CHAN_IRQSEL2_IRQ6   0x60080000  // LPC Channel IRQSEL2 IRQ6
#define LPC_CHAN_IRQSEL2_IRQ7   0x70080000  // LPC Channel IRQSEL2 IRQ7
#define LPC_CHAN_IRQSEL2_IRQ8   0x80080000  // LPC Channel IRQSEL2 IRQ8
#define LPC_CHAN_IRQSEL2_IRQ9   0x90080000  // LPC Channel IRQSEL2 IRQ9
#define LPC_CHAN_IRQSEL2_IRQ10  0xA0080000  // LPC Channel IRQSEL2 IRQ10
#define LPC_CHAN_IRQSEL2_IRQ11  0xB0080000  // LPC Channel IRQSEL2 IRQ11
#define LPC_CHAN_IRQSEL2_IRQ12  0xC0080000  // LPC Channel IRQSEL2 IRQ12
#define LPC_CHAN_IRQSEL2_IRQ13  0xD0080000  // LPC Channel IRQSEL2 IRQ13
#define LPC_CHAN_IRQSEL2_IRQ14  0xE0080000  // LPC Channel IRQSEL2 IRQ14
#define LPC_CHAN_IRQSEL2_IRQ15  0xF0080000  // LPC Channel IRQSEL2 IRQ15

#define LPC_CHAN_COMxIRQ_DISABLE \
                                0x00000000  // LCP Channel COMx IRQ Disabled
#define LPC_CHAN_COMxIRQ_ENABLE 0x00080000  // LCP Channel COMx IRQ Enabled

#define LPC_CHAN_IRQSEL1_NONE   0x00000000  // LPC Channel IRQSEL1 Disabled
#define LPC_CHAN_IRQSEL1_IRQ0   0x00040000  // LPC Channel IRQSEL1 IRQ0
#define LPC_CHAN_IRQSEL1_IRQ1   0x01040000  // LPC Channel IRQSEL1 IRQ1
#define LPC_CHAN_IRQSEL1_IRQ2   0x02040000  // LPC Channel IRQSEL1 IRQ2
#define LPC_CHAN_IRQSEL1_IRQ3   0x03040000  // LPC Channel IRQSEL1 IRQ3
#define LPC_CHAN_IRQSEL1_IRQ4   0x04040000  // LPC Channel IRQSEL1 IRQ4
#define LPC_CHAN_IRQSEL1_IRQ5   0x05040000  // LPC Channel IRQSEL1 IRQ5
#define LPC_CHAN_IRQSEL1_IRQ6   0x06040000  // LPC Channel IRQSEL1 IRQ6
#define LPC_CHAN_IRQSEL1_IRQ7   0x07040000  // LPC Channel IRQSEL1 IRQ7
#define LPC_CHAN_IRQSEL1_IRQ8   0x08040000  // LPC Channel IRQSEL1 IRQ8
#define LPC_CHAN_IRQSEL1_IRQ9   0x09040000  // LPC Channel IRQSEL1 IRQ9
#define LPC_CHAN_IRQSEL1_IRQ10  0x0A040000  // LPC Channel IRQSEL1 IRQ10
#define LPC_CHAN_IRQSEL1_IRQ11  0x0B040000  // LPC Channel IRQSEL1 IRQ11
#define LPC_CHAN_IRQSEL1_IRQ12  0x0C040000  // LPC Channel IRQSEL1 IRQ12
#define LPC_CHAN_IRQSEL1_IRQ13  0x0D040000  // LPC Channel IRQSEL1 IRQ13
#define LPC_CHAN_IRQSEL1_IRQ14  0x0E040000  // LPC Channel IRQSEL1 IRQ14
#define LPC_CHAN_IRQSEL1_IRQ15  0x0F040000  // LPC Channel IRQSEL1 IRQ15

#define LPC_CHAN_IRQSEL0_NONE   0x00000000  // LPC Channel IRQSEL0 Disabled
#define LPC_CHAN_IRQSEL0_IRQ0   0x00000000  // LPC Channel IRQSEL0 IRQ0
#define LPC_CHAN_IRQSEL0_IRQ1   0x00100000  // LPC Channel IRQSEL0 IRQ1
#define LPC_CHAN_IRQSEL0_IRQ2   0x00200000  // LPC Channel IRQSEL0 IRQ2
#define LPC_CHAN_IRQSEL0_IRQ3   0x00300000  // LPC Channel IRQSEL0 IRQ3
#define LPC_CHAN_IRQSEL0_IRQ4   0x00400000  // LPC Channel IRQSEL0 IRQ4
#define LPC_CHAN_IRQSEL0_IRQ5   0x00500000  // LPC Channel IRQSEL0 IRQ5
#define LPC_CHAN_IRQSEL0_IRQ6   0x00600000  // LPC Channel IRQSEL0 IRQ6
#define LPC_CHAN_IRQSEL0_IRQ7   0x00700000  // LPC Channel IRQSEL0 IRQ7
#define LPC_CHAN_IRQSEL0_IRQ8   0x00800000  // LPC Channel IRQSEL0 IRQ8
#define LPC_CHAN_IRQSEL0_IRQ9   0x00900000  // LPC Channel IRQSEL0 IRQ9
#define LPC_CHAN_IRQSEL0_IRQ10  0x00A00000  // LPC Channel IRQSEL0 IRQ10
#define LPC_CHAN_IRQSEL0_IRQ11  0x00B00000  // LPC Channel IRQSEL0 IRQ11
#define LPC_CHAN_IRQSEL0_IRQ12  0x00C00000  // LPC Channel IRQSEL0 IRQ12
#define LPC_CHAN_IRQSEL0_IRQ13  0x00D00000  // LPC Channel IRQSEL0 IRQ13
#define LPC_CHAN_IRQSEL0_IRQ14  0x00E00000  // LPC Channel IRQSEL0 IRQ14
#define LPC_CHAN_IRQSEL0_IRQ15  0x00F00000  // LPC Channel IRQSEL0 IRQ15
#define LPC_CHAN_IRQEN0_OFF     0x00000000  // LPC Channel IRQEN0 Disabled
#define LPC_CHAN_IRQEN0_TRG1    0x00010000  // LPC Channel IRQEN0 Trigger 1
#define LPC_CHAN_IRQEN0_TRG2    0x00020000  // LPC Channel IRQEN0 Trigger 2
#define LPC_CHAN_IRQEN0_TRG3    0x00030000  // LPC Channel IRQEN0 Trigger 3

#define LPC_CHAN_MBARB_ENABLED  0x00000000  // LPC Channel Mailbox Arbritration
                                            // enabled.
#define LPC_CHAN_MBARB_DISABLED 0x00008000  // LPC Channel Mailbox Arbritration
                                            // disabled.

#define LPC_CHAN_SIZE_4         0x00000000  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.
#define LPC_CHAN_SIZE_8         0x00000004  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.
#define LPC_CHAN_SIZE_16        0x00000008  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.
#define LPC_CHAN_SIZE_32        0x0000000C  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.
#define LPC_CHAN_SIZE_64        0x00000010  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.
#define LPC_CHAN_SIZE_128       0x00000014  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.
#define LPC_CHAN_SIZE_256       0x00000018  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.
#define LPC_CHAN_SIZE_512       0x0000001C  // Mailbox IO/Memory Window size
                                            // is 4 Bytes.

//*****************************************************************************
//
// Values that can be passed to LCPChannelConfigCOMxSet as the ulCOMxMode
// parameter or returned from LPCChannelConfigGet in the pulCOMxMode
// parameter.
//
//*****************************************************************************
#define LPC_COMx_MODE_FRMHNML   0x00000000  // Normal From Host model.
#define LPC_COMx_MODE_FRMHIGN   0x00020000  // Ignore From Host data.
#define LPC_COMx_MODE_FRMHDMA   0x00040000  // COMx DMA on From Host data to
                                            // memory
#define LPC_COMx_MODE_UARTDMA   0x00060000  // COMx DMA on From Host data to
                                            // UART1

//*****************************************************************************
//
// Additinal values that can be returned from LPCChannelConfigGet in the
// pulCOMxMode parameter.
//
//*****************************************************************************
#define LPC_COMx_ENABLED        0x00010000  // COMx mode enabled.
    
//*****************************************************************************
//
// Values that can be passed to LPCIntEnable, LPCIntDisable, and LPCIntClear
// as the ulIntFlags parameter and returned by LPCIntStatus.
//
//*****************************************************************************
#define LPC_INT_RST             0x80000000  // LPC Bus Enters or Exits
                                            // Reset State.
#define LPC_INT_SLEEP           0x40000000  // LPC Bus Enters or Exits
                                            // Sleep State.
#define LPC_INT_COMx            0x20000000  // COMx has read/written
                                            // data.
#define LPC_INT_SIRQ            0x10000000  // SERIRQ frame has completed
#define LPC_INT_CH6_EP_TO_HOST  (1 << 24)   // To-Host has been read.
#define LPC_INT_CH6_EP_FROM_DATA \
                                (2 << 24)   // From-Host has been written as
                                            // data.
#define LPC_INT_CH6_EP_FROM_CMD (4 << 24)   // From-Host has been written as
                                            // command.
#define LPC_INT_CH6_MB_HOST_WON (1 << 24)   // Host Won (HW1ST)
#define LPC_INT_CH6_MB_HOST_WRITE \
                                (2 << 24)   // Host Wrote Last Byte.
#define LPC_INT_CH6_MB_HOST_READ \
                                (4 << 24)   // Host Read Last Byte
#define LPC_INT_CH6_MB_MCU_LOST (8 << 24)   // MCU Lost (when host had HW1ST).
#define LPC_INT_CH5_EP_TO_HOST  (1 << 20)   // To-Host has been read.
#define LPC_INT_CH5_EP_FROM_DATA \
                                (2 << 20)   // From-Host has been written as
                                            // data.
#define LPC_INT_CH5_EP_FROM_CMD (4 << 20)   // From-Host has been written as
                                            // command.
#define LPC_INT_CH5_MB_HOST_WON (1 << 20)   // Host Won (HW1ST)
#define LPC_INT_CH5_MB_HOST_WRITE \
                                (2 << 20)   // Host Wrote Last Byte.
#define LPC_INT_CH5_MB_HOST_READ \
                                (4 << 20)   // Host Read Last Byte
#define LPC_INT_CH5_MB_MCU_LOST (8 << 20)   // MCU Lost (when host had HW1ST).
#define LPC_INT_CH4_EP_TO_HOST  (1 << 16)   // To-Host has been read.
#define LPC_INT_CH4_EP_FROM_DATA \
                                (2 << 16)   // From-Host has been written as
                                            // data.
#define LPC_INT_CH4_EP_FROM_CMD (4 << 16)   // From-Host has been written as
                                            // command.
#define LPC_INT_CH4_MB_HOST_WON (1 << 16)   // Host Won (HW1ST)
#define LPC_INT_CH4_MB_HOST_WRITE \
                                (2 << 16)   // Host Wrote Last Byte.
#define LPC_INT_CH4_MB_HOST_READ \
                                (4 << 16)   // Host Read Last Byte
#define LPC_INT_CH4_MB_MCU_LOST (8 << 16)   // MCU Lost (when host had HW1ST).
#define LPC_INT_CH3_EP_TO_HOST  (1 << 12)   // To-Host has been read.
#define LPC_INT_CH3_EP_FROM_DATA \
                                (2 << 12)   // From-Host has been written as
                                            // data.
#define LPC_INT_CH3_EP_FROM_CMD (4 << 12)   // From-Host has been written as
                                            // command.
#define LPC_INT_CH3_MB_HOST_WON (1 << 12)   // Host Won (HW1ST)
#define LPC_INT_CH3_MB_HOST_WRITE \
                                (2 << 12)   // Host Wrote Last Byte.
#define LPC_INT_CH3_MB_HOST_READ \
                                (4 << 12)   // Host Read Last Byte
#define LPC_INT_CH3_MB_MCU_LOST (8 << 12)   // MCU Lost (when host had HW1ST).
#define LPC_INT_CH2_EP_TO_HOST  (1 <<  8)   // To-Host has been read.
#define LPC_INT_CH2_EP_FROM_DATA \
                                (2 <<  8)   // From-Host has been written as
                                            // data.
#define LPC_INT_CH2_EP_FROM_CMD (4 <<  8)   // From-Host has been written as
                                            // command.
#define LPC_INT_CH2_MB_HOST_WON (1 <<  8)   // Host Won (HW1ST)
#define LPC_INT_CH2_MB_HOST_WRITE \
                                (2 <<  8)   // Host Wrote Last Byte.
#define LPC_INT_CH2_MB_HOST_READ \
                                (4 <<  8)   // Host Read Last Byte
#define LPC_INT_CH2_MB_MCU_LOST (8 <<  8)   // MCU Lost (when host had HW1ST).
#define LPC_INT_CH1_EP_TO_HOST  (1 <<  4)   // To-Host has been read.
#define LPC_INT_CH1_EP_FROM_DATA \
                                (2 <<  4)   // From-Host has been written as
                                            // data.
#define LPC_INT_CH1_EP_FROM_CMD (4 <<  4)   // From-Host has been written as
                                            // command.
#define LPC_INT_CH1_MB_HOST_WON (1 <<  4)   // Host Won (HW1ST)
#define LPC_INT_CH1_MB_HOST_WRITE \
                                (2 <<  4)   // Host Wrote Last Byte.
#define LPC_INT_CH1_MB_HOST_READ \
                                (4 <<  4)   // Host Read Last Byte
#define LPC_INT_CH1_MB_MCU_LOST (8 <<  4)   // MCU Lost (when host had HW1ST).
#define LPC_INT_CH0_EP_TO_HOST  (1 <<  0)   // To-Host has been read.
#define LPC_INT_CH0_EP_FROM_DATA \
                                (2 <<  0)   // From-Host has been written as
                                            // data.
#define LPC_INT_CH0_EP_FROM_CMD (4 <<  0)   // From-Host has been written as
                                            // command.
#define LPC_INT_CH0_MB_HOST_WON (1 <<  0)   // Host Won (HW1ST)
#define LPC_INT_CH0_MB_HOST_WRITE \
                                (2 <<  0)   // Host Wrote Last Byte.
#define LPC_INT_CH0_MB_HOST_READ \
                                (4 <<  0)   // Host Read Last Byte
#define LPC_INT_CH0_MB_MCU_LOST (8 <<  0)   // MCU Lost (when host had HW1ST).

//*****************************************************************************
//
// Values that can be passed to LPCCOMxInt... functions as the ulIntFlags
// parameter and returned by LPCIntStatus.
//
//*****************************************************************************
#define LPC_COMx_INT_CX         0x02000000  // Raw Event State for COMx
#define LPC_COMx_INT_CXTX       0x01000000  // Raw Event State for COMx TX
#define LPC_COMx_INT_CXRX       0x00800000  // Raw Event State for COMx RX
#define LPC_COMx_MASK_CX        0x00200000  // Event Mask for COMx
#define LPC_COMx_MASK_CXTX      0x00100000  // Event Mask for COMx TX
#define LPC_COMx_MASK_CXRX      0x00080000  // Event Mask for COMx RX
    
//*****************************************************************************
//
// Values that can be passed to the LPCChannelDMAConfigSet function as part
// of the ulConfig or ulMask parameter, or can be returned from the
// LPCChannelConfigGet function.
//
//*****************************************************************************
#define LPC_DMA_CH3_WEN         0x00000080  // Trigger DMA for "To Host" data
                                            // buffer is empty.
#define LPC_DMA_CH3_REN         0x00000040  // Trigger DMA when "From Host"
                                            // data buffer is full.
#define LPC_DMA_CH2_WEN         0x00000020  // Trigger DMA for "To Host" data
                                            // buffer is empty.
#define LPC_DMA_CH2_REN         0x00000010  // Trigger DMA when "From Host"
                                            // data buffer is full.
#define LPC_DMA_CH1_WEN         0x00000008  // Trigger DMA for "To Host" data
                                            // buffer is empty.
#define LPC_DMA_CH1_REN         0x00000004  // Trigger DMA when "From Host"
                                            // data buffer is full.
#define LPC_DMA_CH0_WEN         0x00000002  // Trigger DMA for "To Host" data
                                            // buffer is empty.
#define LPC_DMA_CH0_REN         0x00000001  // Trigger DMA when "From Host"
                                            // data buffer is full.
//*****************************************************************************
//
// Values that can be passed to the LPCChannelStatusSet and
// LPCChannelStatusClear function, and returned by the LPCChannelStatusGet
// function.
//
//*****************************************************************************
#define LPC_CH_ST_USER0         0x00000100  // User Status Bit 0
#define LPC_CH_ST_USER1         0x00000200  // User Status Bit 1
#define LPC_CH_ST_USER2         0x00000400  // User Status Bit 2
#define LPC_CH_ST_USER3         0x00000800  // User Status Bit 3
#define LPC_CH_ST_USER4         0x00001000  // User Status Bit 4
    
//*****************************************************************************
//
// Additinoal values that can be returned by the LPCChannelStatusGet function.
//
//*****************************************************************************
#define LPC_CH_ST_LASTHW        0x00000080  // Last Host Write
#define LPC_CH_ST_HW1ST         0x00000040  // First Host Write
#define LPC_CH_ST_LASTSW        0x00000020  // Last Slave Write
#define LPC_CH_ST_SW1ST         0x00000010  // First Slave Write
#define LPC_CH_ST_CMD           0x00000008  // Command or Data
#define LPC_CH_ST_FRMH          0x00000002  // From-Host Transaction
#define LPC_CH_ST_TOH           0x00000001  // To-Host Transaction

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void LPCConfigSet(unsigned long ulBase, unsigned long ulConfig);
extern unsigned long LPCConfigGet(unsigned long ulBase);
extern unsigned long LPCStatusGet(unsigned long ulBase,
                                  unsigned long *pulCount,
                                  unsigned long *pulPoolSize);
extern void LPCStatusBlockAddressSet(unsigned long ulBase,
                                     unsigned long ulAddress,
                                     tBoolean bEnabled);
extern unsigned LPCStatusBlockAddressGet(unsigned long ulBase);
extern void LPCSCIAssert(unsigned long ulBase, unsigned long ulCount);
extern void LPCIRQConfig(unsigned long ulBase, tBoolean bIRQPulse,
                         tBoolean bIRQOnChange);
extern void LPCIRQSet(unsigned long ulBase, unsigned long ulIRQ);
extern void LPCIRQClear(unsigned long ulBase, unsigned long ulIRQ);
extern unsigned long LPCIRQGet(unsigned long ulBase);
extern void LPCIRQSend(unsigned long ulBase);
extern void LPCIntRegister(unsigned long ulBase, void (*pfnHandler)(void));
extern void LPCIntUnregister(unsigned long ulBase);
extern void LPCIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void LPCIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long LPCIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void LPCIntClear(unsigned long ulBase, unsigned long ulIntFlags);
extern void LPCChannelEnable(unsigned long ulBase, unsigned long ulChannel);
extern void LPCChannelDisable(unsigned long ulBase, unsigned long ulChannel);
extern void LPCChannelConfigEPSet(unsigned long ulBase,
                                  unsigned long ulChannel,
                                  unsigned long ulConfig,
                                  unsigned long ulAddress,
                                  unsigned long ulOffset);
extern void LPCChannelConfigMBSet(unsigned long ulBase,
                                  unsigned long ulChannel,
                                  unsigned long ulConfig,
                                  unsigned long ulAddress,
                                  unsigned long ulOffset);
extern void LPCChannelConfigCOMxSet(unsigned long ulBase,
                                    unsigned long ulChannel,
                                    unsigned long ulConfig,
                                    unsigned long ulAddress,
                                    unsigned long ulOffset,
                                    unsigned long ulCOMxMode);
extern unsigned long LPCChannelConfigGet(unsigned long ulBase,
                                         unsigned long ulChannel,
                                         unsigned long *pulAddress,
                                         unsigned long *pulOffset,
                                         unsigned long *pulCOMxMode);
extern unsigned long LPCChannelPoolAddressGet(unsigned long ulBase,
                                              unsigned long ulChannel);
extern unsigned long LPCChannelStatusGet(unsigned long ulBase,
                                         unsigned long ulChannel);
extern void LPCChannelStatusSet(unsigned long ulBase, unsigned long ulChannel,
                                unsigned long ulStatus);
extern void LPCChannelStatusClear(unsigned long ulBase,
                                  unsigned long ulChannel,
                                  unsigned long ulStatus);
extern void LPCChannelDMAConfigSet(unsigned long ulBase,
                                   unsigned long ulConfig,
                                   unsigned long ulMask);
extern unsigned long LPCChannelDMAConfigGet(unsigned long ulBase);
extern unsigned char LPCByteRead(unsigned long ulBase, unsigned long ulOffset);
extern void LPCByteWrite(unsigned long ulBase, unsigned long ulOffset,
                         unsigned char ucData);
extern unsigned short LPCHalfWordRead(unsigned long ulBase,
                                      unsigned long ulOffset);
extern void LPCHalfWordWrite(unsigned long ulBase, unsigned long ulOffset,
                             unsigned short usData);
extern unsigned long LPCWordRead(unsigned long ulBase, unsigned long ulOffset);
extern void LPCWordWrite(unsigned long ulBase, unsigned long ulOffset,
                         unsigned long ulData);
extern void LPCCOMxIntEnable(unsigned long ulBase, unsigned long ulIntFlags);
extern void LPCCOMxIntDisable(unsigned long ulBase, unsigned long ulIntFlags);
extern unsigned long LPCCOMxIntStatus(unsigned long ulBase, tBoolean bMasked);
extern void LPCCOMxIntClear(unsigned long ulBase, unsigned long ulIntFlags);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __LPC_H__
