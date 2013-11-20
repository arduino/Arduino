//*****************************************************************************
//
// rom_map.h - Macros to facilitate calling functions in the ROM when they are
//             available and in flash otherwise.
//
// Copyright (c) 2008-2013 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
//   Redistribution and use in source and binary forms, with or without
//   modification, are permitted provided that the following conditions
//   are met:
// 
//   Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the  
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// This is part of revision 2.0.1.11577 of the Tiva Peripheral Driver Library.
//
//*****************************************************************************

#ifndef __DRIVERLIB_ROM_MAP_H__
#define __DRIVERLIB_ROM_MAP_H__

//*****************************************************************************
//
// Macros for the ADC API.
//
//*****************************************************************************
#ifdef ROM_ADCSequenceDataGet
#define MAP_ADCSequenceDataGet                                                \
        ROM_ADCSequenceDataGet
#else
#define MAP_ADCSequenceDataGet                                                \
        ADCSequenceDataGet
#endif
#ifdef ROM_ADCIntDisable
#define MAP_ADCIntDisable                                                     \
        ROM_ADCIntDisable
#else
#define MAP_ADCIntDisable                                                     \
        ADCIntDisable
#endif
#ifdef ROM_ADCIntEnable
#define MAP_ADCIntEnable                                                      \
        ROM_ADCIntEnable
#else
#define MAP_ADCIntEnable                                                      \
        ADCIntEnable
#endif
#ifdef ROM_ADCIntStatus
#define MAP_ADCIntStatus                                                      \
        ROM_ADCIntStatus
#else
#define MAP_ADCIntStatus                                                      \
        ADCIntStatus
#endif
#ifdef ROM_ADCIntClear
#define MAP_ADCIntClear                                                       \
        ROM_ADCIntClear
#else
#define MAP_ADCIntClear                                                       \
        ADCIntClear
#endif
#ifdef ROM_ADCSequenceEnable
#define MAP_ADCSequenceEnable                                                 \
        ROM_ADCSequenceEnable
#else
#define MAP_ADCSequenceEnable                                                 \
        ADCSequenceEnable
#endif
#ifdef ROM_ADCSequenceDisable
#define MAP_ADCSequenceDisable                                                \
        ROM_ADCSequenceDisable
#else
#define MAP_ADCSequenceDisable                                                \
        ADCSequenceDisable
#endif
#ifdef ROM_ADCSequenceConfigure
#define MAP_ADCSequenceConfigure                                              \
        ROM_ADCSequenceConfigure
#else
#define MAP_ADCSequenceConfigure                                              \
        ADCSequenceConfigure
#endif
#ifdef ROM_ADCSequenceStepConfigure
#define MAP_ADCSequenceStepConfigure                                          \
        ROM_ADCSequenceStepConfigure
#else
#define MAP_ADCSequenceStepConfigure                                          \
        ADCSequenceStepConfigure
#endif
#ifdef ROM_ADCSequenceOverflow
#define MAP_ADCSequenceOverflow                                               \
        ROM_ADCSequenceOverflow
#else
#define MAP_ADCSequenceOverflow                                               \
        ADCSequenceOverflow
#endif
#ifdef ROM_ADCSequenceOverflowClear
#define MAP_ADCSequenceOverflowClear                                          \
        ROM_ADCSequenceOverflowClear
#else
#define MAP_ADCSequenceOverflowClear                                          \
        ADCSequenceOverflowClear
#endif
#ifdef ROM_ADCSequenceUnderflow
#define MAP_ADCSequenceUnderflow                                              \
        ROM_ADCSequenceUnderflow
#else
#define MAP_ADCSequenceUnderflow                                              \
        ADCSequenceUnderflow
#endif
#ifdef ROM_ADCSequenceUnderflowClear
#define MAP_ADCSequenceUnderflowClear                                         \
        ROM_ADCSequenceUnderflowClear
#else
#define MAP_ADCSequenceUnderflowClear                                         \
        ADCSequenceUnderflowClear
#endif
#ifdef ROM_ADCProcessorTrigger
#define MAP_ADCProcessorTrigger                                               \
        ROM_ADCProcessorTrigger
#else
#define MAP_ADCProcessorTrigger                                               \
        ADCProcessorTrigger
#endif
#ifdef ROM_ADCHardwareOversampleConfigure
#define MAP_ADCHardwareOversampleConfigure                                    \
        ROM_ADCHardwareOversampleConfigure
#else
#define MAP_ADCHardwareOversampleConfigure                                    \
        ADCHardwareOversampleConfigure
#endif
#ifdef ROM_ADCComparatorConfigure
#define MAP_ADCComparatorConfigure                                            \
        ROM_ADCComparatorConfigure
#else
#define MAP_ADCComparatorConfigure                                            \
        ADCComparatorConfigure
#endif
#ifdef ROM_ADCComparatorRegionSet
#define MAP_ADCComparatorRegionSet                                            \
        ROM_ADCComparatorRegionSet
#else
#define MAP_ADCComparatorRegionSet                                            \
        ADCComparatorRegionSet
#endif
#ifdef ROM_ADCComparatorReset
#define MAP_ADCComparatorReset                                                \
        ROM_ADCComparatorReset
#else
#define MAP_ADCComparatorReset                                                \
        ADCComparatorReset
#endif
#ifdef ROM_ADCComparatorIntDisable
#define MAP_ADCComparatorIntDisable                                           \
        ROM_ADCComparatorIntDisable
#else
#define MAP_ADCComparatorIntDisable                                           \
        ADCComparatorIntDisable
#endif
#ifdef ROM_ADCComparatorIntEnable
#define MAP_ADCComparatorIntEnable                                            \
        ROM_ADCComparatorIntEnable
#else
#define MAP_ADCComparatorIntEnable                                            \
        ADCComparatorIntEnable
#endif
#ifdef ROM_ADCComparatorIntStatus
#define MAP_ADCComparatorIntStatus                                            \
        ROM_ADCComparatorIntStatus
#else
#define MAP_ADCComparatorIntStatus                                            \
        ADCComparatorIntStatus
#endif
#ifdef ROM_ADCComparatorIntClear
#define MAP_ADCComparatorIntClear                                             \
        ROM_ADCComparatorIntClear
#else
#define MAP_ADCComparatorIntClear                                             \
        ADCComparatorIntClear
#endif
#ifdef ROM_ADCReferenceSet
#define MAP_ADCReferenceSet                                                   \
        ROM_ADCReferenceSet
#else
#define MAP_ADCReferenceSet                                                   \
        ADCReferenceSet
#endif
#ifdef ROM_ADCReferenceGet
#define MAP_ADCReferenceGet                                                   \
        ROM_ADCReferenceGet
#else
#define MAP_ADCReferenceGet                                                   \
        ADCReferenceGet
#endif
#ifdef ROM_ADCPhaseDelaySet
#define MAP_ADCPhaseDelaySet                                                  \
        ROM_ADCPhaseDelaySet
#else
#define MAP_ADCPhaseDelaySet                                                  \
        ADCPhaseDelaySet
#endif
#ifdef ROM_ADCPhaseDelayGet
#define MAP_ADCPhaseDelayGet                                                  \
        ROM_ADCPhaseDelayGet
#else
#define MAP_ADCPhaseDelayGet                                                  \
        ADCPhaseDelayGet
#endif
#ifdef ROM_ADCIntClearEx
#define MAP_ADCIntClearEx                                                     \
        ROM_ADCIntClearEx
#else
#define MAP_ADCIntClearEx                                                     \
        ADCIntClearEx
#endif
#ifdef ROM_ADCIntDisableEx
#define MAP_ADCIntDisableEx                                                   \
        ROM_ADCIntDisableEx
#else
#define MAP_ADCIntDisableEx                                                   \
        ADCIntDisableEx
#endif
#ifdef ROM_ADCIntEnableEx
#define MAP_ADCIntEnableEx                                                    \
        ROM_ADCIntEnableEx
#else
#define MAP_ADCIntEnableEx                                                    \
        ADCIntEnableEx
#endif
#ifdef ROM_ADCIntStatusEx
#define MAP_ADCIntStatusEx                                                    \
        ROM_ADCIntStatusEx
#else
#define MAP_ADCIntStatusEx                                                    \
        ADCIntStatusEx
#endif
#ifdef ROM_ADCSequenceDMAEnable
#define MAP_ADCSequenceDMAEnable                                              \
        ROM_ADCSequenceDMAEnable
#else
#define MAP_ADCSequenceDMAEnable                                              \
        ADCSequenceDMAEnable
#endif
#ifdef ROM_ADCSequenceDMADisable
#define MAP_ADCSequenceDMADisable                                             \
        ROM_ADCSequenceDMADisable
#else
#define MAP_ADCSequenceDMADisable                                             \
        ADCSequenceDMADisable
#endif
#ifdef ROM_ADCBusy
#define MAP_ADCBusy                                                           \
        ROM_ADCBusy
#else
#define MAP_ADCBusy                                                           \
        ADCBusy
#endif

//*****************************************************************************
//
// Macros for the AES API.
//
//*****************************************************************************
#ifdef ROM_AESIntStatus
#define MAP_AESIntStatus                                                      \
        ROM_AESIntStatus
#else
#define MAP_AESIntStatus                                                      \
        AESIntStatus
#endif
#ifdef ROM_AESAuthLengthSet
#define MAP_AESAuthLengthSet                                                  \
        ROM_AESAuthLengthSet
#else
#define MAP_AESAuthLengthSet                                                  \
        AESAuthLengthSet
#endif
#ifdef ROM_AESConfigSet
#define MAP_AESConfigSet                                                      \
        ROM_AESConfigSet
#else
#define MAP_AESConfigSet                                                      \
        AESConfigSet
#endif
#ifdef ROM_AESDataAuth
#define MAP_AESDataAuth                                                       \
        ROM_AESDataAuth
#else
#define MAP_AESDataAuth                                                       \
        AESDataAuth
#endif
#ifdef ROM_AESDataProcess
#define MAP_AESDataProcess                                                    \
        ROM_AESDataProcess
#else
#define MAP_AESDataProcess                                                    \
        AESDataProcess
#endif
#ifdef ROM_AESDataProcessAuth
#define MAP_AESDataProcessAuth                                                \
        ROM_AESDataProcessAuth
#else
#define MAP_AESDataProcessAuth                                                \
        AESDataProcessAuth
#endif
#ifdef ROM_AESDataRead
#define MAP_AESDataRead                                                       \
        ROM_AESDataRead
#else
#define MAP_AESDataRead                                                       \
        AESDataRead
#endif
#ifdef ROM_AESDataReadNonBlocking
#define MAP_AESDataReadNonBlocking                                            \
        ROM_AESDataReadNonBlocking
#else
#define MAP_AESDataReadNonBlocking                                            \
        AESDataReadNonBlocking
#endif
#ifdef ROM_AESDataWrite
#define MAP_AESDataWrite                                                      \
        ROM_AESDataWrite
#else
#define MAP_AESDataWrite                                                      \
        AESDataWrite
#endif
#ifdef ROM_AESDataWriteNonBlocking
#define MAP_AESDataWriteNonBlocking                                           \
        ROM_AESDataWriteNonBlocking
#else
#define MAP_AESDataWriteNonBlocking                                           \
        AESDataWriteNonBlocking
#endif
#ifdef ROM_AESDMADisable
#define MAP_AESDMADisable                                                     \
        ROM_AESDMADisable
#else
#define MAP_AESDMADisable                                                     \
        AESDMADisable
#endif
#ifdef ROM_AESDMAEnable
#define MAP_AESDMAEnable                                                      \
        ROM_AESDMAEnable
#else
#define MAP_AESDMAEnable                                                      \
        AESDMAEnable
#endif
#ifdef ROM_AESIntClear
#define MAP_AESIntClear                                                       \
        ROM_AESIntClear
#else
#define MAP_AESIntClear                                                       \
        AESIntClear
#endif
#ifdef ROM_AESIntDisable
#define MAP_AESIntDisable                                                     \
        ROM_AESIntDisable
#else
#define MAP_AESIntDisable                                                     \
        AESIntDisable
#endif
#ifdef ROM_AESIntEnable
#define MAP_AESIntEnable                                                      \
        ROM_AESIntEnable
#else
#define MAP_AESIntEnable                                                      \
        AESIntEnable
#endif
#ifdef ROM_AESIVSet
#define MAP_AESIVSet                                                          \
        ROM_AESIVSet
#else
#define MAP_AESIVSet                                                          \
        AESIVSet
#endif
#ifdef ROM_AESKey1Set
#define MAP_AESKey1Set                                                        \
        ROM_AESKey1Set
#else
#define MAP_AESKey1Set                                                        \
        AESKey1Set
#endif
#ifdef ROM_AESKey2Set
#define MAP_AESKey2Set                                                        \
        ROM_AESKey2Set
#else
#define MAP_AESKey2Set                                                        \
        AESKey2Set
#endif
#ifdef ROM_AESKey3Set
#define MAP_AESKey3Set                                                        \
        ROM_AESKey3Set
#else
#define MAP_AESKey3Set                                                        \
        AESKey3Set
#endif
#ifdef ROM_AESLengthSet
#define MAP_AESLengthSet                                                      \
        ROM_AESLengthSet
#else
#define MAP_AESLengthSet                                                      \
        AESLengthSet
#endif
#ifdef ROM_AESReset
#define MAP_AESReset                                                          \
        ROM_AESReset
#else
#define MAP_AESReset                                                          \
        AESReset
#endif
#ifdef ROM_AESTagRead
#define MAP_AESTagRead                                                        \
        ROM_AESTagRead
#else
#define MAP_AESTagRead                                                        \
        AESTagRead
#endif

//*****************************************************************************
//
// Macros for the CAN API.
//
//*****************************************************************************
#ifdef ROM_CANIntClear
#define MAP_CANIntClear                                                       \
        ROM_CANIntClear
#else
#define MAP_CANIntClear                                                       \
        CANIntClear
#endif
#ifdef ROM_CANInit
#define MAP_CANInit                                                           \
        ROM_CANInit
#else
#define MAP_CANInit                                                           \
        CANInit
#endif
#ifdef ROM_CANEnable
#define MAP_CANEnable                                                         \
        ROM_CANEnable
#else
#define MAP_CANEnable                                                         \
        CANEnable
#endif
#ifdef ROM_CANDisable
#define MAP_CANDisable                                                        \
        ROM_CANDisable
#else
#define MAP_CANDisable                                                        \
        CANDisable
#endif
#ifdef ROM_CANBitTimingSet
#define MAP_CANBitTimingSet                                                   \
        ROM_CANBitTimingSet
#else
#define MAP_CANBitTimingSet                                                   \
        CANBitTimingSet
#endif
#ifdef ROM_CANBitTimingGet
#define MAP_CANBitTimingGet                                                   \
        ROM_CANBitTimingGet
#else
#define MAP_CANBitTimingGet                                                   \
        CANBitTimingGet
#endif
#ifdef ROM_CANMessageSet
#define MAP_CANMessageSet                                                     \
        ROM_CANMessageSet
#else
#define MAP_CANMessageSet                                                     \
        CANMessageSet
#endif
#ifdef ROM_CANMessageGet
#define MAP_CANMessageGet                                                     \
        ROM_CANMessageGet
#else
#define MAP_CANMessageGet                                                     \
        CANMessageGet
#endif
#ifdef ROM_CANStatusGet
#define MAP_CANStatusGet                                                      \
        ROM_CANStatusGet
#else
#define MAP_CANStatusGet                                                      \
        CANStatusGet
#endif
#ifdef ROM_CANMessageClear
#define MAP_CANMessageClear                                                   \
        ROM_CANMessageClear
#else
#define MAP_CANMessageClear                                                   \
        CANMessageClear
#endif
#ifdef ROM_CANIntEnable
#define MAP_CANIntEnable                                                      \
        ROM_CANIntEnable
#else
#define MAP_CANIntEnable                                                      \
        CANIntEnable
#endif
#ifdef ROM_CANIntDisable
#define MAP_CANIntDisable                                                     \
        ROM_CANIntDisable
#else
#define MAP_CANIntDisable                                                     \
        CANIntDisable
#endif
#ifdef ROM_CANIntStatus
#define MAP_CANIntStatus                                                      \
        ROM_CANIntStatus
#else
#define MAP_CANIntStatus                                                      \
        CANIntStatus
#endif
#ifdef ROM_CANRetryGet
#define MAP_CANRetryGet                                                       \
        ROM_CANRetryGet
#else
#define MAP_CANRetryGet                                                       \
        CANRetryGet
#endif
#ifdef ROM_CANRetrySet
#define MAP_CANRetrySet                                                       \
        ROM_CANRetrySet
#else
#define MAP_CANRetrySet                                                       \
        CANRetrySet
#endif
#ifdef ROM_CANErrCntrGet
#define MAP_CANErrCntrGet                                                     \
        ROM_CANErrCntrGet
#else
#define MAP_CANErrCntrGet                                                     \
        CANErrCntrGet
#endif
#ifdef ROM_CANBitRateSet
#define MAP_CANBitRateSet                                                     \
        ROM_CANBitRateSet
#else
#define MAP_CANBitRateSet                                                     \
        CANBitRateSet
#endif

//*****************************************************************************
//
// Macros for the CIR API.
//
//*****************************************************************************
#ifdef ROM_CIRIntStatus
#define MAP_CIRIntStatus                                                      \
        ROM_CIRIntStatus
#else
#define MAP_CIRIntStatus                                                      \
        CIRIntStatus
#endif
#ifdef ROM_CIRConfigGet
#define MAP_CIRConfigGet                                                      \
        ROM_CIRConfigGet
#else
#define MAP_CIRConfigGet                                                      \
        CIRConfigGet
#endif
#ifdef ROM_CIRConfigSet
#define MAP_CIRConfigSet                                                      \
        ROM_CIRConfigSet
#else
#define MAP_CIRConfigSet                                                      \
        CIRConfigSet
#endif
#ifdef ROM_CIRIntClear
#define MAP_CIRIntClear                                                       \
        ROM_CIRIntClear
#else
#define MAP_CIRIntClear                                                       \
        CIRIntClear
#endif
#ifdef ROM_CIRIntDisable
#define MAP_CIRIntDisable                                                     \
        ROM_CIRIntDisable
#else
#define MAP_CIRIntDisable                                                     \
        CIRIntDisable
#endif
#ifdef ROM_CIRIntEnable
#define MAP_CIRIntEnable                                                      \
        ROM_CIRIntEnable
#else
#define MAP_CIRIntEnable                                                      \
        CIRIntEnable
#endif
#ifdef ROM_CIRRxCountGet
#define MAP_CIRRxCountGet                                                     \
        ROM_CIRRxCountGet
#else
#define MAP_CIRRxCountGet                                                     \
        CIRRxCountGet
#endif
#ifdef ROM_CIRRxDisable
#define MAP_CIRRxDisable                                                      \
        ROM_CIRRxDisable
#else
#define MAP_CIRRxDisable                                                      \
        CIRRxDisable
#endif
#ifdef ROM_CIRRxEnable
#define MAP_CIRRxEnable                                                       \
        ROM_CIRRxEnable
#else
#define MAP_CIRRxEnable                                                       \
        CIRRxEnable
#endif
#ifdef ROM_CIRRxMinMaxSet
#define MAP_CIRRxMinMaxSet                                                    \
        ROM_CIRRxMinMaxSet
#else
#define MAP_CIRRxMinMaxSet                                                    \
        CIRRxMinMaxSet
#endif
#ifdef ROM_CIRRxStatusGet
#define MAP_CIRRxStatusGet                                                    \
        ROM_CIRRxStatusGet
#else
#define MAP_CIRRxStatusGet                                                    \
        CIRRxStatusGet
#endif
#ifdef ROM_CIRRxWaitForOutput
#define MAP_CIRRxWaitForOutput                                                \
        ROM_CIRRxWaitForOutput
#else
#define MAP_CIRRxWaitForOutput                                                \
        CIRRxWaitForOutput
#endif
#ifdef ROM_CIRTxDisable
#define MAP_CIRTxDisable                                                      \
        ROM_CIRTxDisable
#else
#define MAP_CIRTxDisable                                                      \
        CIRTxDisable
#endif
#ifdef ROM_CIRTxEnable
#define MAP_CIRTxEnable                                                       \
        ROM_CIRTxEnable
#else
#define MAP_CIRTxEnable                                                       \
        CIRTxEnable
#endif
#ifdef ROM_CIRTxCountSet
#define MAP_CIRTxCountSet                                                     \
        ROM_CIRTxCountSet
#else
#define MAP_CIRTxCountSet                                                     \
        CIRTxCountSet
#endif
#ifdef ROM_CIRTxStatusGet
#define MAP_CIRTxStatusGet                                                    \
        ROM_CIRTxStatusGet
#else
#define MAP_CIRTxStatusGet                                                    \
        CIRTxStatusGet
#endif

//*****************************************************************************
//
// Macros for the Comparator API.
//
//*****************************************************************************
#ifdef ROM_ComparatorIntClear
#define MAP_ComparatorIntClear                                                \
        ROM_ComparatorIntClear
#else
#define MAP_ComparatorIntClear                                                \
        ComparatorIntClear
#endif
#ifdef ROM_ComparatorConfigure
#define MAP_ComparatorConfigure                                               \
        ROM_ComparatorConfigure
#else
#define MAP_ComparatorConfigure                                               \
        ComparatorConfigure
#endif
#ifdef ROM_ComparatorRefSet
#define MAP_ComparatorRefSet                                                  \
        ROM_ComparatorRefSet
#else
#define MAP_ComparatorRefSet                                                  \
        ComparatorRefSet
#endif
#ifdef ROM_ComparatorValueGet
#define MAP_ComparatorValueGet                                                \
        ROM_ComparatorValueGet
#else
#define MAP_ComparatorValueGet                                                \
        ComparatorValueGet
#endif
#ifdef ROM_ComparatorIntEnable
#define MAP_ComparatorIntEnable                                               \
        ROM_ComparatorIntEnable
#else
#define MAP_ComparatorIntEnable                                               \
        ComparatorIntEnable
#endif
#ifdef ROM_ComparatorIntDisable
#define MAP_ComparatorIntDisable                                              \
        ROM_ComparatorIntDisable
#else
#define MAP_ComparatorIntDisable                                              \
        ComparatorIntDisable
#endif
#ifdef ROM_ComparatorIntStatus
#define MAP_ComparatorIntStatus                                               \
        ROM_ComparatorIntStatus
#else
#define MAP_ComparatorIntStatus                                               \
        ComparatorIntStatus
#endif

//*****************************************************************************
//
// Macros for the CRC API.
//
//*****************************************************************************
#ifdef ROM_CRCConfigSet
#define MAP_CRCConfigSet                                                      \
        ROM_CRCConfigSet
#else
#define MAP_CRCConfigSet                                                      \
        CRCConfigSet
#endif
#ifdef ROM_CRCDataProcess
#define MAP_CRCDataProcess                                                    \
        ROM_CRCDataProcess
#else
#define MAP_CRCDataProcess                                                    \
        CRCDataProcess
#endif
#ifdef ROM_CRCDataWrite
#define MAP_CRCDataWrite                                                      \
        ROM_CRCDataWrite
#else
#define MAP_CRCDataWrite                                                      \
        CRCDataWrite
#endif
#ifdef ROM_CRCResultRead
#define MAP_CRCResultRead                                                     \
        ROM_CRCResultRead
#else
#define MAP_CRCResultRead                                                     \
        CRCResultRead
#endif
#ifdef ROM_CRCSeedSet
#define MAP_CRCSeedSet                                                        \
        ROM_CRCSeedSet
#else
#define MAP_CRCSeedSet                                                        \
        CRCSeedSet
#endif

//*****************************************************************************
//
// Macros for the DES API.
//
//*****************************************************************************
#ifdef ROM_DESIntStatus
#define MAP_DESIntStatus                                                      \
        ROM_DESIntStatus
#else
#define MAP_DESIntStatus                                                      \
        DESIntStatus
#endif
#ifdef ROM_DESConfigSet
#define MAP_DESConfigSet                                                      \
        ROM_DESConfigSet
#else
#define MAP_DESConfigSet                                                      \
        DESConfigSet
#endif
#ifdef ROM_DESDataRead
#define MAP_DESDataRead                                                       \
        ROM_DESDataRead
#else
#define MAP_DESDataRead                                                       \
        DESDataRead
#endif
#ifdef ROM_DESDataReadNonBlocking
#define MAP_DESDataReadNonBlocking                                            \
        ROM_DESDataReadNonBlocking
#else
#define MAP_DESDataReadNonBlocking                                            \
        DESDataReadNonBlocking
#endif
#ifdef ROM_DESDataProcess
#define MAP_DESDataProcess                                                    \
        ROM_DESDataProcess
#else
#define MAP_DESDataProcess                                                    \
        DESDataProcess
#endif
#ifdef ROM_DESDataWrite
#define MAP_DESDataWrite                                                      \
        ROM_DESDataWrite
#else
#define MAP_DESDataWrite                                                      \
        DESDataWrite
#endif
#ifdef ROM_DESDataWriteNonBlocking
#define MAP_DESDataWriteNonBlocking                                           \
        ROM_DESDataWriteNonBlocking
#else
#define MAP_DESDataWriteNonBlocking                                           \
        DESDataWriteNonBlocking
#endif
#ifdef ROM_DESDMADisable
#define MAP_DESDMADisable                                                     \
        ROM_DESDMADisable
#else
#define MAP_DESDMADisable                                                     \
        DESDMADisable
#endif
#ifdef ROM_DESDMAEnable
#define MAP_DESDMAEnable                                                      \
        ROM_DESDMAEnable
#else
#define MAP_DESDMAEnable                                                      \
        DESDMAEnable
#endif
#ifdef ROM_DESIntClear
#define MAP_DESIntClear                                                       \
        ROM_DESIntClear
#else
#define MAP_DESIntClear                                                       \
        DESIntClear
#endif
#ifdef ROM_DESIntDisable
#define MAP_DESIntDisable                                                     \
        ROM_DESIntDisable
#else
#define MAP_DESIntDisable                                                     \
        DESIntDisable
#endif
#ifdef ROM_DESIntEnable
#define MAP_DESIntEnable                                                      \
        ROM_DESIntEnable
#else
#define MAP_DESIntEnable                                                      \
        DESIntEnable
#endif
#ifdef ROM_DESIVSet
#define MAP_DESIVSet                                                          \
        ROM_DESIVSet
#else
#define MAP_DESIVSet                                                          \
        DESIVSet
#endif
#ifdef ROM_DESKeySet
#define MAP_DESKeySet                                                         \
        ROM_DESKeySet
#else
#define MAP_DESKeySet                                                         \
        DESKeySet
#endif
#ifdef ROM_DESLengthSet
#define MAP_DESLengthSet                                                      \
        ROM_DESLengthSet
#else
#define MAP_DESLengthSet                                                      \
        DESLengthSet
#endif
#ifdef ROM_DESReset
#define MAP_DESReset                                                          \
        ROM_DESReset
#else
#define MAP_DESReset                                                          \
        DESReset
#endif

//*****************************************************************************
//
// Macros for the EEPROM API.
//
//*****************************************************************************
#ifdef ROM_EEPROMRead
#define MAP_EEPROMRead                                                        \
        ROM_EEPROMRead
#else
#define MAP_EEPROMRead                                                        \
        EEPROMRead
#endif
#ifdef ROM_EEPROMBlockCountGet
#define MAP_EEPROMBlockCountGet                                               \
        ROM_EEPROMBlockCountGet
#else
#define MAP_EEPROMBlockCountGet                                               \
        EEPROMBlockCountGet
#endif
#ifdef ROM_EEPROMBlockHide
#define MAP_EEPROMBlockHide                                                   \
        ROM_EEPROMBlockHide
#else
#define MAP_EEPROMBlockHide                                                   \
        EEPROMBlockHide
#endif
#ifdef ROM_EEPROMBlockLock
#define MAP_EEPROMBlockLock                                                   \
        ROM_EEPROMBlockLock
#else
#define MAP_EEPROMBlockLock                                                   \
        EEPROMBlockLock
#endif
#ifdef ROM_EEPROMBlockPasswordSet
#define MAP_EEPROMBlockPasswordSet                                            \
        ROM_EEPROMBlockPasswordSet
#else
#define MAP_EEPROMBlockPasswordSet                                            \
        EEPROMBlockPasswordSet
#endif
#ifdef ROM_EEPROMBlockProtectGet
#define MAP_EEPROMBlockProtectGet                                             \
        ROM_EEPROMBlockProtectGet
#else
#define MAP_EEPROMBlockProtectGet                                             \
        EEPROMBlockProtectGet
#endif
#ifdef ROM_EEPROMBlockProtectSet
#define MAP_EEPROMBlockProtectSet                                             \
        ROM_EEPROMBlockProtectSet
#else
#define MAP_EEPROMBlockProtectSet                                             \
        EEPROMBlockProtectSet
#endif
#ifdef ROM_EEPROMBlockUnlock
#define MAP_EEPROMBlockUnlock                                                 \
        ROM_EEPROMBlockUnlock
#else
#define MAP_EEPROMBlockUnlock                                                 \
        EEPROMBlockUnlock
#endif
#ifdef ROM_EEPROMIntClear
#define MAP_EEPROMIntClear                                                    \
        ROM_EEPROMIntClear
#else
#define MAP_EEPROMIntClear                                                    \
        EEPROMIntClear
#endif
#ifdef ROM_EEPROMIntDisable
#define MAP_EEPROMIntDisable                                                  \
        ROM_EEPROMIntDisable
#else
#define MAP_EEPROMIntDisable                                                  \
        EEPROMIntDisable
#endif
#ifdef ROM_EEPROMIntEnable
#define MAP_EEPROMIntEnable                                                   \
        ROM_EEPROMIntEnable
#else
#define MAP_EEPROMIntEnable                                                   \
        EEPROMIntEnable
#endif
#ifdef ROM_EEPROMIntStatus
#define MAP_EEPROMIntStatus                                                   \
        ROM_EEPROMIntStatus
#else
#define MAP_EEPROMIntStatus                                                   \
        EEPROMIntStatus
#endif
#ifdef ROM_EEPROMMassErase
#define MAP_EEPROMMassErase                                                   \
        ROM_EEPROMMassErase
#else
#define MAP_EEPROMMassErase                                                   \
        EEPROMMassErase
#endif
#ifdef ROM_EEPROMProgram
#define MAP_EEPROMProgram                                                     \
        ROM_EEPROMProgram
#else
#define MAP_EEPROMProgram                                                     \
        EEPROMProgram
#endif
#ifdef ROM_EEPROMProgramNonBlocking
#define MAP_EEPROMProgramNonBlocking                                          \
        ROM_EEPROMProgramNonBlocking
#else
#define MAP_EEPROMProgramNonBlocking                                          \
        EEPROMProgramNonBlocking
#endif
#ifdef ROM_EEPROMSizeGet
#define MAP_EEPROMSizeGet                                                     \
        ROM_EEPROMSizeGet
#else
#define MAP_EEPROMSizeGet                                                     \
        EEPROMSizeGet
#endif
#ifdef ROM_EEPROMStatusGet
#define MAP_EEPROMStatusGet                                                   \
        ROM_EEPROMStatusGet
#else
#define MAP_EEPROMStatusGet                                                   \
        EEPROMStatusGet
