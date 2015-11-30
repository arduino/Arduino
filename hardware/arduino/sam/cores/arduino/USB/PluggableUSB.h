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

#if defined(USBCON)

class PluggableUSBModule {
public:
  PluggableUSBModule(uint8_t numEps, uint8_t numIfs, uint32_t *epType) :
    numEndpoints(numEps), numInterfaces(numIfs), endpointType(epType)
  { }

protected:
  virtual bool setup(USBSetup& setup) = 0;
  virtual int getInterface(uint8_t* interfaceCount) = 0;
  virtual int getDescriptor(USBSetup& setup) = 0;
  virtual uint8_t getShortName(char *name) { name[0] = 'A'+pluggedInterface; return 1; }

  uint8_t pluggedInterface;
  uint8_t pluggedEndpoint;

  const uint8_t numEndpoints;
  const uint8_t numInterfaces;
  const uint32_t *endpointType;

  PluggableUSBModule *next = NULL;

  friend class PluggableUSB_;
};

class PluggableUSB_ {
public:
  PluggableUSB_();
  bool plug(PluggableUSBModule *node);
  int getInterface(uint8_t* interfaceCount);
  int getDescriptor(USBSetup& setup);
  bool setup(USBSetup& setup);
  void getShortName(char *iSerialNum);

private:
  uint8_t lastIf;
  uint8_t lastEp;
  PluggableUSBModule* rootNode;
};

// Replacement for global singleton.
// This function prevents static-initialization-order-fiasco
// https://isocpp.org/wiki/faq/ctors#static-init-order-on-first-use
PluggableUSB_& PluggableUSB();

#endif

#endif
