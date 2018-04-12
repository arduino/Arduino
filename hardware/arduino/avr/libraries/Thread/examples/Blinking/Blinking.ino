/*****************************************************************************
 *                 Simplest kernel for iterative multithtreading             *
 *                 Autor: Vyacheslav Azarov <slavaza63@gmail.com>            *
 *                  Licensed by GNU GPL V3 from 29 June 2007                 *
 * ***************************************************************************/
 #include <Arduino.h>
 #include "Thread.h"

// data structure of the thread
typedef struct data_type {
      String title;
      long   pause;
}
      data_type;
      
// state structure of the thread
typedef struct state_type {
      char stack[500];
      data_type data;
}
    state_type;

// static allocate the state variables
state_type state1, state2;

// sync barier for sharing the printer
void * mutex_serial = NULL;

__attribute__((OS_task)) void thread_loop(void);

void setup(void)
{
  Serial.begin(9600);

// need to enable for spawn call
  schedule();

// spawn the flow 1
  state1.data.title = "thread 1";
  state1.data.pause = 500;
  spawn(&state1.data, &thread_loop);

// spawn the flow 2
  state2.data.title = "thread 2";
  state2.data.pause = 510;
  spawn(&state2.data, &thread_loop);

// enable time division flow quantization
  quantize();
}

/* Primary thread */
void loop(void)
{
  yield();
}

/* Reentrant script */
void thread_loop(void)
{
    if (thread == MAIN)
    {
      // blocked execution 
      hold();
      Serial.println("impossible to call");
      Serial.flush();
      quantize();
      return;
    }
    
  // try get printer to privileged using
    while (!grab(&mutex_serial, 1000))
    {
      hold();
      Serial.println("grab timeout elapsed");
      quantize();
    }

  // unblocked reentrant functionality
		Serial.println(((data_type*)thread)->title);

    Serial.flush();

    if (!loose(&mutex_serial))
    {
      hold();
      Serial.println("strange mutex behavior");
      Serial.flush();
      quantize();
    }

    // unblocked delay
    delay(((data_type*)thread)->pause);

    // blink interference
    digitalWrite(LED_BUILTIN, thread == &state2.data ? HIGH: LOW);
}
/* End */


