//*****************************************************************************
//
// rom_map.h - Macros to facilitate calling functions in the ROM when they are
//             available and in flash otherwise.
//
// Copyright (c) 2008 Texas Instruments Incorporated.  All rights reserved.
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

#ifndef __ROM_MAP_H__
#define __ROM_MAP_H__

//*****************************************************************************
//
// Macros for the Interrupt API.
//
//*****************************************************************************
#ifdef ROM_IntEnable
#define MAP_IntEnable \
        ROM_IntEnable
#else
#define MAP_IntEnable \
        IntEnable
#endif
#ifdef ROM_IntMasterEnable
#define MAP_IntMasterEnable \
        ROM_IntMasterEnable
#else
#define MAP_IntMasterEnable \
        IntMasterEnable
#endif
#ifdef ROM_IntMasterDisable
#define MAP_IntMasterDisable \
        ROM_IntMasterDisable
#else
#define MAP_IntMasterDisable \
        IntMasterDisable
#endif
#ifdef ROM_IntDisable
#define MAP_IntDisable \
        ROM_IntDisable
#else
#define MAP_IntDisable \
        IntDisable
#endif
#ifdef ROM_IntPriorityGroupingSet
#define MAP_IntPriorityGroupingSet \
        ROM_IntPriorityGroupingSet
#else
#define MAP_IntPriorityGroupingSet \
        IntPriorityGroupingSet
#endif
#ifdef ROM_IntPriorityGroupingGet
#define MAP_IntPriorityGroupingGet \
        ROM_IntPriorityGroupingGet
#else
#define MAP_IntPriorityGroupingGet \
        IntPriorityGroupingGet
#endif
#ifdef ROM_IntPrioritySet
#define MAP_IntPrioritySet \
        ROM_IntPrioritySet
#else
#define MAP_IntPrioritySet \
        IntPrioritySet
#endif
#ifdef ROM_IntPriorityGet
#define MAP_IntPriorityGet \
        ROM_IntPriorityGet
#else
#define MAP_IntPriorityGet \
        IntPriorityGet
#endif
#ifdef ROM_IntPendSet
#define MAP_IntPendSet \
        ROM_IntPendSet
#else
#define MAP_IntPendSet \
        IntPendSet
#endif
#ifdef ROM_IntPendClear
#define MAP_IntPendClear \
        ROM_IntPendClear
#else
#define MAP_IntPendClear \
        IntPendClear
#endif
#ifdef ROM_IntPriorityMaskSet
#define MAP_IntPriorityMaskSet \
        ROM_IntPriorityMaskSet
#else
#define MAP_IntPriorityMaskSet \
        IntPriorityMaskSet
#endif
#ifdef ROM_IntPriorityMaskGet
#define MAP_IntPriorityMaskGet \
        ROM_IntPriorityMaskGet
#else
#define MAP_IntPriorityMaskGet \
        IntPriorityMaskGet
#endif
#ifdef ROM_IntRegister
#define MAP_IntRegister \
        ROM_IntRegister
#else
#define MAP_IntRegister \
        IntRegister
#endif
#ifdef ROM_IntUnregister
#define MAP_IntUnregister \
        ROM_IntUnregister
#else
#define MAP_IntUnregister \
        IntUnregister
#endif
#ifdef ROM_IntVTableBaseSet
#define MAP_IntVTableBaseSet \
        ROM_IntVTableBaseSet
#else
#define MAP_IntVTableBaseSet \
        IntVTableBaseSet
#endif

//*****************************************************************************
//
// Macros for the Timer API.
//
//*****************************************************************************
#ifdef ROM_TimerEnable
#define MAP_TimerEnable \
        ROM_TimerEnable
#else
#define MAP_TimerEnable \
        TimerEnable
#endif
#ifdef ROM_TimerDisable
#define MAP_TimerDisable \
        ROM_TimerDisable
#else
#define MAP_TimerDisable \
        TimerDisable
#endif
#ifdef ROM_TimerConfigure
#define MAP_TimerConfigure \
        ROM_TimerConfigure
#else
#define MAP_TimerConfigure \
        TimerConfigure
#endif
#ifdef ROM_TimerControlLevel
#define MAP_TimerControlLevel \
        ROM_TimerControlLevel
#else
#define MAP_TimerControlLevel \
        TimerControlLevel
#endif
#ifdef ROM_TimerControlTrigger
#define MAP_TimerControlTrigger \
        ROM_TimerControlTrigger
#else
#define MAP_TimerControlTrigger \
        TimerControlTrigger
#endif
#ifdef ROM_TimerControlEvent
#define MAP_TimerControlEvent \
        ROM_TimerControlEvent
#else
#define MAP_TimerControlEvent \
        TimerControlEvent
#endif
#ifdef ROM_TimerControlStall
#define MAP_TimerControlStall \
        ROM_TimerControlStall
#else
#define MAP_TimerControlStall \
        TimerControlStall
#endif
#ifdef ROM_TimerControlWaitOnTrigger
#define MAP_TimerControlWaitOnTrigger \
        ROM_TimerControlWaitOnTrigger
#else
#define MAP_TimerControlWaitOnTrigger \
        TimerControlWaitOnTrigger
#endif
#ifdef ROM_TimerPrescaleSet
#define MAP_TimerPrescaleSet \
        ROM_TimerPrescaleSet
#else
#define MAP_TimerPrescaleSet \
        TimerPrescaleSet
#endif
#ifdef ROM_TimerPrescaleGet
#define MAP_TimerPrescaleGet \
        ROM_TimerPrescaleGet
#else
#define MAP_TimerPrescaleGet \
        TimerPrescaleGet
#endif
#ifdef ROM_TimerPrescaleMatchSet
#define MAP_TimerPrescaleMatchSet \
        ROM_TimerPrescaleMatchSet
#else
#define MAP_TimerPrescaleMatchSet \
        TimerPrescaleMatchSet
#endif
#ifdef ROM_TimerPrescaleMatchGet
#define MAP_TimerPrescaleMatchGet \
        ROM_TimerPrescaleMatchGet
#else
#define MAP_TimerPrescaleMatchGet \
        TimerPrescaleMatchGet
#endif
#ifdef ROM_TimerLoadSet
#define MAP_TimerLoadSet \
        ROM_TimerLoadSet
#else
#define MAP_TimerLoadSet \
        TimerLoadSet
#endif
#ifdef ROM_TimerLoadGet
#define MAP_TimerLoadGet \
        ROM_TimerLoadGet
#else
#define MAP_TimerLoadGet \
        TimerLoadGet
#endif
#ifdef ROM_TimerValueGet
#define MAP_TimerValueGet \
        ROM_TimerValueGet
#else
#define MAP_TimerValueGet \
        TimerValueGet
#endif
#ifdef ROM_TimerMatchSet
#define MAP_TimerMatchSet \
        ROM_TimerMatchSet
#else
#define MAP_TimerMatchSet \
        TimerMatchSet
#endif
#ifdef ROM_TimerMatchGet
#define MAP_TimerMatchGet \
        ROM_TimerMatchGet
#else
#define MAP_TimerMatchGet \
        TimerMatchGet
#endif
#ifdef ROM_TimerIntRegister
#define MAP_TimerIntRegister \
        ROM_TimerIntRegister
#else
#define MAP_TimerIntRegister \
        TimerIntRegister
#endif
#ifdef ROM_TimerIntUnregister
#define MAP_TimerIntUnregister \
        ROM_TimerIntUnregister
#else
#define MAP_TimerIntUnregister \
        TimerIntUnregister
#endif
#ifdef ROM_TimerIntEnable
#define MAP_TimerIntEnable \
        ROM_TimerIntEnable
#else
#define MAP_TimerIntEnable \
        TimerIntEnable
#endif
#ifdef ROM_TimerIntDisable
#define MAP_TimerIntDisable \
        ROM_TimerIntDisable
#else
#define MAP_TimerIntDisable \
        TimerIntDisable
#endif
#ifdef ROM_TimerIntStatus
#define MAP_TimerIntStatus \
        ROM_TimerIntStatus
#else
#define MAP_TimerIntStatus \
        TimerIntStatus
#endif
#ifdef ROM_TimerIntClear
#define MAP_TimerIntClear \
        ROM_TimerIntClear
#else
#define MAP_TimerIntClear \
        TimerIntClear
#endif
#ifdef ROM_TimerSynchronize
#define MAP_TimerSynchronize \
        ROM_TimerSynchronize
#else
#define MAP_TimerSynchronize \
        TimerSynchronize
#endif

//*****************************************************************************
//
// Macros for the UART API.
//
//*****************************************************************************
#ifdef ROM_UARTParityModeSet
#define MAP_UARTParityModeSet \
        ROM_UARTParityModeSet
#else
#define MAP_UARTParityModeSet \
        UARTParityModeSet
#endif
#ifdef ROM_UARTParityModeGet
#define MAP_UARTParityModeGet \
        ROM_UARTParityModeGet
#else
#define MAP_UARTParityModeGet \
        UARTParityModeGet
#endif
#ifdef ROM_UARTFIFOLevelSet
#define MAP_UARTFIFOLevelSet \
        ROM_UARTFIFOLevelSet
#else
#define MAP_UARTFIFOLevelSet \
        UARTFIFOLevelSet
#endif
#ifdef ROM_UARTFIFOLevelGet
#define MAP_UARTFIFOLevelGet \
        ROM_UARTFIFOLevelGet
#else
#define MAP_UARTFIFOLevelGet \
        UARTFIFOLevelGet
#endif
#ifdef ROM_UARTConfigSetExpClk
#define MAP_UARTConfigSetExpClk \
        ROM_UARTConfigSetExpClk
#else
#define MAP_UARTConfigSetExpClk \
        UARTConfigSetExpClk
#endif
#ifdef ROM_UARTConfigGetExpClk
#define MAP_UARTConfigGetExpClk \
        ROM_UARTConfigGetExpClk
#else
#define MAP_UARTConfigGetExpClk \
        UARTConfigGetExpClk
#endif
#ifdef ROM_UARTEnable
#define MAP_UARTEnable \
        ROM_UARTEnable
#else
#define MAP_UARTEnable \
        UARTEnable
#endif
#ifdef ROM_UARTDisable
#define MAP_UARTDisable \
        ROM_UARTDisable
#else
#define MAP_UARTDisable \
        UARTDisable
#endif
#ifdef ROM_UARTFIFOEnable
#define MAP_UARTFIFOEnable \
        ROM_UARTFIFOEnable
#else
#define MAP_UARTFIFOEnable \
        UARTFIFOEnable
#endif
#ifdef ROM_UARTFIFODisable
#define MAP_UARTFIFODisable \
        ROM_UARTFIFODisable
#else
#define MAP_UARTFIFODisable \
        UARTFIFODisable
#endif
#ifdef ROM_UARTEnableSIR
#define MAP_UARTEnableSIR \
        ROM_UARTEnableSIR
#else
#define MAP_UARTEnableSIR \
        UARTEnableSIR
#endif
#ifdef ROM_UARTDisableSIR
#define MAP_UARTDisableSIR \
        ROM_UARTDisableSIR
#else
#define MAP_UARTDisableSIR \
        UARTDisableSIR
#endif
#ifdef ROM_UARTCharsAvail
#define MAP_UARTCharsAvail \
        ROM_UARTCharsAvail
#else
#define MAP_UARTCharsAvail \
        UARTCharsAvail
#endif
#ifdef ROM_UARTSpaceAvail
#define MAP_UARTSpaceAvail \
        ROM_UARTSpaceAvail
#else
#define MAP_UARTSpaceAvail \
        UARTSpaceAvail
#endif
#ifdef ROM_UARTCharGetNonBlocking
#define MAP_UARTCharGetNonBlocking \
        ROM_UARTCharGetNonBlocking
#else
#define MAP_UARTCharGetNonBlocking \
        UARTCharGetNonBlocking
#endif
#ifdef ROM_UARTCharGet
#define MAP_UARTCharGet \
        ROM_UARTCharGet
#else
#define MAP_UARTCharGet \
        UARTCharGet
#endif
#ifdef ROM_UARTCharPutNonBlocking
#define MAP_UARTCharPutNonBlocking \
        ROM_UARTCharPutNonBlocking
#else
#define MAP_UARTCharPutNonBlocking \
        UARTCharPutNonBlocking
#endif
#ifdef ROM_UARTCharPut
#define MAP_UARTCharPut \
        ROM_UARTCharPut
#else
#define MAP_UARTCharPut \
        UARTCharPut
