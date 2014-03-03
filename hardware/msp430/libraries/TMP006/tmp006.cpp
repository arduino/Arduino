/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/


/*

tmp006.c -Energia Library for TMP006 Module.

Modified by Dung Dang, Dec 2013
Rewritten to follow Energia library standard, tmp006 as class object.
Removed Print_Temp() API, this method can be shown as an example sketch.


*/

/*******************************************************************************
 *
 * tmp006.c -Energia Library for TMP006 Module.
 *
 *  Yining Yang
 *  Texas Instruments Inc.
 *  November 2012
 *  Built with CCE Version: 5.2.1 and IAR Embedded Workbench Version: 6.4
 ******************************************************************************/



#include "tmp006.h"
#define USE_USCI_B1 


 /*!
 * INITIALIZATION FUNCTION
 * Initializes the TMP006 and sets up I2C for operation.
 *
 * The temperature sensor is initialized with DRDY enabled.
 * Address pins are selected as ADR1 = 0 & ADR0 = 0.
 * The LaunchPad is in master synchronous mode
 *
 * @param totalSamples: Total number of averaged samples
 *                       \b ONE_SAMPLE \n
 *                       \b TWO_SAMPLES  \n
 *                       \b FOUR_SAMPLES \n
 *                       \b EIGHT_SAMPLES \n
 *                       \b SIXTEEN_SAMPLES  \n
 *
 * @return None
 */
  
	
 void tmp006::begin(uint16_t totalSamples)
{	
   // Initialize Wire
    Wire.begin();
    // Reset TMP006 
    writeRegister(TMP006_CONFIG_REG, TMP006_RESET);
    // Configure TMP006 for initialization 
    writeRegister(TMP006_CONFIG_REG, TMP006_POWER_UP + totalSamples + CONVERSION_BIT_ENABLE);
    	
}


/*!
 * SLEEP FUNCTION
 * Wakes up TMP006 from power down mode without reconfiguration.
 *
 * @param None
 *
 * @return None
 *
 */

	
void tmp006::wakeUp(void)
{
    uint16_t settings;

    // Read and save current settings 
    settings = readRegister(TMP006_CONFIG_REG);
    // Power-up TMP006 with current settings*/
    settings |= TMP006_POWER_UP;
    // Writes to Config register*/
    writeRegister(TMP006_CONFIG_REG, settings);
}
	

 /*!
 * WAKEUP FUNCTION
 * Disables TMP006 by putting it into power down mode.
 *
 * @param None
 *
 * @return None
 *
 */

	
void tmp006::sleep(void)
{
    uint16_t settings;

    /* Read current settings */
    settings = readRegister(TMP006_CONFIG_REG);
    /* Mask out and power down TMP006 */
    settings &= ~(TMP006_POWER_UP);
    /* Power down TMP006 */
    writeRegister(TMP006_CONFIG_REG, settings);
}


 /*******************************************************************************
 *
 * LOWER LEVEL LIBRARY CALLS
 * Allows for more customization, most new users will have no need to  directly 
 * use or configure any of the following code
 * These functions are called on by user level library calls
 *
 ******************************************************************************/   
 
    
/*!
 * READY FUNCTION
 * Function to poll and check if object voltage and ambient temperature results are ready to read.
 *
 * @param None
 *
 * @return \b 0 \b - Data not ready \n
 *         \b 1 \b - Data is ready
 *
 */
	
uint8_t tmp006::ready(void)
{
    /* Read DRDY status from Config register */
     if (CONVERSION_DONE & readRegister(TMP006_CONFIG_REG))
        return 1;
     else
        return 0;
}


/*!
 * READ FROM TMP006 FUNCTION
 * Reads data out of the TMP006 in I2C Master Mode.
 * Uses functions in the Wire library
 *
 * @param registerName is the name of the register you are reading from
 *
 *
 * @return uint16_t value of Register
 *
 */




