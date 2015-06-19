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

#ifndef ti_sysbios_family_arm_msp432_ClockFreqs__include
#define ti_sysbios_family_arm_msp432_ClockFreqs__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_msp432_ClockFreqs__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_msp432_ClockFreqs___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/family/arm/msp432/package/package.defs.h>

#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Clock */
enum ti_sysbios_family_arm_msp432_ClockFreqs_Clock {
    ti_sysbios_family_arm_msp432_ClockFreqs_Clock_ACLK,
    ti_sysbios_family_arm_msp432_ClockFreqs_Clock_SMCLK,
    ti_sysbios_family_arm_msp432_ClockFreqs_Clock_HSMCLK
};
typedef enum ti_sysbios_family_arm_msp432_ClockFreqs_Clock ti_sysbios_family_arm_msp432_ClockFreqs_Clock;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsEnabled ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsIncluded ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__gateObj ti_sysbios_family_arm_msp432_ClockFreqs_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__gatePrms ti_sysbios_family_arm_msp432_ClockFreqs_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__id ti_sysbios_family_arm_msp432_ClockFreqs_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerDefined ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerObj ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn0 ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn1 ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn2 ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn4 ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn8 ti_sysbios_family_arm_msp432_ClockFreqs_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__startupDoneFxn ti_sysbios_family_arm_msp432_ClockFreqs_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__count ti_sysbios_family_arm_msp432_ClockFreqs_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__heap ti_sysbios_family_arm_msp432_ClockFreqs_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__sizeof ti_sysbios_family_arm_msp432_ClockFreqs_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_Object__table ti_sysbios_family_arm_msp432_ClockFreqs_Object__table__C;

/* ACLK */
#ifdef ti_sysbios_family_arm_msp432_ClockFreqs_ACLK__D
#define ti_sysbios_family_arm_msp432_ClockFreqs_ACLK (ti_sysbios_family_arm_msp432_ClockFreqs_ACLK__D)
#else
#define ti_sysbios_family_arm_msp432_ClockFreqs_ACLK (ti_sysbios_family_arm_msp432_ClockFreqs_ACLK__C)
typedef xdc_UInt32 CT__ti_sysbios_family_arm_msp432_ClockFreqs_ACLK;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_ACLK ti_sysbios_family_arm_msp432_ClockFreqs_ACLK__C;
#endif

/* SMCLK */
#ifdef ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK__D
#define ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK (ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK__D)
#else
#define ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK (ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK__C)
typedef xdc_UInt32 CT__ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK__C;
#endif

/* HSMCLK */
#ifdef ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK__D
#define ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK (ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK__D)
#else
#define ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK (ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK__C)
typedef xdc_UInt32 CT__ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK__C;
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_msp432_ClockFreqs_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_msp432_ClockFreqs_Module__startupDone__S, "ti_sysbios_family_arm_msp432_ClockFreqs_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_family_arm_msp432_ClockFreqs_Module__startupDone__S( void );

/* getFrequency__E */
#define ti_sysbios_family_arm_msp432_ClockFreqs_getFrequency ti_sysbios_family_arm_msp432_ClockFreqs_getFrequency__E
xdc__CODESECT(ti_sysbios_family_arm_msp432_ClockFreqs_getFrequency__E, "ti_sysbios_family_arm_msp432_ClockFreqs_getFrequency")
__extern xdc_UInt32 ti_sysbios_family_arm_msp432_ClockFreqs_getFrequency__E( ti_sysbios_family_arm_msp432_ClockFreqs_Clock clock );

