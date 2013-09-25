#ifndef TCPSERVER_h
#define TCPSERVER_h
#include "SimplelinkWifi.h"

class WiFiClient;

class WiFiServer {
private:
  uint16_t _port;
  
public:
  WiFiServer(uint16_t);
  WiFiClient available(uint8_t* status = NULL);
  // void begin();
  // virtual size_t write(uint8_t);
  // virtual size_t write(const uint8_t *buf, size_t size);
  // uint8_t status();

  // using Print::write;
};

#endif
