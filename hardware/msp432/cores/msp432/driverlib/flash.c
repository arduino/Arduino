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
/* Standard Includes */
#include <stdint.h>

/* DriverLib Includes */
#include <flash.h>
#include <debug.h>
#include <interrupt.h>
#include <msp.h>
#include <cpu.h>
#include <rom.h>
#include <sysctl.h>

/* Statics */
static const uint32_t MAX_PROGRAM_TRIES = 5;
static const uint32_t MAX_ERASE_TRIES = 50;

static uint32_t getUserFlashSector(uint32_t addr)
{
    if (addr > 0x1ffff)
    {
        addr = addr - 0x20000;
    }

    switch (addr)
    {
    case 0:
        return FLASH_SECTOR0;
    case 0x1000:
        return FLASH_SECTOR1;
    case 0x2000:
        return FLASH_SECTOR2;
    case 0x3000:
        return FLASH_SECTOR3;
    case 0x4000:
        return FLASH_SECTOR4;
    case 0x5000:
        return FLASH_SECTOR5;
    case 0x6000:
        return FLASH_SECTOR6;
    case 0x7000:
        return FLASH_SECTOR7;
    case 0x8000:
        return FLASH_SECTOR8;
    case 0x9000:
        return FLASH_SECTOR9;
    case 0xA000:
        return FLASH_SECTOR10;
    case 0xB000:
        return FLASH_SECTOR11;
    case 0xC000:
        return FLASH_SECTOR12;
    case 0xD000:
        return FLASH_SECTOR13;
    case 0xE000:
        return FLASH_SECTOR14;
    case 0xF000:
        return FLASH_SECTOR15;
    case 0x10000:
        return FLASH_SECTOR16;
    case 0x11000:
        return FLASH_SECTOR17;
    case 0x12000:
        return FLASH_SECTOR18;
    case 0x13000:
        return FLASH_SECTOR19;
    case 0x14000:
        return FLASH_SECTOR20;
    case 0x15000:
        return FLASH_SECTOR21;
    case 0x16000:
        return FLASH_SECTOR22;
    case 0x17000:
        return FLASH_SECTOR23;
    case 0x18000:
        return FLASH_SECTOR24;
    case 0x19000:
        return FLASH_SECTOR25;
    case 0x1A000:
        return FLASH_SECTOR26;
    case 0x1B000:
        return FLASH_SECTOR27;
    case 0x1C000:
        return FLASH_SECTOR28;
    case 0x1D000:
        return FLASH_SECTOR29;
    case 0x1E000:
        return FLASH_SECTOR30;
    case 0x1F000:
        return FLASH_SECTOR31;
    default:
        ASSERT(false);
        return 0;
    }
}

static bool _FlashCtl_Program8(uint32_t src, uint32_t dest)
{
    uint32_t ii;

    /* Enabling the correct verification settings  */
    FlashCtl_setProgramVerification(FLASH_REGPRE | FLASH_REGPOST);
    FlashCtl_clearProgramVerification(FLASH_BURSTPOST | FLASH_BURSTPRE);

    for(ii=0;ii<MAX_PROGRAM_TRIES;ii++)
    {
        /* Clearing flags */
        FLCTL->rCLRIFG.r |= (FLASH_PROGRAM_ERROR | FLASH_POSTVERIFY_FAILED
                | FLASH_PREVERIFY_FAILED | FLASH_WRDPRGM_COMPLETE);

        HWREG8(dest) = HWREG8(src);

        while (!(FlashCtl_getInterruptStatus() & FLASH_WRDPRGM_COMPLETE))
        {
            __no_operation();
        }

        if ((BITBAND_PERI(FLCTL->rIFG.r, FLCTL_IFG_PRG_ERR_OFS))
                || (BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r,
                        FLCTL_PRG_CTLSTAT_VER_PRE_OFS)
                        && BITBAND_PERI(FLCTL->rIFG.r,
                                FLCTL_IFG_AVPRE_OFS))
                || (BITBAND_PERI(FLCTL->rIFG.r, FLCTL_IFG_AVPST_OFS)))
        {
            if(BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_VER_PRE_OFS))
            {
                FlashCtl_clearProgramVerification(FLASH_REGPRE);
            }
        }
        else
        {
            return true;
        }
    }

    return false;

}

