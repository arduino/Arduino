//*****************************************************************************
//
// gprcm.c - Driver for the GPRCM module.
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

//*****************************************************************************
//
//! \addtogroup GPRCM_Global_Power_Reset_Clock_Module_api
//! @{
//
//*****************************************************************************

#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gprcm.h"
#include "inc/hw_types.h"
#include "debug.h"
#include "interrupt.h"
#include "gprcm.h"

//*****************************************************************************
//
//*****************************************************************************
#define GPRCM_BASE OCP_GPRCM_BASE

//*****************************************************************************
//
//! Reset the Apps cortex and associated peripherals.
//!
//! This function resets the Apps cortex and associated pheriperals.
//!
//! \return None.
//
//*****************************************************************************
void GprcmAppsSSRst()
{
  //
  // Reset Apps and associated peripheral
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) |= 0x2;
}

//*****************************************************************************
//
//! Reset the Apps cortex.
//!
//! This function resets only the Apps cortex.
//!
//! \return None.
//
//*****************************************************************************
void GprcmAppsRst()
{
  //
  // Reset Apps cortex only
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) |= 0x1;
}

//*****************************************************************************
//
//! Reset the NWP subsystem
//!
//!
//! This function resets NWP subsystem.
//!
//! \return None.
//
//*****************************************************************************
void GprcmNwpRst()
{
  unsigned long ulDelay;
  
  //
  // Assert NWP subsystem reset
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) |= 0x4;
  
  //
  // Delay loop
  //
  for(ulDelay =0; ulDelay < 5000; ulDelay++)
  {
      
  }
  
  //
  // De-assert NWP subsystem reset
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) &= ~0x4;
  
}

//*****************************************************************************
//
//! Reset the Apps cortex, NWP and there associated peripherals.
//!
//! This function resets Apps cortex, NWP and there associated peripherals.
//!
//! \return None.
//
//*****************************************************************************
void GprcmMcuGlobalRst()
{
  //
  // Reset MCU
  //
  HWREG(GPRCM_BASE+ GPRCM_O_MCU_GLOBAL_SOFT_RESET) |= 0x1;

}

//*****************************************************************************
//
//! Enable SRAM coloumn retention in DSLP 
//!
//! \param ulBitMap specifies which SRAM columns to be retained.
//!
//! This function enables SRAM retention for specified column 
//! during deep-sleep
//!
//! The parameter \e ulBitMap should be logical OR of one or more of the
//! following:
//! - \b SRAM_COL_1
//! - \b SRAM_COL_2
//! - \b SRAM_COL_3
//! - \b SRAM_COL_4
//!
//! \return None.
//
//*****************************************************************************
void GprcmSramDslpRetEnable(unsigned long ulBitMap)
{
  //
  // Configure the register
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_DSLP_CFG) = ulBitMap;
}

//*****************************************************************************
//
//! Disable SRAM coloumn retention in DSLP 
//!
//! \param ulBitMap specifies which SRAM coloumns not to be retained.
//!
//! This function disables SRAM retention for specified column 
//! during deep-sleep
//!
//! The parameter \e ulBitMap should be logical OR of one or more of the
//! following:
//! - \b SRAM_COL_1
//! - \b SRAM_COL_2
//! - \b SRAM_COL_3
//! - \b SRAM_COL_4
//!
//! \return None.
//
//*****************************************************************************
void GprcmSramDslpRetDisable(unsigned long ulBitMap)
{
  //
  // Configure the register
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_DSLP_CFG) &= ~ulBitMap;
}

//*****************************************************************************
//
//! Enable SRAM coloumn retention in LPDS
//!
//! Enable SRAM coloumn retention in DSLP 
//!
//! \param ulBitMap specifies which SRAM columns to be retained.
//!
//! This function enables SRAM retention for specified column 
//! during LPDS
//!
//! The parameter \e ulBitMap should be logical OR of one or more of the
//! following:
//! - \b SRAM_COL_1
//! - \b SRAM_COL_2
//! - \b SRAM_COL_3
//! - \b SRAM_COL_4
//!
//! \return None.
//!
//
//*****************************************************************************
void GprcmSramLpdsRetEnable(unsigned long ulBitMap)
{
  //
  // Configure the register
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_LPDS_CFG) = ulBitMap;
}

