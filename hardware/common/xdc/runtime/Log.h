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

#ifndef xdc_runtime_Log__include
#define xdc_runtime_Log__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_Log__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_Log___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Log__prologue.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Text.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* NUMARGS */
#define xdc_runtime_Log_NUMARGS (8)

/* PRINTFID */
#define xdc_runtime_Log_PRINTFID (0)

/* EventRec */
typedef xdc_IArg __T1_xdc_runtime_Log_EventRec__arg;
typedef xdc_IArg __ARRAY1_xdc_runtime_Log_EventRec__arg[8];
typedef __ARRAY1_xdc_runtime_Log_EventRec__arg __TA_xdc_runtime_Log_EventRec__arg;
struct xdc_runtime_Log_EventRec {
    xdc_runtime_Types_Timestamp64 tstamp;
    xdc_Bits32 serial;
    xdc_runtime_Types_Event evt;
    __TA_xdc_runtime_Log_EventRec__arg arg;
};

/* Event */

/* EventId */
typedef xdc_runtime_Types_RopeId xdc_runtime_Log_EventId;


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_Log_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_Log_Module__diagsEnabled xdc_runtime_Log_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_Log_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_Log_Module__diagsIncluded xdc_runtime_Log_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_Log_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_Log_Module__diagsMask xdc_runtime_Log_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_Log_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_Log_Module__gateObj xdc_runtime_Log_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_Log_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_Log_Module__gatePrms xdc_runtime_Log_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_Log_Module__id;
__extern __FAR__ const CT__xdc_runtime_Log_Module__id xdc_runtime_Log_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_Log_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_Log_Module__loggerDefined xdc_runtime_Log_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_Log_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_Log_Module__loggerObj xdc_runtime_Log_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_Log_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_Log_Module__loggerFxn0 xdc_runtime_Log_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_Log_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_Log_Module__loggerFxn1 xdc_runtime_Log_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_Log_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_Log_Module__loggerFxn2 xdc_runtime_Log_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_Log_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_Log_Module__loggerFxn4 xdc_runtime_Log_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_Log_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_Log_Module__loggerFxn8 xdc_runtime_Log_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_Log_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_Log_Module__startupDoneFxn xdc_runtime_Log_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_Log_Object__count;
__extern __FAR__ const CT__xdc_runtime_Log_Object__count xdc_runtime_Log_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_Log_Object__heap;
__extern __FAR__ const CT__xdc_runtime_Log_Object__heap xdc_runtime_Log_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_Log_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_Log_Object__sizeof xdc_runtime_Log_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_Log_Object__table;
__extern __FAR__ const CT__xdc_runtime_Log_Object__table xdc_runtime_Log_Object__table__C;

/* L_construct */
#define xdc_runtime_Log_L_construct (xdc_runtime_Log_L_construct__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_construct;
__extern __FAR__ const CT__xdc_runtime_Log_L_construct xdc_runtime_Log_L_construct__C;

/* L_create */
#define xdc_runtime_Log_L_create (xdc_runtime_Log_L_create__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_create;
__extern __FAR__ const CT__xdc_runtime_Log_L_create xdc_runtime_Log_L_create__C;

/* L_destruct */
#define xdc_runtime_Log_L_destruct (xdc_runtime_Log_L_destruct__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_destruct;
__extern __FAR__ const CT__xdc_runtime_Log_L_destruct xdc_runtime_Log_L_destruct__C;

/* L_delete */
#define xdc_runtime_Log_L_delete (xdc_runtime_Log_L_delete__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_delete;
__extern __FAR__ const CT__xdc_runtime_Log_L_delete xdc_runtime_Log_L_delete__C;

/* L_error */
#define xdc_runtime_Log_L_error (xdc_runtime_Log_L_error__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_error;
__extern __FAR__ const CT__xdc_runtime_Log_L_error xdc_runtime_Log_L_error__C;

/* L_warning */
#define xdc_runtime_Log_L_warning (xdc_runtime_Log_L_warning__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_warning;
__extern __FAR__ const CT__xdc_runtime_Log_L_warning xdc_runtime_Log_L_warning__C;

/* L_info */
#define xdc_runtime_Log_L_info (xdc_runtime_Log_L_info__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_info;
__extern __FAR__ const CT__xdc_runtime_Log_L_info xdc_runtime_Log_L_info__C;

/* L_start */
#define xdc_runtime_Log_L_start (xdc_runtime_Log_L_start__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_start;
__extern __FAR__ const CT__xdc_runtime_Log_L_start xdc_runtime_Log_L_start__C;

/* L_stop */
#define xdc_runtime_Log_L_stop (xdc_runtime_Log_L_stop__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_stop;
__extern __FAR__ const CT__xdc_runtime_Log_L_stop xdc_runtime_Log_L_stop__C;

/* L_startInstance */
#define xdc_runtime_Log_L_startInstance (xdc_runtime_Log_L_startInstance__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_startInstance;
__extern __FAR__ const CT__xdc_runtime_Log_L_startInstance xdc_runtime_Log_L_startInstance__C;

/* L_stopInstance */
#define xdc_runtime_Log_L_stopInstance (xdc_runtime_Log_L_stopInstance__C)
typedef xdc_runtime_Log_Event CT__xdc_runtime_Log_L_stopInstance;
__extern __FAR__ const CT__xdc_runtime_Log_L_stopInstance xdc_runtime_Log_L_stopInstance__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_Log_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_Log_Module__startupDone__S, "xdc_runtime_Log_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_Log_Module__startupDone__S( void );

