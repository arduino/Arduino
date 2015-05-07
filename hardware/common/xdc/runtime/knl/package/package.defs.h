/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef xdc_runtime_knl__
#define xdc_runtime_knl__


/*
 * ======== module xdc.runtime.knl.GateH ========
 */


/*
 * ======== module xdc.runtime.knl.Semaphore ========
 */


/*
 * ======== module xdc.runtime.knl.Thread ========
 */

typedef struct xdc_runtime_knl_Thread_Stat xdc_runtime_knl_Thread_Stat;
typedef struct xdc_runtime_knl_Thread_Params xdc_runtime_knl_Thread_Params;
typedef struct xdc_runtime_knl_Thread_Object xdc_runtime_knl_Thread_Object;
typedef struct xdc_runtime_knl_Thread_Struct xdc_runtime_knl_Thread_Struct;
typedef xdc_runtime_knl_Thread_Object* xdc_runtime_knl_Thread_Handle;
typedef struct xdc_runtime_knl_Thread_Object__ xdc_runtime_knl_Thread_Instance_State;
typedef xdc_runtime_knl_Thread_Object* xdc_runtime_knl_Thread_Instance;

/*
 * ======== module xdc.runtime.knl.Sync ========
 */


/*
 * ======== module xdc.runtime.knl.GateThread ========
 */

typedef struct xdc_runtime_knl_GateThread_Fxns__ xdc_runtime_knl_GateThread_Fxns__;
typedef const xdc_runtime_knl_GateThread_Fxns__* xdc_runtime_knl_GateThread_Module;
typedef struct xdc_runtime_knl_GateThread_Params xdc_runtime_knl_GateThread_Params;
typedef struct xdc_runtime_knl_GateThread_Object xdc_runtime_knl_GateThread_Object;
typedef struct xdc_runtime_knl_GateThread_Struct xdc_runtime_knl_GateThread_Struct;
typedef xdc_runtime_knl_GateThread_Object* xdc_runtime_knl_GateThread_Handle;
typedef struct xdc_runtime_knl_GateThread_Object__ xdc_runtime_knl_GateThread_Instance_State;
typedef xdc_runtime_knl_GateThread_Object* xdc_runtime_knl_GateThread_Instance;

/*
 * ======== module xdc.runtime.knl.GateProcess ========
 */

typedef struct xdc_runtime_knl_GateProcess_Fxns__ xdc_runtime_knl_GateProcess_Fxns__;
typedef const xdc_runtime_knl_GateProcess_Fxns__* xdc_runtime_knl_GateProcess_Module;
typedef struct xdc_runtime_knl_GateProcess_Params xdc_runtime_knl_GateProcess_Params;
typedef struct xdc_runtime_knl_GateProcess_Object xdc_runtime_knl_GateProcess_Object;
typedef struct xdc_runtime_knl_GateProcess_Struct xdc_runtime_knl_GateProcess_Struct;
typedef xdc_runtime_knl_GateProcess_Object* xdc_runtime_knl_GateProcess_Handle;
typedef struct xdc_runtime_knl_GateProcess_Object__ xdc_runtime_knl_GateProcess_Instance_State;
typedef xdc_runtime_knl_GateProcess_Object* xdc_runtime_knl_GateProcess_Instance;

/*
 * ======== interface xdc.runtime.knl.ISemaphore ========
 */

typedef struct xdc_runtime_knl_ISemaphore_Fxns__ xdc_runtime_knl_ISemaphore_Fxns__;
typedef const xdc_runtime_knl_ISemaphore_Fxns__* xdc_runtime_knl_ISemaphore_Module;
typedef struct xdc_runtime_knl_ISemaphore_Params xdc_runtime_knl_ISemaphore_Params;
typedef struct xdc_runtime_knl_ISemaphore___Object { xdc_runtime_knl_ISemaphore_Fxns__* __fxns; xdc_Bits32 __label; } *xdc_runtime_knl_ISemaphore_Handle;

/*
 * ======== module xdc.runtime.knl.SemThread ========
 */

