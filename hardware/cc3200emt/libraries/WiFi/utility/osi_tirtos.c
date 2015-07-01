//*****************************************************************************
// osi_tirtos.c
//
// Interface APIs for TI-RTOS function calls
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
//
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions
//  are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Memory.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/family/arm/m3/Hwi.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Mailbox.h>

#include "osi.h"

//Local function definition
static void vSimpleLinkSpawnTask(void *pvParameters);

Mailbox_Handle simpleLink_mailbox;
Task_Handle SimpleLinkSpawnTaskHndl;

// Queue size
#define slQUEUE_SIZE     3

#define TICK_RATE_MS     (Clock_tickPeriod/1000)

/*!
	\brief 	This function registers an interrupt in NVIC table

	The sync object is used for synchronization between different thread or ISR and
	a thread.

	\param	iIntrNum	-	Interrupt number to register
	\param	pEntry	    -	Pointer to the interrupt handler
	\param ucPriority   -   Priority of the interrupt

	\return upon successful creation the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_InterruptRegister(int iIntrNum, P_OSI_INTR_ENTRY pEntry, unsigned char ucPriority)
{
    Error_Block eb;
    Hwi_Handle hHandle;
    Hwi_Params params;

	Error_init(&eb);
	Hwi_Params_init(&params);
	params.priority = (int)ucPriority;
    params.useDispatcher = (unsigned short)1;// Use the interrupt dispatcher with this interrupt


	osi_InterruptDeRegister(iIntrNum);

	Hwi_FuncPtr hwiFxn = (Hwi_FuncPtr)pEntry;
	hHandle = Hwi_create(iIntrNum, hwiFxn, (Hwi_Params*)&params, &eb);
	Hwi_setPriority(iIntrNum, ucPriority);
	if(hHandle != NULL)
		return OSI_OK;
	else
		return OSI_FAILURE;
}

/*!
	\brief 	This function De registers an interrupt in NVIC table

	\param	iIntrNum	-	Interrupt number to register

	\return none
	\note
	\warning
*/
void osi_InterruptDeRegister(int iIntrNum)
{
	Hwi_Handle hHandle = Hwi_getHandle(iIntrNum);
	if (hHandle)
	{
		Hwi_delete(&hHandle);
		hHandle = 0;
	}
}

/*!
	\brief 	This function creates a sync object

	The sync object is used for synchronization between different thread or ISR and
	a thread.

	\param	pSyncObj	-	pointer to the sync object control block

	\return upon successful creation the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_SyncObjCreate(OsiSyncObj_t *pSyncObj)
{
    Semaphore_Handle sem_handle;
    Semaphore_Params params;
	Error_Block eb;

	Error_init(&eb);
	Semaphore_Params_init(&params);
	params.mode = Semaphore_Mode_BINARY;

	sem_handle = Semaphore_create(1, &params, &eb);
	if (NULL == sem_handle)
	{
		*pSyncObj = NULL;
		return OSI_FAILURE;
	}

	*pSyncObj = (OsiSyncObj_t)sem_handle;

	osi_SyncObjClear(pSyncObj);
    return OSI_OK;
}

/*!
	\brief 	This function deletes a sync object

	\param	pSyncObj	-	pointer to the sync object control block

	\return upon successful deletion the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_SyncObjDelete(OsiSyncObj_t *pSyncObj)
{
     /* Semaphore_delete doesn't return the status */
    Semaphore_delete((Semaphore_Handle *)pSyncObj);
    return OSI_OK;
}

/*!
	\brief 		This function generates a sync signal for the object.

	All suspended threads waiting on this sync object are resumed

	\param		pSyncObj	-	pointer to the sync object control block

	\return 	upon successful signalling the function should return 0
				Otherwise, a negative value indicating the error code shall be returned
	\note		the function could called from ISR context
	\warning
*/
OsiReturnVal_e osi_SyncObjSignal(OsiSyncObj_t *pSyncObj)
{
    Semaphore_post((Semaphore_Handle)*pSyncObj);
    return OSI_OK; /* Semaphore_post doesn't return the status */
}