/* doPrint__E */
#define xdc_runtime_Log_doPrint xdc_runtime_Log_doPrint__E
xdc__CODESECT(xdc_runtime_Log_doPrint__E, "xdc_runtime_Log_doPrint")
__extern xdc_Void xdc_runtime_Log_doPrint__E( xdc_runtime_Log_EventRec *evRec );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_Log_Module_startupDone() xdc_runtime_Log_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_Log_Object_heap() xdc_runtime_Log_Object__heap__C

/* Module_heap */
#define xdc_runtime_Log_Module_heap() xdc_runtime_Log_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_Log_Module__id xdc_runtime_Log_Module_id( void ) 
{
    return xdc_runtime_Log_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_Log_Module_hasMask( void ) 
{
    return xdc_runtime_Log_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_Log_Module_getMask( void ) 
{
    return xdc_runtime_Log_Module__diagsMask__C != NULL ? *xdc_runtime_Log_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_Log_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_Log_Module__diagsMask__C != NULL) *xdc_runtime_Log_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#include <xdc/runtime/Log__epilogue.h>

#ifdef xdc_runtime_Log__top__
#undef __nested__
#endif

#endif /* xdc_runtime_Log__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_Log__internalaccess))

#ifndef xdc_runtime_Log__include_state
#define xdc_runtime_Log__include_state


#endif /* xdc_runtime_Log__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_Log__nolocalnames)

#ifndef xdc_runtime_Log__localnames__done
#define xdc_runtime_Log__localnames__done

/* module prefix */
#define Log_NUMARGS xdc_runtime_Log_NUMARGS
#define Log_PRINTFID xdc_runtime_Log_PRINTFID
#define Log_EventRec xdc_runtime_Log_EventRec
#define Log_Event xdc_runtime_Log_Event
#define Log_EventId xdc_runtime_Log_EventId
#define Log_L_construct xdc_runtime_Log_L_construct
#define Log_L_create xdc_runtime_Log_L_create
#define Log_L_destruct xdc_runtime_Log_L_destruct
#define Log_L_delete xdc_runtime_Log_L_delete
#define Log_L_error xdc_runtime_Log_L_error
#define Log_L_warning xdc_runtime_Log_L_warning
#define Log_L_info xdc_runtime_Log_L_info
#define Log_L_start xdc_runtime_Log_L_start
#define Log_L_stop xdc_runtime_Log_L_stop
#define Log_L_startInstance xdc_runtime_Log_L_startInstance
#define Log_L_stopInstance xdc_runtime_Log_L_stopInstance
#define Log_getMask xdc_runtime_Log_getMask
#define Log_getRope xdc_runtime_Log_getRope
#define Log_getEventId xdc_runtime_Log_getEventId
#define Log_print0 xdc_runtime_Log_print0
#define Log_print1 xdc_runtime_Log_print1
#define Log_print2 xdc_runtime_Log_print2
#define Log_print3 xdc_runtime_Log_print3
#define Log_print4 xdc_runtime_Log_print4
#define Log_print5 xdc_runtime_Log_print5
#define Log_print6 xdc_runtime_Log_print6
#define Log_error0 xdc_runtime_Log_error0
#define Log_error1 xdc_runtime_Log_error1
#define Log_error2 xdc_runtime_Log_error2
#define Log_error3 xdc_runtime_Log_error3
#define Log_error4 xdc_runtime_Log_error4
#define Log_error5 xdc_runtime_Log_error5
#define Log_warning0 xdc_runtime_Log_warning0
#define Log_warning1 xdc_runtime_Log_warning1
#define Log_warning2 xdc_runtime_Log_warning2
#define Log_warning3 xdc_runtime_Log_warning3
#define Log_warning4 xdc_runtime_Log_warning4
#define Log_warning5 xdc_runtime_Log_warning5
#define Log_info0 xdc_runtime_Log_info0
#define Log_info1 xdc_runtime_Log_info1
#define Log_info2 xdc_runtime_Log_info2
#define Log_info3 xdc_runtime_Log_info3
#define Log_info4 xdc_runtime_Log_info4
#define Log_info5 xdc_runtime_Log_info5
#define Log_put0 xdc_runtime_Log_put0
#define Log_put1 xdc_runtime_Log_put1
#define Log_put2 xdc_runtime_Log_put2
#define Log_put4 xdc_runtime_Log_put4
#define Log_put8 xdc_runtime_Log_put8
#define Log_write0 xdc_runtime_Log_write0
#define Log_write1 xdc_runtime_Log_write1
#define Log_write2 xdc_runtime_Log_write2
#define Log_write3 xdc_runtime_Log_write3
#define Log_write4 xdc_runtime_Log_write4
#define Log_write5 xdc_runtime_Log_write5
#define Log_write6 xdc_runtime_Log_write6
#define Log_write7 xdc_runtime_Log_write7
#define Log_write8 xdc_runtime_Log_write8
#define Log_doPrint xdc_runtime_Log_doPrint
#define Log_Module_name xdc_runtime_Log_Module_name
#define Log_Module_id xdc_runtime_Log_Module_id
#define Log_Module_startup xdc_runtime_Log_Module_startup
#define Log_Module_startupDone xdc_runtime_Log_Module_startupDone
#define Log_Module_hasMask xdc_runtime_Log_Module_hasMask
#define Log_Module_getMask xdc_runtime_Log_Module_getMask
#define Log_Module_setMask xdc_runtime_Log_Module_setMask
#define Log_Object_heap xdc_runtime_Log_Object_heap
#define Log_Module_heap xdc_runtime_Log_Module_heap

#endif /* xdc_runtime_Log__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:12; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

