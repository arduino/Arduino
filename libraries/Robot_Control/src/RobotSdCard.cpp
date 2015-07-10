/*
  Copyright (c) 2012 Arduino LLC. All right reserved.

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

#include <ArduinoRobot.h>

void RobotControl::beginSD(){
  card.init();
  file.init(&card);
  melody.init(&card);
}

void RobotControl::_enableSD(){
  DDRB = DDRB & 0xDF; //pinMode(CS_LCD,INPUT);
  DDRB = DDRB | 0x10; //pinMode(CS_SD,OUTPUT);
}

/*
void RobotControl::sdTest(){
  file.open("Infor.txt",O_READ);
  uint8_t buf[7];
  char n;
  while ((n = file.read(buf, sizeof(buf))) > 0) {
    for (uint8_t i = 0; i < n; i++) Serial.write(buf[i]);
  }
}*/