#endif
#ifdef ROM_UARTBreakCtl
#define MAP_UARTBreakCtl \
        ROM_UARTBreakCtl
#else
#define MAP_UARTBreakCtl \
        UARTBreakCtl
#endif
#ifdef ROM_UARTBusy
#define MAP_UARTBusy \
        ROM_UARTBusy
#else
#define MAP_UARTBusy \
        UARTBusy
#endif
#ifdef ROM_UARTIntRegister
#define MAP_UARTIntRegister \
        ROM_UARTIntRegister
#else
#define MAP_UARTIntRegister \
        UARTIntRegister
#endif
#ifdef ROM_UARTIntUnregister
#define MAP_UARTIntUnregister \
        ROM_UARTIntUnregister
#else
#define MAP_UARTIntUnregister \
        UARTIntUnregister
#endif
#ifdef ROM_UARTIntEnable
#define MAP_UARTIntEnable \
        ROM_UARTIntEnable
#else
#define MAP_UARTIntEnable \
        UARTIntEnable
#endif
#ifdef ROM_UARTIntDisable
#define MAP_UARTIntDisable \
        ROM_UARTIntDisable
#else
#define MAP_UARTIntDisable \
        UARTIntDisable
#endif
#ifdef ROM_UARTIntStatus
#define MAP_UARTIntStatus \
        ROM_UARTIntStatus
#else
#define MAP_UARTIntStatus \
        UARTIntStatus
#endif
#ifdef ROM_UARTIntClear
#define MAP_UARTIntClear \
        ROM_UARTIntClear
#else
#define MAP_UARTIntClear \
        UARTIntClear
#endif
#ifdef ROM_UARTDMAEnable
#define MAP_UARTDMAEnable \
        ROM_UARTDMAEnable
#else
#define MAP_UARTDMAEnable \
        UARTDMAEnable
#endif
#ifdef ROM_UARTDMADisable
#define MAP_UARTDMADisable \
        ROM_UARTDMADisable
#else
#define MAP_UARTDMADisable \
        UARTDMADisable
#endif
#ifdef ROM_UARTRxErrorGet
#define MAP_UARTRxErrorGet \
        ROM_UARTRxErrorGet
#else
#define MAP_UARTRxErrorGet \
        UARTRxErrorGet
#endif
#ifdef ROM_UARTRxErrorClear
#define MAP_UARTRxErrorClear \
        ROM_UARTRxErrorClear
#else
#define MAP_UARTRxErrorClear \
        UARTRxErrorClear
#endif
#ifdef ROM_UARTModemControlSet
#define MAP_UARTModemControlSet \
        ROM_UARTModemControlSet
#else
#define MAP_UARTModemControlSet \
        UARTModemControlSet
#endif
#ifdef ROM_UARTModemControlClear
#define MAP_UARTModemControlClear \
        ROM_UARTModemControlClear
#else
#define MAP_UARTModemControlClear \
        UARTModemControlClear
#endif
#ifdef ROM_UARTModemControlGet
#define MAP_UARTModemControlGet \
        ROM_UARTModemControlGet
#else
#define MAP_UARTModemControlGet \
        UARTModemControlGet
#endif
#ifdef ROM_UARTModemStatusGet
#define MAP_UARTModemStatusGet \
        ROM_UARTModemStatusGet
#else
#define MAP_UARTModemStatusGet \
        UARTModemStatusGet
#endif
#ifdef ROM_UARTFlowControlSet
#define MAP_UARTFlowControlSet \
        ROM_UARTFlowControlSet
#else
#define MAP_UARTFlowControlSet \
        UARTFlowControlSet
#endif
#ifdef ROM_UARTFlowControlGet
#define MAP_UARTFlowControlGet \
        ROM_UARTFlowControlGet
#else
#define MAP_UARTFlowControlGet \
        UARTFlowControlGet
#endif
#ifdef ROM_UARTTxIntModeSet
#define MAP_UARTTxIntModeSet \
        ROM_UARTTxIntModeSet
#else
#define MAP_UARTTxIntModeSet \
        UARTTxIntModeSet
#endif
#ifdef ROM_UARTTxIntModeGet
#define MAP_UARTTxIntModeGet \
        ROM_UARTTxIntModeGet
#else
#define MAP_UARTTxIntModeGet \
        UARTTxIntModeGet
#endif
#ifdef ROM_UARTClockSourceSet
#define MAP_UARTClockSourceSet \
        ROM_UARTClockSourceSet
#else
#define MAP_UARTClockSourceSet \
        UARTClockSourceSet
#endif
#ifdef ROM_UARTClockSourceGet
#define MAP_UARTClockSourceGet \
        ROM_UARTClockSourceGet
#else
#define MAP_UARTClockSourceGet \
        UARTClockSourceGet
#endif

//*****************************************************************************
//
// Macros for the uDMA API.
//
//*****************************************************************************
#ifdef ROM_uDMAChannelTransferSet
#define MAP_uDMAChannelTransferSet \
        ROM_uDMAChannelTransferSet
#else
#define MAP_uDMAChannelTransferSet \
        uDMAChannelTransferSet
#endif
#ifdef ROM_uDMAEnable
#define MAP_uDMAEnable \
        ROM_uDMAEnable
#else
#define MAP_uDMAEnable \
        uDMAEnable
#endif
#ifdef ROM_uDMADisable
#define MAP_uDMADisable \
        ROM_uDMADisable
#else
#define MAP_uDMADisable \
        uDMADisable
#endif
#ifdef ROM_uDMAErrorStatusGet
#define MAP_uDMAErrorStatusGet \
        ROM_uDMAErrorStatusGet
#else
#define MAP_uDMAErrorStatusGet \
        uDMAErrorStatusGet
#endif
#ifdef ROM_uDMAErrorStatusClear
#define MAP_uDMAErrorStatusClear \
        ROM_uDMAErrorStatusClear
#else
#define MAP_uDMAErrorStatusClear \
        uDMAErrorStatusClear
#endif
#ifdef ROM_uDMAChannelEnable
#define MAP_uDMAChannelEnable \
        ROM_uDMAChannelEnable
#else
#define MAP_uDMAChannelEnable \
        uDMAChannelEnable
#endif
#ifdef ROM_uDMAChannelDisable
#define MAP_uDMAChannelDisable \
        ROM_uDMAChannelDisable
#else
#define MAP_uDMAChannelDisable \
        uDMAChannelDisable
#endif
#ifdef ROM_uDMAChannelIsEnabled
#define MAP_uDMAChannelIsEnabled \
        ROM_uDMAChannelIsEnabled
#else
#define MAP_uDMAChannelIsEnabled \
        uDMAChannelIsEnabled
#endif
#ifdef ROM_uDMAControlBaseSet
#define MAP_uDMAControlBaseSet \
        ROM_uDMAControlBaseSet
#else
#define MAP_uDMAControlBaseSet \
        uDMAControlBaseSet
#endif
#ifdef ROM_uDMAControlBaseGet
#define MAP_uDMAControlBaseGet \
        ROM_uDMAControlBaseGet
#else
#define MAP_uDMAControlBaseGet \
        uDMAControlBaseGet
#endif
#ifdef ROM_uDMAChannelRequest
#define MAP_uDMAChannelRequest \
        ROM_uDMAChannelRequest
#else
#define MAP_uDMAChannelRequest \
        uDMAChannelRequest
#endif
#ifdef ROM_uDMAChannelAttributeEnable
#define MAP_uDMAChannelAttributeEnable \
        ROM_uDMAChannelAttributeEnable
#else
#define MAP_uDMAChannelAttributeEnable \
        uDMAChannelAttributeEnable
#endif
#ifdef ROM_uDMAChannelAttributeDisable
#define MAP_uDMAChannelAttributeDisable \
        ROM_uDMAChannelAttributeDisable
#else
#define MAP_uDMAChannelAttributeDisable \
        uDMAChannelAttributeDisable
#endif
#ifdef ROM_uDMAChannelAttributeGet
#define MAP_uDMAChannelAttributeGet \
        ROM_uDMAChannelAttributeGet
#else
#define MAP_uDMAChannelAttributeGet \
        uDMAChannelAttributeGet
#endif
#ifdef ROM_uDMAChannelControlSet
#define MAP_uDMAChannelControlSet \
        ROM_uDMAChannelControlSet
#else
#define MAP_uDMAChannelControlSet \
        uDMAChannelControlSet
#endif
#ifdef ROM_uDMAChannelSizeGet
#define MAP_uDMAChannelSizeGet \
        ROM_uDMAChannelSizeGet
#else
#define MAP_uDMAChannelSizeGet \
        uDMAChannelSizeGet
#endif
#ifdef ROM_uDMAChannelModeGet
#define MAP_uDMAChannelModeGet \
        ROM_uDMAChannelModeGet
#else
#define MAP_uDMAChannelModeGet \
        uDMAChannelModeGet
#endif
#ifdef ROM_uDMAIntStatus
#define MAP_uDMAIntStatus \
        ROM_uDMAIntStatus
#else
#define MAP_uDMAIntStatus \
        uDMAIntStatus
#endif
#ifdef ROM_uDMAIntClear
#define MAP_uDMAIntClear \
        ROM_uDMAIntClear
#else
#define MAP_uDMAIntClear \
        uDMAIntClear
#endif
#ifdef ROM_uDMAControlAlternateBaseGet
#define MAP_uDMAControlAlternateBaseGet \
        ROM_uDMAControlAlternateBaseGet
#else
#define MAP_uDMAControlAlternateBaseGet \
        uDMAControlAlternateBaseGet
#endif
#ifdef ROM_uDMAChannelScatterGatherSet
#define MAP_uDMAChannelScatterGatherSet \
        ROM_uDMAChannelScatterGatherSet
#else
#define MAP_uDMAChannelScatterGatherSet \
        uDMAChannelScatterGatherSet
#endif
#ifdef ROM_uDMAChannelAssign
#define MAP_uDMAChannelAssign \
        ROM_uDMAChannelAssign
#else
#define MAP_uDMAChannelAssign \
        uDMAChannelAssign
#endif
#ifdef ROM_uDMAIntRegister
#define MAP_uDMAIntRegister \
        ROM_uDMAIntRegister
#else
#define MAP_uDMAIntRegister \
        uDMAIntRegister
#endif
#ifdef ROM_uDMAIntUnregister
#define MAP_uDMAIntUnregister \
        ROM_uDMAIntUnregister
#else
#define MAP_uDMAIntUnregister \
        uDMAIntUnregister
#endif

//*****************************************************************************
//
// Macros for the Watchdog API.
//
//*****************************************************************************
#ifdef ROM_WatchdogIntClear
#define MAP_WatchdogIntClear \
        ROM_WatchdogIntClear
#else
#define MAP_WatchdogIntClear \
        WatchdogIntClear
#endif
#ifdef ROM_WatchdogRunning
#define MAP_WatchdogRunning \
        ROM_WatchdogRunning
#else
#define MAP_WatchdogRunning \
        WatchdogRunning
#endif
#ifdef ROM_WatchdogEnable
#define MAP_WatchdogEnable \
        ROM_WatchdogEnable
#else
#define MAP_WatchdogEnable \
        WatchdogEnable
#endif
#ifdef ROM_WatchdogLock
#define MAP_WatchdogLock \
        ROM_WatchdogLock
#else
#define MAP_WatchdogLock \
        WatchdogLock
#endif
#ifdef ROM_WatchdogUnlock
#define MAP_WatchdogUnlock \
        ROM_WatchdogUnlock
#else
#define MAP_WatchdogUnlock \
        WatchdogUnlock
#endif
#ifdef ROM_WatchdogLockState
#define MAP_WatchdogLockState \
        ROM_WatchdogLockState
#else
#define MAP_WatchdogLockState \
        WatchdogLockState
#endif
#ifdef ROM_WatchdogReloadSet
#define MAP_WatchdogReloadSet \
        ROM_WatchdogReloadSet
#else
#define MAP_WatchdogReloadSet \
        WatchdogReloadSet
#endif
#ifdef ROM_WatchdogReloadGet
#define MAP_WatchdogReloadGet \
        ROM_WatchdogReloadGet
#else
#define MAP_WatchdogReloadGet \
        WatchdogReloadGet
#endif
#ifdef ROM_WatchdogValueGet
#define MAP_WatchdogValueGet \
        ROM_WatchdogValueGet
#else
#define MAP_WatchdogValueGet \
        WatchdogValueGet
