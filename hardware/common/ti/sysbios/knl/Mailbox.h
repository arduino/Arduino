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

#ifndef ti_sysbios_knl_Mailbox__include
#define ti_sysbios_knl_Mailbox__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_knl_Mailbox__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_knl_Mailbox___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/knl/package/package.defs.h>

#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/IModule.h>
#include <ti/sysbios/knl/Queue.h>
#include <xdc/runtime/Assert.h>
#include <ti/sysbios/knl/Event.h>
#include <ti/sysbios/knl/Semaphore.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* MbxElem */
struct ti_sysbios_knl_Mailbox_MbxElem {
    ti_sysbios_knl_Queue_Elem elem;
};


/*
 * ======== CREATE ARGS ========
 */

/* Args__create */
typedef struct ti_sysbios_knl_Mailbox_Args__create {
    xdc_SizeT msgSize;
    xdc_UInt numMsgs;
} ti_sysbios_knl_Mailbox_Args__create;


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* Instance_State */
typedef xdc_Char __T1_ti_sysbios_knl_Mailbox_Instance_State__allocBuf;
typedef xdc_Char *__ARRAY1_ti_sysbios_knl_Mailbox_Instance_State__allocBuf;
typedef __ARRAY1_ti_sysbios_knl_Mailbox_Instance_State__allocBuf __TA_ti_sysbios_knl_Mailbox_Instance_State__allocBuf;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_knl_Mailbox_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__diagsEnabled ti_sysbios_knl_Mailbox_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_knl_Mailbox_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__diagsIncluded ti_sysbios_knl_Mailbox_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_knl_Mailbox_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__diagsMask ti_sysbios_knl_Mailbox_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Mailbox_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__gateObj ti_sysbios_knl_Mailbox_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_knl_Mailbox_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__gatePrms ti_sysbios_knl_Mailbox_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_knl_Mailbox_Module__id;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__id ti_sysbios_knl_Mailbox_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_knl_Mailbox_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__loggerDefined ti_sysbios_knl_Mailbox_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Mailbox_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__loggerObj ti_sysbios_knl_Mailbox_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_knl_Mailbox_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__loggerFxn0 ti_sysbios_knl_Mailbox_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_knl_Mailbox_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__loggerFxn1 ti_sysbios_knl_Mailbox_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_knl_Mailbox_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__loggerFxn2 ti_sysbios_knl_Mailbox_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_knl_Mailbox_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__loggerFxn4 ti_sysbios_knl_Mailbox_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_knl_Mailbox_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__loggerFxn8 ti_sysbios_knl_Mailbox_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_knl_Mailbox_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Module__startupDoneFxn ti_sysbios_knl_Mailbox_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_knl_Mailbox_Object__count;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Object__count ti_sysbios_knl_Mailbox_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_knl_Mailbox_Object__heap;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Object__heap ti_sysbios_knl_Mailbox_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_knl_Mailbox_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Object__sizeof ti_sysbios_knl_Mailbox_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_knl_Mailbox_Object__table;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_Object__table ti_sysbios_knl_Mailbox_Object__table__C;

/* A_invalidBufSize */
#define ti_sysbios_knl_Mailbox_A_invalidBufSize (ti_sysbios_knl_Mailbox_A_invalidBufSize__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_knl_Mailbox_A_invalidBufSize;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_A_invalidBufSize ti_sysbios_knl_Mailbox_A_invalidBufSize__C;

