/**
 * @file - sys_arch.c
 * System Architecture support routines for TI Tiva devices.
 *
 */

/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

/* Copyright (c) 2008 Texas Instruments Incorporated */

/* lwIP includes. */
#include "lwip/opt.h"
#include "lwip/sys.h"

#if NO_SYS

#if SYS_LIGHTWEIGHT_PROT

/* TivaWare header files required for this interface driver. */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

/**
 * This global is defined in lwiplib.c and contains a count of the number of
 * elapsed milliseconds since lwIP started.
 */
extern uint32_t g_ui32LocalTimer;

/**
 * This function returns the system time in milliseconds.
 */
u32_t
sys_now(void)
{
    return(g_ui32LocalTimer);
}


/**
 * This function is used to lock access to critical sections when lwipopt.h
 * defines SYS_LIGHTWEIGHT_PROT. It disables interrupts and returns a value
 * indicating the interrupt enable state when the function entered. This
 * value must be passed back on the matching call to sys_arch_unprotect().
 *
 * @return the interrupt level when the function was entered.
 */
sys_prot_t
sys_arch_protect(void)
{
  return((sys_prot_t)MAP_IntMasterDisable());
}

/**
 * This function is used to unlock access to critical sections when lwipopt.h
 * defines SYS_LIGHTWEIGHT_PROT. It enables interrupts if the value of the lev
 * parameter indicates that they were enabled when the matching call to
 * sys_arch_protect() was made.
 *
 * @param lev is the interrupt level when the matching protect function was
 * called
 */
void
sys_arch_unprotect(sys_prot_t lev)
{
  /* Only turn interrupts back on if they were originally on when the matching
     sys_arch_protect() call was made. */
  if(!(lev & 1)) {
    MAP_IntMasterEnable();
  }
}
#endif /* SYS_LIGHTWEIGHT_PROT */

#else /* NO_SYS */

/* A structure to contain the variables for a sys_thread_t. */
typedef struct {
  void *stackstart;
  void *stackend;
  void (*thread)(void *arg);
  void *arg;
#if RTOS_FREERTOS
  xTaskHandle taskhandle;
#endif /* RTOS_FREERTOS */
} thread_t;

/* Provide a default maximum number of threads. */
#ifndef SYS_THREAD_MAX
#define SYS_THREAD_MAX          4
#endif /* SYS_THREAD_MAX */

/* Provide a default maximum number of semaphores. */
#ifndef SYS_SEM_MAX
#define SYS_SEM_MAX             4
#endif /* SYS_SEM_MAX */

/* Provide a default maximum number of mailboxes. */
#ifndef SYS_MBOX_MAX
#define SYS_MBOX_MAX            4
#endif /* SYS_MBOX_MAX */

/* An array to hold the memory for the available semaphores. */
static sem_t sems[SYS_SEM_MAX];

/* An array to hold the memory for the available mailboxes. */
static mbox_t mboxes[SYS_MBOX_MAX];

/* An array to hold the memory for the available threads. */
static thread_t threads[SYS_THREAD_MAX];

/**
 * Initializes the system architecture layer.
 *
 */
void
sys_init(void)
{
  u32_t i;

  /* Clear out the mailboxes. */
  for(i = 0; i < SYS_MBOX_MAX; i++) {
    mboxes[i].queue = 0;
  }

  /* Clear out the semaphores. */
  for(i = 0; i < SYS_SEM_MAX; i++) {
    sems[i].queue = 0;
  }

  /* Clear out the threads. */
  for(i = 0; i < SYS_THREAD_MAX; i++) {
    threads[i].stackstart = NULL;
    threads[i].stackend = NULL;
  }
}

/**
 * Creates a new semaphore.
 *
 * @param count is non-zero if the semaphore should be acquired initially.
 * @return the handle of the created semaphore.
 */
