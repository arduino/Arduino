#include "xmWire.h"

#include <avr/io.h>

const int xmWire::DEFAULT_BUFFER_SIZE=32;
const uint8_t xmWire::TWI_PORT_NA=0x00;
const uint8_t xmWire::TWI_PORT_C=0x03;
const uint8_t xmWire::TWI_PORT_D=0x04;
const uint8_t xmWire::TWI_PORT_E=0x05;
const uint8_t xmWire::TWI_PORT_F=0x06;
const uint8_t xmWire::TWI_SPEED_100000=1; 
const uint8_t xmWire::TWI_SPEED_400000=2; 

xmWire::xmWire(uint8_t port) {
    this->port=port;
    if(this->port==TWI_PORT_C) 
	twi=&TWIC;
    else if(this->port==TWI_PORT_D) 
	twi=&TWID; 
    else if(this->port==TWI_PORT_E) 
	twi=&TWIE; 
    else if(this->port==TWI_PORT_F) 
	twi=&TWIF; 
    else {
	twi=NULL;
	this->port=TWI_PORT_NA;
    }
}


int xmWire::begin(uint8_t speed, int bufferSize) {
    return begin(0,speed,bufferSize);
}

int xmWire::begin(uint8_t address, uint8_t speed, int bufferSize) {
    unsigned long twiSpeed=0; 
    unsigned long twiBaudrate=0;
    if(port==TWI_PORT_NA) {
	/*
	  this should never happen because
	  the library provides pre instantiated objects
	*/
	return TWI_ERROR_PORT;
    }
    if(speed==TWI_SPEED_100000 
       || speed==TWI_SPEED_400000) {
	this->speed=speed;
    }
    else {
	return TWI_ERROR_SPEED;
    }
    if(bufferSize>0) {
	this->bufferSize=bufferSize;
    }
    else {
	return TWI_ERROR_BUFFERSIZE; 
    }
    if(address<=127) {
	this->address=address;
    }
    else if(this->address>0) {
 	//we are a slave
	return TWI_NOT_IMPLEMENTED;
    }
    else {
	return TWI_ERROR_ADDRESS;
    }
    //initialize the internal buffers
    if(sendBuffer.begin(bufferSize)
       || receiveBuffer.begin(bufferSize)) {
	return TWI_OUT_OF_MEMORY;
    }
    /*
      TODO : enable pullups on SDA/SCL pin?
    */
    PORTCFG.MPCMASK |= (1<<PIN0)|(1<<PIN1); 
    PORTD.PIN0CTRL = 0x38;    
    PORTD.PIN1CTRL = 0x38;    
    twi->MASTER.CTRLA = TWI_MASTER_INTLVL_LO_gc 
	| TWI_MASTER_RIEN_bm 
	| TWI_MASTER_WIEN_bm 
	| TWI_MASTER_ENABLE_bm;
    if(speed==TWI_SPEED_100000)
	twiSpeed=100000UL;
    else if(speed==TWI_SPEED_400000)
	twiSpeed=400000UL;
    twiBaudrate=(F_CPU/(twiSpeed<<2))-5UL;
    twi->MASTER.BAUD=(uint8_t)twiBaudrate;
    twi->MASTER.STATUS=TWI_MASTER_BUSSTATE_IDLE_gc;
    twiResult=TWI_SUCCESS;
    slaveAddress=0;
    return 0;
}

int xmWire::beginTransmission(uint8_t slaveAddress) {
    if(!ready()) 
	return TWI_BUSY;
    if(slaveAddress==0 || slaveAddress>127)
	return TWI_ERROR_ADDRESS;
    this->slaveAddress=slaveAddress;
    sendBuffer.clear();
    return TWI_SUCCESS;   
}

int xmWire::send(uint8_t value) {
    if(slaveAddress==0) {
	//no transdmission was started
	return TWI_NOT_TRANSMITTING;
    }
    if(sendBuffer.put(value)) {
	return TWI_OUT_OF_MEMORY;
    }
    return TWI_SUCCESS;
}
    
int xmWire::send(uint8_t *data, uint8_t quantity) {
    if(slaveAddress==0) {
	//no transdmission was started
	return TWI_NOT_TRANSMITTING;
    }
    if(sendBuffer.put(data,quantity)) {
	return TWI_OUT_OF_MEMORY;
    }
    return TWI_SUCCESS;
}


int xmWire::endTransmission(int expectedByteCount) { 
    if(slaveAddress==0) {
	//no transdmission was started
	return TWI_NOT_TRANSMITTING;
    }
    if(expectedByteCount<0 
       || expectedByteCount > receiveBuffer.size()) {
	//cancel the whole transmission
	return TWI_OUT_OF_MEMORY;
    }
    sendBuffer.flip();
    receiveBuffer.clear();
    //if this is >0 we will send a repeated start condion
    slaveReadSize=expectedByteCount;
    //now start the whole thing by writing the address register
    twiResult=TWI_SUCCESS;
    this->slaveAddress=slaveAddress<<1;
    twi->MASTER.ADDR=this->slaveAddress;
    return TWI_SUCCESS;  
}

