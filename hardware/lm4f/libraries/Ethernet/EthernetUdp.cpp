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
		return;
	}

	/* Increase the number of packets in the queue
	 * that are waiting for processing */
	udp->count++;
	/* Add pacekt to the rear of the queue */
	udp->packets[udp->rear].p = p;
	/* Record the IP address and port the pacekt was received from */
	udp->packets[udp->rear].remoteIP = IPAddress(addr->addr);
	udp->packets[udp->rear].remotePort = port;

	/* Advance the rear of the queue */
	udp->rear++;

	/* Wrap around the end of the array was reached */
	if(udp->rear == UDP_RX_MAX_PACKETS)
		udp->rear = 0;
}

uint8_t EthernetUDP::begin(uint16_t port)
{
	_port = port;
	_pcb = udp_new();
	err_t err = udp_bind(_pcb, IP_ADDR_ANY, port);

	if(err == ERR_USE)
		return 0;

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

	_sendTop = pbuf_alloc(PBUF_TRANSPORT, UDP_TX_PACKET_MAX_SIZE, PBUF_POOL);

	_write = 0;

	if(_sendTop == NULL)
		return false;

	return true;
}

int EthernetUDP::endPacket()
{
	ip_addr_t dest;
	dest.addr = _sendToIP;

	/* Shrink the pbuf to the actual size that was written to it */
	pbuf_realloc(_sendTop, _write);

	/* Send the buffer to the remote host */
	err_t err = udp_sendto(_pcb, _sendTop, &dest, _sendToPort);

	/* udp_sendto is blocking and the pbuf is
	 * no longer needed so free it */
	pbuf_free(_sendTop);

	if(err != ERR_OK)
		return false;

	return true;
}

size_t EthernetUDP::write(uint8_t byte)
{
	return write(&byte, 1);
}

size_t EthernetUDP::write(const uint8_t *buffer, size_t size)
{
	uint16_t avail = _sendTop->tot_len - _write;

	/* If there is no more space available
	 * then return immediately */
	if(avail == 0)
		return 0;

	/* If size to send is larger than is available,
	 * then only send up to the space available */
	if(size > avail)
		size = avail;

	/* Copy buffer into the pbuf */
	pbuf_take(_sendTop, buffer, size);

	_write += size;

	return size;
}

int EthernetUDP::parsePacket()
{
	_read = 0;

	/* Discard the current packet */
	if(_p) {
		pbuf_free(_p);
		_p = NULL;
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
	int b;

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
