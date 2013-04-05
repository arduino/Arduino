//#############################################################################
//
//! \file   f2802x_common/source/pwm.c
//!
//! \brief  Contains the various functions related to the 
//!         pulse width modulation (PWM) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes
#include "DSP28x_Project.h"
#include "f2802x_common/include/pwm.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

void PWM_clearTripZone(PWM_Handle pwmHandle, const PWM_TripZoneFlag_e tripZoneFlag)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->TZCLR |= tripZoneFlag;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneState_DCAEVT1() function


void PWM_decrementDeadBandFallingEdgeDelay(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    pwm->DBFED--;

    return;
} // end of PWM_deccrementDeadBandFallingEdgeDelay() function


void PWM_decrementDeadBandRisingEdgeDelay(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    pwm->DBRED--;

    return;
} // end of PWM_deccrementDeadBandRisingEdgeDelay() function


void PWM_disableAutoConvert(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->HRCNFG &= ~PWM_HRCNFG_AUTOCONV_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableAutoConvert() function


void PWM_disableChopping(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // clear the bits
    pwm->PCCTL &= (~PWM_PCCTL_CHPEN_BITS);

    return;
} // end of PWM_disableChopping() function


void PWM_disableCounterLoad(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_PHSEN_BITS);

    return;
} // end of PWM_disableCounterLoad() function


void PWM_disableDeadBand(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->DBCTL = 0;

    return;
} // end of PWM_disableDeadBand() function


void PWM_disableDeadBandHalfCycle(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->DBCTL &= (~PWM_DBCTL_HALFCYCLE_BITS);

    return;
} // end of PWM_disableDeadBandHalfCycle() function


