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

#ifndef ti_runtime_heaps_HeapRem__include
#define ti_runtime_heaps_HeapRem__include

#ifndef __nested__
#define __nested__
#define ti_runtime_heaps_HeapRem__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_runtime_heaps_HeapRem___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/runtime/heaps/package/package.defs.h>

#include <xdc/runtime/Error.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <xdc/runtime/IHeap.h>


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
typedef xdc_Bits32 CT__ti_runtime_heaps_HeapRem_Module__diagsEnabled;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__diagsEnabled ti_runtime_heaps_HeapRem_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_runtime_heaps_HeapRem_Module__diagsIncluded;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__diagsIncluded ti_runtime_heaps_HeapRem_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_runtime_heaps_HeapRem_Module__diagsMask;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__diagsMask ti_runtime_heaps_HeapRem_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_runtime_heaps_HeapRem_Module__gateObj;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__gateObj ti_runtime_heaps_HeapRem_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_runtime_heaps_HeapRem_Module__gatePrms;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__gatePrms ti_runtime_heaps_HeapRem_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_runtime_heaps_HeapRem_Module__id;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__id ti_runtime_heaps_HeapRem_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_runtime_heaps_HeapRem_Module__loggerDefined;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__loggerDefined ti_runtime_heaps_HeapRem_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_runtime_heaps_HeapRem_Module__loggerObj;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__loggerObj ti_runtime_heaps_HeapRem_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_runtime_heaps_HeapRem_Module__loggerFxn0;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__loggerFxn0 ti_runtime_heaps_HeapRem_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_runtime_heaps_HeapRem_Module__loggerFxn1;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__loggerFxn1 ti_runtime_heaps_HeapRem_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_runtime_heaps_HeapRem_Module__loggerFxn2;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__loggerFxn2 ti_runtime_heaps_HeapRem_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_runtime_heaps_HeapRem_Module__loggerFxn4;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__loggerFxn4 ti_runtime_heaps_HeapRem_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_runtime_heaps_HeapRem_Module__loggerFxn8;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__loggerFxn8 ti_runtime_heaps_HeapRem_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_runtime_heaps_HeapRem_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Module__startupDoneFxn ti_runtime_heaps_HeapRem_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_runtime_heaps_HeapRem_Object__count;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Object__count ti_runtime_heaps_HeapRem_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_runtime_heaps_HeapRem_Object__heap;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Object__heap ti_runtime_heaps_HeapRem_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_runtime_heaps_HeapRem_Object__sizeof;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Object__sizeof ti_runtime_heaps_HeapRem_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_runtime_heaps_HeapRem_Object__table;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_Object__table ti_runtime_heaps_HeapRem_Object__table__C;

/* start */
#define ti_runtime_heaps_HeapRem_start (ti_runtime_heaps_HeapRem_start__C)
typedef xdc_Char *CT__ti_runtime_heaps_HeapRem_start;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_start ti_runtime_heaps_HeapRem_start__C;

