#ifndef ethernet_h
#define ethernet_h

#include <inttypes.h>
//#include "w5100.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "EthernetServer.h"
#include "Dhcp.h"

#define MAX_SOCK_NUM 4

class EthernetClass {
private:
	IPAddress _dnsServerAddress;
	DhcpClass* _dhcp;
	uint8_t _initialized;
	uint8_t _releasing;
public:
	static uint8_t _state[MAX_SOCK_NUM];
	static uint16_t _server_port[MAX_SOCK_NUM];
	// Initialise the Ethernet shield to use the provided MAC address and gain the rest of the
	// configuration through DHCP.
	// Returns 0 if the DHCP configuration failed, and 1 if it succeeded
	int begin(uint8_t *mac_address);
	void begin(uint8_t *mac_address, IPAddress local_ip);
	void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server);
	void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
	void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);

	// non blocking initialization of the Ethershield through DHCP, call
	// initialized afterwards
	void initialize(uint8_t *mac_address);
	// 0 = not initialized yet, 1 = successful initialization, 2 = DHCP failed
	int initialized();

	int maintain();

	// non blocking check for maintain the DHCP lease.
	// DHCP_CHECK_NONE = no maintain needed
	// DHCP_CHECK_RENEW_STARTED = maintain started, call maintainFinished()
	// DHCP_CHECK_REBIND_STARTED = maintain started, call maintainFinished()
	int maintainNeeded();
	// 0 = not finished, 1 = finished and successful, 2 = finished but failed 
	int maintainFinished();

	IPAddress localIP();
	IPAddress subnetMask();
	IPAddress gatewayIP();
	IPAddress dnsServerIP();

	friend class EthernetClient;
	friend class EthernetServer;
};

extern EthernetClass Ethernet;

#endif