void PWM_disableDigitalCompareBlankingWindow(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->DCFCTL &= ~PWM_DCFCTL_BLANKE_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableDigitalCompareBlankingWindow() function


void PWM_disableDigitalCompareBlankingWindowInversion(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->DCFCTL &= ~PWM_DCFCTL_BLANKINV_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableDigitalCompareBlankingWindowInversion() function


void PWM_disableHrPeriod(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;
    
    // set the bits
    pwm->HRPCTL &= ~PWM_HRPCTL_HRPE_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableHrPeriod() function


void PWM_disableHrPhaseSync(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->HRPCTL &= ~PWM_HRPCTL_TBPHSHRLOADE_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableHrPhaseSync() function


void PWM_disableInt(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETSEL &= (~PWM_ETSEL_INTEN_BITS);

    return;
} // end of PWM_disableInt() function


void PWM_disableSocAPulse(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETSEL &= (~PWM_ETSEL_SOCAEN_BITS);

    return;
} // end of PWM_disableSocAPulse() function


void PWM_disableSocBPulse(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETSEL &= (~PWM_ETSEL_SOCBEN_BITS);

    return;
} // end of PWM_disableSocBPulse() function


void PWM_disableTripZones(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->TZSEL = 0;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableTripZones() function


void PWM_disableTripZoneInt(PWM_Handle pwmHandle, const PWM_TripZoneFlag_e interruptSource)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->TZEINT &= ~interruptSource;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableTripZoneInt() function


void PWM_disableTripZoneSrc(PWM_Handle pwmHandle, const PWM_TripZoneSrc_e src)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZSEL &= (~src);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_disableTripZoneSrc() function


void PWM_enableAutoConvert(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->HRCNFG |= PWM_HRCNFG_AUTOCONV_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_enableAutoConvert() function


void PWM_enableChopping(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // set the bits
    pwm->PCCTL = (uint16_t)1;

    return;
} // end of PWM_enableChopping() function


void PWM_enableCounterLoad(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // set the bits
    pwm->TBCTL |= PWM_TBCTL_PHSEN_BITS;

    return;
} // end of PWM_enableCounterLoad() function


void PWM_enableDeadBandHalfCycle(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // set the bits
    pwm->DBCTL |= (uint16_t)PWM_DBCTL_HALFCYCLE_BITS;

    return;
} // end of PWM_enableDeadBandHalfCycle() function


void PWM_enableDigitalCompareBlankingWindow(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->DCFCTL |= PWM_DCFCTL_BLANKE_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_enableDigitalCompareBlankingWindow() function


void PWM_enableDigitalCompareBlankingWindowInversion(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->DCFCTL |= PWM_DCFCTL_BLANKINV_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_enableDigitalCompareBlankingWindowInversion() function


void PWM_enableHrPeriod(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->HRPCTL |= PWM_HRPCTL_HRPE_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_enableHrPeriod() function


void PWM_enableInt(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // set the bits
    pwm->ETSEL |= PWM_ETSEL_INTEN_BITS;

    return;
} // end of PWM_enableInt() function


void PWM_enableHrPhaseSync(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->HRPCTL |= PWM_HRPCTL_TBPHSHRLOADE_BITS;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_enableHrPhaseSync() function


void PWM_enableSocAPulse(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // set the bits
    pwm->ETSEL |= PWM_ETSEL_SOCAEN_BITS;

    return;
} // end of PWM_enableSocAPulse() function


void PWM_enableSocBPulse(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // set the bits
    pwm->ETSEL |= (uint16_t)PWM_ETSEL_SOCBEN_BITS;

    return;
} // end of PWM_enableSocBPulse() function


void PWM_enableTripZoneInt(PWM_Handle pwmHandle, const PWM_TripZoneFlag_e interruptSource)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->TZEINT |= interruptSource;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_enableTripZoneInt() function


void PWM_enableTripZoneSrc(PWM_Handle pwmHandle, const PWM_TripZoneSrc_e src)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    pwm->TZSEL |= src;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_enableTripZoneSrc() function


uint16_t PWM_getDeadBandFallingEdgeDelay(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return (pwm->DBFED);
} // end of PWM_getDeadBandFallingEdgeDelay() function


uint16_t PWM_getDeadBandRisingEdgeDelay(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    return (pwm->DBRED);
} // end of PWM_getDeadBandRisingEdgeDelay() function


uint16_t PWM_getIntCount(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    uint16_t intCount;

    intCount = pwm->ETPS & PWM_ETPS_INTCNT_BITS;

    return(intCount);
} // end of PWM_getIntCount() function

uint16_t PWM_getSocACount(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    uint16_t intCount;

    intCount = pwm->ETPS & PWM_ETPS_SOCACNT_BITS;

    intCount >>= 10;

    return(intCount);
} // end of PWM_getSocACount() function


uint16_t PWM_getSocBCount(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    uint16_t intCount;

    intCount = pwm->ETPS & (uint16_t)PWM_ETPS_SOCBCNT_BITS;

    intCount >>= 14;

    return(intCount);
} // end of PWM_getSocBCount() function


PWM_ShadowStatus_e PWM_getShadowStatus_CmpA(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    PWM_ShadowStatus_e status;


    // clear the bits
    status = (PWM_ShadowStatus_e)(pwm->TBCTL & (~PWM_CMPCTL_SHDWAFULL_BITS));

    status >>= 8;
    
    return(status);
} // end of PWM_getShadowStatus_CmpA() function


PWM_ShadowStatus_e PWM_getShadowStatus_CmpB(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    PWM_ShadowStatus_e status;


    // clear the bits
    status = (PWM_ShadowStatus_e)(pwm->TBCTL & (~PWM_CMPCTL_SHDWAFULL_BITS));

    status >>= 9;
    
    return(status);
} // end of PWM_getShadowStatus_CmpB() function


void PWM_setHrControlMode(PWM_Handle pwmHandle, const PWM_HrControlMode_e controlMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    pwm->HRCNFG &= ~PWM_HRCNFG_CTLMODE_BITS;
    
    pwm->HRCNFG |= controlMode;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setHrControlMode() function


void PWM_setHrEdgeMode(PWM_Handle pwmHandle, const PWM_HrEdgeMode_e edgeMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    pwm->HRCNFG &= ~PWM_HRCNFG_EDGMODE_BITS;
    
    pwm->HRCNFG |= edgeMode;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setHrEdgeMode() function


void PWM_setHrShadowMode(PWM_Handle pwmHandle, const PWM_HrShadowMode_e shadowMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    pwm->HRCNFG &= ~PWM_HRCNFG_HRLOAD_BITS;
    
    pwm->HRCNFG |= shadowMode;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setHrShadowMode() function


void PWM_incrementDeadBandFallingEdgeDelay(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    pwm->DBFED++;

    return;
} // end of PWM_incrementDeadBandFallingEdgeDelay() function


void PWM_incrementDeadBandRisingEdgeDelay(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    pwm->DBRED++;

    return;
} // end of PWM_incrementDeadBandRisingEdgeDelay() function


PWM_Handle PWM_init(void *pMemory, const size_t numBytes)
{
    PWM_Handle pwmHandle;


    if(numBytes < sizeof(PWM_Obj))
    return((PWM_Handle)NULL);


    // assign the handle
    pwmHandle = (PWM_Handle)pMemory;

    return(pwmHandle);
} // end of PWM_init() function


void PWM_setActionQual_CntDown_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLA &= (~PWM_AQCTL_CAD_BITS);

    // set the bits
    pwm->AQCTLA |= (actionQual << 6);

    return;
} // end of PWM_setActionQual_CntDown_CmpA_PwmA() function


void PWM_setActionQual_CntDown_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLB &= (~PWM_AQCTL_CAD_BITS);

    // set the bits
    pwm->AQCTLB |= (actionQual << 6);

    return;
} // end of PWM_setActionQual_CntDown_CmpA_PwmB() function


void PWM_setActionQual_CntDown_CmpB_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLA &= (~PWM_AQCTL_CBD_BITS);

    // set the bits
    pwm->AQCTLA |= (actionQual << 10);

    return;
} // end of PWM_setActionQual_CntDown_CmpB_PwmA() function


void PWM_setActionQual_CntDown_CmpB_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLB &= (~PWM_AQCTL_CBD_BITS);

    // set the bits
    pwm->AQCTLB |= (actionQual << 10);

    return;
} // end of PWM_setActionQual_CntDown_CmpB_PwmB() function


void PWM_setActionQual_CntUp_CmpA_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLA &= (~PWM_AQCTL_CAU_BITS);

    // set the bits
    pwm->AQCTLA |= (actionQual << 4);

    return;
} // end of PWM_setActionQual_CntUp_CmpA_PwmA() function


void PWM_setActionQual_CntUp_CmpA_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLB &= (~PWM_AQCTL_CAU_BITS);

    // set the bits
    pwm->AQCTLB |= (actionQual << 4);

    return;
} // end of PWM_setActionQual_CntUp_CmpA_PwmB() function


void PWM_setActionQual_CntUp_CmpB_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLA &= (~PWM_AQCTL_CBU_BITS);

    // set the bits
    pwm->AQCTLA |= (actionQual << 8);

    return;
} // end of PWM_setActionQual_CntUp_CmpB_PwmA() function


void PWM_setActionQual_CntUp_CmpB_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLB &= (~PWM_AQCTL_CBU_BITS);

    // set the bits
    pwm->AQCTLB |= (actionQual << 8);

    return;
} // end of PWM_setActionQual_CntUp_CmpB_PwmB() function


void PWM_setActionQual_Period_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLA &= (~PWM_AQCTL_PRD_BITS);

    // set the bits
    pwm->AQCTLA |= (actionQual << 2);

    return;
} // end of PWM_setActionQual_Period_PwmA() function


void PWM_setActionQual_Period_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLB &= (~PWM_AQCTL_PRD_BITS);

    // set the bits
    pwm->AQCTLB |= (actionQual << 2);

    return;
} // end of PWM_setActionQual_Period_PwmB() function


void PWM_setActionQual_Zero_PwmA(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLA &= (~PWM_AQCTL_ZRO_BITS);

    // set the bits
    pwm->AQCTLA |= actionQual;

    return;
} // end of PWM_setActionQualZero_PwmA() function


void PWM_setActionQual_Zero_PwmB(PWM_Handle pwmHandle, const PWM_ActionQual_e actionQual)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->AQCTLB &= (~PWM_AQCTL_ZRO_BITS);

    // set the bits
    pwm->AQCTLB |= actionQual;

    return;
} // end of PWM_setActionQualZero_PwmB() function


void PWM_setChoppingClkFreq(PWM_Handle pwmHandle, const PWM_ChoppingClkFreq_e clkFreq)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->PCCTL &= (~PWM_PCCTL_CHPFREQ_BITS);

    // set the bits
    pwm->PCCTL |= clkFreq;

    return;
} // end of PWM_setChoppingClkFreq() function


void PWM_setChoppingDutyCycle(PWM_Handle pwmHandle, const PWM_ChoppingDutyCycle_e dutyCycle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->PCCTL &= (~PWM_PCCTL_CHPDUTY_BITS);

    // set the bits
    pwm->PCCTL |= dutyCycle;

    return;
} // end of PWM_setChoppingDutyCycle() function


void PWM_setChoppingPulseWidth(PWM_Handle pwmHandle, const PWM_ChoppingPulseWidth_e pulseWidth)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->PCCTL &= (~PWM_PCCTL_OSHTWTH_BITS);

    // set the bits
    pwm->PCCTL |= pulseWidth;

    return;
} // end of PWM_setChoppingPulseWidth() function


