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

#ifndef xdc_runtime_System__include
#define xdc_runtime_System__include

#ifndef __nested__
#define __nested__
#define xdc_runtime_System__top__
#endif

#ifdef __cplusplus
#define __extern extern "C"
#else
#define __extern extern
#endif

#define xdc_runtime_System___VERS 160


/*
 * ======== INCLUDES ========
 */

#include <xdc/std.h>

#include <xdc/runtime/xdc.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/package/package.defs.h>

#include <xdc/runtime/IModule.h>
#include <xdc/runtime/Assert.h>
#include <xdc/runtime/ISystemSupport.h>
#include <xdc/runtime/IGateProvider.h>
#include <xdc/runtime/package/System_SupportProxy.h>
#include <xdc/runtime/package/System_Module_GateProxy.h>


/*
 * ======== AUXILIARY DEFINITIONS ========
 */

/* AtexitHandler */
typedef xdc_Void (*xdc_runtime_System_AtexitHandler)(xdc_Int);

/* STATUS_UNKNOWN */
#define xdc_runtime_System_STATUS_UNKNOWN (0xCAFE)

/* AbortFxn */
typedef xdc_Void (*xdc_runtime_System_AbortFxn)(void);

/* ExitFxn */
typedef xdc_Void (*xdc_runtime_System_ExitFxn)(xdc_Int);


/*
 * ======== INTERNAL DEFINITIONS ========
 */

/* ParseData */
struct xdc_runtime_System_ParseData {
    xdc_Int width;
    xdc_Bool lFlag;
    xdc_Bool lJust;
    xdc_Int precis;
    xdc_Int len;
    xdc_Int zpad;
    xdc_Char *end;
    xdc_Bool aFlag;
    xdc_Char *ptr;
};

/* ExtendFxn */
typedef xdc_Int (*xdc_runtime_System_ExtendFxn)(xdc_Char**, xdc_CString*, xdc_VaList*, xdc_runtime_System_ParseData*);

/* Module_State */
typedef xdc_runtime_System_AtexitHandler __T1_xdc_runtime_System_Module_State__atexitHandlers;
typedef xdc_runtime_System_AtexitHandler *__ARRAY1_xdc_runtime_System_Module_State__atexitHandlers;
typedef __ARRAY1_xdc_runtime_System_Module_State__atexitHandlers __TA_xdc_runtime_System_Module_State__atexitHandlers;


/*
 * ======== MODULE-WIDE CONFIGS ========
 */

/* Module__diagsEnabled */
typedef xdc_Bits32 CT__xdc_runtime_System_Module__diagsEnabled;
__extern __FAR__ const CT__xdc_runtime_System_Module__diagsEnabled xdc_runtime_System_Module__diagsEnabled__C;

/* Module__diagsIncluded */
typedef xdc_Bits32 CT__xdc_runtime_System_Module__diagsIncluded;
__extern __FAR__ const CT__xdc_runtime_System_Module__diagsIncluded xdc_runtime_System_Module__diagsIncluded__C;

/* Module__diagsMask */
typedef xdc_Bits16 *CT__xdc_runtime_System_Module__diagsMask;
__extern __FAR__ const CT__xdc_runtime_System_Module__diagsMask xdc_runtime_System_Module__diagsMask__C;

/* Module__gateObj */
typedef xdc_Ptr CT__xdc_runtime_System_Module__gateObj;
__extern __FAR__ const CT__xdc_runtime_System_Module__gateObj xdc_runtime_System_Module__gateObj__C;

/* Module__gatePrms */
typedef xdc_Ptr CT__xdc_runtime_System_Module__gatePrms;
__extern __FAR__ const CT__xdc_runtime_System_Module__gatePrms xdc_runtime_System_Module__gatePrms__C;

/* Module__id */
typedef xdc_runtime_Types_ModuleId CT__xdc_runtime_System_Module__id;
__extern __FAR__ const CT__xdc_runtime_System_Module__id xdc_runtime_System_Module__id__C;

/* Module__loggerDefined */
typedef xdc_Bool CT__xdc_runtime_System_Module__loggerDefined;
__extern __FAR__ const CT__xdc_runtime_System_Module__loggerDefined xdc_runtime_System_Module__loggerDefined__C;

/* Module__loggerObj */
typedef xdc_Ptr CT__xdc_runtime_System_Module__loggerObj;
__extern __FAR__ const CT__xdc_runtime_System_Module__loggerObj xdc_runtime_System_Module__loggerObj__C;

