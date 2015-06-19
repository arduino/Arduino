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

#ifndef ti_sysbios_family_arm_msp432_init_Boot__include
#define ti_sysbios_family_arm_msp432_init_Boot__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_msp432_init_Boot__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_msp432_init_Boot___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/family/arm/msp432/init/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* SpeedOpt */
enum ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt {
    ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt_Low = 0,
    ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt_Medium = 1,
    ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt_High = 2
};
typedef enum ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_msp432_init_Boot_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__diagsEnabled ti_sysbios_family_arm_msp432_init_Boot_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_msp432_init_Boot_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__diagsIncluded ti_sysbios_family_arm_msp432_init_Boot_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_init_Boot_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__gateObj ti_sysbios_family_arm_msp432_init_Boot_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_init_Boot_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__gatePrms ti_sysbios_family_arm_msp432_init_Boot_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_msp432_init_Boot_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__id ti_sysbios_family_arm_msp432_init_Boot_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerDefined ti_sysbios_family_arm_msp432_init_Boot_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerObj ti_sysbios_family_arm_msp432_init_Boot_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn0 ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn1 ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn2 ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn4 ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn8 ti_sysbios_family_arm_msp432_init_Boot_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_msp432_init_Boot_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Module__startupDoneFxn ti_sysbios_family_arm_msp432_init_Boot_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_msp432_init_Boot_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Object__count ti_sysbios_family_arm_msp432_init_Boot_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_msp432_init_Boot_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Object__heap ti_sysbios_family_arm_msp432_init_Boot_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_msp432_init_Boot_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Object__sizeof ti_sysbios_family_arm_msp432_init_Boot_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_msp432_init_Boot_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_msp432_init_Boot_Object__table ti_sysbios_family_arm_msp432_init_Boot_Object__table__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_msp432_init_Boot_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_msp432_init_Boot_Module__startupDone__S, "ti_sysbios_family_arm_msp432_init_Boot_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_family_arm_msp432_init_Boot_Module__startupDone__S( void );

/* init__I */
#define ti_sysbios_family_arm_msp432_init_Boot_init ti_sysbios_family_arm_msp432_init_Boot_init__I
xdc__CODESECT(ti_sysbios_family_arm_msp432_init_Boot_init__I, "ti_sysbios_family_arm_msp432_init_Boot_init")
__extern xdc_Void ti_sysbios_family_arm_msp432_init_Boot_init__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_msp432_init_Boot_Module_startupDone() ti_sysbios_family_arm_msp432_init_Boot_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_msp432_init_Boot_Object_heap() ti_sysbios_family_arm_msp432_init_Boot_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_msp432_init_Boot_Module_heap() ti_sysbios_family_arm_msp432_init_Boot_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_msp432_init_Boot_Module__id ti_sysbios_family_arm_msp432_init_Boot_Module_id( void ) 
{
    return ti_sysbios_family_arm_msp432_init_Boot_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_msp432_init_Boot_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_msp432_init_Boot_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_msp432_init_Boot_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_msp432_init_Boot_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_msp432_init_Boot__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_msp432_init_Boot__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_msp432_init_Boot__internalaccess))

#ifndef ti_sysbios_family_arm_msp432_init_Boot__include_state
#define ti_sysbios_family_arm_msp432_init_Boot__include_state


#endif /* ti_sysbios_family_arm_msp432_init_Boot__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_msp432_init_Boot__nolocalnames)

#ifndef ti_sysbios_family_arm_msp432_init_Boot__localnames__done
#define ti_sysbios_family_arm_msp432_init_Boot__localnames__done

/* module prefix */
#define Boot_SpeedOpt ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt
#define Boot_SpeedOpt_Low ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt_Low
#define Boot_SpeedOpt_Medium ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt_Medium
#define Boot_SpeedOpt_High ti_sysbios_family_arm_msp432_init_Boot_SpeedOpt_High
#define Boot_Module_name ti_sysbios_family_arm_msp432_init_Boot_Module_name
#define Boot_Module_id ti_sysbios_family_arm_msp432_init_Boot_Module_id
#define Boot_Module_startup ti_sysbios_family_arm_msp432_init_Boot_Module_startup
#define Boot_Module_startupDone ti_sysbios_family_arm_msp432_init_Boot_Module_startupDone
#define Boot_Module_hasMask ti_sysbios_family_arm_msp432_init_Boot_Module_hasMask
#define Boot_Module_getMask ti_sysbios_family_arm_msp432_init_Boot_Module_getMask
#define Boot_Module_setMask ti_sysbios_family_arm_msp432_init_Boot_Module_setMask
#define Boot_Object_heap ti_sysbios_family_arm_msp432_init_Boot_Object_heap
#define Boot_Module_heap ti_sysbios_family_arm_msp432_init_Boot_Module_heap

#endif /* ti_sysbios_family_arm_msp432_init_Boot__localnames__done */
#endif
