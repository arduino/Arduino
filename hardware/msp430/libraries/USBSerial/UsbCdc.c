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
 * ======== UsbCdc.c ========
 */
#include <descriptors.h>

#ifdef _CDC_


#include "device.h"
#include "types.h"                //Basic Type declarations
#include "defMSP430USB.h"
#include "usb.h"                  //USB-specific Data Structures
#include "UsbCdc.h"

#include <string.h>

//Local Macros
#define INTFNUM_OFFSET(X)   (X - CDC0_INTFNUM)  //Get the CDC offset

static struct _CdcControl {
    ULONG lBaudrate;
    BYTE bDataBits;
    BYTE bStopBits;
    BYTE bParity;
} CdcControl[CDC_NUM_INTERFACES];

static struct _CdcWrite {
    WORD nCdcBytesToSend;                       //holds counter of bytes to be sent
    WORD nCdcBytesToSendLeft;                   //holds counter how many bytes is still to be sent
    const BYTE* pUsbBufferToSend;               //holds the buffer with data to be sent
    BYTE bCurrentBufferXY;                      //is 0 if current buffer to write data is X, or 1 if current buffer is Y
    BYTE bZeroPacketSent;                       //= FALSE;
    BYTE last_ByteSend;
} CdcWriteCtrl[CDC_NUM_INTERFACES];

static struct _CdcRead {
    BYTE *pUserBuffer;                          //holds the current position of user's receiving buffer. If NULL- no receiving
                                                //operation started
    BYTE *pCurrentEpPos;                        //current positon to read of received data from curent EP
    WORD nBytesToReceive;                       //holds how many bytes was requested by receiveData() to receive
    WORD nBytesToReceiveLeft;                   //holds how many bytes is still requested by receiveData() to receive
    BYTE * pCT1;                                //holds current EPBCTxx register
    BYTE * pCT2;                                //holds next EPBCTxx register
    BYTE * pEP2;                                //holds addr of the next EP buffer
    BYTE nBytesInEp;                            //how many received bytes still available in current EP
    BYTE bCurrentBufferXY;                      //indicates which buffer is used by host to transmit data via OUT endpoint3
} CdcReadCtrl[CDC_NUM_INTERFACES];

#ifdef BRIDGE_CDC_PRESENT

static struct _CdcBridgeCtrl {
    BYTE *uartRx;
    BYTE *uartTx;
    BYTE *uartIFG;
    WORD *usbToUartDmaChSz;
    WORD *usbToUartDmaChCtl;
    BYTE ctsState;
} CdcBridgeCtrl;

#endif

extern WORD wUsbEventMask;

//function pointers
extern VOID *(*USB_TX_memcpy)(VOID * dest, const VOID * source, size_t count);
extern VOID *(*USB_RX_memcpy)(VOID * dest, const VOID * source, size_t count);


/*----------------------------------------------------------------------------+
 | Global Variables                                                            |
 +----------------------------------------------------------------------------*/

#ifdef __GNUC__
extern tDEVICE_REQUEST tSetupPacket  __asm__("0x2380");
extern tEDB __data16 tInputEndPointDescriptorBlock[7] __asm__("0x23C8");
extern tEDB __data16 tOutputEndPointDescriptorBlock[7] __asm__("0x2388");
#else
extern __no_init tEDB __data16 tInputEndPointDescriptorBlock[];
extern __no_init tEDB __data16 tOutputEndPointDescriptorBlock[];
#endif

VOID CdcResetData ()
{
    int i;

    //indicates which buffer is used by host to transmit data via OUT endpoint3 - X buffer is first
    //CdcReadCtrl[intfIndex].bCurrentBufferXY = X_BUFFER;

    memset(&CdcWriteCtrl, 0, sizeof(CdcWriteCtrl));
    memset(&CdcReadCtrl, 0, sizeof(CdcReadCtrl));
    memset(&CdcControl, 0, sizeof(CdcControl));
   
    for (i = 0; i < CDC_NUM_INTERFACES; i++){
        CdcControl[i].bDataBits = 8;
    }
}

/*
 * Sends data over interface intfNum, of size size and starting at address data.
 * Returns: kUSBCDC_sendStarted
 *       kUSBCDC_sendComplete
 *       kUSBCDC_intfBusyError
 */
BYTE USBCDC_sendData (const BYTE* data, WORD size, BYTE intfNum)
{
    BYTE edbIndex;
    WORD state;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    if (size == 0){
        return (kUSBCDC_generalError);
    }

    state = usbDisableInEndpointInterrupt(edbIndex);

    //do not access USB memory if suspended (PLL uce BUS_ERROR
    if ((bFunctionSuspended) ||
        (bEnumerationStatus != ENUMERATION_COMPLETE)){
        //data can not be read because of USB suspended
    	usbRestoreInEndpointInterrupt(state);                                            //restore interrupt status
        return (kUSBCDC_busNotAvailable);
    }

    if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft != 0){
        //the USB still sends previous data, we have to wait
    	usbRestoreInEndpointInterrupt(state);                                           //restore interrupt status
        return (kUSBCDC_intfBusyError);
    }

    //This function generate the USB interrupt. The data will be sent out from interrupt

    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSend = size;
    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft = size;
    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].pUsbBufferToSend = data;

    //trigger Endpoint Interrupt - to start send operation
    USBIEPIFG |= 1 << (edbIndex + 1);                                       //IEPIFGx;

    usbRestoreInEndpointInterrupt(state);

    return (kUSBCDC_sendStarted);
}

