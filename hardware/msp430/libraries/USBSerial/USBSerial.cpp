/*
 (Ported from Arduino to Energia)

USBSerial.cpp (formerly NewSoftSerial.cpp) - 
 Multi-instance USB serial library for Arduino/Wiring
  
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */


// 
// Includes
// 
//#include <avr/interrupt.h>
//#include <avr/pgmspace.h>
//#include "Arduino.h"
#include "Energia.h"
#include "USBSerial.h"

#include "descriptors.h"

#include "device.h"
#include "types.h"               //Basic Type declarations
#include "usb.h"                 //USB-specific functions

#include "HAL_UCS.h"
//#include "HAL_PMM.h"

#include "UsbCdc.h"
#include "usbConstructs.h"


//
// Statics
//


//
// Private methods
//

volatile BYTE bCDCDataReceived_event = FALSE;   //Flag set by event handler to indicate data has been received into USB buffer

#define BUFFER_SIZE 256
char nl[2] = "\n";
char dataBuffer[BUFFER_SIZE] = "";
WORD count;                    


//
// Interrupt handling
//

/* static */
void USBSerial::handle_interrupt()
{
}

//
// Constructor
//
USBSerial::USBSerial(uint16_t port)
{
}

//
// Destructor
//
USBSerial::~USBSerial()
{
  end();
}


//
// Public methods
//

void USBSerial::begin()
{
    __disable_interrupt();                           //Enable interrupts globally
    //Initialization of clock module
    if (USB_PLL_XT == 2){
		#if defined (__MSP430F552x) || defined (__MSP430F550x)
			P5SEL |= 0x0C;                                      //enable XT2 pins for F5529
		#elif defined (__MSP430F563x_F663x)
			P7SEL |= 0x0C;
		#endif

        XT2_Start(XT2DRIVE_0);                                          //Start the "USB crystal"
    } 
	else {
		#if defined (__MSP430F552x) || defined (__MSP430F550x)
			P5SEL |= 0x10;                                      //enable XT1 pins
		#endif

        XT1_Start(XT1DRIVE_0);                                          //Start the "USB crystal"
    }
	
    USB_init();                 //Init USB

    //Enable various USB event handling routines
    USB_setEnabledEvents(kUSB_allUsbEvents);


    // See if we're already attached physically to USB, and if so, connect to it
    // Normally applications don't invoke the event handlers, but this is an exception.
    if (USB_connectionInfo() & kUSB_vbusPresent)
      USB_handleVbusOnEvent();
    __enable_interrupt();                           //Enable interrupts globally
}

void USBSerial::end(uint8_t disableXTAL)
{
  USB_disable();
  if (disableXTAL){
    if (USB_PLL_XT == 2){
		XT2_Stop();
    } else {
		XT1_Stop();
    }
  }
}

void USBSerial::end()
{
	USB_disable();
	if (USB_PLL_XT == 2){
		XT2_Stop();
	} else {
		XT1_Stop();
	}
}


// Read data from buffer
int USBSerial::read()
{
  WORD count; 
  BYTE dataBuffer = 0;  

  // Read from "head"
  count = cdcReceiveDataInBuffer((BYTE*)&dataBuffer,
    1,
    CDC0_INTFNUM);                                //Count has the number of bytes received into
                                                  //dataBuffer
  // Empty buffer?
  if (count == 0){
    bCDCDataReceived_event = FALSE;
    return -1;
	}
  
  return (int)dataBuffer;
}

int USBSerial::available()
{
  if ( (USB_connectionState() == ST_ENUM_ACTIVE) && (USBCDC_bytesInUSBBuffer(CDC0_INTFNUM) > 0) ) return 1;
  return 0;
}

size_t USBSerial::write(uint8_t b)
{

  if (cdcSendDataWaitTilDone((BYTE*)&b,1,CDC0_INTFNUM,0)){  	//send char to the Host
    return 0;   // could not write
  }
  return 1;
}


size_t USBSerial::write(const uint8_t *buffer, size_t size)
{

  if (cdcSendDataWaitTilDone((BYTE*)buffer,size,CDC0_INTFNUM,0)){  	//send char to the Host
    return 0;   // could not write
  }
  return 1;
}

void USBSerial::flush()
{
  while (USBCDC_bytesInUSBBuffer(CDC0_INTFNUM) > 0);            // wait till all send
}

int USBSerial::peek()
{

  // Empty buffer?
  if (USBCDC_bytesInUSBBuffer(CDC0_INTFNUM) == 0)
    return -1;

  // Read from "head"
  return USBCDC_bytesInUSBBuffer(CDC0_INTFNUM);
}

/*  
 * ======== UNMI_ISR ========
 */
#ifndef __GNUC__
#pragma vector = UNMI_VECTOR
__interrupt
#else
__attribute__((interrupt(UNMI_VECTOR)))
#endif
//UNMI interrupt service routine
static void UNMI_ISR(void)
{
    switch (__even_in_range(SYSUNIV, SYSUNIV_BUSIFG ))
    {
        case SYSUNIV_NONE:
            __no_operation();
            break;
        case SYSUNIV_NMIIFG:
            __no_operation();
            break;
        case SYSUNIV_OFIFG:
            UCSCTL7 &= ~(DCOFFG + XT1LFOFFG + XT2OFFG); //Clear OSC flaut Flags fault flags
            SFRIFG1 &= ~OFIFG;                          //Clear OFIFG fault flag
            break;
        case SYSUNIV_ACCVIFG:
            __no_operation();
            break;
        case SYSUNIV_BUSIFG:
            SYSBERRIV = 0;                                      //clear bus error flag
            USB_disable();                                      //Disable
    }
}
