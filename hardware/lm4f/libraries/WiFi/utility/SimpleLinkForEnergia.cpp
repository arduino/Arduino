/*
 * SimpleLinkForEnergia.cpp - Energia Abstraction layer for SimpleLink functions
 *
 * Copyright (C) 2014 Noah Luskey | LuskeyNoah@gmail.com
 *
 */

#include "SimpleLinkForEnergia.h"
#include <Energia.h>
#include "user.h"
#include <SPI.h>
#include "WiFi.h"

#ifdef __cplusplus
extern "C" {
#endif

//#define _VERBOSE_DEBUG_

#ifdef _VERBOSE_DEBUG_
#define DEBUG_TRACE(info) Serial.print(info)
#else
#define DEBUG_TRACE(info)
#endif


void CC3100_enable()
{
    DEBUG_TRACE("3100 ENABLE");
    //
    //enable the cc3100 device by setting nHIB line
    //
    digitalWrite(WiFiClass::pin_nhib, HIGH);
}


void CC3100_disable()
{
    DEBUG_TRACE("3100 DISABLE");
    //
    //disable the cc3100 device by clearing nHIB line
    //
    digitalWrite(WiFiClass::pin_nhib, LOW);
}
    
//
//open the SPI interface (none of the inputs actually matter)
//
int spi_Open(char* pIfName , unsigned long flags)
{
    DEBUG_TRACE("SPI_OPEN");
    //
    //set the direction of the pins for the SPI support
    //
    pinMode(WiFiClass::pin_cs, OUTPUT);
    digitalWrite(WiFiClass::pin_cs, HIGH);
    pinMode(WiFiClass::pin_irq, INPUT);
    pinMode(WiFiClass::pin_nhib, OUTPUT);
    digitalWrite(WiFiClass::pin_nhib, LOW);
    
    //
    //set the spi port up using Energia functions
    //
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    
    //
    //return a success
    //
	return 0;
}


//
//closes the SPI interface
//
int spi_Close(int Fd)
{
    DEBUG_TRACE("SPI_CLOSE");

    //
    //close the SPI library
    //
    SPI.end();
}

//
//read from the SPI interface (Fd doesn't actually matter)
//
int spi_Read(int Fd , char* pBuff , int Len)\
{
    digitalWrite(WiFiClass::pin_cs, LOW);
    
    DEBUG_TRACE("SPI_READ");
    //
    //read bytes into the buffer by transmitting NULL over and over
    //
    for (int i = 0; i < Len; i++) {
        pBuff[i] = SPI.transfer(NULL);
        DEBUG_TRACE(pBuff[i]);
    }
    
    digitalWrite(WiFiClass::pin_cs, HIGH);
    return Len;
}

//
//Write to the SPI interface (Fd doesn't actually matter)
//
int spi_Write(int Fd , char* pBuff , int Len)
{
    digitalWrite(WiFiClass::pin_cs, LOW);
    
    DEBUG_TRACE("SPI_WRITE");
    //
    //transfer all the bytes from the buffer
    //
    for (int i = 0; i < Len; i++) {
        SPI.transfer(pBuff[i]);
        DEBUG_TRACE(pBuff[i]);
    }
    
    digitalWrite(WiFiClass::pin_cs, HIGH);
    return Len;
}


int registerInterruptHandler(void* InterruptHdl , void* pValue)
{
    delay(100);
    DEBUG_TRACE("INTERRUPT REGISTER");
    
    //
    //the IRQ line may already be high
    //in this case, manually call the interrupt first
    //
    if (digitalRead(WiFiClass::pin_irq) && InterruptHdl != NULL) {
        void (*interruptFunction)(void) = (void (*)())InterruptHdl;
        interruptFunction();
    }
    
    if (InterruptHdl == NULL) {
        //
        //according to documentation, a NULL pointer means remove the interrupt
        //
        detachInterrupt(WiFiClass::pin_irq);
    } else {
        //
        //Register the IRQ interrupt handler
        //
        attachInterrupt(WiFiClass::pin_irq, (void (*)())InterruptHdl, RISING);
    }
    
    delay(100);
    return 0;
}

#ifdef __cplusplus
}
#endif /* extern "C" */

