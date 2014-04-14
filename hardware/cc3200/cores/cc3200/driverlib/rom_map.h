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
// Macros for the Watchdog API.
//
//*****************************************************************************
#ifdef ROM_ArcmPeripheralReset
#define MAP_ArcmPeripheralReset \
        ROM_ArcmPeripheralReset
#else
#define MAP_ArcmPeripheralReset \
        ArcmPeripheralReset
#endif
#ifdef ROM_ArcmPeripheralEnable
#define MAP_ArcmPeripheralEnable \
        ROM_ArcmPeripheralEnable
#else
#define MAP_ArcmPeripheralEnable \
        ArcmPeripheralEnable
#endif
#ifdef ROM_ArcmPeripheralDisable
#define MAP_ArcmPeripheralDisable \
        ROM_ArcmPeripheralDisable
#else
#define MAP_ArcmPeripheralDisable \
        ArcmPeripheralDisable
#endif
#ifdef ROM_ArcmPeripheralSlpEnable
#define MAP_ArcmPeripheralSlpEnable \
        ROM_ArcmPeripheralSlpEnable
#else
#define MAP_ArcmPeripheralSlpEnable \
        ArcmPeripheralSlpEnable
#endif
#ifdef ROM_ArcmPeripheralSlpDisable
#define MAP_ArcmPeripheralSlpDisable \
        ROM_ArcmPeripheralSlpDisable
#else
#define MAP_ArcmPeripheralSlpDisable \
        ArcmPeripheralSlpDisable
#endif
#ifdef ROM_ArcmPeripheralDSlpEnable
#define MAP_ArcmPeripheralDSlpEnable \
        ROM_ArcmPeripheralDSlpEnable
#else
#define MAP_ArcmPeripheralDSlpEnable \
        ArcmPeripheralDSlpEnable
#endif
#ifdef ROM_ArcmPeripheralDSlpDisable
#define MAP_ArcmPeripheralDSlpDisable \
        ROM_ArcmPeripheralDSlpDisable
#else
#define MAP_ArcmPeripheralDSlpDisable \
        ArcmPeripheralDSlpDisable
#endif
#ifdef ROM_ArcmPeripheralClkConfig
#define MAP_ArcmPeripheralClkConfig \
        ROM_ArcmPeripheralClkConfig
#else
#define MAP_ArcmPeripheralClkConfig \
        ArcmPeripheralClkConfig
#endif
#ifdef ROM_ArcmPeripheralReady
#define MAP_ArcmPeripheralReady \
        ROM_ArcmPeripheralReady
#else
#define MAP_ArcmPeripheralReady \
        ArcmPeripheralReady
#endif
#ifdef ROM_ArcmSlpWakeupSrcSet
#define MAP_ArcmSlpWakeupSrcSet \
        ROM_ArcmSlpWakeupSrcSet
#else
#define MAP_ArcmSlpWakeupSrcSet \
        ArcmSlpWakeupSrcSet
#endif
#ifdef ROM_ArcmSlpWakeupTimerConfig
#define MAP_ArcmSlpWakeupTimerConfig \
        ROM_ArcmSlpWakeupTimerConfig
#else
#define MAP_ArcmSlpWakeupTimerConfig \
        ArcmSlpWakeupTimerConfig
#endif
#ifdef ROM_ArcmDSlpWakeupSrcSet
#define MAP_ArcmDSlpWakeupSrcSet \
        ROM_ArcmDSlpWakeupSrcSet
#else
#define MAP_ArcmDSlpWakeupSrcSet \
        ArcmDSlpWakeupSrcSet
#endif
#ifdef ROM_ArcmDSlpWakeupTimerConfig
#define MAP_ArcmDSlpWakeupTimerConfig \
        ROM_ArcmDSlpWakeupTimerConfig
#else
#define MAP_ArcmDSlpWakeupTimerConfig \
        ArcmDSlpWakeupTimerConfig
#endif
#ifdef ROM_ArcmRqstNwpWakeup
#define MAP_ArcmRqstNwpWakeup \
        ROM_ArcmRqstNwpWakeup
#else
#define MAP_ArcmRqstNwpWakeup \
        ArcmRqstNwpWakeup
