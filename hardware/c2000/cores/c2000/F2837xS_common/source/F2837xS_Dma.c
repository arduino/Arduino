//###########################################################################
//
// FILE:    F2837xS_DMA.c
//
// TITLE:   F2837xS Device DMA Initialization & Support Functions.
//
//###########################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//###########################################################################

#include "F2837xS_device.h"     // Headerfile Include File
#include "F2837xS_Examples.h"   // Examples Include File

// This function initializes the DMA to a known state.
//
void DMAInitialize(void)
{
    EALLOW;

    // Perform a hard reset on DMA
    DmaRegs.DMACTRL.bit.HARDRESET = 1;
   __asm (" nop"); // one NOP required after HARDRESET

    // Allow DMA to run free on emulation suspend
    DmaRegs.DEBUGCTRL.bit.FREE = 1;

    EDIS;
}


void DMACH1AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
    EALLOW;
    // Set up SOURCE address:
    DmaRegs.CH1.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH1.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH1.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH1.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}

void DMACH1BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
    EALLOW;

    // Set up BURST registers:
    DmaRegs.CH1.BURST_SIZE.all = bsize;                 // Number of words(X-1) x-ferred in a burst
    DmaRegs.CH1.SRC_BURST_STEP = srcbstep;              // Increment source addr between each word x-ferred
    DmaRegs.CH1.DST_BURST_STEP = desbstep;              // Increment dest addr between each word x-ferred


    EDIS;
}

void DMACH1TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
    EALLOW;

    // Set up TRANSFER registers:
    DmaRegs.CH1.TRANSFER_SIZE = tsize;                  // Number of bursts per transfer, DMA interrupt will occur after completed transfer
    DmaRegs.CH1.SRC_TRANSFER_STEP = srctstep;           // TRANSFER_STEP is ignored when WRAP occurs
    DmaRegs.CH1.DST_TRANSFER_STEP = deststep;           // TRANSFER_STEP is ignored when WRAP occurs

    EDIS;
}

void DMACH1WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
    EALLOW;

        // Set up WRAP registers:
    DmaRegs.CH1.SRC_WRAP_SIZE = srcwsize;               // Wrap source address after N bursts
    DmaRegs.CH1.SRC_WRAP_STEP = srcwstep;               // Step for source wrap

    DmaRegs.CH1.DST_WRAP_SIZE = deswsize;               // Wrap destination address after N bursts
    DmaRegs.CH1.DST_WRAP_STEP = deswstep;               // Step for destination wrap

    EDIS;
}


void DMACH1ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
    EALLOW;

    // Set up MODE Register:
    DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH1 = persel; // Source select
    DmaRegs.CH1.MODE.bit.PERINTSEL = 1;             // Should be hard coded to channel, above now selects source
    DmaRegs.CH1.MODE.bit.PERINTE = perinte;         // Peripheral interrupt enable
    DmaRegs.CH1.MODE.bit.ONESHOT = oneshot;         // Oneshot enable
    DmaRegs.CH1.MODE.bit.CONTINUOUS = cont;         // Continuous enable
    DmaRegs.CH1.MODE.bit.OVRINTE = ovrinte;         // Enable/disable the overflow interrupt
    DmaRegs.CH1.MODE.bit.DATASIZE = datasize;       // 16-bit/32-bit data size transfers
    DmaRegs.CH1.MODE.bit.CHINTMODE = chintmode;     // Generate interrupt to CPU at beginning/end of transfer
    DmaRegs.CH1.MODE.bit.CHINTE = chinte;           // Channel Interrupt to CPU enable

    // Clear any spurious flags:
    DmaRegs.CH1.CONTROL.bit.PERINTCLR = 1;          // Clear any spurious interrupt flags
    DmaRegs.CH1.CONTROL.bit.ERRCLR = 1;             // Clear any spurious sync error flags

    // Initialize PIE vector for CPU interrupt:
    PieCtrlRegs.PIEIER7.bit.INTx1 = 1;              // Enable DMA CH1 interrupt in PIE

    EDIS;
}

