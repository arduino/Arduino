/*
 * main.c
 */
#include "DSP28x_Project.h"
extern Uint32 SCI_Boot();

void (*ApplicationPtr) (void);

int main(void) {
	//GPIO and SCI are still setup from Sci_Boot()
	//Setup sysctl and pll
   DisableDog();
   IntOsc1Sel();
   InitPll(DSP28_PLLCR,DSP28_DIVSEL);

	ApplicationPtr = (void(*)(void))SCI_Boot();

	if(ApplicationPtr)
		ApplicationPtr();

	return 0;
}
