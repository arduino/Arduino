/*
 TO DO:
    1) figure out key index for WEP connection, can it be ignored?
 X  2) use wlan even callback to determine if wifi has connected
 X  3) make sure the ip address octet order is correct in config method
 X  4) figure out how to get the SSID of the currently connected station
 X  5) how do you figure out what the index of the currently connected profile is?
 X  6) What's the appropriate socket type to use?
 X  7) Write net app event handler to wait for assigned ip (see tcp socket example)
 X  8) add local IP, subnet mask, and gateway ip methods as described in IPAddress class
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

#define DEBUG

#include <Energia.h>
#include "WiFi.h"
#include "utility/wl_definitions.h"
#include <xdc/runtime/System.h>

extern "C" {
    #include "utility/simplelink.h"
    #include <string.h>
    #include "utility/wlan.h"
    #include "utility/netcfg.h"
    #include "utility/netapp.h"
    #include "utility/socket.h"
}

//
//initialize WiFi_status to the disconnected flag
//
volatile wl_status_t WiFiClass::WiFi_status = WL_DISCONNECTED;
volatile uint32_t WiFiClass::local_IP = 0;
bool WiFiClass::_initialized = false;
bool WiFiClass::_connecting = false;
int8_t WiFiClass::role = ROLE_STA;
volatile int WiFiClass::network_count = 0;
char WiFiClass::fwVersion[] = {0};

//
// initialize AP mode static client registry variables
//
volatile unsigned int WiFiClass::_connectedDeviceCount = 0;
volatile unsigned int WiFiClass::_latestConnect = 0;
#ifdef __MSP430_HAS_FRAM__
__attribute__((section(".text")))
#endif
volatile wlanAttachedDevice_t WiFiClass::_connectedDevices[MAX_AP_DEVICE_REGISTRY];

//
//initialize the ssid and bssid to blank and 0s respectively
//
char WiFiClass::connected_ssid[32] = "";
unsigned char WiFiClass::connected_bssid[BSSID_LEN] = {0,0,0,0,0,0};

//
//a better way of keeping track of servers, clients, ports, and handles
//these provide a central hub for WiFiClient, WiFiServer, WiFiUDP to keep track
//
int16_t WiFiClass::_handleArray[MAX_SOCK_NUM];
int16_t WiFiClass::_portArray[MAX_SOCK_NUM];
int16_t WiFiClass::_typeArray[MAX_SOCK_NUM];
int16_t WiFiClass::_serverPortArray[MAX_SOCK_NUM];
#ifdef __MSP430_HAS_FRAM__
__attribute__((section(".text")))
#endif
WiFiClient WiFiClass::clients[MAX_SOCK_NUM];

//
//initializing pins for cc3100 for launchpad+boosterpack arrangement
//
uint8_t WiFiClass::pin_nhib = 5;
uint8_t WiFiClass::pin_cs = 18;
uint8_t WiFiClass::pin_irq = 19;

//
//These "buffers" are used to "return" strings and IpAddress objects
//Of course, the value must be used before it is overwritted
//
char WiFiClass::string_output_buffer[MAX_SSID_LEN];
IPAddress WiFiClass::ipaddress_output_buffer;

//--tested, working--//
WiFiClass::WiFiClass()
{
    //
    //Initialize the WiFi socket state arrays
    //
    int i;
    for (i = 0; i < MAX_SOCK_NUM; i++) {
        _handleArray[i] = _portArray[i] = _typeArray[i] = _serverPortArray[i] = -1;
    }
}

//--tested, working--//
bool WiFiClass::init()
{
    //
    //only initialize once
    //
    if (_initialized) {
        return true;
    }

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
    //set the mode to station if it's not already in station mode
    //
    if (iRet != ROLE_STA) {
        sl_WlanSetMode(ROLE_STA);
        sl_Stop(0);
        sl_Start(NULL, NULL, NULL);
    }
    
    //
    //disconnect from anything if for some reason it's connected
    //
    sl_WlanDisconnect();
    
    sl_NetAppMDNSUnRegisterService(0, 0);

    _initialized = true;
    
    //
    // Start collecting statistics
    //
    sl_WlanRxStatStart();

    return true;
}

void WiFiClass::setPinHIB(uint8_t pin)
{
    pin_nhib = pin;
}

void WiFiClass::setPinCS(uint8_t pin)
{
    pin_cs = pin;
}

void WiFiClass::setPinIRQ(uint8_t pin)
{
    pin_irq = pin;
}

//--tested, working--//
uint8_t WiFiClass::getSocket()
{
    //
    //return the first socket that is available
    //
    for (uint8_t i = 0; i < MAX_SOCK_NUM; ++i)
    {
        if (_handleArray[i] == -1)
        {
            return i;
        }
    }
    return NO_SOCKET_AVAIL;
}


const char * WiFiClass::driverVersion()
{
    return SL_DRIVER_VERSION;
}

//--tested, working--//
const char* WiFiClass::firmwareVersion()
{
    unsigned char ucConfigOpt = 0;
    unsigned char ucConfigLen = 0;

    SlVersionFull ver = {0};
    ucConfigOpt = SL_DEVICE_GENERAL_VERSION;
    ucConfigLen = sizeof(ver);
    sl_DevGet(SL_DEVICE_GENERAL_CONFIGURATION, &ucConfigOpt, 
                                &ucConfigLen, (unsigned char *)(&ver));
    
    System_snprintf(fwVersion, sizeof(fwVersion),
             "%ld.%ld.%ld.%ld:%ld.%ld.%ld.%ld:%d.%d.%d.%d",
    ver.NwpVersion[0], ver.NwpVersion[1], ver.NwpVersion[2], ver.NwpVersion[3],
    ver.ChipFwAndPhyVersion.FwVersion[0], ver.ChipFwAndPhyVersion.FwVersion[1],
    ver.ChipFwAndPhyVersion.FwVersion[2], ver.ChipFwAndPhyVersion.FwVersion[3],
    ver.ChipFwAndPhyVersion.PhyVersion[0], ver.ChipFwAndPhyVersion.PhyVersion[1],
    ver.ChipFwAndPhyVersion.PhyVersion[2], ver.ChipFwAndPhyVersion.PhyVersion[3]);

   return fwVersion;
}

void WiFiClass::setIpDefaults()
{
    //
    // If ip addess configuration was not set using config(),
    // set IP to DHCP.
    // Only check for IP address since without the IP address
    // being set, static IP configuration is useless?
    //
    if(local_IP == 0) {
        unsigned char val = 1;
        sl_NetCfgSet(SL_IPV4_STA_P2P_CL_DHCP_ENABLE,1,1,&val);
    }
}

int WiFiClass::begin()
{
    int8_t name[32];
    int16_t NameLen;

    if(_connecting) {
        delay(500);
        return status();
    }

    bool init_success = init();
    if (!init_success) {
        return WL_CONNECT_FAILED;
    }

    int16_t ret = sl_WlanProfileGet(0, name, (short int*)&NameLen, NULL, NULL, NULL, NULL);

    if(ret < 0) {
        return WL_CONNECT_FAILED;
    }

    sl_WlanPolicySet(SL_POLICY_CONNECTION , SL_CONNECTION_POLICY(1,1,0,0,0), 0, 0);

    _connecting = true;

    return WL_IDLE_STATUS;

}
//--tested, working--//
int WiFiClass::begin(char* ssid)
{
    //
    // If we already called begin and are already connecting
    // then return the status. This prevents sl_WlanConnect() 
    // from being called repeatedly.
    //
    if(_connecting) {
        delay(500);
        return status();
    }

    //
    //initialize the simplelink driver and make sure it was a success
    //
    bool init_success = init();
    if (!init_success) {
        return WL_CONNECT_FAILED;
    }

    sl_WlanProfileDel(WLAN_DEL_ALL_PROFILES);

    //
    // Set IP address configuration to DHCP if needed
    //
    setIpDefaults();

    sl_WlanPolicySet(SL_POLICY_CONNECTION , SL_CONNECTION_POLICY(1,1,0,0,0), 0, 0);

    //
    //Get name length and set security type to open
    //
    int NameLen = strlen(ssid);
    SlSecParams_t SecParams = {0};
    SecParams.Type = SL_SEC_TYPE_OPEN;
    
    //
    //Connect to the access point (non enterprise, so 5th argument is NULL);
    //also mac address parameter set as null (3rd argument)
    //
    int iRet = sl_WlanConnect((signed char*)ssid, NameLen, NULL, &SecParams, NULL);
    
    //
    //return appropriate status as described by arduino wifi library
    //the WiFiClass:WiFi_status is handled by the WlanEvenHandler
    //in SimpleLinkCallbacks.cpp. However, if iRet < 0, there was an error
    //
    if (iRet == 0) {
        sl_WlanProfileAdd((signed char*)ssid, NameLen, 0, &SecParams, 0, 6, 0);
        _connecting = true;
        return status();
    } else {
        return WL_CONNECT_FAILED;
    }
    
}


//!!Ignore key index!!//
int WiFiClass::begin(char* ssid, uint8_t key_idx, char* key)
{
    //
    // If we already called begin and are already connecting
    // then return the status. This prevents sl_WlanConnect() 
    // from being called repeatedly.
    //
    if(_connecting) {
        delay(500);
        return status();
    }
 
    //
    //initialize the simplelink driver and make sure it was a success
    //
    bool init_success = WiFiClass::init();
    if (!init_success) {
        return WL_CONNECT_FAILED;
    }

    sl_WlanProfileDel(WLAN_DEL_ALL_PROFILES);

    //
    // Set IP address configuration to DHCP if needed
    //
    setIpDefaults();

    sl_WlanPolicySet(SL_POLICY_CONNECTION , SL_CONNECTION_POLICY(1,1,0,0,0), 0, 0);

    //
    //get name length and set security type to WEP
    //add key and keylength to security parameters
    //
    int NameLen = strlen(ssid);
    SlSecParams_t SecParams = {0};
    SecParams.Type = SL_SEC_TYPE_WEP;
    SecParams.Key = (signed char *)key;
    SecParams.KeyLen = strlen(key);
    
    //
    //Connect to the access point (non enterprise, so 5th argument is NULL);
    //also mac address parameter set as null (3rd argument)
    //
    int iRet = sl_WlanConnect((signed char*)ssid, NameLen, NULL, &SecParams, NULL);
    
    //
    //return appropriate status as described by arduino wifi library
    //the WiFiClass:WiFi_status is handled by the WlanEvenHandler
    //in SimpleLinkCallbacks.cpp. However, if iRet < 0, there was an error
    //
    if (iRet == 0) {
        sl_WlanProfileAdd((signed char*)ssid, NameLen, 0, &SecParams, 0, 6, 0);
        _connecting = true;
        return status();
    } else {
        return WL_CONNECT_FAILED;
    }
    
}

//--tested, working--//
int WiFiClass::begin(char* ssid, char *passphrase)
{
    //
    // If we already called begin and are already connecting
    // then return the status. This prevents sl_WlanConnect() 
    // from being called repeatedly.
    //
    if(_connecting) {
        delay(500);
        return status();
    }

    //
    // Set IP address configuration to DHCP if needed
    //
    bool init_success = WiFiClass::init();
    if (!init_success) {
        return WL_CONNECT_FAILED;
    }

    sl_WlanProfileDel(WLAN_DEL_ALL_PROFILES);

    setIpDefaults();

    //
    //initialize the simplelink driver and make sure it was a success
    //
    sl_WlanPolicySet(SL_POLICY_CONNECTION , SL_CONNECTION_POLICY(1,1,0,0,0), 0, 0);

    //
    //get name length and set security type to WPA
    //add passphrase and keylength to security parameters
    //
    int NameLen = strlen(ssid);
    SlSecParams_t SecParams = {0};
    SecParams.Type = SL_SEC_TYPE_WPA;
    SecParams.Key = (signed char *)passphrase;
    SecParams.KeyLen = strlen(passphrase);
    
    //
    //connect to the access point (non enterprise, so 5th argument is NULL)
    //also mac address parameters set as null (3rd argument)
    //
    int iRet = sl_WlanConnect((signed char *)ssid, NameLen, NULL, &SecParams, NULL);

    //
    //return appropriate status as described by arduino wifi library
    //the WiFiClass:WiFi_status is handled by the WlanEvenHandler
    //in SimpleLinkCallbacks.cpp. However, if iRet < 0, there was an error
    //
    if (iRet == 0) {
        sl_WlanProfileAdd((signed char *)ssid, NameLen, 0, &SecParams, 0, 6, 0);
        _connecting = true;
        return status();
    } else {
        return WL_CONNECT_FAILED;
    }
}

int WiFiClass::beginNetwork(char *ssid)
{
    long   retVal = -1;
    int i;

    if (!_initialized) {
        init();
    }

    // Initialize the AP-mode Connected Device array
    WiFiClass::_connectedDeviceCount = 0;
    _latestConnect = 0;
    for (i = 0; i < MAX_AP_DEVICE_REGISTRY; i++) {
        _connectedDevices[i].in_use = false;
        memset((uint8_t *)_connectedDevices[i].ipAddress, 0, 4);
        memset((uint8_t *)_connectedDevices[i].mac, 0, 6);
    }

    retVal = sl_WlanSetMode(ROLE_AP);

    retVal = sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_SSID, strlen(ssid),
                            (unsigned char *)ssid);

    /* Restart Network processor */
    retVal = sl_Stop(30);

    role = ROLE_AP;
    return (retVal == 0 ? sl_Start(NULL, NULL, NULL) : retVal);
}