/* Module__loggerFxn0 */
typedef xdc_runtime_Types_LoggerFxn0 CT__xdc_runtime_System_Module__loggerFxn0;
__extern __FAR__ const CT__xdc_runtime_System_Module__loggerFxn0 xdc_runtime_System_Module__loggerFxn0__C;

/* Module__loggerFxn1 */
typedef xdc_runtime_Types_LoggerFxn1 CT__xdc_runtime_System_Module__loggerFxn1;
__extern __FAR__ const CT__xdc_runtime_System_Module__loggerFxn1 xdc_runtime_System_Module__loggerFxn1__C;

/* Module__loggerFxn2 */
typedef xdc_runtime_Types_LoggerFxn2 CT__xdc_runtime_System_Module__loggerFxn2;
__extern __FAR__ const CT__xdc_runtime_System_Module__loggerFxn2 xdc_runtime_System_Module__loggerFxn2__C;

/* Module__loggerFxn4 */
typedef xdc_runtime_Types_LoggerFxn4 CT__xdc_runtime_System_Module__loggerFxn4;
__extern __FAR__ const CT__xdc_runtime_System_Module__loggerFxn4 xdc_runtime_System_Module__loggerFxn4__C;

/* Module__loggerFxn8 */
typedef xdc_runtime_Types_LoggerFxn8 CT__xdc_runtime_System_Module__loggerFxn8;
__extern __FAR__ const CT__xdc_runtime_System_Module__loggerFxn8 xdc_runtime_System_Module__loggerFxn8__C;

/* Module__startupDoneFxn */
typedef xdc_Bool (*CT__xdc_runtime_System_Module__startupDoneFxn)(void);
__extern __FAR__ const CT__xdc_runtime_System_Module__startupDoneFxn xdc_runtime_System_Module__startupDoneFxn__C;

/* Object__count */
typedef xdc_Int CT__xdc_runtime_System_Object__count;
__extern __FAR__ const CT__xdc_runtime_System_Object__count xdc_runtime_System_Object__count__C;

/* Object__heap */
typedef xdc_runtime_IHeap_Handle CT__xdc_runtime_System_Object__heap;
__extern __FAR__ const CT__xdc_runtime_System_Object__heap xdc_runtime_System_Object__heap__C;

/* Object__sizeof */
typedef xdc_SizeT CT__xdc_runtime_System_Object__sizeof;
__extern __FAR__ const CT__xdc_runtime_System_Object__sizeof xdc_runtime_System_Object__sizeof__C;

/* Object__table */
typedef xdc_Ptr CT__xdc_runtime_System_Object__table;
__extern __FAR__ const CT__xdc_runtime_System_Object__table xdc_runtime_System_Object__table__C;

/* A_cannotFitIntoArg */
#define xdc_runtime_System_A_cannotFitIntoArg (xdc_runtime_System_A_cannotFitIntoArg__C)
typedef xdc_runtime_Assert_Id CT__xdc_runtime_System_A_cannotFitIntoArg;
__extern __FAR__ const CT__xdc_runtime_System_A_cannotFitIntoArg xdc_runtime_System_A_cannotFitIntoArg__C;

/* maxAtexitHandlers */
#ifdef xdc_runtime_System_maxAtexitHandlers__D
#define xdc_runtime_System_maxAtexitHandlers (xdc_runtime_System_maxAtexitHandlers__D)
#else
#define xdc_runtime_System_maxAtexitHandlers (xdc_runtime_System_maxAtexitHandlers__C)
typedef xdc_Int CT__xdc_runtime_System_maxAtexitHandlers;
__extern __FAR__ const CT__xdc_runtime_System_maxAtexitHandlers xdc_runtime_System_maxAtexitHandlers__C;
#endif

/* abortFxn */
#define xdc_runtime_System_abortFxn (xdc_runtime_System_abortFxn__C)
typedef xdc_runtime_System_AbortFxn CT__xdc_runtime_System_abortFxn;
__extern __FAR__ const CT__xdc_runtime_System_abortFxn xdc_runtime_System_abortFxn__C;

/* exitFxn */
#define xdc_runtime_System_exitFxn (xdc_runtime_System_exitFxn__C)
typedef xdc_runtime_System_ExitFxn CT__xdc_runtime_System_exitFxn;
__extern __FAR__ const CT__xdc_runtime_System_exitFxn xdc_runtime_System_exitFxn__C;

