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
#include <stdbool.h>

/* DriverLib Includes */
#include <sysctl.h>
#include <debug.h>

#ifdef DEBUG

static bool SysCtlSRAMBankValid(uint8_t sramBank)
{
    return(
            sramBank == SYSCTL_SRAM_BANK7 ||
            sramBank == SYSCTL_SRAM_BANK6 ||
            sramBank == SYSCTL_SRAM_BANK5 ||
            sramBank == SYSCTL_SRAM_BANK4 ||
            sramBank == SYSCTL_SRAM_BANK3 ||
            sramBank == SYSCTL_SRAM_BANK2 ||
            sramBank == SYSCTL_SRAM_BANK1
    );
}

static bool SysCtlSRAMBankValidRet(uint8_t sramBank)
{
    sramBank &= ~(SYSCTL_SRAM_BANK7 & SYSCTL_SRAM_BANK6 &
            SYSCTL_SRAM_BANK5 & SYSCTL_SRAM_BANK4 &
            SYSCTL_SRAM_BANK3 & SYSCTL_SRAM_BANK2 &
            SYSCTL_SRAM_BANK1);

    return (sramBank == 0);
}

static bool SysCtlPeripheralIsValid (uint16_t hwPeripheral)
{
    hwPeripheral &= ~(SYSCTL_PERIPH_DMA & SYSCTL_PERIPH_WDT &
            SYSCTL_PERIPH_ADC & SYSCTL_PERIPH_EUSCIB3 &
            SYSCTL_PERIPH_EUSCIB2 & SYSCTL_PERIPH_EUSCIB1 &
            SYSCTL_PERIPH_EUSCIB0 & SYSCTL_PERIPH_EUSCIA3 &
            SYSCTL_PERIPH_EUSCIA2 & SYSCTL_PERIPH_EUSCIA1 &
            SYSCTL_PERIPH_EUSCIA0 & SYSCTL_PERIPH_TIMER32_0_MODULE &
            SYSCTL_PERIPH_TIMER16_3 & SYSCTL_PERIPH_TIMER16_2 &
            SYSCTL_PERIPH_TIMER16_2 & SYSCTL_PERIPH_TIMER16_1 &
            SYSCTL_PERIPH_TIMER16_0);

    return (hwPeripheral == 0);
}
#endif

uint_least32_t SysCtl_getSRAMSize(void)
{
    return SYSCTL->rSRAM_SIZE;
}

uint_least32_t SysCtl_getFlashSize(void)
{
    return SYSCTL->rFLASH_SIZE;
}

void SysCtl_disableNMISource(uint_fast8_t flags)
{
    SYSCTL->rNMI_CTLSTAT.r &= ~(flags);
}

void SysCtl_enableNMISource(uint_fast8_t flags)
{
    SYSCTL->rNMI_CTLSTAT.r |= flags;
}

uint_fast8_t SysCtl_getNMISourceStatus(void)
{
    return SYSCTL->rNMI_CTLSTAT.r;
}

void SysCtl_enableSRAMBank(uint_fast8_t sramBank)
{
    ASSERT(SysCtlSRAMBankValid(sramBank));

    /* Waiting for SRAM Ready Bit to be set */
    while (!SYSCTL->rSRAM_BANKEN.b.bSRAM_RDY)
        ;

    SYSCTL->rSRAM_BANKEN.r = (sramBank | SYSCTL_SRAM_BANKEN_BNK0_EN);
}