static bool _FlashCtl_Program32(uint32_t src, uint32_t dest)
{
    uint32_t ii;

    /* Enabling the correct verification settings  */
    FlashCtl_setProgramVerification(FLASH_REGPRE | FLASH_REGPOST);
    FlashCtl_clearProgramVerification(FLASH_BURSTPOST | FLASH_BURSTPRE);

    for(ii=0;ii<MAX_PROGRAM_TRIES;ii++)
    {
        /* Clearing flags */
        FLCTL->rCLRIFG.r |= (FLASH_PROGRAM_ERROR | FLASH_POSTVERIFY_FAILED
                | FLASH_PREVERIFY_FAILED | FLASH_WRDPRGM_COMPLETE);

        HWREG32(dest) = HWREG32(src);

        while (!(FlashCtl_getInterruptStatus() & FLASH_WRDPRGM_COMPLETE))
        {
            __no_operation();
        }

        if ((BITBAND_PERI(FLCTL->rIFG.r, FLCTL_IFG_PRG_ERR_OFS))
                || (BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r,
                        FLCTL_PRG_CTLSTAT_VER_PRE_OFS)
                        && BITBAND_PERI(FLCTL->rIFG.r,
                                FLCTL_IFG_AVPRE_OFS))
                || (BITBAND_PERI(FLCTL->rIFG.r, FLCTL_IFG_AVPST_OFS)))
        {
            if(BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_VER_PRE_OFS))
            {
                FlashCtl_clearProgramVerification(FLASH_REGPRE);
            }
        }
        else
        {
            return true;
        }
    }

    return false;

}

void FlashCtl_enableReadBuffering(uint_fast8_t memoryBank,
        uint_fast8_t accessMethod)
{
    if (memoryBank == FLASH_BANK0 && accessMethod == FLASH_DATA_READ)
        BITBAND_PERI(FLCTL->rBANK0_RDCTL.r, FLCTL_BANK0_RDCTL_BUFD_OFS) = 1;
    else if (memoryBank == FLASH_BANK1 && accessMethod == FLASH_DATA_READ)
        BITBAND_PERI(FLCTL->rBANK1_RDCTL.r, FLCTL_BANK1_RDCTL_BUFD_OFS) = 1;
    else if (memoryBank == FLASH_BANK0
            && accessMethod == FLASH_INSTRUCTION_FETCH)
        BITBAND_PERI(FLCTL->rBANK0_RDCTL.r, FLCTL_BANK0_RDCTL_BUFI_OFS) = 1;
    else if (memoryBank == FLASH_BANK1
            && accessMethod == FLASH_INSTRUCTION_FETCH)
        BITBAND_PERI(FLCTL->rBANK1_RDCTL.r, FLCTL_BANK1_RDCTL_BUFI_OFS) = 1;
    else
        ASSERT(false);
}

void FlashCtl_disableReadBuffering(uint_fast8_t memoryBank,
        uint_fast8_t accessMethod)
{
    if (memoryBank == FLASH_BANK0 && accessMethod == FLASH_DATA_READ)
        BITBAND_PERI(FLCTL->rBANK0_RDCTL.r, FLCTL_BANK0_RDCTL_BUFD_OFS) = 0;
    else if (memoryBank == FLASH_BANK1 && accessMethod == FLASH_DATA_READ)
        BITBAND_PERI(FLCTL->rBANK1_RDCTL.r, FLCTL_BANK1_RDCTL_BUFD_OFS) = 0;
    else if (memoryBank == FLASH_BANK0
            && accessMethod == FLASH_INSTRUCTION_FETCH)
        BITBAND_PERI(FLCTL->rBANK0_RDCTL.r, FLCTL_BANK0_RDCTL_BUFI_OFS) = 0;
    else if (memoryBank == FLASH_BANK1
            && accessMethod == FLASH_INSTRUCTION_FETCH)
        BITBAND_PERI(FLCTL->rBANK1_RDCTL.r, FLCTL_BANK1_RDCTL_BUFI_OFS) = 0;
    else
        ASSERT(false);
}

