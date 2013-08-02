/* --COPYRIGHT--,BSD
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/
/* 
 * ======== usbConstructs.c ========
 */
#include "device.h"
#include "types.h"   //Basic Type declarations

#include "descriptors.h"
#include "usb.h"     //USB-specific functions

#ifdef _CDC_
    #include "UsbCdc.h"
#endif
#ifdef _HID_
    #include "UsbHid.h"
#endif
#ifdef _PHDC_
    #include "UsbPHDC.h"
#endif

#include <intrinsics.h>
#include "usbConstructs.h"


/**************************************************************************************************
 * These are example, user-editable construct functions for calling the API.
 *
 * In cases where fast development is the priority, it's usually best to use these sending
 * construct functions, rather than calling USBCDC_sendData() or USBHID_sendData()
 * directly.  This is because they put boundaries on the "background execution" of sends,
 * simplfying the application.
 *
 * xxxsendDataWaitTilDone() essentially eliminates background processing altogether, always
 * polling after the call to send and not allowing execution to resume until it's done.  This
 * allows simpler coding at the expense of wasted MCU cycles, and MCU execution being "locked"
 * to the host (also called "synchronous" operation).
 *
 * xxxsendDataInBackground() takes advantage of background processing ("asynchronous" operation)
 * by allowing sending to happen during application execution; while at the same time ensuring
 * that the sending always definitely occurs.  It provides most of the simplicity of
 * xxxsendDataWaitTilDone() while minimizing wasted cycles.  It's probably the best choice
 * for most applications.
 *
 * A true, asynchronous implementation would be the most cycle-efficient, but is the most
 * difficult to code; and can't be "contained" in an example function as these other approaches
 * are.  Such an implementation might be advantageous in RTOS-based implementations or those
 * requiring the highest levels of efficiency.
 *
 * These functions take into account all the pertinent return codes, toward ensuring fully
 * robust operation.   The send functions implement a timeout feature, using a loose "number of
 * retries" approach.  This was done in order to avoid using additional hardware resources.  A
 * more sophisticated approach, which the developer might want to implement, would be to use a
 * hardware timer.
 *
 * Please see the MSP430 CDC/HID/MSC USB API Programmer's Guide for a full description of these
 * functions, how they work, and how to use them.
 **************************************************************************************************/



#ifdef _HID_
/* This construct implements post-call polling to ensure the sending completes before the function
 * returns.  It provides the simplest coding, at the expense of wasted cycles and potentially
 * allowing MCU execution to become "locked" to the host, a disadvantage if the host (or bus) is
 * slow.  The function also checks all valid return codes, and returns non-zero if an error occurred.
 * It assumes no previous send operation is underway; also assumes size is non-zero.  */
BYTE hidSendDataWaitTilDone (BYTE* dataBuf,
    WORD size,
    BYTE intfNum,
    ULONG ulTimeout)
{
    ULONG sendCounter = 0;
    WORD bytesSent, bytesReceived;

    switch (USBHID_sendData(dataBuf,size,intfNum)){
        case kUSBHID_sendStarted:
            break;
        case kUSBHID_busNotAvailable:
            return ( 2) ;
        case kUSBHID_intfBusyError:
            return ( 3) ;
        case kUSBHID_generalError:
            return ( 4) ;
        default:;
    }

    /* If execution reaches this point, then the operation successfully started.  Now wait til it's finished. */
    while (1){
        BYTE ret = USBHID_intfStatus(intfNum,&bytesSent,&bytesReceived);
        if (ret & kUSBHID_busNotAvailable){                 /* This may happen at any time */
            return ( 2) ;
        }
        if (ret & kUSBHID_waitingForSend){
            if (ulTimeout && (sendCounter++ >= ulTimeout)){ /* Incr counter & try again */
                return ( 1) ;                               /* Timed out */
            }
        } else {
            return ( 0) ;                                   /* If neither busNotAvailable nor waitingForSend, it succeeded */
        }
    }
}

