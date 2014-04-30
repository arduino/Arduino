//*****************************************************************************
//
// prcm.c - Driver for the Power, Reset and Clock Module (PRCM)
//
// Copyright (C) 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
//  Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup PRCM_Power_Reset_Clock_Module_api
//! @{
//
//*****************************************************************************

#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_apps_rcm.h"
#include "inc/hw_gprcm.h"
#include "inc/hw_hib1p2.h"
#include "inc/hw_hib3p3.h"
#include "prcm.h"
#include "interrupt.h"
#include "cpu.h"
#include "flash.h"
#include "utils.h"


//*****************************************************************************
// Macro definition
//*****************************************************************************
#define PRCM_SOFT_RESET           0x00000001
#define PRCM_ENABLE_STATUS        0x00000002
#define SYS_CLK                   80000000
#define XTAL_CLK                  40000000

//*****************************************************************************
// Global Peripheral clock and rest Registers
//*****************************************************************************
static const PRCM_PeriphRegs_t PRCM_PeriphRegsList[] =
{

	{APPS_RCM_O_CAMERA_CLK_GATING,   APPS_RCM_O_CAMERA_SOFT_RESET   },
	{APPS_RCM_O_MCASP_CLK_GATING,    APPS_RCM_O_MCASP_SOFT_RESET    },
	{APPS_RCM_O_MMCHS_CLK_GATING,    APPS_RCM_O_MMCHS_SOFT_RESET    },
	{APPS_RCM_O_MCSPI_A1_CLK_GATING, APPS_RCM_O_MCSPI_A1_SOFT_RESET },
	{APPS_RCM_O_MCSPI_A2_CLK_GATING, APPS_RCM_O_MCSPI_A2_SOFT_RESET },
	{APPS_RCM_O_UDMA_A_CLK_GATING,   APPS_RCM_O_UDMA_A_SOFT_RESET   },
	{APPS_RCM_O_GPIO_A_CLK_GATING,   APPS_RCM_O_GPIO_A_SOFT_RESET   },
	{APPS_RCM_O_GPIO_B_CLK_GATING,   APPS_RCM_O_GPIO_B_SOFT_RESET   },
	{APPS_RCM_O_GPIO_C_CLK_GATING,   APPS_RCM_O_GPIO_C_SOFT_RESET   },
	{APPS_RCM_O_GPIO_D_CLK_GATING,   APPS_RCM_O_GPIO_D_SOFT_RESET   },
	{APPS_RCM_O_WDOG_A_CLK_GATING,   APPS_RCM_O_WDOG_A_SOFT_RESET   },
	{APPS_RCM_O_UART_A0_CLK_GATING,  APPS_RCM_O_UART_A0_SOFT_RESET  },
	{APPS_RCM_O_UART_A1_CLK_GATING,  APPS_RCM_O_UART_A1_SOFT_RESET  },
	{APPS_RCM_O_GPT_A0_CLK_GATING ,  APPS_RCM_O_GPT_A0_SOFT_RESET   },
	{APPS_RCM_O_GPT_A1_CLK_GATING,   APPS_RCM_O_GPT_A1_SOFT_RESET   },
	{APPS_RCM_O_GPT_A2_CLK_GATING,   APPS_RCM_O_GPT_A2_SOFT_RESET   },
	{APPS_RCM_O_GPT_A3_CLK_GATING,   APPS_RCM_O_GPT_A3_SOFT_RESET   },
	{APPS_RCM_O_CRYPTO_CLK_GATING,   APPS_RCM_O_CRYPTO_SOFT_RESET   },
	{APPS_RCM_O_MCSPI_S0_CLK_GATING, APPS_RCM_O_MCSPI_S0_SOFT_RESET },
	{APPS_RCM_O_I2C_CLK_GATING,      APPS_RCM_O_I2C_SOFT_RESET      }

};

//*****************************************************************************
//
//! Performs a software reset of a SOC
//!
//! This function performs a software reset of a SOC
//!
//! \return None.
//
//*****************************************************************************
void PRCMSOCReset()
{
  //
  // Reset MCU
  //
  HWREG(GPRCM_BASE+ GPRCM_O_MCU_GLOBAL_SOFT_RESET) |= 0x1;

}

//*****************************************************************************
//
//! Performs a software reset of a MCU and associated peripherals
//!
//! \param bIncludeSubsystem is \b true to reset associated peripherals.
//!
//! This function performs a software reset of a MCU and associated peripherals.
//! To reset the associated peripheral, the parameter \e bIncludeSubsystem
//! should be set to \b true.
//!
//! \return None.
//
//*****************************************************************************
void PRCMMCUReset(tBoolean bIncludeSubsystem)
{
  if(bIncludeSubsystem)
  {
    //
    // Reset Apps processor and associated peripheral
    //
    HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) = 0x2;
  }
  else
  {
    //
    // Reset Apps processor only
    //
    HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) = 0x1;
  }
}

