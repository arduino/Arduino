///
/// @mainpage	GetMacAddress
///
/// @details	Get MAC address
/// @n
/// @n
/// @n @a		Developed with [embedXcode+](http://embedXcode.weebly.com)
///
/// @author		ReiVilo
/// @author		ReiVilo
/// @date		Sep 02, 2015 12:12
/// @version	102
///
/// @copyright	(c) ReiVilo, 2015
/// @copyright	CC = BY SA NC
///
/// @see		ReadMe.txt for references
///
/// @n @b   Example
/// @code
///     --- Get MAC address
///     Connecting to energia....connected
///     IP address............192.168.1.23
///     Signal (RSSI) -55 dBm
///     MAC address 11:22:33:44:55:66
///===
/// @endcode
///


// Core library for code-sense - IDE-based
#if defined(ENERGIA) // LaunchPad specific
#   include "Energia.h"
#else // error
#   error Platform not defined
#endif // end IDE

// Include application, user and local libraries
#ifndef __CC3200R1M1RGC__
// Do not include SPI for CC3200 LaunchPad
#include <SPI.h>
#endif
#include <WiFi.h>
/// Network name and password are in Credentials.h
#include "Credentials.h"

// Prototypes


// Define variables and constants


///
/// @brief	Network key index number, only for WEP
///
int keyIndex = 0;


///
/// @brief	Get MAC address
/// @return	MAC address
///
MACAddress getMacAddress()
{
    uint8_t macAddressVal[SL_MAC_ADDR_LEN];
    uint8_t macAddressLen = SL_MAC_ADDR_LEN;
    sl_NetCfgGet(SL_MAC_ADDRESS_GET,NULL,&macAddressLen,macAddressVal);
    MACAddress MAC(macAddressVal);
    return MAC;
}


///
/// @brief	Setup
///
void setup()

{
    Serial.begin(9600);
    delay(500);
    Serial.println("\n\n--- Get MAC address");
    
    // Connect to Wifi network
    Serial.print("Connecting to ");
    Serial.print(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(ssid, password);
    while ( WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println("connected");
    
    Serial.print("IP address");
    while (WiFi.localIP() == INADDR_NONE)
    {
        Serial.print(".");
        delay(300);
    }
    
    // IP address
    IPAddress ip = WiFi.localIP();
    Serial.println(ip);
    
    // Signal strenght
    long rssi = WiFi.RSSI();
    Serial.print("Signal (RSSI) ");
    Serial.print(rssi);
    Serial.println(" dBm");
    
    // MAC address
    Serial.print("MAC address ");
    Serial.println(getMacAddress());
    
    Serial.println("===");
}

///
/// @brief	Loop
///
void loop()
{

}
