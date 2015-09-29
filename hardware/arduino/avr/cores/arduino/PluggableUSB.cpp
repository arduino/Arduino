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

//PUSBCallbacks cbs[MAX_MODULES];
static u8 modules_count = 0;

static PUSBListNode* rootNode = NULL;

int PluggableUSB_::getInterface(u8* interfaceNum)
{
	int ret = 0;
	PUSBListNode* node = rootNode;
	for (u8 i=0; i<modules_count; i++) {
		ret = node->getInterface(interfaceNum);
		node = node->next;
	}
	return ret;
}

int PluggableUSB_::getDescriptor(int8_t t)
{
	int ret = 0;
	PUSBListNode* node = rootNode;
	for (u8 i=0; i<modules_count && ret == 0; i++) {
		ret = node->getDescriptor(t);
		node = node->next;
	}
	return ret;
}

bool PluggableUSB_::setup(USBSetup& setup, u8 j)
{
	bool ret = false;
	PUSBListNode* node = rootNode;
	for (u8 i=0; i<modules_count && ret == false; i++) {
		ret = node->setup(setup, j);
		node = node->next;
	}
	return ret;
}

bool PluggableUSB_::plug(PUSBListNode *node)
{
	if (modules_count >= MAX_MODULES) {
		return false;
	}

	if (modules_count == 0) {
		rootNode = node;
	} else {
		PUSBListNode *current = rootNode;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = node;
	}

	node->pluggedInterface = lastIf;
	node->pluggedEndpoint = lastEp;
	lastIf += node->numInterfaces;
	for (uint8_t i=0; i<node->numEndpoints; i++) {
		_initEndpoints[lastEp] = node->endpointType[i];
		lastEp++;
	}
	modules_count++;
	return true;
	// restart USB layer???
}

#endif

#endif /* if defined(USBCON) */
