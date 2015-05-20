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
 *     INTERNAL DEFINITIONS
 *     MODULE-WIDE CONFIGS
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

#ifndef ti_sysbios_utils_Load__include
#define ti_sysbios_utils_Load__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_utils_Load__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_utils_Load___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/utils/package/package.defs.h>

#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/interfaces/IHwi.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* FuncPtr */
typedef xdc_Void (*ti_sysbios_utils_Load_FuncPtr)(void);

/* Stat */
struct ti_sysbios_utils_Load_Stat {
    xdc_UInt32 threadTime;
    xdc_UInt32 totalTime;
};


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* HookContext */
struct ti_sysbios_utils_Load_HookContext {
    ti_sysbios_knl_Queue_Elem qElem;
    xdc_UInt32 totalTimeElapsed;
    xdc_UInt32 totalTime;
    xdc_UInt32 nextTotalTime;
    xdc_UInt32 timeOfLastUpdate;
    xdc_Ptr threadHandle;
};

/* Module_State */
typedef xdc_UInt32 __T1_ti_sysbios_utils_Load_Module_State__taskStartTime;
typedef xdc_UInt32 *__ARRAY1_ti_sysbios_utils_Load_Module_State__taskStartTime;
typedef __ARRAY1_ti_sysbios_utils_Load_Module_State__taskStartTime __TA_ti_sysbios_utils_Load_Module_State__taskStartTime;
typedef ti_sysbios_knl_Task_Handle __T1_ti_sysbios_utils_Load_Module_State__runningTask;
typedef ti_sysbios_knl_Task_Handle *__ARRAY1_ti_sysbios_utils_Load_Module_State__runningTask;
typedef __ARRAY1_ti_sysbios_utils_Load_Module_State__runningTask __TA_ti_sysbios_utils_Load_Module_State__runningTask;
typedef ti_sysbios_utils_Load_HookContext __T1_ti_sysbios_utils_Load_Module_State__taskEnv;
typedef ti_sysbios_utils_Load_HookContext *__ARRAY1_ti_sysbios_utils_Load_Module_State__taskEnv;
typedef __ARRAY1_ti_sysbios_utils_Load_Module_State__taskEnv __TA_ti_sysbios_utils_Load_Module_State__taskEnv;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_utils_Load_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__diagsEnabled ti_sysbios_utils_Load_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_utils_Load_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__diagsIncluded ti_sysbios_utils_Load_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_utils_Load_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__diagsMask ti_sysbios_utils_Load_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_utils_Load_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__gateObj ti_sysbios_utils_Load_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_utils_Load_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__gatePrms ti_sysbios_utils_Load_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_utils_Load_Module__id;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__id ti_sysbios_utils_Load_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_utils_Load_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__loggerDefined ti_sysbios_utils_Load_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_utils_Load_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__loggerObj ti_sysbios_utils_Load_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_utils_Load_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__loggerFxn0 ti_sysbios_utils_Load_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_utils_Load_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__loggerFxn1 ti_sysbios_utils_Load_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_utils_Load_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__loggerFxn2 ti_sysbios_utils_Load_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_utils_Load_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__loggerFxn4 ti_sysbios_utils_Load_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_utils_Load_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__loggerFxn8 ti_sysbios_utils_Load_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_utils_Load_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_utils_Load_Module__startupDoneFxn ti_sysbios_utils_Load_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_utils_Load_Object__count;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Object__count ti_sysbios_utils_Load_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_utils_Load_Object__heap;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Object__heap ti_sysbios_utils_Load_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_utils_Load_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Object__sizeof ti_sysbios_utils_Load_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_utils_Load_Object__table;
__extern __FAR__ const CT__ti_sysbios_utils_Load_Object__table ti_sysbios_utils_Load_Object__table__C;