#endif
#ifdef ROM_ArcmWakeupStatusGet
#define MAP_ArcmWakeupStatusGet \
        ROM_ArcmWakeupStatusGet
#else
#define MAP_ArcmWakeupStatusGet \
        ArcmWakeupStatusGet
#endif
#ifdef ROM_ArcmMcAspFracDivReset
#define MAP_ArcmMcAspFracDivReset \
        ROM_ArcmMcAspFracDivReset
#else
#define MAP_ArcmMcAspFracDivReset \
        ArcmMcAspFracDivReset
#endif
#ifdef ROM_ArcmMcAspFracDivSet
#define MAP_ArcmMcAspFracDivSet \
        ROM_ArcmMcAspFracDivSet
#else
#define MAP_ArcmMcAspFracDivSet \
        ArcmMcAspFracDivSet
#endif
#ifdef ROM_ArcmMcSPIClkSrcSet
#define MAP_ArcmMcSPIClkSrcSet \
        ROM_ArcmMcSPIClkSrcSet
#else
#define MAP_ArcmMcSPIClkSrcSet \
        ArcmMcSPIClkSrcSet
#endif
#ifdef ROM_ArcmMcSPIClkSrcGet
#define MAP_ArcmMcSPIClkSrcGet \
        ROM_ArcmMcSPIClkSrcGet
#else
#define MAP_ArcmMcSPIClkSrcGet \
        ArcmMcSPIClkSrcGet
#endif
#ifdef ROM_ArcmLpdsEnter
#define MAP_ArcmLpdsEnter \
        ROM_ArcmLpdsEnter
#else
#define MAP_ArcmLpdsEnter \
        ArcmLpdsEnter
#endif
#ifdef ROM_ArcmDslpEnter
#define MAP_ArcmDslpEnter \
        ROM_ArcmDslpEnter
#else
#define MAP_ArcmDslpEnter \
        ArcmDslpEnter
#endif
#ifdef ROM_ArcmSlpEnter
#define MAP_ArcmSlpEnter \
        ROM_ArcmSlpEnter
#else
#define MAP_ArcmSlpEnter \
        ArcmSlpEnter
#endif
#ifdef ROM_ArcmPeripheralClkGet
#define MAP_ArcmPeripheralClkGet \
        ROM_ArcmPeripheralClkGet
#else
#define MAP_ArcmPeripheralClkGet \
        ArcmPeripheralClkGet
#endif
#ifdef ROM_ArcmMcAspFracDivGet
#define MAP_ArcmMcAspFracDivGet \
        ROM_ArcmMcAspFracDivGet
#else
#define MAP_ArcmMcAspFracDivGet \
        ArcmMcAspFracDivGet
#endif

//*****************************************************************************
//
// Macros for the GPRCM API.
//
//*****************************************************************************
#ifdef ROM_GprcmAppsSSRst
#define MAP_GprcmAppsSSRst \
        ROM_GprcmAppsSSRst
#else
#define MAP_GprcmAppsSSRst \
        GprcmAppsSSRst
#endif
#ifdef ROM_GprcmAppsRst
#define MAP_GprcmAppsRst \
        ROM_GprcmAppsRst
#else
#define MAP_GprcmAppsRst \
        GprcmAppsRst
#endif
#ifdef ROM_GprcmNwpRst
#define MAP_GprcmNwpRst \
        ROM_GprcmNwpRst
#else
#define MAP_GprcmNwpRst \
        GprcmNwpRst
#endif
#ifdef ROM_GprcmMcuGlobalRst
#define MAP_GprcmMcuGlobalRst \
        ROM_GprcmMcuGlobalRst
#else
#define MAP_GprcmMcuGlobalRst \
        GprcmMcuGlobalRst
#endif
#ifdef ROM_GprcmSramDslpRetEnable
#define MAP_GprcmSramDslpRetEnable \
        ROM_GprcmSramDslpRetEnable
#else
#define MAP_GprcmSramDslpRetEnable \
        GprcmSramDslpRetEnable
#endif
#ifdef ROM_GprcmSramDslpRetDisable
#define MAP_GprcmSramDslpRetDisable \
        ROM_GprcmSramDslpRetDisable
#else
#define MAP_GprcmSramDslpRetDisable \
        GprcmSramDslpRetDisable