//*****************************************************************************
//
//! Gets the reason for a reset.
//!
//! This function returns the reason(s) for a reset. The reset reason are:-
//! -\b PRCM_POWER_ON  - Device is powering up.
//! -\b PRCM_LPDS_EXIT - Device is exiting from LPDS.
//! -\b PRCM_CORE_RESET - Device is exiting soft core only reset
//! -\b PRCM_MCU_RESET - Device is exiting soft subsystem reset.
//! -\b PRCM_WDT_RESET - Device was reset by watchdog.
//! -\b PRCM_SOC_RESET - Device is exting SOC reset.
//! -\b PRCM_HIB_EXIT - Device is exiting hibernate.
//!
//! \return Returns one of the cause defined above.
//
//*****************************************************************************
unsigned long PRCMSysResetCauseGet()
{
  unsigned long ulWakeupStatus;

  //
  // Read the Reset status
  //
  ulWakeupStatus = (HWREG(GPRCM_BASE+ GPRCM_O_APPS_RESET_CAUSE) & 0xFF);

  //
  // For hibernate do additional chaeck.
  //
  if(ulWakeupStatus == PRCM_POWER_ON)
  {
    if(HWREG(HIB3P3_BASE + HIB3P3_O_MEM_HIB_WAKE_STATUS) & 0x1)
    {
      ulWakeupStatus = PRCM_HIB_EXIT;
    }
  }

  //
  // Return status.
  //
  return ulWakeupStatus;
}

//*****************************************************************************
//
//! Enable clock(s) to peripheral.
//!
//! \param ulPeripheral is one of the valid peripherals
//! \param ulClkFlags are bitmask of clock(s) to be enabled.
//!
//! This function enables the clock for the specified peripheral. Peripherals 
//! are by default clock gated (disabled) and generates a bus fault if 
//! accessed.
//!
//! The parameter \e ulClkFlags can be logical OR of the following:
//! -\b PRCM_RUN_MODE_CLK - Ungates clock to the peripheral
//! -\b PRCM_SLP_MODE_CLK - Keeps the clocks ungated in sleep.
//! -\b PRCM_DSLP_MODE_CLK - Keeps the clock ungated in deepsleep.
//!
//! \return None.
//
//*****************************************************************************
void 
PRCMPeripheralClkEnable(unsigned long ulPeripheral, unsigned long ulClkFlags)
{
  //
  // Enable the specified peripheral clocks
  //
  HWREG(ARCM_BASE + PRCM_PeriphRegsList[ulPeripheral].ulClkReg) |= ulClkFlags;
  
  //
  // Set the default clock for camera
  //
  if(ulPeripheral == PRCM_CAMERA)
  {
    HWREG(ARCM_BASE + APPS_RCM_O_CAMERA_CLK_GEN) = 0x0404;
  }
}

//*****************************************************************************
//
//! Disables clock(s) to peripheral.
//!
//! \param Peripheral is one of the valid peripherals
//! \param ulClkFlags are bitmask of clock(s) to be enabled.
//!
//! This function disable the clock for the specified peripheral. Peripherals 
//! are by default clock gated (disabled) and generated a bus fault if 
//! accessed.
//!
//! The parameter \e ulClkFlags can be logical OR bit fields as defined in
//! PRCMEnablePeripheral().
//!
//! \return None.
//
//*****************************************************************************
void 
PRCMPeripheralClkDisable(unsigned long ulPeripheral, unsigned long ulClkFlags)
{
  //
  // Disable the specified peripheral clocks
  //
  HWREG(ARCM_BASE + PRCM_PeriphRegsList[ulPeripheral].ulClkReg) &= ~ulClkFlags;
}

