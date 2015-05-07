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
 *     MODULE-WIDE CONFIGS
 *     PER-INSTANCE TYPES
 *     VIRTUAL FUNCTIONS
 *     FUNCTION DECLARATIONS
 *     CONVERTORS
 *     SYSTEM FUNCTIONS
 *     
 *     EPILOGUE
 *     PREFIX ALIASES
 */


/*
 * ======== PROLOGUE ========
 */

#ifndef xdc_runtime_Memory_HeapProxy__include
#define xdc_runtime_Memory_HeapProxy__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_Memory_HeapProxy__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_Memory_HeapProxy___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IHeap.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_Memory_HeapProxy_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__diagsEnabled xdc_runtime_Memory_HeapProxy_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_Memory_HeapProxy_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__diagsIncluded xdc_runtime_Memory_HeapProxy_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_Memory_HeapProxy_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__diagsMask xdc_runtime_Memory_HeapProxy_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_Memory_HeapProxy_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__gateObj xdc_runtime_Memory_HeapProxy_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_Memory_HeapProxy_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__gatePrms xdc_runtime_Memory_HeapProxy_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_Memory_HeapProxy_Module__id;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__id xdc_runtime_Memory_HeapProxy_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_Memory_HeapProxy_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__loggerDefined xdc_runtime_Memory_HeapProxy_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_Memory_HeapProxy_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__loggerObj xdc_runtime_Memory_HeapProxy_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn0 xdc_runtime_Memory_HeapProxy_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn1 xdc_runtime_Memory_HeapProxy_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn2 xdc_runtime_Memory_HeapProxy_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn4 xdc_runtime_Memory_HeapProxy_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__loggerFxn8 xdc_runtime_Memory_HeapProxy_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_Memory_HeapProxy_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Module__startupDoneFxn xdc_runtime_Memory_HeapProxy_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_Memory_HeapProxy_Object__count;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Object__count xdc_runtime_Memory_HeapProxy_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_Memory_HeapProxy_Object__heap;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Object__heap xdc_runtime_Memory_HeapProxy_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_Memory_HeapProxy_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Object__sizeof xdc_runtime_Memory_HeapProxy_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_Memory_HeapProxy_Object__table;
__extern __FAR__ const CT__xdc_runtime_Memory_HeapProxy_Object__table xdc_runtime_Memory_HeapProxy_Object__table__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct xdc_runtime_Memory_HeapProxy_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct xdc_runtime_Memory_HeapProxy_Struct {
    const xdc_runtime_Memory_HeapProxy_Fxns__ *__fxns;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_Memory_HeapProxy_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Ptr (*alloc)(xdc_runtime_Memory_HeapProxy_Handle, xdc_SizeT, xdc_SizeT, xdc_runtime_Error_Block*);
    xdc_Void (*free)(xdc_runtime_Memory_HeapProxy_Handle, xdc_Ptr, xdc_SizeT);
    xdc_Bool (*isBlocking)(xdc_runtime_Memory_HeapProxy_Handle);
    xdc_Void (*getStats)(xdc_runtime_Memory_HeapProxy_Handle, xdc_runtime_Memory_Stats*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const xdc_runtime_Memory_HeapProxy_Fxns__ xdc_runtime_Memory_HeapProxy_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_Memory_HeapProxy_Module_startup( state ) (-1)

/* Handle__label__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Handle__label__S, "xdc_runtime_Memory_HeapProxy_Handle__label__S")
__extern xdc_runtime_Types_Label *xdc_runtime_Memory_HeapProxy_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Module__startupDone__S, "xdc_runtime_Memory_HeapProxy_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_Memory_HeapProxy_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Object__create__S, "xdc_runtime_Memory_HeapProxy_Object__create__S")
__extern xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_create, "xdc_runtime_Memory_HeapProxy_create")
__extern xdc_runtime_Memory_HeapProxy_Handle xdc_runtime_Memory_HeapProxy_create( const xdc_runtime_Memory_HeapProxy_Params *__prms, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Object__delete__S, "xdc_runtime_Memory_HeapProxy_Object__delete__S")
__extern xdc_Void xdc_runtime_Memory_HeapProxy_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_delete, "xdc_runtime_Memory_HeapProxy_delete")
__extern void xdc_runtime_Memory_HeapProxy_delete(xdc_runtime_Memory_HeapProxy_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Object__destruct__S, "xdc_runtime_Memory_HeapProxy_Object__destruct__S")
__extern xdc_Void xdc_runtime_Memory_HeapProxy_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Object__get__S, "xdc_runtime_Memory_HeapProxy_Object__get__S")
__extern xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Object__first__S, "xdc_runtime_Memory_HeapProxy_Object__first__S")
__extern xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Object__next__S, "xdc_runtime_Memory_HeapProxy_Object__next__S")
__extern xdc_Ptr xdc_runtime_Memory_HeapProxy_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Params__init__S, "xdc_runtime_Memory_HeapProxy_Params__init__S")
__extern xdc_Void xdc_runtime_Memory_HeapProxy_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* Proxy__abstract__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Proxy__abstract__S, "xdc_runtime_Memory_HeapProxy_Proxy__abstract__S")
__extern xdc_Bool xdc_runtime_Memory_HeapProxy_Proxy__abstract__S( void );

/* Proxy__delegate__S */
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_Proxy__delegate__S, "xdc_runtime_Memory_HeapProxy_Proxy__delegate__S")
__extern xdc_Ptr xdc_runtime_Memory_HeapProxy_Proxy__delegate__S( void );

/* alloc__E */
#define xdc_runtime_Memory_HeapProxy_alloc xdc_runtime_Memory_HeapProxy_alloc__E
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_alloc__E, "xdc_runtime_Memory_HeapProxy_alloc")
__extern xdc_Ptr xdc_runtime_Memory_HeapProxy_alloc__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb );

/* free__E */
#define xdc_runtime_Memory_HeapProxy_free xdc_runtime_Memory_HeapProxy_free__E
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_free__E, "xdc_runtime_Memory_HeapProxy_free")
__extern xdc_Void xdc_runtime_Memory_HeapProxy_free__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_Ptr block, xdc_SizeT size );

/* isBlocking__E */
#define xdc_runtime_Memory_HeapProxy_isBlocking xdc_runtime_Memory_HeapProxy_isBlocking__E
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_isBlocking__E, "xdc_runtime_Memory_HeapProxy_isBlocking")
__extern xdc_Bool xdc_runtime_Memory_HeapProxy_isBlocking__E( xdc_runtime_Memory_HeapProxy_Handle __inst );

/* getStats__E */
#define xdc_runtime_Memory_HeapProxy_getStats xdc_runtime_Memory_HeapProxy_getStats__E
xdc__CODESECT(xdc_runtime_Memory_HeapProxy_getStats__E, "xdc_runtime_Memory_HeapProxy_getStats")
__extern xdc_Void xdc_runtime_Memory_HeapProxy_getStats__E( xdc_runtime_Memory_HeapProxy_Handle __inst, xdc_runtime_Memory_Stats *stats );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IHeap_Module xdc_runtime_Memory_HeapProxy_Module_upCast( void )
{
    return (xdc_runtime_IHeap_Module)xdc_runtime_Memory_HeapProxy_Proxy__delegate__S();
}

/* Module_to_xdc_runtime_IHeap */
#define xdc_runtime_Memory_HeapProxy_Module_to_xdc_runtime_IHeap xdc_runtime_Memory_HeapProxy_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IHeap_Handle xdc_runtime_Memory_HeapProxy_Handle_upCast( xdc_runtime_Memory_HeapProxy_Handle i )
{
    return (xdc_runtime_IHeap_Handle)i;
}

/* Handle_to_xdc_runtime_IHeap */
#define xdc_runtime_Memory_HeapProxy_Handle_to_xdc_runtime_IHeap xdc_runtime_Memory_HeapProxy_Handle_upCast

