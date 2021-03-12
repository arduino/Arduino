/*
  BLEStream.h

  Based on BLESerial.cpp by Voita Molda
  https://github.com/sandeepmistry/arduino-BLEPeripheral/blob/master/examples/serial/BLESerial.h

  Last updated April 4th, 2016
 */

#ifndef _BLE_STREAM_H_
#define _BLE_STREAM_H_

#include <Arduino.h>
#if defined(_VARIANT_ARDUINO_101_X_)
#include <CurieBLE.h>
#define _MAX_ATTR_DATA_LEN_ BLE_MAX_ATTR_DATA_LEN
#else
#include <BLEPeripheral.h>
#define _MAX_ATTR_DATA_LEN_ BLE_ATTRIBUTE_MAX_VALUE_LENGTH
#endif

#define BLESTREAM_TXBUFFER_FLUSH_INTERVAL 80
#define BLESTREAM_MIN_FLUSH_INTERVAL 8 // minimum interval for flushing the TX buffer

// #define BLE_SERIAL_DEBUG

class BLEStream : public BLEPeripheral, public Stream
{
  public:
    BLEStream(unsigned char req = 0, unsigned char rdy = 0, unsigned char rst = 0);

    void begin(...);
    bool poll();
    void end();
    void setFlushInterval(int);

    virtual int available(void);
    virtual int peek(void);
    virtual int read(void);
    virtual void flush(void);
    virtual size_t write(uint8_t byte);
    using Print::write;
    virtual operator bool();

  private:
    bool _connected;
    unsigned long _flushed;
    int _flushInterval;
    static BLEStream* _instance;

    size_t _rxHead;
    size_t _rxTail;
    size_t _rxCount() const;
    unsigned char _rxBuffer[256];
    size_t _txCount;
    unsigned char _txBuffer[_MAX_ATTR_DATA_LEN_];

    BLEService _uartService = BLEService("6E400001-B5A3-F393-E0A9-E50E24DCCA9E");
    BLEDescriptor _uartNameDescriptor = BLEDescriptor("2901", "UART");
    BLECharacteristic _rxCharacteristic = BLECharacteristic("6E400002-B5A3-F393-E0A9-E50E24DCCA9E", BLEWriteWithoutResponse, _MAX_ATTR_DATA_LEN_);
    BLEDescriptor _rxNameDescriptor = BLEDescriptor("2901", "RX - Receive Data (Write)");
    BLECharacteristic _txCharacteristic = BLECharacteristic("6E400003-B5A3-F393-E0A9-E50E24DCCA9E", BLENotify, _MAX_ATTR_DATA_LEN_);
    BLEDescriptor _txNameDescriptor = BLEDescriptor("2901", "TX - Transfer Data (Notify)");

    void _received(const unsigned char* data, size_t size);
    static void _received(BLECentral& /*central*/, BLECharacteristic& rxCharacteristic);
};


/*
 * BLEStream.cpp
 * Copied here as a hack to avoid having to install the BLEPeripheral libarary even if it's
 * not needed.
 */

BLEStream* BLEStream::_instance = NULL;

BLEStream::BLEStream(unsigned char req, unsigned char rdy, unsigned char rst) :
#if defined(_VARIANT_ARDUINO_101_X_)
  BLEPeripheral()
#else
  BLEPeripheral(req, rdy, rst)
#endif
{
  this->_txCount = 0;
  this->_rxHead = this->_rxTail = 0;
  this->_flushed = 0;
  this->_flushInterval = BLESTREAM_TXBUFFER_FLUSH_INTERVAL;
  BLEStream::_instance = this;

  addAttribute(this->_uartService);
  addAttribute(this->_uartNameDescriptor);
  setAdvertisedServiceUuid(this->_uartService.uuid());
  addAttribute(this->_rxCharacteristic);
  addAttribute(this->_rxNameDescriptor);
  this->_rxCharacteristic.setEventHandler(BLEWritten, BLEStream::_received);
  addAttribute(this->_txCharacteristic);
  addAttribute(this->_txNameDescriptor);
}

void BLEStream::begin(...)
{
  BLEPeripheral::begin();
#ifdef BLE_SERIAL_DEBUG
  Serial.println(F("BLEStream::begin()"));
#endif
}

bool BLEStream::poll()
{
  // BLEPeripheral::poll is called each time connected() is called
  this->_connected = BLEPeripheral::connected();
  if (millis() > this->_flushed + this->_flushInterval) {
    flush();
  }
  return this->_connected;
}