#endif
#ifdef ROM_GprcmSramLpdsRetEnable
#define MAP_GprcmSramLpdsRetEnable \
        ROM_GprcmSramLpdsRetEnable
#else
#define MAP_GprcmSramLpdsRetEnable \
        GprcmSramLpdsRetEnable
#endif
#ifdef ROM_GprcmSramLpdsRetDisable
#define MAP_GprcmSramLpdsRetDisable \
        ROM_GprcmSramLpdsRetDisable
#else
#define MAP_GprcmSramLpdsRetDisable \
        GprcmSramLpdsRetDisable
#endif
#ifdef ROM_GprcmAppsRstCauseGet
#define MAP_GprcmAppsRstCauseGet \
        ROM_GprcmAppsRstCauseGet
#else
#define MAP_GprcmAppsRstCauseGet \
        GprcmAppsRstCauseGet
#endif
#ifdef ROM_GprcmLPDSWkupSrcGet
#define MAP_GprcmLPDSWkupSrcGet \
        ROM_GprcmLPDSWkupSrcGet
#else
#define MAP_GprcmLPDSWkupSrcGet \
        GprcmLPDSWkupSrcGet
#endif
#ifdef ROM_GprcmLPDSWkupSrcSet
#define MAP_GprcmLPDSWkupSrcSet \
        ROM_GprcmLPDSWkupSrcSet
#else
#define MAP_GprcmLPDSWkupSrcSet \
        GprcmLPDSWkupSrcSet
#endif
#ifdef ROM_GprcmLPDSWkupTimeSet
#define MAP_GprcmLPDSWkupTimeSet \
        ROM_GprcmLPDSWkupTimeSet
#else
#define MAP_GprcmLPDSWkupTimeSet \
        GprcmLPDSWkupTimeSet
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
#ifdef ROM_I2CMasterInitExpClk
#define MAP_I2CMasterInitExpClk \
        ROM_I2CMasterInitExpClk
#else
#define MAP_I2CMasterInitExpClk \
        I2CMasterInitExpClk
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
#ifdef ROM_I2CMasterInitExpClkEx
#define MAP_I2CMasterInitExpClkEx \
        ROM_I2CMasterInitExpClkEx
#else
#define MAP_I2CMasterInitExpClkEx \
        I2CMasterInitExpClkEx
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
#ifdef ROM_I2CLoopBackEnable
#define MAP_I2CLoopBackEnable \
        ROM_I2CLoopBackEnable
#else
#define MAP_I2CLoopBackEnable \
        I2CLoopBackEnable
#endif
#ifdef ROM_I2CLoopBackDisable
#define MAP_I2CLoopBackDisable \
        ROM_I2CLoopBackDisable
#else
#define MAP_I2CLoopBackDisable \
        I2CLoopBackDisable
#endif
#ifdef ROM_I2CFIFOCtrlSet
#define MAP_I2CFIFOCtrlSet \
        ROM_I2CFIFOCtrlSet
#else
#define MAP_I2CFIFOCtrlSet \
        I2CFIFOCtrlSet
#endif
#ifdef ROM_I2CFIFOWrite
#define MAP_I2CFIFOWrite \
        ROM_I2CFIFOWrite
#else
#define MAP_I2CFIFOWrite \
        I2CFIFOWrite
#endif
#ifdef ROM_I2CFIFORead
#define MAP_I2CFIFORead \
        ROM_I2CFIFORead
#else
#define MAP_I2CFIFORead \
        I2CFIFORead
#endif
#ifdef ROM_I2CMultiMasterEnable
#define MAP_I2CMultiMasterEnable \
        ROM_I2CMultiMasterEnable
#else
#define MAP_I2CMultiMasterEnable \
        I2CMultiMasterEnable
#endif
#ifdef ROM_I2CFIFOStatusGet
#define MAP_I2CFIFOStatusGet \
        ROM_I2CFIFOStatusGet
#else
#define MAP_I2CFIFOStatusGet \
        I2CFIFOStatusGet
#endif
#ifdef ROM_I2CMultiMasterDisable
#define MAP_I2CMultiMasterDisable \
        ROM_I2CMultiMasterDisable
#else
#define MAP_I2CMultiMasterDisable \
        I2CMultiMasterDisable
#endif

