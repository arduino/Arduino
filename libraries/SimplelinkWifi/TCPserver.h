#ifndef TCPSERVER_h
#define TCPSERVER_h
#include "utility/SimplelinkWifi.h"


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
#endif
