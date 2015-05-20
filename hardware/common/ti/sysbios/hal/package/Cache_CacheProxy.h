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

#ifndef ti_sysbios_hal_Cache_CacheProxy__include
#define ti_sysbios_hal_Cache_CacheProxy__include

#ifndef __nested__
#define __nested__
#define ti_sysbios_hal_Cache_CacheProxy__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define ti_sysbios_hal_Cache_CacheProxy___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/hal/package/package.defs.h>

#include <ti/sysbios/interfaces/ICache.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Type */
typedef ti_sysbios_interfaces_ICache_Type ti_sysbios_hal_Cache_CacheProxy_Type;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__ti_sysbios_hal_Cache_CacheProxy_Module__diagsEnabled;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__diagsEnabled ti_sysbios_hal_Cache_CacheProxy_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__ti_sysbios_hal_Cache_CacheProxy_Module__diagsIncluded;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__diagsIncluded ti_sysbios_hal_Cache_CacheProxy_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__ti_sysbios_hal_Cache_CacheProxy_Module__diagsMask;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__diagsMask ti_sysbios_hal_Cache_CacheProxy_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__ti_sysbios_hal_Cache_CacheProxy_Module__gateObj;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__gateObj ti_sysbios_hal_Cache_CacheProxy_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__ti_sysbios_hal_Cache_CacheProxy_Module__gatePrms;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__gatePrms ti_sysbios_hal_Cache_CacheProxy_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__ti_sysbios_hal_Cache_CacheProxy_Module__id;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__id ti_sysbios_hal_Cache_CacheProxy_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerDefined;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerDefined ti_sysbios_hal_Cache_CacheProxy_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerObj;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerObj ti_sysbios_hal_Cache_CacheProxy_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn0;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn0 ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn1;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn1 ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn2;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn2 ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn4;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn4 ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn8;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn8 ti_sysbios_hal_Cache_CacheProxy_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__ti_sysbios_hal_Cache_CacheProxy_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Module__startupDoneFxn ti_sysbios_hal_Cache_CacheProxy_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__ti_sysbios_hal_Cache_CacheProxy_Object__count;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Object__count ti_sysbios_hal_Cache_CacheProxy_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__ti_sysbios_hal_Cache_CacheProxy_Object__heap;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Object__heap ti_sysbios_hal_Cache_CacheProxy_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__ti_sysbios_hal_Cache_CacheProxy_Object__sizeof;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Object__sizeof ti_sysbios_hal_Cache_CacheProxy_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__ti_sysbios_hal_Cache_CacheProxy_Object__table;
__extern __FAR__ const CT__ti_sysbios_hal_Cache_CacheProxy_Object__table ti_sysbios_hal_Cache_CacheProxy_Object__table__C;


/*
 * ======== VIRTUAL FUNCTIONS ========
 */

/* Fxns__ */
struct ti_sysbios_hal_Cache_CacheProxy_Fxns__ {
    xdc_runtime_Types_Base* __base;
    const xdc_runtime_Types_SysFxns2 *__sysp;
    xdc_Void (*enable)(xdc_Bits16);
    xdc_Void (*disable)(xdc_Bits16);
    xdc_Void (*inv)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
    xdc_Void (*wb)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
    xdc_Void (*wbInv)(xdc_Ptr, xdc_SizeT, xdc_Bits16, xdc_Bool);
    xdc_Void (*wbAll)(void);
    xdc_Void (*wbInvAll)(void);
    xdc_Void (*wait)(void);
    xdc_runtime_Types_SysFxns2 __sfxns;
};

/* Module__FXNS__C */
__extern const ti_sysbios_hal_Cache_CacheProxy_Fxns__ ti_sysbios_hal_Cache_CacheProxy_Module__FXNS__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define ti_sysbios_hal_Cache_CacheProxy_Module_startup( state ) (-1)