/* extendFxn */
#define xdc_runtime_System_extendFxn (xdc_runtime_System_extendFxn__C)
typedef xdc_runtime_System_ExtendFxn CT__xdc_runtime_System_extendFxn;
__extern __FAR__ const CT__xdc_runtime_System_extendFxn xdc_runtime_System_extendFxn__C;


/*
 * ======== FUNCTION DECLARATIONS ========
 */

/* Module_startup */
#define xdc_runtime_System_Module_startup xdc_runtime_System_Module_startup__E
xdc__CODESECT(xdc_runtime_System_Module_startup__E, "xdc_runtime_System_Module_startup")
__extern xdc_Int xdc_runtime_System_Module_startup__E( xdc_Int state );
xdc__CODESECT(xdc_runtime_System_Module_startup__F, "xdc_runtime_System_Module_startup")
__extern xdc_Int xdc_runtime_System_Module_startup__F( xdc_Int state );

/* Module__startupDone__S */
xdc__CODESECT(xdc_runtime_System_Module__startupDone__S, "xdc_runtime_System_Module__startupDone__S")
__extern xdc_Bool xdc_runtime_System_Module__startupDone__S( void );

/* abort__E */
#define xdc_runtime_System_abort xdc_runtime_System_abort__E
xdc__CODESECT(xdc_runtime_System_abort__E, "xdc_runtime_System_abort")
__extern xdc_Void xdc_runtime_System_abort__E( xdc_CString str );

/* abortStd__E */
#define xdc_runtime_System_abortStd xdc_runtime_System_abortStd__E
xdc__CODESECT(xdc_runtime_System_abortStd__E, "xdc_runtime_System_abortStd")
__extern xdc_Void xdc_runtime_System_abortStd__E( void );

/* abortSpin__E */
#define xdc_runtime_System_abortSpin xdc_runtime_System_abortSpin__E
xdc__CODESECT(xdc_runtime_System_abortSpin__E, "xdc_runtime_System_abortSpin")
__extern xdc_Void xdc_runtime_System_abortSpin__E( void );

/* atexit__E */
#define xdc_runtime_System_atexit xdc_runtime_System_atexit__E
xdc__CODESECT(xdc_runtime_System_atexit__E, "xdc_runtime_System_atexit")
__extern xdc_Bool xdc_runtime_System_atexit__E( xdc_runtime_System_AtexitHandler handler );

/* exit__E */
#define xdc_runtime_System_exit xdc_runtime_System_exit__E
xdc__CODESECT(xdc_runtime_System_exit__E, "xdc_runtime_System_exit")
__extern xdc_Void xdc_runtime_System_exit__E( xdc_Int stat );

/* exitStd__E */
#define xdc_runtime_System_exitStd xdc_runtime_System_exitStd__E
xdc__CODESECT(xdc_runtime_System_exitStd__E, "xdc_runtime_System_exitStd")
__extern xdc_Void xdc_runtime_System_exitStd__E( xdc_Int stat );

/* exitSpin__E */
#define xdc_runtime_System_exitSpin xdc_runtime_System_exitSpin__E
xdc__CODESECT(xdc_runtime_System_exitSpin__E, "xdc_runtime_System_exitSpin")
__extern xdc_Void xdc_runtime_System_exitSpin__E( xdc_Int stat );

/* processAtExit__E */
#define xdc_runtime_System_processAtExit xdc_runtime_System_processAtExit__E
xdc__CODESECT(xdc_runtime_System_processAtExit__E, "xdc_runtime_System_processAtExit")
__extern xdc_Void xdc_runtime_System_processAtExit__E( xdc_Int stat );

/* putch__E */
#define xdc_runtime_System_putch xdc_runtime_System_putch__E
xdc__CODESECT(xdc_runtime_System_putch__E, "xdc_runtime_System_putch")
__extern xdc_Void xdc_runtime_System_putch__E( xdc_Char ch );

/* flush__E */
#define xdc_runtime_System_flush xdc_runtime_System_flush__E
xdc__CODESECT(xdc_runtime_System_flush__E, "xdc_runtime_System_flush")
__extern xdc_Void xdc_runtime_System_flush__E( void );

