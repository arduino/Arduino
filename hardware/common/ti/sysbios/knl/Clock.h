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
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     FUNCTION DECLARATIONS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_knl_Clock__include
#define ti_sysbios_knl_Clock__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_knl_Clock__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_knl_Clock___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/knl/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/IModule.h>
#include <ti/sysbios/interfaces/ITimer.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/package/Clock_TimerProxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* TickSource */
enum ti_sysbios_knl_Clock_TickSource {
    ti_sysbios_knl_Clock_TickSource_TIMER,
    ti_sysbios_knl_Clock_TickSource_USER,
    ti_sysbios_knl_Clock_TickSource_NULL
};
typedef enum ti_sysbios_knl_Clock_TickSource ti_sysbios_knl_Clock_TickSource;

/* TickMode */
enum ti_sysbios_knl_Clock_TickMode {
    ti_sysbios_knl_Clock_TickMode_PERIODIC,
    ti_sysbios_knl_Clock_TickMode_DYNAMIC
};
typedef enum ti_sysbios_knl_Clock_TickMode ti_sysbios_knl_Clock_TickMode;

/* FuncPtr */
typedef xdc_Void (*ti_sysbios_knl_Clock_FuncPtr)(xdc_UArg);


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_knl_Clock_Args__create {
    ti_sysbios_knl_Clock_FuncPtr clockFxn;
    xdc_UInt timeout;
} ti_sysbios_knl_Clock_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_knl_Clock_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsEnabled ti_sysbios_knl_Clock_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_knl_Clock_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsIncluded ti_sysbios_knl_Clock_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_knl_Clock_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__diagsMask ti_sysbios_knl_Clock_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Clock_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__gateObj ti_sysbios_knl_Clock_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_knl_Clock_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__gatePrms ti_sysbios_knl_Clock_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_knl_Clock_Module__id;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_knl_Clock_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerDefined ti_sysbios_knl_Clock_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Clock_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerObj ti_sysbios_knl_Clock_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_knl_Clock_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn0 ti_sysbios_knl_Clock_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_knl_Clock_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn1 ti_sysbios_knl_Clock_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_knl_Clock_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn2 ti_sysbios_knl_Clock_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_knl_Clock_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn4 ti_sysbios_knl_Clock_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_knl_Clock_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__loggerFxn8 ti_sysbios_knl_Clock_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_knl_Clock_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Module__startupDoneFxn ti_sysbios_knl_Clock_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_knl_Clock_Object__count;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Object__count ti_sysbios_knl_Clock_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_knl_Clock_Object__heap;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Object__heap ti_sysbios_knl_Clock_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_knl_Clock_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Object__sizeof ti_sysbios_knl_Clock_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_knl_Clock_Object__table;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_Object__table ti_sysbios_knl_Clock_Object__table__C;

/* LW_delayed */
#define ti_sysbios_knl_Clock_LW_delayed (ti_sysbios_knl_Clock_LW_delayed__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_knl_Clock_LW_delayed;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed__C;

/* LM_tick */
#define ti_sysbios_knl_Clock_LM_tick (ti_sysbios_knl_Clock_LM_tick__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_knl_Clock_LM_tick;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_LM_tick ti_sysbios_knl_Clock_LM_tick__C;

/* LM_begin */
#define ti_sysbios_knl_Clock_LM_begin (ti_sysbios_knl_Clock_LM_begin__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_knl_Clock_LM_begin;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_LM_begin ti_sysbios_knl_Clock_LM_begin__C;

/* A_clockDisabled */
#define ti_sysbios_knl_Clock_A_clockDisabled (ti_sysbios_knl_Clock_A_clockDisabled__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Clock_A_clockDisabled;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_A_clockDisabled ti_sysbios_knl_Clock_A_clockDisabled__C;

/* A_badThreadType */
#define ti_sysbios_knl_Clock_A_badThreadType (ti_sysbios_knl_Clock_A_badThreadType__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Clock_A_badThreadType;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_A_badThreadType ti_sysbios_knl_Clock_A_badThreadType__C;