void PWM_setClkDiv(PWM_Handle pwmHandle, const PWM_ClkDiv_e clkDiv)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_CLKDIV_BITS);

    // set the bits
    pwm->TBCTL |= clkDiv;

    return;
} // end of PWM_setClkDiv() function


void PWM_setCount(PWM_Handle pwmHandle, const uint16_t count)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // set the bits
    pwm->TBCTR = count;

    return;
} // end of PWM_setCount() function


void PWM_setCounterMode(PWM_Handle pwmHandle, const PWM_CounterMode_e counterMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_CTRMODE_BITS);

    // set the bits
    pwm->TBCTL |= counterMode;

    return;
} // end of PWM_setCounterMode() function


void PWM_setDeadBandFallingEdgeDelay(PWM_Handle pwmHandle, const uint16_t delay)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    pwm->DBFED |= delay;

    return;
} // end of PWM_setDeadBandFallingEdgeDelay() function


void PWM_setDeadBandInputMode(PWM_Handle pwmHandle, const PWM_DeadBandInputMode_e inputMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->DBCTL &= (~PWM_DBCTL_INMODE_BITS);
    
    // set the bits
    pwm->DBCTL |= inputMode;

    return;
} // end of PWM_setDeadBandInputMode() function


void PWM_setDeadBandOutputMode(PWM_Handle pwmHandle, const PWM_DeadBandOutputMode_e outputMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->DBCTL &= (~PWM_DBCTL_OUTMODE_BITS);
    
    // set the bits
    pwm->DBCTL |= outputMode;

    return;
} // end of PWM_setDeadBandOutputMode() function