// This function starts DMA Channel 1.
void StartDMACH1(void)
{
    EALLOW;
    DmaRegs.CH1.CONTROL.bit.RUN = 1;
    EDIS;
}

void DMACH2AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
    EALLOW;

    // Set up SOURCE address:
    DmaRegs.CH2.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH2.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH2.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH2.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}

void DMACH2BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
    EALLOW;

    // Set up BURST registers:
    DmaRegs.CH2.BURST_SIZE.all = bsize;                 // Number of words(X-1) x-ferred in a burst
    DmaRegs.CH2.SRC_BURST_STEP = srcbstep;              // Increment source addr between each word x-ferred
    DmaRegs.CH2.DST_BURST_STEP = desbstep;              // Increment dest addr between each word x-ferred


    EDIS;
}

void DMACH2TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
    EALLOW;

        // Set up TRANSFER registers:
    DmaRegs.CH2.TRANSFER_SIZE = tsize;                  // Number of bursts per transfer, DMA interrupt will occur after completed transfer
    DmaRegs.CH2.SRC_TRANSFER_STEP = srctstep;           // TRANSFER_STEP is ignored when WRAP occurs
    DmaRegs.CH2.DST_TRANSFER_STEP = deststep;           // TRANSFER_STEP is ignored when WRAP occurs

    EDIS;
}

void DMACH2WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
    EALLOW;

        // Set up WRAP registers:
    DmaRegs.CH2.SRC_WRAP_SIZE = srcwsize;               // Wrap source address after N bursts
    DmaRegs.CH2.SRC_WRAP_STEP = srcwstep;               // Step for source wrap

    DmaRegs.CH2.DST_WRAP_SIZE = deswsize;               // Wrap destination address after N bursts
    DmaRegs.CH2.DST_WRAP_STEP = deswstep;               // Step for destination wrap

    EDIS;
}


void DMACH2ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
    EALLOW;

        // Set up MODE Register:
    DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH2 = persel; // Source select
    DmaRegs.CH2.MODE.bit.PERINTSEL = 2;             // Should be hard coded to channel, above now selects source
    DmaRegs.CH2.MODE.bit.PERINTE = perinte;         // Peripheral interrupt enable
    DmaRegs.CH2.MODE.bit.ONESHOT = oneshot;         // Oneshot enable
    DmaRegs.CH2.MODE.bit.CONTINUOUS = cont;         // Continuous enable
    DmaRegs.CH2.MODE.bit.OVRINTE = ovrinte;         // Enable/disable the overflow interrupt
    DmaRegs.CH2.MODE.bit.DATASIZE = datasize;       // 16-bit/32-bit data size transfers
    DmaRegs.CH2.MODE.bit.CHINTMODE = chintmode;     // Generate interrupt to CPU at beginning/end of transfer
    DmaRegs.CH2.MODE.bit.CHINTE = chinte;           // Channel Interrupt to CPU enable

    // Clear any spurious flags:
    DmaRegs.CH2.CONTROL.bit.PERINTCLR = 1;          // Clear any spurious interrupt flags
    DmaRegs.CH2.CONTROL.bit.ERRCLR = 1;             // Clear any spurious sync error flags

    // Initialize PIE vector for CPU interrupt:
    PieCtrlRegs.PIEIER7.bit.INTx2 = 1;              // Enable DMA CH2 interrupt in PIE

    EDIS;
}



// This function starts DMA Channel 2.
void StartDMACH2(void)
{
    EALLOW;
    DmaRegs.CH2.CONTROL.bit.RUN = 1;
    EDIS;
}



void DMACH3AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
    EALLOW;

    // Set up SOURCE address:
    DmaRegs.CH3.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH3.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH3.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH3.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}

void DMACH3BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
    EALLOW;

    // Set up BURST registers:
    DmaRegs.CH3.BURST_SIZE.all = bsize;                 // Number of words(X-1) x-ferred in a burst
    DmaRegs.CH3.SRC_BURST_STEP = srcbstep;              // Increment source addr between each word x-ferred
    DmaRegs.CH3.DST_BURST_STEP = desbstep;              // Increment dest addr between each word x-ferred


    EDIS;
}