#endif
#ifdef ROM_WatchdogIntEnable
#define MAP_WatchdogIntEnable \
        ROM_WatchdogIntEnable
#else
#define MAP_WatchdogIntEnable \
        WatchdogIntEnable
#endif
#ifdef ROM_WatchdogIntStatus
#define MAP_WatchdogIntStatus \
        ROM_WatchdogIntStatus
#else
#define MAP_WatchdogIntStatus \
        WatchdogIntStatus
#endif
#ifdef ROM_WatchdogStallEnable
#define MAP_WatchdogStallEnable \
        ROM_WatchdogStallEnable
#else
#define MAP_WatchdogStallEnable \
        WatchdogStallEnable
#endif
#ifdef ROM_WatchdogStallDisable
#define MAP_WatchdogStallDisable \
        ROM_WatchdogStallDisable
#else
#define MAP_WatchdogStallDisable \
        WatchdogStallDisable
#endif
#ifdef ROM_WatchdogIntTypeSet
#define MAP_WatchdogIntTypeSet \
        ROM_WatchdogIntTypeSet
#else
#define MAP_WatchdogIntTypeSet \
        WatchdogIntTypeSet
#endif
#ifdef ROM_WatchdogIntRegister
#define MAP_WatchdogIntRegister \
        ROM_WatchdogIntRegister
#else
#define MAP_WatchdogIntRegister \
        WatchdogIntRegister
#endif
#ifdef ROM_WatchdogIntUnregister
#define MAP_WatchdogIntUnregister \
        ROM_WatchdogIntUnregister
#else
#define MAP_WatchdogIntUnregister \
        WatchdogIntUnregister
#endif

//*****************************************************************************
//
// Macros for the I2C API.
//
//*****************************************************************************
#ifdef ROM_I2CIntRegister
#define MAP_I2CIntRegister \
        ROM_I2CIntRegister
#else
#define MAP_I2CIntRegister \
        I2CIntRegister
#endif
#ifdef ROM_I2CIntUnregister
#define MAP_I2CIntUnregister \
        ROM_I2CIntUnregister
#else
#define MAP_I2CIntUnregister \
        I2CIntUnregister
#endif
#ifdef ROM_I2CTxFIFOConfigSet
#define MAP_I2CTxFIFOConfigSet \
        ROM_I2CTxFIFOConfigSet
#else
#define MAP_I2CTxFIFOConfigSet \
        I2CTxFIFOConfigSet
#endif
#ifdef ROM_I2CTxFIFOFlush
#define MAP_I2CTxFIFOFlush \
        ROM_I2CTxFIFOFlush
#else
#define MAP_I2CTxFIFOFlush \
        I2CTxFIFOFlush
#endif
#ifdef ROM_I2CRxFIFOConfigSet
#define MAP_I2CRxFIFOConfigSet \
        ROM_I2CRxFIFOConfigSet
#else
#define MAP_I2CRxFIFOConfigSet \
        I2CRxFIFOConfigSet
#endif
#ifdef ROM_I2CRxFIFOFlush
#define MAP_I2CRxFIFOFlush \
        ROM_I2CRxFIFOFlush
#else
#define MAP_I2CRxFIFOFlush \
        I2CRxFIFOFlush
#endif
#ifdef ROM_I2CFIFOStatus
#define MAP_I2CFIFOStatus \
        ROM_I2CFIFOStatus
#else
#define MAP_I2CFIFOStatus \
        I2CFIFOStatus
#endif
#ifdef ROM_I2CFIFODataPut
#define MAP_I2CFIFODataPut \
        ROM_I2CFIFODataPut
#else
#define MAP_I2CFIFODataPut \
        I2CFIFODataPut
#endif
#ifdef ROM_I2CFIFODataPutNonBlocking
#define MAP_I2CFIFODataPutNonBlocking \
        ROM_I2CFIFODataPutNonBlocking
#else
#define MAP_I2CFIFODataPutNonBlocking \
        I2CFIFODataPutNonBlocking
#endif
#ifdef ROM_I2CFIFODataGet
#define MAP_I2CFIFODataGet \
        ROM_I2CFIFODataGet
#else
#define MAP_I2CFIFODataGet \
        I2CFIFODataGet
#endif
#ifdef ROM_I2CFIFODataGetNonBlocking
#define MAP_I2CFIFODataGetNonBlocking \
        ROM_I2CFIFODataGetNonBlocking
#else
#define MAP_I2CFIFODataGetNonBlocking \
        I2CFIFODataGetNonBlocking
#endif
#ifdef ROM_I2CMasterBurstLengthSet
#define MAP_I2CMasterBurstLengthSet \
        ROM_I2CMasterBurstLengthSet
#else
#define MAP_I2CMasterBurstLengthSet \
        I2CMasterBurstLengthSet
#endif
#ifdef ROM_I2CMasterBurstCountGet
#define MAP_I2CMasterBurstCountGet \
        ROM_I2CMasterBurstCountGet
#else
#define MAP_I2CMasterBurstCountGet \
        I2CMasterBurstCountGet
#endif
#ifdef ROM_I2CMasterGlitchFilterConfigSet
#define MAP_I2CMasterGlitchFilterConfigSet \
        ROM_I2CMasterGlitchFilterConfigSet
#else
#define MAP_I2CMasterGlitchFilterConfigSet \
        I2CMasterGlitchFilterConfigSet
#endif
#ifdef ROM_I2CSlaveFIFOEnable
#define MAP_I2CSlaveFIFOEnable \
        ROM_I2CSlaveFIFOEnable
#else
#define MAP_I2CSlaveFIFOEnable \
        I2CSlaveFIFOEnable
#endif
#ifdef ROM_I2CSlaveFIFODisable
#define MAP_I2CSlaveFIFODisable \
        ROM_I2CSlaveFIFODisable
#else
#define MAP_I2CSlaveFIFODisable \
        I2CSlaveFIFODisable
#endif
#ifdef ROM_I2CMasterBusBusy
#define MAP_I2CMasterBusBusy \
        ROM_I2CMasterBusBusy
#else
#define MAP_I2CMasterBusBusy \
        I2CMasterBusBusy
#endif
#ifdef ROM_I2CMasterBusy
#define MAP_I2CMasterBusy \
        ROM_I2CMasterBusy
#else
#define MAP_I2CMasterBusy \
        I2CMasterBusy
#endif
#ifdef ROM_I2CMasterControl
#define MAP_I2CMasterControl \
        ROM_I2CMasterControl
#else
#define MAP_I2CMasterControl \
        I2CMasterControl
#endif
#ifdef ROM_I2CMasterDataGet
#define MAP_I2CMasterDataGet \
        ROM_I2CMasterDataGet
#else
#define MAP_I2CMasterDataGet \
        I2CMasterDataGet
#endif
#ifdef ROM_I2CMasterDataPut
#define MAP_I2CMasterDataPut \
        ROM_I2CMasterDataPut
#else
#define MAP_I2CMasterDataPut \
        I2CMasterDataPut
#endif
#ifdef ROM_I2CMasterDisable
#define MAP_I2CMasterDisable \
        ROM_I2CMasterDisable
#else
#define MAP_I2CMasterDisable \
        I2CMasterDisable
#endif
#ifdef ROM_I2CMasterEnable
#define MAP_I2CMasterEnable \
        ROM_I2CMasterEnable
#else
#define MAP_I2CMasterEnable \
        I2CMasterEnable
#endif
#ifdef ROM_I2CMasterErr
#define MAP_I2CMasterErr \
        ROM_I2CMasterErr
#else
#define MAP_I2CMasterErr \
        I2CMasterErr
#endif
#ifdef ROM_I2CMasterIntClear
#define MAP_I2CMasterIntClear \
        ROM_I2CMasterIntClear
#else
#define MAP_I2CMasterIntClear \
        I2CMasterIntClear
#endif
#ifdef ROM_I2CMasterIntDisable
#define MAP_I2CMasterIntDisable \
        ROM_I2CMasterIntDisable
#else
#define MAP_I2CMasterIntDisable \
        I2CMasterIntDisable
#endif
#ifdef ROM_I2CMasterIntEnable
#define MAP_I2CMasterIntEnable \
        ROM_I2CMasterIntEnable
#else
#define MAP_I2CMasterIntEnable \
        I2CMasterIntEnable
#endif
#ifdef ROM_I2CMasterIntStatus
#define MAP_I2CMasterIntStatus \
        ROM_I2CMasterIntStatus
#else
#define MAP_I2CMasterIntStatus \
        I2CMasterIntStatus
#endif
#ifdef ROM_I2CMasterIntEnableEx
#define MAP_I2CMasterIntEnableEx \
        ROM_I2CMasterIntEnableEx
#else
#define MAP_I2CMasterIntEnableEx \
        I2CMasterIntEnableEx
#endif
#ifdef ROM_I2CMasterIntDisableEx
#define MAP_I2CMasterIntDisableEx \
        ROM_I2CMasterIntDisableEx
#else
#define MAP_I2CMasterIntDisableEx \
        I2CMasterIntDisableEx
#endif
#ifdef ROM_I2CMasterIntStatusEx
#define MAP_I2CMasterIntStatusEx \
        ROM_I2CMasterIntStatusEx
#else
#define MAP_I2CMasterIntStatusEx \
        I2CMasterIntStatusEx
#endif
#ifdef ROM_I2CMasterIntClearEx
#define MAP_I2CMasterIntClearEx \
        ROM_I2CMasterIntClearEx
#else
#define MAP_I2CMasterIntClearEx \
        I2CMasterIntClearEx
#endif
#ifdef ROM_I2CMasterTimeoutSet
#define MAP_I2CMasterTimeoutSet \
        ROM_I2CMasterTimeoutSet
#else
#define MAP_I2CMasterTimeoutSet \
        I2CMasterTimeoutSet
#endif
#ifdef ROM_I2CSlaveACKOverride
#define MAP_I2CSlaveACKOverride \
        ROM_I2CSlaveACKOverride
#else
#define MAP_I2CSlaveACKOverride \
        I2CSlaveACKOverride
#endif
#ifdef ROM_I2CSlaveACKValueSet
#define MAP_I2CSlaveACKValueSet \
        ROM_I2CSlaveACKValueSet
#else
#define MAP_I2CSlaveACKValueSet \
        I2CSlaveACKValueSet
#endif
#ifdef ROM_I2CMasterLineStateGet
#define MAP_I2CMasterLineStateGet \
        ROM_I2CMasterLineStateGet
#else
#define MAP_I2CMasterLineStateGet \
        I2CMasterLineStateGet
#endif
#ifdef ROM_I2CMasterSlaveAddrSet
#define MAP_I2CMasterSlaveAddrSet \
        ROM_I2CMasterSlaveAddrSet
#else
#define MAP_I2CMasterSlaveAddrSet \
        I2CMasterSlaveAddrSet
#endif
#ifdef ROM_I2CSlaveDataGet
#define MAP_I2CSlaveDataGet \
        ROM_I2CSlaveDataGet
#else
#define MAP_I2CSlaveDataGet \
        I2CSlaveDataGet
#endif
#ifdef ROM_I2CSlaveDataPut
#define MAP_I2CSlaveDataPut \
        ROM_I2CSlaveDataPut
#else
#define MAP_I2CSlaveDataPut \
        I2CSlaveDataPut
#endif
#ifdef ROM_I2CSlaveDisable
#define MAP_I2CSlaveDisable \
        ROM_I2CSlaveDisable
#else
#define MAP_I2CSlaveDisable \
        I2CSlaveDisable
#endif
#ifdef ROM_I2CSlaveEnable
#define MAP_I2CSlaveEnable \
        ROM_I2CSlaveEnable
#else
#define MAP_I2CSlaveEnable \
        I2CSlaveEnable
#endif
#ifdef ROM_I2CSlaveInit
#define MAP_I2CSlaveInit \
        ROM_I2CSlaveInit
#else
#define MAP_I2CSlaveInit \
        I2CSlaveInit
#endif
#ifdef ROM_I2CSlaveAddressSet
#define MAP_I2CSlaveAddressSet \
        ROM_I2CSlaveAddressSet
#else
#define MAP_I2CSlaveAddressSet \
        I2CSlaveAddressSet
#endif
#ifdef ROM_I2CSlaveIntClear
#define MAP_I2CSlaveIntClear \
        ROM_I2CSlaveIntClear
#else
#define MAP_I2CSlaveIntClear \
        I2CSlaveIntClear
#endif
#ifdef ROM_I2CSlaveIntDisable
#define MAP_I2CSlaveIntDisable \
        ROM_I2CSlaveIntDisable
