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

#ifndef ti_sysbios_gates_GateMutexPri__include
#define ti_sysbios_gates_GateMutexPri__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_gates_GateMutexPri__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_gates_GateMutexPri___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/gates/package/package.defs.h>

#include <xdc/runtime/Assert.h>
#include <ti/sysbios/knl/Queue.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/IGateProvider.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Q_BLOCKING */
#define ti_sysbios_gates_GateMutexPri_Q_BLOCKING (1)

/* Q_PREEMPTING */
#define ti_sysbios_gates_GateMutexPri_Q_PREEMPTING (2)


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_gates_GateMutexPri_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__diagsEnabled ti_sysbios_gates_GateMutexPri_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_gates_GateMutexPri_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__diagsIncluded ti_sysbios_gates_GateMutexPri_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_gates_GateMutexPri_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__diagsMask ti_sysbios_gates_GateMutexPri_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_gates_GateMutexPri_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__gateObj ti_sysbios_gates_GateMutexPri_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_gates_GateMutexPri_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__gatePrms ti_sysbios_gates_GateMutexPri_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_gates_GateMutexPri_Module__id;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__id ti_sysbios_gates_GateMutexPri_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_gates_GateMutexPri_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__loggerDefined ti_sysbios_gates_GateMutexPri_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_gates_GateMutexPri_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__loggerObj ti_sysbios_gates_GateMutexPri_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn0 ti_sysbios_gates_GateMutexPri_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn1 ti_sysbios_gates_GateMutexPri_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn2 ti_sysbios_gates_GateMutexPri_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn4 ti_sysbios_gates_GateMutexPri_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__loggerFxn8 ti_sysbios_gates_GateMutexPri_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_gates_GateMutexPri_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Module__startupDoneFxn ti_sysbios_gates_GateMutexPri_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_gates_GateMutexPri_Object__count;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Object__count ti_sysbios_gates_GateMutexPri_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_gates_GateMutexPri_Object__heap;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Object__heap ti_sysbios_gates_GateMutexPri_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_gates_GateMutexPri_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Object__sizeof ti_sysbios_gates_GateMutexPri_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_gates_GateMutexPri_Object__table;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_Object__table ti_sysbios_gates_GateMutexPri_Object__table__C;

/* A_badContext */
#define ti_sysbios_gates_GateMutexPri_A_badContext (ti_sysbios_gates_GateMutexPri_A_badContext__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_gates_GateMutexPri_A_badContext;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_A_badContext ti_sysbios_gates_GateMutexPri_A_badContext__C;

/* A_enterTaskDisabled */
#define ti_sysbios_gates_GateMutexPri_A_enterTaskDisabled (ti_sysbios_gates_GateMutexPri_A_enterTaskDisabled__C)
typedef xdc_runtime_Assert_Id CT__ti_sysbios_gates_GateMutexPri_A_enterTaskDisabled;
__extern __FAR__ const CT__ti_sysbios_gates_GateMutexPri_A_enterTaskDisabled ti_sysbios_gates_GateMutexPri_A_enterTaskDisabled__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_gates_GateMutexPri_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_gates_GateMutexPri_Struct {
    const ti_sysbios_gates_GateMutexPri_Fxns__ *__fxns;
    volatile xdc_UInt __f0;
    volatile xdc_Int __f1;
    volatile ti_sysbios_knl_Task_Handle __f2;
    ti_sysbios_knl_Queue_Struct __f3;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_gates_GateMutexPri_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bool (*query)(xdc_Int);
    xdc_IArg (*enter)(ti_sysbios_gates_GateMutexPri_Handle);
    xdc_Void (*leave)(ti_sysbios_gates_GateMutexPri_Handle, xdc_IArg);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_gates_GateMutexPri_Fxns__ ti_sysbios_gates_GateMutexPri_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_gates_GateMutexPri_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Instance_init__E, "ti_sysbios_gates_GateMutexPri_Instance_init")