void PWM_setDeadBandPolarity(PWM_Handle pwmHandle, const PWM_DeadBandPolarity_e polarity)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->DBCTL &= (~PWM_DBCTL_POLSEL_BITS);
    
    // set the bits
    pwm->DBCTL |= polarity;

    return;
} // end of PWM_setDeadBandPolarity() function


void PWM_setDeadBandRisingEdgeDelay(PWM_Handle pwmHandle, const uint16_t delay)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    pwm->DBRED |= delay;

    return;
} // end of PWM_setDeadBandRisingEdgeDelay() function


void PWM_setDigitalCompareFilterSource(PWM_Handle pwmHandle, 
                                const PWM_DigitalCompare_FilterSrc_e input)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Clear any old values
    pwm->DCFCTL &= ~PWM_DCFCTL_SRCSEL_BITS;
    
    // Set the new value
    pwm->DCFCTL |= input;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setDigitalCompareFilterSource() function


void PWM_setDigitalCompareBlankingPulse(PWM_Handle pwmHandle, 
                                const PWM_DigitalCompare_PulseSel_e pulseSelect)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Clear any old values
    pwm->DCFCTL &= ~PWM_DCFCTL_PULSESEL_BITS;
    
    // Set the new value
    pwm->DCFCTL |= pulseSelect << 4;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setDigitalCompareBlankingPulse() function


