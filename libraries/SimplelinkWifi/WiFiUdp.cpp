#include "utility/SimplelinkWifi.h"
#include "WiFi.h"
#include "WiFiUdp.h"
#include "Energia.h"

WiFiUDP::WiFiUDP() : udpSocket (NO_SOCKET_AVAIL) {
	memset(rx_buf, 0, sizeof(rx_buf));
	memset(tx_buf, 0, sizeof(tx_buf));
	rx_buf_pos = 0;
	rx_buf_fill = 0;
	tx_buf_fill = 0;
}

/* Start WiFiUDP socket, listening at local port PORT */
uint8_t WiFiUDP::begin(uint16_t port)
{
	int ret;

	/* Allocate a UDP socket */
	udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	/* Any sockets available? */
	if (udpSocket == NO_SOCKET_AVAIL) {
		return 0;
	}

	serverSocketAddr.sa_family = AF_INET;
	/* Set the Port Number */
	serverSocketAddr.sa_data[0] = (unsigned char)((port & 0xFF00)>> 8);
	serverSocketAddr.sa_data[1] = (unsigned char)(port & 0x00FF);
	memset (&serverSocketAddr.sa_data[2], 0, 4);

	ret = bind(udpSocket, &serverSocketAddr, sizeof(sockaddr));

	/* Did bind fail? */
	if(ret == -1) return 0;

	/* Set internal port to port passed to us */
	_serverPort = port;

	/* up the socket count */
	WiFi.countSocket(1);

	/* Return success */
	return 1;
}

int WiFiUDP::parsePacket()
{
	return available();
}

int WiFiUDP::available()
{
	if(udpSocket == NO_SOCKET_AVAIL) return 0;

	socklen_t fromlen;
	sockaddr from;

	timeval timeout;
	memset(&timeout, 0, sizeof(timeval));
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	fd_set readsds, errorsds;
	FD_ZERO(&readsds);
	FD_ZERO(&errorsds);
	FD_SET(udpSocket, &readsds);
	FD_SET(udpSocket, &errorsds);

	if(!rx_buf_fill) {
		select(udpSocket + 1, &readsds, NULL, &errorsds, &timeout);

		/* If the socket is reported to be closed then the only way to deal
		 * with this is to bluntly open it again using begin(...) */
		if(FD_ISSET(udpSocket, &errorsds)) {
			if(_serverPort != 0) {
				begin(_serverPort);
			}
			return 0;
		}

		if(!FD_ISSET(udpSocket, &readsds)) return 0;

		rx_buf_fill = recvfrom(udpSocket, rx_buf, MAX_RECVFROM_SIZE, 0, &from, &fromlen);

		_remoteIp[0] = from.sa_data[2];
		_remoteIp[1] = from.sa_data[3];
		_remoteIp[2] = from.sa_data[4];
		_remoteIp[3] = from.sa_data[5];

		_remotePort = ((from.sa_data[0] << 8) & 0xFF00) | (from.sa_data[1] & 0x00FF);
	}

	return rx_buf_fill - rx_buf_pos;
}

int WiFiUDP::read()
{
	uint8_t b = 0;

	uint16_t avail;
	avail = available();

	if (avail == 0)
		return -1;

	b = rx_buf[rx_buf_pos];
	rx_buf_pos++;

	if(rx_buf_pos >= rx_buf_fill) {
		rx_buf_pos = 0;
		rx_buf_fill = 0;
	}

	return b;
}

int WiFiUDP::read(unsigned char* buf, size_t size)
{
	size_t i = 0;
	uint8_t *ptr = buf;
	int b;

	if(!size) return -1;

	while(i < size) {
		b = read();

		if(b < 0)
			return i;

		*ptr = (uint8_t)b;
		ptr++;
		i++;
	}

	return i;
}

int WiFiUDP::beginPacket(const char *host, uint16_t port)
{
	// Look up the host first
	int ret = 0;
	IPAddress remote_addr;

	if (WiFi.hostByName(host, remote_addr)) {
		return beginPacket(remote_addr, port);
	}

	return ret;
}

int WiFiUDP::beginPacket(IPAddress ip, uint16_t port)
{
	clientSocketAddr.sa_family = AF_INET;
	// Set the Port Number
	clientSocketAddr.sa_data[0] = (unsigned char)((port & 0xFF00)>> 8);
	clientSocketAddr.sa_data[1] = (unsigned char)(port & 0x00FF);
	clientSocketAddr.sa_data[2] = ip[0];
	clientSocketAddr.sa_data[3] = ip[1];
	clientSocketAddr.sa_data[4] = ip[2];
	clientSocketAddr.sa_data[5] = ip[3];

	tx_buf_fill = 0;

	timeval timeout;
	memset(&timeout, 0, sizeof(timeval));
	timeout.tv_sec = 0;
	timeout.tv_usec = 0;
	fd_set errorsds;
	FD_ZERO(&errorsds);
	FD_SET(udpSocket, &errorsds);

	select(udpSocket + 1, NULL, NULL, &errorsds, &timeout);

	/* If we do not already have a socket then allocate one */
	if ((udpSocket != NO_SOCKET_AVAIL) && !FD_ISSET(udpSocket, &errorsds))
		return 1;

	/* Allocate a socket */
	udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	/* No socket available or somthing bad happened */
	if(udpSocket < 0) {
		udpSocket = NO_SOCKET_AVAIL;
		return 0;
	}

	WiFi.countSocket(1);

	return 1;
}

int WiFiUDP::peek()
{
	if(!available()) return -1;

	return rx_buf[rx_buf_pos];
}

void WiFiUDP::flush()
{
	while (available())
		read();
}

IPAddress WiFiUDP::remoteIP()
{
	return _remoteIp;
}

uint16_t  WiFiUDP::remotePort()
{
	return _remotePort;
}

size_t WiFiUDP::write(uint8_t byte)
{
	return write(&byte, 1);
}

size_t WiFiUDP::write(const uint8_t *buffer, size_t size)
{
	memcpy(&tx_buf[tx_buf_fill], buffer, size);
	tx_buf_fill += size;
	return sizeof(buffer);
}

int WiFiUDP::endPacket()
{
	int len = tx_buf_fill, i = 0;

	if(tx_buf_fill == 0) return 0;

	timeval timeout;
	memset(&timeout, 0, sizeof(timeval));
	timeout.tv_sec = 0;
	timeout.tv_usec = 5000;
	fd_set writesds, errorsds;
	FD_ZERO(&writesds);
	FD_ZERO(&errorsds);
	FD_SET(udpSocket, &writesds);
	FD_SET(udpSocket, &errorsds);

	select(udpSocket + 1, NULL, &writesds, &errorsds, &timeout);

	/* For whatever reason sento chokes when sending more than 96 bytes.
	 * Sending in chunks of 64 bytes works around this limitation. */
	do {
		if(len - i < MAX_SENDTO_SIZE) {
			i += sendto(udpSocket, tx_buf+i, len-i, 0, &clientSocketAddr, sizeof(sockaddr));
		} else {
			i += sendto(udpSocket, tx_buf+i, MAX_SENDTO_SIZE, 0, &clientSocketAddr, sizeof(sockaddr));
		}
	} while(i < len);

	return 0;
}

void WiFiUDP::stop()
{
	_serverPort = 0;
	_clientPort = 0;

	if (udpSocket == NO_SOCKET_AVAIL)
		return;

	closesocket(udpSocket);
	WiFi.countSocket(0);
	udpSocket = NO_SOCKET_AVAIL;
}
