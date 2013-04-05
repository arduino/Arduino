//#############################################################################
//
//! \file   f2802x_common/source/sci.c
//!
//! \brief  Contains the various functions related to the serial 
//!         communications interface (SCI) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes
#include "DSP28x_Project.h"
#include "f2802x_common/include/sci.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals


// **************************************************************************
// the functions


void SCI_clearAutoBaudDetect(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFCT |= SCI_SCIFFCT_ABDCLR_BITS;

    return;
} // end of SCI_clearAutoBaudDetect() function


void SCI_clearRxFifoOvf(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFRX |= SCI_SCIFFRX_FIFO_OVFCLR_BITS;

    return;
} // end of SCI_clearRxFifoOvf() function


void SCI_clearRxFifoInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFRX |= SCI_SCIFFRX_INTCLR_BITS;

    return;
} // end of SCI_clearRxFifoInt() function


void SCI_clearTxFifoInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFTX |= SCI_SCIFFTX_INTCLR_BITS;

    return;
} // end of SCI_clearTxFifoInt() function


void SCI_disable(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL1 &= (~SCI_SCICTL1_RESET_BITS);

    return;
} // end of SCI_disable() function


void SCI_disableAutoBaudAlign(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFCT &= (~SCI_SCIFFCT_CDC_BITS);

    return;
} // end of SCI_disableAutoBaudAlign() function


void SCI_disableLoopBack(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICCR &= (~SCI_SCICCR_LB_ENA_BITS);

    return;
} // end of SCI_disableLoopBack() function


void SCI_disableParity(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICCR &= (~SCI_SCICCR_PARITY_ENA_BITS);

    return;
} // end of SCI_disableParity() function


void SCI_disableRx(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL1 &= (~SCI_SCICTL1_RXENA_BITS);

    return;
} // end of SCI_disableRx() function


void SCI_disableRxErrorInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL1 &= (~SCI_SCICTL1_RX_ERR_INT_ENA_BITS);

    return;
} // end of SCI_disableRxErrorInt() function


void SCI_disableRxFifoInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFRX &= (~SCI_SCIFFRX_IENA_BITS);

    return;
} // end of SCI_disableRxFifoInt() function


void SCI_disableRxInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL2 &= (~SCI_SCICTL2_RX_INT_ENA_BITS);

    return;
} // end of SCI_disableRxInt() function


void SCI_disableSleep(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL1 &= (~SCI_SCICTL1_SLEEP_BITS);

    return;
} // end of SCI_disableSleep() function


void SCI_disableTx(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL1 &= (~SCI_SCICTL1_TXENA_BITS);

    return;
} // end of SCI_disableTx() function


void SCI_disableFifoEnh(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFTX &= (~SCI_SCIFFTX_FIFO_ENA_BITS);

    return;
} // end of SCI_disableTxFifo() function


void SCI_disableTxFifoInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFTX &= (~SCI_SCIFFTX_IENA_BITS);

    return;
} // end of SCI_disableTxFifoInt() function


void SCI_disableTxInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL2 &= (~SCI_SCICTL2_TX_INT_ENA_BITS);

    return;
} // end of SCI_disableTxInt() function


void SCI_disableTxWake(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL1 &= (~SCI_SCICTL1_TXWAKE_BITS);

    return;
} // end of SCI_disableTxWake() function


void SCI_enable(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL1 |= SCI_SCICTL1_RESET_BITS;

    return;
} // end of SCI_enable() function


void SCI_enableAutoBaudAlign(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFCT |= SCI_SCIFFCT_CDC_BITS;

    return;
} // end of SCI_enableAutoBaudAlign() function


void SCI_enableLoopBack(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICCR |= SCI_SCICCR_LB_ENA_BITS;

    return;
} // end of SCI_enableLoopBack() function


void SCI_enableParity(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICCR |= SCI_SCICCR_PARITY_ENA_BITS;

    return;
} // end of SCI_enableParity() function


void SCI_enableRx(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL1 |= SCI_SCICTL1_RXENA_BITS;

    return;
} // end of SCI_enableRx() function


void SCI_enableRxErrorInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL1 |= SCI_SCICTL1_RX_ERR_INT_ENA_BITS;

    return;
} // end of SCI_enableRxErrorInt() function


void SCI_enableRxInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL2 |= SCI_SCICTL2_RX_INT_ENA_BITS;

    return;
} // end of SCI_enableRxInt() function


void SCI_enableSleep(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL1 |= SCI_SCICTL1_SLEEP_BITS;

    return;
} // end of SCI_enableSleep() function


void SCI_enableRxFifoInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFRX |= SCI_SCIFFRX_IENA_BITS;

    return;
} // end of SCI_enableRxFifoInt() function


void SCI_enableTx(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL1 |= SCI_SCICTL1_TXENA_BITS;

    return;
} // end of SCI_enableTx() function


void SCI_enableFifoEnh(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFTX |= SCI_SCIFFTX_FIFO_ENA_BITS;

    return;
} // end of SCI_enableTxFifo() function


void SCI_enableTxFifoInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIFFTX |= SCI_SCIFFTX_IENA_BITS;

    return;
} // end of SCI_enableTxFifoInt() function


void SCI_enableTxInt(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL2 |= SCI_SCICTL2_TX_INT_ENA_BITS;

    return;
} // end of SCI_enableTxInt() function


void SCI_enableTxWake(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCICTL1 |= SCI_SCICTL1_TXWAKE_BITS;

    return;
} // end of SCI_enableTxWake() function


uint16_t SCI_getDataBlocking(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;

    while(SCI_isRxDataReady(sciHandle) != true){
    }

    return (sci->SCIRXBUF);
} // end of SCI_getDataBlocking() function


