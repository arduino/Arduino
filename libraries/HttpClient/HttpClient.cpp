// Class to simplify HTTP fetching on Arduino
// (c) Copyright 2010-2011 MCQN Ltd
// Released under Apache License, version 2.0

#include "HttpClient.h"
#include "b64.h"
#include <Dns.h>
#include <string.h>
#include <ctype.h>

// Initialize constants
const char* HttpClient::kUserAgent = "Arduino/2.0";
const char* HttpClient::kGet = "GET";
const char* HttpClient::kPost = "POST";
const char* HttpClient::kPut = "PUT";
const char* HttpClient::kDelete = "DELETE";
const char* HttpClient::kContentLengthPrefix = "Content-Length: ";

HttpClient::HttpClient(Client& aClient, const char* aProxy, uint16_t aProxyPort)
 : iClient(&aClient), iProxyPort(aProxyPort)
{
  resetState();
  if (aProxy)
  {
    // Resolve the IP address for the proxy
    DNSClient dns;
    dns.begin(Ethernet.dnsServerIP());
    // Not ideal that we discard any errors here, but not a lot we can do in the ctor
    // and we'll get a connect error later anyway
    (void)dns.getHostByName(aProxy, iProxyAddress);
  }
}

void HttpClient::resetState()
{
  iState = eIdle;
  iStatusCode = 0;
  iContentLength = 0;
  iBodyLengthConsumed = 0;
  iContentLengthPtr = 0;
}

void HttpClient::stop()
{
  iClient->stop();
  resetState();
}

void HttpClient::beginRequest()
{
  iState = eRequestStarted;
}

int HttpClient::startRequest(const char* aServerName, uint16_t aServerPort, const char* aURLPath, const char* aHttpMethod, const char* aUserAgent)
{
    tHttpState initialState = iState;
    if ((eIdle != iState) && (eRequestStarted != iState))
    {
        return HTTP_ERROR_API;
    }

    if (iProxyPort)
    {
        if (!iClient->connect(iProxyAddress, iProxyPort) > 0)
        {
#ifdef LOGGING
            Serial.println("Proxy connection failed");
#endif
            return HTTP_ERROR_CONNECTION_FAILED;
        }
    }
    else
    {
        if (!iClient->connect(aServerName, aServerPort) > 0)
        {
#ifdef LOGGING
            Serial.println("Connection failed");
#endif
            return HTTP_ERROR_CONNECTION_FAILED;
        }
    }

    // Now we're connected, send the first part of the request
    int ret = sendInitialHeaders(aServerName, IPAddress(0,0,0,0), aServerPort, aURLPath, aHttpMethod, aUserAgent);
    if ((initialState == eIdle) && (HTTP_SUCCESS == ret))
    {
        // This was a simple version of the API, so terminate the headers now
        finishHeaders();
    }
    // else we'll call it in endRequest or in the first call to print, etc.

    return ret;
}

int HttpClient::startRequest(const IPAddress& aServerAddress, const char* aServerName, uint16_t aServerPort, const char* aURLPath, const char* aHttpMethod, const char* aUserAgent)
{
    tHttpState initialState = iState;
    if ((eIdle != iState) && (eRequestStarted != iState))
    {
        return HTTP_ERROR_API;
    }

    if (iProxyPort)
    {
        if (!iClient->connect(iProxyAddress, iProxyPort) > 0)
        {
#ifdef LOGGING
            Serial.println("Proxy connection failed");
#endif
            return HTTP_ERROR_CONNECTION_FAILED;
        }
    }
    else
    {
        if (!iClient->connect(aServerAddress, aServerPort) > 0)
        {
#ifdef LOGGING
            Serial.println("Connection failed");
#endif
            return HTTP_ERROR_CONNECTION_FAILED;
        }
    }

    // Now we're connected, send the first part of the request
    int ret = sendInitialHeaders(aServerName, aServerAddress, aServerPort, aURLPath, aHttpMethod, aUserAgent);
    if ((initialState == eIdle) && (HTTP_SUCCESS == ret))
    {
        // This was a simple version of the API, so terminate the headers now
        finishHeaders();
    }
    // else we'll call it in endRequest or in the first call to print, etc.

    return ret;
}

int HttpClient::sendInitialHeaders(const char* aServerName, IPAddress aServerIP, uint16_t aPort, const char* aURLPath, const char* aHttpMethod, const char* aUserAgent)
{
#ifdef LOGGING
    Serial.println("Connected");
#endif
    // Send the HTTP command, i.e. "GET /somepath/ HTTP/1.0"
    iClient->print(aHttpMethod);
    iClient->print(" ");
    if (iProxyPort)
    {
      // We're going through a proxy, send a full URL
      iClient->print("http://");
      if (aServerName)
      {
        // We've got a server name, so use it
        iClient->print(aServerName);
      }
      else
      {
        // We'll have to use the IP address
        iClient->print(aServerIP);
      }
      if (aPort != kHttpPort)
      {
        iClient->print(":");
        iClient->print(aPort);
      }
    }
    iClient->print(aURLPath);
    iClient->println(" HTTP/1.0");
    // The host header, if required
    if (aServerName)
    {
        sendHeader("Host", aServerName);
    }
    // And user-agent string
    iClient->print("User-Agent: ");
    if (aUserAgent)
    {
        iClient->println(aUserAgent);
    }
    else
    {
        iClient->println(kUserAgent);
    }

    // Everything has gone well
    iState = eRequestStarted;
    return HTTP_SUCCESS;
}

