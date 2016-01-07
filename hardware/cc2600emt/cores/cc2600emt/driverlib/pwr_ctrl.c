/******************************************************************************
*  Filename:       pwr_ctrl.c
*  Revised:        2015-05-19 11:38:08 +0200 (Tue, 19 May 2015)
*  Revision:       43528
*
*  Description:    Power Control driver.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#include <driverlib/pwr_ctrl.h>

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #undef  PowerCtrlStateSet
    #define PowerCtrlStateSet               NOROM_PowerCtrlStateSet
    #undef  PowerCtrlSourceSet
    #define PowerCtrlSourceSet              NOROM_PowerCtrlSourceSet
#endif

//*****************************************************************************
//
// Force the system in to low power modes.
//
//*****************************************************************************
void
PowerCtrlStateSet(uint32_t ui32Powerstate)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32Powerstate == PWRCTRL_STANDBY) ||
           (ui32Powerstate == PWRCTRL_POWER_DOWN) ||
           (ui32Powerstate == PWRCTRL_SHUTDOWN));

    //
    // Configure the desired power state.
    //
    if(ui32Powerstate == PWRCTRL_STANDBY)
    {
        //
        //
        // Turn of all power domains in the MCU voltage domain. This is
        // necessary to conserve power before switching to the uLDO.
        //
        PRCMPowerDomainOff(PRCM_DOMAIN_RFCORE | PRCM_DOMAIN_SERIAL |
                           PRCM_DOMAIN_PERIPH | PRCM_DOMAIN_CPU |
                           PRCM_DOMAIN_VIMS);

        //
        // Make sure to request power off of the JTAG domain.
        //
        AONWUCJtagPowerOff();

        //
        // Configuration of clock source for MCU and AUX in standby mode.
        //
        AONWUCMcuPowerDownConfig(AONWUC_CLOCK_SRC_LF);
        AONWUCAuxPowerDownConfig(AONWUC_CLOCK_SRC_LF);

        //
        // Configure the recharge controller and request the uLDO as power
        // source.
        //
        AONWUCRechargeCtrlConfigSet(true, 34, 2500, 5000);

        //
        // Enable AUX power down
        // This will tell the system that no HF source is needed and will
        // allow the system to use the low-leakage/effect power supply.
        // NB. This does not allow co-existence of an independent
        // Sensor Controller.
        //
        AUXWUCPowerCtrl(AUX_WUC_POWER_DOWN);
        while(AONWUCPowerStatusGet() & AONWUC_AUX_POWER_ON);

        //
        // Request the uLDO for standby power consumption.
        //
        PowerCtrlSourceSet(PWRCTRL_PWRSRC_ULDO);

        //
        // Sync the AON interface to ensure all writes have gone through
        //
        HWREG(AON_RTC_BASE + AON_RTC_O_SYNC);

        //
        // Enable transition to standby.
        //
        PRCMDeepSleep();
    }
    else if(ui32Powerstate == PWRCTRL_POWER_DOWN)
    {
        //
        // Latch the current IO configuration before going to sleep to ensure
        // the IOs retain their value even after boot and reset of the
        // configuration.
        //
        AONIOCFreezeEnable();

        //
        // Make sure retention on MCU SRAM is on - on pr. default.
        //
        AONWUCMcuSRamConfig(MCU_RAM0_RETENTION | MCU_RAM1_RETENTION |
                            MCU_RAM2_RETENTION | MCU_RAM3_RETENTION);

        //
        // Allow power off on all domains in the MCU voltage domain.
        // This is necessary to conserve power before switching to the uLDO.
        //
        PRCMPowerDomainOff(PRCM_DOMAIN_RFCORE | PRCM_DOMAIN_SERIAL |
                           PRCM_DOMAIN_PERIPH | PRCM_DOMAIN_CPU |
                           PRCM_DOMAIN_VIMS);

        //
        // Turn off the MCU voltage domain. This will not take effect until System CPU
        // is in deep sleep.
        //
        PRCMMcuPowerOff();

        //
        // Set the wake up mode  - default value coming out of reset
        //
        AONWUCMcuWakeUpConfig(MCU_IMM_WAKE_UP);

        //
        // VIRTUAL POWER OFF DISABLE is the default value coming out of reset
        //
        AONWUCMcuPowerOffConfig(MCU_VIRT_PWOFF_DISABLE);

        //
        // Configure the recharge controller and request the uLDO as power
        // source.
        // Recommended maximum numbers for lowest power consumption
        // AdaptRate = 96
        // MaxPeriod = 21440
        // InitPeriod = 14816
        //
        AONWUCRechargeCtrlConfigSet(true, 75, 5000, 7500);

        //
        // Enable AUX power down with LF clock source
        // Turn off JTAG domain and enable powerdown - values are default.
        //
        AONWUCAuxPowerDownConfig(AONWUC_CLOCK_SRC_LF);
        AUXWUCPowerCtrl(AUX_WUC_POWER_DOWN);
        AONWUCDomainPowerDownEnable();
        while(AONWUCPowerStatusGet() & AONWUC_AUX_POWER_ON);

        //
        // Sync the AON interface to ensure all writes have gone through
        //
        HWREG(AON_RTC_BASE + AON_RTC_O_SYNC);

        //
        // Enable transition to power down.
        //
        PRCMDeepSleep();
    }
    else
    {
        //
        // Latch the current IO configuration before going to sleep to ensure
        // the IOs retain their value even after boot and reset of the
        // configuration.
        //
        AONIOCFreezeEnable();

        //
        // Turn of all power domains in the MCU voltage domain.
        //
        PRCMPowerDomainOff(PRCM_DOMAIN_RFCORE | PRCM_DOMAIN_SERIAL |
                           PRCM_DOMAIN_PERIPH | PRCM_DOMAIN_CPU |
                           PRCM_DOMAIN_VIMS);

        //
        // Turn off the MCU voltage domain. This will not take effect until System CPU
        // is in deep sleep.
        //
        PRCMMcuPowerOff();

        //
        // Set the wake up mode of MCU to immediate
        //
        AONWUCMcuWakeUpConfig(MCU_IMM_WAKE_UP);
        AONWUCMcuPowerOffConfig(MCU_VIRT_PWOFF_DISABLE);

        //
        // Turn off the AUX domain and wait for power to be off.
        //
        // Is this required for shutdown mode? or will AUX automatically
        // power off.
        AUXWUCPowerCtrl(AUX_WUC_POWER_OFF);
        while(AONWUCPowerStatusGet() & AONWUC_AUX_POWER_ON)
        { }

        //
        // Latch the IOs in the padring before going to sleep to retain their
        // value even after boot and reset of the configuration.
        //
        PowerCtrlIOFreezeEnable();

        //
        // Enable shutdown and make sure the AON interface is in sync on the
        // 32kHz clock.
        //
        AONWUCShutDownEnable();

        //
        // Sync the AON interface to ensure all writes have gone through
        //
        HWREG(AON_RTC_BASE + AON_RTC_O_SYNC);

        //
        // Enable transition to shutdown.
        //
        PRCMDeepSleep();
    }
}

//*****************************************************************************
//
//! Set (Request) the main power source
//
//*****************************************************************************
void
PowerCtrlSourceSet(uint32_t ui32PowerConfig)
{
    //
    // Check the arguments.
    //
    ASSERT((ui32PowerConfig == PWRCTRL_PWRSRC_DCDC) ||
           (ui32PowerConfig == PWRCTRL_PWRSRC_GLDO) ||
           (ui32PowerConfig == PWRCTRL_PWRSRC_ULDO));

    //
    // Configure the power.
    //
    if(ui32PowerConfig == PWRCTRL_PWRSRC_DCDC) {
        HWREG(AON_SYSCTL_BASE + AON_SYSCTL_O_PWRCTL) |=
            (AON_SYSCTL_PWRCTL_DCDC_EN | AON_SYSCTL_PWRCTL_DCDC_ACTIVE);
    }
    else if (ui32PowerConfig == PWRCTRL_PWRSRC_GLDO)
    {
        HWREG(AON_SYSCTL_BASE + AON_SYSCTL_O_PWRCTL) &=
            ~(AON_SYSCTL_PWRCTL_DCDC_EN | AON_SYSCTL_PWRCTL_DCDC_ACTIVE);
    }
    else
    {
        PRCMMcuUldoConfigure(true);
    }
}