#endif
#ifdef ROM_EEPROMInit
#define MAP_EEPROMInit                                                        \
        ROM_EEPROMInit
#else
#define MAP_EEPROMInit                                                        \
        EEPROMInit
#endif

//*****************************************************************************
//
// Macros for the EPI API.
//
//*****************************************************************************
#ifdef ROM_EPIIntStatus
#define MAP_EPIIntStatus                                                      \
        ROM_EPIIntStatus
#else
#define MAP_EPIIntStatus                                                      \
        EPIIntStatus
#endif
#ifdef ROM_EPIModeSet
#define MAP_EPIModeSet                                                        \
        ROM_EPIModeSet
#else
#define MAP_EPIModeSet                                                        \
        EPIModeSet
#endif
#ifdef ROM_EPIDividerSet
#define MAP_EPIDividerSet                                                     \
        ROM_EPIDividerSet
#else
#define MAP_EPIDividerSet                                                     \
        EPIDividerSet
#endif
#ifdef ROM_EPIConfigSDRAMSet
#define MAP_EPIConfigSDRAMSet                                                 \
        ROM_EPIConfigSDRAMSet
#else
#define MAP_EPIConfigSDRAMSet                                                 \
        EPIConfigSDRAMSet
#endif
#ifdef ROM_EPIConfigGPModeSet
#define MAP_EPIConfigGPModeSet                                                \
        ROM_EPIConfigGPModeSet
#else
#define MAP_EPIConfigGPModeSet                                                \
        EPIConfigGPModeSet
#endif
#ifdef ROM_EPIConfigHB8Set
#define MAP_EPIConfigHB8Set                                                   \
        ROM_EPIConfigHB8Set
#else
#define MAP_EPIConfigHB8Set                                                   \
        EPIConfigHB8Set
#endif
#ifdef ROM_EPIConfigHB16Set
#define MAP_EPIConfigHB16Set                                                  \
        ROM_EPIConfigHB16Set
#else
#define MAP_EPIConfigHB16Set                                                  \
        EPIConfigHB16Set
#endif
#ifdef ROM_EPIAddressMapSet
#define MAP_EPIAddressMapSet                                                  \
        ROM_EPIAddressMapSet
#else
#define MAP_EPIAddressMapSet                                                  \
        EPIAddressMapSet
#endif
#ifdef ROM_EPINonBlockingReadConfigure
#define MAP_EPINonBlockingReadConfigure                                       \
        ROM_EPINonBlockingReadConfigure
#else
#define MAP_EPINonBlockingReadConfigure                                       \
        EPINonBlockingReadConfigure
#endif
#ifdef ROM_EPINonBlockingReadStart
#define MAP_EPINonBlockingReadStart                                           \
        ROM_EPINonBlockingReadStart
#else
#define MAP_EPINonBlockingReadStart                                           \
        EPINonBlockingReadStart
#endif
#ifdef ROM_EPINonBlockingReadStop
#define MAP_EPINonBlockingReadStop                                            \
        ROM_EPINonBlockingReadStop
#else
#define MAP_EPINonBlockingReadStop                                            \
        EPINonBlockingReadStop
#endif
#ifdef ROM_EPINonBlockingReadCount
#define MAP_EPINonBlockingReadCount                                           \
        ROM_EPINonBlockingReadCount
#else
#define MAP_EPINonBlockingReadCount                                           \
        EPINonBlockingReadCount
#endif
#ifdef ROM_EPINonBlockingReadAvail
#define MAP_EPINonBlockingReadAvail                                           \
        ROM_EPINonBlockingReadAvail
#else
#define MAP_EPINonBlockingReadAvail                                           \
        EPINonBlockingReadAvail
#endif
#ifdef ROM_EPINonBlockingReadGet32
#define MAP_EPINonBlockingReadGet32                                           \
        ROM_EPINonBlockingReadGet32
#else
#define MAP_EPINonBlockingReadGet32                                           \
        EPINonBlockingReadGet32
#endif
#ifdef ROM_EPINonBlockingReadGet16
#define MAP_EPINonBlockingReadGet16                                           \
        ROM_EPINonBlockingReadGet16
#else
#define MAP_EPINonBlockingReadGet16                                           \
        EPINonBlockingReadGet16
#endif
#ifdef ROM_EPINonBlockingReadGet8
#define MAP_EPINonBlockingReadGet8                                            \
        ROM_EPINonBlockingReadGet8
#else
#define MAP_EPINonBlockingReadGet8                                            \
        EPINonBlockingReadGet8
#endif
#ifdef ROM_EPIFIFOConfig
#define MAP_EPIFIFOConfig                                                     \
        ROM_EPIFIFOConfig
#else
#define MAP_EPIFIFOConfig                                                     \
        EPIFIFOConfig
#endif
#ifdef ROM_EPIWriteFIFOCountGet
#define MAP_EPIWriteFIFOCountGet                                              \
        ROM_EPIWriteFIFOCountGet
#else
#define MAP_EPIWriteFIFOCountGet                                              \
        EPIWriteFIFOCountGet
#endif
#ifdef ROM_EPIIntEnable
#define MAP_EPIIntEnable                                                      \
        ROM_EPIIntEnable
#else
#define MAP_EPIIntEnable                                                      \
        EPIIntEnable
#endif
#ifdef ROM_EPIIntDisable
#define MAP_EPIIntDisable                                                     \
        ROM_EPIIntDisable
#else
#define MAP_EPIIntDisable                                                     \
        EPIIntDisable
#endif
#ifdef ROM_EPIIntErrorStatus
#define MAP_EPIIntErrorStatus                                                 \
        ROM_EPIIntErrorStatus
#else
#define MAP_EPIIntErrorStatus                                                 \
        EPIIntErrorStatus
#endif
#ifdef ROM_EPIIntErrorClear
#define MAP_EPIIntErrorClear                                                  \
        ROM_EPIIntErrorClear
#else
#define MAP_EPIIntErrorClear                                                  \
        EPIIntErrorClear
#endif
#ifdef ROM_EPIDividerCSSet
#define MAP_EPIDividerCSSet                                                   \
        ROM_EPIDividerCSSet
#else
#define MAP_EPIDividerCSSet                                                   \
        EPIDividerCSSet
#endif
#ifdef ROM_EPIDMATxCount
#define MAP_EPIDMATxCount                                                     \
        ROM_EPIDMATxCount
#else
#define MAP_EPIDMATxCount                                                     \
        EPIDMATxCount
#endif
#ifdef ROM_EPIConfigHB8CSSet
#define MAP_EPIConfigHB8CSSet                                                 \
        ROM_EPIConfigHB8CSSet
#else
#define MAP_EPIConfigHB8CSSet                                                 \
        EPIConfigHB8CSSet
#endif
#ifdef ROM_EPIConfigHB16CSSet
#define MAP_EPIConfigHB16CSSet                                                \
        ROM_EPIConfigHB16CSSet
#else
#define MAP_EPIConfigHB16CSSet                                                \
        EPIConfigHB16CSSet
#endif
#ifdef ROM_EPIConfigHB8TimingSet
#define MAP_EPIConfigHB8TimingSet                                             \
        ROM_EPIConfigHB8TimingSet
#else
#define MAP_EPIConfigHB8TimingSet                                             \
        EPIConfigHB8TimingSet
#endif
#ifdef ROM_EPIConfigHB16TimingSet
#define MAP_EPIConfigHB16TimingSet                                            \
        ROM_EPIConfigHB16TimingSet
#else
#define MAP_EPIConfigHB16TimingSet                                            \
        EPIConfigHB16TimingSet
#endif
#ifdef ROM_EPIPSRAMConfigRegSet
#define MAP_EPIPSRAMConfigRegSet                                              \
        ROM_EPIPSRAMConfigRegSet
#else
#define MAP_EPIPSRAMConfigRegSet                                              \
        EPIPSRAMConfigRegSet
#endif
#ifdef ROM_EPIPSRAMConfigRegRead
#define MAP_EPIPSRAMConfigRegRead                                             \
        ROM_EPIPSRAMConfigRegRead
#else
#define MAP_EPIPSRAMConfigRegRead                                             \
        EPIPSRAMConfigRegRead
#endif
#ifdef ROM_EPIPSRAMConfigRegGetNonBlocking
#define MAP_EPIPSRAMConfigRegGetNonBlocking                                   \
        ROM_EPIPSRAMConfigRegGetNonBlocking
#else
#define MAP_EPIPSRAMConfigRegGetNonBlocking                                   \
        EPIPSRAMConfigRegGetNonBlocking
#endif
#ifdef ROM_EPIPSRAMConfigRegGet
#define MAP_EPIPSRAMConfigRegGet                                              \
        ROM_EPIPSRAMConfigRegGet
#else
#define MAP_EPIPSRAMConfigRegGet                                              \
        EPIPSRAMConfigRegGet
#endif

//*****************************************************************************
//
// Macros for the EMAC API.
//
//*****************************************************************************
#ifdef ROM_EMACIntStatus
#define MAP_EMACIntStatus                                                     \
        ROM_EMACIntStatus
#else
#define MAP_EMACIntStatus                                                     \
        EMACIntStatus
#endif
#ifdef ROM_EMACAddrGet
#define MAP_EMACAddrGet                                                       \
        ROM_EMACAddrGet
#else
#define MAP_EMACAddrGet                                                       \
        EMACAddrGet
#endif
#ifdef ROM_EMACAddrSet
#define MAP_EMACAddrSet                                                       \
        ROM_EMACAddrSet
#else
#define MAP_EMACAddrSet                                                       \
        EMACAddrSet
#endif
#ifdef ROM_EMACConfigGet
#define MAP_EMACConfigGet                                                     \
        ROM_EMACConfigGet
#else
#define MAP_EMACConfigGet                                                     \
        EMACConfigGet
#endif
#ifdef ROM_EMACConfigSet
#define MAP_EMACConfigSet                                                     \
        ROM_EMACConfigSet
#else
#define MAP_EMACConfigSet                                                     \
        EMACConfigSet
#endif
#ifdef ROM_EMACDMAStateGet
#define MAP_EMACDMAStateGet                                                   \
        ROM_EMACDMAStateGet
#else
#define MAP_EMACDMAStateGet                                                   \
        EMACDMAStateGet
#endif
#ifdef ROM_EMACFrameFilterGet
#define MAP_EMACFrameFilterGet                                                \
        ROM_EMACFrameFilterGet
#else
#define MAP_EMACFrameFilterGet                                                \
        EMACFrameFilterGet
#endif
#ifdef ROM_EMACFrameFilterSet
#define MAP_EMACFrameFilterSet                                                \
        ROM_EMACFrameFilterSet
#else
#define MAP_EMACFrameFilterSet                                                \
        EMACFrameFilterSet
#endif
#ifdef ROM_EMACInit
#define MAP_EMACInit                                                          \
        ROM_EMACInit
#else
#define MAP_EMACInit                                                          \
        EMACInit
#endif
#ifdef ROM_EMACIntClear
#define MAP_EMACIntClear                                                      \
        ROM_EMACIntClear
#else
#define MAP_EMACIntClear                                                      \
        EMACIntClear
#endif
#ifdef ROM_EMACIntDisable
#define MAP_EMACIntDisable                                                    \
        ROM_EMACIntDisable
#else
#define MAP_EMACIntDisable                                                    \
        EMACIntDisable
#endif
#ifdef ROM_EMACIntEnable
#define MAP_EMACIntEnable                                                     \
        ROM_EMACIntEnable
#else
#define MAP_EMACIntEnable                                                     \
        EMACIntEnable
#endif
#ifdef ROM_EMACPHYConfigSet
#define MAP_EMACPHYConfigSet                                                  \
        ROM_EMACPHYConfigSet
#else
#define MAP_EMACPHYConfigSet                                                  \
        EMACPHYConfigSet
#endif
#ifdef ROM_EMACPHYPowerOff
#define MAP_EMACPHYPowerOff                                                   \
        ROM_EMACPHYPowerOff
#else
#define MAP_EMACPHYPowerOff                                                   \
        EMACPHYPowerOff
#endif
#ifdef ROM_EMACPHYPowerOn
#define MAP_EMACPHYPowerOn                                                    \
        ROM_EMACPHYPowerOn
#else
#define MAP_EMACPHYPowerOn                                                    \
        EMACPHYPowerOn
#endif
#ifdef ROM_EMACPHYRead
#define MAP_EMACPHYRead                                                       \
        ROM_EMACPHYRead
#else
#define MAP_EMACPHYRead                                                       \
        EMACPHYRead
#endif
#ifdef ROM_EMACPHYWrite
#define MAP_EMACPHYWrite                                                      \
        ROM_EMACPHYWrite
#else
#define MAP_EMACPHYWrite                                                      \
        EMACPHYWrite
#endif
#ifdef ROM_EMACReset
#define MAP_EMACReset                                                         \
        ROM_EMACReset
#else
#define MAP_EMACReset                                                         \
        EMACReset
#endif
#ifdef ROM_EMACRxDisable
#define MAP_EMACRxDisable                                                     \
        ROM_EMACRxDisable
#else
#define MAP_EMACRxDisable                                                     \
        EMACRxDisable
#endif
#ifdef ROM_EMACRxDMACurrentBufferGet
#define MAP_EMACRxDMACurrentBufferGet                                         \
        ROM_EMACRxDMACurrentBufferGet
#else
#define MAP_EMACRxDMACurrentBufferGet                                         \
        EMACRxDMACurrentBufferGet
#endif
#ifdef ROM_EMACRxDMACurrentDescriptorGet
#define MAP_EMACRxDMACurrentDescriptorGet                                     \
        ROM_EMACRxDMACurrentDescriptorGet
#else
#define MAP_EMACRxDMACurrentDescriptorGet                                     \
        EMACRxDMACurrentDescriptorGet
#endif
#ifdef ROM_EMACRxDMADescriptorListGet
#define MAP_EMACRxDMADescriptorListGet                                        \
        ROM_EMACRxDMADescriptorListGet
#else
#define MAP_EMACRxDMADescriptorListGet                                        \
        EMACRxDMADescriptorListGet
#endif
#ifdef ROM_EMACRxDMADescriptorListSet
#define MAP_EMACRxDMADescriptorListSet                                        \
        ROM_EMACRxDMADescriptorListSet
#else
#define MAP_EMACRxDMADescriptorListSet                                        \
        EMACRxDMADescriptorListSet
#endif
#ifdef ROM_EMACRxDMAPollDemand
#define MAP_EMACRxDMAPollDemand                                               \
        ROM_EMACRxDMAPollDemand
#else
#define MAP_EMACRxDMAPollDemand                                               \
        EMACRxDMAPollDemand
#endif
#ifdef ROM_EMACRxEnable
#define MAP_EMACRxEnable                                                      \
        ROM_EMACRxEnable
#else
#define MAP_EMACRxEnable                                                      \
        EMACRxEnable
#endif
#ifdef ROM_EMACRxWatchdogTimerSet
#define MAP_EMACRxWatchdogTimerSet                                            \
        ROM_EMACRxWatchdogTimerSet
#else
#define MAP_EMACRxWatchdogTimerSet                                            \
        EMACRxWatchdogTimerSet
#endif
#ifdef ROM_EMACStatusGet
#define MAP_EMACStatusGet                                                     \
        ROM_EMACStatusGet
#else
#define MAP_EMACStatusGet                                                     \
        EMACStatusGet
#endif
#ifdef ROM_EMACTxDisable
#define MAP_EMACTxDisable                                                     \
        ROM_EMACTxDisable
#else
#define MAP_EMACTxDisable                                                     \
        EMACTxDisable
#endif
#ifdef ROM_EMACTxDMACurrentBufferGet
#define MAP_EMACTxDMACurrentBufferGet                                         \
        ROM_EMACTxDMACurrentBufferGet
#else
#define MAP_EMACTxDMACurrentBufferGet                                         \
        EMACTxDMACurrentBufferGet
#endif
#ifdef ROM_EMACTxDMACurrentDescriptorGet
#define MAP_EMACTxDMACurrentDescriptorGet                                     \
        ROM_EMACTxDMACurrentDescriptorGet
#else
#define MAP_EMACTxDMACurrentDescriptorGet                                     \
        EMACTxDMACurrentDescriptorGet
#endif
#ifdef ROM_EMACTxDMADescriptorListGet
#define MAP_EMACTxDMADescriptorListGet                                        \
        ROM_EMACTxDMADescriptorListGet
#else
#define MAP_EMACTxDMADescriptorListGet                                        \
        EMACTxDMADescriptorListGet
#endif
#ifdef ROM_EMACTxDMADescriptorListSet
#define MAP_EMACTxDMADescriptorListSet                                        \
        ROM_EMACTxDMADescriptorListSet
#else
#define MAP_EMACTxDMADescriptorListSet                                        \
        EMACTxDMADescriptorListSet
#endif
#ifdef ROM_EMACTxDMAPollDemand
#define MAP_EMACTxDMAPollDemand                                               \
        ROM_EMACTxDMAPollDemand
#else
#define MAP_EMACTxDMAPollDemand                                               \
        EMACTxDMAPollDemand
#endif
#ifdef ROM_EMACTxEnable
#define MAP_EMACTxEnable                                                      \
        ROM_EMACTxEnable
#else
#define MAP_EMACTxEnable                                                      \
        EMACTxEnable
#endif
#ifdef ROM_EMACTxFlush
#define MAP_EMACTxFlush                                                       \
        ROM_EMACTxFlush
#else
#define MAP_EMACTxFlush                                                       \
        EMACTxFlush
#endif
#ifdef ROM_EMACHashFilterSet
#define MAP_EMACHashFilterSet                                                 \
        ROM_EMACHashFilterSet
#else
#define MAP_EMACHashFilterSet                                                 \
        EMACHashFilterSet
#endif

//*****************************************************************************
//
// Macros for the Fan API.
//
//*****************************************************************************
#ifdef ROM_FanIntClear
#define MAP_FanIntClear                                                       \
        ROM_FanIntClear
#else
#define MAP_FanIntClear                                                       \
        FanIntClear
#endif
#ifdef ROM_FanChannelConfigAuto
#define MAP_FanChannelConfigAuto                                              \
        ROM_FanChannelConfigAuto
#else
#define MAP_FanChannelConfigAuto                                              \
        FanChannelConfigAuto
#endif
#ifdef ROM_FanChannelConfigManual
#define MAP_FanChannelConfigManual                                            \
        ROM_FanChannelConfigManual
#else
#define MAP_FanChannelConfigManual                                            \
        FanChannelConfigManual
#endif
#ifdef ROM_FanChannelDisable
#define MAP_FanChannelDisable                                                 \
        ROM_FanChannelDisable
#else
#define MAP_FanChannelDisable                                                 \
        FanChannelDisable
#endif
#ifdef ROM_FanChannelDutyGet
#define MAP_FanChannelDutyGet                                                 \
        ROM_FanChannelDutyGet
#else
#define MAP_FanChannelDutyGet                                                 \
        FanChannelDutyGet
#endif
#ifdef ROM_FanChannelDutySet
#define MAP_FanChannelDutySet                                                 \
        ROM_FanChannelDutySet
#else
#define MAP_FanChannelDutySet                                                 \
        FanChannelDutySet
#endif
#ifdef ROM_FanChannelEnable
#define MAP_FanChannelEnable                                                  \
        ROM_FanChannelEnable
#else
#define MAP_FanChannelEnable                                                  \
        FanChannelEnable
#endif
#ifdef ROM_FanChannelRPMGet
#define MAP_FanChannelRPMGet                                                  \
        ROM_FanChannelRPMGet
#else
#define MAP_FanChannelRPMGet                                                  \
        FanChannelRPMGet
#endif
#ifdef ROM_FanChannelRPMSet
#define MAP_FanChannelRPMSet                                                  \
        ROM_FanChannelRPMSet
#else
#define MAP_FanChannelRPMSet                                                  \
        FanChannelRPMSet
#endif
#ifdef ROM_FanChannelStatus
#define MAP_FanChannelStatus                                                  \
        ROM_FanChannelStatus
#else
#define MAP_FanChannelStatus                                                  \
        FanChannelStatus
#endif
#ifdef ROM_FanChannelsGet
#define MAP_FanChannelsGet                                                    \
        ROM_FanChannelsGet
#else
#define MAP_FanChannelsGet                                                    \
        FanChannelsGet
#endif
#ifdef ROM_FanIntDisable
#define MAP_FanIntDisable                                                     \
        ROM_FanIntDisable
#else
#define MAP_FanIntDisable                                                     \
        FanIntDisable
#endif
#ifdef ROM_FanIntEnable
#define MAP_FanIntEnable                                                      \
        ROM_FanIntEnable
#else
#define MAP_FanIntEnable                                                      \
        FanIntEnable
#endif
#ifdef ROM_FanIntStatus
#define MAP_FanIntStatus                                                      \
        ROM_FanIntStatus
#else
#define MAP_FanIntStatus                                                      \
        FanIntStatus
#endif
#ifdef ROM_FanFractionalRPMDisable
#define MAP_FanFractionalRPMDisable                                           \
        ROM_FanFractionalRPMDisable
#else
#define MAP_FanFractionalRPMDisable                                           \
        FanFractionalRPMDisable
#endif
#ifdef ROM_FanFractionalRPMEnable
#define MAP_FanFractionalRPMEnable                                            \
        ROM_FanFractionalRPMEnable
#else
#define MAP_FanFractionalRPMEnable                                            \
        FanFractionalRPMEnable
#endif

//*****************************************************************************
//
// Macros for the Flash API.
//
//*****************************************************************************
#ifdef ROM_FlashProgram
#define MAP_FlashProgram                                                      \
        ROM_FlashProgram
#else
#define MAP_FlashProgram                                                      \
        FlashProgram
#endif
#ifdef ROM_FlashErase
#define MAP_FlashErase                                                        \
        ROM_FlashErase
#else
#define MAP_FlashErase                                                        \
        FlashErase
#endif
#ifdef ROM_FlashProtectGet
#define MAP_FlashProtectGet                                                   \
        ROM_FlashProtectGet
#else
#define MAP_FlashProtectGet                                                   \
        FlashProtectGet
#endif
#ifdef ROM_FlashProtectSet
#define MAP_FlashProtectSet                                                   \
        ROM_FlashProtectSet
#else
#define MAP_FlashProtectSet                                                   \
        FlashProtectSet
#endif
#ifdef ROM_FlashProtectSave
#define MAP_FlashProtectSave                                                  \
        ROM_FlashProtectSave
#else
#define MAP_FlashProtectSave                                                  \
        FlashProtectSave
#endif
#ifdef ROM_FlashUserGet
#define MAP_FlashUserGet                                                      \
        ROM_FlashUserGet
#else
#define MAP_FlashUserGet                                                      \
        FlashUserGet
#endif
#ifdef ROM_FlashUserSet
#define MAP_FlashUserSet                                                      \
        ROM_FlashUserSet
#else
#define MAP_FlashUserSet                                                      \
        FlashUserSet
#endif
#ifdef ROM_FlashUserSave
#define MAP_FlashUserSave                                                     \
        ROM_FlashUserSave
#else
#define MAP_FlashUserSave                                                     \
        FlashUserSave
#endif
#ifdef ROM_FlashIntEnable
#define MAP_FlashIntEnable                                                    \
        ROM_FlashIntEnable
#else
#define MAP_FlashIntEnable                                                    \
        FlashIntEnable
#endif
#ifdef ROM_FlashIntDisable
#define MAP_FlashIntDisable                                                   \
        ROM_FlashIntDisable
#else
#define MAP_FlashIntDisable                                                   \
        FlashIntDisable
#endif
#ifdef ROM_FlashIntStatus
#define MAP_FlashIntStatus                                                    \
        ROM_FlashIntStatus
#else
#define MAP_FlashIntStatus                                                    \
        FlashIntStatus
#endif
#ifdef ROM_FlashIntClear
#define MAP_FlashIntClear                                                     \
        ROM_FlashIntClear
#else
#define MAP_FlashIntClear                                                     \
        FlashIntClear
#endif

//*****************************************************************************
//
// Macros for the FPU API.
//
//*****************************************************************************
#ifdef ROM_FPUEnable
#define MAP_FPUEnable                                                         \
        ROM_FPUEnable
#else
#define MAP_FPUEnable                                                         \
        FPUEnable
#endif
#ifdef ROM_FPUDisable
#define MAP_FPUDisable                                                        \
        ROM_FPUDisable
#else
#define MAP_FPUDisable                                                        \
        FPUDisable
#endif
#ifdef ROM_FPUFlushToZeroModeSet
#define MAP_FPUFlushToZeroModeSet                                             \
        ROM_FPUFlushToZeroModeSet
#else
#define MAP_FPUFlushToZeroModeSet                                             \
        FPUFlushToZeroModeSet
#endif
#ifdef ROM_FPUHalfPrecisionModeSet
#define MAP_FPUHalfPrecisionModeSet                                           \
        ROM_FPUHalfPrecisionModeSet
#else
#define MAP_FPUHalfPrecisionModeSet                                           \
        FPUHalfPrecisionModeSet
#endif
#ifdef ROM_FPULazyStackingEnable
#define MAP_FPULazyStackingEnable                                             \
        ROM_FPULazyStackingEnable
#else
#define MAP_FPULazyStackingEnable                                             \
        FPULazyStackingEnable
#endif
#ifdef ROM_FPUNaNModeSet
#define MAP_FPUNaNModeSet                                                     \
        ROM_FPUNaNModeSet
#else
#define MAP_FPUNaNModeSet                                                     \
        FPUNaNModeSet
#endif
#ifdef ROM_FPURoundingModeSet
#define MAP_FPURoundingModeSet                                                \
        ROM_FPURoundingModeSet
#else
#define MAP_FPURoundingModeSet                                                \
        FPURoundingModeSet
#endif
#ifdef ROM_FPUStackingDisable
#define MAP_FPUStackingDisable                                                \
        ROM_FPUStackingDisable
#else
#define MAP_FPUStackingDisable                                                \
        FPUStackingDisable
#endif
#ifdef ROM_FPUStackingEnable
#define MAP_FPUStackingEnable                                                 \
        ROM_FPUStackingEnable
#else
#define MAP_FPUStackingEnable                                                 \
        FPUStackingEnable
#endif

//*****************************************************************************
//
// Macros for the GPIO API.
//
//*****************************************************************************
#ifdef ROM_GPIOPinWrite
#define MAP_GPIOPinWrite                                                      \
        ROM_GPIOPinWrite
#else
#define MAP_GPIOPinWrite                                                      \
        GPIOPinWrite
#endif
#ifdef ROM_GPIODirModeSet
#define MAP_GPIODirModeSet                                                    \
        ROM_GPIODirModeSet
#else
#define MAP_GPIODirModeSet                                                    \
        GPIODirModeSet
#endif
#ifdef ROM_GPIODirModeGet
#define MAP_GPIODirModeGet                                                    \
        ROM_GPIODirModeGet
#else
#define MAP_GPIODirModeGet                                                    \
        GPIODirModeGet
#endif
#ifdef ROM_GPIOIntTypeSet
#define MAP_GPIOIntTypeSet                                                    \
        ROM_GPIOIntTypeSet
#else
#define MAP_GPIOIntTypeSet                                                    \
        GPIOIntTypeSet
#endif
#ifdef ROM_GPIOIntTypeGet
#define MAP_GPIOIntTypeGet                                                    \
        ROM_GPIOIntTypeGet
#else
#define MAP_GPIOIntTypeGet                                                    \
        GPIOIntTypeGet
#endif
#ifdef ROM_GPIOPadConfigSet
#define MAP_GPIOPadConfigSet                                                  \
        ROM_GPIOPadConfigSet
#else
#define MAP_GPIOPadConfigSet                                                  \
        GPIOPadConfigSet
#endif
#ifdef ROM_GPIOPadConfigGet
#define MAP_GPIOPadConfigGet                                                  \
        ROM_GPIOPadConfigGet
#else
#define MAP_GPIOPadConfigGet                                                  \
        GPIOPadConfigGet
#endif
#ifdef ROM_GPIOPinRead
#define MAP_GPIOPinRead                                                       \
        ROM_GPIOPinRead
#else
#define MAP_GPIOPinRead                                                       \
        GPIOPinRead
#endif
#ifdef ROM_GPIOPinTypeCAN
#define MAP_GPIOPinTypeCAN                                                    \
        ROM_GPIOPinTypeCAN
#else
#define MAP_GPIOPinTypeCAN                                                    \
        GPIOPinTypeCAN
#endif
#ifdef ROM_GPIOPinTypeComparator
#define MAP_GPIOPinTypeComparator                                             \
        ROM_GPIOPinTypeComparator
#else
#define MAP_GPIOPinTypeComparator                                             \
        GPIOPinTypeComparator
#endif
#ifdef ROM_GPIOPinTypeGPIOInput
#define MAP_GPIOPinTypeGPIOInput                                              \
        ROM_GPIOPinTypeGPIOInput
#else
#define MAP_GPIOPinTypeGPIOInput                                              \
        GPIOPinTypeGPIOInput
#endif
#ifdef ROM_GPIOPinTypeGPIOOutput
#define MAP_GPIOPinTypeGPIOOutput                                             \
        ROM_GPIOPinTypeGPIOOutput
#else
#define MAP_GPIOPinTypeGPIOOutput                                             \
        GPIOPinTypeGPIOOutput
#endif
#ifdef ROM_GPIOPinTypeI2C
#define MAP_GPIOPinTypeI2C                                                    \
        ROM_GPIOPinTypeI2C
#else
#define MAP_GPIOPinTypeI2C                                                    \
        GPIOPinTypeI2C
#endif
#ifdef ROM_GPIOPinTypePWM
#define MAP_GPIOPinTypePWM                                                    \
        ROM_GPIOPinTypePWM
#else
#define MAP_GPIOPinTypePWM                                                    \
        GPIOPinTypePWM
#endif
#ifdef ROM_GPIOPinTypeQEI
#define MAP_GPIOPinTypeQEI                                                    \
        ROM_GPIOPinTypeQEI
#else
#define MAP_GPIOPinTypeQEI                                                    \
        GPIOPinTypeQEI
#endif
#ifdef ROM_GPIOPinTypeSSI
#define MAP_GPIOPinTypeSSI                                                    \
        ROM_GPIOPinTypeSSI
#else
#define MAP_GPIOPinTypeSSI                                                    \
        GPIOPinTypeSSI
#endif
#ifdef ROM_GPIOPinTypeTimer
#define MAP_GPIOPinTypeTimer                                                  \
        ROM_GPIOPinTypeTimer
#else
#define MAP_GPIOPinTypeTimer                                                  \
        GPIOPinTypeTimer
#endif
#ifdef ROM_GPIOPinTypeUART
#define MAP_GPIOPinTypeUART                                                   \
        ROM_GPIOPinTypeUART
#else
#define MAP_GPIOPinTypeUART                                                   \
        GPIOPinTypeUART
#endif
#ifdef ROM_GPIOPinTypeGPIOOutputOD
#define MAP_GPIOPinTypeGPIOOutputOD                                           \
        ROM_GPIOPinTypeGPIOOutputOD
#else
#define MAP_GPIOPinTypeGPIOOutputOD                                           \
        GPIOPinTypeGPIOOutputOD
#endif
#ifdef ROM_GPIOPinTypeADC
#define MAP_GPIOPinTypeADC                                                    \
        ROM_GPIOPinTypeADC
