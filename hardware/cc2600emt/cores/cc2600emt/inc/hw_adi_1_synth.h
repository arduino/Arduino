/******************************************************************************
*  Filename:       hw_adi_1_synth_h
*  Revised:        2015-12-03 09:20:10 +0100 (Thu, 03 Dec 2015)
*  Revision:       45256
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

#ifndef __HW_ADI_1_SYNTH_H__
#define __HW_ADI_1_SYNTH_H__

//*****************************************************************************
//
// This section defines the register offsets of
// ADI_1_SYNTH component
//
//*****************************************************************************
// Internal
#define ADI_1_SYNTH_O_VCOLDOCTL0                                    0x00000000

// Internal
#define ADI_1_SYNTH_O_VCOLDOCTL1                                    0x00000001

// Internal
#define ADI_1_SYNTH_O_VCOLDOCFG                                     0x00000002

// Internal
#define ADI_1_SYNTH_O_SLDOCTL0                                      0x00000003

// Internal
#define ADI_1_SYNTH_O_SLDOCTL1                                      0x00000004

// Internal
#define ADI_1_SYNTH_O_SYNTHCTLINIT                                  0x00000008

// Internal
#define ADI_1_SYNTH_O_ATESTCTL0                                     0x00000009

// Internal
#define ADI_1_SYNTH_O_ATESTCTL1                                     0x0000000A

// Internal
#define ADI_1_SYNTH_O_STAT                                          0x0000000F

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_VCOLDOCTL0
//
//*****************************************************************************
// Field:     [4] ATEST_V_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCTL0_ATEST_V_EN                           0x00000010
#define ADI_1_SYNTH_VCOLDOCTL0_ATEST_V_EN_M                         0x00000010
#define ADI_1_SYNTH_VCOLDOCTL0_ATEST_V_EN_S                                  4

// Field:     [3] BYPASS_REG_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCTL0_BYPASS_REG_EN                        0x00000008
#define ADI_1_SYNTH_VCOLDOCTL0_BYPASS_REG_EN_M                      0x00000008
#define ADI_1_SYNTH_VCOLDOCTL0_BYPASS_REG_EN_S                               3

// Field:     [2] RDY_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCTL0_RDY_EN                               0x00000004
#define ADI_1_SYNTH_VCOLDOCTL0_RDY_EN_M                             0x00000004
#define ADI_1_SYNTH_VCOLDOCTL0_RDY_EN_S                                      2

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCTL0_BIAS_DIS                             0x00000002
#define ADI_1_SYNTH_VCOLDOCTL0_BIAS_DIS_M                           0x00000002
#define ADI_1_SYNTH_VCOLDOCTL0_BIAS_DIS_S                                    1

// Field:     [0] EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCTL0_EN                                   0x00000001
#define ADI_1_SYNTH_VCOLDOCTL0_EN_M                                 0x00000001
#define ADI_1_SYNTH_VCOLDOCTL0_EN_S                                          0

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_VCOLDOCTL1
//
//*****************************************************************************
// Field:     [6] ATEST_I_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCTL1_ATEST_I_EN                           0x00000040
#define ADI_1_SYNTH_VCOLDOCTL1_ATEST_I_EN_M                         0x00000040
#define ADI_1_SYNTH_VCOLDOCTL1_ATEST_I_EN_S                                  6

// Field:   [5:0] TRIM_OUT
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCTL1_TRIM_OUT_W                                    6
#define ADI_1_SYNTH_VCOLDOCTL1_TRIM_OUT_M                           0x0000003F
#define ADI_1_SYNTH_VCOLDOCTL1_TRIM_OUT_S                                    0

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_VCOLDOCFG
//
//*****************************************************************************
// Field:     [6] DIV_BIAS_DIS
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCFG_DIV_BIAS_DIS                          0x00000040
#define ADI_1_SYNTH_VCOLDOCFG_DIV_BIAS_DIS_M                        0x00000040
#define ADI_1_SYNTH_VCOLDOCFG_DIV_BIAS_DIS_S                                 6

// Field:   [5:3] COMP_RES
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCFG_COMP_RES_W                                     3
#define ADI_1_SYNTH_VCOLDOCFG_COMP_RES_M                            0x00000038
#define ADI_1_SYNTH_VCOLDOCFG_COMP_RES_S                                     3

// Field:   [2:0] COMP_CAP
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_VCOLDOCFG_COMP_CAP_W                                     3
#define ADI_1_SYNTH_VCOLDOCFG_COMP_CAP_M                            0x00000007
#define ADI_1_SYNTH_VCOLDOCFG_COMP_CAP_S                                     0

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_SLDOCTL0
//
//*****************************************************************************
// Field:     [6] COMP_CAP
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SLDOCTL0_COMP_CAP                               0x00000040
#define ADI_1_SYNTH_SLDOCTL0_COMP_CAP_M                             0x00000040
#define ADI_1_SYNTH_SLDOCTL0_COMP_CAP_S                                      6

// Field:     [5] ATEST_I_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SLDOCTL0_ATEST_I_EN                             0x00000020
#define ADI_1_SYNTH_SLDOCTL0_ATEST_I_EN_M                           0x00000020
#define ADI_1_SYNTH_SLDOCTL0_ATEST_I_EN_S                                    5

// Field:     [4] ATEST_V_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SLDOCTL0_ATEST_V_EN                             0x00000010
#define ADI_1_SYNTH_SLDOCTL0_ATEST_V_EN_M                           0x00000010
#define ADI_1_SYNTH_SLDOCTL0_ATEST_V_EN_S                                    4

// Field:     [2] RDY_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SLDOCTL0_RDY_EN                                 0x00000004
#define ADI_1_SYNTH_SLDOCTL0_RDY_EN_M                               0x00000004
#define ADI_1_SYNTH_SLDOCTL0_RDY_EN_S                                        2

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SLDOCTL0_BIAS_DIS                               0x00000002
#define ADI_1_SYNTH_SLDOCTL0_BIAS_DIS_M                             0x00000002
#define ADI_1_SYNTH_SLDOCTL0_BIAS_DIS_S                                      1

// Field:     [0] EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SLDOCTL0_EN                                     0x00000001
#define ADI_1_SYNTH_SLDOCTL0_EN_M                                   0x00000001
#define ADI_1_SYNTH_SLDOCTL0_EN_S                                            0

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_SLDOCTL1
//
//*****************************************************************************
// Field:   [5:0] TRIM_OUT
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SLDOCTL1_TRIM_OUT_W                                      6
#define ADI_1_SYNTH_SLDOCTL1_TRIM_OUT_M                             0x0000003F
#define ADI_1_SYNTH_SLDOCTL1_TRIM_OUT_S                                      0

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_SYNTHCTLINIT
//
//*****************************************************************************
// Field:     [1] CLK_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SYNTHCTLINIT_CLK_EN                             0x00000002
#define ADI_1_SYNTH_SYNTHCTLINIT_CLK_EN_M                           0x00000002
#define ADI_1_SYNTH_SYNTHCTLINIT_CLK_EN_S                                    1

// Field:     [0] DDI_RESET_N
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_SYNTHCTLINIT_DDI_RESET_N                        0x00000001
#define ADI_1_SYNTH_SYNTHCTLINIT_DDI_RESET_N_M                      0x00000001
#define ADI_1_SYNTH_SYNTHCTLINIT_DDI_RESET_N_S                               0

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_ATESTCTL0
//
//*****************************************************************************
// Field:   [7:0] TESTSEL
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// PEAKDETN_A1              Internal. Only to be used through TI provided API.
// RXOUTQN_A1               Internal. Only to be used through TI provided API.
// RXOUTIN_A1               Internal. Only to be used through TI provided API.
// LDOV_A0                  Internal. Only to be used through TI provided API.
// IFADCP_A0                Internal. Only to be used through TI provided API.
// PEAKDETP_A0              Internal. Only to be used through TI provided API.
// RXOUTQP_A0               Internal. Only to be used through TI provided API.
// RXOUTIP_A0               Internal. Only to be used through TI provided API.
// NC                       Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_W                                      8
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_M                             0x000000FF
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_S                                      0
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_PEAKDETN_A1                   0x00000080
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_RXOUTQN_A1                    0x00000040
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_RXOUTIN_A1                    0x00000020
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_LDOV_A0                       0x00000010
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_IFADCP_A0                     0x00000008
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_PEAKDETP_A0                   0x00000004
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_RXOUTQP_A0                    0x00000002
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_RXOUTIP_A0                    0x00000001
#define ADI_1_SYNTH_ATESTCTL0_TESTSEL_NC                            0x00000000

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_ATESTCTL1
//
//*****************************************************************************
// Field:   [7:2] RESEREVED2
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_ATESTCTL1_RESEREVED2_W                                   6
#define ADI_1_SYNTH_ATESTCTL1_RESEREVED2_M                          0x000000FC
#define ADI_1_SYNTH_ATESTCTL1_RESEREVED2_S                                   2

// Field:   [1:0] TESTSEL
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// LDOITEST_A1              Internal. Only to be used through TI provided API.
// IFADCTESTN_A1            Internal. Only to be used through TI provided API.
// NC                       Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_ATESTCTL1_TESTSEL_W                                      2
#define ADI_1_SYNTH_ATESTCTL1_TESTSEL_M                             0x00000003
#define ADI_1_SYNTH_ATESTCTL1_TESTSEL_S                                      0
#define ADI_1_SYNTH_ATESTCTL1_TESTSEL_LDOITEST_A1                   0x00000002
#define ADI_1_SYNTH_ATESTCTL1_TESTSEL_IFADCTESTN_A1                 0x00000001
#define ADI_1_SYNTH_ATESTCTL1_TESTSEL_NC                            0x00000000

//*****************************************************************************
//
// Register: ADI_1_SYNTH_O_STAT
//
//*****************************************************************************
// Field:     [2] SYNTH_TUNE_ACK
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_STAT_SYNTH_TUNE_ACK                             0x00000004
#define ADI_1_SYNTH_STAT_SYNTH_TUNE_ACK_M                           0x00000004
#define ADI_1_SYNTH_STAT_SYNTH_TUNE_ACK_S                                    2

// Field:     [1] SLDO_RDY
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_STAT_SLDO_RDY                                   0x00000002
#define ADI_1_SYNTH_STAT_SLDO_RDY_M                                 0x00000002
#define ADI_1_SYNTH_STAT_SLDO_RDY_S                                          1

// Field:     [0] LDOVCO_RDY
//
// Internal. Only to be used through TI provided API.
#define ADI_1_SYNTH_STAT_LDOVCO_RDY                                 0x00000001
#define ADI_1_SYNTH_STAT_LDOVCO_RDY_M                               0x00000001
#define ADI_1_SYNTH_STAT_LDOVCO_RDY_S                                        0


#endif // __ADI_1_SYNTH__