/*!
	\brief 		This function generates a sync signal for the object.
				from ISR context.

	All suspended threads waiting on this sync object are resumed

	\param		pSyncObj	-	pointer to the sync object control block

	\return 	upon successful signalling the function should return 0
				Otherwise, a negative value indicating the error code shall be returned
	\note		the function is be called from ISR context
	\warning
*/
OsiReturnVal_e osi_SyncObjSignalFromISR(OsiSyncObj_t *pSyncObj)
{
	Semaphore_post((Semaphore_Handle)*pSyncObj);
    return OSI_OK; /* Semaphore_post doesn't return the status */
}

/*!
	\brief 	This function waits for a sync signal of the specific sync object

	\param	pSyncObj	-	pointer to the sync object control block
	\param	Timeout		-	numeric value specifies the maximum number of mSec to
							stay suspended while waiting for the sync signal
							Currently, the simple link driver uses only two values:
								- OSI_WAIT_FOREVER
								- OSI_NO_WAIT

	\return upon successful reception of the signal within the timeout window return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_SyncObjWait(OsiSyncObj_t *pSyncObj, OsiTime_t Timeout)
{
    Bool ret_status;

	switch(Timeout)
	{
		case OSI_NO_WAIT:
		    Timeout = BIOS_NO_WAIT;
			break;
		case OSI_WAIT_FOREVER:
		    Timeout = BIOS_WAIT_FOREVER;
			break;
		default:
		    Timeout = Timeout/TICK_RATE_MS;
			break;
	}

	ret_status = Semaphore_pend((Semaphore_Handle)*pSyncObj, Timeout);
	if (TRUE != ret_status)
	{
		return OSI_FAILURE;
	}

    return OSI_OK;
}

/*!
	\brief 	This function clears a sync object

	\param	pSyncObj	-	pointer to the sync object control block

	\return upon successful clearing the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_SyncObjClear(OsiSyncObj_t* pSyncObj)
{
	if (osi_SyncObjWait(pSyncObj, 0) == OSI_OK )
    {
        return OSI_OK;
    }
    else
    {
        return OSI_FAILURE;
    }
}

/*!
	\brief 	This function creates a locking object.

	The locking object is used for protecting a shared resources between different
	threads.

	\param	pLockObj	-	pointer to the locking object control block

	\return upon successful creation the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_LockObjCreate(OsiLockObj_t *pLockObj)
{
    Semaphore_Handle sem_handle;
    Semaphore_Params params;
	Error_Block eb;

	Error_init(&eb);
	Semaphore_Params_init(&params);
	params.mode = Semaphore_Mode_BINARY;

	sem_handle = Semaphore_create(1, &params, &eb);
	if (NULL == sem_handle)
	{
		*pLockObj = (OsiLockObj_t)sem_handle;
		return OSI_FAILURE;
	}

    *pLockObj = (OsiLockObj_t)sem_handle;
    return OSI_OK;
}

/*!
	\brief 	This function creates a Task.

	Creates a new Task and add it to the last of tasks that are ready to run

	\param	pEntry	-	pointer to the Task Function
	\param	pcName	-	Task Name String
	\param	usStackDepth	-	Stack Size in bytes
	\param	pvParameters	-	pointer to structure to be passed to the Task Function
	\param	uxPriority	-	Task Priority

	\return upon successful creation the function should return 1
			Otherwise, 0 or a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_TaskCreate(P_OSI_TASK_ENTRY pEntry, const signed char * const pcName, unsigned short usStackDepth,
                   void *pvParameters, unsigned long uxPriority, OsiTaskHandle *pTaskHandle)
{
    Task_Handle tsk_handle = NULL;
    Task_Params taskParams;
    Error_Block eb;

    Error_init(&eb);

    Task_Params_init(&taskParams);
    taskParams.stackSize = usStackDepth; //Stack size needs to be given in Bytes for TI-RTOS
    taskParams.priority = uxPriority;
    taskParams.arg0 = (UArg)pvParameters;
    taskParams.instance->name = (xdc_String)pcName;

    tsk_handle = Task_create((Task_FuncPtr)pEntry, &taskParams, &eb);
    if(pTaskHandle != NULL)
    	*pTaskHandle = (OsiTaskHandle)tsk_handle;
    if (NULL == tsk_handle)
	{
 	   return OSI_FAILURE;
    }

    return OSI_OK;
}


/*!
	\brief 	This function Deletes a Task.

	Deletes a  Task and remove it from list of running task

	\param	pTaskHandle	-	Task Handle

	\note
	\warning
*/
void osi_TaskDelete(OsiTaskHandle* pTaskHandle)
{
	Task_delete((Task_Handle *)pTaskHandle);
}

