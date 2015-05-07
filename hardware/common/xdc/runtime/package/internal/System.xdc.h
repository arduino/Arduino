/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef xdc_runtime_System__INTERNAL__
#define xdc_runtime_System__INTERNAL__

#ifndef xdc_runtime_System__internalaccess
#define xdc_runtime_System__internalaccess
#endif

#include <xdc/runtime/System.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* abort */
#undef xdc_runtime_System_abort
#define xdc_runtime_System_abort xdc_runtime_System_abort__E

/* abortStd */
#undef xdc_runtime_System_abortStd
#define xdc_runtime_System_abortStd xdc_runtime_System_abortStd__E

/* abortSpin */
#undef xdc_runtime_System_abortSpin
#define xdc_runtime_System_abortSpin xdc_runtime_System_abortSpin__E

/* atexit */
#undef xdc_runtime_System_atexit
#define xdc_runtime_System_atexit xdc_runtime_System_atexit__E

/* exit */
#undef xdc_runtime_System_exit
#define xdc_runtime_System_exit xdc_runtime_System_exit__E

/* exitStd */
#undef xdc_runtime_System_exitStd
#define xdc_runtime_System_exitStd xdc_runtime_System_exitStd__E

/* exitSpin */
#undef xdc_runtime_System_exitSpin
#define xdc_runtime_System_exitSpin xdc_runtime_System_exitSpin__E

/* processAtExit */
#undef xdc_runtime_System_processAtExit
#define xdc_runtime_System_processAtExit xdc_runtime_System_processAtExit__E

/* putch */
#undef xdc_runtime_System_putch
#define xdc_runtime_System_putch xdc_runtime_System_putch__E

/* flush */
#undef xdc_runtime_System_flush
#define xdc_runtime_System_flush xdc_runtime_System_flush__E

/* printf */
#undef xdc_runtime_System_printf_va
#define xdc_runtime_System_printf_va xdc_runtime_System_printf_va__F

/* aprintf */
#undef xdc_runtime_System_aprintf_va
#define xdc_runtime_System_aprintf_va xdc_runtime_System_aprintf_va__F

/* sprintf */
#undef xdc_runtime_System_sprintf_va
#define xdc_runtime_System_sprintf_va xdc_runtime_System_sprintf_va__F

/* asprintf */
#undef xdc_runtime_System_asprintf_va
#define xdc_runtime_System_asprintf_va xdc_runtime_System_asprintf_va__F

/* vprintf */
#undef xdc_runtime_System_vprintf
#define xdc_runtime_System_vprintf xdc_runtime_System_vprintf__E

/* avprintf */
#undef xdc_runtime_System_avprintf
#define xdc_runtime_System_avprintf xdc_runtime_System_avprintf__E

/* vsprintf */
#undef xdc_runtime_System_vsprintf
#define xdc_runtime_System_vsprintf xdc_runtime_System_vsprintf__E

/* avsprintf */
#undef xdc_runtime_System_avsprintf
#define xdc_runtime_System_avsprintf xdc_runtime_System_avsprintf__E

/* snprintf */
#undef xdc_runtime_System_snprintf_va
#define xdc_runtime_System_snprintf_va xdc_runtime_System_snprintf_va__F

/* vsnprintf */
#undef xdc_runtime_System_vsnprintf
#define xdc_runtime_System_vsnprintf xdc_runtime_System_vsnprintf__E

/* printfExtend */
#define System_printfExtend xdc_runtime_System_printfExtend__I

/* doPrint */
#define System_doPrint xdc_runtime_System_doPrint__I

/* lastFxn */
#define System_lastFxn xdc_runtime_System_lastFxn__I

/* putchar */
#define System_putchar xdc_runtime_System_putchar__I

/* rtsExit */
#define System_rtsExit xdc_runtime_System_rtsExit__I

/* atexitDone */
#define System_atexitDone xdc_runtime_System_atexitDone__I

/* Module_startup */
#undef xdc_runtime_System_Module_startup
#define xdc_runtime_System_Module_startup xdc_runtime_System_Module_startup__E

/* Instance_init */
#undef xdc_runtime_System_Instance_init
#define xdc_runtime_System_Instance_init xdc_runtime_System_Instance_init__E

/* Instance_finalize */
#undef xdc_runtime_System_Instance_finalize
#define xdc_runtime_System_Instance_finalize xdc_runtime_System_Instance_finalize__E

/* module */
#define System_module ((xdc_runtime_System_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_System_Module__state__V)))
#if !defined(__cplusplus) || !defined(xdc_runtime_System__cplusplus)
#define module ((xdc_runtime_System_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_System_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_System_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_System_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_System_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_System_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_System_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_System_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_System_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_System_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_System_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_System_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_System_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_System_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_System_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_System_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_System_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_System_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_System_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_System_Module_GateProxy_query


#endif /* xdc_runtime_System__INTERNAL____ */