/* setFrequency__E */
#define ti_sysbios_family_arm_msp432_ClockFreqs_setFrequency ti_sysbios_family_arm_msp432_ClockFreqs_setFrequency__E
xdc__CODESECT(ti_sysbios_family_arm_msp432_ClockFreqs_setFrequency__E, "ti_sysbios_family_arm_msp432_ClockFreqs_setFrequency")
__extern xdc_Void ti_sysbios_family_arm_msp432_ClockFreqs_setFrequency__E( ti_sysbios_family_arm_msp432_ClockFreqs_Clock clock, xdc_UInt32 frequency );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_msp432_ClockFreqs_Module_startupDone() ti_sysbios_family_arm_msp432_ClockFreqs_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_msp432_ClockFreqs_Object_heap() ti_sysbios_family_arm_msp432_ClockFreqs_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_msp432_ClockFreqs_Module_heap() ti_sysbios_family_arm_msp432_ClockFreqs_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_msp432_ClockFreqs_Module__id ti_sysbios_family_arm_msp432_ClockFreqs_Module_id( void ) 
{
    return ti_sysbios_family_arm_msp432_ClockFreqs_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_msp432_ClockFreqs_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_msp432_ClockFreqs_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_msp432_ClockFreqs_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_msp432_ClockFreqs_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_msp432_ClockFreqs__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_msp432_ClockFreqs__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_msp432_ClockFreqs__internalaccess))

#ifndef ti_sysbios_family_arm_msp432_ClockFreqs__include_state
#define ti_sysbios_family_arm_msp432_ClockFreqs__include_state

/* Module_State */
struct ti_sysbios_family_arm_msp432_ClockFreqs_Module_State {
    xdc_UInt32 ACLK;
    xdc_UInt32 SMCLK;
    xdc_UInt32 HSMCLK;
};

/* Module__state__V */
extern struct ti_sysbios_family_arm_msp432_ClockFreqs_Module_State__ ti_sysbios_family_arm_msp432_ClockFreqs_Module__state__V;

#endif /* ti_sysbios_family_arm_msp432_ClockFreqs__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_msp432_ClockFreqs__nolocalnames)

#ifndef ti_sysbios_family_arm_msp432_ClockFreqs__localnames__done
#define ti_sysbios_family_arm_msp432_ClockFreqs__localnames__done

/* module prefix */
#define ClockFreqs_Clock ti_sysbios_family_arm_msp432_ClockFreqs_Clock
#define ClockFreqs_Module_State ti_sysbios_family_arm_msp432_ClockFreqs_Module_State
#define ClockFreqs_Clock_ACLK ti_sysbios_family_arm_msp432_ClockFreqs_Clock_ACLK
#define ClockFreqs_Clock_SMCLK ti_sysbios_family_arm_msp432_ClockFreqs_Clock_SMCLK
#define ClockFreqs_Clock_HSMCLK ti_sysbios_family_arm_msp432_ClockFreqs_Clock_HSMCLK
#define ClockFreqs_ACLK ti_sysbios_family_arm_msp432_ClockFreqs_ACLK
#define ClockFreqs_SMCLK ti_sysbios_family_arm_msp432_ClockFreqs_SMCLK
#define ClockFreqs_HSMCLK ti_sysbios_family_arm_msp432_ClockFreqs_HSMCLK
#define ClockFreqs_getFrequency ti_sysbios_family_arm_msp432_ClockFreqs_getFrequency
#define ClockFreqs_setFrequency ti_sysbios_family_arm_msp432_ClockFreqs_setFrequency
#define ClockFreqs_Module_name ti_sysbios_family_arm_msp432_ClockFreqs_Module_name
#define ClockFreqs_Module_id ti_sysbios_family_arm_msp432_ClockFreqs_Module_id
#define ClockFreqs_Module_startup ti_sysbios_family_arm_msp432_ClockFreqs_Module_startup
#define ClockFreqs_Module_startupDone ti_sysbios_family_arm_msp432_ClockFreqs_Module_startupDone
#define ClockFreqs_Module_hasMask ti_sysbios_family_arm_msp432_ClockFreqs_Module_hasMask
#define ClockFreqs_Module_getMask ti_sysbios_family_arm_msp432_ClockFreqs_Module_getMask
#define ClockFreqs_Module_setMask ti_sysbios_family_arm_msp432_ClockFreqs_Module_setMask
#define ClockFreqs_Object_heap ti_sysbios_family_arm_msp432_ClockFreqs_Object_heap
#define ClockFreqs_Module_heap ti_sysbios_family_arm_msp432_ClockFreqs_Module_heap

#endif /* ti_sysbios_family_arm_msp432_ClockFreqs__localnames__done */
#endif
