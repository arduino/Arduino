/*******************************************************************************
 * Copyright (c) 2014 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * and Eclipse Distribution License v1.0 which accompany this distribution.
 *
 * The Eclipse Public License is available at
 *    http://www.eclipse.org/legal/epl-v10.html
 * and the Eclipse Distribution License is available at
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial API and implementation and/or initial documentation
 *******************************************************************************/

/*******************************************************************************
 * Modified for Arduino environment by Temboo
 *    Joe Planisky - replaced fancy fprintf stuff with Serial.print(ln)
 *******************************************************************************/

#if !defined(MQTT_LOGGING_H)
#define MQTT_LOGGING_H

#if !defined(DEBUG)
#define DEBUG(msg) {Serial.print("DEBUG: "); Serial.println(msg);}
#endif

#if !defined(LOG)
#define LOG(msg) {Serial.print("LOG: "); Serial.println(msg);}
#endif

#if !defined(WARN)
#define WARN(msg) {Serial.print("WARN: "); Serial.println(msg);}
#endif 

#if !defined(ERROR)
#define ERROR() {Serial.print("ERROR: "); Serial.println(msg);}
#endif

#endif
