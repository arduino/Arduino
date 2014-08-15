// Class to simplify HTTP fetching on Arduino
// (c) Copyright MCQN Ltd. 2010-2012
// Released under Apache License, version 2.0

#ifndef HttpClient_h
#define HttpClient_h

#include <Arduino.h>
#include <IPAddress.h>
#include "Ethernet.h"
#include "Client.h"

static const int HTTP_SUCCESS =0;
// The end of the headers has been reached.  This consumes the '\n'
// Could not connect to the server
static const int HTTP_ERROR_CONNECTION_FAILED =-1;
// This call was made when the HttpClient class wasn't expecting it
// to be called.  Usually indicates your code is using the class
// incorrectly
static const int HTTP_ERROR_API =-2;
// Spent too long waiting for a reply
static const int HTTP_ERROR_TIMED_OUT =-3;
// The response from the server is invalid, is it definitely an HTTP
// server?
static const int HTTP_ERROR_INVALID_RESPONSE =-4;

class HttpClient : public Client
{
public:
    static const int kNoContentLengthHeader =-1;
    static const int kHttpPort =80;
    static const char* kUserAgent;
    static const char* kGet;
    static const char* kPost;
    static const char* kPut;
    static const char* kDelete;

// FIXME Write longer API request, using port and user-agent, example
// FIXME Update tempToPachube example to calculate Content-Length correctly

    HttpClient(Client& aClient, const char* aProxy =NULL, uint16_t aProxyPort =0);

    /** Start a more complex request.
        Use this when you need to send additional headers in the request,
        but you will also need to call endRequest() when you are finished.
    */
    void beginRequest();

    /** End a more complex request.
        Use this when you need to have sent additional headers in the request,
        but you will also need to call beginRequest() at the start.
    */
    void endRequest();

