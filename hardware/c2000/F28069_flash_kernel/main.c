/*
 * main.c
 */
#include "DSP28x_Project.h"     // Device Headerfile and Examples Include File

extern Uint32 SCI_Boot();

void (*ApplicationPtr) (void);

Uint32 main(void) {
	//GPIO and SCI are still setup from Sci_Boot()
	//Setup sysctl and pll
   DisableDog();
   IntOsc1Sel();
   InitPll(DSP28_PLLCR,DSP28_DIVSEL);

   DELAY_US(100);
   return SCI_Boot();
}
