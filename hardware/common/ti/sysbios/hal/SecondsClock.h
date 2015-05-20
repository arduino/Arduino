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

#ifndef ti_sysbios_hal_SecondsClock__include
#define ti_sysbios_hal_SecondsClock__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_hal_SecondsClock__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_hal_SecondsClock___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/hal/package/package.defs.h>

#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/interfaces/ISeconds.h>


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
typedef xdc_Bits32 CT__ti_sysbios_hal_SecondsClock_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__diagsEnabled ti_sysbios_hal_SecondsClock_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_hal_SecondsClock_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__diagsIncluded ti_sysbios_hal_SecondsClock_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_hal_SecondsClock_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__diagsMask ti_sysbios_hal_SecondsClock_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_hal_SecondsClock_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__gateObj ti_sysbios_hal_SecondsClock_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_hal_SecondsClock_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__gatePrms ti_sysbios_hal_SecondsClock_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_hal_SecondsClock_Module__id;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__id ti_sysbios_hal_SecondsClock_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_hal_SecondsClock_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__loggerDefined ti_sysbios_hal_SecondsClock_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_hal_SecondsClock_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__loggerObj ti_sysbios_hal_SecondsClock_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn0 ti_sysbios_hal_SecondsClock_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn1 ti_sysbios_hal_SecondsClock_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn2 ti_sysbios_hal_SecondsClock_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn4 ti_sysbios_hal_SecondsClock_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__loggerFxn8 ti_sysbios_hal_SecondsClock_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_hal_SecondsClock_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Module__startupDoneFxn ti_sysbios_hal_SecondsClock_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_hal_SecondsClock_Object__count;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Object__count ti_sysbios_hal_SecondsClock_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_hal_SecondsClock_Object__heap;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Object__heap ti_sysbios_hal_SecondsClock_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_hal_SecondsClock_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Object__sizeof ti_sysbios_hal_SecondsClock_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_hal_SecondsClock_Object__table;
__extern __FAR__ const CT__ti_sysbios_hal_SecondsClock_Object__table ti_sysbios_hal_SecondsClock_Object__table__C;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_hal_SecondsClock_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_UInt32 (*get)(void);
    xdc_Void (*set)(xdc_UInt32);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_hal_SecondsClock_Fxns__ ti_sysbios_hal_SecondsClock_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_hal_SecondsClock_Module_startup ti_sysbios_hal_SecondsClock_Module_startup__E
xdc__CODESECT(ti_sysbios_hal_SecondsClock_Module_startup__E, "ti_sysbios_hal_SecondsClock_Module_startup")
__extern xdc_Int ti_sysbios_hal_SecondsClock_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_hal_SecondsClock_Module_startup__F, "ti_sysbios_hal_SecondsClock_Module_startup")
__extern xdc_Int ti_sysbios_hal_SecondsClock_Module_startup__F( xdc_Int state );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_hal_SecondsClock_Module__startupDone__S, "ti_sysbios_hal_SecondsClock_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_hal_SecondsClock_Module__startupDone__S( void );

/* get__E */
#define ti_sysbios_hal_SecondsClock_get ti_sysbios_hal_SecondsClock_get__E
xdc__CODESECT(ti_sysbios_hal_SecondsClock_get__E, "ti_sysbios_hal_SecondsClock_get")
__extern xdc_UInt32 ti_sysbios_hal_SecondsClock_get__E( void );

/* set__E */
#define ti_sysbios_hal_SecondsClock_set ti_sysbios_hal_SecondsClock_set__E
xdc__CODESECT(ti_sysbios_hal_SecondsClock_set__E, "ti_sysbios_hal_SecondsClock_set")
__extern xdc_Void ti_sysbios_hal_SecondsClock_set__E( xdc_UInt32 seconds );

