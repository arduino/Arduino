/*
 TO DO:
    1) figure out key index for WEP connection, can it be ignored?
 X  2) use wlan even callback to determine if wifi has connected
 X  3) make sure the ip address octet order is correct in config method
    4) figure out how to get the SSID of the currently connected station
    4!) how do you figure out what the index of the currently connected profile is?
 */


/*
 WiFi.cpp - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 Author: Noah Luskey
 
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
}

//
//initialize WiFi_status to the disconnected flag
//
wl_status_t WiFiClass::WiFi_status = WL_DISCONNECTED;

WiFiClass::WiFiClass()
{
    //simplelink driver initialization
    init();
}

void WiFiClass::init()
{
    //
    //start the SimpleLink driver (no callback)
    //
    sl_Start(NULL, NULL, NULL);
    
    //
    //disconnect from any old connection
    //
    sl_WlanDisconnect();
    
    
}

uint8_t WiFiClass::getSocket()
{
    
}

char* WiFiClass::firmwareVersion()
{
    
}

int WiFiClass::begin(char* ssid)
{
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
        return WiFiClass::WiFi_status;
    } else {
        return WL_CONNECT_FAILED;
    }
    
}


//!!Ignore key index!!//
int WiFiClass::begin(char* ssid, uint8_t key_idx, char* key)
{
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
        return WiFiClass::WiFi_status;
    } else {
        return WL_CONNECT_FAILED;
    }
    
}

int WiFiClass::begin(char* ssid, char *passphrase)
{
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
        return WiFiClass::WiFi_status;
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
    config.ipV4 = (uint32_t)SL_IPV4_VAL(local_ip[0], local_ip[1], local_ip[2], local_ip[3]);
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
    config.ipV4 = (uint32_t)SL_IPV4_VAL(local_ip[0], local_ip[1], local_ip[2], local_ip[3]);
    config.ipV4DnsServer = (uint32_t)SL_IPV4_VAL(dns_server[0], dns_server[1], dns_server[2], dns_server[3]);
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
    config.ipV4 = (uint32_t)SL_IPV4_VAL(local_ip[0], local_ip[1], local_ip[2], local_ip[3]);
    config.ipV4DnsServer = (uint32_t)SL_IPV4_VAL(dns_server[0], dns_server[1], dns_server[2], dns_server[3]);
    config.ipV4Gateway = (uint32_t)SL_IPV4_VAL(gateway[0], gateway[1], gateway[2], gateway[3]);
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
    config.ipV4 = (uint32_t)SL_IPV4_VAL(local_ip[0], local_ip[1], local_ip[2], local_ip[3]);
    config.ipV4DnsServer = (uint32_t)SL_IPV4_VAL(dns_server[0], dns_server[1], dns_server[2], dns_server[3]);
    config.ipV4Gateway = (uint32_t)SL_IPV4_VAL(gateway[0], gateway[1], gateway[2], gateway[3]);
    config.ipV4Mask = (uint32_t)SL_IPV4_VAL(subnet[0], subnet[1], subnet[2], subnet[3]);
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
    return WiFiClass::WiFi_status;
    
    
}

uint8_t* WiFiClass::macAddress(uint8_t* mac)
{
    //
    //Get the mac address and return the pointer to the array
    //
    uint8_t macLength = 6;
    sl_NetCfgGet(SL_MAC_ADDRESS_GET, NULL, &macLength, (unsigned char *)mac);
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

//!! I'm pretty sure this is wrong !!//
//so there's a way to use sl_WlanProfileGet to get profiles//
//but i don't know how to figure out what profile is currently used//
char* WiFiClass::SSID()
{
    char ssid[32];
    unsigned short len = 32;
    unsigned short  config_opt = WLAN_AP_OPT_SSID;
    sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt , &len, (unsigned char*)ssid);
    
    return ssid;
}

//!! I'm pretty sure this is wrong !!//
//so there's a way to use sl_WlanProfileGet to get profiles//
//but i don't know how to figure out what profile is currently used//
uint8_t* WiFiClass::BSSID(uint8_t* bssid)
{
    
}


//!! I'm pretty sure this is wrong !!//
//so there's a way to use sl_WlanProfileGet to get profiles//
//but i don't know how to figure out what profile is currently used//
int32_t WiFiClass::RSSI()
{
    
}

//!! I'm pretty sure this is wrong !!//
//so there's a way to use sl_WlanProfileGet to get profiles//
//but i don't know how to figure out what profile is currently used//
uint8_t WiFiClass::encryptionType()
{
    
}

int8_t WiFiClass::scanNetworks()
{
    //
    //set the scan interval policy, which activates an immediate scan
    //the scan interval (in case of no connection) is set to 5 minutes
    //
    uint8_t seconds = 300;
    sl_WlanPolicySet(SL_POLICY_SCAN, 1, (unsigned char *)&seconds, sizeof(seconds));
}

char* WiFiClass::SSID(uint8_t networkItem)
{
    
}

uint8_t WiFiClass::encryptionType(uint8_t networkItem)
{
    
}

int32_t WiFiClass::RSSI(uint8_t networkItem)
{
    
}

uint8_t WiFiClass::status()
{
    
}

int WiFiClass::hostByName(const char* aHostname, IPAddress& aResult)
{
    
}

WiFiClass WiFi;



