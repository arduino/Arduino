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

/*-----------------------------------------------------------------------------+
| Include files                                                                |
|-----------------------------------------------------------------------------*/
#include <device.h>
#include <types.h>				// Basic Type declarations
#include <defMSP430USB.h>
#include "descriptors.h"
#include <usb.h>           //USB-specific Data Structures
#include <UsbIsr.h>
#include <string.h>

#include <UsbCdc.h>
//#include <UsbHid.h>
//#include <UsbHidReq.h>
/*----------------------------------------------------------------------------+
| External Variables                                                          |
+----------------------------------------------------------------------------*/
extern BYTE  bFunctionSuspended;

#ifdef __GNUC__
extern tDEVICE_REQUEST tSetupPacket  __asm__("0x2380");
extern tEDB0 tEndPoint0DescriptorBlock __asm__("0x0920");
extern tEDB tInputEndPointDescriptorBlock[7] __asm__("0x23C8");
extern tEDB tOutputEndPointDescriptorBlock[7] __asm__("0x2388");
#else
extern __no_init tEDB0 __data16 tEndPoint0DescriptorBlock;
extern __no_init tEDB __data16 tInputEndPointDescriptorBlock[];
extern __no_init tEDB __data16 tOutputEndPointDescriptorBlock[];
#endif

