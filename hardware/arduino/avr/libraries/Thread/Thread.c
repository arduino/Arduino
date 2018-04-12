/*****************************************************************************
 *                 Simplest kernel for iterative multithtreading             *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <setjmp.h>
#include <stddef.h>
#include <Arduino.h>
#include "Thread.h"

/* Definitions what depend on hardware */

#define QUANTUM_VECTOR	TIMER0_COMPB_vect
#define QUANTUM_VALUE	250

#define __packed
#define __stackup __attribute__((optimize("conserve-stack")))
#define __thread  __attribute__((OS_task))

#define disable_interrupts()   cli()
#define enable_interrupts()    sei()

#define barrier() __asm__ volatile("" ::: "memory")

#define set_stack_pointer(sp)\
\
	barrier(); SP = (uint16_t)(sp);

#define enter_kernel_section()\
\
	unsigned char __sreg__ = SREG;\
	barrier(); SREG = 0;
	
#define leave_kernel_section()\
\
	barrier(); SREG = __sreg__;

#define restart_quantum_timer()\
\
	(OCR0B = TCNT0 + QUANTUM_VALUE)
	
#define disable_quantum_timer() (TIMSK0 &= ~_BV(OCIE0B))
	
#define enable_quantum_timer()\
\
  restart_quantum_timer();\
  TIMSK0 |= _BV(OCIE0B); TCCR0B &= ~_BV(COM0B1)
  

#ifdef __AVR_HAVE_RAMPZ__
#define __PUSH_RAMPZ__\
	"\t in r24,__RAMPZ__"	"\n"\
	"\t push r24"		"\n"
  
#define __POP_RAMPZ__\
	"\t pop r24"		"\n"\
	"\t out __RAMPZ__,r24"	"\n"
#else
#define __PUSH_RAMPZ__
#define __POP_RAMPZ__
#endif

#ifdef __AVR_HAVE_RAMPY__
#define __PUSH_RAMPY__\
	"\t in r24,__RAMPY__"	"\n"\
	"\t push r24"		"\n"
  
#define __POP_RAMPY__\
	"\t pop r24"		"\n"\
	"\t out __RAMPY__,r24"	"\n"
#else
#define __PUSH_RAMPY__
#define __POP_RAMPY__
#endif

#ifdef __AVR_HAVE_RAMPX__
#define __PUSH_RAMPX__\
	"\t in r24,__RAMPX__"	"\n"\
	"\t push r24"		"\n"
  
#define __POP_RAMPX__\
	"\t pop r24"		"\n"\
	"\t out __RAMPX__,r24"	"\n"
#else
#define __PUSH_RAMPX__
#define __POP_RAMPX__
#endif

#ifdef __AVR_HAVE_RAMPD__
#define __PUSH_RAMPD__\
	"\t in r24,__RAMPD__"	"\n"\
	"\t push r24"		"\n"
  
#define __POP_RAMPD__\
	"\t pop r24"		"\n"\
	"\t out __RAMPD__,r24"	"\n"
#else
#define __PUSH_RAMPD__
#define __POP_RAMPD__
#endif  Serial.println("\nbegin\n");
  
__attribute__ ((signal, naked, used, externally_visible))
void QUANTUM_VECTOR (void)
{
  __asm__ (
	"\t push r0"		"\n"
	"\t in   r0,__SREG__"	"\n"
	"\t push r0"		"\n"
	"\t push r1"		"\n"
	"\t clr __zero_reg__"	"\n"
	"\t push r18"		"\n"
	"\t push r19"		"\n"
	"\t push r20"		"\n"
	"\t push r21"		"\n"
	"\t push r22"		"\n"
	"\t push r23"		"\n"
	"\t push r24"		"\n"
	"\t push r25"		"\n"
	"\t push r26"		"\n"
	"\t push r27"		"\n"
	"\t push r30"		"\n"
	"\t push r31"		"\n"
	__PUSH_RAMPD__
	__PUSH_RAMPX__
	__PUSH_RAMPY__
	__PUSH_RAMPZ__
	"\t rcall .L03"		"\n"
	"\t cli"		"\n"
);
        yield();

  __asm__ (
	__POP_RAMPZ__
	__POP_RAMPY__
	__POP_RAMPX__
	__POP_RAMPD__
	"\t pop r31"		"\n"
	"\t pop r30"		"\n"
	"\t pop r27"		"\n"
	"\t pop r26"		"\n"
	"\t pop r25"		"\n"
	"\t pop r24"		"\n"
	"\t pop r23"		"\n"
	"\t pop r22"		"\n"
	"\t pop r21"		"\n"
	"\t pop r20"		"\n"
	"\t pop r19"		"\n"
	"\t pop r18"		"\n"
	"\t pop r1"		"\n"
	"\t pop r0"		"\n"
	"\t out __SREG__,r0"	"\n"
	"\t pop r0"		"\n"
	"\t sei"		"\n"
	"\t ret"		"\n"
".L03:"				"\n"
	"\t reti"		"\n" 
);}


/* Hardware independent description */

typedef	struct ring_t {
	struct ring_t * next;	// next record into ring of threads
	jmp_buf    * context;	// the context stored in the local stack
	void (*__thread loop)(void); // start function of the thread
}
	__packed ring_t;


ring_t  main_thread = {&main_thread,NULL,NULL};
const void * MAIN   =  &main_thread+1;
void       * thread =  &main_thread+1;

static bool  yield_enable = false;

__stackup void spawn(void * state, void (*__thread start)(void))
{
	jmp_buf context; 
	enter_kernel_section();

// store return 
	((ring_t*)thread-1)->context = &context;
	
// insert new thread
  ((ring_t*)state-1)->loop = start;
  ((ring_t*)state-1)->next = ((ring_t*)thread-1)->next;
	((ring_t*)thread-1)->next = (ring_t*)state-1;
	thread = state;
  
// switch thread
	if (!setjmp(context))
	{
		set_stack_pointer((char*)((ring_t*)thread-1)-1);

// repeat always
		for (;;)
		{
			((ring_t*)thread-1)->loop();
			yield();
		}
	}
  
	restart_quantum_timer();
	leave_kernel_section();
	enable_interrupts();
}

void hold(void)
{
	yield_enable = false;
	disable_quantum_timer();
}

void schedule(void)
{
	yield_enable = true;
}

void quantize(void)
{
	schedule();
	enable_quantum_timer();
}

void yield(void)
{
	jmp_buf context;

	if (!yield_enable) return;
	enter_kernel_section();

// change to next 
	((ring_t*)thread-1)->context = &context;
	thread = ((ring_t*)thread-1)->next + 1; 

// switch context
	if (!setjmp(context)) 
		longjmp(*((ring_t*)thread-1)->context, 0);

	restart_quantum_timer();
	leave_kernel_section();
}

bool grab(void ** barrier, unsigned long timeout)
{
	unsigned long starttime;
	enter_kernel_section();
	
	starttime = millis();
	
	while (*barrier != NULL && *barrier != thread) 
	{
		yield();
		if (millis() - starttime > timeout) 
		{
			leave_kernel_section();
			return false;
		}
	}
	*barrier = thread;
	
	leave_kernel_section();
	return true;
}

bool loose(void ** barrier)
{
	enter_kernel_section();
	
	if (*barrier == thread || *barrier == NULL)
	{
		*barrier = NULL;
		leave_kernel_section();
		return true;
	}
	
	leave_kernel_section();
	return	false;
}


