//#############################################################################
//
// File:   F2837xS_sci_io.c
//
// Description:  Contains the various functions related to the serial 
//               communications interface (SCI) object
//
//#############################################################################
// $TI Release: F2837xS Support Library v170 $
// $Release Date: Mon Sep 21 16:56:07 CDT 2015 $
// $Copyright: Copyright (C) 2014-2015 Texas Instruments Incorporated -
//             http://www.ti.com/ ALL RIGHTS RESERVED $
//#############################################################################

// **************************************************************************
// the includes
#include <stdio.h>
#include <file.h>

#include "F28x_Project.h"
#include "F2837xS_sci_io.h"


// **************************************************************************
// the defines


// **************************************************************************
// the globals

uint16_t deviceOpen = 0;


// **************************************************************************
// the functions

int SCI_open(const char * path, unsigned flags, int llv_fd)
{
    if(deviceOpen){
        return (-1);
    }else{
//        ioSci = SCI_init((void *)SCIA_BASE_ADDR, sizeof(SCI_Obj));
    	EALLOW;
    	CpuSysRegs.PCLKCR7.bit.SCI_A = 1;
    	SciaRegs.SCIFFTX.all=0xE040;
		SciaRegs.SCIFFRX.all=0x2044;
		SciaRegs.SCIFFCT.all=0x0;
	    SciaRegs.SCICCR.all =0x0007;   // 1 stop bit,  No loopback
	                                   // No parity,8 char bits,
	                                   // async mode, idle-line protocol
	    SciaRegs.SCICTL1.all =0x0003;  // enable TX, RX, internal SCICLK,
	                                   // Disable RX ERR, SLEEP, TXWAKE
	    SciaRegs.SCICTL2.all =0x0003;
	    SciaRegs.SCICTL2.bit.TXINTENA =1;
	    SciaRegs.SCICTL2.bit.RXBKINTENA =1;

		SciaRegs.SCIHBAUD.bit.BAUD =0x0000;  // 9600 baud @LSPCLK = 10MHz (40 MHz SYSCLK).
		SciaRegs.SCILBAUD.bit.BAUD =0x0081;

	    SciaRegs.SCICTL1.all =0x0023;  // Relinquish SCI from Reset
	    EDIS;

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
    
    while((readCount < count) && SciaRegs.SCIRXST.bit.RXRDY){
        *bufPtr = SciaRegs.SCIRXBUF.bit.SAR;//SCI_getData(ioSci);
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
//        SCI_putDataBlocking(ioSci, *bufPtr);
        while(SciaRegs.SCICTL2.bit.TXRDY != 1){
        }
        SciaRegs.SCITXBUF.bit.TXDT = *bufPtr;
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