void PWM_setDigitalCompareFilterOffset(PWM_Handle pwmHandle, 
                                const uint16_t offset)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // Set the filter offset
    pwm->DCFOFFSET = offset;

    return;
} // end of PWM_setDigitalCompareFilterOffset() function


void PWM_setDigitalCompareFilterWindow(PWM_Handle pwmHandle, 
                                const uint16_t window)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    // Set the window
    pwm->DCFWINDOW = window;

    return;
} // end of PWM_setDigitalCompareFilterWindow() function


void PWM_setDigitalCompareInput(PWM_Handle pwmHandle, 
                                const PWM_DigitalCompare_Input_e input, 
                                const PWM_DigitalCompare_InputSel_e inputSel)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Clear any old values
    pwm->DCTRIPSEL &= ~(0x000F << input);

    // Set the new value
    pwm->DCTRIPSEL |= (inputSel << input);
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setDigitalCompareInput() function


void PWM_setDigitalCompareAEvent1(PWM_Handle pwmHandle, 
                                const bool_t selectFilter,
                                const bool_t disableSync,
                                const bool_t enableSoc,
                                const bool_t generateSync)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Clear any old values
    pwm->DCACTL &= ~0x000F;
    
    // Set the new value
    pwm->DCACTL |= selectFilter | (disableSync << 1) | (enableSoc << 2) | (generateSync << 3);
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setDigitalCompareAEvent1() function


void PWM_setDigitalCompareAEvent2(PWM_Handle pwmHandle, 
                                const bool_t selectFilter,
                                const bool_t disableSync)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Clear any old values
    pwm->DCACTL &= ~0x0300;
    
    // Set the new value
    pwm->DCACTL |= (selectFilter << 8) | (disableSync << 9) ;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setDigitalCompareAEvent2() function


void PWM_setDigitalCompareBEvent1(PWM_Handle pwmHandle, 
                                const bool_t selectFilter,
                                const bool_t disableSync,
                                const bool_t enableSoc,
                                const bool_t generateSync)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Clear any old values
    pwm->DCBCTL &= ~0x000F;
    
    // Set the new value
    pwm->DCBCTL |= selectFilter | (disableSync << 1) | (enableSoc << 2) | (generateSync << 3);
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setDigitalCompareBEvent1() function


void PWM_setDigitalCompareBEvent2(PWM_Handle pwmHandle, 
                                const bool_t selectFilter,
                                const bool_t disableSync)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;
    
    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Clear any old values
    pwm->DCBCTL &= ~0x0300;
    
    // Set the new value
    pwm->DCBCTL |= (selectFilter << 8) | (disableSync << 9) ;
    
    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setDigitalCompareBEvent2() function


void PWM_setHighSpeedClkDiv(PWM_Handle pwmHandle, const PWM_HspClkDiv_e clkDiv)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_HSPCLKDIV_BITS);

    // set the bits
    pwm->TBCTL |= clkDiv;

    return;
} // end of PWM_setHighSpeedClkDiv() function


void PWM_setIntMode(PWM_Handle pwmHandle, const PWM_IntMode_e intMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETSEL &= (~PWM_ETSEL_INTSEL_BITS);

    // set the bits
    pwm->ETSEL |= intMode;

    return;
} // end of PWM_setIntMode() function