/* serviceMargin */
#ifdef ti_sysbios_knl_Clock_serviceMargin__D
#define ti_sysbios_knl_Clock_serviceMargin (ti_sysbios_knl_Clock_serviceMargin__D)
#else
#define ti_sysbios_knl_Clock_serviceMargin (ti_sysbios_knl_Clock_serviceMargin__C)
typedef xdc_UInt32 CT__ti_sysbios_knl_Clock_serviceMargin;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_serviceMargin ti_sysbios_knl_Clock_serviceMargin__C;
#endif

/* tickSource */
#define ti_sysbios_knl_Clock_tickSource (ti_sysbios_knl_Clock_tickSource__C)
typedef ti_sysbios_knl_Clock_TickSource CT__ti_sysbios_knl_Clock_tickSource;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_tickSource ti_sysbios_knl_Clock_tickSource__C;

/* tickMode */
#define ti_sysbios_knl_Clock_tickMode (ti_sysbios_knl_Clock_tickMode__C)
typedef ti_sysbios_knl_Clock_TickMode CT__ti_sysbios_knl_Clock_tickMode;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_tickMode ti_sysbios_knl_Clock_tickMode__C;

/* timerId */
#ifdef ti_sysbios_knl_Clock_timerId__D
#define ti_sysbios_knl_Clock_timerId (ti_sysbios_knl_Clock_timerId__D)
#else
#define ti_sysbios_knl_Clock_timerId (ti_sysbios_knl_Clock_timerId__C)
typedef xdc_UInt CT__ti_sysbios_knl_Clock_timerId;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_timerId ti_sysbios_knl_Clock_timerId__C;
#endif

/* tickPeriod */
#ifdef ti_sysbios_knl_Clock_tickPeriod__D
#define ti_sysbios_knl_Clock_tickPeriod (ti_sysbios_knl_Clock_tickPeriod__D)
#else
#define ti_sysbios_knl_Clock_tickPeriod (ti_sysbios_knl_Clock_tickPeriod__C)
typedef xdc_UInt32 CT__ti_sysbios_knl_Clock_tickPeriod;
__extern __FAR__ const CT__ti_sysbios_knl_Clock_tickPeriod ti_sysbios_knl_Clock_tickPeriod__C;
#endif

