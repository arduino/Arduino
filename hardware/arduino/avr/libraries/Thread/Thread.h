/*****************************************************************************
 *                 Simplest kernel for iterative multithtreading             *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
#ifndef _THREAD_H_
#define _THREAD_H_

#ifdef __cplusplus
	extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

extern const void * MAIN;	// dummy state pointer of main thread
extern void 	  * thread;	// pointer to current thread state

void spawn(void * state, void (*start)(void)); // creation new thread

// switching control

void hold(void);	// disable thread switching and quantize
void schedule(void);	// enable thread swithing by yield only
void quantize(void);	// enable 1 ms quantizing and yield

// explicit swithing 

void yield(void);	// immediately switchng to next thread

// mutual exclussion

bool grab(void ** barrier, unsigned long timeout);
bool loose(void ** barrier);

#ifdef __cplusplus
	}
#endif
#endif

