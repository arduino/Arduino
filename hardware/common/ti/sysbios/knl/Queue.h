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

#ifndef ti_sysbios_knl_Queue__include
#define ti_sysbios_knl_Queue__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_knl_Queue__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_knl_Queue___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/knl/package/package.defs.h>

#include <xdc/runtime/IModule.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Elem */
struct ti_sysbios_knl_Queue_Elem {
    ti_sysbios_knl_Queue_Elem *volatile next;
    ti_sysbios_knl_Queue_Elem *volatile prev;
};


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_knl_Queue_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsEnabled ti_sysbios_knl_Queue_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_knl_Queue_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsIncluded ti_sysbios_knl_Queue_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_knl_Queue_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__diagsMask ti_sysbios_knl_Queue_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Queue_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__gateObj ti_sysbios_knl_Queue_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_knl_Queue_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__gatePrms ti_sysbios_knl_Queue_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_knl_Queue_Module__id;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_knl_Queue_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerDefined ti_sysbios_knl_Queue_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_knl_Queue_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerObj ti_sysbios_knl_Queue_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_knl_Queue_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn0 ti_sysbios_knl_Queue_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_knl_Queue_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn1 ti_sysbios_knl_Queue_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_knl_Queue_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn2 ti_sysbios_knl_Queue_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_knl_Queue_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn4 ti_sysbios_knl_Queue_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_knl_Queue_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__loggerFxn8 ti_sysbios_knl_Queue_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_knl_Queue_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Module__startupDoneFxn ti_sysbios_knl_Queue_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_knl_Queue_Object__count;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Object__count ti_sysbios_knl_Queue_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_knl_Queue_Object__heap;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Object__heap ti_sysbios_knl_Queue_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_knl_Queue_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Object__sizeof ti_sysbios_knl_Queue_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_knl_Queue_Object__table;
__extern __FAR__ const CT__ti_sysbios_knl_Queue_Object__table ti_sysbios_knl_Queue_Object__table__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_knl_Queue_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_knl_Queue_Struct {
    ti_sysbios_knl_Queue_Elem __f0;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_knl_Queue_Module_startup( state ) (-1)

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_knl_Queue_Instance_init__E, "ti_sysbios_knl_Queue_Instance_init")
__extern xdc_Void ti_sysbios_knl_Queue_Instance_init__E(ti_sysbios_knl_Queue_Object *, const ti_sysbios_knl_Queue_Params *);

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Handle__label__S, "ti_sysbios_knl_Queue_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_knl_Queue_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Module__startupDone__S, "ti_sysbios_knl_Queue_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_knl_Queue_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Object__create__S, "ti_sysbios_knl_Queue_Object__create__S")
__extern xdc_Ptr ti_sysbios_knl_Queue_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_knl_Queue_create, "ti_sysbios_knl_Queue_create")
__extern ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Queue_create( const ti_sysbios_knl_Queue_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_knl_Queue_construct, "ti_sysbios_knl_Queue_construct")
__extern void ti_sysbios_knl_Queue_construct( ti_sysbios_knl_Queue_Struct *__obj, const ti_sysbios_knl_Queue_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Object__delete__S, "ti_sysbios_knl_Queue_Object__delete__S")
__extern xdc_Void ti_sysbios_knl_Queue_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_knl_Queue_delete, "ti_sysbios_knl_Queue_delete")
__extern void ti_sysbios_knl_Queue_delete(ti_sysbios_knl_Queue_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Object__destruct__S, "ti_sysbios_knl_Queue_Object__destruct__S")
__extern xdc_Void ti_sysbios_knl_Queue_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_knl_Queue_destruct, "ti_sysbios_knl_Queue_destruct")
__extern void ti_sysbios_knl_Queue_destruct(ti_sysbios_knl_Queue_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Object__get__S, "ti_sysbios_knl_Queue_Object__get__S")
__extern xdc_Ptr ti_sysbios_knl_Queue_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Object__first__S, "ti_sysbios_knl_Queue_Object__first__S")
__extern xdc_Ptr ti_sysbios_knl_Queue_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Object__next__S, "ti_sysbios_knl_Queue_Object__next__S")
__extern xdc_Ptr ti_sysbios_knl_Queue_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_knl_Queue_Params__init__S, "ti_sysbios_knl_Queue_Params__init__S")
__extern xdc_Void ti_sysbios_knl_Queue_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* elemClear__E */
#define ti_sysbios_knl_Queue_elemClear ti_sysbios_knl_Queue_elemClear__E
xdc__CODESECT(ti_sysbios_knl_Queue_elemClear__E, "ti_sysbios_knl_Queue_elemClear")
__extern xdc_Void ti_sysbios_knl_Queue_elemClear__E( ti_sysbios_knl_Queue_Elem *qelem );