/* doTickFunc */
#define ti_sysbios_knl_Clock_doTickFunc (ti_sysbios_knl_Clock_doTickFunc__C)
typedef xdc_Void (*CT__ti_sysbios_knl_Clock_doTickFunc)(xdc_UArg);
__extern __FAR__ const CT__ti_sysbios_knl_Clock_doTickFunc ti_sysbios_knl_Clock_doTickFunc__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_knl_Clock_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_Bool startFlag;
    xdc_UInt32 period;
    xdc_UArg arg;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_knl_Clock_Struct {
    ti_sysbios_knl_Queue_Elem __f0;
    xdc_UInt32 __f1;
    xdc_UInt32 __f2;
    xdc_UInt32 __f3;
    volatile xdc_Bool __f4;
    ti_sysbios_knl_Clock_FuncPtr __f5;
    xdc_UArg __f6;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_knl_Clock_Module_startup ti_sysbios_knl_Clock_Module_startup__E
xdc__CODESECT(ti_sysbios_knl_Clock_Module_startup__E, "ti_sysbios_knl_Clock_Module_startup")
__extern xdc_Int ti_sysbios_knl_Clock_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_knl_Clock_Module_startup__F, "ti_sysbios_knl_Clock_Module_startup")
__extern xdc_Int ti_sysbios_knl_Clock_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_knl_Clock_Instance_init__E, "ti_sysbios_knl_Clock_Instance_init")
__extern xdc_Void ti_sysbios_knl_Clock_Instance_init__E(ti_sysbios_knl_Clock_Object *, ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt timeout, const ti_sysbios_knl_Clock_Params *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_knl_Clock_Instance_finalize__E, "ti_sysbios_knl_Clock_Instance_finalize")
__extern void ti_sysbios_knl_Clock_Instance_finalize__E( ti_sysbios_knl_Clock_Object* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Handle__label__S, "ti_sysbios_knl_Clock_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_knl_Clock_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Module__startupDone__S, "ti_sysbios_knl_Clock_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_knl_Clock_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Object__create__S, "ti_sysbios_knl_Clock_Object__create__S")
__extern xdc_Ptr ti_sysbios_knl_Clock_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_knl_Clock_create, "ti_sysbios_knl_Clock_create")
__extern ti_sysbios_knl_Clock_Handle ti_sysbios_knl_Clock_create( ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt timeout, const ti_sysbios_knl_Clock_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_knl_Clock_construct, "ti_sysbios_knl_Clock_construct")
__extern void ti_sysbios_knl_Clock_construct( ti_sysbios_knl_Clock_Struct *__obj, ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt timeout, const ti_sysbios_knl_Clock_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Object__delete__S, "ti_sysbios_knl_Clock_Object__delete__S")
__extern xdc_Void ti_sysbios_knl_Clock_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_knl_Clock_delete, "ti_sysbios_knl_Clock_delete")
__extern void ti_sysbios_knl_Clock_delete(ti_sysbios_knl_Clock_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Object__destruct__S, "ti_sysbios_knl_Clock_Object__destruct__S")
__extern xdc_Void ti_sysbios_knl_Clock_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_knl_Clock_destruct, "ti_sysbios_knl_Clock_destruct")
__extern void ti_sysbios_knl_Clock_destruct(ti_sysbios_knl_Clock_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Object__get__S, "ti_sysbios_knl_Clock_Object__get__S")
__extern xdc_Ptr ti_sysbios_knl_Clock_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Object__first__S, "ti_sysbios_knl_Clock_Object__first__S")
__extern xdc_Ptr ti_sysbios_knl_Clock_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Object__next__S, "ti_sysbios_knl_Clock_Object__next__S")
__extern xdc_Ptr ti_sysbios_knl_Clock_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_knl_Clock_Params__init__S, "ti_sysbios_knl_Clock_Params__init__S")
__extern xdc_Void ti_sysbios_knl_Clock_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* getTicks__E */
#define ti_sysbios_knl_Clock_getTicks ti_sysbios_knl_Clock_getTicks__E
xdc__CODESECT(ti_sysbios_knl_Clock_getTicks__E, "ti_sysbios_knl_Clock_getTicks")
__extern xdc_UInt32 ti_sysbios_knl_Clock_getTicks__E( void );

/* getTimerHandle__E */
#define ti_sysbios_knl_Clock_getTimerHandle ti_sysbios_knl_Clock_getTimerHandle__E
xdc__CODESECT(ti_sysbios_knl_Clock_getTimerHandle__E, "ti_sysbios_knl_Clock_getTimerHandle")
__extern ti_sysbios_knl_Clock_TimerProxy_Handle ti_sysbios_knl_Clock_getTimerHandle__E( void );

/* tickStop__E */
#define ti_sysbios_knl_Clock_tickStop ti_sysbios_knl_Clock_tickStop__E
xdc__CODESECT(ti_sysbios_knl_Clock_tickStop__E, "ti_sysbios_knl_Clock_tickStop")
__extern xdc_Void ti_sysbios_knl_Clock_tickStop__E( void );

/* tickReconfig__E */
#define ti_sysbios_knl_Clock_tickReconfig ti_sysbios_knl_Clock_tickReconfig__E
xdc__CODESECT(ti_sysbios_knl_Clock_tickReconfig__E, "ti_sysbios_knl_Clock_tickReconfig")
__extern xdc_Bool ti_sysbios_knl_Clock_tickReconfig__E( void );

/* tickStart__E */
#define ti_sysbios_knl_Clock_tickStart ti_sysbios_knl_Clock_tickStart__E
xdc__CODESECT(ti_sysbios_knl_Clock_tickStart__E, "ti_sysbios_knl_Clock_tickStart")
__extern xdc_Void ti_sysbios_knl_Clock_tickStart__E( void );