int WiFiClass::beginNetwork(char *ssid, char *passphrase)
{
    long   retVal = -1;
    int i;

    if (!_initialized) {
        init();
    }

    // Initialize the AP-mode Connected Device array
    WiFiClass::_connectedDeviceCount = 0;
    _latestConnect = 0;
    for (i = 0; i < MAX_AP_DEVICE_REGISTRY; i++) {
        _connectedDevices[i].in_use = false;
        memset((uint8_t *)_connectedDevices[i].ipAddress, 0, 4);
        memset((uint8_t *)_connectedDevices[i].mac, 0, 6);
    }

    retVal = sl_WlanSetMode(ROLE_AP);

    retVal = sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_SSID, strlen(ssid),
                            (unsigned char *)ssid);

    unsigned char  val = SL_SEC_TYPE_WPA;
    retVal = sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_SECURITY_TYPE, 1, (unsigned char *)&val);

    retVal = sl_WlanSet(SL_WLAN_CFG_AP_ID, WLAN_AP_OPT_PASSWORD, strlen(passphrase),
                            (unsigned char *)passphrase);

    /* Restart Network processor */
    retVal = sl_Stop(30);

    role = ROLE_AP;
    return (retVal == 0 ? sl_Start(NULL, NULL, NULL) : retVal);
}


