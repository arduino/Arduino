/*
  USBAPI.h
  Copyright (c) 2005-2014 Arduino.  All right reserved.

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

#ifndef __USBAPI__
#define __USBAPI__

#include <inttypes.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <util/delay.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

#include "Arduino.h"

// This definitions is usefull if you want to reduce the EP_SIZE to 16
// at the moment only 64 and 16 as EP_SIZE for all EPs are supported except the control endpoint
#ifndef USB_EP_SIZE
#define USB_EP_SIZE 64
#endif

#if defined(USBCON)

#include "USBDesc.h"
#include "USBCore.h"

//================================================================================
//================================================================================
//	USB

#define EP_TYPE_CONTROL				(0x00)
#define EP_TYPE_BULK_IN				((1<<EPTYPE1) | (1<<EPDIR))
#define EP_TYPE_BULK_OUT			(1<<EPTYPE1)
#define EP_TYPE_INTERRUPT_IN		((1<<EPTYPE1) | (1<<EPTYPE0) | (1<<EPDIR))
#define EP_TYPE_INTERRUPT_OUT		((1<<EPTYPE1) | (1<<EPTYPE0))
#define EP_TYPE_ISOCHRONOUS_IN		((1<<EPTYPE0) | (1<<EPDIR))
#define EP_TYPE_ISOCHRONOUS_OUT		(1<<EPTYPE0)

class USBDevice_
{
public:
	USBDevice_();
	bool configured();

	void attach();
	void detach();	// Serial port goes down too...
	void poll();
	bool wakeupHost(); // returns false, when wakeup cannot be processed
};
extern USBDevice_ USBDevice;

//================================================================================
//================================================================================
//	Serial over CDC (Serial1 is the physical port)

struct ring_buffer;

#ifndef SERIAL_BUFFER_SIZE
#if ((RAMEND - RAMSTART) < 1023)
#define SERIAL_BUFFER_SIZE 16
#else
#define SERIAL_BUFFER_SIZE 64
#endif
#endif
#if (SERIAL_BUFFER_SIZE>256)
#error Please lower the CDC Buffer size
#endif

class Serial_ : public Stream
{
private:
	int peek_buffer;
public:
	Serial_() { peek_buffer = -1; };
	void begin(unsigned long);
	void begin(unsigned long, uint8_t);
	void end(void);

	virtual int available(void);
	virtual int peek(void);
	virtual int read(void);
	int availableForWrite(void);
	virtual void flush(void);
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t*, size_t);
	using Print::write; // pull in write(str) and write(buf, size) from Print
	operator bool();

	volatile uint8_t _rx_buffer_head;
	volatile uint8_t _rx_buffer_tail;
	unsigned char _rx_buffer[SERIAL_BUFFER_SIZE];

	// This method allows processing "SEND_BREAK" requests sent by
	// the USB host. Those requests indicate that the host wants to
	// send a BREAK signal and are accompanied by a single uint16_t
	// value, specifying the duration of the break. The value 0
	// means to end any current break, while the value 0xffff means
	// to start an indefinite break.
	// readBreak() will return the value of the most recent break
	// request, but will return it at most once, returning -1 when
	// readBreak() is called again (until another break request is
	// received, which is again returned once).
	// This also mean that if two break requests are received
	// without readBreak() being called in between, the value of the
	// first request is lost.
	// Note that the value returned is a long, so it can return
	// 0-0xffff as well as -1.
	int32_t readBreak();

	// These return the settings specified by the USB host for the
	// serial port. These aren't really used, but are offered here
	// in case a sketch wants to act on these settings.
	uint32_t baud();
	uint8_t stopbits();
	uint8_t paritytype();
	uint8_t numbits();
	bool dtr();
	bool rts();
	enum {
		ONE_STOP_BIT = 0,
		ONE_AND_HALF_STOP_BIT = 1,
		TWO_STOP_BITS = 2,
	};
	enum {
		NO_PARITY = 0,
		ODD_PARITY = 1,
		EVEN_PARITY = 2,
		MARK_PARITY = 3,
		SPACE_PARITY = 4,
	};

};
extern Serial_ Serial;

#define HAVE_CDCSERIAL

//================================================================================
//================================================================================
//  Low level API

typedef struct
{
	uint8_t bmRequestType;
	uint8_t bRequest;
	uint8_t wValueL;
	uint8_t wValueH;
	uint16_t wIndex;
	uint16_t wLength;
} USBSetup;

//================================================================================
//================================================================================
//	MSC 'Driver'

int		MSC_GetInterface(uint8_t* interfaceNum);
int		MSC_GetDescriptor(int i);
bool	MSC_Setup(USBSetup& setup);
bool	MSC_Data(uint8_t rx,uint8_t tx);

//================================================================================
//================================================================================
//	CSC 'Driver'

int		CDC_GetInterface(uint8_t* interfaceNum);
int		CDC_GetDescriptor(int i);
bool	CDC_Setup(USBSetup& setup);

//================================================================================
//================================================================================

#define TRANSFER_PGM		0x80
#define TRANSFER_RELEASE	0x40
#define TRANSFER_ZERO		0x20

int USB_SendControl(uint8_t flags, const void* d, int len);
int USB_RecvControl(void* d, int len);
int USB_RecvControlLong(void* d, int len);

uint8_t	USB_Available(uint8_t ep);
uint8_t USB_SendSpace(uint8_t ep);
int USB_Send(uint8_t ep, const void* data, int len);	// blocking
int USB_Recv(uint8_t ep, void* data, int len);		// non-blocking
int USB_Recv(uint8_t ep);							// non-blocking
void USB_Flush(uint8_t ep);

#endif

#endif /* if defined(USBCON) */
