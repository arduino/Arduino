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

#ifndef ti_sysbios_hal_CoreNull__include
#define ti_sysbios_hal_CoreNull__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_hal_CoreNull__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_hal_CoreNull___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/hal/package/package.defs.h>

#include <ti/sysbios/interfaces/ICore.h>


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
typedef xdc_Bits32 CT__ti_sysbios_hal_CoreNull_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__diagsEnabled ti_sysbios_hal_CoreNull_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_hal_CoreNull_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__diagsIncluded ti_sysbios_hal_CoreNull_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_hal_CoreNull_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__diagsMask ti_sysbios_hal_CoreNull_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_hal_CoreNull_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__gateObj ti_sysbios_hal_CoreNull_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_hal_CoreNull_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__gatePrms ti_sysbios_hal_CoreNull_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_hal_CoreNull_Module__id;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__id ti_sysbios_hal_CoreNull_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_hal_CoreNull_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__loggerDefined ti_sysbios_hal_CoreNull_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_hal_CoreNull_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__loggerObj ti_sysbios_hal_CoreNull_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_hal_CoreNull_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__loggerFxn0 ti_sysbios_hal_CoreNull_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_hal_CoreNull_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__loggerFxn1 ti_sysbios_hal_CoreNull_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_hal_CoreNull_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__loggerFxn2 ti_sysbios_hal_CoreNull_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_hal_CoreNull_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__loggerFxn4 ti_sysbios_hal_CoreNull_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_hal_CoreNull_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__loggerFxn8 ti_sysbios_hal_CoreNull_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_hal_CoreNull_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Module__startupDoneFxn ti_sysbios_hal_CoreNull_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_hal_CoreNull_Object__count;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Object__count ti_sysbios_hal_CoreNull_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_hal_CoreNull_Object__heap;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Object__heap ti_sysbios_hal_CoreNull_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_hal_CoreNull_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Object__sizeof ti_sysbios_hal_CoreNull_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_hal_CoreNull_Object__table;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_Object__table ti_sysbios_hal_CoreNull_Object__table__C;

/* numCores */
#ifdef ti_sysbios_hal_CoreNull_numCores__D
#define ti_sysbios_hal_CoreNull_numCores (ti_sysbios_hal_CoreNull_numCores__D)
#else
#define ti_sysbios_hal_CoreNull_numCores (ti_sysbios_hal_CoreNull_numCores__C)
typedef xdc_UInt CT__ti_sysbios_hal_CoreNull_numCores;
__extern __FAR__ const CT__ti_sysbios_hal_CoreNull_numCores ti_sysbios_hal_CoreNull_numCores__C;
#endif


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_hal_CoreNull_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_UInt (*getId)(void);
    xdc_Void (*interruptCore)(xdc_UInt);
    xdc_IArg (*lock)(void);
    xdc_Void (*unlock)(void);
    xdc_UInt (*hwiDisable)(void);
    xdc_UInt (*hwiEnable)(void);
    xdc_Void (*hwiRestore)(xdc_UInt);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_hal_CoreNull_Fxns__ ti_sysbios_hal_CoreNull_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_hal_CoreNull_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_hal_CoreNull_Module__startupDone__S, "ti_sysbios_hal_CoreNull_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_hal_CoreNull_Module__startupDone__S( void );

/* getId__E */
#define ti_sysbios_hal_CoreNull_getId ti_sysbios_hal_CoreNull_getId__E
xdc__CODESECT(ti_sysbios_hal_CoreNull_getId__E, "ti_sysbios_hal_CoreNull_getId")
__extern xdc_UInt ti_sysbios_hal_CoreNull_getId__E( void );

/* interruptCore__E */
#define ti_sysbios_hal_CoreNull_interruptCore ti_sysbios_hal_CoreNull_interruptCore__E
xdc__CODESECT(ti_sysbios_hal_CoreNull_interruptCore__E, "ti_sysbios_hal_CoreNull_interruptCore")
__extern xdc_Void ti_sysbios_hal_CoreNull_interruptCore__E( xdc_UInt coreId );

/* lock__E */
#define ti_sysbios_hal_CoreNull_lock ti_sysbios_hal_CoreNull_lock__E
xdc__CODESECT(ti_sysbios_hal_CoreNull_lock__E, "ti_sysbios_hal_CoreNull_lock")
__extern xdc_IArg ti_sysbios_hal_CoreNull_lock__E( void );

/* unlock__E */
#define ti_sysbios_hal_CoreNull_unlock ti_sysbios_hal_CoreNull_unlock__E
xdc__CODESECT(ti_sysbios_hal_CoreNull_unlock__E, "ti_sysbios_hal_CoreNull_unlock")
__extern xdc_Void ti_sysbios_hal_CoreNull_unlock__E( void );

