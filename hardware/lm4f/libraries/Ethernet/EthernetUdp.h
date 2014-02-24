#define UDP_RX_MAX_PACKETS 32
#define UDP_TX_PACKET_MAX_SIZE 2048

#include "Energia.h"
#include <Udp.h>

struct packet {
	struct pbuf *p;
	IPAddress remoteIP;
	uint16_t remotePort;
};

class EthernetUDP : public UDP {
private:
	struct packet packets[UDP_RX_MAX_PACKETS];
	uint8_t front;
	uint8_t rear;
	uint8_t count;

	struct udp_pcb *_pcb;
	struct pbuf *_p;
	uint16_t _port;
	/* IP and port filled in when receiving a packet */
	IPAddress _remoteIP;
	uint16_t _remotePort;
	/* pbuf, pcb, IP and port used when acting as a client */
	struct pbuf *_sendTop;
	struct udp_pcb *_sendToPcb;
	IPAddress _sendToIP;
	uint16_t _sendToPort;

	uint16_t _read;
	uint16_t _write;
	static void do_recv(void *arg, struct udp_pcb *upcb, struct pbuf *p, struct ip_addr* addr, uint16_t port);
	static void do_dns(const char *name, struct ip_addr *ipaddr, void *arg);
public:
	EthernetUDP();
	virtual uint8_t begin(uint16_t);
	virtual void stop();
	virtual int beginPacket(IPAddress ip, uint16_t port);
	virtual int beginPacket(const char *host, uint16_t port);
	virtual int endPacket();
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *buffer, size_t size);

	using Print::write;

	virtual int parsePacket();
	virtual int available();
	virtual int read();
	virtual int read(unsigned char* buffer, size_t len);
	virtual int read(char* buffer, size_t len) { return read((unsigned char*)buffer, len); };
	virtual int peek();
	virtual void flush();

	virtual IPAddress remoteIP() { return _remoteIP; };
	virtual uint16_t remotePort() { return _remotePort; };
};
