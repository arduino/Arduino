/******************************************************************************
*  Filename:       hw_adi_0_rf_h
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

#ifndef __HW_ADI_0_RF_H__
#define __HW_ADI_0_RF_H__

//*****************************************************************************
//
// This section defines the register offsets of
// ADI_0_RF component
//
//*****************************************************************************
// Internal
#define ADI_0_RF_O_LNACTL0                                          0x00000000

// Internal
#define ADI_0_RF_O_LNACTL1                                          0x00000001

// Internal
#define ADI_0_RF_O_LNACTL2                                          0x00000002

// Internal
#define ADI_0_RF_O_IFAMPCTL0                                        0x00000003

// Internal
#define ADI_0_RF_O_IFAMPCTL1                                        0x00000004

// Internal
#define ADI_0_RF_O_IFAMPCTL2                                        0x00000005

// Internal
#define ADI_0_RF_O_PACTL0                                           0x00000006

// Internal
#define ADI_0_RF_O_PACTL1                                           0x00000007

// Internal
#define ADI_0_RF_O_PACTL2                                           0x00000008

// Internal
#define ADI_0_RF_O_RFLDO0                                           0x00000009

// Internal
#define ADI_0_RF_O_RFLDO1                                           0x0000000A

// Internal
#define ADI_0_RF_O_RFLDO2                                           0x0000000B

// Internal
#define ADI_0_RF_O_IFADCCTL0                                        0x0000000C

// Internal
#define ADI_0_RF_O_IFADCLFCFG0                                      0x0000000D

// Internal
#define ADI_0_RF_O_IFADCLFCFG1                                      0x0000000E

// Internal
#define ADI_0_RF_O_IFADCDAC                                         0x0000000F

// Internal
#define ADI_0_RF_O_IFADCQUANT0                                      0x00000010

// Internal
#define ADI_0_RF_O_IFADCCTL1                                        0x00000012

// Internal
#define ADI_0_RF_O_IFADCCTL2                                        0x00000013

// Internal
#define ADI_0_RF_O_IFALDO1                                          0x00000018

// Internal
#define ADI_0_RF_O_IFALDO2                                          0x00000019

// Internal
#define ADI_0_RF_O_IFALDO3                                          0x0000001A

// Internal
#define ADI_0_RF_O_IFDLDO1                                          0x0000001B

// Internal
#define ADI_0_RF_O_IFDLDO2                                          0x0000001C

// Internal
#define ADI_0_RF_O_IFDLDO3                                          0x0000001D

// Internal
#define ADI_0_RF_O_IFAMPCTL3                                        0x0000001E

// Internal
#define ADI_0_RF_O_STAT                                             0x0000001F

//*****************************************************************************
//
// Register: ADI_0_RF_O_LNACTL0
//
//*****************************************************************************
// Field:   [7:4] MIX_AD
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// MIX_SE_RFN               Internal. Only to be used through TI provided API.
// MIX_SE_RFP               Internal. Only to be used through TI provided API.
// MIX_DIFF_MODE            Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL0_MIX_AD_W                                            4
#define ADI_0_RF_LNACTL0_MIX_AD_M                                   0x000000F0
#define ADI_0_RF_LNACTL0_MIX_AD_S                                            4
#define ADI_0_RF_LNACTL0_MIX_AD_MIX_SE_RFN                          0x000000A0
#define ADI_0_RF_LNACTL0_MIX_AD_MIX_SE_RFP                          0x00000050
#define ADI_0_RF_LNACTL0_MIX_AD_MIX_DIFF_MODE                       0x00000000

// Field:   [3:2] LNA_AD
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// LNA_SE_RFN               Internal. Only to be used through TI provided API.
// LNA_SE_RFP               Internal. Only to be used through TI provided API.
// LNA_DIFF_MODE            Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL0_LNA_AD_W                                            2
#define ADI_0_RF_LNACTL0_LNA_AD_M                                   0x0000000C
#define ADI_0_RF_LNACTL0_LNA_AD_S                                            2
#define ADI_0_RF_LNACTL0_LNA_AD_LNA_SE_RFN                          0x00000008
#define ADI_0_RF_LNACTL0_LNA_AD_LNA_SE_RFP                          0x00000004
#define ADI_0_RF_LNACTL0_LNA_AD_LNA_DIFF_MODE                       0x00000000

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL0_BIAS_DIS                                   0x00000002
#define ADI_0_RF_LNACTL0_BIAS_DIS_M                                 0x00000002
#define ADI_0_RF_LNACTL0_BIAS_DIS_S                                          1

// Field:     [0] EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL0_EN                                         0x00000001
#define ADI_0_RF_LNACTL0_EN_M                                       0x00000001
#define ADI_0_RF_LNACTL0_EN_S                                                0
#define ADI_0_RF_LNACTL0_EN_EN                                      0x00000001
#define ADI_0_RF_LNACTL0_EN_DIS                                     0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_LNACTL1
//
//*****************************************************************************
// Field:   [5:4] DEV_CTL
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL1_DEV_CTL_W                                           2
#define ADI_0_RF_LNACTL1_DEV_CTL_M                                  0x00000030
#define ADI_0_RF_LNACTL1_DEV_CTL_S                                           4

// Field:   [3:0] GAIN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// MAX                      Internal. Only to be used through TI provided API.
// MAX_MINUS_3              Internal. Only to be used through TI provided API.
// MAX_MINUS_6              Internal. Only to be used through TI provided API.
// MAX_MINUS_9              Internal. Only to be used through TI provided API.
// MAX_MINUS_12             Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL1_GAIN_W                                              4
#define ADI_0_RF_LNACTL1_GAIN_M                                     0x0000000F
#define ADI_0_RF_LNACTL1_GAIN_S                                              0
#define ADI_0_RF_LNACTL1_GAIN_MAX                                   0x0000000F
#define ADI_0_RF_LNACTL1_GAIN_MAX_MINUS_3                           0x00000007
#define ADI_0_RF_LNACTL1_GAIN_MAX_MINUS_6                           0x00000003
#define ADI_0_RF_LNACTL1_GAIN_MAX_MINUS_9                           0x00000001
#define ADI_0_RF_LNACTL1_GAIN_MAX_MINUS_12                          0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_LNACTL2
//
//*****************************************************************************
// Field:   [7:6] RXTX_PIN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL2_RXTX_PIN_W                                          2
#define ADI_0_RF_LNACTL2_RXTX_PIN_M                                 0x000000C0
#define ADI_0_RF_LNACTL2_RXTX_PIN_S                                          6

// Field:     [4] EXT_BIAS
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL2_EXT_BIAS                                   0x00000010
#define ADI_0_RF_LNACTL2_EXT_BIAS_M                                 0x00000010
#define ADI_0_RF_LNACTL2_EXT_BIAS_S                                          4

// Field:   [3:0] IB
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_LNACTL2_IB_W                                                4
#define ADI_0_RF_LNACTL2_IB_M                                       0x0000000F
#define ADI_0_RF_LNACTL2_IB_S                                                0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFAMPCTL0
//
//*****************************************************************************
// Field:   [7:3] TRIM
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL0_TRIM_W                                            5
#define ADI_0_RF_IFAMPCTL0_TRIM_M                                   0x000000F8
#define ADI_0_RF_IFAMPCTL0_TRIM_S                                            3

// Field:     [2] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL0_BIAS_DIS                                 0x00000004
#define ADI_0_RF_IFAMPCTL0_BIAS_DIS_M                               0x00000004
#define ADI_0_RF_IFAMPCTL0_BIAS_DIS_S                                        2

// Field:     [1] EN_Q
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL0_EN_Q                                     0x00000002
#define ADI_0_RF_IFAMPCTL0_EN_Q_M                                   0x00000002
#define ADI_0_RF_IFAMPCTL0_EN_Q_S                                            1
#define ADI_0_RF_IFAMPCTL0_EN_Q_EN                                  0x00000002
#define ADI_0_RF_IFAMPCTL0_EN_Q_DIS                                 0x00000000

// Field:     [0] EN_I
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL0_EN_I                                     0x00000001
#define ADI_0_RF_IFAMPCTL0_EN_I_M                                   0x00000001
#define ADI_0_RF_IFAMPCTL0_EN_I_S                                            0
#define ADI_0_RF_IFAMPCTL0_EN_I_EN                                  0x00000001
#define ADI_0_RF_IFAMPCTL0_EN_I_DIS                                 0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFAMPCTL1
//
//*****************************************************************************
// Field:   [5:0] GAIN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// MAX                      Internal. Only to be used through TI provided API.
// MAX_MINUS_3              Internal. Only to be used through TI provided API.
// MAX_MINUS_6              Internal. Only to be used through TI provided API.
// MAX_MINUS_9              Internal. Only to be used through TI provided API.
// MAX_MINUS_12             Internal. Only to be used through TI provided API.
// MAX_MINUS_15             Internal. Only to be used through TI provided API.
// MAX_MINUS_18             Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL1_GAIN_W                                            6
#define ADI_0_RF_IFAMPCTL1_GAIN_M                                   0x0000003F
#define ADI_0_RF_IFAMPCTL1_GAIN_S                                            0
#define ADI_0_RF_IFAMPCTL1_GAIN_MAX                                 0x0000003F
#define ADI_0_RF_IFAMPCTL1_GAIN_MAX_MINUS_3                         0x0000001F
#define ADI_0_RF_IFAMPCTL1_GAIN_MAX_MINUS_6                         0x0000000F
#define ADI_0_RF_IFAMPCTL1_GAIN_MAX_MINUS_9                         0x00000007
#define ADI_0_RF_IFAMPCTL1_GAIN_MAX_MINUS_12                        0x00000003
#define ADI_0_RF_IFAMPCTL1_GAIN_MAX_MINUS_15                        0x00000001
#define ADI_0_RF_IFAMPCTL1_GAIN_MAX_MINUS_18                        0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFAMPCTL2
//
//*****************************************************************************
// Field:   [2:0] ATTN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// MINUS_21                 Internal. Only to be used through TI provided API.
// MINUS_18                 Internal. Only to be used through TI provided API.
// MINUS_15                 Internal. Only to be used through TI provided API.
// MINUS_12                 Internal. Only to be used through TI provided API.
// MINUS_9                  Internal. Only to be used through TI provided API.
// MINUS_6                  Internal. Only to be used through TI provided API.
// MINUS_3                  Internal. Only to be used through TI provided API.
// MIN                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL2_ATTN_W                                            3
#define ADI_0_RF_IFAMPCTL2_ATTN_M                                   0x00000007
#define ADI_0_RF_IFAMPCTL2_ATTN_S                                            0
#define ADI_0_RF_IFAMPCTL2_ATTN_MINUS_21                            0x00000007
#define ADI_0_RF_IFAMPCTL2_ATTN_MINUS_18                            0x00000006
#define ADI_0_RF_IFAMPCTL2_ATTN_MINUS_15                            0x00000005
#define ADI_0_RF_IFAMPCTL2_ATTN_MINUS_12                            0x00000004
#define ADI_0_RF_IFAMPCTL2_ATTN_MINUS_9                             0x00000003
#define ADI_0_RF_IFAMPCTL2_ATTN_MINUS_6                             0x00000002
#define ADI_0_RF_IFAMPCTL2_ATTN_MINUS_3                             0x00000001
#define ADI_0_RF_IFAMPCTL2_ATTN_MIN                                 0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_PACTL0
//
//*****************************************************************************
// Field:   [7:3] TRIM
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL0_TRIM_W                                               5
#define ADI_0_RF_PACTL0_TRIM_M                                      0x000000F8
#define ADI_0_RF_PACTL0_TRIM_S                                               3

// Field:     [2] PEAKDET_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL0_PEAKDET_EN                                  0x00000004
#define ADI_0_RF_PACTL0_PEAKDET_EN_M                                0x00000004
#define ADI_0_RF_PACTL0_PEAKDET_EN_S                                         2
#define ADI_0_RF_PACTL0_PEAKDET_EN_EN                               0x00000004
#define ADI_0_RF_PACTL0_PEAKDET_EN_DIS                              0x00000000

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL0_BIAS_DIS                                    0x00000002
#define ADI_0_RF_PACTL0_BIAS_DIS_M                                  0x00000002
#define ADI_0_RF_PACTL0_BIAS_DIS_S                                           1

// Field:     [0] EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL0_EN                                          0x00000001
#define ADI_0_RF_PACTL0_EN_M                                        0x00000001
#define ADI_0_RF_PACTL0_EN_S                                                 0
#define ADI_0_RF_PACTL0_EN_EN                                       0x00000001
#define ADI_0_RF_PACTL0_EN_DIS                                      0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_PACTL1
//
//*****************************************************************************
// Field:   [7:6] GAIN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL1_GAIN_W                                               2
#define ADI_0_RF_PACTL1_GAIN_M                                      0x000000C0
#define ADI_0_RF_PACTL1_GAIN_S                                               6

// Field:   [5:0] IB
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL1_IB_W                                                 6
#define ADI_0_RF_PACTL1_IB_M                                        0x0000003F
#define ADI_0_RF_PACTL1_IB_S                                                 0

//*****************************************************************************
//
// Register: ADI_0_RF_O_PACTL2
//
//*****************************************************************************
// Field:   [7:5] RXTX
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL2_RXTX_W                                               3
#define ADI_0_RF_PACTL2_RXTX_M                                      0x000000E0
#define ADI_0_RF_PACTL2_RXTX_S                                               5

// Field:   [4:3] CM
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL2_CM_W                                                 2
#define ADI_0_RF_PACTL2_CM_M                                        0x00000018
#define ADI_0_RF_PACTL2_CM_S                                                 3

// Field:   [2:0] AD
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_PACTL2_AD_W                                                 3
#define ADI_0_RF_PACTL2_AD_M                                        0x00000007
#define ADI_0_RF_PACTL2_AD_S                                                 0

//*****************************************************************************
//
// Register: ADI_0_RF_O_RFLDO0
//
//*****************************************************************************
// Field:     [5] ATEST_I_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO0_ATEST_I_EN                                  0x00000020
#define ADI_0_RF_RFLDO0_ATEST_I_EN_M                                0x00000020
#define ADI_0_RF_RFLDO0_ATEST_I_EN_S                                         5

// Field:     [4] ATEST_V_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO0_ATEST_V_EN                                  0x00000010
#define ADI_0_RF_RFLDO0_ATEST_V_EN_M                                0x00000010
#define ADI_0_RF_RFLDO0_ATEST_V_EN_S                                         4

// Field:     [3] BYPASS_REG_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO0_BYPASS_REG_EN                               0x00000008
#define ADI_0_RF_RFLDO0_BYPASS_REG_EN_M                             0x00000008
#define ADI_0_RF_RFLDO0_BYPASS_REG_EN_S                                      3

// Field:     [2] RDY_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO0_RDY_EN                                      0x00000004
#define ADI_0_RF_RFLDO0_RDY_EN_M                                    0x00000004
#define ADI_0_RF_RFLDO0_RDY_EN_S                                             2
#define ADI_0_RF_RFLDO0_RDY_EN_EN                                   0x00000004
#define ADI_0_RF_RFLDO0_RDY_EN_DIS                                  0x00000000

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// DIS                      Internal. Only to be used through TI provided API.
// EN                       Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO0_BIAS_DIS                                    0x00000002
#define ADI_0_RF_RFLDO0_BIAS_DIS_M                                  0x00000002
#define ADI_0_RF_RFLDO0_BIAS_DIS_S                                           1
#define ADI_0_RF_RFLDO0_BIAS_DIS_DIS                                0x00000002
#define ADI_0_RF_RFLDO0_BIAS_DIS_EN                                 0x00000000

// Field:     [0] EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO0_EN                                          0x00000001
#define ADI_0_RF_RFLDO0_EN_M                                        0x00000001
#define ADI_0_RF_RFLDO0_EN_S                                                 0
#define ADI_0_RF_RFLDO0_EN_EN                                       0x00000001
#define ADI_0_RF_RFLDO0_EN_DIS                                      0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_RFLDO1
//
//*****************************************************************************
// Field:   [6:0] TRIM_OUT
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO1_TRIM_OUT_W                                           7
#define ADI_0_RF_RFLDO1_TRIM_OUT_M                                  0x0000007F
#define ADI_0_RF_RFLDO1_TRIM_OUT_S                                           0

//*****************************************************************************
//
// Register: ADI_0_RF_O_RFLDO2
//
//*****************************************************************************
// Field:   [5:3] COMP_RES
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO2_COMP_RES_W                                           3
#define ADI_0_RF_RFLDO2_COMP_RES_M                                  0x00000038
#define ADI_0_RF_RFLDO2_COMP_RES_S                                           3

// Field:   [2:0] COMP_CAP
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_RFLDO2_COMP_CAP_W                                           3
#define ADI_0_RF_RFLDO2_COMP_CAP_M                                  0x00000007
#define ADI_0_RF_RFLDO2_COMP_CAP_S                                           0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFADCCTL0
//
//*****************************************************************************
// Field:   [7:4] INT2ADJ
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL0_INT2ADJ_W                                         4
#define ADI_0_RF_IFADCCTL0_INT2ADJ_M                                0x000000F0
#define ADI_0_RF_IFADCCTL0_INT2ADJ_S                                         4

// Field:   [3:2] AAFCAP
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL0_AAFCAP_W                                          2
#define ADI_0_RF_IFADCCTL0_AAFCAP_M                                 0x0000000C
#define ADI_0_RF_IFADCCTL0_AAFCAP_S                                          2

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// DIS                      Internal. Only to be used through TI provided API.
// EN                       Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL0_BIAS_DIS                                 0x00000002
#define ADI_0_RF_IFADCCTL0_BIAS_DIS_M                               0x00000002
#define ADI_0_RF_IFADCCTL0_BIAS_DIS_S                                        1
#define ADI_0_RF_IFADCCTL0_BIAS_DIS_DIS                             0x00000002
#define ADI_0_RF_IFADCCTL0_BIAS_DIS_EN                              0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFADCLFCFG0
//
//*****************************************************************************
// Field:   [7:4] FF1ADJ
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCLFCFG0_FF1ADJ_W                                        4
#define ADI_0_RF_IFADCLFCFG0_FF1ADJ_M                               0x000000F0
#define ADI_0_RF_IFADCLFCFG0_FF1ADJ_S                                        4

// Field:   [3:0] INT3ADJ
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCLFCFG0_INT3ADJ_W                                       4
#define ADI_0_RF_IFADCLFCFG0_INT3ADJ_M                              0x0000000F
#define ADI_0_RF_IFADCLFCFG0_INT3ADJ_S                                       0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFADCLFCFG1
//
//*****************************************************************************
// Field:   [7:4] FF3ADJ
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCLFCFG1_FF3ADJ_W                                        4
#define ADI_0_RF_IFADCLFCFG1_FF3ADJ_M                               0x000000F0
#define ADI_0_RF_IFADCLFCFG1_FF3ADJ_S                                        4

// Field:   [3:0] FF2ADJ
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCLFCFG1_FF2ADJ_W                                        4
#define ADI_0_RF_IFADCLFCFG1_FF2ADJ_M                               0x0000000F
#define ADI_0_RF_IFADCLFCFG1_FF2ADJ_S                                        0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFADCDAC
//
//*****************************************************************************
// Field:     [7] MODE
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// RTZ                      Internal. Only to be used through TI provided API.
// NRTZ                     Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCDAC_MODE                                      0x00000080
#define ADI_0_RF_IFADCDAC_MODE_M                                    0x00000080
#define ADI_0_RF_IFADCDAC_MODE_S                                             7
#define ADI_0_RF_IFADCDAC_MODE_RTZ                                  0x00000080
#define ADI_0_RF_IFADCDAC_MODE_NRTZ                                 0x00000000

// Field:   [6:1] TRIM
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCDAC_TRIM_W                                             6
#define ADI_0_RF_IFADCDAC_TRIM_M                                    0x0000007E
#define ADI_0_RF_IFADCDAC_TRIM_S                                             1

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFADCQUANT0
//
//*****************************************************************************
// Field:     [3] AUTOCAL_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCQUANT0_AUTOCAL_EN                             0x00000008
#define ADI_0_RF_IFADCQUANT0_AUTOCAL_EN_M                           0x00000008
#define ADI_0_RF_IFADCQUANT0_AUTOCAL_EN_S                                    3

// Field:   [2:0] TH
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCQUANT0_TH_W                                            3
#define ADI_0_RF_IFADCQUANT0_TH_M                                   0x00000007
#define ADI_0_RF_IFADCQUANT0_TH_S                                            0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFADCCTL1
//
//*****************************************************************************
// Field:   [7:5] DITHERTRIM
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL1_DITHERTRIM_W                                      3
#define ADI_0_RF_IFADCCTL1_DITHERTRIM_M                             0x000000E0
#define ADI_0_RF_IFADCCTL1_DITHERTRIM_S                                      5

// Field:     [4] ADCIEN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL1_ADCIEN                                   0x00000010
#define ADI_0_RF_IFADCCTL1_ADCIEN_M                                 0x00000010
#define ADI_0_RF_IFADCCTL1_ADCIEN_S                                          4
#define ADI_0_RF_IFADCCTL1_ADCIEN_EN                                0x00000010
#define ADI_0_RF_IFADCCTL1_ADCIEN_DIS                               0x00000000

// Field:     [3] ADCQEN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL1_ADCQEN                                   0x00000008
#define ADI_0_RF_IFADCCTL1_ADCQEN_M                                 0x00000008
#define ADI_0_RF_IFADCCTL1_ADCQEN_S                                          3
#define ADI_0_RF_IFADCCTL1_ADCQEN_EN                                0x00000008
#define ADI_0_RF_IFADCCTL1_ADCQEN_DIS                               0x00000000

// Field:   [2:1] DITHEREN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// ENG                      Internal. Only to be used through TI provided API.
// ENSD                     Internal. Only to be used through TI provided API.
// ENS                      Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL1_DITHEREN_W                                        2
#define ADI_0_RF_IFADCCTL1_DITHEREN_M                               0x00000006
#define ADI_0_RF_IFADCCTL1_DITHEREN_S                                        1
#define ADI_0_RF_IFADCCTL1_DITHEREN_ENG                             0x00000006
#define ADI_0_RF_IFADCCTL1_DITHEREN_ENSD                            0x00000004
#define ADI_0_RF_IFADCCTL1_DITHEREN_ENS                             0x00000002
#define ADI_0_RF_IFADCCTL1_DITHEREN_DIS                             0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFADCCTL2
//
//*****************************************************************************
// Field:     [7] RESETN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// DIS                      Internal. Only to be used through TI provided API.
// EN                       Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL2_RESETN                                   0x00000080
#define ADI_0_RF_IFADCCTL2_RESETN_M                                 0x00000080
#define ADI_0_RF_IFADCCTL2_RESETN_S                                          7
#define ADI_0_RF_IFADCCTL2_RESETN_DIS                               0x00000080
#define ADI_0_RF_IFADCCTL2_RESETN_EN                                0x00000000

// Field:     [6] CLKGENEN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL2_CLKGENEN                                 0x00000040
#define ADI_0_RF_IFADCCTL2_CLKGENEN_M                               0x00000040
#define ADI_0_RF_IFADCCTL2_CLKGENEN_S                                        6
#define ADI_0_RF_IFADCCTL2_CLKGENEN_EN                              0x00000040
#define ADI_0_RF_IFADCCTL2_CLKGENEN_DIS                             0x00000000

// Field:     [5] ADCDIGCLKEN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL2_ADCDIGCLKEN                              0x00000020
#define ADI_0_RF_IFADCCTL2_ADCDIGCLKEN_M                            0x00000020
#define ADI_0_RF_IFADCCTL2_ADCDIGCLKEN_S                                     5
#define ADI_0_RF_IFADCCTL2_ADCDIGCLKEN_EN                           0x00000020
#define ADI_0_RF_IFADCCTL2_ADCDIGCLKEN_DIS                          0x00000000

// Field:     [1] INVCLKOUT
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFADCCTL2_INVCLKOUT                                0x00000002
#define ADI_0_RF_IFADCCTL2_INVCLKOUT_M                              0x00000002
#define ADI_0_RF_IFADCCTL2_INVCLKOUT_S                                       1
#define ADI_0_RF_IFADCCTL2_INVCLKOUT_EN                             0x00000002
#define ADI_0_RF_IFADCCTL2_INVCLKOUT_DIS                            0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFALDO1
//
//*****************************************************************************
// Field:     [4] ERR_AMP_ZERO_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO1_ERR_AMP_ZERO_EN                            0x00000010
#define ADI_0_RF_IFALDO1_ERR_AMP_ZERO_EN_M                          0x00000010
#define ADI_0_RF_IFALDO1_ERR_AMP_ZERO_EN_S                                   4
#define ADI_0_RF_IFALDO1_ERR_AMP_ZERO_EN_EN                         0x00000010
#define ADI_0_RF_IFALDO1_ERR_AMP_ZERO_EN_DIS                        0x00000000

// Field:     [3] BYPASS_REG_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO1_BYPASS_REG_EN                              0x00000008
#define ADI_0_RF_IFALDO1_BYPASS_REG_EN_M                            0x00000008
#define ADI_0_RF_IFALDO1_BYPASS_REG_EN_S                                     3

// Field:     [2] RDY_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO1_RDY_EN                                     0x00000004
#define ADI_0_RF_IFALDO1_RDY_EN_M                                   0x00000004
#define ADI_0_RF_IFALDO1_RDY_EN_S                                            2
#define ADI_0_RF_IFALDO1_RDY_EN_EN                                  0x00000004
#define ADI_0_RF_IFALDO1_RDY_EN_DIS                                 0x00000000

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// DIS                      Internal. Only to be used through TI provided API.
// EN                       Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO1_BIAS_DIS                                   0x00000002
#define ADI_0_RF_IFALDO1_BIAS_DIS_M                                 0x00000002
#define ADI_0_RF_IFALDO1_BIAS_DIS_S                                          1
#define ADI_0_RF_IFALDO1_BIAS_DIS_DIS                               0x00000002
#define ADI_0_RF_IFALDO1_BIAS_DIS_EN                                0x00000000

// Field:     [0] EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO1_EN                                         0x00000001
#define ADI_0_RF_IFALDO1_EN_M                                       0x00000001
#define ADI_0_RF_IFALDO1_EN_S                                                0
#define ADI_0_RF_IFALDO1_EN_EN                                      0x00000001
#define ADI_0_RF_IFALDO1_EN_DIS                                     0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFALDO2
//
//*****************************************************************************
// Field:   [7:5] COMP_CAP
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO2_COMP_CAP_W                                          3
#define ADI_0_RF_IFALDO2_COMP_CAP_M                                 0x000000E0
#define ADI_0_RF_IFALDO2_COMP_CAP_S                                          5

// Field:   [4:0] TRIM_OUT
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO2_TRIM_OUT_W                                          5
#define ADI_0_RF_IFALDO2_TRIM_OUT_M                                 0x0000001F
#define ADI_0_RF_IFALDO2_TRIM_OUT_S                                          0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFALDO3
//
//*****************************************************************************
// Field:     [4] ATEST_V_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO3_ATEST_V_EN                                 0x00000010
#define ADI_0_RF_IFALDO3_ATEST_V_EN_M                               0x00000010
#define ADI_0_RF_IFALDO3_ATEST_V_EN_S                                        4

// Field:     [3] ATEST_I_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO3_ATEST_I_EN                                 0x00000008
#define ADI_0_RF_IFALDO3_ATEST_I_EN_M                               0x00000008
#define ADI_0_RF_IFALDO3_ATEST_I_EN_S                                        3

// Field:   [2:0] COMP_RES
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFALDO3_COMP_RES_W                                          3
#define ADI_0_RF_IFALDO3_COMP_RES_M                                 0x00000007
#define ADI_0_RF_IFALDO3_COMP_RES_S                                          0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFDLDO1
//
//*****************************************************************************
// Field:     [3] BYPASS_REG_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO1_BYPASS_REG_EN                              0x00000008
#define ADI_0_RF_IFDLDO1_BYPASS_REG_EN_M                            0x00000008
#define ADI_0_RF_IFDLDO1_BYPASS_REG_EN_S                                     3
#define ADI_0_RF_IFDLDO1_BYPASS_REG_EN_EN                           0x00000008
#define ADI_0_RF_IFDLDO1_BYPASS_REG_EN_DIS                          0x00000000

// Field:     [2] RDY_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO1_RDY_EN                                     0x00000004
#define ADI_0_RF_IFDLDO1_RDY_EN_M                                   0x00000004
#define ADI_0_RF_IFDLDO1_RDY_EN_S                                            2
#define ADI_0_RF_IFDLDO1_RDY_EN_EN                                  0x00000004
#define ADI_0_RF_IFDLDO1_RDY_EN_DIS                                 0x00000000

// Field:     [1] BIAS_DIS
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// DIS                      Internal. Only to be used through TI provided API.
// EN                       Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO1_BIAS_DIS                                   0x00000002
#define ADI_0_RF_IFDLDO1_BIAS_DIS_M                                 0x00000002
#define ADI_0_RF_IFDLDO1_BIAS_DIS_S                                          1
#define ADI_0_RF_IFDLDO1_BIAS_DIS_DIS                               0x00000002
#define ADI_0_RF_IFDLDO1_BIAS_DIS_EN                                0x00000000

// Field:     [0] EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO1_EN                                         0x00000001
#define ADI_0_RF_IFDLDO1_EN_M                                       0x00000001
#define ADI_0_RF_IFDLDO1_EN_S                                                0
#define ADI_0_RF_IFDLDO1_EN_EN                                      0x00000001
#define ADI_0_RF_IFDLDO1_EN_DIS                                     0x00000000

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFDLDO2
//
//*****************************************************************************
// Field:   [7:5] COMP_CAP
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO2_COMP_CAP_W                                          3
#define ADI_0_RF_IFDLDO2_COMP_CAP_M                                 0x000000E0
#define ADI_0_RF_IFDLDO2_COMP_CAP_S                                          5

// Field:   [4:0] TRIM_OUT
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO2_TRIM_OUT_W                                          5
#define ADI_0_RF_IFDLDO2_TRIM_OUT_M                                 0x0000001F
#define ADI_0_RF_IFDLDO2_TRIM_OUT_S                                          0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFDLDO3
//
//*****************************************************************************
// Field:     [4] ATEST_V_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO3_ATEST_V_EN                                 0x00000010
#define ADI_0_RF_IFDLDO3_ATEST_V_EN_M                               0x00000010
#define ADI_0_RF_IFDLDO3_ATEST_V_EN_S                                        4
#define ADI_0_RF_IFDLDO3_ATEST_V_EN_EN                              0x00000010
#define ADI_0_RF_IFDLDO3_ATEST_V_EN_DIS                             0x00000000

// Field:     [3] ATEST_I_EN
//
// Internal. Only to be used through TI provided API.
// ENUMs:
// EN                       Internal. Only to be used through TI provided API.
// DIS                      Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO3_ATEST_I_EN                                 0x00000008
#define ADI_0_RF_IFDLDO3_ATEST_I_EN_M                               0x00000008
#define ADI_0_RF_IFDLDO3_ATEST_I_EN_S                                        3
#define ADI_0_RF_IFDLDO3_ATEST_I_EN_EN                              0x00000008
#define ADI_0_RF_IFDLDO3_ATEST_I_EN_DIS                             0x00000000

// Field:   [2:0] COMP_RES
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFDLDO3_COMP_RES_W                                          3
#define ADI_0_RF_IFDLDO3_COMP_RES_M                                 0x00000007
#define ADI_0_RF_IFDLDO3_COMP_RES_S                                          0

//*****************************************************************************
//
// Register: ADI_0_RF_O_IFAMPCTL3
//
//*****************************************************************************
// Field:   [6:4] AAF_CAP_EN
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL3_AAF_CAP_EN_W                                      3
#define ADI_0_RF_IFAMPCTL3_AAF_CAP_EN_M                             0x00000070
#define ADI_0_RF_IFAMPCTL3_AAF_CAP_EN_S                                      4

// Field:   [3:0] IB
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_IFAMPCTL3_IB_W                                              4
#define ADI_0_RF_IFAMPCTL3_IB_M                                     0x0000000F
#define ADI_0_RF_IFAMPCTL3_IB_S                                              0

//*****************************************************************************
//
// Register: ADI_0_RF_O_STAT
//
//*****************************************************************************
// Field:   [7:3] IFADC_CALVAL_OUT
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_STAT_IFADC_CALVAL_OUT_W                                     5
#define ADI_0_RF_STAT_IFADC_CALVAL_OUT_M                            0x000000F8
#define ADI_0_RF_STAT_IFADC_CALVAL_OUT_S                                     3

// Field:     [2] IFADC_CALDONE
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_STAT_IFADC_CALDONE                                 0x00000004
#define ADI_0_RF_STAT_IFADC_CALDONE_M                               0x00000004
#define ADI_0_RF_STAT_IFADC_CALDONE_S                                        2

// Field:     [1] IFLDOS_RDY
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_STAT_IFLDOS_RDY                                    0x00000002
#define ADI_0_RF_STAT_IFLDOS_RDY_M                                  0x00000002
#define ADI_0_RF_STAT_IFLDOS_RDY_S                                           1

// Field:     [0] RF_LDO
//
// Internal. Only to be used through TI provided API.
#define ADI_0_RF_STAT_RF_LDO                                        0x00000001
#define ADI_0_RF_STAT_RF_LDO_M                                      0x00000001
#define ADI_0_RF_STAT_RF_LDO_S                                               0


#endif // __ADI_0_RF__
