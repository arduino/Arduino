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
 * including spcific code for compatibility with AVR platform (not 2560)
 * Scheduler library package available on google Code here:
 * https://code.google.com/p/arduino-scoop-cooperative-scheduler-arm-avr/
 */

#include "SchedulerARMAVR.h"

extern "C" {

#if defined(__arm__)
#define NUM_REGS (8+1+1)	// r4-r11, sp, pc
#elif defined(__AVR_3_BYTE_PC__)
#error "not compatible with atmega256x, sorry ! please provide ideas on the arduino.cc forum"
#else
#define NUM_REGS (8+1+1+1)	// r2-r17, sp, pc, r28-r29
#endif

typedef struct CoopTask {
#ifdef __arm__
	uint32_t regs[NUM_REGS];
#else
    uint16_t regs[NUM_REGS];
#endif
	void* stackPtr;
	struct CoopTask* next;
	struct CoopTask* prev;
} CoopTask;

static CoopTask *cur = 0;

static CoopTask* __attribute__((noinline)) coopSchedule(char taskDied) {
	CoopTask* next = cur->next;

	if (taskDied) {
		// Halt if last task died.
		
		if (next == cur)
			while (1)
				;

		// Delete task
		if (cur->stackPtr)
			free(cur->stackPtr);
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		free(cur);
	}
	cur = next;
#ifdef __AVR__
  asm volatile ("movw    r30, %[reg]" : : [reg] "r" (next));
  asm volatile ("ldd     r5, Z+3");  
  asm volatile ("ldd     r6, Z+4");  
  asm volatile ("ldd     r7, Z+5");  
  asm volatile ("ldd     r8, Z+6");  
  asm volatile ("ldd     r9, Z+7");  
  asm volatile ("ldd     r10, Z+8");  
  asm volatile ("ldd     r11, Z+9");  
  asm volatile ("ldd     r12, Z+10");  
  asm volatile ("ldd     r13, Z+11");  
  asm volatile ("ldd     r14, Z+12");  
  asm volatile ("ldd     r15, Z+13");  
  asm volatile ("ldd     r16, Z+14");  
  asm volatile ("ldd     r17, Z+15");  
  
  asm volatile ("ldd     r2, Z+16");  // restore  SP 
  asm volatile ("ldd     r3, Z+17");
  asm volatile ("in      r4, 0x3f"); // save SREG
  asm volatile ("cli             "); // just to be safe on playing with stack ptr :) (useless with xmega)
  asm volatile ("out     0x3e, r3"); // SPH
  asm volatile ("out     0x3d, r2"); // SPL
  asm volatile ("out     0x3f, r4"); // restore SREG asap (same approach as in setjmp.S credit to Marek Michalkiewicz)
  
  asm volatile ("ldd     r2, Z+0");  
  asm volatile ("ldd     r3, Z+1");  
  asm volatile ("ldd     r4, Z+2");  
  asm volatile ("ldd     r28, Z+20"); // get previous R28,R29
  asm volatile ("ldd     r29, Z+21"); 
  asm volatile ("ldd     __tmp_reg__, Z+18");  // return low
  asm volatile ("ldd     r31, Z+19");          // return hi
  asm volatile ("mov     r30,__tmp_reg__");
  asm volatile ("ijmp");  	          // jump back to task return adress
  #endif

  return cur; // just to avoid warning !
}

static void __attribute__((naked)) __attribute__((noinline)) coopTaskStart(void) {
#ifdef __arm__
	asm (
		"mov   r0, r5;"
		"blx   r4;"
		"mov   r0, #1;"
		"bl    coopSchedule;"
		"ldmia r0, {r4-r12, lr};"
		"mov   sp, r12;"
		"bx    lr;"
	);
#else
  asm volatile ("movw    r30,r2");       // get original taskF parameter
  asm volatile ("movw    r24,r4");       // get original taskData parameter
  asm volatile ("icall");                // call taskF
  asm volatile ("ldi     r24,1");        // task died
  asm volatile ("rjmp    coopSchedule"); // get next task pointer
#endif
}

static void __attribute__((naked)) __attribute__((noinline)) coopDoYield(CoopTask* curTask) {
#ifdef __arm__
	asm (
		"mov   r12, sp;"
		"stmia r0, {r4-r12, lr};"
		"mov   r0, #0;"
		"bl    coopSchedule;"
		"ldmia r0, {r4-r12, lr};"
		"mov   sp, r12;"
		"bx    lr;"
	);
#else
  asm volatile ("movw    r30, %[cur]" : : [cur] "r" (curTask));
  asm volatile ("std     Z+0, r2");   // save register in current cooptask structure 
  asm volatile ("std     Z+1, r3");  
  asm volatile ("std     Z+2, r4");  
  asm volatile ("std     Z+3, r5");  
  asm volatile ("std     Z+4, r6");  
  asm volatile ("std     Z+5, r7");  
  asm volatile ("std     Z+6, r8");  
  asm volatile ("std     Z+7, r9");  
  asm volatile ("std     Z+8, r10");  
  asm volatile ("std     Z+9, r11");  
  asm volatile ("std     Z+10, r12");  
  asm volatile ("std     Z+11, r13");  
  asm volatile ("std     Z+12, r14");  
  asm volatile ("std     Z+13, r15");  
  asm volatile ("std     Z+14, r16");  
  asm volatile ("std     Z+15, r17");  
  asm volatile ("pop     r3");        // return adresse = yield caller /// NOT COMPATIBLE 2560
  asm volatile ("pop     r2"); 
  asm volatile ("std     Z+18, r2");  // store return adress
  asm volatile ("std     Z+19, r3"); 
  asm volatile ("in      r2, 0x3d");  // SPL
  asm volatile ("in      r3, 0x3e");  // SPH
  asm volatile ("std     Z+16, r2"); 
  asm volatile ("std     Z+17, r3");
  asm volatile ("std     Z+20, r28");
  asm volatile ("std     Z+21, r29"); 
  
  asm volatile ("ldi     r24, 0");    
  asm volatile ("rjmp    coopSchedule");  // get next task pointer 
#endif
}

static int coopInit(void) {
	CoopTask* task;

	task = reinterpret_cast<CoopTask *>(malloc(sizeof(CoopTask)));
	if (!task)
		return 0;
	task->next = task;
	task->prev = task;
	task->stackPtr = 0;
	cur = task;

	return 1;
}

static int coopSpawn(SchedulerParametricTask taskF, void* taskData, uint32_t stackSz) {
	uint8_t *stack = (uint8_t*)malloc(stackSz);
	if (!stack)
		return 0;

	CoopTask *task = reinterpret_cast<CoopTask *>(malloc(sizeof(CoopTask)));
	if (!task) {
		free(stack);
		return 0;
	}
	task->stackPtr = stack;
	task->regs[0] = (uint32_t) taskF;
	task->regs[1] = (uint32_t) taskData;
	task->regs[8] = ((uint32_t)(stack + stackSz)) 
#ifdef __arm__
	& ~7
#endif
	;
	task->regs[9] = (uint32_t) & coopTaskStart;

	task->prev = cur;
	task->next = cur->next;
	cur->next->prev = task;
	cur->next = task;

	// These are here so compiler is sure that function is
	// referenced in both variants (cancels a warning)
	if (stackSz == 0xFFFFFFFF)
		coopSchedule(0);
	if (stackSz == 0xFFFFFFFE)
		coopSchedule(1);

	return 1;
}

void yield(void) {
	coopDoYield(cur);
}

}; // extern "C"

SchedulerClass::SchedulerClass() {
	coopInit();
}

static void startLoopHelper(void *taskData) {
	SchedulerTask task = reinterpret_cast<SchedulerTask>(taskData);
	while (true)
		task();
}

void SchedulerClass::startLoop(SchedulerTask task, uint32_t stackSize) {
	coopSpawn(startLoopHelper, reinterpret_cast<void *>(task), stackSize);
}

static void startTaskHelper(void *taskData) {
	SchedulerTask task = reinterpret_cast<SchedulerTask>(taskData);
	task();
}

void SchedulerClass::start(SchedulerTask task, uint32_t stackSize) {
	coopSpawn(startTaskHelper, reinterpret_cast<void *>(task), stackSize);
}

void SchedulerClass::start(SchedulerParametricTask task, void *taskData, uint32_t stackSize) {
	coopSpawn(task, taskData, stackSize);
}
// added for some level of compatibility with Arduino < 150
void SchedulerClass::delay(uint32_t ms) {
  uint32_t end = millis() + ms;
  while (millis() < end)	yield();
}

SchedulerClass Scheduler;