/* maxTypeAlign */
#ifdef ti_sysbios_knl_Mailbox_maxTypeAlign__D
#define ti_sysbios_knl_Mailbox_maxTypeAlign (ti_sysbios_knl_Mailbox_maxTypeAlign__D)
#else
#define ti_sysbios_knl_Mailbox_maxTypeAlign (ti_sysbios_knl_Mailbox_maxTypeAlign__C)
typedef xdc_UInt CT__ti_sysbios_knl_Mailbox_maxTypeAlign;
__extern __FAR__ const CT__ti_sysbios_knl_Mailbox_maxTypeAlign ti_sysbios_knl_Mailbox_maxTypeAlign__C;
#endif


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_knl_Mailbox_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IHeap_Handle heap;
    ti_sysbios_knl_Event_Handle readerEvent;
    xdc_UInt readerEventId;
    ti_sysbios_knl_Event_Handle writerEvent;
    xdc_UInt writerEventId;
    xdc_Ptr buf;
    xdc_UInt bufSize;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_knl_Mailbox_Struct {
    xdc_runtime_IHeap_Handle __f0;
    xdc_SizeT __f1;
    xdc_UInt __f2;
    xdc_Ptr __f3;
    xdc_UInt __f4;
    __TA_ti_sysbios_knl_Mailbox_Instance_State__allocBuf __f5;
    ti_sysbios_knl_Queue_Struct __f6;
    ti_sysbios_knl_Queue_Struct __f7;
    ti_sysbios_knl_Semaphore_Struct __f8;
    ti_sysbios_knl_Semaphore_Struct __f9;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_knl_Mailbox_Module_startup ti_sysbios_knl_Mailbox_Module_startup__E
xdc__CODESECT(ti_sysbios_knl_Mailbox_Module_startup__E, "ti_sysbios_knl_Mailbox_Module_startup")
__extern xdc_Int ti_sysbios_knl_Mailbox_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_knl_Mailbox_Module_startup__F, "ti_sysbios_knl_Mailbox_Module_startup")
__extern xdc_Int ti_sysbios_knl_Mailbox_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Instance_init__E, "ti_sysbios_knl_Mailbox_Instance_init")
__extern xdc_Int ti_sysbios_knl_Mailbox_Instance_init__E(ti_sysbios_knl_Mailbox_Object *, xdc_SizeT msgSize, xdc_UInt numMsgs, const ti_sysbios_knl_Mailbox_Params *, xdc_runtime_Error_Block *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Instance_finalize__E, "ti_sysbios_knl_Mailbox_Instance_finalize")
__extern void ti_sysbios_knl_Mailbox_Instance_finalize__E( ti_sysbios_knl_Mailbox_Object* , int );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Handle__label__S, "ti_sysbios_knl_Mailbox_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_knl_Mailbox_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Module__startupDone__S, "ti_sysbios_knl_Mailbox_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_knl_Mailbox_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Object__create__S, "ti_sysbios_knl_Mailbox_Object__create__S")
__extern xdc_Ptr ti_sysbios_knl_Mailbox_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_knl_Mailbox_create, "ti_sysbios_knl_Mailbox_create")
__extern ti_sysbios_knl_Mailbox_Handle ti_sysbios_knl_Mailbox_create( xdc_SizeT msgSize, xdc_UInt numMsgs, const ti_sysbios_knl_Mailbox_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_knl_Mailbox_construct, "ti_sysbios_knl_Mailbox_construct")
__extern void ti_sysbios_knl_Mailbox_construct( ti_sysbios_knl_Mailbox_Struct *__obj, xdc_SizeT msgSize, xdc_UInt numMsgs, const ti_sysbios_knl_Mailbox_Params *__prms, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Object__delete__S, "ti_sysbios_knl_Mailbox_Object__delete__S")
__extern xdc_Void ti_sysbios_knl_Mailbox_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_knl_Mailbox_delete, "ti_sysbios_knl_Mailbox_delete")
__extern void ti_sysbios_knl_Mailbox_delete(ti_sysbios_knl_Mailbox_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Object__destruct__S, "ti_sysbios_knl_Mailbox_Object__destruct__S")
__extern xdc_Void ti_sysbios_knl_Mailbox_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_knl_Mailbox_destruct, "ti_sysbios_knl_Mailbox_destruct")
__extern void ti_sysbios_knl_Mailbox_destruct(ti_sysbios_knl_Mailbox_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Object__get__S, "ti_sysbios_knl_Mailbox_Object__get__S")
__extern xdc_Ptr ti_sysbios_knl_Mailbox_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Object__first__S, "ti_sysbios_knl_Mailbox_Object__first__S")
__extern xdc_Ptr ti_sysbios_knl_Mailbox_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Object__next__S, "ti_sysbios_knl_Mailbox_Object__next__S")
__extern xdc_Ptr ti_sysbios_knl_Mailbox_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_knl_Mailbox_Params__init__S, "ti_sysbios_knl_Mailbox_Params__init__S")
__extern xdc_Void ti_sysbios_knl_Mailbox_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* getMsgSize__E */
#define ti_sysbios_knl_Mailbox_getMsgSize ti_sysbios_knl_Mailbox_getMsgSize__E
xdc__CODESECT(ti_sysbios_knl_Mailbox_getMsgSize__E, "ti_sysbios_knl_Mailbox_getMsgSize")
__extern xdc_SizeT ti_sysbios_knl_Mailbox_getMsgSize__E( ti_sysbios_knl_Mailbox_Handle __inst );

