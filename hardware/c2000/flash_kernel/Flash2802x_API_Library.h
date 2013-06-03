// TI File $Revision: /main/2 $
// Checkin $Date: February 5, 2008   11:10:00 $
//###########################################################################
//
// FILE:  Flash2802x_API_Library.h	
//
// TITLE: F2802x Flash Algo's main include file
//
// DESCRIPTION:
//
//       This file should be included in any project that uses any of the
//       the F2802x flash APIs.
//
//###########################################################################
// $TI Release:$
// $Release Date:$
//###########################################################################

#ifndef FLASH2802X_API_LIBRARY_H
#define FLASH2802X_API_LIBRARY_H

#include "Flash2802x_API_Config.h"

#ifdef __cplusplus
extern "C" {
#endif



/*---------------------------------------------------------------------------
 28x Datatypes

 For Portability, User Is Recommended To Use Following Data Type Size
 Definitions For 16/32/64-Bit Signed/Unsigned Integers and floating point
 variables:
---------------------------------------------------------------------------*/

#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int                 int16;
typedef long                int32;
//typedef long long           int64;   
typedef unsigned int        Uint16;
typedef unsigned long       Uint32;
//typedef unsigned long long  Uint64;
typedef float               float32;
typedef long double         float64;
#endif

/*---------------------------------------------------------------------------
 API Status Messages

 The following status values are returned from the API to the calling
 program.  These can be used to determine if the API function passed
 or failed.  
---------------------------------------------------------------------------*/
 // Operation passed, no errors were flagged
#define STATUS_SUCCESS                        0   

// The CSM is preventing the function from performing its operation
#define STATUS_FAIL_CSM_LOCKED               10

// Device REVID does not match that required by the API
#define STATUS_FAIL_REVID_INVALID            11
    
// Invalid address passed to the API
#define STATUS_FAIL_ADDR_INVALID             12

// Incorrect PARTID
// For example the F2806 API was used on a F2808 device. 
#define STATUS_FAIL_INCORRECT_PARTID         13

// API/Silicon missmatch.  An old version of the
// API is being used on silicon it is not valid for
// Please update to the latest API. 
#define STATUS_FAIL_API_SILICON_MISMATCH     14

// ---- Erase Specific errors ---- 
#define STATUS_FAIL_NO_SECTOR_SPECIFIED      20
#define STATUS_FAIL_PRECONDITION             21
#define STATUS_FAIL_ERASE                    22
#define STATUS_FAIL_COMPACT                  23
#define STATUS_FAIL_PRECOMPACT               24

// ---- Program Specific errors ----  
#define STATUS_FAIL_PROGRAM                  30
#define STATUS_FAIL_ZERO_BIT_ERROR           31

// ---- Verify Specific errors ----
#define STATUS_FAIL_VERIFY                   40

// Busy is set by each API function before it determines
// a pass or fail condition for that operation.  
// The calling function will will not receive this 
// status condition back from the API
#define STATUS_BUSY                999    

/*---------------------------------------------------------------------------
 Flash sector mask definitions

 The following macros can be used to form a mask specifying which sectors
 will be erased by the erase API function.
 
 Bit0 = Sector A
 Bit1 = Sector B
 Bit2 = Sector C
 Bit3 = Sector D
---------------------------------------------------------------------------*/

#define SECTORA   (Uint16)0x0001
#define SECTORB   (Uint16)0x0002
#define SECTORC   (Uint16)0x0004
#define SECTORD   (Uint16)0x0008


// All sectors on an F2802x - Sectors A - D
#define SECTOR_F2802x (SECTORA|SECTORB|SECTORC|SECTORD)


/*---------------------------------------------------------------------------
 API Status Structure
 
 This structure is used to pass debug data back to the calling routine.
 Note that the Erase API function has 3 parts: precondition, erase and
 and compaction. Erase and compaction failures will not populate 
 the expected and actual data fields.  
---------------------------------------------------------------------------*/

typedef struct {
    Uint32  FirstFailAddr;
    Uint16  ExpectedData;
    Uint16  ActualData;
}FLASH_ST;

/*---------------------------------------------------------------------------
   Interface Function prototypes
   
   For each 28x Flash API library, the function names are of the form:
   Flash<DeviceNum>_<Operation>()
   
   Where <DeviceNum> is the device: ie 2808, 2806, 2801
         <Operation> is the operation such as Erase, Program...
         
   For portability for users who may move between the F2808, F2806 and
   F2801, the following macro definitions are supplied. 
   
   Using these macro definitions,  the user can use instead make a generic
   call:  Flash_<Operation> and the macro will map the call to the proper
   device function
   
   Note except for the toggle test function, all of the function prototypes
   are compatible with F281x devices as well. 
---------------------------------------------------------------------------*/

#define Flash_Erase(a,b)          Flash2802x_Erase(a,b)
#define Flash_Program(a,b,c,d)    Flash2802x_Program(a,b,c,d)
#define Flash_Verify(a,b,c,d)     Flash2802x_Verify(a,b,c,d)
#define Flash_ToggleTest(a,b)     Flash2802x_ToggleTest(a,b)
#define Flash_DepRecover()        Flash2802x_DepRecover()
#define Flash_APIVersionHex()     Flash2802x_APIVersionHex()
#define Flash_APIVersion()        Flash2802x_APIVersion()

extern Uint16  Flash_Erase(Uint16 SectorMask, FLASH_ST *FEraseStat);
extern Uint16  Flash_Program(Uint16 *FlashAddr, Uint16 *BufAddr, Uint32 Length, FLASH_ST *FProgStatus);
extern Uint16  Flash_Verify(Uint16 *StartAddr, Uint16 *BufAddr, Uint32 Length, FLASH_ST *FVerifyStat);
extern void    Flash_ToggleTest(volatile Uint32 *ToggleReg, Uint32 Mask);
extern Uint16  Flash_DepRecover();
extern float32 Flash_APIVersion();
extern Uint16  Flash_APIVersionHex(); 

/*---------------------------------------------------------------------------
   Frequency Scale factor:
   The calling program must provide this global parameter used
   for frequency scaling the algo's.
----------------------------------------------------------------------------*/

extern Uint32 Flash_CPUScaleFactor;

/*---------------------------------------------------------------------------
   Callback Function Pointer:
   A callback function can be specified.  This function will be called
   at safe times during erase, program and verify.  This function can
   then be used to service an external watchdog or send a communications
   packet.
   
   Note: 
   THE FLASH AND OTP ARE NOT AVAILABLE DURING THIS FUNCTION CALL.
   THE FLASH/OTP CANNOT BE READ NOR CAN CODE EXECUTE FROM IT DURING THIS CALL
   DO NOT CALL ANY OF THE THE FLASH API FUNCTIONS DURING THIS CALL
----------------------------------------------------------------------------*/
extern void (*Flash_CallbackPtr) (void);

/*---------------------------------------------------------------------------
   API load/run symbols:
   These symbols are defined by the linker during the link.  Refer to the
   Flash28_API section in the example .cmd file:

   Flash28_API:
   {
        Flash28027_API_Library.lib(.econst) 
        Flash28027_API_Library.lib(.text)
   } LOAD = FLASH, 
     RUN = SARAM, 
     LOAD_START(_Flash28_API_LoadStart),
     LOAD_END(_Flash28_API_LoadEnd),
     RUN_START(_Flash28_API_RunStart),
     PAGE = 0
   
   These are used to copy the flash API from flash to SARAM
   
----------------------------------------------------------------------------*/

extern Uint16 Flash28_API_LoadStart;
extern Uint16 Flash28_API_LoadEnd;
extern Uint16 Flash28_API_RunStart;

#ifdef __cplusplus
}
#endif /* extern "C" */


#endif // -- end FLASH2802x_API_LIBRARY_H 

// --------- END OF FILE ----------------------------------