uint16_t tmp006::readRegister(uint8_t registerName)
{
    uint16_t value;

    /* Begin Tranmission at address of device on bus */
	Wire.beginTransmission(ADR1_0_ADR0_0);
	/* Send Pointer Register Byte */
    Wire.write(registerName);
    /* Sends Stop */
	Wire.endTransmission();
     /* Requests 2 bytes fron Slave */
	Wire.requestFrom(ADR1_0_ADR0_0, 2);
     /* Wait Until 2 Bytes are Ready*/
	while(Wire.available() < 2)	{}

    /* Read*/
    value = Wire.read();
	value = value << 8;
	value|= Wire.read();

    return value;
}


/*!
 * WRITE TO TMP006 FUNCTION
 * Writes data to TMP006 via I2C
 * Uses functions in the Wire library
 *
 * @param registerName is the base address of the I2C Master module.
 * @param data is the bytes you want to be written.
 *
 * This function transmit data to TMP006 via the pointer and data to be
 * transmitted.
 *
 * @return None.
 *
 */


void tmp006::writeRegister(uint8_t registerName, uint16_t data)
{
    /* Begin Tranmission at address of device on bus */
	Wire.beginTransmission(ADR1_0_ADR0_0);
	/* Send Pointer Register Byte */
	Wire.write(registerName);
    /* Read*/
	Wire.write((unsigned char)(data>>8));
	Wire.write((unsigned char)(data&0x00FF));
    /* Sends Stop */
	Wire.endTransmission();

}


/*!
 * TEMPERATURE DATA FUNCTION
 * Function to calculate and return the temperature and raw values from TMP006
 * sensor.
 *
 * @param tempStrucPtr is the pointer to the TMP006_TempStruct to hold result
 *
 * @return None
 *
 */
 

	
void tmp006::getTempStruct(TMP006_TempStruct* tempStrucPtr)
 {

    /* When the data is ready. */
 	while(!ready());
	/*Read the object voltage */
	tempStrucPtr->vObj = readRegister(Volt_REG);
	/* Read the ambient temperature */
	tempStrucPtr->tDie = readRegister(Temp_REG);
	// !TODO: Still debugging
	//tempStrucPtr->tempFixedPoint = TMP006_Calculate(tempStrucPtr->vObj,tempStrucPtr->tDie );


	// For now, let's use the float function

	/*Calculate the temperature in Kelvin */
	tempStrucPtr->tDie_K = ((float)(tempStrucPtr->tDie>>2) *.03125) + 273.15;
	/*Calculate the Voltage in volts*/
	tempStrucPtr->vObj_V = (float)(tempStrucPtr->vObj) * .00000015625;
	/*Calculate the Temperature with corrections in Celsius*/
	tempStrucPtr->temp = Calculate_Temp(&(tempStrucPtr->tDie_K), &(tempStrucPtr->vObj_V));

    
}

/*!
 * TEMPERATURE  FUNCTION
 * Function to calculate and return the temperature and raw values from TMP006
 * sensor.
 *
 * @param tempStrucPtr is the pointer to the TMP006_TempStruct to hold result
 *
 * @return temperature in Celsius (type float)
 *
 */

float tmp006::getTemp()
{
	TMP006_TempStruct tempStruct;
	getTempStruct(&tempStruct);
	return tempStruct.temp;
}


/*!
 * TEMPERATURE CALCULATION FUNCTION
 * Function to calculate temperature based on tdie and vobj
 *
 * @param tDie temperature of the die in Kelvin
 * @param vObj object in Volts
 *
 * @return temperature value in Celsius
 *
 */
float Calculate_Temp(float *tDie_K, float *vObj_V)