#define EP_MAX_PACKET_SIZE_CDC      0x40

//this function is used only by USB interrupt
BOOL CdcToHostFromBuffer (BYTE intfNum)
{
    BYTE byte_count, nTmp2;
    BYTE * pEP1;
    BYTE * pEP2;
    BYTE * pCT1;
    BYTE * pCT2;
    BYTE bWakeUp = FALSE;                                                   //TRUE for wake up after interrupt
    BYTE edbIndex;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft == 0){    //do we have somtething to send?
        if (!CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bZeroPacketSent){        //zero packet was not yet sent
            CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bZeroPacketSent = TRUE;

            if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].last_ByteSend ==
                EP_MAX_PACKET_SIZE_CDC){
                if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY ==
                    X_BUFFER){
                    if (tInputEndPointDescriptorBlock[edbIndex].bEPBCTX &
                        EPBCNT_NAK){
                        tInputEndPointDescriptorBlock[edbIndex].bEPBCTX = 0;
                        CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY
                            = Y_BUFFER;                                     //switch buffer
                    }
                } else {
                    if (tInputEndPointDescriptorBlock[edbIndex].bEPBCTY &
                        EPBCNT_NAK){
                        tInputEndPointDescriptorBlock[edbIndex].bEPBCTY = 0;
                        CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY
                            = X_BUFFER;                                     //switch buffer
                    }
                }
            }

            CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSend = 0;      //nothing to send

            //call event callback function
            if (wUsbEventMask & kUSB_sendCompletedEvent){
                bWakeUp = USBCDC_handleSendCompleted(intfNum);
            }
        } //if (!bSentZeroPacket)

        return (bWakeUp);
    }

    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bZeroPacketSent = FALSE;          //zero packet will be not sent: we have data

    if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY == X_BUFFER){
        //this is the active EP buffer
        pEP1 = (BYTE*)stUsbHandle[intfNum].iep_X_Buffer;
        pCT1 = &tInputEndPointDescriptorBlock[edbIndex].bEPBCTX;

        //second EP buffer
        pEP2 = (BYTE*)stUsbHandle[intfNum].iep_Y_Buffer;
        pCT2 = &tInputEndPointDescriptorBlock[edbIndex].bEPBCTY;
    } else {
        //this is the active EP buffer
        pEP1 = (BYTE*)stUsbHandle[intfNum].iep_Y_Buffer;
        pCT1 = &tInputEndPointDescriptorBlock[edbIndex].bEPBCTY;

        //second EP buffer
        pEP2 = (BYTE*)stUsbHandle[intfNum].iep_X_Buffer;
        pCT2 = &tInputEndPointDescriptorBlock[edbIndex].bEPBCTX;
    }

    //how many byte we can send over one endpoint buffer
    byte_count =
        (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft >
         EP_MAX_PACKET_SIZE_CDC) ? EP_MAX_PACKET_SIZE_CDC : CdcWriteCtrl[
            INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft;
    nTmp2 = *pCT1;

    if (nTmp2 & EPBCNT_NAK){
        USB_TX_memcpy(pEP1, CdcWriteCtrl[INTFNUM_OFFSET(
                                             intfNum)].pUsbBufferToSend,
            byte_count);                                                            //copy data into IEP3 X or Y buffer
        *pCT1 = byte_count;                                                         //Set counter for usb In-Transaction
        CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY =
            (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY + 1) & 0x01;    //switch buffer
        CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft -= byte_count;
        CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].pUsbBufferToSend += byte_count;       //move buffer pointer
        CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].last_ByteSend = byte_count;

        //try to send data over second buffer
        nTmp2 = *pCT2;
        if ((CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft > 0) &&      //do we have more data to send?
            (nTmp2 & EPBCNT_NAK)){                                                  //if the second buffer is free?
            //how many byte we can send over one endpoint buffer
            byte_count =
                (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft >
                 EP_MAX_PACKET_SIZE_CDC) ? EP_MAX_PACKET_SIZE_CDC :
                CdcWriteCtrl[
                    INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft;

            USB_TX_memcpy(pEP2, CdcWriteCtrl[INTFNUM_OFFSET(
                                                 intfNum)].pUsbBufferToSend,
                byte_count);                                                        //copy data into IEP3 X or Y buffer
            *pCT2 = byte_count;                                                     //Set counter for usb In-Transaction
            CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY =
                (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY +
                 1) & 0x01;                                                         //switch buffer
            CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft -=
                byte_count;
            CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].pUsbBufferToSend +=
                byte_count;                                                         //move buffer pointer
            CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].last_ByteSend = byte_count;
        }
    }
    return (bWakeUp);
}

/*
 * Aborts an active send operation on interface intfNum.
 * Returns the number of bytes that were sent prior to the abort, in size.
 */