__extern xdc_Void ti_sysbios_gates_GateMutexPri_Instance_init__E(ti_sysbios_gates_GateMutexPri_Object *, const ti_sysbios_gates_GateMutexPri_Params *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Instance_finalize__E, "ti_sysbios_gates_GateMutexPri_Instance_finalize")
__extern void ti_sysbios_gates_GateMutexPri_Instance_finalize__E( ti_sysbios_gates_GateMutexPri_Object* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Handle__label__S, "ti_sysbios_gates_GateMutexPri_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_gates_GateMutexPri_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Module__startupDone__S, "ti_sysbios_gates_GateMutexPri_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_gates_GateMutexPri_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Object__create__S, "ti_sysbios_gates_GateMutexPri_Object__create__S")
__extern xdc_Ptr ti_sysbios_gates_GateMutexPri_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_create, "ti_sysbios_gates_GateMutexPri_create")
__extern ti_sysbios_gates_GateMutexPri_Handle ti_sysbios_gates_GateMutexPri_create( const ti_sysbios_gates_GateMutexPri_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_construct, "ti_sysbios_gates_GateMutexPri_construct")
__extern void ti_sysbios_gates_GateMutexPri_construct( ti_sysbios_gates_GateMutexPri_Struct *__obj, const ti_sysbios_gates_GateMutexPri_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Object__delete__S, "ti_sysbios_gates_GateMutexPri_Object__delete__S")
__extern xdc_Void ti_sysbios_gates_GateMutexPri_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_delete, "ti_sysbios_gates_GateMutexPri_delete")
__extern void ti_sysbios_gates_GateMutexPri_delete(ti_sysbios_gates_GateMutexPri_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Object__destruct__S, "ti_sysbios_gates_GateMutexPri_Object__destruct__S")
__extern xdc_Void ti_sysbios_gates_GateMutexPri_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_destruct, "ti_sysbios_gates_GateMutexPri_destruct")
__extern void ti_sysbios_gates_GateMutexPri_destruct(ti_sysbios_gates_GateMutexPri_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Object__get__S, "ti_sysbios_gates_GateMutexPri_Object__get__S")
__extern xdc_Ptr ti_sysbios_gates_GateMutexPri_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Object__first__S, "ti_sysbios_gates_GateMutexPri_Object__first__S")
__extern xdc_Ptr ti_sysbios_gates_GateMutexPri_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Object__next__S, "ti_sysbios_gates_GateMutexPri_Object__next__S")
__extern xdc_Ptr ti_sysbios_gates_GateMutexPri_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_Params__init__S, "ti_sysbios_gates_GateMutexPri_Params__init__S")
__extern xdc_Void ti_sysbios_gates_GateMutexPri_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* query__E */
#define ti_sysbios_gates_GateMutexPri_query ti_sysbios_gates_GateMutexPri_query__E
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_query__E, "ti_sysbios_gates_GateMutexPri_query")
__extern xdc_Bool ti_sysbios_gates_GateMutexPri_query__E( xdc_Int qual );

/* enter__E */
#define ti_sysbios_gates_GateMutexPri_enter ti_sysbios_gates_GateMutexPri_enter__E
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_enter__E, "ti_sysbios_gates_GateMutexPri_enter")
__extern xdc_IArg ti_sysbios_gates_GateMutexPri_enter__E( ti_sysbios_gates_GateMutexPri_Handle __inst );

/* leave__E */
#define ti_sysbios_gates_GateMutexPri_leave ti_sysbios_gates_GateMutexPri_leave__E
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_leave__E, "ti_sysbios_gates_GateMutexPri_leave")
__extern xdc_Void ti_sysbios_gates_GateMutexPri_leave__E( ti_sysbios_gates_GateMutexPri_Handle __inst, xdc_IArg key );

