/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_knl__
#define ti_sysbios_knl__


/*
 * ======== module ti.sysbios.knl.Clock ========
 */

typedef struct ti_sysbios_knl_Clock_Module_State ti_sysbios_knl_Clock_Module_State;
typedef struct ti_sysbios_knl_Clock_Params ti_sysbios_knl_Clock_Params;
typedef struct ti_sysbios_knl_Clock_Object ti_sysbios_knl_Clock_Object;
typedef struct ti_sysbios_knl_Clock_Struct ti_sysbios_knl_Clock_Struct;
typedef ti_sysbios_knl_Clock_Object* ti_sysbios_knl_Clock_Handle;
typedef struct ti_sysbios_knl_Clock_Object__ ti_sysbios_knl_Clock_Instance_State;
typedef ti_sysbios_knl_Clock_Object* ti_sysbios_knl_Clock_Instance;

/*
 * ======== module ti.sysbios.knl.Idle ========
 */


/*
 * ======== module ti.sysbios.knl.Intrinsics ========
 */

typedef struct ti_sysbios_knl_Intrinsics_Fxns__ ti_sysbios_knl_Intrinsics_Fxns__;
typedef const ti_sysbios_knl_Intrinsics_Fxns__* ti_sysbios_knl_Intrinsics_Module;

/*
 * ======== module ti.sysbios.knl.Event ========
 */

typedef struct ti_sysbios_knl_Event_PendElem ti_sysbios_knl_Event_PendElem;
typedef struct ti_sysbios_knl_Event_Params ti_sysbios_knl_Event_Params;
typedef struct ti_sysbios_knl_Event_Object ti_sysbios_knl_Event_Object;
typedef struct ti_sysbios_knl_Event_Struct ti_sysbios_knl_Event_Struct;
typedef ti_sysbios_knl_Event_Object* ti_sysbios_knl_Event_Handle;
typedef struct ti_sysbios_knl_Event_Object__ ti_sysbios_knl_Event_Instance_State;
typedef ti_sysbios_knl_Event_Object* ti_sysbios_knl_Event_Instance;

/*
 * ======== module ti.sysbios.knl.Mailbox ========
 */

typedef struct ti_sysbios_knl_Mailbox_MbxElem ti_sysbios_knl_Mailbox_MbxElem;
typedef struct ti_sysbios_knl_Mailbox_Params ti_sysbios_knl_Mailbox_Params;
typedef struct ti_sysbios_knl_Mailbox_Object ti_sysbios_knl_Mailbox_Object;
typedef struct ti_sysbios_knl_Mailbox_Struct ti_sysbios_knl_Mailbox_Struct;
typedef ti_sysbios_knl_Mailbox_Object* ti_sysbios_knl_Mailbox_Handle;
typedef struct ti_sysbios_knl_Mailbox_Object__ ti_sysbios_knl_Mailbox_Instance_State;
typedef ti_sysbios_knl_Mailbox_Object* ti_sysbios_knl_Mailbox_Instance;

/*
 * ======== module ti.sysbios.knl.Queue ========
 */

typedef struct ti_sysbios_knl_Queue_Elem ti_sysbios_knl_Queue_Elem;
typedef struct ti_sysbios_knl_Queue_Params ti_sysbios_knl_Queue_Params;
typedef struct ti_sysbios_knl_Queue_Object ti_sysbios_knl_Queue_Object;
typedef struct ti_sysbios_knl_Queue_Struct ti_sysbios_knl_Queue_Struct;
typedef ti_sysbios_knl_Queue_Object* ti_sysbios_knl_Queue_Handle;
typedef struct ti_sysbios_knl_Queue_Object__ ti_sysbios_knl_Queue_Instance_State;
typedef ti_sysbios_knl_Queue_Object* ti_sysbios_knl_Queue_Instance;

/*
 * ======== module ti.sysbios.knl.Semaphore ========
 */