{
    /* Calculate TMP006. This needs to be reviewed and calibrated by TMP group */
	float S0 = 6e-14;       /* Default S0 cal value */
	float a1 = 1.75e-3;
	float a2 = -1.678e-5;
	float b0 = -2.94e-5;
	float b1 = -5.7e-7;
	float b2 = 4.63e-9;
	float c2 = 13.4;
	float Tref = 298.15;

    //float correctedtemp = *tDie_K - Tref;
    float S = S0*(1+a1*(*tDie_K - Tref)+a2*(*tDie_K - Tref)*(*tDie_K - Tref));
    float Vos = b0 + b1*(*tDie_K - Tref) + b2*(*tDie_K - Tref)*(*tDie_K - Tref);

    //float correctedvolt = *vObj_V - Vos;
    float fObj = *vObj_V - Vos + c2*(*vObj_V - Vos)*(*vObj_V - Vos);
	float Tobj = sqrt(sqrt(((*tDie_K)*(*tDie_K)*(*tDie_K)*(*tDie_K)) + (fObj/S)));



    return (Tobj - 273.15);
}




// Fixed point implementation of the TMP006 calculation, to replace the Calculate_Temp function above
// Currently still showing error when compile
// In function `get_eit_entry':
// C:\MinGW\msys\1.0\home\a0273864\yagarto\gcc-build\arm-none-eabi\thumb\armv7e-m\fpu\fpv4-sp-d16\libgcc/../../../../../../../gcc-4.7.1/libgcc/unwind-arm-common.inc:221: undefined reference to `__exidx_start'
// C:\MinGW\msys\1.0\home\a0273864\yagarto\gcc-build\arm-none-eabi\thumb\armv7e-m\fpu\fpv4-sp-d16\libgcc/../../../../../../../gcc-4.7.1/libgcc/unwind-arm-common.inc:221: undefined reference to `__exidx_end'
// Seems to be a linker error, as library can be compiled alone
// Error when compiling/linking with example code. Maybe too much uint_64_t and/or division is still used in the function?
// Also check license agreement