/* hwiDisable__E */
#define ti_sysbios_hal_CoreNull_hwiDisable ti_sysbios_hal_CoreNull_hwiDisable__E
xdc__CODESECT(ti_sysbios_hal_CoreNull_hwiDisable__E, "ti_sysbios_hal_CoreNull_hwiDisable")
__extern xdc_UInt ti_sysbios_hal_CoreNull_hwiDisable__E( void );

/* hwiEnable__E */
#define ti_sysbios_hal_CoreNull_hwiEnable ti_sysbios_hal_CoreNull_hwiEnable__E
xdc__CODESECT(ti_sysbios_hal_CoreNull_hwiEnable__E, "ti_sysbios_hal_CoreNull_hwiEnable")
__extern xdc_UInt ti_sysbios_hal_CoreNull_hwiEnable__E( void );

/* hwiRestore__E */
#define ti_sysbios_hal_CoreNull_hwiRestore ti_sysbios_hal_CoreNull_hwiRestore__E
xdc__CODESECT(ti_sysbios_hal_CoreNull_hwiRestore__E, "ti_sysbios_hal_CoreNull_hwiRestore")
__extern xdc_Void ti_sysbios_hal_CoreNull_hwiRestore__E( xdc_UInt key );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_ICore_Module ti_sysbios_hal_CoreNull_Module_upCast( void )
{
    return (ti_sysbios_interfaces_ICore_Module)&ti_sysbios_hal_CoreNull_Module__FXNS__C;
}

/* Module_to_ti_sysbios_interfaces_ICore */
#define ti_sysbios_hal_CoreNull_Module_to_ti_sysbios_interfaces_ICore ti_sysbios_hal_CoreNull_Module_upCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_hal_CoreNull_Module_startupDone() ti_sysbios_hal_CoreNull_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_hal_CoreNull_Object_heap() ti_sysbios_hal_CoreNull_Object__heap__C

/* Module_heap */
#define ti_sysbios_hal_CoreNull_Module_heap() ti_sysbios_hal_CoreNull_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_hal_CoreNull_Module__id ti_sysbios_hal_CoreNull_Module_id( void ) 
{
    return ti_sysbios_hal_CoreNull_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_hal_CoreNull_Module_hasMask( void ) 
{
    return ti_sysbios_hal_CoreNull_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_hal_CoreNull_Module_getMask( void ) 
{
    return ti_sysbios_hal_CoreNull_Module__diagsMask__C != NULL ? *ti_sysbios_hal_CoreNull_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_hal_CoreNull_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_hal_CoreNull_Module__diagsMask__C != NULL) *ti_sysbios_hal_CoreNull_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_hal_CoreNull__top__
#undef __nested__
#endif

#endif /* ti_sysbios_hal_CoreNull__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_hal_CoreNull__internalaccess))

#ifndef ti_sysbios_hal_CoreNull__include_state
#define ti_sysbios_hal_CoreNull__include_state


#endif /* ti_sysbios_hal_CoreNull__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_hal_CoreNull__nolocalnames)

#ifndef ti_sysbios_hal_CoreNull__localnames__done
#define ti_sysbios_hal_CoreNull__localnames__done

/* module prefix */
#define CoreNull_numCores ti_sysbios_hal_CoreNull_numCores
#define CoreNull_getId ti_sysbios_hal_CoreNull_getId
#define CoreNull_interruptCore ti_sysbios_hal_CoreNull_interruptCore
#define CoreNull_lock ti_sysbios_hal_CoreNull_lock
#define CoreNull_unlock ti_sysbios_hal_CoreNull_unlock
#define CoreNull_hwiDisable ti_sysbios_hal_CoreNull_hwiDisable
#define CoreNull_hwiEnable ti_sysbios_hal_CoreNull_hwiEnable
#define CoreNull_hwiRestore ti_sysbios_hal_CoreNull_hwiRestore
#define CoreNull_Module_name ti_sysbios_hal_CoreNull_Module_name
#define CoreNull_Module_id ti_sysbios_hal_CoreNull_Module_id
#define CoreNull_Module_startup ti_sysbios_hal_CoreNull_Module_startup
#define CoreNull_Module_startupDone ti_sysbios_hal_CoreNull_Module_startupDone
#define CoreNull_Module_hasMask ti_sysbios_hal_CoreNull_Module_hasMask
#define CoreNull_Module_getMask ti_sysbios_hal_CoreNull_Module_getMask
#define CoreNull_Module_setMask ti_sysbios_hal_CoreNull_Module_setMask
#define CoreNull_Object_heap ti_sysbios_hal_CoreNull_Object_heap
#define CoreNull_Module_heap ti_sysbios_hal_CoreNull_Module_heap
#define CoreNull_Module_upCast ti_sysbios_hal_CoreNull_Module_upCast
#define CoreNull_Module_to_ti_sysbios_interfaces_ICore ti_sysbios_hal_CoreNull_Module_to_ti_sysbios_interfaces_ICore

#endif /* ti_sysbios_hal_CoreNull__localnames__done */
#endif