/*!
	\brief 	This function deletes a locking object.

	\param	pLockObj	-	pointer to the locking object control block

	\return upon successful deletion the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_LockObjDelete(OsiLockObj_t *pLockObj)
{
     Semaphore_delete((Semaphore_Handle *)pLockObj);
     return OSI_OK;   /* Semaphore_delete doesn't return the status */
}

/*!
	\brief 	This function locks a locking object.

	All other threads that call this function before this thread calls
	the osi_LockObjUnlock would be suspended

	\param	pLockObj	-	pointer to the locking object control block
	\param	Timeout		-	numeric value specifies the maximum number of mSec to
							stay suspended while waiting for the locking object
							Currently, the simple link driver uses only two values:
								- OSI_WAIT_FOREVER
								- OSI_NO_WAIT


	\return upon successful reception of the locking object the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_LockObjLock(OsiLockObj_t *pLockObj , OsiTime_t Timeout)
{
    Bool ret_status;
	
	switch(Timeout)
	{
        case OSI_NO_WAIT:
            Timeout = BIOS_NO_WAIT;
            break;
        case OSI_WAIT_FOREVER:
            Timeout = BIOS_WAIT_FOREVER;
            break;
        default:
            Timeout = Timeout/TICK_RATE_MS;
            break;
    }
	
    ret_status = Semaphore_pend((Semaphore_Handle)*pLockObj, Timeout);
    if (TRUE != ret_status)
	{
        return OSI_FAILURE;
	}

    return OSI_OK;
}

/*!
	\brief 	This function unlock a locking object.

	\param	pLockObj	-	pointer to the locking object control block

	\return upon successful unlocking the function should return 0
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/
OsiReturnVal_e osi_LockObjUnlock(OsiLockObj_t *pLockObj)
{
    Semaphore_post((Semaphore_Handle)*pLockObj);
    return OSI_OK; /* Semaphore_post doesn't return the status */
}


/*!
	\brief 	This function call the pEntry callback from a different context

	\param	pEntry		-	pointer to the entry callback function

	\param	pValue		- 	pointer to any type of memory structure that would be
							passed to pEntry callback from the execution thread.

	\param	flags		- 	execution flags - reserved for future usage

	\return upon successful registration of the spawn the function should return 0
			(the function is not blocked till the end of the execution of the function
			and could be returned before the execution is actually completed)
			Otherwise, a negative value indicating the error code shall be returned
	\note
	\warning
*/

OsiReturnVal_e osi_Spawn(P_OSI_SPAWN_ENTRY pEntry, void *pValue, unsigned long flags)
{
    tSimpleLinkSpawnMsg Msg;
	Bool ret_status;

    Msg.pEntry = pEntry;
    Msg.pValue = pValue;
    
	//  Mailbox is copy based so using a stack variable is ok
    ret_status = Mailbox_post(simpleLink_mailbox, &Msg, BIOS_NO_WAIT);
    if (TRUE != ret_status)
	{
        return OSI_FAILURE;
	}

    return OSI_OK;
}

/*!
	\brief 	This is the simplelink spawn task to call SL callback from a different context

	\param	pvParameters		-	pointer to the task parameter

	\return void
	\note
	\warning
*/
void vSimpleLinkSpawnTask(void *pvParameters)
{
    tSimpleLinkSpawnMsg Msg;

    for(;;)
    {
    	Mailbox_pend(simpleLink_mailbox, &Msg, BIOS_WAIT_FOREVER);
    	Msg.pEntry(Msg.pValue);
    }
}

