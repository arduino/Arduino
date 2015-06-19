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

#ifndef ti_sysbios_family_arm_HwiCommon__include
#define ti_sysbios_family_arm_HwiCommon__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_family_arm_HwiCommon__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_family_arm_HwiCommon___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/family/arm/package/package.defs.h>

#include <xdc/runtime/IModule.h>


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
typedef xdc_Bits32 CT__ti_sysbios_family_arm_HwiCommon_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__diagsEnabled ti_sysbios_family_arm_HwiCommon_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_family_arm_HwiCommon_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__diagsIncluded ti_sysbios_family_arm_HwiCommon_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_family_arm_HwiCommon_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__diagsMask ti_sysbios_family_arm_HwiCommon_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_HwiCommon_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__gateObj ti_sysbios_family_arm_HwiCommon_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_family_arm_HwiCommon_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__gatePrms ti_sysbios_family_arm_HwiCommon_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_family_arm_HwiCommon_Module__id;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__id ti_sysbios_family_arm_HwiCommon_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_family_arm_HwiCommon_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__loggerDefined ti_sysbios_family_arm_HwiCommon_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_family_arm_HwiCommon_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__loggerObj ti_sysbios_family_arm_HwiCommon_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn0 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn1 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn2 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn4 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__loggerFxn8 ti_sysbios_family_arm_HwiCommon_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_family_arm_HwiCommon_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Module__startupDoneFxn ti_sysbios_family_arm_HwiCommon_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_family_arm_HwiCommon_Object__count;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Object__count ti_sysbios_family_arm_HwiCommon_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_family_arm_HwiCommon_Object__heap;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Object__heap ti_sysbios_family_arm_HwiCommon_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_family_arm_HwiCommon_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Object__sizeof ti_sysbios_family_arm_HwiCommon_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_family_arm_HwiCommon_Object__table;
__extern __FAR__ const CT__ti_sysbios_family_arm_HwiCommon_Object__table ti_sysbios_family_arm_HwiCommon_Object__table__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_family_arm_HwiCommon_Module_startup ti_sysbios_family_arm_HwiCommon_Module_startup__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_Module_startup__E, "ti_sysbios_family_arm_HwiCommon_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_HwiCommon_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_Module_startup__F, "ti_sysbios_family_arm_HwiCommon_Module_startup")
__extern xdc_Int ti_sysbios_family_arm_HwiCommon_Module_startup__F( xdc_Int state );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_Module__startupDone__S, "ti_sysbios_family_arm_HwiCommon_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_family_arm_HwiCommon_Module__startupDone__S( void );

/* enable__E */
#define ti_sysbios_family_arm_HwiCommon_enable ti_sysbios_family_arm_HwiCommon_enable__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_enable__E, "ti_sysbios_family_arm_HwiCommon_enable")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_enable__E( void );

/* disable__E */
#define ti_sysbios_family_arm_HwiCommon_disable ti_sysbios_family_arm_HwiCommon_disable__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_disable__E, "ti_sysbios_family_arm_HwiCommon_disable")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_disable__E( void );

/* restore__E */
#define ti_sysbios_family_arm_HwiCommon_restore ti_sysbios_family_arm_HwiCommon_restore__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_restore__E, "ti_sysbios_family_arm_HwiCommon_restore")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_restore__E( xdc_UInt key );

/* enableFIQ__E */
#define ti_sysbios_family_arm_HwiCommon_enableFIQ ti_sysbios_family_arm_HwiCommon_enableFIQ__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_enableFIQ__E, "ti_sysbios_family_arm_HwiCommon_enableFIQ")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_enableFIQ__E( void );

/* disableFIQ__E */
#define ti_sysbios_family_arm_HwiCommon_disableFIQ ti_sysbios_family_arm_HwiCommon_disableFIQ__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_disableFIQ__E, "ti_sysbios_family_arm_HwiCommon_disableFIQ")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_disableFIQ__E( void );

/* restoreFIQ__E */
#define ti_sysbios_family_arm_HwiCommon_restoreFIQ ti_sysbios_family_arm_HwiCommon_restoreFIQ__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_restoreFIQ__E, "ti_sysbios_family_arm_HwiCommon_restoreFIQ")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_restoreFIQ__E( xdc_UInt key );

/* enableIRQ__E */
#define ti_sysbios_family_arm_HwiCommon_enableIRQ ti_sysbios_family_arm_HwiCommon_enableIRQ__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_enableIRQ__E, "ti_sysbios_family_arm_HwiCommon_enableIRQ")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_enableIRQ__E( void );

