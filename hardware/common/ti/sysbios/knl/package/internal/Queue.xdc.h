/*
 *  Do not modify this file; it is automatically 
 *  generated and any modifications will be overwritten.
 *
 * @(#) xdc-A71
 */

#ifndef ti_sysbios_knl_Queue__INTERNAL__
#define ti_sysbios_knl_Queue__INTERNAL__

#ifndef ti_sysbios_knl_Queue__internalaccess
#define ti_sysbios_knl_Queue__internalaccess
#endif

#include <ti/sysbios/knl/Queue.h>

#undef xdc_FILE__
#ifndef xdc_FILE
#define xdc_FILE__ NULL
#else
#define xdc_FILE__ xdc_FILE
#endif

/* elemClear */
#undef ti_sysbios_knl_Queue_elemClear
#define ti_sysbios_knl_Queue_elemClear ti_sysbios_knl_Queue_elemClear__E

/* insert */
#undef ti_sysbios_knl_Queue_insert
#define ti_sysbios_knl_Queue_insert ti_sysbios_knl_Queue_insert__E

/* next */
#undef ti_sysbios_knl_Queue_next
#define ti_sysbios_knl_Queue_next ti_sysbios_knl_Queue_next__E

/* prev */
#undef ti_sysbios_knl_Queue_prev
#define ti_sysbios_knl_Queue_prev ti_sysbios_knl_Queue_prev__E

/* remove */
#undef ti_sysbios_knl_Queue_remove
#define ti_sysbios_knl_Queue_remove ti_sysbios_knl_Queue_remove__E

/* isQueued */
#undef ti_sysbios_knl_Queue_isQueued
#define ti_sysbios_knl_Queue_isQueued ti_sysbios_knl_Queue_isQueued__E

/* dequeue */
#undef ti_sysbios_knl_Queue_dequeue
#define ti_sysbios_knl_Queue_dequeue ti_sysbios_knl_Queue_dequeue__E

/* empty */
#undef ti_sysbios_knl_Queue_empty
#define ti_sysbios_knl_Queue_empty ti_sysbios_knl_Queue_empty__E

/* enqueue */
#undef ti_sysbios_knl_Queue_enqueue
#define ti_sysbios_knl_Queue_enqueue ti_sysbios_knl_Queue_enqueue__E

/* get */
#undef ti_sysbios_knl_Queue_get
#define ti_sysbios_knl_Queue_get ti_sysbios_knl_Queue_get__E

/* head */
#undef ti_sysbios_knl_Queue_head
#define ti_sysbios_knl_Queue_head ti_sysbios_knl_Queue_head__E

/* put */
#undef ti_sysbios_knl_Queue_put
#define ti_sysbios_knl_Queue_put ti_sysbios_knl_Queue_put__E

/* Module_startup */
#undef ti_sysbios_knl_Queue_Module_startup
#define ti_sysbios_knl_Queue_Module_startup ti_sysbios_knl_Queue_Module_startup__E

/* Instance_init */
#undef ti_sysbios_knl_Queue_Instance_init
#define ti_sysbios_knl_Queue_Instance_init ti_sysbios_knl_Queue_Instance_init__E

/* Instance_finalize */
#undef ti_sysbios_knl_Queue_Instance_finalize
#define ti_sysbios_knl_Queue_Instance_finalize ti_sysbios_knl_Queue_Instance_finalize__E

/* per-module runtime symbols */
#undef Module__MID
#define Module__MID ti_sysbios_knl_Queue_Module__id__C
#undef Module__DGSINCL
#define Module__DGSINCL ti_sysbios_knl_Queue_Module__diagsIncluded__C
#undef Module__DGSENAB
#define Module__DGSENAB ti_sysbios_knl_Queue_Module__diagsEnabled__C
#undef Module__DGSMASK
#define Module__DGSMASK ti_sysbios_knl_Queue_Module__diagsMask__C
#undef Module__LOGDEF
#define Module__LOGDEF ti_sysbios_knl_Queue_Module__loggerDefined__C
#undef Module__LOGOBJ
#define Module__LOGOBJ ti_sysbios_knl_Queue_Module__loggerObj__C
#undef Module__LOGFXN0
#define Module__LOGFXN0 ti_sysbios_knl_Queue_Module__loggerFxn0__C
#undef Module__LOGFXN1
#define Module__LOGFXN1 ti_sysbios_knl_Queue_Module__loggerFxn1__C
#undef Module__LOGFXN2
#define Module__LOGFXN2 ti_sysbios_knl_Queue_Module__loggerFxn2__C
#undef Module__LOGFXN4
#define Module__LOGFXN4 ti_sysbios_knl_Queue_Module__loggerFxn4__C
#undef Module__LOGFXN8
#define Module__LOGFXN8 ti_sysbios_knl_Queue_Module__loggerFxn8__C
#undef Module__G_OBJ
#define Module__G_OBJ ti_sysbios_knl_Queue_Module__gateObj__C
#undef Module__G_PRMS
#define Module__G_PRMS ti_sysbios_knl_Queue_Module__gatePrms__C
#undef Module__GP_create
#define Module__GP_create ti_sysbios_knl_Queue_Module_GateProxy_create
#undef Module__GP_delete
#define Module__GP_delete ti_sysbios_knl_Queue_Module_GateProxy_delete
#undef Module__GP_enter
#define Module__GP_enter ti_sysbios_knl_Queue_Module_GateProxy_enter
#undef Module__GP_leave
#define Module__GP_leave ti_sysbios_knl_Queue_Module_GateProxy_leave
#undef Module__GP_query
#define Module__GP_query ti_sysbios_knl_Queue_Module_GateProxy_query

/* Object__sizingError */
#line 1 "Error_inconsistent_object_size_in_ti.sysbios.knl.Queue"
typedef char ti_sysbios_knl_Queue_Object__sizingError[sizeof(ti_sysbios_knl_Queue_Object) > sizeof(ti_sysbios_knl_Queue_Struct) ? -1 : 1];


#endif /* ti_sysbios_knl_Queue__INTERNAL____ */
