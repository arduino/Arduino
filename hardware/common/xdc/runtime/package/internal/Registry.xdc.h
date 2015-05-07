/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef xdc_runtime_Registry__INTERNAL__
#define xdc_runtime_Registry__INTERNAL__

#ifndef xdc_runtime_Registry__internalaccess
#define xdc_runtime_Registry__internalaccess
#endif

#include <xdc/runtime/Registry.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* addModule */
#undef xdc_runtime_Registry_addModule
#define xdc_runtime_Registry_addModule xdc_runtime_Registry_addModule__E

/* findByName */
#undef xdc_runtime_Registry_findByName
#define xdc_runtime_Registry_findByName xdc_runtime_Registry_findByName__E

/* findByNamePattern */
#undef xdc_runtime_Registry_findByNamePattern
#define xdc_runtime_Registry_findByNamePattern xdc_runtime_Registry_findByNamePattern__E

/* findById */
#undef xdc_runtime_Registry_findById
#define xdc_runtime_Registry_findById xdc_runtime_Registry_findById__E

/* getMask */
#undef xdc_runtime_Registry_getMask
#define xdc_runtime_Registry_getMask xdc_runtime_Registry_getMask__E

/* isMember */
#undef xdc_runtime_Registry_isMember
#define xdc_runtime_Registry_isMember xdc_runtime_Registry_isMember__E

/* getNextModule */
#undef xdc_runtime_Registry_getNextModule
#define xdc_runtime_Registry_getNextModule xdc_runtime_Registry_getNextModule__E

/* getModuleName */
#undef xdc_runtime_Registry_getModuleName
#define xdc_runtime_Registry_getModuleName xdc_runtime_Registry_getModuleName__E

/* getModuleId */
#undef xdc_runtime_Registry_getModuleId
#define xdc_runtime_Registry_getModuleId xdc_runtime_Registry_getModuleId__E

/* findByNameInList */
#define Registry_findByNameInList xdc_runtime_Registry_findByNameInList__I

/* newModule */
#define Registry_newModule xdc_runtime_Registry_newModule__I

/* matchPattern */
#define Registry_matchPattern xdc_runtime_Registry_matchPattern__I

/* Module_startup */
#undef xdc_runtime_Registry_Module_startup
#define xdc_runtime_Registry_Module_startup xdc_runtime_Registry_Module_startup__E

/* Instance_init */
#undef xdc_runtime_Registry_Instance_init
#define xdc_runtime_Registry_Instance_init xdc_runtime_Registry_Instance_init__E

/* Instance_finalize */
#undef xdc_runtime_Registry_Instance_finalize
#define xdc_runtime_Registry_Instance_finalize xdc_runtime_Registry_Instance_finalize__E

/* module */
#define Registry_module ((xdc_runtime_Registry_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_Registry_Module__state__V)))
#if !defined(__cplusplus) || !defined(xdc_runtime_Registry__cplusplus)
#define module ((xdc_runtime_Registry_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_Registry_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Registry_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Registry_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Registry_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Registry_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Registry_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Registry_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Registry_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Registry_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Registry_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Registry_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Registry_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Registry_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Registry_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Registry_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Registry_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Registry_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Registry_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Registry_Module_GateProxy_query


#endif /* xdc_runtime_Registry__INTERNAL____ */
