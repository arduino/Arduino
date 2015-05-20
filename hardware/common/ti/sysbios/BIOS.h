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

#ifndef ti_sysbios_BIOS__include
#define ti_sysbios_BIOS__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_BIOS__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_BIOS___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/BIOS__prologue.h>
#include <ti/sysbios/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IModule.h>
#include <xdc/runtime/IGateProvider.h>
#include <ti/sysbios/package/BIOS_RtsGateProxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* ThreadType */
enum ti_sysbios_BIOS_ThreadType {
    ti_sysbios_BIOS_ThreadType_Hwi,
    ti_sysbios_BIOS_ThreadType_Swi,
    ti_sysbios_BIOS_ThreadType_Task,
    ti_sysbios_BIOS_ThreadType_Main
};
typedef enum ti_sysbios_BIOS_ThreadType ti_sysbios_BIOS_ThreadType;

/* RtsLockType */
enum ti_sysbios_BIOS_RtsLockType {
    ti_sysbios_BIOS_NoLocking,
    ti_sysbios_BIOS_GateHwi,
    ti_sysbios_BIOS_GateSwi,
    ti_sysbios_BIOS_GateMutex,
    ti_sysbios_BIOS_GateMutexPri
};
typedef enum ti_sysbios_BIOS_RtsLockType ti_sysbios_BIOS_RtsLockType;

/* LibType */
enum ti_sysbios_BIOS_LibType {
    ti_sysbios_BIOS_LibType_Instrumented,
    ti_sysbios_BIOS_LibType_NonInstrumented,
    ti_sysbios_BIOS_LibType_Custom,
    ti_sysbios_BIOS_LibType_Debug
};
typedef enum ti_sysbios_BIOS_LibType ti_sysbios_BIOS_LibType;

/* WAIT_FOREVER */
#define ti_sysbios_BIOS_WAIT_FOREVER (~(0))

/* NO_WAIT */
#define ti_sysbios_BIOS_NO_WAIT (0)

/* StartupFuncPtr */
typedef xdc_Void (*ti_sysbios_BIOS_StartupFuncPtr)(xdc_Void);


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* intSize */
struct ti_sysbios_BIOS_intSize {
    xdc_Int intSize;
};

/* StartFuncPtr */
typedef xdc_Void (*ti_sysbios_BIOS_StartFuncPtr)(xdc_Void);

/* ExitFuncPtr */
typedef xdc_Void (*ti_sysbios_BIOS_ExitFuncPtr)(xdc_Int);

/* Module_State */
typedef ti_sysbios_BIOS_ThreadType __T1_ti_sysbios_BIOS_Module_State__smpThreadType;
typedef ti_sysbios_BIOS_ThreadType *__ARRAY1_ti_sysbios_BIOS_Module_State__smpThreadType;
typedef __ARRAY1_ti_sysbios_BIOS_Module_State__smpThreadType __TA_ti_sysbios_BIOS_Module_State__smpThreadType;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_BIOS_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__diagsEnabled ti_sysbios_BIOS_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_BIOS_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__diagsIncluded ti_sysbios_BIOS_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_BIOS_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__diagsMask ti_sysbios_BIOS_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_BIOS_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__gateObj ti_sysbios_BIOS_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_BIOS_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__gatePrms ti_sysbios_BIOS_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_BIOS_Module__id;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_BIOS_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__loggerDefined ti_sysbios_BIOS_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_BIOS_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__loggerObj ti_sysbios_BIOS_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_BIOS_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn0 ti_sysbios_BIOS_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_BIOS_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn1 ti_sysbios_BIOS_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_BIOS_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn2 ti_sysbios_BIOS_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_BIOS_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn4 ti_sysbios_BIOS_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_BIOS_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__loggerFxn8 ti_sysbios_BIOS_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_BIOS_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_BIOS_Module__startupDoneFxn ti_sysbios_BIOS_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_BIOS_Object__count;
__extern __FAR__ const CT__ti_sysbios_BIOS_Object__count ti_sysbios_BIOS_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_BIOS_Object__heap;
__extern __FAR__ const CT__ti_sysbios_BIOS_Object__heap ti_sysbios_BIOS_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_BIOS_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_BIOS_Object__sizeof ti_sysbios_BIOS_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_BIOS_Object__table;
__extern __FAR__ const CT__ti_sysbios_BIOS_Object__table ti_sysbios_BIOS_Object__table__C;

