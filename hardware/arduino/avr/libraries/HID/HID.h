/*
  HID.h

  Copyright (c) 2015, Arduino LLC
  Original code (pre-library): Copyright (c) 2011, Peter Barrett

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

class HIDDescriptorListNode {
public:
  HIDDescriptorListNode *next = NULL;
  HIDDescriptorListNode(const void *d, const uint16_t l) : data(d), length(l) { }

  const void* data;
  uint16_t length;
};

class HID_ : public PUSBListNode
{
public:
  HID_(void);
  int begin(void);
  void SendReport(uint8_t id, const void* data, int len);
  void AppendDescriptor(HIDDescriptorListNode* node);

protected:
  // Implementation of the PUSBListNode
  int getInterface(uint8_t* interfaceNum);
  int getDescriptor(int8_t t);
  bool setup(USBSetup& setup, uint8_t i);

private:
  HIDDescriptor hidInterface;
  uint8_t epType[1];

  HIDDescriptorListNode* rootNode;
  uint16_t sizeof_hidReportDescriptor;
  uint8_t modules_count;

  uint8_t protocol;
  uint8_t idle;
};

#define D_HIDREPORT(length) { 9, 0x21, 0x01, 0x01, 0, 1, 0x22, lowByte(length), highByte(length) }

#define WEAK __attribute__ ((weak))

#endif

#endif