/* printf__E */
#define xdc_runtime_System_printf xdc_runtime_System_printf__E
xdc__CODESECT(xdc_runtime_System_printf__E, "xdc_runtime_System_printf")
__extern xdc_Int xdc_runtime_System_printf__E( xdc_CString fmt, ... );
xdc__CODESECT(xdc_runtime_System_printf_va__E, "xdc_runtime_System_printf")
__extern xdc_Int xdc_runtime_System_printf_va__E( xdc_CString fmt, va_list _va );
xdc__CODESECT(xdc_runtime_System_printf_va__F, "xdc_runtime_System_printf")
__extern xdc_Int xdc_runtime_System_printf_va__F( xdc_CString fmt, va_list _va );

/* aprintf__E */
#define xdc_runtime_System_aprintf xdc_runtime_System_aprintf__E
xdc__CODESECT(xdc_runtime_System_aprintf__E, "xdc_runtime_System_aprintf")
__extern xdc_Int xdc_runtime_System_aprintf__E( xdc_CString fmt, ... );
xdc__CODESECT(xdc_runtime_System_aprintf_va__E, "xdc_runtime_System_aprintf")
__extern xdc_Int xdc_runtime_System_aprintf_va__E( xdc_CString fmt, va_list _va );
xdc__CODESECT(xdc_runtime_System_aprintf_va__F, "xdc_runtime_System_aprintf")
__extern xdc_Int xdc_runtime_System_aprintf_va__F( xdc_CString fmt, va_list _va );

/* sprintf__E */
#define xdc_runtime_System_sprintf xdc_runtime_System_sprintf__E
xdc__CODESECT(xdc_runtime_System_sprintf__E, "xdc_runtime_System_sprintf")
__extern xdc_Int xdc_runtime_System_sprintf__E( xdc_Char buf[], xdc_CString fmt, ... );
xdc__CODESECT(xdc_runtime_System_sprintf_va__E, "xdc_runtime_System_sprintf")
__extern xdc_Int xdc_runtime_System_sprintf_va__E( xdc_Char buf[], xdc_CString fmt, va_list _va );
xdc__CODESECT(xdc_runtime_System_sprintf_va__F, "xdc_runtime_System_sprintf")
__extern xdc_Int xdc_runtime_System_sprintf_va__F( xdc_Char buf[], xdc_CString fmt, va_list _va );

/* asprintf__E */
#define xdc_runtime_System_asprintf xdc_runtime_System_asprintf__E
xdc__CODESECT(xdc_runtime_System_asprintf__E, "xdc_runtime_System_asprintf")
__extern xdc_Int xdc_runtime_System_asprintf__E( xdc_Char buf[], xdc_CString fmt, ... );
xdc__CODESECT(xdc_runtime_System_asprintf_va__E, "xdc_runtime_System_asprintf")
__extern xdc_Int xdc_runtime_System_asprintf_va__E( xdc_Char buf[], xdc_CString fmt, va_list _va );
xdc__CODESECT(xdc_runtime_System_asprintf_va__F, "xdc_runtime_System_asprintf")
__extern xdc_Int xdc_runtime_System_asprintf_va__F( xdc_Char buf[], xdc_CString fmt, va_list _va );

/* vprintf__E */
#define xdc_runtime_System_vprintf xdc_runtime_System_vprintf__E
xdc__CODESECT(xdc_runtime_System_vprintf__E, "xdc_runtime_System_vprintf")
__extern xdc_Int xdc_runtime_System_vprintf__E( xdc_CString fmt, xdc_VaList va );

/* avprintf__E */
#define xdc_runtime_System_avprintf xdc_runtime_System_avprintf__E
xdc__CODESECT(xdc_runtime_System_avprintf__E, "xdc_runtime_System_avprintf")
__extern xdc_Int xdc_runtime_System_avprintf__E( xdc_CString fmt, xdc_VaList va );

/* vsprintf__E */
#define xdc_runtime_System_vsprintf xdc_runtime_System_vsprintf__E
xdc__CODESECT(xdc_runtime_System_vsprintf__E, "xdc_runtime_System_vsprintf")
__extern xdc_Int xdc_runtime_System_vsprintf__E( xdc_Char buf[], xdc_CString fmt, xdc_VaList va );

/* avsprintf__E */
#define xdc_runtime_System_avsprintf xdc_runtime_System_avsprintf__E
xdc__CODESECT(xdc_runtime_System_avsprintf__E, "xdc_runtime_System_avsprintf")
__extern xdc_Int xdc_runtime_System_avsprintf__E( xdc_Char buf[], xdc_CString fmt, xdc_VaList va );

