/******************************************************************************
*  Filename:       rom.h
*  Revised:        2015-04-09 11:58:21 +0200 (to, 09 apr 2015)
*  Revision:       43183
*
*  Description:    Prototypes for the ROM utility functions.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#ifndef __ROM_H__
#define __ROM_H__

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

#include <inc/hw_types.h>

#ifndef __HAPI_H__
#define __HAPI_H__

//
// Start address of the ROM hard API access table (located after the ROM FW rev field)
//
#define ROM_HAPI_TABLE_ADDR 0x10000048

//
// ROM Hard-API function interface types
//
typedef uint32_t       (* FPTR_CRC32_T)                         \
                                            (uint8_t* /*pui8Data*/,      \
                                             uint32_t  /*ui32ByteCount*/,  \
                                             uint32_t  /*ui32RepeatCount*/);

typedef uint32_t       (* FPTR_GETFLSIZE_T)                     \
                                            (void);

typedef uint32_t       (* FPTR_GETCHIPID_T)                     \
                                            (void);

#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
typedef uint32_t            (* volatile FPTR_DUMMY_T)                         \
                                            (uint32_t  /*ui32Dummy*/);

typedef uint32_t            (* volatile FPTR_PROGRAW_T)                       \
                                            (uint8_t* /*pui8RamData*/,        \
                                             uint32_t  /*ui32OtpAdr*/,        \
                                             uint32_t  /*ui32Count*/);

typedef uint32_t            (* volatile FPTR_PROGECC_T)                       \
                                            (uint8_t* /*pui8RamData*/,        \
                                             uint32_t  /*ui32OtpAdr*/,        \
                                             uint32_t  /*ui32Count*/);
#else
typedef uint32_t       (* FPTR_RESERVED1_T)                     \
                                            (uint32_t);

typedef uint32_t       (* FPTR_RESERVED2_T)                    \
                                            (void);

typedef uint32_t       (* FPTR_RESERVED3_T)                    \
                                            (uint8_t*,                  \
                                             uint32_t,                  \
                                             uint32_t);
#endif
typedef void                (* FPTR_RESETDEV_T)                      \
                                            (void);

typedef uint32_t       (* FPTR_FLETCHER32_T)                    \
                                            (uint16_t* /*pui16Data*/,      \
                                             uint16_t  /*ui16WordCount*/,  \
                                             uint16_t  /*ui16RepeatCount*/);

typedef uint32_t       (* FPTR_MINVAL_T)                        \
                                            (uint32_t*  /*ulpDataBuffer*/,\
                                             uint32_t   /*ui32DataCount*/);

typedef uint32_t       (* FPTR_MAXVAL_T)                        \
                                            (uint32_t*  /*pui32DataBuffer*/,\
                                             uint32_t   /*ui32DataCount*/);

typedef uint32_t       (* FPTR_MEANVAL_T)                       \
                                            (uint32_t*   /*pui32DataBuffer*/,\
                                             uint32_t    /*ui32DataCount*/);

typedef uint32_t       (* FPTR_STDDVAL_T)                       \
                                            (uint32_t*   /*pui32DataBuffer*/,\
                                             uint32_t    /*ui32DataCount*/);

typedef void                (* FPTR_HFSOURCESAFESWITCH_T)            \
                                            (void);

typedef void                (* FPTR_RESETPERIPHERAL_T)               \
                                            (uint32_t    /*ui32Peripheral*/);

typedef void                (* FPTR_RESETDOMAIN_T)                   \
                                            (uint32_t    /*ui32Domain*/);

typedef void                (* FPTR_COMPAIN_T)                       \
                                              (uint8_t /*ut8Signal*/);

typedef void                (* FPTR_COMPAREF_T)                      \
                                              (uint8_t /*ut8Signal*/);

typedef void                (* FPTR_ADCCOMPBIN_T)                    \
                                              (uint8_t /*ut8Signal*/);

typedef void                (* FPTR_COMPBREF_T)                      \
                                              (uint8_t /*ut8Signal*/);

#if (CC_GET_CHIP_OPTION != CC_CHIP_OPTION_OTP)
extern uint32_t MemBusWrkAroundHapiProgramFlash(uint8_t *pui8DataBuffer,
                                                uint32_t ui32Address,
                                                uint32_t ui32Count);

extern uint32_t MemBusWrkAroundHapiEraseSector(uint32_t ui32Address);
#endif

