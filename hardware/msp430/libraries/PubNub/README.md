#PubNub Arduino Library

This library allows your sketches to communicate with the PubNub cloud
message passing system using an Ethernet shield. Your application can
receive and send messages.

##Copy-and-Paste-Ready Code!
See how easy it is to [Publish](examples/PubNubPublisher) and [Subscribe](examples/PubNubSubscriber)!

###Synopsis


	void setup() {
		Serial.begin(9600);
		Ethernet.begin(mac);
		PubNub.begin(pubkey, subkey);
	}

	void loop() {
		/* Maintain DHCP lease. */
		Ethernet.maintain();

		/* Publish message. */
		EthernetClient *pclient = PubNub.publish(pubchannel, "\"message\"");
		if (pclient)
			pclient->stop();

		/* Wait for news. */
		PubSubClient *sclient = PubNub.subscribe(subchannel);
		if (!sclient) return; // error
		char buffer[64]; size_t buflen = 0;
		while (sclient->wait_for_data()) {
			buffer[buflen++] = sclient->read();
		}
		buffer[buflen] = 0;
		sclient->stop();

		/* Print received message. You will want to look at it from
		 * your code instead. */
		Serial.println(buffer);
		delay(10000);
	}

##Library Reference

``bool PubNub.begin(char *publish_key, char *subscribe_key, char *origin)``

To start using PubNub, use PubNub.begin().  This should be called after
Ethernet.begin().

Note that the string parameters are not copied; do not overwrite or free the
memory where you stored the keys! (If you are passing string literals, don't
worry about it.) Note that you should run only one of publish, subscribe and
history requests each at once.

The origin parameter is optional, defaulting to "pubsub.pubnub.com".

``EthernetClient *publish(char *channel, char *message, int timeout)``

Send a message (assumed to be well-formed JSON) to a given channel.

Returns NULL in case of error, instead an instance of EthernetClient
that you can use to read the reply to the publish command. If you
don't care about it, call ``client->stop()`` right away.

The timeout parameter is optional, defaulting to 305. See also
a note about timeouts below.

``PubSubClient *subscribe(char *channel)``

Listen for a message on a given channel. The function will block
and return when a message arrives. NULL is returned in case of error.
The return type is PubSubClient, but from user perspective, you can
work with it exactly like with EthernetClient; it also provides
an extra convenience method ``wait_for_data()`` that allows you
to wait for more data with sensible timeout.

Typically, you will run this function from loop() function to keep
listening for messages indefinitely.

As a reply, you will get a JSON array with messages, e.g.:

```
	["msg1",{msg2:"x"}]
```

and so on. Empty reply [] is also normal and your code must be
able to handle that. Note that the reply specifically does not
include the time token present in the raw reply from PubNub;
no need to worry about that.

The timeout parameter is optional, defaulting to 305. See also
a note about timeouts below.

``EthernetClient *history(char *channel, int limit, int timeout)``

Receive list of the last messages published on the given channel.
The limit argument is optional and defaults to 10.

The timeout parameter is optional, defaulting to 305. See also
a note about timeouts below.

##Installation

Move the contents of the ``pubnub/arduino/`` directory to
``~/sketchbook/libraries/PubNub/`` and restart your Arduino IDE.
Try out the examples!

##Supported Hardware

The Arduino ecosystem features a multitude of platforms that
have significant differences regarding their hardware capabilities;
here, we list the status of PubNub support for various platforms:

  * ATMega168-based generic boards (Duemilanove, Diecimila...):
Not supported due to too small RAM and flash memory size.
  * ATMega328-based generic boards (Duemilanove, Uno), Arduino
Ethernet: Supported.  The space for user code may be somewhat limited.
When using the aJson library, some memory saving tricks are required,
see the top of the PubNubJson example.

  * Arduino Mega (ATMega2560): Supported.
  * Arduino Mega (ATMega1280): Untested, but should work just fine.

Except Arduino Ethernet, network connectivity is provided by
an external board ("shield"):

  * Arduino Ethernet Shield: Supported. We tested only a shield that
is based on the WizNet W5100 chip - but this should be the case for
all but some ancient non-official ethernet shields.
  * Arduino WiFi Shield: Supported, but new enough firmware and software
is required.  The support must be enabled in the PubNub library.
Please see the "WiFi Shield Support" section for details.

##WiFi Shield Support

The PubNub library supports the WiFi shield as well. In order
to use the library with a WiFi-enabled Arduino, you will need
to edit the file PubNub.h, commenting out the line

	//#define PubNub_Ethernet

and uncommenting

	#define PubNub_WiFi

It is essential to use a new enough Arduino version so that
the WiFi library actually works properly. Most notably, version 1.0.5
has been confirmed to work while Arduino 1.0.4 is broken!

The WiFi shield carries its own microcontroller dedicated to the network
communication and this microcontroller has upgradeable firmware.
If some of the PubNub calls fail with your WiFi shield (e.g. you
see "subscribe error" and similar messages in serial console),
the firmware loaded on your WiFi shield may be buggy - e.g. a WiFi
shield bought commercially in May 2013 came preloaded with firmware
that had to be upgraded.  This is not so difficult to do, simply follow:

	http://arduino.cc/en/Hacking/WiFiShieldFirmwareUpgrading

##Notes

* There is no SSL support on Arduino, it is unfeasible with
Arduino Uno or even Arduino Mega's computing power and memory limits.
All the traffic goes on the wire unencrypted and unsigned.

* We re-resolve the origin server IP address before each request.
This means some slow-down for intensive communication, but we rather
expect light traffic and very long-running sketches (days, months),
where refreshing the IP address is quite desirable.

* We let the users read replies at their leisure instead of
returning an already preloaded string so that (a) they can do that
in loop() code while taking care of other things as well (b) we don't
waste precious RAM by pre-allocating buffers that are never needed.

* If you are having problems connecting, maybe you have hit
a bug in Debian's version of Arduino pertaining the DNS code. Try using
an IP address as origin and/or upgrading your Arduino package.

* The optional timeout parameter allows you to specify a timeout
period after which the subscribe call shall be retried. Note
that this timeout is applied only for reading response, not for
connecting or sending data; use retransmission parameters of
the Ethernet library to tune this. As a rule of thumb, timeout
smaller than 30 seconds may still block longer with flaky
network. Default server-side timeout of PubNub API is 300s.

* The vendor firmware for the WiFi shield has dubious TCP implementation;
for example, TCP ports of outgoing connections are always chosen from the
same sequence, so if you reset your Arduino, some of the new connections
may interfere with an outstanding TCP connection that has not been closed
before the reset; i.e. you will typically see a single failed request
somewhere down the road after a reset.
