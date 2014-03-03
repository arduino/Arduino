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
#ifndef __TMP006_H__
#define __TMP006_H__
#include <Energia.h>
#include <Wire.h>



/*******************************************************************************
 *
 * If building with a C++ compiler, make all of the definitions in this header
 * have a C binding.
 *
 ******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif


#define Enable   1
#define Disable  0


/*! \name TMP006 Internal Pointer Register Address
 * @{
 */
/*! TMP006 object voltage register pointer */
#define Volt_REG            0x00
/*! TMP006 ambient temperature register pointer */
#define Temp_REG            0x01
/*! TMP006 configuration register pointer */
#define TMP006_CONFIG_REG          0x02
/*! TMP006 manufacturer ID register pointer */
#define Man_ID              0xFE
/*! TMP006 device ID register pointer */
#define Dev_ID              0xFF
/*! @} */



/*! \name TMP006 Configuration Register Bits
 * @{
 */
#define TMP006_RESET       	0x8000
#define TMP006_POWER_DOWN   0x0000
#define TMP006_POWER_UP     0x7000
#define ONE_SAMPLE          0x0000
#define TWO_SAMPLES         0x0200
#define FOUR_SAMPLES        0x0400
#define EIGHT_SAMPLES       0x0600
#define SIXTEEN_SAMPLES     0x0800
#define CONVERSION_BIT_ENABLE    0x0100
#define CONVERSION_DONE     0x0080


/*! \Address Pin and Bit Configuration
 * @{
 */
#define ADR1_0_ADR0_0  		0x40
#define ADR1_0_ADR0_1		0x41
#define ADR1_0_ADR0_SDA		0x42
#define ADR1_0_ADR0_SCL		0x43
#define ADR1_1_ADR0_0		0x44
#define	ADR1_1_ADR0_1		0x45
#define	ADR1_1_ADR0_SDA		0x46
#define ADR1_1_ADR0_SCL		0x47


/*! @} */
/*******************************************************************************
 *
 * \brief  Temperature reading structure
 *
 ******************************************************************************/
typedef struct
{
    /*! Calculated temperature reading */
	float temp;

    /*! Stores the raw value fromm Volt register */
    signed int vObj;

    /*! Stores the raw value from Temp Register */
    signed int tDie;

	  /*! Stores temp value in Kelvin and ambient volt in V*/
    float tDie_K;
    float vObj_V;
} TMP006_TempStruct;


/*! @} */
/*******************************************************************************
 *
 *    Function Prototyping
 *
 *******************************************************************************/
 
class tmp006
{
  public:
	void begin(uint16_t totalSamples);
	void wakeUp();
	void sleep();
	uint16_t readRegister(uint8_t registerName);
	void writeRegister(uint8_t registerName, uint16_t data);
	
	uint8_t ready();
	void getTempStruct(TMP006_TempStruct* tempStrucPtr);
	float getTemp();
  private:
  
};
 
 // /*! USER LEVEL LIBRARY CALLS */
// void TMP006_Init(unsigned int Total_samples);
// void TMP006_Wakeup(void); 
// void TMP006_Sleep(void);
// void Print_Temp(char Print_structure);


/*! LOWER LEVEL LIBRARY CALLS */
float Calculate_Temp(float *tDie_K, float *vObj_V);
int64_t TMP006_Sqrt4(int64_t);
int TMP006_Calculate(int vout, int tdie);
// 
// unsigned int Read_fromTMP(unsigned char Register);
// void Write_toTMP(unsigned char Register, unsigned int writeByte);
// unsigned char Ready(void);
// TempReading Get_Temp_data(void);


/*******************************************************************************
 *
 * Mark the end of the C bindings section for C++ compilers.
 *
 ******************************************************************************/
#ifdef __cplusplus
}
#endif

#endif // __TMP006_H__