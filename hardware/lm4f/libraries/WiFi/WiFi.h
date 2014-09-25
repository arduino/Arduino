/*
 WiFi.h - Adaptation of Arduino WiFi library for Energia and CC3200 launchpad
 Modified: Noah Luskey | LuskeyNoah@gmail.com
 
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

#ifndef WiFi_h
#define WiFi_h

#include <Energia.h>
#include "IPAddress.h"
#include "utility/wl_definitions.h"
#include "utility/SimpleLink.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"
//
//Max socket number is 8
//
#define MAX_SOCK_NUM 8
#define MAX_SSID_LEN 32
#define BSSID_LEN 6
#define WLAN_DEL_ALL_PROFILES 0xff
#define WL_FW_VER_LENGTH 64

class WiFiClass
{
private:
    static WiFiClient clients[MAX_SOCK_NUM];
    static int8_t role;
    static char fwVersion[WL_FW_VER_LENGTH];
public:
    static int16_t _handleArray[MAX_SOCK_NUM];
    static int16_t _portArray[MAX_SOCK_NUM];
    static int16_t _typeArray[MAX_SOCK_NUM];
    
    static bool _initialized;
    static bool init();
    volatile static int network_count;
    
    //
    //variables maintined by the simplelink callbacks
    //
    volatile static uint32_t local_IP;
    volatile static wl_status_t WiFi_status;
    
    //
    //Because simplelink doesn't provide an easy way to get the ssid or bssid
    //these class variables are maintained by the WlanEventHandler callback
    //
    static char connected_ssid[MAX_SSID_LEN];
    static unsigned char connected_bssid[BSSID_LEN];
    
    //
    //pin numbers for the cc3100 device (based on launchpad)
    //and methods to change them (function names based on silkscreen for consistency)
    //
    static uint8_t pin_nhib;
    static uint8_t pin_cs;
    static uint8_t pin_irq;
    void setPinHIB(uint8_t pin);
    void setPinIRQ(uint8_t pin);
    void setPinCS(uint8_t pin);

    //
    //These "buffers" are used to "return" strings and IpAddress objects
    //Of course, the value must be used before it is overwritted
    //
    static char string_output_buffer[MAX_SSID_LEN];
    static IPAddress ipaddress_output_buffer;
    
    WiFiClass();
    
    /*
     * Get the first socket available
     */
    static uint8_t getSocket();
    
    /*
     * Get firmware and driver version
     */
    char* firmwareVersion();
    char* driverVersion();
    
    /* Start WiFi in AP mode with OPEN network
     *
     * param ssid: Pointer to the SSID string.
     */
    int beginNetwork(char *ssid);

    /* Start WiFi in AP mode with WPA network
     *
     * param ssid: Pointer to the SSID string.
     * param passphrase: Passphrase. Valid characters in a passphrase
     *        must be between ASCII 32-126 (decimal).
     */
    int beginNetwork(char *ssid, char *passphrase);

    /* Start Wifi connection for OPEN network
     *
     * param ssid: Pointer to the SSID string.
     */

    int begin(char* ssid);
    
    /* Start Wifi connection with WEP encryption.
     * Configure a key into the device. The key type (WEP-40, WEP-104)
     * is determined by the size of the key (5 bytes for WEP-40, 13 bytes for WEP-104).
     *
     * param ssid: Pointer to the SSID string.
     * param key_idx: The key index to set. Valid values are 0-3.
     * param key: Key input buffer.
     */
    int begin(char* ssid, uint8_t key_idx, char* key);
    
    /* Start Wifi connection with passphrase
     * the most secure supported mode will be automatically selected
     *
     * param ssid: Pointer to the SSID string.
     * param passphrase: Passphrase. Valid characters in a passphrase
     *        must be between ASCII 32-126 (decimal).
     */
    int begin(char* ssid, char *passphrase);
    
    /* Change Ip configuration settings disabling the dhcp client
     *
     * param local_ip: 	Static ip configuration
     */
    void config(IPAddress local_ip);
    
    /* Change Ip configuration settings disabling the dhcp client
     *
     * param local_ip: 	Static ip configuration
     * param dns_server:     IP configuration for DNS server 1
     */
    void config(IPAddress local_ip, IPAddress dns_server);
    
    /* Change Ip configuration settings disabling the dhcp client
     *
     * param local_ip: 	Static ip configuration
     * param dns_server:     IP configuration for DNS server 1
     * param gateway : 	Static gateway configuration
     */
    void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
    
    /* Change Ip configuration settings disabling the dhcp client
     *
     * param local_ip: 	Static ip configuration
     * param dns_server:     IP configuration for DNS server 1
     * param gateway: 	Static gateway configuration
     * param subnet:		Static Subnet mask
     */
    void config(IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
    
    /* Change DNS Ip configuration
     *
     * param dns_server1: ip configuration for DNS server 1
     */
    void setDNS(IPAddress dns_server1);
    
    /* Change DNS Ip configuration
     *
     * param dns_server1: ip configuration for DNS server 1
     * param dns_server2: ip configuration for DNS server 2
     *
     */
    void setDNS(IPAddress dns_server1, IPAddress dns_server2);
    
    /*
     * Disconnect from the network
     *
     * return: one value of wl_status_t enum
     */
    int disconnect(void);
    
    /*
     * Get the interface MAC address.
     *
     * return: pointer to uint8_t array with length WL_MAC_ADDR_LENGTH
     */
    uint8_t* macAddress(uint8_t* mac);
    
    /*
     * Get the interface IP address.
     *
     * return: Ip address value
     */
    IPAddress localIP();
    
    /*
     * Get the interface subnet mask address.
     *
     * return: subnet mask address value
     */
    IPAddress subnetMask();
    
    /*
     * Get the gateway ip address.
     *
     * return: gateway ip address value
     */
    IPAddress gatewayIP();
    
    /*
     * Return the current SSID associated with the network
     *
     * return: ssid string
     */
    char* SSID();
    
    /*
     * Return the current BSSID associated with the network.
     * It is the MAC address of the Access Point
     *
     * return: pointer to uint8_t array with length WL_MAC_ADDR_LENGTH
     */
    uint8_t* BSSID(uint8_t* bssid);
    
    /*
     * Return the current RSSI /Received Signal Strength in dBm)
     * associated with the network
     *
     * return: signed value
     */
    int32_t RSSI();
    
    /*
     * Return the Encryption Type associated with the network
     *
     * return: one value of wl_enc_type enum
     */
    uint8_t	encryptionType();
    
    /*
     * Start scan WiFi networks available
     *
     * return: Number of discovered networks
     */
    int8_t scanNetworks();
    
    /*
     * Return the SSID discovered during the network scan.
     *
     * param networkItem: specify from which network item want to get the information
     *
     * return: ssid string of the specified item on the networks scanned list
     */
    char*	SSID(uint8_t networkItem);
    
    /*
     * Return the encryption type of the networks discovered during the scanNetworks
     *
     * param networkItem: specify from which network item want to get the information
     *
     * return: encryption type (enum wl_enc_type) of the specified item on the networks scanned list
     */
    uint8_t	encryptionType(uint8_t networkItem);
    
    /*
     * Return the RSSI of the networks discovered during the scanNetworks
     *
     * param networkItem: specify from which network item want to get the information
     *
     * return: signed value of RSSI of the specified item on the networks scanned list
     */
    int32_t RSSI(uint8_t networkItem);
    
    /*
     * Return Connection status.
     *
     * return: one of the value defined in wl_status_t
     */
    uint8_t status();
    
    /*
     * Resolve the given hostname to an IP address.
     * param aHostname: Name to be resolved
     * param aResult: IPAddress structure to store the returned IP address
     * result: 1 if aIPAddrString was successfully converted to an IP address,
     *          else error code
     */
    int hostByName(char* aHostname, IPAddress& aResult);
    
    /*
     * Start Smartconfig.
     * return: 1 if SmartConfig was successfully configured, otherwise -1.
     */
    int startSmartConfig();

    /*
     * Set WiFi network processor Date/Time
     * Params: month (1-12), day (1-31), year, hour (0-23), minute (0-59), second (0-59)
     * return: true if successful, false if invalid parameters were supplied (or sl_DevSet() returned an error)
     */
    boolean setDateTime(uint16_t month, uint16_t day, uint16_t year, uint16_t hour, uint16_t minute, uint16_t second);


    friend class WiFiClient;
    friend class WiFiServer;
};

extern WiFiClass WiFi;

#endif
