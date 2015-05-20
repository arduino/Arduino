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

#ifndef ti_sysbios_knl_Event__include
#define ti_sysbios_knl_Event__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_knl_Event__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_knl_Event___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/knl/Event__prologue.h>
#include <ti/sysbios/knl/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Diags.h>
#include <xdc/runtime/Log.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Id_00 */
#define ti_sysbios_knl_Event_Id_00 (0x1)

/* Id_01 */
#define ti_sysbios_knl_Event_Id_01 (0x2)

/* Id_02 */
#define ti_sysbios_knl_Event_Id_02 (0x4)

/* Id_03 */
#define ti_sysbios_knl_Event_Id_03 (0x8)

/* Id_04 */
#define ti_sysbios_knl_Event_Id_04 (0x10)

/* Id_05 */
#define ti_sysbios_knl_Event_Id_05 (0x20)

/* Id_06 */
#define ti_sysbios_knl_Event_Id_06 (0x40)

/* Id_07 */
#define ti_sysbios_knl_Event_Id_07 (0x80)

/* Id_08 */
#define ti_sysbios_knl_Event_Id_08 (0x100)

/* Id_09 */
#define ti_sysbios_knl_Event_Id_09 (0x200)

/* Id_10 */
#define ti_sysbios_knl_Event_Id_10 (0x400)

/* Id_11 */
#define ti_sysbios_knl_Event_Id_11 (0x800)

/* Id_12 */
#define ti_sysbios_knl_Event_Id_12 (0x1000)

/* Id_13 */
#define ti_sysbios_knl_Event_Id_13 (0x2000)

/* Id_14 */
#define ti_sysbios_knl_Event_Id_14 (0x4000)

/* Id_15 */
#define ti_sysbios_knl_Event_Id_15 (0x8000)

/* Id_16 */
#define ti_sysbios_knl_Event_Id_16 (0x10000)

/* Id_17 */
#define ti_sysbios_knl_Event_Id_17 (0x20000)

/* Id_18 */
#define ti_sysbios_knl_Event_Id_18 (0x40000)

/* Id_19 */
#define ti_sysbios_knl_Event_Id_19 (0x80000)

/* Id_20 */
#define ti_sysbios_knl_Event_Id_20 (0x100000)

/* Id_21 */
#define ti_sysbios_knl_Event_Id_21 (0x200000)

/* Id_22 */
#define ti_sysbios_knl_Event_Id_22 (0x400000)

/* Id_23 */
#define ti_sysbios_knl_Event_Id_23 (0x800000)

/* Id_24 */
#define ti_sysbios_knl_Event_Id_24 (0x1000000)

/* Id_25 */
#define ti_sysbios_knl_Event_Id_25 (0x2000000)

/* Id_26 */
#define ti_sysbios_knl_Event_Id_26 (0x4000000)

/* Id_27 */
#define ti_sysbios_knl_Event_Id_27 (0x8000000)

/* Id_28 */
#define ti_sysbios_knl_Event_Id_28 (0x10000000)

/* Id_29 */
#define ti_sysbios_knl_Event_Id_29 (0x20000000)

/* Id_30 */
#define ti_sysbios_knl_Event_Id_30 (0x40000000)

/* Id_31 */
#define ti_sysbios_knl_Event_Id_31 (0x80000000)

/* Id_NONE */
#define ti_sysbios_knl_Event_Id_NONE (0)


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* PendState */
enum ti_sysbios_knl_Event_PendState {
    ti_sysbios_knl_Event_PendState_TIMEOUT = 0,
    ti_sysbios_knl_Event_PendState_POSTED = 1,
    ti_sysbios_knl_Event_PendState_CLOCK_WAIT = 2,
    ti_sysbios_knl_Event_PendState_WAIT_FOREVER = 3
};
typedef enum ti_sysbios_knl_Event_PendState ti_sysbios_knl_Event_PendState;

