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

#ifndef ti_sysbios_knl_Semaphore__include
#define ti_sysbios_knl_Semaphore__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_knl_Semaphore__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_knl_Semaphore___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/knl/package/package.defs.h>

#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/Assert.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <xdc/runtime/IModule.h>
#include <ti/sysbios/knl/Event.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Mode */
enum ti_sysbios_knl_Semaphore_Mode {
    ti_sysbios_knl_Semaphore_Mode_COUNTING = 0x0,
    ti_sysbios_knl_Semaphore_Mode_BINARY = 0x1,
    ti_sysbios_knl_Semaphore_Mode_COUNTING_PRIORITY = 0x2,
    ti_sysbios_knl_Semaphore_Mode_BINARY_PRIORITY = 0x3
};
typedef enum ti_sysbios_knl_Semaphore_Mode ti_sysbios_knl_Semaphore_Mode;


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_knl_Semaphore_Args__create {
    xdc_Int count;
} ti_sysbios_knl_Semaphore_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* PendState */
enum ti_sysbios_knl_Semaphore_PendState {
    ti_sysbios_knl_Semaphore_PendState_TIMEOUT = 0,
    ti_sysbios_knl_Semaphore_PendState_POSTED = 1,
    ti_sysbios_knl_Semaphore_PendState_CLOCK_WAIT = 2,
    ti_sysbios_knl_Semaphore_PendState_WAIT_FOREVER = 3
};
typedef enum ti_sysbios_knl_Semaphore_PendState ti_sysbios_knl_Semaphore_PendState;

/* PendElem */
struct ti_sysbios_knl_Semaphore_PendElem {
    ti_sysbios_knl_Task_PendElem tpElem;
    ti_sysbios_knl_Semaphore_PendState pendState;
};


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_knl_Semaphore_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsEnabled ti_sysbios_knl_Semaphore_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_knl_Semaphore_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsIncluded ti_sysbios_knl_Semaphore_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_knl_Semaphore_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__diagsMask ti_sysbios_knl_Semaphore_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Semaphore_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gateObj ti_sysbios_knl_Semaphore_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_knl_Semaphore_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__gatePrms ti_sysbios_knl_Semaphore_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_knl_Semaphore_Module__id;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_knl_Semaphore_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerDefined ti_sysbios_knl_Semaphore_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Semaphore_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerObj ti_sysbios_knl_Semaphore_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn0 ti_sysbios_knl_Semaphore_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn1 ti_sysbios_knl_Semaphore_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn2 ti_sysbios_knl_Semaphore_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn4 ti_sysbios_knl_Semaphore_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__loggerFxn8 ti_sysbios_knl_Semaphore_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Module__startupDoneFxn ti_sysbios_knl_Semaphore_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_knl_Semaphore_Object__count;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Object__count ti_sysbios_knl_Semaphore_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_knl_Semaphore_Object__heap;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Object__heap ti_sysbios_knl_Semaphore_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_knl_Semaphore_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Object__sizeof ti_sysbios_knl_Semaphore_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_knl_Semaphore_Object__table;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_Object__table ti_sysbios_knl_Semaphore_Object__table__C;

/* LM_post */
#define ti_sysbios_knl_Semaphore_LM_post (ti_sysbios_knl_Semaphore_LM_post__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_knl_Semaphore_LM_post;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post__C;

/* LM_pend */
#define ti_sysbios_knl_Semaphore_LM_pend (ti_sysbios_knl_Semaphore_LM_pend__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_knl_Semaphore_LM_pend;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend__C;

/* A_noEvents */
#define ti_sysbios_knl_Semaphore_A_noEvents (ti_sysbios_knl_Semaphore_A_noEvents__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Semaphore_A_noEvents;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_A_noEvents ti_sysbios_knl_Semaphore_A_noEvents__C;

/* A_invTimeout */
#define ti_sysbios_knl_Semaphore_A_invTimeout (ti_sysbios_knl_Semaphore_A_invTimeout__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Semaphore_A_invTimeout;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_A_invTimeout ti_sysbios_knl_Semaphore_A_invTimeout__C;

/* A_badContext */
#define ti_sysbios_knl_Semaphore_A_badContext (ti_sysbios_knl_Semaphore_A_badContext__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Semaphore_A_badContext;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_A_badContext ti_sysbios_knl_Semaphore_A_badContext__C;

/* A_overflow */
#define ti_sysbios_knl_Semaphore_A_overflow (ti_sysbios_knl_Semaphore_A_overflow__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Semaphore_A_overflow;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_A_overflow ti_sysbios_knl_Semaphore_A_overflow__C;

