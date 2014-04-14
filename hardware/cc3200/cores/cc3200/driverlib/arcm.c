//*****************************************************************************
//
// arcm.c - Driver for the APPS Reset and Clock Module (ARCM)
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
//! \addtogroup ARCM_Apps_Reset_Clock_Module_api
//! @{
//
//*****************************************************************************

#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_apps_rcm.h"
#include "inc/hw_hib1p2.h"
#include "inc/hw_gprcm.h"
#include "arcm.h"
#include "interrupt.h"
#include "cpu.h"
#include "flash.h"

#define ARCM_BASE_CLOCK 240000000
#define ARCM_SYS_CLOCK  80000000
#define ARCM_XTAL_CLOCK  40000000

#define ARCM_BASE APPS_RCM_BASE

//The bits for run, slp and dslp are same for all the peripherals
#define ARCM_RUN_MODE_CLK_ENABLE   \
                              APPS_RCM_CAMERA_CLK_GATING_CAMERA_RUN_CLK_ENABLE

#define ARCM_SLP_MODE_CLK_ENABLE   \
                              APPS_RCM_CAMERA_CLK_GATING_CAMERA_SLP_CLK_ENABLE

#define ARCM_DSLP_MODE_CLK_ENABLE  \
                              APPS_RCM_CAMERA_CLK_GATING_CAMERA_DSLP_CLK_ENABLE

#define ARCM_SOFT_RESET            \
                               APPS_RCM_CAMERA_SOFT_RESET_CAMERA_SOFT_RESET

#define ARCM_EN_STATUS             \
                               APPS_RCM_CAMERA_SOFT_RESET_CAMERA_ENABLED_STATUS

#define ARCM_CLK_GEN_OFF_TIME_M   \
                               APPS_RCM_MMCHS_CLK_GEN_MMCHS_PLLCKDIV_OFF_TIME_M

#define ARCM_CLK_GEN_ON_TIME_M    \
                                APPS_RCM_MMCHS_CLK_GEN_MMCHS_PLLCKDIV_ON_TIME_M




const unsigned long ulArcmClkGenRegs[]=
{
	APPS_RCM_O_CAMERA_CLK_GEN,
	APPS_RCM_O_MMCHS_CLK_GEN,
	APPS_RCM_O_MCSPI_A1_CLK_GEN,
	APPS_RCM_O_MCSPI_A2_CLK_GEN,
        APPS_RCM_O_MCSPI_S0_CLKDIV_CFG

};

const ArcmPeripheralRegs_t stArcmPerRegs[] =
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
	{APPS_RCM_O_GPIO_E_CLK_GATING,   APPS_RCM_O_GPIO_E_SOFT_RESET   },
	{APPS_RCM_O_WDOG_A_CLK_GATING,   APPS_RCM_O_WDOG_A_SOFT_RESET   },
	{APPS_RCM_O_UART_A0_CLK_GATING,  APPS_RCM_O_UART_A0_SOFT_RESET  },
	{APPS_RCM_O_UART_A1_CLK_GATING,  APPS_RCM_O_UART_A1_SOFT_RESET  },
	{APPS_RCM_O_GPT_A0_CLK_GATING ,  APPS_RCM_O_GPT_A0_SOFT_RESET   },
	{APPS_RCM_O_GPT_A1_CLK_GATING,   APPS_RCM_O_GPT_A1_SOFT_RESET   },
	{APPS_RCM_O_GPT_A2_CLK_GATING,   APPS_RCM_O_GPT_A2_SOFT_RESET   },
	{APPS_RCM_O_GPT_A3_CLK_GATING,   APPS_RCM_O_GPT_A3_SOFT_RESET   },
	{APPS_RCM_O_CRYPTO_CLK_GATING,   APPS_RCM_O_CRYPTO_SOFT_RESET   },
	{APPS_RCM_O_EPI_CLK_GATING,      APPS_RCM_O_EPI_SOFT_RESET      },
	{APPS_RCM_O_MCSPI_S0_CLK_GATING, APPS_RCM_O_MCSPI_S0_SOFT_RESET },
	{APPS_RCM_O_I2C_CLK_GATING,      APPS_RCM_O_I2C_SOFT_RESET      }

};