/* PendElem */
struct ti_sysbios_knl_Event_PendElem {
    ti_sysbios_knl_Task_PendElem tpElem;
    ti_sysbios_knl_Event_PendState pendState;
    xdc_UInt matchingEvents;
    xdc_UInt andMask;
    xdc_UInt orMask;
};


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_knl_Event_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__diagsEnabled ti_sysbios_knl_Event_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_knl_Event_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__diagsIncluded ti_sysbios_knl_Event_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_knl_Event_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__diagsMask ti_sysbios_knl_Event_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Event_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__gateObj ti_sysbios_knl_Event_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_knl_Event_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__gatePrms ti_sysbios_knl_Event_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_knl_Event_Module__id;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__id ti_sysbios_knl_Event_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_knl_Event_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__loggerDefined ti_sysbios_knl_Event_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Event_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__loggerObj ti_sysbios_knl_Event_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_knl_Event_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__loggerFxn0 ti_sysbios_knl_Event_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_knl_Event_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__loggerFxn1 ti_sysbios_knl_Event_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_knl_Event_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__loggerFxn2 ti_sysbios_knl_Event_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_knl_Event_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__loggerFxn4 ti_sysbios_knl_Event_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_knl_Event_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__loggerFxn8 ti_sysbios_knl_Event_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_knl_Event_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_knl_Event_Module__startupDoneFxn ti_sysbios_knl_Event_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_knl_Event_Object__count;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Object__count ti_sysbios_knl_Event_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_knl_Event_Object__heap;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Object__heap ti_sysbios_knl_Event_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_knl_Event_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Object__sizeof ti_sysbios_knl_Event_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_knl_Event_Object__table;
__extern __FAR__ const CT__ti_sysbios_knl_Event_Object__table ti_sysbios_knl_Event_Object__table__C;

/* LM_post */
#define ti_sysbios_knl_Event_LM_post (ti_sysbios_knl_Event_LM_post__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_knl_Event_LM_post;
__extern __FAR__ const CT__ti_sysbios_knl_Event_LM_post ti_sysbios_knl_Event_LM_post__C;

/* LM_pend */
#define ti_sysbios_knl_Event_LM_pend (ti_sysbios_knl_Event_LM_pend__C)
typedef xdc_runtime_Log_Event CT__ti_sysbios_knl_Event_LM_pend;
__extern __FAR__ const CT__ti_sysbios_knl_Event_LM_pend ti_sysbios_knl_Event_LM_pend__C;

/* A_nullEventMasks */
#define ti_sysbios_knl_Event_A_nullEventMasks (ti_sysbios_knl_Event_A_nullEventMasks__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Event_A_nullEventMasks;
__extern __FAR__ const CT__ti_sysbios_knl_Event_A_nullEventMasks ti_sysbios_knl_Event_A_nullEventMasks__C;

/* A_nullEventId */
#define ti_sysbios_knl_Event_A_nullEventId (ti_sysbios_knl_Event_A_nullEventId__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Event_A_nullEventId;
__extern __FAR__ const CT__ti_sysbios_knl_Event_A_nullEventId ti_sysbios_knl_Event_A_nullEventId__C;

/* A_eventInUse */
#define ti_sysbios_knl_Event_A_eventInUse (ti_sysbios_knl_Event_A_eventInUse__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Event_A_eventInUse;
__extern __FAR__ const CT__ti_sysbios_knl_Event_A_eventInUse ti_sysbios_knl_Event_A_eventInUse__C;

/* A_badContext */
#define ti_sysbios_knl_Event_A_badContext (ti_sysbios_knl_Event_A_badContext__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Event_A_badContext;
__extern __FAR__ const CT__ti_sysbios_knl_Event_A_badContext ti_sysbios_knl_Event_A_badContext__C;

/* A_pendTaskDisabled */
#define ti_sysbios_knl_Event_A_pendTaskDisabled (ti_sysbios_knl_Event_A_pendTaskDisabled__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Event_A_pendTaskDisabled;
__extern __FAR__ const CT__ti_sysbios_knl_Event_A_pendTaskDisabled ti_sysbios_knl_Event_A_pendTaskDisabled__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_knl_Event_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_knl_Event_Struct {
    volatile xdc_UInt __f0;
    ti_sysbios_knl_Queue_Struct __f1;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_knl_Event_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_knl_Event_Instance_init__E, "ti_sysbios_knl_Event_Instance_init")
