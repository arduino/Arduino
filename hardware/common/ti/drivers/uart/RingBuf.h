/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ti_drivers_uart_RingBuf__include
#define ti_drivers_uart_RingBuf__include

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ti_drivers_uart_RingBuf_DEBUG

typedef unsigned char RingBuf_BufType;

typedef struct RingBuf_Object {
    RingBuf_BufType    *buffer;
    size_t              length;
    size_t              count;
    size_t              head;
    size_t              tail;
#ifdef ti_drivers_uart_RingBuf_DEBUG
    size_t              maxCount;
#endif
} RingBuf_Object, *RingBuf_Handle;

/*!
 *  \brief  Initialize circular buffer
 *
 *  \object Pointer to a RingBuf Object that contains the member variables to
 *          operate a circular buffer.
 *
 *  \bufPtr Pointer to data buffer to be used for the circular buffer. The
 *          buffer is NOT stored in RingBuf_Object.
 *
 *  \bufSize The size of bufPtr in number of elements of size RingBuf_BufType
 */
void RingBuf_init(RingBuf_Handle object,
                  RingBuf_BufType *bufPtr,
                  size_t bufSize);

/*!
 *  \brief  Put an element of size RingBuf_BufType into the end of the circular
 *          buffer.
 *
 *  \object Pointer to a RingBuf Object that contains the member variables to
 *          operate a circular buffer.
 *
 *  \data   RingBuf_BufType element to be placed at the end of the circular
 *          buffer.
 *
 *  \return Number of elements on the buffer after adding the element, or -1 if
 *          its full.
 */
int RingBuf_put(RingBuf_Handle object,
                RingBuf_BufType data);

/*!
 *  \brief  Get an element of size RingBuf_BufType into the end of the circular
 *          buffer and remove it.
 *
 *  \object Pointer to a RingBuf Object that contains the member variables to
 *          operate a circular buffer.
 *
 *  \data   Pointer to a element of type RingBuf_BufType to be filled with the
 *          data from the front of the circular buffer.
 *
 *  \return Number of elements on the buffer after taking the element out. If
 *          it return -1, the ringBuffer was empty and data is invalid.
 */
int RingBuf_get(RingBuf_Handle object,
                RingBuf_BufType *data);

/*!
 *  \brief  Get the count of elements on the circular buffer and retrieves the
 *          1st data element without removing it.
 *
 *  \object Pointer to a RingBuf Object that contains the member variables to
 *          operate a circular buffer.
 *
 *  \data   Pointer to a element of type RingBuf_BufType to be filled with the
 *          data from the front of the circular buffer. This function does not
 *          remove the data from the circular buffer. Do not evaluate data if
 *          the count returned is equal to 0.
 *
 *  \return Number of elements on the circular buffer. If the number != 0, then
 *          data will contain the first data element of the circular buffer.
 */
int RingBuf_getCount(RingBuf_Handle object,
                     RingBuf_BufType *data);

/*!
 *  \brief  Get the count of elements on the circular buffer.
 *
 *  \object Pointer to a RingBuf Object that contains the member variables to
 *          operate a circular buffer.
 *
 *  \return True if ring buffer is full, else false.
 */
bool RingBuf_isFull(RingBuf_Handle object);

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_RingBuf__include */