/* snprintf__E */
#define xdc_runtime_System_snprintf xdc_runtime_System_snprintf__E
xdc__CODESECT(xdc_runtime_System_snprintf__E, "xdc_runtime_System_snprintf")
__extern xdc_Int xdc_runtime_System_snprintf__E( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, ... );
xdc__CODESECT(xdc_runtime_System_snprintf_va__E, "xdc_runtime_System_snprintf")
__extern xdc_Int xdc_runtime_System_snprintf_va__E( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, va_list _va );
xdc__CODESECT(xdc_runtime_System_snprintf_va__F, "xdc_runtime_System_snprintf")
__extern xdc_Int xdc_runtime_System_snprintf_va__F( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, va_list _va );

/* vsnprintf__E */
#define xdc_runtime_System_vsnprintf xdc_runtime_System_vsnprintf__E
xdc__CODESECT(xdc_runtime_System_vsnprintf__E, "xdc_runtime_System_vsnprintf")
__extern xdc_Int xdc_runtime_System_vsnprintf__E( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, xdc_VaList va );

/* printfExtend__I */
#define xdc_runtime_System_printfExtend xdc_runtime_System_printfExtend__I
xdc__CODESECT(xdc_runtime_System_printfExtend__I, "xdc_runtime_System_printfExtend")
__extern xdc_Int xdc_runtime_System_printfExtend__I( xdc_Char **bufp, xdc_CString *fmt, xdc_VaList *va, xdc_runtime_System_ParseData *parse );

/* doPrint__I */
#define xdc_runtime_System_doPrint xdc_runtime_System_doPrint__I
xdc__CODESECT(xdc_runtime_System_doPrint__I, "xdc_runtime_System_doPrint")
__extern xdc_Int xdc_runtime_System_doPrint__I( xdc_Char buf[], xdc_SizeT n, xdc_CString fmt, xdc_VaList *pva, xdc_Bool aFlag );

/* lastFxn__I */
#define xdc_runtime_System_lastFxn xdc_runtime_System_lastFxn__I
xdc__CODESECT(xdc_runtime_System_lastFxn__I, "xdc_runtime_System_lastFxn")
__extern xdc_Void xdc_runtime_System_lastFxn__I( void );

/* putchar__I */
#define xdc_runtime_System_putchar xdc_runtime_System_putchar__I
xdc__CODESECT(xdc_runtime_System_putchar__I, "xdc_runtime_System_putchar")
__extern xdc_Void xdc_runtime_System_putchar__I( xdc_Char **bufp, xdc_Char ch, xdc_SizeT *n );

/* rtsExit__I */
#define xdc_runtime_System_rtsExit xdc_runtime_System_rtsExit__I
xdc__CODESECT(xdc_runtime_System_rtsExit__I, "xdc_runtime_System_rtsExit")
__extern xdc_Void xdc_runtime_System_rtsExit__I( void );

/* atexitDone__I */
#define xdc_runtime_System_atexitDone xdc_runtime_System_atexitDone__I
xdc__CODESECT(xdc_runtime_System_atexitDone__I, "xdc_runtime_System_atexitDone")
__extern xdc_Bool xdc_runtime_System_atexitDone__I( void );


/*
 * ======== SYSTEM FUNCTIONS ========
 */

/* Module_startupDone */
#define xdc_runtime_System_Module_startupDone() xdc_runtime_System_Module__startupDone__S()

/* Object_heap */
#define xdc_runtime_System_Object_heap() xdc_runtime_System_Object__heap__C

/* Module_heap */
#define xdc_runtime_System_Module_heap() xdc_runtime_System_Object__heap__C

/* Module_id */
static inline CT__xdc_runtime_System_Module__id xdc_runtime_System_Module_id( void ) 
{
    return xdc_runtime_System_Module__id__C;
}

/* Module_hasMask */
static inline xdc_Bool xdc_runtime_System_Module_hasMask( void ) 
{
    return xdc_runtime_System_Module__diagsMask__C != NULL;
}

/* Module_getMask */
static inline xdc_Bits16 xdc_runtime_System_Module_getMask( void ) 
{
    return xdc_runtime_System_Module__diagsMask__C != NULL ? *xdc_runtime_System_Module__diagsMask__C : 0;
}

