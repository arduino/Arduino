/*==============================================================================
 * NETWORK CONFIGURATION
 *
 * You must configure your particular hardware. Follow the steps below.
 *
 * By default, StandardFirmataEthernet is configured as a TCP client.
 * To configure as a TCP server, see STEP 2
 *============================================================================*/

// STEP 1 [REQUIRED]
// Uncomment / comment the appropriate set of includes for your hardware (OPTION A or B)
// Option A is enabled by default.

/*
 * OPTION A: Configure for Arduino Ethernet board or Arduino Ethernet shield (or clone)
 *
 * To configure StandardFirmataEthernet to use the original WIZ5100-based
 * ethernet shield or Arduino Ethernet uncomment the WIZ5100_ETHERNET define below
 */
#define WIZ5100_ETHERNET

#ifdef WIZ5100_ETHERNET
#include <SPI.h>
#include <Ethernet.h>
EthernetClient client;
#endif

/*
 * OPTION B: Configure for Arduin Yun
 *
 * The Ethernet port on the Arduino Yun board can be used with Firmata in this configuration.
 *
 * To execute StandardFirmataEthernet on Yun uncomment the YUN_ETHERNET define below and make
 * sure the WIZ5100_ETHERNET define (above) is commented out.
 *
 * On Yun there's no need to configure local_ip and mac address as this is automatically
 * configured on the linux-side of Yun.
 *
 * Note that it may take several seconds to establish a connection with the Yun.
 */
//#define YUN_ETHERNET

#ifdef YUN_ETHERNET
#include <Bridge.h>
#include <YunClient.h>
YunClient client;
#endif

// STEP 2 [REQUIRED for all boards and shields]
// TCP Client configuration:
// To configure your board as a TCP client, set the IP address of the server you want to connect to.
// TCP Server configuration:
// To configure your board as a TCP server, comment out the following line and also ensure that
// remote_host is also commented out.
#define remote_ip IPAddress(10, 0, 0, 3)
// *** REMOTE HOST IS NOT YET WORKING ***
// replace with hostname of server you want to connect to, comment out if using 'remote_ip'
// #define remote_host "server.local"

// STEP 3 [REQUIRED]
// Replace with the port that your client or server is listening on.
#define network_port 3030

// STEP 4 [REQUIRED unless using DHCP]
// Replace with your board or ethernet shield's IP address
// Comment out if you want to use DHCP
#define local_ip IPAddress(10, 0, 0, 15)

// STEP 5 [REQUIRED]
// replace with ethernet shield mac. Must be unique for your network
const byte mac[] = {0x90, 0xA2, 0xDA, 0x00, 0x53, 0xE5};

/*==============================================================================
 * CONFIGURATION ERROR CHECK (don't change anything here)
 *============================================================================*/

#if !defined WIZ5100_ETHERNET && !defined YUN_ETHERNET
#error "you must define either WIZ5100_ETHERNET or YUN_ETHERNET in ethernetConfig.h"
#endif

#if defined remote_ip && defined remote_host
#error "cannot define both remote_ip and remote_host at the same time in ethernetConfig.h"
#endif

/*==============================================================================
 * PIN IGNORE MACROS (don't change anything here)
 *============================================================================*/

#if defined(WIZ5100_ETHERNET)

// ignore SPI pins, pin 10 (Ethernet SS) and pin 4 (SS for SD-Card on Ethernet shield)
#define IS_IGNORE_PIN(p) ((IS_PIN_SPI(p) || (p) == 4) || (p) == 10)

#endif
