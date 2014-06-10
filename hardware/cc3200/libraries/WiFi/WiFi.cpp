/*
 WiFi.cpp - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 Modified: Noah Luskey
 
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


extern "C" {
    #include "SimpleLink.h"
    #include <string.h>
    #include "wlan.h"
}


WiFiClass::WiFiClass()
{
    //simplelink driver initialization
    init();
}

void WiFiClass::init()
{
    //
    //start the SimpleLink device
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

static char* WiFiClass::firmwareVersion()
{
    
}

int WiFiClass::begin(char* ssid)
{
    //
    //Get name length and set security type to open
    //
    int NameLen = strlen(ssid);
    SlSecParams_t* pSecParams = SL_SEC_TYPE_OPEN;
    
    //
    //Connect to the access point (non enterprise, so 5th argument is NULL);
    //
    int iRet = sl_WlanConnect(ssid, NameLen, pMacAddr, pSecParams, NULL);
    return iRet;
}

int WiFiClass::begin(char* ssid, uint8_t key_idx, const char* key)
{
    
}

int WiFiClass::begin(char* ssid, const char *passphrase)
{
    
}

void WiFiClass::WiFiconfig(IPAddress local_ip)
{
    
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server)
{
    
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway)
{
    
}

void WifiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet)
{
    
}

void WiFiClass::setDNS(IPAddress dns_server1)
{

}

void WiFiClass::setDNS(IPAddress dns_server1, IPAddress dns_server2)
{
    
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

char* WiFiClass::gatewayIP()
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

uint8_t WiFiClass::encyptionType()
{
    
}

int8_t WiFiClass::scanNetworks()
{
    
}

char* WiFiClass::SSID(uint8_t networkItem)
{
    
}

uint8_t encryptionType(uint8_t networkItem)
{
    
}

int32_t RSSI(uint8_t networkItem)
{
    
}

uint8_t WiFiClass::status()
{
    
}

int WiFiClass::hostByName(const char* aHostname, IPAddress& aResult)
{
    
}

