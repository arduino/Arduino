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
 */

#include "Scheduler.h"

extern "C" {

#define NUM_REGS 10	// r4-r11, sp, pc

typedef struct CoopTask {
	uint32_t regs[NUM_REGS];
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
	return next;
}

static void __attribute__((naked)) __attribute__((noinline)) coopTaskStart(void) {
	asm (
		"mov   r0, r5;"
		"blx   r4;"
		/* schedule. */
		"mov   r0, #1;"      /* returned from task func: task done */
		"bl    coopSchedule;"
		/* r0 holds address of next task context */
#if defined(ARDUINO_ARCH_SAMD)
		/* for cortex m0, ldm and stm are restricted to low registers */
		/* load high registers */
		"add   r0, #16;"     /* they are 4 words higher in memory */
		"ldmia r0, {r1-r6};" /* load them in low registers first... */
		"mov   r8, r1;"      /* ...and move them into high registers... */
		"mov   r9, r2;"
		"mov   r10, r3;"
		"mov   r11, r4;"
		"mov   r12, r5;"
		"mov   lr, r6;"
		/* load low registers */
		"sub   r0, r0, #40;" /* back to begin of context */
		"ldmia r0, {r4-r7};"
#else
		"ldmia r0, {r4-r12, lr};"
#endif
		/* restore task stack */
		"mov   sp, r12;"
		/* resume task */
		"bx    lr;"
	);
}

static void __attribute__((naked)) __attribute__((noinline)) coopDoYield(CoopTask* curTask) {
	asm (
		"mov   r12, sp;"
#if defined(ARDUINO_ARCH_SAMD)
		/* store low registers */
		"stmia r0, {r4-r7};"
		/* store high registers */
		"mov   r1, r8;"      /* move them to low registers first. */
		"mov   r2, r9;"
		"mov   r3, r10;"
		"mov   r4, r11;"
		"mov   r5, r12;"
		"mov   r6, lr;"
		"stmia r0, {r1-r6};"
#else
		"stmia r0, {r4-r12, lr};"
#endif
		/* schedule. */
		"mov   r0, #0;"      /* previous task did not complete */
		"bl    coopSchedule;"
		/* r0 holds address of next task context */
#if defined(ARDUINO_ARCH_SAMD)
		/* for cortex m0, ldm and stm are restricted to low registers */
		/* load high registers */
		"add   r0, #16;"     /* they are 4 words higher in memory */
		"ldmia r0, {r1-r6};" /* load them in low registers first... */
		"mov   r8, r1;"      /* ...and move them into high registers... */
		"mov   r9, r2;"
		"mov   r10, r3;"
		"mov   r11, r4;"
		"mov   r12, r5;"
		"mov   lr, r6;"
		/* load low registers */
		"sub   r0, r0, #40;" /* back to begin of context */
		"ldmia r0, {r4-r7};"
#else
		"ldmia r0, {r4-r12, lr};"
#endif
		/* restore task stack */
		"mov   sp, r12;"
		/* resume task */
		"bx    lr;"
	);
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
	task->regs[8] = ((uint32_t)(stack + stackSz)) & ~7;
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

SchedulerClass Scheduler;