/* end */
#define ti_runtime_heaps_HeapRem_end (ti_runtime_heaps_HeapRem_end__C)
typedef xdc_Char *CT__ti_runtime_heaps_HeapRem_end;
__extern __FAR__ const CT__ti_runtime_heaps_HeapRem_end ti_runtime_heaps_HeapRem_end__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_runtime_heaps_HeapRem_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_runtime_heaps_HeapRem_Struct {
    const ti_runtime_heaps_HeapRem_Fxns__ *__fxns;
    xdc_Int __f0;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_runtime_heaps_HeapRem_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Ptr (*alloc)(ti_runtime_heaps_HeapRem_Handle, xdc_SizeT, xdc_SizeT, xdc_runtime_Error_Block*);
    xdc_Void (*free)(ti_runtime_heaps_HeapRem_Handle, xdc_Ptr, xdc_SizeT);
    xdc_Bool (*isBlocking)(ti_runtime_heaps_HeapRem_Handle);
    xdc_Void (*getStats)(ti_runtime_heaps_HeapRem_Handle, xdc_runtime_Memory_Stats*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_runtime_heaps_HeapRem_Fxns__ ti_runtime_heaps_HeapRem_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_runtime_heaps_HeapRem_Module_startup ti_runtime_heaps_HeapRem_Module_startup__E
xdc__CODESECT(ti_runtime_heaps_HeapRem_Module_startup__E, "ti_runtime_heaps_HeapRem_Module_startup")
__extern xdc_Int ti_runtime_heaps_HeapRem_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_runtime_heaps_HeapRem_Module_startup__F, "ti_runtime_heaps_HeapRem_Module_startup")
__extern xdc_Int ti_runtime_heaps_HeapRem_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Instance_init__E, "ti_runtime_heaps_HeapRem_Instance_init")
__extern xdc_Void ti_runtime_heaps_HeapRem_Instance_init__E(ti_runtime_heaps_HeapRem_Object *, const ti_runtime_heaps_HeapRem_Params *);

/* Handle__label__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Handle__label__S, "ti_runtime_heaps_HeapRem_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_runtime_heaps_HeapRem_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Module__startupDone__S, "ti_runtime_heaps_HeapRem_Module__startupDone__S")
__extern xdc_Bool ti_runtime_heaps_HeapRem_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Object__create__S, "ti_runtime_heaps_HeapRem_Object__create__S")
__extern xdc_Ptr ti_runtime_heaps_HeapRem_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_runtime_heaps_HeapRem_create, "ti_runtime_heaps_HeapRem_create")
__extern ti_runtime_heaps_HeapRem_Handle ti_runtime_heaps_HeapRem_create( const ti_runtime_heaps_HeapRem_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_runtime_heaps_HeapRem_construct, "ti_runtime_heaps_HeapRem_construct")
__extern void ti_runtime_heaps_HeapRem_construct( ti_runtime_heaps_HeapRem_Struct *__obj, const ti_runtime_heaps_HeapRem_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Object__delete__S, "ti_runtime_heaps_HeapRem_Object__delete__S")
__extern xdc_Void ti_runtime_heaps_HeapRem_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_runtime_heaps_HeapRem_delete, "ti_runtime_heaps_HeapRem_delete")
__extern void ti_runtime_heaps_HeapRem_delete(ti_runtime_heaps_HeapRem_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Object__destruct__S, "ti_runtime_heaps_HeapRem_Object__destruct__S")
__extern xdc_Void ti_runtime_heaps_HeapRem_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_runtime_heaps_HeapRem_destruct, "ti_runtime_heaps_HeapRem_destruct")
__extern void ti_runtime_heaps_HeapRem_destruct(ti_runtime_heaps_HeapRem_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Object__get__S, "ti_runtime_heaps_HeapRem_Object__get__S")
__extern xdc_Ptr ti_runtime_heaps_HeapRem_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Object__first__S, "ti_runtime_heaps_HeapRem_Object__first__S")
__extern xdc_Ptr ti_runtime_heaps_HeapRem_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Object__next__S, "ti_runtime_heaps_HeapRem_Object__next__S")
__extern xdc_Ptr ti_runtime_heaps_HeapRem_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_runtime_heaps_HeapRem_Params__init__S, "ti_runtime_heaps_HeapRem_Params__init__S")
__extern xdc_Void ti_runtime_heaps_HeapRem_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* alloc__E */
#define ti_runtime_heaps_HeapRem_alloc ti_runtime_heaps_HeapRem_alloc__E
xdc__CODESECT(ti_runtime_heaps_HeapRem_alloc__E, "ti_runtime_heaps_HeapRem_alloc")
__extern xdc_Ptr ti_runtime_heaps_HeapRem_alloc__E( ti_runtime_heaps_HeapRem_Handle __inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb );

/* free__E */
#define ti_runtime_heaps_HeapRem_free ti_runtime_heaps_HeapRem_free__E
xdc__CODESECT(ti_runtime_heaps_HeapRem_free__E, "ti_runtime_heaps_HeapRem_free")
__extern xdc_Void ti_runtime_heaps_HeapRem_free__E( ti_runtime_heaps_HeapRem_Handle __inst, xdc_Ptr block, xdc_SizeT size );

/* isBlocking__E */
#define ti_runtime_heaps_HeapRem_isBlocking ti_runtime_heaps_HeapRem_isBlocking__E
xdc__CODESECT(ti_runtime_heaps_HeapRem_isBlocking__E, "ti_runtime_heaps_HeapRem_isBlocking")
__extern xdc_Bool ti_runtime_heaps_HeapRem_isBlocking__E( ti_runtime_heaps_HeapRem_Handle __inst );

/* getStats__E */
#define ti_runtime_heaps_HeapRem_getStats ti_runtime_heaps_HeapRem_getStats__E
xdc__CODESECT(ti_runtime_heaps_HeapRem_getStats__E, "ti_runtime_heaps_HeapRem_getStats")
__extern xdc_Void ti_runtime_heaps_HeapRem_getStats__E( ti_runtime_heaps_HeapRem_Handle __inst, xdc_runtime_Memory_Stats *stats );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IHeap_Module ti_runtime_heaps_HeapRem_Module_upCast( void )
{
    return (xdc_runtime_IHeap_Module)&ti_runtime_heaps_HeapRem_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IHeap */
#define ti_runtime_heaps_HeapRem_Module_to_xdc_runtime_IHeap ti_runtime_heaps_HeapRem_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IHeap_Handle ti_runtime_heaps_HeapRem_Handle_upCast( ti_runtime_heaps_HeapRem_Handle i )
{
    return (xdc_runtime_IHeap_Handle)i;
}

/* Handle_to_xdc_runtime_IHeap */
#define ti_runtime_heaps_HeapRem_Handle_to_xdc_runtime_IHeap ti_runtime_heaps_HeapRem_Handle_upCast

/* Handle_downCast */
static inline ti_runtime_heaps_HeapRem_Handle ti_runtime_heaps_HeapRem_Handle_downCast( xdc_runtime_IHeap_Handle i )
{
    xdc_runtime_IHeap_Handle i2 = (xdc_runtime_IHeap_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_runtime_heaps_HeapRem_Module__FXNS__C ? (ti_runtime_heaps_HeapRem_Handle)i : 0;
}

/* Handle_from_xdc_runtime_IHeap */
#define ti_runtime_heaps_HeapRem_Handle_from_xdc_runtime_IHeap ti_runtime_heaps_HeapRem_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_runtime_heaps_HeapRem_Module_startupDone() ti_runtime_heaps_HeapRem_Module__startupDone__S()

/* Object_heap */
#define ti_runtime_heaps_HeapRem_Object_heap() ti_runtime_heaps_HeapRem_Object__heap__C

/* Module_heap */
#define ti_runtime_heaps_HeapRem_Module_heap() ti_runtime_heaps_HeapRem_Object__heap__C

/* Module_id */
static inline CT__ti_runtime_heaps_HeapRem_Module__id ti_runtime_heaps_HeapRem_Module_id( void ) 
{
    return ti_runtime_heaps_HeapRem_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_runtime_heaps_HeapRem_Module_hasMask( void ) 
{
    return ti_runtime_heaps_HeapRem_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_runtime_heaps_HeapRem_Module_getMask( void ) 
{
    return ti_runtime_heaps_HeapRem_Module__diagsMask__C != NULL ? *ti_runtime_heaps_HeapRem_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_runtime_heaps_HeapRem_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_runtime_heaps_HeapRem_Module__diagsMask__C != NULL) *ti_runtime_heaps_HeapRem_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_runtime_heaps_HeapRem_Params_init( ti_runtime_heaps_HeapRem_Params *prms ) 
{
    if (prms) {
        ti_runtime_heaps_HeapRem_Params__init__S(prms, 0, sizeof(ti_runtime_heaps_HeapRem_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_runtime_heaps_HeapRem_Params_copy(ti_runtime_heaps_HeapRem_Params *dst, const ti_runtime_heaps_HeapRem_Params *src) 
{
    if (dst) {
        ti_runtime_heaps_HeapRem_Params__init__S(dst, (const void *)src, sizeof(ti_runtime_heaps_HeapRem_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_runtime_heaps_HeapRem_Object_count() ti_runtime_heaps_HeapRem_Object__count__C

/* Object_sizeof */
#define ti_runtime_heaps_HeapRem_Object_sizeof() ti_runtime_heaps_HeapRem_Object__sizeof__C

/* Object_get */
static inline ti_runtime_heaps_HeapRem_Handle ti_runtime_heaps_HeapRem_Object_get(ti_runtime_heaps_HeapRem_Instance_State *oarr, int i) 
{
    return (ti_runtime_heaps_HeapRem_Handle)ti_runtime_heaps_HeapRem_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_runtime_heaps_HeapRem_Handle ti_runtime_heaps_HeapRem_Object_first( void )
{
    return (ti_runtime_heaps_HeapRem_Handle)ti_runtime_heaps_HeapRem_Object__first__S();
}

/* Object_next */
static inline ti_runtime_heaps_HeapRem_Handle ti_runtime_heaps_HeapRem_Object_next( ti_runtime_heaps_HeapRem_Object *obj )
{
    return (ti_runtime_heaps_HeapRem_Handle)ti_runtime_heaps_HeapRem_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_runtime_heaps_HeapRem_Handle_label( ti_runtime_heaps_HeapRem_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_runtime_heaps_HeapRem_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_runtime_heaps_HeapRem_Handle_name( ti_runtime_heaps_HeapRem_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_runtime_heaps_HeapRem_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_runtime_heaps_HeapRem_Handle ti_runtime_heaps_HeapRem_handle( ti_runtime_heaps_HeapRem_Struct *str )
{
    return (ti_runtime_heaps_HeapRem_Handle)str;
}

/* struct */
static inline ti_runtime_heaps_HeapRem_Struct *ti_runtime_heaps_HeapRem_struct( ti_runtime_heaps_HeapRem_Handle inst )
{
    return (ti_runtime_heaps_HeapRem_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_runtime_heaps_HeapRem__top__
#undef __nested__
#endif

#endif /* ti_runtime_heaps_HeapRem__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_runtime_heaps_HeapRem__internalaccess))

#ifndef ti_runtime_heaps_HeapRem__include_state
#define ti_runtime_heaps_HeapRem__include_state

/* Module_State */
struct ti_runtime_heaps_HeapRem_Module_State {
    ti_sysbios_heaps_HeapMem_Handle heap;
};

/* Module__state__V */
extern struct ti_runtime_heaps_HeapRem_Module_State__ ti_runtime_heaps_HeapRem_Module__state__V;

/* Object */
struct ti_runtime_heaps_HeapRem_Object {
    const ti_runtime_heaps_HeapRem_Fxns__ *__fxns;
    xdc_Int count;
};

#endif /* ti_runtime_heaps_HeapRem__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_runtime_heaps_HeapRem__nolocalnames)

#ifndef ti_runtime_heaps_HeapRem__localnames__done
#define ti_runtime_heaps_HeapRem__localnames__done

/* module prefix */
#define HeapRem_Instance ti_runtime_heaps_HeapRem_Instance
#define HeapRem_Handle ti_runtime_heaps_HeapRem_Handle
#define HeapRem_Module ti_runtime_heaps_HeapRem_Module
#define HeapRem_Object ti_runtime_heaps_HeapRem_Object
#define HeapRem_Struct ti_runtime_heaps_HeapRem_Struct
#define HeapRem_Module_State ti_runtime_heaps_HeapRem_Module_State
#define HeapRem_Instance_State ti_runtime_heaps_HeapRem_Instance_State
#define HeapRem_start ti_runtime_heaps_HeapRem_start
#define HeapRem_end ti_runtime_heaps_HeapRem_end
#define HeapRem_Params ti_runtime_heaps_HeapRem_Params
#define HeapRem_alloc ti_runtime_heaps_HeapRem_alloc
#define HeapRem_free ti_runtime_heaps_HeapRem_free
#define HeapRem_isBlocking ti_runtime_heaps_HeapRem_isBlocking
#define HeapRem_getStats ti_runtime_heaps_HeapRem_getStats
#define HeapRem_Module_name ti_runtime_heaps_HeapRem_Module_name
#define HeapRem_Module_id ti_runtime_heaps_HeapRem_Module_id
#define HeapRem_Module_startup ti_runtime_heaps_HeapRem_Module_startup
#define HeapRem_Module_startupDone ti_runtime_heaps_HeapRem_Module_startupDone
#define HeapRem_Module_hasMask ti_runtime_heaps_HeapRem_Module_hasMask
#define HeapRem_Module_getMask ti_runtime_heaps_HeapRem_Module_getMask
#define HeapRem_Module_setMask ti_runtime_heaps_HeapRem_Module_setMask
#define HeapRem_Object_heap ti_runtime_heaps_HeapRem_Object_heap
#define HeapRem_Module_heap ti_runtime_heaps_HeapRem_Module_heap
#define HeapRem_construct ti_runtime_heaps_HeapRem_construct
#define HeapRem_create ti_runtime_heaps_HeapRem_create
#define HeapRem_handle ti_runtime_heaps_HeapRem_handle
#define HeapRem_struct ti_runtime_heaps_HeapRem_struct
#define HeapRem_Handle_label ti_runtime_heaps_HeapRem_Handle_label
#define HeapRem_Handle_name ti_runtime_heaps_HeapRem_Handle_name
#define HeapRem_Instance_init ti_runtime_heaps_HeapRem_Instance_init
#define HeapRem_Object_count ti_runtime_heaps_HeapRem_Object_count
#define HeapRem_Object_get ti_runtime_heaps_HeapRem_Object_get
#define HeapRem_Object_first ti_runtime_heaps_HeapRem_Object_first
#define HeapRem_Object_next ti_runtime_heaps_HeapRem_Object_next
#define HeapRem_Object_sizeof ti_runtime_heaps_HeapRem_Object_sizeof
#define HeapRem_Params_copy ti_runtime_heaps_HeapRem_Params_copy
#define HeapRem_Params_init ti_runtime_heaps_HeapRem_Params_init
#define HeapRem_delete ti_runtime_heaps_HeapRem_delete
#define HeapRem_destruct ti_runtime_heaps_HeapRem_destruct
#define HeapRem_Module_upCast ti_runtime_heaps_HeapRem_Module_upCast
#define HeapRem_Module_to_xdc_runtime_IHeap ti_runtime_heaps_HeapRem_Module_to_xdc_runtime_IHeap
#define HeapRem_Handle_upCast ti_runtime_heaps_HeapRem_Handle_upCast
#define HeapRem_Handle_to_xdc_runtime_IHeap ti_runtime_heaps_HeapRem_Handle_to_xdc_runtime_IHeap
#define HeapRem_Handle_downCast ti_runtime_heaps_HeapRem_Handle_downCast
#define HeapRem_Handle_from_xdc_runtime_IHeap ti_runtime_heaps_HeapRem_Handle_from_xdc_runtime_IHeap

#endif /* ti_runtime_heaps_HeapRem__localnames__done */
#endif