    /** Connect to the server and start to send a GET request.
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aServerPort  Port to connect to on the server
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int get(const char* aServerName, uint16_t aServerPort, const char* aURLPath, 
            const char* aUserAgent =NULL)
      { return startRequest(aServerName, aServerPort, aURLPath, kGet, aUserAgent); }

    /** Connect to the server and start to send a GET request.
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int get(const char* aServerName, const char* aURLPath, const char* aUserAgent =NULL)
      { return startRequest(aServerName, kHttpPort, aURLPath, kGet, aUserAgent); }

    /** Connect to the server and start to send a GET request.  This version connects
      doesn't perform a DNS lookup and just connects to the given IP address.
      @param aServerAddress IP address of the server to connect to
      @param aServerName    Name of the server being connected to.  If NULL, the
                            "Host" header line won't be sent
      @param aServerPort    Port to connect to on the server
      @param aURLPath       Url to request
      @param aUserAgent     User-Agent string to send.  If NULL the default
                            user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int get(const IPAddress& aServerAddress,
            const char* aServerName, 
            uint16_t aServerPort,
            const char* aURLPath, 
            const char* aUserAgent =NULL)
      { return startRequest(aServerAddress, aServerName, aServerPort, aURLPath, kGet, aUserAgent); }

    /** Connect to the server and start to send a GET request.  This version connects
      doesn't perform a DNS lookup and just connects to the given IP address.
      @param aServerAddress IP address of the server to connect to
      @param aServerName    Name of the server being connected to.  If NULL, the
                            "Host" header line won't be sent
      @param aURLPath       Url to request
      @param aUserAgent     User-Agent string to send.  If NULL the default
                            user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int get(const IPAddress& aServerAddress,
            const char* aServerName, 
            const char* aURLPath, 
            const char* aUserAgent =NULL)
      { return startRequest(aServerAddress, aServerName, kHttpPort, aURLPath, kGet, aUserAgent); }

    /** Connect to the server and start to send a POST request.
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aServerPort  Port to connect to on the server
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int post(const char* aServerName, 
             uint16_t aServerPort,
             const char* aURLPath, 
             const char* aUserAgent =NULL)
      { return startRequest(aServerName, aServerPort, aURLPath, kPost, aUserAgent); }

    /** Connect to the server and start to send a POST request.
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int post(const char* aServerName, 
             const char* aURLPath, 
             const char* aUserAgent =NULL)
      { return startRequest(aServerName, kHttpPort, aURLPath, kPost, aUserAgent); }

    /** Connect to the server and start to send a POST request.  This version connects
      doesn't perform a DNS lookup and just connects to the given IP address.
      @param aServerAddress IP address of the server to connect to
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aServerPort  Port to connect to on the server
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int post(const IPAddress& aServerAddress,
             const char* aServerName, 
             uint16_t aServerPort,
             const char* aURLPath, 
             const char* aUserAgent =NULL)
      { return startRequest(aServerAddress, aServerName, aServerPort, aURLPath, kPost, aUserAgent); }

    /** Connect to the server and start to send a POST request.  This version connects
      doesn't perform a DNS lookup and just connects to the given IP address.
      @param aServerAddress IP address of the server to connect to
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int post(const IPAddress& aServerAddress,
             const char* aServerName, 
             const char* aURLPath, 
             const char* aUserAgent =NULL)
      { return startRequest(aServerAddress, aServerName, kHttpPort, aURLPath, kPost, aUserAgent); }

    /** Connect to the server and start to send a PUT request.
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aServerPort  Port to connect to on the server
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int put(const char* aServerName, 
            uint16_t aServerPort,
            const char* aURLPath, 
            const char* aUserAgent =NULL)
      { return startRequest(aServerName, aServerPort, aURLPath, kPut, aUserAgent); }

    /** Connect to the server and start to send a PUT request.
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int put(const char* aServerName, 
            const char* aURLPath, 
            const char* aUserAgent =NULL)
      { return startRequest(aServerName, kHttpPort, aURLPath, kPut, aUserAgent); }

    /** Connect to the server and start to send a PUT request.  This version connects
      doesn't perform a DNS lookup and just connects to the given IP address.
      @param aServerAddress IP address of the server to connect to
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aServerPort  Port to connect to on the server
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int put(const IPAddress& aServerAddress,
            const char* aServerName, 
            uint16_t aServerPort,
            const char* aURLPath, 
            const char* aUserAgent =NULL)
      { return startRequest(aServerAddress, aServerName, aServerPort, aURLPath, kPut, aUserAgent); }

    /** Connect to the server and start to send a PUT request.  This version connects
      doesn't perform a DNS lookup and just connects to the given IP address.
      @param aServerAddress IP address of the server to connect to
      @param aServerName  Name of the server being connected to.  If NULL, the
                          "Host" header line won't be sent
      @param aURLPath     Url to request
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int put(const IPAddress& aServerAddress,
            const char* aServerName, 
            const char* aURLPath, 
            const char* aUserAgent =NULL)
      { return startRequest(aServerAddress, aServerName, kHttpPort, aURLPath, kPut, aUserAgent); }

    /** Connect to the server and start to send the request.
      @param aServerName  Name of the server being connected to.
      @param aServerPort  Port to connect to on the server
      @param aURLPath     Url to request
      @param aHttpMethod  Type of HTTP request to make, e.g. "GET", "POST", etc.
      @param aUserAgent   User-Agent string to send.  If NULL the default
                          user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int startRequest(const char* aServerName,
                     uint16_t    aServerPort,
                     const char* aURLPath,
                     const char* aHttpMethod,
                     const char* aUserAgent);

    /** Connect to the server and start to send the request.
      @param aServerAddress IP address of the server to connect to.
      @param aServerName Name of the server being connected to.  If NULL, the
                         "Host" header line won't be sent
      @param aServerPort  Port to connect to on the server
      @param aURLPath	Url to request
      @param aHttpMethod  Type of HTTP request to make, e.g. "GET", "POST", etc.
      @param aUserAgent User-Agent string to send.  If NULL the default
                        user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int startRequest(const IPAddress& aServerAddress,
                     const char* aServerName,
                     uint16_t    aServerPort,
                     const char* aURLPath,
                     const char* aHttpMethod,
                     const char* aUserAgent);

    /** Send an additional header line.  This can only be called in between the
      calls to startRequest and finishRequest.
      @param aHeader Header line to send, in its entirety (but without the
                     trailing CRLF.  E.g. "Authorization: Basic YQDDCAIGES" 
    */
    void sendHeader(const char* aHeader);

    /** Send an additional header line.  This is an alternate form of
      sendHeader() which takes the header name and content as separate strings.
      The call will add the ": " to separate the header, so for example, to
      send a XXXXXX header call sendHeader("XXXXX", "Something")
      @param aHeaderName Type of header being sent
      @param aHeaderValue Value for that header
    */
    void sendHeader(const char* aHeaderName, const char* aHeaderValue);

    /** Send an additional header line.  This is an alternate form of
      sendHeader() which takes the header name and content separately but where
      the value is provided as an integer.
      The call will add the ": " to separate the header, so for example, to
      send a XXXXXX header call sendHeader("XXXXX", 123)
      @param aHeaderName Type of header being sent
      @param aHeaderValue Value for that header
    */
    void sendHeader(const char* aHeaderName, const int aHeaderValue);

    /** Send a basic authentication header.  This will encode the given username
      and password, and send them in suitable header line for doing Basic
      Authentication.
      @param aUser Username for the authorization
      @param aPassword Password for the user aUser
    */
    void sendBasicAuth(const char* aUser, const char* aPassword);

    /** Finish sending the HTTP request.  This basically just sends the blank
      line to signify the end of the request
    */
    void finishRequest();