void WiFiClass::config(IPAddress local_ip)
{
    if (!_initialized) {
        init();
    }

    //
    // Set the local_IP indicating that the network
    // is configured for static IP.
    //
    local_IP = local_ip;

    //
    //get current configuration
    //
    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = sl_Ntohl((uint32_t)local_ip);
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(SlNetCfgIpV4Args_t), (unsigned char*)&config);
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server)
{
    if (!_initialized) {
        init();
    }

    //
    // Set the local_IP indicating that the network
    // is configured for static IP.
    //
    local_IP = local_ip;

    //
    //get current configuration
    //
    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = sl_Ntohl((uint32_t)local_ip);
    config.ipV4DnsServer = sl_Ntohl((uint32_t)dns_server);
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(SlNetCfgIpV4Args_t), (unsigned char*)&config);
    
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway)
{
    if (!_initialized) {
        init();
    }

    //
    // Set the local_IP indicating that the network
    // is configured for static IP.
    //
    local_IP = local_ip;

    //
    //get current configuration
    //
    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = sl_Ntohl((uint32_t)local_ip);
    config.ipV4DnsServer = sl_Ntohl((uint32_t)dns_server);
    config.ipV4Gateway = sl_Ntohl((uint32_t)gateway);
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(SlNetCfgIpV4Args_t), (unsigned char*)&config);
    
}