//*****************************************************************************
//
//! Gets the input clock for the specified peripheral.
//!
//! \param ulPeripheral is one of the valid peripherals.
//! \param ulHiPulseDiv divides the High pulse.
//! \param ulLoPulseDiv divides the Low pulse.
//!
//! This function gets the input clock for the specified peripheral.
//!
//! The parameter \e ulPeripheral has the same definition as that in 
//! PRCMPeripheralClkEnable();
//!
//! \note Not all peripherals support configuring input clock.
//!
//! \return Returns input clock frequency for specified peripheral.
//
//*****************************************************************************
unsigned long
PRCMPeripheralClockGet(unsigned long ulPeripheral)
{
  unsigned long ulClockFreq;
  unsigned long ulHiPulseDiv;
  unsigned long ulLoPulseDiv;
  
  //
  // Get the clock based on specified peripheral.
  //
  if(((ulPeripheral == PRCM_SSPI) | (ulPeripheral == PRCM_LSPI) 
            | (ulPeripheral == PRCM_GSPI)))
  {
    return XTAL_CLK;
  }
  else if(ulPeripheral == PRCM_CAMERA)
  {
    ulHiPulseDiv = ((HWREG(ARCM_BASE + APPS_RCM_O_CAMERA_CLK_GEN) >> 8) & 0x07);
    ulLoPulseDiv = (HWREG(ARCM_BASE + APPS_RCM_O_CAMERA_CLK_GEN)& 0xFF);    
  }
  else if(ulPeripheral == PRCM_SDHOST)
  {
    ulHiPulseDiv = ((HWREG(ARCM_BASE + APPS_RCM_O_MMCHS_CLK_GEN) >> 8) & 0x07);
    ulLoPulseDiv = (HWREG(ARCM_BASE + APPS_RCM_O_MMCHS_CLK_GEN)& 0xFF);
  }
  else
  {
    return SYS_CLK;
  }
  
  //
  // Compute the clock freq. from the divider value
  //
  ulClockFreq = (240000000/((ulHiPulseDiv + 1) + (ulLoPulseDiv + 1)));
  
  //
  // Return the clock rate.
  //
  return ulClockFreq;
}

//*****************************************************************************
//
//! Performs a software reset of a peripheral.
//!
//! \param ulPeripheral is one of the valid peripheral.
//! \param bAssert is \b true to assert the reset, \b false otherwise.
//!
//! This assert or deassert reset to the specified peripheral based of the
//! \e bAssert parameter.
//!
//! \return None.
//
//*****************************************************************************
void 
PRCMPeripheralReset(unsigned long ulPeripheral)
{
  volatile unsigned long ulDelay;

    //
    // Assert the reset
    //
    HWREG(ARCM_BASE + PRCM_PeriphRegsList[ulPeripheral].ulRstReg)
                                                         |= PRCM_SOFT_RESET;
    //
    // Delay for a little bit.
    //
    for(ulDelay = 0; ulDelay < 16; ulDelay++)
    {
    }
    
    //
    // Deassert the reset
    //
    HWREG(ARCM_BASE+PRCM_PeriphRegsList[ulPeripheral].ulRstReg)
                                                          &= ~PRCM_SOFT_RESET;
}

//*****************************************************************************
//
//! Determines if a peripheral is ready.
//!
//! \param ulPeripheral is one of the valid modules
//!
//! This function determines if a particular peripheral is ready to be
//! accessed. The peripheral may be in a non-ready state if it is not enabled,
//! is being held in reset, or is in the process of becoming ready after being
//! enabled or taken out of reset.
//!
//! \return Returns \b true if the  peripheral is ready, \b false otherwise.
//
//*****************************************************************************
tBoolean
PRCMPeripheralStatusGet(unsigned long ulPeripheral)
{
  unsigned long ReadyBit;

  //
  // Read the ready bit status
  //
  ReadyBit = HWREG(ARCM_BASE + PRCM_PeriphRegsList[ulPeripheral].ulRstReg);
  ReadyBit = ReadyBit & PRCM_ENABLE_STATUS;

  if (ReadyBit)
  {
    //
    // Module is ready
    //
    return(true);
  }
  else
  {
    //
    // Module is not ready
    //
    return(false);
  }
}

//*****************************************************************************
//
//! Enable NWP subsystem.
//!
//! This function enables NWP subsystem.
//!
//! \return None.
//
//*****************************************************************************
void PRCMNWPEnable()
{
  //
  // De-assert and enable NWP subsystem reset
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) &= ~0x4;
  
  //
  // Request for NWP wakeup. This is required for first time wakeup and
  // repeated writes are ignored.  
  //
  HWREG(ARCM_BASE + APPS_RCM_O_APPS_TO_NWP_WAKE_REQUEST)
    = APPS_RCM_APPS_TO_NWP_WAKE_REQUEST_APPS_TO_NWP_WAKEUP_REQUEST;
}

//*****************************************************************************
//
//! Disable NWP subsystem.
//!
//! This function disables NWP subsystem.
//!
//! \return None.
//
//*****************************************************************************
void PRCMNWPDisable()
{
  //
  // Assert NWP subsystem reset
  //
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_SOFT_RESET) |= 0x4;
}

