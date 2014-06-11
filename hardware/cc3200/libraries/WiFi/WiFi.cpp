/*
 TO DO:
    1) figure out key index for WEP connection, can it be ignored?
    2) use wlan even callback to determine if wifi has connected
    3) make sure the ip address octet order is correct in config method
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
#include "wl_definitions.h"


extern "C" {
    #include "SimpleLink.h"
    #include <string.h>
    #include "wlan.h"
    #include "netcfg.h"
}


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
    //Stop smartconfig (if for some reason it's running
    //
    sl_WlanSmartConfigStop();
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
    //simplelink returns 0 on success, arduino returns 0 on failure.
    //
    if (iRet == 0) {
        return WL_CONNECTED;
    } else {
        return WL_IDLE_STATUS;
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
    //simplelink returns 0 on success, arduino returns 0 on failure.
    //
    if (iRet == 0) {
        return WL_CONNECTED;
    } else {
        return WL_IDLE_STATUS;
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
    //simplelink returns 0 on success, arduino returns 0 on failure.
    //
    if (iRet == 0) {
        return WL_CONNECTED;
    } else {
        return WL_IDLE_STATUS;
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
    
}

uint8_t* WiFiClass::macAddress(uint8_t* mac)
{
    
}

IPAddress WiFiClass::subnetMask()
{
    
}

IPAddress WiFiClass::gatewayIP()
{
    
}

char* WiFiClass::SSID()
{
    
}

uint8_t* WiFiClass::BSSID(uint8_t* bssid)
{
    
}

int32_t WiFiClass::RSSI()
{
    
}

uint8_t WiFiClass::encryptionType()
{
    
}

int8_t WiFiClass::scanNetworks()
{
    
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