/* Module_setMask */
static inline xdc_Void xdc_runtime_System_Module_setMask( xdc_Bits16 mask ) 
{
    if (xdc_runtime_System_Module__diagsMask__C != NULL) *xdc_runtime_System_Module__diagsMask__C = mask;
}


/*
 * ======== EPILOGUE ========
 */

#ifdef xdc_runtime_System__top__
#undef __nested__
#endif

#endif /* xdc_runtime_System__include */


/*
 * ======== STATE STRUCTURES ========
 */

#if defined(__config__) || (!defined(__nested__) && defined(xdc_runtime_System__internalaccess))

#ifndef xdc_runtime_System__include_state
#define xdc_runtime_System__include_state

/* Module_State */
struct xdc_runtime_System_Module_State {
    __TA_xdc_runtime_System_Module_State__atexitHandlers atexitHandlers;
    xdc_Int numAtexitHandlers;
};

/* Module__state__V */
extern struct xdc_runtime_System_Module_State__ xdc_runtime_System_Module__state__V;

#endif /* xdc_runtime_System__include_state */

#endif


/*
 * ======== PREFIX ALIASES ========
 */

#if !defined(__nested__) && !defined(xdc_runtime_System__nolocalnames)

#ifndef xdc_runtime_System__localnames__done
#define xdc_runtime_System__localnames__done

/* module prefix */
#define System_AtexitHandler xdc_runtime_System_AtexitHandler
#define System_STATUS_UNKNOWN xdc_runtime_System_STATUS_UNKNOWN
#define System_AbortFxn xdc_runtime_System_AbortFxn
#define System_ExitFxn xdc_runtime_System_ExitFxn
#define System_ParseData xdc_runtime_System_ParseData
#define System_ExtendFxn xdc_runtime_System_ExtendFxn
#define System_Module_State xdc_runtime_System_Module_State
#define System_A_cannotFitIntoArg xdc_runtime_System_A_cannotFitIntoArg
#define System_maxAtexitHandlers xdc_runtime_System_maxAtexitHandlers
#define System_abortFxn xdc_runtime_System_abortFxn
#define System_exitFxn xdc_runtime_System_exitFxn
#define System_extendFxn xdc_runtime_System_extendFxn
#define System_abort xdc_runtime_System_abort
#define System_abortStd xdc_runtime_System_abortStd
#define System_abortSpin xdc_runtime_System_abortSpin
#define System_atexit xdc_runtime_System_atexit
#define System_exit xdc_runtime_System_exit
#define System_exitStd xdc_runtime_System_exitStd
#define System_exitSpin xdc_runtime_System_exitSpin
#define System_processAtExit xdc_runtime_System_processAtExit
#define System_putch xdc_runtime_System_putch
#define System_flush xdc_runtime_System_flush
#define System_printf xdc_runtime_System_printf
#define System_printf_va xdc_runtime_System_printf_va
#define System_aprintf xdc_runtime_System_aprintf
#define System_aprintf_va xdc_runtime_System_aprintf_va
#define System_sprintf xdc_runtime_System_sprintf
#define System_sprintf_va xdc_runtime_System_sprintf_va
#define System_asprintf xdc_runtime_System_asprintf
#define System_asprintf_va xdc_runtime_System_asprintf_va
#define System_vprintf xdc_runtime_System_vprintf
#define System_avprintf xdc_runtime_System_avprintf
#define System_vsprintf xdc_runtime_System_vsprintf
#define System_avsprintf xdc_runtime_System_avsprintf
#define System_snprintf xdc_runtime_System_snprintf
#define System_snprintf_va xdc_runtime_System_snprintf_va
#define System_vsnprintf xdc_runtime_System_vsnprintf
#define System_Module_name xdc_runtime_System_Module_name
#define System_Module_id xdc_runtime_System_Module_id
#define System_Module_startup xdc_runtime_System_Module_startup
#define System_Module_startupDone xdc_runtime_System_Module_startupDone
#define System_Module_hasMask xdc_runtime_System_Module_hasMask
#define System_Module_getMask xdc_runtime_System_Module_getMask
#define System_Module_setMask xdc_runtime_System_Module_setMask
#define System_Object_heap xdc_runtime_System_Object_heap
#define System_Module_heap xdc_runtime_System_Module_heap

/* proxies */
#include <xdc/runtime/package/System_SupportProxy.h>

/* proxies */
#include <xdc/runtime/package/System_Module_GateProxy.h>

#endif /* xdc_runtime_System__localnames__done */
#endif
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:13; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