//
// ROM Hard-API access table type
//
typedef struct
{
    FPTR_CRC32_T                    Crc32;
#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
    FPTR_GETFLSIZE_T                OtpGetSize;
#else
    FPTR_GETFLSIZE_T                FlashGetSize;
#endif
    FPTR_GETCHIPID_T                GetChipId;
#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
    FPTR_DUMMY_T                    Dummy;
    FPTR_PROGRAW_T                  ProgramOtpRaw;
    FPTR_PROGECC_T                  ProgramOtpEcc;
#else
    FPTR_RESERVED1_T                ReservedLocation1;
    FPTR_RESERVED2_T                ReservedLocation2;
    FPTR_RESERVED3_T                ReservedLocation3;
#endif
    FPTR_RESETDEV_T                 ResetDevice;
    FPTR_FLETCHER32_T               Fletcher32;
    FPTR_MINVAL_T                   MinValue;
    FPTR_MAXVAL_T                   MaxValue;
    FPTR_MEANVAL_T                  MeanValue;
    FPTR_STDDVAL_T                  StandDeviationValue;
    FPTR_RESETPERIPHERAL_T          ResetPeripheral;    /* Test functions */
    FPTR_RESETDOMAIN_T              ResetDomain;        /* Test functions */
    FPTR_HFSOURCESAFESWITCH_T       HFSourceSafeSwitch;
    FPTR_COMPAIN_T                  SelectCompAInput;
    FPTR_COMPAREF_T                 SelectCompARef;
    FPTR_ADCCOMPBIN_T               SelectADCCompBInput;
    FPTR_COMPBREF_T                 SelectCompBRef;
} HARD_API_T;

//
// Pointer to the ROM HAPI table
//
#define P_HARD_API                   ((HARD_API_T*) ROM_HAPI_TABLE_ADDR)

//
// Add wrapper around the Hapi functions needing the "bus arbitration issue" workaround
//
extern void SafeHapiAuxAdiSelect( FPTR_VOID_UINT8_T fPtr, uint8_t ut8Signal );

#define HapiCrc32(a,b,c)             P_HARD_API->Crc32(a,b,c)
#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
#define HapiGetOtpSize()             P_HARD_API->OtpGetSize()
#else
#define HapiGetFlashSize()           P_HARD_API->FlashGetSize()
#endif
#define HapiGetChipId()              P_HARD_API->GetChipId()
#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
#define HapiDummy(a)                 P_HARD_API->Dummy(a)
#define HapiProgramOtpRaw(a,b,c)     P_HARD_API->ProgramOtpRaw(a,b,c)
#define HapiProgramOtpEcc(a,b,c)     P_HARD_API->ProgramOtpEcc(a,b,c)
#else
#define HapiSectorErase(a)           MemBusWrkAroundHapiEraseSector(a)
#define HapiProgramFlash(a,b,c)      MemBusWrkAroundHapiProgramFlash(a,b,c)
#endif
#define HapiResetDevice()            P_HARD_API->ResetDevice()
#define HapiFletcher32(a,b,c)        P_HARD_API->Fletcher32(a,b,c)
#define HapiMinValue(a,b)            P_HARD_API->MinValue(a,b)
#define HapiMaxValue(a,b)            P_HARD_API->MaxValue(a,b)
#define HapiMeanValue(a,b)           P_HARD_API->MeanValue(a,b)
#define HapiStandDeviationValue(a,b) P_HARD_API->StandDeviationValue(a,b)
/* Test function */
#define HapiResetPeripheral(a)       P_HARD_API->ResetPeripheral(a)
/* Test function */
#define HapiResetDomain(a)           P_HARD_API->ResetDomain(a)
#define HapiHFSourceSafeSwitch()     P_HARD_API->HFSourceSafeSwitch()
#define HapiSelectCompAInput(a)      SafeHapiAuxAdiSelect( P_HARD_API->SelectCompAInput   , a )
#define HapiSelectCompARef(a)        SafeHapiAuxAdiSelect( P_HARD_API->SelectCompARef     , a )
#define HapiSelectADCCompBInput(a)   SafeHapiAuxAdiSelect( P_HARD_API->SelectADCCompBInput, a )
#define HapiSelectCompBRef(a)        SafeHapiAuxAdiSelect( P_HARD_API->SelectCompBRef     , a )

//
// Defines for input parameter to the HapiSelectCompAInput function.
// The define values can not be changed!
//
#define COMPA_IN_NC            0x00
#define COMPA_IN_AUXIO7        0x09
#define COMPA_IN_AUXIO6        0x0A
#define COMPA_IN_AUXIO5        0x0B
#define COMPA_IN_AUXIO4        0x0C
#define COMPA_IN_AUXIO3        0x0D
#define COMPA_IN_AUXIO2        0x0E
#define COMPA_IN_AUXIO1        0x0F
#define COMPA_IN_AUXIO0        0x10