/* disableIRQ__E */
#define ti_sysbios_family_arm_HwiCommon_disableIRQ ti_sysbios_family_arm_HwiCommon_disableIRQ__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_disableIRQ__E, "ti_sysbios_family_arm_HwiCommon_disableIRQ")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_disableIRQ__E( void );

/* restoreIRQ__E */
#define ti_sysbios_family_arm_HwiCommon_restoreIRQ ti_sysbios_family_arm_HwiCommon_restoreIRQ__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_restoreIRQ__E, "ti_sysbios_family_arm_HwiCommon_restoreIRQ")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_restoreIRQ__E( xdc_UInt key );

/* getTaskSP__E */
#define ti_sysbios_family_arm_HwiCommon_getTaskSP ti_sysbios_family_arm_HwiCommon_getTaskSP__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_getTaskSP__E, "ti_sysbios_family_arm_HwiCommon_getTaskSP")
__extern xdc_Char *ti_sysbios_family_arm_HwiCommon_getTaskSP__E( void );

/* switchFromBootStack__E */
#define ti_sysbios_family_arm_HwiCommon_switchFromBootStack ti_sysbios_family_arm_HwiCommon_switchFromBootStack__E
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_switchFromBootStack__E, "ti_sysbios_family_arm_HwiCommon_switchFromBootStack")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_switchFromBootStack__E( void );

/* switchToSystemMode__I */
#define ti_sysbios_family_arm_HwiCommon_switchToSystemMode ti_sysbios_family_arm_HwiCommon_switchToSystemMode__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_switchToSystemMode__I, "ti_sysbios_family_arm_HwiCommon_switchToSystemMode")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_switchToSystemMode__I( void );

/* enableA__I */
#define ti_sysbios_family_arm_HwiCommon_enableA ti_sysbios_family_arm_HwiCommon_enableA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_enableA__I, "ti_sysbios_family_arm_HwiCommon_enableA")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_enableA__I( void );

/* disableA__I */
#define ti_sysbios_family_arm_HwiCommon_disableA ti_sysbios_family_arm_HwiCommon_disableA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_disableA__I, "ti_sysbios_family_arm_HwiCommon_disableA")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_disableA__I( void );

/* restoreA__I */
#define ti_sysbios_family_arm_HwiCommon_restoreA ti_sysbios_family_arm_HwiCommon_restoreA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_restoreA__I, "ti_sysbios_family_arm_HwiCommon_restoreA")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_restoreA__I( xdc_UInt key );

/* enableFIQA__I */
#define ti_sysbios_family_arm_HwiCommon_enableFIQA ti_sysbios_family_arm_HwiCommon_enableFIQA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_enableFIQA__I, "ti_sysbios_family_arm_HwiCommon_enableFIQA")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_enableFIQA__I( void );

/* disableFIQA__I */
#define ti_sysbios_family_arm_HwiCommon_disableFIQA ti_sysbios_family_arm_HwiCommon_disableFIQA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_disableFIQA__I, "ti_sysbios_family_arm_HwiCommon_disableFIQA")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_disableFIQA__I( void );

/* restoreFIQA__I */
#define ti_sysbios_family_arm_HwiCommon_restoreFIQA ti_sysbios_family_arm_HwiCommon_restoreFIQA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_restoreFIQA__I, "ti_sysbios_family_arm_HwiCommon_restoreFIQA")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_restoreFIQA__I( xdc_UInt key );

/* enableIRQA__I */
#define ti_sysbios_family_arm_HwiCommon_enableIRQA ti_sysbios_family_arm_HwiCommon_enableIRQA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_enableIRQA__I, "ti_sysbios_family_arm_HwiCommon_enableIRQA")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_enableIRQA__I( void );

/* disableIRQA__I */
#define ti_sysbios_family_arm_HwiCommon_disableIRQA ti_sysbios_family_arm_HwiCommon_disableIRQA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_disableIRQA__I, "ti_sysbios_family_arm_HwiCommon_disableIRQA")
__extern xdc_UInt ti_sysbios_family_arm_HwiCommon_disableIRQA__I( void );

/* restoreIRQA__I */
#define ti_sysbios_family_arm_HwiCommon_restoreIRQA ti_sysbios_family_arm_HwiCommon_restoreIRQA__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_restoreIRQA__I, "ti_sysbios_family_arm_HwiCommon_restoreIRQA")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_restoreIRQA__I( xdc_UInt key );

