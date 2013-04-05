//#############################################################################
//
//! \file   f2802x_common/source/adc.c
//!
//! \brief  Contains the various functions related to the analog-to-digital 
//!         converter (ADC) object
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
#include "f2802x_common/include/adc.h"


// assembly file
extern void usDelay(unsigned long Count);


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions

void ADC_disable(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    adc->ADCCTL1 &= (~ADC_ADCCTL1_ADCENABLE_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_disable() function


void ADC_disableBandGap(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCCTL1 &= (~ADC_ADCCTL1_ADCBGPWD_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_disableBandGap() function


void ADC_disableInt(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;
    uint_least8_t regNumber = intNumber >> 1;
    uint16_t clearValue = ADC_INTSELxNy_INTE_BITS << 
    (ADC_INTSELxNy_NUMBITS_PER_REG - ((intNumber & 0x1) << ADC_INTSELxNy_LOG2_NUMBITS_PER_REG));


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->INTSELxNy[regNumber] &= (~clearValue);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_disableInt() function


void ADC_disableRefBuffers(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCCTL1 &= (~ADC_ADCCTL1_ADCREFPWD_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_disableRefBuffers() function

void ADC_disableTempSensor(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Disable Temp Sensor conversion
    adc->ADCCTL1 &= ~ADC_ADCCTL1_TEMPCONV_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_disableTempSensor() function


void ADC_enable(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    adc->ADCCTL1 |= ADC_ADCCTL1_ADCENABLE_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_enable() function


void ADC_enableBandGap(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    adc->ADCCTL1 |= ADC_ADCCTL1_ADCBGPWD_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_enableBandGap() function


void ADC_enableInt(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;
    uint_least8_t regNumber = intNumber >> 1;
    uint_least8_t lShift = ADC_INTSELxNy_NUMBITS_PER_REG - (((intNumber+1) & 0x1) << ADC_INTSELxNy_LOG2_NUMBITS_PER_REG);
    uint16_t setValue = ADC_INTSELxNy_INTE_BITS << lShift;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the value
    adc->INTSELxNy[regNumber] |= setValue;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_enableInt() function


void ADC_enableRefBuffers(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    adc->ADCCTL1 |= ADC_ADCCTL1_ADCREFPWD_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_enableRefBuffers() function

void ADC_enableTempSensor(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // Enable Temp Sensor conversion
    adc->ADCCTL1 |= ADC_ADCCTL1_TEMPCONV_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_enableTempSensor() function

// current sampled last
ADC_Handle ADC_init(void *pMemory, const size_t numBytes)
{
    ADC_Handle adcHandle;


    if(numBytes < sizeof(ADC_Obj))
    return((ADC_Handle)NULL);


    // assign the handle
    adcHandle = (ADC_Handle)pMemory;

    return(adcHandle);
} // end of ADC_init() function


void ADC_powerDown(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCCTL1 &= (~ADC_ADCCTL1_ADCPWDN_BITS);

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_powerDown() function


void ADC_powerUp(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    adc->ADCCTL1 |= ADC_ADCCTL1_ADCPWDN_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_powerUp() function


void ADC_reset(ADC_Handle adcHandle)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // set the bits
    adc->ADCCTL1 |= (uint16_t)ADC_ADCCTL1_RESET_BITS;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_reset() function


void ADC_setIntMode(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber, const ADC_IntMode_e intMode)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;
    uint_least8_t regNumber = intNumber >> 1;
    uint_least8_t lShift = (ADC_INTSELxNy_NUMBITS_PER_REG - (((intNumber+1) & 0x1) << ADC_INTSELxNy_LOG2_NUMBITS_PER_REG));
    uint16_t clearValue = ADC_INTSELxNy_INTCONT_BITS << lShift;
    uint16_t setValue = intMode << lShift;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->INTSELxNy[regNumber] &= ~(clearValue);


    // set the bits
    adc->INTSELxNy[regNumber] |= setValue;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setIntMode() function


void ADC_setIntPulseGenMode(ADC_Handle adcHandle, const ADC_IntPulseGenMode_e pulseMode)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCCTL1 &= (~ADC_ADCCTL1_INTPULSEPOS_BITS);


    // set the bits
    adc->ADCCTL1 |= pulseMode;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setIntPulseGenMode() function


void ADC_setIntSrc(ADC_Handle adcHandle, const ADC_IntNumber_e intNumber, const ADC_IntSrc_e intSrc)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;
    uint_least8_t regNumber = intNumber >> 1;
    uint_least8_t lShift = (ADC_INTSELxNy_NUMBITS_PER_REG - (((intNumber+1) & 0x1) << ADC_INTSELxNy_LOG2_NUMBITS_PER_REG));
    uint16_t clearValue = ADC_INTSELxNy_INTSEL_BITS << lShift;
    uint16_t setValue = intSrc << lShift;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;


    // clear the bits
    adc->INTSELxNy[regNumber] &= ~(clearValue);


    // set the bits
    adc->INTSELxNy[regNumber] |= setValue;


    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setIntSrc() function


void ADC_setSampleMode(ADC_Handle adcHandle, const ADC_SampleMode_e sampleMode)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;
    

    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    if(sampleMode & ADC_ADCSAMPLEMODE_SEPARATE_FLAG) // separate
    {
      adc->ADCSAMPLEMODE &= (~(sampleMode - ADC_ADCSAMPLEMODE_SEPARATE_FLAG));
    }
    else
    {
      adc->ADCSAMPLEMODE |= sampleMode;
    }

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setSampleMode() function


void ADC_setSocChanNumber(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocChanNumber_e chanNumber)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCSOCxCTL[socNumber] &= (~ADC_ADCSOCxCTL_CHSEL_BITS);


    // set the bits
    adc->ADCSOCxCTL[socNumber] |= chanNumber;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setSocChanNumber() function


void ADC_setSocSampleWindow(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocSampleWindow_e sampleWindow)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCSOCxCTL[socNumber] &= (~ADC_ADCSOCxCTL_ACQPS_BITS);


    // set the bits
    adc->ADCSOCxCTL[socNumber] |= sampleWindow;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setSocSampleDelay() function


void ADC_setSocTrigSrc(ADC_Handle adcHandle, const ADC_SocNumber_e socNumber, const ADC_SocTrigSrc_e trigSrc)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCSOCxCTL[socNumber] &= (~ADC_ADCSOCxCTL_TRIGSEL_BITS);


    // set the bits
    adc->ADCSOCxCTL[socNumber] |= trigSrc;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setSocTrigSrc() function


void ADC_setVoltRefSrc(ADC_Handle adcHandle, const ADC_VoltageRefSrc_e voltSrc)
{
    ADC_Obj *adc = (ADC_Obj *)adcHandle;


    ENABLE_PROTECTED_REGISTER_WRITE_MODE;

    // clear the bits
    adc->ADCCTL1 &= (~ADC_ADCCTL1_ADCREFSEL_BITS);


    // set the bits
    adc->ADCCTL1 |= voltSrc;

    DISABLE_PROTECTED_REGISTER_WRITE_MODE;

    return;
} // end of ADC_setVoltRefSrc() function


// end of file
