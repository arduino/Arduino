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

#ifndef ti_sysbios_heaps_HeapCallback__include
#define ti_sysbios_heaps_HeapCallback__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_heaps_HeapCallback__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_heaps_HeapCallback___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IInstance.h>
#include <ti/sysbios/heaps/package/package.defs.h>

#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* AllocInstFxn */
typedef xdc_Ptr (*ti_sysbios_heaps_HeapCallback_AllocInstFxn)(xdc_UArg, xdc_SizeT, xdc_SizeT);

/* CreateInstFxn */
typedef xdc_UArg (*ti_sysbios_heaps_HeapCallback_CreateInstFxn)(xdc_UArg);

/* DeleteInstFxn */
typedef xdc_Void (*ti_sysbios_heaps_HeapCallback_DeleteInstFxn)(xdc_UArg);

/* FreeInstFxn */
typedef xdc_Void (*ti_sysbios_heaps_HeapCallback_FreeInstFxn)(xdc_UArg, xdc_Ptr, xdc_SizeT);

/* GetStatsInstFxn */
typedef xdc_Void (*ti_sysbios_heaps_HeapCallback_GetStatsInstFxn)(xdc_UArg, xdc_runtime_Memory_Stats*);

/* InitInstFxn */
typedef xdc_UArg (*ti_sysbios_heaps_HeapCallback_InitInstFxn)(xdc_UArg);

/* IsBlockingInstFxn */
typedef xdc_Bool (*ti_sysbios_heaps_HeapCallback_IsBlockingInstFxn)(xdc_UArg);


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_heaps_HeapCallback_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__diagsEnabled ti_sysbios_heaps_HeapCallback_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_heaps_HeapCallback_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__diagsIncluded ti_sysbios_heaps_HeapCallback_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_heaps_HeapCallback_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__diagsMask ti_sysbios_heaps_HeapCallback_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapCallback_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__gateObj ti_sysbios_heaps_HeapCallback_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapCallback_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__gatePrms ti_sysbios_heaps_HeapCallback_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_heaps_HeapCallback_Module__id;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__id ti_sysbios_heaps_HeapCallback_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_heaps_HeapCallback_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__loggerDefined ti_sysbios_heaps_HeapCallback_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapCallback_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__loggerObj ti_sysbios_heaps_HeapCallback_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn0 ti_sysbios_heaps_HeapCallback_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn1 ti_sysbios_heaps_HeapCallback_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn2 ti_sysbios_heaps_HeapCallback_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn4 ti_sysbios_heaps_HeapCallback_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__loggerFxn8 ti_sysbios_heaps_HeapCallback_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_heaps_HeapCallback_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Module__startupDoneFxn ti_sysbios_heaps_HeapCallback_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_heaps_HeapCallback_Object__count;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Object__count ti_sysbios_heaps_HeapCallback_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_heaps_HeapCallback_Object__heap;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Object__heap ti_sysbios_heaps_HeapCallback_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_heaps_HeapCallback_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Object__sizeof ti_sysbios_heaps_HeapCallback_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_heaps_HeapCallback_Object__table;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_Object__table ti_sysbios_heaps_HeapCallback_Object__table__C;

/* allocInstFxn */
#define ti_sysbios_heaps_HeapCallback_allocInstFxn (ti_sysbios_heaps_HeapCallback_allocInstFxn__C)
typedef ti_sysbios_heaps_HeapCallback_AllocInstFxn CT__ti_sysbios_heaps_HeapCallback_allocInstFxn;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_allocInstFxn ti_sysbios_heaps_HeapCallback_allocInstFxn__C;

/* createInstFxn */
#define ti_sysbios_heaps_HeapCallback_createInstFxn (ti_sysbios_heaps_HeapCallback_createInstFxn__C)
typedef ti_sysbios_heaps_HeapCallback_CreateInstFxn CT__ti_sysbios_heaps_HeapCallback_createInstFxn;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_createInstFxn ti_sysbios_heaps_HeapCallback_createInstFxn__C;

/* deleteInstFxn */
#define ti_sysbios_heaps_HeapCallback_deleteInstFxn (ti_sysbios_heaps_HeapCallback_deleteInstFxn__C)
typedef ti_sysbios_heaps_HeapCallback_DeleteInstFxn CT__ti_sysbios_heaps_HeapCallback_deleteInstFxn;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_deleteInstFxn ti_sysbios_heaps_HeapCallback_deleteInstFxn__C;

