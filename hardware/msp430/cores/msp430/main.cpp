#include <Arduino.h>

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD; //!!!!!!!!!!!

	init();

	setup();
	// init and setup are called with interrupts off.
	__bis_SR_register(GIE);

	for (;;) {
		loop();
	}

	return 0;
}