/* A_pendTaskDisabled */
#define ti_sysbios_knl_Semaphore_A_pendTaskDisabled (ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Semaphore_A_pendTaskDisabled;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_A_pendTaskDisabled ti_sysbios_knl_Semaphore_A_pendTaskDisabled__C;

/* supportsEvents */
#ifdef ti_sysbios_knl_Semaphore_supportsEvents__D
#define ti_sysbios_knl_Semaphore_supportsEvents (ti_sysbios_knl_Semaphore_supportsEvents__D)
#else
#define ti_sysbios_knl_Semaphore_supportsEvents (ti_sysbios_knl_Semaphore_supportsEvents__C)
typedef xdc_Bool CT__ti_sysbios_knl_Semaphore_supportsEvents;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_supportsEvents ti_sysbios_knl_Semaphore_supportsEvents__C;
#endif

/* supportsPriority */
#ifdef ti_sysbios_knl_Semaphore_supportsPriority__D
#define ti_sysbios_knl_Semaphore_supportsPriority (ti_sysbios_knl_Semaphore_supportsPriority__D)
#else
#define ti_sysbios_knl_Semaphore_supportsPriority (ti_sysbios_knl_Semaphore_supportsPriority__C)
typedef xdc_Bool CT__ti_sysbios_knl_Semaphore_supportsPriority;
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_supportsPriority ti_sysbios_knl_Semaphore_supportsPriority__C;
#endif

/* eventPost */
#define ti_sysbios_knl_Semaphore_eventPost (ti_sysbios_knl_Semaphore_eventPost__C)
typedef xdc_Void (*CT__ti_sysbios_knl_Semaphore_eventPost)(ti_sysbios_knl_Event_Handle, xdc_UInt);
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_eventPost ti_sysbios_knl_Semaphore_eventPost__C;

/* eventSync */
#define ti_sysbios_knl_Semaphore_eventSync (ti_sysbios_knl_Semaphore_eventSync__C)
typedef xdc_Void (*CT__ti_sysbios_knl_Semaphore_eventSync)(ti_sysbios_knl_Event_Handle, xdc_UInt, xdc_UInt);
__extern __FAR__ const CT__ti_sysbios_knl_Semaphore_eventSync ti_sysbios_knl_Semaphore_eventSync__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_knl_Semaphore_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    ti_sysbios_knl_Event_Handle event;
    xdc_UInt eventId;
    ti_sysbios_knl_Semaphore_Mode mode;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_knl_Semaphore_Struct {
    ti_sysbios_knl_Event_Handle __f0;
    xdc_UInt __f1;
    ti_sysbios_knl_Semaphore_Mode __f2;
    volatile xdc_UInt16 __f3;
    ti_sysbios_knl_Queue_Struct __f4;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_knl_Semaphore_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Instance_init__E, "ti_sysbios_knl_Semaphore_Instance_init")
__extern xdc_Void ti_sysbios_knl_Semaphore_Instance_init__E(ti_sysbios_knl_Semaphore_Object *, xdc_Int count, const ti_sysbios_knl_Semaphore_Params *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Instance_finalize__E, "ti_sysbios_knl_Semaphore_Instance_finalize")
__extern void ti_sysbios_knl_Semaphore_Instance_finalize__E( ti_sysbios_knl_Semaphore_Object* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Handle__label__S, "ti_sysbios_knl_Semaphore_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_knl_Semaphore_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Module__startupDone__S, "ti_sysbios_knl_Semaphore_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_knl_Semaphore_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Object__create__S, "ti_sysbios_knl_Semaphore_Object__create__S")
__extern xdc_Ptr ti_sysbios_knl_Semaphore_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_knl_Semaphore_create, "ti_sysbios_knl_Semaphore_create")
__extern ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Semaphore_create( xdc_Int count, const ti_sysbios_knl_Semaphore_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_knl_Semaphore_construct, "ti_sysbios_knl_Semaphore_construct")
__extern void ti_sysbios_knl_Semaphore_construct( ti_sysbios_knl_Semaphore_Struct *__obj, xdc_Int count, const ti_sysbios_knl_Semaphore_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Object__delete__S, "ti_sysbios_knl_Semaphore_Object__delete__S")
__extern xdc_Void ti_sysbios_knl_Semaphore_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_knl_Semaphore_delete, "ti_sysbios_knl_Semaphore_delete")
__extern void ti_sysbios_knl_Semaphore_delete(ti_sysbios_knl_Semaphore_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Object__destruct__S, "ti_sysbios_knl_Semaphore_Object__destruct__S")
__extern xdc_Void ti_sysbios_knl_Semaphore_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_knl_Semaphore_destruct, "ti_sysbios_knl_Semaphore_destruct")
__extern void ti_sysbios_knl_Semaphore_destruct(ti_sysbios_knl_Semaphore_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Object__get__S, "ti_sysbios_knl_Semaphore_Object__get__S")
__extern xdc_Ptr ti_sysbios_knl_Semaphore_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Object__first__S, "ti_sysbios_knl_Semaphore_Object__first__S")
__extern xdc_Ptr ti_sysbios_knl_Semaphore_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Object__next__S, "ti_sysbios_knl_Semaphore_Object__next__S")
__extern xdc_Ptr ti_sysbios_knl_Semaphore_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_knl_Semaphore_Params__init__S, "ti_sysbios_knl_Semaphore_Params__init__S")
__extern xdc_Void ti_sysbios_knl_Semaphore_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* getCount__E */
#define ti_sysbios_knl_Semaphore_getCount ti_sysbios_knl_Semaphore_getCount__E
xdc__CODESECT(ti_sysbios_knl_Semaphore_getCount__E, "ti_sysbios_knl_Semaphore_getCount")
__extern xdc_Int ti_sysbios_knl_Semaphore_getCount__E( ti_sysbios_knl_Semaphore_Handle __inst );

