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
  PUSBListNode(int8_t numEps, int8_t numIfs, uint8_t *epType) :
    numEndpoints(numEps), numInterfaces(numIfs), endpointType(epType)
  { }

  inline uint8_t interface() const { return pluggedInterface; }
  inline int8_t endpoint()   const { return pluggedEndpoint; }

protected:
  virtual bool setup(USBSetup& setup, uint8_t i) = 0;
  virtual int getInterface(uint8_t* interfaceNum) = 0;
  virtual int getDescriptor(int8_t t) = 0;

  uint8_t pluggedInterface;
  int8_t pluggedEndpoint;

  const int8_t numEndpoints;
  const int8_t numInterfaces;
  const uint8_t *endpointType;

public:
  PUSBListNode *next = NULL;

  friend class PluggableUSB_;
};

class PluggableUSB_ {
public:
  PluggableUSB_();
  bool plug(PUSBListNode *node);
  int getInterface(uint8_t* interfaceNum);
  int getDescriptor(int8_t t);
  bool setup(USBSetup& setup, uint8_t i);

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