extern volatile BYTE bHostAsksUSBData;
extern volatile BYTE bTransferInProgress;
extern volatile BYTE bSecondUartTxDataCounter[];
extern volatile PBYTE pbSecondUartTxData;
extern BYTE bStatusAction;
extern WORD wUsbEventMask;
BOOL CdcToHostFromBuffer(BYTE);
BOOL CdcToBufferFromHost(BYTE);
BOOL CdcIsReceiveInProgress(BYTE);
BOOL HidToHostFromBuffer(BYTE);
BOOL HidToBufferFromHost(BYTE);
BOOL HidIsReceiveInProgress(BYTE);
extern WORD wUsbHidEventMask;
BOOL PHDCToHostFromBuffer(BYTE);
BOOL PHDCToBufferFromHost(BYTE);
BOOL PHDCIsReceiveInProgress(BYTE);
/*----------------------------------------------------------------------------+
| General Subroutines                                                         |
+----------------------------------------------------------------------------*/
#pragma vector=USB_UBM_VECTOR
__interrupt VOID iUsbInterruptHandler(VOID)
{
    BYTE bWakeUp = FALSE;
    //Check if the setup interrupt is pending.
    //We need to check it before other interrupts,
    //to work around that the Setup Int has lower priority then Input Endpoint 0
    if (USBIFG & SETUPIFG)
    {
        bWakeUp = SetupPacketInterruptHandler();  
        USBIFG &= ~SETUPIFG;    // clear the interrupt bit
    }   
    switch (__even_in_range(USBVECINT & 0x3f, USBVECINT_OUTPUT_ENDPOINT7))
    {
    case USBVECINT_NONE:
      break;
    case USBVECINT_PWR_DROP:
      __no_operation();
      break;
    case USBVECINT_PLL_LOCK:
      break;
    case USBVECINT_PLL_SIGNAL:
      break;
    case USBVECINT_PLL_RANGE:
      if (wUsbEventMask & kUSB_clockFaultEvent)
      {
          bWakeUp = USB_handleClockEvent();
      }
      break;
    case USBVECINT_PWR_VBUSOn:
      PWRVBUSonHandler();
      if (wUsbEventMask & kUSB_VbusOnEvent)
      {
          bWakeUp = USB_handleVbusOnEvent();
      }
      break;
    case USBVECINT_PWR_VBUSOff:
      PWRVBUSoffHandler();
      if (wUsbEventMask & kUSB_VbusOffEvent)
      {
          bWakeUp = USB_handleVbusOffEvent();
      }
      break;
    case USBVECINT_USB_TIMESTAMP:
      break;
    case USBVECINT_INPUT_ENDPOINT0:
      IEP0InterruptHandler();
      break;
    case USBVECINT_OUTPUT_ENDPOINT0:
      OEP0InterruptHandler();
      break;
    case USBVECINT_RSTR:
      USB_reset();
      if (wUsbEventMask & kUSB_UsbResetEvent)
      {
          bWakeUp = USB_handleResetEvent();
      }
      break;
    case USBVECINT_SUSR:
      USB_suspend();
      if (wUsbEventMask & kUSB_UsbSuspendEvent)
      {
          bWakeUp = USB_handleSuspendEvent();
      }
      break;
    case USBVECINT_RESR:
      USB_resume();
      if (wUsbEventMask & kUSB_UsbResumeEvent)
      {
          bWakeUp = USB_handleResumeEvent();
      }
      //-- after resume we will wake up! Independ what event handler says.
      bWakeUp = TRUE;
      break;
    case USBVECINT_SETUP_PACKET_RECEIVED:
      // NAK both IEP and OEP enpoints
      tEndPoint0DescriptorBlock.bIEPBCNT = EPBCNT_NAK;
      tEndPoint0DescriptorBlock.bOEPBCNT = EPBCNT_NAK;
      SetupPacketInterruptHandler();
      break;
    case USBVECINT_STPOW_PACKET_RECEIVED:
      break;
    case USBVECINT_INPUT_ENDPOINT1:
      break;
    case USBVECINT_INPUT_ENDPOINT2:
      //send saved bytes from buffer...
      bWakeUp = CdcToHostFromBuffer(CDC0_INTFNUM);
            break;
    case USBVECINT_INPUT_ENDPOINT3:
      break;
    case USBVECINT_INPUT_ENDPOINT4:
      break;
    case USBVECINT_INPUT_ENDPOINT5:
      break;
    case USBVECINT_INPUT_ENDPOINT6:
      break;
    case USBVECINT_INPUT_ENDPOINT7:
      break;
    case USBVECINT_OUTPUT_ENDPOINT1:
      break;
    case USBVECINT_OUTPUT_ENDPOINT2:
      //call callback function if no receive operation is underway
      if (!CdcIsReceiveInProgress(CDC0_INTFNUM) && USBCDC_bytesInUSBBuffer(CDC0_INTFNUM))
      {
          if (wUsbEventMask & kUSB_dataReceivedEvent)
          {
              bWakeUp = USBCDC_handleDataReceived(CDC0_INTFNUM);
          }
      }
      else
      {
          //complete receive opereation - copy data to user buffer
          bWakeUp = CdcToBufferFromHost(CDC0_INTFNUM);
      }
            break;
    case USBVECINT_OUTPUT_ENDPOINT3:
      break;
    case USBVECINT_OUTPUT_ENDPOINT4:
      break;
    case USBVECINT_OUTPUT_ENDPOINT5:
      break;
    case USBVECINT_OUTPUT_ENDPOINT6:
      break;
    case USBVECINT_OUTPUT_ENDPOINT7:
      break;
    default:
      break;
    }
    if (bWakeUp)
    {
    	 __bic_SR_register_on_exit(LPM3_bits);   // Exit LPM0-3
    	 __no_operation();                       // Required for debugger
    }
}

/*----------------------------------------------------------------------------+
| Interrupt Sub-routines                                                      |
+----------------------------------------------------------------------------*/
BYTE SetupPacketInterruptHandler(VOID)
{
    BYTE bTemp;
    BYTE bWakeUp = FALSE;
    USBCTL |= FRSTE;      // Function Reset Connection Enable - set enable after first setup packet was received
    usbProcessNewSetupPacket:
    // copy the MSB of bmRequestType to DIR bit of USBCTL
    if((tSetupPacket.bmRequestType & USB_REQ_TYPE_INPUT) == USB_REQ_TYPE_INPUT)
    {
    	USBCTL |= DIR;
    }
    else
    {
    	USBCTL &= ~DIR;
    }
    bStatusAction = STATUS_ACTION_NOTHING;
    // clear out return data buffer
    for(bTemp=0; bTemp<USB_RETURN_DATA_LENGTH; bTemp++)
    {
    	abUsbRequestReturnData[bTemp] = 0x00;
    }
    // decode and process the request
    bWakeUp = usbDecodeAndProcessUsbRequest();
    // check if there is another setup packet pending
    // if it is, abandon current one by NAKing both data endpoint 0
    if((USBIFG & STPOWIFG) != 0x00)
    {
    	USBIFG &= ~(STPOWIFG | SETUPIFG);
    	goto usbProcessNewSetupPacket;
    }
    return bWakeUp;
}

