/******************************************************************************
*  Filename:       hw_ccfg_simple_struct_h
*  Revised:        2015-03-03 09:29:52 +0100 (Tue, 03 Mar 2015)
*  Revision:       42862
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

#ifndef __HW_CCFG_SIMPLE_STRUCT_H__
#define __HW_CCFG_SIMPLE_STRUCT_H__

//*****************************************************************************
//
// Customer configuration (ccfg) typedef.
// The implementation of this struct is required by device ROM boot code
//  and must be placed at the end of flash. Do not modify this struct!
//
//*****************************************************************************
typedef struct
{                                              //  Mapped to address
    uint32_t   CCFG_EXT_LF_CLK               ; // 0x50003FA8
    uint32_t   CCFG_MODE_CONF_1              ; // 0x50003FAC
    uint32_t   CCFG_SIZE_AND_DIS_FLAGS       ; // 0x50003FB0
    uint32_t   CCFG_MODE_CONF                ; // 0x50003FB4
    uint32_t   CCFG_VOLT_LOAD_0              ; // 0x50003FB8
    uint32_t   CCFG_VOLT_LOAD_1              ; // 0x50003FBC
    uint32_t   CCFG_RTC_OFFSET               ; // 0x50003FC0
    uint32_t   CCFG_FREQ_OFFSET              ; // 0x50003FC4
    uint32_t   CCFG_IEEE_MAC_0               ; // 0x50003FC8
    uint32_t   CCFG_IEEE_MAC_1               ; // 0x50003FCC
    uint32_t   CCFG_IEEE_BLE_0               ; // 0x50003FD0
    uint32_t   CCFG_IEEE_BLE_1               ; // 0x50003FD4
    uint32_t   CCFG_BL_CONFIG                ; // 0x50003FD8
    uint32_t   CCFG_ERASE_CONF               ; // 0x50003FDC
    uint32_t   CCFG_CCFG_TI_OPTIONS          ; // 0x50003FE0
    uint32_t   CCFG_CCFG_TAP_DAP_0           ; // 0x50003FE4
    uint32_t   CCFG_CCFG_TAP_DAP_1           ; // 0x50003FE8
    uint32_t   CCFG_IMAGE_VALID_CONF         ; // 0x50003FEC
    uint32_t   CCFG_CCFG_PROT_31_0           ; // 0x50003FF0
    uint32_t   CCFG_CCFG_PROT_63_32          ; // 0x50003FF4
    uint32_t   CCFG_CCFG_PROT_95_64          ; // 0x50003FF8
    uint32_t   CCFG_CCFG_PROT_127_96         ; // 0x50003FFC
} ccfg_t;

//*****************************************************************************
//
// Define the extern ccfg structure (__ccfg)
//
//*****************************************************************************
extern const ccfg_t __ccfg;


#endif // __HW_CCFG_SIMPLE_STRUCT__
