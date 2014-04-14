//*****************************************************************************
//
// gprcm.h - Prototypes and macros for the GPRCM driver.
//
// Copyright (C) 2013 Texas Instruments Incorporated
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

#ifndef __GPRCM_H__
#define __GPRCM_H__

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
//
//*****************************************************************************
#define GPRCM_RST_CAUSE_OFF_HIB     0x00000000
#define GPRCM_RST_CAUSE_LPDS        0x00000001
#define GPRCM_RST_CAUSE_APPS_RST    0x00000003
#define GPRCM_RST_CAUSE_APPS_SS_RST 0x00000004
#define GPRCM_RST_CAUSE_WDT_RST     0x00000005
#define GPRCM_RST_CAUSE_MCU_RST     0x00000006

//*****************************************************************************
// Values that is can be passed to GprcmLPDSWkupSrcGet() or 
// returned from GprcmLPDSWkupSrcGet
//*****************************************************************************
#define GPRCM_LPDS_WKUP_SRC_HOST_IRQ  0x00000080
#define GPRCM_LPDS_WKUP_SRC_NWP_WKUP  0x00000040
#define GPRCM_LPDS_WKUP_SRC_NWP_REQ   0x00000020
#define GPRCM_LPDS_WKUP_SRC_GPIO      0x00000010
#define GPRCM_LPDS_WKUP_SRC_TIMER     0x00000001


//*****************************************************************************
// Values thatcan be passed to GprcmSramDslpRetEnable(), 
// GprcmSramDslpRetDisable, GprcmSramLpdsRetEnable() and  
// GprcmSramLpdsRetDisable()
//*****************************************************************************
#define SRAM_COL_1     0x1
#define SRAM_COL_2     0x2
#define SRAM_COL_3     0x4
#define SRAM_COL_4     0x8

//*****************************************************************************
// Macro to convert millisecond to clocks
//*****************************************************************************  
#define GprcmLpdsMsecToClocks(MilliSec)  ((32768*MilliSec)/1000))

  
//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void GprcmAppsSSRst(void);
extern void GprcmAppsRst(void);
extern void GprcmNwpRst(void);
extern void GprcmMcuGlobalRst(void);
extern void GprcmSramDslpRetEnable(unsigned long ulBitMap);
extern void GprcmSramDslpRetDisable(unsigned long ulBitMap);
extern void GprcmSramLpdsRetEnable(unsigned long ulBitMap);
extern void GprcmSramLpdsRetDisable(unsigned long ulBitMap);
extern unsigned long GprcmAppsRstCauseGet(void);
extern unsigned long GprcmLPDSWkupSrcGet(void);
extern void GprcmLPDSWkupSrcSet(unsigned long ulWkupSrc);
extern void GprcmLPDSWkupTimeSet(unsigned long ulTimeInClocks);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __GPRCM_API_H__