//----------------------------------------------------------------------------
VOID PWRVBUSoffHandler(VOID)
{
	volatile unsigned int i;
    for (i =0; i < USB_MCLK_FREQ/1000*1/10; i++); // 1ms delay
    if (!(USBPWRCTL & USBBGVBV))
    {
    	USBKEYPID   =    0x9628;        // set KEY and PID to 0x9628 -> access to configuration registers enabled
        bEnumerationStatus = 0x00;      // device is not enumerated
    	bFunctionSuspended = FALSE;     // device is not suspended
    	USBCNF     =    0;              // disable USB module
    	USBPLLCTL  &=  ~UPLLEN;         // disable PLL
    	USBPWRCTL &= ~(VBOFFIE + VBOFFIFG + SLDOEN);          // disable interrupt VBUSoff
    	USBKEYPID   =    0x9600;        // access to configuration registers disabled
    }
}

//----------------------------------------------------------------------------
VOID PWRVBUSonHandler(VOID)
{
    volatile unsigned int i;
    for (i =0; i < USB_MCLK_FREQ/1000*1/10; i++);          // waiting till voltage will be stable (1ms delay)
    USBKEYPID =  0x9628;                // set KEY and PID to 0x9628 -> access to configuration registers enabled
    USBPWRCTL |= VBOFFIE;               // enable interrupt VBUSoff
    USBPWRCTL &= ~ (VBONIFG + VBOFFIFG);             // clean int flag (bouncing)
    USBKEYPID =  0x9600;                // access to configuration registers disabled
}

//----------------------------------------------------------------------------
VOID IEP0InterruptHandler(VOID)
{
    USBCTL |= FRSTE;                              // Function Reset Connection Enable
    tEndPoint0DescriptorBlock.bOEPBCNT = 0x00;     
    if(bStatusAction == STATUS_ACTION_DATA_IN)
    {
	    usbSendNextPacketOnIEP0();
    }
    else
    {
        tEndPoint0DescriptorBlock.bIEPCNFG |= EPCNF_STALL; // no more data
    }
}

//----------------------------------------------------------------------------
BYTE OEP0InterruptHandler(VOID)
{
    BYTE bWakeUp = FALSE;
    USBCTL |= FRSTE;                              // Function Reset Connection Enable
    tEndPoint0DescriptorBlock.bIEPBCNT = 0x00;    
    if(bStatusAction == STATUS_ACTION_DATA_OUT)
    {
        usbReceiveNextPacketOnOEP0();
        if(bStatusAction == STATUS_ACTION_NOTHING)
        {
#           ifdef _CDC_
                if(tSetupPacket.bRequest == USB_CDC_SET_LINE_CODING)
                {
                    bWakeUp = Handler_SetLineCoding();
                }
#          endif
#ifdef _HID_
				if (tSetupPacket.bRequest == USB_REQ_SET_REPORT) {
					bWakeUp = USBHID_handleSetReportDataAvailable(tSetupPacket.wIndex);
				}
#endif
      	}
    }
    else
    {
	    tEndPoint0DescriptorBlock.bOEPCNFG |= EPCNF_STALL; // no more data
    }
    return (bWakeUp);
}



/*----------------------------------------------------------------------------+
| End of source file                                                          |
+----------------------------------------------------------------------------*/
/*------------------------ Nothing Below This Line --------------------------*/
