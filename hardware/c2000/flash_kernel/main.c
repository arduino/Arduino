/*
 * main.c
 */
#include "DSP28x_Project.h"
extern Uint32 SCI_Boot();

void (*ApplicationPtr) (void);

Uint32 main(void) {
	//GPIO and SCI are still setup from Sci_Boot()
	//Setup sysctl and pll
   DisableDog();
   IntOsc1Sel();
   InitPll(DSP28_PLLCR,DSP28_DIVSEL);
   InitFlash();

   DELAY_US(100);

//	ApplicationPtr = (void(*)(void))SCI_Boot();
//
//	if(ApplicationPtr)
//		ApplicationPtr();

	return SCI_Boot();

//	asm(" .ref _ExitBoot");
//    asm(" BF  _ExitBoot,UNC");

//   return 0;

}
