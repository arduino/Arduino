#ifndef ethernetserver_h
#define ethernetserver_h

#include "Server.h"
#include "lwip/tcp.h"

#define MAX_CLIENTS 8

/* 
 * client state structure that is passed on to the client
 * through available()
 */
struct client {
	/* Connection port. (may change to 0 at any time during interrupt servicing) */
	volatile uint16_t port;
	/* Received data buffer. (may change to NULL at any time during interrupt servicing) */
	volatile struct pbuf *p;
	/* tcp control block. (may change to NULL at any time during interrupt servicing) */
	volatile struct tcp_pcb *cpcb;
	volatile bool connected;
	uint16_t read;
	bool mode;
};

class EthernetClient;

class EthernetServer : public Server {
private:
	unsigned long lastConnect;
	uint16_t _port;
	struct tcp_pcb *spcb;
	struct client clients[MAX_CLIENTS];
	static err_t do_poll(void *arg, struct tcp_pcb *cpcb);
	static void  do_close(void *arg, struct tcp_pcb *cpcb);
public:
	EthernetServer(uint16_t);
	EthernetClient available();
	virtual void begin();
	virtual size_t write(uint8_t);
	virtual size_t write(const uint8_t *buf, size_t size);
	static err_t do_accept(void *arg, struct tcp_pcb *pcb, err_t err);
	static err_t do_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err);
	static err_t did_sent(void *arg, struct tcp_pcb *pcb, u16_t len);
	using Print::write;
};

#endif