void PWM_setIntPeriod(PWM_Handle pwmHandle, const PWM_IntPeriod_e intPeriod)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETPS &= (~PWM_ETPS_INTPRD_BITS);

    // set the bits
    pwm->ETPS |= intPeriod;

    return;
} // end of PWM_setIntPeriod() function


void PWM_setLoadMode_CmpA(PWM_Handle pwmHandle, const PWM_LoadMode_e loadMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->CMPCTL &= (~PWM_CMPCTL_LOADAMODE_BITS);

    // set the bits
    pwm->CMPCTL |= loadMode;

    return;
} // end of PWM_setLoadMode_CmpA() function


void PWM_setLoadMode_CmpB(PWM_Handle pwmHandle, const PWM_LoadMode_e loadMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->CMPCTL &= (~PWM_CMPCTL_LOADBMODE_BITS);

    // set the bits
    pwm->CMPCTL |= (loadMode << 2);

    return;
} // end of PWM_setLoadMode_CmpB() function


void PWM_setPeriod(PWM_Handle pwmHandle, const uint16_t period)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // initialize the Time-Base Period Register (TBPRD).  These bits determine the period of the time-base counter.
    pwm->TBPRD = period;

    return;
} // end of PWM_setPeriod() function


void PWM_setPeriodHr(PWM_Handle pwmHandle, const uint16_t period)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // initialize the Time-Base Period Register (TBPRD).  These bits determine the period of the time-base counter.
    pwm->TBPRDHR = period;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of PWM_setPeriodHr() function


void PWM_setPhase(PWM_Handle pwmHandle, const uint16_t phase)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    pwm->TBPHS = phase;

    return;
} // end of PWM_setPhase() function


void PWM_setPhaseDir(PWM_Handle pwmHandle, const PWM_PhaseDir_e phaseDir)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_PHSDIR_BITS);

    // set the bits
    pwm->TBCTL |= phaseDir;

    return;
} // end of PWM_setPhaseDir() function


void PWM_setPeriodLoad(PWM_Handle pwmHandle, const PWM_PeriodLoad_e periodLoad)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_PRDLD_BITS);

    // set the bits
    pwm->TBCTL |= periodLoad;

    return;
} // end of PWM_setPeriodLoad() function


void PWM_setRunMode(PWM_Handle pwmHandle, const PWM_RunMode_e runMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_FREESOFT_BITS);

    // set the bits
    pwm->TBCTL |= runMode;

    return;
} // end of PWM_setRunMode() function


void PWM_setSocAPeriod(PWM_Handle pwmHandle, const PWM_SocPeriod_e intPeriod)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETPS &= (~PWM_ETPS_SOCAPRD_BITS);

    // set the bits
    pwm->ETPS |= (intPeriod << 8);

    return;
} // end of PWM_setSocAPeriod() function


void PWM_setSocAPulseSrc(PWM_Handle pwmHandle, const PWM_SocPulseSrc_e pulseSrc)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETSEL &= (~PWM_ETSEL_SOCASEL_BITS);

    // set the bits
    pwm->ETSEL |= (pulseSrc << 8);

    return;
} // end of PWM_setSocAPulseSrc() function


void PWM_setSocBPeriod(PWM_Handle pwmHandle, const PWM_SocPeriod_e intPeriod)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETPS &= (~PWM_ETPS_SOCBPRD_BITS);

    // set the bits
    pwm->ETPS |= (intPeriod << 12);

    return;
} // end of PWM_setSocBPeriod() function


void PWM_setSocBPulseSrc(PWM_Handle pwmHandle, const PWM_SocPulseSrc_e pulseSrc)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->ETSEL &= (~PWM_ETSEL_SOCBSEL_BITS);

    // set the bits
    pwm->ETSEL |= (pulseSrc << 12);

    return;
} // end of PWM_setSocBPulseSrc() function


void PWM_setShadowMode_CmpA(PWM_Handle pwmHandle, const PWM_ShadowMode_e shadowMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->CMPCTL &= (~PWM_CMPCTL_SHDWAMODE_BITS);

    // set the bits
    pwm->CMPCTL |= (shadowMode << 4);

    return;
} // end of PWM_setShadowMode_CmpA() function


