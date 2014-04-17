//*****************************************************************************
//
// arcm.h - Prototypes for the system control driver.
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

#ifndef __ARCM_H__
#define __ARCM_H__

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
// ARCM peripheral register structure
//
//*****************************************************************************
typedef struct ArcmPeripheralRegs
{

unsigned long ClkGatingReg;
unsigned long SoftResetReg;

}ArcmPeripheralRegs_t;


//*****************************************************************************
//
// ArcmPeripherals_t type enum
//
//*****************************************************************************
typedef enum ArcmPeripherals
{
	ARCM_CAMERA,     	/* Perip ID  0  */
	ARCM_MCASP,
	ARCM_MMCHS,
	ARCM_MCSPIA1,
	ARCM_MCSPIA2,
	ARCM_UDMA,
	ARCM_GPIOS0,
	ARCM_GPIOS1,
	ARCM_GPIOS2,
	ARCM_GPIOS3,
	ARCM_GPIOS4,
	ARCM_WDT,
	ARCM_UARTA0,
	ARCM_UARTA1,
	ARCM_TIMERA0,
	ARCM_TIMERA1,
	ARCM_TIMERA2,
	ARCM_TIMERA3,
	ARCM_DTHE,
	ARCM_EPI,
	ARCM_MCSPIS0,
	ARCM_I2CS0
}ArcmPeripherals_t;


//*****************************************************************************
// Value that can be passed to ArcmSlpWakeupSrcSet() and 
// ArcmdSlpWakeupSrcSet() 
//*****************************************************************************
#define ARCM_WAKEUP_SRC_NWP   0x00000002
#define ARCM_WAKEUP_SRC_TIMER 0x00000001
#define ARCM_WAKEUP_SRC_NONE  0x00000000

//*****************************************************************************
// Value returned from ArcmWakeupStatusGet() 
//*****************************************************************************
#define ARCM_DSLP_TIMER_WAKEUP 0x00000008
#define ARCM_SLP_TIMER_WAKEUP  0x00000004
#define ARCM_DSLP_NWP_WAKEUP   0x00000002
#define ARCM_SLP_NWP_WAKEUP    0x00000001


//*****************************************************************************
// Value that can be passed to ArcmMcSPIClockSet()
//***************************************************************************** 
#define ARCM_MCSPI_CLK_SRC_PLL  0x00010000
#define ARCM_MCSPI_CLK_SRC_XTAL 0x00000000

//*****************************************************************************
// Macro to convert millisecond to clocks
//*****************************************************************************
#define ArcmDslpMsecToClocks(MilliSec)  ((40000000*MilliSec)/1000))

//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void ArcmPeripheralReset(ArcmPeripherals_t ePeripheral);
extern void ArcmPeripheralEnable(ArcmPeripherals_t ulPeripheral);
extern void ArcmPeripheralDisable(ArcmPeripherals_t ulPeripheral);
extern void ArcmPeripheralSlpEnable(ArcmPeripherals_t ePeripheral );
extern void ArcmPeripheralSlpDisable(ArcmPeripherals_t ePeripheral );
extern void ArcmPeripheralDSlpEnable(ArcmPeripherals_t ePeripheral );
extern void ArcmPeripheralDSlpDisable(ArcmPeripherals_t ePeripheral );
extern void ArcmPeripheralClkConfig(ArcmPeripherals_t ePeripheral,
                               unsigned long ulOnTime,unsigned long ulOffTime);
extern tBoolean ArcmPeripheralReady(ArcmPeripherals_t ePeripheral);
extern void ArcmSlpWakeupSrcSet(unsigned long ulWakeupSrc);
extern void ArcmSlpWakeupTimerConfig(unsigned long ulTimeInClocks);
extern void ArcmDSlpWakeupSrcSet(unsigned long ulWakeupSrc);
extern void ArcmDSlpWakeupTimerConfig(unsigned long ulTimeInClocks);
extern void ArcmRqstNwpWakeup(void);
extern unsigned long ArcmWakeupStatusGet(void);
extern void ArcmMcAspFracDivReset(void);
extern void ArcmMcAspFracDivSet(float Divider);
extern float ArcmMcAspFracDivGet(void);
extern void ArcmMcSPIClkSrcSet(ArcmPeripherals_t ePeripheral,
                                                       unsigned long ulSrcClk);
extern long ArcmMcSPIClkSrcGet(ArcmPeripherals_t ePeripheral);
extern void ArcmLpdsEnter(void);
extern void ArcmDslpEnter(void);
extern void ArcmSlpEnter(void);
extern unsigned long ArcmPeripheralClkGet(ArcmPeripherals_t ePeripheral);

#ifdef __cplusplus
}
#endif


#endif // __ARCM_API_H__
