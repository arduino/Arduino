/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef xdc_runtime_Error__INTERNAL__
#define xdc_runtime_Error__INTERNAL__

#ifndef xdc_runtime_Error__internalaccess
#define xdc_runtime_Error__internalaccess
#endif

#include <xdc/runtime/Error.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* check */
#undef xdc_runtime_Error_check
#define xdc_runtime_Error_check xdc_runtime_Error_check__E

/* getData */
#undef xdc_runtime_Error_getData
#define xdc_runtime_Error_getData xdc_runtime_Error_getData__E

/* getCode */
#undef xdc_runtime_Error_getCode
#define xdc_runtime_Error_getCode xdc_runtime_Error_getCode__E

/* getId */
#undef xdc_runtime_Error_getId
#define xdc_runtime_Error_getId xdc_runtime_Error_getId__E

/* getMsg */
#undef xdc_runtime_Error_getMsg
#define xdc_runtime_Error_getMsg xdc_runtime_Error_getMsg__E

/* getSite */
#undef xdc_runtime_Error_getSite
#define xdc_runtime_Error_getSite xdc_runtime_Error_getSite__E

/* init */
#undef xdc_runtime_Error_init
#define xdc_runtime_Error_init xdc_runtime_Error_init__E

/* print */
#undef xdc_runtime_Error_print
#define xdc_runtime_Error_print xdc_runtime_Error_print__E

/* policyDefault */
#undef xdc_runtime_Error_policyDefault
#define xdc_runtime_Error_policyDefault xdc_runtime_Error_policyDefault__E

/* policySpin */
#undef xdc_runtime_Error_policySpin
#define xdc_runtime_Error_policySpin xdc_runtime_Error_policySpin__E

/* raiseX */
#undef xdc_runtime_Error_raiseX
#define xdc_runtime_Error_raiseX xdc_runtime_Error_raiseX__E

/* setX */
#undef xdc_runtime_Error_setX
#define xdc_runtime_Error_setX xdc_runtime_Error_setX__E

/* Module_startup */
#undef xdc_runtime_Error_Module_startup
#define xdc_runtime_Error_Module_startup xdc_runtime_Error_Module_startup__E

/* Instance_init */
#undef xdc_runtime_Error_Instance_init
#define xdc_runtime_Error_Instance_init xdc_runtime_Error_Instance_init__E

/* Instance_finalize */
#undef xdc_runtime_Error_Instance_finalize
#define xdc_runtime_Error_Instance_finalize xdc_runtime_Error_Instance_finalize__E

/* module */
#define Error_module ((xdc_runtime_Error_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_Error_Module__state__V)))
#if !defined(__cplusplus) || !defined(xdc_runtime_Error__cplusplus)
#define module ((xdc_runtime_Error_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_Error_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Error_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Error_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Error_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Error_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Error_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Error_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Error_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Error_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Error_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Error_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Error_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Error_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Error_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Error_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Error_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Error_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Error_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Error_Module_GateProxy_query


#endif /* xdc_runtime_Error__INTERNAL____ */