void PWM_setShadowMode_CmpB(PWM_Handle pwmHandle, const PWM_ShadowMode_e shadowMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->CMPCTL &= (~PWM_CMPCTL_SHDWBMODE_BITS);

    // set the bits
    pwm->CMPCTL |= (shadowMode << 6);

    return;
} // end of PWM_setShadowMode_CmpB() function


void PWM_setSwSync(PWM_Handle pwmHandle)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // set the bits
    pwm->TBCTL |= 1 << 6;

    return;
} // end of PWM_setSwSync() function


void PWM_setSyncMode(PWM_Handle pwmHandle, const PWM_SyncMode_e syncMode)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    // clear the bits
    pwm->TBCTL &= (~PWM_TBCTL_SYNCOSEL_BITS);

    // set the bits
    pwm->TBCTL |= syncMode;

    return;
} // end of PWM_setSyncMode() function

void PWM_setTripZoneDCEventSelect_DCAEVT1(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZDCSEL &= (~PWM_TZDCSEL_DCAEVT1_BITS);

    // set the bits
    pwm->TZDCSEL |= tripZoneEvent << 0;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneDCEventSelect_DCAEVT1() function


void PWM_setTripZoneDCEventSelect_DCAEVT2(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZDCSEL &= (~PWM_TZDCSEL_DCAEVT2_BITS);

    // set the bits
    pwm->TZDCSEL |= tripZoneEvent << 3;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneDCEventSelect_DCAEVT2() function


void PWM_setTripZoneDCEventSelect_DCBEVT1(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZDCSEL &= (~PWM_TZDCSEL_DCBEVT1_BITS);

    // set the bits
    pwm->TZDCSEL |= tripZoneEvent << 6;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneDCEventSelect_DCBEVT1() function


void PWM_setTripZoneDCEventSelect_DCBEVT2(PWM_Handle pwmHandle, const PWM_TripZoneDCEventSel_e tripZoneEvent)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZDCSEL &= (~PWM_TZDCSEL_DCBEVT2_BITS);

    // set the bits
    pwm->TZDCSEL |= tripZoneEvent << 9;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneDCEventSelect_DCBEVT2() function


void PWM_setTripZoneState_DCAEVT1(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZCTL &= (~PWM_TZCTL_DCAEVT1_BITS);

    // set the bits
    pwm->TZCTL |= tripZoneState << 4;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneState_DCAEVT1() function


void PWM_setTripZoneState_DCAEVT2(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZCTL &= (~PWM_TZCTL_DCAEVT2_BITS);

    // set the bits
    pwm->TZCTL |= tripZoneState << 6;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneState_DCAEVT2() function


void PWM_setTripZoneState_DCBEVT1(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZCTL &= (~PWM_TZCTL_DCBEVT1_BITS);

    // set the bits
    pwm->TZCTL |= tripZoneState << 8;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneState_DCBEVT1() function


void PWM_setTripZoneState_DCBEVT2(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZCTL &= (~PWM_TZCTL_DCBEVT2_BITS);

    // set the bits
    pwm->TZCTL |= tripZoneState << 10;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneState_DCBEVT2() function


void PWM_setTripZoneState_TZA(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZCTL &= (~PWM_TZCTL_TZA_BITS);

    // set the bits
    pwm->TZCTL |= tripZoneState << 0;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneState_TZA() function


void PWM_setTripZoneState_TZB(PWM_Handle pwmHandle, const PWM_TripZoneState_e tripZoneState)
{
    PWM_Obj *pwm = (PWM_Obj *)pwmHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    pwm->TZCTL &= (~PWM_TZCTL_TZB_BITS);

    // set the bits
    pwm->TZCTL |= tripZoneState << 2;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
}  // end of PWM_setTripZoneState_TZB() function


// end of file