/*!
	\brief 	This is the API to create SL spawn task and create the SL queue

	\param	uxPriority		-	task priority

	\return void
	\note
	\warning
*/
OsiReturnVal_e VStartSimpleLinkSpawnTask(unsigned long uxPriority)
{
    Task_Handle tsk_handle = NULL;
    Task_Params taskParams;
	Error_Block eb;

	Error_init(&eb);

	simpleLink_mailbox = Mailbox_create(sizeof(tSimpleLinkSpawnMsg), slQUEUE_SIZE, NULL, &eb);

	Task_Params_init(&taskParams);
	taskParams.stackSize = 2048;
	taskParams.priority = uxPriority;
    taskParams.instance->name = "SimpleLinkTask";
	tsk_handle = Task_create((Task_FuncPtr)vSimpleLinkSpawnTask, &taskParams, &eb);
	SimpleLinkSpawnTaskHndl = tsk_handle;
	if (NULL == tsk_handle)
	{
		Mailbox_delete(&simpleLink_mailbox);
   	}
	return OSI_OK;
}

/*!
	\brief 	This is the API to delete SL spawn task and delete the SL queue

	\param	none

	\return void
	\note
	\warning
*/
void VDeleteSimpleLinkSpawnTask( void )
{
    Task_delete( &SimpleLinkSpawnTaskHndl );
    Mailbox_delete(&simpleLink_mailbox);
}

/*!
	\brief 	This function to call the memory allocation function of the RTOS

	\param	pMem		-	pointer to the memory which needs to be freed

	\return - void *
	\note
	\warning
*/

void * mem_Malloc(unsigned long Size)
{
	return ( void * )malloc(Size);
}

/*!
	\brief 	This function to call the memory de-allocation function of the RTOS

	\param	pMem		-	pointer to the memory which needs to be freed

	\return - void
	\note
	\warning
*/
void mem_Free(void *pMem)
{
	free(pMem);
}

/*!
	\brief 	This function call the memset function
	\param	pBuf		-	pointer to the memory to be fill
    \param Val          -       Value to be fill
    \param Size         -      Size of the memory which needs to be fill

	\return - void
	\note
	\warning
*/

void mem_set(void *pBuf, int Val, size_t Size)
{
    memset(pBuf, Val, Size);
}

/*!
	\brief 	This function call the memset function
	\param	pDst		-	pointer to the destination
    \param pSrc         -   pointer to the source
    \param Size         -   Size of the memory which needs to be copy

	\return - void
	\note
	\warning
*/
void mem_copy(void *pDst, void *pSrc, size_t Size)
{
    memcpy(pDst, pSrc, Size);
}


/*!
	\brief 	This function use to entering into critical section
	\param	void
	\return - void
	\note
	\warning
*/

unsigned long osi_EnterCritical(void)
{
	unsigned long ulKey;
	ulKey = Hwi_disable();
	return ulKey;
}

/*!
	\brief 	This function use to exit critical section
	\param	void
	\return - void
	\note
	\warning
*/

void osi_ExitCritical(unsigned long ulKey)
{
    Hwi_restore(ulKey);
}

/*!
	\brief 	This function used to create a message queue
	\param	pMsgQ	 	- pointer to the message queue
	\param	pMsgQName	- Name of the Message queue
	\param	MsgSize		- Size of msg on the message queue
	\param	MaxMsgs		- Max number of msgs on the queue
	\return - OsiReturnVal_e
	\note
	\warning
*/
OsiReturnVal_e osi_MsgQCreate(OsiMsgQ_t     *pMsgQ,
                              char          *pMsgQName,
                              unsigned long  MsgSize,
                              unsigned long  MaxMsgs)
{
    Error_Block eb;

	Error_init(&eb);
	*pMsgQ = (OsiMsgQ_t)Mailbox_create(MsgSize, MaxMsgs, NULL, &eb);
    if (*pMsgQ == NULL)
    {
        return OSI_OPERATION_FAILED;
    }
    return OSI_OK;
}
/*!
	\brief 	This function used to delete a message queue
	\param	pMsgQ	-	pointer to the msg queue
	\return - OsiReturnVal_e
	\note
	\warning
*/
OsiReturnVal_e osi_MsgQDelete(OsiMsgQ_t *pMsgQ)
{

	Mailbox_delete((Mailbox_Handle *)pMsgQ);
	return OSI_OK;
}

