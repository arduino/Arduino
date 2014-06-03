/********************************************************************
*
* This file supports assembler and C development for
* MSP430G2553 devices.
*
* ADS1118.h
*
* functions is defined for ADS1118 configuration and data capture.
*
* Texas Instruments, Version 1.0
*
* Rev. 1.0, Setup
*
********************************************************************/


#ifndef __ADS1118
#define __ADS1118

extern volatile unsigned int  flag;		//global flag.


#define ADS1118_OS             (0x8000)         //
#define ADS1118_CH0            (0x0000)         //
#define ADS1118_CH1            (0x3000)         //
#define ADS1118_GAIN0          (0x0000)         //
#define ADS1118_GAIN1          (0x0200)         //
#define ADS1118_GAIN2          (0x0400)         //
#define ADS1118_GAIN4          (0x0600)         //
#define ADS1118_GAIN8          (0x0800)         //
#define ADS1118_GAIN16         (0x0A00)         //
#define ADS1118_PWRDOWN        (0x0100)         //

#define ADS1118_RATE8SPS       (0x0000)         //
#define ADS1118_RATE16SPS      (0x0020)         //
#define ADS1118_RATE32SPS      (0x0040)         //
#define ADS1118_RATE64SPS      (0x0060)         //
#define ADS1118_RATE128SPS     (0x0080)         //
#define ADS1118_RATE250SPS     (0x00A0)         //
#define ADS1118_RATE475SPS     (0x00C0)         //
#define ADS1118_RATE860SPS     (0x00E0)         //

#define ADS1118_TS			   (0x0010)         //
#define ADS1118_PULLUP     	   (0x0008)         //
#define ADS1118_NOP     	   (0x0002)         //
#define ADS1118_CNVRDY     	   (0x0001)         //
//Set the configuration to AIN0/AIN1, FS=+/-0.256, SS, DR=128sps, PULLUP on DOUT
#define ADSCON_CH0		(0x8B8A)
//Set the configuration to AIN2/AIN3, FS=+/-0.256, SS, DR=128sps, PULLUP on DOUT
#define ADSCON_CH1		(0xBB8A)

#define ADS_CS_LOW      digitalWrite(AA2, LOW)
#define ADS_CS_HIGH     digitalWrite(AA2, HIGH)

int WriteSPI(unsigned int config, int mode);
int ReadConfig(unsigned int config, int mode);
void ADS_Config(unsigned int mode);
int ADS_Read(unsigned int mode);
int ADC_code2temp(int code); 			// transform ADC code for far-end to temperature.
int	local_compensation(int local_code); // transform from local sensor code to thermocouple's compensation code.


#endif
