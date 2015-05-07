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

#ifndef xdc_runtime_Timestamp_SupportProxy__include
#define xdc_runtime_Timestamp_SupportProxy__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_Timestamp_SupportProxy__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_Timestamp_SupportProxy___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/ITimestampProvider.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsEnabled xdc_runtime_Timestamp_SupportProxy_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsIncluded xdc_runtime_Timestamp_SupportProxy_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__diagsMask xdc_runtime_Timestamp_SupportProxy_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_Timestamp_SupportProxy_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__gateObj xdc_runtime_Timestamp_SupportProxy_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_Timestamp_SupportProxy_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__gatePrms xdc_runtime_Timestamp_SupportProxy_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_Timestamp_SupportProxy_Module__id;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__id xdc_runtime_Timestamp_SupportProxy_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerDefined xdc_runtime_Timestamp_SupportProxy_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerObj xdc_runtime_Timestamp_SupportProxy_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn0 xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn1 xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn2 xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn4 xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn8 xdc_runtime_Timestamp_SupportProxy_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_Timestamp_SupportProxy_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Module__startupDoneFxn xdc_runtime_Timestamp_SupportProxy_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_Timestamp_SupportProxy_Object__count;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Object__count xdc_runtime_Timestamp_SupportProxy_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_Timestamp_SupportProxy_Object__heap;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Object__heap xdc_runtime_Timestamp_SupportProxy_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_Timestamp_SupportProxy_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Object__sizeof xdc_runtime_Timestamp_SupportProxy_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_Timestamp_SupportProxy_Object__table;
__extern __FAR__ const CT__xdc_runtime_Timestamp_SupportProxy_Object__table xdc_runtime_Timestamp_SupportProxy_Object__table__C;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct xdc_runtime_Timestamp_SupportProxy_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Bits32 (*get32)(void);
    xdc_Void (*get64)(xdc_runtime_Types_Timestamp64*);
    xdc_Void (*getFreq)(xdc_runtime_Types_FreqHz*);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const xdc_runtime_Timestamp_SupportProxy_Fxns__ xdc_runtime_Timestamp_SupportProxy_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_Timestamp_SupportProxy_Module_startup( state ) (-1)

/* Handle__label__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Handle__label__S, "xdc_runtime_Timestamp_SupportProxy_Handle__label__S")
__extern xdc_runtime_Types_Label *xdc_runtime_Timestamp_SupportProxy_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S, "xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Object__create__S, "xdc_runtime_Timestamp_SupportProxy_Object__create__S")
__extern xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Object__delete__S, "xdc_runtime_Timestamp_SupportProxy_Object__delete__S")
__extern xdc_Void xdc_runtime_Timestamp_SupportProxy_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Object__destruct__S, "xdc_runtime_Timestamp_SupportProxy_Object__destruct__S")
__extern xdc_Void xdc_runtime_Timestamp_SupportProxy_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Object__get__S, "xdc_runtime_Timestamp_SupportProxy_Object__get__S")
__extern xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Object__first__S, "xdc_runtime_Timestamp_SupportProxy_Object__first__S")
__extern xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Object__next__S, "xdc_runtime_Timestamp_SupportProxy_Object__next__S")
__extern xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Params__init__S, "xdc_runtime_Timestamp_SupportProxy_Params__init__S")
__extern xdc_Void xdc_runtime_Timestamp_SupportProxy_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* Proxy__abstract__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S, "xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S")
__extern xdc_Bool xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S( void );

/* Proxy__delegate__S */
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S, "xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S")
__extern xdc_Ptr xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S( void );

/* get32__E */
#define xdc_runtime_Timestamp_SupportProxy_get32 xdc_runtime_Timestamp_SupportProxy_get32__E
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_get32__E, "xdc_runtime_Timestamp_SupportProxy_get32")
__extern xdc_Bits32 xdc_runtime_Timestamp_SupportProxy_get32__E( void );

/* get64__E */
#define xdc_runtime_Timestamp_SupportProxy_get64 xdc_runtime_Timestamp_SupportProxy_get64__E
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_get64__E, "xdc_runtime_Timestamp_SupportProxy_get64")
__extern xdc_Void xdc_runtime_Timestamp_SupportProxy_get64__E( xdc_runtime_Types_Timestamp64 *result );

/* getFreq__E */
#define xdc_runtime_Timestamp_SupportProxy_getFreq xdc_runtime_Timestamp_SupportProxy_getFreq__E
xdc__CODESECT(xdc_runtime_Timestamp_SupportProxy_getFreq__E, "xdc_runtime_Timestamp_SupportProxy_getFreq")
__extern xdc_Void xdc_runtime_Timestamp_SupportProxy_getFreq__E( xdc_runtime_Types_FreqHz *freq );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline xdc_runtime_ITimestampProvider_Module xdc_runtime_Timestamp_SupportProxy_Module_upCast( void )
{
    return (xdc_runtime_ITimestampProvider_Module)xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S();
}