err_t
sys_sem_new(sys_sem_t *sem, u8_t count)
{
  void *temp;
  u32_t i;

  /* Find a semaphore that is not in use. */
  for(i = 0; i < SYS_SEM_MAX; i++) {
    if(sems[i].queue == 0) {
      break;
    }
  }
  if(i == SYS_SEM_MAX) {
#if SYS_STATS
    STATS_INC(sys.sem.err);
#endif /* SYS_STATS */
    return ERR_MEM;
  }

  /* Create a single-entry queue to act as a semaphore. */
#if RTOS_FREERTOS
  sem->queue = xQueueCreate(1, sizeof(void *));
  if(sem->queue == NULL) {
#endif /* RTOS_FREERTOS */

#if SYS_STATS
    STATS_INC(sys.sem.err);
#endif /* SYS_STATS */
    return ERR_MEM;
  }

  /* Acquired the semaphore if necessary. */
  if(count == 0) {
    temp = 0;
    xQueueSend(sem->queue, &temp, 0);
  }

  /* Update the semaphore statistics. */
#if SYS_STATS
  STATS_INC(sys.sem.used);
#if LWIP_STATS
  if(lwip_stats.sys.sem.max < lwip_stats.sys.sem.used) {
    lwip_stats.sys.sem.max = lwip_stats.sys.sem.used;
  }
#endif
#endif /* SYS_STATS */

  /* Save the queue handle. */
  sems[i].queue = sem->queue;

  /* Return this semaphore. */
  return (ERR_OK);
}

/**
 * Signal a semaphore.
 *
 * @param sem is the semaphore to signal.
 */
void
sys_sem_signal(sys_sem_t *sem)
{
  void *msg;

  /* Receive a message from the semaphore's queue. */
  xQueueReceive(sem->queue, &msg, 0);
}

/**
 * Wait for a semaphore to be signalled.
 *
 * @param sem is the semaphore
 * @param timeout is the maximum number of milliseconds to wait for the
 *        semaphore to be signalled
 * @return the number of milliseconds that passed before the semaphore was
 *         acquired, or SYS_ARCH_TIMEOUT if the timeout occurred
 */
u32_t
sys_arch_sem_wait(sys_sem_t *sem, u32_t timeout)
{
  portTickType starttime;
  void *msg = 0;

  /* Get the starting time. */
  starttime = xTaskGetTickCount();

  /* See if there is a timeout. */
  if(timeout != 0) {
    /* Send a message to the queue. */
    if(xQueueSend(sem->queue, &msg, timeout / portTICK_RATE_MS) == pdPASS) {
      /* Return the amount of time it took for the semaphore to be
         signalled. */
      return (xTaskGetTickCount() - starttime) * portTICK_RATE_MS;
    } else {
      /* The semaphore failed to signal in the allotted time. */
      return SYS_ARCH_TIMEOUT;
    }
  } else {
    /* Try to send a message to the queue until it succeeds. */
    while(xQueueSend(sem->queue, &msg, portMAX_DELAY) != pdPASS);

    /* Return the amount of time it took for the semaphore to be signalled. */
    return (xTaskGetTickCount() - starttime) * portTICK_RATE_MS;
  }
}

/**
 * Destroys a semaphore.
 *
 * @param sem is the semaphore to be destroyed.
 */
void
sys_sem_free(sys_sem_t *sem)
{
  /* Clear the queue handle. */
  sem->queue = 0;

  /* Update the semaphore statistics. */
#if SYS_STATS
  STATS_DEC(sys.sem.used);
#endif /* SYS_STATS */
}

/**
 * Creates a new mailbox.
 *
 * @param size is the number of entries in the mailbox.
 * @return the handle of the created mailbox.
 */