//
/////////////////////////////////////////////////////////////////////////////////
//
//int64_t TMP006_Sqrt4(int64_t n)
//{
//	// Calculate 4th order square root using a binary search in 14 iterations
//	int64_t answer = 0;
//	int64_t answer2;
//	int64_t answer4;
//	int i;
//	for (i = 14; i >= 0; i--)
//	{
//		answer = answer | (int64_t)(1 << i);
//		answer2 = answer * answer;
//		answer4 = answer2 * answer2;
//		if      (answer4 >  n) { answer = answer & (~(1 << i)); }
//		else if (answer4 == n) { break; }
//	}
//	return answer;
//}
//
//
//// Sensor Coefficients Table       | Resolution        | Floating Point Range | Floating Point Value | Fixed Point Value
//// ---------------------------------------------------------------------------------------------------------------------
//const int64_t TMP006_a1 = 459;         // | 2^-18             | +/- 0.125            |  1.75e-3             |  459
//const int64_t TMP006_a2 = -282;        // | 2^-24             | +/- 0.0019           | -1.68e-5             | -282
//const int64_t TMP006_b0 = -192;        // | 156.25e-9         | +/- 5.12e-3          | -30.0e-6             | -192
//const int64_t TMP006_b1 = -983;        // | 156.25e-9 x 2^-8  | +/- 20.0e-6          | -0.6e-6              | -983
//const int64_t TMP006_b2 = 26;          // | 156.25e-9 x 2^-14 | +/- 312e-9           |  0.25e-9             |  26
//const int64_t TMP006_c2 = 281;         // | 2^-27 / 156.25e-9 | +/- 97               |  13.4                |  281
//const int64_t TMP006_s0 = 14953;       // | 156.25e-9 x 2^-35 | 0 -> 2.98e-13        |  6.8e-14             |  14953
//
//// Other constants
//const int64_t TMP006_e1 = 51;
//const int64_t TMP006_e2 = 154;
//const int64_t TMP006_f1 = 26;
//const int64_t TMP006_f2 = 204;
//const int64_t TMP006_t1 = 60621;		// (296e-6 / 0.15625e-6)*2^5
//
//
//int32_t TMP006_Calculate(int16_t vout, int16_t tdie)
//{
//
//
//	// Variables
//	int64_t fvout;                  // Offset corrected output
//	int64_t s;
//	int64_t tdie64;
//	int64_t vout64;
//	int64_t dt;                     // difference to reference temperature
//	int64_t dt2;                    // difference to reference temperature squared
//	int64_t x;
//	int64_t tobj;                   // Output
//	int64_t tdie_slope = 0;         // Assume initial slope to be zero
//
//	static int64_t tdie_filtered = 0;
//	static int64_t tdie_previous = 0;
//	static int64_t tobj_filtered = 0;
//	static int64_t tobj_previous = 0;
//	static int32_t first_run = 1;
//
//	// Check for valid inputs
//	if (tdie & 0x0003) return 1;             // Make sure the lower two bits are zero
//	if ((vout > 65535) || (vout < -32768)) return 1;
//	if ((tdie > 65535) || (tdie < -32768)) return 1;
//
//	vout64 = (int64_t)vout;                  // Convert input to 64 bit format
//	if (vout64 > 32767) vout64 -= 65536;     // Take care of negative numbers
//	tdie64 = (int64_t)tdie >> 2;             // Get the 14 msb bits & convert input to 64 bit format
//	if (tdie64 > 8191)  tdie64 -= 16384;     // Take care of negative numbers
//	dt = tdie64 - 800;                       // Calculate Tdie - Tref (800 = 25 / 0.03125)
//	dt2 = dt * dt;                           // Calculate (Tdie - Tref) ^ 2
//	tdie64 = tdie64 + 8741;                  // Convert to Kelvin (8741 = 273.15 / 0.03125)
//	vout64 = (vout64 << 11);
//	x = (tdie64 * tdie64);
//	x = (x * x) >> 24;                       // Calculate tdie64^4
//
//#ifdef TMP006_TRANS_CORRECT                  // Transient correction algorithm
//	tdie64 = tdie64 << 8;
//	if (first_run)
//	{
//		tdie_previous = tdie64;
//		tdie_filtered = tdie64;
//#ifndef TMP006_FILTER_OUTPUT
//		first_run = 0;
//#endif
//	}
//	tdie_filtered = ((TMP006_e1 * (tdie64 + tdie_previous)) + (TMP006_e2 * tdie_filtered)) >> 8;
//	tdie_slope = tdie64 - tdie_filtered;
//	tdie_previous = tdie64;
//	vout64 = vout64 + ((tdie_slope * t1) >> 8);
//#endif
//
//	fvout = vout64 - (((TMP006_b0 << 12) + (((TMP006_b1 * dt) + ((TMP006_b2 * dt2) >> 11)) >> 1)) >> 1);
//	fvout = ((TMP006_c2 * (fvout * fvout) >> 31) >> 12) + (fvout >> 5);
//	s = (TMP006_s0 * ((1 << 15) + (((TMP006_a1 * dt) + ((TMP006_a2 * dt2) >> 11)) >> 8 ))) >> 9;
//	x = (x + ((fvout << 31) / s)) << 24;
//	if ((x > 72057594037927900) || (x < 0)) return 1;  // Check limits
//	//tobj = TMP006_Sqrt4(x) - 8741;
//	tobj = x;
//
//#ifdef TMP006_FILTER_OUTPUT                  // Output filtering
//	tobj = tobj << 8;
//	if (first_run)
//	{
//		tobj_previous = tobj;
//		tobj_filtered = tobj;
//		first_run = 0;                       // Not the first run anymore
//	}
//	tobj_filtered = ((f1 * (tobj + tobj_previous)) + (f2 * tobj_filtered)) >> 8;
//	tobj_previous = (tobj);
//	return (int)((tobj_filtered >> 6) & 0xFFFC);  // Return the filtered value and make sure the lower two bits are zero
//#else
//	return (int32_t)((tobj << 2) & 0xFFFC);
//#endif
//
//}
