//*****************************************************************************
//
// hwspinlock.h - Prototypes for the Apps-NWP spinlock.
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

#ifndef __HWSPINLOCK_H__
#define __HWSPINLOCK_H__

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
// values that can be passed to API as ui32LockID parameter
//*****************************************************************************
#define HWSPINLOCK_SSPI        0x02000000
  
//*****************************************************************************
// Values that are returned from HwSpinLockTest()
//*****************************************************************************
#define HWSPINLOCK_OWNER_APPS  0x00000001
#define HWSPINLOCK_OWNER_NWP   0x00000002
#define HWSPINLOCK_OWNER_NONE  0x00000000
  
//*****************************************************************************
//
// API Function prototypes
//
//*****************************************************************************
extern void HwSpinLockAcquire(uint32_t ui32LockID);
extern int32_t HwSpinLockTryAcquire(uint32_t ui32LockID, uint32_t ui32Retry);
extern void HwSpinLockRelease(uint32_t ui32LockID);
extern uint32_t HwSpinLockTest(uint32_t ui32LockID, bool bCurrentStatus);

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __HWSPINLOCK_H__