/* smpEnabled */
#ifdef ti_sysbios_BIOS_smpEnabled__D
#define ti_sysbios_BIOS_smpEnabled (ti_sysbios_BIOS_smpEnabled__D)
#else
#define ti_sysbios_BIOS_smpEnabled (ti_sysbios_BIOS_smpEnabled__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_smpEnabled;
__extern __FAR__ const CT__ti_sysbios_BIOS_smpEnabled ti_sysbios_BIOS_smpEnabled__C;
#endif

/* cpuFreq */
#define ti_sysbios_BIOS_cpuFreq (ti_sysbios_BIOS_cpuFreq__C)
typedef xdc_runtime_Types_FreqHz CT__ti_sysbios_BIOS_cpuFreq;
__extern __FAR__ const CT__ti_sysbios_BIOS_cpuFreq ti_sysbios_BIOS_cpuFreq__C;

/* runtimeCreatesEnabled */
#ifdef ti_sysbios_BIOS_runtimeCreatesEnabled__D
#define ti_sysbios_BIOS_runtimeCreatesEnabled (ti_sysbios_BIOS_runtimeCreatesEnabled__D)
#else
#define ti_sysbios_BIOS_runtimeCreatesEnabled (ti_sysbios_BIOS_runtimeCreatesEnabled__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_runtimeCreatesEnabled;
__extern __FAR__ const CT__ti_sysbios_BIOS_runtimeCreatesEnabled ti_sysbios_BIOS_runtimeCreatesEnabled__C;
#endif

/* taskEnabled */
#ifdef ti_sysbios_BIOS_taskEnabled__D
#define ti_sysbios_BIOS_taskEnabled (ti_sysbios_BIOS_taskEnabled__D)
#else
#define ti_sysbios_BIOS_taskEnabled (ti_sysbios_BIOS_taskEnabled__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_taskEnabled;
__extern __FAR__ const CT__ti_sysbios_BIOS_taskEnabled ti_sysbios_BIOS_taskEnabled__C;
#endif

/* swiEnabled */
#ifdef ti_sysbios_BIOS_swiEnabled__D
#define ti_sysbios_BIOS_swiEnabled (ti_sysbios_BIOS_swiEnabled__D)
#else
#define ti_sysbios_BIOS_swiEnabled (ti_sysbios_BIOS_swiEnabled__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_swiEnabled;
__extern __FAR__ const CT__ti_sysbios_BIOS_swiEnabled ti_sysbios_BIOS_swiEnabled__C;
#endif

/* clockEnabled */
#ifdef ti_sysbios_BIOS_clockEnabled__D
#define ti_sysbios_BIOS_clockEnabled (ti_sysbios_BIOS_clockEnabled__D)
#else
#define ti_sysbios_BIOS_clockEnabled (ti_sysbios_BIOS_clockEnabled__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_clockEnabled;
__extern __FAR__ const CT__ti_sysbios_BIOS_clockEnabled ti_sysbios_BIOS_clockEnabled__C;
#endif

/* heapSize */
#ifdef ti_sysbios_BIOS_heapSize__D
#define ti_sysbios_BIOS_heapSize (ti_sysbios_BIOS_heapSize__D)
#else
#define ti_sysbios_BIOS_heapSize (ti_sysbios_BIOS_heapSize__C)
typedef xdc_SizeT CT__ti_sysbios_BIOS_heapSize;
__extern __FAR__ const CT__ti_sysbios_BIOS_heapSize ti_sysbios_BIOS_heapSize__C;
#endif

/* heapSection */
#define ti_sysbios_BIOS_heapSection (ti_sysbios_BIOS_heapSection__C)
typedef xdc_String CT__ti_sysbios_BIOS_heapSection;
__extern __FAR__ const CT__ti_sysbios_BIOS_heapSection ti_sysbios_BIOS_heapSection__C;

/* heapTrackEnabled */
#ifdef ti_sysbios_BIOS_heapTrackEnabled__D
#define ti_sysbios_BIOS_heapTrackEnabled (ti_sysbios_BIOS_heapTrackEnabled__D)
#else
#define ti_sysbios_BIOS_heapTrackEnabled (ti_sysbios_BIOS_heapTrackEnabled__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_heapTrackEnabled;
__extern __FAR__ const CT__ti_sysbios_BIOS_heapTrackEnabled ti_sysbios_BIOS_heapTrackEnabled__C;
#endif

