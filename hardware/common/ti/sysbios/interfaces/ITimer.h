/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

/*
 * ======== GENERATED SECTIONS ========
 *     
 *     PROLOGUE
 *     INCLUDES
 *     
 *     CREATE ARGS
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION STUBS
 *     FUNCTION SELECTORS
 *     
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_interfaces_ITimer__include
#define ti_sysbios_interfaces_ITimer__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_interfaces_ITimer__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_interfaces_ITimer___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/interfaces/package/package.defs.h>

#include <xdc/runtime/Types.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_FuncPtr)(xdc_UArg);

/* ANY */
#define ti_sysbios_interfaces_ITimer_ANY (~0)

/* StartMode */
enum ti_sysbios_interfaces_ITimer_StartMode {
    ti_sysbios_interfaces_ITimer_StartMode_AUTO,
    ti_sysbios_interfaces_ITimer_StartMode_USER
};
typedef enum ti_sysbios_interfaces_ITimer_StartMode ti_sysbios_interfaces_ITimer_StartMode;

/* RunMode */
enum ti_sysbios_interfaces_ITimer_RunMode {
    ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS,
    ti_sysbios_interfaces_ITimer_RunMode_ONESHOT,
    ti_sysbios_interfaces_ITimer_RunMode_DYNAMIC
};
typedef enum ti_sysbios_interfaces_ITimer_RunMode ti_sysbios_interfaces_ITimer_RunMode;

/* Status */
enum ti_sysbios_interfaces_ITimer_Status {
    ti_sysbios_interfaces_ITimer_Status_INUSE,
    ti_sysbios_interfaces_ITimer_Status_FREE
};
typedef enum ti_sysbios_interfaces_ITimer_Status ti_sysbios_interfaces_ITimer_Status;

/* PeriodType */
enum ti_sysbios_interfaces_ITimer_PeriodType {
    ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS,
    ti_sysbios_interfaces_ITimer_PeriodType_COUNTS
};
typedef enum ti_sysbios_interfaces_ITimer_PeriodType ti_sysbios_interfaces_ITimer_PeriodType;


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_interfaces_ITimer_Args__create {
    xdc_Int id;
    ti_sysbios_interfaces_ITimer_FuncPtr tickFxn;
} ti_sysbios_interfaces_ITimer_Args__create;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_interfaces_ITimer_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    ti_sysbios_interfaces_ITimer_RunMode runMode;
    ti_sysbios_interfaces_ITimer_StartMode startMode;
    xdc_UArg arg;
    xdc_UInt32 period;
    ti_sysbios_interfaces_ITimer_PeriodType periodType;
    xdc_runtime_Types_FreqHz extFreq;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_interfaces_ITimer_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_UInt (*getNumTimers)(void);
    ti_sysbios_interfaces_ITimer_Status (*getStatus)(xdc_UInt);
    xdc_Void (*startup)(void);
    xdc_UInt32 (*getMaxTicks)(void*);
    xdc_Void (*setNextTick)(void*, xdc_UInt32);
    xdc_Void (*start)(void*);
    xdc_Void (*stop)(void*);
    xdc_Void (*setPeriod)(void*, xdc_UInt32);
    xdc_Bool (*setPeriodMicroSecs)(void*, xdc_UInt32);
    xdc_UInt32 (*getPeriod)(void*);
    xdc_UInt32 (*getCount)(void*);
    xdc_Void (*getFreq)(void*, xdc_runtime_Types_FreqHz*);
    ti_sysbios_interfaces_ITimer_FuncPtr (*getFunc)(void*, xdc_UArg*);
    xdc_Void (*setFunc)(void*, ti_sysbios_interfaces_ITimer_FuncPtr, xdc_UArg);
    xdc_Void (*trigger)(void*, xdc_UInt32);
    xdc_UInt32 (*getExpiredCounts)(void*);
    xdc_UInt32 (*getExpiredTicks)(void*, xdc_UInt32);
    xdc_UInt32 (*getCurrentTick)(void*, xdc_Bool);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Interface__BASE__C */
__extern const xdc_runtime_Types_Base ti_sysbios_interfaces_ITimer_Interface__BASE__C;


/*
 * ======== FUNCTION STUBS ========
 */