int xmWire::requestFrom(uint8_t slaveAddress, int expectedByteCount) {
    if(!ready()) 
	return TWI_BUSY;
    if(slaveAddress==0 || slaveAddress>127)
	return TWI_ERROR_ADDRESS;
    if(expectedByteCount<=0 || expectedByteCount>receiveBuffer.size()) {
	//cancel the whole transmission
	return TWI_OUT_OF_MEMORY;
    }
    this->slaveAddress=slaveAddress;
    sendBuffer.clear();
    receiveBuffer.clear();
    this->slaveReadSize=expectedByteCount;
    //now start the whole thing by writing the address register
    twiResult=TWI_SUCCESS;
    this->slaveAddress=(slaveAddress<<1)|0x01;
    twi->MASTER.ADDR=this->slaveAddress;
    return TWI_SUCCESS;
}

int xmWire::transmissionResult() {
    return twiResult;
}

boolean xmWire::ready() {
    return (twi->MASTER.STATUS & 0x01)!=0;
}

uint8_t xmWire::available(void) {
    return receiveBuffer.remaining();
}

uint8_t xmWire::receive(void) {
    return receiveBuffer.get();
}


void xmWire::onMasterInterrupt() {
    /*
      We are here because the interrupthandler called us.
      The twi->MASTER.STATUS register knows what happend
    */
    uint8_t status=twi->MASTER.STATUS;
    if (status & TWI_MASTER_ARBLOST_bm) {
	/* bus arbitration is lost */
	twi->MASTER.STATUS=status | TWI_MASTER_ARBLOST_bm;
	twiResult=TWI_BUS_ARBITRATION_LOST;
    }
    else if(status & TWI_MASTER_BUSERR_bm) {
	/* some kind of bus error */
	twi->MASTER.STATUS=status | TWI_MASTER_BUSERR_bm;
	twiResult=TWI_BUS_ERROR;
    }
    else if (status & TWI_MASTER_WIF_bm) {
	/* interrupt fired for a write-operation */ 
	if (status & TWI_MASTER_RXACK_bm) {
	    /* the flag is set so we have a NACK, cancel the transaction. */
	    twi->MASTER.CTRLC = TWI_MASTER_CMD_STOP_gc;
	    twiResult=TWI_NACK;
	}
	else if(sendBuffer.remaining()) {
	    /* there is still some data to send */
	    twi->MASTER.DATA=(uint8_t)sendBuffer.get();
	}
	else if(slaveReadSize) {
	    /* 
	       we wrote out all the data, but user also wants a 
	       repeated start condition
	    */
	    twi->MASTER.ADDR=this->slaveAddress | 0x01;
	}
	else {
	    /* 
	       we are finished writing and have no pending read 
	       send stop and thats it
	    */
	    twi->MASTER.CTRLC=TWI_MASTER_CMD_STOP_gc;
	    twiResult=TWI_SUCCESS;
	}
    }
    else if (status & TWI_MASTER_RIF_bm) {
	/* interrupt fired for a read-operation */ 
	if(slaveReadSize) {
	    /* we received one more byte which we expected */ 
	    uint8_t data=twi->MASTER.DATA;
	    receiveBuffer.put(data);
	    slaveReadSize--;
	}
	if(slaveReadSize) {
	    /* if we expect more bytes send ACK and wait for it*/
	   twi->MASTER.CTRLC=TWI_MASTER_CMD_RECVTRANS_gc;
	}
	else {
	    /* we send a NACK and stop  */
	    twi->MASTER.CTRLC = TWI_MASTER_ACKACT_bm | TWI_MASTER_CMD_STOP_gc;
	    receiveBuffer.flip();
	    twiResult=TWI_SUCCESS;
	}
    }
}


/*
  Create the TWI instances
  This does not take up too much ram, because the buffers
  are not malloced until we call begin()
*/
xmWire xmWireC(xmWire::TWI_PORT_C);
xmWire xmWireD(xmWire::TWI_PORT_D);
xmWire xmWireE(xmWire::TWI_PORT_E);
xmWire xmWireF(xmWire::TWI_PORT_F);

/** 
 * The interrupt service routine for the 
 * xmWire instance on port C
 */
ISR(TWIC_TWIM_vect) {
    xmWireC.onMasterInterrupt();
}    
    
/** 
 * The interrupt service routine for the 
 * MasterWire instance on port C
 */
ISR(TWID_TWIM_vect) {
    xmWireD.onMasterInterrupt();
}    
    
/** 
 * The interrupt service routine for the 
 * MasterWire instance on port E
 */
ISR(TWIE_TWIM_vect) {
    xmWireE.onMasterInterrupt();
}    
    
/** 
 * The interrupt service routine for the 
 * MasterWire instance on port F
 */
ISR(TWIF_TWIM_vect) {
    xmWireF.onMasterInterrupt();
}    
    
 
  

    


