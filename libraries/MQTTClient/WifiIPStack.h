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

#ifndef ARDUINOWIFIIPSTACK_H
#define ARDUINOWIFIIPSTACK_H

#include <WiFi.h>

class WifiIPStack 
{
public:    
    WifiIPStack()
    {
        //WiFi.begin();              // Use DHCP
        iface.setTimeout(1000);    // 1 second Timeout 
    }
    
    int connect(char* hostname, int port)
    {
        return iface.connect(hostname, port);
    }

    int connect(uint32_t hostname, int port)
    {
        return iface.connect(hostname, port);
    }

    int read(unsigned char* buffer, int len, int timeout)
    {
        int interval = 10;  // all times are in milliseconds
		int total = 0, rc = -1;

		if (timeout < 30)
			interval = 2;
		while (iface.available() < len && total < timeout)
		{
			delay(interval);
			total += interval;
		}
		if (iface.available() >= len)
			rc = iface.readBytes((char*)buffer, len);
		return rc;
    }

    
    int write(unsigned char* buffer, int len, int timeout)
    {
        iface.setTimeout(timeout);  
        return iface.write((uint8_t*)buffer, len);
    }
    
    int disconnect()
    {
        iface.stop();
        return 0;
    }
    
private:

    WiFiClient iface;
    
};

#endif