#else
#define MAP_I2CSlaveIntDisable \
        I2CSlaveIntDisable
#endif
#ifdef ROM_I2CSlaveIntEnable
#define MAP_I2CSlaveIntEnable \
        ROM_I2CSlaveIntEnable
#else
#define MAP_I2CSlaveIntEnable \
        I2CSlaveIntEnable
#endif
#ifdef ROM_I2CSlaveIntClearEx
#define MAP_I2CSlaveIntClearEx \
        ROM_I2CSlaveIntClearEx
#else
#define MAP_I2CSlaveIntClearEx \
        I2CSlaveIntClearEx
#endif
#ifdef ROM_I2CSlaveIntDisableEx
#define MAP_I2CSlaveIntDisableEx \
        ROM_I2CSlaveIntDisableEx
#else
#define MAP_I2CSlaveIntDisableEx \
        I2CSlaveIntDisableEx
#endif
#ifdef ROM_I2CSlaveIntEnableEx
#define MAP_I2CSlaveIntEnableEx \
        ROM_I2CSlaveIntEnableEx
#else
#define MAP_I2CSlaveIntEnableEx \
        I2CSlaveIntEnableEx
#endif
#ifdef ROM_I2CSlaveIntStatus
#define MAP_I2CSlaveIntStatus \
        ROM_I2CSlaveIntStatus
#else
#define MAP_I2CSlaveIntStatus \
        I2CSlaveIntStatus
#endif
#ifdef ROM_I2CSlaveIntStatusEx
#define MAP_I2CSlaveIntStatusEx \
        ROM_I2CSlaveIntStatusEx
#else
#define MAP_I2CSlaveIntStatusEx \
        I2CSlaveIntStatusEx
#endif
#ifdef ROM_I2CSlaveStatus
#define MAP_I2CSlaveStatus \
        ROM_I2CSlaveStatus
#else
#define MAP_I2CSlaveStatus \
        I2CSlaveStatus
#endif
#ifdef ROM_I2CMasterInitExpClk
#define MAP_I2CMasterInitExpClk \
        ROM_I2CMasterInitExpClk
#else
#define MAP_I2CMasterInitExpClk \
        I2CMasterInitExpClk
#endif

//*****************************************************************************
//
// Macros for the SPI API.
//
//*****************************************************************************
#ifdef ROM_SPIEnable
#define MAP_SPIEnable \
        ROM_SPIEnable
#else
#define MAP_SPIEnable \
        SPIEnable
#endif
#ifdef ROM_SPIDisable
#define MAP_SPIDisable \
        ROM_SPIDisable
#else
#define MAP_SPIDisable \
        SPIDisable
#endif
#ifdef ROM_SPIReset
#define MAP_SPIReset \
        ROM_SPIReset
#else
#define MAP_SPIReset \
        SPIReset
#endif
#ifdef ROM_SPIConfigSetExpClk
#define MAP_SPIConfigSetExpClk \
        ROM_SPIConfigSetExpClk
#else
#define MAP_SPIConfigSetExpClk \
        SPIConfigSetExpClk
#endif
#ifdef ROM_SPIDataGetNonBlocking
#define MAP_SPIDataGetNonBlocking \
        ROM_SPIDataGetNonBlocking
#else
#define MAP_SPIDataGetNonBlocking \
        SPIDataGetNonBlocking
#endif
#ifdef ROM_SPIDataGet
#define MAP_SPIDataGet \
        ROM_SPIDataGet
#else
#define MAP_SPIDataGet \
        SPIDataGet
#endif
#ifdef ROM_SPIDataPutNonBlocking
#define MAP_SPIDataPutNonBlocking \
        ROM_SPIDataPutNonBlocking
#else
#define MAP_SPIDataPutNonBlocking \
        SPIDataPutNonBlocking
#endif
#ifdef ROM_SPIDataPut
#define MAP_SPIDataPut \
        ROM_SPIDataPut
#else
#define MAP_SPIDataPut \
        SPIDataPut
#endif
#ifdef ROM_SPIFIFOEnable
#define MAP_SPIFIFOEnable \
        ROM_SPIFIFOEnable
#else
#define MAP_SPIFIFOEnable \
        SPIFIFOEnable
#endif
#ifdef ROM_SPIFIFODisable
#define MAP_SPIFIFODisable \
        ROM_SPIFIFODisable
#else
#define MAP_SPIFIFODisable \
        SPIFIFODisable
#endif
#ifdef ROM_SPIFIFOLevelSet
#define MAP_SPIFIFOLevelSet \
        ROM_SPIFIFOLevelSet
#else
#define MAP_SPIFIFOLevelSet \
        SPIFIFOLevelSet
#endif
#ifdef ROM_SPIFIFOLevelGet
#define MAP_SPIFIFOLevelGet \
        ROM_SPIFIFOLevelGet
#else
#define MAP_SPIFIFOLevelGet \
        SPIFIFOLevelGet
#endif
#ifdef ROM_SPIWordCountSet
#define MAP_SPIWordCountSet \
        ROM_SPIWordCountSet
#else
#define MAP_SPIWordCountSet \
        SPIWordCountSet
#endif
#ifdef ROM_SPIIntRegister
#define MAP_SPIIntRegister \
        ROM_SPIIntRegister
#else
#define MAP_SPIIntRegister \
        SPIIntRegister
#endif
#ifdef ROM_SPIIntUnregister
#define MAP_SPIIntUnregister \
        ROM_SPIIntUnregister
#else
#define MAP_SPIIntUnregister \
        SPIIntUnregister
#endif
#ifdef ROM_SPIIntEnable
#define MAP_SPIIntEnable \
        ROM_SPIIntEnable
#else
#define MAP_SPIIntEnable \
        SPIIntEnable
#endif
#ifdef ROM_SPIIntDisable
#define MAP_SPIIntDisable \
        ROM_SPIIntDisable
#else
#define MAP_SPIIntDisable \
        SPIIntDisable
#endif
#ifdef ROM_SPIIntStatus
#define MAP_SPIIntStatus \
        ROM_SPIIntStatus
#else
#define MAP_SPIIntStatus \
        SPIIntStatus
#endif
#ifdef ROM_SPIIntClear
#define MAP_SPIIntClear \
        ROM_SPIIntClear
#else
#define MAP_SPIIntClear \
        SPIIntClear
#endif
#ifdef ROM_SPIDmaEnable
#define MAP_SPIDmaEnable \
        ROM_SPIDmaEnable
#else
#define MAP_SPIDmaEnable \
        SPIDmaEnable
#endif
#ifdef ROM_SPIDmaDisable
#define MAP_SPIDmaDisable \
        ROM_SPIDmaDisable
#else
#define MAP_SPIDmaDisable \
        SPIDmaDisable
#endif
#ifdef ROM_SPICSEnable
#define MAP_SPICSEnable \
        ROM_SPICSEnable
#else
#define MAP_SPICSEnable \
        SPICSEnable
#endif
#ifdef ROM_SPICSDisable
#define MAP_SPICSDisable \
        ROM_SPICSDisable
#else
#define MAP_SPICSDisable \
        SPICSDisable
#endif
#ifdef ROM_SPITransfer
#define MAP_SPITransfer \
        ROM_SPITransfer
#else
#define MAP_SPITransfer \
        SPITransfer
#endif

//*****************************************************************************
//
// Macros for the CAM API.
//
//*****************************************************************************
#ifdef ROM_CameraReset
#define MAP_CameraReset \
        ROM_CameraReset
#else
#define MAP_CameraReset \
        CameraReset
#endif
#ifdef ROM_CameraParamsConfig
#define MAP_CameraParamsConfig \
        ROM_CameraParamsConfig
#else
#define MAP_CameraParamsConfig \
        CameraParamsConfig
#endif
#ifdef ROM_CameraXClkConfig
#define MAP_CameraXClkConfig \
        ROM_CameraXClkConfig
#else
#define MAP_CameraXClkConfig \
        CameraXClkConfig
#endif
#ifdef ROM_CameraXClkSet
#define MAP_CameraXClkSet \
        ROM_CameraXClkSet
#else
#define MAP_CameraXClkSet \
        CameraXClkSet
#endif
#ifdef ROM_CameraDMAEnable
#define MAP_CameraDMAEnable \
        ROM_CameraDMAEnable
#else
#define MAP_CameraDMAEnable \
        CameraDMAEnable
#endif
#ifdef ROM_CameraDMADisable
#define MAP_CameraDMADisable \
        ROM_CameraDMADisable
#else
#define MAP_CameraDMADisable \
        CameraDMADisable
#endif
#ifdef ROM_CameraThresholdSet
#define MAP_CameraThresholdSet \
        ROM_CameraThresholdSet
#else
#define MAP_CameraThresholdSet \
        CameraThresholdSet
#endif
#ifdef ROM_CameraIntRegister
#define MAP_CameraIntRegister \
        ROM_CameraIntRegister
#else
#define MAP_CameraIntRegister \
        CameraIntRegister
#endif
#ifdef ROM_CameraIntUnregister
#define MAP_CameraIntUnregister \
        ROM_CameraIntUnregister
#else
#define MAP_CameraIntUnregister \
        CameraIntUnregister
#endif
#ifdef ROM_CameraIntEnable
#define MAP_CameraIntEnable \
        ROM_CameraIntEnable
#else
#define MAP_CameraIntEnable \
        CameraIntEnable
#endif
#ifdef ROM_CameraIntDisable
#define MAP_CameraIntDisable \
        ROM_CameraIntDisable
#else
#define MAP_CameraIntDisable \
        CameraIntDisable
#endif
#ifdef ROM_CameraIntStatus
#define MAP_CameraIntStatus \
        ROM_CameraIntStatus
#else
#define MAP_CameraIntStatus \
        CameraIntStatus
#endif
#ifdef ROM_CameraIntClear
#define MAP_CameraIntClear \
        ROM_CameraIntClear
#else
#define MAP_CameraIntClear \
        CameraIntClear
#endif
#ifdef ROM_CameraCaptureStop
#define MAP_CameraCaptureStop \
        ROM_CameraCaptureStop
#else
#define MAP_CameraCaptureStop \
        CameraCaptureStop
#endif
#ifdef ROM_CameraCaptureStart
#define MAP_CameraCaptureStart \
        ROM_CameraCaptureStart
#else
#define MAP_CameraCaptureStart \
        CameraCaptureStart
#endif
#ifdef ROM_CameraBufferRead
#define MAP_CameraBufferRead \
        ROM_CameraBufferRead
#else
#define MAP_CameraBufferRead \
        CameraBufferRead
#endif

//*****************************************************************************
//
// Macros for the FLASH API.
//
//*****************************************************************************
#ifdef ROM_FlashDisable
#define MAP_FlashDisable \
        ROM_FlashDisable
#else
#define MAP_FlashDisable \
        FlashDisable
#endif
#ifdef ROM_FlashErase
#define MAP_FlashErase \
        ROM_FlashErase
#else
#define MAP_FlashErase \
        FlashErase
#endif
#ifdef ROM_FlashMassErase
#define MAP_FlashMassErase \
        ROM_FlashMassErase
#else
#define MAP_FlashMassErase \
        FlashMassErase
#endif
#ifdef ROM_FlashMassEraseNonBlocking
#define MAP_FlashMassEraseNonBlocking \
        ROM_FlashMassEraseNonBlocking
#else
#define MAP_FlashMassEraseNonBlocking \
        FlashMassEraseNonBlocking
#endif
#ifdef ROM_FlashEraseNonBlocking
#define MAP_FlashEraseNonBlocking \
        ROM_FlashEraseNonBlocking
#else
#define MAP_FlashEraseNonBlocking \
        FlashEraseNonBlocking
#endif
#ifdef ROM_FlashProgram
#define MAP_FlashProgram \
        ROM_FlashProgram
#else
#define MAP_FlashProgram \
        FlashProgram
#endif
#ifdef ROM_FlashProgramNonBlocking
#define MAP_FlashProgramNonBlocking \
        ROM_FlashProgramNonBlocking
#else
#define MAP_FlashProgramNonBlocking \
        FlashProgramNonBlocking
#endif
#ifdef ROM_FlashIntRegister
#define MAP_FlashIntRegister \
        ROM_FlashIntRegister
#else
#define MAP_FlashIntRegister \
        FlashIntRegister
#endif
#ifdef ROM_FlashIntUnregister
#define MAP_FlashIntUnregister \
        ROM_FlashIntUnregister
#else
#define MAP_FlashIntUnregister \
        FlashIntUnregister
