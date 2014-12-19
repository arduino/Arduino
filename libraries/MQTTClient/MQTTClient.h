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

#if !defined(MQTTCLIENT_H)
#define MQTTCLIENT_H

#include "FP.h"
#include "MQTTPacket.h"
#include "stdio.h"
#include "MQTTLogging.h"

#if !defined(MQTTCLIENT_QOS1)
    #define MQTTCLIENT_QOS1 1
#endif
#if !defined(MQTTCLIENT_QOS2)
    #define MQTTCLIENT_QOS2 0
#endif

namespace MQTT
{


enum QoS { QOS0, QOS1, QOS2 };

// all failure return codes must be negative
enum returnCode { BUFFER_OVERFLOW = -2, FAILURE = -1, SUCCESS = 0 };


struct Message
{
    enum QoS qos;
    bool retained;
    bool dup;
    unsigned short id;
    void *payload;
    size_t payloadlen;
};


struct MessageData
{
    MessageData(MQTTString &aTopicName, struct Message &aMessage)  : message(aMessage), topicName(aTopicName)
    { }

    struct Message &message;
    MQTTString &topicName;
};


class PacketId
{
public:
    PacketId()
    {
        next = 0;
    }

    int getNext()
    {
        return next = (next == MAX_PACKET_ID) ? 1 : ++next;
    }

private:
    static const int MAX_PACKET_ID = 65535;
    int next;
};


/**
 * @class Client
 * @brief blocking, non-threaded MQTT client API
 *
 * This version of the API blocks on all method calls, until they are complete.  This means that only one
 * MQTT request can be in process at any one time.
 * @param Network a network class which supports send, receive
 * @param Timer a timer class with the methods:
 */
template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE = 50, int MAX_MESSAGE_HANDLERS = 5>
class Client
{

public:

    typedef void (*messageHandler)(MessageData&);

    /** Construct the client
     *  @param network - pointer to an instance of the Network class - must be connected to the endpoint
     *      before calling MQTT connect
     *  @param limits an instance of the Limit class - to alter limits as required
     */
    Client(Network& network, unsigned int command_timeout_ms = 30000);

    /** Set the default message handling callback - used for any message which does not match a subscription message handler
     *  @param mh - pointer to the callback function
     */
    void setDefaultMessageHandler(messageHandler mh)
    {
        defaultMessageHandler.attach(mh);
    }

    /** MQTT Connect - send an MQTT connect packet down the network and wait for a Connack
     *  The nework object must be connected to the network endpoint before calling this
     *  Default connect options are used
     *  @return success code -
     */
    int connect();
    
        /** MQTT Connect - send an MQTT connect packet down the network and wait for a Connack
     *  The nework object must be connected to the network endpoint before calling this
     *  @param options - connect options
     *  @return success code -
     */
    int connect(MQTTPacket_connectData& options);

    /** MQTT Publish - send an MQTT publish packet and wait for all acks to complete for all QoSs
     *  @param topic - the topic to publish to
     *  @param message - the message to send
     *  @return success code -
     */
    int publish(const char* topicName, Message& message);
    
    /** MQTT Publish - send an MQTT publish packet and wait for all acks to complete for all QoSs
     *  @param topic - the topic to publish to
     *  @param payload - the data to send
     *  @param payloadlen - the length of the data
     *  @param qos - the QoS to send the publish at
     *  @param retained - whether the message should be retained
     *  @return success code -
     */
    int publish(const char* topicName, void* payload, size_t payloadlen, enum QoS qos = QOS0, bool retained = false);
    
    /** MQTT Publish - send an MQTT publish packet and wait for all acks to complete for all QoSs
     *  @param topic - the topic to publish to
     *  @param payload - the data to send
     *  @param payloadlen - the length of the data
     *  @param id - the packet id used - returned 
     *  @param qos - the QoS to send the publish at
     *  @param retained - whether the message should be retained
     *  @return success code -
     */
    int publish(const char* topicName, void* payload, size_t payloadlen, unsigned short& id, enum QoS qos = QOS1, bool retained = false);