/* setupSecureContext */
#ifdef ti_sysbios_BIOS_setupSecureContext__D
#define ti_sysbios_BIOS_setupSecureContext (ti_sysbios_BIOS_setupSecureContext__D)
#else
#define ti_sysbios_BIOS_setupSecureContext (ti_sysbios_BIOS_setupSecureContext__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_setupSecureContext;
__extern __FAR__ const CT__ti_sysbios_BIOS_setupSecureContext ti_sysbios_BIOS_setupSecureContext__C;
#endif

/* useSK */
#ifdef ti_sysbios_BIOS_useSK__D
#define ti_sysbios_BIOS_useSK (ti_sysbios_BIOS_useSK__D)
#else
#define ti_sysbios_BIOS_useSK (ti_sysbios_BIOS_useSK__C)
typedef xdc_Bool CT__ti_sysbios_BIOS_useSK;
__extern __FAR__ const CT__ti_sysbios_BIOS_useSK ti_sysbios_BIOS_useSK__C;
#endif

/* installedErrorHook */
#define ti_sysbios_BIOS_installedErrorHook (ti_sysbios_BIOS_installedErrorHook__C)
typedef xdc_Void (*CT__ti_sysbios_BIOS_installedErrorHook)(xdc_runtime_Error_Block*);
__extern __FAR__ const CT__ti_sysbios_BIOS_installedErrorHook ti_sysbios_BIOS_installedErrorHook__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_BIOS_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_BIOS_Module__startupDone__S, "ti_sysbios_BIOS_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_BIOS_Module__startupDone__S( void );

/* start__E */
#define ti_sysbios_BIOS_start ti_sysbios_BIOS_start__E
xdc__CODESECT(ti_sysbios_BIOS_start__E, "ti_sysbios_BIOS_start")
__extern xdc_Void ti_sysbios_BIOS_start__E( void );

/* exit__E */
#define ti_sysbios_BIOS_exit ti_sysbios_BIOS_exit__E
xdc__CODESECT(ti_sysbios_BIOS_exit__E, "ti_sysbios_BIOS_exit")
__extern xdc_Void ti_sysbios_BIOS_exit__E( xdc_Int stat );

/* getThreadType__E */
#define ti_sysbios_BIOS_getThreadType ti_sysbios_BIOS_getThreadType__E
xdc__CODESECT(ti_sysbios_BIOS_getThreadType__E, "ti_sysbios_BIOS_getThreadType")
__extern ti_sysbios_BIOS_ThreadType ti_sysbios_BIOS_getThreadType__E( void );

/* setThreadType__E */
#define ti_sysbios_BIOS_setThreadType ti_sysbios_BIOS_setThreadType__E
xdc__CODESECT(ti_sysbios_BIOS_setThreadType__E, "ti_sysbios_BIOS_setThreadType")
__extern ti_sysbios_BIOS_ThreadType ti_sysbios_BIOS_setThreadType__E( ti_sysbios_BIOS_ThreadType ttype );

/* setCpuFreq__E */
#define ti_sysbios_BIOS_setCpuFreq ti_sysbios_BIOS_setCpuFreq__E
xdc__CODESECT(ti_sysbios_BIOS_setCpuFreq__E, "ti_sysbios_BIOS_setCpuFreq")
__extern xdc_Void ti_sysbios_BIOS_setCpuFreq__E( xdc_runtime_Types_FreqHz *freq );

/* getCpuFreq__E */
#define ti_sysbios_BIOS_getCpuFreq ti_sysbios_BIOS_getCpuFreq__E
xdc__CODESECT(ti_sysbios_BIOS_getCpuFreq__E, "ti_sysbios_BIOS_getCpuFreq")
__extern xdc_Void ti_sysbios_BIOS_getCpuFreq__E( xdc_runtime_Types_FreqHz *freq );

/* errorRaiseHook__I */
#define ti_sysbios_BIOS_errorRaiseHook ti_sysbios_BIOS_errorRaiseHook__I
xdc__CODESECT(ti_sysbios_BIOS_errorRaiseHook__I, "ti_sysbios_BIOS_errorRaiseHook")
__extern xdc_Void ti_sysbios_BIOS_errorRaiseHook__I( xdc_runtime_Error_Block *eb );

/* startFunc__I */
#define ti_sysbios_BIOS_startFunc ti_sysbios_BIOS_startFunc__I
xdc__CODESECT(ti_sysbios_BIOS_startFunc__I, "ti_sysbios_BIOS_startFunc")
__extern xdc_Void ti_sysbios_BIOS_startFunc__I( void );

