#ifndef ethernetserver_h
#define ethernetserver_h

#include "Server.h"

class EthernetClient;

class EthernetServer : 
public Server {
public:
  //Callback definition
  typedef void Callback(EthernetClient &socket);
  // Callbacks
  void registerConnectCallback(Callback *callback);

  EthernetServer(uint16_t);
  EthernetClient available();
  virtual void begin();
  virtual size_t write(uint8_t);
  virtual size_t write(const uint8_t *buf, size_t size);
  using Print::write;

private:
  Callback *onConnect;

  uint16_t _port;
  void accept();

};

#endif
