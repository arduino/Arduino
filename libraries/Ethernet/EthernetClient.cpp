#include "w5100.h"
#include "socket.h"

extern "C" {
#include "string.h"
}

#include "Arduino.h"

#include "Ethernet.h"
#include "EthernetClient.h"
#include "EthernetServer.h"
#include "Dns.h"

uint16_t EthernetClient::_srcport = 1024;

EthernetClient::EthernetClient() : _sock(MAX_SOCK_NUM) {
}

EthernetClient::EthernetClient(uint8_t sock) : _sock(sock) {
}

int EthernetClient::initializeConnection(const char *host, uint16_t port) {
	if (_dns) {
		return 0; // init already busy
	}
	IPAddress ip;
	_dns = new DNSClient();
	_dns->begin(Ethernet.dnsServerIP());
	int res = _dns->startHostRequest(host, ip);
	if (res == 0) {
		_dnsresolved = 0;
		_port = port;
		return 1;
	}
	else if (res == 1) {
		delete _dns;
		_dns = NULL;
		return initializeConnection(ip, port);
	}
	else {
		delete _dns;
		_dns = NULL;
		return 0;
	}
}
int EthernetClient::connect(const char* host, uint16_t port) {
	if (!initializeConnection(host, port)) {
		return 0;
	}
	int result = 0;
	while (result == 0) {
		result = connectionInitialized();
		if (result == 0) {
			delay(1);
		}
	}
	return result == 1;
}

int EthernetClient::initializeConnection(IPAddress ip, uint16_t port) {
	_dnsresolved = 1;
	if (_sock != MAX_SOCK_NUM) {
		return 0; 
	}

	for (int i = 0; i < MAX_SOCK_NUM; i++) {
		uint8_t s = W5100.readSnSR(i);
		if (s == SnSR::CLOSED || s == SnSR::FIN_WAIT || s == SnSR::CLOSE_WAIT) {
			_sock = i;
			break;
		}
	}
	if (_sock == MAX_SOCK_NUM)
		return 0;

	_srcport++;
	if (_srcport == 0) _srcport = 1024;
	socket(_sock, SnMR::TCP, _srcport, 0);

	if (!::connect(_sock, rawIPAddress(ip), port)) {
		_sock = MAX_SOCK_NUM;
		return 0;
	}
	_established = 0;
	return 1;
}

int EthernetClient::connect(IPAddress ip, uint16_t port) {
	if (!initializeConnection(ip, port)) {
		return 0;
	}
	int result = 0;
	while (result == 0) {
		result = connectionInitialized();
		if (result == 0) {
			delay(1);
		}
	}
	return result == 1;
}

uint8_t EthernetClient::connectionInitialized() {
	if (!_dnsresolved) {
		IPAddress ip;
		int result = _dns->getHostRequestResult(ip);
		if (result == 1) {
			_dnsresolved = 1;
			delete _dns;
			_dns = NULL;
			return initializeConnection(ip, _port) == 1 ? 0 : 2;
		}
		else if (result > 1) {
			delete _dns;
			_dns = NULL;
			_sock = MAX_SOCK_NUM;
			return 2;
		}
		return 0;
	}
	else {
		if (_established) {
			return _established;
		}
		if (_sock == MAX_SOCK_NUM) {
			return 2;
		}
		if (status() != SnSR::ESTABLISHED) {
			_established = 0;
			if (status() == SnSR::CLOSED) {
				_sock = MAX_SOCK_NUM;
				return 2;
			}
		}
		else {
			_established = 1;
		}
		return _established;
	}
}

size_t EthernetClient::write(uint8_t b) {
	return write(&b, 1);
}

size_t EthernetClient::write(const uint8_t *buf, size_t size) {
	if (_sock == MAX_SOCK_NUM) {
		setWriteError();
		return 0;
	}
	if (!send(_sock, buf, size)) {
		setWriteError();
		return 0;
	}
	return size;
}

int EthernetClient::available() {
	if (_sock != MAX_SOCK_NUM)
		return W5100.getRXReceivedSize(_sock);
	return 0;
}

int EthernetClient::read() {
	uint8_t b;
	if ( recv(_sock, &b, 1) > 0 )
	{
		// recv worked
		return b;
	}
	else
	{
		// No data available
		return -1;
	}
}

int EthernetClient::read(uint8_t *buf, size_t size) {
	return recv(_sock, buf, size);
}

int EthernetClient::peek() {
	uint8_t b;
	// Unlike recv, peek doesn't check to see if there's any data available, so we must
	if (!available())
		return -1;
	::peek(_sock, &b);
	return b;
}

void EthernetClient::flush() {
	while (available())
		read();
}

void EthernetClient::stop() {
	if (_sock == MAX_SOCK_NUM)
		return;

	// attempt to close the connection gracefully (send a FIN to other side)
	disconnect(_sock);
	unsigned long start = millis();

	// wait a second for the connection to close
	while (status() != SnSR::CLOSED && millis() - start < 1000)
		delay(1);

	// if it hasn't closed, close it forcefully
	if (status() != SnSR::CLOSED)
		close(_sock);

	EthernetClass::_server_port[_sock] = 0;
	_sock = MAX_SOCK_NUM;
}

uint8_t EthernetClient::connected() {
	if (_sock == MAX_SOCK_NUM) return 0;
	if (_dnsresolved == 0) return 0;
	if (_established == 0) return 0;

	uint8_t s = status();
	return !(s == SnSR::LISTEN || s == SnSR::CLOSED || s == SnSR::FIN_WAIT ||
			(s == SnSR::CLOSE_WAIT && !available()));
}

uint8_t EthernetClient::status() {
	if (_sock == MAX_SOCK_NUM) return SnSR::CLOSED;
	return W5100.readSnSR(_sock);
}

// the next function allows us to use the client returned by
// EthernetServer::available() as the condition in an if-statement.

EthernetClient::operator bool() {
	return _sock != MAX_SOCK_NUM;
}