//*****************************************************************************
//
// Macros for the MCSPI API.
//
//*****************************************************************************
#ifdef ROM_McSPIReset
#define MAP_McSPIReset \
        ROM_McSPIReset
#else
#define MAP_McSPIReset \
        McSPIReset
#endif
#ifdef ROM_McSPIConfig
#define MAP_McSPIConfig \
        ROM_McSPIConfig
#else
#define MAP_McSPIConfig \
        McSPIConfig
#endif
#ifdef ROM_McSPIMSModeGet
#define MAP_McSPIMSModeGet \
        ROM_McSPIMSModeGet
#else
#define MAP_McSPIMSModeGet \
        McSPIMSModeGet
#endif
#ifdef ROM_McSPIWordLenGet
#define MAP_McSPIWordLenGet \
        ROM_McSPIWordLenGet
#else
#define MAP_McSPIWordLenGet \
        McSPIWordLenGet
#endif
#ifdef ROM_McSPISPITRModeSet
#define MAP_McSPISPITRModeSet \
        ROM_McSPISPITRModeSet
#else
#define MAP_McSPISPITRModeSet \
        McSPISPITRModeSet
#endif
#ifdef ROM_McSPISPITRModeGet
#define MAP_McSPISPITRModeGet \
        ROM_McSPISPITRModeGet
#else
#define MAP_McSPISPITRModeGet \
        McSPISPITRModeGet
#endif
#ifdef ROM_McSPIDataLineConfigSet
#define MAP_McSPIDataLineConfigSet \
        ROM_McSPIDataLineConfigSet
#else
#define MAP_McSPIDataLineConfigSet \
        McSPIDataLineConfigSet
#endif
#ifdef ROM_McSPIDataLineConfigGet
#define MAP_McSPIDataLineConfigGet \
        ROM_McSPIDataLineConfigGet
#else
#define MAP_McSPIDataLineConfigGet \
        McSPIDataLineConfigGet
#endif
#ifdef ROM_McSPIChannelEnable
#define MAP_McSPIChannelEnable \
        ROM_McSPIChannelEnable
#else
#define MAP_McSPIChannelEnable \
        McSPIChannelEnable
#endif
#ifdef ROM_McSPIChannelDisable
#define MAP_McSPIChannelDisable \
        ROM_McSPIChannelDisable
#else
#define MAP_McSPIChannelDisable \
        McSPIChannelDisable
#endif
#ifdef ROM_McSPIDataNonBlockingGet
#define MAP_McSPIDataNonBlockingGet \
        ROM_McSPIDataNonBlockingGet
#else
#define MAP_McSPIDataNonBlockingGet \
        McSPIDataNonBlockingGet
#endif
#ifdef ROM_McSPIDataGet
#define MAP_McSPIDataGet \
        ROM_McSPIDataGet
#else
#define MAP_McSPIDataGet \
        McSPIDataGet
#endif
#ifdef ROM_McSPIDataNonBlockingPut
#define MAP_McSPIDataNonBlockingPut \
        ROM_McSPIDataNonBlockingPut
#else
#define MAP_McSPIDataNonBlockingPut \
        McSPIDataNonBlockingPut
#endif
#ifdef ROM_McSPIDataPut
#define MAP_McSPIDataPut \
        ROM_McSPIDataPut
#else
#define MAP_McSPIDataPut \
        McSPIDataPut
#endif
#ifdef ROM_McSPICSEnable
#define MAP_McSPICSEnable \
        ROM_McSPICSEnable
#else
#define MAP_McSPICSEnable \
        McSPICSEnable
#endif
#ifdef ROM_McSPICSDisable
#define MAP_McSPICSDisable \
        ROM_McSPICSDisable
#else
#define MAP_McSPICSDisable \
        McSPICSDisable
#endif
#ifdef ROM_McSPITransfer
#define MAP_McSPITransfer \
        ROM_McSPITransfer
#else
#define MAP_McSPITransfer \
        McSPITransfer
#endif
#ifdef ROM_McSPIFIFOEnable
#define MAP_McSPIFIFOEnable \
        ROM_McSPIFIFOEnable
#else
#define MAP_McSPIFIFOEnable \
        McSPIFIFOEnable