typedef struct ti_sysbios_knl_Semaphore_PendElem ti_sysbios_knl_Semaphore_PendElem;
typedef struct ti_sysbios_knl_Semaphore_Params ti_sysbios_knl_Semaphore_Params;
typedef struct ti_sysbios_knl_Semaphore_Object ti_sysbios_knl_Semaphore_Object;
typedef struct ti_sysbios_knl_Semaphore_Struct ti_sysbios_knl_Semaphore_Struct;
typedef ti_sysbios_knl_Semaphore_Object* ti_sysbios_knl_Semaphore_Handle;
typedef struct ti_sysbios_knl_Semaphore_Object__ ti_sysbios_knl_Semaphore_Instance_State;
typedef ti_sysbios_knl_Semaphore_Object* ti_sysbios_knl_Semaphore_Instance;

/*
 * ======== module ti.sysbios.knl.Swi ========
 */

typedef struct ti_sysbios_knl_Swi_HookSet ti_sysbios_knl_Swi_HookSet;
typedef struct ti_sysbios_knl_Swi_Module_State ti_sysbios_knl_Swi_Module_State;
typedef struct ti_sysbios_knl_Swi_Params ti_sysbios_knl_Swi_Params;
typedef struct ti_sysbios_knl_Swi_Object ti_sysbios_knl_Swi_Object;
typedef struct ti_sysbios_knl_Swi_Struct ti_sysbios_knl_Swi_Struct;
typedef ti_sysbios_knl_Swi_Object* ti_sysbios_knl_Swi_Handle;
typedef struct ti_sysbios_knl_Swi_Object__ ti_sysbios_knl_Swi_Instance_State;
typedef ti_sysbios_knl_Swi_Object* ti_sysbios_knl_Swi_Instance;

/*
 * ======== module ti.sysbios.knl.Task ========
 */

typedef struct ti_sysbios_knl_Task_Stat ti_sysbios_knl_Task_Stat;
typedef struct ti_sysbios_knl_Task_HookSet ti_sysbios_knl_Task_HookSet;
typedef struct ti_sysbios_knl_Task_PendElem ti_sysbios_knl_Task_PendElem;
typedef struct ti_sysbios_knl_Task_Module_State ti_sysbios_knl_Task_Module_State;
typedef struct ti_sysbios_knl_Task_RunQEntry ti_sysbios_knl_Task_RunQEntry;
typedef struct ti_sysbios_knl_Task_Module_StateSmp ti_sysbios_knl_Task_Module_StateSmp;
typedef struct ti_sysbios_knl_Task_Params ti_sysbios_knl_Task_Params;
typedef struct ti_sysbios_knl_Task_Object ti_sysbios_knl_Task_Object;
typedef struct ti_sysbios_knl_Task_Struct ti_sysbios_knl_Task_Struct;
typedef ti_sysbios_knl_Task_Object* ti_sysbios_knl_Task_Handle;
typedef struct ti_sysbios_knl_Task_Object__ ti_sysbios_knl_Task_Instance_State;
typedef ti_sysbios_knl_Task_Object* ti_sysbios_knl_Task_Instance;

/*
 * ======== module ti.sysbios.knl.Clock_TimerProxy ========
 */

typedef struct ti_sysbios_knl_Clock_TimerProxy_Fxns__ ti_sysbios_knl_Clock_TimerProxy_Fxns__;
typedef const ti_sysbios_knl_Clock_TimerProxy_Fxns__* ti_sysbios_knl_Clock_TimerProxy_Module;
typedef struct ti_sysbios_knl_Clock_TimerProxy_Params ti_sysbios_knl_Clock_TimerProxy_Params;
typedef struct ti_sysbios_interfaces_ITimer___Object *ti_sysbios_knl_Clock_TimerProxy_Handle;

/*
 * ======== module ti.sysbios.knl.Intrinsics_SupportProxy ========
 */

typedef struct ti_sysbios_knl_Intrinsics_SupportProxy_Fxns__ ti_sysbios_knl_Intrinsics_SupportProxy_Fxns__;
typedef const ti_sysbios_knl_Intrinsics_SupportProxy_Fxns__* ti_sysbios_knl_Intrinsics_SupportProxy_Module;

/*
 * ======== module ti.sysbios.knl.Task_SupportProxy ========
 */

typedef struct ti_sysbios_knl_Task_SupportProxy_Fxns__ ti_sysbios_knl_Task_SupportProxy_Fxns__;
typedef const ti_sysbios_knl_Task_SupportProxy_Fxns__* ti_sysbios_knl_Task_SupportProxy_Module;


#endif /* ti_sysbios_knl__ */ 