void DMACH3TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
    EALLOW;

        // Set up TRANSFER registers:
    DmaRegs.CH3.TRANSFER_SIZE = tsize;                  // Number of bursts per transfer, DMA interrupt will occur after completed transfer
    DmaRegs.CH3.SRC_TRANSFER_STEP = srctstep;           // TRANSFER_STEP is ignored when WRAP occurs
    DmaRegs.CH3.DST_TRANSFER_STEP = deststep;           // TRANSFER_STEP is ignored when WRAP occurs

    EDIS;
}

void DMACH3WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
    EALLOW;

            // Set up WRAP registers:
    DmaRegs.CH3.SRC_WRAP_SIZE = srcwsize;               // Wrap source address after N bursts
    DmaRegs.CH3.SRC_WRAP_STEP = srcwstep;               // Step for source wrap

    DmaRegs.CH3.DST_WRAP_SIZE = deswsize;               // Wrap destination address after N bursts
    DmaRegs.CH3.DST_WRAP_STEP = deswstep;               // Step for destination wrap

    EDIS;
}


void DMACH3ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
    EALLOW;

    // Set up MODE Register:
    DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH3 = persel; // Source select
    DmaRegs.CH3.MODE.bit.PERINTSEL = 3;             // Should be hard coded to channel, above now selects source
    DmaRegs.CH3.MODE.bit.PERINTE = perinte;         // Peripheral interrupt enable
    DmaRegs.CH3.MODE.bit.ONESHOT = oneshot;         // Oneshot enable
    DmaRegs.CH3.MODE.bit.CONTINUOUS = cont;         // Continuous enable
    DmaRegs.CH3.MODE.bit.OVRINTE = ovrinte;         // Enable/disable the overflow interrupt
    DmaRegs.CH3.MODE.bit.DATASIZE = datasize;       // 16-bit/32-bit data size transfers
    DmaRegs.CH3.MODE.bit.CHINTMODE = chintmode;     // Generate interrupt to CPU at beginning/end of transfer
    DmaRegs.CH3.MODE.bit.CHINTE = chinte;           // Channel Interrupt to CPU enable

    // Clear any spurious flags:
    DmaRegs.CH3.CONTROL.bit.PERINTCLR = 1;          // Clear any spurious interrupt flags
    DmaRegs.CH3.CONTROL.bit.ERRCLR = 1;             // Clear any spurious sync error flags

    // Initialize PIE vector for CPU interrupt:
    PieCtrlRegs.PIEIER7.bit.INTx3 = 1;              // Enable DMA CH3 interrupt in PIE

    EDIS;
}

// This function starts DMA Channel 3.
void StartDMACH3(void)
{
    EALLOW;
    DmaRegs.CH3.CONTROL.bit.RUN = 1;
    EDIS;
}


void DMACH4AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
    EALLOW;

    // Set up SOURCE address:
    DmaRegs.CH4.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH4.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH4.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH4.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}

void DMACH4BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
    EALLOW;

    // Set up BURST registers:
    DmaRegs.CH4.BURST_SIZE.all = bsize;                 // Number of words(X-1) x-ferred in a burst
    DmaRegs.CH4.SRC_BURST_STEP = srcbstep;              // Increment source addr between each word x-ferred
    DmaRegs.CH4.DST_BURST_STEP = desbstep;              // Increment dest addr between each word x-ferred


    EDIS;
}

void DMACH4TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
    EALLOW;

    // Set up TRANSFER registers:
    DmaRegs.CH4.TRANSFER_SIZE = tsize;                  // Number of bursts per transfer, DMA interrupt will occur after completed transfer
    DmaRegs.CH4.SRC_TRANSFER_STEP = srctstep;           // TRANSFER_STEP is ignored when WRAP occurs
    DmaRegs.CH4.DST_TRANSFER_STEP = deststep;           // TRANSFER_STEP is ignored when WRAP occurs

    EDIS;
}

