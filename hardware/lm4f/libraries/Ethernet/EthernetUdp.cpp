#include "EthernetUdp.h"
#include "lwip/udp.h"
#include <lwip/dns.h>

EthernetUDP::EthernetUDP() {
	_read = 0;
	front = 0;
	count = 0;
}

void EthernetUDP::do_recv(void *arg, struct udp_pcb *upcb, struct pbuf *p, struct ip_addr* addr, uint16_t port)
{
	EthernetUDP *udp = static_cast<EthernetUDP*>(arg);

	/* No more space in the receive queue */
	if(udp->count >= UDP_RX_MAX_PACKETS) {
		pbuf_free(p);
		Serial.println("queue is full");
	}

	udp->count++;
	udp->packets[udp->rear].p = p;
	udp->packets[udp->rear].remoteIP = IPAddress(addr->addr);
	udp->packets[udp->rear].remotePort = port;

//	Serial.print("IP: ");
//	Serial.println(udp->packets[udp->rear].remoteIP);
//	Serial.print("port: ");
//	Serial.println(udp->packets[udp->rear].remotePort);

	udp->rear++;

	if(udp->rear == UDP_RX_MAX_PACKETS)
		udp->rear = 0;

//	Serial.print("rear: ");
//	Serial.println(udp->rear);
//	Serial.print("front: ");
//	Serial.println(udp->front);

//	Serial.print("count: ");
//	Serial.println(udp->count);

//	Serial.print("recv: ");
//	Serial.println(p->len);
//	Serial.print("tot_len: ");
//	Serial.println(p->tot_len);
}

uint8_t EthernetUDP::begin(uint16_t port)
{
	_port = port;
	_pcb = udp_new();
	err_t err = udp_bind(_pcb, IP_ADDR_ANY, port);
	udp_recv(_pcb, do_recv, this);
	return 1;
}

int EthernetUDP::available()
{
	if(!_p)
		return 0;

	return _p->tot_len - _read;
}

void EthernetUDP::stop()
{
	udp_remove(_pcb);
}

void EthernetUDP::do_dns(const char *name, struct ip_addr *ipaddr, void *arg)
{
	ip_addr_t *result = (ip_addr_t *)arg;

	/* BEWARE: lwip stack has been modified to set ipaddr
	 * to IPADDR_NONE if the lookup failed */
	result->addr = ipaddr->addr;
}

int EthernetUDP::beginPacket(const char *host, uint16_t port)
{
	ip_addr_t ip;
	ip.addr = 0;

	dns_gethostbyname(host, &ip, do_dns, &ip);

	while(!ip.addr) {
		delay(10);
	}

	if(ip.addr == IPADDR_NONE) return false;

	return(beginPacket(IPAddress(ip.addr), port));
}

int EthernetUDP::beginPacket(IPAddress ip, uint16_t port)
{
	_sendToIP = ip;
	_sendToPort = port;

	_sendTop = pbuf_alloc(PBUF_TRANSPORT, 1024, PBUF_POOL);

	_write = 0;
}

int EthernetUDP::endPacket()
{
	ip_addr_t dest;
	dest.addr = _sendToIP;

	udp_sendto(_pcb, _sendTop, &dest, _sendToPort);
}

size_t EthernetUDP::write(uint8_t byte)
{
}

size_t EthernetUDP::write(const uint8_t *buffer, size_t size)
{
	if(size > 1024)
		size = 1024;

	memcpy(_sendTop->payload + _read, buffer, size);
}

int EthernetUDP::parsePacket()
{

	/* Discard the current packet */
	if(_p) {
		pbuf_free(_p);
		_p = NULL;
		_read = 0;
		_remotePort = 0;
		_remoteIP = IPAddress(IPADDR_NONE);
	}

	/* No more packets in the queue */
	if(!count) {
		return 0;
	}

	/* Take the next packet from the front of the queue */
	_p = packets[front].p;
	_remoteIP = packets[front].remoteIP;
	_remotePort = packets[front].remotePort;

	count--;
	/* Advance the front of the queue */
	front++;

	/* Wrap around if end of queue has been reached */
	if(front == UDP_RX_MAX_PACKETS)
		front = 0;

	/* Return the total len of the queue */
	return _p->tot_len;
}

int EthernetUDP::read()
{
	if(!available()) return -1;

	uint8_t *buf = (uint8_t *)_p->payload;
	uint8_t b = buf[_read];
	_read = _read + 1;

	if((_read == _p->len) && _p->next) {
		_read = 0;
		pbuf *p;
		p = _p->next;
		/* Increase ref count on p->next
		 * 1->2->1->etc */
		pbuf_ref(_p->next);
		/* Free p which decreases ref count of the chain
		 * and frees up to p->next in this case
		 * ...->1->1->etc */
		pbuf_free(_p);
		_p = NULL;
		_p = p;
	} else if(_read == _p->len) {
		_read = 0;
		pbuf_free(_p);
		_p = NULL;
	}

	return b;
}


int EthernetUDP::read(unsigned char* buffer, size_t len)
{
	uint16_t avail = available();
	uint16_t i;
	int8_t b;

	if(!avail)
		return -1;

	/* TODO: Replace lazy method with optimized on */
	for(i = 0; i < len; i++) {
		b = read();
		if(b == -1)
			break;
		buffer[i] = b;
	}

	return i;
}

int EthernetUDP::peek()
{
	uint8_t b;

	if (!available())
		return -1;

	uint8_t *buf = (uint8_t *)_p->payload;
	b = buf[_read];

	return b;
}

void EthernetUDP::flush()
{
	if(available()) {
		_read = _p->tot_len;
	}
}
