/*
 * board.h - CC3100 boosterpack configuration
 *
 * Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#ifndef _BOARD_H
#define _BOARD_H

#ifdef __cplusplus
extern "C" {
#endif

/*!
    \brief  type definition for the host interrupt handler

    \param  pValue  -   pointer to any memory strcuture. The value of this pointer is given on
                        registration of a new interrupt handler

    \note
*/
typedef void (*SL_P_EVENT_HANDLER)(void);

#define P_EVENT_HANDLER SL_P_EVENT_HANDLER

/*!
    \brief register an interrupt handler for the host IRQ

    \param[in]      InterruptHdl    -    pointer to interrupt handler function

    \param[in]      pValue          -    pointer to a memory strcuture that is
                    passed to the interrupt handler.

    \return         upon successful registration, the function shall return 0.
                    Otherwise, -1 shall be returned

    \sa
    \note           If there is already registered interrupt handler, the
                    function should overwrite the old handler with the new one

    \warning
*/
int osi_RegisterInterruptHandler(P_EVENT_HANDLER InterruptHdl , void *pValue);


/*!
    \brief             Enables the CC3100

    \param[in]         none

    \return            none

    \note

    \warning
*/
void CC3100_enable();

/*!
    \brief             Disables the CC3100

    \param[in]         none

    \return            none

    \note

    \warning
*/
void CC3100_disable();

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif
