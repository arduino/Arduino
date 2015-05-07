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

#ifndef xdc_runtime_Error__include
#define xdc_runtime_Error__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_Error__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_Error___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Error__prologue.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/Types.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* Policy */
enum xdc_runtime_Error_Policy {
    xdc_runtime_Error_TERMINATE,
    xdc_runtime_Error_UNWIND
};
typedef enum xdc_runtime_Error_Policy xdc_runtime_Error_Policy;

/* Id */

/* HookFxn */
typedef xdc_Void (*xdc_runtime_Error_HookFxn)(xdc_runtime_Error_Block*);

/* NUMARGS */
#define xdc_runtime_Error_NUMARGS (2)

/* Data */
typedef xdc_IArg __T1_xdc_runtime_Error_Data__arg;
typedef xdc_IArg __ARRAY1_xdc_runtime_Error_Data__arg[2];
typedef __ARRAY1_xdc_runtime_Error_Data__arg __TA_xdc_runtime_Error_Data__arg;
struct xdc_runtime_Error_Data {
    __TA_xdc_runtime_Error_Data__arg arg;
};

/* Block */
typedef xdc_IArg __T1_xdc_runtime_Error_Block__xtra;
typedef xdc_IArg __ARRAY1_xdc_runtime_Error_Block__xtra[4];
typedef __ARRAY1_xdc_runtime_Error_Block__xtra __TA_xdc_runtime_Error_Block__xtra;
struct xdc_runtime_Error_Block {
    xdc_UInt16 unused;
    xdc_runtime_Error_Data data;
    xdc_runtime_Error_Id id;
    xdc_String msg;
    xdc_runtime_Types_Site site;
    __TA_xdc_runtime_Error_Block__xtra xtra;
};

/* PolicyFxn */
typedef xdc_Void (*xdc_runtime_Error_PolicyFxn)(xdc_runtime_Error_Block*, xdc_runtime_Types_ModuleId, xdc_CString, xdc_Int, xdc_runtime_Error_Id, xdc_IArg, xdc_IArg);


/*
 * ======== INTERNAL DEFINITIONS ========
 */


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_Error_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_Error_Module__diagsEnabled xdc_runtime_Error_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_Error_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_Error_Module__diagsIncluded xdc_runtime_Error_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_Error_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_Error_Module__diagsMask xdc_runtime_Error_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_Error_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_Error_Module__gateObj xdc_runtime_Error_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_Error_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_Error_Module__gatePrms xdc_runtime_Error_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_Error_Module__id;
__extern __FAR__ const CT__xdc_runtime_Error_Module__id xdc_runtime_Error_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_Error_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_Error_Module__loggerDefined xdc_runtime_Error_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_Error_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_Error_Module__loggerObj xdc_runtime_Error_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_Error_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_Error_Module__loggerFxn0 xdc_runtime_Error_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_Error_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_Error_Module__loggerFxn1 xdc_runtime_Error_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_Error_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_Error_Module__loggerFxn2 xdc_runtime_Error_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_Error_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_Error_Module__loggerFxn4 xdc_runtime_Error_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_Error_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_Error_Module__loggerFxn8 xdc_runtime_Error_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_Error_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_Error_Module__startupDoneFxn xdc_runtime_Error_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_Error_Object__count;
__extern __FAR__ const CT__xdc_runtime_Error_Object__count xdc_runtime_Error_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_Error_Object__heap;
__extern __FAR__ const CT__xdc_runtime_Error_Object__heap xdc_runtime_Error_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_Error_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_Error_Object__sizeof xdc_runtime_Error_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_Error_Object__table;
__extern __FAR__ const CT__xdc_runtime_Error_Object__table xdc_runtime_Error_Object__table__C;

/* policyFxn */
#define xdc_runtime_Error_policyFxn (xdc_runtime_Error_policyFxn__C)
typedef xdc_runtime_Error_PolicyFxn CT__xdc_runtime_Error_policyFxn;
__extern __FAR__ const CT__xdc_runtime_Error_policyFxn xdc_runtime_Error_policyFxn__C;

/* E_generic */
#define xdc_runtime_Error_E_generic (xdc_runtime_Error_E_generic__C)
typedef xdc_runtime_Error_Id CT__xdc_runtime_Error_E_generic;
__extern __FAR__ const CT__xdc_runtime_Error_E_generic xdc_runtime_Error_E_generic__C;

/* E_memory */
#define xdc_runtime_Error_E_memory (xdc_runtime_Error_E_memory__C)
typedef xdc_runtime_Error_Id CT__xdc_runtime_Error_E_memory;
__extern __FAR__ const CT__xdc_runtime_Error_E_memory xdc_runtime_Error_E_memory__C;

/* E_msgCode */
#define xdc_runtime_Error_E_msgCode (xdc_runtime_Error_E_msgCode__C)
typedef xdc_runtime_Error_Id CT__xdc_runtime_Error_E_msgCode;
__extern __FAR__ const CT__xdc_runtime_Error_E_msgCode xdc_runtime_Error_E_msgCode__C;

