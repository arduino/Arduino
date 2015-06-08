/*
  PluggableUSB.cpp
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

#include "USBAPI.h"
#include "PluggableUSB.h"

#if defined(USBCON)	
#ifdef PLUGGABLE_USB_ENABLED

#define MAX_MODULES	6

static u8 lastIf = CDC_ACM_INTERFACE + CDC_INTERFACE_COUNT;
static u8 lastEp = CDC_FIRST_ENDPOINT + CDC_ENPOINT_COUNT;

extern u8 _initEndpoints[];

PUSBCallbacks cbs[MAX_MODULES];
u8 modules_count = 0;

int8_t PUSB_GetInterface(u8* interfaceNum)
{
	int8_t ret = 0;
	for (u8 i=0; i<modules_count; i++) {
		ret = cbs[i].getInterface(interfaceNum);
	}
	return ret;
}

int8_t PUSB_GetDescriptor(int8_t t)
{
	int8_t ret = 0;
	for (u8 i=0; i<modules_count && ret == 0; i++) {
		ret = cbs[i].getDescriptor(t);
	}
	return ret;
}

bool PUSB_Setup(Setup& setup, u8 j)
{
	bool ret = false;
	for (u8 i=0; i<modules_count && ret == false; i++) {
		ret = cbs[i].setup(setup, j);
	}
	return ret;
}

int8_t PUSB_AddFunction(PUSBCallbacks *cb, u8* interface) 
{
	if (modules_count >= MAX_MODULES) {
		return 0;
	}
	cbs[modules_count] = *cb;

	*interface = lastIf;
	lastIf++;
	for ( u8 i = 0; i< cb->numEndpoints; i++) {
		_initEndpoints[lastEp] = cb->endpointType[i];
		lastEp++;
	}
	modules_count++;
	return lastEp-1;
	// restart USB layer???
}

#endif

#endif /* if defined(USBCON) */