BYTE USBCDC_abortSend (WORD* size, BYTE intfNum)
{
    BYTE edbIndex;
    WORD state;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    state = usbDisableInEndpointInterrupt(edbIndex);                                                         //disable interrupts - atomic operation

    *size =
        (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSend -
         CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft);
    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSend = 0;
    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft = 0;

    usbRestoreInEndpointInterrupt(state);
    return (kUSB_succeed);
}

//This function copies data from OUT endpoint into user's buffer
//Arguments:
//pEP - pointer to EP to copy from
//pCT - pointer to pCT control reg
//
VOID CopyUsbToBuff (BYTE* pEP, BYTE* pCT, BYTE intfNum)
{
    BYTE nCount;

    //how many byte we can get from one endpoint buffer
    nCount =
        (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft >
         CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp) ? CdcReadCtrl[
            INTFNUM_OFFSET(intfNum)].nBytesInEp : CdcReadCtrl[INTFNUM_OFFSET(
                                                                  intfNum)].
        nBytesToReceiveLeft;

    USB_RX_memcpy(CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer, pEP, nCount);   //copy data from OEP3 X or Y buffer
    CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft -= nCount;
    CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer += nCount;                     //move buffer pointer
    //to read rest of data next time from this place

    if (nCount == CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp){                 //all bytes are copied from receive buffer?
        //switch current buffer
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY =
            (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY + 1) & 0x01;

        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = 0;

        //clear NAK, EP ready to receive data
        *pCT = 0x00;
    } else {
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp -= nCount;
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCurrentEpPos = pEP + nCount;
    }
}

/*
 * Receives data over interface intfNum, of size size, into memory starting at address data.
 * Returns:
 *  kUSBCDC_receiveStarted  if the receiving process started.
 *  kUSBCDC_receiveCompleted  all requested date are received.
 *  kUSBCDC_receiveInProgress  previous receive opereation is in progress. The requested receive operation can be not started.
 *  kUSBCDC_generalError  error occurred.
 */
BYTE USBCDC_receiveData (BYTE* data, WORD size, BYTE intfNum)
{
    BYTE nTmp1;
    BYTE edbIndex;
    WORD state;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    if ((size == 0) ||                                                      //read size is 0
        (data == NULL)){
        return (kUSBCDC_generalError);
    }

    state = usbDisableOutEndpointInterrupt(edbIndex);
    //atomic operation - disable interrupts

    //do not access USB memory if suspended (PLL off). It may produce BUS_ERROR
    if ((bFunctionSuspended) ||
        (bEnumerationStatus != ENUMERATION_COMPLETE)){
        //data can not be read because of USB suspended
    	usbRestoreOutEndpointInterrupt(state);
        return (kUSBCDC_busNotAvailable);
    }

    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer != NULL){          //receive process already started
    	usbRestoreOutEndpointInterrupt(state);
        return (kUSBCDC_intfBusyError);
    }

    CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceive = size;            //bytes to receive
    CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft = size;        //left bytes to receive
    CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer = data;                //set user receive buffer

    //read rest of data from buffer, if any
    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp > 0){
        //copy data from pEP-endpoint into User's buffer
        CopyUsbToBuff(CdcReadCtrl[INTFNUM_OFFSET(
                                      intfNum)].pCurrentEpPos,
            CdcReadCtrl[INTFNUM_OFFSET(
                            intfNum)
            ].pCT1, intfNum);

        if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft == 0){ //the Receive opereation is completed
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer = NULL;        //no more receiving pending
            if (wUsbEventMask & kUSB_receiveCompletedEvent){
                USBCDC_handleReceiveCompleted(intfNum);                     //call event handler in interrupt context
            }
            usbRestoreOutEndpointInterrupt(state);
            return (kUSBCDC_receiveCompleted);                              //receive completed
        }

        //check other EP buffer for data - exchange pCT1 with pCT2
        if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 ==
            &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX){
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
                &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY;
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCurrentEpPos =
                (BYTE*)stUsbHandle[intfNum].oep_Y_Buffer;
        } else {
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
                &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX;
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCurrentEpPos =
                (BYTE*)stUsbHandle[intfNum].oep_X_Buffer;
        }

        nTmp1 = *CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1;
        //try read data from second buffer
        if (nTmp1 & EPBCNT_NAK){                                            //if the second buffer has received data?
            nTmp1 = nTmp1 & 0x7f;                                           //clear NAK bit
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = nTmp1;        //holds how many valid bytes in the EP buffer
            CopyUsbToBuff(CdcReadCtrl[INTFNUM_OFFSET(
                                          intfNum)].pCurrentEpPos,
                CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1, intfNum);
        }

        if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft == 0){ //the Receive opereation is completed
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer = NULL;        //no more receiving pending
            if (wUsbEventMask & kUSB_receiveCompletedEvent){
                USBCDC_handleReceiveCompleted(intfNum);                     //call event handler in interrupt context
            }
            usbRestoreOutEndpointInterrupt(state);
            return (kUSBCDC_receiveCompleted);                              //receive completed
        }
    } //read rest of data from buffer, if any

    //read 'fresh' data, if available
    nTmp1 = 0;
    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY == X_BUFFER){ //this is current buffer
        if (tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX & EPBCNT_NAK){ //this buffer has a valid data packet
            //this is the active EP buffer
            //pEP1
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCurrentEpPos =
                (BYTE*)stUsbHandle[intfNum].oep_X_Buffer;
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
                &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX;

            //second EP buffer
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pEP2 =
                (BYTE*)stUsbHandle[intfNum].oep_Y_Buffer;
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2 =
                &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY;
            nTmp1 = 1;                                                      //indicate that data is available
        }
    } else {                                                                //Y_BUFFER
        if (tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY & EPBCNT_NAK){
            //this is the active EP buffer
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCurrentEpPos =
                (BYTE*)stUsbHandle[intfNum].oep_Y_Buffer;
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
                &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY;

            //second EP buffer
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pEP2 =
                (BYTE*)stUsbHandle[intfNum].oep_X_Buffer;
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2 =
                &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX;
            nTmp1 = 1;                                                      //indicate that data is available
        }
    }

    if (nTmp1){
        //how many byte we can get from one endpoint buffer
        nTmp1 = *CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1;
        while (nTmp1 == 0)
        {
            nTmp1 = *CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1;
        }

        if (nTmp1 & EPBCNT_NAK){
            nTmp1 = nTmp1 & 0x7f;                                           //clear NAK bit
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = nTmp1;        //holds how many valid bytes in the EP buffer

            CopyUsbToBuff(CdcReadCtrl[INTFNUM_OFFSET(
                                          intfNum)].pCurrentEpPos,
                CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1, intfNum);

            nTmp1 = *CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2;
            //try read data from second buffer
            if ((CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft >
                 0) &&                                                      //do we have more data to send?
                (nTmp1 & EPBCNT_NAK)){                                      //if the second buffer has received data?
                nTmp1 = nTmp1 & 0x7f;                                       //clear NAK bit
                CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = nTmp1;    //holds how many valid bytes in the EP buffer
                CopyUsbToBuff(CdcReadCtrl[INTFNUM_OFFSET(
                                              intfNum)].pEP2,
                    CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2, intfNum);
                CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
                    CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2;
            }
        }
    }

    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft == 0){     //the Receive opereation is completed
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer = NULL;            //no more receiving pending
        if (wUsbEventMask & kUSB_receiveCompletedEvent){
            USBCDC_handleReceiveCompleted(intfNum);                         //call event handler in interrupt context
        }
        usbRestoreOutEndpointInterrupt(state);
        return (kUSBCDC_receiveCompleted);
    }

    //interrupts enable
    usbRestoreOutEndpointInterrupt(state);
    return (kUSBCDC_receiveStarted);
}