    /** MQTT Subscribe - send an MQTT subscribe packet and wait for the suback
     *  @param topicFilter - a topic pattern which can include wildcards
     *  @param qos - the MQTT QoS to subscribe at
     *  @param mh - the callback function to be invoked when a message is received for this subscription
     *  @return success code -
     */
    int subscribe(const char* topicFilter, enum QoS qos, messageHandler mh);

    /** MQTT Unsubscribe - send an MQTT unsubscribe packet and wait for the unsuback
     *  @param topicFilter - a topic pattern which can include wildcards
     *  @return success code -
     */
    int unsubscribe(const char* topicFilter);

    /** MQTT Disconnect - send an MQTT disconnect packet, and clean up any state
     *  @return success code -
     */
    int disconnect();

    /** A call to this API must be made within the keepAlive interval to keep the MQTT connection alive
     *  yield can be called if no other MQTT operation is needed.  This will also allow messages to be
     *  received.
     *  @param timeout_ms the time to wait, in milliseconds
     *  @return success code - on failure, this means the client has disconnected
     */
    int yield(unsigned long timeout_ms = 1000L);

    /** Is the client connected?
     *  @return flag - is the client connected or not?
     */
    bool isConnected()
    {
        return isconnected;
    }

private:

    int cycle(Timer& timer);
    int waitfor(int packet_type, Timer& timer);
    int keepalive();
    int publish(int len, Timer& timer, enum QoS qos);

    int decodePacket(int* value, int timeout);
    int readPacket(Timer& timer);
    int sendPacket(int length, Timer& timer);
    int deliverMessage(MQTTString& topicName, Message& message);
    bool isTopicMatched(char* topicFilter, MQTTString& topicName);

    Network& ipstack;
    unsigned long command_timeout_ms;

    unsigned char sendbuf[MAX_MQTT_PACKET_SIZE];
    unsigned char readbuf[MAX_MQTT_PACKET_SIZE];

    Timer last_sent, last_received;
    unsigned int keepAliveInterval;
    bool ping_outstanding;
    bool cleansession;

    PacketId packetid;

    struct MessageHandlers
    {
        const char* topicFilter;
        FP<void, MessageData&> fp;
    } messageHandlers[MAX_MESSAGE_HANDLERS];      // Message handlers are indexed by subscription topic

    FP<void, MessageData&> defaultMessageHandler;

    bool isconnected;

#if MQTTCLIENT_QOS1 || MQTTCLIENT_QOS2
    unsigned char pubbuf[MAX_MQTT_PACKET_SIZE];  // store the last publish for sending on reconnect
    int inflightLen;
    unsigned short inflightMsgid;
    enum QoS inflightQoS;
#endif

#if MQTTCLIENT_QOS2
    bool pubrel;
    #if !defined(MAX_INCOMING_QOS2_MESSAGES)
        #define MAX_INCOMING_QOS2_MESSAGES 10
    #endif
    unsigned short incomingQoS2messages[MAX_INCOMING_QOS2_MESSAGES];
    bool isQoS2msgidFree(unsigned short id);
    bool useQoS2msgid(unsigned short id);
#endif

};

}


template<class Network, class Timer, int a, int MAX_MESSAGE_HANDLERS>
MQTT::Client<Network, Timer, a, MAX_MESSAGE_HANDLERS>::Client(Network& network, unsigned int command_timeout_ms)  : ipstack(network), packetid()
{
    last_sent = Timer();
    last_received = Timer();
    ping_outstanding = false;
    for (int i = 0; i < MAX_MESSAGE_HANDLERS; ++i)
        messageHandlers[i].topicFilter = 0;
    this->command_timeout_ms = command_timeout_ms;
    isconnected = false;

#if MQTTCLIENT_QOS1 || MQTTCLIENT_QOS2
    inflightMsgid = 0;
    inflightQoS = QOS0;
#endif


#if MQTTCLIENT_QOS2
    pubrel = false;
    for (int i = 0; i < MAX_INCOMING_QOS2_MESSAGES; ++i)
        incomingQoS2messages[i] = 0;
#endif
}

