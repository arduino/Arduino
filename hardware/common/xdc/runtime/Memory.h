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

#ifndef xdc_runtime_Memory__include
#define xdc_runtime_Memory__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_Memory__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_Memory___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/package/Memory_HeapProxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Q_BLOCKING */
#define xdc_runtime_Memory_Q_BLOCKING (1)

/* Size */
typedef xdc_UArg xdc_runtime_Memory_Size;

/* Stats */
struct xdc_runtime_Memory_Stats {
    xdc_runtime_Memory_Size totalSize;
    xdc_runtime_Memory_Size totalFreeSize;
    xdc_runtime_Memory_Size largestFreeSize;
};


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_Memory_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__diagsEnabled xdc_runtime_Memory_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_Memory_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__diagsIncluded xdc_runtime_Memory_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_Memory_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__diagsMask xdc_runtime_Memory_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_Memory_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__gateObj xdc_runtime_Memory_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_Memory_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__gatePrms xdc_runtime_Memory_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_Memory_Module__id;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__id xdc_runtime_Memory_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_Memory_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__loggerDefined xdc_runtime_Memory_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_Memory_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__loggerObj xdc_runtime_Memory_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_Memory_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn0 xdc_runtime_Memory_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_Memory_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn1 xdc_runtime_Memory_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_Memory_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn2 xdc_runtime_Memory_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_Memory_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn4 xdc_runtime_Memory_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_Memory_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_Memory_Module__loggerFxn8 xdc_runtime_Memory_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_Memory_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_Memory_Module__startupDoneFxn xdc_runtime_Memory_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_Memory_Object__count;
__extern __FAR__ const CT__xdc_runtime_Memory_Object__count xdc_runtime_Memory_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_Memory_Object__heap;
__extern __FAR__ const CT__xdc_runtime_Memory_Object__heap xdc_runtime_Memory_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_Memory_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_Memory_Object__sizeof xdc_runtime_Memory_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_Memory_Object__table;
__extern __FAR__ const CT__xdc_runtime_Memory_Object__table xdc_runtime_Memory_Object__table__C;

/* defaultHeapInstance */
#define xdc_runtime_Memory_defaultHeapInstance (xdc_runtime_Memory_defaultHeapInstance__C)
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_Memory_defaultHeapInstance;
__extern __FAR__ const CT__xdc_runtime_Memory_defaultHeapInstance xdc_runtime_Memory_defaultHeapInstance__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_Memory_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_Memory_Module__startupDone__S, "xdc_runtime_Memory_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_Memory_Module__startupDone__S( void );

/* alloc__E */
#define xdc_runtime_Memory_alloc xdc_runtime_Memory_alloc__E
xdc__CODESECT(xdc_runtime_Memory_alloc__E, "xdc_runtime_Memory_alloc")
__extern xdc_Ptr xdc_runtime_Memory_alloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb );

/* calloc__E */
#define xdc_runtime_Memory_calloc xdc_runtime_Memory_calloc__E
xdc__CODESECT(xdc_runtime_Memory_calloc__E, "xdc_runtime_Memory_calloc")
__extern xdc_Ptr xdc_runtime_Memory_calloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_runtime_Error_Block *eb );

/* free__E */
#define xdc_runtime_Memory_free xdc_runtime_Memory_free__E
xdc__CODESECT(xdc_runtime_Memory_free__E, "xdc_runtime_Memory_free")
__extern xdc_Void xdc_runtime_Memory_free__E( xdc_runtime_IHeap_Handle heap, xdc_Ptr block, xdc_SizeT size );

/* getStats__E */
#define xdc_runtime_Memory_getStats xdc_runtime_Memory_getStats__E
xdc__CODESECT(xdc_runtime_Memory_getStats__E, "xdc_runtime_Memory_getStats")
__extern xdc_Void xdc_runtime_Memory_getStats__E( xdc_runtime_IHeap_Handle heap, xdc_runtime_Memory_Stats *stats );

/* query__E */
#define xdc_runtime_Memory_query xdc_runtime_Memory_query__E
xdc__CODESECT(xdc_runtime_Memory_query__E, "xdc_runtime_Memory_query")
__extern xdc_Bool xdc_runtime_Memory_query__E( xdc_runtime_IHeap_Handle heap, xdc_Int qual );