//
// Defines for input parameter to the HapiSelectCompARef function.
// The define values can not be changed!
//
#define COMPA_REF_NC           0x00
#define COMPA_REF_VDD1P2V      0x01
#define COMPA_REF_VSSA         0x02
#define COMPA_REF_VDDA3P3V     0x03
#define COMPA_REF_ADCVREFP     0x04
#define COMPA_REF_AUXIO7       0x09
#define COMPA_REF_AUXIO6       0x0A
#define COMPA_REF_AUXIO5       0x0B
#define COMPA_REF_AUXIO4       0x0C
#define COMPA_REF_AUXIO3       0x0D
#define COMPA_REF_AUXIO2       0x0E
#define COMPA_REF_AUXIO1       0x0F
#define COMPA_REF_AUXIO0       0x10

//
// Defines for input parameter to the HapiSelectADCCompBInput function.
// The define values can not be changed!
//
#define ADC_COMPB_IN_NC        0x00
#define ADC_COMPB_IN_VDD1P2V   0x03
#define ADC_COMPB_IN_VSSA      0x04
#define ADC_COMPB_IN_VDDA3P3V  0x05
#define ADC_COMPB_IN_AUXIO7    0x09
#define ADC_COMPB_IN_AUXIO6    0x0A
#define ADC_COMPB_IN_AUXIO5    0x0B
#define ADC_COMPB_IN_AUXIO4    0x0C
#define ADC_COMPB_IN_AUXIO3    0x0D
#define ADC_COMPB_IN_AUXIO2    0x0E
#define ADC_COMPB_IN_AUXIO1    0x0F
#define ADC_COMPB_IN_AUXIO0    0x10

//
// Defines for input parameter to the HapiSelectCompBRef function.
// The define values can not be changed!
//
#define COMPB_REF_NC            0x00
#define COMPB_REF_VDD1P2V       0x01
#define COMPB_REF_VSSA          0x02
#define COMPB_REF_VDDA3P3V      0x03

#endif // __HAPI_H_

//*****************************************************************************
//
// Pointers to the main API tables.
//
//*****************************************************************************
#define ROM_APITABLE            ((uint32_t *)0x10000180)
#define ROM_VERSION             (ROM_APITABLE[0])
#define ROM_AON_EVENTTABLE      ((uint32_t *)(ROM_APITABLE[1]))
#define ROM_AON_IOCTABLE        ((uint32_t *)(ROM_APITABLE[2]))
#define ROM_AON_RTCTABLE        ((uint32_t *)(ROM_APITABLE[3]))
#define ROM_AON_WUCTABLE        ((uint32_t *)(ROM_APITABLE[4]))
#define ROM_AUX_CTRLTABLE       ((uint32_t *)(ROM_APITABLE[5]))
#define ROM_AUX_TDCTABLE        ((uint32_t *)(ROM_APITABLE[6]))
#define ROM_AUX_TIMERTABLE      ((uint32_t *)(ROM_APITABLE[7]))
#define ROM_AUX_WUCTABLE        ((uint32_t *)(ROM_APITABLE[8]))
#define ROM_DDITABLE            ((uint32_t *)(ROM_APITABLE[9]))
#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
#define ROM_OTPTABLE            ((uint32_t *)(ROM_APITABLE[10]))
#else
#define ROM_FLASHTABLE          ((uint32_t *)(ROM_APITABLE[10]))
#endif
#define ROM_I2CTABLE            ((uint32_t *)(ROM_APITABLE[11]))
#define ROM_INTERRUPTTABLE      ((uint32_t *)(ROM_APITABLE[12]))
#define ROM_IOCTABLE            ((uint32_t *)(ROM_APITABLE[13]))
#define ROM_PRCMTABLE           ((uint32_t *)(ROM_APITABLE[14]))
#define ROM_SMPHTABLE           ((uint32_t *)(ROM_APITABLE[15]))
#define ROM_SPISTABLE           ((uint32_t *)(ROM_APITABLE[16]))
#define ROM_SSITABLE            ((uint32_t *)(ROM_APITABLE[17]))
#define ROM_TIMERTABLE          ((uint32_t *)(ROM_APITABLE[18]))
#define ROM_TRNGTABLE           ((uint32_t *)(ROM_APITABLE[19]))
#define ROM_UARTTABLE           ((uint32_t *)(ROM_APITABLE[20]))
#define ROM_UDMATABLE           ((uint32_t *)(ROM_APITABLE[21]))
#define ROM_VIMSTABLE           ((uint32_t *)(ROM_APITABLE[22]))

