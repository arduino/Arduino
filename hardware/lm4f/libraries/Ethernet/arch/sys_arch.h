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
#ifndef __ARCH_SYS_ARCH_H__
#define __ARCH_SYS_ARCH_H__

#if RTOS_FREERTOS
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#define portQUEUE_OVERHEAD_BYTES 1  // Constant, used for consistency
#endif /* RTOS_FREERTOS */

/* Find the size of the largest required mbox. */
#define MAX1 ((TCPIP_MBOX_SIZE > DEFAULT_RAW_RECVMBOX_SIZE) ? \
              TCPIP_MBOX_SIZE : DEFAULT_RAW_RECVMBOX_SIZE)
#define MAX2 ((MAX1 > DEFAULT_UDP_RECVMBOX_SIZE) ? MAX1 : \
              DEFAULT_UDP_RECVMBOX_SIZE)
#define MAX3 ((MAX2 > DEFAULT_TCP_RECVMBOX_SIZE) ? MAX2 : \
              DEFAULT_TCP_RECVMBOX_SIZE)
#define MBOX_MAX ((MAX3 > DEFAULT_ACCEPTMBOX_SIZE) ? MAX3 : \
                  DEFAULT_ACCEPTMBOX_SIZE)

///* A structure to hold the variables for a sys_sem_t. */
typedef struct {
  xQueueHandle queue;
  signed char buffer[sizeof(void *) + portQUEUE_OVERHEAD_BYTES];
} sem_t;

/* A structure to hold the variables for a sys_mbox_t. */
typedef struct {
  xQueueHandle queue;
  signed char buffer[(sizeof(void *) * MBOX_MAX) + portQUEUE_OVERHEAD_BYTES];
} mbox_t;

/* Typedefs for the various port-specific types. */
typedef mbox_t sys_mbox_t;
typedef sem_t sys_sem_t;
typedef xTaskHandle sys_thread_t;

/* The value for an unallocated mbox. */
#define SYS_MBOX_NULL       0

#endif /* __ARCH_SYS_ARCH_H__ */