/* freeInstFxn */
#define ti_sysbios_heaps_HeapCallback_freeInstFxn (ti_sysbios_heaps_HeapCallback_freeInstFxn__C)
typedef ti_sysbios_heaps_HeapCallback_FreeInstFxn CT__ti_sysbios_heaps_HeapCallback_freeInstFxn;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_freeInstFxn ti_sysbios_heaps_HeapCallback_freeInstFxn__C;

/* getStatsInstFxn */
#define ti_sysbios_heaps_HeapCallback_getStatsInstFxn (ti_sysbios_heaps_HeapCallback_getStatsInstFxn__C)
typedef ti_sysbios_heaps_HeapCallback_GetStatsInstFxn CT__ti_sysbios_heaps_HeapCallback_getStatsInstFxn;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_getStatsInstFxn ti_sysbios_heaps_HeapCallback_getStatsInstFxn__C;

/* initInstFxn */
#define ti_sysbios_heaps_HeapCallback_initInstFxn (ti_sysbios_heaps_HeapCallback_initInstFxn__C)
typedef ti_sysbios_heaps_HeapCallback_InitInstFxn CT__ti_sysbios_heaps_HeapCallback_initInstFxn;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_initInstFxn ti_sysbios_heaps_HeapCallback_initInstFxn__C;

/* isBlockingInstFxn */
#define ti_sysbios_heaps_HeapCallback_isBlockingInstFxn (ti_sysbios_heaps_HeapCallback_isBlockingInstFxn__C)
typedef ti_sysbios_heaps_HeapCallback_IsBlockingInstFxn CT__ti_sysbios_heaps_HeapCallback_isBlockingInstFxn;
__extern __FAR__ const CT__ti_sysbios_heaps_HeapCallback_isBlockingInstFxn ti_sysbios_heaps_HeapCallback_isBlockingInstFxn__C;


/*
 * ======== PER-INSTANCE TYPES ========
 */

/* Params */
struct ti_sysbios_heaps_HeapCallback_Params {
    size_t __size;
    const void *__self;
    void *__fxns;
    xdc_runtime_IInstance_Params *instance;
    xdc_UArg arg;
    xdc_runtime_IInstance_Params __iprms;
};

/* Struct */
struct ti_sysbios_heaps_HeapCallback_Struct {
    const ti_sysbios_heaps_HeapCallback_Fxns__ *__fxns;
    xdc_UArg __f0;
    xdc_UArg __f1;
    xdc_runtime_Types_CordAddr __name;
};


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_heaps_HeapCallback_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Ptr (*alloc)(ti_sysbios_heaps_HeapCallback_Handle, xdc_SizeT, xdc_SizeT, xdc_runtime_Error_Block*);
    xdc_Void (*free)(ti_sysbios_heaps_HeapCallback_Handle, xdc_Ptr, xdc_SizeT);
    xdc_Bool (*isBlocking)(ti_sysbios_heaps_HeapCallback_Handle);
    xdc_Void (*getStats)(ti_sysbios_heaps_HeapCallback_Handle, xdc_runtime_Memory_Stats*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_heaps_HeapCallback_Fxns__ ti_sysbios_heaps_HeapCallback_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_heaps_HeapCallback_Module_startup ti_sysbios_heaps_HeapCallback_Module_startup__E
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Module_startup__E, "ti_sysbios_heaps_HeapCallback_Module_startup")
__extern xdc_Int ti_sysbios_heaps_HeapCallback_Module_startup__E( xdc_Int state );
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Module_startup__F, "ti_sysbios_heaps_HeapCallback_Module_startup")
__extern xdc_Int ti_sysbios_heaps_HeapCallback_Module_startup__F( xdc_Int state );

/* Instance_init__E */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Instance_init__E, "ti_sysbios_heaps_HeapCallback_Instance_init")
__extern xdc_Void ti_sysbios_heaps_HeapCallback_Instance_init__E(ti_sysbios_heaps_HeapCallback_Object *, const ti_sysbios_heaps_HeapCallback_Params *);