/* getNumFreeMsgs__E */
#define ti_sysbios_knl_Mailbox_getNumFreeMsgs ti_sysbios_knl_Mailbox_getNumFreeMsgs__E
xdc__CODESECT(ti_sysbios_knl_Mailbox_getNumFreeMsgs__E, "ti_sysbios_knl_Mailbox_getNumFreeMsgs")
__extern xdc_Int ti_sysbios_knl_Mailbox_getNumFreeMsgs__E( ti_sysbios_knl_Mailbox_Handle __inst );

/* getNumPendingMsgs__E */
#define ti_sysbios_knl_Mailbox_getNumPendingMsgs ti_sysbios_knl_Mailbox_getNumPendingMsgs__E
xdc__CODESECT(ti_sysbios_knl_Mailbox_getNumPendingMsgs__E, "ti_sysbios_knl_Mailbox_getNumPendingMsgs")
__extern xdc_Int ti_sysbios_knl_Mailbox_getNumPendingMsgs__E( ti_sysbios_knl_Mailbox_Handle __inst );

/* pend__E */
#define ti_sysbios_knl_Mailbox_pend ti_sysbios_knl_Mailbox_pend__E
xdc__CODESECT(ti_sysbios_knl_Mailbox_pend__E, "ti_sysbios_knl_Mailbox_pend")
__extern xdc_Bool ti_sysbios_knl_Mailbox_pend__E( ti_sysbios_knl_Mailbox_Handle __inst, xdc_Ptr msg, xdc_UInt32 timeout );

/* post__E */
#define ti_sysbios_knl_Mailbox_post ti_sysbios_knl_Mailbox_post__E
xdc__CODESECT(ti_sysbios_knl_Mailbox_post__E, "ti_sysbios_knl_Mailbox_post")
__extern xdc_Bool ti_sysbios_knl_Mailbox_post__E( ti_sysbios_knl_Mailbox_Handle __inst, xdc_Ptr msg, xdc_UInt32 timeout );

/* cleanQue__I */
#define ti_sysbios_knl_Mailbox_cleanQue ti_sysbios_knl_Mailbox_cleanQue__I
xdc__CODESECT(ti_sysbios_knl_Mailbox_cleanQue__I, "ti_sysbios_knl_Mailbox_cleanQue")
__extern xdc_Void ti_sysbios_knl_Mailbox_cleanQue__I( ti_sysbios_knl_Queue_Handle obj );

/* postInit__I */
#define ti_sysbios_knl_Mailbox_postInit ti_sysbios_knl_Mailbox_postInit__I
xdc__CODESECT(ti_sysbios_knl_Mailbox_postInit__I, "ti_sysbios_knl_Mailbox_postInit")
__extern xdc_Int ti_sysbios_knl_Mailbox_postInit__I( ti_sysbios_knl_Mailbox_Object *obj, xdc_SizeT blockSize );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_knl_Mailbox_Module_startupDone() ti_sysbios_knl_Mailbox_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_knl_Mailbox_Object_heap() ti_sysbios_knl_Mailbox_Object__heap__C

