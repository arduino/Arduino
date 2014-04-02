/*
 Servo.cpp - Interrupt driven Servo library for MSP430
 Copyright (c) 2012 Petr Baudis.  All right reserved.
 Modified by Peter Brier 26-6-2012: Fixed timing/IRQ problem

 Derived from:
 Servo.cpp - Interrupt driven Servo library for Arduino using 16 bit timers- Version 2
 Copyright (c) 2009 Michael Margolis.  All right reserved.

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "Energia.h"
#include "Servo.h"

#define F_TIMER (F_CPU/8L)
#define usToTicks(_us)    (( clockCyclesPerMicrosecond()* _us) / 8)     // converts microseconds to timer ticks (assumes prescale of 8)
#define ticksToUs(_ticks) (( (unsigned)_ticks * 8)/ clockCyclesPerMicrosecond() ) // converts from ticks back to microseconds

#define TRIM_DURATION       2                               // compensation ticks to trim adjust for digitalWrite delays // 12 August 2009


#define SERVO_MIN() (MIN_PULSE_WIDTH - this->min * 4)  // minimum value in uS for this servo
#define SERVO_MAX() (MAX_PULSE_WIDTH - this->max * 4)  // maximum value in uS for this servo 


/************ static functions and data structures common to all instances ***********************/


static servo_t servos[MAX_SERVOS]; // static array of servo structures
static unsigned int ServoCount = 0; // the total number of attached servos

static volatile int counter = 0; // Servo counter; -1 before first servo starts being serviced
static volatile unsigned int totalWait = 0; // Total amount waited so far in the current period; after all servos, wait for the rest of REFRESH_INTERVAL

#ifndef TIMERA0_VECTOR
#define TIMERA0_VECTOR TIMER0_A0_VECTOR
#endif /* TIMER0_A0_VECTOR */

// Timer A0 interrupt service routine
static void inline
Timer_A(void)
{
  static unsigned long wait;
  if (counter >= 0) {
    /* Turn pulse off. */
    digitalWrite(servos[counter].Pin.nbr, LOW);
  }

  /* Service next servo, while skipping any inactive servo records. */
  do {
    counter++;
  /* counter is nonnegative, so it is save to type cast to unsigned */
  } while (!servos[counter].Pin.isActive && (unsigned)counter < ServoCount);

  /* Counter range is 0-ServoCount, the last count is used to complete the REFRESH_INTERVAL 
   * counter is nonnegative, so it is save to type cast to unsigned */
  if ((unsigned)counter < ServoCount) {
    /* Turn pulse on for the next servo. */
    digitalWrite(servos[counter].Pin.nbr, HIGH);
    /* And hold! */
    totalWait += servos[counter].ticks;
    TA0CCR0 = servos[counter].ticks;
  } else {
    /* Wait for the remaining of REFRESH_INTERVAL. */
    wait = usToTicks(REFRESH_INTERVAL) - totalWait;
    totalWait = 0;
    TA0CCR0 = (wait < 1000 ? 1000 : wait);
    counter = -1;
  }
}

// Timer A0 interrupt service routine
__attribute__((interrupt(TIMERA0_VECTOR)))
static void
Timer_A_int(void)
{
  Timer_A();
}

static boolean isTimerActive(void)
{
  // returns true if any servo is active
  for(int i = 0; i < MAX_SERVOS; i++)
    if (servos[i].Pin.isActive == true)
      return true;
  return false;
}

static void enableTimer(void)
{
  counter = -1;
  totalWait = 0;

  Timer_A(); // enable first servo

  TA0CCTL0 = CCIE;                             // CCR0 interrupt enabled
  TA0CTL = TASSEL_2 + MC_1 + ID_3;           // prescale SMCLK/8, upmode
}

static void disableTimer(void)
{
  // disable interrupt
  TA0CCTL0 = 0;
  TA0CCR0 = 0;
}


/****************** end of static functions ******************************/

Servo::Servo()
{
  if( ServoCount < MAX_SERVOS) {
    this->servoIndex = ServoCount++;                    // assign a servo index to this instance
	servos[this->servoIndex].ticks = usToTicks(DEFAULT_PULSE_WIDTH);   // store default values
  }
  else
    this->servoIndex = INVALID_SERVO ;  // too many servos 
}

uint8_t Servo::attach(int pin)
{
  return this->attach(pin, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
}

uint8_t Servo::attach(int pin, int min, int max)
{
  if(this->servoIndex < MAX_SERVOS ) {
    pinMode( pin, OUTPUT) ;                                   // set servo pin to output
    servos[this->servoIndex].Pin.nbr = pin;  

    // todo min/max check: abs(min - MIN_PULSE_WIDTH) /4 < 128 
    this->min  = (MIN_PULSE_WIDTH - min)/4; //resolution of min/max is 4 uS
    this->max  = (MAX_PULSE_WIDTH - max)/4; 

    boolean timer_active = isTimerActive();
    servos[this->servoIndex].Pin.isActive = true;
    if (!timer_active)
      enableTimer();
  } 
  return this->servoIndex ;
}

void Servo::detach()  
{
  servos[this->servoIndex].Pin.isActive = false;
  if (!isTimerActive())
    disableTimer();
}

void Servo::write(int value)
{  
  if(value < MIN_PULSE_WIDTH)
  {  // treat values less than 544 as angles in degrees (valid values in microseconds are handled as microseconds)
    if(value < 0) value = 0;
    if(value > 180) value = 180;
    value = map(value, 0, 180, SERVO_MIN(),  SERVO_MAX());      
  }
  this->writeMicroseconds(value);
}

void Servo::writeMicroseconds(int value)
{
  // calculate and store the values for the given channel
  byte channel = this->servoIndex;
  if( (channel < MAX_SERVOS) )   // ensure channel is valid
  {  
    if( value < SERVO_MIN() )          // ensure pulse width is valid
      value = SERVO_MIN();
    else if( value > SERVO_MAX() )
      value = SERVO_MAX();       
    value = value - TRIM_DURATION;
    volatile int v = usToTicks(value);  // convert to ticks after compensating for interrupt overhead - 12 Aug 2009
    servos[channel].ticks = v; // this is atomic on a 16bit uC, no need to disable Interrupts
  } 
}

int Servo::read() // return the value as degrees
{
  return  map( this->readMicroseconds()+1, SERVO_MIN(), SERVO_MAX(), 0, 180);     
}

int Servo::readMicroseconds()
{
  unsigned int pulsewidth;
  if( this->servoIndex != INVALID_SERVO )
    pulsewidth = ticksToUs(servos[this->servoIndex].ticks) + TRIM_DURATION;
  else 
    pulsewidth = 0;

  return pulsewidth;   
}

bool Servo::attached()
{
  return servos[this->servoIndex].Pin.isActive ;
}