/* This construct implements pre-call polling to ensure the sending completes before the function
 * returns.  It provides simple coding while also taking advantage of the efficiencies of background
 * processing.  If a previous send operation is underway, this function does waste cycles polling,
 * like xxxsendDataWaitTilDone(); however it's less likely to do so since much of the sending
 * presumably took place in the background since the last call to xxxsendDataInBackground().
 * The function also checks all valid return codes, and returns non-zero if an error occurred.
 * It assumes no previous send operation is underway; also assumes size is non-zero.
 * This call assumes a previous send operation might be underway; also assumes size is non-zero.
 * Returns zero if send completed; non-zero if it failed, with 1 = timeout and 2 = bus is gone. */
BYTE hidSendDataInBackground (BYTE* dataBuf,
    WORD size,
    BYTE intfNum,
    ULONG ulTimeout)
{
    ULONG sendCounter = 0;
    WORD bytesSent, bytesReceived;

    while (USBHID_intfStatus(intfNum,&bytesSent,
               &bytesReceived) & kUSBHID_waitingForSend){
        if (ulTimeout && ((sendCounter++) > ulTimeout)){    /* A send operation is underway; incr counter & try again */
            return ( 1) ;                                   /* Timed out */
        }
    }

    /* The interface is now clear.  Call sendData(). */
    switch (USBHID_sendData(dataBuf,size,intfNum)){
        case kUSBHID_sendStarted:
            return ( 0) ;
        case kUSBHID_busNotAvailable:
            return ( 2) ;
        default:
            return ( 4) ;
    }
}

/* This call only retrieves data that is already waiting in the USB buffer -- that is, data that has
 * already been received by the MCU.  It assumes a previous, open receive operation (began by a direct
 * call to USBxxx_receiveData()) is NOT underway on this interface; and no receive operation remains
 * open after this call returns.  It doesn't check for kUSBxxx_busNotAvailable, because it doesn't
 * matter if it's not.  size is the maximum that is allowed to be received before exiting; i.e., it
 * is the size allotted to dataBuf.  Returns the number of bytes received. */
WORD hidReceiveDataInBuffer (BYTE* dataBuf, WORD size, BYTE intfNum)
{
    WORD bytesInBuf;
	WORD rxCount = 0;
    BYTE* currentPos = dataBuf;

    while (bytesInBuf = USBHID_bytesInUSBBuffer(intfNum)){
        if ((WORD)(currentPos - dataBuf + bytesInBuf) <= size){
            rxCount = bytesInBuf;
			USBHID_receiveData(currentPos,rxCount,intfNum);
        	currentPos += rxCount;
        } else {
            rxCount = size - (currentPos - dataBuf);
			USBHID_receiveData(currentPos,rxCount,intfNum);
        	currentPos += rxCount;
			return (currentPos - dataBuf);
        }
    }
	
	return (currentPos - dataBuf);
}

#endif

/*********************************************************************************************
 * Please see the MSP430 USB CDC API Programmer's Guide Sec. 9 for a full description of these
 * functions, how they work, and how to use them.
 **********************************************************************************************/

#ifdef _CDC_
/* This construct implements post-call polling to ensure the sending completes before the function
 * returns.  It provides the simplest coding, at the expense of wasted cycles and potentially
 * allowing MCU execution to become "locked" to the host, a disadvantage if the host (or bus) is
 * slow.  The function also checks all valid return codes, and returns non-zero if an error occurred.
 * It assumes no previous send operation is underway; also assumes size is non-zero.  */
BYTE cdcSendDataWaitTilDone (BYTE* dataBuf,
    WORD size,
    BYTE intfNum,
    ULONG ulTimeout)
{
    ULONG sendCounter = 0;
    WORD bytesSent, bytesReceived;

    switch (USBCDC_sendData(dataBuf,size,intfNum))
    {
        case kUSBCDC_sendStarted:
            break;
        case kUSBCDC_busNotAvailable:
            return ( 2) ;
        case kUSBCDC_intfBusyError:
            return ( 3) ;
        case kUSBCDC_generalError:
            return ( 4) ;
        default:;
    }

    /* If execution reaches this point, then the operation successfully started.  Now wait til it's finished. */
    while (1){
        BYTE ret = USBCDC_intfStatus(intfNum,&bytesSent,&bytesReceived);
        if (ret & kUSBCDC_busNotAvailable){                 /* This may happen at any time */
            return ( 2) ;
        }
        if (ret & kUSBCDC_waitingForSend){
            if (ulTimeout && (sendCounter++ >= ulTimeout)){ /* Incr counter & try again */
                return ( 1) ;                               /* Timed out */
            }
        } else {
            return ( 0) ;                                   /* If neither busNotAvailable nor waitingForSend, it succeeded */
        }
    }
}

