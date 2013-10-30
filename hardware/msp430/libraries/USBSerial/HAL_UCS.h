/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/*******************************************************************************
 *
 * HAL_UCS.h
 * Provides Functions to Initialize the UCS/FLL and clock sources
 * 
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/ 
 * 
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 * Created: Version 1.0 11/24/2009
 * Updated: Version 2.0 12/15/2010
 *          Added Functions: XT2_Stop() and XT1_Stop()
 *  
 ******************************************************************************/

#ifndef HAL_UCS_H
#define HAL_UCS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include "HAL_MACROS.h"

/*******************************************************************************
 * Macros
 ******************************************************************************/

/* Select source for FLLREF  e.g. SELECT_FLLREF(SELREF__XT1CLK) */
#define SELECT_FLLREF(source) st(UCSCTL3 = (UCSCTL3 & ~(SELREF_7)) | (source);) 
/* Select source for ACLK    e.g. SELECT_ACLK(SELA__XT1CLK) */
#define SELECT_ACLK(source)   st(UCSCTL4 = (UCSCTL4 & ~(SELA_7))   | (source);) 
/* Select source for MCLK    e.g. SELECT_MCLK(SELM__XT2CLK) */
#define SELECT_MCLK(source)   st(UCSCTL4 = (UCSCTL4 & ~(SELM_7))   | (source);) 
/* Select source for SMCLK   e.g. SELECT_SMCLK(SELS__XT2CLK) */
#define SELECT_SMCLK(source)  st(UCSCTL4 = (UCSCTL4 & ~(SELS_7))   | (source);) 
/* Select source for MCLK and SMCLK e.g. SELECT_MCLK_SMCLK(SELM__DCOCLK + SELS__DCOCLK) */
#define SELECT_MCLK_SMCLK(sources) st(UCSCTL4 = (UCSCTL4 & ~(SELM_7 + SELS_7)) | (sources);)

/* set ACLK/x */
#define ACLK_DIV(x)         st(UCSCTL5 = (UCSCTL5 & ~(DIVA_7)) | (DIVA__##x);)     
/* set MCLK/x */
#define MCLK_DIV(x)         st(UCSCTL5 = (UCSCTL5 & ~(DIVM_7)) | (DIVM__##x);)     
/* set SMCLK/x */
#define SMCLK_DIV(x)        st(UCSCTL5 = (UCSCTL5 & ~(DIVS_7)) | (DIVS__##x);)     
/* Select divider for FLLREF  e.g. SELECT_FLLREFDIV(2) */
#define SELECT_FLLREFDIV(x) st(UCSCTL3 = (UCSCTL3 & ~(FLLREFDIV_7))|(FLLREFDIV__##x);) 

/*******************************************************************************
 * Defines
 ******************************************************************************/
#define UCS_STATUS_OK     0
#define UCS_STATUS_ERROR  1

/*******************************************************************************
 * \brief   Startup routine for 32kHz Crystal on LFXT1
 *
 * \param xtdrive   Bits defining the LFXT drive mode after startup
 ******************************************************************************/
extern void LFXT_Start(uint16_t xtdrive);

/*******************************************************************************
 * \brief   Startup routine for 32kHz Crystal on LFXT1 with timeout counter
 *
 * \param xtdrive   Bits defining the LFXT drive mode after startup
 * \param timeout   Value for the timeout counter
 ******************************************************************************/
extern uint16_t LFXT_Start_Timeout(uint16_t xtdrive, uint16_t timeout);

/*******************************************************************************
 * \brief   Startup routine for XT1
 *
 * \param xtdrive   Bits defining the XT drive mode
 ******************************************************************************/
extern void XT1_Start(uint16_t xtdrive);

/*******************************************************************************
 * \brief   Startup routine for XT1 with timeout counter
 *
 * \param xtdrive   Bits defining the XT drive mode
 * \param timeout   Value for the timeout counter
 ******************************************************************************/
extern uint16_t XT1_Start_Timeout(uint16_t xtdrive, uint16_t timeout);

/*******************************************************************************
 * \brief   Use XT1 in Bypasss mode
 ******************************************************************************/
extern void XT1_Bypass(void);

/*******************************************************************************
 * \brief   Stop XT1 oscillator
 ******************************************************************************/
extern void XT1_Stop(void);

/*******************************************************************************
 * \brief   Startup routine for XT2
 *
 * \param xtdrive   Bits defining the XT drive mode
 ******************************************************************************/
extern void XT2_Start(uint16_t xtdrive);

/*******************************************************************************
 * \brief   Startup routine for XT2 with timeout counter
 *
 * \param xtdrive   Bits defining the XT drive mode
 * \param timeout   Value for the timeout counter
 ******************************************************************************/
extern uint16_t XT2_Start_Timeout(uint16_t xtdrive, uint16_t timeout);

/*******************************************************************************
 * \brief   Use XT2 in Bypasss mode for MCLK
 ******************************************************************************/
extern void XT2_Bypass(void);

/*******************************************************************************
 * \brief   Stop XT2 oscillator
 ******************************************************************************/
extern void XT2_Stop(void);

/*******************************************************************************
 * \brief   Initializes FLL of the UCS and wait till settled before allowing
 *          code execution to resume. The use of this function is preferred
 *          over the use of Init_FLL().
 *
 * \param fsystem  Required system frequency (MCLK) in kHz
 * \param ratio    Ratio between fsystem and FLLREFCLK
 ******************************************************************************/
extern void Init_FLL_Settle(uint16_t fsystem, uint16_t ratio);

/*******************************************************************************
 * \brief   Initializes FLL of the UCS
 *
 * \param fsystem  Required system frequency (MCLK) in kHz
 * \param ratio    Ratio between fsystem and FLLREFCLK
 ******************************************************************************/
extern void Init_FLL(uint16_t fsystem, uint16_t ratio);

#ifdef __cplusplus
}
#endif
#endif /* HAL_UCS_H */
