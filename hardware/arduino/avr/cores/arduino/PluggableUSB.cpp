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

extern uint8_t _initEndpoints[];

//PUSBCallbacks cbs[MAX_MODULES];

PluggableUSB_ PluggableUSB;

int PluggableUSB_::getInterface(uint8_t* interfaceNum)
{
	int ret = 0;
	PUSBListNode* node = rootNode;
	for (uint8_t i=0; i<modulesCount; i++) {
		ret = node->getInterface(interfaceNum);
		node = node->next;
	}
	return ret;
}

int PluggableUSB_::getDescriptor(int8_t t)
{
	int ret = 0;
	PUSBListNode* node = rootNode;
	for (uint8_t i=0; i<modulesCount && ret == 0; i++) {
		ret = node->getDescriptor(t);
		node = node->next;
	}
	return ret;
}

bool PluggableUSB_::setup(USBSetup& setup, uint8_t j)
{
	bool ret = false;
	PUSBListNode* node = rootNode;
	for (uint8_t i=0; i<modulesCount && ret == false; i++) {
		ret = node->setup(setup, j);
		node = node->next;
	}
	return ret;
}

bool PluggableUSB_::plug(PUSBListNode *node)
{
	if (modulesCount >= MAX_MODULES) {
		return false;
	}

	if (modulesCount == 0) {
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
	modulesCount++;
	return true;
	// restart USB layer???
}

PluggableUSB_::PluggableUSB_() : lastIf(CDC_ACM_INTERFACE + CDC_INTERFACE_COUNT),
                                 lastEp(CDC_FIRST_ENDPOINT + CDC_ENPOINT_COUNT),
                                 modulesCount(0), rootNode(NULL)
{
	// Empty
}

#endif

#endif /* if defined(USBCON) */
