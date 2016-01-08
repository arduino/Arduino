/******************************************************************************
*  Filename:       hw_prcm_h
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

#ifndef __HW_PRCM_H__
#define __HW_PRCM_H__

//*****************************************************************************
//
// This section defines the register offsets of
// PRCM component
//
//*****************************************************************************
// Infrastructure Clock Division Factor For Run Mode
#define PRCM_O_INFRCLKDIVR                                          0x00000000

// Infrastructure Clock Division Factor For Sleep Mode
#define PRCM_O_INFRCLKDIVS                                          0x00000004

// Infrastructure Clock Division Factor For DeepSleep Mode
#define PRCM_O_INFRCLKDIVDS                                         0x00000008

// MCU Voltage Domain Control
#define PRCM_O_VDCTL                                                0x0000000C

// Clock Load Control
#define PRCM_O_CLKLOADCTL                                           0x00000028

// RFC Clock Gate
#define PRCM_O_RFCCLKG                                              0x0000002C

// VIMS Clock Gate
#define PRCM_O_VIMSCLKG                                             0x00000030

// TRNG, CRYPTO And UDMA Clock Gate For Run Mode
#define PRCM_O_SECDMACLKGR                                          0x0000003C

// TRNG, CRYPTO And UDMA Clock Gate For Sleep Mode
#define PRCM_O_SECDMACLKGS                                          0x00000040

// TRNG, CRYPTO And UDMA Clock Gate For Deep Sleep Mode
#define PRCM_O_SECDMACLKGDS                                         0x00000044

// GPIO Clock Gate For Run Mode
#define PRCM_O_GPIOCLKGR                                            0x00000048

// GPIO Clock Gate For Sleep Mode
#define PRCM_O_GPIOCLKGS                                            0x0000004C

// GPIO Clock Gate For Deep Sleep Mode
#define PRCM_O_GPIOCLKGDS                                           0x00000050

// GPT Clock Gate For Run Mode
#define PRCM_O_GPTCLKGR                                             0x00000054

// GPT Clock Gate For Sleep Mode
#define PRCM_O_GPTCLKGS                                             0x00000058

// GPT Clock Gate For Deep Sleep Mode
#define PRCM_O_GPTCLKGDS                                            0x0000005C

// I2C Clock Gate For Run Mode
#define PRCM_O_I2CCLKGR                                             0x00000060

// I2C Clock Gate For Sleep Mode
#define PRCM_O_I2CCLKGS                                             0x00000064

// I2C Clock Gate For Deep Sleep Mode
#define PRCM_O_I2CCLKGDS                                            0x00000068

// UART Clock Gate For Run Mode
#define PRCM_O_UARTCLKGR                                            0x0000006C

// UART Clock Gate For Sleep Mode
#define PRCM_O_UARTCLKGS                                            0x00000070

// UART Clock Gate For Deep Sleep Mode
#define PRCM_O_UARTCLKGDS                                           0x00000074

// SSI Clock Gate For Run Mode
#define PRCM_O_SSICLKGR                                             0x00000078

// SSI Clock Gate For Sleep Mode
#define PRCM_O_SSICLKGS                                             0x0000007C

// SSI Clock Gate For Deep Sleep Mode
#define PRCM_O_SSICLKGDS                                            0x00000080

// I2S Clock Gate For Run Mode
#define PRCM_O_I2SCLKGR                                             0x00000084

// I2S Clock Gate For Sleep Mode
#define PRCM_O_I2SCLKGS                                             0x00000088

// I2S Clock Gate For Deep Sleep Mode
#define PRCM_O_I2SCLKGDS                                            0x0000008C

// Internal
#define PRCM_O_CPUCLKDIV                                            0x000000B8

// I2S Clock Control
#define PRCM_O_I2SBCLKSEL                                           0x000000C8

// GPT Scalar
#define PRCM_O_GPTCLKDIV                                            0x000000CC

// I2S Clock Control
#define PRCM_O_I2SCLKCTL                                            0x000000D0

// MCLK Division Ratio
#define PRCM_O_I2SMCLKDIV                                           0x000000D4

// BCLK Division Ratio
#define PRCM_O_I2SBCLKDIV                                           0x000000D8

// WCLK Division Ratio
#define PRCM_O_I2SWCLKDIV                                           0x000000DC

// SW Initiated Resets
#define PRCM_O_SWRESET                                              0x0000010C

// WARM Reset Control And Status
#define PRCM_O_WARMRESET                                            0x00000110

// Power Domain Control
#define PRCM_O_PDCTL0                                               0x0000012C

// RFC Power Domain Control
#define PRCM_O_PDCTL0RFC                                            0x00000130

// SERIAL Power Domain Control
#define PRCM_O_PDCTL0SERIAL                                         0x00000134

// PERIPH Power Domain Control
#define PRCM_O_PDCTL0PERIPH                                         0x00000138

// Power Domain Status
#define PRCM_O_PDSTAT0                                              0x00000140

// RFC Power Domain Status
#define PRCM_O_PDSTAT0RFC                                           0x00000144

// SERIAL Power Domain Status
#define PRCM_O_PDSTAT0SERIAL                                        0x00000148

// PERIPH Power Domain Status
#define PRCM_O_PDSTAT0PERIPH                                        0x0000014C

// Power Domain Control
#define PRCM_O_PDCTL1                                               0x0000017C

// CPU Power Domain Control
#define PRCM_O_PDCTL1CPU                                            0x00000184

// RFC Power Domain Control
#define PRCM_O_PDCTL1RFC                                            0x00000188

// VIMS Power Domain Control
#define PRCM_O_PDCTL1VIMS                                           0x0000018C

// Power Domain Status
#define PRCM_O_PDSTAT1                                              0x00000194

// BUS Power Domain Status
#define PRCM_O_PDSTAT1BUS                                           0x00000198

// RFC Power Domain Status
#define PRCM_O_PDSTAT1RFC                                           0x0000019C

// CPU Power Domain Status
#define PRCM_O_PDSTAT1CPU                                           0x000001A0

// VIMS Power Domain Status
#define PRCM_O_PDSTAT1VIMS                                          0x000001A4

// Selected RFC Mode
#define PRCM_O_RFCMODESEL                                           0x000001D0

// Memory Retention Control
#define PRCM_O_RAMRETEN                                             0x00000224

//*****************************************************************************
//
// Register: PRCM_O_INFRCLKDIVR
//
//*****************************************************************************
// Field:   [1:0] RATIO
//
// Division rate for clocks driving modules in the MCU_AON domain when system
// CPU is in run mode. Division ratio affects both infrastructure clock and
// perbusull clock.
// ENUMs:
// DIV32                    Divide by 32
// DIV8                     Divide by 8
// DIV2                     Divide by 2
// DIV1                     Divide by 1
#define PRCM_INFRCLKDIVR_RATIO_W                                             2
#define PRCM_INFRCLKDIVR_RATIO_M                                    0x00000003
#define PRCM_INFRCLKDIVR_RATIO_S                                             0
#define PRCM_INFRCLKDIVR_RATIO_DIV32                                0x00000003
#define PRCM_INFRCLKDIVR_RATIO_DIV8                                 0x00000002
#define PRCM_INFRCLKDIVR_RATIO_DIV2                                 0x00000001
#define PRCM_INFRCLKDIVR_RATIO_DIV1                                 0x00000000

//*****************************************************************************
//
// Register: PRCM_O_INFRCLKDIVS
//
//*****************************************************************************
// Field:   [1:0] RATIO
//
// Division rate for clocks driving modules in the MCU_AON domain when system
// CPU is in sleep mode. Division ratio affects both infrastructure clock and
// perbusull clock.
// ENUMs:
// DIV32                    Divide by 32
// DIV8                     Divide by 8
// DIV2                     Divide by 2
// DIV1                     Divide by 1
#define PRCM_INFRCLKDIVS_RATIO_W                                             2
#define PRCM_INFRCLKDIVS_RATIO_M                                    0x00000003
#define PRCM_INFRCLKDIVS_RATIO_S                                             0
#define PRCM_INFRCLKDIVS_RATIO_DIV32                                0x00000003
#define PRCM_INFRCLKDIVS_RATIO_DIV8                                 0x00000002
#define PRCM_INFRCLKDIVS_RATIO_DIV2                                 0x00000001
#define PRCM_INFRCLKDIVS_RATIO_DIV1                                 0x00000000

//*****************************************************************************
//
// Register: PRCM_O_INFRCLKDIVDS
//
//*****************************************************************************
// Field:   [1:0] RATIO
//
// Division rate for clocks driving modules in the MCU_AON domain when system
// CPU is in seepsleep mode. Division ratio affects both infrastructure clock
// and perbusull clock.
// ENUMs:
// DIV32                    Divide by 32
// DIV8                     Divide by 8
// DIV2                     Divide by 2
// DIV1                     Divide by 1
#define PRCM_INFRCLKDIVDS_RATIO_W                                            2
#define PRCM_INFRCLKDIVDS_RATIO_M                                   0x00000003
#define PRCM_INFRCLKDIVDS_RATIO_S                                            0
#define PRCM_INFRCLKDIVDS_RATIO_DIV32                               0x00000003
#define PRCM_INFRCLKDIVDS_RATIO_DIV8                                0x00000002
#define PRCM_INFRCLKDIVDS_RATIO_DIV2                                0x00000001
#define PRCM_INFRCLKDIVDS_RATIO_DIV1                                0x00000000

//*****************************************************************************
//
// Register: PRCM_O_VDCTL
//
//*****************************************************************************
// Field:     [2] MCU_VD
//
// Request WUC to power down the MCU voltage domain
//
// 0: No request
// 1: Assert request when possible. An asserted power down request will result
// in a boot of the MCU system when powered up again.
//
// The bit will have no effect before the following requirements are met:
// 1. PDCTL1.CPU_ON = 0
// 2. PDCTL1.VIMS_MODE = 0
// 3. SECDMACLKGDS.DMA_CLK_EN = 0 (Note: Setting must be loaded with
// CLKLOADCTL.LOAD)
// 4. SECDMACLKGDS.CRYPTO_CLK_EN = 0 (Note: Setting must be loaded with
// CLKLOADCTL.LOAD)
// 5. RFC do no request access to BUS
// 6. System CPU in deepsleep
#define PRCM_VDCTL_MCU_VD                                           0x00000004
#define PRCM_VDCTL_MCU_VD_BITN                                               2
#define PRCM_VDCTL_MCU_VD_M                                         0x00000004
#define PRCM_VDCTL_MCU_VD_S                                                  2

// Field:     [0] ULDO
//
// Request WUC to switch to uLDO.
//
// 0: No request
// 1: Assert request when possible
//
// The bit will have no effect before the following requirements are met:
// 1. PDCTL1.CPU_ON = 0
// 2. PDCTL1.VIMS_MODE = 0
// 3. SECDMACLKGDS.DMA_CLK_EN = 0 (Note: Setting must be loaded with
// CLKLOADCTL.LOAD)
// 4. SECDMACLKGDS.CRYPTO_CLK_EN = 0 (Note: Setting must be loaded with
// CLKLOADCTL.LOAD)
// 5. RFC do no request access to BUS
// 6. System CPU in deepsleep
#define PRCM_VDCTL_ULDO                                             0x00000001
#define PRCM_VDCTL_ULDO_BITN                                                 0
#define PRCM_VDCTL_ULDO_M                                           0x00000001
#define PRCM_VDCTL_ULDO_S                                                    0

//*****************************************************************************
//
// Register: PRCM_O_CLKLOADCTL
//
//*****************************************************************************
// Field:     [1] LOAD_DONE
//
// Status of LOAD.
// Will be cleared to 0 when any of the registers requiring a LOAD is written
// to, and be set to 1 when a LOAD is done.
// Note that writing no change to a register will result in the LOAD_DONE being
// cleared.
//
// 0 : One or more registers have been write accessed after last LOAD
// 1 : No registers are write accessed after last LOAD
#define PRCM_CLKLOADCTL_LOAD_DONE                                   0x00000002
#define PRCM_CLKLOADCTL_LOAD_DONE_BITN                                       1
#define PRCM_CLKLOADCTL_LOAD_DONE_M                                 0x00000002
#define PRCM_CLKLOADCTL_LOAD_DONE_S                                          1

// Field:     [0] LOAD
//
// 0: No action
// 1: Load settings to CLKCTRL. Bit is HW cleared.
//
// Multiple changes to settings may be done before LOAD is written once so all
// changes takes place at the same time. LOAD can also be done after single
// setting updates.
//
// Registers that needs to be followed by LOAD before settings being applied
// are:
// - RFCCLKG
// - VIMSCLKG
// - SECDMACLKGR
// - SECDMACLKGS
// - SECDMACLKGDS
// - GPIOCLKGR
// - GPIOCLKGS
// - GPIOCLKGDS
// - GPTCLKGR
// - GPTCLKGS
// - GPTCLKGDS
// - GPTCLKDIV
// - I2CCLKGR
// - I2CCLKGS
// - I2CCLKGDS
// - SSICLKGR
// - SSICLKGS
// - SSICLKGDS
// - UARTCLKGR
// - UARTCLKGS
// - UARTCLKGDS
// - I2SCLKGR
// - I2SCLKGS
// - I2SCLKGDS
// - I2SBCLKSEL
// - I2SCLKCTL
// - I2SMCLKDIV
// - I2SBCLKDIV
// - I2SWCLKDIV
#define PRCM_CLKLOADCTL_LOAD                                        0x00000001
#define PRCM_CLKLOADCTL_LOAD_BITN                                            0
#define PRCM_CLKLOADCTL_LOAD_M                                      0x00000001
#define PRCM_CLKLOADCTL_LOAD_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_RFCCLKG
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock if RFC power domain is on
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_RFCCLKG_CLK_EN                                         0x00000001
#define PRCM_RFCCLKG_CLK_EN_BITN                                             0
#define PRCM_RFCCLKG_CLK_EN_M                                       0x00000001
#define PRCM_RFCCLKG_CLK_EN_S                                                0

//*****************************************************************************
//
// Register: PRCM_O_VIMSCLKG
//
//*****************************************************************************
// Field:   [1:0] CLK_EN
//
// 00: Disable clock
// 01: Disable clock when SYSBUS clock is disabled
// 11: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_VIMSCLKG_CLK_EN_W                                               2
#define PRCM_VIMSCLKG_CLK_EN_M                                      0x00000003
#define PRCM_VIMSCLKG_CLK_EN_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_SECDMACLKGR
//
//*****************************************************************************
// Field:     [8] DMA_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGR_DMA_CLK_EN                                 0x00000100
#define PRCM_SECDMACLKGR_DMA_CLK_EN_BITN                                     8
#define PRCM_SECDMACLKGR_DMA_CLK_EN_M                               0x00000100
#define PRCM_SECDMACLKGR_DMA_CLK_EN_S                                        8

// Field:     [1] TRNG_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGR_TRNG_CLK_EN                                0x00000002
#define PRCM_SECDMACLKGR_TRNG_CLK_EN_BITN                                    1
#define PRCM_SECDMACLKGR_TRNG_CLK_EN_M                              0x00000002
#define PRCM_SECDMACLKGR_TRNG_CLK_EN_S                                       1

// Field:     [0] CRYPTO_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGR_CRYPTO_CLK_EN                              0x00000001
#define PRCM_SECDMACLKGR_CRYPTO_CLK_EN_BITN                                  0
#define PRCM_SECDMACLKGR_CRYPTO_CLK_EN_M                            0x00000001
#define PRCM_SECDMACLKGR_CRYPTO_CLK_EN_S                                     0

//*****************************************************************************
//
// Register: PRCM_O_SECDMACLKGS
//
//*****************************************************************************
// Field:     [8] DMA_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGS_DMA_CLK_EN                                 0x00000100
#define PRCM_SECDMACLKGS_DMA_CLK_EN_BITN                                     8
#define PRCM_SECDMACLKGS_DMA_CLK_EN_M                               0x00000100
#define PRCM_SECDMACLKGS_DMA_CLK_EN_S                                        8

// Field:     [1] TRNG_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGS_TRNG_CLK_EN                                0x00000002
#define PRCM_SECDMACLKGS_TRNG_CLK_EN_BITN                                    1
#define PRCM_SECDMACLKGS_TRNG_CLK_EN_M                              0x00000002
#define PRCM_SECDMACLKGS_TRNG_CLK_EN_S                                       1

// Field:     [0] CRYPTO_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGS_CRYPTO_CLK_EN                              0x00000001
#define PRCM_SECDMACLKGS_CRYPTO_CLK_EN_BITN                                  0
#define PRCM_SECDMACLKGS_CRYPTO_CLK_EN_M                            0x00000001
#define PRCM_SECDMACLKGS_CRYPTO_CLK_EN_S                                     0

//*****************************************************************************
//
// Register: PRCM_O_SECDMACLKGDS
//
//*****************************************************************************
// Field:     [8] DMA_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGDS_DMA_CLK_EN                                0x00000100
#define PRCM_SECDMACLKGDS_DMA_CLK_EN_BITN                                    8
#define PRCM_SECDMACLKGDS_DMA_CLK_EN_M                              0x00000100
#define PRCM_SECDMACLKGDS_DMA_CLK_EN_S                                       8

// Field:     [1] TRNG_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGDS_TRNG_CLK_EN                               0x00000002
#define PRCM_SECDMACLKGDS_TRNG_CLK_EN_BITN                                   1
#define PRCM_SECDMACLKGDS_TRNG_CLK_EN_M                             0x00000002
#define PRCM_SECDMACLKGDS_TRNG_CLK_EN_S                                      1

// Field:     [0] CRYPTO_CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_SECDMACLKGDS_CRYPTO_CLK_EN                             0x00000001
#define PRCM_SECDMACLKGDS_CRYPTO_CLK_EN_BITN                                 0
#define PRCM_SECDMACLKGDS_CRYPTO_CLK_EN_M                           0x00000001
#define PRCM_SECDMACLKGDS_CRYPTO_CLK_EN_S                                    0

//*****************************************************************************
//
// Register: PRCM_O_GPIOCLKGR
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_GPIOCLKGR_CLK_EN                                       0x00000001
#define PRCM_GPIOCLKGR_CLK_EN_BITN                                           0
#define PRCM_GPIOCLKGR_CLK_EN_M                                     0x00000001
#define PRCM_GPIOCLKGR_CLK_EN_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_GPIOCLKGS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_GPIOCLKGS_CLK_EN                                       0x00000001
#define PRCM_GPIOCLKGS_CLK_EN_BITN                                           0
#define PRCM_GPIOCLKGS_CLK_EN_M                                     0x00000001
#define PRCM_GPIOCLKGS_CLK_EN_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_GPIOCLKGDS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_GPIOCLKGDS_CLK_EN                                      0x00000001
#define PRCM_GPIOCLKGDS_CLK_EN_BITN                                          0
#define PRCM_GPIOCLKGDS_CLK_EN_M                                    0x00000001
#define PRCM_GPIOCLKGDS_CLK_EN_S                                             0

//*****************************************************************************
//
// Register: PRCM_O_GPTCLKGR
//
//*****************************************************************************
// Field:   [3:0] CLK_EN
//
// Each bit below has the following meaning:
//
// 0: Disable clock
// 1: Enable clock
//
// ENUMs can be combined
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
// ENUMs:
// GPT3                     Enable clock for GPT3
// GPT2                     Enable clock for GPT2
// GPT1                     Enable clock for GPT1
// GPT0                     Enable clock for GPT0
#define PRCM_GPTCLKGR_CLK_EN_W                                               4
#define PRCM_GPTCLKGR_CLK_EN_M                                      0x0000000F
#define PRCM_GPTCLKGR_CLK_EN_S                                               0
#define PRCM_GPTCLKGR_CLK_EN_GPT3                                   0x00000008
#define PRCM_GPTCLKGR_CLK_EN_GPT2                                   0x00000004
#define PRCM_GPTCLKGR_CLK_EN_GPT1                                   0x00000002
#define PRCM_GPTCLKGR_CLK_EN_GPT0                                   0x00000001

//*****************************************************************************
//
// Register: PRCM_O_GPTCLKGS
//
//*****************************************************************************
// Field:   [3:0] CLK_EN
//
// Each bit below has the following meaning:
//
// 0: Disable clock
// 1: Enable clock
//
// ENUMs can be combined
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
// ENUMs:
// GPT3                     Enable clock for GPT3
// GPT2                     Enable clock for GPT2
// GPT1                     Enable clock for GPT1
// GPT0                     Enable clock for GPT0
#define PRCM_GPTCLKGS_CLK_EN_W                                               4
#define PRCM_GPTCLKGS_CLK_EN_M                                      0x0000000F
#define PRCM_GPTCLKGS_CLK_EN_S                                               0
#define PRCM_GPTCLKGS_CLK_EN_GPT3                                   0x00000008
#define PRCM_GPTCLKGS_CLK_EN_GPT2                                   0x00000004
#define PRCM_GPTCLKGS_CLK_EN_GPT1                                   0x00000002
#define PRCM_GPTCLKGS_CLK_EN_GPT0                                   0x00000001

//*****************************************************************************
//
// Register: PRCM_O_GPTCLKGDS
//
//*****************************************************************************
// Field:   [3:0] CLK_EN
//
// Each bit below has the following meaning:
//
// 0: Disable clock
// 1: Enable clock
//
// ENUMs can be combined
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
// ENUMs:
// GPT3                     Enable clock for GPT3
// GPT2                     Enable clock for GPT2
// GPT1                     Enable clock for GPT1
// GPT0                     Enable clock for GPT0
#define PRCM_GPTCLKGDS_CLK_EN_W                                              4
#define PRCM_GPTCLKGDS_CLK_EN_M                                     0x0000000F
#define PRCM_GPTCLKGDS_CLK_EN_S                                              0
#define PRCM_GPTCLKGDS_CLK_EN_GPT3                                  0x00000008
#define PRCM_GPTCLKGDS_CLK_EN_GPT2                                  0x00000004
#define PRCM_GPTCLKGDS_CLK_EN_GPT1                                  0x00000002
#define PRCM_GPTCLKGDS_CLK_EN_GPT0                                  0x00000001

//*****************************************************************************
//
// Register: PRCM_O_I2CCLKGR
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2CCLKGR_CLK_EN                                        0x00000001
#define PRCM_I2CCLKGR_CLK_EN_BITN                                            0
#define PRCM_I2CCLKGR_CLK_EN_M                                      0x00000001
#define PRCM_I2CCLKGR_CLK_EN_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_I2CCLKGS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2CCLKGS_CLK_EN                                        0x00000001
#define PRCM_I2CCLKGS_CLK_EN_BITN                                            0
#define PRCM_I2CCLKGS_CLK_EN_M                                      0x00000001
#define PRCM_I2CCLKGS_CLK_EN_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_I2CCLKGDS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2CCLKGDS_CLK_EN                                       0x00000001
#define PRCM_I2CCLKGDS_CLK_EN_BITN                                           0
#define PRCM_I2CCLKGDS_CLK_EN_M                                     0x00000001
#define PRCM_I2CCLKGDS_CLK_EN_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_UARTCLKGR
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_UARTCLKGR_CLK_EN                                       0x00000001
#define PRCM_UARTCLKGR_CLK_EN_BITN                                           0
#define PRCM_UARTCLKGR_CLK_EN_M                                     0x00000001
#define PRCM_UARTCLKGR_CLK_EN_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_UARTCLKGS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_UARTCLKGS_CLK_EN                                       0x00000001
#define PRCM_UARTCLKGS_CLK_EN_BITN                                           0
#define PRCM_UARTCLKGS_CLK_EN_M                                     0x00000001
#define PRCM_UARTCLKGS_CLK_EN_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_UARTCLKGDS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_UARTCLKGDS_CLK_EN                                      0x00000001
#define PRCM_UARTCLKGDS_CLK_EN_BITN                                          0
#define PRCM_UARTCLKGDS_CLK_EN_M                                    0x00000001
#define PRCM_UARTCLKGDS_CLK_EN_S                                             0

//*****************************************************************************
//
// Register: PRCM_O_SSICLKGR
//
//*****************************************************************************
// Field:   [1:0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
// ENUMs:
// SSI1                     Enable clock for SSI1
// SSI0                     Enable clock for SSI0
#define PRCM_SSICLKGR_CLK_EN_W                                               2
#define PRCM_SSICLKGR_CLK_EN_M                                      0x00000003
#define PRCM_SSICLKGR_CLK_EN_S                                               0
#define PRCM_SSICLKGR_CLK_EN_SSI1                                   0x00000002
#define PRCM_SSICLKGR_CLK_EN_SSI0                                   0x00000001

//*****************************************************************************
//
// Register: PRCM_O_SSICLKGS
//
//*****************************************************************************
// Field:   [1:0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
// ENUMs:
// SSI1                     Enable clock for SSI1
// SSI0                     Enable clock for SSI0
#define PRCM_SSICLKGS_CLK_EN_W                                               2
#define PRCM_SSICLKGS_CLK_EN_M                                      0x00000003
#define PRCM_SSICLKGS_CLK_EN_S                                               0
#define PRCM_SSICLKGS_CLK_EN_SSI1                                   0x00000002
#define PRCM_SSICLKGS_CLK_EN_SSI0                                   0x00000001

//*****************************************************************************
//
// Register: PRCM_O_SSICLKGDS
//
//*****************************************************************************
// Field:   [1:0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
// ENUMs:
// SSI1                     Enable clock for SSI1
// SSI0                     Enable clock for SSI0
#define PRCM_SSICLKGDS_CLK_EN_W                                              2
#define PRCM_SSICLKGDS_CLK_EN_M                                     0x00000003
#define PRCM_SSICLKGDS_CLK_EN_S                                              0
#define PRCM_SSICLKGDS_CLK_EN_SSI1                                  0x00000002
#define PRCM_SSICLKGDS_CLK_EN_SSI0                                  0x00000001

//*****************************************************************************
//
// Register: PRCM_O_I2SCLKGR
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SCLKGR_CLK_EN                                        0x00000001
#define PRCM_I2SCLKGR_CLK_EN_BITN                                            0
#define PRCM_I2SCLKGR_CLK_EN_M                                      0x00000001
#define PRCM_I2SCLKGR_CLK_EN_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_I2SCLKGS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SCLKGS_CLK_EN                                        0x00000001
#define PRCM_I2SCLKGS_CLK_EN_BITN                                            0
#define PRCM_I2SCLKGS_CLK_EN_M                                      0x00000001
#define PRCM_I2SCLKGS_CLK_EN_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_I2SCLKGDS
//
//*****************************************************************************
// Field:     [0] CLK_EN
//
//
// 0: Disable clock
// 1: Enable clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SCLKGDS_CLK_EN                                       0x00000001
#define PRCM_I2SCLKGDS_CLK_EN_BITN                                           0
#define PRCM_I2SCLKGDS_CLK_EN_M                                     0x00000001
#define PRCM_I2SCLKGDS_CLK_EN_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_CPUCLKDIV
//
//*****************************************************************************
// Field:     [0] RATIO
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// DIV2                     Internal. Only to be used through TI provided API.
// DIV1                     Internal. Only to be used through TI provided API.
#define PRCM_CPUCLKDIV_RATIO                                        0x00000001
#define PRCM_CPUCLKDIV_RATIO_BITN                                            0
#define PRCM_CPUCLKDIV_RATIO_M                                      0x00000001
#define PRCM_CPUCLKDIV_RATIO_S                                               0
#define PRCM_CPUCLKDIV_RATIO_DIV2                                   0x00000001
#define PRCM_CPUCLKDIV_RATIO_DIV1                                   0x00000000

//*****************************************************************************
//
// Register: PRCM_O_I2SBCLKSEL
//
//*****************************************************************************
// Field:     [0] SRC
//
// BCLK source selector
//
// 0: Use external BCLK
// 1: Use internally generated clock
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SBCLKSEL_SRC                                         0x00000001
#define PRCM_I2SBCLKSEL_SRC_BITN                                             0
#define PRCM_I2SBCLKSEL_SRC_M                                       0x00000001
#define PRCM_I2SBCLKSEL_SRC_S                                                0

//*****************************************************************************
//
// Register: PRCM_O_GPTCLKDIV
//
//*****************************************************************************
// Field:   [3:0] RATIO
//
// Scalar used for GPTs. The division rate will be constant and ungated for Run
// / Sleep / DeepSleep mode.
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
// Other values are not supported.
// ENUMs:
// DIV256                   Divide by 256
// DIV128                   Divide by 128
// DIV64                    Divide by 64
// DIV32                    Divide by 32
// DIV16                    Divide by 16
// DIV8                     Divide by 8
// DIV4                     Divide by 4
// DIV2                     Divide by 2
// DIV1                     Divide by 1
#define PRCM_GPTCLKDIV_RATIO_W                                               4
#define PRCM_GPTCLKDIV_RATIO_M                                      0x0000000F
#define PRCM_GPTCLKDIV_RATIO_S                                               0
#define PRCM_GPTCLKDIV_RATIO_DIV256                                 0x00000008
#define PRCM_GPTCLKDIV_RATIO_DIV128                                 0x00000007
#define PRCM_GPTCLKDIV_RATIO_DIV64                                  0x00000006
#define PRCM_GPTCLKDIV_RATIO_DIV32                                  0x00000005
#define PRCM_GPTCLKDIV_RATIO_DIV16                                  0x00000004
#define PRCM_GPTCLKDIV_RATIO_DIV8                                   0x00000003
#define PRCM_GPTCLKDIV_RATIO_DIV4                                   0x00000002
#define PRCM_GPTCLKDIV_RATIO_DIV2                                   0x00000001
#define PRCM_GPTCLKDIV_RATIO_DIV1                                   0x00000000

//*****************************************************************************
//
// Register: PRCM_O_I2SCLKCTL
//
//*****************************************************************************
// Field:     [3] SMPL_ON_POSEDGE
//
// On the I2S serial interface, data and WCLK is sampled and clocked out on
// opposite edges of BCLK.
//
// 0 - data and WCLK are sampled on the negative edge and clocked out on the
// positive edge.
// 1 - data and WCLK are sampled on the positive edge and clocked out on the
// negative edge.
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SCLKCTL_SMPL_ON_POSEDGE                              0x00000008
#define PRCM_I2SCLKCTL_SMPL_ON_POSEDGE_BITN                                  3
#define PRCM_I2SCLKCTL_SMPL_ON_POSEDGE_M                            0x00000008
#define PRCM_I2SCLKCTL_SMPL_ON_POSEDGE_S                                     3

// Field:   [2:1] WCLK_PHASE
//
// Decides how the WCLK division ratio is calculated and used to generate
// different duty cycles (See I2SWCLKDIV.WDIV).
//
// 0: Single phase
// 1: Dual phase
// 2: User Defined
// 3: Reserved/Undefined
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SCLKCTL_WCLK_PHASE_W                                          2
#define PRCM_I2SCLKCTL_WCLK_PHASE_M                                 0x00000006
#define PRCM_I2SCLKCTL_WCLK_PHASE_S                                          1

// Field:     [0] EN
//
//
// 0: MCLK, BCLK and **WCLK** will be static low
// 1: Enables the generation of  MCLK, BCLK and WCLK
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SCLKCTL_EN                                           0x00000001
#define PRCM_I2SCLKCTL_EN_BITN                                               0
#define PRCM_I2SCLKCTL_EN_M                                         0x00000001
#define PRCM_I2SCLKCTL_EN_S                                                  0

//*****************************************************************************
//
// Register: PRCM_O_I2SMCLKDIV
//
//*****************************************************************************
// Field:   [9:0] MDIV
//
// An unsigned factor of the division ratio used to generate MCLK [2-1024]:
//
// MCLK = MCUCLK/MDIV[Hz]
// MCUCLK is 48MHz in normal mode. For powerdown mode the frequency is defined
// by AON_WUC:MCUCLK.PWR_DWN_SRC
//
// A value of 0 is interpreted as 1024.
// A value of 1 is invalid.
// If MDIV is odd the low phase of the clock is one MCUCLK period longer than
// the high phase.
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SMCLKDIV_MDIV_W                                              10
#define PRCM_I2SMCLKDIV_MDIV_M                                      0x000003FF
#define PRCM_I2SMCLKDIV_MDIV_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_I2SBCLKDIV
//
//*****************************************************************************
// Field:   [9:0] BDIV
//
// An unsigned factor of the division ratio used to generate I2S BCLK [2-1024]:
//
// BCLK = MCUCLK/BDIV[Hz]
// MCUCLK is 48MHz in normal mode. For powerdown mode the frequency is defined
// by AON_WUC:MCUCLK.PWR_DWN_SRC
//
// A value of 0 is interpreted as 1024.
// A value of 1 is invalid.
// If BDIV is odd and I2SCLKCTL.SMPL_ON_POSEDGE = 0, the low phase of the clock
// is one MCUCLK period longer than the high phase.
// If BDIV is odd and I2SCLKCTL.SMPL_ON_POSEDGE = 1 , the high phase of the
// clock is one MCUCLK period longer than the low phase.
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SBCLKDIV_BDIV_W                                              10
#define PRCM_I2SBCLKDIV_BDIV_M                                      0x000003FF
#define PRCM_I2SBCLKDIV_BDIV_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_I2SWCLKDIV
//
//*****************************************************************************
// Field:  [15:0] WDIV
//
// If I2SCLKCTL.WCLK_PHASE = 0, Single phase.
// WCLK is high one BCLK period and low WDIV[9:0] (unsigned, [1-1023]) BCLK
// periods.
//
// WCLK = MCUCLK / BDIV*(WDIV[9:0] + 1) [Hz]
// MCUCLK is 48MHz in normal mode. For powerdown mode the frequency is defined
// by AON_WUC:MCUCLK.PWR_DWN_SRC
//
// If I2SCLKCTL.WCLK_PHASE = 1, Dual phase.
// Each phase on WCLK (50% duty cycle) is WDIV[9:0] (unsigned, [1-1023]) BCLK
// periods.
//
// WCLK = MCUCLK / BDIV*(2*WDIV[9:0]) [Hz]
//
// If I2SCLKCTL.WCLK_PHASE = 2, User defined.
// WCLK is high WDIV[7:0] (unsigned, [1-255]) BCLK periods and low WDIV[15:8]
// (unsigned, [1-255]) BCLK periods.
//
// WCLK = MCUCLK / (BDIV*(WDIV[7:0] + WDIV[15:8]) [Hz]
//
// For changes to take effect, CLKLOADCTL.LOAD needs to be written
#define PRCM_I2SWCLKDIV_WDIV_W                                              16
#define PRCM_I2SWCLKDIV_WDIV_M                                      0x0000FFFF
#define PRCM_I2SWCLKDIV_WDIV_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_SWRESET
//
//*****************************************************************************
// Field:     [2] MCU
//
// Internal. Only to be used through TI provided API.
#define PRCM_SWRESET_MCU                                            0x00000004
#define PRCM_SWRESET_MCU_BITN                                                2
#define PRCM_SWRESET_MCU_M                                          0x00000004
#define PRCM_SWRESET_MCU_S                                                   2

//*****************************************************************************
//
// Register: PRCM_O_WARMRESET
//
//*****************************************************************************
// Field:     [2] WR_TO_PINRESET
//
// 0: No action
// 1: A warm system reset event triggered by the below listed sources will
// result in an emulated pin reset.
//
// Warm reset sources included:
// ICEPick sysreset
// System CPU reset request, CPU_SCS:AIRCR.SYSRESETREQ
// System CPU Lockup
// WDT timeout
//
// An active ICEPick block system reset will gate all sources except ICEPick
// sysreset
//
// SW can read AON_SYSCTL:RESETCTL.RESET_SRC to find the source of the last
// reset resulting in a full power up sequence. WARMRESET in this register is
// set in the scenario that WR_TO_PINRESET=1 and one of the above listed
// sources is triggered.
#define PRCM_WARMRESET_WR_TO_PINRESET                               0x00000004
#define PRCM_WARMRESET_WR_TO_PINRESET_BITN                                   2
#define PRCM_WARMRESET_WR_TO_PINRESET_M                             0x00000004
#define PRCM_WARMRESET_WR_TO_PINRESET_S                                      2

// Field:     [1] LOCKUP_STAT
//
//
// 0: No registred event
// 1: A system CPU LOCKUP event has occured since last SW clear of the
// register.
//
// A read of this register clears both  WDT_STAT and LOCKUP_STAT.
#define PRCM_WARMRESET_LOCKUP_STAT                                  0x00000002
#define PRCM_WARMRESET_LOCKUP_STAT_BITN                                      1
#define PRCM_WARMRESET_LOCKUP_STAT_M                                0x00000002
#define PRCM_WARMRESET_LOCKUP_STAT_S                                         1

// Field:     [0] WDT_STAT
//
//
// 0: No registered event
// 1: A WDT event has occured since last SW clear of the register.
//
// A read of this register clears both WDT_STAT and LOCKUP_STAT.
#define PRCM_WARMRESET_WDT_STAT                                     0x00000001
#define PRCM_WARMRESET_WDT_STAT_BITN                                         0
#define PRCM_WARMRESET_WDT_STAT_M                                   0x00000001
#define PRCM_WARMRESET_WDT_STAT_S                                            0

//*****************************************************************************
//
// Register: PRCM_O_PDCTL0
//
//*****************************************************************************
// Field:     [2] PERIPH_ON
//
// PERIPH Power domain.
//
// 0: PERIPH power domain is powered down
// 1: PERIPH power domain is powered up
#define PRCM_PDCTL0_PERIPH_ON                                       0x00000004
#define PRCM_PDCTL0_PERIPH_ON_BITN                                           2
#define PRCM_PDCTL0_PERIPH_ON_M                                     0x00000004
#define PRCM_PDCTL0_PERIPH_ON_S                                              2

// Field:     [1] SERIAL_ON
//
// SERIAL Power domain.
//
// 0: SERIAL power domain is powered down
// 1: SERIAL power domain is powered up
#define PRCM_PDCTL0_SERIAL_ON                                       0x00000002
#define PRCM_PDCTL0_SERIAL_ON_BITN                                           1
#define PRCM_PDCTL0_SERIAL_ON_M                                     0x00000002
#define PRCM_PDCTL0_SERIAL_ON_S                                              1

// Field:     [0] RFC_ON
//
//
// 0: RFC power domain powered off if also PDCTL1.RFC_ON = 0
// 1: RFC power domain powered on
#define PRCM_PDCTL0_RFC_ON                                          0x00000001
#define PRCM_PDCTL0_RFC_ON_BITN                                              0
#define PRCM_PDCTL0_RFC_ON_M                                        0x00000001
#define PRCM_PDCTL0_RFC_ON_S                                                 0

//*****************************************************************************
//
// Register: PRCM_O_PDCTL0RFC
//
//*****************************************************************************
// Field:     [0] ON
//
// Alias for PDCTL0.RFC_ON
#define PRCM_PDCTL0RFC_ON                                           0x00000001
#define PRCM_PDCTL0RFC_ON_BITN                                               0
#define PRCM_PDCTL0RFC_ON_M                                         0x00000001
#define PRCM_PDCTL0RFC_ON_S                                                  0

//*****************************************************************************
//
// Register: PRCM_O_PDCTL0SERIAL
//
//*****************************************************************************
// Field:     [0] ON
//
// Alias for PDCTL0.SERIAL_ON
#define PRCM_PDCTL0SERIAL_ON                                        0x00000001
#define PRCM_PDCTL0SERIAL_ON_BITN                                            0
#define PRCM_PDCTL0SERIAL_ON_M                                      0x00000001
#define PRCM_PDCTL0SERIAL_ON_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_PDCTL0PERIPH
//
//*****************************************************************************
// Field:     [0] ON
//
// Alias for PDCTL0.PERIPH_ON
#define PRCM_PDCTL0PERIPH_ON                                        0x00000001
#define PRCM_PDCTL0PERIPH_ON_BITN                                            0
#define PRCM_PDCTL0PERIPH_ON_M                                      0x00000001
#define PRCM_PDCTL0PERIPH_ON_S                                               0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT0
//
//*****************************************************************************
// Field:     [2] PERIPH_ON
//
// PERIPH Power domain.
//
// 0: Domain may be powered down
// 1: Domain powered up (guaranteed)
#define PRCM_PDSTAT0_PERIPH_ON                                      0x00000004
#define PRCM_PDSTAT0_PERIPH_ON_BITN                                          2
#define PRCM_PDSTAT0_PERIPH_ON_M                                    0x00000004
#define PRCM_PDSTAT0_PERIPH_ON_S                                             2

// Field:     [1] SERIAL_ON
//
// SERIAL Power domain.
//
// 0: Domain may be powered down
// 1: Domain powered up (guaranteed)
#define PRCM_PDSTAT0_SERIAL_ON                                      0x00000002
#define PRCM_PDSTAT0_SERIAL_ON_BITN                                          1
#define PRCM_PDSTAT0_SERIAL_ON_M                                    0x00000002
#define PRCM_PDSTAT0_SERIAL_ON_S                                             1

// Field:     [0] RFC_ON
//
// RFC Power domain
//
// 0: Domain may be powered down
// 1: Domain powered up (guaranteed)
#define PRCM_PDSTAT0_RFC_ON                                         0x00000001
#define PRCM_PDSTAT0_RFC_ON_BITN                                             0
#define PRCM_PDSTAT0_RFC_ON_M                                       0x00000001
#define PRCM_PDSTAT0_RFC_ON_S                                                0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT0RFC
//
//*****************************************************************************
// Field:     [0] ON
//
// Alias for PDSTAT0.RFC_ON
#define PRCM_PDSTAT0RFC_ON                                          0x00000001
#define PRCM_PDSTAT0RFC_ON_BITN                                              0
#define PRCM_PDSTAT0RFC_ON_M                                        0x00000001
#define PRCM_PDSTAT0RFC_ON_S                                                 0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT0SERIAL
//
//*****************************************************************************
// Field:     [0] ON
//
// Alias for PDSTAT0.SERIAL_ON
#define PRCM_PDSTAT0SERIAL_ON                                       0x00000001
#define PRCM_PDSTAT0SERIAL_ON_BITN                                           0
#define PRCM_PDSTAT0SERIAL_ON_M                                     0x00000001
#define PRCM_PDSTAT0SERIAL_ON_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT0PERIPH
//
//*****************************************************************************
// Field:     [0] ON
//
// Alias for PDSTAT0.PERIPH_ON
#define PRCM_PDSTAT0PERIPH_ON                                       0x00000001
#define PRCM_PDSTAT0PERIPH_ON_BITN                                           0
#define PRCM_PDSTAT0PERIPH_ON_M                                     0x00000001
#define PRCM_PDSTAT0PERIPH_ON_S                                              0

//*****************************************************************************
//
// Register: PRCM_O_PDCTL1
//
//*****************************************************************************
// Field:     [3] VIMS_MODE
//
//
// 0: VIMS power domain is only powered when CPU power domain is powered.
// 1: VIMS power domain is powered whenever the BUS power domain is powered.
#define PRCM_PDCTL1_VIMS_MODE                                       0x00000008
#define PRCM_PDCTL1_VIMS_MODE_BITN                                           3
#define PRCM_PDCTL1_VIMS_MODE_M                                     0x00000008
#define PRCM_PDCTL1_VIMS_MODE_S                                              3

// Field:     [2] RFC_ON
//
//
// 0: RFC power domain powered off if also PDCTL0.RFC_ON = 0
// 1: RFC power domain powered on
//
// Bit shall be used by RFC in autonomus mode but there is no HW restrictions
// fom system CPU to access the bit.
#define PRCM_PDCTL1_RFC_ON                                          0x00000004
#define PRCM_PDCTL1_RFC_ON_BITN                                              2
#define PRCM_PDCTL1_RFC_ON_M                                        0x00000004
#define PRCM_PDCTL1_RFC_ON_S                                                 2

// Field:     [1] CPU_ON
//
//
// 0: Causes a power down of the CPU power domain when system CPU indicates it
// is idle.
// 1: Initiates power-on of the CPU power domain.
//
// This bit is automatically set by a WIC power-on event.
#define PRCM_PDCTL1_CPU_ON                                          0x00000002
#define PRCM_PDCTL1_CPU_ON_BITN                                              1
#define PRCM_PDCTL1_CPU_ON_M                                        0x00000002
#define PRCM_PDCTL1_CPU_ON_S                                                 1

//*****************************************************************************
//
// Register: PRCM_O_PDCTL1CPU
//
//*****************************************************************************
// Field:     [0] ON
//
// This is an alias for PDCTL1.CPU_ON
#define PRCM_PDCTL1CPU_ON                                           0x00000001
#define PRCM_PDCTL1CPU_ON_BITN                                               0
#define PRCM_PDCTL1CPU_ON_M                                         0x00000001
#define PRCM_PDCTL1CPU_ON_S                                                  0

//*****************************************************************************
//
// Register: PRCM_O_PDCTL1RFC
//
//*****************************************************************************
// Field:     [0] ON
//
// This is an alias for PDCTL1.RFC_ON
#define PRCM_PDCTL1RFC_ON                                           0x00000001
#define PRCM_PDCTL1RFC_ON_BITN                                               0
#define PRCM_PDCTL1RFC_ON_M                                         0x00000001
#define PRCM_PDCTL1RFC_ON_S                                                  0

//*****************************************************************************
//
// Register: PRCM_O_PDCTL1VIMS
//
//*****************************************************************************
// Field:     [0] ON
//
// This is an alias for PDCTL1.VIMS_MODE
#define PRCM_PDCTL1VIMS_ON                                          0x00000001
#define PRCM_PDCTL1VIMS_ON_BITN                                              0
#define PRCM_PDCTL1VIMS_ON_M                                        0x00000001
#define PRCM_PDCTL1VIMS_ON_S                                                 0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT1
//
//*****************************************************************************
// Field:     [4] BUS_ON
//
//
// 0: BUS domain not accessible
// 1: BUS domain is currently accessible
#define PRCM_PDSTAT1_BUS_ON                                         0x00000010
#define PRCM_PDSTAT1_BUS_ON_BITN                                             4
#define PRCM_PDSTAT1_BUS_ON_M                                       0x00000010
#define PRCM_PDSTAT1_BUS_ON_S                                                4

// Field:     [3] VIMS_MODE
//
//
// 0: VIMS domain not accessible
// 1: VIMS domain is currently accessible
#define PRCM_PDSTAT1_VIMS_MODE                                      0x00000008
#define PRCM_PDSTAT1_VIMS_MODE_BITN                                          3
#define PRCM_PDSTAT1_VIMS_MODE_M                                    0x00000008
#define PRCM_PDSTAT1_VIMS_MODE_S                                             3

// Field:     [2] RFC_ON
//
//
// 0: RFC domain not accessible
// 1: RFC domain is currently accessible
#define PRCM_PDSTAT1_RFC_ON                                         0x00000004
#define PRCM_PDSTAT1_RFC_ON_BITN                                             2
#define PRCM_PDSTAT1_RFC_ON_M                                       0x00000004
#define PRCM_PDSTAT1_RFC_ON_S                                                2

// Field:     [1] CPU_ON
//
//
// 0: CPU and BUS domain not accessible
// 1: CPU and BUS domains are both currently accessible
#define PRCM_PDSTAT1_CPU_ON                                         0x00000002
#define PRCM_PDSTAT1_CPU_ON_BITN                                             1
#define PRCM_PDSTAT1_CPU_ON_M                                       0x00000002
#define PRCM_PDSTAT1_CPU_ON_S                                                1

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT1BUS
//
//*****************************************************************************
// Field:     [0] ON
//
// This is an alias for PDSTAT1.BUS_ON
#define PRCM_PDSTAT1BUS_ON                                          0x00000001
#define PRCM_PDSTAT1BUS_ON_BITN                                              0
#define PRCM_PDSTAT1BUS_ON_M                                        0x00000001
#define PRCM_PDSTAT1BUS_ON_S                                                 0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT1RFC
//
//*****************************************************************************
// Field:     [0] ON
//
// This is an alias for PDSTAT1.RFC_ON
#define PRCM_PDSTAT1RFC_ON                                          0x00000001
#define PRCM_PDSTAT1RFC_ON_BITN                                              0
#define PRCM_PDSTAT1RFC_ON_M                                        0x00000001
#define PRCM_PDSTAT1RFC_ON_S                                                 0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT1CPU
//
//*****************************************************************************
// Field:     [0] ON
//
// This is an alias for PDSTAT1.CPU_ON
#define PRCM_PDSTAT1CPU_ON                                          0x00000001
#define PRCM_PDSTAT1CPU_ON_BITN                                              0
#define PRCM_PDSTAT1CPU_ON_M                                        0x00000001
#define PRCM_PDSTAT1CPU_ON_S                                                 0

//*****************************************************************************
//
// Register: PRCM_O_PDSTAT1VIMS
//
//*****************************************************************************
// Field:     [0] ON
//
// This is an alias for PDSTAT1.VIMS_MODE
#define PRCM_PDSTAT1VIMS_ON                                         0x00000001
#define PRCM_PDSTAT1VIMS_ON_BITN                                             0
#define PRCM_PDSTAT1VIMS_ON_M                                       0x00000001
#define PRCM_PDSTAT1VIMS_ON_S                                                0

//*****************************************************************************
//
// Register: PRCM_O_RFCMODESEL
//
//*****************************************************************************
// Field:   [2:0] CURR
//
// Written by MCU - Outputs to RFC. Only modes permitted by RFCMODEHWOPT.AVAIL
// are writeable.
// ENUMs:
// MODE7                    Select Mode 7
// MODE6                    Select Mode 6
// MODE5                    Select Mode 5
// MODE4                    Select Mode 4
// MODE3                    Select Mode 3
// MODE2                    Select Mode 2
// MODE1                    Select Mode 1
// MODE0                    Select Mode 0
#define PRCM_RFCMODESEL_CURR_W                                               3
#define PRCM_RFCMODESEL_CURR_M                                      0x00000007
#define PRCM_RFCMODESEL_CURR_S                                               0
#define PRCM_RFCMODESEL_CURR_MODE7                                  0x00000007
#define PRCM_RFCMODESEL_CURR_MODE6                                  0x00000006
#define PRCM_RFCMODESEL_CURR_MODE5                                  0x00000005
#define PRCM_RFCMODESEL_CURR_MODE4                                  0x00000004
#define PRCM_RFCMODESEL_CURR_MODE3                                  0x00000003
#define PRCM_RFCMODESEL_CURR_MODE2                                  0x00000002
#define PRCM_RFCMODESEL_CURR_MODE1                                  0x00000001
#define PRCM_RFCMODESEL_CURR_MODE0                                  0x00000000

//*****************************************************************************
//
// Register: PRCM_O_RAMRETEN
//
//*****************************************************************************
// Field:     [2] RFC
//
//
// 0: Retention for RFC SRAM disabled
// 1: Retention for RFC SRAM enabled
#define PRCM_RAMRETEN_RFC                                           0x00000004
#define PRCM_RAMRETEN_RFC_BITN                                               2
#define PRCM_RAMRETEN_RFC_M                                         0x00000004
#define PRCM_RAMRETEN_RFC_S                                                  2

// Field:   [1:0] VIMS
//
//
// 0: Memory retention disabled
// 1: Memory retention enabled
//
// Bit 0: VIMS_TRAM
// Bit 1: VIMS_CRAM
//
// Legal modes depend on settings in VIMS:CTL.MODE
//
// 00: VIMS:CTL.MODE must be OFF before DEEPSLEEP is asserted - must be set to
// CACHE or SPLIT mode after waking up again
// 01: VIMS:CTL.MODE must be GPRAM before DEEPSLEEP is asserted. Must remain in
// GPRAM mode after wake up, alternatively select OFF mode first and then CACHE
// or SPILT mode.
// 10: Illegal mode
// 11: No restrictions
#define PRCM_RAMRETEN_VIMS_W                                                 2
#define PRCM_RAMRETEN_VIMS_M                                        0x00000003
#define PRCM_RAMRETEN_VIMS_S                                                 0


#endif // __PRCM__
