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

#ifndef xdc_runtime_Core__include
#define xdc_runtime_Core__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_Core__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_Core___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Text.h>
#include <xdc/runtime/Error.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* ObjDesc */
struct xdc_runtime_Core_ObjDesc {
    xdc_Ptr fxnTab;
    xdc_runtime_Types_Link *modLink;
    xdc_SizeT objAlign;
    xdc_runtime_IHeap_Handle objHeap;
    xdc_SizeT objName;
    xdc_SizeT objSize;
    xdc_Ptr prmsInit;
    xdc_SizeT prmsSize;
};


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_Core_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_Core_Module__diagsEnabled xdc_runtime_Core_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_Core_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_Core_Module__diagsIncluded xdc_runtime_Core_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_Core_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_Core_Module__diagsMask xdc_runtime_Core_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_Core_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_Core_Module__gateObj xdc_runtime_Core_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_Core_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_Core_Module__gatePrms xdc_runtime_Core_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_Core_Module__id;
__extern __FAR__ const CT__xdc_runtime_Core_Module__id xdc_runtime_Core_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_Core_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_Core_Module__loggerDefined xdc_runtime_Core_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_Core_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_Core_Module__loggerObj xdc_runtime_Core_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_Core_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_Core_Module__loggerFxn0 xdc_runtime_Core_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_Core_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_Core_Module__loggerFxn1 xdc_runtime_Core_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_Core_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_Core_Module__loggerFxn2 xdc_runtime_Core_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_Core_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_Core_Module__loggerFxn4 xdc_runtime_Core_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_Core_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_Core_Module__loggerFxn8 xdc_runtime_Core_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_Core_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_Core_Module__startupDoneFxn xdc_runtime_Core_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_Core_Object__count;
__extern __FAR__ const CT__xdc_runtime_Core_Object__count xdc_runtime_Core_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_Core_Object__heap;
__extern __FAR__ const CT__xdc_runtime_Core_Object__heap xdc_runtime_Core_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_Core_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_Core_Object__sizeof xdc_runtime_Core_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_Core_Object__table;
__extern __FAR__ const CT__xdc_runtime_Core_Object__table xdc_runtime_Core_Object__table__C;

/* A_initializedParams */
#define xdc_runtime_Core_A_initializedParams (xdc_runtime_Core_A_initializedParams__C)
typedef xdc_runtime_Assert_Id CT__xdc_runtime_Core_A_initializedParams;
__extern __FAR__ const CT__xdc_runtime_Core_A_initializedParams xdc_runtime_Core_A_initializedParams__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_Core_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_Core_Module__startupDone__S, "xdc_runtime_Core_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_Core_Module__startupDone__S( void );

/* assignLabel__I */
#define xdc_runtime_Core_assignLabel xdc_runtime_Core_assignLabel__I
xdc__CODESECT(xdc_runtime_Core_assignLabel__I, "xdc_runtime_Core_assignLabel")
__extern xdc_Void xdc_runtime_Core_assignLabel__I( xdc_runtime_Types_Label *lab, xdc_runtime_Text_CordAddr iname, xdc_Bool named );

/* assignParams__I */
#define xdc_runtime_Core_assignParams xdc_runtime_Core_assignParams__I
xdc__CODESECT(xdc_runtime_Core_assignParams__I, "xdc_runtime_Core_assignParams")
__extern xdc_Void xdc_runtime_Core_assignParams__I( xdc_Ptr dstPrms, const xdc_Ptr srcPrms, xdc_SizeT mpsz, xdc_SizeT ipsz );

/* createObject__I */
#define xdc_runtime_Core_createObject xdc_runtime_Core_createObject__I
xdc__CODESECT(xdc_runtime_Core_createObject__I, "xdc_runtime_Core_createObject")
__extern xdc_Ptr xdc_runtime_Core_createObject__I( const xdc_runtime_Core_ObjDesc *od, xdc_Ptr curObj, xdc_Ptr resPrms, const xdc_Ptr argPrms, xdc_SizeT argPrmsSize, xdc_runtime_Error_Block *eb );

/* constructObject__I */
#define xdc_runtime_Core_constructObject xdc_runtime_Core_constructObject__I
xdc__CODESECT(xdc_runtime_Core_constructObject__I, "xdc_runtime_Core_constructObject")
__extern xdc_Ptr xdc_runtime_Core_constructObject__I( const xdc_runtime_Core_ObjDesc *od, xdc_Ptr curObj, xdc_Ptr resPrms, const xdc_Ptr argPrms, xdc_SizeT argPrmsSize, xdc_runtime_Error_Block *eb );

/* deleteObject__I */
#define xdc_runtime_Core_deleteObject xdc_runtime_Core_deleteObject__I
xdc__CODESECT(xdc_runtime_Core_deleteObject__I, "xdc_runtime_Core_deleteObject")
__extern xdc_Void xdc_runtime_Core_deleteObject__I( const xdc_runtime_Core_ObjDesc *od, xdc_Ptr curObj, xdc_Fxn finalFxn, xdc_Int istat, xdc_Bool consFlg );

/* destructObject__I */
#define xdc_runtime_Core_destructObject xdc_runtime_Core_destructObject__I
xdc__CODESECT(xdc_runtime_Core_destructObject__I, "xdc_runtime_Core_destructObject")
__extern xdc_Void xdc_runtime_Core_destructObject__I( const xdc_runtime_Core_ObjDesc *od, xdc_Ptr curObj, xdc_Fxn finalFxn, xdc_Int istat, xdc_Bool consFlg );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_Core_Module_startupDone() xdc_runtime_Core_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_Core_Object_heap() xdc_runtime_Core_Object__heap__C

/* Module_heap */
#define xdc_runtime_Core_Module_heap() xdc_runtime_Core_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_Core_Module__id xdc_runtime_Core_Module_id( void ) 
{
    return xdc_runtime_Core_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_Core_Module_hasMask( void ) 
{
    return xdc_runtime_Core_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_Core_Module_getMask( void ) 
{
    return xdc_runtime_Core_Module__diagsMask__C != NULL ? *xdc_runtime_Core_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_Core_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_Core_Module__diagsMask__C != NULL) *xdc_runtime_Core_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_Core__top__
#undef __nested__
#endif

#endif /* xdc_runtime_Core__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_Core__internalaccess))

#ifndef xdc_runtime_Core__include_state
#define xdc_runtime_Core__include_state


#endif /* xdc_runtime_Core__include_state */

#endif

/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_Core__nolocalnames)

#ifndef xdc_runtime_Core__localnames__done
#define xdc_runtime_Core__localnames__done

/* module prefix */
#define Core_ObjDesc xdc_runtime_Core_ObjDesc
#define Core_A_initializedParams xdc_runtime_Core_A_initializedParams
#define Core_Module_name xdc_runtime_Core_Module_name
#define Core_Module_id xdc_runtime_Core_Module_id
#define Core_Module_startup xdc_runtime_Core_Module_startup
#define Core_Module_startupDone xdc_runtime_Core_Module_startupDone
#define Core_Module_hasMask xdc_runtime_Core_Module_hasMask
#define Core_Module_getMask xdc_runtime_Core_Module_getMask
#define Core_Module_setMask xdc_runtime_Core_Module_setMask
#define Core_Object_heap xdc_runtime_Core_Object_heap
#define Core_Module_heap xdc_runtime_Core_Module_heap

#endif /* xdc_runtime_Core__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:11; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

