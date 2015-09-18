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

#include "ArduinoRobot.h"

void RobotControl::drawBase(){
	Arduino_LCD::drawCircle(64,80,50,foreGround);
	Arduino_LCD::drawLine(64,30,64,20,foreGround);
}
void RobotControl::drawDire(int16_t dire){
	static uint8_t x_old;
	static uint8_t y_old;
	static uint8_t x_t_old;
	static uint8_t y_t_old;

	uint8_t x=60*sin(dire/360.0*6.28)+64;
	uint8_t x_t=40*sin(dire/360.0*6.28)+64;
	uint8_t y=60*cos(dire/360.0*6.28)+80;
	uint8_t y_t=40*cos(dire/360.0*6.28)+80;

	Arduino_LCD::drawLine(x_t_old,y_t_old,x_old,y_old,backGround);
	Arduino_LCD::drawLine(x_t,y_t,x,y,RED);

	x_old=x;
	y_old=y;
	x_t_old=x_t;
	y_t_old=y_t;
}

void RobotControl::drawCompass(uint16_t value){
	drawBase();
	drawDire(value);
	debugPrint(value,57,76);
}

//display logos 
void RobotControl::displayLogos(){
	_drawBMP("lg0.bmp",0,0);
	delay(2000);
	_drawBMP("lg1.bmp",0,0);
	delay(2000);
	clearScreen();
}

//wait for a button to be pressed
void RobotControl::waitContinue(uint8_t key){
  while(!(Robot.keyboardRead()==key));
}
