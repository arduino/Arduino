/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef xdc_runtime_LoggerCallback__INTERNAL__
#define xdc_runtime_LoggerCallback__INTERNAL__

#ifndef xdc_runtime_LoggerCallback__internalaccess
#define xdc_runtime_LoggerCallback__internalaccess
#endif

#include <xdc/runtime/LoggerCallback.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* enable */
#undef xdc_runtime_LoggerCallback_enable
#define xdc_runtime_LoggerCallback_enable xdc_runtime_LoggerCallback_enable__E

/* disable */
#undef xdc_runtime_LoggerCallback_disable
#define xdc_runtime_LoggerCallback_disable xdc_runtime_LoggerCallback_disable__E

/* write0 */
#undef xdc_runtime_LoggerCallback_write0
#define xdc_runtime_LoggerCallback_write0 xdc_runtime_LoggerCallback_write0__E

/* write1 */
#undef xdc_runtime_LoggerCallback_write1
#define xdc_runtime_LoggerCallback_write1 xdc_runtime_LoggerCallback_write1__E

/* write2 */
#undef xdc_runtime_LoggerCallback_write2
#define xdc_runtime_LoggerCallback_write2 xdc_runtime_LoggerCallback_write2__E

/* write4 */
#undef xdc_runtime_LoggerCallback_write4
#define xdc_runtime_LoggerCallback_write4 xdc_runtime_LoggerCallback_write4__E

/* write8 */
#undef xdc_runtime_LoggerCallback_write8
#define xdc_runtime_LoggerCallback_write8 xdc_runtime_LoggerCallback_write8__E

/* Module_startup */
#undef xdc_runtime_LoggerCallback_Module_startup
#define xdc_runtime_LoggerCallback_Module_startup xdc_runtime_LoggerCallback_Module_startup__E

/* Instance_init */
#undef xdc_runtime_LoggerCallback_Instance_init
#define xdc_runtime_LoggerCallback_Instance_init xdc_runtime_LoggerCallback_Instance_init__E

/* Instance_finalize */
#undef xdc_runtime_LoggerCallback_Instance_finalize
#define xdc_runtime_LoggerCallback_Instance_finalize xdc_runtime_LoggerCallback_Instance_finalize__E

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_LoggerCallback_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_LoggerCallback_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_LoggerCallback_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_LoggerCallback_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_LoggerCallback_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_LoggerCallback_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_LoggerCallback_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_LoggerCallback_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_LoggerCallback_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_LoggerCallback_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_LoggerCallback_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_LoggerCallback_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_LoggerCallback_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_LoggerCallback_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_LoggerCallback_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_LoggerCallback_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_LoggerCallback_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_LoggerCallback_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_xdc.runtime.LoggerCallback"
typedef char xdc_runtime_LoggerCallback_Object__sizingError[sizeof(xdc_runtime_LoggerCallback_Object) > sizeof(xdc_runtime_LoggerCallback_Struct) ? -1 : 1];


#endif /* xdc_runtime_LoggerCallback__INTERNAL____ */
