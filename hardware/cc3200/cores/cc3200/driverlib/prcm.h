//*****************************************************************************
//
// prcm.h - Prototypes for the PRCM control driver.
//
// Copyright (C); 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

#ifndef __PRCM_H__
#define __PRCM_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
// Values that can be passed to PRCMPeripheralEnable() and
// PRCMPeripheralDisable()
//*****************************************************************************
#define PRCM_RUN_MODE_CLK         0x00000001
#define PRCM_SLP_MODE_CLK         0x00000100
#define PRCM_DSLP_MODE_CLK        0x00010000

//*****************************************************************************
// Values that can be passed to PRCMSRAMRetentionEnable() and
// PRCMSRAMRetentionDisable() as ulSramColSel.
//*****************************************************************************
#define PRCM_SRAM_COL_1 0x00000001
#define PRCM_SRAM_COL_2 0x00000002
#define PRCM_SRAM_COL_3 0x00000003
#define PRCM_SRAM_COL_4 0x00000008

//*****************************************************************************
// Values that can be passed to PRCMSRAMRetentionEnable() and
// PRCMSRAMRetentionDisable() as ulModeFlags.
//*****************************************************************************
#define PRCM_SRAM_DSLP_RET 0x00000001
#define PRCM_SRAM_LPDS_RET 0x00000002

//*****************************************************************************
// Values that can be passed to PRCMLPDSWakeupSourceEnable(),
// PRCMLPDSWakeupCauseGet() and PRCMLPDSWakeupSourceDisable().
//*****************************************************************************
#define PRCM_LPDS_HOST_IRQ  0x00000080
#define PRCM_LPDS_GPIO      0x00000010
#define PRCM_LPDS_TIMER     0x00000001

//*****************************************************************************
// Values that can be passed to PRCMLPDSWakeUpGPIOSelect() as Type
//*****************************************************************************  
#define PRCM_LPDS_LOW_LEVEL  0x00000002
#define PRCM_LPDS_HIGH_LEVEL 0x00000000
#define PRCM_LPDS_FALL_EDGE  0x00000001
#define PRCM_LPDS_RISE_EDGE  0x00000003

//*****************************************************************************
// Values that can be passed to PRCMLPDSWakeUpGPIOSelect()
//*****************************************************************************  
#define PRCM_LPDS_GPIO2     0x00000000
#define PRCM_LPDS_GPIO4     0x00000001
#define PRCM_LPDS_GPIO13    0x00000002
#define PRCM_LPDS_GPIO17    0x00000003
#define PRCM_LPDS_GPIO11    0x00000004
#define PRCM_LPDS_GPIO24    0x00000005
#define PRCM_LPDS_GPIO26    0x00000006
  
//*****************************************************************************
// Values that can be passed to PRCMHibernateWakeupSourceEnable(),
// PRCMHibernateWakeupSourceDisable().
//*****************************************************************************
#define PRCM_HIB_RTC        0x00000001
#define PRCM_HIB_GPIO       0x007F0000
  
//*****************************************************************************
// Values that can be passed to PRCMHibernateWakeUpGPIOSelect() as ulType
//*****************************************************************************
#define PRCM_HIB_LOW_LEVEL  0x00000000
#define PRCM_HIB_HIGH_LEVEL 0x00000001
#define PRCM_HIB_FALL_EDGE  0x00000002
#define PRCM_HIB_RISE_EDGE  0x00000003

//*****************************************************************************
// Values that can be passed to PRCMHibernateWakeUpGPIOSelect() 
//*****************************************************************************
#define PRCM_HIB_GPIO2     0x00000001
#define PRCM_HIB_GPIO4     0x00000002
#define PRCM_HIB_GPIO13    0x00000004
#define PRCM_HIB_GPIO17    0x00000008
#define PRCM_HIB_GPIO11    0x00000010
#define PRCM_HIB_GPIO24    0x00000020
#define PRCM_HIB_GPIO26    0x00000040

//*****************************************************************************
// Values that will be returned from PRCMSysResetCauseGet().
//*****************************************************************************
#define PRCM_POWER_ON    0x00000000
#define PRCM_LPDS_EXIT   0x00000001
#define PRCM_CORE_RESET  0x00000003
#define PRCM_MCU_RESET   0x00000004
#define PRCM_WDT_RESET   0x00000005
#define PRCM_SOC_RESET   0x00000006
#define PRCM_HIB_EXIT    0x00000007

//*****************************************************************************
// Values that can be passed to PRCMHibernateWakeupCauseGet().
//*****************************************************************************
#define PRCM_HIB_WAKEUP_CAUSE_SLOW_CLOCK  0x00000002
#define PRCM_HIB_WAKEUP_CAUSE_GPIO        0x00000004

