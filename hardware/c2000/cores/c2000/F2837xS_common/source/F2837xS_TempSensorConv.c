//###########################################################################
// FILE:   F2837xS_TempSensorConv.c
// TITLE:  F2837xS Temperature Sensor Conversion Functions
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // F2837xS Headerfile Include File
#include "F2837xS_Examples.h"   // F2837xS Examples Include File

// Useful definitions
#define FP_SCALE 32768       //Scale factor for Q15 fixed point numbers (2^15)
#define FP_ROUND FP_SCALE/2  //Added to Q15 numbers before converting to integer to round the number

// Amount to add to Q15 fixed point numbers to shift from Celsius to Kelvin
// (Converting guarantees number is positive, which makes rounding more efficient)
#define KELVIN 273
#define KELVIN_OFF FP_SCALE*KELVIN


// The following pointers to function calls are:
//Slope of temperature sensor (deg. C / ADC code).  Stored in fixed point Q15 format.
#define getTempSlope() (*(int (*)(void))0x7036E)()
//ADC code corresponding to temperature sensor output at 0 deg. C
#define getTempOffset() (*(int (*)(void))0x70372)()

int32 tempSensor_tempSlope;
Uint16 tempSensor_tempOffset;
float32 tempSensor_scaleFactor;

//Initialize the temperature sensor by powering up the sensor, loading
//the calibration values from OTP to RAM, and recording the intended
//VREFHI voltage.  
//note: This function doesn't support VREFLO != 0.0V, but this could 
//be implemented if desired. 
void InitTempSensor(float32 vrefhi_voltage)
{
	EALLOW;

	//power up the the temperature sensor
	AnalogSubsysRegs.TSNSCTL.bit.ENABLE = 1;
	//delay to allow the sensor to power up
	DELAY_US(1000);

    EDIS;

    //need to remember VREFHI voltage so that sensor readings can be scaled
    //to match 2.5V values used for calibration data.
    tempSensor_scaleFactor = vrefhi_voltage;
    
    //check the device revision
    if(DevCfgRegs.REVID >= 3)
    {
        //for production devices (Rev. C), pull the slope and offset from OTP
        tempSensor_tempSlope = (int32)getTempSlope();
        tempSensor_tempOffset = getTempOffset();
    }
    else
    {
        //for pre-production devices, use these static values for slope and offset
        tempSensor_tempSlope = 5196;
        tempSensor_tempOffset = 1788;
    }   
}

//This function uses the reference data stored in OTP to convert the raw temperature
//sensor reading into degrees C
int16 GetTemperatureC(int16 sensorSample)
{
    sensorSample = (int16)((tempSensor_scaleFactor/2.5)*(sensorSample));

    return ((sensorSample - tempSensor_tempOffset)*tempSensor_tempSlope + FP_ROUND + KELVIN_OFF)/FP_SCALE - KELVIN;
}

//This function uses the reference data stored in OTP to convert the raw temperature
//sensor reading into degrees K
int16 GetTemperatureK(int16 sensorSample)
{
    sensorSample = (int16)((2.5/tempSensor_scaleFactor)*(sensorSample));

    return ((sensorSample - tempSensor_tempOffset)*tempSensor_tempSlope + FP_ROUND + KELVIN_OFF)/FP_SCALE;
}