//*****************************************************************************
//
//! \internal
//! Compute output of the clock divier
//!
//! \param ulInputClk is imput divider clock frequency
//! \param ulDivRegOff is the offset of divider register
//!
//! This function compute and returns output of the clock divier in Hz
//!
//! \retun Output of the clock divier
//
//*****************************************************************************
static unsigned long 
ArcmPeripheralClkCompute(unsigned long ulInputClk, unsigned long ulDivRegOff)
{
  unsigned long ulOutputClk;
  unsigned char ucOnTime;
  unsigned char ucOffTime;
  
  ucOnTime = ((HWREG(APPS_RCM_BASE + ulDivRegOff) >> 8) & 0x7);
  ucOffTime = (HWREG(APPS_RCM_BASE + ulDivRegOff) & 0x7);
  
  ulOutputClk = (ulInputClk/((ucOnTime + 1) + (ucOffTime + 1)));
  
  return(ulOutputClk); 
}

//*****************************************************************************
//
//! Enables RUN mode clock
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function enables the run mode clock for the given module.
//!
//! \return None.
//
//*****************************************************************************
void ArcmPeripheralEnable(ArcmPeripherals_t ePeripheral)
{
  //
  // Set the RUN mode clock bit
  //
  HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].ClkGatingReg)
                                                   |= ARCM_RUN_MODE_CLK_ENABLE;
}

//*****************************************************************************
//
//! Disables RUN mode clock
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function disables the run mode clock for the given module.
//!
//! \return None.
//
//*****************************************************************************
void ArcmPeripheralDisable(ArcmPeripherals_t ePeripheral )
{
  //
  // Reset the RUN mode clock bit
  //
  HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].ClkGatingReg) 
                                                  &= ~ARCM_RUN_MODE_CLK_ENABLE;
}

//*****************************************************************************
//
//! Assert a reset to the specfied module
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function assert a reset to the specfied module.
//!
//! \return None.
//
//*****************************************************************************
void ArcmPeripheralReset(ArcmPeripherals_t ePeripheral )
{
  volatile unsigned long ulDelay;

  //
  // Set the reset bit
  //
  HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].SoftResetReg) |= ARCM_SOFT_RESET;
  
  //
  // Small Delay
  //
  for(ulDelay =0; ulDelay<5000; ulDelay++)
  {
          
  }
  
  //
  // Re-set the reset bit
  //
  HWREG(ARCM_BASE+stArcmPerRegs[ePeripheral].SoftResetReg) &= ~ARCM_SOFT_RESET;
}

//*****************************************************************************
//
//! Checks ready status for the module
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function return ready status for the given module.
//!
//! \return \b true is module is ready elae \b false
//
//*****************************************************************************
tBoolean ArcmPeripheralReady(ArcmPeripherals_t ePeripheral)
{
  unsigned long ReadyBit;
  
  //
  // Read the ready bit status
  //
  ReadyBit = HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].SoftResetReg);
  ReadyBit =  ReadyBit & ARCM_EN_STATUS;

  //
  // Return the status
  //
  if (ReadyBit )
  {
          return(true);
  }
  else
  {
          return(false);
  }

}

//*****************************************************************************
//
//! Enables SLEEP mode clock
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function enables the sleep mode clock for the given module.
//!
//! \return None.
//
//*****************************************************************************
void ArcmPeripheralSlpEnable(ArcmPeripherals_t ePeripheral )
{
  //
  // Set sleep mode clock
  //
  HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].ClkGatingReg) 
                                                   |= ARCM_SLP_MODE_CLK_ENABLE;
}

//*****************************************************************************
//
//! Disables SLEEP mode clock
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function disables the sleep mode clock for the given module.
//!
//! \return None.
//
//*****************************************************************************

void ArcmPeripheralSlpDisable(ArcmPeripherals_t ePeripheral )
{
  //
  // Reset sleep mode clock
  //
  HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].ClkGatingReg) 
                                                  &= ~ARCM_SLP_MODE_CLK_ENABLE;
}

//*****************************************************************************
//
//! Enables Deep SLEEP mode clock
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function enables the deep sleep mode clock for the given module.
//!
//! \return None.
//
//*****************************************************************************
void ArcmPeripheralDSlpEnable(ArcmPeripherals_t ePeripheral )
{
  //
  // Set deep sleep mode clock
  //
  HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].ClkGatingReg) 
                                                  |= ARCM_DSLP_MODE_CLK_ENABLE;
}

