#include "utility/SimplelinkWifi.h"
#include "WiFi.h"
#include "Energia.h"

extern WiFiClass WiFi;

extern fd_set gConnectedSockets;

WiFiClient::WiFiClient() : clientSocket(255) {
	rx_buf_pos=0;
	rx_buf_fill=0;
	no_more_bytes = 0;
}

WiFiClient::WiFiClient(long _sock) : clientSocket(_sock) {
	rx_buf_pos=0;
	rx_buf_fill=0;
	no_more_bytes = 0;
	FD_CLR(_sock, &gConnectedSockets);
}

int WiFiClient::available()
{
	if(clientSocket == 255) return 0;

	int ret;
	timeval timeout;
	memset(&timeout, 0, sizeof(timeval));
	timeout.tv_sec = 0;
	timeout.tv_usec = 500000;
	fd_set readsds, errorsds;
	FD_ZERO(&readsds);
	FD_ZERO(&errorsds);
	FD_SET(clientSocket, &readsds);
	FD_SET(clientSocket, &errorsds);

	if(!rx_buf_fill){
		ret = select(clientSocket + 1, &readsds, NULL, &errorsds, &timeout);
		if(!FD_ISSET(clientSocket, &readsds)) return 0;
		rx_buf_fill = recv(((long)clientSocket) & 0xFF, rx_buf, 16, 0);

		if(rx_buf_fill <= 0) {
			rx_buf_pos = 0;
			rx_buf_fill = 0;
		}
	}

	return rx_buf_fill - rx_buf_pos;
}

int WiFiClient::read(uint8_t* buf, size_t size)
{
	size_t i = 0;
	uint8_t *ptr = buf;
	int b;

	if(!size) return -1;

	while(i < size) {
		b = read();

		if(b < 0)
			return i;

		*ptr = (uint8_t) b;
		ptr++;
		i++;
	}

	return i;
}

int WiFiClient::peek()
{
	if(!available()) return 0;

	return rx_buf[rx_buf_pos];
}

void WiFiClient::flush() {
	while (available())
		read();
}

int WiFiClient::read()
{
	uint8_t b = 0;

	if (!available())
		return -1;

	b = rx_buf[rx_buf_pos];
	rx_buf_pos++;

	if(rx_buf_pos >= rx_buf_fill) {
		rx_buf_pos=0;
		rx_buf_fill=0;
	}

	return b;
}

uint8_t WiFiClient::connected()
{
	if(clientSocket == 255) return 0;
	return !(!FD_ISSET(clientSocket, &gConnectedSockets) && !available());
}

WiFiClient::operator bool() {
	return clientSocket != 255;
}

int WiFiClient::connect(const char* host, uint16_t port) {
	IPAddress remote_addr;
	if (WiFi.hostByName(host, remote_addr) > 0)
	{
		return connect(remote_addr, port);
	}
	return 0;
}

int WiFiClient::connect(IPAddress ip, uint16_t port) {
	clientSocketAddr.sa_family = AF_INET;
	clientSocketAddr.sa_data[0] = (unsigned char)((port & 0xFF00)>> 8);
	clientSocketAddr.sa_data[1] = (unsigned char)(port & 0x00FF);
	clientSocketAddr.sa_data[2] = ip[0];
	clientSocketAddr.sa_data[3] = ip[1];
	clientSocketAddr.sa_data[4] = ip[2];
	clientSocketAddr.sa_data[5] = ip[3];

	socklen_t addrlen;
	addrlen = sizeof(clientSocketAddr);

	if ((clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) >=0)
	{
		if (sl_connect(clientSocket, (sockaddr *)&clientSocketAddr, addrlen) >=0) {
			WiFi.countSocket(1);
			/* Indicate that the socket is connected in the fd_set */
			FD_SET(clientSocket, &gConnectedSockets);
			return 1;
		}
	}

	return 0;
}


size_t WiFiClient::write(uint8_t b)
{
	send(((long)clientSocket)&0xFF, &b, 1, 0);
	return 1;
}

size_t WiFiClient::write(const uint8_t *buf, size_t size)
{

	int strlen = size,i = 0;

	if(size == 0) return 0;

	do{
		if(strlen-i<TX_BUF_SIZE){
			i += send(((long)clientSocket)&0xFF, buf+i, strlen-i, 0);
		}
		else {
			i += send(((long)clientSocket)&0xFF, buf+i, TX_BUF_SIZE, 0);
		}
	}while( i < strlen);

	return strlen;
}

void WiFiClient::stop() {
	if (clientSocket == 255)
		return;

	closesocket(clientSocket);
	FD_CLR(clientSocket, &gConnectedSockets);
	WiFi.countSocket(0);
	clientSocket = 255;
}