/* pend__E */
#define ti_sysbios_knl_Semaphore_pend ti_sysbios_knl_Semaphore_pend__E
xdc__CODESECT(ti_sysbios_knl_Semaphore_pend__E, "ti_sysbios_knl_Semaphore_pend")
__extern xdc_Bool ti_sysbios_knl_Semaphore_pend__E( ti_sysbios_knl_Semaphore_Handle __inst, xdc_UInt32 timeout );

/* post__E */
#define ti_sysbios_knl_Semaphore_post ti_sysbios_knl_Semaphore_post__E
xdc__CODESECT(ti_sysbios_knl_Semaphore_post__E, "ti_sysbios_knl_Semaphore_post")
__extern xdc_Void ti_sysbios_knl_Semaphore_post__E( ti_sysbios_knl_Semaphore_Handle __inst );

/* registerEvent__E */
#define ti_sysbios_knl_Semaphore_registerEvent ti_sysbios_knl_Semaphore_registerEvent__E
xdc__CODESECT(ti_sysbios_knl_Semaphore_registerEvent__E, "ti_sysbios_knl_Semaphore_registerEvent")
__extern xdc_Void ti_sysbios_knl_Semaphore_registerEvent__E( ti_sysbios_knl_Semaphore_Handle __inst, ti_sysbios_knl_Event_Handle event, xdc_UInt eventId );

/* reset__E */
#define ti_sysbios_knl_Semaphore_reset ti_sysbios_knl_Semaphore_reset__E
xdc__CODESECT(ti_sysbios_knl_Semaphore_reset__E, "ti_sysbios_knl_Semaphore_reset")
__extern xdc_Void ti_sysbios_knl_Semaphore_reset__E( ti_sysbios_knl_Semaphore_Handle __inst, xdc_Int count );

/* pendTimeout__I */
#define ti_sysbios_knl_Semaphore_pendTimeout ti_sysbios_knl_Semaphore_pendTimeout__I
xdc__CODESECT(ti_sysbios_knl_Semaphore_pendTimeout__I, "ti_sysbios_knl_Semaphore_pendTimeout")
__extern xdc_Void ti_sysbios_knl_Semaphore_pendTimeout__I( xdc_UArg arg );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_knl_Semaphore_Module_startupDone() ti_sysbios_knl_Semaphore_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_knl_Semaphore_Object_heap() ti_sysbios_knl_Semaphore_Object__heap__C

