//*****************************************************************************
//
// udma.h - Prototypes and macros for the uDMA controller.
//
// Copyright (c) 2007-2012 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __UDMA_H__
#define __UDMA_H__

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
//! \addtogroup udma_api
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
// A structure that defines an entry in the channel control table.  These
// fields are used by the uDMA controller and normally it is not necessary for
// software to directly read or write fields in the table.
//
//*****************************************************************************
typedef struct
{
    //
    // The ending source address of the data transfer.
    //
    volatile void *pvSrcEndAddr;

    //
    // The ending destination address of the data transfer.
    //
    volatile void *pvDstEndAddr;

    //
    // The channel control mode.
    //
    volatile unsigned long ulControl;

    //
    // An unused location.
    //
    volatile unsigned long ulSpare;
}
tDMAControlTable;

//*****************************************************************************
//
//! A helper macro for building scatter-gather task table entries.
//!
//! \param ulTransferCount is the count of items to transfer for this task.
//! \param ulItemSize is the bit size of the items to transfer for this task.
//! \param ulSrcIncrement is the bit size increment for source data.
//! \param pvSrcAddr is the starting address of the data to transfer.
//! \param ulDstIncrement is the bit size increment for destination data.
//! \param pvDstAddr is the starting address of the destination data.
//! \param ulArbSize is the arbitration size to use for the transfer task.
//! \param ulMode is the transfer mode for this task.
//!
//! This macro is intended to be used to help populate a table of uDMA tasks
//! for a scatter-gather transfer.  This macro will calculate the values for
//! the fields of a task structure entry based on the input parameters.
//!
//! There are specific requirements for the values of each parameter.  No
//! checking is done so it is up to the caller to ensure that correct values
//! are used for the parameters.
//!
//! The \e ulTransferCount parameter is the number of items that will be
//! transferred by this task.  It must be in the range 1-1024.
//!
//! The \e ulItemSize parameter is the bit size of the transfer data.  It must
//! be one of \b UDMA_SIZE_8, \b UDMA_SIZE_16, or \b UDMA_SIZE_32.
//!
//! The \e ulSrcIncrement parameter is the increment size for the source data.
//! It must be one of \b UDMA_SRC_INC_8, \b UDMA_SRC_INC_16,
//! \b UDMA_SRC_INC_32, or \b UDMA_SRC_INC_NONE.
//!
//! The \e pvSrcAddr parameter is a void pointer to the beginning of the source
//! data.
//!
//! The \e ulDstIncrement parameter is the increment size for the destination
//! data.  It must be one of \b UDMA_DST_INC_8, \b UDMA_DST_INC_16,
//! \b UDMA_DST_INC_32, or \b UDMA_DST_INC_NONE.
//!
//! The \e pvDstAddr parameter is a void pointer to the beginning of the
//! location where the data will be transferred.
//!
//! The \e ulArbSize parameter is the arbitration size for the transfer, and
//! must be one of \b UDMA_ARB_1, \b UDMA_ARB_2, \b UDMA_ARB_4, and so on
//! up to \b UDMA_ARB_1024.  This is used to select the arbitration size in
//! powers of 2, from 1 to 1024.
//!
//! The \e ulMode parameter is the mode to use for this transfer task.  It
//! must be one of \b UDMA_MODE_BASIC, \b UDMA_MODE_AUTO,
//! \b UDMA_MODE_MEM_SCATTER_GATHER, or \b UDMA_MODE_PER_SCATTER_GATHER.  Note
//! that normally all tasks will be one of the scatter-gather modes while the
//! last task is a task list will be AUTO or BASIC.
//!
//! This macro is intended to be used to initialize individual entries of
//! a structure of tDMAControlTable type, like this:
//!
//! \verbatim
//!     tDMAControlTable MyTaskList[] =
//!     {
//!         uDMATaskStructEntry(Task1Count, UDMA_SIZE_8,
//!                             UDMA_SRC_INC_8, MySourceBuf,
//!                             UDMA_DST_INC_8, MyDestBuf,
//!                             UDMA_ARB_8, UDMA_MODE_MEM_SCATTER_GATHER),
//!         uDMATaskStructEntry(Task2Count, ... ),
//!     }
//! \endverbatim
//!
//! \return Nothing; this is not a function.
//
//*****************************************************************************
#define uDMATaskStructEntry(ulTransferCount,                                  \
                            ulItemSize,                                       \
                            ulSrcIncrement,                                   \
                            pvSrcAddr,                                        \
                            ulDstIncrement,                                   \
                            pvDstAddr,                                        \
                            ulArbSize,                                        \
                            ulMode)                                           \
    {                                                                         \
        (((ulSrcIncrement) == UDMA_SRC_INC_NONE) ? (void *)(pvSrcAddr) :      \
            ((void *)(&((unsigned char *)(pvSrcAddr))[((ulTransferCount) <<   \
                                         ((ulSrcIncrement) >> 26)) - 1]))),   \
            (((ulDstIncrement) == UDMA_DST_INC_NONE) ? (void *)(pvDstAddr) :  \
            ((void *)(&((unsigned char *)(pvDstAddr))[((ulTransferCount) <<   \
                                         ((ulDstIncrement) >> 30)) - 1]))),   \
        (ulSrcIncrement) | (ulDstIncrement) | (ulItemSize) | (ulArbSize) |    \
        (((ulTransferCount) - 1) << 4) |                                      \
        ((((ulMode) == UDMA_MODE_MEM_SCATTER_GATHER) ||                       \
          ((ulMode) == UDMA_MODE_PER_SCATTER_GATHER)) ?                       \
                (ulMode) | UDMA_MODE_ALT_SELECT : (ulMode)), 0                \
    }

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
// Flags that can be passed to uDMAChannelAttributeEnable(),
// uDMAChannelAttributeDisable(), and returned from uDMAChannelAttributeGet().
//
//*****************************************************************************
#define UDMA_ATTR_USEBURST      0x00000001
#define UDMA_ATTR_ALTSELECT     0x00000002
#define UDMA_ATTR_HIGH_PRIORITY 0x00000004
#define UDMA_ATTR_REQMASK       0x00000008
#define UDMA_ATTR_ALL           0x0000000F

