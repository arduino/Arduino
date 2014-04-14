//*****************************************************************************
//
// rom.h - Macros to facilitate calling functions in the ROM.
//
// Copyright (c) 2007 Texas Instruments Incorporated.  All rights reserved.
// TI Information - Selective Disclosure
//
//*****************************************************************************
//##### INTERNAL BEGIN #####
//*****************************************************************************
//
// THIS IS AN AUTO-GENERATED FILE.  DO NOT EDIT BY HAND.
// Created by version Unversioned directory of DriverLib and version 0 of ROMSource.
//
//*****************************************************************************
//##### INTERNAL END #####

#ifndef __ROM_H__
#define __ROM_H__

//*****************************************************************************
//
// Pointers to the main API tables.
//
//*****************************************************************************
//##### INTERNAL BEGIN #####
#define ROM_APITABLE            ((unsigned long *)0x0000040C)
//##### INTERNAL END #####
#define ROM_VERSION             (ROM_APITABLE[0])
#define ROM_UARTTABLE           ((unsigned long *)(ROM_APITABLE[1]))
#define ROM_TIMERTABLE          ((unsigned long *)(ROM_APITABLE[2]))
#define ROM_WATCHDOGTABLE       ((unsigned long *)(ROM_APITABLE[3]))
#define ROM_ARCMTABLE           ((unsigned long *)(ROM_APITABLE[4]))
#define ROM_INTERRUPTTABLE      ((unsigned long *)(ROM_APITABLE[5]))
#define ROM_UDMATABLE           ((unsigned long *)(ROM_APITABLE[6]))
#define ROM_GPRCMTABLE          ((unsigned long *)(ROM_APITABLE[7]))
#define ROM_I2CTABLE            ((unsigned long *)(ROM_APITABLE[8]))
#define ROM_MCSPITABLE          ((unsigned long *)(ROM_APITABLE[9]))
#define ROM_CAMERATABLE         ((unsigned long *)(ROM_APITABLE[10]))
#define ROM_FLASHTABLE          ((unsigned long *)(ROM_APITABLE[11]))
#define ROM_EPITABLE            ((unsigned long *)(ROM_APITABLE[12]))
#define ROM_PINTABLE            ((unsigned long *)(ROM_APITABLE[13]))
#define ROM_SYSTICKTABLE        ((unsigned long *)(ROM_APITABLE[14]))
#define ROM_UTILSTABLE          ((unsigned long *)(ROM_APITABLE[15]))
#define ROM_MCASPTABLE          ((unsigned long *)(ROM_APITABLE[16]))
#define ROM_SEMAPHORETABLE      ((unsigned long *)(ROM_APITABLE[17]))
#define ROM_GPIOTABLE           ((unsigned long *)(ROM_APITABLE[18]))
#define ROM_HIBTABLE            ((unsigned long *)(ROM_APITABLE[19]))
#define ROM_AESTABLE            ((unsigned long *)(ROM_APITABLE[20]))
#define ROM_DESTABLE            ((unsigned long *)(ROM_APITABLE[21]))
#define ROM_SHAMD5TABLE         ((unsigned long *)(ROM_APITABLE[22]))
#define ROM_CRCTABLE            ((unsigned long *)(ROM_APITABLE[23]))