/* tick__E */
#define ti_sysbios_knl_Clock_tick ti_sysbios_knl_Clock_tick__E
xdc__CODESECT(ti_sysbios_knl_Clock_tick__E, "ti_sysbios_knl_Clock_tick")
__extern xdc_Void ti_sysbios_knl_Clock_tick__E( void );

/* workFunc__E */
#define ti_sysbios_knl_Clock_workFunc ti_sysbios_knl_Clock_workFunc__E
xdc__CODESECT(ti_sysbios_knl_Clock_workFunc__E, "ti_sysbios_knl_Clock_workFunc")
__extern xdc_Void ti_sysbios_knl_Clock_workFunc__E( xdc_UArg arg0, xdc_UArg arg1 );

/* workFuncDynamic__E */
#define ti_sysbios_knl_Clock_workFuncDynamic ti_sysbios_knl_Clock_workFuncDynamic__E
xdc__CODESECT(ti_sysbios_knl_Clock_workFuncDynamic__E, "ti_sysbios_knl_Clock_workFuncDynamic")
__extern xdc_Void ti_sysbios_knl_Clock_workFuncDynamic__E( xdc_UArg arg0, xdc_UArg arg1 );

/* logTick__E */
#define ti_sysbios_knl_Clock_logTick ti_sysbios_knl_Clock_logTick__E
xdc__CODESECT(ti_sysbios_knl_Clock_logTick__E, "ti_sysbios_knl_Clock_logTick")
__extern xdc_Void ti_sysbios_knl_Clock_logTick__E( void );

/* getCompletedTicks__E */
#define ti_sysbios_knl_Clock_getCompletedTicks ti_sysbios_knl_Clock_getCompletedTicks__E
xdc__CODESECT(ti_sysbios_knl_Clock_getCompletedTicks__E, "ti_sysbios_knl_Clock_getCompletedTicks")
__extern xdc_UInt32 ti_sysbios_knl_Clock_getCompletedTicks__E( void );

/* getTickPeriod__E */
#define ti_sysbios_knl_Clock_getTickPeriod ti_sysbios_knl_Clock_getTickPeriod__E
xdc__CODESECT(ti_sysbios_knl_Clock_getTickPeriod__E, "ti_sysbios_knl_Clock_getTickPeriod")
__extern xdc_UInt32 ti_sysbios_knl_Clock_getTickPeriod__E( void );

/* getTicksUntilInterrupt__E */
#define ti_sysbios_knl_Clock_getTicksUntilInterrupt ti_sysbios_knl_Clock_getTicksUntilInterrupt__E
xdc__CODESECT(ti_sysbios_knl_Clock_getTicksUntilInterrupt__E, "ti_sysbios_knl_Clock_getTicksUntilInterrupt")
__extern xdc_UInt32 ti_sysbios_knl_Clock_getTicksUntilInterrupt__E( void );

/* walkQueueDynamic__E */
#define ti_sysbios_knl_Clock_walkQueueDynamic ti_sysbios_knl_Clock_walkQueueDynamic__E
xdc__CODESECT(ti_sysbios_knl_Clock_walkQueueDynamic__E, "ti_sysbios_knl_Clock_walkQueueDynamic")
__extern xdc_UInt32 ti_sysbios_knl_Clock_walkQueueDynamic__E( xdc_Bool service, xdc_UInt32 tick );

/* scheduleNextTick__E */
#define ti_sysbios_knl_Clock_scheduleNextTick ti_sysbios_knl_Clock_scheduleNextTick__E
xdc__CODESECT(ti_sysbios_knl_Clock_scheduleNextTick__E, "ti_sysbios_knl_Clock_scheduleNextTick")
__extern xdc_Void ti_sysbios_knl_Clock_scheduleNextTick__E( xdc_UInt32 deltaTicks, xdc_UInt32 absTick );

