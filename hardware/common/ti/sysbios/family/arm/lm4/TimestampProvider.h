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
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     STATE STRUCTURES
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef ti_sysbios_family_arm_lm4_TimestampProvider__include
#define ti_sysbios_family_arm_lm4_TimestampProvider__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_lm4_TimestampProvider__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_lm4_TimestampProvider___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/family/arm/lm4/package/package.defs.h>

#include <ti/sysbios/interfaces/ITimestamp.h>
#include <ti/sysbios/family/arm/lm4/Timer.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsEnabled ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsIncluded ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__gateObj ti_sysbios_family_arm_lm4_TimestampProvider_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__gatePrms ti_sysbios_family_arm_lm4_TimestampProvider_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__id ti_sysbios_family_arm_lm4_TimestampProvider_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerDefined ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerObj ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn0 ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn1 ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn2 ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn4 ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn8 ti_sysbios_family_arm_lm4_TimestampProvider_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__startupDoneFxn ti_sysbios_family_arm_lm4_TimestampProvider_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__count ti_sysbios_family_arm_lm4_TimestampProvider_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__heap ti_sysbios_family_arm_lm4_TimestampProvider_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__sizeof ti_sysbios_family_arm_lm4_TimestampProvider_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_Object__table ti_sysbios_family_arm_lm4_TimestampProvider_Object__table__C;

/* useClockTimer */
#ifdef ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer__D
#define ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer (ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer__D)
#else
#define ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer (ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer__C)
typedef xdc_Bool CT__ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer__C;
#endif

/* timerId */
#ifdef ti_sysbios_family_arm_lm4_TimestampProvider_timerId__D
#define ti_sysbios_family_arm_lm4_TimestampProvider_timerId (ti_sysbios_family_arm_lm4_TimestampProvider_timerId__D)
#else
#define ti_sysbios_family_arm_lm4_TimestampProvider_timerId (ti_sysbios_family_arm_lm4_TimestampProvider_timerId__C)
typedef xdc_UInt CT__ti_sysbios_family_arm_lm4_TimestampProvider_timerId;
__extern __FAR__ const CT__ti_sysbios_family_arm_lm4_TimestampProvider_timerId ti_sysbios_family_arm_lm4_TimestampProvider_timerId__C;
#endif


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_family_arm_lm4_TimestampProvider_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bits32 (*get32)(void);
    xdc_Void (*get64)(xdc_runtime_Types_Timestamp64*);
    xdc_Void (*getFreq)(xdc_runtime_Types_FreqHz*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_family_arm_lm4_TimestampProvider_Fxns__ ti_sysbios_family_arm_lm4_TimestampProvider_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup__E
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup__E, "ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup__F, "ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup__F( xdc_Int state );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_Module__startupDone__S, "ti_sysbios_family_arm_lm4_TimestampProvider_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_family_arm_lm4_TimestampProvider_Module__startupDone__S( void );

/* get32__E */
#define ti_sysbios_family_arm_lm4_TimestampProvider_get32 ti_sysbios_family_arm_lm4_TimestampProvider_get32__E
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_get32__E, "ti_sysbios_family_arm_lm4_TimestampProvider_get32")
__extern xdc_Bits32 ti_sysbios_family_arm_lm4_TimestampProvider_get32__E( void );

/* get64__E */
#define ti_sysbios_family_arm_lm4_TimestampProvider_get64 ti_sysbios_family_arm_lm4_TimestampProvider_get64__E
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_get64__E, "ti_sysbios_family_arm_lm4_TimestampProvider_get64")
__extern xdc_Void ti_sysbios_family_arm_lm4_TimestampProvider_get64__E( xdc_runtime_Types_Timestamp64 *result );

/* getFreq__E */
#define ti_sysbios_family_arm_lm4_TimestampProvider_getFreq ti_sysbios_family_arm_lm4_TimestampProvider_getFreq__E
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_getFreq__E, "ti_sysbios_family_arm_lm4_TimestampProvider_getFreq")
__extern xdc_Void ti_sysbios_family_arm_lm4_TimestampProvider_getFreq__E( xdc_runtime_Types_FreqHz *freq );

/* startTimer__E */
#define ti_sysbios_family_arm_lm4_TimestampProvider_startTimer ti_sysbios_family_arm_lm4_TimestampProvider_startTimer__E
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_startTimer__E, "ti_sysbios_family_arm_lm4_TimestampProvider_startTimer")
__extern xdc_Void ti_sysbios_family_arm_lm4_TimestampProvider_startTimer__E( void );

/* rolloverFunc__E */
#define ti_sysbios_family_arm_lm4_TimestampProvider_rolloverFunc ti_sysbios_family_arm_lm4_TimestampProvider_rolloverFunc__E
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_rolloverFunc__E, "ti_sysbios_family_arm_lm4_TimestampProvider_rolloverFunc")
__extern xdc_Void ti_sysbios_family_arm_lm4_TimestampProvider_rolloverFunc__E( xdc_UArg unused );