/* policy */
#define xdc_runtime_Error_policy (xdc_runtime_Error_policy__C)
typedef xdc_runtime_Error_Policy CT__xdc_runtime_Error_policy;
__extern __FAR__ const CT__xdc_runtime_Error_policy xdc_runtime_Error_policy__C;

/* raiseHook */
#define xdc_runtime_Error_raiseHook (xdc_runtime_Error_raiseHook__C)
typedef xdc_runtime_Error_HookFxn CT__xdc_runtime_Error_raiseHook;
__extern __FAR__ const CT__xdc_runtime_Error_raiseHook xdc_runtime_Error_raiseHook__C;

/* maxDepth */
#ifdef xdc_runtime_Error_maxDepth__D
#define xdc_runtime_Error_maxDepth (xdc_runtime_Error_maxDepth__D)
#else
#define xdc_runtime_Error_maxDepth (xdc_runtime_Error_maxDepth__C)
typedef xdc_UInt16 CT__xdc_runtime_Error_maxDepth;
__extern __FAR__ const CT__xdc_runtime_Error_maxDepth xdc_runtime_Error_maxDepth__C;
#endif


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_Error_Module_startup( state ) (-1)

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_Error_Module__startupDone__S, "xdc_runtime_Error_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_Error_Module__startupDone__S( void );

/* check__E */
#define xdc_runtime_Error_check xdc_runtime_Error_check__E
xdc__CODESECT(xdc_runtime_Error_check__E, "xdc_runtime_Error_check")
__extern xdc_Bool xdc_runtime_Error_check__E( xdc_runtime_Error_Block *eb );

/* getData__E */
#define xdc_runtime_Error_getData xdc_runtime_Error_getData__E
xdc__CODESECT(xdc_runtime_Error_getData__E, "xdc_runtime_Error_getData")
__extern xdc_runtime_Error_Data *xdc_runtime_Error_getData__E( xdc_runtime_Error_Block *eb );

/* getCode__E */
#define xdc_runtime_Error_getCode xdc_runtime_Error_getCode__E
xdc__CODESECT(xdc_runtime_Error_getCode__E, "xdc_runtime_Error_getCode")
__extern xdc_UInt16 xdc_runtime_Error_getCode__E( xdc_runtime_Error_Block *eb );

/* getId__E */
#define xdc_runtime_Error_getId xdc_runtime_Error_getId__E
xdc__CODESECT(xdc_runtime_Error_getId__E, "xdc_runtime_Error_getId")
__extern xdc_runtime_Error_Id xdc_runtime_Error_getId__E( xdc_runtime_Error_Block *eb );

/* getMsg__E */
#define xdc_runtime_Error_getMsg xdc_runtime_Error_getMsg__E
xdc__CODESECT(xdc_runtime_Error_getMsg__E, "xdc_runtime_Error_getMsg")
__extern xdc_String xdc_runtime_Error_getMsg__E( xdc_runtime_Error_Block *eb );

/* getSite__E */
#define xdc_runtime_Error_getSite xdc_runtime_Error_getSite__E
xdc__CODESECT(xdc_runtime_Error_getSite__E, "xdc_runtime_Error_getSite")
__extern xdc_runtime_Types_Site *xdc_runtime_Error_getSite__E( xdc_runtime_Error_Block *eb );

/* init__E */
#define xdc_runtime_Error_init xdc_runtime_Error_init__E
xdc__CODESECT(xdc_runtime_Error_init__E, "xdc_runtime_Error_init")
__extern xdc_Void xdc_runtime_Error_init__E( xdc_runtime_Error_Block *eb );

/* print__E */
#define xdc_runtime_Error_print xdc_runtime_Error_print__E
xdc__CODESECT(xdc_runtime_Error_print__E, "xdc_runtime_Error_print")
__extern xdc_Void xdc_runtime_Error_print__E( xdc_runtime_Error_Block *eb );

/* policyDefault__E */
#define xdc_runtime_Error_policyDefault xdc_runtime_Error_policyDefault__E
xdc__CODESECT(xdc_runtime_Error_policyDefault__E, "xdc_runtime_Error_policyDefault")
__extern xdc_Void xdc_runtime_Error_policyDefault__E( xdc_runtime_Error_Block *eb, xdc_runtime_Types_ModuleId mod, xdc_CString file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 );

/* policySpin__E */
#define xdc_runtime_Error_policySpin xdc_runtime_Error_policySpin__E
xdc__CODESECT(xdc_runtime_Error_policySpin__E, "xdc_runtime_Error_policySpin")
__extern xdc_Void xdc_runtime_Error_policySpin__E( xdc_runtime_Error_Block *eb, xdc_runtime_Types_ModuleId mod, xdc_CString file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 );