#endif
#ifdef ROM_McSPIFIFODisable
#define MAP_McSPIFIFODisable \
        ROM_McSPIFIFODisable
#else
#define MAP_McSPIFIFODisable \
        McSPIFIFODisable
#endif
#ifdef ROM_McSPIConfigureAFL
#define MAP_McSPIConfigureAFL \
        ROM_McSPIConfigureAFL
#else
#define MAP_McSPIConfigureAFL \
        McSPIConfigureAFL
#endif
#ifdef ROM_McSPIConfigureAEL
#define MAP_McSPIConfigureAEL \
        ROM_McSPIConfigureAEL
#else
#define MAP_McSPIConfigureAEL \
        McSPIConfigureAEL
#endif
#ifdef ROM_McSPIConfigureWCNT
#define MAP_McSPIConfigureWCNT \
        ROM_McSPIConfigureWCNT
#else
#define MAP_McSPIConfigureWCNT \
        McSPIConfigureWCNT
#endif
#ifdef ROM_McSPIDmaEnable
#define MAP_McSPIDmaEnable \
        ROM_McSPIDmaEnable
#else
#define MAP_McSPIDmaEnable \
        McSPIDmaEnable
#endif
#ifdef ROM_McSPIDmaDisable
#define MAP_McSPIDmaDisable \
        ROM_McSPIDmaDisable
#else
#define MAP_McSPIDmaDisable \
        McSPIDmaDisable
#endif
#ifdef ROM_McSPIIntRegister
#define MAP_McSPIIntRegister \
        ROM_McSPIIntRegister
#else
#define MAP_McSPIIntRegister \
        McSPIIntRegister
#endif
#ifdef ROM_McSPIIntUnregister
#define MAP_McSPIIntUnregister \
        ROM_McSPIIntUnregister
#else
#define MAP_McSPIIntUnregister \
        McSPIIntUnregister
#endif
#ifdef ROM_McSPIIntEnable
#define MAP_McSPIIntEnable \
        ROM_McSPIIntEnable
#else
#define MAP_McSPIIntEnable \
        McSPIIntEnable
#endif
#ifdef ROM_McSPIIntDisable
#define MAP_McSPIIntDisable \
        ROM_McSPIIntDisable
#else
#define MAP_McSPIIntDisable \
        McSPIIntDisable
#endif
#ifdef ROM_McSPIIntStatus
#define MAP_McSPIIntStatus \
        ROM_McSPIIntStatus
#else
#define MAP_McSPIIntStatus \
        McSPIIntStatus
#endif
#ifdef ROM_McSPIIntClear
#define MAP_McSPIIntClear \
        ROM_McSPIIntClear
#else
#define MAP_McSPIIntClear \
        McSPIIntClear
#endif
#ifdef ROM_McSPIInitDelaySet
#define MAP_McSPIInitDelaySet \
        ROM_McSPIInitDelaySet
#else
#define MAP_McSPIInitDelaySet \
        McSPIInitDelaySet
#endif
#ifdef ROM_McSPIInitDelayGet
#define MAP_McSPIInitDelayGet \
        ROM_McSPIInitDelayGet
#else
#define MAP_McSPIInitDelayGet \
        McSPIInitDelayGet
#endif
#ifdef ROM_McSPIStartBitEnable
#define MAP_McSPIStartBitEnable \
        ROM_McSPIStartBitEnable
#else
#define MAP_McSPIStartBitEnable \
        McSPIStartBitEnable
#endif
#ifdef ROM_McSPIStartBitDisable
#define MAP_McSPIStartBitDisable \
        ROM_McSPIStartBitDisable
#else
#define MAP_McSPIStartBitDisable \
        McSPIStartBitDisable
#endif
#ifdef ROM_McSPITurboModeEnable
#define MAP_McSPITurboModeEnable \
        ROM_McSPITurboModeEnable
#else
#define MAP_McSPITurboModeEnable \
        McSPITurboModeEnable
#endif
#ifdef ROM_McSPITurboModeDisable
#define MAP_McSPITurboModeDisable \
        ROM_McSPITurboModeDisable
#else
#define MAP_McSPITurboModeDisable \
        McSPITurboModeDisable
#endif
#ifdef ROM_McSPI3PinModeEnable
#define MAP_McSPI3PinModeEnable \
        ROM_McSPI3PinModeEnable