err_t
sys_mbox_new(sys_mbox_t *mbox, int size)
{
  u32_t i;

  /* Fail if the mailbox size is too large. */
  if(size > MBOX_MAX) {
#if SYS_STATS
    STATS_INC(sys.mbox.err);
#endif /* SYS_STATS */
    return ERR_MEM;
  }

  /* Find a mailbox that is not in use. */
  for(i = 0; i < SYS_MBOX_MAX; i++) {
    if(mboxes[i].queue == 0) {
      break;
    }
  }
  if(i == SYS_MBOX_MAX) {
#if SYS_STATS
    STATS_INC(sys.mbox.err);
#endif /* SYS_STATS */
    return ERR_MEM;
  }

#if RTOS_FREERTOS
  /* Create a queue for this mailbox. */
  mbox->queue = xQueueCreate(size, sizeof(void *));
  if(mbox == NULL) {
#endif /* RTOS_FREERTOS */

#if SYS_STATS
    STATS_INC(sys.mbox.err);
#endif /* SYS_STATS */
    return ERR_MEM;
  }

  /* Update the mailbox statistics. */
#if SYS_STATS
  STATS_INC(sys.mbox.used);
#if LWIP_STATS
  if(lwip_stats.sys.mbox.max < lwip_stats.sys.mbox.used) {
    lwip_stats.sys.mbox.max = lwip_stats.sys.mbox.used;
  }
#endif
#endif /* SYS_STATS */

  /* Save the queue handle. */
  mboxes[i].queue = mbox->queue;

  /* Return this mailbox. */
  return ERR_OK;
}

/**
 * Sends a message to a mailbox.
 *
 * @param mbox is the mailbox
 * @param msg is the message to send
 */
void
sys_mbox_post(sys_mbox_t *mbox, void *msg)
{
  /* Send this message to the queue. */
  while(xQueueSend(mbox->queue, &msg, portMAX_DELAY) != pdPASS);
}

/**
 * Tries to send a message to a mailbox.
 *
 * @param mbox is the mailbox
 * @param msg is the message to send
 * @return ERR_OK if the message was sent and ERR_MEM if there was no space for
 *         the message
 */
err_t
sys_mbox_trypost(sys_mbox_t *mbox, void *msg)
{
  /* Send this message to the queue. */
  if(xQueueSend(mbox->queue, &msg, 0) == pdPASS) {
    return ERR_OK;
  }

  /* Update the mailbox statistics. */
#if SYS_STATS
  STATS_INC(sys.mbox.err);
#endif /* SYS_STATS */

  /* The message could not be sent. */
  return ERR_MEM;
}

/**
 * Retrieve a message from a mailbox.
 *
 * @param mbox is the mailbox
 * @param msg is a pointer to the location to receive the message
 * @param timeout is the maximum number of milliseconds to wait for the message
 * @return the number of milliseconds that passed before the message was
 *         received, or SYS_ARCH_TIMEOUT if the tmieout occurred
 */
u32_t
sys_arch_mbox_fetch(sys_mbox_t *mbox, void **msg, u32_t timeout)
{
  portTickType starttime;
  void *dummyptr;

  /* If the actual message contents are not required, provide a local variable
     to recieve the message. */
  if(msg == NULL) {
    msg = &dummyptr;
  }

  /* Get the starting time. */
  starttime = xTaskGetTickCount();

  /* See if there is a timeout. */
  if(timeout != 0) {
    /* Receive a message from the queue. */
    if(xQueueReceive(mbox->queue, msg, timeout / portTICK_RATE_MS) == pdPASS) {
      /* Return the amount of time it took for the message to be received. */
      return (xTaskGetTickCount() - starttime) * portTICK_RATE_MS;
    } else {
      /* No message arrived in the allotted time. */
      *msg = NULL;
      return SYS_ARCH_TIMEOUT;
    }
  } else {
    /* Try to receive a message until one arrives. */
    while(xQueueReceive(mbox->queue, msg, portMAX_DELAY) != pdPASS);

    /* Return the amount of time it took for the message to be received. */
    return (xTaskGetTickCount() - starttime) * portTICK_RATE_MS;
  }
}

/**
 * Try to receive a message from a mailbox, returning immediately if one is not
 * available.
 *
 * @param mbox is the mailbox
 * @param msg is a pointer to the location to receive the message
 * @return ERR_OK if a message was available and SYS_MBOX_EMPTY if one was not
 *         available
 */
u32_t
sys_arch_mbox_tryfetch(sys_mbox_t *mbox, void **msg)
{
  void *dummyptr;

  /* If the actual message contents are not required, provide a local variable
     to recieve the message. */
  if(msg == NULL) {
    msg = &dummyptr;
  }

  /* Recieve a message from the queue. */
  if(xQueueReceive(mbox->queue, msg, 0) == pdPASS) {
    /* A message was available. */
    return ERR_OK;
  } else {
    /* A message was not available. */
    return SYS_MBOX_EMPTY;
  }
}

