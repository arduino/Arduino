/*==============================================================================
 * WIFI CONFIGURATION
 *
 * You must configure your particular hardware. Follow the steps below.
 *
 * By default, StandardFirmataWiFi is configured as a TCP server, to configure
 * as a TCP client, see STEP 2.
 *============================================================================*/

// STEP 1 [REQUIRED]
// Uncomment / comment the appropriate set of includes for your hardware (OPTION A, B or C)
// Arduino MKR1000 or ESP8266 are enabled by default if compiling for either of those boards.

/*
 * OPTION A: Configure for Arduino MKR1000 or Arduino WiFi Shield 101
 *
 * This will configure StandardFirmataWiFi to use the WiFi101 library, which works with the
 * Arduino WiFi101 shield and devices that have the WiFi101 chip built in (such as the MKR1000).
 * It is compatible with 802.11 B/G/N networks.
 *
 * If you are using the MKR1000 board, continue on to STEP 2. If you are using the WiFi 101 shield,
 * follow the instructions below.
 *
 * To enable for the WiFi 101 shield, uncomment the #define WIFI_101 below and verify the
 * #define ARDUINO_WIFI_SHIELD is commented out for OPTION B.
 *
 * IMPORTANT: You must have the WiFI 101 library installed. To easily install this library, open
 * the library manager via: Arduino IDE Menus: Sketch > Include Library > Manage Libraries > filter
 * search for "WiFi101" > Select the result and click 'install'
 */
//#define WIFI_101

//do not modify the following 11 lines
#if defined(ARDUINO_SAMD_MKR1000) && !defined(WIFI_101)
// automatically include if compiling for MRK1000
#define WIFI_101
#endif
#ifdef WIFI_101
#include <WiFi101.h>
#include "utility/WiFiClientStream.h"
#include "utility/WiFiServerStream.h"
  #define WIFI_LIB_INCLUDED
#endif

/*
 * OPTION B: Configure for legacy Arduino WiFi shield
 *
 * This will configure StandardFirmataWiFi to use the original WiFi library (deprecated) provided
 * with the Arduino IDE. It is supported by the Arduino WiFi shield (a discontinued product) and
 * is compatible with 802.11 B/G networks.
 *
 * To configure StandardFirmataWiFi to use the legacy Arduino WiFi shield
 * leave the #define below uncommented and ensure #define WIFI_101 is commented out for OPTION A.
 */
//#define ARDUINO_WIFI_SHIELD

//do not modify the following 10 lines
#ifdef ARDUINO_WIFI_SHIELD
#include <WiFi.h>
#include "utility/WiFiClientStream.h"
#include "utility/WiFiServerStream.h"
  #ifdef WIFI_LIB_INCLUDED
  #define MULTIPLE_WIFI_LIB_INCLUDES
  #else
  #define WIFI_LIB_INCLUDED
  #endif
#endif

/*
 * OPTION C: Configure for ESP8266
 *
 * This will configure StandardFirmataWiFi to use the ESP8266WiFi library for boards
 * with an ESP8266 chip. It is compatible with 802.11 B/G/N networks.
 *
 * The appropriate libraries are included automatically when compiling for the ESP8266 so
 * continue on to STEP 2.
 *
 * IMPORTANT: You must have the esp8266 board support installed. To easily install this board see
 * the instructions here: https://github.com/esp8266/Arduino#installing-with-boards-manager.
 */
//do not modify the following 14 lines
#ifdef ESP8266
// automatically include if compiling for ESP8266
#define ESP8266_WIFI
#endif
#ifdef ESP8266_WIFI
#include <ESP8266WiFi.h>
#include "utility/WiFiClientStream.h"
#include "utility/WiFiServerStream.h"
  #ifdef WIFI_LIB_INCLUDED
  #define MULTIPLE_WIFI_LIB_INCLUDES
  #else
  #define WIFI_LIB_INCLUDED
  #endif
#endif

/*
 * OPTION D: Configure for HUZZAH
 *
 * HUZZAH with CC3000 is not yet supported, this will be added in a later revision to
 * StandardFirmataWiFi.
 * For HUZZAH with ESP8266 use ESP8266_WIFI.
 */

//------------------------------
// TODO
//------------------------------
//#define HUZZAH_WIFI


// STEP 2 [OPTIONAL for all boards and shields]
// If you want to setup you board as a TCP client, uncomment the following define and replace
// the IP address with the IP address of your server.
//#define SERVER_IP 10, 0, 0, 15


// STEP 3 [REQUIRED for all boards and shields]
// replace this with your wireless network SSID
char ssid[] = "your_network_name";


// STEP 4 [OPTIONAL for all boards and shields]
// If you want to use a static IP (v4) address, uncomment the line below. You can also change the IP.
// If the first line is commented out, the WiFi shield will attempt to get an IP from the DHCP server.
// If you are using a static IP with the ESP8266 then you must also uncomment the SUBNET and GATEWAY.
//#define STATIC_IP_ADDRESS  192,168,1,113
//#define SUBNET_MASK        255,255,255,0 // REQUIRED for ESP8266_WIFI, optional for others
//#define GATEWAY_IP_ADDRESS 0,0,0,0       // REQUIRED for ESP8266_WIFI, optional for others


