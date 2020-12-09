/* IRLibSAMD21.h
 * Part of IRLib Library for Arduino receiving, decoding, and sending
 * infrared signals. See COPYRIGHT.txt and LICENSE.txt for more information.
 *
 * This type of content is normally stored in IRLibHardware.h but we have 
 * moved at her because the SAMD21 support is significantly different than the
 * AVR 8-bit hardware support. Separating it out into a separate file
 * will make it easier to include comments and to maintain the code.
 */

/* See IRLibSAMD21.h for details about this implementation.
 */
#if defined (__SAMD21G18A__)
#include "IRLibHardware.h"

//Save some typing
#define IR_APD g_APinDescription[IR_SEND_PWM_PIN]

void initializeSAMD21PWM(uint16_t khz) {
  // Enable the port multiplexer for the PWM channel on pin   
  PORT->Group[IR_APD.ulPort].PINCFG[IR_APD.ulPin].bit.PMUXEN = 1;
  // Connect the TCC timer to the port outputs - port pins are paired odd PMUXO and even PMUXE
  // F & E peripherals specify the timers: TCC0, TCC1 and TCC2
  PORT->Group[IR_APD.ulPort].PMUX[IR_APD.ulPin >> 1].reg |= IR_MUX_EF; 

  // Feed GCLK0 to TCC0 and TCC1
  REG_GCLK_CLKCTRL = GCLK_CLKCTRL_CLKEN |       // Enable GCLK0 to TCC0 and TCC1
                     GCLK_CLKCTRL_GEN_GCLK0 |   // Select GCLK0
                     GCLK_CLKCTRL_ID_TCC0_TCC1; // Feed GCLK0 to TCC0 and TCC1
  syncGCLK;                                     // Wait for synchronization

  // Normal (single slope) PWM operation: timers countinuously count up to PER 
  // register value and then is reset to 0
  IR_TCCx->WAVE.reg |= TCC_WAVE_WAVEGEN_NPWM;   // Setup single slope PWM on TCCx
  while (IR_TCCx->SYNCBUSY.bit.WAVE);           // Wait for synchronization

  // Each timer counts up to a maximum or TOP value set by the PER register,
  // this determines the frequency of the PWM operation.
  uint32_t cc = F_CPU/(khz*1000) - 1;
  IR_TCCx->PER.reg = cc;      // Set the frequency of the PWM on IR_TCCx
  while(IR_TCCx->SYNCBUSY.bit.PER);

  // The CCx register value corresponds to the pulsewidth in microseconds (us) 
  IR_TCCx->CC[(IR_CCn & 0x03)].reg = cc/3;      // Set the duty cycle of the PWM on TCC0 to 33%
  while(IR_TCCx->SYNCBUSY.bit.IR_CCx);
    
  // Enable IR_TCCx timer but do not turn on PWM yet. Will turn it on later.
  IR_TCCx->CTRLA.reg |= TCC_CTRLA_PRESCALER_DIV1;     // Divide GCLK0 by 1
  while (IR_TCCx->SYNCBUSY.bit.ENABLE);
  IR_TCCx->CTRLA.reg &= ~TCC_CTRLA_ENABLE;            //initially off will turn on later
  while (IR_TCCx->SYNCBUSY.bit.ENABLE);
}
/*
 * Setup the 50 microsecond timer hardware interrupt for the IRrecv class.
 */
void initializeSAMD21timerInterrupt(void) {
  GCLK->CLKCTRL.reg = (uint16_t)(GCLK_CLKCTRL_CLKEN | 
                      GCLK_CLKCTRL_GEN_GCLK0 | 
                      GCLK_CLKCTRL_ID(IR_GCM));
  syncGCLK;
  IR_TCx->COUNT16.CTRLA.reg &= ~TC_CTRLA_ENABLE;
  syncTC;
  IR_TCx->COUNT16.CTRLA.reg = TC_CTRLA_SWRST;
  while (IR_TCx->COUNT16.CTRLA.bit.SWRST);
  IR_TCx->COUNT16.CTRLA.reg |= TC_CTRLA_MODE_COUNT16;
  IR_TCx->COUNT16.CTRLA.reg |= TC_CTRLA_WAVEGEN_MFRQ;
  IR_TCx->COUNT16.CC[0].reg = F_CPU/(1000000/USEC_PER_TICK) - 1;
  syncTC;
}
#endif