//*****************************************************************************
//
// Macros for calling ROM functions in the AON_EVENT API.
//
//*****************************************************************************

#define ROM_AONEventMcuWakeUpSet                                              \
        ((void (*)(uint32_t ui32MCUWUEvent,                                   \
                   uint32_t ui32EventSrc))ROM_AON_EVENTTABLE[0])

#define ROM_AONEventMcuWakeUpGet                                              \
        ((uint32_t (*)(uint32_t ui32MCUWUEvent))ROM_AON_EVENTTABLE[1])

#define ROM_AONEventAuxWakeUpSet                                              \
        ((void (*)(uint32_t ui32AUXWUEvent,                                   \
                   uint32_t ui32EventSrc))ROM_AON_EVENTTABLE[2])

#define ROM_AONEventAuxWakeUpGet                                              \
        ((uint32_t (*)(uint32_t ui32AUXWUEvent))ROM_AON_EVENTTABLE[3])

#define ROM_AONEventMcuSet                                                    \
        ((void (*)(uint32_t ui32MCUEvent,                                     \
                   uint32_t ui32EventSrc))ROM_AON_EVENTTABLE[4])

#define ROM_AONEventMcuGet                                                    \
        ((uint32_t (*)(uint32_t ui32MCUEvent))ROM_AON_EVENTTABLE[5])
//*****************************************************************************
//
// Macros for calling ROM functions in the AON_IOC API.
//
//*****************************************************************************

#define ROM_AONIOCDriveStrengthSet                                            \
        ((void (*)(uint32_t ui32LowDrvStr,                                    \
                   uint32_t ui32MedDrvStr,                                    \
                   uint32_t ui32MaxDrvStr))ROM_AON_IOCTABLE[0])

#define ROM_AONIOCDriveStrengthGet                                            \
        ((uint32_t (*)(uint32_t ui32DriveLevel))ROM_AON_IOCTABLE[1])
//*****************************************************************************
//
// Macros for calling ROM functions in the AON_RTC API.
//
//*****************************************************************************

#define ROM_AONRTCStatus                                                      \
        ((uint32_t (*)(void))ROM_AON_RTCTABLE[0])

#define ROM_AONRTCEventClear                                                  \
        ((void (*)(uint32_t ui32Channel))ROM_AON_RTCTABLE[1])

#define ROM_AONRTCEventGet                                                    \
        ((bool (*)(uint32_t ui32Channel))ROM_AON_RTCTABLE[2])

#define ROM_AONRTCModeCh1Set                                                  \
        ((void (*)(uint32_t ui32Mode))ROM_AON_RTCTABLE[3])

#define ROM_AONRTCModeCh1Get                                                  \
        ((uint32_t (*)(void))ROM_AON_RTCTABLE[4])

#define ROM_AONRTCModeCh2Set                                                  \
        ((void (*)(uint32_t ui32Mode))ROM_AON_RTCTABLE[5])

#define ROM_AONRTCModeCh2Get                                                  \
        ((uint32_t (*)(void))ROM_AON_RTCTABLE[6])

#define ROM_AONRTCChannelEnable                                               \
        ((void (*)(uint32_t ui32Channel))ROM_AON_RTCTABLE[7])

#define ROM_AONRTCChannelDisable                                              \
        ((void (*)(uint32_t ui32Channel))ROM_AON_RTCTABLE[8])

#define ROM_AONRTCCompareValueSet                                             \
        ((void (*)(uint32_t ui32Channel,                                      \
                   uint32_t ui32CompValue))ROM_AON_RTCTABLE[9])

#define ROM_AONRTCCompareValueGet                                             \
        ((uint32_t (*)(uint32_t ui32Channel))ROM_AON_RTCTABLE[10])

//*****************************************************************************
//
// Macros for calling ROM functions in the AON_WUC API.
//
//*****************************************************************************


#define ROM_AONWUCAuxSRamConfig                                               \
        ((void (*)(uint32_t ui32Retention))ROM_AON_WUCTABLE[1])

#define ROM_AONWUCAuxWakeupEvent                                              \
        ((void (*)(uint32_t ui32Mode))ROM_AON_WUCTABLE[2])

#define ROM_AONWUCAuxReset                                                    \
        ((void (*)(void))ROM_AON_WUCTABLE[3])

#define ROM_AONWUCRechargeCtrlConfigSet                                       \
        ((void (*)(bool bAdaptEnable,                                         \
                   uint32_t ui32AdaptRate,                                    \
                   uint32_t ui32Period,                                       \
                   uint32_t ui32MaxPeriod))ROM_AON_WUCTABLE[4])