// STEP 5 [REQUIRED for all boards and shields]
// define your port number here, you will need this to open a TCP connection to your Arduino
#define SERVER_PORT 3030


// STEP 6 [REQUIRED for all boards and shields]
// determine your network security type (OPTION A, B, or C). Option A is the most common, and the
// default.

/*
 * OPTION A: WPA / WPA2
 *
 * WPA is the most common network security type. A passphrase is required to connect to this type.
 *
 * To enable, leave #define WIFI_WPA_SECURITY uncommented below, set your wpa_passphrase value
 * appropriately, and do not uncomment the #define values under options B and C
 */
#define WIFI_WPA_SECURITY

#ifdef WIFI_WPA_SECURITY
char wpa_passphrase[] = "your_wpa_passphrase";
#endif  //WIFI_WPA_SECURITY


/*
 * OPTION B: WEP
 *
 * WEP is a less common (and regarded as less safe) security type. A WEP key and its associated
 * index are required to connect to this type.
 *
 * To enable, Uncomment the #define below, set your wep_index and wep_key values appropriately,
 * and verify the #define values under options A and C are commented out.
 */
//#define WIFI_WEP_SECURITY

#ifdef WIFI_WEP_SECURITY
//The wep_index below is a zero-indexed value.
//Valid indices are [0-3], even if your router/gateway numbers your keys [1-4].
byte wep_index = 0;
char wep_key[] = "your_wep_key";
#endif  //WIFI_WEP_SECURITY


/*
 * OPTION C: Open network (no security)
 *
 * Open networks have no security, can be connected to by any device that knows the ssid, and are
 * unsafe.
 *
 * To enable, uncomment #define WIFI_NO_SECURITY below and verify the #define values
 * under options A and B are commented out.
 */
//#define WIFI_NO_SECURITY

/*==============================================================================
 * CONFIGURATION ERROR CHECK (don't change anything here)
 *============================================================================*/

#ifdef MULTIPLE_WIFI_LIB_INCLUDES
#error "you may not define more than one wifi device type in wifiConfig.h."
#endif

#ifndef WIFI_LIB_INCLUDED
#error "you must define a wifi device type in wifiConfig.h."
#endif

#if ((defined(WIFI_NO_SECURITY) && (defined(WIFI_WEP_SECURITY) || defined(WIFI_WPA_SECURITY))) || (defined(WIFI_WEP_SECURITY) && defined(WIFI_WPA_SECURITY)))
#error "you may not define more than one security type at the same time in wifiConfig.h."
#endif  //WIFI_* security define check

#if !(defined(WIFI_NO_SECURITY) || defined(WIFI_WEP_SECURITY) || defined(WIFI_WPA_SECURITY))
#error "you must define a wifi security type in wifiConfig.h."
#endif  //WIFI_* security define check

#if (defined(ESP8266_WIFI) && !(defined(WIFI_NO_SECURITY) || (defined(WIFI_WPA_SECURITY))))
#error "you must choose between WIFI_NO_SECURITY and WIFI_WPA_SECURITY"
#endif

/*==============================================================================
 * WIFI STREAM (don't change anything here)
 *============================================================================*/

#ifdef SERVER_IP
  WiFiClientStream stream(IPAddress(SERVER_IP), SERVER_PORT);
#else
  WiFiServerStream stream(SERVER_PORT);
#endif

/*==============================================================================
 * PIN IGNORE MACROS (don't change anything here)
 *============================================================================*/

#if defined(WIFI_101) && !defined(ARDUINO_SAMD_MKR1000)
// ignore SPI pins, pin 5 (reset WiFi101 shield), pin 7 (WiFi handshake) and pin 10 (WiFi SS)
// also don't ignore SS pin if it's not pin 10. Not needed for Arduino MKR1000.
#define IS_IGNORE_PIN(p)  ((p) == 10 || (IS_PIN_SPI(p) && (p) != SS) || (p) == 5 || (p) == 7)

#elif defined(ARDUINO_WIFI_SHIELD) && defined(__AVR_ATmega32U4__)
// ignore SPI pins, pin 4 (SS for SD-Card on WiFi-shield), pin 7 (WiFi handshake) and pin 10 (WiFi SS)
// On Leonardo, pin 24 maps to D4 and pin 28 maps to D10
#define IS_IGNORE_PIN(p)  ((IS_PIN_SPI(p) || (p) == 4) || (p) == 7 || (p) == 10 || (p) == 24 || (p) == 28)

#elif defined(ARDUINO_WIFI_SHIELD)
// ignore SPI pins, pin 4 (SS for SD-Card on WiFi-shield), pin 7 (WiFi handshake) and pin 10 (WiFi SS)
#define IS_IGNORE_PIN(p)  ((IS_PIN_SPI(p) || (p) == 4) || (p) == 7 || (p) == 10)

#elif defined(ESP8266_WIFI) && defined(SERIAL_DEBUG)
#define IS_IGNORE_PIN(p)  ((p) == 1)

#endif