//*****************************************************************************
//
//! Configure McASP fracactional divider
//!
//! \param ulMcASPClkIn is the required input clock for McAPS module
//!
//! This function configures McASP fracactional divider. By default this
//! divider is set to output 24 Mhz clock to McASP module.
//!
//! The minimum frequency that can be obtained by configuring this divider is
//!
//! (240000KHz/1023.99) =  234.377 KHz
//!
//! \return None.
//
//*****************************************************************************
void
PRCMMcASPClockInputSet(unsigned long ulMcASPClkIn)
{
  unsigned long long ullDiv;
  unsigned char  ucInteger;
  unsigned short usFrac;

  ullDiv = (((unsigned long long)240000000 * 65536)/ulMcASPClkIn);

  ucInteger = (ullDiv/65536);
  usFrac    = (ullDiv%65536);

  HWREG(ARCM_BASE + APPS_RCM_O_MCASP_FRAC_CLK_CONFIG0) =
    ((ucInteger & 0x3FF) << 16 | usFrac);
}

//*****************************************************************************
//
//! Puts the system into Low Power Deel Sleep (LPDS) power mode.
//!
//! This function puts the system into Low Power Deel Sleep (LPDS) power mode.
//! A call to this function never returns and the execution starts from Reset.
//!
//! \return None.
//
//*****************************************************************************
void
PRCMLPDSEnter()
{
  volatile unsigned long ulDelay;

  //
  // Check if flash exists
  //
  if(HWREG((GPRCM_BASE +
            GPRCM_O_GPRCM_EFUSE_READ_REG2) & 0x00110000) == 0x00110000)
  {

    //
    // Disable the flash
    //
    FlashDisable();
  }
  
  //
  // Disable TestPD
  //
  HWREG(0x4402E168) |= (1<<9);
  
  //
  // Set bandgap duty cycle to 1
  //
  HWREG(HIB1P2_BASE + HIB1P2_O_BGAP_DUTY_CYCLING_EXIT_CFG) = 0x1;

  //
  // Request LPDS
  //
  HWREG(ARCM_BASE + APPS_RCM_O_APPS_LPDS_REQ)
          = APPS_RCM_APPS_LPDS_REQ_APPS_LPDS_REQ;

  __asm("    nop\n"
        "    nop\n"
        "    nop\n"
        "    nop\n");

}

//*****************************************************************************
//
//! Enable the individual LPDS wakeup source(s).
//!
//! \param ulLpdsWakeupSrc is logical OR of wakeup sources.
//!
//! This function enable the individual LPDS wakeup source(s) and following
//! three wakeup sources (\e ulLpdsWakeupSrc ) are supported by the device.
//! -\b PRCM_LPDS_WKUP_HOST_IRQ
//! -\b PRCM_LPDS_WKUP_GPIO
//! -\b PRCM_LPDS_WKUP_TIMER
//!
//! \return None.
//
//*****************************************************************************
void
PRCMLPDSWakeupSourceEnable(unsigned long ulLpdsWakeupSrc)
{
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_LPDS_WAKEUP_CFG) = ulLpdsWakeupSrc;
}

//*****************************************************************************
//
//! Disable the individual LPDS wakeup source(s).
//!
//! \param ulLpdsWakeupSrc is logical OR of wakeup sources.
//!
//! This function enable the individual LPDS wakeup source(s) and following
//! three wake up sources (\e ulLpdsWakeupSrc ) are supported by the device.
//! -\b PRCM_LPDS_WKUP_HOST_IRQ
//! -\b PRCM_LPDS_WKUP_GPIO
//! -\b PRCM_LPDS_WKUP_TIMER
//!
//! \return None.
//
//*****************************************************************************
void
PRCMLPDSWakeupSourceDisable(unsigned long ulLpdsWakeupSrc)
{
  HWREG(GPRCM_BASE+ GPRCM_O_APPS_LPDS_WAKEUP_CFG) &= ~ulLpdsWakeupSrc;
}


//*****************************************************************************
//
//! Get LPDS wakeup cause
//!
//! \param ulLpdsWakeupSrc is logical OR of wakeup sources.
//!
//! This function gets LPDS wakeup caouse
//!
//! \return Returns values enumerated as described in 
//! PRCMLPDSWakeupSourceEnable().
//
//*****************************************************************************
unsigned long
PRCMLPDSWakeupCauseGet()
{
  return (HWREG(GPRCM_BASE+ GPRCM_O_APPS_LPDS_WAKEUP_SRC));
}

//*****************************************************************************
//
//! Sets LPDS wakeup Timer
//!
//! \param ulTicks is number of 32.768 KHz clocks
//!
//! This function sets internal LPDS wakeup timer running at 32.768 KHz. The 
//! timer is only configured if the parameter \e ulTicks is in valid range i.e. 
//! from 21 to 2^32.
//!
//! \return Returns \b true on success, \b false otherwise.
//
//*****************************************************************************
tBoolean 
PRCMLPDSIntervalSet(unsigned long ulTicks)
{
  //
  // Check sleep is atleast for 21 cycles
  // If not set the sleep time to 21 cycles
  //
  if( ulTicks < 21)
  {
      return(false);
  }

  HWREG(GPRCM_BASE + GPRCM_O_APPS_LPDS_WAKETIME_WAKE_CFG) = ulTicks;
  HWREG(GPRCM_BASE + GPRCM_O_APPS_LPDS_WAKETIME_OPP_CFG) = ulTicks-20;

  return(true);
}

