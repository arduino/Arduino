// Simple Base64 code
// (c) Copyright 2010 MCQN Ltd.
// Released under Apache License, version 2.0

#include "b64.h"

/* Simple test program
#include <stdio.h>
void main()
{
    char* in = "amcewen";
    char out[22];

    b64_encode(in, 15, out, 22);
    out[21] = '\0';

    printf(out);
}
*/

int b64_encode(const unsigned char* aInput, int aInputLen, unsigned char* aOutput, int aOutputLen)
{
    // Work out if we've got enough space to encode the input
    // Every 6 bits of input becomes a byte of output
    if (aOutputLen < (aInputLen*8)/6)
    {
        // FIXME Should we return an error here, or just the length
        return (aInputLen*8)/6;
    }

    // If we get here we've got enough space to do the encoding

    const char* b64_dictionary = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    if (aInputLen == 3)
    {
        aOutput[0] = b64_dictionary[aInput[0] >> 2];
        aOutput[1] = b64_dictionary[(aInput[0] & 0x3)<<4|(aInput[1]>>4)];
        aOutput[2] = b64_dictionary[(aInput[1]&0x0F)<<2|(aInput[2]>>6)];
        aOutput[3] = b64_dictionary[aInput[2]&0x3F];
    }
    else if (aInputLen == 2)
    {
        aOutput[0] = b64_dictionary[aInput[0] >> 2];
        aOutput[1] = b64_dictionary[(aInput[0] & 0x3)<<4|(aInput[1]>>4)];
        aOutput[2] = b64_dictionary[(aInput[1]&0x0F)<<2];
        aOutput[3] = '=';
    }
    else if (aInputLen == 1)
    {
        aOutput[0] = b64_dictionary[aInput[0] >> 2];
        aOutput[1] = b64_dictionary[(aInput[0] & 0x3)<<4];
        aOutput[2] = '=';
        aOutput[3] = '=';
    }
    else
    {
        // Break the input into 3-byte chunks and process each of them
        int i;
        for (i = 0; i < aInputLen/3; i++)
        {
            b64_encode(&aInput[i*3], 3, &aOutput[i*4], 4);
        }
        if (aInputLen % 3 > 0)
        {
            // It doesn't fit neatly into a 3-byte chunk, so process what's left
            b64_encode(&aInput[i*3], aInputLen % 3, &aOutput[i*4], aOutputLen - (i*4));
        }
    }
}

