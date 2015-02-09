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
#include "crc32.h"
#include <msp.h>
#include <debug.h>

void CRC32_setSeed(uint32_t seed, uint_fast8_t crcType)
{
    ASSERT((CRC16_MODE == crcType) || (CRC32_MODE == crcType));

    if (CRC16_MODE == crcType)
        CRC32->rCRC16INIRES = seed;
    else
    {
        CRC32->rCRC32INIRES_HI = ((seed & 0xFFFF0000) >> 16);
        CRC32->rCRC32INIRES_LO = (seed & 0xFFFF);
    }
}

void CRC32_set8BitData(uint8_t dataIn, uint_fast8_t crcType)
{
    ASSERT((CRC16_MODE == crcType) || (CRC32_MODE == crcType));

    if (CRC16_MODE == crcType)
        HWREG8(CRC32_BASE + OFS_CRC16DI) = dataIn;
    else
        HWREG8(CRC32_BASE + OFS_CRC32DI) = dataIn;
}

void CRC32_set16BitData(uint16_t dataIn, uint_fast8_t crcType)
{
    ASSERT((CRC16_MODE == crcType) || (CRC32_MODE == crcType));

    if (CRC16_MODE == crcType)
        CRC32->rCRC16DI = dataIn;
    else
        CRC32->rCRC32DI = dataIn;
}

void CRC32_set32BitData(uint32_t dataIn)
{
    //CRC32->rCRC32DI = dataIn & 0xFFFF;
    //CRC32->rCRC32DI = (uint16_t) ((dataIn & 0xFFFF0000) >> 16);

    HWREG16(CRC32_BASE + OFS_CRC32DI) = dataIn & 0xFFFF;
    HWREG16(CRC32_BASE + OFS_CRC32DI) = (uint16_t)(
            (dataIn & 0xFFFF0000) >> 16);
}

void CRC32_set8BitDataReversed(uint8_t dataIn, uint_fast8_t crcType)
{
    ASSERT((CRC16_MODE == crcType) || (CRC32_MODE == crcType));

    if (CRC16_MODE == crcType)
        HWREG8(CRC32_BASE + OFS_CRC16DIRB) = dataIn;
    else
        HWREG8(CRC32_BASE + OFS_CRC32DIRB) = dataIn;
}

void CRC32_set16BitDataReversed(uint16_t dataIn, uint_fast8_t crcType)
{
    ASSERT((CRC16_MODE == crcType) || (CRC32_MODE == crcType));

    if (CRC16_MODE == crcType)
        CRC32->rCRC16DIRB = dataIn;
    else
        CRC32->rCRC32DIRB = dataIn;
}

void CRC32_set32BitDataReversed(uint32_t dataIn)
{
    HWREG16(CRC32_BASE + OFS_CRC32DIRB) = dataIn & 0xFFFF;
    HWREG16(CRC32_BASE + OFS_CRC32DIRB) = (uint16_t)(
            (dataIn & 0xFFFF0000) >> 16);
    //CRC32->rCRC32DIRB = dataIn & 0xFFFF;
    //CRC32->rCRC32DIRB = (uint16_t) ((dataIn & 0xFFFF0000) >> 16);
}

uint32_t CRC32_getResult(uint_fast8_t crcType)
{
    uint32_t result;
    ASSERT((CRC16_MODE == crcType) || (CRC32_MODE == crcType));

    if (CRC16_MODE == crcType)
        return CRC32->rCRC16INIRES;
    else
    {
        result = CRC32->rCRC32INIRES_HI;
        result = (result << 16);
        result |= CRC32->rCRC32INIRES_LO;
        return (result);
    }
}

uint32_t CRC32_getResultReversed(uint_fast8_t crcType)
{
    uint32_t result;
    ASSERT((CRC16_MODE == crcType) || (CRC32_MODE == crcType));

    if (CRC16_MODE == crcType)
        return CRC32->rCRC16RESR;
    else
    {
        result = CRC32->rCRC32RESR_HI;
        result = (result << 16);
        result |= CRC32->rCRC32RESR_LO;
        return (result);
    }
}