/* Module_heap */
#define ti_sysbios_knl_Mailbox_Module_heap() ti_sysbios_knl_Mailbox_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_knl_Mailbox_Module__id ti_sysbios_knl_Mailbox_Module_id( void ) 
{
    return ti_sysbios_knl_Mailbox_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_knl_Mailbox_Module_hasMask( void ) 
{
    return ti_sysbios_knl_Mailbox_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_knl_Mailbox_Module_getMask( void ) 
{
    return ti_sysbios_knl_Mailbox_Module__diagsMask__C != NULL ? *ti_sysbios_knl_Mailbox_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_knl_Mailbox_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_knl_Mailbox_Module__diagsMask__C != NULL) *ti_sysbios_knl_Mailbox_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_knl_Mailbox_Params_init( ti_sysbios_knl_Mailbox_Params *prms ) 
{
    if (prms) {
        ti_sysbios_knl_Mailbox_Params__init__S(prms, 0, sizeof(ti_sysbios_knl_Mailbox_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_knl_Mailbox_Params_copy(ti_sysbios_knl_Mailbox_Params *dst, const ti_sysbios_knl_Mailbox_Params *src) 
{
    if (dst) {
        ti_sysbios_knl_Mailbox_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_knl_Mailbox_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_knl_Mailbox_Object_count() ti_sysbios_knl_Mailbox_Object__count__C

/* Object_sizeof */
#define ti_sysbios_knl_Mailbox_Object_sizeof() ti_sysbios_knl_Mailbox_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_knl_Mailbox_Handle ti_sysbios_knl_Mailbox_Object_get(ti_sysbios_knl_Mailbox_Instance_State *oarr, int i) 
{
    return (ti_sysbios_knl_Mailbox_Handle)ti_sysbios_knl_Mailbox_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_knl_Mailbox_Handle ti_sysbios_knl_Mailbox_Object_first( void )
{
    return (ti_sysbios_knl_Mailbox_Handle)ti_sysbios_knl_Mailbox_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_knl_Mailbox_Handle ti_sysbios_knl_Mailbox_Object_next( ti_sysbios_knl_Mailbox_Object *obj )
{
    return (ti_sysbios_knl_Mailbox_Handle)ti_sysbios_knl_Mailbox_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_knl_Mailbox_Handle_label( ti_sysbios_knl_Mailbox_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_knl_Mailbox_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_knl_Mailbox_Handle_name( ti_sysbios_knl_Mailbox_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_knl_Mailbox_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_knl_Mailbox_Handle ti_sysbios_knl_Mailbox_handle( ti_sysbios_knl_Mailbox_Struct *str )
{
    return (ti_sysbios_knl_Mailbox_Handle)str;
}

/* struct */
static inline ti_sysbios_knl_Mailbox_Struct *ti_sysbios_knl_Mailbox_struct( ti_sysbios_knl_Mailbox_Handle inst )
{
    return (ti_sysbios_knl_Mailbox_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_knl_Mailbox__top__
#undef __nested__
#endif

#endif /* ti_sysbios_knl_Mailbox__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_knl_Mailbox__internalaccess))

#ifndef ti_sysbios_knl_Mailbox__include_state
#define ti_sysbios_knl_Mailbox__include_state

/* Object */
struct ti_sysbios_knl_Mailbox_Object {
    xdc_runtime_IHeap_Handle heap;
    xdc_SizeT msgSize;
    xdc_UInt numMsgs;
    xdc_Ptr buf;
    xdc_UInt numFreeMsgs;
    __TA_ti_sysbios_knl_Mailbox_Instance_State__allocBuf allocBuf;
    char __dummy;
};

/* Instance_State_dataQue */
__extern __FAR__ const xdc_SizeT ti_sysbios_knl_Mailbox_Instance_State_dataQue__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Mailbox_Instance_State_dataQue(ti_sysbios_knl_Mailbox_Object *obj)
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)obj) + ti_sysbios_knl_Mailbox_Instance_State_dataQue__O);
}

/* Instance_State_freeQue */
__extern __FAR__ const xdc_SizeT ti_sysbios_knl_Mailbox_Instance_State_freeQue__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Mailbox_Instance_State_freeQue(ti_sysbios_knl_Mailbox_Object *obj)
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)obj) + ti_sysbios_knl_Mailbox_Instance_State_freeQue__O);
}

/* Instance_State_dataSem */
__extern __FAR__ const xdc_SizeT ti_sysbios_knl_Mailbox_Instance_State_dataSem__O;
static inline ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Mailbox_Instance_State_dataSem(ti_sysbios_knl_Mailbox_Object *obj)
{
    return (ti_sysbios_knl_Semaphore_Handle)(((char*)obj) + ti_sysbios_knl_Mailbox_Instance_State_dataSem__O);
}

/* Instance_State_freeSem */
__extern __FAR__ const xdc_SizeT ti_sysbios_knl_Mailbox_Instance_State_freeSem__O;
static inline ti_sysbios_knl_Semaphore_Handle ti_sysbios_knl_Mailbox_Instance_State_freeSem(ti_sysbios_knl_Mailbox_Object *obj)
{
    return (ti_sysbios_knl_Semaphore_Handle)(((char*)obj) + ti_sysbios_knl_Mailbox_Instance_State_freeSem__O);
}

#endif /* ti_sysbios_knl_Mailbox__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_knl_Mailbox__nolocalnames)

#ifndef ti_sysbios_knl_Mailbox__localnames__done
#define ti_sysbios_knl_Mailbox__localnames__done

/* module prefix */
#define Mailbox_Instance ti_sysbios_knl_Mailbox_Instance
#define Mailbox_Handle ti_sysbios_knl_Mailbox_Handle
#define Mailbox_Module ti_sysbios_knl_Mailbox_Module
#define Mailbox_Object ti_sysbios_knl_Mailbox_Object
#define Mailbox_Struct ti_sysbios_knl_Mailbox_Struct
#define Mailbox_MbxElem ti_sysbios_knl_Mailbox_MbxElem
#define Mailbox_Instance_State ti_sysbios_knl_Mailbox_Instance_State
#define Mailbox_A_invalidBufSize ti_sysbios_knl_Mailbox_A_invalidBufSize
#define Mailbox_maxTypeAlign ti_sysbios_knl_Mailbox_maxTypeAlign
#define Mailbox_Instance_State_dataQue ti_sysbios_knl_Mailbox_Instance_State_dataQue
#define Mailbox_Instance_State_freeQue ti_sysbios_knl_Mailbox_Instance_State_freeQue
#define Mailbox_Instance_State_dataSem ti_sysbios_knl_Mailbox_Instance_State_dataSem
#define Mailbox_Instance_State_freeSem ti_sysbios_knl_Mailbox_Instance_State_freeSem
#define Mailbox_Params ti_sysbios_knl_Mailbox_Params
#define Mailbox_getMsgSize ti_sysbios_knl_Mailbox_getMsgSize
#define Mailbox_getNumFreeMsgs ti_sysbios_knl_Mailbox_getNumFreeMsgs
#define Mailbox_getNumPendingMsgs ti_sysbios_knl_Mailbox_getNumPendingMsgs
#define Mailbox_pend ti_sysbios_knl_Mailbox_pend
#define Mailbox_post ti_sysbios_knl_Mailbox_post
#define Mailbox_Module_name ti_sysbios_knl_Mailbox_Module_name
#define Mailbox_Module_id ti_sysbios_knl_Mailbox_Module_id
#define Mailbox_Module_startup ti_sysbios_knl_Mailbox_Module_startup
#define Mailbox_Module_startupDone ti_sysbios_knl_Mailbox_Module_startupDone
#define Mailbox_Module_hasMask ti_sysbios_knl_Mailbox_Module_hasMask
#define Mailbox_Module_getMask ti_sysbios_knl_Mailbox_Module_getMask
#define Mailbox_Module_setMask ti_sysbios_knl_Mailbox_Module_setMask
#define Mailbox_Object_heap ti_sysbios_knl_Mailbox_Object_heap
#define Mailbox_Module_heap ti_sysbios_knl_Mailbox_Module_heap
#define Mailbox_construct ti_sysbios_knl_Mailbox_construct
#define Mailbox_create ti_sysbios_knl_Mailbox_create
#define Mailbox_handle ti_sysbios_knl_Mailbox_handle
#define Mailbox_struct ti_sysbios_knl_Mailbox_struct
#define Mailbox_Handle_label ti_sysbios_knl_Mailbox_Handle_label
#define Mailbox_Handle_name ti_sysbios_knl_Mailbox_Handle_name
#define Mailbox_Instance_init ti_sysbios_knl_Mailbox_Instance_init
#define Mailbox_Object_count ti_sysbios_knl_Mailbox_Object_count
#define Mailbox_Object_get ti_sysbios_knl_Mailbox_Object_get
#define Mailbox_Object_first ti_sysbios_knl_Mailbox_Object_first
#define Mailbox_Object_next ti_sysbios_knl_Mailbox_Object_next
#define Mailbox_Object_sizeof ti_sysbios_knl_Mailbox_Object_sizeof
#define Mailbox_Params_copy ti_sysbios_knl_Mailbox_Params_copy
#define Mailbox_Params_init ti_sysbios_knl_Mailbox_Params_init
#define Mailbox_Instance_finalize ti_sysbios_knl_Mailbox_Instance_finalize
#define Mailbox_delete ti_sysbios_knl_Mailbox_delete
#define Mailbox_destruct ti_sysbios_knl_Mailbox_destruct

#endif /* ti_sysbios_knl_Mailbox__localnames__done */
#endif
