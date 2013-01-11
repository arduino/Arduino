/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

/* modified by Fabrice Oudert 8 Jan 2013
 * including spcific code for compatibility with AVR platform (not atmega2560)
 * Scheduler library package available on google Code here:
 * https://code.google.com/p/arduino-scoop-cooperative-scheduler-arm-avr/
 */
 
#ifndef _SCHEDULDER_H_
#define _SCHEDULDER_H_

#include <Arduino.h>

extern "C" {
	typedef void (*SchedulerTask)(void);
	typedef void (*SchedulerParametricTask)(void *);

#if ARDUINO < 150
void yield(void); // define a global yield function 
#warning "library calls to Arduino delay doesnt contain yield() and might block scheduler during this delay"
#endif

}

#ifndef yieldPROTECT
#define yieldPROTECT() static uint8_t __yieldProtect = 0; \
uint8_t* __temp __attribute__((__cleanup__(__yieldUnprotect))) = & __yieldProtect; \
while (__yieldProtect) yield(); __yieldProtect = 1; 
void inline __yieldUnprotect(uint8_t* *__s) { uint8_t* staticFlag = *__s; *staticFlag = 0; };
#endif

#ifndef yieldATOMIC
#define yieldATOMIC for ( uint8_t __temp __attribute__((__cleanup__(__decYieldAtomic))) = __incYieldAtomic(); __temp  ; __temp = 0 )
static volatile uint8_t __yieldAtomic = 0;
void  inline   __decYieldAtomic(const  uint8_t *__s) { --__yieldAtomic; }
uint8_t inline __incYieldAtomic(void)                { ++__yieldAtomic; return 1; }
#endif

#ifdef __AVR__
#define SchedulerDefaultStack 256  // proposed value, might be too low fo complex application or too high if not needed ... to be experimented by user
#else
#define SchedulerDefaultStack 1024 // original value , probably too much for most usage, but lot of memory on SAM
#endif


class SchedulerClass {
public:
	SchedulerClass();
	static void startLoop(SchedulerTask task, uint32_t stackSize = SchedulerDefaultStack);
	static void start(SchedulerTask task, uint32_t stackSize = SchedulerDefaultStack);
	static void start(SchedulerParametricTask task, void *data, uint32_t stackSize = SchedulerDefaultStack);
    static void delay(uint32_t ms);
	
	static void yield() { ::yield(); };
};

extern SchedulerClass Scheduler;


#endif

