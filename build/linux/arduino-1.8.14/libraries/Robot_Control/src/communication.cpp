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

bool RobotControl::isActionDone(){
	if(messageIn.receiveData()){
		if(messageIn.readByte()==COMMAND_ACTION_DONE){
			return true;
		}
	}
	return false;
}

void RobotControl::pauseMode(uint8_t onOff){
	messageOut.writeByte(COMMAND_PAUSE_MODE);
	if(onOff){
		messageOut.writeByte(true);
	}else{
		messageOut.writeByte(false);
	}
	messageOut.sendData();
}

void RobotControl::lineFollowConfig(uint8_t KP, uint8_t KD, uint8_t robotSpeed, uint8_t intergrationTime){
	messageOut.writeByte(COMMAND_LINE_FOLLOW_CONFIG);
	messageOut.writeByte(KP);
	messageOut.writeByte(KD);
	messageOut.writeByte(robotSpeed);
	messageOut.writeByte(intergrationTime);
	messageOut.sendData();
}
