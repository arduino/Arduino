/*
 * -------------------------------------------
 *    MSP432 DriverLib - v01_04_00_18 
 * -------------------------------------------
 *
 * --COPYRIGHT--,BSD,BSD
 * Copyright (c) 2015, Texas Instruments Incorporated
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
#include <reset.h>
#include <debug.h>

void ResetCtl_initiateSoftReset(void)
{
    RSTCTL->rRESET_REQ.r |= (RESET_KEY | RESET_SOFT_RESET);
}

void ResetCtl_initiateSoftResetWithSource(uint32_t source)
{
    RSTCTL->rSOFTRESET_SET.r |= (source);
}

uint32_t ResetCtl_getSoftResetSource(void)
{
    return RSTCTL->rSOFTRESET_STAT.r;
}

void ResetCtl_clearSoftResetSource(uint32_t mask)
{
    RSTCTL->rSOFTRESET_CLR.r |= mask;
}

void ResetCtl_initiateHardReset(void)
{
    RSTCTL->rRESET_REQ.r |= (RESET_KEY | RESET_HARD_RESET);
}

void ResetCtl_initiateHardResetWithSource(uint32_t source)
{
    RSTCTL->rHARDRESET_SET.r |= (source);
}

uint32_t ResetCtl_getHardResetSource(void)
{
    return RSTCTL->rHARDRESET_STAT.r;
}

void ResetCtl_clearHardResetSource(uint32_t mask)
{
    RSTCTL->rHARDRESET_CLR.r |= mask;
}

uint32_t ResetCtl_getPSSSource(void)
{
    return RSTCTL->rPSSRESET_STAT.r;
}

void ResetCtl_clearPSSFlags(void)
{
    RSTCTL->rPSSRESET_CLR.r |= RSTCTL_PSSRESET_CLR_CLR;
}

uint32_t ResetCtl_getPCMSource(void)
{
    return RSTCTL->rPCMRESET_STAT.r;
}

void ResetCtl_clearPCMFlags(void)
{
    RSTCTL->rPCMRESET_CLR.r |= RSTCTL_PCMRESET_CLR_CLR;
}