/* LS_cpuLoad */
#define ti_sysbios_utils_Load_LS_cpuLoad (ti_sysbios_utils_Load_LS_cpuLoad__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_utils_Load_LS_cpuLoad;
__extern __FAR__ const CT__ti_sysbios_utils_Load_LS_cpuLoad ti_sysbios_utils_Load_LS_cpuLoad__C;

/* LS_hwiLoad */
#define ti_sysbios_utils_Load_LS_hwiLoad (ti_sysbios_utils_Load_LS_hwiLoad__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_utils_Load_LS_hwiLoad;
__extern __FAR__ const CT__ti_sysbios_utils_Load_LS_hwiLoad ti_sysbios_utils_Load_LS_hwiLoad__C;

/* LS_swiLoad */
#define ti_sysbios_utils_Load_LS_swiLoad (ti_sysbios_utils_Load_LS_swiLoad__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_utils_Load_LS_swiLoad;
__extern __FAR__ const CT__ti_sysbios_utils_Load_LS_swiLoad ti_sysbios_utils_Load_LS_swiLoad__C;

/* LS_taskLoad */
#define ti_sysbios_utils_Load_LS_taskLoad (ti_sysbios_utils_Load_LS_taskLoad__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_utils_Load_LS_taskLoad;
__extern __FAR__ const CT__ti_sysbios_utils_Load_LS_taskLoad ti_sysbios_utils_Load_LS_taskLoad__C;

/* postUpdate */
#define ti_sysbios_utils_Load_postUpdate (ti_sysbios_utils_Load_postUpdate__C)
typedef ti_sysbios_utils_Load_FuncPtr CT__ti_sysbios_utils_Load_postUpdate;
__extern __FAR__ const CT__ti_sysbios_utils_Load_postUpdate ti_sysbios_utils_Load_postUpdate__C;

/* updateInIdle */
#ifdef ti_sysbios_utils_Load_updateInIdle__D
#define ti_sysbios_utils_Load_updateInIdle (ti_sysbios_utils_Load_updateInIdle__D)
#else
#define ti_sysbios_utils_Load_updateInIdle (ti_sysbios_utils_Load_updateInIdle__C)
typedef xdc_Bool CT__ti_sysbios_utils_Load_updateInIdle;
__extern __FAR__ const CT__ti_sysbios_utils_Load_updateInIdle ti_sysbios_utils_Load_updateInIdle__C;
#endif

/* windowInMs */
#ifdef ti_sysbios_utils_Load_windowInMs__D
#define ti_sysbios_utils_Load_windowInMs (ti_sysbios_utils_Load_windowInMs__D)
#else
#define ti_sysbios_utils_Load_windowInMs (ti_sysbios_utils_Load_windowInMs__C)
typedef xdc_UInt CT__ti_sysbios_utils_Load_windowInMs;
__extern __FAR__ const CT__ti_sysbios_utils_Load_windowInMs ti_sysbios_utils_Load_windowInMs__C;
#endif

/* hwiEnabled */
#ifdef ti_sysbios_utils_Load_hwiEnabled__D
#define ti_sysbios_utils_Load_hwiEnabled (ti_sysbios_utils_Load_hwiEnabled__D)
#else
#define ti_sysbios_utils_Load_hwiEnabled (ti_sysbios_utils_Load_hwiEnabled__C)
typedef xdc_Bool CT__ti_sysbios_utils_Load_hwiEnabled;
__extern __FAR__ const CT__ti_sysbios_utils_Load_hwiEnabled ti_sysbios_utils_Load_hwiEnabled__C;
#endif

/* swiEnabled */
#ifdef ti_sysbios_utils_Load_swiEnabled__D
#define ti_sysbios_utils_Load_swiEnabled (ti_sysbios_utils_Load_swiEnabled__D)
#else
#define ti_sysbios_utils_Load_swiEnabled (ti_sysbios_utils_Load_swiEnabled__C)
typedef xdc_Bool CT__ti_sysbios_utils_Load_swiEnabled;
__extern __FAR__ const CT__ti_sysbios_utils_Load_swiEnabled ti_sysbios_utils_Load_swiEnabled__C;
#endif