//*****************************************************************************
// Values that can be passed to PRCMSEnableInterrupt
//*****************************************************************************
#define PRCM_INT_RTC            0x00000001

//*****************************************************************************
// Values that can be passed to PRCMPeripheralClkEnable(),
// PRCMPeripheralClkDisable(), PRCMPeripheralReset()
//*****************************************************************************
#define PRCM_CAMERA  0x00000000
#define PRCM_MCASP   0x00000001
#define PRCM_SDHOST  0x00000002
#define PRCM_GSPI    0x00000003
#define PRCM_LSPI    0x00000004
#define PRCM_UDMA    0x00000005
#define PRCM_GPIOA0  0x00000006
#define PRCM_GPIOA1  0x00000007
#define PRCM_GPIOA2  0x00000008
#define PRCM_GPIOA3  0x00000009
#define PRCM_WDT     0x0000000A
#define PRCM_UARTA0  0x0000000B
#define PRCM_UARTA1  0x0000000C
#define PRCM_TIMERA0 0x0000000D
#define PRCM_TIMERA1 0x0000000E
#define PRCM_TIMERA2 0x0000000F
#define PRCM_TIMERA3 0x00000010
#define PRCM_DTHE    0x00000011
#define PRCM_SSPI    0x00000012
#define PRCM_I2CA0   0x00000013
  
//*****************************************************************************
//
// Peripheral clock and reset control registers
//
//*****************************************************************************
typedef struct _PRCM_PeripheralRegs_
{

unsigned long ulClkReg;
unsigned long ulRstReg;

}PRCM_PeriphRegs_t;

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void PRCMSOCReset(void);
extern void PRCMMCUReset(tBoolean bIncludeSubsystem);
extern unsigned long PRCMSysResetCauseGet(void);

extern void PRCMPeripheralClkEnable(unsigned long ulPeripheral, 
                                    unsigned long ulClkFlags);
extern void PRCMPeripheralClkDisable(unsigned long ulPeripheral, 
                                     unsigned long ulClkFlags);
extern void PRCMPeripheralReset(unsigned long ulPeripheral);
extern tBoolean PRCMPeripheralStatusGet(unsigned long ulPeripheral);

extern void PRCMNWPEnable(void);
extern void PRCMNWPDisable(void);

extern void PRCMMcASPClockInputSet(unsigned long ulMcASPClkIn);
extern unsigned long PRCMPeripheralClockGet(unsigned long ulPeripheral);

extern void PRCMSleepEnter(void);
extern void PRCMDeepSleepEnter(void);

extern void PRCMSRAMRetentionEnable(unsigned long ulSramColSel, 
                                    unsigned long ulFlags);
extern void PRCMSRAMRetentionDisable(unsigned long ulSramColSel, 
                                     unsigned long ulFlags);

extern void PRCMLPDSEnter(void);
extern tBoolean PRCMLPDSIntervalSet(unsigned long ulTicks);
extern void PRCMLPDSWakeupSourceEnable(unsigned long ulLpdsWakeupSrc);
extern unsigned long PRCMLPDSWakeupCauseGet(void);
extern void PRCMLPDSWakeUpGPIOSelect(unsigned long ulGPIOPin, 
                                     unsigned long ulType);
extern void PRCMLPDSWakeupSourceDisable(unsigned long ulLpdsWakeupSrc);

extern void PRCMHibernateEnter(void);
extern void PRCMHibernateWakeupSourceEnable(unsigned long ulHIBWakupSrc);
extern unsigned long PRCMHibernateWakeupCauseGet(void);
extern void PRCMHibernateWakeUpGPIOSelect(unsigned long ulMultiGPIOBitMap, 
                                          unsigned long ulType);
extern void PRCMHibernateWakeupSourceDisable(unsigned long ulHIBWakupSrc);
extern tBoolean PRCMHibernateIntervalSet(unsigned long long ullTicks);

extern unsigned long long PRCMRTCGet(void);
extern void PRCMRTCMatchSet(unsigned long long ullTicks);

extern void PRCMOCRRegisterWrite(unsigned char ucIndex, 
                                 unsigned long ulRegValue);
extern unsigned long PRCMOCRRegisterRead(unsigned char ucIndex);

extern void PRCMIntRegister(void (*pfnHandler)(void));
extern void PRCMIntUnregister(void);
extern void PRCMIntEnable(unsigned long ulIntFlags);
extern void PRCMIntDisable(unsigned long ulIntFlags);
extern unsigned long PRCMIntStatus(void);


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //  __PRCM_H__