//this function is used only by USB interrupt.
//It fills user receiving buffer with received data
BOOL CdcToBufferFromHost (BYTE intfNum)
{
    BYTE * pEP1;
    BYTE nTmp1;
    BYTE bWakeUp = FALSE;                                                   //per default we do not wake up after interrupt

    BYTE edbIndex;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft == 0){     //do we have somtething to receive?
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer = NULL;            //no more receiving pending
        return (bWakeUp);
    }

    //No data to receive...
    if (!((tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX |
           tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY)
          & 0x80)){
        return (bWakeUp);
    }

    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY == X_BUFFER){ //X is current buffer
        //this is the active EP buffer
        pEP1 = (BYTE*)stUsbHandle[intfNum].oep_X_Buffer;
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
            &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX;

        //second EP buffer
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pEP2 =
            (BYTE*)stUsbHandle[intfNum].oep_Y_Buffer;
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2 =
            &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY;
    } else {
        //this is the active EP buffer
        pEP1 = (BYTE*)stUsbHandle[intfNum].oep_Y_Buffer;
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
            &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY;

        //second EP buffer
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pEP2 =
            (BYTE*)stUsbHandle[intfNum].oep_X_Buffer;
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2 =
            &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX;
    }

    //how many byte we can get from one endpoint buffer
    nTmp1 = *CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1;

    if (nTmp1 & EPBCNT_NAK){
        nTmp1 = nTmp1 & 0x7f;                                                   //clear NAK bit
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = nTmp1;                //holds how many valid bytes in the EP buffer

        CopyUsbToBuff(pEP1, CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1, intfNum);

        nTmp1 = *CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2;
        //try read data from second buffer
        if ((CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft > 0) &&   //do we have more data to send?
            (nTmp1 & EPBCNT_NAK)){                                              //if the second buffer has received data?
            nTmp1 = nTmp1 & 0x7f;                                               //clear NAK bit
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = nTmp1;            //holds how many valid bytes in the EP buffer
            CopyUsbToBuff(CdcReadCtrl[INTFNUM_OFFSET(
                                          intfNum)].pEP2,
                CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2, intfNum);
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT1 =
                CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2;
        }
    }

    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft == 0){         //the Receive opereation is completed
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer = NULL;                //no more receiving pending
        if (wUsbEventMask & kUSB_receiveCompletedEvent){
            bWakeUp |= USBCDC_handleReceiveCompleted(intfNum);
        }

        if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp){                   //Is not read data still available in the EP?
            if (wUsbEventMask & kUSB_dataReceivedEvent){
                bWakeUp |= USBCDC_handleDataReceived(intfNum);
            }
        }
    }
    return (bWakeUp);
}

