#ifndef PubNub_h
#define PubNub_h


#include <stdint.h>


/* By default, the PubNub library is built to work with the Ethernet
 * shield. WiFi shield support can be enabled by commenting the
 * following line and commenting out the line after that. Refer
 * to the PubNubJsonWifi sketch for a complete example. */
#define PubNub_Ethernet
//#define PubNub_WiFi


#if defined(PubNub_Ethernet)
#include <Ethernet.h>
#define PubNub_BASE_CLIENT EthernetClient

#elif defined(PubNub_WiFi)
#include <WiFi.h>
#define PubNub_BASE_CLIENT WiFiClient

#else
#error PubNub_BASE_CLIENT set to an invalid value!
#endif


/* Some notes:
 *
 * (i) There is no SSL support on Arduino, it is unfeasible with
 * Arduino Uno or even Arduino Mega's computing power and memory limits.
 * All the traffic goes on the wire unencrypted and unsigned.
 *
 * (ii) We re-resolve the origin server IP address before each request.
 * This means some slow-down for intensive communication, but we rather
 * expect light traffic and very long-running sketches (days, months),
 * where refreshing the IP address is quite desirable.
 *
 * (iii) We let the users read replies at their leisure instead of
 * returning an already preloaded string so that (a) they can do that
 * in loop() code while taking care of other things as well (b) we don't
 * waste precious RAM by pre-allocating buffers that are never needed.
 *
 * (iv) If you are having problems connecting, maybe you have hit
 * a bug in Debian's version of Arduino pertaining the DNS code. Try using
 * an IP address as origin and/or upgrading your Arduino package.
 *
 * (v) The optional timeout parameter allows you to specify a timeout
 * period after which the subscribe call shall be retried. Note
 * that this timeout is applied only for reading response, not for
 * connecting or sending data; use retransmission parameters of
 * the Ethernet library to tune this. As a rule of thumb, timeout
 * smaller than 30 seconds may still block longer with flaky
 * network. Default server-side timeout of PubNub API is 300s.
 *
 * (vi) If some of the PubNub calls fail with your WiFi shield (e.g. you
 * see "subscribe error" and similar messages in serial console), your
 * WiFi shield firmware may be buggy - e.g. a WiFi shield bought
 * commercially in May 2013 had a firmware that had to be upgaded.
 * This is not so difficult to do, simply follow:
 *
 *   	http://arduino.cc/en/Hacking/WiFiShieldFirmwareUpgrading
 *
 * (vii) The vendor firmware for the WiFi shield has dubious TCP implementation;
 * for example, TCP ports of outgoing connections are always chosen from the
 * same sequence, so if you reset your Arduino, some of the new connections
 * may interfere with an outstanding TCP connection that has not been closed
 * before the reset; i.e. you will typically see a single failed request
 * somewhere down the road after a reset.
 *
 * (viii) It is essential to use a new enough Arduino version so that
 * the WiFi library actually works properly. Most notably, version 1.0.5
 * has been confirmed to work while Arduino 1.0.4 is broken.
 */


/* This class is a thin EthernetClient wrapper whose goal is to
 * automatically acquire time token information when reading
 * subscribe call response.
 *
 * (i) The user application sees only the JSON body, not the timetoken.
 * As soon as the body ends, PubSubclient reads the rest of HTTP reply
 * itself and disconnects. The stored timetoken is used in the next call
 * to the PubSub::subscribe method then. */
class PubSubClient : public PubNub_BASE_CLIENT {
public:
	PubSubClient() :
		PubNub_BASE_CLIENT(), json_enabled(false)
	{
		strcpy(timetoken, "0");
	}

	/* Customized functions that make reading stop as soon as we
	 * have hit ',' outside of braces and string, which indicates
	 * end of JSON body. */
	virtual int read();
	virtual int read(uint8_t *buf, size_t size);
	virtual void stop();

	/* Block until data is available. Returns false in case the
	 * connection goes down or timeout expires. */
	bool wait_for_data(int timeout = 310);

	/* Enable the JSON state machine. */
	void start_body();