/* taskEnabled */
#ifdef ti_sysbios_utils_Load_taskEnabled__D
#define ti_sysbios_utils_Load_taskEnabled (ti_sysbios_utils_Load_taskEnabled__D)
#else
#define ti_sysbios_utils_Load_taskEnabled (ti_sysbios_utils_Load_taskEnabled__C)
typedef xdc_Bool CT__ti_sysbios_utils_Load_taskEnabled;
__extern __FAR__ const CT__ti_sysbios_utils_Load_taskEnabled ti_sysbios_utils_Load_taskEnabled__C;
#endif

/* autoAddTasks */
#ifdef ti_sysbios_utils_Load_autoAddTasks__D
#define ti_sysbios_utils_Load_autoAddTasks (ti_sysbios_utils_Load_autoAddTasks__D)
#else
#define ti_sysbios_utils_Load_autoAddTasks (ti_sysbios_utils_Load_autoAddTasks__C)
typedef xdc_Bool CT__ti_sysbios_utils_Load_autoAddTasks;
__extern __FAR__ const CT__ti_sysbios_utils_Load_autoAddTasks ti_sysbios_utils_Load_autoAddTasks__C;
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_utils_Load_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_utils_Load_Module__startupDone__S, "ti_sysbios_utils_Load_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_utils_Load_Module__startupDone__S( void );

/* getTaskLoad__E */
#define ti_sysbios_utils_Load_getTaskLoad ti_sysbios_utils_Load_getTaskLoad__E
xdc__CODESECT(ti_sysbios_utils_Load_getTaskLoad__E, "ti_sysbios_utils_Load_getTaskLoad")
__extern xdc_Bool ti_sysbios_utils_Load_getTaskLoad__E( ti_sysbios_knl_Task_Handle task, ti_sysbios_utils_Load_Stat *stat );

/* update__E */
#define ti_sysbios_utils_Load_update ti_sysbios_utils_Load_update__E
xdc__CODESECT(ti_sysbios_utils_Load_update__E, "ti_sysbios_utils_Load_update")
__extern xdc_Void ti_sysbios_utils_Load_update__E( void );

/* updateCPULoad__E */
#define ti_sysbios_utils_Load_updateCPULoad ti_sysbios_utils_Load_updateCPULoad__E
xdc__CODESECT(ti_sysbios_utils_Load_updateCPULoad__E, "ti_sysbios_utils_Load_updateCPULoad")
__extern xdc_Void ti_sysbios_utils_Load_updateCPULoad__E( void );

/* updateLoads__E */
#define ti_sysbios_utils_Load_updateLoads ti_sysbios_utils_Load_updateLoads__E
xdc__CODESECT(ti_sysbios_utils_Load_updateLoads__E, "ti_sysbios_utils_Load_updateLoads")
__extern xdc_Void ti_sysbios_utils_Load_updateLoads__E( void );

/* updateCurrentThreadTime__E */
#define ti_sysbios_utils_Load_updateCurrentThreadTime ti_sysbios_utils_Load_updateCurrentThreadTime__E
xdc__CODESECT(ti_sysbios_utils_Load_updateCurrentThreadTime__E, "ti_sysbios_utils_Load_updateCurrentThreadTime")
__extern xdc_Void ti_sysbios_utils_Load_updateCurrentThreadTime__E( void );

/* updateThreadContexts__E */
#define ti_sysbios_utils_Load_updateThreadContexts ti_sysbios_utils_Load_updateThreadContexts__E
xdc__CODESECT(ti_sysbios_utils_Load_updateThreadContexts__E, "ti_sysbios_utils_Load_updateThreadContexts")
__extern xdc_Void ti_sysbios_utils_Load_updateThreadContexts__E( void );