//helper for USB interrupt handler
BOOL CdcIsReceiveInProgress (BYTE intfNum)
{
    return (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer != NULL);
}

/*
 * Aborts an active receive operation on interface intfNum.
 * Returns the number of bytes that were received and transferred
 * to the data location established for this receive operation.
 */
BYTE USBCDC_abortReceive (WORD* size, BYTE intfNum)
{
    //interrupts disable
	BYTE edbIndex;
	WORD state;

    edbIndex = stUsbHandle[intfNum].edb_Index;
    state = usbDisableOutEndpointInterrupt(edbIndex);

    *size = 0;                                                              //set received bytes count to 0

    //is receive operation underway?
    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer){
        //how many bytes are already received?
        *size = CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceive -
                CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft;

        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = 0;
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer = NULL;
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceiveLeft = 0;
    }

    //restore interrupt status
    usbRestoreOutEndpointInterrupt(state);
    return (kUSB_succeed);
}

/*
 * This function rejects payload data that has been received from the host.
 */
BYTE USBCDC_rejectData (BYTE intfNum)
{
    BYTE edbIndex;
    WORD state;

    edbIndex = stUsbHandle[intfNum].edb_Index;
    state = usbDisableOutEndpointInterrupt(edbIndex);

    //atomic operation - disable interrupts

    //do not access USB memory if suspended (PLL off). It may produce BUS_ERROR
    if (bFunctionSuspended){
    	usbRestoreOutEndpointInterrupt(state);
        return (kUSBCDC_busNotAvailable);
    }

    //Is receive operation underway?
    //- do not flush buffers if any operation still active.
    if (!CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer){
        BYTE tmp1 = tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX &
                    EPBCNT_NAK;
        BYTE tmp2 = tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY &
                    EPBCNT_NAK;

        if (tmp1 ^ tmp2){                                                   //switch current buffer if any and only ONE of buffers
                                                                            //is full
            //switch current buffer
            CdcReadCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY =
                (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY +
                 1) & 0x01;
        }

        tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX = 0;               //flush buffer X
        tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY = 0;               //flush buffer Y
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = 0;                //indicates that no more data available in the EP
    }

    usbRestoreOutEndpointInterrupt(state);
    return (kUSB_succeed);
}

/*
 * This function indicates the status of the itnerface intfNum.
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
BYTE USBCDC_intfStatus (BYTE intfNum, WORD* bytesSent, WORD* bytesReceived)
{
    BYTE ret = 0;
    WORD stateIn, stateOut;
    BYTE edbIndex;

    *bytesSent = 0;
    *bytesReceived = 0;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    stateIn = usbDisableInEndpointInterrupt(edbIndex);
    stateOut = usbDisableOutEndpointInterrupt(edbIndex);

    //Is send operation underway?
    if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft != 0){
        ret |= kUSBCDC_waitingForSend;
        *bytesSent = CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSend -
                     CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft;
    }

    //Is receive operation underway?
    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pUserBuffer != NULL){
        ret |= kUSBCDC_waitingForReceive;
        *bytesReceived = CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesToReceive -
                         CdcReadCtrl[INTFNUM_OFFSET(intfNum)].
                         nBytesToReceiveLeft;
    } else {                                                                //receive operation not started
        //do not access USB memory if suspended (PLL off).
        //It may produce BUS_ERROR
        if (!bFunctionSuspended){
            if ((tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX &
                 EPBCNT_NAK)  |                                             //any of buffers has a valid data packet
                (tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY &
                 EPBCNT_NAK)){
                ret |= kUSBCDC_dataWaiting;
            }
        }
    }

    if ((bFunctionSuspended) ||
        (bEnumerationStatus != ENUMERATION_COMPLETE)){
        //if suspended or not enumerated - report no other tasks pending
        ret = kUSBCDC_busNotAvailable;
    }

    //restore interrupt status
    usbRestoreInEndpointInterrupt(stateIn);
    usbRestoreOutEndpointInterrupt(stateOut);

    __no_operation();
    return (ret);
}

/*
 * Returns how many bytes are in the buffer are received and ready to be read.
 */
BYTE USBCDC_bytesInUSBBuffer (BYTE intfNum)
{
    BYTE bTmp1 = 0;
    WORD state;
    BYTE edbIndex;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    state = usbDisableOutEndpointInterrupt(edbIndex);
    //atomic operation - disable interrupts

    if ((bFunctionSuspended) ||
        (bEnumerationStatus != ENUMERATION_COMPLETE)){
    	usbRestoreOutEndpointInterrupt(state);
        //if suspended or not enumerated - report 0 bytes available
        return (0);
    }

    if (CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp > 0){               //If a RX operation is underway, part of data may
                                                                            //was read of the OEP buffer
        bTmp1 = CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp;
        if (*CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2 & EPBCNT_NAK){       //the next buffer has a valid data packet
            bTmp1 += *CdcReadCtrl[INTFNUM_OFFSET(intfNum)].pCT2 & 0x7F;
        }
    } else {
        if (tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX & EPBCNT_NAK){ //this buffer has a valid data packet
            bTmp1 = tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX & 0x7F;
        }
        if (tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY & EPBCNT_NAK){ //this buffer has a valid data packet
            bTmp1 += tOutputEndPointDescriptorBlock[edbIndex].bEPBCTY & 0x7F;
        }
    }

    usbRestoreOutEndpointInterrupt(state);
    return (bTmp1);
}

