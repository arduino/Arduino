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
  bool (*setup)(USBSetup& setup, uint8_t i);
  int (*getInterface)(uint8_t* interfaceNum);
  int (*getDescriptor)(int8_t t);
  int8_t numEndpoints;
  int8_t numInterfaces;
  uint8_t *endpointType;

  inline uint8_t interface() const { return pluggedInterface; }
  inline int8_t endpoint()   const { return pluggedEndpoint; }

protected:
  uint8_t pluggedInterface;
  int8_t pluggedEndpoint;

public:
  PUSBListNode *next = NULL;

  friend class PluggableUSB_;
};

class PluggableUSB_ {
public:
  static bool plug(PUSBListNode *node);
  static int getInterface(uint8_t* interfaceNum);
  static int getDescriptor(int8_t t);
  static bool setup(USBSetup& setup, uint8_t i);
};

extern PluggableUSB_ PluggableUSB;

#endif

#endif
