/*
 OneMsTaskTimer.h - Leveraging tasks using a timer with 1ms resolution
 
 History:
 got inspired by Arduino MsTimer2 by Javier Valencia <javiervalencia80@gmail.com>
 11/Nov/14 - Made more flexible for MSP430 variants
             set to 1ms overflow time -> change to OneMsTaskTimer
			 by Stefan Sch
 17/Nov/14 - restructured code to support mulitple tasks 
             added suppport for CC3200
			 by Stefan Sch
 
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

/*
 MSP430 Notes:
 This timer currently uses Timer1 available on chips like the MSP430G2553
 It uses CCR0 in interrupt mode with the same period as PWM so PWM is 
 still available for Timer1 which means pwm , analogWrite() is still available
 on the Timer1 associated pins.  We could have hacked into the watchdog timer
 which is used for millis() but that would have been a core change.
 
 The MSP430/Energia Servo library uses Timer0 so this library should be able to 
 run concurrently with Servo.  
 
 It will not run at the same time as the interrupt driven software serial library
 because that uses both timer interrupt vectors
*/

/*
How to use:
 Some applications or sensors require to get an tick, acknowledge or something else
 in a very regulare time frame. To handle that, this library can be used.
 Note: As all tasks are handled inside an interrupt service routine this should be 
       as less and as short as possible. 
	   
 For each task a structure 
   OneMsTaskTimer_t myTask1 ={500,  flash1, 0, 0};
 is required and needs to be setup with following parameters:
   Parameter 1: time in milli seconds between each task call
   Parameter 2: pointer to function which should be called by the tasks
   Parameter 3: init 0 - only used internal
   Parameter 4: init 0 - only used internal
 
 Add a task to the list to be processed:
   OneMsTaskTimer::add(&myTask1); // 500ms period
  
 Then start the timer:
   OneMsTaskTimer::start();
 To Stop the timer call:
   void stop();

  To remove a task from the list use:
    void remove(OneMsTaskTimer_t * task);
	
  When getting problems that a timer is used by another function already, a different
  Timer can be selected with:  
   void set_timer_index(uint32_t timer_index);
  Note: this function is not available for the MSP430. For this architecture the timer module
        can only be changed by modifing the define:
        #define DEFAULT_TIMER TIMER_A0_MODULE
		in the library source file

*/


#ifndef OneMsTaskTimer_h
#define OneMsTaskTimer_h

#include <stdint.h>

typedef struct OneMsTaskTimer_t{
    uint32_t msecs;
    void (*func)();
    uint32_t count;
    OneMsTaskTimer_t * nextTask;
} OneMsTaskTimer_t;


namespace OneMsTaskTimer {
//	extern volatile int8_t overflowing;
	void add(OneMsTaskTimer_t * task);
	void remove(OneMsTaskTimer_t * task);
	void start();
	void start(uint32_t timer_index);
	void stop();
	void set_timer_index(uint32_t timer_index);
	void _ticHandler();
}

#endif
