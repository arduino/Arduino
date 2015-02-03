/*****************************************************************************
*
*  osal.h  - CC3000 Host Driver Implementation.
*  Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
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
*****************************************************************************/
#ifndef __OSAL_H__
#define __OSAL_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef  __cplusplus
extern "C" {
#endif

//#ifdef MULTI_THREAD_SUPPORT
#include <osal/sys_bios/inc/os.h>

//*****************************************************************************
//
// Prototypes for the APIs.
//
//*****************************************************************************
#define MAX_LENGTH 15;

typedef unsigned char   uInt8;
typedef unsigned short  uInt16;
typedef unsigned long   uInt32;
typedef char            sInt8;
typedef short           sInt16;
typedef long            sInt32;

typedef void *          handle;

typedef void(*entry_func)(void *);

typedef enum ret_status{
    e_SUCCESS,
    e_FAILURE = -1
}e_ret_status;

typedef enum wait_flag{
    e_NO_WAIT,
    e_WAIT_FOREVER,
    e_WAIT_FOR_TIMEOUT
}e_wait_flag;

typedef enum sem_mode{
    e_MODE_COUNTING,
    e_MODE_BINARY
}e_sem_mode;

typedef struct thread_params{
    sInt8      *thread_name;
    uInt8       priority;
    uInt16      stack_size;

    entry_func  p_entry_function;
    handle      p_func_params;
    handle      p_stack_start;

    /* Extensible */

}s_thread_params;


/* TBD - Move to a different place */
#define MAX_NUM_OF_SOCKETS 4

typedef struct _wlan_socket_t
{
    int sd;
    long status;
    SemaphoreHandle sd_semaphore;
}wlan_socket_t;
/* TBD - Move to a different place */

/**
 * \brief allocate memory
 *
 * Function allocates size bytes of uninitialized memory, and returns a pointer to the allocated memory.\n
 * The allocated space is suitably aligned (after possible pointer coercion) for storage of any type of object.
 *
 * \param[in] size    number of memory bytes to allocate
 *
 * \return   On success return a pointer to the allocated space, on failure return null
 * \sa OS_free
 * \note
 *
 * \warning
 */
void * OS_malloc(uInt32 size);

/**
 * \brief free allocated memory
 *
 * Function causes the allocated memory referenced by ptr to
 *  be made available for future allocations.\n If ptr is
 * NULL, no action occurs.
 *
 *  \param[in] ptr   pointer to previously allocated memory
 *
 * \return   None
 *
 * \sa OS_malloc
 * \note
 *
 * \warning
 */
void OS_free(void * ptr);

/**
 * \brief creates a mutex for inter-thread mutual exclusion for resource protection
 *
 *
 *
 *  \param[in] p_handle     Handle to a mutex control block
 *  \param[in] p_name       Name of mutex
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_mutex_delete, OS_mutex_lock, OS_mutex_unlock
 * \note
 *
 * \warning
 */
e_ret_status OS_mutex_create(handle p_handle, const void *const p_name);

/**
 * \brief delete mutex object
 *
 * Deletes the specified mutex.
 * All threads suspended waiting for the mutex are resumed and given a TX_DELETED return status
 *
 * \param[in] p_handle      Handle to a mutex control block
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_mutex_create, OS_mutex_lock, OS_mutex_unlock
 * \note
 *
 * \warning
 */
e_ret_status OS_mutex_delete(handle p_handle);

/**
 * \brief try to obtain the exclusive ownership on the mutex
 *
 * Attempts to obtain exclusive ownership of the specified mutex.
 * If the calling thread already owns the mutex, an internal counter is incremented
 * and a successful status is returned.
 *
 * \param[in] p_handle      Handle to a mutex control block
 * \param[in] p_handle      Key for nested mutex (SYS/BIOS)
 *                          If OS doesnt support, assign -1 to it in your implementation
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_mutex_create, OS_mutex_delete, OS_mutex_unlock
 * \note
 *
 * \warning
 */
e_ret_status OS_mutex_lock(handle p_handle, handle p_key);

/**
 * \brief delete mutex object
 *
 * decrements the ownership count of the specified mutex.
 * If the ownership count is zero, the mutex is made available
 *
 * \param[in] mutex_ptr  Pointer to a mutex control block
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_mutex_create, OS_mutex_lock, OS_mutex_delete
 * \note
 *
 * \warning
 */
e_ret_status OS_mutex_unlock(handle p_handle, sInt32 key);

/**
 * \brief create semaphore object
 *
 * Creates a counting semaphore for inter-thread synchronization.
 * The initial semaphore count is specified as an input parameter.
 *
 * \param[in] p_sem_handle      Handle to semaphore control block
 * \param[in] p_name            Name of the semaphore - UNUSED in SYS/BIOS
 * \param[in] count             Initial count of the semaphore
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_semaphore_delete, OS_semaphore_put, OS_semaphore_get
 * \note
 *
 * \warning
 */
e_ret_status OS_semaphore_create(handle p_sem_handle, const void *const p_name, uInt16 mode, uInt16 count);

/**
 * \brief delete semaphore object
 *
 * Deletes the specified counting semaphore.
 *
 * \param[in] p_sem_handle      Handle to semaphore control block
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_semaphore_create, semaphore_put, OS_semaphore_get
 * \note
 *
 * \warning
 */
e_ret_status OS_semaphore_delete(handle p_sem_handle);

/**
 * \brief decrease semaphore object counter
 *
 * retrieves an instance (a single count) from the specified counting semaphore.
 * As a result, the specified semaphore’s count is decreased by one
 *
 * \param[in] p_sem_handle      Handle to semaphore control block
 * \param[in] time_out          Timeout value - Can also take e_NO_WAIT or e_WAIT_FOREVER
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_semaphore_delete, OS_semaphore_put, OS_semaphore_create
 * \note
 *
 * \warning
 */
e_ret_status OS_semaphore_pend(handle p_sem_handle,
                               uInt32 timeout);

/**
 * \brief increase semaphore object count
 *
 * puts an instance into the specified counting semaphore,
 * which in reality increments the counting semaphore by one
 *
 * \param[in] p_sem_handle      Handle to semaphore control block
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_semaphore_delete, OS_semaphore_create, OS_semaphore_get
 * \note
 *
 * \warning
 */
e_ret_status OS_semaphore_post(handle p_sem_handle);

/**
 * \brief create and run a new thread
 *
 * creates an application thread that starts execution at the specified task entry function.
 * The stack and priority, are among the attributes specified by the input parameters.
 * In addition, the initial execution state of the thread is set to start running immediately after the thead is created
 *
 *  \param[in] p_handle     Handle to a thread control block
 *  \param[in] p_params     Thread params - Memory to be freed by caller
 *                              stackSize = Size of stack
 *                              priority = Task's priority (Order specific to OS)
 *                              p_entry_function = Task's entry function
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_thread_delete, OS_thread_terminate, OS_thread_sleep
 * \note
 *
 * \warning
 */
e_ret_status OS_thread_create(handle p_handle,
                              s_thread_params *p_params);

/**
 * \brief terminates a thread
 *
 * terminates the specified application thread regardless of whether the thread is suspended or not.
 * A thread may call this service to terminate itself.
 * Once terminated, the thread must be deleted and re-created in order for it to execute again
 *
 * \param[in] p_handle     Handle to a thread control block
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_thread_create, OS_thread_delete, OS_thread_sleep
 * \note
 *
 * \warning
 */
e_ret_status OS_thread_terminate(handle p_handle);

/**
 * \brief delete a thread
 *
 * deletes the specified application thread. Since the specified thread must be in a
 * terminated or completed state, this service cannot be called from a thread attempting to delete itself.
 * It is the application’s responsibility to manage the memory area associated
 * with the thread’s stack, which is available after this service completes.
 * In addition, the application must prevent use of a deleted thread
 *
 * \param[in] p_handle     Handle to a thread control block
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_thread_create, OS_thread_terminate, OS_thread_sleep
 * \note
 *
 * \warning
 */
e_ret_status OS_thread_delete(handle p_handle);

/**
 * \brief suspend the thread for limited time
 *
 * causes the calling thread to suspend for the specified number of timer ticks.
 * The amount of physical time associated with a timer tick is application specific.
 * This function can only be called only from an application thread
 *
 *  \param[in] ticks        The number of timer ticks to suspend the calling application thread,
 *                          ranging from 0 through 0xFFFFFFFF.
 *                          If 0 is specified, the service returns immediately.
 *
 * \return   e_SUCCESS on success, e_FAILURE on error
 *
 * \sa OS_threaad_create, OS_thread_delete, OS_thread_terminate
 * \note
 *
 * \warning
 */
e_ret_status OS_thread_sleep(uInt16 ticks);

/**
 * \brief start the system with a specific entry function
 *
 *
 *
 *  \param[in] entry_function
 *
 * \return 0 on success
 *
 * \sa
 * \note
 *
 * \warning
 */

//#endif //MULTI_THREAD_SUPPORT

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef  __cplusplus
}
#endif // __cplusplus

#endif // __OSAL_H__


