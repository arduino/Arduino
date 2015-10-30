#ifndef SERVO_H
#define SERVO_H

#include "Energia.h"
#include <inttypes.h>
#include <ti/sysbios/hal/Timer.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Error.h>
//#include <ti/sysbios/family/arm/msp432/Timer.h>

// Hardware limitations information
#define MIN_SERVO_PULSE_WIDTH 		544
#define MAX_SERVO_PULSE_WIDTH 		2400
#define DEFAULT_SERVO_PULSE_WIDTH   1500
#define REFRESH_INTERVAL 		    20000

// Aliases for timer config and loading
#define SERVO_TIMER				TIMERA0_BASE
#define SERVO_TIME_CFG			TIMER_CFG_B_PERIODIC | TIMER_CFG_SPLIT_PAIR
#define SERVO_TIMER_TRIGGER		TIMER_TIMB_TIMEOUT
#define SERVO_TIMER_INTERRUPT	INT_TIMERA0B
#define SERVO_TIMER_AB			TIMER_B
#define SERVO_TIMER_PERIPH		PRCM_TIMERA0

// Other defines
#define SERVOS_PER_TIMER 	8
#define INVALID_SERVO 		255

typedef struct
{
	unsigned int pin_number;
	unsigned int pulse_width;
	bool enabled;
} servo_t;

class Servo
{
private:
	unsigned int index;
	int min;
	int max;
public:
	Servo();
	static Timer_Params timerParams;
	static Timer_Handle timerHandle;
	unsigned int attach(unsigned int pin, int min = MIN_SERVO_PULSE_WIDTH, int max = MAX_SERVO_PULSE_WIDTH);
	void detach();
	void writeMicroseconds(int value);
	int readMicroseconds();
	void write(int value);
	int read();
	bool attached();
};

extern "C" Void ServoIntHandler(UArg arg0);

#endif // SERVO_H
