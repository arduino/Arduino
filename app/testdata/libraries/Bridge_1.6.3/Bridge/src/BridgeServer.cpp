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

#include <BridgeServer.h>
#include <BridgeClient.h>

BridgeServer::BridgeServer(uint16_t _p, BridgeClass &_b) :
  bridge(_b), port(_p), listening(false), useLocalhost(false) {
}

void BridgeServer::begin() {
  uint8_t tmp[] = {
    'N',
    static_cast<uint8_t>(port >> 8),
    static_cast<uint8_t>(port)
  };
  uint8_t res[1];
  String address = F("127.0.0.1");
  if (!useLocalhost)
    address = F("0.0.0.0");
  bridge.transfer(tmp, 3, (const uint8_t *)address.c_str(), address.length(), res, 1);
  listening = (res[0] == 1);
}

BridgeClient BridgeServer::accept() {
  uint8_t cmd[] = {'k'};
  uint8_t res[1];
  unsigned int l = bridge.transfer(cmd, 1, res, 1);
  if (l == 0)
    return BridgeClient();
  return BridgeClient(res[0]);
}

size_t BridgeServer::write(uint8_t c) {
  uint8_t cmd[] = { 'b', c };
  bridge.transfer(cmd, 2);
  return 1;
}