#if MQTTCLIENT_QOS2
template<class Network, class Timer, int a, int b>
bool MQTT::Client<Network, Timer, a, b>::isQoS2msgidFree(unsigned short id)
{
    for (int i = 0; i < MAX_INCOMING_QOS2_MESSAGES; ++i)
    {
        if (incomingQoS2messages[i] == id)
            return false;
    }
    return true;
}


template<class Network, class Timer, int a, int b>
bool MQTT::Client<Network, Timer, a, b>::useQoS2msgid(unsigned short id)
{
    for (int i = 0; i < MAX_INCOMING_QOS2_MESSAGES; ++i)
    {
        if (incomingQoS2messages[i] == 0)
        {
            incomingQoS2messages[i] = id;
            return true;
        }
    }
    return false;
}
#endif


template<class Network, class Timer, int a, int b>
int MQTT::Client<Network, Timer, a, b>::sendPacket(int length, Timer& timer)
{
    int rc = FAILURE,
        sent = 0;

    while (sent < length && !timer.expired())
    {
        rc = ipstack.write(&sendbuf[sent], length, timer.left_ms());
        if (rc < 0)  // there was an error writing the data
            break;
        sent += rc;
    }
    if (sent == length)
    {
        if (this->keepAliveInterval > 0)
            last_sent.countdown(this->keepAliveInterval); // record the fact that we have successfully sent the packet
        rc = SUCCESS;
    }
    else
        rc = FAILURE;
        
#if defined(MQTT_DEBUG)
    char printbuf[150];
    DEBUG("Rc %d from sending packet %s\n", rc, MQTTFormat_toServerString(printbuf, sizeof(printbuf), sendbuf, length));
#endif
    return rc;
}


template<class Network, class Timer, int a, int b>
int MQTT::Client<Network, Timer, a, b>::decodePacket(int* value, int timeout)
{
    unsigned char c;
    int multiplier = 1;
    int len = 0;
    const int MAX_NO_OF_REMAINING_LENGTH_BYTES = 4;

    *value = 0;
    do
    {
        int rc = MQTTPACKET_READ_ERROR;

        if (++len > MAX_NO_OF_REMAINING_LENGTH_BYTES)
        {
            rc = MQTTPACKET_READ_ERROR; /* bad data */
            goto exit;
        }
        rc = ipstack.read(&c, 1, timeout);
        if (rc != 1)
            goto exit;
        *value += (c & 127) * multiplier;
        multiplier *= 128;
    } while ((c & 128) != 0);
exit:
    return len;
}


/**
 * If any read fails in this method, then we should disconnect from the network, as on reconnect
 * the packets can be retried.
 * @param timeout the max time to wait for the packet read to complete, in milliseconds
 * @return the MQTT packet type, or -1 if none
 */
template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::readPacket(Timer& timer)
{
    int rc = FAILURE;
    MQTTHeader header = {0};
    int len = 0;
    int rem_len = 0;
	int read = 0;

    /* 1. read the header byte.  This has the packet type in it */
    if (ipstack.read(readbuf, 1, timer.left_ms()) != 1)
        goto exit;

    len = 1;
    /* 2. read the remaining length.  This is variable in itself */
    decodePacket(&rem_len, timer.left_ms());
    len += MQTTPacket_encode(readbuf + 1, rem_len); /* put the original remaining length into the buffer */

	if (rem_len > (MAX_MQTT_PACKET_SIZE - len))
	{
		rc = BUFFER_OVERFLOW;
		goto exit;
	}

    /* 3. read the rest of the buffer using a callback to supply the rest of the data */
    if (rem_len > 0 && (ipstack.read(readbuf + len, rem_len, timer.left_ms()) != rem_len))
        goto exit;

    header.byte = readbuf[0];
    rc = header.bits.type;
    if (this->keepAliveInterval > 0)
        last_received.countdown(this->keepAliveInterval); // record the fact that we have successfully received a packet
exit:
        
#if defined(MQTT_DEBUG)
	if (rc >= 0)
	{
		char printbuf[50];
		DEBUG("Rc %d from receiving packet %s\n", rc, MQTTFormat_toClientString(printbuf, sizeof(printbuf), readbuf, len));
	}
#endif
    return rc;
}