#else
#define MAP_GPIOPinTypeADC                                                    \
        GPIOPinTypeADC
#endif
#ifdef ROM_GPIOPinTypeUSBDigital
#define MAP_GPIOPinTypeUSBDigital                                             \
        ROM_GPIOPinTypeUSBDigital
#else
#define MAP_GPIOPinTypeUSBDigital                                             \
        GPIOPinTypeUSBDigital
#endif
#ifdef ROM_GPIOPinConfigure
#define MAP_GPIOPinConfigure                                                  \
        ROM_GPIOPinConfigure
#else
#define MAP_GPIOPinConfigure                                                  \
        GPIOPinConfigure
#endif
#ifdef ROM_GPIOPinTypeUSBAnalog
#define MAP_GPIOPinTypeUSBAnalog                                              \
        ROM_GPIOPinTypeUSBAnalog
#else
#define MAP_GPIOPinTypeUSBAnalog                                              \
        GPIOPinTypeUSBAnalog
#endif
#ifdef ROM_GPIOPinTypeEPI
#define MAP_GPIOPinTypeEPI                                                    \
        ROM_GPIOPinTypeEPI
#else
#define MAP_GPIOPinTypeEPI                                                    \
        GPIOPinTypeEPI
#endif
#ifdef ROM_GPIODMATriggerEnable
#define MAP_GPIODMATriggerEnable                                              \
        ROM_GPIODMATriggerEnable
#else
#define MAP_GPIODMATriggerEnable                                              \
        GPIODMATriggerEnable
#endif
#ifdef ROM_GPIODMATriggerDisable
#define MAP_GPIODMATriggerDisable                                             \
        ROM_GPIODMATriggerDisable
#else
#define MAP_GPIODMATriggerDisable                                             \
        GPIODMATriggerDisable
#endif
#ifdef ROM_GPIOADCTriggerEnable
#define MAP_GPIOADCTriggerEnable                                              \
        ROM_GPIOADCTriggerEnable
#else
#define MAP_GPIOADCTriggerEnable                                              \
        GPIOADCTriggerEnable
#endif
#ifdef ROM_GPIOADCTriggerDisable
#define MAP_GPIOADCTriggerDisable                                             \
        ROM_GPIOADCTriggerDisable
#else
#define MAP_GPIOADCTriggerDisable                                             \
        GPIOADCTriggerDisable
#endif
#ifdef ROM_GPIOPinTypeFan
#define MAP_GPIOPinTypeFan                                                    \
        ROM_GPIOPinTypeFan
#else
#define MAP_GPIOPinTypeFan                                                    \
        GPIOPinTypeFan
#endif
#ifdef ROM_GPIOPinTypeLPC
#define MAP_GPIOPinTypeLPC                                                    \
        ROM_GPIOPinTypeLPC
#else
#define MAP_GPIOPinTypeLPC                                                    \
        GPIOPinTypeLPC
#endif
#ifdef ROM_GPIOPinTypePECIRx
#define MAP_GPIOPinTypePECIRx                                                 \
        ROM_GPIOPinTypePECIRx
#else
#define MAP_GPIOPinTypePECIRx                                                 \
        GPIOPinTypePECIRx
#endif
#ifdef ROM_GPIOPinTypePECITx
#define MAP_GPIOPinTypePECITx                                                 \
        ROM_GPIOPinTypePECITx
#else
#define MAP_GPIOPinTypePECITx                                                 \
        GPIOPinTypePECITx
#endif
#ifdef ROM_GPIOPinTypeI2CSCL
#define MAP_GPIOPinTypeI2CSCL                                                 \
        ROM_GPIOPinTypeI2CSCL
#else
#define MAP_GPIOPinTypeI2CSCL                                                 \
        GPIOPinTypeI2CSCL
#endif
#ifdef ROM_GPIOPinTypeCIR
#define MAP_GPIOPinTypeCIR                                                    \
        ROM_GPIOPinTypeCIR
#else
#define MAP_GPIOPinTypeCIR                                                    \
        GPIOPinTypeCIR
#endif
#ifdef ROM_GPIOPinTypeKBRow
#define MAP_GPIOPinTypeKBRow                                                  \
        ROM_GPIOPinTypeKBRow
#else
#define MAP_GPIOPinTypeKBRow                                                  \
        GPIOPinTypeKBRow
#endif
#ifdef ROM_GPIOPinTypeKBColumn
#define MAP_GPIOPinTypeKBColumn                                               \
        ROM_GPIOPinTypeKBColumn
#else
#define MAP_GPIOPinTypeKBColumn                                               \
        GPIOPinTypeKBColumn
#endif
#ifdef ROM_GPIOPinTypeLEDSeq
#define MAP_GPIOPinTypeLEDSeq                                                 \
        ROM_GPIOPinTypeLEDSeq
#else
#define MAP_GPIOPinTypeLEDSeq                                                 \
        GPIOPinTypeLEDSeq
#endif
#ifdef ROM_GPIOPinTypeOneWire
#define MAP_GPIOPinTypeOneWire                                                \
        ROM_GPIOPinTypeOneWire
#else
#define MAP_GPIOPinTypeOneWire                                                \
        GPIOPinTypeOneWire
#endif
#ifdef ROM_GPIOPinTypePS2
#define MAP_GPIOPinTypePS2                                                    \
        ROM_GPIOPinTypePS2
#else
#define MAP_GPIOPinTypePS2                                                    \
        GPIOPinTypePS2
#endif
#ifdef ROM_GPIOPinTypeWakeHigh
#define MAP_GPIOPinTypeWakeHigh                                               \
        ROM_GPIOPinTypeWakeHigh
#else
#define MAP_GPIOPinTypeWakeHigh                                               \
        GPIOPinTypeWakeHigh
#endif
#ifdef ROM_GPIOPinTypeWakeLow
#define MAP_GPIOPinTypeWakeLow                                                \
        ROM_GPIOPinTypeWakeLow
#else
#define MAP_GPIOPinTypeWakeLow                                                \
        GPIOPinTypeWakeLow
#endif
#ifdef ROM_GPIOPinTypePECIAnalog
#define MAP_GPIOPinTypePECIAnalog                                             \
        ROM_GPIOPinTypePECIAnalog
#else
#define MAP_GPIOPinTypePECIAnalog                                             \
        GPIOPinTypePECIAnalog
#endif
#ifdef ROM_GPIOIntClear
#define MAP_GPIOIntClear                                                      \
        ROM_GPIOIntClear
#else
#define MAP_GPIOIntClear                                                      \
        GPIOIntClear
#endif
#ifdef ROM_GPIOIntDisable
#define MAP_GPIOIntDisable                                                    \
        ROM_GPIOIntDisable
#else
#define MAP_GPIOIntDisable                                                    \
        GPIOIntDisable
#endif
#ifdef ROM_GPIOIntEnable
#define MAP_GPIOIntEnable                                                     \
        ROM_GPIOIntEnable
#else
#define MAP_GPIOIntEnable                                                     \
        GPIOIntEnable
#endif
#ifdef ROM_GPIOIntStatus
#define MAP_GPIOIntStatus                                                     \
        ROM_GPIOIntStatus
#else
#define MAP_GPIOIntStatus                                                     \
        GPIOIntStatus
#endif
#ifdef ROM_GPIOPinWakeStatus
#define MAP_GPIOPinWakeStatus                                                 \
        ROM_GPIOPinWakeStatus
#else
#define MAP_GPIOPinWakeStatus                                                 \
        GPIOPinWakeStatus
#endif
#ifdef ROM_GPIOPinTypeLCD
#define MAP_GPIOPinTypeLCD                                                    \
        ROM_GPIOPinTypeLCD
#else
#define MAP_GPIOPinTypeLCD                                                    \
        GPIOPinTypeLCD
#endif

//*****************************************************************************
//
// Macros for the Hibernate API.
//
//*****************************************************************************
#ifdef ROM_HibernateIntClear
#define MAP_HibernateIntClear                                                 \
        ROM_HibernateIntClear
#else
#define MAP_HibernateIntClear                                                 \
        HibernateIntClear
#endif
#ifdef ROM_HibernateEnableExpClk
#define MAP_HibernateEnableExpClk                                             \
        ROM_HibernateEnableExpClk
#else
#define MAP_HibernateEnableExpClk                                             \
        HibernateEnableExpClk
#endif
#ifdef ROM_HibernateDisable
#define MAP_HibernateDisable                                                  \
        ROM_HibernateDisable
#else
#define MAP_HibernateDisable                                                  \
        HibernateDisable
#endif
#ifdef ROM_HibernateRTCEnable
#define MAP_HibernateRTCEnable                                                \
        ROM_HibernateRTCEnable
#else
#define MAP_HibernateRTCEnable                                                \
        HibernateRTCEnable
#endif
#ifdef ROM_HibernateRTCDisable
#define MAP_HibernateRTCDisable                                               \
        ROM_HibernateRTCDisable
#else
#define MAP_HibernateRTCDisable                                               \
        HibernateRTCDisable
#endif
#ifdef ROM_HibernateWakeSet
#define MAP_HibernateWakeSet                                                  \
        ROM_HibernateWakeSet
#else
#define MAP_HibernateWakeSet                                                  \
        HibernateWakeSet
#endif
#ifdef ROM_HibernateWakeGet
#define MAP_HibernateWakeGet                                                  \
        ROM_HibernateWakeGet
#else
#define MAP_HibernateWakeGet                                                  \
        HibernateWakeGet
#endif
#ifdef ROM_HibernateLowBatSet
#define MAP_HibernateLowBatSet                                                \
        ROM_HibernateLowBatSet
#else
#define MAP_HibernateLowBatSet                                                \
        HibernateLowBatSet
#endif
#ifdef ROM_HibernateLowBatGet
#define MAP_HibernateLowBatGet                                                \
        ROM_HibernateLowBatGet
#else
#define MAP_HibernateLowBatGet                                                \
        HibernateLowBatGet
#endif
#ifdef ROM_HibernateRTCSet
#define MAP_HibernateRTCSet                                                   \
        ROM_HibernateRTCSet
#else
#define MAP_HibernateRTCSet                                                   \
        HibernateRTCSet
#endif
#ifdef ROM_HibernateRTCGet
#define MAP_HibernateRTCGet                                                   \
        ROM_HibernateRTCGet
#else
#define MAP_HibernateRTCGet                                                   \
        HibernateRTCGet
#endif
#ifdef ROM_HibernateRTCTrimSet
#define MAP_HibernateRTCTrimSet                                               \
        ROM_HibernateRTCTrimSet
#else
#define MAP_HibernateRTCTrimSet                                               \
        HibernateRTCTrimSet
#endif
#ifdef ROM_HibernateRTCTrimGet
#define MAP_HibernateRTCTrimGet                                               \
        ROM_HibernateRTCTrimGet
#else
#define MAP_HibernateRTCTrimGet                                               \
        HibernateRTCTrimGet
#endif
#ifdef ROM_HibernateDataSet
#define MAP_HibernateDataSet                                                  \
        ROM_HibernateDataSet
#else
#define MAP_HibernateDataSet                                                  \
        HibernateDataSet
#endif
#ifdef ROM_HibernateDataGet
#define MAP_HibernateDataGet                                                  \
        ROM_HibernateDataGet
#else
#define MAP_HibernateDataGet                                                  \
        HibernateDataGet
#endif
#ifdef ROM_HibernateRequest
#define MAP_HibernateRequest                                                  \
        ROM_HibernateRequest
#else
#define MAP_HibernateRequest                                                  \
        HibernateRequest
#endif
#ifdef ROM_HibernateIntEnable
#define MAP_HibernateIntEnable                                                \
        ROM_HibernateIntEnable
#else
#define MAP_HibernateIntEnable                                                \
        HibernateIntEnable
#endif
#ifdef ROM_HibernateIntDisable
#define MAP_HibernateIntDisable                                               \
        ROM_HibernateIntDisable
#else
#define MAP_HibernateIntDisable                                               \
        HibernateIntDisable
#endif
#ifdef ROM_HibernateIntStatus
#define MAP_HibernateIntStatus                                                \
        ROM_HibernateIntStatus
#else
#define MAP_HibernateIntStatus                                                \
        HibernateIntStatus
#endif
#ifdef ROM_HibernateIsActive
#define MAP_HibernateIsActive                                                 \
        ROM_HibernateIsActive
#else
#define MAP_HibernateIsActive                                                 \
        HibernateIsActive
#endif
#ifdef ROM_HibernateRTCSSGet
#define MAP_HibernateRTCSSGet                                                 \
        ROM_HibernateRTCSSGet
#else
#define MAP_HibernateRTCSSGet                                                 \
        HibernateRTCSSGet
#endif
#ifdef ROM_HibernateClockConfig
#define MAP_HibernateClockConfig                                              \
        ROM_HibernateClockConfig
#else
#define MAP_HibernateClockConfig                                              \
        HibernateClockConfig
#endif
#ifdef ROM_HibernateBatCheckStart
#define MAP_HibernateBatCheckStart                                            \
        ROM_HibernateBatCheckStart
#else
#define MAP_HibernateBatCheckStart                                            \
        HibernateBatCheckStart
#endif
#ifdef ROM_HibernateBatCheckDone
#define MAP_HibernateBatCheckDone                                             \
        ROM_HibernateBatCheckDone
#else
#define MAP_HibernateBatCheckDone                                             \
        HibernateBatCheckDone
#endif
#ifdef ROM_HibernateGPIORetentionEnable
#define MAP_HibernateGPIORetentionEnable                                      \
        ROM_HibernateGPIORetentionEnable
#else
#define MAP_HibernateGPIORetentionEnable                                      \
        HibernateGPIORetentionEnable
#endif
#ifdef ROM_HibernateGPIORetentionDisable
#define MAP_HibernateGPIORetentionDisable                                     \
        ROM_HibernateGPIORetentionDisable
#else
#define MAP_HibernateGPIORetentionDisable                                     \
        HibernateGPIORetentionDisable
#endif
#ifdef ROM_HibernateGPIORetentionGet
#define MAP_HibernateGPIORetentionGet                                         \
        ROM_HibernateGPIORetentionGet
#else
#define MAP_HibernateGPIORetentionGet                                         \
        HibernateGPIORetentionGet
#endif
#ifdef ROM_HibernateCounterMode
#define MAP_HibernateCounterMode                                              \
        ROM_HibernateCounterMode
#else
#define MAP_HibernateCounterMode                                              \
        HibernateCounterMode
#endif
#ifdef ROM_HibernateCalendarSet
#define MAP_HibernateCalendarSet                                              \
        ROM_HibernateCalendarSet
#else
#define MAP_HibernateCalendarSet                                              \
        HibernateCalendarSet
#endif
#ifdef ROM_HibernateCalendarGet
#define MAP_HibernateCalendarGet                                              \
        ROM_HibernateCalendarGet
#else
#define MAP_HibernateCalendarGet                                              \
        HibernateCalendarGet
#endif
#ifdef ROM_HibernateCalendarMatchSet
#define MAP_HibernateCalendarMatchSet                                         \
        ROM_HibernateCalendarMatchSet
#else
#define MAP_HibernateCalendarMatchSet                                         \
        HibernateCalendarMatchSet
#endif
#ifdef ROM_HibernateCalendarMatchGet
#define MAP_HibernateCalendarMatchGet                                         \
        ROM_HibernateCalendarMatchGet
#else
#define MAP_HibernateCalendarMatchGet                                         \
        HibernateCalendarMatchGet
#endif
#ifdef ROM_HibernateTamperDisable
#define MAP_HibernateTamperDisable                                            \
        ROM_HibernateTamperDisable
#else
#define MAP_HibernateTamperDisable                                            \
        HibernateTamperDisable
#endif
#ifdef ROM_HibernateTamperEnable
#define MAP_HibernateTamperEnable                                             \
        ROM_HibernateTamperEnable
#else
#define MAP_HibernateTamperEnable                                             \
        HibernateTamperEnable
#endif
#ifdef ROM_HibernateTamperEventsClear
#define MAP_HibernateTamperEventsClear                                        \
        ROM_HibernateTamperEventsClear
#else
#define MAP_HibernateTamperEventsClear                                        \
        HibernateTamperEventsClear
#endif
#ifdef ROM_HibernateTamperEventsConfig
#define MAP_HibernateTamperEventsConfig                                       \
        ROM_HibernateTamperEventsConfig
#else
#define MAP_HibernateTamperEventsConfig                                       \
        HibernateTamperEventsConfig
#endif
#ifdef ROM_HibernateTamperEventsGet
#define MAP_HibernateTamperEventsGet                                          \
        ROM_HibernateTamperEventsGet
#else
#define MAP_HibernateTamperEventsGet                                          \
        HibernateTamperEventsGet
#endif
#ifdef ROM_HibernateTamperExtOscValid
#define MAP_HibernateTamperExtOscValid                                        \
        ROM_HibernateTamperExtOscValid
#else
#define MAP_HibernateTamperExtOscValid                                        \
        HibernateTamperExtOscValid
#endif
#ifdef ROM_HibernateTamperExtOscRecover
#define MAP_HibernateTamperExtOscRecover                                      \
        ROM_HibernateTamperExtOscRecover
#else
#define MAP_HibernateTamperExtOscRecover                                      \
        HibernateTamperExtOscRecover
#endif
#ifdef ROM_HibernateTamperIODisable
#define MAP_HibernateTamperIODisable                                          \
        ROM_HibernateTamperIODisable
#else
#define MAP_HibernateTamperIODisable                                          \
        HibernateTamperIODisable
#endif
#ifdef ROM_HibernateTamperIOEnable
#define MAP_HibernateTamperIOEnable                                           \
        ROM_HibernateTamperIOEnable
#else
#define MAP_HibernateTamperIOEnable                                           \
        HibernateTamperIOEnable
#endif
#ifdef ROM_HibernateTamperStatusGet
#define MAP_HibernateTamperStatusGet                                          \
        ROM_HibernateTamperStatusGet
#else
#define MAP_HibernateTamperStatusGet                                          \
        HibernateTamperStatusGet
#endif
#ifdef ROM_HibernateRTCSSMatchGet
#define MAP_HibernateRTCSSMatchGet                                            \
        ROM_HibernateRTCSSMatchGet
#else
#define MAP_HibernateRTCSSMatchGet                                            \
        HibernateRTCSSMatchGet
#endif

//*****************************************************************************
//
// Macros for the I2C API.
//
//*****************************************************************************
#ifdef ROM_I2CMasterDataPut
#define MAP_I2CMasterDataPut                                                  \
        ROM_I2CMasterDataPut
#else
#define MAP_I2CMasterDataPut                                                  \
        I2CMasterDataPut
#endif
#ifdef ROM_I2CMasterInitExpClk
#define MAP_I2CMasterInitExpClk                                               \
        ROM_I2CMasterInitExpClk
#else
#define MAP_I2CMasterInitExpClk                                               \
        I2CMasterInitExpClk
#endif
#ifdef ROM_I2CMasterEnable
#define MAP_I2CMasterEnable                                                   \
        ROM_I2CMasterEnable
#else
#define MAP_I2CMasterEnable                                                   \
        I2CMasterEnable
#endif
#ifdef ROM_I2CMasterDisable
#define MAP_I2CMasterDisable                                                  \
        ROM_I2CMasterDisable
#else
#define MAP_I2CMasterDisable                                                  \
        I2CMasterDisable
#endif
#ifdef ROM_I2CMasterIntEnable
#define MAP_I2CMasterIntEnable                                                \
        ROM_I2CMasterIntEnable
#else
#define MAP_I2CMasterIntEnable                                                \
        I2CMasterIntEnable
#endif
#ifdef ROM_I2CMasterIntDisable
#define MAP_I2CMasterIntDisable                                               \
        ROM_I2CMasterIntDisable
#else
#define MAP_I2CMasterIntDisable                                               \
        I2CMasterIntDisable
#endif
#ifdef ROM_I2CMasterIntStatus
#define MAP_I2CMasterIntStatus                                                \
        ROM_I2CMasterIntStatus
#else
#define MAP_I2CMasterIntStatus                                                \
        I2CMasterIntStatus
#endif
#ifdef ROM_I2CMasterIntClear
#define MAP_I2CMasterIntClear                                                 \
        ROM_I2CMasterIntClear
#else
#define MAP_I2CMasterIntClear                                                 \
        I2CMasterIntClear
#endif
#ifdef ROM_I2CMasterSlaveAddrSet
#define MAP_I2CMasterSlaveAddrSet                                             \
        ROM_I2CMasterSlaveAddrSet
#else
#define MAP_I2CMasterSlaveAddrSet                                             \
        I2CMasterSlaveAddrSet
#endif
#ifdef ROM_I2CMasterBusy
#define MAP_I2CMasterBusy                                                     \
        ROM_I2CMasterBusy
#else
#define MAP_I2CMasterBusy                                                     \
        I2CMasterBusy
#endif
#ifdef ROM_I2CMasterBusBusy
#define MAP_I2CMasterBusBusy                                                  \
        ROM_I2CMasterBusBusy
#else
#define MAP_I2CMasterBusBusy                                                  \
        I2CMasterBusBusy
#endif
#ifdef ROM_I2CMasterControl
#define MAP_I2CMasterControl                                                  \
        ROM_I2CMasterControl
#else
#define MAP_I2CMasterControl                                                  \
        I2CMasterControl
#endif
#ifdef ROM_I2CMasterErr
#define MAP_I2CMasterErr                                                      \
        ROM_I2CMasterErr
#else
#define MAP_I2CMasterErr                                                      \
        I2CMasterErr
#endif
#ifdef ROM_I2CMasterDataGet
#define MAP_I2CMasterDataGet                                                  \
        ROM_I2CMasterDataGet
#else
#define MAP_I2CMasterDataGet                                                  \
        I2CMasterDataGet
#endif
#ifdef ROM_I2CMasterIntEnableEx
#define MAP_I2CMasterIntEnableEx                                              \
        ROM_I2CMasterIntEnableEx
#else
#define MAP_I2CMasterIntEnableEx                                              \
        I2CMasterIntEnableEx
#endif
#ifdef ROM_I2CMasterIntDisableEx
#define MAP_I2CMasterIntDisableEx                                             \
        ROM_I2CMasterIntDisableEx
#else
#define MAP_I2CMasterIntDisableEx                                             \
        I2CMasterIntDisableEx
#endif
#ifdef ROM_I2CMasterIntStatusEx
#define MAP_I2CMasterIntStatusEx                                              \
        ROM_I2CMasterIntStatusEx
#else
#define MAP_I2CMasterIntStatusEx                                              \
        I2CMasterIntStatusEx
#endif
#ifdef ROM_I2CMasterIntClearEx
#define MAP_I2CMasterIntClearEx                                               \
        ROM_I2CMasterIntClearEx
#else
#define MAP_I2CMasterIntClearEx                                               \
        I2CMasterIntClearEx
#endif
#ifdef ROM_I2CMasterTimeoutSet
#define MAP_I2CMasterTimeoutSet                                               \
        ROM_I2CMasterTimeoutSet
#else
#define MAP_I2CMasterTimeoutSet                                               \
        I2CMasterTimeoutSet
#endif
#ifdef ROM_I2CMasterLineStateGet
#define MAP_I2CMasterLineStateGet                                             \
        ROM_I2CMasterLineStateGet
#else
#define MAP_I2CMasterLineStateGet                                             \
        I2CMasterLineStateGet
#endif
#ifdef ROM_I2CTxFIFOConfigSet
#define MAP_I2CTxFIFOConfigSet                                                \
        ROM_I2CTxFIFOConfigSet
#else
#define MAP_I2CTxFIFOConfigSet                                                \
        I2CTxFIFOConfigSet
#endif
#ifdef ROM_I2CTxFIFOFlush
#define MAP_I2CTxFIFOFlush                                                    \
        ROM_I2CTxFIFOFlush
#else
#define MAP_I2CTxFIFOFlush                                                    \
        I2CTxFIFOFlush
#endif
#ifdef ROM_I2CRxFIFOConfigSet
#define MAP_I2CRxFIFOConfigSet                                                \
        ROM_I2CRxFIFOConfigSet
#else
#define MAP_I2CRxFIFOConfigSet                                                \
        I2CRxFIFOConfigSet
#endif
#ifdef ROM_I2CRxFIFOFlush
#define MAP_I2CRxFIFOFlush                                                    \
        ROM_I2CRxFIFOFlush
#else
#define MAP_I2CRxFIFOFlush                                                    \
        I2CRxFIFOFlush
#endif
#ifdef ROM_I2CFIFOStatus
#define MAP_I2CFIFOStatus                                                     \
        ROM_I2CFIFOStatus
#else
#define MAP_I2CFIFOStatus                                                     \
        I2CFIFOStatus
#endif
#ifdef ROM_I2CFIFODataPut
#define MAP_I2CFIFODataPut                                                    \
        ROM_I2CFIFODataPut
#else
#define MAP_I2CFIFODataPut                                                    \
        I2CFIFODataPut
#endif
#ifdef ROM_I2CFIFODataPutNonBlocking
#define MAP_I2CFIFODataPutNonBlocking                                         \
        ROM_I2CFIFODataPutNonBlocking
#else
#define MAP_I2CFIFODataPutNonBlocking                                         \
        I2CFIFODataPutNonBlocking
#endif
#ifdef ROM_I2CFIFODataGet
#define MAP_I2CFIFODataGet                                                    \
        ROM_I2CFIFODataGet
#else
#define MAP_I2CFIFODataGet                                                    \
        I2CFIFODataGet
#endif
#ifdef ROM_I2CFIFODataGetNonBlocking
#define MAP_I2CFIFODataGetNonBlocking                                         \
        ROM_I2CFIFODataGetNonBlocking
#else
#define MAP_I2CFIFODataGetNonBlocking                                         \
        I2CFIFODataGetNonBlocking
#endif
#ifdef ROM_I2CMasterBurstLengthSet
#define MAP_I2CMasterBurstLengthSet                                           \
        ROM_I2CMasterBurstLengthSet
#else
#define MAP_I2CMasterBurstLengthSet                                           \
        I2CMasterBurstLengthSet
#endif
#ifdef ROM_I2CMasterBurstCountGet
#define MAP_I2CMasterBurstCountGet                                            \
        ROM_I2CMasterBurstCountGet
#else
#define MAP_I2CMasterBurstCountGet                                            \
        I2CMasterBurstCountGet
#endif
#ifdef ROM_I2CMasterGlitchFilterConfigSet
#define MAP_I2CMasterGlitchFilterConfigSet                                    \
        ROM_I2CMasterGlitchFilterConfigSet
#else
#define MAP_I2CMasterGlitchFilterConfigSet                                    \
        I2CMasterGlitchFilterConfigSet
#endif

//*****************************************************************************
//
// Macros for the Interrupt API.
//
//*****************************************************************************
#ifdef ROM_IntEnable
#define MAP_IntEnable                                                         \
        ROM_IntEnable
#else
#define MAP_IntEnable                                                         \
        IntEnable
#endif
#ifdef ROM_IntMasterEnable
#define MAP_IntMasterEnable                                                   \
        ROM_IntMasterEnable
#else
#define MAP_IntMasterEnable                                                   \
        IntMasterEnable
#endif
#ifdef ROM_IntMasterDisable
#define MAP_IntMasterDisable                                                  \
        ROM_IntMasterDisable
#else
#define MAP_IntMasterDisable                                                  \
        IntMasterDisable
#endif
#ifdef ROM_IntDisable
#define MAP_IntDisable                                                        \
        ROM_IntDisable
#else
#define MAP_IntDisable                                                        \
        IntDisable
#endif
#ifdef ROM_IntPriorityGroupingSet
#define MAP_IntPriorityGroupingSet                                            \
        ROM_IntPriorityGroupingSet
#else
#define MAP_IntPriorityGroupingSet                                            \
        IntPriorityGroupingSet
#endif
#ifdef ROM_IntPriorityGroupingGet
#define MAP_IntPriorityGroupingGet                                            \
        ROM_IntPriorityGroupingGet
#else
#define MAP_IntPriorityGroupingGet                                            \
        IntPriorityGroupingGet
#endif
#ifdef ROM_IntPrioritySet
#define MAP_IntPrioritySet                                                    \
        ROM_IntPrioritySet
#else
#define MAP_IntPrioritySet                                                    \
        IntPrioritySet
#endif
#ifdef ROM_IntPriorityGet
#define MAP_IntPriorityGet                                                    \
        ROM_IntPriorityGet
#else
#define MAP_IntPriorityGet                                                    \
        IntPriorityGet
#endif
#ifdef ROM_IntPendSet
#define MAP_IntPendSet                                                        \
        ROM_IntPendSet
#else
#define MAP_IntPendSet                                                        \
        IntPendSet
#endif
#ifdef ROM_IntPendClear
#define MAP_IntPendClear                                                      \
        ROM_IntPendClear
#else
#define MAP_IntPendClear                                                      \
        IntPendClear
#endif
#ifdef ROM_IntPriorityMaskSet
#define MAP_IntPriorityMaskSet                                                \
        ROM_IntPriorityMaskSet
#else
#define MAP_IntPriorityMaskSet                                                \
        IntPriorityMaskSet
#endif
#ifdef ROM_IntPriorityMaskGet
#define MAP_IntPriorityMaskGet                                                \
        ROM_IntPriorityMaskGet
#else
#define MAP_IntPriorityMaskGet                                                \
        IntPriorityMaskGet
#endif
#ifdef ROM_IntIsEnabled
#define MAP_IntIsEnabled                                                      \
        ROM_IntIsEnabled
#else
#define MAP_IntIsEnabled                                                      \
        IntIsEnabled
#endif

//*****************************************************************************
//
// Macros for the KBScan API.
//
//*****************************************************************************
#ifdef ROM_KBScanIntStatus
#define MAP_KBScanIntStatus                                                   \
        ROM_KBScanIntStatus
#else
#define MAP_KBScanIntStatus                                                   \
        KBScanIntStatus
#endif
#ifdef ROM_KBScanConfigGet
#define MAP_KBScanConfigGet                                                   \
        ROM_KBScanConfigGet
#else
#define MAP_KBScanConfigGet                                                   \
        KBScanConfigGet
#endif
#ifdef ROM_KBScanConfigSet
#define MAP_KBScanConfigSet                                                   \
        ROM_KBScanConfigSet
#else
#define MAP_KBScanConfigSet                                                   \
        KBScanConfigSet
#endif
#ifdef ROM_KBScanDisable
#define MAP_KBScanDisable                                                     \
        ROM_KBScanDisable
#else
#define MAP_KBScanDisable                                                     \
        KBScanDisable
#endif
#ifdef ROM_KBScanEnable
#define MAP_KBScanEnable                                                      \
        ROM_KBScanEnable
#else
#define MAP_KBScanEnable                                                      \
        KBScanEnable
#endif
#ifdef ROM_KBScanIntClear
#define MAP_KBScanIntClear                                                    \
        ROM_KBScanIntClear
#else
#define MAP_KBScanIntClear                                                    \
        KBScanIntClear
#endif
#ifdef ROM_KBScanIntDisable
#define MAP_KBScanIntDisable                                                  \
        ROM_KBScanIntDisable
#else
#define MAP_KBScanIntDisable                                                  \
        KBScanIntDisable
#endif
#ifdef ROM_KBScanIntEnable
#define MAP_KBScanIntEnable                                                   \
        ROM_KBScanIntEnable
