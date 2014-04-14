//*****************************************************************************
//
// pinmap.h - Defines and Macros for the pin mux module
//
// Copyright (C) 2013 Texas Instruments Incorporated
//
// All rights reserved. Property of Texas Instruments Incorporated.
// Restricted rights to use, duplicate or disclose this code are
// granted through contract.
// The program may not be used without the written permission of
// Texas Instruments Incorporated or against the terms and conditions
// stipulated in the agreement under which this program has been supplied,
// and under no circumstances can it be used with non-TI connectivity device.
//
//*****************************************************************************

#ifndef __PINMAP_H__
#define __PINMAP_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif
 
//*****************************************************************************
// Macros Defining Pins
//*****************************************************************************

#define PIN_1 	 0x00
#define PIN_2 	 0x01
#define PIN_3  	 0x02
#define PIN_4 	 0x03
#define PIN_5  	 0x04
#define PIN_6  	 0x05
#define PIN_7  	 0x06
#define PIN_8  	 0x07

#define PIN_11   0x0A
#define PIN_12   0x0B
#define PIN_13   0x0C
#define PIN_14   0x0D
#define PIN_15   0x0E
#define PIN_16   0x0F
#define PIN_17   0x10
#define PIN_18   0x11
#define PIN_19 	 0x12
#define PIN_20   0x13
#define PIN_21   0x14

#define PIN_29   0x1C
#define PIN_30   0x1D

#define PIN_45   0x2C
#define PIN_46   0x2D
#define PIN_47   0x2E
#define PIN_48   0x2F
#define PIN_49   0x30
#define PIN_50   0x31

#define PIN_52   0x33
#define PIN_53   0x34

#define PIN_55   0x36
#define PIN_56   0x37
#define PIN_57   0x38
#define PIN_58   0x39
#define PIN_59   0x3A
#define PIN_60   0x3B
#define PIN_61	 0x3C
#define PIN_62	 0x3D
#define PIN_63	 0x3E
#define PIN_64	 0x3F



//*****************************************************************************
// Macros that can be used with PinConfigSet(), PinTypeGet(), PinStrengthGet()
//*****************************************************************************
 
#define PIN_MODE_0	 0x00
#define PIN_MODE_1	 0X01
#define PIN_MODE_2	 0x02
#define PIN_MODE_3	 0x03
#define PIN_MODE_4	 0x04
#define PIN_MODE_5	 0x05
#define PIN_MODE_6	 0x06
#define PIN_MODE_7	 0x07
#define PIN_MODE_8	 0x08
#define PIN_MODE_9	 0x09
#define PIN_MODE_10	 0x0A
#define PIN_MODE_11	 0x0B
#define PIN_MODE_12	 0x0C
#define PIN_MODE_13	 0x0D
#define PIN_MODE_14	 0x0E

//*****************************************************************************
// Macros that can be used with PinConfigSet(), PinTypeGet(), PinStrengthGet()
// PinConfigGet(), PinTypeGet(), PinStrengthGet().
//*****************************************************************************  
#define PIN_STRENGTH_2MA    0x00000020
#define PIN_STRENGTH_4MA    0x00000040
#define PIN_STRENGTH_8MA    0x00000080

#define PIN_TYPE_STD      0x00000000
#define PIN_TYPE_STD_PU   0x00000100
#define PIN_TYPE_STD_PD   0x00000200

#define PIN_TYPE_OD       0x00000010
#define PIN_TYPE_OD_PU    0x00000110
#define PIN_TYPE_OD_PD    0x00000210
  
  
//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************

extern void PinModeSet(unsigned long ulPin,unsigned long ulPinMode);
extern unsigned long PinModeGet(unsigned long ulPin); 
extern void PinConfigGet(unsigned long ulPin,unsigned long  *pulPinStrength,
	       					unsigned long *pulPinType);
extern void PinConfigSet(unsigned long ulPin,unsigned long  ulPinStrength, 
						unsigned long ulPinType);
extern void PinTypeSet(unsigned long ulPin, unsigned long ulPinType);
extern unsigned long PinTypeGet(unsigned long ulPin);
extern void PinStrengthSet(unsigned long ulPin, unsigned ulPinStrength);
extern unsigned long PinStrengthGet(unsigned long ulPin);
extern void PinTypeUART(unsigned long ulPin,unsigned long ulPinMode);
extern void PinTypeI2C(unsigned long ulPin,unsigned long ulPinMode);
extern void PinTypeMcSPI(unsigned long ulPin,unsigned long ulPinMode);
extern void PinTypeMcASP(unsigned long ulPin,unsigned long ulPinMode);
extern void PinTypeTimer(unsigned long ulPin,unsigned long ulPinMode);
extern void PinTypeCAM(unsigned long ulPin,unsigned long ulPinMode);
extern void PinTypeEPI(unsigned long ulPin,unsigned long ulPinMode);
extern void PinTypeGPIO(unsigned long ulPin,unsigned long ulPinMode,tBoolean bOpenDrain);


#ifdef __cplusplus
}
#endif

#endif /*__PINMAP_H__*/