/* This construct implements pre-call polling to ensure the sending completes before the function
 * returns.  It provides simple coding while also taking advantage of the efficiencies of background
 * processing.  If a previous send operation is underway, this function does waste cycles polling,
 * like xxxsendDataWaitTilDone(); however it's less likely to do so since much of the sending
 * presumably took place in the background since the last call to xxxsendDataInBackground().
 * The function also checks all valid return codes, and returns non-zero if an error occurred.
 * It assumes no previous send operation is underway; also assumes size is non-zero.
 * This call assumes a previous send operation might be underway; also assumes size is non-zero.
 * Returns zero if send completed; non-zero if it failed, with 1 = timeout and 2 = bus is gone. */
BYTE cdcSendDataInBackground (BYTE* dataBuf,
    WORD size,
    BYTE intfNum,
    ULONG ulTimeout)
{
    ULONG sendCounter = 0;
    WORD bytesSent, bytesReceived;

    while (USBCDC_intfStatus(intfNum,&bytesSent,
               &bytesReceived) & kUSBCDC_waitingForSend){
        if (ulTimeout && ((sendCounter++) > ulTimeout)){    /* A send operation is underway; incr counter & try again */
            return ( 1) ;                                   /* Timed out                */
        }
    }

    /* The interface is now clear.  Call sendData().   */
    switch (USBCDC_sendData(dataBuf,size,intfNum)){
        case kUSBCDC_sendStarted:
            return ( 0) ;
        case kUSBCDC_busNotAvailable:
            return ( 2) ;
        default:
            return ( 4) ;
    }
}

/* This call only retrieves data that is already waiting in the USB buffer -- that is, data that has
 * already been received by the MCU.  It assumes a previous, open receive operation (began by a direct
 * call to USBxxx_receiveData()) is NOT underway on this interface; and no receive operation remains
 * open after this call returns.  It doesn't check for kUSBxxx_busNotAvailable, because it doesn't
 * matter if it's not.  size is the maximum that is allowed to be received before exiting; i.e., it
 * is the size allotted to dataBuf.  Returns the number of bytes received. */
WORD cdcReceiveDataInBuffer (BYTE* dataBuf, WORD size, BYTE intfNum)
{
    WORD bytesInBuf;
	WORD rxCount = 0;
    BYTE* currentPos = dataBuf;

    while ((bytesInBuf = USBCDC_bytesInUSBBuffer(intfNum))){
        if ((WORD)(currentPos - dataBuf + bytesInBuf) <= size){
            rxCount = bytesInBuf;
			USBCDC_receiveData(currentPos,rxCount,intfNum);
        	currentPos += rxCount;
        } else {
            rxCount = size - (currentPos - dataBuf);
			USBCDC_receiveData(currentPos,rxCount,intfNum);
        	currentPos += rxCount;
			return (currentPos - dataBuf);
        }
    }
	
	return (currentPos - dataBuf);
}

#endif

#ifdef _PHDC_
/* This construct implements post-call polling to ensure the sending completes before the function
 * returns.  It provides the simplest coding, at the expense of wasted cycles and potentially
 * allowing MCU execution to become "locked" to the host, a disadvantage if the host (or bus) is
 * slow.  The function also checks all valid return codes, and returns non-zero if an error occurred.
 * It assumes no previous send operation is underway; also assumes size is non-zero.  */