#endif
#ifdef ROM_FlashIntEnable
#define MAP_FlashIntEnable \
        ROM_FlashIntEnable
#else
#define MAP_FlashIntEnable \
        FlashIntEnable
#endif
#ifdef ROM_FlashIntDisable
#define MAP_FlashIntDisable \
        ROM_FlashIntDisable
#else
#define MAP_FlashIntDisable \
        FlashIntDisable
#endif
#ifdef ROM_FlashIntStatus
#define MAP_FlashIntStatus \
        ROM_FlashIntStatus
#else
#define MAP_FlashIntStatus \
        FlashIntStatus
#endif
#ifdef ROM_FlashIntClear
#define MAP_FlashIntClear \
        ROM_FlashIntClear
#else
#define MAP_FlashIntClear \
        FlashIntClear
#endif
#ifdef ROM_FlashProtectGet
#define MAP_FlashProtectGet \
        ROM_FlashProtectGet
#else
#define MAP_FlashProtectGet \
        FlashProtectGet
#endif

//*****************************************************************************
//
// Macros for the Pin API.
//
//*****************************************************************************
#ifdef ROM_PinModeSet
#define MAP_PinModeSet \
        ROM_PinModeSet
#else
#define MAP_PinModeSet \
        PinModeSet
#endif
#ifdef ROM_PinDirModeSet
#define MAP_PinDirModeSet \
        ROM_PinDirModeSet
#else
#define MAP_PinDirModeSet \
        PinDirModeSet
#endif
#ifdef ROM_PinDirModeGet
#define MAP_PinDirModeGet \
        ROM_PinDirModeGet
#else
#define MAP_PinDirModeGet \
        PinDirModeGet
#endif
#ifdef ROM_PinModeGet
#define MAP_PinModeGet \
        ROM_PinModeGet
#else
#define MAP_PinModeGet \
        PinModeGet
#endif
#ifdef ROM_PinConfigGet
#define MAP_PinConfigGet \
        ROM_PinConfigGet
#else
#define MAP_PinConfigGet \
        PinConfigGet
#endif
#ifdef ROM_PinConfigSet
#define MAP_PinConfigSet \
        ROM_PinConfigSet
#else
#define MAP_PinConfigSet \
        PinConfigSet
#endif
#ifdef ROM_PinTypeUART
#define MAP_PinTypeUART \
        ROM_PinTypeUART
#else
#define MAP_PinTypeUART \
        PinTypeUART
#endif
#ifdef ROM_PinTypeI2C
#define MAP_PinTypeI2C \
        ROM_PinTypeI2C
#else
#define MAP_PinTypeI2C \
        PinTypeI2C
#endif
#ifdef ROM_PinTypeSPI
#define MAP_PinTypeSPI \
        ROM_PinTypeSPI
#else
#define MAP_PinTypeSPI \
        PinTypeSPI
#endif
#ifdef ROM_PinTypeMcASP
#define MAP_PinTypeMcASP \
        ROM_PinTypeMcASP
#else
#define MAP_PinTypeMcASP \
        PinTypeMcASP
#endif
#ifdef ROM_PinTypeTimer
#define MAP_PinTypeTimer \
        ROM_PinTypeTimer
#else
#define MAP_PinTypeTimer \
        PinTypeTimer
#endif
#ifdef ROM_PinTypeCamera
#define MAP_PinTypeCamera \
        ROM_PinTypeCamera
#else
#define MAP_PinTypeCamera \
        PinTypeCamera
#endif
#ifdef ROM_PinTypeGPIO
#define MAP_PinTypeGPIO \
        ROM_PinTypeGPIO
#else
#define MAP_PinTypeGPIO \
        PinTypeGPIO
#endif
#ifdef ROM_PinTypeADC
#define MAP_PinTypeADC \
        ROM_PinTypeADC
#else
#define MAP_PinTypeADC \
        PinTypeADC
#endif
#ifdef ROM_PinTypeSDHost
#define MAP_PinTypeSDHost \
        ROM_PinTypeSDHost
#else
#define MAP_PinTypeSDHost \
        PinTypeSDHost
#endif

//*****************************************************************************
//
// Macros for the SYSTICK API.
//
//*****************************************************************************
#ifdef ROM_SysTickEnable
#define MAP_SysTickEnable \
        ROM_SysTickEnable
#else
#define MAP_SysTickEnable \
        SysTickEnable
#endif
#ifdef ROM_SysTickDisable
#define MAP_SysTickDisable \
        ROM_SysTickDisable
#else
#define MAP_SysTickDisable \
        SysTickDisable
#endif
#ifdef ROM_SysTickIntRegister
#define MAP_SysTickIntRegister \
        ROM_SysTickIntRegister
#else
#define MAP_SysTickIntRegister \
        SysTickIntRegister
#endif
#ifdef ROM_SysTickIntUnregister
#define MAP_SysTickIntUnregister \
        ROM_SysTickIntUnregister
#else
#define MAP_SysTickIntUnregister \
        SysTickIntUnregister
#endif
#ifdef ROM_SysTickIntEnable
#define MAP_SysTickIntEnable \
        ROM_SysTickIntEnable
#else
#define MAP_SysTickIntEnable \
        SysTickIntEnable
#endif
#ifdef ROM_SysTickIntDisable
#define MAP_SysTickIntDisable \
        ROM_SysTickIntDisable
#else
#define MAP_SysTickIntDisable \
        SysTickIntDisable
#endif
#ifdef ROM_SysTickPeriodSet
#define MAP_SysTickPeriodSet \
        ROM_SysTickPeriodSet
#else
#define MAP_SysTickPeriodSet \
        SysTickPeriodSet
#endif
#ifdef ROM_SysTickPeriodGet
#define MAP_SysTickPeriodGet \
        ROM_SysTickPeriodGet
#else
#define MAP_SysTickPeriodGet \
        SysTickPeriodGet
#endif
#ifdef ROM_SysTickValueGet
#define MAP_SysTickValueGet \
        ROM_SysTickValueGet
#else
#define MAP_SysTickValueGet \
        SysTickValueGet
#endif

//*****************************************************************************
//
// Macros for the UTILS API.
//
//*****************************************************************************
#ifdef ROM_UtilsDelay
#define MAP_UtilsDelay \
        ROM_UtilsDelay
#else
#define MAP_UtilsDelay \
        UtilsDelay
#endif

//*****************************************************************************
//
// Macros for the MCSPI API.
//
//*****************************************************************************
#ifdef ROM_McASPReset
#define MAP_McASPReset \
        ROM_McASPReset
#else
#define MAP_McASPReset \
        McASPReset
#endif
#ifdef ROM_McASPPinDirSet
#define MAP_McASPPinDirSet \
        ROM_McASPPinDirSet
#else
#define MAP_McASPPinDirSet \
        McASPPinDirSet
#endif
#ifdef ROM_McASPGBLEnable
#define MAP_McASPGBLEnable \
        ROM_McASPGBLEnable
#else
#define MAP_McASPGBLEnable \
        McASPGBLEnable
#endif
#ifdef ROM_McASPGBLDisable
#define MAP_McASPGBLDisable \
        ROM_McASPGBLDisable
#else
#define MAP_McASPGBLDisable \
        McASPGBLDisable
#endif
#ifdef ROM_McASPTxValidBitSet
#define MAP_McASPTxValidBitSet \
        ROM_McASPTxValidBitSet
#else
#define MAP_McASPTxValidBitSet \
        McASPTxValidBitSet
#endif
#ifdef ROM_McASPRxValidBitSet
#define MAP_McASPRxValidBitSet \
        ROM_McASPRxValidBitSet
#else
#define MAP_McASPRxValidBitSet \
        McASPRxValidBitSet
#endif
#ifdef ROM_McASPTxValidBitGet
#define MAP_McASPTxValidBitGet \
        ROM_McASPTxValidBitGet
#else
#define MAP_McASPTxValidBitGet \
        McASPTxValidBitGet
#endif
#ifdef ROM_McASPRxValidBitGet
#define MAP_McASPRxValidBitGet \
        ROM_McASPRxValidBitGet
#else
#define MAP_McASPRxValidBitGet \
        McASPRxValidBitGet
#endif
#ifdef ROM_McASPClkConfig
#define MAP_McASPClkConfig \
        ROM_McASPClkConfig
#else
#define MAP_McASPClkConfig \
        McASPClkConfig
#endif
#ifdef ROM_McASPFSyncConfig
#define MAP_McASPFSyncConfig \
        ROM_McASPFSyncConfig
#else
#define MAP_McASPFSyncConfig \
        McASPFSyncConfig
#endif
#ifdef ROM_McASPSerEnable
#define MAP_McASPSerEnable \
        ROM_McASPSerEnable
#else
#define MAP_McASPSerEnable \
        McASPSerEnable
#endif
#ifdef ROM_McASPSerDisable
#define MAP_McASPSerDisable \
        ROM_McASPSerDisable
#else
#define MAP_McASPSerDisable \
        McASPSerDisable
#endif
#ifdef ROM_McASPSendNonBlocking
#define MAP_McASPSendNonBlocking \
        ROM_McASPSendNonBlocking
#else
#define MAP_McASPSendNonBlocking \
        McASPSendNonBlocking
#endif
#ifdef ROM_McASPSend
#define MAP_McASPSend \
        ROM_McASPSend
#else
#define MAP_McASPSend \
        McASPSend
#endif
#ifdef ROM_McASPRecvNonBlocking
#define MAP_McASPRecvNonBlocking \
        ROM_McASPRecvNonBlocking
#else
#define MAP_McASPRecvNonBlocking \
        McASPRecvNonBlocking
#endif
#ifdef ROM_McASPRecv
#define MAP_McASPRecv \
        ROM_McASPRecv
#else
#define MAP_McASPRecv \
        McASPRecv
#endif
#ifdef ROM_McASPTxActiveSlotSet
#define MAP_McASPTxActiveSlotSet \
        ROM_McASPTxActiveSlotSet
#else
#define MAP_McASPTxActiveSlotSet \
        McASPTxActiveSlotSet
#endif
#ifdef ROM_McASPRxActiveSlotSet
#define MAP_McASPRxActiveSlotSet \
        ROM_McASPRxActiveSlotSet
#else
#define MAP_McASPRxActiveSlotSet \
        McASPRxActiveSlotSet
#endif
#ifdef ROM_McASPTxActiveSlotGet
#define MAP_McASPTxActiveSlotGet \
        ROM_McASPTxActiveSlotGet
#else
#define MAP_McASPTxActiveSlotGet \
        McASPTxActiveSlotGet
#endif
#ifdef ROM_McASPRxActiveSlotGet
#define MAP_McASPRxActiveSlotGet \
        ROM_McASPRxActiveSlotGet
#else
#define MAP_McASPRxActiveSlotGet \
        McASPRxActiveSlotGet
#endif
#ifdef ROM_McASPTxCurSlotGet
#define MAP_McASPTxCurSlotGet \
        ROM_McASPTxCurSlotGet
#else
#define MAP_McASPTxCurSlotGet \
        McASPTxCurSlotGet
#endif
#ifdef ROM_McASPRxCurSlotGet
#define MAP_McASPRxCurSlotGet \
        ROM_McASPRxCurSlotGet
#else
#define MAP_McASPRxCurSlotGet \
        McASPRxCurSlotGet
#endif
#ifdef ROM_McASPIntRegister
#define MAP_McASPIntRegister \
        ROM_McASPIntRegister
#else
#define MAP_McASPIntRegister \
        McASPIntRegister
#endif
#ifdef ROM_McASPIntUnregister
#define MAP_McASPIntUnregister \
        ROM_McASPIntUnregister
#else
#define MAP_McASPIntUnregister \
        McASPIntUnregister
#endif
#ifdef ROM_McASPIntEnable
#define MAP_McASPIntEnable \
        ROM_McASPIntEnable
#else
#define MAP_McASPIntEnable \
        McASPIntEnable
#endif
#ifdef ROM_McASPIntDisable
#define MAP_McASPIntDisable \
        ROM_McASPIntDisable
#else
#define MAP_McASPIntDisable \
        McASPIntDisable
#endif
#ifdef ROM_McASPIntStatus
#define MAP_McASPIntStatus \
        ROM_McASPIntStatus
#else
#define MAP_McASPIntStatus \
        McASPIntStatus
#endif
#ifdef ROM_McASPIntClear
#define MAP_McASPIntClear \
        ROM_McASPIntClear
#else
#define MAP_McASPIntClear \
        McASPIntClear