void WiFiClass::config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet)
{
    if (!_initialized) {
        init();
    }

    //
    // Set the local_IP indicating that the network
    // is configured for static IP.
    //
    local_IP = local_ip;

    //
    //get current configuration
    //
    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4 = sl_Ntohl((uint32_t)local_ip);
    config.ipV4DnsServer = sl_Ntohl((uint32_t)dns_server);
    config.ipV4Gateway = sl_Ntohl((uint32_t)gateway);
    config.ipV4Mask = sl_Ntohl((uint32_t)subnet);
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(SlNetCfgIpV4Args_t), (unsigned char*)&config);
    
}


void WiFiClass::setDNS(IPAddress dns_server1)
{
    if (!_initialized) {
        init();
    }
    //
    //get current configuration
    //
    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //Assign new ip address and new dns server to current config
    //and use netcfgset to set the new configuration in memory
    //
    config.ipV4DnsServer = (uint32_t)SL_IPV4_VAL(dns_server1[0], dns_server1[1], dns_server1[2], dns_server1[3]);
    sl_NetCfgSet(SL_IPV4_STA_P2P_CL_STATIC_ENABLE, 1, sizeof(SlNetCfgIpV4Args_t), (unsigned char*)&config);
}


//--Not supported? Only set the dns server using the first address--//
void WiFiClass::setDNS(IPAddress dns_server1, IPAddress dns_server2)
{
    if (!_initialized) {
        init();
    }
    //
    //because only 1 dns server is supported, use the previous set dns function
    //
    WiFiClass::setDNS(dns_server1);
}