#else
#define MAP_McSPI3PinModeEnable \
        McSPI3PinModeEnable
#endif
#ifdef ROM_McSPI3PinModeDisable
#define MAP_McSPI3PinModeDisable \
        ROM_McSPI3PinModeDisable
#else
#define MAP_McSPI3PinModeDisable \
        McSPI3PinModeDisable
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
#ifdef ROM_CamBufferRead
#define MAP_CamBufferRead \
        ROM_CamBufferRead
#else
#define MAP_CamBufferRead \
        CamBufferRead
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
// Macros for the EPI API.
//
//*****************************************************************************
#ifdef ROM_EPIModeSet
#define MAP_EPIModeSet \
        ROM_EPIModeSet
#else
#define MAP_EPIModeSet \
        EPIModeSet
#endif
#ifdef ROM_EPIDividerSet
#define MAP_EPIDividerSet \
        ROM_EPIDividerSet
#else
#define MAP_EPIDividerSet \
        EPIDividerSet
#endif
#ifdef ROM_EPIConfigSDRAMSet
#define MAP_EPIConfigSDRAMSet \
        ROM_EPIConfigSDRAMSet
#else
#define MAP_EPIConfigSDRAMSet \
        EPIConfigSDRAMSet
#endif
#ifdef ROM_EPIAddressMapSet
#define MAP_EPIAddressMapSet \
        ROM_EPIAddressMapSet
#else
#define MAP_EPIAddressMapSet \
        EPIAddressMapSet
#endif
#ifdef ROM_EPINonBlockingReadConfigure
#define MAP_EPINonBlockingReadConfigure \
        ROM_EPINonBlockingReadConfigure
#else
#define MAP_EPINonBlockingReadConfigure \
        EPINonBlockingReadConfigure
#endif
#ifdef ROM_EPINonBlockingReadStart
#define MAP_EPINonBlockingReadStart \
        ROM_EPINonBlockingReadStart
#else
#define MAP_EPINonBlockingReadStart \
        EPINonBlockingReadStart
#endif
#ifdef ROM_EPINonBlockingReadStop
#define MAP_EPINonBlockingReadStop \
        ROM_EPINonBlockingReadStop
#else
#define MAP_EPINonBlockingReadStop \
        EPINonBlockingReadStop
#endif
#ifdef ROM_EPINonBlockingReadCount
#define MAP_EPINonBlockingReadCount \
        ROM_EPINonBlockingReadCount
#else
#define MAP_EPINonBlockingReadCount \
        EPINonBlockingReadCount
#endif
#ifdef ROM_EPINonBlockingReadAvail
#define MAP_EPINonBlockingReadAvail \
        ROM_EPINonBlockingReadAvail
#else
#define MAP_EPINonBlockingReadAvail \
        EPINonBlockingReadAvail
#endif
#ifdef ROM_EPINonBlockingReadGet32
#define MAP_EPINonBlockingReadGet32 \
        ROM_EPINonBlockingReadGet32
#else
#define MAP_EPINonBlockingReadGet32 \
        EPINonBlockingReadGet32
#endif
#ifdef ROM_EPINonBlockingReadGet16
#define MAP_EPINonBlockingReadGet16 \
        ROM_EPINonBlockingReadGet16
#else
#define MAP_EPINonBlockingReadGet16 \
        EPINonBlockingReadGet16
#endif
#ifdef ROM_EPINonBlockingReadGet8
#define MAP_EPINonBlockingReadGet8 \
        ROM_EPINonBlockingReadGet8
#else
#define MAP_EPINonBlockingReadGet8 \
        EPINonBlockingReadGet8
#endif
#ifdef ROM_EPIFIFOConfig
#define MAP_EPIFIFOConfig \
        ROM_EPIFIFOConfig
#else
#define MAP_EPIFIFOConfig \
        EPIFIFOConfig
#endif
#ifdef ROM_EPIWriteFIFOCountGet
#define MAP_EPIWriteFIFOCountGet \
        ROM_EPIWriteFIFOCountGet
#else
#define MAP_EPIWriteFIFOCountGet \
        EPIWriteFIFOCountGet
