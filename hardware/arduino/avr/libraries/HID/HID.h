/*
  Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett

  Permission to use, copy, modify, and/or distribute this software for
  any purpose with or without fee is hereby granted, provided that the
  above copyright notice and this permission notice appear in all copies.

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
  WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
  BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
  OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
  WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
  ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
  SOFTWARE.
 */

#ifndef HID_h
#define HID_h

#include <stdint.h>
#include <Arduino.h>
#include "PluggableUSB.h"

#if defined(USBCON)

#define _USING_HID

// HID 'Driver'
// ------------
#define HID_GET_REPORT        0x01
#define HID_GET_IDLE          0x02
#define HID_GET_PROTOCOL      0x03
#define HID_SET_REPORT        0x09
#define HID_SET_IDLE          0x0A
#define HID_SET_PROTOCOL      0x0B

#define HID_HID_DESCRIPTOR_TYPE         0x21
#define HID_REPORT_DESCRIPTOR_TYPE      0x22
#define HID_PHYSICAL_DESCRIPTOR_TYPE    0x23

// HID subclass HID1.11 Page 8 4.2 Subclass
#define HID_SUBCLASS_NONE 0
#define HID_SUBCLASS_BOOT_INTERFACE 1

// HID Keyboard/Mouse bios compatible protocols HID1.11 Page 9 4.3 Protocols
#define HID_PROTOCOL_NONE 0
#define HID_PROTOCOL_KEYBOARD 1
#define HID_PROTOCOL_MOUSE 2

// Normal or bios protocol (Keyboard/Mouse) HID1.11 Page 54 7.2.5 Get_Protocol Request
// "protocol" variable is used for this purpose.
#define HID_BOOT_PROTOCOL	0
#define HID_REPORT_PROTOCOL	1

// HID Request Type HID1.11 Page 51 7.2.1 Get_Report Request
#define HID_REPORT_TYPE_INPUT   1
#define HID_REPORT_TYPE_OUTPUT  2
#define HID_REPORT_TYPE_FEATURE 3

typedef struct
{
  uint8_t len;      // 9
  uint8_t dtype;    // 0x21
  uint8_t addr;
  uint8_t versionL; // 0x101
  uint8_t versionH; // 0x101
  uint8_t country;
  uint8_t desctype; // 0x22 report
  uint8_t descLenL;
  uint8_t descLenH;
} HIDDescDescriptor;

typedef struct 
{
  InterfaceDescriptor hid;
  HIDDescDescriptor   desc;
  EndpointDescriptor  in;
} HIDDescriptor;

class HIDSubDescriptor {
public:
  HIDSubDescriptor *next = NULL;
  HIDSubDescriptor(const void *d, const uint16_t l) : data(d), length(l) { }

  const void* data;
  const uint16_t length;
};

class HID_ : public PluggableUSBModule
{
public:
  HID_(void);
  int begin(void);
  int SendReport(uint8_t id, const void* data, int len);
  void AppendDescriptor(HIDSubDescriptor* node);

protected:
  // Implementation of the PluggableUSBModule
  int getInterface(uint8_t* interfaceCount);
  int getDescriptor(USBSetup& setup);
  bool setup(USBSetup& setup);
  uint8_t getShortName(char* name);

private:
  uint8_t epType[1];

  HIDSubDescriptor* rootNode;
  uint16_t descriptorSize;

  uint8_t protocol;
  uint8_t idle;
};

// Replacement for global singleton.
// This function prevents static-initialization-order-fiasco
// https://isocpp.org/wiki/faq/ctors#static-init-order-on-first-use
HID_& HID();

#define D_HIDREPORT(length) { 9, 0x21, 0x01, 0x01, 0, 1, 0x22, lowByte(length), highByte(length) }

#endif // USBCON

#endif // HID_h
