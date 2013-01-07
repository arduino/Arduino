// Arduino DNS client for WizNet5100-based Ethernet shield
// (c) Copyright 2009-2010 MCQN Ltd.
// Released under Apache License, version 2.0

#ifndef DNSClient_h
#define DNSClient_h

#include <EthernetUdp.h>

class DNSClient
{
public:
	// ctor
	void begin(const IPAddress& aDNSServer);

	/** Convert a numeric IP address string into a four-byte IP address.
	  @param aIPAddrString IP address to convert
	  @param aResult IPAddress structure to store the returned IP address
	  @result 1 if aIPAddrString was successfully converted to an IP address,
	  else error code
	  */
	int inet_aton(const char *aIPAddrString, IPAddress& aResult);

	/** Resolve the given hostname to an IP address.
	  @param aHostname Name to be resolved
	  @param aResult IPAddress structure to store the returned IP address
	  @result 1 if aIPAddrString was successfully converted to an IP address,
	  else error code
	  */
	int getHostByName(const char* aHostname, IPAddress& aResult);

	/** non blocking version of retrieving an IP for a hostname
	  @param aHostname Name to be resolved
	  @param aResult IPAddress structure to store the returned IP address, 
	  		in case @result == 1, else nothing will be assigned
	  @result 
	  	1 if we already have an IP address, 
		0 if we have started the dns lookup, start calling getHostRequestResult(),
		else: an error code.

	 */
	int startHostRequest(const char* aHostname, IPAddress& aResult);
	/** get the result of the hostname lookup
	  @param aResult IPAddress structure to store the returned IP address, 
	  		in case @result == 1, else nothing will be assigned
	  @result
	  	1 if we have an IP address,
		0 if we do not have a response yet
		else: an error occured
	 */
	int getHostRequestResult(IPAddress& aResult);

protected:
	uint16_t BuildRequest(const char* aName);
	uint16_t ProcessResponse(IPAddress& aAddress);

	IPAddress iDNSServer;
	uint16_t iRequestId;
	EthernetUDP iUdp;
	uint8_t _resolving;
	uint32_t _startResolving; 
};

#endif
