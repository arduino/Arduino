#ifndef client_h
#define client_h
#include "WProgram.h"	
#include "Print.h"

class Client : public Stream {

public:
  Client();
  Client(uint8_t);
  Client(uint8_t *, uint16_t);

  uint8_t status();
  uint8_t connect();
  uint8_t connect(uint8_t *remote_ip, uint16_t remote_port);
  virtual void write(uint8_t);
  virtual void write(const char *str);
  virtual void write(const uint8_t *buf, size_t size);
  virtual int available();
  virtual int read();
  virtual int read(uint8_t *buf, size_t size);
  virtual int peek();
  virtual void flush();
  void stop();
  uint8_t connected();
  uint8_t operator==(int);
  uint8_t operator!=(int);
  operator bool();

  // Add data to the packet about to be sent.  Only valid to call this after
  // a call to connect or finishSendPacket.
  // @param buf - data to append to the outgoing packet
  // @param len - number of bytes to append from buf
  // @return Number of bytes successfully appended
  uint16_t addData(uint8_t *buf, uint16_t len);

  // Add a single byte of data to the packet in progress
  uint16_t addData(uint8_t b);

  // Send the packet.  Only valid to call this after a call to connect()
  // and at least one call to addData. Or finishSendPacket, and then more addData()
  // @return 1 if successful, or 0 if there was an error
  uint16_t finishSendPacket(); //send the packet

  friend class Server;

private:
  static uint16_t _srcport;
  uint8_t _sock;
  uint8_t *_ip;
  uint16_t _port;
  uint16_t _offset; // offset into the packet being sent (used in streaming API)
};

#endif
