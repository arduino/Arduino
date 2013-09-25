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
 * ======== UsbCdc.h ========
 */
#ifndef _UsbCdc_H_
#define _UsbCdc_H_

#ifdef __cplusplus
extern "C"
{
#endif


#define kUSBCDC_sendStarted         0x01
#define kUSBCDC_sendComplete        0x02
#define kUSBCDC_intfBusyError       0x03
#define kUSBCDC_receiveStarted      0x04
#define kUSBCDC_receiveCompleted    0x05
#define kUSBCDC_receiveInProgress   0x06
#define kUSBCDC_generalError        0x07
#define kUSBCDC_busNotAvailable     0x08


/*----------------------------------------------------------------------------
 * These functions can be used in application
 +----------------------------------------------------------------------------*/

/*
 * Sends data over interface intfNum, of size size and starting at address data.
 * Returns:  kUSBCDC_sendStarted
 *          kUSBCDC_sendComplete
 *          kUSBCDC_intfBusyError
 */
BYTE USBCDC_sendData (const BYTE* data, WORD size, BYTE intfNum);

/*
 * Receives data over interface intfNum, of size size, into memory starting at address data.
 */
BYTE USBCDC_receiveData (BYTE* data, WORD size, BYTE intfNum);

/*
 * Aborts an active receive operation on interface intfNum.
 * size: the number of bytes that were received and transferred
 * to the data location established for this receive operation.
 */
BYTE USBCDC_abortReceive (WORD* size, BYTE intfNum);


#define kUSBCDC_noDataWaiting 1 //returned by USBCDC_rejectData() if no data pending

/*
 * This function rejects payload data that has been received from the host.
 */
BYTE USBCDC_rejectData (BYTE intfNum);

/*
 * Aborts an active send operation on interface intfNum.  Returns the number of bytes that were sent prior to the abort, in size.
 */
BYTE USBCDC_abortSend (WORD* size, BYTE intfNum);


#define kUSBCDC_waitingForSend      0x01
#define kUSBCDC_waitingForReceive   0x02
#define kUSBCDC_dataWaiting         0x04
#define kUSBCDC_busNotAvailable     0x08
#define kUSB_allCdcEvents           0xFF

/*
 * This function indicates the status of the interface intfNum.
 * If a send operation is active for this interface,
 * the function also returns the number of bytes that have been transmitted to the host.
 * If a receiver operation is active for this interface, the function also returns
 * the number of bytes that have been received from the host and are waiting at the assigned address.
 *
 * returns kUSBCDC_waitingForSend (indicates that a call to USBCDC_SendData()
 * has been made, for which data transfer has not been completed)
 *
 * returns kUSBCDC_waitingForReceive (indicates that a receive operation
 * has been initiated, but not all data has yet been received)
 *
 * returns kUSBCDC_dataWaiting (indicates that data has been received
 * from the host, waiting in the USB receive buffers)
 */
BYTE USBCDC_intfStatus (BYTE intfNum, WORD* bytesSent, WORD* bytesReceived);

/*
 * Returns how many bytes are in the buffer are received and ready to be read.
 */
BYTE USBCDC_bytesInUSBBuffer (BYTE intfNum);

/*----------------------------------------------------------------------------
 * Event-Handling routines
 +----------------------------------------------------------------------------*/

/*
 * This event indicates that data has been received for interface intfNum, but no data receive operation is underway.
 * returns TRUE to keep CPU awake
 */
BYTE USBCDC_handleDataReceived (BYTE intfNum);

/*
 * This event indicates that a send operation on interface intfNum has just been completed.
 * returns TRUE to keep CPU awake
 */
BYTE USBCDC_handleSendCompleted (BYTE intfNum);

/*
 * This event indicates that a receive operation on interface intfNum has just been completed.
 * returns TRUE to keep CPU awake
 */
BYTE USBCDC_handleReceiveCompleted (BYTE intfNum);

/*
 * Toggle state variable for CTS in USB Stack
 */
void USBCDC_setCTS(BYTE state);

/*
 * This event indicates that a SetLineCoding request was received from the host and new values
 * for line coding paramters are available.
 *
 */
BYTE USBCDC_handleSetLineCoding (BYTE intfNum, ULONG lBaudrate);

/*
 * This event indicates that a SetControlLineState request was received from the host. 
 * Basically new RTS and DTR states have been sent. Bit 0 of lineState is DTR and Bit 1 is RTS.
 *
 */
BYTE USBCDC_handleSetControlLineState (BYTE intfNum, BYTE lineState);

/*----------------------------------------------------------------------------
 * These functions is to be used ONLY by USB stack, and not by application
 +----------------------------------------------------------------------------*/

/**
 * Send a packet with the settings of the second uart back to the usb host
 */
BYTE usbGetLineCoding(VOID);

/**
 * Prepare EP0 to receive a packet with the settings for the second uart
 */
BYTE usbSetLineCoding(VOID);

/**
 * Function set or reset RTS
 */
BYTE usbSetControlLineState(VOID);

/**
 * Readout the settings (send from usb host) for the second uart
 */
BYTE Handler_SetLineCoding(VOID);

/**
 * sets up dma for CDC interface used as usb to uart bridge
 */
BYTE USBCDC_setupDMA_Bridge();
/**
 * sends data alread present in endpoint buffer
 */
BYTE USBCDC_Bridge_sendData (WORD size, BYTE intfNum);
/**
 * gets address of input endpoint X
 */
BYTE *USBCDC_Bridge_getInEndpointBufferXAddr(BYTE intfNum);
/**
 * gets address of input endpoint Y
 */
BYTE *USBCDC_Bridge_getInEndpointBufferYAddr(BYTE intfNum);
/**
 * gets address of output endpoint X
 */
BYTE *USBCDC_Bridge_getOutEndpointBufferXAddr(BYTE intfNum);
/**
 * gets address of output endpoint Y
 */
BYTE *USBCDC_Bridge_getOutEndpointBufferYAddr(BYTE intfNum);
/**
 * completes receive operation once data from endpoint has been transmitted thru uart
 */
BYTE USBCDC_Bridge_completeReceiveData(BYTE intfNum);


#ifdef __cplusplus
}
#endif
#endif  //_UsbCdc_H_