/* insert__E */
#define ti_sysbios_knl_Queue_insert ti_sysbios_knl_Queue_insert__E
xdc__CODESECT(ti_sysbios_knl_Queue_insert__E, "ti_sysbios_knl_Queue_insert")
__extern xdc_Void ti_sysbios_knl_Queue_insert__E( ti_sysbios_knl_Queue_Elem *qelem, ti_sysbios_knl_Queue_Elem *elem );

/* next__E */
#define ti_sysbios_knl_Queue_next ti_sysbios_knl_Queue_next__E
xdc__CODESECT(ti_sysbios_knl_Queue_next__E, "ti_sysbios_knl_Queue_next")
__extern xdc_Ptr ti_sysbios_knl_Queue_next__E( ti_sysbios_knl_Queue_Elem *qelem );

/* prev__E */
#define ti_sysbios_knl_Queue_prev ti_sysbios_knl_Queue_prev__E
xdc__CODESECT(ti_sysbios_knl_Queue_prev__E, "ti_sysbios_knl_Queue_prev")
__extern xdc_Ptr ti_sysbios_knl_Queue_prev__E( ti_sysbios_knl_Queue_Elem *qelem );

/* remove__E */
#define ti_sysbios_knl_Queue_remove ti_sysbios_knl_Queue_remove__E
xdc__CODESECT(ti_sysbios_knl_Queue_remove__E, "ti_sysbios_knl_Queue_remove")
__extern xdc_Void ti_sysbios_knl_Queue_remove__E( ti_sysbios_knl_Queue_Elem *qelem );

/* isQueued__E */
#define ti_sysbios_knl_Queue_isQueued ti_sysbios_knl_Queue_isQueued__E
xdc__CODESECT(ti_sysbios_knl_Queue_isQueued__E, "ti_sysbios_knl_Queue_isQueued")
__extern xdc_Bool ti_sysbios_knl_Queue_isQueued__E( ti_sysbios_knl_Queue_Elem *qelem );

/* dequeue__E */
#define ti_sysbios_knl_Queue_dequeue ti_sysbios_knl_Queue_dequeue__E
xdc__CODESECT(ti_sysbios_knl_Queue_dequeue__E, "ti_sysbios_knl_Queue_dequeue")
__extern xdc_Ptr ti_sysbios_knl_Queue_dequeue__E( ti_sysbios_knl_Queue_Handle __inst );

/* empty__E */
#define ti_sysbios_knl_Queue_empty ti_sysbios_knl_Queue_empty__E
xdc__CODESECT(ti_sysbios_knl_Queue_empty__E, "ti_sysbios_knl_Queue_empty")
__extern xdc_Bool ti_sysbios_knl_Queue_empty__E( ti_sysbios_knl_Queue_Handle __inst );

/* enqueue__E */
#define ti_sysbios_knl_Queue_enqueue ti_sysbios_knl_Queue_enqueue__E
xdc__CODESECT(ti_sysbios_knl_Queue_enqueue__E, "ti_sysbios_knl_Queue_enqueue")
__extern xdc_Void ti_sysbios_knl_Queue_enqueue__E( ti_sysbios_knl_Queue_Handle __inst, ti_sysbios_knl_Queue_Elem *elem );