//*****************************************************************************
//
// Macros for calling ROM functions in the Interrupt API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_IntEnable                                                         \
        ((void (*)(unsigned long ulInterrupt))ROM_INTERRUPTTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntMasterEnable                                                   \
        ((tBoolean (*)(void))ROM_INTERRUPTTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntMasterDisable                                                  \
        ((tBoolean (*)(void))ROM_INTERRUPTTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntDisable                                                        \
        ((void (*)(unsigned long ulInterrupt))ROM_INTERRUPTTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPriorityGroupingSet                                            \
        ((void (*)(unsigned long ulBits))ROM_INTERRUPTTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPriorityGroupingGet                                            \
        ((unsigned long (*)(void))ROM_INTERRUPTTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPrioritySet                                                    \
        ((void (*)(unsigned long ulInterrupt,                                 \
                   unsigned char ucPriority))ROM_INTERRUPTTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPriorityGet                                                    \
        ((long (*)(unsigned long ulInterrupt))ROM_INTERRUPTTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPendSet                                                        \
        ((void (*)(unsigned long ulInterrupt))ROM_INTERRUPTTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPendClear                                                      \
        ((void (*)(unsigned long ulInterrupt))ROM_INTERRUPTTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPriorityMaskSet                                                \
        ((void (*)(unsigned long ulPriorityMask))ROM_INTERRUPTTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntPriorityMaskGet                                                \
        ((unsigned long (*)(void))ROM_INTERRUPTTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntRegister                                                       \
        ((void (*)(unsigned long ulInterrupt,                                 \
                   void (*pfnHandler)(void)))ROM_INTERRUPTTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntUnregister                                                     \
        ((void (*)(unsigned long ulInterrupt))ROM_INTERRUPTTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_IntVTableBaseSet                                                  \
        ((void (*)(unsigned long ulVtableBase))ROM_INTERRUPTTABLE[14])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Timer API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_TimerEnable                                                       \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer))ROM_TIMERTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerDisable                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer))ROM_TIMERTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerConfigure                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulConfig))ROM_TIMERTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerControlLevel                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   tBoolean bInvert))ROM_TIMERTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerControlTrigger                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   tBoolean bEnable))ROM_TIMERTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerControlEvent                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   unsigned long ulEvent))ROM_TIMERTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerControlStall                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   tBoolean bStall))ROM_TIMERTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerControlWaitOnTrigger                                         \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   tBoolean bWait))ROM_TIMERTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerPrescaleSet                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   unsigned long ulValue))ROM_TIMERTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerPrescaleGet                                                  \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulTimer))ROM_TIMERTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerPrescaleMatchSet                                             \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   unsigned long ulValue))ROM_TIMERTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerPrescaleMatchGet                                             \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulTimer))ROM_TIMERTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerLoadSet                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   unsigned long ulValue))ROM_TIMERTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerLoadGet                                                      \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulTimer))ROM_TIMERTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerValueGet                                                     \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulTimer))ROM_TIMERTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerMatchSet                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   unsigned long ulValue))ROM_TIMERTABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerMatchGet                                                     \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulTimer))ROM_TIMERTABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerIntRegister                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer,                                     \
                   void (*pfnHandler)(void)))ROM_TIMERTABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerIntUnregister                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimer))ROM_TIMERTABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerIntEnable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_TIMERTABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerIntDisable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_TIMERTABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerIntStatus                                                    \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_TIMERTABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerIntClear                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_TIMERTABLE[22])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_TimerSynchronize                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTimers))ROM_TIMERTABLE[23])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the UART API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_UARTParityModeSet                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulParity))ROM_UARTTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTParityModeGet                                                 \
        ((unsigned long (*)(unsigned long ulBase))ROM_UARTTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTFIFOLevelSet                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTxLevel,                                   \
                   unsigned long ulRxLevel))ROM_UARTTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTFIFOLevelGet                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long *pulTxLevel,                                 \
                   unsigned long *pulRxLevel))ROM_UARTTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTConfigSetExpClk                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulUARTClk,                                   \
                   unsigned long ulBaud,                                      \
                   unsigned long ulConfig))ROM_UARTTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTConfigGetExpClk                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulUARTClk,                                   \
                   unsigned long *pulBaud,                                    \
                   unsigned long *pulConfig))ROM_UARTTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTEnable                                                        \
        ((void (*)(unsigned long ulBase))ROM_UARTTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTDisable                                                       \
        ((void (*)(unsigned long ulBase))ROM_UARTTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTFIFOEnable                                                    \
        ((void (*)(unsigned long ulBase))ROM_UARTTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTFIFODisable                                                   \
        ((void (*)(unsigned long ulBase))ROM_UARTTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTEnableSIR                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   tBoolean bLowPower))ROM_UARTTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTDisableSIR                                                    \
        ((void (*)(unsigned long ulBase))ROM_UARTTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTCharsAvail                                                    \
        ((tBoolean (*)(unsigned long ulBase))ROM_UARTTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTSpaceAvail                                                    \
        ((tBoolean (*)(unsigned long ulBase))ROM_UARTTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTCharGetNonBlocking                                            \
        ((long (*)(unsigned long ulBase))ROM_UARTTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTCharGet                                                       \
        ((long (*)(unsigned long ulBase))ROM_UARTTABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTCharPutNonBlocking                                            \
        ((tBoolean (*)(unsigned long ulBase,                                  \
                       unsigned char ucData))ROM_UARTTABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTCharPut                                                       \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucData))ROM_UARTTABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTBreakCtl                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                   tBoolean bBreakState))ROM_UARTTABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTBusy                                                          \
        ((tBoolean (*)(unsigned long ulBase))ROM_UARTTABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTIntRegister                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   void(*pfnHandler)(void)))ROM_UARTTABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTIntUnregister                                                 \
        ((void (*)(unsigned long ulBase))ROM_UARTTABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTIntEnable                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_UARTTABLE[22])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTIntDisable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_UARTTABLE[23])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTIntStatus                                                     \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_UARTTABLE[24])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTIntClear                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_UARTTABLE[25])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTDMAEnable                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDMAFlags))ROM_UARTTABLE[26])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTDMADisable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDMAFlags))ROM_UARTTABLE[27])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTRxErrorGet                                                    \
        ((unsigned long (*)(unsigned long ulBase))ROM_UARTTABLE[28])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTRxErrorClear                                                  \
        ((void (*)(unsigned long ulBase))ROM_UARTTABLE[29])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTModemControlSet                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulControl))ROM_UARTTABLE[30])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTModemControlClear                                             \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulControl))ROM_UARTTABLE[31])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTModemControlGet                                               \
        ((unsigned long (*)(unsigned long ulBase))ROM_UARTTABLE[32])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTModemStatusGet                                                \
        ((unsigned long (*)(unsigned long ulBase))ROM_UARTTABLE[33])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTFlowControlSet                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMode))ROM_UARTTABLE[34])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTFlowControlGet                                                \
        ((unsigned long (*)(unsigned long ulBase))ROM_UARTTABLE[35])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTTxIntModeSet                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMode))ROM_UARTTABLE[36])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTTxIntModeGet                                                  \
        ((unsigned long (*)(unsigned long ulBase))ROM_UARTTABLE[37])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTClockSourceSet                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulSource))ROM_UARTTABLE[38])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_UARTClockSourceGet                                                \
        ((unsigned long (*)(unsigned long ulBase))ROM_UARTTABLE[39])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the uDMA API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelTransferSet                                            \
        ((void (*)(unsigned long ulChannelStructIndex,                        \
                   unsigned long ulMode,                                      \
                   void *pvSrcAddr,                                           \
                   void *pvDstAddr,                                           \
                   unsigned long ulTransferSize))ROM_UDMATABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAEnable                                                        \
        ((void (*)(void))ROM_UDMATABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMADisable                                                       \
        ((void (*)(void))ROM_UDMATABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAErrorStatusGet                                                \
        ((unsigned long (*)(void))ROM_UDMATABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAErrorStatusClear                                              \
        ((void (*)(void))ROM_UDMATABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelEnable                                                 \
        ((void (*)(unsigned long ulChannelNum))ROM_UDMATABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelDisable                                                \
        ((void (*)(unsigned long ulChannelNum))ROM_UDMATABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelIsEnabled                                              \
        ((tBoolean (*)(unsigned long ulChannelNum))ROM_UDMATABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAControlBaseSet                                                \
        ((void (*)(void *pControlTable))ROM_UDMATABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAControlBaseGet                                                \
        ((void * (*)(void))ROM_UDMATABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelRequest                                                \
        ((void (*)(unsigned long ulChannelNum))ROM_UDMATABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelAttributeEnable                                        \
        ((void (*)(unsigned long ulChannelNum,                                \
                   unsigned long ulAttr))ROM_UDMATABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelAttributeDisable                                       \
        ((void (*)(unsigned long ulChannelNum,                                \
                   unsigned long ulAttr))ROM_UDMATABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelAttributeGet                                           \
        ((unsigned long (*)(unsigned long ulChannelNum))ROM_UDMATABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelControlSet                                             \
        ((void (*)(unsigned long ulChannelStructIndex,                        \
                   unsigned long ulControl))ROM_UDMATABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelSizeGet                                                \
        ((unsigned long (*)(unsigned long ulChannelStructIndex))ROM_UDMATABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelModeGet                                                \
        ((unsigned long (*)(unsigned long ulChannelStructIndex))ROM_UDMATABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAIntStatus                                                     \
        ((unsigned long (*)(void))ROM_UDMATABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAIntClear                                                      \
        ((void (*)(unsigned long ulChanMask))ROM_UDMATABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAControlAlternateBaseGet                                       \
        ((void * (*)(void))ROM_UDMATABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelScatterGatherSet                                       \
        ((void (*)(unsigned long ulChannelNum,                                \
                   unsigned ulTaskCount,                                      \
                   void *pvTaskList,                                          \
                   unsigned long ulIsPeriphSG))ROM_UDMATABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAChannelAssign                                                 \
        ((void (*)(unsigned long ulMapping))ROM_UDMATABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAIntRegister                                                   \
        ((void (*)(unsigned long ulIntChannel,                                \
                   void (*pfnHandler)(void)))ROM_UDMATABLE[22])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_uDMAIntUnregister                                                 \
        ((void (*)(unsigned long ulIntChannel))ROM_UDMATABLE[23])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Watchdog API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogIntClear                                                  \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogRunning                                                   \
        ((tBoolean (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogEnable                                                    \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogLock                                                      \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogUnlock                                                    \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogLockState                                                 \
        ((tBoolean (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogReloadSet                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulLoadVal))ROM_WATCHDOGTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogReloadGet                                                 \
        ((unsigned long (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogValueGet                                                  \
        ((unsigned long (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogIntEnable                                                 \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogIntStatus                                                 \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_WATCHDOGTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogStallEnable                                               \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogStallDisable                                              \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogIntTypeSet                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulType))ROM_WATCHDOGTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogIntRegister                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   void(*pfnHandler)(void)))ROM_WATCHDOGTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_WatchdogIntUnregister                                             \
        ((void (*)(unsigned long ulBase))ROM_WATCHDOGTABLE[15])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the Watchdog API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralReset                                               \
        ((void (*)(ArcmPeripherals_t ePeripheral))ROM_ARCMTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralEnable                                              \
        ((void (*)(ArcmPeripherals_t ulPeripheral))ROM_ARCMTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralDisable                                             \
        ((void (*)(ArcmPeripherals_t ulPeripheral))ROM_ARCMTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralSlpEnable                                           \
        ((void (*)(ArcmPeripherals_t ePeripheral ))ROM_ARCMTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralSlpDisable                                          \
        ((void (*)(ArcmPeripherals_t ePeripheral ))ROM_ARCMTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralDSlpEnable                                          \
        ((void (*)(ArcmPeripherals_t ePeripheral ))ROM_ARCMTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralDSlpDisable                                         \
        ((void (*)(ArcmPeripherals_t ePeripheral ))ROM_ARCMTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralClkConfig                                           \
        ((void (*)(ArcmPeripherals_t ePeripheral,                             \
                   unsigned long ulOnTime,                                    \
                  unsigned long ulOffTime))ROM_ARCMTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralReady                                               \
        ((tBoolean (*)(ArcmPeripherals_t ePeripheral))ROM_ARCMTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmSlpWakeupSrcSet                                               \
        ((void (*)(unsigned long ulWakeupSrc))ROM_ARCMTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmSlpWakeupTimerConfig                                          \
        ((void (*)(unsigned long ulTimeInClocks))ROM_ARCMTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmDSlpWakeupSrcSet                                              \
        ((void (*)(unsigned long ulWakeupSrc))ROM_ARCMTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmDSlpWakeupTimerConfig                                         \
        ((void (*)(unsigned long ulTimeInClocks))ROM_ARCMTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmRqstNwpWakeup                                                 \
        ((void (*)(void))ROM_ARCMTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmWakeupStatusGet                                               \
        ((unsigned long (*)(void))ROM_ARCMTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmMcAspFracDivReset                                             \
        ((void (*)(void))ROM_ARCMTABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmMcAspFracDivSet                                               \
        ((void (*)(float Divider))ROM_ARCMTABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmMcSPIClkSrcSet                                                \
        ((void (*)(ArcmPeripherals_t ePeripheral,                             \
                   unsigned long ulSrcClk))ROM_ARCMTABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmMcSPIClkSrcGet                                                \
        ((long (*)(ArcmPeripherals_t ePeripheral))ROM_ARCMTABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmLpdsEnter                                                     \
        ((void (*)(void))ROM_ARCMTABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmDslpEnter                                                     \
        ((void (*)(void))ROM_ARCMTABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmSlpEnter                                                      \
        ((void (*)(void))ROM_ARCMTABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmPeripheralClkGet                                              \
        ((unsigned long (*)(ArcmPeripherals_t ePeripheral))ROM_ARCMTABLE[22])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_ArcmMcAspFracDivGet                                               \
        ((float (*)(void))ROM_ARCMTABLE[23])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the GPRCM API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmAppsSSRst                                                    \
        ((void (*)(void))ROM_GPRCMTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmAppsRst                                                      \
        ((void (*)(void))ROM_GPRCMTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmNwpRst                                                       \
        ((void (*)(void))ROM_GPRCMTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmMcuGlobalRst                                                 \
        ((void (*)(void))ROM_GPRCMTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmSramDslpRetEnable                                            \
        ((void (*)(unsigned long ulBitMap))ROM_GPRCMTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmSramDslpRetDisable                                           \
        ((void (*)(unsigned long ulBitMap))ROM_GPRCMTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmSramLpdsRetEnable                                            \
        ((void (*)(unsigned long ulBitMap))ROM_GPRCMTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmSramLpdsRetDisable                                           \
        ((void (*)(unsigned long ulBitMap))ROM_GPRCMTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmAppsRstCauseGet                                              \
        ((unsigned long (*)(void))ROM_GPRCMTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmLPDSWkupSrcGet                                               \
        ((unsigned long (*)(void))ROM_GPRCMTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmLPDSWkupSrcSet                                               \
        ((void (*)(unsigned long ulWkupSrc))ROM_GPRCMTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GprcmLPDSWkupTimeSet                                              \
        ((void (*)(unsigned long ulTimeInClocks))ROM_GPRCMTABLE[11])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the I2C API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_I2CIntRegister                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   void(fnHandler)(void)))ROM_I2CTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CIntUnregister                                                  \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterBusBusy                                                  \
        ((tBoolean (*)(unsigned long ulBase))ROM_I2CTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterBusy                                                     \
        ((tBoolean (*)(unsigned long ulBase))ROM_I2CTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterControl                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulCmd))ROM_I2CTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterDataGet                                                  \
        ((unsigned long (*)(unsigned long ulBase))ROM_I2CTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterDataPut                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucData))ROM_I2CTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterDisable                                                  \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterEnable                                                   \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterErr                                                      \
        ((unsigned long (*)(unsigned long ulBase))ROM_I2CTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterInitExpClk                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulI2CClk,                                    \
                   tBoolean bFast))ROM_I2CTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntClear                                                 \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntDisable                                               \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntEnable                                                \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntStatus                                                \
        ((tBoolean (*)(unsigned long ulBase,                                  \
                       tBoolean bMasked))ROM_I2CTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntEnableEx                                              \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_I2CTABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntDisableEx                                             \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_I2CTABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntStatusEx                                              \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_I2CTABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterInitExpClkEx                                             \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulI2CClk,                                    \
                   tBoolean bConfHiSpd,                                       \
                  unsigned long ulMode))ROM_I2CTABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterIntClearEx                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_I2CTABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterTimeoutSet                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulValue))ROM_I2CTABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveACKOverride                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   tBoolean bEnable))ROM_I2CTABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveACKValueSet                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   tBoolean bACK))ROM_I2CTABLE[22])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterLineStateGet                                             \
        ((unsigned long (*)(unsigned long ulBase))ROM_I2CTABLE[23])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMasterSlaveAddrSet                                             \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucSlaveAddr,                                 \
                   tBoolean bReceive))ROM_I2CTABLE[24])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveDataGet                                                   \
        ((unsigned long (*)(unsigned long ulBase))ROM_I2CTABLE[25])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveDataPut                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucData))ROM_I2CTABLE[26])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveDisable                                                   \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[27])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveEnable                                                    \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[28])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveInit                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucSlaveAddr))ROM_I2CTABLE[29])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveAddressSet                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucAddrNum,                                   \
                   unsigned char ucSlaveAddr))ROM_I2CTABLE[30])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntClear                                                  \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[31])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntDisable                                                \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[32])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntEnable                                                 \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[33])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntClearEx                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_I2CTABLE[34])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntDisableEx                                              \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_I2CTABLE[35])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntEnableEx                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_I2CTABLE[36])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntStatus                                                 \
        ((tBoolean (*)(unsigned long ulBase,                                  \
                       tBoolean bMasked))ROM_I2CTABLE[37])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveIntStatusEx                                               \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_I2CTABLE[38])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CSlaveStatus                                                    \
        ((unsigned long (*)(unsigned long ulBase))ROM_I2CTABLE[39])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CLoopBackEnable                                                 \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[40])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CLoopBackDisable                                                \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[41])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CFIFOCtrlSet                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulTxTrigLvl,                                 \
                   unsigned long ulTxFlag,                                    \
                   unsigned ulRxTrigLvl,                                      \
                   unsigned long ulRxFlag))ROM_I2CTABLE[42])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CFIFOWrite                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                  unsigned char ucData))ROM_I2CTABLE[43])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CFIFORead                                                       \
        ((unsigned long (*)(unsigned long ulBase))ROM_I2CTABLE[44])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMultiMasterEnable                                              \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[45])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CFIFOStatusGet                                                  \
        ((unsigned long (*)(unsigned long ulBase))ROM_I2CTABLE[46])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_I2CMultiMasterDisable                                             \
        ((void (*)(unsigned long ulBase))ROM_I2CTABLE[47])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the MCSPI API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIReset                                                        \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIConfig                                                       \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucMSMode,                                    \
                   unsigned long ulMcSPIClk,                                  \
                   unsigned long ulBaud,                                      \
                   unsigned char ucWordLen,                                   \
                   unsigned char ucCSPolarity,                                \
                   unsigned char ucClkPhase,                                  \
                   unsigned char ucClkPolarity))ROM_MCSPITABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIMSModeGet                                                    \
        ((unsigned char (*)(unsigned long ulBase))ROM_MCSPITABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIWordLenGet                                                   \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCSPITABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPISPITRModeSet                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulSPIMode))ROM_MCSPITABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPISPITRModeGet                                                 \
        ((unsigned char (*)(unsigned long ulBase))ROM_MCSPITABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDataLineConfigSet                                            \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucDataLineConf))ROM_MCSPITABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDataLineConfigGet                                            \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCSPITABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIChannelEnable                                                \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIChannelDisable                                               \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDataNonBlockingGet                                           \
        ((tBoolean (*)(unsigned long ulBase,                                  \
                       unsigned long * pulData))ROM_MCSPITABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDataGet                                                      \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCSPITABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDataNonBlockingPut                                           \
        ((tBoolean (*)(unsigned long ulBase,                                  \
                       unsigned long ulData))ROM_MCSPITABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDataPut                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulData))ROM_MCSPITABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPICSEnable                                                     \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPICSDisable                                                    \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPITransfer                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char *ucDout,                                     \
                   unsigned char *ucDin,                                      \
                   unsigned long ulSize,                                      \
                   unsigned long ulFlags))ROM_MCSPITABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIFIFOEnable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlags))ROM_MCSPITABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIFIFODisable                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlags))ROM_MCSPITABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIConfigureAFL                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucAFLData))ROM_MCSPITABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIConfigureAEL                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucAELData))ROM_MCSPITABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIConfigureWCNT                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned short ucWCNT))ROM_MCSPITABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDmaEnable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlags))ROM_MCSPITABLE[22])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIDmaDisable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned ulFlags))ROM_MCSPITABLE[23])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIIntRegister                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   void(*pfnHandler)(void)))ROM_MCSPITABLE[24])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIIntUnregister                                                \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[25])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIIntEnable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_MCSPITABLE[26])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIIntDisable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_MCSPITABLE[27])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIIntStatus                                                    \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_MCSPITABLE[28])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIIntClear                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_MCSPITABLE[29])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIInitDelaySet                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char ucInitDelay))ROM_MCSPITABLE[30])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIInitDelayGet                                                 \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCSPITABLE[31])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIStartBitEnable                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   tBoolean bSBPolHigh))ROM_MCSPITABLE[32])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPIStartBitDisable                                              \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[33])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPITurboModeEnable                                              \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[34])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPITurboModeDisable                                             \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[35])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPI3PinModeEnable                                               \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[36])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McSPI3PinModeDisable                                              \
        ((void (*)(unsigned long ulBase))ROM_MCSPITABLE[37])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the CAM API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_CameraReset                                                       \
        ((void (*)(unsigned long ulBase))ROM_CAMERATABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraReset                                                       \
        ((void (*)(unsigned long ulBase))ROM_CAMERATABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraParamsConfig                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulHSPol,                                     \
                   unsigned long ulVSPol,                                     \
                   unsigned long ulFlags))ROM_CAMERATABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraXClkConfig                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulCamClkIn,                                  \
                   unsigned long ulXClk))ROM_CAMERATABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraXClkSet                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned char bXClkFlags))ROM_CAMERATABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraDMAEnable                                                   \
        ((void (*)(unsigned long ulBase))ROM_CAMERATABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraDMADisable                                                  \
        ((void (*)(unsigned long ulBase))ROM_CAMERATABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraThresholdSet                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulThreshold))ROM_CAMERATABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraIntRegister                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   void (*pfnHandler)(void)))ROM_CAMERATABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraIntUnregister                                               \
        ((void (*)(unsigned long ulBase))ROM_CAMERATABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraIntEnable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_CAMERATABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraIntDisable                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_CAMERATABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraIntStatus                                                   \
        ((unsigned long (*)(unsigned long ulBase))ROM_CAMERATABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraIntClear                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_CAMERATABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraCaptureStop                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   tBoolean bImmediate))ROM_CAMERATABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CameraCaptureStart                                                \
        ((void (*)(unsigned long ulBase))ROM_CAMERATABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CamBufferRead                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                  unsigned long *pBuffer,                                     \
                   unsigned char ucSize))ROM_CAMERATABLE[16])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the FLASH API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_FlashDisable                                                      \
        ((void (*)(void))ROM_FLASHTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashErase                                                        \
        ((long (*)(unsigned long ulAddress))ROM_FLASHTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashMassErase                                                    \
        ((long (*)(void))ROM_FLASHTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashMassEraseNonBlocking                                         \
        ((void (*)(void))ROM_FLASHTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashEraseNonBlocking                                             \
        ((void (*)(unsigned long ulAddress))ROM_FLASHTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashProgram                                                      \
        ((long (*)(unsigned long *pulData,                                    \
                   unsigned long ulAddress,                                   \
                   unsigned long ulCount))ROM_FLASHTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashProgramNonBlocking                                           \
        ((long (*)(unsigned long *pulData,                                    \
                   unsigned long ulAddress,                                   \
                   unsigned long ulCount))ROM_FLASHTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashIntRegister                                                  \
        ((void (*)(void (*pfnHandler)(void)))ROM_FLASHTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashIntUnregister                                                \
        ((void (*)(void))ROM_FLASHTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashIntEnable                                                    \
        ((void (*)(unsigned long ulIntFlags))ROM_FLASHTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashIntDisable                                                   \
        ((void (*)(unsigned long ulIntFlags))ROM_FLASHTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashIntStatus                                                    \
        ((unsigned long (*)(tBoolean bMasked))ROM_FLASHTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashIntClear                                                     \
        ((void (*)(unsigned long ulIntFlags))ROM_FLASHTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_FlashProtectGet                                                   \
        ((tFlashProtection (*)(unsigned long ulAddress))ROM_FLASHTABLE[13])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the EPI API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_EPIModeSet                                                        \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMode))ROM_EPITABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIDividerSet                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDivider))ROM_EPITABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIConfigSDRAMSet                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulConfig,                                    \
                   unsigned long ulRefresh))ROM_EPITABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIAddressMapSet                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMap))ROM_EPITABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadConfigure                                       \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulChannel,                                   \
                   unsigned long ulDataSize,                                  \
                   unsigned long ulAddress))ROM_EPITABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadStart                                           \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulChannel,                                   \
                   unsigned long ulCount))ROM_EPITABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadStop                                            \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulChannel))ROM_EPITABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadCount                                           \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulChannel))ROM_EPITABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadAvail                                           \
        ((unsigned long (*)(unsigned long ulBase))ROM_EPITABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadGet32                                           \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulCount,                            \
                            unsigned long *pulBuf))ROM_EPITABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadGet16                                           \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulCount,                            \
                            unsigned short *pusBuf))ROM_EPITABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPINonBlockingReadGet8                                            \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulCount,                            \
                            unsigned char *pucBuf))ROM_EPITABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIFIFOConfig                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulConfig))ROM_EPITABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIWriteFIFOCountGet                                              \
        ((unsigned long (*)(unsigned long ulBase))ROM_EPITABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIIntEnable                                                      \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_EPITABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIIntDisable                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulIntFlags))ROM_EPITABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIIntStatus                                                      \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_EPITABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIIntErrorStatus                                                 \
        ((unsigned long (*)(unsigned long ulBase))ROM_EPITABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIIntErrorClear                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulErrFlags))ROM_EPITABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIIntRegister                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   void (*pfnHandler)(void)))ROM_EPITABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_EPIIntUnregister                                                  \
        ((void (*)(unsigned long ulBase))ROM_EPITABLE[20])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the PinMAP API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_PinModeSet                                                        \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinModeGet                                                        \
        ((unsigned long (*)(unsigned long ulPin))ROM_PINTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinConfigGet                                                      \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long  *pulPinStrength,                             \
                   unsigned long *pulPinType))ROM_PINTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinConfigSet                                                      \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long  ulPinStrength,                               \
                   unsigned long ulPinType))ROM_PINTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeSet                                                        \
        ((void (*)(unsigned long ulPin,                                       \
                   unsigned long ulPinType))ROM_PINTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeGet                                                        \
        ((unsigned long (*)(unsigned long ulPin))ROM_PINTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinStrengthSet                                                    \
        ((void (*)(unsigned long ulPin,                                       \
                   unsigned ulPinStrength))ROM_PINTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinStrengthGet                                                    \
        ((unsigned long (*)(unsigned long ulPin))ROM_PINTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeUART                                                       \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeI2C                                                        \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeMcSPI                                                      \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeMcASP                                                      \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeTimer                                                      \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeCAM                                                        \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeEPI                                                        \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode))ROM_PINTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_PinTypeGPIO                                                       \
        ((void (*)(unsigned long ulPin,                                       \
                  unsigned long ulPinMode,                                    \
                  tBoolean bOpenDrain))ROM_PINTABLE[15])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SYSTICK API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickEnable                                                     \
        ((void (*)(void))ROM_SYSTICKTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickDisable                                                    \
        ((void (*)(void))ROM_SYSTICKTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickIntRegister                                                \
        ((void (*)(void (*pfnHandler)(void)))ROM_SYSTICKTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickIntUnregister                                              \
        ((void (*)(void))ROM_SYSTICKTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickIntEnable                                                  \
        ((void (*)(void))ROM_SYSTICKTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickIntDisable                                                 \
        ((void (*)(void))ROM_SYSTICKTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickPeriodSet                                                  \
        ((void (*)(unsigned long ulPeriod))ROM_SYSTICKTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickPeriodGet                                                  \
        ((unsigned long (*)(void))ROM_SYSTICKTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SysTickValueGet                                                   \
        ((unsigned long (*)(void))ROM_SYSTICKTABLE[8])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the UTILS API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_UtilsDelay                                                        \
        ((void (*)(unsigned long ulCount))ROM_UTILSTABLE[0])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SEMAPHORE API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_HwSemaphoreLock                                                   \
        ((unsigned long (*)(unsigned long ulSemId,                            \
                            unsigned long ulTimeout))ROM_SEMAPHORETABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HwSemaphoreUnlock                                                 \
        ((void (*)(unsigned long ulSemId))ROM_SEMAPHORETABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HwSemaphoreCurrentOwnerGet                                        \
        ((unsigned long (*)(unsigned long ulSemId))ROM_SEMAPHORETABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HwSemaphorePrevOwnerGet                                           \
        ((unsigned long (*)(unsigned long ulSemId))ROM_SEMAPHORETABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HwSemaphoreFlashGet                                               \
        ((void (*)(void))ROM_SEMAPHORETABLE[4])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the MCSPI API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_McASPReset                                                        \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPPinDirSet                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulPin,                                       \
                  unsigned long ulPinDir))ROM_MCASPTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPGBLEnable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlag))ROM_MCASPTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPGBLDisable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlag))ROM_MCASPTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxValidBitSet                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulValidMask))ROM_MCASPTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxValidBitSet                                                \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulValidMask))ROM_MCASPTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxValidBitGet                                                \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxValidBitGet                                                \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPClkConfig                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMcASPClk,                                  \
                   unsigned long ulBitClk,                                    \
                   unsigned ulClkPol))ROM_MCASPTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPFSyncConfig                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFSyncMode,                                 \
                  unsigned long ulWidth,                                      \
                   unsigned long ulPol,                                       \
                  tBoolean bExtrn))ROM_MCASPTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPSerEnable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDataPin,                                   \
                   unsigned long ulSerMode,                                   \
                   unsigned long ulInactLvl))ROM_MCASPTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPSerDisable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDataPin))ROM_MCASPTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPSendNonBlocking                                              \
        ((long (*)(unsigned long ulBase,                                      \
                   unsigned long ulDataPin,                                   \
                  unsigned long ulData))ROM_MCASPTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPSend                                                         \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDataPin,                                   \
                  unsigned long ulData))ROM_MCASPTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRecvNonBlocking                                              \
        ((long (*)(unsigned long ulBase,                                      \
                   unsigned long ulDataPin,                                   \
                  unsigned long *ulData))ROM_MCASPTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRecv                                                         \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDataPin,                                   \
                  unsigned long *ulData))ROM_MCASPTABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxActiveSlotSet                                              \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMask))ROM_MCASPTABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxActiveSlotSet                                              \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMask))ROM_MCASPTABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxActiveSlotGet                                              \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxActiveSlotGet                                              \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxCurSlotGet                                                 \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxCurSlotGet                                                 \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPIntRegister                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   void (*pfnHandler)(void)))ROM_MCASPTABLE[22])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPIntUnregister                                                \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[23])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPIntEnable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlag))ROM_MCASPTABLE[24])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPIntDisable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlag))ROM_MCASPTABLE[25])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPIntStatus                                                    \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[26])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPIntClear                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlag))ROM_MCASPTABLE[27])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxPortSet                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlag))ROM_MCASPTABLE[28])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxPortGet                                                    \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[29])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxPortSet                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFlag))ROM_MCASPTABLE[30])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxPortGet                                                    \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[31])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxEnable                                                     \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[32])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxEnable                                                     \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[33])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxDisable                                                    \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[34])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxDisable                                                    \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[35])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPXferModeSet                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulMode))ROM_MCASPTABLE[36])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxClkChkConfig                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulPrescale,                                  \
                  unsigned long ulMin,                                        \
                  unsigned long ulMax))ROM_MCASPTABLE[37])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxClkChkCount                                                \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[38])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxClkChkConfig                                               \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulPrescale,                                  \
                  unsigned long ulMin,                                        \
                  unsigned long ulMax))ROM_MCASPTABLE[39])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxClkChkCount                                                \
        ((unsigned long (*)(unsigned long ulBase))ROM_MCASPTABLE[40])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPPinDirGet                                                    \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            unsigned long ulPin))ROM_MCASPTABLE[41])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxFMTConfig                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFdelay,                                    \
                  unsigned long ulPad,                                        \
                   unsigned long ulSlot,                                      \
                   unsigned long ulWord,                                      \
                   unsigned long ulAlign,                                     \
                   unsigned long ulOrder,                                     \
                   unsigned long ulDspRep))ROM_MCASPTABLE[42])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxFMTConfig                                                  \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulFdelay,                                    \
                  unsigned long ulPad,                                        \
                   unsigned long ulSlot,                                      \
                   unsigned long ulWord,                                      \
                   unsigned long ulAlign,                                     \
                   unsigned long ulOrder,                                     \
                   unsigned long ulDspRep))ROM_MCASPTABLE[43])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPDMAStatus                                                    \
        ((unsigned long (*)(unsigned long ulBase,                             \
                            tBoolean bMasked))ROM_MCASPTABLE[44])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPDMAClear                                                     \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDmaFlag))ROM_MCASPTABLE[45])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPDMAEnable                                                    \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDmaFlag))ROM_MCASPTABLE[46])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPDMADisable                                                   \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulDmaFlag))ROM_MCASPTABLE[47])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxFIFOEnable                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulLevel,                                     \
                   unsigned long ulWordspertransfer))ROM_MCASPTABLE[48])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxFIFOEnable                                                 \
        ((void (*)(unsigned long ulBase,                                      \
                   unsigned long ulLevel,                                     \
                   unsigned long ulWordspertransfer))ROM_MCASPTABLE[49])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPTxFIFODisable                                                \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[50])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_McASPRxFIFODisable                                                \
        ((void (*)(unsigned long ulBase))ROM_MCASPTABLE[51])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the HIB API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_HIBXtalClkEnable                                                  \
        ((void (*)(unsigned long ulTrim))ROM_HIBTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBXtalClkDfltEnable                                              \
        ((void (*)(void))ROM_HIBTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBEnter                                                          \
        ((void (*)(void))ROM_HIBTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBRTCEnable                                                      \
        ((void (*)(void))ROM_HIBTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBRTCRead                                                        \
        ((unsigned long long (*)(void))ROM_HIBTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBRTCWakeEnable                                                  \
        ((void (*)(unsigned long long ulWakeupVal))ROM_HIBTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBRTCWakeDisable                                                 \
        ((void (*)(void))ROM_HIBTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBEnableIRQ                                                      \
        ((void (*)(unsigned long long ulWakeupVal))ROM_HIBTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBDisableIRQ                                                     \
        ((void (*)(void))ROM_HIBTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBGPIOWakeEnable                                                 \
        ((void (*)(unsigned char ucGPIONum,                                   \
                   unsigned char ucGPIOCOnf))ROM_HIBTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBRetRegWrite                                                    \
        ((long (*)(unsigned char ucRegIndex,                                  \
                   unsigned long ulRegValue))ROM_HIBTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBRetRegRead                                                     \
        ((long (*)(unsigned char ucRegIndex,                                  \
                   unsigned long *ulRegVal))ROM_HIBTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBWakeupCauseGet                                                 \
        ((unsigned long (*)(void))ROM_HIBTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBLPDSWkupGPIOSet                                                \
        ((void (*)(unsigned long ucGPIOSel))ROM_HIBTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_HIBRTCReset                                                       \
        ((void (*)(void))ROM_HIBTABLE[14])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the GPIO API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_GPIODirModeSet                                                    \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned char ucPins,                                      \
                   unsigned long ulPinIO))ROM_GPIOTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIODirModeGet                                                    \
        ((unsigned long (*)(unsigned long ulPort,                             \
                            unsigned char ucPin))ROM_GPIOTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntTypeSet                                                    \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned char ucPins,                                      \
                   unsigned long ulIntType))ROM_GPIOTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntTypeGet                                                    \
        ((unsigned long (*)(unsigned long ulPort,                             \
                            unsigned char ucPin))ROM_GPIOTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntEnable                                                     \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned long ulIntFlags))ROM_GPIOTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntDisable                                                    \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned long ulIntFlags))ROM_GPIOTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntStatus                                                     \
        ((long (*)(unsigned long ulPort,                                      \
                   tBoolean bMasked))ROM_GPIOTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntClear                                                      \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned long ulIntFlags))ROM_GPIOTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntRegister                                                   \
        ((void (*)(unsigned long ulPort,                                      \
                   void (*pfnIntHandler)(void)))ROM_GPIOTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOIntUnregister                                                 \
        ((void (*)(unsigned long ulPort))ROM_GPIOTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOPinRead                                                       \
        ((long (*)(unsigned long ulPort,                                      \
                   unsigned char ucPins))ROM_GPIOTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOPinWrite                                                      \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned char ucPins,                                      \
                   unsigned char ucVal))ROM_GPIOTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOPinTypeGPIOInput                                              \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned char ucPins))ROM_GPIOTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIOPinTypeGPIOOutput                                             \
        ((void (*)(unsigned long ulPort,                                      \
                   unsigned char ucPins))ROM_GPIOTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIODMATriggerEnable                                              \
        ((void (*)(unsigned long ulPort))ROM_GPIOTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_GPIODMATriggerDisable                                             \
        ((void (*)(unsigned long ulPort))ROM_GPIOTABLE[15])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the AES API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_AESAuthLengthSet                                                  \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Length))ROM_AESTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESConfigSet                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Config))ROM_AESTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDataRead                                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Dest))ROM_AESTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDataReadNonBlocking                                            \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Dest))ROM_AESTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDataProcess                                                    \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src,                                        \
                   uint32_t *pui32Dest,                                       \
                   uint32_t ui32Length))ROM_AESTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDataAuth                                                       \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src,                                        \
                   uint32_t ui32Length,                                       \
                   uint32_t *pui32Tag))ROM_AESTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDataProcessAuth                                                \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src,                                        \
                   uint32_t *pui32Dest,                                       \
                   uint32_t ui32Length,                                       \
                   uint32_t *pui32AuthSrc,                                    \
                   uint32_t ui32AuthLength,                                   \
                   uint32_t *pui32Tag))ROM_AESTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDataWrite                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_AESTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDataWriteNonBlocking                                           \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_AESTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDMADisable                                                     \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Flags))ROM_AESTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESDMAEnable                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Flags))ROM_AESTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESIntClear                                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_AESTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESIntDisable                                                     \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_AESTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESIntEnable                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_AESTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESIntRegister                                                    \
        ((void (*)(uint32_t ui32Base,                                         \
                   void(*pfnHandler)(void)))ROM_AESTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESIntStatus                                                      \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       bool bMasked))ROM_AESTABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESIntUnregister                                                  \
        ((void (*)(uint32_t ui32Base))ROM_AESTABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESIVSet                                                          \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32IVdata))ROM_AESTABLE[17])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESKey1Set                                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Key,                                        \
                   uint32_t ui32Keysize))ROM_AESTABLE[18])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESKey2Set                                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Key,                                        \
                   uint32_t ui32Keysize))ROM_AESTABLE[19])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESKey3Set                                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Key))ROM_AESTABLE[20])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESLengthSet                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint64_t ui64Length))ROM_AESTABLE[21])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_AESTagRead                                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32TagData))ROM_AESTABLE[22])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the DES API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_DESConfigSet                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Config))ROM_DESTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESDataRead                                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Dest))ROM_DESTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESDataReadNonBlocking                                            \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Dest))ROM_DESTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESDataProcess                                                    \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src,                                        \
                   uint32_t *pui32Dest,                                       \
                   uint32_t ui32Length))ROM_DESTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESDataWrite                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_DESTABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESDataWriteNonBlocking                                           \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_DESTABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESDMADisable                                                     \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Flags))ROM_DESTABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESDMAEnable                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Flags))ROM_DESTABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESIntClear                                                       \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_DESTABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESIntDisable                                                     \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_DESTABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESIntEnable                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_DESTABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESIntRegister                                                    \
        ((void (*)(uint32_t ui32Base,                                         \
                   void(*pfnHandler)(void)))ROM_DESTABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESIntStatus                                                      \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       bool bMasked))ROM_DESTABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESIntUnregister                                                  \
        ((void (*)(uint32_t ui32Base))ROM_DESTABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESIVSet                                                          \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32IVdata))ROM_DESTABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESKeySet                                                         \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Key))ROM_DESTABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_DESLengthSet                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Length))ROM_DESTABLE[16])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the SHAMD5 API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5ConfigSet                                                   \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Mode))ROM_SHAMD5TABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5DataProcess                                                 \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32DataSrc,                                    \
                   uint32_t ui32DataLength,                                   \
                   uint32_t *pui32HashResult))ROM_SHAMD5TABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5DataWrite                                                   \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_SHAMD5TABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5DataWriteNonBlocking                                        \
        ((bool (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_SHAMD5TABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5DMADisable                                                  \
        ((void (*)(uint32_t ui32Base))ROM_SHAMD5TABLE[4])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5DMAEnable                                                   \
        ((void (*)(uint32_t ui32Base))ROM_SHAMD5TABLE[5])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5HashLengthSet                                               \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Length))ROM_SHAMD5TABLE[6])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5HMACKeySet                                                  \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_SHAMD5TABLE[7])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5HMACPPKeyGenerate                                           \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Key,                                        \
                   uint32_t *pui32PPKey))ROM_SHAMD5TABLE[8])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5HMACPPKeySet                                                \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Src))ROM_SHAMD5TABLE[9])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5HMACProcess                                                 \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32DataSrc,                                    \
                   uint32_t ui32DataLength,                                   \
                   uint32_t *pui32HashResult))ROM_SHAMD5TABLE[10])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5IntClear                                                    \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_SHAMD5TABLE[11])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5IntDisable                                                  \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_SHAMD5TABLE[12])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5IntEnable                                                   \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32IntFlags))ROM_SHAMD5TABLE[13])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5IntRegister                                                 \
        ((void (*)(uint32_t ui32Base,                                         \
                   void(*pfnHandler)(void)))ROM_SHAMD5TABLE[14])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5IntStatus                                                   \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       bool bMasked))ROM_SHAMD5TABLE[15])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5IntUnregister                                               \
        ((void (*)(uint32_t ui32Base))ROM_SHAMD5TABLE[16])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_SHAMD5ResultRead                                                  \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t *pui32Dest))ROM_SHAMD5TABLE[17])
#endif

//*****************************************************************************
//
// Macros for calling ROM functions in the CRC API.
//
//*****************************************************************************
#if defined(TARGET_IS_CC3101)
#define ROM_CRCConfigSet                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32CRCConfig))ROM_CRCTABLE[0])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CRCDataProcess                                                    \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       uint32_t *pui32DataIn,                                 \
                       uint32_t ui32DataLength,                               \
                       bool bPPResult))ROM_CRCTABLE[1])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CRCDataWrite                                                      \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Data))ROM_CRCTABLE[2])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CRCResultRead                                                     \
        ((uint32_t (*)(uint32_t ui32Base,                                     \
                       bool bPPResult))ROM_CRCTABLE[3])
#endif
#if defined(TARGET_IS_CC3101)
#define ROM_CRCSeedSet                                                        \
        ((void (*)(uint32_t ui32Base,                                         \
                   uint32_t ui32Seed))ROM_CRCTABLE[4])
#endif

#endif // __ROM_H__
