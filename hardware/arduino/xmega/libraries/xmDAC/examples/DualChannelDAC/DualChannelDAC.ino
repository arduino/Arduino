/**
 * This example shows how to output an analog signal using
 * the DAC (DigitalAnalogConverter) of an ATXMega in 
 * Dual Channel Mode.
 * 
 * Created 2010 by Eberhard Fahle <e.fahle@wayoda.org>
 * 
 * THIS CODE IS IN THE PUBLIC DOMAIN
 *
 */

/* The name of the library to include is "xmDAC" */
#include "xmDAC.h"

/*
 * Create a variable for the DAC on the hardware.
 * The ATXmega has at most two ports equipped with a DAC.
 * We use the DAC on Port B.
 * The two signals will be written to pins 2 and 3 on port B (PB2 + PB3)
 */
xmDAC dac=xmDAC(xmDAC::DAC_PORT_B);

/**
 * Prepare the DAC before outputting a signal.
 */
void setup() {
  /*
   * Initialize the DAC in dual channel mode. 
   * Use the supply voltage of the board as the reference voltage.
   */
  int result=dac.begin(xmDAC::DUAL_CHANNEL_MODE, xmDAC::VREF_VCC);
}

void loop() {
  /* 
   * The output is a slow sawtooth signal running from 0 to VCC in
   * 4096 steps which is output to pin2, 
   * and a reversed sawtooth (VCC->0) signal output to pin 3.
   * The voltage rises and drops slow enough to be visible on a multimeter. 
   * When the sawtooth signal is completed the output stays at its last level 
   * level for two seconds. (VCC on pin 2; 0v on pin 3)
   * Then the voltage drops to 0V on pin 2 and rises to VCC on pin 3
   * and stays at this level for two seconds.
   * Then the whole signal is repeated.
   */
  int vout0=0;
  int vout1=0xFFF;
  while(vout0<=0xFFF) {
    dac.write(vout0,vout1);
    delay(5);
    vout0++;
    vout1--;
  }
  delay(2000);
  dac.write(0,0xFFF);
  delay(2000);
}