/* atExitFunc__I */
#define ti_sysbios_BIOS_atExitFunc ti_sysbios_BIOS_atExitFunc__I
xdc__CODESECT(ti_sysbios_BIOS_atExitFunc__I, "ti_sysbios_BIOS_atExitFunc")
__extern xdc_Void ti_sysbios_BIOS_atExitFunc__I( xdc_Int stat );

/* exitFunc__I */
#define ti_sysbios_BIOS_exitFunc ti_sysbios_BIOS_exitFunc__I
xdc__CODESECT(ti_sysbios_BIOS_exitFunc__I, "ti_sysbios_BIOS_exitFunc")
__extern xdc_Void ti_sysbios_BIOS_exitFunc__I( xdc_Int stat );

/* registerRTSLock__I */
#define ti_sysbios_BIOS_registerRTSLock ti_sysbios_BIOS_registerRTSLock__I
xdc__CODESECT(ti_sysbios_BIOS_registerRTSLock__I, "ti_sysbios_BIOS_registerRTSLock")
__extern xdc_Void ti_sysbios_BIOS_registerRTSLock__I( void );

/* removeRTSLock__I */
#define ti_sysbios_BIOS_removeRTSLock ti_sysbios_BIOS_removeRTSLock__I
xdc__CODESECT(ti_sysbios_BIOS_removeRTSLock__I, "ti_sysbios_BIOS_removeRTSLock")
__extern xdc_Void ti_sysbios_BIOS_removeRTSLock__I( void );

/* rtsLock__I */
#define ti_sysbios_BIOS_rtsLock ti_sysbios_BIOS_rtsLock__I
xdc__CODESECT(ti_sysbios_BIOS_rtsLock__I, "ti_sysbios_BIOS_rtsLock")
__extern xdc_Void ti_sysbios_BIOS_rtsLock__I( void );

/* rtsUnlock__I */
#define ti_sysbios_BIOS_rtsUnlock ti_sysbios_BIOS_rtsUnlock__I
xdc__CODESECT(ti_sysbios_BIOS_rtsUnlock__I, "ti_sysbios_BIOS_rtsUnlock")
__extern xdc_Void ti_sysbios_BIOS_rtsUnlock__I( void );

/* nullFunc__I */
#define ti_sysbios_BIOS_nullFunc ti_sysbios_BIOS_nullFunc__I
xdc__CODESECT(ti_sysbios_BIOS_nullFunc__I, "ti_sysbios_BIOS_nullFunc")
__extern xdc_Void ti_sysbios_BIOS_nullFunc__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_BIOS_Module_startupDone() ti_sysbios_BIOS_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_BIOS_Object_heap() ti_sysbios_BIOS_Object__heap__C

