/*
  Copyright (c) 2013 Arduino LLC. All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

#include <BridgeClient.h>

BridgeClient::BridgeClient(uint8_t _h, BridgeClass &_b) :
  bridge(_b), handle(_h), opened(true), buffered(0) {
}

BridgeClient::BridgeClient(BridgeClass &_b) :
  bridge(_b), handle(0), opened(false), buffered(0) {
}

BridgeClient::~BridgeClient() {
}

BridgeClient& BridgeClient::operator=(const BridgeClient &_x) {
  opened = _x.opened;
  handle = _x.handle;
  return *this;
}

void BridgeClient::stop() {
  if (opened) {
    uint8_t cmd[] = {'j', handle};
    bridge.transfer(cmd, 2);
  }
  opened = false;
  buffered = 0;
  readPos = 0;
}

void BridgeClient::doBuffer() {
  // If there are already char in buffer exit
  if (buffered > 0)
    return;

  // Try to buffer up to 32 characters
  readPos = 0;
  uint8_t cmd[] = {'K', handle, sizeof(buffer)};
  buffered = bridge.transfer(cmd, 3, buffer, sizeof(buffer));
}

int BridgeClient::available() {
  // Look if there is new data available
  doBuffer();
  return buffered;
}

int BridgeClient::read() {
  doBuffer();
  if (buffered == 0)
    return -1; // no chars available
  else {
    buffered--;
    return buffer[readPos++];
  }
}

int BridgeClient::read(uint8_t *buff, size_t size) {
  size_t readed = 0;
  do {
    if (buffered == 0) {
      doBuffer();
      if (buffered == 0)
        return readed;
    }
    buff[readed++] = buffer[readPos++];
    buffered--;
  } while (readed < size);
  return readed;
}

int BridgeClient::peek() {
  doBuffer();
  if (buffered == 0)
    return -1; // no chars available
  else
    return buffer[readPos];
}

size_t BridgeClient::write(uint8_t c) {
  if (!opened)
    return 0;
  uint8_t cmd[] = {'l', handle, c};
  bridge.transfer(cmd, 3);
  return 1;
}

size_t BridgeClient::write(const uint8_t *buf, size_t size) {
  if (!opened)
    return 0;
  uint8_t cmd[] = {'l', handle};
  bridge.transfer(cmd, 2, buf, size, NULL, 0);
  return size;
}

void BridgeClient::flush() {
}

uint8_t BridgeClient::connected() {
  if (!opened)
    return false;
  // Client is "connected" if it has unread bytes
  if (available())
    return true;

  uint8_t cmd[] = {'L', handle};
  uint8_t res[1];
  bridge.transfer(cmd, 2, res, 1);
  return (res[0] == 1);
}

int BridgeClient::connect(IPAddress ip, uint16_t port) {
  String address;
  address.reserve(18);
  address += ip[0];
  address += '.';
  address += ip[1];
  address += '.';
  address += ip[2];
  address += '.';
  address += ip[3];
  return connect(address.c_str(), port);
}

int BridgeClient::connect(const char *host, uint16_t port) {
  uint8_t tmp[] = {
    'C',
    static_cast<uint8_t>(port >> 8),
    static_cast<uint8_t>(port)
  };
  uint8_t res[1];
  int l = bridge.transfer(tmp, 3, (const uint8_t *)host, strlen(host), res, 1);
  if (l == 0)
    return 0;
  handle = res[0];

  // wait for connection
  uint8_t tmp2[] = { 'c', handle };
  uint8_t res2[1];
  while (true) {
    bridge.transfer(tmp2, 2, res2, 1);
    if (res2[0] == 0)
      break;
    delay(1);
  }
  opened = true;

  // check for successful connection
  if (connected())
    return 1;

  stop();
  handle = 0;
  return 0;
}

int BridgeClient::connectSSL(const char *host, uint16_t port) {
  if (bridge.getBridgeVersion() < 161)
    return -1;

  uint8_t tmp[] = {
    'Z',
    static_cast<uint8_t>(port >> 8),
    static_cast<uint8_t>(port)
  };
  uint8_t res[1];
  int l = bridge.transfer(tmp, 3, (const uint8_t *)host, strlen(host), res, 1);
  if (l == 0)
    return 0;
  handle = res[0];

  // wait for connection
  uint8_t tmp2[] = { 'c', handle };
  uint8_t res2[1];
  while (true) {
    bridge.transfer(tmp2, 2, res2, 1);
    if (res2[0] == 0)
      break;
    delay(1);
  }
  opened = true;

  // check for successful connection
  if (connected())
    return 1;

  stop();
  handle = 0;
  return 0;
}