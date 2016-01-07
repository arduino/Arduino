/******************************************************************************
*  Filename:       sys_ctrl.c
*  Revised:        2015-09-25 11:16:31 +0200 (Fri, 25 Sep 2015)
*  Revision:       44664
*
*  Description:    Driver for the System Control.
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

// Hardware headers
#include <inc/hw_types.h>
#include <inc/hw_ccfg.h>
// Driverlib headers
#include <driverlib/aon_batmon.h>
#include <driverlib/sys_ctrl.h>

// Prototype from setup.c
int32_t SignExtendVddrTrimValue( uint32_t ui32VddrTrimVal );

//*****************************************************************************
//
// Handle support for DriverLib in ROM:
// This section will undo prototype renaming made in the header file
//
//*****************************************************************************
#if !defined(DOXYGEN)
    #undef  SysCtrlPowerEverything
    #define SysCtrlPowerEverything          NOROM_SysCtrlPowerEverything
    #undef  SysCtrlStandby
    #define SysCtrlStandby                  NOROM_SysCtrlStandby
    #undef  SysCtrlPowerdown
    #define SysCtrlPowerdown                NOROM_SysCtrlPowerdown
    #undef  SysCtrlShutdown
    #define SysCtrlShutdown                 NOROM_SysCtrlShutdown
    #undef  SysCtrlResetSourceGet
    #define SysCtrlResetSourceGet           NOROM_SysCtrlResetSourceGet
#endif

//*****************************************************************************
//
// Recharge calculator defines and globals
//
//*****************************************************************************

#define  PD_STATE_CACHE_RET      1
#define  PD_STATE_RFMEM_RET      2
#define  PD_STATE_XOSC_LPM       4
#define  PD_STATE_EXT_REG_MODE   8

typedef struct {
   uint32_t    pdTime               ;
   uint16_t    pdRechargePeriod     ;
   uint8_t     pdState              ;
   int8_t      pdTemp               ;
} PowerQualGlobals_t;

static PowerQualGlobals_t powerQualGlobals;


//*****************************************************************************
//
// Arrays that maps the "peripheral set" number (which is stored in the
// third nibble of the PRCM_PERIPH_* defines) to the PRCM register that
// contains the relevant bit for that peripheral.
//
//*****************************************************************************

// Run mode registers
static const uint32_t g_pui32ModuleCG[] =
{
    PRCM_PERIPH_TIMER0,
    PRCM_PERIPH_TIMER1,
    PRCM_PERIPH_TIMER2,
    PRCM_PERIPH_TIMER3,
    PRCM_PERIPH_SSI0,
    PRCM_PERIPH_SSI1,
    PRCM_PERIPH_UART0,
    PRCM_PERIPH_I2C0,
    PRCM_PERIPH_UDMA,
    PRCM_PERIPH_TRNG,
    PRCM_PERIPH_CRYPTO,
    PRCM_PERIPH_GPIO,
    PRCM_PERIPH_I2S
};

//*****************************************************************************
//
// Power up everything
//
//*****************************************************************************
void
SysCtrlPowerEverything(void)
{
    uint32_t ui32Idx;
    uint32_t ui32AuxClocks;

    //
    // Force power on AUX
    //
    AONWUCAuxWakeupEvent(AONWUC_AUX_WAKEUP);
    while(!(AONWUCPowerStatusGet() & AONWUC_AUX_POWER_ON))
    { }

    //
    // Enable all the AUX domain clocks and wait for them to be ready
    //
    ui32AuxClocks = AUX_WUC_ADI_CLOCK | AUX_WUC_OSCCTRL_CLOCK |
                    AUX_WUC_TDCIF_CLOCK | AUX_WUC_ANAIF_CLOCK |
                    AUX_WUC_TIMER_CLOCK | AUX_WUC_AIODIO0_CLOCK |
                    AUX_WUC_AIODIO1_CLOCK | AUX_WUC_SMPH_CLOCK |
                    AUX_WUC_TDC_CLOCK | AUX_WUC_ADC_CLOCK |
                    AUX_WUC_REF_CLOCK;
    AUXWUCClockEnable(ui32AuxClocks);
    while(AUXWUCClockStatus(ui32AuxClocks) != AUX_WUC_CLOCK_READY)
    { }

    //
    // Request to switch to the crystal to enable radio operation.
    // It takes a while for the XTAL to be ready so it is possible to
    // perform other tasks while waiting.
    OSCClockSourceSet(OSC_SRC_CLK_MF | OSC_SRC_CLK_HF, OSC_XOSC_HF);
    OSCClockSourceSet(OSC_SRC_CLK_LF, OSC_XOSC_LF);

    //
    // Switch the HF source to XTAL - must be performed safely out of ROM to
    // avoid flash issues when switching the clock.
    //
    // NB. If already running XTAL on HF clock source the ROM will wait forever
    // on a flag that will never be set - need to check.
    //
    if(OSCClockSourceGet(OSC_SRC_CLK_HF) != OSC_XOSC_HF) {
        OSCHfSourceSwitch();
    }

    //
    // Turn on all the MCU power domains
    // If the CPU is running and executing code the SYSBUS, VIMS and CPU are
    // automatically on as well.
    //
    PRCMPowerDomainOn(PRCM_DOMAIN_RFCORE | PRCM_DOMAIN_SERIAL |
                      PRCM_DOMAIN_PERIPH);
    //
    // Wait for power to be on
    //
    while(PRCMPowerDomainStatus(PRCM_DOMAIN_RFCORE | PRCM_DOMAIN_SERIAL |
                                PRCM_DOMAIN_PERIPH) != PRCM_DOMAIN_POWER_ON);

    PRCMLoadSet();
    while(!PRCMLoadGet());

    //
    // Ensure the domain clocks are running and wait for the clock settings to
    // take effect
    //
    PRCMDomainEnable(PRCM_DOMAIN_RFCORE | PRCM_DOMAIN_VIMS);
    PRCMLoadSet();
    while(!PRCMLoadGet())
    { }

    //
    // Enable all the RF Core clocks
    //
    // Do not read back to check, for two reasons:
    // 1. CPE will update the PWMCLKENABLE register right after boot
    // 2. The PWMCLKENABLE register always reads back what is written
    HWREG(RFC_PWR_NONBUF_BASE + RFC_PWR_O_PWMCLKEN) = 0x7FF;

    //
    // Enable all peripheral clocks in System CPU run/sleep/deep-sleep mode.
    //
    for(ui32Idx = 0; ui32Idx < sizeof(g_pui32ModuleCG) / sizeof(uint32_t);
        ui32Idx++)
    {
        PRCMPeripheralRunEnable(g_pui32ModuleCG[ui32Idx]);
        PRCMPeripheralSleepEnable(g_pui32ModuleCG[ui32Idx]);
        PRCMPeripheralDeepSleepEnable(g_pui32ModuleCG[ui32Idx]);
    }
    PRCMLoadSet();
    while(!PRCMLoadGet())
    { }
}

//*****************************************************************************
//
//! Force the system in to standby mode
//
//*****************************************************************************
void SysCtrlStandby(void)
{
    //
    // Enable the oscillator configuration interface
    //
    OSCInterfaceEnable();

    //
    // Ensure the low frequency clock source is sourced from a low frequency
    // oscillator. The XTAL will provide the most accurate real time clock.
    //
    OSCClockSourceSet(OSC_SRC_CLK_LF,OSC_XOSC_LF);

    //
    // Enable the oscillator configuration interface
    //
    OSCInterfaceDisable();

    //
    // Execute the transition to standby
    //
    PowerCtrlStateSet(PWRCTRL_STANDBY);
}

//*****************************************************************************
//
//! Force the system in to power down.
//
//*****************************************************************************
void
SysCtrlPowerdown(void)
{
    //
    // Make sure the oscillator interface is enabled
    //
    OSCInterfaceEnable();

    //
    // Source the LF clock from the low frequency XTAL_OSC.
    // HF and MF are sourced from the high frequency RC_OSC.
    //
    OSCClockSourceSet(OSC_SRC_CLK_LF, OSC_XOSC_LF);
    OSCClockSourceSet(OSC_SRC_CLK_MF | OSC_SRC_CLK_HF, OSC_RCOSC_HF);

    //
    // Check if already sourcing the HF clock from RC_OSC.
    // If a switch of the clock source is not required, then the call to ROM
    // will loop forever.
    //
    if(OSCClockSourceGet(OSC_SRC_CLK_HF) != OSC_RCOSC_HF)
    {
        OSCHfSourceSwitch();
    }

    //
    // Disable the oscillator interface
    //
    OSCInterfaceDisable();

    //
    // Execute the transition to power down.
    //
    PowerCtrlStateSet(PWRCTRL_POWER_DOWN);
}

//*****************************************************************************
//
//! Force the system in to shutdown.
//
//*****************************************************************************
void
SysCtrlShutdown(void)
{
    //
    // Make sure the oscillator interface is enabled
    //
    OSCInterfaceEnable();

    //
    // Source the LF clock from the low frequency RC_OSC.
    // HF and MF are sourced from the high frequency RC_OSC.
    //
    OSCClockSourceSet(OSC_SRC_CLK_LF, OSC_RCOSC_LF);
    OSCClockSourceSet(OSC_SRC_CLK_MF | OSC_SRC_CLK_HF, OSC_RCOSC_HF);

    //
    // Check if already sourcing the HF clock from RC_OSC.
    // If a switch of the clock source is not required, then the call to ROM
    // will loop forever.
    //
    if(OSCClockSourceGet(OSC_SRC_CLK_HF) != OSC_RCOSC_HF)
    {
        OSCHfSourceSwitch();
    }

    //
    // Disable the oscillator interface
    //
    OSCInterfaceDisable();

    //
    // Execute transition to shutdown.
    //
    PowerCtrlStateSet(PWRCTRL_SHUTDOWN);
}


//*****************************************************************************
// Need to know the CCFG:MODE_CONF.VDDR_TRIM_SLEEP_DELTA fild width in order
// to sign extend correctly but this is however not defined in the hardware
// description fields and are therefore defined separately here.
//*****************************************************************************
#define CCFG_MODE_CONF_VDDR_TRIM_SLEEP_DELTA_WIDTH    4

//*****************************************************************************
//
// SysCtrlSetRechargeBeforePowerDown( xoscPowerMode )
//
//*****************************************************************************
void
SysCtrlSetRechargeBeforePowerDown( uint32_t xoscPowerMode )
{
   int32_t           curTemp                 ;
   int32_t           shiftedTemp             ;
   int32_t           deltaVddrSleepTrim      ;
   int32_t           vddrTrimSleep           ;
   int32_t           vddrTrimActve           ;
   int32_t           diffVddrActiveSleep     ;
   uint32_t          ccfg_ModeConfReg        ;
   uint32_t          curState                ;
   uint32_t          prcmRamRetention        ;
   uint32_t          di                      ;
   uint32_t          dii                     ;
   uint32_t          ti                      ;
   uint32_t          cd                      ;
   uint32_t          cl                      ;
   uint32_t          load                    ;
   uint32_t          k                       ;
   uint32_t          vddrCap                 ;
   uint32_t          newRechargePeriod       ;
   uint32_t          perE                    ;
   uint32_t          perM                    ;
   const uint32_t  * pLookupTable            ;

   //
   // If external regulator mode we shall:
   // - Disable adaptive recharge (bit[31]=0) in AON_WUC_O_RECHARGECFG
   // - Set recharge period to approximately 500 mS (perM=31, perE=5 => 0xFD)
   // - Make sure you get a recalculation if leaving external regulator mode by setting powerQualGlobals.pdState accordingly
   //
   if ( HWREG( AON_SYSCTL_BASE + AON_SYSCTL_O_PWRCTL ) & AON_SYSCTL_PWRCTL_EXT_REG_MODE ) {
      powerQualGlobals.pdState = PD_STATE_EXT_REG_MODE;
      HWREG( AON_WUC_BASE + AON_WUC_O_RECHARGECFG  ) = 0x00A4FDFD;
      return;
   }

   //--- Spec. point 1 ---
   curTemp  = AONBatMonTemperatureGetDegC();
   curState = 0;

   // read the MODE_CONF register in CCFG
   ccfg_ModeConfReg = HWREG( CCFG_BASE + CCFG_O_MODE_CONF );
   // Get VDDR_TRIM_SLEEP_DELTA + 1 (sign extended)
   deltaVddrSleepTrim = ((((int32_t) ccfg_ModeConfReg )
      << ( 32 - CCFG_MODE_CONF_VDDR_TRIM_SLEEP_DELTA_WIDTH - CCFG_MODE_CONF_VDDR_TRIM_SLEEP_DELTA_S ))
      >> ( 32 - CCFG_MODE_CONF_VDDR_TRIM_SLEEP_DELTA_WIDTH )) + 1;
   // Do temperature compensation if enabled
   if (( ccfg_ModeConfReg & CCFG_MODE_CONF_VDDR_TRIM_SLEEP_TC ) == 0 ) {
      int32_t tcDelta = ( 62 - curTemp ) >> 3;
      if ( tcDelta > 8 ) tcDelta = 8;
      if ( tcDelta > deltaVddrSleepTrim ) deltaVddrSleepTrim = tcDelta;
   }
   {
      vddrTrimSleep = SignExtendVddrTrimValue((
         HWREG( FCFG1_BASE + FCFG1_O_LDO_TRIM ) &
         FCFG1_LDO_TRIM_VDDR_TRIM_SLEEP_M ) >>
         FCFG1_LDO_TRIM_VDDR_TRIM_SLEEP_S ) ;
      vddrTrimActve = SignExtendVddrTrimValue((
         HWREG( FCFG1_BASE + FCFG1_O_SHDW_ANA_TRIM ) &
         FCFG1_SHDW_ANA_TRIM_VDDR_TRIM_M ) >>
         FCFG1_SHDW_ANA_TRIM_VDDR_TRIM_S ) ;
   }
   vddrTrimSleep += deltaVddrSleepTrim;
   if ( vddrTrimSleep >  21 ) vddrTrimSleep =  21;
   if ( vddrTrimSleep < -10 ) vddrTrimSleep = -10;
   // Write adjusted value using MASKED write (MASK8)
   HWREGH( ADI3_BASE + ADI_O_MASK8B + ( ADI_3_REFSYS_O_DCDCCTL1 * 2 )) = (( ADI_3_REFSYS_DCDCCTL1_VDDR_TRIM_SLEEP_M << 8 ) |
      (( vddrTrimSleep << ADI_3_REFSYS_DCDCCTL1_VDDR_TRIM_SLEEP_S ) & ADI_3_REFSYS_DCDCCTL1_VDDR_TRIM_SLEEP_M ));

   prcmRamRetention = HWREG( PRCM_BASE + PRCM_O_RAMRETEN );
   if ( prcmRamRetention & PRCM_RAMRETEN_VIMS_M ) {
      curState |= PD_STATE_CACHE_RET;
   }
   if ( prcmRamRetention & PRCM_RAMRETEN_RFC ) {
      curState |= PD_STATE_RFMEM_RET;
   }
   if ( xoscPowerMode != XOSC_IN_HIGH_POWER_MODE ) {
      curState |= PD_STATE_XOSC_LPM;
   }

   //--- Spec. point 2 ---
   if ((( curTemp - powerQualGlobals.pdTemp ) >= 5 ) || ( curState != powerQualGlobals.pdState )) {
      //--- Spec. point 3 ---
      shiftedTemp = curTemp - 15;

      //--- Spec point 4 ---
      //4. Check for external VDDR load option (may not be supported): ext_load = (VDDR_EXT_LOAD=0 in CCFG)
      // Currently not implementing external load handling
      // if ( __ccfg.ulModeConfig & MODE_CONF_VDDR_EXT_LOAD ) {
      // }

      pLookupTable = (uint32_t *)( FCFG1_BASE + FCFG1_O_PWD_CURR_20C );

      //--- Spec point 5 ---
      di    = 0;
      ti    = 0;
      if ( shiftedTemp >= 0 ) {
         //--- Spec point 5.a ---
         shiftedTemp += ( shiftedTemp << 4 );

         //--- Spec point 5.b ---
         ti = ( shiftedTemp >> 8 );
         if ( ti > 7 ) {
            ti = 7;
         }
         dii = ti;
         if ( dii > 6 ) {
            dii = 6;
         }

         //--- Spec point 5.c ---
         cd = pLookupTable[ dii + 1 ] - pLookupTable[ dii ];

         //--- Spec point 5.d ---
         di = cd & 0xFF;

         //--- Spec point 5.e ---
         if ( curState & PD_STATE_XOSC_LPM ) {
            di += (( cd >> 8 ) & 0xFF );
         }
         if ( curState & PD_STATE_RFMEM_RET ) {
            di += (( cd >> 16 ) & 0xFF );
         }
         if ( curState & PD_STATE_CACHE_RET ) {
            di += (( cd >> 24 ) & 0xFF );
         }

         //--- Spec point 5.f ---
         // Currently not implementing external load handling
      }

      //--- Spec. point 6 ---
      cl = pLookupTable[ ti ];

      //--- Spec. point 7 ---
      load = cl & 0xFF;

      //--- Spec. point 8 ---
      if ( curState & PD_STATE_XOSC_LPM ) {
         load += (( cl >> 8 ) & 0xFF );
      }
      if ( curState & PD_STATE_RFMEM_RET ) {
         load += (( cl >> 16 ) & 0xFF );
      }
      if ( curState & PD_STATE_CACHE_RET ) {
         load += (( cl >> 24 ) & 0xFF );
      }

      //--- Spec. point 9 ---
      load += ((( di * ( shiftedTemp - ( ti << 8 ))) + 128 ) >> 8 );

      // Currently not implementing external load handling
      // if ( __ccfg.ulModeConfig & MODE_CONF_VDDR_EXT_LOAD ) {
         //--- Spec. point 10 ---
      // } else {
         //--- Spec. point 11 ---
         diffVddrActiveSleep = ( vddrTrimActve - vddrTrimSleep );
         if ( diffVddrActiveSleep < 1 ) diffVddrActiveSleep = 1;
         k = ( diffVddrActiveSleep * 52 );
      // }

      //--- Spec. point 12 ---

      vddrCap = ( ccfg_ModeConfReg & CCFG_MODE_CONF_VDDR_CAP_M ) >> CCFG_MODE_CONF_VDDR_CAP_S;
      newRechargePeriod = ( vddrCap * k ) / load;
      if ( newRechargePeriod > 0xFFFF ) {
         newRechargePeriod = 0xFFFF;
      }
      powerQualGlobals.pdRechargePeriod = newRechargePeriod;

      //--- Spec. point 13 ---
      if ( curTemp >  127 ) curTemp =  127;
      if ( curTemp < -128 ) curTemp = -128;
      powerQualGlobals.pdTemp    = curTemp;
      powerQualGlobals.pdState   = curState;
   }

   powerQualGlobals.pdTime    = HWREG( AON_RTC_BASE + AON_RTC_O_SEC );

   // Calculate PER_E and PER_M (based on powerQualGlobals.pdRechargePeriod)
   // Round downwards but make sure PER_E=0 and PER_M=1 is the minimum possible setting.
   // (assuming that powerQualGlobals.pdRechargePeriod always are <= 0xFFFF)
   perE = 0;
   perM = powerQualGlobals.pdRechargePeriod;
   if ( perM < 31 ) {
      perM = 31;
      powerQualGlobals.pdRechargePeriod = 31;
   }
   while ( perM > 511 ) {
      perM >>= 1;
      perE  += 1;
   }
   perM = ( perM - 15 ) >> 4;

   HWREG( AON_WUC_BASE + AON_WUC_O_RECHARGECFG ) =
      ( 0x80A4E700                          ) |
      ( perM << AON_WUC_RECHARGECFG_PER_M_S ) |
      ( perE << AON_WUC_RECHARGECFG_PER_E_S ) ;
   HWREG( AON_WUC_BASE + AON_WUC_O_RECHARGESTAT ) = 0;
}


//*****************************************************************************
//
// SysCtrlAdjustRechargeAfterPowerDown()
//
//*****************************************************************************
void
SysCtrlAdjustRechargeAfterPowerDown( void )
{
   int32_t     curTemp                 ;
   uint32_t    longestRechargePeriod   ;
   uint32_t    deltaTime               ;
   uint32_t    newRechargePeriod       ;

   //--- Spec. point 2 ---
   longestRechargePeriod = ( HWREG( AON_WUC_BASE + AON_WUC_O_RECHARGESTAT ) &
      AON_WUC_RECHARGESTAT_MAX_USED_PER_M ) >>
      AON_WUC_RECHARGESTAT_MAX_USED_PER_S ;

   if ( longestRechargePeriod != 0 ) {
      //--- Spec. changed (originaly point 1) ---
      curTemp = AONBatMonTemperatureGetDegC();
      if ( curTemp < powerQualGlobals.pdTemp ) {
         if ( curTemp < -128 ) {
            curTemp = -128;
         }
         powerQualGlobals.pdTemp = curTemp;
      }

      //--- Spec. point 4 ---
      if ( longestRechargePeriod < powerQualGlobals.pdRechargePeriod ) {
         powerQualGlobals.pdRechargePeriod = longestRechargePeriod;
      } else {
         //--- Spec. point 5 ---
         deltaTime = HWREG( AON_RTC_BASE + AON_RTC_O_SEC ) - powerQualGlobals.pdTime + 2;
         if ( deltaTime > 31 ) {
            deltaTime = 31;
         }
         newRechargePeriod = powerQualGlobals.pdRechargePeriod + (( longestRechargePeriod - powerQualGlobals.pdRechargePeriod ) >> (deltaTime>>1));
         if ( newRechargePeriod > 0xFFFF ) {
            newRechargePeriod = 0xFFFF;
         }
         powerQualGlobals.pdRechargePeriod = newRechargePeriod;
      }
   }
}


//*****************************************************************************
//
// SysCtrl_DCDC_VoltageConditionalControl()
//
//*****************************************************************************
void
SysCtrl_DCDC_VoltageConditionalControl( void )
{
   uint32_t batThreshold     ;  // Fractional format with 8 fractional bits.
   uint32_t aonBatmonBat     ;  // Fractional format with 8 fractional bits.
   uint32_t ccfg_ModeConfReg ;  // Holds a copy of the CCFG_O_MODE_CONF register.
   uint32_t aonSysctlPwrctl  ;  // Reflect whats read/written to the AON_SYSCTL_O_PWRCTL register.

   //
   // We could potentially call this function before any battery voltage measurement
   // is made/available. In that case we must make sure that we do not turn off the DCDC.
   // This can be done by doing nothing as long as the battery voltage is 0 (Since the
   // reset value of the battery voltage register is 0).
   //
   aonBatmonBat = HWREG( AON_BATMON_BASE + AON_BATMON_O_BAT );
   if ( aonBatmonBat != 0 ) {
      //
      // Check if Voltage Conditional Control is enabled
      // It is enabled if both:
      // - DCDC in use (either in active or recharge mode), (in use if one of the corresponding CCFG bits are zero).
      // - Alternative DCDC settings are enabled ( DIS_ALT_DCDC_SETTING == 0 )
      //
      ccfg_ModeConfReg = HWREG( CCFG_BASE + CCFG_O_MODE_CONF );

      if (((( ccfg_ModeConfReg & CCFG_MODE_CONF_DCDC_RECHARGE_M ) == 0                                            ) ||
           (( ccfg_ModeConfReg & CCFG_MODE_CONF_DCDC_ACTIVE_M   ) == 0                                            )    ) &&
          (( HWREG( CCFG_BASE + CCFG_O_SIZE_AND_DIS_FLAGS ) & CCFG_SIZE_AND_DIS_FLAGS_DIS_ALT_DCDC_SETTING ) == 0      )    )
      {
         aonSysctlPwrctl = HWREG( AON_SYSCTL_BASE + AON_SYSCTL_O_PWRCTL );
         batThreshold    = (((( HWREG( CCFG_BASE + CCFG_O_MODE_CONF_1 ) &
            CCFG_MODE_CONF_1_ALT_DCDC_VMIN_M ) >>
            CCFG_MODE_CONF_1_ALT_DCDC_VMIN_S ) + 28 ) << 4 );

         if ( aonSysctlPwrctl & ( AON_SYSCTL_PWRCTL_DCDC_EN_M | AON_SYSCTL_PWRCTL_DCDC_ACTIVE_M )) {
            //
            // DCDC is ON, check if it should be switched off
            //
            if ( aonBatmonBat < batThreshold ) {
               aonSysctlPwrctl &= ~( AON_SYSCTL_PWRCTL_DCDC_EN_M | AON_SYSCTL_PWRCTL_DCDC_ACTIVE_M );

               HWREG( AON_SYSCTL_BASE + AON_SYSCTL_O_PWRCTL ) = aonSysctlPwrctl;
            }
         } else {
            //
            // DCDC is OFF, check if it should be switched on
            //
            if ( aonBatmonBat > batThreshold ) {
               if (( ccfg_ModeConfReg & CCFG_MODE_CONF_DCDC_RECHARGE_M ) == 0 ) aonSysctlPwrctl |= AON_SYSCTL_PWRCTL_DCDC_EN_M     ;
               if (( ccfg_ModeConfReg & CCFG_MODE_CONF_DCDC_ACTIVE_M   ) == 0 ) aonSysctlPwrctl |= AON_SYSCTL_PWRCTL_DCDC_ACTIVE_M ;

               HWREG( AON_SYSCTL_BASE + AON_SYSCTL_O_PWRCTL ) = aonSysctlPwrctl;
            }
         }
      }
   }
}


//*****************************************************************************
//
// SysCtrlResetSourceGet()
//
//*****************************************************************************
uint32_t
SysCtrlResetSourceGet( void )
{
   if ( HWREG( AON_SYSCTL_BASE + AON_SYSCTL_O_RESETCTL ) & AON_SYSCTL_RESETCTL_WU_FROM_SD_M ) {
      return ( RSTSRC_WAKEUP_FROM_SHUTDOWN );
   } else {
      return (( HWREG( AON_SYSCTL_BASE + AON_SYSCTL_O_RESETCTL ) &
                AON_SYSCTL_RESETCTL_RESET_SRC_M ) >>
                AON_SYSCTL_RESETCTL_RESET_SRC_S ) ;
   }
}