//*****************************************************************************
//
//! Disables Deep SLEEP mode clock
//!
//! \param ePeripheral is one of the valid modules
//!
//! This function disables the deep sleep mode clock for the given module.
//!
//! \return None.
//
//*****************************************************************************
void ArcmPeripheralDSlpDisable(ArcmPeripherals_t ePeripheral )
{
  //
  // Reset deep sleep mode clock
  //
  HWREG(ARCM_BASE + stArcmPerRegs[ePeripheral].ClkGatingReg) 
                                                 &= ~ARCM_DSLP_MODE_CLK_ENABLE;
}

//*****************************************************************************
//
//! Configures base (input) clock for modules
//!
//! \param ePeripheral is one of the valid modules
//! \param ulOnTime is the on time in 240 Mhz clock cycle
//! \param ulOffTime is the off time in 240 Mhz clock cycle
//!
//! This function configures the base (input) clock for some of modules.
//! The clock to the module is calculated as follows:
//!
//!   module_clock = (240/((ulOnTime + 1) + (ulOffTime + 1)) Mhz 
//!
//!
//! The parameter \e ePeripheral should be one of the following
//! 
//! - \b ARCM_CAMERA
//! - \b ARCM_MMCHS
//! - \b ARCM_MCSPIA1
//! - \b ARCM_MCSPIA2
//! - \b ARCM_MCSPIS0
//!
//! This configuration is valid for ARCM_MCSPIA1, ARCM_MCSPIA2 and ARCM_MCSPIS0
//! if and only if PLL is selected al clock source. 
//! See \sa ArcmMcSPIClockSelect() for more details on selecting McSPI source
//! clock
//!
//! \return None.
//
//*****************************************************************************
void 
ArcmPeripheralClkConfig(ArcmPeripherals_t ePeripheral,
                        unsigned long ulOnTime, unsigned long ulOffTime)
{
  unsigned long ulPerihConfig;

  if(ePeripheral == ARCM_MCSPIS0)
  {
      ePeripheral = (ArcmPeripherals_t)5;
  }

  ulPerihConfig= HWREG(ARCM_BASE + ulArcmClkGenRegs[ePeripheral]);
  ulPerihConfig=(ulPerihConfig & ~ARCM_CLK_GEN_OFF_TIME_M)|ulOffTime;
  ulPerihConfig=(ulPerihConfig & ~ARCM_CLK_GEN_ON_TIME_M)|ulOnTime;

  //
  // Configure the corresponfing clock gen register
  //
  HWREG(ARCM_BASE + ulArcmClkGenRegs[ePeripheral]) = ulPerihConfig;
}

//*****************************************************************************
//
//! Selecte the McSPI clock source 
//!
//! \param ePeripheral is one of the valid modules
//! \param ulSrcClk is one of the valic McSPI clock
//!
//! This function selects between PLL and XTAL as McSPI inout clock.
//! Parameter \e ulSrcClk should be one of the following
//!
//! - \b ARCM_MCSPI_CLK_SRC_PLL for 240 Mhz
//! - \b ARCM_MCSPI_CLK_SRC_XTAL for 40 Mhz
//!
//! \return None.
//
//*****************************************************************************
void ArcmMcSPIClkSrcSet(ArcmPeripherals_t ePeripheral, unsigned long ulSrcClk)
{
  if(ePeripheral == ARCM_MCSPIS0)
  {
    HWREG(ARCM_BASE + APPS_RCM_O_MCSPI_S0_CLKDIV_CFG) |= ulSrcClk;
  }
  else if(ePeripheral == ARCM_MCSPIA1)
  {
    HWREG(ARCM_BASE + APPS_RCM_O_MCSPI_A1_CLK_GEN) |= ulSrcClk;
  }
  else if(ePeripheral == ARCM_MCSPIA2)
  {
    HWREG(ARCM_BASE + APPS_RCM_O_MCSPI_A2_CLK_GEN) |= ulSrcClk;
  }
}

//*****************************************************************************
//
//! Selecte the McSPI clock source 
//!
//! \param ePeripheral is one of the valid McSPI modules
//!
//! This function selects between PLL and XTAL as McSPI inout clock.
//! Parameter \e ulSrcClk should be one of the following
//!
//! \return Returns \b ARCM_MCSPI_CLK_SRC_PLL for 240 Mhz or 
//! \b ARCM_MCSPI_CLK_SRC_XTAL for 40 Mhz or -1 for invalid \e ePeripheral.
//!
//
//*****************************************************************************
long
ArcmMcSPIClkSrcGet(ArcmPeripherals_t ePeripheral)
{
  if(ePeripheral == ARCM_MCSPIS0)
  {
    return(HWREG(ARCM_BASE + APPS_RCM_O_MCSPI_S0_CLKDIV_CFG) 
           & ARCM_MCSPI_CLK_SRC_PLL);
  }
  else if(ePeripheral == ARCM_MCSPIA1)
  {
    return(HWREG(ARCM_BASE + APPS_RCM_O_MCSPI_A2_CLK_GEN) 
           & ARCM_MCSPI_CLK_SRC_PLL);
  }
  else if(ePeripheral == ARCM_MCSPIA2)
  {
    return(HWREG(ARCM_BASE + APPS_RCM_O_MCSPI_A2_CLK_GEN) 
           & ARCM_MCSPI_CLK_SRC_PLL);
  }
  
  return(-1);
}


