/*
 ###############################################################################
 #
 # Temboo MQTT edge device library
 #
 # Copyright (C) 2017, Temboo Inc.
 #
 # Licensed under the Apache License, Version 2.0 (the "License");
 # you may not use this file except in compliance with the License.
 # You may obtain a copy of the License at
 #
 # http://www.apache.org/licenses/LICENSE-2.0
 #
 # Unless required by applicable law or agreed to in writing,
 # software distributed under the License is distributed on an
 # "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 # either express or implied. See the License for the specific
 # language governing permissions and limitations under the License.
 #
 ###############################################################################
 */

#ifndef TEMBOOBASEIPSTACK_H_
#define TEMBOOBASEIPSTACK_H_

#include <Client.h>

static const int WRITE_CHUNK_SIZE = 64;

class TembooMQTTIPStack
{
public:    
    TembooMQTTIPStack(Client& client) : m_client(client) {
    }
    
    int connect(const char* hostname, int port) {
        return m_client.connect(hostname, port);
    }

    bool isConnected() {
        return m_client.connected();
    }
    
    int disconnect() {
        m_client.stop();
        return 0;
    }

    int read(unsigned char* buffer, int len, int timeoutMillis) {

        m_client.setTimeout(timeoutMillis);
        size_t count = m_client.readBytes((char*)buffer, len);
        
        // Not sure this is a totally good idea.
        // (Stream defaults to 1000 mS timeouts.)
        m_client.setTimeout(1000);
        return count;
    }
    
    int write(unsigned char* buffer, int len, int timeout) {

        // It's possible for write to get called with a 0 timeout, 
        // in which case we want to make at least one attempt to send
        // the data.
        timeout = timeout == 0 ? 1 : timeout;
        m_client.setTimeout(timeout); 

        // Arduino's WiFiClient::write can accept only a limited 
        // number of characters on each call, so we must make sure
        // we pass less than this limit.  Note that this isn't necessary
        // for Arduino's EthernetClient.  However, instead of trying to 
        // differentiate between clients, we do it for both.
        // It SHOULDN'T impact performance in any significant way, but
        // if you're using a client that doesn't have this limitation and
        // the idea bothers you, feel free to eliminate the min() call or
        // else set WRITE_CHUNK_SIZE to a large number.
       
        // Note that the caller (in this case, MQTT::Client::sendPacket)
        // is responsible for calling this method repeatedly until all
        // bytes have been written.
		
        size_t count = m_client.write(buffer, min(len, WRITE_CHUNK_SIZE));
        
        // Not sure this is a totally good idea.
        // (Stream defaults to 1000 mS timeouts.)
        m_client.setTimeout(1000);
        return count;
    }
    

protected:
    Client& m_client;
};

#endif

