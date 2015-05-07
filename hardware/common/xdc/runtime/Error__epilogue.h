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
/*
 *  ======== xdc_runtime_Error_raise ========
 *  Call underlying error handler with current module ID, file name, and
 *  line number.
 *
 *  Note use of xdc_FILE__ in lieu of __FILE__; this is done
 *  to prevent accumulation of file name strings in the application.  See
 *  xdc.h for details.
 */
#define xdc_runtime_Error_raise(eb, id, arg1, arg2) \
    xdc_runtime_Error_raiseX((eb), Module__MID, xdc_FILE__, __LINE__, \
        (id), (IArg)(arg1), (IArg)(arg2));

/*
 *  ======== xdc_runtime_Error_idToCode ========
 */
#define xdc_runtime_Error_idToCode(id) \
    (xdc_UInt16)((id) & 0x0000ffff)

/*
 *  ======== xdc_runtime_Error_idToUid ========
 */
#define xdc_runtime_Error_idToUid(id) \
    (xdc_UInt16)((id) >> 16)
/*
 *  @(#) xdc.runtime; 2, 1, 0,0; 4-24-2015 12:34:11; /db/ztree/library/trees/xdc/xdc-A71/src/packages/
 */

