/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef xdc_runtime_Memory__INTERNAL__
#define xdc_runtime_Memory__INTERNAL__

#ifndef xdc_runtime_Memory__internalaccess
#define xdc_runtime_Memory__internalaccess
#endif

#include <xdc/runtime/Memory.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* alloc */
#undef xdc_runtime_Memory_alloc
#define xdc_runtime_Memory_alloc xdc_runtime_Memory_alloc__E

/* calloc */
#undef xdc_runtime_Memory_calloc
#define xdc_runtime_Memory_calloc xdc_runtime_Memory_calloc__E

/* free */
#undef xdc_runtime_Memory_free
#define xdc_runtime_Memory_free xdc_runtime_Memory_free__E

/* getStats */
#undef xdc_runtime_Memory_getStats
#define xdc_runtime_Memory_getStats xdc_runtime_Memory_getStats__E

/* query */
#undef xdc_runtime_Memory_query
#define xdc_runtime_Memory_query xdc_runtime_Memory_query__E

/* getMaxDefaultTypeAlign */
#undef xdc_runtime_Memory_getMaxDefaultTypeAlign
#define xdc_runtime_Memory_getMaxDefaultTypeAlign xdc_runtime_Memory_getMaxDefaultTypeAlign__E

/* valloc */
#undef xdc_runtime_Memory_valloc
#define xdc_runtime_Memory_valloc xdc_runtime_Memory_valloc__E

/* Module_startup */
#undef xdc_runtime_Memory_Module_startup
#define xdc_runtime_Memory_Module_startup xdc_runtime_Memory_Module_startup__E

/* Instance_init */
#undef xdc_runtime_Memory_Instance_init
#define xdc_runtime_Memory_Instance_init xdc_runtime_Memory_Instance_init__E

/* Instance_finalize */
#undef xdc_runtime_Memory_Instance_finalize
#define xdc_runtime_Memory_Instance_finalize xdc_runtime_Memory_Instance_finalize__E

/* module */
#define Memory_module ((xdc_runtime_Memory_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_Memory_Module__state__V)))
#if !defined(__cplusplus) || !defined(xdc_runtime_Memory__cplusplus)
#define module ((xdc_runtime_Memory_Module_State *)(xdc__MODOBJADDR__(xdc_runtime_Memory_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID xdc_runtime_Memory_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL xdc_runtime_Memory_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB xdc_runtime_Memory_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK xdc_runtime_Memory_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF xdc_runtime_Memory_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ xdc_runtime_Memory_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 xdc_runtime_Memory_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 xdc_runtime_Memory_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 xdc_runtime_Memory_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 xdc_runtime_Memory_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 xdc_runtime_Memory_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ xdc_runtime_Memory_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS xdc_runtime_Memory_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create xdc_runtime_Memory_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete xdc_runtime_Memory_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter xdc_runtime_Memory_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave xdc_runtime_Memory_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query xdc_runtime_Memory_Module_GateProxy_query


#endif /* xdc_runtime_Memory__INTERNAL____ */
