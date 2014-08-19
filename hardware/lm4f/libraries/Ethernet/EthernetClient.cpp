#include "Energia.h"

#include "Ethernet.h"
#include "EthernetClient.h"
#include "EthernetServer.h"

EthernetClient::EthernetClient(){
	_connected = false;
	cs = &client_state;
	_read = &cs->read;
	cs->mode = true;
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
	cs->mode = false;
}

err_t EthernetClient::do_poll(void *arg, struct tcp_pcb *cpcb)
{
	EthernetClient *client = static_cast<EthernetClient*>(arg);

	if(client->_connected) {
		if(cpcb->keep_cnt_sent++ > 4) {
			cpcb->keep_cnt_sent = 0;
			/* Stop polling */
			tcp_poll(cpcb, NULL, 0);
			tcp_abort(cpcb);
			return ERR_OK;
		}
		/* Send tcp keep alive probe */
		tcp_keepalive(cpcb);
		return ERR_OK;
	}

	/* We only end up here if the connection failed to close
	 * in an earlier call to tcp_close */
	err_t err = tcp_close(cpcb);

	if (err != ERR_OK) {
		/* error closing, try again later in poll (every 2 sec) */
		tcp_poll(cpcb, do_poll, 4);
		return err;
	}

	return err;
}

void EthernetClient::do_err(void * arg, err_t err)
{
	EthernetClient *client = static_cast<EthernetClient*>(arg);

	if(client->_connected) {
		client->_connected = false;
		return;
	}

	/*
	 * Set connected to true to finish connecting.
	 * ::connect wil take care of figuring out if we are truly connected
	 * by looking at the socket state
	 */
	client->_connected = true;
}

err_t EthernetClient::do_connected(void * arg, struct tcp_pcb * tpcb, err_t err)
{
	EthernetClient *client = static_cast<EthernetClient*>(arg);

	client->_connected = true;

	return err;
}

err_t EthernetClient::do_recv(void *arg, struct tcp_pcb *cpcb, struct pbuf *p, err_t err)
{
	/*
	 * Get the client object from the argument
	 * to get access to variables and functions
	 */
	EthernetClient *client = static_cast<EthernetClient*>(arg);

	if(p == 0) {
		client->_connected = false;
		return ERR_OK;
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

	if(cpcb == NULL) {
		return false;
	}

	tcp_arg(cpcb, this);
	tcp_recv(cpcb, do_recv);
	tcp_err(cpcb, do_err);

	uint8_t val = tcp_connect(cpcb, &dest, port, do_connected);

	if(val != ERR_OK) {
		return false;
	}


	/* Wait for the connection.
	 * Abort if the connection does not succeed within 10 sec */
	unsigned long then = millis();

	while(!_connected) {
		unsigned long now = millis();
		delay(10);
		if(now - then > CONNECTION_TIMEOUT) {
			tcp_close(cpcb);
			cpcb = NULL;
			return false;
		}
	}

	if(cpcb->state != ESTABLISHED) {
		_connected = false;
	}

	/* Poll to determine if the peer is still alive */
	tcp_poll(cpcb, do_poll, 10);
	return _connected;
}

size_t EthernetClient::write(uint8_t b) {
	return write(&b, 1);
}


size_t EthernetClient::write(const uint8_t *buf, size_t size) {
	uint32_t i = 0, inc = 0;
	boolean stuffed_buffer = false;

	// Attempt to write in 1024-byte increments.
	while (i < size) {
		inc = (size-i) < 1024 ? size-i : 1024;
		err_t err = tcp_write(cpcb, buf+i, inc, TCP_WRITE_FLAG_COPY);
		if (err != ERR_MEM) {
			// Keep enqueueing the lwIP buffer until it's full...
			i += inc;
			stuffed_buffer = false;
		} else {
			if (!stuffed_buffer) {
				// Buffer full; force output
				if (cs->mode) tcp_output(cpcb);
				stuffed_buffer = true;
			} else {
				delay(1);  // else wait a little bit for lwIP to flush its buffers
			}
		}
	}
	// flush any remaining queue contents
	if (!stuffed_buffer) {
		if (cs->mode) tcp_output(cpcb);
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
	uint16_t avail = available();
	uint16_t i;
	int b;

	if(!avail)
		return -1;

	/* TODO: Replace lazy method with optimized on */
	for(i = 0; i < size; i++) {
		b = read();
		if(b == -1)
			break;
		buf[i] = b;
	}

	return i;
}

int EthernetClient::peek()
{
	uint8_t b;

	if (!available())
		return -1;

	uint8_t *buf = (uint8_t *)cs->p->payload;
	b = buf[*_read];

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

	_connected = false;
	/* Stop frees any resources including any unread buffers */
	err_t err;

	if(cpcb) {
		tcp_err(cpcb, NULL);

		if(_p) {
			tcp_recved(cpcb, _p->tot_len);
			pbuf_free(_p);
			_p = NULL;
		}

		err = tcp_close(cpcb);
	}

	if (err != ERR_OK) {
		/* Error closing, try again later in poll (every 2 sec) */
		tcp_poll(cpcb, do_poll, 4);
	} else {
		cpcb = NULL;
	}
}

uint8_t EthernetClient::connected()
{
	return (available() || _connected);
}

uint8_t EthernetClient::status()
{
	if(cpcb == NULL) {
		return CLOSED;
	}

	return cpcb->state;
}

EthernetClient::operator bool()
{
	if(cpcb == NULL) return false;
	if(cpcb->state != ESTABLISHED) return false;

	return true;
}