#define ROM_AONWUCOscConfig                                                   \
        ((void (*)(uint32_t ui32Period))ROM_AON_WUCTABLE[5])


//*****************************************************************************
//
// Macros for calling ROM functions in the AUX_TDC API.
//
//*****************************************************************************

#define ROM_AUXTDCConfigSet                                                   \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32StartCondition,                               \
                   uint32_t ui32StopCondition))ROM_AUX_TDCTABLE[0])

#define ROM_AUXTDCMeasurementDone                                             \
        ((uint32_t (*)(uint32_t ui32Base))ROM_AUX_TDCTABLE[1])
//*****************************************************************************
//
// Macros for calling ROM functions in the AUX_TIMER API.
//
//*****************************************************************************

#define ROM_AUXTimerConfigure                                                 \
        ((void (*)(uint32_t ui32Timer,                                        \
                   uint32_t ui32Config))ROM_AUX_TIMERTABLE[0])

#define ROM_AUXTimerStart                                                     \
        ((void (*)(uint32_t ui32Timer))ROM_AUX_TIMERTABLE[1])

#define ROM_AUXTimerStop                                                      \
        ((void (*)(uint32_t ui32Timer))ROM_AUX_TIMERTABLE[2])

#define ROM_AUXTimerPrescaleSet                                               \
        ((void (*)(uint32_t ui32Timer,                                        \
                   uint32_t ui32PrescaleDiv))ROM_AUX_TIMERTABLE[3])

#define ROM_AUXTimerPrescaleGet                                               \
        ((uint32_t (*)(uint32_t ui32Timer))ROM_AUX_TIMERTABLE[4])
//*****************************************************************************
//
// Macros for calling ROM functions in the AUX_WUC API.
//
//*****************************************************************************

#define ROM_AUXWUCClockEnable                                                 \
        ((void (*)(uint32_t ui32Clocks))ROM_AUX_WUCTABLE[0])

#define ROM_AUXWUCClockDisable                                                \
        ((void (*)(uint32_t ui32Clocks))ROM_AUX_WUCTABLE[1])

#define ROM_AUXWUCClockStatus                                                 \
        ((uint32_t (*)(uint32_t ui32Clocks))ROM_AUX_WUCTABLE[2])

#define ROM_AUXWUCPowerCtrl                                                   \
        ((void (*)(uint32_t ui32PowerMode))ROM_AUX_WUCTABLE[3])
//*****************************************************************************
//
// Macros for calling ROM functions in the DDI API.
//
//*****************************************************************************


#if (CC_GET_CHIP_OPTION == CC_CHIP_OPTION_OTP)
//*****************************************************************************
//
// Macros for calling ROM functions in the OTP API.
//
//*****************************************************************************

#define ROM_OTPRawProgram                                                     \
        ((uint32_t (*)(const void* pOtpAddr,                                  \
                       void* pSrc,                                            \
                       uint32_t ui32NoOfBytes))ROM_OTPTABLE[0])

#define ROM_OTPEccProgram                                                     \
        ((uint32_t (*)(const void* pOtpAddr,                                  \
                       void* pSrc,                                            \
                       uint32_t ui32NoOfBytes))ROM_OTPTABLE[1])

#define ROM_OTPElemRawProgram                                                 \
        ((uint32_t (*)(const void* pOtpAddr,                                  \
                       void* pSrc,                                            \
                       uint32_t ui32NoOfBytes,                                \
                       const void** ppui32FailOtpAddr))ROM_OTPTABLE[2])

#define ROM_OTPElemEccProgram                                                 \
        ((uint32_t (*)(const void* pOtpAddr,                                  \
                       void* pSrc,                                            \
                       uint32_t ui32NoOfBytes,                                \
                       const void** ppui32FailOtpAddr))ROM_OTPTABLE[3])

#define ROM_OTPTrimForProgram                                                 \
        ((void (*)(void))ROM_OTPTABLE[4])

#define ROM_OTPEfuseReadRow                                                   \
        ((bool (*)(uint32_t *pui32EfuseData,                                  \
                   uint32_t ui32RowAddress))ROM_OTPTABLE[5])

#define ROM_OTPRepair                                                         \
        ((bool (*)(const void* pOtpAddr))ROM_OTPTABLE[6])

#define ROM_OTPBrick                                                          \
        ((bool (*)(uint32_t ui32Key))ROM_OTPTABLE[7])

#define ROM_OTPGetFreeRepairs                                                 \
        ((uint32_t (*)(void))ROM_OTPTABLE[8])