/* Handle__label__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Handle__label__S, "ti_sysbios_hal_Cache_CacheProxy_Handle__label__S")
__extern xdc_runtime_Types_Label *ti_sysbios_hal_Cache_CacheProxy_Handle__label__S( xdc_Ptr obj, xdc_runtime_Types_Label *lab );

/* Module__startupDone__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Module__startupDone__S, "ti_sysbios_hal_Cache_CacheProxy_Module__startupDone__S")
__extern xdc_Bool ti_sysbios_hal_Cache_CacheProxy_Module__startupDone__S( void );

/* Object__create__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Object__create__S, "ti_sysbios_hal_Cache_CacheProxy_Object__create__S")
__extern xdc_Ptr ti_sysbios_hal_Cache_CacheProxy_Object__create__S( xdc_Ptr __oa, xdc_SizeT __osz, xdc_Ptr __aa, const xdc_UChar *__pa, xdc_SizeT __psz, xdc_runtime_Error_Block *__eb );

/* Object__delete__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Object__delete__S, "ti_sysbios_hal_Cache_CacheProxy_Object__delete__S")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_Object__delete__S( xdc_Ptr instp );

/* Object__destruct__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Object__destruct__S, "ti_sysbios_hal_Cache_CacheProxy_Object__destruct__S")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_Object__destruct__S( xdc_Ptr objp );

/* Object__get__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Object__get__S, "ti_sysbios_hal_Cache_CacheProxy_Object__get__S")
__extern xdc_Ptr ti_sysbios_hal_Cache_CacheProxy_Object__get__S( xdc_Ptr oarr, xdc_Int i );

/* Object__first__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Object__first__S, "ti_sysbios_hal_Cache_CacheProxy_Object__first__S")
__extern xdc_Ptr ti_sysbios_hal_Cache_CacheProxy_Object__first__S( void );

/* Object__next__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Object__next__S, "ti_sysbios_hal_Cache_CacheProxy_Object__next__S")
__extern xdc_Ptr ti_sysbios_hal_Cache_CacheProxy_Object__next__S( xdc_Ptr obj );

/* Params__init__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Params__init__S, "ti_sysbios_hal_Cache_CacheProxy_Params__init__S")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_Params__init__S( xdc_Ptr dst, const xdc_Void *src, xdc_SizeT psz, xdc_SizeT isz );

/* Proxy__abstract__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Proxy__abstract__S, "ti_sysbios_hal_Cache_CacheProxy_Proxy__abstract__S")
__extern xdc_Bool ti_sysbios_hal_Cache_CacheProxy_Proxy__abstract__S( void );

/* Proxy__delegate__S */
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_Proxy__delegate__S, "ti_sysbios_hal_Cache_CacheProxy_Proxy__delegate__S")
__extern xdc_Ptr ti_sysbios_hal_Cache_CacheProxy_Proxy__delegate__S( void );

/* enable__E */
#define ti_sysbios_hal_Cache_CacheProxy_enable ti_sysbios_hal_Cache_CacheProxy_enable__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_enable__E, "ti_sysbios_hal_Cache_CacheProxy_enable")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_enable__E( xdc_Bits16 type );

/* disable__E */
#define ti_sysbios_hal_Cache_CacheProxy_disable ti_sysbios_hal_Cache_CacheProxy_disable__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_disable__E, "ti_sysbios_hal_Cache_CacheProxy_disable")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_disable__E( xdc_Bits16 type );

/* inv__E */
#define ti_sysbios_hal_Cache_CacheProxy_inv ti_sysbios_hal_Cache_CacheProxy_inv__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_inv__E, "ti_sysbios_hal_Cache_CacheProxy_inv")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_inv__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait );

/* wb__E */
#define ti_sysbios_hal_Cache_CacheProxy_wb ti_sysbios_hal_Cache_CacheProxy_wb__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_wb__E, "ti_sysbios_hal_Cache_CacheProxy_wb")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_wb__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait );

/* wbInv__E */
#define ti_sysbios_hal_Cache_CacheProxy_wbInv ti_sysbios_hal_Cache_CacheProxy_wbInv__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_wbInv__E, "ti_sysbios_hal_Cache_CacheProxy_wbInv")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbInv__E( xdc_Ptr blockPtr, xdc_SizeT byteCnt, xdc_Bits16 type, xdc_Bool wait );

/* wbAll__E */
#define ti_sysbios_hal_Cache_CacheProxy_wbAll ti_sysbios_hal_Cache_CacheProxy_wbAll__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_wbAll__E, "ti_sysbios_hal_Cache_CacheProxy_wbAll")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbAll__E( void );

/* wbInvAll__E */
#define ti_sysbios_hal_Cache_CacheProxy_wbInvAll ti_sysbios_hal_Cache_CacheProxy_wbInvAll__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_wbInvAll__E, "ti_sysbios_hal_Cache_CacheProxy_wbInvAll")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_wbInvAll__E( void );

/* wait__E */
#define ti_sysbios_hal_Cache_CacheProxy_wait ti_sysbios_hal_Cache_CacheProxy_wait__E
xdc__CODESECT(ti_sysbios_hal_Cache_CacheProxy_wait__E, "ti_sysbios_hal_Cache_CacheProxy_wait")
__extern xdc_Void ti_sysbios_hal_Cache_CacheProxy_wait__E( void );


/*
 * ======== CONVERTORS ========
 */

/* Module_upCast */
static inline ti_sysbios_interfaces_ICache_Module ti_sysbios_hal_Cache_CacheProxy_Module_upCast( void )
{
    return (ti_sysbios_interfaces_ICache_Module)ti_sysbios_hal_Cache_CacheProxy_Proxy__delegate__S();
}