/* addI__E */
#define ti_sysbios_knl_Clock_addI ti_sysbios_knl_Clock_addI__E
xdc__CODESECT(ti_sysbios_knl_Clock_addI__E, "ti_sysbios_knl_Clock_addI")
__extern xdc_Void ti_sysbios_knl_Clock_addI__E( ti_sysbios_knl_Clock_Handle __inst, ti_sysbios_knl_Clock_FuncPtr clockFxn, xdc_UInt32 timeout, xdc_UArg arg );

/* removeI__E */
#define ti_sysbios_knl_Clock_removeI ti_sysbios_knl_Clock_removeI__E
xdc__CODESECT(ti_sysbios_knl_Clock_removeI__E, "ti_sysbios_knl_Clock_removeI")
__extern xdc_Void ti_sysbios_knl_Clock_removeI__E( ti_sysbios_knl_Clock_Handle __inst );

/* start__E */
#define ti_sysbios_knl_Clock_start ti_sysbios_knl_Clock_start__E
xdc__CODESECT(ti_sysbios_knl_Clock_start__E, "ti_sysbios_knl_Clock_start")
__extern xdc_Void ti_sysbios_knl_Clock_start__E( ti_sysbios_knl_Clock_Handle __inst );

/* startI__E */
#define ti_sysbios_knl_Clock_startI ti_sysbios_knl_Clock_startI__E
xdc__CODESECT(ti_sysbios_knl_Clock_startI__E, "ti_sysbios_knl_Clock_startI")
__extern xdc_Void ti_sysbios_knl_Clock_startI__E( ti_sysbios_knl_Clock_Handle __inst );

/* stop__E */
#define ti_sysbios_knl_Clock_stop ti_sysbios_knl_Clock_stop__E
xdc__CODESECT(ti_sysbios_knl_Clock_stop__E, "ti_sysbios_knl_Clock_stop")
__extern xdc_Void ti_sysbios_knl_Clock_stop__E( ti_sysbios_knl_Clock_Handle __inst );

/* setPeriod__E */
#define ti_sysbios_knl_Clock_setPeriod ti_sysbios_knl_Clock_setPeriod__E
xdc__CODESECT(ti_sysbios_knl_Clock_setPeriod__E, "ti_sysbios_knl_Clock_setPeriod")
__extern xdc_Void ti_sysbios_knl_Clock_setPeriod__E( ti_sysbios_knl_Clock_Handle __inst, xdc_UInt32 period );

/* setTimeout__E */
#define ti_sysbios_knl_Clock_setTimeout ti_sysbios_knl_Clock_setTimeout__E
xdc__CODESECT(ti_sysbios_knl_Clock_setTimeout__E, "ti_sysbios_knl_Clock_setTimeout")
__extern xdc_Void ti_sysbios_knl_Clock_setTimeout__E( ti_sysbios_knl_Clock_Handle __inst, xdc_UInt32 timeout );

/* setFunc__E */
#define ti_sysbios_knl_Clock_setFunc ti_sysbios_knl_Clock_setFunc__E
xdc__CODESECT(ti_sysbios_knl_Clock_setFunc__E, "ti_sysbios_knl_Clock_setFunc")
__extern xdc_Void ti_sysbios_knl_Clock_setFunc__E( ti_sysbios_knl_Clock_Handle __inst, ti_sysbios_knl_Clock_FuncPtr fxn, xdc_UArg arg );

/* getPeriod__E */
#define ti_sysbios_knl_Clock_getPeriod ti_sysbios_knl_Clock_getPeriod__E
xdc__CODESECT(ti_sysbios_knl_Clock_getPeriod__E, "ti_sysbios_knl_Clock_getPeriod")
__extern xdc_UInt32 ti_sysbios_knl_Clock_getPeriod__E( ti_sysbios_knl_Clock_Handle __inst );

/* getTimeout__E */
#define ti_sysbios_knl_Clock_getTimeout ti_sysbios_knl_Clock_getTimeout__E
xdc__CODESECT(ti_sysbios_knl_Clock_getTimeout__E, "ti_sysbios_knl_Clock_getTimeout")
__extern xdc_UInt32 ti_sysbios_knl_Clock_getTimeout__E( ti_sysbios_knl_Clock_Handle __inst );

