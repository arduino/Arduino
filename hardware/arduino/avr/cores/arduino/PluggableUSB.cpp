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

// TODO: set correct value for different CPUs
#define MAX_EP 6

extern uint8_t _initEndpoints[];

PluggableUSB_ PluggableUSB;

int PluggableUSB_::getInterface(uint8_t* interfaceNum)
{
	int ret = 0;
	PUSBListNode* node;
	for (node = rootNode; node; node = node->next) {
		ret = node->getInterface(interfaceNum);
	}
	return ret;
}

int PluggableUSB_::getDescriptor(int8_t t)
{
	PUSBListNode* node;
	for (node = rootNode; node; node = node->next) {
		int ret = node->getDescriptor(t);
		if (ret)
			return ret;
	}
	return 0;
}

bool PluggableUSB_::setup(USBSetup& setup, uint8_t j)
{
	PUSBListNode* node;
	for (node = rootNode; node; node = node->next) {
		if (node->setup(setup, j)) {
			return true;
		}
	}
	return false;
}

bool PluggableUSB_::plug(PUSBListNode *node)
{
	if ((lastEp + node->numEndpoints) >= MAX_EP) {
		return false;
	}

	if (!rootNode) {
		rootNode = node;
	} else {
		PUSBListNode *current = rootNode;
		while (current->next) {
			current = current->next;
		}
		current->next = node;
	}

	node->pluggedInterface = lastIf;
	node->pluggedEndpoint = lastEp;
	lastIf += node->numInterfaces;
	for (uint8_t i = 0; i < node->numEndpoints; i++) {
		_initEndpoints[lastEp] = node->endpointType[i];
		lastEp++;
	}
	return true;
	// restart USB layer???
}

PluggableUSB_::PluggableUSB_() : lastIf(CDC_ACM_INTERFACE + CDC_INTERFACE_COUNT),
                                 lastEp(CDC_FIRST_ENDPOINT + CDC_ENPOINT_COUNT),
                                 rootNode(NULL)
{
	// Empty
}

#endif

#endif /* if defined(USBCON) */
