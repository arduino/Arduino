#ifndef ethernetclient_h
#define ethernetclient_h
#include "Arduino.h"	
#include "Print.h"
#include "Client.h"
#include "Dns.h"
#include "IPAddress.h"

class EthernetClient : public Client {

public:
	EthernetClient();
	EthernetClient(uint8_t sock);

	uint8_t status();
	virtual int connect(IPAddress ip, uint16_t port);
	virtual int connect(const char *host, uint16_t port);
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *buf, size_t size);
	virtual int available();
	virtual int read();
	virtual int read(uint8_t *buf, size_t size);
	virtual int peek();
	virtual void flush();
	virtual void stop();
	virtual uint8_t connected();
	virtual operator bool();


	// non blocking variant of the connect  method,  
	// 0 = failed, 1 = successful initialization, call connectionInitialized()
	virtual int initializeConnection(IPAddress ip, uint16_t port);
	// non blocking variant of the connect & DNS method, call connectionInitialized()
	// 0 = failed, 1 = successful initialization, call connectionInitialized()
	virtual int initializeConnection(const char *host, uint16_t port);
	// 0 = still working, 1 = successful connection, 2 = connection failed
	virtual uint8_t connectionInitialized();

	friend class EthernetServer;

	using Print::write;

private:
	static uint16_t _srcport;
	uint8_t _sock;
	uint8_t _established;
	uint8_t _dnsresolved;
	uint16_t _port;

	DNSClient* _dns;
};

#endif