/* reset__E */
#define ti_sysbios_utils_Load_reset ti_sysbios_utils_Load_reset__E
xdc__CODESECT(ti_sysbios_utils_Load_reset__E, "ti_sysbios_utils_Load_reset")
__extern xdc_Void ti_sysbios_utils_Load_reset__E( void );

/* getGlobalSwiLoad__E */
#define ti_sysbios_utils_Load_getGlobalSwiLoad ti_sysbios_utils_Load_getGlobalSwiLoad__E
xdc__CODESECT(ti_sysbios_utils_Load_getGlobalSwiLoad__E, "ti_sysbios_utils_Load_getGlobalSwiLoad")
__extern xdc_Bool ti_sysbios_utils_Load_getGlobalSwiLoad__E( ti_sysbios_utils_Load_Stat *stat );

/* getGlobalHwiLoad__E */
#define ti_sysbios_utils_Load_getGlobalHwiLoad ti_sysbios_utils_Load_getGlobalHwiLoad__E
xdc__CODESECT(ti_sysbios_utils_Load_getGlobalHwiLoad__E, "ti_sysbios_utils_Load_getGlobalHwiLoad")
__extern xdc_Bool ti_sysbios_utils_Load_getGlobalHwiLoad__E( ti_sysbios_utils_Load_Stat *stat );

/* getCPULoad__E */
#define ti_sysbios_utils_Load_getCPULoad ti_sysbios_utils_Load_getCPULoad__E
xdc__CODESECT(ti_sysbios_utils_Load_getCPULoad__E, "ti_sysbios_utils_Load_getCPULoad")
__extern xdc_UInt32 ti_sysbios_utils_Load_getCPULoad__E( void );

/* calculateLoad__E */
#define ti_sysbios_utils_Load_calculateLoad ti_sysbios_utils_Load_calculateLoad__E
xdc__CODESECT(ti_sysbios_utils_Load_calculateLoad__E, "ti_sysbios_utils_Load_calculateLoad")
__extern xdc_UInt32 ti_sysbios_utils_Load_calculateLoad__E( ti_sysbios_utils_Load_Stat *stat );

/* setMinIdle__E */
#define ti_sysbios_utils_Load_setMinIdle ti_sysbios_utils_Load_setMinIdle__E
xdc__CODESECT(ti_sysbios_utils_Load_setMinIdle__E, "ti_sysbios_utils_Load_setMinIdle")
__extern xdc_UInt32 ti_sysbios_utils_Load_setMinIdle__E( xdc_UInt32 newMinIdleTime );

/* addTask__E */
#define ti_sysbios_utils_Load_addTask ti_sysbios_utils_Load_addTask__E
xdc__CODESECT(ti_sysbios_utils_Load_addTask__E, "ti_sysbios_utils_Load_addTask")
__extern xdc_Void ti_sysbios_utils_Load_addTask__E( ti_sysbios_knl_Task_Handle task, ti_sysbios_utils_Load_HookContext *env );

/* removeTask__E */
#define ti_sysbios_utils_Load_removeTask ti_sysbios_utils_Load_removeTask__E
xdc__CODESECT(ti_sysbios_utils_Load_removeTask__E, "ti_sysbios_utils_Load_removeTask")
__extern xdc_Bool ti_sysbios_utils_Load_removeTask__E( ti_sysbios_knl_Task_Handle task );

/* idleFxn__E */
#define ti_sysbios_utils_Load_idleFxn ti_sysbios_utils_Load_idleFxn__E
xdc__CODESECT(ti_sysbios_utils_Load_idleFxn__E, "ti_sysbios_utils_Load_idleFxn")
__extern xdc_Void ti_sysbios_utils_Load_idleFxn__E( void );

