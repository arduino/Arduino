/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef xdc_runtime_knl_Thread_Proxy__INTERNAL__
#define xdc_runtime_knl_Thread_Proxy__INTERNAL__

#ifndef xdc_runtime_knl_Thread_Proxy__internalaccess
#define xdc_runtime_knl_Thread_Proxy__internalaccess
#endif

#include <xdc/runtime/knl/Thread_Proxy.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* self */
#undef xdc_runtime_knl_Thread_Proxy_self
#define xdc_runtime_knl_Thread_Proxy_self xdc_runtime_knl_Thread_Proxy_self__E

/* start */
#undef xdc_runtime_knl_Thread_Proxy_start
#define xdc_runtime_knl_Thread_Proxy_start xdc_runtime_knl_Thread_Proxy_start__E

/* yield */
#undef xdc_runtime_knl_Thread_Proxy_yield
#define xdc_runtime_knl_Thread_Proxy_yield xdc_runtime_knl_Thread_Proxy_yield__E

/* compareOsPriorities */
#undef xdc_runtime_knl_Thread_Proxy_compareOsPriorities
#define xdc_runtime_knl_Thread_Proxy_compareOsPriorities xdc_runtime_knl_Thread_Proxy_compareOsPriorities__E

/* sleep */
#undef xdc_runtime_knl_Thread_Proxy_sleep
#define xdc_runtime_knl_Thread_Proxy_sleep xdc_runtime_knl_Thread_Proxy_sleep__E

/* join */
#undef xdc_runtime_knl_Thread_Proxy_join
#define xdc_runtime_knl_Thread_Proxy_join xdc_runtime_knl_Thread_Proxy_join__E

/* getPriority */
#undef xdc_runtime_knl_Thread_Proxy_getPriority
#define xdc_runtime_knl_Thread_Proxy_getPriority xdc_runtime_knl_Thread_Proxy_getPriority__E

/* setPriority */
#undef xdc_runtime_knl_Thread_Proxy_setPriority
#define xdc_runtime_knl_Thread_Proxy_setPriority xdc_runtime_knl_Thread_Proxy_setPriority__E

/* getOsPriority */
#undef xdc_runtime_knl_Thread_Proxy_getOsPriority
#define xdc_runtime_knl_Thread_Proxy_getOsPriority xdc_runtime_knl_Thread_Proxy_getOsPriority__E

/* setOsPriority */
#undef xdc_runtime_knl_Thread_Proxy_setOsPriority
#define xdc_runtime_knl_Thread_Proxy_setOsPriority xdc_runtime_knl_Thread_Proxy_setOsPriority__E

/* getOsHandle */
#undef xdc_runtime_knl_Thread_Proxy_getOsHandle
#define xdc_runtime_knl_Thread_Proxy_getOsHandle xdc_runtime_knl_Thread_Proxy_getOsHandle__E

/* getTls */
#undef xdc_runtime_knl_Thread_Proxy_getTls
#define xdc_runtime_knl_Thread_Proxy_getTls xdc_runtime_knl_Thread_Proxy_getTls__E

/* setTls */
#undef xdc_runtime_knl_Thread_Proxy_setTls
#define xdc_runtime_knl_Thread_Proxy_setTls xdc_runtime_knl_Thread_Proxy_setTls__E

/* stat */
#undef xdc_runtime_knl_Thread_Proxy_stat
#define xdc_runtime_knl_Thread_Proxy_stat xdc_runtime_knl_Thread_Proxy_stat__E

/* Module_startup */
#undef xdc_runtime_knl_Thread_Proxy_Module_startup
#define xdc_runtime_knl_Thread_Proxy_Module_startup xdc_runtime_knl_Thread_Proxy_Module_startup__E

/* Instance_init */
#undef xdc_runtime_knl_Thread_Proxy_Instance_init
#define xdc_runtime_knl_Thread_Proxy_Instance_init xdc_runtime_knl_Thread_Proxy_Instance_init__E

/* Instance_finalize */
#undef xdc_runtime_knl_Thread_Proxy_Instance_finalize
#define xdc_runtime_knl_Thread_Proxy_Instance_finalize xdc_runtime_knl_Thread_Proxy_Instance_finalize__E

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_knl_Thread_Proxy_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_knl_Thread_Proxy_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_knl_Thread_Proxy_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_knl_Thread_Proxy_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_knl_Thread_Proxy_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_knl_Thread_Proxy_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_knl_Thread_Proxy_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_knl_Thread_Proxy_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_knl_Thread_Proxy_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_knl_Thread_Proxy_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_knl_Thread_Proxy_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_knl_Thread_Proxy_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_knl_Thread_Proxy_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_knl_Thread_Proxy_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_knl_Thread_Proxy_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_knl_Thread_Proxy_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_knl_Thread_Proxy_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_knl_Thread_Proxy_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_xdc.runtime.knl.Thread_Proxy"
typedef char xdc_runtime_knl_Thread_Proxy_Object__sizingError[sizeof(xdc_runtime_knl_Thread_Proxy_Object) > sizeof(xdc_runtime_knl_Thread_Proxy_Struct) ? -1 : 1];


#endif /* xdc_runtime_knl_Thread_Proxy__INTERNAL____ */
