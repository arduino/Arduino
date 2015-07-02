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

typedef struct __attribute__((packed))
{
  bool (*setup)(USBSetup& setup, u8 i);
  int (*getInterface)(u8* interfaceNum);
  int (*getDescriptor)(int8_t t);
  int8_t numEndpoints;
  int8_t numInterfaces;
  uint8_t *endpointType;
} PUSBCallbacks;

typedef struct
{
  u8 interface;
  u8 firstEndpoint;
} PUSBReturn;

class PUSBListNode {
public:
  PUSBListNode *next = NULL;
  PUSBCallbacks *cb;
  PUSBListNode(PUSBCallbacks *ncb) {cb = ncb;}
};

int8_t PUSB_AddFunction(PUSBListNode *node, u8 *interface);

int PUSB_GetInterface(u8* interfaceNum);

int PUSB_GetDescriptor(int8_t t);

bool PUSB_Setup(USBSetup& setup, u8 i);

void PUSB_Begin();

#endif

#endif
