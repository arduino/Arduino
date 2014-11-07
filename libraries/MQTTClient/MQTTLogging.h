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

#if !defined(MQTT_LOGGING_H)
#define MQTT_LOGGING_H

#define STREAM      stdout
#if !defined(DEBUG)
#define DEBUG(...)    \
    {\
    fprintf(STREAM, "DEBUG:   %s L#%d ", __PRETTY_FUNCTION__, __LINE__);  \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    }
#endif
#if !defined(LOG)
#define LOG(...)    \
    {\
    fprintf(STREAM, "LOG:   %s L#%d ", __PRETTY_FUNCTION__, __LINE__);  \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    }
#endif
#if !defined(WARN)
#define WARN(...)   \
    { \
    fprintf(STREAM, "WARN:  %s L#%d ", __PRETTY_FUNCTION__, __LINE__);  \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    }
#endif 
#if !defined(ERROR)
#define ERROR(...)  \
    { \
    fprintf(STREAM, "ERROR: %s L#%d ", __PRETTY_FUNCTION__, __LINE__); \
    fprintf(STREAM, ##__VA_ARGS__); \
    fflush(STREAM); \
    exit(1); \
    }
#endif

#endif