#endif
#ifdef ROM_McASPTxPortSet
#define MAP_McASPTxPortSet \
        ROM_McASPTxPortSet
#else
#define MAP_McASPTxPortSet \
        McASPTxPortSet
#endif
#ifdef ROM_McASPTxPortGet
#define MAP_McASPTxPortGet \
        ROM_McASPTxPortGet
#else
#define MAP_McASPTxPortGet \
        McASPTxPortGet
#endif
#ifdef ROM_McASPRxPortSet
#define MAP_McASPRxPortSet \
        ROM_McASPRxPortSet
#else
#define MAP_McASPRxPortSet \
        McASPRxPortSet
#endif
#ifdef ROM_McASPRxPortGet
#define MAP_McASPRxPortGet \
        ROM_McASPRxPortGet
#else
#define MAP_McASPRxPortGet \
        McASPRxPortGet
#endif
#ifdef ROM_McASPTxEnable
#define MAP_McASPTxEnable \
        ROM_McASPTxEnable
#else
#define MAP_McASPTxEnable \
        McASPTxEnable
#endif
#ifdef ROM_McASPRxEnable
#define MAP_McASPRxEnable \
        ROM_McASPRxEnable
#else
#define MAP_McASPRxEnable \
        McASPRxEnable
#endif
#ifdef ROM_McASPTxDisable
#define MAP_McASPTxDisable \
        ROM_McASPTxDisable
#else
#define MAP_McASPTxDisable \
        McASPTxDisable
#endif
#ifdef ROM_McASPRxDisable
#define MAP_McASPRxDisable \
        ROM_McASPRxDisable
#else
#define MAP_McASPRxDisable \
        McASPRxDisable
#endif
#ifdef ROM_McASPXferModeSet
#define MAP_McASPXferModeSet \
        ROM_McASPXferModeSet
#else
#define MAP_McASPXferModeSet \
        McASPXferModeSet
#endif
#ifdef ROM_McASPTxClkChkConfig
#define MAP_McASPTxClkChkConfig \
        ROM_McASPTxClkChkConfig
#else
#define MAP_McASPTxClkChkConfig \
        McASPTxClkChkConfig
#endif
#ifdef ROM_McASPTxClkChkCount
#define MAP_McASPTxClkChkCount \
        ROM_McASPTxClkChkCount
#else
#define MAP_McASPTxClkChkCount \
        McASPTxClkChkCount
#endif
#ifdef ROM_McASPRxClkChkConfig
#define MAP_McASPRxClkChkConfig \
        ROM_McASPRxClkChkConfig
#else
#define MAP_McASPRxClkChkConfig \
        McASPRxClkChkConfig
#endif
#ifdef ROM_McASPRxClkChkCount
#define MAP_McASPRxClkChkCount \
        ROM_McASPRxClkChkCount
#else
#define MAP_McASPRxClkChkCount \
        McASPRxClkChkCount
#endif
#ifdef ROM_McASPPinDirGet
#define MAP_McASPPinDirGet \
        ROM_McASPPinDirGet
#else
#define MAP_McASPPinDirGet \
        McASPPinDirGet
#endif
#ifdef ROM_McASPTxFMTConfig
#define MAP_McASPTxFMTConfig \
        ROM_McASPTxFMTConfig
#else
#define MAP_McASPTxFMTConfig \
        McASPTxFMTConfig
#endif
#ifdef ROM_McASPRxFMTConfig
#define MAP_McASPRxFMTConfig \
        ROM_McASPRxFMTConfig
#else
#define MAP_McASPRxFMTConfig \
        McASPRxFMTConfig
#endif
#ifdef ROM_McASPDMAStatus
#define MAP_McASPDMAStatus \
        ROM_McASPDMAStatus
#else
#define MAP_McASPDMAStatus \
        McASPDMAStatus
#endif
#ifdef ROM_McASPDMAClear
#define MAP_McASPDMAClear \
        ROM_McASPDMAClear
#else
#define MAP_McASPDMAClear \
        McASPDMAClear
#endif
#ifdef ROM_McASPDMAEnable
#define MAP_McASPDMAEnable \
        ROM_McASPDMAEnable
#else
#define MAP_McASPDMAEnable \
        McASPDMAEnable
#endif
#ifdef ROM_McASPDMADisable
#define MAP_McASPDMADisable \
        ROM_McASPDMADisable
#else
#define MAP_McASPDMADisable \
        McASPDMADisable
#endif
#ifdef ROM_McASPTxFIFOEnable
#define MAP_McASPTxFIFOEnable \
        ROM_McASPTxFIFOEnable
#else
#define MAP_McASPTxFIFOEnable \
        McASPTxFIFOEnable
#endif
#ifdef ROM_McASPRxFIFOEnable
#define MAP_McASPRxFIFOEnable \
        ROM_McASPRxFIFOEnable
#else
#define MAP_McASPRxFIFOEnable \
        McASPRxFIFOEnable
#endif
#ifdef ROM_McASPTxFIFODisable
#define MAP_McASPTxFIFODisable \
        ROM_McASPTxFIFODisable
#else
#define MAP_McASPTxFIFODisable \
        McASPTxFIFODisable
#endif
#ifdef ROM_McASPRxFIFODisable
#define MAP_McASPRxFIFODisable \
        ROM_McASPRxFIFODisable
#else
#define MAP_McASPRxFIFODisable \
        McASPRxFIFODisable
#endif

//*****************************************************************************
//
// Macros for the GPIO API.
//
//*****************************************************************************
#ifdef ROM_GPIODirModeSet
#define MAP_GPIODirModeSet \
        ROM_GPIODirModeSet
#else
#define MAP_GPIODirModeSet \
        GPIODirModeSet
#endif
#ifdef ROM_GPIODirModeGet
#define MAP_GPIODirModeGet \
        ROM_GPIODirModeGet
#else
#define MAP_GPIODirModeGet \
        GPIODirModeGet
#endif
#ifdef ROM_GPIOIntTypeSet
#define MAP_GPIOIntTypeSet \
        ROM_GPIOIntTypeSet
#else
#define MAP_GPIOIntTypeSet \
        GPIOIntTypeSet
#endif
#ifdef ROM_GPIOIntTypeGet
#define MAP_GPIOIntTypeGet \
        ROM_GPIOIntTypeGet
#else
#define MAP_GPIOIntTypeGet \
        GPIOIntTypeGet
#endif
#ifdef ROM_GPIOIntEnable
#define MAP_GPIOIntEnable \
        ROM_GPIOIntEnable
#else
#define MAP_GPIOIntEnable \
        GPIOIntEnable
#endif
#ifdef ROM_GPIOIntDisable
#define MAP_GPIOIntDisable \
        ROM_GPIOIntDisable
#else
#define MAP_GPIOIntDisable \
        GPIOIntDisable
#endif
#ifdef ROM_GPIOIntStatus
#define MAP_GPIOIntStatus \
        ROM_GPIOIntStatus
#else
#define MAP_GPIOIntStatus \
        GPIOIntStatus
#endif
#ifdef ROM_GPIOIntClear
#define MAP_GPIOIntClear \
        ROM_GPIOIntClear
#else
#define MAP_GPIOIntClear \
        GPIOIntClear
#endif
#ifdef ROM_GPIOIntRegister
#define MAP_GPIOIntRegister \
        ROM_GPIOIntRegister
#else
#define MAP_GPIOIntRegister \
        GPIOIntRegister
#endif
#ifdef ROM_GPIOIntUnregister
#define MAP_GPIOIntUnregister \
        ROM_GPIOIntUnregister
#else
#define MAP_GPIOIntUnregister \
        GPIOIntUnregister
#endif
#ifdef ROM_GPIOPinRead
#define MAP_GPIOPinRead \
        ROM_GPIOPinRead
#else
#define MAP_GPIOPinRead \
        GPIOPinRead
#endif
#ifdef ROM_GPIOPinWrite
#define MAP_GPIOPinWrite \
        ROM_GPIOPinWrite
#else
#define MAP_GPIOPinWrite \
        GPIOPinWrite
#endif
#ifdef ROM_GPIOPinTypeGPIOInput
#define MAP_GPIOPinTypeGPIOInput \
        ROM_GPIOPinTypeGPIOInput
#else
#define MAP_GPIOPinTypeGPIOInput \
        GPIOPinTypeGPIOInput
#endif
#ifdef ROM_GPIOPinTypeGPIOOutput
#define MAP_GPIOPinTypeGPIOOutput \
        ROM_GPIOPinTypeGPIOOutput
#else
#define MAP_GPIOPinTypeGPIOOutput \
        GPIOPinTypeGPIOOutput
#endif
#ifdef ROM_GPIODMATriggerEnable
#define MAP_GPIODMATriggerEnable \
        ROM_GPIODMATriggerEnable
#else
#define MAP_GPIODMATriggerEnable \
        GPIODMATriggerEnable
#endif
#ifdef ROM_GPIODMATriggerDisable
#define MAP_GPIODMATriggerDisable \
        ROM_GPIODMATriggerDisable
#else
#define MAP_GPIODMATriggerDisable \
        GPIODMATriggerDisable
#endif

//*****************************************************************************
//
// Macros for the AES API.
//
//*****************************************************************************
#ifdef ROM_AESAuthLengthSet
#define MAP_AESAuthLengthSet \
        ROM_AESAuthLengthSet
#else
#define MAP_AESAuthLengthSet \
        AESAuthLengthSet
#endif
#ifdef ROM_AESConfigSet
#define MAP_AESConfigSet \
        ROM_AESConfigSet
#else
#define MAP_AESConfigSet \
        AESConfigSet
#endif
#ifdef ROM_AESDataRead
#define MAP_AESDataRead \
        ROM_AESDataRead
#else
#define MAP_AESDataRead \
        AESDataRead
#endif
#ifdef ROM_AESDataReadNonBlocking
#define MAP_AESDataReadNonBlocking \
        ROM_AESDataReadNonBlocking
#else
#define MAP_AESDataReadNonBlocking \
        AESDataReadNonBlocking
#endif
#ifdef ROM_AESDataProcess
#define MAP_AESDataProcess \
        ROM_AESDataProcess
#else
#define MAP_AESDataProcess \
        AESDataProcess
#endif
#ifdef ROM_AESDataAuth
#define MAP_AESDataAuth \
        ROM_AESDataAuth
#else
#define MAP_AESDataAuth \
        AESDataAuth
#endif
#ifdef ROM_AESDataProcessAuth
#define MAP_AESDataProcessAuth \
        ROM_AESDataProcessAuth
#else
#define MAP_AESDataProcessAuth \
        AESDataProcessAuth
#endif
#ifdef ROM_AESDataWrite
#define MAP_AESDataWrite \
        ROM_AESDataWrite
#else
#define MAP_AESDataWrite \
        AESDataWrite
#endif
#ifdef ROM_AESDataWriteNonBlocking
#define MAP_AESDataWriteNonBlocking \
        ROM_AESDataWriteNonBlocking
#else
#define MAP_AESDataWriteNonBlocking \
        AESDataWriteNonBlocking
#endif
#ifdef ROM_AESDMADisable
#define MAP_AESDMADisable \
        ROM_AESDMADisable
#else
#define MAP_AESDMADisable \
        AESDMADisable
#endif
#ifdef ROM_AESDMAEnable
#define MAP_AESDMAEnable \
        ROM_AESDMAEnable
#else
#define MAP_AESDMAEnable \
        AESDMAEnable
#endif
#ifdef ROM_AESIntClear
#define MAP_AESIntClear \
        ROM_AESIntClear
#else
#define MAP_AESIntClear \
        AESIntClear
#endif
#ifdef ROM_AESIntDisable
#define MAP_AESIntDisable \
        ROM_AESIntDisable
#else
#define MAP_AESIntDisable \
        AESIntDisable
#endif
#ifdef ROM_AESIntEnable
#define MAP_AESIntEnable \
        ROM_AESIntEnable
#else
#define MAP_AESIntEnable \
        AESIntEnable
#endif
#ifdef ROM_AESIntRegister
#define MAP_AESIntRegister \
        ROM_AESIntRegister
#else
#define MAP_AESIntRegister \
        AESIntRegister
#endif
#ifdef ROM_AESIntStatus
#define MAP_AESIntStatus \
        ROM_AESIntStatus
#else
#define MAP_AESIntStatus \
        AESIntStatus
#endif
#ifdef ROM_AESIntUnregister
#define MAP_AESIntUnregister \
        ROM_AESIntUnregister
