#if defined(ARDUINO_ARCH_MEGAAVR)

#include <Arduino.h>
#include <Servo.h>

#define usToTicks(_us)    ((clockCyclesPerMicrosecond() / 16 * _us) / 4)                 // converts microseconds to tick
#define ticksToUs(_ticks) (((unsigned) _ticks * 16) / (clockCyclesPerMicrosecond() / 4))   // converts from ticks back to microseconds

#define TRIM_DURATION  5                                   // compensation ticks to trim adjust for digitalWrite delays

static servo_t servos[MAX_SERVOS];                         // static array of servo structures

uint8_t ServoCount = 0;                                    // the total number of attached servos

static volatile int8_t currentServoIndex[_Nbr_16timers];   // index for the servo being pulsed for each timer (or -1 if refresh interval)

// convenience macros
#define SERVO_INDEX_TO_TIMER(_servo_nbr) ((timer16_Sequence_t)(_servo_nbr / SERVOS_PER_TIMER))   // returns the timer controlling this servo
#define SERVO_INDEX_TO_CHANNEL(_servo_nbr) (_servo_nbr % SERVOS_PER_TIMER)                       // returns the index of the servo on this timer
#define SERVO_INDEX(_timer,_channel)  ((_timer*SERVOS_PER_TIMER) + _channel)                     // macro to access servo index by timer and channel
#define SERVO(_timer,_channel)  (servos[SERVO_INDEX(_timer,_channel)])                           // macro to access servo class by timer and channel

#define SERVO_MIN() (MIN_PULSE_WIDTH - this->min * 4)   // minimum value in uS for this servo
#define SERVO_MAX() (MAX_PULSE_WIDTH - this->max * 4)   // maximum value in uS for this servo

#undef REFRESH_INTERVAL
#define REFRESH_INTERVAL 16000

void ServoHandler(int timer)
{
    if (currentServoIndex[timer] < 0) {
        // Write compare register
        _timer->CCMP = 0;
    } else {
        if (SERVO_INDEX(timer, currentServoIndex[timer]) < ServoCount && SERVO(timer, currentServoIndex[timer]).Pin.isActive == true) {
            digitalWrite(SERVO(timer, currentServoIndex[timer]).Pin.nbr, LOW);   // pulse this channel low if activated
        }
    }

    // Select the next servo controlled by this timer
    currentServoIndex[timer]++;

    if (SERVO_INDEX(timer, currentServoIndex[timer]) < ServoCount && currentServoIndex[timer] < SERVOS_PER_TIMER) {
        if (SERVO(timer, currentServoIndex[timer]).Pin.isActive == true) {   // check if activated
            digitalWrite(SERVO(timer, currentServoIndex[timer]).Pin.nbr, HIGH);   // it's an active channel so pulse it high
        }

        // Get the counter value
        uint16_t tcCounterValue =  0; //_timer->CCMP;
        _timer->CCMP = (uint16_t) (tcCounterValue + SERVO(timer, currentServoIndex[timer]).ticks);
    }
    else {
        // finished all channels so wait for the refresh period to expire before starting over

        // Get the counter value
        uint16_t tcCounterValue = _timer->CCMP;

        if (tcCounterValue + 4UL < usToTicks(REFRESH_INTERVAL)) {   // allow a few ticks to ensure the next OCR1A not missed
            _timer->CCMP = (uint16_t) usToTicks(REFRESH_INTERVAL);
        }
        else {
            _timer->CCMP = (uint16_t) (tcCounterValue + 4UL);   // at least REFRESH_INTERVAL has elapsed
        }

        currentServoIndex[timer] = -1;   // this will get incremented at the end of the refresh period to start again at the first channel
    }

    /* Clear flag */
    _timer->INTFLAGS = TCB_CAPT_bm;
}

#if defined USE_TIMERB0
ISR(TCB0_INT_vect)
#elif defined USE_TIMERB1
ISR(TCB1_INT_vect)
#elif defined USE_TIMERB2
ISR(TCB2_INT_vect)
#endif
{
  ServoHandler(0);
}