//----------------------------------------------------------------------------
//Line Coding Structure
//dwDTERate     | 4 | Data terminal rate, in bits per second
//bCharFormat   | 1 | Stop bits, 0 = 1 Stop bit, 1 = 1,5 Stop bits, 2 = 2 Stop bits
//bParityType   | 1 | Parity, 0 = None, 1 = Odd, 2 = Even, 3= Mark, 4 = Space
//bDataBits     | 1 | Data bits (5,6,7,8,16)
//----------------------------------------------------------------------------
BYTE usbGetLineCoding (VOID)
{
    BYTE infIndex;

    if(tSetupPacket.wIndex % 2)
    {
        infIndex = (tSetupPacket.wIndex-1) / 2;
    }
    else
    {
        infIndex = (tSetupPacket.wIndex) / 2;
    }

    abUsbRequestReturnData[6] =
        CdcControl[infIndex].bDataBits;          //Data bits = 8
    abUsbRequestReturnData[5] =
        CdcControl[infIndex].bParity;            //No Parity
    abUsbRequestReturnData[4] =
        CdcControl[infIndex].bStopBits;          //Stop bits = 1

    abUsbRequestReturnData[3] =
        CdcControl[infIndex].lBaudrate >> 24;
    abUsbRequestReturnData[2] =
        CdcControl[infIndex].lBaudrate >> 16;
    abUsbRequestReturnData[1] =
        CdcControl[infIndex].lBaudrate >> 8;
    abUsbRequestReturnData[0] =
        CdcControl[infIndex].lBaudrate;

    wBytesRemainingOnIEP0 = 0x07;                                           //amount of data to be send over EP0 to host
    usbSendDataPacketOnEP0((PBYTE)&abUsbRequestReturnData[0]);              //send data to host

    return (FALSE);
}

//----------------------------------------------------------------------------

BYTE usbSetLineCoding (VOID)
{
    usbReceiveDataPacketOnEP0((PBYTE)&abUsbRequestIncomingData);            //receive data over EP0 from Host

    return (FALSE);
}

//----------------------------------------------------------------------------

BYTE usbSetControlLineState (VOID)
{
	USBCDC_handleSetControlLineState((BYTE)tSetupPacket.wIndex,
            (BYTE)tSetupPacket.wValue);
    usbSendZeroLengthPacketOnIEP0();                                        //Send ZLP for status stage

    return (FALSE);
}

//----------------------------------------------------------------------------

BYTE Handler_SetLineCoding (VOID)
{
    BYTE bWakeUp;
    volatile BYTE infIndex;
 
    if(tSetupPacket.wIndex % 2)
    {
        infIndex = (tSetupPacket.wIndex-1) / 2;
    }
    else
    {
        infIndex = (tSetupPacket.wIndex) / 2;
    }

    //Baudrate Settings

    CdcControl[infIndex].lBaudrate =
        (ULONG)abUsbRequestIncomingData[3] << 24 |
        (ULONG)abUsbRequestIncomingData[2] << 16 |
        (ULONG)
        abUsbRequestIncomingData[1] << 8 | abUsbRequestIncomingData[0];
    bWakeUp =
        USBCDC_handleSetLineCoding(tSetupPacket.wIndex,
            CdcControl[infIndex].lBaudrate);

    return (bWakeUp);
}

#ifdef BRIDGE_CDC_PRESENT