/* get__E */
#define ti_sysbios_knl_Queue_get ti_sysbios_knl_Queue_get__E
xdc__CODESECT(ti_sysbios_knl_Queue_get__E, "ti_sysbios_knl_Queue_get")
__extern xdc_Ptr ti_sysbios_knl_Queue_get__E( ti_sysbios_knl_Queue_Handle __inst );

/* head__E */
#define ti_sysbios_knl_Queue_head ti_sysbios_knl_Queue_head__E
xdc__CODESECT(ti_sysbios_knl_Queue_head__E, "ti_sysbios_knl_Queue_head")
__extern xdc_Ptr ti_sysbios_knl_Queue_head__E( ti_sysbios_knl_Queue_Handle __inst );

/* put__E */
#define ti_sysbios_knl_Queue_put ti_sysbios_knl_Queue_put__E
xdc__CODESECT(ti_sysbios_knl_Queue_put__E, "ti_sysbios_knl_Queue_put")
__extern xdc_Void ti_sysbios_knl_Queue_put__E( ti_sysbios_knl_Queue_Handle __inst, ti_sysbios_knl_Queue_Elem *elem );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_knl_Queue_Module_startupDone() ti_sysbios_knl_Queue_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_knl_Queue_Object_heap() ti_sysbios_knl_Queue_Object__heap__C