//*****************************************************************************
//
// DMA control modes that can be passed to uDMAModeSet() and returned
// uDMAModeGet().
//
//*****************************************************************************
#define UDMA_MODE_STOP          0x00000000
#define UDMA_MODE_BASIC         0x00000001
#define UDMA_MODE_AUTO          0x00000002
#define UDMA_MODE_PINGPONG      0x00000003
#define UDMA_MODE_MEM_SCATTER_GATHER                                          \
                                0x00000004
#define UDMA_MODE_PER_SCATTER_GATHER                                          \
                                0x00000006
#define UDMA_MODE_ALT_SELECT    0x00000001

//*****************************************************************************
//
// Channel configuration values that can be passed to uDMAControlSet().
//
//*****************************************************************************
#define UDMA_DST_INC_8          0x00000000
#define UDMA_DST_INC_16         0x40000000
#define UDMA_DST_INC_32         0x80000000
#define UDMA_DST_INC_NONE       0xc0000000
#define UDMA_SRC_INC_8          0x00000000
#define UDMA_SRC_INC_16         0x04000000
#define UDMA_SRC_INC_32         0x08000000
#define UDMA_SRC_INC_NONE       0x0c000000
#define UDMA_SIZE_8             0x00000000
#define UDMA_SIZE_16            0x11000000
#define UDMA_SIZE_32            0x22000000
#define UDMA_ARB_1              0x00000000
#define UDMA_ARB_2              0x00004000
#define UDMA_ARB_4              0x00008000
#define UDMA_ARB_8              0x0000c000
#define UDMA_ARB_16             0x00010000
#define UDMA_ARB_32             0x00014000
#define UDMA_ARB_64             0x00018000
#define UDMA_ARB_128            0x0001c000
#define UDMA_ARB_256            0x00020000
#define UDMA_ARB_512            0x00024000
#define UDMA_ARB_1024           0x00028000
#define UDMA_NEXT_USEBURST      0x00000008

