//*****************************************************************************
//
// flash.h - Prototypes for the flash driver.
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

#ifndef __FLASH_H__
#define __FLASH_H__

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
//
// Values that can be passed to FlashProtectSet(), and returned by
// FlashProtectGet().
//
//*****************************************************************************
typedef enum
{
    FlashReadWrite,                         // Flash can be read and written
    FlashReadOnly,                          // Flash can only be read
    FlashExecuteOnly                        // Flash can only be executed
}
tFlashProtection;

//*****************************************************************************
//
// Values passed to FlashIntEnable(), FlashIntDisable() and FlashIntClear() and
// returned from FlashIntStatus().
//
//*****************************************************************************
#define FLASH_INT_PROGRAM     0x00000002 // Programming Interrupt Mask
#define FLASH_INT_ACCESS      0x00000001 // Access Interrupt Mask
#define FLASH_INT_EEPROM      0x00000004 // EEPROM Interrupt Mask
#define FLASH_INT_VOLTAGE_ERR 0x00000200 // Voltage Error Interrupt Mask
#define FLASH_INT_DATA_ERR    0x00000400 // Invalid Data Interrupt Mask
#define FLASH_INT_ERASE_ERR   0x00000800 // Erase Error Interrupt Mask
#define FLASH_INT_PROGRAM_ERR 0x00002000 // Program Verify Error Interrupt Mask


//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
extern void FlashDisable(void);
extern long FlashErase(unsigned long ulAddress);
extern void FlashEraseNonBlocking(unsigned long ulAddress);
extern long FlashMassErase(void);
extern void FlashMassEraseNonBlocking(void);
extern long FlashProgram(unsigned long *pulData, unsigned long ulAddress,
                         unsigned long ulCount);
extern long FlashProgramNonBlocking(unsigned long *pulData,
                                    unsigned long ulAddress,
                                    unsigned long ulCount);
extern void FlashIntRegister(void (*pfnHandler)(void));
extern void FlashIntUnregister(void);
extern void FlashIntEnable(unsigned long ulIntFlags);
extern void FlashIntDisable(unsigned long ulIntFlags);
extern unsigned long FlashIntStatus(tBoolean bMasked);
extern void FlashIntClear(unsigned long ulIntFlags);
extern tFlashProtection FlashProtectGet(unsigned long ulAddress);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __FLASH_H__