// assume topic filter and name is in correct format
// # can only be at end
// + and # can only be next to separator
template<class Network, class Timer, int a, int b>
bool MQTT::Client<Network, Timer, a, b>::isTopicMatched(char* topicFilter, MQTTString& topicName)
{
    char* curf = topicFilter;
    char* curn = topicName.lenstring.data;
    char* curn_end = curn + topicName.lenstring.len;

    while (*curf && curn < curn_end)
    {
        if (*curn == '/' && *curf != '/')
            break;
        if (*curf != '+' && *curf != '#' && *curf != *curn)
            break;
        if (*curf == '+')
        {   // skip until we meet the next separator, or end of string
            char* nextpos = curn + 1;
            while (nextpos < curn_end && *nextpos != '/')
                nextpos = ++curn + 1;
        }
        else if (*curf == '#')
            curn = curn_end - 1;    // skip until end of string
        curf++;
        curn++;
    };

    return (curn == curn_end) && (*curf == '\0');
}



template<class Network, class Timer, int a, int MAX_MESSAGE_HANDLERS>
int MQTT::Client<Network, Timer, a, MAX_MESSAGE_HANDLERS>::deliverMessage(MQTTString& topicName, Message& message)
{
    int rc = FAILURE;

    // we have to find the right message handler - indexed by topic
    for (int i = 0; i < MAX_MESSAGE_HANDLERS; ++i)
    {
        if (messageHandlers[i].topicFilter != 0 && (MQTTPacket_equals(&topicName, (char*)messageHandlers[i].topicFilter) ||
                isTopicMatched((char*)messageHandlers[i].topicFilter, topicName)))
        {
            if (messageHandlers[i].fp.attached())
            {
                MessageData md(topicName, message);
                messageHandlers[i].fp(md);
                rc = SUCCESS;
            }
        }
    }

    if (rc == FAILURE && defaultMessageHandler.attached())
    {
        MessageData md(topicName, message);
        defaultMessageHandler(md);
        rc = SUCCESS;
    }

    return rc;
}