//*****************************************************************************
//
// Channel numbers to be passed to API functions that require a channel number
// ID.
//
//*****************************************************************************
#define UDMA_CHANNEL_USBEP1RX   0
#define UDMA_CHANNEL_USBEP1TX   1
#define UDMA_CHANNEL_USBEP2RX   2
#define UDMA_CHANNEL_USBEP2TX   3
#define UDMA_CHANNEL_USBEP3RX   4
#define UDMA_CHANNEL_USBEP3TX   5
#define UDMA_CHANNEL_ETH0RX     6
#define UDMA_CHANNEL_ETH0TX     7
#define UDMA_CHANNEL_UART0RX    8
#define UDMA_CHANNEL_UART0TX    9
#define UDMA_CHANNEL_SSI0RX     10
#define UDMA_CHANNEL_SSI0TX     11
#define UDMA_CHANNEL_ADC0       14
#define UDMA_CHANNEL_ADC1       15
#define UDMA_CHANNEL_ADC2       16
#define UDMA_CHANNEL_ADC3       17
#define UDMA_CHANNEL_TMR0A      18
#define UDMA_CHANNEL_TMR0B      19
#define UDMA_CHANNEL_TMR1A      20
#define UDMA_CHANNEL_TMR1B      21
#define UDMA_CHANNEL_UART1RX    22
#define UDMA_CHANNEL_UART1TX    23
#define UDMA_CHANNEL_SSI1RX     24
#define UDMA_CHANNEL_SSI1TX     25
#define UDMA_CHANNEL_I2S0RX     28
#define UDMA_CHANNEL_I2S0TX     29
#define UDMA_CHANNEL_SW         30

//*****************************************************************************
//
// Flags to be OR'd with the channel ID to indicate if the primary or alternate
// control structure should be used.
//
//*****************************************************************************
#define UDMA_PRI_SELECT         0x00000000
#define UDMA_ALT_SELECT         0x00000020

//*****************************************************************************
//
// uDMA interrupt sources, to be passed to uDMAIntRegister() and
// uDMAIntUnregister().
//
//*****************************************************************************
#define UDMA_INT_SW             62
#define UDMA_INT_ERR            63

//*****************************************************************************
//
// Channel numbers to be passed to API functions that require a channel number
// ID.  These are for secondary peripheral assignments.
//
//*****************************************************************************
#define UDMA_SEC_CHANNEL_UART2RX_0                                            \
                                0
#define UDMA_SEC_CHANNEL_UART2TX_1                                            \
                                1
#define UDMA_SEC_CHANNEL_TMR3A  2
#define UDMA_SEC_CHANNEL_TMR3B  3
#define UDMA_SEC_CHANNEL_TMR2A_4                                              \
                                4
#define UDMA_SEC_CHANNEL_TMR2B_5                                              \
                                5
#define UDMA_SEC_CHANNEL_TMR2A_6                                              \
                                6
#define UDMA_SEC_CHANNEL_TMR2B_7                                              \
                                7
#define UDMA_SEC_CHANNEL_UART1RX                                              \
                                8
#define UDMA_SEC_CHANNEL_UART1TX                                              \
                                9
#define UDMA_SEC_CHANNEL_SSI1RX 10
#define UDMA_SEC_CHANNEL_SSI1TX 11
#define UDMA_SEC_CHANNEL_UART2RX_12                                           \
                                12
#define UDMA_SEC_CHANNEL_UART2TX_13                                           \
                                13
#define UDMA_SEC_CHANNEL_TMR2A_14                                             \
                                14
#define UDMA_SEC_CHANNEL_TMR2B_15                                             \
                                15
#define UDMA_SEC_CHANNEL_TMR1A  18
#define UDMA_SEC_CHANNEL_TMR1B  19
#define UDMA_SEC_CHANNEL_EPI0RX 20
#define UDMA_SEC_CHANNEL_EPI0TX 21
#define UDMA_SEC_CHANNEL_ADC10  24
#define UDMA_SEC_CHANNEL_ADC11  25
#define UDMA_SEC_CHANNEL_ADC12  26
#define UDMA_SEC_CHANNEL_ADC13  27
#define UDMA_SEC_CHANNEL_SW     30