bool FlashCtl_unprotectSector(uint_fast8_t memorySpace, uint32_t sectorMask)
{
    switch (memorySpace)
    {
    case FLASH_MAIN_MEMORY_SPACE_BANK0:
        FLCTL->rBANK0_MAIN_WEPROT.r &= ~sectorMask;
        break;
    case FLASH_MAIN_MEMORY_SPACE_BANK1:
        FLCTL->rBANK1_MAIN_WEPROT.r &= ~sectorMask;
        break;
    case FLASH_INFO_MEMORY_SPACE_BANK0:
        ASSERT(sectorMask <= 0x04);
        FLCTL->rBANK0_INFO_WEPROT.r &= ~sectorMask;
        break;
    case FLASH_INFO_MEMORY_SPACE_BANK1:
        ASSERT(sectorMask <= 0x04);
        FLCTL->rBANK1_INFO_WEPROT.r &= ~sectorMask;
        break;

    default:
        ASSERT(false);

    }

    return !FlashCtl_isSectorProtected(memorySpace, sectorMask);
}

bool FlashCtl_protectSector(uint_fast8_t memorySpace, uint32_t sectorMask)
{
    switch (memorySpace)
    {
    case FLASH_MAIN_MEMORY_SPACE_BANK0:
        FLCTL->rBANK0_MAIN_WEPROT.r |= sectorMask;
        break;
    case FLASH_MAIN_MEMORY_SPACE_BANK1:
        FLCTL->rBANK1_MAIN_WEPROT.r |= sectorMask;
        break;
    case FLASH_INFO_MEMORY_SPACE_BANK0:
        ASSERT(sectorMask <= 0x04);
        FLCTL->rBANK0_INFO_WEPROT.r |= sectorMask;
        break;
    case FLASH_INFO_MEMORY_SPACE_BANK1:
        ASSERT(sectorMask <= 0x04);
        FLCTL->rBANK1_INFO_WEPROT.r |= sectorMask;
        break;

    default:
        ASSERT(false);

    }

    return FlashCtl_isSectorProtected(memorySpace, sectorMask);
}

bool FlashCtl_isSectorProtected(uint_fast8_t memorySpace, uint32_t sector)
{
    switch (memorySpace)
    {
    case FLASH_MAIN_MEMORY_SPACE_BANK0:
        return FLCTL->rBANK0_MAIN_WEPROT.r & sector;
    case FLASH_MAIN_MEMORY_SPACE_BANK1:
        return FLCTL->rBANK1_MAIN_WEPROT.r & sector;
    case FLASH_INFO_MEMORY_SPACE_BANK0:
        ASSERT(sector <= 0x04);
        return FLCTL->rBANK0_INFO_WEPROT.r & sector;
    case FLASH_INFO_MEMORY_SPACE_BANK1:
        ASSERT(sector <= 0x04);
        return FLCTL->rBANK1_INFO_WEPROT.r & sector;
    default:
        return false;
    }
}

