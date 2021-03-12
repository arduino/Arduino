#if defined(ARDUINO_ARCH_MBED)

#include <Arduino.h>
#include <Servo.h>

class ServoImpl {
    mbed::DigitalOut   *pin;
    mbed::Timeout      timeout;  // calls a callback once when a timeout expires
    mbed::Ticker       ticker;   // calls a callback repeatedly with a timeout

public:
    ServoImpl(PinName _pin) {
      pin = new mbed::DigitalOut(_pin);
    }

    ~ServoImpl() {
        ticker.detach();
        timeout.detach();
        delete pin;
    }

    void start(uint32_t duration_us) {
      duration = duration_us;
      ticker.attach(mbed::callback(this, &ServoImpl::call), 0.02f);
    }

    void call() {
        timeout.attach(mbed::callback(this, &ServoImpl::toggle), duration / 1e6);
        toggle();
    }

    void toggle() {
      *pin = !*pin;
    }

    int32_t           duration = -1;
};

static ServoImpl* servos[MAX_SERVOS];                      // static array of servo structures
uint8_t ServoCount = 0;                                    // the total number of attached servos

#define SERVO_MIN() (MIN_PULSE_WIDTH - this->min)   // minimum value in uS for this servo
#define SERVO_MAX() (MAX_PULSE_WIDTH - this->max)   // maximum value in uS for this servo

#define TRIM_DURATION   15                           //callback overhead (35 uS) -> 15uS if toggle() is called after starting the timeout

Servo::Servo()
{
  if (ServoCount < MAX_SERVOS) {
    this->servoIndex = ServoCount++;
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
  pinMode(pin, OUTPUT);                                   // set servo pin to output
  servos[this->servoIndex] = new ServoImpl(digitalPinToPinName(pin));

  this->min  = (MIN_PULSE_WIDTH - min);
  this->max  = (MAX_PULSE_WIDTH - max);
  return this->servoIndex;
}

void Servo::detach()
{
  delete servos[this->servoIndex];
  servos[this->servoIndex] = NULL;
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
  if (!servos[this->servoIndex]) {
    return;
  }
  // calculate and store the values for the given channel
  byte channel = this->servoIndex;
  if( (channel < MAX_SERVOS) )   // ensure channel is valid
  {
    if (value < SERVO_MIN())          // ensure pulse width is valid
      value = SERVO_MIN();
    else if (value > SERVO_MAX())
      value = SERVO_MAX();

    value = value - TRIM_DURATION;
    if (servos[this->servoIndex]->duration == -1) {
      servos[this->servoIndex]->start(value);
    }
    servos[this->servoIndex]->duration = value;
  }
}

int Servo::read() // return the value as degrees
{
  return map(readMicroseconds(), SERVO_MIN(), SERVO_MAX(), 0, 180);
}

int Servo::readMicroseconds()
{
  if (!servos[this->servoIndex]) {
    return 0;
  }
  return servos[this->servoIndex]->duration;
}

bool Servo::attached()
{
  return servos[this->servoIndex] != NULL;
}

#endif