//*****************************************************************************
//
// uDMA default/secondary peripheral selections, to be passed to
// uDMAChannelSelectSecondary() and uDMAChannelSelectDefault().
//
//*****************************************************************************
#define UDMA_DEF_USBEP1RX_SEC_UART2RX                                         \
                                0x00000001
#define UDMA_DEF_USBEP1TX_SEC_UART2TX                                         \
                                0x00000002
#define UDMA_DEF_USBEP2RX_SEC_TMR3A                                           \
                                0x00000004
#define UDMA_DEF_USBEP2TX_SEC_TMR3B                                           \
                                0x00000008
#define UDMA_DEF_USBEP3RX_SEC_TMR2A                                           \
                                0x00000010
#define UDMA_DEF_USBEP3TX_SEC_TMR2B                                           \
                                0x00000020
#define UDMA_DEF_ETH0RX_SEC_TMR2A                                             \
                                0x00000040
#define UDMA_DEF_ETH0TX_SEC_TMR2B                                             \
                                0x00000080
#define UDMA_DEF_UART0RX_SEC_UART1RX                                          \
                                0x00000100
#define UDMA_DEF_UART0TX_SEC_UART1TX                                          \
                                0x00000200
#define UDMA_DEF_SSI0RX_SEC_SSI1RX                                            \
                                0x00000400
#define UDMA_DEF_SSI0TX_SEC_SSI1TX                                            \
                                0x00000800
#define UDMA_DEF_RESERVED_SEC_UART2RX                                         \
                                0x00001000
#define UDMA_DEF_RESERVED_SEC_UART2TX                                         \
                                0x00002000
#define UDMA_DEF_ADC00_SEC_TMR2A                                              \
                                0x00004000
#define UDMA_DEF_ADC01_SEC_TMR2B                                              \
                                0x00008000
#define UDMA_DEF_ADC02_SEC_RESERVED                                           \
                                0x00010000
#define UDMA_DEF_ADC03_SEC_RESERVED                                           \
                                0x00020000
#define UDMA_DEF_TMR0A_SEC_TMR1A                                              \
                                0x00040000
#define UDMA_DEF_TMR0B_SEC_TMR1B                                              \
                                0x00080000
#define UDMA_DEF_TMR1A_SEC_EPI0RX                                             \
                                0x00100000
#define UDMA_DEF_TMR1B_SEC_EPI0TX                                             \
                                0x00200000
#define UDMA_DEF_UART1RX_SEC_RESERVED                                         \
                                0x00400000
#define UDMA_DEF_UART1TX_SEC_RESERVED                                         \
                                0x00800000
#define UDMA_DEF_SSI1RX_SEC_ADC10                                             \
                                0x01000000
#define UDMA_DEF_SSI1TX_SEC_ADC11                                             \
                                0x02000000
#define UDMA_DEF_RESERVED_SEC_ADC12                                           \
                                0x04000000
#define UDMA_DEF_RESERVED_SEC_ADC13                                           \
                                0x08000000
#define UDMA_DEF_I2S0RX_SEC_RESERVED                                          \
                                0x10000000
#define UDMA_DEF_I2S0TX_SEC_RESERVED                                          \
                                0x20000000

//*****************************************************************************
//
// Values that can be passed to uDMAChannelAssign() to select peripheral
// mapping for each channel.  The channels named RESERVED may be assigned
// to a peripheral in future parts.
//
//*****************************************************************************
//
// Channel 0
//
#define UDMA_CH0_USB0EP1RX          0x00000000
#define UDMA_CH0_UART2RX            0x00010000
#define UDMA_CH0_RESERVED2          0x00020000
#define UDMA_CH0_TIMER4A            0x00030000
#define UDMA_CH0_RESERVED4          0x00040000

//
// Channel 1
//
#define UDMA_CH1_USB0EP1TX          0x00000001
#define UDMA_CH1_UART2TX            0x00010001
#define UDMA_CH1_RESERVED2          0x00020001
#define UDMA_CH1_TIMER4B            0x00030001
#define UDMA_CH1_RESERVED4          0x00040001

