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

#if !defined(COUNTDOWN_H)
#define COUNTDOWN_H

class Countdown
{
public:
    Countdown()
    {  
		interval_end_ms = 0L;
    }
    
    Countdown(int ms)
    {
        countdown_ms(ms);   
    }
    
    bool expired()
    {
        return (interval_end_ms > 0L) && (millis() >= interval_end_ms);
    }
    
    void countdown_ms(unsigned long ms)  
    {
        interval_end_ms = millis() + ms;
    }
    
    void countdown(int seconds)
    {
        countdown_ms((unsigned long)seconds * 1000L);
    }
    
    int left_ms()
    {
        return interval_end_ms - millis();
    }
    
private:
    unsigned long interval_end_ms; 
};

#endif
