/**
 * This code shows how to output an analog signal using
 * the DAC (DigitalAnalogConverter) of an ATXMega.
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
 * The signal is written to pin 2 on port B (PB2)
 */
xmDAC dac=xmDAC(xmDAC::DAC_PORT_B);

/**
 * Prepeare the DAC before outputting a signal.
 */
void setup() {
  /*
   * Initialize the DAC in single channel mode. 
   * Use the supply voltage of the board as the reference voltage
   */
  int result=dac.begin(xmDAC::SINGLE_CHANNEL_MODE, xmDAC::VREF_VCC);
}

void loop() {
  /* 
   * The output is a slow sawtooth signal running from 0V to VCC in
   * 4096 steps.
   * The voltage rises slow enough to be visible on a multimeter. 
   * When the maximum output voltage is reached the output stays at this
   * level for two seconds.
   * Then the voltage drops to 0V and stays at this level for another 
   * two seconds. Then the whole signal is repeated.
   */
  int vout=0;
  while(vout<=0xFFF) {
    dac.write(vout);
    delay(5);
    vout++;
  }
  delay(2000);
  dac.write(0);
  delay(2000);
}