/* Handle_downCast */
static inline xdc_runtime_Memory_HeapProxy_Handle xdc_runtime_Memory_HeapProxy_Handle_downCast( xdc_runtime_IHeap_Handle i )
{
    xdc_runtime_IHeap_Handle i2 = (xdc_runtime_IHeap_Handle)i;
if (xdc_runtime_Memory_HeapProxy_Proxy__abstract__S()) return (xdc_runtime_Memory_HeapProxy_Handle)i;
    return (void*)i2->__fxns == (void*)xdc_runtime_Memory_HeapProxy_Proxy__delegate__S() ? (xdc_runtime_Memory_HeapProxy_Handle)i : 0;
}

/* Handle_from_xdc_runtime_IHeap */
#define xdc_runtime_Memory_HeapProxy_Handle_from_xdc_runtime_IHeap xdc_runtime_Memory_HeapProxy_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_Memory_HeapProxy_Module_startupDone() xdc_runtime_Memory_HeapProxy_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_Memory_HeapProxy_Object_heap() xdc_runtime_Memory_HeapProxy_Object__heap__C

/* Module_heap */
#define xdc_runtime_Memory_HeapProxy_Module_heap() xdc_runtime_Memory_HeapProxy_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_Memory_HeapProxy_Module__id xdc_runtime_Memory_HeapProxy_Module_id( void ) 
{
    return xdc_runtime_Memory_HeapProxy_Module__id__C;
}

/* Proxy_abstract */
#define xdc_runtime_Memory_HeapProxy_Proxy_abstract() xdc_runtime_Memory_HeapProxy_Proxy__abstract__S()

/* Proxy_delegate */
#define xdc_runtime_Memory_HeapProxy_Proxy_delegate() ((xdc_runtime_IHeap_Module)xdc_runtime_Memory_HeapProxy_Proxy__delegate__S())

