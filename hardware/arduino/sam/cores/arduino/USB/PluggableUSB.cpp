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
#include "USBDesc.h"
#include "PluggableUSB.h"

#ifdef PLUGGABLE_USB_ENABLED

#define MAX_MODULES	6

static uint8_t lastIf = CDC_ACM_INTERFACE + CDC_INTERFACE_COUNT;
static uint8_t lastEp = CDC_FIRST_ENDPOINT + CDC_ENPOINT_COUNT;

extern uint32_t EndPoints[];

//PUSBCallbacks cbs[MAX_MODULES];
static uint8_t modules_count = 0;

static PUSBListNode* rootNode = NULL;

int PUSB_GetInterface(uint8_t* interfaceNum)
{
	int ret = 0;
	PUSBListNode* node = rootNode;
	for (uint8_t i=0; i<modules_count; i++) {
		ret = node->cb->getInterface(interfaceNum);
		node = node->next;
	}
	return ret;
}

int PUSB_GetDescriptor(int8_t t)
{
	int ret = 0;
	PUSBListNode* node = rootNode;
	for (uint8_t i=0; i<modules_count && ret == 0; i++) {
		ret = node->cb->getDescriptor(t);
		node = node->next;
	}
	return ret;
}

bool PUSB_Setup(USBSetup& setup, uint8_t j)
{
	bool ret = false;
	PUSBListNode* node = rootNode;
	for (uint8_t i=0; i<modules_count && ret == false; i++) {
		ret = node->cb->setup(setup, j);
		node = node->next;
	}
	return ret;
}

int8_t PUSB_AddFunction(PUSBListNode *node, uint8_t* interface)
{
	if (modules_count >= MAX_MODULES) {
		return 0;
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

	*interface = lastIf;
	lastIf += node->cb->numInterfaces;
	for ( uint8_t i = 0; i< node->cb->numEndpoints; i++) {
		EndPoints[lastEp] = node->cb->endpointType[i];
		lastEp++;
	}
	modules_count++;
	return lastEp - node->cb->numEndpoints;
	// restart USB layer???
}

#endif