#else
//*****************************************************************************
//
// Macros for calling ROM functions in the FLASH API.
//
//*****************************************************************************

#define ROM_FlashPowerModeGet                                                 \
        ((uint32_t (*)(void))ROM_FLASHTABLE[1])

#define ROM_FlashProtectionSet                                                \
        ((void (*)(uint32_t ui32SectorAddress,                                \
                   uint32_t ui32ProtectMode))ROM_FLASHTABLE[2])

#define ROM_FlashProtectionGet                                                \
        ((uint32_t (*)(uint32_t ui32SectorAddress))ROM_FLASHTABLE[3])

#define ROM_FlashProtectionSave                                               \
        ((uint32_t (*)(uint32_t ui32SectorAddress))ROM_FLASHTABLE[4])

#define ROM_FlashEfuseReadRow                                                 \
        ((bool (*)(uint32_t *pui32EfuseData,                                  \
                   uint32_t ui32RowAddress))ROM_FLASHTABLE[8])

#define ROM_FlashDisableSectorsForWrite                                       \
        ((void (*)(void))ROM_FLASHTABLE[9])
#endif
//*****************************************************************************
//
// Macros for calling ROM functions in the I2C API.
//
//*****************************************************************************

#define ROM_I2CMasterInitExpClk                                               \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32I2CClk,                                       \
                   bool bFast))ROM_I2CTABLE[0])

#define ROM_I2CMasterErr                                                      \
        ((uint32_t (*)(uint32_t ui32Base))ROM_I2CTABLE[1])
//*****************************************************************************
//
// Macros for calling ROM functions in the INTERRUPT API.
//
//*****************************************************************************

#define ROM_IntPriorityGroupingSet                                            \
        ((void (*)(uint32_t ui32Bits))ROM_INTERRUPTTABLE[0])

#define ROM_IntPriorityGroupingGet                                            \
        ((uint32_t (*)(void))ROM_INTERRUPTTABLE[1])

#define ROM_IntPrioritySet                                                    \
        ((void (*)(uint32_t ui32Interrupt,                                    \
                   uint8_t ui8Priority))ROM_INTERRUPTTABLE[2])

#define ROM_IntPriorityGet                                                    \
        ((int32_t (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[3])

#define ROM_IntEnable                                                         \
        ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[4])

#define ROM_IntDisable                                                        \
        ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[5])

#define ROM_IntPendSet                                                        \
        ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[6])

#define ROM_IntPendGet                                                        \
        ((bool (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[7])

#define ROM_IntPendClear                                                      \
        ((void (*)(uint32_t ui32Interrupt))ROM_INTERRUPTTABLE[8])
//*****************************************************************************
//
// Macros for calling ROM functions in the IOC API.
//
//*****************************************************************************

#define ROM_IOCPortConfigureSet                                               \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32PortId,                                       \
                   uint32_t ui32IOConfig))ROM_IOCTABLE[0])

#define ROM_IOCPortConfigureGet                                               \
        ((uint32_t (*)(uint32_t ui32IOId))ROM_IOCTABLE[1])

#define ROM_IOCIOShutdownSet                                                  \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32IOShutdown))ROM_IOCTABLE[2])


#define ROM_IOCIOModeSet                                                      \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32IOMode))ROM_IOCTABLE[4])

#define ROM_IOCIOIntSet                                                       \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32Int,                                          \
                   uint32_t ui32EdgeDet))ROM_IOCTABLE[5])

#define ROM_IOCIOPortPullSet                                                  \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32Pull))ROM_IOCTABLE[6])

#define ROM_IOCIOHystSet                                                      \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32Hysteresis))ROM_IOCTABLE[7])

#define ROM_IOCIOInputSet                                                     \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32Input))ROM_IOCTABLE[8])

#define ROM_IOCIOSlewCtrlSet                                                  \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32SlewEnable))ROM_IOCTABLE[9])

#define ROM_IOCIODrvStrengthSet                                               \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32IOCurrent,                                    \
                   uint32_t ui32DrvStrength))ROM_IOCTABLE[10])

#define ROM_IOCIOPortIdSet                                                    \
        ((void (*)(uint32_t ui32IOId,                                         \
                   uint32_t ui32PortId))ROM_IOCTABLE[11])

#define ROM_IOCIntEnable                                                      \
        ((void (*)(uint32_t ui32IOId))ROM_IOCTABLE[12])

#define ROM_IOCIntDisable                                                     \
        ((void (*)(uint32_t ui32IOId))ROM_IOCTABLE[13])

#define ROM_IOCPinTypeGpioInput                                               \
        ((void (*)(uint32_t ui32IOId))ROM_IOCTABLE[14])