/* getMaxDefaultTypeAlign__E */
#define xdc_runtime_Memory_getMaxDefaultTypeAlign xdc_runtime_Memory_getMaxDefaultTypeAlign__E
xdc__CODESECT(xdc_runtime_Memory_getMaxDefaultTypeAlign__E, "xdc_runtime_Memory_getMaxDefaultTypeAlign")
__extern xdc_SizeT xdc_runtime_Memory_getMaxDefaultTypeAlign__E( void );

/* valloc__E */
#define xdc_runtime_Memory_valloc xdc_runtime_Memory_valloc__E
xdc__CODESECT(xdc_runtime_Memory_valloc__E, "xdc_runtime_Memory_valloc")
__extern xdc_Ptr xdc_runtime_Memory_valloc__E( xdc_runtime_IHeap_Handle heap, xdc_SizeT size, xdc_SizeT align, xdc_Char value, xdc_runtime_Error_Block *eb );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_Memory_Module_startupDone() xdc_runtime_Memory_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_Memory_Object_heap() xdc_runtime_Memory_Object__heap__C

/* Module_heap */
#define xdc_runtime_Memory_Module_heap() xdc_runtime_Memory_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_Memory_Module__id xdc_runtime_Memory_Module_id( void ) 
{
    return xdc_runtime_Memory_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_Memory_Module_hasMask( void ) 
{
    return xdc_runtime_Memory_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_Memory_Module_getMask( void ) 
{
    return xdc_runtime_Memory_Module__diagsMask__C != NULL ? *xdc_runtime_Memory_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_Memory_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_Memory_Module__diagsMask__C != NULL) *xdc_runtime_Memory_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_Memory__top__
#undef __nested__
#endif

#endif /* xdc_runtime_Memory__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_Memory__internalaccess))

#ifndef xdc_runtime_Memory__include_state
#define xdc_runtime_Memory__include_state

/* Module_State */
struct xdc_runtime_Memory_Module_State {
    xdc_SizeT maxDefaultTypeAlign;
};

/* Module__state__V */
extern struct xdc_runtime_Memory_Module_State__ xdc_runtime_Memory_Module__state__V;

#endif /* xdc_runtime_Memory__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_Memory__nolocalnames)

#ifndef xdc_runtime_Memory__localnames__done
#define xdc_runtime_Memory__localnames__done

/* module prefix */
#define Memory_Q_BLOCKING xdc_runtime_Memory_Q_BLOCKING
#define Memory_Size xdc_runtime_Memory_Size
#define Memory_Stats xdc_runtime_Memory_Stats
#define Memory_Module_State xdc_runtime_Memory_Module_State
#define Memory_defaultHeapInstance xdc_runtime_Memory_defaultHeapInstance
#define Memory_alloc xdc_runtime_Memory_alloc
#define Memory_calloc xdc_runtime_Memory_calloc
#define Memory_free xdc_runtime_Memory_free
#define Memory_getStats xdc_runtime_Memory_getStats
#define Memory_query xdc_runtime_Memory_query
#define Memory_getMaxDefaultTypeAlign xdc_runtime_Memory_getMaxDefaultTypeAlign
#define Memory_valloc xdc_runtime_Memory_valloc
#define Memory_Module_name xdc_runtime_Memory_Module_name
#define Memory_Module_id xdc_runtime_Memory_Module_id
#define Memory_Module_startup xdc_runtime_Memory_Module_startup
#define Memory_Module_startupDone xdc_runtime_Memory_Module_startupDone
#define Memory_Module_hasMask xdc_runtime_Memory_Module_hasMask
#define Memory_Module_getMask xdc_runtime_Memory_Module_getMask
#define Memory_Module_setMask xdc_runtime_Memory_Module_setMask
#define Memory_Object_heap xdc_runtime_Memory_Object_heap
#define Memory_Module_heap xdc_runtime_Memory_Module_heap

/* proxies */
#include <xdc/runtime/package/Memory_HeapProxy.h>

#endif /* xdc_runtime_Memory__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:13; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