#else
#define MAP_AESIntUnregister \
        AESIntUnregister
#endif
#ifdef ROM_AESIVSet
#define MAP_AESIVSet \
        ROM_AESIVSet
#else
#define MAP_AESIVSet \
        AESIVSet
#endif
#ifdef ROM_AESKey1Set
#define MAP_AESKey1Set \
        ROM_AESKey1Set
#else
#define MAP_AESKey1Set \
        AESKey1Set
#endif
#ifdef ROM_AESKey2Set
#define MAP_AESKey2Set \
        ROM_AESKey2Set
#else
#define MAP_AESKey2Set \
        AESKey2Set
#endif
#ifdef ROM_AESKey3Set
#define MAP_AESKey3Set \
        ROM_AESKey3Set
#else
#define MAP_AESKey3Set \
        AESKey3Set
#endif
#ifdef ROM_AESLengthSet
#define MAP_AESLengthSet \
        ROM_AESLengthSet
#else
#define MAP_AESLengthSet \
        AESLengthSet
#endif
#ifdef ROM_AESTagRead
#define MAP_AESTagRead \
        ROM_AESTagRead
#else
#define MAP_AESTagRead \
        AESTagRead
#endif

//*****************************************************************************
//
// Macros for the DES API.
//
//*****************************************************************************
#ifdef ROM_DESConfigSet
#define MAP_DESConfigSet \
        ROM_DESConfigSet
#else
#define MAP_DESConfigSet \
        DESConfigSet
#endif
#ifdef ROM_DESDataRead
#define MAP_DESDataRead \
        ROM_DESDataRead
#else
#define MAP_DESDataRead \
        DESDataRead
#endif
#ifdef ROM_DESDataReadNonBlocking
#define MAP_DESDataReadNonBlocking \
        ROM_DESDataReadNonBlocking
#else
#define MAP_DESDataReadNonBlocking \
        DESDataReadNonBlocking
#endif
#ifdef ROM_DESDataProcess
#define MAP_DESDataProcess \
        ROM_DESDataProcess
#else
#define MAP_DESDataProcess \
        DESDataProcess
#endif
#ifdef ROM_DESDataWrite
#define MAP_DESDataWrite \
        ROM_DESDataWrite
#else
#define MAP_DESDataWrite \
        DESDataWrite
#endif
#ifdef ROM_DESDataWriteNonBlocking
#define MAP_DESDataWriteNonBlocking \
        ROM_DESDataWriteNonBlocking
#else
#define MAP_DESDataWriteNonBlocking \
        DESDataWriteNonBlocking
#endif
#ifdef ROM_DESDMADisable
#define MAP_DESDMADisable \
        ROM_DESDMADisable
#else
#define MAP_DESDMADisable \
        DESDMADisable
#endif
#ifdef ROM_DESDMAEnable
#define MAP_DESDMAEnable \
        ROM_DESDMAEnable
#else
#define MAP_DESDMAEnable \
        DESDMAEnable
#endif
#ifdef ROM_DESIntClear
#define MAP_DESIntClear \
        ROM_DESIntClear
#else
#define MAP_DESIntClear \
        DESIntClear
#endif
#ifdef ROM_DESIntDisable
#define MAP_DESIntDisable \
        ROM_DESIntDisable
#else
#define MAP_DESIntDisable \
        DESIntDisable
#endif
#ifdef ROM_DESIntEnable
#define MAP_DESIntEnable \
        ROM_DESIntEnable
#else
#define MAP_DESIntEnable \
        DESIntEnable
#endif
#ifdef ROM_DESIntRegister
#define MAP_DESIntRegister \
        ROM_DESIntRegister
#else
#define MAP_DESIntRegister \
        DESIntRegister
#endif
#ifdef ROM_DESIntStatus
#define MAP_DESIntStatus \
        ROM_DESIntStatus
#else
#define MAP_DESIntStatus \
        DESIntStatus
#endif
#ifdef ROM_DESIntUnregister
#define MAP_DESIntUnregister \
        ROM_DESIntUnregister
#else
#define MAP_DESIntUnregister \
        DESIntUnregister
#endif
#ifdef ROM_DESIVSet
#define MAP_DESIVSet \
        ROM_DESIVSet
#else
#define MAP_DESIVSet \
        DESIVSet
#endif
#ifdef ROM_DESKeySet
#define MAP_DESKeySet \
        ROM_DESKeySet
#else
#define MAP_DESKeySet \
        DESKeySet
#endif
#ifdef ROM_DESLengthSet
#define MAP_DESLengthSet \
        ROM_DESLengthSet
#else
#define MAP_DESLengthSet \
        DESLengthSet
#endif

//*****************************************************************************
//
// Macros for the SHAMD5 API.
//
//*****************************************************************************
#ifdef ROM_SHAMD5ConfigSet
#define MAP_SHAMD5ConfigSet \
        ROM_SHAMD5ConfigSet
#else
#define MAP_SHAMD5ConfigSet \
        SHAMD5ConfigSet
#endif
#ifdef ROM_SHAMD5DataProcess
#define MAP_SHAMD5DataProcess \
        ROM_SHAMD5DataProcess
#else
#define MAP_SHAMD5DataProcess \
        SHAMD5DataProcess
#endif
#ifdef ROM_SHAMD5DataWrite
#define MAP_SHAMD5DataWrite \
        ROM_SHAMD5DataWrite
#else
#define MAP_SHAMD5DataWrite \
        SHAMD5DataWrite
#endif
#ifdef ROM_SHAMD5DataWriteNonBlocking
#define MAP_SHAMD5DataWriteNonBlocking \
        ROM_SHAMD5DataWriteNonBlocking
#else
#define MAP_SHAMD5DataWriteNonBlocking \
        SHAMD5DataWriteNonBlocking
#endif
#ifdef ROM_SHAMD5DMADisable
#define MAP_SHAMD5DMADisable \
        ROM_SHAMD5DMADisable
#else
#define MAP_SHAMD5DMADisable \
        SHAMD5DMADisable
#endif
#ifdef ROM_SHAMD5DMAEnable
#define MAP_SHAMD5DMAEnable \
        ROM_SHAMD5DMAEnable
#else
#define MAP_SHAMD5DMAEnable \
        SHAMD5DMAEnable
#endif
#ifdef ROM_SHAMD5HashLengthSet
#define MAP_SHAMD5HashLengthSet \
        ROM_SHAMD5HashLengthSet
#else
#define MAP_SHAMD5HashLengthSet \
        SHAMD5HashLengthSet
#endif
#ifdef ROM_SHAMD5HMACKeySet
#define MAP_SHAMD5HMACKeySet \
        ROM_SHAMD5HMACKeySet
#else
#define MAP_SHAMD5HMACKeySet \
        SHAMD5HMACKeySet
#endif
#ifdef ROM_SHAMD5HMACPPKeyGenerate
#define MAP_SHAMD5HMACPPKeyGenerate \
        ROM_SHAMD5HMACPPKeyGenerate
#else
#define MAP_SHAMD5HMACPPKeyGenerate \
        SHAMD5HMACPPKeyGenerate
#endif
#ifdef ROM_SHAMD5HMACPPKeySet
#define MAP_SHAMD5HMACPPKeySet \
        ROM_SHAMD5HMACPPKeySet
#else
#define MAP_SHAMD5HMACPPKeySet \
        SHAMD5HMACPPKeySet
#endif
#ifdef ROM_SHAMD5HMACProcess
#define MAP_SHAMD5HMACProcess \
        ROM_SHAMD5HMACProcess
#else
#define MAP_SHAMD5HMACProcess \
        SHAMD5HMACProcess
#endif
#ifdef ROM_SHAMD5IntClear
#define MAP_SHAMD5IntClear \
        ROM_SHAMD5IntClear
#else
#define MAP_SHAMD5IntClear \
        SHAMD5IntClear
#endif
#ifdef ROM_SHAMD5IntDisable
#define MAP_SHAMD5IntDisable \
        ROM_SHAMD5IntDisable
#else
#define MAP_SHAMD5IntDisable \
        SHAMD5IntDisable
#endif
#ifdef ROM_SHAMD5IntEnable
#define MAP_SHAMD5IntEnable \
        ROM_SHAMD5IntEnable
#else
#define MAP_SHAMD5IntEnable \
        SHAMD5IntEnable
#endif
#ifdef ROM_SHAMD5IntRegister
#define MAP_SHAMD5IntRegister \
        ROM_SHAMD5IntRegister
#else
#define MAP_SHAMD5IntRegister \
        SHAMD5IntRegister
#endif
#ifdef ROM_SHAMD5IntStatus
#define MAP_SHAMD5IntStatus \
        ROM_SHAMD5IntStatus
#else
#define MAP_SHAMD5IntStatus \
        SHAMD5IntStatus
#endif
#ifdef ROM_SHAMD5IntUnregister
#define MAP_SHAMD5IntUnregister \
        ROM_SHAMD5IntUnregister
#else
#define MAP_SHAMD5IntUnregister \
        SHAMD5IntUnregister
#endif
#ifdef ROM_SHAMD5ResultRead
#define MAP_SHAMD5ResultRead \
        ROM_SHAMD5ResultRead
#else
#define MAP_SHAMD5ResultRead \
        SHAMD5ResultRead
#endif

//*****************************************************************************
//
// Macros for the CRC API.
//
//*****************************************************************************
#ifdef ROM_CRCConfigSet
#define MAP_CRCConfigSet \
        ROM_CRCConfigSet
#else
#define MAP_CRCConfigSet \
        CRCConfigSet
#endif
#ifdef ROM_CRCDataProcess
#define MAP_CRCDataProcess \
        ROM_CRCDataProcess
#else
#define MAP_CRCDataProcess \
        CRCDataProcess
#endif
#ifdef ROM_CRCDataWrite
#define MAP_CRCDataWrite \
        ROM_CRCDataWrite
#else
#define MAP_CRCDataWrite \
        CRCDataWrite
#endif
#ifdef ROM_CRCResultRead
#define MAP_CRCResultRead \
        ROM_CRCResultRead
#else
#define MAP_CRCResultRead \
        CRCResultRead
#endif
#ifdef ROM_CRCSeedSet
#define MAP_CRCSeedSet \
        ROM_CRCSeedSet
#else
#define MAP_CRCSeedSet \
        CRCSeedSet
#endif

//*****************************************************************************
//
// Macros for the SDHOST API.
//
//*****************************************************************************
#ifdef ROM_SDHostCmdReset
#define MAP_SDHostCmdReset \
        ROM_SDHostCmdReset
#else
#define MAP_SDHostCmdReset \
        SDHostCmdReset
#endif
#ifdef ROM_SDHostInit
#define MAP_SDHostInit \
        ROM_SDHostInit
#else
#define MAP_SDHostInit \
        SDHostInit
#endif
#ifdef ROM_SDHostCmdSend
#define MAP_SDHostCmdSend \
        ROM_SDHostCmdSend
#else
#define MAP_SDHostCmdSend \
        SDHostCmdSend
#endif
#ifdef ROM_SDHostIntRegister
#define MAP_SDHostIntRegister \
        ROM_SDHostIntRegister
#else
#define MAP_SDHostIntRegister \
        SDHostIntRegister
#endif
#ifdef ROM_SDHostIntUnregister
#define MAP_SDHostIntUnregister \
        ROM_SDHostIntUnregister
#else
#define MAP_SDHostIntUnregister \
        SDHostIntUnregister
#endif
#ifdef ROM_SDHostIntEnable
#define MAP_SDHostIntEnable \
        ROM_SDHostIntEnable
#else
#define MAP_SDHostIntEnable \
        SDHostIntEnable
#endif
#ifdef ROM_SDHostIntDisable
#define MAP_SDHostIntDisable \
        ROM_SDHostIntDisable
#else
#define MAP_SDHostIntDisable \
        SDHostIntDisable
#endif
#ifdef ROM_SDHostIntStatus
#define MAP_SDHostIntStatus \
        ROM_SDHostIntStatus
#else
#define MAP_SDHostIntStatus \
        SDHostIntStatus
#endif
#ifdef ROM_SDHostIntClear
#define MAP_SDHostIntClear \
        ROM_SDHostIntClear
#else
#define MAP_SDHostIntClear \
        SDHostIntClear
#endif
#ifdef ROM_SDHostRespStatus
#define MAP_SDHostRespStatus \
        ROM_SDHostRespStatus
#else
#define MAP_SDHostRespStatus \
        SDHostRespStatus