void BLEStream::end()
{
  this->_rxCharacteristic.setEventHandler(BLEWritten, (void(*)(BLECentral&, BLECharacteristic&))NULL);
  this->_rxHead = this->_rxTail = 0;
  flush();
  BLEPeripheral::disconnect();
}

int BLEStream::available(void)
{
// BLEPeripheral::poll only calls delay(1) in CurieBLE so skipping it here to avoid the delay
#ifndef _VARIANT_ARDUINO_101_X_
  // TODO Need to do more testing to determine if all of these calls to BLEPeripheral::poll are
  // actually necessary. Seems to run fine without them, but only minimal testing so far.
  BLEPeripheral::poll();
#endif
  int retval = (this->_rxHead - this->_rxTail + sizeof(this->_rxBuffer)) % sizeof(this->_rxBuffer);
#ifdef BLE_SERIAL_DEBUG
  if (retval > 0) {
    Serial.print(F("BLEStream::available() = "));
    Serial.println(retval);
  }
#endif
  return retval;
}

int BLEStream::peek(void)
{
#ifndef _VARIANT_ARDUINO_101_X_
  BLEPeripheral::poll();
#endif
  if (this->_rxTail == this->_rxHead) return -1;
  uint8_t byte = this->_rxBuffer[this->_rxTail];
#ifdef BLE_SERIAL_DEBUG
  Serial.print(F("BLEStream::peek() = 0x"));
  Serial.println(byte, HEX);
#endif
  return byte;
}

int BLEStream::read(void)
{
#ifndef _VARIANT_ARDUINO_101_X_
  BLEPeripheral::poll();
#endif
  if (this->_rxTail == this->_rxHead) return -1;
  this->_rxTail = (this->_rxTail + 1) % sizeof(this->_rxBuffer);
  uint8_t byte = this->_rxBuffer[this->_rxTail];
#ifdef BLE_SERIAL_DEBUG
  Serial.print(F("BLEStream::read() = 0x"));
  Serial.println(byte, HEX);
#endif
  return byte;
}

void BLEStream::flush(void)
{
  if (this->_txCount == 0) return;
#ifndef _VARIANT_ARDUINO_101_X_
  // ensure there are available packets before sending
  while(!this->_txCharacteristic.canNotify()) {
    BLEPeripheral::poll();
  }
#endif
  this->_txCharacteristic.setValue(this->_txBuffer, this->_txCount);
  this->_flushed = millis();
  this->_txCount = 0;
#ifdef BLE_SERIAL_DEBUG
  Serial.println(F("BLEStream::flush()"));
#endif
}

size_t BLEStream::write(uint8_t byte)
{
#ifndef _VARIANT_ARDUINO_101_X_
  BLEPeripheral::poll();
#endif
  if (this->_txCharacteristic.subscribed() == false) return 0;
  this->_txBuffer[this->_txCount++] = byte;
  if (this->_txCount == sizeof(this->_txBuffer)) flush();
#ifdef BLE_SERIAL_DEBUG
  Serial.print(F("BLEStream::write( 0x"));
  Serial.print(byte, HEX);
  Serial.println(F(") = 1"));
#endif
  return 1;
}

BLEStream::operator bool()
{
  bool retval = this->_connected = BLEPeripheral::connected();
#ifdef BLE_SERIAL_DEBUG
  Serial.print(F("BLEStream::operator bool() = "));
  Serial.println(retval);
#endif
  return retval;
}

void BLEStream::setFlushInterval(int interval)
{
  if (interval > BLESTREAM_MIN_FLUSH_INTERVAL) {
    this->_flushInterval = interval;
  }
}

void BLEStream::_received(const unsigned char* data, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    this->_rxHead = (this->_rxHead + 1) % sizeof(this->_rxBuffer);
    this->_rxBuffer[this->_rxHead] = data[i];
  }
#ifdef BLE_SERIAL_DEBUG
  Serial.print(F("BLEStream::received("));
  for (int i = 0; i < size; i++) Serial.print(data[i], HEX);
  Serial.println(F(")"));
#endif
}

void BLEStream::_received(BLECentral& /*central*/, BLECharacteristic& rxCharacteristic)
{
  BLEStream::_instance->_received(rxCharacteristic.value(), rxCharacteristic.valueLength());
}


#endif // _BLE_STREAM_H_