typedef struct xdc_runtime_knl_SemThread_Fxns__ xdc_runtime_knl_SemThread_Fxns__;
typedef const xdc_runtime_knl_SemThread_Fxns__* xdc_runtime_knl_SemThread_Module;
typedef struct xdc_runtime_knl_SemThread_Params xdc_runtime_knl_SemThread_Params;
typedef struct xdc_runtime_knl_SemThread_Object xdc_runtime_knl_SemThread_Object;
typedef struct xdc_runtime_knl_SemThread_Struct xdc_runtime_knl_SemThread_Struct;
typedef xdc_runtime_knl_SemThread_Object* xdc_runtime_knl_SemThread_Handle;
typedef struct xdc_runtime_knl_SemThread_Object__ xdc_runtime_knl_SemThread_Instance_State;
typedef xdc_runtime_knl_SemThread_Object* xdc_runtime_knl_SemThread_Instance;

/*
 * ======== module xdc.runtime.knl.SemProcess ========
 */

typedef struct xdc_runtime_knl_SemProcess_Fxns__ xdc_runtime_knl_SemProcess_Fxns__;
typedef const xdc_runtime_knl_SemProcess_Fxns__* xdc_runtime_knl_SemProcess_Module;
typedef struct xdc_runtime_knl_SemProcess_Params xdc_runtime_knl_SemProcess_Params;
typedef struct xdc_runtime_knl_SemProcess_Object xdc_runtime_knl_SemProcess_Object;
typedef struct xdc_runtime_knl_SemProcess_Struct xdc_runtime_knl_SemProcess_Struct;
typedef xdc_runtime_knl_SemProcess_Object* xdc_runtime_knl_SemProcess_Handle;
typedef struct xdc_runtime_knl_SemProcess_Object__ xdc_runtime_knl_SemProcess_Instance_State;
typedef xdc_runtime_knl_SemProcess_Object* xdc_runtime_knl_SemProcess_Instance;

/*
 * ======== interface xdc.runtime.knl.ISync ========
 */

typedef struct xdc_runtime_knl_ISync_Fxns__ xdc_runtime_knl_ISync_Fxns__;
typedef const xdc_runtime_knl_ISync_Fxns__* xdc_runtime_knl_ISync_Module;
typedef struct xdc_runtime_knl_ISync_Params xdc_runtime_knl_ISync_Params;
typedef struct xdc_runtime_knl_ISync___Object { xdc_runtime_knl_ISync_Fxns__* __fxns; xdc_Bits32 __label; } *xdc_runtime_knl_ISync_Handle;

/*
 * ======== module xdc.runtime.knl.SyncGeneric ========
 */

typedef struct xdc_runtime_knl_SyncGeneric_Fxns__ xdc_runtime_knl_SyncGeneric_Fxns__;
typedef const xdc_runtime_knl_SyncGeneric_Fxns__* xdc_runtime_knl_SyncGeneric_Module;
typedef struct xdc_runtime_knl_SyncGeneric_Params xdc_runtime_knl_SyncGeneric_Params;
typedef struct xdc_runtime_knl_SyncGeneric_Object xdc_runtime_knl_SyncGeneric_Object;
typedef struct xdc_runtime_knl_SyncGeneric_Struct xdc_runtime_knl_SyncGeneric_Struct;
typedef xdc_runtime_knl_SyncGeneric_Object* xdc_runtime_knl_SyncGeneric_Handle;
typedef struct xdc_runtime_knl_SyncGeneric_Object__ xdc_runtime_knl_SyncGeneric_Instance_State;
typedef xdc_runtime_knl_SyncGeneric_Object* xdc_runtime_knl_SyncGeneric_Instance;

/*
 * ======== module xdc.runtime.knl.SyncNull ========
 */

typedef struct xdc_runtime_knl_SyncNull_Fxns__ xdc_runtime_knl_SyncNull_Fxns__;
typedef const xdc_runtime_knl_SyncNull_Fxns__* xdc_runtime_knl_SyncNull_Module;
typedef struct xdc_runtime_knl_SyncNull_Params xdc_runtime_knl_SyncNull_Params;
typedef struct xdc_runtime_knl_SyncNull_Object xdc_runtime_knl_SyncNull_Object;
typedef struct xdc_runtime_knl_SyncNull_Struct xdc_runtime_knl_SyncNull_Struct;
typedef xdc_runtime_knl_SyncNull_Object* xdc_runtime_knl_SyncNull_Handle;
typedef struct xdc_runtime_knl_SyncNull_Object__ xdc_runtime_knl_SyncNull_Instance_State;
typedef xdc_runtime_knl_SyncNull_Object* xdc_runtime_knl_SyncNull_Instance;

/*
 * ======== module xdc.runtime.knl.SyncSemThread ========
 */