//*****************************************************************************
//
//! Selects the GPIO for LPDS wakeup
//!
//! \param ulGPIOPin is one of the valid GPIO fro LPDS wakeup.
//! \param ulType is the wakeup trigger type.
//!
//! This function setects the wakeup GPIO for LPDS wakeup and can be 
//! used to select one out of 7 pre-defined GPIO(s).
//! 
//! The parameter \e ulLpdsGPIOSel should be one of the following:-
//! -\b PRCM_LPDS_GPIO2
//! -\b PRCM_LPDS_GPIO4
//! -\b PRCM_LPDS_GPIO13
//! -\b PRCM_LPDS_GPIO17
//! -\b PRCM_LPDS_GPIO11
//! -\b PRCM_LPDS_GPIO24
//! -\b PRCM_LPDS_GPIO26
//!
//! The parameter \e ulType sets the trigger type and can be one of the 
//! following:
//! - \b PRCM_LPDS_LOW_LEVEL
//! - \b PRCM_LPDS_HIGH_LEVEL
//! - \b PRCM_LPDS_FALL_EDGE
//! - \b PRCM_LPDS_RISE_EDGE
//!
//! \return None.
//
//*****************************************************************************
void
PRCMLPDSWakeUpGPIOSelect(unsigned long ulGPIOPin, unsigned long ulType)
{
  //
  // Set the wakeup GPIO
  //
  HWREG(HIB3P3_BASE + HIB3P3_O_MEM_HIB_LPDS_GPIO_SEL) = ulGPIOPin;
  
  //
  // Set the trigger type.
  //
  HWREG(GPRCM_BASE + GPRCM_O_APPS_GPIO_WAKE_CONF) = (ulType & 0x3);
}

//*****************************************************************************
//
//! Puts the system into Sleep.
//!
//! This function puts the system into sleep power mode. System exits the power
//! state on any one of the available interrupt. On exit from sleep mode the
//! function returns to the calling function with all the processor core 
//! registers retained.
//!
//! \return None.
//
//*****************************************************************************
void
PRCMSleepEnter()
{
  //
  // Request Sleep
  //
  CPUwfi();
}

//*****************************************************************************
//
//! Puts the system into Deep Sleep power mode.
//!
//! This function puts the system into Deep Sleep power mode. System exits the 
//! power state on any one of the available interrupt. On exit from deep
//! sleep the function returns to the calling function with all the processor 
//! core registers retained.
//!
//! \return None.
//
//*****************************************************************************
void
PRCMDeepSleepEnter()
{
  //
  // Set bandgap duty cycle to 1
  //
  HWREG(HIB1P2_BASE + HIB1P2_O_BGAP_DUTY_CYCLING_EXIT_CFG) = 0x1;

  //
  // Enable DSLP in cortex
  //
  HWREG(0xE000ED10)|=1<<2;

  //
  // Request Deep Sleep
  //
  CPUwfi();

  //
  // Disable DSLP in cortex before
  // returning to the caller
  //
  HWREG(0xE000ED10) &= ~(1<<2);

}

//*****************************************************************************
//
//! Enable SRAM column retention during Deep Sleep and/or LPDS Power mode(s)
//!
//! \param ulSramColSel is bit mask of valid SRAM columns.
//! \param ulModeFlags is the bit mask of power modes.
//!
//! This functions enables the SRAM retention. The device supports configurable
//! SRAM column retention in Low Power Deep Sleep (LPDS) and Deep Sleep power
//! modes. Each column is of 64 KB size.
//!
//! The parameter \e ulSramColSel should be logical OR of the following:-
//! -\b PRCM_SRAM_COL_1
//! -\b PRCM_SRAM_COL_2
//! -\b PRCM_SRAM_COL_3
//! -\b PRCM_SRAM_COL_4
//!
//! The parameter \e ulModeFlags selects the power modes and sholud be logical 
//! OR of one or more of the following
//! -\b PRCM_SRAM_DSLP_RET
//! -\b PRCM_SRAM_LPDS_RET
//!
//! \return None.
//
//****************************************************************************
void 
PRCMSRAMRetentionEnable(unsigned long ulSramColSel, unsigned long ulModeFlags)
{
  if(ulModeFlags & PRCM_SRAM_DSLP_RET)
  {
    //
    // Configure deep sleep SRAM retention register
    //
    HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_DSLP_CFG) = (ulSramColSel & 0xF);
  }

  if(ulModeFlags & PRCM_SRAM_LPDS_RET)
  {
    //
    // Configure LPDS SRAM retention register
    //
    HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_LPDS_CFG) = (ulSramColSel & 0xF);
  }
}

