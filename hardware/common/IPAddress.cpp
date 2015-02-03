#include "Arduino.h"
#include "IPAddress.h"

extern "C"{
#include "netcfg.h"
}

IPAddress::IPAddress()
{
    memset(&_address, 0, sizeof(_address));
}

IPAddress::IPAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet)
{
    _address._32 = SL_IPV4_VAL(first_octet,second_octet,third_octet,fourth_octet);
}

IPAddress::IPAddress(uint32_t address)
{
    _address._32 = address;
}

IPAddress::IPAddress(const uint8_t *address)
{
    _address._32 =
            address[0] << 8*3 |
            address[1] << 8*2 |
            address[2] << 8*1 |
            address[3] << 8*0;
}

IPAddress& IPAddress::operator=(const uint8_t *address)
{
    _address._32 =
            address[0] << 8*3 |
            address[1] << 8*2 |
            address[2] << 8*1 |
            address[3] << 8*0;
    return (*this);
}

IPAddress& IPAddress::operator=(uint32_t address)
{
    _address._32 = address;
    return (*this);
}

bool IPAddress::operator==(const uint8_t* addr)
{
    return (_address._32 ==
            addr[0] << 8*3 |
            addr[1] << 8*2 |
            addr[2] << 8*1 |
            addr[3] << 8*0);
}

size_t IPAddress::printTo(Print& p) const
{
    size_t n = 0;
    for (int i =0; i < 3; i++)
    {
        n += p.print(SL_IPV4_BYTE(_address._32,i), DEC);
        n += p.print('.');
    }
    n += p.print(SL_IPV4_BYTE(_address._32,3), DEC);
    return (n);
}

uint8_t IPAddress::operator[](int index) const
{
    if(index >= sizeof(_address) || index < 0) {
        return (0);
    }
    return (SL_IPV4_BYTE(_address._32,index));
}

uint8_t& IPAddress::operator[](int index)
{
    return (_address._8[3-index]);  // it's stored backwards
}