/* Instance_finalize__E */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Instance_finalize__E, "ti_sysbios_heaps_HeapCallback_Instance_finalize")
__extern void ti_sysbios_heaps_HeapCallback_Instance_finalize__E( ti_sysbios_heaps_HeapCallback_Object* );

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Handle__label__S, "ti_sysbios_heaps_HeapCallback_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_heaps_HeapCallback_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Module__startupDone__S, "ti_sysbios_heaps_HeapCallback_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_heaps_HeapCallback_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Object__create__S, "ti_sysbios_heaps_HeapCallback_Object__create__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapCallback_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* create */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_create, "ti_sysbios_heaps_HeapCallback_create")
__extern ti_sysbios_heaps_HeapCallback_Handle ti_sysbios_heaps_HeapCallback_create( const ti_sysbios_heaps_HeapCallback_Params *__prms, xdc_runtime_Error_Block *__eb );

/* construct */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_construct, "ti_sysbios_heaps_HeapCallback_construct")
__extern void ti_sysbios_heaps_HeapCallback_construct( ti_sysbios_heaps_HeapCallback_Struct *__obj, const ti_sysbios_heaps_HeapCallback_Params *__prms );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Object__delete__S, "ti_sysbios_heaps_HeapCallback_Object__delete__S")
__extern xdc_Void ti_sysbios_heaps_HeapCallback_Object__delete__S( xdc_Ptr instp );

/* delete */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_delete, "ti_sysbios_heaps_HeapCallback_delete")
__extern void ti_sysbios_heaps_HeapCallback_delete(ti_sysbios_heaps_HeapCallback_Handle *instp);

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Object__destruct__S, "ti_sysbios_heaps_HeapCallback_Object__destruct__S")
__extern xdc_Void ti_sysbios_heaps_HeapCallback_Object__destruct__S( xdc_Ptr objp );

/* destruct */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_destruct, "ti_sysbios_heaps_HeapCallback_destruct")
__extern void ti_sysbios_heaps_HeapCallback_destruct(ti_sysbios_heaps_HeapCallback_Struct *obj);

/* Object__get__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Object__get__S, "ti_sysbios_heaps_HeapCallback_Object__get__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapCallback_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Object__first__S, "ti_sysbios_heaps_HeapCallback_Object__first__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapCallback_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Object__next__S, "ti_sysbios_heaps_HeapCallback_Object__next__S")
__extern xdc_Ptr ti_sysbios_heaps_HeapCallback_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_Params__init__S, "ti_sysbios_heaps_HeapCallback_Params__init__S")
__extern xdc_Void ti_sysbios_heaps_HeapCallback_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* alloc__E */
#define ti_sysbios_heaps_HeapCallback_alloc ti_sysbios_heaps_HeapCallback_alloc__E
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_alloc__E, "ti_sysbios_heaps_HeapCallback_alloc")
__extern xdc_Ptr ti_sysbios_heaps_HeapCallback_alloc__E( ti_sysbios_heaps_HeapCallback_Handle __inst, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb );

/* free__E */
#define ti_sysbios_heaps_HeapCallback_free ti_sysbios_heaps_HeapCallback_free__E
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_free__E, "ti_sysbios_heaps_HeapCallback_free")
__extern xdc_Void ti_sysbios_heaps_HeapCallback_free__E( ti_sysbios_heaps_HeapCallback_Handle __inst, xdc_Ptr block, xdc_SizeT size );

/* isBlocking__E */
#define ti_sysbios_heaps_HeapCallback_isBlocking ti_sysbios_heaps_HeapCallback_isBlocking__E
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_isBlocking__E, "ti_sysbios_heaps_HeapCallback_isBlocking")
__extern xdc_Bool ti_sysbios_heaps_HeapCallback_isBlocking__E( ti_sysbios_heaps_HeapCallback_Handle __inst );

/* getStats__E */
#define ti_sysbios_heaps_HeapCallback_getStats ti_sysbios_heaps_HeapCallback_getStats__E
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_getStats__E, "ti_sysbios_heaps_HeapCallback_getStats")
__extern xdc_Void ti_sysbios_heaps_HeapCallback_getStats__E( ti_sysbios_heaps_HeapCallback_Handle __inst, xdc_runtime_Memory_Stats *stats );