void DMACH4WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
    EALLOW;

        // Set up WRAP registers:
    DmaRegs.CH4.SRC_WRAP_SIZE = srcwsize;               // Wrap source address after N bursts
    DmaRegs.CH4.SRC_WRAP_STEP = srcwstep;               // Step for source wrap

    DmaRegs.CH4.DST_WRAP_SIZE = deswsize;               // Wrap destination address after N bursts
    DmaRegs.CH4.DST_WRAP_STEP = deswstep;               // Step for destination wrap

    EDIS;
}


void DMACH4ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
    EALLOW;

        // Set up MODE Register:
    DmaClaSrcSelRegs.DMACHSRCSEL1.bit.CH4 = persel; // Source select
    DmaRegs.CH4.MODE.bit.PERINTSEL = 4;             // Should be hard coded to channel, above now selects source
    DmaRegs.CH4.MODE.bit.PERINTE = perinte;         // Peripheral interrupt enable
    DmaRegs.CH4.MODE.bit.ONESHOT = oneshot;         // Oneshot enable
    DmaRegs.CH4.MODE.bit.CONTINUOUS = cont;         // Continuous enable
    DmaRegs.CH4.MODE.bit.OVRINTE = ovrinte;         // Enable/disable the overflow interrupt
    DmaRegs.CH4.MODE.bit.DATASIZE = datasize;       // 16-bit/32-bit data size transfers
    DmaRegs.CH4.MODE.bit.CHINTMODE = chintmode;     // Generate interrupt to CPU at beginning/end of transfer
    DmaRegs.CH4.MODE.bit.CHINTE = chinte;           // Channel Interrupt to CPU enable

    // Clear any spurious flags:
    DmaRegs.CH4.CONTROL.bit.PERINTCLR = 1;          // Clear any spurious interrupt flags
    DmaRegs.CH4.CONTROL.bit.ERRCLR = 1;             // Clear any spurious sync error flags

    // Initialize PIE vector for CPU interrupt:
    PieCtrlRegs.PIEIER7.bit.INTx4 = 1;              // Enable DMA CH4 interrupt in PIE

    EDIS;
}


// This function starts DMA Channel 4.
void StartDMACH4(void)
{
    EALLOW;
    DmaRegs.CH4.CONTROL.bit.RUN = 1;
    EDIS;
}


void DMACH5AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
    EALLOW;

    // Set up SOURCE address:
    DmaRegs.CH5.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH5.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH5.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH5.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}

void DMACH5BurstConfig(Uint16 bsize, int16 srcbstep, int16 desbstep)
{
    EALLOW;


    // Set up BURST registers:
    DmaRegs.CH5.BURST_SIZE.all = bsize;                 // Number of words(X-1) x-ferred in a burst
    DmaRegs.CH5.SRC_BURST_STEP = srcbstep;              // Increment source addr between each word x-ferred
    DmaRegs.CH5.DST_BURST_STEP = desbstep;              // Increment dest addr between each word x-ferred

    EDIS;
}

void DMACH5TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
    EALLOW;


        // Set up TRANSFER registers:
    DmaRegs.CH5.TRANSFER_SIZE = tsize;                  // Number of bursts per transfer, DMA interrupt will occur after completed transfer
    DmaRegs.CH5.SRC_TRANSFER_STEP = srctstep;           // TRANSFER_STEP is ignored when WRAP occurs
    DmaRegs.CH5.DST_TRANSFER_STEP = deststep;           // TRANSFER_STEP is ignored when WRAP occurs

    EDIS;
}

void DMACH5WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
    EALLOW;


        // Set up WRAP registers:
    DmaRegs.CH5.SRC_WRAP_SIZE = srcwsize;               // Wrap source address after N bursts
    DmaRegs.CH5.SRC_WRAP_STEP = srcwstep;               // Step for source wrap

    DmaRegs.CH5.DST_WRAP_SIZE = deswsize;               // Wrap destination address after N bursts
    DmaRegs.CH5.DST_WRAP_STEP = deswstep;               // Step for destination wrap

    EDIS;
}


