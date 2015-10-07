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
  PUSBListNode(uint8_t numEps, uint8_t numIfs, uint8_t *epType) :
    numEndpoints(numEps), numInterfaces(numIfs), endpointType(epType)
  { }

  inline uint8_t interface() const { return pluggedInterface; }
  inline uint8_t endpoint()   const { return pluggedEndpoint; }

protected:
  virtual bool setup(USBSetup& setup) = 0;
  virtual int getInterface(uint8_t* interfaceCount) = 0;
  virtual int getDescriptor(USBSetup& setup) = 0;

  uint8_t pluggedInterface;
  uint8_t pluggedEndpoint;

  const uint8_t numEndpoints;
  const uint8_t numInterfaces;
  const uint8_t *endpointType;

  PUSBListNode *next = NULL;

  friend class PluggableUSB_;
};

class PluggableUSB_ {
public:
  PluggableUSB_();
  bool plug(PUSBListNode *node);
  int getInterface(uint8_t* interfaceCount);
  int getDescriptor(USBSetup& setup);
  bool setup(USBSetup& setup);

private:
  uint8_t lastIf;
  uint8_t lastEp;
  PUSBListNode* rootNode;
};

// Replacement for global singleton.
// This function prevents static-initialization-order-fiasco
// https://isocpp.org/wiki/faq/ctors#static-init-order-on-first-use
PluggableUSB_& PluggableUSB();

#endif

#endif