/*!
	\brief 	This function is used to write data to the MsgQ

	\param	pMsgQ	-	pointer to the message queue
	\param	pMsg	-	pointer to the Msg strut to read into
	\param	Timeout	-	timeout to wait for the Msg to be available

	\return - OsiReturnVal_e
	\note
	\warning
*/
OsiReturnVal_e osi_MsgQWrite(OsiMsgQ_t *pMsgQ, void *pMsg, OsiTime_t Timeout)
{
    Bool ret_status;

    switch(Timeout)
	{
		case OSI_NO_WAIT:
		    Timeout = BIOS_NO_WAIT;
			break;
		case OSI_WAIT_FOREVER:
		    Timeout = BIOS_WAIT_FOREVER;
			break;
		default:
		    Timeout = Timeout/TICK_RATE_MS;
			break;
	}    
	
    ret_status = Mailbox_post((Mailbox_Handle)*pMsgQ, pMsg, Timeout);
    Task_yield();
    if (TRUE != ret_status)
	{
        return OSI_OPERATION_FAILED;
	}
    
	return OSI_OK;
}

/*!
	\brief 	This function is used to read data from the MsgQ

	\param	pMsgQ	-	pointer to the message queue
	\param	pMsg	-	pointer to the Msg strut to read into
	\param	Timeout	-	timeout to wait for the Msg to be available

	\return - OsiReturnVal_e
	\note
	\warning
*/
OsiReturnVal_e osi_MsgQRead(OsiMsgQ_t* pMsgQ, void* pMsg , OsiTime_t Timeout)
{
    Bool ret_status;
    
    switch(Timeout)
	{
		case OSI_NO_WAIT:
		    Timeout = BIOS_NO_WAIT;
			break;
		case OSI_WAIT_FOREVER:
		    Timeout = BIOS_WAIT_FOREVER;
			break;
		default:
		    Timeout = Timeout/TICK_RATE_MS;
			break;
	}    
	
    ret_status = Mailbox_pend((Mailbox_Handle)*pMsgQ, pMsg, Timeout);
    if (TRUE != ret_status)
	{
        return OSI_OPERATION_FAILED;
	}
	return OSI_OK;
}
/*!
	\brief 	This function used to suspend the task for the specified number of milli secs
	\param	MilliSecs	-	Time in millisecs to suspend the task
	\return - void
	\note
	\warning
*/
void osi_Sleep(unsigned int MilliSecs)
{
	UInt nticks;

	nticks = (MilliSecs / TICK_RATE_MS);
	Task_sleep(nticks);
}


/*!
	\brief 	This function used to disable the tasks
	\param	- void
	\return - Key with the suspended tasks
	\note
	\warning
*/
unsigned long osi_TaskDisable(void)
{
    return(Task_disable());
}


/*!
	\brief 	This function used to resume all the tasks
	\param	key	-	returned from suspend tasks
	\return - void
	\note
	\warning
*/
void osi_TaskEnable(unsigned long ulKey)
{
	Task_restore(ulKey);
}


/*!
	\brief 	This function used to start the kernel
	\param	void
	\return - void
	\note
	\warning
*/
void osi_start()
{
	BIOS_start();
}


/*!
	\brief 	This function used to save the os context before sleep
	\param	void
	\return - void
	\note
	\warning
*/
void osi_ContextSave()
{
}

/*!
	\brief 	This function used to retrieve the context after sleep
	\param	void
	\return - void
	\note
	\warning
*/
void osi_ContextRestore()
{
}

