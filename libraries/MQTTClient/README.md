# Eclipse Paho MQTT C/C++ client for Embedded platforms

This repository contains the source code for the [Eclipse Paho](http://eclipse.org/paho) MQTT C/C++ client library for Embedded platorms. 

The MQTTPacket directory contains the lowest level C library with the smallest requirements.  This supplies simple serialization 
and deserialization routines.  It is mainly up to you to write and read to and from the network.

The MQTTClient directory contains the next level C++ library.  This still avoids most networking code so that you can plugin the
network of your choice.

## Build requirements / compilation

There are helper scripts (build...) in various directories.  The client library is a set of building blocks which you pick and choose from, so that the smallest MQTT application can be built.

## Usage and API

See the samples directory for examples of intended use.


## Runtime tracing

As yet, there is no tracing.  For the smallest client, should we have tracing?


## Reporting bugs

Please report bugs under the "MQTT-Embedded-C" Component in [Eclipse Bugzilla](http://bugs.eclipse.org/bugs/) for the Paho Technology project.

## More information

Discussion of the Paho clients takes place on the [Eclipse paho-dev mailing list](https://dev.eclipse.org/mailman/listinfo/paho-dev).

General questions about the MQTT protocol are discussed in the [MQTT Google Group](https://groups.google.com/forum/?hl=en-US&fromgroups#!forum/mqtt).

There is much more information available via the [MQTT community site](http://mqtt.org).
