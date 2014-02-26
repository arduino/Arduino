#ifndef ethernetclient_h
#define ethernetclient_h
#include "Energia.h"
#include "Print.h"
#include "Client.h"
#include "IPAddress.h"
#include "EthernetServer.h"
#include <lwip/dns.h>

/* Set connection timeout to 10 sec */
#define CONNECTION_TIMEOUT 1000 * 10

class EthernetClient : public Client {
public:
	EthernetClient();
	EthernetClient(struct client *c);

	uint8_t status();
	virtual int connect(IPAddress ip, uint16_t port);
	virtual int connect(const char *host, uint16_t port);
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *buf, size_t size);
	virtual int available();
	virtual int read();
	virtual int port();
	virtual int read(uint8_t *buf, size_t size);
	virtual int peek();
	virtual void flush();
	virtual void stop();
	virtual uint8_t connected();
	virtual operator bool();
	static err_t do_connected(void *arg, struct tcp_pcb *pcb, err_t err);
	static err_t do_recv(void *arg, struct tcp_pcb *cpcb, struct pbuf *p, err_t err);
	static err_t do_poll(void *arg, struct tcp_pcb *cpcb);
	static void do_err(void * arg, err_t err);
	static void do_dns(const char *name, struct ip_addr *ipaddr, void *arg);
	friend class EthernetServer;
	using Print::write;

private:
	struct pbuf *_p;
	struct tcp_pcb *cpcb;
	struct client client_state;
	uint16_t *_read;
	volatile bool _connected;
	struct client *cs;
};
#endif
