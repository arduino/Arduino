/*
  ************************************************************************
  *	wiring_analog.c
  *
  *	Arduino core files for C2000
  *		Copyright (c) 2012 Trey German. All right reserved.
  *
  *
  ***********************************************************************
  Derived from:
  wiring_analog.c - analog input and output
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#include "wiring_private.h"
#include "pins_energia.h"

#ifdef TMS320F28027
#include "F2802x_common/include/F2802x_EPwm_defines.h"
#elif defined(TMS320F28069)
#include "F2806x_common/include/F2806x_EPwm_defines.h"
#endif



//(60Mhz / 2)/ 490Hz = 61224 = TBPRD
#define EPWM1_TIMER_TBPRD  61224  // Period register
#define EPWM2_TIMER_TBPRD  61224  // Period register
#define EPWM3_TIMER_TBPRD  61224  // Period register

uint16_t analog_reference = 0;


void analogReference(uint16_t mode)
{
	// can't actually set the register here because the default setting
	// will connect AVCC and the AREF pin, which would cause a short if
	// there's something connected to AREF.
	analog_reference = mode;
}


uint32_t analog_period = F_CPU/490;
uint16_t analog_div = 0, analog_res=255; // devide clock with 0, 2, 4, 8

//TODO: Can be a lot more efficiant.
//      - lower clock rated / input devider to conserve Energia.
//      - pin configuration logic.

// Note set frequency before sending analog value
// Lowest fequency is defined by clock frequency F_CPU, and max counter value 2^16-1
// fmin = F_CPU / 2^16
void analogFrequency(uint32_t freq)
{
//  if ( freq <= F_CPU/(4*65334L) ) { analog_div = ID_3; freq *=8; }
//  else if ( freq <= F_CPU/(2*65334L) ) { analog_div = ID_2; freq *=4; }
//  else if ( freq <= F_CPU/(4*65334L) ) { analog_div = ID_1; freq *=2; }
//  analog_period = F_CPU/freq;
}

// Set the resulution (nr of counts for 100%), default = 255, large values may not work at all frequencies
void analogResolution(uint16_t res)
{
  analog_res = res;
}

void InitEPwm()
{
   EALLOW;
   SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK =1;
   SysCtrlRegs.PCLKCR1.bit.EPWM2ENCLK =1;
   SysCtrlRegs.PCLKCR1.bit.EPWM3ENCLK =1;
   SysCtrlRegs.PCLKCR1.bit.EPWM4ENCLK =1;
   #ifdef TMS320F28069
   SysCtrlRegs.PCLKCR1.bit.EPWM5ENCLK =1;
   SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK =1;
   SysCtrlRegs.PCLKCR1.bit.EPWM7ENCLK =1;
   SysCtrlRegs.PCLKCR1.bit.EPWM8ENCLK =1;
   #endif
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;
   
   
   // Setup TBCLK
   EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm1Regs.TBPRD = EPWM1_TIMER_TBPRD;       // Set timer period
   EPwm1Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm1Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm1Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm1Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm1Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm1Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm1Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

   // Set Compare values
   EPwm1Regs.CMPA.all = 0;    // Set compare A value
   EPwm1Regs.CMPB = 0;              // Set Compare B value

   // Set actions
   EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
   EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;          // Clear PWM1A on event A, up count

   EPwm1Regs.AQCTLB.bit.ZRO = AQ_SET;            // Set PWM1B on Zero
   EPwm1Regs.AQCTLB.bit.CBU = AQ_CLEAR;          // Clear PWM1B on event B, up count

   // Setup TBCLK
   EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm2Regs.TBPRD = EPWM2_TIMER_TBPRD;       // Set timer period
   EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm2Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm2Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm2Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm2Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm2Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm2Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

   // Set Compare values
   EPwm2Regs.CMPA.all = 0;       // Set compare A value
   EPwm2Regs.CMPB = 0;                 // Set Compare B value

   // Set actions
   EPwm2Regs.AQCTLA.bit.ZRO = AQ_SET;             // Clear PWM2A on Period
   EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;               // Set PWM2A on event A, up count

   EPwm2Regs.AQCTLB.bit.ZRO = AQ_SET;             // Clear PWM2B on Period
   EPwm2Regs.AQCTLB.bit.CBU = AQ_CLEAR;               // Set PWM2B on event B, up count

   // Setup TBCLK
   EPwm3Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm3Regs.TBPRD = EPWM3_TIMER_TBPRD;       // Set timer period
   EPwm3Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm3Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm3Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm3Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm3Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm3Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm3Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm3Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

  // Set Compare values
   EPwm3Regs.CMPA.all = 0; // Set compare A value
   EPwm3Regs.CMPB = 0;           // Set Compare B value

   // Set Actions
   EPwm3Regs.AQCTLA.bit.ZRO = AQ_SET;         // Set PWM3A on event B, up count
   EPwm3Regs.AQCTLA.bit.CAU = AQ_CLEAR;       // Clear PWM3A on event B, up count

   EPwm3Regs.AQCTLB.bit.ZRO = AQ_TOGGLE;      // Toggle EPWM3B on Zero
   EPwm3Regs.AQCTLB.bit.CBU = AQ_CLEAR;      // Toggle EPWM3B on Zero

   // Setup TBCLK
   EPwm4Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm4Regs.TBPRD = EPWM3_TIMER_TBPRD;       // Set timer period
   EPwm4Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm4Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm4Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm4Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm4Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm4Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm4Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm4Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm4Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

  // Set Compare values
   EPwm4Regs.CMPA.all = 0; // Set compare A value
   EPwm4Regs.CMPB = 0;           // Set Compare B value

   // Set Actions
   EPwm4Regs.AQCTLA.bit.ZRO = AQ_SET;         // Set PWM4A on event B, up count
   EPwm4Regs.AQCTLA.bit.CAU = AQ_CLEAR;       // Clear PWM4A on event B, up count

   EPwm4Regs.AQCTLB.bit.ZRO = AQ_TOGGLE;      // Toggle EPWM4B on Zero
   EPwm4Regs.AQCTLB.bit.CBU = AQ_CLEAR;      // Toggle EPWM4B on Zero

   #ifdef TMS320F28069
   // Setup TBCLK
   EPwm5Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm5Regs.TBPRD = EPWM3_TIMER_TBPRD;       // Set timer period
   EPwm5Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm5Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm5Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm5Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm5Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm5Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm5Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm5Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm5Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

  // Set Compare values
   EPwm5Regs.CMPA.all = 0; // Set compare A value
   EPwm5Regs.CMPB = 0;           // Set Compare B value

   // Set Actions
   EPwm5Regs.AQCTLA.bit.ZRO = AQ_SET;         // Set PWM5A on event B, up count
   EPwm5Regs.AQCTLA.bit.CAU = AQ_CLEAR;       // Clear PWM5A on event B, up count

   EPwm5Regs.AQCTLB.bit.ZRO = AQ_TOGGLE;      // Toggle EPWM5B on Zero
   EPwm5Regs.AQCTLB.bit.CBU = AQ_CLEAR;      // Toggle EPWM5B on Zero


   // Setup TBCLK
   EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm6Regs.TBPRD = EPWM3_TIMER_TBPRD;       // Set timer period
   EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm6Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm6Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm6Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm6Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

  // Set Compare values
   EPwm6Regs.CMPA.all = 0; // Set compare A value
   EPwm6Regs.CMPB = 0;           // Set Compare B value

   // Set Actions
   EPwm6Regs.AQCTLA.bit.ZRO = AQ_SET;         // Set PWM6A on event B, up count
   EPwm6Regs.AQCTLA.bit.CAU = AQ_CLEAR;       // Clear PWM6A on event B, up count

   EPwm6Regs.AQCTLB.bit.ZRO = AQ_TOGGLE;      // Toggle EPWM6B on Zero
   EPwm6Regs.AQCTLB.bit.CBU = AQ_CLEAR;      // Toggle EPWM6B on Zero

   // Setup TBCLK
   EPwm7Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm7Regs.TBPRD = EPWM3_TIMER_TBPRD;       // Set timer period
   EPwm7Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm7Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm7Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm7Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm7Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm7Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm7Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm7Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm7Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

  // Set Compare values
   EPwm7Regs.CMPA.all = 0; // Set compare A value
   EPwm7Regs.CMPB = 0;           // Set Compare B value

   // Set Actions
   EPwm7Regs.AQCTLA.bit.ZRO = AQ_SET;         // Set PWM7A on event B, up count
   EPwm7Regs.AQCTLA.bit.CAU = AQ_CLEAR;       // Clear PWM7A on event B, up count

   EPwm7Regs.AQCTLB.bit.ZRO = AQ_TOGGLE;      // Toggle EPWM7B on Zero
   EPwm7Regs.AQCTLB.bit.CBU = AQ_CLEAR;      // Toggle EPWM7B on Zero

   // Setup TBCLK
   EPwm8Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP; // Count up
   EPwm8Regs.TBPRD = EPWM3_TIMER_TBPRD;       // Set timer period
   EPwm8Regs.TBCTL.bit.PHSEN = TB_DISABLE;    // Disable phase loading
   EPwm8Regs.TBPHS.half.TBPHS = 0x0000;       // Phase is 0
   EPwm8Regs.TBCTR = 0x0000;                  // Clear counter
   EPwm8Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;   // Clock ratio to SYSCLKOUT
   EPwm8Regs.TBCTL.bit.CLKDIV = TB_DIV2;

   // Setup shadow register load on ZERO
   EPwm8Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
   EPwm8Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
   EPwm8Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
   EPwm8Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

  // Set Compare values
   EPwm8Regs.CMPA.all = 0; // Set compare A value
   EPwm8Regs.CMPB = 0;           // Set Compare B value

   // Set Actions
   EPwm8Regs.AQCTLA.bit.ZRO = AQ_SET;         // Set PWM8A on event B, up count
   EPwm8Regs.AQCTLA.bit.CAU = AQ_CLEAR;       // Clear PWM8A on event B, up count

   EPwm8Regs.AQCTLB.bit.ZRO = AQ_TOGGLE;      // Toggle EPWM8B on Zero
   EPwm8Regs.AQCTLB.bit.CBU = AQ_CLEAR;      // Toggle EPWM8B on Zero

   #endif



   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;
   EDIS;
}

void analogInit(void)
{
	analogResolution(255);

	//ADC Setup
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
    (*Device_cal)();
//    EDIS;

//    EALLOW;
    AdcRegs.ADCCTL1.bit.ADCBGPWD  = 1;      // Power ADC BG
    AdcRegs.ADCCTL1.bit.ADCREFPWD = 1;      // Power reference
    AdcRegs.ADCCTL1.bit.ADCPWDN   = 1;      // Power ADC
    AdcRegs.ADCCTL1.bit.ADCENABLE = 1;      // Enable ADC
    AdcRegs.ADCCTL1.bit.ADCREFSEL = 0;      // Select interal BG
//    EDIS;

    delay(1);

    AdcRegs.ADCSOC0CTL.bit.CHSEL= 0;	//A0
//    AdcRegs.ADCSOC1CTL.bit.CHSEL= 1;	//A1
//    AdcRegs.ADCSOC2CTL.bit.CHSEL= 2;	//A2
//    AdcRegs.ADCSOC3CTL.bit.CHSEL= 3;	//A3
//    AdcRegs.ADCSOC4CTL.bit.CHSEL= 4;	//A4
//    AdcRegs.ADCSOC5CTL.bit.CHSEL= 6;	//A6
//    AdcRegs.ADCSOC6CTL.bit.CHSEL= 7;	//A7
//    AdcRegs.ADCSOC7CTL.bit.CHSEL= 9;	//B1
//    AdcRegs.ADCSOC8CTL.bit.CHSEL= 10;	//B2
//    AdcRegs.ADCSOC9CTL.bit.CHSEL= 11;	//B3
//    AdcRegs.ADCSOC10CTL.bit.CHSEL= 12;	//B4
//    AdcRegs.ADCSOC11CTL.bit.CHSEL= 14;	//B6
//    AdcRegs.ADCSOC12CTL.bit.CHSEL= 15;	//B7
    AdcRegs.ADCSOC1CTL.bit.CHSEL= 0;	//A1
    AdcRegs.ADCSOC2CTL.bit.CHSEL= 0;	//A2
    AdcRegs.ADCSOC3CTL.bit.CHSEL= 0;	//A3
    AdcRegs.ADCSOC4CTL.bit.CHSEL= 0;	//A4
    AdcRegs.ADCSOC5CTL.bit.CHSEL= 0;	//A6
    AdcRegs.ADCSOC6CTL.bit.CHSEL= 0;	//A7
    AdcRegs.ADCSOC7CTL.bit.CHSEL= 0;	//B1
    AdcRegs.ADCSOC8CTL.bit.CHSEL= 0;	//B2
    AdcRegs.ADCSOC9CTL.bit.CHSEL= 0;	//B3
    AdcRegs.ADCSOC10CTL.bit.CHSEL= 0;	//B4
    AdcRegs.ADCSOC11CTL.bit.CHSEL= 0;	//B6
    AdcRegs.ADCSOC12CTL.bit.CHSEL= 0;	//B7
    AdcRegs.ADCSOC13CTL.bit.CHSEL= 0;
    AdcRegs.ADCSOC14CTL.bit.CHSEL= 0;
    AdcRegs.ADCSOC15CTL.bit.CHSEL= 0;

    AdcRegs.ADCSOC0CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC1CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC2CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC3CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC4CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC5CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC6CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC7CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC8CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC9CTL.bit.ACQPS  = 6;
    AdcRegs.ADCSOC10CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC11CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC12CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC13CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC14CTL.bit.ACQPS = 6;
    AdcRegs.ADCSOC15CTL.bit.ACQPS = 6;

    AdcRegs.ADCSOC0CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC1CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC2CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC3CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC4CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC5CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC6CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC7CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC8CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC9CTL.bit.TRIGSEL  = 0;
    AdcRegs.ADCSOC10CTL.bit.TRIGSEL = 0;
    AdcRegs.ADCSOC11CTL.bit.TRIGSEL = 0;
    AdcRegs.ADCSOC12CTL.bit.TRIGSEL = 0;
    AdcRegs.ADCSOC13CTL.bit.TRIGSEL = 0;
    AdcRegs.ADCSOC14CTL.bit.TRIGSEL = 0;
    AdcRegs.ADCSOC15CTL.bit.TRIGSEL = 0;

    //Assert interrupt for EOC1 and enable interrupt
    AdcRegs.INTSEL1N2.bit.INT1SEL = 1;
    AdcRegs.INTSEL1N2.bit.INT1E = 1;

    //ePWM Setup
    InitEPwm();


    EDIS;
}


//Arduino specifies ~490 Hz for analog out PWM so we follow suit.
#define PWM_PERIOD analog_period // F_CPU/490
#define PWM_DUTY(x) ( (unsigned long)x*PWM_PERIOD / (unsigned long)analog_res )
void analogWrite(uint8_t pin, int val)
{
    pinMode(pin, OUTPUT); // pin as output

    if (val == 0)
    {
        digitalWrite(pin, LOW); // set pin to LOW when duty cycle is 0
                        // digitalWrite will take care of invalid pins
    }
    else if (val == analog_res)
    {
        digitalWrite(pin, HIGH); // set pin HIGH when duty cycle is 255
                                         // digitalWrite will take care of invalid pins
    }
    else
    {

        uint8_t port = digitalPinToPort(pin);   // get pin port
                
        if (port == NOT_A_PORT) 
            return; // pin on timer?

		EALLOW;
        switch(digitalPinToTimer(pin)) {                // which pwm?

			case PWM1A:                              // EPwm1A
                            GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1;  //Enable PWM output on this pin
                            EPwm1Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

			case PWM1B:                              // EPwm1B
            				GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 1;  //Enable PWM output on this pin
            				EPwm1Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
            				break;

			case PWM2A:                              // EPwm2A
                            GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 1;  //Enable PWM output on this pin
                            EPwm2Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

 			case PWM2B:                              // EPwm2B
                			GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 1;  //Enable PWM output on this pin
                			EPwm2Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
                			break;

			case PWM3A:                              // EPwm3A
                            GpioCtrlRegs.GPAMUX1.bit.GPIO4 = 1;  //Enable PWM output on this pin
                            EPwm3Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

 			case PWM3B:                              // EPwm3B
                			GpioCtrlRegs.GPAMUX1.bit.GPIO5 = 1;  //Enable PWM output on this pin
                			EPwm3Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
                			break;

			case PWM4A:                              // EPwm4A
                            GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 1;  //Enable PWM output on this pin
                            EPwm4Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

 			case PWM4B:                              // EPwm4B
                			GpioCtrlRegs.GPAMUX1.bit.GPIO7 = 1;  //Enable PWM output on this pin
                			EPwm4Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
                			break;

      #ifdef TMS320F28069               

      case PWM5A:                              // EPwm5A
                            GpioCtrlRegs.GPAMUX1.bit.GPIO8 = 1;  //Enable PWM output on this pin
                            EPwm5Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

      case PWM5B:                              // EPwm5B
                      GpioCtrlRegs.GPAMUX1.bit.GPIO9 = 1;  //Enable PWM output on this pin
                      EPwm5Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
                      break;

      case PWM6A:                              // EPwm6A
                            GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 1;  //Enable PWM output on this pin
                            EPwm6Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

      case PWM6B:                              // EPwm6B
                      GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 1;  //Enable PWM output on this pin
                      EPwm6Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
                      break;

      case PWM7A:                              // EPwm7A
                            GpioCtrlRegs.GPBMUX1.bit.GPIO40 = 1;  //Enable PWM output on this pin
                            EPwm7Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

      case PWM7B:                              // EPwm7B
                      GpioCtrlRegs.GPBMUX1.bit.GPIO41 = 1;  //Enable PWM output on this pin
                      EPwm7Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
                      break;

      case PWM8A:                              // EPwm8A
                            GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 1;  //Enable PWM output on this pin
                            EPwm8Regs.CMPA.half.CMPA = PWM_DUTY(val);  // PWM duty cycle
                            break;

      case PWM8B:                              // EPwm8B
                      GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 1;  //Enable PWM output on this pin
                      EPwm8Regs.CMPB = PWM_DUTY(val);  // PWM duty cycle
                      break;
      #endif 


 
            case NOT_ON_TIMER:                      // not on a timer output pin
			default:                                // or TxA0 pin
				if (val <= (analog_res >> 1)) {
					digitalWrite(pin, LOW); // 
				} else {
					digitalWrite(pin, HIGH);
				}
                }
        }
 	EDIS;
}

uint16_t analogRead(uint8_t pin)
{
// make sure we have an ADC
	if(SysCtrlRegs.PCLKCR0.bit.ADCENCLK == 0){
		analogInit();
	}

    if(pin & 0x8000)
    {
        pin &= 0x7FFF;
	
    	EALLOW;
    	//Setup SOC1 to sample selected pin
    	AdcRegs.ADCSOC1CTL.bit.CHSEL = pin;
    	//Force SOC 0 and 1
    	AdcRegs.ADCSOCFRC1.all = 3;
    	EDIS;

	    while(AdcRegs.ADCINTFLG.bit.ADCINT1 != 1){
	    	//wait until conversion is done
    	}
    	AdcRegs.ADCINTFLGCLR.bit.ADCINT1 = 1;

	    return (AdcResult.ADCRESULT1);
    }else{
        return 0;
    }


}