#define ROM_IOCPinTypeGpioOutput                                              \
        ((void (*)(uint32_t ui32IOId))ROM_IOCTABLE[15])

#define ROM_IOCPinTypeUart                                                    \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Rx,                                           \
                   uint32_t ui32Tx,                                           \
                   uint32_t ui32Cts,                                          \
                   uint32_t ui32Rts))ROM_IOCTABLE[16])

#define ROM_IOCPinTypeSsiMaster                                               \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Rx,                                           \
                   uint32_t ui32Tx,                                           \
                   uint32_t ui32Fss,                                          \
                   uint32_t ui32Clk))ROM_IOCTABLE[17])

#define ROM_IOCPinTypeSsiSlave                                                \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Rx,                                           \
                   uint32_t ui32Tx,                                           \
                   uint32_t ui32Fss,                                          \
                   uint32_t ui32Clk))ROM_IOCTABLE[18])

#define ROM_IOCPinTypeI2c                                                     \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Data,                                         \
                   uint32_t ui32Clk))ROM_IOCTABLE[19])

#define ROM_IOCPinTypeSpis                                                    \
        ((void (*)(uint32_t ui32Rx,                                           \
                   uint32_t ui32Tx,                                           \
                   uint32_t ui32Fss,                                          \
                   uint32_t ui32Clk))ROM_IOCTABLE[20])

#define ROM_IOCPinTypeAux                                                     \
        ((void (*)(uint32_t ui32IOId))ROM_IOCTABLE[21])
//*****************************************************************************
//
// Macros for calling ROM functions in the PRCM API.
//
//*****************************************************************************

#define ROM_PRCMInfClockConfigureSet                                          \
        ((void (*)(uint32_t ui32ClkDiv,                                       \
                   uint32_t ui32PowerMode))ROM_PRCMTABLE[0])

#define ROM_PRCMInfClockConfigureGet                                          \
        ((uint32_t (*)(uint32_t ui32PowerMode))ROM_PRCMTABLE[1])


#define ROM_PRCMAudioClockConfigSet                                           \
        ((void (*)(uint32_t ui32ClkConfig,                                    \
                   uint32_t ui32SampleRate))ROM_PRCMTABLE[4])

#define ROM_PRCMPowerDomainOn                                                 \
        ((void (*)(uint32_t ui32Domains))ROM_PRCMTABLE[5])

#define ROM_PRCMPowerDomainOff                                                \
        ((void (*)(uint32_t ui32Domains))ROM_PRCMTABLE[6])

#define ROM_PRCMPeripheralRunEnable                                           \
        ((void (*)(uint32_t ui32Peripheral))ROM_PRCMTABLE[7])

#define ROM_PRCMPeripheralRunDisable                                          \
        ((void (*)(uint32_t ui32Peripheral))ROM_PRCMTABLE[8])

#define ROM_PRCMPeripheralSleepEnable                                         \
        ((void (*)(uint32_t ui32Peripheral))ROM_PRCMTABLE[9])

#define ROM_PRCMPeripheralSleepDisable                                        \
        ((void (*)(uint32_t ui32Peripheral))ROM_PRCMTABLE[10])

#define ROM_PRCMPeripheralDeepSleepEnable                                     \
        ((void (*)(uint32_t ui32Peripheral))ROM_PRCMTABLE[11])

#define ROM_PRCMPeripheralDeepSleepDisable                                    \
        ((void (*)(uint32_t ui32Peripheral))ROM_PRCMTABLE[12])

#define ROM_PRCMPowerDomainStatus                                             \
        ((uint32_t (*)(uint32_t ui32Domains))ROM_PRCMTABLE[13])

#define ROM_PRCMDeepSleep                                                     \
        ((void (*)(void))ROM_PRCMTABLE[14])

//*****************************************************************************
//
// Macros for calling ROM functions in the SMPH API.
//
//*****************************************************************************

#define ROM_SMPHAcquire                                                       \
        ((void (*)(uint32_t ui32Semaphore))ROM_SMPHTABLE[0])
//*****************************************************************************
//
// Macros for calling ROM functions in the SSI API.
//
//*****************************************************************************

#define ROM_SSIConfigSetExpClk                                                \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32SSIClk,                                       \
                   uint32_t ui32Protocol,                                     \
                   uint32_t ui32Mode,                                         \
                   uint32_t ui32BitRate,                                      \
                   uint32_t ui32DataWidth))ROM_SSITABLE[0])

#define ROM_SSIDataPut                                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Data))ROM_SSITABLE[1])

