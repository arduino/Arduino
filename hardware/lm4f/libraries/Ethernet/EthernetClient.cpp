#include "Energia.h"

#include "Ethernet.h"
#include "EthernetClient.h"
#include "EthernetServer.h"

EthernetClient::EthernetClient(){
	_connected = false;
	cs = &client_state;
	_read = &cs->read;

}

EthernetClient::EthernetClient(struct client *c) {
	if(c == NULL) {
		cpcb = NULL;
		return;
	}

	_connected = true;
	_read = &c->read;
	_p = c->p;
	cpcb = c->cpcb;
	cs = c;
}

err_t EthernetClient::do_poll(void *arg, struct tcp_pcb *cpcb)
{

	/* We only end up here if the connection failed to close
	 * in an earlier call to tcp_close */
	err_t err = tcp_close(cpcb);

	if (err != ERR_OK) {
		/* error closing, try again later in polli (every 2 sec) */
		tcp_poll(cpcb, do_poll, 4);
		return err;
	}

	EthernetClient *client = static_cast<EthernetClient*>(arg);

	tcp_arg(cpcb, NULL);
	tcp_recv(cpcb, NULL);
	tcp_err(cpcb, NULL);
	tcp_poll(cpcb, NULL, 0);
	tcp_sent(cpcb, NULL);

	client->_connected = false;
	return err;

}

void EthernetClient::do_err(void * arg, err_t err)
{
	//Serial.print("do_err called: ");
	//Serial.println(err);

	EthernetClient *client = static_cast<EthernetClient*>(arg);
	/*
	 * Set connected to true to finish connecting.
	 * ::connect wil take care of figuring out if we are truly connected
	 * by looking at the socket state
	 */
	client->_connected = true;
}

err_t EthernetClient::do_connected(void * arg, struct tcp_pcb * tpcb, err_t err)
{
	//Serial.println("do_connected called");
	EthernetClient *client = static_cast<EthernetClient*>(arg);
	client->_connected = true;
	return err;
}

err_t EthernetClient::do_close(void *arg, struct tcp_pcb *cpcb)
{
	/*
	 * Get the client object from the argument
	 * to get access to variables and functions
	 */
	EthernetClient *client = static_cast<EthernetClient*>(arg);

	tcp_recved(cpcb, client->_p->tot_len);
	pbuf_free(client->_p);
	client->_p = NULL;

	err_t err = tcp_close(cpcb);

	if (err != ERR_OK) {
		/* Error closing, try again later in poll (every 2 sec) */
		tcp_poll(cpcb, do_poll, 4);
		return err;
	}

	tcp_arg(cpcb, NULL);
	tcp_recv(cpcb, NULL);
	tcp_err(cpcb, NULL);
	tcp_poll(cpcb, NULL, 0);
	tcp_sent(cpcb, NULL);

	client->_connected = false;
	return err;
}

err_t EthernetClient::do_recv(void *arg, struct tcp_pcb *cpcb, struct pbuf *p, err_t err)
{
	/*
	 * Get the server object from the argument
	 * to get access to variables and functions
	 */
	EthernetClient *client = static_cast<EthernetClient*>(arg);
	//Serial.println("do_recv called");

	if(p == 0) {
		return do_close(arg, cpcb);
	}

	if(client->cs->p != 0)
		pbuf_cat(client->cs->p, p);
	else
		client->cs->p = p;

	return ERR_OK;
}

void EthernetClient::do_dns(const char *name, struct ip_addr *ipaddr, void *arg)
{
	ip_addr_t *result = (ip_addr_t *)arg;

	/* BEWARE: lwip stack has been modified to set ipaddr
	 * to IPADDR_NONE if the lookup failed */
	result->addr = ipaddr->addr;
}

int EthernetClient::connect(const char* host, uint16_t port)
{
	ip_addr_t ip;
	ip.addr = 0;

	dns_gethostbyname(host, &ip, do_dns, &ip);

	while(!ip.addr) {
		delay(10);
	}

	if(ip.addr == IPADDR_NONE) return false;

	return(connect(IPAddress(ip.addr), port));
}

int EthernetClient::connect(IPAddress ip, uint16_t port)
{
	ip_addr_t dest;
	dest.addr = ip;

	cpcb = tcp_new();
	tcp_arg(cpcb, this);
	tcp_recv(cpcb, do_recv);
	tcp_err(cpcb, do_err);
	tcp_connect(cpcb, &dest, port, do_connected);

	while(!_connected) {
		delay(10);
	}

	if(cpcb->state != ESTABLISHED) {
		_connected = false;
	}

	return _connected;
}

size_t EthernetClient::write(uint8_t b) {
	return write(&b, 1);
}


size_t EthernetClient::write(const uint8_t *buf, size_t size) {
	err_t err = tcp_write(cpcb, buf, size, TCP_WRITE_FLAG_COPY);
	if (err == ERR_MEM) {
		/* TODO: Need to send smaller chunks if fails */
	}
}

int EthernetClient::available() {
	if(!cs->p) return 0;

	return cs->p->tot_len - *_read;
}

int EthernetClient::port()
{
	return cs->port;
}

int EthernetClient::read() {
	if(!available()) return -1;

	uint8_t *buf = (uint8_t *)cs->p->payload;
	uint8_t b = buf[*_read];
	*_read = *_read + 1;

	tcp_recved(cpcb, *_read);

	if((*_read == cs->p->len) && cs->p->next) {
		*_read = 0;
		pbuf *p;
		p = cs->p->next;
		/* Increase ref count on p->next
		 * 1->2->1->etc */
		pbuf_ref(cs->p->next);
		/* Free p which decreases ref count of the chain
		 * and frees up to p->next in this case
		 * ...->1->1->etc */
		pbuf_free(cs->p);
		cs->p = NULL;
		cs->p = p;
	} else if(*_read == cs->p->len) {
		*_read = 0;
		pbuf_free(cs->p);
		cs->p = NULL;
	}

	return b;
}

int EthernetClient::read(uint8_t *buf, size_t size)
{

}

int EthernetClient::peek()
{
  uint8_t b;
  return b;
}

void EthernetClient::flush()
{
	if(available()) {
		*_read = _p->tot_len;
		tcp_recved(cpcb, _p->tot_len);
	}
}

void EthernetClient::stop()
{
	if(cpcb)
		tcp_close(cpcb);
	_connected = false;
}

uint8_t EthernetClient::connected()
{
	return _connected;
}

uint8_t EthernetClient::status()
{
}

EthernetClient::operator bool()
{
	if(cpcb == NULL) return false;
	if(cpcb->state != ESTABLISHED) return false;

	return true;
	
}