int WiFiClass::disconnect(void)
{
    if (!_initialized) {
        init();
    }
    //
    //disconnect from the wlan and return the current wlan_status
    //
    sl_WlanDisconnect();
    return WiFi_status;
}

unsigned int WiFiClass::getTotalDevices(void)
{
#ifdef SL_PLATFORM_MULTI_THREADED
#else
    _SlNonOsMainLoopTask();
#endif
    return WiFiClass::_connectedDeviceCount;
}

uint8_t* WiFiClass::macAddress(uint8_t* mac)
{
    if (!_initialized) {
        init();
    }
    //
    //Get the mac address and return the pointer to the array
    //
    uint8_t macTemp[6];
    uint8_t macLength = 6;
    sl_NetCfgGet(SL_MAC_ADDRESS_GET, NULL, &macLength, (unsigned char *)macTemp);

    //
    //All the arduino examples return the mac address reverse from simplelink
    //
    memcpy(mac, macTemp, 6);
    
    return mac;
}

//--tested, working--//
IPAddress WiFiClass::localIP()
{
    //
    //the local IP is maintained with callbacks, so _SlNonOsMainLoopTask()
    //is critical. The IP is "written" into the buffer to avoid memory errors
    //
    _SlNonOsMainLoopTask();

    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);

    //
    //change the uint32_t IP to the IPAddress class and return
    //
    IPAddress retIP(0,0,0,0);
    retIP = sl_Htonl(config.ipV4);
    return retIP;
}

//--tested, working--//
IPAddress WiFiClass::subnetMask()
{
    if (!_initialized) {
        init();
    }
    //
    //get current configuration
    //
    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //change the uint32_t IP to the IPAddress class and return
    //
    IPAddress retIP(0,0,0,0);
    retIP = sl_Htonl(config.ipV4Mask);
    return retIP;
    
}

//--tested, working--//
IPAddress WiFiClass::gatewayIP()
{
    if (!_initialized) {
        init();
    }
    //
    //get current configuration
    //
    SlNetCfgIpV4Args_t config = {0};
    unsigned char len = sizeof(SlNetCfgIpV4Args_t);
    sl_NetCfgGet(SL_IPV4_STA_P2P_CL_GET_INFO, NULL, &len, (unsigned char*)&config);
    
    //
    //change the uint32_t IP to the IPAddress class and return
    //
    IPAddress retIP(0,0,0,0);
    retIP = sl_Htonl(config.ipV4Gateway);
    return retIP;
}

//--tested, working--//
char* WiFiClass::SSID()
{
    if (!_initialized) {
        init();
    }

    //
    //connected_ssid maintained by wlan event handler (SimpleLinkCallbacks.cpp)
    //when in station mode. For AP mode use sl_WlanGet to obtain the SSID.
    //
    if(role == ROLE_STA)
        return (char*)WiFiClass::connected_ssid;

    char ssid[32];
    unsigned short len = 32;
    unsigned short  config_opt = WLAN_AP_OPT_SSID;
    sl_WlanGet(SL_WLAN_CFG_AP_ID, &config_opt , &len, (unsigned char*)ssid);

    strcpy(string_output_buffer, ssid);
    return string_output_buffer;
}