#else
#define MAP_KBScanIntEnable                                                   \
        KBScanIntEnable
#endif
#ifdef ROM_KBScanStatusGet
#define MAP_KBScanStatusGet                                                   \
        ROM_KBScanStatusGet
#else
#define MAP_KBScanStatusGet                                                   \
        KBScanStatusGet
#endif
#ifdef ROM_KBScanTrigger
#define MAP_KBScanTrigger                                                     \
        ROM_KBScanTrigger
#else
#define MAP_KBScanTrigger                                                     \
        KBScanTrigger
#endif

//*****************************************************************************
//
// Macros for the LCD API.
//
//*****************************************************************************
#ifdef ROM_LCDIntStatus
#define MAP_LCDIntStatus                                                      \
        ROM_LCDIntStatus
#else
#define MAP_LCDIntStatus                                                      \
        LCDIntStatus
#endif
#ifdef ROM_LCDClockReset
#define MAP_LCDClockReset                                                     \
        ROM_LCDClockReset
#else
#define MAP_LCDClockReset                                                     \
        LCDClockReset
#endif
#ifdef ROM_LCDDMAConfigSet
#define MAP_LCDDMAConfigSet                                                   \
        ROM_LCDDMAConfigSet
#else
#define MAP_LCDDMAConfigSet                                                   \
        LCDDMAConfigSet
#endif
#ifdef ROM_LCDIDDCommandWrite
#define MAP_LCDIDDCommandWrite                                                \
        ROM_LCDIDDCommandWrite
#else
#define MAP_LCDIDDCommandWrite                                                \
        LCDIDDCommandWrite
#endif
#ifdef ROM_LCDIDDConfigSet
#define MAP_LCDIDDConfigSet                                                   \
        ROM_LCDIDDConfigSet
#else
#define MAP_LCDIDDConfigSet                                                   \
        LCDIDDConfigSet
#endif
#ifdef ROM_LCDIDDDataRead
#define MAP_LCDIDDDataRead                                                    \
        ROM_LCDIDDDataRead
#else
#define MAP_LCDIDDDataRead                                                    \
        LCDIDDDataRead
#endif
#ifdef ROM_LCDIDDDataWrite
#define MAP_LCDIDDDataWrite                                                   \
        ROM_LCDIDDDataWrite
#else
#define MAP_LCDIDDDataWrite                                                   \
        LCDIDDDataWrite
#endif
#ifdef ROM_LCDIDDDMADisable
#define MAP_LCDIDDDMADisable                                                  \
        ROM_LCDIDDDMADisable
#else
#define MAP_LCDIDDDMADisable                                                  \
        LCDIDDDMADisable
#endif
#ifdef ROM_LCDIDDDMAWrite
#define MAP_LCDIDDDMAWrite                                                    \
        ROM_LCDIDDDMAWrite
#else
#define MAP_LCDIDDDMAWrite                                                    \
        LCDIDDDMAWrite
#endif
#ifdef ROM_LCDIDDIndexedRead
#define MAP_LCDIDDIndexedRead                                                 \
        ROM_LCDIDDIndexedRead
#else
#define MAP_LCDIDDIndexedRead                                                 \
        LCDIDDIndexedRead
#endif
#ifdef ROM_LCDIDDIndexedWrite
#define MAP_LCDIDDIndexedWrite                                                \
        ROM_LCDIDDIndexedWrite
#else
#define MAP_LCDIDDIndexedWrite                                                \
        LCDIDDIndexedWrite
#endif
#ifdef ROM_LCDIDDStatusRead
#define MAP_LCDIDDStatusRead                                                  \
        ROM_LCDIDDStatusRead
#else
#define MAP_LCDIDDStatusRead                                                  \
        LCDIDDStatusRead
#endif
#ifdef ROM_LCDIDDTimingSet
#define MAP_LCDIDDTimingSet                                                   \
        ROM_LCDIDDTimingSet
#else
#define MAP_LCDIDDTimingSet                                                   \
        LCDIDDTimingSet
#endif
#ifdef ROM_LCDIntClear
#define MAP_LCDIntClear                                                       \
        ROM_LCDIntClear
#else
#define MAP_LCDIntClear                                                       \
        LCDIntClear
#endif
#ifdef ROM_LCDIntDisable
#define MAP_LCDIntDisable                                                     \
        ROM_LCDIntDisable
#else
#define MAP_LCDIntDisable                                                     \
        LCDIntDisable
#endif
#ifdef ROM_LCDIntEnable
#define MAP_LCDIntEnable                                                      \
        ROM_LCDIntEnable
#else
#define MAP_LCDIntEnable                                                      \
        LCDIntEnable
#endif
#ifdef ROM_LCDModeSet
#define MAP_LCDModeSet                                                        \
        ROM_LCDModeSet
#else
#define MAP_LCDModeSet                                                        \
        LCDModeSet
#endif
#ifdef ROM_LCDRasterACBiasIntCountSet
#define MAP_LCDRasterACBiasIntCountSet                                        \
        ROM_LCDRasterACBiasIntCountSet
#else
#define MAP_LCDRasterACBiasIntCountSet                                        \
        LCDRasterACBiasIntCountSet
#endif
#ifdef ROM_LCDRasterConfigSet
#define MAP_LCDRasterConfigSet                                                \
        ROM_LCDRasterConfigSet
#else
#define MAP_LCDRasterConfigSet                                                \
        LCDRasterConfigSet
#endif
#ifdef ROM_LCDRasterDisable
#define MAP_LCDRasterDisable                                                  \
        ROM_LCDRasterDisable
#else
#define MAP_LCDRasterDisable                                                  \
        LCDRasterDisable
#endif
#ifdef ROM_LCDRasterEnable
#define MAP_LCDRasterEnable                                                   \
        ROM_LCDRasterEnable
#else
#define MAP_LCDRasterEnable                                                   \
        LCDRasterEnable
#endif
#ifdef ROM_LCDRasterFrameBufferSet
#define MAP_LCDRasterFrameBufferSet                                           \
        ROM_LCDRasterFrameBufferSet
#else
#define MAP_LCDRasterFrameBufferSet                                           \
        LCDRasterFrameBufferSet
#endif
#ifdef ROM_LCDRasterPaletteSet
#define MAP_LCDRasterPaletteSet                                               \
        ROM_LCDRasterPaletteSet
#else
#define MAP_LCDRasterPaletteSet                                               \
        LCDRasterPaletteSet
#endif
#ifdef ROM_LCDRasterSubPanelConfigSet
#define MAP_LCDRasterSubPanelConfigSet                                        \
        ROM_LCDRasterSubPanelConfigSet
#else
#define MAP_LCDRasterSubPanelConfigSet                                        \
        LCDRasterSubPanelConfigSet
#endif
#ifdef ROM_LCDRasterSubPanelDisable
#define MAP_LCDRasterSubPanelDisable                                          \
        ROM_LCDRasterSubPanelDisable
#else
#define MAP_LCDRasterSubPanelDisable                                          \
        LCDRasterSubPanelDisable
#endif
#ifdef ROM_LCDRasterSubPanelEnable
#define MAP_LCDRasterSubPanelEnable                                           \
        ROM_LCDRasterSubPanelEnable
#else
#define MAP_LCDRasterSubPanelEnable                                           \
        LCDRasterSubPanelEnable
#endif
#ifdef ROM_LCDRasterTimingSet
#define MAP_LCDRasterTimingSet                                                \
        ROM_LCDRasterTimingSet
#else
#define MAP_LCDRasterTimingSet                                                \
        LCDRasterTimingSet
#endif

//*****************************************************************************
//
// Macros for the LEDSeq API.
//
//*****************************************************************************
#ifdef ROM_LEDSeqIntStatus
#define MAP_LEDSeqIntStatus                                                   \
        ROM_LEDSeqIntStatus
#else
#define MAP_LEDSeqIntStatus                                                   \
        LEDSeqIntStatus
#endif
#ifdef ROM_LEDSeqConfigGet
#define MAP_LEDSeqConfigGet                                                   \
        ROM_LEDSeqConfigGet
#else
#define MAP_LEDSeqConfigGet                                                   \
        LEDSeqConfigGet
#endif
#ifdef ROM_LEDSeqConfigSet
#define MAP_LEDSeqConfigSet                                                   \
        ROM_LEDSeqConfigSet
#else
#define MAP_LEDSeqConfigSet                                                   \
        LEDSeqConfigSet
#endif
#ifdef ROM_LEDSeqDisable
#define MAP_LEDSeqDisable                                                     \
        ROM_LEDSeqDisable
#else
#define MAP_LEDSeqDisable                                                     \
        LEDSeqDisable
#endif
#ifdef ROM_LEDSeqEnable
#define MAP_LEDSeqEnable                                                      \
        ROM_LEDSeqEnable
#else
#define MAP_LEDSeqEnable                                                      \
        LEDSeqEnable
#endif
#ifdef ROM_LEDSeqIntClear
#define MAP_LEDSeqIntClear                                                    \
        ROM_LEDSeqIntClear
#else
#define MAP_LEDSeqIntClear                                                    \
        LEDSeqIntClear
#endif
#ifdef ROM_LEDSeqIntDisable
#define MAP_LEDSeqIntDisable                                                  \
        ROM_LEDSeqIntDisable
#else
#define MAP_LEDSeqIntDisable                                                  \
        LEDSeqIntDisable
#endif
#ifdef ROM_LEDSeqIntEnable
#define MAP_LEDSeqIntEnable                                                   \
        ROM_LEDSeqIntEnable
#else
#define MAP_LEDSeqIntEnable                                                   \
        LEDSeqIntEnable
#endif
#ifdef ROM_LEDSeqSequenceGet
#define MAP_LEDSeqSequenceGet                                                 \
        ROM_LEDSeqSequenceGet
#else
#define MAP_LEDSeqSequenceGet                                                 \
        LEDSeqSequenceGet
#endif
#ifdef ROM_LEDSeqSequenceSet
#define MAP_LEDSeqSequenceSet                                                 \
        ROM_LEDSeqSequenceSet
#else
#define MAP_LEDSeqSequenceSet                                                 \
        LEDSeqSequenceSet
#endif

//*****************************************************************************
//
// Macros for the LPC API.
//
//*****************************************************************************
#ifdef ROM_LPCIntClear
#define MAP_LPCIntClear                                                       \
        ROM_LPCIntClear
#else
#define MAP_LPCIntClear                                                       \
        LPCIntClear
#endif
#ifdef ROM_LPCByteRead
#define MAP_LPCByteRead                                                       \
        ROM_LPCByteRead
#else
#define MAP_LPCByteRead                                                       \
        LPCByteRead
#endif
#ifdef ROM_LPCByteWrite
#define MAP_LPCByteWrite                                                      \
        ROM_LPCByteWrite
#else
#define MAP_LPCByteWrite                                                      \
        LPCByteWrite
#endif
#ifdef ROM_LPCChannelConfigCOMxSet
#define MAP_LPCChannelConfigCOMxSet                                           \
        ROM_LPCChannelConfigCOMxSet
#else
#define MAP_LPCChannelConfigCOMxSet                                           \
        LPCChannelConfigCOMxSet
#endif
#ifdef ROM_LPCChannelConfigGet
#define MAP_LPCChannelConfigGet                                               \
        ROM_LPCChannelConfigGet
#else
#define MAP_LPCChannelConfigGet                                               \
        LPCChannelConfigGet
#endif
#ifdef ROM_LPCChannelConfigEPSet
#define MAP_LPCChannelConfigEPSet                                             \
        ROM_LPCChannelConfigEPSet
#else
#define MAP_LPCChannelConfigEPSet                                             \
        LPCChannelConfigEPSet
#endif
#ifdef ROM_LPCChannelConfigMBSet
#define MAP_LPCChannelConfigMBSet                                             \
        ROM_LPCChannelConfigMBSet
#else
#define MAP_LPCChannelConfigMBSet                                             \
        LPCChannelConfigMBSet
#endif
#ifdef ROM_LPCChannelDMAConfigGet
#define MAP_LPCChannelDMAConfigGet                                            \
        ROM_LPCChannelDMAConfigGet
#else
#define MAP_LPCChannelDMAConfigGet                                            \
        LPCChannelDMAConfigGet
#endif
#ifdef ROM_LPCChannelDMAConfigSet
#define MAP_LPCChannelDMAConfigSet                                            \
        ROM_LPCChannelDMAConfigSet
#else
#define MAP_LPCChannelDMAConfigSet                                            \
        LPCChannelDMAConfigSet
#endif
#ifdef ROM_LPCChannelDisable
#define MAP_LPCChannelDisable                                                 \
        ROM_LPCChannelDisable
#else
#define MAP_LPCChannelDisable                                                 \
        LPCChannelDisable
#endif
#ifdef ROM_LPCChannelEnable
#define MAP_LPCChannelEnable                                                  \
        ROM_LPCChannelEnable
#else
#define MAP_LPCChannelEnable                                                  \
        LPCChannelEnable
#endif
#ifdef ROM_LPCChannelStatusClear
#define MAP_LPCChannelStatusClear                                             \
        ROM_LPCChannelStatusClear
#else
#define MAP_LPCChannelStatusClear                                             \
        LPCChannelStatusClear
#endif
#ifdef ROM_LPCChannelStatusGet
#define MAP_LPCChannelStatusGet                                               \
        ROM_LPCChannelStatusGet
#else
#define MAP_LPCChannelStatusGet                                               \
        LPCChannelStatusGet
#endif
#ifdef ROM_LPCChannelStatusSet
#define MAP_LPCChannelStatusSet                                               \
        ROM_LPCChannelStatusSet
#else
#define MAP_LPCChannelStatusSet                                               \
        LPCChannelStatusSet
#endif
#ifdef ROM_LPCCOMxIntClear
#define MAP_LPCCOMxIntClear                                                   \
        ROM_LPCCOMxIntClear
#else
#define MAP_LPCCOMxIntClear                                                   \
        LPCCOMxIntClear
#endif
#ifdef ROM_LPCCOMxIntDisable
#define MAP_LPCCOMxIntDisable                                                 \
        ROM_LPCCOMxIntDisable
#else
#define MAP_LPCCOMxIntDisable                                                 \
        LPCCOMxIntDisable
#endif
#ifdef ROM_LPCCOMxIntEnable
#define MAP_LPCCOMxIntEnable                                                  \
        ROM_LPCCOMxIntEnable
#else
#define MAP_LPCCOMxIntEnable                                                  \
        LPCCOMxIntEnable
#endif
#ifdef ROM_LPCCOMxIntStatus
#define MAP_LPCCOMxIntStatus                                                  \
        ROM_LPCCOMxIntStatus
#else
#define MAP_LPCCOMxIntStatus                                                  \
        LPCCOMxIntStatus
#endif
#ifdef ROM_LPCConfigGet
#define MAP_LPCConfigGet                                                      \
        ROM_LPCConfigGet
#else
#define MAP_LPCConfigGet                                                      \
        LPCConfigGet
#endif
#ifdef ROM_LPCConfigSet
#define MAP_LPCConfigSet                                                      \
        ROM_LPCConfigSet
#else
#define MAP_LPCConfigSet                                                      \
        LPCConfigSet
#endif
#ifdef ROM_LPCHalfWordRead
#define MAP_LPCHalfWordRead                                                   \
        ROM_LPCHalfWordRead
#else
#define MAP_LPCHalfWordRead                                                   \
        LPCHalfWordRead
#endif
#ifdef ROM_LPCHalfWordWrite
#define MAP_LPCHalfWordWrite                                                  \
        ROM_LPCHalfWordWrite
#else
#define MAP_LPCHalfWordWrite                                                  \
        LPCHalfWordWrite
#endif
#ifdef ROM_LPCIRQClear
#define MAP_LPCIRQClear                                                       \
        ROM_LPCIRQClear
#else
#define MAP_LPCIRQClear                                                       \
        LPCIRQClear
#endif
#ifdef ROM_LPCIRQConfig
#define MAP_LPCIRQConfig                                                      \
        ROM_LPCIRQConfig
#else
#define MAP_LPCIRQConfig                                                      \
        LPCIRQConfig
#endif
#ifdef ROM_LPCIRQGet
#define MAP_LPCIRQGet                                                         \
        ROM_LPCIRQGet
#else
#define MAP_LPCIRQGet                                                         \
        LPCIRQGet
#endif
#ifdef ROM_LPCIRQSend
#define MAP_LPCIRQSend                                                        \
        ROM_LPCIRQSend
#else
#define MAP_LPCIRQSend                                                        \
        LPCIRQSend
#endif
#ifdef ROM_LPCIRQSet
#define MAP_LPCIRQSet                                                         \
        ROM_LPCIRQSet
#else
#define MAP_LPCIRQSet                                                         \
        LPCIRQSet
#endif
#ifdef ROM_LPCIntDisable
#define MAP_LPCIntDisable                                                     \
        ROM_LPCIntDisable
#else
#define MAP_LPCIntDisable                                                     \
        LPCIntDisable
#endif
#ifdef ROM_LPCIntEnable
#define MAP_LPCIntEnable                                                      \
        ROM_LPCIntEnable
#else
#define MAP_LPCIntEnable                                                      \
        LPCIntEnable
#endif
#ifdef ROM_LPCIntStatus
#define MAP_LPCIntStatus                                                      \
        ROM_LPCIntStatus
#else
#define MAP_LPCIntStatus                                                      \
        LPCIntStatus
#endif
#ifdef ROM_LPCSCIAssert
#define MAP_LPCSCIAssert                                                      \
        ROM_LPCSCIAssert
#else
#define MAP_LPCSCIAssert                                                      \
        LPCSCIAssert
#endif
#ifdef ROM_LPCStatusGet
#define MAP_LPCStatusGet                                                      \
        ROM_LPCStatusGet
#else
#define MAP_LPCStatusGet                                                      \
        LPCStatusGet
#endif
#ifdef ROM_LPCWordRead
#define MAP_LPCWordRead                                                       \
        ROM_LPCWordRead
#else
#define MAP_LPCWordRead                                                       \
        LPCWordRead
#endif
#ifdef ROM_LPCWordWrite
#define MAP_LPCWordWrite                                                      \
        ROM_LPCWordWrite
#else
#define MAP_LPCWordWrite                                                      \
        LPCWordWrite
#endif
#ifdef ROM_LPCChannelPoolAddressGet
#define MAP_LPCChannelPoolAddressGet                                          \
        ROM_LPCChannelPoolAddressGet
#else
#define MAP_LPCChannelPoolAddressGet                                          \
        LPCChannelPoolAddressGet
#endif
#ifdef ROM_LPCStatusBlockAddressGet
#define MAP_LPCStatusBlockAddressGet                                          \
        ROM_LPCStatusBlockAddressGet
#else
#define MAP_LPCStatusBlockAddressGet                                          \
        LPCStatusBlockAddressGet
#endif
#ifdef ROM_LPCStatusBlockAddressSet
#define MAP_LPCStatusBlockAddressSet                                          \
        ROM_LPCStatusBlockAddressSet
#else
#define MAP_LPCStatusBlockAddressSet                                          \
        LPCStatusBlockAddressSet
#endif

//*****************************************************************************
//
// Macros for the LPCB API.
//
//*****************************************************************************
#ifdef ROM_LPCBIntClear
#define MAP_LPCBIntClear                                                      \
        ROM_LPCBIntClear
#else
#define MAP_LPCBIntClear                                                      \
        LPCBIntClear
#endif
#ifdef ROM_LPCBByteRead
#define MAP_LPCBByteRead                                                      \
        ROM_LPCBByteRead
#else
#define MAP_LPCBByteRead                                                      \
        LPCBByteRead
#endif
#ifdef ROM_LPCBByteWrite
#define MAP_LPCBByteWrite                                                     \
        ROM_LPCBByteWrite
#else
#define MAP_LPCBByteWrite                                                     \
        LPCBByteWrite
#endif
#ifdef ROM_LPCBChannelConfigCOMxSet
#define MAP_LPCBChannelConfigCOMxSet                                          \
        ROM_LPCBChannelConfigCOMxSet
#else
#define MAP_LPCBChannelConfigCOMxSet                                          \
        LPCBChannelConfigCOMxSet
#endif
#ifdef ROM_LPCBChannelConfigGet
#define MAP_LPCBChannelConfigGet                                              \
        ROM_LPCBChannelConfigGet
#else
#define MAP_LPCBChannelConfigGet                                              \
        LPCBChannelConfigGet
#endif
#ifdef ROM_LPCBChannelConfigEPSet
#define MAP_LPCBChannelConfigEPSet                                            \
        ROM_LPCBChannelConfigEPSet
#else
#define MAP_LPCBChannelConfigEPSet                                            \
        LPCBChannelConfigEPSet
#endif
#ifdef ROM_LPCBChannelConfigMBSet
#define MAP_LPCBChannelConfigMBSet                                            \
        ROM_LPCBChannelConfigMBSet
#else
#define MAP_LPCBChannelConfigMBSet                                            \
        LPCBChannelConfigMBSet
#endif
#ifdef ROM_LPCBChannelDMAConfigGet
#define MAP_LPCBChannelDMAConfigGet                                           \
        ROM_LPCBChannelDMAConfigGet
#else
#define MAP_LPCBChannelDMAConfigGet                                           \
        LPCBChannelDMAConfigGet
#endif
#ifdef ROM_LPCBChannelDMAConfigSet
#define MAP_LPCBChannelDMAConfigSet                                           \
        ROM_LPCBChannelDMAConfigSet
#else
#define MAP_LPCBChannelDMAConfigSet                                           \
        LPCBChannelDMAConfigSet
#endif
#ifdef ROM_LPCBChannelDisable
#define MAP_LPCBChannelDisable                                                \
        ROM_LPCBChannelDisable
#else
#define MAP_LPCBChannelDisable                                                \
        LPCBChannelDisable
#endif
#ifdef ROM_LPCBChannelEnable
#define MAP_LPCBChannelEnable                                                 \
        ROM_LPCBChannelEnable
#else
#define MAP_LPCBChannelEnable                                                 \
        LPCBChannelEnable
#endif
#ifdef ROM_LPCBChannelStatusClear
#define MAP_LPCBChannelStatusClear                                            \
        ROM_LPCBChannelStatusClear
#else
#define MAP_LPCBChannelStatusClear                                            \
        LPCBChannelStatusClear
#endif
#ifdef ROM_LPCBChannelStatusGet
#define MAP_LPCBChannelStatusGet                                              \
        ROM_LPCBChannelStatusGet
#else
#define MAP_LPCBChannelStatusGet                                              \
        LPCBChannelStatusGet
#endif
#ifdef ROM_LPCBChannelStatusSet
#define MAP_LPCBChannelStatusSet                                              \
        ROM_LPCBChannelStatusSet
#else
#define MAP_LPCBChannelStatusSet                                              \
        LPCBChannelStatusSet
#endif
#ifdef ROM_LPCBConfigGet
#define MAP_LPCBConfigGet                                                     \
        ROM_LPCBConfigGet
#else
#define MAP_LPCBConfigGet                                                     \
        LPCBConfigGet
#endif
#ifdef ROM_LPCBConfigSet
#define MAP_LPCBConfigSet                                                     \
        ROM_LPCBConfigSet
#else
#define MAP_LPCBConfigSet                                                     \
        LPCBConfigSet
#endif
#ifdef ROM_LPCBHalfWordRead
#define MAP_LPCBHalfWordRead                                                  \
        ROM_LPCBHalfWordRead
#else
#define MAP_LPCBHalfWordRead                                                  \
        LPCBHalfWordRead
#endif
#ifdef ROM_LPCBHalfWordWrite
#define MAP_LPCBHalfWordWrite                                                 \
        ROM_LPCBHalfWordWrite
#else
#define MAP_LPCBHalfWordWrite                                                 \
        LPCBHalfWordWrite
#endif
#ifdef ROM_LPCBIRQClear
#define MAP_LPCBIRQClear                                                      \
        ROM_LPCBIRQClear
#else
#define MAP_LPCBIRQClear                                                      \
        LPCBIRQClear
#endif
#ifdef ROM_LPCBIRQConfig
#define MAP_LPCBIRQConfig                                                     \
        ROM_LPCBIRQConfig
#else
#define MAP_LPCBIRQConfig                                                     \
        LPCBIRQConfig
#endif
#ifdef ROM_LPCBIRQGet
#define MAP_LPCBIRQGet                                                        \
        ROM_LPCBIRQGet
#else
#define MAP_LPCBIRQGet                                                        \
        LPCBIRQGet
#endif
#ifdef ROM_LPCBIRQSend
#define MAP_LPCBIRQSend                                                       \
        ROM_LPCBIRQSend
#else
#define MAP_LPCBIRQSend                                                       \
        LPCBIRQSend
#endif
#ifdef ROM_LPCBIRQSet
#define MAP_LPCBIRQSet                                                        \
        ROM_LPCBIRQSet
#else
#define MAP_LPCBIRQSet                                                        \
        LPCBIRQSet
#endif
#ifdef ROM_LPCBIntDisable
#define MAP_LPCBIntDisable                                                    \
        ROM_LPCBIntDisable
#else
#define MAP_LPCBIntDisable                                                    \
        LPCBIntDisable
#endif
#ifdef ROM_LPCBIntEnable
#define MAP_LPCBIntEnable                                                     \
        ROM_LPCBIntEnable
#else
#define MAP_LPCBIntEnable                                                     \
        LPCBIntEnable
#endif
#ifdef ROM_LPCBIntStatus
#define MAP_LPCBIntStatus                                                     \
        ROM_LPCBIntStatus
#else
#define MAP_LPCBIntStatus                                                     \
        LPCBIntStatus
#endif
#ifdef ROM_LPCBSCIAssert
#define MAP_LPCBSCIAssert                                                     \
        ROM_LPCBSCIAssert
#else
#define MAP_LPCBSCIAssert                                                     \
        LPCBSCIAssert
#endif
#ifdef ROM_LPCBStatusGet
#define MAP_LPCBStatusGet                                                     \
        ROM_LPCBStatusGet
#else
#define MAP_LPCBStatusGet                                                     \
        LPCBStatusGet
#endif
#ifdef ROM_LPCBWordRead
#define MAP_LPCBWordRead                                                      \
        ROM_LPCBWordRead
#else
#define MAP_LPCBWordRead                                                      \
        LPCBWordRead
#endif
#ifdef ROM_LPCBWordWrite
#define MAP_LPCBWordWrite                                                     \
        ROM_LPCBWordWrite
#else
#define MAP_LPCBWordWrite                                                     \
        LPCBWordWrite
#endif
#ifdef ROM_LPCBChannelPoolAddressGet
#define MAP_LPCBChannelPoolAddressGet                                         \
        ROM_LPCBChannelPoolAddressGet
#else
#define MAP_LPCBChannelPoolAddressGet                                         \
        LPCBChannelPoolAddressGet
#endif
#ifdef ROM_LPCBStatusBlockAddressGet
#define MAP_LPCBStatusBlockAddressGet                                         \
        ROM_LPCBStatusBlockAddressGet
#else
#define MAP_LPCBStatusBlockAddressGet                                         \
        LPCBStatusBlockAddressGet
#endif
#ifdef ROM_LPCBStatusBlockAddressSet
#define MAP_LPCBStatusBlockAddressSet                                         \
        ROM_LPCBStatusBlockAddressSet
#else
#define MAP_LPCBStatusBlockAddressSet                                         \
        LPCBStatusBlockAddressSet
#endif
#ifdef ROM_LPCBChannelConfigCOMSet
#define MAP_LPCBChannelConfigCOMSet                                           \
        ROM_LPCBChannelConfigCOMSet
#else
#define MAP_LPCBChannelConfigCOMSet                                           \
        LPCBChannelConfigCOMSet
#endif
#ifdef ROM_LPCBChannelConfigCOMGet
#define MAP_LPCBChannelConfigCOMGet                                           \
        ROM_LPCBChannelConfigCOMGet
#else
#define MAP_LPCBChannelConfigCOMGet                                           \
        LPCBChannelConfigCOMGet
#endif
#ifdef ROM_LPCBCOMIntEnable
#define MAP_LPCBCOMIntEnable                                                  \
        ROM_LPCBCOMIntEnable
#else
#define MAP_LPCBCOMIntEnable                                                  \
        LPCBCOMIntEnable
#endif
#ifdef ROM_LPCBCOMIntDisable
#define MAP_LPCBCOMIntDisable                                                 \
        ROM_LPCBCOMIntDisable
#else
#define MAP_LPCBCOMIntDisable                                                 \
        LPCBCOMIntDisable
#endif
#ifdef ROM_LPCBCOMCTSSet
#define MAP_LPCBCOMCTSSet                                                     \
        ROM_LPCBCOMCTSSet
#else
#define MAP_LPCBCOMCTSSet                                                     \
        LPCBCOMCTSSet
#endif
#ifdef ROM_LPCBCOMDSRSet
#define MAP_LPCBCOMDSRSet                                                     \
        ROM_LPCBCOMDSRSet
#else
#define MAP_LPCBCOMDSRSet                                                     \
        LPCBCOMDSRSet
#endif
#ifdef ROM_LPCBCOMStatusGet
#define MAP_LPCBCOMStatusGet                                                  \
        ROM_LPCBCOMStatusGet
#else
#define MAP_LPCBCOMStatusGet                                                  \
        LPCBCOMStatusGet
#endif
#ifdef ROM_LPCBCOMInterceptRXFIFOWrite
#define MAP_LPCBCOMInterceptRXFIFOWrite                                       \
        ROM_LPCBCOMInterceptRXFIFOWrite
#else
#define MAP_LPCBCOMInterceptRXFIFOWrite                                       \
        LPCBCOMInterceptRXFIFOWrite
#endif
#ifdef ROM_LPCBCOMInterceptTXFIFORead
#define MAP_LPCBCOMInterceptTXFIFORead                                        \
        ROM_LPCBCOMInterceptTXFIFORead
#else
#define MAP_LPCBCOMInterceptTXFIFORead                                        \
        LPCBCOMInterceptTXFIFORead
#endif
#ifdef ROM_LPCBChannelStallClear
#define MAP_LPCBChannelStallClear                                             \
        ROM_LPCBChannelStallClear
#else
#define MAP_LPCBChannelStallClear                                             \
        LPCBChannelStallClear
#endif
#ifdef ROM_LPCBRTCAddressSet
#define MAP_LPCBRTCAddressSet                                                 \
        ROM_LPCBRTCAddressSet
#else
#define MAP_LPCBRTCAddressSet                                                 \
        LPCBRTCAddressSet
#endif

//*****************************************************************************
//
// Macros for the MPU API.
//
//*****************************************************************************
#ifdef ROM_MPUEnable
#define MAP_MPUEnable                                                         \
        ROM_MPUEnable
#else
#define MAP_MPUEnable                                                         \
        MPUEnable
#endif
#ifdef ROM_MPUDisable
#define MAP_MPUDisable                                                        \
        ROM_MPUDisable
#else
#define MAP_MPUDisable                                                        \
        MPUDisable
#endif
#ifdef ROM_MPURegionCountGet
#define MAP_MPURegionCountGet                                                 \
        ROM_MPURegionCountGet
#else
#define MAP_MPURegionCountGet                                                 \
        MPURegionCountGet
#endif
#ifdef ROM_MPURegionEnable
#define MAP_MPURegionEnable                                                   \
        ROM_MPURegionEnable
