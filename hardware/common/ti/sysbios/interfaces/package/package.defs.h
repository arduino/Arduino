/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_interfaces__
#define ti_sysbios_interfaces__


/*
 * ======== interface ti.sysbios.interfaces.ICore ========
 */

typedef struct ti_sysbios_interfaces_ICore_Fxns__ ti_sysbios_interfaces_ICore_Fxns__;
typedef const ti_sysbios_interfaces_ICore_Fxns__* ti_sysbios_interfaces_ICore_Module;

/*
 * ======== interface ti.sysbios.interfaces.IHwi ========
 */

typedef struct ti_sysbios_interfaces_IHwi_HookSet ti_sysbios_interfaces_IHwi_HookSet;
typedef struct ti_sysbios_interfaces_IHwi_StackInfo ti_sysbios_interfaces_IHwi_StackInfo;
typedef struct ti_sysbios_interfaces_IHwi_Fxns__ ti_sysbios_interfaces_IHwi_Fxns__;
typedef const ti_sysbios_interfaces_IHwi_Fxns__* ti_sysbios_interfaces_IHwi_Module;
typedef struct ti_sysbios_interfaces_IHwi_Params ti_sysbios_interfaces_IHwi_Params;
typedef struct ti_sysbios_interfaces_IHwi___Object { ti_sysbios_interfaces_IHwi_Fxns__* __fxns; xdc_Bits32 __label; } *ti_sysbios_interfaces_IHwi_Handle;

/*
 * ======== interface ti.sysbios.interfaces.ITaskSupport ========
 */

typedef struct ti_sysbios_interfaces_ITaskSupport_Fxns__ ti_sysbios_interfaces_ITaskSupport_Fxns__;
typedef const ti_sysbios_interfaces_ITaskSupport_Fxns__* ti_sysbios_interfaces_ITaskSupport_Module;

/*
 * ======== interface ti.sysbios.interfaces.ITimer ========
 */

typedef struct ti_sysbios_interfaces_ITimer_Fxns__ ti_sysbios_interfaces_ITimer_Fxns__;
typedef const ti_sysbios_interfaces_ITimer_Fxns__* ti_sysbios_interfaces_ITimer_Module;
typedef struct ti_sysbios_interfaces_ITimer_Params ti_sysbios_interfaces_ITimer_Params;
typedef struct ti_sysbios_interfaces_ITimer___Object { ti_sysbios_interfaces_ITimer_Fxns__* __fxns; xdc_Bits32 __label; } *ti_sysbios_interfaces_ITimer_Handle;

/*
 * ======== interface ti.sysbios.interfaces.ITimerSupport ========
 */

typedef struct ti_sysbios_interfaces_ITimerSupport_Fxns__ ti_sysbios_interfaces_ITimerSupport_Fxns__;
typedef const ti_sysbios_interfaces_ITimerSupport_Fxns__* ti_sysbios_interfaces_ITimerSupport_Module;

/*
 * ======== interface ti.sysbios.interfaces.ITimestamp ========
 */

typedef struct ti_sysbios_interfaces_ITimestamp_Fxns__ ti_sysbios_interfaces_ITimestamp_Fxns__;
typedef const ti_sysbios_interfaces_ITimestamp_Fxns__* ti_sysbios_interfaces_ITimestamp_Module;

/*
 * ======== interface ti.sysbios.interfaces.IIntrinsicsSupport ========
 */

typedef struct ti_sysbios_interfaces_IIntrinsicsSupport_Fxns__ ti_sysbios_interfaces_IIntrinsicsSupport_Fxns__;
typedef const ti_sysbios_interfaces_IIntrinsicsSupport_Fxns__* ti_sysbios_interfaces_IIntrinsicsSupport_Module;

/*
 * ======== interface ti.sysbios.interfaces.ICache ========
 */

typedef struct ti_sysbios_interfaces_ICache_Fxns__ ti_sysbios_interfaces_ICache_Fxns__;
typedef const ti_sysbios_interfaces_ICache_Fxns__* ti_sysbios_interfaces_ICache_Module;

/*
 * ======== interface ti.sysbios.interfaces.IPower ========
 */

typedef struct ti_sysbios_interfaces_IPower_Fxns__ ti_sysbios_interfaces_IPower_Fxns__;
typedef const ti_sysbios_interfaces_IPower_Fxns__* ti_sysbios_interfaces_IPower_Module;

/*
 * ======== interface ti.sysbios.interfaces.IRomDevice ========
 */

typedef struct ti_sysbios_interfaces_IRomDevice_Fxns__ ti_sysbios_interfaces_IRomDevice_Fxns__;
typedef const ti_sysbios_interfaces_IRomDevice_Fxns__* ti_sysbios_interfaces_IRomDevice_Module;

/*
 * ======== interface ti.sysbios.interfaces.ISeconds ========
 */

typedef struct ti_sysbios_interfaces_ISeconds_Fxns__ ti_sysbios_interfaces_ISeconds_Fxns__;
typedef const ti_sysbios_interfaces_ISeconds_Fxns__* ti_sysbios_interfaces_ISeconds_Module;


#endif /* ti_sysbios_interfaces__ */ 
