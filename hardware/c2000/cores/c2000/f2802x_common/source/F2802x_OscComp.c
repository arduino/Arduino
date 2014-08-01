// TI File $Revision: /main/2 $
// Checkin $Date: January 3, 2011   11:23:09 $
//###########################################################################
//
// FILE:   DSP2802x_OscComp.c
//
// TITLE:  DSP2802x oscillator compensation functions
//
// This file contains the functions which adjust the oscillator trim and compensate
// for frequency drift based on the current temperature sensor reading.
//
// This program makes use of variables stored in OTP during factory
// test.  These OTP locations on pre-TMS devices may not be populated.
// Ensure that the following memory locations in TI OTP are populated
// (not 0xFFFF) before use:
//
// 0x3D7E90 to 0x3D7EA4
//
// Note that these functions pull data from the OTP by calling functions which
// reside in OTP.  Therefore the OTP wait-states (controlled by
// FlashRegs.FOTPWAIT.bit.OTPWAIT) will significantly affect the time required
// to execute these functions.
//
//###########################################################################
// $TI Release: 2802x C/C++ Header Files and Peripheral Examples V1.29 $
// $Release Date: January 11, 2011 $
//###########################################################################

#include "F2802x_Device.h"     // Headerfile Include File
#include "f2802x_common/include/f2802x_examples.h"   // Examples Include File


// Useful definitions
  #define FP_SCALE 32768       // Scale factor for Q15 fixed point numbers (2^15)
  #define FP_ROUND FP_SCALE/2  // Quantity added to Q15 numbers before converting
                               // to integer to round the number

//Amount to add to Q16.15 fixed point number to shift from a fine trim range of
//(-31 to 31) to (1 to 63).  This guarantees that the trim is positive and can
//therefore be efficiently rounded
  #define OSC_POSTRIM 32
  #define OSC_POSTRIM_OFF FP_SCALE*OSC_POSTRIM

//The following functions return reference values stored in OTP.

//Slope used to compensate oscillator 1 (fine trim steps / ADC code). Stored
//in fixed point Q15 format.
  #define getOsc1FineTrimSlope() (*(int16 (*)(void))0x3D7E90)()
//Oscillator 1 fine trim at high temp
  #define getOsc1FineTrimOffset() (*(int16 (*)(void))0x3D7E93)()
//Oscillator 1 coarse trim
  #define getOsc1CoarseTrim() (*(int16 (*)(void))0x3D7E96)()

//Slope used to compensate oscillator 2 (fine trim steps / ADC code). Stored
//in fixed point Q15 format.
  #define getOsc2FineTrimSlope() (*(int16 (*)(void))0x3D7E99)()
//Oscillator 2 fine trim at high temp
  #define getOsc2FineTrimOffset() (*(int16 (*)(void))0x3D7E9C)()
//Oscillator 2 coarse trim
  #define getOsc2CoarseTrim() (*(int16 (*)(void))0x3D7E9F)()

//ADC reading of temperature sensor at reference temperature for compensation
  #define getRefTempOffset() (*(int16 (*)(void))0x3D7EA2)()

//Define function for later use
Uint16 GetOscTrimValue(int Coarse, int Fine);


// This function uses the temperature sensor sample reading to perform internal oscillator 1 compensation with
// reference values stored in OTP.
void Osc1Comp (int16 sensorSample)
{
    int16 compOscFineTrim;

    EALLOW;
    compOscFineTrim = ((sensorSample - getRefTempOffset())*(int32)getOsc1FineTrimSlope()
                      + OSC_POSTRIM_OFF + FP_ROUND )/FP_SCALE + getOsc1FineTrimOffset() - OSC_POSTRIM;
    if(compOscFineTrim > 31){
        compOscFineTrim = 31;
    }
    else if(compOscFineTrim < -31){
        compOscFineTrim = -31;
    } 
    SysCtrlRegs.INTOSC1TRIM.all = GetOscTrimValue(getOsc1CoarseTrim(), compOscFineTrim);
    EDIS;
}

// This function uses the temperature sensor sample reading to perform internal oscillator 2 compensation with
// reference values stored in OTP.
void Osc2Comp (int16 sensorSample)
{
    int16 compOscFineTrim;

    EALLOW;
    compOscFineTrim = ((sensorSample - getRefTempOffset())*(int32)getOsc2FineTrimSlope()
                      + OSC_POSTRIM_OFF + FP_ROUND )/FP_SCALE + getOsc2FineTrimOffset() - OSC_POSTRIM;
    
    if(compOscFineTrim > 31){
        compOscFineTrim = 31;
    }
    else if(compOscFineTrim < -31){
        compOscFineTrim = -31;
    }
    
    SysCtrlRegs.INTOSC2TRIM.all = GetOscTrimValue(getOsc2CoarseTrim(), compOscFineTrim);
    EDIS;
}

//This function packs the coarse and fine trim into
//the format of the oscillator trim register
Uint16 GetOscTrimValue(int Coarse, int Fine)
{
    Uint16 regValue = 0;

    if(Fine < 0)
    {
        regValue = ((-Fine) | 0x20) << 9;
    }
    else
    {
        regValue = Fine << 9;
    }
    if(Coarse < 0)
    {
        regValue |= ((-Coarse) | 0x80);
    }
    else
    {
        regValue |= Coarse;
    }
    return regValue;
}

