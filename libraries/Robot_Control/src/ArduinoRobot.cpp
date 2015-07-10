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

#include "ArduinoRobot.h"
#include "Multiplexer.h"
#include "Wire.h"
#include "EasyTransfer2.h"

//RobotControl::RobotControl(){}

RobotControl::RobotControl():Arduino_LCD(LCD_CS,DC_LCD,RST_LCD){

}

void RobotControl::begin(){
	Wire.begin();
	//Compass
	//nothing here
		
	//TK sensors
	uint8_t MuxPins[]={MUXA,MUXB,MUXC,MUXD};
	Multiplexer::begin(MuxPins,MUX_IN,4);
	
	//piezo
	pinMode(BUZZ,OUTPUT);
	
	//communication
	Serial1.begin(9600);
	messageOut.begin(&Serial1);
	messageIn.begin(&Serial1);
	
	//TFT initialization
	//Arduino_LCD::initR(INITR_GREENTAB);
}

void RobotControl::setMode(uint8_t mode){
	messageOut.writeByte(COMMAND_SWITCH_MODE);
	messageOut.writeByte(mode);
	messageOut.sendData();
}


RobotControl Robot=RobotControl();