    /** Get the HTTP status code contained in the response.
      For example, 200 for successful request, 404 for file not found, etc.
    */
    int responseStatusCode();

    /** Read the next character of the response headers.
      This functions in the same way as read() but to be used when reading
      through the headers.  Check whether or not the end of the headers has
      been reached by calling endOfHeadersReached(), although after that point
      this will still return data as read() would, but slightly less efficiently
      @return The next character of the response headers
    */
    int readHeader();

    /** Skip any response headers to get to the body.
      Use this if you don't want to do any special processing of the headers
      returned in the response.  You can also use it after you've found all of
      the headers you're interested in, and just want to get on with processing
      the body.
      @return HTTP_SUCCESS if successful, else an error code
    */
    int skipResponseHeaders();

    /** Test whether all of the response headers have been consumed.
      @return true if we are now processing the response body, else false
    */
    bool endOfHeadersReached() { return (iState == eReadingBody); };

    /** Test whether the end of the body has been reached.
      Only works if the Content-Length header was returned by the server
      @return true if we are now at the end of the body, else false
    */
    bool endOfBodyReached();
    virtual bool endOfStream() { return endOfBodyReached(); };
    virtual bool completed() { return endOfBodyReached(); };

    /** Return the length of the body.
      @return Length of the body, in bytes, or kNoContentLengthHeader if no
      Content-Length header was returned by the server
    */
    int contentLength() { return iContentLength; };

    // Inherited from Print
    // Note: 1st call to these indicates the user is sending the body, so if need
    // Note: be we should finish the header first
    virtual size_t write(uint8_t aByte) { if (iState < eRequestSent) { finishHeaders(); }; return iClient-> write(aByte); };
    virtual size_t write(const uint8_t *aBuffer, size_t aSize) { if (iState < eRequestSent) { finishHeaders(); }; return iClient->write(aBuffer, aSize); };
    // Inherited from Stream
    virtual int available() { return iClient->available(); };
    /** Read the next byte from the server.
      @return Byte read or -1 if there are no bytes available.
    */
    virtual int read();
    virtual int read(uint8_t *buf, size_t size);
    virtual int peek() { return iClient->peek(); };
    virtual void flush() { return iClient->flush(); };

    // Inherited from Client
    virtual int connect(IPAddress ip, uint16_t port) { return iClient->connect(ip, port); };
    virtual int connect(const char *host, uint16_t port) { return iClient->connect(host, port); };
    virtual void stop();
    virtual uint8_t connected() { iClient->connected(); };
    virtual operator bool() { return bool(iClient); };
protected:
    /** Reset internal state data back to the "just initialised" state
    */
    void resetState();

    /** Send the first part of the request and the initial headers.
      @param aServerName Name of the server being connected to.  If NULL, the
                         "Host" header line won't be sent
      @param aServerIP  IP address of the server (only used if we're going through a
                        proxy and aServerName is NULL
      @param aServerPort  Port of the server being connected to.
      @param aURLPath	Url to request
      @param aHttpMethod  Type of HTTP request to make, e.g. "GET", "POST", etc.
      @param aUserAgent User-Agent string to send.  If NULL the default
                        user-agent kUserAgent will be sent
      @return 0 if successful, else error
    */
    int sendInitialHeaders(const char* aServerName,
                     IPAddress   aServerIP,
                     uint16_t    aPort,
                     const char* aURLPath,
                     const char* aHttpMethod,
                     const char* aUserAgent);

    /* Let the server know that we've reached the end of the headers
    */
    void finishHeaders();

    // Number of milliseconds that we wait each time there isn't any data
    // available to be read (during status code and header processing)
    static const int kHttpWaitForDataDelay = 1000;
    // Number of milliseconds that we'll wait in total without receiveing any
    // data before returning HTTP_ERROR_TIMED_OUT (during status code and header
    // processing)
    static const int kHttpResponseTimeout = 30*1000;
    static const char* kContentLengthPrefix;
    typedef enum {
        eIdle,
        eRequestStarted,
        eRequestSent,
        eReadingStatusCode,
        eStatusCodeRead,
        eReadingContentLength,
        eSkipToEndOfHeader,
        eLineStartingCRFound,
        eReadingBody
    } tHttpState;
    // Ethernet client we're using
    Client* iClient;
    // Current state of the finite-state-machine
    tHttpState iState;
    // Stores the status code for the response, once known
    int iStatusCode;
    // Stores the value of the Content-Length header, if present
    int iContentLength;
    // How many bytes of the response body have been read by the user
    int iBodyLengthConsumed;
    // How far through a Content-Length header prefix we are
    const char* iContentLengthPtr;
    // Address of the proxy to use, if we're using one
    IPAddress iProxyAddress;
    uint16_t iProxyPort;
};

#endif