typedef struct xdc_runtime_knl_SyncSemThread_Fxns__ xdc_runtime_knl_SyncSemThread_Fxns__;
typedef const xdc_runtime_knl_SyncSemThread_Fxns__* xdc_runtime_knl_SyncSemThread_Module;
typedef struct xdc_runtime_knl_SyncSemThread_Params xdc_runtime_knl_SyncSemThread_Params;
typedef struct xdc_runtime_knl_SyncSemThread_Object xdc_runtime_knl_SyncSemThread_Object;
typedef struct xdc_runtime_knl_SyncSemThread_Struct xdc_runtime_knl_SyncSemThread_Struct;
typedef xdc_runtime_knl_SyncSemThread_Object* xdc_runtime_knl_SyncSemThread_Handle;
typedef struct xdc_runtime_knl_SyncSemThread_Object__ xdc_runtime_knl_SyncSemThread_Instance_State;
typedef xdc_runtime_knl_SyncSemThread_Object* xdc_runtime_knl_SyncSemThread_Instance;

/*
 * ======== module xdc.runtime.knl.Cache ========
 */


/*
 * ======== interface xdc.runtime.knl.ICacheSupport ========
 */

typedef struct xdc_runtime_knl_ICacheSupport_Fxns__ xdc_runtime_knl_ICacheSupport_Fxns__;
typedef const xdc_runtime_knl_ICacheSupport_Fxns__* xdc_runtime_knl_ICacheSupport_Module;

/*
 * ======== module xdc.runtime.knl.CacheSupportNull ========
 */

typedef struct xdc_runtime_knl_CacheSupportNull_Fxns__ xdc_runtime_knl_CacheSupportNull_Fxns__;
typedef const xdc_runtime_knl_CacheSupportNull_Fxns__* xdc_runtime_knl_CacheSupportNull_Module;

/*
 * ======== interface xdc.runtime.knl.IGateThreadSupport ========
 */

typedef struct xdc_runtime_knl_IGateThreadSupport_Fxns__ xdc_runtime_knl_IGateThreadSupport_Fxns__;
typedef const xdc_runtime_knl_IGateThreadSupport_Fxns__* xdc_runtime_knl_IGateThreadSupport_Module;
typedef struct xdc_runtime_knl_IGateThreadSupport_Params xdc_runtime_knl_IGateThreadSupport_Params;
typedef struct xdc_runtime_knl_IGateThreadSupport___Object { xdc_runtime_knl_IGateThreadSupport_Fxns__* __fxns; xdc_Bits32 __label; } *xdc_runtime_knl_IGateThreadSupport_Handle;

/*
 * ======== module xdc.runtime.knl.GateThreadSupportNull ========
 */

typedef struct xdc_runtime_knl_GateThreadSupportNull_Fxns__ xdc_runtime_knl_GateThreadSupportNull_Fxns__;
typedef const xdc_runtime_knl_GateThreadSupportNull_Fxns__* xdc_runtime_knl_GateThreadSupportNull_Module;
typedef struct xdc_runtime_knl_GateThreadSupportNull_Params xdc_runtime_knl_GateThreadSupportNull_Params;
typedef struct xdc_runtime_knl_GateThreadSupportNull_Object xdc_runtime_knl_GateThreadSupportNull_Object;
typedef struct xdc_runtime_knl_GateThreadSupportNull_Struct xdc_runtime_knl_GateThreadSupportNull_Struct;
typedef xdc_runtime_knl_GateThreadSupportNull_Object* xdc_runtime_knl_GateThreadSupportNull_Handle;
typedef struct xdc_runtime_knl_GateThreadSupportNull_Object__ xdc_runtime_knl_GateThreadSupportNull_Instance_State;
typedef xdc_runtime_knl_GateThreadSupportNull_Object* xdc_runtime_knl_GateThreadSupportNull_Instance;

/*
 * ======== interface xdc.runtime.knl.IGateProcessSupport ========
 */

typedef struct xdc_runtime_knl_IGateProcessSupport_Fxns__ xdc_runtime_knl_IGateProcessSupport_Fxns__;
typedef const xdc_runtime_knl_IGateProcessSupport_Fxns__* xdc_runtime_knl_IGateProcessSupport_Module;
typedef struct xdc_runtime_knl_IGateProcessSupport_Params xdc_runtime_knl_IGateProcessSupport_Params;
typedef struct xdc_runtime_knl_IGateProcessSupport___Object { xdc_runtime_knl_IGateProcessSupport_Fxns__* __fxns; xdc_Bits32 __label; } *xdc_runtime_knl_IGateProcessSupport_Handle;