#endif
#ifdef ROM_EPIIntEnable
#define MAP_EPIIntEnable \
        ROM_EPIIntEnable
#else
#define MAP_EPIIntEnable \
        EPIIntEnable
#endif
#ifdef ROM_EPIIntDisable
#define MAP_EPIIntDisable \
        ROM_EPIIntDisable
#else
#define MAP_EPIIntDisable \
        EPIIntDisable
#endif
#ifdef ROM_EPIIntStatus
#define MAP_EPIIntStatus \
        ROM_EPIIntStatus
#else
#define MAP_EPIIntStatus \
        EPIIntStatus
#endif
#ifdef ROM_EPIIntErrorStatus
#define MAP_EPIIntErrorStatus \
        ROM_EPIIntErrorStatus
#else
#define MAP_EPIIntErrorStatus \
        EPIIntErrorStatus
#endif
#ifdef ROM_EPIIntErrorClear
#define MAP_EPIIntErrorClear \
        ROM_EPIIntErrorClear
#else
#define MAP_EPIIntErrorClear \
        EPIIntErrorClear
#endif
#ifdef ROM_EPIIntRegister
#define MAP_EPIIntRegister \
        ROM_EPIIntRegister
#else
#define MAP_EPIIntRegister \
        EPIIntRegister
#endif
#ifdef ROM_EPIIntUnregister
#define MAP_EPIIntUnregister \
        ROM_EPIIntUnregister
#else
#define MAP_EPIIntUnregister \
        EPIIntUnregister
#endif

//*****************************************************************************
//
// Macros for the PinMAP API.
//
//*****************************************************************************
#ifdef ROM_PinModeSet
#define MAP_PinModeSet \
        ROM_PinModeSet
#else
#define MAP_PinModeSet \
        PinModeSet
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
#ifdef ROM_PinTypeSet
#define MAP_PinTypeSet \
        ROM_PinTypeSet
#else
#define MAP_PinTypeSet \
        PinTypeSet
#endif
#ifdef ROM_PinTypeGet
#define MAP_PinTypeGet \
        ROM_PinTypeGet
#else
#define MAP_PinTypeGet \
        PinTypeGet
#endif
#ifdef ROM_PinStrengthSet
#define MAP_PinStrengthSet \
        ROM_PinStrengthSet
#else
#define MAP_PinStrengthSet \
        PinStrengthSet
#endif
#ifdef ROM_PinStrengthGet
#define MAP_PinStrengthGet \
        ROM_PinStrengthGet
#else
#define MAP_PinStrengthGet \
        PinStrengthGet
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
#ifdef ROM_PinTypeMcSPI
#define MAP_PinTypeMcSPI \
        ROM_PinTypeMcSPI
#else
#define MAP_PinTypeMcSPI \
        PinTypeMcSPI
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
#ifdef ROM_PinTypeCAM
#define MAP_PinTypeCAM \
        ROM_PinTypeCAM
#else
#define MAP_PinTypeCAM \
        PinTypeCAM
#endif
#ifdef ROM_PinTypeEPI
#define MAP_PinTypeEPI \
        ROM_PinTypeEPI
#else
#define MAP_PinTypeEPI \
        PinTypeEPI
#endif
#ifdef ROM_PinTypeGPIO
#define MAP_PinTypeGPIO \
        ROM_PinTypeGPIO
#else
#define MAP_PinTypeGPIO \
        PinTypeGPIO
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
// Macros for the SEMAPHORE API.
//
//*****************************************************************************
#ifdef ROM_HwSemaphoreLock
#define MAP_HwSemaphoreLock \
        ROM_HwSemaphoreLock
#else
#define MAP_HwSemaphoreLock \
        HwSemaphoreLock
#endif
#ifdef ROM_HwSemaphoreUnlock
#define MAP_HwSemaphoreUnlock \
        ROM_HwSemaphoreUnlock
#else
#define MAP_HwSemaphoreUnlock \
        HwSemaphoreUnlock
#endif
#ifdef ROM_HwSemaphoreCurrentOwnerGet
#define MAP_HwSemaphoreCurrentOwnerGet \
        ROM_HwSemaphoreCurrentOwnerGet
#else
#define MAP_HwSemaphoreCurrentOwnerGet \
        HwSemaphoreCurrentOwnerGet