#else
#define MAP_MPURegionEnable                                                   \
        MPURegionEnable
#endif
#ifdef ROM_MPURegionDisable
#define MAP_MPURegionDisable                                                  \
        ROM_MPURegionDisable
#else
#define MAP_MPURegionDisable                                                  \
        MPURegionDisable
#endif
#ifdef ROM_MPURegionSet
#define MAP_MPURegionSet                                                      \
        ROM_MPURegionSet
#else
#define MAP_MPURegionSet                                                      \
        MPURegionSet
#endif
#ifdef ROM_MPURegionGet
#define MAP_MPURegionGet                                                      \
        ROM_MPURegionGet
#else
#define MAP_MPURegionGet                                                      \
        MPURegionGet
#endif

//*****************************************************************************
//
// Macros for the OneWire API.
//
//*****************************************************************************
#ifdef ROM_OneWireIntStatus
#define MAP_OneWireIntStatus                                                  \
        ROM_OneWireIntStatus
#else
#define MAP_OneWireIntStatus                                                  \
        OneWireIntStatus
#endif
#ifdef ROM_OneWireBusReset
#define MAP_OneWireBusReset                                                   \
        ROM_OneWireBusReset
#else
#define MAP_OneWireBusReset                                                   \
        OneWireBusReset
#endif
#ifdef ROM_OneWireBusStatus
#define MAP_OneWireBusStatus                                                  \
        ROM_OneWireBusStatus
#else
#define MAP_OneWireBusStatus                                                  \
        OneWireBusStatus
#endif
#ifdef ROM_OneWireDataGet
#define MAP_OneWireDataGet                                                    \
        ROM_OneWireDataGet
#else
#define MAP_OneWireDataGet                                                    \
        OneWireDataGet
#endif
#ifdef ROM_OneWireDataGetNonBlocking
#define MAP_OneWireDataGetNonBlocking                                         \
        ROM_OneWireDataGetNonBlocking
#else
#define MAP_OneWireDataGetNonBlocking                                         \
        OneWireDataGetNonBlocking
#endif
#ifdef ROM_OneWireInit
#define MAP_OneWireInit                                                       \
        ROM_OneWireInit
#else
#define MAP_OneWireInit                                                       \
        OneWireInit
#endif
#ifdef ROM_OneWireIntClear
#define MAP_OneWireIntClear                                                   \
        ROM_OneWireIntClear
#else
#define MAP_OneWireIntClear                                                   \
        OneWireIntClear
#endif
#ifdef ROM_OneWireIntDisable
#define MAP_OneWireIntDisable                                                 \
        ROM_OneWireIntDisable
#else
#define MAP_OneWireIntDisable                                                 \
        OneWireIntDisable
#endif
#ifdef ROM_OneWireIntEnable
#define MAP_OneWireIntEnable                                                  \
        ROM_OneWireIntEnable
#else
#define MAP_OneWireIntEnable                                                  \
        OneWireIntEnable
#endif
#ifdef ROM_OneWireTransaction
#define MAP_OneWireTransaction                                                \
        ROM_OneWireTransaction
#else
#define MAP_OneWireTransaction                                                \
        OneWireTransaction
#endif
#ifdef ROM_OneWireDMADisable
#define MAP_OneWireDMADisable                                                 \
        ROM_OneWireDMADisable
#else
#define MAP_OneWireDMADisable                                                 \
        OneWireDMADisable
#endif
#ifdef ROM_OneWireDMAEnable
#define MAP_OneWireDMAEnable                                                  \
        ROM_OneWireDMAEnable
#else
#define MAP_OneWireDMAEnable                                                  \
        OneWireDMAEnable
#endif

//*****************************************************************************
//
// Macros for the PECI API.
//
//*****************************************************************************
#ifdef ROM_PECIIntClear
#define MAP_PECIIntClear                                                      \
        ROM_PECIIntClear
#else
#define MAP_PECIIntClear                                                      \
        PECIIntClear
#endif
#ifdef ROM_PECIAdvCmdSend
#define MAP_PECIAdvCmdSend                                                    \
        ROM_PECIAdvCmdSend
#else
#define MAP_PECIAdvCmdSend                                                    \
        PECIAdvCmdSend
#endif
#ifdef ROM_PECIAdvCmdSendNonBlocking
#define MAP_PECIAdvCmdSendNonBlocking                                         \
        ROM_PECIAdvCmdSendNonBlocking
#else
#define MAP_PECIAdvCmdSendNonBlocking                                         \
        PECIAdvCmdSendNonBlocking
#endif
#ifdef ROM_PECIAdvCmdStatusGet
#define MAP_PECIAdvCmdStatusGet                                               \
        ROM_PECIAdvCmdStatusGet
#else
#define MAP_PECIAdvCmdStatusGet                                               \
        PECIAdvCmdStatusGet
#endif
#ifdef ROM_PECIConfigGet
#define MAP_PECIConfigGet                                                     \
        ROM_PECIConfigGet
#else
#define MAP_PECIConfigGet                                                     \
        PECIConfigGet
#endif
#ifdef ROM_PECIConfigSet
#define MAP_PECIConfigSet                                                     \
        ROM_PECIConfigSet
#else
#define MAP_PECIConfigSet                                                     \
        PECIConfigSet
#endif
#ifdef ROM_PECIDomainMaxReadClear
#define MAP_PECIDomainMaxReadClear                                            \
        ROM_PECIDomainMaxReadClear
#else
#define MAP_PECIDomainMaxReadClear                                            \
        PECIDomainMaxReadClear
#endif
#ifdef ROM_PECIDomainValueClear
#define MAP_PECIDomainValueClear                                              \
        ROM_PECIDomainValueClear
#else
#define MAP_PECIDomainValueClear                                              \
        PECIDomainValueClear
#endif
#ifdef ROM_PECIDomainConfigGet
#define MAP_PECIDomainConfigGet                                               \
        ROM_PECIDomainConfigGet
#else
#define MAP_PECIDomainConfigGet                                               \
        PECIDomainConfigGet
#endif
#ifdef ROM_PECIDomainConfigSet
#define MAP_PECIDomainConfigSet                                               \
        ROM_PECIDomainConfigSet
#else
#define MAP_PECIDomainConfigSet                                               \
        PECIDomainConfigSet
#endif
#ifdef ROM_PECIDomainDisable
#define MAP_PECIDomainDisable                                                 \
        ROM_PECIDomainDisable
#else
#define MAP_PECIDomainDisable                                                 \
        PECIDomainDisable
#endif
#ifdef ROM_PECIDomainEnable
#define MAP_PECIDomainEnable                                                  \
        ROM_PECIDomainEnable
#else
#define MAP_PECIDomainEnable                                                  \
        PECIDomainEnable
#endif
#ifdef ROM_PECIDomainMaxReadGet
#define MAP_PECIDomainMaxReadGet                                              \
        ROM_PECIDomainMaxReadGet
#else
#define MAP_PECIDomainMaxReadGet                                              \
        PECIDomainMaxReadGet
#endif
#ifdef ROM_PECIDomainValueGet
#define MAP_PECIDomainValueGet                                                \
        ROM_PECIDomainValueGet
#else
#define MAP_PECIDomainValueGet                                                \
        PECIDomainValueGet
#endif
#ifdef ROM_PECIIntDisable
#define MAP_PECIIntDisable                                                    \
        ROM_PECIIntDisable
#else
#define MAP_PECIIntDisable                                                    \
        PECIIntDisable
#endif
#ifdef ROM_PECIIntEnable
#define MAP_PECIIntEnable                                                     \
        ROM_PECIIntEnable
#else
#define MAP_PECIIntEnable                                                     \
        PECIIntEnable
#endif
#ifdef ROM_PECIIntStatus
#define MAP_PECIIntStatus                                                     \
        ROM_PECIIntStatus
#else
#define MAP_PECIIntStatus                                                     \
        PECIIntStatus
#endif
#ifdef ROM_PECIBypassEnable
#define MAP_PECIBypassEnable                                                  \
        ROM_PECIBypassEnable
#else
#define MAP_PECIBypassEnable                                                  \
        PECIBypassEnable
#endif
#ifdef ROM_PECIBypassDisable
#define MAP_PECIBypassDisable                                                 \
        ROM_PECIBypassDisable
#else
#define MAP_PECIBypassDisable                                                 \
        PECIBypassDisable
#endif
#ifdef ROM_PECIDomainAverageConfigSet
#define MAP_PECIDomainAverageConfigSet                                        \
        ROM_PECIDomainAverageConfigSet
#else
#define MAP_PECIDomainAverageConfigSet                                        \
        PECIDomainAverageConfigSet
#endif
#ifdef ROM_PECIDomainAverageGet
#define MAP_PECIDomainAverageGet                                              \
        ROM_PECIDomainAverageGet
#else
#define MAP_PECIDomainAverageGet                                              \
        PECIDomainAverageGet
#endif
#ifdef ROM_PECIDomainAverageConfigGet
#define MAP_PECIDomainAverageConfigGet                                        \
        ROM_PECIDomainAverageConfigGet
#else
#define MAP_PECIDomainAverageConfigGet                                        \
        PECIDomainAverageConfigGet
#endif
#ifdef ROM_PECIBaudGet
#define MAP_PECIBaudGet                                                       \
        ROM_PECIBaudGet
#else
#define MAP_PECIBaudGet                                                       \
        PECIBaudGet
#endif

//*****************************************************************************
//
// Macros for the Port80 API.
//
//*****************************************************************************
#ifdef ROM_Port80DataWrite
#define MAP_Port80DataWrite                                                   \
        ROM_Port80DataWrite
#else
#define MAP_Port80DataWrite                                                   \
        Port80DataWrite
#endif
#ifdef ROM_Port80Config
#define MAP_Port80Config                                                      \
        ROM_Port80Config
#else
#define MAP_Port80Config                                                      \
        Port80Config
#endif

//*****************************************************************************
//
// Macros for the PS2 API.
//
//*****************************************************************************
#ifdef ROM_PS2IntStatus
#define MAP_PS2IntStatus                                                      \
        ROM_PS2IntStatus
#else
#define MAP_PS2IntStatus                                                      \
        PS2IntStatus
#endif
#ifdef ROM_PS2CommandWrite
#define MAP_PS2CommandWrite                                                   \
        ROM_PS2CommandWrite
#else
#define MAP_PS2CommandWrite                                                   \
        PS2CommandWrite
#endif
#ifdef ROM_PS2ConfigGet
#define MAP_PS2ConfigGet                                                      \
        ROM_PS2ConfigGet
#else
#define MAP_PS2ConfigGet                                                      \
        PS2ConfigGet
#endif
#ifdef ROM_PS2ConfigSet
#define MAP_PS2ConfigSet                                                      \
        ROM_PS2ConfigSet
#else
#define MAP_PS2ConfigSet                                                      \
        PS2ConfigSet
#endif
#ifdef ROM_PS2DataRead
#define MAP_PS2DataRead                                                       \
        ROM_PS2DataRead
#else
#define MAP_PS2DataRead                                                       \
        PS2DataRead
#endif
#ifdef ROM_PS2Disable
#define MAP_PS2Disable                                                        \
        ROM_PS2Disable
#else
#define MAP_PS2Disable                                                        \
        PS2Disable
#endif
#ifdef ROM_PS2Enable
#define MAP_PS2Enable                                                         \
        ROM_PS2Enable
#else
#define MAP_PS2Enable                                                         \
        PS2Enable
#endif
#ifdef ROM_PS2InhibitClear
#define MAP_PS2InhibitClear                                                   \
        ROM_PS2InhibitClear
#else
#define MAP_PS2InhibitClear                                                   \
        PS2InhibitClear
#endif
#ifdef ROM_PS2InhibitSet
#define MAP_PS2InhibitSet                                                     \
        ROM_PS2InhibitSet
#else
#define MAP_PS2InhibitSet                                                     \
        PS2InhibitSet
#endif
#ifdef ROM_PS2IntClear
#define MAP_PS2IntClear                                                       \
        ROM_PS2IntClear
#else
#define MAP_PS2IntClear                                                       \
        PS2IntClear
#endif
#ifdef ROM_PS2IntDisable
#define MAP_PS2IntDisable                                                     \
        ROM_PS2IntDisable
#else
#define MAP_PS2IntDisable                                                     \
        PS2IntDisable
#endif
#ifdef ROM_PS2IntEnable
#define MAP_PS2IntEnable                                                      \
        ROM_PS2IntEnable
#else
#define MAP_PS2IntEnable                                                      \
        PS2IntEnable
#endif
#ifdef ROM_PS2StatusGet
#define MAP_PS2StatusGet                                                      \
        ROM_PS2StatusGet
#else
#define MAP_PS2StatusGet                                                      \
        PS2StatusGet
#endif

//*****************************************************************************
//
// Macros for the PWM API.
//
//*****************************************************************************
#ifdef ROM_PWMPulseWidthSet
#define MAP_PWMPulseWidthSet                                                  \
        ROM_PWMPulseWidthSet
#else
#define MAP_PWMPulseWidthSet                                                  \
        PWMPulseWidthSet
#endif
#ifdef ROM_PWMGenConfigure
#define MAP_PWMGenConfigure                                                   \
        ROM_PWMGenConfigure
#else
#define MAP_PWMGenConfigure                                                   \
        PWMGenConfigure
#endif
#ifdef ROM_PWMGenPeriodSet
#define MAP_PWMGenPeriodSet                                                   \
        ROM_PWMGenPeriodSet
#else
#define MAP_PWMGenPeriodSet                                                   \
        PWMGenPeriodSet
#endif
#ifdef ROM_PWMGenPeriodGet
#define MAP_PWMGenPeriodGet                                                   \
        ROM_PWMGenPeriodGet
#else
#define MAP_PWMGenPeriodGet                                                   \
        PWMGenPeriodGet
#endif
#ifdef ROM_PWMGenEnable
#define MAP_PWMGenEnable                                                      \
        ROM_PWMGenEnable
#else
#define MAP_PWMGenEnable                                                      \
        PWMGenEnable
#endif
#ifdef ROM_PWMGenDisable
#define MAP_PWMGenDisable                                                     \
        ROM_PWMGenDisable
#else
#define MAP_PWMGenDisable                                                     \
        PWMGenDisable
#endif
#ifdef ROM_PWMPulseWidthGet
#define MAP_PWMPulseWidthGet                                                  \
        ROM_PWMPulseWidthGet
#else
#define MAP_PWMPulseWidthGet                                                  \
        PWMPulseWidthGet
#endif
#ifdef ROM_PWMDeadBandEnable
#define MAP_PWMDeadBandEnable                                                 \
        ROM_PWMDeadBandEnable
#else
#define MAP_PWMDeadBandEnable                                                 \
        PWMDeadBandEnable
#endif
#ifdef ROM_PWMDeadBandDisable
#define MAP_PWMDeadBandDisable                                                \
        ROM_PWMDeadBandDisable
#else
#define MAP_PWMDeadBandDisable                                                \
        PWMDeadBandDisable
#endif
#ifdef ROM_PWMSyncUpdate
#define MAP_PWMSyncUpdate                                                     \
        ROM_PWMSyncUpdate
#else
#define MAP_PWMSyncUpdate                                                     \
        PWMSyncUpdate
#endif
#ifdef ROM_PWMSyncTimeBase
#define MAP_PWMSyncTimeBase                                                   \
        ROM_PWMSyncTimeBase
#else
#define MAP_PWMSyncTimeBase                                                   \
        PWMSyncTimeBase
#endif
#ifdef ROM_PWMOutputState
#define MAP_PWMOutputState                                                    \
        ROM_PWMOutputState
#else
#define MAP_PWMOutputState                                                    \
        PWMOutputState
#endif
#ifdef ROM_PWMOutputInvert
#define MAP_PWMOutputInvert                                                   \
        ROM_PWMOutputInvert
#else
#define MAP_PWMOutputInvert                                                   \
        PWMOutputInvert
#endif
#ifdef ROM_PWMOutputFault
#define MAP_PWMOutputFault                                                    \
        ROM_PWMOutputFault
#else
#define MAP_PWMOutputFault                                                    \
        PWMOutputFault
#endif
#ifdef ROM_PWMGenIntTrigEnable
#define MAP_PWMGenIntTrigEnable                                               \
        ROM_PWMGenIntTrigEnable
#else
#define MAP_PWMGenIntTrigEnable                                               \
        PWMGenIntTrigEnable
#endif
#ifdef ROM_PWMGenIntTrigDisable
#define MAP_PWMGenIntTrigDisable                                              \
        ROM_PWMGenIntTrigDisable
#else
#define MAP_PWMGenIntTrigDisable                                              \
        PWMGenIntTrigDisable
#endif
#ifdef ROM_PWMGenIntStatus
#define MAP_PWMGenIntStatus                                                   \
        ROM_PWMGenIntStatus
#else
#define MAP_PWMGenIntStatus                                                   \
        PWMGenIntStatus
#endif
#ifdef ROM_PWMGenIntClear
#define MAP_PWMGenIntClear                                                    \
        ROM_PWMGenIntClear
#else
#define MAP_PWMGenIntClear                                                    \
        PWMGenIntClear
#endif
#ifdef ROM_PWMIntEnable
#define MAP_PWMIntEnable                                                      \
        ROM_PWMIntEnable
#else
#define MAP_PWMIntEnable                                                      \
        PWMIntEnable
#endif
#ifdef ROM_PWMIntDisable
#define MAP_PWMIntDisable                                                     \
        ROM_PWMIntDisable
#else
#define MAP_PWMIntDisable                                                     \
        PWMIntDisable
#endif
#ifdef ROM_PWMFaultIntClear
#define MAP_PWMFaultIntClear                                                  \
        ROM_PWMFaultIntClear
#else
#define MAP_PWMFaultIntClear                                                  \
        PWMFaultIntClear
#endif
#ifdef ROM_PWMIntStatus
#define MAP_PWMIntStatus                                                      \
        ROM_PWMIntStatus
#else
#define MAP_PWMIntStatus                                                      \
        PWMIntStatus
#endif
#ifdef ROM_PWMOutputFaultLevel
#define MAP_PWMOutputFaultLevel                                               \
        ROM_PWMOutputFaultLevel
#else
#define MAP_PWMOutputFaultLevel                                               \
        PWMOutputFaultLevel
#endif
#ifdef ROM_PWMFaultIntClearExt
#define MAP_PWMFaultIntClearExt                                               \
        ROM_PWMFaultIntClearExt
#else
#define MAP_PWMFaultIntClearExt                                               \
        PWMFaultIntClearExt
#endif
#ifdef ROM_PWMGenFaultConfigure
#define MAP_PWMGenFaultConfigure                                              \
        ROM_PWMGenFaultConfigure
#else
#define MAP_PWMGenFaultConfigure                                              \
        PWMGenFaultConfigure
#endif
#ifdef ROM_PWMGenFaultTriggerSet
#define MAP_PWMGenFaultTriggerSet                                             \
        ROM_PWMGenFaultTriggerSet
#else
#define MAP_PWMGenFaultTriggerSet                                             \
        PWMGenFaultTriggerSet
#endif
#ifdef ROM_PWMGenFaultTriggerGet
#define MAP_PWMGenFaultTriggerGet                                             \
        ROM_PWMGenFaultTriggerGet
#else
#define MAP_PWMGenFaultTriggerGet                                             \
        PWMGenFaultTriggerGet
#endif
#ifdef ROM_PWMGenFaultStatus
#define MAP_PWMGenFaultStatus                                                 \
        ROM_PWMGenFaultStatus
#else
#define MAP_PWMGenFaultStatus                                                 \
        PWMGenFaultStatus
#endif
#ifdef ROM_PWMGenFaultClear
#define MAP_PWMGenFaultClear                                                  \
        ROM_PWMGenFaultClear
#else
#define MAP_PWMGenFaultClear                                                  \
        PWMGenFaultClear
#endif
#ifdef ROM_PWMClockSet
#define MAP_PWMClockSet                                                       \
        ROM_PWMClockSet
#else
#define MAP_PWMClockSet                                                       \
        PWMClockSet
#endif
#ifdef ROM_PWMClockGet
#define MAP_PWMClockGet                                                       \
        ROM_PWMClockGet
#else
#define MAP_PWMClockGet                                                       \
        PWMClockGet
#endif
#ifdef ROM_PWMOutputUpdateMode
#define MAP_PWMOutputUpdateMode                                               \
        ROM_PWMOutputUpdateMode
#else
#define MAP_PWMOutputUpdateMode                                               \
        PWMOutputUpdateMode
#endif

//*****************************************************************************
//
// Macros for the QEI API.
//
//*****************************************************************************
#ifdef ROM_QEIPositionGet
#define MAP_QEIPositionGet                                                    \
        ROM_QEIPositionGet
#else
#define MAP_QEIPositionGet                                                    \
        QEIPositionGet
#endif
#ifdef ROM_QEIEnable
#define MAP_QEIEnable                                                         \
        ROM_QEIEnable
#else
#define MAP_QEIEnable                                                         \
        QEIEnable
#endif
#ifdef ROM_QEIDisable
#define MAP_QEIDisable                                                        \
        ROM_QEIDisable
#else
#define MAP_QEIDisable                                                        \
        QEIDisable
#endif
#ifdef ROM_QEIConfigure
#define MAP_QEIConfigure                                                      \
        ROM_QEIConfigure
#else
#define MAP_QEIConfigure                                                      \
        QEIConfigure
#endif
#ifdef ROM_QEIPositionSet
#define MAP_QEIPositionSet                                                    \
        ROM_QEIPositionSet
#else
#define MAP_QEIPositionSet                                                    \
        QEIPositionSet
#endif
#ifdef ROM_QEIDirectionGet
#define MAP_QEIDirectionGet                                                   \
        ROM_QEIDirectionGet
#else
#define MAP_QEIDirectionGet                                                   \
        QEIDirectionGet
#endif
#ifdef ROM_QEIErrorGet
#define MAP_QEIErrorGet                                                       \
        ROM_QEIErrorGet
#else
#define MAP_QEIErrorGet                                                       \
        QEIErrorGet
#endif
#ifdef ROM_QEIVelocityEnable
#define MAP_QEIVelocityEnable                                                 \
        ROM_QEIVelocityEnable
#else
#define MAP_QEIVelocityEnable                                                 \
        QEIVelocityEnable
#endif
#ifdef ROM_QEIVelocityDisable
#define MAP_QEIVelocityDisable                                                \
        ROM_QEIVelocityDisable
#else
#define MAP_QEIVelocityDisable                                                \
        QEIVelocityDisable
#endif
#ifdef ROM_QEIVelocityConfigure
#define MAP_QEIVelocityConfigure                                              \
        ROM_QEIVelocityConfigure
#else
#define MAP_QEIVelocityConfigure                                              \
        QEIVelocityConfigure
#endif
#ifdef ROM_QEIVelocityGet
#define MAP_QEIVelocityGet                                                    \
        ROM_QEIVelocityGet
#else
#define MAP_QEIVelocityGet                                                    \
        QEIVelocityGet
#endif
#ifdef ROM_QEIIntEnable
#define MAP_QEIIntEnable                                                      \
        ROM_QEIIntEnable
#else
#define MAP_QEIIntEnable                                                      \
        QEIIntEnable
#endif
#ifdef ROM_QEIIntDisable
#define MAP_QEIIntDisable                                                     \
        ROM_QEIIntDisable
#else
#define MAP_QEIIntDisable                                                     \
        QEIIntDisable
#endif
#ifdef ROM_QEIIntStatus
#define MAP_QEIIntStatus                                                      \
        ROM_QEIIntStatus
#else
#define MAP_QEIIntStatus                                                      \
        QEIIntStatus
#endif
#ifdef ROM_QEIIntClear
#define MAP_QEIIntClear                                                       \
        ROM_QEIIntClear
#else
#define MAP_QEIIntClear                                                       \
        QEIIntClear
#endif

//*****************************************************************************
//
// Macros for the SHAMD5 API.
//
//*****************************************************************************
#ifdef ROM_SHAMD5IntStatus
#define MAP_SHAMD5IntStatus                                                   \
        ROM_SHAMD5IntStatus
#else
#define MAP_SHAMD5IntStatus                                                   \
        SHAMD5IntStatus
#endif
#ifdef ROM_SHAMD5ConfigSet
#define MAP_SHAMD5ConfigSet                                                   \
        ROM_SHAMD5ConfigSet
#else
#define MAP_SHAMD5ConfigSet                                                   \
        SHAMD5ConfigSet
#endif
#ifdef ROM_SHAMD5DataProcess
#define MAP_SHAMD5DataProcess                                                 \
        ROM_SHAMD5DataProcess
#else
#define MAP_SHAMD5DataProcess                                                 \
        SHAMD5DataProcess
#endif
#ifdef ROM_SHAMD5DataWrite
#define MAP_SHAMD5DataWrite                                                   \
        ROM_SHAMD5DataWrite
#else
#define MAP_SHAMD5DataWrite                                                   \
        SHAMD5DataWrite
#endif
#ifdef ROM_SHAMD5DataWriteNonBlocking
#define MAP_SHAMD5DataWriteNonBlocking                                        \
        ROM_SHAMD5DataWriteNonBlocking
#else
#define MAP_SHAMD5DataWriteNonBlocking                                        \
        SHAMD5DataWriteNonBlocking
#endif
#ifdef ROM_SHAMD5DMADisable
#define MAP_SHAMD5DMADisable                                                  \
        ROM_SHAMD5DMADisable
#else
#define MAP_SHAMD5DMADisable                                                  \
        SHAMD5DMADisable
#endif
#ifdef ROM_SHAMD5DMAEnable
#define MAP_SHAMD5DMAEnable                                                   \
        ROM_SHAMD5DMAEnable
#else
#define MAP_SHAMD5DMAEnable                                                   \
        SHAMD5DMAEnable
#endif
#ifdef ROM_SHAMD5HashLengthSet
#define MAP_SHAMD5HashLengthSet                                               \
        ROM_SHAMD5HashLengthSet
#else
#define MAP_SHAMD5HashLengthSet                                               \
        SHAMD5HashLengthSet
#endif
#ifdef ROM_SHAMD5HMACKeySet
#define MAP_SHAMD5HMACKeySet                                                  \
        ROM_SHAMD5HMACKeySet
#else
#define MAP_SHAMD5HMACKeySet                                                  \
        SHAMD5HMACKeySet
#endif
#ifdef ROM_SHAMD5HMACPPKeyGenerate
#define MAP_SHAMD5HMACPPKeyGenerate                                           \
        ROM_SHAMD5HMACPPKeyGenerate
#else
#define MAP_SHAMD5HMACPPKeyGenerate                                           \
        SHAMD5HMACPPKeyGenerate
#endif
#ifdef ROM_SHAMD5HMACPPKeySet
#define MAP_SHAMD5HMACPPKeySet                                                \
        ROM_SHAMD5HMACPPKeySet
#else
#define MAP_SHAMD5HMACPPKeySet                                                \
        SHAMD5HMACPPKeySet
#endif
#ifdef ROM_SHAMD5HMACProcess
#define MAP_SHAMD5HMACProcess                                                 \
        ROM_SHAMD5HMACProcess
#else
#define MAP_SHAMD5HMACProcess                                                 \
        SHAMD5HMACProcess
#endif
#ifdef ROM_SHAMD5IntClear
#define MAP_SHAMD5IntClear                                                    \
        ROM_SHAMD5IntClear
#else
#define MAP_SHAMD5IntClear                                                    \
        SHAMD5IntClear
#endif
#ifdef ROM_SHAMD5IntDisable
#define MAP_SHAMD5IntDisable                                                  \
        ROM_SHAMD5IntDisable
#else
#define MAP_SHAMD5IntDisable                                                  \
        SHAMD5IntDisable
#endif
#ifdef ROM_SHAMD5IntEnable
#define MAP_SHAMD5IntEnable                                                   \
        ROM_SHAMD5IntEnable
#else
#define MAP_SHAMD5IntEnable                                                   \
        SHAMD5IntEnable
#endif
#ifdef ROM_SHAMD5Reset
#define MAP_SHAMD5Reset                                                       \
        ROM_SHAMD5Reset
#else
#define MAP_SHAMD5Reset                                                       \
        SHAMD5Reset
#endif
#ifdef ROM_SHAMD5ResultRead
#define MAP_SHAMD5ResultRead                                                  \
        ROM_SHAMD5ResultRead
#else
#define MAP_SHAMD5ResultRead                                                  \
        SHAMD5ResultRead
#endif

//*****************************************************************************
//
// Macros for the SMBus API.
//
//*****************************************************************************
#ifdef ROM_SMBusMasterIntProcess
#define MAP_SMBusMasterIntProcess                                             \
        ROM_SMBusMasterIntProcess
#else
#define MAP_SMBusMasterIntProcess                                             \
        SMBusMasterIntProcess
#endif
#ifdef ROM_SMBusARPDisable
#define MAP_SMBusARPDisable                                                   \
        ROM_SMBusARPDisable
#else
#define MAP_SMBusARPDisable                                                   \
        SMBusARPDisable
#endif
#ifdef ROM_SMBusARPEnable
#define MAP_SMBusARPEnable                                                    \
        ROM_SMBusARPEnable
#else
#define MAP_SMBusARPEnable                                                    \
        SMBusARPEnable
#endif
#ifdef ROM_SMBusARPUDIDPacketDecode
#define MAP_SMBusARPUDIDPacketDecode                                          \
        ROM_SMBusARPUDIDPacketDecode
#else
#define MAP_SMBusARPUDIDPacketDecode                                          \
        SMBusARPUDIDPacketDecode
#endif
#ifdef ROM_SMBusARPUDIDPacketEncode
#define MAP_SMBusARPUDIDPacketEncode                                          \
        ROM_SMBusARPUDIDPacketEncode
#else
#define MAP_SMBusARPUDIDPacketEncode                                          \
        SMBusARPUDIDPacketEncode
#endif
#ifdef ROM_SMBusMasterARPAssignAddress
#define MAP_SMBusMasterARPAssignAddress                                       \
        ROM_SMBusMasterARPAssignAddress
#else
#define MAP_SMBusMasterARPAssignAddress                                       \
        SMBusMasterARPAssignAddress
#endif
#ifdef ROM_SMBusMasterARPGetUDIDDir
#define MAP_SMBusMasterARPGetUDIDDir                                          \
        ROM_SMBusMasterARPGetUDIDDir
#else
#define MAP_SMBusMasterARPGetUDIDDir                                          \
        SMBusMasterARPGetUDIDDir
#endif
#ifdef ROM_SMBusMasterARPGetUDIDGen
#define MAP_SMBusMasterARPGetUDIDGen                                          \
        ROM_SMBusMasterARPGetUDIDGen
#else
#define MAP_SMBusMasterARPGetUDIDGen                                          \
        SMBusMasterARPGetUDIDGen
#endif
#ifdef ROM_SMBusMasterARPNotifyMaster
#define MAP_SMBusMasterARPNotifyMaster                                        \
        ROM_SMBusMasterARPNotifyMaster
#else
#define MAP_SMBusMasterARPNotifyMaster                                        \
        SMBusMasterARPNotifyMaster
#endif
#ifdef ROM_SMBusMasterARPPrepareToARP
#define MAP_SMBusMasterARPPrepareToARP                                        \
        ROM_SMBusMasterARPPrepareToARP