//*****************************************************************************
//
//! Sets Apps sleep wake sources 
//!
//! \param ulWakeupSrc is one of the valid sources
//!
//! This function sets sources ( Sleep Wakeup timer and/or NWP )
//! that can wakeup the core from sleep.
//!
//! the parameter \e ulWakeupSrc should be one of the following:
//!
//! - \b ARCM_WAKEUP_SRC_NWP to wakeup on interrupt from NWP
//! - \b ARCM_WAKEUP_SRC_TIMER to wakeup due to sleep Timer expiry
//! - \b ARCM_WAKEUP_SRC_NONE to mask both the sources 
//!
//! \return none.
//
//*****************************************************************************
void ArcmSlpWakeupSrcSet(unsigned long ulWakeupSrc)
{
  //
  // Write the corresponing register
  //
  HWREG(ARCM_BASE + APPS_RCM_O_APPS_RCM_SLP_WAKE_ENABLE) = ulWakeupSrc;
}

//*****************************************************************************
//
//! Configures Apps sleep wakeup timer 
//!
//! \param ulTimeInClocks is the number of 80 Mhz clocks cycles
//!
//! This function configures sleep wakeup timer to wakeup the core after
//! \e ulTimeInClocks number of 80Mhz clocks.
//!
//! \return none.
//
//*****************************************************************************

void 
ArcmSlpWakeupTimerConfig(unsigned long ulTimeInClocks)
{
  //
  // Set the wakeup time
  //
  HWREG(ARCM_BASE + APPS_RCM_O_APPS_SLP_WAKETIMER_CFG) = ulTimeInClocks;
}

//*****************************************************************************
//
//! Sets Apps deep sleep wake sources 
//!
//! \param ulWakeupSrc is one of the valid sources
//!
//! This function sets sources ( Deep sleep wakeup timer and/or NWP )
//! that can wakeup the core from sleep.
//!
//! the parameter \e ulWakeupSrc should be one of the following:
//!
//! - \b ARCM_WAKEUP_SRC_NWP to wakeup on interrupt from NWP
//! - \b ARCM_WAKEUP_SRC_TIMER to wakeup due to deep sleep Timer expiry
//! - \b ARCM_WAKEUP_SRC_NONE to mask both the sources 
//!
//! \return none.
//
//*****************************************************************************
void ArcmDSlpWakeupSrcSet(unsigned long ulWakeupSrc)
{
  //
  // Write the corresponing register
  //
  HWREG(ARCM_BASE + APPS_RCM_O_APPS_DSLP_WAKE_CONFIG) = ulWakeupSrc;
}

//*****************************************************************************
//
//! Configures Apps deep sleep wakeup timer 
//!
//! \param ulTimeInClocks is the number of 40 Mhz clocks cycles
//!
//! This function configures deep sleep wakeup timer to wakeup the core after
//! \e ulTimeInClocks number of 40Mhz clocks. To specify wakeup time in 
//! milli-second use ArcmDslpMsecToClocks()
//!
//! The parameter \e ulTimeInClocks can range from 21 to 2^16
//!
//! \return none.
//
//*****************************************************************************
void 
ArcmDSlpWakeupTimerConfig(unsigned long ulTimeInClocks)
{
  unsigned long ulOpp;
  unsigned long ulWake;
  
  //
  // Check sleep is atleast for 21 cycles
  // If not set the sleep time to 21 cycles
  //
  if( ulTimeInClocks < 21)
  {
      ulTimeInClocks = 21;
  }
  
  //
  // Calculate the Wakeup and OPP values
  //
  ulWake = ulTimeInClocks & 0xFFFF;
  ulOpp  = ulWake - 20;
  
  ulWake =  (ulOpp << 16) | ulWake ;
  
  //
  // Configure the register
  //
  HWREG(ARCM_BASE + APPS_RCM_O_APPS_DSLP_WAKE_TIMER_CFG) = ulWake;
}