/* getContext__E */
#define ti_sysbios_heaps_HeapCallback_getContext ti_sysbios_heaps_HeapCallback_getContext__E
xdc__CODESECT(ti_sysbios_heaps_HeapCallback_getContext__E, "ti_sysbios_heaps_HeapCallback_getContext")
__extern xdc_UArg ti_sysbios_heaps_HeapCallback_getContext__E( ti_sysbios_heaps_HeapCallback_Handle __inst );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_IHeap_Module ti_sysbios_heaps_HeapCallback_Module_upCast( void )
{
    return (xdc_runtime_IHeap_Module)&ti_sysbios_heaps_HeapCallback_Module__FXNS__C;
}

/* Module_to_xdc_runtime_IHeap */
#define ti_sysbios_heaps_HeapCallback_Module_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapCallback_Module_upCast

/* Handle_upCast */
static inline xdc_runtime_IHeap_Handle ti_sysbios_heaps_HeapCallback_Handle_upCast( ti_sysbios_heaps_HeapCallback_Handle i )
{
    return (xdc_runtime_IHeap_Handle)i;
}

/* Handle_to_xdc_runtime_IHeap */
#define ti_sysbios_heaps_HeapCallback_Handle_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapCallback_Handle_upCast

/* Handle_downCast */
static inline ti_sysbios_heaps_HeapCallback_Handle ti_sysbios_heaps_HeapCallback_Handle_downCast( xdc_runtime_IHeap_Handle i )
{
    xdc_runtime_IHeap_Handle i2 = (xdc_runtime_IHeap_Handle)i;
    return (void*)i2->__fxns == (void*)&ti_sysbios_heaps_HeapCallback_Module__FXNS__C ? (ti_sysbios_heaps_HeapCallback_Handle)i : 0;
}

/* Handle_from_xdc_runtime_IHeap */
#define ti_sysbios_heaps_HeapCallback_Handle_from_xdc_runtime_IHeap ti_sysbios_heaps_HeapCallback_Handle_downCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_heaps_HeapCallback_Module_startupDone() ti_sysbios_heaps_HeapCallback_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_heaps_HeapCallback_Object_heap() ti_sysbios_heaps_HeapCallback_Object__heap__C