#else
#define MAP_SMBusMasterARPPrepareToARP                                        \
        SMBusMasterARPPrepareToARP
#endif
#ifdef ROM_SMBusMasterARPResetDeviceDir
#define MAP_SMBusMasterARPResetDeviceDir                                      \
        ROM_SMBusMasterARPResetDeviceDir
#else
#define MAP_SMBusMasterARPResetDeviceDir                                      \
        SMBusMasterARPResetDeviceDir
#endif
#ifdef ROM_SMBusMasterARPResetDeviceGen
#define MAP_SMBusMasterARPResetDeviceGen                                      \
        ROM_SMBusMasterARPResetDeviceGen
#else
#define MAP_SMBusMasterARPResetDeviceGen                                      \
        SMBusMasterARPResetDeviceGen
#endif
#ifdef ROM_SMBusMasterBlockProcessCall
#define MAP_SMBusMasterBlockProcessCall                                       \
        ROM_SMBusMasterBlockProcessCall
#else
#define MAP_SMBusMasterBlockProcessCall                                       \
        SMBusMasterBlockProcessCall
#endif
#ifdef ROM_SMBusMasterBlockRead
#define MAP_SMBusMasterBlockRead                                              \
        ROM_SMBusMasterBlockRead
#else
#define MAP_SMBusMasterBlockRead                                              \
        SMBusMasterBlockRead
#endif
#ifdef ROM_SMBusMasterBlockWrite
#define MAP_SMBusMasterBlockWrite                                             \
        ROM_SMBusMasterBlockWrite
#else
#define MAP_SMBusMasterBlockWrite                                             \
        SMBusMasterBlockWrite
#endif
#ifdef ROM_SMBusMasterByteReceive
#define MAP_SMBusMasterByteReceive                                            \
        ROM_SMBusMasterByteReceive
#else
#define MAP_SMBusMasterByteReceive                                            \
        SMBusMasterByteReceive
#endif
#ifdef ROM_SMBusMasterByteSend
#define MAP_SMBusMasterByteSend                                               \
        ROM_SMBusMasterByteSend
#else
#define MAP_SMBusMasterByteSend                                               \
        SMBusMasterByteSend
#endif
#ifdef ROM_SMBusMasterByteWordRead
#define MAP_SMBusMasterByteWordRead                                           \
        ROM_SMBusMasterByteWordRead
#else
#define MAP_SMBusMasterByteWordRead                                           \
        SMBusMasterByteWordRead
#endif
#ifdef ROM_SMBusMasterByteWordWrite
#define MAP_SMBusMasterByteWordWrite                                          \
        ROM_SMBusMasterByteWordWrite
#else
#define MAP_SMBusMasterByteWordWrite                                          \
        SMBusMasterByteWordWrite
#endif
#ifdef ROM_SMBusMasterHostNotify
#define MAP_SMBusMasterHostNotify                                             \
        ROM_SMBusMasterHostNotify
#else
#define MAP_SMBusMasterHostNotify                                             \
        SMBusMasterHostNotify
#endif
#ifdef ROM_SMBusMasterI2CRead
#define MAP_SMBusMasterI2CRead                                                \
        ROM_SMBusMasterI2CRead
#else
#define MAP_SMBusMasterI2CRead                                                \
        SMBusMasterI2CRead
#endif
#ifdef ROM_SMBusMasterI2CWrite
#define MAP_SMBusMasterI2CWrite                                               \
        ROM_SMBusMasterI2CWrite
#else
#define MAP_SMBusMasterI2CWrite                                               \
        SMBusMasterI2CWrite
#endif
#ifdef ROM_SMBusMasterI2CWriteRead
#define MAP_SMBusMasterI2CWriteRead                                           \
        ROM_SMBusMasterI2CWriteRead
#else
#define MAP_SMBusMasterI2CWriteRead                                           \
        SMBusMasterI2CWriteRead
#endif
#ifdef ROM_SMBusMasterInit
#define MAP_SMBusMasterInit                                                   \
        ROM_SMBusMasterInit
#else
#define MAP_SMBusMasterInit                                                   \
        SMBusMasterInit
#endif
#ifdef ROM_SMBusMasterIntEnable
#define MAP_SMBusMasterIntEnable                                              \
        ROM_SMBusMasterIntEnable
#else
#define MAP_SMBusMasterIntEnable                                              \
        SMBusMasterIntEnable
#endif
#ifdef ROM_SMBusMasterProcessCall
#define MAP_SMBusMasterProcessCall                                            \
        ROM_SMBusMasterProcessCall
#else
#define MAP_SMBusMasterProcessCall                                            \
        SMBusMasterProcessCall
#endif
#ifdef ROM_SMBusMasterQuickCommand
#define MAP_SMBusMasterQuickCommand                                           \
        ROM_SMBusMasterQuickCommand
#else
#define MAP_SMBusMasterQuickCommand                                           \
        SMBusMasterQuickCommand
#endif
#ifdef ROM_SMBusPECDisable
#define MAP_SMBusPECDisable                                                   \
        ROM_SMBusPECDisable
#else
#define MAP_SMBusPECDisable                                                   \
        SMBusPECDisable
#endif
#ifdef ROM_SMBusPECEnable
#define MAP_SMBusPECEnable                                                    \
        ROM_SMBusPECEnable
#else
#define MAP_SMBusPECEnable                                                    \
        SMBusPECEnable
#endif
#ifdef ROM_SMBusRxPacketSizeGet
#define MAP_SMBusRxPacketSizeGet                                              \
        ROM_SMBusRxPacketSizeGet
#else
#define MAP_SMBusRxPacketSizeGet                                              \
        SMBusRxPacketSizeGet
#endif
#ifdef ROM_SMBusSlaveACKSend
#define MAP_SMBusSlaveACKSend                                                 \
        ROM_SMBusSlaveACKSend
#else
#define MAP_SMBusSlaveACKSend                                                 \
        SMBusSlaveACKSend
#endif
#ifdef ROM_SMBusSlaveAddressSet
#define MAP_SMBusSlaveAddressSet                                              \
        ROM_SMBusSlaveAddressSet
#else
#define MAP_SMBusSlaveAddressSet                                              \
        SMBusSlaveAddressSet
#endif
#ifdef ROM_SMBusSlaveARPFlagARGet
#define MAP_SMBusSlaveARPFlagARGet                                            \
        ROM_SMBusSlaveARPFlagARGet
#else
#define MAP_SMBusSlaveARPFlagARGet                                            \
        SMBusSlaveARPFlagARGet
#endif
#ifdef ROM_SMBusSlaveARPFlagARSet
#define MAP_SMBusSlaveARPFlagARSet                                            \
        ROM_SMBusSlaveARPFlagARSet
#else
#define MAP_SMBusSlaveARPFlagARSet                                            \
        SMBusSlaveARPFlagARSet
#endif
#ifdef ROM_SMBusSlaveARPFlagAVGet
#define MAP_SMBusSlaveARPFlagAVGet                                            \
        ROM_SMBusSlaveARPFlagAVGet
#else
#define MAP_SMBusSlaveARPFlagAVGet                                            \
        SMBusSlaveARPFlagAVGet
#endif
#ifdef ROM_SMBusSlaveARPFlagAVSet
#define MAP_SMBusSlaveARPFlagAVSet                                            \
        ROM_SMBusSlaveARPFlagAVSet
#else
#define MAP_SMBusSlaveARPFlagAVSet                                            \
        SMBusSlaveARPFlagAVSet
#endif
#ifdef ROM_SMBusSlaveBlockTransferDisable
#define MAP_SMBusSlaveBlockTransferDisable                                    \
        ROM_SMBusSlaveBlockTransferDisable
#else
#define MAP_SMBusSlaveBlockTransferDisable                                    \
        SMBusSlaveBlockTransferDisable
#endif
#ifdef ROM_SMBusSlaveBlockTransferEnable
#define MAP_SMBusSlaveBlockTransferEnable                                     \
        ROM_SMBusSlaveBlockTransferEnable
#else
#define MAP_SMBusSlaveBlockTransferEnable                                     \
        SMBusSlaveBlockTransferEnable
#endif
#ifdef ROM_SMBusSlaveCommandGet
#define MAP_SMBusSlaveCommandGet                                              \
        ROM_SMBusSlaveCommandGet
#else
#define MAP_SMBusSlaveCommandGet                                              \
        SMBusSlaveCommandGet
#endif
#ifdef ROM_SMBusSlaveI2CDisable
#define MAP_SMBusSlaveI2CDisable                                              \
        ROM_SMBusSlaveI2CDisable
#else
#define MAP_SMBusSlaveI2CDisable                                              \
        SMBusSlaveI2CDisable
#endif
#ifdef ROM_SMBusSlaveI2CEnable
#define MAP_SMBusSlaveI2CEnable                                               \
        ROM_SMBusSlaveI2CEnable
#else
#define MAP_SMBusSlaveI2CEnable                                               \
        SMBusSlaveI2CEnable
#endif
#ifdef ROM_SMBusSlaveInit
#define MAP_SMBusSlaveInit                                                    \
        ROM_SMBusSlaveInit
#else
#define MAP_SMBusSlaveInit                                                    \
        SMBusSlaveInit
#endif
#ifdef ROM_SMBusSlaveIntAddressGet
#define MAP_SMBusSlaveIntAddressGet                                           \
        ROM_SMBusSlaveIntAddressGet
#else
#define MAP_SMBusSlaveIntAddressGet                                           \
        SMBusSlaveIntAddressGet
#endif
#ifdef ROM_SMBusSlaveIntEnable
#define MAP_SMBusSlaveIntEnable                                               \
        ROM_SMBusSlaveIntEnable
#else
#define MAP_SMBusSlaveIntEnable                                               \
        SMBusSlaveIntEnable
#endif
#ifdef ROM_SMBusSlaveIntProcess
#define MAP_SMBusSlaveIntProcess                                              \
        ROM_SMBusSlaveIntProcess
#else
#define MAP_SMBusSlaveIntProcess                                              \
        SMBusSlaveIntProcess
#endif
#ifdef ROM_SMBusSlaveManualACKDisable
#define MAP_SMBusSlaveManualACKDisable                                        \
        ROM_SMBusSlaveManualACKDisable
#else
#define MAP_SMBusSlaveManualACKDisable                                        \
        SMBusSlaveManualACKDisable
#endif
#ifdef ROM_SMBusSlaveManualACKEnable
#define MAP_SMBusSlaveManualACKEnable                                         \
        ROM_SMBusSlaveManualACKEnable
#else
#define MAP_SMBusSlaveManualACKEnable                                         \
        SMBusSlaveManualACKEnable
#endif
#ifdef ROM_SMBusSlaveManualACKStatusGet
#define MAP_SMBusSlaveManualACKStatusGet                                      \
        ROM_SMBusSlaveManualACKStatusGet
#else
#define MAP_SMBusSlaveManualACKStatusGet                                      \
        SMBusSlaveManualACKStatusGet
#endif
#ifdef ROM_SMBusSlaveProcessCallDisable
#define MAP_SMBusSlaveProcessCallDisable                                      \
        ROM_SMBusSlaveProcessCallDisable
#else
#define MAP_SMBusSlaveProcessCallDisable                                      \
        SMBusSlaveProcessCallDisable
#endif
#ifdef ROM_SMBusSlaveProcessCallEnable
#define MAP_SMBusSlaveProcessCallEnable                                       \
        ROM_SMBusSlaveProcessCallEnable
#else
#define MAP_SMBusSlaveProcessCallEnable                                       \
        SMBusSlaveProcessCallEnable
#endif
#ifdef ROM_SMBusSlaveRxBufferSet
#define MAP_SMBusSlaveRxBufferSet                                             \
        ROM_SMBusSlaveRxBufferSet
#else
#define MAP_SMBusSlaveRxBufferSet                                             \
        SMBusSlaveRxBufferSet
#endif
#ifdef ROM_SMBusSlaveTransferInit
#define MAP_SMBusSlaveTransferInit                                            \
        ROM_SMBusSlaveTransferInit
#else
#define MAP_SMBusSlaveTransferInit                                            \
        SMBusSlaveTransferInit
#endif
#ifdef ROM_SMBusSlaveTxBufferSet
#define MAP_SMBusSlaveTxBufferSet                                             \
        ROM_SMBusSlaveTxBufferSet
#else
#define MAP_SMBusSlaveTxBufferSet                                             \
        SMBusSlaveTxBufferSet
#endif
#ifdef ROM_SMBusSlaveUDIDSet
#define MAP_SMBusSlaveUDIDSet                                                 \
        ROM_SMBusSlaveUDIDSet
#else
#define MAP_SMBusSlaveUDIDSet                                                 \
        SMBusSlaveUDIDSet
#endif
#ifdef ROM_SMBusStatusGet
#define MAP_SMBusStatusGet                                                    \
        ROM_SMBusStatusGet
#else
#define MAP_SMBusStatusGet                                                    \
        SMBusStatusGet
#endif
#ifdef ROM_SMBusSlaveDataSend
#define MAP_SMBusSlaveDataSend                                                \
        ROM_SMBusSlaveDataSend
#else
#define MAP_SMBusSlaveDataSend                                                \
        SMBusSlaveDataSend
#endif
#ifdef ROM_SMBusFIFOEnable
#define MAP_SMBusFIFOEnable                                                   \
        ROM_SMBusFIFOEnable
#else
#define MAP_SMBusFIFOEnable                                                   \
        SMBusFIFOEnable
#endif
#ifdef ROM_SMBusFIFODisable
#define MAP_SMBusFIFODisable                                                  \
        ROM_SMBusFIFODisable
#else
#define MAP_SMBusFIFODisable                                                  \
        SMBusFIFODisable
#endif
#ifdef ROM_SMBusDMAEnable
#define MAP_SMBusDMAEnable                                                    \
        ROM_SMBusDMAEnable
#else
#define MAP_SMBusDMAEnable                                                    \
        SMBusDMAEnable
#endif
#ifdef ROM_SMBusDMADisable
#define MAP_SMBusDMADisable                                                   \
        ROM_SMBusDMADisable
#else
#define MAP_SMBusDMADisable                                                   \
        SMBusDMADisable
#endif

//*****************************************************************************
//
// Macros for the SPIFlash API.
//
//*****************************************************************************
#ifdef ROM_SPIFlashIntHandler
#define MAP_SPIFlashIntHandler                                                \
        ROM_SPIFlashIntHandler
#else
#define MAP_SPIFlashIntHandler                                                \
        SPIFlashIntHandler
#endif
#ifdef ROM_SPIFlashInit
#define MAP_SPIFlashInit                                                      \
        ROM_SPIFlashInit
#else
#define MAP_SPIFlashInit                                                      \
        SPIFlashInit
#endif
#ifdef ROM_SPIFlashWriteStatus
#define MAP_SPIFlashWriteStatus                                               \
        ROM_SPIFlashWriteStatus
#else
#define MAP_SPIFlashWriteStatus                                               \
        SPIFlashWriteStatus
#endif
#ifdef ROM_SPIFlashPageProgram
#define MAP_SPIFlashPageProgram                                               \
        ROM_SPIFlashPageProgram
#else
#define MAP_SPIFlashPageProgram                                               \
        SPIFlashPageProgram
#endif
#ifdef ROM_SPIFlashPageProgramNonBlocking
#define MAP_SPIFlashPageProgramNonBlocking                                    \
        ROM_SPIFlashPageProgramNonBlocking
#else
#define MAP_SPIFlashPageProgramNonBlocking                                    \
        SPIFlashPageProgramNonBlocking
#endif
#ifdef ROM_SPIFlashRead
#define MAP_SPIFlashRead                                                      \
        ROM_SPIFlashRead
#else
#define MAP_SPIFlashRead                                                      \
        SPIFlashRead
#endif
#ifdef ROM_SPIFlashReadNonBlocking
#define MAP_SPIFlashReadNonBlocking                                           \
        ROM_SPIFlashReadNonBlocking
#else
#define MAP_SPIFlashReadNonBlocking                                           \
        SPIFlashReadNonBlocking
#endif
#ifdef ROM_SPIFlashWriteDisable
#define MAP_SPIFlashWriteDisable                                              \
        ROM_SPIFlashWriteDisable
#else
#define MAP_SPIFlashWriteDisable                                              \
        SPIFlashWriteDisable
#endif
#ifdef ROM_SPIFlashReadStatus
#define MAP_SPIFlashReadStatus                                                \
        ROM_SPIFlashReadStatus
#else
#define MAP_SPIFlashReadStatus                                                \
        SPIFlashReadStatus
#endif
#ifdef ROM_SPIFlashWriteEnable
#define MAP_SPIFlashWriteEnable                                               \
        ROM_SPIFlashWriteEnable
#else
#define MAP_SPIFlashWriteEnable                                               \
        SPIFlashWriteEnable
#endif
#ifdef ROM_SPIFlashFastRead
#define MAP_SPIFlashFastRead                                                  \
        ROM_SPIFlashFastRead
#else
#define MAP_SPIFlashFastRead                                                  \
        SPIFlashFastRead
#endif
#ifdef ROM_SPIFlashFastReadNonBlocking
#define MAP_SPIFlashFastReadNonBlocking                                       \
        ROM_SPIFlashFastReadNonBlocking
#else
#define MAP_SPIFlashFastReadNonBlocking                                       \
        SPIFlashFastReadNonBlocking
#endif
#ifdef ROM_SPIFlashSectorErase
#define MAP_SPIFlashSectorErase                                               \
        ROM_SPIFlashSectorErase
#else
#define MAP_SPIFlashSectorErase                                               \
        SPIFlashSectorErase
#endif
#ifdef ROM_SPIFlashDualRead
#define MAP_SPIFlashDualRead                                                  \
        ROM_SPIFlashDualRead
#else
#define MAP_SPIFlashDualRead                                                  \
        SPIFlashDualRead
#endif
#ifdef ROM_SPIFlashDualReadNonBlocking
#define MAP_SPIFlashDualReadNonBlocking                                       \
        ROM_SPIFlashDualReadNonBlocking
#else
#define MAP_SPIFlashDualReadNonBlocking                                       \
        SPIFlashDualReadNonBlocking
#endif
#ifdef ROM_SPIFlashBlockErase32
#define MAP_SPIFlashBlockErase32                                              \
        ROM_SPIFlashBlockErase32
#else
#define MAP_SPIFlashBlockErase32                                              \
        SPIFlashBlockErase32
#endif
#ifdef ROM_SPIFlashQuadRead
#define MAP_SPIFlashQuadRead                                                  \
        ROM_SPIFlashQuadRead
#else
#define MAP_SPIFlashQuadRead                                                  \
        SPIFlashQuadRead
#endif
#ifdef ROM_SPIFlashQuadReadNonBlocking
#define MAP_SPIFlashQuadReadNonBlocking                                       \
        ROM_SPIFlashQuadReadNonBlocking
#else
#define MAP_SPIFlashQuadReadNonBlocking                                       \
        SPIFlashQuadReadNonBlocking
#endif
#ifdef ROM_SPIFlashReadID
#define MAP_SPIFlashReadID                                                    \
        ROM_SPIFlashReadID
#else
#define MAP_SPIFlashReadID                                                    \
        SPIFlashReadID
#endif
#ifdef ROM_SPIFlashChipErase
#define MAP_SPIFlashChipErase                                                 \
        ROM_SPIFlashChipErase
#else
#define MAP_SPIFlashChipErase                                                 \
        SPIFlashChipErase
#endif
#ifdef ROM_SPIFlashBlockErase64
#define MAP_SPIFlashBlockErase64                                              \
        ROM_SPIFlashBlockErase64
#else
#define MAP_SPIFlashBlockErase64                                              \
        SPIFlashBlockErase64
#endif

//*****************************************************************************
//
// Macros for the SSI API.
//
//*****************************************************************************
#ifdef ROM_SSIDataPut
#define MAP_SSIDataPut                                                        \
        ROM_SSIDataPut
#else
#define MAP_SSIDataPut                                                        \
        SSIDataPut
#endif
#ifdef ROM_SSIConfigSetExpClk
#define MAP_SSIConfigSetExpClk                                                \
        ROM_SSIConfigSetExpClk
#else
#define MAP_SSIConfigSetExpClk                                                \
        SSIConfigSetExpClk
#endif
#ifdef ROM_SSIEnable
#define MAP_SSIEnable                                                         \
        ROM_SSIEnable
#else
#define MAP_SSIEnable                                                         \
        SSIEnable
#endif
#ifdef ROM_SSIDisable
#define MAP_SSIDisable                                                        \
        ROM_SSIDisable
#else
#define MAP_SSIDisable                                                        \
        SSIDisable
#endif
#ifdef ROM_SSIIntEnable
#define MAP_SSIIntEnable                                                      \
        ROM_SSIIntEnable
#else
#define MAP_SSIIntEnable                                                      \
        SSIIntEnable
#endif
#ifdef ROM_SSIIntDisable
#define MAP_SSIIntDisable                                                     \
        ROM_SSIIntDisable
#else
#define MAP_SSIIntDisable                                                     \
        SSIIntDisable
#endif
#ifdef ROM_SSIIntStatus
#define MAP_SSIIntStatus                                                      \
        ROM_SSIIntStatus
#else
#define MAP_SSIIntStatus                                                      \
        SSIIntStatus
#endif
#ifdef ROM_SSIIntClear
#define MAP_SSIIntClear                                                       \
        ROM_SSIIntClear
#else
#define MAP_SSIIntClear                                                       \
        SSIIntClear
#endif
#ifdef ROM_SSIDataPutNonBlocking
#define MAP_SSIDataPutNonBlocking                                             \
        ROM_SSIDataPutNonBlocking
#else
#define MAP_SSIDataPutNonBlocking                                             \
        SSIDataPutNonBlocking
#endif
#ifdef ROM_SSIDataGet
#define MAP_SSIDataGet                                                        \
        ROM_SSIDataGet
#else
#define MAP_SSIDataGet                                                        \
        SSIDataGet
#endif
#ifdef ROM_SSIDataGetNonBlocking
#define MAP_SSIDataGetNonBlocking                                             \
        ROM_SSIDataGetNonBlocking
#else
#define MAP_SSIDataGetNonBlocking                                             \
        SSIDataGetNonBlocking
#endif
#ifdef ROM_SSIDMAEnable
#define MAP_SSIDMAEnable                                                      \
        ROM_SSIDMAEnable
#else
#define MAP_SSIDMAEnable                                                      \
        SSIDMAEnable
#endif
#ifdef ROM_SSIDMADisable
#define MAP_SSIDMADisable                                                     \
        ROM_SSIDMADisable
#else
#define MAP_SSIDMADisable                                                     \
        SSIDMADisable
#endif
#ifdef ROM_SSIBusy
#define MAP_SSIBusy                                                           \
        ROM_SSIBusy
#else
#define MAP_SSIBusy                                                           \
        SSIBusy
#endif
#ifdef ROM_SSIClockSourceGet
#define MAP_SSIClockSourceGet                                                 \
        ROM_SSIClockSourceGet
#else
#define MAP_SSIClockSourceGet                                                 \
        SSIClockSourceGet
#endif
#ifdef ROM_SSIClockSourceSet
#define MAP_SSIClockSourceSet                                                 \
        ROM_SSIClockSourceSet
#else
#define MAP_SSIClockSourceSet                                                 \
        SSIClockSourceSet
#endif
#ifdef ROM_SSIAdvModeSet
#define MAP_SSIAdvModeSet                                                     \
        ROM_SSIAdvModeSet
#else
#define MAP_SSIAdvModeSet                                                     \
        SSIAdvModeSet
#endif
#ifdef ROM_SSIAdvDataPutFrameEnd
#define MAP_SSIAdvDataPutFrameEnd                                             \
        ROM_SSIAdvDataPutFrameEnd
#else
#define MAP_SSIAdvDataPutFrameEnd                                             \
        SSIAdvDataPutFrameEnd
#endif
#ifdef ROM_SSIAdvDataPutFrameEndNonBlocking
#define MAP_SSIAdvDataPutFrameEndNonBlocking                                  \
        ROM_SSIAdvDataPutFrameEndNonBlocking
#else
#define MAP_SSIAdvDataPutFrameEndNonBlocking                                  \
        SSIAdvDataPutFrameEndNonBlocking
#endif
#ifdef ROM_SSIAdvFrameHoldEnable
#define MAP_SSIAdvFrameHoldEnable                                             \
        ROM_SSIAdvFrameHoldEnable
#else
#define MAP_SSIAdvFrameHoldEnable                                             \
        SSIAdvFrameHoldEnable
#endif
#ifdef ROM_SSIAdvFrameHoldDisable
#define MAP_SSIAdvFrameHoldDisable                                            \
        ROM_SSIAdvFrameHoldDisable
#else
#define MAP_SSIAdvFrameHoldDisable                                            \
        SSIAdvFrameHoldDisable
#endif

//*****************************************************************************
//
// Macros for the SysCtl API.
//
//*****************************************************************************
#ifdef ROM_SysCtlSleep
#define MAP_SysCtlSleep                                                       \
        ROM_SysCtlSleep
#else
#define MAP_SysCtlSleep                                                       \
        SysCtlSleep
#endif
#ifdef ROM_SysCtlSRAMSizeGet
#define MAP_SysCtlSRAMSizeGet                                                 \
        ROM_SysCtlSRAMSizeGet
#else
#define MAP_SysCtlSRAMSizeGet                                                 \
        SysCtlSRAMSizeGet
#endif
#ifdef ROM_SysCtlFlashSizeGet
#define MAP_SysCtlFlashSizeGet                                                \
        ROM_SysCtlFlashSizeGet
#else
#define MAP_SysCtlFlashSizeGet                                                \
        SysCtlFlashSizeGet
#endif
#ifdef ROM_SysCtlPeripheralPresent
#define MAP_SysCtlPeripheralPresent                                           \
        ROM_SysCtlPeripheralPresent
#else
#define MAP_SysCtlPeripheralPresent                                           \
        SysCtlPeripheralPresent
#endif
#ifdef ROM_SysCtlPeripheralReset
#define MAP_SysCtlPeripheralReset                                             \
        ROM_SysCtlPeripheralReset
#else
#define MAP_SysCtlPeripheralReset                                             \
        SysCtlPeripheralReset
#endif
#ifdef ROM_SysCtlPeripheralEnable
#define MAP_SysCtlPeripheralEnable                                            \
        ROM_SysCtlPeripheralEnable
#else
#define MAP_SysCtlPeripheralEnable                                            \
        SysCtlPeripheralEnable
#endif
#ifdef ROM_SysCtlPeripheralDisable
#define MAP_SysCtlPeripheralDisable                                           \
        ROM_SysCtlPeripheralDisable
#else
#define MAP_SysCtlPeripheralDisable                                           \
        SysCtlPeripheralDisable
#endif
#ifdef ROM_SysCtlPeripheralSleepEnable
#define MAP_SysCtlPeripheralSleepEnable                                       \
        ROM_SysCtlPeripheralSleepEnable
#else
#define MAP_SysCtlPeripheralSleepEnable                                       \
        SysCtlPeripheralSleepEnable
#endif
#ifdef ROM_SysCtlPeripheralSleepDisable
#define MAP_SysCtlPeripheralSleepDisable                                      \
        ROM_SysCtlPeripheralSleepDisable
#else
#define MAP_SysCtlPeripheralSleepDisable                                      \
        SysCtlPeripheralSleepDisable
#endif
#ifdef ROM_SysCtlPeripheralDeepSleepEnable
#define MAP_SysCtlPeripheralDeepSleepEnable                                   \
        ROM_SysCtlPeripheralDeepSleepEnable
#else
#define MAP_SysCtlPeripheralDeepSleepEnable                                   \
        SysCtlPeripheralDeepSleepEnable
#endif
#ifdef ROM_SysCtlPeripheralDeepSleepDisable
#define MAP_SysCtlPeripheralDeepSleepDisable                                  \
        ROM_SysCtlPeripheralDeepSleepDisable
#else
#define MAP_SysCtlPeripheralDeepSleepDisable                                  \
        SysCtlPeripheralDeepSleepDisable
#endif
#ifdef ROM_SysCtlPeripheralClockGating
#define MAP_SysCtlPeripheralClockGating                                       \
        ROM_SysCtlPeripheralClockGating
#else
#define MAP_SysCtlPeripheralClockGating                                       \
        SysCtlPeripheralClockGating
#endif
#ifdef ROM_SysCtlIntEnable
#define MAP_SysCtlIntEnable                                                   \
        ROM_SysCtlIntEnable
#else
#define MAP_SysCtlIntEnable                                                   \
        SysCtlIntEnable
#endif
#ifdef ROM_SysCtlIntDisable
#define MAP_SysCtlIntDisable                                                  \
        ROM_SysCtlIntDisable
#else
#define MAP_SysCtlIntDisable                                                  \
        SysCtlIntDisable
#endif
#ifdef ROM_SysCtlIntClear
#define MAP_SysCtlIntClear                                                    \
        ROM_SysCtlIntClear
#else
#define MAP_SysCtlIntClear                                                    \
        SysCtlIntClear
#endif
#ifdef ROM_SysCtlIntStatus
#define MAP_SysCtlIntStatus                                                   \
        ROM_SysCtlIntStatus
#else
#define MAP_SysCtlIntStatus                                                   \
        SysCtlIntStatus
#endif
#ifdef ROM_SysCtlReset
#define MAP_SysCtlReset                                                       \
        ROM_SysCtlReset
#else
#define MAP_SysCtlReset                                                       \
        SysCtlReset
#endif
#ifdef ROM_SysCtlDeepSleep
#define MAP_SysCtlDeepSleep                                                   \
        ROM_SysCtlDeepSleep
#else
#define MAP_SysCtlDeepSleep                                                   \
        SysCtlDeepSleep
#endif
#ifdef ROM_SysCtlResetCauseGet
#define MAP_SysCtlResetCauseGet                                               \
        ROM_SysCtlResetCauseGet
#else
#define MAP_SysCtlResetCauseGet                                               \
        SysCtlResetCauseGet
#endif
#ifdef ROM_SysCtlResetCauseClear
#define MAP_SysCtlResetCauseClear                                             \
        ROM_SysCtlResetCauseClear
#else
#define MAP_SysCtlResetCauseClear                                             \
        SysCtlResetCauseClear
#endif
#ifdef ROM_SysCtlClockSet
#define MAP_SysCtlClockSet                                                    \
        ROM_SysCtlClockSet
#else
#define MAP_SysCtlClockSet                                                    \
        SysCtlClockSet
#endif
#ifdef ROM_SysCtlClockGet
#define MAP_SysCtlClockGet                                                    \
        ROM_SysCtlClockGet
#else
#define MAP_SysCtlClockGet                                                    \
        SysCtlClockGet
#endif
#ifdef ROM_SysCtlPWMClockSet
#define MAP_SysCtlPWMClockSet                                                 \
        ROM_SysCtlPWMClockSet
#else
#define MAP_SysCtlPWMClockSet                                                 \
        SysCtlPWMClockSet
#endif
#ifdef ROM_SysCtlPWMClockGet
#define MAP_SysCtlPWMClockGet                                                 \
        ROM_SysCtlPWMClockGet
#else
#define MAP_SysCtlPWMClockGet                                                 \
        SysCtlPWMClockGet
