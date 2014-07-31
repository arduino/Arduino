/*
 * SimpleLinkForEnergia.h - Energia Abstraction layer for SimpleLink functions
 *
 * Copyright (C) 2014 Noah Luskey | LuskeyNoah@gmail.com
 *
 */


#ifndef _SIMPLELINK_FOR_ENERGIA_H_
#define _SIMPLELINK_FOR_ENERGIA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "user.h"

//
//these two function control the nHIB line on the launchpad
//
void CC3100_enable(void);
void CC3100_disable(void);
    
//
//dealing with spi interface stuff (open, close, write, etc.)
//
int spi_Open(char* pIfName , unsigned long flags);
int spi_Close(int Fd);
int spi_Read(int Fd , char* pBuff , int Len);
int spi_Write(int Fd , char* pBuff , int Len);

//
//register the interrupt handler
//because the interface is SPI, masking methods aren't necessary
//
int registerInterruptHandler(void* InterruptHdl , void* pValue);

//
//helper functions for spi and other pin stuff
//
void initPins(void);
void initSPI(void);
    


#ifdef __cplusplus
}
#endif

#endif /*_SIMPLELINK_FOR_ENERGIA_H_*/