bool FlashCtl_verifyMemory(void* verifyAddr, uint32_t length,
        uint_fast8_t pattern)
{
    uint32_t memoryPattern, addr, otpOffset;
    uint_fast8_t memoryType;

    ASSERT(pattern == FLASH_0_PATTERN || pattern == FLASH_1_PATTERN);

    addr = (uint32_t) verifyAddr;
    memoryPattern = (pattern == FLASH_1_PATTERN) ? 0xFFFFFFFF : 0;
    memoryType = (addr > __MAIN_MEMORY_END__) ? FLASH_INFO_SPACE : FLASH_MAIN_SPACE;

    /* Taking care of byte accesses */
    while ((addr & 0x03) && (length > 0))
    {
        if (HWREG8(addr++) != ((uint8_t) memoryPattern))
            return false;
        length--;
    }

    /* Making sure we are aligned by 128-bit address */
    while (((addr & 0x0F)) && (length > 3))
    {
        if (HWREG32(addr) != memoryPattern)
            return false;

        addr = addr + 4;
        length = length - 4;
    }

    /* Burst Verify */
    if (length > 63)
    {

        /* Setting/clearing INFO flash flags as appropriate */
        if (addr > __MAIN_MEMORY_END__)
        {
            FLCTL->rRDBRST_CTLSTAT.r = (FLCTL->rRDBRST_CTLSTAT.r
                    & ~FLCTL_RDBRST_CTLSTAT_MEM_TYPE_M)
                    | FLCTL_RDBRST_CTLSTAT_MEM_TYPE_1;
            otpOffset = 0x00200000;
        } else
        {
            FLCTL->rRDBRST_CTLSTAT.r = (FLCTL->rRDBRST_CTLSTAT.r
                    & ~FLCTL_RDBRST_CTLSTAT_MEM_TYPE_M)
                    | FLCTL_RDBRST_CTLSTAT_MEM_TYPE_0;
            otpOffset = __MAIN_MEMORY_START__;
        }

        /* Clearing any lingering fault flags  and preparing burst verify*/
        BITBAND_PERI(FLCTL->rRDBRST_CTLSTAT.r, FLCTL_RDBRST_CTLSTAT_CLR_STAT_OFS) =
                1;
        FLCTL->rRDBRST_FAILCNT.r = 0;
        FLCTL->rRDBRST_STARTADDR.r = addr - otpOffset;
        FLCTL->rRDBRST_LEN.r = (length & 0xFFFFFFF0);
        addr += FLCTL->rRDBRST_LEN.r;
        length = length & 0xF;

        /* Starting Burst Verify */
        FLCTL->rRDBRST_CTLSTAT.r = (FLCTL_RDBRST_CTLSTAT_STOP_FAIL | pattern
                | memoryType | FLCTL_RDBRST_CTLSTAT_START);

        /* While the burst read hasn't finished */
        while ((FLCTL->rRDBRST_CTLSTAT.r & FLCTL_RDBRST_CTLSTAT_BRST_STAT_M)
                != FLCTL_RDBRST_CTLSTAT_BRST_STAT_3)
        {
            __no_operation();
        }

        /* Checking  for a verification/access error/failure */
        if (BITBAND_PERI(FLCTL->rRDBRST_CTLSTAT.r,
                FLCTL_RDBRST_CTLSTAT_CMP_ERR_OFS)
                || BITBAND_PERI(FLCTL->rRDBRST_CTLSTAT.r,
                        FLCTL_RDBRST_CTLSTAT_ADDR_ERR_OFS)
                || FLCTL->rRDBRST_FAILCNT.r)
        {
            /* Clearing the Read Burst flag and returning */
            BITBAND_PERI(FLCTL->rRDBRST_CTLSTAT.r, FLCTL_RDBRST_CTLSTAT_CLR_STAT_OFS) =
                    1;
            return false;
        }

        /* Clearing the Read Burst flag */
        BITBAND_PERI(FLCTL->rRDBRST_CTLSTAT.r, FLCTL_RDBRST_CTLSTAT_CLR_STAT_OFS) =
                1;

    }

    /* Remaining Words */
    while (length > 3)
    {
        if (HWREG32(addr) != memoryPattern)
            return false;

        addr = addr + 4;
        length = length - 4;
    }

    /* Remaining Bytes */
    while (length > 0)
    {
        if (HWREG8(addr++) != ((uint8_t) memoryPattern))
            return false;
        length--;
    }

    return true;
}

bool FlashCtl_setReadMode(uint32_t flashBank, uint32_t readMode)
{

    if (FLCTL->rPOWER_STAT.r & FLCTL_POWER_STAT_RD_2T)
        return false;

    if (flashBank == FLASH_BANK0)
    {
        FLCTL->rBANK0_RDCTL.r = (FLCTL->rBANK0_RDCTL.r
                & ~FLCTL_BANK0_RDCTL_RD_MODE_M) | readMode;
        while (FLCTL->rBANK0_RDCTL.b.bRD_MODE != readMode)
            ;
    } else if (flashBank == FLASH_BANK1)
    {
        FLCTL->rBANK1_RDCTL.r = (FLCTL->rBANK1_RDCTL.r
                & ~FLCTL_BANK1_RDCTL_RD_MODE_M) | readMode;
        while (FLCTL->rBANK1_RDCTL.b.bRD_MODE != readMode)
            ;
    } else
    {
        ASSERT(false);
        return false;
    }

    return true;
}

uint32_t FlashCtl_getReadMode(uint32_t flashBank)
{
    if (flashBank == FLASH_BANK0)
    {
        return FLCTL->rBANK0_RDCTL.b.bRD_MODE;
    } else if (flashBank == FLASH_BANK1)
    {
        return FLCTL->rBANK1_RDCTL.b.bRD_MODE;
    } else
    {
        ASSERT(false);
        return 0;
    }
}