/*
 * ======== module xdc.runtime.knl.GateProcessSupportNull ========
 */

typedef struct xdc_runtime_knl_GateProcessSupportNull_Fxns__ xdc_runtime_knl_GateProcessSupportNull_Fxns__;
typedef const xdc_runtime_knl_GateProcessSupportNull_Fxns__* xdc_runtime_knl_GateProcessSupportNull_Module;
typedef struct xdc_runtime_knl_GateProcessSupportNull_Params xdc_runtime_knl_GateProcessSupportNull_Params;
typedef struct xdc_runtime_knl_GateProcessSupportNull_Object xdc_runtime_knl_GateProcessSupportNull_Object;
typedef struct xdc_runtime_knl_GateProcessSupportNull_Struct xdc_runtime_knl_GateProcessSupportNull_Struct;
typedef xdc_runtime_knl_GateProcessSupportNull_Object* xdc_runtime_knl_GateProcessSupportNull_Handle;
typedef struct xdc_runtime_knl_GateProcessSupportNull_Object__ xdc_runtime_knl_GateProcessSupportNull_Instance_State;
typedef xdc_runtime_knl_GateProcessSupportNull_Object* xdc_runtime_knl_GateProcessSupportNull_Instance;

/*
 * ======== interface xdc.runtime.knl.ISemThreadSupport ========
 */

typedef struct xdc_runtime_knl_ISemThreadSupport_Fxns__ xdc_runtime_knl_ISemThreadSupport_Fxns__;
typedef const xdc_runtime_knl_ISemThreadSupport_Fxns__* xdc_runtime_knl_ISemThreadSupport_Module;
typedef struct xdc_runtime_knl_ISemThreadSupport_Params xdc_runtime_knl_ISemThreadSupport_Params;
typedef struct xdc_runtime_knl_ISemThreadSupport___Object { xdc_runtime_knl_ISemThreadSupport_Fxns__* __fxns; xdc_Bits32 __label; } *xdc_runtime_knl_ISemThreadSupport_Handle;

/*
 * ======== interface xdc.runtime.knl.ISemProcessSupport ========
 */

typedef struct xdc_runtime_knl_ISemProcessSupport_Fxns__ xdc_runtime_knl_ISemProcessSupport_Fxns__;
typedef const xdc_runtime_knl_ISemProcessSupport_Fxns__* xdc_runtime_knl_ISemProcessSupport_Module;
typedef struct xdc_runtime_knl_ISemProcessSupport_Params xdc_runtime_knl_ISemProcessSupport_Params;
typedef struct xdc_runtime_knl_ISemProcessSupport___Object { xdc_runtime_knl_ISemProcessSupport_Fxns__* __fxns; xdc_Bits32 __label; } *xdc_runtime_knl_ISemProcessSupport_Handle;

/*
 * ======== interface xdc.runtime.knl.IThreadSupport ========
 */

typedef struct xdc_runtime_knl_IThreadSupport_Stat xdc_runtime_knl_IThreadSupport_Stat;
typedef struct xdc_runtime_knl_IThreadSupport_Fxns__ xdc_runtime_knl_IThreadSupport_Fxns__;
typedef const xdc_runtime_knl_IThreadSupport_Fxns__* xdc_runtime_knl_IThreadSupport_Module;
typedef struct xdc_runtime_knl_IThreadSupport_Params xdc_runtime_knl_IThreadSupport_Params;
typedef struct xdc_runtime_knl_IThreadSupport___Object { xdc_runtime_knl_IThreadSupport_Fxns__* __fxns; xdc_Bits32 __label; } *xdc_runtime_knl_IThreadSupport_Handle;

/*
 * ======== module xdc.runtime.knl.GateH_Proxy ========
 */

typedef struct xdc_runtime_knl_GateH_Proxy_Fxns__ xdc_runtime_knl_GateH_Proxy_Fxns__;
typedef const xdc_runtime_knl_GateH_Proxy_Fxns__* xdc_runtime_knl_GateH_Proxy_Module;
typedef struct xdc_runtime_knl_GateH_Proxy_Params xdc_runtime_knl_GateH_Proxy_Params;
typedef struct xdc_runtime_IGateProvider___Object *xdc_runtime_knl_GateH_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.Semaphore_Proxy ========
 */