void DMACH5ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
    EALLOW;

        // Set up MODE Register:
    DmaClaSrcSelRegs.DMACHSRCSEL2.bit.CH5 = persel; // Source select
    DmaRegs.CH5.MODE.bit.PERINTSEL = 5;             // Should be hard coded to channel, above now selects source
    DmaRegs.CH5.MODE.bit.PERINTE = perinte;         // Peripheral interrupt enable
    DmaRegs.CH5.MODE.bit.ONESHOT = oneshot;         // Oneshot enable
    DmaRegs.CH5.MODE.bit.CONTINUOUS = cont;         // Continuous enable
    DmaRegs.CH5.MODE.bit.OVRINTE = ovrinte;         // Enable/disable the overflow interrupt
    DmaRegs.CH5.MODE.bit.DATASIZE = datasize;       // 16-bit/32-bit data size transfers
    DmaRegs.CH5.MODE.bit.CHINTMODE = chintmode;     // Generate interrupt to CPU at beginning/end of transfer
    DmaRegs.CH5.MODE.bit.CHINTE = chinte;           // Channel Interrupt to CPU enable

    // Clear any spurious flags:
    DmaRegs.CH5.CONTROL.bit.PERINTCLR = 1;          // Clear any spurious interrupt flags
    DmaRegs.CH5.CONTROL.bit.ERRCLR = 1;             // Clear any spurious sync error flags

    // Initialize PIE vector for CPU interrupt:
    PieCtrlRegs.PIEIER7.bit.INTx5 = 1;              // Enable DMA CH5 interrupt in PIE

    EDIS;
}

// This function starts DMA Channel 5.
void StartDMACH5(void)
{
    EALLOW;
    DmaRegs.CH5.CONTROL.bit.RUN = 1;
    EDIS;
}



void DMACH6AddrConfig(volatile Uint16 *DMA_Dest,volatile Uint16 *DMA_Source)
{
    EALLOW;

    // Set up SOURCE address:
    DmaRegs.CH6.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH6.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH6.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH6.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}

void DMACH6BurstConfig(Uint16 bsize,Uint16 srcbstep, int16 desbstep)
{
    EALLOW;

    // Set up BURST registers:
    DmaRegs.CH6.BURST_SIZE.all = bsize;                 // Number of words(X-1) x-ferred in a burst
    DmaRegs.CH6.SRC_BURST_STEP = srcbstep;                  // Increment source addr between each word x-ferred
    DmaRegs.CH6.DST_BURST_STEP = desbstep;                // Increment dest addr between each word x-ferred


    EDIS;
}

void DMACH6TransferConfig(Uint16 tsize, int16 srctstep, int16 deststep)
{
    EALLOW;

    // Set up TRANSFER registers:
    DmaRegs.CH6.TRANSFER_SIZE = tsize;                  // Number of bursts per transfer, DMA interrupt will occur after completed transfer
    DmaRegs.CH6.SRC_TRANSFER_STEP = srctstep;           // TRANSFER_STEP is ignored when WRAP occurs
    DmaRegs.CH6.DST_TRANSFER_STEP = deststep;           // TRANSFER_STEP is ignored when WRAP occurs

    EDIS;
}

void DMACH6WrapConfig(Uint16 srcwsize, int16 srcwstep, Uint16 deswsize, int16 deswstep)
{
    EALLOW;

        // Set up WRAP registers:
    DmaRegs.CH6.SRC_WRAP_SIZE = srcwsize;               // Wrap source address after N bursts
    DmaRegs.CH6.SRC_WRAP_STEP = srcwstep;               // Step for source wrap

    DmaRegs.CH6.DST_WRAP_SIZE = deswsize;               // Wrap destination address after N bursts
    DmaRegs.CH6.DST_WRAP_STEP = deswstep;               // Step for destination wrap

    EDIS;
}


