//#############################################################################
//
//! \file   f2802x_common/source/sci_io.c
//!
//! \brief  Contains the various functions related to the serial 
//!         communications interface (SCI) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//  (C) Copyright 2012, Texas Instruments, Inc.
//#############################################################################
// $TI Release: f2802x Support Library v210 $
// $Release Date: Mon Sep 17 09:13:31 CDT 2012 $
//#############################################################################

// **************************************************************************
// the includes
#include <stdio.h>
#include <file.h>

#include "DSP28x_Project.h"
#include "f2802x_common/include/sci.h"
#include "f2802x_common/include/sci_io.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals

uint16_t deviceOpen = 0;
SCI_Handle ioSci;


// **************************************************************************
// the functions

int SCI_open(const char * path, unsigned flags, int llv_fd)
{
    if(deviceOpen){
        return (-1);
    }else{
        ioSci = SCI_init((void *)SCIA_BASE_ADDR, sizeof(SCI_Obj));
        deviceOpen = 1;
        return (1);    
    }    
    
}

int SCI_close(int dev_fd)
{
    if((dev_fd != 1) || (!deviceOpen)){
        return (-1);
    }else{
        deviceOpen = 0;
        return (0);
    }    
    
}

int SCI_read(int dev_fd, char * buf, unsigned count)
{
    uint16_t readCount = 0;
    uint16_t * bufPtr = (uint16_t *) buf;
    
    if(count == 0) {
        return (0);
    }
    
    while((readCount < count) && SCI_isRxDataReady(ioSci)){
        *bufPtr = SCI_getData(ioSci);
        readCount++;
        bufPtr++;
    }
    
    return (readCount);
    
}

int SCI_write(int dev_fd, char * buf, unsigned count)
{
    uint16_t writeCount = 0;
    uint16_t * bufPtr = (uint16_t *) buf;
    
    if(count == 0) {
        return (0);
    }
    
    while(writeCount < count){
        SCI_putDataBlocking(ioSci, *bufPtr);
        writeCount++;
        bufPtr++;
    }
    
    return (writeCount);
    
}

off_t SCI_lseek(int dev_fd, off_t offset, int origin)
{
    return (0);   
}

int SCI_unlink(const char * path)
{
    return (0);
}

int SCI_rename(const char * old_name, const char * new_name)
{
    return (0);    
}



// end of file