template<class Network, class Timer, int a, int b>
int MQTT::Client<Network, Timer, a, b>::yield(unsigned long timeout_ms)
{
    int rc = SUCCESS;
    Timer timer = Timer();

    timer.countdown_ms(timeout_ms);
    while (!timer.expired())
    {
        if (cycle(timer) < 0)
        {
            rc = FAILURE;
            break;
        }
    }

    return rc;
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::cycle(Timer& timer)
{
    /* get one piece of work off the wire and one pass through */

    // read the socket, see what work is due
    int packet_type = readPacket(timer);

    int len = 0,
        rc = SUCCESS;

    switch (packet_type)
    {
		case FAILURE:
		case BUFFER_OVERFLOW:
			rc = packet_type;
			break;
        case CONNACK:
        case PUBACK:
        case SUBACK:
            break;
        case PUBLISH:
		{
            MQTTString topicName = MQTTString_initializer;
            Message msg;
            if (MQTTDeserialize_publish((unsigned char*)&msg.dup, (int*)&msg.qos, (unsigned char*)&msg.retained, (unsigned short*)&msg.id, &topicName,
                                 (unsigned char**)&msg.payload, (int*)&msg.payloadlen, readbuf, MAX_MQTT_PACKET_SIZE) != 1)
                goto exit;
#if MQTTCLIENT_QOS2
            if (msg.qos != QOS2)
#endif
                deliverMessage(topicName, msg);
#if MQTTCLIENT_QOS2
            else if (isQoS2msgidFree(msg.id))
            {
                if (useQoS2msgid(msg.id))
                    deliverMessage(topicName, msg);
                else
                    WARN("Maximum number of incoming QoS2 messages exceeded");
            }
#endif
#if MQTTCLIENT_QOS1 || MQTTCLIENT_QOS2
            if (msg.qos != QOS0)
            {
                if (msg.qos == QOS1)
                    len = MQTTSerialize_ack(sendbuf, MAX_MQTT_PACKET_SIZE, PUBACK, 0, msg.id);
                else if (msg.qos == QOS2)
                    len = MQTTSerialize_ack(sendbuf, MAX_MQTT_PACKET_SIZE, PUBREC, 0, msg.id);
                if (len <= 0)
                    rc = FAILURE;
                else
                    rc = sendPacket(len, timer);
                if (rc == FAILURE)
                    goto exit; // there was a problem
            }
            break;
#endif
		}
#if MQTTCLIENT_QOS2
        case PUBREC:
            unsigned short mypacketid;
            unsigned char dup, type;
            if (MQTTDeserialize_ack(&type, &dup, &mypacketid, readbuf, MAX_MQTT_PACKET_SIZE) != 1)
                rc = FAILURE;
            else if ((len = MQTTSerialize_ack(sendbuf, MAX_MQTT_PACKET_SIZE, PUBREL, 0, mypacketid)) <= 0)
                rc = FAILURE;
            else if ((rc = sendPacket(len, timer)) != SUCCESS) // send the PUBREL packet
                rc = FAILURE; // there was a problem
            if (rc == FAILURE)
                goto exit; // there was a problem
            break;
        case PUBCOMP:
            break;
#endif
        case PINGRESP:
            ping_outstanding = false;
            break;
    }
    keepalive();
exit:
    if (rc == SUCCESS)
        rc = packet_type;
    return rc;
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::keepalive()
{
    int rc = FAILURE;

    if (keepAliveInterval == 0)
    {
        rc = SUCCESS;
        goto exit;
    }

    if (last_sent.expired() || last_received.expired())
    {
        if (!ping_outstanding)
        {
            Timer timer = Timer(1000);
            int len = MQTTSerialize_pingreq(sendbuf, MAX_MQTT_PACKET_SIZE);
            if (len > 0 && (rc = sendPacket(len, timer)) == SUCCESS) // send the ping packet
                ping_outstanding = true;
        }
    }

exit:
    return rc;
}


// only used in single-threaded mode where one command at a time is in process
template<class Network, class Timer, int a, int b>
int MQTT::Client<Network, Timer, a, b>::waitfor(int packet_type, Timer& timer)
{
    int rc = FAILURE;

    do
    {
        if (timer.expired())
            break; // we timed out
    }
    while ((rc = cycle(timer)) != packet_type);

    return rc;
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::connect(MQTTPacket_connectData& options)
{
    Timer connect_timer = Timer(command_timeout_ms);
    int rc = FAILURE;
    int len = 0;

    if (isconnected) // don't send connect packet again if we are already connected
        goto exit;

    this->keepAliveInterval = options.keepAliveInterval;
    this->cleansession = options.cleansession;
    if ((len = MQTTSerialize_connect(sendbuf, MAX_MQTT_PACKET_SIZE, &options)) <= 0)
        goto exit;
    if ((rc = sendPacket(len, connect_timer)) != SUCCESS)  // send the connect packet
        goto exit; // there was a problem

    if (this->keepAliveInterval > 0)
        last_received.countdown(this->keepAliveInterval);
    // this will be a blocking call, wait for the connack
    if (waitfor(CONNACK, connect_timer) == CONNACK)
    {
        unsigned char connack_rc = 255;
        bool sessionPresent = false;
        if (MQTTDeserialize_connack((unsigned char*)&sessionPresent, &connack_rc, readbuf, MAX_MQTT_PACKET_SIZE) == 1)
            rc = connack_rc;
        else
            rc = FAILURE;
    }
    else
        rc = FAILURE;

#if MQTTCLIENT_QOS2
    // resend an inflight publish
    if (inflightMsgid >0 && inflightQoS == QOS2 && pubrel)
    {
        if ((len = MQTTSerialize_ack(sendbuf, MAX_MQTT_PACKET_SIZE, PUBREL, 0, inflightMsgid)) <= 0)
            rc = FAILURE;
        else
            rc = publish(len, connect_timer, inflightQoS);
    }
    else
#endif
#if MQTTCLIENT_QOS1 || MQTTCLIENT_QOS2
    if (inflightMsgid > 0)
    {
        memcpy(sendbuf, pubbuf, MAX_MQTT_PACKET_SIZE);
        rc = publish(inflightLen, connect_timer, inflightQoS);
    }
#endif

exit:
    if (rc == SUCCESS)
        isconnected = true;
    return rc;
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::connect()
{
    MQTTPacket_connectData default_options = MQTTPacket_connectData_initializer;
    return connect(default_options);
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int MAX_MESSAGE_HANDLERS>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, MAX_MESSAGE_HANDLERS>::subscribe(const char* topicFilter, enum QoS qos, messageHandler messageHandler)
{
    int rc = FAILURE;
    Timer timer = Timer(command_timeout_ms);
    int len = 0;
    MQTTString topic = {(char*)topicFilter, 0, 0};

    if (!isconnected)
        goto exit;

    len = MQTTSerialize_subscribe(sendbuf, MAX_MQTT_PACKET_SIZE, 0, packetid.getNext(), 1, &topic, (int*)&qos);
    if (len <= 0)
        goto exit;
    if ((rc = sendPacket(len, timer)) != SUCCESS) // send the subscribe packet
        goto exit;             // there was a problem

    if (waitfor(SUBACK, timer) == SUBACK)      // wait for suback
    {
        int count = 0, grantedQoS = -1;
        unsigned short mypacketid;
        if (MQTTDeserialize_suback(&mypacketid, 1, &count, &grantedQoS, readbuf, MAX_MQTT_PACKET_SIZE) == 1)
            rc = grantedQoS; // 0, 1, 2 or 0x80
        if (rc != 0x80)
        {
            for (int i = 0; i < MAX_MESSAGE_HANDLERS; ++i)
            {
                if (messageHandlers[i].topicFilter == 0)
                {
                    messageHandlers[i].topicFilter = topicFilter;
                    messageHandlers[i].fp.attach(messageHandler);
                    rc = 0;
                    break;
                }
            }
        }
    }
    else
        rc = FAILURE;

exit:
    if (rc != SUCCESS)
        isconnected = false;
    return rc;
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int MAX_MESSAGE_HANDLERS>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, MAX_MESSAGE_HANDLERS>::unsubscribe(const char* topicFilter)
{
    int rc = FAILURE;
    Timer timer = Timer(command_timeout_ms);
    MQTTString topic = {(char*)topicFilter, 0, 0};
    int len = 0;

    if (!isconnected)
        goto exit;

    if ((len = MQTTSerialize_unsubscribe(sendbuf, MAX_MQTT_PACKET_SIZE, 0, packetid.getNext(), 1, &topic)) <= 0)
        goto exit;
    if ((rc = sendPacket(len, timer)) != SUCCESS) // send the unsubscribe packet
        goto exit; // there was a problem

    if (waitfor(UNSUBACK, timer) == UNSUBACK)
    {
        unsigned short mypacketid;  // should be the same as the packetid above
        if (MQTTDeserialize_unsuback(&mypacketid, readbuf, MAX_MQTT_PACKET_SIZE) == 1)
            rc = 0;
    }
    else
        rc = FAILURE;

exit:
    if (rc != SUCCESS)
        isconnected = false;
    return rc;
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::publish(int len, Timer& timer, enum QoS qos)
{
    int rc;

    if ((rc = sendPacket(len, timer)) != SUCCESS) // send the publish packet
        goto exit; // there was a problem

#if MQTTCLIENT_QOS1
    if (qos == QOS1)
    {
        if (waitfor(PUBACK, timer) == PUBACK)
        {
            unsigned short mypacketid;
            unsigned char dup, type;
            if (MQTTDeserialize_ack(&type, &dup, &mypacketid, readbuf, MAX_MQTT_PACKET_SIZE) != 1)
                rc = FAILURE;
            else if (inflightMsgid == mypacketid)
                inflightMsgid = 0;
        }
        else
            rc = FAILURE;
    }
#elif MQTTCLIENT_QOS2
    else if (qos == QOS2)
    {
        if (waitfor(PUBCOMP, timer) == PUBCOMP)
        {
            unsigned short mypacketid;
            unsigned char dup, type;
            if (MQTTDeserialize_ack(&type, &dup, &mypacketid, readbuf, MAX_MQTT_PACKET_SIZE) != 1)
                rc = FAILURE;
            else if (inflightMsgid == mypacketid)
                inflightMsgid = 0;
        }
        else
            rc = FAILURE;
    }
#endif

exit:
    if (rc != SUCCESS)
        isconnected = false;
    return rc;
}



template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::publish(const char* topicName, void* payload, size_t payloadlen, unsigned short& id, enum QoS qos, bool retained)
{
    int rc = FAILURE;
    Timer timer = Timer(command_timeout_ms);
    MQTTString topicString = MQTTString_initializer;
    int len = 0;

    if (!isconnected)
        goto exit;

    topicString.cstring = (char*)topicName;

#if MQTTCLIENT_QOS1 || MQTTCLIENT_QOS2
    if (qos == QOS1 || qos == QOS2)
        id = packetid.getNext();
#endif

    len = MQTTSerialize_publish(sendbuf, MAX_MQTT_PACKET_SIZE, 0, qos, retained, id,
              topicString, (unsigned char*)payload, payloadlen);
    if (len <= 0)
        goto exit;

#if MQTTCLIENT_QOS1 || MQTTCLIENT_QOS2
    if (!cleansession)
    {
        memcpy(pubbuf, sendbuf, len);
        inflightMsgid = id;
        inflightLen = len;
        inflightQoS = qos;
#if MQTTCLIENT_QOS2
        pubrel = false;
#endif
    }
#endif

    rc = publish(len, timer, qos);
exit:
    return rc;
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::publish(const char* topicName, void* payload, size_t payloadlen, enum QoS qos, bool retained)
{
    unsigned short id = 0;  // dummy - not used for anything
    return publish(topicName, payload, payloadlen, id, qos, retained);
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::publish(const char* topicName, Message& message)
{
    return publish(topicName, message.payload, message.payloadlen, message.qos, message.retained);
}


template<class Network, class Timer, int MAX_MQTT_PACKET_SIZE, int b>
int MQTT::Client<Network, Timer, MAX_MQTT_PACKET_SIZE, b>::disconnect()
{
    int rc = FAILURE;
    Timer timer = Timer(command_timeout_ms);     // we might wait for incomplete incoming publishes to complete
    int len = MQTTSerialize_disconnect(sendbuf, MAX_MQTT_PACKET_SIZE);
    if (len > 0)
        rc = sendPacket(len, timer);            // send the disconnect packet

    isconnected = false;
    return rc;
}


#endif
