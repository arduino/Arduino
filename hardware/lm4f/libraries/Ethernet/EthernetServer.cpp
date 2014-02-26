#include "Ethernet.h"
#include "EthernetClient.h"
#include "EthernetServer.h"


uint8_t EthernetServer::num_clients = 0;

EthernetServer::EthernetServer(uint16_t port)
{
	_port = port;
	lastConnect = 0;
}

err_t EthernetServer::do_poll(void *arg, struct tcp_pcb *cpcb)
{
	/* We only end up here if the connection failed to close
	 * in an earlier call to tcp_close */
	err_t err = tcp_close(cpcb);

	if (err != ERR_OK) {
		/* error closing, try again later in polli (every 2 sec) */
		tcp_poll(cpcb, do_poll, 4);
	}

	return err;
}

err_t EthernetServer::do_close(void *arg, struct tcp_pcb *cpcb)
{
	num_clients--;

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
	for(i = 0; i < server->num_clients; i++) {
		if(server->clients[i].port == cpcb->remote_port) break;
	}

	server->clients[i].port = 0;

	tcp_recved(cpcb, server->clients[i].p->tot_len);
	pbuf_free(server->clients[i].p);

	err_t err = tcp_close(cpcb);

	if (err != ERR_OK) {
		/* Error closing, try again later in polli (every 2 sec) */
		tcp_poll(cpcb, do_poll, 4);
		return err;
	}

	server->clients[i].p = 0;
	server->clients[i].cpcb = NULL;
	server->clients[i].read = 0;

	return err;
}

err_t EthernetServer::did_sent(void *arg, struct tcp_pcb *pcb, u16_t len)
{
	return ERR_OK;
}

err_t EthernetServer::do_recv(void *arg, struct tcp_pcb *cpcb, struct pbuf *p, err_t err)
{
	/*
	 * Get the server object from the argument
	 * to get access to variables and functions
	 */
	EthernetServer *server = static_cast<EthernetServer*>(arg);

	if(p == 0) {
		return do_close(arg, cpcb);
	}

	/* find the connection */
	uint8_t i;
	for(i = 0; i < server->num_clients; i++) {
		if(server->clients[i].port == cpcb->remote_port) break;
	}

	if(server->clients[i].p != 0)
		pbuf_cat(server->clients[i].p, p);
	else
		server->clients[i].p = p;

	return ERR_OK;
}

err_t EthernetServer::do_accept(void *arg, struct tcp_pcb *cpcb, err_t err)
{
	/*
	 * Get the server object from the argument
	 * to get access to variables and functions
	 */
	EthernetServer *server = static_cast<EthernetServer*>(arg);

	unsigned long now;

	now = millis();

	/* Slow down the rate at which connecitons are comming in
	 * if connections are coming in faster than 50 milli seconds */
	if(now - server->lastConnect < 50) {
		delay(30);
	}

	server->lastConnect = millis();
	/*
	 * Maximum number of clients reached.
	 * Drop the connection.
	 */
	if(server->num_clients == MAX_CLIENTS) {
		return ERR_MEM;
	}

	/*
	 * Find active client
	 * TODO: Do not always settle on the first starving the others.
	 */
	uint8_t i;
	for(i = 0; i < server->num_clients; i++) {
		if(server->clients[i].port == 0) break;
	}

	server->num_clients++;

	memset (&server->clients[i], 0, sizeof(struct client));

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

void EthernetServer::begin()
{
	spcb = tcp_new();
	tcp_bind(spcb, IP_ADDR_ANY, _port);
	spcb = tcp_listen(spcb);
	tcp_arg(spcb, this);
	tcp_accept(spcb, do_accept);
}

EthernetClient EthernetServer::available()
{
	/* No clients connected */
	if(num_clients == 0)
		return EthernetClient(NULL);

	/* Find active client */
	uint8_t i;
	for(i = 0 ; i < num_clients; i++) {
		if(clients[i].port != 0) break;
	}

	/* Connection established? */
	if(clients[i].cpcb->state != ESTABLISHED)
		return EthernetClient(NULL);

	EthernetClient client(&clients[i]);
	return client;
}

size_t EthernetServer::write(uint8_t b)
{
	return write(&b, 1);
}

size_t EthernetServer::write(const uint8_t *buffer, size_t size)
{
	uint8_t i;
	size_t n = 0;
	EthernetClient client;

	/* Find connected clients */
	for(i = 0 ; i < num_clients; i++) {
		if(clients[i].port != 0 && clients[i].cpcb->state == ESTABLISHED)
			client = EthernetClient(&clients[i]);
			n += client.write(buffer, size);
	}

	return n;
}