#endif
#ifdef ROM_SysCtlADCSpeedSet
#define MAP_SysCtlADCSpeedSet                                                 \
        ROM_SysCtlADCSpeedSet
#else
#define MAP_SysCtlADCSpeedSet                                                 \
        SysCtlADCSpeedSet
#endif
#ifdef ROM_SysCtlADCSpeedGet
#define MAP_SysCtlADCSpeedGet                                                 \
        ROM_SysCtlADCSpeedGet
#else
#define MAP_SysCtlADCSpeedGet                                                 \
        SysCtlADCSpeedGet
#endif
#ifdef ROM_SysCtlUSBPLLEnable
#define MAP_SysCtlUSBPLLEnable                                                \
        ROM_SysCtlUSBPLLEnable
#else
#define MAP_SysCtlUSBPLLEnable                                                \
        SysCtlUSBPLLEnable
#endif
#ifdef ROM_SysCtlUSBPLLDisable
#define MAP_SysCtlUSBPLLDisable                                               \
        ROM_SysCtlUSBPLLDisable
#else
#define MAP_SysCtlUSBPLLDisable                                               \
        SysCtlUSBPLLDisable
#endif
#ifdef ROM_SysCtlDelay
#define MAP_SysCtlDelay                                                       \
        ROM_SysCtlDelay
#else
#define MAP_SysCtlDelay                                                       \
        SysCtlDelay
#endif
#ifdef ROM_SysCtlPeripheralReady
#define MAP_SysCtlPeripheralReady                                             \
        ROM_SysCtlPeripheralReady
#else
#define MAP_SysCtlPeripheralReady                                             \
        SysCtlPeripheralReady
#endif
#ifdef ROM_SysCtlPeripheralPowerOn
#define MAP_SysCtlPeripheralPowerOn                                           \
        ROM_SysCtlPeripheralPowerOn
#else
#define MAP_SysCtlPeripheralPowerOn                                           \
        SysCtlPeripheralPowerOn
#endif
#ifdef ROM_SysCtlPeripheralPowerOff
#define MAP_SysCtlPeripheralPowerOff                                          \
        ROM_SysCtlPeripheralPowerOff
#else
#define MAP_SysCtlPeripheralPowerOff                                          \
        SysCtlPeripheralPowerOff
#endif
#ifdef ROM_SysCtlMOSCConfigSet
#define MAP_SysCtlMOSCConfigSet                                               \
        ROM_SysCtlMOSCConfigSet
#else
#define MAP_SysCtlMOSCConfigSet                                               \
        SysCtlMOSCConfigSet
#endif
#ifdef ROM_SysCtlPIOSCCalibrate
#define MAP_SysCtlPIOSCCalibrate                                              \
        ROM_SysCtlPIOSCCalibrate
#else
#define MAP_SysCtlPIOSCCalibrate                                              \
        SysCtlPIOSCCalibrate
#endif
#ifdef ROM_SysCtlDeepSleepClockSet
#define MAP_SysCtlDeepSleepClockSet                                           \
        ROM_SysCtlDeepSleepClockSet
#else
#define MAP_SysCtlDeepSleepClockSet                                           \
        SysCtlDeepSleepClockSet
#endif
#ifdef ROM_SysCtlDeepSleepClockConfigSet
#define MAP_SysCtlDeepSleepClockConfigSet                                     \
        ROM_SysCtlDeepSleepClockConfigSet
#else
#define MAP_SysCtlDeepSleepClockConfigSet                                     \
        SysCtlDeepSleepClockConfigSet
#endif
#ifdef ROM_SysCtlClockFreqSet
#define MAP_SysCtlClockFreqSet                                                \
        ROM_SysCtlClockFreqSet
#else
#define MAP_SysCtlClockFreqSet                                                \
        SysCtlClockFreqSet
#endif
#ifdef ROM_SysCtlLPCLowPowerConfigSet
#define MAP_SysCtlLPCLowPowerConfigSet                                        \
        ROM_SysCtlLPCLowPowerConfigSet
#else
#define MAP_SysCtlLPCLowPowerConfigSet                                        \
        SysCtlLPCLowPowerConfigSet
#endif
#ifdef ROM_SysCtlLPCLowPowerStatusGet
#define MAP_SysCtlLPCLowPowerStatusGet                                        \
        ROM_SysCtlLPCLowPowerStatusGet
#else
#define MAP_SysCtlLPCLowPowerStatusGet                                        \
        SysCtlLPCLowPowerStatusGet
#endif
#ifdef ROM_SysCtlResetBehaviorSet
#define MAP_SysCtlResetBehaviorSet                                            \
        ROM_SysCtlResetBehaviorSet
#else
#define MAP_SysCtlResetBehaviorSet                                            \
        SysCtlResetBehaviorSet
#endif
#ifdef ROM_SysCtlResetBehaviorGet
#define MAP_SysCtlResetBehaviorGet                                            \
        ROM_SysCtlResetBehaviorGet
#else
#define MAP_SysCtlResetBehaviorGet                                            \
        SysCtlResetBehaviorGet
#endif
#ifdef ROM_SysCtlFlashSectorSizeGet
#define MAP_SysCtlFlashSectorSizeGet                                          \
        ROM_SysCtlFlashSectorSizeGet
#else
#define MAP_SysCtlFlashSectorSizeGet                                          \
        SysCtlFlashSectorSizeGet
#endif
#ifdef ROM_SysCtlVoltageEventConfig
#define MAP_SysCtlVoltageEventConfig                                          \
        ROM_SysCtlVoltageEventConfig
#else
#define MAP_SysCtlVoltageEventConfig                                          \
        SysCtlVoltageEventConfig
#endif
#ifdef ROM_SysCtlVoltageEventStatus
#define MAP_SysCtlVoltageEventStatus                                          \
        ROM_SysCtlVoltageEventStatus
#else
#define MAP_SysCtlVoltageEventStatus                                          \
        SysCtlVoltageEventStatus
#endif
#ifdef ROM_SysCtlVoltageEventClear
#define MAP_SysCtlVoltageEventClear                                           \
        ROM_SysCtlVoltageEventClear
#else
#define MAP_SysCtlVoltageEventClear                                           \
        SysCtlVoltageEventClear
#endif
#ifdef ROM_SysCtlNMIStatus
#define MAP_SysCtlNMIStatus                                                   \
        ROM_SysCtlNMIStatus
#else
#define MAP_SysCtlNMIStatus                                                   \
        SysCtlNMIStatus
#endif
#ifdef ROM_SysCtlNMIClear
#define MAP_SysCtlNMIClear                                                    \
        ROM_SysCtlNMIClear
#else
#define MAP_SysCtlNMIClear                                                    \
        SysCtlNMIClear
#endif
#ifdef ROM_SysCtlClockOutConfig
#define MAP_SysCtlClockOutConfig                                              \
        ROM_SysCtlClockOutConfig
#else
#define MAP_SysCtlClockOutConfig                                              \
        SysCtlClockOutConfig
#endif
#ifdef ROM_SysCtlAltClkConfig
#define MAP_SysCtlAltClkConfig                                                \
        ROM_SysCtlAltClkConfig
#else
#define MAP_SysCtlAltClkConfig                                                \
        SysCtlAltClkConfig
#endif
#ifdef ROM_SysCtlLDOConfigSet
#define MAP_SysCtlLDOConfigSet                                                \
        ROM_SysCtlLDOConfigSet
#else
#define MAP_SysCtlLDOConfigSet                                                \
        SysCtlLDOConfigSet
#endif
#ifdef ROM_SysCtlBrownOutConfigSet
#define MAP_SysCtlBrownOutConfigSet                                           \
        ROM_SysCtlBrownOutConfigSet
#else
#define MAP_SysCtlBrownOutConfigSet                                           \
        SysCtlBrownOutConfigSet
#endif

//*****************************************************************************
//
// Macros for the SysExc API.
//
//*****************************************************************************
#ifdef ROM_SysExcIntStatus
#define MAP_SysExcIntStatus                                                   \
        ROM_SysExcIntStatus
#else
#define MAP_SysExcIntStatus                                                   \
        SysExcIntStatus
#endif
#ifdef ROM_SysExcIntClear
#define MAP_SysExcIntClear                                                    \
        ROM_SysExcIntClear
#else
#define MAP_SysExcIntClear                                                    \
        SysExcIntClear
#endif
#ifdef ROM_SysExcIntDisable
#define MAP_SysExcIntDisable                                                  \
        ROM_SysExcIntDisable
#else
#define MAP_SysExcIntDisable                                                  \
        SysExcIntDisable
#endif
#ifdef ROM_SysExcIntEnable
#define MAP_SysExcIntEnable                                                   \
        ROM_SysExcIntEnable
#else
#define MAP_SysExcIntEnable                                                   \
        SysExcIntEnable
#endif

//*****************************************************************************
//
// Macros for the SysTick API.
//
//*****************************************************************************
#ifdef ROM_SysTickValueGet
#define MAP_SysTickValueGet                                                   \
        ROM_SysTickValueGet
#else
#define MAP_SysTickValueGet                                                   \
        SysTickValueGet
#endif
#ifdef ROM_SysTickEnable
#define MAP_SysTickEnable                                                     \
        ROM_SysTickEnable
#else
#define MAP_SysTickEnable                                                     \
        SysTickEnable
#endif
#ifdef ROM_SysTickDisable
#define MAP_SysTickDisable                                                    \
        ROM_SysTickDisable
#else
#define MAP_SysTickDisable                                                    \
        SysTickDisable
#endif
#ifdef ROM_SysTickIntEnable
#define MAP_SysTickIntEnable                                                  \
        ROM_SysTickIntEnable
#else
#define MAP_SysTickIntEnable                                                  \
        SysTickIntEnable
#endif
#ifdef ROM_SysTickIntDisable
#define MAP_SysTickIntDisable                                                 \
        ROM_SysTickIntDisable
#else
#define MAP_SysTickIntDisable                                                 \
        SysTickIntDisable
#endif
#ifdef ROM_SysTickPeriodSet
#define MAP_SysTickPeriodSet                                                  \
        ROM_SysTickPeriodSet
#else
#define MAP_SysTickPeriodSet                                                  \
        SysTickPeriodSet
#endif
#ifdef ROM_SysTickPeriodGet
#define MAP_SysTickPeriodGet                                                  \
        ROM_SysTickPeriodGet
#else
#define MAP_SysTickPeriodGet                                                  \
        SysTickPeriodGet
#endif

//*****************************************************************************
//
// Macros for the Timer API.
//
//*****************************************************************************
#ifdef ROM_TimerIntClear
#define MAP_TimerIntClear                                                     \
        ROM_TimerIntClear
#else
#define MAP_TimerIntClear                                                     \
        TimerIntClear
#endif
#ifdef ROM_TimerEnable
#define MAP_TimerEnable                                                       \
        ROM_TimerEnable
#else
#define MAP_TimerEnable                                                       \
        TimerEnable
#endif
#ifdef ROM_TimerDisable
#define MAP_TimerDisable                                                      \
        ROM_TimerDisable
#else
#define MAP_TimerDisable                                                      \
        TimerDisable
#endif
#ifdef ROM_TimerConfigure
#define MAP_TimerConfigure                                                    \
        ROM_TimerConfigure
#else
#define MAP_TimerConfigure                                                    \
        TimerConfigure
#endif
#ifdef ROM_TimerControlLevel
#define MAP_TimerControlLevel                                                 \
        ROM_TimerControlLevel
#else
#define MAP_TimerControlLevel                                                 \
        TimerControlLevel
#endif
#ifdef ROM_TimerControlTrigger
#define MAP_TimerControlTrigger                                               \
        ROM_TimerControlTrigger
#else
#define MAP_TimerControlTrigger                                               \
        TimerControlTrigger
#endif
#ifdef ROM_TimerControlEvent
#define MAP_TimerControlEvent                                                 \
        ROM_TimerControlEvent
#else
#define MAP_TimerControlEvent                                                 \
        TimerControlEvent
#endif
#ifdef ROM_TimerControlStall
#define MAP_TimerControlStall                                                 \
        ROM_TimerControlStall
#else
#define MAP_TimerControlStall                                                 \
        TimerControlStall
#endif
#ifdef ROM_TimerRTCEnable
#define MAP_TimerRTCEnable                                                    \
        ROM_TimerRTCEnable
#else
#define MAP_TimerRTCEnable                                                    \
        TimerRTCEnable
#endif
#ifdef ROM_TimerRTCDisable
#define MAP_TimerRTCDisable                                                   \
        ROM_TimerRTCDisable
#else
#define MAP_TimerRTCDisable                                                   \
        TimerRTCDisable
#endif
#ifdef ROM_TimerPrescaleSet
#define MAP_TimerPrescaleSet                                                  \
        ROM_TimerPrescaleSet
#else
#define MAP_TimerPrescaleSet                                                  \
        TimerPrescaleSet
#endif
#ifdef ROM_TimerPrescaleGet
#define MAP_TimerPrescaleGet                                                  \
        ROM_TimerPrescaleGet
#else
#define MAP_TimerPrescaleGet                                                  \
        TimerPrescaleGet
#endif
#ifdef ROM_TimerPrescaleMatchSet
#define MAP_TimerPrescaleMatchSet                                             \
        ROM_TimerPrescaleMatchSet
#else
#define MAP_TimerPrescaleMatchSet                                             \
        TimerPrescaleMatchSet
#endif
#ifdef ROM_TimerPrescaleMatchGet
#define MAP_TimerPrescaleMatchGet                                             \
        ROM_TimerPrescaleMatchGet
#else
#define MAP_TimerPrescaleMatchGet                                             \
        TimerPrescaleMatchGet
#endif
#ifdef ROM_TimerLoadSet
#define MAP_TimerLoadSet                                                      \
        ROM_TimerLoadSet
#else
#define MAP_TimerLoadSet                                                      \
        TimerLoadSet
#endif
#ifdef ROM_TimerLoadGet
#define MAP_TimerLoadGet                                                      \
        ROM_TimerLoadGet
#else
#define MAP_TimerLoadGet                                                      \
        TimerLoadGet
#endif
#ifdef ROM_TimerValueGet
#define MAP_TimerValueGet                                                     \
        ROM_TimerValueGet
#else
#define MAP_TimerValueGet                                                     \
        TimerValueGet
#endif
#ifdef ROM_TimerMatchSet
#define MAP_TimerMatchSet                                                     \
        ROM_TimerMatchSet
#else
#define MAP_TimerMatchSet                                                     \
        TimerMatchSet
#endif
#ifdef ROM_TimerMatchGet
#define MAP_TimerMatchGet                                                     \
        ROM_TimerMatchGet
#else
#define MAP_TimerMatchGet                                                     \
        TimerMatchGet
#endif
#ifdef ROM_TimerIntEnable
#define MAP_TimerIntEnable                                                    \
        ROM_TimerIntEnable
#else
#define MAP_TimerIntEnable                                                    \
        TimerIntEnable
#endif
#ifdef ROM_TimerIntDisable
#define MAP_TimerIntDisable                                                   \
        ROM_TimerIntDisable
#else
#define MAP_TimerIntDisable                                                   \
        TimerIntDisable
#endif
#ifdef ROM_TimerIntStatus
#define MAP_TimerIntStatus                                                    \
        ROM_TimerIntStatus
#else
#define MAP_TimerIntStatus                                                    \
        TimerIntStatus
#endif
#ifdef ROM_TimerControlWaitOnTrigger
#define MAP_TimerControlWaitOnTrigger                                         \
        ROM_TimerControlWaitOnTrigger
#else
#define MAP_TimerControlWaitOnTrigger                                         \
        TimerControlWaitOnTrigger
#endif
#ifdef ROM_TimerLoadSet64
#define MAP_TimerLoadSet64                                                    \
        ROM_TimerLoadSet64
#else
#define MAP_TimerLoadSet64                                                    \
        TimerLoadSet64
#endif
#ifdef ROM_TimerLoadGet64
#define MAP_TimerLoadGet64                                                    \
        ROM_TimerLoadGet64
#else
#define MAP_TimerLoadGet64                                                    \
        TimerLoadGet64
#endif
#ifdef ROM_TimerValueGet64
#define MAP_TimerValueGet64                                                   \
        ROM_TimerValueGet64
#else
#define MAP_TimerValueGet64                                                   \
        TimerValueGet64
#endif
#ifdef ROM_TimerMatchSet64
#define MAP_TimerMatchSet64                                                   \
        ROM_TimerMatchSet64
#else
#define MAP_TimerMatchSet64                                                   \
        TimerMatchSet64
#endif
#ifdef ROM_TimerMatchGet64
#define MAP_TimerMatchGet64                                                   \
        ROM_TimerMatchGet64
#else
#define MAP_TimerMatchGet64                                                   \
        TimerMatchGet64
#endif
#ifdef ROM_TimerClockSourceGet
#define MAP_TimerClockSourceGet                                               \
        ROM_TimerClockSourceGet
#else
#define MAP_TimerClockSourceGet                                               \
        TimerClockSourceGet
#endif
#ifdef ROM_TimerClockSourceSet
#define MAP_TimerClockSourceSet                                               \
        ROM_TimerClockSourceSet
#else
#define MAP_TimerClockSourceSet                                               \
        TimerClockSourceSet
#endif
#ifdef ROM_TimerADCEventGet
#define MAP_TimerADCEventGet                                                  \
        ROM_TimerADCEventGet
#else
#define MAP_TimerADCEventGet                                                  \
        TimerADCEventGet
#endif
#ifdef ROM_TimerADCEventSet
#define MAP_TimerADCEventSet                                                  \
        ROM_TimerADCEventSet
#else
#define MAP_TimerADCEventSet                                                  \
        TimerADCEventSet
#endif
#ifdef ROM_TimerDMAEventGet
#define MAP_TimerDMAEventGet                                                  \
        ROM_TimerDMAEventGet
#else
#define MAP_TimerDMAEventGet                                                  \
        TimerDMAEventGet
#endif
#ifdef ROM_TimerDMAEventSet
#define MAP_TimerDMAEventSet                                                  \
        ROM_TimerDMAEventSet
#else
#define MAP_TimerDMAEventSet                                                  \
        TimerDMAEventSet
#endif
#ifdef ROM_TimerSynchronize
#define MAP_TimerSynchronize                                                  \
        ROM_TimerSynchronize
#else
#define MAP_TimerSynchronize                                                  \
        TimerSynchronize
#endif

//*****************************************************************************
//
// Macros for the UART API.
//
//*****************************************************************************
#ifdef ROM_UARTCharPut
#define MAP_UARTCharPut                                                       \
        ROM_UARTCharPut
#else
#define MAP_UARTCharPut                                                       \
        UARTCharPut
#endif
#ifdef ROM_UARTParityModeSet
#define MAP_UARTParityModeSet                                                 \
        ROM_UARTParityModeSet
#else
#define MAP_UARTParityModeSet                                                 \
        UARTParityModeSet
#endif
#ifdef ROM_UARTParityModeGet
#define MAP_UARTParityModeGet                                                 \
        ROM_UARTParityModeGet
#else
#define MAP_UARTParityModeGet                                                 \
        UARTParityModeGet
#endif
#ifdef ROM_UARTFIFOLevelSet
#define MAP_UARTFIFOLevelSet                                                  \
        ROM_UARTFIFOLevelSet
#else
#define MAP_UARTFIFOLevelSet                                                  \
        UARTFIFOLevelSet
#endif
#ifdef ROM_UARTFIFOLevelGet
#define MAP_UARTFIFOLevelGet                                                  \
        ROM_UARTFIFOLevelGet
#else
#define MAP_UARTFIFOLevelGet                                                  \
        UARTFIFOLevelGet
#endif
#ifdef ROM_UARTConfigSetExpClk
#define MAP_UARTConfigSetExpClk                                               \
        ROM_UARTConfigSetExpClk
#else
#define MAP_UARTConfigSetExpClk                                               \
        UARTConfigSetExpClk
#endif
#ifdef ROM_UARTConfigGetExpClk
#define MAP_UARTConfigGetExpClk                                               \
        ROM_UARTConfigGetExpClk
#else
#define MAP_UARTConfigGetExpClk                                               \
        UARTConfigGetExpClk
#endif
#ifdef ROM_UARTEnable
#define MAP_UARTEnable                                                        \
        ROM_UARTEnable
#else
#define MAP_UARTEnable                                                        \
        UARTEnable
#endif
#ifdef ROM_UARTDisable
#define MAP_UARTDisable                                                       \
        ROM_UARTDisable
#else
#define MAP_UARTDisable                                                       \
        UARTDisable
#endif
#ifdef ROM_UARTEnableSIR
#define MAP_UARTEnableSIR                                                     \
        ROM_UARTEnableSIR
#else
#define MAP_UARTEnableSIR                                                     \
        UARTEnableSIR
#endif
#ifdef ROM_UARTDisableSIR
#define MAP_UARTDisableSIR                                                    \
        ROM_UARTDisableSIR
#else
#define MAP_UARTDisableSIR                                                    \
        UARTDisableSIR
#endif
#ifdef ROM_UARTCharsAvail
#define MAP_UARTCharsAvail                                                    \
        ROM_UARTCharsAvail
#else
#define MAP_UARTCharsAvail                                                    \
        UARTCharsAvail
#endif
#ifdef ROM_UARTSpaceAvail
#define MAP_UARTSpaceAvail                                                    \
        ROM_UARTSpaceAvail
#else
#define MAP_UARTSpaceAvail                                                    \
        UARTSpaceAvail
#endif
#ifdef ROM_UARTCharGetNonBlocking
#define MAP_UARTCharGetNonBlocking                                            \
        ROM_UARTCharGetNonBlocking
#else
#define MAP_UARTCharGetNonBlocking                                            \
        UARTCharGetNonBlocking
#endif
#ifdef ROM_UARTCharGet
#define MAP_UARTCharGet                                                       \
        ROM_UARTCharGet
#else
#define MAP_UARTCharGet                                                       \
        UARTCharGet
#endif
#ifdef ROM_UARTCharPutNonBlocking
#define MAP_UARTCharPutNonBlocking                                            \
        ROM_UARTCharPutNonBlocking
#else
#define MAP_UARTCharPutNonBlocking                                            \
        UARTCharPutNonBlocking
#endif
#ifdef ROM_UARTBreakCtl
#define MAP_UARTBreakCtl                                                      \
        ROM_UARTBreakCtl
#else
#define MAP_UARTBreakCtl                                                      \
        UARTBreakCtl
#endif
#ifdef ROM_UARTIntEnable
#define MAP_UARTIntEnable                                                     \
        ROM_UARTIntEnable
#else
#define MAP_UARTIntEnable                                                     \
        UARTIntEnable
#endif
#ifdef ROM_UARTIntDisable
#define MAP_UARTIntDisable                                                    \
        ROM_UARTIntDisable
#else
#define MAP_UARTIntDisable                                                    \
        UARTIntDisable
#endif
#ifdef ROM_UARTIntStatus
#define MAP_UARTIntStatus                                                     \
        ROM_UARTIntStatus
#else
#define MAP_UARTIntStatus                                                     \
        UARTIntStatus
#endif
#ifdef ROM_UARTIntClear
#define MAP_UARTIntClear                                                      \
        ROM_UARTIntClear
#else
#define MAP_UARTIntClear                                                      \
        UARTIntClear
#endif
#ifdef ROM_UARTDMAEnable
#define MAP_UARTDMAEnable                                                     \
        ROM_UARTDMAEnable
#else
#define MAP_UARTDMAEnable                                                     \
        UARTDMAEnable
#endif
#ifdef ROM_UARTDMADisable
#define MAP_UARTDMADisable                                                    \
        ROM_UARTDMADisable
#else
#define MAP_UARTDMADisable                                                    \
        UARTDMADisable
#endif
#ifdef ROM_UARTFIFOEnable
#define MAP_UARTFIFOEnable                                                    \
        ROM_UARTFIFOEnable
#else
#define MAP_UARTFIFOEnable                                                    \
        UARTFIFOEnable
#endif
#ifdef ROM_UARTFIFODisable
#define MAP_UARTFIFODisable                                                   \
        ROM_UARTFIFODisable
#else
#define MAP_UARTFIFODisable                                                   \
        UARTFIFODisable
#endif
#ifdef ROM_UARTBusy
#define MAP_UARTBusy                                                          \
        ROM_UARTBusy
#else
#define MAP_UARTBusy                                                          \
        UARTBusy
#endif
#ifdef ROM_UARTTxIntModeSet
#define MAP_UARTTxIntModeSet                                                  \
        ROM_UARTTxIntModeSet
#else
#define MAP_UARTTxIntModeSet                                                  \
        UARTTxIntModeSet
#endif
#ifdef ROM_UARTTxIntModeGet
#define MAP_UARTTxIntModeGet                                                  \
        ROM_UARTTxIntModeGet
#else
#define MAP_UARTTxIntModeGet                                                  \
        UARTTxIntModeGet
#endif
#ifdef ROM_UARTRxErrorGet
#define MAP_UARTRxErrorGet                                                    \
        ROM_UARTRxErrorGet
#else
#define MAP_UARTRxErrorGet                                                    \
        UARTRxErrorGet
#endif
#ifdef ROM_UARTRxErrorClear
#define MAP_UARTRxErrorClear                                                  \
        ROM_UARTRxErrorClear
#else
#define MAP_UARTRxErrorClear                                                  \
        UARTRxErrorClear
#endif
#ifdef ROM_UARTClockSourceSet
#define MAP_UARTClockSourceSet                                                \
        ROM_UARTClockSourceSet
#else
#define MAP_UARTClockSourceSet                                                \
        UARTClockSourceSet
#endif
#ifdef ROM_UARTClockSourceGet
#define MAP_UARTClockSourceGet                                                \
        ROM_UARTClockSourceGet
#else
#define MAP_UARTClockSourceGet                                                \
        UARTClockSourceGet
#endif
#ifdef ROM_UART9BitEnable
#define MAP_UART9BitEnable                                                    \
        ROM_UART9BitEnable
#else
#define MAP_UART9BitEnable                                                    \
        UART9BitEnable
#endif
#ifdef ROM_UART9BitDisable
#define MAP_UART9BitDisable                                                   \
        ROM_UART9BitDisable
#else
#define MAP_UART9BitDisable                                                   \
        UART9BitDisable
#endif
#ifdef ROM_UART9BitAddrSet
#define MAP_UART9BitAddrSet                                                   \
        ROM_UART9BitAddrSet
#else
#define MAP_UART9BitAddrSet                                                   \
        UART9BitAddrSet
#endif
#ifdef ROM_UART9BitAddrSend
#define MAP_UART9BitAddrSend                                                  \
        ROM_UART9BitAddrSend
#else
#define MAP_UART9BitAddrSend                                                  \
        UART9BitAddrSend
#endif
#ifdef ROM_UARTSmartCardDisable
#define MAP_UARTSmartCardDisable                                              \
        ROM_UARTSmartCardDisable
#else
#define MAP_UARTSmartCardDisable                                              \
        UARTSmartCardDisable
#endif
#ifdef ROM_UARTSmartCardEnable
#define MAP_UARTSmartCardEnable                                               \
        ROM_UARTSmartCardEnable
#else
#define MAP_UARTSmartCardEnable                                               \
        UARTSmartCardEnable
#endif
#ifdef ROM_UARTModemControlClear
#define MAP_UARTModemControlClear                                             \
        ROM_UARTModemControlClear
#else
#define MAP_UARTModemControlClear                                             \
        UARTModemControlClear
#endif
#ifdef ROM_UARTModemControlGet
#define MAP_UARTModemControlGet                                               \
        ROM_UARTModemControlGet
#else
#define MAP_UARTModemControlGet                                               \
        UARTModemControlGet
#endif
#ifdef ROM_UARTModemControlSet
#define MAP_UARTModemControlSet                                               \
        ROM_UARTModemControlSet
#else
#define MAP_UARTModemControlSet                                               \
        UARTModemControlSet
#endif
#ifdef ROM_UARTModemStatusGet
#define MAP_UARTModemStatusGet                                                \
        ROM_UARTModemStatusGet
#else
#define MAP_UARTModemStatusGet                                                \
        UARTModemStatusGet
#endif
#ifdef ROM_UARTFlowControlGet
#define MAP_UARTFlowControlGet                                                \
        ROM_UARTFlowControlGet
#else
#define MAP_UARTFlowControlGet                                                \
        UARTFlowControlGet
#endif
#ifdef ROM_UARTFlowControlSet
#define MAP_UARTFlowControlSet                                                \
        ROM_UARTFlowControlSet
#else
#define MAP_UARTFlowControlSet                                                \
        UARTFlowControlSet
#endif

//*****************************************************************************
//
// Macros for the uDMA API.
//
//*****************************************************************************
#ifdef ROM_uDMAChannelTransferSet
#define MAP_uDMAChannelTransferSet                                            \
        ROM_uDMAChannelTransferSet
#else
#define MAP_uDMAChannelTransferSet                                            \
        uDMAChannelTransferSet
#endif
#ifdef ROM_uDMAEnable
#define MAP_uDMAEnable                                                        \
        ROM_uDMAEnable
#else
#define MAP_uDMAEnable                                                        \
        uDMAEnable
#endif
#ifdef ROM_uDMADisable
#define MAP_uDMADisable                                                       \
        ROM_uDMADisable
#else
#define MAP_uDMADisable                                                       \
        uDMADisable
#endif
#ifdef ROM_uDMAErrorStatusGet
#define MAP_uDMAErrorStatusGet                                                \
        ROM_uDMAErrorStatusGet
#else
#define MAP_uDMAErrorStatusGet                                                \
        uDMAErrorStatusGet
#endif
#ifdef ROM_uDMAErrorStatusClear
#define MAP_uDMAErrorStatusClear                                              \
        ROM_uDMAErrorStatusClear
#else
#define MAP_uDMAErrorStatusClear                                              \
        uDMAErrorStatusClear
#endif
#ifdef ROM_uDMAChannelEnable
#define MAP_uDMAChannelEnable                                                 \
        ROM_uDMAChannelEnable
#else
#define MAP_uDMAChannelEnable                                                 \
        uDMAChannelEnable
#endif
#ifdef ROM_uDMAChannelDisable
#define MAP_uDMAChannelDisable                                                \
        ROM_uDMAChannelDisable
#else
#define MAP_uDMAChannelDisable                                                \
        uDMAChannelDisable
#endif
#ifdef ROM_uDMAChannelIsEnabled
#define MAP_uDMAChannelIsEnabled                                              \
        ROM_uDMAChannelIsEnabled
#else
#define MAP_uDMAChannelIsEnabled                                              \
        uDMAChannelIsEnabled
#endif
#ifdef ROM_uDMAControlBaseSet
#define MAP_uDMAControlBaseSet                                                \
        ROM_uDMAControlBaseSet
#else
#define MAP_uDMAControlBaseSet                                                \
        uDMAControlBaseSet
#endif
#ifdef ROM_uDMAControlBaseGet
#define MAP_uDMAControlBaseGet                                                \
        ROM_uDMAControlBaseGet
#else
#define MAP_uDMAControlBaseGet                                                \
        uDMAControlBaseGet
#endif
#ifdef ROM_uDMAChannelRequest
#define MAP_uDMAChannelRequest                                                \
        ROM_uDMAChannelRequest
#else
#define MAP_uDMAChannelRequest                                                \
        uDMAChannelRequest
