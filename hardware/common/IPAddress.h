#ifndef IPADDRESS_H
#define IPADDRESS_H

#include "Printable.h"

// A class to make it easier to handle IPV4 addresses

class IPAddress : public Printable {
    private:
        union{
            uint32_t _32;
            uint8_t _8[4];  // NOTE: _8[0] == _32&0xff (they're stored backwards)
        } _address;

    public:
        // Constructors
        IPAddress();
        IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet);
        IPAddress(uint32_t address);
        IPAddress(const uint8_t *address);

        // Overloaded cast operator to allow IPAddress objects to be used as uint32_t
        operator uint32_t() { return _address._32; };
        bool operator==(const IPAddress& addr) { return _address._32 == addr._address._32; };
        bool operator==(const uint8_t* addr);

        // Overloaded index operator to allow getting and setting individual octets of the address
        uint8_t  operator[](int index) const;
        uint8_t& operator[](int index);

        // Overloaded copy operators to allow initialization of IPAddress objects from other types
        IPAddress& operator=(const uint8_t *address);
        IPAddress& operator=(uint32_t address);

        virtual size_t printTo(Print& p) const;

        friend class EthernetClass;
        friend class UDP;
        friend class Client;
        friend class Server;
        friend class DhcpClass;
        friend class DNSClient;
};

const IPAddress INADDR_NONE(0,0,0,0);

#endif