/* Module_heap */
#define ti_sysbios_knl_Semaphore_Module_heap() ti_sysbios_knl_Semaphore_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_knl_Semaphore_Module__id ti_sysbios_knl_Semaphore_Module_id( void ) 
{
    return ti_sysbios_knl_Semaphore_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_knl_Semaphore_Module_hasMask( void ) 
{
    return ti_sysbios_knl_Semaphore_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_knl_Semaphore_Module_getMask( void ) 
{
    return ti_sysbios_knl_Semaphore_Module__diagsMask__C != NULL ? *ti_sysbios_knl_Semaphore_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_knl_Semaphore_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_knl_Semaphore_Module__diagsMask__C != NULL) *ti_sysbios_knl_Semaphore_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_knl_Semaphore_Params_init( ti_sysbios_knl_Semaphore_Params *prms ) 
{
    if (prms) {
        ti_sysbios_knl_Semaphore_Params__init__S(prms, 0, sizeof(ti_sysbios_knl_Semaphore_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_knl_Semaphore_Params_copy(ti_sysbios_knl_Semaphore_Params *dst, const ti_sysbios_knl_Semaphore_Params *src) 
{
    if (dst) {
        ti_sysbios_knl_Semaphore_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_knl_Semaphore_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_knl_Semaphore_Object_count() ti_sysbios_knl_Semaphore_Object__count__C

/* Object_sizeof */
#define ti_sysbios_knl_Semaphore_Object_sizeof() ti_sysbios_knl_Semaphore_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Semaphore_Object_get(ti_sysbios_knl_Semaphore_Instance_State *oarr, int i) 
{
    return (ti_sysbios_knl_Semaphore_Handle)ti_sysbios_knl_Semaphore_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Semaphore_Object_first( void )
{
    return (ti_sysbios_knl_Semaphore_Handle)ti_sysbios_knl_Semaphore_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Semaphore_Object_next( ti_sysbios_knl_Semaphore_Object *obj )
{
    return (ti_sysbios_knl_Semaphore_Handle)ti_sysbios_knl_Semaphore_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_knl_Semaphore_Handle_label( ti_sysbios_knl_Semaphore_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_knl_Semaphore_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_knl_Semaphore_Handle_name( ti_sysbios_knl_Semaphore_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_knl_Semaphore_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Semaphore_handle( ti_sysbios_knl_Semaphore_Struct *str )
{
    return (ti_sysbios_knl_Semaphore_Handle)str;
}

/* struct */
static inline ti_sysbios_knl_Semaphore_Struct *ti_sysbios_knl_Semaphore_struct( ti_sysbios_knl_Semaphore_Handle inst )
{
    return (ti_sysbios_knl_Semaphore_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_knl_Semaphore__top__
#undef __nested__
#endif

#endif /* ti_sysbios_knl_Semaphore__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_knl_Semaphore__internalaccess))

#ifndef ti_sysbios_knl_Semaphore__include_state
#define ti_sysbios_knl_Semaphore__include_state

/* Object */
struct ti_sysbios_knl_Semaphore_Object {
    ti_sysbios_knl_Event_Handle event;
    xdc_UInt eventId;
    ti_sysbios_knl_Semaphore_Mode mode;
    volatile xdc_UInt16 count;
    char __dummy;
};

/* Instance_State_pendQ */
__extern __FAR__ const xdc_SizeT ti_sysbios_knl_Semaphore_Instance_State_pendQ__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Semaphore_Instance_State_pendQ(ti_sysbios_knl_Semaphore_Object *obj)
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)obj) + ti_sysbios_knl_Semaphore_Instance_State_pendQ__O);
}

#endif /* ti_sysbios_knl_Semaphore__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_knl_Semaphore__nolocalnames)

#ifndef ti_sysbios_knl_Semaphore__localnames__done
#define ti_sysbios_knl_Semaphore__localnames__done

/* module prefix */
#define Semaphore_Instance ti_sysbios_knl_Semaphore_Instance
#define Semaphore_Handle ti_sysbios_knl_Semaphore_Handle
#define Semaphore_Module ti_sysbios_knl_Semaphore_Module
#define Semaphore_Object ti_sysbios_knl_Semaphore_Object
#define Semaphore_Struct ti_sysbios_knl_Semaphore_Struct
#define Semaphore_Mode ti_sysbios_knl_Semaphore_Mode
#define Semaphore_PendState ti_sysbios_knl_Semaphore_PendState
#define Semaphore_PendElem ti_sysbios_knl_Semaphore_PendElem
#define Semaphore_Instance_State ti_sysbios_knl_Semaphore_Instance_State
#define Semaphore_Mode_COUNTING ti_sysbios_knl_Semaphore_Mode_COUNTING
#define Semaphore_Mode_BINARY ti_sysbios_knl_Semaphore_Mode_BINARY
#define Semaphore_Mode_COUNTING_PRIORITY ti_sysbios_knl_Semaphore_Mode_COUNTING_PRIORITY
#define Semaphore_Mode_BINARY_PRIORITY ti_sysbios_knl_Semaphore_Mode_BINARY_PRIORITY
#define Semaphore_PendState_TIMEOUT ti_sysbios_knl_Semaphore_PendState_TIMEOUT
#define Semaphore_PendState_POSTED ti_sysbios_knl_Semaphore_PendState_POSTED
#define Semaphore_PendState_CLOCK_WAIT ti_sysbios_knl_Semaphore_PendState_CLOCK_WAIT
#define Semaphore_PendState_WAIT_FOREVER ti_sysbios_knl_Semaphore_PendState_WAIT_FOREVER
#define Semaphore_LM_post ti_sysbios_knl_Semaphore_LM_post
#define Semaphore_LM_pend ti_sysbios_knl_Semaphore_LM_pend
#define Semaphore_A_noEvents ti_sysbios_knl_Semaphore_A_noEvents
#define Semaphore_A_invTimeout ti_sysbios_knl_Semaphore_A_invTimeout
#define Semaphore_A_badContext ti_sysbios_knl_Semaphore_A_badContext
#define Semaphore_A_overflow ti_sysbios_knl_Semaphore_A_overflow
#define Semaphore_A_pendTaskDisabled ti_sysbios_knl_Semaphore_A_pendTaskDisabled
#define Semaphore_supportsEvents ti_sysbios_knl_Semaphore_supportsEvents
#define Semaphore_supportsPriority ti_sysbios_knl_Semaphore_supportsPriority
#define Semaphore_eventPost ti_sysbios_knl_Semaphore_eventPost
#define Semaphore_eventSync ti_sysbios_knl_Semaphore_eventSync
#define Semaphore_Instance_State_pendQ ti_sysbios_knl_Semaphore_Instance_State_pendQ
#define Semaphore_Params ti_sysbios_knl_Semaphore_Params
#define Semaphore_getCount ti_sysbios_knl_Semaphore_getCount
#define Semaphore_pend ti_sysbios_knl_Semaphore_pend
#define Semaphore_post ti_sysbios_knl_Semaphore_post
#define Semaphore_registerEvent ti_sysbios_knl_Semaphore_registerEvent
#define Semaphore_reset ti_sysbios_knl_Semaphore_reset
#define Semaphore_Module_name ti_sysbios_knl_Semaphore_Module_name
#define Semaphore_Module_id ti_sysbios_knl_Semaphore_Module_id
#define Semaphore_Module_startup ti_sysbios_knl_Semaphore_Module_startup
#define Semaphore_Module_startupDone ti_sysbios_knl_Semaphore_Module_startupDone
#define Semaphore_Module_hasMask ti_sysbios_knl_Semaphore_Module_hasMask
#define Semaphore_Module_getMask ti_sysbios_knl_Semaphore_Module_getMask
#define Semaphore_Module_setMask ti_sysbios_knl_Semaphore_Module_setMask
#define Semaphore_Object_heap ti_sysbios_knl_Semaphore_Object_heap
#define Semaphore_Module_heap ti_sysbios_knl_Semaphore_Module_heap
#define Semaphore_construct ti_sysbios_knl_Semaphore_construct
#define Semaphore_create ti_sysbios_knl_Semaphore_create
#define Semaphore_handle ti_sysbios_knl_Semaphore_handle
#define Semaphore_struct ti_sysbios_knl_Semaphore_struct
#define Semaphore_Handle_label ti_sysbios_knl_Semaphore_Handle_label
#define Semaphore_Handle_name ti_sysbios_knl_Semaphore_Handle_name
#define Semaphore_Instance_init ti_sysbios_knl_Semaphore_Instance_init
#define Semaphore_Object_count ti_sysbios_knl_Semaphore_Object_count
#define Semaphore_Object_get ti_sysbios_knl_Semaphore_Object_get
#define Semaphore_Object_first ti_sysbios_knl_Semaphore_Object_first
#define Semaphore_Object_next ti_sysbios_knl_Semaphore_Object_next
#define Semaphore_Object_sizeof ti_sysbios_knl_Semaphore_Object_sizeof
#define Semaphore_Params_copy ti_sysbios_knl_Semaphore_Params_copy
#define Semaphore_Params_init ti_sysbios_knl_Semaphore_Params_init
#define Semaphore_Instance_finalize ti_sysbios_knl_Semaphore_Instance_finalize
#define Semaphore_delete ti_sysbios_knl_Semaphore_delete
#define Semaphore_destruct ti_sysbios_knl_Semaphore_destruct

#endif /* ti_sysbios_knl_Semaphore__localnames__done */
#endif