bool FlashCtl_performMassErase(void)
{
    uint32_t userFlash, ii, jj, sector;

    /* Trying a mass erase in ROM first. If it fails (should be rare), going
     * through and erasing each sector one-by-one
     */
    if (!FlashInternal_performMassErase(true))
    {
        userFlash = SysCtl_getFlashSize() / 2;

        for (ii = __MAIN_MEMORY_START__; ii < userFlash; ii += 4096)
        {
            sector = getUserFlashSector(ii);

            if (!((FLCTL->rBANK0_MAIN_WEPROT.r) & sector))
            {
                for (jj = 1; jj < MAX_ERASE_TRIES; jj++)
                {
                    if (FlashInternal_eraseSector(ii, true))
                    {
                        break;
                    }
                }

                if (jj == MAX_ERASE_TRIES)
                    return false;
            }

            if (!(FLCTL->rBANK1_MAIN_WEPROT.r & sector))
            {
                for (jj = 1; jj < MAX_ERASE_TRIES; jj++)
                {
                    if (FlashInternal_eraseSector(ii + userFlash, true))
                    {
                        break;
                    }
                }

                if (jj == MAX_ERASE_TRIES)
                    return false;
            }

            if (sector < FLCTL_BANK0_MAIN_WEPROT_PROT2)
            {
                if (!(FLCTL->rBANK0_INFO_WEPROT.r & sector))
                {
                    for (jj = 1; jj < MAX_ERASE_TRIES; jj++)
                    {
                        if (FlashInternal_eraseSector(ii + __BSL_MEMORY_START__,
                        true))
                        {
                            break;
                        }
                    }

                    if (jj == MAX_ERASE_TRIES)
                        return false;
                }

                if (!(FLCTL->rBANK1_INFO_WEPROT.r & sector))
                {

                    for (jj = 1; jj < MAX_ERASE_TRIES; jj++)
                    {

                        if (FlashInternal_eraseSector(
                                ii + __BSL_MEMORY_START__ + 0x2000, true))
                        {
                            break;
                        }
                    }

                    if (jj == MAX_ERASE_TRIES)
                        return false;
                }

            }
        }
    }

    return true;
}

bool FlashCtl_eraseSector(uint32_t addr)
{
    uint32_t ii;

    for(ii=0;ii<MAX_ERASE_TRIES;ii++)
    {
        if(FlashInternal_eraseSector(addr, true))
        {
            return true;
        }
    }

    return false;
}

bool FlashCtl_programMemory(void* src, void* dest, uint32_t length)
{
    uint32_t destAddr, srcAddr;
    bool res;

    /* Casting to integers */
    srcAddr = (uint32_t)src;
    destAddr = (uint32_t)dest;

    /* Enabling word programming */
    FlashCtl_enableWordProgramming(FLASH_IMMEDIATE_WRITE_MODE);

    /* Assume failure */
    res = false;

    /* Taking care of byte accesses */
    while ((destAddr & 0x03) && length > 0)
    {
        if(!_FlashCtl_Program8(srcAddr,destAddr))
        {
            goto FlashProgramCleanUp;
        }
        else
        {
            srcAddr++;
            destAddr++;
            length--;
        }
    }

    /* Taking care of word accesses */
    while ((destAddr & 0x0F) && (length > 3))
    {
        if (!_FlashCtl_Program32(srcAddr, destAddr))
        {
            goto FlashProgramCleanUp;
        }
        else
        {
            srcAddr += 4;
            destAddr += 4;
            length -= 4;
        }
    }

    /* Remaining byte accesses */
    while (length > 0)
    {
        if(!_FlashCtl_Program8(srcAddr,destAddr))
        {
            goto FlashProgramCleanUp;
        }
        else
        {
            srcAddr++;
            destAddr++;
            length--;
        }
    }

    /* If we got this far that means that we succeeded  */
    res = true;

FlashProgramCleanUp:
    FlashCtl_disableWordProgramming();
    return res;

}

void FlashCtl_setProgramVerification(uint32_t verificationSetting)
{
    if ((verificationSetting & FLASH_BURSTPOST))
        BITBAND_PERI(FLCTL->rPRGBRST_CTLSTAT.r, FLCTL_PRGBRST_CTLSTAT_AUTO_PST_OFS) =
                1;

    if ((verificationSetting & FLASH_BURSTPRE))
        BITBAND_PERI(FLCTL->rPRGBRST_CTLSTAT.r, FLCTL_PRGBRST_CTLSTAT_AUTO_PRE_OFS) =
                1;

    if ((verificationSetting & FLASH_REGPRE))
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_VER_PRE_OFS) = 1;

    if ((verificationSetting & FLASH_REGPOST))
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_VER_PST_OFS) = 1;
}