#define ROM_SSIDataPutNonBlocking                                             \
        ((int32_t (*)(uint32_t ui32Base,                                      \
                      uint32_t ui32Data))ROM_SSITABLE[2])

#define ROM_SSIDataGet                                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Data))ROM_SSITABLE[3])

#define ROM_SSIDataGetNonBlocking                                             \
        ((int32_t (*)(uint32_t ui32Base,                                      \
                      uint32_t *pui32Data))ROM_SSITABLE[4])
//*****************************************************************************
//
// Macros for calling ROM functions in the TIMER API.
//
//*****************************************************************************

#define ROM_TimerConfigure                                                    \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Config))ROM_TIMERTABLE[0])

#define ROM_TimerLevelControl                                                 \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Timer,                                        \
                   bool bInvert))ROM_TIMERTABLE[1])

#define ROM_TimerTriggerControl                                               \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Timer,                                        \
                   bool bEnable))ROM_TIMERTABLE[2])

#define ROM_TimerStallControl                                                 \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Timer,                                        \
                   bool bStall))ROM_TIMERTABLE[3])

#define ROM_TimerWaitOnTriggerControl                                         \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Timer,                                        \
                   bool bWait))ROM_TIMERTABLE[4])
//*****************************************************************************
//
// Macros for calling ROM functions in the TRNG API.
//
//*****************************************************************************

#define ROM_TRNGNumberGet                                                     \
        ((uint32_t (*)(uint32_t ui32Word))ROM_TRNGTABLE[1])
//*****************************************************************************
//
// Macros for calling ROM functions in the UART API.
//
//*****************************************************************************

#define ROM_UARTFIFOLevelGet                                                  \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32TxLevel,                                    \
                   uint32_t *pui32RxLevel))ROM_UARTTABLE[0])

#define ROM_UARTConfigSetExpClk                                               \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32UARTClk,                                      \
                   uint32_t ui32Baud,                                         \
                   uint32_t ui32Config))ROM_UARTTABLE[1])

#define ROM_UARTConfigGetExpClk                                               \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32UARTClk,                                      \
                   uint32_t *pui32Baud,                                       \
                   uint32_t *pui32Config))ROM_UARTTABLE[2])

#define ROM_UARTDisable                                                       \
        ((void (*)(uint32_t ui32Base))ROM_UARTTABLE[3])

#define ROM_UARTCharGetNonBlocking                                            \
        ((int32_t (*)(uint32_t ui32Base))ROM_UARTTABLE[4])

#define ROM_UARTCharGet                                                       \
        ((int32_t (*)(uint32_t ui32Base))ROM_UARTTABLE[5])

#define ROM_UARTCharPutNonBlocking                                            \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint8_t ui8Data))ROM_UARTTABLE[6])

#define ROM_UARTCharPut                                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint8_t ui8Data))ROM_UARTTABLE[7])
//*****************************************************************************
//
// Macros for calling ROM functions in the UDMA API.
//
//*****************************************************************************

#define ROM_uDMAChannelAttributeEnable                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32ChannelNum,                                   \
                   uint32_t ui32Attr))ROM_UDMATABLE[0])

#define ROM_uDMAChannelAttributeDisable                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32ChannelNum,                                   \
                   uint32_t ui32Attr))ROM_UDMATABLE[1])

#define ROM_uDMAChannelAttributeGet                                           \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       uint32_t ui32ChannelNum))ROM_UDMATABLE[2])

#define ROM_uDMAChannelControlSet                                             \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32ChannelStructIndex,                           \
                   uint32_t ui32Control))ROM_UDMATABLE[3])

#define ROM_uDMAChannelScatterGatherSet                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32ChannelNum,                                   \
                   uint32_t ui32TaskCount,                                    \
                   void *pvTaskList,                                          \
                   uint32_t ui32IsPeriphSG))ROM_UDMATABLE[5])

#define ROM_uDMAChannelSizeGet                                                \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       uint32_t ui32ChannelStructIndex))ROM_UDMATABLE[6])

#define ROM_uDMAChannelModeGet                                                \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       uint32_t ui32ChannelStructIndex))ROM_UDMATABLE[7])
//*****************************************************************************
//
// Macros for calling ROM functions in the VIMS API.
//
//*****************************************************************************

#define ROM_VIMSConfigure                                                     \
        ((void (*)(uint32_t ui32Base,                                         \
                   bool bRoundRobin,                                          \
                   bool bPrefetch))ROM_VIMSTABLE[0])

#define ROM_VIMSModeSet                                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Mode))ROM_VIMSTABLE[1])

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif // __ROM_H__
