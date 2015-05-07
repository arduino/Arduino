/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_runtime_heaps_HeapRem__INTERNAL__
#define ti_runtime_heaps_HeapRem__INTERNAL__

#ifndef ti_runtime_heaps_HeapRem__internalaccess
#define ti_runtime_heaps_HeapRem__internalaccess
#endif

#include <ti/runtime/heaps/HeapRem.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* alloc */
#undef ti_runtime_heaps_HeapRem_alloc
#define ti_runtime_heaps_HeapRem_alloc ti_runtime_heaps_HeapRem_alloc__E

/* free */
#undef ti_runtime_heaps_HeapRem_free
#define ti_runtime_heaps_HeapRem_free ti_runtime_heaps_HeapRem_free__E

/* isBlocking */
#undef ti_runtime_heaps_HeapRem_isBlocking
#define ti_runtime_heaps_HeapRem_isBlocking ti_runtime_heaps_HeapRem_isBlocking__E

/* getStats */
#undef ti_runtime_heaps_HeapRem_getStats
#define ti_runtime_heaps_HeapRem_getStats ti_runtime_heaps_HeapRem_getStats__E

/* Module_startup */
#undef ti_runtime_heaps_HeapRem_Module_startup
#define ti_runtime_heaps_HeapRem_Module_startup ti_runtime_heaps_HeapRem_Module_startup__E

/* Instance_init */
#undef ti_runtime_heaps_HeapRem_Instance_init
#define ti_runtime_heaps_HeapRem_Instance_init ti_runtime_heaps_HeapRem_Instance_init__E

/* Instance_finalize */
#undef ti_runtime_heaps_HeapRem_Instance_finalize
#define ti_runtime_heaps_HeapRem_Instance_finalize ti_runtime_heaps_HeapRem_Instance_finalize__E

/* module */
#define HeapRem_module ((ti_runtime_heaps_HeapRem_Module_State *)(xdc__MODOBJADDR__(ti_runtime_heaps_HeapRem_Module__state__V)))
#if !defined(__cplusplus) || !defined(ti_runtime_heaps_HeapRem__cplusplus)
#define module ((ti_runtime_heaps_HeapRem_Module_State *)(xdc__MODOBJADDR__(ti_runtime_heaps_HeapRem_Module__state__V)))
#endif
/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_runtime_heaps_HeapRem_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_runtime_heaps_HeapRem_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_runtime_heaps_HeapRem_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_runtime_heaps_HeapRem_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_runtime_heaps_HeapRem_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_runtime_heaps_HeapRem_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_runtime_heaps_HeapRem_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_runtime_heaps_HeapRem_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_runtime_heaps_HeapRem_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_runtime_heaps_HeapRem_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_runtime_heaps_HeapRem_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_runtime_heaps_HeapRem_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_runtime_heaps_HeapRem_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_runtime_heaps_HeapRem_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_runtime_heaps_HeapRem_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_runtime_heaps_HeapRem_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_runtime_heaps_HeapRem_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_runtime_heaps_HeapRem_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.runtime.heaps.HeapRem"
typedef char ti_runtime_heaps_HeapRem_Object__sizingError[sizeof(ti_runtime_heaps_HeapRem_Object) > sizeof(ti_runtime_heaps_HeapRem_Struct) ? -1 : 1];


#endif /* ti_runtime_heaps_HeapRem__INTERNAL____ */