/* Params_init */
static inline void xdc_runtime_Memory_HeapProxy_Params_init( xdc_runtime_Memory_HeapProxy_Params *prms ) 
{
    if (prms) {
        xdc_runtime_Memory_HeapProxy_Params__init__S(prms, 0, sizeof(xdc_runtime_Memory_HeapProxy_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void xdc_runtime_Memory_HeapProxy_Params_copy(xdc_runtime_Memory_HeapProxy_Params *dst, const xdc_runtime_Memory_HeapProxy_Params *src) 
{
    if (dst) {
        xdc_runtime_Memory_HeapProxy_Params__init__S(dst, (const void *)src, sizeof(xdc_runtime_Memory_HeapProxy_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_Memory_HeapProxy__top__
#undef __nested__
#endif

#endif /* xdc_runtime_Memory_HeapProxy__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_Memory_HeapProxy__nolocalnames)

#ifndef xdc_runtime_Memory_HeapProxy__localnames__done
#define xdc_runtime_Memory_HeapProxy__localnames__done

/* module prefix */
#define Memory_HeapProxy_Instance xdc_runtime_Memory_HeapProxy_Instance
#define Memory_HeapProxy_Handle xdc_runtime_Memory_HeapProxy_Handle
#define Memory_HeapProxy_Module xdc_runtime_Memory_HeapProxy_Module
#define Memory_HeapProxy_Object xdc_runtime_Memory_HeapProxy_Object
#define Memory_HeapProxy_Struct xdc_runtime_Memory_HeapProxy_Struct
#define Memory_HeapProxy_Params xdc_runtime_Memory_HeapProxy_Params
#define Memory_HeapProxy_alloc xdc_runtime_Memory_HeapProxy_alloc
#define Memory_HeapProxy_free xdc_runtime_Memory_HeapProxy_free
#define Memory_HeapProxy_isBlocking xdc_runtime_Memory_HeapProxy_isBlocking
#define Memory_HeapProxy_getStats xdc_runtime_Memory_HeapProxy_getStats
#define Memory_HeapProxy_Module_name xdc_runtime_Memory_HeapProxy_Module_name
#define Memory_HeapProxy_Module_id xdc_runtime_Memory_HeapProxy_Module_id
#define Memory_HeapProxy_Module_startup xdc_runtime_Memory_HeapProxy_Module_startup
#define Memory_HeapProxy_Module_startupDone xdc_runtime_Memory_HeapProxy_Module_startupDone
#define Memory_HeapProxy_Module_hasMask xdc_runtime_Memory_HeapProxy_Module_hasMask
#define Memory_HeapProxy_Module_getMask xdc_runtime_Memory_HeapProxy_Module_getMask
#define Memory_HeapProxy_Module_setMask xdc_runtime_Memory_HeapProxy_Module_setMask
#define Memory_HeapProxy_Object_heap xdc_runtime_Memory_HeapProxy_Object_heap
#define Memory_HeapProxy_Module_heap xdc_runtime_Memory_HeapProxy_Module_heap
#define Memory_HeapProxy_construct xdc_runtime_Memory_HeapProxy_construct
#define Memory_HeapProxy_create xdc_runtime_Memory_HeapProxy_create
#define Memory_HeapProxy_handle xdc_runtime_Memory_HeapProxy_handle
#define Memory_HeapProxy_struct xdc_runtime_Memory_HeapProxy_struct
#define Memory_HeapProxy_Handle_label xdc_runtime_Memory_HeapProxy_Handle_label
#define Memory_HeapProxy_Handle_name xdc_runtime_Memory_HeapProxy_Handle_name
#define Memory_HeapProxy_Instance_init xdc_runtime_Memory_HeapProxy_Instance_init
#define Memory_HeapProxy_Object_count xdc_runtime_Memory_HeapProxy_Object_count
#define Memory_HeapProxy_Object_get xdc_runtime_Memory_HeapProxy_Object_get
#define Memory_HeapProxy_Object_first xdc_runtime_Memory_HeapProxy_Object_first
#define Memory_HeapProxy_Object_next xdc_runtime_Memory_HeapProxy_Object_next
#define Memory_HeapProxy_Object_sizeof xdc_runtime_Memory_HeapProxy_Object_sizeof
#define Memory_HeapProxy_Params_copy xdc_runtime_Memory_HeapProxy_Params_copy
#define Memory_HeapProxy_Params_init xdc_runtime_Memory_HeapProxy_Params_init
#define Memory_HeapProxy_Instance_State xdc_runtime_Memory_HeapProxy_Instance_State
#define Memory_HeapProxy_Proxy_abstract xdc_runtime_Memory_HeapProxy_Proxy_abstract
#define Memory_HeapProxy_Proxy_delegate xdc_runtime_Memory_HeapProxy_Proxy_delegate
#define Memory_HeapProxy_delete xdc_runtime_Memory_HeapProxy_delete
#define Memory_HeapProxy_destruct xdc_runtime_Memory_HeapProxy_destruct
#define Memory_HeapProxy_Module_upCast xdc_runtime_Memory_HeapProxy_Module_upCast
#define Memory_HeapProxy_Module_to_xdc_runtime_IHeap xdc_runtime_Memory_HeapProxy_Module_to_xdc_runtime_IHeap
#define Memory_HeapProxy_Handle_upCast xdc_runtime_Memory_HeapProxy_Handle_upCast
#define Memory_HeapProxy_Handle_to_xdc_runtime_IHeap xdc_runtime_Memory_HeapProxy_Handle_to_xdc_runtime_IHeap
#define Memory_HeapProxy_Handle_downCast xdc_runtime_Memory_HeapProxy_Handle_downCast
#define Memory_HeapProxy_Handle_from_xdc_runtime_IHeap xdc_runtime_Memory_HeapProxy_Handle_from_xdc_runtime_IHeap

#endif /* xdc_runtime_Memory_HeapProxy__localnames__done */
#endif