#endif
#ifdef ROM_HwSemaphorePrevOwnerGet
#define MAP_HwSemaphorePrevOwnerGet \
        ROM_HwSemaphorePrevOwnerGet
#else
#define MAP_HwSemaphorePrevOwnerGet \
        HwSemaphorePrevOwnerGet
#endif
#ifdef ROM_HwSemaphoreFlashGet
#define MAP_HwSemaphoreFlashGet \
        ROM_HwSemaphoreFlashGet
#else
#define MAP_HwSemaphoreFlashGet \
        HwSemaphoreFlashGet
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
// Macros for the HIB API.
//
//*****************************************************************************
#ifdef ROM_HIBXtalClkEnable
#define MAP_HIBXtalClkEnable \
        ROM_HIBXtalClkEnable
#else
#define MAP_HIBXtalClkEnable \
        HIBXtalClkEnable
#endif
#ifdef ROM_HIBXtalClkDfltEnable
#define MAP_HIBXtalClkDfltEnable \
        ROM_HIBXtalClkDfltEnable
#else
#define MAP_HIBXtalClkDfltEnable \
        HIBXtalClkDfltEnable
#endif
#ifdef ROM_HIBEnter
#define MAP_HIBEnter \
        ROM_HIBEnter
#else
#define MAP_HIBEnter \
        HIBEnter
#endif
#ifdef ROM_HIBRTCEnable
#define MAP_HIBRTCEnable \
        ROM_HIBRTCEnable
#else
#define MAP_HIBRTCEnable \
        HIBRTCEnable
#endif
#ifdef ROM_HIBRTCRead
#define MAP_HIBRTCRead \
        ROM_HIBRTCRead
#else
#define MAP_HIBRTCRead \
        HIBRTCRead
#endif
#ifdef ROM_HIBRTCWakeEnable
#define MAP_HIBRTCWakeEnable \
        ROM_HIBRTCWakeEnable
#else
#define MAP_HIBRTCWakeEnable \
        HIBRTCWakeEnable
#endif
#ifdef ROM_HIBRTCWakeDisable
#define MAP_HIBRTCWakeDisable \
        ROM_HIBRTCWakeDisable
#else
#define MAP_HIBRTCWakeDisable \
        HIBRTCWakeDisable
#endif
#ifdef ROM_HIBEnableIRQ
#define MAP_HIBEnableIRQ \
        ROM_HIBEnableIRQ
#else
#define MAP_HIBEnableIRQ \
        HIBEnableIRQ
#endif
#ifdef ROM_HIBDisableIRQ
#define MAP_HIBDisableIRQ \
        ROM_HIBDisableIRQ
#else
#define MAP_HIBDisableIRQ \
        HIBDisableIRQ
#endif
#ifdef ROM_HIBGPIOWakeEnable
#define MAP_HIBGPIOWakeEnable \
        ROM_HIBGPIOWakeEnable
#else
#define MAP_HIBGPIOWakeEnable \
        HIBGPIOWakeEnable
#endif
#ifdef ROM_HIBRetRegWrite
#define MAP_HIBRetRegWrite \
        ROM_HIBRetRegWrite
#else
#define MAP_HIBRetRegWrite \
        HIBRetRegWrite
#endif
#ifdef ROM_HIBRetRegRead
#define MAP_HIBRetRegRead \
        ROM_HIBRetRegRead
#else
#define MAP_HIBRetRegRead \
        HIBRetRegRead
#endif
#ifdef ROM_HIBWakeupCauseGet
#define MAP_HIBWakeupCauseGet \
        ROM_HIBWakeupCauseGet
#else
#define MAP_HIBWakeupCauseGet \
        HIBWakeupCauseGet
#endif
#ifdef ROM_HIBLPDSWkupGPIOSet
#define MAP_HIBLPDSWkupGPIOSet \
        ROM_HIBLPDSWkupGPIOSet
#else
#define MAP_HIBLPDSWkupGPIOSet \
        HIBLPDSWkupGPIOSet
#endif
#ifdef ROM_HIBRTCReset
#define MAP_HIBRTCReset \
        ROM_HIBRTCReset
#else
#define MAP_HIBRTCReset \
        HIBRTCReset
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

#endif // __ROM_MAP_H__
