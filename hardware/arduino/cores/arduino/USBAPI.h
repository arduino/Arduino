

#ifndef __USBAPI__
#define __USBAPI__

#if defined(USBCON)

//================================================================================
//================================================================================
//	USB

class USBDevice_
{
public:
	USBDevice_();
	bool configured();
	
	void attach();
	void detach();	// Serial port goes down too...
	void poll();
};
extern USBDevice_ USBDevice;

//================================================================================
//================================================================================
//	Serial over CDC (Serial1 is the physical port)

class Serial_ : public Stream
{
private:
	ring_buffer *_cdc_rx_buffer;
public:
	void begin(uint16_t baud_count);
	void end(void);
	
	virtual int available(void);
	virtual void accept(void);
	virtual int peek(void);
	virtual int read(void);
	virtual void flush(void);
	virtual size_t write(uint8_t);
	using Print::write; // pull in write(str) and write(buf, size) from Print
	operator bool();
};
extern Serial_ Serial;

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
	bool isPressed(uint8_t b = MOUSE_LEFT);	// check LEFT by default
};
extern Mouse_ Mouse;

//================================================================================
//================================================================================
//	Keyboard

// USB HID based keycodes
// as taken from: http://www.usb.org/developers/devclass_docs/Hut1_11.pdf
#define KEYCODE_LEFT_CTRL		0xE0
#define KEYCODE_LEFT_SHIFT		0xE1
#define KEYCODE_LEFT_ALT		0xE2
#define KEYCODE_LEFT_GUI		0xE3
#define KEYCODE_RIGHT_CTRL		0xE4
#define KEYCODE_RIGHT_SHIFT		0xE5
#define KEYCODE_RIGHT_ALT		0xE6
#define KEYCODE_RIGHT_GUI		0xE7

#define KEYCODE_UP_ARROW		0x52
#define KEYCODE_DOWN_ARROW		0x51
#define KEYCODE_LEFT_ARROW		0x50
#define KEYCODE_RIGHT_ARROW		0x4F
#define KEYCODE_BACKSPACE		0x2A
#define KEYCODE_TAB				0x2B
#define KEYCODE_RETURN			0x28
#define KEYCODE_ESC				0x29
#define KEYCODE_INSERT			0x49
#define KEYCODE_DELETE			0xD4
#define KEYCODE_PAGE_UP			0x4B
#define KEYCODE_PAGE_DOWN		0x4E
#define KEYCODE_HOME			0x4A
#define KEYCODE_END				0x4D
#define KEYCODE_CAPS_LOCK		0x39
#define KEYCODE_F1				0x3A
#define KEYCODE_F2				0x3B
#define KEYCODE_F3				0x3C
#define KEYCODE_F4				0x3D
#define KEYCODE_F5				0x3E
#define KEYCODE_F6				0x3F
#define KEYCODE_F7				0x40
#define KEYCODE_F8				0x41
#define KEYCODE_F9				0x42
#define KEYCODE_F10				0x43
#define KEYCODE_F11				0x44
#define KEYCODE_F12				0x45

#define KEYCODE_ENTER				KEYCODE_RETURN
#define KEYCODE_SPACEBAR			0x2C
#define	KEYCODE_PRINT_SCREEN		0x46
#define KEYCODE_SCROLL_LOCK			0x47
#define KEYCODE_PAUSE				0x48
#define KEYCODE_KEYPAD_NUM_LOCK		0x53
#define KEYCODE_KEYPAD_RETURN		0x58
#define KEYCODE_KEYPAD_ENTER		KEYCODE_KEYPAD_RETURN
#define KEYCODE_KEYPAD_END			0x59
#define KEYCODE_KEYPAD_DOWN_ARROW	0x5A
#define KEYCODE_KEYPAD_PAGE_DOWN	0x5B
#define KEYCODE_KEYPAD_LEFT_ARROW	0x5C
#define KEYCODE_KEYPAD_RIGHT_ARROW	0x5E
#define KEYCODE_KEYPAD_HOME			0x5F
#define KEYCODE_KEYPAD_UP_ARROW		0x60
#define KEYCODE_KEYPAD_PAGE_UP		0x61
#define KEYCODE_KEYPAD_INSERT		0x62
#define KEYCODE_KEYPAD_DELETE		0x63
#define KEYCODE_APPLICATION			0x65
#define KEYCODE_POWER				0x66
#define KEYCODE_F13					0x68
#define KEYCODE_F14					0x69
#define KEYCODE_F15					0x6A
#define KEYCODE_F16					0x6B
#define KEYCODE_F17					0x6C
#define KEYCODE_F18					0x6D
#define KEYCODE_F19					0x6E
#define KEYCODE_F20					0x6F
#define KEYCODE_F21					0x70
#define KEYCODE_F22					0x71
#define KEYCODE_F23					0x72
#define KEYCODE_F24					0x73
#define KEYCODE_EXECUTE				0x74
#define KEYCODE_HELP				0x75
#define KEYCODE_MENU				0x76
#define KEYCODE_SELECT				0x77
#define KEYCODE_STOP				0x78
#define KEYCODE_AGAIN				0x79
#define KEYCODE_UNDO				0x7A
#define KEYCODE_CUT					0x7B
#define KEYCODE_COPY				0x7C
#define KEYCODE_PASTE				0x7D
#define KEYCODE_FIND				0x7E
#define KEYCODE_MUTE				0x7F
#define KEYCODE_VOLUME_UP			0x80
#define KEYCODE_VOLUME_DOWN			0x81
#define KEYCODE_CANCEL				0x9B
#define KEYCODE_CLEAR				0x9C
#define KEYCODE_PRIOR				0x9D
#define KEYCODE_KEYPAD_TAB			0xBA
#define KEYCODE_KEYPAD_BACKSPACE	0xBB

// ASCII based keys
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

#define KEY_ENTER			KEY_RETURN

//	Low level key report: up to 6 keys and shift, ctrl etc at once
#define KEYREPORT_KEYCOUNT	0x06
typedef struct
{
	uint8_t modifiers;
	uint8_t reserved;
	uint8_t keys[KEYREPORT_KEYCOUNT];
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
	virtual size_t pressKeycode(uint8_t k, uint8_t send);
	virtual size_t releaseKeycode(uint8_t k, uint8_t send);
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
void	HID_SendReport(uint8_t id, const void* data, int len);

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
int		CDC_GetDescriptor(int i);
bool	CDC_Setup(Setup& setup);

//================================================================================
//================================================================================

#define TRANSFER_PGM		0x80
#define TRANSFER_RELEASE	0x40
#define TRANSFER_ZERO		0x20

int USB_SendControl(uint8_t flags, const void* d, int len);
int USB_RecvControl(void* d, int len);

uint8_t	USB_Available(uint8_t ep);
int USB_Send(uint8_t ep, const void* data, int len);	// blocking
int USB_Recv(uint8_t ep, void* data, int len);		// non-blocking
int USB_Recv(uint8_t ep);							// non-blocking
void USB_Flush(uint8_t ep);

#endif

#endif /* if defined(USBCON) */