/*
 * This file is part of xmlibraries.
 * xmlibraries is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * xmlibraries is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2010 Eberhard Fahle <e.fahle@wayoda.org>
 */
#include "xmDAC.h"

#include "Arduino.h"
#include <avr/io.h>

const uint8_t xmDAC::VREF_BANDGAP=0x00; 
const uint8_t xmDAC::VREF_VCC=0x01; 
const uint8_t xmDAC::VREF_AREF_PORT_A=0x02; 
const uint8_t xmDAC::VREF_AREF_PORT_B=0x03; 
const uint8_t xmDAC::DAC_PORT_A=0x01;
const uint8_t xmDAC::DAC_PORT_B=0x02;
const uint8_t xmDAC::SINGLE_CHANNEL_MODE=0x01;
const uint8_t xmDAC::DUAL_CHANNEL_MODE=0x02;

xmDAC::xmDAC(uint8_t port) {
    if(port==DAC_PORT_B) {
	this->port=port;
	dac=&DACB;
    }
#ifdef DACA
    else if(port==DAC_PORT_A) {
	this->port=port;
	dac=&DACA;
    } 
#endif
    else {
	this->port=-1;
	dac=NULL;
    }
    enabled=false;
}
 
int xmDAC::begin(uint8_t mode, uint8_t vref) {
    enabled=false;
    if(port==-1 || dac==NULL) {
	//user selected illegal port
	return -1;
    }
    if(mode==SINGLE_CHANNEL_MODE 
       || mode==DUAL_CHANNEL_MODE) {
	this->mode=mode;
    }
    else {
	//user used illegal mode value
	return -2;
    }
    if(vref==VREF_BANDGAP
       || vref==VREF_VCC
       || vref==VREF_AREF_PORT_A
       || vref==VREF_AREF_PORT_B) {
	this->vref=vref;
    }
    else {
	//user used illegal vref value
	return -3;
    }
    if(this->mode==SINGLE_CHANNEL_MODE) {
	/* 
	  set single channel operation 
	  conversion is triggered by a write to the data register
	*/
	dac->CTRLB=(dac->CTRLB&~DAC_CHSEL_gm)|DAC_CHSEL_SINGLE_gc;
	/*
	  select the ref-voltage  
	  data is right adjusted in the registers 
	*/
	dac->CTRLC=(dac->CTRLC & ~( DAC_REFSEL_gm | DAC_LEFTADJ_bm )) 
	    | (this->vref<<3);
	/*
	  enable channel 0 on this port
	  enable the DAC module
	*/
	dac->CTRLA=(dac->CTRLA & ~DAC_CH1EN_bm)|DAC_CH0EN_bm|DAC_ENABLE_bm;
	enabled=true;
    }
    else {
	/*
	  set dual channel operation
	  conversion is triggered by a write to the data registers
	  for the channels
	*/
	dac->CTRLB =(dac->CTRLB & ~DAC_CHSEL_gm )|DAC_CHSEL_DUAL_gc;
	/*
	  select the ref-voltage  
	  data is right adjusted in the registers 
	*/
	dac->CTRLC =(dac->CTRLC & ~( DAC_REFSEL_gm | DAC_LEFTADJ_bm )) 
	    | (this->vref<<3);
	/*
	  set conversion interval
	  set refresh timing for dual channel mode
	  FIXME:
	  What would be sensible values here?
	  For now we use a conversion interval of 
	  64CLK (2µs at 32MHz Clock),
	  and a refresh of 512CLK (16µs at 32MHz Clock)
	  This is OK for a xplain board running at 32MHz.
	*/
	dac->TIMCTRL=(uint8_t)DAC_CONINTVAL_64CLK_gc|DAC_REFRESH_512CLK_gc;
	/*
	  enable channel 0 AND channel 1  on this port and the DAC
	*/
	dac->CTRLA |= DAC_CH1EN_bm | DAC_CH0EN_bm | DAC_ENABLE_bm;
	enabled=true;
    }
    return 0;
}

void xmDAC::end() {
    if(dac!=NULL) {
	//disable the DAC
	dac->CTRLA&=0xFE;
    }
    enabled=false;
}

int xmDAC::write(int ch0, int ch1) {
    if(!enabled) {
	//DAC is not enabled
	return -1;
    }
    if(mode==SINGLE_CHANNEL_MODE) {
	if(ch0<0 || ch0>0xFFF)  {
	    //EINVAL on single channel
	    return -2;
	}
 	dac->CH0DATA=ch0;
	//now wait for conversion to finish
	while(!dac->STATUS & DAC_CH0DRE_bm)
	    ;
    }
    else {
	//we are in dual channel mode
	if(ch0>0xFFF || ch1>0xFFF) {
	    //EINVAL on one of the channels
	    return -3;
	}
	if(ch0>=0) {
	    dac->CH0DATA=ch0;
	    while(!dac->STATUS & DAC_CH0DRE_bm)
		;
	}
	if(ch1>=0) {
	    dac->CH1DATA=ch1;
	    //now wait for conversion to finish
	    while(!dac->STATUS & DAC_CH1DRE_bm)
 		;
	}
    }
    //ok the values where sucessfully written
    return 0;
}

bool xmDAC::isEnabled() {
    return enabled;
}