//
// Channel 2
//
#define UDMA_CH2_USB0EP2RX          0x00000002
#define UDMA_CH2_TIMER3A            0x00010002
#define UDMA_CH2_RESERVED2          0x00020002
#define UDMA_CH2_RESERVED3          0x00030002
#define UDMA_CH2_RESERVED4          0x00040002

//
// Channel 3
//
#define UDMA_CH3_USB0EP2TX          0x00000003
#define UDMA_CH3_TIMER3B            0x00010003
#define UDMA_CH3_RESERVED2          0x00020003
#define UDMA_CH3_LPC0_3             0x00030003
#define UDMA_CH3_RESERVED4          0x00040003

//
// Channel 4
//
#define UDMA_CH4_USB0EP3RX          0x00000004
#define UDMA_CH4_TIMER2A            0x00010004
#define UDMA_CH4_RESERVED2          0x00020004
#define UDMA_CH4_GPIOA              0x00030004
#define UDMA_CH4_RESERVED4          0x00040004

//
// Channel 5
//
#define UDMA_CH5_USB0EP3TX          0x00000005
#define UDMA_CH5_TIMER2B            0x00010005
#define UDMA_CH5_RESERVED2          0x00020005
#define UDMA_CH5_GPIOB              0x00030005
#define UDMA_CH5_RESERVED4          0x00040005

//
// Channel 6
//
#define UDMA_CH6_RESERVED0          0x00000006
#define UDMA_CH6_TIMER2A            0x00010006
#define UDMA_CH6_UART5RX            0x00020006
#define UDMA_CH6_GPIOC              0x00030006
#define UDMA_CH6_I2C0RX             0x00040006

//
// Channel 7
//
#define UDMA_CH7_RESERVED0          0x00000007
#define UDMA_CH7_TIMER2B            0x00010007
#define UDMA_CH7_UART5TX            0x00020007
#define UDMA_CH7_GPIOD              0x00030007
#define UDMA_CH7_I2C0TX             0x00040007

//
// Channel 8
//
#define UDMA_CH8_UART0RX            0x00000008
#define UDMA_CH8_UART1RX            0x00010008
#define UDMA_CH8_RESERVED2          0x00020008
#define UDMA_CH8_TIMER5A            0x00030008
#define UDMA_CH8_I2C1RX             0x00040008

//
// Channel 9
//
#define UDMA_CH9_UART0TX            0x00000009
#define UDMA_CH9_UART1TX            0x00010009
#define UDMA_CH9_RESERVED2          0x00020009
#define UDMA_CH9_TIMER5B            0x00030009
#define UDMA_CH9_I2C1TX             0x00040009

//
// Channel 10
//
#define UDMA_CH10_SSI0RX            0x0000000A
#define UDMA_CH10_SSI1RX            0x0001000A
#define UDMA_CH10_UART6RX           0x0002000A
#define UDMA_CH10_WTIMER0A          0x0003000A
#define UDMA_CH10_I2C2RX            0x0004000A

//
// Channel 11
//
#define UDMA_CH11_SSI0TX            0x0000000B
#define UDMA_CH11_SSI1TX            0x0001000B
#define UDMA_CH11_UART6TX           0x0002000B
#define UDMA_CH11_WTIMER0B          0x0003000B
#define UDMA_CH11_I2C2TX            0x0004000B

//
// Channel 12
//
#define UDMA_CH12_RESERVED0         0x0000000C
#define UDMA_CH12_UART2RX           0x0001000C
#define UDMA_CH12_SSI2RX            0x0002000C
#define UDMA_CH12_WTIMER1A          0x0003000C
#define UDMA_CH12_GPIOK             0x0004000C

//
// Channel 13
//
#define UDMA_CH13_RESERVED0         0x0000000D
#define UDMA_CH13_UART2TX           0x0001000D
#define UDMA_CH13_SSI2TX            0x0002000D
#define UDMA_CH13_WTIMER1B          0x0003000D
#define UDMA_CH13_GPIOL             0x0004000D