/* idleFxnPwr__E */
#define ti_sysbios_utils_Load_idleFxnPwr ti_sysbios_utils_Load_idleFxnPwr__E
xdc__CODESECT(ti_sysbios_utils_Load_idleFxnPwr__E, "ti_sysbios_utils_Load_idleFxnPwr")
__extern xdc_Void ti_sysbios_utils_Load_idleFxnPwr__E( void );

/* taskCreateHook__E */
#define ti_sysbios_utils_Load_taskCreateHook ti_sysbios_utils_Load_taskCreateHook__E
xdc__CODESECT(ti_sysbios_utils_Load_taskCreateHook__E, "ti_sysbios_utils_Load_taskCreateHook")
__extern xdc_Void ti_sysbios_utils_Load_taskCreateHook__E( ti_sysbios_knl_Task_Handle task, xdc_runtime_Error_Block *eb );

/* taskDeleteHook__E */
#define ti_sysbios_utils_Load_taskDeleteHook ti_sysbios_utils_Load_taskDeleteHook__E
xdc__CODESECT(ti_sysbios_utils_Load_taskDeleteHook__E, "ti_sysbios_utils_Load_taskDeleteHook")
__extern xdc_Void ti_sysbios_utils_Load_taskDeleteHook__E( ti_sysbios_knl_Task_Handle task );

/* taskSwitchHook__E */
#define ti_sysbios_utils_Load_taskSwitchHook ti_sysbios_utils_Load_taskSwitchHook__E
xdc__CODESECT(ti_sysbios_utils_Load_taskSwitchHook__E, "ti_sysbios_utils_Load_taskSwitchHook")
__extern xdc_Void ti_sysbios_utils_Load_taskSwitchHook__E( ti_sysbios_knl_Task_Handle curTask, ti_sysbios_knl_Task_Handle nextTask );

/* swiBeginHook__E */
#define ti_sysbios_utils_Load_swiBeginHook ti_sysbios_utils_Load_swiBeginHook__E
xdc__CODESECT(ti_sysbios_utils_Load_swiBeginHook__E, "ti_sysbios_utils_Load_swiBeginHook")
__extern xdc_Void ti_sysbios_utils_Load_swiBeginHook__E( ti_sysbios_knl_Swi_Handle swi );

/* swiEndHook__E */
#define ti_sysbios_utils_Load_swiEndHook ti_sysbios_utils_Load_swiEndHook__E
xdc__CODESECT(ti_sysbios_utils_Load_swiEndHook__E, "ti_sysbios_utils_Load_swiEndHook")
__extern xdc_Void ti_sysbios_utils_Load_swiEndHook__E( ti_sysbios_knl_Swi_Handle swi );

/* hwiBeginHook__E */
#define ti_sysbios_utils_Load_hwiBeginHook ti_sysbios_utils_Load_hwiBeginHook__E
xdc__CODESECT(ti_sysbios_utils_Load_hwiBeginHook__E, "ti_sysbios_utils_Load_hwiBeginHook")
__extern xdc_Void ti_sysbios_utils_Load_hwiBeginHook__E( ti_sysbios_interfaces_IHwi_Handle hwi );

/* hwiEndHook__E */
#define ti_sysbios_utils_Load_hwiEndHook ti_sysbios_utils_Load_hwiEndHook__E
xdc__CODESECT(ti_sysbios_utils_Load_hwiEndHook__E, "ti_sysbios_utils_Load_hwiEndHook")
__extern xdc_Void ti_sysbios_utils_Load_hwiEndHook__E( ti_sysbios_interfaces_IHwi_Handle hwi );

/* taskRegHook__E */
#define ti_sysbios_utils_Load_taskRegHook ti_sysbios_utils_Load_taskRegHook__E
xdc__CODESECT(ti_sysbios_utils_Load_taskRegHook__E, "ti_sysbios_utils_Load_taskRegHook")
__extern xdc_Void ti_sysbios_utils_Load_taskRegHook__E( xdc_Int id );