//--tested, working--//
uint8_t* WiFiClass::BSSID(uint8_t* bssid)
{
    if (!_initialized) {
        init();
    }

    if (bssid != NULL) {
        memcpy(bssid, WiFiClass::connected_bssid, BSSID_LEN);
    }

    return bssid;
}


int32_t WiFiClass::RSSI()
{
    long lRetVal = -1;

    if (WiFi.status() != WL_CONNECTED) {
        return 0;
    }

    SlGetRxStatResponse_t rxStatResp;

    lRetVal = sl_WlanRxStatGet(&rxStatResp,0);
    if (lRetVal < 0) {
        return 0;
    }

    return rxStatResp.AvarageMgMntRssi;
}

//!! How to get the current connection??!!//
uint8_t WiFiClass::encryptionType()
{
    return 0;
}

//--tested, working--//
int8_t WiFiClass::scanNetworks()
{
    if (!_initialized) {
        init();
    }

    const int WLAN_SCAN_COUNT = 20;
    int iRet;
    
    unsigned char ucpolicyOpt;
    union
    {
        unsigned char ucPolicy[4];
        unsigned int uiPolicyLen;
    }policyVal;
    
    //
    // make sure the connection policy is not set (so no scan is run in the background)
    //
    ucpolicyOpt = SL_CONNECTION_POLICY(0, 0, 0, 0, 0);
    iRet = sl_WlanPolicySet(SL_POLICY_CONNECTION , ucpolicyOpt, NULL, 0);
    if(iRet != 0)
    {
        sl_WlanPolicySet(SL_POLICY_CONNECTION , SL_CONNECTION_POLICY(1,1,0,0,0), 0, 0);
        return 0;
    }

    //
    // set the scan policy for ten seconds. This starts the scan.
    //
    policyVal.uiPolicyLen = 10;
    iRet = sl_WlanPolicySet(SL_POLICY_SCAN , SL_SCAN_POLICY(1), (unsigned char *)(policyVal.ucPolicy), sizeof(policyVal));
    if(iRet != 0)
    {
        sl_WlanPolicySet(SL_POLICY_CONNECTION , SL_CONNECTION_POLICY(1,1,0,0,0), 0, 0);
        return 0;
    }
    delay(300);
    
    //
    // get scan results - all 20 entries in one transaction
    // this array isn't actually used, but you have to do this to get the count
    //
    Sl_WlanNetworkEntry_t found_networks[WLAN_SCAN_COUNT];
    network_count = sl_WlanGetNetworkList(0, (unsigned char)WLAN_SCAN_COUNT, found_networks);
    
    //
    // disable scan
    //
    ucpolicyOpt = SL_SCAN_POLICY(0);
    sl_WlanPolicySet(SL_POLICY_SCAN , ucpolicyOpt, NULL, 0);
    sl_WlanPolicySet(SL_POLICY_CONNECTION , SL_CONNECTION_POLICY(1,1,0,0,0), 0, 0);
    
    return network_count;
    
}

//--tested, working--//
char* WiFiClass::SSID(uint8_t networkItem)
{
    if (!_initialized) {
        init();
    }
    //
    //get the network list and return the ssid of the requested index
    //
    if (networkItem >= network_count) {
        return NULL;
    }
    
    //
    //fetch all 20 items. For some reason, fetching a single item doesn't work
    //
    Sl_WlanNetworkEntry_t netInfo[network_count];
    memset(&netInfo, 0, sizeof(netInfo));
    sl_WlanGetNetworkList(0, network_count, (Sl_WlanNetworkEntry_t*)&netInfo);

    strcpy(string_output_buffer, (char*)netInfo[networkItem].ssid);
    return  string_output_buffer;
    
}

