#include <Energia.h>
extern "C" void setup(void);
extern "C" void loop(void);


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