__extern xdc_Void ti_sysbios_knl_Event_Instance_init__E(ti_sysbios_knl_Event_Object *, const ti_sysbios_knl_Event_Params *);

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_knl_Event_Handle__label__S, "ti_sysbios_knl_Event_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_knl_Event_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_knl_Event_Module__startupDone__S, "ti_sysbios_knl_Event_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_knl_Event_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_knl_Event_Object__create__S, "ti_sysbios_knl_Event_Object__create__S")
__extern xdc_Ptr ti_sysbios_knl_Event_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_knl_Event_create, "ti_sysbios_knl_Event_create")
__extern ti_sysbios_knl_Event_Handle ti_sysbios_knl_Event_create( const ti_sysbios_knl_Event_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_knl_Event_construct, "ti_sysbios_knl_Event_construct")
__extern void ti_sysbios_knl_Event_construct( ti_sysbios_knl_Event_Struct *__obj, const ti_sysbios_knl_Event_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_knl_Event_Object__delete__S, "ti_sysbios_knl_Event_Object__delete__S")
__extern xdc_Void ti_sysbios_knl_Event_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_knl_Event_delete, "ti_sysbios_knl_Event_delete")
__extern void ti_sysbios_knl_Event_delete(ti_sysbios_knl_Event_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_knl_Event_Object__destruct__S, "ti_sysbios_knl_Event_Object__destruct__S")
__extern xdc_Void ti_sysbios_knl_Event_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_knl_Event_destruct, "ti_sysbios_knl_Event_destruct")
__extern void ti_sysbios_knl_Event_destruct(ti_sysbios_knl_Event_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_knl_Event_Object__get__S, "ti_sysbios_knl_Event_Object__get__S")
__extern xdc_Ptr ti_sysbios_knl_Event_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_knl_Event_Object__first__S, "ti_sysbios_knl_Event_Object__first__S")
__extern xdc_Ptr ti_sysbios_knl_Event_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_knl_Event_Object__next__S, "ti_sysbios_knl_Event_Object__next__S")
__extern xdc_Ptr ti_sysbios_knl_Event_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_knl_Event_Params__init__S, "ti_sysbios_knl_Event_Params__init__S")
__extern xdc_Void ti_sysbios_knl_Event_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* pend__E */
#define ti_sysbios_knl_Event_pend ti_sysbios_knl_Event_pend__E
xdc__CODESECT(ti_sysbios_knl_Event_pend__E, "ti_sysbios_knl_Event_pend")
__extern xdc_UInt ti_sysbios_knl_Event_pend__E( ti_sysbios_knl_Event_Handle __inst, xdc_UInt andMask, xdc_UInt orMask, xdc_UInt32 timeout );

/* post__E */
#define ti_sysbios_knl_Event_post ti_sysbios_knl_Event_post__E
xdc__CODESECT(ti_sysbios_knl_Event_post__E, "ti_sysbios_knl_Event_post")
__extern xdc_Void ti_sysbios_knl_Event_post__E( ti_sysbios_knl_Event_Handle __inst, xdc_UInt eventMask );

/* getPostedEvents__E */
#define ti_sysbios_knl_Event_getPostedEvents ti_sysbios_knl_Event_getPostedEvents__E
xdc__CODESECT(ti_sysbios_knl_Event_getPostedEvents__E, "ti_sysbios_knl_Event_getPostedEvents")
__extern xdc_UInt ti_sysbios_knl_Event_getPostedEvents__E( ti_sysbios_knl_Event_Handle __inst );

/* sync__E */
#define ti_sysbios_knl_Event_sync ti_sysbios_knl_Event_sync__E
xdc__CODESECT(ti_sysbios_knl_Event_sync__E, "ti_sysbios_knl_Event_sync")
__extern xdc_Void ti_sysbios_knl_Event_sync__E( ti_sysbios_knl_Event_Handle __inst, xdc_UInt eventId, xdc_UInt count );

/* pendTimeout__I */
#define ti_sysbios_knl_Event_pendTimeout ti_sysbios_knl_Event_pendTimeout__I
xdc__CODESECT(ti_sysbios_knl_Event_pendTimeout__I, "ti_sysbios_knl_Event_pendTimeout")
__extern xdc_Void ti_sysbios_knl_Event_pendTimeout__I( xdc_UArg arg );

/* checkEvents__I */
#define ti_sysbios_knl_Event_checkEvents ti_sysbios_knl_Event_checkEvents__I
xdc__CODESECT(ti_sysbios_knl_Event_checkEvents__I, "ti_sysbios_knl_Event_checkEvents")
__extern xdc_UInt ti_sysbios_knl_Event_checkEvents__I( ti_sysbios_knl_Event_Object *event, xdc_UInt andMask, xdc_UInt orMask );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_knl_Event_Module_startupDone() ti_sysbios_knl_Event_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_knl_Event_Object_heap() ti_sysbios_knl_Event_Object__heap__C