/* raiseX__E */
#define xdc_runtime_Error_raiseX xdc_runtime_Error_raiseX__E
xdc__CODESECT(xdc_runtime_Error_raiseX__E, "xdc_runtime_Error_raiseX")
__extern xdc_Void xdc_runtime_Error_raiseX__E( xdc_runtime_Error_Block *eb, xdc_runtime_Types_ModuleId mod, xdc_CString file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 );

/* setX__E */
#define xdc_runtime_Error_setX xdc_runtime_Error_setX__E
xdc__CODESECT(xdc_runtime_Error_setX__E, "xdc_runtime_Error_setX")
__extern xdc_Void xdc_runtime_Error_setX__E( xdc_runtime_Error_Block *eb, xdc_runtime_Types_ModuleId mod, xdc_CString file, xdc_Int line, xdc_runtime_Error_Id id, xdc_IArg arg1, xdc_IArg arg2 );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_Error_Module_startupDone() xdc_runtime_Error_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_Error_Object_heap() xdc_runtime_Error_Object__heap__C

/* Module_heap */
#define xdc_runtime_Error_Module_heap() xdc_runtime_Error_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_Error_Module__id xdc_runtime_Error_Module_id( void ) 
{
    return xdc_runtime_Error_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_Error_Module_hasMask( void ) 
{
    return xdc_runtime_Error_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_Error_Module_getMask( void ) 
{
    return xdc_runtime_Error_Module__diagsMask__C != NULL ? *xdc_runtime_Error_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_Error_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_Error_Module__diagsMask__C != NULL) *xdc_runtime_Error_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#include <xdc/runtime/Error__epilogue.h>

#ifdef xdc_runtime_Error__top__
#undef __nested__
#endif

#endif /* xdc_runtime_Error__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_Error__internalaccess))

#ifndef xdc_runtime_Error__include_state
#define xdc_runtime_Error__include_state

/* Module_State */
struct xdc_runtime_Error_Module_State {
    xdc_UInt16 count;
};

/* Module__state__V */
extern struct xdc_runtime_Error_Module_State__ xdc_runtime_Error_Module__state__V;

#endif /* xdc_runtime_Error__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_Error__nolocalnames)

#ifndef xdc_runtime_Error__localnames__done
#define xdc_runtime_Error__localnames__done

/* module prefix */
#define Error_Policy xdc_runtime_Error_Policy
#define Error_Id xdc_runtime_Error_Id
#define Error_HookFxn xdc_runtime_Error_HookFxn
#define Error_NUMARGS xdc_runtime_Error_NUMARGS
#define Error_Data xdc_runtime_Error_Data
#define Error_Block xdc_runtime_Error_Block
#define Error_PolicyFxn xdc_runtime_Error_PolicyFxn
#define Error_Module_State xdc_runtime_Error_Module_State
#define Error_TERMINATE xdc_runtime_Error_TERMINATE
#define Error_UNWIND xdc_runtime_Error_UNWIND
#define Error_policyFxn xdc_runtime_Error_policyFxn
#define Error_E_generic xdc_runtime_Error_E_generic
#define Error_E_memory xdc_runtime_Error_E_memory
#define Error_E_msgCode xdc_runtime_Error_E_msgCode
#define Error_policy xdc_runtime_Error_policy
#define Error_raiseHook xdc_runtime_Error_raiseHook
#define Error_maxDepth xdc_runtime_Error_maxDepth
#define Error_check xdc_runtime_Error_check
#define Error_getData xdc_runtime_Error_getData
#define Error_getCode xdc_runtime_Error_getCode
#define Error_getId xdc_runtime_Error_getId
#define Error_getMsg xdc_runtime_Error_getMsg
#define Error_getSite xdc_runtime_Error_getSite
#define Error_idToCode xdc_runtime_Error_idToCode
#define Error_idToUid xdc_runtime_Error_idToUid
#define Error_init xdc_runtime_Error_init
#define Error_print xdc_runtime_Error_print
#define Error_policyDefault xdc_runtime_Error_policyDefault
#define Error_policySpin xdc_runtime_Error_policySpin
#define Error_raise xdc_runtime_Error_raise
#define Error_raiseX xdc_runtime_Error_raiseX
#define Error_setX xdc_runtime_Error_setX
#define Error_Module_name xdc_runtime_Error_Module_name
#define Error_Module_id xdc_runtime_Error_Module_id
#define Error_Module_startup xdc_runtime_Error_Module_startup
#define Error_Module_startupDone xdc_runtime_Error_Module_startupDone
#define Error_Module_hasMask xdc_runtime_Error_Module_hasMask
#define Error_Module_getMask xdc_runtime_Error_Module_getMask
#define Error_Module_setMask xdc_runtime_Error_Module_setMask
#define Error_Object_heap xdc_runtime_Error_Object_heap
#define Error_Module_heap xdc_runtime_Error_Module_heap

#endif /* xdc_runtime_Error__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:11; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

