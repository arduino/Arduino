#ifndef WIFI_h
#define WIFI_h
#include "SimplelinkWifi.h"
#include "IPAddress.h"



class WiFiClass
{
	private:
    	static void init();	
	public:
	
	WiFiClass();
	void setCSpin(uint8_t pin);
	void setENpin(uint8_t pin);
	void setIRQpin(uint8_t pin);
	int begin();
	int begin(char* ssid);
	int begin(char* ssid, unsigned char* pass);
	int begin(char* ssid, uint8_t key_idx, unsigned char* key );
	uint8_t status();
	//int startSmartConfig();
	bool countSocket(bool add_sock);
};

extern WiFiClass WiFi;


// client

class WiFiClient{
private:
  unsigned short int port;
  long clientSocket;
  uint8_t rx_buf[16];
  int rx_buf_pos;
  int rx_buf_fill;
  sockaddr clientSocketAddr;
public:
	WiFiClient();
	WiFiClient(long sock);
	int available();
	int read();
	int connect(IPAddress ip, uint16_t port);
	uint8_t connected();
	operator bool();
	size_t write(uint8_t);
	size_t print(char*);
	size_t print(uint16_t);
	size_t println(uint16_t);
	size_t println(char*);
	size_t println();
	void stop();
	
	friend class WiFiClass;

};

// server
class WiFiServer {
private:
  unsigned short int port;
  long serverSocket;
  sockaddr serverSocketAddr;
  long clientDescriptor;
public:
  WiFiServer(uint16_t);
  WiFiClient available();
  void begin();
  size_t write(uint8_t);

  friend class WiFiClass;

};


#define UDP_TX_PACKET_MAX_SIZE 24

class WiFiUDP {
private:
  unsigned short int port;
  long udpSocket;
  sockaddr udpSocketAddr;
  volatile unsigned int bytesRecvd;
  int packetSize;
  unsigned char packetBuffer[25]; //25 is from basic wifi application  pucCC3000_Rx_Buffer[CC3000_APP_BUFFER_SIZE + CC3000_RX_BUFFER_OVERHEAD_SIZE];
  unsigned char rx_buf[25];
  long udpSocket2;
  sockaddr udpSocketAddr2;  

public:
  WiFiUDP();  // Constructor
  uint8_t begin(uint16_t);	// initialize, start listening on specified port. Returns 1 if successful, 0 if there are no sockets available to use

  int beginPacket(IPAddress ip, uint16_t _port);
  

  int endPacket();

  size_t write(const uint8_t *buffer, size_t size);
  

  int parsePacket();
  int available();


  int read(char* buffer, size_t len);
  void stop();
  
  friend class WiFiClass;

  

};

#endif
