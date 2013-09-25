#include "wifi.h"
#include "SimplelinkWifi.h"
#include "Energia.h"

#define DISABLE	(0)
#define ENABLE	(1)
extern volatile unsigned long ulSmartConfigFinished, ulCC3000Connected,ulCC3000DHCP,
OkToDoShutDown, ulCC3000DHCP_configured;
extern volatile unsigned char ucStopSmartConfig;

extern uint8_t CSpin;
extern uint8_t ENpin;
extern uint8_t IRQpin;

// Simple Config Prefix
const char aucCC3000_prefix[] = {'T', 'T', 'T'};

//AES key "smartconfigAES16"
const unsigned char smartconfigkey[] = {0x73,0x6d,0x61,0x72,0x74,0x63,0x6f,0x6e,0x66,0x69,0x67,0x41,0x45,0x53,0x31,0x36};

uint8_t calculator_socket_number = 0;
WiFiClass::WiFiClass()
{
	// Driver initialization
	init();
}

void WiFiClass::setCSpin(uint8_t pin){
	CSpin=pin;
}
void WiFiClass::setENpin(uint8_t pin){
	ENpin=pin;
}
void WiFiClass::setIRQpin(uint8_t pin){
	IRQpin=pin;
}


void WiFiClass::init()
{
    //stuff
	// pio_init();
}

// connect to an open AP
int WiFiClass::begin(char* ssid)
{
	uint8_t status=0;
    pio_init();
    init_spi();
    // WLAN On API Implementation
	wlan_init( CC3000_UsynchCallback, sendWLFWPatch, sendDriverPatch, sendBootLoaderPatch, ReadWlanInterruptPin, WlanInterruptEnable, WlanInterruptDisable, WriteWlanPin);
	
	// Trigger a WLAN device
	wlan_start(0);
	wlan_set_event_mask(HCI_EVNT_WLAN_KEEPALIVE|HCI_EVNT_WLAN_UNSOL_INIT|HCI_EVNT_WLAN_ASYNC_PING_REPORT);

    // char *pcSsid;
	// long ulSsidLen = 14;
	
	// pcSsid = & SSID[0];
	
	//wlan_connect(WLAN_SEC_UNSEC,pcSsid,ulSsidLen,NULL, NULL, 0);
	wlan_connect(WLAN_SEC_UNSEC,ssid,strlen(ssid),NULL, NULL, 0);
	// wlan_connect(WLAN_SEC_UNSEC,pcSsid,strlen(pcSsid),NULL, NULL, 0);
	
	while (ulCC3000Connected  == 0)
	{
		
		__delay_cycles(6000000);
		
	}

	return status;
}

// connect to a WPA AP
int WiFiClass::begin(char* ssid, unsigned char* pass)
{
//char ssid[] = "yourAP";     //  your network SSID (name) 
//unsigned char pass[] = "qwertyuiopqwe";  // your network password
	
	uint8_t status=0;
    pio_init();
    init_spi();
    // WLAN On API Implementation
	wlan_init( CC3000_UsynchCallback, sendWLFWPatch, sendDriverPatch, sendBootLoaderPatch, ReadWlanInterruptPin, WlanInterruptEnable, WlanInterruptDisable, WriteWlanPin);
	
	// Trigger a WLAN device
	wlan_start(0);
	wlan_set_event_mask(HCI_EVNT_WLAN_KEEPALIVE|HCI_EVNT_WLAN_UNSOL_INIT|HCI_EVNT_WLAN_ASYNC_PING_REPORT);

	//wlan_connect(WLAN_SEC_WPA2,ssid,strlen(ssid),NULL, passphrase, strlen(passphrase));
wlan_connect(WLAN_SEC_WPA2,ssid,strlen(ssid),NULL, pass,strlen((char *)(pass)));

	while (ulCC3000Connected  == 0)
	{
		
		__delay_cycles(6000000);
		

		
	}
	return status;
}