/* Module_heap */
#define ti_sysbios_heaps_HeapCallback_Module_heap() ti_sysbios_heaps_HeapCallback_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_heaps_HeapCallback_Module__id ti_sysbios_heaps_HeapCallback_Module_id( void ) 
{
    return ti_sysbios_heaps_HeapCallback_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool ti_sysbios_heaps_HeapCallback_Module_hasMask( void ) 
{
    return ti_sysbios_heaps_HeapCallback_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 ti_sysbios_heaps_HeapCallback_Module_getMask( void ) 
{
    return ti_sysbios_heaps_HeapCallback_Module__diagsMask__C != NULL ? *ti_sysbios_heaps_HeapCallback_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void ti_sysbios_heaps_HeapCallback_Module_setMask( xdc_Bits16 mask ) 
{
    if (ti_sysbios_heaps_HeapCallback_Module__diagsMask__C != NULL) *ti_sysbios_heaps_HeapCallback_Module__diagsMask__C = mask;
}

/* Params_init */
static inline void ti_sysbios_heaps_HeapCallback_Params_init( ti_sysbios_heaps_HeapCallback_Params *prms ) 
{
    if (prms) {
        ti_sysbios_heaps_HeapCallback_Params__init__S(prms, 0, sizeof(ti_sysbios_heaps_HeapCallback_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Params_copy */
static inline void ti_sysbios_heaps_HeapCallback_Params_copy(ti_sysbios_heaps_HeapCallback_Params *dst, const ti_sysbios_heaps_HeapCallback_Params *src) 
{
    if (dst) {
        ti_sysbios_heaps_HeapCallback_Params__init__S(dst, (const void *)src, sizeof(ti_sysbios_heaps_HeapCallback_Params), sizeof(xdc_runtime_IInstance_Params));
    }
}

/* Object_count */
#define ti_sysbios_heaps_HeapCallback_Object_count() ti_sysbios_heaps_HeapCallback_Object__count__C

/* Object_sizeof */
#define ti_sysbios_heaps_HeapCallback_Object_sizeof() ti_sysbios_heaps_HeapCallback_Object__sizeof__C

/* Object_get */
static inline ti_sysbios_heaps_HeapCallback_Handle ti_sysbios_heaps_HeapCallback_Object_get(ti_sysbios_heaps_HeapCallback_Instance_State *oarr, int i) 
{
    return (ti_sysbios_heaps_HeapCallback_Handle)ti_sysbios_heaps_HeapCallback_Object__get__S(oarr, i);
}

/* Object_first */
static inline ti_sysbios_heaps_HeapCallback_Handle ti_sysbios_heaps_HeapCallback_Object_first( void )
{
    return (ti_sysbios_heaps_HeapCallback_Handle)ti_sysbios_heaps_HeapCallback_Object__first__S();
}

/* Object_next */
static inline ti_sysbios_heaps_HeapCallback_Handle ti_sysbios_heaps_HeapCallback_Object_next( ti_sysbios_heaps_HeapCallback_Object *obj )
{
    return (ti_sysbios_heaps_HeapCallback_Handle)ti_sysbios_heaps_HeapCallback_Object__next__S(obj);
}

/* Handle_label */
static inline xdc_runtime_Types_Label *ti_sysbios_heaps_HeapCallback_Handle_label( ti_sysbios_heaps_HeapCallback_Handle inst, xdc_runtime_Types_Label *lab )
{
    return ti_sysbios_heaps_HeapCallback_Handle__label__S(inst, lab);
}

/* Handle_name */
static inline xdc_String ti_sysbios_heaps_HeapCallback_Handle_name( ti_sysbios_heaps_HeapCallback_Handle inst )
{
    xdc_runtime_Types_Label lab;
    return ti_sysbios_heaps_HeapCallback_Handle__label__S(inst, &lab)->iname;
}

/* handle */
static inline ti_sysbios_heaps_HeapCallback_Handle ti_sysbios_heaps_HeapCallback_handle( ti_sysbios_heaps_HeapCallback_Struct *str )
{
    return (ti_sysbios_heaps_HeapCallback_Handle)str;
}

/* struct */
static inline ti_sysbios_heaps_HeapCallback_Struct *ti_sysbios_heaps_HeapCallback_struct( ti_sysbios_heaps_HeapCallback_Handle inst )
{
    return (ti_sysbios_heaps_HeapCallback_Struct*)inst;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_heaps_HeapCallback__top__
#undef __nested__
#endif

#endif /* ti_sysbios_heaps_HeapCallback__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(ti_sysbios_heaps_HeapCallback__internalaccess))

#ifndef ti_sysbios_heaps_HeapCallback__include_state
#define ti_sysbios_heaps_HeapCallback__include_state

/* Object */
struct ti_sysbios_heaps_HeapCallback_Object {
    const ti_sysbios_heaps_HeapCallback_Fxns__ *__fxns;
    xdc_UArg context;
    xdc_UArg arg;
};

#endif /* ti_sysbios_heaps_HeapCallback__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_heaps_HeapCallback__nolocalnames)

#ifndef ti_sysbios_heaps_HeapCallback__localnames__done
#define ti_sysbios_heaps_HeapCallback__localnames__done

/* module prefix */
#define HeapCallback_Instance ti_sysbios_heaps_HeapCallback_Instance
#define HeapCallback_Handle ti_sysbios_heaps_HeapCallback_Handle
#define HeapCallback_Module ti_sysbios_heaps_HeapCallback_Module
#define HeapCallback_Object ti_sysbios_heaps_HeapCallback_Object
#define HeapCallback_Struct ti_sysbios_heaps_HeapCallback_Struct
#define HeapCallback_AllocInstFxn ti_sysbios_heaps_HeapCallback_AllocInstFxn
#define HeapCallback_CreateInstFxn ti_sysbios_heaps_HeapCallback_CreateInstFxn
#define HeapCallback_DeleteInstFxn ti_sysbios_heaps_HeapCallback_DeleteInstFxn
#define HeapCallback_FreeInstFxn ti_sysbios_heaps_HeapCallback_FreeInstFxn
#define HeapCallback_GetStatsInstFxn ti_sysbios_heaps_HeapCallback_GetStatsInstFxn
#define HeapCallback_InitInstFxn ti_sysbios_heaps_HeapCallback_InitInstFxn
#define HeapCallback_IsBlockingInstFxn ti_sysbios_heaps_HeapCallback_IsBlockingInstFxn
#define HeapCallback_Instance_State ti_sysbios_heaps_HeapCallback_Instance_State
#define HeapCallback_allocInstFxn ti_sysbios_heaps_HeapCallback_allocInstFxn
#define HeapCallback_createInstFxn ti_sysbios_heaps_HeapCallback_createInstFxn
#define HeapCallback_deleteInstFxn ti_sysbios_heaps_HeapCallback_deleteInstFxn
#define HeapCallback_freeInstFxn ti_sysbios_heaps_HeapCallback_freeInstFxn
#define HeapCallback_getStatsInstFxn ti_sysbios_heaps_HeapCallback_getStatsInstFxn
#define HeapCallback_initInstFxn ti_sysbios_heaps_HeapCallback_initInstFxn
#define HeapCallback_isBlockingInstFxn ti_sysbios_heaps_HeapCallback_isBlockingInstFxn
#define HeapCallback_Params ti_sysbios_heaps_HeapCallback_Params
#define HeapCallback_alloc ti_sysbios_heaps_HeapCallback_alloc
#define HeapCallback_free ti_sysbios_heaps_HeapCallback_free
#define HeapCallback_isBlocking ti_sysbios_heaps_HeapCallback_isBlocking
#define HeapCallback_getStats ti_sysbios_heaps_HeapCallback_getStats
#define HeapCallback_getContext ti_sysbios_heaps_HeapCallback_getContext
#define HeapCallback_Module_name ti_sysbios_heaps_HeapCallback_Module_name
#define HeapCallback_Module_id ti_sysbios_heaps_HeapCallback_Module_id
#define HeapCallback_Module_startup ti_sysbios_heaps_HeapCallback_Module_startup
#define HeapCallback_Module_startupDone ti_sysbios_heaps_HeapCallback_Module_startupDone
#define HeapCallback_Module_hasMask ti_sysbios_heaps_HeapCallback_Module_hasMask
#define HeapCallback_Module_getMask ti_sysbios_heaps_HeapCallback_Module_getMask
#define HeapCallback_Module_setMask ti_sysbios_heaps_HeapCallback_Module_setMask
#define HeapCallback_Object_heap ti_sysbios_heaps_HeapCallback_Object_heap
#define HeapCallback_Module_heap ti_sysbios_heaps_HeapCallback_Module_heap
#define HeapCallback_construct ti_sysbios_heaps_HeapCallback_construct
#define HeapCallback_create ti_sysbios_heaps_HeapCallback_create
#define HeapCallback_handle ti_sysbios_heaps_HeapCallback_handle
#define HeapCallback_struct ti_sysbios_heaps_HeapCallback_struct
#define HeapCallback_Handle_label ti_sysbios_heaps_HeapCallback_Handle_label
#define HeapCallback_Handle_name ti_sysbios_heaps_HeapCallback_Handle_name
#define HeapCallback_Instance_init ti_sysbios_heaps_HeapCallback_Instance_init
#define HeapCallback_Object_count ti_sysbios_heaps_HeapCallback_Object_count
#define HeapCallback_Object_get ti_sysbios_heaps_HeapCallback_Object_get
#define HeapCallback_Object_first ti_sysbios_heaps_HeapCallback_Object_first
#define HeapCallback_Object_next ti_sysbios_heaps_HeapCallback_Object_next
#define HeapCallback_Object_sizeof ti_sysbios_heaps_HeapCallback_Object_sizeof
#define HeapCallback_Params_copy ti_sysbios_heaps_HeapCallback_Params_copy
#define HeapCallback_Params_init ti_sysbios_heaps_HeapCallback_Params_init
#define HeapCallback_Instance_finalize ti_sysbios_heaps_HeapCallback_Instance_finalize
#define HeapCallback_delete ti_sysbios_heaps_HeapCallback_delete
#define HeapCallback_destruct ti_sysbios_heaps_HeapCallback_destruct
#define HeapCallback_Module_upCast ti_sysbios_heaps_HeapCallback_Module_upCast
#define HeapCallback_Module_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapCallback_Module_to_xdc_runtime_IHeap
#define HeapCallback_Handle_upCast ti_sysbios_heaps_HeapCallback_Handle_upCast
#define HeapCallback_Handle_to_xdc_runtime_IHeap ti_sysbios_heaps_HeapCallback_Handle_to_xdc_runtime_IHeap
#define HeapCallback_Handle_downCast ti_sysbios_heaps_HeapCallback_Handle_downCast
#define HeapCallback_Handle_from_xdc_runtime_IHeap ti_sysbios_heaps_HeapCallback_Handle_from_xdc_runtime_IHeap

#endif /* ti_sysbios_heaps_HeapCallback__localnames__done */
#endif