/* logLoads__I */
#define ti_sysbios_utils_Load_logLoads ti_sysbios_utils_Load_logLoads__I
xdc__CODESECT(ti_sysbios_utils_Load_logLoads__I, "ti_sysbios_utils_Load_logLoads")
__extern xdc_Void ti_sysbios_utils_Load_logLoads__I( void );

/* logCPULoad__I */
#define ti_sysbios_utils_Load_logCPULoad ti_sysbios_utils_Load_logCPULoad__I
xdc__CODESECT(ti_sysbios_utils_Load_logCPULoad__I, "ti_sysbios_utils_Load_logCPULoad")
__extern xdc_Void ti_sysbios_utils_Load_logCPULoad__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_utils_Load_Module_startupDone() ti_sysbios_utils_Load_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_utils_Load_Object_heap() ti_sysbios_utils_Load_Object__heap__C

/* Module_heap */
#define ti_sysbios_utils_Load_Module_heap() ti_sysbios_utils_Load_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_utils_Load_Module__id ti_sysbios_utils_Load_Module_id( void ) 
{
    return ti_sysbios_utils_Load_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_utils_Load_Module_hasMask( void ) 
{
    return ti_sysbios_utils_Load_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_utils_Load_Module_getMask( void ) 
{
    return ti_sysbios_utils_Load_Module__diagsMask__C != NULL ? *ti_sysbios_utils_Load_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_utils_Load_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_utils_Load_Module__diagsMask__C != NULL) *ti_sysbios_utils_Load_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_utils_Load__top__
#undef __nested__
#endif

#endif /* ti_sysbios_utils_Load__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_utils_Load__internalaccess))

#ifndef ti_sysbios_utils_Load__include_state
#define ti_sysbios_utils_Load__include_state

/* Module_State */
struct ti_sysbios_utils_Load_Module_State {
    xdc_Int taskHId;
    __TA_ti_sysbios_utils_Load_Module_State__taskStartTime taskStartTime;
    xdc_UInt32 timeElapsed;
    __TA_ti_sysbios_utils_Load_Module_State__runningTask runningTask;
    xdc_Bool firstSwitchDone;
    xdc_UInt32 swiStartTime;
    ti_sysbios_utils_Load_HookContext swiEnv;
    __TA_ti_sysbios_utils_Load_Module_State__taskEnv taskEnv;
    xdc_UInt32 swiCnt;
    xdc_UInt32 hwiStartTime;
    ti_sysbios_utils_Load_HookContext hwiEnv;
    xdc_UInt32 hwiCnt;
    xdc_UInt32 timeSlotCnt;
    xdc_UInt32 minLoop;
    xdc_UInt32 minIdle;
    xdc_UInt32 t0;
    xdc_UInt32 idleCnt;
    xdc_UInt32 cpuLoad;
    xdc_UInt32 taskEnvLen;
    xdc_UInt32 taskNum;
    xdc_Bool powerEnabled;
    xdc_UInt32 idleStartTime;
    xdc_UInt32 busyStartTime;
    xdc_UInt32 busyTime;
    char __dummy;
};

/* Module__state__V */
extern struct ti_sysbios_utils_Load_Module_State__ ti_sysbios_utils_Load_Module__state__V;

/* Module_State_taskList */
__extern __FAR__ const xdc_SizeT ti_sysbios_utils_Load_Module_State_taskList__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_utils_Load_Module_State_taskList()
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)&ti_sysbios_utils_Load_Module__state__V) + ti_sysbios_utils_Load_Module_State_taskList__O);
}

#endif /* ti_sysbios_utils_Load__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_utils_Load__nolocalnames)

#ifndef ti_sysbios_utils_Load__localnames__done
#define ti_sysbios_utils_Load__localnames__done