/* Module_to_xdc_runtime_ITimestampProvider */
#define xdc_runtime_Timestamp_SupportProxy_Module_to_xdc_runtime_ITimestampProvider xdc_runtime_Timestamp_SupportProxy_Module_upCast

/* Module_upCast2 */
static inline xdc_runtime_ITimestampClient_Module xdc_runtime_Timestamp_SupportProxy_Module_upCast2( void )
{
    return (xdc_runtime_ITimestampClient_Module)xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S();
}

/* Module_to_xdc_runtime_ITimestampClient */
#define xdc_runtime_Timestamp_SupportProxy_Module_to_xdc_runtime_ITimestampClient xdc_runtime_Timestamp_SupportProxy_Module_upCast2


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_Timestamp_SupportProxy_Module_startupDone() xdc_runtime_Timestamp_SupportProxy_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_Timestamp_SupportProxy_Object_heap() xdc_runtime_Timestamp_SupportProxy_Object__heap__C

/* Module_heap */
#define xdc_runtime_Timestamp_SupportProxy_Module_heap() xdc_runtime_Timestamp_SupportProxy_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_Timestamp_SupportProxy_Module__id xdc_runtime_Timestamp_SupportProxy_Module_id( void ) 
{
    return xdc_runtime_Timestamp_SupportProxy_Module__id__C;
}

/* Proxy_abstract */
#define xdc_runtime_Timestamp_SupportProxy_Proxy_abstract() xdc_runtime_Timestamp_SupportProxy_Proxy__abstract__S()

/* Proxy_delegate */
#define xdc_runtime_Timestamp_SupportProxy_Proxy_delegate() ((xdc_runtime_ITimestampProvider_Module)xdc_runtime_Timestamp_SupportProxy_Proxy__delegate__S())


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_Timestamp_SupportProxy__top__
#undef __nested__
#endif

#endif /* xdc_runtime_Timestamp_SupportProxy__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_Timestamp_SupportProxy__nolocalnames)

#ifndef xdc_runtime_Timestamp_SupportProxy__localnames__done
#define xdc_runtime_Timestamp_SupportProxy__localnames__done

/* module prefix */
#define Timestamp_SupportProxy_get32 xdc_runtime_Timestamp_SupportProxy_get32
#define Timestamp_SupportProxy_get64 xdc_runtime_Timestamp_SupportProxy_get64
#define Timestamp_SupportProxy_getFreq xdc_runtime_Timestamp_SupportProxy_getFreq
#define Timestamp_SupportProxy_Module_name xdc_runtime_Timestamp_SupportProxy_Module_name
#define Timestamp_SupportProxy_Module_id xdc_runtime_Timestamp_SupportProxy_Module_id
#define Timestamp_SupportProxy_Module_startup xdc_runtime_Timestamp_SupportProxy_Module_startup
#define Timestamp_SupportProxy_Module_startupDone xdc_runtime_Timestamp_SupportProxy_Module_startupDone
#define Timestamp_SupportProxy_Module_hasMask xdc_runtime_Timestamp_SupportProxy_Module_hasMask
#define Timestamp_SupportProxy_Module_getMask xdc_runtime_Timestamp_SupportProxy_Module_getMask
#define Timestamp_SupportProxy_Module_setMask xdc_runtime_Timestamp_SupportProxy_Module_setMask
#define Timestamp_SupportProxy_Object_heap xdc_runtime_Timestamp_SupportProxy_Object_heap
#define Timestamp_SupportProxy_Module_heap xdc_runtime_Timestamp_SupportProxy_Module_heap
#define Timestamp_SupportProxy_Proxy_abstract xdc_runtime_Timestamp_SupportProxy_Proxy_abstract
#define Timestamp_SupportProxy_Proxy_delegate xdc_runtime_Timestamp_SupportProxy_Proxy_delegate
#define Timestamp_SupportProxy_Module_upCast xdc_runtime_Timestamp_SupportProxy_Module_upCast
#define Timestamp_SupportProxy_Module_to_xdc_runtime_ITimestampProvider xdc_runtime_Timestamp_SupportProxy_Module_to_xdc_runtime_ITimestampProvider
#define Timestamp_SupportProxy_Module_upCast2 xdc_runtime_Timestamp_SupportProxy_Module_upCast2
#define Timestamp_SupportProxy_Module_to_xdc_runtime_ITimestampClient xdc_runtime_Timestamp_SupportProxy_Module_to_xdc_runtime_ITimestampClient

#endif /* xdc_runtime_Timestamp_SupportProxy__localnames__done */
#endif
