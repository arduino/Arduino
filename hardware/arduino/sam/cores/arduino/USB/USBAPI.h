/*
  Copyright (c) 2012 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef __USBAPI__
#define __USBAPI__

#if defined __cplusplus

#include "RingBuffer.h"

//================================================================================
//================================================================================
//	USB

class USBDevice_
{
public:
	USBDevice_();
	bool configured();

	bool attach();
	bool detach();	// Serial port goes down too...
	void poll();
};
extern USBDevice_ USBDevice;

//================================================================================
//================================================================================
//	Serial over CDC (Serial1 is the physical port)

class Serial_ : public Stream
{
private:
	RingBuffer *_cdc_rx_buffer;
public:
	void begin(uint32_t baud_count);
	void begin(uint32_t baud_count, uint8_t config);
	void end(void);

	virtual int available(void);
	virtual void accept(void);
	virtual int peek(void);
	virtual int read(void);
	virtual void flush(void);
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *buffer, size_t size);
	using Print::write; // pull in write(str) from Print
	operator bool();

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
extern Serial_ SerialUSB;


//Gurbrinder: Midi Interface
//================================================================================
//================================================================================
//	MIDI USB class 

typedef struct 
{
	uint8_t header;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
}midiEventPacket_t;

class MIDI_
{
private:
	RingBuffer *_midi_rx_buffer;
public:
	void begin();

	virtual uint32_t available(void);
	virtual void accept(void);
	virtual midiEventPacket_t read(void);
	virtual void flush(void);
	virtual void sendMIDI(midiEventPacket_t event);
	virtual size_t write(const uint8_t *buffer, size_t size);
	operator bool();
};
extern MIDI_ MidiUSB;

//================================================================================
//================================================================================
//	Mouse

#define MOUSE_LEFT 1
#define MOUSE_RIGHT 2
#define MOUSE_MIDDLE 4
#define MOUSE_ALL (MOUSE_LEFT | MOUSE_RIGHT | MOUSE_MIDDLE)

class Mouse_
{
private:
	uint8_t _buttons;
	void buttons(uint8_t b);
public:
	Mouse_(void);
	void begin(void);
	void end(void);
	void click(uint8_t b = MOUSE_LEFT);
	void move(signed char x, signed char y, signed char wheel = 0);
	void press(uint8_t b = MOUSE_LEFT);		// press LEFT by default
	void release(uint8_t b = MOUSE_LEFT);	// release LEFT by default
	bool isPressed(uint8_t b = MOUSE_ALL);	// check all buttons by default
};
extern Mouse_ Mouse;

//================================================================================
//================================================================================
//	Keyboard

#define KEY_LEFT_CTRL		0x80
#define KEY_LEFT_SHIFT		0x81
#define KEY_LEFT_ALT		0x82
#define KEY_LEFT_GUI		0x83
#define KEY_RIGHT_CTRL		0x84
#define KEY_RIGHT_SHIFT		0x85
#define KEY_RIGHT_ALT		0x86
#define KEY_RIGHT_GUI		0x87

#define KEY_UP_ARROW		0xDA
#define KEY_DOWN_ARROW		0xD9
#define KEY_LEFT_ARROW		0xD8
#define KEY_RIGHT_ARROW		0xD7
#define KEY_BACKSPACE		0xB2
#define KEY_TAB				0xB3
#define KEY_RETURN			0xB0
#define KEY_ESC				0xB1
#define KEY_INSERT			0xD1
#define KEY_DELETE			0xD4
#define KEY_PAGE_UP			0xD3
#define KEY_PAGE_DOWN		0xD6
#define KEY_HOME			0xD2
#define KEY_END				0xD5
#define KEY_CAPS_LOCK		0xC1
#define KEY_F1				0xC2
#define KEY_F2				0xC3
#define KEY_F3				0xC4
#define KEY_F4				0xC5
#define KEY_F5				0xC6
#define KEY_F6				0xC7
#define KEY_F7				0xC8
#define KEY_F8				0xC9
#define KEY_F9				0xCA
#define KEY_F10				0xCB
#define KEY_F11				0xCC
#define KEY_F12				0xCD

//	Low level key report: up to 6 keys and shift, ctrl etc at once
typedef struct
{
	uint8_t modifiers;
	uint8_t reserved;
	uint8_t keys[6];
} KeyReport;

class Keyboard_ : public Print
{
private:
	KeyReport _keyReport;
	void sendReport(KeyReport* keys);
public:
	Keyboard_(void);
	void begin(void);
	void end(void);
	virtual size_t write(uint8_t k);
	virtual size_t press(uint8_t k);
	virtual size_t release(uint8_t k);
	virtual void releaseAll(void);
};
extern Keyboard_ Keyboard;

//================================================================================
//================================================================================
//	Low level API

typedef struct
{
	uint8_t bmRequestType;
	uint8_t bRequest;
	uint8_t wValueL;
	uint8_t wValueH;
	uint16_t wIndex;
	uint16_t wLength;
} Setup;

//================================================================================
//================================================================================
//	HID 'Driver'

int		HID_GetInterface(uint8_t* interfaceNum);
int		HID_GetDescriptor(int i);
bool	HID_Setup(Setup& setup);
void	HID_SendReport(uint8_t id, const void* data, uint32_t len);

//================================================================================
//================================================================================
//	MSC 'Driver'

int		MSC_GetInterface(uint8_t* interfaceNum);
int		MSC_GetDescriptor(int i);
bool	MSC_Setup(Setup& setup);
bool	MSC_Data(uint8_t rx,uint8_t tx);

//================================================================================
//================================================================================
//	CSC 'Driver'

int		CDC_GetInterface(uint8_t* interfaceNum);
int		CDC_GetOtherInterface(uint8_t* interfaceNum);
int		CDC_GetDescriptor(int i);
bool	CDC_Setup(Setup& setup);

//================================================================================
//================================================================================
//	MIDI 'Driver'

int		MIDI_GetInterface(uint8_t* interfaceNum);
int		MIDI_GetOtherInterface(uint8_t* interfaceNum);
int		MIDI_GetDescriptor(int i);
bool	MIDI_Setup(Setup& setup);

//================================================================================
//================================================================================

#define TRANSFER_RELEASE	0x40
#define TRANSFER_ZERO		0x20

void USBD_InitControl(int end);
int USBD_SendControl(uint8_t flags, const void* d, uint32_t len);
int USBD_RecvControl(void* d, uint32_t len);
int USBD_SendInterfaces(void);
bool USBD_ClassInterfaceRequest(Setup& setup);


uint32_t USBD_Available(uint32_t ep);
uint32_t USBD_SendSpace(uint32_t ep);
uint32_t USBD_Send(uint32_t ep, const void* d, uint32_t len);
uint32_t USBD_Recv(uint32_t ep, void* data, uint32_t len);		// non-blocking
uint32_t USBD_Recv(uint32_t ep);							// non-blocking
void USBD_Flush(uint32_t ep);
uint32_t USBD_Connected(void);

#endif
#endif
