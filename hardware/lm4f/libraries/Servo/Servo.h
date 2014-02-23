#ifndef SERVO_H
#define SERVO_H

#include "Energia.h"
#include <inttypes.h>

// Hardware limitations information
#define MIN_SERVO_PULSE_WIDTH 		544
#define MAX_SERVO_PULSE_WIDTH 		2400
#define DEFAULT_SERVO_PULSE_WIDTH   1500
#define REFRESH_INTERVAL 		    20000

// Aliases for timer config and loading
#define SERVO_TIMER				TIMER2_BASE
#define SERVO_TIME_CFG			TIMER_CFG_PERIODIC
#define SERVO_TIMER_TRIGGER		TIMER_TIMA_TIMEOUT
#define SERVO_TIMER_INTERRUPT	INT_TIMER2A
#define SERVO_TIMER_A			TIMER_A
#define SERVO_TIMER_PERIPH		SYSCTL_PERIPH_TIMER2

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
    unsigned int attach(unsigned int pin, int min = MIN_SERVO_PULSE_WIDTH, int max = MAX_SERVO_PULSE_WIDTH);
    void detach();
    void writeMicroseconds(int value);
    int readMicroseconds();
    void write(int value);
    int read();
    bool attached();

};

extern "C" void ServoIntHandler(void);

#endif // SERVO_H