typedef struct xdc_runtime_knl_Semaphore_Proxy_Fxns__ xdc_runtime_knl_Semaphore_Proxy_Fxns__;
typedef const xdc_runtime_knl_Semaphore_Proxy_Fxns__* xdc_runtime_knl_Semaphore_Proxy_Module;
typedef struct xdc_runtime_knl_Semaphore_Proxy_Params xdc_runtime_knl_Semaphore_Proxy_Params;
typedef struct xdc_runtime_knl_ISemaphore___Object *xdc_runtime_knl_Semaphore_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.Thread_Proxy ========
 */

typedef struct xdc_runtime_knl_Thread_Proxy_Fxns__ xdc_runtime_knl_Thread_Proxy_Fxns__;
typedef const xdc_runtime_knl_Thread_Proxy_Fxns__* xdc_runtime_knl_Thread_Proxy_Module;
typedef struct xdc_runtime_knl_Thread_Proxy_Params xdc_runtime_knl_Thread_Proxy_Params;
typedef struct xdc_runtime_knl_IThreadSupport___Object *xdc_runtime_knl_Thread_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.Sync_Proxy ========
 */

typedef struct xdc_runtime_knl_Sync_Proxy_Fxns__ xdc_runtime_knl_Sync_Proxy_Fxns__;
typedef const xdc_runtime_knl_Sync_Proxy_Fxns__* xdc_runtime_knl_Sync_Proxy_Module;
typedef struct xdc_runtime_knl_Sync_Proxy_Params xdc_runtime_knl_Sync_Proxy_Params;
typedef struct xdc_runtime_knl_ISync___Object *xdc_runtime_knl_Sync_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.GateThread_Proxy ========
 */

typedef struct xdc_runtime_knl_GateThread_Proxy_Fxns__ xdc_runtime_knl_GateThread_Proxy_Fxns__;
typedef const xdc_runtime_knl_GateThread_Proxy_Fxns__* xdc_runtime_knl_GateThread_Proxy_Module;
typedef struct xdc_runtime_knl_GateThread_Proxy_Params xdc_runtime_knl_GateThread_Proxy_Params;
typedef struct xdc_runtime_knl_IGateThreadSupport___Object *xdc_runtime_knl_GateThread_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.GateProcess_Proxy ========
 */

typedef struct xdc_runtime_knl_GateProcess_Proxy_Fxns__ xdc_runtime_knl_GateProcess_Proxy_Fxns__;
typedef const xdc_runtime_knl_GateProcess_Proxy_Fxns__* xdc_runtime_knl_GateProcess_Proxy_Module;
typedef struct xdc_runtime_knl_GateProcess_Proxy_Params xdc_runtime_knl_GateProcess_Proxy_Params;
typedef struct xdc_runtime_knl_IGateProcessSupport___Object *xdc_runtime_knl_GateProcess_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.SemThread_Proxy ========
 */

typedef struct xdc_runtime_knl_SemThread_Proxy_Fxns__ xdc_runtime_knl_SemThread_Proxy_Fxns__;
typedef const xdc_runtime_knl_SemThread_Proxy_Fxns__* xdc_runtime_knl_SemThread_Proxy_Module;
typedef struct xdc_runtime_knl_SemThread_Proxy_Params xdc_runtime_knl_SemThread_Proxy_Params;
typedef struct xdc_runtime_knl_ISemThreadSupport___Object *xdc_runtime_knl_SemThread_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.SemProcess_Proxy ========
 */

typedef struct xdc_runtime_knl_SemProcess_Proxy_Fxns__ xdc_runtime_knl_SemProcess_Proxy_Fxns__;
typedef const xdc_runtime_knl_SemProcess_Proxy_Fxns__* xdc_runtime_knl_SemProcess_Proxy_Module;
typedef struct xdc_runtime_knl_SemProcess_Proxy_Params xdc_runtime_knl_SemProcess_Proxy_Params;
typedef struct xdc_runtime_knl_ISemProcessSupport___Object *xdc_runtime_knl_SemProcess_Proxy_Handle;

/*
 * ======== module xdc.runtime.knl.Cache_Proxy ========
 */

typedef struct xdc_runtime_knl_Cache_Proxy_Fxns__ xdc_runtime_knl_Cache_Proxy_Fxns__;
typedef const xdc_runtime_knl_Cache_Proxy_Fxns__* xdc_runtime_knl_Cache_Proxy_Module;


#endif /* xdc_runtime_knl__ */ 
