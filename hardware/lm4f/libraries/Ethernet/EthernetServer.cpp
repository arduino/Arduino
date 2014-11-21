#include "Ethernet.h"
#include "EthernetClient.h"
#include "EthernetServer.h"

/* SYNC_FETCH_AND_NULL: atomic{ tmp=*x; *x=NULL; return tmp; } */
#define SYNC_FETCH_AND_NULL(x)   (__sync_fetch_and_and(x, NULL))

EthernetServer::EthernetServer(uint16_t port) {
	_port = port;
	lastConnect = 0;
}

err_t EthernetServer::do_poll(void *arg, struct tcp_pcb *cpcb) {
	/* We only end up here if the connection failed to close
	 * in an earlier call to tcp_close */
	err_t err = tcp_close(cpcb);

	if (err != ERR_OK) {
		/* error closing, try again later in polli (every 2 sec) */
		tcp_poll(cpcb, do_poll, 4);
	}

	return err;
}

void EthernetServer::do_close(void *arg, struct tcp_pcb *cpcb) {
	/*
	 * Get the server object from the argument
	 * to get access to variables and functions
	 */
	EthernetServer *server = static_cast<EthernetServer*>(arg);

	tcp_arg(cpcb, NULL);
	tcp_recv(cpcb, NULL);
	tcp_err(cpcb, NULL);
	tcp_poll(cpcb, NULL, 0);
	tcp_sent(cpcb, NULL);

	uint8_t i;
	for (i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].port == cpcb->remote_port)
			break;
	}
	if (i >= MAX_CLIENTS) {
		/* connection already closed */
		return;
	}

	/* --- close the connection --- */

	struct client * cs = &server->clients[i];

	cs->read = 0;
	cs->port = 0;

	if (cs->p) {
		if (cs->cpcb)
			tcp_recved(cpcb, cs->p->tot_len);
		pbuf_free((pbuf*)cs->p);
		cs->p = NULL;
	}
	if (cs->cpcb) {
		err_t err = tcp_close(cpcb);
		if (err != ERR_OK) {
			/* Error closing, try again later in polli (every 2 sec) */
			tcp_poll(cpcb, do_poll, 4);
		}
		cs->cpcb = NULL;
	}

	return;
}

err_t EthernetServer::did_sent(void *arg, struct tcp_pcb *pcb, u16_t len) {
	return ERR_OK;
}

err_t EthernetServer::do_recv(void *arg, struct tcp_pcb *cpcb, struct pbuf *p,
		err_t err) {

	/*
	 * Get the server object from the argument
	 * to get access to variables and functions
	 */
	EthernetServer *server = static_cast<EthernetServer*>(arg);

	/* p==0 for end-of-connection (TCP_FIN packet) */
	if (p == 0) {
		do_close(arg, cpcb);
		return ERR_OK;
	}

	/* find the connection */
	uint8_t i;
	for (i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].port == cpcb->remote_port)
			break;
	}
	if (i >= MAX_CLIENTS) {
		/* connection already closed - reject the data */
		return ERR_MEM;
	}

	if (server->clients[i].p != 0)
		pbuf_cat((pbuf*)server->clients[i].p, p);
	else
		server->clients[i].p = p;

	return ERR_OK;
}

err_t EthernetServer::do_accept(void *arg, struct tcp_pcb *cpcb, err_t err) {
	/*
	 * Get the server object from the argument
	 * to get access to variables and functions
	 */

	EthernetServer *server = static_cast<EthernetServer*>(arg);

	/* Find free client */
	uint8_t i;
	for (i = 0; i < MAX_CLIENTS; i++) {
		if (server->clients[i].port == 0)
			break;
	}
	if (i >= MAX_CLIENTS) {
		return ERR_MEM;
	}

	memset(&server->clients[i], 0, sizeof(struct client));

	server->clients[i].port = cpcb->remote_port;
	server->clients[i].cpcb = cpcb;

	tcp_accepted(server->spcb);

	tcp_arg(cpcb, arg);
	tcp_recv(cpcb, do_recv);
	tcp_sent(cpcb, did_sent);

	/*
	 * Returning ERR_OK indicates to the stack the the
	 * connection has been accepted
	 */
	return ERR_OK;
}

void EthernetServer::begin() {
	spcb = tcp_new();
	tcp_bind(spcb, IP_ADDR_ANY, _port);
	spcb = tcp_listen(spcb);
	tcp_arg(spcb, this);
	tcp_accept(spcb, do_accept);
}

EthernetClient EthernetServer::available() {
	static uint8_t lastClient = 0; /* serve the clients in a round-robin fashion */
	uint8_t i;
	/* Find active client */
	for (i = 0; i < MAX_CLIENTS; i++) {
		if (++lastClient >= MAX_CLIENTS)
			lastClient = 0;
		if (clients[lastClient].port != 0) {
			/* cpcb may change to NULL during interrupt servicing, so avoid the NULL pointer access */
			struct tcp_pcb * cpcb = (tcp_pcb*)clients[lastClient].cpcb;
			if (cpcb && cpcb->state == ESTABLISHED)
				return EthernetClient(&clients[lastClient]);
		}
	}
	/* No client connection active */
	return EthernetClient(NULL);
}

size_t EthernetServer::write(uint8_t b) {
	return write(&b, 1);
}

size_t EthernetServer::write(const uint8_t *buffer, size_t size) {
	uint8_t i;
	size_t n = 0;
	EthernetClient client;

	/* Find connected clients */
	for (i = 0; i < MAX_CLIENTS; i++) {
		if (clients[i].port != 0 && clients[i].cpcb
				&& clients[i].cpcb->state == ESTABLISHED) {
			/* cpcb may change to NULL during interrupt servicing, so avoid the NULL pointer access */
			struct tcp_pcb * cpcb = (tcp_pcb*)clients[i].cpcb;
			if (cpcb && cpcb->state == ESTABLISHED) {
				client = EthernetClient(&clients[i]);
				n += client.write(buffer, size);
			}
		}
	}

	return n;
}