uint16_t SCI_getDataNonBlocking(SCI_Handle sciHandle, uint16_t * success)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;

    if(SCI_isRxDataReady(sciHandle)){
        *success = true;
        return (sci->SCIRXBUF); 
    }
    
    *success = false;
    return (NULL);
} // end of SCI_getDataNonBlocking() function


SCI_FifoStatus_e SCI_getRxFifoStatus(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;
    SCI_FifoStatus_e status;

    // get the status
    status = (SCI_FifoStatus_e)(sci->SCIFFRX & SCI_SCIFFRX_FIFO_ST_BITS);

    return(status);
} // SCI_getRxFifoStatus() function


SCI_FifoStatus_e SCI_getTxFifoStatus(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;
    SCI_FifoStatus_e status;

    // get the status
    status = (SCI_FifoStatus_e)(sci->SCIFFTX & SCI_SCIFFTX_FIFO_ST_BITS);

    return(status);
} // SCI_getTxFifoStatus() function


SCI_Handle SCI_init(void *pMemory, const size_t numBytes)
{
    SCI_Handle sciHandle;


    if(numBytes < sizeof(SCI_Obj))
    return((SCI_Handle)NULL);

    // assign the handle
    sciHandle = (SCI_Handle)pMemory;
    
    return(sciHandle);
} // end of SCI_init() function


void SCI_putDataBlocking(SCI_Handle sciHandle, uint16_t data)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;

    while(SCI_isTxReady(sciHandle) != true){
    }
    
    // write the data
    sci->SCITXBUF = data;
    
} // end of SCI_putDataBlocking() function


uint16_t SCI_putDataNonBlocking(SCI_Handle sciHandle, uint16_t data)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;

    if(SCI_isTxReady(sciHandle)){
        // write the data
        sci->SCITXBUF = data;
        
        return (true);
    }

    return (false);
} // end of SCI_putDataNonBlocking() function


void SCI_reset(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICTL1 &= (~SCI_SCICTL1_RESET_BITS);

    return;
} // end of SCI_reset() function


void SCI_resetChannels(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFTX &= (~SCI_SCIFFTX_CHAN_RESET_BITS);
    asm(" nop");
    sci->SCIFFTX |= (uint16_t)(SCI_SCIFFTX_CHAN_RESET_BITS);
    
    return;
} // SCI_resetChannels() function


void SCI_resetRxFifo(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFRX &= (~SCI_SCIFFRX_FIFO_RESET_BITS);
    asm(" nop");
    sci->SCIFFRX |= SCI_SCIFFRX_FIFO_RESET_BITS;

    return;
} // end of SCI_resetRxFifo() function


void SCI_resetTxFifo(SCI_Handle sciHandle)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFTX &= (~SCI_SCIFFTX_FIFO_RESET_BITS);
    asm(" nop");
    sci->SCIFFTX |= SCI_SCIFFTX_FIFO_RESET_BITS;

    return;
} // end of SCI_resetTxFifo() function


void SCI_setBaudRate(SCI_Handle sciHandle, const SCI_BaudRate_e baudRate)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIHBAUD = ((uint16_t)baudRate >> 8);
    sci->SCILBAUD = baudRate & 0xFF;

    return;
} // end of SCI_setBaudRate() function


void SCI_setCharLength(SCI_Handle sciHandle, const SCI_CharLength_e charLength)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICCR &= (~SCI_SCICCR_CHAR_LENGTH_BITS);

    // set the bits
    sci->SCICCR |= charLength;

    return;
} // SCI_setCharLength() function


void SCI_setMode(SCI_Handle sciHandle, const SCI_Mode_e mode)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICCR &= (~SCI_SCICCR_MODE_BITS);

    // set the bits
    sci->SCICCR |= mode;

    return;
} // SCI_setMode() function


void SCI_setNumStopBits(SCI_Handle sciHandle, const SCI_NumStopBits_e numBits)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICCR &= (~SCI_SCICCR_STOP_BITS);

    // set the bits
    sci->SCICCR |= numBits;

    return;
} // SCI_setNumStopBits() function


void SCI_setPriority(SCI_Handle sciHandle, const SCI_Priority_e priority)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // set the bits
    sci->SCIPRI = priority;

    return;
} // SCI_setPriority() function


void SCI_setParity(SCI_Handle sciHandle, const SCI_Parity_e parity)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCICCR &= (~SCI_SCICCR_PARITY_BITS);

    // set the bits
    sci->SCICCR |= parity;

    return;
} // SCI_setParity() function


void SCI_setTxDelay(SCI_Handle sciHandle, const uint8_t delay)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the bits
    sci->SCIFFCT &= (~SCI_SCIFFCT_DELAY_BITS); 

    // set the bits
    sci->SCIFFCT |= delay;

    return;
} // end of SCI_setTxDelay() function

void SCI_setRxFifoIntLevel(SCI_Handle sciHandle, const SCI_FifoLevel_e fifoLevel)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the value
    sci->SCIFFTX &= (~SCI_SCIFFRX_IL_BITS);

    // set the bits
    sci->SCIFFRX |= fifoLevel;

    return;
} // end of SCI_setRxFifoIntLevel() function

void SCI_setTxFifoIntLevel(SCI_Handle sciHandle, const SCI_FifoLevel_e fifoLevel)
{
    SCI_Obj *sci = (SCI_Obj *)sciHandle;


    // clear the value
    sci->SCIFFTX &= (~SCI_SCIFFTX_IL_BITS);

    // set the bits
    sci->SCIFFTX |= fifoLevel;

    return;
} // end of SCI_setTxFifoIntLevel() function


// end of file
