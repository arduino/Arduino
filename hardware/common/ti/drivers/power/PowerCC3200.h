/*
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
 */
/*
 *  ======== PowerCC3200.h ========
 *
 */

#ifndef ti_drivers_power_PowerCC3200__include
#define ti_drivers_power_PowerCC3200__include

#include <stdint.h>
#include <ti/drivers/ports/ListP.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! latency times in microseconds */
#define PowerCC3200_RESUMETIMEDEEPSLEEP     1000
#define PowerCC3200_RESUMETIMELPDS          13000
#define PowerCC3200_TOTALTIMEDEEPSLEEP      2000
#define PowerCC3200_TOTALTIMELPDS           20000
#define PowerCC3200_TOTALTIMESHUTDOWN       500000
#define PowerCC3200_WAKEDELAYDEEPSLEEP      1000

/*! Power resources */
#define PowerCC3200_PERIPH_CAMERA           0
#define PowerCC3200_PERIPH_I2S              1
#define PowerCC3200_PERIPH_SDHOST           2
#define PowerCC3200_PERIPH_GSPI             3
#define PowerCC3200_PERIPH_LSPI             4
#define PowerCC3200_PERIPH_UDMA             5
#define PowerCC3200_PERIPH_GPIOA0           6
#define PowerCC3200_PERIPH_GPIOA1           7
#define PowerCC3200_PERIPH_GPIOA2           8
#define PowerCC3200_PERIPH_GPIOA3           9
#define PowerCC3200_PERIPH_WDT              10
#define PowerCC3200_PERIPH_UARTA0           11
#define PowerCC3200_PERIPH_UARTA1           12
#define PowerCC3200_PERIPH_TIMERA0          13
#define PowerCC3200_PERIPH_TIMERA1          14
#define PowerCC3200_PERIPH_TIMERA2          15
#define PowerCC3200_PERIPH_TIMERA3          16
#define PowerCC3200_PERIPH_DTHE             17
#define PowerCC3200_PERIPH_SSPI             18
#define PowerCC3200_PERIPH_I2CA0            19
#define PowerCC3200_NUMRESOURCES            20

/*!
 *  @brief  Power constraints on the CC3200 device
 *
 *  Each constraint must be a power of two and must be sequential
 *  without any gaps.
 */
#define PowerCC3200_DS_DISALLOW             0x1
#define PowerCC3200_LPDS_DISALLOW           0x2
#define PowerCC3200_SD_DISALLOW             0x4
#define PowerCC3200_NUMCONSTRAINTS          3

/*!
 *  @brief  Power events on the CC3200 device
 *
 *  Each event must be a power of two and must be sequential
 *  without any gaps.
 */
#define PowerCC3200_ENTERING_DEEPSLEEP      0x1
#define PowerCC3200_ENTERING_LPDS           0x2
#define PowerCC3200_ENTERING_SHUTDOWN       0x4
#define PowerCC3200_AWAKE_DEEPSLEEP         0x8
#define PowerCC3200_AWAKE_LPDS              0x10
#define PowerCC3200_NUMEVENTS               5

/*! Power sleep states */
#define PowerCC3200_DEEPSLEEP               0x1
#define PowerCC3200_LPDS                    0x2

/*! @brief Power global configuration */
typedef struct PowerCC3200_Config {
    /*! Init function for power policy */
    Power_PolicyInitFxn policyInitFxn;
    /*! The power policy function */
    Power_PolicyFxn policyFxn;
    /*! Hook function called when entering LPDS mode */
    void (*enterLPDSHookFxn)(void);
    /*! Hook function called when resuming from LPDS mode */
    void (*resumeLPDSHookFxn)(void);
    /*! Determines whether to run the power policy function */
    bool runPolicy;
    /*! Enable GPIO as a wakeup source for LPDS */
    bool enableGPIOWakeupLPDS;
    /*! Enable GPIO as a wakeup source for shutdown */
    bool enableGPIOWakeupShutdown;
    /*! Enable Network activity as a wakeup source for LPDS */
    bool enableNetworkWakeupLPDS;
    /*! The GPIO source for wakeup from LPDS */
    uint32_t wakeupGPIOSourceLPDS;
    /*! The GPIO trigger type for wakeup from LPDS */
    uint32_t wakeupGPIOTypeLPDS;
    /*! The GPIO sources for wakeup from shutdown */
    uint32_t wakeupGPIOSourceShutdown;
    /*! The GPIO trigger type for wakeup from shutdown */
    uint32_t wakeupGPIOTypeShutdown;
    /*! time in microseconds before waking up from shutdown */
    uint32_t wakeupShutdownTime;
    /*! SRAM retention mask for LPDS */
    uint32_t ramRetentionMaskLPDS;
} PowerCC3200_Config;

/*! Module_State */
typedef struct PowerCC3200_Module_State {
    ListP_List notifyList;
    uint32_t constraintMask;
    uint32_t state;
    uint16_t dbRecords[PowerCC3200_NUMRESOURCES];
    uint8_t refCount[PowerCC3200_NUMRESOURCES];
    uint8_t constraintCounts[PowerCC3200_NUMCONSTRAINTS];
} PowerCC3200_Module_State;

/*! NVIC registers that need to be save on entering LPDS */
typedef struct PowerCC3200_NVIC_Registers {
    /*! Vector Table Offset */
    uint32_t vectorTable;
    /*! Auxiliary control register */
    uint32_t auxCtrl;
    /*! Interrupt Control and State */
    uint32_t intCtrlState;
    /*! Application Interrupt Reset control */
    uint32_t appInt;
    /*! System control */
    uint32_t sysCtrl;
    /*! Configuration control */
    uint32_t configCtrl;
    /*! System Handler Priority 1 */
    uint32_t sysPri1;
    /*! System Handler Priority 2 */
    uint32_t sysPri2;
    /*! System Handler Priority 3 */
    uint32_t sysPri3;
    /*! System Handler control and state register */
    uint32_t sysHcrs;
    /*! SysTick Control Status */
    uint32_t systickCtrl;
    /*! SysTick Reload */
    uint32_t systickReload;
    /*! SysTick Calibration */
    uint32_t systickCalib;
    /*! Interrupt set enablea */
    uint32_t intSetEn[6];
    /*! Interrupt prioritya */
    uint32_t intPriority[49];
} PowerCC3200_NVIC_Registers;

/*! M4 core registers that need to be save on entering LPDS */
typedef struct PowerCC3200_M4_Registers {
    uint32_t msp;
    uint32_t psp;
    uint32_t psr;
    uint32_t primask;
    uint32_t faultmask;
    uint32_t basepri;
    uint32_t control;
} PowerCC3200_M4_Registers;

/*! struct of context registers to save on entering LPDS */
typedef struct PowerCC3200_SaveRegisters {
    PowerCC3200_M4_Registers m4Regs;
    PowerCC3200_NVIC_Registers nvicRegs;
} PowerCC3200_SaveRegisters;

/*! default init function for config structure */
void Power_init(void);

/*! default power policy for config structure */
void PowerCC3200_sleepPolicy(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_PowerCC3200_PowerCC3200__include */