static void initISR(timer16_Sequence_t timer)
{
  //TCA0.SINGLE.CTRLA = (TCA_SINGLE_CLKSEL_DIV16_gc) | (TCA_SINGLE_ENABLE_bm);

  _timer->CTRLA = TCB_CLKSEL_CLKTCA_gc;
  // Timer to Periodic interrupt mode
  // This write will also disable any active PWM outputs
  _timer->CTRLB = TCB_CNTMODE_INT_gc;
  // Enable interrupt
  _timer->INTCTRL = TCB_CAPTEI_bm;
  // Enable timer
  _timer->CTRLA |= TCB_ENABLE_bm;
}

static void finISR(timer16_Sequence_t timer)
{
  // Disable interrupt
  _timer->INTCTRL = 0;
}

static boolean isTimerActive(timer16_Sequence_t timer)
{
  // returns true if any servo is active on this timer
  for(uint8_t channel=0; channel < SERVOS_PER_TIMER; channel++) {
    if(SERVO(timer,channel).Pin.isActive == true)
      return true;
  }
  return false;
}

/****************** end of static functions ******************************/

Servo::Servo()
{
  if (ServoCount < MAX_SERVOS) {
    this->servoIndex = ServoCount++;                    // assign a servo index to this instance
    servos[this->servoIndex].ticks = usToTicks(DEFAULT_PULSE_WIDTH);   // store default values
  } else {
    this->servoIndex = INVALID_SERVO;  // too many servos
  }
}

uint8_t Servo::attach(int pin)
{
  return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

uint8_t Servo::attach(int pin, int min, int max)
{
  timer16_Sequence_t timer;

  if (this->servoIndex < MAX_SERVOS) {
    pinMode(pin, OUTPUT);                                   // set servo pin to output
    servos[this->servoIndex].Pin.nbr = pin;
    // todo min/max check: abs(min - MIN_PULSE_WIDTH) /4 < 128
    this->min  = (MIN_PULSE_WIDTH - min)/4; //resolution of min/max is 4 uS
    this->max  = (MAX_PULSE_WIDTH - max)/4;
    // initialize the timer if it has not already been initialized
    timer = SERVO_INDEX_TO_TIMER(servoIndex);
    if (isTimerActive(timer) == false) {
      initISR(timer);
    }
    servos[this->servoIndex].Pin.isActive = true;  // this must be set after the check for isTimerActive
  }
  return this->servoIndex;
}

void Servo::detach()
{
  timer16_Sequence_t timer;

  servos[this->servoIndex].Pin.isActive = false;
  timer = SERVO_INDEX_TO_TIMER(servoIndex);
  if(isTimerActive(timer) == false) {
    finISR(timer);
  }
}

void Servo::write(int value)
{
  // treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
  if (value < MIN_PULSE_WIDTH)
  {
    if (value < 0)
      value = 0;
    else if (value > 180)
      value = 180;

    value = map(value, 0, 180, SERVO_MIN(), SERVO_MAX());
  }
  writeMicroseconds(value);
}

void Servo::writeMicroseconds(int value)
{
  // calculate and store the values for the given channel
  byte channel = this->servoIndex;
  if( (channel < MAX_SERVOS) )   // ensure channel is valid
  {
    if (value < SERVO_MIN())          // ensure pulse width is valid
      value = SERVO_MIN();
    else if (value > SERVO_MAX())
      value = SERVO_MAX();

    value = value - TRIM_DURATION;
    value = usToTicks(value);  // convert to ticks after compensating for interrupt overhead
    servos[channel].ticks = value;
  }
}

int Servo::read() // return the value as degrees
{
  return map(readMicroseconds()+1, SERVO_MIN(), SERVO_MAX(), 0, 180);
}

int Servo::readMicroseconds()
{
  unsigned int pulsewidth;
  if (this->servoIndex != INVALID_SERVO)
    pulsewidth = ticksToUs(servos[this->servoIndex].ticks)  + TRIM_DURATION;
  else
    pulsewidth  = 0;

  return pulsewidth;
}

bool Servo::attached()
{
  return servos[this->servoIndex].Pin.isActive;
}

#endif