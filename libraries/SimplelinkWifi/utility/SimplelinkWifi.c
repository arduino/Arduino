#include <SimplelinkWifi.h>



#define PALTFORM_VERSION						(1)

#define CC3000_APP_BUFFER_SIZE						(5)

#define CC3000_RX_BUFFER_OVERHEAD_SIZE			(20)

#define DISABLE										(0)

#define ENABLE										(1)

#define SL_VERSION_LENGTH							(11)

#define NETAPP_IPCONFIG_MAC_OFFSET				(20)

volatile unsigned long ulSmartConfigFinished, ulCC3000Connected,ulCC3000DHCP,
OkToDoShutDown, ulCC3000DHCP_configured, ulCC3000WasConnected;

volatile fd_set gConnectedSockets;

volatile unsigned char ucStopSmartConfig;

volatile long ulSocket;

volatile unsigned long SendmDNSAdvertisment;
char DevServname[] = {'C','C','3','0','0','0'};

//device name used by smart config response
char device_name[] = "home_assistant";
 	
//AES key "smartconfigAES16"
const unsigned char smartconfigkey[] = {0x73,0x6d,0x61,0x72,0x74,0x63,0x6f,0x6e,0x66,0x69,0x67,0x41,0x45,0x53,0x31,0x36};

//unsigned char printOnce = 1;
 


// Reception from the air, buffer - the max data length  + headers

unsigned char pucCC3000_Rx_Buffer[CC3000_APP_BUFFER_SIZE + CC3000_RX_BUFFER_OVERHEAD_SIZE];




//*****************************************************************************
//
//! CC3000_UsynchCallback
//!
//! @param  lEventType   Event type
//! @param  data   
//! @param  length   
//!
//! @return none
//!
//! @brief  The function handles asynchronous events that come from CC3000  
//!		      device and operates a LED1 to have an on-board indication
//
//*****************************************************************************
#include <Energia.h>
void CC3000_UsynchCallback(long lEventType, char * data, unsigned char length)
{

	if (lEventType == HCI_EVNT_BSD_TCP_CLOSE_WAIT)
	{
		FD_CLR(data[0], &gConnectedSockets);
	}

	if (lEventType == HCI_EVNT_WLAN_ASYNC_SIMPLE_CONFIG_DONE)
	{
		ulSmartConfigFinished = 1;
		ucStopSmartConfig     = 1;  
		
	}
	
	if (lEventType == HCI_EVNT_WLAN_UNSOL_CONNECT)
	{
		ulCC3000Connected = 1;
		ulCC3000WasConnected = 1;
		
	}
	
	if (lEventType == HCI_EVNT_WLAN_UNSOL_DISCONNECT)
	{		
		ulCC3000Connected = 0;
		ulCC3000DHCP      = 0;
		ulCC3000DHCP_configured = 0;

	}
	
	if (lEventType == HCI_EVNT_WLAN_UNSOL_DHCP)
	{
		// Notes: 
		// 1) IP config parameters are received swapped
		// 2) IP config parameters are valid only if status is OK, i.e. ulCC3000DHCP becomes 1
		
		// only if status is OK, the flag is set to 1 and the addresses are valid
		if ( *(data + NETAPP_IPCONFIG_MAC_OFFSET) == 0)
		{
			//sprintf( (char*)pucCC3000_Rx_Buffer,"IP:%d.%d.%d.%d\f\r", data[3],data[2], data[1], data[0] );

			ulCC3000DHCP = 1;

		}
		else
		{
			ulCC3000DHCP = 0;

		}
	}
	
	if (lEventType == HCI_EVENT_CC3000_CAN_SHUT_DOWN)
	{
		OkToDoShutDown = 1;
	}
	
}
