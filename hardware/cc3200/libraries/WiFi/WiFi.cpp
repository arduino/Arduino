/*
 TO DO:
    1) figure out key index for WEP connection, can it be ignored?
 X  2) use wlan even callback to determine if wifi has connected
 X  3) make sure the ip address octet order is correct in config method
 X  4) figure out how to get the SSID of the currently connected station
 X  5) how do you figure out what the index of the currently connected profile is?
    6) What's the appropriate socket type to use?
    7) Write net app event handler to wait for assigned ip (see tcp socket example)
 */


/*
 WiFi.cpp - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 Author: Noah Luskey | LuskeyNoah@gmail.com
 
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

#include <Energia.h>
#include "WiFi.h"
#include "Utility/wl_definitions.h"


extern "C" {
    #include "SimpleLink.h"
    #include <string.h>
    #include "wlan.h"
    #include "netcfg.h"
    #include "netapp.h"
    #include "socket.h"
    #include "udma_if.h"
}

//
//initialize WiFi_status to the disconnected flag
//
wl_status_t WiFiClass::WiFi_status = WL_DISCONNECTED;

//
//initialize the ssid and bssid to blank and 0s respectively
//
char WiFiClass::connected_ssid[32] = "";
unsigned char WiFiClass::connected_bssid[6] = {0,0,0,0,0,0};

int16_t WiFiClass::_state[MAX_SOCK_NUM];
uint16_t WiFiClass::_server_port[MAX_SOCK_NUM];


WiFiClass::WiFiClass()
{
    //
    //Initialize the WiFi socket state arrays
    //
    int i;
    for (i = 0; i < MAX_SOCK_NUM; i++) {
        _state[i] = NA_STATE;
        _server_port[i] = 0;
    }
}

bool WiFiClass::init()
{
    //
    //Initialize the UDMA
    //
    UDMAInit();
    
    //
    //start the SimpleLink driver (no callback)
    //
    int iRet = sl_Start(NULL, NULL, NULL);
    
    //
    //check if sl_start failed
    //
    if (iRet==ROLE_STA_ERR || iRet==ROLE_AP_ERR || iRet==ROLE_P2P_ERR) {
        return false;
    }
    
    //
    //disconnect from any old connection
    //
    sl_WlanDisconnect();
    
    //
    //reset the Wlan Policy
    //
    sl_WlanPolicySet(SL_POLICY_CONNECTION, SL_CONNECTION_POLICY(0,0,0,0,0), NULL, 0);

    return true;
}

uint8_t WiFiClass::getSocket()
{
    //
    //return the first socket handle that is available
    //
    for (uint8_t i = 0; i < MAX_SOCK_NUM; ++i)
    {
        if (WiFiClass::_server_port[i] == 0)
        {
            return i;
        }
    }
    return NO_SOCKET_AVAIL;
}

char* WiFiClass::firmwareVersion()
{
    //
    //underlying simplelink api is version 0.5 as of June 12th
    //
    return "SimpleLink SDK 0.5";
}

int WiFiClass::begin(char* ssid)
{
    //
    //initialize the simplelink driver and make sure it was a success
    //
    bool init_success = WiFiClass::init();
    if (!init_success) {
        return WL_CONNECT_FAILED;
    }
    
    //
    //Get name length and set security type to open
    //
    int NameLen = strlen(ssid);
    SlSecParams_t* pSecParams;
    pSecParams->Type = SL_SEC_TYPE_OPEN;
    
    //
    //Connect to the access point (non enterprise, so 5th argument is NULL);
    //also mac address parameter set as null (3rd argument)
    //
    int iRet = sl_WlanConnect(ssid, NameLen, NULL, pSecParams, NULL);
    
    //
    //return appropriate status as described by arduino wifi library
    //the WiFiClass:WiFi_status is handled by the WlanEvenHandler
    //in SimpleLinkCallbacks.cpp. However, if iRet < 0, there was an error
    //
    if (iRet == 0) {
        return WiFi_status;
    } else {
        return WL_CONNECT_FAILED;
    }
    
}


//!!Ignore key index!!//
int WiFiClass::begin(char* ssid, uint8_t key_idx, char* key)
{
    //
    //initialize the simplelink driver and make sure it was a success
    //
    bool init_success = WiFiClass::init();
    if (!init_success) {
        return WL_CONNECT_FAILED;
    }
    
    //
    //get name length and set security type to WEP
    //add key and keylength to security parameters
    //
    int NameLen = strlen(ssid);
    SlSecParams_t* pSecParams;
    pSecParams->Type = SL_SEC_TYPE_WEP;
    pSecParams->Key = key;
    pSecParams->KeyLen = strlen(key);
    
    //
    //Connect to the access point (non enterprise, so 5th argument is NULL);
    //also mac address parameter set as null (3rd argument)
    //
    int iRet = sl_WlanConnect(ssid, NameLen, NULL, pSecParams, NULL);
    
    //
    //return appropriate status as described by arduino wifi library
    //the WiFiClass:WiFi_status is handled by the WlanEvenHandler
    //in SimpleLinkCallbacks.cpp. However, if iRet < 0, there was an error
    //
    if (iRet == 0) {
        return WiFi_status;
    } else {
        return WL_CONNECT_FAILED;
    }
    
}

int WiFiClass::begin(char* ssid, char *passphrase)
{
    //
    //initialize the simplelink driver and make sure it was a success
    //
    bool init_success = WiFiClass::init();
    if (!init_success) {
        return WL_CONNECT_FAILED;
    }
    
    //
    //get name length and set security type to WPA
    //add passphrase and keylength to security parameters
    //
    int NameLen = strlen(ssid);
    SlSecParams_t* pSecParams;
    pSecParams->Type = SL_SEC_TYPE_WPA;
    pSecParams->Key = passphrase;
    pSecParams->KeyLen = strlen(passphrase);
    
    //
    //connect to the access point (non enterprise, so 5th argument is NULL)
    //also mac address parameters set as null (3rd argument)
    //
    int iRet = sl_WlanConnect(ssid, NameLen, NULL, pSecParams, NULL);
    
    //
    //return appropriate status as described by arduino wifi library
    //the WiFiClass:WiFi_status is handled by the WlanEvenHandler
    //in SimpleLinkCallbacks.cpp. However, if iRet < 0, there was an error
    //
    if (iRet == 0) {
        return WiFi_status;
    } else {
        return WL_CONNECT_FAILED;
    }
}

void WiFiClass::config(IPAddress local_ip)
{
    //
    //get current configuration
    //
    _NetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(_NetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = (uint32_t)local_ip;
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(_NetCfgIpV4Args_t), (unsigned char*)&config);
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server)
{
    //
    //get current configuration
    //
    _NetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(_NetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = (uint32_t)local_ip;
    config.ipV4DnsServer = (uint32_t)dns_server;
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(_NetCfgIpV4Args_t), (unsigned char*)&config);
    
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway)
{
    //
    //get current configuration
    //
    _NetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(_NetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = (uint32_t)local_ip;
    config.ipV4DnsServer = (uint32_t)dns_server;
    config.ipV4Gateway = (uint32_t)gateway;
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(_NetCfgIpV4Args_t), (unsigned char*)&config);
    
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet)
{
    //
    //get current configuration
    //
    _NetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(_NetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = (uint32_t)local_ip;
    config.ipV4DnsServer = (uint32_t)dns_server;
    config.ipV4Gateway = (uint32_t)gateway;
    config.ipV4Mask = (uint32_t)subnet;
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(_NetCfgIpV4Args_t), (unsigned char*)&config);
    
}

void WiFiClass::setDNS(IPAddress dns_server1)
{
    //
    //get current configuration
    //
    _NetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(_NetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4DnsServer = (uint32_t)SL_IPV4_VAL(dns_server1[0], dns_server1[1], dns_server1[2], dns_server1[3]);
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(_NetCfgIpV4Args_t), (unsigned char*)&config);
}

//!!Not supported. Only set the dns server using the first address!!//
void WiFiClass::setDNS(IPAddress dns_server1, IPAddress dns_server2)
{
    //
    //because only 1 dns server is supported, use the previous set dns function
    //
    WiFiClass::setDNS(dns_server1);
}

int WiFiClass::disconnect(void)
{
    //
    //disconnect from the wlan and return the current wlan_status
    //
    int iRet = sl_WlanDisconnect();
    return WiFi_status;
    
    
}

uint8_t* WiFiClass::macAddress(uint8_t* mac)
{
    //
    //Get the mac address and return the pointer to the array
    //
    uint8_t macLength = 6;
    sl_NetCfgGet(SL_MAC_ADDRESS_GET, NULL, &macLength, (unsigned char *)mac);
    return mac;
}

IPAddress WiFiClass::subnetMask()
{
    //
    //get current configuration
    //
    _NetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(_NetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //change the uint32_t IP to the IPAddress class and return
    //
    IPAddress ipRet;
    ipRet = config.ipV4Mask;
    return ipRet;
    
}

IPAddress WiFiClass::gatewayIP()
{
    //
    //get current configuration
    //
    _NetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(_NetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //change the uint32_t IP to the IPAddress class and return
    //
    IPAddress ipRet;
    ipRet = config.ipV4Gateway;
    return ipRet;
}

char* WiFiClass::SSID()
{
    //
    //maximum ssid length is 32, however it will be shorter than this
    //because the simplelink api handles the name oddly this sets
    //the Nth character to '\0' to make sure the string handles correctly
    //
    
    return (char*)WiFiClass::connected_ssid;
}

uint8_t* WiFiClass::BSSID(uint8_t* bssid)
{
    //
    //because the bssid 6 char array is maintained by the callback
    //passing in a 6 char array is unecessary and only kept for
    //compatability with the Arduino WiFi library
    //
    return WiFiClass::connected_bssid;
    
}

//!! How to get the current connection??!!//
int32_t WiFiClass::RSSI()
{
    return 0;
}

//!! How to get the current connection??!!//
uint8_t WiFiClass::encryptionType()
{
    return 0;
}

int8_t WiFiClass::scanNetworks()
{
    //
    //set the scan interval policy, which activates an immediate scan
    //the scan interval (in case of no connection) is set to 5 minutes
    //
    uint8_t seconds = 300;
    sl_WlanPolicySet(SL_POLICY_SCAN, 1, (unsigned char *)&seconds, sizeof(seconds));
    
    //
    //get the number of valid entries. Unfortunately this has to be done
    //in a convoluted fashion where the entries are allocated memory.
    //sl_WlanGetNetworkList returns the number of valid networks found (up to 20)
    //
    Sl_WlanNetworkEntry_t networks[20];
    return sl_WlanGetNetworkList(0, 20, networks);
    
}

char* WiFiClass::SSID(uint8_t networkItem)
{
    //
    //get the network list and return the ssid of the requested index
    //!!This won't work, right? Because the networks array is allocated for the
    //!!life of this function and becomes garbage once the function returns
    //
    Sl_WlanNetworkEntry_t networks[20];
    int networkCount = sl_WlanGetNetworkList(0, 20, networks);
    if (networkItem >= networkCount) {
        return NULL;
    }
    return (char*)networks[networkItem].ssid;
    
}

uint8_t WiFiClass::encryptionType(uint8_t networkItem)
{
    //
    //get the network list and pull out the security type of the requested item
    //
    Sl_WlanNetworkEntry_t networks[20];
    int networkCount = sl_WlanGetNetworkList(0, 20, networks);
    if (networkItem >= networkCount) {
        return 0;
    }
    uint8_t security = networks[networkItem].sec_type;
    
    //
    //the security type returned by simplelink has to be matched
    //to the security type that would be returned by arduino
    //TKIP (WPA) = 2, WEP = 5, NONE = 7, AUTO = 8
    //
    if (security == SL_SEC_TYPE_WPA) {
        return 2;
    } else if (security == SL_SEC_TYPE_WEP) {
        return 5;
    } else if (security == SL_SEC_TYPE_OPEN) {
        return 7;
    } else {
        return 8;
    }
}

int32_t WiFiClass::RSSI(uint8_t networkItem)
{
    //
    //get the network list and pull out the security type of the requested item
    //
    Sl_WlanNetworkEntry_t networks[20];
    int networkCount = sl_WlanGetNetworkList(0, 20, networks);
    if (networkItem >= networkCount) {
        return 0;
    }
    return (int32_t)networks[networkItem].rssi;
}


uint8_t WiFiClass::status()
{
    //
    //This class variable is maintained by the slWlanEvenHandler
    //
    return WiFi_status;
}

int WiFiClass::hostByName(char* aHostname, IPAddress& aResult)
{
    //
    //Use the netapp api to resolve an IP for the requested hostname
    //
    unsigned long DestinationIP;
    int iRet = sl_NetAppDnsGetHostByName(aHostname, strlen(aHostname), &DestinationIP, SL_AF_INET);
    aResult = DestinationIP;
    
    if (iRet > 0) {
        return 1;
    } else {
        return iRet;
    }
    
}

WiFiClass WiFi;



