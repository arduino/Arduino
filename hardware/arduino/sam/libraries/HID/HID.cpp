/* Copyright (c) 2015, Arduino LLC
**
** Original code (pre-library): Copyright (c) 2011, Peter Barrett
**
** Permission to use, copy, modify, and/or distribute this software for  
** any purpose with or without fee is hereby granted, provided that the  
** above copyright notice and this permission notice appear in all copies.  
** 
** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL  
** WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED  
** WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR  
** BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES  
** OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  
** WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,  
** ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  
** SOFTWARE.  
*/

#include "USB/PluggableUSB.h"
#include "HID.h"

HID_ HID;

static uint8_t HID_ENDPOINT_INT;

//================================================================================
//================================================================================

//	HID report descriptor

#define LSB(_x) ((_x) & 0xFF)
#define MSB(_x) ((_x) >> 8)

#define RAWHID_USAGE_PAGE	0xFFC0
#define RAWHID_USAGE		0x0C00
#define RAWHID_TX_SIZE 64
#define RAWHID_RX_SIZE 64

static uint8_t HID_INTERFACE;

HIDDescriptor _hidInterface;

static HIDDescriptorListNode* rootNode = NULL;
static uint8_t sizeof_hidReportDescriptor = 0;
static uint8_t modules_count = 0;
//================================================================================
//================================================================================
//	Driver

uint8_t _hid_protocol = 1;
uint8_t _hid_idle = 1;

int HID_GetInterface(uint8_t* interfaceNum)
{
	interfaceNum[0] += 1;	// uses 1
	_hidInterface =
	{
		D_INTERFACE(HID_INTERFACE,1,3,0,0),
		D_HIDREPORT(sizeof_hidReportDescriptor),
		D_ENDPOINT(USB_ENDPOINT_IN (HID_ENDPOINT_INT),USB_ENDPOINT_TYPE_INTERRUPT,0x40,0x01)
	};
	return USBD_SendControl(0,&_hidInterface,sizeof(_hidInterface));
}

int HID_GetDescriptor(int8_t t)
{
	if (HID_REPORT_DESCRIPTOR_TYPE == t) {
		HIDDescriptorListNode* current = rootNode;
		int total = 0;
		while(current != NULL) {
			total += USBD_SendControl(0,current->data,current->length);
			current = current->next;
		}
		return total;
	} else {
		return 0;
	}
}

void HID_::AppendDescriptor(HIDDescriptorListNode *node)
{
	if (modules_count == 0) {
		rootNode = node;
	} else {
		HIDDescriptorListNode *current = rootNode;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = node;
	}
	modules_count++;
	sizeof_hidReportDescriptor += node->length;
}

void HID_::SendReport(uint8_t id, const void* data, int len)
{
	uint8_t p[64];
	const uint8_t *d = reinterpret_cast<const uint8_t *>(data);

	p[0] = id;
	for (uint32_t i=0; i<len; i++)
		p[i+1] = d[i];
	USBD_Send(HID_TX, p, len+1);
}

bool HID_Setup(USBSetup& setup, uint8_t i)
{
	if (HID_INTERFACE != i) {
		return false;
	} else {
		uint8_t r = setup.bRequest;
		uint8_t requestType = setup.bmRequestType;
		if (REQUEST_DEVICETOHOST_CLASS_INTERFACE == requestType)
		{
			if (HID_GET_REPORT == r)
			{
			//HID_GetReport();
				return true;
			}
			if (HID_GET_PROTOCOL == r)
			{
			//Send8(_hid_protocol);	// TODO
				return true;
			}
		}
		
		if (REQUEST_HOSTTODEVICE_CLASS_INTERFACE == requestType)
		{
			if (HID_SET_PROTOCOL == r)
			{
				_hid_protocol = setup.wValueL;
				return true;
			}

			if (HID_SET_IDLE == r)
			{
				_hid_idle = setup.wValueL;
				return true;
			}
		}
		return false;
	}
}

HID_::HID_(void)
{
	static uint32_t endpointType[1];

	endpointType[0] = EP_TYPE_INTERRUPT_IN;

	static PUSBCallbacks cb = {
		.setup = &HID_Setup,
		.getInterface = &HID_GetInterface,
		.getDescriptor = &HID_GetDescriptor,
		.numEndpoints = 1,
		.numInterfaces = 1,
		.endpointType = endpointType,
	};

	static PUSBListNode node(&cb);

	HID_ENDPOINT_INT = PUSB_AddFunction(&node, &HID_INTERFACE);
}

int HID_::begin(void)
{
	return 0;
}