/* Module_heap */
#define ti_sysbios_BIOS_Module_heap() ti_sysbios_BIOS_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_BIOS_Module__id ti_sysbios_BIOS_Module_id( void ) 
{
    return ti_sysbios_BIOS_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_BIOS_Module_hasMask( void ) 
{
    return ti_sysbios_BIOS_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_BIOS_Module_getMask( void ) 
{
    return ti_sysbios_BIOS_Module__diagsMask__C != NULL ? *ti_sysbios_BIOS_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_BIOS_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_BIOS_Module__diagsMask__C != NULL) *ti_sysbios_BIOS_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#include <ti/sysbios/BIOS__epilogue.h>

#ifdef ti_sysbios_BIOS__top__
#undef __nested__
#endif

#endif /* ti_sysbios_BIOS__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_BIOS__internalaccess))

#ifndef ti_sysbios_BIOS__include_state
#define ti_sysbios_BIOS__include_state

/* Module_State */
struct ti_sysbios_BIOS_Module_State {
    xdc_runtime_Types_FreqHz cpuFreq;
    xdc_UInt rtsGateCount;
    xdc_IArg rtsGateKey;
    ti_sysbios_BIOS_RtsGateProxy_Handle rtsGate;
    ti_sysbios_BIOS_ThreadType threadType;
    __TA_ti_sysbios_BIOS_Module_State__smpThreadType smpThreadType;
    volatile ti_sysbios_BIOS_StartFuncPtr startFunc;
    volatile ti_sysbios_BIOS_ExitFuncPtr exitFunc;
};

/* Module__state__V */
extern struct ti_sysbios_BIOS_Module_State__ ti_sysbios_BIOS_Module__state__V;

#endif /* ti_sysbios_BIOS__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_BIOS__nolocalnames)

#ifndef ti_sysbios_BIOS__localnames__done
#define ti_sysbios_BIOS__localnames__done

/* module prefix */
#define BIOS_ThreadType ti_sysbios_BIOS_ThreadType
#define BIOS_RtsLockType ti_sysbios_BIOS_RtsLockType
#define BIOS_LibType ti_sysbios_BIOS_LibType
#define BIOS_WAIT_FOREVER ti_sysbios_BIOS_WAIT_FOREVER
#define BIOS_NO_WAIT ti_sysbios_BIOS_NO_WAIT
#define BIOS_StartupFuncPtr ti_sysbios_BIOS_StartupFuncPtr
#define BIOS_intSize ti_sysbios_BIOS_intSize
#define BIOS_StartFuncPtr ti_sysbios_BIOS_StartFuncPtr
#define BIOS_ExitFuncPtr ti_sysbios_BIOS_ExitFuncPtr
#define BIOS_Module_State ti_sysbios_BIOS_Module_State
#define BIOS_ThreadType_Hwi ti_sysbios_BIOS_ThreadType_Hwi
#define BIOS_ThreadType_Swi ti_sysbios_BIOS_ThreadType_Swi
#define BIOS_ThreadType_Task ti_sysbios_BIOS_ThreadType_Task
#define BIOS_ThreadType_Main ti_sysbios_BIOS_ThreadType_Main
#define BIOS_NoLocking ti_sysbios_BIOS_NoLocking
#define BIOS_GateHwi ti_sysbios_BIOS_GateHwi
#define BIOS_GateSwi ti_sysbios_BIOS_GateSwi
#define BIOS_GateMutex ti_sysbios_BIOS_GateMutex
#define BIOS_GateMutexPri ti_sysbios_BIOS_GateMutexPri
#define BIOS_LibType_Instrumented ti_sysbios_BIOS_LibType_Instrumented
#define BIOS_LibType_NonInstrumented ti_sysbios_BIOS_LibType_NonInstrumented
#define BIOS_LibType_Custom ti_sysbios_BIOS_LibType_Custom
#define BIOS_LibType_Debug ti_sysbios_BIOS_LibType_Debug
#define BIOS_smpEnabled ti_sysbios_BIOS_smpEnabled
#define BIOS_cpuFreq ti_sysbios_BIOS_cpuFreq
#define BIOS_runtimeCreatesEnabled ti_sysbios_BIOS_runtimeCreatesEnabled
#define BIOS_taskEnabled ti_sysbios_BIOS_taskEnabled
#define BIOS_swiEnabled ti_sysbios_BIOS_swiEnabled
#define BIOS_clockEnabled ti_sysbios_BIOS_clockEnabled
#define BIOS_heapSize ti_sysbios_BIOS_heapSize
#define BIOS_heapSection ti_sysbios_BIOS_heapSection
#define BIOS_heapTrackEnabled ti_sysbios_BIOS_heapTrackEnabled
#define BIOS_setupSecureContext ti_sysbios_BIOS_setupSecureContext
#define BIOS_useSK ti_sysbios_BIOS_useSK
#define BIOS_installedErrorHook ti_sysbios_BIOS_installedErrorHook
#define BIOS_start ti_sysbios_BIOS_start
#define BIOS_exit ti_sysbios_BIOS_exit
#define BIOS_getThreadType ti_sysbios_BIOS_getThreadType
#define BIOS_setThreadType ti_sysbios_BIOS_setThreadType
#define BIOS_setCpuFreq ti_sysbios_BIOS_setCpuFreq
#define BIOS_getCpuFreq ti_sysbios_BIOS_getCpuFreq
#define BIOS_Module_name ti_sysbios_BIOS_Module_name
#define BIOS_Module_id ti_sysbios_BIOS_Module_id
#define BIOS_Module_startup ti_sysbios_BIOS_Module_startup
#define BIOS_Module_startupDone ti_sysbios_BIOS_Module_startupDone
#define BIOS_Module_hasMask ti_sysbios_BIOS_Module_hasMask
#define BIOS_Module_getMask ti_sysbios_BIOS_Module_getMask
#define BIOS_Module_setMask ti_sysbios_BIOS_Module_setMask
#define BIOS_Object_heap ti_sysbios_BIOS_Object_heap
#define BIOS_Module_heap ti_sysbios_BIOS_Module_heap

/* proxies */
#include <ti/sysbios/package/BIOS_RtsGateProxy.h>

#endif /* ti_sysbios_BIOS__localnames__done */
#endif
