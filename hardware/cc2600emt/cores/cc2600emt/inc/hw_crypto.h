/******************************************************************************
*  Filename:       hw_crypto_h
*  Revised:        2015-11-12 13:07:02 +0100 (Thu, 12 Nov 2015)
*  Revision:       45056
*
* Copyright (c) 2015, Texas Instruments Incorporated
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1) Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
* 2) Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3) Neither the name of the ORGANIZATION nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __HW_CRYPTO_H__
#define __HW_CRYPTO_H__

//*****************************************************************************
//
// This section defines the register offsets of
// CRYPTO component
//
//*****************************************************************************
// DMA Channel 0 Control
#define CRYPTO_O_DMACH0CTL                                          0x00000000

// DMA Channel 0 External Address
#define CRYPTO_O_DMACH0EXTADDR                                      0x00000004

// DMA Channel 0 Length
#define CRYPTO_O_DMACH0LEN                                          0x0000000C

// DMA Controller Status
#define CRYPTO_O_DMASTAT                                            0x00000018

// DMA Controller Software Reset
#define CRYPTO_O_DMASWRESET                                         0x0000001C

// DMA Channel 1 Control
#define CRYPTO_O_DMACH1CTL                                          0x00000020

// DMA Channel 1 External Address
#define CRYPTO_O_DMACH1EXTADDR                                      0x00000024

// DMA Channel 1 Length
#define CRYPTO_O_DMACH1LEN                                          0x0000002C

// DMA Controller Master Configuration
#define CRYPTO_O_DMABUSCFG                                          0x00000078

// DMA Controller Port Error
#define CRYPTO_O_DMAPORTERR                                         0x0000007C

// DMA Controller Version
#define CRYPTO_O_DMAHWVER                                           0x000000FC

// Key Write Area
#define CRYPTO_O_KEYWRITEAREA                                       0x00000400

// Key Written Area Status
#define CRYPTO_O_KEYWRITTENAREA                                     0x00000404

// Key Size
#define CRYPTO_O_KEYSIZE                                            0x00000408

// Key Read Area
#define CRYPTO_O_KEYREADAREA                                        0x0000040C

// Clear AES_KEY2/GHASH Key
#define CRYPTO_O_AESKEY20                                           0x00000500

// Clear AES_KEY2/GHASH Key
#define CRYPTO_O_AESKEY21                                           0x00000504

// Clear AES_KEY2/GHASH Key
#define CRYPTO_O_AESKEY22                                           0x00000508

// Clear AES_KEY2/GHASH Key
#define CRYPTO_O_AESKEY23                                           0x0000050C

// Clear AES_KEY3
#define CRYPTO_O_AESKEY30                                           0x00000510

// Clear AES_KEY3
#define CRYPTO_O_AESKEY31                                           0x00000514

// Clear AES_KEY3
#define CRYPTO_O_AESKEY32                                           0x00000518

// Clear AES_KEY3
#define CRYPTO_O_AESKEY33                                           0x0000051C

// AES Initialization Vector
#define CRYPTO_O_AESIV0                                             0x00000540

// AES Initialization Vector
#define CRYPTO_O_AESIV1                                             0x00000544

// AES Initialization Vector
#define CRYPTO_O_AESIV2                                             0x00000548

// AES Initialization Vector
#define CRYPTO_O_AESIV3                                             0x0000054C

// AES Input/Output Buffer Control
#define CRYPTO_O_AESCTL                                             0x00000550

// Crypto Data Length LSW
#define CRYPTO_O_AESDATALEN0                                        0x00000554

// Crypto Data Length MSW
#define CRYPTO_O_AESDATALEN1                                        0x00000558

// AES Authentication Length
#define CRYPTO_O_AESAUTHLEN                                         0x0000055C

// Data Input/Output
#define CRYPTO_O_AESDATAOUT0                                        0x00000560

// AES Data Input/Output 0
#define CRYPTO_O_AESDATAIN0                                         0x00000560

// AES Data Input/Output 3
#define CRYPTO_O_AESDATAOUT1                                        0x00000564

// AES Data Input/Output 1
#define CRYPTO_O_AESDATAIN1                                         0x00000564

// AES Data Input/Output 2
#define CRYPTO_O_AESDATAOUT2                                        0x00000568

// AES Data Input/Output 2
#define CRYPTO_O_AESDATAIN2                                         0x00000568

// AES Data Input/Output 3
#define CRYPTO_O_AESDATAOUT3                                        0x0000056C

// Data Input/Output
#define CRYPTO_O_AESDATAIN3                                         0x0000056C

// AES Tag Output
#define CRYPTO_O_AESTAGOUT0                                         0x00000570

// AES Tag Output
#define CRYPTO_O_AESTAGOUT1                                         0x00000574

// AES Tag Output
#define CRYPTO_O_AESTAGOUT2                                         0x00000578

// AES Tag Output
#define CRYPTO_O_AESTAGOUT3                                         0x0000057C

// Master Algorithm Select
#define CRYPTO_O_ALGSEL                                             0x00000700

// Master Protection Control
#define CRYPTO_O_DMAPROTCTL                                         0x00000704

// Software Reset
#define CRYPTO_O_SWRESET                                            0x00000740

// Interrupt Configuration
#define CRYPTO_O_IRQTYPE                                            0x00000780

// Interrupt Enable
#define CRYPTO_O_IRQEN                                              0x00000784

// Interrupt Clear
#define CRYPTO_O_IRQCLR                                             0x00000788

// Interrupt Set
#define CRYPTO_O_IRQSET                                             0x0000078C

// Interrupt Status
#define CRYPTO_O_IRQSTAT                                            0x00000790

// CTRL Module Version
#define CRYPTO_O_HWVER                                              0x000007FC

//*****************************************************************************
//
// Register: CRYPTO_O_DMACH0CTL
//
//*****************************************************************************
// Field:     [1] PRIO
//
// Channel priority:
//
// A channel with high priority will be served before a channel with low
// priority in cases with simultaneous access requests. If both channels have
// the same priority access of the channels to the external port is arbitrated
// using a Round Robin scheme.
// ENUMs:
// HIGH                     Priority high
// LOW                      Priority low
#define CRYPTO_DMACH0CTL_PRIO                                       0x00000002
#define CRYPTO_DMACH0CTL_PRIO_BITN                                           1
#define CRYPTO_DMACH0CTL_PRIO_M                                     0x00000002
#define CRYPTO_DMACH0CTL_PRIO_S                                              1
#define CRYPTO_DMACH0CTL_PRIO_HIGH                                  0x00000002
#define CRYPTO_DMACH0CTL_PRIO_LOW                                   0x00000000

// Field:     [0] EN
//
// DMA Channel 0 Control
// ENUMs:
// EN                       Channel enabled
// DIS                      Channel disabled
#define CRYPTO_DMACH0CTL_EN                                         0x00000001
#define CRYPTO_DMACH0CTL_EN_BITN                                             0
#define CRYPTO_DMACH0CTL_EN_M                                       0x00000001
#define CRYPTO_DMACH0CTL_EN_S                                                0
#define CRYPTO_DMACH0CTL_EN_EN                                      0x00000001
#define CRYPTO_DMACH0CTL_EN_DIS                                     0x00000000

//*****************************************************************************
//
// Register: CRYPTO_O_DMACH0EXTADDR
//
//*****************************************************************************
// Field:  [31:0] ADDR
//
// Channel external address value.
// Holds the last updated external address after being sent to the master
// interface.
#define CRYPTO_DMACH0EXTADDR_ADDR_W                                         32
#define CRYPTO_DMACH0EXTADDR_ADDR_M                                 0xFFFFFFFF
#define CRYPTO_DMACH0EXTADDR_ADDR_S                                          0

//*****************************************************************************
//
// Register: CRYPTO_O_DMACH0LEN
//
//*****************************************************************************
// Field:  [15:0] LEN
//
// DMA transfer length in bytes.
// During configuration, this register contains the DMA transfer length in
// bytes. During operation, it contains the last updated value of the DMA
// transfer length after being sent to the master interface.
// Note: Writing a non-zero value to this register field starts the transfer if
// the channel is enabled by setting DMACH0CTL.EN.
#define CRYPTO_DMACH0LEN_LEN_W                                              16
#define CRYPTO_DMACH0LEN_LEN_M                                      0x0000FFFF
#define CRYPTO_DMACH0LEN_LEN_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_DMASTAT
//
//*****************************************************************************
// Field:    [17] PORT_ERR
//
// Reflects possible transfer errors on the AHB port.
#define CRYPTO_DMASTAT_PORT_ERR                                     0x00020000
#define CRYPTO_DMASTAT_PORT_ERR_BITN                                        17
#define CRYPTO_DMASTAT_PORT_ERR_M                                   0x00020000
#define CRYPTO_DMASTAT_PORT_ERR_S                                           17

// Field:     [1] CH1_ACTIVE
//
// This register field indicates if DMA channel 1 is active or not.
// 0: Not active
// 1: Active
#define CRYPTO_DMASTAT_CH1_ACTIVE                                   0x00000002
#define CRYPTO_DMASTAT_CH1_ACTIVE_BITN                                       1
#define CRYPTO_DMASTAT_CH1_ACTIVE_M                                 0x00000002
#define CRYPTO_DMASTAT_CH1_ACTIVE_S                                          1

// Field:     [0] CH0_ACTIVE
//
// This register field indicates if DMA channel 0 is active or not.
// 0: Not active
// 1: Active
#define CRYPTO_DMASTAT_CH0_ACTIVE                                   0x00000001
#define CRYPTO_DMASTAT_CH0_ACTIVE_BITN                                       0
#define CRYPTO_DMASTAT_CH0_ACTIVE_M                                 0x00000001
#define CRYPTO_DMASTAT_CH0_ACTIVE_S                                          0

//*****************************************************************************
//
// Register: CRYPTO_O_DMASWRESET
//
//*****************************************************************************
// Field:     [0] RESET
//
// Software reset enable
//
// 0:  Disable
// 1:  Enable (self-cleared to zero).
//
// Note: Completion of the software reset must be checked in DMASTAT.CH0_ACTIVE
// and DMASTAT.CH1_ACTIVE.
#define CRYPTO_DMASWRESET_RESET                                     0x00000001
#define CRYPTO_DMASWRESET_RESET_BITN                                         0
#define CRYPTO_DMASWRESET_RESET_M                                   0x00000001
#define CRYPTO_DMASWRESET_RESET_S                                            0

//*****************************************************************************
//
// Register: CRYPTO_O_DMACH1CTL
//
//*****************************************************************************
// Field:     [1] PRIO
//
// Channel priority:
//
// A channel with high priority will be served before a channel with low
// priority in cases with simultaneous access requests. If both channels have
// the same priority access of the channels to the external port is arbitrated
// using a Round Robin scheme.
// ENUMs:
// HIGH                     Priority high
// LOW                      Priority low
#define CRYPTO_DMACH1CTL_PRIO                                       0x00000002
#define CRYPTO_DMACH1CTL_PRIO_BITN                                           1
#define CRYPTO_DMACH1CTL_PRIO_M                                     0x00000002
#define CRYPTO_DMACH1CTL_PRIO_S                                              1
#define CRYPTO_DMACH1CTL_PRIO_HIGH                                  0x00000002
#define CRYPTO_DMACH1CTL_PRIO_LOW                                   0x00000000

// Field:     [0] EN
//
// Channel enable:
//
// Note: Disabling an active channel will interrupt the DMA operation. The
// ongoing block transfer will be completed, but no new transfers will be
// requested.
// ENUMs:
// EN                       Channel enabled
// DIS                      Channel disabled
#define CRYPTO_DMACH1CTL_EN                                         0x00000001
#define CRYPTO_DMACH1CTL_EN_BITN                                             0
#define CRYPTO_DMACH1CTL_EN_M                                       0x00000001
#define CRYPTO_DMACH1CTL_EN_S                                                0
#define CRYPTO_DMACH1CTL_EN_EN                                      0x00000001
#define CRYPTO_DMACH1CTL_EN_DIS                                     0x00000000

//*****************************************************************************
//
// Register: CRYPTO_O_DMACH1EXTADDR
//
//*****************************************************************************
// Field:  [31:0] ADDR
//
// Channel external address value.
// Holds the last updated external address after being sent to the master
// interface.
#define CRYPTO_DMACH1EXTADDR_ADDR_W                                         32
#define CRYPTO_DMACH1EXTADDR_ADDR_M                                 0xFFFFFFFF
#define CRYPTO_DMACH1EXTADDR_ADDR_S                                          0

//*****************************************************************************
//
// Register: CRYPTO_O_DMACH1LEN
//
//*****************************************************************************
// Field:  [15:0] LEN
//
// DMA transfer length in bytes.
// During configuration, this register contains the DMA transfer length in
// bytes. During operation, it contains the last updated value of the DMA
// transfer length after being sent to the master interface.
// Note: Writing a non-zero value to this register field starts the transfer if
// the channel is enabled by setting DMACH1CTL.EN.
#define CRYPTO_DMACH1LEN_LEN_W                                              16
#define CRYPTO_DMACH1LEN_LEN_M                                      0x0000FFFF
#define CRYPTO_DMACH1LEN_LEN_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_DMABUSCFG
//
//*****************************************************************************
// Field: [15:12] AHB_MST1_BURST_SIZE
//
// Maximum burst size that can be performed on the AHB bus
// ENUMs:
// 64_BYTE                  64 bytes
// 32_BYTE                  32 bytes
// 16_BYTE                  16 bytes
// 8_BYTE                   8 bytes
// 4_BYTE                   4 bytes
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_W                               4
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_M                      0x0000F000
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_S                              12
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_64_BYTE                0x00006000
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_32_BYTE                0x00005000
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_16_BYTE                0x00004000
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_8_BYTE                 0x00003000
#define CRYPTO_DMABUSCFG_AHB_MST1_BURST_SIZE_4_BYTE                 0x00002000

// Field:    [11] AHB_MST1_IDLE_EN
//
// Idle transfer insertion between consecutive burst transfers on AHB
// ENUMs:
// IDLE                     Idle transfer insertion enabled
// NO_IDLE                  Do not insert idle transfers.
#define CRYPTO_DMABUSCFG_AHB_MST1_IDLE_EN                           0x00000800
#define CRYPTO_DMABUSCFG_AHB_MST1_IDLE_EN_BITN                              11
#define CRYPTO_DMABUSCFG_AHB_MST1_IDLE_EN_M                         0x00000800
#define CRYPTO_DMABUSCFG_AHB_MST1_IDLE_EN_S                                 11
#define CRYPTO_DMABUSCFG_AHB_MST1_IDLE_EN_IDLE                      0x00000800
#define CRYPTO_DMABUSCFG_AHB_MST1_IDLE_EN_NO_IDLE                   0x00000000

// Field:    [10] AHB_MST1_INCR_EN
//
// Burst length type of AHB transfer
// ENUMs:
// SPECIFIED                Fixed length bursts or single transfers
// UNSPECIFIED              Unspecified length burst transfers
#define CRYPTO_DMABUSCFG_AHB_MST1_INCR_EN                           0x00000400
#define CRYPTO_DMABUSCFG_AHB_MST1_INCR_EN_BITN                              10
#define CRYPTO_DMABUSCFG_AHB_MST1_INCR_EN_M                         0x00000400
#define CRYPTO_DMABUSCFG_AHB_MST1_INCR_EN_S                                 10
#define CRYPTO_DMABUSCFG_AHB_MST1_INCR_EN_SPECIFIED                 0x00000400
#define CRYPTO_DMABUSCFG_AHB_MST1_INCR_EN_UNSPECIFIED               0x00000000

// Field:     [9] AHB_MST1_LOCK_EN
//
// Locked transform on AHB
// ENUMs:
// LOCKED                   Transfers are locked
// NOT_LOCKED               Transfers are not locked
#define CRYPTO_DMABUSCFG_AHB_MST1_LOCK_EN                           0x00000200
#define CRYPTO_DMABUSCFG_AHB_MST1_LOCK_EN_BITN                               9
#define CRYPTO_DMABUSCFG_AHB_MST1_LOCK_EN_M                         0x00000200
#define CRYPTO_DMABUSCFG_AHB_MST1_LOCK_EN_S                                  9
#define CRYPTO_DMABUSCFG_AHB_MST1_LOCK_EN_LOCKED                    0x00000200
#define CRYPTO_DMABUSCFG_AHB_MST1_LOCK_EN_NOT_LOCKED                0x00000000

// Field:     [8] AHB_MST1_BIGEND
//
// Endianess for the AHB master
// ENUMs:
// BIG_ENDIAN               Big Endian
// LITTLE_ENDIAN            Little Endian
#define CRYPTO_DMABUSCFG_AHB_MST1_BIGEND                            0x00000100
#define CRYPTO_DMABUSCFG_AHB_MST1_BIGEND_BITN                                8
#define CRYPTO_DMABUSCFG_AHB_MST1_BIGEND_M                          0x00000100
#define CRYPTO_DMABUSCFG_AHB_MST1_BIGEND_S                                   8
#define CRYPTO_DMABUSCFG_AHB_MST1_BIGEND_BIG_ENDIAN                 0x00000100
#define CRYPTO_DMABUSCFG_AHB_MST1_BIGEND_LITTLE_ENDIAN              0x00000000

//*****************************************************************************
//
// Register: CRYPTO_O_DMAPORTERR
//
//*****************************************************************************
// Field:    [12] AHB_ERR
//
// A 1 indicates that the Crypto peripheral has detected an AHB bus error
#define CRYPTO_DMAPORTERR_AHB_ERR                                   0x00001000
#define CRYPTO_DMAPORTERR_AHB_ERR_BITN                                      12
#define CRYPTO_DMAPORTERR_AHB_ERR_M                                 0x00001000
#define CRYPTO_DMAPORTERR_AHB_ERR_S                                         12

// Field:     [9] LAST_CH
//
// Indicates which channel was serviced last (channel 0 or channel 1) by the
// AHB master port.
#define CRYPTO_DMAPORTERR_LAST_CH                                   0x00000200
#define CRYPTO_DMAPORTERR_LAST_CH_BITN                                       9
#define CRYPTO_DMAPORTERR_LAST_CH_M                                 0x00000200
#define CRYPTO_DMAPORTERR_LAST_CH_S                                          9

//*****************************************************************************
//
// Register: CRYPTO_O_DMAHWVER
//
//*****************************************************************************
// Field: [27:24] HW_MAJOR_VER
//
// Major version number
#define CRYPTO_DMAHWVER_HW_MAJOR_VER_W                                       4
#define CRYPTO_DMAHWVER_HW_MAJOR_VER_M                              0x0F000000
#define CRYPTO_DMAHWVER_HW_MAJOR_VER_S                                      24

// Field: [23:20] HW_MINOR_VER
//
// Minor version number
#define CRYPTO_DMAHWVER_HW_MINOR_VER_W                                       4
#define CRYPTO_DMAHWVER_HW_MINOR_VER_M                              0x00F00000
#define CRYPTO_DMAHWVER_HW_MINOR_VER_S                                      20

// Field: [19:16] HW_PATCH_LVL
//
// Patch level.
#define CRYPTO_DMAHWVER_HW_PATCH_LVL_W                                       4
#define CRYPTO_DMAHWVER_HW_PATCH_LVL_M                              0x000F0000
#define CRYPTO_DMAHWVER_HW_PATCH_LVL_S                                      16

// Field:  [15:8] VER_NUM_COMPL
//
// Bit-by-bit complement of the VER_NUM field bits.
#define CRYPTO_DMAHWVER_VER_NUM_COMPL_W                                      8
#define CRYPTO_DMAHWVER_VER_NUM_COMPL_M                             0x0000FF00
#define CRYPTO_DMAHWVER_VER_NUM_COMPL_S                                      8

// Field:   [7:0] VER_NUM
//
// Version number of the DMA Controller (209)
#define CRYPTO_DMAHWVER_VER_NUM_W                                            8
#define CRYPTO_DMAHWVER_VER_NUM_M                                   0x000000FF
#define CRYPTO_DMAHWVER_VER_NUM_S                                            0

//*****************************************************************************
//
// Register: CRYPTO_O_KEYWRITEAREA
//
//*****************************************************************************
// Field:     [7] RAM_AREA7
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA7                               0x00000080
#define CRYPTO_KEYWRITEAREA_RAM_AREA7_BITN                                   7
#define CRYPTO_KEYWRITEAREA_RAM_AREA7_M                             0x00000080
#define CRYPTO_KEYWRITEAREA_RAM_AREA7_S                                      7
#define CRYPTO_KEYWRITEAREA_RAM_AREA7_SEL                           0x00000080
#define CRYPTO_KEYWRITEAREA_RAM_AREA7_NOT_SEL                       0x00000000

// Field:     [6] RAM_AREA6
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA6                               0x00000040
#define CRYPTO_KEYWRITEAREA_RAM_AREA6_BITN                                   6
#define CRYPTO_KEYWRITEAREA_RAM_AREA6_M                             0x00000040
#define CRYPTO_KEYWRITEAREA_RAM_AREA6_S                                      6
#define CRYPTO_KEYWRITEAREA_RAM_AREA6_SEL                           0x00000040
#define CRYPTO_KEYWRITEAREA_RAM_AREA6_NOT_SEL                       0x00000000

// Field:     [5] RAM_AREA5
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA5                               0x00000020
#define CRYPTO_KEYWRITEAREA_RAM_AREA5_BITN                                   5
#define CRYPTO_KEYWRITEAREA_RAM_AREA5_M                             0x00000020
#define CRYPTO_KEYWRITEAREA_RAM_AREA5_S                                      5
#define CRYPTO_KEYWRITEAREA_RAM_AREA5_SEL                           0x00000020
#define CRYPTO_KEYWRITEAREA_RAM_AREA5_NOT_SEL                       0x00000000

// Field:     [4] RAM_AREA4
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA4                               0x00000010
#define CRYPTO_KEYWRITEAREA_RAM_AREA4_BITN                                   4
#define CRYPTO_KEYWRITEAREA_RAM_AREA4_M                             0x00000010
#define CRYPTO_KEYWRITEAREA_RAM_AREA4_S                                      4
#define CRYPTO_KEYWRITEAREA_RAM_AREA4_SEL                           0x00000010
#define CRYPTO_KEYWRITEAREA_RAM_AREA4_NOT_SEL                       0x00000000

// Field:     [3] RAM_AREA3
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA3                               0x00000008
#define CRYPTO_KEYWRITEAREA_RAM_AREA3_BITN                                   3
#define CRYPTO_KEYWRITEAREA_RAM_AREA3_M                             0x00000008
#define CRYPTO_KEYWRITEAREA_RAM_AREA3_S                                      3
#define CRYPTO_KEYWRITEAREA_RAM_AREA3_SEL                           0x00000008
#define CRYPTO_KEYWRITEAREA_RAM_AREA3_NOT_SEL                       0x00000000

// Field:     [2] RAM_AREA2
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA2                               0x00000004
#define CRYPTO_KEYWRITEAREA_RAM_AREA2_BITN                                   2
#define CRYPTO_KEYWRITEAREA_RAM_AREA2_M                             0x00000004
#define CRYPTO_KEYWRITEAREA_RAM_AREA2_S                                      2
#define CRYPTO_KEYWRITEAREA_RAM_AREA2_SEL                           0x00000004
#define CRYPTO_KEYWRITEAREA_RAM_AREA2_NOT_SEL                       0x00000000

// Field:     [1] RAM_AREA1
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA1                               0x00000002
#define CRYPTO_KEYWRITEAREA_RAM_AREA1_BITN                                   1
#define CRYPTO_KEYWRITEAREA_RAM_AREA1_M                             0x00000002
#define CRYPTO_KEYWRITEAREA_RAM_AREA1_S                                      1
#define CRYPTO_KEYWRITEAREA_RAM_AREA1_SEL                           0x00000002
#define CRYPTO_KEYWRITEAREA_RAM_AREA1_NOT_SEL                       0x00000000

// Field:     [0] RAM_AREA0
//
// Represents an area of 128 bits.
// Select the key store RAM area(s) where the key(s) needs to be written.
//
// Writing to multiple RAM locations is only possible when the selected RAM
// areas are sequential.
// ENUMs:
// SEL                      This RAM area is selected to be written
// NOT_SEL                  This RAM area is not selected to be written
#define CRYPTO_KEYWRITEAREA_RAM_AREA0                               0x00000001
#define CRYPTO_KEYWRITEAREA_RAM_AREA0_BITN                                   0
#define CRYPTO_KEYWRITEAREA_RAM_AREA0_M                             0x00000001
#define CRYPTO_KEYWRITEAREA_RAM_AREA0_S                                      0
#define CRYPTO_KEYWRITEAREA_RAM_AREA0_SEL                           0x00000001
#define CRYPTO_KEYWRITEAREA_RAM_AREA0_NOT_SEL                       0x00000000

//*****************************************************************************
//
// Register: CRYPTO_O_KEYWRITTENAREA
//
//*****************************************************************************
// Field:     [7] RAM_AREA_WRITTEN7
//
// On read this bit returns the key area written status.
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN7                     0x00000080
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN7_BITN                         7
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN7_M                   0x00000080
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN7_S                            7
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN7_WRITTEN             0x00000080
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN7_NOT_WRITTEN         0x00000000

// Field:     [6] RAM_AREA_WRITTEN6
//
// On read this bit returns the key area written status.
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN6                     0x00000040
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN6_BITN                         6
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN6_M                   0x00000040
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN6_S                            6
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN6_WRITTEN             0x00000040
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN6_NOT_WRITTEN         0x00000000

// Field:     [5] RAM_AREA_WRITTEN5
//
// On read this bit returns the key area written status.
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN5                     0x00000020
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN5_BITN                         5
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN5_M                   0x00000020
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN5_S                            5
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN5_WRITTEN             0x00000020
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN5_NOT_WRITTEN         0x00000000

// Field:     [4] RAM_AREA_WRITTEN4
//
// On read this bit returns the key area written status.
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN4                     0x00000010
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN4_BITN                         4
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN4_M                   0x00000010
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN4_S                            4
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN4_WRITTEN             0x00000010
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN4_NOT_WRITTEN         0x00000000

// Field:     [3] RAM_AREA_WRITTEN3
//
// On read this bit returns the key area written status.
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN3                     0x00000008
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN3_BITN                         3
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN3_M                   0x00000008
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN3_S                            3
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN3_WRITTEN             0x00000008
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN3_NOT_WRITTEN         0x00000000

// Field:     [2] RAM_AREA_WRITTEN2
//
// On read this bit returns the key area written status.
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN2                     0x00000004
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN2_BITN                         2
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN2_M                   0x00000004
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN2_S                            2
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN2_WRITTEN             0x00000004
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN2_NOT_WRITTEN         0x00000000

// Field:     [1] RAM_AREA_WRITTEN1
//
// On read this bit returns the key area written status.
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN1                     0x00000002
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN1_BITN                         1
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN1_M                   0x00000002
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN1_S                            1
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN1_WRITTEN             0x00000002
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN1_NOT_WRITTEN         0x00000000

// Field:     [0] RAM_AREA_WRITTEN0
//
// On read this bit returns the key area written status.
//
//
// This bit can be reset by writing a 1.
//
// Note: This register will be reset on a soft reset initiated by writing to
// DMASWRESET.RESET. After a soft reset, all keys must be rewritten to the key
// store memory.
// ENUMs:
// WRITTEN                  This RAM area is written with valid key
//                          information
// NOT_WRITTEN              This RAM area is not written with valid key
//                          information
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN0                     0x00000001
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN0_BITN                         0
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN0_M                   0x00000001
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN0_S                            0
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN0_WRITTEN             0x00000001
#define CRYPTO_KEYWRITTENAREA_RAM_AREA_WRITTEN0_NOT_WRITTEN         0x00000000

//*****************************************************************************
//
// Register: CRYPTO_O_KEYSIZE
//
//*****************************************************************************
// Field:   [1:0] SIZE
//
// Key size
//
// When writing to this register, KEYWRITTENAREA will be reset.
//
// Note: For the Crypto peripheral this field is fixed to 128 bits. For
// software compatibility KEYWRITTENAREA will  be reset when writing to this
// register.
// ENUMs:
// 256_BIT                  Not supported
// 192_BIT                  Not supported
// 128_BIT                  128 bits
#define CRYPTO_KEYSIZE_SIZE_W                                                2
#define CRYPTO_KEYSIZE_SIZE_M                                       0x00000003
#define CRYPTO_KEYSIZE_SIZE_S                                                0
#define CRYPTO_KEYSIZE_SIZE_256_BIT                                 0x00000003
#define CRYPTO_KEYSIZE_SIZE_192_BIT                                 0x00000002
#define CRYPTO_KEYSIZE_SIZE_128_BIT                                 0x00000001

//*****************************************************************************
//
// Register: CRYPTO_O_KEYREADAREA
//
//*****************************************************************************
// Field:    [31] BUSY
//
// Key store operation busy status flag (read only)
//
// 0: operation is completed.
// 1: operation is not completed and the key store is busy.
#define CRYPTO_KEYREADAREA_BUSY                                     0x80000000
#define CRYPTO_KEYREADAREA_BUSY_BITN                                        31
#define CRYPTO_KEYREADAREA_BUSY_M                                   0x80000000
#define CRYPTO_KEYREADAREA_BUSY_S                                           31

// Field:   [3:0] RAM_AREA
//
// Selects the area of the key store RAM from where the key needs to be read
// that will be written to the AES engine.
//
// Only RAM areas that contain valid written keys can be selected.
// ENUMs:
// NO_RAM                   No RAM
// RAM_AREA7                RAM Area 7
// RAM_AREA6                RAM Area 6
// RAM_AREA5                RAM Area 5
// RAM_AREA4                RAM Area 4
// RAM_AREA3                RAM Area 3
// RAM_AREA2                RAM Area 2
// RAM_AREA1                RAM Area 1
// RAM_AREA0                RAM Area 0
#define CRYPTO_KEYREADAREA_RAM_AREA_W                                        4
#define CRYPTO_KEYREADAREA_RAM_AREA_M                               0x0000000F
#define CRYPTO_KEYREADAREA_RAM_AREA_S                                        0
#define CRYPTO_KEYREADAREA_RAM_AREA_NO_RAM                          0x00000008
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA7                       0x00000007
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA6                       0x00000006
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA5                       0x00000005
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA4                       0x00000004
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA3                       0x00000003
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA2                       0x00000002
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA1                       0x00000001
#define CRYPTO_KEYREADAREA_RAM_AREA_RAM_AREA0                       0x00000000

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY20
//
//*****************************************************************************
// Field:  [31:0] KEY2
//
// AESKEY2.* bits 31+x:0+x or AES_GHASH_H.* bits 31+x:0+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register array.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY20_KEY2_W                                              32
#define CRYPTO_AESKEY20_KEY2_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY20_KEY2_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY21
//
//*****************************************************************************
// Field:  [31:0] KEY2
//
// AESKEY2.* bits 31+x:0+x or AES_GHASH_H.* bits 31+x:0+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register array.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY21_KEY2_W                                              32
#define CRYPTO_AESKEY21_KEY2_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY21_KEY2_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY22
//
//*****************************************************************************
// Field:  [31:0] KEY2
//
// AESKEY2.* bits 31+x:0+x or AES_GHASH_H.* bits 31+x:0+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register array.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY22_KEY2_W                                              32
#define CRYPTO_AESKEY22_KEY2_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY22_KEY2_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY23
//
//*****************************************************************************
// Field:  [31:0] KEY2
//
// AESKEY2.* bits 31+x:0+x or AES_GHASH_H.* bits 31+x:0+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register array.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY23_KEY2_W                                              32
#define CRYPTO_AESKEY23_KEY2_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY23_KEY2_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY30
//
//*****************************************************************************
// Field:  [31:0] KEY3
//
// AESKEY3.* bits 31+x:0+x or AESKEY2.* bits 159+x:128+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register arrary.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY30_KEY3_W                                              32
#define CRYPTO_AESKEY30_KEY3_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY30_KEY3_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY31
//
//*****************************************************************************
// Field:  [31:0] KEY3
//
// AESKEY3.* bits 31+x:0+x or AESKEY2.* bits 159+x:128+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register arrary.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY31_KEY3_W                                              32
#define CRYPTO_AESKEY31_KEY3_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY31_KEY3_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY32
//
//*****************************************************************************
// Field:  [31:0] KEY3
//
// AESKEY3.* bits 31+x:0+x or AESKEY2.* bits 159+x:128+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register arrary.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY32_KEY3_W                                              32
#define CRYPTO_AESKEY32_KEY3_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY32_KEY3_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESKEY33
//
//*****************************************************************************
// Field:  [31:0] KEY3
//
// AESKEY3.* bits 31+x:0+x or AESKEY2.* bits 159+x:128+x, where x = 0, 32, 64,
// 96 ordered from the LSW entry of this 4-deep register arrary.
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESKEY33_KEY3_W                                              32
#define CRYPTO_AESKEY33_KEY3_M                                      0xFFFFFFFF
#define CRYPTO_AESKEY33_KEY3_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_AESIV0
//
//*****************************************************************************
// Field:  [31:0] IV
//
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESIV0_IV_W                                                  32
#define CRYPTO_AESIV0_IV_M                                          0xFFFFFFFF
#define CRYPTO_AESIV0_IV_S                                                   0

//*****************************************************************************
//
// Register: CRYPTO_O_AESIV1
//
//*****************************************************************************
// Field:  [31:0] IV
//
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESIV1_IV_W                                                  32
#define CRYPTO_AESIV1_IV_M                                          0xFFFFFFFF
#define CRYPTO_AESIV1_IV_S                                                   0

//*****************************************************************************
//
// Register: CRYPTO_O_AESIV2
//
//*****************************************************************************
// Field:  [31:0] IV
//
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESIV2_IV_W                                                  32
#define CRYPTO_AESIV2_IV_M                                          0xFFFFFFFF
#define CRYPTO_AESIV2_IV_S                                                   0

//*****************************************************************************
//
// Register: CRYPTO_O_AESIV3
//
//*****************************************************************************
// Field:  [31:0] IV
//
// The interpretation of this field depends on the crypto operation mode.
#define CRYPTO_AESIV3_IV_W                                                  32
#define CRYPTO_AESIV3_IV_M                                          0xFFFFFFFF
#define CRYPTO_AESIV3_IV_S                                                   0

//*****************************************************************************
//
// Register: CRYPTO_O_AESCTL
//
//*****************************************************************************
// Field:    [31] CONTEXT_RDY
//
// If 1, this status bit indicates that the context data registers can be
// overwritten and the Host is permitted to write the next context.  Writing a
// context means writing either a mode, the crypto length or
// AESDATALEN1.LEN_MSW, AESDATALEN0.LEN_LSW length registers
#define CRYPTO_AESCTL_CONTEXT_RDY                                   0x80000000
#define CRYPTO_AESCTL_CONTEXT_RDY_BITN                                      31
#define CRYPTO_AESCTL_CONTEXT_RDY_M                                 0x80000000
#define CRYPTO_AESCTL_CONTEXT_RDY_S                                         31

// Field:    [30] SAVED_CONTEXT_RDY
//
// If read as 1, this status bit indicates that an AES authentication TAG
// and/or IV block(s) is/are available for the Host to retrieve. This bit is
// only asserted if SAVE_CONTEXT is set to 1. The bit is mutually exclusive
// with CONTEXT_RDY.
//
// Writing 1 clears the bit to zero, indicating the Crypto peripheral can start
// its next operation. This bit is also cleared when the 4th word of the output
// TAG and/or IV is read.
//
// Note: All other mode bit writes will be ignored when this mode bit is
// written with 1.
//
// Note: This bit is controlled automatically by the Crypto peripheral for TAG
// read DMA operations.
//
// For typical use, this bit does NOT need to be written, but is used for
// status reading only. In this case, this status bit is automatically
// maintained by the Crypto peripheral.
#define CRYPTO_AESCTL_SAVED_CONTEXT_RDY                             0x40000000
#define CRYPTO_AESCTL_SAVED_CONTEXT_RDY_BITN                                30
#define CRYPTO_AESCTL_SAVED_CONTEXT_RDY_M                           0x40000000
#define CRYPTO_AESCTL_SAVED_CONTEXT_RDY_S                                   30

// Field:    [29] SAVE_CONTEXT
//
// IV must be read before the AES engine can start a new operation.
#define CRYPTO_AESCTL_SAVE_CONTEXT                                  0x20000000
#define CRYPTO_AESCTL_SAVE_CONTEXT_BITN                                     29
#define CRYPTO_AESCTL_SAVE_CONTEXT_M                                0x20000000
#define CRYPTO_AESCTL_SAVE_CONTEXT_S                                        29

// Field: [24:22] CCM_M
//
// Defines M that indicates the length of the authentication field for CCM
// operations; the authentication field length equals two times the value of
// CCM_M plus one.
// Note: The Crypto peripheral always returns a 128-bit authentication field,
// of which the M least significant bytes are valid. All values are supported.
#define CRYPTO_AESCTL_CCM_M_W                                                3
#define CRYPTO_AESCTL_CCM_M_M                                       0x01C00000
#define CRYPTO_AESCTL_CCM_M_S                                               22

// Field: [21:19] CCM_L
//
// Defines L that indicates the width of the length field for CCM operations;
// the length field in bytes equals the value of CMM_L plus one. All values are
// supported.
#define CRYPTO_AESCTL_CCM_L_W                                                3
#define CRYPTO_AESCTL_CCM_L_M                                       0x00380000
#define CRYPTO_AESCTL_CCM_L_S                                               19

// Field:    [18] CCM
//
// AES-CCM mode enable.
// AES-CCM is a combined mode, using AES for both authentication and
// encryption.
// Note: Selecting AES-CCM mode requires writing of AESDATALEN1.LEN_MSW and
// AESDATALEN0.LEN_LSW  after all other registers.
// Note: The CTR mode bit in this register must also be set to 1 to enable
// AES-CTR; selecting other AES modes than CTR mode is invalid.
#define CRYPTO_AESCTL_CCM                                           0x00040000
#define CRYPTO_AESCTL_CCM_BITN                                              18
#define CRYPTO_AESCTL_CCM_M                                         0x00040000
#define CRYPTO_AESCTL_CCM_S                                                 18

// Field:    [15] CBC_MAC
//
// MAC mode enable.
// The DIR bit must be set to 1 for this mode.
// Selecting this mode requires writing the AESDATALEN1.LEN_MSW and
// AESDATALEN0.LEN_LSW registers after all other registers.
#define CRYPTO_AESCTL_CBC_MAC                                       0x00008000
#define CRYPTO_AESCTL_CBC_MAC_BITN                                          15
#define CRYPTO_AESCTL_CBC_MAC_M                                     0x00008000
#define CRYPTO_AESCTL_CBC_MAC_S                                             15

// Field:   [8:7] CTR_WIDTH
//
// Specifies the counter width for AES-CTR mode
// ENUMs:
// 128_BIT                  128 bits
// 96_BIT                   96 bits
// 64_BIT                   64 bits
// 32_BIT                   32 bits
#define CRYPTO_AESCTL_CTR_WIDTH_W                                            2
#define CRYPTO_AESCTL_CTR_WIDTH_M                                   0x00000180
#define CRYPTO_AESCTL_CTR_WIDTH_S                                            7
#define CRYPTO_AESCTL_CTR_WIDTH_128_BIT                             0x00000180
#define CRYPTO_AESCTL_CTR_WIDTH_96_BIT                              0x00000100
#define CRYPTO_AESCTL_CTR_WIDTH_64_BIT                              0x00000080
#define CRYPTO_AESCTL_CTR_WIDTH_32_BIT                              0x00000000

// Field:     [6] CTR
//
// AES-CTR mode enable
// This bit must also be set for CCM, when encryption/decryption is required.
#define CRYPTO_AESCTL_CTR                                           0x00000040
#define CRYPTO_AESCTL_CTR_BITN                                               6
#define CRYPTO_AESCTL_CTR_M                                         0x00000040
#define CRYPTO_AESCTL_CTR_S                                                  6

// Field:     [5] CBC
//
// CBC mode enable
#define CRYPTO_AESCTL_CBC                                           0x00000020
#define CRYPTO_AESCTL_CBC_BITN                                               5
#define CRYPTO_AESCTL_CBC_M                                         0x00000020
#define CRYPTO_AESCTL_CBC_S                                                  5

// Field:   [4:3] KEY_SIZE
//
// This field specifies the key size.
// The key size is automatically configured when a new key is loaded via the
// key store module.
// 00 = N/A - reserved
// 01 = 128 bits
// 10 = N/A - reserved
// 11 = N/A - reserved
// For the Crypto peripheral this field is fixed to 128 bits.
#define CRYPTO_AESCTL_KEY_SIZE_W                                             2
#define CRYPTO_AESCTL_KEY_SIZE_M                                    0x00000018
#define CRYPTO_AESCTL_KEY_SIZE_S                                             3

// Field:     [2] DIR
//
// Direction.
// 0 : Decrypt operation is performed.
// 1 : Encrypt operation is performed.
//
// This bit must be written with a 1 when CBC-MAC is selected.
#define CRYPTO_AESCTL_DIR                                           0x00000004
#define CRYPTO_AESCTL_DIR_BITN                                               2
#define CRYPTO_AESCTL_DIR_M                                         0x00000004
#define CRYPTO_AESCTL_DIR_S                                                  2

// Field:     [1] INPUT_RDY
//
// If read as 1, this status bit indicates that the 16-byte AES input buffer is
// empty. The Host is permitted to write the next block of data.
//
// Writing a 0 clears the bit to zero and indicates that the AES engine can use
// the provided input data block.
//
// Writing a 1 to this bit will be ignored.
//
// Note: For DMA operations, this bit is automatically controlled by the Crypto
// peripheral.
// After reset, this bit is 0. After writing a context (note 1), this bit will
// become 1.
//
// For typical use, this bit does NOT need to be written, but is used for
// status reading only. In this case, this status bit is automatically
// maintained by the Crypto peripheral.
#define CRYPTO_AESCTL_INPUT_RDY                                     0x00000002
#define CRYPTO_AESCTL_INPUT_RDY_BITN                                         1
#define CRYPTO_AESCTL_INPUT_RDY_M                                   0x00000002
#define CRYPTO_AESCTL_INPUT_RDY_S                                            1

// Field:     [0] OUTPUT_RDY
//
// If read as 1, this status bit indicates that an AES output block is
// available to be retrieved by the Host.
//
// Writing a 0 clears the bit to zero and indicates that output data is read by
// the Host. The AES engine can provide a next output data block.
//
// Writing a 1 to this bit will be ignored.
//
// Note: For DMA operations, this bit is automatically controlled by the Crypto
// peripheral.
//
// For typical use, this bit does NOT need to be written, but is used for
// status reading only. In this case, this status bit is automatically
// maintained by the Crypto peripheral.
#define CRYPTO_AESCTL_OUTPUT_RDY                                    0x00000001
#define CRYPTO_AESCTL_OUTPUT_RDY_BITN                                        0
#define CRYPTO_AESCTL_OUTPUT_RDY_M                                  0x00000001
#define CRYPTO_AESCTL_OUTPUT_RDY_S                                           0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATALEN0
//
//*****************************************************************************
// Field:  [31:0] LEN_LSW
//
// Used to write the Length values to the Crypto peripheral.
//
// This register contains bits [31:0] of the combined data length.
#define CRYPTO_AESDATALEN0_LEN_LSW_W                                        32
#define CRYPTO_AESDATALEN0_LEN_LSW_M                                0xFFFFFFFF
#define CRYPTO_AESDATALEN0_LEN_LSW_S                                         0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATALEN1
//
//*****************************************************************************
// Field:  [28:0] LEN_MSW
//
// Bits [60:32] of the combined data length.
//
// Bits [60:0] of the crypto length registers AESDATALEN1 and AESDATALEN0 store
// the cryptographic data length in bytes for all modes. Once processing with
// this context is started, this length decrements to zero. Data lengths up to
// (2^61 - 1) bytes are allowed.
// For GCM, any value up to 2^36 - 32 bytes can be used. This is because a
// 32-bit counter mode is used; the maximum number of 128-bit blocks is 2^32 -
// 2, resulting in a maximum number of bytes of 2^36 - 32.
// Writing to this register triggers the engine to start using this context.
// This is valid for all modes except GCM and CCM.
// Note: For the combined modes (GCM and CCM), this length does not include the
// authentication only data; the authentication length is specified in the
// AESAUTHLEN.LEN.
// All modes must have a length > 0. For the combined modes, it is allowed to
// have one of the lengths equal to zero.
// For the basic encryption modes (ECB/CBC/CTR) it is allowed to program zero
// to the length field; in that case the length is assumed infinite.
// All data must be byte (8-bit) aligned for stream cipher modes; bit aligned
// data streams are not supported by the Crypto peripheral. For block cipher
// modes, the data length must be programmed in multiples of the block cipher
// size, 16 bytes.
#define CRYPTO_AESDATALEN1_LEN_MSW_W                                        29
#define CRYPTO_AESDATALEN1_LEN_MSW_M                                0x1FFFFFFF
#define CRYPTO_AESDATALEN1_LEN_MSW_S                                         0

//*****************************************************************************
//
// Register: CRYPTO_O_AESAUTHLEN
//
//*****************************************************************************
// Field:  [31:0] LEN
//
// Authentication data length in bytes for combined mode, CCM only.
// Supported AAD-lengths for CCM are from 0 to (216 - 28) bytes. Once
// processing with this context is started, this length decrements to zero.
// Writing this register triggers the engine to start using this context for
// CCM.
#define CRYPTO_AESAUTHLEN_LEN_W                                             32
#define CRYPTO_AESAUTHLEN_LEN_M                                     0xFFFFFFFF
#define CRYPTO_AESAUTHLEN_LEN_S                                              0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAOUT0
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data register 0 for output block data from the Crypto peripheral.
// These bits = AES Output Data[31:0] of {127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host read operation, these registers contain the 128-bit output block
// from the latest AES operation. Reading from a word-aligned offset within
// this address range will read one word (4 bytes) of data out the 4-word deep
// (16 bytes = 128-bits AES block) data output buffer. The words (4 words, one
// full block) should be read before the core will move the next block to the
// data output buffer. To empty the data output buffer, AESCTL.OUTPUT_RDY must
// be written.
// For the modes with authentication (CBC-MAC, GCM and CCM), the invalid
// (message) bytes/words can be written with any data.
//
// Note: The AAD / authentication only data is not copied to the output buffer
// but only used for authentication.
#define CRYPTO_AESDATAOUT0_DATA_W                                           32
#define CRYPTO_AESDATAOUT0_DATA_M                                   0xFFFFFFFF
#define CRYPTO_AESDATAOUT0_DATA_S                                            0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAIN0
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data registers for input block data to the Crypto peripheral.
// These bits = AES Input Data[31:0]  of [127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host write operation, these registers must be written with the 128-bit
// input block for the next AES operation. Writing at a word-aligned offset
// within this address range will store the word (4 bytes) of data into the
// corresponding position of 4-word deep (16 bytes = 128-bit AES block) data
// input buffer. This buffer is used for the next AES operation. If the last
// data block is not completely filled with valid data (see notes below), it is
// allowed to write only the words with valid data. Next AES operation is
// triggered by writing to AESCTL.INPUT_RDY.
//
// Note: AES typically operates on 128 bits block multiple input data. The CTR,
// GCM and CCM modes form an exception. The last block of a CTR-mode message
// may contain less than 128 bits (refer to [NIST 800-38A]): 0 < n <= 128 bits.
// For GCM/CCM, the last block of both AAD and message data may contain less
// than 128 bits (refer to [NIST 800-38D]). The Crypto peripheral automatically
// pads or masks misaligned ending data blocks with zeroes for GCM, CCM and
// CBC-MAC. For CTR mode, the remaining data in an unaligned data block is
// ignored.
#define CRYPTO_AESDATAIN0_DATA_W                                            32
#define CRYPTO_AESDATAIN0_DATA_M                                    0xFFFFFFFF
#define CRYPTO_AESDATAIN0_DATA_S                                             0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAOUT1
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data registers for output block data from the Crypto peripheral.
// These bits = AES Output Data[63:32] of [127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host read operation, these registers contain the 128-bit output block
// from the latest AES operation. Reading from a word-aligned offset within
// this address range will read one word (4 bytes) of data out the 4-word deep
// (16 bytes = 128-bits AES block) data output buffer. The words (4 words, one
// full block) should be read before the core will move the next block to the
// data output buffer. To empty the data output buffer, AESCTL.OUTPUT_RDY must
// be written.
// For the modes with authentication (CBC-MAC, GCM and CCM), the invalid
// (message) bytes/words can be written with any data.
//
// Note: The AAD / authentication only data is not copied to the output buffer
// but only used for authentication.
#define CRYPTO_AESDATAOUT1_DATA_W                                           32
#define CRYPTO_AESDATAOUT1_DATA_M                                   0xFFFFFFFF
#define CRYPTO_AESDATAOUT1_DATA_S                                            0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAIN1
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data registers for input block data to the Crypto peripheral.
// These bits = AES Input Data[63:32]  of [127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host write operation, these registers must be written with the 128-bit
// input block for the next AES operation. Writing at a word-aligned offset
// within this address range will store the word (4 bytes) of data into the
// corresponding position of 4-word deep (16 bytes = 128-bit AES block) data
// input buffer. This buffer is used for the next AES operation. If the last
// data block is not completely filled with valid data (see notes below), it is
// allowed to write only the words with valid data. Next AES operation is
// triggered by writing to AESCTL.INPUT_RDY.
//
// Note: AES typically operates on 128 bits block multiple input data. The CTR,
// GCM and CCM modes form an exception. The last block of a CTR-mode message
// may contain less than 128 bits (refer to [NIST 800-38A]): 0 < n <= 128 bits.
// For GCM/CCM, the last block of both AAD and message data may contain less
// than 128 bits (refer to [NIST 800-38D]). The Crypto peripheral automatically
// pads or masks misaligned ending data blocks with zeroes for GCM, CCM and
// CBC-MAC. For CTR mode, the remaining data in an unaligned data block is
// ignored.
#define CRYPTO_AESDATAIN1_DATA_W                                            32
#define CRYPTO_AESDATAIN1_DATA_M                                    0xFFFFFFFF
#define CRYPTO_AESDATAIN1_DATA_S                                             0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAOUT2
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data registers for output block data from the Crypto peripheral.
// These bits = AES Output Data[95:64] of [127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host read operation, these registers contain the 128-bit output block
// from the latest AES operation. Reading from a word-aligned offset within
// this address range will read one word (4 bytes) of data out the 4-word deep
// (16 bytes = 128-bits AES block) data output buffer. The words (4 words, one
// full block) should be read before the core will move the next block to the
// data output buffer. To empty the data output buffer, AESCTL.OUTPUT_RDY must
// be written.
// For the modes with authentication (CBC-MAC, GCM and CCM), the invalid
// (message) bytes/words can be written with any data.
//
// Note: The AAD / authentication only data is not copied to the output buffer
// but only used for authentication.
#define CRYPTO_AESDATAOUT2_DATA_W                                           32
#define CRYPTO_AESDATAOUT2_DATA_M                                   0xFFFFFFFF
#define CRYPTO_AESDATAOUT2_DATA_S                                            0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAIN2
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data registers for input block data to the Crypto peripheral.
// These bits = AES Input Data[95:64]  of [127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host write operation, these registers must be written with the 128-bit
// input block for the next AES operation. Writing at a word-aligned offset
// within this address range will store the word (4 bytes) of data into the
// corresponding position of 4-word deep (16 bytes = 128-bit AES block) data
// input buffer. This buffer is used for the next AES operation. If the last
// data block is not completely filled with valid data (see notes below), it is
// allowed to write only the words with valid data. Next AES operation is
// triggered by writing to AESCTL.INPUT_RDY.
//
// Note: AES typically operates on 128 bits block multiple input data. The CTR,
// GCM and CCM modes form an exception. The last block of a CTR-mode message
// may contain less than 128 bits (refer to [NIST 800-38A]): 0 < n <= 128 bits.
// For GCM/CCM, the last block of both AAD and message data may contain less
// than 128 bits (refer to [NIST 800-38D]). The Crypto peripheral automatically
// pads or masks misaligned ending data blocks with zeroes for GCM, CCM and
// CBC-MAC. For CTR mode, the remaining data in an unaligned data block is
// ignored.
#define CRYPTO_AESDATAIN2_DATA_W                                            32
#define CRYPTO_AESDATAIN2_DATA_M                                    0xFFFFFFFF
#define CRYPTO_AESDATAIN2_DATA_S                                             0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAOUT3
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data registers for output block data from the Crypto peripheral.
// These bits = AES Output Data[127:96] of [127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host read operation, these registers contain the 128-bit output block
// from the latest AES operation. Reading from a word-aligned offset within
// this address range will read one word (4 bytes) of data out the 4-word deep
// (16 bytes = 128-bits AES block) data output buffer. The words (4 words, one
// full block) should be read before the core will move the next block to the
// data output buffer. To empty the data output buffer, AESCTL.OUTPUT_RDY must
// be written.
// For the modes with authentication (CBC-MAC, GCM and CCM), the invalid
// (message) bytes/words can be written with any data.
//
// Note: The AAD / authentication only data is not copied to the output buffer
// but only used for authentication.
#define CRYPTO_AESDATAOUT3_DATA_W                                           32
#define CRYPTO_AESDATAOUT3_DATA_M                                   0xFFFFFFFF
#define CRYPTO_AESDATAOUT3_DATA_S                                            0

//*****************************************************************************
//
// Register: CRYPTO_O_AESDATAIN3
//
//*****************************************************************************
// Field:  [31:0] DATA
//
// Data registers for input block data to the Crypto peripheral.
// These bits = AES Input Data[127:96] of [127:0]
//
// For normal operations, this register is not used, since data input and
// output is transferred from and to the AES engine via DMA.
//
// For a Host write operation, these registers must be written with the 128-bit
// input block for the next AES operation. Writing at a word-aligned offset
// within this address range will store the word (4 bytes) of data into the
// corresponding position of 4-word deep (16 bytes = 128-bit AES block) data
// input buffer. This buffer is used for the next AES operation. If the last
// data block is not completely filled with valid data (see notes below), it is
// allowed to write only the words with valid data. Next AES operation is
// triggered by writing to AESCTL.INPUT_RDY.
//
// Note: AES typically operates on 128 bits block multiple input data. The CTR,
// GCM and CCM modes form an exception. The last block of a CTR-mode message
// may contain less than 128 bits (refer to [NIST 800-38A]): 0 < n <= 128 bits.
// For GCM/CCM, the last block of both AAD and message data may contain less
// than 128 bits (refer to [NIST 800-38D]). The Crypto peripheral automatically
// pads or masks misaligned ending data blocks with zeroes for GCM, CCM and
// CBC-MAC. For CTR mode, the remaining data in an unaligned data block is
// ignored.
#define CRYPTO_AESDATAIN3_DATA_W                                            32
#define CRYPTO_AESDATAIN3_DATA_M                                    0xFFFFFFFF
#define CRYPTO_AESDATAIN3_DATA_S                                             0

//*****************************************************************************
//
// Register: CRYPTO_O_AESTAGOUT0
//
//*****************************************************************************
// Field:  [31:0] TAG
//
// This register contains the authentication TAG for the combined and
// authentication-only modes.
#define CRYPTO_AESTAGOUT0_TAG_W                                             32
#define CRYPTO_AESTAGOUT0_TAG_M                                     0xFFFFFFFF
#define CRYPTO_AESTAGOUT0_TAG_S                                              0

//*****************************************************************************
//
// Register: CRYPTO_O_AESTAGOUT1
//
//*****************************************************************************
// Field:  [31:0] TAG
//
// This register contains the authentication TAG for the combined and
// authentication-only modes.
#define CRYPTO_AESTAGOUT1_TAG_W                                             32
#define CRYPTO_AESTAGOUT1_TAG_M                                     0xFFFFFFFF
#define CRYPTO_AESTAGOUT1_TAG_S                                              0

//*****************************************************************************
//
// Register: CRYPTO_O_AESTAGOUT2
//
//*****************************************************************************
// Field:  [31:0] TAG
//
// This register contains the authentication TAG for the combined and
// authentication-only modes.
#define CRYPTO_AESTAGOUT2_TAG_W                                             32
#define CRYPTO_AESTAGOUT2_TAG_M                                     0xFFFFFFFF
#define CRYPTO_AESTAGOUT2_TAG_S                                              0

//*****************************************************************************
//
// Register: CRYPTO_O_AESTAGOUT3
//
//*****************************************************************************
// Field:  [31:0] TAG
//
// This register contains the authentication TAG for the combined and
// authentication-only modes.
#define CRYPTO_AESTAGOUT3_TAG_W                                             32
#define CRYPTO_AESTAGOUT3_TAG_M                                     0xFFFFFFFF
#define CRYPTO_AESTAGOUT3_TAG_S                                              0

//*****************************************************************************
//
// Register: CRYPTO_O_ALGSEL
//
//*****************************************************************************
// Field:    [31] TAG
//
// If this bit is cleared to 0, the DMA operation involves only data.
// If this bit is set, the DMA operation includes a TAG (Authentication Result
// / Digest).
#define CRYPTO_ALGSEL_TAG                                           0x80000000
#define CRYPTO_ALGSEL_TAG_BITN                                              31
#define CRYPTO_ALGSEL_TAG_M                                         0x80000000
#define CRYPTO_ALGSEL_TAG_S                                                 31

// Field:     [1] AES
//
// If set to 1,  the AES data is loaded via DMA
// Both Read and Write maximum transfer size to DMA engine is set to 16 bytes
#define CRYPTO_ALGSEL_AES                                           0x00000002
#define CRYPTO_ALGSEL_AES_BITN                                               1
#define CRYPTO_ALGSEL_AES_M                                         0x00000002
#define CRYPTO_ALGSEL_AES_S                                                  1

// Field:     [0] KEY_STORE
//
// If set to 1, selects the Key Store to be loaded via DMA.
// The maximum transfer size to DMA engine is set to 32 bytes (however
// transfers of 16, 24 and 32 bytes are allowed)
#define CRYPTO_ALGSEL_KEY_STORE                                     0x00000001
#define CRYPTO_ALGSEL_KEY_STORE_BITN                                         0
#define CRYPTO_ALGSEL_KEY_STORE_M                                   0x00000001
#define CRYPTO_ALGSEL_KEY_STORE_S                                            0

//*****************************************************************************
//
// Register: CRYPTO_O_DMAPROTCTL
//
//*****************************************************************************
// Field:     [0] EN
//
// Select AHB transfer protection control for DMA transfers using the key store
// area as destination.
// 0 : transfers use 'USER' type access.
// 1 : transfers use 'PRIVILEGED' type access.
#define CRYPTO_DMAPROTCTL_EN                                        0x00000001
#define CRYPTO_DMAPROTCTL_EN_BITN                                            0
#define CRYPTO_DMAPROTCTL_EN_M                                      0x00000001
#define CRYPTO_DMAPROTCTL_EN_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_SWRESET
//
//*****************************************************************************
// Field:     [0] RESET
//
// If this bit is set to 1, the following modules are reset:
// - Master control internal state is reset. That includes interrupt, error
// status register and result available interrupt generation FSM.
// - Key store module state is reset. That includes clearing the Written Area
// flags; therefore the keys must be reloaded to the key store module.
// Writing 0 has no effect.
// The bit is self cleared after executing the reset.
#define CRYPTO_SWRESET_RESET                                        0x00000001
#define CRYPTO_SWRESET_RESET_BITN                                            0
#define CRYPTO_SWRESET_RESET_M                                      0x00000001
#define CRYPTO_SWRESET_RESET_S                                               0

//*****************************************************************************
//
// Register: CRYPTO_O_IRQTYPE
//
//*****************************************************************************
// Field:     [0] IEN
//
// Interrupt enable. This bit must be set to 1 to enable interrupts from the
// Crypto peripheral.
// 0 : All interrupts are disabled enabled.
// 1 : All interrupts are enabled.
#define CRYPTO_IRQTYPE_IEN                                          0x00000001
#define CRYPTO_IRQTYPE_IEN_BITN                                              0
#define CRYPTO_IRQTYPE_IEN_M                                        0x00000001
#define CRYPTO_IRQTYPE_IEN_S                                                 0

//*****************************************************************************
//
// Register: CRYPTO_O_IRQEN
//
//*****************************************************************************
// Field:     [1] DMA_IN_DONE
//
// This bit enables IRQSTAT.DMA_IN_DONE as source for IRQ.
#define CRYPTO_IRQEN_DMA_IN_DONE                                    0x00000002
#define CRYPTO_IRQEN_DMA_IN_DONE_BITN                                        1
#define CRYPTO_IRQEN_DMA_IN_DONE_M                                  0x00000002
#define CRYPTO_IRQEN_DMA_IN_DONE_S                                           1

// Field:     [0] RESULT_AVAIL
//
// This bit enables IRQSTAT.RESULT_AVAIL as source for IRQ.
#define CRYPTO_IRQEN_RESULT_AVAIL                                   0x00000001
#define CRYPTO_IRQEN_RESULT_AVAIL_BITN                                       0
#define CRYPTO_IRQEN_RESULT_AVAIL_M                                 0x00000001
#define CRYPTO_IRQEN_RESULT_AVAIL_S                                          0

//*****************************************************************************
//
// Register: CRYPTO_O_IRQCLR
//
//*****************************************************************************
// Field:    [31] DMA_BUS_ERR
//
// If 1 is written to this bit, IRQSTAT.DMA_BUS_ERR is cleared.
#define CRYPTO_IRQCLR_DMA_BUS_ERR                                   0x80000000
#define CRYPTO_IRQCLR_DMA_BUS_ERR_BITN                                      31
#define CRYPTO_IRQCLR_DMA_BUS_ERR_M                                 0x80000000
#define CRYPTO_IRQCLR_DMA_BUS_ERR_S                                         31

// Field:    [30] KEY_ST_WR_ERR
//
// If 1 is written to this bit, IRQSTAT.KEY_ST_WR_ERR is cleared.
#define CRYPTO_IRQCLR_KEY_ST_WR_ERR                                 0x40000000
#define CRYPTO_IRQCLR_KEY_ST_WR_ERR_BITN                                    30
#define CRYPTO_IRQCLR_KEY_ST_WR_ERR_M                               0x40000000
#define CRYPTO_IRQCLR_KEY_ST_WR_ERR_S                                       30

// Field:    [29] KEY_ST_RD_ERR
//
// If 1 is written to this bit, IRQSTAT.KEY_ST_RD_ERR is cleared.
#define CRYPTO_IRQCLR_KEY_ST_RD_ERR                                 0x20000000
#define CRYPTO_IRQCLR_KEY_ST_RD_ERR_BITN                                    29
#define CRYPTO_IRQCLR_KEY_ST_RD_ERR_M                               0x20000000
#define CRYPTO_IRQCLR_KEY_ST_RD_ERR_S                                       29

// Field:     [1] DMA_IN_DONE
//
// If 1 is written to this bit, IRQSTAT.DMA_IN_DONE is cleared.
#define CRYPTO_IRQCLR_DMA_IN_DONE                                   0x00000002
#define CRYPTO_IRQCLR_DMA_IN_DONE_BITN                                       1
#define CRYPTO_IRQCLR_DMA_IN_DONE_M                                 0x00000002
#define CRYPTO_IRQCLR_DMA_IN_DONE_S                                          1

// Field:     [0] RESULT_AVAIL
//
// If 1 is written to this bit, IRQSTAT.RESULT_AVAIL is cleared.
#define CRYPTO_IRQCLR_RESULT_AVAIL                                  0x00000001
#define CRYPTO_IRQCLR_RESULT_AVAIL_BITN                                      0
#define CRYPTO_IRQCLR_RESULT_AVAIL_M                                0x00000001
#define CRYPTO_IRQCLR_RESULT_AVAIL_S                                         0

//*****************************************************************************
//
// Register: CRYPTO_O_IRQSET
//
//*****************************************************************************
// Field:     [1] DMA_IN_DONE
//
// If 1 is written to this bit, IRQSTAT.DMA_IN_DONE is set.
// Writing 0 has no effect.
#define CRYPTO_IRQSET_DMA_IN_DONE                                   0x00000002
#define CRYPTO_IRQSET_DMA_IN_DONE_BITN                                       1
#define CRYPTO_IRQSET_DMA_IN_DONE_M                                 0x00000002
#define CRYPTO_IRQSET_DMA_IN_DONE_S                                          1

// Field:     [0] RESULT_AVAIL
//
// If 1 is written to this bit, IRQSTAT.RESULT_AVAIL is set.
// Writing 0 has no effect.
#define CRYPTO_IRQSET_RESULT_AVAIL                                  0x00000001
#define CRYPTO_IRQSET_RESULT_AVAIL_BITN                                      0
#define CRYPTO_IRQSET_RESULT_AVAIL_M                                0x00000001
#define CRYPTO_IRQSET_RESULT_AVAIL_S                                         0

//*****************************************************************************
//
// Register: CRYPTO_O_IRQSTAT
//
//*****************************************************************************
// Field:    [31] DMA_BUS_ERR
//
// This bit is set when a DMA bus error is detected during a DMA operation. The
// value of this register is held until it is cleared via IRQCLR.DMA_BUS_ERR
// Note: This error is asserted if an error is detected on the AHB master
// interface during a DMA operation.
// Note: This is not an interrupt source.
#define CRYPTO_IRQSTAT_DMA_BUS_ERR                                  0x80000000
#define CRYPTO_IRQSTAT_DMA_BUS_ERR_BITN                                     31
#define CRYPTO_IRQSTAT_DMA_BUS_ERR_M                                0x80000000
#define CRYPTO_IRQSTAT_DMA_BUS_ERR_S                                        31

// Field:    [30] KEY_ST_WR_ERR
//
// This bit is set when a write error is detected during the DMA write
// operation to the key store memory. The value of this register is held until
// it is cleared via IRQCLR.KEY_ST_WR_ERR
// Note: This error is asserted if a DMA operation does not cover a full key
// area or more areas are written than expected.
// Note: This is not an interrupt source.
#define CRYPTO_IRQSTAT_KEY_ST_WR_ERR                                0x40000000
#define CRYPTO_IRQSTAT_KEY_ST_WR_ERR_BITN                                   30
#define CRYPTO_IRQSTAT_KEY_ST_WR_ERR_M                              0x40000000
#define CRYPTO_IRQSTAT_KEY_ST_WR_ERR_S                                      30

// Field:    [29] KEY_ST_RD_ERR
//
// This bit will be set when a read error is detected during the read of a key
// from the key store, while copying it to the AES engine. The value of this
// register is held until it is cleared via IRQCLR.KEY_ST_RD_ERR.
// Note: This error is asserted if a key location is selected in the key store
// that is not available.
// Note: This is not an interrupt source.
#define CRYPTO_IRQSTAT_KEY_ST_RD_ERR                                0x20000000
#define CRYPTO_IRQSTAT_KEY_ST_RD_ERR_BITN                                   29
#define CRYPTO_IRQSTAT_KEY_ST_RD_ERR_M                              0x20000000
#define CRYPTO_IRQSTAT_KEY_ST_RD_ERR_S                                      29

// Field:     [1] DMA_IN_DONE
//
// This bit returns the status of DMA data in done interrupt.
#define CRYPTO_IRQSTAT_DMA_IN_DONE                                  0x00000002
#define CRYPTO_IRQSTAT_DMA_IN_DONE_BITN                                      1
#define CRYPTO_IRQSTAT_DMA_IN_DONE_M                                0x00000002
#define CRYPTO_IRQSTAT_DMA_IN_DONE_S                                         1

// Field:     [0] RESULT_AVAIL
//
// This bit is set high when the Crypto peripheral has a result available.
#define CRYPTO_IRQSTAT_RESULT_AVAIL                                 0x00000001
#define CRYPTO_IRQSTAT_RESULT_AVAIL_BITN                                     0
#define CRYPTO_IRQSTAT_RESULT_AVAIL_M                               0x00000001
#define CRYPTO_IRQSTAT_RESULT_AVAIL_S                                        0

//*****************************************************************************
//
// Register: CRYPTO_O_HWVER
//
//*****************************************************************************
// Field: [27:24] HW_MAJOR_VER
//
// Major version number
#define CRYPTO_HWVER_HW_MAJOR_VER_W                                          4
#define CRYPTO_HWVER_HW_MAJOR_VER_M                                 0x0F000000
#define CRYPTO_HWVER_HW_MAJOR_VER_S                                         24

// Field: [23:20] HW_MINOR_VER
//
// Minor version number
#define CRYPTO_HWVER_HW_MINOR_VER_W                                          4
#define CRYPTO_HWVER_HW_MINOR_VER_M                                 0x00F00000
#define CRYPTO_HWVER_HW_MINOR_VER_S                                         20

// Field: [19:16] HW_PATCH_LVL
//
// Patch level, starts at 0 at first delivery of this version.
#define CRYPTO_HWVER_HW_PATCH_LVL_W                                          4
#define CRYPTO_HWVER_HW_PATCH_LVL_M                                 0x000F0000
#define CRYPTO_HWVER_HW_PATCH_LVL_S                                         16

// Field:  [15:8] VER_NUM_COMPL
//
// These bits simply contain the complement of VER_NUM (0x87), used by a driver
// to ascertain that the Crypto peripheral register is indeed read.
#define CRYPTO_HWVER_VER_NUM_COMPL_W                                         8
#define CRYPTO_HWVER_VER_NUM_COMPL_M                                0x0000FF00
#define CRYPTO_HWVER_VER_NUM_COMPL_S                                         8

// Field:   [7:0] VER_NUM
//
// The version number for the Crypto peripheral, this field contains the value
// 120 (decimal) or 0x78.
#define CRYPTO_HWVER_VER_NUM_W                                               8
#define CRYPTO_HWVER_VER_NUM_M                                      0x000000FF
#define CRYPTO_HWVER_VER_NUM_S                                               0


#endif // __CRYPTO__