/* Module_heap */
#define ti_sysbios_knl_Queue_Module_heap() ti_sysbios_knl_Queue_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_knl_Queue_Module__id ti_sysbios_knl_Queue_Module_id( void ) 
{
    return ti_sysbios_knl_Queue_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_knl_Queue_Module_hasMask( void ) 
{
    return ti_sysbios_knl_Queue_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_knl_Queue_Module_getMask( void ) 
{
    return ti_sysbios_knl_Queue_Module__diagsMask__C != NULL ? *ti_sysbios_knl_Queue_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_knl_Queue_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_knl_Queue_Module__diagsMask__C != NULL) *ti_sysbios_knl_Queue_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_knl_Queue_Params_init( ti_sysbios_knl_Queue_Params *prms ) 
{
    if (prms) {
        ti_sysbios_knl_Queue_Params__init__S(prms, 0, sizeof(ti_sysbios_knl_Queue_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_knl_Queue_Params_copy(ti_sysbios_knl_Queue_Params *dst, const ti_sysbios_knl_Queue_Params *src) 
{
    if (dst) {
        ti_sysbios_knl_Queue_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_knl_Queue_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_knl_Queue_Object_count() ti_sysbios_knl_Queue_Object__count__C

/* Object_sizeof */
#define ti_sysbios_knl_Queue_Object_sizeof() ti_sysbios_knl_Queue_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Queue_Object_get(ti_sysbios_knl_Queue_Instance_State *oarr, int i) 
{
    return (ti_sysbios_knl_Queue_Handle)ti_sysbios_knl_Queue_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Queue_Object_first( void )
{
    return (ti_sysbios_knl_Queue_Handle)ti_sysbios_knl_Queue_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Queue_Object_next( ti_sysbios_knl_Queue_Object *obj )
{
    return (ti_sysbios_knl_Queue_Handle)ti_sysbios_knl_Queue_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_knl_Queue_Handle_label( ti_sysbios_knl_Queue_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_knl_Queue_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_knl_Queue_Handle_name( ti_sysbios_knl_Queue_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_knl_Queue_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_knl_Queue_Handle ti_sysbios_knl_Queue_handle( ti_sysbios_knl_Queue_Struct *str )
{
    return (ti_sysbios_knl_Queue_Handle)str;
}

/* struct */
static inline ti_sysbios_knl_Queue_Struct *ti_sysbios_knl_Queue_struct( ti_sysbios_knl_Queue_Handle inst )
{
    return (ti_sysbios_knl_Queue_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_knl_Queue__top__
#undef __nested__
#endif

#endif /* ti_sysbios_knl_Queue__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_knl_Queue__internalaccess))

#ifndef ti_sysbios_knl_Queue__include_state
#define ti_sysbios_knl_Queue__include_state

/* Object */
struct ti_sysbios_knl_Queue_Object {
    ti_sysbios_knl_Queue_Elem elem;
};

#endif /* ti_sysbios_knl_Queue__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_knl_Queue__nolocalnames)

#ifndef ti_sysbios_knl_Queue__localnames__done
#define ti_sysbios_knl_Queue__localnames__done

/* module prefix */
#define Queue_Instance ti_sysbios_knl_Queue_Instance
#define Queue_Handle ti_sysbios_knl_Queue_Handle
#define Queue_Module ti_sysbios_knl_Queue_Module
#define Queue_Object ti_sysbios_knl_Queue_Object
#define Queue_Struct ti_sysbios_knl_Queue_Struct
#define Queue_Elem ti_sysbios_knl_Queue_Elem
#define Queue_Instance_State ti_sysbios_knl_Queue_Instance_State
#define Queue_Params ti_sysbios_knl_Queue_Params
#define Queue_elemClear ti_sysbios_knl_Queue_elemClear
#define Queue_insert ti_sysbios_knl_Queue_insert
#define Queue_next ti_sysbios_knl_Queue_next
#define Queue_prev ti_sysbios_knl_Queue_prev
#define Queue_remove ti_sysbios_knl_Queue_remove
#define Queue_isQueued ti_sysbios_knl_Queue_isQueued
#define Queue_dequeue ti_sysbios_knl_Queue_dequeue
#define Queue_empty ti_sysbios_knl_Queue_empty
#define Queue_enqueue ti_sysbios_knl_Queue_enqueue
#define Queue_get ti_sysbios_knl_Queue_get
#define Queue_head ti_sysbios_knl_Queue_head
#define Queue_put ti_sysbios_knl_Queue_put
#define Queue_Module_name ti_sysbios_knl_Queue_Module_name
#define Queue_Module_id ti_sysbios_knl_Queue_Module_id
#define Queue_Module_startup ti_sysbios_knl_Queue_Module_startup
#define Queue_Module_startupDone ti_sysbios_knl_Queue_Module_startupDone
#define Queue_Module_hasMask ti_sysbios_knl_Queue_Module_hasMask
#define Queue_Module_getMask ti_sysbios_knl_Queue_Module_getMask
#define Queue_Module_setMask ti_sysbios_knl_Queue_Module_setMask
#define Queue_Object_heap ti_sysbios_knl_Queue_Object_heap
#define Queue_Module_heap ti_sysbios_knl_Queue_Module_heap
#define Queue_construct ti_sysbios_knl_Queue_construct
#define Queue_create ti_sysbios_knl_Queue_create
#define Queue_handle ti_sysbios_knl_Queue_handle
#define Queue_struct ti_sysbios_knl_Queue_struct
#define Queue_Handle_label ti_sysbios_knl_Queue_Handle_label
#define Queue_Handle_name ti_sysbios_knl_Queue_Handle_name
#define Queue_Instance_init ti_sysbios_knl_Queue_Instance_init
#define Queue_Object_count ti_sysbios_knl_Queue_Object_count
#define Queue_Object_get ti_sysbios_knl_Queue_Object_get
#define Queue_Object_first ti_sysbios_knl_Queue_Object_first
#define Queue_Object_next ti_sysbios_knl_Queue_Object_next
#define Queue_Object_sizeof ti_sysbios_knl_Queue_Object_sizeof
#define Queue_Params_copy ti_sysbios_knl_Queue_Params_copy
#define Queue_Params_init ti_sysbios_knl_Queue_Params_init
#define Queue_delete ti_sysbios_knl_Queue_delete
#define Queue_destruct ti_sysbios_knl_Queue_destruct

#endif /* ti_sysbios_knl_Queue__localnames__done */
#endif