/* initTimerHandle__I */
#define ti_sysbios_family_arm_lm4_TimestampProvider_initTimerHandle ti_sysbios_family_arm_lm4_TimestampProvider_initTimerHandle__I
xdc__CODESECT(ti_sysbios_family_arm_lm4_TimestampProvider_initTimerHandle__I, "ti_sysbios_family_arm_lm4_TimestampProvider_initTimerHandle")
__extern xdc_Void ti_sysbios_family_arm_lm4_TimestampProvider_initTimerHandle__I( void );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_ITimestamp_Module ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast( void )
{
    return (ti_sysbios_interfaces_ITimestamp_Module)&ti_sysbios_family_arm_lm4_TimestampProvider_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_ITimestamp */
#define ti_sysbios_family_arm_lm4_TimestampProvider_Module_to_ti_sysbios_interfaces_ITimestamp ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast

/* Module_upCast2 */
static inline xdc_runtime_ITimestampProvider_Module ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast2( void )
{
    return (xdc_runtime_ITimestampProvider_Module)&ti_sysbios_family_arm_lm4_TimestampProvider_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampProvider */
#define ti_sysbios_family_arm_lm4_TimestampProvider_Module_to_xdc_runtime_ITimestampProvider ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast2

/* Module_upCast3 */
static inline xdc_runtime_ITimestampClient_Module ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast3( void )
{
    return (xdc_runtime_ITimestampClient_Module)&ti_sysbios_family_arm_lm4_TimestampProvider_Module__FXNS__C;
}

/* Module_to_xdc_runtime_ITimestampClient */
#define ti_sysbios_family_arm_lm4_TimestampProvider_Module_to_xdc_runtime_ITimestampClient ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast3


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_lm4_TimestampProvider_Module_startupDone() ti_sysbios_family_arm_lm4_TimestampProvider_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_lm4_TimestampProvider_Object_heap() ti_sysbios_family_arm_lm4_TimestampProvider_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_lm4_TimestampProvider_Module_heap() ti_sysbios_family_arm_lm4_TimestampProvider_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_lm4_TimestampProvider_Module__id ti_sysbios_family_arm_lm4_TimestampProvider_Module_id( void ) 
{
    return ti_sysbios_family_arm_lm4_TimestampProvider_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_lm4_TimestampProvider_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_lm4_TimestampProvider_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_lm4_TimestampProvider_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_lm4_TimestampProvider_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_lm4_TimestampProvider__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_lm4_TimestampProvider__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_lm4_TimestampProvider__internalaccess))

#ifndef ti_sysbios_family_arm_lm4_TimestampProvider__include_state
#define ti_sysbios_family_arm_lm4_TimestampProvider__include_state

/* Module_State */
struct ti_sysbios_family_arm_lm4_TimestampProvider_Module_State {
    ti_sysbios_family_arm_lm4_Timer_Handle timer;
    volatile xdc_UInt32 hi;
};

/* Module__state__V */
extern struct ti_sysbios_family_arm_lm4_TimestampProvider_Module_State__ ti_sysbios_family_arm_lm4_TimestampProvider_Module__state__V;

#endif /* ti_sysbios_family_arm_lm4_TimestampProvider__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_lm4_TimestampProvider__nolocalnames)

#ifndef ti_sysbios_family_arm_lm4_TimestampProvider__localnames__done
#define ti_sysbios_family_arm_lm4_TimestampProvider__localnames__done

/* module prefix */
#define TimestampProvider_Module_State ti_sysbios_family_arm_lm4_TimestampProvider_Module_State
#define TimestampProvider_useClockTimer ti_sysbios_family_arm_lm4_TimestampProvider_useClockTimer
#define TimestampProvider_timerId ti_sysbios_family_arm_lm4_TimestampProvider_timerId
#define TimestampProvider_get32 ti_sysbios_family_arm_lm4_TimestampProvider_get32
#define TimestampProvider_get64 ti_sysbios_family_arm_lm4_TimestampProvider_get64
#define TimestampProvider_getFreq ti_sysbios_family_arm_lm4_TimestampProvider_getFreq
#define TimestampProvider_startTimer ti_sysbios_family_arm_lm4_TimestampProvider_startTimer
#define TimestampProvider_rolloverFunc ti_sysbios_family_arm_lm4_TimestampProvider_rolloverFunc
#define TimestampProvider_Module_name ti_sysbios_family_arm_lm4_TimestampProvider_Module_name
#define TimestampProvider_Module_id ti_sysbios_family_arm_lm4_TimestampProvider_Module_id
#define TimestampProvider_Module_startup ti_sysbios_family_arm_lm4_TimestampProvider_Module_startup
#define TimestampProvider_Module_startupDone ti_sysbios_family_arm_lm4_TimestampProvider_Module_startupDone
#define TimestampProvider_Module_hasMask ti_sysbios_family_arm_lm4_TimestampProvider_Module_hasMask
#define TimestampProvider_Module_getMask ti_sysbios_family_arm_lm4_TimestampProvider_Module_getMask
#define TimestampProvider_Module_setMask ti_sysbios_family_arm_lm4_TimestampProvider_Module_setMask
#define TimestampProvider_Object_heap ti_sysbios_family_arm_lm4_TimestampProvider_Object_heap
#define TimestampProvider_Module_heap ti_sysbios_family_arm_lm4_TimestampProvider_Module_heap
#define TimestampProvider_Module_upCast ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast
#define TimestampProvider_Module_to_ti_sysbios_interfaces_ITimestamp ti_sysbios_family_arm_lm4_TimestampProvider_Module_to_ti_sysbios_interfaces_ITimestamp
#define TimestampProvider_Module_upCast2 ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast2
#define TimestampProvider_Module_to_xdc_runtime_ITimestampProvider ti_sysbios_family_arm_lm4_TimestampProvider_Module_to_xdc_runtime_ITimestampProvider
#define TimestampProvider_Module_upCast3 ti_sysbios_family_arm_lm4_TimestampProvider_Module_upCast3
#define TimestampProvider_Module_to_xdc_runtime_ITimestampClient ti_sysbios_family_arm_lm4_TimestampProvider_Module_to_xdc_runtime_ITimestampClient

#endif /* ti_sysbios_family_arm_lm4_TimestampProvider__localnames__done */
#endif
