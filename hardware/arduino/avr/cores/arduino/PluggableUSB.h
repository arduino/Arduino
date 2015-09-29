/*
  PluggableUSB.h
  Copyright (c) 2015 Arduino LLC

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

#ifndef PUSB_h
#define PUSB_h

#include "USBAPI.h"
#include <stdint.h>

#if defined(USBCON)

class PUSBListNode {
public:
  PUSBListNode() { }
  bool (*setup)(USBSetup& setup, u8 i);
  int (*getInterface)(u8* interfaceNum);
  int (*getDescriptor)(int8_t t);
  int8_t numEndpoints;
  int8_t numInterfaces;
  uint8_t *endpointType;

public:
  PUSBListNode *next = NULL;
};

class PluggableUSB_ {
public:
  static int8_t addFunction(PUSBListNode *node, u8 *interface);
  static int getInterface(u8* interfaceNum);
  static int getDescriptor(int8_t t);
  static bool setup(USBSetup& setup, u8 i);
};

extern PluggableUSB_ PluggableUSB;

#endif

#endif