#endif
#ifdef ROM_uDMAChannelAttributeEnable
#define MAP_uDMAChannelAttributeEnable                                        \
        ROM_uDMAChannelAttributeEnable
#else
#define MAP_uDMAChannelAttributeEnable                                        \
        uDMAChannelAttributeEnable
#endif
#ifdef ROM_uDMAChannelAttributeDisable
#define MAP_uDMAChannelAttributeDisable                                       \
        ROM_uDMAChannelAttributeDisable
#else
#define MAP_uDMAChannelAttributeDisable                                       \
        uDMAChannelAttributeDisable
#endif
#ifdef ROM_uDMAChannelAttributeGet
#define MAP_uDMAChannelAttributeGet                                           \
        ROM_uDMAChannelAttributeGet
#else
#define MAP_uDMAChannelAttributeGet                                           \
        uDMAChannelAttributeGet
#endif
#ifdef ROM_uDMAChannelControlSet
#define MAP_uDMAChannelControlSet                                             \
        ROM_uDMAChannelControlSet
#else
#define MAP_uDMAChannelControlSet                                             \
        uDMAChannelControlSet
#endif
#ifdef ROM_uDMAChannelSizeGet
#define MAP_uDMAChannelSizeGet                                                \
        ROM_uDMAChannelSizeGet
#else
#define MAP_uDMAChannelSizeGet                                                \
        uDMAChannelSizeGet
#endif
#ifdef ROM_uDMAChannelModeGet
#define MAP_uDMAChannelModeGet                                                \
        ROM_uDMAChannelModeGet
#else
#define MAP_uDMAChannelModeGet                                                \
        uDMAChannelModeGet
#endif
#ifdef ROM_uDMAChannelSelectSecondary
#define MAP_uDMAChannelSelectSecondary                                        \
        ROM_uDMAChannelSelectSecondary
#else
#define MAP_uDMAChannelSelectSecondary                                        \
        uDMAChannelSelectSecondary
#endif
#ifdef ROM_uDMAChannelSelectDefault
#define MAP_uDMAChannelSelectDefault                                          \
        ROM_uDMAChannelSelectDefault
#else
#define MAP_uDMAChannelSelectDefault                                          \
        uDMAChannelSelectDefault
#endif
#ifdef ROM_uDMAIntStatus
#define MAP_uDMAIntStatus                                                     \
        ROM_uDMAIntStatus
#else
#define MAP_uDMAIntStatus                                                     \
        uDMAIntStatus
#endif
#ifdef ROM_uDMAIntClear
#define MAP_uDMAIntClear                                                      \
        ROM_uDMAIntClear
#else
#define MAP_uDMAIntClear                                                      \
        uDMAIntClear
#endif
#ifdef ROM_uDMAControlAlternateBaseGet
#define MAP_uDMAControlAlternateBaseGet                                       \
        ROM_uDMAControlAlternateBaseGet
#else
#define MAP_uDMAControlAlternateBaseGet                                       \
        uDMAControlAlternateBaseGet
#endif
#ifdef ROM_uDMAChannelScatterGatherSet
#define MAP_uDMAChannelScatterGatherSet                                       \
        ROM_uDMAChannelScatterGatherSet
#else
#define MAP_uDMAChannelScatterGatherSet                                       \
        uDMAChannelScatterGatherSet
#endif
#ifdef ROM_uDMAChannelAssign
#define MAP_uDMAChannelAssign                                                 \
        ROM_uDMAChannelAssign
#else
#define MAP_uDMAChannelAssign                                                 \
        uDMAChannelAssign
#endif

//*****************************************************************************
//
// Macros for the USB API.
//
//*****************************************************************************
#ifdef ROM_USBDevAddrGet
#define MAP_USBDevAddrGet                                                     \
        ROM_USBDevAddrGet
#else
#define MAP_USBDevAddrGet                                                     \
        USBDevAddrGet
#endif
#ifdef ROM_USBDevAddrSet
#define MAP_USBDevAddrSet                                                     \
        ROM_USBDevAddrSet
#else
#define MAP_USBDevAddrSet                                                     \
        USBDevAddrSet
#endif
#ifdef ROM_USBDevConnect
#define MAP_USBDevConnect                                                     \
        ROM_USBDevConnect
#else
#define MAP_USBDevConnect                                                     \
        USBDevConnect
#endif
#ifdef ROM_USBDevDisconnect
#define MAP_USBDevDisconnect                                                  \
        ROM_USBDevDisconnect
#else
#define MAP_USBDevDisconnect                                                  \
        USBDevDisconnect
#endif
#ifdef ROM_USBDevEndpointConfigSet
#define MAP_USBDevEndpointConfigSet                                           \
        ROM_USBDevEndpointConfigSet
#else
#define MAP_USBDevEndpointConfigSet                                           \
        USBDevEndpointConfigSet
#endif
#ifdef ROM_USBDevEndpointDataAck
#define MAP_USBDevEndpointDataAck                                             \
        ROM_USBDevEndpointDataAck
#else
#define MAP_USBDevEndpointDataAck                                             \
        USBDevEndpointDataAck
#endif
#ifdef ROM_USBDevEndpointStall
#define MAP_USBDevEndpointStall                                               \
        ROM_USBDevEndpointStall
#else
#define MAP_USBDevEndpointStall                                               \
        USBDevEndpointStall
#endif
#ifdef ROM_USBDevEndpointStallClear
#define MAP_USBDevEndpointStallClear                                          \
        ROM_USBDevEndpointStallClear
#else
#define MAP_USBDevEndpointStallClear                                          \
        USBDevEndpointStallClear
#endif
#ifdef ROM_USBDevEndpointStatusClear
#define MAP_USBDevEndpointStatusClear                                         \
        ROM_USBDevEndpointStatusClear
#else
#define MAP_USBDevEndpointStatusClear                                         \
        USBDevEndpointStatusClear
#endif
#ifdef ROM_USBEndpointDataGet
#define MAP_USBEndpointDataGet                                                \
        ROM_USBEndpointDataGet
#else
#define MAP_USBEndpointDataGet                                                \
        USBEndpointDataGet
#endif
#ifdef ROM_USBEndpointDataPut
#define MAP_USBEndpointDataPut                                                \
        ROM_USBEndpointDataPut
#else
#define MAP_USBEndpointDataPut                                                \
        USBEndpointDataPut
#endif
#ifdef ROM_USBEndpointDataSend
#define MAP_USBEndpointDataSend                                               \
        ROM_USBEndpointDataSend
#else
#define MAP_USBEndpointDataSend                                               \
        USBEndpointDataSend
#endif
#ifdef ROM_USBEndpointDataToggleClear
#define MAP_USBEndpointDataToggleClear                                        \
        ROM_USBEndpointDataToggleClear
#else
#define MAP_USBEndpointDataToggleClear                                        \
        USBEndpointDataToggleClear
#endif
#ifdef ROM_USBEndpointStatus
#define MAP_USBEndpointStatus                                                 \
        ROM_USBEndpointStatus
#else
#define MAP_USBEndpointStatus                                                 \
        USBEndpointStatus
#endif
#ifdef ROM_USBFIFOAddrGet
#define MAP_USBFIFOAddrGet                                                    \
        ROM_USBFIFOAddrGet
#else
#define MAP_USBFIFOAddrGet                                                    \
        USBFIFOAddrGet
#endif
#ifdef ROM_USBFIFOConfigGet
#define MAP_USBFIFOConfigGet                                                  \
        ROM_USBFIFOConfigGet
#else
#define MAP_USBFIFOConfigGet                                                  \
        USBFIFOConfigGet
#endif
#ifdef ROM_USBFIFOConfigSet
#define MAP_USBFIFOConfigSet                                                  \
        ROM_USBFIFOConfigSet
#else
#define MAP_USBFIFOConfigSet                                                  \
        USBFIFOConfigSet
#endif
#ifdef ROM_USBFIFOFlush
#define MAP_USBFIFOFlush                                                      \
        ROM_USBFIFOFlush
#else
#define MAP_USBFIFOFlush                                                      \
        USBFIFOFlush
#endif
#ifdef ROM_USBFrameNumberGet
#define MAP_USBFrameNumberGet                                                 \
        ROM_USBFrameNumberGet
#else
#define MAP_USBFrameNumberGet                                                 \
        USBFrameNumberGet
#endif
#ifdef ROM_USBHostAddrGet
#define MAP_USBHostAddrGet                                                    \
        ROM_USBHostAddrGet
#else
#define MAP_USBHostAddrGet                                                    \
        USBHostAddrGet
#endif
#ifdef ROM_USBHostAddrSet
#define MAP_USBHostAddrSet                                                    \
        ROM_USBHostAddrSet
#else
#define MAP_USBHostAddrSet                                                    \
        USBHostAddrSet
#endif
#ifdef ROM_USBHostEndpointConfig
#define MAP_USBHostEndpointConfig                                             \
        ROM_USBHostEndpointConfig
#else
#define MAP_USBHostEndpointConfig                                             \
        USBHostEndpointConfig
#endif
#ifdef ROM_USBHostEndpointDataAck
#define MAP_USBHostEndpointDataAck                                            \
        ROM_USBHostEndpointDataAck
#else
#define MAP_USBHostEndpointDataAck                                            \
        USBHostEndpointDataAck
#endif
#ifdef ROM_USBHostEndpointDataToggle
#define MAP_USBHostEndpointDataToggle                                         \
        ROM_USBHostEndpointDataToggle
#else
#define MAP_USBHostEndpointDataToggle                                         \
        USBHostEndpointDataToggle
#endif
#ifdef ROM_USBHostEndpointStatusClear
#define MAP_USBHostEndpointStatusClear                                        \
        ROM_USBHostEndpointStatusClear
#else
#define MAP_USBHostEndpointStatusClear                                        \
        USBHostEndpointStatusClear
#endif
#ifdef ROM_USBHostHubAddrGet
#define MAP_USBHostHubAddrGet                                                 \
        ROM_USBHostHubAddrGet
#else
#define MAP_USBHostHubAddrGet                                                 \
        USBHostHubAddrGet
#endif
#ifdef ROM_USBHostHubAddrSet
#define MAP_USBHostHubAddrSet                                                 \
        ROM_USBHostHubAddrSet
#else
#define MAP_USBHostHubAddrSet                                                 \
        USBHostHubAddrSet
#endif
#ifdef ROM_USBHostPwrDisable
#define MAP_USBHostPwrDisable                                                 \
        ROM_USBHostPwrDisable
#else
#define MAP_USBHostPwrDisable                                                 \
        USBHostPwrDisable
#endif
#ifdef ROM_USBHostPwrEnable
#define MAP_USBHostPwrEnable                                                  \
        ROM_USBHostPwrEnable
#else
#define MAP_USBHostPwrEnable                                                  \
        USBHostPwrEnable
#endif
#ifdef ROM_USBHostPwrConfig
#define MAP_USBHostPwrConfig                                                  \
        ROM_USBHostPwrConfig
#else
#define MAP_USBHostPwrConfig                                                  \
        USBHostPwrConfig
#endif
#ifdef ROM_USBHostPwrFaultDisable
#define MAP_USBHostPwrFaultDisable                                            \
        ROM_USBHostPwrFaultDisable
#else
#define MAP_USBHostPwrFaultDisable                                            \
        USBHostPwrFaultDisable
#endif
#ifdef ROM_USBHostPwrFaultEnable
#define MAP_USBHostPwrFaultEnable                                             \
        ROM_USBHostPwrFaultEnable
#else
#define MAP_USBHostPwrFaultEnable                                             \
        USBHostPwrFaultEnable
#endif
#ifdef ROM_USBHostRequestIN
#define MAP_USBHostRequestIN                                                  \
        ROM_USBHostRequestIN
#else
#define MAP_USBHostRequestIN                                                  \
        USBHostRequestIN
#endif
#ifdef ROM_USBHostRequestStatus
#define MAP_USBHostRequestStatus                                              \
        ROM_USBHostRequestStatus
#else
#define MAP_USBHostRequestStatus                                              \
        USBHostRequestStatus
#endif
#ifdef ROM_USBHostReset
#define MAP_USBHostReset                                                      \
        ROM_USBHostReset
#else
#define MAP_USBHostReset                                                      \
        USBHostReset
#endif
#ifdef ROM_USBHostResume
#define MAP_USBHostResume                                                     \
        ROM_USBHostResume
#else
#define MAP_USBHostResume                                                     \
        USBHostResume
#endif
#ifdef ROM_USBHostSpeedGet
#define MAP_USBHostSpeedGet                                                   \
        ROM_USBHostSpeedGet
#else
#define MAP_USBHostSpeedGet                                                   \
        USBHostSpeedGet
#endif
#ifdef ROM_USBHostSuspend
#define MAP_USBHostSuspend                                                    \
        ROM_USBHostSuspend
#else
#define MAP_USBHostSuspend                                                    \
        USBHostSuspend
#endif
#ifdef ROM_USBDevEndpointConfigGet
#define MAP_USBDevEndpointConfigGet                                           \
        ROM_USBDevEndpointConfigGet
#else
#define MAP_USBDevEndpointConfigGet                                           \
        USBDevEndpointConfigGet
#endif
#ifdef ROM_USBEndpointDMAEnable
#define MAP_USBEndpointDMAEnable                                              \
        ROM_USBEndpointDMAEnable
#else
#define MAP_USBEndpointDMAEnable                                              \
        USBEndpointDMAEnable
#endif
#ifdef ROM_USBEndpointDMADisable
#define MAP_USBEndpointDMADisable                                             \
        ROM_USBEndpointDMADisable
#else
#define MAP_USBEndpointDMADisable                                             \
        USBEndpointDMADisable
#endif
#ifdef ROM_USBEndpointDataAvail
#define MAP_USBEndpointDataAvail                                              \
        ROM_USBEndpointDataAvail
#else
#define MAP_USBEndpointDataAvail                                              \
        USBEndpointDataAvail
#endif
#ifdef ROM_USBModeGet
#define MAP_USBModeGet                                                        \
        ROM_USBModeGet
#else
#define MAP_USBModeGet                                                        \
        USBModeGet
#endif
#ifdef ROM_USBEndpointDMAChannel
#define MAP_USBEndpointDMAChannel                                             \
        ROM_USBEndpointDMAChannel
#else
#define MAP_USBEndpointDMAChannel                                             \
        USBEndpointDMAChannel
#endif
#ifdef ROM_USBIntDisableControl
#define MAP_USBIntDisableControl                                              \
        ROM_USBIntDisableControl
#else
#define MAP_USBIntDisableControl                                              \
        USBIntDisableControl
#endif
#ifdef ROM_USBIntEnableControl
#define MAP_USBIntEnableControl                                               \
        ROM_USBIntEnableControl
#else
#define MAP_USBIntEnableControl                                               \
        USBIntEnableControl
#endif
#ifdef ROM_USBIntStatusControl
#define MAP_USBIntStatusControl                                               \
        ROM_USBIntStatusControl
#else
#define MAP_USBIntStatusControl                                               \
        USBIntStatusControl
#endif
#ifdef ROM_USBIntDisableEndpoint
#define MAP_USBIntDisableEndpoint                                             \
        ROM_USBIntDisableEndpoint
#else
#define MAP_USBIntDisableEndpoint                                             \
        USBIntDisableEndpoint
#endif
#ifdef ROM_USBIntEnableEndpoint
#define MAP_USBIntEnableEndpoint                                              \
        ROM_USBIntEnableEndpoint
#else
#define MAP_USBIntEnableEndpoint                                              \
        USBIntEnableEndpoint
#endif
#ifdef ROM_USBIntStatusEndpoint
#define MAP_USBIntStatusEndpoint                                              \
        ROM_USBIntStatusEndpoint
#else
#define MAP_USBIntStatusEndpoint                                              \
        USBIntStatusEndpoint
#endif
#ifdef ROM_USBHostMode
#define MAP_USBHostMode                                                       \
        ROM_USBHostMode
#else
#define MAP_USBHostMode                                                       \
        USBHostMode
#endif
#ifdef ROM_USBDevMode
#define MAP_USBDevMode                                                        \
        ROM_USBDevMode
#else
#define MAP_USBDevMode                                                        \
        USBDevMode
#endif
#ifdef ROM_USBPHYPowerOff
#define MAP_USBPHYPowerOff                                                    \
        ROM_USBPHYPowerOff
#else
#define MAP_USBPHYPowerOff                                                    \
        USBPHYPowerOff
#endif
#ifdef ROM_USBPHYPowerOn
#define MAP_USBPHYPowerOn                                                     \
        ROM_USBPHYPowerOn
#else
#define MAP_USBPHYPowerOn                                                     \
        USBPHYPowerOn
#endif
#ifdef ROM_USBOTGMode
#define MAP_USBOTGMode                                                        \
        ROM_USBOTGMode
#else
#define MAP_USBOTGMode                                                        \
        USBOTGMode
#endif
#ifdef ROM_USBHostRequestINClear
#define MAP_USBHostRequestINClear                                             \
        ROM_USBHostRequestINClear
#else
#define MAP_USBHostRequestINClear                                             \
        USBHostRequestINClear
#endif
#ifdef ROM_USBNumEndpointsGet
#define MAP_USBNumEndpointsGet                                                \
        ROM_USBNumEndpointsGet
#else
#define MAP_USBNumEndpointsGet                                                \
        USBNumEndpointsGet
#endif
#ifdef ROM_USBClockDisable
#define MAP_USBClockDisable                                                   \
        ROM_USBClockDisable
#else
#define MAP_USBClockDisable                                                   \
        USBClockDisable
#endif
#ifdef ROM_USBClockEnable
#define MAP_USBClockEnable                                                    \
        ROM_USBClockEnable
#else
#define MAP_USBClockEnable                                                    \
        USBClockEnable
#endif
#ifdef ROM_USBControllerVersion
#define MAP_USBControllerVersion                                              \
        ROM_USBControllerVersion
#else
#define MAP_USBControllerVersion                                              \
        USBControllerVersion
#endif
#ifdef ROM_USBDevLPMConfig
#define MAP_USBDevLPMConfig                                                   \
        ROM_USBDevLPMConfig
#else
#define MAP_USBDevLPMConfig                                                   \
        USBDevLPMConfig
#endif
#ifdef ROM_USBDevLPMDisable
#define MAP_USBDevLPMDisable                                                  \
        ROM_USBDevLPMDisable
#else
#define MAP_USBDevLPMDisable                                                  \
        USBDevLPMDisable
#endif
#ifdef ROM_USBDevLPMEnable
#define MAP_USBDevLPMEnable                                                   \
        ROM_USBDevLPMEnable
#else
#define MAP_USBDevLPMEnable                                                   \
        USBDevLPMEnable
#endif
#ifdef ROM_USBDevLPMRemoteWake
#define MAP_USBDevLPMRemoteWake                                               \
        ROM_USBDevLPMRemoteWake
#else
#define MAP_USBDevLPMRemoteWake                                               \
        USBDevLPMRemoteWake
#endif
#ifdef ROM_USBDevSpeedGet
#define MAP_USBDevSpeedGet                                                    \
        ROM_USBDevSpeedGet
#else
#define MAP_USBDevSpeedGet                                                    \
        USBDevSpeedGet
#endif
#ifdef ROM_USBDMAChannelAddressGet
#define MAP_USBDMAChannelAddressGet                                           \
        ROM_USBDMAChannelAddressGet
#else
#define MAP_USBDMAChannelAddressGet                                           \
        USBDMAChannelAddressGet
#endif
#ifdef ROM_USBDMAChannelAddressSet
#define MAP_USBDMAChannelAddressSet                                           \
        ROM_USBDMAChannelAddressSet
#else
#define MAP_USBDMAChannelAddressSet                                           \
        USBDMAChannelAddressSet
#endif
#ifdef ROM_USBDMAChannelConfigSet
#define MAP_USBDMAChannelConfigSet                                            \
        ROM_USBDMAChannelConfigSet
#else
#define MAP_USBDMAChannelConfigSet                                            \
        USBDMAChannelConfigSet
#endif
#ifdef ROM_USBDMAChannelDisable
#define MAP_USBDMAChannelDisable                                              \
        ROM_USBDMAChannelDisable
#else
#define MAP_USBDMAChannelDisable                                              \
        USBDMAChannelDisable
#endif
#ifdef ROM_USBDMAChannelEnable
#define MAP_USBDMAChannelEnable                                               \
        ROM_USBDMAChannelEnable
#else
#define MAP_USBDMAChannelEnable                                               \
        USBDMAChannelEnable
#endif
#ifdef ROM_USBDMAChannelIntDisable
#define MAP_USBDMAChannelIntDisable                                           \
        ROM_USBDMAChannelIntDisable
#else
#define MAP_USBDMAChannelIntDisable                                           \
        USBDMAChannelIntDisable
#endif
#ifdef ROM_USBDMAChannelIntEnable
#define MAP_USBDMAChannelIntEnable                                            \
        ROM_USBDMAChannelIntEnable
#else
#define MAP_USBDMAChannelIntEnable                                            \
        USBDMAChannelIntEnable
#endif
#ifdef ROM_USBDMAChannelCountGet
#define MAP_USBDMAChannelCountGet                                             \
        ROM_USBDMAChannelCountGet
#else
#define MAP_USBDMAChannelCountGet                                             \
        USBDMAChannelCountGet
#endif
#ifdef ROM_USBDMAChannelCountSet
#define MAP_USBDMAChannelCountSet                                             \
        ROM_USBDMAChannelCountSet
#else
#define MAP_USBDMAChannelCountSet                                             \
        USBDMAChannelCountSet
#endif
#ifdef ROM_USBDMAChannelIntStatus
#define MAP_USBDMAChannelIntStatus                                            \
        ROM_USBDMAChannelIntStatus
#else
#define MAP_USBDMAChannelIntStatus                                            \
        USBDMAChannelIntStatus
#endif
#ifdef ROM_USBDMAChannelStatus
#define MAP_USBDMAChannelStatus                                               \
        ROM_USBDMAChannelStatus
#else
#define MAP_USBDMAChannelStatus                                               \
        USBDMAChannelStatus
#endif
#ifdef ROM_USBDMAChannelStatusClear
#define MAP_USBDMAChannelStatusClear                                          \
        ROM_USBDMAChannelStatusClear
#else
#define MAP_USBDMAChannelStatusClear                                          \
        USBDMAChannelStatusClear
#endif
#ifdef ROM_USBHighSpeed
#define MAP_USBHighSpeed                                                      \
        ROM_USBHighSpeed
#else
#define MAP_USBHighSpeed                                                      \
        USBHighSpeed
#endif
#ifdef ROM_USBHostEndpointPing
#define MAP_USBHostEndpointPing                                               \
        ROM_USBHostEndpointPing
#else
#define MAP_USBHostEndpointPing                                               \
        USBHostEndpointPing
#endif
#ifdef ROM_USBHostEndpointSpeed
#define MAP_USBHostEndpointSpeed                                              \
        ROM_USBHostEndpointSpeed
#else
#define MAP_USBHostEndpointSpeed                                              \
        USBHostEndpointSpeed
#endif
#ifdef ROM_USBHostLPMConfig
#define MAP_USBHostLPMConfig                                                  \
        ROM_USBHostLPMConfig
#else
#define MAP_USBHostLPMConfig                                                  \
        USBHostLPMConfig
#endif
#ifdef ROM_USBHostLPMResume
#define MAP_USBHostLPMResume                                                  \
        ROM_USBHostLPMResume
#else
#define MAP_USBHostLPMResume                                                  \
        USBHostLPMResume
#endif
#ifdef ROM_USBHostLPMSend
#define MAP_USBHostLPMSend                                                    \
        ROM_USBHostLPMSend
#else
#define MAP_USBHostLPMSend                                                    \
        USBHostLPMSend
#endif
#ifdef ROM_USBLPMIntDisable
#define MAP_USBLPMIntDisable                                                  \
        ROM_USBLPMIntDisable
#else
#define MAP_USBLPMIntDisable                                                  \
        USBLPMIntDisable
#endif
#ifdef ROM_USBLPMIntEnable
#define MAP_USBLPMIntEnable                                                   \
        ROM_USBLPMIntEnable
#else
#define MAP_USBLPMIntEnable                                                   \
        USBLPMIntEnable
#endif
#ifdef ROM_USBLPMIntStatus
#define MAP_USBLPMIntStatus                                                   \
        ROM_USBLPMIntStatus
#else
#define MAP_USBLPMIntStatus                                                   \
        USBLPMIntStatus
#endif
#ifdef ROM_USBLPMLinkStateGet
#define MAP_USBLPMLinkStateGet                                                \
        ROM_USBLPMLinkStateGet
#else
#define MAP_USBLPMLinkStateGet                                                \
        USBLPMLinkStateGet
#endif
#ifdef ROM_USBEndpointPacketCountSet
#define MAP_USBEndpointPacketCountSet                                         \
        ROM_USBEndpointPacketCountSet
#else
#define MAP_USBEndpointPacketCountSet                                         \
        USBEndpointPacketCountSet
#endif
#ifdef ROM_USBULPIConfig
#define MAP_USBULPIConfig                                                     \
        ROM_USBULPIConfig
#else
#define MAP_USBULPIConfig                                                     \
        USBULPIConfig
#endif
#ifdef ROM_USBULPIDisable
#define MAP_USBULPIDisable                                                    \
        ROM_USBULPIDisable
#else
#define MAP_USBULPIDisable                                                    \
        USBULPIDisable
#endif
#ifdef ROM_USBULPIEnable
#define MAP_USBULPIEnable                                                     \
        ROM_USBULPIEnable
#else
#define MAP_USBULPIEnable                                                     \
        USBULPIEnable
#endif
#ifdef ROM_USBULPIRegRead
#define MAP_USBULPIRegRead                                                    \
        ROM_USBULPIRegRead
#else
#define MAP_USBULPIRegRead                                                    \
        USBULPIRegRead
#endif
#ifdef ROM_USBULPIRegWrite
#define MAP_USBULPIRegWrite                                                   \
        ROM_USBULPIRegWrite
#else
#define MAP_USBULPIRegWrite                                                   \
        USBULPIRegWrite
#endif
#ifdef ROM_USBOTGSessionRequest
#define MAP_USBOTGSessionRequest                                              \
        ROM_USBOTGSessionRequest
#else
#define MAP_USBOTGSessionRequest                                              \
        USBOTGSessionRequest
#endif
#ifdef ROM_USBModeConfig
#define MAP_USBModeConfig                                                     \
        ROM_USBModeConfig
#else
#define MAP_USBModeConfig                                                     \
        USBModeConfig
#endif

//*****************************************************************************
//
// Macros for the Watchdog API.
//
//*****************************************************************************
#ifdef ROM_WatchdogIntClear
#define MAP_WatchdogIntClear                                                  \
        ROM_WatchdogIntClear
#else
#define MAP_WatchdogIntClear                                                  \
        WatchdogIntClear
#endif
#ifdef ROM_WatchdogRunning
#define MAP_WatchdogRunning                                                   \
        ROM_WatchdogRunning
#else
#define MAP_WatchdogRunning                                                   \
        WatchdogRunning
#endif
#ifdef ROM_WatchdogEnable
#define MAP_WatchdogEnable                                                    \
        ROM_WatchdogEnable
#else
#define MAP_WatchdogEnable                                                    \
        WatchdogEnable
#endif
#ifdef ROM_WatchdogResetEnable
#define MAP_WatchdogResetEnable                                               \
        ROM_WatchdogResetEnable
#else
#define MAP_WatchdogResetEnable                                               \
        WatchdogResetEnable
#endif
#ifdef ROM_WatchdogResetDisable
#define MAP_WatchdogResetDisable                                              \
        ROM_WatchdogResetDisable
#else
#define MAP_WatchdogResetDisable                                              \
        WatchdogResetDisable
#endif
#ifdef ROM_WatchdogLock
#define MAP_WatchdogLock                                                      \
        ROM_WatchdogLock
#else
#define MAP_WatchdogLock                                                      \
        WatchdogLock
#endif
#ifdef ROM_WatchdogUnlock
#define MAP_WatchdogUnlock                                                    \
        ROM_WatchdogUnlock
#else
#define MAP_WatchdogUnlock                                                    \
        WatchdogUnlock
#endif
#ifdef ROM_WatchdogLockState
#define MAP_WatchdogLockState                                                 \
        ROM_WatchdogLockState
#else
#define MAP_WatchdogLockState                                                 \
        WatchdogLockState
#endif
#ifdef ROM_WatchdogReloadSet
#define MAP_WatchdogReloadSet                                                 \
        ROM_WatchdogReloadSet
#else
#define MAP_WatchdogReloadSet                                                 \
        WatchdogReloadSet
#endif
#ifdef ROM_WatchdogReloadGet
#define MAP_WatchdogReloadGet                                                 \
        ROM_WatchdogReloadGet
#else
#define MAP_WatchdogReloadGet                                                 \
        WatchdogReloadGet
#endif
#ifdef ROM_WatchdogValueGet
#define MAP_WatchdogValueGet                                                  \
        ROM_WatchdogValueGet
#else
#define MAP_WatchdogValueGet                                                  \
        WatchdogValueGet
#endif
#ifdef ROM_WatchdogIntEnable
#define MAP_WatchdogIntEnable                                                 \
        ROM_WatchdogIntEnable
#else
#define MAP_WatchdogIntEnable                                                 \
        WatchdogIntEnable
#endif
#ifdef ROM_WatchdogIntStatus
#define MAP_WatchdogIntStatus                                                 \
        ROM_WatchdogIntStatus
#else
#define MAP_WatchdogIntStatus                                                 \
        WatchdogIntStatus
#endif
#ifdef ROM_WatchdogStallEnable
#define MAP_WatchdogStallEnable                                               \
        ROM_WatchdogStallEnable
#else
#define MAP_WatchdogStallEnable                                               \
        WatchdogStallEnable
#endif
#ifdef ROM_WatchdogStallDisable
#define MAP_WatchdogStallDisable                                              \
        ROM_WatchdogStallDisable
#else
#define MAP_WatchdogStallDisable                                              \
        WatchdogStallDisable
#endif
#ifdef ROM_WatchdogIntTypeSet
#define MAP_WatchdogIntTypeSet                                                \
        ROM_WatchdogIntTypeSet
#else
#define MAP_WatchdogIntTypeSet                                                \
        WatchdogIntTypeSet
#endif

//*****************************************************************************
//
// Macros for the Software API.
//
//*****************************************************************************
#ifdef ROM_Crc16Array
#define MAP_Crc16Array                                                        \
        ROM_Crc16Array
#else
#define MAP_Crc16Array                                                        \
        Crc16Array
#endif
#ifdef ROM_Crc16Array3
#define MAP_Crc16Array3                                                       \
        ROM_Crc16Array3
#else
#define MAP_Crc16Array3                                                       \
        Crc16Array3
#endif
#ifdef ROM_Crc16
#define MAP_Crc16                                                             \
        ROM_Crc16
#else
#define MAP_Crc16                                                             \
        Crc16
#endif
#ifdef ROM_Crc8CCITT
#define MAP_Crc8CCITT                                                         \
        ROM_Crc8CCITT
#else
#define MAP_Crc8CCITT                                                         \
        Crc8CCITT
#endif
#ifdef ROM_Crc32
#define MAP_Crc32                                                             \
        ROM_Crc32
#else
#define MAP_Crc32                                                             \
        Crc32
#endif

#endif // __DRIVERLIB_ROM_MAP_H__