/* create */
xdc__CODESECT(ti_sysbios_interfaces_ITimer_create, "ti_sysbios_interfaces_ITimer_create")
__extern ti_sysbios_interfaces_ITimer_Handle ti_sysbios_interfaces_ITimer_create(ti_sysbios_interfaces_ITimer_Module, xdc_Int id, ti_sysbios_interfaces_ITimer_FuncPtr tickFxn, const ti_sysbios_interfaces_ITimer_Params *, xdc_runtime_Error_Block *__eb);

/* delete */
xdc__CODESECT(ti_sysbios_interfaces_ITimer_delete, "ti_sysbios_interfaces_ITimer_delete")
__extern xdc_Void ti_sysbios_interfaces_ITimer_delete(ti_sysbios_interfaces_ITimer_Handle *);

/* Handle_to_Module */
static inline ti_sysbios_interfaces_ITimer_Module ti_sysbios_interfaces_ITimer_Handle_to_Module( ti_sysbios_interfaces_ITimer_Handle inst )
{
    return inst->__fxns;
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_interfaces_ITimer_Handle_label( ti_sysbios_interfaces_ITimer_Handle inst, xdc_runtime_Types_Label *lab )
{
    return inst->__fxns->__sysp->__label(inst, lab);
}

/* Module_id */
static inline xdc_runtime_Types_ModuleId ti_sysbios_interfaces_ITimer_Module_id( ti_sysbios_interfaces_ITimer_Module mod )
{
    return mod->__sysp->__mid;
}

/* getNumTimers */
static inline xdc_UInt ti_sysbios_interfaces_ITimer_getNumTimers( ti_sysbios_interfaces_ITimer_Module __inst )
{
    return __inst->getNumTimers();
}

/* getStatus */
static inline ti_sysbios_interfaces_ITimer_Status ti_sysbios_interfaces_ITimer_getStatus( ti_sysbios_interfaces_ITimer_Module __inst, xdc_UInt id )
{
    return __inst->getStatus(id);
}

/* startup */
static inline xdc_Void ti_sysbios_interfaces_ITimer_startup( ti_sysbios_interfaces_ITimer_Module __inst )
{
    __inst->startup();
}

/* getMaxTicks */
static inline xdc_UInt32 ti_sysbios_interfaces_ITimer_getMaxTicks( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return __inst->__fxns->getMaxTicks((void*)__inst);
}

/* setNextTick */
static inline xdc_Void ti_sysbios_interfaces_ITimer_setNextTick( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_UInt32 ticks )
{
    __inst->__fxns->setNextTick((void*)__inst, ticks);
}

/* start */
static inline xdc_Void ti_sysbios_interfaces_ITimer_start( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    __inst->__fxns->start((void*)__inst);
}

/* stop */
static inline xdc_Void ti_sysbios_interfaces_ITimer_stop( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    __inst->__fxns->stop((void*)__inst);
}

/* setPeriod */
static inline xdc_Void ti_sysbios_interfaces_ITimer_setPeriod( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_UInt32 period )
{
    __inst->__fxns->setPeriod((void*)__inst, period);
}

/* setPeriodMicroSecs */
static inline xdc_Bool ti_sysbios_interfaces_ITimer_setPeriodMicroSecs( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_UInt32 microsecs )
{
    return __inst->__fxns->setPeriodMicroSecs((void*)__inst, microsecs);
}

/* getPeriod */
static inline xdc_UInt32 ti_sysbios_interfaces_ITimer_getPeriod( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return __inst->__fxns->getPeriod((void*)__inst);
}

/* getCount */
static inline xdc_UInt32 ti_sysbios_interfaces_ITimer_getCount( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return __inst->__fxns->getCount((void*)__inst);
}

/* getFreq */
static inline xdc_Void ti_sysbios_interfaces_ITimer_getFreq( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_runtime_Types_FreqHz *freq )
{
    __inst->__fxns->getFreq((void*)__inst, freq);
}

/* getFunc */
static inline ti_sysbios_interfaces_ITimer_FuncPtr ti_sysbios_interfaces_ITimer_getFunc( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_UArg *arg )
{
    return __inst->__fxns->getFunc((void*)__inst, arg);
}

/* setFunc */
static inline xdc_Void ti_sysbios_interfaces_ITimer_setFunc( ti_sysbios_interfaces_ITimer_Handle __inst, ti_sysbios_interfaces_ITimer_FuncPtr fxn, xdc_UArg arg )
{
    __inst->__fxns->setFunc((void*)__inst, fxn, arg);
}

/* trigger */
static inline xdc_Void ti_sysbios_interfaces_ITimer_trigger( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_UInt32 cycles )
{
    __inst->__fxns->trigger((void*)__inst, cycles);
}

/* getExpiredCounts */
static inline xdc_UInt32 ti_sysbios_interfaces_ITimer_getExpiredCounts( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return __inst->__fxns->getExpiredCounts((void*)__inst);
}

/* getExpiredTicks */
static inline xdc_UInt32 ti_sysbios_interfaces_ITimer_getExpiredTicks( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_UInt32 tickPeriod )
{
    return __inst->__fxns->getExpiredTicks((void*)__inst, tickPeriod);
}

/* getCurrentTick */
static inline xdc_UInt32 ti_sysbios_interfaces_ITimer_getCurrentTick( ti_sysbios_interfaces_ITimer_Handle __inst, xdc_Bool save )
{
    return __inst->__fxns->getCurrentTick((void*)__inst, save);
}


/*
 * ======== FUNCTION SELECTORS ========
 */

/* These functions return function pointers for module and instance functions.
 * The functions accept modules and instances declared as types defined in this
 * interface, but they return functions defined for the actual objects passed
 * as parameters. These functions are not invoked by any generated code or
 * XDCtools internal code.
 */

/* getNumTimers_{FxnT,fxnP} */
typedef xdc_UInt (*ti_sysbios_interfaces_ITimer_getNumTimers_FxnT)(void);
static inline ti_sysbios_interfaces_ITimer_getNumTimers_FxnT ti_sysbios_interfaces_ITimer_getNumTimers_fxnP( ti_sysbios_interfaces_ITimer_Module __inst )
{
    return (ti_sysbios_interfaces_ITimer_getNumTimers_FxnT)__inst->getNumTimers;
}

/* getStatus_{FxnT,fxnP} */
typedef ti_sysbios_interfaces_ITimer_Status (*ti_sysbios_interfaces_ITimer_getStatus_FxnT)(xdc_UInt);
static inline ti_sysbios_interfaces_ITimer_getStatus_FxnT ti_sysbios_interfaces_ITimer_getStatus_fxnP( ti_sysbios_interfaces_ITimer_Module __inst )
{
    return (ti_sysbios_interfaces_ITimer_getStatus_FxnT)__inst->getStatus;
}

/* startup_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_startup_FxnT)(void);
static inline ti_sysbios_interfaces_ITimer_startup_FxnT ti_sysbios_interfaces_ITimer_startup_fxnP( ti_sysbios_interfaces_ITimer_Module __inst )
{
    return (ti_sysbios_interfaces_ITimer_startup_FxnT)__inst->startup;
}

/* getMaxTicks_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_interfaces_ITimer_getMaxTicks_FxnT)(xdc_Void *);
static inline ti_sysbios_interfaces_ITimer_getMaxTicks_FxnT ti_sysbios_interfaces_ITimer_getMaxTicks_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getMaxTicks_FxnT)__inst->__fxns->getMaxTicks;
}

/* setNextTick_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_setNextTick_FxnT)(xdc_Void *, xdc_UInt32);
static inline ti_sysbios_interfaces_ITimer_setNextTick_FxnT ti_sysbios_interfaces_ITimer_setNextTick_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_setNextTick_FxnT)__inst->__fxns->setNextTick;
}

/* start_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_start_FxnT)(xdc_Void *);
static inline ti_sysbios_interfaces_ITimer_start_FxnT ti_sysbios_interfaces_ITimer_start_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_start_FxnT)__inst->__fxns->start;
}

/* stop_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_stop_FxnT)(xdc_Void *);
static inline ti_sysbios_interfaces_ITimer_stop_FxnT ti_sysbios_interfaces_ITimer_stop_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_stop_FxnT)__inst->__fxns->stop;
}

/* setPeriod_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_setPeriod_FxnT)(xdc_Void *, xdc_UInt32);
static inline ti_sysbios_interfaces_ITimer_setPeriod_FxnT ti_sysbios_interfaces_ITimer_setPeriod_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_setPeriod_FxnT)__inst->__fxns->setPeriod;
}

/* setPeriodMicroSecs_{FxnT,fxnP} */
typedef xdc_Bool (*ti_sysbios_interfaces_ITimer_setPeriodMicroSecs_FxnT)(xdc_Void *, xdc_UInt32);
static inline ti_sysbios_interfaces_ITimer_setPeriodMicroSecs_FxnT ti_sysbios_interfaces_ITimer_setPeriodMicroSecs_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_setPeriodMicroSecs_FxnT)__inst->__fxns->setPeriodMicroSecs;
}