/* Module_heap */
#define ti_sysbios_knl_Event_Module_heap() ti_sysbios_knl_Event_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_knl_Event_Module__id ti_sysbios_knl_Event_Module_id( void ) 
{
    return ti_sysbios_knl_Event_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_knl_Event_Module_hasMask( void ) 
{
    return ti_sysbios_knl_Event_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_knl_Event_Module_getMask( void ) 
{
    return ti_sysbios_knl_Event_Module__diagsMask__C != NULL ? *ti_sysbios_knl_Event_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_knl_Event_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_knl_Event_Module__diagsMask__C != NULL) *ti_sysbios_knl_Event_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_knl_Event_Params_init( ti_sysbios_knl_Event_Params *prms ) 
{
    if (prms) {
        ti_sysbios_knl_Event_Params__init__S(prms, 0, sizeof(ti_sysbios_knl_Event_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_knl_Event_Params_copy(ti_sysbios_knl_Event_Params *dst, const ti_sysbios_knl_Event_Params *src) 
{
    if (dst) {
        ti_sysbios_knl_Event_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_knl_Event_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_knl_Event_Object_count() ti_sysbios_knl_Event_Object__count__C

/* Object_sizeof */
#define ti_sysbios_knl_Event_Object_sizeof() ti_sysbios_knl_Event_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_knl_Event_Handle ti_sysbios_knl_Event_Object_get(ti_sysbios_knl_Event_Instance_State *oarr, int i) 
{
    return (ti_sysbios_knl_Event_Handle)ti_sysbios_knl_Event_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_knl_Event_Handle ti_sysbios_knl_Event_Object_first( void )
{
    return (ti_sysbios_knl_Event_Handle)ti_sysbios_knl_Event_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_knl_Event_Handle ti_sysbios_knl_Event_Object_next( ti_sysbios_knl_Event_Object *obj )
{
    return (ti_sysbios_knl_Event_Handle)ti_sysbios_knl_Event_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_knl_Event_Handle_label( ti_sysbios_knl_Event_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_knl_Event_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_knl_Event_Handle_name( ti_sysbios_knl_Event_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_knl_Event_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_knl_Event_Handle ti_sysbios_knl_Event_handle( ti_sysbios_knl_Event_Struct *str )
{
    return (ti_sysbios_knl_Event_Handle)str;
}

/* struct */
static inline ti_sysbios_knl_Event_Struct *ti_sysbios_knl_Event_struct( ti_sysbios_knl_Event_Handle inst )
{
    return (ti_sysbios_knl_Event_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#include <ti/sysbios/knl/Event__epilogue.h>

#ifdef ti_sysbios_knl_Event__top__
#undef __nested__
#endif

#endif /* ti_sysbios_knl_Event__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_knl_Event__internalaccess))

#ifndef ti_sysbios_knl_Event__include_state
#define ti_sysbios_knl_Event__include_state

/* Object */
struct ti_sysbios_knl_Event_Object {
    volatile xdc_UInt postedEvents;
    char __dummy;
};

/* Instance_State_pendQ */
__extern __FAR__ const xdc_SizeT ti_sysbios_knl_Event_Instance_State_pendQ__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Event_Instance_State_pendQ(ti_sysbios_knl_Event_Object *obj)
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)obj) + ti_sysbios_knl_Event_Instance_State_pendQ__O);
}

#endif /* ti_sysbios_knl_Event__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_knl_Event__nolocalnames)

#ifndef ti_sysbios_knl_Event__localnames__done
#define ti_sysbios_knl_Event__localnames__done

/* module prefix */
#define Event_Instance ti_sysbios_knl_Event_Instance
#define Event_Handle ti_sysbios_knl_Event_Handle
#define Event_Module ti_sysbios_knl_Event_Module
#define Event_Object ti_sysbios_knl_Event_Object
#define Event_Struct ti_sysbios_knl_Event_Struct
#define Event_Id_00 ti_sysbios_knl_Event_Id_00
#define Event_Id_01 ti_sysbios_knl_Event_Id_01
#define Event_Id_02 ti_sysbios_knl_Event_Id_02
#define Event_Id_03 ti_sysbios_knl_Event_Id_03
#define Event_Id_04 ti_sysbios_knl_Event_Id_04
#define Event_Id_05 ti_sysbios_knl_Event_Id_05
#define Event_Id_06 ti_sysbios_knl_Event_Id_06
#define Event_Id_07 ti_sysbios_knl_Event_Id_07
#define Event_Id_08 ti_sysbios_knl_Event_Id_08
#define Event_Id_09 ti_sysbios_knl_Event_Id_09
#define Event_Id_10 ti_sysbios_knl_Event_Id_10
#define Event_Id_11 ti_sysbios_knl_Event_Id_11
#define Event_Id_12 ti_sysbios_knl_Event_Id_12
#define Event_Id_13 ti_sysbios_knl_Event_Id_13
#define Event_Id_14 ti_sysbios_knl_Event_Id_14
#define Event_Id_15 ti_sysbios_knl_Event_Id_15
#define Event_Id_16 ti_sysbios_knl_Event_Id_16
#define Event_Id_17 ti_sysbios_knl_Event_Id_17
#define Event_Id_18 ti_sysbios_knl_Event_Id_18
#define Event_Id_19 ti_sysbios_knl_Event_Id_19
#define Event_Id_20 ti_sysbios_knl_Event_Id_20
#define Event_Id_21 ti_sysbios_knl_Event_Id_21
#define Event_Id_22 ti_sysbios_knl_Event_Id_22
#define Event_Id_23 ti_sysbios_knl_Event_Id_23
#define Event_Id_24 ti_sysbios_knl_Event_Id_24
#define Event_Id_25 ti_sysbios_knl_Event_Id_25
#define Event_Id_26 ti_sysbios_knl_Event_Id_26
#define Event_Id_27 ti_sysbios_knl_Event_Id_27
#define Event_Id_28 ti_sysbios_knl_Event_Id_28
#define Event_Id_29 ti_sysbios_knl_Event_Id_29
#define Event_Id_30 ti_sysbios_knl_Event_Id_30
#define Event_Id_31 ti_sysbios_knl_Event_Id_31
#define Event_Id_NONE ti_sysbios_knl_Event_Id_NONE
#define Event_PendState ti_sysbios_knl_Event_PendState
#define Event_PendElem ti_sysbios_knl_Event_PendElem
#define Event_Instance_State ti_sysbios_knl_Event_Instance_State
#define Event_PendState_TIMEOUT ti_sysbios_knl_Event_PendState_TIMEOUT
#define Event_PendState_POSTED ti_sysbios_knl_Event_PendState_POSTED
#define Event_PendState_CLOCK_WAIT ti_sysbios_knl_Event_PendState_CLOCK_WAIT
#define Event_PendState_WAIT_FOREVER ti_sysbios_knl_Event_PendState_WAIT_FOREVER
#define Event_LM_post ti_sysbios_knl_Event_LM_post
#define Event_LM_pend ti_sysbios_knl_Event_LM_pend
#define Event_A_nullEventMasks ti_sysbios_knl_Event_A_nullEventMasks
#define Event_A_nullEventId ti_sysbios_knl_Event_A_nullEventId
#define Event_A_eventInUse ti_sysbios_knl_Event_A_eventInUse
#define Event_A_badContext ti_sysbios_knl_Event_A_badContext
#define Event_A_pendTaskDisabled ti_sysbios_knl_Event_A_pendTaskDisabled
#define Event_Instance_State_pendQ ti_sysbios_knl_Event_Instance_State_pendQ
#define Event_Params ti_sysbios_knl_Event_Params
#define Event_pend ti_sysbios_knl_Event_pend
#define Event_post ti_sysbios_knl_Event_post
#define Event_getPostedEvents ti_sysbios_knl_Event_getPostedEvents
#define Event_sync ti_sysbios_knl_Event_sync
#define Event_Module_name ti_sysbios_knl_Event_Module_name
#define Event_Module_id ti_sysbios_knl_Event_Module_id
#define Event_Module_startup ti_sysbios_knl_Event_Module_startup
#define Event_Module_startupDone ti_sysbios_knl_Event_Module_startupDone
#define Event_Module_hasMask ti_sysbios_knl_Event_Module_hasMask
#define Event_Module_getMask ti_sysbios_knl_Event_Module_getMask
#define Event_Module_setMask ti_sysbios_knl_Event_Module_setMask
#define Event_Object_heap ti_sysbios_knl_Event_Object_heap
#define Event_Module_heap ti_sysbios_knl_Event_Module_heap
#define Event_construct ti_sysbios_knl_Event_construct
#define Event_create ti_sysbios_knl_Event_create
#define Event_handle ti_sysbios_knl_Event_handle
#define Event_struct ti_sysbios_knl_Event_struct
#define Event_Handle_label ti_sysbios_knl_Event_Handle_label
#define Event_Handle_name ti_sysbios_knl_Event_Handle_name
#define Event_Instance_init ti_sysbios_knl_Event_Instance_init
#define Event_Object_count ti_sysbios_knl_Event_Object_count
#define Event_Object_get ti_sysbios_knl_Event_Object_get
#define Event_Object_first ti_sysbios_knl_Event_Object_first
#define Event_Object_next ti_sysbios_knl_Event_Object_next
#define Event_Object_sizeof ti_sysbios_knl_Event_Object_sizeof
#define Event_Params_copy ti_sysbios_knl_Event_Params_copy
#define Event_Params_init ti_sysbios_knl_Event_Params_init
#define Event_delete ti_sysbios_knl_Event_delete
#define Event_destruct ti_sysbios_knl_Event_destruct

#endif /* ti_sysbios_knl_Event__localnames__done */
#endif