void HttpClient::sendHeader(const char* aHeader)
{
    iClient->println(aHeader);
}

void HttpClient::sendHeader(const char* aHeaderName, const char* aHeaderValue)
{
    iClient->print(aHeaderName);
    iClient->print(": ");
    iClient->println(aHeaderValue);
}

void HttpClient::sendHeader(const char* aHeaderName, const int aHeaderValue)
{
    iClient->print(aHeaderName);
    iClient->print(": ");
    iClient->println(aHeaderValue);
}

void HttpClient::sendBasicAuth(const char* aUser, const char* aPassword)
{
    // Send the initial part of this header line
    iClient->print("Authorization: Basic ");
    // Now Base64 encode "aUser:aPassword" and send that
    // This seems trickier than it should be but it's mostly to avoid either
    // (a) some arbitrarily sized buffer which hopes to be big enough, or
    // (b) allocating and freeing memory
    // ...so we'll loop through 3 bytes at a time, outputting the results as we
    // go.
    // In Base64, each 3 bytes of unencoded data become 4 bytes of encoded data
    unsigned char input[3];
    unsigned char output[5]; // Leave space for a '\0' terminator so we can easily print
    int userLen = strlen(aUser);
    int passwordLen = strlen(aPassword);
    int inputOffset = 0;
    for (int i = 0; i < (userLen+1+passwordLen); i++)
    {
        // Copy the relevant input byte into the input
        if (i < userLen)
        {
            input[inputOffset++] = aUser[i];
        }
        else if (i == userLen)
        {
            input[inputOffset++] = ':';
        }
        else
        {
            input[inputOffset++] = aPassword[i-(userLen+1)];
        }
        // See if we've got a chunk to encode
        if ( (inputOffset == 3) || (i == userLen+passwordLen) )
        {
            // We've either got to a 3-byte boundary, or we've reached then end
            b64_encode(input, inputOffset, output, 4);
            // NUL-terminate the output string
            output[4] = '\0';
            // And write it out
            iClient->print((char*)output);
// FIXME We might want to fill output with '=' characters if b64_encode doesn't
// FIXME do it for us when we're encoding the final chunk
            inputOffset = 0;
        }
    }
    // And end the header we've sent
    iClient->println();
}

void HttpClient::finishHeaders()
{
    iClient->println();
    iState = eRequestSent;
}

void HttpClient::endRequest()
{
    if (iState < eRequestSent)
    {
        // We still need to finish off the headers
        finishHeaders();
    }
    // else the end of headers has already been sent, so nothing to do here
}

int HttpClient::responseStatusCode()
{
    if (iState < eRequestSent)
    {
        return HTTP_ERROR_API;
    }
    // The first line will be of the form Status-Line:
    //   HTTP-Version SP Status-Code SP Reason-Phrase CRLF
    // Where HTTP-Version is of the form:
    //   HTTP-Version   = "HTTP" "/" 1*DIGIT "." 1*DIGIT

    char c = '\0';
    do
    {
        // Make sure the status code is reset, and likewise the state.  This
        // lets us easily cope with 1xx informational responses by just
        // ignoring them really, and reading the next line for a proper response
        iStatusCode = 0;
        iState = eRequestSent;

        unsigned long timeoutStart = millis();
        // Psuedo-regexp we're expecting before the status-code
        const char* statusPrefix = "HTTP/*.* ";
        const char* statusPtr = statusPrefix;
        // Whilst we haven't timed out & haven't reached the end of the headers
        while ((c != '\n') && 
               ( (millis() - timeoutStart) < kHttpResponseTimeout ))
        {
            if (available())
            {
                c = read();
                switch(iState)
                {
                case eRequestSent:
                    // We haven't reached the status code yet
                    if ( (*statusPtr == '*') || (*statusPtr == c) )
                    {
                        // This character matches, just move along
                        statusPtr++;
                        if (*statusPtr == '\0')
                        {
                            // We've reached the end of the prefix
                            iState = eReadingStatusCode;
                        }
                    }
                    else
                    {
                        return HTTP_ERROR_INVALID_RESPONSE;
                    }
                    break;
                case eReadingStatusCode:
                    if (isdigit(c))
                    {
                        // This assumes we won't get more than the 3 digits we
                        // want
                        iStatusCode = iStatusCode*10 + (c - '0');
                    }
                    else
                    {
                        // We've reached the end of the status code
                        // We could sanity check it here or double-check for ' '
                        // rather than anything else, but let's be lenient
                        iState = eStatusCodeRead;
                    }
                    break;
                case eStatusCodeRead:
                    // We're just waiting for the end of the line now
                    break;
                };
                // We read something, reset the timeout counter
                timeoutStart = millis();
            }
            else
            {
                // We haven't got any data, so let's pause to allow some to
                // arrive
                delay(kHttpWaitForDataDelay);
            }
        }
        if ( (c == '\n') && (iStatusCode < 200) )
        {
            // We've reached the end of an informational status line
            c = '\0'; // Clear c so we'll go back into the data reading loop
        }
    }
    // If we've read a status code successfully but it's informational (1xx)
    // loop back to the start
    while ( (iState == eStatusCodeRead) && (iStatusCode < 200) );

    if ( (c == '\n') && (iState == eStatusCodeRead) )
    {
        // We've read the status-line successfully
        return iStatusCode;
    }
    else if (c != '\n')
    {
        // We must've timed out before we reached the end of the line
        return HTTP_ERROR_TIMED_OUT;
    }
    else
    {
        // This wasn't a properly formed status line, or at least not one we
        // could understand
        return HTTP_ERROR_INVALID_RESPONSE;
    }
}