void FlashCtl_clearProgramVerification(uint32_t verificationSetting)
{
    if ((verificationSetting & FLASH_BURSTPOST))
        BITBAND_PERI(FLCTL->rPRGBRST_CTLSTAT.r, FLCTL_PRGBRST_CTLSTAT_AUTO_PST_OFS) =
                0;

    if ((verificationSetting & FLASH_BURSTPRE))
        BITBAND_PERI(FLCTL->rPRGBRST_CTLSTAT.r, FLCTL_PRGBRST_CTLSTAT_AUTO_PRE_OFS) =
                0;

    if ((verificationSetting & FLASH_REGPRE))
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_VER_PRE_OFS) = 0;

    if ((verificationSetting & FLASH_REGPOST))
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_VER_PST_OFS) = 0;

}

void FlashCtl_enableWordProgramming(uint32_t mode)
{
    if (mode == FLASH_IMMEDIATE_WRITE_MODE)
    {
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_ENABLE_OFS) = 1;
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_MODE_OFS) = 0;

    } else if (mode == FLASH_COLLATED_WRITE_MODE)
    {
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_ENABLE_OFS) = 1;
        BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_MODE_OFS) = 1;
    }
}

void FlashCtl_disableWordProgramming(void)
{
    BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_ENABLE_OFS) = 0;
}

uint32_t FlashCtl_isWordProgrammingEnabled(void)
{
    if (!BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_ENABLE_OFS))
    {
        return 0;
    } else if (BITBAND_PERI(FLCTL->rPRG_CTLSTAT.r, FLCTL_PRG_CTLSTAT_MODE_OFS))
        return FLASH_COLLATED_WRITE_MODE;
    else
        return FLASH_IMMEDIATE_WRITE_MODE;
}

void FlashCtl_setWaitState(uint32_t flashBank, uint32_t waitState)
{
    if (flashBank == FLASH_BANK0)
    {
        FLCTL->rBANK0_RDCTL.r =
                (FLCTL->rBANK0_RDCTL.r & ~FLCTL_BANK0_RDCTL_WAIT_M)
                        | (waitState << 12);
    } else if (flashBank == FLASH_BANK1)
    {
        FLCTL->rBANK1_RDCTL.r =
                (FLCTL->rBANK1_RDCTL.r & ~FLCTL_BANK1_RDCTL_WAIT_M)
                        | (waitState << 12);
    } else
    {
        ASSERT(false);
    }
}

uint32_t FlashCtl_getWaitState(uint32_t flashBank)
{
    if (flashBank == FLASH_BANK0)
    {
        return FLCTL->rBANK0_RDCTL.b.bWAIT;
    } else if (flashBank == FLASH_BANK1)
    {
        return FLCTL->rBANK1_RDCTL.b.bWAIT;
    } else
    {
        ASSERT(false);
        return 0;
    }
}

void FlashCtl_enableInterrupt(uint32_t flags)
{
    FLCTL->rIE.r |= flags;
}

void FlashCtl_disableInterrupt(uint32_t flags)
{
    FLCTL->rIE.r &= ~flags;
}

uint32_t FlashCtl_getInterruptStatus(void)
{
    return FLCTL->rIFG.r;
}

uint32_t FlashCtl_getEnabledInterruptStatus(void)
{
    return FlashCtl_getInterruptStatus() & FLCTL->rIE.r;
}

void FlashCtl_clearInterruptFlag(uint32_t flags)
{
    FLCTL->rCLRIFG.r |= flags;
}

void FlashCtl_registerInterrupt(void (*intHandler)(void))
{
    //
    // Register the interrupt handler, returning an error if an error occurs.
    //
    Interrupt_registerInterrupt(INT_FLCTL, intHandler);

    //
    // Enable the system control interrupt.
    //
    Interrupt_enableInterrupt(INT_FLCTL);
}

void FlashCtl_unregisterInterrupt(void)
{
    //
    // Disable the interrupt.
    //
    Interrupt_disableInterrupt(INT_FLCTL);

    //
    // Unregister the interrupt handler.
    //
    Interrupt_unregisterInterrupt(INT_FLCTL);
}