// connect to a WEP AP
int WiFiClass::begin(char* ssid, uint8_t key_idx, unsigned char *key)
{
//  char ssid[] = "yourAP";     //  your network SSID (name) 
// uint8_t key_idx = 13;
// unsigned char key[] = "qwertyuiopqwe";  // your network password

	uint8_t status=0;
    pio_init();
    init_spi();
    // WLAN On API Implementation
	wlan_init( CC3000_UsynchCallback, sendWLFWPatch, sendDriverPatch, sendBootLoaderPatch, ReadWlanInterruptPin, WlanInterruptEnable, WlanInterruptDisable, WriteWlanPin);
	
	// Trigger a WLAN device
	wlan_start(0);
	wlan_set_event_mask(HCI_EVNT_WLAN_KEEPALIVE|HCI_EVNT_WLAN_UNSOL_INIT|HCI_EVNT_WLAN_ASYNC_PING_REPORT);

	wlan_connect(WLAN_SEC_WEP,ssid,strlen(ssid),NULL, key, key_idx);
	
	while (ulCC3000Connected  == 0)
	{
		
		__delay_cycles(6000000);
		
		
	}
	return status;
}

// Do stuff before smartconfig
int WiFiClass::begin()
{
	//uint8_t status=0;
    pio_init();
    init_spi();
	// WLAN On API Implementation
	wlan_init( CC3000_UsynchCallback, sendWLFWPatch, sendDriverPatch, sendBootLoaderPatch, ReadWlanInterruptPin, WlanInterruptEnable, WlanInterruptDisable, WriteWlanPin);
	
	// Trigger a WLAN device
	wlan_start(0);
	

	
	// Mask out all non-required events from CC3000
	wlan_set_event_mask(HCI_EVNT_WLAN_KEEPALIVE|HCI_EVNT_WLAN_UNSOL_INIT|HCI_EVNT_WLAN_ASYNC_PING_REPORT);
	
	
//	wakeup_timer_init();
	
	ucStopSmartConfig   = 0;
	
	int i=0;
	while (i<5)
	{
		
		__delay_cycles(6000000);
		

		i++;
		
	}
	if(ulCC3000Connected==0)
	return WL_DISCONNECTED;
	else return WL_CONNECTED;
}

uint8_t WiFiClass::status()
{
    if(ulCC3000Connected==0)
	return WL_DISCONNECTED;
	else return WL_CONNECTED;
}

/*
int WiFiClass::startSmartConfig()
{	ulSmartConfigFinished = 0;
	ulCC3000Connected = 0;
	ulCC3000DHCP = 0;
	OkToDoShutDown=0;
	
	// Reset all the previous configuration
	wlan_ioctl_set_connection_policy(DISABLE, DISABLE, DISABLE);	
	wlan_ioctl_del_profile(255);
	
	//Wait until CC3000 is disconnected
	while (ulCC3000Connected == 1)
	{
		__delay_cycles(1000);
	}
	
	// Trigger the Smart Config process

	wlan_smart_config_set_prefix((char*)aucCC3000_prefix);
     
	
	// Start the SmartConfig start process
	wlan_smart_config_start(1);
                                                                           
	
	// Wait for Smartconfig process complete
	while (ulSmartConfigFinished == 0)
	{
		
		__delay_cycles(6000000);
		
		
	}
	

#ifndef CC3000_UNENCRYPTED_SMART_CONFIG
	// create new entry for AES encryption key
	nvmem_create_entry(NVMEM_AES128_KEY_FILEID,16);

	
	// write AES key to NVMEM
	aes_write_key((unsigned char *)(&smartconfigkey[0]));

	// Decrypt configuration information and add profile
	
	wlan_smart_config_process();

#endif    
	
	// Configure to connect automatically to the AP retrieved in the 
	// Smart config process
	wlan_ioctl_set_connection_policy(DISABLE, DISABLE, ENABLE);
	
	// reset the CC3000
	wlan_stop();
	
	__delay_cycles(6000000);

	wlan_start(0);
	
	// Mask out all non-required events
	wlan_set_event_mask(HCI_EVNT_WLAN_KEEPALIVE|HCI_EVNT_WLAN_UNSOL_INIT|HCI_EVNT_WLAN_ASYNC_PING_REPORT);

	return 0;
}
*/

// if it return 0, it means the socket number is over how many CC3000 can handler
bool WiFiClass::countSocket(bool add_sock)
{   
	if(add_sock) 
		calculator_socket_number++; 
	else calculator_socket_number--;
	if (calculator_socket_number>4) 
		return 0; 
	else return 1;
}

WiFiClass WiFi;