/* swiHandler__I */
#define ti_sysbios_family_arm_HwiCommon_swiHandler ti_sysbios_family_arm_HwiCommon_swiHandler__I
xdc__CODESECT(ti_sysbios_family_arm_HwiCommon_swiHandler__I, "ti_sysbios_family_arm_HwiCommon_swiHandler")
__extern xdc_Void ti_sysbios_family_arm_HwiCommon_swiHandler__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_family_arm_HwiCommon_Module_startupDone() ti_sysbios_family_arm_HwiCommon_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_family_arm_HwiCommon_Object_heap() ti_sysbios_family_arm_HwiCommon_Object__heap__C

/* Module_heap */
#define ti_sysbios_family_arm_HwiCommon_Module_heap() ti_sysbios_family_arm_HwiCommon_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_family_arm_HwiCommon_Module__id ti_sysbios_family_arm_HwiCommon_Module_id( void ) 
{
    return ti_sysbios_family_arm_HwiCommon_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_family_arm_HwiCommon_Module_hasMask( void ) 
{
    return ti_sysbios_family_arm_HwiCommon_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_family_arm_HwiCommon_Module_getMask( void ) 
{
    return ti_sysbios_family_arm_HwiCommon_Module__diagsMask__C != NULL ? *ti_sysbios_family_arm_HwiCommon_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_family_arm_HwiCommon_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_family_arm_HwiCommon_Module__diagsMask__C != NULL) *ti_sysbios_family_arm_HwiCommon_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_family_arm_HwiCommon__top__
#undef __nested__
#endif

#endif /* ti_sysbios_family_arm_HwiCommon__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_family_arm_HwiCommon__internalaccess))

#ifndef ti_sysbios_family_arm_HwiCommon__include_state
#define ti_sysbios_family_arm_HwiCommon__include_state

/* Module_State */
struct ti_sysbios_family_arm_HwiCommon_Module_State {
    xdc_Char *taskSP;
    xdc_Char *isrStack;
    xdc_Ptr isrStackBase;
    xdc_Ptr isrStackSize;
};

/* Module__state__V */
extern struct ti_sysbios_family_arm_HwiCommon_Module_State__ ti_sysbios_family_arm_HwiCommon_Module__state__V;

#endif /* ti_sysbios_family_arm_HwiCommon__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_family_arm_HwiCommon__nolocalnames)

#ifndef ti_sysbios_family_arm_HwiCommon__localnames__done
#define ti_sysbios_family_arm_HwiCommon__localnames__done

/* module prefix */
#define HwiCommon_Module_State ti_sysbios_family_arm_HwiCommon_Module_State
#define HwiCommon_enable ti_sysbios_family_arm_HwiCommon_enable
#define HwiCommon_disable ti_sysbios_family_arm_HwiCommon_disable
#define HwiCommon_restore ti_sysbios_family_arm_HwiCommon_restore
#define HwiCommon_enableFIQ ti_sysbios_family_arm_HwiCommon_enableFIQ
#define HwiCommon_disableFIQ ti_sysbios_family_arm_HwiCommon_disableFIQ
#define HwiCommon_restoreFIQ ti_sysbios_family_arm_HwiCommon_restoreFIQ
#define HwiCommon_enableIRQ ti_sysbios_family_arm_HwiCommon_enableIRQ
#define HwiCommon_disableIRQ ti_sysbios_family_arm_HwiCommon_disableIRQ
#define HwiCommon_restoreIRQ ti_sysbios_family_arm_HwiCommon_restoreIRQ
#define HwiCommon_getTaskSP ti_sysbios_family_arm_HwiCommon_getTaskSP
#define HwiCommon_switchFromBootStack ti_sysbios_family_arm_HwiCommon_switchFromBootStack
#define HwiCommon_Module_name ti_sysbios_family_arm_HwiCommon_Module_name
#define HwiCommon_Module_id ti_sysbios_family_arm_HwiCommon_Module_id
#define HwiCommon_Module_startup ti_sysbios_family_arm_HwiCommon_Module_startup
#define HwiCommon_Module_startupDone ti_sysbios_family_arm_HwiCommon_Module_startupDone
#define HwiCommon_Module_hasMask ti_sysbios_family_arm_HwiCommon_Module_hasMask
#define HwiCommon_Module_getMask ti_sysbios_family_arm_HwiCommon_Module_getMask
#define HwiCommon_Module_setMask ti_sysbios_family_arm_HwiCommon_Module_setMask
#define HwiCommon_Object_heap ti_sysbios_family_arm_HwiCommon_Object_heap
#define HwiCommon_Module_heap ti_sysbios_family_arm_HwiCommon_Module_heap

#endif /* ti_sysbios_family_arm_HwiCommon__localnames__done */
#endif
