#include "utility/SimplelinkWifi.h"
#include "WiFi.h"
#include "Energia.h"
extern WiFiClass WiFi;
#define socket_overflow 2

WiFiClient::WiFiClient() : clientSocket(255) {
	rx_buf_pos=0;
	rx_buf_fill=0;
	no_more_bytes = 0;
}

WiFiClient::WiFiClient(long _sock) : clientSocket(_sock) {
	rx_buf_pos=0;
	rx_buf_fill=0;
	no_more_bytes = 0;
}

int WiFiClient::available()
{
	if(clientSocket == 255) return 0;

	int ret = 0;
	timeval timeout;
	memset(&timeout, 0, sizeof(timeval));
	timeout.tv_sec = 0;
	timeout.tv_usec = 500000;
	fd_set readsds, errorsds;
	FD_ZERO(&readsds);
	FD_ZERO(&errorsds);
	FD_SET(clientSocket, &readsds);
	FD_SET(clientSocket, &errorsds);

//	int wRecvTimeout = 5;
//	setsockopt (clientSocket, SOL_SOCKET, SOCKOPT_RECV_TIMEOUT, &wRecvTimeout, sizeof(wRecvTimeout));
//	// Nothing more to do if no packet received
//	if (ret <= 0) {
//		return 0;
//	}

	if(!rx_buf_fill){
		ret = select(clientSocket+1, &readsds, NULL, &errorsds, &timeout);
		if(!FD_ISSET(clientSocket, &readsds)) return 0;
		rx_buf_fill = recv(((long)clientSocket)&0xFF, rx_buf, 16, 0);//RX_BUF_SIZE

		if(rx_buf_fill <= 0) {
			rx_buf_pos = 0;
			rx_buf_fill = 0;
		}
	}

	return rx_buf_fill - rx_buf_pos;
}

int WiFiClient::read(uint8_t* buf, size_t size)
{
	return 0;
}

int WiFiClient::peek()
{
	return 0;
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

	b=rx_buf[rx_buf_pos];
	rx_buf_pos++;
	if(rx_buf_pos>=rx_buf_fill){rx_buf_pos=0;rx_buf_fill=0;}

	return b;
}

uint8_t WiFiClient::connected()
{
	if(clientSocket == 255) return 0;
	if(available()) return 1;
	/* TODO: Danger! This assumes that the connection has been close
	 * if there is no data available.
	 * The correct thing to do would be to figure out if the connections is still alive.
	 * send() does the trick but for some reason the CC3000 ends up running out of buffers so no go!
	 */ 
	return 0;

//	if((send( clientSocket, "", 0, 0) <= 0)) {
//		return 0;
//	} else {
//		return 1;
//	}
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
			i = send(((long)clientSocket)&0xFF, buf+i, strlen-i, 0);
			//i=strlen;
		}
		else {
			i = send(((long)clientSocket)&0xFF, buf+i, TX_BUF_SIZE, 0);
			//i+=TX_BUF_SIZE;
		}
	}while( i < strlen);

	return strlen;
}

void WiFiClient::stop() {
	if (clientSocket == 255)
		return;

	closesocket(clientSocket);
	WiFi.countSocket(0);
	clientSocket = 255;
}
