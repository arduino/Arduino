#ifndef ethernet_h
#define ethernet_h

#include <inttypes.h>
//#include "w5100.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "EthernetServer.h"
#include "Dhcp.h"

#ifndef MAX_SOCK_NUM
#define MAX_SOCK_NUM 4
#endif

class EthernetClass {
private:
  IPAddress _dnsServerAddress;
  DhcpClass* _dhcp;
public:
  static uint8_t _state[MAX_SOCK_NUM];
  static uint16_t _server_port[MAX_SOCK_NUM];
  // Initialise the Ethernet shield to use the provided MAC address and gain the rest of the
  // configuration through DHCP.
  // Returns 0 if the DHCP configuration failed, and 1 if it succeeded
  int begin(uint8_t *mac_address, uint8_t csPin = SS);
  void begin(uint8_t *mac_address, IPAddress local_ip, uint8_t csPin = SS);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, uint8_t csPin = SS);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, uint8_t csPin = SS);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet, uint8_t csPin = SS);
  int maintain();

  IPAddress localIP();
  IPAddress subnetMask();
  IPAddress gatewayIP();
  IPAddress dnsServerIP();
  void macAddress(byte *mac);

  friend class EthernetClient;
  friend class EthernetServer;
};

extern EthernetClass Ethernet;

#endif
