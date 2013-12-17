#include <Energia.h>
extern "C" void setup(void);
extern "C" void loop(void);

//TwoWire Wire;

int main(void)
{
	init();

	setup();

	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}

//	return 0;
}