/* module prefix */
#define Load_FuncPtr ti_sysbios_utils_Load_FuncPtr
#define Load_Stat ti_sysbios_utils_Load_Stat
#define Load_HookContext ti_sysbios_utils_Load_HookContext
#define Load_Module_State ti_sysbios_utils_Load_Module_State
#define Load_LS_cpuLoad ti_sysbios_utils_Load_LS_cpuLoad
#define Load_LS_hwiLoad ti_sysbios_utils_Load_LS_hwiLoad
#define Load_LS_swiLoad ti_sysbios_utils_Load_LS_swiLoad
#define Load_LS_taskLoad ti_sysbios_utils_Load_LS_taskLoad
#define Load_postUpdate ti_sysbios_utils_Load_postUpdate
#define Load_updateInIdle ti_sysbios_utils_Load_updateInIdle
#define Load_windowInMs ti_sysbios_utils_Load_windowInMs
#define Load_hwiEnabled ti_sysbios_utils_Load_hwiEnabled
#define Load_swiEnabled ti_sysbios_utils_Load_swiEnabled
#define Load_taskEnabled ti_sysbios_utils_Load_taskEnabled
#define Load_autoAddTasks ti_sysbios_utils_Load_autoAddTasks
#define Load_Module_State_taskList ti_sysbios_utils_Load_Module_State_taskList
#define Load_getTaskLoad ti_sysbios_utils_Load_getTaskLoad
#define Load_update ti_sysbios_utils_Load_update
#define Load_updateCPULoad ti_sysbios_utils_Load_updateCPULoad
#define Load_updateLoads ti_sysbios_utils_Load_updateLoads
#define Load_updateCurrentThreadTime ti_sysbios_utils_Load_updateCurrentThreadTime
#define Load_updateThreadContexts ti_sysbios_utils_Load_updateThreadContexts
#define Load_reset ti_sysbios_utils_Load_reset
#define Load_getGlobalSwiLoad ti_sysbios_utils_Load_getGlobalSwiLoad
#define Load_getGlobalHwiLoad ti_sysbios_utils_Load_getGlobalHwiLoad
#define Load_getCPULoad ti_sysbios_utils_Load_getCPULoad
#define Load_calculateLoad ti_sysbios_utils_Load_calculateLoad
#define Load_setMinIdle ti_sysbios_utils_Load_setMinIdle
#define Load_addTask ti_sysbios_utils_Load_addTask
#define Load_removeTask ti_sysbios_utils_Load_removeTask
#define Load_idleFxn ti_sysbios_utils_Load_idleFxn
#define Load_idleFxnPwr ti_sysbios_utils_Load_idleFxnPwr
#define Load_taskCreateHook ti_sysbios_utils_Load_taskCreateHook
#define Load_taskDeleteHook ti_sysbios_utils_Load_taskDeleteHook
#define Load_taskSwitchHook ti_sysbios_utils_Load_taskSwitchHook
#define Load_swiBeginHook ti_sysbios_utils_Load_swiBeginHook
#define Load_swiEndHook ti_sysbios_utils_Load_swiEndHook
#define Load_hwiBeginHook ti_sysbios_utils_Load_hwiBeginHook
#define Load_hwiEndHook ti_sysbios_utils_Load_hwiEndHook
#define Load_taskRegHook ti_sysbios_utils_Load_taskRegHook
#define Load_Module_name ti_sysbios_utils_Load_Module_name
#define Load_Module_id ti_sysbios_utils_Load_Module_id
#define Load_Module_startup ti_sysbios_utils_Load_Module_startup
#define Load_Module_startupDone ti_sysbios_utils_Load_Module_startupDone
#define Load_Module_hasMask ti_sysbios_utils_Load_Module_hasMask
#define Load_Module_getMask ti_sysbios_utils_Load_Module_getMask
#define Load_Module_setMask ti_sysbios_utils_Load_Module_setMask
#define Load_Object_heap ti_sysbios_utils_Load_Object_heap
#define Load_Module_heap ti_sysbios_utils_Load_Module_heap

#endif /* ti_sysbios_utils_Load__localnames__done */
#endif
