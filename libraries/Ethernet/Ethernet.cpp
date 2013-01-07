#include "w5100.h"
#include "Ethernet.h"
#include "Dhcp.h"

// XXX: don't make assumptions about the value of MAX_SOCK_NUM.
uint8_t EthernetClass::_state[MAX_SOCK_NUM] = { 
	0, 0, 0, 0 };
uint16_t EthernetClass::_server_port[MAX_SOCK_NUM] = { 
	0, 0, 0, 0 };

int EthernetClass::initialized() {
	if (_dhcp == NULL || _initialized) {
		return 1;
	}
	int result = _dhcp->successful();
	if (result == 1) {
		// We've successfully found a DHCP server and got our configuration info, so set things
		// accordingly
		W5100.setIPAddress(_dhcp->getLocalIp().raw_address());
		W5100.setGatewayIp(_dhcp->getGatewayIp().raw_address());
		W5100.setSubnetMask(_dhcp->getSubnetMask().raw_address());
		_dnsServerAddress = _dhcp->getDnsServerIp();
		_initialized = 1;
		_releasing = 0;
	}
	if (result == 2) {
		_initialized = 1;
		_releasing = 0;
	}
	return result;
}


void EthernetClass::initialize(uint8_t *mac_address)
{
	static DhcpClass s_dhcp;
	_dhcp = &s_dhcp;

	// Initialise the basic info
	W5100.init();
	W5100.setMACAddress(mac_address);
	W5100.setIPAddress(IPAddress(0,0,0,0).raw_address());

	// Now try to get our config info from a DHCP server
	_dhcp->beginWithDHCP(mac_address);
	_initialized = 0;
}

int EthernetClass::begin(uint8_t *mac_address) {
	initialize(mac_address);
	int result = 0;
	while (result == 0) {
		result = initialized();
	}
	return result == 1;
}

void EthernetClass::begin(uint8_t *mac_address, IPAddress local_ip)
{
	// Assume the DNS server will be the machine on the same network as the local IP
	// but with last octet being '1'
	IPAddress dns_server = local_ip;
	dns_server[3] = 1;
	begin(mac_address, local_ip, dns_server);
}

void EthernetClass::begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server)
{
	// Assume the gateway will be the machine on the same network as the local IP
	// but with last octet being '1'
	IPAddress gateway = local_ip;
	gateway[3] = 1;
	begin(mac_address, local_ip, dns_server, gateway);
}

void EthernetClass::begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway)
{
	IPAddress subnet(255, 255, 255, 0);
	begin(mac_address, local_ip, dns_server, gateway, subnet);
}

void EthernetClass::begin(uint8_t *mac, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet)
{
	W5100.init();
	W5100.setMACAddress(mac);
	W5100.setIPAddress(local_ip._address);
	W5100.setGatewayIp(gateway._address);
	W5100.setSubnetMask(subnet._address);
	_dnsServerAddress = dns_server;
	_initialized = 1;
	_releasing = 0;
}

int EthernetClass::maintain() {
	int result = maintainNeeded();
	if (result == DHCP_CHECK_NONE) {
		return result;
	}
	if (result == DHCP_CHECK_REBIND_STARTED) {
		result = 3;
	}
	int res = maintainFinished();
	while (res == 0) {
		delay(10);
		res = maintainFinished();
	}
	return result + (res == 1 ? 1 : 0);
}

int EthernetClass::maintainFinished() {
	int result = _dhcp->successful();
	if (result == 1) {
		_releasing = 0;
		W5100.setIPAddress(_dhcp->getLocalIp().raw_address());
		W5100.setGatewayIp(_dhcp->getGatewayIp().raw_address());
		W5100.setSubnetMask(_dhcp->getSubnetMask().raw_address());
		_dnsServerAddress = _dhcp->getDnsServerIp();
	}
	return result;
}

int EthernetClass::maintainNeeded(){
	int rc = DHCP_CHECK_NONE;
	if(_initialized && _dhcp != NULL){
		if (_releasing) {
			return 1;
		}
		//we have a pointer to dhcp, use it
		rc = _dhcp->checkLease();
		if (rc != DHCP_CHECK_NONE) {
			_releasing = 1;
			return rc;
		}
	}
	return rc;
}

IPAddress EthernetClass::localIP()
{
	IPAddress ret;
	W5100.getIPAddress(ret.raw_address());
	return ret;
}

IPAddress EthernetClass::subnetMask()
{
	IPAddress ret;
	W5100.getSubnetMask(ret.raw_address());
	return ret;
}

IPAddress EthernetClass::gatewayIP()
{
	IPAddress ret;
	W5100.getGatewayIp(ret.raw_address());
	return ret;
}

IPAddress EthernetClass::dnsServerIP()
{
	return _dnsServerAddress;
}

EthernetClass Ethernet;
