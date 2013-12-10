#ifndef wifiudp_h
#define wifiudp_h

#include <Stream.h>
#include <IPAddress.h>

#define MAX_SENDTO_SIZE 95
#define MAX_RECVFROM_SIZE 95
#define UDP_TX_PACKET_MAX_SIZE 255
#define UDP_RX_PACKET_MAX_SIZE 255
#define NO_SOCKET_AVAIL 255

class WiFiUDP : public Stream {
private:
	/* socket descriptor for client and server */
	long udpSocket;
	/* Port for when in server mode */
	uint16_t _serverPort;
	/* IP of the remote host talking to us */
	IPAddress _remoteIp;
	/* Port of the remote host talking to us */
	uint16_t _remotePort;

	/* Socket address when in server mode */
	sockaddr serverSocketAddr;

	/* Position in the rx buffer */
	uint16_t rx_buf_pos;
	/* Counter to keep track of if we need to read fromt the socket to fill the rx buffer */
	uint16_t rx_buf_fill;
	/* rx buffer that is filled with a call to recvfrom */
	unsigned char rx_buf[UDP_RX_PACKET_MAX_SIZE];

	/* Port for when in client mode */
	uint16_t _clientPort;
	/* Socket address when in client mode */
	sockaddr clientSocketAddr;
	/* Counter to keep track of how many bytes are in the tx buffer */
	uint16_t tx_buf_fill;
	/* tx buffer */
	unsigned char tx_buf[UDP_TX_PACKET_MAX_SIZE];

public:
	/* Constructor */
	WiFiUDP();
	/* initialize, start listening on specified port. Returns 1 if successful, 0 if there are no sockets available to use */
	uint8_t begin(uint16_t);
	/* Finish with the UDP socket */
	void stop();

	/* API's related to sending packets */

	/* Start building up a packet to send to the remote host specific in ip and port
	 * Returns 1 if successful, 0 if there was a problem with the supplied IP address or port */
	int beginPacket(IPAddress ip, uint16_t _port);
	/* Start building up a packet to send to the remote host specific in host and port
	 * Returns 1 if successful, 0 if there was a problem resolving the hostname or port */
	int beginPacket(const char *host, uint16_t port);
	/* Finish off this packet and send it
	 * Returns 1 if the packet was sent successfully, 0 if there was an error */
	int endPacket();
	/* Write a single byte into the packet */
	virtual size_t write(uint8_t);
	/* Write size bytes from buffer into the packet */
	virtual size_t write(const uint8_t *buffer, size_t size);

	using Print::write;

	/* API's related to reading packets */

	/* Start processing the next available incoming packet
	 * Returns the size of the packet in bytes, or 0 if no packets are available */
	int parsePacket();
	/* Number of bytes remaining in the current packet */
	int available();
	/* Return the next byte from the current packet without moving on to the next byte */
	virtual int peek();
	/* Finish reading the current packet */
	virtual void flush();
	/* Read a single byte from the current packet */
	virtual int read();
	/* Read up to len bytes from the current packet and place them into buffer
	 * Returns the number of bytes read, or 0 if none are available */
	virtual int read(unsigned char* buffer, size_t len);
	/* Read up to len characters from the current packet and place them into buffer
	 * Returns the number of characters read, or 0 if none are available */
	virtual int read(char* buffer, size_t len) { return read((unsigned char*)buffer, len); };
	/* Return the IP address of the host who sent the current incoming packet */
	virtual IPAddress remoteIP();
	/* Return the port of the host who sent the current incoming packet */
	virtual uint16_t remotePort();

	friend class WiFiClass;

};

#endif