/* increment__I */
#define ti_sysbios_hal_SecondsClock_increment ti_sysbios_hal_SecondsClock_increment__I
xdc__CODESECT(ti_sysbios_hal_SecondsClock_increment__I, "ti_sysbios_hal_SecondsClock_increment")
__extern xdc_Void ti_sysbios_hal_SecondsClock_increment__I( xdc_UArg arg );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_ISeconds_Module ti_sysbios_hal_SecondsClock_Module_upCast( void )
{
    return (ti_sysbios_interfaces_ISeconds_Module)&ti_sysbios_hal_SecondsClock_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_ISeconds */
#define ti_sysbios_hal_SecondsClock_Module_to_ti_sysbios_interfaces_ISeconds ti_sysbios_hal_SecondsClock_Module_upCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_hal_SecondsClock_Module_startupDone() ti_sysbios_hal_SecondsClock_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_hal_SecondsClock_Object_heap() ti_sysbios_hal_SecondsClock_Object__heap__C

/* Module_heap */
#define ti_sysbios_hal_SecondsClock_Module_heap() ti_sysbios_hal_SecondsClock_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_hal_SecondsClock_Module__id ti_sysbios_hal_SecondsClock_Module_id( void ) 
{
    return ti_sysbios_hal_SecondsClock_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_hal_SecondsClock_Module_hasMask( void ) 
{
    return ti_sysbios_hal_SecondsClock_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_hal_SecondsClock_Module_getMask( void ) 
{
    return ti_sysbios_hal_SecondsClock_Module__diagsMask__C != NULL ? *ti_sysbios_hal_SecondsClock_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_hal_SecondsClock_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_hal_SecondsClock_Module__diagsMask__C != NULL) *ti_sysbios_hal_SecondsClock_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_hal_SecondsClock__top__
#undef __nested__
#endif

#endif /* ti_sysbios_hal_SecondsClock__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_hal_SecondsClock__internalaccess))

#ifndef ti_sysbios_hal_SecondsClock__include_state
#define ti_sysbios_hal_SecondsClock__include_state

/* Module_State */
struct ti_sysbios_hal_SecondsClock_Module_State {
    xdc_UInt32 seconds;
    xdc_UInt32 c1;
    xdc_UInt32 c2;
    xdc_Int32 c1Inc;
    xdc_UInt32 count1;
    xdc_UInt32 count2;
    char __dummy;
};

/* Module__state__V */
extern struct ti_sysbios_hal_SecondsClock_Module_State__ ti_sysbios_hal_SecondsClock_Module__state__V;

/* Module_State_clock */
__extern __FAR__ const xdc_SizeT ti_sysbios_hal_SecondsClock_Module_State_clock__O;
static inline ti_sysbios_knl_Clock_Handle ti_sysbios_hal_SecondsClock_Module_State_clock()
{
    return (ti_sysbios_knl_Clock_Handle)(((char*)&ti_sysbios_hal_SecondsClock_Module__state__V) + ti_sysbios_hal_SecondsClock_Module_State_clock__O);
}

#endif /* ti_sysbios_hal_SecondsClock__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_hal_SecondsClock__nolocalnames)

#ifndef ti_sysbios_hal_SecondsClock__localnames__done
#define ti_sysbios_hal_SecondsClock__localnames__done

/* module prefix */
#define SecondsClock_Module_State ti_sysbios_hal_SecondsClock_Module_State
#define SecondsClock_Module_State_clock ti_sysbios_hal_SecondsClock_Module_State_clock
#define SecondsClock_get ti_sysbios_hal_SecondsClock_get
#define SecondsClock_set ti_sysbios_hal_SecondsClock_set
#define SecondsClock_Module_name ti_sysbios_hal_SecondsClock_Module_name
#define SecondsClock_Module_id ti_sysbios_hal_SecondsClock_Module_id
#define SecondsClock_Module_startup ti_sysbios_hal_SecondsClock_Module_startup
#define SecondsClock_Module_startupDone ti_sysbios_hal_SecondsClock_Module_startupDone
#define SecondsClock_Module_hasMask ti_sysbios_hal_SecondsClock_Module_hasMask
#define SecondsClock_Module_getMask ti_sysbios_hal_SecondsClock_Module_getMask
#define SecondsClock_Module_setMask ti_sysbios_hal_SecondsClock_Module_setMask
#define SecondsClock_Object_heap ti_sysbios_hal_SecondsClock_Object_heap
#define SecondsClock_Module_heap ti_sysbios_hal_SecondsClock_Module_heap
#define SecondsClock_Module_upCast ti_sysbios_hal_SecondsClock_Module_upCast
#define SecondsClock_Module_to_ti_sysbios_interfaces_ISeconds ti_sysbios_hal_SecondsClock_Module_to_ti_sysbios_interfaces_ISeconds

#endif /* ti_sysbios_hal_SecondsClock__localnames__done */
#endif