//
// Channel 14
//
#define UDMA_CH14_ADC0_0            0x0000000E
#define UDMA_CH14_TIMER2A           0x0001000E
#define UDMA_CH14_SSI3RX            0x0002000E
#define UDMA_CH14_GPIOE             0x0003000E
#define UDMA_CH14_GPIOM             0x0004000E

//
// Channel 15
//
#define UDMA_CH15_ADC0_1            0x0000000F
#define UDMA_CH15_TIMER2B           0x0001000F
#define UDMA_CH15_SSI3TX            0x0002000F
#define UDMA_CH15_GPIOF             0x0003000F
#define UDMA_CH15_GPION             0x0004000F

//
// Channel 16
//
#define UDMA_CH16_ADC0_2            0x00000010
#define UDMA_CH16_RESERVED1         0x00010010
#define UDMA_CH16_UART3RX           0x00020010
#define UDMA_CH16_WTIMER2A          0x00030010
#define UDMA_CH16_GPIOP             0x00040010

//
// Channel 17
//
#define UDMA_CH17_ADC0_3            0x00000011
#define UDMA_CH17_RESERVED1         0x00010011
#define UDMA_CH17_UART3TX           0x00020011
#define UDMA_CH17_WTIMER2B          0x00030011
#define UDMA_CH17_RESERVED4         0x00040011

//
// Channel 18
//
#define UDMA_CH18_TIMER0A           0x00000012
#define UDMA_CH18_TIMER1A           0x00010012
#define UDMA_CH18_UART4RX           0x00020012
#define UDMA_CH18_GPIOB             0x00030012
#define UDMA_CH18_I2C3RX            0x00040012

//
// Channel 19
//
#define UDMA_CH19_TIMER0B           0x00000013
#define UDMA_CH19_TIMER1B           0x00010013
#define UDMA_CH19_UART4TX           0x00020013
#define UDMA_CH19_GPIOG             0x00030013
#define UDMA_CH19_I2C3TX            0x00040013

//
// Channel 20
//
#define UDMA_CH20_TIMER1A           0x00000014
#define UDMA_CH20_RESERVED1         0x00010014
#define UDMA_CH20_UART7RX           0x00020014
#define UDMA_CH20_GPIOH             0x00030014
#define UDMA_CH20_I2C4RX            0x00040014

//
// Channel 21
//
#define UDMA_CH21_TIMER1B           0x00000015
#define UDMA_CH21_RESERVED1         0x00010015
#define UDMA_CH21_UART7TX           0x00020015
#define UDMA_CH21_GPIOJ             0x00030015
#define UDMA_CH21_I2C4TX            0x00040015

//
// Channel 22
//
#define UDMA_CH22_UART1RX           0x00000016
#define UDMA_CH22_RESERVED1         0x00010016
#define UDMA_CH22_RESERVED2         0x00020016
#define UDMA_CH22_LPC0_2            0x00030016
#define UDMA_CH22_I2C5RX            0x00040016

//
// Channel 23
//
#define UDMA_CH23_UART1TX           0x00000017
#define UDMA_CH23_RESERVED1         0x00010017
#define UDMA_CH23_RESERVED2         0x00020017
#define UDMA_CH23_LPC0_1            0x00030017
#define UDMA_CH23_I2C5TX            0x00040017

//
// Channel 24
//
#define UDMA_CH24_SSI1RX            0x00000018
#define UDMA_CH24_ADC1_0            0x00010018
#define UDMA_CH24_RESERVED2         0x00020018
#define UDMA_CH24_WTIMER3A          0x00030018
#define UDMA_CH24_GPIOQ             0x00040018

//
// Channel 25
//
#define UDMA_CH25_SSI1TX            0x00000019
#define UDMA_CH25_ADC1_1            0x00010019
#define UDMA_CH25_RESERVED2         0x00020019
#define UDMA_CH25_WTIMER3B          0x00030019
#define UDMA_CH25_RESERVED4         0x00040019

//
// Channel 26
//
#define UDMA_CH26_RESERVED0         0x0000001A
#define UDMA_CH26_ADC1_2            0x0001001A
#define UDMA_CH26_RESERVED2         0x0002001A
#define UDMA_CH26_WTIMER4A          0x0003001A
#define UDMA_CH26_RESERVED4         0x0004001A