//*****************************************************************************
//
//! Disable SRAM column retention during Deep Sleep and/or LPDS Power mode(s).
//!
//! \param ulSramColSel is bit mask of valid SRAM columns.
//! \param ulFlags is the bit mask of power modes.
//!
//! This functions disable the SRAM retention. The device supports configurable
//! SRAM column retention in Low Power Deep Sleep (LPDS) and Deep Sleep power
//! modes. Each column is of 64 KB size.
//!
//! The parameter \e ulSramColSel should be logical OR of the following:-
//! -\b PRCM_SRAM_COL_1
//! -\b PRCM_SRAM_COL_2
//! -\b PRCM_SRAM_COL_3
//! -\b PRCM_SRAM_COL_4
//!
//! The parameter \e ulFlags selects the power modes and sholud be logical OR
//! of one or more of the following
//! -\b PRCM_SRAM_DSLP_RET
//! -\b PRCM_SRAM_LPDS_RET
//!
//! \return None.
//
//****************************************************************************
void
PRCMSRAMRetentionDisable(unsigned long ulSramColSel, unsigned long ulFlags)
{
  if(ulFlags & PRCM_SRAM_DSLP_RET)
  {
    //
    // Configure deep sleep SRAM retention register
    //
    HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_DSLP_CFG) &= ~(ulSramColSel & 0xF);
  }

  if(ulFlags & PRCM_SRAM_LPDS_RET)
  {
    //
    // Configure LPDS SRAM retention register
    //
    HWREG(GPRCM_BASE+ GPRCM_O_APPS_SRAM_LPDS_CFG) &= ~(ulSramColSel & 0xF);
  }
}


//*****************************************************************************
//
//! Enables individual HIB wakeup source(s).
//!
//! \param ulHIBWakupSrc is logical OR of valid HIB wakeup sources.
//!
//! This function enables individual HIB wakeup source(s). The paramter
//! \e ulHIBWakupSrc is the bit mask of HIB wakeup sources and should be
//! logical OR of one or more of the follwoing :-
//! -\b PRCM_HIB_RTC
//! -\b PRCM_HIB_GPIO
//!
//! \return None.
//
//*****************************************************************************
void 
PRCMHibernateWakeupSourceEnable(unsigned long ulHIBWakupSrc)
{
  //
  // Enable HIB wakeup sources
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_WAKE_EN) |= (ulHIBWakupSrc & 0x1);
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_GPIO_WAKE_EN) |= ((ulHIBWakupSrc>>16)&0xFF);
}

//*****************************************************************************
//
//! Disable individual HIB wakeup source(s).
//!
//! \param ulHIBWakupSrc is logical OR of valid HIB wakeup sources.
//!
//! This function disable individual HIB wakeup source(s). The paramter
//! \e ulHIBWakupSrc is same as bit fileds defined in
//! PRCMEnableHibernateWakeupSource()
//!
//! \return None.
//
//*****************************************************************************
void
PRCMHibernateWakeupSourceDisable(unsigned long ulHIBWakupSrc)
{
  //
  // Disable HIB wakeup sources
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_WAKE_EN) &= ~(ulHIBWakupSrc & 0x1);
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_GPIO_WAKE_EN) &= ~((ulHIBWakupSrc>>16)&0xFF);
}


//*****************************************************************************
//
//! Get hibernate wakeup cause
//!
//! This function gets the hibernate wakeup cause.
//!
//! \return Returns \b PRCM_HIB_WAKEUP_CAUSE_SLOW_CLOCK or
//! \b PRCM_HIB_WAKEUP_CAUSE_GPIO
//
//*****************************************************************************
unsigned long
PRCMHibernateWakeupCauseGet()
{
  return ((HWREG(HIB3P3_BASE + HIB3P3_O_MEM_HIB_WAKE_STATUS) >> 1) & 0xF);
}

//*****************************************************************************
//
//! Sets Hibernate wakeup Timer
//!
//! \param ullTicks is number of 32.768 KHz clocks
//!
//! This function sets internal hibernate wakeup timer running at 32.768 KHz.
//!
//! \return Returns \b true on success, \b false otherwise.
//
//*****************************************************************************
tBoolean 
PRCMHibernateIntervalSet(unsigned long long ullTicks)
{
  unsigned long long ullRTCVal;

  //
  // Latch the RTC vlaue
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_TIMER_READ) = 0x1;

  //
  // Read latched values as 2 32-bit vlaues
  //
  ullRTCVal  = HWREG(HIB3P3_BASE + HIB3P3_O_MEM_HIB_RTC_TIMER_MSW);
  ullRTCVal  = ullRTCVal << 32;
  ullRTCVal |= HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_TIMER_LSW);
  
  //
  // Add the interval
  //
  ullRTCVal = ullRTCVal + ullTicks;
  
  //
  // Set RTC match value
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_WAKE_LSW_CONF)
                                           = (unsigned long)(ullRTCVal);
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_WAKE_MSW_CONF)
                                           = (unsigned long)(ullRTCVal>>32);
  
  return(true);
}