BYTE USBCDC_setupDMA_Bridge()
{
    CdcBridgeCtrl.ctsState = 0;  
    switch (BRIDGE_UART_USCI_NUM) {
        case 0:
            CdcBridgeCtrl.uartRx = (BYTE *)&UCA0RXBUF;
            CdcBridgeCtrl.uartTx = (BYTE *)&UCA0TXBUF;
            CdcBridgeCtrl.uartIFG = (BYTE *)&UCA0IFG;
            break;
        case 1:
            CdcBridgeCtrl.uartRx = (BYTE *)&UCA1RXBUF;
            CdcBridgeCtrl.uartTx = (BYTE *)&UCA1TXBUF;
            CdcBridgeCtrl.uartIFG = (BYTE *)&UCA1IFG;            
            break;
        case 2:
            CdcBridgeCtrl.uartRx = (BYTE *)&UCB0RXBUF;
            CdcBridgeCtrl.uartTx = (BYTE *)&UCB0TXBUF;
            CdcBridgeCtrl.uartIFG = (BYTE *)&UCB0IFG;            
            break;
        case 3:
            CdcBridgeCtrl.uartRx = (BYTE *)&UCB1RXBUF;
            CdcBridgeCtrl.uartTx = (BYTE *)&UCB1TXBUF;
            CdcBridgeCtrl.uartIFG = (BYTE *)&UCB1IFG;            
            break;            
    }
    switch (BRIDGE_UART_TO_USB_DMA_CHAN)
    {
        case 0:            
            DMACTL0 = DMA0TSEL_16;
            __data16_write_addr((unsigned short) &DMA0SA,(unsigned long)CdcBridgeCtrl.uartRx);
            __data16_write_addr((unsigned short) &DMA0DA,(unsigned long)USBCDC_Bridge_getInEndpointBufferXAddr(CDC0_INTFNUM)); 
            DMA0SZ = 16;   
            DMA0CTL = DMADT_0 + DMADSTINCR_3 + DMASBDB + DMAEN + DMAIE;
            break;
        case 1:
            DMACTL0 = DMA1TSEL_16;
            __data16_write_addr((unsigned short) &DMA1SA,(unsigned long)CdcBridgeCtrl.uartRx);
            __data16_write_addr((unsigned short) &DMA1DA,(unsigned long)USBCDC_Bridge_getInEndpointBufferXAddr(CDC0_INTFNUM)); 
            DMA1SZ = 16;   
            DMA1CTL = DMADT_0 + DMADSTINCR_3 + DMASBDB + DMAEN + DMAIE;            
            break;
        case 2:
            DMACTL1 = DMA2TSEL_16;
            __data16_write_addr((unsigned short) &DMA2SA,(unsigned long)CdcBridgeCtrl.uartRx);
            __data16_write_addr((unsigned short) &DMA2DA,(unsigned long)USBCDC_Bridge_getInEndpointBufferXAddr(CDC0_INTFNUM)); 
            DMA2SZ = 16;   
            DMA2CTL = DMADT_0 + DMADSTINCR_3 + DMASBDB + DMAEN + DMAIE;                
            break;
    }
    
    switch (BRIDGE_USB_TO_UART_DMA_CHAN)
    {
        case 0:
            CdcBridgeCtrl.usbToUartDmaChSz = (WORD *)&DMA0SZ;
            CdcBridgeCtrl.usbToUartDmaChCtl = (WORD *)&DMA0CTL;
            DMACTL0 = DMA0TSEL_17;
            __data16_write_addr((unsigned short) &DMA0SA,(unsigned long)(USBCDC_Bridge_getOutEndpointBufferXAddr(CDC0_INTFNUM) + 1));
            __data16_write_addr((unsigned short) &DMA0DA,(unsigned long)CdcBridgeCtrl.uartTx);
            break;
        case 1:
            CdcBridgeCtrl.usbToUartDmaChSz = (WORD *)&DMA1SZ;
            CdcBridgeCtrl.usbToUartDmaChCtl = (WORD *)&DMA1CTL;            
            DMACTL0 = DMA1TSEL_17;
            __data16_write_addr((unsigned short) &DMA1SA,(unsigned long)(USBCDC_Bridge_getOutEndpointBufferXAddr(CDC0_INTFNUM) + 1));
            __data16_write_addr((unsigned short) &DMA1DA,(unsigned long)CdcBridgeCtrl.uartTx);            
            break;
        case 2:
            CdcBridgeCtrl.usbToUartDmaChSz = (WORD *)&DMA2SZ;
            CdcBridgeCtrl.usbToUartDmaChCtl = (WORD *)&DMA2CTL;            
            DMACTL1 = DMA2TSEL_17;
            __data16_write_addr((unsigned short) &DMA2SA,(unsigned long)(USBCDC_Bridge_getOutEndpointBufferXAddr(CDC0_INTFNUM) + 1));
            __data16_write_addr((unsigned short) &DMA2DA,(unsigned long)CdcBridgeCtrl.uartTx);                
            break;
    }         
    
    return (TRUE);
}

BYTE USBCDC_Bridge_sendData (WORD size, BYTE intfNum)
{
    BYTE edbIndex;
    WORD state;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    state = usbDisableInEndpointInterrupt(edbIndex);
    //atomic operation - disable interrupts

    //do not access USB memory if suspended (PLL off). It may produce BUS_ERROR
    if ((bFunctionSuspended) ||
        (bEnumerationStatus != ENUMERATION_COMPLETE)){
        //data can not be read because of USB suspended
    	usbRestoreInEndpointInterrupt(state);
        return (kUSBCDC_busNotAvailable);
    }

    if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft != 0){
        //the USB still sends previous data, we have to wait
    	usbRestoreInEndpointInterrupt(state);
        return (kUSBCDC_intfBusyError);
    }

    //This function generate the USB interrupt. The data will be sent out from interrupt

    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSend = size;
    CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft = size;

    //trigger Endpoint Interrupt - to start send operation
    USBIEPIFG |= 1 << (edbIndex + 1);                                       //IEPIFGx;

    usbRestoreInEndpointInterrupt(state);

    return (kUSBCDC_sendStarted);
}