//*****************************************************************************
//
//! Apps to NWP wakeup request
//!
//! This function sends wakeup request to NWP.
//!
//! \return none.
//
//*****************************************************************************
void ArcmRqstNwpWakeup()
{
  //
  // Request NWP wakeup
  //
  HWREG(ARCM_BASE + APPS_RCM_O_APPS_TO_NWP_WAKE_REQUEST)
    = APPS_RCM_APPS_TO_NWP_WAKE_REQUEST_APPS_TO_NWP_WAKEUP_REQUEST;
}

//*****************************************************************************
//
//! Gets Apps wakeup status
//!
//! This function returns the source that woke up Apps.
//! The returned value will be one of the following
//! 
//! - \b ARCM_DSLP_TIMER_WAKEUP
//! - \b ARCM_SLP_TIMER_WAKEUP
//! - \b ARCM_DSLP_NWP_WAKEUP
//! - \b ARCM_SLP_NWP_WAKEUP
//!
//! \return Returns 32 bit value which indicates the wakeup source
//
//*****************************************************************************
unsigned long ArcmWakeupStatusGet()
{
  //
  // Return register value
  //
  return (HWREG(ARCM_BASE + APPS_RCM_O_APPS_RCM_INTERRUPT_STATUS) & 0xF);
}

//*****************************************************************************
//
//! Resets McASP fracactional divider configuration
//!
//! This function resets McASP fracactional divider configuration
//!
//! \return None.
//
//*****************************************************************************
void ArcmMcAspFracDivReset()
{
  //
  // Set the reset bit (self clearing)
  //
  HWREG(ARCM_BASE + APPS_RCM_O_MCASP_FRAC_CLK_CONFIG1)
      |= APPS_RCM_MCASP_FRAC_CLK_CONFIG1_MCASP_FRAC_DIV_SOFT_RESET;
}

//*****************************************************************************
//
//! Sets McASP fracactional divider
//!
//! \param Divider is divider value.
//!
//! This function configures McASP fracactional divider. By default this 
//! divider is set to output 24 Mhz clock to McASP module.
//!
//! Output clock to the McASP module is calculated as follows:
//!
//!     McASP_clock = (240/Divider) Mhz
//!
//! \return None.
//
//*****************************************************************************
void ArcmMcAspFracDivSet(float Divider)
{
  unsigned short usDivisor;
  unsigned short usFraction;

  //
  // Calculate the Divisor and fractional part
  //
  usDivisor = (unsigned short) Divider;
  usFraction = (unsigned short)((Divider - usDivisor) *(2^16));

  //
  // Configure the divider
  //
  HWREG(ARCM_BASE + APPS_RCM_O_MCASP_FRAC_CLK_CONFIG0)
    = (((usDivisor & 0x3FF) << 16) | (usFraction & 0xFFFF));
}

//*****************************************************************************
//
//! Gets McASP fracactional divider
//!
//! \param Divider is divider value.
//!
//! This function retiives McASP fracactional divider. By default this 
//! divider is set to output 24 Mhz clock to McASP module.
//!
//! Output clock to the McASP module is calculated as follows:
//!
//!     McASP_clock = (240/Divider) Mhz
//!
//! \return Returns McASP frcation divider value.
//
//*****************************************************************************
float ArcmMcAspFracDivGet()
{
  unsigned short usDivisor;
  unsigned short usFraction;
  float Divider;
  
  //
  // Get the divisor and fractional part
  //
  usDivisor = HWREG(ARCM_BASE + APPS_RCM_O_MCASP_FRAC_CLK_CONFIG0) >> 16;
  usFraction = HWREG(ARCM_BASE + APPS_RCM_O_MCASP_FRAC_CLK_CONFIG0) & 0xFFFF;

  //
  // Calulate divider
  //
  Divider  = ((float)(usDivisor) + (((float)usFraction )/(float)(2^16)));
  
  return(Divider);
}

