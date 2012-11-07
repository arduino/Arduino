#include <Energia.h>

int main(void)
{
	init();

	setup();

	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}

	return 0;
}