void DMACH6ModeConfig(Uint16 persel, Uint16 perinte, Uint16 oneshot, Uint16 cont, Uint16 synce, Uint16 syncsel, Uint16 ovrinte, Uint16 datasize, Uint16 chintmode, Uint16 chinte)
{
    EALLOW;

        // Set up MODE Register:
    DmaClaSrcSelRegs.DMACHSRCSEL2.bit.CH6 = persel; // Source select
    DmaRegs.CH6.MODE.bit.PERINTSEL = 6;             // Should be hard coded to channel, above now selects source
    DmaRegs.CH6.MODE.bit.PERINTE = perinte;         // Peripheral interrupt enable
    DmaRegs.CH6.MODE.bit.ONESHOT = oneshot;         // Oneshot enable
    DmaRegs.CH6.MODE.bit.CONTINUOUS = cont;         // Continuous enable
    DmaRegs.CH6.MODE.bit.OVRINTE = ovrinte;         // Enable/disable the overflow interrupt
    DmaRegs.CH6.MODE.bit.DATASIZE = datasize;       // 16-bit/32-bit data size transfers
    DmaRegs.CH6.MODE.bit.CHINTMODE = chintmode;     // Generate interrupt to CPU at beginning/end of transfer
    DmaRegs.CH6.MODE.bit.CHINTE = chinte;           // Channel Interrupt to CPU enable

    // Clear any spurious flags:
    DmaRegs.CH6.CONTROL.bit.PERINTCLR = 1;          // Clear any spurious interrupt flags
    DmaRegs.CH6.CONTROL.bit.ERRCLR = 1;             // Clear any spurious sync error flags

    // Initialize PIE vector for CPU interrupt:
    PieCtrlRegs.PIEIER7.bit.INTx6 = 1;              // Enable DMA CH6 interrupt in PIE

    EDIS;
}

// This function starts DMA Channel 6.
void StartDMACH6(void)
{
    EALLOW;
    DmaRegs.CH6.CONTROL.bit.RUN = 1;
    EDIS;
}

//Following functions are required for EMIF as the address is out of 22bit range
void DMACH1AddrConfig32bit(volatile Uint32 *DMA_Dest,volatile Uint32 *DMA_Source)
{
    EALLOW;
    // Set up SOURCE address:
    DmaRegs.CH1.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH1.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH1.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH1.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}

void DMACH2AddrConfig32bit(volatile Uint32 *DMA_Dest,volatile Uint32 *DMA_Source)
{
    EALLOW;
    // Set up SOURCE address:
    DmaRegs.CH2.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH2.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH2.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH2.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}
void DMACH3AddrConfig32bit(volatile Uint32 *DMA_Dest,volatile Uint32 *DMA_Source)
{
    EALLOW;
    // Set up SOURCE address:
    DmaRegs.CH3.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH3.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH3.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH3.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}
void DMACH4AddrConfig32bit(volatile Uint32 *DMA_Dest,volatile Uint32 *DMA_Source)
{
    EALLOW;
    // Set up SOURCE address:
    DmaRegs.CH4.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH4.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH4.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH4.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}
void DMACH5AddrConfig32bit(volatile Uint32 *DMA_Dest,volatile Uint32 *DMA_Source)
{
    EALLOW;
    // Set up SOURCE address:
    DmaRegs.CH5.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH5.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH5.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH5.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}
void DMACH6AddrConfig32bit(volatile Uint32 *DMA_Dest,volatile Uint32 *DMA_Source)
{
    EALLOW;
    // Set up SOURCE address:
    DmaRegs.CH6.SRC_BEG_ADDR_SHADOW = (Uint32)DMA_Source;   // Point to beginning of source buffer
    DmaRegs.CH6.SRC_ADDR_SHADOW =     (Uint32)DMA_Source;

    // Set up DESTINATION address:
    DmaRegs.CH6.DST_BEG_ADDR_SHADOW = (Uint32)DMA_Dest;     // Point to beginning of destination buffer
    DmaRegs.CH6.DST_ADDR_SHADOW =     (Uint32)DMA_Dest;


    EDIS;
}
//===========================================================================
// No more.
//===========================================================================