/**
 * Destroys a mailbox.
 *
 * @param mbox is the mailbox to be destroyed.
 */
void
sys_mbox_free(sys_mbox_t *mbox)
{
  /* There should not be any messages waiting (if there are it is a bug).  If
     any are waiting, increment the mailbox error count. */
#if RTOS_FREERTOS
  if(uxQueueMessagesWaiting(mbox->queue) != 0) {
#endif /* RTOS_FREERTOS */

#if SYS_STATS
    STATS_INC(sys.mbox.err);
#endif /* SYS_STATS */
  }

  /* Clear the queue handle. */
  mbox->queue = 0;

  /* Update the mailbox statistics. */
#if SYS_STATS
   STATS_DEC(sys.mbox.used);
#endif /* SYS_STATS */
}

/**
 * Checks the validity of a mailbox.
 *
 * @param mbox is the mailbox whose validity is to be checked.
 */
int
sys_mbox_valid(sys_mbox_t *mbox)
{
  /*Check if a mailbox has been created*/
  if(mbox->queue == SYS_MBOX_NULL){
      return 0;
  }
  else{
      return 1;
  }
}

/**
 * The routine for a thread.  This handles some housekeeping around the
 * applications's thread routine.
 *
 * @param arg is the index into the thread structure for this thread
 */
static void
sys_arch_thread(void *arg)
{
  u32_t i;

  /* Get this threads index. */
  i = (u32_t)arg;

  /* Call the application's thread routine. */
  threads[i].thread(threads[i].arg);

  /* Free the memory used by this thread's stack. */
  mem_free(threads[i].stackstart);

  /* Clear the stack from the thread structure. */
  threads[i].stackstart = NULL;
  threads[i].stackend = NULL;

  /* Delete this task. */
#if RTOS_FREERTOS
  vTaskDelete(NULL);
#endif
}

/**
 * Creates a new thread.
 *
 * @param name is the name of this thread
 * @param thread is a pointer to the function to run in the new thread
 * @param arg is the argument to pass to the thread's function
 * @param stacksize is the size of the stack to allocate for this thread
 * @param prio is the priority of the new thread
 * @return the handle fo the created thread
 */
sys_thread_t
sys_thread_new(const char *name, lwip_thread_fn thread, void *arg,
               int stacksize, int prio)
{
  sys_thread_t created_thread;
  void *data;
  u32_t i;

  /* Find a thread that is not in use. */
  for(i = 0; i < SYS_THREAD_MAX; i++) {
    if(threads[i].stackstart == NULL) {
      break;
    }
  }
  if(i == SYS_THREAD_MAX) {
      return NULL;
  }

  /* Allocate memory for the thread's stack. */
  data = mem_malloc(stacksize);
  if(!data) {
    return NULL;
  }

  /* Save the details of this thread. */
  threads[i].stackstart = data;
  threads[i].stackend = (void *)((char *)data + stacksize);
  threads[i].thread = thread;
  threads[i].arg = arg;

  /* Create a new thread. */
#if RTOS_FREERTOS
  if(xTaskCreate(sys_arch_thread, (signed portCHAR *)name,
                 stacksize/sizeof(int), (void *)i, tskIDLE_PRIORITY+prio,
                 &threads[i].taskhandle) != pdTRUE){
    threads[i].stackstart = NULL;
    threads[i].stackend = NULL;
    return NULL;
  }
  created_thread = threads[i].taskhandle;
#endif /* RTOS_FREERTOS */

  /* Return this thread. */
  return created_thread;
}

/**
 * Enters a critical section.
 *
 * @return the previous protection level
 */
sys_prot_t
sys_arch_protect(void)
{
#if RTOS_FREERTOS
  taskENTER_CRITICAL();
#endif

  return 1;
}

/**
 * Leaves a critical section.
 *
 * @param the preivous protection level
 */
void
sys_arch_unprotect(sys_prot_t val)
{
#if RTOS_FREERTOS
  taskEXIT_CRITICAL();
#endif
}

#endif /* NO_SYS */