#endif
#ifdef ROM_SDHostRespGet
#define MAP_SDHostRespGet \
        ROM_SDHostRespGet
#else
#define MAP_SDHostRespGet \
        SDHostRespGet
#endif
#ifdef ROM_SDHostBlockSizeSet
#define MAP_SDHostBlockSizeSet \
        ROM_SDHostBlockSizeSet
#else
#define MAP_SDHostBlockSizeSet \
        SDHostBlockSizeSet
#endif
#ifdef ROM_SDHostBlockCountSet
#define MAP_SDHostBlockCountSet \
        ROM_SDHostBlockCountSet
#else
#define MAP_SDHostBlockCountSet \
        SDHostBlockCountSet
#endif
#ifdef ROM_SDHostDataNonBlockingWrite
#define MAP_SDHostDataNonBlockingWrite \
        ROM_SDHostDataNonBlockingWrite
#else
#define MAP_SDHostDataNonBlockingWrite \
        SDHostDataNonBlockingWrite
#endif
#ifdef ROM_SDHostDataNonBlockingRead
#define MAP_SDHostDataNonBlockingRead \
        ROM_SDHostDataNonBlockingRead
#else
#define MAP_SDHostDataNonBlockingRead \
        SDHostDataNonBlockingRead
#endif
#ifdef ROM_SDHostDataWrite
#define MAP_SDHostDataWrite \
        ROM_SDHostDataWrite
#else
#define MAP_SDHostDataWrite \
        SDHostDataWrite
#endif
#ifdef ROM_SDHostDataRead
#define MAP_SDHostDataRead \
        ROM_SDHostDataRead
#else
#define MAP_SDHostDataRead \
        SDHostDataRead
#endif
#ifdef ROM_SDHostSetExpClk
#define MAP_SDHostSetExpClk \
        ROM_SDHostSetExpClk
#else
#define MAP_SDHostSetExpClk \
        SDHostSetExpClk
#endif

//*****************************************************************************
//
// Macros for the PRCM API.
//
//*****************************************************************************
#ifdef ROM_PRCMSOCReset
#define MAP_PRCMSOCReset \
        ROM_PRCMSOCReset
#else
#define MAP_PRCMSOCReset \
        PRCMSOCReset
#endif
#ifdef ROM_PRCMMCUReset
#define MAP_PRCMMCUReset \
        ROM_PRCMMCUReset
#else
#define MAP_PRCMMCUReset \
        PRCMMCUReset
#endif
#ifdef ROM_PRCMSysResetCauseGet
#define MAP_PRCMSysResetCauseGet \
        ROM_PRCMSysResetCauseGet
#else
#define MAP_PRCMSysResetCauseGet \
        PRCMSysResetCauseGet
#endif
#ifdef ROM_PRCMPeripheralClkEnable
#define MAP_PRCMPeripheralClkEnable \
        ROM_PRCMPeripheralClkEnable
#else
#define MAP_PRCMPeripheralClkEnable \
        PRCMPeripheralClkEnable
#endif
#ifdef ROM_PRCMPeripheralClkDisable
#define MAP_PRCMPeripheralClkDisable \
        ROM_PRCMPeripheralClkDisable
#else
#define MAP_PRCMPeripheralClkDisable \
        PRCMPeripheralClkDisable
#endif
#ifdef ROM_PRCMPeripheralReset
#define MAP_PRCMPeripheralReset \
        ROM_PRCMPeripheralReset
#else
#define MAP_PRCMPeripheralReset \
        PRCMPeripheralReset
#endif
#ifdef ROM_PRCMPeripheralStatusGet
#define MAP_PRCMPeripheralStatusGet \
        ROM_PRCMPeripheralStatusGet
#else
#define MAP_PRCMPeripheralStatusGet \
        PRCMPeripheralStatusGet
#endif
#ifdef ROM_PRCMNWPEnable
#define MAP_PRCMNWPEnable \
        ROM_PRCMNWPEnable
#else
#define MAP_PRCMNWPEnable \
        PRCMNWPEnable
#endif
#ifdef ROM_PRCMNWPDisable
#define MAP_PRCMNWPDisable \
        ROM_PRCMNWPDisable
#else
#define MAP_PRCMNWPDisable \
        PRCMNWPDisable
#endif
#ifdef ROM_PRCMMcASPClockInputSet
#define MAP_PRCMMcASPClockInputSet \
        ROM_PRCMMcASPClockInputSet
#else
#define MAP_PRCMMcASPClockInputSet \
        PRCMMcASPClockInputSet
#endif
#ifdef ROM_PRCMPeripheralClockGet
#define MAP_PRCMPeripheralClockGet \
        ROM_PRCMPeripheralClockGet
#else
#define MAP_PRCMPeripheralClockGet \
        PRCMPeripheralClockGet
#endif
#ifdef ROM_PRCMSleepEnter
#define MAP_PRCMSleepEnter \
        ROM_PRCMSleepEnter
#else
#define MAP_PRCMSleepEnter \
        PRCMSleepEnter
#endif
#ifdef ROM_PRCMDeepSleepEnter
#define MAP_PRCMDeepSleepEnter \
        ROM_PRCMDeepSleepEnter
#else
#define MAP_PRCMDeepSleepEnter \
        PRCMDeepSleepEnter
#endif
#ifdef ROM_PRCMSRAMRetentionEnable
#define MAP_PRCMSRAMRetentionEnable \
        ROM_PRCMSRAMRetentionEnable
#else
#define MAP_PRCMSRAMRetentionEnable \
        PRCMSRAMRetentionEnable
#endif
#ifdef ROM_PRCMSRAMRetentionDisable
#define MAP_PRCMSRAMRetentionDisable \
        ROM_PRCMSRAMRetentionDisable
#else
#define MAP_PRCMSRAMRetentionDisable \
        PRCMSRAMRetentionDisable
#endif
#ifdef ROM_PRCMLPDSEnter
#define MAP_PRCMLPDSEnter \
        ROM_PRCMLPDSEnter
#else
#define MAP_PRCMLPDSEnter \
        PRCMLPDSEnter
#endif
#ifdef ROM_PRCMLPDSIntervalSet
#define MAP_PRCMLPDSIntervalSet \
        ROM_PRCMLPDSIntervalSet
#else
#define MAP_PRCMLPDSIntervalSet \
        PRCMLPDSIntervalSet
#endif
#ifdef ROM_PRCMLPDSWakeupSourceEnable
#define MAP_PRCMLPDSWakeupSourceEnable \
        ROM_PRCMLPDSWakeupSourceEnable
#else
#define MAP_PRCMLPDSWakeupSourceEnable \
        PRCMLPDSWakeupSourceEnable
#endif
#ifdef ROM_PRCMLPDSWakeupCauseGet
#define MAP_PRCMLPDSWakeupCauseGet \
        ROM_PRCMLPDSWakeupCauseGet
#else
#define MAP_PRCMLPDSWakeupCauseGet \
        PRCMLPDSWakeupCauseGet
#endif
#ifdef ROM_PRCMLPDSWakeUpGPIOSelect
#define MAP_PRCMLPDSWakeUpGPIOSelect \
        ROM_PRCMLPDSWakeUpGPIOSelect
#else
#define MAP_PRCMLPDSWakeUpGPIOSelect \
        PRCMLPDSWakeUpGPIOSelect
#endif
#ifdef ROM_PRCMLPDSWakeupSourceDisable
#define MAP_PRCMLPDSWakeupSourceDisable \
        ROM_PRCMLPDSWakeupSourceDisable
#else
#define MAP_PRCMLPDSWakeupSourceDisable \
        PRCMLPDSWakeupSourceDisable
#endif
#ifdef ROM_PRCMHibernateEnter
#define MAP_PRCMHibernateEnter \
        ROM_PRCMHibernateEnter
#else
#define MAP_PRCMHibernateEnter \
        PRCMHibernateEnter
#endif
#ifdef ROM_PRCMHibernateWakeupSourceEnable
#define MAP_PRCMHibernateWakeupSourceEnable \
        ROM_PRCMHibernateWakeupSourceEnable
#else
#define MAP_PRCMHibernateWakeupSourceEnable \
        PRCMHibernateWakeupSourceEnable
#endif
#ifdef ROM_PRCMHibernateWakeupCauseGet
#define MAP_PRCMHibernateWakeupCauseGet \
        ROM_PRCMHibernateWakeupCauseGet
#else
#define MAP_PRCMHibernateWakeupCauseGet \
        PRCMHibernateWakeupCauseGet
#endif
#ifdef ROM_PRCMHibernateWakeUpGPIOSelect
#define MAP_PRCMHibernateWakeUpGPIOSelect \
        ROM_PRCMHibernateWakeUpGPIOSelect
#else
#define MAP_PRCMHibernateWakeUpGPIOSelect \
        PRCMHibernateWakeUpGPIOSelect
#endif
#ifdef ROM_PRCMHibernateWakeupSourceDisable
#define MAP_PRCMHibernateWakeupSourceDisable \
        ROM_PRCMHibernateWakeupSourceDisable
#else
#define MAP_PRCMHibernateWakeupSourceDisable \
        PRCMHibernateWakeupSourceDisable
#endif
#ifdef ROM_PRCMHibernateIntervalSet
#define MAP_PRCMHibernateIntervalSet \
        ROM_PRCMHibernateIntervalSet
#else
#define MAP_PRCMHibernateIntervalSet \
        PRCMHibernateIntervalSet
#endif
#ifdef ROM_PRCMRTCGet
#define MAP_PRCMRTCGet \
        ROM_PRCMRTCGet
#else
#define MAP_PRCMRTCGet \
        PRCMRTCGet
#endif
#ifdef ROM_PRCMRTCMatchSet
#define MAP_PRCMRTCMatchSet \
        ROM_PRCMRTCMatchSet
#else
#define MAP_PRCMRTCMatchSet \
        PRCMRTCMatchSet
#endif
#ifdef ROM_PRCMOCRRegisterWrite
#define MAP_PRCMOCRRegisterWrite \
        ROM_PRCMOCRRegisterWrite
#else
#define MAP_PRCMOCRRegisterWrite \
        PRCMOCRRegisterWrite
#endif
#ifdef ROM_PRCMOCRRegisterRead
#define MAP_PRCMOCRRegisterRead \
        ROM_PRCMOCRRegisterRead
#else
#define MAP_PRCMOCRRegisterRead \
        PRCMOCRRegisterRead
#endif
#ifdef ROM_PRCMIntRegister
#define MAP_PRCMIntRegister \
        ROM_PRCMIntRegister
#else
#define MAP_PRCMIntRegister \
        PRCMIntRegister
#endif
#ifdef ROM_PRCMIntUnregister
#define MAP_PRCMIntUnregister \
        ROM_PRCMIntUnregister
#else
#define MAP_PRCMIntUnregister \
        PRCMIntUnregister
#endif
#ifdef ROM_PRCMIntEnable
#define MAP_PRCMIntEnable \
        ROM_PRCMIntEnable
#else
#define MAP_PRCMIntEnable \
        PRCMIntEnable
#endif
#ifdef ROM_PRCMIntDisable
#define MAP_PRCMIntDisable \
        ROM_PRCMIntDisable
#else
#define MAP_PRCMIntDisable \
        PRCMIntDisable
#endif
#ifdef ROM_PRCMIntStatus
#define MAP_PRCMIntStatus \
        ROM_PRCMIntStatus
#else
#define MAP_PRCMIntStatus \
        PRCMIntStatus
#endif

//*****************************************************************************
//
// Macros for the PRCM API.
//
//*****************************************************************************
#ifdef ROM_HwSpinLockAcquire
#define MAP_HwSpinLockAcquire \
        ROM_HwSpinLockAcquire
#else
#define MAP_HwSpinLockAcquire \
        HwSpinLockAcquire
#endif
#ifdef ROM_HwSpinLockTryAcquire
#define MAP_HwSpinLockTryAcquire \
        ROM_HwSpinLockTryAcquire
#else
#define MAP_HwSpinLockTryAcquire \
        HwSpinLockTryAcquire
#endif
#ifdef ROM_HwSpinLockRelease
#define MAP_HwSpinLockRelease \
        ROM_HwSpinLockRelease
#else
#define MAP_HwSpinLockRelease \
        HwSpinLockRelease
#endif
#ifdef ROM_HwSpinLockTest
#define MAP_HwSpinLockTest \
        ROM_HwSpinLockTest
#else
#define MAP_HwSpinLockTest \
        HwSpinLockTest
#endif

#endif // __ROM_MAP_H__