//--tested, working--//
uint8_t WiFiClass::encryptionType(uint8_t networkItem)
{
    if (!_initialized) {
        init();
    }
    //
    //get the network list and pull out the security type of the requested item
    //
    if (networkItem >= network_count) {
        return 0;
    }

    //
    //fetch all 20 items. For some reason, fetching a signle item doesn't work
    //
    Sl_WlanNetworkEntry_t netInfo[network_count];
    memset(&netInfo, 0, sizeof(netInfo));
    sl_WlanGetNetworkList(0, network_count, (Sl_WlanNetworkEntry_t*)&netInfo);
    
    uint8_t security = netInfo[networkItem].sec_type;
    
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
    } else if (security == SL_SEC_TYPE_WPS_PBC){
        return 2;
    } else if (security == SL_SEC_TYPE_WPS_PIN){
        return 2;
    } else {
        return 8;
    }
}

//--tested, working--//
int32_t WiFiClass::RSSI(uint8_t networkItem)
{
    if (!_initialized) {
        init();
    }
    //
    //get the network list and pull out the security type of the requested item
    //
    if (networkItem >= network_count) {
        return 0;
    }
    
    //
    //fetch all 20 items. For some reason, fetching a single item doesn't work
    //
    Sl_WlanNetworkEntry_t netInfo[network_count];
    memset(&netInfo, 0, sizeof(netInfo));
    sl_WlanGetNetworkList(0, network_count, (Sl_WlanNetworkEntry_t*)&netInfo);
    
    return (int32_t)netInfo[networkItem].rssi;
}

//--tested, working--//
uint8_t WiFiClass::status()
{
    if (!_initialized) {
        init();
    }

    if(role == ROLE_AP)
        return WL_AP_MODE;
    //
    //This class variable is maintained by the slWlanEvenHandler
    //
    _SlNonOsMainLoopTask();
    return WiFi_status;
}

//--tested, working--//
int WiFiClass::hostByName(char* aHostname, IPAddress& aResult)
{
    if (!_initialized) {
        init();
    }
    //
    //Use the netapp api to resolve an IP for the requested hostname
    //
    unsigned long DestinationIP;
    int iRet = sl_NetAppDnsGetHostByName((signed char *)aHostname, strlen(aHostname), &DestinationIP, SL_AF_INET);
    aResult = sl_Htonl(DestinationIP);
    
    if (iRet >= 0) {
        return 1;
    } else {
        return iRet;
    }
    
}

int WiFiClass::startSmartConfig(bool block)
{
    unsigned char policyVal;

    if (!_initialized) {
        init();
    }

    sl_WlanProfileDel(WLAN_DEL_ALL_PROFILES);

    sl_WlanSmartConfigStart(0,  //groupIdBitmask
        SMART_CONFIG_CIPHER_NONE, //cipher
        0,                        //publicKeyLen
        0,                        //group1KeyLen
        0,                        //group2KeyLen
        NULL,                     //publicKey
        NULL,                     //group1Key
        NULL);                    //group2Key

    if (sl_WlanPolicySet(SL_POLICY_CONNECTION, SL_CONNECTION_POLICY(1,0,0,0,0), &policyVal, 1 /*PolicyValLen*/) < 0) {
        return -1;
    }


    if(!block) {
        return 0;
    }

    /* Block until connected */
    while (WiFi.status() != WL_CONNECTED) {
#ifndef SL_PLATFORM_MULTI_THREADED
        // TODO: this call appears unnecessary: status() already calls sl_Task
        sl_Task();
#else
        // TODO: is 10 appropriate?  to save power, shouldn't we always delay?
        delay(10);
#endif
    }

    return 0;
}

/* This function takes uint16_t arguments for compactness on MSP430 w/ CC3100, but actual SlDateTime_t members are uint32_t.
 */
boolean WiFiClass::setDateTime(uint16_t month, uint16_t day, uint16_t year, uint16_t hour, uint16_t minute, uint16_t second)
{
    if (day < 1 || day > 31 || month < 1 || month > 12 || hour > 23 || minute > 59 || second > 59)
        return false;

    SlDateTime_t dt;
    dt.sl_tm_day = (uint32_t)day;
    dt.sl_tm_mon = (uint32_t)month;
    dt.sl_tm_year = (uint32_t)year;
    dt.sl_tm_hour = (uint32_t)hour;
    dt.sl_tm_min = (uint32_t)minute;
    dt.sl_tm_sec = (uint32_t)second;

    int32_t i = sl_DevSet(SL_DEVICE_GENERAL_CONFIGURATION, SL_DEVICE_GENERAL_CONFIGURATION_DATE_TIME,
                          sizeof(SlDateTime_t), (uint8_t *)&dt);
    if (i != 0)
        return false;
    return true;
}