//*****************************************************************************
//
//! Requests LPDS
//!
//! This function requests lpds
//!
//! \return None.
//
//*****************************************************************************
void ArcmLpdsEnter()
{
  //
  // Check if flash exists
  //
  if(HWREG((OCP_GPRCM_BASE + 
            GPRCM_O_GPRCM_EFUSE_READ_REG2) & 0x00110000) == 0x00110000)
  {
    
    //
    // Disable the flash 
    //
    FlashDisable();
  }

  //
  // Set bandgap duty cycle to 1
  //
  HWREG(OCP_HIB1P2_BASE + HIB1P2_O_BGAP_DUTY_CYCLING_EXIT_CFG) = 0x1;

  //
  // Request LPDS
  //
  HWREG(APPS_RCM_BASE + APPS_RCM_O_APPS_LPDS_REQ)
          = APPS_RCM_APPS_LPDS_REQ_APPS_LPDS_REQ;
  //
  // Code should never reach here
  //
}

//*****************************************************************************
//
//! Requests deep sleep
//!
//! This function requests deep sleep
//!
//! \return None.
//
//*****************************************************************************
void ArcmDslpEnter()
{

  //
  // Set bandgap duty cycle to 1
  //
  HWREG(OCP_HIB1P2_BASE + HIB1P2_O_BGAP_DUTY_CYCLING_EXIT_CFG) = 0x1;

  //
  // Enable DSLP in cortex
  //
  HWREG(0xE000ED10)|=1<<2;

  // 
  // Enter DSLP
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
//! Requests sleep
//!
//! This function requests sleep
//!
//! \return None.
//
//*****************************************************************************
void ArcmSlpEnter()
{
  // 
  // Enter SLP
  //
  CPUwfi();
  
}


//*****************************************************************************
//
//! Get the source clock of specified module
//!
//! This function returns source clock of specified module in Hz.
//!
//! \return Return module clock source in Hz
//
//*****************************************************************************
unsigned long ArcmPeripheralClkGet(ArcmPeripherals_t ePeripheral)
{   
  unsigned long ulPeriphClk;
  switch(ePeripheral)
  {
    case ARCM_CAMERA : ulPeriphClk = 0;
    ulPeriphClk = ArcmPeripheralClkCompute(ARCM_BASE_CLOCK,
                                           APPS_RCM_O_CAMERA_CLK_GEN);
    break;
    
    case ARCM_MCASP : ulPeriphClk = 0;
    ulPeriphClk = (unsigned long)(ARCM_BASE_CLOCK/ArcmMcAspFracDivGet());
    break; 
                       
    case ARCM_MMCHS : ulPeriphClk = 0;
    ulPeriphClk = ARCM_BASE_CLOCK;
    break;
                       
    case ARCM_MCSPIA1 : ulPeriphClk = 0;
    if(ArcmMcSPIClkSrcGet(ARCM_MCSPIA1) == ARCM_MCSPI_CLK_SRC_PLL)
    {
      ulPeriphClk = ArcmPeripheralClkCompute(ARCM_BASE_CLOCK,
                                             APPS_RCM_O_MCSPI_A1_CLK_GEN);
                                                          
    }
    else
    {
       ulPeriphClk = ARCM_XTAL_CLOCK;
    }
    break;
                       
    case ARCM_MCSPIA2 : ulPeriphClk = 0;
    if(ArcmMcSPIClkSrcGet(ARCM_MCSPIA2) == ARCM_MCSPI_CLK_SRC_PLL)
    {
      ulPeriphClk = ArcmPeripheralClkCompute(ARCM_BASE_CLOCK,
                                             APPS_RCM_O_MCSPI_A2_CLK_GEN);
                                                          
    }
    else
    {
       ulPeriphClk = ARCM_XTAL_CLOCK;
    }
    break;
                       
    case ARCM_UDMA : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_GPIOS0 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break; 
                       
    case ARCM_GPIOS1 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_GPIOS2 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_GPIOS3 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_GPIOS4 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_WDT : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_UARTA0 :ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_UARTA1 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_TIMERA0 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_TIMERA1 :ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_TIMERA2 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_TIMERA3 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_DTHE : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_EPI : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
                       
    case ARCM_MCSPIS0 :ulPeriphClk = 0;
    if(ArcmMcSPIClkSrcGet(ARCM_MCSPIS0) == ARCM_MCSPI_CLK_SRC_PLL)
    {
      ulPeriphClk = ArcmPeripheralClkCompute(ARCM_BASE_CLOCK,
                                             APPS_RCM_O_MCSPI_S0_CLKDIV_CFG);
                                                          
    }
    else
    {
       ulPeriphClk = ARCM_XTAL_CLOCK;
    }
    break;                  
                       
    case ARCM_I2CS0 : ulPeriphClk = 0;
                       ulPeriphClk = ARCM_SYS_CLOCK;
                       break;
  }
  
  return(ulPeriphClk);
}
