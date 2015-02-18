
#include <Arduino.h>
#include <MACAddress.h>


const MACAddress MACADDR_NONE(0,0,0,0,0,0);

MACAddress::MACAddress()
{
    memset(_address, 0, sizeof(_address));
}

MACAddress::MACAddress(uint8_t first_octet, uint8_t second_octet, uint8_t third_octet, uint8_t fourth_octet, uint8_t fifth_octet, uint8_t sixth_octet)
{
    _address[0] = first_octet;
    _address[1] = second_octet;
    _address[2] = third_octet;
    _address[3] = fourth_octet;
    _address[4] = fifth_octet;
    _address[5] = sixth_octet;
}

MACAddress::MACAddress(const uint8_t *address)
{
    memcpy(_address, address, sizeof(_address));
}

MACAddress& MACAddress::operator=(const uint8_t *address)
{
    memcpy(_address, address, sizeof(_address));
    return *this;
}

bool MACAddress::operator==(const MACAddress& addr)
{
    return memcmp(addr._address, _address, sizeof(_address)) == 0;
}

bool MACAddress::operator==(const uint8_t* addr)
{
    return memcmp(addr, _address, sizeof(_address)) == 0;
}

size_t MACAddress::printTo(Print& p) const
{
    size_t n = 0;
    for (int i =0; i < 5; i++)
    {
	if (_address[i] < 0x10)
		n += p.print('0');
        n += p.print(_address[i], HEX);
        n += p.print(':');
    }
    if (_address[5] < 0x10)
        n += p.print('0');
    n += p.print(_address[5], HEX);
    return n;
}