/* isActive__E */
#define ti_sysbios_knl_Clock_isActive ti_sysbios_knl_Clock_isActive__E
xdc__CODESECT(ti_sysbios_knl_Clock_isActive__E, "ti_sysbios_knl_Clock_isActive")
__extern xdc_Bool ti_sysbios_knl_Clock_isActive__E( ti_sysbios_knl_Clock_Handle __inst );

/* doTick__I */
#define ti_sysbios_knl_Clock_doTick ti_sysbios_knl_Clock_doTick__I
xdc__CODESECT(ti_sysbios_knl_Clock_doTick__I, "ti_sysbios_knl_Clock_doTick")
__extern xdc_Void ti_sysbios_knl_Clock_doTick__I( xdc_UArg arg );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_knl_Clock_Module_startupDone() ti_sysbios_knl_Clock_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_knl_Clock_Object_heap() ti_sysbios_knl_Clock_Object__heap__C

/* Module_heap */
#define ti_sysbios_knl_Clock_Module_heap() ti_sysbios_knl_Clock_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_knl_Clock_Module__id ti_sysbios_knl_Clock_Module_id( void ) 
{
    return ti_sysbios_knl_Clock_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_knl_Clock_Module_hasMask( void ) 
{
    return ti_sysbios_knl_Clock_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_knl_Clock_Module_getMask( void ) 
{
    return ti_sysbios_knl_Clock_Module__diagsMask__C != NULL ? *ti_sysbios_knl_Clock_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_knl_Clock_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_knl_Clock_Module__diagsMask__C != NULL) *ti_sysbios_knl_Clock_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_knl_Clock_Params_init( ti_sysbios_knl_Clock_Params *prms ) 
{
    if (prms) {
        ti_sysbios_knl_Clock_Params__init__S(prms, 0, sizeof(ti_sysbios_knl_Clock_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_knl_Clock_Params_copy(ti_sysbios_knl_Clock_Params *dst, const ti_sysbios_knl_Clock_Params *src) 
{
    if (dst) {
        ti_sysbios_knl_Clock_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_knl_Clock_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_knl_Clock_Object_count() ti_sysbios_knl_Clock_Object__count__C

/* Object_sizeof */
#define ti_sysbios_knl_Clock_Object_sizeof() ti_sysbios_knl_Clock_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_knl_Clock_Object_get(ti_sysbios_knl_Clock_Instance_State *oarr, int i) 
{
    return (ti_sysbios_knl_Clock_Handle)ti_sysbios_knl_Clock_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_knl_Clock_Object_first( void )
{
    return (ti_sysbios_knl_Clock_Handle)ti_sysbios_knl_Clock_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_knl_Clock_Object_next( ti_sysbios_knl_Clock_Object *obj )
{
    return (ti_sysbios_knl_Clock_Handle)ti_sysbios_knl_Clock_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_knl_Clock_Handle_label( ti_sysbios_knl_Clock_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_knl_Clock_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_knl_Clock_Handle_name( ti_sysbios_knl_Clock_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_knl_Clock_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_knl_Clock_handle( ti_sysbios_knl_Clock_Struct *str )
{
    return (ti_sysbios_knl_Clock_Handle)str;
}

/* struct */
static inline ti_sysbios_knl_Clock_Struct *ti_sysbios_knl_Clock_struct( ti_sysbios_knl_Clock_Handle inst )
{
    return (ti_sysbios_knl_Clock_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_knl_Clock__top__
#undef __nested__
#endif

#endif /* ti_sysbios_knl_Clock__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_knl_Clock__internalaccess))

#ifndef ti_sysbios_knl_Clock__include_state
#define ti_sysbios_knl_Clock__include_state

/* Module_State */
struct ti_sysbios_knl_Clock_Module_State {
    volatile xdc_UInt32 ticks;
    xdc_UInt swiCount;
    ti_sysbios_knl_Clock_TimerProxy_Handle timer;
    ti_sysbios_knl_Swi_Handle swi;
    volatile xdc_UInt numTickSkip;
    xdc_UInt32 nextScheduledTick;
    xdc_UInt32 maxSkippable;
    xdc_Bool inWorkFunc;
    xdc_Bool startDuringWorkFunc;
    xdc_Bool ticking;
    char __dummy;
};

/* Module__state__V */
extern struct ti_sysbios_knl_Clock_Module_State__ ti_sysbios_knl_Clock_Module__state__V;

/* Object */
struct ti_sysbios_knl_Clock_Object {
    ti_sysbios_knl_Queue_Elem elem;
    xdc_UInt32 timeout;
    xdc_UInt32 currTimeout;
    xdc_UInt32 period;
    volatile xdc_Bool active;
    ti_sysbios_knl_Clock_FuncPtr fxn;
    xdc_UArg arg;
};

/* Module_State_clockQ */
__extern __FAR__ const xdc_SizeT ti_sysbios_knl_Clock_Module_State_clockQ__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Clock_Module_State_clockQ()
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)&ti_sysbios_knl_Clock_Module__state__V) + ti_sysbios_knl_Clock_Module_State_clockQ__O);
}

#endif /* ti_sysbios_knl_Clock__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_knl_Clock__nolocalnames)

#ifndef ti_sysbios_knl_Clock__localnames__done
#define ti_sysbios_knl_Clock__localnames__done

/* module prefix */
#define Clock_Instance ti_sysbios_knl_Clock_Instance
#define Clock_Handle ti_sysbios_knl_Clock_Handle
#define Clock_Module ti_sysbios_knl_Clock_Module
#define Clock_Object ti_sysbios_knl_Clock_Object
#define Clock_Struct ti_sysbios_knl_Clock_Struct
#define Clock_TickSource ti_sysbios_knl_Clock_TickSource
#define Clock_TickMode ti_sysbios_knl_Clock_TickMode
#define Clock_FuncPtr ti_sysbios_knl_Clock_FuncPtr
#define Clock_Instance_State ti_sysbios_knl_Clock_Instance_State
#define Clock_Module_State ti_sysbios_knl_Clock_Module_State
#define Clock_TickSource_TIMER ti_sysbios_knl_Clock_TickSource_TIMER
#define Clock_TickSource_USER ti_sysbios_knl_Clock_TickSource_USER
#define Clock_TickSource_NULL ti_sysbios_knl_Clock_TickSource_NULL
#define Clock_TickMode_PERIODIC ti_sysbios_knl_Clock_TickMode_PERIODIC
#define Clock_TickMode_DYNAMIC ti_sysbios_knl_Clock_TickMode_DYNAMIC
#define Clock_LW_delayed ti_sysbios_knl_Clock_LW_delayed
#define Clock_LM_tick ti_sysbios_knl_Clock_LM_tick
#define Clock_LM_begin ti_sysbios_knl_Clock_LM_begin
#define Clock_A_clockDisabled ti_sysbios_knl_Clock_A_clockDisabled
#define Clock_A_badThreadType ti_sysbios_knl_Clock_A_badThreadType
#define Clock_serviceMargin ti_sysbios_knl_Clock_serviceMargin
#define Clock_tickSource ti_sysbios_knl_Clock_tickSource
#define Clock_tickMode ti_sysbios_knl_Clock_tickMode
#define Clock_timerId ti_sysbios_knl_Clock_timerId
#define Clock_tickPeriod ti_sysbios_knl_Clock_tickPeriod
#define Clock_doTickFunc ti_sysbios_knl_Clock_doTickFunc
#define Clock_Module_State_clockQ ti_sysbios_knl_Clock_Module_State_clockQ
#define Clock_Params ti_sysbios_knl_Clock_Params
#define Clock_getTicks ti_sysbios_knl_Clock_getTicks
#define Clock_getTimerHandle ti_sysbios_knl_Clock_getTimerHandle
#define Clock_tickStop ti_sysbios_knl_Clock_tickStop
#define Clock_tickReconfig ti_sysbios_knl_Clock_tickReconfig
#define Clock_tickStart ti_sysbios_knl_Clock_tickStart
#define Clock_tick ti_sysbios_knl_Clock_tick
#define Clock_workFunc ti_sysbios_knl_Clock_workFunc
#define Clock_workFuncDynamic ti_sysbios_knl_Clock_workFuncDynamic
#define Clock_logTick ti_sysbios_knl_Clock_logTick
#define Clock_getCompletedTicks ti_sysbios_knl_Clock_getCompletedTicks
#define Clock_getTickPeriod ti_sysbios_knl_Clock_getTickPeriod
#define Clock_getTicksUntilInterrupt ti_sysbios_knl_Clock_getTicksUntilInterrupt
#define Clock_walkQueueDynamic ti_sysbios_knl_Clock_walkQueueDynamic
#define Clock_scheduleNextTick ti_sysbios_knl_Clock_scheduleNextTick
#define Clock_addI ti_sysbios_knl_Clock_addI
#define Clock_removeI ti_sysbios_knl_Clock_removeI
#define Clock_start ti_sysbios_knl_Clock_start
#define Clock_startI ti_sysbios_knl_Clock_startI
#define Clock_stop ti_sysbios_knl_Clock_stop
#define Clock_setPeriod ti_sysbios_knl_Clock_setPeriod
#define Clock_setTimeout ti_sysbios_knl_Clock_setTimeout
#define Clock_setFunc ti_sysbios_knl_Clock_setFunc
#define Clock_getPeriod ti_sysbios_knl_Clock_getPeriod
#define Clock_getTimeout ti_sysbios_knl_Clock_getTimeout
#define Clock_isActive ti_sysbios_knl_Clock_isActive
#define Clock_Module_name ti_sysbios_knl_Clock_Module_name
#define Clock_Module_id ti_sysbios_knl_Clock_Module_id
#define Clock_Module_startup ti_sysbios_knl_Clock_Module_startup
#define Clock_Module_startupDone ti_sysbios_knl_Clock_Module_startupDone
#define Clock_Module_hasMask ti_sysbios_knl_Clock_Module_hasMask
#define Clock_Module_getMask ti_sysbios_knl_Clock_Module_getMask
#define Clock_Module_setMask ti_sysbios_knl_Clock_Module_setMask
#define Clock_Object_heap ti_sysbios_knl_Clock_Object_heap
#define Clock_Module_heap ti_sysbios_knl_Clock_Module_heap
#define Clock_construct ti_sysbios_knl_Clock_construct
#define Clock_create ti_sysbios_knl_Clock_create
#define Clock_handle ti_sysbios_knl_Clock_handle
#define Clock_struct ti_sysbios_knl_Clock_struct
#define Clock_Handle_label ti_sysbios_knl_Clock_Handle_label
#define Clock_Handle_name ti_sysbios_knl_Clock_Handle_name
#define Clock_Instance_init ti_sysbios_knl_Clock_Instance_init
#define Clock_Object_count ti_sysbios_knl_Clock_Object_count
#define Clock_Object_get ti_sysbios_knl_Clock_Object_get
#define Clock_Object_first ti_sysbios_knl_Clock_Object_first
#define Clock_Object_next ti_sysbios_knl_Clock_Object_next
#define Clock_Object_sizeof ti_sysbios_knl_Clock_Object_sizeof
#define Clock_Params_copy ti_sysbios_knl_Clock_Params_copy
#define Clock_Params_init ti_sysbios_knl_Clock_Params_init
#define Clock_Instance_finalize ti_sysbios_knl_Clock_Instance_finalize
#define Clock_delete ti_sysbios_knl_Clock_delete
#define Clock_destruct ti_sysbios_knl_Clock_destruct

/* proxies */
#include <ti/sysbios/knl/package/Clock_TimerProxy.h>

#endif /* ti_sysbios_knl_Clock__localnames__done */
#endif
