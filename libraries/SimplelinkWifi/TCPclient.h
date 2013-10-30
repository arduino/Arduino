#ifndef tcpclient_h
#define tcpclient_h
#include "IPAddress.h"
#include "Print.h"
#include "Client.h"

class WiFiClient : public Client
{
	private:
		unsigned short int port;
		long clientSocket;
		uint8_t rx_buf[16];
		int rx_buf_pos;
		int rx_buf_fill;
		int no_more_bytes;
		sockaddr clientSocketAddr;
	public:
		WiFiClient();
		WiFiClient(long sock);
		int available();
		int read();
		virtual int connect(IPAddress ip, uint16_t port);
		virtual int connect(const char *host, uint16_t port);
		virtual int read(uint8_t *buf, size_t size);
		virtual int peek();
		virtual void flush();
		virtual uint8_t connected();
		operator bool();
		virtual size_t write(uint8_t);
		virtual size_t write(const uint8_t *buf, size_t size);
		virtual void stop();
	
	using Print::write;
};
#endif