/* getPeriod_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_interfaces_ITimer_getPeriod_FxnT)(xdc_Void *);
static inline ti_sysbios_interfaces_ITimer_getPeriod_FxnT ti_sysbios_interfaces_ITimer_getPeriod_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getPeriod_FxnT)__inst->__fxns->getPeriod;
}

/* getCount_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_interfaces_ITimer_getCount_FxnT)(xdc_Void *);
static inline ti_sysbios_interfaces_ITimer_getCount_FxnT ti_sysbios_interfaces_ITimer_getCount_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getCount_FxnT)__inst->__fxns->getCount;
}

/* getFreq_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_getFreq_FxnT)(xdc_Void *, xdc_runtime_Types_FreqHz*);
static inline ti_sysbios_interfaces_ITimer_getFreq_FxnT ti_sysbios_interfaces_ITimer_getFreq_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getFreq_FxnT)__inst->__fxns->getFreq;
}

/* getFunc_{FxnT,fxnP} */
typedef ti_sysbios_interfaces_ITimer_FuncPtr (*ti_sysbios_interfaces_ITimer_getFunc_FxnT)(xdc_Void *, xdc_UArg*);
static inline ti_sysbios_interfaces_ITimer_getFunc_FxnT ti_sysbios_interfaces_ITimer_getFunc_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getFunc_FxnT)__inst->__fxns->getFunc;
}

