//
// LCD_utilities.cpp
// Library C++ code
// ----------------------------------
// Developed with embedXcode
// http://embedXcode.weebly.com
//
// Project LCD_screen
//
// Created by Rei VILO, Jun 01, 2013
// embedXcode.weebly.com
//
//
// Copyright © Rei VILO, 2013
// License CC = BY NC SA
//
// See LCD_utilities.h and ReadMe.txt for references
//

#include <stdio.h>

// Library header
#include "LCD_utilities.h"

char bufferIn[128];
char bufferOut[128];
char bufferFormat[32];

int32_t cos32x100(int32_t degreesX100)
{
    int32_t i = 1;
    
    if (degreesX100<0) { i = -i; degreesX100 = -degreesX100; }
    
    degreesX100 %= 36000;
    
    if (degreesX100>9000) {
        if (degreesX100<18000)      { i = -i; degreesX100 = 18000-degreesX100; }
        else if (degreesX100<27000) { i = -i; degreesX100 = degreesX100-18000; }
        else              {         degreesX100 = 36000-degreesX100; }
    }
    
    if (degreesX100< 1000)      return i * map(degreesX100,    0, 1000, 100, 98);
    else if (degreesX100< 2000) return i * map(degreesX100, 1000, 2000,  98, 93);
    else if (degreesX100< 3000) return i * map(degreesX100, 2000, 3000,  93, 86);
    else if (degreesX100< 4000) return i * map(degreesX100, 3000, 4000,  86, 76);
    else if (degreesX100< 5000) return i * map(degreesX100, 4000, 5000,  76, 64);
    else if (degreesX100< 6000) return i * map(degreesX100, 5000, 6000,  64, 50);
    else if (degreesX100< 7000) return i * map(degreesX100, 6000, 7000,  50, 34);
    else if (degreesX100< 8000) return i * map(degreesX100, 7000, 8000,  34, 17);
    else              return i * map(degreesX100, 8000, 9000,  17,  0);
}

int32_t sin32x100(int32_t degreesX100)
{
    return cos32x100(degreesX100+27000);
}

String utf2iso(String s)
{
    uint8_t c;
    
    s.toCharArray(bufferIn, s.length());
    
    memset(&bufferOut, 0x00, sizeof(bufferOut));
    
    
    for (uint8_t i=0; i<strlen(bufferIn); i++) {
        c = (uint8_t)bufferIn[i];
        
        if (c < 128) {
            bufferOut[strlen(bufferOut)] = c;
        } else if (c == 0xc3) {
            bufferOut[strlen(bufferOut)] = (bufferIn[++i] + 64);
        } else if (c == 0xc2) {
            bufferOut[strlen(bufferOut)] = bufferIn[++i];
        } else if (c == 0xe2) {
            if ((bufferIn[i+1] == 0x82) && (bufferIn[i+2] == 0xac)) {
                bufferOut[strlen(bufferOut)] = 128;
                i += 2;
            }
        }
        bufferOut[strlen(bufferOut)] = 0;
    }
    return bufferOut;
}

String i32toa(int32_t number, int32_t unit, uint8_t decimal, uint8_t size)
{
    
	memset(&bufferIn, 0x00, sizeof(bufferIn));
	memset(&bufferOut, 0x00, sizeof(bufferOut));
    
	int32_t multiplier = 1;
	for (uint8_t i=0; i<decimal; i++) multiplier *= 10;
	number = (number * multiplier *10 / unit +5) /10 ;
    
	if (decimal > 0) {
		if (size>decimal) sprintf(bufferFormat, "%%%dd.", size-decimal-1);
		else strcpy(bufferFormat, "%0d.");
		sprintf(bufferOut, bufferFormat, number/multiplier);
        
		if (number < 0) number  = -number;
		sprintf(bufferFormat, "%%0%dd", decimal);
		sprintf(bufferOut+strlen(bufferOut), bufferFormat, number%multiplier);
        
	} else {
		sprintf(bufferFormat, "%%%dd", size);
		sprintf(bufferOut, bufferFormat, number/multiplier);
	}
    
	if ((size > 0) && (strlen(bufferOut)>size)) strcpy(bufferOut, "#");
	return bufferOut;
}

String htoa(uint32_t number, uint8_t size)
{
    sprintf(bufferFormat, "%%0%dx", size);
    sprintf(bufferOut, bufferFormat, number);
    
    if ((size > 0) && (strlen(bufferOut)>size)) strcpy(bufferOut, "#");
    
    return bufferOut;
}


String ttoa(uint32_t number, uint8_t size)
{
    String s = "";
    memset(&bufferOut, 0x00, sizeof(bufferOut));
    
    if (number < (uint32_t)1000) {
        sprintf(bufferFormat, "%%%ddms", (size>2) ? size-2 : 0);
        sprintf(bufferOut, bufferFormat, number);
    } else if (number < (uint32_t)60000) {
        number /= 100;
        sprintf(bufferFormat, "%%%dd", (size>3) ? size-3 : 0);
        sprintf(bufferOut, bufferFormat, number/10);
        sprintf(bufferOut+strlen(bufferOut), ".%ds", number%10);
    } else if (number < (uint32_t)3600000) {
        number /= (uint32_t)6000;
        sprintf(bufferFormat, "%%%dd", (size>4) ? size-4 : 0);
        sprintf(bufferOut, bufferFormat, number/10);
        sprintf(bufferOut+strlen(bufferOut), ".%dmn", number%10);
    } else {
        number /= (uint32_t)360000;
        sprintf(bufferFormat, "%%%dd", (size>3) ? size-3 : 0);
        sprintf(bufferOut, bufferFormat, number/10);
        sprintf(bufferOut+strlen(bufferOut), ".%dh", number%10);
    }
    
    return bufferOut;
}


String btoa(uint16_t number, uint8_t size)
{
    if (size < 8) return "#";
    
    memset(&bufferOut, 0x00, sizeof(bufferOut));
    memset(&bufferOut, '0', size);
    uint8_t i = size;
    
    while ((number>0) && (i>0)) {
        bufferOut[--i] = '0'+(number%2);
        number >>= 1;
    }
    if (i==0) strcpy(bufferOut, "#");
    
    return bufferOut;
}

