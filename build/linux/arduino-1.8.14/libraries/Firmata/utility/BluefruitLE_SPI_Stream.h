/*
  BluefruitLE_SPI_Stream.h

  Documentation for the various AT commands used below is available at
  https://learn.adafruit.com/adafruit-feather-m0-bluefruit-le/at-commands
 */

#ifndef _BLUEFRUIT_LE_SPI_STREAM_H_
#define _BLUEFRUIT_LE_SPI_STREAM_H_

#include <Adafruit_BluefruitLE_SPI.h>


class BluefruitLE_SPI_Stream : public Stream
{
  public:
    BluefruitLE_SPI_Stream(int8_t csPin, int8_t irqPin, int8_t rstPin);

    void setLocalName(const char *localName);
    void setConnectionInterval(unsigned short minConnInterval, unsigned short maxConnInterval);
    void setFlushInterval(int flushInterval);

    void begin();
    bool poll();
    void end();

    // Print overrides
    size_t write(uint8_t byte);
    using Print::write;  // Expose other write variants

    // Stream overrides
    int available();
    int read();
    int peek();
    void flush();

  private:
    Adafruit_BluefruitLE_SPI ble;

    String localName;
    unsigned short minConnInterval;
    unsigned short maxConnInterval;

    uint8_t txBuffer[SDEP_MAX_PACKETSIZE];
    size_t txCount;
};


BluefruitLE_SPI_Stream::BluefruitLE_SPI_Stream(int8_t csPin, int8_t irqPin, int8_t rstPin) :
  ble(csPin, irqPin, rstPin),
  minConnInterval(0),
  maxConnInterval(0),
  txCount(0)
{ }

void BluefruitLE_SPI_Stream::setLocalName(const char *localName)
{
  this->localName = localName;
}

void BluefruitLE_SPI_Stream::setConnectionInterval(unsigned short minConnInterval, unsigned short maxConnInterval)
{
  this->minConnInterval = minConnInterval;
  this->maxConnInterval = maxConnInterval;
}

void BluefruitLE_SPI_Stream::setFlushInterval(int flushInterval)
{
  // Not used
}

void BluefruitLE_SPI_Stream::begin()
{
  // Initialize the SPI interface
  ble.begin();

  // Perform a factory reset to make sure everything is in a known state
  ble.factoryReset();

  // Disable command echo from Bluefruit
  ble.echo(false);

  // Change the MODE LED to indicate BLE UART activity
  ble.println("AT+HWMODELED=BLEUART");

  // Set local name
  if (localName.length() > 0) {
    ble.print("AT+GAPDEVNAME=");
    ble.println(localName);
  }

  // Set connection interval
  if (minConnInterval > 0 && maxConnInterval > 0) {
    ble.print("AT+GAPINTERVALS=");
    ble.print(minConnInterval);
    ble.print(",");
    ble.print(maxConnInterval);
    ble.println(",,,");
  }

  // Disable real and simulated mode switch (i.e. "+++") command
  ble.println("AT+MODESWITCHEN=local,0");
  ble.enableModeSwitchCommand(false);

  // Switch to data mode
  ble.setMode(BLUEFRUIT_MODE_DATA);
}

bool BluefruitLE_SPI_Stream::poll()
{
  // If there's outgoing data in the buffer, just send it.  The firmware on
  // the nRF51822 will decide when to transmit the data in its TX FIFO.
  if (txCount) flush();

  // In order to check for a connection, we would need to switch from data to
  // command mode and back again.  However, due to the internal workings of
  // Adafruit_BluefruitLE_SPI, this can lead to unread incoming data being
  // lost.  Therefore, we always return true.
  return true;
}

void BluefruitLE_SPI_Stream::end()
{
  flush();
  ble.end();
}

size_t BluefruitLE_SPI_Stream::write(uint8_t byte)
{
  txBuffer[txCount++] = byte;
  if (txCount == sizeof(txBuffer)) flush();
  return 1;
}

int BluefruitLE_SPI_Stream::available()
{
  return ble.available();
}

int BluefruitLE_SPI_Stream::read()
{
  return ble.read();
}

int BluefruitLE_SPI_Stream::peek()
{
  return ble.peek();
}

void BluefruitLE_SPI_Stream::flush()
{
  ble.write(txBuffer, txCount);
  txCount = 0;
}


#endif // _BLUEFRUIT_LE_SPI_STREAM_H_