/* setFunc_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_setFunc_FxnT)(xdc_Void *, ti_sysbios_interfaces_ITimer_FuncPtr, xdc_UArg);
static inline ti_sysbios_interfaces_ITimer_setFunc_FxnT ti_sysbios_interfaces_ITimer_setFunc_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_setFunc_FxnT)__inst->__fxns->setFunc;
}

/* trigger_{FxnT,fxnP} */
typedef xdc_Void (*ti_sysbios_interfaces_ITimer_trigger_FxnT)(xdc_Void *, xdc_UInt32);
static inline ti_sysbios_interfaces_ITimer_trigger_FxnT ti_sysbios_interfaces_ITimer_trigger_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_trigger_FxnT)__inst->__fxns->trigger;
}

/* getExpiredCounts_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_interfaces_ITimer_getExpiredCounts_FxnT)(xdc_Void *);
static inline ti_sysbios_interfaces_ITimer_getExpiredCounts_FxnT ti_sysbios_interfaces_ITimer_getExpiredCounts_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getExpiredCounts_FxnT)__inst->__fxns->getExpiredCounts;
}

/* getExpiredTicks_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_interfaces_ITimer_getExpiredTicks_FxnT)(xdc_Void *, xdc_UInt32);
static inline ti_sysbios_interfaces_ITimer_getExpiredTicks_FxnT ti_sysbios_interfaces_ITimer_getExpiredTicks_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getExpiredTicks_FxnT)__inst->__fxns->getExpiredTicks;
}

/* getCurrentTick_{FxnT,fxnP} */
typedef xdc_UInt32 (*ti_sysbios_interfaces_ITimer_getCurrentTick_FxnT)(xdc_Void *, xdc_Bool);
static inline ti_sysbios_interfaces_ITimer_getCurrentTick_FxnT ti_sysbios_interfaces_ITimer_getCurrentTick_fxnP( ti_sysbios_interfaces_ITimer_Handle __inst )
{
    return (ti_sysbios_interfaces_ITimer_getCurrentTick_FxnT)__inst->__fxns->getCurrentTick;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_interfaces_ITimer__top__
#undef __nested__
#endif

#endif /* ti_sysbios_interfaces_ITimer__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_interfaces_ITimer__nolocalnames)

#ifndef ti_sysbios_interfaces_ITimer__localnames__done
#define ti_sysbios_interfaces_ITimer__localnames__done

/* module prefix */
#define ITimer_Instance ti_sysbios_interfaces_ITimer_Instance
#define ITimer_Handle ti_sysbios_interfaces_ITimer_Handle
#define ITimer_Module ti_sysbios_interfaces_ITimer_Module
#define ITimer_FuncPtr ti_sysbios_interfaces_ITimer_FuncPtr
#define ITimer_ANY ti_sysbios_interfaces_ITimer_ANY
#define ITimer_StartMode ti_sysbios_interfaces_ITimer_StartMode
#define ITimer_RunMode ti_sysbios_interfaces_ITimer_RunMode
#define ITimer_Status ti_sysbios_interfaces_ITimer_Status
#define ITimer_PeriodType ti_sysbios_interfaces_ITimer_PeriodType
#define ITimer_StartMode_AUTO ti_sysbios_interfaces_ITimer_StartMode_AUTO
#define ITimer_StartMode_USER ti_sysbios_interfaces_ITimer_StartMode_USER
#define ITimer_RunMode_CONTINUOUS ti_sysbios_interfaces_ITimer_RunMode_CONTINUOUS
#define ITimer_RunMode_ONESHOT ti_sysbios_interfaces_ITimer_RunMode_ONESHOT
#define ITimer_RunMode_DYNAMIC ti_sysbios_interfaces_ITimer_RunMode_DYNAMIC
#define ITimer_Status_INUSE ti_sysbios_interfaces_ITimer_Status_INUSE
#define ITimer_Status_FREE ti_sysbios_interfaces_ITimer_Status_FREE
#define ITimer_PeriodType_MICROSECS ti_sysbios_interfaces_ITimer_PeriodType_MICROSECS
#define ITimer_PeriodType_COUNTS ti_sysbios_interfaces_ITimer_PeriodType_COUNTS
#define ITimer_Params ti_sysbios_interfaces_ITimer_Params
#define ITimer_getNumTimers ti_sysbios_interfaces_ITimer_getNumTimers
#define ITimer_getNumTimers_fxnP ti_sysbios_interfaces_ITimer_getNumTimers_fxnP
#define ITimer_getNumTimers_FxnT ti_sysbios_interfaces_ITimer_getNumTimers_FxnT
#define ITimer_getStatus ti_sysbios_interfaces_ITimer_getStatus
#define ITimer_getStatus_fxnP ti_sysbios_interfaces_ITimer_getStatus_fxnP
#define ITimer_getStatus_FxnT ti_sysbios_interfaces_ITimer_getStatus_FxnT
#define ITimer_startup ti_sysbios_interfaces_ITimer_startup
#define ITimer_startup_fxnP ti_sysbios_interfaces_ITimer_startup_fxnP
#define ITimer_startup_FxnT ti_sysbios_interfaces_ITimer_startup_FxnT
#define ITimer_getMaxTicks ti_sysbios_interfaces_ITimer_getMaxTicks
#define ITimer_getMaxTicks_fxnP ti_sysbios_interfaces_ITimer_getMaxTicks_fxnP
#define ITimer_getMaxTicks_FxnT ti_sysbios_interfaces_ITimer_getMaxTicks_FxnT
#define ITimer_setNextTick ti_sysbios_interfaces_ITimer_setNextTick
#define ITimer_setNextTick_fxnP ti_sysbios_interfaces_ITimer_setNextTick_fxnP
#define ITimer_setNextTick_FxnT ti_sysbios_interfaces_ITimer_setNextTick_FxnT
#define ITimer_start ti_sysbios_interfaces_ITimer_start
#define ITimer_start_fxnP ti_sysbios_interfaces_ITimer_start_fxnP
#define ITimer_start_FxnT ti_sysbios_interfaces_ITimer_start_FxnT
#define ITimer_stop ti_sysbios_interfaces_ITimer_stop
#define ITimer_stop_fxnP ti_sysbios_interfaces_ITimer_stop_fxnP
#define ITimer_stop_FxnT ti_sysbios_interfaces_ITimer_stop_FxnT
#define ITimer_setPeriod ti_sysbios_interfaces_ITimer_setPeriod
#define ITimer_setPeriod_fxnP ti_sysbios_interfaces_ITimer_setPeriod_fxnP
#define ITimer_setPeriod_FxnT ti_sysbios_interfaces_ITimer_setPeriod_FxnT
#define ITimer_setPeriodMicroSecs ti_sysbios_interfaces_ITimer_setPeriodMicroSecs
#define ITimer_setPeriodMicroSecs_fxnP ti_sysbios_interfaces_ITimer_setPeriodMicroSecs_fxnP
#define ITimer_setPeriodMicroSecs_FxnT ti_sysbios_interfaces_ITimer_setPeriodMicroSecs_FxnT
#define ITimer_getPeriod ti_sysbios_interfaces_ITimer_getPeriod
#define ITimer_getPeriod_fxnP ti_sysbios_interfaces_ITimer_getPeriod_fxnP
#define ITimer_getPeriod_FxnT ti_sysbios_interfaces_ITimer_getPeriod_FxnT
#define ITimer_getCount ti_sysbios_interfaces_ITimer_getCount
#define ITimer_getCount_fxnP ti_sysbios_interfaces_ITimer_getCount_fxnP
#define ITimer_getCount_FxnT ti_sysbios_interfaces_ITimer_getCount_FxnT
#define ITimer_getFreq ti_sysbios_interfaces_ITimer_getFreq
#define ITimer_getFreq_fxnP ti_sysbios_interfaces_ITimer_getFreq_fxnP
#define ITimer_getFreq_FxnT ti_sysbios_interfaces_ITimer_getFreq_FxnT
#define ITimer_getFunc ti_sysbios_interfaces_ITimer_getFunc
#define ITimer_getFunc_fxnP ti_sysbios_interfaces_ITimer_getFunc_fxnP
#define ITimer_getFunc_FxnT ti_sysbios_interfaces_ITimer_getFunc_FxnT
#define ITimer_setFunc ti_sysbios_interfaces_ITimer_setFunc
#define ITimer_setFunc_fxnP ti_sysbios_interfaces_ITimer_setFunc_fxnP
#define ITimer_setFunc_FxnT ti_sysbios_interfaces_ITimer_setFunc_FxnT
#define ITimer_trigger ti_sysbios_interfaces_ITimer_trigger
#define ITimer_trigger_fxnP ti_sysbios_interfaces_ITimer_trigger_fxnP
#define ITimer_trigger_FxnT ti_sysbios_interfaces_ITimer_trigger_FxnT
#define ITimer_getExpiredCounts ti_sysbios_interfaces_ITimer_getExpiredCounts
#define ITimer_getExpiredCounts_fxnP ti_sysbios_interfaces_ITimer_getExpiredCounts_fxnP
#define ITimer_getExpiredCounts_FxnT ti_sysbios_interfaces_ITimer_getExpiredCounts_FxnT
#define ITimer_getExpiredTicks ti_sysbios_interfaces_ITimer_getExpiredTicks
#define ITimer_getExpiredTicks_fxnP ti_sysbios_interfaces_ITimer_getExpiredTicks_fxnP
#define ITimer_getExpiredTicks_FxnT ti_sysbios_interfaces_ITimer_getExpiredTicks_FxnT
#define ITimer_getCurrentTick ti_sysbios_interfaces_ITimer_getCurrentTick
#define ITimer_getCurrentTick_fxnP ti_sysbios_interfaces_ITimer_getCurrentTick_fxnP
#define ITimer_getCurrentTick_FxnT ti_sysbios_interfaces_ITimer_getCurrentTick_FxnT
#define ITimer_Module_name ti_sysbios_interfaces_ITimer_Module_name
#define ITimer_create ti_sysbios_interfaces_ITimer_create
#define ITimer_delete ti_sysbios_interfaces_ITimer_delete
#define ITimer_Handle_label ti_sysbios_interfaces_ITimer_Handle_label
#define ITimer_Handle_to_Module ti_sysbios_interfaces_ITimer_Handle_to_Module

#endif /* ti_sysbios_interfaces_ITimer__localnames__done */
#endif