//*****************************************************************************
//
//! Disable SRAM coloumn retention in LPDS
//!
//! Enable SRAM coloumn retention in DSLP 
//!
//! \param ulBitMap specifies which SRAM columns not to be retained.
//!
//! This function disable SRAM retention for specified column 
//! during LPDS
//!
//! The parameter \e ulBitMap should be logical OR of one or more of the
//! following:
//! - \b SRAM_COL_1
//! - \b SRAM_COL_2
//! - \b SRAM_COL_3
//! - \b SRAM_COL_4
//!
//! \return None.
//
//*****************************************************************************
void GprcmSramLpdsRetDisable(unsigned long ulBitMap)
{
  //
  // Configure the register
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_LPDS_CFG) &= ~ulBitMap;
}

//*****************************************************************************
//
//! Get Apps reset cause
//!
//!
//! Use this function to get the cause for apps reset. The function returns one
//! the following macro
//!
//! -\b GPRCM_RST_CAUSE_OFF_HIB
//! -\b GPRCM_RST_CAUSE_LPDS
//! -\b GPRCM_RST_CAUSE_APPS_RST
//! -\b GPRCM_RST_CAUSE_APPS_SS_RST
//! -\b GPRCM_RST_CAUSE_WDT_RST
//! -\b GPRCM_RST_CAUSE_MCU_RST
//!
//! \return the read value
//
//*****************************************************************************
unsigned long GprcmAppsRstCauseGet()
{
  return(HWREG(GPRCM_BASE+ GPRCM_O_APPS_RESET_CAUSE));
}

//*****************************************************************************
//
//! Get LPDS wakeup source
//!
//! Use this function to get the cause that wokeup ths apps from LPDS.The
//! returns one of the following macro
//!
//! -\b GPRCM_LPDS_WKUP_SRC_HOST_IRQ
//! -\b GPRCM_LPDS_WKUP_SRC_NWP_REQ
//! -\b GPRCM_LPDS_WKUP_SRC_NWP_WKUP
//! -\b GPRCM_LPDS_WKUP_SRC_GPIO
//! -\b GPRCM_LPDS_WKUP_SRC_TIMER
//!
//! \return None.
//
//*****************************************************************************
unsigned long GprcmLPDSWkupSrcGet()
{
  return (HWREG(GPRCM_BASE+ GPRCM_O_APPS_LPDS_WAKEUP_SRC));
}

//*****************************************************************************
//
//! Set LPDS wakeup source
//!
//! Use this function to get the cause that wakeup ths apps from LPDS.The
//! returns one of the following macro
//!
//! -\b GPRCM_LPDS_WKUP_SRC_HOST_IRQ
//! -\b GPRCM_LPDS_WKUP_SRC_NWP_REQ
//! -\b GPRCM_LPDS_WKUP_SRC_NWP_WKUP
//! -\b GPRCM_LPDS_WKUP_SRC_GPIO
//! -\b GPRCM_LPDS_WKUP_SRC_TIMER
//!
//! \return None.
//
//*****************************************************************************
void GprcmLPDSWkupSrcSet(unsigned long ulWkupSrc)
{
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_LPDS_WAKEUP_CFG) = ulWkupSrc;
}

//*****************************************************************************
//
//! Configures LPDS Timer
//!
//! \param ulTimeInClocks is number of 32.768 Khz clocks
//!
//! This function configures LPDS wakeup timer. To specify the wake up time in
//! milli second use GprcmLpdsMsecToClocks() macro 
//!
//! The parameter \e ulTimeInClocks can range from 21 to 2^32
//!
//! \return None.
//
//*****************************************************************************
void GprcmLPDSWkupTimeSet(unsigned long ulTimeInClocks)
{
  //
  // Check sleep is atleast for 21 cycles
  // If not set the sleep time to 21 cycles
  //
  if( ulTimeInClocks < 21)
  {
      ulTimeInClocks = 21;
  }
  
  HWREG(GPRCM_BASE + GPRCM_O_APPS_LPDS_WAKETIME_WAKE_CFG) = ulTimeInClocks;
  HWREG(GPRCM_BASE + GPRCM_O_APPS_LPDS_WAKETIME_OPP_CFG) = ulTimeInClocks-20;
}




