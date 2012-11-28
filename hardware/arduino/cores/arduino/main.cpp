#include <Arduino.h>

extern "C" void setup(void) __attribute__((weak));
extern "C" void loop(void) __attribute__((weak));

__attribute__((weak))
int main(void)
{
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	if (setup) setup();
    
	for (;;) {
		if (loop) loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}