/* Register a new client who has attached to us in AP mode! */
void WiFiClass::_registerNewDeviceIP(unsigned char *ip, unsigned char *mac)
{
    int i;

    // Have we seen this client attach yet?
    for (i=0; i < MAX_AP_DEVICE_REGISTRY; i++) {
        if (_connectedDevices[i].in_use && !memcmp((uint8_t *)(_connectedDevices[i].mac), mac, 6)) {
            // We have; update the IP and exit.
            memcpy((uint8_t *)(_connectedDevices[i].ipAddress), ip, 4);
            _latestConnect = i;
            return;
        }
    }
    // If not, add this client as a new entry.
    for (i=0; i < MAX_AP_DEVICE_REGISTRY; i++) {
        if (!_connectedDevices[i].in_use) {
            _connectedDevices[i].in_use = true;
            memcpy((uint8_t *)(_connectedDevices[i].ipAddress), ip, 4);
            memcpy((uint8_t *)(_connectedDevices[i].mac), mac, 6);
            /* Note: We don't update _latestConnect b/c the only time we reach this code block
             * is when the client attaches but has not yet obtained an IP address; thus there's
             * nothing we can do with that client (connect, etc) anyway.
             */
            return;
        }
    }
    // No slots left for new clients; exit without registering them.
    return;
}

/* Deregister a client by MAC address. */
void WiFiClass::_unregisterDevice(unsigned char *mac)
{
    int i;

    // Find the client
    for (i=0; i < MAX_AP_DEVICE_REGISTRY; i++) {
        if (_connectedDevices[i].in_use && !memcmp((uint8_t *)(_connectedDevices[i].mac), mac, 6)) {
            // We have; set in_use to false.
            _connectedDevices[i].in_use = false;
            return;
        }
    }
    // Didn't find them?  Too bad, nothing to see here...
    return;
}

/* Print a specified IP/MAC from the connected device list. */
IPAddress WiFiClass::deviceIpAddress(unsigned int idx)
{
    int i = 0, j = 0;

    // Find the client
    do {
        if (_connectedDevices[i].in_use) {
            if (j == idx) {
                return IPAddress((uint8_t *)_connectedDevices[i].ipAddress);
            }
            j++;
        }
        i++;
    } while (i < MAX_AP_DEVICE_REGISTRY);

    // Not found!
    return INADDR_NONE;
}

MACAddress WiFiClass::deviceMacAddress(unsigned int idx)
{
    int i = 0, j = 0;

    // Find the client
    do {
        if (_connectedDevices[i].in_use) {
            if (j == idx) {
                return MACAddress((uint8_t *)_connectedDevices[i].mac);
            }
            j++;
        }
        i++;
    } while (i < MAX_AP_DEVICE_REGISTRY);

    // Not found!
    return MACADDR_NONE;
}

/* Find an IP address based on a recorded MAC address (6-byte binary format) */
IPAddress WiFiClass::deviceIpByMacAddress(MACAddress mac)
{
    int i = 0;

    // Search by MAC
    for (i=0; i < MAX_AP_DEVICE_REGISTRY; i++) {
        if (_connectedDevices[i].in_use) {
            if ( mac == (uint8_t *)_connectedDevices[i].mac ) {
                return IPAddress((uint8_t *)_connectedDevices[i].ipAddress);
            }
        }
    }

    // Not found!
    return INADDR_NONE;
}

/* Return a MAC address based on a recorded IP address */
MACAddress WiFiClass::deviceMacByIpAddress(IPAddress ip)
{
    int i = 0;

    // Search by IP
    for (i=0; i < MAX_AP_DEVICE_REGISTRY; i++) {
        if (_connectedDevices[i].in_use) {
            if ( ip == (uint8_t *)_connectedDevices[i].ipAddress ) {
                return MACAddress((uint8_t *)_connectedDevices[i].mac);
            }
        }
    }

    // Not found!
    return MACADDR_NONE;
}



WiFiClass WiFi;