//*****************************************************************************
//
//! Selects the GPIO(s) for hibernate wakeup
//!
//! \param ulGPIOBitMap is the bit-map of valid hibernate wakeup GPIO. 
//! \param ulType is the wakeup trigger type.
//!
//! This function setects the wakeup GPIO for hibernate and can be 
//! used to select any combination of 7 pre-defined GPIO(s).
//!
//! This function enables individual HIB wakeup source(s). The paramter
//! \e ulGPIOBitMap should be one of the follwoing :-
//! -\b PRCM_HIB_WAKEUP_GPIO2
//! -\b PRCM_HIB_WAKEUP_GPIO4
//! -\b PRCM_HIB_WAKEUP_GPIO13
//! -\b PRCM_HIB_WAKEUP_GPIO17
//! -\b PRCM_HIB_WAKEUP_GPIO11
//! -\b PRCM_HIB_WAKEUP_GPIO24
//! -\b PRCM_HIB_WAKEUP_GPIO26
//!
//! The parameter \e ulType sets the trigger type and can be one of the 
//! following:
//! - \b PRCM_HIB_LOW_LEVEL
//! - \b PRCM_HIB_HIGH_LEVEL
//! - \b PRCM_HIB_FALL_EDGE
//! - \b PRCM_HIB_RISE_EDGE
//!
//! \return None.
//
//*****************************************************************************
void
PRCMHibernateWakeUpGPIOSelect(unsigned long ulGPIOBitMap, unsigned long ulType)
{
  unsigned char ucLoop;
  
  //
  // Set the source bit mask.
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_GPIO_WAKE_EN) = (ulGPIOBitMap&0xFF);
  
  //
  // Set the configuration for each GPIO
  //
  for(ucLoop=0; ucLoop < 7; ucLoop++)
  {
    if(ulGPIOBitMap & (1<<ucLoop))
    {
      HWREG(HIB3P3_BASE+HIB3P3_O_MEM_GPIO_WAKE_CONF) = ulType << (ucLoop*2);
    }
  }
}

//*****************************************************************************
//
//! Puts the system into Hibernate
//!
//! This function puts the system into Hibernate. The device enters HIB
//! immediately and on exit from HIB device core starts its execution from
//! reset thus the function never returns.
//!
//! \return None.
//
//*****************************************************************************
void 
PRCMHibernateEnter()
{
  //
  // Enable 32KHz internal RC oscillator
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_INT_OSC_CONF) = 0x00000101;
  
  //
  // Delay for a little bit.
  //
  UtilsDelay(8000);
  
  //
  // Enable 16MHz clock
  //
  HWREG(HIB1P2_BASE+HIB1P2_O_CM_OSC_16M_CONFIG) = 0x00010008;
  
  //
  // Delay for a little bit.
  //
  UtilsDelay(8000);

  //
  // Request hibernate.
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_REQ) = 0x1;

  __asm("    nop\n"
        "    nop\n"
        "    nop\n"
        "    nop\n");
}

//*****************************************************************************
//
//! Gets the current value of the internal RTC
//!
//! This function latches and reads the internal RTC running at 32.768 Khz
//!
//! \return 64-bit current counter vlaue.
//
//*****************************************************************************
unsigned long long
PRCMRTCGet()
{
  unsigned long long ullRTCVal;

  //
  // Latch the RTC vlaue
  //
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_TIMER_READ) = 0x1;

  //
  // Read latched values as 2 32-bit vlaues
  //
  ullRTCVal  = HWREG(HIB3P3_BASE + HIB3P3_O_MEM_HIB_RTC_TIMER_MSW);
  ullRTCVal  = ullRTCVal << 32;
  ullRTCVal |= HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_RTC_TIMER_LSW);

  return ullRTCVal;
}


