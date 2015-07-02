#ifndef COMPLETEHID_h
#define COMPLETEHID_h

#if 0 //defined(_USING_HID)

#error "Can only attach one submodule to HID module"

#else

#define _USING_HID

#include "HID.h"
#include "HIDTables.h"

extern HID_ HID;

//================================================================================
//================================================================================
//  Mouse

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
  void moveAbsolute(uint16_t x, uint16_t y);
  void press(uint8_t b = MOUSE_LEFT);   // press LEFT by default
  void release(uint8_t b = MOUSE_LEFT); // release LEFT by default
  bool isPressed(uint8_t b = MOUSE_LEFT); // check LEFT by default
};
extern Mouse_ Mouse;

//================================================================================
//================================================================================
//  Keyboard

#define KEY_LEFT_CTRL   0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT    0x82
#define KEY_LEFT_GUI    0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT   0x86
#define KEY_RIGHT_GUI   0x87

#define KEY_UP_ARROW    0xDA
#define KEY_DOWN_ARROW    0xD9
#define KEY_LEFT_ARROW    0xD8
#define KEY_RIGHT_ARROW   0xD7
#define KEY_BACKSPACE   0xB2
#define KEY_TAB       0xB3
#define KEY_RETURN      0xB0
#define KEY_ESC       0xB1
#define KEY_INSERT      0xD1
#define KEY_DELETE      0xD4
#define KEY_PAGE_UP     0xD3
#define KEY_PAGE_DOWN   0xD6
#define KEY_HOME      0xD2
#define KEY_END       0xD5
#define KEY_CAPS_LOCK   0xC1
#define KEY_F1        0xC2
#define KEY_F2        0xC3
#define KEY_F3        0xC4
#define KEY_F4        0xC5
#define KEY_F5        0xC6
#define KEY_F6        0xC7
#define KEY_F7        0xC8
#define KEY_F8        0xC9
#define KEY_F9        0xCA
#define KEY_F10       0xCB
#define KEY_F11       0xCC
#define KEY_F12       0xCD

//  Low level key report: up to 6 keys and shift, ctrl etc at once
#define KEYREPORT_KEYCOUNT  0x06
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
  size_t write(uint8_t k);
  size_t press(uint8_t k);
  size_t release(uint8_t k);
  size_t writeKeycode(uint8_t k);
  size_t pressKeycode(uint8_t k);
  size_t releaseKeycode(uint8_t k);
  size_t addKeycodeToReport(uint8_t k);
  size_t removeKeycodeFromReport(uint8_t k);
  void releaseAll(void);
  size_t systemControl(uint8_t k);
  size_t consumerControl(uint8_t k);
};
extern Keyboard_ Keyboard;

// System Control values for Keyboard_::systemControl()
//  these defines come from the HID usage table "Generic Desktop Page (0x01)"
//  in the USB standard document "HID Usage Tables" (HUT1_12v2.pdf)
//  Currently this list contains only OSC (one shot control) values,
//  the implementation of systemControl will have to be changed when
//  adding OOC or RTC values.
#define SYSTEM_CONTROL_POWER_DOWN              1
#define SYSTEM_CONTROL_SLEEP                   2
#define SYSTEM_CONTROL_WAKEUP                  3
#define SYSTEM_CONTROL_COLD_RESTART            4
#define SYSTEM_CONTROL_WARM_RESTART            5
#define SYSTEM_CONTROL_DOCK                    6
#define SYSTEM_CONTROL_UNDOCK                  7
#define SYSTEM_CONTROL_SPEAKER_MUTE            8
#define SYSTEM_CONTROL_HIBERNATE               9
#define SYSTEM_CONTROL_DISPLAY_INVERT         10
#define SYSTEM_CONTROL_DISPLAY_INTERNAL       11
#define SYSTEM_CONTROL_DISPLAY_EXTERNAL       12
#define SYSTEM_CONTROL_DISPLAY_BOTH           13
#define SYSTEM_CONTROL_DISPLAY_DUAL           14
#define SYSTEM_CONTROL_DISPLAY_TOGGLE_INT_EXT 15
#define SYSTEM_CONTROL_DISPLAY_SWAP           16



// Consumer Control values for Keyboard_::systemControl()
//  these defines come from the HID usage table "Consumer Device Page (0x0c)"
//  in the USB standard document "HID Usage Tables" (HUT1_12v2.pdf)
//  Currently this list contains only OSC (one shot control) values,
//  the implementation of systemControl will have to be changed when
//  adding OOC or RTC values.

#define CONSUMER_CONTROL_VOLUME_MUTE        1
#define CONSUMER_CONTROL_VOLUME_UP          2
#define CONSUMER_CONTROL_VOLUME_DOWN        3
#define CONSUMER_CONTROL_PLAY_PAUSE         4
#define CONSUMER_CONTROL_STOP               5
#define CONSUMER_CONTROL_PREV_TRACK         6
#define CONSUMER_CONTROL_NEXT_TRACK         7
#define CONSUMER_CONTROL_EJECT              8

#endif
#endif