BYTE phdcSendDataWaitTilDone (BYTE* dataBuf,
    WORD size,
    BYTE intfNum,
    ULONG ulTimeout)
{
    ULONG sendCounter = 0;
    WORD bytesSent, bytesReceived;

    switch (USBPHDC_sendData(dataBuf,size,intfNum))
    {
        case kUSBPHDC_sendStarted:
            break;
        case kUSBPHDC_busNotAvailable:
            return ( 2) ;
        case kUSBPHDC_intfBusyError:
            return ( 3) ;
        case kUSBPHDC_generalError:
            return ( 4) ;
        default:;
    }

    /* If execution reaches this point, then the operation successfully started.  Now wait til it's finished. */
    while (1){
        BYTE ret = USBPHDC_intfStatus(intfNum,&bytesSent,&bytesReceived);
        if (ret & kUSBPHDC_busNotAvailable){                 /* This may happen at any time */
            return ( 2) ;
        }
        if (ret & kUSBPHDC_waitingForSend){
            if (ulTimeout && (sendCounter++ >= ulTimeout)){ /* Incr counter & try again */
                return ( 1) ;                               /* Timed out */
            }
        } else {
            return ( 0) ;                                   /* If neither busNotAvailable nor waitingForSend, it succeeded */
        }
    }
}

/* This construct implements pre-call polling to ensure the sending completes before the function
 * returns.  It provides simple coding while also taking advantage of the efficiencies of background
 * processing.  If a previous send operation is underway, this function does waste cycles polling,
 * like xxxsendDataWaitTilDone(); however it's less likely to do so since much of the sending
 * presumably took place in the background since the last call to xxxsendDataInBackground().
 * The function also checks all valid return codes, and returns non-zero if an error occurred.
 * It assumes no previous send operation is underway; also assumes size is non-zero.
 * This call assumes a previous send operation might be underway; also assumes size is non-zero.
 * Returns zero if send completed; non-zero if it failed, with 1 = timeout and 2 = bus is gone. */
BYTE phdcSendDataInBackground (BYTE* dataBuf,
    WORD size,
    BYTE intfNum,
    ULONG ulTimeout)
{
    ULONG sendCounter = 0;
    WORD bytesSent, bytesReceived;

    while (USBPHDC_intfStatus(intfNum,&bytesSent,
               &bytesReceived) & kUSBPHDC_waitingForSend){
        if (ulTimeout && ((sendCounter++) > ulTimeout)){    /* A send operation is underway; incr counter & try again */
            return ( 1) ;                                   /* Timed out                */
        }
    }

    /* The interface is now clear.  Call sendData().   */
    switch (USBPHDC_sendData(dataBuf,size,intfNum)){
        case kUSBPHDC_sendStarted:
            return ( 0) ;
        case kUSBPHDC_busNotAvailable:
            return ( 2) ;
        default:
            return ( 4) ;
    }
}

/* This call only retrieves data that is already waiting in the USB buffer -- that is, data that has
 * already been received by the MCU.  It assumes a previous, open receive operation (began by a direct
 * call to USBxxx_receiveData()) is NOT underway on this interface; and no receive operation remains
 * open after this call returns.  It doesn't check for kUSBxxx_busNotAvailable, because it doesn't
 * matter if it's not.  size is the maximum that is allowed to be received before exiting; i.e., it
 * is the size allotted to dataBuf.  Returns the number of bytes received. */
WORD phdcReceiveDataInBuffer (BYTE* dataBuf, WORD size, BYTE intfNum)
{
    WORD bytesInBuf;
	WORD rxCount = 0;
    BYTE* currentPos = dataBuf;

    while (bytesInBuf = USBPHDC_bytesInUSBBuffer(intfNum)){
        if ((WORD)(currentPos - dataBuf + bytesInBuf) <= size){
            rxCount = bytesInBuf;
			USBPHDC_receiveData(currentPos,rxCount,intfNum);
        	currentPos += rxCount;
        } else {
            rxCount = size - (currentPos - dataBuf);
			USBPHDC_receiveData(currentPos,rxCount,intfNum);
        	currentPos += rxCount;
			return (currentPos - dataBuf);
        }
    }
	
	return (currentPos - dataBuf);
}

#endif