//*****************************************************************************
//
//! Sets RTC match value to interrupt the processor.
//!
//! \param ullValue is the match value.
//!
//! This function sets the match value for RTC. This is use to interrupt the 
//! processor when RTC counts to the specified value.  
//!
//! \return None.
//
//*****************************************************************************
void PRCMRTCMatchSet(unsigned long long ullValue)
{  
  //
  // Set RTC match value
  //
  HWREG(HIB3P3_BASE + HIB3P3_O_MEM_HIB_RTC_IRQ_LSW_CONF)
                                           = (unsigned long)(ullValue);
  HWREG(HIB3P3_BASE + HIB3P3_O_MEM_HIB_RTC_IRQ_LSW_CONF)
                                           = (unsigned long)(ullValue>>32);
}

//*****************************************************************************
//
//! Write to On-Chip Retention (OCR) register.
//!
//! This function writes to On-Chip retention register. The device supports two
//! 4-byte OCR register which are retained across all power mode.
//!
//! The parameter \e ucIndex is an index of the OCR and can be \b 0 or \b 1.
//!
//! \return None.
//
//*****************************************************************************
void PRCMOCRRegisterWrite(unsigned char ucIndex, unsigned long ulRegValue)
{
  HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_REG2 + (ucIndex << 2)) = ulRegValue;
}

//*****************************************************************************
//
//! Read from On-Chip Retention (OCR) register.
//!
//! This function reads from On-Chip retention register. The device supports two
//! 4-byte OCR register which are retained across all power mode.
//!
//! The parameter \e ucIndex is an index of the OCR and can be \b 0 or \b 1.
//!
//! \return None.
//
//*****************************************************************************
unsigned long PRCMOCRRegisterRead(unsigned char ucIndex)
{
  //
  // Return the read value.
  //
  return HWREG(HIB3P3_BASE+HIB3P3_O_MEM_HIB_REG2 + (ucIndex << 2));
}

//*****************************************************************************
//
//! Registers an interrupt handler for the PRCM.
//!
//! \param pfnHandler is a pointer to the function to be called when the
//! interrupt is activated.
//!
//! This function does the actual registering of the interrupt handler.  This
//! function enables the global interrupt in the interrupt controller;
//!
//! \return None.
//
//*****************************************************************************
void PRCMIntRegister(void (*pfnHandler)(void))
{
  //
  // Register the interrupt handler.
  //
  IntRegister(INT_PRCM, pfnHandler);

  //
  // Enable the PRCM interrupt.
  //
  IntEnable(INT_PRCM);
}

//*****************************************************************************
//
//! Unregisters an interrupt handler for the PRCM.
//!
//! \param pfnHandler is a pointer to the function to be called when the
//! interrupt is activated.
//!
//! This function does the actual unregistering of the interrupt handler.  It
//! clears the handler to be called when a PRCM interrupt occurs.  This
//! function also masks off the interrupt in the interrupt controller so that
//! the interrupt handler no longer is called.
//!
//! \return None.
//
//*****************************************************************************
void PRCMIntUnregister()
{
  //
  // Enable the UART interrupt.
  //
  IntDisable(INT_PRCM);

  //
  // Register the interrupt handler.
  //
  IntUnregister(INT_PRCM);
}

//*****************************************************************************
//
//! Gets the current interrupt status.
//!
//! This function returns the PRCM interrupt status of interrupts that are
//! allowed to reflect to the processor. The interrupts are cleared on read.
//!
//! \return Returns the current interrupt status.
//
//*****************************************************************************
unsigned long PRCMIntStatus()
{
    return HWREG(ARCM_BASE + APPS_RCM_O_APPS_RCM_INTERRUPT_STATUS);
}

//*****************************************************************************
//
//! Enables individual PRCM interrupt sources.
//!
//! \param ulIntFlags is the bit mask of the interrupt sources to be enabled.
//!
//! This function enables the indicated ARCM interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter is the logical OR of any of the following:
//! -\b PRCM_INT_RTC
//!
//
//*****************************************************************************
void PRCMIntEnable(unsigned long ulIntFlags)
{
  if(ulIntFlags & PRCM_INT_RTC )
  {
    HWREG(ARCM_BASE + 0x124) |= 0x1;
  }
}

//*****************************************************************************
//
//! Disables individual PRCM interrupt sources.
//!
//! \param ulIntFlags is the bit mask of the interrupt sources to be disabled.
//!
//! This function disables the indicated ARCM interrupt sources.  Only the
//! sources that are enabled can be reflected to the processor interrupt;
//! disabled sources have no effect on the processor.
//!
//! The \e ulIntFlags parameter has the same definition as the \e ulIntFlags
//! parameter to PRCMEnableInterrupt().
//!
//! \return None.
//
//*****************************************************************************
void PRCMIntDisable(unsigned long ulIntFlags)
{
  if(ulIntFlags & PRCM_INT_RTC )
  {
    HWREG(ARCM_BASE + 0x124) &= ~0x1;
  }
}

//*****************************************************************************
//
// Close the Doxygen group.
//! @}
//
//*****************************************************************************
