/*
  Copyright (c) 2015 Arduino LLC. All right reserved.

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

#include "BridgeUdp.h"

BridgeUDP::BridgeUDP(BridgeClass &_b) :
  bridge(_b), opened(false), avail(0), buffered(0), readPos(0) {
}

/* Start BridgeUDP socket, listening at local port PORT */
uint8_t BridgeUDP::begin(uint16_t port) {
  if (opened)
    return 0;
  uint8_t cmd[] = {'e', (uint8_t)((port >> 8) & 0xFF), (uint8_t)(port & 0xFF)};
  uint8_t res[2];
  bridge.transfer(cmd, 3, res, 2);
  if (res[1] == 1) // Error...
    return 0;
  handle = res[0];
  opened = true;
  return 1;
}

/* Release any resources being used by this BridgeUDP instance */
void BridgeUDP::stop()
{
  if (!opened)
    return;
  uint8_t cmd[] = {'q', handle};
  bridge.transfer(cmd, 2);
  opened = false;
}

int BridgeUDP::beginPacket(const char *host, uint16_t port)
{
  if (!opened)
    return 0;
  uint8_t cmd[] = {'E', handle, (uint8_t)((port >> 8) & 0xFF), (uint8_t)(port & 0xFF)};
  uint8_t res[1];
  bridge.transfer(cmd, 4, (const uint8_t *)host, strlen(host), res, 1);
  return res[0]; // 1=Success, 0=Error
}

int BridgeUDP::beginBroadcastPacket(uint16_t port)
{
  if (!opened)
    return 0;
  uint8_t cmd[] = {'v', handle, (uint8_t)((port >> 8) & 0xFF), (uint8_t)(port & 0xFF)};
  uint8_t res[1];
  bridge.transfer(cmd, 4, res, 1);
  return res[0]; // 1=Success, 0=Error
}

int BridgeUDP::beginPacket(IPAddress ip, uint16_t port)
{
  if (!opened)
    return 0;
  String address;
  address.reserve(18);
  address += ip[0];
  address += '.';
  address += ip[1];
  address += '.';
  address += ip[2];
  address += '.';
  address += ip[3];
  return beginPacket(address.c_str(), port);
}

int BridgeUDP::endPacket()
{
  if (!opened)
    return 0;
  uint8_t cmd[] = {'H', handle};
  uint8_t res[1];
  bridge.transfer(cmd, 2, res, 1);
  return res[0]; // 1=Success, 0=Error
}

size_t BridgeUDP::write(const uint8_t *buffer, size_t size)
{
  if (!opened)
    return 0;
  uint8_t cmd[] = {'h', handle};
  uint8_t res[1];
  bridge.transfer(cmd, 2, buffer, size, res, 1);
  return res[0]; // 1=Success, 0=Error
}

int BridgeUDP::parsePacket()
{
  if (!opened)
    return 0;
  buffered = 0;
  readPos = 0;
  uint8_t cmd[] = {'Q', handle};
  uint8_t res[3];
  bridge.transfer(cmd, 2, res, 3);
  if (res[0] == 0) {
    // There aren't any packets available
    return 0;
  }
  avail = (res[1] << 8) + res[2];
  return 1;
}

void BridgeUDP::doBuffer() {
  // If there are already char in buffer exit
  if (buffered > 0)
    return;
  if (avail == 0)
    return;

  // Try to buffer up to 32 characters
  readPos = 0;
  uint8_t cmd[] = {'u', handle, sizeof(buffer)};
  buffered = bridge.transfer(cmd, 3, buffer, sizeof(buffer));
}

int BridgeUDP::read()
{
  if (!opened)
    return -1;
  doBuffer();
  if (buffered == 0) {
    return -1; // no chars available
  }
  buffered--;
  avail--;
  return buffer[readPos++];
}

int BridgeUDP::read(unsigned char* buff, size_t size)
{
  if (!opened)
    return -1;
  size_t readed = 0;
  do {
    if (buffered == 0) {
      doBuffer();
      if (buffered == 0)
        return readed;
    }
    buff[readed++] = buffer[readPos++];
    buffered--;
    avail--;
  } while (readed < size);
  return readed;
}

int BridgeUDP::peek()
{
  if (!opened)
    return -1;
  doBuffer();
  if (buffered == 0)
    return -1; // no chars available
  return buffer[readPos];
}

IPAddress BridgeUDP::remoteIP()
{
  if (!opened)
    return -1;
  uint8_t cmd[] = {'T', handle};
  uint8_t res[7];
  bridge.transfer(cmd, 2, res, 7);
  if (res[0] == 0)
    return IPAddress(0,0,0,0);
  return IPAddress(res[1], res[2], res[3], res[4]);
}

uint16_t BridgeUDP::remotePort()
{
  if (!opened)
    return -1;
  uint8_t cmd[] = {'T', handle};
  uint8_t res[7];
  bridge.transfer(cmd, 2, res, 7);
  if (res[0] == 0)
    return 0;
  return (res[5] << 8) + res[6];
}
