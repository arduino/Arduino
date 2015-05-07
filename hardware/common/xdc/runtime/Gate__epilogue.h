/* 
 *  Copyright (c) 2008 Texas Instruments. All rights reserved. 
 *  This program and the accompanying materials are made available under the 
 *  terms of the Eclipse Public License v1.0 and Eclipse Distribution License
 *  v. 1.0 which accompanies this distribution. The Eclipse Public License is
 *  available at http://www.eclipse.org/legal/epl-v10.html and the Eclipse
 *  Distribution License is available at 
 *  http://www.eclipse.org/org/documents/edl-v10.php.
 *
 *  Contributors:
 *      Texas Instruments - initial implementation
 * */
#define xdc_runtime_Gate_allocInstance( eb ) \
    ((xdc_runtime_Gate_Ref)Module__GP_create(Module__G_PRMS, (eb)))

#define xdc_runtime_Gate_freeInstance( gate ) \
    Module__GP_delete((xdc_Ptr)(&(gate)))

#define xdc_runtime_Gate_enterInstance( gate ) \
    Module__GP_enter((xdc_Ptr)(gate))

#define xdc_runtime_Gate_enterModule() \
    Module__GP_enter(Module__G_OBJ)

#define xdc_runtime_Gate_leaveInstance( gate, key ) \
    Module__GP_leave((xdc_Ptr)(gate), (key))

#define xdc_runtime_Gate_leaveModule( key ) \
    Module__GP_leave(Module__G_OBJ, (key))

#define xdc_runtime_Gate_canBlock( ) \
    Module__GP_query(xdc_runtime_IGateProvider_Q_BLOCKING)

#define xdc_runtime_Gate_canBePreempted( ) \
    Module__GP_query(xdc_runtime_IGateProvider_Q_PREEMPTING)
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:12; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