int HttpClient::skipResponseHeaders()
{
    // Just keep reading until we finish reading the headers or time out
    unsigned long timeoutStart = millis();
    // Whilst we haven't timed out & haven't reached the end of the headers
    while ((!endOfHeadersReached()) && 
           ( (millis() - timeoutStart) < kHttpResponseTimeout ))
    {
        if (available())
        {
            (void)readHeader();
            // We read something, reset the timeout counter
            timeoutStart = millis();
        }
        else
        {
            // We haven't got any data, so let's pause to allow some to
            // arrive
            delay(kHttpWaitForDataDelay);
        }
    }
    if (endOfHeadersReached())
    {
        // Success
        return HTTP_SUCCESS;
    }
    else
    {
        // We must've timed out
        return HTTP_ERROR_TIMED_OUT;
    }
}

bool HttpClient::endOfBodyReached()
{
    if (endOfHeadersReached() && (contentLength() != kNoContentLengthHeader))
    {
        // We've got to the body and we know how long it will be
        return (iBodyLengthConsumed >= contentLength());
    }
    return false;
}

int HttpClient::read()
{
    uint8_t b[1];
    int ret = read(b, 1);
    if (ret == 1)
    {
        return b[0];
    }
    else
    {
        return -1;
    }
}

int HttpClient::read(uint8_t *buf, size_t size)
{
    int ret =iClient->read(buf, size);
    if (endOfHeadersReached() && iContentLength > 0)
    {
        // We're outputting the body now and we've seen a Content-Length header
        // So keep track of how many bytes are left
        if (ret >= 0)
	{
            iBodyLengthConsumed += ret;
	}
    }
    return ret;
}

int HttpClient::readHeader()
{
    char c = read();

    if (endOfHeadersReached())
    {
        // We've passed the headers, but rather than return an error, we'll just
        // act as a slightly less efficient version of read()
        return c;
    }

    // Whilst reading out the headers to whoever wants them, we'll keep an
    // eye out for the "Content-Length" header
    switch(iState)
    {
    case eStatusCodeRead:
        // We're at the start of a line, or somewhere in the middle of reading
        // the Content-Length prefix
        if (*iContentLengthPtr == c)
        {
            // This character matches, just move along
            iContentLengthPtr++;
            if (*iContentLengthPtr == '\0')
            {
                // We've reached the end of the prefix
                iState = eReadingContentLength;
                // Just in case we get multiple Content-Length headers, this
                // will ensure we just get the value of the last one
                iContentLength = 0;
            }
        }
        else if ((iContentLengthPtr == kContentLengthPrefix) && (c == '\r'))
        {
            // We've found a '\r' at the start of a line, so this is probably
            // the end of the headers
            iState = eLineStartingCRFound;
        }
        else
        {
            // This isn't the Content-Length header, skip to the end of the line
            iState = eSkipToEndOfHeader;
        }
        break;
    case eReadingContentLength:
        if (isdigit(c))
        {
            iContentLength = iContentLength*10 + (c - '0');
        }
        else
        {
            // We've reached the end of the content length
            // We could sanity check it here or double-check for "\r\n"
            // rather than anything else, but let's be lenient
            iState = eSkipToEndOfHeader;
        }
        break;
    case eLineStartingCRFound:
        if (c == '\n')
        {
            iState = eReadingBody;
        }
        break;
    default:
        // We're just waiting for the end of the line now
        break;
    };

    if ( (c == '\n') && !endOfHeadersReached() )
    {
        // We've got to the end of this line, start processing again
        iState = eStatusCodeRead;
        iContentLengthPtr = kContentLengthPrefix;
    }
    // And return the character read to whoever wants it
    return c;
}