/* Module_to_ti_sysbios_interfaces_ICache */
#define ti_sysbios_hal_Cache_CacheProxy_Module_to_ti_sysbios_interfaces_ICache ti_sysbios_hal_Cache_CacheProxy_Module_upCast


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define ti_sysbios_hal_Cache_CacheProxy_Module_startupDone() ti_sysbios_hal_Cache_CacheProxy_Module__startupDone__S()

/* Object_heap */
#define ti_sysbios_hal_Cache_CacheProxy_Object_heap() ti_sysbios_hal_Cache_CacheProxy_Object__heap__C

/* Module_heap */
#define ti_sysbios_hal_Cache_CacheProxy_Module_heap() ti_sysbios_hal_Cache_CacheProxy_Object__heap__C

/* Module_id */
static inline CT__ti_sysbios_hal_Cache_CacheProxy_Module__id ti_sysbios_hal_Cache_CacheProxy_Module_id( void ) 
{
    return ti_sysbios_hal_Cache_CacheProxy_Module__id__C;
}

/* Proxy_abstract */
#define ti_sysbios_hal_Cache_CacheProxy_Proxy_abstract() ti_sysbios_hal_Cache_CacheProxy_Proxy__abstract__S()

/* Proxy_delegate */
#define ti_sysbios_hal_Cache_CacheProxy_Proxy_delegate() ((ti_sysbios_interfaces_ICache_Module)ti_sysbios_hal_Cache_CacheProxy_Proxy__delegate__S())


/*
 * ======== EPILOGUE ========
 */

#ifdef ti_sysbios_hal_Cache_CacheProxy__top__
#undef __nested__
#endif

#endif /* ti_sysbios_hal_Cache_CacheProxy__include */


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(ti_sysbios_hal_Cache_CacheProxy__nolocalnames)

#ifndef ti_sysbios_hal_Cache_CacheProxy__localnames__done
#define ti_sysbios_hal_Cache_CacheProxy__localnames__done

/* module prefix */
#define Cache_CacheProxy_Type ti_sysbios_hal_Cache_CacheProxy_Type
#define Cache_CacheProxy_enable ti_sysbios_hal_Cache_CacheProxy_enable
#define Cache_CacheProxy_disable ti_sysbios_hal_Cache_CacheProxy_disable
#define Cache_CacheProxy_inv ti_sysbios_hal_Cache_CacheProxy_inv
#define Cache_CacheProxy_wb ti_sysbios_hal_Cache_CacheProxy_wb
#define Cache_CacheProxy_wbInv ti_sysbios_hal_Cache_CacheProxy_wbInv
#define Cache_CacheProxy_wbAll ti_sysbios_hal_Cache_CacheProxy_wbAll
#define Cache_CacheProxy_wbInvAll ti_sysbios_hal_Cache_CacheProxy_wbInvAll
#define Cache_CacheProxy_wait ti_sysbios_hal_Cache_CacheProxy_wait
#define Cache_CacheProxy_Module_name ti_sysbios_hal_Cache_CacheProxy_Module_name
#define Cache_CacheProxy_Module_id ti_sysbios_hal_Cache_CacheProxy_Module_id
#define Cache_CacheProxy_Module_startup ti_sysbios_hal_Cache_CacheProxy_Module_startup
#define Cache_CacheProxy_Module_startupDone ti_sysbios_hal_Cache_CacheProxy_Module_startupDone
#define Cache_CacheProxy_Module_hasMask ti_sysbios_hal_Cache_CacheProxy_Module_hasMask
#define Cache_CacheProxy_Module_getMask ti_sysbios_hal_Cache_CacheProxy_Module_getMask
#define Cache_CacheProxy_Module_setMask ti_sysbios_hal_Cache_CacheProxy_Module_setMask
#define Cache_CacheProxy_Object_heap ti_sysbios_hal_Cache_CacheProxy_Object_heap
#define Cache_CacheProxy_Module_heap ti_sysbios_hal_Cache_CacheProxy_Module_heap
#define Cache_CacheProxy_Proxy_abstract ti_sysbios_hal_Cache_CacheProxy_Proxy_abstract
#define Cache_CacheProxy_Proxy_delegate ti_sysbios_hal_Cache_CacheProxy_Proxy_delegate
#define Cache_CacheProxy_Module_upCast ti_sysbios_hal_Cache_CacheProxy_Module_upCast
#define Cache_CacheProxy_Module_to_ti_sysbios_interfaces_ICache ti_sysbios_hal_Cache_CacheProxy_Module_to_ti_sysbios_interfaces_ICache

#endif /* ti_sysbios_hal_Cache_CacheProxy__localnames__done */
#endif