//this function is used only by USB interrupt
BOOL CdcToHostFromBuffer_Bridge (BYTE intfNum)
{
    BYTE byte_count, nTmp2;
    BYTE * pCT1;
    BYTE bWakeUp = FALSE;                                                   //TRUE for wake up after interrupt
    BYTE edbIndex;

    if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft == 0){
        return (bWakeUp);
    }
    
    edbIndex = stUsbHandle[intfNum].edb_Index;
    
    //this is the active EP buffer
    pCT1 = &tInputEndPointDescriptorBlock[edbIndex].bEPBCTX;

    if (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY == X_BUFFER){
        pCT1 = &tInputEndPointDescriptorBlock[edbIndex].bEPBCTX;
    } else {
        pCT1 = &tInputEndPointDescriptorBlock[edbIndex].bEPBCTY;
    }
    
    //how many byte we can send over one endpoint buffer
    byte_count =
        (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft >
         EP_MAX_PACKET_SIZE_CDC) ? EP_MAX_PACKET_SIZE_CDC : CdcWriteCtrl[
            INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft;
    nTmp2 = *pCT1;

   CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY =
        (CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].bCurrentBufferXY + 1) & 0x01; 
            
    if (nTmp2 & EPBCNT_NAK){                                                            //copy data into IEP3 X or Y buffer
        *pCT1 = byte_count;                                                         //Set counter for usb In-Transaction
        CdcWriteCtrl[INTFNUM_OFFSET(intfNum)].nCdcBytesToSendLeft -= byte_count;
    }
    
    return (bWakeUp);
}

BYTE *USBCDC_Bridge_getInEndpointBufferXAddr(BYTE intfNum) {    
    return ((BYTE *)stUsbHandle[CDC0_INTFNUM].iep_X_Buffer);
}

BYTE *USBCDC_Bridge_getInEndpointBufferYAddr(BYTE intfNum) {    
    return ((BYTE *)stUsbHandle[CDC0_INTFNUM].iep_Y_Buffer);
}

BYTE *USBCDC_Bridge_getOutEndpointBufferXAddr(BYTE intfNum) {    
    return ((BYTE *)stUsbHandle[CDC0_INTFNUM].oep_X_Buffer);
}

BYTE *USBCDC_Bridge_getOutEndpointBufferYAddr(BYTE intfNum) {    
    return ((BYTE *)stUsbHandle[CDC0_INTFNUM].oep_Y_Buffer);
}

//this function is used only by USB interrupt.
//It fills user receiving buffer with received data
BOOL CdcToBufferFromHost_Bridge (BYTE intfNum)
{
    BYTE *pEP1, *pCT1;
    BYTE nTmp1;
    BYTE bWakeUp = FALSE;                                                   //per default we do not wake up after interrupt
    BYTE i;    
    BYTE edbIndex;

    edbIndex = stUsbHandle[intfNum].edb_Index;

    //No data to receive...
    if (!((tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX & 0x80))){
        return (bWakeUp);
    }

    if (CdcBridgeCtrl.ctsState == 0) {
    	return (bWakeUp);
    }
            
    //this is the active EP buffer
    pEP1 = (BYTE*)stUsbHandle[intfNum].oep_X_Buffer;
    pCT1 = &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX;
    
    __no_operation();
    __no_operation();
    
    //how many byte we can get from endpoint buffer
    nTmp1 = *pCT1;

    if (nTmp1 & EPBCNT_NAK){
        nTmp1 = nTmp1 & 0x7f;                                                   //clear NAK bit
        CdcReadCtrl[INTFNUM_OFFSET(intfNum)].nBytesInEp = nTmp1;                //holds how many valid bytes in the EP buffer

        if (nTmp1 > 0) {
            //Start DMA
            if (nTmp1 > 5 ) {
                //Start DMA
                while (!(*CdcBridgeCtrl.uartIFG & UCTXIFG));
                *CdcBridgeCtrl.uartTx = *pEP1;
                *CdcBridgeCtrl.usbToUartDmaChSz = nTmp1 - 1;                // Block size
                *CdcBridgeCtrl.usbToUartDmaChCtl = DMADT_0 + DMASRCINCR_3 + DMASBDB + DMAEN + DMAIE;// Rpt, inc src, enable
            }
            else {
                for (i = 0; i < nTmp1; i++) {                
                    while (!(*CdcBridgeCtrl.uartIFG & UCTXIFG));          // USCI_A0 TX buffer ready?
                        *CdcBridgeCtrl.uartTx = *pEP1++;                  // TX -> RXed character 
                }
                *pCT1 = 0x00;
            }
        }
        else {
             *pCT1 = 0x00;
        }        
    }
    
    return (bWakeUp);
}

BYTE USBCDC_Bridge_completeReceiveData (BYTE intfNum)
{
    BYTE *pCT1;
    BYTE edbIndex;

    DMA2CTL = 0;
    edbIndex = stUsbHandle[intfNum].edb_Index;
    pCT1 = &tOutputEndPointDescriptorBlock[edbIndex].bEPBCTX;
    *pCT1 = 0x00;
    
    return (FALSE);
}

void USBCDC_setCTS(BYTE state)
{
	  CdcBridgeCtrl.ctsState = state;
      CdcToBufferFromHost_Bridge(CDC0_INTFNUM);
}
#endif  //BRIDGE_CDC_PRESENT

#endif  //ifdef _CDC_

/*----------------------------------------------------------------------------+
 | End of source file                                                          |
 +----------------------------------------------------------------------------*/
/*------------------------ Nothing Below This Line --------------------------*/