void SysCtl_disableSRAMBank(uint_fast8_t sramBank)
{
    ASSERT(SysCtlSRAMBankValid(sramBank));

    /* Waiting for SRAM Ready Bit to be set */
    while (!SYSCTL->rSRAM_BANKEN.b.bSRAM_RDY)
        ;      

    switch (sramBank)
    {
    case SYSCTL_SRAM_BANK7:
        sramBank = SYSCTL_SRAM_BANK6 +  SYSCTL_SRAM_BANK5 + SYSCTL_SRAM_BANK4
                        + SYSCTL_SRAM_BANK3 + SYSCTL_SRAM_BANK2 
                        + SYSCTL_SRAM_BANK1;
        break;
    case SYSCTL_SRAM_BANK6:
        sramBank =   SYSCTL_SRAM_BANK5 + SYSCTL_SRAM_BANK4
                        + SYSCTL_SRAM_BANK3 + SYSCTL_SRAM_BANK2 
                        + SYSCTL_SRAM_BANK1;
        break;
    case SYSCTL_SRAM_BANK5:
        sramBank =   SYSCTL_SRAM_BANK4 + SYSCTL_SRAM_BANK3  
                + SYSCTL_SRAM_BANK2 + SYSCTL_SRAM_BANK1;
        break;
    case SYSCTL_SRAM_BANK4:
        sramBank =   SYSCTL_SRAM_BANK3 + SYSCTL_SRAM_BANK2 
                        + SYSCTL_SRAM_BANK1;
        break;
    case SYSCTL_SRAM_BANK3:
        sramBank =   SYSCTL_SRAM_BANK2 + SYSCTL_SRAM_BANK1;
        break;
    case SYSCTL_SRAM_BANK2:
        sramBank = SYSCTL_SRAM_BANK1;
        break;
    case SYSCTL_SRAM_BANK1:
        sramBank = 0;
        break;
    default:
        return;
    }

    SYSCTL->rSRAM_BANKEN.r = (sramBank | SYSCTL_SRAM_BANKEN_BNK0_EN);
}

void SysCtl_enableSRAMBankRetention(uint_fast8_t sramBank)
{
    ASSERT(SysCtlSRAMBankValidRet(sramBank));

    /* Waiting for SRAM Ready Bit to be set */
    while (!SYSCTL->rSRAM_BANKRET.b.bSRAM_RDY)
        ;

    SYSCTL->rSRAM_BANKRET.r |= sramBank;
}

void SysCtl_disableSRAMBankRetention(uint_fast8_t sramBank)
{
    ASSERT(SysCtlSRAMBankValidRet(sramBank));

    /* Waiting for SRAM Ready Bit to be set */
    while (!SYSCTL->rSRAM_BANKRET.b.bSRAM_RDY)
        ;

    SYSCTL->rSRAM_BANKRET.r &= ~sramBank;
}

void SysCtl_rebootDevice(void)
{
    SYSCTL->rREBOOT_CTL.r = (SYSCTL_REBOOT_CTL_REBOOT | SYSCTL_REBOOT_KEY);
}

void SysCtl_enablePeripheralAtCPUHalt(uint_fast16_t devices)
{
    ASSERT(SysCtlPeripheralIsValid(devices));
    SYSCTL->rPERIHALT_CTL.r &= ~devices;
}

void SysCtl_disablePeripheralAtCPUHalt(uint_fast16_t devices)
{
    ASSERT(SysCtlPeripheralIsValid(devices));
    SYSCTL->rPERIHALT_CTL.r |= devices;
}

void SysCtl_setWDTTimeoutResetType(uint_fast8_t resetType)
{
    if (resetType)
        SYSCTL->rWDTRESET_CTL.r |=
                SYSCTL_WDTRESET_CTL_TIMEOUT;
    else
        SYSCTL->rWDTRESET_CTL.r &= ~SYSCTL_WDTRESET_CTL_TIMEOUT;
}

void SysCtl_setWDTPasswordViolationResetType(uint_fast8_t resetType)
{
    ASSERT(resetType <= SYSCTL_HARD_RESET);

    if (resetType)
        SYSCTL->rWDTRESET_CTL.r |=
                SYSCTL_WDTRESET_CTL_VIOLATION;
    else
        SYSCTL->rWDTRESET_CTL.r &= ~SYSCTL_WDTRESET_CTL_VIOLATION;
}

void SysCtl_enableGlitchFilter(void)
{
    SYSCTL->rDIO_GLTFLT_CTL.r |= SYSCTL_DIO_GLTFLT_CTL_GLTCH_EN;
}

void SysCtl_disableGlitchFilter(void)
{
    SYSCTL->rDIO_GLTFLT_CTL.r &= ~SYSCTL_DIO_GLTFLT_CTL_GLTCH_EN;
}

uint_fast16_t SysCtl_getTempCalibrationConstant(uint32_t refVoltage,
        uint32_t temperature)
{
    return HWREG16(TLV_BASE + refVoltage + temperature);
}