	inline char *server_timetoken() { return timetoken; }

private:
	void _state_input(uint8_t ch, uint8_t *nextbuf, size_t nextsize);
	void _grab_timetoken(uint8_t *nextbuf, size_t nextsize);

	/* JSON state machine context */
	bool json_enabled:1;
	bool in_string:1;
	bool after_backslash:1;
	int braces_depth;

	/* Time token acquired during the last subscribe request. */
	char timetoken[22];
};


enum PubNub_BH {
	PubNub_BH_OK,
	PubNub_BH_ERROR,
	PubNub_BH_TIMEOUT,
};

class PubNub {
public:
	/* Init the Pubnub Client API
	 *
	 * This should be called after Ethernet.begin().
	 * Note that the string parameters are not copied; do not
	 * overwrite or free the memory where you stored the keys!
	 * (If you are passing string literals, don't worry about it.)
	 * Note that you should run only a single publish at once.
	 *
	 * @param string publish_key required key to send messages.
	 * @param string subscribe_key required key to receive messages.
	 * @param string origin optional setting for cloud origin.
	 * @return boolean whether begin() was successful. */
	bool begin(const char *publish_key, const char *subscribe_key, const char *origin = "pubsub.pubnub.com");

	/* Set the UUID identification of PubNub client. This is useful
	 * e.g. for presence identification.
	 *
	 * Pass NULL to unset. The string is not copied over (just like
	 * in begin()). See the PubNubSubscriber example for simple code
	 * that generates a random UUID (although not 100% reliable). */
	void set_uuid(const char *uuid);

	/* Publish
	 *
	 * Send a message (assumed to be well-formed JSON) to a given channel.
	 *
	 * Note that the reply can be obtained using code like:
	     client = publish("demo", "\"lala\"");
	     if (!client) return; // error
	     while (client->connected()) {
	       // More sophisticated code will want to add timeout handling here
	       while (client->connected() && !client->available()) ; // wait
	       char c = client->read();
	       Serial.print(c);
	     }
	     client->stop();
	 * You will get content right away, the header has been already
	 * skipped inside the function. If you do not care about
	 * the reply, just call client->stop(); immediately.
	 *
	 * It returns an object that is typically EthernetClient (but it
	 * can be a WiFiClient if you enabled the WiFi shield).
	 *
	 * @param string channel required channel name.
	 * @param string message required message string in JSON format.
	 * @param string timeout optional timeout in seconds.
	 * @return string Stream-ish object with reply message or NULL on error. */
	PubNub_BASE_CLIENT *publish(const char *channel, const char *message, int timeout = 30);

	/**
	 * Subscribe
	 *
	 * Listen for a message on a given channel. The function will block
	 * and return when a message arrives. Typically, you will run this
	 * function from loop() function to keep listening for messages
	 * indefinitely.
	 *
	 * As a reply, you will get a JSON array with messages, e.g.:
	 * 	["msg1",{msg2:"x"}]
	 * and so on. Empty reply [] is also normal and your code must be
	 * able to handle that. Note that the reply specifically does not
	 * include the time token present in the raw reply.
	 *
	 * @param string channel required channel name.
	 * @param string timeout optional timeout in seconds.
	 * @return string Stream-ish object with reply message or NULL on error. */
	PubSubClient *subscribe(const char *channel, int timeout = 310);

	/**
	 * History
	 *
	 * Receive list of the last N messages on the given channel.
	 *
	 * @param string channel required channel name.
	 * @param int limit optional number of messages to retrieve.
	 * @param string timeout optional timeout in seconds.
	 * @return string Stream-ish object with reply message or NULL on error. */
	PubNub_BASE_CLIENT *history(const char *channel, int limit = 10, int timeout = 310);

private:
	enum PubNub_BH _request_bh(PubNub_BASE_CLIENT &client, unsigned long t_start, int timeout, char qparsep);

	const char *publish_key, *subscribe_key;
	const char *origin;
	const char *uuid;

	PubNub_BASE_CLIENT publish_client, history_client;
	PubSubClient subscribe_client;
};

extern class PubNub PubNub;

#endif