//
// Channel 27
//
#define UDMA_CH27_RESERVED0         0x0000001B
#define UDMA_CH27_ADC1_3            0x0001001B
#define UDMA_CH27_RESERVED2         0x0002001B
#define UDMA_CH27_WTIMER4B          0x0003001B
#define UDMA_CH27_RESERVED4         0x0004001B

//
// Channel 28
//
#define UDMA_CH28_RESERVED0         0x0000001C
#define UDMA_CH28_RESERVED1         0x0001001C
#define UDMA_CH28_RESERVED2         0x0002001C
#define UDMA_CH28_WTIMER5A          0x0003001C
#define UDMA_CH28_RESERVED4         0x0004001C

//
// Channel 29
//
#define UDMA_CH29_RESERVED0         0x0000001D
#define UDMA_CH29_RESERVED1         0x0001001D
#define UDMA_CH29_RESERVED2         0x0002001D
#define UDMA_CH29_WTIMER5B          0x0003001D
#define UDMA_CH29_RESERVED4         0x0004001D

//
// Channel 30
//
#define UDMA_CH30_SW                0x0000001E
#define UDMA_CH30_RESERVED1         0x0001001E
#define UDMA_CH30_RESERVED2         0x0002001E
#define UDMA_CH30_RESERVED3         0x0003001E
#define UDMA_CH30_RESERVED4         0x0004001E

//
// Channel 31
//
#define UDMA_CH31_RESERVED0         0x0000001F
#define UDMA_CH31_RESERVED1         0x0001001F
#define UDMA_CH31_RESERVED2         0x0002001F
#define UDMA_CH31_LPC0_0            0x0003001F
#define UDMA_CH31_RESERVED4         0x0004001F

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void uDMAEnable(void);
extern void uDMADisable(void);
extern unsigned long uDMAErrorStatusGet(void);
extern void uDMAErrorStatusClear(void);
extern void uDMAChannelEnable(unsigned long ulChannelNum);
extern void uDMAChannelDisable(unsigned long ulChannelNum);
extern tBoolean uDMAChannelIsEnabled(unsigned long ulChannelNum);
extern void uDMAControlBaseSet(void *pControlTable);
extern void *uDMAControlBaseGet(void);
extern void *uDMAControlAlternateBaseGet(void);
extern void uDMAChannelRequest(unsigned long ulChannelNum);
extern void uDMAChannelAttributeEnable(unsigned long ulChannelNum,
                                       unsigned long ulAttr);
extern void uDMAChannelAttributeDisable(unsigned long ulChannelNum,
                                        unsigned long ulAttr);
extern unsigned long uDMAChannelAttributeGet(unsigned long ulChannelNum);
extern void uDMAChannelControlSet(unsigned long ulChannelStructIndex,
                                  unsigned long ulControl);
extern void uDMAChannelTransferSet(unsigned long ulChannelStructIndex,
                                   unsigned long ulMode, void *pvSrcAddr,
                                   void *pvDstAddr,
                                   unsigned long ulTransferSize);
extern void uDMAChannelScatterGatherSet(unsigned long ulChannelNum,
                                        unsigned ulTaskCount, void *pvTaskList,
                                        unsigned long ulIsPeriphSG);
extern unsigned long uDMAChannelSizeGet(unsigned long ulChannelStructIndex);
extern unsigned long uDMAChannelModeGet(unsigned long ulChannelStructIndex);
extern void uDMAIntRegister(unsigned long ulIntChannel,
                            void (*pfnHandler)(void));
extern void uDMAIntUnregister(unsigned long ulIntChannel);
extern void uDMAChannelSelectDefault(unsigned long ulDefPeriphs);
extern void uDMAChannelSelectSecondary(unsigned long ulSecPeriphs);
extern unsigned long uDMAIntStatus(void);
extern void uDMAIntClear(unsigned long ulChanMask);
extern void uDMAChannelAssign(unsigned long ulMapping);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __UDMA_H__