/* insertPri__I */
#define ti_sysbios_gates_GateMutexPri_insertPri ti_sysbios_gates_GateMutexPri_insertPri__I
xdc__CODESECT(ti_sysbios_gates_GateMutexPri_insertPri__I, "ti_sysbios_gates_GateMutexPri_insertPri")
__extern xdc_Void ti_sysbios_gates_GateMutexPri_insertPri__I( ti_sysbios_knl_Queue_Object *queue, ti_sysbios_knl_Queue_Elem *newElem, xdc_Int newPri );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IGateProvider_Module ti_sysbios_gates_GateMutexPri_Module_upCast( void )
{
    return (xdc_runtime_IGateProvider_Module)&ti_sysbios_gates_GateMutexPri_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IGateProvider */
#define ti_sysbios_gates_GateMutexPri_Module_to_xdc_runtime_IGateProvider ti_sysbios_gates_GateMutexPri_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IGateProvider_Handle ti_sysbios_gates_GateMutexPri_Handle_upCast( ti_sysbios_gates_GateMutexPri_Handle i )
{
    return (xdc_runtime_IGateProvider_Handle)i;
}

/* Handle_to_xdc_runtime_IGateProvider */
#define ti_sysbios_gates_GateMutexPri_Handle_to_xdc_runtime_IGateProvider ti_sysbios_gates_GateMutexPri_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_gates_GateMutexPri_Handle ti_sysbios_gates_GateMutexPri_Handle_downCast( xdc_runtime_IGateProvider_Handle i )
{
    xdc_runtime_IGateProvider_Handle i2 = (xdc_runtime_IGateProvider_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_gates_GateMutexPri_Module__FXNS__C ? (ti_sysbios_gates_GateMutexPri_Handle)i : 0;
}

/* Handle_from_xdc_runtime_IGateProvider */
#define ti_sysbios_gates_GateMutexPri_Handle_from_xdc_runtime_IGateProvider ti_sysbios_gates_GateMutexPri_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_gates_GateMutexPri_Module_startupDone() ti_sysbios_gates_GateMutexPri_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_gates_GateMutexPri_Object_heap() ti_sysbios_gates_GateMutexPri_Object__heap__C

/* Module_heap */
#define ti_sysbios_gates_GateMutexPri_Module_heap() ti_sysbios_gates_GateMutexPri_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_gates_GateMutexPri_Module__id ti_sysbios_gates_GateMutexPri_Module_id( void ) 
{
    return ti_sysbios_gates_GateMutexPri_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_gates_GateMutexPri_Module_hasMask( void ) 
{
    return ti_sysbios_gates_GateMutexPri_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_gates_GateMutexPri_Module_getMask( void ) 
{
    return ti_sysbios_gates_GateMutexPri_Module__diagsMask__C != NULL ? *ti_sysbios_gates_GateMutexPri_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_gates_GateMutexPri_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_gates_GateMutexPri_Module__diagsMask__C != NULL) *ti_sysbios_gates_GateMutexPri_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_gates_GateMutexPri_Params_init( ti_sysbios_gates_GateMutexPri_Params *prms ) 
{
    if (prms) {
        ti_sysbios_gates_GateMutexPri_Params__init__S(prms, 0, sizeof(ti_sysbios_gates_GateMutexPri_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_gates_GateMutexPri_Params_copy(ti_sysbios_gates_GateMutexPri_Params *dst, const ti_sysbios_gates_GateMutexPri_Params *src) 
{
    if (dst) {
        ti_sysbios_gates_GateMutexPri_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_gates_GateMutexPri_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_gates_GateMutexPri_Object_count() ti_sysbios_gates_GateMutexPri_Object__count__C

/* Object_sizeof */
#define ti_sysbios_gates_GateMutexPri_Object_sizeof() ti_sysbios_gates_GateMutexPri_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_gates_GateMutexPri_Handle ti_sysbios_gates_GateMutexPri_Object_get(ti_sysbios_gates_GateMutexPri_Instance_State *oarr, int i) 
{
    return (ti_sysbios_gates_GateMutexPri_Handle)ti_sysbios_gates_GateMutexPri_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_gates_GateMutexPri_Handle ti_sysbios_gates_GateMutexPri_Object_first( void )
{
    return (ti_sysbios_gates_GateMutexPri_Handle)ti_sysbios_gates_GateMutexPri_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_gates_GateMutexPri_Handle ti_sysbios_gates_GateMutexPri_Object_next( ti_sysbios_gates_GateMutexPri_Object *obj )
{
    return (ti_sysbios_gates_GateMutexPri_Handle)ti_sysbios_gates_GateMutexPri_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_gates_GateMutexPri_Handle_label( ti_sysbios_gates_GateMutexPri_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_gates_GateMutexPri_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_gates_GateMutexPri_Handle_name( ti_sysbios_gates_GateMutexPri_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_gates_GateMutexPri_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_gates_GateMutexPri_Handle ti_sysbios_gates_GateMutexPri_handle( ti_sysbios_gates_GateMutexPri_Struct *str )
{
    return (ti_sysbios_gates_GateMutexPri_Handle)str;
}

/* struct */
static inline ti_sysbios_gates_GateMutexPri_Struct *ti_sysbios_gates_GateMutexPri_struct( ti_sysbios_gates_GateMutexPri_Handle inst )
{
    return (ti_sysbios_gates_GateMutexPri_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_gates_GateMutexPri__top__
#undef __nested__
#endif

#endif /* ti_sysbios_gates_GateMutexPri__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_gates_GateMutexPri__internalaccess))

#ifndef ti_sysbios_gates_GateMutexPri__include_state
#define ti_sysbios_gates_GateMutexPri__include_state

/* Object */
struct ti_sysbios_gates_GateMutexPri_Object {
    const ti_sysbios_gates_GateMutexPri_Fxns__ *__fxns;
    volatile xdc_UInt mutexCnt;
    volatile xdc_Int ownerOrigPri;
    volatile ti_sysbios_knl_Task_Handle owner;
    char __dummy;
};

/* Instance_State_pendQ */
__extern __FAR__ const xdc_SizeT ti_sysbios_gates_GateMutexPri_Instance_State_pendQ__O;
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_gates_GateMutexPri_Instance_State_pendQ(ti_sysbios_gates_GateMutexPri_Object *obj)
{
    return (ti_sysbios_knl_Queue_Handle)(((char*)obj) + ti_sysbios_gates_GateMutexPri_Instance_State_pendQ__O);
}

#endif /* ti_sysbios_gates_GateMutexPri__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_gates_GateMutexPri__nolocalnames)

#ifndef ti_sysbios_gates_GateMutexPri__localnames__done
#define ti_sysbios_gates_GateMutexPri__localnames__done

/* module prefix */
#define GateMutexPri_Instance ti_sysbios_gates_GateMutexPri_Instance
#define GateMutexPri_Handle ti_sysbios_gates_GateMutexPri_Handle
#define GateMutexPri_Module ti_sysbios_gates_GateMutexPri_Module
#define GateMutexPri_Object ti_sysbios_gates_GateMutexPri_Object
#define GateMutexPri_Struct ti_sysbios_gates_GateMutexPri_Struct
#define GateMutexPri_Q_BLOCKING ti_sysbios_gates_GateMutexPri_Q_BLOCKING
#define GateMutexPri_Q_PREEMPTING ti_sysbios_gates_GateMutexPri_Q_PREEMPTING
#define GateMutexPri_Instance_State ti_sysbios_gates_GateMutexPri_Instance_State
#define GateMutexPri_A_badContext ti_sysbios_gates_GateMutexPri_A_badContext
#define GateMutexPri_A_enterTaskDisabled ti_sysbios_gates_GateMutexPri_A_enterTaskDisabled
#define GateMutexPri_Instance_State_pendQ ti_sysbios_gates_GateMutexPri_Instance_State_pendQ
#define GateMutexPri_Params ti_sysbios_gates_GateMutexPri_Params
#define GateMutexPri_query ti_sysbios_gates_GateMutexPri_query
#define GateMutexPri_enter ti_sysbios_gates_GateMutexPri_enter
#define GateMutexPri_leave ti_sysbios_gates_GateMutexPri_leave
#define GateMutexPri_Module_name ti_sysbios_gates_GateMutexPri_Module_name
#define GateMutexPri_Module_id ti_sysbios_gates_GateMutexPri_Module_id
#define GateMutexPri_Module_startup ti_sysbios_gates_GateMutexPri_Module_startup
#define GateMutexPri_Module_startupDone ti_sysbios_gates_GateMutexPri_Module_startupDone
#define GateMutexPri_Module_hasMask ti_sysbios_gates_GateMutexPri_Module_hasMask
#define GateMutexPri_Module_getMask ti_sysbios_gates_GateMutexPri_Module_getMask
#define GateMutexPri_Module_setMask ti_sysbios_gates_GateMutexPri_Module_setMask
#define GateMutexPri_Object_heap ti_sysbios_gates_GateMutexPri_Object_heap
#define GateMutexPri_Module_heap ti_sysbios_gates_GateMutexPri_Module_heap
#define GateMutexPri_construct ti_sysbios_gates_GateMutexPri_construct
#define GateMutexPri_create ti_sysbios_gates_GateMutexPri_create
#define GateMutexPri_handle ti_sysbios_gates_GateMutexPri_handle
#define GateMutexPri_struct ti_sysbios_gates_GateMutexPri_struct
#define GateMutexPri_Handle_label ti_sysbios_gates_GateMutexPri_Handle_label
#define GateMutexPri_Handle_name ti_sysbios_gates_GateMutexPri_Handle_name
#define GateMutexPri_Instance_init ti_sysbios_gates_GateMutexPri_Instance_init
#define GateMutexPri_Object_count ti_sysbios_gates_GateMutexPri_Object_count
#define GateMutexPri_Object_get ti_sysbios_gates_GateMutexPri_Object_get
#define GateMutexPri_Object_first ti_sysbios_gates_GateMutexPri_Object_first
#define GateMutexPri_Object_next ti_sysbios_gates_GateMutexPri_Object_next
#define GateMutexPri_Object_sizeof ti_sysbios_gates_GateMutexPri_Object_sizeof
#define GateMutexPri_Params_copy ti_sysbios_gates_GateMutexPri_Params_copy
#define GateMutexPri_Params_init ti_sysbios_gates_GateMutexPri_Params_init
#define GateMutexPri_Instance_finalize ti_sysbios_gates_GateMutexPri_Instance_finalize
#define GateMutexPri_delete ti_sysbios_gates_GateMutexPri_delete
#define GateMutexPri_destruct ti_sysbios_gates_GateMutexPri_destruct
#define GateMutexPri_Module_upCast ti_sysbios_gates_GateMutexPri_Module_upCast
#define GateMutexPri_Module_to_xdc_runtime_IGateProvider ti_sysbios_gates_GateMutexPri_Module_to_xdc_runtime_IGateProvider
#define GateMutexPri_Handle_upCast ti_sysbios_gates_GateMutexPri_Handle_upCast
#define GateMutexPri_Handle_to_xdc_runtime_IGateProvider ti_sysbios_gates_GateMutexPri_Handle_to_xdc_runtime_IGateProvider
#define GateMutexPri_Handle_downCast ti_sysbios_gates_GateMutexPri_Handle_downCast
#define GateMutexPri_Handle_from_xdc_runtime_IGateProvider ti_sysbios_gates_GateMutexPri_Handle_from_xdc_runtime_IGateProvider

#endif /* ti_sysbios_gates_GateMutexPri__localnames__done */
#endif
