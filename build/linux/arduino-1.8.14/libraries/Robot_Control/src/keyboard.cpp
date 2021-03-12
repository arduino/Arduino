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

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
int pul_min[]={0,133,319,494,732};
int pul_max[]={10,153,339,514,752};
/*int pul_min[]={0,123,295,471,714};
int pul_max[]={0,143,315,491,734};*/
/*
int pul_min[]={0,133,319,494,732};
int pul_max[]={10,153,339,514,752};
*/
void sort(int* v);

void RobotControl::keyboardCalibrate(int *vals){
	for(int i=0;i<5;i++){
		pul_min[i]=vals[i]-10;
		pul_max[i]=vals[i]+10;
	}
}
int8_t RobotControl::keyboardRead(void)
{

  int lectura_pul;
  int8_t conta_pul=0;
  static int anterior=0;

  lectura_pul = this->averageAnalogInput(KEY);

  while ((conta_pul < NUMBER_BUTTONS) && !(lectura_pul >= pul_min[conta_pul] && lectura_pul <= pul_max[conta_pul]))
    conta_pul++;

  if (conta_pul >= NUMBER_BUTTONS)
    conta_pul = -1;
  else
    delay(100);

  return conta_pul;
}

int RobotControl::averageAnalogInput(int pinNum)
{
  int vals[5];
  for(int i=0;i<5;i++){
	for(int j=i;j<5;j++){
	  vals[j]=::analogRead(pinNum);
	}
	sort(vals);
  }
  return vals[0];
}
void sort(int* v){
  int tmp;
  for(int i=0;i<4;i++)
    for(int j=i+1;j<5;j++)
      if(v[j]<v[i]){
        tmp=v[j];
        v[j]=v[i];
        v[i]=tmp;
      }
  v[0]=v[3];
}
